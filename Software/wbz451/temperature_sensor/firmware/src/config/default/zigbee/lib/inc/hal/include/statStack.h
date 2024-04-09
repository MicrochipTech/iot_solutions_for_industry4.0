/*******************************************************************************
  HAL statStack Header File

  Company:
    Microchip Technology Inc.

  File Name:
    statStack.h

  Summary:
    This file contains the Collection of stack statistics, runtime data for report.

  Description:
    This file contains the Collection of stack statistics, runtime data for report.
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

/******************************************************************************
                   Define section
******************************************************************************/
#ifndef _STAT_STACK_H_
#define _STAT_STACK_H_

#define STACK_CHECK_DISABLED (0xFFFFu)

#define UTIL_CSTACK_PTR_HIADDR (0x001Du)
#define UTIL_CSTACK_PTR_LOADDR (UTIL_CSTACK_PTR_HIADDR-1)

#ifdef __BOARD_SAMR21__
#define STACK_INIT_MARGIN 0xF0
#else
#define STACK_INIT_MARGIN 0x0
#endif
/******************************************************************************
                    Static functions prototypes section
******************************************************************************/


#if defined(_STATS_ENABLED_)
/**************************************************************************//**
\brief Measure stack usage by searching for first overwritten byte of
       default fill pattern

\param[in] start - start of section
\param[in] end - end of section (address of byte after the last one)
\return number of used bytes
******************************************************************************/
uint16_t probeStack(const volatile uint8_t *start, const volatile uint8_t *end);

/**************************************************************************//**
\brief Measures stack and returns

\param[out] None
\param[in] None
\return number of actually placed bytes
******************************************************************************/
uint16_t Stat_GetCurrentStackLeft(void);
#endif //(_STATS_ENABLED_)
#endif
// eof stackStat.h
