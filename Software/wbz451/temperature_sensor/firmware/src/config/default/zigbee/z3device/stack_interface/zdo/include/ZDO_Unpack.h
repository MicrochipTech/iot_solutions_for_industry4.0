/*******************************************************************************
  Zigbee Device object Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ZDO_Unpack.h

  Summary:
    Unpack the ZDO requests and calls corresponding ZDO API.

  Description:
    This file contains declaration for ZDO Unpack requests and calls corresponding ZDO API.
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


#ifndef _ZDO_UNPACK_H_
#define _ZDO_UNPACK_H_
/*******************************************************************************
                             Includes section
*******************************************************************************/

#include <framework_defs.h>
#include <zdo/include/zdoPermissions.h>
#include <zdo/include/private/zdoPowerManager.h>
#include <z3device/stack_interface/zgb_api.h>
#include <zdo/include/zdo.h>

/*******************************************************************************
                    Global variables section
*******************************************************************************/

typedef struct _ZDO_FindShortByExt_t
{
  ExtAddr_t const *extAddr;
  ShortAddr_t const *ret;
}ZDO_FindShortByExt_t;

typedef struct _ZDO_FindExtByShort_t
{
  ShortAddr_t shortAddr;
  ExtAddr_t const *ret;
}ZDO_FindExtByShort_t;

typedef struct _ZDO_NodeDescriptor_t
{
  const NodeDescriptor_t* ret;
}ZDO_NodeDescriptor_t;

/******************************************************************************
                    Protoypes section
******************************************************************************/
/**************************************************************************//**
\brief ZDO_ZdpReq Unpack function
\param[in] req - request
******************************************************************************/
typedef uint16_t (*ZDO_Permission_t);

void ZDO_ZdpReq_Unpack(void *req);

void ZDO_FindShortByExt_Unpack(void *req);

void ZDO_FindExtByShort_Unpack(void *req);

void ZDO_GetPreconfiguredStatus_Unpack(void *req);

void ZDO_VerifyKeyReq_Unpack(void *req);

void ZDO_StartNetworkReq_Unpack(void *req);

void ZDO_WakeUpReq_Unpack(void *req);

void ZDO_StartSyncReq_Unpack(void *req);

void ZDO_StopSyncReq_Unpack(void *req);

void ZDO_SleepReq_Unpack(void *req);

void ZDO_ResetNetworkReq_Unpack(void *req);

void ZDO_GetNwkStatus_Unpack(void *req);

void ZDO_GetLqiRssi_Unpack(void *req);

void ZDO_GetParentAddr_Unpack(void *req);

void ZDO_GetChildrenAddr_Unpack(void *req);

void ZDO_SetTxPowerReq_Unpack(void *req);

void ZDO_GetNeibAmount_Unpack(void *req);

void ZDO_GetNeibTable_Unpack(void *req);

void ZDO_IsDeviceReadyToSleep_Unpack(void *req);

void ZDO_IncreaseJoinAttemptsAmount_Unpack(void *req);

void ZDO_GetNodeDescriptor_Unpack(void *req);

#endif // ZDO_UNPACK
