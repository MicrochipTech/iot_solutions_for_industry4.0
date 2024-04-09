/*******************************************************************************
  MAC HWI Memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiMem.h

  Summary:
    This file contains the MACHWI variable's memory description.

  Description:
    This file contains the MACHWI variable's memory description.
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

#ifndef _MACHWIMEM_H
#define _MACHWIMEM_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysQueue.h>
#include <hal/include/appTimer.h>
#include <mac_phy/mac_hwi/include/machwiManager.h>
#include <mac_phy/mac_hwi/include/machwiHwdReqMemPool.h>
#include <mac_phy/mac_hwi/include/machwiAssociateHandler.h>
#include <mac_phy/mac_hwi/include/machwiDisassociateHandler.h>
#include <mac_phy/mac_hwi/include/machwiScanHandler.h>
#include <mac_phy/mac_hwi/include/machwiStartHandler.h>
#include <mac_phy/mac_hwi/include/machwiTransactionHandler.h>
#include <mac_phy/mac_hwi/include/machwiPollHandler.h>
#include <mac_phy/include/macBanNode.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  union
  {
    MachwiAssociateState_t    assoc;
#ifdef _MAC_DISASSOCIATE_
    MachwiDisassociateState_t disassoc;
#endif // _MAC_DISASSOCIATE_
    MachwiScanState_t         scan;
#ifdef _FFD_
    MachwiStartState_t        start;
#endif // _FFD_
  } state;
  void                      *machwiReq; // Used by all modules which need to save requests' parameters.
  BC_Timer_t                   comAppTimer; // Used by all modules except machwiTransactionQueue.
  QueueDescriptor_t         reqQueueDescr;
  MAC_DisassociateInd_t     disassociateInd; // For the disassociate handler needs.
  MachwiHwdReqDescr_t       machwdReq;
#ifdef _FFD_
  QueueDescriptor_t         transactionQueueDescr; // For the transaction queue needs - transaction queue descriptor.
  HAL_AppTimer_t            transTimer; // For the transaction queue needs - transaction queue timer.
  MachwiTransaction_t       *currentTransaction;
#endif //_FFD_
  void                      (*sendSwitchConfirm)(void);
#ifdef _MAC_BAN_NODE_
  MAC_BanTable_t            banTable;
#endif /* _MAC_BAN_NODE_ */
#ifdef _FFD_
#ifdef _TEST_EMPTY_DATA_FEATURE_
  HAL_AppTimer_t            emptyDataDelayTimer;
#endif /*_TEST_EMPTY_DATA_FEATURE_*/
#endif /*_FFD_*/
  MachwiState_t             managerState; // For the manager needs.
  MachwiPollHandlerState_t  pollState; // For the poll handler needs.
  bool                      txCoordRealigCmd; // For the start handler needs.
  uint8_t                   nextChannel; // For the scan handler needs.
  uint8_t                   postponedAction; // MAC postponed actions bit field.
  bool                      switchIsLocked; // For the switching Rx Control needs.
#ifdef _FFD_
  MachwiTransactionHandlerState_t transactionHandlerState; // For the transaction handler needs.
  uint8_t                   activatedTransactionsCounter;
#endif //_FFD_
} MachwiMem_t;

#endif /* _MACHWIMEM_H */

// eof machwiMem.h
