// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSDE Data Header File

  Company
    Microchip Technology Inc.

  File Name
    apsdeData.h

  Summary
    The interface for sending data through the APS component.

  Description
    This header file provides the interface for sending data through APS component.
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
#if !defined _APSDE_DATA_H
#define _APSDE_DATA_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>
#include <systemenvironment/include/sysEndian.h>
#include <zdo/include/zdoAddrResolving.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** struct APS_DataConf_t apsdeData.h "aps.h"
 
    The structure for reporting the result of APS_DataReq() function
 
    A pointer to an instance of this type is received as an argument in a confirmation callback for APS_DataReq()
    request reporting the result of data transmission.
    The structure definition follows APSDE-DATA confirm primitive described in
    ZigBee Specification r18, 2.2.4.1.2 APSDE-DATA.confirm, page 27. */
typedef struct
{
  /** The status of the data request. See \ref DataReqStatuses "details". */
  APS_Status_t status;
  /**  Timestamp for the transmitted packet based on the local clock,
   * as provided by the NWK layer. */
  uint32_t txTime;
} APS_DataConf_t;

/**
    struct APS_TxOptions_t apsdeData.h "aps.h"
 
    Describes additional options for data transmission.
 
    The structure is used to set additional parameters for a data request such as
    \li to request for acknowledgement set acknowledgedTransmission to 1
    \li to enable fragmentation set fragmentationPermitted to 1
    \li to enable encryption of the application payload of a data frame set securityEnabledTransmission to 1
    \li to use network key to encrypt the application payload of a data frame set useNwkKey to 1
    \li to include extended nonce (combination of extended address and
    sequence number) to the auxiliary header set includeExtendedNonce to 1
 
    These fields conform to the primitive defined in ZigBee Specification r20, Table 2.2, page 25.
 
    Few extensions to the specification are defined:
    \li to disable decryption of sent data (clobbers data pointed by the asdu field) set doNotDecrypt to 1
    \li to enable indications from own broadcast transmissions set indicateBroadcasts to 1
    \li to disable discovery of a route path to the destination node in the case
    when such path is unknown; in such case if the route is unknown an error is reported
 
    */
BEGIN_PACK 
typedef union PACK
{
  uint8_t field;
  struct PACK
  {
    uint8_t   securityEnabledTransmission :1;
    uint8_t   useNwkKey                   :1;
    uint8_t   acknowledgedTransmission    :1;
    uint8_t   fragmentationPermitted      :1;
    uint8_t   includeExtendedNonce        :1;
    uint8_t   doNotDecrypt                :1;
    uint8_t   indicateBroadcasts          :1;
    uint8_t   noRouteDiscovery            :1;
  };
} APS_TxOptions_t;
END_PACK

/** The structure represents parameters of data request, i.e. the  request for sending data across the network. A pointer
    to an instance of the structure should to be passed as an argument to APS_DataReq() function
    The structure definition follows APSDE-DATA request primitive described in
    Zigbee Specification r18, 2.2.4.1.1 APSDE-DATA.request, page 23. */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    void *next; /*!< Used for queue support */
#ifdef _ZAPPSI_
    /* to be compatible with MAC service. */
    uint8_t requestId;
    /* Sequence number to identify request-response pair. */
    uint8_t sequenceNumber;
    union
    {
      /* Callback wrapper routine pointer */
      void (*callback)(void*);
      /* Processing routine pointer to call after required memory will become free */
      void (*process)(void*);
    } zsi;
