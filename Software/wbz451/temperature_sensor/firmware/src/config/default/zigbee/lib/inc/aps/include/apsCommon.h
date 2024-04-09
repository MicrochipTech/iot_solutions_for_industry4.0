// DOM-IGNORE-BEGIN
/*******************************************************************************
  APS Common Header File

  Company
    Microchip Technology Inc.

  File Name
    apsCommon.h

  Summary
    Definitions of common APS layer's constants and types.

  Description
    This header file defines the common APS layer parameters.
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
#if !defined _APS_COMMON_H
#define _APS_COMMON_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                               Definitions section
 ******************************************************************************/
 
// DOM-IGNORE-BEGIN
/**
    Length of min APS header. This header includes the following fields:
    \li frame control        - 1 octet
    \li destination endpoint - 1 octet
    \li cluster identifier   - 2 octets
    \li profile identifier   - 2 octets
    \li source endpoint      - 1 octet
    \li APS counter          - 1 octet 
    */
#define APS_COMMON_DATA_FRAME_HEADER_LENGTH 8U
/** Maximum length of APS extended header in data packets. */
#ifdef _APS_FRAGMENTATION_
#define APS_DATA_EXTENDED_HEADER_LENGTH 2U
#else
#define APS_DATA_EXTENDED_HEADER_LENGTH 0U
#endif

/** Maximum length of InterPan frame header */
#define APS_COMMON_INTERPAN_FRAME_HEADER_LENGTH 9U

/** Maximum header size for InterPan message */
#define APS_MAX_INTERPAN_HEADER_LENGTH \
  (APS_COMMON_INTERPAN_FRAME_HEADER_LENGTH + MAC_MAX_INTERPAN_MPDU_UNSECURED_OVERHEAD)

#ifndef _LINK_SECURITY_
/** Maximum APS header's size */
#define APS_MAX_DATA_FRAME_HEADER_LENGTH \
  (APS_COMMON_DATA_FRAME_HEADER_LENGTH + APS_DATA_EXTENDED_HEADER_LENGTH)

/** Minimum length of APS auxiliary header. */
#define APS_MIN_AUXILIARY_HEADER_LENGTH   0U
/** Maximum APS footer's size. */
#define APS_MAX_DATA_FRAME_FOOTER_LENGTH  0U

#define APS_AUXILIARY_HEADER_LENGTH 0U

#else /* _LINK_SECURITY_ */

/** Minimum length of APS auxiliary header. */
#define APS_MIN_AUXILIARY_HEADER_LENGTH   6U
/**
    brief APS auxiliary header's size
 
    See ZigBee spec. r18, 4.5.1.1, Security Control Field.
    */
#define APS_AUXILIARY_HEADER_LENGTH  (APS_MIN_AUXILIARY_HEADER_LENGTH + 8U)

/** Maximum APS header's size */
#define APS_MAX_DATA_FRAME_HEADER_LENGTH  \
  (APS_COMMON_DATA_FRAME_HEADER_LENGTH + APS_DATA_EXTENDED_HEADER_LENGTH + APS_AUXILIARY_HEADER_LENGTH)

/** Maximum APS footer's size: 4 bytes - Message Integrity Code (MIC) */
#define APS_MAX_DATA_FRAME_FOOTER_LENGTH  4U

#endif /* _LINK_SECURITY_ */

/** Maximum length of APS data payload which can be sent. */
#define APS_MAX_TX_ASDU_SIZE  (NWK_MAX_TX_NSDU_SIZE - APS_COMMON_DATA_FRAME_HEADER_LENGTH)

/** Length of APS payload which can be received. */
#define APS_MAX_RX_ASDU_SIZE \
  (NWK_MAX_RX_NSDU_SIZE - APS_COMMON_DATA_FRAME_HEADER_LENGTH - APS_DATA_EXTENDED_HEADER_LENGTH)

