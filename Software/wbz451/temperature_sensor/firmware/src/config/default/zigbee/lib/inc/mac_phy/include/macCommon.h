/*******************************************************************************
  MAC Common Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macCommon.h

  Summary:
    This file contains the Declarations of common MAC layer fields and types.

  Description:
    This file contains the Declarations of common MAC layer fields and types.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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

#ifndef _MACCOMMON_H
#define _MACCOMMON_H

/******************************************************************************
                         Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/
//! MAC primitives' return codes.
typedef enum
{
  // IEEE802.15.4 table - 83.
  MAC_PAN_AT_CAPACITY_STATUS        = 0x01,
  MAC_PAN_ACCESS_DENIED_STATUS      = 0x02,
  // IEEE802.15.4 table - 78.
  MAC_SUCCESS_STATUS                = 0x00,
  MAC_UNSUPPORTED_LEGACY            = 0xDE,
  MAC_BEACON_LOSS_STATUS            = 0xE0,
  MAC_CHANNEL_ACCESS_FAILURE_STATUS = 0xE1,
  MAC_DENIED_STATUS                 = 0xE2,
  MAC_DISABLE_TRX_FAILURE_STATUS    = 0xE3,
  MAC_FRAME_TOO_LONG_STATUS         = 0xE5,
  MAC_INVALID_GTS_STATUS            = 0xE6,
  MAC_INVALID_HANDLE_STATUS         = 0xE7,
  MAC_INVALID_PARAMETER_STATUS      = 0xE8,
  MAC_NO_ACK_STATUS                 = 0xE9,
  MAC_NO_BEACON_STATUS              = 0xEA, //!< No beacons are received by the device
  MAC_NO_DATA_STATUS                = 0xEB,
  MAC_NO_SHORT_ADDRESS_STATUS       = 0xEC,
  MAC_PAN_ID_CONFLICT_STATUS        = 0xEE,
  MAC_REALIGNMENT_STATUS            = 0xEF,
  MAC_TRANSACTION_EXPIRED_STATUS    = 0xF0,
  MAC_TRANSACTION_OVERFLOW_STATUS   = 0xF1,
  MAC_TX_ACTIVE_STATUS              = 0xF2,
  MAC_UNSUPPORTED_ATTRIBUTE_STATUS  = 0xF4,
  MAC_INVALID_ADDRESS_STATUS        = 0xF5,
  MAC_INVALID_INDEX_STATUS          = 0xF9,
  MAC_LIMIT_REACHED_STATUS          = 0xFA, ///< There are some unscanned channels yet, but there is no memory.
  MAC_ON_TIME_TOO_LONG_STATUS       = 0xF6,
  MAC_PAST_TIME_STATUS              = 0xF7,
  MAC_READ_ONLY_STATUS              = 0xFB,
  MAC_SCAN_IN_PROGRESS_STATUS       = 0xFC,
  MAC_SUPERFRAME_OVERLAP_STATUS     = 0xFD,
  MAC_TRACKING_OFF_STATUS           = 0xF8
} MAC_Status_t;

/******************************************************************************
                        Types section.
******************************************************************************/
//! Internal service fields which give us opportunity to compose requests' queue.
typedef struct
{
  void    *next;
  uint8_t requestId;
}  MAC_Service_t;

/**
 * \brief Internal service fields which give us opportunity to compose and to serve
 * transactions frame queue.
*/
typedef struct
{
  void     *next;
  uint8_t  requestId;
  uint32_t ttl;
  bool     activated;
}  MAC_ServiceTransaction_t;

#endif //_MACCOMMON_H

// eof macCommon.h
