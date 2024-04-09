/*******************************************************************************
 System statistics Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysStat.h

  Summary:
    Collection of internal runtime data for report

  Description:
    Collection of internal runtime data for report
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

#ifndef _SYS_STAT_H
#define _SYS_STAT_H

/******************************************************************************
                   Define section
******************************************************************************/
#define SYS_STACK_CHECK_DISABLED (0xFFFFu)


#if  defined(_STATS_ENABLED_)
/******************************************************************************
                   Types section
******************************************************************************/
typedef struct _SYS_StatGenerator_t
{
  void *next;
  uint8_t (*gen)(uint8_t *buf, uint8_t maxSize);
} SYS_StatGenerator_t;

/******************************************************************************
                   Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Register new generator of stat data

\param[in] gen - generator
******************************************************************************/
void SYS_RegisterStatGenerator(SYS_StatGenerator_t *gen);

/**************************************************************************//**
\brief Collect stats from registered generators into the supplied buffer

\param[out] buf - buffer to place stat report
\param[in] maxSize - size limit of buffer
\return number of actually placed bytes
******************************************************************************/
uint8_t SYS_GenerateStatReport(uint8_t *buf, uint8_t maxSize);


/**************************************************************************//**
\brief Measures stack and returns

\param[out] None
\param[in] None
\return number of actually placed bytes
******************************************************************************/
uint16_t SYS_StatGetMinimumStackLeft(void);

/**************************************************************************//**
\brief Measures Current stack left and returns

\param[out] None
\param[in] None
\return  Remaining Stack left
******************************************************************************/

uint16_t Stat_GetCurrentStackLeft(void);

#endif // _STATS_ENABLED_

#endif // _SYS_STAT_H
// eof sysStat.h
