/*******************************************************************************
  Zigbee Cluster Library Level Control Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclLevelControlCluster.h

  Summary:
    Interface and types of Level Control Cluster.

  Description:
    This file contains the Interface and types of Level Control Cluster.
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


#ifndef _ZCLLEVELCONTROLCLUSTER_H
#define _ZCLLEVELCONTROLCLUSTER_H

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
 * \brief Amount of Level Control cluster server's attributes
*/
#define ZCL_LEVEL_CONTROL_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 5

/**
 * \brief Client doesn't have attributes.
*/
#define ZCL_LEVEL_CONTROL_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT 1

/**
 * \brief Level Control Cluster commands amount
*/

#define ZCL_LEVEL_CONTROL_SERVER_CLUSTER_COMMANDS_AMOUNT 8
#define ZCL_LEVEL_CONTROL_CLIENT_CLUSTER_COMMANDS_AMOUNT 8

/**
 * \brief Level Control Cluster server's attributes identifiers
*/
#define ZCL_LEVEL_CONTROL_CLUSTER_VERSION_ATTRIBUTE_ID                  CCPU_TO_LE16(0xfffd)

/**
 * \brief Level Control Cluster server's attributes identifiers
*/

#define ZCL_LEVEL_CONTROL_CLUSTER_CURRENT_LEVEL_ATTRIBUTE_ID            CCPU_TO_LE16(0x0000)
#define ZCL_LEVEL_CONTROL_CLUSTER_REMAINING_TIME_ATTRIBUTE_ID           CCPU_TO_LE16(0x0001)
#define ZCL_LEVEL_CONTROL_CLUSTER_ON_OFF_TRANSITION_TIME_ATTRIBUTE_ID   CCPU_TO_LE16(0x0010)
#define ZCL_LEVEL_CONTROL_CLUSTER_ON_LEVEL_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0011)

/**
 * \brief On/Off Cluster client's command identifiers
*/

#define ZCL_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_COMMAND_ID          0x00
#define ZCL_LEVEL_CONTROL_CLUSTER_MOVE_COMMAND_ID                   0x01
#define ZCL_LEVEL_CONTROL_CLUSTER_STEP_COMMAND_ID                   0x02
#define ZCL_LEVEL_CONTROL_CLUSTER_STOP_COMMAND_ID                   0x03
#define ZCL_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_W_ONOFF_COMMAND_ID  0x04
#define ZCL_LEVEL_CONTROL_CLUSTER_MOVE_W_ONOFF_COMMAND_ID           0x05
#define ZCL_LEVEL_CONTROL_CLUSTER_STEP_W_ONOFF_COMMAND_ID           0x06
#define ZCL_LEVEL_CONTROL_CLUSTER_STOP_W_ONOFF_COMMAND_ID           0x07

/**
 * \brief Level Control Cluster default and special values
*/
#define ZCL_LEVEL_CONTROL_CLUSTER_ASAP_TRANSITION_TIME           0xffff
#define ZCL_LEVEL_CONTROL_CLUSTER_MOVE_IMMEDIATE_TRANSITION_TIME 0x0000

/**
 * \brief Level Control Cluster client define attributes macros
*/
#define ZCL_DEFINE_LEVEL_CONTROL_CLUSTER_CLIENT_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_LEVEL_CONTROL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/**
 * \brief Level Control  Cluster server define attributes macros
*/

#define ZCL_DEFINE_LEVEL_CONTROL_CLUSTER_SERVER_MANDATORY_ATTRIBUTES(min, max) \
    DEFINE_REPORTABLE_ATTRIBUTE(currentLevel, ZCL_READONLY_ATTRIBUTE, ZCL_LEVEL_CONTROL_CLUSTER_CURRENT_LEVEL_ATTRIBUTE_ID, ZCL_U8BIT_DATA_TYPE_ID, min, max), \
    DEFINE_ATTRIBUTE(remainingTime, ZCL_READONLY_ATTRIBUTE, ZCL_LEVEL_CONTROL_CLUSTER_REMAINING_TIME_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_LEVEL_CONTROL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

#define ZCL_DEFINE_LEVEL_CONTROL_CLUSTER_SERVER_OPTIONAL_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(onOffTransitionTime, ZCL_READWRITE_ATTRIBUTE, ZCL_LEVEL_CONTROL_CLUSTER_ON_OFF_TRANSITION_TIME_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE_WITH_BOUNDARY(onLevel, ZCL_READWRITE_ATTRIBUTE, ZCL_LEVEL_CONTROL_CLUSTER_ON_LEVEL_ATTRIBUTE_ID, ZCL_U8BIT_DATA_TYPE_ID, 0x00, 0xFE)


/**
 * \brief Level Control Cluster define commands macros
*/

#define ZCL_DEFINE_LEVEL_CONTROL_CLUSTER_COMMANDS(moveToLevelCommandInd,\
                                                  moveCommandInd,\
                                                  stepCommandInd,\
                                                  stopCommandInd,\
                                                  moveToLevelWOnOffCommandInd,\
                                                  moveWOnOffCommandInd,\
                                                  stepWOnOffCommandInd,\
                                                  stopWOnOffCommandInd)\
    DEFINE_COMMAND(moveToLevelCommand, ZCL_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_COMMAND_ID,                  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     moveToLevelCommandInd),                                                                \
    DEFINE_COMMAND(moveCommand, ZCL_LEVEL_CONTROL_CLUSTER_MOVE_COMMAND_ID,                                  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     moveCommandInd),                                                                       \
    DEFINE_COMMAND(stepCommand, ZCL_LEVEL_CONTROL_CLUSTER_STEP_COMMAND_ID,                                  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     stepCommandInd),                                                                       \
    DEFINE_COMMAND(stopCommand, ZCL_LEVEL_CONTROL_CLUSTER_STOP_COMMAND_ID,                                  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     stopCommandInd),                                                                       \
    DEFINE_COMMAND(moveToLevelWOnOffCommand, ZCL_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_W_ONOFF_COMMAND_ID,    \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     moveToLevelWOnOffCommandInd),                                                          \
    DEFINE_COMMAND(moveWOnOffCommand, ZCL_LEVEL_CONTROL_CLUSTER_MOVE_W_ONOFF_COMMAND_ID,                    \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     moveWOnOffCommandInd),                                                                 \
    DEFINE_COMMAND(stepWOnOffCommand, ZCL_LEVEL_CONTROL_CLUSTER_STEP_W_ONOFF_COMMAND_ID,                    \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     stepWOnOffCommandInd),                                                                 \
    DEFINE_COMMAND(stopWOnOffCommand, ZCL_LEVEL_CONTROL_CLUSTER_STOP_W_ONOFF_COMMAND_ID,                    \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     stopWOnOffCommandInd)

