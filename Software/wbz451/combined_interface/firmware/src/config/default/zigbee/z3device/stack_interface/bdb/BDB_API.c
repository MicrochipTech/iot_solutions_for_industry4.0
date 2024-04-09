/*******************************************************************************
 Zigbee BDB APIs source File

  Company:
    Microchip Technology Inc.

  File Name:
    bdb_api.c

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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <framework_defs.h>

#include <z3device/stack_interface/zgb_api.h>
#include <z3device/stack_interface/bdb/include/bdb_api.h>
  
/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Global variables section
******************************************************************************/
DECLARE_QUEUE(appBdbEventsubscribersQueue);
static Stack_API_Request_t apiRequest;
/*******************************************************************************
                    Static functions section
*******************************************************************************/

/*******************************************************************************
                    Implementation section
*******************************************************************************/
/**************************************************************************//**
\brief BDB_Init pack function
\param[in] initDoneCallback - callback
******************************************************************************/
void ZB_BDB_Init(BDB_InitDone_t initDoneCallback)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_Init_Unpack;
  apiRequest.parameters = initDoneCallback;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_InvokeCommissioning pack function
\param[in] req - Req parameters
******************************************************************************/
void ZB_BDB_InvokeCommissioning(BDB_InvokeCommissioningReq_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_InvokeCommissioning_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_GetBdbNodeIsOnANetwork pack function
\return bool - true if the device is on network, false - otherwise
******************************************************************************/
bool ZB_BDB_GetBdbNodeIsOnANetwork(void)
{
  bool ret = 0;
  apiRequest.unpack_fn = (unpack_ptr)BDB_GetBdbNodeIsOnANetwork_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief BDB_GetCommissioningCapability pack function
\return BDB_NodeCommissioningCapability_t - commissioning capability
******************************************************************************/
BDB_NodeCommissioningCapability_t ZB_BDB_GetCommissioningCapability(void)
{
  BDB_NodeCommissioningCapability_t comCap;
  apiRequest.unpack_fn = (unpack_ptr)BDB_GetCommissioningCapability_Unpack;
  apiRequest.parameters = &comCap;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);

  return comCap; 
}

/**************************************************************************//**
\brief BDB_SetChannelMask pack function - Sets the channel mask BDB attribute

\param[in] type - type of the channel mask - primary or secondary
\param[in] channelMask - channel mask value to set
******************************************************************************/
void ZB_BDB_SetChannelMask(BDB_ChannelMaskType_t type, uint32_t channelMask)
{
  BDB_SetGetChannelMask_t bdbSetChannelMask;
  bdbSetChannelMask.type = type;
  bdbSetChannelMask.channelMask = channelMask;
  
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetChannelMask_Unpack;
  apiRequest.parameters = &bdbSetChannelMask;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest); 
}

/**************************************************************************//**
\brief BDB_GetChannelMask pack function - Gets the channel mask BDB attribute

\param[in] type - type of the channel mask - primary or secondary
\return channelMask
******************************************************************************/
uint32_t ZB_BDB_GetChannelMask(BDB_ChannelMaskType_t type)
{
  BDB_SetGetChannelMask_t bdbGetChannelMask;
  bdbGetChannelMask.type = type;
  
  apiRequest.unpack_fn = (unpack_ptr)BDB_GetChannelMask_Unpack;
  apiRequest.parameters = &bdbGetChannelMask;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest); ;
  return bdbGetChannelMask.channelMask;
}

/**************************************************************************//**
\brief BDB_SetTCLKRetryMaxAttempts pack function

\param[in] attempts - number of max retry attempts
******************************************************************************/
void ZB_BDB_SetTCLKRetryMaxAttempts(uint8_t attempts)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetTCLKRetryMaxAttempts_Unpack;
  apiRequest.parameters = &attempts;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest); 

}

/**************************************************************************//**
\brief BDB_SetTCLKExchangeMethod pack function

\param[in] attempts - number of max retry attempts
******************************************************************************/
void ZB_BDB_SetTCLKExchangeMethod(uint8_t exchangeMethod)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetTCLKExchangeMethod_Unpack;
  apiRequest.parameters = &exchangeMethod;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_ResetToFactoryNew pack function - BDB reset via local action

\param[in] leaveNetwork - leave network before resetting to FN
******************************************************************************/
void ZB_BDB_ResetToFactoryNew(bool leaveNetwork)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_ResetToFactoryNew_Unpack;
  apiRequest.parameters = &leaveNetwork;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_ConfigureInstallCode Pack function - API to configure Install Code
 This API calculates the CRC for the install code and compare with the given CRC
 Derives the link key using SSP AES and sets the key in APS Key Pair Set

