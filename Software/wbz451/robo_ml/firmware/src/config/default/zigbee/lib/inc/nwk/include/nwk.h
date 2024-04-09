// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwk.h

  Summary:
    This file contains the Interface of NWK layer.

  Description:
    This file contains the Interface of NWK layer.
 *******************************************************************************/

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

#if !defined _NWK_H
#define _NWK_H

/******************************************************************************
                                 Includes section
 ******************************************************************************/
#include <nwk/include/nwkCommon.h>

#include <nwk/include/nldeData.h>
#include <nwk/include/nlmeDirectJoin.h>
#include <nwk/include/nlmeEdScan.h>
#include <nwk/include/nlmeJoin.h>
#include <nwk/include/nlmeLeave.h>
#include <nwk/include/nlmeNetworkDiscovery.h>
#include <nwk/include/nlmeNetworkFormation.h>
#include <nwk/include/nlmeNwkStatus.h>
#include <nwk/include/nlmePermitJoining.h>
#include <nwk/include/nlmeReset.h>
#include <nwk/include/nlmeRouteDiscovery.h>
#include <nwk/include/nlmeStartRouter.h>
#include <nwk/include/nlmeSync.h>
#include <nwk/include/nlmeSyncLoss.h>

/** Extra network headers */
#include <nwk/include/nwkAttributes.h>
#include <nwk/include/nwkSecurity.h>
#include <nwk/include/nwkAddressResolv.h>
#include <nwk/include/nwkNeighbor.h>
#include <nwk/include/nwkRouteInfo.h>
#include <nwk/include/nwkGroup.h>
#include <nwk/include/nwkRouteTable.h>

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NWK_Init shall be called only by APS and only once at startup.

  \return None.
 ******************************************************************************/
void NWK_Init(void);

/**************************************************************************//**
  \brief The stack don't sleep if this function return 'true'.

  \return 'true' if the network layer if active otherwise 'false'.
 ******************************************************************************/
bool NWK_IsActiveTransaction(void);

/**************************************************************************//**
  \brief NWK layer activities launching
 ******************************************************************************/
void NWK_LaunchActivities(void);

/**************************************************************************//**
  \brief NWK layer activities stopping
 ******************************************************************************/
void NWK_StopActivities(void);

/**************************************************************************//**
  \brief Determine if node has all the parameters required to operate in network.

  \return True if node has all the parameters required to operate in network false otherwise.
 ******************************************************************************/
bool NWK_DeviceIsAbleToOperateInNetwork(void);

/**************************************************************************//**
  \brief Force LinkStatus command transmission.
 ******************************************************************************/
void NWK_ForceLinkStatusSending(void);

#ifdef _GREENPOWER_SUPPORT_
/**************************************************************************//**
  \brief Force the node to change its own addr
 ******************************************************************************/
void NWK_ForceChangeOwnAddr(void);

#endif /* _GREENPOWER_SUPPORT_ */
#ifdef _CUSTOM_PASSIVE_ACK_THRESHOLD_
/**************************************************************************//**
  \brief Set the threshold value for passive ack

  \param[in] thresholdValue - Passive Ack threshold value to be set.
  \return None.
 ******************************************************************************/
void NWK_SetPassiveAckThreshold(uint8_t thresholdValue);
#endif /* _CUSTOM_PASSIVE_ACK_THRESHOLD_ */

#ifdef _CUSTOM_SUPPRESS_RETRANSMISSION_
/**************************************************************************//**
  \brief Enable or disable broadcast retransmissions

  \param[in] value - Boolean value 'true' to enale, 'false' to disable.
  \return None.
 ******************************************************************************/
void NWK_ConfigureBroadcastRetransmission(bool value);

/**************************************************************************//**
  \brief Enable or disable multicast retransmissions

  \param[in] value - Boolean value 'true' to enale, 'false' to disable.
  \return None. 
 ******************************************************************************/
void NWK_ConfigureMulticastRetransmission(bool value);

/**************************************************************************//**
  \brief Enable or disable Route Request retransmissions

  \param[in] value - Boolean value 'true' to enale, 'false' to disable
  \return None.
 ******************************************************************************/
void NWK_ConfigureRouteRequestRetransmission(bool value);

#endif /* _CUSTOM_SUPPRESS_RETRANSMISSION_ */

#endif  /* _NWK_H */
/** eof nwk.h */

