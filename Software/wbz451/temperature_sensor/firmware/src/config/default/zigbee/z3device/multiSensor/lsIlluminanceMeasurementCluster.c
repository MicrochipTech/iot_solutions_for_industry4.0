/*******************************************************************************
  Light-Sensor Illuminance Measurement Cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
   lsIlluminanceMeasurementCluster.c

  Summary:
    This file contains Light-Sensor Illuminance Measurement Cluster.

  Description:
    This file contains Light-Sensor Illuminance Measurement Cluster.
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

#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/z3Device.h>
#include <zcl/include/zclZllBasicCluster.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/multiSensor/include/lsBasicCluster.h>
#include <z3device/multiSensor/include/osIdentifyCluster.h>
#include <z3device/multiSensor/include/lsIdentifyCluster.h>
#include <z3device/multiSensor/include/msClusters.h>
#include <z3device/multiSensor/include/lsIlluminanceMeasurementCluster.h>
#include <app_zigbee/app_zigbee_handler.h>

/*******************************************************************************
                    Static functions section
*******************************************************************************/
static void lsFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t id);
static void lsConfigureReportingResp(ZCL_Notify_t *ntfy);
static void ZCL_LsIlluminanceAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);

/******************************************************************************
                    static variables
******************************************************************************/
static ZCL_DeviceEndpoint_t lsEndpoint =
{
  .simpleDescriptor =
  {
    .endpoint            = APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR,
    .AppProfileId        = PROFILE_ID_HOME_AUTOMATION,
    .AppDeviceId         = APP_Z3DEVICE_LS_ID,
    .AppInClustersCount  = ARRAY_SIZE(lsServerClusterIds),
    .AppInClustersList   = lsServerClusterIds,
    .AppOutClustersCount = ARRAY_SIZE(lsClientClusterIds),
    .AppOutClustersList  = lsClientClusterIds,
  },
  .serverCluster = lsServerClusters,
  .clientCluster = lsClientClusters,
};

static ClusterId_t lsServerClusterToBindIds[] =
{
  ILLUMINANCE_MEASUREMENT_CLUSTER_ID,
};

static AppBindReq_t lsBindReq =
{
  .remoteServers     = NULL,
  .remoteServersCnt  = 0,
  .remoteClients     = lsServerClusterToBindIds,
  .remoteClientsCnt  = ARRAY_SIZE(lsServerClusterToBindIds),
  .groupId           = 0xffff,
  .srcEndpoint       = APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR,
  .callback          = lsFindingBindingFinishedForACluster,
  .startIdentifyingFn= lsIdetifyStartIdentifyingCb
};

ZCL_IlluminanceMeasurementClusterServerAttributes_t lsIlluminanceMeasurementClusterServerAttributes =
{
  ZCL_DEFINE_ILLUMINANCE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES(ILLUMINANCE_MEASUREMENT_VAL_MIN_REPORT_PERIOD, ILLUMINANCE_MEASUREMENT_VAL_MAX_REPORT_PERIOD)
};

ZCL_IlluminanceMeasurementClusterServerAttributes_t __attribute__((persistent)) backuplsIlluminanceMeasurementClusterServerAttributes;
/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void lsDeviceInit(void)
{
  APP_RegisterEndpoint(&lsEndpoint, &lsBindReq);

  lsBasicClusterInit();
  lsIdentifyClusterInit();
  illuminanceMeasurementClusterInit();

  if (PDS_IsAbleToRestore(APP_MS_ILLU_MEASURED_VALUE_MEM_ID))
    PDS_Restore(APP_MS_ILLU_MEASURED_VALUE_MEM_ID);
}

/**************************************************************************//**
\brief Initializes Illuminance measurement Sensing cluster
******************************************************************************/
void illuminanceMeasurementClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, ILLUMINANCE_MEASUREMENT_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
  ZCL_Cluster_t *clientSideCluster = ZCL_GetCluster(APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, ILLUMINANCE_MEASUREMENT_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);

  if (cluster)
    cluster->ZCL_AttributeEventInd = ZCL_LsIlluminanceAttributeEventInd;

  lsIlluminanceMeasurementClusterServerAttributes.lightSensorType.value = APP_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_VALUE;
  lsIlluminanceMeasurementClusterServerAttributes.measuredValue.value = APP_ILLUMINANCE_MEASUREMENT_MEASURED_VALUE_ATTRIBUTE_VALUE;
  lsIlluminanceMeasurementClusterServerAttributes.minMeasuredValue.value = APP_ILLUMINANCE_MEASUREMENT_MIN_MEASURED_VALUE_ATTRIBUTE_VALUE;
  lsIlluminanceMeasurementClusterServerAttributes.maxMeasuredValue.value = APP_ILLUMINANCE_MEASUREMENT_MAX_MEASURED_VALUE_ATTRIBUTE_VALUE;
  lsIlluminanceMeasurementClusterServerAttributes.tolerance.value = APP_ILLUMINANCE_MEASUREMENT_TOLERANCE_ATTRIBUTE_VALUE;
  lsIlluminanceMeasurementClusterServerAttributes.clusterVersion.value = ILLUMINANCE_MEASUREMENT_CLUSTER_VERSION;

  if (clientSideCluster)
    clientSideCluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

