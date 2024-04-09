/*******************************************************************************
  Occupancy-Sensor Occupancy Sensing cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    osOccupancySensingCluster.c

  Summary:
    This file contains the Occupancy-Sensor Occupancy Sensing cluster interface.

  Description:
    This file contains the Occupancy-Sensor Occupancy Sensing cluster interface.
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
#include <z3device/multiSensor/include/osOccupancySensingCluster.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/z3Device.h>
#include <z3device/multiSensor/include/msClusters.h>
#include <zcl/include/zclZllBasicCluster.h>
#include <z3device/multiSensor/include/osBasicCluster.h>
#include <z3device/multiSensor/include/osIdentifyCluster.h>
#include <z3device/multiSensor/include/osIdentifyCluster.h>

#include <zcl/include/zclCommandManager.h>
/*******************************************************************************
                    Static functions section
*******************************************************************************/
static void osFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t clusterId);
static void osConfigureReportingResp(ZCL_Notify_t *ntfy);
static void ZCL_OsOccupancyAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);

/******************************************************************************
                                  Types
*******************************************************************************/


/******************************************************************************
                    Local variables
******************************************************************************/
static ZCL_DeviceEndpoint_t osEndpoint =
{
  .simpleDescriptor =
  {
    .endpoint            = APP_ENDPOINT_OCCUPANCY_SENSOR,
    .AppProfileId        = PROFILE_ID_HOME_AUTOMATION,
    .AppDeviceId         = APP_Z3DEVICE_OS_ID,
    .AppInClustersCount  = ARRAY_SIZE(osServerClusterIds),
    .AppInClustersList   = osServerClusterIds,
    .AppOutClustersCount = ARRAY_SIZE(osClientClusterIds),
    .AppOutClustersList  = osClientClusterIds,
  },
  .serverCluster = osServerClusters,
  .clientCluster = osClientClusters,
};

static ClusterId_t osClientClusterToBindIds[] =
{
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID
};

static ClusterId_t osServerClusterToBindIds[] =
{
  OCCUPANCY_SENSING_CLUSTER_ID,
};

static AppBindReq_t osBindReq =
{
  .remoteServers     = osClientClusterToBindIds,
  .remoteServersCnt  = ARRAY_SIZE(osClientClusterToBindIds),
  .remoteClients     = osServerClusterToBindIds,
  .remoteClientsCnt  = ARRAY_SIZE(osServerClusterToBindIds),
  .groupId           = 0xffff,
  .srcEndpoint       = APP_ENDPOINT_OCCUPANCY_SENSOR,
  .callback          = osFindingBindingFinishedForACluster,
  .startIdentifyingFn= osIdetifyStartIdentifyingCb
};

ZCL_OccupancySensingClusterServerAttributes_t osOccupancySensingClusterServerAttributes =
{
  ZCL_DEFINE_OCCUPANCY_SENSING_CLUSTER_SERVER_ATTRIBUTES(OCCUPANCY_SENSING_VAL_MIN_REPORT_PERIOD, OCCUPANCY_SENSING_VAL_MAX_REPORT_PERIOD)
};

ZCL_OccupancySensingClusterServerAttributes_t  __attribute__((persistent)) backuposOccupancySensingClusterServerAttributes;

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void osDeviceInit(void)
{
  APP_RegisterEndpoint(&osEndpoint, &osBindReq);

  osBasicClusterInit();
  osIdentifyClusterInit();
  occupancySensingClusterInit();

  if (PDS_IsAbleToRestore(APP_MS_OCCUPANCY_MEM_ID))
    PDS_Restore(APP_MS_OCCUPANCY_MEM_ID);
}

/**************************************************************************//**
\brief Initializes Occupancy Sensing cluster
******************************************************************************/
void occupancySensingClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_OCCUPANCY_SENSOR, OCCUPANCY_SENSING_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
  ZCL_Cluster_t *clientSideCluster = ZCL_GetCluster(APP_ENDPOINT_OCCUPANCY_SENSOR, OCCUPANCY_SENSING_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);

  if (cluster)
    cluster->ZCL_AttributeEventInd = ZCL_OsOccupancyAttributeEventInd;
  
  osOccupancySensingClusterServerAttributes.occupancySensorType.value = OCCUPANYC_SENSOR_TYPE_ATTRIBUTE_VALUE_PIR;
  osOccupancySensingClusterServerAttributes.occupancy.value = OCCUPANCY_ATTRIBUTE_VALUE_UNOCCUPIED;
  osOccupancySensingClusterServerAttributes.clusterVersion.value = OCCUPANCY_CLUSTER_VERSION;
  if (clientSideCluster)
    clientSideCluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}
