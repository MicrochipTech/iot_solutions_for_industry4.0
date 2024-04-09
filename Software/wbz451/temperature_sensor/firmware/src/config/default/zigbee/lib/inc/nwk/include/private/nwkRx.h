// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Rx Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkRx.h

  Summary:
    This file contains the Functions for processing of received input data.

  Description:
    This file contains the Functions for processing of received input data.
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

// DOM-IGNORE-BEGIN
#if !defined _NWK_RX_H
#define _NWK_RX_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/private/nwkSystem.h>
#include <nwk/include/private/nwkFrame.h>
#include <nwk/include/nldeData.h>
#include <nwk/include/private/nwkTx.h>
#if defined _SECURITY_
#include <security/serviceprovider/include/sspSfp.h>
#endif /* _SECURITY_ */

/******************************************************************************
                              Definition section
 ******************************************************************************/
#define NWK_UNICAST_COMMAND_TRANSIT_TX_PARAMETERS \
  {NWK_TX_DELAY_UNICAST_COMMAND, NULL, NULL, true}
#define NWK_UNICAST_DATA_TRANSIT_TX_PARAMETERS \
  {NWK_TX_DELAY_TRANSIT_DATA, NULL, NULL, true}
#define NWK_BROADCAST_TRANSIT_TX_PARAMETERS \
  {NWK_TX_DELAY_BROADCAST, NULL, NULL, true}
#define NWK_MULTICAST_MEMBER_TRANSIT_TX_PARAMETERS \
  {NWK_TX_DELAY_MULTICAST, NULL, NULL, true}

/******************************************************************************
                                 Types section
 ******************************************************************************/
 
/** Input packet meta information. */
typedef struct _NwkInputPacket_t
{
  bool retransmit      : 1;
  bool decryptRequired : 1;
  bool indicate        : 1;
  NwkBitField_t txId   : 5;
  uint8_t *data;
  NwkLength_t length;
  NwkParseHeader_t parsedHeader;
  union
  {
    NWK_DataInd_t dataInd;
#if defined _SECURITY_
    SSP_DecryptFrameReq_t decryptReq;
#endif /* _SECURITY_ */
  } primitive;
} NwkInputPacket_t;

/******************************************************************************
                             Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
  \brief The upper layer has completed data processing.

  \param[in] resp - NLDE-DATA indication primitive's parameters structure.
  \return None.
 ******************************************************************************/
void NWK_DataResp(NWK_DataResp_t *resp);

#if defined(_ROUTER_) || defined(_COORDINATOR_) 
/***************************************************************************//**
  \brief Fill Neighbor table with default information and given parameters

  \param[in] neighbor - entry to be filled.
  \param[in] extAddr - extended IEEE 64-bit address of sender.
  \param[in] shortAddr - network address of sender.
  \param[in] lqi - link quality of the received frame
                   command from MAC layer.
  \param[in] rssi - RSSI of the received frame.

  \return None.
 ******************************************************************************/
void nwkFillNeighborEntryRxFrame(NwkNeighbor_t *neighbor, const ExtAddr_t extAddr, const ShortAddr_t shortAddr, const Lqi_t lqi, const Rssi_t rssi);
#endif

#endif /* _NWK_RX_H */
/** eof nwkRx.h */

