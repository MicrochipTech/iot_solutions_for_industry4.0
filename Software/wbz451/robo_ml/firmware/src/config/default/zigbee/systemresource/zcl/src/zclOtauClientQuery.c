/*******************************************************************************
  Zigbee Cluster Library OTAU Client Query Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClientQuery.c

  Summary:
    The file implements the OTAU client querying for image part.

  Description:
    The file implements the OTAU client querying for image part.
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
#include <pds/include/wlPdsMemIds.h>
#include <systemenvironment/include/sysTypes.h>

#if APP_DEVICE_OTAU_LOGGING == 1
#include <app_zigbee/zigbee_console/console.h>
#endif

/******************************************************************************
                   External variables section
******************************************************************************/
extern ZclOtauClientStateMachine_t otauStateMachine;
extern ZCL_OtauClusterClientAttributes_t otauClientAttributes;
extern ExtAddr_t tempServerExtAddr;

extern ExtAddr_t otauUnauthorizedServers[OTAU_MAX_UNAUTHORIZED_SERVERS];
extern ZclOtauDiscoveryResult_t *actvServer;

/******************************************************************************
                   Global variables section
******************************************************************************/
static void otauStartImageLoading(void);
static void otauSendQueryNextImageReq(void);

/******************************************************************************
                   Implementation section
******************************************************************************/


/***************************************************************************//**
\brief Sends the new image req with the updated imgtype value
******************************************************************************/
static void otauSendQueryNextImageReq(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_OtauQueryNextImageReq_t *tmpOtauReq = &clientMem->zclReqMem.uQueryNextImageReq;
  ZCL_Request_t *tmpZclReq = &clientMem->reqMem.zclCommandReq;
  uint16_t csManufacturerId = 0;
  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);
  
  //Enabling fast polling for Query Next Image
  if (!isOtauBusy)
  {
    zclRaiseCustomMessage(OTAU_QUERY_NEXT_IMAGE_INITIATED);
    isOtauBusy = true;
  }

  zclOtauFillOutgoingZclRequest(QUERY_NEXT_IMAGE_REQUEST_ID, sizeof(ZCL_OtauQueryNextImageReq_t), (uint8_t *)tmpOtauReq);

  tmpOtauReq->controlField.hardwareVersionPresent = 0;
  tmpOtauReq->controlField.reserved               = 0;
  tmpOtauReq->manufacturerId                      = csManufacturerId;
  tmpOtauReq->imageType                           = 0xffff;//TODO: clientMem->eepromImgType;
  memcpy(&tmpOtauReq->currentFirmwareVersion, &zclOtauMem.initParam.firmwareVersion,sizeof(ZCL_OtauFirmwareVersion_t));

  ZCL_CommandReq(tmpZclReq);
}

/***************************************************************************//**
\brief Start to query after elapsing a jitter

\param[in] queryJitter - queryJitter value
******************************************************************************/
static void otauQueryAfterJitter(uint8_t queryJitter)
{
  uint16_t generatedRandomJitter = 0;

  generatedRandomJitter = SYS_GetNormalizedRandomNumber(OTAU_IMAGE_NOTIFY_MAX_QUERY_JITTER_VALUE);

  if (generatedRandomJitter <= queryJitter)
  {
    /*If the generated value is less than or equal to the received value
          for QueryJitter, it SHALL query the upgrade server.
          If not, then it SHALL discard the message and no further processing SHALL continue*/
    otauStartQueryTimer();
  }
  return;
}

