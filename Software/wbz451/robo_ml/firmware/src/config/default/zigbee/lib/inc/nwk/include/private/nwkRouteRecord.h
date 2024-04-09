// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Route Record Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkRouteRecord.h

  Summary:
    This file contains the Interface of NWK Route Record functionality.

  Description:
    This file contains the Interface of NWK Route Record functionality.
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


/**
    The route record command allows the route taken by a unicast packet
    through the network to be recorded in the command payload and delivered
    to the destination device. ZigBee spec r18, 3.4.5, page 330.
    */
// DOM-IGNORE-END
 
// DOM-IGNORE-BEGIN
#if !defined _NWK_ROUTE_RECORD_H
#define _NWK_ROUTE_RECORD_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <systemenvironment/include/sysQueue.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/nldeData.h>
#include <nwk/include/private/nwkFrame.h>

/******************************************************************************
                               Define(s) section
 ******************************************************************************/
#define NWK_ROUTE_RECORD_TX_PARAMETERS \
  {NWK_TX_DELAY_INITIAL_ROUTE_RECORD, nwkPrepareRouteRecordTx, \
   nwkConfirmRouteRecordTx, true}
#define NWK_ROUTE_RECORD_TRANSIT_TX_PARAMETERS \
  {NWK_TX_DELAY_UNICAST_COMMAND, nwkPrepareTransitRouteRecordTx, NULL, true}
#define NWK_IS_NOT_ROUTE_RECORD(outPkt) \
  ((NWK_ROUTE_RECORD_TX_ID != (outPkt)->txId) && \
   (NWK_ROUTE_RECORD_TRANSIT_TX_ID != (outPkt)->txId))

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Route record command format. ZigBee spec r18, Figure 3.18, page 330. */
BEGIN_PACK
typedef struct PACK _NwkRouteRecordPayload_t
{
  /** The identifier of the route request command. */
  uint8_t commandId;
  /** This field contains the number of relays in the relay list field of
   * the route record command. ZigBee spec r18, 3.4.5.3.1, page 331. */
  uint8_t relayCount;
  /** The relay list field is a list of the 16-bit network addresses of the nodes
   * that have relayed the packet. ZigBee spec r18, 3.4.5.3.2, page 331. */
  ShortAddr_t relayList[NWK_MAX_SOURCE_ROUTE];
} NwkRouteRecordPayload_t;
END_PACK

/** Internal states of the route record component */
typedef enum _NwkRouteRecordState_t
{
  NWK_ROUTE_RECORD_IDLE_STATE = 0x2E,
  NWK_ROUTE_RECORD_FIRST_STATE = 0xF6,
  NWK_ROUTE_RECORD_BEGIN_STATE = NWK_ROUTE_RECORD_FIRST_STATE,
  NWK_ROUTE_RECORD_PREPARE_STATE = 0xF7,
  NWK_ROUTE_RECORD_SEND_STATE = 0xF8,
  NWK_ROUTE_RECORD_CONFIRM_STATE = 0xF9,
  NWK_ROUTE_RECORD_LAST_STATE
} NwkRouteRecordState_t;

/** Internal variables and state of the route record component. */
typedef struct _NwkRouteRecord_t
{
  QueueDescriptor_t queue; /**< Queue of requests from other NWK components. */
  NwkRouteRecordState_t state; /**< finite-state machine. */
} NwkRouteRecord_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
#if defined NWK_ROUTING_CAPACITY && defined _NWK_ROUTE_RECORD_
/**************************************************************************//**
  \brief Send the route record command before given output packet.

  \param[in] outPkt - pointer to output packet for which route record is sending.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkRouteRecordReq(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Transmission of the route record command is done.

  \param[in] outPkt - pointer to output packet for which route record is sending.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkRouteRecordConf(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Prepare header and payload of the route record command.

  \param outPkt - pointer to output packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkPrepareRouteRecordTx(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Confirmation of the route record command transmission.

  \param outPkt - pointer to output packet.
  \param status - network status of route record transmission.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkConfirmRouteRecordTx(NwkOutputPacket_t *const outPkt,const NWK_Status_t status);

/**************************************************************************//**
  \brief Relay list of transit route record is changed.

  \param outPkt - pointer to output packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkPrepareTransitRouteRecordTx(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Reset the route record component.
 ******************************************************************************/
NWK_PRIVATE void nwkResetRouteRecord(void);

/**************************************************************************//**
  \brief Main task handler of the route record component.
 ******************************************************************************/
NWK_PRIVATE void nwkRouteRecordTaskHandler(void);

#else /* NWK_ROUTING_CAPACITY and _NWK_ROUTE_RECORD_ */

#define nwkPrepareRouteRecordTx NULL
#define nwkConfirmRouteRecordTx NULL
#define nwkPrepareTransitRouteRecordTx NULL
#define nwkResetRouteRecord() (void)0
#define nwkRouteRecordTaskHandler NULL

#endif /* NWK_ROUTING_CAPACITY and _NWK_ROUTE_RECORD_ */

#if defined NWK_ROUTING_CAPACITY && defined _NWK_ROUTE_CACHE_
/***************************************************************************//**
  \brief Action when a route record command is received.

  \param payload - pointer to raw command payload.
  \param header  - pointer to raw NWK header of command.
  \param parse   - parsed NWK header fields.
  \return 'true' if continue processing of command packet otherwise 'false'.
 ******************************************************************************/
NWK_PRIVATE bool nwkRouteRecordFrameInd(const uint8_t *const payload, const NwkFrameHeader_t *const header, const NwkParseHeader_t *const parse);

#else /* NWK_ROUTING_CAPACITY and _NWK_ROUTE_CACHE_*/
#define nwkRouteRecordFrameInd NULL
#endif /* NWK_ROUTING_CAPACITY and _NWK_ROUTE_CACHE_ */

#endif /* _NWK_ROUTE_RECORD_H */
/** eof nwkRouteRecord.h */

