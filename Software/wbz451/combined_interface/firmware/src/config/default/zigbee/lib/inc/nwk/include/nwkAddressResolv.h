// DOM-IGNORE-BEGIN
/*******************************************************************************
  Network Address Resolve Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkAddressResolv.h

  Summary:
    This file provides the Interface of address resolution.

  Description:
    This file provides the Interface of NWK address resolution and its parameters.
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

#if !defined _NWK_ADDRESS_RESOLV_H
#define _NWK_ADDRESS_RESOLV_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Link short network and IEEE extended address.

  \param[in] shortAddr - a short address.
             extAddr - an extended address.
  \return 'true' if short and extended addresses are linked successfully
    otherwise 'false'.
 ******************************************************************************/
bool NWK_LinkShortAndExtAddress(const ShortAddr_t shortAddr,
  const ExtAddr_t extAddr);

/**************************************************************************//**
  \brief Remove the entry with given address from the address map.

  \param[in] extAddr - pointer to a extended address.
  \return None.
 ******************************************************************************/
void NWK_RemoveFromAddressMap(const ExtAddr_t *const extAddr);

/**************************************************************************//**
  \brief Searching a extended address by the short address.

  \param[in] shortAddr - a short address.
  \return Pointer to the extended address in the address map.
          \c NULL if the extended address is not found.
 ******************************************************************************/
const ExtAddr_t* NWK_GetExtByShortAddress(const ShortAddr_t shortAddr);

/**************************************************************************//**
  \brief Searching a short address by the extended address.

  \param[in] extAddr - pointer to the extended address.
  \return Pointer to the short address in the address map.
          \c NULL if the short address is not found.
 ******************************************************************************/
const ShortAddr_t* NWK_GetShortByExtAddress(const ExtAddr_t *const extAddr);

#endif /* _NWK_ADDRESS_RESOLV_H */
/** eof nwkAddressResolv.h */

