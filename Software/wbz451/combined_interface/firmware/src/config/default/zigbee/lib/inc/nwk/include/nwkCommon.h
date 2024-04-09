// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Common Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkCommon.h

  Summary:
    This file contains the Declarations of common NWK layer constants and types.

  Description:
    This file contains the Declarations of common NWK layer constants and types.
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

#if !defined _NWK_COMMON_H
#define _NWK_COMMON_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysQueue.h>
#include <mac_phy/include/macAffix.h>

/******************************************************************************
                               Definitions section
 ******************************************************************************/
/** Base NWK header length of data packet:
 * - frame control field (2 octets),
 * - destination address (2 octets),
 * - source address (2 octets),
 * - radius (1 octet),
 * - sequence number (1 octet) */
#define NWK_COMMON_HEADER_LENGTH 8U
/** + Source IEEE Address (8 octet) + Dest IEEE Address (8 octet). */
#define NWK_CUSTOM_HEADER_LENGTH (NWK_COMMON_HEADER_LENGTH + 8U + 8U)
/* + multicast control field (1 octet). */
#ifdef _CUSTOM_NWK_HEADER_
#define NWK_DATA_FRAME_HEADER_LENGTH (NWK_CUSTOM_HEADER_LENGTH + 1U)
#else
#define NWK_DATA_FRAME_HEADER_LENGTH (NWK_COMMON_HEADER_LENGTH + 1U)
#endif

/** Length of auxiliary frame header. See ZigBee spec r18, Figure 4.3. */
#if defined _SECURITY_
  #define NWK_AUXILIARY_HEADER_SIZE 14U
  #define NWK_MAX_DATA_FRAME_FOOTER_LENGTH 4U
#else
  #define NWK_AUXILIARY_HEADER_SIZE 0U
  #define NWK_MAX_DATA_FRAME_FOOTER_LENGTH 0U
#endif /* _SECURITY_ */

/** The hop count radius for concentrator route discoveries. ZigBee spec r18, Table 3.44, page 348. */
#define NWK_CONCENTRATOR_RADIUS 8U /* hop */
/** The maximum number of hops in a source route. ZigBee spec r18, Table 3.44. */
#define NWK_MAX_SOURCE_ROUTE (NWK_CONCENTRATOR_RADIUS)
/** Maximum length of the source route subframe:
 * - relay count field (1 octet),
 * - relay index field (1 octet),
 * - relay list (NWK_MAX_SOURCE_ROUTE * size of short address).
 * See ZigBee spec r18, 3.3.1.9, page 316. */
#if defined _NWK_SOURCE_ROUTING_
  #define NWK_MAX_SOURCE_ROUTE_SUBFRAME_LENGTH (2U+(2U*NWK_MAX_SOURCE_ROUTE))
#else
  #define NWK_MAX_SOURCE_ROUTE_SUBFRAME_LENGTH 0U
#endif /* _NWK_SOURCE_ROUTING_ */

/** Maximum lenght of NWK header. */
#define NWK_MAX_UNSECURE_HEADER_LEHGTH \
  (NWK_DATA_FRAME_HEADER_LENGTH + NWK_MAX_SOURCE_ROUTE_SUBFRAME_LENGTH)

#define NWK_MAX_DATA_FRAME_HEADER_LEHGTH \
  (NWK_MAX_UNSECURE_HEADER_LEHGTH + NWK_AUXILIARY_HEADER_SIZE)

/** Length of the reserved part in the data frame. */
#define NWK_AFFIX_LENGTH (MAC_AFFIX_LENGTH + \
   NWK_MAX_DATA_FRAME_HEADER_LEHGTH + NWK_MAX_DATA_FRAME_FOOTER_LENGTH)

/** Length of the reserved header in the data frame. */
#define NWK_NSDU_OFFSET (MAC_MSDU_OFFSET + NWK_MAX_DATA_FRAME_HEADER_LEHGTH)

/** Maximum length of NWK payload which can be sent. */
#define NWK_MAX_NSDU_SIZE (MAC_MAX_MSDU_SIZE \
   - NWK_MAX_DATA_FRAME_HEADER_LEHGTH - NWK_MAX_DATA_FRAME_FOOTER_LENGTH)

