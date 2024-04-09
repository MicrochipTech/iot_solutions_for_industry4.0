/*******************************************************************************
  ZLL Address Manager Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_AddressManager_Bindings.h

  Summary:
    This file contains the ZLL Address Manager Bindings functions.

  Description:
    This file contains the ZLL Address Manager Bindings functions.
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


#ifndef N_ADDRESSMANAGER_BINDINGS_H
#define N_ADDRESSMANAGER_BINDINGS_H

#if defined(__GNUC__)
#include "zllplatform/infrastructure/N_Util/include/N_Util_Bindings.h"
#include "zllplatform/infrastructure/N_Util/include/N_Util.h"
#endif
// This

#define N_AddressManager_LogState N_AddressManager_LogState_Impl
#define N_AddressManager_AllocateAddresses N_AddressManager_AllocateAddresses_Impl
#define N_AddressManager_AllocateAddressesForDealer N_AddressManager_AllocateAddressesForDealer_Impl
#define N_AddressManager_AssignAddressRange N_AddressManager_AssignAddressRange_Impl
#define N_AddressManager_HasFreeGroupIds N_AddressManager_HasFreeGroupIds_Impl
#define N_AddressManager_AllocateGroupId N_AddressManager_AllocateGroupId_Impl
#define N_AddressManager_GetFreeGroupIdRange N_AddressManager_GetFreeGroupIdRange_Impl

#ifdef TESTHARNESS
#  define N_Flash_ItemInit N_Flash_Stub_ItemInit
#  define N_Flash_Read N_Flash_Stub_Read
#  define N_Flash_Write N_Flash_Stub_Write

#  define N_Util_Random N_Util_Stub_Random

#else
#  define N_Flash_ItemInit N_Flash_ItemInit_Impl
#  define N_Flash_Read N_Flash_Read_Impl
#  define N_Flash_Write N_Flash_Write_Impl

#  define N_Util_Random N_Util_Random_Impl

#endif

#endif /*N_ADDRESSMANAGER_BINDINGS_H*/
