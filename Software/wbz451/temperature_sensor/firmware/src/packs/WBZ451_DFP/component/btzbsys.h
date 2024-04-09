/*
 * Component description for BTZBSYS
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2023-05-31T11:03:01Z */
#ifndef _BZ45_BTZBSYS_COMPONENT_H_
#define _BZ45_BTZBSYS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR BTZBSYS                                      */
/* ************************************************************************** */

/* -------- BTZBSYS_SUBSYS_CNTRL_REG0 : (BTZBSYS Offset: 0x00) (R/W 32) SUBSYS_CNTRL_REG0 -------- */
#define BTZBSYS_SUBSYS_CNTRL_REG0_RESETVALUE  _UINT32_(0x00)                                       /*  (BTZBSYS_SUBSYS_CNTRL_REG0) SUBSYS_CNTRL_REG0  Reset Value */

#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_slp_ctrl_Pos _UINT32_(0)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_slp_ctrl Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_slp_ctrl_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_slp_ctrl_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_slp_ctrl Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_slp_ctrl(value) (BTZBSYS_SUBSYS_CNTRL_REG0_zb_slp_ctrl_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_slp_ctrl_Pos)) /* Assigment of value for zb_slp_ctrl in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_soft_reset_in_Pos _UINT32_(1)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_soft_reset_in Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_soft_reset_in_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_soft_reset_in_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_soft_reset_in Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_soft_reset_in(value) (BTZBSYS_SUBSYS_CNTRL_REG0_zb_soft_reset_in_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_soft_reset_in_Pos)) /* Assigment of value for zb_soft_reset_in in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_reset_by_fw_Pos _UINT32_(3)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_reset_by_fw Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_reset_by_fw_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_reset_by_fw_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_reset_by_fw Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_reset_by_fw(value) (BTZBSYS_SUBSYS_CNTRL_REG0_zb_reset_by_fw_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_reset_by_fw_Pos)) /* Assigment of value for zb_reset_by_fw in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_en_main_clk_Pos _UINT32_(4)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_en_main_clk Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_en_main_clk_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_en_main_clk_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) zb_en_main_clk Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_zb_en_main_clk(value) (BTZBSYS_SUBSYS_CNTRL_REG0_zb_en_main_clk_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_zb_en_main_clk_Pos)) /* Assigment of value for zb_en_main_clk in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_1_iom_en_Pos _UINT32_(5)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG0) ant_div_sel_1_iom_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_1_iom_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_1_iom_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) ant_div_sel_1_iom_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_1_iom_en(value) (BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_1_iom_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_1_iom_en_Pos)) /* Assigment of value for ant_div_sel_1_iom_en in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_2_iom_en_Pos _UINT32_(6)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG0) ant_div_sel_2_iom_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_2_iom_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_2_iom_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) ant_div_sel_2_iom_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_2_iom_en(value) (BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_2_iom_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_ant_div_sel_2_iom_en_Pos)) /* Assigment of value for ant_div_sel_2_iom_en in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_pdc_ov_Pos _UINT32_(16)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_pdc_ov Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_pdc_ov_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_pdc_ov_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_pdc_ov Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_pdc_ov(value) (BTZBSYS_SUBSYS_CNTRL_REG0_bt_pdc_ov_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_pdc_ov_Pos)) /* Assigment of value for bt_pdc_ov in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_sfr_wakeup_bit_Pos _UINT32_(17)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_sfr_wakeup_bit Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_sfr_wakeup_bit_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_sfr_wakeup_bit_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_sfr_wakeup_bit Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_sfr_wakeup_bit(value) (BTZBSYS_SUBSYS_CNTRL_REG0_bt_sfr_wakeup_bit_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_sfr_wakeup_bit_Pos)) /* Assigment of value for bt_sfr_wakeup_bit in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_hw_rc_re_cal_Pos _UINT32_(18)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_hw_rc_re_cal Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_hw_rc_re_cal_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_hw_rc_re_cal_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_hw_rc_re_cal Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_hw_rc_re_cal(value) (BTZBSYS_SUBSYS_CNTRL_REG0_bt_hw_rc_re_cal_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_hw_rc_re_cal_Pos)) /* Assigment of value for bt_hw_rc_re_cal in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_reset_by_fw_Pos _UINT32_(19)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_reset_by_fw Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_reset_by_fw_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_reset_by_fw_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_reset_by_fw Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_reset_by_fw(value) (BTZBSYS_SUBSYS_CNTRL_REG0_bt_reset_by_fw_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_reset_by_fw_Pos)) /* Assigment of value for bt_reset_by_fw in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_en_main_clk_Pos _UINT32_(20)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_en_main_clk Position */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_en_main_clk_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_en_main_clk_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG0) bt_en_main_clk Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG0_bt_en_main_clk(value) (BTZBSYS_SUBSYS_CNTRL_REG0_bt_en_main_clk_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG0_bt_en_main_clk_Pos)) /* Assigment of value for bt_en_main_clk in the BTZBSYS_SUBSYS_CNTRL_REG0 register */
#define BTZBSYS_SUBSYS_CNTRL_REG0_Msk         _UINT32_(0x001F007B)                                 /* (BTZBSYS_SUBSYS_CNTRL_REG0) Register Mask  */


