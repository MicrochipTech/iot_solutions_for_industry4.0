/*******************************************************************************
  Groups Cluster Source file

  Company:
    Microchip Technology Inc.

  File Name:
    GroupsCluster.c

  Summary:
    This file contains Groups Cluster Implementation.

  Description:
    This file contains Groups Cluster Implementation.
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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <zcl/include/zclCommandManager.h>
#include <zcl/clusters/include/groupsCluster.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
static void fillAddGroupIfIdentifyingPayload(ZCL_AddGroup_t *payload, uint16_t group);
static void fillViewRemoveGroupPayload(ZCL_ViewGroup_t *payload, uint16_t group);
static uint8_t fillGetGroupMembershipPayload(ZCL_GetGroupMembership_t *payload, uint8_t count, uint16_t *list);

/******************************************************************************
                    Global variables section
******************************************************************************/
DECLARE_QUEUE(groupsSubscribers);

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
/brief Sends Add Group command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendAddGroup(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_GROUPS_CLUSTER_ADD_GROUP_COMMAND_ID, sizeof(ZCL_AddGroup_t), srcEp);
  fillAddGroupIfIdentifyingPayload((ZCL_AddGroup_t *)req->requestPayload, group);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, GROUPS_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends View Group command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendViewGroup(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_GROUPS_CLUSTER_VIEW_GROUP_COMMAND_ID, sizeof(ZCL_ViewGroup_t), srcEp);
  fillViewRemoveGroupPayload((ZCL_ViewGroup_t *)req->requestPayload, group);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, GROUPS_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Get Group Membership command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] count - group count;
