/*******************************************************************************
  ZCL ZLL On/Off Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclZllOnOffCluster.h

  Summary:
    The header file describes the ZLL On/Off Cluster and its interface.

  Description:
    The header file describes the ZLL On/Off Cluster and its interface.
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


#ifndef _ZCLZLLONOFFCLUSTER_H
#define	_ZCLZLLONOFFCLUSTER_H

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

#define ZCL_ON_OFF_CLUSTER_ACCEPT_ONLY_WHEN_ON                      0x01u

#define ZCL_ON_OFF_CLUSTER_STARTUP_OFF                              0x00u
#define ZCL_ON_OFF_CLUSTER_STARTUP_ON                               0x01u
#define ZCL_ON_OFF_CLUSTER_STARTUP_TOGGLE                           0x02u
#define ZCL_ON_OFF_CLUSTER_STARTUP_PREVIOUS                         0xffu

/**
 * \brief On/Off Cluster server attributes amount
*/
#define ZCL_ONOFF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT                  6u

/**
 * \brief On/Off Cluster client attributes amount. Clinet doesn't have attributes.
*/

#define ZCL_ONOFF_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT                  1u

/**
 * \brief On/Off Cluster commands amount
*/

#define ZCL_ONOFF_SERVER_CLUSTER_COMMANDS_AMOUNT                    6u
#define ZCL_ONOFF_CLIENT_CLUSTER_COMMANDS_AMOUNT                    6u

/**
 * \brief On/Off ClusterVersion attribute identifier
*/

#define ZCL_ONOFF_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID       CCPU_TO_LE16(0xfffd)

/**
 * \brief On/Off Cluster server's attributes identifiers
*/

#define ZCL_ONOFF_CLUSTER_ONOFF_SERVER_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0000)
#define ZCL_ONOFF_CLUSTER_GLOBAL_SCENE_CONTROL_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x4000)
#define ZCL_ONOFF_CLUSTER_ON_TIME_SERVER_ATTRIBUTE_ID               CCPU_TO_LE16(0x4001)
#define ZCL_ONOFF_CLUSTER_OFF_WAIT_TIME_SERVER_ATTRIBUTE_ID         CCPU_TO_LE16(0x4002)
#if ZLO_CLUSTER_ENHANCEMENTS == 1
#define ZCL_ONOFF_CLUSTER_STARTUP_ONOFF_SERVER_ATTRIBUTE_ID         CCPU_TO_LE16(0x4003)
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */

/**
 * \brief On/Off Cluster client's command identifiers
*/

#define ZCL_ONOFF_CLUSTER_OFF_COMMAND_ID                            0x00u
#define ZCL_ONOFF_CLUSTER_ON_COMMAND_ID                             0x01u
#define ZCL_ONOFF_CLUSTER_TOGGLE_COMMAND_ID                         0x02u
#define ZCL_ONOFF_CLUSTER_OFF_WITH_EFFECT_COMMAND_ID                0x40u
#define ZCL_ONOFF_CLUSTER_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID    0x41u
#define ZCL_ONOFF_CLUSTER_ON_WITH_TIMED_OFF_COMMAND_ID              0x42u

/**
 * \brief On/Off Cluster server define attributes macros
*/

