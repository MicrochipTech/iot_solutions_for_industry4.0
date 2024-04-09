
/*******************************************************************************
  HAL AppClock Header File

  Company:
    Microchip Technology Inc.

  File Name:
    halAppClock.h

  Summary:
    This file contains the Declarations of appTimer hardware-dependent module.

  Description:
    This file contains the declarations of appTimer hardware-dependent module for Pic32cx.
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

#ifndef _HALAPPCLOCK_H
#define _HALAPPCLOCK_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <hal/include/halTaskManager.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
#if defined (HAL_48MHz)
#define CPU_CLK_HZ  48000000
#elif defined (HAL_64MHz)
#define CPU_CLK_HZ 64000000
#endif
/** \brief system timer interval in ms */
#define HAL_APPTIMERINTERVAL 10ul
/** \brief frequency prescaler for system timer */
#if ((CPU_CLK_HZ == 48000000) || (CPU_CLK_HZ == 64000000))
  #define TIMER_FREQUENCY_PRESCALER            16
  #define RTIMER_FREQUENCY_PRESCALER           16
  #define AMOUNT_TIMER_CLOCK_IN_ONE_USEC       (APB_CLK_HZ/TIMER_FREQUENCY_PRESCALER/1000000ul)
  #define AMOUNT_USEC_FOR_TIMER_CLOCK          (1000000ul/(APB_CLK_HZ/TIMER_FREQUENCY_PRESCALER))
  #define AMOUNT_NSEC_FOR_TIMER_CLOCK          (1000000000ul/(APB_CLK_HZ/TIMER_FREQUENCY_PRESCALER))
//#else
//  #error HAL Frequency is not selected
#endif

/** \brief timer counter top value */
#define TOP_TIMER_COUNTER_VALUE  ((APB_CLK_HZ/1000ul) / TIMER_FREQUENCY_PRESCALER) * HAL_APPTIMERINTERVAL
/** \brief Usable timer channel */
#define HAL_TIMER_CHANNEL  0

#define TCC2_SYNCBUSY  TCC2_REGS->TCC_SYNCBUSY
#define TCC2_CTRLA     TCC2_REGS->TCC_CTRLA
#define TCC2_16COUNT   TCC2_REGS->TCC_COUNT
#define TCC2_CTRLBSET  TCC2_REGS->TCC_CTRLBSET
#define TCC2_CTRLBCLR  TCC2_REGS->TCC_CTRLBCLR
#define TCC2_CC0       TCC2_REGS->TCC_CC[0]
#define TCC2_CC1       TCC2_REGS->TCC_CC[1]
#define TCC2_CC2       TCC2_REGS->TCC_CC[2]
#define TCC2_CC3       TCC2_REGS->TCC_CC[3]
#define TCC2_CC4       TCC2_REGS->TCC_CC[4]
#define TCC2_CC5       TCC2_REGS->TCC_CC[5]
#define TCC2_INTENSET  TCC2_REGS->TCC_INTENSET
#define TCC2_INTENCLR  TCC2_REGS->TCC_INTENCLR
#define TCC2_INTFLAG   TCC2_REGS->TCC_INTFLAG
#define TCC2_WAVE      TCC2_REGS->TCC_WAVE
#define TCC2_STATUS    TCC2_REGS->TCC_STATUS
/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief configure, enable and start timer counter channel 0
******************************************************************************/
void halStartAppClock(void);

/**************************************************************************//**
\brief Stop and disable timer
******************************************************************************/
void halStopAppClock(void);

/**************************************************************************//**
\brief Synchronization system time which based on application timer.
******************************************************************************/
void halAppSystemTimeSynchronize(void);

/******************************************************************************
 To get app clock elapsed time since last ISR
 Parameters:
   none
 Returns:
   elapsed time in us
 *****************************************************************************/
uint32_t halGetElapsedTimeFromAppClock(void);

/**************************************************************************//**
\brief Return time of sleep timer.

\return
  time in ms.
******************************************************************************/
uint32_t halGetTimeOfAppTimer(void);

/**************************************************************************//**
\brief Delay in microseconds.

\param[in] us - delay time in microseconds
******************************************************************************/
void halDelayUs(uint16_t us);

/**************************************************************************//**
\brief Takes account of the sleep interval.

\param[in]
  interval - time of sleep
******************************************************************************/
void halAdjustSleepInterval(uint32_t interval);
/**************************************************************************//**
\brief Takes backup of current sys time

\param[in]
  interval - time of sleep
******************************************************************************/
void halBackupSystemTime(void);

/**************************************************************************//**
\brief restoring of current sys time

\param[in]
  interval - time of sleep
******************************************************************************/
void halRestoreSystemTime(void);

#endif
// eof halAppClock.h
