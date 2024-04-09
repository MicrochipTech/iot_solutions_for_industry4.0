/*******************************************************************************
  Light-Sensor Identify cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    lsIdentifyCluster.c

  Summary:
    This file contains Light-Sensor Identify cluster interface.

  Description:
    This file contains Light-Sensor Identify cluster interface.
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)
#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/multiSensor/include/lsIdentifyCluster.h>
#include <zcl/clusters/include/identifyCluster.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/zclCommandManager.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/z3Device.h>
#include <zcl/include/zclZllIdentifyCluster.h>
#if defined(BOARD_MEGARF) || defined(BOARD_SAMR21)
#include <ledsExt.h>
#include <lcdExt.h>
#include <leds.h>
#endif
#include <zcl/clusters/include/identifyCluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define IDENTIFY_EFFECT_TIMER_PERIOD  500U // in milliseconds
#define DEFAULT_IDENTIFY_TIME         3U

#define BLINK_IDENTIFY_TIME           1U   // in seconds
#define BREATHE_IDENTIFY_TIME         15U  // in seconds
#define OKAY_IDENTIFY_TIME            2U   // in seconds
#define CHANNEL_CHANGE_IDENTIFY_TIME  8U   // in seconds

#define LED_MAX_BRIGHTNESS            254U
#define LED_MIN_BRIGHTNESS            2U
#define LED_NO_BRIGHTNESS             0U

/******************************************************************************
                    Prototypes section
******************************************************************************/


static void ZCL_LsIdentifyAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);

static ZCL_Status_t identifyInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Identify_t *payload);
static ZCL_Status_t identifyQueryInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
static ZCL_Status_t triggerEffectInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_TriggerEffect_t *payload);
static ZCL_Status_t identifyQueryResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_IdentifyQueryResponse_t *payload);

// some support functions
static void (*identifycb)(void);
static void lsIdentifyFinish(void);

// timer functions
static void identifyEffectTimerFired(void);

/******************************************************************************
                    Global variables section
******************************************************************************/
ZCL_IdentifyClusterServerAttributes_t lsIdentifyClusterServerAttributes =
{
  ZCL_DEFINE_IDENTIFY_CLUSTER_SERVER_ATTRIBUTES()
};

ZCL_IdentifyClusterClientAttributes_t lsIdentifyClusterClientAttributes =
{
  ZCL_DEFINE_IDENTIFY_CLUSTER_CLIENT_ATTRIBUTES()
};
PROGMEM_DECLARE(ZCL_IdentifyClusterCommands_t  lsIdentifyCommands) =
{
  ZCL_IDENTIFY_CLUSTER_COMMANDS(identifyInd, identifyQueryInd, triggerEffectInd, identifyQueryResponseInd)
};

/******************************************************************************
                    Static variables section
******************************************************************************/
static HAL_AppTimer_t identifyEffectTimer;

static struct
{
  bool period        : 1;
  bool finish        : 1;
  bool chChangeEffect: 1;
  bool minTime       : 1;
} identificationStatus;

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Identify cluster
******************************************************************************/
void lsIdentifyClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, IDENTIFY_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
  ZCL_Cluster_t *identifyCluster = ZCL_GetCluster(APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, IDENTIFY_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);
  // All ongoing identification (if any) should be stopped
  lsIdentifyStop();

  // Server attributes init
  lsIdentifyClusterServerAttributes.identifyTime.value = 0;
  lsIdentifyClusterServerAttributes.clusterVersion.value = IDENTIFY_CLUSTER_VERSION;

  if (cluster)
    cluster->ZCL_AttributeEventInd = ZCL_LsIdentifyAttributeEventInd;

  // Client attributes init
  lsIdentifyClusterClientAttributes.clusterVersion.value = IDENTIFY_CLUSTER_VERSION;

  LEDS_SET_COLOR_HS(255,255);
  if (identifyCluster)
    identifyCluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

/******************************************************************************
*                     SOME SUPPORT FUNCTIONS
******************************************************************************/

/**************************************************************************//**
\brief Makes device to start identify itself

\param[in] time - identifying time in seconds
******************************************************************************/
void lsIdetifyStartIdentifyingCb(uint16_t time, void (*cb)(void))
{
  lsIdentifyClusterServerAttributes.identifyTime.value = time;
  identifycb = cb;

  lsIdentifyStart(lsIdentifyClusterServerAttributes.identifyTime.value);
}

/******************************************************************************
*                 IDENTIFICATION and TRIGGER EFFECT TIMER HANDLER
******************************************************************************/
/**************************************************************************//**
\brief Checks if identification process is in progress

\returns true if it is, false otherwise
******************************************************************************/
bool lsIdentifyIsIdentifying(void)
{
  return (lsIdentifyClusterServerAttributes.identifyTime.value > 0);
}

/**************************************************************************//**
\brief Stop identification routine.
******************************************************************************/
void lsIdentifyStop(void)
{
  identificationStatus.period = 0;
  identificationStatus.minTime = false;
  identificationStatus.chChangeEffect = false;

  HAL_StopAppTimer(&identifyEffectTimer);

  lsIdentifyClusterServerAttributes.identifyTime.value = 0;

  if (identifycb)
    identifycb();

  LEDS_SET_BRIGHTNESS(LED_NO_BRIGHTNESS);
}

/**************************************************************************//**
\brief Finish identification routine.
******************************************************************************/
static void lsIdentifyFinish(void)
{
  identificationStatus.finish = true;
}

