/*******************************************************************************
  HAL Task Manager Source File

  Company:
    Microchip Technology Inc.

  File Name:
    halTaskManager.c

  Summary:
    This file contains the Implementation of Hardware Abstraction Layer task manager.

  Description:
    This file contains the Implementation of Hardware Abstraction Layer task manager and its
    corresponding functions.
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
#include <hal/include/halTaskManager.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
#define HANDLERS_GET(A, I) memcpy_P(A, &halHandlers[I], sizeof(HalTask_t))

#define HAL_APP_TIMER_HANDLER           halAppTimerHandler

#ifdef _HAL_HW_AES_
  #define HAL_HW_AES_HANDLER            halSmRequestHandler
#else
  #define HAL_HW_AES_HANDLER            halEmptyHandler
#endif // _HAL_HW_AES_

#define HAL_WAKEUP_HANDLER            halWakeupHandler
#define HAL_SLEEP_HANDLER             halPowerOff
#define HAL_ASYNC_TIMER_HANDLER       halAsyncTimerHandler
#define HAL_SLEEP_TIME_SYNC_HANDLER   halSleepSystemTimeSynchronize

/******************************************************************************
                   Prototypes section
******************************************************************************/
void halAppTimerHandler(void);
void halSigUsartHandler(void);
void halSigUsbHandler(void);
void halSigEepromReadyHandler(void);
void halSig2WireSerialHandler(void);
void halAsyncTimerHandler(void);
void halSleepSystemTimeSynchronize(void);
void halWakeupHandler(void);
void halPowerOff(void);
void halSigAdcHandler(void);
void halSmRequestHandler (void);

static void halEmptyHandler(void);


/******************************************************************************
                   Global variables section
******************************************************************************/
volatile HalTaskBitMask_t halTaskFlags = 0; // HAL USART tasks' bit mask.
volatile HalTaskBitMask_t halAcceptedTasks = HAL_ALL_TASKS_ACCEPTED_MASK;
HalTask_t PROGMEM_DECLARE(halHandlers[HAL_MAX_TASKS_ID]) =
{
  HAL_APP_TIMER_HANDLER,
  HAL_HW_AES_HANDLER
};

/******************************************************************************
                   Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Empty handler to fill empty peripheries.
******************************************************************************/
static void halEmptyHandler(void)
{}

/**************************************************************************//**
\brief HAL task handler.
******************************************************************************/
void HAL_TaskHandler(void)
{
  HalTask_t         handler = NULL;
  HalTaskBitMask_t  mask = 1;
  uint8_t           index = 0;
  HalTaskBitMask_t  tmpFlags = 0;

  ATOMIC_SECTION_ENTER
  tmpFlags = halTaskFlags;
  ATOMIC_SECTION_LEAVE

  if (!(tmpFlags & halAcceptedTasks))
    return;

  for ( ; index < (uint8_t)HAL_MAX_TASKS_ID; index++, mask <<= 1)
  {
    if (tmpFlags & mask & halAcceptedTasks)
    {
      ATOMIC_SECTION_ENTER
      halTaskFlags ^= mask;
      ATOMIC_SECTION_LEAVE
      HANDLERS_GET(&handler, index);
      handler();
    }
  }

  (void)halEmptyHandler; // to kill warning "unused function"
}
// eof halTaskManager.c
