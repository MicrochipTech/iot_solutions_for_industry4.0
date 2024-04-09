// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Transmission Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkTx.h

  Summary:
    This file comprises the Interface of NWK transmission.

  Description:
    This file comprises the Interface of NWK transmission.
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
#if !defined _NWK_TX_H
#define _NWK_TX_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <nwk/include/nldeData.h>
#include <nwk/include/private/nwkDbg.h>
#include <systemenvironment/include/sysAssert.h>

/******************************************************************************
                               Definition section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
/** List of transmission parameters: delay type, prepare and confirm functions.
 * NOTE: Offset of tx parameters in this list must be equal tx id. */
#define NWK_TX_PARAMETERS \
{ \
  NWK_LINK_STATUS_TX_PARAMETERS,              /* NWK_LINK_STATUS_TX_ID */      \
  NWK_BROADCAST_STATUS_TX_PARAMETERS,         /* NWK_BROADCAST_STATUS_TX_ID */ \
  NWK_UNICAST_STATUS_TX_PARAMETERS,           /* NWK_UNICAST_STATUS_TX_ID */   \
  NWK_JOIN_REQ_TX_PARAMETERS,                 /* NWK_JOIN_REQ_TX_ID */         \
  NWK_ADDR_CONFLICT_JOIN_RESP_TX_PARAMETERS,  /* NWK_ADDR_CONFLICT_JOIN_RESP_TX_ID */ \
  NWK_JOIN_RESP_TX_PARAMETERS,                /* NWK_JOIN_RESP_TX_ID */        \
  NWK_LEAVE_ITSELF_TX_PARAMETERS,             /* NWK_LEAVE_ITSELF_TX_ID */     \
  NWK_LEAVE_CHILD_TX_PARAMETERS,              /* NWK_LEAVE_CHILD_TX_ID */      \
  NWK_REPORT_TX_PARAMETERS,                   /* NWK_REPORT_TX_ID */           \
  NWK_UPDATE_TX_PARAMETERS,                   /* NWK_UPDATE_TX_ID */           \
  NWK_ROUTE_REPLY_TX_PARAMETERS,              /* NWK_ROUTE_REPLY_TX_ID */      \
  NWK_INITIAL_ROUTE_REQ_TX_PARAMETERS,        /* NWK_INITIAL_ROUTE_REQ_TX_ID */\
  NWK_INITIAL_MANYTOONE_ROUTE_REQ_TX_PARAMETERS, /* NWK_INITIAL_MANYTOONE_ROUTE_REQ_TX_ID */\
  NWK_ROUTE_REQ_TX_PARAMETERS,                /* NWK_ROUTE_REQ_TX_ID */        \
  NWK_MANYTOONE_ROUTE_REQ_TX_PARAMETERS,      /* NWK_MANYTOONE_ROUTE_REQ_TX_ID */\
  NWK_ROUTE_RECORD_TX_PARAMETERS,             /* NWK_ROUTE_RECORD_TX_ID */     \
  NWK_MANY_TO_ONE_STATUS_TX_PARAMETERS,       /* NWK_MANY_TO_ONE_STATUS_TX_ID */\
  NWK_LEAVE_UNKNOWN_CHILD_PARAMETERS,         /* NWK_LEAVE_UNKNOWN_CHILD_TX_ID */ \
  NWK_ENDDEVICE_TIMEOUT_REQ_TX_PARAMETERS,    /* NWK_ENDDEVICE_TIMEOUT_REQ_TX_ID */ \
  NWK_ENDDEVICE_TIMEOUT_RESP_TX_PARAMETERS,   /* NWK_ENDDEVICE_TIMEOUT_RESP_TX_ID */ \
  \
  NWK_UNICAST_COMMAND_TRANSIT_TX_PARAMETERS,  /* NWK_UNICAST_COMMAND_TRANSIT_TX_ID */ \
  NWK_UNICAST_DATA_TRANSIT_TX_PARAMETERS,     /* NWK_UNICAST_DATA_TRANSIT_TX_ID */    \
  NWK_BROADCAST_TRANSIT_TX_PARAMETERS,        /* NWK_BROADCAST_TRANSIT_TX_ID */       \
  NWK_MULTICAST_MEMBER_TRANSIT_TX_PARAMETERS, /* NWK_MULTICAST_MEMBER_TRANSIT_TX_ID */\
  NWK_SOURCE_ROUTE_TRANSIT_TX_PARAMETERS,     /* NWK_SOURCE_ROUTE_TRANSIT_TX_ID */    \
  NWK_ROUTE_RECORD_TRANSIT_TX_PARAMETERS,     /* NWK_ROUTE_RECORD_TRANSIT_TX_ID */    \
  NWK_MANY_TO_ONE_TRANSIT_STATUS_TX_PARAMETERS, /* NWK_MANY_TO_ONE_TRANSIT_STATUS_TX_ID */\
  \
  NWK_UNICAST_DATA_TX_PARAMETERS,             /* NWK_UNICAST_DATA_TX_ID */     \
  NWK_BROADCAST_DATA_TX_PARAMETERS,           /* NWK_BROADCAST_DATA_TX_ID */   \
  NWK_MULTICAST_MEMBER_TX_PARAMETERS,         /* NWK_MULTICAST_MEMBER_TX_ID */ \
  NWK_SOURCE_ROUTE_TX_PARAMETERS              /* NWK_SOURCE_ROUTE_TX_ID */     \
}
// DOM-IGNORE-END

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Identifiers of transmission requests. */
typedef enum _NwkTxId_t
{
  NWK_LINK_STATUS_TX_ID = 0x00,
  NWK_BROADCAST_STATUS_TX_ID = 0x01,
  NWK_UNICAST_STATUS_TX_ID = 0x02,
  NWK_JOIN_REQ_TX_ID = 0x03,
  NWK_ADDR_CONFLICT_JOIN_RESP_TX_ID = 0x04,
  NWK_JOIN_RESP_TX_ID = 0x05,
  NWK_LEAVE_ITSELF_TX_ID = 0x06,
  NWK_LEAVE_CHILD_TX_ID = 0x07,
  NWK_REPORT_TX_ID = 0x08,
  NWK_UPDATE_TX_ID = 0x09,
  NWK_ROUTE_REPLY_TX_ID = 0x0A,
  NWK_INITIAL_ROUTE_REQ_TX_ID = 0x0B,
  NWK_INITIAL_MANYTOONE_ROUTE_REQ_TX_ID = 0x0C,
  NWK_ROUTE_REQ_TX_ID = 0x0D,
  NWK_MANYTOONE_ROUTE_REQ_TX_ID = 0x0E,
  NWK_ROUTE_RECORD_TX_ID = 0x0F,
  NWK_MANY_TO_ONE_STATUS_TX_ID = 0x10,
  NWK_LEAVE_UNKNOWN_CHILD_TX_ID = 0x11,
  NWK_ENDDEVICE_TIMEOUT_REQ_TX_ID = 0x12,
  NWK_ENDDEVICE_TIMEOUT_RESP_TX_ID = 0x13,
  NWK_MAX_COMMAND_TX_ID = NWK_ENDDEVICE_TIMEOUT_RESP_TX_ID,

  NWK_UNICAST_COMMAND_TRANSIT_TX_ID = 0x14,
  NWK_UNICAST_DATA_TRANSIT_TX_ID = 0x15,
  NWK_MULTICAST_NON_MEMBER_TRANSIT_TX_ID = NWK_UNICAST_DATA_TRANSIT_TX_ID,
  NWK_BROADCAST_TRANSIT_TX_ID = 0x16,
  NWK_MULTICAST_MEMBER_TRANSIT_TX_ID = 0x17,
  NWK_SOURCE_ROUTE_TRANSIT_TX_ID = 0x18,
  NWK_ROUTE_RECORD_TRANSIT_TX_ID = 0x19,
  NWK_MANY_TO_ONE_TRANSIT_STATUS_TX_ID = 0x1A,

  NWK_MIN_DATA_TX_ID = 0x1B,
  NWK_UNICAST_DATA_TX_ID = NWK_MIN_DATA_TX_ID,
  NWK_MULTICAST_NON_MEMBER_TX_ID = NWK_UNICAST_DATA_TX_ID,
  NWK_BROADCAST_DATA_TX_ID = 0x1C,
  NWK_MULTICAST_MEMBER_TX_ID = 0x1D,
  NWK_SOURCE_ROUTE_TX_ID = 0x1E,

  NWK_MAX_TX_ID
} NwkTxId_t;

