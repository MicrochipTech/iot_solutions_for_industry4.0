/*******************************************************************************
  HAL MacIsr Header File

  Company:
    Microchip Technology Inc.

  File Name:
    halMacIsr.h

  Summary:
    This file contains the Implementation of hal timer specifically used by the MAC layer for its functionality.

  Description:
    This file provides the interface to access the HAL timer API's required by the BitCloud MAC
    layer.
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

#ifndef _HALMACISR_H
#define _HALMACISR_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#if defined(__ICCARM__)
#include <pic32cx1012bz25048_fpga.h>
#elif defined (__GNUC__)
#include <xc.h>
#endif

#include <systemenvironment/include/sysTypes.h>
#include <halAppClock.h>

/******************************************************************************
                        Types section.
******************************************************************************/
typedef enum
{
  HAL_RTIMER_REPEAT_MODE   = 0,
  HAL_RTIMER_ONE_SHOT_MODE = 1,
  HAL_RTIMER_STOPPED_MODE  = 2
} HAL_RTimerMode_t;

typedef struct // Timer description.
{
  volatile HAL_RTimerMode_t    mode;       // Mode.
  volatile uint16_t            period;     // Period of the timer.
  volatile uint16_t            nextEvent;  // Counter of periods.
} RTimerDescr_t;

/******************************************************************************
  MAC timer handler.
******************************************************************************/

void halMacTimerHandler(void);

/******************************************************************************
  Initializes Rtimer and RF ext. interrupts.
******************************************************************************/
void ZB_HAL_InitMacIsr(void);

/******************************************************************************
  Starts RTimer. Function should be invoked in critical section.
  Parameters:
    mode    - RTimer mode.
    period  - RTimer period.
******************************************************************************/
bool HAL_StartRtimer(HAL_RTimerMode_t mode, uint16_t period);

/******************************************************************************
  Stops RTimer. Function should be invoked in critical section.
******************************************************************************/
void HAL_StopRtimer(void);

/******************************************************************************
  Returns status of RTimer
******************************************************************************/
bool HAL_IsRtimerStopped(void);

#endif /* _HALMACISR_H */

// eof halMacIsr.h