/* -------- BTZBSYS_SUBSYS_CNTRL_REG1 : (BTZBSYS Offset: 0x04) (R/W 32) SUBSYS_CNTRL_REG1 -------- */
#define BTZBSYS_SUBSYS_CNTRL_REG1_RESETVALUE  _UINT32_(0xF000)                                     /*  (BTZBSYS_SUBSYS_CNTRL_REG1) SUBSYS_CNTRL_REG1  Reset Value */

#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Pos _UINT32_(0)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_dbg_bus_sel_top Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Msk (_UINT32_(0x3) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_dbg_bus_sel_top Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top(value) (BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Pos)) /* Assigment of value for subsys_dbg_bus_sel_top in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_Pos _UINT32_(2)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_dbg_bus_sel Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_Msk (_UINT32_(0x3) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_dbg_bus_sel Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel(value) (BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_Pos)) /* Assigment of value for subsys_dbg_bus_sel in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_clk_src_sel_Pos _UINT32_(4)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_clk_src_sel Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_clk_src_sel_Msk (_UINT32_(0x3) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_clk_src_sel_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_clk_src_sel Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_clk_src_sel(value) (BTZBSYS_SUBSYS_CNTRL_REG1_subsys_clk_src_sel_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_clk_src_sel_Pos)) /* Assigment of value for subsys_clk_src_sel in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_ssubsys_clk_div_sel_Pos _UINT32_(6)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_clk_div_sel Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_ssubsys_clk_div_sel_Msk (_UINT32_(0x3) << BTZBSYS_SUBSYS_CNTRL_REG1_ssubsys_clk_div_sel_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_clk_div_sel Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_ssubsys_clk_div_sel(value) (BTZBSYS_SUBSYS_CNTRL_REG1_ssubsys_clk_div_sel_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_ssubsys_clk_div_sel_Pos)) /* Assigment of value for ssubsys_clk_div_sel in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready_Pos _UINT32_(8)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_bypass_xtal_ready Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_bypass_xtal_ready Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready(value) (BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready_Pos)) /* Assigment of value for subsys_bypass_xtal_ready in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock_Pos _UINT32_(9)                                          /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_bypass_pll_lock Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_bypass_pll_lock Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock(value) (BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock_Pos)) /* Assigment of value for subsys_bypass_pll_lock in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_xtal_ready_delay_Pos _UINT32_(12)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_xtal_ready_delay Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_xtal_ready_delay_Msk (_UINT32_(0xF) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_xtal_ready_delay_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) subsys_xtal_ready_delay Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_subsys_xtal_ready_delay(value) (BTZBSYS_SUBSYS_CNTRL_REG1_subsys_xtal_ready_delay_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_subsys_xtal_ready_delay_Pos)) /* Assigment of value for subsys_xtal_ready_delay in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_iom_en_Pos _UINT32_(16)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) tr_sw_iom_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_iom_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_iom_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) tr_sw_iom_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_iom_en(value) (BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_iom_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_iom_en_Pos)) /* Assigment of value for tr_sw_iom_en in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_n_iom_en_Pos _UINT32_(17)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) tr_sw_n_iom_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_n_iom_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_n_iom_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) tr_sw_n_iom_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_n_iom_en(value) (BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_n_iom_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_tr_sw_n_iom_en_Pos)) /* Assigment of value for tr_sw_n_iom_en in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_pa_on_iom_en_Pos _UINT32_(18)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) pa_on_iom_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_pa_on_iom_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_pa_on_iom_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) pa_on_iom_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_pa_on_iom_en(value) (BTZBSYS_SUBSYS_CNTRL_REG1_pa_on_iom_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_pa_on_iom_en_Pos)) /* Assigment of value for pa_on_iom_en in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_lna_on_iom_en_Pos _UINT32_(19)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) lna_on_iom_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_lna_on_iom_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_lna_on_iom_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) lna_on_iom_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_lna_on_iom_en(value) (BTZBSYS_SUBSYS_CNTRL_REG1_lna_on_iom_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_lna_on_iom_en_Pos)) /* Assigment of value for lna_on_iom_en in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_en_Pos _UINT32_(20)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) zb_bt_bar_ovrd_en Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_en_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_en_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) zb_bt_bar_ovrd_en Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_en(value) (BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_en_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_en_Pos)) /* Assigment of value for zb_bt_bar_ovrd_en in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_val_Pos _UINT32_(21)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) zb_bt_bar_ovrd_val Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_val_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_val_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) zb_bt_bar_ovrd_val Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_val(value) (BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_val_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_zb_bt_bar_ovrd_val_Pos)) /* Assigment of value for zb_bt_bar_ovrd_val in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_invert_btadc_clk_Pos _UINT32_(22)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) invert_btadc_clk Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_invert_btadc_clk_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_invert_btadc_clk_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) invert_btadc_clk Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_invert_btadc_clk(value) (BTZBSYS_SUBSYS_CNTRL_REG1_invert_btadc_clk_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_invert_btadc_clk_Pos)) /* Assigment of value for invert_btadc_clk in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_clk_lp_req_Pos _UINT32_(23)                                         /* (BTZBSYS_SUBSYS_CNTRL_REG1) clk_lp_req Position */
#define BTZBSYS_SUBSYS_CNTRL_REG1_clk_lp_req_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_CNTRL_REG1_clk_lp_req_Pos) /* (BTZBSYS_SUBSYS_CNTRL_REG1) clk_lp_req Mask */
#define BTZBSYS_SUBSYS_CNTRL_REG1_clk_lp_req(value) (BTZBSYS_SUBSYS_CNTRL_REG1_clk_lp_req_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_CNTRL_REG1_clk_lp_req_Pos)) /* Assigment of value for clk_lp_req in the BTZBSYS_SUBSYS_CNTRL_REG1 register */
#define BTZBSYS_SUBSYS_CNTRL_REG1_Msk         _UINT32_(0x00FFF3FF)                                 /* (BTZBSYS_SUBSYS_CNTRL_REG1) Register Mask  */


