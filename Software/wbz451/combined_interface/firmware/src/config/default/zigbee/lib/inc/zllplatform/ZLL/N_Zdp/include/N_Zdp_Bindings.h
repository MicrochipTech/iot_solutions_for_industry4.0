/*******************************************************************************
  ZLL ZDP Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Zdp_Bindings.h

  Summary:
    This file contains the ZLL ZDP Bindings functions.

  Description:
    This file contains the ZLL ZDP Bindings functions.
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


// N_Cmi
#define N_Cmi_PlatformToBcAddressingConvert N_Cmi_PlatformToBcAddressingConvert_Impl
#define N_Cmi_PlatformToBcAddressModeConvert N_Cmi_PlatformToBcAddressModeConvert_Impl

#if defined (ZIGBEE_ROUTER) || defined (ZIGBEE_COORDINATOR)
  #define N_Zdp_RouterZdpRequest    N_Cmi_ZdpRequest_Impl
#endif
#if defined(ZIGBEE_END_DEVICE)
  #define N_Zdp_EnddeviceZdpRequest    N_EndDeviceRobustness_ZdpRequest_Impl
  //#define N_Zdp_ZdpRequest    N_Cmi_ZdpRequest_Impl
#endif /* ZIGBEE_END_DEVICE */

#define N_Cmi_ZdpRequest N_Cmi_ZdpRequest_Impl
#define N_EndDeviceRobustness_ZdpRequest N_EndDeviceRobustness_ZdpRequest_Impl
