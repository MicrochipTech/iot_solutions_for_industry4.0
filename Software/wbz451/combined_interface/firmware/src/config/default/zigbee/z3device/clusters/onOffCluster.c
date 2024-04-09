/*******************************************************************************
  On Off Cluster source File

  Company:
    Microchip Technology Inc.

  File Name:
    onOffCluster.c

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


/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/clusters/include/onOffCluster.h>
#include <zcl/include/zclCommandManager.h>


/******************************************************************************
                    Prototypes section
******************************************************************************/
static void fillOffWithEffectPayload(ZCL_OffWithEffect_t *payload,
                                       uint8_t effectId, uint8_t effectVariant);

static void fillOnWithTimedOffPayload(ZCL_OnWithTimedOff_t *payload,
                                       uint8_t onOffControl, uint16_t onTime,
                                       uint16_t offWaitTime);

/**************************************************************************//**
\brief Sends On, Off or Toggle command to bound devices

\param[in] mode    - address mode;
\param[in] addr    - short address of destination node or number of group;
\param[in] ep      - endpoint number of destination device;
\param[in] srcEp   - source endpoint;
\param[in] command - command id
******************************************************************************/
void onOffSendOnOffToggle(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,  Endpoint_t srcEp, OnOffToggle_t command)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, command, 0, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, ONOFF_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Fills OffWithEffect command structure

\param[out] payload - pointer to command structure;
\param[in] effectIdentifier - effect identifier value
\param[in] effectVariant    - effect variant value
******************************************************************************/
static void fillOffWithEffectPayload(ZCL_OffWithEffect_t *payload,
                                       uint8_t effectId, uint8_t effectVariant)
{
  payload->effectIdentifier = effectId;
  payload->effectVariant = effectVariant;
}

/**************************************************************************//**
\brief Sends OffWithEffect command to bound devices

\param[in] mode          - address mode;
\param[in] addr          - short address of destination node or number of group;
\param[in] ep            - endpoint number of destination device;
\param[in] srcEp         - source endpoint;
\param[in] effectId      - effect identifier;
\param[in] effectVariant - effect variant;
******************************************************************************/
void onOffSendOffWithEffect(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
                           uint8_t effectId, uint8_t effectVariant)
{
  ZCL_Request_t *req = getFreeCommand();

  if (NULL == req)
    return;

  fillCommandRequest(req, ZCL_ONOFF_CLUSTER_OFF_WITH_EFFECT_COMMAND_ID, sizeof(ZCL_OffWithEffect_t), srcEp);
  fillOffWithEffectPayload((ZCL_OffWithEffect_t *)req->requestPayload, effectId, effectVariant);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, ONOFF_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Fills On With Timed Off command structure

\param[out] payload - pointer to command structure;
\param[in] onOffControl - on off control value;
\param[in] onTime - on time value;
\param[in] offWaitTime - off wait time value;
******************************************************************************/
static void fillOnWithTimedOffPayload(ZCL_OnWithTimedOff_t *payload,
                                       uint8_t onOffControl, uint16_t onTime,
                                       uint16_t offWaitTime)
{
  payload->onOffControl = onOffControl;
  payload->onTime       = onTime;
  payload->offWaitTime  = offWaitTime;
}

/**************************************************************************//**
\brief Sends OnWithTimedOff command to bound devices

\param[in] mode          - address mode;
\param[in] addr          - short address of destination node or number of group;
\param[in] ep            - endpoint number of destination device;
\param[in] srcEp         - source endpoint;
\param[in] onOffControl  - on/off control
\param[in] onTime        - on time in 1/10ths of second
\param[in] offWaitTime   - off wait time in 1/10ths of second
******************************************************************************/
void onOffSendOnWithTimedOff(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
                             uint8_t onOffControl, uint16_t onTime, uint16_t offWaitTime)
{
  ZCL_Request_t *req = getFreeCommand();

  if (NULL == req)
    return;

  fillCommandRequest(req, ZCL_ONOFF_CLUSTER_ON_WITH_TIMED_OFF_COMMAND_ID, sizeof(ZCL_OnWithTimedOff_t), srcEp);
  fillOnWithTimedOffPayload((ZCL_OnWithTimedOff_t *)req->requestPayload, onOffControl, onTime, offWaitTime);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, ONOFF_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends OnWithRecallGlobalScene command to bound devices

\param[in] mode          - address mode;
\param[in] addr          - short address of destination node or number of group;
\param[in] ep            - endpoint number of destination device;
\param[in] srcEp         - source endpoint;
******************************************************************************/
void onOffSendOnWithRecallGlobalScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp)
{
  ZCL_Request_t *req = getFreeCommand();

  if (NULL == req)
    return;

  fillCommandRequest(req, ZCL_ONOFF_CLUSTER_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID, 0, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, ONOFF_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
//eof onOffCluster.c
