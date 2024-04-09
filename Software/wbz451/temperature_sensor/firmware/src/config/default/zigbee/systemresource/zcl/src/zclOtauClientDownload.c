/*******************************************************************************
  Zigbee Cluster Library OTAU Client Download Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClientDownload.c

  Summary:
    The file implements the OTAU client image downloading part.

  Description:
    The file implements the OTAU client image downloading part.
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
#if APP_USE_OTAU == 1 && defined(_ZCL_SUPPORT_) && defined(OTAU_CLIENT)

/******************************************************************************
                   Includes section
******************************************************************************/
#include <zcl/include/zclOtauManager.h>
#include <zcl/include/zclOtauClient.h>
#include <z3device/otau/ofd/include/ofdMemoryDriver.h>
#include <hal/cortexm4/pic32cx/include/halAes.h>

#if APP_DEVICE_OTAU_LOGGING == 1
#include <app_zigbee/zigbee_console/console.h>
#endif

/******************************************************************************
                   Defines section
******************************************************************************/
#define OTAU_MINIMUM_BLOCK_PERIOD 100

/******************************************************************************
                   External variables section
******************************************************************************/
extern ZclOtauClientStateMachine_t        otauStateMachine;
extern ZCL_OtauClusterClientAttributes_t  otauClientAttributes;

static ZCL_OtauUpgradeImageHeader_t otauImageHeader;

static uint8_t otauAesDecryptIV[AES_BLOCK_SIZE]  = OTA_IMAGE_CBC_IV;
static uint8_t otauAesDecryptKey[AES_BLOCK_SIZE] = OTA_IMAGE_CBC_KEY;

static bool otauImageIVRecovery = false;

/******************************************************************************
                   Prototypes section
******************************************************************************/
static bool otauCheckBlockRespFields(ZCL_OtauImageBlockResp_t *payload);
static bool otauCheckOtauHeaderFields(ZCL_OtauUpgradeImageHeader_t *otauImageHeader);
static void otauProcessImageBlockResponse(void);
static void otauBlockResponseImageDataStoring(ZCL_OtauImageBlockResp_t *payload);
static void otauImageBlockIntervalElapseCB(void);
static void otauImageBlockReq(void);
static void otauImagePageReq(void);

/******************************************************************************
                   Implementation section
******************************************************************************/
    
uint8_t getAesDecryptIVsize (void)
{
    return sizeof(otauAesDecryptIV);
}
void otauSetNewKey(const uint8_t *key)
{
    memcpy(otauAesDecryptKey, key, sizeof(otauAesDecryptKey));
}
void otauSetNewIV(const uint8_t *iv)
{
    memcpy(otauAesDecryptIV, iv, sizeof(otauAesDecryptIV));
}

void setOtauIVrecovery(bool flag)
{
    otauImageIVRecovery = flag;
}
/***************************************************************************//**
\brief Check fields of block response command

\param[in] payload - pointer to command.

\return true - fields are correct,  \n
        false - otherwise.
******************************************************************************/
static bool otauCheckBlockRespFields(ZCL_OtauImageBlockResp_t *payload)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  OtauImageAuxVar_t *tmpAuxParam = &clientMem->imageAuxParam;
  uint16_t csManufacturerId = 0;

  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);

  switch(payload->imageType)
  {
    case OTAU_IMAGE_TYPE_MANU_SPEC_NULL_UPGRADE_FILE :
    case OTAU_IMAGE_TYPE_APPLICATION :
    case OTAU_IMAGE_TYPE_CLIENT_SECURITY_CREDENTIAL :
    case OTAU_IMAGE_TYPE_CLIENT_CONFIGURATION :
    case OTAU_IMAGE_TYPE_SERVER_LOG         :
    case OTAU_IMAGE_TYPE_PICTURE :
    case OTAU_IMAGE_TYPE_WILD_CARD :
      /* for secured image, server needs to propagate the imgType of the OTA file */
      if (
          ((csManufacturerId == payload->manufacturerId) || (0xffff == payload->manufacturerId) )&& 
          (clientMem->newFirmwareVersion.versionId == payload->firmwareVersion.versionId) && 
          (payload->dataSize <= tmpAuxParam->requestBlockSize) && 
          (payload->dataSize != 0) && 
          (payload->fileOffset  < tmpAuxParam->totalImageLength)
       )
      {
        return (true);
      }
      /*else Fall through*/
    default:
      return (false);
    break;
  }
}

