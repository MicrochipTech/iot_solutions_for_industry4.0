/*******************************************************************************
  Application Zigbee Device Select File

  Company:
    Microchip Technology Inc.

  File Name:
    zigbeeAppDeviceSelect.h

  Summary:
    This file contains the Application Zigbee Device Selection.

  Description:
    This file contains the Application Zigbee Device Selection.
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

#ifndef _Z3_DEVICETYPE_CONFIG_H_
#define _Z3_DEVICETYPE_CONFIG_H_

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
#define APP_DEVICE_TYPE_CUSTOM_DEVICE           88

#define ZIGBEE_COLOR_SCENE_CONTROLLER  APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER
#define ZIGBEE_MULTI_SENSOR            APP_DEVICE_TYPE_MULTI_SENSOR
#define ZIGBEE_COMBINED_INTERFACE      APP_DEVICE_TYPE_COMBINED_INTERFACE
#define ZIGBEE_THERMOSTAT              APP_DEVICE_TYPE_THERMOSTAT
#define ZIGBEE_IAS_ACE                 APP_DEVICE_TYPE_IAS_ACE
#define ZIGBEE_ON_OFF_LIGHT            APP_DEVICE_TYPE_ON_OFF_LIGHT
#define ZIGBEE_DIMMABLE_LIGHT          APP_DEVICE_TYPE_DIMMABLE_LIGHT
#define ZIGBEE_COLOR_LIGHT             APP_DEVICE_TYPE_COLOR_LIGHT
#define ZIGBEE_EXTENDED_COLOR_LIGHT    APP_DEVICE_TYPE_EXTENDED_COLOR_LIGHT
#define ZIGBEE_TEMPERATURE_COLOR_LIGHT APP_DEVICE_TYPE_TEMPERATURE_COLOR_LIGHT
#define ZIGBEE_CUSTOM                  APP_DEVICE_TYPE_CUSTOM_DEVICE



#define APP_ZGP_DEVICE_TYPE_NONE                0
#define APP_ZGP_DEVICE_TYPE_PROXY_BASIC         1
#define APP_ZGP_DEVICE_TYPE_COMBO_BASIC         2


#define APP_Z3_DEVICE_TYPE             ZIGBEE_MULTI_SENSOR


#define CS_UID 0 //Unique Identifier (UID) determining the device extended address

//Primary and secondary channel set configuration 
#define CS_BDB_PRIMARY_CHANNELS_MASK       0x2000000  //0x2108800 //standard (11, 15, 20, 25)
#define CS_BDB_SECONDARY_CHANNELS_MASK     0x2000000  //0x5ef7000 //standard
//#define CS_BDB_PRIMARY_CHANNELS_MASK       0x2108800 //standard (11, 15, 20, 25)
//#define CS_BDB_SECONDARY_CHANNELS_MASK     0x5ef7000 //standard

#ifndef CPU_CLK_HZ
#define CPU_CLK_HZ              64000000  // Core CPU Clock
#endif
#endif