/* -------- BTZBSYS_SUBSYS_STATUS_REG0 : (BTZBSYS Offset: 0x20) (R/W 32) SUBSYS_STATUS_REG0 -------- */
#define BTZBSYS_SUBSYS_STATUS_REG0_RESETVALUE _UINT32_(0x00)                                       /*  (BTZBSYS_SUBSYS_STATUS_REG0) SUBSYS_STATUS_REG0  Reset Value */

#define BTZBSYS_SUBSYS_STATUS_REG0_zb_sleep_mode_Pos _UINT32_(0)                                          /* (BTZBSYS_SUBSYS_STATUS_REG0) zb_sleep_mode Position */
#define BTZBSYS_SUBSYS_STATUS_REG0_zb_sleep_mode_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG0_zb_sleep_mode_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG0) zb_sleep_mode Mask */
#define BTZBSYS_SUBSYS_STATUS_REG0_zb_sleep_mode(value) (BTZBSYS_SUBSYS_STATUS_REG0_zb_sleep_mode_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG0_zb_sleep_mode_Pos)) /* Assigment of value for zb_sleep_mode in the BTZBSYS_SUBSYS_STATUS_REG0 register */
#define BTZBSYS_SUBSYS_STATUS_REG0_zb_deep_sleep_mode_Pos _UINT32_(1)                                          /* (BTZBSYS_SUBSYS_STATUS_REG0) zb_deep_sleep_mode Position */
#define BTZBSYS_SUBSYS_STATUS_REG0_zb_deep_sleep_mode_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG0_zb_deep_sleep_mode_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG0) zb_deep_sleep_mode Mask */
#define BTZBSYS_SUBSYS_STATUS_REG0_zb_deep_sleep_mode(value) (BTZBSYS_SUBSYS_STATUS_REG0_zb_deep_sleep_mode_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG0_zb_deep_sleep_mode_Pos)) /* Assigment of value for zb_deep_sleep_mode in the BTZBSYS_SUBSYS_STATUS_REG0 register */
#define BTZBSYS_SUBSYS_STATUS_REG0_radio_idle_zb_Pos _UINT32_(2)                                          /* (BTZBSYS_SUBSYS_STATUS_REG0) radio_idle_zb Position */
#define BTZBSYS_SUBSYS_STATUS_REG0_radio_idle_zb_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG0_radio_idle_zb_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG0) radio_idle_zb Mask */
#define BTZBSYS_SUBSYS_STATUS_REG0_radio_idle_zb(value) (BTZBSYS_SUBSYS_STATUS_REG0_radio_idle_zb_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG0_radio_idle_zb_Pos)) /* Assigment of value for radio_idle_zb in the BTZBSYS_SUBSYS_STATUS_REG0 register */
#define BTZBSYS_SUBSYS_STATUS_REG0_bt_low_power_mode_Pos _UINT32_(16)                                         /* (BTZBSYS_SUBSYS_STATUS_REG0) bt_low_power_mode Position */
#define BTZBSYS_SUBSYS_STATUS_REG0_bt_low_power_mode_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG0_bt_low_power_mode_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG0) bt_low_power_mode Mask */
#define BTZBSYS_SUBSYS_STATUS_REG0_bt_low_power_mode(value) (BTZBSYS_SUBSYS_STATUS_REG0_bt_low_power_mode_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG0_bt_low_power_mode_Pos)) /* Assigment of value for bt_low_power_mode in the BTZBSYS_SUBSYS_STATUS_REG0 register */
#define BTZBSYS_SUBSYS_STATUS_REG0_bt_rf_idle_Pos _UINT32_(17)                                         /* (BTZBSYS_SUBSYS_STATUS_REG0) bt_rf_idle Position */
#define BTZBSYS_SUBSYS_STATUS_REG0_bt_rf_idle_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG0_bt_rf_idle_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG0) bt_rf_idle Mask */
#define BTZBSYS_SUBSYS_STATUS_REG0_bt_rf_idle(value) (BTZBSYS_SUBSYS_STATUS_REG0_bt_rf_idle_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG0_bt_rf_idle_Pos)) /* Assigment of value for bt_rf_idle in the BTZBSYS_SUBSYS_STATUS_REG0 register */
#define BTZBSYS_SUBSYS_STATUS_REG0_Msk        _UINT32_(0x00030007)                                 /* (BTZBSYS_SUBSYS_STATUS_REG0) Register Mask  */


