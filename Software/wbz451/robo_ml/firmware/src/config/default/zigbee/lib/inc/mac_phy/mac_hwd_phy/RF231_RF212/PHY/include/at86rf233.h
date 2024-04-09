/*******************************************************************************
  AT86Rf233 Header File

  Company:
    Microchip Technology Inc.

  File Name:
    at86rf233.h
  Summary:
    This file contains the Declarations for Microchip AT86RF233.

  Description:
    This file contains the Declarations for Microchip AT86RF233 transceiver parameters.
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

#ifndef _AT86RF233_H_
#define _AT86RF233_H_

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysEndian.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/at86rf233.h>

/******************************************************************************
                    Common definitions
******************************************************************************/
/* Mask which defines supported channels */
#define RF_SUPPORTED_CHANNELS   0x07fff800
/* Minimum channel number */
#define RF_MIN_CHANNEL          11
/* Maximum channel number */
#define RF_MAX_CHANNEL          26
/* Minimum RSSI sensitivity */
#define AT86RF231_RSSI_BASE_VAL (-94)

#define DEVICE_ID_TYPE      0x0000F000
#define DEVICE_ID_MPA_TYPE  0x0000F000
#define DEVICE_ID_LPA_TYPE  0x0000B000

#define CS_DEVICE_POWER_MPA_LPA 0x0F
#define CS_DEVICE_POWER_LPA_ONLY 0x0B


/******************************************************************************
                    Registers addresses
******************************************************************************/
#ifdef _PIC32CX_

#define WIRELESS_ZBT_BASEADDR   0x41010000UL  

#define ZB_BASEADDR        (WIRELESS_ZBT_BASEADDR + 0x0000)    //0x4101_0000 ~ 0x4101_0FFF; 4KB size
#define ARB_BASEADDR       (WIRELESS_ZBT_BASEADDR + 0x1000)    //0x4101_1000 ~ 0x4101_1FFF; 4KB size
#define BT_BASEADDR        (WIRELESS_ZBT_BASEADDR + 0x2000)    //0x4101_2000 ~ 0x4101_2FFF; 4KB size
#define BT1_BASEADDR       (WIRELESS_ZBT_BASEADDR + 0x2000)    //0x4101_2000 ~ 0x4101_2FFF; 4KB size
#define BT2_BASEADDR       (WIRELESS_ZBT_BASEADDR + 0x3000)    //0x4101_3000 ~ 0x4101_3FFF; 4KB size
#define SUBSYS_BASEADDR    (WIRELESS_ZBT_BASEADDR + 0x4000)    //0x4101_4000 ~ 0x4101_4FFF; 4KB size

#define ZB_FRAME_BUFFER_SIZE            127     // Bytes
#define ZB_TX_FRAME_BUFFER_OFFSET       0x100
#define ZB_RX_FRAME_BUFFER_OFFSET       0x200
#define ZB_RX_FRAME_LENGTH_OFFSET       0x280

#define ZB_TX_FRAME_BUFFER_ADDR         ZB_BASEADDR + ZB_TX_FRAME_BUFFER_OFFSET    //0x4202_2100 ~ 0x4202_217F     // 127 Bytes
#define ZB_RX_FRAME_BUFFER_ADDR         ZB_BASEADDR + ZB_RX_FRAME_BUFFER_OFFSET    //0x4202_2100 ~ 0x4202_217F     // 127 Bytes
#define ZB_RX_FRAME_LENGTH              ZB_BASEADDR + ZB_RX_FRAME_LENGTH_OFFSET

#define SUBSYS_ZB_EN_MAIN_CLK_16MHZ     (1 << 4)        // B2782285.PNG

/*Register Map*/
#define TRX_STATUS_OFFSET     0x01
#define	TRX_STATE_OFFSET      0x02
#define	TRX_CTRL_0_OFFSET     0x03
#define	TRX_CTRL_1_OFFSET     0x04
#define	PHY_TX_PWR_OFFSET     0x05
#define	PHY_RSSI_OFFSET       0x06
#define	PHY_ED_LEVEL_OFFSET   0x07
#define	PHY_CC_CCA_OFFSET     0x08
#define	CCA_THRESH_OFFSET     0x09
#define	RX_CTRL_OFFSET        0x0A
#define	SFD_VALUE_OFFSET      0x0B
#define	TRX_CTRL_2_OFFSET     0x0C
#define	ANT_DIV_OFFSET        0x0D
#define	IRQ_MASK_OFFSET       0x0E
#define	IRQ_STATUS_OFFSET     0x0F
#define	VREG_CTRL_OFFSET      0x10
#define	BATMON_OFFSET         0x11
#define	XOSC_CTRL_OFFSET      0x12
#define	CC_CTRL_0_OFFSET      0x13
#define	CC_CTRL_1_OFFSET      0x14
#define	RX_SYN_OFFSET         0x15
#define	TRX_RPC_OFFSET        0x16
#define	XAH_CTRL_OFFSET       0x17
#define	FTN_CTRL_OFFSET       0x18
#define	XAH_CTRL_2_OFFSET     0x19
#define	PLL_CF_OFFSET         0x1A
#define	PLL_DCU_OFFSET        0x1B
#define	PART_NUM_OFFSET       0x1C
#define	VERSION_NUM_OFFSET    0x1D
#define	MAN_ID_0_OFFSET       0x1E
#define	MAN_ID_1_OFFSET       0x1F
#define	SHORT_ADDR_0_OFFSET   0x20
#define	SHORT_ADDR_1_OFFSET   0x21
#define	PAN_ID_0_OFFSET       0x22
#define	PAN_ID_1_OFFSET       0x23
#define	IEEE_ADDR_0_OFFSET    0x24
#define	IEEE_ADDR_1_OFFSET    0x25
#define	IEEE_ADDR_2_OFFSET    0x26
#define	IEEE_ADDR_3_OFFSET    0x27
#define	IEEE_ADDR_4_OFFSET    0x28
#define	IEEE_ADDR_5_OFFSET    0x29
#define	IEEE_ADDR_6_OFFSET    0x2A
#define	IEEE_ADDR_7_OFFSET    0x2B
#define	XAH_CTRL_0_OFFSET     0x2C
#define	CSMA_SEED_0_OFFSET    0x2D
#define	CSMA_SEED_1_OFFSET    0x2E
#define	CSMA_BE_OFFSET        0x2F
#define	TEST_CTRL_DIGI_OFFSET 0x36
#define ZB_RADIO_CTRL_IRQ_STATUS_OFFSET 0x40
#define ZB_RADIO_CTRL_OFFSET  0x42
#define ZB_RADIO_CTRL_1_OFFSET  0x43
#define ZB_RADIO_CTRL_2_OFFSET  0x44
#define ZB_RADIO_CTRL_3_OFFSET  0x45
#define ZB_RADIO_CTRL_4_OFFSET  0x46
#define ZB_RADIO_CTRL_5_OFFSET  0x47
#define ZB_RADIO_CTRL_6_OFFSET  0x48
#define ZB_RADIO_CTRL_7_OFFSET  0x49
#define ZB_RADIO_CTRL_8_OFFSET  0x4A
#define ZB_RADIO_CTRL_9_OFFSET  0x4B
#define ZB_RADIO_CTRL_10_OFFSET  0x4C
#define RX_FRAME_LENGTH_OFFSET 0x280

