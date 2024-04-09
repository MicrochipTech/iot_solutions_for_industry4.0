// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Address Map Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkAddressMap.h

  Summary:
    This file contains the access interface to the address map.

  Description:
    This file contains the access interface to the NWK address map table.
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
#if !defined _NWK_ADDRESS_MAP_H
#define _NWK_ADDRESS_MAP_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/private/nwkSystem.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Type of size of the address map. */
typedef uint16_t NwkSizeOfAddressMap_t;

/** Type of entry of the address map. */
typedef struct _NwkAddressMapEntry_t
{
  /** The entry is busy (true) or not (false). */
  bool busy               : 1;
  /** Conflict of short addresses is detected (true) or not (false). */
  bool conflict           : 1;
  NwkBitField_t reserved  : 6;
  /** A network address (16-bit). */
  ShortAddr_t shortAddr;
  /** IEEE address (64-bit). */
  ExtAddr_t extAddr;
} NwkAddressMapEntry_t;

/** Type of the address map. */
typedef struct _NwkAddressMap_t
{
  /** Array of address map entries. */
  NwkAddressMapEntry_t *table;
  /** Pointer to memory area after last entry of the address map. */
  NwkAddressMapEntry_t *end;
  /** Current position for a new entry. */
  NwkAddressMapEntry_t *current;
} NwkAddressMap_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Add a short and extended addresses in the address map.

  \param[in] shortAddr - a short address.
  \param[in] extAddr - an extended address.
  \param[in] isConflict - 'true' if shortAddr conflict with other short address
                          in the network otherwise 'false'.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkAddToAddressMap(const ShortAddr_t shortAddr,const ExtAddr_t extAddr, const bool isConflict);

/**************************************************************************//**
  \brief Find entry in the address map by IEEE address.

  \param[in] extAddr - pointer to IEEE extended 64-bit address.
  \return Pointer to an entry in the address map.
 ******************************************************************************/
NWK_PRIVATE NwkAddressMapEntry_t* nwkFindAddressMapEntryByExtAddr(const ExtAddr_t *const extAddr);

/**************************************************************************//**
  \brief Find entry in the address map by short address.

  \param[in] shortAddr - a network short address.
  \return Pointer to an entry in the address map.
 ******************************************************************************/
NWK_PRIVATE NwkAddressMapEntry_t* nwkFindAddressMapEntryByShortAddr(const ShortAddr_t shortAddr);

#if defined _RESOLVE_ADDR_CONFLICT_
/**************************************************************************//**
  \brief Find entry in the address map with conflicted short address.

  \return Pointer to an entry in the address map.
 ******************************************************************************/
NWK_PRIVATE NwkAddressMapEntry_t* nwkFindAddrMapConflictEntry(void);
#endif /* _RESOLVE_ADDR_CONFLICT_ */

/**************************************************************************//**
  \brief Get maximum size of NWK address map.
 ******************************************************************************/
NWK_PRIVATE NwkSizeOfAddressMap_t nwkAddrMapSize(void);

/**************************************************************************//**
  \brief Reset the address map.
 ******************************************************************************/
NWK_PRIVATE void nwkResetAddressMap(void);

#endif /* _NWK_ADDRESS_MAP_H */
/** eof nwkAddressMap.h */

