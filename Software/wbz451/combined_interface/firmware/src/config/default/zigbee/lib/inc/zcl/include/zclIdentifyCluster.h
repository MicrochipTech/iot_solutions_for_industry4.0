/*******************************************************************************
  Zigbee Cluster Library Identify Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclIdentifyCluster.h

  Summary:
    The header file describes the ZCL Identify Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Identify Cluster.
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


#ifndef _ZCLIDENTIFYCLUSTER_H
#define _ZCLIDENTIFYCLUSTER_H

/*******************************************************************************
                   Includes section
*******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/
/**
 * \brief Identify Server Cluster attributes amount.
*/
#define ZCL_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES_AMOUNT   2u

/**
 * \brief Identify Client Cluster attributes amount.
*/
#define ZCL_IDENTIFY_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT   1u

/**
 * \brief Identify Client Cluster commands amount.
*/
#define ZCL_IDENTIFY_SERVER_CLUSTER_COMMANDS_AMOUNT     4u
#define ZCL_IDENTIFY_CLIENT_CLUSTER_COMMANDS_AMOUNT     4u

/**
 * \brief Identify Server Cluster attributes identifiers.
*/
#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_TIME_ATTRIBUTE_ID       CCPU_TO_LE16(0x0000)
#define ZCL_IDENTIFY_CLUSTER_COMMISSIONING_STATE_ATTRIBUTE_ID CCPU_TO_LE16(0x0001)

/**
 * \brief Identify Server Cluster commands identifiers.
*/
#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_RESPONSE_COMMAND_ID 0x00

/**
 * \brief Identify Client Cluster commands identifiers.
*/
#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_COMMAND_ID                   0x00
#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_COMMAND_ID             0x01
#define ZCL_IDENTIFY_CLUSTER_EZ_MODE_INVOKE_COMMAND_ID             0x02
#define ZCL_IDENTIFY_CLUSTER_UPDATE_COMMISSIONING_STATE_COMMAND_ID 0x03

/*
 *\brief ZCL Idetify Cluster server side attributes defining macros
 */
#ifdef HA_PROFILE_EXTENSIONS

  #define ZCL_DEFINE_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(identifyTime,       ZCL_READWRITE_ATTRIBUTE, ZCL_IDENTIFY_CLUSTER_IDENTIFY_TIME_ATTRIBUTE_ID,       ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(commissioningState, ZCL_READONLY_ATTRIBUTE,  ZCL_IDENTIFY_CLUSTER_COMMISSIONING_STATE_ATTRIBUTE_ID, ZCL_8BIT_BITMAP_DATA_TYPE_ID)

#else

  #define ZCL_DEFINE_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(identifyTime, ZCL_READWRITE_ATTRIBUTE, ZCL_IDENTIFY_CLUSTER_IDENTIFY_TIME_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

#endif /* HA_PROFILE_EXTENSIONS */

/*
 * \brief ZCL Identify Cluster commands defining macros
 */
#ifdef HA_PROFILE_EXTENSIONS

  #define IDENTIFY_CLUSTER_COMMANDS(identifyInd, identifyQueryInd, identifyQueryResponseInd, ezModeInvokeInd, updateCommissioningInd) \
    DEFINE_COMMAND(identifyCommand, ZCL_IDENTIFY_CLUSTER_IDENTIFY_COMMAND_ID, \
                   COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   identifyInd), \
    DEFINE_COMMAND(identifyQueryCommand, ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_COMMAND_ID, \
                   COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   identifyQueryInd), \
    DEFINE_COMMAND(identifyQueryResponseCommand, ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_RESPONSE_COMMAND_ID, \
                   COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   identifyQueryResponseInd), \
    DEFINE_COMMAND(ezModeInvokeCommand, ZCL_IDENTIFY_CLUSTER_EZ_MODE_INVOKE_COMMAND_ID, \
                   COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   ezModeInvokeInd), \
    DEFINE_COMMAND(updateCommissioningStateCommand, ZCL_IDENTIFY_CLUSTER_UPDATE_COMMISSIONING_STATE_COMMAND_ID, \
                   COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   updateCommissioningStateInd)

#else

  #define IDENTIFY_CLUSTER_COMMANDS(identifyInd, identifyQueryInd, identifyQueryResponseInd) \
    DEFINE_COMMAND(identifyCommand, ZCL_IDENTIFY_CLUSTER_IDENTIFY_COMMAND_ID, \
                   COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   identifyInd), \
    DEFINE_COMMAND(identifyQueryCommand, ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_COMMAND_ID, \
                   COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   identifyQueryInd), \
    DEFINE_COMMAND(identifyQueryResponseCommand, ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_RESPONSE_COMMAND_ID, \
                   COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                   identifyQueryResponseInd)