//TODO - To Clean Up and Map
#define TRX_STATUS_REG    TRX_STATUS_OFFSET     //MMIO_REG(ZB_BASEADDR + TRX_STATUS_OFFSET    , uint8_t)
#define TRX_STATE_REG     TRX_STATE_OFFSET      //MMIO_REG((ZB_BASEADDR + TRX_STATE_OFFSET)     , uint8_t)
#define TRX_CTRL_0_REG    TRX_CTRL_0_OFFSET     //MMIO_REG((ZB_BASEADDR + TRX_CTRL_0_OFFSET)    , uint8_t)
#define TRX_CTRL_1_REG    TRX_CTRL_1_OFFSET     //MMIO_REG(ZB_BASEADDR + TRX_CTRL_1_OFFSET    , uint8_t)
#define PHY_TX_PWR_REG    PHY_TX_PWR_OFFSET     //MMIO_REG(ZB_BASEADDR + PHY_TX_PWR_OFFSET    , uint8_t)
#define PHY_RSSI_REG      PHY_RSSI_OFFSET       //MMIO_REG(ZB_BASEADDR + PHY_RSSI_OFFSET      , uint8_t)
#define PHY_ED_LEVEL_REG  PHY_ED_LEVEL_OFFSET   //MMIO_REG(ZB_BASEADDR + PHY_ED_LEVEL_OFFSET  , uint8_t)
#define PHY_CC_CCA_REG    PHY_CC_CCA_OFFSET     //MMIO_REG(ZB_BASEADDR + PHY_CC_CCA_OFFSET    , uint8_t)
#define CCA_THRESH_REG    CCA_THRESH_OFFSET     //MMIO_REG(ZB_BASEADDR + CCA_THRESH_OFFSET    , uint8_t)
#define RX_CTRL_REG       RX_CTRL_OFFSET        //MMIO_REG(ZB_BASEADDR + RX_CTRL_OFFSET       , uint8_t)
#define SFD_VALUE_REG     SFD_VALUE_OFFSET      //MMIO_REG(ZB_BASEADDR + SFD_VALUE_OFFSET     , uint8_t)
#define TRX_CTRL_2_REG    TRX_CTRL_2_OFFSET     //MMIO_REG(ZB_BASEADDR + TRX_CTRL_2_OFFSET    , uint8_t)
#define ANT_DIV_REG       ANT_DIV_OFFSET        //MMIO_REG(ZB_BASEADDR + ANT_DIV_OFFSET       , uint8_t)
#define IRQ_MASK_REG      IRQ_MASK_OFFSET       //MMIO_REG(ZB_BASEADDR + IRQ_MASK_OFFSET      , uint8_t)
#define IRQ_STATUS_REG    IRQ_STATUS_OFFSET     //MMIO_REG(ZB_BASEADDR + IRQ_STATUS_OFFSET    , uint8_t)
#define VREG_CTRL_REG     VREG_CTRL_OFFSET      //MMIO_REG(ZB_BASEADDR + VREG_CTRL_OFFSET     , uint8_t)
#define BATMON_REG        BATMON_OFFSET         //MMIO_REG(ZB_BASEADDR + BATMON_OFFSET        , uint8_t)
#define XOSC_CTRL_REG     XOSC_CTRL_OFFSET      //MMIO_REG(ZB_BASEADDR + XOSC_CTRL_OFFSET     , uint8_t)
#define CC_CTRL_0_REG     CC_CTRL_0_OFFSET      //MMIO_REG(ZB_BASEADDR + CC_CTRL_0_OFFSET     , uint8_t)
#define CC_CTRL_1_REG     CC_CTRL_1_OFFSET      //MMIO_REG(ZB_BASEADDR + CC_CTRL_1_OFFSET     , uint8_t)
#define RX_SYN_REG        RX_SYN_OFFSET         //MMIO_REG(ZB_BASEADDR + RX_SYN_OFFSET        , uint8_t)
#define TRX_RPC_REG       TRX_RPC_OFFSET        //MMIO_REG(ZB_BASEADDR + TRX_RPC_OFFSET       , uint8_t)
#define XAH_CTRL_REG      XAH_CTRL_OFFSET       //MMIO_REG(ZB_BASEADDR + XAH_CTRL_OFFSET      , uint8_t)
#define FTN_CTRL_REG      FTN_CTRL_OFFSET       //MMIO_REG(ZB_BASEADDR + FTN_CTRL_OFFSET      , uint8_t)
#define XAH_CTRL_2_REG    XAH_CTRL_2_OFFSET     //MMIO_REG(ZB_BASEADDR + XAH_CTRL_2_OFFSET    , uint8_t)
#define PLL_CF_REG        PLL_CF_OFFSET         //MMIO_REG(ZB_BASEADDR + PLL_CF_OFFSET        , uint8_t)
#define PLL_DCU_REG       PLL_DCU_OFFSET        //MMIO_REG(ZB_BASEADDR + PLL_DCU_OFFSET       , uint8_t)
#define PART_NUM_REG      PART_NUM_OFFSET       //MMIO_REG(ZB_BASEADDR + PART_NUM_OFFSET      , uint8_t)
#define VERSION_NUM_REG   VERSION_NUM_OFFSET    //MMIO_REG(ZB_BASEADDR + VERSION_NUM_OFFSET   , uint8_t)
#define MAN_ID_0_REG      MAN_ID_0_OFFSET       //MMIO_REG(ZB_BASEADDR + MAN_ID_0_OFFSET      , uint8_t)
#define MAN_ID_1_REG      MAN_ID_1_OFFSET       //MMIO_REG(ZB_BASEADDR + MAN_ID_1_OFFSET      , uint8_t)
#define SHORT_ADDR_0_REG  SHORT_ADDR_0_OFFSET   //MMIO_REG(ZB_BASEADDR + SHORT_ADDR_0_OFFSET  , uint8_t)
#define SHORT_ADDR_1_REG  SHORT_ADDR_1_OFFSET   //MMIO_REG(ZB_BASEADDR + SHORT_ADDR_1_OFFSET  , uint8_t)
#define PAN_ID_0_REG      PAN_ID_0_OFFSET       //MMIO_REG(ZB_BASEADDR + PAN_ID_0_OFFSET      , uint8_t)
#define PAN_ID_1_REG      PAN_ID_1_OFFSET       //MMIO_REG(ZB_BASEADDR + PAN_ID_1_OFFSET      , uint8_t)
#define IEEE_ADDR_0_REG   IEEE_ADDR_0_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_0_OFFSET   , uint8_t)
#define IEEE_ADDR_1_REG   IEEE_ADDR_1_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_1_OFFSET   , uint8_t)
#define IEEE_ADDR_2_REG   IEEE_ADDR_2_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_2_OFFSET   , uint8_t)
#define IEEE_ADDR_3_REG   IEEE_ADDR_3_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_3_OFFSET   , uint8_t)
#define IEEE_ADDR_4_REG   IEEE_ADDR_4_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_4_OFFSET   , uint8_t)
#define IEEE_ADDR_5_REG   IEEE_ADDR_5_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_5_OFFSET   , uint8_t)
#define IEEE_ADDR_6_REG   IEEE_ADDR_6_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_6_OFFSET   , uint8_t)
#define IEEE_ADDR_7_REG   IEEE_ADDR_7_OFFSET    //MMIO_REG(ZB_BASEADDR + IEEE_ADDR_7_OFFSET   , uint8_t)
#define XAH_CTRL_0_REG    XAH_CTRL_0_OFFSET     //MMIO_REG(ZB_BASEADDR + XAH_CTRL_0_OFFSET    , uint8_t)
#define CSMA_SEED_0_REG   CSMA_SEED_0_OFFSET    //MMIO_REG(ZB_BASEADDR + CSMA_SEED_0_OFFSET   , uint8_t)
#define CSMA_SEED_1_REG   CSMA_SEED_1_OFFSET    //MMIO_REG(ZB_BASEADDR + CSMA_SEED_1_OFFSET   , uint8_t)
#define CSMA_BE_REG       CSMA_BE_OFFSET        //MMIO_REG(ZB_BASEADDR + CSMA_BE_OFFSET       , uint8_t)
#define TEST_CTRL_DIGI    TEST_CTRL_DIGI_OFFSET //MMIO_REG(ZB_BASEADDR + TEST_CTRL_DIGI_OFFSET, uint8_t)
#define ZB_RADIO_CTRL_IRQ_STATUS_REG ZB_RADIO_CTRL_IRQ_STATUS_OFFSET
#define ZB_RADIO_CTRL_REG ZB_RADIO_CTRL_OFFSET
#define ZB_RADIO_CTRL_1_REG ZB_RADIO_CTRL_1_OFFSET
#define ZB_RADIO_CTRL_2_REG ZB_RADIO_CTRL_2_OFFSET
#define ZB_RADIO_CTRL_3_REG ZB_RADIO_CTRL_3_OFFSET
#define ZB_RADIO_CTRL_4_REG ZB_RADIO_CTRL_4_OFFSET
#define ZB_RADIO_CTRL_5_REG ZB_RADIO_CTRL_5_OFFSET
#define ZB_RADIO_CTRL_6_REG ZB_RADIO_CTRL_6_OFFSET
#define ZB_RADIO_CTRL_7_REG ZB_RADIO_CTRL_7_OFFSET
#define ZB_RADIO_CTRL_8_REG ZB_RADIO_CTRL_8_OFFSET
#define ZB_RADIO_CTRL_9_REG ZB_RADIO_CTRL_9_OFFSET
#define ZB_RADIO_CTRL_10_REG ZB_RADIO_CTRL_10_OFFSET
#define RX_FRAME_LENGTH   RX_FRAME_LENGTH_OFFSET//MMIO_REG(ZB_BASEADDR + RX_FRAME_LENGTH_OFFSET, uint8_t)

