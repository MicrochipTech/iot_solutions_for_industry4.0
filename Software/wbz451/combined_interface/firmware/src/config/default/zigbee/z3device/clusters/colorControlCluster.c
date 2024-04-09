/*******************************************************************************
  Color Control Cluster source File

  Company:
    Microchip Technology Inc.

  File Name:
    colorControlCluster.c

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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <zcl/include/zclZllColorControlCluster.h>
#include <z3device/clusters/include/colorControlCluster.h>
#include <zcl/include/zclCommandManager.h>

/******************************************************************************
                    Implementation section
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
  uint8_t hue, uint8_t direction, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveToHueCommand_t *cmd;
  ZCL_ZllMoveToHueWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveToHueWithOptionsCommand_t) : sizeof(ZCL_ZllMoveToHueCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_TO_HUE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveToHueCommand_t *)req->requestPayload;
  cmd->hue = hue;
  cmd->direction = direction;
  cmd->transitionTime = transitionTime;

  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveToHueWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t moveMode, uint8_t rate, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveHueCommand_t *cmd;
  ZCL_ZllMoveHueWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveHueWithOptionsCommand_t) : sizeof(ZCL_ZllMoveHueCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_HUE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveHueCommand_t *)req->requestPayload;
  cmd->moveMode = moveMode;
  cmd->rate = rate;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveHueWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t stepMode, uint8_t stepSize, uint8_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllStepHueCommand_t *cmd;
  ZCL_ZllStepHueWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllStepHueWithOptionsCommand_t) : sizeof(ZCL_ZllStepHueCommand_t);
  // fill command request
  fillCommandRequest(req, STEP_HUE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllStepHueCommand_t *)req->requestPayload;
  cmd->stepMode = stepMode;
  cmd->stepSize = stepSize;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllStepHueWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t saturation, uint16_t transitionTime,  uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveToSaturationCommand_t *cmd;
  ZCL_ZllMoveToSaturationWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveToSaturationWithOptionsCommand_t) : sizeof(ZCL_ZllMoveToSaturationCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_TO_SATURATION_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveToSaturationCommand_t *)req->requestPayload;
  cmd->saturation = saturation;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveToSaturationWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t moveMode, uint8_t rate, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveSaturationCommand_t *cmd;
  ZCL_ZllMoveSaturationWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllStepSaturationWithOptionsCommand_t) : sizeof(ZCL_ZllStepSaturationCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_SATURATION_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveSaturationCommand_t *)req->requestPayload;
  cmd->moveMode = moveMode;
  cmd->rate = rate;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveSaturationWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t stepMode, uint8_t stepSize, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllStepSaturationCommand_t *cmd;
  ZCL_ZllStepSaturationWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllStepSaturationWithOptionsCommand_t) : sizeof(ZCL_ZllStepSaturationCommand_t);
  // fill command request
  fillCommandRequest(req, STEP_SATURATION_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllStepSaturationCommand_t *)req->requestPayload;
  cmd->stepMode = stepMode;
  cmd->stepSize = stepSize;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllStepSaturationWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t hue, uint8_t saturation, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveToHueAndSaturationCommand_t *cmd;
  ZCL_ZllMoveToHueAndSaturationWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveToHueAndSaturationWithOptionsCommand_t) : sizeof(ZCL_ZllMoveToHueAndSaturationCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_TO_HUE_AND_SATURATION_COMMAND_ID, cmdSize, srcEp);
  
  // fill command payload
  cmd = (ZCL_ZllMoveToHueAndSaturationCommand_t *)req->requestPayload;
  cmd->hue = hue;
  cmd->saturation = saturation;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveToHueAndSaturationWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint16_t colorX, uint16_t colorY, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveToColorCommand_t *cmd;
  ZCL_ZllMoveToColorWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveToColorWithOptionsCommand_t) : sizeof(ZCL_ZllMoveToColorCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_TO_COLOR_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveToColorCommand_t *)req->requestPayload;
  cmd->colorX = colorX;
  cmd->colorY = colorY;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveToColorWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  int16_t rateX, int16_t rateY, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveColorCommand_t *cmd;
  ZCL_ZllMoveColorWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveColorWithOptionsCommand_t) : sizeof(ZCL_ZllMoveColorCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_COLOR_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveColorCommand_t *)req->requestPayload;
  cmd->rateX = rateX;
  cmd->rateY = rateY;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveColorWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
void colorControlSendMoveToColorTemperatureCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t colorTemperature, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveToColorTemperatureCommand_t *cmd;
  ZCL_ZllMoveToColorTemperatureWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveToColorTemperatureWithOptionsCommand_t) : sizeof(ZCL_ZllMoveToColorTemperatureCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_TO_COLOR_TEMPERATURE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveToColorTemperatureCommand_t *)req->requestPayload;
  cmd->colorTemperature = colorTemperature;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveToColorTemperatureWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
void colorControlSendStepColorCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  int16_t stepX, int16_t stepY, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllStepColorCommand_t *cmd;
  ZCL_ZllStepColorWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllStepColorWithOptionsCommand_t) : sizeof(ZCL_ZllStepColorCommand_t);
  // fill command request
  fillCommandRequest(req, STEP_COLOR_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllStepColorCommand_t *)req->requestPayload;
  cmd->stepX = stepX;
  cmd->stepY = stepY;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllStepColorWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint16_t enhancedHue, uint8_t direction, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllEnhancedMoveToHueCommand_t *cmd;
  ZCL_ZllEnhancedMoveToHueWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllEnhancedMoveToHueWithOptionsCommand_t) : sizeof(ZCL_ZllEnhancedMoveToHueCommand_t);
  // fill command request
  fillCommandRequest(req, ENHANCED_MOVE_TO_HUE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllEnhancedMoveToHueCommand_t *)req->requestPayload;
  cmd->enhancedHue = enhancedHue;
  cmd->direction = direction;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllEnhancedMoveToHueWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t moveMode, uint16_t rate, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllEnhancedMoveHueCommand_t *cmd;
  ZCL_ZllEnhancedMoveHueWithOptionsCommand_t *cmdWithOptions;
  
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllEnhancedMoveHueWithOptionsCommand_t) : sizeof(ZCL_ZllEnhancedMoveHueCommand_t);
  // fill command request
  fillCommandRequest(req, ENHANCED_MOVE_HUE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllEnhancedMoveHueCommand_t *)req->requestPayload;
  cmd->moveMode = moveMode;
  cmd->rate = rate;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllEnhancedMoveHueWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint8_t stepMode, uint16_t stepSize, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllEnhancedStepHueCommand_t *cmd;
  ZCL_ZllEnhancedStepHueWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllEnhancedStepHueWithOptionsCommand_t) : sizeof(ZCL_ZllEnhancedStepHueCommand_t);
  // fill command request
  fillCommandRequest(req, ENHANCED_STEP_HUE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllEnhancedStepHueCommand_t *)req->requestPayload;
  cmd->stepMode = stepMode;
  cmd->stepSize = stepSize;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllEnhancedStepHueWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint16_t enhancedHue, uint8_t saturation, uint16_t transitionTime, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t *cmd;
  ZCL_ZllEnhancedMoveToHueAndSaturationWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllEnhancedMoveToHueAndSaturationWithOptionsCommand_t) : sizeof(ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t);
  // fill command request
  fillCommandRequest(req, ENHANCED_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t *)req->requestPayload;
  cmd->enhancedHue = enhancedHue;
  cmd->saturation = saturation;
  cmd->transitionTime = transitionTime;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllEnhancedMoveToHueAndSaturationWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint16_t time, uint16_t startHue, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllColorLoopSetCommand_t *cmd;
  ZCL_ZllColorLoopSetWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllColorLoopSetWithOptionsCommand_t) : sizeof(ZCL_ZllColorLoopSetCommand_t);
  // fill command request
  fillCommandRequest(req, COLOR_LOOP_SET_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllColorLoopSetCommand_t *)req->requestPayload;
  cmd->updateFlags = updateFlags;
  cmd->action = (ZCL_ZllColorLoopAction_t) action;
  cmd->direction = direction;
  cmd->time = time;
  cmd->startHue = startHue;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllColorLoopSetWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint16_t colorTemperatureMaximum, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllMoveColorTemperatureCommand_t *cmd;
  ZCL_ZllMoveColorTemperatureWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllMoveColorTemperatureWithOptionsCommand_t) : sizeof(ZCL_ZllMoveColorTemperatureCommand_t);
  // fill command request
  fillCommandRequest(req, MOVE_COLOR_TEMPERATURE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllMoveColorTemperatureCommand_t *)req->requestPayload;
  cmd->moveMode = moveMode;
  cmd->rate = rate;
  cmd->colorTemperatureMinimum = colorTemperatureMinimum;
  cmd->colorTemperatureMaximum = colorTemperatureMaximum;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllMoveColorTemperatureWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
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
  uint16_t colorTemperatureMinimum,uint16_t colorTemperatureMaximum, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllStepColorTemperatureCommand_t *cmd;
  ZCL_ZllStepColorTemperatureWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllStepColorTemperatureWithOptionsCommand_t) : sizeof(ZCL_ZllStepColorTemperatureCommand_t);
  // fill command request
  fillCommandRequest(req, STEP_COLOR_TEMPERATURE_COMMAND_ID, cmdSize, srcEp);

  // fill command payload
  cmd = (ZCL_ZllStepColorTemperatureCommand_t *)req->requestPayload;
  cmd->stepMode = stepMode;
  cmd->stepSize = stepSize;
  cmd->transitionTime = transitionTime;
  cmd->colorTemperatureMinimum = colorTemperatureMinimum;
  cmd->colorTemperatureMaximum = colorTemperatureMaximum;
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllStepColorTemperatureWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Stop Move Step command

\param[in] mode                     - address mode;
\param[in] addr                     - short address of destination node or number of group;
\param[in] ep                       - endpoint number of destination device;
\param[in] srcEp                    - endpoint number of source device;
\param[in] optionsMask              - optionsMask;
\param[in] optionsOverride          - optionsOverride;
******************************************************************************/
void colorControlSendStopMoveStepCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize;
  ZCL_ZllStopMoveStepWithOptionsCommand_t *cmdWithOptions;
  if (!(req = getFreeCommand()))
  {
    return;
  }
  cmdSize = optionsMask ? sizeof(ZCL_ZllStopMoveStepWithOptionsCommand_t) : 0; 
  // fill command request
  fillCommandRequest(req, STOP_MOVE_STEP_COMMAND_ID, cmdSize, srcEp);
  
  // fill command payload (if optional fields are given)
  if (optionsMask)
  {
    cmdWithOptions = (ZCL_ZllStopMoveStepWithOptionsCommand_t *)req->requestPayload;
    cmdWithOptions->optionsMask = optionsMask;    
    cmdWithOptions->optionsOverride = optionsOverride;    
  }
  
  // fill destination addressing
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, COLOR_CONTROL_CLUSTER_ID);
  
  ZCL_CommandManagerSendCommand(req);
}
