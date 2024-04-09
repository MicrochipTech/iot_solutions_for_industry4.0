/*******************************************************************************
  ZCL Alarm Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclAlarmsCluster.h

  Summary:
    The header file describes the ZCL Alarm Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Alarm Cluster.
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


#ifndef _ZCLALARMSCLUSTER_H
#define _ZCLALARMSCLUSTER_H

/*!
Attributes and commands for sending alarm notifications and configuring alarm
functionality.
*/

/*******************************************************************************
                   Includes section
*******************************************************************************/

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/

/***************************************************************************//**
  \brief ZCL Alarms Cluster server side commands amount
*******************************************************************************/
#define ZCL_ALARMS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT        2

/***************************************************************************//**
  \brief ZCL Alarms Cluster derver side commands amount
*******************************************************************************/
#define ZCL_ALARMS_CLUSTER_SERVER_COMMANDS_AMOUNT          6

/***************************************************************************//**
  \brief ZCL Alarms Cluster client side commands amount
*******************************************************************************/
#define ZCL_ALARMS_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT        1
//There are no any attributes at the client side

/***************************************************************************//**
  \brief ZCL Alarms Cluster derver side commands amount
*******************************************************************************/
#define ZCL_ALARMS_CLUSTER_CLIENT_COMMANDS_AMOUNT          6

//Atribute Ids of alarm Information Attribute Set at the server side
//!ZCL Alarms Cluster server side alarmCount attribute id
#define ZCL_ALARMS_CLUSTER_SERVER_ALARM_COUNT_ATTRIBUTE_ID               CCPU_TO_LE16(0x0000)

//Attribute Ids of Basic Cluster Information
#define ZCL_ALARMS_CLUSTER_VERSION_ATTRIBUTE_ID                          CCPU_TO_LE16(0xfffd)

//!ZCL Alarms Cluster server side ResetAlarm command id
#define ZCL_ALARMS_CLUSTER_SERVER_RESET_ALARM_COMMAND_ID        0x00
//!ZCL Alarms Cluster server side ResetAllAlarms command id
#define ZCL_ALARMS_CLUSTER_SERVER_RESET_ALL_ALARMS_COMMAND_ID   0x01
//!ZCL Alarms Cluster server side GetAlarm command id
#define ZCL_ALARMS_CLUSTER_SERVER_GET_ALARM_COMMAND_ID          0x02
//!ZCL Alarms Cluster server side ResetAlarmLog command id
#define ZCL_ALARMS_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID    0x03

//!ZCL Alarms Cluster server side Alarm command id
#define ZCL_ALARMS_CLUSTER_CLIENT_ALARM_COMMAND_ID                0x00
//!ZCL Alarms Cluster server side GetAlarmResponse command id
#define ZCL_ALARMS_CLUSTER_CLIENT_GET_ALARM_RESPONSE_COMMAND_ID   0x01

/*******************************************************************************
                   Types section
*******************************************************************************/

/***************************************************************************//**
  \brief ZCL Alarms Cluster server side attributes defining macros

  This macros should be used for ZCL Alarm Cluster server side attributes defining.

  \return None

  \internal
  //The typical usage is:
  //Alarm Cluster server side related attributes
  ZCL_AlarmClusterServerAttributes_t alarmClusterAttributes = ZCL_DEFINE_ALARM_CLUSTER_SERVER_ATTRIBUTES();
*******************************************************************************/
#define ZCL_DEFINE_ALARMS_CLUSTER_SERVER_ATTRIBUTES()           

#define ZCL_DEFINE_ALARMS_CLUSTER_CLIENT_ATTRIBUTES() \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_ALARMS_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID) 
/**
 * \brief Alarm Cluster define commands macros
 */

#define ZCL_DEFINE_ALARMS_CLUSTER_SERVER_COMMANDS(resetAlarmCommandInd, resetAllAlarmsCommandInd, getAlarmCommandInd, \
                                          resetAlarmLogCommandInd) 

#define ZCL_DEFINE_ALARMS_CLUSTER_CLIENT_COMMANDS(alarmCommandInd, getAlarmResponseCommandInd) \
    DEFINE_COMMAND(alarm, ZCL_ALARMS_CLUSTER_CLIENT_ALARM_COMMAND_ID,  \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     alarmCommandInd), \
    DEFINE_COMMAND(getAlarmResponse, ZCL_ALARMS_CLUSTER_CLIENT_GET_ALARM_RESPONSE_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     getAlarmResponseCommandInd)

