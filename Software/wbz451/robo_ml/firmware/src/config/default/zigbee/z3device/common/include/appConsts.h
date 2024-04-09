/*******************************************************************************
  Application Constants Header File

  Company:
    Microchip Technology Inc.

  File Name:
    appConst.h

  Summary:
    This file contains the Application Devices related definition.

  Description:
    This file contains the Application Devices related definition.
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

#ifndef _APPCONSTS_H
#define _APPCONSTS_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zdo/include/appFramework.h>
#include <zcl/include/zcl.h>
#include <pds/include/wlPdsMemIds.h>
/******************************************************************************
                    Defines section
******************************************************************************/
#define APP_VERSION                              0x01 // manufacturer-defined
#define APP_PROFILE_ID                           PROFILE_ID_HOME_AUTOMATION
#define CLUSTER_VERSION                          1 // default value specified in ZCL r6
#define ZCL_VERSION                              8 // as specified in ZCL r7
#define HW_VERSION                               1 // manufacturer-defined
#define POWER_SOURCE                             4 // DC source (as in EKs - for testing)
#define UNKNOWN_ENVIRONMENT                      0xff // unknown
#define STACK_VERSION                            0x03

#define BASIC_CLUSTER_VERSION                    3
#define COLOR_CONTROL_CLUSTER_VERSION            3
#define COMMISSIONING_CLUSTER_VERSION            2
#define IDENTIFY_CLUSTER_VERSION                 2
#define GROUPS_CLUSTER_VERSION                   3
#define LEVEL_CONTROL_CLUSTER_VERSION            3
#define ONOFF_CLUSTER_VERSION                    2
#define SCENES_CLUSTER_VERSION                   3
#define ALARM_CLUSTER_VERSION                    1
#define FAN_CONTROL_CLUSTER_VERSION              1
#define HUMIDITY_MEASUREMENT_CLUSTER_VERSION     2
#define ACE_CLUSTER_VERSION                      1
#define ZONE_CLUSTER_VERSION                     2
#define ILLUMINANCE_MEASUREMENT_CLUSTER_VERSION  2
#define OCCUPANCY_CLUSTER_VERSION                2
#define TEMPERATURE_MEASUREMENT_CLUSTER_VERSION  3
#define THERMOSTAT_CLUSTER_VERSION               3
#define THERMOSTAT_UI_CONF_CLUSTER_VERSION       1
#define TIME_CLUSTER_VERSION                     2

#define LIGHTING_DEVICE_CLASS                    0x00 // lighting device

// Table 68 â?? Values of the GenericDeviceType attribute for the lighting class form
// ZigBee Lighting & Occupancy Device Specification, v0.9
// ZigBee Document 15-0014-04, December 4th, 2015
#define INCANDESCENT_DEVICE_TYPE                             0x00
#define SPOTLIGHT_HALOGEN_DEVICE_TYPE                        0x01
#define HALOGEN_BULB_DEVICE_TYPE                             0x02
#define	CFL_DEVICE_TYPE                                      0x03
#define	LINEAR_FLUORESCENT_DEVICE_TYPE                       0x04
#define	LED_BULB_DEVICE_TYPE                                 0x05
#define	SPOTLIGHT_LED_DEVICE_TYPE                            0x06
#define	LED_STRIP_DEVICE_TYPE                                0x07
#define	LED_TUBE_DEVICE_TYPE                                 0x08
#define	GENERIC_INDOOR LUMINAIRE_LIGHT_FIXTURE_DEVICE_TYPE   0x09
#define	GENERIC_OUTDOOR_LUMINAIRE_LIGHT_FIXTURE_DEVICE_TYPE  0x0A
#define	PENDANT_LUMINAIRE_LIGHT_FIXTURE_DEVICE_TYPE          0x0B
#define	FLOOR_STANDING_LUMINAIRE_LIGHT_FIXTURE_DEVICE_TYPE   0x0C
#define	GENERIC_CONTROLLER_REMOTE_CONTROLLER_DEVICE_TYPE     0xE0
#define	WALL_SWITCH_DEVICE_TYPE                              0xE1
#define	PORTABLE_REMOTE_CONTROLLER_DEVICE_TYPE               0xE2
#define	MOTION_SENSOR_LIGHT_SENSOR_DEVICE_TYPE               0xE3
#define	GENERIC_ACTUATOR_DEVICE_TYPE                         0xF0
#define	WALL_SOCKET_DEVICE_TYPE                              0xF1
#define	GATEWAY_BRIDGE_DEVICE_TYPE                           0xF2
#define	PLUG_IN_UNIT_DEVICE_TYPE                             0xF3
#define	RETROFIT_ACTUATOR_DEVICE_TYPE                        0xF4
#define	UNSPECIFIED_DEVICE_TYPE                              0xFF


