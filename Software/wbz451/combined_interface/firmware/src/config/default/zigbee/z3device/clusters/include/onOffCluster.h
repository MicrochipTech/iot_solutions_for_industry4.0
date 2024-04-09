/*******************************************************************************
  On Off Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    onOffCluster.h

  Summary:
    This file contains On Off Cluster Implemenation.

  Description:
    This file contains On Off Cluster Implemenation.
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

#ifndef _ONOFFCLUSTER_H
#define _ONOFFCLUSTER_H
/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclZllOnOffCluster.h>

/******************************************************************************
                    Types section
******************************************************************************/
/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  OFF_COMMAND    = 0,
  ON_COMMAND     = 1,
  TOGGLE_COMMAND = 2
} OnOffToggle_t;

/******************************************************************************
                    Externals
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Sends On, Off or Toggle command to bound devices

\param[in] mode    - address mode;
\param[in] addr    - short address of destination node or number of group;
\param[in] ep      - endpoint number of destination device;
\param[in] command - command id
******************************************************************************/
void onOffSendOnOffToggle(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, OnOffToggle_t command);

/**************************************************************************//**
\brief Sends OffWithEffect command to bound devices

\param[in] mode          - address mode;
\param[in] addr          - short address of destination node or number of group;
\param[in] ep            - endpoint number of destination device;
\param[in] effectId      - effect identifier;
\param[in] effectVariant - effect variant;
******************************************************************************/
void onOffSendOffWithEffect(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
                           uint8_t effectId, uint8_t effectVariant);

/**************************************************************************//**
\brief Sends OnWithRecallGlobalScene command to bound devices

\param[in] mode          - address mode;
\param[in] addr          - short address of destination node or number of group;
\param[in] ep            - endpoint number of destination device;
******************************************************************************/
void onOffSendOnWithRecallGlobalScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
\brief Sends OnWithTimedOff command to bound devices

\param[in] mode          - address mode;
\param[in] addr          - short address of destination node or number of group;
\param[in] ep            - endpoint number of destination device;
\param[in] onOffControl  - on/off control
\param[in] onTime        - on time in 1/10ths of second
\param[in] offWaitTime   - off wait time in 1/10ths of second
******************************************************************************/
void onOffSendOnWithTimedOff(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,Endpoint_t srcEp,
                             uint8_t onOffControl, uint16_t onTime, uint16_t offWaitTime);

/**************************************************************************//**
\brief Sends the Configure Reporting for onOff cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
\param[in] min  - the minimum reporting interval;
\param[in] max  - the maximum reporting interval
******************************************************************************/
void onOffConfigureReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,Endpoint_t srcEp,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max);

/**************************************************************************//**
\brief Checks, if device is in On state

\return True, if device is in On state; false - otherwise.
******************************************************************************/
bool deviceIsOn(void);

#endif // _DSONOFFCLUSTER_H

// eof dsOnOffCluster.h

