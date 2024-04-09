/*******************************************************************************
  Combined Interface Basic cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
   ciBasicCluster.c

  Summary:
    This file contains the Combined Interface Basic cluster interface.

  Description:
    This file contains the Combined Interface Basic cluster interface.
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE)

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/combinedInterface/include/ciClusters.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/combinedInterface/include/ciBasicCluster.h>
#include <z3device/combinedInterface/include/ciIdentifyCluster.h>
#include <z3device/combinedInterface/include/ciOnOffCluster.h>
#include <z3device/combinedInterface/include/ciLevelControlCluster.h>
#include <z3device/combinedInterface/include/ciGroupsCluster.h>
#include <z3device/combinedInterface/include/ciScenesCluster.h>
#include <z3device/combinedInterface/include/ciOccupancySensingCluster.h>
#include <z3device/combinedInterface/include/ciCommissioningCluster.h>
#include <z3device/combinedInterface/include/ciIlluminanceMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciHumidityMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciTemperatureMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciColorControlCluster.h>
#include <z3device/combinedInterface/include/ciThermostatCluster.h>
#include <z3device/combinedInterface/include/ciFanControlCluster.h>
#include <z3device/combinedInterface/include/ciTimeCluster.h>
#include <z3device/combinedInterface/include/ciAlarmsCluster.h>
#include <z3device/combinedInterface/include/ciThermostatUiConfCluster.h>
#include <z3device/combinedInterface/include/ciIasZoneCluster.h>
#include <z3device/combinedInterface/include/ciIasACECluster.h>
#include <app_zigbee/app_zigbee_handler.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
static ZCL_Status_t resetToFactoryDefaultsInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
/******************************************************************************
                    Global variables section
******************************************************************************/
ZCL_BasicClusterServerAttributes_t ciBasicClusterServerAttributes =
{
  ZCL_DEFINE_BASIC_CLUSTER_SERVER_ATTRIBUTES()
};

ZCL_BasicClusterClientAttributes_t ciBasicClusterClientAttributes =
{
  ZCL_DEFINE_BASIC_CLUSTER_CLIENT_ATTRIBUTES()
};

PROGMEM_DECLARE (ZCL_BasicClusterServerCommands_t ciBasicClusterServerCommands) =
{
  ZCL_DEFINE_BASIC_CLUSTER_COMMANDS(resetToFactoryDefaultsInd)
};

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Basic cluster
******************************************************************************/
void ciBasicClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_COMBINED_INTERFACE, BASIC_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);

  ciBasicClusterServerAttributes.clusterVersion.value      = BASIC_CLUSTER_VERSION;
  ciBasicClusterServerAttributes.zclVersion.value          = ZCL_VERSION;
  ciBasicClusterServerAttributes.powerSource.value         = POWER_SOURCE;
  ciBasicClusterServerAttributes.physicalEnvironment.value = UNKNOWN_ENVIRONMENT;
  ciBasicClusterServerAttributes.applicationVersion.value  = APP_VERSION;
  ciBasicClusterServerAttributes.stackVersion.value        = STACK_VERSION;
  ciBasicClusterServerAttributes.hwVersion.value           = HW_VERSION;
  memcpy(ciBasicClusterServerAttributes.manufacturerName.value, "\x1f Microchip ", 12);
  memcpy(ciBasicClusterServerAttributes.modelIdentifier.value, "\x1f CombinedInterface", 19);
  memcpy(ciBasicClusterServerAttributes.dateCode.value, "\xf 20150901", 10);
  memcpy(ciBasicClusterServerAttributes.swBuildId.value, "\xf abcdefgh", 10);
  /* Client side attributes */
  ciBasicClusterClientAttributes.clusterVersion.value      = BASIC_CLUSTER_VERSION;
  cluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

/**************************************************************************//**
\brief Callback on receive of resetToFactoryDefaults command
******************************************************************************/
static ZCL_Status_t resetToFactoryDefaultsInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_CLUSTER;
  event.eventId = CMD_ZCL_RESET_TO_FACTORY_DEFAULTS;
  event.eventData.zclEventData.addressing = addressing;
  event.eventData.zclEventData.payloadLength = payloadLength;
  event.eventData.zclEventData.payload = payload;

  for (uint8_t i=0; i<CI_SERVER_CLUSTER_INIT_COUNT; i++)
  {
    if (ciServerClusterInitFunctions[i])
      (ciServerClusterInitFunctions[i])();
  }

  // needs to enable after app directory is created
  //PDS_Store(Z3DEVICE_APP_MEMORY_MEM_ID);

  APP_Zigbee_Handler(event);
  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Sends resetToFactoryDefaults command unicastly

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
******************************************************************************/
void basicResetToFactoryDefaultsCommand(APS_AddrMode_t mode,ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_BASIC_CLUSTER_SERVER_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID, 0, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, BASIC_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE

// eof ciBasicCluster.c
