/*******************************************************************************
  HAL TaskManager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    halTaskManager.h

  Summary:
    This file contains the  Declarations of enums and functions of HAL task manager.

  Description:
    This file contains the  Declarations of enums and functions of HAL task manager.
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

#ifndef _HALTASKHANDLER_H
#define _HALTASKHANDLER_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTaskManager.h>

/******************************************************************************
                               Types section
*******************************************************************************/



#define HAL_ALL_TASKS_ACCEPTED_MASK 0xFFFFU

typedef enum
{
  HAL_APPTIMER,
  HAL_SM_REQ,
  HAL_MAX_TASKS_ID
} HalTaskIds_t;

typedef volatile uint16_t HalTaskBitMask_t;


/**************************************************************************//**
  \brief HAL USART task type declaration.
******************************************************************************/
typedef void (* HalTask_t)(void);

/******************************************************************************
                   External variables section
******************************************************************************/
extern volatile HalTaskBitMask_t halTaskFlags;
extern volatile HalTaskBitMask_t halAcceptedTasks;

/******************************************************************************
                   Inline static functions section
******************************************************************************/
/**************************************************************************//**
\brief Set task for HAL task manager.

\param[in]
  task id
******************************************************************************/
INLINE void halPostTask(HalTaskIds_t id)
{
  ATOMIC_SECTION_ENTER
  halTaskFlags |= ((HalTaskBitMask_t)1 << id);
  ATOMIC_SECTION_LEAVE
  SYS_PostTask(HAL_TASK_ID);
}

INLINE void halPostTaskFromISR(HalTaskIds_t id)
{
  halTaskFlags |= ((HalTaskBitMask_t)1 << id);
  SYS_PostTaskFromISR(HAL_TASK_ID);
}

/**************************************************************************//**
\brief Clear task for HAL task manager.

\param[in]
  task id
******************************************************************************/
INLINE void halClearTask(HalTaskIds_t id)
{
  ATOMIC_SECTION_ENTER
  halTaskFlags &= ~((HalTaskBitMask_t)1 << id);
  ATOMIC_SECTION_LEAVE
}

/**************************************************************************//**
\brief Holds execution of required tasks.

\param[in] mask - mask of tasks to not be held
******************************************************************************/
INLINE void HAL_HoldOnTasks(HalTaskBitMask_t mask)
{
  halAcceptedTasks = mask;
}

/**************************************************************************//**
\brief Accepts execution of previously holded tasks.
******************************************************************************/
INLINE void HAL_ReleaseAllHeldTasks(void)
{
  halAcceptedTasks = HAL_ALL_TASKS_ACCEPTED_MASK;
  SYS_PostTask(HAL_TASK_ID);
}

#endif  /*_HALTASKHANDLER_H*/

// eof halTaskManager.h
