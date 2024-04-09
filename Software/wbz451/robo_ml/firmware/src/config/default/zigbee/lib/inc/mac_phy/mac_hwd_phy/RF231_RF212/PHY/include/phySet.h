/*******************************************************************************
  PHY Set Handling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phySet.h

  Summary:
    This file includes the declaration to configure the PHY PIB parameter.

  Description:
    This file includes the prototypes to set PHY PIB parameters.
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

#ifndef _PHYSET_H
#define _PHYSET_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyCommon.h>
#include <mac_phy/mac_hwd_phy/include/machwdSet.h>
#include <mac_phy/include/macphyPib.h>

/******************************************************************************
                        Types section.
******************************************************************************/
// PIB identifiers.
typedef enum
{
  // PHY id.
  PHY_SET_PIB_CURRENT_CHANNEL_ID     = PHY_PIB_CURRENT_CHANNEL_ID,
  PHY_SET_PIB_TRANSMIT_POWER_ID      = PHY_PIB_TRANSMIT_POWER_ID,
  PHY_SET_PIB_CCA_MODE_ID            = PHY_PIB_CCA_MODE_ID,
  PHY_SET_PIB_CURRENT_PAGE_ID        = PHY_PIB_CURRENT_PAGE_ID,
  // MAC id.
  PHY_SET_PIB_MAX_CSMA_BACKOFFS_ID   = MAC_PIB_MAX_CSMA_BACKOFFS_ID,
  PHY_SET_PIB_PANID_ID               = MAC_PIB_PANID_ID,
  PHY_SET_PIB_SHORT_ADDR_ID          = MAC_PIB_SHORT_ADDR_ID,
  PHY_SET_PIB_MIN_BE_ID              = MAC_PIB_MIN_BE_ID,
  PHY_SET_PIB_MAX_FRAME_RETRIES_ID   = MAC_PIB_MAX_FRAME_RETRIES_ID,
  PHY_SET_PIB_EXT_ADDR_ID            = MAC_PIB_EXT_ADDR_ID,
  // Additional id for software needs.
  PHY_SET_PIB_RF_IRQ_DISABLE_ID      = MACHWD_PIB_RF_IRQ_DISABLE_ID,
  PHY_SET_PIB_PAN_COORDINATOR_ID     = MACHWD_PIB_PAN_COORDINATOR_ID,
  PHY_SET_PIB_CCA_ED_THRES           = MACHWD_PIB_CCA_ED_THRES_ID
} PHY_SetPibId_t;

typedef struct
{
  PHY_SetPibId_t    id;
  MACHWD_PibAttr_t  attr;
} PHY_SetReq_t;

/******************************************************************************
                        Prototypes section.
******************************************************************************/
/**************************************************************************//**
  \brief Performs parameter's set request to the RF chip.

  \param[in] setReq - phy set request's parameters.
******************************************************************************/
PHY_ReqStatus_t PHY_SetReq(PHY_SetReq_t *setReq);

void PHY_SetTestCarrierInit(void);
void PHY_Enable_TxStartIRQ(void);

/**************************************************************************//**
  \brief Set the transceiver in test carrier mode.

  \param[in] channel - the Channel Number.
  \param[in] modulated -0 for CW mode 1 for modulated PRBS mode.

  \return    None. 
******************************************************************************/
void PHY_SetTestCarrier(uint8_t channel, bool modulated);

/**************************************************************************//**
  \brief Set the transmit power.

  \param[in] txPower - the TXPOWER radio register value to use.
 
******************************************************************************/
void PHY_setTxPowerDirectly(uint8_t txPower);


/**************************************************************************//**
  \brief Set the transmit power in dBM.

  \param[in] txPowerDbm - the TXPOWER dBM.
 
******************************************************************************/
void PHY_setTxPowerinDbm(int8_t txPowerDbm);

#endif /* _PHYSET_H */

// eof phySet.c
