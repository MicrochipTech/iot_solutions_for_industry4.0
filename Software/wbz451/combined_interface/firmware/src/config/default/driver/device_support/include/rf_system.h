#ifndef RF_SYSTEM_H
#define RF_SYSTEM_H

#include <xc.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Wireless Subsystem Enable Flag */
typedef enum 
{
    WSS_ENABLE_NONE, //None
    WSS_ENABLE_BLE,  // BLE Enable
    WSS_ENABLE_ZB,   // Zigbee Enable
    WSS_ENABLE_BLE_ZB //BLE and Zigbee Enable
}wssEnable_t;

// *****************************************************************************
/**
*@brief This routine will load the System calibration values for the RF, and PMU
*       subsystems. The main functions are RF initialization, BLE Modem initialization,
*       load Calibration data from IB, VCO coarse tune (ACLB) and Initialize Arbiter
*
*@param wssEnable_t wssEnable -  wireless subsystem enable flag
*       0: None 
*       1: BLE enable
*       2: ZB enable
*       3: BLE enable & ZB enable
*
*@retval None
*/
void SYS_Load_Cal(wssEnable_t wssEnable);

// *****************************************************************************
/**
*@brief This routine will decide if RF need to be calibrated. current method is 
*       a default 60 sec timer to trigger calibration
*
*@param None
*
*@retval A boolean value: 
*       True means RF need to be calibrated. 
*       False means RF doesn't need to be calibrated
*/

bool RF_NeedCal(void);


// *****************************************************************************
/**
*@brief This routine will calibrate the RF from a Timer event condition. The main 
*       functions are TX_Power_Compensation and RSSI_ED_Compensation, which are
*       compensation over temperature. Since temperature may change over time, user
*       can choose do RF_Timer_Cal over time.
*
*@param wssEnable_t wssEnable -  wireless subsystem enable flag
*       0: None 
*       1: BLE enable
*       2: ZB enable
*       3: BLE enable & ZB enable
*
*@retval None
*/
void RF_Timer_Cal(wssEnable_t wssEnable);


// *****************************************************************************
/**
*@brief This routine will read current temperature ADC value. The functionality is 
*       provided by RF IP.
*
*@param None
*
*@retval uint16    The ADC value of current temperature
*/
uint16_t Temperature_Reading(void);

// *****************************************************************************
/**
*@brief This routine will configure the RF system clock that feeds the MCU.
*
*@param None
*
*@retval None
*/
void SYS_ClkGen_Config(void);

// *****************************************************************************
/**
*@brief This routine will the RF subsystem as idle mode.
*
*@param None
*
*@retval None
*/
void RF_SetIdleMode(void);

#ifdef __cplusplus
}
#endif

#endif /* RF_SYSTEM_H_INCLUDED */
