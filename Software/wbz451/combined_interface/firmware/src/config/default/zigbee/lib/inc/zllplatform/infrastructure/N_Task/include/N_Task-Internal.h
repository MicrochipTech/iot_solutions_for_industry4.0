/*******************************************************************************
  ZLL Task Internal Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Task_Internal.h

  Summary:
    This file contains the ZLL Task Internal Handling functions.

  Description:
    This file contains the ZLL Task Internal Handling functions.
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



#ifndef N_TASK_INTERNAL_H
#define N_TASK_INTERNAL_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

/** Internal call-back propagated from the host OS's task handler. */
typedef void (*pfTaskHandler_t)(void);

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/


/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

/**************************************************************************//**
  \brief Enter a critical section.

  \return A value to be passed to N_Task_Internal_ExitCriticalSection()
 ******************************************************************************/
uint8_t N_Task_Internal_EnterCriticalSection(void);

/**************************************************************************//**
  \brief Exit a critical section.

  \return intState The value returned from the matching N_Task_Internal_EnterCriticalSection().
 ******************************************************************************/
void N_Task_Internal_ExitCriticalSection(uint8_t intState);

/**************************************************************************//**
  \brief Set an event to the internal task. This will cause the registered task callback function to be called (decoupled).

  \return None
 ******************************************************************************/
void N_Task_Internal_SetEvent(void);

/**************************************************************************//**
  \brief Initialise the OS-specific part of N_Task and register the task callback function.

  \return None
 ******************************************************************************/
void N_Task_Internal_Init(pfTaskHandler_t taskCallback);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_TASK_INTERNAL_H
