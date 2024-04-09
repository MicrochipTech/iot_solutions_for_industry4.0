/*******************************************************************************
  Custom Alarm Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customAlarmsCluster.h

  Summary:
    This file contains the Custom Alarm Cluster interface.

  Description:
    This file contains the Custom Alarm Cluster interface.
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

#ifndef _CUSTOMALARMSCLUSTER_H
#define _CUSTOMALARMSCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclAlarmsCluster.h>

/******************************************************************************
                    Defines section
******************************************************************************/
#define ALARM_TABLE_SIZE 5

/******************************************************************************
                    External variables section
******************************************************************************/
extern ZCL_AlarmsClusterServerAttributes_t customAlarmsClusterServerAttributes;
extern ZCL_AlarmsClusterClientAttributes_t customAlarmsClusterClientAttributes;
extern PROGMEM_DECLARE (ZCL_AlarmsClusterServerCommands_t   customAlarmsClusterServerCommands);
extern PROGMEM_DECLARE (ZCL_AlarmsClusterClientCommands_t   customAlarmsClusterClientCommands);

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Identify cluster
******************************************************************************/
void customAlarmsClusterInit(void);

/**************************************************************************//**
\brief alarm notification raised by other clusters

\param[in] alarmCode - alarm code;
\param[in] clusterId - cluster identifier;
******************************************************************************/
void ZCL_AlarmNotification(ZCL_Alarm_t *alarm, Endpoint_t srcEndPoint, bool masked);

/**************************************************************************//**
\brief Add alarm entry

\param[in] alarmCode - alarm code;
\param[in] clusterId - cluster identifier;
******************************************************************************/
void addAlarmEntry(uint8_t alarmCode, ClusterId_t clusterId);

/**************************************************************************//**
\brief Removes the corresponding entry from the alarm log

\param[in] alarmCode - alarm code;
\param[in] clusterId - cluster identifier;
******************************************************************************/
void removeAlarmID(uint8_t alarmCode, ClusterId_t clusterId);

/**************************************************************************//**
\brief Sends Reset alarm command unicastly

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp   - source endpoint;
\param[in] alarmCode - alarm code to be reset;
\param[in] clsuetrId   - cluster identifier;
******************************************************************************/
void alarmsSendResetAlarm(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t alarmCode, ClusterId_t clusterId);

/**************************************************************************//**
\brief Sends Reset all alarms command unicastly

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp- source endpoint;
******************************************************************************/
void alarmsSendResetAllAlarms(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
\brief Sends Get Alarm command unicastly

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp- source endpoint;
******************************************************************************/
void alarmsSendGetAlarm(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
\brief Sends Get Alarm command unicastly

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp- source endpoint;
******************************************************************************/
void alarmsSendResetAlarmLog(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

#endif // _CUSTOMALARMSCLUSTER_H

// eof customAlarmsCluster.h
