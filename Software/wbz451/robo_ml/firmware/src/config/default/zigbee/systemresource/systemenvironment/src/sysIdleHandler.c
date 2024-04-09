/*******************************************************************************
  System idle handler Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysIdleHandler.c

  Summary:
    Implementation of system idle handler.

  Description:
    Implementation of system idle handler.
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
                   Includes section
******************************************************************************/
#ifndef _MAC2_
#include <zdo/include/zdo.h>
#endif
//#include <systemenvironment/include/sysSleep.h>
#include <hal/cortexm4/pic32cx/include/halMacIsr.h>

#define SYS_IDLE 
/******************************************************************************
                   Prototypes section
******************************************************************************/
#if defined(_ENDDEVICE_) && defined(_SLEEP_WHEN_IDLE_)
#if !defined(_ZGPD_SPECIFIC_) && !defined(MAC_TEST_APP)
static void sysIdleHandlerSleepConf(ZDO_SleepConf_t *conf);
#endif
#endif /* _ENDDEVICE_ && _SLEEP_WHEN_IDLE_ */

/******************************************************************************
                   Global variables section
******************************************************************************/
#if (defined(_ENDDEVICE_) && defined(_SLEEP_WHEN_IDLE_))||(defined(_ZGPD_SPECIFIC_) && defined(_SLEEP_WHEN_IDLE_)) 
#if !defined(_ZGPD_SPECIFIC_) && !defined(MAC_TEST_APP)
static ZDO_SleepReq_t sleepReq;
#endif
static bool sleepWhenIdleEnabled = false;
#endif /* _ENDDEVICE_ && _SLEEP_WHEN_IDLE_ */

/******************************************************************************
                   Implementations section
******************************************************************************/
void SYS_IdleHandler(void)
{
#if (defined(_ENDDEVICE_) && defined(_SLEEP_WHEN_IDLE_))||(defined(_ZGPD_SPECIFIC_) && defined(_SLEEP_WHEN_IDLE_))
  if (sleepWhenIdleEnabled)
  {
#ifdef _ZGPD_SPECIFIC_
#if (APP_ENABLE_CONSOLE == 0)
     HAL_Sleep_t halSleep;
     uint32_t maxSleepTime = ~0UL;

     if (HAL_IsRtimerStopped())
     {
       SYS_PostEvent(BC_EVENT_MAX_SLEEP_TIME_REQUEST, (SYS_EventData_t)&maxSleepTime);
       halSleep.sleepTime = 0;
       if(maxSleepTime != ~0UL)
      {
         halSleep.sleepTime = maxSleepTime;
      }
      halSleep.callback = NULL;
      SYS_Sleep(&halSleep);
     }
#endif
#else
#ifndef _MAC2_
    bool rxOnWhenIdle;
    DeviceType_t deviceType;

    CS_ReadParameter(CS_DEVICE_TYPE_ID, &deviceType);
    CS_ReadParameter(CS_RX_ON_WHEN_IDLE_ID, &rxOnWhenIdle);

    if (DEVICE_TYPE_END_DEVICE == deviceType &&
        false == rxOnWhenIdle)
    {
      sleepReq.ZDO_SleepConf = sysIdleHandlerSleepConf;
      ZDO_SleepReq(&sleepReq);
      return;
    }
#endif
#endif
  }
#endif /* _ENDDEVICE_ && _SLEEP_WHEN_IDLE_ */

  SYS_IDLE;
}

#if defined(_SLEEP_WHEN_IDLE_)
/**************************************************************************//**
  \brief Enables sleep when a device is idle.
  It is disabled by default. If this is enabled, an end device automatically
  tries to go to sleep mode when there are no pending tasks and wakes up on
  expiration of CS_SLEEP_PERIOD or any application timer.
  The sleep period is equal to the minimum value between the rest of
  CS_SLEEP_PERIOD (CS_SLEEP_PERIOD minus time from the last poll)
  and the shortest time to fire of all application timers.
  If an end device wakes up on expiration of CS_SLEEP_PERIOD it polls
  its parent, otherwise it doesn't.
  Also, an end device can be wakep up by external interrupts. Application
  must be subscribed to event HAL_EVENT_WAKING_UP and call ZDO_WakeUpReq()
  in callback function.
  When the stack tries to go to sleep mode, it raises two events -
  BC_EVENT_BUSY_REQUEST and BC_EVENT_POLL_REQUEST allowing application to
  control sleep.
******************************************************************************/
void SYS_EnableSleepWhenIdle(void)
{
#if (defined(_ENDDEVICE_))||(defined(_ZGPD_SPECIFIC_))
  sleepWhenIdleEnabled = true;
#endif /* _ENDDEVICE_ */
}

/**************************************************************************//**
  \brief Disables sleep when device is idle.
******************************************************************************/
void SYS_DisableSleepWhenIdle(void)
{
#if (defined(_ENDDEVICE_))||(defined(_ZGPD_SPECIFIC_))
  sleepWhenIdleEnabled = false;
#endif /* _ENDDEVICE_ */
}

/**************************************************************************//**
  \brief Returns true if sleep when idle is enabled. False otherwise.
******************************************************************************/
bool SYS_IsSleepWhenIdleEnabled(void)
{
#if (defined(_ENDDEVICE_) && defined(_SLEEP_WHEN_IDLE_))||(defined(_ZGPD_SPECIFIC_) && defined(_SLEEP_WHEN_IDLE_))
  return sleepWhenIdleEnabled;
#else
  return false;
#endif /* _ENDDEVICE_ && _SLEEP_WHEN_IDLE_ */
}

#if defined(_ENDDEVICE_)
#if !defined(_ZGPD_SPECIFIC_) && !defined(MAC_TEST_APP)
/**************************************************************************//**
  \brief Sleep request confirm.

  \param[in]  conf - parameters of the confirm.
******************************************************************************/
static void sysIdleHandlerSleepConf(ZDO_SleepConf_t *conf)
{
  (void)conf;
}

#endif /* _ZGPD_SPECIFIC_ */
#endif /* _ENDDEVICE_ */
#endif /* _SLEEP_WHEN_IDLE_ */

// eof sysIdleHandler.c