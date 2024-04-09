/*******************************************************************************
  Zigbee Device object Unpack Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ZDO_Unpack.c

  Summary:
    Unpack the ZDO requests and calls corresponding ZDO API.

  Description:
    Unpack the ZDO requests and calls corresponding ZDO API.
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
#include <z3device/stack_interface/zdo/include/ZDO_Unpack.h>
#include <z3device/stack_interface/zgb_api.h>
#include <zdo/include/zdo.h>
#include <zdo/include/private/zdoDbg.h>
#include <zdo/include/private/zdoMem.h>
#include <zdo/include/private/zdoPowerManager.h>
/******************************************************************************
                    Definitions section
*******************************************************************************/
void ZDO_ResetNetworkConf_CB (void *resp);
void ZDO_MgmtNwkUpdateNotf_CB(void *resp);
void ZDO_WakeUpInd_CB(void *resp);
void ZDO_BindIndication_CB(void *resp);
void ZDO_UnbindIndication_CB(void *resp);

ZDO_CALLBACK_ptr ZB_ZDO_CallBack[ZDO_APP_CALLBACK_MAX] =
{
  ZDO_ResetNetworkConf_CB,
  ZDO_MgmtNwkUpdateNotf_CB,
  ZDO_WakeUpInd_CB,
  ZDO_BindIndication_CB,
  ZDO_UnbindIndication_CB,
};

void ZDO_ZdpReq_Unpack(void *req)
{
  ZDO_ZdpReq_t *zdpReq = (ZDO_ZdpReq_t *)req;
  ZDO_ZdpReq(zdpReq);
}

void ZDO_FindShortByExt_Unpack(void *req)
{
  ZDO_FindShortByExt_t *findShortByExt = (ZDO_FindShortByExt_t *)req;
  findShortByExt->ret = ZDO_FindShortByExt(findShortByExt->extAddr);
}

void ZDO_FindExtByShort_Unpack(void *req)
{
  ZDO_FindExtByShort_t *findExtByShort = (ZDO_FindExtByShort_t *)req;
  findExtByShort->ret = ZDO_FindExtByShort(findExtByShort->shortAddr);
}

void ZDO_GetPreconfiguredStatus_Unpack(void *req)
{
  bool ret = 0;
  ret = ZDO_GetPreconfiguredStatus();
  *((bool*) req) = ret;
}

void ZDO_VerifyKeyReq_Unpack(void *req)
{
  ZDO_VerifiKeyReq_t *zdoVerifyKeyReq = (ZDO_VerifiKeyReq_t *)req;
  ZDO_VerifyKeyReq(zdoVerifyKeyReq);
}

void ZDO_StartNetworkReq_Unpack(void *req)
{
  ZDO_StartNetworkReq_t *startNetwork = (ZDO_StartNetworkReq_t *)req;
  ZDO_StartNetworkReq(startNetwork);
}

void ZDO_WakeUpReq_Unpack(void *req)
{
  ZDO_WakeUpReq_t *wakeUpReq = (ZDO_WakeUpReq_t *)req;
  ZDO_WakeUpReq(wakeUpReq);
}

#ifdef _ENDDEVICE_
void ZDO_StartSyncReq_Unpack(void *req)
{
  ZDO_Status_t *status = (ZDO_Status_t *)req;
  *status = ZDO_StartSyncReq();
}

void ZDO_StopSyncReq_Unpack(void *req)
{
  ZDO_Status_t status;
  status = ZDO_StopSyncReq();
  *((ZDO_Status_t *)req) = status;
}
#endif //_ENDDEVICE_

void ZDO_ResetNetworkReq_Unpack(void *req)
{
  ZDO_ResetNetworkReq_t *resetReq = (ZDO_ResetNetworkReq_t *)req;
  ZDO_ResetNetworkReq(resetReq);
}

void ZDO_GetNwkStatus_Unpack(void *req)
{
  ZDO_NwkStatus_t status;
  status = ZDO_GetNwkStatus();
  *((ZDO_NwkStatus_t *)req) = status;
}

void ZDO_GetLqiRssi_Unpack(void *req)
{
  ZDO_GetLqiRssi_t *lqiRssi = (ZDO_GetLqiRssi_t *)req;
  ZDO_GetLqiRssi(lqiRssi);
}

void ZDO_GetParentAddr_Unpack(void *req)
{
  NodeAddr_t *parentAddr = (NodeAddr_t *)req;
  ZDO_GetParentAddr(parentAddr);
}

