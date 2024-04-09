/*******************************************************************************
  Custom Source file

  Company:
    Microchip Technology Inc.

  File Name:
    custom.c

  Summary:
    This file contains Custom Implementation.

  Description:
    This file contains Custom Implementation. 
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE)

/******************************************************************************
                             Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/custom/include/customClusters.h>
#include <zcl/clusters/include/identifyCluster.h>
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
#include <z3device/common/include/z3Device.h>
#include <zcl/include/zclSecurityManager.h>
#include <app_zigbee/zigbee_console/console.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/otauService.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/custom/include/custom.h>
#include <z3device/clusters/include/scenesCluster.h>
#include <z3device/clusters/include/commissioningCluster.h>
#ifdef OTAU_CLIENT
#include <zcl/include/zclOtauManager.h>
#endif

#include <z3device/custom/include/customArmorientationcluster0Cluster.h>
#include <zcl/include/zclArmorientationcluster0Cluster.h>
/******************************************************************************
                   type(s) section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/
static void customFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t id);
#if (ZB_COMMISSIONING_ON_STARTUP == 1)
#ifdef _ZCL_REPORTING_SUPPORT_
static void customConfigureReportingResp(ZCL_Notify_t *ntfy);
#endif
#endif

#ifdef OTAU_CLIENT 
static void customAddOTAUClientCluster(void);
static void configureImageKeyDone(void);
#endif
/******************************************************************************
                    Local variables section
******************************************************************************/
static ZCL_DeviceEndpoint_t customEndpoint =
{
  .simpleDescriptor =
  {
    .endpoint            = APP_ENDPOINT_CUSTOM,
    .AppProfileId        = PROFILE_ID_HOME_AUTOMATION,
    .AppDeviceId         = APP_Z3DEVICE_ID,
    .AppDeviceVersion    = 0x1,
    .AppInClustersCount  = ARRAY_SIZE(customServerClusterIds),
    .AppInClustersList   = customServerClusterIds,
    .AppOutClustersCount = ARRAY_SIZE(customClientClusterIds),
    .AppOutClustersList  = customClientClusterIds,
  },
  .serverCluster = customServerClusters,
  .clientCluster = customClientClusters,
};

static ClusterId_t customClientClusterToBindIds[] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  SCENES_CLUSTER_ID,
  ZLL_COMMISSIONING_CLUSTER_ID,
  ARMORIENTATIONCLUSTER0_CLUSTER_ID,
};

static ClusterId_t customServerClusterToBindIds[] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  SCENES_CLUSTER_ID,
  ZLL_COMMISSIONING_CLUSTER_ID,
  ARMORIENTATIONCLUSTER0_CLUSTER_ID,
};

static AppBindReq_t customBindReq =
{
  .srcEndpoint       = APP_ENDPOINT_CUSTOM,
  .remoteServersCnt  = ARRAY_SIZE(customClientClusterToBindIds),
  .remoteClientsCnt  = ARRAY_SIZE(customServerClusterToBindIds),
  .groupId           = 0xffff,
  .remoteServers     = customClientClusterToBindIds,
  .remoteClients     = customServerClusterToBindIds,
  .callback          = customFindingBindingFinishedForACluster,
  .startIdentifyingFn= customIdetifyStartIdentifyingCb
};

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void appDeviceInit(void)
{

#if APP_ENABLE_CONSOLE == 1
  initConsole();
#endif

  LCD_INIT();


  LCD_PRINT(0, 1, "Custom Device");

  if (!APP_RegisterEndpoint(&customEndpoint, &customBindReq))
    return;

  ZCL_CommandManagerInit();
  customBasicClusterInit();
  customIdentifyClusterInit();
  customGroupsClusterInit();
  customScenesClusterInit();
  customCommissioningClusterInit();

#ifdef OTAU_CLIENT
  customAddOTAUClientCluster();
#endif //OTAU_CLIENT

#ifdef _ENABLE_PERSISTENT_SERVER_
  if (PDS_IsAbleToRestore(APP_CUSTOM_SCENES_MEM_ID))
    PDS_Restore(APP_CUSTOM_SCENES_MEM_ID);
#endif
  /**CHANGE* - cluster version need to be reinitilized here after PDS Restore same for all devices
    implement a common function to reinitilized */
  customArmorientationcluster0Init();
}

