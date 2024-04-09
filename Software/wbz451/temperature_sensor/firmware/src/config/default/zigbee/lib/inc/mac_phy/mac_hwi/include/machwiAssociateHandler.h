/*******************************************************************************
  MAC HWI Associate Handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiAssociateHandler.h

  Summary:
    This file contains the MAC Hwi Association Handler prototypes.

  Description:
    This file contains the MAC Hwi Association Handler prototypes and parameters.
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

#ifndef _MACHWIASSOCIATEHANDLER_H
#define _MACHWIASSOCIATEHANDLER_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <mac_phy/mac_hwi/include/machwiManager.h>

/******************************************************************************
                       Types section
******************************************************************************/
typedef enum
{
  MACHWI_IDLE_ASSOCIATE_STATE,
  MACHWI_SET_CHANNEL_ASSOCIATE_STATE,
  MACHWI_SET_PAGE_ASSOCIATE_STATE,
  MACHWI_SET_COORD_PAN_ID_ASSOCIATE_STATE,
  MACHWI_SET_SHORT_ADDR_ASSOCIATE_STATE,
  MACHWI_CLR_RX_ON_WHEN_IDLE_ASSOCIATE_STATE,
  MACHWI_TX_ASSOCIATE_REQUEST_ASSOCIATE_STATE,
  MACHWI_WAIT_TX_DATA_REQUEST_ASSOCIATE_STATE,
  MACHWI_TX_DATA_REQUEST_ASSOCIATE_STATE,
  MACHWI_WAIT_ASSOCIATE_RESP_FRAME_ASSOCIATE_STATE,
  MACHWI_SET_TRX_OFF_ASSOCIATE_STATE,
} MachwiAssociateState_t;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/******************************************************************************
 Checks associate request parameters, sends associate and data request commands.
 Waits for the responce.
 Parameters:
   none.
 Returns:
   current status of operation (success or "in progress").
******************************************************************************/
MachwiHandlerResult_t machwiAssociateReqHandler(void);

#ifdef _FFD_
/******************************************************************************
 Checks associate responce parameters, and puts the responce to the transaction
 queue.
 Parameters:
   none.
 Returns:
   current status of operation (success or "in progress").
******************************************************************************/
MachwiHandlerResult_t machwiAssociateRespHandler(void);
#endif //_FFD_

/******************************************************************************
  Indicates, that associate response command frame was received.
  Parameters:
    associateRespDescr - associate response command frame description.
  Returns:
    none.
******************************************************************************/
void machwiAssociateRespInd(MAC_FrameDescr_t *associateRespDescr);

#ifdef _FFD_
/******************************************************************************
  Indicates, that associate request command frame was received.
  Parameters:
    associateReqDescr - associate request command frame description.
  Returns:
    none.
******************************************************************************/
void machwiAssociateReqInd(MAC_FrameDescr_t *associateReqDescr);
#endif //_FFD_

/******************************************************************************
  Resets associate handler.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetAssociateHandler(void);


#endif /* _MACHWIASSOCIATEHANDLER_H */

// eof machwiAssociateHandler.h
