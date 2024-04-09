/*******************************************************************************
  MAC Environment PAN Information base Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macenvPib.h

  Summary:
    This file contains the MAC and PHY PIB access function prototypes.

  Description:
    This file contains the MAC and PHY PIB access function prototypes.
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

#ifndef _MACENVPIB_H
#define _MACENVPIB_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/macphyPib.h>
#include <mac_phy/include/macCommon.h>
#include <mac_phy/mac_env/include/macenvMem.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/
#define MS_1000 1000U /* Divider from us to ms. */

/******************************************************************************
                    Types section
******************************************************************************/
//! PIB request's descriptor.
typedef struct
{
  MACPHY_PibId_t   id;
  MACPHY_PibAttr_t attr;
} MacPhyPibReq_t;

/******************************************************************************
                   Constants section
******************************************************************************/

/******************************************************************************
                    External variables section
******************************************************************************/
extern PIB_t csPIB;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief Resets MACPHY PIB.
  \param none.
  \return none.
******************************************************************************/
void macenvResetPib(void);

/**************************************************************************//**
  \brief Sets MAC or PHY attribute to PIB.
  \param[in] pibAttr - pointer to attribute structure.
  \return SUCCESS, READ_ONLY, UNSUPPORTED_ATTRIBUTE or INVALID_PARAMETER.
******************************************************************************/
MAC_Status_t macenvSetPibAttr(const MacPhyPibReq_t *pibAttr);

/**************************************************************************//**
  \brief Gets MAC or PHY attribute from PIB.
  \param[inout] pibAttr - pointer to attribute structure.
  \return SUCCESS or UNSUPPORTED_ATTRIBUTE.
******************************************************************************/
MAC_Status_t macenvGetPibAttr(MacPhyPibReq_t *pibAttr);

/**************************************************************************//**
  \brief Calculates  maximum frame total wait time.
  \return maximum frame total wait time.
******************************************************************************/
uint32_t macenvCalculateMaxFrameTotalWaitTimeInMs(void);

/******************************************************************************
  Calculates  MAC response wait time (IEEE standart: macResponseWaitTime).
  Parameters:
    none.
  Return:
    MAC response wait time.
******************************************************************************/
uint32_t macenvCalculateResponceWaitTimeInMs(void);

/**************************************************************************//**
  \brief Detects PHY symbol duration.
  \param none;
  \return PHY symbol duration.
******************************************************************************/
uint8_t macenvGetPhySymbolDuration(void);

#ifdef _FFD_
/**************************************************************************//**
  \brief Calculates MAC transaction persistence time im ms.

  \param[in] MAC transaction persistence time in unit periods.
             IEEE802.15.4_2006, 7.4.2, Table 86, page 166.
  \return time calculated (milliseconds).
******************************************************************************/
uint32_t macenvConvertTransPersistTimeFromUnitsToMs(uint16_t transPersTimeInUnits);
#endif // _FFD_

/**************************************************************************//**
  \brief Gets current value for dsn parameter of PHY&MAC PIB and then increments it.
  \return current dsn value.
******************************************************************************/
INLINE uint8_t macenvGetAndIncDsn(void)
{
  return csPIB.macAttr.dsn++;
}

/**************************************************************************//**
  \brief Gets current value for bsn parameter of PHY&MAC PIB and then increments it.
  \return current bsn value.
******************************************************************************/
#ifdef _FFD_
INLINE uint8_t macenvGetAndIncBsn(void)
{
  return csPIB.macAttr.bsn++;
}
#endif // _FFD_

/**************************************************************************//**
  \brief Gets channel.
  \return current channel.
******************************************************************************/
INLINE uint8_t macenvGetChannel(void)
{
  return csPIB.phyAttr.channel;
}

/**************************************************************************//**
  \brief Gets supported channels.
  \return supported channels.
******************************************************************************/
INLINE uint32_t macenvGetChannelsSupported(void)
{
  return csPIB.phyAttr.channelsSupported;
}

/**************************************************************************//**
  \brief Gets tx power.
  \return current tx power.
******************************************************************************/
INLINE int8_t macenvGetTxPower(void)
{
  return csPIB.phyAttr.transmitPower;
}