#define ZB_RADIO_CTRL_8_REG_ADDR                (ZB_RADIO_CTRL_8_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_9_REG_ADDR                (ZB_RADIO_CTRL_9_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_6_REG_ADDR                (ZB_RADIO_CTRL_6_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_5_REG_ADDR                (ZB_RADIO_CTRL_5_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_REG_ADDR                  (ZB_RADIO_CTRL_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_3_REG_ADDR                (ZB_RADIO_CTRL_3_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_4_REG_ADDR                (ZB_RADIO_CTRL_4_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_7_REG_ADDR                (ZB_RADIO_CTRL_7_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_10_REG_ADDR               (ZB_RADIO_CTRL_10_OFFSET + ZB_BASEADDR)
#define ZB_MAC_RAD_CTRL_IRQ_MASK_ADDR           (ZB_MAC_RAD_CTRL_IRQ_MASK_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_IRQ_STATUS_REG_ADDR       (ZB_RADIO_CTRL_IRQ_STATUS_OFFSET + ZB_BASEADDR)
#define ZB_RADIO_CTRL_9_REG_ADDR                (ZB_RADIO_CTRL_9_OFFSET + ZB_BASEADDR)

#define COMMON_MEMORY_ADDR              0x20010000UL


#if 1 //def _ACTUAL_FPGA_
#define ZBT_ARBITER_ADDR                            0x41011000
#define BT_BB_BASE_ADDR                             0x41012000
#define SUBSYS_BASE_ADDR                            0x41014000
#else
#define BT_BB_BASE_ADDR                             0x42020000
#define SUBSYS_BASE_ADDR                            0x42024000
#define ZBT_ARBITER_ADDR                            0x42023000
#endif

#define ZB_FRAME_BUFFER_SIZE            127     // Bytes
#define ZB_TX_FRAME_BUFFER_OFFSET       0x100
#define ZB_RX_FRAME_BUFFER_OFFSET       0x200
#define ZB_TX_FRAME_BUFFER_ADDR         ZB_BASEADDR + ZB_TX_FRAME_BUFFER_OFFSET    //0x4202_2100 ~ 0x4202_217F     // 127 Bytes
#define ZB_RX_FRAME_BUFFER_ADDR         ZB_BASEADDR + ZB_RX_FRAME_BUFFER_OFFSET    //0x4202_2100 ~ 0x4202_217F     // 127 Bytes
#define SUBSYS_ZB_EN_MAIN_CLK_16MHZ     (1 << 4)        // B2782285.PNG


#define SUBSYS_CNTRL_REG0               (SUBSYS_BASE_ADDR)
#define SUBSYS_CNTRL_REG1               (SUBSYS_BASE_ADDR + 0x4)
#define SUBSYS_STATUS_REG0              (SUBSYS_BASE_ADDR + 0x20)
#define SUBSYS_STATUS_REG1              (SUBSYS_BASE_ADDR + 0x24)
#define RADIO_ARBITER_BT_CONTROL        (ZBT_ARBITER_ADDR + 0x0)
#define RADIO_ARBITER_ZB_CONTROL        (ZBT_ARBITER_ADDR + 0x4)
#define RADIO_ARBITER_EVENT_CONTROL     (ZBT_ARBITER_ADDR + 0x8)
#define RADIO_ARBITER_CORE_CONTROL_ADDR (ZBT_ARBITER_ADDR + 0xC)
#define RADIO_ARBITER_CORE_STATUS_ADDR  (ZBT_ARBITER_ADDR + 0x10)
#define RADIO_ARBITER_INT_STATUS        (ZBT_ARBITER_ADDR + 0x14)
#define RADIO_ARBITER_INT_MASK          (ZBT_ARBITER_ADDR + 0x18)
#define DIRECT_RFIELD_IF_FREQ           (ZBT_ARBITER_ADDR + 0x1704)

#define DIRECT_RFIELD_IQ_EPS_THETA  0x42021766
 //DIRECT_RFIELD_IQ_THETA = 0xB

#define DIRECT_RFIELD_DPLL_RG2_OFFSET                   0x04BA
#define DIRECT_RFIELD_BYPASS_MEM_ACCESS_BRIDGE_OFFSET   0x044E

#define DIRECT_RFIELD_DPLL_RG2                          (BT_BB_BASE_ADDR + DIRECT_RFIELD_DPLL_RG2_OFFSET)
#define DIRECT_RFIELD_BYPASS_MEM_ACCESS_BRIDGE          (BT_BB_BASE_ADDR + DIRECT_RFIELD_BYPASS_MEM_ACCESS_BRIDGE_OFFSET)

#define _nop_  __asm volatile ( "nop" )

//#define BT_RF_Control_Register_RF_CTRL_ll_addr                           ( BT_MAC_BASE_ADDR + 0x1000)
//#define BT_rf_control_register_rf_ctrl_2_hl_addr                         ( BT_MAC_BASE_ADDR + 0x1002)
//#define BT_rf_programming_register_rfprog_hl_addr                        ( BT_MAC_BASE_ADDR + 0x1006)
//#define BT_ana_ip_ctrl_reg2_hl_addr                                      ( BT_MAC_BASE_ADDR + 0x04ba)
//#define BT_SiWData_ll_addr                                               ( BT_MAC_BASE_ADDR + 0x1028)

//Radio Reg
#define Radio_Arbiter_BT_Control_Addr         ARB_BASEADDR + 0x000
#define Radio_Arbiter_ZB_Control_Addr         ARB_BASEADDR + 0x004
#define Radio_Arbiter_Event_Control_Addr      ARB_BASEADDR + 0x008
#define Radio_Arbiter_Core_Control_Addr       ARB_BASEADDR + 0x00C
#define Radio_Arbiter_Core_Status_Addr        ARB_BASEADDR + 0x010
#define Radio_Arbiter_Interrupt_Status_Addr   ARB_BASEADDR + 0x014
#define Radio_Arbiter_Interrupt_Mask_Addr     ARB_BASEADDR + 0x018

