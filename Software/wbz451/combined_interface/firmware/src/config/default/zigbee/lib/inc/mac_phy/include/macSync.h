/*******************************************************************************
  MAC Synchronisation Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macSync.h

  Summary:
    This file provides interface to MAC Synchronisation primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    sync primitives.
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

#ifndef _MACSYNC_H
#define _MACSYNC_H

/******************************************************************************
                        Includes section
******************************************************************************/

/******************************************************************************
                        Defines section
******************************************************************************/

/******************************************************************************
                        Types section
******************************************************************************/
//! Set of loss indication reasons. IEEE 802.15.4-2006 Table 75.
typedef enum
{
  MAC_PAN_ID_CONFLICT = 0,
  MAC_REALIGNMENT     = 1,
  MAC_BEACON_LOSS     = 2
} MAC_SyncLossReason_t;

//! MLME-SYNC_LOSS indication structure. IEEE 802.15.4-2006 7.1.15.2
typedef struct
{
  //! The reason that synchronization was lost.
  MAC_SyncLossReason_t reason;
  //! The PAN identifier with which the device lost synchronization or to which
  //! it was realigned.
  PanId_t              panId;
  //! The logical channel on which the device lost synchronization or to which it
  //! was realigned.
  uint8_t              logicalChannel;
  //! The channel page on which the device lost synchronization or to which it
  //! was realigned.
  uint8_t              channelPage;
}  MAC_SyncLossInd_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-SYNC_LOSS indication primitive's prototype.
  \param indParams - MLME-SYNC_LOSS indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_SyncLossInd(MAC_SyncLossInd_t *indParams);

#endif /* _MACSYNC_H */

// eof macSync.h