/***************************************************************************//**
\brief Check OTAU header fields of the block response command with offset 0

\param[in] payload - pointer to command.

\return true - fields are correct,  \n
        false - otherwise.
******************************************************************************/
static bool otauCheckOtauHeaderFields(ZCL_OtauUpgradeImageHeader_t *otaImageHeader)
{
  uint16_t csManufacturerId = 0;
  uint32_t fileVersion = 0;
    
  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);

  if((OTAUHDR_FILEID != otaImageHeader->upgradeFileID) || 
     //Extract major number and check against OTAUHDR_MAJOR_VERSION
     (OTAUHDR_MAJOR_VERSION != (otaImageHeader->headerVersion >> OTAUHDR_MAJOR_VERSION_SHIFT)) ||
      // If manufacturerId does not match, return false
     ((csManufacturerId != otaImageHeader->manufacturerId) && (0xffff != otaImageHeader->manufacturerId))
    )
    {
      return false;
    }
  
  // check for the manufacturer specific image type, if the image type is other than the
  // manufacturer supported one, return false
  switch(otaImageHeader->imageType)
  {
    case OTAU_IMAGE_TYPE_MANU_SPEC_NULL_UPGRADE_FILE :
    case OTAU_IMAGE_TYPE_APPLICATION :
    case OTAU_IMAGE_TYPE_CLIENT_SECURITY_CREDENTIAL :
    case OTAU_IMAGE_TYPE_CLIENT_CONFIGURATION :
    case OTAU_IMAGE_TYPE_SERVER_LOG         :
    case OTAU_IMAGE_TYPE_PICTURE :
    case OTAU_IMAGE_TYPE_WILD_CARD :
  break;
  
  default:
   return (false);
  }
  if(zclGetOtauClientMem()->imageAuxParam.totalImageLength != otaImageHeader->totalImageSize)
  {
     appOtauPrintf("OTAU: Image Length Mismatch QR %d, OH %d\r\n",
        zclGetOtauClientMem()->imageAuxParam.totalImageLength,
        otaImageHeader->totalImageSize);
      return false;
  }
  CS_ReadParameter(CS_ZCL_OTAU_FILE_VERSION_ID, &fileVersion);
  
  if(otaImageHeader->firmwareVersion.versionId == fileVersion)
    return false;

  return (true);
}


/***************************************************************************//**
\brief Stores received from image block response data to page buffer or
       to flash directly (depends on page request usage).

\param[in] payload - payload form received image block response
******************************************************************************/

static void otauBlockResponseImageDataStoring(ZCL_OtauImageBlockResp_t *payload)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZclOtauClientImageBuffer_t *tmpOtauParam = &clientMem->otauParam;
  OFD_MemoryAccessParam_t *tmpOfdParam = &clientMem->ofdParam;

  memcpy(&tmpOtauParam->receivedImgBlock, payload->imageData, payload->dataSize);
  tmpOfdParam->data = tmpOtauParam->receivedImgBlock;
  tmpOfdParam->length = payload->dataSize;

#if !defined _PIC32CX_BZ3_
  /* Decrypt the packet before writing into the flash */

  /*Step 1: Set CBC key and IV*/
  halAesSetKeyIV(otauAesDecryptKey, otauAesDecryptIV);
  /* Step 2: Copy the lasy 16bytes as new IV for the next Image block to be received */
  memcpy(otauAesDecryptIV, &tmpOfdParam->data[tmpOfdParam->length - sizeof(otauAesDecryptIV)] , sizeof(otauAesDecryptIV));
  /* Step 3: Perfrom the decryption of the current image block */
  halAesCBC_Decrypt(tmpOfdParam->data, tmpOfdParam->length);
#endif
  /*Step 4: Write the decrypted block into flash*/
  CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT, &clientMem->ofdParam.ofdWriteRetry);
  otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT ,otauStartWrite);

}

