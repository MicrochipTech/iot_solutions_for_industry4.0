// DOM-IGNORE-BEGIN
/*******************************************************************************
  HAL APP Timer Header File

  Company:
    Microchip Technology Inc.

  File Name:
    appTimer.h

  Summary:
    This file describes the HAL appTimer interface.

  Description:
    This file provides interface to the HAL appTimer API's.
 *******************************************************************************/

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
 
// DOM-IGNORE-BEGIN

#ifndef _APPTIMER_H
#define _APPTIMER_H

// DOM-IGNORE-END

/******************************************************************************
                   Includes section
 ******************************************************************************/
 
#include <systemenvironment/include/sysTypes.h>
#include <halAppClock.h>
#include <hal/include/bcTimer.h>

/******************************************************************************
                   Types section
 ******************************************************************************/
/**fields of structure
    uint32_t interval - timer firing interval. Interval must be more than 10 ms (set by user
    TimerMode_t mode - timer work mode (set by user). Must be chosen from
           TIMER_REPEAT_MODE
           TIMER_ONE_SHOT_MODE
    void (*callback)(void) - pointer to timer callback function (set by user). 
    Must not be set to NULL.    
*/
typedef BC_Timer_t HAL_AppTimer_t;

/******************************************************************************
                   Prototypes section
 ******************************************************************************/
 
#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************//**
  \brief Starts to count an interval (starts user timer).

  \param appTimer - pointer to the timer structure. HAL_APPTimer_t is type definition of BC_Timer_t
					
  \return 1 - pointer is NULL
          0 - success
 **************************************************************************/
int HAL_StartAppTimer(HAL_AppTimer_t *appTimer);

/*********************************************************************//**
  \brief Stops the user timer.

  \param appTimer - pointer to the timer structure.

  \return 1 - there is no appTimer started or pointer is NULL
          0 - success
 **********************************************************************/
int HAL_StopAppTimer(HAL_AppTimer_t *appTimer);

/********************************************************************//**
  \brief Gets system time.
  
  \param None

  \return time since power up in millisecond 8 bytes.
 ***********************************************************************/
BcTime_t HAL_GetSystemTime(void);

/*********************************************************************//**
  \brief Return elapsed time of app timer since last ISR
  
  \param None
  
  \return time in us.
 *********************************************************************/
uint32_t HAL_GetElapsedAppTimerTimeSinceLastIsr(void);

/*****************************************************************//**
  \brief  Remaining time in the timer.
  
  \param appTimer - pointer to HAL_AppTimer_t.
  
  \return 1 No app timer running.
          0 Success    
 **********************************************************************/
int HAL_RemainingAppTimer(HAL_AppTimer_t *appTimer, uint32_t *remainingTime);
/*****************************************************************//**
  \brief  Backing up timers info

 **********************************************************************/
void HAL_BackupRunningTimers(uint32_t expectedSleepTime);

/*****************************************************************//**
  \brief  Restoring timers info

 **********************************************************************/
void HAL_RestoreRunningTimers(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*_APPTIMER_H*/
//eof appTimer.h
