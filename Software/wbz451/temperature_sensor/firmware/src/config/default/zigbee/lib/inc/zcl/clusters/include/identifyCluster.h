/*******************************************************************************
  Identify cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    identifyCluster.h

  Summary:
    Identify cluster interface.

  Description:
    This file contains Identify cluster interface.
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


#ifndef _IDENTIFYCLUSTER_H
#define _IDENTIFYCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/zclZllIdentifyCluster.h>

/******************************************************************************
                   Definition(s) section
******************************************************************************/
#define RAISE_CALLBACKS_TO_IDENTIFY_SUBSCIBERS(queue, callback) \
  for (IdentifySubscriber_t *subscriber = getQueueElem(&queue); subscriber; subscriber = getNextQueueElem(subscriber)) \
    if (subscriber->callback) \
      subscriber->callback(addressing, payload);

/******************************************************************************
                    External variables section
******************************************************************************/
extern QueueDescriptor_t identifySubscribers;

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  struct
  {
    void *next;
  } service;

  void (*identify)(ZCL_Addressing_t *addressing, ZCL_Identify_t *payload);
  void (*identifyQuery)(ZCL_Addressing_t *addressing, uint8_t *payload);
  void (*identifyQueryResponse)(ZCL_Addressing_t *addressing, ZCL_IdentifyQueryResponse_t *payload);
} IdentifySubscriber_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Stops Identify cluster
******************************************************************************/
void identifyClusterStop(HAL_AppTimer_t* identifyTimer);

/**************************************************************************//**
\brief Send Identify Query command unicastly

\param[in] nwkState         - new netwrok state;
\param[in] operationalState - new operational state
******************************************************************************/
//void identifyUpdateCommissioningState(bool nwkState, bool operationalState);

/**************************************************************************//**
\brief Adds record to a list of subscribers

\param[in] subscriber - pointer to subscriber;
******************************************************************************/
void identifySubscribe(IdentifySubscriber_t *subscriber);

/**************************************************************************//**
\brief Sends Identify command

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint
******************************************************************************/
void identifySendIdentifyQuery(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
\brief Sends Identify request

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] time - identify time
******************************************************************************/
void identifySendTriggerEffect(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint8_t effectId, uint8_t effectVariant);

/**************************************************************************//**
\brief Makes device to start identify itself

\param[in] time - identifying time in seconds
******************************************************************************/
void idetifyStartIdentifyingCb(uint16_t time, void (*cb)(void));

/**************************************************************************//**
\brief Resets subscribers queue
******************************************************************************/
void idenityResetSubscribers(void);

/**************************************************************************//**
\brief send Identify QueryResponse cmd
******************************************************************************/
ZCL_Status_t sendIdentifyQueryResponse(ZCL_Addressing_t *addressing, Endpoint_t srcEp, uint16_t identifyTime);

/**************************************************************************//**
\brief send Identify cmd
******************************************************************************/
void identifySendIdentify(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t time);


#endif // _IDENTIFYCLUSTER_H

// eof identifyCluster.h