\param[in] list  - group list;
******************************************************************************/
void groupsSendGetGroupMembership(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t count, uint16_t *list)
{
  ZCL_Request_t *req;
  uint8_t size;

  if (!(req = getFreeCommand()))
    return;

  size = fillGetGroupMembershipPayload((ZCL_GetGroupMembership_t *)req->requestPayload, count, list);
  fillCommandRequest(req, ZCL_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP_COMMAND_ID, size,  srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, GROUPS_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Remove Group command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendRemoveGroup(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_GROUPS_CLUSTER_REMOVE_GROUP_COMMAND_ID, sizeof(ZCL_RemoveGroup_t), srcEp);
  fillViewRemoveGroupPayload((ZCL_ViewGroup_t *)req->requestPayload, group);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, GROUPS_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Remove All Groups command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendRemoveAllGroups(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_GROUPS_CLUSTER_REMOVE_ALL_GROUPS_COMMAND_ID, 0, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, GROUPS_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Add Group If Identifying command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendAddGroupIfIdentifying(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_GROUPS_CLUSTER_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID, sizeof(ZCL_AddGroup_t), srcEp);
  fillAddGroupIfIdentifyingPayload((ZCL_AddGroup_t *)req->requestPayload, group);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, GROUPS_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Adds record to a list of subscribers

\param[in] subscriber - pointer to subscriber;
******************************************************************************/
void groupsSubscribe(GroupsSubscriber_t *subscriber)
{
  if (!isQueueElem(&groupsSubscribers, subscriber))
    if(!putQueueElem(&groupsSubscribers, subscriber))
    {
      /* failed to queue */
    }
}

/**************************************************************************//**
\brief Fills Add Group and Add Group If Identifying command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id
******************************************************************************/
static void fillAddGroupIfIdentifyingPayload(ZCL_AddGroup_t *payload, uint16_t group)
{
  payload->groupId      = group;
  payload->groupName[0] = 0;
}

/**************************************************************************//**
\brief Fills View Group and Remove Group command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id
******************************************************************************/
static void fillViewRemoveGroupPayload(ZCL_ViewGroup_t *payload, uint16_t group)
{
  payload->groupId = group;
}

/**************************************************************************//**
\brief Fills Get Group Membership command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id
******************************************************************************/
uint8_t fillGetGroupMembershipPayload(ZCL_GetGroupMembership_t *payload, uint8_t count, uint16_t *list)
{
  payload->groupCount = count;

  if (!count)
    return sizeof(ZCL_GetGroupMembership_t) - sizeof(uint16_t); /*groupList[1]*/

  for (uint8_t i = 0; i < count; i++)
    payload->groupList[i] = list[i];

  return sizeof(ZCL_GetGroupMembership_t) - sizeof(uint16_t) /*groupList[1]*/ + count * sizeof(uint16_t);
}

/*Server commands */

/**************************************************************************//**
\brief Fills Add Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  status  - status of group adding
******************************************************************************/
void fillAddGroupResponsePayload(ZCL_AddGroupResponse_t *payload, uint16_t group, uint8_t status)
{
  payload->status  = status;
  payload->groupId = group;
}

/**************************************************************************//**
\brief Fills Get Group Membership Response command structure

\param[out] payload - pointer to command structure;
\param[in]  req     - pointer to appropriate request
\param[in] srcEp    - source endpoint
\returns the amount of group ids in reponse
******************************************************************************/
uint8_t fillGetGroupMembershipRespPayload(ZCL_GetGroupMembershipResponse_t *payload, ZCL_GetGroupMembership_t *req, Endpoint_t srcEp)
{
  payload->capacity   = NWK_GroupCapacity();
  payload->groupCount = 0;

  if (req->groupCount)
    for (uint8_t i = 0; i < req->groupCount; i++)
    {
      if (NWK_IsGroupMember(req->groupList[i], srcEp))
        payload->groupList[payload->groupCount++] = req->groupList[i];
    }
  else
  {
    NWK_GroupTableEntry_t *group = NULL;

    while ((group = NWK_NextGroup(group)))
      payload->groupList[payload->groupCount++] = group->addr;
  }

  return sizeof(ZCL_GetGroupMembershipResponse_t) - ((CS_GROUP_TABLE_SIZE - payload->groupCount) * sizeof(uint16_t));

}

/**************************************************************************//**
\brief Fills Remove Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id
\param[in]  status  - status of group adding
******************************************************************************/
void fillRemoveGroupResponsePayload(ZCL_RemoveGroupResponse_t *payload, uint16_t group, uint8_t status)
{
  payload->status  = status;
  payload->groupId = group;
}

/**************************************************************************//**
\brief Fills View Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id
\param[in] srcEp    - source endpoint;
******************************************************************************/
void fillViewGroupResponsePayload(ZCL_ViewGroupResponse_t *payload, uint16_t group, Endpoint_t srcEp)
{
  if ((group == 0x0000) || (group >= 0xfff8))
    payload->status = ZCL_INVALID_VALUE_STATUS;
  else if (NWK_IsGroupMember(group, srcEp))
    payload->status = ZCL_SUCCESS_STATUS;
  else
    payload->status = ZCL_NOT_FOUND_STATUS;
  payload->groupId = group;
}

/**************************************************************************//**
\brief Adds group to group table

\param[in] group - group id
\param[in] srcEp - source endpoint

\returns status of group adding
******************************************************************************/
ZCL_Status_t addGroup(uint16_t group, uint8_t srcEp)
{
    if ((group == 0x0000) || (group >= 0xfff8))
      return ZCL_INVALID_VALUE_STATUS;
    if (NWK_IsGroupMember(group, srcEp))
      return ZCL_SUCCESS_STATUS;
    if (NWK_AddGroup(group, srcEp))
      return ZCL_SUCCESS_STATUS;
    else
      return ZCL_INSUFFICIENT_SPACE_STATUS;
}

/**************************************************************************//**
\brief Removes group from group table

\param[in] group - group id
\param[in] srcEp - source endpoint
\param[in] scenePool - Scene table
\returns status of group removing
******************************************************************************/
ZCL_Status_t removeGroup(uint16_t group, uint8_t srcEp, Scene_t* scenePool)
{
  if ((group == 0x0000) || (group >= 0xfff8))
    return ZCL_INVALID_VALUE_STATUS;
  if (NWK_RemoveGroup(group, srcEp))
  {
    removeScenesByGroup(group, scenePool);
    return ZCL_SUCCESS_STATUS;
  }
  else
    return ZCL_NOT_FOUND_STATUS;
}

/**************************************************************************//**
\brief Removes all groups from group table
\param[in] srcEp     - source endpoint
\param[in] scenePool - Scene table
******************************************************************************/
void removeAllGroups(uint8_t srcEp, Scene_t* scenePool)
{
  NWK_GroupTableEntry_t *group = NULL;

  while (NULL != (group = NWK_NextGroup(group)))
    removeScenesByGroup(group->addr, scenePool);

  NWK_RemoveAllGroups(srcEp);  
}


/**************************************************************************//**
\brief Checks whether given group id is a group id that exists on this device

\param[in] group - group id

\param[in] srcEp - source endpoint

\returns true if group id exists on this device, false otherwise
******************************************************************************/
bool groupsIsValidGroup(uint16_t group, Endpoint_t srcEp)
{
  return (group == 0 || NWK_IsGroupMember(group, srcEp));
}

// eof groupsCluster.c