/** Maximum size of an APS payload */
#define APS_MAX_ASDU_SIZE \
  (NWK_MAX_NSDU_SIZE - APS_MAX_DATA_FRAME_HEADER_LENGTH - APS_MAX_DATA_FRAME_FOOTER_LENGTH)

#define APS_MAX_NON_SECURITY_ASDU_SIZE \
  (NWK_MAX_NSDU_SIZE - APS_COMMON_DATA_FRAME_HEADER_LENGTH)

/** Maximum size of an APS InterPan frame payload */
#define APS_MAX_INTERPAN_ASDU_SIZE \
  (MAC_MAX_INTERPAN_MSDU_SIZE - APS_COMMON_INTERPAN_FRAME_HEADER_LENGTH)

/** Size of the reserved header in a data frame */
#define APS_ASDU_OFFSET \
  (NWK_NSDU_OFFSET + APS_MAX_DATA_FRAME_HEADER_LENGTH)

/** Size of the data frame's reserved part */
#define APS_AFFIX_LENGTH \
  (NWK_AFFIX_LENGTH + APS_MAX_DATA_FRAME_HEADER_LENGTH + APS_MAX_DATA_FRAME_FOOTER_LENGTH)

/** APS Broadcast endpoint */
#define APS_BROADCAST_ENDPOINT      0xff
/** ZDO endpoint */
#define APS_ZDO_ENDPOINT            0x00
/** Reserved endpoints */
#define APS_ZGP_RESERVED_ENDPOINT   0xf2
#define APS_MIN_RESERVED_ENDPOINT   0xf1
#define APS_MAX_RESERVED_ENDPOINT   0xfe

/** Minimum value of a user's endpoint number */
#define APS_MIN_USER_ENDPOINT       0x01

/** Maximum value of a user's endpoint number */
#define APS_MAX_USER_ENDPOINT       0xf0

/** APS addresses limiting values */
#define APS_MAX_UNICAST_SHORT_ADDRESS 0xfff7
#define APS_MAX_UNICAST_EXT_ADDRESS   0xfffffffffffffff9ULL
#define APS_INVALID_EXT_ADDRESS       0x0000000000000000ULL

/** APS broadcast addresses values */
#define APS_BROADCAST_ALL_EXT_ADDRESS               0xffffffffffffffffULL
#define APS_BROADCAST_RX_ON_WHEN_IDLE_EXT_ADDRESS   0xfffffffffffffffdULL
#define APS_BROADCAST_ALL_ROUTERS_EXT_ADDRESS       0xfffffffffffffffcULL
#define APS_BROADCAST_LOW_POWER_ROUTERS_EXT_ADDRESS 0xfffffffffffffffbULL

#define APS_SM_INVALID_FRAME_COUNTER_VALUE  (0xffffffffUL)

/* Special value for extended address indicates unspecific (can be used with every
   device) address: e.g. can be used in Key Pair Set to indicate a global key entries. */
#define APS_UNIVERSAL_EXTENDED_ADDRESS APS_BROADCAST_ALL_EXT_ADDRESS
/* Special value of apsTrustCenterAddress indicates distrubuted trust center mode. */
#define APS_DISTRIBUTED_TC_ADDRESS APS_UNIVERSAL_EXTENDED_ADDRESS

/* These definitions are deprecated and shouldn't be used */
#define APS_SM_BROADCAST_EXT_ADDRESS                     APS_BROADCAST_ALL_EXT_ADDRESS
#define APS_SM_BROADCAST_ALL_EXT_ADDRESS                 APS_BROADCAST_ALL_EXT_ADDRESS
#define APS_SM_BROADCAST_RX_ON_WHEN_IDLE_EXT_ADDRESS     APS_BROADCAST_RX_ON_WHEN_IDLE_EXT_ADDRESS
#define APS_SM_BROADCAST_ALL_ROUTERS_EXT_ADDRESS         APS_BROADCAST_ALL_ROUTERS_EXT_ADDRESS
#define APS_SM_BROADCAST_LOW_POWER_ROUTERS_EXT_ADDRESS   APS_BROADCAST_LOW_POWER_ROUTERS_EXT_ADDRESS
#define APS_SM_UNIVERSAL_TRUST_CENTER_EXT_ADDRESS        APS_UNIVERSAL_EXTENDED_ADDRESS
#define APS_LAST_UNICAST_ADDRESS                         APS_MAX_UNICAST_EXT_ADDRESS
#define APS_SM_INVALID_EXT_ADDRESS                       APS_INVALID_EXT_ADDRESS