#define ZB_ABORTED_FOR_HIGH_PRIO_BT         0x002
#define ZB_ABORTED_RADIO_TIMEOUT_RECEIVED   0x008
#define ZB_TIME_SENS_REQ_LOST               0x020
#define BT_TIME_SENS_REQ_LOST               0x010
#define BT_ABORTED_FOR_HIGH_PRIO_ZB         0x001
#define BT_ABORTED_RADIO_TIMEOUT_RECEIVED   0x004
#define COLLISION_PREDICTED                 0x040
#define IDLE_INT                            0x080


// Arbiter Core Status
#define ARBITER_ZB_GRANT_STATE 0x01
#define RADIO_OWNER_ZB_LINK    0x04

//BT SubSystem
#define  SUBSYS_STATS_REG1_ADDR  (SUBSYS_BASE_ADDR + 0x24) // R
#define  SUBSYS_CNTRL_REG0_ADDR  (SUBSYS_BASE_ADDR + 0x00) // RW
#define  SUBSYS_CNTRL_REG1_ADDR  (SUBSYS_BASE_ADDR + 0x04) // RW
#define  SUBSYS_CNTRL_REG2_ADDR  (SUBSYS_BASE_ADDR + 0x08) // RW
#define  SUBSYS_CNTRL_REG3_ADDR  (SUBSYS_BASE_ADDR + 0x0C) // RW
#define  SUBSYS_STATS_REG0_ADDR  (SUBSYS_BASE_ADDR + 0x20) // R
#define  SUBSYS_STATS_REG1_ADDR  (SUBSYS_BASE_ADDR + 0x24) // R

//#define ZB_TX_RAM                     ZB_BASEADDR + 0x100
#define ZB_MAC_TRX_STATUS               ZB_BASEADDR + 0x01
#define ZB_MAC_TRX_STATE                ZB_BASEADDR + 0x02  //N
#define ZB_MAC_TRX_CTRL_0               ZB_BASEADDR + 0x03 //N
#define ZB_MAC_TRX_CTRL_1               ZB_BASEADDR + 0x04 //N
#define ZB_MAC_PHY_RSSI                 ZB_BASEADDR + 0x06
#define ZB_MAC_PHY_ED_LEVEL             ZB_BASEADDR + 0x07
#define ZB_MAC_PHY_CCA                  ZB_BASEADDR + 0x08
#define ZB_MAC_CCA_THRES                ZB_BASEADDR + 0x09
//PHY_CC_CCA
//PHY_CC_CCA

#define ZB_MAC_RX_CTRL                ZB_BASEADDR + 0x0A
#define ZB_MAC_TRX_CTRL_2             ZB_BASEADDR + 0x0C
#define ZB_MAC_IRQ_MASK               ZB_BASEADDR + 0x0E //N
#define ZB_MAC_IRQ_STATUS             ZB_BASEADDR + 0x0F //N
#define ZB_MAC_MISC_0                 ZB_BASEADDR + 0x11 //N
#define  ZB_MAC_TRX_RPC               ZB_BASEADDR + 0x16
//#define ZB_MAC_PART_NUM               ZB_BASEADDR + 0x1C
//#define ZB_MAC_VERSION_NUM            ZB_BASEADDR + 0x1D
#define ZB_MAC_XAH_CTRL_1             ZB_BASEADDR + 0x17 //N
#define ZB_MAC_XAH_CTRL_2             ZB_BASEADDR + 0x19 //N
#define ZB_MAC_SHORT_LOWER            ZB_BASEADDR + 0x20        
#define ZB_MAC_SHORT_UPPER            ZB_BASEADDR + 0x21
#define ZB_MAC_PANID_LOWER            ZB_BASEADDR + 0x22 
#define ZB_MAC_PANID_UPPER            ZB_BASEADDR + 0x23

#define ZB_MAC_IEEE_0                 ZB_BASEADDR + 0x24
#define ZB_MAC_IEEE_1                 ZB_BASEADDR + 0x25
#define ZB_MAC_IEEE_2                 ZB_BASEADDR + 0x26
#define ZB_MAC_IEEE_3                 ZB_BASEADDR + 0x27
#define ZB_MAC_IEEE_4                 ZB_BASEADDR + 0x28
#define ZB_MAC_IEEE_5                 ZB_BASEADDR + 0x29
#define ZB_MAC_IEEE_6                 ZB_BASEADDR + 0x2A
#define ZB_MAC_IEEE_7                 ZB_BASEADDR + 0x2B

#define ZB_MAC_XAH_CTRL_0             ZB_BASEADDR + 0x2C
#define ZB_MAC_CSMA_SEED_0            ZB_BASEADDR + 0x2D
#define ZB_MAC_CSMA_SEED_1            ZB_BASEADDR + 0x2E
#define ZB_MAC_CSMA_BE                ZB_BASEADDR + 0x2F


//#define ZB_TST_SDM                    ZB_BASEADDR + 0x3D
#define ZB_MAC_RAD_CTRL_IRQ_MASK        ZB_BASEADDR + 0x41  //N ???
#define ZB_MAC_RAD_CTRL_IRQ_STATUS      ZB_BASEADDR + 0x40 
#define ZB_MAC_ZB_RADIO_CTRL            ZB_BASEADDR + 0x42 //N
#define ZB_MAC_ZB_RADIO_CTRL_2          ZB_BASEADDR + 0x44 //N
#define ZB_MAC_ZB_RADIO_STAT_0          ZB_BASEADDR + 0x4D //N

#define ZB_MAC_TX_MODEM_0               ZB_BASEADDR + 0xA0 //N
#define ZB_MAC_TX_MODEM_1               ZB_BASEADDR + 0xA1 //N
#define ZB_MAC_TX_MODEM_2               ZB_BASEADDR + 0xA2 //N
#define ZB_MAC_TX_MODEM_3               ZB_BASEADDR + 0xA3 //N
#define ZB_MAC_TX_MODEM_4               ZB_BASEADDR + 0xA4 //N
#define ZB_MAC_TX_MODEM_5               ZB_BASEADDR + 0xA5 //N
#define ZB_MAC_PHY_TX_PWR               ZB_BASEADDR + 0x05
#define ZB_MAC_PART_NUM                 ZB_BASEADDR + 0x1C
#define ZB_MAC_DDP_ACT_0                ZB_BASEADDR + 0xB0
#define ZB_MAC_DDP_ACT_1                ZB_BASEADDR + 0xB1
#define ZB_MAC_DDP_ACT_2                ZB_BASEADDR + 0xB2
#define ZB_MAC_DDP_XAH_0                ZB_BASEADDR + 0xB3
#define ZB_MAC_DDP_0                    ZB_BASEADDR + 0xB4
#define ZB_MAC_DDP_1                    ZB_BASEADDR + 0xB5
#define ZB_MAC_DDP_2                    ZB_BASEADDR + 0xB6
#define ZB_MAC_DDP_3                    ZB_BASEADDR + 0xB7
#define ZB_MAC_DDP_4                    ZB_BASEADDR + 0xB8
#define ZB_MAC_DDP_5                    ZB_BASEADDR + 0xB9
#define ZB_MAC_DDP_8                    ZB_BASEADDR + 0xBC
#define ZB_MAC_DDP_9                    ZB_BASEADDR + 0xBD
#define ZB_MAC_DDP_10                   ZB_BASEADDR + 0xBE
#define ZB_MAC_DDP_11                   ZB_BASEADDR + 0xBF
#define ZB_MAC_AGC_0                    ZB_BASEADDR + 0xC0
#define ZB_MAC_AGC_1                    ZB_BASEADDR + 0xC1
#define ZB_MAC_AGC_2                    ZB_BASEADDR + 0xC2
#define ZB_MAC_AGC_3                    ZB_BASEADDR + 0xC3
#define ZB_MAC_AGC_4                    ZB_BASEADDR + 0xC4
#define ZB_MAC_AGC_5                    ZB_BASEADDR + 0xC5
#define ZB_MAC_AGC_6                    ZB_BASEADDR + 0xC6
#define ZB_MAC_AGC_7                    ZB_BASEADDR + 0xC7
#define ZB_MAC_AGC_8                    ZB_BASEADDR + 0xC8
#define ZB_MAC_AGC_9                    ZB_BASEADDR + 0xC9
#define ZB_MAC_AGC_10                   ZB_BASEADDR + 0xCA
#define ZB_MAC_AGC_11                   ZB_BASEADDR + 0xCB
#define ZB_MAC_AGC_12                   ZB_BASEADDR + 0xCC
#define ZB_MAC_AGC_13                   ZB_BASEADDR + 0xCD
#define ZB_MAC_AGC_14                   ZB_BASEADDR + 0xCE
#define ZB_MAC_AGC_15                   ZB_BASEADDR + 0xCF
#define ZB_MAC_AGC_16                   ZB_BASEADDR + 0xD0
#define ZB_MAC_AGC_17                   ZB_BASEADDR + 0xD1
#define ZB_MAC_AGC_18                   ZB_BASEADDR + 0xD2
#define ZB_MAC_AGC_19                   ZB_BASEADDR + 0xD3
#define ZB_MAC_AGC_20                   ZB_BASEADDR + 0xD4
#define ZB_MAC_AGC_21                   ZB_BASEADDR + 0xD5
#define ZB_MAC_AGC_22                   ZB_BASEADDR + 0xD6
#define ZB_MAC_AGC_23                   ZB_BASEADDR + 0xD7
#define ZB_MAC_AGC_24                   ZB_BASEADDR + 0xD8

