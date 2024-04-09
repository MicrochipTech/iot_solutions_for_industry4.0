/*******************************************************************************
  HAL sleep Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sleep.h

  Summary:
    This file describes the sleep interface.

  Description:
    This file describes the sleep interface.
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

/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/
#ifndef _SLEEP_H
#define _SLEEP_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                   Types section
******************************************************************************/
typedef void (* HAL_WakeUpCallback_t)(bool);

/** \brief System sleep parameters */
typedef struct
{
  uint32_t sleepTime; //!< Time of mcu's and radio's sleeping
  bool startPoll;
  HAL_WakeUpCallback_t callback; //!< Pointer to a wake up callback function. Can be set to NULL.
} HAL_Sleep_t;

/** \brief Sleep modes enumeration. Avaible only for AVR. */
typedef enum _HAL_SleepMode_t
{
  HAL_SLEEP_MODE_NONE = 0x00,
  HAL_SLEEP_MODE_POWER_SAVE = 0x01,
  HAL_SLEEP_MODE_POWER_DOWN = 0x02,
  HAL_SLEEP_MODE_IDLE = 0x03
} HAL_SleepMode_t;

/** \brief Wake up source. Avaible only for AVR. */
typedef enum _HAL_WakeUpSource_t
{
  HAL_WAKEUP_SOURCE_SLEEP_TIMER = 0x00,
  HAL_WAKEUP_SOURCE_EXT_IRQ = 0x01
} HAL_WakeUpSource_t;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Starts sleep timer and HAL sleep. When system is wake up send callback
\param[in]
    sleepParam - pointer to sleep structure.
\return
    -1 - bad parameters,   \n
    -2 - sleep timer busy, \n
    -3 - sleep system has been started.
     0 - success.
******************************************************************************/
int HAL_StartSystemSleep(HAL_Sleep_t *sleepParam);

/**************************************************************************//**
\brief Prepares mcu for power-save, power-down.
  Power-down the mode is possible only when internal RC is used
\return
  -1 - there is no possibility to sleep.
******************************************************************************/
int HAL_Sleep(void);

/***************************************************************************//**
\brief Makes MCU's entering the Idle mode.
*******************************************************************************/
void HAL_IdleMode(void);

#endif /* _SLEEP_H */
