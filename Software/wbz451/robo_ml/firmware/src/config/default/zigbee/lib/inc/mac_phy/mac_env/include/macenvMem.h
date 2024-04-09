/*******************************************************************************
  MAC environment Memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macenvMem.h

  Summary:
    This file provides access to the MAC and PHY PIB memory.

  Description:
    This file provides access to the MAC and PHY PIB memory.
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

#ifndef _MACENVMEM_H
#define _MACENVMEM_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/phy.h>
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
//! PHY PIB attributes.
typedef struct
{
  uint8_t         channel;
  uint32_t        channelsSupported; // Just one row for current page.
  int8_t          transmitPower;
  PHY_CcaMode_t   ccaMode;
  uint8_t         currentPage;
  uint16_t        maxFrameDuration;
  uint8_t         shrDuration;
  uint8_t         symbolsPerOctet;
} PhyPibAttr_t;

//! MAC PIB attributes.
typedef struct
{
  uint32_t        ackWaitDuration;
  bool            associatedPanCoord;
#ifdef _FFD_
  bool            associationPermit;
#endif // _FFD_
  bool            autoRequest;
  //bool          battLifeExt;
  //uint8_t       battLifeExtPeriods;
#ifdef _FFD_
  uint8_t         *beaconPayload;
  uint8_t         beaconPayloadLength;
  //uint8_t       beaconOrder;
  //uint32_t      beaconTxTime;
  uint8_t         bsn;
#endif // _FFD_
  ExtAddr_t       coordExtAddr;
  ShortAddr_t     coordShortAddr;
  uint8_t         dsn;
  //bool          gtsPermit;
  uint8_t         maxBe;
  uint8_t         maxCsmaBackoffs;
  //uint8_t       maxFrameTotalWaitTime;
  uint8_t         maxFrameRetries;
  uint8_t         minBe;
  //uint8_t       minLifsPeriod;
  //uint8_t       minSifsPeriod;
  PanId_t         panId;
#ifdef _FFD_
  //bool          promiscuousMode;
#endif // _FFD_
  uint8_t         responseWaitTime;
  bool            rxOnWhenIdle;
  bool            securityEnabled;
  ShortAddr_t     shortAddr;
#ifdef _FFD_
  //uint8_t       superframeOrder;
  //uint8_t       syncSymbolOffset;
#endif // _FFD_
  //bool          timestampSupported;
#ifdef _FFD_
  //uint16_t        transactionPersistenceTime;
#endif // _FFD_
  /************************************************************/
  // Additional attributes. NOT described in the standard.
  ExtAddr_t       extAddr;  // Device own extended address.
  bool            panCoordinator;
  // For PanServer needs.
#ifdef _FFD_
  bool            beaconTxEnable;
#endif //_FFD_
/** Duration in milliseconds of maximum length frame transferring. */
  uint8_t         maxFrameTransmissionTime;
  uint8_t         ccaEdThres;
} MacPibAttr_t;

//! MAC and PHY PIB attributes.
typedef struct
{
  MacPibAttr_t macAttr;
  PhyPibAttr_t phyAttr;
} PIB_t;

#endif /*_MACENVMEM_H*/

// eof macphyPibMem.h
