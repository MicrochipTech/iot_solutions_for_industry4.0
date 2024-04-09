/*******************************************************************************
  Zigbee Cluster Library Thermostat Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclThermostatCluster.h

  Summary:
    The header file describes the ZCL Thermostat Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Thermostat Cluster.
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


#ifndef _ZCLTHERMOSTATCLUSTER_H
#define _ZCLTHERMOSTATCLUSTER_H

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
#define ZCL_THERMOSTAT_TEMPERATURE_SCALE 100

/***************************************************************************//**
\brief Thermostat Cluster server attributes amount
*******************************************************************************/
#define ZCL_THERMOSTAT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 26

/***************************************************************************//**
\brief Thermostat Cluster client attributes amount. Clinet doesn't have attributes
*******************************************************************************/

#define ZCL_THERMOSTAT_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT 1

/***************************************************************************//**
\brief Thermostat Cluster commands amount
*******************************************************************************/

#define ZCL_THERMOSTAT_CLUSTER_COMMANDS_AMOUNT 1

/***************************************************************************//**
\brief Thermostat cluster server's attributes identifiers
*******************************************************************************/
/***************************************************************************//**
\brief Thermostat information attributes
*******************************************************************************/
#define ZCL_THERMOSTAT_CLUSTER_LOCAL_TEMPERATURE_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0000)
#define ZCL_THERMOSTAT_CLUSTER_OUTDOOR_TEMPERATURE_SERVER_ATTRIBUTE_ID          CCPU_TO_LE16(0x0001)
#define ZCL_THERMOSTAT_CLUSTER_OCUPANCY_SERVER_ATTRIBUTE_ID                     CCPU_TO_LE16(0x0002)
#define ZCL_THERMOSTAT_CLUSTER_ABS_MIN_HEAT_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0003)
#define ZCL_THERMOSTAT_CLUSTER_ABS_MAX_HEAT_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0004)
#define ZCL_THERMOSTAT_CLUSTER_ABS_MIN_COOL_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0005)
#define ZCL_THERMOSTAT_CLUSTER_ABS_MAX_COOL_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0006)
#define ZCL_THERMOSTAT_CLUSTER_PI_COOLING_DEMAND_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0007)
#define ZCL_THERMOSTAT_CLUSTER_PI_HEATING_DEMAND_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0008)
#define ZCL_THERMOSTAT_CLUSTER_HVAC_SYSTEM_TYPE_CONFIG_SERVER_ATTRIBUTE_ID      CCPU_TO_LE16(0x0009)

/***************************************************************************//**
\brief Thermostat Settings
*******************************************************************************/
#define ZCL_THERMOSTAT_CLUSTER_LOCAL_TEMPERATURE_CALIBRATION_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x0010)
#define ZCL_THERMOSTAT_CLUSTER_OCCUPIED_COOLING_SETPOINT_SERVER_ATTRIBUTE_ID      CCPU_TO_LE16(0x0011)
#define ZCL_THERMOSTAT_CLUSTER_OCCUPIED_HEATING_SETPOINT_SERVER_ATTRIBUTE_ID      CCPU_TO_LE16(0x0012)
#define ZCL_THERMOSTAT_CLUSTER_UNOCCUPIED_COOLING_SETPOINT_SERVER_ATTRIBUTE_ID    CCPU_TO_LE16(0x0013)
#define ZCL_THERMOSTAT_CLUSTER_UNOCCUPIED_HEATING_SETPOINT_SERVER_ATTRIBUTE_ID    CCPU_TO_LE16(0x0014)
#define ZCL_THERMOSTAT_CLUSTER_MIN_HEAT_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x0015)
#define ZCL_THERMOSTAT_CLUSTER_MAX_HEAT_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x0016)
#define ZCL_THERMOSTAT_CLUSTER_MIN_COOL_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x0017)
#define ZCL_THERMOSTAT_CLUSTER_MAX_COOL_SETPOINT_LIMIT_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x0018)
#define ZCL_THERMOSTAT_CLUSTER_MIN_SETPOINT_DEADBAND_SERVER_ATTRIBUTE_ID          CCPU_TO_LE16(0x0019)
#define ZCL_THERMOSTAT_CLUSTER_REMOTE_SENSING_SERVER_ATTRIBUTE_ID                 CCPU_TO_LE16(0x001A)
#define ZCL_THERMOSTAT_CLUSTER_CONTROL_SEQUENCE_OF_OPERATION_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x001B)
#define ZCL_THERMOSTAT_CLUSTER_SYSTEM_MODE_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x001C)
#define ZCL_THERMOSTAT_CLUSTER_ALARM_MASK_SERVER_ATTRIBUTE_ID                     CCPU_TO_LE16(0x001D)
#define ZCL_THERMOSTAT_CLUSTER_THERMOSTAT_RUNNING_MODE_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x001E)

/***************************************************************************//**
\brief HVAC Relay Attribute Set
*******************************************************************************/
#define ZCL_THERMOSTAT_CLUSTER_THERMOSTAT_RUNNING_STATE_SERVER_ATTRIBUTE_ID       CCPU_TO_LE16(0x0029)

