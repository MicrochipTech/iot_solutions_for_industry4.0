/*******************************************************************************
  Level Control Cluster source File

  Company:
    Microchip Technology Inc.

  File Name:
    levelControlCluster.c

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


/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/zclZllLevelControlCluster.h>
#if defined(BOARD_MEGARF) || defined(BOARD_SAMR21)
#include <ledsExt.h>
#include <lcdExt.h>
#endif
#include <zcl/include/zclCommandManager.h>
#include <z3device/clusters/include/haClusters.h>
#include <z3device/common/include/z3Device.h>
#include <z3device/clusters/include/onOffCluster.h>
#include <app_zigbee/zigbee_console/console.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
static void fillMoveToLevelPayload(ZCL_MoveToLevelWithOptions_t *payload, uint8_t level, uint16_t time,
                                   uint8_t optionsMask, uint8_t optionsOverride);
static void fillMovePayload(ZCL_MoveWithOptions_t *payload, uint8_t mode, uint8_t rate,
                            uint8_t optionsMask, uint8_t optionsOverride);
static void fillStepPayload(ZCL_StepWithOptions_t *payload, uint8_t mode, uint8_t size, uint16_t time,
                            uint8_t optionsMask, uint8_t optionsOverride);
#if APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_DIMMABLE_LIGHT
/**************************************************************************//**
\brief Display current level value.
******************************************************************************/
void levelControlDisplayLevel(uint8_t level)
{
  LCD_PRINT(2, 0, "%3d", level);
#if (ZB_COMMISSIONING_ON_STARTUP == 1 && APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_DIMMABLE_LIGHT)
  {
    appSnprintf("Current level value: %3d\r\n", level);
  }
#endif //ZB_COMMISSIONING_ON_STARTUP == 1

  LEDS_SET_BRIGHTNESS(level);
  (void)level;
}
#endif
/**************************************************************************//**
\brief Sends Move To Level or Move To Level with On/Off command
  to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] srcEp           - source endpoint;
\param[in] level           - color level;
\param[in] time            - transition time in 1/10 of second;
\param[in] onOff           - if true then Move To Level with On/Off command is sent,
  otherwise Move To Level command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendMoveToLevel(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t level, uint16_t time, bool onOff, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize = sizeof(ZCL_MoveToLevelWithOptions_t);
  uint8_t command = onOff ? ZCL_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_W_ONOFF_COMMAND_ID :
    ZCL_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_COMMAND_ID;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, command, cmdSize, srcEp);

  
  fillMoveToLevelPayload((ZCL_MoveToLevelWithOptions_t *)req->requestPayload, level, time, optionsMask, optionsOverride);

  fillDstAddressing(&req->dstAddressing, mode, addr, ep, LEVEL_CONTROL_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Move or Move with On/Off command to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] srcEp           - source endpoint;
\param[in] moveMode        - mode mode;
\param[in] rate            - move rate;
\param[in] onOff           - if true then Move with On/Off command is sent,
  otherwise Move command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendMove(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t moveMode, uint8_t rate, bool onOff, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize = sizeof(ZCL_MoveWithOptions_t);
  uint8_t command = onOff ? ZCL_LEVEL_CONTROL_CLUSTER_MOVE_W_ONOFF_COMMAND_ID :
    ZCL_LEVEL_CONTROL_CLUSTER_MOVE_COMMAND_ID;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, command, cmdSize, srcEp);
  
  fillMovePayload((ZCL_MoveWithOptions_t *)req->requestPayload, moveMode, rate,
                    optionsMask, optionsOverride);

  fillDstAddressing(&req->dstAddressing, mode, addr, ep, LEVEL_CONTROL_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Step or Step with On/Off command to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] srcEp           - source endpoint;
\param[in] stepMode        - step mode;
\param[in] size            - step size;
\param[in] time            - transition time;
\param[in] onOff           - if true then Step with On/Off command is sent,
  otherwise Step command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendStep(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t stepMode, uint8_t size, uint16_t time, bool onOff, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize = sizeof(ZCL_StepWithOptions_t);
  uint8_t command = onOff ? ZCL_LEVEL_CONTROL_CLUSTER_STEP_W_ONOFF_COMMAND_ID :
    ZCL_LEVEL_CONTROL_CLUSTER_STEP_COMMAND_ID;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, command, cmdSize, srcEp);
  
  fillStepPayload((ZCL_StepWithOptions_t *)req->requestPayload, stepMode, size, time,
                  optionsMask, optionsOverride);

  fillDstAddressing(&req->dstAddressing, mode, addr, ep, LEVEL_CONTROL_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Stop or Stop with On/Off command to bound devices

\param[in] mode            - address mode;
\param[in] addr            - short address of destination node or number of group;
\param[in] ep              - endpoint number of destination device;
\param[in] srcEp           - source endpoint;
\param[in] onOff           - if true then Stop with On/Off command is sent,
  otherwise Stop command is sent
\param[in] optionsMask     - options mask
\param[in] optionsOverride - options override
******************************************************************************/
void levelControlSendStop(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  bool onOff, uint8_t optionsMask, uint8_t optionsOverride)
{
  ZCL_Request_t *req;
  uint8_t cmdSize = 0;
  uint8_t command = onOff ? ZCL_LEVEL_CONTROL_CLUSTER_STOP_W_ONOFF_COMMAND_ID :
    ZCL_LEVEL_CONTROL_CLUSTER_STOP_COMMAND_ID;
    
  ZCL_StopWithOptions_t *cmd;

  if (!(req = getFreeCommand()))
    return;

  cmdSize = sizeof(ZCL_StopWithOptions_t);

  fillCommandRequest(req, command, cmdSize, srcEp);
  
  cmd = (ZCL_StopWithOptions_t *)req->requestPayload;
  cmd->optionsMask = optionsMask;
  cmd->optionsOverride = optionsOverride;
   
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, LEVEL_CONTROL_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Fills Move To Level command structure

\param[out] payload - pointer to command structure;
\param[in]  level   - color level;
\param[in]  time    - transition time
******************************************************************************/
static void fillMoveToLevelPayload(ZCL_MoveToLevelWithOptions_t *payload, uint8_t level, uint16_t time,
                                   uint8_t optionsMask, uint8_t optionsOverride)
{
  payload->level          = level;
  payload->transitionTime = time;
  payload->optionsMask  = optionsMask;
  payload->optionsOverride = optionsOverride;
}
/**************************************************************************//**
\brief Fills Move command structure

\param[out] payload - pointer to command structure;
\param[in]  mode    - move mode;
\param[in]  rate    - move rate
******************************************************************************/
static void fillMovePayload(ZCL_MoveWithOptions_t *payload, uint8_t mode, uint8_t rate,
                            uint8_t optionsMask, uint8_t optionsOverride)
{  
  payload->moveMode = mode;
  payload->rate     = rate;
  payload->optionsMask  = optionsMask;
  payload->optionsOverride = optionsOverride;

}
/**************************************************************************//**
\brief Fills Step command structure

\param[out] payload - pointer to command structure;
\param[in]  mode    - move mode;
\param[in]  size    - step size;
\param[in]  time    - transition time
******************************************************************************/
static void fillStepPayload(ZCL_StepWithOptions_t *payload, uint8_t mode, uint8_t size, uint16_t time,
                            uint8_t optionsMask, uint8_t optionsOverride)
{
 
  payload->stepMode       = mode;
  payload->stepSize       = size;
  payload->transitionTime = time;  
  payload->optionsMask  = optionsMask;
  payload->optionsOverride = optionsOverride;

}
