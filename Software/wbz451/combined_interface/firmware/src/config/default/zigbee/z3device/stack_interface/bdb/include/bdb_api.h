/*******************************************************************************
 Zigbee BDB APIs Header File

  Company:
    Microchip Technology Inc.

  File Name:
    bdb_api.h

  Summary:
    This file contains the Base device Behaviour Api's for this project.

  Description:
    This file contains the packing Base device Behaviour requests and send them to zigbee stack through SVC
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

#ifndef _BDB_API_H
#define _BDB_API_H
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <bdb/include/bdb.h>
#include <bdb/include/bdbInstallCode.h>
#include <z3device/stack_interface/bdb/include/BDB_Unpack.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/
#ifdef _PIC32CX_
#define BDB_Init                       ZB_BDB_Init
#define BDB_InvokeCommissioning        ZB_BDB_InvokeCommissioning
#define BDB_GetBdbNodeIsOnANetwork     ZB_BDB_GetBdbNodeIsOnANetwork
#define BDB_GetCommissioningCapability ZB_BDB_GetCommissioningCapability
#define BDB_SetChannelMask             ZB_BDB_SetChannelMask
#define BDB_GetChannelMask             ZB_BDB_GetChannelMask
#define BDB_SetTargetType              ZB_BDB_SetTargetType
#define BDB_SetTCLKRetryMaxAttempts    ZB_BDB_SetTCLKRetryMaxAttempts
#define BDB_SetTCLKExchangeMethod      ZB_BDB_SetTCLKExchangeMethod
#define BDB_ResetVia_TouchlinkCluster  ZB_BDB_ResetVia_TouchlinkCluster
#define BDB_ResetToFactoryNew          ZB_BDB_ResetToFactoryNew
#define BDB_ConfigureInstallCode       ZB_BDB_ConfigureInstallCode
#define BDB_SetInstallCodeUsage        ZB_BDB_SetInstallCodeUsage
#define BDB_EventsSubscribe            ZB_BDB_EventsSubscribe
#define BDB_SetNodeJoinTimeout         ZB_BDB_SetNodeJoinTimeout
#define BDB_SetTCRequireKeyExchange    ZB_BDB_SetTCRequireKeyExchange
#define BDB_SetToulinkRole             ZB_BDB_SetToulinkRole
#define BDB_SetAllowTLResetToFN        ZB_BDB_SetAllowTLResetToFN
#endif
/*******************************************************************************
                    Global variables section
*******************************************************************************/

/******************************************************************************
                    Protoypes section
******************************************************************************/
/**************************************************************************//**
\brief BDB_Init pack function
\param[in] initDoneCallback - callback
******************************************************************************/
void ZB_BDB_Init(BDB_InitDone_t initDoneCallback);

/**************************************************************************//**
\brief BDB_InvokeCommissioning pack function
\param[in] req - Req parameters
******************************************************************************/
void ZB_BDB_InvokeCommissioning(BDB_InvokeCommissioningReq_t *req);

/**************************************************************************//**
\brief BDB_GetBdbNodeIsOnANetwork pack function
\return bool - true if the device is on network, false - otherwise
******************************************************************************/
bool ZB_BDB_GetBdbNodeIsOnANetwork(void);

/**************************************************************************//**
\brief BDB_GetCommissioningCapability pack function
\return BDB_NodeCommissioningCapability_t - commissioning capability
******************************************************************************/
BDB_NodeCommissioningCapability_t ZB_BDB_GetCommissioningCapability(void);

/**************************************************************************//**
\brief BDB_SetChannelMask pack function - Sets the channel mask BDB attribute

\param[in] type - type of the channel mask - primary or secondary
\param[in] channelMask - channel mask value to set
******************************************************************************/
void ZB_BDB_SetChannelMask(BDB_ChannelMaskType_t type, uint32_t channelMask);

/**************************************************************************//**
\brief BDB_SetTargetType pack function - Sets target type for device

\param[in] req - request parameters
******************************************************************************/
void ZB_BDB_SetTargetType(BDB_SetTargetType_t *req);

