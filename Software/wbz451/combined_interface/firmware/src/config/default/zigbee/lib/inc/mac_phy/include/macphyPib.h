/*******************************************************************************
  MAC PHY Information Base Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macphyPib.h

  Summary:
    This file provides access to the MAC and PHY Information base.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    MAC and PHY PIB access.
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

#ifndef _MACPHYPIB_H
#define _MACPHYPIB_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <inttypes.h>
#include <mac_phy/include/phy.h>
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/
/**
 * \brief The maximum PSDU size (in octets) the PHY shall be able to receive/send.
 * IEEE Std 802.15.4-2006. Table 22.
*/
#define PHY_MAX_PACKET_SIZE   127U

//! RX-to-TX or TX-to-RX maximum turnaround time. IEEE Std 802.15.4-2006. Table 22.
#define PHY_TURNARROUND_TIME  12

/**
 * \brief The maximum number of octets added by the MAC sublayer to the PSDU
 * without security. IEEE Std 802.15.4-2006. Table 85.
*/
/**
 * \brief ZigBee Document 053474r17: D.4 aMaxMACFrameSize.
 *
*/

#ifndef _IEEE_ZIGBEE_COMPLIANCE_
  #define MAC_MAX_MPDU_UNSECURED_OVERHEAD 25U
  #define MAC_MAX_INTERPAN_MPDU_UNSECURED_OVERHEAD  MAC_MAX_MPDU_UNSECURED_OVERHEAD
#else
  #define MAC_MAX_MPDU_UNSECURED_OVERHEAD_NO_SRC_ADDR_IEEE_DST_ADDR_MODE 15U // 25 - 8*2(ext addr) + 8(dst ext addr)  -2(src panid)
#ifdef _ZGPD_SPECIFIC_
#if CS_ZGPD_SPECIFIC_ENABLE == true
  #define MAC_MAX_MPDU_UNSECURED_OVERHEAD 25U
  #define MAC_MAX_INTERPAN_MPDU_UNSECURED_OVERHEAD  MAC_MAX_MPDU_UNSECURED_OVERHEAD
#else /*CS_ZGPD_SPECIFIC_ENABLE*/
  #define MAC_MAX_MPDU_UNSECURED_OVERHEAD 11U // 25 - 8*2(ext addr) + 2*2(short addr) - 2(dst panId)
  #define MAC_MAX_INTERPAN_MPDU_UNSECURED_OVERHEAD 25U
#endif
#else /*_ZGPD_SPECIFIC_*/
  #define MAC_MAX_MPDU_UNSECURED_OVERHEAD 11U // 25 - 8*2(ext addr) + 2*2(short addr) - 2(dst panId)
  #define MAC_MAX_INTERPAN_MPDU_UNSECURED_OVERHEAD 25U
#endif
#endif // _IEEE_ZIGBEE_COMPLIANCE_

/**
 * \brief The number of symbols forming a superframe slot when the superframe
 * order is equal to 0. IEEE Std 802.15.4-2006. Table 85.
*/
#define MAC_BASE_SLOT_DURATION          60

//! The number of slots contained in any superframe. IEEE Std 802.15.4-2006. Table 85.
#define MAC_NUM_SUPERFRAME_SLOTS        16

/**
 * \brief The number of symbols forming a superframe when the superframe
 * order is equal to 0. IEEE Std 802.15.4-2006. Table 85.
*/
#define MAC_BASE_SUPERFRAME_DURATION    (MAC_BASE_SLOT_DURATION * MAC_NUM_SUPERFRAME_SLOTS)

/**
 * \brief The number of superframes in which a GTS descriptor
 * exists in the beacon frame of the PAN coordinator. IEEE Std 802.15.4-2006. Table 85.
*/
#define MAC_GTS_DESC_PERSISTENCE_TIME   4

/**
 * \brief The maximum number of octets added by the MAC
 * sublayer to the MAC payload of a beacon frame. IEEE Std 802.15.4-2006. Table 85.
*/
#define MAC_MAX_BEACON_OVERHEAD         MAC_MAX_MPDU_UNSECURED_OVERHEAD

/**
 * \brief The maximum size, in octets, of a beacon payload.
 * IEEE Std 802.15.4-2006. Table 85.
 */
#define MAC_MAX_BEACON_PAYLOAD_LENGTH   (PHY_MAX_PACKET_SIZE - MAC_MAX_BEACON_OVERHEAD)

