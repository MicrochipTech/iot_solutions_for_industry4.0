/*******************************************************************************
  ZLL Initialization Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Init.h

  Summary:
    This file contains the ZLL Initialization functions.

  Description:
    This file contains the ZLL Initialization functions.
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


#ifndef N_INIT_H
#define N_INIT_H

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

typedef struct N_Init_InitializationCallback_t
{
    /** Function that is called when the platform task list can be initialized
    */
    void (*TaskListInitializer)(void);

    /** Function that is called just before the stack is started. This callback function
     *  should initialize the components that are required before N_Cmi is initialized.
    */
    void (*EarlyPlatformInitializer)(void);

    /** Function that is called as final initialization routine. Within this function, the
     *  remaining platform components and the application components can be initialized.
    */
    void (*ApplicationInitializer)(void);

    int8_t endOfList;
} N_Init_InitializationCallback_t;

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

/**************************************************************************//**
  \brief Initialize the CPU.

  \return None.
 ******************************************************************************/

void N_Init_Cpu(void);

/**************************************************************************//**
  \brief Initialize the HAL and Memory allocation.

  \return None.
 ******************************************************************************/

void N_Init_HalAndMemory(void);

/**************************************************************************//**
  \brief Initialize the ZigBee stack and register initialization functions for platform components.

  \return None.
 ******************************************************************************/

void N_Init_Stack(const N_Init_InitializationCallback_t* pCb);

/**************************************************************************//**
  \brief Initialize the ZigBee Platform.
        Note: This function will start calling the callback functions passed to N_Init_Stack.

  \return None.
 ******************************************************************************/

void N_Init_Platform(void);

/**************************************************************************//**
  \brief Return TRUE when the platform is initialized

  \return None.
 ******************************************************************************/

bool N_Init_IsInitDone(void);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_INIT_H
