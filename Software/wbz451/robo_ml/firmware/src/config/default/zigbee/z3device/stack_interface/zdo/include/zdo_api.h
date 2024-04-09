/*******************************************************************************
 Zigbee ZDO APIs Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdo_api.h

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

#include <zdo/include/zdo.h>
#include <zdo/include/zdoSecurityManager.h>
#include <zdo/include/zdoConfigServer.h>
/******************************************************************************
                    Definitions section
*******************************************************************************/
#ifdef _PIC32CX_
#define ZDO_ZdpReq ZB_ZDO_ZdpReq
#define ZDO_FindShortByExt ZB_ZDO_FindShortByExt
#define ZDO_FindExtByShort ZB_ZDO_FindExtByShort
#define ZDO_GetPreconfiguredStatus ZB_ZDO_GetPreconfiguredStatus
#define ZDO_VerifyKeyReq ZB_ZDO_VerifyKeyReq
#define ZDO_StartNetworkReq ZB_ZDO_StartNetworkReq
#define ZDO_WakeUpReq ZB_ZDO_WakeUpReq
#define ZDO_StartSyncReq ZB_ZDO_StartSyncReq
#define ZDO_StopSyncReq ZB_ZDO_StopSyncReq
#define ZDO_ResetNetworkReq ZB_ZDO_ResetNetworkReq
#define ZDO_GetNwkStatus ZB_ZDO_GetNwkStatus
#define ZDO_GetLqiRssi ZB_ZDO_GetLqiRssi
#define ZDO_GetParentAddr ZB_ZDO_GetParentAddr
#define ZDO_GetChildrenAddr ZB_ZDO_GetChildrenAddr
#define ZDO_SetTxPowerReq ZB_ZDO_SetTxPowerReq
#define ZDO_GetNeibAmount ZB_ZDO_GetNeibAmount
#define ZDO_GetNeibTable ZB_ZDO_GetNeibTable
#define ZDO_IsDeviceReadyToSleep ZB_ZDO_IsDeviceReadyToSleep
#if defined(_ROUTER_) || defined(_ENDDEVICE_)
#define ZDO_IncreaseJoinAttemptsAmount ZB_ZDO_IncreaseJoinAttemptsAmount
#endif /* defined(_ROUTER_) || defined(_ENDDEVICE_) */
#define ZDO_GetNodeDescriptor ZB_ZDO_GetNodeDescriptor
#endif
/******************************************************************************
                    Protoypes section
******************************************************************************/
void ZB_ZDO_ZdpReq(ZDO_ZdpReq_t *zdpReq);
const ShortAddr_t* ZB_ZDO_FindShortByExt(const ExtAddr_t *const extAddr);
const ExtAddr_t* ZDO_FindExtByShort(const ShortAddr_t shortAddr);
void ZDO_ResolveAddrReq(ZDO_ResolveAddrReq_t *req);
uint8_t ZDO_GetPreconfiguredStatus(void);
void ZDO_VerifyKeyReq(ZDO_VerifiKeyReq_t *zdoVerifyKeyReq);
void ZDO_StartNetworkReq(ZDO_StartNetworkReq_t *req);
void ZDO_WakeUpReq(ZDO_WakeUpReq_t * req);
ZDO_Status_t ZDO_StartSyncReq(void);
ZDO_Status_t ZDO_StopSyncReq(void);
void ZDO_SleepReq(ZDO_SleepReq_t *req);
void ZDO_TaskHandler(void);
ZDO_PRIVATE void ZDO_UpdateParentInfo();
void ZDO_ResetNetworkReq(ZDO_ResetNetworkReq_t *req);
ZDO_NwkStatus_t ZDO_GetNwkStatus(void);
void ZDO_OrphanScanKeepalive(void);
void ZDO_GetLqiRssi(ZDO_GetLqiRssi_t *lqiRssi);
void ZDO_GetParentAddr(NodeAddr_t *parentAddr);
void ZDO_GetChildrenAddr(ZDO_GetChildrenAddr_t *childrenAddr);
void ZDO_SetTxPowerReq(ZDO_SetTxPowerReq_t *req);
void ZDO_GetNeibAmount(ZDO_GetNeibAmount_t *amount);
void ZDO_GetNeibTable(ZDO_Neib_t *table);
bool ZDO_IsDeviceReadyToSleep(void);
void ZDO_ResetNetworkConf(ZDO_ResetNetworkConf_t *conf);
#if defined(_ROUTER_) || defined(_ENDDEVICE_)
void ZDO_IncreaseJoinAttemptsAmount(uint8_t amount);
#endif /* defined(_ROUTER_) || defined(_ENDDEVICE_) */
