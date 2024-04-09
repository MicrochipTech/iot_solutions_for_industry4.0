/*******************************************************************************
  Zigbee Cluster Library OTAU Client Cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClient.c

  Summary:
    The file implements the OTAU client initialization and common part.

  Description:
    The file implements the OTAU client initialization and common part.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#if (APP_USE_OTAU == 1)
#include <zigbee/z3device_configs/otauConfig.h>
#endif

#ifdef OTAU_CLIENT

#if APP_USE_OTAU == 1 && defined(_ZCL_SUPPORT_) 

/******************************************************************************
                   Includes section
******************************************************************************/
#include <zcl/include/zclOtauManager.h>

#include <zcl/include/zclOtauClient.h>
#include <z3device/otau/ofd/include/ofdMemoryDriver.h>
#include <pds/include/wlPdsMemIds.h>
#include "peripheral/nvm/plib_nvm.h"
#include <hal/cortexm4/pic32cx/include/halAes.h>

#if APP_DEVICE_OTAU_LOGGING == 1
#include <app_zigbee/zigbee_console/console.h>
#endif

#define NVM_WORD_SIZE (sizeof(uint32_t))

#define NVM_QUAD_WORD_SIZE (NVM_WORD_SIZE * 4)
/******************************************************************************
                   External variables section
******************************************************************************/
extern ZclOtauDiscoveryResult_t *actvServer;

/******************************************************************************
                          Prototypes section
******************************************************************************/
static void otauEraseComplete(OFD_Status_t status);
extern void otauSwitchToNewImage(void);

/*******************************************************************************
                        Global variables section
*******************************************************************************/
// OTAU Cluster Attributes
ZCL_OtauClusterClientAttributes_t otauClientAttributes =
{
  DEFINE_OTAU_CLIENT_ATTRIBUTES
};

// OTAU Cluster Commands
ZCL_OtauClusterCommands_t otauClientCommands =
{
  OTAU_COMMANDS(otauImageNotifyInd, NULL, otauQueryNextImageRespInd, NULL, NULL, \
               otauImageBlockRespInd, NULL, otauUpgradeEndRespInd)
};

DECLARE_QUEUE(zclOtauServerDiscoveryQueue);
ExtAddr_t otauUnauthorizedServers[OTAU_MAX_UNAUTHORIZED_SERVERS];

/******************************************************************************
                        Static variables section
******************************************************************************/
#if defined _PIC32CX_BZ3_
static otauPageBuff_t otauClientBuff;
static DRV_HANDLE sst26_hdl;
#endif

/******************************************************************************
                   External variables section
******************************************************************************/
ZclOtauClientStateMachine_t otauStateMachine = OTAU_STOPPED_STATE;
ExtAddr_t tempServerExtAddr = INVALID_SERVER_EXT_ADDRESS;
bool isOtauBusy = false;

/***************************************************************************//**
\brief Callback from flash driver about opening

\param[in] status - status of action
******************************************************************************/
void otauStartServerFinding(void)
{
    if(PDS_IsAbleToRestore(OTAU_ATTRIBUTES_MEM_DIR_ID))
    {
        PDS_Restore(OTAU_ATTRIBUTES_MEM_DIR_ID);
        COPY_EXT_ADDR(tempServerExtAddr,otauClientAttributes.upgradeServerID.value);
        zclGetOtauClientMem()->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;
    }
    else
    { 
        // Attributes restore failed, initialize to default
        CS_ReadParameter(CS_ZCL_OTAU_DEFAULT_UPGRADE_SERVER_IEEE_ADDRESS_ID, &tempServerExtAddr);
        otauClientAttributes.imageUpgradeStatus.value = OTAU_NORMAL;
        otauClientAttributes.minimumBlockPeriod.value = ZCL_OTAU_DEFAULT_BLOCK_REQ_PERIOD;
        COPY_EXT_ADDR(otauClientAttributes.upgradeServerID.value,tempServerExtAddr);
        PDS_Store(OTAU_ATTRIBUTES_MEM_DIR_ID);
    }

    otauClientAttributes.clusterRevision.value          = 1;
    otauClientAttributes.upgradeActivationPolicy.value  = OTA_SERVER_ACTIVATION_ALLOWED;
    otauClientAttributes.upgradeTimeoutPolicy.value     = OTA_NO_UPGRADE_AFTER_TIMEOUT;

    if(isExtAddrValid(tempServerExtAddr))
    {
        OTAU_SET_STATE(otauStateMachine, OTAU_GET_NWK_ADDR_STATE);
        otauNwkAddrReq();
    }
    else
    {
        OTAU_SET_STATE(otauStateMachine, OTAU_WAIT_TO_DISCOVER_STATE);
        otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT * 10, otauStartDiscovery);
    }
}


