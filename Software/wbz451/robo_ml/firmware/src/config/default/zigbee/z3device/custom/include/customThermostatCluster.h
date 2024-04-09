/*******************************************************************************
 Custom Thermostat Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customThermostatCluster.h

  Summary:
    This file contains the Custom Thermostat cluster interface.

  Description:
    This file contains the Custom Thermostat cluster interface.
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

#ifndef _CUSTOMTHERMOSTATCLUSTER_H
#define _CUSTOMTHERMOSTATCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#define ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
#include <zcl/include/zclThermostatCluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#ifdef ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
/*Uncomment the following attribute if external node is used as temperature sensor*/
  #define THERMOSTAT_EXTERNAL_TEMPERATURE_SENSOR_NODE_AVAILABLE
#endif

#define THERMOSTAT_LOCAL_TEMPERATURE_MIN_REPORT_PERIOD 18
#define THERMOSTAT_LOCAL_TEMPERATURE_MAX_REPORT_PERIOD 28

#define THERMOSTAT_PI_CO0LING_DEMAND_MIN_REPORT_PERIOD 8
#define THERMOSTAT_PI_CO0LING_DEMAND_MAX_REPORT_PERIOD 32

#define THERMOSTAT_PI_HEATING_DEMAND_MIN_REPORT_PERIOD 10
#define THERMOSTAT_PI_HEATING_DEMAND_MAX_REPORT_PERIOD 36

#define ZCL_TH_LOCAL_TEMPERATURE_DEF    20
#define ZCL_TH_PI_COOLING_DEMAND_DEF    0
#define ZCL_TH_PI_HEATING_DEMAND_DEF    0
#define ZCL_TH_RUNNING_STATE_DEF ( ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_HEAT_STATE_BIT_POS) | \
                               ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_COOL_STATE_BIT_POS) | \
                               ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_FAN_STATE_BIT_POS) | \
                               ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_HEAT_STAGE2_STATE_BIT_POS) | \
                               ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_COOL_STAGE2_STATE_BIT_POS) | \
                               ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_FAN_STAGE2_STATE_BIT_POS) | \
                               ((uint8_t)ZCL_RUNNING_STATE_OFF << ZCL_FAN_STAGE3_STATE_BIT_POS) )
#define THERMOSTAT_LOCAL_TEMPERATURE_SCALE 100

/******************************************************************************
                    Typedefs section
******************************************************************************/
typedef struct PACK
{
  ZCL_AttributeId_t id;
  uint8_t type;
  uint8_t properties;
  int16_t value;
} setPoint_t;

/******************************************************************************
                    External variables section
******************************************************************************/
extern ZCL_ThermostatClusterServerAttributes_t customThermostatClusterServerAttributes;
extern ZCL_ThermostatClusterClientAttributes_t customThermostatClusterClientAttributes;
extern PROGMEM_DECLARE (ZCL_ThermostatClusterCommands_t customThermostatClusterServerCommands);

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Thermostat cluster
******************************************************************************/
void customThermostatClusterInit(void);
void thermostatClusterInitAttributes(void);
void thermostatUpdateServerAttributes(int16_t temperature);
#ifdef ZCL_THERMOSTAT_CLUSTER_INCLUDE_OPTIONAL_ATTRIBUTES
ZCL_Status_t thermostatSetOccupancy(ZCL_ThOccupancy_t value);
void thermostatUpdateThRunningMode(int16_t temperature);
#endif

/**************************************************************************//**
\brief Set alarm mask
******************************************************************************/
void thermostatSetAlarmMaskAttr(uint8_t alarMask);
/**************************************************************************//**
\brief Set alarm active or inactive
******************************************************************************/
void customSetAlarmActive(ZclThermostatAlarmCode_t alarmCode, bool setAlarm);
/**************************************************************************//**
\brief To check alaem is masked or not
******************************************************************************/
bool isAlarmMasked(ZclThermostatAlarmCode_t alarmCode);
/**************************************************************************//**
\brief Check alarm is active or not
******************************************************************************/
bool isAlarmActive(ZclThermostatAlarmCode_t alarmCode);

#if ZB_COMMISSIONING_ON_STARTUP == 0
/**************************************************************************//**
\brief Set local temperature
******************************************************************************/
void setLocalTemperature(int16_t temp);

/**************************************************************************//**
\brief Set Occupied cooling setpoint
******************************************************************************/
void setOccupiedCoolingSp(int16_t temp);

/**************************************************************************//**
\brief Set Occupied heating setpoint
******************************************************************************/
void setOccupiedHeatingSp(int16_t temp);

/**************************************************************************//**
\brief Set Absolute MinCoolSetpointLimit
******************************************************************************/
void setAbsMinCoolSetpointLimit(int16_t temp);

/**************************************************************************//**
\brief Set PI Cooling demand
******************************************************************************/
void setPiCoolingDemand(uint8_t temp);

/**************************************************************************//**
\brief Set PI Heating demand
******************************************************************************/
void setPiHeatingDemand(uint8_t temp);

#endif
#endif // _CUSTOMTHERMOSTATCLUSTER_H

// eof customThermostatCluster.h
