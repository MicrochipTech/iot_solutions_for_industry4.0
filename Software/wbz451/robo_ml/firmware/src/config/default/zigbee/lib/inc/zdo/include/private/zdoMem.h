// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoMem.h

  Summary:
    This file contains the internal Zigbee device object memory.

  Description:
    This file contains the internal Zigbee device object memory.
 *******************************************************************************/


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

// DOM-IGNORE-BEGIN
#ifndef _ZDOMEM_H
#define _ZDOMEM_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/zdo.h>
#include <zdo/include/private/zdoNwkManager.h>
#include <zdo/include/private/zdoPowerManager.h>
#include <zdo/include/private/zdoStartNetwork.h>
#include <zdo/include/private/zdoLeaveNetwork.h>
#include <zdo/include/private/zdoZdpReq.h>
#include <zdo/include/zdoSecurityManager.h>
#include <zdo/include/private/zdoEndDeviceBinding.h>
#include <zdo/include/private/zdoPermissionsTable.h>
#include <zdo/include/private/zdoAddrResolvingInt.h>
#include <zdo/include/private/zdoMgmtNwkUpdate.h>


/******************************************************************************
                                Types section
 ******************************************************************************/
typedef union _ZdoStackReq_t
{
  // Requests from ZDO to NLME
#if defined(_COORDINATOR_) || (defined(_ROUTER_) && defined(_DISTRIBUTED_SECURITY_))
  NWK_NetworkFormationReq_t nwkFormationReq;
#endif

#if defined(_ROUTER_) || defined(_ENDDEVICE_)
  NWK_JoinReq_t             nwkJoinReq;
#endif

#if defined(_COORDINATOR_) || defined(_ROUTER_)
  NWK_PermitJoiningReq_t    nwkPermitJoiningReq;
#endif

#if defined(_ROUTER_)
  NWK_StartRouterReq_t      nwkStartRouterReq;
#endif

  NWK_LeaveReq_t            nwkLeaveReq;

  // Requests from ZDO to APSME
  APS_ResetReq_t            apsResetReq;
  APS_StartReq_t            apsStartReq;
  APS_StopReq_t             apsStopReq;
} ZdoStackReq_t;

typedef struct _ZdoMem_t
{
  ZdoStackReq_t             stackReq;
  ZdoStartNetwork_t         zdoStartNetwork;
  ZdoLeaveNetwork_t         zdoLeaveNetwork;
  ZdoPowerManager_t         powerManager;
  ZdoNwkManager_t           nwkManager;
  ZdoZdpReq_t               zdoZdpReq;
#ifdef _SECURITY_
  ZdoSecurityManager_t      zdoSecurityManager;
#endif
  uint16_t                  enabledModules;
#ifdef _END_DEVICE_BINDING_
  ZdoEndDeviceBinding_t     endDevBinding;
#endif
#ifdef _PERMISSIONS_
  ZdoPermissions_t          permissions;
#endif
  ZdoAddrResolving_t        zdoAddrResolving;
  ZdoMgmtNwkUpdate_t        mgmtNwkUpdate;
} ZdoMem_t;

extern ZdoMem_t zdoMem;

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoStackReq_t * zdoMemStackRequest(void)
{
  return &zdoMem.stackReq;
}

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoPowerManager_t * zdoMemPowerManager(void)
{
  return &zdoMem.powerManager;
}

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoNwkManager_t * zdoMemNwkManager(void)
{
  return &zdoMem.nwkManager;
}

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoZdpReq_t * zdoMemZdpReq(void)
{
  return &zdoMem.zdoZdpReq;
}

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoStartNetwork_t * zdoMemStartNetwork(void)
{
  return &zdoMem.zdoStartNetwork;
}

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoLeaveNetwork_t * zdoMemLeaveNetwork(void)
{
  return &zdoMem.zdoLeaveNetwork;
}


#ifdef _SECURITY_
/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoSecurityManager_t * zdoMemSecurityManager(void)
{
  return &zdoMem.zdoSecurityManager;
}
#endif


#ifdef _END_DEVICE_BINDING_
/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoEndDeviceBinding_t * zdoMemEndDeviceBinding(void)
{
  return &zdoMem.endDevBinding;
}
#endif


#ifdef _PERMISSIONS_
/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoPermissions_t * zdoMemPermissions(void)
{
  return &zdoMem.permissions;
}
#endif

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoAddrResolving_t * zdoMemAddrResolving(void)
{
  return &zdoMem.zdoAddrResolving;
}

/*************************************************************//**
  \brief ### todo by unithra.
  \param[in] ### todo by unithra.
  \return ### todo by unithra.
 ***************************************************************/
static inline ZdoMgmtNwkUpdate_t * zdoMemMgmtNwkUpdate(void)
{
  return &zdoMem.mgmtNwkUpdate;
}

#endif // _ZDOMEM_H

