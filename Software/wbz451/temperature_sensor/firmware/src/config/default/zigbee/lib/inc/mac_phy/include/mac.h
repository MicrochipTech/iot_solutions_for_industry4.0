/*******************************************************************************
  MAC Header File

  Company:
    Microchip Technology Inc.

  File Name:
    mac.h

  Summary:
    IEEE 802.15.4-2006 public headers files' union.

  Description:
    This file contains the IEEE 802.15.4-2006 public headers files' union.
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

#ifndef _MAC_H
#define _MAC_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/phy.h>
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macAffix.h>
#include <mac_phy/include/macAssociate.h>
#include <mac_phy/include/macBeacon.h>
#include <mac_phy/include/macCommon.h>
#include <mac_phy/include/macData.h>
#include <mac_phy/include/macDisassociate.h>
#include <mac_phy/include/macOrphan.h>
#include <mac_phy/include/macPoll.h>
#include <mac_phy/include/macPurge.h>
#include <mac_phy/include/macReset.h>
#include <mac_phy/include/macRxEnable.h>
#include <mac_phy/include/macScan.h>
#include <mac_phy/include/macSetGet.h>
#include <mac_phy/include/macStart.h>
#include <mac_phy/include/macSync.h>
#ifdef _MAC_HW_AES_
#include <mac_phy/include/rfEncrypt.h>
#endif
#include <mac_phy/include/rfBattery.h>
#include <mac_phy/include/rfRandom.h>
#include <mac_phy/include/rfCalibration.h>
#include <mac_phy/include/rfRegAccess.h>
#include <mac_phy/include/macBanNode.h>
#include <mac_phy/mac_env/include/macenvPib.h>
#include <mac_phy/include/macEnvironment.h>

#endif //_MAC_H

// eof mac.h