/***************************************************************************//**
\brief Writes the received image to external flash
******************************************************************************/
void otauProcessSuccessfullWritingToFlash(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  OtauImageAuxVar_t *tmpAuxParam = &clientMem->imageAuxParam;
  OFD_MemoryAccessParam_t *tmpOfdParam = &clientMem->ofdParam;
  
  tmpAuxParam->requestFileOffset += tmpOfdParam->length;
  

    if((tmpAuxParam->requestFileOffset % OTAU_RECOVERY_BLOCK_SIZE_MIN) < tmpAuxParam->requestBlockSize)
    {
        ZclOtauRecovery_t *recoveryParams = zclOtauGetRecoveryParams();

        recoveryParams->fileOffset = tmpAuxParam->requestFileOffset;
        PDS_Store(OTAU_RECOVERY_IMAGE_OFFSET_MEM_ID);
    }

  tmpOfdParam->offset += tmpOfdParam->length;
  /*Reset the OFD write length*/
  tmpOfdParam->length = 0;
  
  /*Restore the retry count*/
  CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,&clientMem->retryCount);

  /*if download completed*/
  if (tmpAuxParam->requestFileOffset == tmpAuxParam->totalImageLength)
  {
    ZclOtauRecovery_t *recoveyParams = zclOtauGetRecoveryParams();

#if !defined _PIC32CX_BZ3_ 
    clientMem->ofdParam.data = recoveyParams->image.metaHeader;
    clientMem->ofdParam.length = sizeof(recoveyParams->image.metaHeader);
    clientMem->ofdParam.offset = OFD_IMAGE_START_ADDRESS;
#else
    clientMem->ofdParam.length = OTAU_MAX_REQ_BLOCK_SIZE;
    clientMem->ofdParam.offset = tmpOfdParam->offset;
#endif

    if (true == OFD_Write(&clientMem->ofdParam) )
    {
      #if defined _PIC32CX_BZ3_ 
      // Copy the 1st page from PDS and write it to externam flash
        clientMem->ofdParam.data = recoveyParams->image.otauHeader;
        otauExternalPageWrite(clientMem->ofdParam.data, OFD_IMAGE_START_ADDRESS);
      #endif
        OTAU_SET_STATE(otauStateMachine, OTAU_WAIT_TO_UPGRADE_STATE);
        clientMem->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;
        appOtauPrintf("OTAU: Image Transferred Sucessfully\r\n");
        otauStartGenericTimer(UPGRADE_END_REQ_QUICK_TIMEOUT, otauUpgradeEndReq);
        return;
    }
#if !defined _PIC32CX_BZ3_
    else
    {
        appOtauPrintf("OTAU: Image Transferred FAILED\r\n");
        otauAbortUpgradeProcess();
    }
#endif
  }
  /*end of download completed*/

#if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
  else if((tmpAuxParam->totalImageLength - tmpAuxParam->requestFileOffset) < CS_ZCL_OTAU_IMAGE_PAGE_REQUEST_PAGE_SIZE)
  {
#endif
    if((tmpAuxParam->totalImageLength - tmpAuxParam->requestFileOffset) < OTAU_MAX_REQ_BLOCK_SIZE)
    {
      tmpAuxParam->requestBlockSize = tmpAuxParam->totalImageLength - tmpAuxParam->requestFileOffset;
    }
    else
    {
      tmpAuxParam->requestBlockSize = OTAU_MAX_REQ_BLOCK_SIZE;
    }
#if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
  }
  else    // remaining size is greater than Page size
  {
    ZCL_OtauImagePageReq_t *tmpOtauReq = &clientMem->zclReqMem.uImagePageReq;
    if(tmpAuxParam->requestFileOffset  == tmpOtauReq->fileOffset + tmpOtauReq->pageSize)
    {
		// request a new page
		otauScheduleImagePageReq();    
		return;

    }
    else
	{
      otauRestartBlockRxTimer();
      return;
	}
    

  }
