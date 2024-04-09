/*******************************************************************************
  Group Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    groupsCluster.h

  Summary:
    Groups cluster interface.

  Description:
    This file contains Groups cluster interface functions.
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


#ifndef _GROUPSCLUSTER_H
#define _GROUPSCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclZllGroupsCluster.h>
#include <zcl/clusters/include/scenes.h>

/******************************************************************************
                   Definition(s) section
******************************************************************************/
#define RAISE_CALLBACKS_TO_GROUPS_SUBSCIBERS(queue, callback) \
  for (GroupsSubscriber_t *subscriber = getQueueElem(&queue); subscriber; subscriber = getNextQueueElem(subscriber)) \
    if (subscriber->callback) \
      subscriber->callback(addressing, payload);

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  struct
  {
    void *next;
  } service;

  void (*addGroupResponse)(ZCL_Addressing_t *addressing, ZCL_AddGroupResponse_t *payload) ;
} GroupsSubscriber_t;

/******************************************************************************
                    Externals
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Adds record to a list of subscribers

\param[in] subscriber - pointer to subscriber;
******************************************************************************/
void groupsSubscribe(GroupsSubscriber_t *subscriber);

/**************************************************************************//**
\brief Initializes Groups cluster
******************************************************************************/
void groupsClusterInit(void);

/**************************************************************************//**
\brief Sends Add Group command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendAddGroup(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group);

/**************************************************************************//**
\brief Sends View Group command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendViewGroup(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,Endpoint_t srcEp,
  uint16_t group);

/**************************************************************************//**
\brief Sends Get Group Membership command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] count - group count;
\param[in] list  - group list;
******************************************************************************/
void groupsSendGetGroupMembership(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,Endpoint_t srcEp,
  uint8_t count, uint16_t *list);

/**************************************************************************//**
\brief Sends Remove Group command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendRemoveGroup(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group);

/**************************************************************************//**
\brief Sends Remove All Groups command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendRemoveAllGroups(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
\brief Sends Add Group If Identifying command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void groupsSendAddGroupIfIdentifying(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group);

/**************************************************************************//**
\brief Fills Add Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  status  - status of group adding
******************************************************************************/
void fillAddGroupResponsePayload(ZCL_AddGroupResponse_t *payload, uint16_t group, uint8_t status);

/**************************************************************************//**
\brief Fills Add Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  status  - status of group adding
******************************************************************************/
void fillAddGroupResponsePayload(ZCL_AddGroupResponse_t *payload, uint16_t group, uint8_t status);

/**************************************************************************//**
\brief Fills Get Group Membership Response command structure

\param[out] payload - pointer to command structure;
\param[in]  req     - pointer to appropriate request

\returns the amount of group ids in reponse
******************************************************************************/
uint8_t fillGetGroupMembershipRespPayload(ZCL_GetGroupMembershipResponse_t *payload, ZCL_GetGroupMembership_t *req, Endpoint_t srcEp);

/**************************************************************************//**
\brief Fills Remove Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  status  - status of group adding
******************************************************************************/
void fillRemoveGroupResponsePayload(ZCL_RemoveGroupResponse_t *payload, uint16_t group, uint8_t status);

/**************************************************************************//**
\brief Fills View Group Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id
******************************************************************************/
void fillViewGroupResponsePayload(ZCL_ViewGroupResponse_t *payload, uint16_t group, Endpoint_t srcEp);

/**************************************************************************//**
\brief Adds group to group table

\param[in] group - group id

\returns status of group adding
******************************************************************************/
ZCL_Status_t addGroup(uint16_t group, uint8_t srcEp);


/**************************************************************************//**
\brief Removes group from group table

\param[in] group - group id

\returns status of group removing
******************************************************************************/
ZCL_Status_t removeGroup(uint16_t group, uint8_t srcEp, Scene_t* scenePool);


/**************************************************************************//**
\brief Removes all groups from group table
******************************************************************************/
void removeAllGroups(uint8_t srcEp, Scene_t* scenePool);


/**************************************************************************//**
\brief Checks whether given group id is a group id that exists on this device

\param[in] group - group id

\param[in] srcEp - source endpoint

\returns true if group id exists on this device, false otherwise
******************************************************************************/
bool groupsIsValidGroup(uint16_t group, Endpoint_t srcEp);

#endif // _MSGROUPSCLUSTER_H

// eof msGroupsCluster.h