/** Maximum length of NWK payload which can be received. */
#define NWK_MAX_RX_NSDU_SIZE (MAC_MAX_MSDU_SIZE - \
  (NWK_COMMON_HEADER_LENGTH + NWK_AUXILIARY_HEADER_SIZE + NWK_MAX_DATA_FRAME_FOOTER_LENGTH))
/** Maximum length of NWK payload which can be sent. */
#define NWK_MAX_TX_NSDU_SIZE (MAC_MAX_MSDU_SIZE - \
  (NWK_COMMON_HEADER_LENGTH + NWK_AUXILIARY_HEADER_SIZE + NWK_MAX_DATA_FRAME_FOOTER_LENGTH))

/** Valid broadcast addresses. See ZigBee spec r18, Table 3.54, page 411. */
#define IS_BROADCAST_ADDR(A) (LE16_TO_CPU(A) >= 0xFFF8U)
/** Valid broadcast addresses. See ZigBee spec r18, Table 3.54, page 411. */
#define IS_CORRECT_SHORT_ADDR(A) (LE16_TO_CPU(A) < 0xFFF8U)

/** Low power routers only. */
#define LOW_POWER_ROUT_ADDR CCPU_TO_LE16(0xFFFBU)
/** Low power routers only. */
#define BROADCAST_ADDR_LOWPOWER_ROUTERS LOW_POWER_ROUT_ADDR

/** All routers and coordinator in the network. */
#define ALL_ROUT_AND_COORD_ADDR CCPU_TO_LE16(0xFFFCU)
/** All routers and coordinator in the network. */
#define BROADCAST_ADDR_ROUTERS ALL_ROUT_AND_COORD_ADDR

/** All devices with MAC attribute macRxOnWhenIdle = TRUE. */
#define RX_ON_WHEN_IDLE_ADDR CCPU_TO_LE16(0xFFFDU)
/** All devices with MAC attribute macRxOnWhenIdle = TRUE. */
#define BROADCAST_ADDR_RX_ON_WHEN_IDLE RX_ON_WHEN_IDLE_ADDR

/** All devices in the network. */
#define ALL_DEVICES_IN_PAN_ADDR 0xFFFFU
/** All devices in the network. */
#define BROADCAST_ADDR_ALL ALL_DEVICES_IN_PAN_ADDR

/** The value of the nwkNetworkAddress attribute of its NIB has  a value of 0xffff indicating that it is not currently joined to a network. */
#define NWK_NO_SHORT_ADDR 0xFFFFU

/** Added to assign random address during address conflict in large nwk */
#define NWK_STOCHASTIC_REQ_SHORT_ADDR 	0xFFFEU

/** The maximum broadcast jitter time measured in number of octets. ZigBee spec r18, Table 3.43. */
#define NWKC_MAX_BROADCAST_JITTER 2048U /*<! ~0x40 milliseconds in 2.4GHz */

/* Maximum radius for non-member mode multicast frame. */
#define NWK_MAX_NON_MEMBER_MULTICAST_RADIUS 7U

/** The value of the extendedPanId attribute in NIB has
 * a value of 0x0000000000000000 indicating that the device is not (or wasn't)
 * currently joined to a network. */
#define NWK_NO_EXT_PANID 0ULL

/** Set dafault values for internal uses. */
#define NWK_DEFINE_LEAVE_CONTROL_DEFAULT \
  {                                      \
    .cleanRouteTable    = 1U,            \
    .cleanNeighborTable = 1U,            \
    .cleanAddresmap     = 0U,            \
    .cleanKeyPairSet    = 0U,            \
    .cleanBindingTable  = 0U,            \
    .cleanGroupTable    = 0U,            \
    .cleanNwkSecKeys    = 0U,            \
    .silent             = 0U             \
  }

#if defined _COORDINATOR_ || defined _ROUTER_
  #define NWK_ROUTING_CAPACITY