#endif
  
  otauScheduleImageBlockReq();
  return;
}

static bool OFD_EraseImage(void )
{	
	int pagesToBeErased = (OFD_IMAGE_MAX_SIZE / NVM_FLASH_PAGESIZE) - 1; 

    while (pagesToBeErased >= 0 )
    {
        while(NVM_IsBusy());
        if (true != NVM_PageErase(OFD_IMAGE_START_ADDRESS + (pagesToBeErased * NVM_FLASH_PAGESIZE)))
            return false;
        pagesToBeErased--;
    }
    return true;
}
/***************************************************************************//**
\brief Start erase image area
******************************************************************************/
void otauStartErase(void)
{
	
  if(OTAU_CHECK_STATE(otauStateMachine,OTAU_START_DOWNLOAD_STATE))
  {
    uint8_t flashErased[64];
    memset(flashErased,0xff,sizeof(flashErased));
    if(memcmp(flashErased,(void *)OFD_IMAGE_START_ADDRESS, sizeof(flashErased)))
    {
        // Slot 2 is not erased, erase it to continue
        appOtauPrintf("OTAU: Flash Erasing...\r\n");
        if(true != OFD_EraseImage())
        {
            appOtauPrintf("OTAU: Flash Erase failed\r\n");
            return;
        }
        appOtauPrintf("OTAU: Erase Complete\r\n");
    }
    otauEraseComplete(OFD_STATUS_SUCCESS);
       
  }
  else
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_OFD_ERASE);
    zclRestartOtauClient();
  }
  return;
}

/***************************************************************************//**
\brief Callback from flash driver about end of flash erasing

\param[in] status - status of action;
******************************************************************************/
static void otauEraseComplete(OFD_Status_t status)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  switch(status)
  {
    case OFD_STATUS_SUCCESS:
      if(OTAU_CHECK_STATE(otauStateMachine,OTAU_START_DOWNLOAD_STATE))
      {
        otauStartDownload();
      }
      else
      {
        // Assert Error
        SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_OFD_ERASE_CALLBACK);
        zclRestartOtauClient();
      }
      break;

    case OFD_STATUS_SERIAL_BUSY:
    case OFD_SERIAL_INTERFACE_BUSY:
      otauStartGenericTimer(REPOST_OFD_ACTION, otauStartErase);
      break;

    default:
      appOtauPrintf("OTAU: OFD Erase Failed\r\n");
      SYS_E_ASSERT_ERROR(false, ZCL_OTAU_DOWNLOAD_ABORTED);
      zclRaiseCustomMessage(OTAU_OFD_DRIVER_ERROR);
      otauSetImageUpgradeStatusAttr(OTAU_NORMAL);
      zclRestartOtauClient();
      break;
  }
}

void otauSetImageUpgradeStatusAttr(ZCL_ImageUpdateStatus_t status)
{
  otauClientAttributes.imageUpgradeStatus.value = status;
  PDS_Store(OTAU_UPGRADE_STATUS_ATTR_MEM_ID);
}