/**************************************************************************//**
\brief BDB_GetChannelMask pack function - Gets the channel mask BDB attribute

\param[in] type - type of the channel mask - primary or secondary
\return channelMask
******************************************************************************/
uint32_t ZB_BDB_GetChannelMask(BDB_ChannelMaskType_t type);

/**************************************************************************//**
\brief BDB_SetTCLKRetryMaxAttempts pack function

\param[in] attempts - number of max retry attempts
******************************************************************************/
void ZB_BDB_SetTCLKRetryMaxAttempts(uint8_t attempts);

/**************************************************************************//**
\brief BDB_SetTCLKExchangeMethod pack function

\param[in] attempts - number of max retry attempts
******************************************************************************/
void ZB_BDB_SetTCLKExchangeMethod(uint8_t exchangeMethod);

/**************************************************************************//**
\brief BDB_ResetVia_TouchlinkCluster pack function
       Resets the target device to factory defaults using touchlink commissioning cluster

\param[in] pfcallback - callback to be called with status once the request is complete
******************************************************************************/
void ZB_BDB_ResetVia_TouchlinkCluster(ResetTargetCallback_t pfcallback);

/**************************************************************************//**
\brief BDB_ResetToFactoryNew pack function - BDB reset via local action

\param[in] leaveNetwork - leave network before resetting to FN
******************************************************************************/
void ZB_BDB_ResetToFactoryNew(bool leaveNetwork);

/**************************************************************************//**
\brief BDB_ConfigureInstallCode Pack function - API to configure Install Code
 This API calculates the CRC for the install code and compare with the given CRC
 Derives the link key using SSP AES and sets the key in APS Key Pair Set

\param[in] deviceAddress - set to 0xffffffff in device or ext addr of the joining device
\param[in] installCode - pointer which holds the install code to be derived
\param[in] pfCallback - callback function to be called once the operation is finished
******************************************************************************/
void ZB_BDB_ConfigureInstallCode(ExtAddr_t deviceAddress, uint8_t *installCode, IcStatusCallback_t pfCallback);

#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
/**************************************************************************//**
\brief BDB_SetInstallCodeUsage pack function  - Sets the install code usage at the trust center

\param[in] useInstallCode - if it is true, TC will allow only install code devices to join
******************************************************************************/
void ZB_BDB_SetInstallCodeUsage(bool useInstallCode);
#endif

/**************************************************************************//**
\brief BDB_EventsSubscribe pack function - BDB Events Subscription handler.
    \param Subscription parameters
******************************************************************************/
void ZB_BDB_EventsSubscribe(const BdbEventSubscriber_t* bdbEventsubscriber);

/**************************************************************************//**
\brief BDB_SetNodeJoinTimeout pack function 
Used to set the bdbTrustCenterNodeJoinTimeout in seconds for the Trust Center
to remove the Trust Center link key of the newly joined node that did not successfully establish a new link key.

\param[in] timeOutInSec - timeout in seconds
******************************************************************************/
void ZB_BDB_SetNodeJoinTimeout(uint8_t timeOutInSec);

/**************************************************************************//**
\brief BDB_SetTCRequireKeyExchange pack function 
Sets the Trust center Require key change or not of the joining device
\param[in] requireKeyExchange - true or false
******************************************************************************/
void ZB_BDB_SetTCRequireKeyExchange (bool requireKeyExchange);

/**************************************************************************//**
\brief Sets the Touchlink role

\param[in] initiator - true is initiator , false means target
******************************************************************************/
void ZB_BDB_SetToulinkRole(bool initiator);

/**************************************************************************//**
\brief BDB_SetAllowTLResetToFN pack function 
       BDB set the device to allow to accept TL reset to FN

\param[in] allow - true - allows resettofn, false-does not allow
******************************************************************************/
void ZB_BDB_SetAllowTLResetToFN(bool allow);

/**************************************************************************//**
\brief Application callBack function for BDB

\param[in] Callback Pointer
******************************************************************************/
void ZB_BDB_CallBack(ZB_AppGenericCallbackParam_t* cb);
#endif // _BDB_API_H