/***************************************************************************//**
\brief Query next image response indication

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer.

\return status of indication routine
******************************************************************************/
ZCL_Status_t otauQueryNextImageRespInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauQueryNextImageResp_t *payload)
{
  
  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_QUERY_FOR_IMAGE_STATE))
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_QUERY_NEXT_IMAGE_RSP);
    otauStartQueryTimer();
    return (ZCL_SUCCESS_STATUS);
  }

  isOtauBusy = false;

  switch (payload->status)
  {
    case ZCL_NO_IMAGE_AVAILABLE_STATUS:
      otauStartQueryTimer();
      break;

    case ZCL_NOT_AUTHORIZED_STATUS:
      for (uint8_t i = 0; i < OTAU_MAX_UNAUTHORIZED_SERVERS; i++)
      {
        if ((otauUnauthorizedServers[i] == ZERO_SERVER_EXT_ADDRESS) || \
            (otauUnauthorizedServers[i] == INVALID_SERVER_EXT_ADDRESS))
        {
          COPY_EXT_ADDR(otauUnauthorizedServers[i], tempServerExtAddr);
        }
      }
      tempServerExtAddr = INVALID_SERVER_EXT_ADDRESS;
      otauStartDiscovery();
      break;

    case ZCL_SUCCESS_STATUS:
    {
      uint16_t csManufacturerId = 0;
      
      ZCL_OtauFirmwareVersion_t version = zclGetOtauMem()->initParam.firmwareVersion;

      otauStopGenericTimer();
      CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);
      if (((csManufacturerId != payload->manufacturerId) && (0xffff != payload->manufacturerId)) ||
          ((OTAU_IMAGE_TYPE_MANU_SPEC_NULL_UPGRADE_FILE != payload->imageType) &&
          (OTAU_IMAGE_TYPE_WILD_CARD != payload->imageType) &&
          (OTAU_IMAGE_TYPE_APPLICATION != payload->imageType) &&
          (OTAU_IMAGE_TYPE_CLIENT_SECURITY_CREDENTIAL != payload->imageType))
          )
      {
        /*If manufactures ID and Image Type doesn't match, send malformed command and restart discovery*/
        zclRaiseCustomMessage(OTAU_SERVER_RECEIVED_MALFORMED_COMMAND);
        /*Restart OTAU discovery*/
        otauStartDiscoveryTimer();
        return (ZCL_MALFORMED_COMMAND_STATUS);
      }
      else if (0 == memcmp(&version, &payload->currentFirmwareVersion, sizeof(ZCL_OtauFirmwareVersion_t)))
      {
        SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_OPERATION);
        otauStartQueryTimer();
      }
      else  // All parameters are good, proceed to Download
      {
        ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
        OTAU_SET_STATE(otauStateMachine,OTAU_START_DOWNLOAD_STATE);
        clientMem->downloadingImgType = payload->imageType;
        memcpy(&clientMem->queryNextImageResp, payload, sizeof(ZCL_OtauQueryNextImageResp_t));
        otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauStartImageLoading);
      }
    }
    break;

    default:
      /*Restart OTAU discovery*/
      otauStartDiscoveryTimer();
      return (ZCL_MALFORMED_COMMAND_STATUS);
  }

  (void)addressing;
  (void)payloadLength;
  return (ZCL_SUCCESS_STATUS);
}