/* All Public Profiles. */
#define APS_WILDCARD_PROFILE_ID  0xFFFF
/* Standard profile range. */
#define APS_MIN_STANDARD_PROFILE_ID 0x0000
#define APS_MAX_STANDARD_PROFILE_ID 0x7FFF
// DOM-IGNORE-END

/******************************************************************************
                                 Types section
 ******************************************************************************/
 
/** Struct APS_Address_t apsCommon.h "aps.h"
    Common APS address type
    Used as a part of standard APS primitives */
typedef union
{
  ShortAddr_t shortAddress; /*!< 16-bit network address */
#ifdef _APS_MULTICAST_
  GroupAddr_t groupAddress; /*!< 16-bit group (multicast) address */
#endif
  uint8_t extAddress[8];     /*!< 64-bit extended IEEE address */
} APS_Address_t;

/** Struct _APS_DataQualityIndicator_t 
    Data quality indicator for APS Packets */
typedef struct _APS_DataQualityIndicator_t
{
  /** The link quality indication delivered by the NLDE. */
    uint8_t linkQuality;
  /** receive signal strength indication delivered by NLDE */
    int8_t rssi;  
} APS_DataQualityIndicator_t;

/** struct APS_BcastDataCount_t
    APS Broadcast packet count indicator */
typedef struct {
  /** APS layer Rx broadcast count */
  uint16_t rxBcast;
  /** APS layer Tx broadcast count */
  uint16_t txBcast;
}APS_BcastDataCount_t;

/** APS addressing modes Defines APS addressing modes */
typedef enum
{
  /** Indirect addressing mode via binding */
  APS_NO_ADDRESS = 0x00,
  /** Group addressing mode via multicasting */
  APS_GROUP_ADDRESS = 0x01,
  /** Unicast addressing mode, with a 16-bit network (short) address */
  APS_SHORT_ADDRESS = 0x02,
  /** Unicast addressing mode, with a 64-bit IEEE (extended) address. */
  APS_EXT_ADDRESS = 0x03
} APS_AddrMode_t;