/***************************************************************************//**
  \brief ZCL Alarms Cluster server side defining macros

  This macros should be used with #ZCL_DEFINE_ALARM_CLUSTER_SERVER_ATTRIBUTES for
  ZCL Basic Cluster server side defining in application.

  \param attributes - pointer to cluster server attributes (ZCL_AlarmClusterServerAttributes_t)

  \return None

  \internal
  //The typical code is:
  //Alarm Cluster server side related attributes
  ZCL_AlarmClusterServerAttributes_t alarmClusterServerAttributes = DEFINE_ZCL_ALARM_CLUSTER_SERVER_ATTRIBUTES();
  ZCL_Cluster_t myClusters[] =
  {
    ZCL_DEFINE_ALARM_CLUSTER_SERVER(&alarmClusterServerAttributes, &alarmClusterServerCommands),
    //... Any other cluster defining ...
  }
*******************************************************************************/
#define ALARMS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands)                      \
  {                                                                                           \
    .id = ALARMS_CLUSTER_ID,                                                                  \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},\
    .attributesAmount = ZCL_ALARMS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT,                          \
    .attributes = (uint8_t *) clattributes,                                                   \
    .commandsAmount = ZCL_ALARMS_CLUSTER_SERVER_COMMANDS_AMOUNT,                              \
    .commands = (uint8_t *)clcommands                                                         \
  }

#define ZCL_DEFINE_ALARMS_CLUSTER_SERVER_FLASH(clattributes) ALARMS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes)
/***************************************************************************//**
  \brief ZCL alarms Cluster client side defining macros

  This macros should be used for ZCL alarm Cluster client side defining in application.

  \return None

  \internal
  //The typical code is:
  ZCL_Cluster_t myClusters[] =
  {
    ZCL_DEFINE_ALARM_CLUSTER_CLIENT(),
    //... Any other cluster defining ...
  }
*******************************************************************************/
#define ALARMS_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands)                      \
  {                                                                                           \
    .id = ALARMS_CLUSTER_ID,                                                                  \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},\
    .attributesAmount = ZCL_ALARMS_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT,                          \
    .attributes = NULL,                                                                       \
    .commandsAmount = ZCL_ALARMS_CLUSTER_CLIENT_COMMANDS_AMOUNT,                              \
    .commands = (uint8_t *)clcommands                                                         \
  }

#define DEFINE_ALARMS_CLUSTER(cltype, clattributes, clcommands) \
    ALARMS_CLUSTER_##cltype(clattributes, clcommands)

#define ZCL_DEFINE_ALARMS_CLUSTER_CLIENT_FLASH() ALARMS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE()
BEGIN_PACK
/***************************************************************************//**
  \brief
    ZCL Alarm Cluster server side attributes
*******************************************************************************/
typedef struct PACK
{
  //!Alarm Information attribute set (Id == 0x00)
  //!Alarm Device Settings attribute set (Id == 0x01)
} ZCL_AlarmsClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_AlarmsClusterClientAttributes_t;

/***************************************************************************//**
  \brief
    ZCL Alarm Cluster server side command payload structures
*******************************************************************************/
/**
 * \brief Reset alarm Command Payload format.
 */

typedef struct PACK
{
  uint8_t alarmCode;
  ClusterId_t clusterIdentifier;
} ZCL_ResetAlarm_t;

/***************************************************************************//**
  \brief
    ZCL Alarm Cluster server side alarm table structure
*******************************************************************************/
typedef struct PACK
{
  uint8_t alarmCode;
  ClusterId_t clusterIdentifier;
  uint32_t timeStamp;
} ZCL_AlarmEntry_t;

/***************************************************************************//**
  \brief
    ZCL Alarm Cluster server alarm event notification
*******************************************************************************/
typedef struct PACK
{
  ZCL_CommandId_t commandId;
  uint8_t alarmCode;
  ClusterId_t clusterIdentifier;
} ZCL_ResetAlarmNotification_t;

/***************************************************************************//**
  \brief
    ZCL Alarm Cluster client side command payload structures
*******************************************************************************/
/**
 * \brief Alarm Command Payload format.
 */

typedef struct PACK
{
  uint8_t alarmCode;
  ClusterId_t clusterIdentifier;
} ZCL_Alarm_t;

typedef struct PACK
{
  uint8_t status;
  uint8_t alarmCode;
  ClusterId_t clusterIdentifier;
  uint32_t timeStamp;
} ZCL_getAlarmResponse_t;

END_PACK

/***************************************************************************//**
  \brief
    Describes the Alarm Cluster server side commands
*******************************************************************************/
typedef struct PACK
{
} ZCL_AlarmsClusterServerCommands_t;

/***************************************************************************//**
  \brief
    Describes the Alarm Cluster client side commands

*******************************************************************************/
typedef struct PACK
{
  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x00, #ZCL_ALARM_CLUSTER_SERVER_ALARM_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes
    */
    ZCL_Status_t(*alarmCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Alarm_t * payload);
  } alarm;
  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x01, #ZCL_ALARM_CLUSTER_SERVER_GET_ALARM_RESPONSE_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes
    */
    ZCL_Status_t(*getAlarmResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_getAlarmResponse_t * payload);
  } getAlarmResponse;
} ZCL_AlarmsClusterClientCommands_t;

#endif //#ifndef _ZCLALARMSCLUSTER_H

//eof zclAlarmsCluster.h
