/*******************************************************************************
  PHY Memory Access Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phyMemAccess.h

  Summary:
    This file contains the prototypes for PHY memory access functions.

  Description:
    This file contains the prototypes for PHY memory access functions.
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

#ifndef _PHYMEMACCESS_H
#define _PHYMEMACCESS_H

/******************************************************************************
                           Includes section
******************************************************************************/
#include <mac_phy/include/macMem.h>

/******************************************************************************
                           External variables section
******************************************************************************/
/** Declared in .../MAC_ENV/src/macMem.c */
extern MAC_Mem_t macMem;

/******************************************************************************
                           Inline functions section
 ******************************************************************************/
INLINE volatile PHY_TrxCmd_t *phyMemPhyTrxCmd(void)
{
  return &macMem.phy.phyTrxCmd;
}

INLINE volatile HAL_RTimerSource_t *phyMemRTimerSource(void)
{
  return &macMem.phy.rTimerSource;
}

INLINE volatile PhyTrxState_t *phyMemPhyTrxState(void)
{
  return &macMem.phy.phyTrxState;
}

INLINE volatile PhyState_t *phyMemPhyState(void)
{
  return &macMem.phy.phyState;
}

INLINE volatile uint8_t *phyMemArbReqType(void)
{
  return &macMem.phy.phyArbReqType;
}

// For use in phyRxFrame.h only.
INLINE volatile uint8_t *phyMemRxByteCounter(void)
{
  return &macMem.phy.rxByteCounter;
}

// For use in phyRxFrame.h only.
INLINE volatile int8_t *phyMemRssi(void)
{
  return &macMem.phy.rssi;
}

#if defined(_FFD_) && defined(_CONTROL_FRAME_PENDING_BIT_)
INLINE volatile bool *phyMemAckedWithoutPendBit(void)
{
  return &macMem.phy.ackedWithoutPendBit;
}
#endif

#ifdef _CHILD_MANAGEMENT_
INLINE volatile bool *phyMemIsUnknownChild(void)
{
  return &macMem.phy.unknownChild;
}
#endif

INLINE volatile bool *phyArbTimeourAbortStatus(void)
{
	return &macMem.phy.arbTimeourAbortStatus;
}

/**************************************************************************//**
 \brief Returns current PHY arbiter mode.

 \return PHY arbiter mode
******************************************************************************/
INLINE uint8_t *phyMemPhyRadioArbMode(void)
{
  return &macMem.phy.radioArbMode;
}

/******************************************************************************
  Gets address of PHY memory.
  Parameters: none.
  returns: Address of PHY memory.
******************************************************************************/
INLINE PhyMem_t* phyGetMem(void)
{
  return &macMem.phy;
}

#endif // _PHYMEMACCESS_H

/* eof phyMemAccess.h*/

