/*******************************************************************************
  Combined Interface Source File

  Company:
    Microchip Technology Inc.

  File Name:
    combinedInterface.c

  Summary:
    This file contains the Combined Interface interface.

  Description:
    This file contains the Combined Interface interface.
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
#include <z3device/combinedInterface/include/ciClusters.h>
#include <z3device/combinedInterface/include/ciIdentifyCluster.h>
#include <z3device/combinedInterface/include/ciOnOffCluster.h>
#include <z3device/combinedInterface/include/ciLevelControlCluster.h>
#include <z3device/combinedInterface/include/ciCommissioningCluster.h>
#include <z3device/combinedInterface/include/ciBasicCluster.h>
#include <z3device/combinedInterface/include/ciGroupsCluster.h>
#include <z3device/combinedInterface/include/ciOccupancySensingCluster.h>
#include <z3device/combinedInterface/include/ciIlluminanceMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciScenesCluster.h>
#include <zcl/clusters/include/identifyCluster.h>
#include <z3device/clusters/include/basicCluster.h>
#include <z3device/common/include/z3Device.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/zclSecurityManager.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/common/include/otauService.h>
#include <mac_phy/include/mac.h>
#include <z3device/combinedInterface/include/ciTemperatureMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciHumidityMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciColorControlCluster.h>
#include <z3device/combinedInterface/include/ciThermostatCluster.h>
#include <z3device/combinedInterface/include/ciTimeCluster.h>
#include <z3device/combinedInterface/include/ciIasACECluster.h>
#include <z3device/combinedInterface/include/ciIasZoneCluster.h>
#include <z3device/combinedInterface/include/ciArmcluster0Cluster.h>

#ifdef OTAU_SERVER
#include <zcl/include/zclOTAUCluster.h>
#endif

/*******************************************************************************
                    Static functions section
*******************************************************************************/
#ifdef OTAU_SERVER
static void ciAddOTAUServerCluster(void);
#endif //OTAU_SERVER
/******************************************************************************
                    Local variables section
******************************************************************************/
static ZCL_DeviceEndpoint_t ciEndpoint =
{
  .simpleDescriptor =
  {
    .endpoint            = APP_ENDPOINT_COMBINED_INTERFACE,
    .AppProfileId        = PROFILE_ID_HOME_AUTOMATION,
    .AppDeviceId         = HA_COMBINED_INTERFACE_ID,
    .AppDeviceVersion    = 0x1,
    .AppInClustersCount  = ARRAY_SIZE(ciServerClusterIds),
    .AppInClustersList   = ciServerClusterIds,
    .AppOutClustersCount = ARRAY_SIZE(ciClientClusterIds),
    .AppOutClustersList  = ciClientClusterIds,
  },
  .serverCluster = ciServerClusters,
  .clientCluster = ciClientClusters,
};

static ClusterId_t ciClientClusterToBindIds[] =
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
  COLOR_CONTROL_CLUSTER_ID,
  IAS_ZONE_CLUSTER_ID,
  ARMCLUSTER0_CLUSTER_ID,       //sankar
};

static ClusterId_t ciServerClusterToBindIds[] =
{
  BASIC_CLUSTER_ID,
  IDENTIFY_CLUSTER_ID,
  GROUPS_CLUSTER_ID,
  IAS_ACE_CLUSTER_ID,
  ARMCLUSTER0_CLUSTER_ID,
};

static AppBindReq_t ciBindReq =
{
  .remoteServers     = ciClientClusterToBindIds,
  .remoteServersCnt  = ARRAY_SIZE(ciClientClusterToBindIds),
  .remoteClients     = ciServerClusterToBindIds,
  .remoteClientsCnt  = ARRAY_SIZE(ciServerClusterToBindIds),
  .groupId           = 0xffff,
  .srcEndpoint       = APP_ENDPOINT_COMBINED_INTERFACE,
  .callback          = NULL,
  .startIdentifyingFn= ciIdetifyStartIdentifyingCb
};


static ZCL_LinkKeyDesc_t lightKeyDesc = {CCPU_TO_LE64(APS_UNIVERSAL_EXTENDED_ADDRESS), HA_LINK_KEY};