\param[in] deviceAddress - set to 0xffffffff in device or ext addr of the joining device
\param[in] installCode - pointer which holds the install code to be derived
\param[in] pfCallback - callback function to be called once the operation is finished
******************************************************************************/
void ZB_BDB_ConfigureInstallCode(ExtAddr_t deviceAddress, uint8_t *installCode, IcStatusCallback_t pfCallback)
{
  BDB_ConfigureInstallCode_t bdbConfigureInstallCode;
  memcpy((uint8_t*)&bdbConfigureInstallCode.deviceAddress,  (uint8_t*)&deviceAddress, sizeof(ExtAddr_t));
  bdbConfigureInstallCode.installCode = installCode;
  bdbConfigureInstallCode.pfCallback = pfCallback;

  apiRequest.unpack_fn = (unpack_ptr)BDB_ConfigureInstallCode_Unpack;
  apiRequest.parameters = &bdbConfigureInstallCode;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
/**************************************************************************//**
\brief BDB_SetInstallCodeUsage pack function  - Sets the install code usage at the trust center

\param[in] useInstallCode - if it is true, TC will allow only install code devices to join
******************************************************************************/
void ZB_BDB_SetInstallCodeUsage(bool useInstallCode)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetInstallCodeUsage_Unpack;
  apiRequest.parameters = &useInstallCode;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}
#endif

/**************************************************************************//**
\brief BDB_EventsSubscribe pack function - BDB Events Subscription handler.
    \param Subscription parameters
******************************************************************************/
void ZB_BDB_EventsSubscribe(const BdbEventSubscriber_t* bdbEventsubscriber)
{
  if (!isQueueElem(&appBdbEventsubscribersQueue, bdbEventsubscriber))
    if(!putQueueElem(&appBdbEventsubscribersQueue, (void*)bdbEventsubscriber))
    {
      //SYS_E_ASSERT_ERROR(false, BDB_EVENTS_QUEUE_NOT_ALLOCATED);
    }

  apiRequest.unpack_fn = (unpack_ptr)BDB_EventsSubscribe_Unpack;
  apiRequest.parameters = (void *)bdbEventsubscriber;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);

}
/**************************************************************************//**
\brief BDB_SetNodeJoinTimeout pack function 
Used to set the bdbTrustCenterNodeJoinTimeout in seconds for the Trust Center
to remove the Trust Center link key of the newly joined node that did not successfully establish a new link key.

\param[in] timeOutInSec - timeout in seconds
******************************************************************************/
void ZB_BDB_SetNodeJoinTimeout(uint8_t timeOutInSec)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetNodeJoinTimeout_Unpack;
  apiRequest.parameters = &timeOutInSec;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_SetTCRequireKeyExchange pack function 
Sets the Trust center Require key change or not of the joining device
\param[in] requireKeyExchange - true or false
******************************************************************************/
void ZB_BDB_SetTCRequireKeyExchange (bool requireKeyExchange)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetTCRequireKeyExchange_Unpack;
  apiRequest.parameters = &requireKeyExchange;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}


#if BDB_TOUCHLINK_SUPPORT == 1  
/**************************************************************************//**
\brief BDB_SetAllowTLResetToFN pack function 
       BDB set the device to allow to accept TL reset to FN

\param[in] allow - true - allows resettofn, false-does not allow
******************************************************************************/
void ZB_BDB_SetAllowTLResetToFN(bool allow)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetAllowTLResetToFN_Unpack;
  apiRequest.parameters = &allow;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_SetTargetType pack function - Sets target type for device

\param[in] req - request parameters
******************************************************************************/

void ZB_BDB_SetTargetType(BDB_SetTargetType_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetTargetType_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);

}
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1

/**************************************************************************//**
\brief Sets the Touchlink role

\param[in] initiator - true is initiator , false means target
******************************************************************************/
void ZB_BDB_SetToulinkRole(bool initiator)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_SetToulinkRole_Unpack;
  apiRequest.parameters = &initiator;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief BDB_ResetVia_TouchlinkCluster pack function
       Resets the target device to factory defaults using touchlink commissioning cluster

