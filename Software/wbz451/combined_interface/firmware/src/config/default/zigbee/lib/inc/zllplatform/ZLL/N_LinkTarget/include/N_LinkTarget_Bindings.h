/*******************************************************************************
  ZLL Link Target Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_LinkTarget_Bindings.h

  Summary:
    This file contains the ZLL Link Target Bindings functions.

  Description:
    This file contains the ZLL Link Target Bindings functions.
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

#ifndef N_LINKTARGET_BINDINGS_H
#define N_LINKTARGET_BINDINGS_H
// implemented interface(s)
#define N_LinkTarget_Subscribe N_LinkTarget_Subscribe_Impl
#define N_LinkTarget_SetTargetType N_LinkTarget_SetTargetType_Impl
#define N_LinkTarget_SetTouchlinkPriority N_LinkTarget_SetTouchlinkPriority_Impl
#define N_LinkTarget_AllowStealing N_LinkTarget_AllowStealing_Impl
// N_Radio_Internal
#define N_Radio_SetChannel N_Radio_SetChannel_Impl
// used interfaces
#ifdef TESTHARNESS

#  define N_AddressManager_AssignAddressRange N_AddressManager_Stub_AssignAddressRange
#  define N_AddressManager_AllocateAddresses N_AddressManager_Stub_AllocateAddresses
#  define N_AddressManager_AllocateAddressesForDealer N_AddressManager_Stub_AllocateAddressesForDealer

#  define N_Cmi_AddChild N_Cmi_Stub_AddChild
#  define N_Cmi_GetNetworkKey N_Cmi_Stub_GetNetworkKey

#  define N_Connection_Subscribe N_Connection_Stub_Subscribe
#  define N_Connection_JoinNetwork N_Connection_Stub_JoinNetwork
#  define N_Connection_UpdateNetwork N_Connection_Stub_UpdateNetwork
#  define N_Connection_SetTargetInterPanModeOn N_Connection_Stub_SetTargetInterPanModeOn
#  define N_Connection_SetTargetInterPanModeOff N_Connection_Stub_SetTargetInterPanModeOff
#  define N_Connection_FindFreePan N_Connection_Stub_FindFreePan
#  define N_Connection_AbortAssociate N_Connection_Stub_AbortAssociate

#  define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_Stub_GetNetworkExtendedPanId
#  define N_DeviceInfo_GetNetworkAddress N_DeviceInfo_Stub_GetNetworkAddress
#  define N_DeviceInfo_IsFactoryNew N_DeviceInfo_Stub_IsFactoryNew
#  define N_DeviceInfo_IsEndDevice N_DeviceInfo_Stub_IsEndDevice
#  define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_Stub_GetNetworkUpdateId
#  define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_Stub_GetNetworkChannel
#  define N_DeviceInfo_GetNetworkPanId N_DeviceInfo_Stub_GetNetworkPanId
#  define N_DeviceInfo_GetChannelMask N_DeviceInfo_Stub_GetChannelMask
#  define N_DeviceInfo_GetTouchlinkRssiCorrection N_DeviceInfo_Stub_GetTouchlinkRssiCorrection
#  define N_DeviceInfo_GetTouchlinkRssiThreshold N_DeviceInfo_Stub_GetTouchlinkRssiThreshold
#  define N_DeviceInfo_GetIEEEAddress N_DeviceInfo_Stub_GetIEEEAddress
#  define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_Stub_GetNrChannelsInChannelMask
#  define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_Stub_GetChannelForIndex
#  define N_DeviceInfo_IsChannelInMask N_DeviceInfo_Stub_IsChannelInMask
#  define N_DeviceInfo_IsAddressAssignmentCapable N_DeviceInfo_Stub_IsAddressAssignmentCapable
#  define N_DeviceInfo_CanBeLinkInitiator N_DeviceInfo_Stub_CanBeLinkInitiator
#  define N_DeviceInfo_GetTouchlinkZerodBmTransmitPower N_DeviceInfo_Stub_GetTouchlinkZerodBmTransmitPower
#  define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_Stub_GetTrustCenterMode
#  define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_Stub_GetPrimaryChannelMask

#  define N_Timer_Start16 N_Timer_Start16_Impl
#  define N_Timer_Stop N_Timer_Stop_Impl
#  define N_Timer_IsRunning N_Timer_IsRunning_Impl

#  define N_InterPan_Subscribe N_InterPan_Stub_Subscribe
#  define N_InterPan_SendScanResponse N_InterPan_Stub_SendScanResponse
#  define N_InterPan_SendNetworkJoinRouterResponse N_InterPan_Stub_SendNetworkJoinRouterResponse
#  define N_InterPan_SendDeviceInfoResponse N_InterPan_Stub_SendDeviceInfoResponse
#  define N_InterPan_SendNetworkStartResponse N_InterPan_Stub_SendNetworkStartResponse
#  define N_InterPan_SendNetworkJoinEndDeviceResponse N_InterPan_Stub_SendNetworkJoinEndDeviceResponse
#  define N_InterPan_SendNetworkJoinEndDeviceRequest N_InterPan_Stub_SendNetworkJoinEndDeviceRequest
#  define N_InterPan_SendNetworkJoinRouterRequest N_InterPan_Stub_SendNetworkJoinRouterRequest

#  define N_PacketDistributor_GetNumberOfZclEndpoints N_PacketDistributor_Stub_GetNumberOfZclEndpoints
#  define N_PacketDistributor_GetZclEndpointFromIndex N_PacketDistributor_Stub_GetZclEndpointFromIndex
#  define N_PacketDistributor_FindEndpoint N_PacketDistributor_Stub_FindEndpoint
#  define N_PacketDistributor_GetGroupCount N_PacketDistributor_Stub_GetGroupCount
#  define N_PacketDistributor_GetTotalGroupCount N_PacketDistributor_Stub_GetTotalGroupCount

#  define N_Security_GetKeyBitMask N_Security_Stub_GetKeyBitMask
#  define N_Security_GetResponseId N_Security_Stub_GetResponseId
#  define N_Security_GetTransactionId N_Security_Stub_GetTransactionId
#  define N_Security_UseNetworkKey N_Security_Stub_UseNetworkKey
#  define N_Security_GetNetworkKey N_Security_Stub_GetNetworkKey
#  define N_Security_EncryptNetworkKey N_Security_Stub_EncryptNetworkKey
#  define N_Security_DecryptNetworkKey N_Security_Stub_DecryptNetworkKey
#  define N_Security_GenerateNewNetworkKey N_Security_Stub_GenerateNewNetworkKey

#  define N_Radio_SetTxPower N_Radio_Stub_SetTxPower
#  define N_Radio_GetTxPower N_Radio_Stub_GetTxPower

// These functions do not need to be stubbed, they are utility functions
#  define N_Security_IsCompatibleWithKeyMask N_Security_IsCompatibleWithKeyMask_Impl
#  define N_Security_FindSharedKeyIndex N_Security_FindSharedKeyIndex_Impl

#  define N_Util_Random N_Util_Stub_Random

#else

// bindings that are diferent for end-device and router

#  if defined(ZIGBEE_END_DEVICE)
#    define N_Connection_EnddeviceJoinNetwork N_ConnectionEndDevice_JoinNetwork_Impl
#    define N_Connection_EnddeviceSubscribe N_ConnectionEndDevice_Subscribe_Impl
#    define N_Connection_EnddeviceFindFreePan N_ConnectionEndDevice_FindFreePan_Impl
#    define N_Connection_EnddeviceUpdateNetwork N_Connection_UpdateNetwork_Impl
#    define N_Connection_EnddeviceAbortAssociate N_ConnectionEndDevice_AbortAssociate_Impl
#endif
#if defined(ZIGBEE_ROUTER) || defined(ZIGBEE_COORDINATOR)
#    define N_Connection_RouterJoinNetwork N_ConnectionRouter_JoinNetwork_Impl
#    define N_Connection_RouterSubscribe N_ConnectionRouter_Subscribe_Impl
#    define N_Connection_RouterFindFreePan N_ConnectionRouter_FindFreePan_Impl
#    define N_Connection_RouterAbortAssociate N_ConnectionRouter_AbortAssociate_Impl
# endif

// bindings that are the same for end-device and router
#define N_Connection_UpdateNetwork N_Connection_UpdateNetwork_Impl
#define N_Connection_SetTargetInterPanMacChannel N_Connection_SetTargetInterPanMacChannel_Impl
#define N_Connection_SetInitiatorInterPanModeOn N_Connection_SetInitiatorInterPanModeOn_Impl
#define N_Connection_SetInitiatorInterPanModeOff N_Connection_SetInitiatorInterPanModeOff_Impl
#define N_Connection_InitiatorIsSetInterPanModeInProgress N_Connection_InitiatorIsSetInterPanModeInProgress_Impl
#define N_Connection_SetTargetInterPanModeOn N_Connection_SetTargetInterPanModeOn_Impl
#define N_Connection_SetTargetInterPanModeOff N_Connection_SetTargetInterPanModeOff_Impl
#define N_Connection_TargetIsInterpanModeOn N_Connection_TargetIsInterpanModeOn_Impl

#  define N_AddressManager_AssignAddressRange N_AddressManager_AssignAddressRange_Impl
#  define N_AddressManager_AllocateAddresses N_AddressManager_AllocateAddresses_Impl
#  define N_AddressManager_AllocateAddressesForDealer N_AddressManager_AllocateAddressesForDealer_Impl

#  define N_Cmi_AddChild N_Cmi_AddChild_Impl
#  define N_Cmi_GetNetworkKey N_Cmi_GetNetworkKey_Impl

#  define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_GetNetworkExtendedPanId_Impl
#  define N_DeviceInfo_GetNetworkAddress N_DeviceInfo_GetNetworkAddress_Impl
#  define N_DeviceInfo_IsFactoryNew N_DeviceInfo_IsFactoryNew_Impl
#  define N_DeviceInfo_IsEndDevice N_DeviceInfo_IsEndDevice_Impl
#  define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_GetNetworkUpdateId_Impl
#  define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_GetNetworkChannel_Impl
#  define N_DeviceInfo_GetNetworkPanId N_DeviceInfo_GetNetworkPanId_Impl
#  define N_DeviceInfo_GetChannelMask N_DeviceInfo_GetChannelMask_Impl
#  define N_DeviceInfo_GetTouchlinkRssiCorrection N_DeviceInfo_GetTouchlinkRssiCorrection_Impl
#  define N_DeviceInfo_GetTouchlinkRssiThreshold N_DeviceInfo_GetTouchlinkRssiThreshold_Impl
#  define N_DeviceInfo_GetIEEEAddress N_DeviceInfo_GetIEEEAddress_Impl
#  define N_DeviceInfo_IsChannelInMask N_DeviceInfo_IsChannelInMask_Impl
#  define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_GetNrChannelsInChannelMask_Impl
#  define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_GetChannelForIndex_Impl
#  define N_DeviceInfo_IsAddressAssignmentCapable N_DeviceInfo_IsAddressAssignmentCapable_Impl
#  define N_DeviceInfo_CanBeLinkInitiator N_DeviceInfo_CanBeLinkInitiator_Impl
#  define N_DeviceInfo_GetTouchlinkZerodBmTransmitPower N_DeviceInfo_GetTouchlinkZerodBmTransmitPower_Impl
#  define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_GetTrustCenterMode_Impl
#  define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_GetPrimaryChannelMask_Impl
#  define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_GetSecondaryChannelMask_Impl

#  define N_Timer_Start16 N_Timer_Start16_Impl
#  define N_Timer_Stop N_Timer_Stop_Impl
#  define N_Timer_IsRunning N_Timer_IsRunning_Impl

#  define N_InterPan_Subscribe N_InterPan_Subscribe_Impl
#  define N_InterPan_SendScanResponse N_InterPan_SendScanResponse_Impl
#  define N_InterPan_SendNetworkJoinRouterResponse N_InterPan_SendNetworkJoinRouterResponse_Impl
#  define N_InterPan_SendDeviceInfoResponse N_InterPan_SendDeviceInfoResponse_Impl
#  define N_InterPan_SendNetworkStartResponse N_InterPan_SendNetworkStartResponse_Impl
#  define N_InterPan_SendNetworkJoinEndDeviceResponse N_InterPan_SendNetworkJoinEndDeviceResponse_Impl
#  define N_InterPan_SendNetworkJoinEndDeviceRequest N_InterPan_SendNetworkJoinEndDeviceRequest_Impl
#  define N_InterPan_SendNetworkJoinRouterRequest N_InterPan_SendNetworkJoinRouterRequest_Impl

#  define N_PacketDistributor_GetNumberOfZclEndpoints N_PacketDistributor_GetNumberOfZclEndpoints_Impl
#  define N_PacketDistributor_GetZclEndpointFromIndex N_PacketDistributor_GetZclEndpointFromIndex_Impl
#  define N_PacketDistributor_FindEndpoint N_PacketDistributor_FindEndpoint_Impl
#  define N_PacketDistributor_GetGroupCount N_PacketDistributor_GetGroupCount_Impl
#  define N_PacketDistributor_GetTotalGroupCount N_PacketDistributor_GetTotalGroupCount_Impl
#  define N_PacketDistributor_GetNumberOfZllEndpoints N_PacketDistributor_GetNumberOfZllEndpoints_Impl
#  define N_PacketDistributor_GetZllEndpointFromIndex N_PacketDistributor_GetZllEndpointFromIndex_Impl
#  define N_PacketDistributor_GetTotalGroupCountZll N_PacketDistributor_GetTotalGroupCountZll_Impl

#  define N_Security_GetResponseId N_Security_GetResponseId_Impl
#  define N_Security_GenerateNewNetworkKey N_Security_GenerateNewNetworkKey_Impl
#  define N_Security_EncryptNetworkKey N_Security_EncryptNetworkKey_Impl
#  define N_Security_DecryptNetworkKey N_Security_DecryptNetworkKey_Impl
#  define N_Security_GetKeyBitMask N_Security_GetKeyBitMask_Impl
#  define N_Security_IsCompatibleWithKeyMask N_Security_IsCompatibleWithKeyMask_Impl
#  define N_Security_FindSharedKeyIndex N_Security_FindSharedKeyIndex_Impl

#  define N_Radio_SetTxPower N_Radio_SetTxPower_Impl
#  define N_Radio_GetTxPower N_Radio_GetTxPower_Impl

#  define N_Util_Random N_Util_Random_Impl

#endif

#endif /*N_LINKTARGET_BINDINGS_H*/