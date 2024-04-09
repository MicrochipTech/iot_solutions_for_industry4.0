/*******************************************************************************
  Zigbee Cluster Library Group Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclGroupsCluster.h

  Summary:
    The header file describes the ZCL Groups Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Groups Cluster.
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


#ifndef _ZCLGROUPSCLUSTER_H
#define _ZCLGROUPSCLUSTER_H

/*!
Attributes and commands for determining basic information about a device,
setting user device information such as location, enabling a device and resetting it
to factory defaults.
*/

/*******************************************************************************
                   Includes section
*******************************************************************************/

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/

/**
 * \brief Groups Cluster group name support bit
*/

#define GROUP_NAME_SUPPORT_FLAG  0x80

/**
 * \brief Groups Cluster server attributes amount
*/

#define ZCL_GROUPS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 2

/**
 * \brief Groups Cluster client attributes amount. Clinet doesn't have attributes.
*/

#define ZCL_GROUPS_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT 1

/**
 * \brief Groups Cluster commands amount
*/

#define ZCL_GROUPS_CLUSTER_SERVER_COMMANDS_AMOUNT (10)
#define ZCL_GROUPS_CLUSTER_CLIENT_COMMANDS_AMOUNT (10)

/**
 * \brief Groups ClusterVersion attribute
*/
#define ZCL_GROUPS_CLUSTER_VERSION_ATTRIBUTE_ID              CCPU_TO_LE16(0xfffd)

/**
 * \brief Groups Cluster server's attributes identifiers
*/

#define ZCL_GROUPS_CLUSTER_NAME_SUPPORT_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0000)

/**
 * \brief Groups Cluster client's command identifiers
*/

#define ZCL_GROUPS_CLUSTER_ADD_GROUP_COMMAND_ID 0x00
#define ZCL_GROUPS_CLUSTER_VIEW_GROUP_COMMAND_ID 0x01
#define ZCL_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP_COMMAND_ID 0x02
#define ZCL_GROUPS_CLUSTER_REMOVE_GROUP_COMMAND_ID 0x03
#define ZCL_GROUPS_CLUSTER_REMOVE_ALL_GROUPS_COMMAND_ID 0x04
#define ZCL_GROUPS_CLUSTER_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID 0x05

/**
 * \brief Groups Cluster servers's command identifiers
*/

#define ZCL_GROUPS_CLUSTER_ADD_GROUP_RESPONSE_COMMAND_ID 0x00
#define ZCL_GROUPS_CLUSTER_VIEW_GROUP_RESPONSE_COMMAND_ID 0x01
#define ZCL_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP_RESPONSE_COMMAND_ID 0x02
#define ZCL_GROUPS_CLUSTER_REMOVE_GROUP_RESPONSE_COMMAND_ID 0x03

/**
 * \brief Groups Cluster server define attributes macros
*/

#define ZCL_DEFINE_GROUPS_CLUSTER_SERVER_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(nameSupport, ZCL_READONLY_ATTRIBUTE, ZCL_GROUPS_CLUSTER_NAME_SUPPORT_SERVER_ATTRIBUTE_ID, ZCL_8BIT_BITMAP_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_GROUPS_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)


/**
* \brief Groups Cluster server define attributes macros
*/
#define ZCL_DEFINE_GROUPS_CLUSTER_CLIENT_ATTRIBUTES() \
   DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_GROUPS_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/**
 * \brief On/Off Cluster define commands macros
*/

#define ZCL_DEFINE_GROUPS_CLUSTER_COMMANDS(addGroupCommandInd, viewGroupCommandInd, getGroupMembershipCommandInd, \
        removeGroupCommandInd, removeAllGroupsCommandInd, addGroupIfIdentifyingCommandInd, \
        addGroupResponseCommandInd, viewGroupResponseCommandInd, getGroupMembershipResponseCommandInd, \
        removeGroupResponseCommandInd) \
    DEFINE_COMMAND(addGroupCommand, ZCL_GROUPS_CLUSTER_ADD_GROUP_COMMAND_ID,                                       \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                         \
                     addGroupCommandInd),                                                                          \
    DEFINE_COMMAND(viewGroupCommand, ZCL_GROUPS_CLUSTER_VIEW_GROUP_COMMAND_ID,                                     \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                         \
                     viewGroupCommandInd),                                                                         \
    DEFINE_COMMAND(getGroupMembershipCommand, ZCL_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP_COMMAND_ID,                  \
                      COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                        \
                     getGroupMembershipCommandInd),                                                                \
    DEFINE_COMMAND(removeGroupCommand, ZCL_GROUPS_CLUSTER_REMOVE_GROUP_COMMAND_ID,                                 \
                      COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                        \
                     removeGroupCommandInd),                                                                       \
    DEFINE_COMMAND(removeAllGroupsCommand, ZCL_GROUPS_CLUSTER_REMOVE_ALL_GROUPS_COMMAND_ID,                        \
                      COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                     \
                     removeAllGroupsCommandInd),                                                                   \
    DEFINE_COMMAND(addGroupIfIdentifyingCommand, ZCL_GROUPS_CLUSTER_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID,           \
                      COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                     \
                     addGroupIfIdentifyingCommandInd),                                                             \
    DEFINE_COMMAND(addGroupResponseCommand, ZCL_GROUPS_CLUSTER_ADD_GROUP_RESPONSE_COMMAND_ID,                      \
                      COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                     \
                     addGroupResponseCommandInd),                                                                  \
    DEFINE_COMMAND(viewGroupResponseCommand, ZCL_GROUPS_CLUSTER_VIEW_GROUP_RESPONSE_COMMAND_ID,                    \
                      COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                     \
                     viewGroupResponseCommandInd),                                                                 \
    DEFINE_COMMAND(getGroupMembershipResponseCommand, ZCL_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP_RESPONSE_COMMAND_ID, \
                      COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                     \
                     getGroupMembershipResponseCommandInd),                                                        \
    DEFINE_COMMAND(removeGroupResponseCommand, ZCL_GROUPS_CLUSTER_REMOVE_GROUP_RESPONSE_COMMAND_ID,                \
                      COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),                     \
                     removeGroupResponseCommandInd)

