/*******************************************************************************
  MAC HwdSet Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwdSet.h

  Summary:
    This file contains the MACHWD set types and function prototypes.

  Description:
    This file contains the MACHWD set types and function prototypes.
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

#ifndef _MACHWDSET_H
#define _MACHWDSET_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <inttypes.h>
#include <mac_phy/mac_hwd_phy/include/machwdService.h>
#include <mac_phy/include/macphyPib.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/
//! Start point for Atmel own identifier counting.
#define MACHWD_ATMEL_RESERVED_ID 0xF0

/******************************************************************************
                    Types section
******************************************************************************/
//! MACHWD PIB identifiers.
typedef enum
{
  // PHY id.
  MACHWD_PIB_CURRENT_CHANNEL_ID     = PHY_PIB_CURRENT_CHANNEL_ID,
  MACHWD_PIB_TRANSMIT_POWER_ID      = PHY_PIB_TRANSMIT_POWER_ID,
  MACHWD_PIB_CCA_MODE_ID            = PHY_PIB_CCA_MODE_ID,
  MACHWD_PIB_CURRENT_PAGE_ID        = PHY_PIB_CURRENT_PAGE_ID,
  // MAC id.
  MACHWD_PIB_MAX_CSMA_BACKOFFS_ID   = MAC_PIB_MAX_CSMA_BACKOFFS_ID,
  MACHWD_PIB_PANID_ID               = MAC_PIB_PANID_ID,
  MACHWD_PIB_SHORT_ADDR_ID          = MAC_PIB_SHORT_ADDR_ID,
  MACHWD_PIB_MIN_BE_ID              = MAC_PIB_MIN_BE_ID,
  MACHWD_PIB_MAX_FRAME_RETRIES_ID   = MAC_PIB_MAX_FRAME_RETRIES_ID,
  MACHWD_PIB_EXT_ADDR_ID            = MAC_PIB_EXT_ADDR_ID,
  // Additional id for software needs.
  MACHWD_PIB_RF_IRQ_DISABLE_ID      = MACHWD_ATMEL_RESERVED_ID,
  MACHWD_PIB_BEACON_RX_MODE_ID      = MACHWD_ATMEL_RESERVED_ID + 1,
  // Additional id for hardware needs.
  MACHWD_PIB_PAN_COORDINATOR_ID     = MACHWD_ATMEL_RESERVED_ID + 2,
  MACHWD_PIB_CCA_ED_THRES_ID        = MAC_PIB_CCA_ED_THRES,
} MACHWD_PibId_t;

//! MACHWD PIB attribute type.
typedef union
{
  MAC_PibAttr_t macPib;
  PHY_PibAttr_t phyPib;
  bool panCoordinator;
  bool rfIrqDisable;
  bool beaconRxMode;
} MACHWD_PibAttr_t;

//! MACHWD set request structure.
typedef struct
{
  //! Service field - for internal needs.
  MACHWD_Service_t  service;
  //! MACHWD PIB identifier.
  MACHWD_PibId_t    id;
  //! MACHWD PIB attribute.
  MACHWD_PibAttr_t  attr;
  // MACHWD set confirm callback function's pointer.
  void (*MACHWD_SetConf)(void);
} MACHWD_SetReq_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief Sets MACHWD attributes.
  \param reqParams - MACHWD set request structure pointer.
  \return none.
******************************************************************************/
void MACHWD_SetReq(MACHWD_SetReq_t *reqParams);

#endif /* _MACHWDSET_H */

// eof machwdSet.h
