/*******************************************************************************
  PHY Common Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phyCommon.h

  Summary:
    This file contains the PHY Common Attributes.

  Description:
    This file contains the PHY Common Attributes.
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

#ifndef _PHYCOMMON_H
#define _PHYCOMMON_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/at86rf233.h>

/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  PHY_SUCCESS_REQ_STATUS,
  PHY_BUSY_RX_REQ_STATUS,
  PHY_IN_PROGRESS_REQ_STATUS,
  PHY_BUSY_ARBITER_TX_REQ_STATUS,
  PHY_BUSY_ARBITER_RX_REQ_STATUS
} PHY_ReqStatus_t;

typedef enum
{
  HAL_ED_DELAY_ID,
  HAL_RF_STATE_POLL_DELAY_ID,
  HAL_RF_RTS_STATE_POLL_DELAY_ID,
  HAL_RF_TX_RETRY_DELAY_ID,
  HAL_RF_TX_RETRY_FAILURE_DELAY_ID,
#ifdef _ZGPD_SPECIFIC_
  HAL_IDENTICAL_FRAME_DELAY_ID,
  HAL_RX_AFTER_TX_INTERVAL_ID,
  HAL_RX_OFFSET_ID
#endif /* End of _ZGPD_SPECIFIC_ */
} HAL_RTimerSource_t;

typedef enum
{
  PHY_FORCE_TRX_OFF_CMD = TRX_CMD_FORCE_TRX_OFF,
  PHY_RX_ON_CMD         = TRX_CMD_RX_ON,
  PHY_TRX_OFF_CMD       = TRX_CMD_TRX_OFF,
  PHY_RX_AACK_ON_CMD    = TRX_CMD_RX_AACK_ON,
  PHY_TX_ARET_ON_CMD    = TRX_CMD_TX_ARET_ON,
  PHY_PLL_ON_CMD        = TRX_CMD_PLL_ON
} PHY_TrxCmd_t;

typedef enum
{
  PHY_RX_ON_TRX_STATE       = TRX_STATUS_RX_ON,
  PHY_OFF_TRX_STATE         = TRX_STATUS_TRX_OFF,
  PHY_RX_AACK_ON_TRX_STATE  = TRX_STATUS_RX_AACK_ON,
  PHY_TX_ARET_ON_TRX_STATE  = TRX_STATUS_TX_ARET_ON,
  PHY_PLL_ON_TRX_STATE      = TRX_STATUS_PLL_ON
} PhyTrxState_t;

typedef enum
{
  PHY_IDLE_STATE,
  PHY_BUSY_RX_STATE
} PhyState_t;

#endif /* _PHYCOMMON_H */

// eof phyCommon.h
