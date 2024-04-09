/*******************************************************************************
  Zigbee Cluster Library Header File

  Company:
    Microchip Technology Inc.

  File Name:
    NWK_Unpack.h

  Summary:
    Unpack the NWK requests and calls corresponding NWK API.

  Description:
    This file contains declaration for NWK Unpack requests and calls corresponding NWK API.
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
#include <framework_defs.h>
#include <z3device/stack_interface/zgb_api.h>
#include <nwk/include/nwk.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  NWK_GroupAddr_t addr;
  NWK_GroupData_t data;
  bool status;
}NWK_GroupReq_t;

typedef struct
{
  NWK_GroupData_t data;
  bool status;
}NWK_RemoveAllGroups_t;

typedef struct
{
  NWK_GroupTableEntry_t *currEntry;
  NWK_GroupTableEntry_t *nextEntry;
}NWK_NextGroup_t;

typedef struct
{
  ShortAddr_t addr;
  bool silent;
  NWK_Status_t status;
}NWK_SetShortAddr_t;
  
typedef struct
{
  ExtAddr_t const *extAddr;
  ShortAddr_t const *addr;      
}NWK_GetShortByExtAddress_t;

typedef struct
{
  ShortAddr_t shortAddr;
  ExtAddr_t const *addr;
}NWK_GetExtByShortAddress_t;

typedef struct
{
  uint8_t const *key;
  NWK_KeySeqNum_t keySeqNum;
  bool ret;
}NWK_SetKey_t;

typedef struct
{
  NWK_KeySeqNum_t keySeqNum;
  const uint8_t* ret;
}NWK_ActiveKey_t;

#if defined _RESOLVE_PANID_CONFLICT_
typedef void (* NwkUpdatePanIdConf_t)(void);
typedef struct
{
  PanId_t newPanId;
  NwkUpdateId_t updateId;
  NwkUpdatePanIdConf_t callback;
}NWK_UpdatePanId_t;
#endif

#if defined _CERTIFICATION_  
typedef struct
{
  uint8_t keyAmount;
  NWK_Status_t status;
}NWK_SetKeyAmount_t;
#endif
/*******************************************************************************
                    Global variables section
*******************************************************************************/
void NWK_GroupCapacity_Unpack (void *req);
void NWK_RemoveGroup_Unpack(void *req);
void NWK_RemoveAllGroups_Unpack(void *req);
void NWK_NextGroup_Unpack(void *req);
void NWK_LeaveReq_Unpack(void *req);
void NWK_GetUpdateId_Unpack(void *req);
void NWK_GetShortAddr_Unpack(void *req);
void NWK_IsGroupMember_Unpack(void *req);
void NWK_AddGroup_Unpack(void *req);
void NWK_SetShortAddr_Unpack(void *req);
void NWK_GetShortByExtAddress_Unpack(void *req);
void NWK_GetExtByShortAddress_Unpack(void *req);
void NWK_ResetGroups_Unpack(void *req);
void NWK_GetParentInformation_Unpack(void *req);
void NWK_GetParentShortAddr_Unpack(void *req);
void NWK_GetPanId_Unpack(void *req);
void NWK_SetPanId_Unpack(void *req);
void NWK_GetExtPanId_Unpack(void *req);
void NWK_SetExtPanId_Unpack(void *req);
void NWK_GetDeviceType_Unpack(void *req);
void NWK_GetLogicalChannel_Unpack(void *req);
void NWK_SetLogicalChannel_Unpack(void *req);
void NWK_GetBroadcastDeliveryTime_Unpack(void *req);
void NWK_GetManagerAddr_Unpack(void *req);
void NWK_SetManagerAddr_Unpack(void *req);
void NWK_SetUpdateId_Unpack(void *req);
void NWK_SetSymLink_Unpack(void *req);
void NWK_GetProtocolVersion_Unpack(void *req);
void NWK_GetTransmitCouner_Unpack(void *req);
void NWK_GetTransmitFailureCounter_Unpack(void *req);
void NWK_SetPassiveAckThreshold_Unpack(void *req);
void NWK_SetRejoinPermit_Unpack(void *req);
void NWK_GetSecurityLevel_Unpack(void *req);
void NWK_GetSecureAllFrames_Unpack(void *req);
void NWK_SetKey_Unpack(void *req);
void NWK_GetActiveKeySeqNumber_Unpack(void *req);
void NWK_GetActiveKey_Unpack(void *req);
void NWK_GetUpdatedSecOutCounter_Unpack(void *req);
void NWK_GetSecOutCounter_Unpack(void *req);
void NWK_UpdatePanId_Unpack(void *req);
void NWK_SetKeyAmount_Unpack(void *req);