/***************************************************************************//**
\brief All requests confirm.

\param[in] resp - pointer to response parameters.
******************************************************************************/
void otauSomeRequestConfirm(ZCL_Notify_t *resp)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_Request_t *tmpZclReq = GET_PARENT_BY_FIELD(ZCL_Request_t, notify, resp);


  switch (resp->status)
  {
    case ZCL_SUCCESS_STATUS: // received on aps ack / low-layer confirmation
      break;

    default: // received on zcl wait timer expiry
      if (clientMem->retryCount--)
      {
        HAL_StopAppTimer(&clientMem->blockResponseWaitTimer);
        switch (tmpZclReq->id)
        {
          case IMAGE_PAGE_REQUEST_ID:
            otauStopGenericTimer();
            otauScheduleImagePageReq();
            break;

          case IMAGE_BLOCK_REQUEST_ID:
            otauStopGenericTimer();
            otauScheduleImageBlockReq();
            break;

          case QUERY_NEXT_IMAGE_REQUEST_ID:
            otauStopGenericTimer();
            /*Restart Query Timer*/
            otauStartQueryTimer();
            break;

          case UPGRADE_END_REQUEST_ID:
            if (ZCL_SUCCESS_STATUS == clientMem->otauUpgradeEndStatus)
            {
              otauStopGenericTimer();
              otauStartGenericTimer(UPGRADE_END_REQ_QUICK_TIMEOUT, otauUpgradeEndReq);
            }
            break;
        }
      }
      else
      {
        if (UPGRADE_END_REQUEST_ID == tmpZclReq->id)
        {
          // handle non-success at otauUpgradeEndStatus assignment place
          if (ZCL_SUCCESS_STATUS == clientMem->otauUpgradeEndStatus)
          {
            //do switch : OTAU r23, sec 6.13 as UpgradeTimeoutPolicy = 0
            otauStartGenericTimer(AMOUNT_MSEC_IN_SEC, otauSwitchToNewImage);
          }
        }
        else if(QUERY_NEXT_IMAGE_REQUEST_ID == tmpZclReq->id)
        {
          otauStartDiscoveryTimer();
        }
        else
        {
          otauAbortUpgradeProcess();
        }
      }
      break;
  }
}
/***************************************************************************//**
\brief Abort OTAU process and reinitate discovery.

\param[in] Void
******************************************************************************/
void otauAbortUpgradeProcess(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
#if !defined _PIC32CX_BZ3_
  uint8_t otauAesDecryptIV[AES_BLOCK_SIZE];
  memset(&otauAesDecryptIV,0,AES_BLOCK_SIZE);
  otauSetNewIV(otauAesDecryptIV);
#endif

  SYS_E_ASSERT_ERROR(false, ZCL_OTAU_DOWNLOAD_ABORTED);
  clientMem->otauUpgradeEndStatus = ZCL_ABORT_STATUS;
  otauUpgradeEndReq();
  zclRaiseCustomMessage(OTAU_DOWNLOAD_ABORTED);

  otauSetImageUpgradeStatusAttr(OTAU_NORMAL);

  zclOtauResetRecoveryParams();
  zclOtauResetAttributesPDS();
  clientMem->imageAuxParam.requestFileOffset      = 0;
  clientMem->imageAuxParam.requestBlockSize       = OTAU_MAX_REQ_BLOCK_SIZE;
  clientMem->imageAuxParam.totalImageLength       = 0; 

  clientMem->otauParam.receivedImgBlockSize       = 0;
  clientMem->newFirmwareVersion.versionId         = 0;
  
  setOtauIVrecovery(false);

  otauStartGenericTimer(AMOUNT_MSEC_IN_SEC,otauStartDiscoveryTimer);
}
/***************************************************************************//**
\brief otau default response handler.

\param[in] resp - pointer to response parametres.
******************************************************************************/
void otauSomeDefaultResponse(ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_DefaultResp_t *defaultResp = (ZCL_DefaultResp_t*)payload;
  ZCL_Request_t *tmpZclReq = &clientMem->reqMem.zclCommandReq;

  appOtauPrintf("OTAU: DefaultResp->Req:%d, Status 0x%02x\r\n", tmpZclReq->id, defaultResp->statusCode);
  switch(tmpZclReq->id)
  {
    case UPGRADE_END_REQUEST_ID:
    {
      switch (defaultResp->statusCode)
      {
        case ZCL_WAIT_FOR_DATA_STATUS:
        {
            /*keep retrying Upgrade end quest after some time*/
            otauStartGenericTimer(UPGRADE_END_REQ_QUICK_TIMEOUT, otauUpgradeEndReq);
        }
        break;
        case ZCL_ABORT_STATUS:
          zclOtauResetRecoveryParams();
          zclOtauResetAttributesPDS();
          otauSetImageUpgradeStatusAttr(OTAU_NORMAL);
          clientMem->imageAuxParam.requestFileOffset  = 0;
          clientMem->imageAuxParam.requestBlockSize   = OTAU_MAX_REQ_BLOCK_SIZE;
          clientMem->imageAuxParam.totalImageLength   = 0;

          clientMem->otauParam.receivedImgBlockSize   = 0;
          clientMem->newFirmwareVersion.versionId     = 0;
          otauStartDiscoveryTimer();
          break;
        case ZCL_INVALID_IMAGE_STATUS:
        case ZCL_MALFORMED_COMMAND_STATUS:
        {
          if (ZCL_SUCCESS_STATUS == clientMem->otauUpgradeEndStatus)
          {
            if (clientMem->retryCount--)
            {
              otauStartGenericTimer(UPGRADE_END_REQ_QUICK_TIMEOUT, otauUpgradeEndReq);
            }
            else
            {
              zclOtauResetRecoveryParams();
              zclOtauResetAttributesPDS();
              clientMem->imageAuxParam.requestFileOffset  = 0;
              clientMem->imageAuxParam.requestBlockSize   = OTAU_MAX_REQ_BLOCK_SIZE;
              clientMem->imageAuxParam.totalImageLength   = 0;

              clientMem->otauParam.receivedImgBlockSize   = 0;
              clientMem->newFirmwareVersion.versionId     = 0;
              otauStartDiscoveryTimer();
            }
          }
          else
          {
            isOtauBusy = false;
            zclOtauResetRecoveryParams();
            clientMem->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;
            if (ZCL_ABORT_STATUS == clientMem->otauUpgradeEndStatus)
            {
              zclRaiseCustomMessage(OTAU_DOWNLOAD_ABORTED);
            }
            else
            {
              otauStartDiscoveryTimer();
            }

          }
        }
        break;
        case ZCL_SUCCESS_STATUS:
        default:
        {
            isOtauBusy = false;
            zclOtauResetRecoveryParams();
            if (ZCL_SUCCESS_STATUS != clientMem->otauUpgradeEndStatus)
            {
                if (ZCL_ABORT_STATUS == clientMem->otauUpgradeEndStatus)
                {
                  zclRaiseCustomMessage(OTAU_DOWNLOAD_ABORTED);
                }
                clientMem->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;
                otauStartDiscoveryTimer();
            }
        }
        break;
      }
    }
    break;
    case QUERY_NEXT_IMAGE_REQUEST_ID:
    {
        otauStartQueryTimer();
        break;
    }
    case IMAGE_BLOCK_REQUEST_ID:
    case IMAGE_PAGE_REQUEST_ID:
        switch (defaultResp->statusCode)
        {
            case ZCL_MALFORMED_COMMAND_STATUS:
                if (ZCL_SUCCESS_STATUS == clientMem->otauUpgradeEndStatus)
                {
                    if (clientMem->retryCount--)
                    {
                        #if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
                            otauScheduleImagePageReq();
                        #else
                            otauScheduleImageBlockReq();
                        #endif
                    }
                    else
                    {
                      appOtauPrintf("OTAU: Block req Malformed resp \r\n");
                      otauAbortUpgradeProcess();
                    }
                }
            break;
            case ZCL_WAIT_FOR_DATA_STATUS:
            {
                HAL_AppTimer_t *tmpBlockRespTimer = &clientMem->blockResponseWaitTimer;
                HAL_StopAppTimer(tmpBlockRespTimer);
                #if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
                    otauScheduleImagePageReq();
                #else
                    otauScheduleImageBlockReq();
                #endif
            }
            break;
            default:
                appOtauPrintf("OTAU: Invalid default response \r\n");
                otauAbortUpgradeProcess();
            break;
      }
      break;

    default:
      // Goto discovery for "default-response-with-non-success"
      if (ZCL_SUCCESS_STATUS != defaultResp->statusCode)
      {
        otauStartDiscoveryTimer();
      }      
      break;
  }

  (void)addressing;
  (void)payloadLength;
  (void)req;
}