/**************************************************************************//**
\brief Callback about confguring image key on EEPROM
******************************************************************************/
#ifdef OTAU_CLIENT
static void configureImageKeyDone(void)
{
  return;
}
#endif

/**************************************************************************//**
\brief Device common task handler
******************************************************************************/
void appDeviceTaskHandler(void)
{
  switch (appDeviceState) // Actual device state when one joined network
  {
    case DEVICE_INITIAL_STATE:
      {
        appDeviceState = DEVICE_ACTIVE_IDLE_STATE;
      }
#ifdef OTAU_CLIENT
      startOtauClient();
#endif
      break;
    case DEVICE_ACTIVE_IDLE_STATE:
    default:
      break;
  }
}

/*******************************************************************************
\brief callback called on the finishing of binding of one cluster
********************************************************************************/
static void customFindingBindingFinishedForACluster(Endpoint_t ResponentEp, ClusterId_t clusterId)
{
  ZCL_Cluster_t *serverCluster;
  switch(clusterId)
  {
    case ONOFF_CLUSTER_ID:
      serverCluster = ZCL_GetCluster(APP_ENDPOINT_CUSTOM, ONOFF_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
      if (serverCluster)
#ifdef _ZCL_REPORTING_SUPPORT_
#if (ZB_COMMISSIONING_ON_STARTUP == 1)
        sendConfigureReportingToNotify(APP_ENDPOINT_CUSTOM, 0, ONOFF_CLUSTER_ID,
                                     ZCL_ONOFF_CLUSTER_ONOFF_SERVER_ATTRIBUTE_ID, ONOFF_VAL_MAX_REPORT_PERIOD,
                                     customConfigureReportingResp);
#else
        ZCL_StartReporting();
#endif
#endif
      break;
    case LEVEL_CONTROL_CLUSTER_ID:
       serverCluster = ZCL_GetCluster(APP_ENDPOINT_CUSTOM, LEVEL_CONTROL_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
       if (serverCluster)
#if (ZB_COMMISSIONING_ON_STARTUP == 1)
#ifdef _ZCL_REPORTING_SUPPORT_
         sendConfigureReportingToNotify(APP_ENDPOINT_CUSTOM, 0,
                                      LEVEL_CONTROL_CLUSTER_ID,ZCL_LEVEL_CONTROL_CLUSTER_CURRENT_LEVEL_ATTRIBUTE_ID,
                                      LEVEL_CONTROL_VAL_MAX_REPORT_PERIOD, customConfigureReportingResp);
#endif
#else
       ZCL_StartReporting();
#endif

      break;
      case ARMORIENTATIONCLUSTER0_CLUSTER_ID:       //sankar
          ZCL_StartReporting();     //sankar
          printf("FB Done\r\n");    //sankar
          break;
    default:
       ZCL_StartReporting();
      break;


  }

}

#if (ZB_COMMISSIONING_ON_STARTUP == 1)
#ifdef _ZCL_REPORTING_SUPPORT_
/**************************************************************************//**
\brief Indication of configure reporting response

\param[in] ntfy - pointer to response
******************************************************************************/
static void customConfigureReportingResp(ZCL_Notify_t *ntfy)
{
  ZCL_StartReporting();
  (void)ntfy;
}
#endif
#endif
/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStart(uint16_t identifyTime, bool colorEffect, uint16_t enhancedHue)
{
  customIdentifyStart(identifyTime, colorEffect, enhancedHue);
}

/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStop(void)
{
  customIdentifyStop();
}

#ifdef OTAU_CLIENT 
/**************************************************************************//**
\brief Adds OTAU client cluster to list of clients clusters of custom devices
******************************************************************************/
static void customAddOTAUClientCluster(void)
{
  customClientClusters[CUSTOM_CLIENT_CLUSTERS_COUNT - 1U] = ZCL_GetOtauClientCluster();
}
#endif // OTAU_CLIENT

#endif // APP_DEVICE_TYPE_CUSTOM_DEVICE
// eof custom.c
