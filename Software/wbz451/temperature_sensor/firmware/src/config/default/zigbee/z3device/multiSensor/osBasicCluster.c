/*******************************************************************************
 Occupancy Sensor Basic cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    osBasicCluster.c

  Summary:
    This file contains the Occupancy Sensor Basic cluster interface.

  Description:
    This file contains the Occupancy Sensor Basic cluster interface.
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
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/common/include/appConsts.h>
#include <z3device/clusters/include/basicCluster.h>
#include <z3device/multiSensor/include/msClusters.h>
#include <z3device/multiSensor/include/osBasicCluster.h>
#include <zcl/include/zclCommandManager.h>
#include <app_zigbee/app_zigbee_handler.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
static ZCL_Status_t resetToFactoryDefaultsInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
/******************************************************************************
                    Global variables section
******************************************************************************/
ZCL_BasicClusterServerAttributes_t osBasicClusterServerAttributes =
{
  ZCL_DEFINE_BASIC_CLUSTER_SERVER_ATTRIBUTES()
};


PROGMEM_DECLARE(ZCL_BasicClusterServerCommands_t osBasicClusterServerCommands) =
{
  ZCL_DEFINE_BASIC_CLUSTER_COMMANDS(resetToFactoryDefaultsInd)
};

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Basic cluster
******************************************************************************/
void osBasicClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_OCCUPANCY_SENSOR, BASIC_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);

  osBasicClusterServerAttributes.clusterVersion.value      = BASIC_CLUSTER_VERSION;
  osBasicClusterServerAttributes.zclVersion.value          = ZCL_VERSION;
  osBasicClusterServerAttributes.powerSource.value         = POWER_SOURCE;
  osBasicClusterServerAttributes.physicalEnvironment.value = UNKNOWN_ENVIRONMENT;
  osBasicClusterServerAttributes.applicationVersion.value  = APP_VERSION;
  osBasicClusterServerAttributes.stackVersion.value        = STACK_VERSION;
  osBasicClusterServerAttributes.hwVersion.value           = HW_VERSION;
  memcpy(osBasicClusterServerAttributes.manufacturerName.value, "\x1f Microchip ", 12);
  memcpy(osBasicClusterServerAttributes.modelIdentifier.value, "\x1f OccupancySensor", 17);
  memcpy(osBasicClusterServerAttributes.dateCode.value, "\xf 20150901", 10);
#if ZLO_CLUSTER_ENHANCEMENTS == 1
  osBasicClusterServerAttributes.genericDeviceClass.value  = LIGHTING_DEVICE_CLASS;
  osBasicClusterServerAttributes.genericDeviceType.value   = MOTION_SENSOR_LIGHT_SENSOR_DEVICE_TYPE;
  memcpy(osBasicClusterServerAttributes.productCode.value, "\x1f\x4XYZ123", 8);
  memcpy(osBasicClusterServerAttributes.productURL.value, "\x1f  www.microchip.com ", 17);
#endif
  memcpy(osBasicClusterServerAttributes.swBuildId.value, "\xf abcdefgh", 10);
  if (cluster)
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

  for (uint8_t i=0; i<OS_CLIENT_CLUSTERS_COUNT; i++)
  {
    if (osClientClusterInitFunctions[i])
      (osClientClusterInitFunctions[i])();
  }

  // needs to enable after app directory is created
  //PDS_Store(Z3DEVICE_APP_MEMORY_MEM_ID);

  APP_Zigbee_Handler(event);
  return ZCL_SUCCESS_STATUS;
}
#endif //#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
#endif //#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)

// eof osBasicCluster.c
