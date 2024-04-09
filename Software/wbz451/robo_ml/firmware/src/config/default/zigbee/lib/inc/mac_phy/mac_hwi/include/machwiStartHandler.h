/*******************************************************************************
  MAC HWI Start Handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiStartHandler.h

  Summary:
    This file contains the prototype for MAC HWI start Req Routines.

  Description:
    This file contains the prototype for MAC HWI start Req Routines.
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

#ifndef _MACHWISTARTHANDLER_H
#define _MACHWISTARTHANDLER_H
#ifdef _FFD_

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/mac_hwd_phy/include/machwd.h>
#include <mac_phy/mac_hwi/include/machwiManager.h>

/******************************************************************************
                        Defines section
******************************************************************************/

/******************************************************************************
                        Types section
******************************************************************************/
typedef enum
{
  MACHWI_IDLE_START_STATE,
  MACHWI_SET_PAN_ID_START_STATE,
  MACHWI_SET_PAN_COORDINATOR_START_STATE,
  MACHWI_SET_PAGE_START_STATE,
  MACHWI_SET_CHANNEL_START_STATE,
  MACHWI_TX_COORD_REALIG_CMD_STATE,
} MachwiStartState_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/******************************************************************************
  TBD
 Parameters:
   TBD - TBD.
 Returns:
   TBD.
******************************************************************************/
MachwiHandlerResult_t machwiStartReqHandler(void);

/******************************************************************************
  Resets start handler.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetStartHandler(void);

#endif // _FFD_
#endif /* _MACHWISTARTHANDLER_H */

// eof machwiStartHandler.h
