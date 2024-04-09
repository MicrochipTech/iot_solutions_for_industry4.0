/*******************************************************************************
  System Sleep Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sleep_system.h

  Summary:
    This file contains the System Sleep functions for the project.

  Description:
    This file contains the System Sleep functions for the project.
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

#ifndef SLEEP_SYSTEM_H
#define SLEEP_SYSTEM_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Function Prototypes
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/**
*@brief The API is used to enable/disable retention RAM
*
*@param bool enable   Set as true to enable retention RAM; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigRetRam(bool enable);

// *****************************************************************************
/**
*@brief The API is used to disable debug bus for power saving purpose.
*
*@param None
*
*@retval None
*/
void DEVICE_SLEEP_DisableDebugBus(void);

// *****************************************************************************
/**
*@brief The API is used to enable/disable RF clock.
*
*@param bool enable   Set as true to enable RF clock; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigRfClk(bool enable);

// *****************************************************************************
/**
*@brief The API is used to enable/disable BT/ZB sub-system bypass PLL lock.
*
*@param bool enable   Set as true to enable BT/ZB sub-system bypass PLL lock; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigSubSysPllLock(bool enable);

// *****************************************************************************
/**
*@brief The API is used to enable/disable RF MBS.
*
*@param bool enable   Set as true to enable RF MBS; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigRfMbs(bool enable);

// *****************************************************************************
/**
@brief The API is used to enable/disable BT/ZB sub-system crystal .
*
*@param bool enable   Set as true to enable BT/ZB sub-system crystal; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigSubSysXtalReady(bool enable);

// *****************************************************************************
/**
@brief The API is used to enable/disable ACLB clock .
*
*@param bool enable   Set as true to enable ACLB; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigAclbClk(bool enable);

// *****************************************************************************
/**
@brief The API is used to enable/disable RF crystal .
*
*@param bool enable   Set as true to enable RF crystal; set as false to disable.
*
*@retval None
*/
void DEVICE_SLEEP_ConfigRfXtal(bool enable);

// *****************************************************************************
/**
@brief The API is used to bring the wireless subsystem in low power mode.\n
       It should be called when the application requests the device into deep sleep or xtreme deep sleep mode.
*
*@param None
*
*@retval None
*/
void DEVICE_SLEEP_ConfigWssLowPowerMode(void);


#ifdef __cplusplus
}
#endif

#endif//SLEEP_SYSTEM_H
