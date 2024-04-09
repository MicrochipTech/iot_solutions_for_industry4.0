/*******************************************************************************
  MAC BanNode  Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macBanNode.h

  Summary:
    This file contains the Interface of the ban node functionality.

  Description:
    This file contains the Interface of the ban node functionality.
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

#ifndef _MAC_BAN_NODE_H
#define _MAC_BAN_NODE_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                              Definitions section
 ******************************************************************************/
#define LINK_COST_VALUE_NODE_BANNED 0xFF

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of node ban table entry. */
typedef struct _MAC_BanTableEntry_t
{
  /* IEEE address of the banned node. */
  ExtAddr_t  extAddr;
  /* Short address of the banned node. */
  ShortAddr_t  shortAddr;
  /* Link cost to be used for all messages from the node. */
  /* Valid range to correct the link cost (not to ban the node): 1 - 7 */
  /* Use link cost value LINK_COST_VALUE_NODE_BANNED to ban the node */
  uint8_t cost;
  /* Rssi to be used for all messages from the node. */
  int8_t rssi;
} MAC_BanTableEntry_t;

/** Type of the ban table size. */
typedef uint8_t MAC_BanTableSize_t;
/** Type of a ban entry index. */
typedef MAC_BanTableSize_t MAC_BanTableIndex_t;

/** Type of the ban node table. */
typedef struct _MAC_BanTable_t
{
  /* Pointer to the first entry of the ban table. */
  MAC_BanTableEntry_t  *entry;
  /* Current size of the ban node table. */
  MAC_BanTableSize_t  size;
  /* Index of the oldest banned node. */
  MAC_BanTableIndex_t  oldBannedNode;
  /* Ban all nodes by default (true) or not (false). After reset this attribute
   * is equal to false. */
  bool  banAll;
} MAC_BanTable_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Ban any frame from the node or correct link cost for all the frames
    from the node.

  \param shortAddr - short address of the node affected.
    If the short address of banned node is unknown then pass MAC_NO_SHORT_ADDR.
  \param extAddr - extended address of the node affetced.
    If the extended address of banned node is unknown then pass 0.
  \param cost - link cost value for all the frames received from the node.
    If node shall be baned - use link cost value LINK_COST_VALUE_NODE_BANNED.
  \param rssi - rssi value for all the frames received from the node.

  \return None.
 ******************************************************************************/
void MAC_BanNode(const ShortAddr_t shortAddr, const ExtAddr_t extAddr,
  const uint8_t cost, const int8_t rssi);

/**************************************************************************//**
  \brief Set global flag banAll

  \param banAll - ban all nodes by default or not.

  \return None.
 ******************************************************************************/
void MAC_BanAllNodes(const bool banAll);

/**************************************************************************//**
  \brief Is given short address banned or not.

  \param shortAddr - short address of the banned node.
  \param lqi - frame lqi pointer to be corrected if it is needed.
  \param rssi - frame rssi pointer to be corrected if it is needed.

  \return 'true' if the node is banned otherwise return 'false'.
 ******************************************************************************/
bool MAC_IsBannedShortAddr(const ShortAddr_t shortAddr, uint8_t *const lqi, int8_t *const rssi);

/**************************************************************************//**
  \brief Is given extended addresss banned or not.

  \param extAddr - extended address of the banned node.
  \param lqi - frame lqi pointer to be corrected if it is needed.
  \param rssi - frame rssi pointer to be corrected if it is needed.

  \return 'true' if the node is banned otherwise return 'false'.
 ******************************************************************************/
bool MAC_IsBannedExtAddr(const ExtAddr_t extAddr, uint8_t *const lqi, int8_t *const rssi);

/******************************************************************************
  \brief Reload from the config server and reset the ban table.
 ******************************************************************************/
void MAC_ResetBanTable(void);

#endif /* _MAC_BAN_NODE_H */
/** eof macBanNode.h */

