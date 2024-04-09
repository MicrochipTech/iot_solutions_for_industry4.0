/*******************************************************************************
  Color Scene Remote Bindings Header file.

  Company:
    Microchip Technology Inc.

  File Name:
    colorSceneRemoteBindings.h

  Summary:
    This file contains Color Scene Remote Bindings functions.

  Description:
    his file contains Color Scene Remote Bindings functions.
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

#ifndef COLORSCENEREMOTEBINDING_H
#define COLORSCENEREMOTEBINDING_H


// N_Connection
#if defined(ZIGBEE_END_DEVICE)
  #define N_Connection_Subscribe N_ConnectionEndDevice_Subscribe_Impl
  #define N_Connection_JoinNetwork N_ConnectionEndDevice_JoinNetwork_Impl
  #define N_Connection_UpdateNetwork N_ConnectionEndDevice_UpdateNetwork_Impl
  #define N_Connection_IsConnected N_ConnectionEndDevice_IsConnected_Impl
  #define N_Connection_Reconnect N_ConnectionEndDevice_Reconnect_Impl
  #define N_Connection_ReconnectUrgent N_ConnectionEndDevice_ReconnectUrgent_Impl
  #define N_Connection_SetInitiatorInterPanModeOn N_ConnectionEndDevice_SetInitiatorInterPanModeOn_Impl
  #define N_Connection_SetInitiatorInterPanModeOff N_ConnectionEndDevice_SetInitiatorInterPanModeOff_Impl
  #define N_Connection_SetTargetInterPanModeOn N_ConnectionEndDevice_SetTargetInterPanModeOn_Impl
  #define N_Connection_SetTargetInterPanModeOff N_ConnectionEndDevice_SetTargetInterPanModeOff_Impl
  #define N_Connection_SetInterPanModeOn N_ConnectionEndDevice_SetInterPanModeOn_Impl
  #define N_Connection_SetInterPanModeOff N_ConnectionEndDevice_SetInterPanModeOff_Impl
  #define N_Connection_SetPollRate N_ConnectionEndDevice_SetPollRate_Impl
  #define N_Connection_ForceNormalPolling N_ConnectionEndDevice_ForceNormalPolling_Impl
  #define N_Connection_FindFreePan N_ConnectionEndDevice_FindFreePan_Impl
  #define N_Connection_SendNetworkLeaveIndication N_ConnectionEndDevice_SendNetworkLeaveIndication_Impl
#else
  #define N_Connection_Subscribe N_ConnectionRouter_Subscribe_Impl
  #define N_Connection_JoinNetwork N_ConnectionRouter_JoinNetwork_Impl
  #define N_Connection_UpdateNetwork N_ConnectionRouter_UpdateNetwork_Impl
  #define N_Connection_IsConnected N_ConnectionRouter_IsConnected_Impl
  #define N_Connection_Reconnect N_ConnectionRouter_Reconnect_Impl
  #define N_Connection_ReconnectUrgent N_ConnectionRouter_ReconnectUrgent_Impl
  #define N_Connection_SetInitiatorInterPanModeOn N_ConnectionRouter_SetInitiatorInterPanModeOn_Impl
  #define N_Connection_SetInitiatorInterPanModeOff N_ConnectionRouter_SetInitiatorInterPanModeOff_Impl
  #define N_Connection_SetTargetInterPanModeOn N_ConnectionRouter_SetTargetInterPanModeOn_Impl
  #define N_Connection_SetTargetInterPanModeOff N_ConnectionRouter_SetTargetInterPanModeOff_Impl
  #define N_Connection_SetInterPanModeOn N_ConnectionRouter_SetInterPanModeOn_Impl
  #define N_Connection_SetInterPanModeOff N_ConnectionRouter_SetInterPanModeOff_Impl
  #define N_Connection_SetPollRate N_ConnectionRouter_SetPollRate_Impl
  #define N_Connection_ForceNormalPolling N_ConnectionRouter_ForceNormalPolling_Impl
  #define N_Connection_FindFreePan N_ConnectionRouter_FindFreePan_Impl
  #define N_Connection_SendNetworkLeaveIndication N_ConnectionRouter_SendNetworkLeaveIndication_Impl
  #define N_Connection_LeaveNetwork N_ConnectionRouter_LeaveNetwork_Impl
  #define N_Connection_ReconnectHandler_Rejoin N_Connection_ReconnectHandler_Rejoin_Impl
#endif

#define N_Connection_AssociateDiscovery N_Connection_AssociateDiscovery_Impl
#define N_Connection_AbortAssociateDiscovery N_Connection_AbortAssociateDiscovery_Impl
#define N_Connection_AssociateJoin N_Connection_AssociateJoin_Impl

#define N_Connection_TargetIsInterpanModeOn N_Connection_TargetIsInterpanModeOn_Impl

// N_DeviceInfo
#define N_DeviceInfo_Subscribe N_DeviceInfo_Subscribe_Impl
#define N_DeviceInfo_GetPlatformVersion N_DeviceInfo_GetPlatformVersion_Impl
#define N_DeviceInfo_GetBuildDateStr N_DeviceInfo_GetBuildDateStr_Impl
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

// N_LinkInitiator
#define N_LinkInitiator_Subscribe N_LinkInitiator_Subscribe_Impl
#define N_LinkInitiator_Scan N_LinkInitiator_Scan_Impl
#define N_LinkInitiator_StopScan N_LinkInitiator_StopScan_Impl
#define N_LinkInitiator_IdentifyStartRequest N_LinkInitiator_IdentifyStartRequest_Impl
#define N_LinkInitiator_IdentifyStopRequest N_LinkInitiator_IdentifyStopRequest_Impl
#define N_LinkInitiator_DeviceInfoRequest N_LinkInitiator_DeviceInfoRequest_Impl
#define N_LinkInitiator_JoinDevice N_LinkInitiator_JoinDevice_Impl
#define N_LinkInitiator_ResetDeviceToFactoryNew N_LinkInitiator_ResetDeviceToFactoryNew_Impl

// N_LinkTarget
#define N_LinkTarget_Subscribe N_LinkTarget_Subscribe_Impl
#define N_LinkTarget_SetTargetType N_LinkTarget_SetTargetType_Impl
#define N_LinkTarget_SetTouchlinkPriority N_LinkTarget_SetTouchlinkPriority_Impl
#define N_LinkTarget_AllowStealing N_LinkTarget_AllowStealing_Impl

// N_Cmi
#  define N_Cmi_Subscribe N_Cmi_Subscribe_Impl
#  define N_Cmi_StartNetworking N_Cmi_StartNetworking_Impl
#  define N_Cmi_StartRouter N_Cmi_StartRouter_Impl
#  define N_Cmi_SetMacChannel N_Cmi_SetMacChannel_Impl
#  define N_Cmi_UpdateNetworkChannel N_Cmi_UpdateNetworkChannel_Impl
#  define N_Cmi_NetworkDiscovery N_Cmi_NetworkDiscovery_Impl
#  define N_Cmi_SendLinkStatus N_Cmi_SendLinkStatus_Impl
#  define N_Cmi_Join N_Cmi_Join_Impl
#  define N_Cmi_ResetNetworkSettings N_Cmi_ResetNetworkSettings_Impl
#  define N_Cmi_GetNetworkParams N_Cmi_GetNetworkParams_Impl
#  define N_Cmi_GetParentInfo N_Cmi_GetParentInfo_Impl
#  define N_Cmi_SwitchNetworkKey N_Cmi_SwitchNetworkKey_Impl
#  define N_Cmi_GetTotalTransmissions N_Cmi_GetTotalTransmissions_Impl
#  define N_Cmi_EnergyDetectScan N_Cmi_EnergyDetectScan_Impl
#  define N_Cmi_SendLeaveIndication N_Cmi_SendLeaveIndication_Impl
#  define N_Cmi_ProcessLeaveIndication N_Cmi_ProcessLeaveIndication_Impl
#  define N_Cmi_SendUpdateDevice N_Cmi_SendUpdateDevice_Impl
#  define N_Cmi_DataRequest N_Cmi_DataRequest_Impl
#  define N_Cmi_SetZllLinkKeyAsPrimary N_Cmi_SetZllLinkKeyAsPrimary_Impl
#  define N_Cmi_UseNwkMulticast N_Cmi_UseNwkMulticast_Impl
#  define N_Cmi_InitMacLayer N_Cmi_InitMacLayer_Impl
#  define N_Cmi_SetPollRateForTimePeriod N_Cmi_SetPollRateForTimePeriod_Impl

// S_Nv
#  define S_Nv_EraseAll S_Nv_EraseAll_Impl

//N_Zdp
#define N_Zdp_SendMgmtPermitJoiningReq N_Zdp_SendMgmtPermitJoiningReq_Impl
#define N_Zdp_SendMgmtNwkUpdateReq N_Zdp_SendMgmtNwkUpdateReq_Impl
#define N_Zdp_SendMgmtBindReq N_Zdp_SendMgmtBindReq_Impl

// N_PacketDistributor
#define N_PacketDistributor_RegisterEndpoint N_PacketDistributor_RegisterEndpoint_Impl

//N_Hac
#define N_Hac_RegisterEndpoint N_Hac_RegisterEndpoint_Impl

// IN_AfDataRequest
#if defined(ZIGBEE_END_DEVICE)
  #  define IN_AfDataRequest_DataRequest N_EndDeviceRobustness_DataRequest_Impl
#else
  #  define IN_AfDataRequest_DataRequest N_Cmi_DataRequest_Impl
#endif /* ZIGBEE_END_DEVICE */

// N_EndDeviceRobustness
#define N_EndDeviceRobustness_DataRequest N_EndDeviceRobustness_DataRequest_Impl

#endif /*COLORSCENEREMOTEBINDING_H*/

