/*******************************************************************************
  Application Zigbee configuration File

  Company:
    Microchip Technology Inc.

  File Name:
    zigbeeAppConfig.h

  Summary:
    This file contains the Application Zigbee configuration.

  Description:
    This file contains the Application Zigbee configuration.
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

#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

#if !defined _USE_LIB_ || defined _SUPER_SET_LIB_
#include "zigbeeAppDeviceSelect.h" 
#endif
//-----------------------------------------------
// Includes Application specific Configurations.
//-----------------------------------------------
#ifndef _PIC32CX_
#define _PIC32CX_
#endif

#ifndef _USE_RTOS_
#define _USE_RTOS_  // Needed for RTOS specifc atomic implementation
#endif

#ifdef _USE_LIB_

#ifndef CPU_CLK_HZ
//#define CPU_CLK_HZ              64000000  // Core Clock
#define CPU_CLK_HZ              48000000  // Core Clock
#endif

#endif


#define APB_CLK_HZ              CPU_CLK_HZ // Peripheral Frequency
 
/* Hardware Board Definitions - Do Not Change*/
#define BOARD_PIC32CX          1
#define BOARD_FAKE             2

/* Select BSP */
#define BSP_SUPPORT                 BOARD_PIC32CX

// Enables or disables support for OTA Upgrade.
#define APP_USE_OTAU 0

#ifndef TRNG_MODULE_ENABLED
#define TRNG_MODULE_ENABLED
#endif

#ifdef _USE_LIB_

/* Application Device Types Definitions - Do Not Change */
#define APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER  1
#define APP_DEVICE_TYPE_MULTI_SENSOR            2
#define APP_DEVICE_TYPE_COMBINED_INTERFACE      3
#define APP_DEVICE_TYPE_THERMOSTAT              4
#define APP_DEVICE_TYPE_IAS_ACE                 5
#define APP_DEVICE_TYPE_ON_OFF_LIGHT            10
#define APP_DEVICE_TYPE_DIMMABLE_LIGHT          11
#define APP_DEVICE_TYPE_COLOR_LIGHT             12
#define APP_DEVICE_TYPE_EXTENDED_COLOR_LIGHT    13
#define APP_DEVICE_TYPE_TEMPERATURE_COLOR_LIGHT 14

#define APP_ZGP_DEVICE_TYPE_NONE                0
#define APP_ZGP_DEVICE_TYPE_PROXY_BASIC         1
#define APP_ZGP_DEVICE_TYPE_COMBO_BASIC         2

#else

#define  ZIGBEE_COORDINATOR

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE)
#if !defined(ZIGBEE_COORDINATOR)
#warning " Select ZIGBEE_COORDINATOR in library bitcloudPreInclude.h"
#endif
#endif

#define MICROCHIP_APPLICATION_SUPPORT 1

#endif //#ifdef _USE_LIB_

// Specifies the number of join retries the device perform on join failure
#define APP_JOIN_ATTEMPTS_AMOUNT    3

// Specifies the frequency (in sec) of join retries on join failure
#define APP_JOIN_ATTEMPT_INTERVAL   3

// Specifies maximum number of scenes that can be stored
#define MAX_SCENES_AMOUNT 16u

#define APP_ENABLE_CONSOLE 1

// Enable/disable BDB specific commands in console
#define BDB_COMMANDS_IN_CONSOLE 1

// Enable/disable Cluster specific commands in console
#define ZCL_COMMANDS_IN_CONSOLE 1

// Enable or disable extra client or server clusters
#define ZLO_EXTRA_CLUSTERS_SUPPORT 1

// Enable or disable optional attributes support for clusters
#define ZLO_CLUSTER_ENHANCEMENTS 1

// Enable/disable ZDO specific commands in console
#define ZDO_COMMANDS_IN_CONSOLE 1

// Enable/disable Commissioining specific commands in console
#define COMMISSIONING_COMMANDS_IN_CONSOLE 1

#if APP_ENABLE_CONSOLE == 1
// Specifies if logging enabled
#define APP_DEVICE_EVENTS_LOGGING 0
#else
#define APP_DEVICE_EVENTS_LOGGING 0
#endif

#define _ENABLE_PERSISTENT_SERVER_

//-----------------------------------------------
//APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR
//-----------------------------------------------
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)
  /* Enable Different Sensor Type under Multi-Sensor */
