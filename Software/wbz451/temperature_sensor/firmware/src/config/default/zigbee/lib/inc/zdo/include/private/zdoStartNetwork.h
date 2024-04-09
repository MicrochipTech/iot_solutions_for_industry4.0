// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object start network Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoStartNetwork.h

  Summary:
    This file contains the Interface for ZDO Start Network request routines.

  Description:
    This file contains the Interface for ZDO Start Network request routines.
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
#ifndef _ZDOSTARTNETWORK_H
#define _ZDOSTARTNETWORK_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/zdo.h>
#include <systemenvironment/include/sysQueue.h>
#include <nwk/include/nwk.h>

/******************************************************************************
                                Definitions section
 ******************************************************************************/

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** ########### TOdo by unithra. */
typedef enum _ZdoStartNetworkState_t
{
  ZDO_START_NETWORK_IDLE_STATE,
  ZDO_START_NETWORK_BEGIN_STATE,
  ZDO_START_NETWORK_APS_RESET_STATE,
  ZDO_START_NETWORK_FORMATION_STATE,
  ZDO_START_NETWORK_JOIN_STATE,
  ZDO_START_NETWORK_REJOIN_STATE,
  ZDO_START_NETWORK_JOINED_STATE,
  ZDO_START_NETWORK_START_ROUTER_STATE,
  ZDO_START_NETWORK_PERMIT_JOIN_STATE,
  ZDO_START_NETWORK_APS_START_STATE,
  ZDO_START_NETWORK_ANNCE_STATE,
  ZDO_START_NETWORK_CONFIRM_STATE
} ZdoStartNetworkState_t;

/** ########### TOdo by unithra. */
typedef void (ZdoStartNetworkConf_t)(ZDO_Status_t status);

/** ########### TOdo by unithra. */
typedef struct _ZdoStartNetwork_t
{
  QueueDescriptor_t        queue;
  NWK_JoinControl_t        joinCtrl;
  ZdoStartNetworkConf_t    *confirm;
#if defined(_ROUTER_) || defined(_ENDDEVICE_)
  HAL_AppTimer_t           joinTimer;
  uint8_t                  joinAttempts;
#endif
  ZdoStartNetworkState_t   state;
} ZdoStartNetwork_t;

/** ########### TOdo by unithra. */
typedef struct
{
  QueueDescriptor_t        queue;
  /** The requested timeout enumeration. */
  NwkEndDeviceTimeout_t timeout;
  /** This bitmask indicates the end device  requested configuration. */
  uint8_t endDeviceConfiguration;
  /** Confirm callback fucntion's pointer. */
  void (*NWK_EndDeviceTimeoutConf)(NWK_EndDeviceTimeoutConf_t *conf);
  /** Corresponding confirmation structure. */
  NWK_EndDeviceTimeoutConf_t confirm;
}ZdoEndDeviceTimeoutReq_t;

/******************************************************************************
                        Prototypes section
 ******************************************************************************/

/**************************************************************************//**
  \brief Reset Start Network component.
  \param None
  \return None
 ******************************************************************************/
ZDO_PRIVATE void zdoStartNetworkReset(void);

/*************************************************************************//**
  \brief Start Network request task handler.
  \param None
  \return None
 ******************************************************************************/
ZDO_PRIVATE void zdoStartNetworkTaskHandler(void);

/**************************************************************************//**
  \brief Allocate Start Network module
  \param[in] startNetworkConf - confirmation callback
  \return true - if module was alocated, false otherwise
 ******************************************************************************/
ZDO_PRIVATE bool zdoStartNetworkAlloc(ZdoStartNetworkConf_t *startNetworkConf);

/*************************************************************************//**
  \brief Free Start Network module
  \param None
  \return None
 ******************************************************************************/
ZDO_PRIVATE void zdoStartNetworkFree(void);

#if defined (_CHILD_MANAGEMENT_) && defined(_ENDDEVICE_)
/**************************************************************************//**
  \brief End device timeout request.
  \param None
  \return None
 ******************************************************************************/
ZDO_PRIVATE void  zdoEndDeviceTimeoutReq(void);
#endif

#if defined(_COORDINATOR_) || (defined(_ROUTER_) && defined(_DISTRIBUTED_SECURITY_))
/************************************************************************//**
  \brief NLME-NETWORK-FORMATION.request preparing and sending.
  \param None
  \return None
******************************************************************************/
ZDO_PRIVATE void zdoNetworkFormationReq(void);
#endif /* #if defined(_COORDINATOR_) || (defined(_ROUTER_) && defined(_DISTRIBUTED_SECURITY_)) */

#if defined _ROUTER_ || defined _ENDDEVICE_
/**************************************************************************//**
  \brief Rejoin network
 ******************************************************************************/
ZDO_PRIVATE void zdoRejoinNetwork(void);
#endif

#if !defined _LIGHT_LINK_PROFILE_ && (defined _ROUTER_ || defined _ENDDEVICE_)
/**************************************************************************//**
  \brief Start Intra-PAN portability procedure. Stop activity and try to rejoin.
 ******************************************************************************/
ZDO_PRIVATE void zdoPerformIntraPanPortability(void);

#else
#define zdoPerformIntraPanPortability() (void)0
#endif

#endif // _ZDOSTARTNETWORK_H

// eof zdoStartNetwork.h