/* Test Zigbee device types  */
/* This value used in BDB and ZLO tests to identify Coordinator */
#define TEST_DEVICE_TYPE_ZIGBEE_COORDINATOR 0x02U
/* This value used in BDB and ZLO tests to identify Router */
#define TEST_DEVICE_TYPE_ZIGBEE_ROUTER      0x03U
/* This value used in BDB and ZLO tests to identify End Device */
#define TEST_DEVICE_TYPE_ZIGBEE_END_DEVICE  0x04U
/* This value used in ZGP tests to identify TH(combo basic Device with certification support) */
#define TEST_DEVICE_TYPE_ZGP_TH             0x07U
/* This value used in ZGP tests to identify combo basic Device */
#define TEST_DEVICE_TYPE_ZGP_COMBO_BASIC    0x08U

#define APP_ENDPOINT_COMBINED_INTERFACE          0x14
#define APP_ENDPOINT_MULTI_SENSOR                0x15
#define APP_ENDPOINT_OCCUPANCY_SENSOR            0x13
#define APP_ENDPOINT_TEMPERATURE_SENSOR          0x16
#define APP_ENDPOINT_HUMIDITY_SENSOR             0x17
#define APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR 0x18
#define APP_ENDPOINT_THERMOSTAT                  0x19
#define APP_ENDPOINT_IAS_ACE                     0x1A

#define APP_ENDPOINT_ON_OFF_LIGHT                0x20
#define APP_ENDPOINT_DIMMABLE_LIGHT              0x21
#define APP_ENDPOINT_COLOR_LIGHT                 0x22
#define APP_ENDPOINT_EXTENDED_COLOR_LIGHT        0x23
#define APP_ENDPOINT_TEMPERATURE_COLOR_LIGHT     0x24
#define APP_ENDPOINT_COLOR_SCENE_CONTROLLER      0x26

#define APP_ENDPOINT_CUSTOM                      0x30

/* Light Specific Devices */
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_ON_OFF_LIGHT)
  #define APP_Z3DEVICE_ID      ZLO_ON_OFF_LIGHT_DEVICE_ID
  #define APP_ENDPOINT_LIGHT   APP_ENDPOINT_ON_OFF_LIGHT

#elif APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_DIMMABLE_LIGHT
  #define APP_Z3DEVICE_ID      ZLO_DIMMABLE_LIGHT_DEVICE_ID
  #define APP_ENDPOINT_LIGHT   APP_ENDPOINT_DIMMABLE_LIGHT

#elif APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_LIGHT
  #define APP_Z3DEVICE_ID      ZLO_COLOR_DIMMABLE_LIGHT_DEVICE_ID
  #define APP_ENDPOINT_LIGHT   APP_ENDPOINT_COLOR_LIGHT

#elif APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_EXTENDED_COLOR_LIGHT
  #define APP_Z3DEVICE_ID      ZLO_EXTENDED_COLOR_LIGHT_DEVICE_ID
  #define APP_ENDPOINT_LIGHT   APP_ENDPOINT_EXTENDED_COLOR_LIGHT

#elif APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_TEMPERATURE_COLOR_LIGHT
  #define APP_Z3DEVICE_ID      ZLO_COLOR_TEMPERATURE_LIGHT_DEVICE_ID
  #define APP_ENDPOINT_LIGHT   APP_ENDPOINT_TEMPERATURE_COLOR_LIGHT

#elif APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER
  #define APP_Z3DEVICE_ID      ZLO_COLOR_SCENE_CONTROLLER_DEVICE_ID
  #define APP_ENDPOINT_LIGHT   APP_ENDPOINT_COLOR_SCENE_CONTROLLER