/**
 * \brief Level Control Cluster definition macros
*/

#define LEVEL_CONTROL_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = LEVEL_CONTROL_CLUSTER_ID, \
   .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
   .attributesAmount = ZCL_LEVEL_CONTROL_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_LEVEL_CONTROL_SERVER_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define LEVEL_CONTROL_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = LEVEL_CONTROL_CLUSTER_ID, \
   .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
   .attributesAmount = ZCL_LEVEL_CONTROL_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_LEVEL_CONTROL_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_LEVEL_CONTROL_CLUSTER(cltype, clattributes, clcommands) \
    LEVEL_CONTROL_CLUSTER_##cltype(clattributes, clcommands)

#define LEVEL_CONTROL_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = LEVEL_CONTROL_CLUSTER_ID, \
   .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
   .attributesAmount = ZCL_LEVEL_CONTROL_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_LEVEL_CONTROL_SERVER_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define LEVEL_CONTROL_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = LEVEL_CONTROL_CLUSTER_ID, \
   .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
   .attributesAmount = ZCL_LEVEL_CONTROL_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_LEVEL_CONTROL_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DEFINE_LEVEL_CONTROL_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    LEVEL_CONTROL_CLUSTER_##cltype##_FLASH(clattributes, clcommands)

#define DEFINE_LEVEL_CONTROL_CLUSTER_EXTENSION_FIELD_SET(value) \
    .clusterId = LEVEL_CONTROL_CLUSTER_ID, \
    .length = sizeof(uint8_t), \
    .currentLevel = value

/******************************************************************************
                    Types section
******************************************************************************/
BEGIN_PACK

/**
 * \brief Move To Level Command Payload format.
 */
typedef struct PACK
{
  uint8_t level;
  uint16_t transitionTime;
} ZCL_MoveToLevel_t;

typedef ZCL_MoveToLevel_t ZCL_MoveToLevelWithOnOff_t;

/**
 * \brief Move Command Payload format.
 */
typedef struct PACK
{
  uint8_t moveMode;
  uint8_t rate;
} ZCL_Move_t;

typedef ZCL_Move_t ZCL_MoveWithOnOff_t;

/**
 * \brief Step Command Payload format.
 */
typedef struct PACK
{
  uint8_t stepMode;
  uint8_t stepSize;
  uint16_t transitionTime;
} ZCL_Step_t;

typedef ZCL_Step_t ZCL_StepWithOnOff_t;

/**
 * \brief Level Control Cluster server's attributes
*/
typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value;
    ZCL_ReportTime_t  reportCounter;     //!<For internal use only
    ZCL_ReportTime_t  minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t  maxReportInterval; //!<Maximum reporting interval field value
    uint8_t           reportableChange;  //!<Reporting change field value
    ZCL_ReportTime_t  timeoutPeriod;     //!<Timeout period field value
    uint8_t           lastReportedValue; //!<Last reported value
  } currentLevel;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } remainingTime;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_LevelControlClusterServerAttributes_t;

/**
 * \brief Level Control Cluster client's attributes
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
} ZCL_LevelControlClusterClientAttributes_t;

/**
 *   \brief Level Control Cluster extension field set
 */
typedef struct PACK
{
    uint16_t clusterId;
    uint8_t length;
    uint8_t currentLevel;
} ZCL_LevelControlSceneExtensionFields_t;

END_PACK

/**
 * \brief MoveLevel command direction values
*/
typedef enum
{
  ZCL_MOVE_MODE_UP   = 0x00,
  ZCL_MOVE_MODE_DOWN = 0x01
} ZCL_MoveLevelMode_t;

/**
 * \brief StepLevel command direction values
*/
typedef enum
{
  ZCL_STEP_MODE_UP   = 0x00,
  ZCL_STEP_MODE_DOWN = 0x01
} ZCL_StepLevelMode_t;

/**
 * \brief Level Control Cluster clients's commands.
*/

typedef struct
{
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*moveToLevelCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_MoveToLevel_t *payload);
  } moveToLevelCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*moveCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Move_t *payload);
  } moveCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*stepCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Step_t *payload);
  } stepCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*stopCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
  } stopCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*moveToLevelWOnOffCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_MoveToLevelWithOnOff_t *payload);
  } moveToLevelWOnOffCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*moveWOnOffCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_MoveWithOnOff_t *payload);
  } moveWOnOffCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*stepWOnOffCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_StepWithOnOff_t *payload);
  } stepWOnOffCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*stopWOnOffCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
  } stopWOnOffCommand;
} ZCL_LevelControlClusterCommands_t;

#endif /* _ZCLLEVELCONTROLCLUSTER_H */