/** Type of iterator for transmission identifiers. */
typedef uint8_t NwkTxIdIter_t;

/** Type of callback function for preparing an output packet. */
typedef void (* NwkPrepareTxFunc_t)(NwkOutputPacket_t *const);
/** Type of callback function for confirmation of packet transmission. */
typedef void (* NwkConfirmTxFunc_t)(NwkOutputPacket_t *const, const NWK_Status_t);

/** Internal variables of transmission component. */
typedef struct _NwkTx_t
{
  /** Queue of output packets */
  QueueDescriptor_t queue;
  
  /** Queue of output packets to be dropped */
  QueueDescriptor_t toBeDroppedQueue;
} NwkTx_t;

/** Internal states of output packet for debug. */
typedef enum _NwkOutPktState_t
{
  NWK_OUTPKT_IN_QUEUE_STATE = 0x00,
  NWK_OUTPKT_RDISCOVERY_STATE = 0x01,
  NWK_OUTPKT_MAC_STATE = 0x02,
  NWK_OUTPKT_DELAY_STATE = 0x03,
  NWK_OUTPKT_ENCRYPT_STATE = 0x04,
  NWK_OUTPKT_DECRYPT_STATE = 0x05,
  NWK_OUTPKT_ROUTE_RECORD_STATE = 0x06,
  NWK_OUTPKT_TO_BE_DROPPED_STATE = 0x07
} NwkOutPktState_t;