#if ZLO_CLUSTER_ENHANCEMENTS == 1
#define ZCL_DEFINE_ONOFF_CLUSTER_SERVER_ATTRIBUTES(min, max) \
    DEFINE_REPORTABLE_ATTRIBUTE(onOff,   ZCL_READONLY_ATTRIBUTE,  ZCL_ONOFF_CLUSTER_ONOFF_SERVER_ATTRIBUTE_ID,                ZCL_BOOLEAN_DATA_TYPE_ID, min, max), \
    DEFINE_ATTRIBUTE(globalSceneControl, ZCL_READONLY_ATTRIBUTE,  ZCL_ONOFF_CLUSTER_GLOBAL_SCENE_CONTROL_SERVER_ATTRIBUTE_ID, ZCL_BOOLEAN_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(onTime,             ZCL_READWRITE_ATTRIBUTE, ZCL_ONOFF_CLUSTER_ON_TIME_SERVER_ATTRIBUTE_ID,              ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(offWaitTime,        ZCL_READWRITE_ATTRIBUTE, ZCL_ONOFF_CLUSTER_OFF_WAIT_TIME_SERVER_ATTRIBUTE_ID,        ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(startUpOnOff,       ZCL_READWRITE_ATTRIBUTE, ZCL_ONOFF_CLUSTER_STARTUP_ONOFF_SERVER_ATTRIBUTE_ID,        ZCL_8BIT_ENUM_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(clusterVersion,     ZCL_READONLY_ATTRIBUTE,  ZCL_ONOFF_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID,      ZCL_U16BIT_DATA_TYPE_ID)
#else
#define ZCL_DEFINE_ONOFF_CLUSTER_SERVER_ATTRIBUTES(min, max) \
    DEFINE_REPORTABLE_ATTRIBUTE(onOff,   ZCL_READONLY_ATTRIBUTE,  ZCL_ONOFF_CLUSTER_ONOFF_SERVER_ATTRIBUTE_ID,                ZCL_BOOLEAN_DATA_TYPE_ID, min, max), \
    DEFINE_ATTRIBUTE(globalSceneControl, ZCL_READONLY_ATTRIBUTE,  ZCL_ONOFF_CLUSTER_GLOBAL_SCENE_CONTROL_SERVER_ATTRIBUTE_ID, ZCL_BOOLEAN_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(onTime,             ZCL_READWRITE_ATTRIBUTE, ZCL_ONOFF_CLUSTER_ON_TIME_SERVER_ATTRIBUTE_ID,              ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(offWaitTime,        ZCL_READWRITE_ATTRIBUTE, ZCL_ONOFF_CLUSTER_OFF_WAIT_TIME_SERVER_ATTRIBUTE_ID,        ZCL_U16BIT_DATA_TYPE_ID), \
    DEFINE_ATTRIBUTE(clusterVersion,     ZCL_READONLY_ATTRIBUTE,  ZCL_ONOFF_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID,      ZCL_U16BIT_DATA_TYPE_ID)
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */
/**
 * \brief On/Off Cluster client define attributes macros
*/
#define ZCL_DEFINE_ONOFF_CLUSTER_CLIENT_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_ONOFF_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID) 
/**
 * \brief On/Off Cluster define commands macros
*/

#define ZCL_DEFINE_ONOFF_CLUSTER_COMMANDS(onCommandInd, offCommandInd, toggleCommandInd, offWithEffectInd, onWithRecallGlobalSceneInd, onWithTimedOffInd) \
    DEFINE_COMMAND(onCommand, ZCL_ONOFF_CLUSTER_ON_COMMAND_ID,  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), \
                     onCommandInd), \
    DEFINE_COMMAND(offCommand, ZCL_ONOFF_CLUSTER_OFF_COMMAND_ID, \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), \
                     offCommandInd), \
    DEFINE_COMMAND(toggleCommand, ZCL_ONOFF_CLUSTER_TOGGLE_COMMAND_ID, \
                      COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), \
                     toggleCommandInd), \
    DEFINE_COMMAND(offWithEffectCommand, ZCL_ONOFF_CLUSTER_OFF_WITH_EFFECT_COMMAND_ID,  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), \
                     offWithEffectInd), \
    DEFINE_COMMAND(onWithRecallGlobalSceneCommand, ZCL_ONOFF_CLUSTER_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID,  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), \
                     onWithRecallGlobalSceneInd), \
    DEFINE_COMMAND(onWithTimedOffCommand, ZCL_ONOFF_CLUSTER_ON_WITH_TIMED_OFF_COMMAND_ID,  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_NO_ACK), \
                     onWithTimedOffInd)

/**
 * \brief On/Off Cluster definition macros
*/

#define ONOFF_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = ONOFF_CLUSTER_ID, \
   .options = \
   { \
     .type = ZCL_CLIENT_CLUSTER_TYPE, \
     .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
     .reserved = 0, \
   }, \
   .attributesAmount = ZCL_ONOFF_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ONOFF_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define ONOFF_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = ONOFF_CLUSTER_ID, \
   .options = \
   { \
     .type = ZCL_SERVER_CLUSTER_TYPE, \
     .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
     .reserved = 0, \
   }, \
   .attributesAmount = ZCL_ONOFF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ONOFF_SERVER_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_ONOFF_CLUSTER(cltype, clattributes, clcommands) \
    ONOFF_CLUSTER_##cltype(clattributes, clcommands)

/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief On/Off Cluster server's attributes
*/

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    bool                value;
    ZCL_ReportTime_t    reportCounter;     //!<For internal use only
    ZCL_ReportTime_t    minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t    maxReportInterval; //!<Maximum reporting interval field value
    bool                reportableChange;  //!<Reporting change field value
    ZCL_ReportTime_t    timeoutPeriod;     //!<Timeout period field value
    bool                lastReportedValue; //!<Last reported value
  } onOff;
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    bool                value;
  } globalSceneControl;
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } onTime;
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } offWaitTime;
#if ZLO_CLUSTER_ENHANCEMENTS == 1
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint8_t             value;
  } startUpOnOff;
#endif

  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;    
  } clusterVersion;
  
} ZCL_OnOffClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;
} ZCL_OnOffClusterClientAttributes_t;

/**
 *   \brief On/Off Cluster extension field set
 */
typedef struct PACK
{
    uint16_t  clusterId;
    uint8_t   length;
    bool      onOffValue;
} ZCL_OnOffClusterExtensionFieldSet_t;

typedef struct PACK
{
  uint8_t     effectIdentifier;
  uint8_t     effectVariant;
} ZCL_OffWithEffect_t;

typedef struct PACK
{
  uint8_t   onOffControl;
  uint16_t  onTime;
  uint16_t  offWaitTime;
} ZCL_OnWithTimedOff_t;

END_PACK

/**
 * \brief On/Off Cluster clients's commands.
*/

typedef struct
{
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*onCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } onCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*offCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } offCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*toggleCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } toggleCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*offWithEffectCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OffWithEffect_t * payload);
  } offWithEffectCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*onWithRecallGlobalSceneCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } onWithRecallGlobalSceneCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*onWithTimedOffCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OnWithTimedOff_t * payload);
  } onWithTimedOffCommand;
} ZCL_OnOffClusterCommands_t;

#define DEFINE_ONOFF_CLUSTER_EXTENSION_FIELD_SET(value) \
    .clusterId = ONOFF_CLUSTER_ID, \
    .length = sizeof(uint8_t), \
    .onOffValue = value

#endif	/* _ZCLZLLONOFFCLUSTER_H */

