/*******************************************************************************
  Combined Interface clusters Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ciClusters.h

  Summary:
    This file contains the Combined Interface clusters interface.

  Description:
    This file contains the Combined Interface clusters interface.
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
#include <z3device/clusters/include/basicCluster.h>
#include <zcl/clusters/include/identifyCluster.h>
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
#include <z3device/combinedInterface/include/ciArmcluster0Cluster.h>

/******************************************************************************
                    Global variables
******************************************************************************/
ZCL_Cluster_t ciServerClusters[CI_SERVER_CLUSTERS_COUNT] =
{
  ZCL_DEFINE_BASIC_CLUSTER_SERVER(&ciBasicClusterServerAttributes, &ciBasicClusterServerCommands),
  DEFINE_IDENTIFY_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &ciIdentifyClusterServerAttributes, &ciIdentifyCommands),
  DEFINE_GROUPS_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &ciGroupsClusterServerAttributes, &ciGroupsCommands),
  DEFINE_IAS_ACE_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &ciIasACEAceClusterServerAttributes, &ciIASACEClusterCommands),
     // Optional
  DEFINE_COMMISSIONING_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &ciCommissioningClusterServerAttributes, &ciCommissioningClusterCommands),
  DEFINE_TIME_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &ciTimeClusterServerAttributes, NULL)
};

void (*ciServerClusterInitFunctions[CI_SERVER_CLUSTER_INIT_COUNT])() =
{
  ciBasicClusterInit,
  ciIdentifyClusterInit,
  ciGroupsClusterInit,
  ciIasACEClusterInit,
    // Optional
  ciCommissioningClusterInit,
};

ZCL_Cluster_t ciClientClusters[CI_CLIENT_CLUSTERS_COUNT] =
{
  ZCL_DEFINE_BASIC_CLUSTER_CLIENT(&ciBasicClusterClientAttributes),
  DEFINE_IDENTIFY_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciIdentifyClusterClientAttributes, &ciIdentifyCommands),
  DEFINE_ONOFF_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciOnOffClusterClientAttributes, &ciOnOffCommands),
  DEFINE_LEVEL_CONTROL_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciOnOffClusterClientAttributes, &ciLevelControlCommands),
  DEFINE_GROUPS_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciGroupsClusterClientAttributes, &ciGroupsCommands),
  DEFINE_SCENES_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciScenesClusterClientAttributes, &ciScenesCommands),
  DEFINE_OCCUPANCY_SENSING_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciOccupancySensingClusterClientAttributes, NULL),
  DEFINE_ILLUMINANCE_MEASUREMENT_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciIlluminanceMeasurementClusterClientAttributes), 
  DEFINE_HUMIDITY_MEASUREMENT_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciHumidityMeasurementClusterClientAttributes),
  DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciTemperatureMeasurementClusterClientAttributes),
  DEFINE_COMMISSIONING_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciCommissioningClusterClientAttributes, &ciCommissioningClusterCommands),
  DEFINE_COLOR_CONTROL_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciColorControlClusterClientAttributes, &ciColorControlCommands),
  DEFINE_THERMOSTAT_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciThermostatClusterClientAttributes, NULL),
  DEFINE_THERMOSTAT_UI_CONF_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciThermostatUiConfClusterClientAttributes, NULL),
  DEFINE_ALARMS_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciAlarmsClusterClientAttributes, &ciAlarmsCommands),
  DEFINE_FAN_CONTROL_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciFanControlClusterClientAttributes, NULL),
  DEFINE_IAS_ZONE_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &ciZoneClusterClientAttributes, &ciIASZoneClusterClientCommands),
  DEFINE_ARMCLUSTER0_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &armcluster0ClientClusterAttributes, &armcluster0ClientClusterCommands)      //sankar
};

ClusterId_t   ciServerClusterIds[CI_SERVER_CLUSTERS_COUNT] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  IAS_ACE_CLUSTER_ID,
  // Optional
  ZLL_COMMISSIONING_CLUSTER_ID,
  TIME_CLUSTER_ID,
#ifdef OTAU_SERVER
  OTAU_CLUSTER_ID, // Always should be on last position in list of clusters ID.
#endif // OTAU_SERVER
};

ClusterId_t   ciClientClusterIds[CI_CLIENT_CLUSTERS_COUNT] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  ONOFF_CLUSTER_ID,
  LEVEL_CONTROL_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  SCENES_CLUSTER_ID,
  OCCUPANCY_SENSING_CLUSTER_ID,
  ILLUMINANCE_MEASUREMENT_CLUSTER_ID,
  TEMPERATURE_MEASUREMENT_CLUSTER_ID,
  HUMIDITY_MEASUREMENT_CLUSTER_ID,
  ZLL_COMMISSIONING_CLUSTER_ID,
  COLOR_CONTROL_CLUSTER_ID,
  THERMOSTAT_CLUSTER_ID,
  THERMOSTAT_UI_CONF_CLUSTER_ID,
  ALARMS_CLUSTER_ID,
  FAN_CONTROL_CLUSTER_ID,
  IAS_ZONE_CLUSTER_ID,
  ARMCLUSTER0_CLUSTER_ID        //sankar
};

void (*ciClientClusterInitFunctions[CI_CLIENT_CLUSTER_INIT_COUNT])() =
{
  ciBasicClusterInit,
  ciIdentifyClusterInit,
  ciOnOffClusterInit,
  ciLevelControlClusterInit,
  ciGroupsClusterInit,
  ciScenesClusterInit,
  ciOccupancySensingClusterInit,
  ciIlluminanceMeasurementClusterInit,
  ciTemperatureMeasurementClusterInit,
  ciHumidityMeasurementClusterInit,
  ciCommissioningClusterInit,
  ciColorControlClusterInit,
  ciThermostatClusterInit,
  ciThermostatUiConfClusterInit,
  ciAlarmsClusterInit,
  ciFanControlClusterInit,
  ciIasZoneClusterInit,
  ciArmcluster0Init             //sankar 
};
#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE

// eof ciClusters.c