/***************************************************************************//**
\brief Thermostat Cluster client's command identifiers
*******************************************************************************/

#define ZCL_THERMOSTAT_CLUSTER_SETPOINT_RAISE_LOWER_COMMAND_ID            0x00
#define ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
/***************************************************************************//**
\brief Thermostat Cluster attributes default definitions
*******************************************************************************/



#define ZCL_TH_ABS_MIN_HEAT_SP_LIMIT_DEF    7
#define ZCL_TH_ABS_MAX_HEAT_SP_LIMIT_DEF    30
#define ZCL_TH_ABS_MIN_COOL_SP_LIMIT_DEF    16
#define ZCL_TH_ABS_MAX_COOL_SP_LIMIT_DEF    32

#define ZCL_TH_LOCAL_TEMP_CALIB_DEF         0
#define ZCL_TH_OCCUPIED_COOLING_SP_DEF      26
#define ZCL_TH_OCCUPIED_HEATING_SP_DEF      20
#define ZCL_TH_UNOCCUPIED_COOLING_SP_DEF    26
#define ZCL_TH_UNOCCUPIED_HEATING_SP_DEF    20
#define ZCL_TH_MIN_HEAT_SP_LIMIT_DEF        7
#define ZCL_TH_MAX_HEAT_SP_LIMIT_DEF        30
#define ZCL_TH_MIN_COOL_SP_LIMIT_DEF        16
#define ZCL_TH_MAX_COOL_SP_LIMIT_DEF        32

#define ZCL_TH_MIN_SP_DEADBABD_DEF          0x19
#define ZCL_TH_REMOTE_SENSING_DEF           0

//Attribute Ids of Basic Cluster Information
#define ZCL_THERMOSTAT_CLUSTER_VERSION_ATTRIBUTE_ID                          CCPU_TO_LE16(0xfffd)

/***************************************************************************//**
\brief Thermostat Cluster server define attributes macros
*******************************************************************************/

#define ZCL_DEFINE_THERMOSTAT_CLUSTER_SERVER_MANDATORY_ATTRIBUTES(reportMin, reportMax) \
      
#define ZCL_DEFINE_THERMOSTAT_MEASUREMENT_CLUSTER_CLIENT_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_THERMOSTAT_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID) 
      
#ifdef ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
#define ZCL_DEFINE_THERMOSTAT_CLUSTER_SERVER_OPTIONAL_ATTRIBUTES(reportMin, reportMax) \
    DEFINE_ATTRIBUTE_WITH_BOUNDARY(thermostatRunningState, ZCL_READONLY_ATTRIBUTE, ZCL_THERMOSTAT_CLUSTER_THERMOSTAT_RUNNING_STATE_SERVER_ATTRIBUTE_ID, ZCL_16BIT_BITMAP_DATA_TYPE_ID, 0x00, 0x7f)
#endif /*ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES*/
/***************************************************************************//**
\brief Thermostat Cluster define commands macros
*******************************************************************************/

#define ZCL_DEFINE_THERMOSTAT_CLUSTER_COMMANDS(setpointCommandInd) 

/***************************************************************************//**
\brief Thermostat Cluster definition macros
*******************************************************************************/

#define THERMOSTAT_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define THERMOSTAT_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_THERMOSTAT_CLUSTER(cltype, clattributes, clcommands) \
    THERMOSTAT_CLUSTER_##cltype(clattributes, clcommands)

#define THERMOSTAT_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define THERMOSTAT_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = THERMOSTAT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_THERMOSTAT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_THERMOSTAT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DEFINE_THERMOSTAT_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    THERMOSTAT_CLUSTER_##cltype##_FLASH(clattributes, clcommands)
/******************************************************************************
                    Types section
******************************************************************************/
typedef enum _ZCL_ThSetPointMode_t
{
  ZCL_ADJUST_HEAT_SETPOINT,
  ZCL_ADJUST_COOL_SETPOINT,
  ZCL_ADJUST_HEAT_AND_COOL_SETPOINT,
}ZCL_ThSetPointMode_t;

typedef enum _ZCL_ThSystemMode_t
{
  ZCL_SYS_MODE_OFF = 0,
  ZCL_SYS_MODE_AUTO,
  ZCL_SYS_MODE_RESERVED,
  ZCL_SYS_MODE_COOL,
  ZCL_SYS_MODE_HEAT,
  ZCL_SYS_MODE_EMERGENCY_HEATING,
  ZCL_SYS_MODE_PRECOOLING,
  ZCL_SYS_MODE_FAN_ONLY,
  ZCL_SYS_MODE_DRY,
  ZCL_SYS_MODE_SLEEP
}ZCL_ThSystemMode_t;

typedef enum _ZCL_ThOccupancy_t
{
  ZCL_NOT_OCCUPIED = 0,
  ZCL_OCCUPIED = 1,  
}ZCL_ThOccupancy_t;