/***************************************************************************//**
\brief Start image downloading process
******************************************************************************/
static void otauStartImageLoading(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_OtauQueryNextImageResp_t *payload = &clientMem->queryNextImageResp;

  /*Image size shall be greater than the OTAU header size*/
  if (sizeof(ZCL_OtauUpgradeImageHeader_t) > payload->imageSize)
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_IMAGE_RECEIVED);

    clientMem->imageAuxParam.requestFileOffset  = 0;
    clientMem->imageAuxParam.requestBlockSize   = OTAU_MAX_REQ_BLOCK_SIZE;
    clientMem->imageAuxParam.totalImageLength   = 0;

    zclOtauResetAttributesPDS();
    zclOtauResetRecoveryParams();

    //file is empty, send upgrade end req with invalid image status
    clientMem->otauUpgradeEndStatus = ZCL_INVALID_IMAGE_STATUS;
    appOtauPrintf("OTAU: Query resp Empty file  \r\n");
    otauAbortUpgradeProcess();
    return;
  }

  ZclOtauRecovery_t *recoveryParams = zclOtauGetRecoveryParams();

  if (PDS_IsAbleToRestore(OTAU_RECOVERY_DIR_ID))
  {
    PDS_Restore(OTAU_RECOVERY_DIR_ID);
    
    appOtauPrintf("OTAU: PDS Restored\r\n");

    /*Check the paylod parameters against the image to be recovered*/
    if( (0 == memcmp(&recoveryParams->image.version, &payload->currentFirmwareVersion, sizeof(ZCL_OtauFirmwareVersion_t))) &&
        (recoveryParams->image.totalSize == payload->imageSize) )
    {
      appOtauPrintf("OTAU: Image Version and Size Matched\r\n");

      clientMem->imageAuxParam.totalImageLength = payload->imageSize;
      memcpy(&clientMem->newFirmwareVersion,&recoveryParams->image.version,sizeof(ZCL_OtauFirmwareVersion_t));

      if (recoveryParams->fileOffset == recoveryParams->image.totalSize)
      { // full file is already present, proceed to upgrade
        OTAU_SET_STATE(otauStateMachine, OTAU_WAIT_TO_UPGRADE_STATE);
        appOtauPrintf("OTAU: Recovery Image already available\r\n");
        clientMem->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;
        otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauUpgradeEndReq);
        return;
      }

      if(recoveryParams->fileOffset == 0)
      {
        clientMem->imageAuxParam.requestBlockSize = OTAU_MAX_REQ_BLOCK_SIZE;
        appOtauPrintf("OTAU: Fresh Download after restore\r\n");
        clientMem->ofdParam.offset = OFD_IMAGE_START_ADDRESS;
      }
      else
      {
      #if !defined _PIC32CX_BZ3_  
        clientMem->imageAuxParam.requestFileOffset = recoveryParams->fileOffset - getAesDecryptIVsize();
        clientMem->imageAuxParam.requestBlockSize = getAesDecryptIVsize();
      #else
        clientMem->imageAuxParam.requestFileOffset = recoveryParams->fileOffset - OTAU_MAX_REQ_BLOCK_SIZE;
        clientMem->imageAuxParam.requestBlockSize = OTAU_MAX_REQ_BLOCK_SIZE;
        DRV_HANDLE *handle = getSstHandle();
        //Erase 4 sectors of 4k each from the restored file offset
        for(uint8_t sectorIndex  = 0; sectorIndex  < OTAU_MAX_SECTOR_ERASE; sectorIndex ++)
        {
          //Erase 4 sectors of 4k each from the restored file offset
          (void)DRV_SST26_SectorErase(*handle,recoveryParams->fileOffset+(sectorIndex*NVM_FLASH_PAGESIZE));
        }
        while(DRV_SST26_TransferStatusGet(*handle) == DRV_SST26_TRANSFER_BUSY);
      #endif
        appOtauPrintf("Restored file offset %d\r\n",recoveryParams->fileOffset);
        setOtauIVrecovery(true);
      }
      OTAU_SET_STATE(otauStateMachine, OTAU_GET_IMAGE_DOWNLOADING_STATE);
      otauScheduleImageBlockReq();
      return;
    }
    else
    {
      appOtauPrintf("OTAU: Image Version or Size Invalid\r\n");
    }
  }
  else
  {
    // <Assert warning and notify application>
  }
  appOtauPrintf("OTAU: Fresh Download\r\n");
  recoveryParams->fileOffset = 0;
  recoveryParams->image.totalSize = payload->imageSize;
  memcpy(&recoveryParams->image.version, &payload->currentFirmwareVersion, sizeof(ZCL_OtauFirmwareVersion_t));

  /*Do fresh Download*/
  // If atleast one of the above check failed then restart the download from scratch.
  clientMem->newFirmwareVersion.versionId     = payload->currentFirmwareVersion.versionId;
  clientMem->imageAuxParam.totalImageLength   = payload->imageSize;
  clientMem->imageAuxParam.requestFileOffset  = 0;

  clientMem->ofdParam.offset = OFD_IMAGE_START_ADDRESS;
  OTAU_SET_STATE(otauStateMachine,OTAU_START_DOWNLOAD_STATE);
  PDS_Store(OTAU_RECOVERY_DIR_ID);
