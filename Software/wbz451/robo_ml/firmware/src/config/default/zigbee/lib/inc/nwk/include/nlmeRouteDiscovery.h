// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Route Discovery Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeRouteDiscovery.h

  Summary:
    This file provides the NLME-ROUTE-DISCOVERY interface.

  Description:
    This file provides the NLME-ROUTE-DISCOVERY interface.
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

#if !defined _NLME_ROUTE_DISCOVERY_H
#define _NLME_ROUTE_DISCOVERY_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nlmeNwkStatus.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** NLME-ROUTE-DISCOVERY confirm primitive's parameters structure.ZigBee Specification r17, 3.2.2.32 NLME-NETWORK-FORMATION.confirm, page 306. */
typedef struct _NWK_RouteDiscoveryConf_t
{
  /** The status of an attempt to initiate route discovery. */
  NWK_Status_t status;
  /** In the case where the Status parameter has a value of ROUTE_ERROR,
   * this code gives further information about the kind of error that occurred.
   * Otherwise, it should be ignored. ZigBee spec r17, Table 3.35. */
  NWK_StatusIndErrorCodes_t networkStatusCode;
  ShortAddr_t nextHop;
} NWK_RouteDiscoveryConf_t;

/** NLME-ROUTE-DISCOVERY request primitive's parameters structure. Zigbee Specification r17, 3.2.2.31 NLME-ROUTE-DISCOVERY.request. */
typedef struct _NWK_RouteDiscoveryReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  } service;
  /** A parameter specifying the kind of destination address provided. */
  NWK_DstAddrMode_t dstAddrMode;
  /** The destination of the route discovery. */
  ShortAddr_t dstAddr;
  /** This optional parameter describes the number of hops that the route
   * request will travel through the network. */
  NwkRadius_t radius;
  /** In the case where DstAddrMode has a value of zero, indicating many-to-one
   * route discovery, this flag determines whether the NWK should establish
   * a route record table. TRUE = no route record table should be established,
   * FALSE = establish a route record table */
  bool noRouteCache;
  /** NLME-ROUTE-DISCOVERY confirm callback function's pointer. */
  void (*NWK_RouteDiscoveryConf)(NWK_RouteDiscoveryConf_t *conf);
  NWK_RouteDiscoveryConf_t confirm;
} NWK_RouteDiscoveryReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-ROUTE-DISCOVERY request primitive's prototype.

  \param[in] req - NLME-ROUTE-DISCOVERY request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_RouteDiscoveryReq(NWK_RouteDiscoveryReq_t *const req);

/**************************************************************************//**
  \brief Call the route discovery confirm when the first route has been found,

    If the routing path is unknown and NWK_RouteDiscoveryReq was called then
  the fastRouteDiscovery flag idicates that NWK layer has to wait all route
  responses or only one. The others responses will be accepted and processed.

  \param[in] fastRouteDiscovery - if true then calls NWK_RouteDiscoveryConf
                                  when the first route has been found
                                  otherwise wait some period.
  \return None.
 ******************************************************************************/
void NWK_FindAnyRouteAtFirstTime(const bool fastRouteDiscovery);

#if defined NWK_ROUTING_CAPACITY \
  && (defined _NWK_MESH_ROUTING_ || defined _NWK_MANY_TO_ONE_ROUTING_)
/**************************************************************************//**
  \brief Free the entry of the routing table.

  \param[in] dstAddr - a short address of destination node.
             isGroupId - 'true' if dstAddr is group id otherwise 'false'.
  \return None.
 ******************************************************************************/
void NWK_FreeRoutingEntry(const ShortAddr_t dstAddr, const bool isGroupId);

#endif /* NWK_ROUTING_CAPACITY and (_NWK_MESH_ROUTING_ or _NWK_MANY_TO_ONE_ROUTING_) */

#endif /* _NLME_ROUTE_DISCOVERY_H */
/** eof nlmeRouteDiscovery.h */