#endif

// Organize device-related definitions and check device type setting.
// Usually this section shall not be changed by user.
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE)
#define APP_DEVICE_TYPE       DEV_TYPE_ENDDEVICE
#define APP_SRC_ENDPOINT_ID      APP_ENDPOINT_CUSTOM
#define APP_Z3DEVICE_ID          ZLO_CUSTOM_DEVICE_ID
#define APP_ENDPOINTS_AMOUNT         1

#elif (APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_ON_OFF_LIGHT)
  // ZigBee Device Type
  #define APP_DEVICE_TYPE       DEV_TYPE_ENDDEVICE
  // Source Endpoint Identifier
  #define APP_SRC_ENDPOINT_ID   APP_ENDPOINT_LIGHT
  // Endpoint count
  #define APP_ENDPOINTS_AMOUNT  1u
  // LED driving method
  #define APP_USE_PWM
  // Red channel
  #define ENABLE_DITHERING_A    0u
  //#define ENABLE_DITHERING_A    1u
  // Green channel
  #define ENABLE_DITHERING_B    0u
  //#define ENABLE_DITHERING_B    1u
  // Blue channel
  #define ENABLE_DITHERING_C    0u
  //#define ENABLE_DITHERING_C    1u
  // PWM frequency in Hz
#if (ZB_COMMISSIONING_ON_STARTUP == 0)
  #define APP_PWM_FREQUENCY     900u
#else
  #define APP_PWM_FREQUENCY     22000u
#endif

#elif (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)
  #define APP_DEVICE_TYPE DEV_TYPE_ENDDEVICE
  #define APP_SRC_ENDPOINT_ID  APP_ENDPOINT_MULTI_SENSOR
  #ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
    #define APP_SRC_ENDPOINT1_ID APP_ENDPOINT_OCCUPANCY_SENSOR
    /* Z3.0 Device Type  */
    #define APP_Z3DEVICE_OS_ID        ZLO_OCCUPANCY_SENSOR_DEVICE_ID
    #define OCCUPANCY_SENSOR_ENDPOINT     1
  #else
    #define OCCUPANCY_SENSOR_ENDPOINT     0
  #endif
  #ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
    #define APP_SRC_ENDPOINT2_ID APP_ENDPOINT_TEMPERATURE_SENSOR
    /* Z3.0 Device Type  */
    #define APP_Z3DEVICE_TS_ID        HA_TEMPERATURE_SENSOR_DEVICE_ID//TODO
    #define TEMPERATURE_SENSOR_ENDPOINT   1
  #else
    #define TEMPERATURE_SENSOR_ENDPOINT   0
  #endif
  #ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR  //manufacturer specific
    #define APP_SRC_ENDPOINT3_ID APP_ENDPOINT_HUMIDITY_SENSOR
    /* Humidity Sensor logical device Id form reserved space */
    #define APP_HA_HUMIDITY_SENSOR_DEVICE_ID    0x03ff
    /* Z3.0 Device Type  */
    #define APP_Z3DEVICE_HS_ID        APP_HA_HUMIDITY_SENSOR_DEVICE_ID
    #define HUMIDITY_SENSOR_ENDPOINT      1
  #else
    #define HUMIDITY_SENSOR_ENDPOINT      0
  #endif
  #ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
    #define APP_SRC_ENDPOINT4_ID APP_ENDPOINT_EXTENDED_COLOR_LIGHT_SENSOR
    /* Z3.0 Device Type  */
    #define APP_Z3DEVICE_LS_ID        ZLO_LIGHT_SENSOR_DEVICE_ID
    #define LIGHT_SENSOR_ENDPOINT         1
  #else
    #define LIGHT_SENSOR_ENDPOINT         0
  #endif

  #define APP_ENDPOINTS_AMOUNT            (OCCUPANCY_SENSOR_ENDPOINT + TEMPERATURE_SENSOR_ENDPOINT + HUMIDITY_SENSOR_ENDPOINT + LIGHT_SENSOR_ENDPOINT)