#endif /* _COORDINATOR_ or _ROUTER_ */

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** NWK primitives' return codes. ZigBee spec r17, 3.7, page 417. */
typedef enum _NWK_Status
{
  /** A request has been executed successfully. */
  NWK_SUCCESS_STATUS                 = 0x00,
  /** The MAC requested operation was completed successfully. */
  NWK_MAC_SUCCESS_STATUS             = 0x00,
  /** IEEE 802.15.4-2006, Table 83.
   * Valid values of the Association Status field. */
  NWK_MAC_PAN_AT_CAPACITY_STATUS     = 0x01,
  NWK_MAC_PAN_ACCESS_DENIED_STATUS   = 0x02,
  /** An invalid or out-of-range parameter has been passed to a primitive from
   * the next higher layer. */
  NWK_INVALID_PARAMETERS_STATUS      = 0xC1,
  /** The next higher layer has issued a request that is invalid or cannot be
   * executed given the current state of the NWK layer. */
  NWK_INVALID_REQUEST_STATUS         = 0xC2,
  /** An NLME-JOIN.request has been disallowed. */
  NWK_NOT_PERMITTED_STATUS           = 0xC3,
  /** An NLME-NETWORK-FORMATION.request has failed to start a network. */
  NWK_STARTUP_FAILURE_STATUS         = 0xC4,
  /** A device with the address supplied to the NLMEDIRECT-JOIN.request is
   * already present in the neighbor table of the device on which
   * the NLME-DIRECT-JOIN.request was issued. */
  NWK_ALREADY_PRESENT_STATUS         = 0xC5,
  /** Used to indicate that an NLME-SYNC.request has failed at the MAC layer. */
  NWK_SYNC_FAILURE_STATUS            = 0xC6,
  /** An NLME-JOIN-DIRECTLY.request has failed because there is no more room in
   * the neighbor table. */
  NWK_NEIGHBOR_TABLE_FULL_STATUS     = 0xC7,
  /** An NLME-LEAVE.request has failed because the device addressed in
   * the parameter list is not in the neighbor table of the issuing device. */
  NWK_UNKNOWN_DEVICE_STATUS          = 0xC8,
  /** An NLME-GET.request or NLME-SET.request has been issued with
   * an unknown attribute identifier. */
  NWK_UNSUPPORTED_ATTRIBUTE_STATUS   = 0xC9,
  /** An NLME-JOIN.request has been issued in an environment
   * where no networks are detectable. */
  NWK_NO_NETWORKS_STATUS             = 0xCA,
  /** Security processing has been attempted on an outgoing frame,
   * and has failed because the frame counter has reached its maximum value. */
  NWK_MAX_FRM_COUNTER_STATUS         = 0xCC,
  /** Security processing has been attempted on an outgoing frame,
   * and has failed because no key was available with which to process it. */
  NWK_NO_KEY_STATUS                  = 0xCD,
  /** Security processing has been attempted on an outgoing frame,
   * and has failed because the security engine produced erroneous output. */
  NWK_BAD_CCM_OUTPUT_STATUS          = 0xCE,
  /** An attempt to discover a route has failed due to a lack of routing table
   * or discovery table capacity. */
  NWK_NO_ROUTING_CAPACITY_STATUS     = 0xCF,
  /** An attempt to discover a route has failed due to a reason other
   * than a lack of routing capacity. */
  NWK_ROUTE_DISCOVERY_FAILED_STATUS  = 0xD0,
  /** An NLDE-DATA.request has failed due to a routing
   * failure on the sending device. */
  NWK_ROUTE_ERROR_STATUS             = 0xD1,
  /** An attempt to send a broadcast frame or member mode multicast has failed
   * due to the fact that there is no room in the BTT. */
  NWK_BT_TABLE_FULL_STATUS           = 0xD2,
  /** An NLDE-DATA.request has failed due to insufficient buffering available.
   **/
  NWK_FRAME_NOT_BUFFERED_STATUS      = 0xD3,
  /** IEEE 802.15.4-2006, Table 78 MAC enumerations description. */
  /** The frame counter purportedly applied by the originator of the
   * received frame is invalid. */
  NWK_MAC_COUNTER_ERROR_STATUS       = 0xDB,
  /** The key purportedly applied by the originator of the received frame is
   * not allowed to be used with that frame type according to the key usage
   * policy of the recipient. */
  NWK_MAC_IMPROPER_KEY_TYPE_STATUS   = 0xDC,
  /** The security level purportedly applied by the originator of the received
   * frame does not meet the minimum security level required/expected by
   * the recipient for that frame type. */
  NWK_MAC_IMPROPER_SECURITY_LEVEL_STATUS = 0xDD,
  /** The received frame was purportedly secured using security based on
   * IEEE Std 802.15.4-2003, and such security is not supported by this standard.
   **/
  NWK_MAC_UNSUPPORTED_LEGACY_STATUS   = 0xDE,
  /** The security purportedly applied by the originator of the received frame
   * is not supported. */
  NWK_MAC_UNSUPPORTED_SECURITY_STATUS = 0xDF,
  /** The beacon was lost following a synchronization request. */
  NWK_MAC_BEACON_LOSS_STATUS          = 0xE0,
  /** A transmission could not take place due to activity on the channel,
   * i.e., the CSMA-CA mechanism has failed. */
  NWK_MAC_CHANNEL_ACCESS_FAILURE_STATUS = 0xE1,
  /** The GTS request has been denied by the PAN coordinator. */
  NWK_MAC_DENIED_STATUS               = 0xE2,
  /** The attempt to disable the transceiver has failed. */
  NWK_MAC_DISABLE_TRX_FAILURE_STATUS  = 0xE3,
  /** Either a frame resulting from processing has a length that is
   * greater than aMaxPHYPacketSize or a requested transaction is
   * too large to fit in the CAP or GTS. */
  NWK_MAC_FRAME_TOO_LONG_STATUS       = 0xE5,
  /** The requested GTS transmission failed because the specified
   * GTS either did not have a transmit GTS direction or was not defined. */
  NWK_MAC_INVALID_GTS_STATUS          = 0xE6,
  /** A request to purge an MSDU from the transaction queue was made using
   * an MSDU handle that was not found in the transaction table. */
  NWK_MAC_INVALID_HANDLE_STATUS       = 0xE7,
  /** A parameter in the primitive is either not supported or is out of
   * the valid range. */
  NWK_MAC_INVALID_PARAMETER_STATUS    = 0xE8,
  /** No acknowledgment was received after macMaxFrameRetries. */
  NWK_MAC_NO_ACK_STATUS               = 0xE9,
  /** A scan operation failed to find any network beacons. */
  NWK_MAC_NO_BEACON_STATUS            = 0xEA,
  /** No response data were available following a request. */
  NWK_MAC_NO_DATA_STATUS              = 0xEB,
  /** The operation failed because a 16-bit short address was not allocated. */
  NWK_MAC_NO_SHORT_ADDRESS_STATUS     = 0xEC,
  /** A receiver enable request was unsuccessful because it could not be
   * completed within the CAP. */
  NWK_MAC_OUT_OF_CAP_STATUS           = 0xED,
  /** A PAN identifier conflict has been detected and communicated
   * to the PAN coordinator. */
  NWK_MAC_PAN_ID_CONFLICT_STATUS      = 0xEE,
  /** A coordinator realignment command has been received. */
  NWK_MAC_REALIGNMENT_STATUS          = 0xEF,
  /** The transaction has expired and its information was discarded. */
  NWK_MAC_TRANSACTION_EXPIRED_STATUS  = 0xF0,
  /** There is no capacity to store the transaction. */
  NWK_MAC_TRANSACTION_OVERFLOW_STATUS = 0xF1,
  /** The transceiver was in the transmitter enabled state when the receiver
   * was requested to be enabled. */
  NWK_MAC_TX_ACTIVE_STATUS            = 0xF2,
  /** The key purportedly used by the originator of the received frame is
   * not available or, if available, the originating device is not known
   * or is blacklisted with that particular key. */
  NWK_MAC_UNAVAILABLE_KEY_STATUS      = 0xF3,
  /** A SET/GET request was issued with the identifier of a PIB
   * attribute that is not supported. */
  NWK_MAC_UNSUPPORTED_ATTRIBUTE_STATUS = 0xF4,
  /** A request to send data was unsuccessful because neither the source address
   * parameters nor the destination address parameters were present. */
  NWK_MAC_INVALID_ADDRESS_STATUS      = 0xF5,
  /** A receiver enable request was unsuccessful because it specified a number
   * of symbols that was longer than the beacon interval. */
  NWK_MAC_ON_TIME_TOO_LONG_STATUS     = 0xF6,
  /** A receiver enable request was unsuccessful because it could not be
   * completed within the current superframe and was not permitted to be
   * deferred until the next superframe. */
  NWK_MAC_PAST_TIME_STATUS            = 0xF7,
  /** The device was instructed to start sending beacons based on the
   * timing of the beacon transmissions of its coordinator, but the device
   * is not currently tracking the beacon of its coordinator. */
  NWK_MAC_TRACKING_OFF_STATUS         = 0xF8,
  /** An attempt to write to a MAC PIB attribute that is in a table failed
   * because the specified table index was out of range. */
  NWK_MAC_INVALID_INDEX_STATUS        = 0xF9,
  /** There are some unscanned channels yet, but there is no memory */
  NWK_MAC_LIMIT_REACHED_STATUS        = 0xFA,
  /** A SET/GET request was issued with the identifier of an attribute
   * that is read only. */
  NWK_MAC_READ_ONLY_STATUS            = 0xFB,
  /** A request to perform a scan operation failed because the MLME was
   * in the process of performing a previously initiated scan operation. */
  NWK_MAC_SCAN_IN_PROGRESS_STATUS     = 0xFC,
  /** The device was instructed to start sending beacons based on the timing of
   * the beacon transmissions of its coordinator, but the instructed start time
   * overlapped the transmission time of the beacon of its coordinator. */
  NWK_MAC_SUPERFRAME_OVERLAP_STATUS   = 0xFD,
  /** The End device Timeout Resp is not received by End device
    * within the timeout period */
  NWK_END_DEVICE_TIMEOUT_RESP_TIMEOUT = 0xFE
} NWK_Status_t;

