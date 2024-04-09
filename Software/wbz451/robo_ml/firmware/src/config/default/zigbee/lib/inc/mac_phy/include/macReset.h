/*******************************************************************************
  MAC Reset Handling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macReset.h

  Summary:
    This file provides access to the MAC Reset primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    reset primitives.
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

#ifndef _MACRESET_H
#define _MACRESET_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                        Defines section
******************************************************************************/
/******************************************************************************
                        Types section
******************************************************************************/
/**
 * \brief MLME-RESET confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.9.2 MLME-RESET.confirm.
 */
typedef struct
{
  //! The result of the reset operation.
  MAC_Status_t status;
}  MAC_ResetConf_t;

/**
 * \brief MLME-RESET request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.9.1 MLME-RESET.request
 */
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t service;
  //! If TRUE, the MAC sublayer is reset, and all MAC PIB attributes are set
  //! to their default values. It resets radio chip also.
  bool setDefaultPib;
  // MLME-RESET confirm callback function's pointer.
  void (*MAC_ResetConf)(MAC_ResetConf_t *conf);
  // MLME-RESET confirm parameters structure.
  MAC_ResetConf_t confirm;
}  MAC_ResetReq_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-RESET request primitive's prototype.
  \param reqParams - MLME-RESET request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_ResetReq(MAC_ResetReq_t *reqParams);

#endif /* _MACRESET_H */

// eof macReset.h
