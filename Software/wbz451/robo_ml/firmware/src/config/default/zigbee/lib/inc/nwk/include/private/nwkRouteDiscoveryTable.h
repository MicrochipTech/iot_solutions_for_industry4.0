// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Route Discovery Table Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkRouteDiscoveryTable.h

  Summary:
    This file contains the Interface of the route discovery table.

  Description:
    This file contains the Interface of the route discovery table.
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
    A ZigBee router or ZigBee coordinator maintains a route discovery table
    containing the information that is required during route discovery.
   */
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#if !defined _NWK_ROUTE_DISCOVERY_TABLE_H
#define _NWK_ROUTE_DISCOVERY_TABLE_H
// DOM-IGNORE-END

/******************************************************************************
                                 Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <nwk/include/private/nwkSystem.h>
#include <zdo/include/appFramework.h>
#include <hal/include/appTimer.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/nlmeRouteDiscovery.h>
#include <nwk/include/private/nwkPacket.h>

/******************************************************************************
                                 Define(s) section
 ******************************************************************************/
#define NWK_RDISC_IS_MANY_TO_ONE(routeDiscoveryEntry) \
  (NWK_DSTADDRMODE_NOADDR == (routeDiscoveryEntry)->dstAddrMode)
#define NWK_RDISC_IS_MULTICAST(routeDiscoveryEntry) \
  (NWK_DSTADDRMODE_MULTICAST == (routeDiscoveryEntry)->dstAddrMode)
#define NWK_RDISC_IS_UNICAST(routeDiscoveryEntry) \
  (NWK_DSTADDRMODE_SHORT == (routeDiscoveryEntry)->dstAddrMode)

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** Route discovery table entry. See ZigBee spec r18, Table 3.53, page 391. */
typedef struct _NwkRouteDiscoveryEntry_t
{
  /** Time-to-live of entry. If this field is equal to 0 then entry is inactive.
   **/
  uint8_t ttl;
  /* For this entry route request transmission is required or not. */
  bool routeRequestRequired : 1;
  /** A flag indicating that route request is required on originator. */
  bool initialRouteRequest  : 1;
  /* For this entry route reply transmission is required or not. */
  bool routeReplyRequired   : 1;
  bool highPriority         : 1;
  /** A flag indicating that the concentrator does not store source routes. */
  bool noRouteCache         : 1;
  /* - NWK_DSTADDRMODE_NOADDR - this value indicating that the source node
   *     is a concentrator that issued a many-to-one route request.
   * - NWK_DSTADDRMODE_MULTICAST - the destination address is a Group ID.
   * - NWK_DSTADDRMODE_SHORT - unicast route discovery.
   * */
  NwkBitField_t dstAddrMode : 2;
  bool reserved             : 1;
  /** The accumulated path cost from the source of
   * the route request to the current device. */
  NwkPathCost_t forwardCost;
  /** The accumulated path cost from the current device
   * to the destination device. */
  NwkPathCost_t residualCost;
  /** The 16-bit network address of the route request's initiator. */
  ShortAddr_t srcAddr;
  /** The 16-bit network address of the device that has sent the most recent
   * lowest cost route request command frame corresponding to this entry's
   * route request identifier and source address. This field is used to
   * determine the path that an eventual route reply command frame should
   * follow. */
  ShortAddr_t senderAddr;
  /** Destination short address or group id of route discovery request. */
  ShortAddr_t dstAddr;
  /** A sequence number for a route request command frame that is incremented
   * each time a device initiates a route request. */
  NwkRouteRequestId_t routeRequestId;
  /** Value of the radius field for the new rebroadcasted route request. */
  NwkRadius_t rreqRadius;
  /** Value of the radius field of the route replay command with the best cost. */
  NwkRadius_t rrepRadius;
  /** Sequence number of initial route request command. */
  uint8_t sequenceNumber;
  /** Initial route request parameters. */
  NWK_RouteDiscoveryReq_t *req;
  /** Pointer to output network packet. */
  NwkOutputPacket_t *outPkt;
} NwkRouteDiscoveryEntry_t;

/** State of processing of incoming requests to send route request
    or reply commands. */
typedef enum _NwkRouteDiscoveryTableState_t
{
  NWK_RDISC_TABLE_IDLE_STATE = 0x00,
  /** Preparing and sending of route reqply or request command. */
  NWK_RDISC_TABLE_REQUEST_PROCESSING_STATE = 0x93,
  /** Wating a free packet from the network packet manager. */
  NWK_RDISC_TABLE_WAIT_PACKET_STATE = 0x1A
} NwkRouteDiscoveryTableState_t;

/**
   Route discovery table - a table used by a ZigBee coordinator or ZigBee router
   to store temporary information used during route discovery.
   */
typedef struct _NwkRouteDiscoveryTable_t
{
  /** The countdown timer that is used for decrement of time-to-live fields.*/
  HAL_AppTimer_t timer;
  /** Pointer to the route discovery table. */
  NwkRouteDiscoveryEntry_t *table;
  /** Pointer to memory area after last entry of the route discovery table. */
  NwkRouteDiscoveryEntry_t *end;
  /** Current state of the route discovery table. */
  NwkRouteDiscoveryTableState_t state;
  /** Boolean flag indicating that the countdown timer is started. */
  bool isTimerStarted;
} NwkRouteDiscoveryTable_t;

