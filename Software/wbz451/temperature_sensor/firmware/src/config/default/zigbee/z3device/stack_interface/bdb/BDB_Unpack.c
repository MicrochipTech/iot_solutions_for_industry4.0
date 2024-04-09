/*******************************************************************************
  Base Device Behavior Unpack Source file

  Company:
    Microchip Technology Inc.

  File Name:
    BDB_Unpack.c

  Summary:
    Unpack the BDB requests and calls corresponding BDB API.

  Description:
    Unpack the BDB requests and calls corresponding BDB API.
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

/*******************************************************************************
                             Includes section
*******************************************************************************/
#include <z3device/stack_interface/bdb/include/BDB_Unpack.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/

/*******************************************************************************
                    Global variables section
*******************************************************************************/
static ZB_AppGenericCallbackParam_t cbParams;
extern ZB_AppGenericCallBack fnAppGenericCB;

//callbacks
BdbEventSubscriber_t s_BDB_EventsLocalCallback =
{
  .connected = bdbEvent_Connected,
  .disconnected = bdbEvent_Disconnected,
  .identifyStartIndication = bdbEvent_IdentifyStartIndication,
  .identifyStopIndication = bdbEvent_IdentifyStopIndication,
  .updateNetworkIndication = bdbEvent_UpdateNetworkIndication,
  .queryingCompleted = bdbEvent_QeryingCompleted,
  .joinNetworkIndication = bdbEvent_JoinNetworkIndication,
  .SteeringNetwork = bdbEvent_SteeringNetwork,
  .tclkProcedureOngoing = bdbEvent_TclkProcedureOngoing,
  .tclkProcedureCompleted = bdbEvent_TclkProcedureCompleted,
  .addingBindingLinks = bdbEvent_AddingBindingLinks,
  .scanIndication = bdbEvent_ScanIndication,
  .touchlinkCompleted = bdbEvent_TouchlinkCompleted,
  .networkFormationCompleted = bdbEvent_NetworkFormationCompleted,
  .SteeringCompleted = bdbEvent_NetworkSteeringCompleted,
  .findingBindingCompleted = bdbEvent_FindingBindingCompleted,
  .ResetToFactoryDefaults = bdbEvent_ResetToFactoryDefaults,
  .querying = bdbEvent_Querying,  
  .scanning = bdbEvent_Scanning,
  .identifying = bdbEvent_Identifying,
  .joining = bdbEvent_Joining,
#if ZB_COMMISSIONING_ON_STARTUP == 1
  .findingBindingInitiatorModeCompleted = bdbEvent_FindingBindingInitiatorModeCompleted,
#endif  /* ZB_COMMISSIONING_ON_STARTUP == 1 */
};



/*******************************************************************************
                    Implementation section
*******************************************************************************/

/**************************************************************************//**
\brief BDB_Init Unpack function
\param[in] req - request
******************************************************************************/
void BDB_Init_Unpack(void *req)
{
  BDB_InitDone_t initCompleted = (BDB_InitDone_t)req;
  BDB_Init(initCompleted);
}

/**************************************************************************//**
\brief BDB_InvokeCommissioning Unpack function
\param[in] req - request
******************************************************************************/
void BDB_InvokeCommissioning_Unpack(void *req)
{
  BDB_InvokeCommissioningReq_t *invokeCommReq = (BDB_InvokeCommissioningReq_t*)req;
  BDB_InvokeCommissioning(invokeCommReq);
}

/**************************************************************************//**
\brief BDB_GetBdbNodeIsOnANetwork Unpack function
\param[in] req - request
******************************************************************************/
void BDB_GetBdbNodeIsOnANetwork_Unpack(void *req)
{
  bool retVal;
  retVal = BDB_GetBdbNodeIsOnANetwork();
  *((bool*) req) = retVal;  
}

/**************************************************************************//**
\brief BDB_GetCommissioningCapability Unpack function
\param[in] req - request
******************************************************************************/
void BDB_GetCommissioningCapability_Unpack(void *req)
{
  BDB_NodeCommissioningCapability_t comCapability;
  comCapability = BDB_GetCommissioningCapability();
  *((BDB_NodeCommissioningCapability_t*) req) = comCapability;
}

/**************************************************************************//**
\brief BDB_SetChannelMask Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetChannelMask_Unpack(void *req)
{
  BDB_SetGetChannelMask_t *bdbSetChannelMask =  (BDB_SetGetChannelMask_t* )req;
  BDB_SetChannelMask(bdbSetChannelMask->type, bdbSetChannelMask->channelMask);
}

/**************************************************************************//**
\brief BDB_GetChannelMask Unpack function
\param[in] req - request
******************************************************************************/
void BDB_GetChannelMask_Unpack(void *req)
{
  BDB_SetGetChannelMask_t *bdbGetChannelMask =  (BDB_SetGetChannelMask_t* )req;
  bdbGetChannelMask->channelMask = BDB_GetChannelMask(bdbGetChannelMask->type);
}

