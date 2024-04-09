// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Neighbor Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkNeighbor.h

  Summary:
    This file contains the NWK layer Neighbor table interface.

  Description:
    This file contains the NWK layer Neighbor table interface.
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

/**//**
 *  The neighbor table of a device shall contain information on every device
 * within transmission range. ZigBee Spec r17, 3.6.1.5, page 366.
 **/
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#if !defined _NWK_NEIGHBOR_H
#define _NWK_NEIGHBOR_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <hal/include/appTimer.h>
#include <nwk/include/nwkCommon.h>
#ifdef _CHILD_MANAGEMENT_
#include <nwk/include/nwkEndDeviceTimeout.h>
#endif

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** The relationship between the neighbor and the current device */
typedef enum _Relationship_t
{
  RELATIONSHIP_PARENT                = 0x00, /**< neighbor is the parent */
  RELATIONSHIP_CHILD                 = 0x01, /**< neighbor is a child */
  RELATIONSHIP_SIBLING               = 0x02, /**< neighbor is a sibling */
  RELATIONSHIP_NONE_OF_ABOVE         = 0x03, /**< none of the above */
  RELATIONSHIP_PREVIOUS_CHILD        = 0x04, /**< previous child */
  RELATIONSHIP_UNAUTHENTICATED_CHILD = 0x05, /**< unauthenticated child */
  RELATIONSHIP_EMPTY
} Relationship_t;

/** The neighbor table item. */
typedef struct _NwkNeighbor_t
{
  Relationship_t relationship;
  /** The type of neighbor device. */
  DeviceType_t deviceType;
  /** IEEE 802.15.4-2006 7.3.1.2 Capability Information field. */
  MAC_CapabilityInf_t capability;
  /** The logical channel on which the network is operating. */
  Channel_t logicalChannel;
  /** The 16-bit network address of the neighboring device. */
  ShortAddr_t networkAddr;
  PanId_t panId;
  /** 64-bit IEEE address that is unique to every device. */
  ExtAddr_t extAddr;
  /** The 64-bit unique identifier of the network to which the device belongs.*/
  ExtPanId_t extPanId;
  /** The tree depth of the neighbor device. */
  NwkDepth_t depth;
  /** The value identifying a snapshot of the network settings with which this
   * node is operating with.*/
  NwkUpdateId_t updateId;
  /** Indicates if neighbor's receiver is enabled during idle periods. */
  bool rxOnWhenIdle       :1;
  /** An indication of whether the device is accepting joining requests. */
  bool permitJoining      :1;
  /** An indication of whether the device has been
   * ruled out as a potential parent. */
  bool potentialParent    :1;
  /** Network address of the neighbor is conflict with other address in network.
   **/
  bool isAddressConflict  :1;
  /** Upper layer knowns about this child (true) or not (false).*/
  bool isKnownChild       :1;
  unsigned reserved1      :3;

 
#ifdef _CHILD_MANAGEMENT_
  /** The end deviceâ??s configuration. */
  uint16_t endDeviceConfiguration;
  /** This field indicates the timeout, in seconds, for the end device child. */
  uint32_t deviceTimeout;
  /** This link is used to traverse next End Device in case of hash collision **/
  struct _NwkNeighbor_t *next;
#endif /* _CHILD_MANAGEMENT_ */
} NwkNeighbor_t;

/** The neighbor table item. */
typedef struct _NwkNeighborR20_t
{
  Relationship_t relationship;
  /** The type of neighbor device. */
  DeviceType_t deviceType;
  /** IEEE 802.15.4-2006 7.3.1.2 Capability Information field. */
  MAC_CapabilityInf_t capability;
  /** The logical channel on which the network is operating. */
  Channel_t logicalChannel;
  /** The 16-bit network address of the neighboring device. */
  ShortAddr_t networkAddr;
  PanId_t panId;
  /** 64-bit IEEE address that is unique to every device. */
  ExtAddr_t extAddr;
  /** The 64-bit unique identifier of the network to which the device belongs.*/
  ExtPanId_t extPanId;
  /** The tree depth of the neighbor device. */
  NwkDepth_t depth;
  /** The value identifying a snapshot of the network settings with which this
   * node is operating with.*/
  NwkUpdateId_t updateId;
  /** Indicates if neighbor's receiver is enabled during idle periods. */
  bool rxOnWhenIdle       :1;
  /** An indication of whether the device is accepting joining requests. */
  bool permitJoining      :1;
  /** An indication of whether the device has been
   * ruled out as a potential parent. */
  bool potentialParent    :1;
  /** Network address of the neighbor is conflict with other address in network.
   **/
  bool isAddressConflict  :1;
  /** Upper layer knowns about this child (true) or not (false).*/
  bool isKnownChild       :1;
  unsigned reserved1      :3;
} NwkNeighborR20_t;

