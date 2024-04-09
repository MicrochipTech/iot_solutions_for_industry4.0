/*******************************************************************************
  PHY Memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phyMem.h

  Summary:
    This file contains the prototypes for PHY memory type.

  Description:
    This file contains the prototypes for PHY memory type.
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

#ifndef _PHYMEM_H
#define _PHYMEM_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyCommon.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
/** PHY sublayer internal memory pool */
typedef struct
{
  volatile PHY_TrxCmd_t      phyTrxCmd;

  // Source of timer invocation
  volatile HAL_RTimerSource_t  rTimerSource;

  volatile PhyTrxState_t     phyTrxState;
  volatile PhyState_t        phyState;
  volatile uint8_t           phyArbReqType;

  // For use in phyRxFrame.h only.
  volatile  uint8_t          rxByteCounter;
  volatile  int8_t           rssi;
  volatile bool              arbTimeourAbortStatus;

#if defined(_FFD_) && defined(_CONTROL_FRAME_PENDING_BIT_)
  volatile bool ackedWithoutPendBit;
#endif
#ifdef _CHILD_MANAGEMENT_
  volatile bool unknownChild;
#endif
  uint8_t           radioArbMode;
  // pointer to a battery monitor indication
  void (* phyBatMonInd)(void);
} PhyMem_t;

#endif /*_PHYMEM_H*/

// eof macphyMem.h