/******************************************************************************
                   Implementation section
******************************************************************************/

/***************************************************************************//**
\brief Start otau client service
******************************************************************************/
void zclStartOtauClient(void)
{
    ZclOtauMem_t *otauMem = zclGetOtauMem();
    ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
    uint8_t  deepSleepWakeupSrc=0;
    CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,&clientMem->retryCount);
    appOtauPrintf("Firmware version 0x%04x\r\n",CS_ZCL_OTAU_FILE_VERSION);
    otauClientAttributes.minimumBlockPeriod.value = ZCL_OTAU_DEFAULT_BLOCK_REQ_PERIOD;  // ZCL 6
    for (uint8_t i = 0; i < OTAU_MAX_UNAUTHORIZED_SERVERS; i++)
    {
        COPY_EXT_ADDR(otauUnauthorizedServers[i], INVALID_SERVER_EXT_ADDRESS);
    }
    isOtauBusy = false;
    otauMem->isOtauStopTriggered = false;
    CS_ReadParameter(CS_DEVICE_DEEP_SLEEP_WAKEUP_SRC_ID, &deepSleepWakeupSrc);
    if(deepSleepWakeupSrc==0)//no wake from deep sleep
    {
      otauStartServerFinding();
    }
    return;
}

#if defined _PIC32CX_BZ3_

