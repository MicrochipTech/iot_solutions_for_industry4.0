/*******************************************************************************
  Multi-Sensor Humidity Measurement cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    hsHumidityMeasurementCluster.c

  Summary:
    This file contains the Multi-Sensor Humidity Measurement cluster interface.

  Description:
    This file contains the Multi-Sensor Humidity Measurement cluster interface.
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
#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/z3Device.h>
#include <z3device/multiSensor/include/msClusters.h>
#include <zcl/include/zclZllBasicCluster.h>
#include <z3device/multiSensor/include/hsHumidityMeasurementCluster.h>
#include <z3device/multiSensor/include/hsBasicCluster.h>
#include <z3device/multiSensor/include/hsIdentifyCluster.h>
#include <z3device/multiSensor/include/hsGroupsCluster.h>
#include <zcl/include/zclCommandManager.h>
#include <app_zigbee/app_zigbee_handler.h>

/*******************************************************************************
                    Static functions section
*******************************************************************************/
static void hsFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t id);
static void hsConfigureReportingResp(ZCL_Notify_t *ntfy);
static void ZCL_HsHumidityAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);

/******************************************************************************
                    static variables
******************************************************************************/
static ZCL_DeviceEndpoint_t hsEndpoint =
{
  .simpleDescriptor =
  {
    .endpoint            = APP_ENDPOINT_HUMIDITY_SENSOR,
    .AppProfileId        = PROFILE_ID_HOME_AUTOMATION,
    .AppDeviceId         = APP_Z3DEVICE_HS_ID,
    .AppInClustersCount  = ARRAY_SIZE(hsServerClusterIds),
    .AppInClustersList   = hsServerClusterIds,
    .AppOutClustersCount = ARRAY_SIZE(hsClientClusterIds),
    .AppOutClustersList  = hsClientClusterIds,
  },
  .serverCluster = hsServerClusters,
  .clientCluster = hsClientClusters,
};

static ClusterId_t hsServerClusterToBindIds[] =
{
  HUMIDITY_MEASUREMENT_CLUSTER_ID,
};

static AppBindReq_t hsBindReq =
{
  .remoteServers     = NULL,
  .remoteServersCnt  = 0,
  .remoteClients     = hsServerClusterToBindIds,
  .remoteClientsCnt  = ARRAY_SIZE(hsServerClusterToBindIds),
  .groupId           = 0xffff,
  .srcEndpoint       = APP_ENDPOINT_HUMIDITY_SENSOR,
  .callback          = hsFindingBindingFinishedForACluster,
  .startIdentifyingFn= hsIdetifyStartIdentifyingCb
};

ZCL_HumidityMeasurementClusterServerAttributes_t hsHumidityMeasurementClusterServerAttributes =
{
  ZCL_DEFINE_HUMIDITY_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES(HUMIDITY_MEASUREMENT_VAL_MIN_REPORT_PERIOD, HUMIDITY_MEASUREMENT_VAL_MAX_REPORT_PERIOD)
};

ZCL_HumidityMeasurementClusterServerAttributes_t __attribute__((persistent)) backuphsHumidityMeasurementClusterServerAttributes;

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void hsDeviceInit(void)
{
  APP_RegisterEndpoint(&hsEndpoint, &hsBindReq);
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_HUMIDITY_SENSOR, HUMIDITY_MEASUREMENT_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
   
  if (cluster)
    cluster->ZCL_AttributeEventInd = ZCL_HsHumidityAttributeEventInd;
  
  hsBasicClusterInit();
  hsIdentifyClusterInit();
  humidityMeasurementClusterInit();

  if (PDS_IsAbleToRestore(APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID))
    PDS_Restore(APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID);
}

/**************************************************************************//**
\brief Initializes Humidity Measurement cluster
******************************************************************************/
void humidityMeasurementClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_HUMIDITY_SENSOR, HUMIDITY_MEASUREMENT_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);
  hsHumidityMeasurementClusterServerAttributes.measuredValue.value = APP_HUMIDITY_MEASUREMENT_MEASURED_VALUE_ATTRIBUTE_VALUE;
  hsHumidityMeasurementClusterServerAttributes.minMeasuredValue.value = APP_HUMIDITY_MEASUREMENT_MIN_MEASURED_VALUE_ATTRIBUTE_VALUE;
  hsHumidityMeasurementClusterServerAttributes.maxMeasuredValue.value = APP_HUMIDITY_MEASUREMENT_MAX_MEASURED_VALUE_ATTRIBUTE_VALUE;
  hsHumidityMeasurementClusterServerAttributes.tolerance.value = APP_HUMIDITY_MEASUREMENT_TOLERANCE_ATTRIBUTE_VALUE;//to be updated
  hsHumidityMeasurementClusterServerAttributes.clusterVersion.value = HUMIDITY_MEASUREMENT_CLUSTER_VERSION;
  if (cluster)
    cluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