/**************************************************************************//**
\brief Update the measured Value
******************************************************************************/
void illuminanceMeasurementUpdateMeasuredValue(void)
{
  uint16_t measuredValue;

  measuredValue = rand()% APP_ILLUMINANCE_MEASUREMENT_MAX_MEASURED_VALUE_ATTRIBUTE_VALUE;
  if (measuredValue < lsIlluminanceMeasurementClusterServerAttributes.minMeasuredValue.value)
    lsIlluminanceMeasurementClusterServerAttributes.measuredValue.value = lsIlluminanceMeasurementClusterServerAttributes.minMeasuredValue.value;
  else
    lsIlluminanceMeasurementClusterServerAttributes.measuredValue.value = measuredValue;
  
  PDS_Store(APP_MS_ILLU_MEASURED_VALUE_MEM_ID);
#ifdef _ZCL_REPORTING_SUPPORT_
  ZCL_ReportOnChangeIfNeeded(&lsIlluminanceMeasurementClusterServerAttributes.measuredValue);
#endif
}

/*******************************************************************************
\brief callback called on the finishing of binding of one cluster
********************************************************************************/
static void lsFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t clusterId)
{
  if (ILLUMINANCE_MEASUREMENT_CLUSTER_ID == clusterId)
  {
    ZCL_Cluster_t *serverCluster = ZCL_GetCluster(APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, ILLUMINANCE_MEASUREMENT_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
    if (serverCluster)
      sendConfigureReportingToNotify(APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR, APP_ENDPOINT_COMBINED_INTERFACE, ILLUMINANCE_MEASUREMENT_CLUSTER_ID,
      ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_MEASURED_VALUE_SERVER_ATTRIBUTE_ID, ILLUMINANCE_MEASUREMENT_VAL_MAX_REPORT_PERIOD, lsConfigureReportingResp);
  }
}


/**************************************************************************//**
\brief Indication of configure reporting response

\param[in] ntfy - pointer to response
******************************************************************************/
static void lsConfigureReportingResp(ZCL_Notify_t *ntfy)
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
static void ZCL_LsIlluminanceAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
  APP_Zigbee_Event_t eventItem;
  eventItem.eventGroup = EVENT_CLUSTER;
  eventItem.eventId = CMD_ZCL_ATTR_ILLUMINANCE_MEASUREMENT;
  eventItem.eventData.zclAttributeData.addressing = addressing;
  eventItem.eventData.zclAttributeData.attributeId = attributeId;
  eventItem.eventData.zclAttributeData.event = event;
  APP_Zigbee_Handler(eventItem);

  if (((ZCL_CONFIGURE_ATTRIBUTE_REPORTING_EVENT == event) || \
       (ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == event)) && \
      (ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_MEASURED_VALUE_SERVER_ATTRIBUTE_ID == attributeId))
  {
    PDS_Store(APP_MS_ILLU_MEASURED_VALUE_MEM_ID);
  }
}
/**************************************************************************//**
\brief Backing up attributes
******************************************************************************/
void lsBackupLsAttributes(void)
{
  memcpy4ByteAligned(&backuplsIlluminanceMeasurementClusterServerAttributes, &lsIlluminanceMeasurementClusterServerAttributes, sizeof(ZCL_IlluminanceMeasurementClusterServerAttributes_t));
}

/**************************************************************************//**
\brief Restoring attributes
******************************************************************************/
void lsRestoreLsAttributes(void)
{ 
  memcpy4ByteAligned(&lsIlluminanceMeasurementClusterServerAttributes,&backuplsIlluminanceMeasurementClusterServerAttributes,  sizeof(ZCL_IlluminanceMeasurementClusterServerAttributes_t));
}
#endif  //#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
#endif  //#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)



// eof lsilluminanceMeasurementCluster.c