#endif /* # _ZAPPSI_ */
    ZDO_ResolveAddrReq_t resolveAddrReq; /*!< Used for address resolving */
  } service;
  /** \endcond **/

  /**  The addressing mode for identifying the destination of a data request.
   * May take any non-reserved value from the following list:
    APS_NO_ADDRESS (0x00) - used for binding; set dstAddress and dstEndpoint
    APS_GROUP_ADDRESS (0x01) - used for group transmission; 16-bit group address should be specified in dstAddress; dstEndpoint is not set
   *APS_SHORT_ADDRESS (0x02) - identifying the destination (unicast or broadcast) with  a 16-bit short address specified
   * in dstAddress and the endpoint set in dstEndpoint
    APS_EXT_ADDRESS (0x03) - identifying the destination with a 64-bit extended address specified in dstAddress and the endpoint set in dstEndpoint
   0x04..0xff - reserved values, must not be used by the application*/
  APS_AddrMode_t dstAddrMode;
  /**
   *  Endian "[LE]" The address of the individual device or group address
   * of the entity to which the ASDU is being transferred.
   **/
  APS_Address_t dstAddress;
  /** This parameter shall be present if and only if the DstAddrMode parameter
   * value is 0x02 or 0x03 and, if present, shall contain either the number of
   * individual endpoints of the entity to which the ASDU is being transferred,
   * or the broadcast endpoint (0xff). */
  Endpoint_t dstEndpoint;
  /** Endian "[LE]" The identifier of the profile for which
   * this frame is intended. */
  ProfileId_t profileId;
  /** Endian "[LE]" The identifier of the cluster for which
   * this frame is intended. */
  ClusterId_t clusterId;
  /** The endpoint on the request originator node from
   * which the data frame is being transferred. */
  Endpoint_t srcEndpoint;
  /** The number of octets comprising the ASDU to be transferred.
   * The maximum length of an individual APS frame payload is given
   * as NsduLength-apscMinHeaderOverhead. Assuming the possibility
   * of fragmentation, a maximum-sized single ASDU consists of 256 such blocks.
   **/
  uint16_t asduLength;
  /** The set of octets comprising the ASDU to be transferred. */
  uint8_t *asdu;
  /** The transmission options for the ASDU to be transferred.
   * See structure definition for details.
   */
  APS_TxOptions_t txOptions;

#if defined _GREENPOWER_SUPPORT_
  /*  Alias usage by  for the current frame */
  bool useAlias;
  /*  The source address to be used for this NSDU. If the UseAlias parameter 
         has a value of FALSE,  the AliasSrcAddr parameter is ignored.*/
  ShortAddr_t aliasSrcAddr;
  /*  The sequence number to be used for this NSDU. If the UseAlias parameter
         has a value of FALSE, the AliasSeqNumb parameter is ignored.*/
  uint8_t aliasSeqNumber;
#endif /*_GREENPOWER_SUPPORT_*/

  /** The distance, in hops, that a transmitted frame will be allowed to
   * travel via the network*/
  uint8_t radius;
  /** A pointer to a callback function called upon request
   * completion. Must not be set to NULL. */
  void (*APS_DataConf)(APS_DataConf_t *conf);
  /** Confirm primitive passed to the callback and containing the results of request execution*/
  APS_DataConf_t confirm;
} APS_DataReq_t;

/**
    struct APS_DataInd_t apsdeData.h "aps.h"
    The structure for indication of data reception
    A pointer to an instance of this type is passed to a data indication callback registered for a given
    endpoint when the data is received destined to the endpoint.
    The structure definition follows APSDE-DATA indication primitive described in
    Zigbee Specification r18, 2.2.4.1.3 APSDE-DATA.indication, page 29. */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    void *next; /*!< Service field for queue support */
#ifdef _ZAPPSI_
    /* to be compatible with MAC service. */
    uint8_t requestId;
    /* Sequence number to identify request-response pair. */
    uint8_t sequenceNumber;
    union
    {
      /* Callback wrapper routine pointer */
      void (*callback)(void*);
      /* Processing routine pointer to call after required memory will become free */
      void (*process)(void*);
    } zsi;
