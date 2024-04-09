/*******************************************************************************
  ZLL Device Information Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Deviceinfo_Bindings.h

  Summary:
    This file contains the ZLL Device Information Bindings functions.

  Description:
    This file contains the ZLL Device Information Bindings functions.
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


#ifndef N_DEVICEINFO_BINDINGS_H
#define N_DEVICEINFO_BINDINGS_H

// This
#define N_DeviceInfo_Subscribe N_DeviceInfo_Subscribe_Impl
#define N_DeviceInfo_GetStackVersion N_DeviceInfo_GetStackVersion_Impl
#define N_DeviceInfo_GetTouchlinkRssiCorrection N_DeviceInfo_GetTouchlinkRssiCorrection_Impl
#define N_DeviceInfo_GetTouchlinkRssiThreshold N_DeviceInfo_GetTouchlinkRssiThreshold_Impl
#define N_DeviceInfo_GetNetworkPanId N_DeviceInfo_GetNetworkPanId_Impl
#define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_GetNetworkExtendedPanId_Impl
#define N_DeviceInfo_GetNetworkAddress N_DeviceInfo_GetNetworkAddress_Impl
#define N_DeviceInfo_GetParentNetworkAddress N_DeviceInfo_GetParentNetworkAddress_Impl
#define N_DeviceInfo_GetIEEEAddress N_DeviceInfo_GetIEEEAddress_Impl
#define N_DeviceInfo_GetParentIEEEAddress N_DeviceInfo_GetParentIEEEAddress_Impl
#define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_GetNetworkChannel_Impl
#define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_GetNetworkUpdateId_Impl
#define N_DeviceInfo_IsFactoryNew N_DeviceInfo_IsFactoryNew_Impl
#define N_DeviceInfo_IsEndDevice N_DeviceInfo_IsEndDevice_Impl
#define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_GetPrimaryChannelMask_Impl
#define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_GetSecondaryChannelMask_Impl
#define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_GetNrChannelsInChannelMask_Impl
#define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_GetChannelForIndex_Impl
#define N_DeviceInfo_IsChannelInMask N_DeviceInfo_IsChannelInMask_Impl
#define N_DeviceInfo_IsAddressAssignmentCapable N_DeviceInfo_IsAddressAssignmentCapable_Impl
#define N_DeviceInfo_CanBeLinkInitiator N_DeviceInfo_CanBeLinkInitiator_Impl
#define N_DeviceInfo_GetTouchlinkZerodBmTransmitPower N_DeviceInfo_GetTouchlinkZerodBmTransmitPower_Impl
#define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_GetTrustCenterMode_Impl

#define N_DeviceInfo_SetTouchlinkRssiCorrection N_DeviceInfo_SetTouchlinkRssiCorrection_Impl
#define N_DeviceInfo_SetTouchlinkRssiThreshold N_DeviceInfo_SetTouchlinkRssiThreshold_Impl
#define N_DeviceInfo_SetNetworkPanId N_DeviceInfo_SetNetworkPanId_Impl
#define N_DeviceInfo_SetNetworkExtendedPanId N_DeviceInfo_SetNetworkExtendedPanId_Impl
#define N_DeviceInfo_SetNetworkAddress N_DeviceInfo_SetNetworkAddress_Impl
#define N_DeviceInfo_SetParentNetworkAddress N_DeviceInfo_SetParentNetworkAddress_Impl
#define N_DeviceInfo_SetNetworkChannel N_DeviceInfo_SetNetworkChannel_Impl
#define N_DeviceInfo_SetNetworkUpdateId N_DeviceInfo_SetNetworkUpdateId_Impl
#define N_DeviceInfo_SetFactoryNew N_DeviceInfo_SetFactoryNew_Impl
#define N_DeviceInfo_SetPrimaryChannelMask N_DeviceInfo_SetPrimaryChannelMask_Impl
#define N_DeviceInfo_SetSecondaryChannelMask N_DeviceInfo_SetSecondaryChannelMask_Impl
#define N_DeviceInfo_SetParentIEEEAddress N_DeviceInfo_SetParentIEEEAddress_Impl
#define N_DeviceInfo_SetCanBeLinkInitiator N_DeviceInfo_SetCanBeLinkInitiator_Impl
#define N_DeviceInfo_SetAddressAssignmentCapable N_DeviceInfo_SetAddressAssignmentCapable_Impl
#define N_DeviceInfo_SetTrustCenterMode N_DeviceInfo_SetTrustCenterMode_Impl
#define N_DeviceInfo_GetProfileIdForEndpoint N_DeviceInfo_GetProfileIdForEndpoint_Impl

#ifdef TESTHARNESS
    #define NLME_GetExtAddr N_DeviceInfo_Wrapper_NLME_GetExtAddr

    #define N_Flash_ItemInit N_Flash_Stub_ItemInit
    #define N_Flash_Read N_Flash_Stub_Read
    #define N_Flash_Write N_Flash_Stub_Write
#endif

#endif  /*N_DEVICEINFO_BINDINGS_H*/