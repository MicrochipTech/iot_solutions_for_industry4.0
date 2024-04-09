/*******************************************************************************
  Combined Interface IASZone cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
   ciIasZoneCluster.h

  Summary:
    This file contains the Combined Interface IASZone cluster implementation.

  Description:
    This file contains the Combined Interface IASZone cluster implementation.
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE)

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/common/include/appConsts.h>
#include <z3device/combinedInterface/include/ciIasZoneCluster.h>
#include <z3device/combinedInterface/include/ciIasACECluster.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/clusters/include/haClusters.h>
#include <app_zigbee/zigbee_console/console.h>
#include <app_zigbee/app_zigbee_handler.h>
/******************************************************************************
                    Local variables section
******************************************************************************/
#define IEEE_ADDRESS_LENGTH       0x08
/******************************************************************************
                    Prototypes section
******************************************************************************/
static ZCL_Status_t zoneStatusChangeNotificationCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ZoneStatusChangeNot_t *payload);
static ZCL_Status_t zoneEnrollRequestCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ZoneEnrollRequest_t *payload);
static void zoneTableEntry(ZCL_ZoneEnrollResCommand_t *response, ZCL_ZoneEnrollRequest_t *payload, ZCL_Addressing_t *addressing);
void writeAttrCallback(ZCL_Notify_t *ntfy);
ZCL_Status_t zoneAutoEnrollResponse(ZCL_Notify_t *ntfy);
/*****************************************************************************/

/******************************************************************************
                    global variables section
******************************************************************************/
zoneTable_t zoneTables[ZONE_TABLE_ENTRIES];
/******************************************************************************
                   defines section
******************************************************************************/
PROGMEM_DECLARE (ZCL_IasZoneClusterCommands_t ciIASZoneClusterClientCommands) =
{
  ZCL_DEFINE_IAS_ZONE_CLUSTER_COMMANDS(zoneStatusChangeNotificationCommandInd, zoneEnrollRequestCommandInd, NULL, NULL, NULL)
};

ZCL_IasZoneClusterClientAttributes_t ciZoneClusterClientAttributes =
{
  ZCL_DEFINE_IAS_ZONE_CLUSTER_CLIENT_ATTRIBUTES()
};