#elif (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_THERMOSTAT)
#define APP_DEVICE_TYPE          DEV_TYPE_ENDDEVICE
#define APP_SRC_ENDPOINT_ID      APP_ENDPOINT_THERMOSTAT
#define APP_Z3DEVICE_ID          HA_THERMOSTAT_DEVICE_ID
#define APP_ENDPOINTS_AMOUNT         1

#elif (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE)
  #define APP_DEVICE_TYPE       DEV_TYPE_ENDDEVICE
  #define APP_SRC_ENDPOINT_ID APP_ENDPOINT_COMBINED_INTERFACE
  /* Z3.0 Device Type  */
  #define APP_Z3DEVICE_ID        HA_COMBINED_INTERFACE_ID
  #define APP_ENDPOINTS_AMOUNT              1
#elif (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER)
  #define APP_DEVICE_TYPE DEV_TYPE_ENDDEVICE
  #define APP_SRC_ENDPOINT_ID  APP_ENDPOINT_COLOR_SCENE_CONTROLLER
  #define APP_ENDPOINTS_AMOUNT            1
#elif (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_IAS_ACE)
  #define APP_DEVICE_TYPE DEV_TYPE_ENDDEVICE
  #define APP_Z3DEVICE_ID      ZLO_IAS_ACE_DEVICE_ID
  #define APP_SRC_ENDPOINT_ID APP_ENDPOINT_IAS_ACE
  #define APP_ENDPOINTS_AMOUNT              1

#else
  #error Device type is not detected
#endif

#if (APP_DEVICE_TYPE == DEV_TYPE_ENDDEVICE) && (APP_ZGP_DEVICE_TYPE != APP_ZGP_DEVICE_TYPE_NONE)
#error ZGP infrastructure device is enabled for end device
#endif

#if (APP_ZGP_DEVICE_TYPE != APP_ZGP_DEVICE_TYPE_COMBO_BASIC) && (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
#warning ZGP Certification should be enabled only when zgp device type is chosen as Combo
#endif

#if (APP_DEVICE_TYPE != DEV_TYPE_ENDDEVICE) && (APP_ZGP_DEVICE_TYPE != APP_ZGP_DEVICE_TYPE_NONE)
#if !defined(_GREENPOWER_SUPPORT_) || !defined(ZGP_SECURITY_ENABLE)
#error Green power support is not enabled in the stack for ZGP infrastructure device
#endif
#endif

#ifndef APP_NETWORK_KEY
  #define APP_NETWORK_KEY {0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc,0xcc}
#endif //#ifndef APP_NETWORK_KEY


#define HA_LINK_KEY {0x5a,0x69,0x67,0x42,0x65,0x65,0x41,0x6c,0x6c,0x69,0x61,0x6e,0x63,0x65,0x30,0x39}
// For ZLL networks compatibility
#define DS_LINK_KEY {0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xdA, 0xdb, 0xdc, 0xdd, 0xde, 0xdf}

#define TL_LINK_KEY {0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xcA, 0xcb, 0xcc, 0xcd, 0xce, 0xcf}

#define IC_LINK_KEY {0x66, 0xB6, 0x90, 0x09, 0x81, 0xE1, 0xEE, 0x3C, 0xA4, 0x20, 0x6B, 0x6B, 0x86, 0x1C, 0x02, 0xBB}

#define Z3DEVICE_APP_MEMORY_MEM_ID                APP_DIR1_MEM_ID

