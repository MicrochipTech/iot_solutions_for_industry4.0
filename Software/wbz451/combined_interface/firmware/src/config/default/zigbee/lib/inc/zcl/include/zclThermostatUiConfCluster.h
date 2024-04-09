/*******************************************************************************
  Zigbee Cluster Library Thermostat UI Configuration Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclThermostatUiConfCluster.h

  Summary:
    The header file describes the ZCL Thermostat Ui conf Cluster and its 
    interface

  Description:
    The file describes the types and interface of the 
    ZCL Thermostat UI conf Cluster.
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


#ifndef _ZCLTHERMOSTATUICONFCLUSTER_H
#define _ZCLTHERMOSTATUICONFCLUSTER_H
/*******************************************************************************
                   Includes section
*******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/
/***************************************************************************//**
\brief Thermostat Ui conf Cluster server attributes amount
*******************************************************************************/

#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 4

/***************************************************************************//**
\brief Thermostat UI conf Cluster client attributes amount. Clinet doesn't have attributes
*******************************************************************************/

#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT 1

/***************************************************************************//**
\brief Thermostat UI conf Cluster commands amount
*******************************************************************************/

#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_COMMANDS_AMOUNT 0

//Attribute Ids of Basic Cluster Information
#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_VERSION_ATTRIBUTE_ID                          CCPU_TO_LE16(0xfffd)

/***************************************************************************//**
\brief Thermostat UI conf Cluster server's attributes identifiers
*******************************************************************************/
// Thermostat ui conf information
#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_TEMPERATURE_DISPLAY_MODE_SERVER_ATTRIBUTE_ID         CCPU_TO_LE16(0x0000)
#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_KEYPAD_LOCKOUT_SERVER_ATTRIBUTE_ID                   CCPU_TO_LE16(0x0001)
#define ZCL_THERMOSTAT_UI_CONF_CLUSTER_SCHEDULE_PROGRAMMING_VISIBILITY_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0002)

/***************************************************************************//**
\brief Thermostat UI conf Cluster server define attributes macros
*******************************************************************************/

#define ZCL_DEFINE_THERMOSTAT_UI_CONF_CLUSTER_SERVER_ATTRIBUTES() 

/***************************************************************************//**
\brief Thermostat UI conf Cluster client define attributes macros
*******************************************************************************/
#define ZCL_DEFINE_THERMOSTAT_UI_CONF_CLUSTER_CLIENT_ATTRIBUTES() \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_THERMOSTAT_UI_CONF_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID) 
    
/***************************************************************************//**
\brief Thermostat Cluster definition macros
*******************************************************************************/

#define THERMOSTAT_UI_CONF_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_UI_CONF_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define THERMOSTAT_UI_CONF_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_UI_CONF_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}
#define DEFINE_THERMOSTAT_UI_CONF_CLUSTER(cltype, clattributes, clcommands) \
    THERMOSTAT_UI_CONF_CLUSTER_##cltype(clattributes, clcommands)

#define THERMOSTAT_UI_CONF_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_UI_CONF_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define THERMOSTAT_UI_CONF_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_UI_CONF_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_UI_CONF_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DEFINE_THERMOSTAT_UI_CONF_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    THERMOSTAT_UI_CONF_CLUSTER_##cltype##_FLASH(clattributes, clcommands)

/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  ZCL_TEMPERATURE_IN_CELSIUS = 0x00,
  ZCL_TEMPERATURE_IN_FAHRENHEIT = 0x01
} ZCL_ThUiConfTemperatureDisplayMode_t;

typedef enum
{
  ZCL_NO_LOCKOUT = 0x00,
  ZCL_LEVEL_1_LOCKOUT = 0x01,
  ZCL_LEVEL_2_LOCKOUT = 0x02,
  ZCL_LEVEL_3_LOCKOUT = 0x03,
  ZCL_LEVEL_4_LOCKOUT = 0x04,
  ZCL_LEVEL_5_LOCKOUT = 0x05
} ZCL_ThUiConfKeypadLockOut_t;

typedef enum
{
  ZCL_ENABLE_LOCAL_SCHEDULE_PROGRAMMING = 0x00,
  ZCL_DISABLE_LOCAL_SCHEDULE_PROGRAMMING = 0x01
} ZCL_ThUiConfScheduleProgVisibility_t;

BEGIN_PACK
/***************************************************************************//**
\brief Thermostat Cluster server's attributes
*******************************************************************************/

typedef struct PACK
{
} ZCL_ThermostatUiConfClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_ThermostatUiConfClusterClientAttributes_t;

END_PACK
#endif /* _ZCLTHERMOSTATUICONFCLUSTER_H */
