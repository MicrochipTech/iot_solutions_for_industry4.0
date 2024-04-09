/*******************************************************************************
  Color Control Cluster header File

  Company:
    Microchip Technology Inc.

  File Name:
    colorControlCluster.h

  Summary:
    This file contains Color Control Cluster Implemenation.

  Description:
    This file contains Color Control Cluster Implemenation.
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

#ifndef _COLORCONTROLCLUSTER_H
#define _COLORCONTROLCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclZllColorControlCluster.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Sends move to hue command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] hue            - hue;
\param[in] direction      - direction;
\param[in] transitionTime - transitionTime;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveToHueCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t hue, uint8_t direction, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move hue command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] moveMode       - moveMode;
\param[in] rate           - rate;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveHueCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t moveMode, uint8_t rate, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends step hue command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] stepMode       - stepMode;
\param[in] stepSize       - stepSize;
\param[in] transitionTime - transitionTime;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendStepHueCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t stepMode, uint8_t stepSize, uint8_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move to saturation command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] saturation     - saturation;
\param[in] transitionTime - transitionTime;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveToSaturationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t saturation, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move saturation command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] moveMode       - moveMode;
\param[in] rate           - rate;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveSaturationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t moveMode, uint8_t rate, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends step saturation command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] stepMode       - stepMode;
\param[in] stepSize       - stepSize;
\param[in] transitionTime - transitionTime;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendStepSaturationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t stepMode, uint8_t stepSize, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move to hue and saturation command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] hue            - hue;
\param[in] saturation     - saturation;
\param[in] transitionTime - transitionTime;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveToHueAndSaturationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t hue,uint8_t saturation,uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move to color command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] colorX         - colorX;
\param[in] colorY         - colorY;
\param[in] transitionTime - transitionTime;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveToColorCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t colorX,uint16_t colorY,uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move color command

\param[in] mode           - address mode;
\param[in] addr           - short address of destination node or number of group;
\param[in] ep             - endpoint number of destination device;
\param[in] srcEp          - endpoint number of source device;
\param[in] rateX          - rateX;
\param[in] rateY          - rateY;
\param[in] optionsMask    - optionsMask;
\param[in] optionsOverride- optionsOverride;
******************************************************************************/
void colorControlSendMoveColorCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  int16_t rateX,int16_t rateY, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move to color temperature command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] colorTemperature - colorTemperature;
\param[in] transitionTime   - transitionTime;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendStepColorCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  int16_t stepX, int16_t stepY, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends step color command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] colorX           - colorX;
\param[in] colorY           - colorY;
\param[in] transitionTime   - transitionTime;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendMoveToColorTemperatureCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t colorTemperature,uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends enhanced move to hue command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] enhancedHue      - enhancedHue;
\param[in] direction        - direction;
\param[in] transitionTime   - transitionTime;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendEnhancedMoveToHueCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t enhancedHue, uint8_t direction, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends enhanced move hue command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] moveMode         - moveMode;
\param[in] rate             - rate;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendEnhancedMoveHueCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t moveMode, uint16_t rate, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends enhanced step hue command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] stepMode         - stepMode;
\param[in] stepSize         - stepSize;
\param[in] transitionTime   - transitionTime;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendEnhancedStepHueCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t stepMode, uint16_t stepSize, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends enhanced move to hue and saturation command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] enhancedHue      - enhancedHue;
\param[in] saturation       - saturation;
\param[in] transitionTime   - transitionTime;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendEnhancedMoveToHueAndSaturationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t enhancedHue, uint8_t saturation, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends color loop set command

\param[in] mode             - address mode;
\param[in] addr             - short address of destination node or number of group;
\param[in] ep               - endpoint number of destination device;
\param[in] srcEp            - endpoint number of source device;
\param[in] updateFlags      - update Flags;
\param[in] action           - action;
\param[in] direction        - direction;
\param[in] time             - transitionTime;
\param[in] startHue         - start Hue;
\param[in] optionsMask      - optionsMask;
\param[in] optionsOverride  - optionsOverride;
******************************************************************************/
void colorControlSendColorLoopSetCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t updateFlags, uint8_t action, uint8_t direction,
  uint16_t time, uint16_t startHue, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends move color temperature command

\param[in] mode                     - address mode;
\param[in] addr                     - short address of destination node or number of group;
\param[in] ep                       - endpoint number of destination device;
\param[in] srcEp                    - endpoint number of source device;
\param[in] moveMode                 - move Mode;
\param[in] rate                     - rate;
\param[in] colorTemperatureMinimum  - colorTemperatureMinimum;
\param[in] colorTemperatureMaximum  - colorTemperatureMaximum;
\param[in] optionsMask              - optionsMask;
\param[in] optionsOverride          - optionsOverride;
******************************************************************************/
void colorControlSendMoveColorTemperatureCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t moveMode,uint16_t rate,uint16_t colorTemperatureMinimum,
  uint16_t colorTemperatureMaximum, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends step color temperature command

\param[in] mode                     - address mode;
\param[in] addr                     - short address of destination node or number of group;
\param[in] ep                       - endpoint number of destination device;
\param[in] srcEp                    - endpoint number of source device;
\param[in] stepMode                 - step Mode;
\param[in] stepSize                 - step Size;
\param[in] transitionTime           - transition Time;
\param[in] colorTemperatureMinimum  - colorTemperatureMinimum;
\param[in] colorTemperatureMaximum  - colorTemperatureMaximum;
\param[in] optionsMask              - optionsMask;
\param[in] optionsOverride          - optionsOverride;
******************************************************************************/
void colorControlSendStepColorTemperatureCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t  stepMode,uint16_t stepSize,uint16_t transitionTime,
  uint16_t colorTemperatureMinimum,uint16_t colorTemperatureMaximum, uint8_t optionsMask, uint8_t optionsOverride);

/**************************************************************************//**
\brief Sends Stop Move Step command

\param[in] mode                     - address mode;
\param[in] addr                     - short address of destination node or number of group;
\param[in] ep                       - endpoint number of destination device;
\param[in] srcEp                    - endpoint number of source device;
\param[in] optionsMask              - optionsMask;
\param[in] optionsOverride          - optionsOverride;
******************************************************************************/
void colorControlSendStopMoveStepCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t optionsMask, uint8_t optionsOverride);

#endif // _COLORCONTROLCLUSTER_H