#define ZB_MAC_RAD_CTRL_IRQ_STATUS_OFFSET 0x40

//Arbitration Definitions
#define ZB_ARB_RADIO_GRANT_RECEIVED    0x01
#define ZB_ARB_RADIO_GRANT_TIMEOUT     0x02
#define ZB_ARB_RADIO_ABORT_REQUEST     0x04
#define ZB_ARB_RADIO_CCA_RETRY_FORCED  0x08
#define ZB_ARB_RADIO_TASK_DONE         0x10
#define ZB_ARB_RADIO_GRANT_XACS_DONE   0x20 
#define ZB_ARB_RADIO_UNREG_INT_6       0x40
#define ZB_ARB_RADIO_UNREG_INT_7       0x80

//Arbitration / Custom Definitions
#define ARB_RADIO_USE_CASE_GRANT_RECEIVED    1
#define ARB_RADIO_USE_CASE_GRANT_TIMEOUT     2
#define ARB_RADIO_USE_CASE_ABORT_REQUEST     3
#define ARB_RADIO_USE_CASE_CCA_RETRY_FORCED  4
#define ARB_RADIO_USE_CASE_TASK_DONE         5
#define ARB_RADIO_USE_CASE_GRANT_XACS_DONE   6 
#define ARB_RADIO_USE_CASE_UNREG_INT_6       7
#define ARB_RADIO_USE_CASE_UNREG_INT_7       8
#define ARB_RADIO_USE_CASE_ZB_ABORT_HIGH_PRIO_BT 9
#define ARB_RADIO_USE_CASE_ZB_ABORTED_TIMEOUT  10
#define ARB_RADIO_USE_CASE_ZB_TIME_SEN_LOST 11
#define ARB_RADIO_USE_CASE_COLLISION_PRED 12

//ZB Radio controller FSM state 
#define RF_IDLE          0x00
#define PASS_CMD         0x10
#define GEN_RADIO_REQ    0x20
#define WAIT_GRANT       0x30 
#define WAIT_FOR_DONE    0x40  
#define GRANT_TIMEOUT    0x50  
#define REQ_ABORT        0x60  
#define BACKOFF_WAIT     0x70  
#define WAIT_ABORT_DONE  0x80  
#define DUMMY_DONE       0x90  
#define FORCE_CCA_RETRY  0xA0  
#define WAIT_PLL_WAKEUP  0xB0  
#define NEXT_RADIO_REQ   0xC0  
#define WAIT_XAH_STATE   0xD0  
#define TASK_DONE        0xE0

#define ZB_MAC_ZB_RADIO_STAT_0_OFFSET   0x4D

#else

/* Common register addresses */
#define TRX_STATUS_REG    0x01
#define TRX_STATE_REG     0x02
#define TRX_CTRL_0_REG    0x03
#define TRX_CTRL_1_REG    0x04
#define PHY_TX_PWR_REG    0x05
#define PHY_RSSI_REG      0x06
#define PHY_ED_LEVEL_REG  0x07
#define PHY_CC_CCA_REG    0x08
#define CCA_THRESH_REG    0x09
#define RX_CTRL_REG       0x0A
#define SFD_VALUE_REG     0x0B
#define TRX_CTRL_2_REG    0x0C
#define ANT_DIV_REG       0x0D
#define IRQ_MASK_REG      0x0E
#define IRQ_STATUS_REG    0x0F
#define VREG_CTRL_REG     0x10
#define BATMON_REG        0x11
#define XOSC_CTRL_REG     0x12
#define CC_CTRL_0_REG     0x13
#define CC_CTRL_1_REG     0x14
#define RX_SYN_REG        0x15
#define TRX_RPC_REG       0x16
#define XAH_CTRL_REG      0x17
#define FTN_CTRL_REG      0x18
#define XAH_CTRL_2_REG    0x19
#define PLL_CF_REG        0x1A
#define PLL_DCU_REG       0x1B
#define PART_NUM_REG      0x1C
#define VERSION_NUM_REG   0x1D
#define MAN_ID_0_REG      0x1E
#define MAN_ID_1_REG      0x1F
#define SHORT_ADDR_0_REG  0x20
#define SHORT_ADDR_1_REG  0x21
#define PAN_ID_0_REG      0x22
#define PAN_ID_1_REG      0x23
#define IEEE_ADDR_0_REG   0x24
#define IEEE_ADDR_1_REG   0x25
#define IEEE_ADDR_2_REG   0x26
#define IEEE_ADDR_3_REG   0x27
#define IEEE_ADDR_4_REG   0x28
#define IEEE_ADDR_5_REG   0x29
#define IEEE_ADDR_6_REG   0x2A
#define IEEE_ADDR_7_REG   0x2B
#define XAH_CTRL_0_REG    0x2C
#define CSMA_SEED_0_REG   0x2D
#define CSMA_SEED_1_REG   0x2E
#define CSMA_BE_REG       0x2F
#define TEST_CTRL_DIGI    0x36
#endif

/* SRAM register addresses */
#define AESST_REG         0x82
#define AESCON_REG        0x83
#define AESCON_SHADOW_REG 0x94

/******************************************************************************
                    Command values
******************************************************************************/
#define RF_CMD_RW ((1<<7) | (1<<6))
#define RF_CMD_RR ((1<<7) | (0<<6))
#define RF_CMD_FW ((0<<7) | (1<<6) | (1<<5))
#define RF_CMD_FR ((0<<7) | (0<<6) | (1<<5))
#define RF_CMD_SW ((0<<7) | (1<<6) | (0<<5))
#define RF_CMD_SR ((0<<7) | (0<<6) | (0<<5))
#define RF_RADDRM ((0<<7) | (0<<6) | (1<<5) | (1<<4) | (1<<3) | (1<<2) |(1<<1) | (1<<0))

