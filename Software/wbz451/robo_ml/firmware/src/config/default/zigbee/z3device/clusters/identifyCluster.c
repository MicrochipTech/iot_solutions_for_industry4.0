/*******************************************************************************
  Identify Cluster Source file

  Company:
    Microchip Technology Inc.

  File Name:
    identifyCluster.c

  Summary:
    This file contains Identify Cluster Implementation.

  Description:
    This file contains Identify Cluster Implementation.
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
#include <zcl/clusters/include/identifyCluster.h>
#include <zcl/include/zclCommandManager.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/z3Device.h>
//#include <leds.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define IDENTIFY_TIMER_PERIOD 1000u

/******************************************************************************
                    Global variables section
******************************************************************************/
DECLARE_QUEUE(identifySubscribers);

/******************************************************************************
                    Prototypes section
******************************************************************************/
static void fillIdentifyQueryResponsePayload(ZCL_IdentifyQueryResponse_t *payload, uint16_t time);
static void fillTriggerEffectPayload(ZCL_TriggerEffect_t *payload, uint8_t effectIdentifier, uint8_t effectVariant);
static void fillIdentifyPayload(ZCL_Identify_t *payload, uint16_t time);

/**************************************************************************//**
\brief Adds record to a list of subscribers

\param[in] subscriber - pointer to subscriber;
******************************************************************************/
void identifySubscribe(IdentifySubscriber_t *subscriber)
{
  if (!isQueueElem(&identifySubscribers, subscriber))
    if(!putQueueElem(&identifySubscribers, subscriber))
    {
      /* failed to queue */
    }
}

/**************************************************************************//**
\brief Identify reset subscribers queue
******************************************************************************/
void idenityResetSubscribers()
{
  resetQueue(&identifySubscribers);
}

/**CHNANGE - Add SrcEp inteh function header in all file wherever it isi required*/
/**************************************************************************//**
\brief Sends Identify request

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp- source endpoint;
\param[in] time - identify time
******************************************************************************/
void identifySendIdentify(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,  Endpoint_t srcEp,
  uint16_t time)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_IDENTIFY_CLUSTER_IDENTIFY_COMMAND_ID, sizeof(ZCL_Identify_t), srcEp);
  fillIdentifyPayload((ZCL_Identify_t *)req->requestPayload, time);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, IDENTIFY_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Fills Identify command structure

\param[out] payload - pointer to command structure;
\param[in]  time    - identify time
******************************************************************************/
static void fillIdentifyPayload(ZCL_Identify_t *payload, uint16_t time)
{
  payload->identifyTime = time;
}

/**************************************************************************//**
\brief Sends Identify TriggerEffect request

\param[in] mode     - address mode;
\param[in] addr     - short address of destination node;
\param[in] ep       - destination endpoint;
\param[in] srcEp    - source endpoint;
\param[in] effectId - Effect Id
\param[in] effectId - Effect varient
******************************************************************************/
void identifySendTriggerEffect(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t effectId, uint8_t effectVariant)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_IDENTIFY_CLUSTER_TRIGGER_EFFECT_COMMAND_ID, sizeof(ZCL_TriggerEffect_t), srcEp);
  fillTriggerEffectPayload((ZCL_TriggerEffect_t *)req->requestPayload, effectId, effectVariant);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, IDENTIFY_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Fills Trigger Effect command structure

\param[out] payload - pointer to command structure;
\param[in] effectIdentifier - effect identifier value
\param[in] effectVariant    - effect variant value
******************************************************************************/
static void fillTriggerEffectPayload(ZCL_TriggerEffect_t *payload, uint8_t effectIdentifier, uint8_t effectVariant)
{
  payload->effectIdentifier = effectIdentifier;
  payload->effectVariant    = effectVariant;
}
/**************************************************************************//**
\brief Sends Identify Query request

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node;
\param[in] ep    - destination endpoint;
\param[in] srcEp - source endpoint;
******************************************************************************/
void identifySendIdentifyQuery(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep,  Endpoint_t srcEp)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_COMMAND_ID, 0, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, IDENTIFY_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Identidy Query Response command

\param[in] addressing - addressing information about sender device
\param[in] srcEp          - source endpoint;
\param[in] identifyTime   - identifyTime;

\returns status of sending
******************************************************************************/
ZCL_Status_t sendIdentifyQueryResponse(ZCL_Addressing_t *addressing, Endpoint_t srcEp, uint16_t identifyTime)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return ZCL_INSUFFICIENT_SPACE_STATUS;

  fillCommandRequest(req, ZCL_IDENTIFY_CLUSTER_IDENTIFY_QUERY_RESPONSE_COMMAND_ID,
                     sizeof(ZCL_IdentifyQueryResponse_t), srcEp);
  /* to be done based on the endpoint */
  fillIdentifyQueryResponsePayload((ZCL_IdentifyQueryResponse_t *)req->requestPayload, identifyTime);
  fillDstAddressingViaSourceAddressing(&req->dstAddressing, addressing, ZCL_CLUSTER_SIDE_CLIENT);
  ZCL_CommandManagerSendCommand(req);

  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Fills Identify Query Response command structure

\param[out] payload - pointer to command structure;
\param[in]  time    - identify time
******************************************************************************/
static void fillIdentifyQueryResponsePayload(ZCL_IdentifyQueryResponse_t *payload, uint16_t time)
{
  payload->timeout = time;
}

/**CHANGE - Check LED behaviour and need to be corrected if required */
/**************************************************************************//**
\brief Makes device to start identify itself

\param[in] time - identifying time in seconds
******************************************************************************/
void idetifyStartIdentifyingCb(uint16_t time, void (*cb)(void))
{
  for (int8_t i = 0;i < APP_ENDPOINTS_AMOUNT;i++)
    deviceBindReqs[i]->startIdentifyingFn(time, cb);
}

//eof identifyCluster.c
