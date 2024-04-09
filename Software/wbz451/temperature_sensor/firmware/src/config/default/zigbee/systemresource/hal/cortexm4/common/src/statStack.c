/*******************************************************************************
  HAL Stack statistics Source File

  Company:
    Microchip Technology Inc.

  File Name:
    stackStat.c

  Summary:
    This file contains the Collection of stack statistics and the runtime data for report.

  Description:
    This file contains the Collection of stack statistics and the runtime data for report.
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


#if defined(_STATS_ENABLED_)

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <statStack.h>
#include <Core_cm4.h>

/******************************************************************************
                   Define section
******************************************************************************/
/******************************************************************************
				   Extern section
******************************************************************************/

#ifdef __GNUC__
extern unsigned int __stack_start;
extern unsigned int __stack;
#endif

/******************************************************************************
                    Static functions prototypes section
******************************************************************************/

uint16_t probeStack(const volatile uint8_t *start, const volatile uint8_t *end);


// Preincluded generator for reporting stack usage. Only classic AVRs are supported for now

/**************************************************************************//**
\brief Measure stack usage by searching for first overwritten byte of
       default fill pattern

\param[in] start - start of section
\param[in] end - end of section (address of byte after the last one)
\return number of used bytes
******************************************************************************/
uint16_t probeStack(const volatile uint8_t *start, const volatile uint8_t *end)
{  
  while (start < end && *(uint32_t *)start == 0x0A0B0C0D)
    start+=4;
  return end - start;
}


/**************************************************************************//**
\brief Measures stack and returns

\param[out] None
\param[in] None
\return number of actually placed bytes
******************************************************************************/

uint16_t Stat_GetCurrentStackLeft(void)
{
#if defined(__ICCARM__)  //Only for ARM
  #pragma section = "CSTACK"
  volatile uint8_t* pCStackEnd = __segment_begin("CSTACK");
#elif defined(__GNUC__) 
  volatile uint8_t* pCStackEnd = (uint8_t *)&__stack_start;
#else
  return STACK_CHECK_DISABLED;
#endif	
  uint8_t *pCStack = (uint8_t *)__get_MSP();

  return ((uint16_t) (pCStack - pCStackEnd));
}
#endif //(_STATS_ENABLED_)
// eof stackStat.c
