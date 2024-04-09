/*******************************************************************************
  MAC SuperFrame Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macSuperframe.h

  Summary:
    This file provides interface to MAC Superframe type declarations.

  Description:
    This file provides interface to MAC Superframe type declarations.
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

#ifndef _MACSUPERFRAME_H
#define _MACSUPERFRAME_H

/******************************************************************************
                        Include section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysEndian.h>
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                        Types section.
******************************************************************************/
//! MAC GTS characteristics. IEEE 802.15.4-2006 Figure 65.
BEGIN_PACK
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t    length : 4,
    uint8_t direction : 1,
    uint8_t      type : 1,
    uint8_t  reserved : 2
  ))
}  MAC_GtsCharacteristics_t;
END_PACK

//! Superframe specification. IEEE 802.15.4-2006 Figure 47.
BEGIN_PACK
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint16_t beaconOrder       : 4,
    uint16_t superframeOrder   : 4
  ))
  LITTLE_ENDIAN_OCTET(5, (
    uint16_t finalCapSlot      : 4,
    uint16_t battLifeExt       : 1,
    uint16_t reserved          : 1,
    uint16_t panCoordinator    : 1,
    uint16_t associationPermit : 1
  ))
}  MAC_SuperframeSpec_t;
END_PACK

//! GTS specification field. IEEE 802.15.4-2006 Figure 48.
BEGIN_PACK
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t count    : 3,
    uint8_t reserved : 4,
    uint8_t permit   : 1
  ))
}  MAC_GtsSpec_t;
END_PACK

//! GTS descriptor. IEEE 802.15.4-2006  Figure 50.
BEGIN_PACK
typedef struct PACK
{
  ShortAddr_t shortAddr;
  struct
  {
    LITTLE_ENDIAN_OCTET(2, (
      uint8_t startSlot : 4,
      uint8_t length    : 4
    ))
  } gts;
}  MAC_GtsDescr_t;
END_PACK

/******************************************************************************
                        Defines section.
******************************************************************************/
//! Max of GTS.
#define MAC_GTS_MAX 7

//! MAC GTS direction type. IEEE 802.15.4-2006 7.3.9.2 GTS Characteristics field.
typedef enum
{
  MAC_GTS_DIRECTION_TRANSMIT = 0,
  MAC_GTS_DIRECTION_RECEIVE  = 1
} MAC_GtsDirection_t;

#endif // _MACSUPERFRAME_H

// eof macSuperframe.h
