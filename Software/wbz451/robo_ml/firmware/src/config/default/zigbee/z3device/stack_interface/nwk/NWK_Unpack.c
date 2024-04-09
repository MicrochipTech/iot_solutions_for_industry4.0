/*******************************************************************************
  Zigbee Cluster Library Unpack Source File

  Company:
    Microchip Technology Inc.

  File Name:
    NWK_Unpack.c

  Summary:
    Unpack the NWK requests and calls corresponding NWK API.

  Description:
    Unpack the NWK requests and calls corresponding NWK API.
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
#include <z3device/stack_interface/nwk/include/NWK_Unpack.h>
#include <nwk/include/nwkGroup.h>
#include <nwk/include/nwkConfigServer.h>
#include <nwk/include/private/nwkIB.h>
#include <nwk/include/private/nwkUpdateCommand.h>
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

void NWK_GroupCapacity_Unpack (void *req)
{
  NWK_GroupTableSize_t *tableSize = (NWK_GroupTableSize_t *)req;
  
  *tableSize = (NWK_GroupTableSize_t)NWK_GroupCapacity();
  return;
}

void NWK_RemoveGroup_Unpack (void *req)
{
  NWK_GroupReq_t *nwkRemoveGroup = (NWK_GroupReq_t *)req;

  nwkRemoveGroup->status = NWK_RemoveGroup(nwkRemoveGroup->addr,nwkRemoveGroup->data);
  return;
}

void NWK_RemoveAllGroups_Unpack (void *req)
{
  NWK_RemoveAllGroups_t *removeAllGroup = (NWK_RemoveAllGroups_t *)req;

  removeAllGroup->status = NWK_RemoveAllGroups(removeAllGroup->data);
  return;
}

void NWK_NextGroup_Unpack (void *req)
{
  NWK_NextGroup_t *nextGroup = (NWK_NextGroup_t *)req;

  nextGroup->nextEntry = NWK_NextGroup(nextGroup->currEntry);
  return;
}

void NWK_LeaveReq_Unpack (void *req)
{
  NWK_LeaveReq((NWK_LeaveReq_t*)req);
  return;
}

void NWK_GetUpdateId_Unpack (void *req)
{
  NwkUpdateId_t *nwkId = (NwkUpdateId_t *)req;

  *nwkId = NWK_GetUpdateId();
  return;
}

void NWK_GetShortAddr_Unpack (void *req)
{
  ShortAddr_t *shortAddr = (ShortAddr_t*)req;
  *shortAddr =  NWK_GetShortAddr();
  return;
}

void NWK_IsGroupMember_Unpack (void *req)
{
  NWK_GroupReq_t *groupMember = req;

  groupMember->status = NWK_IsGroupMember(groupMember->addr,groupMember->data);
  return;
}

void NWK_AddGroup_Unpack (void *req)
{
  NWK_GroupReq_t *addGroup = req;

  addGroup->status = NWK_AddGroup(addGroup->addr,addGroup->data);
  return;
}

void NWK_SetShortAddr_Unpack (void *req)
{
  NWK_SetShortAddr_t *setShortAddr = (NWK_SetShortAddr_t *)req; 
  setShortAddr->status = NWK_SetShortAddr(setShortAddr->addr, setShortAddr->silent);  
}

void NWK_GetShortByExtAddress_Unpack (void *req)
{
  NWK_GetShortByExtAddress_t *getShortByExtAddr = (NWK_GetShortByExtAddress_t *)req;
  getShortByExtAddr->addr = NWK_GetShortByExtAddress(getShortByExtAddr->extAddr);
}

void NWK_GetExtByShortAddress_Unpack (void *req)
{
  NWK_GetExtByShortAddress_t *getExtByShortAddr = (NWK_GetExtByShortAddress_t *) req;
  getExtByShortAddr->addr = NWK_GetExtByShortAddress(getExtByShortAddr->shortAddr);
}

void NWK_ResetGroups_Unpack (void *req)
{
  NWK_ResetGroups();
}

void NWK_GetParentInformation_Unpack (void *req)
{
  uint16_t ret;
  ret = NWK_GetParentInformation();
  *((uint16_t *)req) = ret;
}

void NWK_GetParentShortAddr_Unpack (void *req)
{
  ShortAddr_t addr;
  addr = NWK_GetParentShortAddr();
  *((ShortAddr_t *)req) = addr;
}

void NWK_GetPanId_Unpack (void *req)
{
   PanId_t id;
   id = NWK_GetPanId();
   *((PanId_t *)req) = id;
}

void NWK_SetPanId_Unpack(void *req)
{
  NIB_t* nwkMemNib = (NIB_t *)req;
  NWK_SetPanId(nwkMemNib->panId);
}

void NWK_GetExtPanId_Unpack(void *req)
{
  ExtPanId_t id;
  id = NWK_GetExtPanId();
  *((ExtPanId_t *)req) = id;
}

void NWK_SetExtPanId_Unpack(void *req)
{
  ExtPanId_t *extPanId = (ExtPanId_t *)req;
  NWK_SetExtPanId(extPanId);
}

void NWK_GetDeviceType_Unpack(void *req)
{
  DeviceType_t type;
  type = NWK_GetDeviceType();
  *((DeviceType_t *)req) = type;
}

void NWK_GetLogicalChannel_Unpack(void *req)
{
  Channel_t channel;
  channel = NWK_GetLogicalChannel();
  *((Channel_t *)req) = channel;
}

void NWK_SetLogicalChannel_Unpack(void *req)
{
  NIB_t* nwkMemNib = (NIB_t *)req;
  NWK_SetLogicalChannel(nwkMemNib->logicalChannel);
}

void NWK_GetBroadcastDeliveryTime_Unpack(void *req)
{
  uint32_t time;
  time = NWK_GetBroadcastDeliveryTime();
  *((uint32_t *)req) = time;
}

void NWK_GetManagerAddr_Unpack(void *req)
{
  ShortAddr_t addr;
  addr = NWK_GetManagerAddr();
  *((ShortAddr_t *)req) = addr;
}

void NWK_SetManagerAddr_Unpack(void *req)
{
  NIB_t* nwkMemNib = (NIB_t *)req;
  NWK_SetManagerAddr(nwkMemNib->managerAddr);
}

void NWK_SetUpdateId_Unpack(void *req)
{
  NIB_t* nwkMemNib = (NIB_t *)req;
  NWK_SetUpdateId(nwkMemNib->updateId);
}

void NWK_SetSymLink_Unpack(void *req)
{
  NIB_t* nwkMemNib = (NIB_t *)req;
  NWK_SetSymLink(nwkMemNib->symLink);
}

void NWK_GetProtocolVersion_Unpack(void *req)
{
  uint8_t ret;
  ret = NWK_GetProtocolVersion();
  *((uint8_t *)req) = ret;
}

void NWK_GetTransmitCouner_Unpack(void *req)
{
  uint16_t ret;
  ret = NWK_GetTransmitCouner();
  *((uint16_t *)req) = ret;
}

void NWK_GetTransmitFailureCounter_Unpack(void *req)
{
  uint16_t ret;
  ret = NWK_GetTransmitFailureCounter();
  *((uint16_t *)req) = ret;
}

void NWK_SetPassiveAckThreshold_Unpack(void *req)
{
#if defined _CUSTOM_PASSIVE_ACK_THRESHOLD_ && defined _NWK_PASSIVE_ACK_ && (defined _ROUTER_ || defined _COORDINATOR_)    
  NWK_SetPassiveAckThreshold(*(uint8_t *)req);
#endif
}


#if defined _ROUTER_ || defined _COORDINATOR_
void NWK_SetRejoinPermit_Unpack(void *req)
{
  NWK_SetRejoinPermit(*(uint8_t const*)req);
}
#endif

void NWK_GetSecurityLevel_Unpack(void *req)
{
  uint8_t ret;
  ret = NWK_GetSecurityLevel();
  *((uint8_t *)req) = ret;
}

void NWK_GetSecureAllFrames_Unpack(void *req)
{
  bool ret;
  ret = NWK_GetSecureAllFrames();
  *((bool *)req) = ret;
}

void NWK_SetKey_Unpack(void *req)
{
  NWK_SetKey_t *setKey = (NWK_SetKey_t *)req;
  setKey->ret = NWK_SetKey(setKey->key , setKey->keySeqNum);
}

void NWK_GetActiveKeySeqNumber_Unpack(void *req)
{
  NWK_KeySeqNum_t keySumNum;
  keySumNum = NWK_GetActiveKeySeqNumber();
  *((NWK_KeySeqNum_t *)req) = keySumNum;
}

void NWK_GetActiveKey_Unpack(void *req)
{
  NWK_ActiveKey_t *activeKey = (NWK_ActiveKey_t *)req;
  activeKey->ret = NWK_GetActiveKey();
}

void NWK_GetUpdatedSecOutCounter_Unpack(void *req)
{
  NwkOutFrameCounter_t ret;
  ret = NWK_GetUpdatedSecOutCounter();
  *((NwkOutFrameCounter_t *)req) = ret;
}

void NWK_GetSecOutCounter_Unpack(void *req)
{
  NwkOutFrameCounter_t ret;
  ret = NWK_GetSecOutCounter();
  *((NwkOutFrameCounter_t *)req) = ret;
}

#if defined _RESOLVE_PANID_CONFLICT_
void NWK_UpdatePanId_Unpack(void *req)
{
  NWK_UpdatePanId_t *updatePanId =  (NWK_UpdatePanId_t *)req;
  NWK_UpdatePanId(updatePanId->newPanId, updatePanId->updateId, updatePanId->callback);
}
#endif

#if defined _CERTIFICATION_
void NWK_SetKeyAmount_Unpack(void *req)
{
  NWK_SetKeyAmount_t *setKeyAmount = (NWK_SetKeyAmount_t *)req;
  setKeyAmount->status = NWK_SetKeyAmount(setKeyAmount->keyAmount);
}
#endif /* _CERTIFICATION_ */  
/* End of File*/
