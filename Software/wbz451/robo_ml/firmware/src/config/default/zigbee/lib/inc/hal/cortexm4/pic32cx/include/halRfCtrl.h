/*******************************************************************************
  HAL RF Control Header File

  Company:
    Microchip Technology Inc.

  File Name:
    halRfCtrl.h

  Summary:
    This file contains the Types and constants declaration for IEEE802.15.4 
    PHY implementation.

  Description:
    This file contains the Types and constants declaration for IEEE802.15.4 
    PHY implementation.
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

/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/

#ifndef _HALRFCTRL_H
#define _HALRFCTRL_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  HAL_FREQ_NOCLK,
  HAL_FREQ_1MHZ,
  HAL_FREQ_2MHZ,
  HAL_FREQ_4MHZ,
  HAL_FREQ_8MHZ,
  HAL_FREQ_16MHZ
} HalSysFreq_t;

/******************************************************************************
                   Define(s) section
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/
/******************************************************************************
  Delay in us
******************************************************************************/
void HAL_Delay(uint8_t us);

/******************************************************************************
  Clear the irq.
******************************************************************************/
void HAL_ClearRfIrqFlag(void);

/******************************************************************************
  Enables the irq.
******************************************************************************/
void HAL_EnableRfIrq(void);

/******************************************************************************
  Disables the irq.
******************************************************************************/
uint8_t HAL_DisableRfIrq(void);

/******************************************************************************
  Sets SLP_TR pin to 1.
******************************************************************************/
void HAL_SetRfSlpTr(void);

/******************************************************************************
  Clears SLP_TR pin to 0.
******************************************************************************/
void HAL_ClearRfSlpTr(void);

/******************************************************************************
  Makes SLP_TR pin as input.
******************************************************************************/
void HAL_MakeInRfSlpTr(void);

/******************************************************************************
  Makes SLP_TR pin as input.
******************************************************************************/
void HAL_MakeOutRfSlpTr(void);

/******************************************************************************
  Sets RST_TR pin to 1.
******************************************************************************/
void HAL_SetRfRst(void);

/******************************************************************************
  Clears RST_TR pin to 1.
******************************************************************************/
void HAL_ClearRfRst(void);

/******************************************************************************
  Init pins that controls RF chip.
******************************************************************************/
void ZB_HAL_InitRfPins(void);

/******************************************************************************
  Initialization rf irq.
******************************************************************************/
void ZB_HAL_InitRfIrq(void);

/******************************************************************************
  Returns current frequency code.
******************************************************************************/
HalSysFreq_t HAL_GetRfFreq(void);

/**************************************************************************//**
  \brief Enables RX TX indicator for radio if that is supported.
******************************************************************************/
void HAL_EnableRxTxSwitcher(void);

/**************************************************************************//**
  \brief Disables RX TX indicator for radio if that is supported.
******************************************************************************/
void HAL_DisableRxTxSwitcher(void);

/*******************************************************************************
  Enables Transceiver clock
*******************************************************************************/
void HAL_EnableTransceiver(void);

/**************************************************************************//**
  \brief Enables Antenna diversity option for radio if that is supported.
******************************************************************************/
void ZB_HAL_InitAntennaDiversity(void);

/**************************************************************************//**
  \brief Enables Antenna diversity in RX mode for radio if that is supported.
******************************************************************************/
void HAL_EnableRxAntennaDiversity(void);

/**************************************************************************//**
  \brief Enables Antenna diversity in TX mode for radio if that is supported.
******************************************************************************/
void HAL_EnableTxAntennaDiversity(void);

/**************************************************************************//**
  \brief To switch from the antenna used for last transmission to the other
******************************************************************************/
void HAL_SwitchLastTxAntenna(void);

/**************************************************************************//**
  \brief Wait for when radio will be waked up.
******************************************************************************/
void halWaitRadio(void);

/**************************************************************************//**
  \brief Check whether transceiver in TRX_OFF state
******************************************************************************/
bool halRadioInTrxOff(void);

/******************************************************************************
  \brief Init pins for CLKM
******************************************************************************/
void ZB_HAL_InitRfClkmPins(void);

/******************************************************************************
  Disable pins for CLKM
******************************************************************************/
void HAL_DissableRfClkmPins(void);

/**************************************************************************//**
  \brief EIC IRQ handler to handle RF IRQ 
******************************************************************************/

void EIC_Handler(void);

/**************************************************************************//**
  \brief Pin configuration forAntenna diversity feature
******************************************************************************/
bool BSP_BoardSpecificAntennaDiversityPinInit(uint8_t* antennaSelected, uint16_t* pRfCntrlFecfg);

/**************************************************************************//**
\brief Checks whether Ant Div actions reuired based on the board and ant div enabled or not
******************************************************************************/
bool BSP_IsAntDiversityActionsRequired(void);

#endif /* _HALRFCTRL_H */

// eof halRfCtrl.h
