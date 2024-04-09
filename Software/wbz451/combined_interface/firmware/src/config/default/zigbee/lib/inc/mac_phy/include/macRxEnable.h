/*******************************************************************************
  MAC RxEnable Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macRxEnable.h

  Summary:
    This file provides access to the MAC Reception Enable primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    rx enable primitives.
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

#ifndef _MACRXENABLE_H
#define _MACRXENABLE_H

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
 * \brief MLME-RX_ENABLE confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.10.2 MLME-RX-ENABLE.confirm.
 */
typedef struct _MAC_RxEnableConf_t
{
  //! The result of the request to enable or disable the receiver.
  MAC_Status_t status;
}  MAC_RxEnableConf_t;

/**
 * \brief MLME-RX_ENABLE request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.10.1 MLME-RX-ENABLE.request.
 * deferPermit and rxOnTime  are NOT used - superframe functionality is not implemented.
 * rxOnDuration behaviour is changed. Non-standard addition.
 */
typedef struct _MAC_RxEnableReq_t
{
  //! Service field - for internal needs.
  MAC_Service_t service;
  //! Behaviour is changed. If rxOnDuration == 0 the receiver is switched off.
  //! If rxOnDuartion != 0 the receiver is switched on.
  uint32_t      rxOnDuration;
  //! MLME-RX-ENABLE callback pointer.
  void (*MAC_RxEnableConf)(MAC_RxEnableConf_t *conf);
  //! MLME-RX-ENABLE confirm parameters' structure.
  MAC_RxEnableConf_t confirm;
}  MAC_RxEnableReq_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-RX_ENABLE request primitive's prototype.
  \param reqParams - MLME-RX_ENABLE request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_RxEnableReq(MAC_RxEnableReq_t *reqParams);

#endif /* _MACRXENABLE_H */

// eof macRxEnable.h