/***************************************************************************//**
\brief Getter function for sst handle
******************************************************************************/
DRV_HANDLE * getSstHandle(void)
{
    return &sst26_hdl;
}

/***************************************************************************//**
\brief Add elements to otau buffer
******************************************************************************/
bool otauCacheExternalFlashPage(otauPageBuff_t* clientBuffer, uint8_t* data, uint32_t* writeAddress, uint16_t blockLength)
{
    ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
    OtauImageAuxVar_t *tmpAuxParam = &clientMem->imageAuxParam;
    uint32_t  saddr,startaddress;
    bool status;
    uint16_t remainingDataLength = 0;
    
	//Check if there is no sufficient space in the buffer for the incoming block
    if((DRV_SST26_PAGE_SIZE - clientBuffer->end) <= blockLength) 
    {
        uint16_t length = DRV_SST26_PAGE_SIZE - clientBuffer->end;
        
		//Copy portion of the incoming block that fits in the buffer
        memcpy(&(clientBuffer->buff[clientBuffer->end]), data, length);
        remainingDataLength = blockLength - length;
        clientBuffer->end = DRV_SST26_PAGE_SIZE;
        if((uint32_t)writeAddress <= DRV_SST26_PAGE_SIZE)
        {
          // Store the first page on to PDS
          ZclOtauRecovery_t *recoveyParams = zclOtauGetRecoveryParams();
          memcpy(recoveyParams->image.otauHeader,clientBuffer->buff,DRV_SST26_PAGE_SIZE);
          PDS_Store(OTAU_RECOVERY_IMAGE_DETAILS_MEM_ID);
        }
        else
          //Do a page write, since the buffer is full
          status = otauExternalPageWrite(clientBuffer->buff, (uint32_t)writeAddress);
        
        clientBuffer->end = 0;
        
		//Copy the remaining portion of the incoming block into the reseted buffer
        memcpy(&(clientBuffer->buff[clientBuffer->end]), (uint8_t* )(data+blockLength-remainingDataLength), remainingDataLength);
        clientBuffer->end += remainingDataLength;
        remainingDataLength = 0;
        
    }  else {
		//Copy the entire incoming block into the buffer
        memcpy(&(clientBuffer->buff[clientBuffer->end]), data, blockLength);
        clientBuffer->end += blockLength;
    }
    
    //Do a page write if the buffer is full or incoming block offset is the end of the image
    if((clientBuffer->end == DRV_SST26_PAGE_SIZE) || (tmpAuxParam->requestFileOffset == tmpAuxParam->totalImageLength)) 
    {         
        clientBuffer->end = DRV_SST26_PAGE_SIZE;
        if( (uint32_t)writeAddress > DRV_SST26_PAGE_SIZE)
          status = otauExternalPageWrite(clientBuffer->buff, (uint32_t)writeAddress);
        clientBuffer->end = 0;
    }
    
    return status;
}

