/*******************************************************************************
  Zigbee NWK APIs source File

  Company:
    Microchip Technology Inc.

  File Name:
    nwk_api.c

  Summary:
    This file contains the Network Api's for this project.

  Description:
    This file contains the packing Network requests and send them to zigbee stack through SVC
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
#include <z3device/stack_interface/nwk/include/nwk_api.h>
#include <z3device/stack_interface/nwk/include/NWK_Unpack.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/
static Stack_API_Request_t apiRequest;
/*******************************************************************************
                    Implementation section
*******************************************************************************/
/**************************************************************************//**
\brief NWK_GroupCapacity pack function
\param[in] req - request
******************************************************************************/
NWK_GroupTableSize_t ZB_NWK_GroupCapacity(void)
{
  NWK_GroupTableSize_t tableSize = 0;  
  
  apiRequest.unpack_fn = (unpack_ptr)NWK_GroupCapacity_Unpack;
  apiRequest.parameters = &tableSize;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  
  return (tableSize);
}

/**************************************************************************//**
\brief NWK_RemoveGroup pack function
\param[in] const NWK_GroupAddr_t addr, const NWK_GroupData_t data
******************************************************************************/
bool ZB_NWK_RemoveGroup(const NWK_GroupAddr_t addr, const NWK_GroupData_t data)
{
  NWK_GroupReq_t nwkRemoveGroup;
  
  nwkRemoveGroup.addr = addr;
  nwkRemoveGroup.data = data;
  
  apiRequest.unpack_fn = (unpack_ptr)NWK_RemoveGroup_Unpack;
  apiRequest.parameters = &nwkRemoveGroup;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (nwkRemoveGroup.status);
}

/**************************************************************************//**
\brief NWK_RemoveAllGroups pack function
\param[in] NWK_GroupData_t 
******************************************************************************/
bool ZB_NWK_RemoveAllGroups(const NWK_GroupData_t data)
{
  NWK_RemoveAllGroups_t removeAllGroup;

  apiRequest.unpack_fn = (unpack_ptr)NWK_RemoveAllGroups_Unpack;
  apiRequest.parameters = &removeAllGroup;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (removeAllGroup.status);
}
/**************************************************************************//**
\brief NWK_NextGroup pack function
\param[in] NWK_GroupTableEntry_t *entry
******************************************************************************/
NWK_GroupTableEntry_t* ZB_NWK_NextGroup(NWK_GroupTableEntry_t *entry)
{
  NWK_NextGroup_t nextGroup;
  nextGroup.currEntry = entry;

  apiRequest.unpack_fn = (unpack_ptr)NWK_NextGroup_Unpack;
  apiRequest.parameters = &nextGroup;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (nextGroup.nextEntry);
}

/**************************************************************************//**
\brief NWK_LeaveReq pack function
\param[in] NWK_LeaveReq_t *req
******************************************************************************/
void ZB_NWK_LeaveReq(NWK_LeaveReq_t *const req)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_LeaveReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief NWK_GetUpdateId pack function
\param[in] None
\ return value: NwkUpdateId_t
******************************************************************************/
NwkUpdateId_t ZB_NWK_GetUpdateId(void)
{
  NwkUpdateId_t nwkId = 0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetUpdateId_Unpack;
  apiRequest.parameters = &nwkId;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (nwkId);
}

/**************************************************************************//**
\brief NWK_GetShortAddr pack function
\param[in] None
\ return value: ShortAddr_t
******************************************************************************/
ShortAddr_t ZB_NWK_GetShortAddr(void)
{
  ShortAddr_t shortAddr = 0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetShortAddr_Unpack;
  apiRequest.parameters = &shortAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (shortAddr);
}

/**************************************************************************//**
\brief NWK_IsGroupMember pack function
\param[in] const NWK_GroupAddr_t addr, const NWK_GroupData_t data
\ return value: Success or Failure
******************************************************************************/
bool ZB_NWK_IsGroupMember(const NWK_GroupAddr_t addr, const NWK_GroupData_t data)
{
  NWK_GroupReq_t groupMember;
  
  groupMember.addr = addr;
  groupMember.data = data;

  apiRequest.unpack_fn = (unpack_ptr)NWK_IsGroupMember_Unpack;
  apiRequest.parameters = &groupMember;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (groupMember.status);
}