/**************************************************************************//**
\brief Toggles occupancy
******************************************************************************/
void occupancySensingToggleOccupancy(void)
{
  if (OCCUPANCY_ATTRIBUTE_VALUE_UNOCCUPIED == osOccupancySensingClusterServerAttributes.occupancy.value)
    osOccupancySensingClusterServerAttributes.occupancy.value = OCCUPANCY_ATTRIBUTE_VALUE_OCCUPIED;
  else
    osOccupancySensingClusterServerAttributes.occupancy.value = OCCUPANCY_ATTRIBUTE_VALUE_UNOCCUPIED;
  
  PDS_Store(APP_MS_OCCUPANCY_MEM_ID);
#ifdef _ZCL_REPORTING_SUPPORT_
  ZCL_ReportOnChangeIfNeeded(&osOccupancySensingClusterServerAttributes.occupancy);
#endif
}
/*******************************************************************************
\brief callback called on the finishing of binding of one cluster
********************************************************************************/
static void osFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t clusterId)
{
  if (OCCUPANCY_SENSING_CLUSTER_ID == clusterId)
  {
    ZCL_Cluster_t *serverCluster = ZCL_GetCluster(APP_ENDPOINT_OCCUPANCY_SENSOR, OCCUPANCY_SENSING_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
    if(serverCluster)
     sendConfigureReportingToNotify(APP_ENDPOINT_OCCUPANCY_SENSOR, APP_ENDPOINT_COMBINED_INTERFACE, OCCUPANCY_SENSING_CLUSTER_ID,
        ZCL_OCCUPANCY_SENSING_CLUSTER_OCCUPANCY_SERVER_ATTRIBUTE_ID, OCCUPANCY_SENSING_VAL_MAX_REPORT_PERIOD, osConfigureReportingResp);
  }
}

/**************************************************************************//**
\brief Indication of configure reporting response

\param[in] ntfy - pointer to response
******************************************************************************/
static void osConfigureReportingResp(ZCL_Notify_t *ntfy)
{
#ifdef _ZCL_REPORTING_SUPPORT_
  ZCL_StartReporting();
#endif
  (void)ntfy;
}

/**************************************************************************//**
\brief Attribute event (writing/reading) callback.

\param[in] addressing - incoming request addressing information.
\param[in] attributeId - attribute identifier.
\param[in] event - attribute event (read/write).
******************************************************************************/
static void ZCL_OsOccupancyAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
  APP_Zigbee_Event_t eventItem;
  eventItem.eventGroup = EVENT_CLUSTER;
  eventItem.eventId = CMD_ZCL_ATTR_OCCUPANCY;
  eventItem.eventData.zclAttributeData.addressing = addressing;
  eventItem.eventData.zclAttributeData.attributeId = attributeId;
  eventItem.eventData.zclAttributeData.event = event;
  APP_Zigbee_Handler(eventItem);

  if (((ZCL_CONFIGURE_ATTRIBUTE_REPORTING_EVENT == event) || \
      (ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == event)) && \
      ((ZCL_OCCUPANCY_SENSING_CLUSTER_OCCUPANCY_SERVER_ATTRIBUTE_ID == attributeId))
      )
  {
    PDS_Store(APP_MS_OCCUPANCY_MEM_ID);
  }
}

/**************************************************************************//**
\brief Backing up attributes
******************************************************************************/
void osBackupOsAttributes(void)
{
   memcpy4ByteAligned(&backuposOccupancySensingClusterServerAttributes, &osOccupancySensingClusterServerAttributes, sizeof(ZCL_OccupancySensingClusterServerAttributes_t));
}

/**************************************************************************//**
\brief Restoring attributes
******************************************************************************/
void osRestoreOsAttributes(void)
{
   memcpy4ByteAligned(&osOccupancySensingClusterServerAttributes, &backuposOccupancySensingClusterServerAttributes, sizeof(ZCL_OccupancySensingClusterServerAttributes_t));
}
#endif //#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
#endif //#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)

// eof osOccupancySensingCluster.c