/**************************************************************************//**
  \brief Gets CCA mode.
  \return current CCA mode.
******************************************************************************/
INLINE PHY_CcaMode_t macenvGetCcaMode(void)
{
  return csPIB.phyAttr.ccaMode;
}

/**************************************************************************//**
  \brief Gets CCA mode.
  \return current CCA mode.
******************************************************************************/
INLINE PHY_CcaMode_t macenvGetccaEdThres(void)
{
  return (PHY_CcaMode_t)csPIB.macAttr.ccaEdThres;
}

/**************************************************************************//**
  \brief Gets current page.
  \return current page.
******************************************************************************/
INLINE uint8_t macenvGetCurrentPage(void)
{
  return csPIB.phyAttr.currentPage;
}

/**************************************************************************//**
  \brief Gets max CSMA backoffs.
  \return max CSMA backoffs.
******************************************************************************/
INLINE uint8_t macenvGetMaxCsmaBackoffs(void)
{
  return csPIB.macAttr.maxCsmaBackoffs;
}

/**************************************************************************//**
  \brief Gets PAN ID.
  \return PAN ID.
******************************************************************************/
INLINE PanId_t macenvGetPanId(void)
{
  return csPIB.macAttr.panId;
}

/**************************************************************************//**
  \brief Gets short address.
  \return short address.
******************************************************************************/
INLINE ShortAddr_t macenvGetShortAddr(void)
{
  return csPIB.macAttr.shortAddr;
}

/**************************************************************************//**
  \brief Gets min BE.
  \return min BE.
******************************************************************************/
INLINE uint8_t macenvGetMinBe(void)
{
  return csPIB.macAttr.minBe;
}

/**************************************************************************//**
  \brief Gets max frame retries.
  \return max frame retries.
******************************************************************************/
INLINE uint8_t macenvGetMaxFrameRetries(void)
{
  return csPIB.macAttr.maxFrameRetries;
}

/**************************************************************************//**
  \brief Gets rx on when idle parameter.
  \return rx on when idle parameter.
******************************************************************************/
INLINE bool macenvGetRxOnWhenIdle(void)
{
  return csPIB.macAttr.rxOnWhenIdle;
}

/**************************************************************************//**
  \brief Gets coordinator short address.
  \return coordinator short address.
******************************************************************************/
INLINE ShortAddr_t macenvGetCoordShortAddr(void)
{
  return csPIB.macAttr.coordShortAddr;
}

/**************************************************************************//**
  \brief Gets pointer to coordinator extended address.
  \return pointer to coordinator extended address.
******************************************************************************/
INLINE ExtAddr_t* macenvGetCoordExtAddr(void)
{
  return &csPIB.macAttr.coordExtAddr;
}

/**************************************************************************//**
  \brief Gets response wait time.
  \return response wait time.
******************************************************************************/
INLINE uint8_t macenvGetResponseWaitTime(void)
{
  return csPIB.macAttr.responseWaitTime;
}

/**************************************************************************//**
  \brief Gets PAN coordinator parameter.
  \return PAN coordinator parameter.
******************************************************************************/
INLINE bool macenvGetPanCoordinator(void)
{
  return csPIB.macAttr.panCoordinator;
}

/**************************************************************************//**
  \brief Gets association permit parameter.
  \return association permit parameter.
******************************************************************************/
#ifdef _FFD_
INLINE bool macenvGetAssociationPermit(void)
{
  return csPIB.macAttr.associationPermit;
}
#endif

/**************************************************************************//**
  \brief Gets beacon payload pointer.
  \return beacon payload pointer.
******************************************************************************/
#ifdef _FFD_
INLINE uint8_t* macenvGetBeaconPayload(void)
{
  return csPIB.macAttr.beaconPayload;
}
#endif

/**************************************************************************//**
  \brief Gets beacon payload length.
  \return beacon payload length.
******************************************************************************/
#ifdef _FFD_
INLINE uint8_t macenvGetBeaconPayloadLength(void)
{
  return csPIB.macAttr.beaconPayloadLength;
}
#endif

/**************************************************************************//**
  \brief Gets beacon tx enable parameter.
  \return beacon tx enable parameter.
******************************************************************************/
#ifdef _FFD_
INLINE bool macenvGetBeaconTxEnable(void)
{
  return csPIB.macAttr.beaconTxEnable;
}
#endif

