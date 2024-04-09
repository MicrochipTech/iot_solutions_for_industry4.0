// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Frames Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkFrame.h

  Summary:
    This file contains the NWK layer frame formats and declarations for the functions.

  Description:
    This file contains the NWK layer frame formats and declarations for the functions.
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
#if !defined _NWK_FRAME_H
#define _NWK_FRAME_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <systemenvironment/include/sysTypes.h>
#include <nwk/include/private/nwkSystem.h>
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                               Define(s) section
 ******************************************************************************/
#define NWK_HEADER(outPkt) ((NwkFrameHeader_t *)(NWK_GET_OUTPKT_DATA(outPkt)))
#define IS_DATA(nwkHeader) \
  (NWK_FRAMETYPE_DATA == (nwkHeader)->frameControl.frameType)
#define IS_COMMAND(nwkHeader) \
  (NWK_FRAMETYPE_COMMAND == (nwkHeader)->frameControl.frameType)
#define IS_UNICAST(nwkHeader) \
  (((nwkHeader)->frameControl.multicastFlag \
    && (NWK_FRAME_MULTICAST_NON_MEMBER_MODE == (nwkHeader)->field.multicast.control.mode)) \
  || (!(nwkHeader)->frameControl.multicastFlag \
    && IS_CORRECT_SHORT_ADDR((nwkHeader)->dstAddr)))

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Values of the Frame Type Sub-Field. ZigBee spec r17, Table 3.37. */
typedef enum _NwkFrameTypeFlag_t
{
  NWK_FRAMETYPE_DATA = 0,
  NWK_FRAMETYPE_COMMAND = 1,
/** Inter-PAN delivery modes
    ZigBee Smart Energy profile specification r15
    B.4 Frame Format, page 90
    */
  NWK_FRAMETYPE_INTERPAN = 3
} NwkFrameTypeFlag_t;

/** Values of the Discover Route Sub-Field. ZigBee spec r17, Table 3.38. */
typedef enum _NwkDiscoverRouteFlag_t
{
  NWK_DISCOVER_ROUTE_SUPPRESS = 0,
  NWK_DISCOVER_ROUTE_ENABLE = 1
} NwkDiscoverRouteFlag_t;

/** Values of the Multicast Mode Sub-Field. ZigBee spec r17, Table 3.39. */
typedef enum _NwkMulticastMode_t
{
  NWK_FRAME_MULTICAST_NON_MEMBER_MODE = 0,
  NWK_FRAME_MULTICAST_MEMBER_MODE = 1
} NwkMulticastMode_t;

/** NWK command frame identifiers. ZigBee spec r17, Table 3.40. */
typedef enum _NwkCmdIdentifier_t
{
  NWK_CMD_ROUTE_REQUEST   = 0x01, /**< ZigBee spec r17, 3.4.1 */
  NWK_CMD_ROUTE_REPLY     = 0x02, /**< ZigBee spec r17, 3.4.2 */
  NWK_CMD_NETWORK_STATUS  = 0x03, /**< ZigBee spec r17, 3.4.3 */
  NWK_CMD_LEAVE           = 0x04, /**< ZigBee spec r17, 3.4.4 */
  NWK_CMD_ROUTE_RECORD    = 0x05, /**< ZigBee spec r17, 3.4.5 */
  NWK_CMD_REJOIN_REQUEST  = 0x06, /**< ZigBee spec r17, 3.4.6 */
  NWK_CMD_REJOIN_RESPONSE = 0x07, /**< ZigBee spec r17, 3.4.7 */
  NWK_CMD_LINK_STATUS     = 0x08, /**< ZigBee spec r17, 3.4.8 */
  NWK_CMD_NETWORK_REPORT  = 0x09, /**< ZigBee spec r17, 3.4.9 */
  NWK_CMD_NETWORK_UPDATE  = 0x0a, /**< ZigBee spec r17, 3.4.10 */
  NWK_CMD_ENDDEVICE_TIMEOUT_REQUEST  = 0x0b, /**< Child Aging and Recovery Protocol r20, 7.2 */
  NWK_CMD_ENDDEVICE_TIMEOUT_RESPONSE = 0x0c, /**< Child Aging and Recovery Protocol r20, 7.2 */
} NwkCmdIdentifier_t;

/** Type of command id field. */
typedef uint8_t NwkCommandIdField_t;

/** Frame Control Field. ZigBee spec r17, 3.3.1.1, page 308. 
    The frame control field is 16 bits in length and contains
    information defining the frame type, addressing and sequencing
    fields and other control flags.*/
