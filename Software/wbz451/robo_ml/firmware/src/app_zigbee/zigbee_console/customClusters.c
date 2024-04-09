/*******************************************************************************
  Custom Cluster Source file

  Company:
    Microchip Technology Inc.

  File Name:
    customCluster.c

  Summary:
    This file contains Custom Cluster Implementation.

  Description:
    This file contains Custom Cluster Implementation . 
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

#if APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE
/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/clusters/include/identifyCluster.h>
#include <z3device/custom/include/customClusters.h>
#include <z3device/custom/include/customBasicCluster.h>
#include <z3device/custom/include/customIdentifyCluster.h>
#include <z3device/custom/include/customOnOffCluster.h>
#include <z3device/custom/include/customLevelControlCluster.h>
#include <z3device/custom/include/customColorControlCluster.h>
#include <z3device/custom/include/customGroupsCluster.h>
#include <z3device/custom/include/customScenesCluster.h>
#include <z3device/custom/include/customAlarmsCluster.h>
#include <z3device/custom/include/customFanControlCluster.h>
#include <z3device/custom/include/customHumidityMeasurementCluster.h>
#include <z3device/custom/include/customIasACECluster.h>
#include <z3device/custom/include/customIasZoneCluster.h>
#include <z3device/custom/include/customOccupancySensingCluster.h>
#include <z3device/custom/include/customIlluminanceMeasurementCluster.h>
#include <z3device/custom/include/customTemperatureMeasurementCluster.h>
#include <z3device/custom/include/customThermostatCluster.h>
#include <z3device/custom/include/customThermostatUiConfCluster.h>
#include <z3device/custom/include/customTimeCluster.h>
#include <z3device/custom/include/customCommissioningCluster.h>
#include <z3device/custom/include/customDiagnosticsCluster.h>

#include <z3device/custom/include/customArmorientationcluster0Cluster.h>
#include <zcl/include/zclArmorientationcluster0Cluster.h>
/******************************************************************************
                    Global variables
******************************************************************************/
ZCL_Cluster_t customServerClusters[CUSTOM_SERVER_CLUSTERS_COUNT] =
{
  ZCL_DEFINE_BASIC_CLUSTER_SERVER(&customBasicClusterServerAttributes, &customBasicClusterServerCommands),
  DEFINE_IDENTIFY_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &customIdentifyClusterServerAttributes, &customIdentifyCommands),
  DEFINE_GROUPS_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &customGroupsClusterServerAttributes, &customGroupsCommands),
  DEFINE_SCENES_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &customScenesClusterServerAttributes, &customScenesCommands),
  DEFINE_COMMISSIONING_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &customCommissioningClusterServerAttributes, &customCommissioningClusterCommands),
  DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER(ZCL_SERVER_CLUSTER_TYPE, &armorientationcluster0ServerClusterAttributes, &armorientationcluster0ServerClusterCommands),
};

void (*customServerClusterInitFunctions[CUSTOM_SERVER_CLUSTER_INIT_COUNT])() =
{
  customBasicClusterInit,
  customIdentifyClusterInit,
  customGroupsClusterInit,
  customScenesClusterInit,
  customCommissioningClusterInit,
  customArmorientationcluster0Init,
};


ClusterId_t customServerClusterIds[CUSTOM_SERVER_CLUSTERS_COUNT] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  SCENES_CLUSTER_ID,
  ZLL_COMMISSIONING_CLUSTER_ID,
  ARMORIENTATIONCLUSTER0_CLUSTER_ID,
};

ZCL_Cluster_t customClientClusters[CUSTOM_CLIENT_CLUSTERS_COUNT] =
{
  ZCL_DEFINE_BASIC_CLUSTER_CLIENT(&customBasicClusterClientAttributes),
  DEFINE_IDENTIFY_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &customIdentifyClusterClientAttributes, &customIdentifyCommands),
  DEFINE_GROUPS_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &customGroupsClusterClientAttributes, &customGroupsCommands),
  DEFINE_SCENES_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &customScenesClusterClientAttributes, &customScenesClientCommands),
  DEFINE_COMMISSIONING_CLUSTER(ZCL_CLIENT_CLUSTER_TYPE, &customCommissioningClusterClientAttributes, &customCommissioningClusterCommands),
};


ClusterId_t customClientClusterIds[CUSTOM_CLIENT_CLUSTERS_COUNT] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  SCENES_CLUSTER_ID,
  ZLL_COMMISSIONING_CLUSTER_ID,
};

void (*customClientClusterInitFunctions[CUSTOM_CLIENT_CLUSTER_INIT_COUNT])() =
{
  customBasicClusterInit,
  customIdentifyClusterInit,
  customGroupsClusterInit,
  customScenesClusterInit,
  customCommissioningClusterInit,
};


#endif // #if APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE

// eof customClusters.c