/***************************************************************************//**
\brief start page write
******************************************************************************/
bool otauExternalPageWrite(uint8_t * otauDataBuffer, uint32_t writeAddress)
 {
    uint32_t pageWriteAddress = (writeAddress&0xFFFFFF00);
    bool status;
    DRV_HANDLE *handle = getSstHandle();
    status = DRV_SST26_PageWrite(*handle,(uint8_t *)otauDataBuffer,(uint32_t )pageWriteAddress);
    {
    if(status == false)
      appOtauPrintf("Otau Write failed \r\n");
    }
    while(DRV_SST26_TransferStatusGet(*handle) == DRV_SST26_TRANSFER_BUSY);
    memset((void *)otauDataBuffer, 0xff , DRV_SST26_PAGE_SIZE);
    return status;
 }
#endif


/***************************************************************************//**
\brief start ofd write
******************************************************************************/
bool OFD_Write(OFD_MemoryAccessParam_t *accessParam)
{
    uint16_t n_QW, n_W, remain, i = 0;
    uint8_t *pData = (uint8_t *)accessParam->data;
    uint8_t *pAddress = (uint8_t*) accessParam->offset;
    uint16_t size = (uint16_t)accessParam->length;
    bool status;
    if(0 == size)
    {
        return false; // Nothing to write
    }

#if defined _PIC32CX_BZ3_ 
    ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
    if (OFD_IMAGE_START_ADDRESS == clientMem->ofdParam.offset)
      memset(&otauClientBuff.buff, 0xff , DRV_SST26_PAGE_SIZE);
    status = otauCacheExternalFlashPage(&otauClientBuff, (uint8_t *)pData, (uint32_t *)pAddress, size);
#else
    if ((uint32_t)pAddress % NVM_QUAD_WORD_SIZE)
    {
      appSnprintf("Address offset is not 16 bytes aligned\r\n");
      return false;
    }

    if(size % NVM_QUAD_WORD_SIZE)
    {
      appSnprintf("Size is not 16 bytes aligned\r\n");
      return false;
    }

    for(uint16_t i = 0; i < (size / NVM_QUAD_WORD_SIZE); i++)
    {
      while(NVM_IsBusy());
      NVM_QuadWordWrite((uint32_t *)pData, (uint32_t)pAddress );
      pAddress += NVM_QUAD_WORD_SIZE;
      pData += NVM_QUAD_WORD_SIZE;
    }
    while(NVM_IsBusy());
      status = true;
#endif
    return status;
}

/***************************************************************************//**
\brief Start write image part
******************************************************************************/
void otauStartWrite (void)
{
    ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

    if ((!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE)) && \
        (!OTAU_CHECK_STATE(otauStateMachine, OTAU_WAIT_TO_UPGRADE_STATE)))
    {
      SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_OFD_WRITE);
      return;
    }

    /*
        Fix to eliminate erasing of partially downloaded image on reset by bootlader, skip the first image block write into flash
        instead store it in PDS, so we can write it to Flash once all the packets are received
      */
#if !defined _PIC32CX_BZ3_ 
    ZclOtauRecovery_t *recoveyParams = zclOtauGetRecoveryParams();
    if (OFD_IMAGE_START_ADDRESS == clientMem->ofdParam.offset)
    {
        // Store the first block on to PDS
        memcpy(recoveyParams->image.metaHeader,clientMem->ofdParam.data,clientMem->ofdParam.length);
        PDS_Store(OTAU_RECOVERY_IMAGE_DETAILS_MEM_ID);
    }
#endif
    else if (true != OFD_Write(&clientMem->ofdParam) )
    {
        if(clientMem->ofdParam.ofdWriteRetry--)
        {
            appOtauPrintf("OTAU: Flash Write retry\r\n");
            otauStartGenericTimer(REPOST_OFD_ACTION, otauStartWrite);
        }
        else
        {
            appOtauPrintf("OTAU: Flash Write failed\r\n");
            SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_OPERATION);
            appOtauPrintf("OTAU: Restarting OTA\r\n");
            zclRestartOtauClient();
        }
        return;
     }

     otauStartGenericTimer(REPOST_OFD_ACTION, otauProcessSuccessfullWritingToFlash);
}

