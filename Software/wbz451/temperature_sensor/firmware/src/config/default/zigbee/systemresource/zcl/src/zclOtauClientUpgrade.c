/*******************************************************************************
  Zigbee Cluster Library OTAU Client Upgrade Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClientUpgrade.c

  Summary:
    The file implements the OTAU client upgrade end request/response handling.

  Description:
    The file implements the OTAU client upgrade end request/response handling.
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

#if APP_DEVICE_OTAU_LOGGING == 1
#include <app_zigbee/zigbee_console/console.h>
#endif
/******************************************************************************
                   Define(s) section
******************************************************************************/
#define CRC_INITIALIZATION_VALUE    0xFF

/******************************************************************************
                   Type definitions section
******************************************************************************/
typedef enum
{
  OTAU_HDR_NOT_AVAILABLE,
  OTAU_HDR_NO_IMGSEC,
  OTAU_HDR_NO_INTEG_CHK,
  OTAU_HDR_INVALID_PARAMETERS,
  OTAU_HDR_UNALLINGED_PAYLOAD,
  OTAU_HDR_DECRYPTION_IN_PROGRESS,
  OTAU_HDR_CRC_SUCCESS,
  OTAU_HDR_CRC_FAILED,
}IntergityCheckStatus_t;


/******************************************************************************
                   External variables section
******************************************************************************/
extern ZclOtauClientStateMachine_t otauStateMachine;
extern ZCL_OtauClusterClientAttributes_t otauClientAttributes;

/******************************************************************************
                        Static variables section
******************************************************************************/
#if (APP_USE_FAKE_OFD_DRIVER == 0)
static uint8_t  localMic[OTAUHDR_INTEGRITYCODE_OCTETLEN] = {0};
static uint32_t otauPayloadSize;

/* dataMinusOne buffer is use to temporary store the ciphered data to use it as 
   IV key for the next block for CBC mode
*/
static ZCL_OtauImageType_t otauHdrImgType = CS_ZCL_OTAU_DEFAULT_IMAGE_TYPE;
#endif

uint32_t otauNVMmem __attribute__((section ("text"))); // TODO
/******************************************************************************
                    Prototypes section
******************************************************************************/
void otauSwitchToNewImage(void);

/******************************************************************************
                   Implementation section
******************************************************************************/


/***************************************************************************//**
\brief Callback from EEPROM driver after completion of otauProceedToIntegrityCheck
******************************************************************************/
void otauSwitchToNewImage(void)
{
    appOtauPrintf("OTAU: Switching to New Image\r\n");
    zclOtauResetRecoveryParams();
    zclRaiseCustomMessage(OTAU_DEVICE_SHALL_CHANGE_IMAGE);
}

/***************************************************************************//**
\brief Sends upgrade end request to server
******************************************************************************/
void otauUpgradeEndReq(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZCL_OtauUpgradeEndReq_t *tmpOtauReq = &clientMem->zclReqMem.uUpgradeEndReq;
  ZCL_Request_t *tmpZclReq = &clientMem->reqMem.zclCommandReq;

  uint16_t csManufacturerId = 0;
  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);

  // If polling is happening already, no need to raise this action
  if (!isOtauInProgress())
  {
    zclRaiseCustomMessage(OTAU_UPGRADE_REQUEST_INITIATED);
  }

  if (!isOtauBusy)
  {
    isOtauBusy = true;
  }
  zclOtauFillOutgoingZclRequest(UPGRADE_END_REQUEST_ID, sizeof(ZCL_OtauUpgradeEndReq_t), (uint8_t *)tmpOtauReq);

  otauSetImageUpgradeStatusAttr(OTAU_DOWNLOAD_COMPLETE);
  tmpOtauReq->status          = clientMem->otauUpgradeEndStatus;
  tmpOtauReq->imageType       = clientMem->downloadingImgType;
  appOtauPrintf("OTAU: Sending Upgrade End request with status 0x%02x\r\n",clientMem->otauUpgradeEndStatus);
  HAL_StopAppTimer(&clientMem->blockResponseWaitTimer);

  tmpOtauReq->manufacturerId  = csManufacturerId;
  memcpy(&tmpOtauReq->firmwareVersion, &clientMem->newFirmwareVersion,sizeof(ZCL_OtauFirmwareVersion_t));

  ZCL_CommandReq(tmpZclReq);
}

/***************************************************************************//**
\brief Handles upgrade end response from server

\param[in] addressing - source parameters
\param[in] payloadLength - length of payload
\param[in] payload - upgrade end parameters pointer
******************************************************************************/

ZCL_Status_t otauUpgradeEndRespInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauUpgradeEndResp_t *payload)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  uint16_t csManufacturerId;
  bool validUpgrdTime = 0;
  uint32_t deltaTime = 0;
  
  (void)addressing;
  (void)payloadLength;

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_WAIT_TO_UPGRADE_STATE))
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_UPGRADE_END_RSP);
    return ZCL_SUCCESS_STATUS;
  }
  else if(isOtauStopped())
  {
    return ZCL_ABORT_STATUS;
  }

  isOtauBusy = false;

  CS_ReadParameter(CS_MANUFACTURER_CODE_ID, &csManufacturerId);

  validUpgrdTime = (payload->upgradeTime >= payload->currentTime)?true:false;

  if (!validUpgrdTime && (csManufacturerId != payload->manufacturerId) && (0xffff != payload->manufacturerId))
  {
    if (clientMem->retryCount--)
    {
      otauStartGenericTimer(AMOUNT_MSEC_IN_SEC, otauUpgradeEndReq);
    }
    else
    {
      zclOtauResetRecoveryParams();
      appOtauPrintf("OTAU: Upgrade end resp retry failed \r\n");
      otauAbortUpgradeProcess();
    }
    return ZCL_MALFORMED_COMMAND_STATUS;
  }

  CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,&clientMem->retryCount);
  // keep querying the server either until finite time is sent or until goes unreachable
  if (UNLIMITED_WAITING_TIME == payload->upgradeTime)
  {
    otauSetImageUpgradeStatusAttr(OTAU_WAITING_TO_UPGRADE);
    // Sould the client polls ?
    otauStartGenericTimer(WAITING_UPGRADE_END_RESPONSE_TIMEOUT, otauUpgradeEndReq);
  }
  else
  {
    otauSetImageUpgradeStatusAttr(OTAU_COUNT_DOWN);
    deltaTime = AMOUNT_MSEC_IN_SEC * (payload->upgradeTime - payload->currentTime);
    appOtauPrintf("OTAU: Upgrade End Resp:Upgrade in %d ms\r\n",deltaTime);
    
    otauStartGenericTimer(deltaTime, otauSwitchToNewImage);
  }
  return ZCL_SUCCESS_STATUS;
}

#endif // (_ZCL_SUPPORT_ == 1) && (APP_USE_OTAU == 1)
#endif // OTAU_CLIENT
//eof zclOtauClientUpgrade.c
