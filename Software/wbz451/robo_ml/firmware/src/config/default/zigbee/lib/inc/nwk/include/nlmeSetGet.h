// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Set Get Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeSetGet.h

  Summary:
    This file contains the NLME-SET and NLME-GET interface.

  Description:
    This file contains the NLME-SET and NLME-GET interface.
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

#if !defined _NLME_SET_GET_H
#define _NLME_SET_GET_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Identifiers of network information base attributes. ZigBee spec r17,Table 3.44. */
typedef enum _NWK_NibId_t
{
  /** This NIB attribute have the same value as macPANId. */
  NWK_NIB_PANID_ID                  = 0x80,
  /** A sequence number used to identify outgoing frames. */
  NWK_NIB_SEQUENCE_NUMBER_ID        = 0x81,
  /** The maximum time duration in milliseconds allowed for the parent and
   * all child devices to retransmit a broadcast message.
   * Valid range: 0-0x2710. */
  NWK_NIB_PASSIVE_ACK_TIMEOUT_ID    = 0x82,
  /** The maximum number of retries allowed after a broadcast transmission
   * failure. Valid range: 0-5. */
  NWK_NIB_MAX_BROADCAST_RETRIES_ID  = 0x83,
  /** The number of children a device is allowed to have on its current network.
   **/
  NWK_NIB_MAX_CHILDREN_ID           = 0x84,
  /** The depth a device can have. */
  NWK_NIB_MAX_DEPTH_ID              = 0x85,
  /** The number of routers any one device is allowed to have as children. */
  NWK_NIB_MAX_ROUTERS_ID            = 0x86,
  /** The current set of neighbor table entries in the device. */
  NWK_NIB_NEIGHBOR_TABLE_ID         = 0x87,
  /** Time duration in seconds that a broadcast message needs to encompass
   * the entire network. */
  NWK_NIB_NETWORK_BROADCAST_DELIVERY_TIME_ID    = 0x88,
  /** If this is set to 0, the NWK layer shall calculate link cost from
   * all neighbor nodes using the LQI values reported by the MAC layer;
   * otherwise, it shall report a constant value. */
  NWK_NIB_REPORT_CONSTANT_COST_ID   = 0x89,
  /** The number of retries allowed after an unsuccessful route request. */
  NWK_NIB_ROUTE_DISCOVERY_RETRIES_PERMITTED_ID  = 0x8A,
  /** The current set of routing table entries in the device. */
  NWK_NIB_ROUTE_TABLE_ID            = 0x8B,
  /** A flag that determines if a time stamp indication is provided on incoming
   * and outgoing packets.
   *   '1' - time indication provided.
   *   '0' - no time indication provided. */
  NWK_NIB_TIME_STAMP_ID             = 0x8C,
  /** The current route symmetry setting. 'true' means that routes are considered
   * to be comprised of symmetric links. Backward and forward routes are created
   * during one-route discovery and they are identical. 'false' indicates that
   * routes are not consider to be comprised of symmetric links. Only the forward
   * route is stored during route discovery. */
  NWK_NIB_SYM_LINK_ID               = 0x8E,
  /** This field shall contain the device capability information established at
   * network joining time. */
  NWK_NIB_CAPABILITY_INFORMATION_ID = 0x8F,
  /** A value that determines the method used to assign addresses:
   *  - 0x00 = use distributed address allocation
   *  - 0x01 = reserved
   *  - 0x02 = use stochastic address allocation. */
  NWK_NIB_ADDR_ALLOC_ID             = 0x90,
  /** A flag that determines whether the NWK layer should assume the ability
   * to use hierarchical routing:
   * - true = assume the ability to use hierarchical routing.
   * - false = never use hierarchical routing. */
  NWK_NIB_USE_TREE_ROUTING_ID       = 0x91,
  /** The address of the designated network channel manager function. */
  NWK_NIB_MANAGER_ADDR_ID           = 0x92,
  /** The maximum number of hops in a source route. */
  NWK_NIB_MAX_SOURCE_ROUTE_ID       = 0x93,
  /** The value identifying a snapshot of the network settings with
   * which this node is operating with. */
  NWK_NIB_UPDATE_ID                 = 0x94,
  /** The maximum time (in superframe periods) that a transaction is stored by a
   * coordinator and indicated in its beacon. */
  NWK_NIB_TRANSACTION_PERSISTENCE_TIME_ID     = 0x95,
  /** The 16-bit address that the device uses to communicate with the PAN. */
  NWK_NIB_NETWORK_ADDRESS_ID        = 0x96,
  /** The identifier of the ZigBee stack profile in use for this device. */
  NWK_NIB_STACK_PROFILE_ID          = 0x97,
  /** The current set of broadcast transaction table entries in the device. */
  NWK_NIB_BROADCAST_TRANSACTION_TABLE_ID      = 0x98,
  /** The Extended PAN Identifier for the PAN of which the device is a member.
   * The value 0x0000000000000000 means the Extended PAN Identifier is unknown.
   **/
  NWK_NIB_EXTENDED_PANID_ID         = 0x9A,
  /** A flag determining the layer where multicast messaging occurs.
   * - true = multicast occurs at the network layer.
   * - false = multicast occurs at the APS layer and using the APS header.*/
  NWK_NIB_USE_MULTICAST_ID          = 0x9B,
  /** The route record table. */
  NWK_NIB_ROUTE_RECORD_TABLE_ID     = 0x9C,
  /** A flag determining if this device is a concentrator.
   * - true = Device is a concentrator.
   * - false = Device is not a concentrator.*/
  NWK_NIB_IS_CONCENTRATOR_ID        = 0x9D,
  /** The hop count radius for concentrator route discoveries. */
  NWK_NIB_CONCENTRATOR_RADIUS_ID    = 0x9E,
  /** The time in seconds between concentrator route discoveries.
   * If set to 0x0000, the discoveries are done at start up and
   * by the next higher layer only. */
  NWK_NIB_CONCENTRATOR_DISCOVERY_TIME_ID      = 0x9F,
  /** The security level for outgoing and incoming NWK frames. */
  NWK_NIB_SECURITY_LEVEL_ID         = 0xA0,
  /** Set of network security material descriptors capable of maintaining
   * an active and alternate network key. */
  NWK_NIB_SECURITY_MATERIAL_SET_ID  = 0xA1,
  /** The sequence number of the active network key in nwkSecurityMaterialSet.
   **/
  NWK_NIB_ACTIVE_KEY_SEQ_NUMBER_ID  = 0xA2,
  /** Indicates whether incoming NWK frames must be all checked for freshness
   * when the memory for incoming frame counts is exceeded. */
  NWK_NIB_ALL_FRESH_ID              = 0xA3,
  /** Indicates whether security shall be applied to incoming and outgoing NWK
   * data frames.If set to 0x01, security processing shall be applied to all
   * incoming and outgoing frames except data frames destined for the current
   * device that have the security sub-field of the frame control field
   * set to 0. If this attribute has a value of 0x01, the NWK layer shall not
   * relay frames that have the security sub-field of the frame control field
   * set to 0. The SecurityEnable parameter of the NLDE-DATA.request primitive
   * shall override the setting of this attribute. */
  NWK_NIB_SECURE_ALL_FRAMES_ID      = 0xA5,
  /** The time in seconds between link status command frames. */
  NWK_NIB_LINK_STATUS_PERIOD_ID     = 0xA6,
  /** The number of missed link status command frames before resetting the link
   * costs to zero. */
  NWK_NIB_ROUTER_AGE_LIMIT_ID       = 0xA7,
  /** Use static addressing or not. */
  NWK_NIB_UNIQUE_ADDR_ID            = 0xA8,
  /** The current set of 64-bit IEEE to 16-bit network address map. */
  NWK_NIB_ADDRESS_MAP_ID            = 0xA9,
  /** Extra nib attributes. */
  NWK_NIB_INT_LOGICAL_CHANNEL_ID    = 0xF0,
  NWK_NIB_INT_PARENT_SHORT_ID       = 0xF1,
  NWK_NIB_INT_TRANSMIT_COUNTER_ID   = 0xF2,
  NWK_NIB_INT_TRANSMIT_FAILURE_COUNTER_ID = 0xF3,
  NWK_NIB_INT_DEPTH_ID              = 0xF4,
  NWK_NIB_INT_SECURITY_IB_ID        = 0xF5,
  NWK_NIB_INT_EXTENDED_ADDRESS_ID   = 0xF6,
  NWK_NIB_MAX_NEIGHBOR_ROUTE_COST_ID = 0xF7,
  NWK_NIB_PREDEFINED_PANID_ID       = 0xF8
} NWK_NibId_t;

