/*******************************************************************************
  System timer Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysTimer.c

  Summary:
    This file contains the Implementation of the system timer.

  Description:
    This file contains the Implementation of the system timer.
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
#include <systemenvironment/include/sysTimer.h>

/******************************************************************************
                           Implementations section
 ******************************************************************************/
/******************************************************************************
  \brief Initialize the System Timer.

  \param[in] sysTimer - timer pointer will be initialized.
  \param[in] mode - timer mode:  TIMER_ONE_SHOT_MODE or TIMER_REPEAT_MODE.
  \param[in] interval - timer interval (milliseconds).
  \param[in] handler - timer handler function pointer.

  \return None.
 *****************************************************************************/
void SYS_InitTimer(SYS_Timer_t *const sysTimer, const TimerMode_t mode,
  const uint32_t interval, void (*handler)(void))
{
  SYS_StopTimer(sysTimer);

  sysTimer->state = SYS_TIMER_STOPPED;
  sysTimer->timer.mode = mode;
  sysTimer->timer.interval = interval;
  sysTimer->timer.callback = handler;
}

/******************************************************************************
  \brief Start the System Timer.

  \param[in] sysTimer - timer pointer will be started.

  \return None.
 ******************************************************************************/
void SYS_StartTimer(SYS_Timer_t *const sysTimer)
{
  if (SYS_TIMER_STOPPED == sysTimer->state)
  {
    sysTimer->state = SYS_TIMER_STARTED;
    HAL_StartAppTimer(&sysTimer->timer);
  }
}

/******************************************************************************
  \brief Stop the System Timer.

  \param[in] sysTimer - timer pointer will be stopped.

  \return None.
 *****************************************************************************/
void SYS_StopTimer(SYS_Timer_t *const sysTimer)
{
  if (SYS_TIMER_STARTED == sysTimer->state)
  {
    sysTimer->state = SYS_TIMER_STOPPED;
    HAL_StopAppTimer(&sysTimer->timer);
  }
}

/* eof sysTimer.c */

