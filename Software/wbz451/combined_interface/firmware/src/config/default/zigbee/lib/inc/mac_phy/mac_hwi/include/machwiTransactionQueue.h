/*******************************************************************************
  MAC HWI Transaction Queue Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiTransactionQueue.h

  Summary:
    This file defines the prototype for MAC HWI Transaction Queue Handling.

  Description:
    This file defines the prototype for MAC HWI Transaction Queue Handling.
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

#ifndef _MACHWITRANSACTIONQUEUE_H
#define _MACHWITRANSACTIONQUEUE_H
#ifdef _FFD_

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/macData.h>
#include <mac_phy/include/macFrame.h>
#include <mac_phy/include/macAssociate.h>
#include <mac_phy/include/macDisassociate.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
// Transaction event.
typedef enum
{
  MAC_TRANSACTION_EXPIRED_EVENT = MAC_TRANSACTION_EXPIRED_STATUS,
  MAC_TRANSACTION_ACTIVATED_EVENT
} MachwiTransactionEvent_t;

// Transaction.
typedef union
{
  MAC_DataReq_t         dataReq;
  MAC_AssociateResp_t   associateResp;
  MAC_DisassociateReq_t disassociateReq;
} MachwiTransaction_t;

/******************************************************************************
                    Constants section
******************************************************************************/

/******************************************************************************
                    External variables
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/
/******************************************************************************
  TBD.
******************************************************************************/
void machwiPutTransactionToQueue(MachwiTransaction_t *transaction);

/******************************************************************************
  TBD.
******************************************************************************/
result_t machwiPurgeTransactionFromQueue(uint8_t msduHandle);

#if defined(_CUSTOM_MAC_HWI_PURGE_TRANSACTION_REJOIN_)
/**************************************************************************//**
 \brief Compares MAC Addr from command's parameters with transactions in the
  transaction queue. If matched - transaction is removed from the queue.
*****************************************************************************/
void machwiPurgeAllTransactionForANode (ShortAddr_t nodeAddr);
#endif // (_CUSTOM_MAC_HWI_PURGE_TRANSACTION_REJOIN_)

/**************************************************************************//**
 \brief Compares MAC Data Request command's parameters with transactions in the
  transaction queue. If matched - transaction is marked as "activated".

 \param frameDescr - Data Request MAC command descriptor.
 \return true if transaction to be transmitted is found, false otherwise
******************************************************************************/
bool machwiTestAndKickQueueTransactions(MAC_FrameDescr_t *frameDescr);

/**************************************************************************//**
 \brief Finds trunsactions which were already activated.

  \return Activated transaction pointer if found, NULL otherwise.
******************************************************************************/
MachwiTransaction_t *machwiGetActivatedTransactionFromQueue(void);

/******************************************************************************
  TBD.
******************************************************************************/
uint8_t* machwiFillPendingAddrSpecAndList(uint8_t *beaconPayload);

/******************************************************************************
  Resets transaction queue.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetTransactionQueue(void);

/******************************************************************************
 Deletes transaction from queue.
 Parameters:
   transaction - pointer to transaction wich should be deleted.
 Returns:
  none.
******************************************************************************/
void machwiDeleteTransactionFromQueue(MachwiTransaction_t *transaction);

/******************************************************************************
 Checks if MAC transaction queue is empty
 Parameters:
   none
 Returns:
  true, if MAC transaction queue is empty, false otherwise.
******************************************************************************/
bool machwiTransactionQueueEmpty(void);

#endif //_FFD_
#endif /* _MACHWITRANSACTIONQUEUE_H */

// eof machwiTransactionQueue.h