/* -------- BTZBSYS_SUBSYS_STATUS_REG1 : (BTZBSYS Offset: 0x24) (R/W 32) SUBSYS_STATUS_REG1 -------- */
#define BTZBSYS_SUBSYS_STATUS_REG1_RESETVALUE _UINT32_(0x00)                                       /*  (BTZBSYS_SUBSYS_STATUS_REG1) SUBSYS_STATUS_REG1  Reset Value */

#define BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Pos _UINT32_(0)                                          /* (BTZBSYS_SUBSYS_STATUS_REG1) xtal_ready_out Position */
#define BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG1) xtal_ready_out Mask */
#define BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out(value) (BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Pos)) /* Assigment of value for xtal_ready_out in the BTZBSYS_SUBSYS_STATUS_REG1 register */
#define BTZBSYS_SUBSYS_STATUS_REG1_pll_lock_out_Pos _UINT32_(1)                                          /* (BTZBSYS_SUBSYS_STATUS_REG1) pll_lock_out Position */
#define BTZBSYS_SUBSYS_STATUS_REG1_pll_lock_out_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG1_pll_lock_out_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG1) pll_lock_out Mask */
#define BTZBSYS_SUBSYS_STATUS_REG1_pll_lock_out(value) (BTZBSYS_SUBSYS_STATUS_REG1_pll_lock_out_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG1_pll_lock_out_Pos)) /* Assigment of value for pll_lock_out in the BTZBSYS_SUBSYS_STATUS_REG1 register */
#define BTZBSYS_SUBSYS_STATUS_REG1_XTAL_ready_Pos _UINT32_(2)                                          /* (BTZBSYS_SUBSYS_STATUS_REG1) XTAL_ready Position */
#define BTZBSYS_SUBSYS_STATUS_REG1_XTAL_ready_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG1_XTAL_ready_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG1) XTAL_ready Mask */
#define BTZBSYS_SUBSYS_STATUS_REG1_XTAL_ready(value) (BTZBSYS_SUBSYS_STATUS_REG1_XTAL_ready_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG1_XTAL_ready_Pos)) /* Assigment of value for XTAL_ready in the BTZBSYS_SUBSYS_STATUS_REG1 register */
#define BTZBSYS_SUBSYS_STATUS_REG1_PLL_locked_Pos _UINT32_(3)                                          /* (BTZBSYS_SUBSYS_STATUS_REG1) PLL_locked Position */
#define BTZBSYS_SUBSYS_STATUS_REG1_PLL_locked_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG1_PLL_locked_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG1) PLL_locked Mask */
#define BTZBSYS_SUBSYS_STATUS_REG1_PLL_locked(value) (BTZBSYS_SUBSYS_STATUS_REG1_PLL_locked_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG1_PLL_locked_Pos)) /* Assigment of value for PLL_locked in the BTZBSYS_SUBSYS_STATUS_REG1 register */
#define BTZBSYS_SUBSYS_STATUS_REG1_clk_lp_ready_Pos _UINT32_(4)                                          /* (BTZBSYS_SUBSYS_STATUS_REG1) clk_lp_ready Position */
#define BTZBSYS_SUBSYS_STATUS_REG1_clk_lp_ready_Msk (_UINT32_(0x1) << BTZBSYS_SUBSYS_STATUS_REG1_clk_lp_ready_Pos) /* (BTZBSYS_SUBSYS_STATUS_REG1) clk_lp_ready Mask */
#define BTZBSYS_SUBSYS_STATUS_REG1_clk_lp_ready(value) (BTZBSYS_SUBSYS_STATUS_REG1_clk_lp_ready_Msk & (_UINT32_(value) << BTZBSYS_SUBSYS_STATUS_REG1_clk_lp_ready_Pos)) /* Assigment of value for clk_lp_ready in the BTZBSYS_SUBSYS_STATUS_REG1 register */
#define BTZBSYS_SUBSYS_STATUS_REG1_Msk        _UINT32_(0x0000001F)                                 /* (BTZBSYS_SUBSYS_STATUS_REG1) Register Mask  */


