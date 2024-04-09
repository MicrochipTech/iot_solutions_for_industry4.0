/*******************************************************************************
  MAC Purging Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macPurge.h

  Summary:
    This file provides access to the MAC Purging parameters.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
     purge primitives.
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

#ifndef _MACPURGE_H
#define _MACPURGE_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                        Defines section
******************************************************************************/

/******************************************************************************
                        Types section
******************************************************************************/
/**
 * \brief MCPS-PURGE confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.1.5 MCPS-PURGE.confirm.
 */
typedef struct
{
  //! The handle of the MSDU requested to be purge from the transaction queue.
  uint8_t msduHandle;
  //! The status of the request to be purged an MSDU from the transaction queue.
  MAC_Status_t status;
}  MAC_PurgeConf_t;

/**
 * \brief MCPS-PURGE request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.1.4 MCPS-PURGE.request.
 */
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t service;
  //! The handle of the MSDU to be purged from the transaction queue.
  uint8_t       msduHandle;
  //! MCPS-PURGE confirm callback function pointer.
  void (*MAC_PurgeConf)(MAC_PurgeConf_t *conf);
  //! MCPS-PURGE confirm parameters' structure.
  MAC_PurgeConf_t confirm;
}  MAC_PurgeReq_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MCPS-PURGE request primitive's prototype.
  \param reqParams - MCPS-PURGE request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_PurgeReq(MAC_PurgeReq_t *reqParams);

#endif /* _MACPURGE_H */

// eof macPurge.h
