/*******************************************************************************
  ZLL Timer Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Timer_Bindings.h

  Summary:
    This file contains the ZLL Timer Bindings functions.

  Description:
    This file contains the ZLL Timer Bindings functions.
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


#ifndef N_TIMER_BINDINGS_H
#define N_TIMER_BINDINGS_H

// implemented interface(s)
#define N_Timer_Start32 N_Timer_Start32_Impl
#define N_Timer_Start16 N_Timer_Start16_Impl
#define N_Timer_Reload32 N_Timer_Reload32_Impl
#define N_Timer_Reload16 N_Timer_Reload16_Impl
#define N_Timer_Stop N_Timer_Stop_Impl
#define N_Timer_IsRunning N_Timer_IsRunning_Impl
#define N_Timer_GetRemaining N_Timer_GetRemaining_Impl
#define N_Timer_GetSystemTime N_Timer_GetSystemTime_Impl

#endif