#endif /* # _ZAPPSI_ */
  } service;
  /** \endcond **/

  /** The addressing mode used to identify the destination
   * in the data frame that has been received.
   * May take any non-reserved value from the following list:
    APS_NO_ADDRESS (0x00) - used for binding; set dstAddress and dstEndpoint
    APS_GROUP_ADDRESS (0x01) - used for group transmission; 16-bit group address should be specified in dstAddress; dstEndpoint is not set
    APS_SHORT_ADDRESS (0x02) - identifying the destination (unicast or broadcast) with  a 16-bit short address specified
   * in dstAddress and the endpoint set in dstEndpoint
    APS_EXT_ADDRESS (0x03) - identifying the destination with a 64-bit extended address specified in dstAddress and the endpoint set in dstEndpoint
   0x04..0xff - reserved values, must not be used by the application*/
  APS_AddrMode_t dstAddrMode;
  /**                                            Endian "[LE]" The individual device address or group addressto which
   * the ASDU is directed. Value size depends on the dstAddrMode parameter. */
  APS_Address_t dstAddress;
  /** The target endpoint on the local entity to which the ASDU is directed. */
  Endpoint_t dstEndpoint;
  /** The addressing mode for the source address used in this primitive
   * and of the APDU that has been received. May possess any non-reserved value
   * from the following list:
   APS_SHORT_ADDRESS (0x02) - short address is used in srcAddress and srcEndpoint is specified
   APS_EXT_ADDRESS (0x03) - extended address is used in srcAddress and srcEndpoint is specified
    */
  APS_AddrMode_t srcAddrMode;
  /**  Endian "[LE]" The individual device address of the entity from which
   * the ASDU has been received.
   * Value type and size is depend of the srcAddrMode parameter. */
  APS_Address_t srcAddress;
  /**  Endian "[LE]" Network address of previous hop from which the packet
   * received. */
  ShortAddr_t prevHopAddr;
  /** The number of the individual endpoint of the entity from
   * which the ASDU has been received. */
  Endpoint_t srcEndpoint;
  /**  Endian "[LE]" The identifier of the profile from
   * which this frame originates. */
  ProfileId_t profileId;
  /**  Endian "[LE]" The identifier of the received object. */
  ClusterId_t clusterId;
  /** The number of octets comprising the ASDU being indicated by the APSDE. */
  uint16_t asduLength;
  /** The set of octets comprising the ASDU being indicated by the APSDE. */
  uint8_t *asdu;
  /** The status of the incoming frame processing. */
  APS_Status_t status;
  /**
    APS_UNSECURED_STATUS=0xaf if the ASDU was received without any security.
    APS_SECURED_NWK_KEY_STATUS=0xac if the received ASDU was secured
                                     with the NWK key,
    APS_SECURED_LINK_KEY_STATUS=0xab if the ASDU was secured with a link key,
    APS_SECURED_TRUST_CENTER_LINK_KEY_STATUS=0xb1 if the ASDU was secured
                                     with the trust center link key,
    APS_SECURED_HASH_OF_TRUST_CENTER_LINK_KEY_STATUS=0xb2 if secured
                                     with hash of the trust center link key.
   */
  APS_Status_t securityStatus;
  /** The status of whether the NSDU is using security: TRUE = use,
   * FALSE = doesn't use. */
  bool nwkSecurityStatus;
  /** The link quality indication delivered by the NLDE. */
  uint8_t linkQuality;
  /** Timestamp for the received packet based on the local clock,
   * as provided by the NWK layer. */
  uint32_t rxTime;
  int8_t rssi;
} APS_DataInd_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/