/******************************************************************************
                    Registers description
******************************************************************************/
BEGIN_PACK
/***************************
        TRX_STATUS
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t trxStatus : 5,
    uint8_t reserved  : 1,
    uint8_t ccaStatus : 1,
    uint8_t ccaDone   : 1
  ))
} MAY_ALIAS RegTrxStatus_t;

#define TRX_STATUS_MEANINGFUL_BITS     0x1F
#define REG_TRX_STATUS_TRX_STATUS_MASK 0x1F
// CCA_DONE
#define CCA_IN_PROGRESS                0
#define CCA_DONE                       1
// CCA_STATUS
#define CCA_STATUS_BUSY                0
#define CCA_STATUS_IDLE                1
// TRX_STATUS
#define TRX_STATUS_P_ON                0
#define TRX_STATUS_BUSY_RX             1
#define TRX_STATUS_BUSY_TX             2
#define TRX_STATUS_RX_ON               6
#define TRX_STATUS_TRX_OFF             8
#define TRX_STATUS_PLL_ON              9
#define TRX_STATUS_SLEEP               15
#define TRX_STATUS_PREP_DEEP_SLEEP     16
#define TRX_STATUS_BUSY_RX_AACK        17
#define TRX_STATUS_BUSY_TX_ARET        18
#define TRX_STATUS_RX_AACK_ON          22
#define TRX_STATUS_TX_ARET_ON          25
#define TRX_STATUS_TRANS_IN_PROGRESS   31

/***************************
        TRX_STATE
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t trxCmd     : 5,
    uint8_t tracStatus : 3
  ))
} MAY_ALIAS RegTrxState_t;

// TRAC_STATUS
#define TRAC_STATUS_SUCCESS                0
#define TRAC_STATUS_SUCCESS_DATA_PENDING   1
#define TRAC_STATUS_WAIT_FOR_ACK           2
#define TRAC_STATUS_CHANNEL_ACCESS_FAILURE 3
#define TRAC_STATUS_NO_ACK                 5
#define TRAC_STATUS_INVALID                7

//PLL and CCA Flag Check
#define PLL_LOCK_FLAG_SET             0x01
#define CCA_ED_DONE                   0x10


// TRX_CMD
#define TRX_CMD_NOP                        0
#define TRX_CMD_TX_START                   2
#define TRX_CMD_FORCE_TRX_OFF              3
#define TRX_CMD_FORCE_PLL_ON               4
#define TRX_CMD_RX_ON                      6
#define TRX_CMD_TRX_OFF                    8
#define TRX_CMD_PLL_ON                     9
#define TRX_CMD_PREP_DEEP_SLEEP            16
#define TRX_CMD_RX_AACK_ON                 22
#define TRX_CMD_TX_ARET_ON                 25

/***************************
        TRX_CTRL_0
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t clkmCtrl   : 3,
    uint8_t clkmShaSel : 1,
    uint8_t reserved   : 4
  ))
} MAY_ALIAS RegTrxCtrl0_t;

// CLKM_SHA_SEL
#define CLKM_SHA_SEL_DISABLE 0
#define CLKM_SHA_SEL_ENABLE  1
// CLKM_CTRL
#define CLK_CTRL_NOCLK       0
#define CLK_CTRL_1MHZ        1
#define CLK_CTRL_2MHZ        2
#define CLK_CTRL_4MHZ        3
#define CLK_CTRL_8MHZ        4
#define CLK_CTRL_16MHZ       5
#define CLK_CTRL_1_4MHZ      6
#define CLK_CTRL_1_16MHZ     7

/***************************
        TRX_CTRL_1
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(7, (
    uint8_t irqPolarity  : 1,
    uint8_t irqMaskMode  : 1,
    uint8_t spiCmdMode   : 2,
    uint8_t rxBlCtrl     : 1,
    uint8_t txAutoCrcOn  : 1,
    uint8_t irq2ExtEn    : 1,
    uint8_t paExtEn      : 1
  ))
} MAY_ALIAS RegTrxCtrl1_t;

// Mask for TRX_CTRL_1
#define IRQ2_EXT_EN_MASK        (1 << 6)
// PA_EXT_EN
#define PA_EXT_DISABLE          0
#define PA_EXT_ENABLE           1
// IRQ_2_EXT_EN
#define IRQ_2_EXT_DISABLE       0
#define IRQ_2_EXT_ENABLE        1
// TX_AUTO_CRC_ON
#define TX_AUTO_CRC_ON_DISABLE  0
#define TX_AUTO_CRC_ON_ENABLE   1
// SPI_CMD_MODE
#define SPI_CMD_MODE_DEFAULT    0
#define SPI_CMD_MODE_TRX_STATUS 1
#define SPI_CMD_MODE_PHY_RSSI   2
#define SPI_CMD_MODE_IRQ_STATUS 3
// IRQ_MASK_MODE
#define NOT_SHOW_MASKED_IRQ     0
#define SHOW_MASKED_IRQ         1
// IRQ_POLARITY
#define IRQ_HIGH_ACTIVE         0
#define IRQ_LOW_ACTIVE          1

/***************************
        PHY_TX_PWR
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t txPwr       : 4,
    uint8_t reserved    : 4
  ))
} MAY_ALIAS RegPhyTxPwr_t;

// Masks for PHY_TX_PWR register
#define REG_PHY_TX_PWR_TX_PWR_MASK 0x0F

// TX_PWR_LPA_MPA Mode Values 
#define TXPWR_12_DBM_BACKOFF_VALUE        0x00 //12 dBm
#define TXPWR_11_DBM_BACKOFF_VALUE        0x01 //11 dBm
#define TXPWR_10_DBM_BACKOFF_VALUE        0x02 //10 dBm
#define TXPWR_9_DBM_BACKOFF_VALUE         0x03 //9 dBm
#define TXPWR_8_DBM_BACKOFF_VALUE         0x04 //8 dBm
#define TXPWR_7_DBM_BACKOFF_VALUE         0x05 //7 dBm
#define TXPWR_6_DBM_BACKOFF_VALUE         0x06 //6 dBm
#define TXPWR_5_DBM_BACKOFF_VALUE         0x07 //5 dBm
#define TXPWR_4_DBM_BACKOFF_VALUE         0x07 //5 dBm
#define TXPWR_3_DBM_BACKOFF_VALUE         0x08 //3.5 dBm
#define TXPWR_2_DBM_BACKOFF_VALUE         0x09 //2 dBm
#define TXPWR_1_DBM_BACKOFF_VALUE         0x09 //2 dBm
#define TXPWR_0_DBM_BACKOFF_VALUE         0x0A //0.5 dBm
#define TXPWR_MIN_1_DBM_BACKOFF_VALUE     0x0A //0.5 dBm
#define TXPWR_MIN_2_DBM_BACKOFF_VALUE     0X0B //-1.5 dBm
#define TXPWR_MIN_3_DBM_BACKOFF_VALUE     0X0B //-1.5 dBm
#define TXPWR_MIN_4_DBM_BACKOFF_VALUE     0X0C //-4 dBm  
#define TXPWR_MIN_5_DBM_BACKOFF_VALUE     0X0C //-4 dBm
#define TXPWR_MIN_6_DBM_BACKOFF_VALUE     0X0C //-4 dBm
#define TXPWR_MIN_7_DBM_BACKOFF_VALUE     0X0D //-7 dBm
#define TXPWR_MIN_8_DBM_BACKOFF_VALUE     0X0D //-7 dBm
#define TXPWR_MIN_9_DBM_BACKOFF_VALUE     0X0D //-7 dBm
#define TXPWR_MIN_10_DBM_BACKOFF_VALUE    0X0E //-10 dBm
#define TXPWR_MIN_11_DBM_BACKOFF_VALUE    0X0E //-10 dBm
#define TXPWR_MIN_12_DBM_BACKOFF_VALUE    0X0E //-10 dBm
#define TXPWR_MIN_13_DBM_BACKOFF_VALUE    0X0E //-10 dBm
#define TXPWR_MIN_14_DBM_BACKOFF_VALUE    0X0F //-14 dBm


// TX_PWR LPA Mode Only Values 
#define TXPWR_6_DBM_BACKOFF_LPA_VALUE         0x00 //5.5 dBm
#define TXPWR_5_DBM_BACKOFF_LPA_VALUE         0x01 //5 dBm
#define TXPWR_4_5_DBM_BACKOFF_LPA_VALUE       0x02 //4.5 dBm
#define TXPWR_4_DBM_BACKOFF_LPA_VALUE         0x03 //4 dBm
#define TXPWR_3_DBM_BACKOFF_LPA_VALUE         0x04 //3 dBm
#define TXPWR_2_DBM_BACKOFF_LPA_VALUE         0x05 //2 dBm
#define TXPWR_1_DBM_BACKOFF_LPA_VALUE         0x06 //1 dBm
#define TXPWR_0_DBM_BACKOFF_LPA_VALUE         0x07 //0 dBm
#define TXPWR_MIN_1_DBM_BACKOFF_LPA_VALUE     0x08 //-1 dBm
#define TXPWR_MIN_2_DBM_BACKOFF_LPA_VALUE     0x09 //-2 dBm
#define TXPWR_MIN_3_DBM_BACKOFF_LPA_VALUE     0x0A //-3 dBm
#define TXPWR_MIN_4_DBM_BACKOFF_LPA_VALUE     0x0B //-4 dBm
#define TXPWR_MIN_5_DBM_BACKOFF_LPA_VALUE     0x0C //-5 dBm
#define TXPWR_MIN_6_DBM_BACKOFF_LPA_VALUE     0x0C //-5 dBm
#define TXPWR_MIN_7_DBM_BACKOFF_LPA_VALUE     0x0D //-7 dBm
#define TXPWR_MIN_8_DBM_BACKOFF_LPA_VALUE     0x0D //-7 dBm
#define TXPWR_MIN_9_DBM_BACKOFF_LPA_VALUE     0x0D //-7 dBm
#define TXPWR_MIN_10_DBM_BACKOFF_LPA_VALUE    0x0D //-7 dBm
#define TXPWR_MIN_11_DBM_BACKOFF_LPA_VALUE    0x0E //-11 dBm
#define TXPWR_MIN_12_DBM_BACKOFF_LPA_VALUE    0x0E //-11 dBm
#define TXPWR_MIN_13_DBM_BACKOFF_LPA_VALUE    0x0E //-11 dBm
#define TXPWR_MIN_14_DBM_BACKOFF_LPA_VALUE    0x0E //-11 dBm
#define TXPWR_MIN_15_DBM_BACKOFF_LPA_VALUE    0x0E //-11 dBm
#define TXPWR_MIN_16_DBM_BACKOFF_LPA_VALUE    0x0F //-16 dBm

/***************************
        PHY_RSSI
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t rssi       : 5,
    uint8_t rndValue   : 2,
    uint8_t rxCrcValid : 1
  ))
} MAY_ALIAS RegPhyRssi_t;

/***************************
        PHY_CC_CCA
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t channel    : 5,
    uint8_t ccaMode    : 2,
    uint8_t ccaRequest : 1
  ))
} MAY_ALIAS RegPhyCcCca_t;

// Masks for PHY_CC_CCA register
#define REG_PHY_CC_CCA_CCA_REQUEST_MASK 0x80
#define REG_PHY_CC_CCA_CCA_MODE_MASK    0x60
#define REG_PHY_CC_CCA_CHANNEL_MASK     0x1F
// CCA_REQUEST
#define CCA_REQUEST_START               1
// CCA_MODE
#define CCA_MODE_0                      0
#define CCA_MODE_1                      1
#define CCA_MODE_2                      2
#define CCA_MODE_3                      3

/***************************
        CCA_THRES
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t ccaEdThres  : 4,
    uint8_t reserved : 4
  ))
} MAY_ALIAS RegCcaThres_t;

//Mask for PHY_CCA_THRES register
#define REG_PHY_CCA_THRES_CCA_ED_THRES_MASK 0x0F

/***************************
        RX_CTRL
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t pdtThres : 4,
    uint8_t reserved : 4
  ))
} MAY_ALIAS RegRxCtrl_t;

#define PDT_THRES_ANT_DIV_ENABLED 0x03
#define PDT_THRES_DEFAULT         0x07

/***************************
        PHY_TRX_CTRL_2
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(5, (
    uint8_t oqpskDataRate : 3,
    uint8_t reserved1     : 2,
    uint8_t oqpskScramEn  : 1,
    uint8_t reserved2     : 1,
    uint8_t rxSafeMode    : 1
  ))
} MAY_ALIAS RegTrxCtrl2_t;

// Bit numbers
#define RF_SAFE_MODE          7
#define OQPSK_DATA_RATE_1     1
#define OQPSK_DATA_RATE_0     0
// RX_SAFE_MODE
#define RF_SAFE_MODE_DISABLE  0
#define RF_SAFE_MODE_ENABLE   1
// OQPSK_DATA_RATE
#define OQPSK_DATA_RATE_250K  0
#define OQPSK_DATA_RATE_500K  1
#define OQPSK_DATA_RATE_1M    2
#define OQPSK_DATA_RATE_2M    3

/***************************
        ANT_DIV
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(5, (
    uint8_t antCtrl     : 2,
    uint8_t antExtSwEn  : 1,
    uint8_t antDivEn    : 1,
    uint8_t reserved    : 3,
    uint8_t antSel      : 1
  ))
} MAY_ALIAS RegAntDiv_t;

// Masks for ANT_DIV register
#define ANT_SEL_MASK         (1 << 7)
#define ANT_DIV_ENABLED_MASK (1 << 3)
// ANT_EXT_SW_EN values of ANT_DIV
#define ANT_EXT_SW_ENABLED   0x04
#define ANT_EXT_SW_DISABLED  0x00
// ANT_CTRL values of ANT_DIV
#define ANT_CTRL_DEFAULT     0x00
#define ANT_CTRL_ANTENNA_0   0x01
#define ANT_CTRL_ANTENNA_1   0x02

/***************************
        IRQ_STATUS
****************************/
// Mask for IRQ_STATUS register
#define BAT_LOW_MASK      (1 << 7) // 0x80 IRQ7
#define TRX_UR_MASK       (1 << 6) // 0x40 IRQ6
#define AMI_MASK          (1 << 5) // 0x20 IRQ5
#define CCA_ED_READY_MASK (1 << 4) // 0x10 IRQ4
#define TRX_END_MASK      (1 << 3) // 0x08 IRQ3
#define RX_START_MASK     (1 << 2) // 0x04 IRQ2
#define PLL_UNLOCK_MASK   (1 << 1) // 0x02 IRQ1
#define PLL_LOCK_MASK     (1 << 0) // 0x01 IRQ0

