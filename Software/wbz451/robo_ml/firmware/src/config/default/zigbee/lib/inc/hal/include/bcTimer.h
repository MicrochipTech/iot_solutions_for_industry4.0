/*******************************************************************************
  BC HAL Timer  Header File

  Company:
    Microchip Technology Inc.

  File Name:
    bcTimer.h

  Summary:
    This file contains the Declaration of timer queue interface, hardware-independent module.

  Description:
    This file contains the Declaration of timer queue interface, hardware-independent module.
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

#ifndef _MNHALTIMER_H
#define _MNHALTIMER_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                   Types section
******************************************************************************/
/** \brief mode of timers  */
typedef enum
{
  TIMER_REPEAT_MODE,
  TIMER_ONE_SHOT_MODE
} TimerMode_t;

/** \brief fields of structure: \n
    uint32_t interval - timer firing interval (set by user) \n
    TimerMode_t mode - timer work mode (set by user). Must be chosen from: \n
           TIMER_REPEAT_MODE \n
           TIMER_ONE_SHOT_MODE \n
    void (*callback)(void) - pointer to timer callback function (set by user). \n
    next - pointer to next cell of list \n
    intervalLeft - absolute fired time */
typedef struct _Timer_t
{
  struct
  {
    struct _Timer_t *next;
    uint32_t sysTimeLabel;
  } service;
  uint32_t interval;
  TimerMode_t mode;
  void (*callback)(void); //!< Must not be set to NULL.
} BC_Timer_t;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Adds timer to the timer's list. Timers sorted by remaining time.
\param[in]
  head - address of pointer to head of the timers list.
\param[in]
  timer - address of timer that must be added to the list.
\param[in]
  sysTime - current time, used for sorting.
******************************************************************************/
void halAddTimer(BC_Timer_t **head, BC_Timer_t *timer, uint32_t sysTime);

/**************************************************************************//**
\brief Removes timer from the timers list.
\param[in]
  head - address of pointer to head of the timers list.
\param[in]
  prev - address of the timer before the timer that must be removed from the list.
\param[in]
  p - address of timer that must be removed from the list.

\return pointer to next cell or pointer to head if deleting is head
******************************************************************************/
BC_Timer_t* halRemoveTimer(BC_Timer_t **head, BC_Timer_t *prev, BC_Timer_t *p);

/**************************************************************************//**
\brief The search of the timer in the timers list before one.
\param[in]
  head - address of pointer to head of the timers list.

\return pointer to saerching timer
******************************************************************************/
BC_Timer_t *halFindPrevTimer(BC_Timer_t **head,  BC_Timer_t *p);

#endif /* _MNHALTIMER_H */

// eof bcTimer.h