/**************************************************************************//**
\brief BDB_SetTCLKRetryMaxAttempts Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTCLKRetryMaxAttempts_Unpack(void *req)
{
#if defined ZIGBEE_ROUTER || defined ZIGBEE_END_DEVICE
  BDB_SetTCLKRetryMaxAttempts(*((uint8_t *)req));
#endif
}

/**************************************************************************//**
\brief BDB_SetTCLKExchangeMethod Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTCLKExchangeMethod_Unpack(void *req)
{
#if defined ZIGBEE_ROUTER || defined ZIGBEE_END_DEVICE
  BDB_SetTCLKExchangeMethod(*((uint8_t *)req));
#endif
}

/**************************************************************************//**
\brief BDB_ResetToFactoryNew Unpack function
\param[in] req - request
******************************************************************************/
void BDB_ResetToFactoryNew_Unpack(void *req)
{
  BDB_ResetToFactoryNew(*((bool *)req));
}

/**************************************************************************//**
\brief BDB_ConfigureInstallCode Unpack function
\param[in] req - request
******************************************************************************/
void BDB_ConfigureInstallCode_Unpack(void *req)
{
  BDB_ConfigureInstallCode_t* bdbConfigureInstallCode = (BDB_ConfigureInstallCode_t* )req;
  BDB_ConfigureInstallCode(bdbConfigureInstallCode->deviceAddress, bdbConfigureInstallCode->installCode, bdbConfigureInstallCode->pfCallback);
}

/**************************************************************************//**
\brief BDB_SetInstallCodeUsage Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetInstallCodeUsage_Unpack(void *req)
{
  BDB_SetInstallCodeUsage(*((bool *)req));
}

/**************************************************************************//**
\brief BDB_EventsSubscribe Unpack function
\param[in] req - request
******************************************************************************/
void BDB_EventsSubscribe_Unpack(void *req)
{
  (void)req;
  //subscribe to local callbacks.On receiving callback call callback subscribed by app
  BDB_EventsSubscribe(&s_BDB_EventsLocalCallback);
}

/**************************************************************************//**
\brief BDB_SetNodeJoinTimeout Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetNodeJoinTimeout_Unpack(void *req)
{
  BDB_SetNodeJoinTimeout(*((uint8_t *)req));
}

/**************************************************************************//**
\brief BDB_SetTCRequireKeyExchange Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTCRequireKeyExchange_Unpack(void *req)
{
  BDB_SetTCRequireKeyExchange(*((bool *)req));
}

#if BDB_TOUCHLINK_SUPPORT == 1
/**************************************************************************//**
\brief BDB_SetAllowTLResetToFN Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetAllowTLResetToFN_Unpack(void *req)
{
  BDB_SetAllowTLResetToFN(*((bool *)req));
}

/**************************************************************************//**
\brief BDB_SetTargetType Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetTargetType_Unpack(void *req)
{
  BDB_SetTargetType_t *bdbSetTargetType = (BDB_SetTargetType_t *)req;
  BDB_SetTargetType(bdbSetTargetType);
}
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
/**************************************************************************//**
\brief BDB_SetToulinkRole Unpack function
\param[in] req - request
******************************************************************************/
void BDB_SetToulinkRole_Unpack(void *req)
{
  BDB_SetToulinkRole(*((bool *)req));
}

/**************************************************************************//**
\brief BDB_SetTCLKExchangeMethod Unpack function
\param[in] req - request
******************************************************************************/
void BDB_ResetVia_TouchlinkCluster_Unpack(void *req)
{
  BDB_ResetVia_TouchlinkCluster((ResetTargetCallback_t)req);
}
#endif //#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
#endif //#if BDB_TOUCHLINK_SUPPORT == 1


/* Application Callbacks*/

