/*******************************************************************************
  MAC HWI Manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiManager.h

  Summary:
    This file contains the Main MAC layer requests' manager header file.

  Description:
    This file contains the Main MAC layer requests' manager header file.
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

#ifndef _MACHWIMANAGER_H
#define _MACHWIMANAGER_H

/******************************************************************************
                        Includes  section.
******************************************************************************/
#include <mac_phy/include/macAssociate.h>
#include <mac_phy/include/macOrphan.h>
#include <mac_phy/include/macCommStatus.h>
#include <mac_phy/include/macData.h>
#include <mac_phy/include/macAssociate.h>
#include <mac_phy/include/macDisassociate.h>
#include <mac_phy/include/macPoll.h>
#include <mac_phy/include/macPurge.h>
#include <mac_phy/include/macReset.h>
#include <mac_phy/include/macRxEnable.h>
#include <mac_phy/include/macStart.h>
#include <mac_phy/include/macScan.h>
#include <mac_phy/include/macSync.h>
#include <mac_phy/include/macSetGet.h>
#include <mac_phy/include/macFrame.h>

/******************************************************************************
                        Types section.
******************************************************************************/
/******************************************************************************
  Status of current operation which could be returned from particular handler.
******************************************************************************/
typedef enum
{
  MACHWI_SUCCESS_HNDLR_RESULT,
  MACHWI_IN_PROGRESS_HNDLR_RESULT,
} MachwiHandlerResult_t;

/******************************************************************************
  Possible states of machwiManager.
******************************************************************************/
typedef enum // machwiManager possible states.
{
  MACHWI_IDLE_STATE,
  MACHWI_SET_REQ_STATE,
  MACHWI_GET_REQ_STATE,
  MACHWI_HARD_RESET_REQ_STATE,
  MACHWI_SOFT_RESET_REQ_STATE,
  MACHWI_SCAN_REQ_STATE,
#ifdef _FFD_
  MACHWI_START_REQ_STATE,
#endif //_FFD_
  MACHWI_ASSOCIATE_REQ_STATE,
#ifdef _FFD_
  MACHWI_ASSOCIATE_RESP_STATE,
#endif //_FFD_
  MACHWI_DISASSOCIATE_REQ_STATE,
  MACHWI_RX_ENABLE_REQ_STATE,
#ifdef _FFD_
  MACHWI_ORPHAN_RESP_STATE,
#endif //_FFD_
  MACHWI_POLL_REQ_STATE,
  MACHWI_DATA_REQ_STATE,
#ifdef _FFD_
  MACHWI_PURGE_REQ_STATE,
#endif //_FFD_
  MACHWI_TRANSACTION_TX_STATE,
  MACHWI_BEACON_TX_STATE,
#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_
  MACHWI_EMPTY_DATA_TX_STATE,
#endif /*_PENDING_EMPTY_DATA_FRAME_*/
#endif /*_FFD_*/
} MachwiState_t;

/******************************************************************************
  Types of possible requests to MAC_HWI.
******************************************************************************/
typedef enum  // machwi possible requests' types.
{
  MACHWI_SET_REQ_ID            = MACHWI_SET_REQ_STATE,
  MACHWI_GET_REQ_ID            = MACHWI_GET_REQ_STATE,
  MACHWI_HARD_RESET_REQ_ID     = MACHWI_HARD_RESET_REQ_STATE,
  MACHWI_SOFT_RESET_REQ_ID     = MACHWI_SOFT_RESET_REQ_STATE,
  MACHWI_SCAN_REQ_ID           = MACHWI_SCAN_REQ_STATE,
#ifdef _FFD_
  MACHWI_START_REQ_ID          = MACHWI_START_REQ_STATE,
#endif //_FFD_
  MACHWI_ASSOCIATE_REQ_ID      = MACHWI_ASSOCIATE_REQ_STATE,
#ifdef _FFD_
  MACHWI_ASSOCIATE_RESP_ID     = MACHWI_ASSOCIATE_RESP_STATE,
#endif //_FFD_
  MACHWI_DISASSOCIATE_REQ_ID   = MACHWI_DISASSOCIATE_REQ_STATE,
  MACHWI_RX_ENABLE_REQ_ID      = MACHWI_RX_ENABLE_REQ_STATE,
#ifdef _FFD_
  MACHWI_ORPHAN_RESP_ID        = MACHWI_ORPHAN_RESP_STATE,
#endif //_FFD_
  MACHWI_POLL_REQ_ID           = MACHWI_POLL_REQ_STATE,
  MACHWI_DATA_REQ_ID           = MACHWI_DATA_REQ_STATE,
#ifdef _FFD_
  MACHWI_PURGE_REQ_ID          = MACHWI_PURGE_REQ_STATE,
#endif //_FFD_
  MACHWI_TRANSACTION_TX_REQ_ID = MACHWI_TRANSACTION_TX_STATE,
  MACHWI_BEACON_TX_REQ_ID      = MACHWI_BEACON_TX_STATE,
#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_  
  MACHWI_EMPTY_DATA_TX_REQ_ID  = MACHWI_EMPTY_DATA_TX_STATE,
#endif /*_PENDING_EMPTY_DATA_FRAME_*/
#endif /*_FFD_*/
} MachwiRequestId_t;

