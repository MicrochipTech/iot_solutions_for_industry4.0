/*******************************************************************************
  Level Control Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    levelControlCluster.h

  Summary:
    This file contains Level Control Cluster Implemenation.

  Description:
    This file contains Level Control Cluster Implemenation.
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

#ifndef _LEVELCONTROLCLUSTER_H
#define _LEVELCONTROLCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/zclZllLevelControlCluster.h>


/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Display current level value.
******************************************************************************/
void levelControlDisplayLevel(uint8_t level);

/**************************************************************************//**
\brief Sends Move To Level or Move To Level with On/Off command
  to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] level           - color level;
\param[in] time            - transition time in 1/10 of second;
\param[in] onOff           - if true then Move To Level with On/Off command is sent,
  otherwise Move To Level command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendMoveToLevel(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t level, uint16_t time, bool onOff, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends Move or Move with On/Off command to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] moveMode        - mode mode;
\param[in] rate            - move rate;
\param[in] onOff           - if true then Move with On/Off command is sent,
  otherwise Move command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendMove(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t moveMode, uint8_t rate, bool onOff, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends Step or Step with On/Off command to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] stepMode        - step mode;
\param[in] size            - step size;
\param[in] time            - transition time;
\param[in] onOff           - if true then Step with On/Off command is sent,
  otherwise Step command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendStep(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t stepMode, uint8_t size, uint16_t time, bool onOff, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends Stop or Stop with On/Off command to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] onOff           - if true then Stop with On/Off command is sent,
  otherwise Stop command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendStop(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  bool onOff, uint8_t optionsMask, uint8_t optionsOverride);

#endif //_LEVELCONTROLCLUSTER_H