/**************************************************************************//**
\brief NWK_AddGroup pack function
\param[in] const NWK_GroupAddr_t addr, const NWK_GroupData_t data
\ return value: Success or Failure
******************************************************************************/
bool ZB_NWK_AddGroup(const NWK_GroupAddr_t addr, const NWK_GroupData_t data)
{
  NWK_GroupReq_t addGroup;
  
  addGroup.addr = addr;
  addGroup.data = data;

  apiRequest.unpack_fn = (unpack_ptr)NWK_AddGroup_Unpack;
  apiRequest.parameters = &addGroup;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (addGroup.status);
}

/**************************************************************************//**
\brief NWK_SetShortAddr pack function
\param[in] const ShortAddr_t shortAddr, const bool silent
\ return value: NWK_Status_t
******************************************************************************/
NWK_Status_t ZB_NWK_SetShortAddr(const ShortAddr_t shortAddr, const bool silent)
{
  NWK_SetShortAddr_t setShortAddr;
  setShortAddr.addr = shortAddr;
  setShortAddr.silent = silent;

  apiRequest.unpack_fn = (unpack_ptr)NWK_SetShortAddr_Unpack;
  apiRequest.parameters = &setShortAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (setShortAddr.status);
}

/**************************************************************************//**
\brief ZB_NWK_GetShortByExtAddress pack function
\param[in] const ExtAddr_t *const extAddr
\ return value: ShortAddr_t*
******************************************************************************/
const ShortAddr_t* ZB_NWK_GetShortByExtAddress(const ExtAddr_t *const extAddr)
{
  NWK_GetShortByExtAddress_t getShortByExtAddr;
  getShortByExtAddr.extAddr = extAddr;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetShortByExtAddress_Unpack;
  apiRequest.parameters = &getShortByExtAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (getShortByExtAddr.addr);
}

/**************************************************************************//**
\brief ZB_NWK_GetExtByShortAddress pack function
\param[in] const ShortAddr_t shortAddr
\ return value: ExtAddr_t*
******************************************************************************/
const ExtAddr_t* ZB_NWK_GetExtByShortAddress(const ShortAddr_t shortAddr)
{
  NWK_GetExtByShortAddress_t getExtByShortAddr;
  getExtByShortAddr.shortAddr = shortAddr;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetExtByShortAddress_Unpack;
  apiRequest.parameters = &getExtByShortAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return (getExtByShortAddr.addr);
}

/**************************************************************************//**
\brief ZB_NWK_ResetGroups pack function
\param[in] None
\ return value: None
******************************************************************************/
void ZB_NWK_ResetGroups(void)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_ResetGroups_Unpack;
  apiRequest.parameters = NULL;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_GetParentInformation pack function