#if (APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_ON_OFF_LIGHT)
#define APP_LIGHT_SCENES_MEM_ID                   APP_PARAM1_MEM_ID
#define APP_LIGHT_ONOFF_MEM_ID                    APP_PARAM2_MEM_ID
#define APP_LIGHT_LEVEL_CONTROL_MEM_ID            APP_PARAM3_MEM_ID
#define APP_LIGHT_COLOR_CONTROL_MEM_ID            APP_PARAM4_MEM_ID
#endif

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE)
#define APP_CUSTOM_SCENES_MEM_ID                        APP_PARAM1_MEM_ID
#define APP_CUSTOM_ONOFF_MEM_ID                         APP_PARAM2_MEM_ID
#define APP_CUSTOM_LEVEL_CONTROL_MEM_ID                 APP_PARAM3_MEM_ID
#define APP_CUSTOM_COLOR_CONTROL_MEM_ID                 APP_PARAM4_MEM_ID
#define APP_CUSTOM_OCCUPANCY_MEM_ID                     APP_PARAM5_MEM_ID
#define APP_CUSTOM_TEMP_MEASURED_VALUE_MEM_ID           APP_PARAM6_MEM_ID
#define APP_CUSTOM_HUMIDITY_MEASURED_VALUE_MEM_ID       APP_PARAM7_MEM_ID
#define APP_CUSTOM_ILLU_MEASURED_VALUE_MEM_ID           APP_PARAM8_MEM_ID
#define APP_CUSTOM_LOCAL_TEMPERATURE_MEM_ID             APP_PARAM9_MEM_ID
#define APP_CUSTOM_PICOOLING_DEMAND_MEM_ID              APP_PARAM10_MEM_ID
#define APP_CUSTOM_PIHEATING_DEMAND_MEM_ID              APP_PARAM11_MEM_ID
#define APP_CUSTOM_TEMPERATURE_MEASURED_VALUE_MEM_ID    APP_PARAM12_MEM_ID
#endif

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
#define APP_MS_OCCUPANCY_MEM_ID                APP_PARAM1_MEM_ID
#endif // APP_SENSOR_TYPE_OCCUPANCY_SENSOR

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
#define APP_MS_TEMP_MEASURED_VALUE_MEM_ID      APP_PARAM2_MEM_ID
#endif // APP_SENSOR_TYPE_TEMPERATURE_SENSOR

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
#define APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID  APP_PARAM4_MEM_ID
#endif // APP_SENSOR_TYPE_HUMIDITY_SENSOR

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
#define APP_MS_ILLU_MEASURED_VALUE_MEM_ID      APP_PARAM6_MEM_ID
#endif // APP_SENSOR_TYPE_LIGHT_SENSOR

#endif  // (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_THERMOSTAT)
#define APP_TH_LOCAL_TEMPERATURE_MEM_ID                APP_PARAM1_MEM_ID
#define APP_TH_OCCUPIED_COOLING_SETPOINT_MEM_ID        APP_PARAM2_MEM_ID
#define APP_TH_OCCUPIED_HEATING_SETPOINT_MEM_ID        APP_PARAM3_MEM_ID
#define APP_TH_OCCUPANCY_MEM_ID                        APP_PARAM4_MEM_ID
#define APP_TH_HUMIDITY_MEASURED_VALUE_MEM_ID          APP_PARAM5_MEM_ID
#define APP_TH_SCENES_MEM_ID                           APP_PARAM6_MEM_ID
#define APP_TH_TEMPERATURE_MEASURED_VALUE_MEM_ID       APP_PARAM7_MEM_ID
#define APP_TH_PICOOLING_DEMAND_MEM_ID                 APP_PARAM8_MEM_ID
#define APP_TH_PIHEATING_DEMAND_MEM_ID                 APP_PARAM9_MEM_ID
#endif

#ifdef APP_DEVICE_TYPE_IAS_ACE
#define APP_IAS_ACE_ZONE_MEM_ID                          APP_PARAM1_MEM_ID
#define APP_IAS_ACE_ZONE_STATE_MEM_ID                    APP_PARAM2_MEM_ID
#define APP_IAS_ACE_ZONE_TYPE_MEM_ID                     APP_PARAM3_MEM_ID
#define APP_IAS_ACE_ZONE_STATUS_MEM_ID                   APP_PARAM4_MEM_ID
#define APP_IAS_ACE_ZONE_CIE_ADDR_MEM_ID                 APP_PARAM5_MEM_ID
#define APP_IAS_ACE_ZONE_ID_MEM_ID                       APP_PARAM6_MEM_ID
#define APP_IAS_ACE_ZONE_NO_SENSITIVITY_LEVELS_MEM_ID    APP_PARAM7_MEM_ID
#define APP_IAS_ACE_ZONE_NO_CURR_SENSITIVITY_LEV_MEM_ID  APP_PARAM8_MEM_ID

#endif

#define HA_APP_MEMORY_MEM_ID                           APP_DIR1_MEM_ID

#endif // _APPCONSTS_H

// eof appConsts.h