/** APS status values used in most of standard primives */
typedef enum
{
  /** A request has been executed successfully. */
  APS_SUCCESS_STATUS                     = 0x00,
  /** IEEE 802.15.4-2006, Table 83. */
  /** Valid values of the Association Status field. */
  APS_MAC_PAN_AT_CAPACITY_STATUS         = 0x01,
  APS_MAC_PAN_ACCESS_DENIED_STATUS       = 0x02,
  /** The supplied endpoint was equal to 0x00 or 0xff. */
  APS_INVALID_EP_STATUS                  = 0x82,
  /** A transmit request has failed since the ASDU is too large and fragmentation
   * is not supported. */
  APS_ASDU_TOO_LONG_STATUS               = 0xa0,
  /** A received fragmented frame can not be defragmented currently. */
  APS_DEFRAG_DEFERRED_STATUS             = 0xa1,
  /** A received fragmented frame can not be defragmented, because the device
   * does not support fragmentation. */
  APS_DEFRAG_UNSUPPORTED_STATUS          = 0xa2,
  /** APS is in a state when request's execution is impossible. */
  APS_ILLEGAL_REQUEST_STATUS             = 0xa3,
  /** An APSME-UNBIND.request has failed, because the requested binding link does not
   * exist in the binding table. */
  APS_INVALID_BINDING_STATUS             = 0xa4,
  /** An APSME-REMOVE-GROUP.request has been issued with a group identifier
   * that is absent in the group table. */
  APS_INVALID_GROUP_STATUS               = 0xa5,
  /** A parameter's value is invalid or out of range. */
  APS_INVALID_PARAMETER_STATUS           = 0xa6,
  /** An APSDE-DATA.request requesting acknowledged transmission has failed
   * because of no acknowledgement being received. */
  APS_NO_ACK_STATUS                      = 0xa7,
  /** An APSDE-DATA.request with the destination addressing mode set to 0x00
   * has failed, because no devices are bound to this device. */
  APS_NO_BOUND_DEVICE_STATUS             = 0xa8,
  /** An APSDE-DATA.request with the destination addressing mode
   * set to 0x03 has failed, because the corresponding short address has not been found
   * in the address map table. */
  APS_NO_SHORT_ADDRESS_STATUS            = 0xa9,
  /** An APSDE-DATA.request with the destination addressing mode set to 0x00
   * has failed, because the binding table is not supported on the device. */
  APS_NOT_SUPPORTED_STATUS               = 0xaa,
  /** An ASDU secured using a link key has been received . */
  APS_SECURED_LINK_KEY_STATUS            = 0xab,
  /** An ASDU secured using a network key has been received. */
  APS_SECURED_NWK_KEY_STATUS             = 0xac,
  /** An APSDE-DATA.request requesting security has resulted in an error
   * during the corresponding security processing. */
  APS_SECURITY_FAIL_STATUS               = 0xad,
  /** An APSME-BIND.request or APSME.ADDGROUP.request have been issued ,while the binding
   * table or the group table, respectively, is full. */
  APS_TABLE_FULL_STATUS                  = 0xae,
  /** An unsecured ASDU has been received. */
  APS_UNSECURED_STATUS                   = 0xaf,
  /** An APSME-GET.request or APSMESET.request has been issued with an
   * unknown attribute's identifier. */
  APS_UNSUPPORTED_ATTRIBUTE_STATUS       = 0xb0,
  /** An ASDU secured using the trust center link key has been received. */
  APS_SECURED_TRUST_CENTER_LINK_KEY_STATUS          = 0xb1,
  /** An ASDU secured using the trust center's link key's hash has been received. */
  APS_SECURED_HASH_OF_TRUST_CENTER_LINK_KEY_STATUS  = 0xb2,
  /** An invalid or out-of-range parameter has been passed to a primitive from
   * the next higher layer. */
  APS_NWK_INVALID_PARAMETERS_STATUS      = 0xC1,
  /** The next higher layer has issued a request that is invalid or cannot be
   * executed given the current state of the NWK layer. */
  APS_NWK_INVALID_REQUEST_STATUS         = 0xC2,
  /** An NLME-JOIN.request has been disallowed. */
  APS_NWK_NOT_PERMITTED_STATUS           = 0xC3,
  /** An NLME-NETWORK-FORMATION.request has failed to start a network. */
  APS_NWK_STARTUP_FAILURE_STATUS         = 0xC4,
  /** A device with the address supplied to the NLMEDIRECT-JOIN.request is
   * already present in the neighbor table of the device on which
   * the NLME-DIRECT-JOIN.request has been issued. */
  APS_NWK_ALREADY_PRESENT_STATUS         = 0xC5,
  /** An NLME-SYNC.request has failed at the MAC layer. */
  APS_NWK_SYNC_FAILURE_STATUS            = 0xC6,
  /** An NLME-JOIN-DIRECTLY.request has failed, because there the neighbor table is full. */
  APS_NWK_NEIGHBOR_TABLE_FULL_STATUS     = 0xC7,
  /** An NLME-LEAVE.request has failed, because the device addressed in
   * the parameter list is not in the neighbor table of the issuing device. */
  APS_NWK_UNKNOWN_DEVICE_STATUS          = 0xC8,
  /** An NLME-GET.request or NLME-SET.request has been issued with
   * an unknown attribute's identifier. */
  APS_NWK_UNSUPPORTED_ATTRIBUTE_STATUS   = 0xC9,
  /** No networks has been detected after an NLME-JOIN.request has been issued. */
  APS_NWK_NO_NETWORKS_STATUS             = 0xCA,
  /** Security processing has been attempted on an outgoing frame
   * and has failed, because the frame counter has reached its maximum value. */
  APS_NWK_MAX_FRM_COUNTER_STATUS         = 0xCC,
  /** Security processing has been attempted on an outgoing frame
   * and has failed, because no key was available with which to process it. */
  APS_NWK_NO_KEY_STATUS                  = 0xCD,
  /** Security processing has been attempted on an outgoing frame
   * and has failed, because the security engine produced erroneous output. */
  APS_NWK_BAD_CCM_OUTPUT_STATUS          = 0xCE,
  /** An attempt to discover a route has failed because of a lack of routing table's
   * or discovery table's capacity. */
  APS_NWK_NO_ROUTING_CAPACITY_STATUS     = 0xCF,
  /** An attempt to discover a route has failed owing to a reason other
   * than a lack of routing tables' capacity. */
  APS_NWK_ROUTE_DISCOVERY_FAILED_STATUS  = 0xD0,
  /** An NLDE-DATA.request has failed due to a routing
   * failure on the sending device. */
  APS_NWK_ROUTE_ERROR_STATUS             = 0xD1,
  /** An attempt to send a broadcast frame or member mode multicast has failed,
   * because there is no room in the broadcast transmission table. */
  APS_NWK_BT_TABLE_FULL_STATUS           = 0xD2,
  /** An NLDE-DATA.request has failed owing to a lack of buffered space. */
  APS_NWK_FRAME_NOT_BUFFERED_STATUS      = 0xD3,
  /** IEEE 802.15.4-2006, Table 78 MAC enumerations description. */
  /** The frame counter purportedly applied by the originator of the
   * received frame is invalid. */
  APS_MAC_COUNTER_ERROR_STATUS           = 0xDB,
  /** The key purportedly applied by the originator of the received frame is
   * not allowed to be used with that frame type according to the key usage
   * policy of the recipient. */
  APS_MAC_IMPROPER_KEY_TYPE_STATUS       = 0xDC,
  /** The security level purportedly applied by the originator of the received
   * frame does not meet the minimum security level required/expected by
   * the recipient for that frame type. */
  APS_MAC_IMPROPER_SECURITY_LEVEL_STATUS = 0xDD,
  /** The received frame was purportedly secured using security based on
   * IEEE Std 802.15.4-2003, though such security is not supported by this standard.
   **/
  APS_MAC_UNSUPPORTED_LEGACY_STATUS      = 0xDE,
  /** The security purportedly applied by the originator of the received frame
   * is not supported. */
  APS_MAC_UNSUPPORTED_SECURITY_STATUS    = 0xDF,
  /** The beacon was lost following a synchronization request. */
  APS_MAC_BEACON_LOSS_STATUS             = 0xE0,
  /** A transmission could not take place due to activity on the channel,
   * i.e., the CSMA-CA mechanism has failed. */
  APS_MAC_CHANNEL_ACCESS_FAILURE_STATUS  = 0xE1,
  /** The GTS request has been denied by the PAN coordinator. */
  APS_MAC_DENIED_STATUS                  = 0xE2,
  /** The attempt to disable the transceiver has failed. */
  APS_MAC_DISABLE_TRX_FAILURE_STATUS     = 0xE3,
  /** Either a frame resulting from processing has a length that is
   * greater than aMaxPHYPacketSize or a requested transaction is
   * too large to fit in the CAP or GTS. */
  APS_MAC_FRAME_TOO_LONG_STATUS          = 0xE5,
  /** The requested GTS transmission has failed because the specified
   * GTS either does not have a transmit GTS direction or has not been defined. */
  APS_MAC_INVALID_GTS_STATUS             = 0xE6,
  /** A request to purge an MSDU from the transaction queue was made using
   * an MSDU handle that was not found in the transaction table. */
  APS_MAC_INVALID_HANDLE_STATUS          = 0xE7,
  /** A parameter in the primitive is either not supported or is out of
   * the valid range. */
  APS_MAC_INVALID_PARAMETER_STATUS       = 0xE8,
  /** No acknowledgment was received after macMaxFrameRetries. */
  APS_MAC_NO_ACK_STATUS                  = 0xE9,
  /** A scan operation failed to find any network beacons. */
  APS_MAC_NO_BEACON_STATUS               = 0xEA,
  /** No response data were available following a request. */
  APS_MAC_NO_DATA_STATUS                 = 0xEB,
  /** The operation failed because a 16-bit short address was not allocated. */
  APS_MAC_NO_SHORT_ADDRESS_STATUS        = 0xEC,
  /** A receiver enable request was unsuccessful because it could not be
   * completed within the CAP. */
  APS_MAC_OUT_OF_CAP_STATUS              = 0xED,
  /** A PAN identifier conflict has been detected and communicated
   * to the PAN coordinator. */
  APS_MAC_PAN_ID_CONFLICT_STATUS         = 0xEE,
  /** A coordinator realignment command has been received. */
  APS_MAC_REALIGNMENT_STATUS             = 0xEF,
  /** The transaction has expired and its information was discarded. */
  APS_MAC_TRANSACTION_EXPIRED_STATUS     = 0xF0,
  /** There is no capacity to store the transaction. */
  APS_MAC_TRANSACTION_OVERFLOW_STATUS    = 0xF1,
  /** The transceiver was in the transmitter enabled state when the receiver
   * was requested to be enabled. */
  APS_MAC_TX_ACTIVE_STATUS               = 0xF2,
  /** The key purportedly used by the originator of the received frame is
   * not available or, if available, the originating device is not known
   * or is blacklisted with that particular key. */
  APS_MAC_UNAVAILABLE_KEY_STATUS         = 0xF3,
  /** A SET/GET request was issued with the identifier of a PIB
   * attribute that is not supported. */
  APS_MAC_UNSUPPORTED_ATTRIBUTE_STATUS   = 0xF4,
  /** A request to send data was unsuccessful because neither the source address
   * parameters nor the destination address parameters were present. */
  APS_MAC_INVALID_ADDRESS_STATUS         = 0xF5,
  /** A receiver enable request was unsuccessful because it specified a number
   * of symbols that was longer than the beacon interval. */
  APS_MAC_ON_TIME_TOO_LONG_STATUS        = 0xF6,
  /** A receiver enable request was unsuccessful because it could not be
   * completed within the current superframe and was not permitted to be
   * deferred until the next superframe. */
  APS_MAC_PAST_TIME_STATUS               = 0xF7,
  /** The device was instructed to start sending beacons based on the
   * timing of the beacon transmissions of its coordinator, but the device
   * is not currently tracking the beacon of its coordinator. */
  APS_MAC_TRACKING_OFF_STATUS            = 0xF8,
  /** An attempt to write to a MAC PIB attribute that is in a table failed
   * because the specified table index was out of range. */
  APS_MAC_INVALID_INDEX_STATUS           = 0xF9,
  /** There are some unscanned channels yet, but there is no memory */
  APS_MAC_LIMIT_REACHED_STATUS           = 0xFA,
  /** A SET/GET request was issued with the identifier of an attribute
   * that is read only. */
  APS_MAC_READ_ONLY_STATUS               = 0xFB,
  /** A request to perform a scan operation failed because the MLME was
   * in the process of performing a previously initiated scan operation. */
  APS_MAC_SCAN_IN_PROGRESS_STATUS        = 0xFC,
  /** The device was instructed to start sending beacons based on the timing of
   * the beacon transmissions of its coordinator, but the instructed start time
   * overlapped the transmission time of the beacon of its coordinator. */
  APS_MAC_SUPERFRAME_OVERLAP_STATUS      = 0xFD
} APS_Status_t;

#endif /* _APS_COMMON_H */
/** eof apsCommon.h */