/******************************************************************************
  Types of possible postponed MAC_HWI actions.
******************************************************************************/
typedef enum
{
  MAC_HWI_POSTPONED_ACTION_TRANSACTION_TX = (1 << 0),
  MAC_HWI_POSTPONED_ACTION_BEACON_TX      = (1 << 1),
} MachwiPostponedAction_t;

/******************************************************************************
                        Prototypes section.
******************************************************************************/
/******************************************************************************
  Main system entry point.
  Parameters:
    none.
  returns:
    none.
******************************************************************************/
void MAC_HWI_TaskHandler(void);

/******************************************************************************
\brief MAC_HWI handler that is called Force Run Task
******************************************************************************/
void MAC_HWI_ForceTaskHandler(void);

/******************************************************************************
 Sends confirmation to the upper layer.
 Parameters:
   request - parameters of the request to be confirmed.
 Returns:
   none.
******************************************************************************/
void machwiSendConfToUpperLayer(void *request);

#ifdef _FFD_
/******************************************************************************
  Sends MAC_AssociteInd to the upper layer.
  Parameters:
    associateInd - associate indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendAssociateInd(MAC_AssociateInd_t *associateInd);
#endif //_FFD_

/******************************************************************************
  Sends MAC_DataInd to the upper layer.
  Parameters:
    dataInd - data indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendDataInd(MAC_DataInd_t *dataInd);

/******************************************************************************
  Sends MAC_DisassociteInd to the upper layer.
  Parameters:
    disassociateInd - disassociate indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendDisassociateInd(MAC_DisassociateInd_t *disassociateInd);

/******************************************************************************
  Sends MAC_BeaconNotifyInd to the upper layer.
  Parameters:
    beaconInd - beacon notify indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendBeaconNotifyInd(MAC_BeaconNotifyInd_t *beaconInd);

/******************************************************************************
  Sends MAC_SyncLossInd to the upper layer.
  Parameters:
    lossInd - sync loss notify indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendSyncLossNotifyInd(MAC_SyncLossInd_t *syncLoss);

#ifdef _FFD_
/******************************************************************************
  Sends MAC_OrphanInd to the upper layer.
  Parameters:
    orphanInd - orphan indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendOrphanInd(MAC_OrphanInd_t *orphanInd);

/******************************************************************************
  Sends MAC_PollInd to the upper layer.
  Parameters:
    pollInd - poll indication descriptor.
  Returnes:
    none.
******************************************************************************/
void machwiSendPollInd(MAC_PollInd_t *pollInd);

/**************************************************************************//**
  \brief initiates transaction transmission if MAC is in IDLE state. If state
    is not IDLE - postpones operation.
******************************************************************************/
void machwiTxTransactionReq(void);

/**************************************************************************//**
  \brief initiates beacon transmission if MAC is in IDLE state. If state
    is not IDLE - postpones operation.
******************************************************************************/
void machwiTxBeaconReq(void);

/**************************************************************************//**
  \brief The function initiates empty data frame transmission if there were no 
    real transaction found and frame pending bit was set. Empty data frame will 
    be only sent if MAC is not busy with any other tasks. Otherwise the empty 
    frame will be dropped.
  \param[in] frameDescr - data request frame description.
******************************************************************************/
#ifdef _PENDING_EMPTY_DATA_FRAME_
void machwiTxEmptyDataFrameReq(MAC_FrameDescr_t *frameDescr);
#endif // _PENDING_EMPTY_DATA_FRAME_

#endif //_FFD_

#endif //_MACHWIMANAGER_H

// eof machwiManager.h