/** NWK NIB attribute type. */
typedef union _NWK_NibAttr_t
{
  PanId_t panId;
  NwkSequenceNumber_t sequenceNumber;
  uint16_t passiveAckTimeout;
  uint8_t maxBroadcastRetries;
  NwkChildCount_t maxChildren;
  NwkDepth_t maxDepth;
  NwkChildCount_t maxRouters;
  void *neighborTable;
  uint32_t networkBroadcastDeliveryTime;
  uint8_t reportConstantCost;
  uint8_t routeDiscoveryRetriesPermitted;
  void *routeTable;
  bool symLink;
  MAC_CapabilityInf_t capabilityInformation;
  uint8_t addrAlloc;
  bool useTreeRouting;
  ShortAddr_t managerAddr;
  uint8_t maxSourceRoute;
  NwkUpdateId_t updateId;
  uint16_t transactionPersistenceTime;
  ShortAddr_t networkAddress;
  uint8_t stackProfile;
  void *broadcastTransactionTable;
  void *groupIDTable;
  ExtPanId_t extendedPANID;
  bool useMulticast;
  void *routeRecordTable;
  bool isConcentrator;
  NwkRadius_t concentratorRadius;
  uint8_t concentratorDiscoveryTime;
  uint8_t linkStatusPeriod;
  uint8_t routerAgeLimit;
  bool uniqueAddr;
  void *addressMap;
  bool timeStamp;
  uint16_t txTotal;
  Channel_t logicalChannel;
  ShortAddr_t parentShortAddr;
  uint16_t transmitCounter;
  uint16_t transmitFailureCounter;
  NwkDepth_t depth;
  void *securityIB;
  ExtAddr_t extAddr;
} NWK_NibAttr_t;

