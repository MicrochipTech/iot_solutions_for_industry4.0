// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object power manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoPowerManager.h

  Summary:
    The header file describes the constants, types and internal interface
    of ZDO power manager

  Description:
    The header file describes the constants, types and internal interface
    of ZDO power manager

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
#ifndef _ZDOPOWERMANAGER_H
#define _ZDOPOWERMANAGER_H
// DOM-IGNORE-END

/******************************************************************************
                        Includes section
 ******************************************************************************/
#include <nwk/include/nwk.h>
#include <zdo/include/zdo.h>
#include <zdo/include/zdoConfigServer.h>
/******************************************************************************
                        Types section
 ******************************************************************************/
 
/** ############## ToDo by unithra */
typedef struct _ZdoPowerManager_t
{
  ZDO_SleepReq_t         *sleepReq;
  ZDO_WakeUpReq_t        *wakeUpReq;
  MAC_RxEnableReq_t      rxReq;
#ifdef _ENDDEVICE_
  NWK_SyncReq_t          syncReq;
  HAL_AppTimer_t         syncTimer;
#if defined(_SLEEP_WHEN_IDLE_)
  uint32_t               lastPollTime;
#endif /* _SLEEP_WHEN_IDLE_ */
#ifdef _CHILD_MANAGEMENT_
  uint16_t               parentInfo;
#endif

#endif // _ENDDEVICE_
  bool                   sleeping;
  bool                   rxOnWhenIdle;
#ifdef _ENDDEVICE_
  uint8_t                syncFailCounter;
  bool                   waitingSyncConf;
  bool                   polling;
#endif // _ENDDEVICE_
} ZdoPowerManager_t;

/******************************************************************************
                        Prototypes section
 ******************************************************************************/

/**************************************************************************//**
  \brief Reset power manager
 ******************************************************************************/
ZDO_PRIVATE void zdoPowerManagerReset(void);

/**************************************************************************//**
  \brief Power Manager module task handler

    Note: always post ZDO_POWER_MANAGER_TASK_ID after performing actions that
    may result in device ability to sleep.
 ******************************************************************************/
ZDO_PRIVATE void zdoPowerManagerHandler(void);

/**************************************************************************//**
  \brief Updates the Parent Information
    
  \param None ### to do by Unithra
 ******************************************************************************/
ZDO_PRIVATE void ZDO_UpdateParentInfo(void);

/*************************************************************************//**
  \brief ZDO NWK Join Confirmation for orphan scan
  \param[in] conf - confirmation data
 ******************************************************************************/
ZDO_PRIVATE void ZDO_NWK_JoinConf(NWK_JoinConf_t *conf);

#endif // _ZDOPOWERMANAGER_H_

// eof zdoPowerManager.h
