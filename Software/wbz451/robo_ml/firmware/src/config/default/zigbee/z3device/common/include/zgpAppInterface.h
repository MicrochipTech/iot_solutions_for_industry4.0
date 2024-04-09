/*******************************************************************************
  Zigbee Green Power Application Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zgpAppInterface.h

  Summary:
    This file contains the Zigbee Green Power Application interface

  Description:
    This file contains the Zigbee Green Power Application interface
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

#ifndef _ZGPAPPINTERFACE_H
#define _ZGPAPPINTERFACE_H

#ifdef _GREENPOWER_SUPPORT_
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC

#include <zgp/GPInfrastructure/highZgp/include/zgpInfraDevice.h>

/**************************************************************************//**
Defines Section
******************************************************************************/
#define ZCL_IDENTIFY_PAYLOAD 0x003C
#define ZCL_COLOR_CONTROL_STOP_PAYLOAD 0x0000

#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#ifndef ZGP_DISABLE_TRANSLATION_TABLE
/**************************************************************************//**
Initialized the sink translation table
******************************************************************************/
void ZGP_TransTableInit(bool resetToFN);
#endif
#endif

/**************************************************************************//**
  \brief To initialize ZGP application and core ZGP

  \param[in] resetToFN - status of resetting to factory new

  \return none
******************************************************************************/
void ZGP_AppInit(void);

#endif //// #if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#endif // _GREENPOWER_SUPPORT_
#endif //_ZGPAPPINTERFACE_H
