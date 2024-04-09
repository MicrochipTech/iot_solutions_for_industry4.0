// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Route Infomration Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkRouteInfo.h

  Summary:
    This file contains the Public route information.

  Description:
    This file contains the Public route information.
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
#if !defined _NWK_ROUTE_INFO_H
#define _NWK_ROUTE_INFO_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>

/******************************************************************************
                              Definitions section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
/* Invalid concentrator descriptor. */
#define NWK_INVALID_CONCENTRATOR (UINT16_MAX)
/* Macro return true if concentrator descriptor is valid. */
#define IS_VALID_CONCENTRATOR(descr) (NWK_INVALID_CONCENTRATOR != (descr))
// DOM-IGNORE-END

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of concentrator descriptor. */
typedef uint16_t NWK_Concentrator_t;

/** Type of concentrator indication structure.
   Deprecated. Use generic subscription to event BC_EVENT_NEW_CONCENTRATOR instead. */
typedef struct _NWK_ConcentratorInd_t
{
  /** Service fields - for internal needs (event receiver for compatibility with new event system). */
  SYS_EventService_t service;
  /** This function is called when new concentrator is found.
     New argument 'id' was added as a transition to generic event system.
     Please update you software and ignore this argument for a moment. */
  void (* NWK_ConcentratorInd)(SYS_EventId_t id, SYS_EventData_t data);
} NWK_ConcentratorInd_t;

/** Type of the relay count field. Valid range 0-0xffff.
    See Zigbee spec r18, Table 3.45. */
typedef uint16_t NWK_RelayCount_t;

#if defined (_NWK_ROUTE_CACHE_ ) || defined (_NWK_MANY_TO_ONE_ROUTING_)
/** Type of Source routing status. */
typedef enum _NWK_SourceRouting_Status_t
{
  NWK_SourceRouting_Success,
  NWK_SourceRouting_Failure,
  NWK_SourceRouting_OutOfMemory,
  NWK_SourceRouting_BufferFull,
  NWK_SourceRouting_DiscoveryTableFull,
  NWK_SourceRouting_RelayListTooLong,
} NWK_SourceRouting_Status_t;

/** Type of Source routing event. */
typedef enum _NWK_SourceRouting_EventType_t
{
  NWK_RouteRecordReceived,
  NWK_SourceRouteFailed,
  NWK_ManyToOneRouteFailed,
} NWK_SourceRouting_EventType_t;

/** Route record received event indicator. */
typedef struct PACK
{
  __PACKED ShortAddr_t srcAddr;
  uint8_t relayCount;
  ShortAddr_t relayList[NWK_MAX_SOURCE_ROUTE];
}NWK_RouteRecordInfo_t;

BEGIN_PACK
/** Source route failed event indicator. */
typedef struct PACK
{
  ShortAddr_t originalDestinationAddress;
  ShortAddr_t reporterAddress;
}NWK_SourceRouteFailureStatus_t;
END_PACK

typedef struct PACK
{
  NWK_SourceRouting_EventType_t type;
  union
  {
    __PACKED ShortAddr_t reporterAddr;
    NWK_RouteRecordInfo_t routeRecordData;
    NWK_SourceRouteFailureStatus_t sourceRouteFailureStatus;
  } sourceRouteEventData;
}NWK_SourceRouteEvent_t;
#endif /* _NWK_ROUTE_CACHE_ || _NWK_MANY_TO_ONE_ROUTING_ */


/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief This function return the 16-bit network address of the next hop on
     the way to the destination.

  \return The network address of the next hop.
 ******************************************************************************/
ShortAddr_t NWK_GetNextHop(ShortAddr_t dstAddr);

/**************************************************************************//**
  \brief This function adds the 16-bit network address of the next hop on
     the way to the destination.
  \param[in]  dstAddr - Destination address
  \param[in]  isGroupId - is it Group address or not
  \param[in]  nextHopAddr - The address of the next hop
  \param[in]  cost - Path cost for next hop
  \return  None
 ******************************************************************************/


#if defined _NWK_MESH_ROUTING_

void NWK_UpdateNextHop(const ShortAddr_t dstAddr, const bool isGroupId, const ShortAddr_t nextHopAddr, const NwkPathCost_t cost);
#endif /* _NWK_MESH_ROUTING_ */