static uint16_t zone_type = APP_IAS_ZONE_TYPE_ATTRIBUTE_VALUE;
/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Thermostat cluster
******************************************************************************/
void ciIasZoneClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_COMBINED_INTERFACE, IAS_ZONE_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);
  for(uint8_t zoneEntry= DEFAULT_VAL; zoneEntry < ZONE_TABLE_ENTRIES; zoneEntry++)
  {
    zoneTables[zoneEntry].zoneId = 0xFF;
    zoneTables[zoneEntry].zoneType = 0xFFFF;
    zoneTables[zoneEntry].zoneStatus = 0x0000;
    zoneTables[zoneEntry].zoneAddress = DEFAULT_EXT_ADDR;
  }
  cluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
  ciZoneClusterClientAttributes.clusterVersion.value = ZONE_CLUSTER_VERSION;
}
/**************************************************************************//**
  \brief ZoneStatusChangeNotificationCommandInd
  \param[in] addressing - pointer to addressing information
  \param[in] payloadLength - payloadlength
  \param[in] payload - ChangeNotification payload
  \return status of indication routine
******************************************************************************/
static ZCL_Status_t zoneStatusChangeNotificationCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ZoneStatusChangeNot_t *payload)
{
  APP_Zigbee_Event_t event;
  if(payload->zoneId >= ZONE_TABLE_ENTRIES)
  {
    return ZCL_INVALID_ATTRIBUTE_VALUE_STATUS;
  }
  //Expected to Send the Changed Command to the Device , but what happens for the Periodic report and CIE do not maintain attributes to check for the change.
  //For now the locally maintained zonestatus within the zonetable is used for the same
  if(zoneTables[payload->zoneId].zoneStatus != payload->zoneStatus)
  {
    zoneTables[payload->zoneId].zoneStatus = payload->zoneStatus;
    aceZoneStatusChangedCommand(addressing->addrMode, addressing->addr.shortAddress, addressing->endpointId, APP_ENDPOINT_COMBINED_INTERFACE, payload->zoneId, payload->zoneStatus, DEFAULT_SOUND, ZONE_LABEL);
  }

  event.eventGroup = EVENT_CLUSTER;
  event.eventId = CMD_ZCL_ZONE_STATUS_CHANGE_NOTIFY;
  event.eventData.zclEventData.addressing = addressing;
  event.eventData.zclEventData.payloadLength = payloadLength;
  event.eventData.zclEventData.payload = (uint8_t*)payload;
  APP_Zigbee_Handler(event);
  return ZCL_SUCCESS_STATUS;
}
/**************************************************************************//**
  \brief ZoneTableEntry
  \param[in] response - Zone enroll resp;
  \param[in] payload - Zone enroll req;
  \param[in] addressing   - address details;
  \return none
******************************************************************************/
static void zoneTableEntry(ZCL_ZoneEnrollResCommand_t *response, ZCL_ZoneEnrollRequest_t *payload, ZCL_Addressing_t *addressing)
{
  uint64_t zoneServerAddr = DEFAULT_EXT_ADDR;
  uint8_t freeIndex = 0xFF;
  uint8_t zoneEntryIndex = 0;
  response->enrollResponseCode = ENROLL_RESP_TOO_MANY_ZONES;
  const ExtAddr_t *extAddr = NWK_GetExtByShortAddress(addressing->addr.shortAddress);

  if(*extAddr != 0)
    COPY_64BIT_VALUE_A(&zoneServerAddr,extAddr);

  for(zoneEntryIndex = 0; zoneEntryIndex < ZONE_TABLE_ENTRIES; zoneEntryIndex++)
  {
    if(zoneTables[zoneEntryIndex].zoneId == 0xFF)
    {
      if(freeIndex == 0xFF)
        freeIndex = zoneEntryIndex;
    }
    else if(zoneTables[zoneEntryIndex].zoneAddress == zoneServerAddr)
    {
      response->enrollResponseCode = ENROLL_RESP_SUCCESS;
      response->zoneId = zoneTables[zoneEntryIndex].zoneId;
      break;
    }
   }
   if (zoneEntryIndex == ZONE_TABLE_ENTRIES)
   {
     if(freeIndex != 0xFF)
     {
       zoneTables[freeIndex].zoneId = freeIndex;
       zoneTables[freeIndex].zoneType = payload->zoneType;
       zoneTables[freeIndex].zoneAddress = zoneServerAddr;
       response->zoneId = freeIndex;
       response->enrollResponseCode = ENROLL_RESP_SUCCESS;
     }
     else
     {
       response->zoneId = 0xFF;
       response->enrollResponseCode = ENROLL_RESP_TOO_MANY_ZONES;
     }
   }
}
/**************************************************************************//**
  \brief ZoneEnrollRequestCommandInd
  \param[in] addressing - pointer to addressing information;
  \param[in] payload - Zone enroll req payload;
  \param[in] request - Zone enroll request;
  \return status of indication routine
******************************************************************************/
ZCL_Status_t zoneEnrollRequestCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ZoneEnrollRequest_t *payload)
{
  ZCL_Request_t *req;
  APP_Zigbee_Event_t event;

  if (!(req = getFreeCommand()))
    return ZCL_INSUFFICIENT_SPACE_STATUS;
  
  fillCommandRequest(req, ZCL_IAS_ZONE_CLUSTER_ZONE_ENROLL_RESPONSE_COMMAND_ID, sizeof(ZCL_ZoneEnrollResCommand_t), APP_ENDPOINT_COMBINED_INTERFACE);
  zoneTableEntry((ZCL_ZoneEnrollResCommand_t *)req->requestPayload, payload ,addressing);
  fillDstAddressingViaSourceAddressing(&req->dstAddressing, addressing, ZCL_CLUSTER_SIDE_SERVER);
  ZCL_CommandManagerSendCommand(req);

  event.eventGroup = EVENT_CLUSTER;
  event.eventId = CMD_ZCL_ZONE_ENROLL_REQ;
  event.eventData.zclEventData.addressing = addressing;
  event.eventData.zclEventData.payloadLength = payloadLength;
  event.eventData.zclEventData.payload = (uint8_t*)payload;
  APP_Zigbee_Handler(event);
  return ZCL_SUCCESS_STATUS;
}
/**************************************************************************//**
  \brief ZoneInitiateNormalOperatingModeCommand
  \param[in] mode   - address mode;
  \param[in] addr   - short address of destination node;
  \param[in] ep     - destination endpoint;
  \param[in] srcEp- source endpoint;
  \return none
******************************************************************************/
void zoneInitiateNormalOperatingModeCommand(APS_AddrMode_t mode,ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;
  
  fillCommandRequest(req, ZCL_IAS_ZONE_CLUSTER_ZONE_NORMAL_OPERATIONG_MODE, 0, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, IAS_ZONE_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
  \brief ZoneInitiateTestModeCommand
  \param[in] mode   - address mode;
  \param[in] addr   - short address of destination node;
  \param[in] ep     - destination endpoint;
  \param[in] srcEp- source endpoint;
  \param[in] testmode_duration     - test mode duration;
  \param[in] testmode_duration     - test mode duration;
  \return none
******************************************************************************/
void zoneInitiateTestModeCommand(APS_AddrMode_t mode,ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t testmodeDuration, uint8_t currentZoneSensitivityLevel)
{
  ZCL_Request_t *req;
  ZCL_ZoneInitiateTestMode_t reqpayload;
  //ZCL_ZoneEnrollResCommand_t response;

  if (!(req = getFreeCommand()))
    return;

  //Test Mode dutaion - typically it should be greater than zero
  if(testmodeDuration > 0)
  {
    reqpayload.testmodeDuration = testmodeDuration;
  }
  else
  {
    reqpayload.testmodeDuration = TEST_MODE_DURATION;
  }
  //CurrentZoneSensitivit level to be modified in Zone Server
  reqpayload.currentZoneSensitivityLevel = currentZoneSensitivityLevel;
  
  fillCommandRequest(req, ZCL_IAS_ZONE_CLUSTER_ZONE_TEST_MODE, sizeof(ZCL_ZoneInitiateTestMode_t), srcEp);
  memcpy((ZCL_ZoneInitiateTestMode_t *)req->requestPayload, &reqpayload , sizeof(ZCL_ZoneInitiateTestMode_t));
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, IAS_ZONE_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/***************************************************************************//**
 \brief Callback to initiate AutoEnrollResponse
 \param[in] addressing - pointer to addressing information;
 \return none
*******************************************************************************/
void writeAttrCallback(ZCL_Notify_t *ntfy)
{
  appSnprintf("callback to initiate Zone Enroll Response\r\n");
  //zoneEnrollRequestCommandInd(ntfy->addressing, sizeof(uint16_t), (ZCL_ZoneEnrollRequest_t*)&zone_type);

  if (ZCL_SUCCESS_STATUS == ntfy->status)
  {
     zoneAutoEnrollResponse(ntfy);
  }
  else
  {
    appSnprintf("ZclConfirm: status = 0x%02x\r\n", ntfy->status);
  }

}

/***************************************************************************//**
 \brief Initiate AutoEnroll Response
 \param[in] addressing - pointer to addressing information;
 \return none
*******************************************************************************/
ZCL_Status_t zoneAutoEnrollResponse(ZCL_Notify_t *ntfy)
{
  ZCL_Request_t *req;
  ZCL_ZoneEnrollRequest_t payload;
  payload.zoneType = zone_type;
  payload.manufacturerCode = CS_MANUFACTURER_CODE;

  if (!(req = getFreeCommand()))
    return ZCL_INSUFFICIENT_SPACE_STATUS;
  
  req->requestPayload = ntfy->responsePayload;
  fillCommandRequest(req, ZCL_IAS_ZONE_CLUSTER_ZONE_ENROLL_RESPONSE_COMMAND_ID, sizeof(ZCL_ZoneEnrollResCommand_t), APP_ENDPOINT_COMBINED_INTERFACE);
  zoneTableEntry((ZCL_ZoneEnrollResCommand_t *)req->requestPayload, &payload, ntfy->addressing);
  fillDstAddressingViaSourceAddressing(&req->dstAddressing, ntfy->addressing, ZCL_CLUSTER_SIDE_SERVER);
  ZCL_CommandManagerSendCommand(req);

  return ZCL_SUCCESS_STATUS;
}

/***************************************************************************//**
 \brief Initiate Enrolment procedure command
 \param[in] addressing - pointer to addressing information;
 \return none
*******************************************************************************/
void aceZoneEnrollmentProcInitiateCmd(APS_AddrMode_t mode, ShortAddr_t zoneServerAddr, uint8_t srcEp, void *data, uint8_t enrolmentType)
{
  switch(enrolmentType)
  {
  case AUTO_ENROLL_REQUEST_ENABLE:
       writeAttribute(mode, zoneServerAddr, APP_ENDPOINT_IAS_ACE, srcEp,
       IAS_ZONE_CLUSTER_ID, ZCL_U64BIT_DATA_TYPE_ID, ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_IAS_CIE_ADDRESS_ATTRIBUTE_ID, data, IEEE_ADDRESS_LENGTH, NULL);
       break;
  case AUTO_ENROLL_REQUEST_DISABLE:
      writeAttribute(mode, zoneServerAddr, APP_ENDPOINT_IAS_ACE, srcEp,
       IAS_ZONE_CLUSTER_ID, ZCL_U64BIT_DATA_TYPE_ID, ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_IAS_CIE_ADDRESS_ATTRIBUTE_ID, data, IEEE_ADDRESS_LENGTH, writeAttrCallback);
       break;
  }
}
#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE
// eof ciIasZoneCluster.c
