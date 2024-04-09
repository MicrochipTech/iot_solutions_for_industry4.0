/*******************************************************************************
  MAC HWI Transaction Handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiTransactionHandler.h

  Summary:
    This file contains the MAC HWI Transaction Handler routines.

  Description:
    This file contains the MAC HWI Transaction Handler routines.
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

#ifndef _MACHWITRANSACTIONHANDLER_H
#define _MACHWITRANSACTIONHANDLER_H
#ifdef _FFD_

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/mac_hwi/include/machwiTransactionQueue.h>

/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  MACHWI_IDLE_TRANSACTION_HANDLER_STATE,
  MACHWI_BUSY_ASSOCIATE_TRANSACTION_HANDLER_STATE,
#ifdef _MAC_DISASSOCIATE_

  MACHWI_BUSY_DISASSOCIATE_TRANSACTION_HANDLER_STATE,
#endif //_MAC_DISASSOCIATE_

  MACHWI_BUSY_DATA_TRANSACTION_HANDLER_STATE,
} MachwiTransactionHandlerState_t;

/******************************************************************************
                        Prototypes section.
******************************************************************************/

/******************************************************************************
  Indicates, that transaction event happened (it was requested or just expired).
  Parameters:
    transaction - transaction descriptor.
    event - type of the event (MAC_TRANSACTION_EXPIRED_EVENT or
            MAC_TRANSACTION_READY_EVENT).
  Returns:
    true - activate the kicked transaction, false - otherwise.
******************************************************************************/
bool machwiSendTransactionEvent(MachwiTransaction_t *transaction, MachwiTransactionEvent_t event);


/******************************************************************************
  Resets transaction handler.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetTransactionHandler(void);

#endif //_FFD_
#endif //_MACHWITRANSACTIONHANDLER_H

// eof machwiTransactionHandler.h