/**
 * \brief On/Off Cluster definition macros
*/

#define GROUPS_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = GROUPS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GROUPS_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GROUPS_CLUSTER_CLIENT_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define GROUPS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = GROUPS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GROUPS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GROUPS_CLUSTER_SERVER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_GROUPS_CLUSTER(cltype, clattributes, clcommands) \
    GROUPS_CLUSTER_##cltype(clattributes, clcommands)

#define GROUPS_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = GROUPS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GROUPS_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GROUPS_CLUSTER_CLIENT_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define GROUPS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = GROUPS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GROUPS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GROUPS_CLUSTER_SERVER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DEFINE_GROUPS_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    GROUPS_CLUSTER_##cltype##_FLASH(clattributes, clcommands)

/******************************************************************************
                    Types section
 ******************************************************************************/
BEGIN_PACK

/**
 * \brief Add Group Command Payload format.
 */

typedef struct PACK
{
  uint16_t groupId;
  uint8_t groupName[2];
} ZCL_AddGroup_t;

/**
 * \brief View Group Command Payload format.
 */

typedef struct PACK
{
  uint16_t groupId;
} ZCL_ViewGroup_t;

/**
 * \brief Get Group Membership Command Payload format.
 */

typedef struct PACK
{
  uint8_t groupCount;
  uint16_t groupList[1];
} ZCL_GetGroupMembership_t;

/**
 * \brief Remove Group Command Payload format.
 */

typedef struct PACK
{
  uint16_t groupId;
} ZCL_RemoveGroup_t;

/**
 * \brief Add Group if identifying Command Payload format.
 */

typedef struct PACK
{
  uint16_t groupId;
  uint8_t groupName[2];
} ZCL_AddGroupIfIdentifying_t;

/**
 * \brief Add Group Response Command Payload format.
 */

typedef struct PACK
{
  uint8_t status;
  uint16_t groupId;
} ZCL_AddGroupResponse_t;

/**
 * \brief View Group Response Command Payload format.
 */

typedef struct PACK
{
  uint8_t status;
  uint16_t groupId;
  uint8_t groupName[2];
} ZCL_ViewGroupResponse_t;

/**
 * \brief Get Group Membership Response Payload format.
 */

typedef struct PACK
{
  uint8_t capacity;
  uint8_t groupCount;
  uint16_t groupList[1];
} ZCL_GetGroupMembershipResponse_t;

/**
 * \brief Remove Group Command Response Payload format.
 */

typedef struct PACK
{
  uint8_t status;
  uint16_t groupId;
} ZCL_RemoveGroupResponse_t;

/**
 * \brief Groups Cluster server's attributes
 */

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value;
  } nameSupport;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_GroupsClusterServerAttributes_t;

/**
 * \brief Groups Cluster client's attributes
 */

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_GroupsClusterClientAttributes_t;

END_PACK

/**
 * \brief Groups Cluster commands.
 */

typedef struct
{
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*addGroupCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_AddGroup_t * payload);
  } addGroupCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*viewGroupCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ViewGroup_t * payload);
  } viewGroupCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*getGroupMembershipCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupMembership_t * payload);
  } getGroupMembershipCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*removeGroupCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_RemoveGroup_t * payload);
  } removeGroupCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*removeAllGroupsCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, void * payload);
  } removeAllGroupsCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*addGroupIfIdentifyingCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_AddGroupIfIdentifying_t * payload);
  } addGroupIfIdentifyingCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*addGroupResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_AddGroupResponse_t * payload);
  } addGroupResponseCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*viewGroupResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ViewGroupResponse_t * payload);
  } viewGroupResponseCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*getGroupMembershipResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupMembershipResponse_t * payload);
  } getGroupMembershipResponseCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*removeGroupResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_RemoveGroupResponse_t * payload);
  } removeGroupResponseCommand;
} ZCL_GroupsClusterCommands_t;

#endif /* _ZCLGROUPSCLUSTER_H */
