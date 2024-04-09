/*******************************************************************************
  ZLL Reconnect Handler Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_ReconnectHandler_Bindings.h

  Summary:
    This file contains the ZLL Reconnect Handler Bindings functions.

  Description:
    This file contains the ZLL Reconnect Handler Bindings functions.
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


// used interfaces
#if defined(TESTHARNESS)
// ...bind to stubs...

// N_Connection
#define N_Connection_ReconnectHandler_Subscribe N_Connection_Stub_ReconnectHandler_Subscribe
#define N_Connection_ReconnectHandler_NetworkDiscovery N_Connection_Stub_ReconnectHandler_NetworkDiscovery
#define N_Connection_ReconnectHandler_Rejoin N_Connection_Stub_ReconnectHandler_Rejoin
#define N_Connection_ReconnectHandler_ReconnectDone N_Connection_Stub_ReconnectHandler_ReconnectDone
#define N_Connection_ReconnectHandler_UnsecureRejoin N_Connection_Stub_ReconnectHandler_UnsecureRejoin

// N_DeviceInfo
#define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_Stub_GetPrimaryChannelMask
#define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_Stub_GetSecondaryChannelMask
#define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_Stub_GetNetworkChannel
#define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_Stub_GetNetworkExtendedPanId
#define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_Stub_GetNetworkUpdateId
#define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_Stub_GetTrustCenterMode

#else
// ...bind to implementation...

// N_Connection
#define N_Connection_ReconnectHandler_Subscribe N_Connection_ReconnectHandler_Subscribe_Impl
#define N_Connection_ReconnectHandler_NetworkDiscovery N_Connection_ReconnectHandler_NetworkDiscovery_Impl
#define N_Connection_ReconnectHandler_Rejoin N_Connection_ReconnectHandler_Rejoin_Impl
#define N_Connection_ReconnectHandler_ReconnectDone N_Connection_ReconnectHandler_ReconnectDone_Impl
#define N_Connection_ReconnectHandler_UnsecureRejoin N_Connection_ReconnectHandler_UnsecureRejoin_Impl

// N_DeviceInfo
#define N_DeviceInfo_GetPrimaryChannelMask N_DeviceInfo_GetPrimaryChannelMask_Impl
#define N_DeviceInfo_GetSecondaryChannelMask N_DeviceInfo_GetSecondaryChannelMask_Impl
#define N_DeviceInfo_GetNetworkChannel N_DeviceInfo_GetNetworkChannel_Impl
#define N_DeviceInfo_GetNetworkExtendedPanId N_DeviceInfo_GetNetworkExtendedPanId_Impl
#define N_DeviceInfo_GetNetworkUpdateId N_DeviceInfo_GetNetworkUpdateId_Impl
#define N_DeviceInfo_GetTrustCenterMode N_DeviceInfo_GetTrustCenterMode_Impl

#endif