\param[in] None
\ return value: uint16_t
******************************************************************************/
uint16_t ZB_NWK_GetParentInformation(void)
{
  uint16_t ret =0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetParentInformation_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief ZB_NWK_GetParentShortAddr pack function
\param[in] None
\ return value: ShortAddr_t
******************************************************************************/
ShortAddr_t ZB_NWK_GetParentShortAddr(void)
{
  ShortAddr_t addr;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetParentShortAddr_Unpack;
  apiRequest.parameters = &addr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return addr;
}

/**************************************************************************//**
\brief ZB_NWK_GetPanId pack function
\param[in] None
\ return value: PanId_t
******************************************************************************/
PanId_t ZB_NWK_GetPanId(void)
{
  PanId_t id;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetPanId_Unpack;
  apiRequest.parameters = &id;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return id;
}

/**************************************************************************//**
\brief ZB_NWK_SetPanId pack function
\param[in] PanId_t panId
\ return value: None
******************************************************************************/
void ZB_NWK_SetPanId(PanId_t panId)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetPanId_Unpack;
  apiRequest.parameters = &panId;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_GetExtPanId pack function
\param[in] None
\ return value: ExtPanId_t
******************************************************************************/
ExtPanId_t ZB_NWK_GetExtPanId(void)
{
  ExtPanId_t id;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetExtPanId_Unpack;
  apiRequest.parameters = &id;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return id;
}

/**************************************************************************//**
\brief ZB_NWK_SetExtPanId pack function
\param[in] const ExtPanId_t *extPanId
\ return value: None
******************************************************************************/
void ZB_NWK_SetExtPanId(const ExtPanId_t *extPanId)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetExtPanId_Unpack;
  apiRequest.parameters = (void *)extPanId;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_GetDeviceType pack function
\param[in] None
\ return value: DeviceType_t
******************************************************************************/
DeviceType_t ZB_NWK_GetDeviceType(void)
{
  DeviceType_t type;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetDeviceType_Unpack;
  apiRequest.parameters = &type;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return type;
}

/**************************************************************************//**
\brief ZB_NWK_GetLogicalChannel pack function
\param[in] None
\ return value: Channel_t
******************************************************************************/
Channel_t ZB_NWK_GetLogicalChannel(void)
{
  Channel_t channel;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetLogicalChannel_Unpack;
  apiRequest.parameters = &channel;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return channel;
}

/**************************************************************************//**
\brief ZB_NWK_SetLogicalChannel pack function
\param[in] const Channel_t channel
\ return value: none
******************************************************************************/
void ZB_NWK_SetLogicalChannel(const Channel_t channel)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetLogicalChannel_Unpack;
  apiRequest.parameters = (void *)&channel;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_GetBroadcastDeliveryTime pack function
\param[in] none
\ return value: uint32_t
******************************************************************************/
uint32_t ZB_NWK_GetBroadcastDeliveryTime(void)
{
  uint32_t time;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetBroadcastDeliveryTime_Unpack;
  apiRequest.parameters = &time;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return time;
}

/**************************************************************************//**
\brief ZB_NWK_GetManagerAddr pack function
\param[in] none
\ return value: ShortAddr_t
******************************************************************************/
ShortAddr_t ZB_NWK_GetManagerAddr(void)
{
  ShortAddr_t addr;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetManagerAddr_Unpack;
  apiRequest.parameters = &addr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return addr;
}

/**************************************************************************//**
\brief ZB_NWK_SetManagerAddr pack function
\param[in] const ShortAddr_t shortAddr
\ return value: none
******************************************************************************/
void ZB_NWK_SetManagerAddr(const ShortAddr_t shortAddr)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetManagerAddr_Unpack;
  apiRequest.parameters = (void *)&shortAddr;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_SetUpdateId pack function
\param[in] const NwkUpdateId_t updateId
\ return value: none
******************************************************************************/
void ZB_NWK_SetUpdateId(const NwkUpdateId_t updateId)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetUpdateId_Unpack;
  apiRequest.parameters = (void *)&updateId;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_SetSymLink pack function
\param[in] const bool symLink
\ return value: none
******************************************************************************/
void ZB_NWK_SetSymLink(const bool symLink)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetSymLink_Unpack;
  apiRequest.parameters = (void *)&symLink;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_GetProtocolVersion pack function
\param[in] none
\ return value: uint8_t
******************************************************************************/
uint8_t ZB_NWK_GetProtocolVersion(void)
{
  uint8_t ret =0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetProtocolVersion_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief ZB_NWK_GetTransmitCouner pack function
\param[in] none
\ return value: uint16_t
******************************************************************************/
uint16_t ZB_NWK_GetTransmitCouner(void)
{
  uint16_t ret =0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetTransmitCouner_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief ZB_NWK_GetTransmitFailureCounter pack function
\param[in] none
\ return value: uint16_t
******************************************************************************/
uint16_t ZB_NWK_GetTransmitFailureCounter(void)
{
  uint16_t ret =0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetTransmitFailureCounter_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief ZB_NWK_SetPassiveAckThreshold pack function
\param[in] uint8_t thresholdValue
\ return value: none
******************************************************************************/
void ZB_NWK_SetPassiveAckThreshold(uint8_t thresholdValue)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetPassiveAckThreshold_Unpack;
  apiRequest.parameters = &thresholdValue;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_SetRejoinPermit pack function
\param[in] const NWK_RejoinPermit_t permit
\ return value: none
******************************************************************************/
void ZB_NWK_SetRejoinPermit(const NWK_RejoinPermit_t permit)
{
  apiRequest.unpack_fn = (unpack_ptr)NWK_SetRejoinPermit_Unpack;
  apiRequest.parameters = (void *)&permit;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZB_NWK_GetSecurityLevel pack function
\param[in] none
\ return value: uint8_t
******************************************************************************/
uint8_t ZB_NWK_GetSecurityLevel(void)
{
  uint8_t ret = 0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetSecurityLevel_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief ZB_NWK_GetSecureAllFrames pack function
\param[in] none
\ return value: success or failure
******************************************************************************/
bool ZB_NWK_GetSecureAllFrames(void)
{
  bool ret = 0;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetSecureAllFrames_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret;
}

/**************************************************************************//**
\brief ZB_NWK_SetKey pack function
\param[in] const uint8_t *const key, const NWK_KeySeqNum_t keySeqNum
\ return value: success or failure
******************************************************************************/
bool ZB_NWK_SetKey(const uint8_t *const key, const NWK_KeySeqNum_t keySeqNum)
{
  NWK_SetKey_t setKey;
  setKey.key = key;
  setKey.keySeqNum = keySeqNum;

  apiRequest.unpack_fn = (unpack_ptr)NWK_SetKey_Unpack;
  apiRequest.parameters = &setKey;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return setKey.ret; 
}

/**************************************************************************//**
\brief ZB_NWK_GetActiveKeySeqNumber pack function
\param[in] none
\ return value: NWK_KeySeqNum_t
******************************************************************************/
NWK_KeySeqNum_t ZB_NWK_GetActiveKeySeqNumber(void)
{
  NWK_KeySeqNum_t keySumNum;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetActiveKeySeqNumber_Unpack;
  apiRequest.parameters = &keySumNum;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return keySumNum;
}

/**************************************************************************//**
\brief ZB_NWK_GetActiveKey pack function
\param[in] const NWK_KeySeqNum_t keySeqNum
\ return value: success or failure
******************************************************************************/
const uint8_t* ZB_NWK_GetActiveKey(const NWK_KeySeqNum_t keySeqNum)
{
  NWK_ActiveKey_t activeKey;
  activeKey.keySeqNum = keySeqNum;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetActiveKey_Unpack;
  apiRequest.parameters = &activeKey;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return activeKey.ret; 
}
 
/**************************************************************************//**
\brief ZB_NWK_GetUpdatedSecOutCounter pack function
\param[in] none
\ return value: NwkOutFrameCounter_t
******************************************************************************/
NwkOutFrameCounter_t ZB_NWK_GetUpdatedSecOutCounter(void)
{
  NwkOutFrameCounter_t ret;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetUpdatedSecOutCounter_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret; 
}

/**************************************************************************//**
\brief ZB_NWK_GetSecOutCounter pack function
\param[in] none
\ return value: NwkOutFrameCounter_t
******************************************************************************/
NwkOutFrameCounter_t ZB_NWK_GetSecOutCounter(void)
{
  NwkOutFrameCounter_t ret;

  apiRequest.unpack_fn = (unpack_ptr)NWK_GetSecOutCounter_Unpack;
  apiRequest.parameters = &ret;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return ret; 
}

#if defined _RESOLVE_PANID_CONFLICT_
/**************************************************************************//**
\brief ZB_NWK_UpdatePanId pack function
\param[in] const PanId_t newPanId, const NwkUpdateId_t updateId,
  const NwkUpdatePanIdConf_t callback
\ return value: none
******************************************************************************/
void ZB_NWK_UpdatePanId(const PanId_t newPanId, const NwkUpdateId_t updateId,
  const NwkUpdatePanIdConf_t callback)
{
  NWK_UpdatePanId_t updatePanId;
  updatePanId.newPanId = newPanId;
  updatePanId.updateId = updateId;
  updatePanId.callback = callback;

  apiRequest.unpack_fn = (unpack_ptr)NWK_UpdatePanId_Unpack;
  apiRequest.parameters = &updatePanId;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}
#endif

#if defined _CERTIFICATION_
/**************************************************************************//**
\brief ZB_NWK_SetKeyAmount pack function
\param[in] const uint8_t keyAmount)
\ return value: NWK_Status_t
******************************************************************************/
NWK_Status_t ZB_NWK_SetKeyAmount(const uint8_t keyAmount)
{
  NWK_SetKeyAmount_t setKeyAmount;
  setKeyAmount.keyAmount = keyAmount;

  apiRequest.unpack_fn = (unpack_ptr)NWK_SetKeyAmount_Unpack;
  apiRequest.parameters = &setKeyAmount;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return setKeyAmount.status;
}
#endif 