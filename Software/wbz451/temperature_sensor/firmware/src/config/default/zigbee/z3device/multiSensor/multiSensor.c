/*******************************************************************************
  multisensor source File

  Company:
    Microchip Technology Inc.

  File Name:
    multisensor.c

  Summary:
    This file contains the multisensor interface.

  Description:
    This file contains the multisensor interface.
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

/******************************************************************************
                             Includes section
******************************************************************************/
#include <stdio.h>
#include <z3device/clusters/include/haClusters.h>
#include <z3device/common/include/appConsts.h>
#include <z3device/common/include/z3Device.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/zclSecurityManager.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/clusters/include/identifyCluster.h>
#include <systemenvironment/include/sysIdleHandler.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/otauService.h>
#include <hal/include/sleep.h>
#include <z3device/multiSensor/include/osOccupancySensingCluster.h>
#include <z3device/multiSensor/include/lsIlluminanceMeasurementCluster.h>
#include <z3device/multiSensor/include/tsTemperatureMeasurementCluster.h>
#include <z3device/multiSensor/include/hsHumidityMeasurementCluster.h>
#include <z3device/clusters/include/basicCluster.h>
#include <zcl/include/zclCommandManager.h>
#ifdef OTAU_CLIENT
#include <zcl/include/zclOtauManager.h>
#endif
#include <z3device/multiSensor/include/msClusters.h>


/******************************************************************************
                             Defines section
******************************************************************************/
#define SWITCHING_PERIOD                    20000UL

/******************************************************************************
                        Prototypes section
******************************************************************************/
static void isBusyOrPollCheck(SYS_EventId_t eventId, SYS_EventData_t data);

#ifdef OTAU_CLIENT 
static void configureImageKeyDone(void);
static void msAddOTAUClientCluster(void);
#endif
//#if ZB_COMMISSIONING_ON_STARTUP == 1 
static void updateSensorsAttributeValues(void);
//#endif
/******************************************************************************
                    Local variables section
******************************************************************************/
#if APP_USE_OTAU == 1
static ZCL_DeviceEndpoint_t msEndpoint =
{
  .simpleDescriptor =
  {
    .endpoint            = APP_ENDPOINT_MULTI_SENSOR,
    .AppProfileId        = PROFILE_ID_HOME_AUTOMATION,
    .AppDeviceId         = APP_Z3_MULTI_SENSOR_DEVICE_ID,
    .AppInClustersCount  = 0,
    .AppInClustersList   = NULL,
    .AppOutClustersCount = ARRAY_SIZE(msClientClusterIds),
    .AppOutClustersList  = msClientClusterIds,
  },
  .serverCluster = NULL,
  .clientCluster = msClientClusters,
};
#endif  /* APP_USE_OTAU */
//#if ZB_COMMISSIONING_ON_STARTUP == 1 
static HAL_AppTimer_t sensorAttributeUpdateTimer =
{
  .interval = SWITCHING_PERIOD,
  .mode     = TIMER_REPEAT_MODE,
  .callback = updateSensorsAttributeValues,
};
//#endif
static SYS_EventReceiver_t zdoBusyPollCheck = { .func = isBusyOrPollCheck};


/******************************************************************************
                   type(s) section
******************************************************************************/

/******************************************************************************
                    Static functions section
******************************************************************************/
static void APP_RestoreZCLAttributes(void);

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void appDeviceInit(void)
{
    
  uint8_t deepSleepWakeupSrc = 0U;
  /* OTAU cluster is common cluster to all endpoint and resides on the ms endpoint */
#if APP_USE_OTAU == 1
  ZCL_RegisterEndpoint(&msEndpoint);
#endif

#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
  osDeviceInit();
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
  lsDeviceInit();
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
  tsDeviceInit();
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
  hsDeviceInit();
#endif

#ifdef OTAU_CLIENT
  msAddOTAUClientCluster();
#endif //OTAU_CLIENT

  ZCL_CommandManagerInit();

  CS_ReadParameter(CS_DEVICE_DEEP_SLEEP_WAKEUP_SRC_ID, &deepSleepWakeupSrc);

  /* Execute only if it is wakenup from deep sleep. */
  if(deepSleepWakeupSrc > 0U)
    APP_RestoreZCLAttributes();

#if APP_ENABLE_CONSOLE == 1
  initConsole();
#endif

  /* Initialize the LCD screen */
  LCD_INIT();
  LCD_PRINT(0, 1, "MultiSensor");
  /* Timer update the attribute values of various sensor types */
//#if ZB_COMMISSIONING_ON_STARTUP == 1  
  HAL_StartAppTimer(&sensorAttributeUpdateTimer); //to test longer deep sleep intervals >20secs
//#endif
#if defined (_SLEEP_WHEN_IDLE_)
#if (ZB_COMMISSIONING_ON_STARTUP == 1)
  SYS_EnableSleepWhenIdle();
#endif
#endif
  SYS_SubscribeToEvent(BC_EVENT_POLL_REQUEST, &zdoBusyPollCheck);
}

