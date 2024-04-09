/*******************************************************************************
  ZLL Address Manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_AddressManager.h

  Summary:
    This file contains the ZLL Address Manager functions.

  Description:
    This file contains the ZLL Address Manager functions.
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


#ifndef N_ADDRESSMANAGER_H
#define N_ADDRESSMANAGER_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

typedef enum N_AddressManager_Status_t
{
    N_AddressManager_Status_Success,                    //< Returned values from the pool
    N_AddressManager_Status_RandomValue,                //< Returned random values
    N_AddressManager_Status_IllegalParameters,          //< The input parameters were incorrect
} N_AddressManager_Status_t;

typedef struct N_AddressManager_FreeRanges_t
{
    uint16_t addressFirst;
    uint16_t addressCount;
    uint16_t groupFirst;
    uint16_t groupCount;
} N_AddressManager_FreeRanges_t;

extern N_AddressManager_FreeRanges_t s_freeRanges;


/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Sets an address range and a group identifier range (obtained from another device)
        This function must only be called with address ranges obtained from another device's
        Address Manager (using AllocateAddressesForDealer).
        A virgin device automatically starts with a full address range.
	    Note: Call with all zeroes to make the address and group id pool of the
          device empty. The device is only capable of handing out random
          values after this

  \param[in] dealAddrFirst [in] The first address that can be dealt
  \param[in] dealAddrLast [in] The last address that can be dealt
  \param[in] dealGroupFirst [in] The first group identifier that can be dealt
  \param[in] dealGroupLast [in] The last group identifier that can be dealt

  \return Indicates success
 ******************************************************************************/

N_AddressManager_Status_t N_AddressManager_AssignAddressRange(
    uint16_t dealAddrFirst, uint16_t dealAddrLast, uint16_t dealGroupFirst, uint16_t dealGroupLast);

/**************************************************************************//**
  \brief Returns TRUE if there are group identifiers available

  \return TRUE if group identifiers available in the pool, FALSE otherwise
 ******************************************************************************/
bool N_AddressManager_HasFreeGroupIds(void);

/**************************************************************************//**
  \brief Allocates a group identifier for the caller

  \param[in] *pGroupId [out] The group identifier allocated for the caller

  \return Indication of success.
 ******************************************************************************/
N_AddressManager_Status_t N_AddressManager_AllocateGroupId(uint16_t* pGroupId);

/**************************************************************************//**
  \brief Get the current valid FreeGroupIdRangeBegin and idEnd possible

  \param[in] address pointers to idBegin and idEnd

  \return None
 ******************************************************************************/
void N_AddressManager_GetFreeGroupIdRange_Impl(uint16_t* idBegin, uint16_t* idEnd);

/***************************************************************************************************
* PLATFORM INTERNAL INTERFACE
***************************************************************************************************//** \privatesection
*/

/** Allocates a short address and group identifiers for a non-assignment-capable device
    \param numGroups [in] The number of group identifiers to allocate for the device
    \param *pAddr [out] The short address allocated for the device itself
    \param *pGroupIdFirst [out] The start of the allocated group identifier range for the device
    \returns Indication of success.
*/
N_AddressManager_Status_t N_AddressManager_AllocateAddresses(
    uint8_t numGroups, uint16_t* pAddr, uint16_t* pGroupIdFirst);

/** Allocates a short address and group identifiers for an assignment-capable device, plus
    ranges of addresses and group identifiers for the Address Manager of that device
    \param numGroups [in] The number of group identifiers to allocate for the device, must be 1
    \param *pAddr [out] The short address allocated for the device itself
    \param *pGroupIdFirst [out] The start of the allocated group identifier range for the device
    \param *pDealAddrFirst [out] The first address for the Address Manager of the other device
    \param *pDealAddrLast [out] The last address for the Address Manager of the other device
    \param *pDealGroupFirst [out] The first group identifier for the Address Manager of the other device
    \param *pDealGroupLast [out] The last group identifier for the Address Manager of the other device
    \returns Indication of success.
    \note short addresses and group identifiers range must be kept the same for now
*/
N_AddressManager_Status_t N_AddressManager_AllocateAddressesForDealer(
    uint8_t numGroups, uint16_t* pAddr, uint16_t* pGroupIdFirst,
    uint16_t* pDealAddrFirst, uint16_t* pDealAddrLast, uint16_t* pDealGroupFirst, uint16_t* pDealGroupLast);


/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_ADDRESSMANAGER_H
