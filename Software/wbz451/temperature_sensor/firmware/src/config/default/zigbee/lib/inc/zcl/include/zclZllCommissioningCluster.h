/*******************************************************************************
  Zigbee Cluster Library ZLL Commissioning Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclZllCommissioningCluster.h

  Summary:
    The header file describes the ZLL Commissioning Cluster and its interface.

  Description:
    The header file describes the ZLL Commissioning Cluster and its interface.
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


#ifndef _ZCLZLLCOMISSIONINGCLUSTER_H
#define _ZCLZLLCOMISSIONINGCLUSTER_H

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
 * \brief Commissioning Server Cluster attributes amount.
*/

#define ZCL_COMMISSIONING_CLUSTER_SERVER_ATTRIBUTES_AMOUNT      1u

/**
 * \brief Commissioning Client Cluster attributes amount.
*/

#define ZCL_COMMISSIONING_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT      1u

/**
 * \brief Commissioning Client Cluster commands amount.
*/

#define ZCL_COMMISSIONING_CLUSTER_COMMANDS_AMOUNT               5u

/**
 * \brief Commissioning ClusterVersion attribute identifier
*/

#define ZCL_COMMISSIONING_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID         CCPU_TO_LE16(0xfffd)

/**
 * \brief Commissioning Server Cluster commands identifiers.
*/

#define ZCL_COMMISSIONING_CLUSTER_ENDPOINT_INFORMATION_COMMAND_ID             0x40
#define ZCL_COMMISSIONING_CLUSTER_GET_GROUP_IDENTIFIERS_RESPONSE_COMMAND_ID   0x41
#define ZCL_COMMISSIONING_CLUSTER_GET_ENDPOINT_LIST_RESPONSE_COMMAND_ID       0x42

/**
 * \brief Commissioning Client Cluster commands identifiers.
*/

#define ZCL_COMMISSIONING_CLUSTER_GET_GROUP_IDENTIFIERS_COMMAND_ID            0x41
#define ZCL_COMMISSIONING_CLUSTER_GET_ENDPOINT_LIST_COMMAND_ID                0x42

/**
 * \brief Commissioning Cluster server define attributes macros
*/

#define ZCL_DEFINE_COMMISSIONING_CLUSTER_SERVER_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_COMMISSIONING_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/**
 * \brief Commissioning Cluster client define attributes macros
*/

#define ZCL_DEFINE_COMMISSIONING_CLUSTER_CLIENT_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_COMMISSIONING_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/*
 * \brief ZCL Commissioning Cluster commands defining macros
 */

#define ZCL_DEFINE_COMMISSIONING_CLUSTER_COMMANDS(getGroupIdentifiersInd, getEndpointListInd, \
        endpointInformationResponseInd, getGroupIdentifiersResponseInd, getEndpointListResponseInd) \
    DEFINE_COMMAND(getGroupIdentifiersCommand, 0x41, COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), getGroupIdentifiersInd), \
    DEFINE_COMMAND(getEndpointListCommand, 0x42, COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), getEndpointListInd), \
    DEFINE_COMMAND(endpointInformationCommand, 0x40, COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), endpointInformationResponseInd), \
    DEFINE_COMMAND(getGroupIdentifiersResponseCommand, 0x41, COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), getGroupIdentifiersResponseInd), \
    DEFINE_COMMAND(getEndpointListResponseCommand, 0x42, COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), getEndpointListResponseInd)


#define COMMISSIONING_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = ZLL_COMMISSIONING_CLUSTER_ID, \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_COMMISSIONING_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_COMMISSIONING_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (uint8_t *)clcommands \
  }

#define COMMISSIONING_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = ZLL_COMMISSIONING_CLUSTER_ID, \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_COMMISSIONING_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_COMMISSIONING_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (uint8_t *)clcommands \
  }

#define DEFINE_COMMISSIONING_CLUSTER(cltype, clattributes, clcommands) COMMISSIONING_CLUSTER_##cltype(clattributes, clcommands)

/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief Get Group Identifiers command format
*/
typedef struct PACK
{
  uint8_t startIndex;
} ZCL_GetGroupIdentifiers_t;

/**
 * \brief Get Endpoint List command format
*/
typedef struct PACK
{
  uint8_t startIndex;
} ZCL_GetEndpointList_t;

/**
 * \brief Endpoint Information command format
*/
typedef struct PACK
{
  uint64_t ieeeAddress;
  uint16_t networkAddress;
  uint8_t  endpointId;
  uint16_t profileId;
  uint16_t deviceId;
  uint8_t  version;
} ZCL_EndpointInformation_t;

/**
 * \brief Group Information Record format
*/
typedef struct PACK
{
  uint16_t groupId;
  uint8_t  groupType;
} ZCL_GroupInformationRecord_t;

/**
 * \brief Endpoint Information Record format
*/
typedef struct PACK
{
  uint16_t networkAddress;
  uint8_t  endpointId;
  uint16_t profileId;
  uint16_t deviceId;
  uint8_t  version;
} ZCL_EndpointInformationRecord_t;

/**
 * \brief Get Group Identifiers Response command format
*/
typedef struct PACK
{
  uint8_t  total;
  uint8_t  startIndex;
  uint8_t  count;
  ZCL_GroupInformationRecord_t recordList[5];
} ZCL_GetGroupIdentifiersResponse_t;

/**
 * \brief Get Endpoint List Response command format
*/
typedef struct PACK
{
  uint8_t  total;
  uint8_t  startIndex;
  uint8_t  count;
  ZCL_EndpointInformationRecord_t recordList[1];
} ZCL_GetEndpointListResponse_t;

END_PACK

BEGIN_PACK
/***************************************************************************//**
  \brief
    Touchlink commissioning Cluster server side attributes
*******************************************************************************/
typedef struct PACK
{
  /*! TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;

} ZCL_CommissioningClusterServerAttributes_t;

/***************************************************************************//**
  \brief
    Touchlink commissioning Cluster client side attributes
*******************************************************************************/
typedef struct PACK
{
  /*! TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;

} ZCL_CommissioningClusterClientAttributes_t;

END_PACK

typedef struct
{
  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*getGroupIdentifiersCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiers_t *payload);
  } getGroupIdentifiersCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*getEndpointListCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointList_t *payload);
  } getEndpointListCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*endpointInformationCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_EndpointInformation_t *payload);
  } endpointInformationCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*getGroupIdentifiersResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetGroupIdentifiersResponse_t *payload);
  } getGroupIdentifiersResponseCommand;

  struct
  {
    ZCL_CommandId_t       id;
    ZclCommandOptions_t   options;
    ZCL_Status_t (*getEndpointListResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_GetEndpointListResponse_t *payload);
  } getEndpointListResponseCommand;
} ZCL_CommissioningClusterCommands_t;


#endif // _ZCLZLLCOMISSIONINGCLUSTER_H

// eof zclZllCommissioningCluster.h
