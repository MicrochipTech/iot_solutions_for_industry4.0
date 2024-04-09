/*******************************************************************************
  HAL Atomic Header File

  Company:
    Microchip Technology Inc.

  File Name:
    atomic.h

  Summary:
    This file describes the atomic sections.

  Description:
    This file describes the atomic sections.
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

#ifndef _ATOMIC_H
#define _ATOMIC_H

/******************************************************************************
                   Includes section
******************************************************************************/
#if defined(AT91SAM7X256) || defined(AT32UC3A0512) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
 || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A)
  #include <inttypes.h>
#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA256A3) || defined(ATXMEGA128B1) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2) || defined(WIN)
  #include <halAtomic.h>

#elif defined(_PIC32CX_)

#include <xc.h>

#endif

#if defined(AT91SAM7X256) || defined(AT32UC3A0512) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
 || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A) || defined(_PIC32CX_)
/******************************************************************************
                   Types section
******************************************************************************/
typedef  uint32_t atomic_t;

/******************************************************************************
                   Inline static functions section
******************************************************************************/
/******************************************************************************
 Disables global interrupt. Enter atomic section.
******************************************************************************/
void halStartAtomic(atomic_t volatile *pAtomic);

/******************************************************************************
 Exit atomic section
******************************************************************************/
void halEndAtomic(atomic_t volatile *pAtomic);
  /** \brief Marks the begin of atomic section */
#define ATOMIC_SECTION_ENTER  {volatile atomic_t __atomic; halStartAtomic(&__atomic);
  /** \brief Marks the end of atomic section */
#define ATOMIC_SECTION_LEAVE  halEndAtomic(&__atomic);}

#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA256A3) || defined(ATXMEGA128B1) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)
  /** \brief Marks the begin of atomic section */
  #define ATOMIC_SECTION_ENTER {atomic_t __atomic = halStartAtomic();
  /** \brief Marks the end of atomic section */
  #define ATOMIC_SECTION_LEAVE halEndAtomic(__atomic);}
#elif defined(SIMULATOR)
  /** \brief Marks the begin of atomic section */
  #define ATOMIC_SECTION_ENTER  do {} while (0);
  /** \brief Marks the end of atomic section */
  #define ATOMIC_SECTION_LEAVE  do {} while (0);
#elif defined(WIN)
  /** \brief Marks the begin of atomic section */
  #define ATOMIC_SECTION_ENTER {halStartAtomic();
  /** \brief Marks the end of atomic section */
  #define ATOMIC_SECTION_LEAVE halEndAtomic();}
#endif

#if defined(_PIC32CX_) && defined (_USE_RTOS_)
/* Critical section management. */
extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );

#undef ATOMIC_SECTION_ENTER
#undef  ATOMIC_SECTION_LEAVE

#define ATOMIC_SECTION_ENTER          vPortEnterCritical();
#define ATOMIC_SECTION_LEAVE          vPortExitCritical();
#endif

#endif // _ATOMIC_H

// eof atomic.h
