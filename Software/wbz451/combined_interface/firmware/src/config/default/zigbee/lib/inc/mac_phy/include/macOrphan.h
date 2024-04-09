/*******************************************************************************
  MAC Orphan Handling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macOrphan.h

  Summary:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    orphan primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    orphan primitives.
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

#ifndef _MACORPHAN_H
#define _MACORPHAN_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macCommon.h>
#include <mac_phy/include/macCommStatus.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/

/******************************************************************************
                        Types section.
******************************************************************************/
//! MLME-ORPHAN indication primitive's parameters. IEEE 802.15.4-2006 7.1.8.1
typedef struct
{
  //! The address of the orphaned device.
  ExtAddr_t extAddr;
}  MAC_OrphanInd_t;

//! MLME-ORPHAN response pritive's parameters. IEEE 802.15.4-2006 7.1.8.2
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t service;
  //! The address of the orphaned device.
  ExtAddr_t     extAddr;
  //! The 16-bit short address allocated to the orphaned device if it is
  //! associated with this coordinator.
  ShortAddr_t   shortAddr;
  //! TRUE if the orphaned device is associated with this coordinator or FALSE otherwise.
  bool          associate;
  //! MLME-ORPHAN response callback function pointer.
  void (*MAC_CommStatusInd)(MAC_CommStatusInd_t *commStat);
  // MLME-COMM_STATUS parameters' structure.
  MAC_CommStatusInd_t commStatus;
}  MAC_OrphanResp_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-ORPHAN indication primitive's prototype.
  \param indParams - MLME-ORPHAN indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_OrphanInd(MAC_OrphanInd_t *indParams);

/**************************************************************************//**
  \brief  MLME-ORPHAN response primitive's prototype.
  \param respParams - MLME-ORPHAN response parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_OrphanResp(MAC_OrphanResp_t *respParams);

#endif // _MACORPHAN_H

// eof macOrphan.h
