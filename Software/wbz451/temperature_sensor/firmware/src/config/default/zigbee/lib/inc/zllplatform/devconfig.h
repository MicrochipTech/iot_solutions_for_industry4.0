/*******************************************************************************
  ZLL Device Configuration Header File

  Company:
    Microchip Technology Inc.

  File Name:
    devconfig.h

  Summary:
    This file contains the ZLL Device Configuration functions.

  Description:
    This file contains the ZLL Device Configuration functions.
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


#ifndef N_DEVCONFIG_H
#define N_DEVCONFIG_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/
#include "ZLL/N_DeviceInfo/include/N_DeviceInfo.h" // for channel defines

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* DEVELOPER DEFINES
***************************************************************************************************/

/** Define to change the channel masks of the device */
//#define DEVCFG_PRIMARY_CHANNELMASK        (ZB_CHANNEL_12)
//#define DEVCFG_SECONDARY_CHANNELMASK      (0u)

/** Define to set a fixed panId */
//#define DEVCFG_FIXED_PANID        (0x1337u)

/** Define to set a fixed extended panId */
//#define DEVCFG_FIXED_EXT_PANID    { 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u }

/** Define to set a fixed network key */
//#define DEVCFG_FIXED_NWK_KEY      { 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 
//                                    0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu, 0x00u }

/** Define to disable the watchdog */
//#define DEVCFG_DISABLE_WATCHDOG

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_DEVCONFIG_H
