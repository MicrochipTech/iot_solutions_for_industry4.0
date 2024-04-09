// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Config Server Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkConfigServer.h

  Summary:
    This file contains the data types necessary for building of the ConfigServer.

  Description:
    This file contains the data types necessary for building of the Network ConfigServer.
 *******************************************************************************/

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

#if !defined _NWK_CONFIG_SERVER_H
#define _NWK_CONFIG_SERVER_H

/******************************************************************************
                               Definitions section
 ******************************************************************************/
#ifndef NWK_PRIVATE
  #define NWK_PRIVATE
#endif /* #ifndef NWK_PRIVATE */

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkTx.h>
#include <nwk/include/private/nwkPacket.h>
#include <nwk/include/private/nwkJoinInd.h>
#include <nwk/include/private/nwkRoutingTable.h>
#include <nwk/include/private/nwkRouteDiscoveryTable.h>
#include <nwk/include/private/nwkRouteDiscovery.h>
#include <nwk/include/private/nwkAddressMap.h>
#include <nwk/include/private/nwkBTT.h>
#include <nwk/include/private/nwkRouteCache.h>
#include <nwk/include/nwkGroup.h>
#include <nwk/include/private/nwkIB.h>
#include <nwk/include/private/nwkPassiveAck.h>
#include <nwk/include/nwkSecurity.h>
#include <nwk/include/private/nwkEndDeviceTimeoutInd.h>

#endif /* _NWK_CONFIG_SERVER_H */
/** eof nwkConfigServer.h */

