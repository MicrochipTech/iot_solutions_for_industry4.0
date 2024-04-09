/*******************************************************************************
  ZLL Timer Internal Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Timer_Internal.h

  Summary:
    This file contains the ZLL Timer Internal functions.

  Description:
    This file contains the ZLL Timer Internal functions.
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


#ifndef N_TIMER_INTERNAL_H
#define N_TIMER_INTERNAL_H

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
* EXPORTED FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Update the running timers. Implemented by the common code, called by the platform specific code.

  \return None.
 ******************************************************************************/
void N_Timer_Internal_Update(void);

/**************************************************************************//**
  \brief Start a timer on the underlying platform.
        Implemented by the platform specific code, called by the common code.

  \param[in] timeoutMs The timer delay in milliseconds.
 
  \return None.
 ******************************************************************************/
void N_Timer_Internal_SetTimer(int32_t timeoutMs);

/**************************************************************************//**
  \brief Stop the platform timer on the bitcloud stack.
        Implemented by the common code, called by the platform specific code.

  \param[in] timeoutMs The timer delay in milliseconds.
 
  \return None.
 ******************************************************************************/
void N_Timer_Internal_Stop(void);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_TIMER_INTERNAL_H
