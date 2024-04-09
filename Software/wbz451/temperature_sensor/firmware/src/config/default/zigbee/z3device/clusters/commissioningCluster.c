/*******************************************************************************
  Commissioning Cluster source File

  Company:
    Microchip Technology Inc.

  File Name:
    ommissioningCluster.h

  Summary:
    This file contains Commissioning Cluster Implemenation.

  Description:
    This file contains Commissioning Cluster Implemenation.
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

#if (APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_COMBINED_INTERFACE) || (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER)
/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/common/include/appConsts.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/clusters/include/commissioningCluster.h>

/******************************************************************************
                    Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Fill the endpoint information command payload

\param[in] payload - pointer to command payload
******************************************************************************/
static void fillEndpointInformationPayload(ZCL_EndpointInformation_t *payload)
{
  ExtAddr_t ieeeAddr;

  memcpy(&ieeeAddr, MAC_GetExtAddr(), sizeof(ExtAddr_t));

  payload->ieeeAddress    = ieeeAddr;
  payload->networkAddress = NWK_GetShortAddr();
  payload->endpointId     = APP_SRC_ENDPOINT_ID;
  payload->profileId      = APP_PROFILE_ID;
  payload->deviceId       = APP_Z3DEVICE_ID;
  payload->version        = APP_VERSION;
}

/**************************************************************************//**
\brief Send Endpoint Information command to target device.

\param[in] mode - addressing mode
\param[in] addr - dst address
\param[in] ep   - dst endpoint
******************************************************************************/
void commissioningSendEndpointInformation(ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
  {
    return;
  }

  // fill command request
  fillCommandRequest(req, ZCL_COMMISSIONING_CLUSTER_ENDPOINT_INFORMATION_COMMAND_ID,
                     sizeof(ZCL_EndpointInformation_t), srcEp);

  // fill command payload
  fillEndpointInformationPayload((ZCL_EndpointInformation_t *)req->requestPayload);

  // fill destination addressing
  fillDstAddressingServer(&req->dstAddressing, APS_SHORT_ADDRESS, addr, ep, ZLL_COMMISSIONING_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Fill the get group identifiers response command payload

\param[in] payload - pointer to response payload
\param[in] startIndex - start index

\return Size of the command payload
******************************************************************************/
uint8_t fillGetGroupIdentifiersResponsePayload(ZCL_GetGroupIdentifiersResponse_t *payload, uint8_t startIndex)
{
  uint8_t size = sizeof(uint8_t) /*total*/ + sizeof(uint8_t) /*startIndex*/ + sizeof(uint8_t) /*count*/;
  uint8_t index = 0, n = 0;

  NWK_GroupTableEntry_t *group = NWK_NextGroup((NWK_GroupTableEntry_t *)NULL); // returns the first group entry

  while (NULL != group)
  {
    if (index >= startIndex && (n < ARRAY_SIZE(payload->recordList)))
    {
      payload->recordList[n].groupId = group->addr;
      payload->recordList[n].groupType = 0;
      n++;

      size += sizeof(ZCL_GroupInformationRecord_t);
    }

    group = NWK_NextGroup(group);
    index++;
  }

  payload->total = index;
  payload->startIndex = startIndex;
  payload->count = n;

  return size;
}

/**************************************************************************//**
\brief Fill the get endpoint list response command payload

\param[in] payload - pointer to response payload
\param[in] startIndex - start index

\return Size of the command payload
******************************************************************************/
uint8_t fillGetEndpointListResponsePayload(ZCL_GetEndpointListResponse_t *payload, uint8_t startIndex)
{
  uint8_t size = sizeof(uint8_t) /*total*/ + sizeof(uint8_t) /*startIndex*/ + sizeof(uint8_t) /*count*/;

  if (0 == startIndex)
  {
    payload->recordList[0].networkAddress = NWK_GetShortAddr();
    payload->recordList[0].endpointId = APP_SRC_ENDPOINT_ID;
    payload->recordList[0].profileId = APP_PROFILE_ID;
    payload->recordList[0].deviceId = APP_Z3DEVICE_ID;
    payload->recordList[0].version = APP_VERSION;

    size += sizeof(ZCL_EndpointInformationRecord_t);
    payload->count = 1;
  }
  else
  {
    payload->count = 0;
  }
  payload->total = 1;
  payload->startIndex = startIndex;

  return size;
}
/**************************************************************************//**
\brief Send Get Group Identifiers command to target device.

\param[in] addr       - dst address
\param[in] ep         - dst endpoint
\param[in] startIndex - start index of group ids
******************************************************************************/
void commissioningSendGetGroupIdentifiers(ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t startIndex)
{
  ZCL_Request_t *req;
  ZCL_GetGroupIdentifiers_t *getGroupIdentifiersCmd;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }

  // fill command request 
  fillCommandRequest(req, ZCL_COMMISSIONING_CLUSTER_GET_GROUP_IDENTIFIERS_COMMAND_ID,
                     sizeof(ZCL_GetGroupIdentifiers_t),srcEp);

  // fill command payload
  getGroupIdentifiersCmd = (ZCL_GetGroupIdentifiers_t *)req->requestPayload;
  getGroupIdentifiersCmd->startIndex = startIndex;

  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, APS_SHORT_ADDRESS, addr, ep, ZLL_COMMISSIONING_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Send Get Endpoint List command to target device.

\param[in] addr       - dst address
\param[in] ep         - dst endpoint
\param[in] startIndex - start index of endpoints
******************************************************************************/
void commissioningGetEndpointList(ShortAddr_t addr, Endpoint_t ep,Endpoint_t srcEp, uint8_t startIndex)
{
  ZCL_Request_t *req;
  ZCL_GetEndpointList_t *getEndpointListCmd;

  if (!(req = getFreeCommand()))
  {
    return;
  }

  // fill command request
  fillCommandRequest(req, ZCL_COMMISSIONING_CLUSTER_GET_ENDPOINT_LIST_COMMAND_ID,
                     sizeof(ZCL_GetEndpointList_t), srcEp);

  // fill command payload
  getEndpointListCmd = (ZCL_GetEndpointList_t *)req->requestPayload;
  getEndpointListCmd->startIndex = startIndex;

  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, APS_SHORT_ADDRESS, addr, ep, ZLL_COMMISSIONING_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
#endif //  APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_COMBINED_INTERFACE || APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER
