/*******************************************************************************
  Zigbee NWK APIs Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwk_api.h

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

#ifndef NWK_API_H
#define NWK_API_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <z3device/stack_interface/zgb_api.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/
#ifdef _PIC32CX_
#define NWK_GroupCapacity              ZB_NWK_GroupCapacity
#define NWK_RemoveGroup                ZB_NWK_RemoveGroup
#define NWK_RemoveAllGroups            ZB_NWK_RemoveAllGroups
#define NWK_NextGroup                  ZB_NWK_NextGroup
#define NWK_LeaveReq                   ZB_NWK_LeaveReq
#define NWK_GetUpdateId                ZB_NWK_GetUpdateId
#define NWK_GetShortAddr               ZB_NWK_GetShortAddr
#define NWK_IsGroupMember              ZB_NWK_IsGroupMember
#define NWK_AddGroup                   ZB_NWK_AddGroup
#define NWK_SetShortAddr               ZB_NWK_SetShortAddr
#define NWK_GetShortByExtAddress       ZB_NWK_GetShortByExtAddress
#define NWK_GetExtByShortAddress       ZB_NWK_GetExtByShortAddress
#define NWK_ResetGroups                ZB_NWK_ResetGroups
#define NWK_GetParentInformation       ZB_NWK_GetParentInformation
#define NWK_GetParentShortAddr         ZB_NWK_GetParentShortAddr
#define NWK_GetPanId                   ZB_NWK_GetPanId
#define NWK_SetPanId                   ZB_NWK_SetPanId
#define NWK_GetExtPanId                ZB_NWK_GetExtPanId
#define NWK_SetExtPanId                ZB_NWK_SetExtPanId
#define NWK_GetDeviceType              ZB_NWK_GetDeviceType
#define NWK_GetLogicalChannel          ZB_NWK_GetLogicalChannel
#define NWK_SetLogicalChannel          ZB_NWK_SetLogicalChannel
#define NWK_GetBroadcastDeliveryTime   ZB_NWK_GetBroadcastDeliveryTime
#define NWK_GetManagerAddr             ZB_NWK_GetManagerAddr
#define NWK_SetManagerAddr             ZB_NWK_SetManagerAddr
#define NWK_SetUpdateId                ZB_NWK_SetUpdateId
#define NWK_SetSymLink                 ZB_NWK_SetSymLink
#define NWK_GetProtocolVersion         ZB_NWK_GetProtocolVersion
#define NWK_GetTransmitCouner          ZB_NWK_GetTransmitCouner 
#define NWK_GetTransmitFailureCounter  ZB_NWK_GetTransmitFailureCounter
#define NWK_SetPassiveAckThreshold     ZB_NWK_SetPassiveAckThreshold 
#define NWK_SetRejoinPermit            ZB_NWK_SetRejoinPermit
#define NWK_GetSecurityLevel           ZB_NWK_GetSecurityLevel
#define NWK_GetSecureAllFrames         ZB_NWK_GetSecureAllFrames
#define NWK_SetKey                     ZB_NWK_SetKey
#define NWK_GetActiveKeySeqNumber      ZB_NWK_GetActiveKeySeqNumber
#define NWK_GetActiveKey               ZB_NWK_GetActiveKey
#define NWK_GetUpdatedSecOutCounter    ZB_NWK_GetUpdatedSecOutCounter
#define NWK_GetSecOutCounter           ZB_NWK_GetSecOutCounter
#define NWK_UpdatePanId                ZB_NWK_UpdatePanId   
#define NWK_SetKeyAmount               ZB_NWK_SetKeyAmount
#endif

/*******************************************************************************
                    Global variables section
*******************************************************************************/

/******************************************************************************
                    Protoypes section
******************************************************************************/
/**************************************************************************//**
\brief NWK_GroupCapacity pack function
\param[in] None
******************************************************************************/
NWK_GroupTableSize_t ZB_NWK_GroupCapacity(void);

/**************************************************************************//**
\brief NWK_RemoveGroup pack function
\param[in] const NWK_GroupAddr_t addr, const NWK_GroupData_t data
******************************************************************************/
bool ZB_NWK_RemoveGroup(const NWK_GroupAddr_t addr, const NWK_GroupData_t data);

/**************************************************************************//**
\brief NWK_RemoveAllGroups pack function
\param[in] NWK_GroupData_t data
******************************************************************************/
bool ZB_NWK_RemoveAllGroups(const NWK_GroupData_t data);
/**************************************************************************//**
\brief NWK_NextGroup pack function
\param[in] NWK_GroupTableEntry_t *entry
******************************************************************************/
NWK_GroupTableEntry_t* ZB_NWK_NextGroup(NWK_GroupTableEntry_t *entry);

/**************************************************************************//**
\brief NWK_LeaveReq pack function
\param[in] NWK_LeaveReq_t *req
******************************************************************************/
void ZB_NWK_LeaveReq(NWK_LeaveReq_t *const req);

/**************************************************************************//**
\brief NWK_GetUpdateId pack function
\param[in] None
\ return value: NwkUpdateId_t
******************************************************************************/
NwkUpdateId_t ZB_NWK_GetUpdateId(void);

/**************************************************************************//**
\brief NWK_GetShortAddr pack function
\param[in] None
\ return value: ShortAddr_t
******************************************************************************/
ShortAddr_t ZB_NWK_GetShortAddr(void);

/**************************************************************************//**
\brief NWK_IsGroupMember pack function
\param[in] const NWK_GroupAddr_t addr, const NWK_GroupData_t data
\ return value: Success or Failure
******************************************************************************/
bool ZB_NWK_IsGroupMember(const NWK_GroupAddr_t addr, const NWK_GroupData_t data);

/**************************************************************************//**
\brief NWK_AddGroup pack function
\param[in] const NWK_GroupAddr_t addr, const NWK_GroupData_t data
\ return value: Success or Failure
******************************************************************************/
bool ZB_NWK_AddGroup(const NWK_GroupAddr_t addr, const NWK_GroupData_t data);

/**************************************************************************//**
\brief NWK_SetShortAddr pack function
\param[in] const ShortAddr_t shortAddr, const bool silent
\ return value: NWK_Status_t
******************************************************************************/
NWK_Status_t ZB_NWK_SetShortAddr(const ShortAddr_t shortAddr, const bool silent);

/**************************************************************************//**
\brief ZB_NWK_GetShortByExtAddress pack function
\param[in] const ExtAddr_t *const extAddr
\ return value: ShortAddr_t*
******************************************************************************/
const ShortAddr_t* ZB_NWK_GetShortByExtAddress(const ExtAddr_t *const extAddr);

/**************************************************************************//**
\brief ZB_NWK_GetExtByShortAddress pack function
\param[in] const ShortAddr_t shortAddr
\ return value: ExtAddr_t*
******************************************************************************/
const ExtAddr_t* ZB_NWK_GetExtByShortAddress(const ShortAddr_t shortAddr);

/**************************************************************************//**
\brief ZB_NWK_ResetGroups pack function
\param[in] None
\ return value: None
******************************************************************************/
void ZB_NWK_ResetGroups(void);

/**************************************************************************//**
\brief ZB_NWK_GetParentInformation pack function
\param[in] None
\ return value: uint16_t
******************************************************************************/
uint16_t ZB_NWK_GetParentInformation(void);

/**************************************************************************//**
\brief ZB_NWK_GetParentShortAddr pack function
\param[in] None
\ return value: ShortAddr_t
******************************************************************************/
ShortAddr_t ZB_NWK_GetParentShortAddr(void);

/**************************************************************************//**
\brief ZB_NWK_GetPanId pack function
\param[in] None
\ return value: PanId_t
******************************************************************************/
PanId_t ZB_NWK_GetPanId(void);

/**************************************************************************//**
\brief ZB_NWK_SetPanId pack function
\param[in] PanId_t panId
\ return value: None
******************************************************************************/
void ZB_NWK_SetPanId(PanId_t panId);

/**************************************************************************//**
\brief ZB_NWK_GetExtPanId pack function
\param[in] None
\ return value: ExtPanId_t
******************************************************************************/
ExtPanId_t ZB_NWK_GetExtPanId(void);

/**************************************************************************//**
\brief ZB_NWK_SetExtPanId pack function
\param[in] const ExtPanId_t *extPanId
\ return value: None
******************************************************************************/
void ZB_NWK_SetExtPanId(const ExtPanId_t *extPanId);

/**************************************************************************//**
\brief ZB_NWK_GetDeviceType pack function
\param[in] None
\ return value: DeviceType_t
******************************************************************************/
DeviceType_t ZB_NWK_GetDeviceType(void);

/**************************************************************************//**
\brief ZB_NWK_GetLogicalChannel pack function
\param[in] None
\ return value: Channel_t
******************************************************************************/
Channel_t ZB_NWK_GetLogicalChannel(void);

/**************************************************************************//**
\brief ZB_NWK_SetLogicalChannel pack function
\param[in] const Channel_t channel
\ return value: none
******************************************************************************/
void ZB_NWK_SetLogicalChannel(const Channel_t channel);

/**************************************************************************//**
\brief ZB_NWK_GetBroadcastDeliveryTime pack function
\param[in] none
\ return value: uint32_t
******************************************************************************/
uint32_t ZB_NWK_GetBroadcastDeliveryTime(void);

/**************************************************************************//**
\brief ZB_NWK_GetManagerAddr pack function
\param[in] none
\ return value: ShortAddr_t
******************************************************************************/
ShortAddr_t ZB_NWK_GetManagerAddr(void);

/**************************************************************************//**
\brief ZB_NWK_SetManagerAddr pack function
\param[in] const ShortAddr_t shortAddr
\ return value: none
******************************************************************************/
void ZB_NWK_SetManagerAddr(const ShortAddr_t shortAddr);

/**************************************************************************//**
\brief ZB_NWK_SetUpdateId pack function
\param[in] const NwkUpdateId_t updateId
\ return value: none
******************************************************************************/
void ZB_NWK_SetUpdateId(const NwkUpdateId_t updateId);

/**************************************************************************//**
\brief ZB_NWK_SetSymLink pack function
\param[in] const bool symLink
\ return value: none
******************************************************************************/
void ZB_NWK_SetSymLink(const bool symLink);

/**************************************************************************//**
\brief ZB_NWK_GetProtocolVersion pack function
\param[in] none
\ return value: uint8_t
******************************************************************************/
uint8_t ZB_NWK_GetProtocolVersion(void);

/**************************************************************************//**
\brief ZB_NWK_GetTransmitCouner pack function
\param[in] none
\ return value: uint16_t
******************************************************************************/
uint16_t ZB_NWK_GetTransmitCouner(void);

/**************************************************************************//**
\brief ZB_NWK_GetTransmitFailureCounter pack function
\param[in] none
\ return value: uint16_t
******************************************************************************/
uint16_t ZB_NWK_GetTransmitFailureCounter(void);

/**************************************************************************//**
\brief ZB_NWK_SetPassiveAckThreshold pack function
\param[in] uint8_t thresholdValue
\ return value: none
******************************************************************************/
void ZB_NWK_SetPassiveAckThreshold(uint8_t thresholdValue);

/**************************************************************************//**
\brief ZB_NWK_SetRejoinPermit pack function
\param[in] const NWK_RejoinPermit_t permit
\ return value: none
******************************************************************************/
void ZB_NWK_SetRejoinPermit(const NWK_RejoinPermit_t permit);

/**************************************************************************//**
\brief ZB_NWK_GetSecurityLevel pack function
\param[in] none
\ return value: uint8_t
******************************************************************************/
uint8_t ZB_NWK_GetSecurityLevel(void);

/**************************************************************************//**
\brief ZB_NWK_GetSecureAllFrames pack function
\param[in] none
\ return value: success or failure
******************************************************************************/
bool ZB_NWK_GetSecureAllFrames(void);

/**************************************************************************//**
\brief ZB_NWK_SetKey pack function
\param[in] const uint8_t *const key, const NWK_KeySeqNum_t keySeqNum
\ return value: success or failure
******************************************************************************/
bool ZB_NWK_SetKey(const uint8_t *const key, const NWK_KeySeqNum_t keySeqNum);

/**************************************************************************//**
\brief ZB_NWK_GetActiveKeySeqNumber pack function
\param[in] none
\ return value: NWK_KeySeqNum_t
******************************************************************************/
NWK_KeySeqNum_t ZB_NWK_GetActiveKeySeqNumber(void);

/**************************************************************************//**
\brief ZB_NWK_GetActiveKey pack function
\param[in] const NWK_KeySeqNum_t keySeqNum
\ return value: success or failure
******************************************************************************/
const uint8_t* ZB_NWK_GetActiveKey(const NWK_KeySeqNum_t keySeqNum);

/**************************************************************************//**
\brief ZB_NWK_GetUpdatedSecOutCounter pack function
\param[in] none
\ return value: NwkOutFrameCounter_t
******************************************************************************/
NwkOutFrameCounter_t ZB_NWK_GetUpdatedSecOutCounter(void);

/**************************************************************************//**
\brief ZB_NWK_GetSecOutCounter pack function
\param[in] none
\ return value: NwkOutFrameCounter_t
******************************************************************************/
NwkOutFrameCounter_t ZB_NWK_GetSecOutCounter(void);

#if defined _RESOLVE_PANID_CONFLICT_
typedef void (* NwkUpdatePanIdConf_t)(void);

/**************************************************************************//**
\brief ZB_NWK_UpdatePanId pack function
\param[in] const PanId_t newPanId, const NwkUpdateId_t updateId,
  const NwkUpdatePanIdConf_t callback
\ return value: none
******************************************************************************/
void ZB_NWK_UpdatePanId(const PanId_t newPanId, const NwkUpdateId_t updateId,
  const NwkUpdatePanIdConf_t callback);
#endif

#if defined _CERTIFICATION_
/**************************************************************************//**
\brief ZB_NWK_SetKeyAmount pack function
\param[in] const uint8_t keyAmount)
\ return value: NWK_Status_t
******************************************************************************/
NWK_Status_t ZB_NWK_SetKeyAmount(const uint8_t keyAmount);
#endif
#endif // ZCL_API_H
