/*******************************************************************************
  Base Device Behavior Unpack Header file

  Company:
    Microchip Technology Inc.

  File Name:
    BDB_Unpack.h

  Summary:
    Unpack the BDB requests and calls corresponding BDB API..

  Description:
    This file contains declaration for BDB Unpack requests and calls corresponding BDB API..
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


#ifndef _BDB_UNPACK_H_
#define _BDB_UNPACK_H_
/*******************************************************************************
                             Includes section
*******************************************************************************/
#include <framework_defs.h>
#include <z3device/stack_interface/zgb_api.h>
#include <bdb/include/bdb.h>
#include <bdb/include/bdbInstallCode.h>
#include <bdb/include/bdbTouchlink.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
/*************************************************************************//**
  \brief BDB_SetChannelMask() API parameters
*****************************************************************************/
typedef struct _BDB_SetChannelMask
{
  BDB_ChannelMaskType_t type;
  uint32_t channelMask;
} BDB_SetGetChannelMask_t;

/*************************************************************************//**
  \brief BDB_ConfigureInstallCode() API parameters
*****************************************************************************/
typedef struct _BDB_ConfigureInstallCode
{
  ExtAddr_t deviceAddress;
  uint8_t *installCode;
  IcStatusCallback_t pfCallback;
} BDB_ConfigureInstallCode_t;


/*************************************************************************//**
  \brief BDB two argument callback structure
**************************************************************************/
typedef struct _BDB_JoinNwkCbParam
{
  uint16_t groupIdFirst;
  uint16_t groupIdLast;
} BDB_JoinNwkCbParam_t;

/*******************************************************************************
                    Global variables section
*******************************************************************************/

/******************************************************************************
                    Protoypes section
******************************************************************************/
/**************************************************************************//**
\brief BDB_Init Unpack function
\param[in] req - request
******************************************************************************/
void BDB_Init_Unpack(void *req);

/**************************************************************************//**
\brief BDB_InvokeCommissioning Unpack function
\param[in] req - request
******************************************************************************/
void BDB_InvokeCommissioning_Unpack(void *req);

/**************************************************************************//**
\brief BDB_GetBdbNodeIsOnANetwork Unpack function
\param[in] req - request
******************************************************************************/
void BDB_GetBdbNodeIsOnANetwork_Unpack(void *req);

/**************************************************************************//**
\brief BDB_GetCommissioningCapability Unpack function
\param[in] req - request
******************************************************************************/
void BDB_GetCommissioningCapability_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetChannelMask Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetChannelMask_Unpack(void *req);

/**************************************************************************//**
\brief BDB_GetChannelMask Unpack function
\param[in] req - request
******************************************************************************/
void BDB_GetChannelMask_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetTargetType Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTargetType_Unpack(void *req);
/**************************************************************************//**
\brief BDB_SetTCLKRetryMaxAttempts Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTCLKRetryMaxAttempts_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetTCLKExchangeMethod Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTCLKExchangeMethod_Unpack(void *req);

/**************************************************************************//**
\brief BDB_ResetToFactoryNew Unpack function
\param[in] req - request
******************************************************************************/
void BDB_ResetToFactoryNew_Unpack(void *req);

/**************************************************************************//**
\brief BDB_ConfigureInstallCode Unpack function
\param[in] req - request
******************************************************************************/
void BDB_ConfigureInstallCode_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetInstallCodeUsage Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetInstallCodeUsage_Unpack(void *req);

/**************************************************************************//**
\brief BDB_EventsSubscribe Unpack function
\param[in] req - request
******************************************************************************/
void BDB_EventsSubscribe_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetNodeJoinTimeout Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetNodeJoinTimeout_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetTCRequireKeyExchange Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTCRequireKeyExchange_Unpack(void *req);



