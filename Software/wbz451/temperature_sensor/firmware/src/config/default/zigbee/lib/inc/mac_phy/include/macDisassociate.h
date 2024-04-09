/*******************************************************************************
  MAC Disassociation Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macDisassociate.h

  Summary:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    disassociation primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    disassociation primitives.
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

#ifndef _MACDISASSOCIATE_H
#define _MACDISASSOCIATE_H

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
/**************************************************************************//**
  \brief Disassociation possible reasons.

  IEEE 802.15.4-2006 7.3.3.2 Disassociation Reason field.
******************************************************************************/
typedef enum
{
  MAC_COORDINATOR_WISHES_DEVICE_LEAVE_PAN_REASON = 0x01,
  MAC_DEVICE_WISHES_LEAVE_PAN_REASON             = 0x02,
} MAC_DeassociateReason_t;

/**************************************************************************//**
  \brief MLME-DISASSOCIATE confirm primitive's parameters structure declaration.

  IEEE 802.15.4-2006 7.1.4.3 MLME-DISASSOCIATE.confirm.
******************************************************************************/
typedef struct
{
  //! The status of the disassociation attempt.
  MAC_Status_t   status;
  //! The addressing mode of the device that has either requested
  //! disassociation or been instructed to disassociate by its coordinator.
  MAC_AddrMode_t deviceAddrMode;
  //! The PAN identifier of the device that has either requested disassociation or
  //! been instructed to disassociate by its coordinator.
  PanId_t        devicePanId;
  //! The address of the device that has either requested disassociation or
  //! been instructed to disassociate by its coordinator.
  MAC_Addr_t     deviceAddr;
}  MAC_DisassociateConf_t;

/**************************************************************************//**
  \brief MLME-DISASSOCIATE request primitive's parameters structure declaration.

  IEEE 802.15.4-2006 7.1.4.3 MLME-DISASSOCIATE.confirm.
******************************************************************************/
typedef struct
{
  //! Service field - for internal needs.
  MAC_ServiceTransaction_t  service;
  //! The addressing mode of the device to which to send the disassociation
  //! notification command.
  MAC_AddrMode_t            deviceAddrMode;
  //! The PAN identifier of the device to which to send the disassociation
  //! notification command.
  PanId_t                   devicePanId;
  //! The address of the device to which to send the disassociation notification command.
  MAC_Addr_t                deviceAddr;
  //! The reason for the disassociation.
  MAC_DeassociateReason_t   reason;
  //! TRUE if the disassociation notification command is to be sent indirectly.
  bool                      txIndirect;
  //! MLME-DISASSOCIATE confirm callback fubction's pointer.
  void (*MAC_DisassociateConf)(MAC_DisassociateConf_t *conf);
  //! MLME-DISASSOCIATE confirm parameters' structure.
  MAC_DisassociateConf_t confirm;
}  MAC_DisassociateReq_t;

/*************************************************************************//**
  \brief MLME-DISASSOCIATE indication primitive's parameters.

  IEEE 802.15.4-2006 7.1.4.2 MLME-DISASSOCIATE.indication.
*****************************************************************************/
typedef struct
{
  //! The address of the device requesting disassociation.
  ExtAddr_t                 extAddr;
  //! The reason for the disassociation.
  MAC_DeassociateReason_t   reason;
}  MAC_DisassociateInd_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-DISASSOCIATE request primitive's prototype.

  \param reqParams - MLME-DISASSOCIATE request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_DisassociateReq(MAC_DisassociateReq_t *reqParams);

/**************************************************************************//**
  \brief MLME-DISASSOCIATE indication primitive's prototype.

  \param indParams - MLME-DISASSOCIATE indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_DisassociateInd(MAC_DisassociateInd_t *indParams);

#endif /* _MACDISASSOCIATE_H */

// eof macDisassociate.h
