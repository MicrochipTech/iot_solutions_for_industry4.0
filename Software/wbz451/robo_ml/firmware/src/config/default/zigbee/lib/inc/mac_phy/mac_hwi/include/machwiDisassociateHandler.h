/*******************************************************************************
  MAC HWI Disassociate Handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiDisassociate.h

  Summary:
    This file provides the prototypes for MAC HWI DisAssociation Handling.

  Description:
    This file provides the prototypes for MAC HWI DisAssociation Handling.
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

#ifndef _MACHWIDISASSOCIATE_H
#define _MACHWIDISASSOCIATE_H
#ifdef _MAC_DISASSOCIATE_


/******************************************************************************
                    Includes section
******************************************************************************/
#include <mac_phy/include/macFrame.h>
#include <mac_phy/include/macDisassociate.h>
#include <mac_phy/mac_hwi/include/machwiManager.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  MACHWI_IDLE_DISASSOCIATE_STATE,
  MACHWI_SET_PAN_ID_DISASSOCIATE_STATE,
  MACHWI_SET_SHORT_ADDR_DISASSOCIATE_STATE,
} MachwiDisassociateState_t;

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
  Resets disassociate component.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetDisassociateHandler(void);

/******************************************************************************
 Checks disassociation request parameters, sends disassociation notification
 command.
 Parameters:
   none.
 Returns:
   current status of operation (success or "in progress").
******************************************************************************/
MachwiHandlerResult_t machwiDisassociateReqHandler(void);

/******************************************************************************
  Sets disassociation notification command fields.
  Parameters:
    frameDescr      - pointer to frame descriptor which will be set.
    disassociateReq - pointer to disassociation notification command
      parameters.
  Returns:
    none.
******************************************************************************/
void machwiPrepareDisassociateNotifCmdFrame(
  MAC_FrameDescr_t *frameDescr,
  MAC_DisassociateReq_t *disassociateReq);

/******************************************************************************
  Indicates, that disassociation notification command frame was received.
  Parameters:
    frameDescr - frame description.
  Returns:
    none.
******************************************************************************/
void machwiDisassociateNotifInd(MAC_FrameDescr_t *frameDescr);

#endif /* _MAC_DISASSOCIATE_ */

#endif /* _MACHWIDISASSOCIATE_H */

// eof machwiDisassociate.h