/******************************************************************************
                        Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void appDeviceInit(void)
{
#if APP_ENABLE_CONSOLE == 1
  initConsole();
#endif
  /* Initialize the LCD screen */
#if BSP_SUPPORT == BOARD_SAMR21_ZLLEK
  LCD_INIT();
#endif

  LCD_PRINT(0, 1, "Combined Interface");

  APP_RegisterEndpoint(&ciEndpoint, &ciBindReq);

  ZCL_CommandManagerInit();
  ciBasicClusterInit();
  ciIdentifyClusterInit();
  ciOnOffClusterInit();
  ciLevelControlClusterInit();
  ciGroupsClusterInit();
  ciScenesClusterInit();
  ciOccupancySensingClusterInit();
  ciIlluminanceMeasurementClusterInit();
  ciTemperatureMeasurementClusterInit();
  ciHumidityMeasurementClusterInit();
  ciCommissioningClusterInit();
  ciColorControlClusterInit();
  ciThermostatClusterInit();
  ciTimeClusterInit();
  ciIasACEClusterInit();
  ciIasZoneClusterInit();
  ciArmcluster0Init();           //sankar

#ifdef OTAU_SERVER
  ciAddOTAUServerCluster();
  startOtauServer();
#endif //OTAU_SERVER
}

/**************************************************************************//**
\brief Performs security initialization actions
******************************************************************************/
void appSecurityInit(void)
{
  ZCL_Set_t zclSet;
  ExtAddr_t trustCenterAddress;
  ExtAddr_t macAddr;
  APS_TcMode_t tcMode;
  DeviceType_t deviceType;
  // Setup security parameters
  bool securityOn;

  CS_ReadParameter(CS_SECURITY_ON_ID, &securityOn);
  if (securityOn)
  {
    uint8_t preconfiguredStatus;
    CS_ReadParameter(CS_APS_TRUST_CENTER_ADDRESS_ID, &trustCenterAddress);
    CS_ReadParameter(CS_UID_ID, &macAddr);
    if (IS_EQ_EXT_ADDR(macAddr, trustCenterAddress))
      tcMode = APS_CENTRALIZED_TRUST_CENTER;
    else
      tcMode = APS_NOT_TRUST_CENTER;

    CS_ReadParameter(CS_ZDO_SECURITY_STATUS_ID, &preconfiguredStatus);
    CS_ReadParameter(CS_DEVICE_TYPE_ID, &deviceType);

    if ((PRECONFIGURED_NETWORK_KEY == preconfiguredStatus)
      || (APS_CENTRALIZED_TRUST_CENTER == tcMode)
    )
    {
      uint8_t nwkDefaultKey[SECURITY_KEY_SIZE];

      CS_ReadParameter(CS_NETWORK_KEY_ID, &nwkDefaultKey);
      NWK_SetKey(nwkDefaultKey, NWK_STARTUP_ACTIVE_KEY_SEQUENCE_NUMBER);
      NWK_ActivateKey(NWK_STARTUP_ACTIVE_KEY_SEQUENCE_NUMBER);
    }
  }

  ZCL_ResetSecurity();

  //Setting the Link Key Descriptor
  zclSet.attr.id = ZCL_LINK_KEY_DESC_ID;
  zclSet.attr.value.linkKeyDesc = &lightKeyDesc;
  ZCL_Set(&zclSet);
}

/**************************************************************************//**
\brief Device common task handler
******************************************************************************/
void appDeviceTaskHandler(void)
{
 /* Do nothing */
}

#ifdef OTAU_SERVER
/**************************************************************************//**
\brief Adds OTAU server cluster to list of clients clusters of combined
       interface device
******************************************************************************/
static void ciAddOTAUServerCluster(void)
{
  ciServerClusters[CI_SERVER_CLUSTERS_COUNT - 1] = ZCL_GetOtauServerCluster();
}
#endif //OTAU_SERVER

/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStart(uint16_t identifyTime, bool colorEffect, uint16_t enhancedHue)
{
  ciIdentifyStart(identifyTime);
  (void)colorEffect,(void)enhancedHue;
}

/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStop(void)
{
  ciIdentifyStop();
}

#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE
// eof combinedInterface.c
