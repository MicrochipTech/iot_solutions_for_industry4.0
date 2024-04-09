// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object network manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoNwkManager.h

  Summary:
    This file contains the header file describes the constants, types and internal interface
    of ZDO network manager.

  Description:
    This file contains the header file describes the constants, types and internal interface
    of ZDO network manager.

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
#ifndef _ZDONWKMANAGER_H
#define _ZDONWKMANAGER_H
// DOM-IGNORE-END

/******************************************************************************
                            Includes section
 ******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <nwk/include/nwk.h>
#include <zdo/include/zdo.h>
#include <zdo/include/private/zdoTaskManager.h>
#include <aps/include/aps.h>
#include <zdo/include/private/zdoCommands.h>

/******************************************************************************
                            Types section
 ******************************************************************************/

/** To do By UNITHRA. */
typedef enum
{
  ZDO_IDLE_NWK_UPDATE_STATE,
  ZDO_INTERNAL_NWK_UPDATE_STATE,
  ZDO_EXTERNAL_NWK_UPDATE_STATE,
  ZDO_EXTERNAL_ERROR_NWK_UPDATE_STATE
} ZdoNWKUpdateState_t;

/** to do by Unithra. */
typedef struct _ZdoNwkManager_t
{
  MAC_SetReq_t          macSetReq;
  ZDO_SetTxPowerReq_t   *txPowerReq;
#ifdef _SECURITY_
  APS_UpdateDeviceReq_t apsUpdateDeviceReq;
#endif //_SECURITY_
  uint16_t              totalTransactions;
  uint16_t              failTransactions;
  HAL_AppTimer_t        updateNwkWaitTimer;
  uint8_t               transSeqNum;
  uint8_t               statusIndCounter: 4;
  bool                  updateDeviceReqBusy: 1;
  bool                  updateDeviceReqPending: 1;
  bool                  badLink;
} ZdoNwkManager_t;

/******************************************************************************
                                Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
  \brief ###########to do by Unithra
  \param[in] deviceAnnceConf - ###########to do by Unithra
  \return ###########to do by Unithra
 ******************************************************************************/
ZDO_PRIVATE void zdoNwkManagerReset(void);

/**************************************************************************//**
  \brief Send Device Annce command
  \param[in] deviceAnnceConf - confirmation callback
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoSendDeviceAnnce(ZdoCommand_t *const zdoCommand,void (*deviceAnnceConf)(ZDO_ZdpResp_t *zdpResp));

#if defined _SECURITY_
#if defined(_COORDINATOR_) || defined(_ROUTER_) || defined(_LINK_SECURITY_)
/*************************************************************************//**
  \brief Check if short address is available for given extended address and send
  appropriate request if not.
  \param[in] addr - extended address to check
  \return true - short address already available
           false - short address currently is not available, request was sent
 ******************************************************************************/
ZDO_PRIVATE bool zdoDiscoverNwkAddress(const ExtAddr_t *const addr);
#endif
#endif

#endif // _ZDONWKMANAGER_H

// eof zdoNwkManager.h