/**************************************************************************//**
\brief Update the measured Value
******************************************************************************/
void humidityMeasurementUpdateMeasuredValue(void)
{
  uint16_t measuredValue ;

  measuredValue = hsHumidityMeasurementClusterServerAttributes.measuredValue.value + APP_HUMIDITY_MEASUREMENT_MEASURED_VALUE_PERIODIC_CHANGE;

  if (measuredValue > hsHumidityMeasurementClusterServerAttributes.maxMeasuredValue.value)
    hsHumidityMeasurementClusterServerAttributes.measuredValue.value =  hsHumidityMeasurementClusterServerAttributes.minMeasuredValue.value;
  else
    hsHumidityMeasurementClusterServerAttributes.measuredValue.value = measuredValue;
  
  PDS_Store(APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID);
#ifdef _ZCL_REPORTING_SUPPORT_
  ZCL_ReportOnChangeIfNeeded(&hsHumidityMeasurementClusterServerAttributes.measuredValue);
#endif
}

/*******************************************************************************
\brief callback called on the finishing of binding of one cluster
********************************************************************************/
static void hsFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t clusterId)
{
  if (HUMIDITY_MEASUREMENT_CLUSTER_ID == clusterId)
  {
    ZCL_Cluster_t *serverCluster = ZCL_GetCluster(APP_ENDPOINT_HUMIDITY_SENSOR, HUMIDITY_MEASUREMENT_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
    if (serverCluster)
      sendConfigureReportingToNotify(APP_ENDPOINT_HUMIDITY_SENSOR, APP_ENDPOINT_COMBINED_INTERFACE, HUMIDITY_MEASUREMENT_CLUSTER_ID,
      ZCL_HUMIDITY_MEASUREMENT_CLUSTER_SERVER_MEASURED_VALUE_ATTRIBUTE_ID, HUMIDITY_MEASUREMENT_VAL_MAX_REPORT_PERIOD, hsConfigureReportingResp);
      
  }
}


/**************************************************************************//**
\brief Indication of configure reporting response

\param[in] ntfy - pointer to response
******************************************************************************/
static void hsConfigureReportingResp(ZCL_Notify_t *ntfy)
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
static void ZCL_HsHumidityAttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
  APP_Zigbee_Event_t eventItem;
  eventItem.eventGroup = EVENT_CLUSTER;
  eventItem.eventId = CMD_ZCL_ATTR_HUMIDITY_MEASUREMENT;
  eventItem.eventData.zclAttributeData.addressing = addressing;
  eventItem.eventData.zclAttributeData.attributeId = attributeId;
  eventItem.eventData.zclAttributeData.event = event;
 
  APP_Zigbee_Handler(eventItem);
  if (((ZCL_CONFIGURE_ATTRIBUTE_REPORTING_EVENT == event) || \
       (ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == event)) && \
      (ZCL_HUMIDITY_MEASUREMENT_CLUSTER_SERVER_MEASURED_VALUE_ATTRIBUTE_ID == attributeId))      
  {
    PDS_Store(APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID);
  }

}

/**************************************************************************//**
\brief Backing up attributes
******************************************************************************/
void hsBackupHsAttributes(void)
{
  memcpy4ByteAligned(&backuphsHumidityMeasurementClusterServerAttributes,&hsHumidityMeasurementClusterServerAttributes, sizeof(ZCL_HumidityMeasurementClusterServerAttributes_t));
}

/**************************************************************************//**
\brief Restoring attributes
******************************************************************************/
void hsRestoreHsAttributes(void)
{
  memcpy4ByteAligned(&hsHumidityMeasurementClusterServerAttributes, &backuphsHumidityMeasurementClusterServerAttributes, sizeof(ZCL_HumidityMeasurementClusterServerAttributes_t));
}

#endif  //#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
#endif  //#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)



// eof hsHumidityMeasurementCluster.c
