/*******************************************************************************
  Application Timer Source File

  Company:
    Microchip Technology Inc.

  File Name:
    appTimer.c

  Summary:
    This file contains the implementation of application Timer.

  Description:
    This file contains the implementation of application Timer for the Bitcloud Stack.
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
/******************************************************************************
                   Includes section
******************************************************************************/
#include <hal/include/appTimer.h>
#include <systemenvironment/include/sysAssert.h>
#include <hal/cortexm4/pic32cx/include/halDbg.h>
#include <hal/cortexm4/pic32cx/include/halAppClock.h>
/******************************************************************************
                   External global variables section
******************************************************************************/
extern uint8_t halAppTimeOvfw;

/******************************************************************************
                   Global variables section
******************************************************************************/
static HAL_AppTimer_t *halAppTimerHead = NULL; // head of appTimer list
static HAL_AppTimer_t __attribute__((persistent)) *backupHalAppTimerHead;
static HAL_AppTimer_t __attribute__((persistent)) backupTimers[6];
static uint32_t __attribute__((persistent)) backupxExpectedIdleTime;
 
/******************************************************************************
                   Implementations section
******************************************************************************/
/******************************************************************************
  \brief Returns the time left value for the smallest app timer.
  \return time left for the smallest application timer.
******************************************************************************/
uint32_t halGetTimeToNextAppTimer(void)
{
  uint32_t timeToFire = ~0UL;
  uint32_t currentTime = halGetTimeOfAppTimer();

  if (halAppTimerHead)
  {
    if ((uint64_t)(halAppTimerHead->service.sysTimeLabel) + halAppTimerHead->interval > currentTime)
      timeToFire = (uint64_t)(halAppTimerHead->service.sysTimeLabel) + halAppTimerHead->interval - currentTime;
    else
      timeToFire = 0;
  }

  return timeToFire;
}

/******************************************************************************
Interrupt handler of appTimer clock.
******************************************************************************/
void halAppTimerHandler(void)
{
  uint32_t sysTime;

  // search for expired timers and call their callbacks
  while (halAppTimerHead
      && ((sysTime = halGetTimeOfAppTimer()) - halAppTimerHead->service.sysTimeLabel) >= halAppTimerHead->interval)
  {
    HAL_AppTimer_t *p = halAppTimerHead;
    (void) halRemoveTimer(&halAppTimerHead, NULL, p);
    if (TIMER_REPEAT_MODE == p->mode)
    {
      p->service.sysTimeLabel = sysTime;
      halAddTimer(&halAppTimerHead, p, sysTime);
    }

    //SYS_E_ASSERT_FATAL(p->callback, APPTIMER_HANDLER_0);
    if (NULL != p->callback)
       p->callback();
  }
}

/******************************************************************************
Check if timer is already started.
Parameters:
  appTimer - pointer to HAL_AppTimer_t.
Returns:
  true - timer specified already started and presents in the system timers queue
  false - timer is't started yet
******************************************************************************/
static bool isTimerAlreadyStarted(HAL_AppTimer_t *appTimer)
{
  bool result = false;
  BC_Timer_t *p; // p is bottom of list
  p = halAppTimerHead;

  while (NULL != p)
  {
    if (p == appTimer)
      return true;
    
    p = (BC_Timer_t *)p->service.next;
  }
  return result;
}

/******************************************************************************
Starts to count an interval.
Parameters:
  appTimer - pointer to HAL_AppTimer_t.
Returns:
  -1 - pointer is NULL.
  0 - success
******************************************************************************/
int HAL_StartAppTimer(HAL_AppTimer_t *appTimer)
{
  uint32_t sysTime;

  if (!appTimer)
    return -1;

  if (true == isTimerAlreadyStarted(appTimer))
  {
    SYS_E_ASSERT_ERROR(false, APPTIMER_MISTAKE);
    return 0;
  }
  sysTime = halGetTimeOfAppTimer();
  appTimer->service.next = NULL;
  appTimer->service.sysTimeLabel = sysTime;
  halAddTimer((BC_Timer_t**)(&halAppTimerHead), (BC_Timer_t*)appTimer, sysTime);
  return 0;
}