/**************************************************************************//**
\brief BDB Connected callback function
\param[in] void
******************************************************************************/
void bdbEvent_Connected(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Connected_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB Disconnected callback function
\param[in] void
******************************************************************************/
void bdbEvent_Disconnected(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_Disconnected_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB IdentifyStartIndication callback function
\param[in] uValue - identify duration
******************************************************************************/
void bdbEvent_IdentifyStartIndication (uint16_t uValue)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_IdentifyStartIndication_ID;
    cbParams.parameters = (void *)&uValue;
    cbParams.paramSize = sizeof(uValue);
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB IdentifyStopIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_IdentifyStopIndication(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_IdentifyStopIndication_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB UpdateNetworkIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_UpdateNetworkIndication(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_UpdateNetworkIndication_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB bdbEvent_QeryingCompleted callback function
\param[in] void
******************************************************************************/
void bdbEvent_QeryingCompleted(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_QeryingCompleted_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB JoinNetworkIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_JoinNetworkIndication(uint16_t groupIdFirst, uint16_t groupIdLast)
{
  BDB_JoinNwkCbParam_t joinNwkParam;
  joinNwkParam.groupIdFirst = groupIdFirst;
  joinNwkParam.groupIdLast = groupIdLast;

  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_JoinNetworkIndication_ID;
    cbParams.parameters = (void *)&joinNwkParam;
    cbParams.paramSize = sizeof(joinNwkParam);
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB TouchlinkCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_TouchlinkCompleted(BDB_CommissioningStatus_t status)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_TouchlinkCompleted_ID;
    cbParams.parameters = (void *)&status;
    cbParams.paramSize = sizeof(status);
    fnAppGenericCB(&cbParams);
  }
}
/**************************************************************************//**
\brief BDB NetworkFormationCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_NetworkFormationCompleted(BDB_CommissioningStatus_t status)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_NetworkFormationCompleted_ID;
    cbParams.parameters = (void *)&status;
    cbParams.paramSize = sizeof(status);
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB NetworkSteeringCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_NetworkSteeringCompleted(BDB_CommissioningStatus_t status)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_NetworkSteeringCompleted_ID;
    cbParams.parameters = (void *)&status;
    cbParams.paramSize = sizeof(status);
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB FindingBindingCompleted callback function
\param[in] status - Commissioning status
******************************************************************************/
void bdbEvent_FindingBindingCompleted(BDB_CommissioningStatus_t status)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_FindingBindingCompleted_ID;
    cbParams.parameters = (void *)&status;
    cbParams.paramSize = sizeof(status);
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB ResetToFactoryDefaults callback function
\param[in] void
******************************************************************************/
void bdbEvent_ResetToFactoryDefaults(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_ResetToFactoryDefaults_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB Querying callback function
\param[in] void
******************************************************************************/
void bdbEvent_Querying(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_Querying_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB Scanning callback function
\param[in] void
******************************************************************************/
void bdbEvent_Scanning(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_Scanning_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB Identifying callback function
\param[in] void
******************************************************************************/
void bdbEvent_Identifying(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_Identifying_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB Joining callback function
\param[in] void
******************************************************************************/
void bdbEvent_Joining(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_Joining_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB ScanIndication callback function
\param[in] void
******************************************************************************/
void bdbEvent_ScanIndication(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_ScanIndication_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB SteeringNetwork callback function
\param[in] void
******************************************************************************/

void bdbEvent_SteeringNetwork(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_SteeringNetwork_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB TclkProcedureOngoing callback function
\param[in] void
******************************************************************************/
void bdbEvent_TclkProcedureOngoing(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_TclkProcedureOngoing_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }  
}

/**************************************************************************//**
\brief BDB TclkProcedureCompleted callback function
\param[in] void
******************************************************************************/
void bdbEvent_TclkProcedureCompleted(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_TclkProcedureCompleted_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }  
}

/**************************************************************************//**
\brief BDB AddingBindingLinks callback function
\param[in] void
******************************************************************************/
void bdbEvent_AddingBindingLinks(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_AddingBindingLinks_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}

/**************************************************************************//**
\brief BDB FindingBindingInitiatorModeCompleted callback function
\param[in] void
******************************************************************************/
void bdbEvent_FindingBindingInitiatorModeCompleted(void)
{
  if (NULL != fnAppGenericCB)
  {
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_Event_FindingBindingInitiatorModeCompleted_ID;
    cbParams.parameters = (void *)NULL;
    cbParams.paramSize = 0;
    fnAppGenericCB(&cbParams);
  }
}
  
void BDB_InvokeCommissioningConfirm(BDB_InvokeCommissioningConfCallback_t callbackFn, BDB_InvokeCommissioningConf_t *conf)
{
  if (NULL != fnAppGenericCB)
  {
    BDB_CommissioningConfCB_t bdbConfCb;
    bdbConfCb.callbackFn = callbackFn;
    bdbConfCb.confirm = conf;
    cbParams.eModuleID = ZIGBEE_BDB;
    cbParams.uCallBackID = BDB_CommissioningConfCallback_ID;
    cbParams.parameters = (void *)&bdbConfCb;
    cbParams.paramSize = sizeof(BDB_CommissioningConfCB_t);
    fnAppGenericCB(&cbParams);
  }
}