/** Type of size of the route discovery table. */
typedef uint8_t NwkRouteDiscoveryTableSize_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
#if defined NWK_ROUTING_CAPACITY \
  && (defined _NWK_MESH_ROUTING_ || defined _NWK_MANY_TO_ONE_ROUTING_)
/**************************************************************************//**
  \brief Allocate place for new discovery request in the route discovery table.

  \param[in] highPriority - if new entry is important
    then this parameter is 'true' otherwise 'false'.
  \return Pointer to an allocated route discovery entry or NULL.
 ******************************************************************************/
NWK_PRIVATE NwkRouteDiscoveryEntry_t* nwkAllocRouteDiscoveryEntry(const bool highPriority);

/**************************************************************************//**
  \brief Find an active route discovery entry by route request id and source address.

  \param[in] srcAddr - network address of route discovery originator.
  \param[in] requestId - identifier of initial route request.
  \return Pointer to a route discovery entry or NULL if entry is not found.
 ******************************************************************************/
NWK_PRIVATE NwkRouteDiscoveryEntry_t* nwkFindRouteDiscoveryEntry(const ShortAddr_t srcAddr,const NwkRouteRequestId_t requestId);
  
/**************************************************************************//**
  \brief Find whether route discovery entry exists.

  \param[in] dstAddr - network address of route discovery destination.
  \param[in] srcAddr - network address of route discovery originator.
  \return true/false
 ******************************************************************************/
NWK_PRIVATE bool nwkIsRouteDiscoveryEntryExist(const ShortAddr_t dstAddr, const ShortAddr_t srcAddr);

/**************************************************************************//**
  \brief Main task handler of the NWK route discovery component.
 ******************************************************************************/
NWK_PRIVATE void nwkRouteDiscoveryTableTaskHandler(void);

/**************************************************************************//**
  \brief Indication about network packet realizing.
 ******************************************************************************/
NWK_PRIVATE void nwkRouteDiscoveryTableFreePacketInd(void);

/**************************************************************************//**
  \brief Reset internal state and entries of the route discovery table.
 ******************************************************************************/
NWK_PRIVATE void nwkResetRouteDiscoveryTable(void);

#if defined _NWK_MESH_ROUTING_ || defined _NWK_CONCENTRATOR_
/**************************************************************************//**
  \brief Stop processing of route discovery entries.
 ******************************************************************************/
NWK_PRIVATE void nwkFlushRouteDiscoveryTable(void);
#endif /* _NWK_MESH_ROUTING_ or _NWK_CONCENTRATOR_ */

/**************************************************************************//**
  \brief Prepare and send the route request command.

  \param[in] entry - pointer to a route discovery entry that is required
    transmission of route request command.
  \param[in] isInitialRequest - 'true' if this node is originator
    of route discovery otherwise 'false'.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkSendRouteDiscoveryRequest(NwkRouteDiscoveryEntry_t *const entry, const bool isInitialRequest);

/***************************************************************************//**
  \brief nwkRouteDiscoveryTable idle checking.

  \return true, if nwkRouteDiscoveryTable performs no activity, false - otherwise.
 ******************************************************************************/
NWK_PRIVATE bool nwkRouteDiscoveryTableIsIdle(void);

#if defined _NWK_MESH_ROUTING_
/**************************************************************************//**
  \brief Prepare and send the route reply command.

  \param[in] entry - pointer to a route discovery entry that is required
    transmission of route reply command.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkSendRouteDiscoveryReply(NwkRouteDiscoveryEntry_t *const entry);
#endif /* _NWK_MESH_ROUTING_ */

/**************************************************************************//**
  \brief Reliably adding a path cost and a link cost.

  \param[in] pathCost - cost of path.
  \param[in] linkCost - cost of link.
  \return Summary path cost.
 ******************************************************************************/
NWK_PRIVATE NwkPathCost_t nwkSumPathCost(const NwkPathCost_t pathCost,const NwkLinkCost_t linkCost);

/**************************************************************************//**
  \brief Confirmation of the route request transmission.

  \param[in] outPkt - pointer to output packet.
  \param[in] status - network status of route request transmission.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkConfirmRouteRequestTx(NwkOutputPacket_t *const outPkt,const NWK_Status_t status);

/**************************************************************************//**
  \brief Compare new path cost with old path cost.

  \param[in] oldCost - path cost from the route discovery table.
  \param[in] newCost - path cost from a route request or a route reply command.

  \return 'true' if new path cost is better than old one otherwise return 'false'.
 ******************************************************************************/
NWK_PRIVATE bool nwkIsBestPathCost(const uint16_t oldCost, const uint16_t newCost);

#else /* NWK_ROUTING_CAPACITY and _NWK_MESH_ROUTING_ */

#define nwkRouteDiscoveryTableTaskHandler NULL
#define nwkConfirmRouteRequestTx NULL
#define nwkRouteDiscoveryTableIsIdle NULL
#define nwkResetRouteDiscoveryTable() (void)0
#define nwkRouteDiscoveryTableFreePacketInd() (void)0

#endif /* NWK_ROUTING_CAPACITY and (_NWK_MESH_ROUTING_ or _NWK_MANY_TO_ONE_ROUTING_) */
#endif /* _NWK_ROUTE_DISCOVERY_TABLE_H */
/* eof nwkRouteDiscoveryTable.h */

