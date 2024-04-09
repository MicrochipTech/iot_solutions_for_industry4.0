/*******************************************************************************
  MAC HWI Poll Handling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiPollHandler.h

  Summary:
    This file contains the prototype for MAC poll routine.

  Description:
    This file contains the prototype for MAC poll routine handling.
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

#ifndef _MACHWIPOLLHANDLER_H
#define _MACHWIPOLLHANDLER_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <mac_phy/include/macFrame.h>
#include <mac_phy/mac_hwi/include/machwiManager.h>

/******************************************************************************
                        Typesa definition section
******************************************************************************/
/******************************************************************************
  MAC Hardware Independent part POLL handler possible states.
******************************************************************************/
typedef enum
{
  MACHWI_POLL_HANDLER_STATE_IDLE,
  MACHWI_POLL_HANDLER_STATE_DATA_REQ_TRANSMISSION,
  MACHWI_POLL_HANDLER_STATE_ANSWER_WAITING,
  MACHWI_POLL_HANDLER_STATE_TRX_STATE_SETTING,
} MachwiPollHandlerState_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/******************************************************************************
  Resets poll handler.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetPollHandler(void);

/******************************************************************************
  Indicates data reception to upper layer.
  Parameters:
    frameDescr - pointer to frame descriptor.
  Returns:
    none.
******************************************************************************/
void machwiDataIndication(MAC_FrameDescr_t *frameDescr);

/******************************************************************************
 Checks poll request parameters, sends data request commands.
 Waits for the data.
 Parameters:
   none.
 Returns:
   current status of operation (success or "in progress").
******************************************************************************/
MachwiHandlerResult_t machwiPollReqHandler(void);

/******************************************************************************
  Indicates, that data request frame was received.
  Parameters:
    pollDescr - Poll description.
  Returns:
    none.
******************************************************************************/
void machwiPollInd(MAC_FrameDescr_t *frameDescr);

#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_
/**************************************************************************//**
  \brief Sends an empty data frame in reply to the data request.
  \param[in] frameDescr - data request frame description.
******************************************************************************/
void machwiPollHandlerReplyWithEmptyDataFrame(MAC_FrameDescr_t *frameDescr);
#endif // _PENDING_EMPTY_DATA_FRAME_
#endif /*_FFD_*/

#endif //_MACHWIPOLLHANDLER_H
// eof machwiPollHandler.h
