/*******************************************************************************
  ZLL ZCL Framework Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Zcl_Framework_Bindings.h

  Summary:
    This file contains the ZLL ZCL Framework Bindings functions.

  Description:
    This file contains the ZLL ZCL Framework Bindings functions.
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


#define N_Zcl_Framework_RegisterFoundationCommand N_Zcl_Framework_RegisterFoundationCommand_Impl
#define N_Zcl_Framework_RegisterCluster N_Zcl_Framework_RegisterCluster_Impl
#define N_Zcl_Framework_AddSubscriber N_Zcl_Framework_AddSubscriber_Impl
#define N_Zcl_Framework_FindSubscriber N_Zcl_Framework_FindSubscriber_Impl
#define N_Zcl_Framework_EnableZclEndpoint N_Zcl_Framework_EnableZclEndpoint_Impl
#define N_Zcl_Framework_GetNextSequenceNumber N_Zcl_Framework_GetNextSequenceNumber_Impl
#define N_Zcl_Framework_SendCommand N_Zcl_Framework_SendCommand_Impl
#define N_Zcl_Framework_SendClusterSpecificRequest N_Zcl_Framework_SendClusterSpecificRequest_Impl
#define N_Zcl_Framework_SendRequest N_Zcl_Framework_SendRequest_Impl
#define N_Zcl_Framework_SendCommandTxOptions N_Zcl_Framework_SendCommandTxOptions_Impl
#define N_Zcl_Framework_SendClusterSpecificResponse N_Zcl_Framework_SendClusterSpecificResponse_Impl
#define N_Zcl_Framework_GetSourceAddress N_Zcl_Framework_GetSourceAddress_Impl
#define N_Zcl_Framework_GetDestinationEndpoint N_Zcl_Framework_GetDestinationEndpoint_Impl
#define N_Zcl_Framework_GetReceivedSequenceNumber N_Zcl_Framework_GetReceivedSequenceNumber_Impl
#define N_Zcl_Framework_GetSentSequenceNumber N_Zcl_Framework_GetSentSequenceNumber_Impl
#define N_Zcl_Framework_ReceivedAsUnicast N_Zcl_Framework_ReceivedAsUnicast_Impl
#define N_Zcl_Framework_Subscribe N_Zcl_Framework_Subscribe_Impl
#define N_Zcl_Framework_IsReceivedDirectionClientSide N_Zcl_Framework_IsReceivedDirectionClientSide_Impl
#define N_Zcl_Framework_GetIncomingData N_Zcl_Framework_GetIncomingData_Impl
#define N_Zcl_Framework_GetDestinationAddress N_Zcl_Framework_GetDestinationAddress_Impl

// used interfaces
#if defined(TESTHARNESS)

   // N_Zcl_DataRequest
#  define N_Zcl_DataRequest N_Zcl_DataRequest_Stub_DataRequest

   // N_Zcl_DataInd
#  define N_Zcl_DataInd_Subscribe N_Zcl_DataInd_Stub_Subscribe  

   // N_PacketDistributor
#  define N_PacketDistributor_FindEndpoint N_PacketDistributor_Stub_FindEndpoint

#else

#  if defined(DISABLE_BINDING_AND_LOCAL_LOOPBACK)


#    if defined(ZIGBEE_END_DEVICE)
//#      define N_Zcl_DataRequest N_EndDeviceRobustness_DataRequest_Impl
#    else
//#      define N_Zcl_DataRequest N_ChannelChecker_DataRequest_Impl
#    endif

#  endif

#  if defined(ZIGBEE_END_DEVICE)
#    define N_Zcl_DataRequest N_EndDeviceRobustness_DataRequest_Impl
#  else
#    define N_Zcl_DataRequest N_Cmi_DataRequest_Impl
#  endif
   // N_Zcl_DataInd
#  define N_Zcl_DataInd_Subscribe N_PacketDistributor_Subscribe_Impl
   // N_PacketDistributor
#  define N_PacketDistributor_FindEndpoint N_PacketDistributor_FindEndpoint_Impl

   // N_Cmi
#  define N_Cmi_PlatformToBcAddressingConvert N_Cmi_PlatformToBcAddressingConvert_Impl
#  define N_Cmi_PlatformToBcAddressModeConvert N_Cmi_PlatformToBcAddressModeConvert_Impl

   // N_Binding
#  define N_Binding_FindBinding N_Binding_FindBinding_Impl

#endif

