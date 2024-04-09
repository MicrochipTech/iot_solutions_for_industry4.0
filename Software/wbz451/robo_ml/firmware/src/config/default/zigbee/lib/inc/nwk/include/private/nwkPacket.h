// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Packet Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkPacket.h

  Summary:
    This file defines the Interface to the network packet manager.

  Description:
    This file defines the Interface to the network packet manager.
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
#if !defined _NWK_PACKET_H
#define _NWK_PACKET_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <systemenvironment/include/sysQueue.h>
#include <mac_phy/include/mac.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/private/nwkRx.h>
#include <nwk/include/private/nwkTx.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of network packet. */
typedef enum _NwkPacketType_t
{
  NWK_UNKNOWN_PACKET = 0x0,
  /** Command packet from NWK component. */
  NWK_OUTPUT_COMMAND_PACKET = 0x1,
  /** CHILD Command packet from NWK component. */
  NWK_OUTPUT_COMMAND_CHILD_PACKET = 0x2,
  /** Command packet from MAC-layer. */
  NWK_INPUT_COMMAND_PACKET = 0x3,
  /** Data packet from MAC-layer. */
  NWK_INPUT_DATA_PACKET = 0x4,
  /** Transit packet from MAC-layer. */
  NWK_TRANSIT_PACKET = 0x5,
  /** Loopback transmission from APS-layer. */
  NWK_LOOPBACK_PACKET = 0x6,
  /** Data packet from an external layer. */
  NWK_EXTERN_PACKET = 0x7,
  NWK_BUFFER_TYPE_LAST
} NwkPacketType_t;

/** Network packet type. */
typedef struct _NwkPacket_t
{
  /** Network packet type. */
  NwkPacketType_t type;
  TOP_GUARD
  uint8_t macHeader[MAC_MSDU_OFFSET];
  uint8_t macPayload[MAC_MAX_MSDU_SIZE];
#if (MAC_AFFIX_LENGTH - MAC_MSDU_OFFSET)
  uint8_t macFooter[MAC_AFFIX_LENGTH - MAC_MSDU_OFFSET];
#endif
  BOTTOM_GUARD
  union
  {
    /** Service information for incoming packet from MAC-layer. */
    NwkInputPacket_t in;
    /** Service information for outgoing packet from NWK-layer. */
    NwkOutputPacket_t out;
#if defined _NWK_ALLOCATOR_
    /** Service information for outgoing packet from an upper-layer. */
    NwkExternPacket_t ext;
#endif /* _NWK_ALLOCATOR_ */
  } pkt;
} NwkPacket_t;

/** Type of total amount of network packets. */
typedef uint8_t NwkPacketsAmount_t;

/** Internal variables of the network packet manager. */
typedef struct _NwkPacketManager_t
{
  /** Array of network packets. */
  NwkPacket_t *pkt;
  /** Total amount of network packets. */
  NwkPacketsAmount_t amount;
  /** Queue of external packet allocation requests. */
  QueueDescriptor_t queue;
} NwkPacketManager_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Allocate a free memory space for an input packet with type.

  \param[in] type - type of packet.
  \param[in] length - needed packet length.
  \return Pointer to input packet or NULL.
 ******************************************************************************/
NWK_PRIVATE NwkInputPacket_t* nwkAllocInputPacket(const NwkPacketType_t type,
  const NwkLength_t length);

/**************************************************************************//**
  \brief Free an input packet.

  \param[in] inPkt - pointer to an input packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkFreeInputPacket(NwkInputPacket_t *const inPkt);

/**************************************************************************//**
  \brief Allocate a free memory space for an output.

  \param[in] type - type of output packet.
  \return Pointer to output packet or NULL.
 ******************************************************************************/
NWK_PRIVATE NwkOutputPacket_t* nwkAllocOutputPacket(const NwkPacketType_t type);

/**************************************************************************//**
  \brief Free an output packet.

  \param[in] outPkt - pointer to an output packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkFreeOutputPacket(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Reset the network packet manager.
 ******************************************************************************/
NWK_PRIVATE void nwkResetPacketManager(void);

#if defined NWK_ROUTING_CAPACITY
/**************************************************************************//**
  \brief To transform an input packet to the output packet.

  \param[in] inPkt - pointer to an input packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE
NwkOutputPacket_t* nwkTransformInToOutPacket(NwkInputPacket_t *const inPkt);
#endif /* NWK_ROUTING_CAPACITY */

#if defined _NWK_ALLOCATOR_
/**************************************************************************//**
  \brief Process an incoming request to allocate memory for NWK_DataReq.
 ******************************************************************************/
NWK_PRIVATE void nwkAllocDataReqTaskHandler(void);

#else
#define nwkAllocDataReqTaskHandler NULL
#endif /* _NWK_ALLOCATOR_ */
#endif /* _NWK_PACKET_H */
/** eof nwkPacket.h */