/**************************************************************************//**
\brief Callback about confguring image key on EEPROM
******************************************************************************/
#ifdef OTAU_CLIENT
static void configureImageKeyDone(void)
{}
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
#ifdef OTAU_CLIENT
        startOtauClient();
#endif
      }
      break;
    case DEVICE_ACTIVE_IDLE_STATE:
    default:
      break;
  }
}
/**************************************************************************//**
\brief backup ZCL attributes
******************************************************************************/
void APP_BackupZCLAttributes(void)
{
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
    osBackupOsAttributes();
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
    tsBackupTsAttributes();
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR    
    lsBackupLsAttributes();
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
    hsBackupHsAttributes();
#endif
}
/**************************************************************************//**
\brief Restore ZCL attributes
******************************************************************************/
static void APP_RestoreZCLAttributes(void)
{
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
    osRestoreOsAttributes();
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
    tsRestoreTsAttributes();
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR    
    lsRestoreLsAttributes();
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
    hsRestoreHsAttributes();
#endif    
       
}
//#if ZB_COMMISSIONING_ON_STARTUP == 1  
/**************************************************************************//**
\brief Periodic update of various attributes of different sensors
*****************************************************************************/
static void updateSensorsAttributeValues(void)
{
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
  occupancySensingToggleOccupancy();
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
  illuminanceMeasurementUpdateMeasuredValue();
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
  extern uint16_t APP_temphum13_get_temperature( void );
  uint16_t temperature = APP_temphum13_get_temperature();
  printf("Temperature: %d.%d\r\n",temperature/100, temperature%100);
  tempeartureMeasurementUpdateMeasuredValue(temperature);
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
  humidityMeasurementUpdateMeasuredValue();
#endif
}
//#endif
/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStart(uint16_t identifyTime, bool colorEffect, uint16_t enhancedHue)
{
#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
  lsIdentifyStart(identifyTime);
#endif
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
  osIdentifyStart(identifyTime);
#endif
#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
  tsIdentifyStart(identifyTime);
#endif
#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
  hsIdentifyStart(identifyTime);
#endif
  (void)colorEffect, (void)enhancedHue;
}

/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStop(void)
{
#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
  lsIdentifyStop();
#endif
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
  osIdentifyStop();
#endif
#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
  tsIdentifyStop();
#endif
#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
  hsIdentifyStop();
#endif
}

#ifdef OTAU_CLIENT
/**************************************************************************//**
\brief Adds OTAU client cluster to list of clients clusters of multisensor 
       device.
******************************************************************************/
static void msAddOTAUClientCluster(void)
{
  msClientClusters[MS_CLIENT_CLUSTERS_COUNT - 1U] = ZCL_GetOtauClientCluster(); 
}
#endif // OTAU_CLIENT

/**************************************************************************//**
  \brief Processes BC_EVENT_POLL_REQUEST event

  \param[in] eventId - id of raised event;
  \param[in] data    - event's data.
******************************************************************************/
static void isBusyOrPollCheck(SYS_EventId_t eventId, SYS_EventData_t data)
{
#if defined (_SLEEP_WHEN_IDLE_)
  bool *check = (bool *)data;

  if (BC_EVENT_POLL_REQUEST == eventId)
    *check |= isCommssioiningInProgress();
#else
  (void)eventId, (void)data;
#endif
}

#endif // APP_DEVICE_TYPE_MULTI_SENSOR
// eof multiSensor.c