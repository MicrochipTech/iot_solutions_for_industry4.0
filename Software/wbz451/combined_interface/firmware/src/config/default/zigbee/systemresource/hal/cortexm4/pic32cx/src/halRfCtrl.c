/*******************************************************************************
  HAL Radio Frequency Control Source File

  Company:
    Microchip Technology Inc.

  File Name:
    halRfCtrl.c

  Summary:
    This file provides Interface to the RF Control Registers to support the MAC and PHY
    functionality.

  Description:
    This file provides Interface to the RF Control Registers to support the MAC and PHY
    functionality.
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

/******************************************************************************
                        Includes section.
******************************************************************************/
#include "device.h"
#include <hal/cortexm4/pic32cx/include/halAppClock.h>
#include <hal/cortexm4/pic32cx/include/halRfCtrl.h>
#include <hal/cortexm4/pic32cx/include/halMacIsr.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
#define RF_REGISTER_READ_ACCESS_MODE      0x80
#define RF_REGISTER_TRX_STATUS_ADDRESS    0x01
#define RF_TRX_OFF_STATE                  0x08
#define RF_REGISTER_TRX_REG_ADDRESS       0x02

#define RF_PHY_IRQn                       30
/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief  Read transceiver state
******************************************************************************/
static uint8_t readTrxState(void);

/**************************************************************************//**
\brief  MAC RF interrupt handler
******************************************************************************/
void phyDispatcheRfInterrupt(void);

#ifdef _HAL_RF_RX_TX_INDICATOR_
/**************************************************************************//**
\brief  Turn on pin 1 (DIG3) and pin 2 (DIG4) to indicate the transmit state of
the radio transceiver.
******************************************************************************/
void phyRxTxSwitcherOn(void);

/**************************************************************************//**
\brief  Turn off pin 1 (DIG3) and pin 2 (DIG4) to indicate the transmit state of
the radio transceiver.
******************************************************************************/
void phyRxTxSwitcherOff(void);
#endif //_HAL_RF_RX_TX_INDICATOR_

#ifdef _HAL_ANT_DIVERSITY_
/**************************************************************************//**
\brief  Enable antenna diversity feature.
******************************************************************************/
void phyAntennaDiversityInit(void);

/**************************************************************************//**
\brief  Enable antenna diversity in the receive state of the radio transceiver.
******************************************************************************/
void phyRxAntennaDiversity(void);

/**************************************************************************//**
\brief  Enable antenna diversity in the transmit state of the radio transceiver.
******************************************************************************/
void phyTxAntennaDiversity(void);
/**************************************************************************//**
\brief  read the antenna used for last transmission and switch to other antenna 
******************************************************************************/
void phySwitchLastTxAntenna(void);
#else
/**************************************************************************//**
\brief  Select antenna 1/2 for next transmission or reception.
******************************************************************************/
int8_t PHY_SelectAntenna(uint8_t antenna);
#endif //_HAL_ANT_DIVERSITY_

/******************************************************************************
                    Implementations section
******************************************************************************/
/******************************************************************************
  Delay in us
******************************************************************************/
void HAL_Delay(uint8_t us)
{
  halDelayUs(us);
}

/******************************************************************************
  Clear the irq.
******************************************************************************/
void HAL_ClearRfIrqFlag(void)
{
  //halClearExtIrq((uint32_t)IRQ_RF_PIN);
  NVIC_ClearPendingIRQ((IRQn_Type)RF_PHY_IRQn);
}

/******************************************************************************
  Enables the irq.
******************************************************************************/
void HAL_EnableRfIrq(void)
{
 NVIC_EnableIRQ((IRQn_Type)RF_PHY_IRQn);
}

/******************************************************************************
  Disables the irq.
******************************************************************************/
uint8_t HAL_DisableRfIrq(void)
{
  NVIC_DisableIRQ((IRQn_Type)RF_PHY_IRQn);
  return 1;
}

/******************************************************************************
  Sets SLP_TR pin to 1.
******************************************************************************/
void HAL_SetRfSlpTr(void)
{
  //z_do_bitwr32(SUBSYS_CNTRL_REG0_ADDR, 0x1, 0x1); //Slp_tr bit in subsys
}

/******************************************************************************
  Clears SLP_TR pin to 0.
******************************************************************************/
void HAL_ClearRfSlpTr(void)
{
 // z_do_bitwr32(SUBSYS_CNTRL_REG0_ADDR, 0x1, 0x0);
}

/******************************************************************************
  Makes SLP_TR pin as input.
******************************************************************************/
void HAL_MakeInRfSlpTr(void)
{
  //GPIO_RF_SLP_TR_make_in();
}

/******************************************************************************
  Makes SLP_TR pin as input.
******************************************************************************/
void HAL_MakeOutRfSlpTr(void)
{
  //GPIO_RF_SLP_TR_make_out();
}

/******************************************************************************
  Sets RST_TR pin to 1.
******************************************************************************/
void HAL_SetRfRst(void)
{
  //GPIO_RF_RST_set();
}

/******************************************************************************
  Clears RST_TR pin to 1.
******************************************************************************/
void HAL_ClearRfRst(void)
{
  //GPIO_RF_RST_clr();
}

/******************************************************************************
  Init pins that controls RF chip.
******************************************************************************/
void HAL_InitRfPins(void)
{
  //GPIO_RF_SLP_TR_clr();
  //GPIO_RF_SLP_TR_make_out();

  //GPIO_RF_RST_set();
  //GPIO_RF_RST_make_out();
}