#if BDB_TOUCHLINK_SUPPORT == 1
/**************************************************************************//**
\brief BDB_SetAllowTLResetToFN Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetAllowTLResetToFN_Unpack(void *req);

#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1

/**************************************************************************//**
\brief BDB_SetToulinkRole Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetToulinkRole_Unpack(void *req);

/**************************************************************************//**
\brief BDB_SetTCLKExchangeMethod Unpack function
\param[in] req - request
******************************************************************************/
void BDB_ResetVia_TouchlinkCluster_Unpack(void *req);

#endif //BDB_TOUCHLINK_SUPPORT == 1
#endif //BDB_TOUCHLINK_INITIATOR_SUPPORT == 1

/**************************************************************************//**
\brief BDB Connected callback function
\param[in] void
******************************************************************************/
void bdbEvent_Connected(void);

/**************************************************************************//**
\brief BDB Disconnected callback function
\param[in] void
******************************************************************************/
void bdbEvent_Disconnected(void);

/**************************************************************************//**
\brief BDB IdentifyStartIndication callback function
\param[in] uValue - identify duration
******************************************************************************/
void bdbEvent_IdentifyStartIndication (uint16_t uValue);

/**************************************************************************//**
\brief BDB IdentifyStopIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_IdentifyStopIndication(void);

/**************************************************************************//**
\brief BDB UpdateNetworkIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_UpdateNetworkIndication(void);

/**************************************************************************//**
\brief BDB bdbEvent_QeryingCompleted callback function
\param[in] void
******************************************************************************/
void bdbEvent_QeryingCompleted(void);

/**************************************************************************//**
\brief BDB JoinNetworkIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_JoinNetworkIndication(uint16_t groupIdFirst, uint16_t groupIdLast);

/**************************************************************************//**
\brief BDB TouchlinkCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_TouchlinkCompleted(BDB_CommissioningStatus_t status);

/**************************************************************************//**
\brief BDB NetworkFormationCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_NetworkFormationCompleted(BDB_CommissioningStatus_t status);

/**************************************************************************//**
\brief BDB NetworkSteeringCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_NetworkSteeringCompleted(BDB_CommissioningStatus_t status);

/**************************************************************************//**
\brief BDB FindingBindingCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_FindingBindingCompleted(BDB_CommissioningStatus_t status);

/**************************************************************************//**
\brief BDB ResetToFactoryDefaults callback function
\param[in] void
******************************************************************************/
void bdbEvent_ResetToFactoryDefaults(void);

/**************************************************************************//**
\brief BDB Querying callback function
\param[in] void
******************************************************************************/
void bdbEvent_Querying(void);

/**************************************************************************//**
\brief BDB Scanning callback function
\param[in] void
******************************************************************************/
void bdbEvent_Scanning(void);

/**************************************************************************//**
\brief BDB Identifying callback function
\param[in] void
******************************************************************************/
void bdbEvent_Identifying(void);

/**************************************************************************//**
\brief BDB Joining callback function
\param[in] void
******************************************************************************/
void bdbEvent_Joining(void);

/**************************************************************************//**
\brief BDB ScanIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_ScanIndication(void);

/**************************************************************************//**
\brief BDB SteeringNetwork callback function
\param[in] void
******************************************************************************/
void bdbEvent_SteeringNetwork(void);

/**************************************************************************//**
\brief BDB TclkProcedureOngoing callback function
\param[in] void
******************************************************************************/
void bdbEvent_TclkProcedureOngoing(void);

/**************************************************************************//**
\brief BDB TclkProcedureCompleted callback function
\param[in] void
******************************************************************************/
void bdbEvent_TclkProcedureCompleted(void);

/**************************************************************************//**
\brief BDB AddingBindingLinks callback function
\param[in] void
******************************************************************************/
void bdbEvent_AddingBindingLinks(void);

/**************************************************************************//**
\brief BDB FindingBindingInitiatorModeCompleted callback function
\param[in] void
******************************************************************************/
void bdbEvent_FindingBindingInitiatorModeCompleted(void);


#endif
/* eof */