/** NLME-SET confirm primitive's parameters structure declaration.  ZigBee Specification r17, 3.2.2.29 NLME-GET.confirm, page 301. */
typedef struct _NWK_SetConf_t
{
  /** The result of the request to write the NIB attribute. */
  NWK_Status_t status;
  /** The identifier of the NIB attribute that was written. */
  NWK_NibId_t attrId;
} NWK_SetConf_t;

typedef struct _NWK_SetReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  };
  /** The identifier of the NIB attribute to write. */
  NWK_NibId_t attrId;
  /** The value to write to the indicated NIB attribute. */
  NWK_NibAttr_t attrValue;
  /** NLME-SET confirm callback function's pointer. */
  void (*NWK_SetConf)(NWK_SetConf_t *conf);
  /** NLME-SET confirm parameters' structure. */
  NWK_SetConf_t confirm;
} NWK_SetReq_t;

/** NLME-GET confirm primitive's parameters structure declaration. ZigBee Specification r17, 3.2.2.27 NLME-GET.confirm, page 299. */
typedef struct _NWK_GetConf_t
{
  /** The results of the request to read a NIB attribute value. */
  NWK_Status_t status;
  /** The identifier of the NIB attribute that was read. */
  NWK_NibId_t attrId;
  /** The value of the indicated NIB attribute that was read. */
  NWK_NibAttr_t attrValue;
} NWK_GetConf_t;

/** NLME-GET request primitive's parameters structure declaration.Zigbee Specification r17, 3.2.2.26 NLME-SYNC.request, page 298. */
typedef struct _NWK_GetReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  }  service;
  /** The identifier of the PIB attribute to read. */
  NWK_NibId_t attrId;
  /** NLME-GET confirm callback function's pointer. */
  void (*NWK_GetConf)(NWK_GetConf_t *conf);
  /** NLME-GET confirm parameters' structure. */
  NWK_GetConf_t confirm;
} NWK_GetReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-SET request primitive's prototype.

  \param[in] req - NLME-SET request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_SetReq(NWK_SetReq_t *const req);

/**************************************************************************//**
  \brief NLME-GET request primitive's prototype.

  \param[in] req - NLME-GET request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_GetReq(NWK_GetReq_t *const req);

#endif /* _NLME_SET_GET_H */
/** eof nlmeSetGet.h */