/******************************************************************************
  Init pins for CLKM
******************************************************************************/
void HAL_InitRfClkmPins(void)
{
  //PinConfig_t rfclkm;
  // Configure PIOs for RFCTRL 
  //rfclkm.portNum = PORT_C;
  //rfclkm.pinNum = 16;
  //rfclkm.functionConfig = 5;
  //GPIO_pinfunc_config(&rfclkm);
}

/******************************************************************************
  Dissable pins for CLKM
******************************************************************************/
void HAL_DissableRfClkmPins(void)
{
  //PinConfig_t rfclkm;
  // Configure PIOs for RFCTRL 
  //rfclkm.portNum = PORT_C;
  //rfclkm.pinNum = 16;
  //rfclkm.functionConfig = 0;
  //GPIO_pinfunc_config(&rfclkm);
}

/******************************************************************************
  Initialization rf irq.
******************************************************************************/
void ZB_HAL_InitRfIrq(void)
{
//  //enable BT_ZB_SUBSYS_IRQ_1 - Definition in startup_liberty
  NVIC_DisableIRQ((IRQn_Type)RF_PHY_IRQn);
  NVIC_SetPriority((IRQn_Type)RF_PHY_IRQn, 5);
  NVIC_ClearPendingIRQ((IRQn_Type)RF_PHY_IRQn);
  NVIC_EnableIRQ((IRQn_Type)RF_PHY_IRQn);
}

/******************************************************************************
  Returns current frequency code.
******************************************************************************/
HalSysFreq_t HAL_GetRfFreq(void)
{
#if ((CPU_CLK_HZ == 48000000) || (CPU_CLK_HZ == 64000000)) //Need check the usability of this func.
  return HAL_FREQ_8MHZ;
#else
  return HAL_FREQ_4MHZ;
#endif
}

/**************************************************************************//**
  \brief Wait for when radio will be waked up.

  \param none.
  \return none.
******************************************************************************/
void halWaitRadio(void)
{
  while(RF_TRX_OFF_STATE != readTrxState());
}

/**************************************************************************//**
\brief  Read transceiver state
******************************************************************************/
static uint8_t readTrxState(void)
{
  uint8_t tempValue = 0;
  // TODO:
  //(void) HAL_WriteByteRfSpi(RF_REGISTER_READ_ACCESS_MODE | RF_REGISTER_TRX_STATUS_ADDRESS);
  //tempValue = HAL_WriteByteRfSpi(tempValue);
  return tempValue;
}

/**************************************************************************//**
  \brief Check whether transceiver in TRX_OFF state
******************************************************************************/
bool halRadioInTrxOff(void)
{
  return (RF_TRX_OFF_STATE == readTrxState());

}

/**************************************************************************//**
  \brief Enables RX TX indicator for radio if that is supported.
******************************************************************************/
void HAL_EnableRxTxSwitcher(void)
{
  #ifdef _HAL_RF_RX_TX_INDICATOR_
    phyRxTxSwitcherOn();
  #endif //_HAL_RF_RX_TX_INDICATOR_
}

/**************************************************************************//**
  \brief Disables RX TX indicator for radio if that is supported.
******************************************************************************/
void HAL_DisableRxTxSwitcher(void)
{
  #ifdef _HAL_RF_RX_TX_INDICATOR_
    phyRxTxSwitcherOff();
  #endif //_HAL_RF_RX_TX_INDICATOR_
}

/*******************************************************************************
  Enables Transceiver clock
*******************************************************************************/
void HAL_EnableTransceiver(void)
{
  // todo
}

/**************************************************************************//**
  \brief Enables Antenna diversity option for radio if that is supported.
******************************************************************************/
#ifndef _PIC32CX_
void HAL_InitAntennaDiversity(void)
{
  bool pinConfigRequired;
  uint16_t rfCntrlFecfg;
  uint8_t antennaSelected;

  pinConfigRequired = BSP_BoardSpecificAntennaDiversityPinInit(&antennaSelected, &rfCntrlFecfg);

  if (pinConfigRequired)
  {
    /* Enable the clock of RFCTRL */
    //PM_APBCMASK |= PM_APBCMASK_RFCTRL;

    //RFCTRL_FECFG = rfCntrlFecfg;

#ifdef _HAL_ANT_DIVERSITY_
    phyAntennaDiversityInit();
#else
    (void) PHY_SelectAntenna(antennaSelected);
#endif
  }
}
#endif
/**************************************************************************//**
  \brief Enables Antenna diversity in RX mode for radio if that is supported.
******************************************************************************/
void HAL_EnableRxAntennaDiversity(void)
{
  #ifdef _HAL_ANT_DIVERSITY_
    phyRxAntennaDiversity();
  #endif //_HAL_ANT_DIVERSITY_
}

/**************************************************************************//**
  \brief Enables Antenna diversity in TX mode for radio if that is supported.
******************************************************************************/
void HAL_EnableTxAntennaDiversity(void)
{/* Commented out as Tx antenna diversity is not required */
/*  #ifdef _HAL_ANT_DIVERSITY_
    phyTxAntennaDiversity();
  #endif //_HAL_ANT_DIVERSITY_
*/
}

/**************************************************************************//**
  \brief To switch from the antenna used for last transmission to the other
******************************************************************************/
void HAL_SwitchLastTxAntenna(void)
{
  #ifdef _HAL_ANT_DIVERSITY_
    phySwitchLastTxAntenna();
  #endif //_HAL_ANT_DIVERSITY_
}

//eof halRfCtrl.c