/**
 * \brief The number of consecutive lost beacons that will cause the MAC
 * sublayer of a receiving device to declare a loss of synchronization.
 * IEEE Std 802.15.4-2006. Table 85.
 */
#define MAC_MAX_LOST_BEACONS            4


/**************************************************************************//**
  \brief The minimum number of octets added by the MAC sublayer to the PSDU.

  IEEE Std 802.15.4-2006. Table 85.
******************************************************************************/
#define MAC_MIN_MPDU_OVERHEAD           9

/**
 * \brief The maximum number of octets that can be transmitted in the MAC Payload
 * field of an unsecured MAC frame that will be guaranteed not to exceed aMaxPHYPacketSize.
 * IEEE Std 802.15.4-2006. Table 85.
 */
#define MAC_MAX_SAFE_PAYLOAD_SIZE       (PHY_MAX_PACKET_SIZE - MAC_MAX_MPDU_UNSECURED_OVERHEAD)

/**
 * \brief The maximum number of octets that can be transmitted in the MAC Payload field.
 * IEEE Std 802.15.4-2006. Table 85.
 */
#define MAC_MAX_PAYLOAD_SIZE            (PHY_MAX_PACKET_SIZE - MAC_MIN_MPDU_OVERHEAD)

/**
 * \brief The maximum size of an MPDU, in octets, that can be followed by a SIFS period.
 * IEEE Std 802.15.4-2006. Table 85.
 */
#define MAC_MAX_SIFS_FRAME_SIZE         18

//! The minimum number of symbols forming the CAP.IEEE Std 802.15.4-2006. Table 85.
#define MAC_MIN_CAP_LENGTH              440

/**
 * \brief The number of symbols forming the basic time period used
 * by the CSMA-CA algorithm.
 * IEEE Std 802.15.4-2006. Table 85.
 */
#define MAC_UNIT_BACKOFF_PERIOD         20

/** Bit mask of frequency bands that are supported by the underlying
 * IEEE 802.15.4 radio. */
#define PHY_FREQUENCY_BAND_868  0x01
#define PHY_FREQUENCY_BAND_902  0x04
#define PHY_FREQUENCY_BAND_2400 0x08

/**************************************************************************//**
  \def PHY_PIB_TRANSMIT_POWER_DEFAULT
  \brief Default transmit power for the radio trancivier.
******************************************************************************/
/**************************************************************************//**
  \def PHY_PIB_CURRENT_CHANNEL_DEFAULT
  \brief Default channel to start for the radio trancivier.
******************************************************************************/
/**************************************************************************//**
  \def PHY_PIB_CURRENT_PAGE_DEFAULT
  \brief Default page to start for the radio trancivier.
******************************************************************************/

#define PHY_PIB_TRANSMIT_POWER_DEFAULT    DBM_3
#define PHY_PIB_CURRENT_CHANNEL_DEFAULT   0x0B
#define PHY_PIB_CURRENT_PAGE_DEFAULT      0
#define PHY_FREQUENCY_BANDS               PHY_FREQUENCY_BAND_2400

// Default values of MAC PIB attributes.

#define MAC_PIB_ACK_WAIT_DURATION_DEFAULT          54
#define MAC_PIB_ASSOCIATION_PERMIT_DEFAULT           false
#define MAC_PIB_AUTO_REQUEST_DEFAULT                 true
#define MAC_PIB_BATT_LIFE_EXT_DEFAULT                false
#define MAC_PIB_BEACON_PAYLOAD_DEFAULT               NULL
#define MAC_PIB_BEACON_PAYLOAD_LENGTH_DEFAULT        0
#define MAC_PIB_BEACON_ORDER_DEFAULT                 15
#define MAC_PIB_BEACON_TX_TIME_DEFAULT               0
#define MAC_PIB_COORD_SHORT_ADDR_DEFAULT             0xFFFF
#define MAC_PIB_COORD_EXT_ADDR_DEFAULT               0xFFFFFFFFFFFFFFFFLL ///< Not defined in standard.
#define MAC_PIB_GTS_PERMIT_DEFAULT                   true
#define MAC_PIB_MAX_CSMA_BACKOFFS_DEFAULT            4
#define MAC_PIB_MAX_BE_DEFAULT                       5
#define MAC_PIB_MIN_BE_DEFAULT                       3
#define MAC_PIB_PANID_DEFAULT                        0xFFFF
#define MAC_PIB_PROMISCUOUS_MODE_DEFAULT             false
#define MAC_PIB_RX_ON_WHEN_IDLE_DEFAULT              false
#define MAC_PIB_SHORT_ADDR_DEFAULT                   0xFFFF
#define MAC_PIB_SUPERFRAME_ORDER_DEFAULT             15
#define MAC_PIB_TRANSACTION_PERSISTENCE_TIME_DEFAULT 0x01F4
#define MAC_PIB_ASSOCIATED_PAN_COORD_DEFAULT         false
#define MAC_PIB_MAX_FRAME_RETRIES_DEFAULT            3
#define MAC_PIB_RESPONSE_WAIT_TIME_DEFAULT           32
#define MAC_PIB_SECURITY_ENABLED_DEFAULT             false