#ifdef _CHILD_MANAGEMENT_
/** Nwk End Device Hash used to respond Data Request as Per R21 **/
typedef struct _NwkEndDeviceHash_t
{
  uint16_t hashMap;
  NwkNeighbor_t *head;
}NwkEndDeviceHash_t;
#endif


/** Type of life time of neighbors in ticks. */
#ifdef _CHILD_MANAGEMENT_
typedef uint32_t NwkLifeTime_t;
#else
typedef uint16_t NwkLifeTime_t;
#endif
/** The bit map of passive acks, each bit is matched to a broadcast that
 * waits passive acknowledgements. */
typedef uint8_t NwkPassiveAckMap_t;

/** Mutable fields of a entry in the neighbor table. */
typedef struct _NwkMutablePartOfNeighbor_t
{
  /** The time of life of a neighbor entry. */
  NwkLifeTime_t lifeTime;
  /** The estimated link quality for RF transmissions from this device. */
  Lqi_t lqi;
  Rssi_t rssi;
  /** The cost of an outgoing link as measured by the neighbor. */
  unsigned outgoingCost   :3;
  /** The cost of an incoming link as measured by this device. */
  unsigned incomingCost   :3;
#ifndef _CHILD_MANAGEMENT_
  unsigned reserved1      :2;
#elif defined _PARENT_ANNCE_
  bool keepAliveSeen      :1;
  bool reserved1          :1;
#else  
  unsigned reserved1      :2;
#endif

#if defined _NWK_PASSIVE_ACK_
  NwkPassiveAckMap_t passiveAckMap;
#endif /* _NWK_PASSIVE_ACK_ */
} NwkMutablePartOfNeighbor_t;

/** Type of size of the neighbor table. */
typedef uint8_t NwkSizeOfNeighborTable_t;

/** Type of the neighbor table. */
typedef struct _NwkNeighborTable_t
{
 /** The array of a neighbor entry. */
  NwkNeighbor_t *table;
  /** Pointer to memory area after last entry of the neighbor table. */
  NwkNeighbor_t *end;
  /** The array of a mutable neighbor entry. */
  NwkMutablePartOfNeighbor_t *mutableTable;
  /** Current size of the neighbor table. */
  NwkSizeOfNeighborTable_t size;
#if defined _ROUTER_ || defined _COORDINATOR_
  /** Timer for internal use. */
  HAL_AppTimer_t ageTimer;
#endif /* _ROUTER_ or _COORDINATOR_ */
} NwkNeighborTable_t;

/** For backward compatibility */
typedef NwkNeighbor_t Neib_t;
typedef NwkMutablePartOfNeighbor_t MutableNeib_t;
typedef NwkNeighborTable_t NeibTable_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Access function to the neighbor table.

  \return Pointer to the neighbor table.
 ******************************************************************************/
NwkNeighborTable_t * NWK_GetNeighborTable(void);

/**************************************************************************//**
  \brief Searching a neighbor entry by extended address.

  \param[in] extAddr - extended IEEE address of neighbor.
  \return NULL if no records found, or entry with extAddr otherwise
 ******************************************************************************/
NwkNeighbor_t * NWK_FindNeighborByExtAddr(const ExtAddr_t extAddr);

/**************************************************************************//**
  \brief Searching a neighbor entry by short address.

  \param[in] shortAddr - network address of neighbor.
  \return NULL if no records found, or entry with shortAddr otherwise
 ******************************************************************************/
NwkNeighbor_t * NWK_FindNeighborByShortAddr(const ShortAddr_t shortAddr);

/**************************************************************************//**
  \brief Remove a neighbor from the neighbor table with leave indication.

  \param[in] neighbor - pointer to a entry in the neighbor table.
  \param[in] cleanAddressMap - Remove records from address map if existed.
  \param[in] rejoin - Will rejoin network or not
  \return None.
 ******************************************************************************/
void NWK_RemoveNeighbor(NwkNeighbor_t *const neighbor, bool cleanAddressMap, bool rejoin, bool leaveInd);

/**************************************************************************//**
  \brief Link quality indication for given neighbor.

  \param[in] neighbor - pointer to a entry of neighbor in the neighbor table.
  \return LQI of received frames from a neighbor
 ******************************************************************************/
Lqi_t NWK_GetNeighborsLqi(NwkNeighbor_t const *const neighbor);

/**************************************************************************//**
  \brief RSSI for given neighbor.

  \param[in] neighbor - pointer to a entry of neighbor in the neighbor table.
  \return RSSI of received frames from a neighbor
 ******************************************************************************/