/******************************************************************************
                   Inline static functions prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Is this packet a network data?

  \param[in] outPkt - pointer to the output network packet.
  \return 'true' if this output packet is data packet otherwise return 'false'.
 ******************************************************************************/
INLINE bool nwkIsDataPacket(const NwkOutputPacket_t *const outPkt)
{
  /** For FATAL, third param(false) has no effect */
  SYS_E_ASSERT_FATAL((outPkt->txId < NWK_MAX_TX_ID), NWKTX_NWKISDATAPACKET0);

  return (NWK_MIN_DATA_TX_ID <= outPkt->txId);
}

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Request to transmit the output packet.

  \param[in] outPkt - pointer to the output network packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkTxReq(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Main task handler of the packet transmission component
 ******************************************************************************/
NWK_PRIVATE void nwkTxTaskHandler(void);

/**************************************************************************//**
  \brief Reset the packet transmission component.
 ******************************************************************************/
NWK_PRIVATE void nwkResetTx(void);

/**************************************************************************//**
  \brief Confirmation of packet transmission.

  \param[in] outPkt - pointer to output packet.
  \param[in] status - network status of packet transmission.

  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkTxConf(NwkOutputPacket_t *const outPkt, const NWK_Status_t status);

/**************************************************************************//**
  \brief Write default values to parameters of MAC_DataReq request.

  \param[in] outPkt - pointer to an output packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkInitMacDataReq(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Start packet transmission.

  \param[in] outPkt - pointer to output packet.
  \param[in] encrypt - if 'true' then packet encrypting is required.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkTransmitOutputPacket(NwkOutputPacket_t *const outPkt, const bool encrypt);

  /**************************************************************************//**
  \brief Drops the output packet rising callback with unsuccessful status.

  \param[in] outPkt - pointer to output packet.
 ******************************************************************************/
NWK_PRIVATE void nwkDropPacket(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Checks if the output packet has correct parameters.

  \param[in] outPkt - pointer to output packet.
  \return true if the output packet is valid, false otherwise.
 ******************************************************************************/
NWK_PRIVATE bool nwkIsOutPacketValid(NwkOutputPacket_t *const outPkt);

#endif /* _NWK_TX_H */
/** eof nwkTx.h */