/**************************************************************************//**
  \brief Get descriptor of next concentrator.

  Example:
    NWK_Concentrator_t c = NWK_INVALID_CONCENTRATOR;

    while (IS_VALID_CONCENTRATOR(c = NWK_NextConcentrator(c)))
    {
      cAddr = NWK_ShortAddrOfConcentrator(c);
      if (MASTER_CONCENTRATOR_ADDR == cAddr)
        ...
      ...
    }

  \param[in] prevConcentrator - descriptor of previous concentrator or
    NWK_INVALID_CONCENTRATOR if it's initial call.

  \return if next concentrator is found then return valid descriptor otherwise
    return NWK_INVALID_CONCENTRATOR.
 ******************************************************************************/
NWK_Concentrator_t NWK_NextConcentrator(const NWK_Concentrator_t prevConcentrator);

/**************************************************************************//**
  \brief Get short address of given concentrator.

    Note: Call this function and NWK_NextConcentrator() in same task.

  \param[in] concentrator - descriptor of concentrator (see NWK_NextConcentrator).
  \return Short address of concentrator.
 ******************************************************************************/
ShortAddr_t NWK_ShortAddrOfConcentrator(const NWK_Concentrator_t concentrator);

/**************************************************************************//**
  \brief Get short address of next hop node for given concentrator.

    Note: Call this function and NWK_NextConcentrator() in same task.

  \param[in] concentrator - descriptor of concentrator (see NWK_NextConcentrator).
  \return Short address of next hop.
 ******************************************************************************/
ShortAddr_t NWK_NextHopToConcentrator(const NWK_Concentrator_t concentrator);

/**************************************************************************//**
  \brief Subscribe to indication about new concentrators.

  Deprecated. Subscribe to generic BC_EVENT_NEW_CONCENTRATOR instead.

  \param[in] ind - pointer to concentrator indication structure.
  \return None.
 ******************************************************************************/
/*DEPRECATED*/ void NWK_SubscribeToConcentratorInfo(NWK_ConcentratorInd_t *const ind);

/**************************************************************************//**
  \brief Unsubscribe from indication about new concentrators.

  Deprecated. Unsubscribe from generic BC_EVENT_NEW_CONCENTRATOR instead.

  \param[in] ind - pointer to concentrator indication structure.
  \return None.
 ******************************************************************************/
/*DEPRECATED*/ void NWK_UnsubscribeFromConcentratorInfo(NWK_ConcentratorInd_t *const ind);

#if defined _NWK_ROUTE_CACHE_
/**************************************************************************//**
  \brief Clear the relay list for the given destination address.

   Relay list to the destination device from the routeCache is cleared.

  \param[in] dstAddr - The dst address for which this relayList should be cleared.
  \return None.
 ******************************************************************************/
void NWK_ClearRelayList(const ShortAddr_t dstAddr);

/**************************************************************************//**
  \brief Set the relay list for the given destination address.

   Relay list to use if a message is sent to the destination address.

  \param[in] dstAddr - The dst address for which this relayList should be cleared.
  \param[in] relayCount - The dst address for which this relayList should be cleared.
  \param[in] path - The list of network addresses by which the packet is relayed through the network.
  \return Status code indicating the status of the operation.
 ******************************************************************************/
NWK_SourceRouting_Status_t NWK_SetRelayList(const ShortAddr_t dstAddr, const NWK_RelayCount_t relayCount, ShortAddr_t *path);

#endif /* _NWK_ROUTE_CACHE_ */

#if defined _CUSTOM_4_SECURITY_MODE_
/**************************************************************************//**
  \brief Add a known concentrator information.

  \param[in] shortAddr - short address of the concentrator.
  \param[in] nextHopAddr - next hop address on a rote to the concentrator.
  \param[in] noRouteCache - noRouteCahce flag of the concentrator.
  \return None.
 ******************************************************************************/
void NWK_AddConcentrator(const ShortAddr_t shortAddr, const ShortAddr_t nextHopAddr, const bool noRouteCache);
#endif /* _CUSTOM_4_SECURITY_MODE_ */

#endif /* _NWK_ROUTE_INFO_H */
/** eof nwkRouteInfo.h */