/***************************************************************************//**
\brief Process the successful image block received as per the current state

\param[in] payload - data pointer.

\return status of the processing
******************************************************************************/
void otauRestartBlockRxTimer (void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  HAL_AppTimer_t *tmpBlockRespTimer = &clientMem->blockResponseWaitTimer;

  HAL_StopAppTimer(tmpBlockRespTimer);

  if(otauClientAttributes.minimumBlockPeriod.value)
    tmpBlockRespTimer->interval  = ((NWK_GetUnicastDeliveryTime() + (otauClientAttributes.minimumBlockPeriod.value)) * 4);
  else
    tmpBlockRespTimer->interval  = (NWK_GetUnicastDeliveryTime() + AMOUNT_MSEC_IN_SEC) * 4;
  tmpBlockRespTimer->mode      = TIMER_ONE_SHOT_MODE;
  tmpBlockRespTimer->callback  = otauImageBlockIntervalElapseCB;
  HAL_StartAppTimer(tmpBlockRespTimer);
  return;
}

/***************************************************************************//**
\brief otauProcessImageBlockResponse
******************************************************************************/
static void otauProcessImageBlockResponse (void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  if (OTAU_IMAGE_TYPE_MANU_SPEC_NULL_UPGRADE_FILE == clientMem->blockResp.imageType)
  {
    clientMem->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;
    otauUpgradeEndReq();
    otauStartGenericTimer(AMOUNT_MSEC_IN_SEC,otauStartDiscoveryTimer);
    return;
  }
  else if(0 == clientMem->blockResp.fileOffset) // if its the first
  {
  #if defined _PIC32CX_BZ3_
    DRV_HANDLE *handle = getSstHandle();
	*handle = DRV_SST26_Open(sysObj.drvSST26, DRV_IO_INTENT_READWRITE);
	(void) DRV_SST26_ChipErase(*handle);
	while(DRV_SST26_TransferStatusGet(*handle) == DRV_SST26_TRANSFER_BUSY);
  #endif
    memcpy(&otauImageHeader, clientMem->blockResp.imageData, clientMem->blockResp.dataSize);
    clientMem->imageAuxParam.requestFileOffset = clientMem->blockResp.dataSize;
    clientMem->imageAuxParam.requestBlockSize = sizeof(otauImageHeader) - clientMem->blockResp.dataSize;
    otauScheduleImageBlockReq();
    return;
  }
  else if((0 != clientMem->blockResp.fileOffset) && (clientMem->blockResp.fileOffset < sizeof(otauImageHeader) ))
  {
    // got the remaining part of OTAU header
    uint32_t headerOffset = (uint32_t )&otauImageHeader + clientMem->blockResp.fileOffset;
    memcpy((void *)headerOffset, clientMem->blockResp.imageData,clientMem->blockResp.dataSize);

    if(!otauCheckOtauHeaderFields(&otauImageHeader))
    {
        appOtauPrintf("OTAU: OTAU Header Mismatch\r\n");
        otauAbortUpgradeProcess();
        return;
        
    }

    clientMem->imageAuxParam.requestFileOffset = clientMem->blockResp.fileOffset + clientMem->blockResp.dataSize;
    // Handle NULL image
    if(clientMem->imageAuxParam.totalImageLength == clientMem->imageAuxParam.requestFileOffset)
    {
        // It was just a null Image
        // Send Upgrade End Request with 
        clientMem->otauUpgradeEndStatus = ZCL_INVALID_IMAGE_STATUS;
        otauUpgradeEndReq();
        otauSetImageUpgradeStatusAttr(OTAU_NORMAL);

        zclOtauResetRecoveryParams();
        zclOtauResetAttributesPDS();
        clientMem->imageAuxParam.requestFileOffset      = 0;
        clientMem->imageAuxParam.requestBlockSize       = OTAU_MAX_REQ_BLOCK_SIZE;
        clientMem->imageAuxParam.totalImageLength       = 0; 

        clientMem->otauParam.receivedImgBlockSize       = 0;
        clientMem->newFirmwareVersion.versionId         = 0;

        otauStartGenericTimer(AMOUNT_MSEC_IN_SEC,otauStartDiscoveryTimer);
        return;
    }
    
    clientMem->imageAuxParam.requestBlockSize = OTAU_MAX_REQ_BLOCK_SIZE;
#if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
	 otauScheduleImagePageReq();
 #else
	 otauScheduleImageBlockReq();
 #endif 

    return ;
  }
  else if (true == otauImageIVRecovery)
  {
    otauImageIVRecovery = false;
    #if !defined _PIC32CX_BZ3_
      memcpy(otauAesDecryptIV, clientMem->blockResp.imageData, sizeof(otauAesDecryptIV));
      clientMem->imageAuxParam.requestFileOffset = clientMem->blockResp.fileOffset + clientMem->blockResp.dataSize;
    #else
      clientMem->imageAuxParam.requestFileOffset = ((((clientMem->blockResp.fileOffset + clientMem->blockResp.dataSize)/DRV_SST26_PAGE_SIZE)-1)*DRV_SST26_PAGE_SIZE)+sizeof(otauImageHeader);
    #endif
    otauSetImageUpgradeStatusAttr(OTAU_DOWNLOAD_IN_PROGRESS);
    
    clientMem->imageAuxParam.requestBlockSize = OTAU_MAX_REQ_BLOCK_SIZE;
    clientMem->ofdParam.offset = OFD_IMAGE_START_ADDRESS + clientMem->imageAuxParam.requestFileOffset - sizeof(otauImageHeader);
    #if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
      otauScheduleImagePageReq();
    #else
      otauScheduleImageBlockReq();
    #endif
    
    return;
  }

  else// its an image block
  {
    if (OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE) && 
              (clientMem->blockResp.fileOffset == clientMem->imageAuxParam.requestFileOffset))
    {
      /*Restoring the retry count since a sucessful block is received*/
      CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,&clientMem->retryCount);
      otauBlockResponseImageDataStoring(&clientMem->blockResp);
    }
    else if (clientMem->retryCount--)
    {
      otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT,otauScheduleImageBlockReq); //TODO:  page mode
      return ;
    }
    else
    {
      appOtauPrintf("OTAU: Block request retry failed\r\n");
      otauAbortUpgradeProcess();
    }
    return;
  }
}