/**************************************************************************//**
\brief Shows identification effect in way specified.

\param[in] identifyTime - identifying period in seconds.
******************************************************************************/
void lsIdentifyStart(uint16_t identifyTime)
{
  HAL_StopAppTimer(&identifyEffectTimer);

  identificationStatus.finish = false;

  lsIdentifyClusterServerAttributes.identifyTime.value = identifyTime;

  LEDS_SET_BRIGHTNESS(LED_NO_BRIGHTNESS);

  identifyEffectTimer.mode = TIMER_REPEAT_MODE;
  identifyEffectTimer.interval = IDENTIFY_EFFECT_TIMER_PERIOD;
  identifyEffectTimer.callback = identifyEffectTimerFired;

  HAL_StartAppTimer(&identifyEffectTimer);
}

/**************************************************************************//**
\brief Timer expiry handler for identifyEffectTimer
******************************************************************************/
static void identifyEffectTimerFired(void)
{
  uint8_t level = 0;

  if (identificationStatus.chChangeEffect)
  {
    if (identificationStatus.period)
    {
      lsIdentifyClusterServerAttributes.identifyTime.value--;
      identificationStatus.period = !identificationStatus.period;
    }
    else
    {
      identificationStatus.period = !identificationStatus.period;
    }

    if (!identificationStatus.minTime)
    {
      level = LED_MAX_BRIGHTNESS;
      identificationStatus.minTime = !identificationStatus.minTime;
    }
    else
    {
      level = LED_MIN_BRIGHTNESS;
    }
  }
  else
  { // Effects such as Blink, Breathe and Okay or Normal Identify
    identificationStatus.period = !identificationStatus.period;

    if (identificationStatus.period)
    {
      level = LED_MAX_BRIGHTNESS;
      lsIdentifyClusterServerAttributes.identifyTime.value--;
    }
  }

  LEDS_SET_BRIGHTNESS(level);

  (void)level;

  if ((0 == lsIdentifyClusterServerAttributes.identifyTime.value) || identificationStatus.finish)
  {
    lsIdentifyStop();
  }
}

/**************************************************************************//**
\brief Callback on receiving Identify command

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer

\return status of indication routine
******************************************************************************/
static ZCL_Status_t identifyInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Identify_t *payload)
{
  appSnprintf("->Identify\r\n");

  if (payload->identifyTime)
  {
    lsIdentifyStart(payload->identifyTime);
  }
  else
  {
    lsIdentifyStop();
  }

  RAISE_CALLBACKS_TO_IDENTIFY_SUBSCIBERS(identifySubscribers, identify);

  (void)addressing, (void)payloadLength;
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Callback on receiving Identify Query command

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer

\return status of indication routine
******************************************************************************/
static ZCL_Status_t identifyQueryInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  //appSnprintf( "->IdentifyQuery\r\n");

  /* to be handled based on the destination endpoint*/
  if (lsIdentifyClusterServerAttributes.identifyTime.value)
    return sendIdentifyQueryResponse(addressing, APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, lsIdentifyClusterServerAttributes.identifyTime.value);

  RAISE_CALLBACKS_TO_IDENTIFY_SUBSCIBERS(identifySubscribers, identifyQuery);

  (void)payload, (void)payloadLength;
  return ZCL_SUCCESS_WITH_DEFAULT_RESPONSE_STATUS;
}


/**************************************************************************//**
\brief Callback on receiving Identify Query Response command

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer

\return status of indication routine
******************************************************************************/
static ZCL_Status_t identifyQueryResponseInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_IdentifyQueryResponse_t *payload)
{
  //appSnprintf("->IdentifyQueryResponse, addr = %d\r\n", addressing->addr.shortAddress);

  RAISE_CALLBACKS_TO_IDENTIFY_SUBSCIBERS(identifySubscribers, identifyQueryResponse);

  (void)payloadLength;
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Callback on receive of Trigger Effect command
******************************************************************************/
static ZCL_Status_t triggerEffectInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_TriggerEffect_t *payload)
{
  appSnprintf("->TriggerEffect %d\r\n",  payload->effectIdentifier);

  switch (payload->effectIdentifier)
  {
    case ZCL_EFFECT_IDENTIFIER_BLINK:
      lsIdentifyStart(BLINK_IDENTIFY_TIME);
      break;

    case ZCL_EFFECT_IDENTIFIER_BREATHE:
      lsIdentifyStart(BREATHE_IDENTIFY_TIME);
      break;

    case ZCL_EFFECT_IDENTIFIER_OKAY:
      lsIdentifyStart(OKAY_IDENTIFY_TIME);
      break;

    case ZCL_EFFECT_IDENTIFIER_CHANNEL_CHANGE:
      identificationStatus.chChangeEffect = true;
      lsIdentifyStart(CHANNEL_CHANGE_IDENTIFY_TIME);
      break;

    case ZCL_EFFECT_IDENTIFIER_FINISH_EFFECT:
      lsIdentifyFinish();
      break;

    case ZCL_EFFECT_IDENTIFIER_STOP_EFFECT:
      lsIdentifyStop();
      break;

    default:
      break;
  }
  (void)addressing;
  (void)payloadLength;
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Attribute event (writing/reading) callback.

\param[in] addressing - incoming request addressing information.
\param[in] attributeId - attribute identifier.
\param[in] event - attribute event (read/write).
******************************************************************************/
static void ZCL_LsIdentifyAttributeEventInd(ZCL_Addressing_t *addressing,
  ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
  if ((ZCL_WRITE_ATTRIBUTE_EVENT == event) &&
      (ZCL_IDENTIFY_CLUSTER_IDENTIFY_TIME_ATTRIBUTE_ID == attributeId))
  {
    if (lsIdentifyClusterServerAttributes.identifyTime.value)
    {
      lsIdentifyStart(lsIdentifyClusterServerAttributes.identifyTime.value);
    }
    else
    {
      lsIdentifyStop();
    }
    (void)addressing;
  }
}

#endif //#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
#endif //#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)

// eof lsIdentifyCluster.c