/** Type of the 64-bit PAN identifier of the network.*/
typedef uint64_t ExtPanId_t;

/** Type of channels mask. */
typedef uint32_t ChannelsMask_t;

/** Type of MAC channel number. */
typedef uint8_t Channel_t;

/** Type of update identifier. The value identifying a snapshot of the network settings with which this node is operating with. */
typedef uint8_t NwkUpdateId_t;

/** Type of sequence number of NWK packets. */
typedef uint8_t NwkSequenceNumber_t;

typedef uint8_t BeaconOrder_t;
typedef BeaconOrder_t ScanDuration_t;

/** Type of link quality indicator. */
typedef uint8_t Lqi_t;
/** Type of received signal strength indication. */
typedef int8_t Rssi_t;

/** Type of link cost. */
typedef uint8_t NwkLinkCost_t;
/** Type of route path cost. */
typedef uint8_t NwkPathCost_t;

/** Length of any NWK data: header, payload and etc. */
typedef uint8_t NwkLength_t;

/** Type of children counters. */
typedef uint8_t NwkChildCount_t;

typedef uint8_t NwkDepth_t;
typedef NwkDepth_t NwkRadius_t;

/** The kind of destination address*/
typedef enum _NWK_DstAddrMode_t
{
  NWK_DSTADDRMODE_NOADDR    = 0, /**< No destination address. */
  /** 16-bit network address of a multicast group. */
  NWK_DSTADDRMODE_MULTICAST = 1,
  /** 16-bit network address of an individual device or a broadcast address. */
  NWK_DSTADDRMODE_SHORT     = 2
} NWK_DstAddrMode_t;