typedef enum _ZCL_ThHvacSystemTypeConfigCoolstage_t
{
  ZCL_HVAC_COOL_STAGE_1 = 0,
  ZCL_HVAC_COOL_STAGE_2,
  ZCL_HVAC_COOL_STAGE_3
}ZCL_ThHvacSystemTypeConfigCoolstage_t;

typedef enum _ZCL_ThHvacSystemTypeConfigHeatStage_t
{
  ZCL_HVAC_HEAT_STAGE_1 = 0,
  ZCL_HVAC_HEAT_STAGE_2,
  ZCL_HVAC_HEAT_STAGE_3
}ZCL_ThHvacSystemTypeConfigHeatStage_t;

typedef enum _ZCL_ThHvacSystemTypeConfigHeatType_t
{
  ZCL_HVAC_TYPE_CONVENTIONAL = 0,
  ZCL_HVAC_TYPE_PUMP,
}ZCL_ThHvacSystemTypeConfigHeatType_t;

typedef enum _ZCL_ThHvacSystemTypeConfigHeatSource_t
{
  ZCL_HVAC_SOURCE_ELECTRIC = 0,
  ZCL_HVAC_SOURCE_GAS,
}ZCL_ThHvacSystemTypeConfigHeatSource_t;

typedef enum _ZCL_ThRemoteSensing_t
{
  ZCL_SENSE_INTERNALLY = 0,
  ZCL_SENSE_EXTERNALLY = 1,
}ZCL_ThRemoteSensing_t;

typedef enum _ZCL_ThAlarmMaskState_t
{
  ZCL_TH_ALARM_DISABLED = 0,
  ZCL_TH_ALARM_ENABLED = 1,
}ZCL_ThAlarmMaskState_t;

typedef enum _ZCL_ThAlarmMaskBitPos_t
{
  ZCL_INIT_FAILURE_BIT_POS,
  ZCL_HARDWARE_FAILURE_BIT_POS,
  ZCL_SELF_CALIBRATION_FAILURE_BIT_POS,
}ZCL_ThAlarmMaskBitPos_t;

typedef enum _ZCL_ThRunningMode_t
{
  ZCL_RUNNING_MODE_OFF = 0,
  ZCL_RUNNING_MODE_COOL = 3,
  ZCL_RUNNING_MODE_HEAT = 4,
}ZCL_ThRunningMode_t;

typedef enum _ZCL_ThControlSeqOfOperation_t
{
  ZCL_COOL_ONLY,
  ZCL_COOL_WITH_REHEAT,
  ZCL_HEAT_ONLY,
  ZCL_HEAT_WITH_REHEAT,
  ZCL_COOL_HEAT_4PIPES,
  ZCL_COOL_HEAT_4PIPES_REHEAT
}ZCL_ThControlSeqOfOperation_t;

typedef enum _ZCL_ThRunningState_t
{
  ZCL_RUNNING_STATE_OFF = 0,
  ZCL_RUNNING_STATE_ON = 1,
}ZCL_ThRunningState_t;

typedef enum _ZCL_ThRunningStateBit_t
{
  ZCL_HEAT_STATE_BIT_POS,
  ZCL_COOL_STATE_BIT_POS,
  ZCL_FAN_STATE_BIT_POS,
  ZCL_HEAT_STAGE2_STATE_BIT_POS,
  ZCL_COOL_STAGE2_STATE_BIT_POS,
  ZCL_FAN_STAGE2_STATE_BIT_POS,
  ZCL_FAN_STAGE3_STATE_BIT_POS,
}ZCL_ThRunningStateBit_t;

typedef enum _ZclThermostatAlarmCode_t
{
  ZCL_INIT_FAILURE,
  ZCL_HARDWARE_FAILURE,
  ZCL_SELF_CALIBRATION_FAILURE,
  NO_OF_ALARM_CODES
}ZclThermostatAlarmCode_t;


BEGIN_PACK

/***************************************************************************//**
\brief Setpoint Raise/Lower Command Payload format
*******************************************************************************/
typedef struct PACK
{
  int8_t mode;
  int8_t amount;
} ZCL_SetpointRaiseLower_t;

/***************************************************************************//**
\brief Thermostat Cluster server's attributes
*******************************************************************************/

typedef struct PACK
{
#ifdef ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
#endif

#ifdef ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
#endif /* ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES*/

#ifdef ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  } thermostatRunningState;              //! <Attr ID 0x0029>  
 #endif
} ZCL_ThermostatClusterServerAttributes_t;

/**
 *   \brief Thermostat Cluster extension field set
 */
typedef struct PACK
{
    ClusterId_t clusterId;
    uint8_t     length;
    int16_t     occupiedCoolingSetpoint;
    int16_t     occupiedHeatingSetpoint;
    uint8_t     systemMode;
} ZCL_ThermostatClusterExtensionFieldSet_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;                 //! <Attr ID 0x0000>
} ZCL_ThermostatClusterClientAttributes_t;

END_PACK

/***************************************************************************//**
\brief Thermostat Cluster commands
*******************************************************************************/
typedef struct
{
} ZCL_ThermostatClusterCommands_t;

#endif /* _ZCLTHERMOSTATCLUSTER_H */

