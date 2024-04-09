/*******************************************************************************
 Zigbee ZDO APIs source File

  Company:
    Microchip Technology Inc.

  File Name:
    zdo_api.c

  Summary:
    This file contains the Zigbee device object Api's for this project.

  Description:
    This file contains the packing Zigbee device object requests and send them to zigbee stack through SVC
	
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
#include <z3device/stack_interface/zdo/include/zdo_api.h>
#include <z3device/stack_interface/zdo/include/ZDO_Unpack.h>
#include <zdo/include/zdo.h>

/*******************************************************************************
                    Global variables section
*******************************************************************************/
static Stack_API_Request_t apiRequest;

/*******************************************************************************
                    Implementation section
*******************************************************************************/
void ZB_ZDO_ZdpReq(ZDO_ZdpReq_t *zdpReq)
{
  
  apiRequest.unpack_fn = (unpack_ptr)ZDO_ZdpReq_Unpack;
  apiRequest.parameters = zdpReq;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

const ShortAddr_t* ZB_ZDO_FindShortByExt(const ExtAddr_t *const extAddr)
{ 
  ZDO_FindShortByExt_t findShortByExt;
  findShortByExt.extAddr = extAddr;
  
  apiRequest.unpack_fn = (unpack_ptr)ZDO_FindShortByExt_Unpack;
  apiRequest.parameters = &findShortByExt;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return findShortByExt.ret;
}

const ExtAddr_t* ZB_ZDO_FindExtByShort(const ShortAddr_t shortAddr)
{
  ZDO_FindExtByShort_t findExtByShort;
  findExtByShort.shortAddr = shortAddr;
  
  apiRequest.unpack_fn = (unpack_ptr)ZDO_FindExtByShort_Unpack;
  apiRequest.parameters = &findExtByShort;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return findExtByShort.ret;
}

uint8_t ZB_ZDO_GetPreconfiguredStatus(void)
{
  uint8_t ret = 0;

  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetPreconfiguredStatus_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

void ZB_ZDO_VerifyKeyReq(ZDO_VerifiKeyReq_t *zdoVerifyKeyReq)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_VerifyKeyReq_Unpack;
  apiRequest.parameters = zdoVerifyKeyReq;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_StartNetworkReq(ZDO_StartNetworkReq_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_StartNetworkReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_WakeUpReq(ZDO_WakeUpReq_t * req)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_WakeUpReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

#ifdef _ENDDEVICE_
ZDO_Status_t ZB_ZDO_StartSyncReq(void)
{
  ZDO_Status_t status;

  apiRequest.unpack_fn = (unpack_ptr)ZDO_StartSyncReq_Unpack;
  apiRequest.parameters = &status;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return status;
}

ZDO_Status_t ZB_ZDO_StopSyncReq(void)
{
  ZDO_Status_t status;

  apiRequest.unpack_fn = (unpack_ptr)ZDO_StopSyncReq_Unpack;
  apiRequest.parameters = &status;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return status;
}
#endif //_ENDDEVICE_

void ZB_ZDO_ResetNetworkReq(ZDO_ResetNetworkReq_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_ResetNetworkReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

ZDO_NwkStatus_t ZB_ZDO_GetNwkStatus(void)
{
  ZDO_NwkStatus_t status;

  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetNwkStatus_Unpack;
  apiRequest.parameters = &status;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return status;
}

void ZB_ZDO_GetLqiRssi(ZDO_GetLqiRssi_t *lqiRssi)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetLqiRssi_Unpack;
  apiRequest.parameters = lqiRssi;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_GetParentAddr(NodeAddr_t *parentAddr)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetParentAddr_Unpack;
  apiRequest.parameters = parentAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_GetChildrenAddr(ZDO_GetChildrenAddr_t *childrenAddr)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetChildrenAddr_Unpack;
  apiRequest.parameters = childrenAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_SetTxPowerReq(ZDO_SetTxPowerReq_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_SetTxPowerReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_GetNeibAmount(ZDO_GetNeibAmount_t *amount)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetNeibAmount_Unpack;
  apiRequest.parameters = amount;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

void ZB_ZDO_GetNeibTable(ZDO_Neib_t *table)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetNeibTable_Unpack;
  apiRequest.parameters = table;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

bool ZB_ZDO_IsDeviceReadyToSleep(void)
{
  bool ret = 0;
  apiRequest.unpack_fn = (unpack_ptr)ZDO_IsDeviceReadyToSleep_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

#if defined(_ROUTER_) || defined(_ENDDEVICE_)
void ZB_ZDO_IncreaseJoinAttemptsAmount(uint8_t amount)
{
  apiRequest.unpack_fn = (unpack_ptr)ZDO_IncreaseJoinAttemptsAmount_Unpack;
  apiRequest.parameters = &amount;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}
#endif /* defined(_ROUTER_) || defined(_ENDDEVICE_) */

const NodeDescriptor_t* ZB_ZDO_GetNodeDescriptor(void)
{
  ZDO_NodeDescriptor_t nodeDesc;
  apiRequest.unpack_fn = (unpack_ptr)ZDO_GetNodeDescriptor_Unpack;
  apiRequest.parameters = &nodeDesc;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return nodeDesc.ret;
}