/**************************************************************************//**
\brief Sends data to a node in the network.

The function is used to transmit data across the network. The function is able 
to send a data frame to a single node (unicast), an arbitrary group of nodes (multicast), 
or to all nodes in the network (broadcast). Sending data to devices that support 
a specific cluster and to which the node has already bound is also possible. Specific 
actions performed by the request depend on parameters configuration. A destination 
type is identified according the value of APS_DataReq_t::dstAddrMode.

To send a unicast message to a node with a known short address set ::APS_SHORT_ADDRESS 
as addressing mode, specify the destination address, destination and source endpoints, 
profile and cluster IDs. Specified cluster should be supported by both the destination 
and the originator enpoints. Both endpoints should also have the same profile ID. If 
the short address is unknown ::APS_EXT_ADDRESS mode can be used to identify the 
destination with a help of extended address (\c dstAddress.extAddress field). For 
broadcasting exactly the same parameters should be set, but the destination address 
(\c dstAddress.shortAddress) should be assigned to ::BROADCAST_ADDR_ALL to send a 
message to all nodes in the network, ::BROADCAST_ADDR_RX_ON_WHEN_IDLE to send a message 
to all nodes with \c rxOnWhenIdle parameter equal to 1, or ::BROADCAST_ADDR_ROUTERS to 
send data to all routers.

To send data to all members of a group set ::APS_GROUP_ADDRESS as addressing mode, and 
specify 16bit group address (via \c dstAddress.groupAddress). Destination endpoint 
should be assigned to 0xFF value. The data will be delivered to all endpoints associated 
to a given group address on each group member. To apply binding use ::APS_NO_ADDRESS mode 
and specify source endpoint and cluster ID. Other parameters such as profile, destination 
address and endpoint are ignored.

Actual data to be sent with a request is provided through APS_DataReq_t::asdu. The 
parameter takes as an argument a pointer to a segment of memory within a specially 
defined structure. Consider the example:

\code
// Application message buffer
BEGIN_PACK
typedef struct
{
  uint8_t header[APS_ASDU_OFFSET]; // Header
  uint8_t data[APP_ASDU_SIZE]; // Application data
  uint8_t footer[APS_AFFIX_LENGTH - APS_ASDU_OFFSET]; //Footer
} PACK AppMessageBuffer_t; END_PACK
static AppMessageBuffer_t appMessageBuffer; // A global variable for the message buffer
static APS_DataReq_t dataReq; // A global variable for the data request
...
dataReq.asdu = appMessageBuffer.data;
dataReq.asduLength = sizeof(appMessageBuffer.data);
\endcode

Additional options are switched on and off with a help of  APS_DataReq_t::txOptions parameter. 
For unicast messages the application can request for acknowledgement and apply fragmentation 
if it needs to sends greater amounts of data within a single request. Security is also
may be turned and off.

The result of the operation is reported via callback call with confirm (APS_DataConf_t) 
primitive pointer as an argument. In case of acknowledged transmission the callback is called 
after the response from the destination node is received. When one of destination nodes 
receives data, it fires data indication callback on the destination endpoint.


\anchor DataReqStatuses

  Response statuses:
  Accessed via the APS_DataConf_t::status field of the APS_DataReq_t::APS_DataConf 
  callback's argument \n\n
  ::APS_SUCCESS_STATUS (0x00) - indicates successful transmission and delivery (if acknowledgement
    has been requested) of the frame \n
  ::APS_NO_SHORT_ADDRESS_STATUS (0xA9) - the extended addressing mode is used, and the short
    address corresponding to the provided extended address has not been found \n
  ::APS_NO_BOUND_DEVICE_STATUS (0xA8) - the no address addressing mode is used, and no
    bound devices conforming to the request have been found \n
  ::APS_SECURITY_FAIL_STATUS (0xAD) - the link key for encryption has not been found; or 
    the extended address of the destination device is unknown (and hence the link key
    cannot be located); or encryption of the APS payload via a network key is requested,
    but the network key is not activated; or a broadcast frame or a multicast frame is attempted 
    to be sent with the APS payload encrypted with a link key \n
  ::APS_NO_ACK_STATUS (0xA7) - no acknowledgement has been received (if acknowledgement was
    requested) \n
  ::APS_ASDU_TOO_LONG_STATUS (0xA0) - the request can not be sent, because the payload (ASDU) 
    is to long, and fragmentation is not supported \n
  ::APS_ILLEGAL_REQUEST_STATUS (0xA3) - APS is being stopped or reset - in such states when
    execution of a data request is impossible \n 
  ::APS_NWK_INVALID_REQUEST_STATUS (0xC2) - invalid parameters have been provided, or sending a
    frame is impossible, because the node has not yet started the network or has lost 
    connection to the network \n
  ::APS_NWK_MAX_FRM_COUNTER_STATUS (0xCC) - the frame counter (the number of encryptions performed by
    the NWK layer) reached its maximum value; rebuilding the network may be needed \n
  ::APS_NWK_BAD_CCM_OUTPUT_STATUS (0xCE) - an error occured while encrypting or decrypting the frame, 
    possibly for memory corruption of hardware related error  \n
  ::APS_NWK_ROUTE_ERROR_STATUS (0xD1) - the route to the destination is unknown and route discovery
    for this frame is prohibited \n
  ::APS_NWK_ROUTE_DISCOVERY_FAILED_STATUS (0xD0) - no routes have been found for the provided
    destination during route discovery procedure \n
  ::APS_MAC_NO_ACK_STATUS (0xE9) - transmission to the first hop failed, because MAC has not
    received the ack frame from the neighbor \n
  ::APS_MAC_TRANSACTION_EXPIRED_STATUS (0xF0) - the parent node, sending the frame, failed to
    transmit the frame to its sleeping child node, because the child node has not sent a
    poll request to retrieve the frame from the parent in time \n
    
  \param req - The APSDE-DATA.request primitive pointer.
                 \sa APS_DataReq_t

  \return None
 ******************************************************************************/
void APS_DataReq(APS_DataReq_t *const req);

/**************************************************************************//**
  \brief ZDO APSDE-DATA.indication handler.

  \param ind - pointer to APSDE_DATA.indication parameters.
  \return None.
 ******************************************************************************/
extern void APS_ZdoDataInd(APS_DataInd_t *ind);

/**************************************************************************//**
  \brief Recalculates transmission timeouts and duplicate rejection time.
         Reads maximum frame transmission time,
         indirect poll rate and other parameters from the config server and
         updates ack time.

  
  \param None
  \return None
 ******************************************************************************/
void APS_CalculateTimes(void);

#endif /* _APSDE_DATA_H */
/** eof apsdeData.h */