#endif /* HA_PROFILE_EXTENSIONS */

#define IDENTIFY_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = IDENTIFY_CLUSTER_ID, \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_IDENTIFY_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_IDENTIFY_SERVER_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (uint8_t *)clcommands \
  }

#define IDENTIFY_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = IDENTIFY_CLUSTER_ID, \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_IDENTIFY_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (uint8_t *)clcommands \
  }

#define DEFINE_IDENTIFY_CLUSTER(cltype, clattributes, clcommands) IDENTIFY_CLUSTER_##cltype(clattributes, clcommands)

#define IDENTIFY_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
  { \
    .id = IDENTIFY_CLUSTER_ID, \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_IDENTIFY_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_IDENTIFY_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (FLASH_PTR uint8_t *)clcommands \
  }

#define IDENTIFY_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
  { \
    .id = IDENTIFY_CLUSTER_ID, \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_IDENTIFY_CLUSTER_SERVER_COMMANDS_AMOUNT, \
    .commands = (FLASH_PTR uint8_t *)clcommands \
  }

#define DEFINE_IDENTIFY_CLUSTER_FLASH(cltype, clattributes, clcommands) IDENTIFY_CLUSTER_##cltype##_FLASH(clattributes, clcommands)
/******************************************************************************
                    Types section
******************************************************************************/

/**
 * \brief Update Commssioning State Payload format.
*/
typedef enum
{
  ZCL_UPDATE_COMMISSIONING_STATE_ACTION_NULL  = 0x00,
  ZCL_UPDATE_COMMISSIONING_STATE_ACTION_SET   = 0x01,
  ZCL_UPDATE_COMMISSIONING_STATE_ACTION_CLEAR = 0x02
} ZCL_UpdateCommissioningStateAction_t;

BEGIN_PACK
/**
 * \brief Identify Commissioning State attribute format.
*/
typedef struct PACK
{
  union PACK
  {
    LITTLE_ENDIAN_OCTET(3, (
      uint8_t networkState     : 1,
      uint8_t operationalState : 1,
      uint8_t reserved         : 6
    ))
    uint8_t data;
  };
} ZCL_CommissioningState_t;

/**
 * \brief Identify Command Payload format.
*/
typedef struct PACK
{
  uint16_t identifyTime;
} ZCL_Identify_t;

/**
 * \brief Identify Query Response Payload format.
*/
typedef struct PACK
{
  uint16_t timeout;
} ZCL_IdentifyQueryResponse_t;

/**
 * \brief EZ-Mode Invoke Payload format.
*/
typedef struct PACK
{
  union PACK
  {
    LITTLE_ENDIAN_OCTET(4, (
      uint8_t factoryFresh      : 1,
      uint8_t networkSteering   : 1,
      uint8_t findingAndBinding : 1,
      uint8_t reserved          : 5
    ))
    uint8_t data;
  };
} ZCL_EzModeInvoke_t;

/**
 * \brief Update Commssioning State Payload format.
*/
typedef struct PACK
{
  ZCL_UpdateCommissioningStateAction_t action;
  ZCL_CommissioningState_t commissioningStateMask;
} ZCL_UpdateCommissioningState_t;

/**
 * \brief Identify cluster attributes.
*/
typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t           type;
    uint8_t           properties;
    uint16_t          value;
  } identifyTime;

  struct PACK
  {
    ZCL_AttributeId_t        id;
    uint8_t                  type;
    uint8_t                  properties;
    ZCL_CommissioningState_t value;
  } commissioningState;
} ZCL_IdentifyClusterAttributes_t;

END_PACK

typedef struct
{
  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*identifyCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Identify_t *payload);
  } identifyCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*identifyQueryCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
  } identifyQueryCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*identifyQueryResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_IdentifyQueryResponse_t *payload);
  } identifyQueryResponseCommand;

#ifdef HA_PROFILE_EXTENSIONS
  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*ezModeInvokeCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_EzModeInvoke_t *payload);
  } ezModeInvokeCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*updateCommissioningCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_UpdateCommissioningState_t *payload);
  } updateCommissioningStateCommand;

#endif /* HA_PROFILE_EXTENSIONS */
} ZCL_IdentifyClusterCommands_t;

#endif /* _ZCLIDENTIFYCLUSTER_H */