BEGIN_PACK
typedef struct PACK _NwkFrameControl_t
{
  LITTLE_ENDIAN_OCTET(3, (
    /** The frame type sub-field is 2 bits in length and shall be set to one of
     * the nonreserved values: NWK_FRAMETYPE_DATA or NWK_FRAMETYPE_COMMAND. */
    NwkBitField_t frameType         : 2,
    /** The protocol version sub-field shall be set to a number reflecting
     * the ZigBee NWK protocol version in use. The protocol version in use
     * on a particular device shall be made available as the value of
     * the NWK constant nwkcProtocolVersion. */
    NwkBitField_t protocolVersion   : 4,
    /** The discover route sub-field may be used to control route discovery
     * operations for the transit of this frame. */
    NwkBitField_t discoverRoute     : 2
  ))
  LITTLE_ENDIAN_OCTET(7, (
    /** The multicast flag sub-field is 1 bit in length and has the value 0
     * if the frame is a unicast or broadcast frame and the value 1 if it is
     * a multicast frame. The multicast control field of the NWK header shall
     * be present only if the multicast flag has the value 1.
     * ZigBee spec r17, 3.3.1.1.4, page 309. */
    NwkBitField_t multicastFlag     : 1,
    /** The security sub-field shall have a value of 1 if, and only if,
     * the frame is to have NWK security operations enabled. If security for
     * this frame is implemented at another layer or disabled entirely,
     * it shall have a value of 0. */
    NwkBitField_t security          : 1,
    /** The source route sub-field shall have a value of 1 if and only
     * if a source route subframe is present in the NWK header.
     * ZigBee spec r17, 3.3.1.1.6, page 308. */
    NwkBitField_t sourceRoute       : 1,
    /** The destination IEEE address sub-field shall have a value of 1 if,
     * and only if, the NWK header is to include the full IEEE address
     * of the destination. */
    NwkBitField_t dstExtAddr        : 1,
    /** The source IEEE address sub-field shall have a value of 1 if, and
     * only if, the NWK header is to include the full IEEE address
     * of the source device. */
    NwkBitField_t srcExtAddr        : 1,
    /** If the source of the message is an end device and the nwkParentInformation
     * field of the NIB is a value other than 0, then this sub-field shall be set to 1.
     * Otherwise this sub-field shall be set to 0. */
    NwkBitField_t endDeviceInitiator: 1,
    NwkBitField_t reserved          : 2
  ))
} NwkFrameControl_t;
END_PACK

/** Type of unaligned extended IEEE address. */
BEGIN_PACK
typedef union PACK _NwkFrameExtAddr_t
{
  ExtAddr_t value;
  uint8_t raw[sizeof(ExtAddr_t)];
} NwkFrameExtAddr_t;
END_PACK

/** The multicast control sub-field is 1 octet in length and shall only be
    present if the multicast flag sub-field has a value of 1. It is divided into
    three sub-fields as illustrated in ZigBee spec r17, Figure 3.7. */
BEGIN_PACK
typedef struct PACK _NwkFrameMulticastField_t
{
  LITTLE_ENDIAN_OCTET(3, (
    /** The multicast mode sub-field indicates whether the frame is to be
     * transmitted using member or non-member mode. Member mode is used to
     * propagate multicasts between the devices that are members of
     * the destination group. Nonmember mode is used to transmit a multicast
     * frame from a device that is not a member of the multicast group to
     * a device that is a member of the multicast group. */
    NwkBitField_t mode               : 2,
    /** The nonmember radius sub-field indicates the range of a member mode
     * multicast when relayed by devices that are not members of the
     * destination group. */
    NwkBitField_t nonMemberRadius    : 3,
    /** The maximum value of the NonmemberRadius sub-field for this frame.
     * ZigBee spec r17, 3.3.1.8.3, page 312. */
    NwkBitField_t maxNonMemberRadius : 3
  ))
} NwkFrameMulticastField_t;
END_PACK

/** Source route subframe format. ZigBee spec r18, Figure 3.8, page 316. */
BEGIN_PACK
typedef struct PACK _NwkSourceRouteSubframe_t
{
  /** The relay count sub-field indicates the number of relays contained in
   * the relay list. ZigBee spec r18, 3.3.1.9.1, page 316. */
  uint8_t relayCount;
  /** The relay index sub-field indicates the index of the next relay in
   * the relay list subfield to which the packet will be transmitted.
   * ZigBee spec r18, 3.3.1.9.2, page 316. */
  uint8_t relayIndex;
  /** The relay list sub-field shall contain the list of relay addresses.
   * ZigBee spec r18, 3.3.1.9.3, page 316. */
  ShortAddr_t relayList[NWK_MAX_SOURCE_ROUTE];
} NwkSourceRouteSubframe_t;
END_PACK

