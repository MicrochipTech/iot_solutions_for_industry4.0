/*******************************************************************************
  Custom Commissioning cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    customCommissioningCluster.c

  Summary:
    This file contains the Custom Commissioning Cluster implementation.

  Description:
    This file contains the Custom Commissioning Cluster implementation.
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
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE)

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/common/include/appConsts.h>
#include <z3device/clusters/include/haClusters.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/clusters/include/commissioningCluster.h>
#include <z3device/custom/include/customCommissioningCluster.h>

/******************************************************************************
                    Prototypes
******************************************************************************/
static ZCL_Status_t getGroupIdentifiersInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiers_t *payload);
static ZCL_Status_t getEndpointListInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointList_t *payload);
static ZCL_Status_t getGroupIdentifiersInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiers_t *payload);
static ZCL_Status_t getEndpointListInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointList_t *payload);
static ZCL_Status_t endpointInformationResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_EndpointInformation_t *payload);
static ZCL_Status_t getGroupIdentifiersResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiersResponse_t *payload);
static ZCL_Status_t getEndpointListResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointListResponse_t *payload);
/******************************************************************************
                    Global variables
******************************************************************************/
ZCL_CommissioningClusterServerAttributes_t customCommissioningClusterServerAttributes =
{
  ZCL_DEFINE_COMMISSIONING_CLUSTER_SERVER_ATTRIBUTES()
};

ZCL_CommissioningClusterClientAttributes_t customCommissioningClusterClientAttributes =
{
  ZCL_DEFINE_COMMISSIONING_CLUSTER_CLIENT_ATTRIBUTES()
};


ZCL_CommissioningClusterCommands_t customCommissioningClusterCommands =
{
  ZCL_DEFINE_COMMISSIONING_CLUSTER_COMMANDS(getGroupIdentifiersInd, getEndpointListInd,
      endpointInformationResponseInd, getGroupIdentifiersResponseInd, getEndpointListResponseInd)
};

/******************************************************************************
                    Implementations section
******************************************************************************/

/**************************************************************************//**
\brief Initialize Commissioning cluster.
******************************************************************************/
void customCommissioningClusterInit(void)
{
  ZCL_Cluster_t *commissioningCluster = ZCL_GetCluster(APP_ENDPOINT_CUSTOM,
                                                       ZLL_COMMISSIONING_CLUSTER_ID,
                                                       ZCL_CLUSTER_SIDE_SERVER);

  customCommissioningClusterServerAttributes.clusterVersion.value = CLUSTER_VERSION;
  
  commissioningCluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

/**************************************************************************//**
\brief Callback on receive of Get Group Identifiers command
******************************************************************************/
static ZCL_Status_t getGroupIdentifiersInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiers_t *payload)
{
  ZCL_Request_t *req;
  uint8_t size;

  appSnprintf("getGroupIdentifiersInd(), startIndex=%02d\r\n", payload->startIndex);
  
  if (!(req = getFreeCommand()))
  {
   return ZCL_INSUFFICIENT_SPACE_STATUS;
  }
  
  size = fillGetGroupIdentifiersResponsePayload((ZCL_GetGroupIdentifiersResponse_t *)req->requestPayload,  payload->startIndex);
  fillCommandRequest(req, ZCL_COMMISSIONING_CLUSTER_GET_GROUP_IDENTIFIERS_RESPONSE_COMMAND_ID, size, APP_SRC_ENDPOINT_ID);
  fillDstAddressingViaSourceAddressing(&req->dstAddressing, addressing, ZCL_CLUSTER_SIDE_CLIENT);
  ZCL_CommandManagerSendCommand(req);

  (void) payloadLength;
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Callback on receive of Get Endpoint List command
******************************************************************************/
static ZCL_Status_t getEndpointListInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointList_t *payload)
{
  ZCL_Request_t *req;
  uint8_t size;

  appSnprintf("getEndpointListInd(), startIndex=%02d\r\n", payload->startIndex);
  
  if (!(req = getFreeCommand()))
  {
   return ZCL_INSUFFICIENT_SPACE_STATUS;
  }
  
  size = fillGetEndpointListResponsePayload((ZCL_GetEndpointListResponse_t *)req->requestPayload,  payload->startIndex);
  fillCommandRequest(req, ZCL_COMMISSIONING_CLUSTER_GET_ENDPOINT_LIST_RESPONSE_COMMAND_ID, size, APP_SRC_ENDPOINT_ID);
  fillDstAddressingViaSourceAddressing(&req->dstAddressing, addressing, ZCL_CLUSTER_SIDE_CLIENT);
  ZCL_CommandManagerSendCommand(req);

  (void)payloadLength;
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Callback on receive of Endpoint Information command
******************************************************************************/
static ZCL_Status_t endpointInformationResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_EndpointInformation_t *payload)
{
  uint64_t tmpAddr;
  uint8_t *tmp;

  COPY_EXT_ADDR(tmpAddr, payload->ieeeAddress);
  tmp = (uint8_t *)&tmpAddr;

  appSnprintf("endpointInformationInd()\r\n");

  appSnprintf("ieeeAddress=");



  for (uint8_t i = 0; i < 8; i++)
  {
    appSnprintf("%02x", tmp[8-(i+1)]);
  }

  appSnprintf(", networkAddress=0x%04x, endpointId=0x%02x, profileId=0x%04x, deviceId=0x%04x, version=0x%02x\r\n", payload->networkAddress, payload->endpointId, payload->profileId, payload->deviceId, payload->version);

  (void)addressing;
  (void)payloadLength;
  (void)payload;
  (void)tmp;
  
  /*
   * The endpoint information command shall be sent using unicast transmission.
   * On receipt of this command, the device shall respond using a
   * ZCL default response command.
   * -- 13.3.2.2.6 Endpoint Information Command, ZCL specification
   */
  return ZCL_SUCCESS_WITH_DEFAULT_RESPONSE_STATUS;
}

/**************************************************************************//**
\brief Callback on receive of Get Group Identifiers Response command
******************************************************************************/
static ZCL_Status_t getGroupIdentifiersResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiersResponse_t *payload)
{
  uint8_t i;
  ZCL_GroupInformationRecord_t record;

  appSnprintf("getGroupIdentifiersResponseInd()\r\n");

  appSnprintf("total=%d, startIndex=%d, count=%d\r\n", payload->total, payload->startIndex, payload->count);


  for (i = 0; i < payload->count; i++)
  {
    record = payload->recordList[i];
    appSnprintf("group id=0x%04x, type=0x%02x\r\n", record.groupId, record.groupType);
  }

  (void)addressing;
  (void)payloadLength;
  (void)payload;
  (void)record;
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Callback on receive of Get Endpoint List Response command
******************************************************************************/
static ZCL_Status_t getEndpointListResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointListResponse_t *payload)
{
  uint8_t i;
  ZCL_EndpointInformationRecord_t record;


  appSnprintf("getEndpointListResponseInd()\r\n");

  appSnprintf("total=%d, startIndex=%d, count=%d\r\n", payload->total, payload->startIndex, payload->count);


  for (i = 0; i < payload->count; i++)
  {
    record = payload->recordList[i];
    appSnprintf("endpoint networkAddress=0x%04x, endpointId=0x%02x, profileId=0x%04x, deviceId=0x%04x, version=0x%02x\r\n", record.networkAddress, record.endpointId, record.profileId, record.deviceId, record.version);
  }

  (void)addressing;
  (void)payloadLength;
  (void)payload;
  (void)record;
  return ZCL_SUCCESS_STATUS;
}

#endif // #if APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE

// eof customCommissioningCluster.c