/***************************************************************************//**
\brief Restart otau client service
******************************************************************************/
void zclRestartOtauClient(void)
{
  /*Reset Download complete flag in EEPROM(if set)*/

  zclOtauResetRecoveryParams();
  otauStartServerFinding();
  return;
}
/***************************************************************************//**
\brief Stop otau client service
******************************************************************************/
void zclStopOtauClient(void)
{
  ZclOtauMem_t *otauMem = zclGetOtauMem();
  OTAU_SET_STATE(otauStateMachine, OTAU_STOPPED_STATE);

  if (otauMem->isOtauStopTriggered)
  {
    return;
  }
  otauMem->isOtauStopTriggered = true;
  isOtauBusy = false;
  otauStopGenericTimer();

}

/***************************************************************************//**
\brief Checks whether the given IEEE or extended address is valid

\param[in] *addr - pointer to the IEEE or extended address

\return 'true' if address is valid otherwise 'false'
******************************************************************************/
bool isExtAddrValid(ExtAddr_t addr)
{ 
  if ((IS_EQ_EXT_ADDR(addr, ZERO_SERVER_EXT_ADDRESS)) || (IS_EQ_EXT_ADDR(addr, INVALID_SERVER_EXT_ADDRESS)))
  {
    return false;
  }

  return true;
}

/***************************************************************************//**
\brief Fills ZCL_Request_t structure fields for outgoing request.

\param[in] id - zcl command id;
\param[in] length - the length of zcl command payload;
\param[in] payload - pointer to zcl command payload
******************************************************************************/
void zclOtauFillOutgoingZclRequest(uint8_t id, uint8_t length, uint8_t *payload)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_Request_t *tmpZclReq = &(clientMem->reqMem.zclCommandReq);
  uint32_t rspWaitTime = NWK_GetUnicastDeliveryTime();
  uint8_t otauMaxRetryCount = 0;

  CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,&otauMaxRetryCount);

  SYS_E_ASSERT_ERROR((otauMaxRetryCount >= clientMem->retryCount), ZCL_OTAU_INVALID_OTAURETRYCOUNT);

  /* increase the wait time with retries and ceil with predefined timeout */  
  rspWaitTime += (OTAU_DEFAULT_RESPONSE_WAIT_TIMEOUT * ((otauMaxRetryCount+1) - clientMem->retryCount));

  tmpZclReq->dstAddressing.addrMode             = APS_SHORT_ADDRESS;

  tmpZclReq->dstAddressing.addr.shortAddress    = actvServer->serverShortAddress;
  tmpZclReq->dstAddressing.endpointId           = actvServer->serverEndpoint;

  tmpZclReq->dstAddressing.profileId            = zclOtauMem.initParam.profileId;
  tmpZclReq->dstAddressing.clusterId            = OTAU_CLUSTER_ID;
  tmpZclReq->dstAddressing.clusterSide          = ZCL_SERVER_CLUSTER_TYPE;
  tmpZclReq->dstAddressing.manufacturerSpecCode = 0;
  tmpZclReq->dstAddressing.sequenceNumber       = ZCL_GetNextSeqNumber();
  tmpZclReq->endpointId                         = zclOtauMem.initParam.otauEndpoint;
  tmpZclReq->id                                 = id;
  tmpZclReq->defaultResponse                    = ZCL_FRAME_CONTROL_ENABLE_DEFAULT_RESPONSE;
  tmpZclReq->requestLength                      = length;
  tmpZclReq->requestPayload                     = payload;
  tmpZclReq->responseWaitTimeout                = rspWaitTime;
  tmpZclReq->ZCL_Notify                         = otauSomeRequestConfirm;
}

/***************************************************************************//**
\brief Gets Otau's cluster

\return Otau's client cluster
******************************************************************************/
ZCL_Cluster_t ZCL_GetOtauClientCluster(void)
{
  ZCL_Cluster_t cluster = DEFINE_OTAU_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, 
                                    &otauClientAttributes, &otauClientCommands);
  cluster.ZCL_DefaultRespInd = otauSomeDefaultResponse;

  return cluster;
}
#endif // (ZCL_SUPPORT == 1) && (APP_USE_OTAU == 1)
#endif //#ifdef OTAU_CLIENT
// eof zclOtauClient.c
