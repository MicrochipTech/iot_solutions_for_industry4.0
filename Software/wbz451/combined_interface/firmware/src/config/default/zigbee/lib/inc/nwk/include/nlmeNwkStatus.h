// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME NWK Status Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeNwkStatus.h

  Summary:
    This file contains the NLME-NWK-STATUS interface.

  Description:
    This file contains the NLME-NWK-STATUS interface.
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

#if !defined _NLME_NWK_STATUS_H
#define _NLME_NWK_STATUS_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/

/** Status Codes for network status command frame. */
typedef enum _NWK_StatusIndErrorCodes_t
{
  /** Route discovery and/or repair has been attempted and no route to
   * the intended destination address has been discovered. */
  NWK_NO_ROUTE_AVAILABLE            =  0x00,
  /** The routing failure occurred as a result of the failure of an attempt
   * to route the frame along the tree. */
  NWK_TREE_LINK_FAILURE             =  0x01,
  /** The routing failure did not occur as a result of an attempt to route along
   * the tree. */
  NWK_NON_TREE_LINK_FAILURE         =  0x02,
  /** The frame was not relayed because the relaying device was running low
   * on battery power. */
  NWK_LOW_BATTERY_LEVEL             =  0x03,
  /** The failure occurred because the relaying device has no routing capacity.
   **/
  NWK_NO_ROUTING_CAPACITY           =  0x04,
  /** The failure occurred as the result of an attempt to buffer
   * a frame for a sleeping end device child and the relaying device
   * had no buffer capacity to use. */
  NWK_NO_INDIRECT_CAPACITY          =  0x05,
  /** A frame that was buffered on behalf of a sleeping end device child has
   * been dropped as a result of a time-out. */
  NWK_INDIRECT_TRANSACTION_EXPIRY   =  0x06,
  /** An end device child of the relaying device is for some reason unavailable.
   **/
  NWK_TARGET_DEVICE_UNAVAILABLE     =  0x07,
  /** The frame was addressed to a non-existent end device
   * child of the relaying device. */
  NWK_TARGET_ADDRESS_UNALLOCATED    =  0x08,
  /** The failure occurred as a result of a failure in the RF link to
   * the device's parent. This status is only used locally on a device
   * to indicate loss of communication with the parent. */
  NWK_PARENT_LINK_FAILURE           =  0x09,
  /** The multicast route identified in the destination address
   * field should be validated. */
  NWK_VALIDATE_ROUTE                =  0x0A,
  /** Source routing has failed, probably indicating a link failure in one of
   * the source route's links. */
  NWK_SOURCE_ROUTE_FAILURE          =  0x0B,
  /** A route established as a result of a many-to-one route request has failed.
   **/
  NWK_MANY_TO_ONE_ROUTE_FAILURE     =  0x0C,
  /** The address in the destination address field has been determined to be
   * in use by two or more devices. */
  NWK_ADDRESS_CONFLICT              =  0x0D,
  /** The source device has the IEEE address in the Source IEEE address field
   * and, if the Destination IEEE address field is present, the value it
   * contains is the expected IEEE address of the destination. */
  NWK_VERIFY_ADDRESSES              =  0x0E,
  /** The operational network PAN identifier of the device has been updated. */
  NWK_PAN_IDENTIFIER_UPDATE         =  0x0F,
  /** The network address of the device has been updated. */
  NWK_NETWORK_ADDRESS_UPDATE        =  0x10,
  /** A frame counter reported in a received frame had a value less than or
   * equal to that stored in nwkSecurityMaterialSet. */
  NWK_BAD_FRAME_COUNTER             =  0x11,
  /** The key sequence number reported in a received frame did not match
   * that of nwkActiveKeySeqNumber. */
  NWK_BAD_KEY_SEQUENCE_NUMBER       =  0x12,
  NWK_PARENT_LINK_SUCCESS           =  0x13,
  NWK_BAD_LINK                      =  0x14,
  NWK_STATIC_ADDRESS_CONFLICT       =  0x15,
  /** If the security material cannot be obtained, security processing shall indicate a failure
   * to the next higher layer with a status of 'frame security failed' and no further
   * security processing shall be done on this frame. ZigBee spec r20, 4.3.1.2, page 435 */
  NWK_FRAME_SECURITY_FAILED         =  0x16
} NWK_StatusIndErrorCodes_t;

/** NLME-NWK-STATUS indication primitive's parameters structure. Zigbee Specification r17, 3.2.2.30 NLME-NWK-STATUS.indication, page 302. */
typedef struct _NWK_NwkStatusInd_t
{
  /** The 16-bit network address of the device
   * associated with the status information. */
  ShortAddr_t shortAddress;
  /** The error code associated with the failure. */
  NWK_StatusIndErrorCodes_t status;
} NWK_NwkStatusInd_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-NWK-STATUS indication primitive's prototype.

  \return None.
 ******************************************************************************/
extern void NWK_NwkStatusInd(NWK_NwkStatusInd_t *ind);

#endif /* _NLME_NWK_STATUS_H */
/** eof nlmeNwkStatus.h */

