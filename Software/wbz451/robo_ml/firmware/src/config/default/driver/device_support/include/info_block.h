// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

#ifndef IB_BLOCK_H
#define IB_BLOCK_H

#include <xc.h>
#include <stdbool.h>
#include "rf_system.h"
#ifdef __cplusplus
extern "C" {
#endif
// *****************************************************************************
/**
*@brief This routine will get Bluetooth Device Address from IB. If there exists
*       BDADDR IB, then it will return the BDADDR stored in IB. Otherwise, it
*       returns FAILS (1)
*
*@param[out] uint8_t *  "p_Addr" - the pointer to the memory stores BDADDR
*
*@retval A boolean value, True means valid BDADDR IB
*
*/
bool IB_GetBdAddr(uint8_t * p_bdAddr);

// *****************************************************************************
/**
*@brief This routine will get ZB MAC Address from IB. If there exists
*       MAC_ADDR IB, then it will return the MAC_ADDR stored in IB. Otherwise, it
*       returns FAILS (1))
*
*@param[out] uint8_t *  "p_Addr" - the pointer to the memory stores MAC_ADDR
*
*@retval A boolean value, True means valid ZB MAC Address IB
*/
bool IB_GetMACAddr(uint8_t * p_addr);

// *****************************************************************************
/**
*@brief This routine will get Battery voltage 3.0 V ADC value from IB. The value can
*       be used for Battery voltage slope and detect battery voltage
*
*@param IB_BatteryCalSar_T * p_batVoltageSar -
*                     the pointer to the memory stores Battery voltage ADC value
*
*@retval A boolean value, True means valid Battery voltage ADC IB
*/
bool IB_GetBatVoltage3v0Sar(int16_t * p_batVoltageSar);

// *****************************************************************************
/**
*@brief This routine will get Battery voltage 2.2 V ADC value from IB. The value can
*       be used for Battery voltage slope and detect battery voltage
*
*@param IB_BatteryCalSar_T * p_batVoltageSar -
*                     the pointer to the memory stores Battery voltage ADC value
*
*@retval A boolean value, True means valid Battery voltage ADC IB
*/
bool IB_GetBatVoltage2v2Sar(int16_t * p_batVoltageSar);

// *****************************************************************************
/**
*@brief This routine will get RSSI compensation offset value from IB. The value can
*       be used to compensation RSSI detection
*
*@param int8_t * p_rssiOffset -  the memory to store RSSI compensation offset value
*
*@retval A boolean value, True means vaild RSSI compensation offset IB
*/
bool IB_GetRssiOffset(int8_t * p_rssiOffset);

// *****************************************************************************
/**
*@brief This routine will get antenna gain value from IB. The value can
*       be used to calculate radiative power.
*       radiative power = conductive power + antenna gain
*
*@param int8_t * p_antennaGain  -  the memory to store antenna gain value
*
*@retval A boolean value, True means vaild antenna gain IB
*/
bool IB_GetAntennaGain(int8_t * p_antennaGain);

// *****************************************************************************
/**
*@brief This routine will load all settings from the Info Block into the appropriate
*       sub-systems for proper chip operation.
*       NOTE: This is done automatically by SYS_Load_Cal(uint8_t wssEnable)
*
*@param None
*
*@retval uint8_t      0 is success
*                     1 is fail
*/
uint8_t InformationBlockLoad(uint8_t checkIb, uint8_t * checkIbExist, wssEnable_t wssEnable);

#ifdef __cplusplus
}
#endif

#endif /* IB_BLOCK_H_INCLUDED */