/**************************************************************************//**
  \brief Gets auto request parameter.
  \return auto request parameter.
******************************************************************************/
INLINE bool macenvGetAutoRequest(void)
{
  return csPIB.macAttr.autoRequest;
}

/**************************************************************************//**
  \brief Gets associated PAN coordinator parameter.
  \return associated PAN coordinator parameter.
******************************************************************************/
INLINE bool macenvGetAssociatedPanCoord(void)
{
  return csPIB.macAttr.associatedPanCoord;
}

/**************************************************************************//**
  \brief Sets channel.
  \param channel - channel to set.
  \return none.
******************************************************************************/
INLINE void macenvSetChannel(uint8_t channel)
{
  csPIB.phyAttr.channel = channel;
}

/**************************************************************************//**
  \brief Sets short address.
  \param shortAddr - short address.
  \return none.
******************************************************************************/
INLINE void macenvSetShortAddr(ShortAddr_t shortAddr)
{
  csPIB.macAttr.shortAddr = shortAddr;
}

/**************************************************************************//**
  \brief Sets associated pan coordinator parameter.
  \param associatedPanCoord.
  \return none.
******************************************************************************/
INLINE void macenvSetAssociatedPanCoord(bool associatedPanCoord)
{
  csPIB.macAttr.associatedPanCoord = associatedPanCoord;
}

/**************************************************************************//**
  \brief Sets coordinator short address.
  \param coordShortAddr - coordinator short address.
  \return none.
******************************************************************************/
INLINE void macenvSetCoordShortAddr(ShortAddr_t coordShortAddr)
{
  csPIB.macAttr.coordShortAddr = coordShortAddr;
}

/**************************************************************************//**
  \brief Sets coordinator ext address.
  \param coordExtAddr - coordinator ext address.
  \return none.
******************************************************************************/
INLINE void macenvSetCoordExtAddr(ExtAddr_t* coordExtAddr)
{
  COPY_EXT_ADDR(csPIB.macAttr.coordExtAddr, *coordExtAddr);
}

/**************************************************************************//**
  \brief Sets PAN ID.
  \param panId - PAN ID.
  \return none.
******************************************************************************/
INLINE void macenvSetPanId(PanId_t panId)
{
  csPIB.macAttr.panId = panId;
}

/**************************************************************************//**
  \brief Sets PAN coordinator parameter.
  \param panCoordinator - PAN coordinator parameter.
  \return none.
******************************************************************************/
INLINE void macenvSetPanCoordinator(bool panCoordinator)
{
  csPIB.macAttr.panCoordinator = panCoordinator;
}

/**************************************************************************//**
  \brief Sets beacon payload length.
  \param beaconTxEnable - beacon tx enable parameter.
  \return none.
******************************************************************************/
#ifdef _FFD_
INLINE void macenvSetBeaconTxEnable(bool beaconTxEnable)
{
  csPIB.macAttr.beaconTxEnable = beaconTxEnable;
}
#endif

/******************************************************************************
  \brief Converts time in Microseconds to time in Milliseconds.
  \param[in] time in microseconds.
  \return time in milliseconds
******************************************************************************/
INLINE uint32_t convertTimeFromUsToMs(uint32_t timeInUs)
{
  return (timeInUs / MS_1000);
}

/**************************************************************************//**
  \brief Sets max frame transmission time attribute value.

  \param[in] time - new max frame transmission time value.
  \return None.
 ******************************************************************************/
INLINE void MAC_SetMaxFrameTransmissionTime(const uint8_t time)
{
  csPIB.macAttr.maxFrameTransmissionTime = time;
}

/**************************************************************************//**
  \brief Gets max frame transmission time attribute value.

  \return Max frame transmission time attribute value.
 ******************************************************************************/
INLINE uint8_t MAC_GetMaxFrameTransmissionTime(void)
{
  return csPIB.macAttr.maxFrameTransmissionTime;
}

/**************************************************************************//**
  \brief Gets max frame transmission time attribute value.

  \return Max frame transmission time attribute value.
 ******************************************************************************/
INLINE uint8_t MAC_GetChannel(void)
{
  return csPIB.phyAttr.channel;
}

#endif /* _MACENVPIB_H */

// eof macenvPib.h
