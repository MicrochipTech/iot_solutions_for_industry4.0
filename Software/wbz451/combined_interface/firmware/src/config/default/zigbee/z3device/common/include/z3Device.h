/*******************************************************************************
  Z3Device Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    z3device.h

  Summary:
    This file contains the Common application declarations

  Description:
    This file contains the Common application declarations
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

#ifndef _Z3DEVICE_H
#define _Z3DEVICE_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/clusters/include/haClusters.h>
#include <z3device/common/include/appConsts.h>
#include <bdb/include/bdb.h>
#include <z3device/common/include/pic32cxBSP.h>

/******************************************************************************
                    Defines section
******************************************************************************/

//Table 4 â?? Bits of the bdbCommissioningMode attribute
//5.3.2 bdbCommissioningMode attribute
#define BDB_COMMISSIONING_TOUCHLINK       0 //(1)
#define BDB_COMMISSIONING_NWK_STEERING    1 // (2)
#define BDB_COMMISSIONING_NWK_FORMATION   2 // (4)
#define BDB_COMMISSIONING_FINDING_BINDING 3 // (8)

#define TOUCHLINKING_MASK     (1 << BDB_COMMISSIONING_TOUCHLINK)
#define NWK_STEERING_MASK     (1 << BDB_COMMISSIONING_NWK_STEERING)
#define NWK_FORMATION_MASK    (1 << BDB_COMMISSIONING_NWK_FORMATION)
#define FINDING_BINDING_MASK  (1 << BDB_COMMISSIONING_FINDING_BINDING)

/* Visualization redirect */

#if (BSP_SUPPORT == BOARD_PIC32CX)
  #define LEDS_OPEN()                                 BSP_LedsOpen()
  #define LEDS_SET_COLOR_HS(hue, saturation)          BSP_SetLedColorHS(hue, saturation)
  #define LEDS_SET_COLOR_XY(x, y)                     BSP_SetLedColorXY(x, y)
  #define LEDS_SET_BRIGHTNESS(level)                  BSP_SetLedBrightnessLevel(level)
  #define TEMP_SENSOR_OPEN()                          BSP_TempSensorOpen()
  #define TEMP_SENSOR_READ(x)                         BSP_ReadTempSensor(x)

  #define LED_INIT()                                  BSP_LedsOpen()
  #define LED_ON()                                    BSP_OnLed()
  #define LED_OFF()                                   BSP_OffLed()
  #define LED_TOGGLE()                                BSP_ToggleLed()
  
  #define BUTTON_OPEN()                               BSP_ButtonOpen()
  #define BUTTON_READ(x)                              BSP_ReadButtonsState(x)

  #define LCD_INIT()                                  (void)0
  #define LCD_PRINT(...)                              (void)0
  #define LCD_FILL(...)                               (void)0
  #define LCD_CLEAR()                                 (void)0
#endif 

/******************************************************************************
                    Globals section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

typedef enum
{
  DEVICE_INITIAL_STATE,
  DEVICE_ACTIVE_IDLE_STATE,
} AppDeviceState_t;


typedef enum
{
  FINDING_BINDING_INITIATOR,
  FINDING_BINDING_TARGET,
  FINDING_BINDING_NONE,
} AppEpFindingAnbdBindingRole_t;


typedef enum
{
  APP_INITIAL_STATE,    //State to initialize the application
  APP_START_WAIT_STATE, //State is where initialization is done, waiting to enter into the network
  APP_START_NETWORK_STATE,
  APP_IN_NETWORK_STATE,
  APP_IN_NETWORK_PERMITJOIN_STATE,
  APP_FINDING_BINDING_STATE,
  APP_IN_NETWORK_IDLE_STATE
} AppState_t;


/******************************************************************************
                    Global variables section
******************************************************************************/
/******************************************************************************           
                        external variables section
******************************************************************************/
extern AppDeviceState_t appDeviceState;

extern AppBindReq_t* deviceBindReqs[APP_ENDPOINTS_AMOUNT];

/******************************************************************************
                             Prototypes section
******************************************************************************/
/**************************************************************************//**
/brief Device initialization routine
******************************************************************************/
void appDeviceInit(void);

/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void appSecurityInit(void);

/**************************************************************************//**
\brief Device common task handler
******************************************************************************/
void appDeviceTaskHandler(void);

/**************************************************************************//**
\brief Stops identifying on endpoints
******************************************************************************/
void appIdentifyStart(uint16_t identifyTime, bool colorEffect, uint16_t enhancedHue);

/**************************************************************************//**
\brief Stops Identifying
******************************************************************************/
void appIdentifyStop(void);

/**************************************************************************//**
\brief Check the commssioning inprogress status

\returns true, if commissioning is in progress, false otherwise
******************************************************************************/
bool isCommssioiningInProgress(void);

/**************************************************************************//**
\brief Register Endpoint

\returns true, if Register Endpoint is Successful, false otherwise
******************************************************************************/
bool APP_RegisterEndpoint(ZCL_DeviceEndpoint_t *endpoint, AppBindReq_t* dlBindReq);

/**************************************************************************//**
\brief backing of zcl attributes for device to support deep sleep 

******************************************************************************/
void APP_BackupZCLAttributes(void);

/**************************************************************************//**
\brief Reset the report configuration of the device's reportable attributes

\param[in] none
******************************************************************************/
void resetReportConfig(void);

#if BSP_SUPPORT == BOARD_SAMR21_ZLLEK
 void buttonReleased(uint8_t button);
#endif

#ifdef ZAPPSI_HOST
/**************************************************************************//**
\brief resets NP
******************************************************************************/
void appResetNP(void);

/**************************************************************************//**
\brief restarts Application
******************************************************************************/
void restartApp(void);

#endif //ZAPPSI_HOST

void process_ZB_evt(void);

#endif // _Z3DEVICE_H
// eof z3Device.h