/******************************************************************************
Stops the timer.
Parameters:
  appTimer - pointer to HAL_AppTimer_t.
Returns:
 -1 there is not the appTimer.
 0 - success
******************************************************************************/
int HAL_StopAppTimer(HAL_AppTimer_t *appTimer)
{
  BC_Timer_t *prev = 0;
  BC_Timer_t **t = &appTimer;

  if (!appTimer)
    return -1;
  if (halAppTimerHead != *t)
  {
    if (!(prev = halFindPrevTimer((BC_Timer_t**)(&halAppTimerHead), appTimer)))
      return -1;  // This timer is not in the list
  }
  (void) halRemoveTimer((BC_Timer_t**)(&halAppTimerHead), prev, appTimer);
  return 0;
}

/**************************************************************************//**
\brief Gets system time.

\return
  time since power up in milliseconds(8 bytes).
******************************************************************************/
BcTime_t HAL_GetSystemTime(void)
{
  BcTime_t sysTime = 0ull;

  sysTime = halGetTimeOfAppTimer();
  sysTime |= ((BcTime_t)halAppTimeOvfw << 32);
  return sysTime;
}

/******************************************************************************
Return elapsed time of app timer since last ISR

Returns:
  time in us.
******************************************************************************/
uint32_t HAL_GetElapsedAppTimerTimeSinceLastIsr(void)
{
  return halGetElapsedTimeFromAppClock();
}

/******************************************************************************
Remaining time in the timer.
Parameters:
  appTimer - pointer to HAL_AppTimer_t.
Returns:
 -1 No app timer running.
  0 Success    
******************************************************************************/
int HAL_RemainingAppTimer(HAL_AppTimer_t *appTimer, uint32_t *remainingTime)
{
  uint32_t currentTime = halGetTimeOfAppTimer();
  *remainingTime = ~0UL;

  if (!appTimer)
    return -1;
  if (true != isTimerAlreadyStarted(appTimer))
    return -1;
  
  if (halAppTimerHead)
  {
    if ((uint64_t)(appTimer->service.sysTimeLabel) + appTimer->interval > currentTime)
      *remainingTime = (uint64_t)(appTimer->service.sysTimeLabel) + appTimer->interval - currentTime;
    else
      *remainingTime = 0;
  }
  return 0;
}

/******************************************************************************
 * Backing up of running timers and sys time

Returns:
 * void
******************************************************************************/
void HAL_BackupRunningTimers(uint32_t expectedSleepTime)
{
  uint8_t i =0;
  HAL_AppTimer_t *p = NULL; 
  memcpy(&backupHalAppTimerHead,&halAppTimerHead, 4);
  p = halAppTimerHead;  
  while(p)    
  {
    backupTimers[i].mode = p->mode;
    backupTimers[i].interval = p->interval;
    backupTimers[i].callback = p->callback;
    backupTimers[i].service.sysTimeLabel = p->service.sysTimeLabel;
    backupTimers[i].service.next = p->service.next;        
    p = p->service.next;
    i++;
  } 
  //backup system time  
  halBackupSystemTime();
  backupxExpectedIdleTime = expectedSleepTime;
}

/******************************************************************************
 * Restoring of running timers and sys time

Returns:
  void
******************************************************************************/
void HAL_RestoreRunningTimers(void)
{
  uint8_t i =0;
  halRestoreSystemTime();
  memcpy(&halAppTimerHead, &backupHalAppTimerHead, 4);
  HAL_AppTimer_t *p = halAppTimerHead; //= &backupTimers[0];
  for(i=0; p;i++)
  {
    p->mode = backupTimers[i].mode;
     p->interval = backupTimers[i].interval;      
     p->callback = backupTimers[i].callback;
     p->service.sysTimeLabel = backupTimers[i].service.sysTimeLabel;
     p->service.next = backupTimers[i].service.next;
     p = p->service.next;
  }
  {
      halAdjustSleepInterval(backupxExpectedIdleTime-1);
  }
}


// eof appTimer.c
