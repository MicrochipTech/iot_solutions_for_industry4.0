/*******************************************************************************
  ZLL Inter Pan Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_InterPan_Bindings.h

  Summary:
    This file contains the ZLL Inter Pan Bindings functions.

  Description:
    This file contains the ZLL Inter Pan Bindings functions.
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

// implemented interface
#define N_InterPan_Subscribe N_InterPan_Subscribe_Impl
#define N_InterPan_BroadcastScanRequest N_InterPan_BroadcastScanRequest_Impl
#define N_InterPan_UnicastScanRequest N_InterPan_UnicastScanRequest_Impl
#define N_InterPan_SendScanResponse N_InterPan_SendScanResponse_Impl
#define N_InterPan_SendDeviceInfoRequest N_InterPan_SendDeviceInfoRequest_Impl
#define N_InterPan_SendDeviceInfoResponse N_InterPan_SendDeviceInfoResponse_Impl
#define N_InterPan_SendIdentifyRequest N_InterPan_SendIdentifyRequest_Impl
#define N_InterPan_SendNetworkStartRequest N_InterPan_SendNetworkStartRequest_Impl
#define N_InterPan_SendNetworkStartResponse N_InterPan_SendNetworkStartResponse_Impl
#define N_InterPan_SendNetworkJoinRouterRequest N_InterPan_SendNetworkJoinRouterRequest_Impl
#define N_InterPan_SendNetworkJoinRouterResponse N_InterPan_SendNetworkJoinRouterResponse_Impl
#define N_InterPan_SendNetworkJoinEndDeviceRequest N_InterPan_SendNetworkJoinEndDeviceRequest_Impl
#define N_InterPan_SendNetworkJoinEndDeviceResponse N_InterPan_SendNetworkJoinEndDeviceResponse_Impl
#define N_InterPan_SendNetworkUpdateRequest N_InterPan_SendNetworkUpdateRequest_Impl
#define N_InterPan_SendResetToFactoryNewRequest N_InterPan_SendResetToFactoryNewRequest_Impl
#define N_InterPan_SendInterPanCommand N_InterPan_SendInterPanCommand_Impl

#if defined(TESTHARNESS)
// N_Zcl_DataRequest
#  define N_Zcl_DataRequest N_Zcl_DataRequest_Stub_DataRequest

// N_Zcl_DataInd
#  define N_Zcl_DataInd_Subscribe N_Zcl_DataInd_Stub_Subscribe

// N_PacketDistributor
#  define N_PacketDistributor_FindEndpoint N_PacketDistributor_Stub_FindEndpoint
#  define N_PacketDistributor_IsInterPan N_PacketDistributor_Stub_IsInterPan

#else
// N_Zcl_DataRequest
#if defined(ZIGBEE_END_DEVICE)
  #  define N_Zcl_DataRequest N_EndDeviceRobustness_DataRequest_Impl
#else
  #  define N_Zcl_DataRequest N_Cmi_DataRequest_Impl
#endif /* ZIGBEE_END_DEVICE */

// N_ZCL_DataInd
#  define N_Zcl_DataInd_Subscribe N_PacketDistributor_Subscribe_Impl

// N_PacketDistributor
#  define N_PacketDistributor_FindEndpoint N_PacketDistributor_FindEndpoint_Impl
#  define N_PacketDistributor_IsInterPan N_PacketDistributor_IsInterPan_Impl

#endif
