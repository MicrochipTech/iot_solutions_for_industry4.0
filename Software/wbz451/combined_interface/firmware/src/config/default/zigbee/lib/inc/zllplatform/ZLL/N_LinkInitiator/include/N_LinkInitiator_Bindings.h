/*******************************************************************************
  ZLL Link Initiator Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_LinkInitiator_Bindings.h

  Summary:
    This file contains the ZLL Link Initiator Bindings functions.

  Description:
    This file contains the ZLL Link Initiator Bindings functions.
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

#ifndef N_LINKINITIATOR_BINDINGS_H
#define N_LINKINITIATOR_BINDINGS_H
// implemented interface(s)
#define N_LinkInitiator_Subscribe N_LinkInitiator_Subscribe_Impl
#define N_LinkInitiator_Scan N_LinkInitiator_Scan_Impl
#define N_LinkInitiator_StopScan N_LinkInitiator_StopScan_Impl
#define N_LinkInitiator_IdentifyStartRequest N_LinkInitiator_IdentifyStartRequest_Impl
#define N_LinkInitiator_IdentifyStopRequest N_LinkInitiator_IdentifyStopRequest_Impl
#define N_LinkInitiator_DeviceInfoRequest N_LinkInitiator_DeviceInfoRequest_Impl
#define N_LinkInitiator_JoinDevice N_LinkInitiator_JoinDevice_Impl
#define N_LinkInitiator_ResetDeviceToFactoryNew N_LinkInitiator_ResetDeviceToFactoryNew_Impl

// used interfaces
#ifdef TESTHARNESS

# define N_AddressManager_AllocateAddresses N_AddressManager_Stub_AllocateAddresses
# define N_AddressManager_AllocateAddressesForDealer N_AddressManager_Stub_AllocateAddressesForDealer
# define N_AddressManager_AssignAddressRange N_AddressManager_Stub_AssignAddressRange

# define N_Cmi_Subscribe N_Cmi_Stub_Subscribe
# define N_Cmi_SetMacChannel N_Cmi_Stub_SetMacChannel
# define N_Cmi_UpdateNetworkChannel N_Cmi_Stub_UpdateNetworkChannel
# define N_Cmi_GetNetworkKey N_Cmi_Stub_GetNetworkKey

# define N_Connection_Subscribe N_Connection_Stub_Subscribe
# define N_Connection_JoinNetwork N_Connection_Stub_JoinNetwork
# define N_Connection_UpdateNetwork N_Connection_Stub_UpdateNetwork
# define N_Connection_ReconnectUrgent N_Connection_Stub_ReconnectUrgent
# define N_Connection_SetInitiatorInterPanModeOn N_Connection_Stub_SetInitiatorInterPanModeOn
# define N_Connection_SetInitiatorInterPanModeOff N_Connection_Stub_SetInitiatorInterPanModeOff
#define N_Connection_InitiatorIsSetInterPanModeInProgress N_Connection_Stub_IsSetInterPanModeInProgress_Impl
# define N_Connection_FindFreePan N_Connection_Stub_FindFreePan

# define N_InterPan_Subscribe N_InterPan_Stub_Subscribe
# define N_InterPan_BroadcastScanRequest N_InterPan_Stub_BroadcastScanRequest
# define N_InterPan_SendDeviceInfoRequest N_InterPan_Stub_SendDeviceInfoRequest
# define N_InterPan_SendIdentifyRequest N_InterPan_Stub_SendIdentifyRequest
# define N_InterPan_SendNetworkJoinRouterRequest N_InterPan_Stub_SendNetworkJoinRouterRequest
# define N_InterPan_SendNetworkStartRequest N_InterPan_Stub_SendNetworkStartRequest
# define N_InterPan_SendNetworkJoinEndDeviceRequest N_InterPan_Stub_SendNetworkJoinEndDeviceRequest
# define N_InterPan_SendNetworkUpdateRequest N_InterPan_Stub_SendNetworkUpdateRequest
# define N_InterPan_SendNetworkJoinRouterResponse N_InterPan_Stub_SendNetworkJoinRouterResponse
# define N_InterPan_SendNetworkJoinEndDeviceResponse N_InterPan_Stub_SendNetworkJoinEndDeviceResponse
# define N_InterPan_SendResetToFactoryNewRequest N_InterPan_Stub_SendResetToFactoryNewRequest

# define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_Stub_GetNetworkExtendedPanId
# define N_DeviceInfo_GetNetworkAddress N_DeviceInfo_Stub_GetNetworkAddress
# define N_DeviceInfo_IsFactoryNew N_DeviceInfo_Stub_IsFactoryNew
# define N_DeviceInfo_IsEndDevice N_DeviceInfo_Stub_IsEndDevice
# define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_Stub_GetNetworkUpdateId
# define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_Stub_GetNetworkChannel
# define N_DeviceInfo_GetTouchlinkRssiThreshold N_DeviceInfo_Stub_GetTouchlinkRssiThreshold
# define N_DeviceInfo_GetNetworkPanId N_DeviceInfo_Stub_GetNetworkPanId
# define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_Stub_GetChannelForIndex
# define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_Stub_GetNrChannelsInChannelMask
# define N_DeviceInfo_IsChannelInMask N_DeviceInfo_Stub_IsChannelInMask
# define N_DeviceInfo_GetIEEEAddress N_DeviceInfo_Stub_GetIEEEAddress
# define N_DeviceInfo_IsAddressAssignmentCapable N_DeviceInfo_Stub_IsAddressAssignmentCapable
# define N_DeviceInfo_GetTouchlinkZerodBmTransmitPower N_DeviceInfo_Stub_GetTouchlinkZerodBmTransmitPower
# define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_Stub_GetTrustCenterMode
# define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_Stub_GetPrimaryChannelMask
# define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_Stub_GetSecondaryChannelMask

# define N_PacketDistributor_GetTotalGroupCount N_PacketDistributor_Stub_GetTotalGroupCount

# define N_Security_GetTransactionId N_Security_Stub_GetTransactionId
# define N_Security_GetKeyBitMask N_Security_Stub_GetKeyBitMask
# define N_Security_GetResponseId N_Security_Stub_GetResponseId
# define N_Security_EncryptNetworkKey N_Security_Stub_EncryptNetworkKey
# define N_Security_GenerateNewNetworkKey N_Security_Stub_GenerateNewNetworkKey
# define N_Security_DecryptNetworkKey N_Security_Stub_DecryptNetworkKey

// These functions do not need to be stubbed, they are utility functions
# define N_Security_IsCompatibleWithKeyMask N_Security_IsCompatibleWithKeyMask_Impl
# define N_Security_FindSharedKeyIndex N_Security_FindSharedKeyIndex_Impl

# define N_Timer_Start16 N_Timer_Start16_Impl

# define N_Zdp_ClientSubscribe N_Zdp_Stub_ClientSubscribe
# define N_Zdp_SendNwkAddrReq N_Zdp_Stub_SendNwkAddrReq
# define N_Zdp_SendIeeeAddrReq N_Zdp_Stub_SendIeeeAddrReq
# define N_Zdp_SendNodeDescReq N_Zdp_Stub_SendNodeDescReq_Impl

# define N_Radio_SetTxPower N_Radio_Stub_SetTxPower
# define N_Radio_GetTxPower N_Radio_Stub_GetTxPower

# define N_Util_Random N_Util_Stub_Random

#else

// bindings that are diferent for end-device and router

# if defined(ZIGBEE_END_DEVICE)
#  define N_Connection_EnddeviceSubscribe N_ConnectionEndDevice_Subscribe_Impl
#  define N_Connection_EnddeviceJoinNetwork N_ConnectionEndDevice_JoinNetwork_Impl
#  define N_Connection_EnddeviceReconnectUrgent N_ConnectionEndDevice_ReconnectUrgent_Impl
#  define N_Connection_EnddeviceFindFreePan N_ConnectionEndDevice_FindFreePan_Impl
#endif
#if defined(ZIGBEE_ROUTER) || defined(ZIGBEE_COORDINATOR)
#  define N_Connection_RouterSubscribe N_ConnectionRouter_Subscribe_Impl
#  define N_Connection_RouterJoinNetwork N_ConnectionRouter_JoinNetwork_Impl
#  define N_Connection_RouterReconnectUrgent N_ConnectionRouter_ReconnectUrgent_Impl
#  define N_Connection_RouterFindFreePan N_ConnectionRouter_FindFreePan_Impl
# endif

// bindings that are the same for end-device and router
#define N_Connection_UpdateNetwork N_Connection_UpdateNetwork_Impl
#define N_Connection_SetInitiatorInterPanModeOn N_Connection_SetInitiatorInterPanModeOn_Impl
#define N_Connection_SetInitiatorInterPanModeOff N_Connection_SetInitiatorInterPanModeOff_Impl
#define N_Connection_InitiatorIsSetInterPanModeInProgress N_Connection_InitiatorIsSetInterPanModeInProgress_Impl
#define N_Connection_SetTargetInterPanModeOn N_Connection_SetTargetInterPanModeOn_Impl
#define N_Connection_SetTargetInterPanModeOff N_Connection_SetTargetInterPanModeOff_Impl
#define N_Connection_TargetIsInterpanModeOn N_Connection_TargetIsInterpanModeOn_Impl
#define N_Connection_SetTargetInterPanMacChannel N_Connection_SetTargetInterPanMacChannel_Impl

# define N_AddressManager_AllocateAddresses N_AddressManager_AllocateAddresses_Impl
# define N_AddressManager_AllocateAddressesForDealer N_AddressManager_AllocateAddressesForDealer_Impl
# define N_AddressManager_AssignAddressRange N_AddressManager_AssignAddressRange_Impl

# define N_Cmi_Subscribe N_Cmi_Subscribe_Impl
# define N_Cmi_SetMacChannel N_Cmi_SetMacChannel_Impl
# define N_Cmi_UpdateNetworkChannel N_Cmi_UpdateNetworkChannel_Impl
# define N_Cmi_GetNetworkKey N_Cmi_GetNetworkKey_Impl

# define N_InterPan_Subscribe N_InterPan_Subscribe_Impl
# define N_InterPan_BroadcastScanRequest N_InterPan_BroadcastScanRequest_Impl
# define N_InterPan_SendDeviceInfoRequest N_InterPan_SendDeviceInfoRequest_Impl
# define N_InterPan_SendIdentifyRequest N_InterPan_SendIdentifyRequest_Impl
# define N_InterPan_SendNetworkJoinRouterRequest N_InterPan_SendNetworkJoinRouterRequest_Impl
# define N_InterPan_SendNetworkStartRequest N_InterPan_SendNetworkStartRequest_Impl
# define N_InterPan_SendNetworkJoinEndDeviceRequest N_InterPan_SendNetworkJoinEndDeviceRequest_Impl
# define N_InterPan_SendNetworkUpdateRequest N_InterPan_SendNetworkUpdateRequest_Impl
# define N_InterPan_SendNetworkJoinRouterResponse N_InterPan_SendNetworkJoinRouterResponse_Impl
# define N_InterPan_SendNetworkJoinEndDeviceResponse N_InterPan_SendNetworkJoinEndDeviceResponse_Impl
# define N_InterPan_SendResetToFactoryNewRequest N_InterPan_SendResetToFactoryNewRequest_Impl

# define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_GetNetworkExtendedPanId_Impl
# define N_DeviceInfo_GetNetworkAddress N_DeviceInfo_GetNetworkAddress_Impl
# define N_DeviceInfo_IsFactoryNew N_DeviceInfo_IsFactoryNew_Impl
# define N_DeviceInfo_IsEndDevice N_DeviceInfo_IsEndDevice_Impl
# define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_GetNetworkUpdateId_Impl
# define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_GetNetworkChannel_Impl
# define N_DeviceInfo_GetTouchlinkRssiThreshold N_DeviceInfo_GetTouchlinkRssiThreshold_Impl
# define N_DeviceInfo_GetNetworkPanId N_DeviceInfo_GetNetworkPanId_Impl
# define N_DeviceInfo_GetChannelForIndex N_DeviceInfo_GetChannelForIndex_Impl
# define N_DeviceInfo_GetNrChannelsInChannelMask N_DeviceInfo_GetNrChannelsInChannelMask_Impl
# define N_DeviceInfo_GetChannelMask N_DeviceInfo_GetChannelMask_Impl
# define N_DeviceInfo_IsChannelInMask N_DeviceInfo_IsChannelInMask_Impl
# define N_DeviceInfo_GetIEEEAddress N_DeviceInfo_GetIEEEAddress_Impl
# define N_DeviceInfo_IsAddressAssignmentCapable N_DeviceInfo_IsAddressAssignmentCapable_Impl
# define N_DeviceInfo_GetTouchlinkZerodBmTransmitPower N_DeviceInfo_GetTouchlinkZerodBmTransmitPower_Impl
# define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_GetTrustCenterMode_Impl
# define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_GetPrimaryChannelMask_Impl
# define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_GetSecondaryChannelMask_Impl

# define N_PacketDistributor_GetTotalGroupCount N_PacketDistributor_GetTotalGroupCount_Impl

# define N_Security_GetTransactionId N_Security_GetTransactionId_Impl
# define N_Security_GetKeyBitMask N_Security_GetKeyBitMask_Impl
# define N_Security_GetResponseId N_Security_GetResponseId_Impl
# define N_Security_FindSharedKeyIndex N_Security_FindSharedKeyIndex_Impl
# define N_Security_IsCompatibleWithKeyMask N_Security_IsCompatibleWithKeyMask_Impl
# define N_Security_EncryptNetworkKey N_Security_EncryptNetworkKey_Impl
# define N_Security_GenerateNewNetworkKey N_Security_GenerateNewNetworkKey_Impl
# define N_Security_DecryptNetworkKey N_Security_DecryptNetworkKey_Impl

# define N_Timer_Start16 N_Timer_Start16_Impl

# define N_Zdp_ClientSubscribe N_Zdp_ClientSubscribe_Impl
# define N_Zdp_SendNwkAddrReq N_Zdp_SendNwkAddrReq_Impl
# define N_Zdp_SendIeeeAddrReq N_Zdp_SendIeeeAddrReq_Impl
# define N_Zdp_SendNodeDescReq N_Zdp_SendNodeDescReq_Impl

# define N_Radio_SetTxPower N_Radio_SetTxPower_Impl
# define N_Radio_GetTxPower N_Radio_GetTxPower_Impl

# define N_Util_Random N_Util_Random_Impl

# define N_Timer_Stop N_Timer_Stop_Impl

#endif

#endif /*N_LINKINITIATOR_BINDINGS_H*/
