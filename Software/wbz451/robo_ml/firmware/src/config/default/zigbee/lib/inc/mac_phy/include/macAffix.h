/*******************************************************************************
  MAC Affix Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macAffix.h

  Summary:
    This file contains the MAC frames' header and footer size constants.

  Description:
    This file contains the MAC frames' header and footer size constants.
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

#ifndef _MACAFFIX_H
#define _MACAFFIX_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/include/macphyPib.h>

/******************************************************************************
                        Defines section
******************************************************************************/
//! aMaxMACPayloadSize (IEEE 802.15.4-2006 Table 85).
#define MAC_MAX_MSDU_SIZE (PHY_MAX_PACKET_SIZE - MAC_MAX_MPDU_UNSECURED_OVERHEAD)
#define MAC_MAX_MSDU_SIZE_NO_SRC_ADDR_IEEE_DST_ADDR_MODE (PHY_MAX_PACKET_SIZE - MAC_MAX_MPDU_UNSECURED_OVERHEAD_NO_SRC_ADDR_IEEE_DST_ADDR_MODE)
//! aMaxBeaconOverhead (IEEE 802.15.4-2006 Table 85).
#define MAC_MAX_BEACON_HEADER_LENGTH MAC_MAX_BEACON_OVERHEAD
//! aMaxMPDUUnsecuredOverhead (IEEE 802.15.4-2006 Table 85).
#define MAC_MAX_DATA_FRAME_HEADER_LENGTH MAC_MAX_MPDU_UNSECURED_OVERHEAD

#ifndef _IEEE_ZIGBEE_COMPLIANCE_
#define MAC_MAX_INTERPAN_MSDU_SIZE  MAC_MAX_MSDU_SIZE
#else
#define MAC_MAX_INTERPAN_MSDU_SIZE (PHY_MAX_PACKET_SIZE - MAC_MAX_INTERPAN_MPDU_UNSECURED_OVERHEAD)
#endif // _IEEE_ZIGBEE_COMPLIANCE_

/**
 * \brief MAC footer length in common frame buffer.
 * It has zero length becouse FCS is calculated by RF chip. MAC does't has to
 * reserve bytes to allocate it's footer.
 */
#define MAC_MAX_DATA_FRAME_FOOTER_LENGTH 0U
//! Offset in common frame buffer for allocating MPDU.
#define MAC_MSDU_OFFSET MAC_MAX_MPDU_UNSECURED_OVERHEAD
//! MAC affix.
#define MAC_AFFIX_LENGTH (MAC_MAX_MPDU_UNSECURED_OVERHEAD + MAC_MAX_DATA_FRAME_FOOTER_LENGTH)

#endif /* _MACAFFIX_H */

// eof macAffix.h