/** \brief BTZBSYS register offsets definitions */
#define BTZBSYS_SUBSYS_CNTRL_REG0_REG_OFST _UINT32_(0x00)      /* (BTZBSYS_SUBSYS_CNTRL_REG0) SUBSYS_CNTRL_REG0 Offset */
#define BTZBSYS_SUBSYS_CNTRL_REG1_REG_OFST _UINT32_(0x04)      /* (BTZBSYS_SUBSYS_CNTRL_REG1) SUBSYS_CNTRL_REG1 Offset */
#define BTZBSYS_SUBSYS_STATUS_REG0_REG_OFST _UINT32_(0x20)      /* (BTZBSYS_SUBSYS_STATUS_REG0) SUBSYS_STATUS_REG0 Offset */
#define BTZBSYS_SUBSYS_STATUS_REG1_REG_OFST _UINT32_(0x24)      /* (BTZBSYS_SUBSYS_STATUS_REG1) SUBSYS_STATUS_REG1 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief BTZBSYS register API structure */
typedef struct
{  /*  */
  __IO  uint32_t                       BTZBSYS_SUBSYS_CNTRL_REG0; /**< Offset: 0x00 (R/W  32) SUBSYS_CNTRL_REG0 */
  __IO  uint32_t                       BTZBSYS_SUBSYS_CNTRL_REG1; /**< Offset: 0x04 (R/W  32) SUBSYS_CNTRL_REG1 */
  __I   uint8_t                        Reserved1[0x18];
  __IO  uint32_t                       BTZBSYS_SUBSYS_STATUS_REG0; /**< Offset: 0x20 (R/W  32) SUBSYS_STATUS_REG0 */
  __IO  uint32_t                       BTZBSYS_SUBSYS_STATUS_REG1; /**< Offset: 0x24 (R/W  32) SUBSYS_STATUS_REG1 */
} btzbsys_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_BTZBSYS_COMPONENT_H_ */