/** Type of parsed NWK header. */
typedef struct _NwkParseHeader_t
{
  /** Pointer to a destination extended address in a original NWK header. */
  const NwkFrameExtAddr_t *dstExt;
  /** Pointer to a source extended address in a original NWK header. */
  const NwkFrameExtAddr_t *srcExt;
  /** Pointer to a multicast field. */
  NwkFrameMulticastField_t *multicast;
  /** Pointer to a source route subframe. */
  NwkSourceRouteSubframe_t *sourceRouteSubframe;
  /** Pointer to first octet of NWK payload. */
  uint8_t *payload;
  /** Size of NWK header in octets. */
  NwkLength_t headerSize;
  /** Size of NWK payload in octets. */
  NwkLength_t payloadSize;
  /** Source MAC short address. */
  ShortAddr_t macSrcAddr;
  /** Link quality indicator of received frame. */
  Lqi_t lqi;
  /** Received signal strength indication. */
  Rssi_t rssi;
  /** Extended address from auxilary header. It's address of previous hop. */
  ExtAddr_t auxExtAddr;
} NwkParseHeader_t;

/** Type of a NWK header, which comprises frame control, addressing
    and sequencing information. */
BEGIN_PACK
typedef struct PACK _NwkFrameHeader_t
{
  /** The frame control field shall be formatted as illustrated in
   * ZigBee spec r17, Figure 3.6. */
  NwkFrameControl_t frameControl;
  /** The destination address field shall always be present and shall be 2
   * octets in length. If the multicast flag sub-field of the frame control
   * field has the value 0, the destination address field shall hold the 16-bit
   * network address of the destination device or a broadcast address
   * (see Table 3.54). If the multicast flag sub-field has the value 1,
   * the destination address field shall hold the 16-bit Group ID of the
   * destination multicast group. ZigBee spec r17, 3.3.1.2, page 310. */
  ShortAddr_t dstAddr;
  /** The source address field shall always be present. It shall always be 2
   * octets in length and shall hold the network address of the source device of
   * the frame. ZigBee spec r17, 3.3.1.3, page 310. */
  ShortAddr_t srcAddr;
  /** The radius field shall always be present. It will be 1 octet in length and
   * specifies the range of a radius-limited transmission. The field shall be
   * decremented by 1 by each receiving device. */
  NwkRadius_t radius;
  /** The sequence number field is present in every frame and is 1 octet
   * in length. The sequence number value shall be incremented by 1 with each
   * new frame transmitted */
  NwkSequenceNumber_t sequenceNumber;
  union PACK
  {
    struct PACK
    {
      /** The destination IEEE address field, if present, contains the 64-bit
       * IEEE address corresponding to the 16-bit network address contained in
       * the destination address field of the NWK header.
       * ZigBee spec r17, 3.3.1.6, page 310. */
      NwkFrameExtAddr_t dstExt;
      /** The source IEEE address field, if present, contains the 64-bit
       * IEEE address corresponding to the 16-bit network address contained
       * in the source address field. */
      NwkFrameExtAddr_t srcExt;
      uint8_t payload[1];
    } dst_src;
    struct PACK
    {
      NwkFrameExtAddr_t srcExt;
      uint8_t payload[1];
    } src;
    struct PACK
    {
      /** The multicast control sub-field is 1 octet in length and shall only
       * be present if the multicast flag sub-field has a value of 1. It is
       * divided into three sub-fields as illustrated in ZigBee spec r17,
       * Figure 3.7. */
      NwkFrameMulticastField_t control;
      uint8_t payload[1];
    } multicast;
    /** As per the R22 specification,Table 3-45 Allowable Frame Control Sub-Field Configurations
     * For Multicast Dest iEEE address should not be included*/
    struct PACK
    {
      NwkFrameExtAddr_t srcExt;
      NwkFrameMulticastField_t control;
      uint8_t payload[1];
    } src_multicast;
    /** First octet of NWK payload. */
    uint8_t payload[1];
  } field;
} NwkFrameHeader_t;
END_PACK

/******************************************************************************
                            Prototypes section
 ******************************************************************************/
 
/***************************************************************************//**
  \brief Clear frame, then fill it with commonly used fields.

  \param[in] nwkHeader - pointer to header.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkPrepareCommonFrame(NwkFrameHeader_t *const nwkHeader);

/***************************************************************************//**
  \brief Parse floating fields of frame.

  \param[in] nwkHeader - header to parse.
  \param[in] parse - structure with pointer to frame fields,
                     NULL - if field is not present, correct pointer otherwise.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkParseHeader(NwkFrameHeader_t *const nwkHeader,
  NwkParseHeader_t *const parse);

/**************************************************************************//**
  \brief Gets maximum default radius. It's 2*maxDepth or 255.

  \return 2 * maxDepth if maxDepth less 128 otherwise 255.
 ******************************************************************************/
NWK_PRIVATE NwkRadius_t nwkGetDefaultRadius(void);

#endif /* _NWK_FRAME_H */
/** eof nwkFrame.h */

