// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Routing Table Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkRoutingTable.h

  Summary:
    This file comprises the Interface of NWK Routing Table.

  Description:
    This file comprises the Interface of NWK Routing Table.
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
#if !defined _NWK_ROUTING_TABLE_H
#define _NWK_ROUTING_TABLE_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/private/nwkSystem.h>
#include <nwk/include/nwkRouteTable.h>

/******************************************************************************
                                Types section
 ******************************************************************************/

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
#if defined NWK_ROUTING_CAPACITY \
  && (defined _NWK_MESH_ROUTING_ || defined _NWK_MANY_TO_ONE_ROUTING_)
/**************************************************************************//**
  \brief Allocate a new entry in the routing table.

  \return pointer to an entry or NULL.
 ******************************************************************************/
NWK_PRIVATE NwkRoutingTableEntry_t* nwkAllocRoutingEntry(void);

/**************************************************************************//**
  \brief Free an entry of the routing table.

  \param[in] dstAddr - the short address of destination node.
  \param[in] isGroupId - 'true' if dstAddr is group id otherwise 'false'.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkFreeRoutingEntry(const ShortAddr_t dstAddr,const bool isGroupId);

/**************************************************************************//**
  \brief Free all entries with the given next hop.

  \param[in] nextHop - the short address of next hop node.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkDeleteNextHop(const ShortAddr_t nextHop);

/**************************************************************************//**
  \brief Delete the device from the routing table.

    Free all entries with next hop address or destination address are equal
  to the given short address.

  \param[in] shortAddr - the short address of removed node.
  \return None.
 ******************************************************************************/
INLINE void nwkDeleteFromRoutingTable(const ShortAddr_t shortAddr)
{
  nwkFreeRoutingEntry(shortAddr, false);
  nwkDeleteNextHop(shortAddr);
}

/**************************************************************************//**
  \brief Find a routing table entry by destination address.

  \param[in] dstAddr - a short address of destination node.
  \param[in] isGroupId - 'true' if dstAddr is group id otherwise 'false'.

  \return pointer to a routing table entry with given dstAddr.
 ******************************************************************************/
NWK_PRIVATE NwkRoutingTableEntry_t* nwkFindRoutingEntry(const ShortAddr_t dstAddr, const bool isGroupId);

/***************************************************************************//**
 \brief Update information of the routing table entry after a packet transmission.

 \param[in] entry - pointer to an entry in the routing table.
 \param status - NWK status of packet transmission.
 ******************************************************************************/
NWK_PRIVATE void nwkUpdateRoutingEntry(NwkRoutingTableEntry_t *const entry, const NWK_Status_t status);

/**************************************************************************//**
  \brief Reset the routing table.
 ******************************************************************************/
NWK_PRIVATE void nwkResetRoutingTable(void);

#if defined _NWK_MESH_ROUTING_
/**************************************************************************//**
  \brief Setting the next hop address of the routing table entry.

  \param[in] dstAddr - a short address of destination node.
  \param[in] nextHopAddr - short address of next hop node.
  \param[in] isGroupId - 'true' if dstAddr is group id otherwise 'false'.
  \param[in] cost - cost of path to destination node.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkUpdateNextHop(const ShortAddr_t dstAddr,const bool isGroupId, const ShortAddr_t nextHopAddr,const NwkPathCost_t cost);

#else
#define nwkUpdateNextHop(dstAddr, isGroupId, nextHopAddr, cost) (void)0
#endif /* _NWK_MESH_ROUTING_ */
#else /* NWK_ROUTING_CAPACITY and (_NWK_MESH_ROUTING_ or _NWK_MANY_TO_ONE_ROUTING_) */

#define nwkResetRoutingTable() (void)0
#define nwkUpdateNextHop(dstAddr, isGroupId, nextHopAddr, cost) (void)0
#define nwkFreeRoutingEntry(dstAddr, isGroupId) (void)0
#define nwkRemoveNextHop(nextHop) (void)0
#define nwkDeleteFromRoutingTable(shortAddr) (void)0

#endif /* NWK_ROUTING_CAPACITY and (_NWK_MESH_ROUTING_ or _NWK_MANY_TO_ONE_ROUTING_) */
#endif /* _NWK_ROUTING_TABLE_H */
/** eof nwkRoutingTable.h */