/***************************************************************************//**
\brief Process the image block received with wait status as per the current state

\param[in] payload - data pointer.

\return status of the processing
******************************************************************************/
ZCL_Status_t otauProcessWaitDataImageBlockResponse(ZCL_OtauImageBlockResp_t *payload)
{
  uint32_t tempDelay= 0;

  if(0 == payload->requestTime - payload->currentTime)
  {
    tempDelay  =  payload->minimumBlockPeriod;
    otauClientAttributes.minimumBlockPeriod.value = tempDelay;
    PDS_Store(OTAU_MIN_BLOCK_PERIOD_ATTR_MEM_ID);
  }
  else if (payload->requestTime > payload->currentTime)
  { /*One time delay for next block request*/
    tempDelay = ((payload->requestTime  - payload->currentTime) * AMOUNT_MSEC_IN_SEC);
  }
  else
  {
    zclRaiseCustomMessage(OTAU_SERVER_RECEIVED_MALFORMED_COMMAND);
    otauSetImageUpgradeStatusAttr(OTAU_NORMAL);
    otauStartQueryTimer();
    return (ZCL_MALFORMED_COMMAND_STATUS);
  }
  appOtauPrintf("OTAU: Wait For data delay %d\r\n",tempDelay);
  if( OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE) )
  {
    #if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
    otauScheduleImagePageReq();
    #else
    otauScheduleImageBlockReq();
    #endif
    
  }

  else
  {
    appOtauPrintf("OTAU: Wait for data in wrong state\r\n");
    otauAbortUpgradeProcess();
  }
  return (ZCL_SUCCESS_STATUS);
}

