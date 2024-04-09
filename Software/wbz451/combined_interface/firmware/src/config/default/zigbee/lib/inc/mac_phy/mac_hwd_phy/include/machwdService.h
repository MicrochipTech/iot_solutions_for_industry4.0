/*******************************************************************************
  MAC HwdService Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwdService.h

  Summary:
    This file Describes MAC Hwd service types' parameter declarations for internal needs.

  Description:
    This file Describes MAC Hwd service types' parameter declarations for internal needs.
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

#ifndef _MACHWDSERVISE_H
#define _MACHWDSERVISE_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                        Types section.
******************************************************************************/
//! Set of MACHWD request identifiers.
enum
{
  MACHWD_TX_DATA_REQ_ID,
  MACHWD_SET_TRX_STATE_REQ_ID,
  MACHWD_SET_REQ_ID,
  MACHWD_ED_REQ_ID,
#ifdef _RF_AES_
  MACHWD_ENCRYPT_REQ_ID,
#endif /*_RF_AES_*/
#ifdef _RF_BAT_MON_
  MACHWD_BAT_MON_REQ_ID,
#endif /*_RF_BAT_MON_*/
#ifdef _RF_RND_
  MACHWD_RND_REQ_ID,
#endif /* _RF_RND_*/
#ifdef _RF_CALIBRATION_
  MACHWD_CALIBRATION_REQ_ID,
#endif
#ifdef _RF_REG_ACCESS_
  MACHWD_REG_WRITE_REQ_ID,
  MACHWD_REG_READ_REQ_ID,
#endif
  MACHWD_HANDLERS_NUMBER // Must be the last in the list
};

//! Inherited service structure.
typedef MAC_Service_t MACHWD_Service_t;

#endif /* _MACHWDSERVISE_H */

// eof machwdService.h