#define APP_SENSOR_TYPE_OCCUPANCY_SENSOR    //Occupancy Sensor Device.
#define APP_SENSOR_TYPE_LIGHT_SENSOR        //Light Sensor Device.
#define APP_SENSOR_TYPE_HUMIDITY_SENSOR     // Humidity Sensor.
#define APP_SENSOR_TYPE_TEMPERATURE_SENSOR  // Temperature Sensor.
#endif

// Specifies Commissioning on startup is enabled or disabled
#define ZB_COMMISSIONING_ON_STARTUP 0

/* Enable/Disable AutoEnrollResponse for IAS*/
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_IAS_ACE)
//#define IAS_ZONE_AUTO_ENROLL_REQUEST_ENABLE
#endif

/* Enable/Define Zone Table Size */
#define APP_IAS_ZONE_TYPE_ATTRIBUTE_VALUE  0x000D

// Select ZGP Infra device type: proxyBasic/comboBasic
#define APP_ZGP_DEVICE_TYPE  APP_ZGP_DEVICE_TYPE_NONE

//#define APP_ZGP_DEVICE_TYPE APP_ZGP_DEVICE_TYPE_NONE
//#define APP_ZGP_DEVICE_TYPE APP_ZGP_DEVICE_TYPE_PROXY_BASIC
//#define APP_ZGP_DEVICE_TYPE APP_ZGP_DEVICE_TYPE_COMBO_BASIC

//#define   _GREENPOWER_SUPPORT_
//#define   ZGP_SECURITY_ENABLE

//-----------------------------------------------
//APP_ZGP_DEVICE_TYPE != APP_ZGP_DEVICE_TYPE_NONE
//-----------------------------------------------
#if (APP_ZGP_DEVICE_TYPE != APP_ZGP_DEVICE_TYPE_NONE)
  // Enables or disables zgp certification testing extension
  #define APP_ENABLE_ZGP_CERTIFICATION_EXTENSION 0
  //#define APP_ENABLE_ZGP_CERTIFICATION_EXTENSION 1
  
  // Enables ZGP task handler
   #define _SYS_ZGP_TASK_
  
  // Configures ZGP proxy table. Minimum size should be 5
  #define ZGP_PROXY_TABLE_SIZE 5
  
  // Configures ZGP sink table. Minimum size should be 5.
  #define ZGP_SINK_TABLE_SIZE 5
  
  // Configures ZGP dstub buffer based on no.of ZGPDs in the network.
  #define ZGP_DSTUB_BUFFERS_AMOUNT 3
  
  // Enabling the switch excludes the Application code specific to translation table 
  #if (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
  #define ZGP_DISABLE_TRANSLATION_TABLE
  #else
  //#define ZGP_DISABLE_TRANSLATION_TABLE
  #endif
  
  // Enabling the switch excludes the Application code specific to ZGP Generic
  // 8-contact switch device support
  //#define ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT

  // Enabling the switch excludes the Application code specific to translation table
#define ZGP_ENABLE_MULTI_SENSOR_SUPPORT

//#define ZGP_ENABLE_MULTI_SENSOR_SUPPORT
  
  // Enabling manufacturer specific cmd/cluster handling in sink
  //#define ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING
  
  // Enabling the switch requests APS_ACK for all the zgpClusterCommands sent out
  #define ZGP_CMD_ENABLE_APS_ACK
#endif //

/* End device reconnection timeout in seconds during parent loss. 
   This value should be greater than the nwk discovery Time that depends
   on the operaing channel masks and scan duration */
#if defined(ZIGBEE_END_DEVICE)
#define N_END_DEVICE_ROBUSTNESS_RECONNECTION_TIMEOUT   2u
#endif

//-----------------------------------------------
//ZB_COMMISSIONING_ON_STARTUP != 0
//-----------------------------------------------
#if (ZB_COMMISSIONING_ON_STARTUP != 0)
#define APP_COMMISSIONING_FORMING 1
  
#define APP_COMMISSIONING_TOUCHLINK 0

#define APP_COMMISSIONING_STEERING 1

#define APP_COMMISSIONING_FINDING_AND_BINDING 1
#endif

#define CS_RF_TX_POWER   3
#define CS_TX_ANTENNA_GAIN    3

#ifndef _USE_LIB_
/* Bit Cloud Configurations*/
#include <zigbee/z3device_configs/bitcloudPreInclude.h>
#endif
#include <zigbee/z3device_configs/stackConfig.h>
#endif // _APP_CONFIG_H_
