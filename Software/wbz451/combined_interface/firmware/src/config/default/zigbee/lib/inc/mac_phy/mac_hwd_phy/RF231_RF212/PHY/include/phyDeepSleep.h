/*******************************************************************************
  PHY Deep Sleep Handling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phyDeepSleep.h

  Summary:
    This file defines the Transceiver Deep Sleep mode interface.

  Description:
    This file defines the Transceiver Deep Sleep mode interface.
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

#ifndef _PHYDEEPSLEEP_H
#define _PHYDEEPSLEEP_H

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
 
/******************************************************************************
                               Global variables
******************************************************************************/
bool trx_sleep_enabled;

/******************************************************************************
  \brief Prepare transceiver to the Deep Sleep mode.
 ******************************************************************************/
void PHY_PrepareDeepSleep(void);

/******************************************************************************
  \brief Restore transceiver from the Deep Sleep mode.
 ******************************************************************************/
void PHY_RestoreFromDeepSleep(void);

/******************************************************************************
  \brief Prepare transceiver to Sleep mode.
 ******************************************************************************/
void PHY_PrepareSleep(void);

/******************************************************************************
  \brief Restore transceiver from Sleep mode.
 ******************************************************************************/
void PHY_RestoreFromSleep(void);

/******************************************************************************
  \brief BLE PWR Mng Utility for Sleep.
 ******************************************************************************/
void PHY_BleRfPwrMgmt(uint8_t value , bool orAnd);

/******************************************************************************
  \brief BLE Clock On or Off.
 ******************************************************************************/
void PHY_BLEClockOnOff(bool status);

#endif /* _PHYDEEPSLEEP_H */
/** eof phyDeepSleep.h */