#if !defined _PIC32CX_BZ3_  
  otauStartErase();
#else
  otauStartDownload();
#endif
}


/***************************************************************************//**
\brief Image notify indication

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer.

\return status of indication routine
******************************************************************************/
ZCL_Status_t otauImageNotifyInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauImageNotify_t *payload)
{
  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_QUERY_FOR_IMAGE_STATE))
  {
    /*Client has to be in query state to process Image notification*/
    appOtauPrintf("Image Notify at wrong state %d\r\n",otauStateMachine);
    return ZCL_SUCCESS_STATUS;
  }

  appOtauPrintf("IMG Notify Type %d Jitter %d\r\n",payload->payloadType,payload->queryJitter);

  /* For payload type value of 0x01, if manufacturer code matches the
  * device's own value, the device shall proceed. For payload type value
  * of 0x02, if both manufacturer code and image type match the device's
  * own values, the device shall proceed. For payload type value of 0x03
  * if both manufacturer code and image type match the device's own values
  * but the new file version is not a match, the device shall proceed.
  *
  * - Chapter 6.10.3.4, ZigBee OTAU Cluster Spec 095264r19
  */

  if (addressing->nonUnicast)
  {
    // Broadcast IN

    /* For invalid broadcast or multicast Image Notify command, for example,
     * out-of-range query jitter value is used, or the reserved payload type
     * value is used, or the command is badly formatted, the client shall
     * ignore such command and no processing shall be done.
     *
     * - Chapter 6.10.3.5, ZigBee OTAU Cluster Spec 095264r19
     */
    uint16_t csManufacturerId = 0;

    switch (payload->payloadType)
    {
      case OTAU_PAYLOAD_TYPE_NEW_FILE_VERSION:

      case OTAU_PAYLOAD_TYPE_IMAGE_TYPE:

        switch (payload->imageType)
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
            return ZCL_SUCCESS_STATUS;
            break;
        }

      case OTAU_PAYLOAD_TYPE_MANUFACTURER_CODE:
        CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);
        if ((csManufacturerId != payload->manufacturerCode))
        {
          return ZCL_SUCCESS_STATUS;
        }

      case OTAU_PAYLOAD_TYPE_QUERY_JITTER:
        if (!payload->queryJitter || ( payload->queryJitter > OTAU_IMAGE_NOTIFY_MAX_QUERY_JITTER_VALUE))
        {
          return ZCL_SUCCESS_STATUS;
        }
        break;
      default:
        return ZCL_SUCCESS_STATUS;
        break;
    }
    otauQueryAfterJitter(payload->queryJitter);
  }
  else
  { // For Unicast Image notification, Send Image Query irrespective of any parameters
    otauStartQueryTimer();
  }
  zclRaiseCustomMessage(OTAU_IMAGE_NOTIFICATION_RECEIVED);

  (void)payloadLength;
  return ZCL_SUCCESS_STATUS;
}

/***************************************************************************//**
\brief Start timer to elapse query interval
******************************************************************************/
void otauStartQueryTimer(void)
{
  uint32_t queryInterval;
  
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  
  CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,&clientMem->retryCount);
  CS_ReadParameter(CS_ZCL_OTAU_QUERY_INTERVAL_ID, &queryInterval);
  OTAU_SET_STATE(otauStateMachine, OTAU_QUERY_FOR_IMAGE_STATE);
  isOtauBusy = false;
  otauStartGenericTimer(queryInterval, otauSendQueryNextImageReq);
}

#endif // (_ZCL_SUPPORT_ == 1) && (APP_USE_OTAU == 1)

//eof zclOtauClientQuery.c
