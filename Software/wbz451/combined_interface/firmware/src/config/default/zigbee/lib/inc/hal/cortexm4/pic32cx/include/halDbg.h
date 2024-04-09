/*******************************************************************************
  HAL Debug Header File

  Company:
    Microchip Technology Inc.

  File Name:
    halDbg.h

  Summary:
    This file contains the Declarations of hal debug Codes.

  Description:
    This file contains the HAL Debug codes and information.
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

#ifndef _HALDBG_H
#define _HALDBG_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/dbg.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
enum
{
  APPTIMER_MISTAKE                         = 0x2000,
  USARTC_HALUNKNOWNERRORREASON_0           = 0x2001,
  USARTC_HALUNKNOWNERRORREASON_1           = 0x2002,
  USARTC_HALSIGUSARTTRANSMISSIONCOMPLETE_0 = 0x2003,
  USARTC_HALSIGUSARTRECEPTIONCOMPLETE_0    = 0x2004,
  APPTIMER_HANDLER_0                       = 0x2005,
  IRQ_NULLCALLBACK_0                       = 0x2006,
  EXT_IRQ_NULLCALLBACK0                    = 0x2007,
  FLASH_PAGEFILLBUFFERINCORRECTOFFSET_0    = 0x2008,
  I2C_NULLCALLBACK_0                       = 0x2009,
  SLEEPTIMER_NULLCALLBACK_0                = 0x200a,
  ADC_NULLCALLBACK_0                       = 0x200b,
  EEPROM_EMULATION_NO_MEMORY               = 0x200c,
  EEPROM_EMULATION_NOT_INITIALIZED_0       = 0x200d,
  EEPROM_EMULATION_NOT_INITIALIZED_1       = 0x200e,
  EEPROM_EMULATION_NOT_INITIALIZED_2       = 0x200f,
  EEPROM_EMULATION_BAD_ADDRESS_0           = 0x2010,
  EEPROM_EMULATION_BAD_ADDRESS_1           = 0x2011,
  EEPROM_EMULATION_BAD_ROW_WRITE           = 0x2012,
  EEPROM_EMULATION_ROW_MAP_NOT_VALID       = 0x2013,
  EEPROM_EMULATION_ADDITIONALROW_NOT_FOUND = 0x2014,
  EEPROM_EMULATION_INVALID_ADDITIONALROW   = 0x2015,
  EEPROM_EMULATION_INIT_SPAREROW_NOT_FOUND = 0x2016,
  EEPROM_EMULATION_MIGRATION_NO_SPAREROW   = 0x2017,
  EEPROM_EMULATION_INVALID_SPARE_ROW       = 0x2018,
  TIMER_ISR_STACK_OVERFLOW                 = 0x2019,
  EIC_ISR_STACK_OVERFLOW                   = 0x201A,
  WDT_ISR_STACK_OVERFLOW                   = 0x201B,
  WDT_TC_ISR_STACK_OVERFLOW                = 0x201C,
  RTC_ISR_STACK_OVERFLOW                   = 0x201D,
  MAC_TIMER_ISR_STACK_OVERFLOW             = 0x201E,
  TIMER2_ISR_STACK_OVERFLOW                = 0x201F,
  ADC_ISR_STACK_OVERFLOW                   = 0x2020,
  USART_CHANNEL_0_ISR_STACK_OVERFLOW       = 0x2021,
  USART_CHANNEL_1_ISR_STACK_OVERFLOW       = 0x2022,
  HAL_HARD_FAULT_EXCEPTION                 = 0x2023,
  HAL_HARD_FAULT_EXCEPTION_STACK_OVERFLOW  = 0x2024,
  HAL_AES                                  = 0x2025,
};

/******************************************************************************
                   Prototypes section
******************************************************************************/

#endif /* _HALDBG_H */

// eof halDbg.h