\param[in] pfcallback - callback to be called with status once the request is complete
******************************************************************************/
void ZB_BDB_ResetVia_TouchlinkCluster(ResetTargetCallback_t pfcallback)
{
  apiRequest.unpack_fn = (unpack_ptr)BDB_ResetVia_TouchlinkCluster_Unpack;
  apiRequest.parameters = pfcallback;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

#endif //BDB_TOUCHLINK_SUPPORT == 1  
#endif //BDB_TOUCHLINK_INITIATOR_SUPPORT == 1

/**************************************************************************//**
\brief BDB event callbacks
       All BDB events are called via this call back from stack to app. 
       Based on the application subscription corresponding call back is called.

\param[in] cb - callback paramters structure with moduleId, callback Id & callback params 
******************************************************************************/

void ZB_BDB_CallBack(ZB_AppGenericCallbackParam_t* cb)
{
  switch (cb->uCallBackID)
  {
    case BDB_Connected_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, connected);
      break;
    case BDB_Event_Disconnected_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, disconnected);
      break;
    case BDB_Event_IdentifyStartIndication_ID:
    {
       uint16_t argument = *((uint16_t*)cb->parameters);
       RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_SINGLE_ARGUMENT(appBdbEventsubscribersQueue, identifyStartIndication);
    }
    break;
    case BDB_Event_IdentifyStopIndication_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, identifyStopIndication);
      break;
    case BDB_Event_UpdateNetworkIndication_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, updateNetworkIndication);
      break;
    case BDB_Event_QeryingCompleted_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, queryingCompleted);
      break;
    case BDB_Event_JoinNetworkIndication_ID:
    {
      BDB_JoinNwkCbParam_t* bdbTwoArguments = (BDB_JoinNwkCbParam_t*)(cb->parameters);
      uint16_t groupIdFirst =  bdbTwoArguments->groupIdFirst;
      uint16_t groupIdLast = bdbTwoArguments->groupIdLast;
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_TWO_ARGUMENTS(appBdbEventsubscribersQueue, joinNetworkIndication);
    }
    break;
    case BDB_Event_TouchlinkCompleted_ID:
    {
      BDB_CommissioningStatus_t argument = *((BDB_CommissioningStatus_t*)cb->parameters);
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_SINGLE_ARGUMENT(appBdbEventsubscribersQueue, touchlinkCompleted);
    }
    break;

    case BDB_Event_NetworkFormationCompleted_ID:
    {
      BDB_CommissioningStatus_t argument = *((BDB_CommissioningStatus_t*)cb->parameters);
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_SINGLE_ARGUMENT(appBdbEventsubscribersQueue, networkFormationCompleted);
    }
    break;
    case BDB_Event_NetworkSteeringCompleted_ID:
    {
      BDB_CommissioningStatus_t argument = *((BDB_CommissioningStatus_t*)cb->parameters);
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_SINGLE_ARGUMENT(appBdbEventsubscribersQueue, SteeringCompleted);
    }
    break;
    case BDB_Event_FindingBindingCompleted_ID:
    {
      BDB_CommissioningStatus_t argument = *((BDB_CommissioningStatus_t*)cb->parameters);
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_SINGLE_ARGUMENT(appBdbEventsubscribersQueue, findingBindingCompleted);
    }
    break;
    case BDB_Event_ResetToFactoryDefaults_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, ResetToFactoryDefaults);
      break;
    case BDB_Event_TclkProcedureOngoing_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, tclkProcedureOngoing);
      break;
    case BDB_Event_TclkProcedureCompleted_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, tclkProcedureCompleted);
      break;
    case BDB_Event_AddingBindingLinks_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, addingBindingLinks);
      break;
    case BDB_Event_Querying_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, querying);
      break;
    case BDB_Event_Scanning_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, scanning);
      break;
    case BDB_Event_Identifying_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, identifying);
      break;
    case BDB_Event_Joining_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, joining);
      break;
    case BDB_Event_ScanIndication_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, scanIndication);
      break;
    case BDB_Event_SteeringNetwork_ID:
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, SteeringNetwork);
      break;
    case BDB_Event_FindingBindingInitiatorModeCompleted_ID:
#if ZB_COMMISSIONING_ON_STARTUP == 1
      RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(appBdbEventsubscribersQueue, findingBindingInitiatorModeCompleted);
#endif
      break;
      case BDB_CommissioningConfCallback_ID:
      {
        BDB_CommissioningConfCB_t *bdbConfCb = (BDB_CommissioningConfCB_t*)(cb->parameters);
        if (bdbConfCb->callbackFn)
          bdbConfCb->callbackFn(bdbConfCb->confirm);
      }
      break;
    default:
      break;
  }
}