/** The method used to assign addresses. */
typedef enum _NWK_AddrAlloc_t
{
  NWK_ADDR_ALLOC_DISTRIBUTED = 0, /**< Use distributed address allocation. */
  NWK_ADDR_ALLOC_RESERVED    = 1,
  NWK_ADDR_ALLOC_STOCHASTIC  = 2, /**< Use stochastic address allocation. */
  NWK_ADDR_ALLOC_FROM_UID    = 3  /**< Use 2 octet from IEEE extended address. */
} NWK_AddrAlloc_t;

/** Type of initial route request identifier. */
typedef uint8_t NwkRouteRequestId_t;

/** Global state of the network layer. */
typedef uint8_t NwkState_t;

typedef  BitField_t  NwkBitField_t;

/** Constants that specify how to the device joins to a network. */
typedef enum _NWK_JoinMethod_t
{
  /** This value is prohibited by NWK layer and may be used by the upper layer. */
  NWK_JOIN_BY_DEFAULT = 0,
  /** The device is joining to a network with known parameters. Device's own
   * parameters are also known. This join procedure won't be visible on the air. */
  NWK_JOIN_VIA_COMMISSIONING = 1,
  /** The device is requesting to join a network through association. */
  NWK_JOIN_VIA_ASSOCIATION = 2,
  /** The device is joining the network using the NWK rejoining procedure. */
  NWK_JOIN_VIA_REJOIN = 3,
  /** The device is joining directly or rejoining the network using
   * the orphaning procedure. */
  NWK_JOIN_VIA_ORPHAN_SCAN = 4,
  /** Form the network and become PAN coordinator. */
  NWK_JOIN_VIA_FORMING = 5,
  NWK_JOIN_VIA_ORPHAN_KEEPALIVE = 6
} NWK_JoinMethod_t;