void ZDO_GetChildrenAddr_Unpack(void *req)
{
  ZDO_GetChildrenAddr_t *childrenAddr = (ZDO_GetChildrenAddr_t *)req;
  ZDO_GetChildrenAddr(childrenAddr);
}

void ZDO_SetTxPowerReq_Unpack(void *req)
{
  ZDO_SetTxPowerReq_t *setReq = (ZDO_SetTxPowerReq_t *)req;
  ZDO_SetTxPowerReq(setReq);
}

void ZDO_GetNeibAmount_Unpack(void *req)
{
  ZDO_GetNeibAmount_t *amount = (ZDO_GetNeibAmount_t *)req;
  ZDO_GetNeibAmount(amount);
}

void ZDO_GetNeibTable_Unpack(void *req)
{
  ZDO_Neib_t *table = (ZDO_Neib_t *)req;
  ZDO_GetNeibTable(table);
}

void ZDO_IsDeviceReadyToSleep_Unpack(void *req)
{
  bool ret;
  ret = ZDO_IsDeviceReadyToSleep();
  *((bool*) req) = ret;  
}

void ZDO_IncreaseJoinAttemptsAmount_Unpack(void *req)
{
#if defined _ROUTER_ || defined _ENDDEVICE_
  ZdoStartNetwork_t *startNwk = (ZdoStartNetwork_t *)req;
  ZDO_IncreaseJoinAttemptsAmount(startNwk->joinAttempts);
#endif
}

void ZDO_GetNodeDescriptor_Unpack(void *req)
{
   ZDO_NodeDescriptor_t *nodeDesc = (ZDO_NodeDescriptor_t *)req;
   nodeDesc->ret = ZDO_GetNodeDescriptor();
}

ZB_AppGenericCallbackParam_t cbParams;
extern ZB_AppGenericCallBack fnAppGenericCB;

/***********************************************************************************
  Stub for ZDO_ResetNetwork

  Parameters:
    bindInd - indication

  Return:
    none

 ***********************************************************************************/
void ZDO_ResetNetworkConf(ZDO_ResetNetworkConf_t *conf)
{
  sysAssert(ZDO_SUCCESS_STATUS == conf->status, ZDOINIT_ZDOINITRESETNETWORKCONF_0);

  cbParams.eModuleID = ZIGBEE_ZDO;
  cbParams.uCallBackID = ZDO_ResetNwkConf_ID;
  cbParams.parameters = (void *)conf;
  cbParams.paramSize = sizeof(ZDO_ResetNetworkConf_t);
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&cbParams);
}

/***********************************************************************************
  Stub for ZDO Binding Indication

  Parameters:
    bindInd - indication

  Return:
    none

 ***********************************************************************************/
void ZDO_BindIndication(ZDO_BindInd_t *bindInd)
{ 
  cbParams.eModuleID = ZIGBEE_ZDO;
  cbParams.uCallBackID = ZDO_BindIndication_ID;
  cbParams.parameters = (void *)bindInd;
  cbParams.paramSize = sizeof(ZDO_BindInd_t);
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&cbParams);
}

/***********************************************************************************
  Stub for ZDO Unbinding Indication

  Parameters:
    unbindInd - indication

  Return:
    none

 ***********************************************************************************/
void ZDO_UnbindIndication(ZDO_UnbindInd_t *unbindInd)
{
  cbParams.eModuleID = ZIGBEE_ZDO;
  cbParams.uCallBackID = ZDO_UnbindIndication_ID;
  cbParams.parameters = (void *)unbindInd;
  cbParams.paramSize = sizeof(ZDO_UnbindInd_t);
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&cbParams);
}

/*******************************************************************************
  Description: just a stub.

  Parameters: are not used.

  Returns: nothing.
*******************************************************************************/
void ZDO_MgmtNwkUpdateNotf(ZDO_MgmtNwkUpdateNotf_t *nwkParams)
{ 
  cbParams.eModuleID = ZIGBEE_ZDO;
  cbParams.uCallBackID = ZDO_MgmtNwkUpdateNotf_ID;
  cbParams.parameters = (void *)nwkParams;
  cbParams.paramSize = sizeof(ZDO_MgmtNwkUpdateNotf_t);
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&cbParams);
}


/*******************************************************************************
  Description: just a stub.

  Parameters: none.

  Returns: nothing.
*******************************************************************************/
void ZDO_WakeUpInd(void)
{
  cbParams.eModuleID = ZIGBEE_ZDO;
  cbParams.uCallBackID = ZDO_WakeUpInd_ID;
  cbParams.parameters = (void *)NULL;
  cbParams.paramSize = 0;
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&cbParams);
}