/***************************
        VREG_CTRL
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(6, (
    uint8_t reserved1 : 2,
    uint8_t dvddOk    : 1,
    uint8_t dvregExt  : 1,
    uint8_t reserved2 : 2,
    uint8_t avddOk    : 1,
    uint8_t avregExt  : 1
  ))
} MAY_ALIAS RegVregCtrl_t;

// AVREG_EXT
#define AVREG_USE_INTERNAL 0
#define AVREG_USE_EXTERNAL 1
// AVDD_OK
#define AVDD_OK_DISABLE    0
#define AVDD_OK_ENABLE     1
// DVREG_EXT
#define DVREG_USE_INTERNAL 0
#define DVREG_USE_EXTERNAL 1
// DVDD_OK
#define DVDD_OK_DISABLE    0
#define DVDD_OK_ENABLE     1

/***************************
        BATMON
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t batmonVth : 4,
    uint8_t batmonHr  : 1,
    uint8_t batmonOk  : 1,
    uint8_t reserved  : 2
  ))
} MAY_ALIAS RegBatmon_t;

#define BATMON_OK 1

/***************************
        XOSC_CTRL
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t xtalTrim : 4,
    uint8_t xtalMode : 4
  ))
} MAY_ALIAS RegXoscCtrl_t;

// XTAL_MODE
#define XTAL_MODE_SWITCH_OFF    0
#define XTAL_MODE_EXTERNAL_OSC  4
#define XTAL_MODE_INTERNAL_OSC  15
// XTAL_TRIM
#define XTAL_TRIM_0_0PF         0
#define XTAL_TRIM_0_3PF         1
#define XTAL_TRIM_0_6PF         2
#define XTAL_TRIM_0_9PF         3
#define XTAL_TRIM_1_2PF         4
#define XTAL_TRIM_1_5PF         5
#define XTAL_TRIM_1_8PF         6
#define XTAL_TRIM_2_1PF         7
#define XTAL_TRIM_2_4PF         8
#define XTAL_TRIM_2_7PF         9
#define XTAL_TRIM_3_0PF         10
#define XTAL_TRIM_3_3PF         11
#define XTAL_TRIM_3_6PF         12
#define XTAL_TRIM_3_9PF         13
#define XTAL_TRIM_4_2PF         14
#define XTAL_TRIM_4_5PF         15

/***************************
        CC_CTRL_1
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t ccBand    : 4,
    uint8_t reserved0 : 4
  ))
} MAY_ALIAS RegCcCtrl1_t;

// CC_BAND possible values
#define CC_BAND_0 0
#define CC_BAND_8 8
#define CC_BAND_9 9

/***************************
        RX_SYN
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t rx_pdt_level : 4,
    uint8_t reserved     : 3,
    uint8_t rx_pdt_dis   : 1
  ))
} MAY_ALIAS RegRx_Syn_t;

// RX_SYN possible values
#define RX_PDT_DISABLE  (1 << 7)
#define RX_PDT_ENABLE   0U

/***************************
        TRX_RPC
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(7, (
    uint8_t reserved   : 1,
    uint8_t ipanRpcEn  : 1,
    uint8_t xahTxRpcEn : 1,
    uint8_t pllRpcEn   : 1,
    uint8_t pdtRpcEn   : 1,
    uint8_t rxRpcEn    : 1,
    uint8_t rxRpcCtrl  : 2
  ))
} MAY_ALIAS RegTrxRpc_t;

/***************************
        XAH_CTRL_1
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(8, (
    uint8_t aackSpcEn     : 1, // not described in datasheet
    uint8_t aackPromMode  : 1,
    uint8_t aackAckTime   : 1,
    uint8_t reserved1     : 1,
    uint8_t aackUpldResFt : 1,
    uint8_t aackFltrResFt : 1,
    uint8_t reserved2     : 1,
    uint8_t aretTxTsEn    : 1
  ))
} MAY_ALIAS RegXahCtrl1_t;

/***************************
        FTN_CTRL
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t reserved  : 7,
    uint8_t ftnStart  : 1
  ))
} MAY_ALIAS RegFtnCtrl_t;

#define FTN_START 1

/***************************
        XAH_CTRL_2
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t reserved         : 1,
    uint8_t aretCsmaRetries  : 3,
    uint8_t aretFrameRetries : 4
  ))
} MAY_ALIAS RegXahCtrl2_t;

/***************************
        PLL_CF
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t pllCf      : 4,
    uint8_t reserved1  : 2,
    uint8_t reserved2  : 1,
    uint8_t pllCfStart : 1
  ))
} MAY_ALIAS RegPllCf_t;

/***************************
        PLL_DCU
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t reserved1   : 6,
    uint8_t reserved2   : 1,
    uint8_t pllDcuStart : 1
  ))
} MAY_ALIAS RegPllDcu_t;

/***************************
        XAH_CTRL_0
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3, (
    uint8_t slottedOperation : 1,
    uint8_t maxCsmaRetries   : 3,
    uint8_t maxFrameRetries  : 4
  ))
} RegXahCtrl0_t;

// Mask for XAH_CTRL_0 register
#define REG_XAH_CTRL_0_MAX_FRAME_RETRIES_MASK 0xF0
#define REG_XAH_CTRL_0_SLOTTED_OPERATION_MASK 0x01
#define REG_XAH_CTRL_0_MAX_CSMA_RETRIES_MASK  0x0E

/***************************
        CSMA_SEED_1
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(5, (
    uint8_t csmaSeed1 : 3,
    uint8_t iAmCoord  : 1,
    uint8_t aackDisAck  : 1,
    uint8_t aackSetPd   : 1,
    uint8_t aackFvnMode : 2
  ))
} MAY_ALIAS RegCsmaSeed1_t;

// Masks for CSMA_SEED_1 register
#define REG_CSMA_SEED_1_AACK_FVN_MODE_MASK 0xC0
#define REG_CSMA_SEED_1_AACK_SET_PD_MASK   0x20
#define REG_CSMA_SEED_1_AACK_DIS_ACK_MASK  0x10
#define REG_CSMA_SEED_1_I_AM_COORD_MASK    0x08
#define REG_CSMA_SEED_1_CSMA_SEED1_MASK    0x07
// AACK_FVN_MODE
#define AACK_FVN_MODE_ACK_0                0
#define AACK_FVN_MODE_ACK_0_1              1
#define AACK_FVN_MODE_ACK_0_1_2            2
#define AACK_FVN_MODE_ACK_ANY              3

/***************************
        CSMA_BE
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t minBe : 4,
    uint8_t maxBe : 4
  ))
} MAY_ALIAS RegCsmaBe_t;

// Masks for CSMA_BE register
#define REG_CSMA_BE_MAX_BE_MASK 0xF0
#define REG_CSMA_BE_MIN_BE_MASK 0x0F

/***************************
        TST_CTRL_DIG
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(5, (
    uint8_t tstCtrlDig : 4,
    uint8_t reserved1  : 1,
    uint8_t reserved2  : 1,
    uint8_t reserved3  : 1,
    uint8_t reserved4  : 1
  ))
} MAY_ALIAS RegTestCtrlDigi_t;

/***************************
        AESCON
****************************/
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t reserved  : 3,
    uint8_t aesd      : 1,
    uint8_t aesmode   : 3,
    uint8_t aesr      : 1
  ))
} MAY_ALIAS RegAescon_t;

typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t reserved  : 3,
    uint8_t aesd      : 1,
    uint8_t aesmode   : 3,
    uint8_t aesr      : 1
  ))
} MAY_ALIAS RegAesconShadow_t;

// Security mode control
#define AESR      7
#define AESMODE2  6
#define AESMODE1  5
#define AESMODE0  4
#define AESD      3
// AES_REQUEST
#define START_SECURITY_MODULE 1
// AES_MODE
#define ECB_MODE              0
#define KEY_MODE              1
#define CBC_MODE              2
// AES_DIR
#define AES_ENCRYPTION        0
#define AES_DECRYPTION        1

END_PACK
#endif /* _AT86RF233_H_ */

// eof at86rf233.h
