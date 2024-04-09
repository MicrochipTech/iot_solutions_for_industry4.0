/*******************************************************************************
  ZCL ZLL Identify Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclZllIdentifyCluster.h

  Summary:
    The header file describes the ZLL Identify Cluster and its interface.

  Description:
    The header file describes the ZLL Identify Cluster and its interface.
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


#ifndef _ZCLZLLIDENTIFYCLUSTER_H
#define _ZCLZLLIDENTIFYCLUSTER_H

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
 * \brief Identify ClusterVersion attribute identifier (for both server and client)
*/
#define ZCL_IDENTIFY_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID    CCPU_TO_LE16(0xfffd)

/**
 * \brief Identify Server Cluster attributes identifiers.
*/
#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_TIME_ATTRIBUTE_ID             CCPU_TO_LE16(0x0000)

/**
 * \brief Identify Server Cluster commands identifiers.
*/

#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_RESPONSE_COMMAND_ID     0x00u

/**
 * \brief Identify Client Cluster commands identifiers.
*/

#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_COMMAND_ID                    0x00u
#define ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_COMMAND_ID              0x01u
#define ZCL_IDENTIFY_CLUSTER_TRIGGER_EFFECT_COMMAND_ID              0x40u

/*
 *\brief ZCL Idetify Cluster server side attributes defining macros
 */

#define ZCL_DEFINE_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES() \
  DEFINE_ATTRIBUTE(identifyTime,   ZCL_READWRITE_ATTRIBUTE, ZCL_IDENTIFY_CLUSTER_IDENTIFY_TIME_ATTRIBUTE_ID,          ZCL_U16BIT_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE,  ZCL_IDENTIFY_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/*
 *\brief ZCL Idetify Cluster client side attributes defining macros
 */

#define ZCL_DEFINE_IDENTIFY_CLUSTER_CLIENT_ATTRIBUTES() \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_IDENTIFY_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/*
 * \brief ZCL Identify Cluster commands defining macros
 */

#define ZCL_IDENTIFY_CLUSTER_COMMANDS(identifyCommandInd, identifyQueryCommandInd, triggerEffectCommandInd, identifyQueryResponseCommandInd) \
    DEFINE_COMMAND(identifyCommand,              0x00, COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), identifyCommandInd), \
    DEFINE_COMMAND(identifyQueryCommand,         0x01, COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),       identifyQueryCommandInd), \
    DEFINE_COMMAND(triggerEffectCommand,         0x40, COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), triggerEffectCommandInd), \
    DEFINE_COMMAND(identifyQueryResponseCommand, 0x00, COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),    identifyQueryResponseCommandInd)

#define IDENTIFY_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id               = IDENTIFY_CLUSTER_ID, \
    .options          = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_IDENTIFY_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
    .attributes       = (uint8_t *)clattributes, \
    .commandsAmount   = ZCL_IDENTIFY_SERVER_CLUSTER_COMMANDS_AMOUNT, \
    .commands         = (uint8_t *)clcommands \
  }

#define IDENTIFY_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id               = IDENTIFY_CLUSTER_ID, \
    .options          = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
    .attributes       = (uint8_t *)clattributes, \
    .commandsAmount   = ZCL_IDENTIFY_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
    .commands         = (uint8_t *)clcommands \
  }

#define DEFINE_IDENTIFY_CLUSTER(cltype, clattributes, clcommands) IDENTIFY_CLUSTER_##cltype(clattributes, clcommands)

/******************************************************************************
                    Types section
******************************************************************************/

/**
 * \brief Possible values for the Effect Identifier field.
*/
enum
{
  ZCL_EFFECT_IDENTIFIER_BLINK           = 0x00,
  ZCL_EFFECT_IDENTIFIER_BREATHE         = 0x01,
  ZCL_EFFECT_IDENTIFIER_OKAY            = 0x02,
  ZCL_EFFECT_IDENTIFIER_CHANNEL_CHANGE  = 0x0b,
  ZCL_EFFECT_IDENTIFIER_FINISH_EFFECT   = 0xfe,
  ZCL_EFFECT_IDENTIFIER_STOP_EFFECT     = 0xff,
};

/**
 * \brief Possible values for the Effect Variant field.
*/
enum
{
  ZCL_EFFECT_VARIANT_DEFAULT            = 0x00,
};

BEGIN_PACK

/**
 * \brief Identify Command Payload format.
*/
typedef struct PACK
{
  uint16_t identifyTime;
} ZCL_Identify_t;

/**
 * \brief Trigger Effect Command Payload format.
*/
typedef struct PACK
{
  uint8_t effectIdentifier;
  uint8_t effectVariant;
} ZCL_TriggerEffect_t;

/**
 * \brief Identify Query Response Payload format.
*/
typedef struct PACK
{
  uint16_t timeout;
} ZCL_IdentifyQueryResponse_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } identifyTime;

  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;

} ZCL_IdentifyClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;
} ZCL_IdentifyClusterClientAttributes_t;

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
    ZCL_Status_t (*triggerEffectCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_TriggerEffect_t *payload);
  } triggerEffectCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*identifyQueryResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_IdentifyQueryResponse_t *payload);
  } identifyQueryResponseCommand;
} ZCL_IdentifyClusterCommands_t;


#endif // _ZCLZLLIDENTIFYCLUSTER_H

// eof zclZllIdentifyCluster.h