Rssi_t NWK_GetNeighborsRssi(NwkNeighbor_t const *const neighbor);

/**************************************************************************//**
  \brief Is given neighbor known child.

  \param[in] extAddr - extended address of child.
  \param[in] setKnownFlag - change the known flag to 'true' if this parameter
                              is equal 'true'.

  \return Current value of known flag.
 ******************************************************************************/
bool NWK_IsKnownChild(const ExtAddr_t extAddr, const bool setKnownFlag);

/**************************************************************************//**
  \brief Is given neighbor is child.

  \param[in] neighbor - pointer to a entry of neighbor in the neighbor table.

  \return True, given neighbor is child.; otherwise - false.
 ******************************************************************************/
INLINE bool NWK_IsChild(Neib_t const *const neighbor)
{
  return (RELATIONSHIP_CHILD == neighbor->relationship)
      || (RELATIONSHIP_UNAUTHENTICATED_CHILD == neighbor->relationship);
}

/**************************************************************************//**
  \brief Is given neighbor is unauthenticated child.

  \param[in] neighbor - pointer to a entry of neighbor in the neighbor table.

  \return True, given neighbor is unauthenticated child.; otherwise - false.
 ******************************************************************************/
INLINE bool NWK_IsUnauthenticatedChild(Neib_t const *const neighbor)
{
  return (RELATIONSHIP_UNAUTHENTICATED_CHILD == neighbor->relationship);
}

/**************************************************************************//**
  \brief Authenticate a child node.

  \param[in] extAddr - pointer to the extended address of child.
  \return None.
 ******************************************************************************/
bool NWK_AuthenticateNeighbor(const ExtAddr_t *const extAddr);

/**************************************************************************//**
  \brief This function adds neighbor table record for a known neighbor.

  \param[in] nwkAddress - neighbor network address;
  \param[in] extAddr    - pointer to extended address of a node.
  \param[in] replaceEntry - replace existing entry with relationship-noneOfabove 
                                        if neighbor table is full  
  \return pointer to neighbor.
 *****************************************************************************/
NwkNeighbor_t * NWK_AddKnownNeighbor(const ShortAddr_t nwkAddress, ExtAddr_t *extAddr, bool replaceEntry);

/**************************************************************************//**
  \brief Linear search of an EndDevice child.

  \param[in] exceptShortAddr - to ignore entries with this address.
  \param[in] neighbor - begin search after this neighbor.
  \return Pointer to EndDevice child in the neighbor table.
 ******************************************************************************/
NwkNeighbor_t * NWK_NextEDChild(NwkNeighbor_t* neighbor,
  const ShortAddr_t exceptShortAddr);

/**************************************************************************//**
  \brief Calculate an incoming cost by LQI.

  \param[in] lqi - link quality indicator.
  \return None.
 ******************************************************************************/
NwkPathCost_t NWK_CostFromLqi(const Lqi_t lqi);

/***************************************************************************//**
  \brief Updating the outgoing cost and age field of the neighbor.

  \param[in] neighbor - pointer to a neighbor in the neighbor table.
  \param[in] outgoingCost - new outgoing cost.

  \return None.
 ******************************************************************************/
void nwkUpdateOutgoingCostAndLifeTime(NwkNeighbor_t *const neighbor,
  const NwkPathCost_t outgoingCost);

#if defined(_ROUTER_) || defined(_COORDINATOR_)
#if defined(_NWK_KEEP_STALE_NEIGHBOR_ENTRY_)
/**************************************************************************//**
  \brief Check whether the neighbor is stale

  \param[in] neighbor - neighbor that needs to be checked

  \return TRUE if neighbor is stale, FALSE otherwise
 ******************************************************************************/
bool NWK_IsNeighborStale(NwkNeighbor_t* const neighbor);

/***************************************************************************//**
  \brief Find the stale entry in neighbor table

  \return Stale entry (NwkNeighbor_t*) if available, NULL otherwise
 ******************************************************************************/
NwkNeighbor_t * NWK_RemoveStaleNeighbor(void);

#endif //#if defined(_NWK_KEEP_STALE_NEIGHBOR_ENTRY_)
#endif //#if defined(_ROUTER_) || defined(_COORDINATOR_)
#ifdef _CHILD_MANAGEMENT_
uint32_t convertNwkEndDeviceTimeoutToSec(NwkEndDeviceTimeout_t timeout);
void nwkUpdateEDHashMap(NwkNeighbor_t *neighbor);
void NWK_RecomputeEDHashMap(void);
bool nwkNeighborSearch(const ShortAddr_t shortAddr);
#endif
#endif /* _NWK_NEIGHBOR_H */
/** eof nwkNeighbor.h */