/***************************************************************************//**
\brief Image block response indication

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer.

\return status of indication routine
******************************************************************************/
ZCL_Status_t otauImageBlockRespInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauImageBlockResp_t *payload)
{
  ZCL_Status_t status = ZCL_SUCCESS_STATUS;
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  /* Stop the running block timer as we received a block response*/
  HAL_StopAppTimer(&clientMem->blockResponseWaitTimer);
  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE)) 
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_IMAGE_BLOCK_RSP);
    appOtauPrintf("OTAU: Block resp indication in wrong state\r\n");
    return (ZCL_SUCCESS_STATUS);
  }

  switch(payload->status)
  {
    case ZCL_SUCCESS_STATUS:
      if (!otauCheckBlockRespFields(payload))
      {
        appOtauPrintf("OTAU: Check block resp failed\r\n");
        zclRaiseCustomMessage(OTAU_SERVER_RECEIVED_MALFORMED_COMMAND);
        if(clientMem->retryCount--)
        {
          if (OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE) )
          {
            otauScheduleImageBlockReq();
          }
        }
        else
        { // Retry failed 
          appOtauPrintf("OTAU: Check block resp retry failed\r\n");
          otauAbortUpgradeProcess();
        }
        return ZCL_MALFORMED_COMMAND_STATUS;
      }
      else
      {
        memcpy(&clientMem->blockResp, payload, sizeof(ZCL_OtauImageBlockResp_t));
        otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauProcessImageBlockResponse);
      }
      return (ZCL_SUCCESS_STATUS);
    break;

    case ZCL_ABORT_STATUS:
      isOtauBusy = false;
      otauStopGenericTimer();
      zclOtauResetRecoveryParams();
      zclOtauResetAttributesPDS();

      zclRaiseCustomMessage(OTAU_DOWNLOAD_ABORTED);
      /*Context switch to Discovery*/
      otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT,otauStartDiscoveryTimer);
      appOtauPrintf("OTAU: Server aborted the download\r\n");
      return (ZCL_SUCCESS_STATUS);
    break;

    case ZCL_WAIT_FOR_DATA_STATUS:
      status = otauProcessWaitDataImageBlockResponse(payload);
    break;

    default:
      appOtauPrintf("OTAU: Block resp indication -Malformed\r\n");
      status = ZCL_MALFORMED_COMMAND_STATUS;
      zclRaiseCustomMessage(OTAU_SERVER_RECEIVED_MALFORMED_COMMAND);
      if (clientMem->retryCount--)
      {
#if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
        otauScheduleImagePageReq();
#else
        otauScheduleImageBlockReq();
#endif // APP_SUPPORT_OTAU_PAGE_REQUEST == 1
      }
      else  // Even retrying is failed, so give up this upgrade and start again
      {
        appOtauPrintf("OTAU: Block resp indication wrong status retry failed\r\n");
        otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauAbortUpgradeProcess);
      }
    break;
  }

  (void)addressing;
  (void)payloadLength;
  return status;
}

/***************************************************************************//**
\brief Send image block request
******************************************************************************/
static void otauImageBlockReq(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_OtauImageBlockReq_t *tmpOtauReq = &clientMem->zclReqMem.uImageBlockReq;
  ZCL_Request_t *tmpZclReq = &clientMem->reqMem.zclCommandReq;
  uint16_t csManufacturerId;
  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);

  HAL_StopAppTimer(&clientMem->blockResponseWaitTimer);

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_IMAGE_BLOCK_REQ);
    return;
  }

  if (!isOtauBusy)
  {
    isOtauBusy = true;
  }

  zclOtauFillOutgoingZclRequest(IMAGE_BLOCK_REQUEST_ID, sizeof(ZCL_OtauImageBlockReq_t), (uint8_t *)tmpOtauReq);

  tmpOtauReq->controlField.blockRequestDelayPresent = 1;
  tmpOtauReq->controlField.reqNodeIeeeAddrPresent   = 0;
  tmpOtauReq->controlField.reserved                 = 0;
  tmpOtauReq->manufacturerId                        = csManufacturerId;
  tmpOtauReq->imageType                             = clientMem->downloadingImgType;
  memcpy(&tmpOtauReq->firmwareVersion,&clientMem->newFirmwareVersion,sizeof(ZCL_OtauFirmwareVersion_t));
  tmpOtauReq->fileOffset                            = clientMem->imageAuxParam.requestFileOffset;
  tmpOtauReq->maxDataSize                           = clientMem->imageAuxParam.requestBlockSize;
  tmpOtauReq->minimumBlockPeriod                    = otauClientAttributes.minimumBlockPeriod.value;
  ZCL_CommandReq(tmpZclReq);
  otauRestartBlockRxTimer();
}

