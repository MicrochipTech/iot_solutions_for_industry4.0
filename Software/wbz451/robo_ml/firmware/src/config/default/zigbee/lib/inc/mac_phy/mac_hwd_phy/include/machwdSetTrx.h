/*******************************************************************************
  MAC HwdSetTrx Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwdSetTrx.h

  Summary:
    This file contains the MACHWD transceiver control types and function prototypes.

  Description:
    This file contains the MACHWD transceiver control types and function prototypes.
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

#ifndef _MACHWDSETTRX_H
#define _MACHWDSETTRX_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/mac_hwd_phy/include/machwdService.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
//! Set of commands to control radio transcivier.
typedef enum
{
  MACHWD_TX_ON_CMD,
  MACHWD_RX_ON_CMD,
  MACHWD_TRX_OFF_CMD,
  MACHWD_PLL_ON_CMD
} MACHWD_TrxCmd_t;

//! Set TRX state request structure.
typedef struct
{
  //! Service field - for internal needs.
  MACHWD_Service_t         service;
  //! Command to chnage the trancivier current state.
  MACHWD_TrxCmd_t          trxCmd;
  // MACHWD set trx state confirm callback function's pointer.
  void (*MACHWD_SetTrxStateConf)(void);
} MACHWD_SetTrxStateReq_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief Set trx state.
  \param reqParams - MACHWD set trx state request structure pointer.
  \return none.
******************************************************************************/
void MACHWD_SetTrxStateReq(MACHWD_SetTrxStateReq_t *reqParams);

#endif /* _MACHWDSETTRX_H */

// eof machwdSetTrx.h