/******************************************************************************
                    Types section
******************************************************************************/
//! PHY PIB attribute identifiers (IEEE Std 802.15.4-2006. - table 23).
typedef enum
{
  PHY_PIB_CURRENT_CHANNEL_ID    = 0x00,
  PHY_PIB_CHANNELS_SUPPORTED_ID = 0x01,   // Read-only
  PHY_PIB_TRANSMIT_POWER_ID     = 0x02,
  PHY_PIB_CCA_MODE_ID           = 0x03,
  PHY_PIB_CURRENT_PAGE_ID       = 0x04,
  PHY_PIB_MAX_FRAME_DURATION_ID = 0x05,   // Read-only
  PHY_PIB_SHR_DURATION_ID       = 0x06,   // Read-only
  PHY_PIB_SYMBOLS_PER_OCTET_ID  = 0x07,   // Read-only
} PHY_PibId_t;

//! PHY PIB attribute types (IEEE Std 802.15.4-2006. - table 23).
typedef union
{
  uint8_t         channel;
  uint32_t        channelsSupported;
  int8_t          transmitPower;
  PHY_CcaMode_t   ccaMode;
  uint8_t         currentPage;
  uint16_t        maxFrameDuration;
  uint8_t         shrDuration;
  uint8_t         symbolsPerOctet;
} PHY_PibAttr_t;

//! MAC PIB attribute ID type.
typedef enum
{
  MAC_PIB_ACK_WAIT_DURATION_ID            = 0x40,
  MAC_PIB_ASSOCIATION_PERMIT_ID           = 0x41,
  MAC_PIB_AUTO_REQUEST_ID                 = 0x42,
  MAC_PIB_BATT_LIFE_EXT_ID                = 0x43,
  MAC_PIB_BATT_LIFE_EXT_PERIODS_ID        = 0x44,
  MAC_PIB_BEACON_PAYLOAD_ID               = 0x45,
  MAC_PIB_BEACON_PAYLOAD_LENGTH_ID        = 0x46,
  MAC_PIB_BEACON_ORDER_ID                 = 0x47,
  MAC_PIB_BEACON_TX_TIME_ID               = 0x48,
  MAC_PIB_BSN_ID                          = 0x49,
  MAC_PIB_COORD_EXT_ADDR_ID               = 0x4A,
  MAC_PIB_COORD_SHORT_ADDR_ID             = 0x4B,
  MAC_PIB_DSN_ID                          = 0x4C,
  MAC_PIB_GTS_PERMIT_ID                   = 0x4D,
  MAC_PIB_MAX_CSMA_BACKOFFS_ID            = 0x4E,
  MAC_PIB_MIN_BE_ID                       = 0x4F,
  MAC_PIB_PANID_ID                        = 0x50,
  MAC_PIB_PROMISCUOUS_MODE_ID             = 0x51,
  MAC_PIB_RX_ON_WHEN_IDLE_ID              = 0x52,
  MAC_PIB_SHORT_ADDR_ID                   = 0x53,
  MAC_PIB_SUPERFRAME_ORDER_ID             = 0x54,
  MAC_PIB_TRANSACTION_PERSISTENCE_TIME_ID = 0x55,
  MAC_PIB_ASSOCIATED_PAN_COORD_ID         = 0x56,
  MAC_PIB_MAX_BE_ID                       = 0x57,
  MAC_PIB_MAX_FRAME_TOTAL_WAIT_TIME_ID    = 0x58,
  MAC_PIB_MAX_FRAME_RETRIES_ID            = 0x59,
  MAC_PIB_RESPONSE_WAIT_TIME_ID           = 0x5A, ///< There is in additional parameter exist in PIB - MAC_PIB_RESPONSE_WAIT_TIME_MS_ID. Time in ms.
  MAC_PIB_SYNC_SYMBOL_OFFSET_ID           = 0x5B,
  MAC_PIB_TIMESTAMP_SUPPORTED_ID          = 0x5C,
  MAC_PIB_SECURITY_ENABLED_ID             = 0x5D,

  MAC_PIB_EXT_ADDR_ID                     = 0x6F,

  MAC_PIB_KEY_TABLE_ID                        = 0x71,
  MAC_PIB_KEY_TABLE_ENTRIES_ID                = 0x72,
  MAC_PIB_DEVICE_TABLE_ID                     = 0x73,
  MAC_PIB_DEVICE_TABLE_ENTRIES_ID             = 0x74,
  MAC_PIB_SECURITY_LEVEL_TABLE_ID             = 0x75,
  MAC_PIB_SECUTITY_LEVEL_TABLE_ENTRIES_ID     = 0x76,
  MAC_PIB_FRAME_COUNTER_ID                    = 0x77,
  MAC_PIB_AUTO_REQ_SECURITY_LEVEL_ID          = 0x78,
  MAC_PIB_AUTO_REQ_SECUTITY_KEY_ID_MODE_ID    = 0x79,
  MAC_PIB_AUTO_REQ_KEY_SOURCE_ID              = 0x7A,
  MAC_PIB_AUTO_REQUEST_KEY_INDEX_ID           = 0x7B,
  MAC_PIB_DEFAULT_KEY_SOURCE_ID               = 0x7C,
  MAC_PIB_PAN_COORD_EXT_ADDR_ID               = 0x7D,
  MAC_PIB_PAN_COORD_SHORT_ADDR_ID             = 0x7E,

  MAC_PIB_BEACON_TX_ENABLE_ID                 = 0x80, ///< Additional identifier. NOT described in the standard.
  MAC_PIB_RESPONSE_WAIT_TIME_MS_ID            = 0x81, ///< Additional identifier. NOT described in the standard. Time in ms. Read only.
  MAC_PIB_TRANSACTION_PERSIST_TIME_MS_ID      = 0x83, ///
  MAC_PIB_CCA_ED_THRES                        = 0x84, ///< Additional identifier.

} MAC_PibId_t;

