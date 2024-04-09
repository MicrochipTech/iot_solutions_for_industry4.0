/*******************************************************************************
  MAC Addressing Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macAddr.h

  Summary:
    This file contains the MAC addressing types and constants.

  Description:
    This file contains the MAC addressing types and constants.
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

#ifndef _MACADDR_H
#define _MACADDR_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                        Define(s) section.
******************************************************************************/
#define MAC_BROADCAST_PANID       0xFFFFU ///< Broadcast PANID.
#define MAC_BROADCAST_SHORT_ADDR  0xFFFFU ///< Broadcast short address, no association.
#define MAC_NO_SHORT_ADDR         0xFFFEU ///< After association no short address.
#define MAC_NO_EXT_ADDR           0x00ULL

/******************************************************************************
                        Types section.
******************************************************************************/
typedef uint16_t PanId_t;     ///< PAN identifier type declaration.
typedef uint16_t ShortAddr_t; ///< Short address type declaration.
typedef uint64_t ExtAddr_t;   ///< Extended address type declaration.

/// Union of possible MAC address types.
typedef union
{
  ShortAddr_t sh;
  ExtAddr_t   ext;
  uint8_t     raw[8];
} MAC_Addr_t;

//! MAC address mode types (IEEE 802.15.4-2006 Table 80).
 typedef enum
{
  MAC_NO_ADDR_MODE    = 0x00,
  MAC_RSRV_ADDR_MODE  = 0x01,
  MAC_SHORT_ADDR_MODE = 0x02,
  MAC_EXT_ADDR_MODE   = 0x03
} MAC_AddrMode_t;

/******************************************************************************
                        Definitions section.
******************************************************************************/
#if defined UINT64_MEMCMP
  #define IS_EQ_EXT_ADDR(A, B)    IS_EQ_64BIT_VALUES(A, B)
  #define IS_EQ_EXT_ADDR_A(A, B)    IS_EQ_64BIT_VALUES_A(A, B)
  #define IS_CORRECT_EXT_ADDR(A)  isCorrectExtAddr((const uint8_t *)&A)
  #define COPY_EXT_ADDR(DST, SRC) COPY_64BIT_VALUE(DST, SRC)
  #define COPY_EXT_ADDR_A(DST, SRC) COPY_64BIT_VALUE_A(DST, SRC)
#else
  #define IS_EQ_EXT_ADDR(A, B)    IS_EQ_64BIT_VALUES(A, B)
  #define IS_CORRECT_EXT_ADDR(A)  (MAC_NO_EXT_ADDR != (A))
  #define COPY_EXT_ADDR(DST, SRC) COPY_64BIT_VALUE(DST, SRC)
  #define IS_EQ_EXT_ADDR_A(A, B)    IS_EQ_64BIT_VALUES_A(A, B)
  #define COPY_EXT_ADDR_A(DST, SRC) COPY_64BIT_VALUE_A(DST, SRC)
#endif

/******************************************************************************
                Inline static functions prototypes section
******************************************************************************/
INLINE bool isCorrectExtAddr(const uint8_t *extAddr)
{
  uint8_t i = 0U;

  do
    if (extAddr[i]) return true;
  while (++i < sizeof(uint64_t));
  return false;
}

#endif //_MACADDR_H

// eof macAddr.h