/** The type defines network join method and joining settings. */
typedef struct _NWK_JoinControl_t
{
  /** The method of joining the network. */
  NWK_JoinMethod_t method;
  /** If this parameter is TRUE than NWK layer will encrypt all NWK packet
   * during join procedure. It means that if the method parameter is equal
   * to NWK_JOIN_VIA_REJOIN than NWK layer will encrypt rejoin request
   * command and will expect encrypted rejoin response command. */
  bool secured;
  /** TRUE means that NWK performs active scan to discover networks in
   * neighborhood otherwise NWK uses the neighbor table as is. In that
   * case (FALSE value), you can put all known neighbors to the neighbor table
   * before join and NWK will try to join only to these neighbors. */
  bool discoverNetworks;
  /** Notify other ZigBee devices that the device has joined or re-joined the network. */
  bool annce;
  /** The flag indicates that the neighbor table must be cleared or not. */
  bool clearNeighborTable;
} NWK_JoinControl_t;

/** Constants that specify maximum permit joining period. */
typedef enum
{
  /** Infinite permit joining. */
  NWK_MAX_PERMIT_JOIN_PERIOD_INFINITE = 0,
  /** Permit joining for 3 hours following ZLL specification. */
  NWK_MAX_PERMIT_JOIN_PERIOD_ZLL      = 1,
  /** Permit joining for 0xFE seconds. */
  NWK_MAX_PERMIT_JOIN_PERIOD_SHORT    = 2
} NWK_MaxPermitJoiningPeriod_t;

/** Leave control field, defined action on leave request. */
typedef struct PACK _NWK_LeaveControl_t
{
  NwkBitField_t cleanRouteTable    :1;
  NwkBitField_t cleanNeighborTable :1;
  NwkBitField_t cleanAddresmap     :1;
  NwkBitField_t cleanKeyPairSet    :1;
  NwkBitField_t cleanBindingTable  :1;
  NwkBitField_t cleanGroupTable    :1;
  NwkBitField_t cleanNwkSecKeys    :1;
  NwkBitField_t silent             :1;
} NWK_LeaveControl_t;

#ifdef _CHILD_MANAGEMENT_
/** Values of the Parent Information Bitmask. */
#define MAC_DATA_POLL_KEEP_ALIVE_SUPPORTED       1U
#define ENDDEVICE_TIMEOUT_KEEP_ALIVE_SUPPORTED   2U
#endif

#define NWK_LIFE_TICK 2048U

#endif /* _NWK_COMMON_H */
/** eof nwkCommon.h */

