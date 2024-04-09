/*******************************************************************************
  Combined Interface Thermostat cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ciThermostatCluster.h

  Summary:
    This file contains the Combined Interface Thermostat cluster interface.

  Description:
    This file contains the Combined Interface Thermostat cluster interface.
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

#ifndef _CITHERMOSTATCLUSTER_H
#define _CITHERMOSTATCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclThermostatCluster.h>
#include <z3device/clusters/include/haClusters.h>
/******************************************************************************
                    Defines section
******************************************************************************/
#define THERMOSTAT_LOCAL_TEMPERATURE_SCALE 100

typedef struct PACK
{
  ZCL_AttributeId_t id;
  uint8_t type;
  uint8_t properties;
  int16_t value;
} setPoint_t;
/******************************************************************************
                    Externals
******************************************************************************/
extern PROGMEM_DECLARE (ZCL_ThermostatClusterCommands_t ciThermostatClusterCommands);
extern ZCL_ThermostatClusterClientAttributes_t ciThermostatClusterClientAttributes;
/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Initializes Thermostat cluster
******************************************************************************/
void ciThermostatClusterInit(void);

/**************************************************************************//**
  \brief Sends Setpoint Raise/Lower command

  \param[in] mode - address mode;
  \param[in] addr - short address of destination node;
  \param[in] ep   - destination endpoint;
  \param mode - set points to be adjusted
  \param amount - amount of increase/decrease to setpoint value
        (in steps of 0.1°C.)
  \return none
******************************************************************************/
void ciSendSetpointRaiseLowerCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,Endpoint_t srcEp,
  int8_t setPointMode, int8_t amount);

#endif // _CITHERMOSTATCLUSTER_H

// eof ciThermostatCluster.h