//! MAC PIB attribute type.
typedef union
{
  uint32_t              ackWaitDuration;
  bool                  associationPermit;
  bool                  autoRequest;
  //bool                  battLifeExt;
  //uint8_t               battLifeExtPeriods;
  uint8_t               *beaconPayload;
  uint8_t               beaconPayloadLength;
  //uint8_t               beaconOrder;
  //uint32_t              beaconTxTime;
  uint8_t               bsn;
  ExtAddr_t             coordExtAddr;
  ShortAddr_t           coordShortAddr;
  uint8_t               dsn;
  bool                  gtsPermit;
  uint8_t               maxCsmaBackoffs;
  uint8_t               minBe;
  PanId_t               panId;
  //bool                  promiscuousMode;
  bool                  rxOnWhenIdle;
  ShortAddr_t           shortAddr;
  ExtAddr_t             extAddr;                   // Additional parameter. NOT described in the standard.
                                                   // This parameter replaces MAC_EXTENDED_ADDRESS constant.
                                                   // Device own extended address.
  //uint8_t               superframeOrder;
  uint16_t              transactionPersistenceTime;
  uint32_t              transactionPersistenceTimeInMs;
  bool                  associatedPanCoord;
  uint8_t               maxBe;
  //uint8_t               maxFrameTotalWaitTime;
  uint8_t               maxFrameRetries;
  uint8_t               responseWaitTime;
  bool                  timestampSupported;
  bool                  securityEnabled;
  bool                  beaconTxEnable;
  uint32_t              responseWaitTimeMs; // MAC response wait time in !!!milliseconds!!!.
  uint8_t               ccaEdThres; // Additional parameter. NOT described in the standard.
} MAC_PibAttr_t;

//! Union of MAC and PHY PIB attributes.
typedef union
{
  MAC_PibAttr_t macPibAttr;
  PHY_PibAttr_t phyPibAttr;
} MACPHY_PibAttr_t;

//! Union of MAC and PHY PIB attributes IDs.
typedef union
{
  MAC_PibId_t macPibId;
  PHY_PibId_t phyPibId;
} MACPHY_PibId_t;

/******************************************************************************
                   Constants section
******************************************************************************/

#endif /* _MACPHYPIB_H */

// eof macphyPib.h