/***************************************************************************//**
\brief Shedule image block request
******************************************************************************/
void otauScheduleImageBlockReq(void)
{
  //no need to go for sleeo during the OTAU procedure
  if (!isOtauBusy)
  {
    isOtauBusy = true;
  }
  /*Add a minimum delay for scheduling if the minimumBlockPeriod is set less than OTAU_MINIMUM_BLOCK_PERIOD*/
  if (otauClientAttributes.minimumBlockPeriod.value > OTAU_MINIMUM_BLOCK_PERIOD)
    otauStartGenericTimer(otauClientAttributes.minimumBlockPeriod.value, otauImageBlockReq);
  else
    otauStartGenericTimer(OTAU_MINIMUM_BLOCK_PERIOD, otauImageBlockReq);
}
/***************************************************************************//**
\brief Shedule image page request
******************************************************************************/
void otauScheduleImagePageReq(void)
{
  if (otauClientAttributes.minimumBlockPeriod.value > OTAU_MINIMUM_BLOCK_PERIOD)
  {
    otauStartGenericTimer(otauClientAttributes.minimumBlockPeriod.value, otauImagePageReq);
  }
  else
  {
    otauStartGenericTimer(OTAU_MINIMUM_BLOCK_PERIOD, otauImagePageReq);
  }
}

/***************************************************************************//**
\brief Send image page request
******************************************************************************/
static void otauImagePageReq(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  OtauImageAuxVar_t *tmpAuxParam = &clientMem->imageAuxParam;
  ZCL_OtauImagePageReq_t *tmpOtauReq = &clientMem->zclReqMem.uImagePageReq;
  ZCL_Request_t *tmpZclReq = &clientMem->reqMem.zclCommandReq;
  
  uint16_t csManufacturerId = 0;

  HAL_StopAppTimer(&clientMem->blockResponseWaitTimer);

  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);
  
  zclOtauFillOutgoingZclRequest(IMAGE_PAGE_REQUEST_ID, sizeof(ZCL_OtauImagePageReq_t), (uint8_t *)tmpOtauReq);
  tmpOtauReq->controlField.reqNodeIeeeAddrPresent = 0;
  tmpOtauReq->controlField.reserved               = 0;
  tmpOtauReq->manufacturerId                      = csManufacturerId;
  tmpOtauReq->imageType                           = clientMem->downloadingImgType;
  memcpy(&tmpOtauReq->firmwareVersion, &clientMem->newFirmwareVersion, sizeof(ZCL_OtauFirmwareVersion_t));
  tmpOtauReq->fileOffset                          = tmpAuxParam->requestFileOffset;
  tmpOtauReq->maxDataSize                         = tmpAuxParam->requestBlockSize;
  tmpOtauReq->pageSize                            = CS_ZCL_OTAU_IMAGE_PAGE_REQUEST_PAGE_SIZE;

  tmpOtauReq->responseSpacing = otauClientAttributes.minimumBlockPeriod.value;
  if (!isOtauBusy)
  {
    isOtauBusy = true;
  }
  ZCL_CommandReq(tmpZclReq);
  otauRestartBlockRxTimer();
}

/***************************************************************************//**
\brief ReqInterval duration has elapsed
******************************************************************************/
static void otauImageBlockIntervalElapseCB(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  if(clientMem->retryCount--)
  {
    /*  Retry last request  */
    appOtauPrintf("OTAU: Retrying last packet %d\r\n",clientMem->imageAuxParam.requestFileOffset);
    
#if APP_SUPPORT_OTAU_PAGE_REQUEST == 1
      otauImagePageReq();
#else
      otauImageBlockReq();
#endif
  }
  else
  {
    appOtauPrintf("OTAU: RX Timer elapsed Retry failed \r\n");
    /*Send upgrade end request?*/
    otauAbortUpgradeProcess();
  }
}
/***************************************************************************//**
\brief Start or continue the image download
******************************************************************************/
void otauStartDownload(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  OtauImageAuxVar_t *tmpAuxParam = &clientMem->imageAuxParam;

  if(!OTAU_CHECK_STATE(otauStateMachine,OTAU_START_DOWNLOAD_STATE))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_START_DOWNLOAD);
    return;
  }

  otauSetImageUpgradeStatusAttr(OTAU_DOWNLOAD_IN_PROGRESS);
  tmpAuxParam->requestBlockSize = OTAU_MAX_REQ_BLOCK_SIZE;


  OTAU_SET_STATE(otauStateMachine,OTAU_GET_IMAGE_DOWNLOADING_STATE);
  if (tmpAuxParam->totalImageLength < OTAU_MAX_REQ_BLOCK_SIZE)
  {
    otauAbortUpgradeProcess();
    return;
  }
  /*Always start with block request irrespective of the page mode settings*/
  otauScheduleImageBlockReq();
}

#endif // (_ZCL_SUPPORT_ == 1) && (APP_USE_OTAU == 1)

//eof zclOtauClientDownload.c
