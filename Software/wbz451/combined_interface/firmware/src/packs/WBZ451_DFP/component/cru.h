/*
 * Component description for CRU
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
#ifndef _BZ45_CRU_COMPONENT_H_
#define _BZ45_CRU_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR CRU                                          */
/* ************************************************************************** */

/* -------- CRU_OSCCON : (CRU Offset: 0x00) (R/W 32) CRU OSCILLATOR CONTROL REGISTER -------- */
#define CRU_OSCCON_RESETVALUE                 _UINT32_(0x100)                                      /*  (CRU_OSCCON) CRU OSCILLATOR CONTROL REGISTER  Reset Value */

#define CRU_OSCCON_OSWEN_Pos                  _UINT32_(0)                                          /* (CRU_OSCCON) Oscillator Switch Enable bit Position */
#define CRU_OSCCON_OSWEN_Msk                  (_UINT32_(0x1) << CRU_OSCCON_OSWEN_Pos)              /* (CRU_OSCCON) Oscillator Switch Enable bit Mask */
#define CRU_OSCCON_OSWEN(value)               (CRU_OSCCON_OSWEN_Msk & (_UINT32_(value) << CRU_OSCCON_OSWEN_Pos)) /* Assigment of value for OSWEN in the CRU_OSCCON register */
#define   CRU_OSCCON_OSWEN_SWITCH_Val         _UINT32_(0x1)                                        /* (CRU_OSCCON) Request oscillator switch to selection specified by NOSC[3:0] bits  */
#define   CRU_OSCCON_OSWEN_SWITCH_COMPLETE_Val _UINT32_(0x0)                                        /* (CRU_OSCCON) Oscillator switch is complete  */
#define CRU_OSCCON_OSWEN_SWITCH               (CRU_OSCCON_OSWEN_SWITCH_Val << CRU_OSCCON_OSWEN_Pos) /* (CRU_OSCCON) Request oscillator switch to selection specified by NOSC[3:0] bits Position  */
#define CRU_OSCCON_OSWEN_SWITCH_COMPLETE      (CRU_OSCCON_OSWEN_SWITCH_COMPLETE_Val << CRU_OSCCON_OSWEN_Pos) /* (CRU_OSCCON) Oscillator switch is complete Position  */
#define CRU_OSCCON_SOSCEN_Pos                 _UINT32_(1)                                          /* (CRU_OSCCON) 32 kHz Secondary (LP) Oscillator Enable bit Position */
#define CRU_OSCCON_SOSCEN_Msk                 (_UINT32_(0x1) << CRU_OSCCON_SOSCEN_Pos)             /* (CRU_OSCCON) 32 kHz Secondary (LP) Oscillator Enable bit Mask */
#define CRU_OSCCON_SOSCEN(value)              (CRU_OSCCON_SOSCEN_Msk & (_UINT32_(value) << CRU_OSCCON_SOSCEN_Pos)) /* Assigment of value for SOSCEN in the CRU_OSCCON register */
#define   CRU_OSCCON_SOSCEN_ON_Val            _UINT32_(0x1)                                        /* (CRU_OSCCON) Enable Secondary Oscillator  */
#define   CRU_OSCCON_SOSCEN_OFF_Val           _UINT32_(0x0)                                        /* (CRU_OSCCON) Disable Secondary Oscillator  */
#define CRU_OSCCON_SOSCEN_ON                  (CRU_OSCCON_SOSCEN_ON_Val << CRU_OSCCON_SOSCEN_Pos)  /* (CRU_OSCCON) Enable Secondary Oscillator Position  */
#define CRU_OSCCON_SOSCEN_OFF                 (CRU_OSCCON_SOSCEN_OFF_Val << CRU_OSCCON_SOSCEN_Pos) /* (CRU_OSCCON) Disable Secondary Oscillator Position  */
#define CRU_OSCCON_CF_Pos                     _UINT32_(3)                                          /* (CRU_OSCCON) Clock Fail Detect bit (Read / writable / Clearable by application) Position */
#define CRU_OSCCON_CF_Msk                     (_UINT32_(0x1) << CRU_OSCCON_CF_Pos)                 /* (CRU_OSCCON) Clock Fail Detect bit (Read / writable / Clearable by application) Mask */
#define CRU_OSCCON_CF(value)                  (CRU_OSCCON_CF_Msk & (_UINT32_(value) << CRU_OSCCON_CF_Pos)) /* Assigment of value for CF in the CRU_OSCCON register */
#define   CRU_OSCCON_CF_FAIL_DET_Val          _UINT32_(0x1)                                        /* (CRU_OSCCON) FSCM has detected clock failure  */
#define   CRU_OSCCON_CF_NO_FAILDET_Val        _UINT32_(0x0)                                        /* (CRU_OSCCON) FSCM has not detected clock failure  */
#define CRU_OSCCON_CF_FAIL_DET                (CRU_OSCCON_CF_FAIL_DET_Val << CRU_OSCCON_CF_Pos)    /* (CRU_OSCCON) FSCM has detected clock failure Position  */
#define CRU_OSCCON_CF_NO_FAILDET              (CRU_OSCCON_CF_NO_FAILDET_Val << CRU_OSCCON_CF_Pos)  /* (CRU_OSCCON) FSCM has not detected clock failure Position  */
#define CRU_OSCCON_SLPEN_Pos                  _UINT32_(4)                                          /* (CRU_OSCCON) Enable SLEEP Mode bit Position */
#define CRU_OSCCON_SLPEN_Msk                  (_UINT32_(0x1) << CRU_OSCCON_SLPEN_Pos)              /* (CRU_OSCCON) Enable SLEEP Mode bit Mask */
#define CRU_OSCCON_SLPEN(value)               (CRU_OSCCON_SLPEN_Msk & (_UINT32_(value) << CRU_OSCCON_SLPEN_Pos)) /* Assigment of value for SLPEN in the CRU_OSCCON register */
#define   CRU_OSCCON_SLPEN_SLEEP_Val          _UINT32_(0x1)                                        /* (CRU_OSCCON) When a WAIT Instruction is executed device will enter SLEEP Mode  */
#define   CRU_OSCCON_SLPEN_IDLE_Val           _UINT32_(0x0)                                        /* (CRU_OSCCON) When a WAIT instruction is executed device will enter IDLE Mode  */
#define CRU_OSCCON_SLPEN_SLEEP                (CRU_OSCCON_SLPEN_SLEEP_Val << CRU_OSCCON_SLPEN_Pos) /* (CRU_OSCCON) When a WAIT Instruction is executed device will enter SLEEP Mode Position  */
#define CRU_OSCCON_SLPEN_IDLE                 (CRU_OSCCON_SLPEN_IDLE_Val << CRU_OSCCON_SLPEN_Pos)  /* (CRU_OSCCON) When a WAIT instruction is executed device will enter IDLE Mode Position  */
#define CRU_OSCCON_CLKLOCK_Pos                _UINT32_(7)                                          /* (CRU_OSCCON) Clock Lock Enabled bit Position */
#define CRU_OSCCON_CLKLOCK_Msk                (_UINT32_(0x1) << CRU_OSCCON_CLKLOCK_Pos)            /* (CRU_OSCCON) Clock Lock Enabled bit Mask */
#define CRU_OSCCON_CLKLOCK(value)             (CRU_OSCCON_CLKLOCK_Msk & (_UINT32_(value) << CRU_OSCCON_CLKLOCK_Pos)) /* Assigment of value for CLKLOCK in the CRU_OSCCON register */
#define   CRU_OSCCON_CLKLOCK_LOCKED_Val       _UINT32_(0x1)                                        /* (CRU_OSCCON) All clock and PLL configuration registers are locked.  These include OSCCON, OSCTRIM, SPLLCON, UPLLCON, PBxDIV  */
#define   CRU_OSCCON_CLKLOCK_UNLOCKED_Val     _UINT32_(0x0)                                        /* (CRU_OSCCON) Clock and PLL selection registers are not locked, configurations may be modified  */
#define CRU_OSCCON_CLKLOCK_LOCKED             (CRU_OSCCON_CLKLOCK_LOCKED_Val << CRU_OSCCON_CLKLOCK_Pos) /* (CRU_OSCCON) All clock and PLL configuration registers are locked.  These include OSCCON, OSCTRIM, SPLLCON, UPLLCON, PBxDIV Position  */
#define CRU_OSCCON_CLKLOCK_UNLOCKED           (CRU_OSCCON_CLKLOCK_UNLOCKED_Val << CRU_OSCCON_CLKLOCK_Pos) /* (CRU_OSCCON) Clock and PLL selection registers are not locked, configurations may be modified Position  */
#define CRU_OSCCON_NOSC_Pos                   _UINT32_(8)                                          /* (CRU_OSCCON) New Oscillator Selection bits Position */
#define CRU_OSCCON_NOSC_Msk                   (_UINT32_(0xF) << CRU_OSCCON_NOSC_Pos)               /* (CRU_OSCCON) New Oscillator Selection bits Mask */
#define CRU_OSCCON_NOSC(value)                (CRU_OSCCON_NOSC_Msk & (_UINT32_(value) << CRU_OSCCON_NOSC_Pos)) /* Assigment of value for NOSC in the CRU_OSCCON register */
#define   CRU_OSCCON_NOSC_FRCDIV_Val          _UINT32_(0x0)                                        /* (CRU_OSCCON) Fast RC Oscillator (FRC) divided by OSCCON.FRCDIV ( Supports FRC/16 and FRC/1)  */
#define   CRU_OSCCON_NOSC_SPLL_Val            _UINT32_(0x1)                                        /* (CRU_OSCCON) System PLL (SPLL1 Module) (input clock and divider set by SPLLCON)  */
#define   CRU_OSCCON_NOSC_POSC_Val            _UINT32_(0x2)                                        /* (CRU_OSCCON) Primary Oscillator  */
#define   CRU_OSCCON_NOSC_SOSC_Val            _UINT32_(0x3)                                        /* (CRU_OSCCON) Secondary Oscillator (SOSC)  */
#define   CRU_OSCCON_NOSC_LPRC_Val            _UINT32_(0x4)                                        /* (CRU_OSCCON) Low Power RC Oscillator (LPRC)  */
#define CRU_OSCCON_NOSC_FRCDIV                (CRU_OSCCON_NOSC_FRCDIV_Val << CRU_OSCCON_NOSC_Pos)  /* (CRU_OSCCON) Fast RC Oscillator (FRC) divided by OSCCON.FRCDIV ( Supports FRC/16 and FRC/1) Position  */
#define CRU_OSCCON_NOSC_SPLL                  (CRU_OSCCON_NOSC_SPLL_Val << CRU_OSCCON_NOSC_Pos)    /* (CRU_OSCCON) System PLL (SPLL1 Module) (input clock and divider set by SPLLCON) Position  */
#define CRU_OSCCON_NOSC_POSC                  (CRU_OSCCON_NOSC_POSC_Val << CRU_OSCCON_NOSC_Pos)    /* (CRU_OSCCON) Primary Oscillator Position  */
#define CRU_OSCCON_NOSC_SOSC                  (CRU_OSCCON_NOSC_SOSC_Val << CRU_OSCCON_NOSC_Pos)    /* (CRU_OSCCON) Secondary Oscillator (SOSC) Position  */
#define CRU_OSCCON_NOSC_LPRC                  (CRU_OSCCON_NOSC_LPRC_Val << CRU_OSCCON_NOSC_Pos)    /* (CRU_OSCCON) Low Power RC Oscillator (LPRC) Position  */
#define CRU_OSCCON_COSC_Pos                   _UINT32_(12)                                         /* (CRU_OSCCON) Current Oscillator Selection bits (Read-only) Position */
#define CRU_OSCCON_COSC_Msk                   (_UINT32_(0xF) << CRU_OSCCON_COSC_Pos)               /* (CRU_OSCCON) Current Oscillator Selection bits (Read-only) Mask */
#define CRU_OSCCON_COSC(value)                (CRU_OSCCON_COSC_Msk & (_UINT32_(value) << CRU_OSCCON_COSC_Pos)) /* Assigment of value for COSC in the CRU_OSCCON register */
#define   CRU_OSCCON_COSC_FRCDIV_Val          _UINT32_(0x0)                                        /* (CRU_OSCCON) Fast RC Oscillator (FRC) divided by OSCCON.FRCDIV (Supports FRC/16 and FRC/1)  */
#define   CRU_OSCCON_COSC_SPLL_Val            _UINT32_(0x1)                                        /* (CRU_OSCCON) System PLL (SPLL1 Module) (input clock and divider set by SPLLCON)  */
#define   CRU_OSCCON_COSC_POSC_Val            _UINT32_(0x2)                                        /* (CRU_OSCCON) Primary Oscillator- POSC  */
#define   CRU_OSCCON_COSC_SOSC_Val            _UINT32_(0x3)                                        /* (CRU_OSCCON) Secondary Oscillator (SOSC)  */
#define   CRU_OSCCON_COSC_LPRC_Val            _UINT32_(0x4)                                        /* (CRU_OSCCON) Low Power RC Oscillator (LPRC)  */
#define CRU_OSCCON_COSC_FRCDIV                (CRU_OSCCON_COSC_FRCDIV_Val << CRU_OSCCON_COSC_Pos)  /* (CRU_OSCCON) Fast RC Oscillator (FRC) divided by OSCCON.FRCDIV (Supports FRC/16 and FRC/1) Position  */
#define CRU_OSCCON_COSC_SPLL                  (CRU_OSCCON_COSC_SPLL_Val << CRU_OSCCON_COSC_Pos)    /* (CRU_OSCCON) System PLL (SPLL1 Module) (input clock and divider set by SPLLCON) Position  */
#define CRU_OSCCON_COSC_POSC                  (CRU_OSCCON_COSC_POSC_Val << CRU_OSCCON_COSC_Pos)    /* (CRU_OSCCON) Primary Oscillator- POSC Position  */
#define CRU_OSCCON_COSC_SOSC                  (CRU_OSCCON_COSC_SOSC_Val << CRU_OSCCON_COSC_Pos)    /* (CRU_OSCCON) Secondary Oscillator (SOSC) Position  */
#define CRU_OSCCON_COSC_LPRC                  (CRU_OSCCON_COSC_LPRC_Val << CRU_OSCCON_COSC_Pos)    /* (CRU_OSCCON) Low Power RC Oscillator (LPRC) Position  */
#define CRU_OSCCON_WAKE2SPD_Pos               _UINT32_(21)                                         /* (CRU_OSCCON) 2-Speed startup enabled in Sleep mode bit Position */
#define CRU_OSCCON_WAKE2SPD_Msk               (_UINT32_(0x1) << CRU_OSCCON_WAKE2SPD_Pos)           /* (CRU_OSCCON) 2-Speed startup enabled in Sleep mode bit Mask */
#define CRU_OSCCON_WAKE2SPD(value)            (CRU_OSCCON_WAKE2SPD_Msk & (_UINT32_(value) << CRU_OSCCON_WAKE2SPD_Pos)) /* Assigment of value for WAKE2SPD in the CRU_OSCCON register */
#define   CRU_OSCCON_WAKE2SPD_FRC_Val         _UINT32_(0x1)                                        /* (CRU_OSCCON) When the device EXITS Sleep Mode, the sys_clk will be from FRC until the selected clock is ready  */
#define   CRU_OSCCON_WAKE2SPD_SELECTED_CLK_Val _UINT32_(0x0)                                        /* (CRU_OSCCON) When the device EXITS Sleep Mode, the sys_clk will be from the selected clock.  */
#define CRU_OSCCON_WAKE2SPD_FRC               (CRU_OSCCON_WAKE2SPD_FRC_Val << CRU_OSCCON_WAKE2SPD_Pos) /* (CRU_OSCCON) When the device EXITS Sleep Mode, the sys_clk will be from FRC until the selected clock is ready Position  */
#define CRU_OSCCON_WAKE2SPD_SELECTED_CLK      (CRU_OSCCON_WAKE2SPD_SELECTED_CLK_Val << CRU_OSCCON_WAKE2SPD_Pos) /* (CRU_OSCCON) When the device EXITS Sleep Mode, the sys_clk will be from the selected clock. Position  */
#define CRU_OSCCON_DRMEN_Pos                  _UINT32_(23)                                         /* (CRU_OSCCON) Enable Dream Mode bit Position */
#define CRU_OSCCON_DRMEN_Msk                  (_UINT32_(0x1) << CRU_OSCCON_DRMEN_Pos)              /* (CRU_OSCCON) Enable Dream Mode bit Mask */
#define CRU_OSCCON_DRMEN(value)               (CRU_OSCCON_DRMEN_Msk & (_UINT32_(value) << CRU_OSCCON_DRMEN_Pos)) /* Assigment of value for DRMEN in the CRU_OSCCON register */
#define   CRU_OSCCON_DRMEN_SLEEP_Val          _UINT32_(0x1)                                        /* (CRU_OSCCON) When the cpu_si_sleep input is asserted and SLPEN = 1, DMA transfer complete causes SLEEP Mode to be entered  */
#define   CRU_OSCCON_DRMEN_NO_EFFECT_Val      _UINT32_(0x0)                                        /* (CRU_OSCCON) DMA transfer has no effect  */
#define CRU_OSCCON_DRMEN_SLEEP                (CRU_OSCCON_DRMEN_SLEEP_Val << CRU_OSCCON_DRMEN_Pos) /* (CRU_OSCCON) When the cpu_si_sleep input is asserted and SLPEN = 1, DMA transfer complete causes SLEEP Mode to be entered Position  */
#define CRU_OSCCON_DRMEN_NO_EFFECT            (CRU_OSCCON_DRMEN_NO_EFFECT_Val << CRU_OSCCON_DRMEN_Pos) /* (CRU_OSCCON) DMA transfer has no effect Position  */
#define CRU_OSCCON_FRCDIV_Pos                 _UINT32_(24)                                         /* (CRU_OSCCON) Fast RC Clock Divider bits Position */
#define CRU_OSCCON_FRCDIV_Msk                 (_UINT32_(0x7) << CRU_OSCCON_FRCDIV_Pos)             /* (CRU_OSCCON) Fast RC Clock Divider bits Mask */
#define CRU_OSCCON_FRCDIV(value)              (CRU_OSCCON_FRCDIV_Msk & (_UINT32_(value) << CRU_OSCCON_FRCDIV_Pos)) /* Assigment of value for FRCDIV in the CRU_OSCCON register */
#define   CRU_OSCCON_FRCDIV_DIV_1_Val         _UINT32_(0x0)                                        /* (CRU_OSCCON) FRC Divide by 1  */
#define   CRU_OSCCON_FRCDIV_DIV_2_Val         _UINT32_(0x1)                                        /* (CRU_OSCCON) FRC Divide by 2  */
#define   CRU_OSCCON_FRCDIV_DIV_4_Val         _UINT32_(0x2)                                        /* (CRU_OSCCON) FRC Divide by 4  */
#define   CRU_OSCCON_FRCDIV_DIV_8_Val         _UINT32_(0x3)                                        /* (CRU_OSCCON) FRC Divide by 8  */
#define   CRU_OSCCON_FRCDIV_DIV_16_Val        _UINT32_(0x4)                                        /* (CRU_OSCCON) FRC Divide by 16  */
#define   CRU_OSCCON_FRCDIV_DIV_32_Val        _UINT32_(0x5)                                        /* (CRU_OSCCON) FRC Divide by 32  */
#define   CRU_OSCCON_FRCDIV_DIV_64_Val        _UINT32_(0x6)                                        /* (CRU_OSCCON) FRC Divide by 64  */
#define   CRU_OSCCON_FRCDIV_DIV_256_Val       _UINT32_(0x7)                                        /* (CRU_OSCCON) FRC Divide by 256  */
#define CRU_OSCCON_FRCDIV_DIV_1               (CRU_OSCCON_FRCDIV_DIV_1_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 1 Position  */
#define CRU_OSCCON_FRCDIV_DIV_2               (CRU_OSCCON_FRCDIV_DIV_2_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 2 Position  */
#define CRU_OSCCON_FRCDIV_DIV_4               (CRU_OSCCON_FRCDIV_DIV_4_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 4 Position  */
#define CRU_OSCCON_FRCDIV_DIV_8               (CRU_OSCCON_FRCDIV_DIV_8_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 8 Position  */
#define CRU_OSCCON_FRCDIV_DIV_16              (CRU_OSCCON_FRCDIV_DIV_16_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 16 Position  */
#define CRU_OSCCON_FRCDIV_DIV_32              (CRU_OSCCON_FRCDIV_DIV_32_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 32 Position  */
#define CRU_OSCCON_FRCDIV_DIV_64              (CRU_OSCCON_FRCDIV_DIV_64_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 64 Position  */
#define CRU_OSCCON_FRCDIV_DIV_256             (CRU_OSCCON_FRCDIV_DIV_256_Val << CRU_OSCCON_FRCDIV_Pos) /* (CRU_OSCCON) FRC Divide by 256 Position  */
#define CRU_OSCCON_Msk                        _UINT32_(0x07A0FF9B)                                 /* (CRU_OSCCON) Register Mask  */


/* -------- CRU_OSCCONCLR : (CRU Offset: 0x04) (R/W 32)  -------- */
#define CRU_OSCCONCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_OSCCONCLR)   Reset Value */

#define CRU_OSCCONCLR_Msk                     _UINT32_(0x00000000)                                 /* (CRU_OSCCONCLR) Register Mask  */


/* -------- CRU_OSCCONSET : (CRU Offset: 0x08) (R/W 32)  -------- */
#define CRU_OSCCONSET_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_OSCCONSET)   Reset Value */

#define CRU_OSCCONSET_Msk                     _UINT32_(0x00000000)                                 /* (CRU_OSCCONSET) Register Mask  */


/* -------- CRU_OSCCONINV : (CRU Offset: 0x0C) (R/W 32)  -------- */
#define CRU_OSCCONINV_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_OSCCONINV)   Reset Value */

#define CRU_OSCCONINV_Msk                     _UINT32_(0x00000000)                                 /* (CRU_OSCCONINV) Register Mask  */


/* -------- CRU_OSCTUN : (CRU Offset: 0x10) (R/W 32) CRU OSCILLATOR TRIMMING REGISTER -------- */
#define CRU_OSCTUN_RESETVALUE                 _UINT32_(0x00)                                       /*  (CRU_OSCTUN) CRU OSCILLATOR TRIMMING REGISTER  Reset Value */

#define CRU_OSCTUN_TUN_Pos                    _UINT32_(0)                                          /* (CRU_OSCTUN) Internal Fast RC (FRC) Oscillator Tuning bits Position */
#define CRU_OSCTUN_TUN_Msk                    (_UINT32_(0x3F) << CRU_OSCTUN_TUN_Pos)               /* (CRU_OSCTUN) Internal Fast RC (FRC) Oscillator Tuning bits Mask */
#define CRU_OSCTUN_TUN(value)                 (CRU_OSCTUN_TUN_Msk & (_UINT32_(value) << CRU_OSCTUN_TUN_Pos)) /* Assigment of value for TUN in the CRU_OSCTUN register */
#define   CRU_OSCTUN_TUN_Max_Val              _UINT32_(0x1F)                                       /* (CRU_OSCTUN) Maximum Frequency  */
#define   CRU_OSCTUN_TUN_Center_Val           _UINT32_(0x0)                                        /* (CRU_OSCTUN) Center Frequency, oscillator is running at calibrated frequency  */
#define   CRU_OSCTUN_TUN_Min_Val              _UINT32_(0x20)                                       /* (CRU_OSCTUN) Minimum Frequency  */
#define CRU_OSCTUN_TUN_Max                    (CRU_OSCTUN_TUN_Max_Val << CRU_OSCTUN_TUN_Pos)       /* (CRU_OSCTUN) Maximum Frequency Position  */
#define CRU_OSCTUN_TUN_Center                 (CRU_OSCTUN_TUN_Center_Val << CRU_OSCTUN_TUN_Pos)    /* (CRU_OSCTUN) Center Frequency, oscillator is running at calibrated frequency Position  */
#define CRU_OSCTUN_TUN_Min                    (CRU_OSCTUN_TUN_Min_Val << CRU_OSCTUN_TUN_Pos)       /* (CRU_OSCTUN) Minimum Frequency Position  */
#define CRU_OSCTUN_Msk                        _UINT32_(0x0000003F)                                 /* (CRU_OSCTUN) Register Mask  */


/* -------- CRU_OSCTUNCLR : (CRU Offset: 0x14) (R/W 32)  -------- */
#define CRU_OSCTUNCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_OSCTUNCLR)   Reset Value */

#define CRU_OSCTUNCLR_Msk                     _UINT32_(0x00000000)                                 /* (CRU_OSCTUNCLR) Register Mask  */


/* -------- CRU_OSCTUNSET : (CRU Offset: 0x18) (R/W 32)  -------- */
#define CRU_OSCTUNSET_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_OSCTUNSET)   Reset Value */

#define CRU_OSCTUNSET_Msk                     _UINT32_(0x00000000)                                 /* (CRU_OSCTUNSET) Register Mask  */


/* -------- CRU_OSCTUNINV : (CRU Offset: 0x1C) (R/W 32)  -------- */
#define CRU_OSCTUNINV_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_OSCTUNINV)   Reset Value */

#define CRU_OSCTUNINV_Msk                     _UINT32_(0x00000000)                                 /* (CRU_OSCTUNINV) Register Mask  */


/* -------- CRU_SPLLCON : (CRU Offset: 0x20) (R/W 32) SPLL CONTROL REGISTER -------- */
#define CRU_SPLLCON_RESETVALUE                _UINT32_(0xC0000108)                                 /*  (CRU_SPLLCON) SPLL CONTROL REGISTER  Reset Value */

#define CRU_SPLLCON_SPLLPWDN_Pos              _UINT32_(3)                                          /* (CRU_SPLLCON) PLL Power Down Register bit Position */
#define CRU_SPLLCON_SPLLPWDN_Msk              (_UINT32_(0x1) << CRU_SPLLCON_SPLLPWDN_Pos)          /* (CRU_SPLLCON) PLL Power Down Register bit Mask */
#define CRU_SPLLCON_SPLLPWDN(value)           (CRU_SPLLCON_SPLLPWDN_Msk & (_UINT32_(value) << CRU_SPLLCON_SPLLPWDN_Pos)) /* Assigment of value for SPLLPWDN in the CRU_SPLLCON register */
#define   CRU_SPLLCON_SPLLPWDN_PLL_OFF_Val    _UINT32_(0x1)                                        /* (CRU_SPLLCON) PLL is powered down  */
#define   CRU_SPLLCON_SPLLPWDN_PLL_ON_Val     _UINT32_(0x0)                                        /* (CRU_SPLLCON) PLL is active  */
#define CRU_SPLLCON_SPLLPWDN_PLL_OFF          (CRU_SPLLCON_SPLLPWDN_PLL_OFF_Val << CRU_SPLLCON_SPLLPWDN_Pos) /* (CRU_SPLLCON) PLL is powered down Position  */
#define CRU_SPLLCON_SPLLPWDN_PLL_ON           (CRU_SPLLCON_SPLLPWDN_PLL_ON_Val << CRU_SPLLCON_SPLLPWDN_Pos) /* (CRU_SPLLCON) PLL is active Position  */
#define CRU_SPLLCON_SPLLFLOCK_Pos             _UINT32_(4)                                          /* (CRU_SPLLCON) System PLL Force Lock Position */
#define CRU_SPLLCON_SPLLFLOCK_Msk             (_UINT32_(0x1) << CRU_SPLLCON_SPLLFLOCK_Pos)         /* (CRU_SPLLCON) System PLL Force Lock Mask */
#define CRU_SPLLCON_SPLLFLOCK(value)          (CRU_SPLLCON_SPLLFLOCK_Msk & (_UINT32_(value) << CRU_SPLLCON_SPLLFLOCK_Pos)) /* Assigment of value for SPLLFLOCK in the CRU_SPLLCON register */
#define   CRU_SPLLCON_SPLLFLOCK_ASSERT_Val    _UINT32_(0x1)                                        /* (CRU_SPLLCON) Force the SPLL lock signal to be asserted  */
#define   CRU_SPLLCON_SPLLFLOCK_NO_ASSERT_Val _UINT32_(0x0)                                        /* (CRU_SPLLCON) Do not force the SPLL lock signal to be asserted  */
#define CRU_SPLLCON_SPLLFLOCK_ASSERT          (CRU_SPLLCON_SPLLFLOCK_ASSERT_Val << CRU_SPLLCON_SPLLFLOCK_Pos) /* (CRU_SPLLCON) Force the SPLL lock signal to be asserted Position  */
#define CRU_SPLLCON_SPLLFLOCK_NO_ASSERT       (CRU_SPLLCON_SPLLFLOCK_NO_ASSERT_Val << CRU_SPLLCON_SPLLFLOCK_Pos) /* (CRU_SPLLCON) Do not force the SPLL lock signal to be asserted Position  */
#define CRU_SPLLCON_SPLLRST_Pos               _UINT32_(5)                                          /* (CRU_SPLLCON) System PLL Reset Position */
#define CRU_SPLLCON_SPLLRST_Msk               (_UINT32_(0x1) << CRU_SPLLCON_SPLLRST_Pos)           /* (CRU_SPLLCON) System PLL Reset Mask */
#define CRU_SPLLCON_SPLLRST(value)            (CRU_SPLLCON_SPLLRST_Msk & (_UINT32_(value) << CRU_SPLLCON_SPLLRST_Pos)) /* Assigment of value for SPLLRST in the CRU_SPLLCON register */
#define   CRU_SPLLCON_SPLLRST_ASSERT_Val      _UINT32_(0x1)                                        /* (CRU_SPLLCON) Assert the reset to the SPLL  */
#define   CRU_SPLLCON_SPLLRST_NO_ASSERT_Val   _UINT32_(0x0)                                        /* (CRU_SPLLCON) De-assert the reset to the SPLL  */
#define CRU_SPLLCON_SPLLRST_ASSERT            (CRU_SPLLCON_SPLLRST_ASSERT_Val << CRU_SPLLCON_SPLLRST_Pos) /* (CRU_SPLLCON) Assert the reset to the SPLL Position  */
#define CRU_SPLLCON_SPLLRST_NO_ASSERT         (CRU_SPLLCON_SPLLRST_NO_ASSERT_Val << CRU_SPLLCON_SPLLRST_Pos) /* (CRU_SPLLCON) De-assert the reset to the SPLL Position  */
#define CRU_SPLLCON_SPLLPOSTDIV1_Pos          _UINT32_(8)                                          /* (CRU_SPLLCON) SPLL Clock 1 Divide Value, 1 to 255 Position */
#define CRU_SPLLCON_SPLLPOSTDIV1_Msk          (_UINT32_(0xFF) << CRU_SPLLCON_SPLLPOSTDIV1_Pos)     /* (CRU_SPLLCON) SPLL Clock 1 Divide Value, 1 to 255 Mask */
#define CRU_SPLLCON_SPLLPOSTDIV1(value)       (CRU_SPLLCON_SPLLPOSTDIV1_Msk & (_UINT32_(value) << CRU_SPLLCON_SPLLPOSTDIV1_Pos)) /* Assigment of value for SPLLPOSTDIV1 in the CRU_SPLLCON register */
#define CRU_SPLLCON_SPLLPOSTDIV2_Pos          _UINT32_(16)                                         /* (CRU_SPLLCON) SPLL Clock 2 Divide Value, 1 to 15 Position */
#define CRU_SPLLCON_SPLLPOSTDIV2_Msk          (_UINT32_(0xF) << CRU_SPLLCON_SPLLPOSTDIV2_Pos)      /* (CRU_SPLLCON) SPLL Clock 2 Divide Value, 1 to 15 Mask */
#define CRU_SPLLCON_SPLLPOSTDIV2(value)       (CRU_SPLLCON_SPLLPOSTDIV2_Msk & (_UINT32_(value) << CRU_SPLLCON_SPLLPOSTDIV2_Pos)) /* Assigment of value for SPLLPOSTDIV2 in the CRU_SPLLCON register */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DISABLE_Val _UINT32_(0x0)                                        /* (CRU_SPLLCON) Disable  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_1_Val  _UINT32_(0x1)                                        /* (CRU_SPLLCON) Second post divide by 1  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_2_Val  _UINT32_(0x2)                                        /* (CRU_SPLLCON) Second post divide by 2  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_3_Val  _UINT32_(0x3)                                        /* (CRU_SPLLCON) Second post divide by 3  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_4_Val  _UINT32_(0x4)                                        /* (CRU_SPLLCON) Second post divide by 4  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_5_Val  _UINT32_(0x5)                                        /* (CRU_SPLLCON) Second post divide by 5  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_6_Val  _UINT32_(0x6)                                        /* (CRU_SPLLCON) Second post divide by 6  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_7_Val  _UINT32_(0x7)                                        /* (CRU_SPLLCON) Second post divide by 7  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_8_Val  _UINT32_(0x8)                                        /* (CRU_SPLLCON) Second post divide by 8  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_9_Val  _UINT32_(0x9)                                        /* (CRU_SPLLCON) Second post divide by 9  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_10_Val _UINT32_(0xA)                                        /* (CRU_SPLLCON) Second post divide by 10  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_11_Val _UINT32_(0xB)                                        /* (CRU_SPLLCON) Second post divide by 11  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_12_Val _UINT32_(0xC)                                        /* (CRU_SPLLCON) Second post divide by 12  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_13_Val _UINT32_(0xD)                                        /* (CRU_SPLLCON) Second post divide by 13  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_14_Val _UINT32_(0xE)                                        /* (CRU_SPLLCON) Second post divide by 14  */
#define   CRU_SPLLCON_SPLLPOSTDIV2_DIV_15_Val _UINT32_(0xF)                                        /* (CRU_SPLLCON) Second post divide by 15  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DISABLE      (CRU_SPLLCON_SPLLPOSTDIV2_DISABLE_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Disable Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_1        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_1_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 1 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_2        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_2_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 2 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_3        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_3_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 3 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_4        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_4_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 4 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_5        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_5_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 5 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_6        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_6_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 6 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_7        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_7_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 7 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_8        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_8_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 8 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_9        (CRU_SPLLCON_SPLLPOSTDIV2_DIV_9_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 9 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_10       (CRU_SPLLCON_SPLLPOSTDIV2_DIV_10_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 10 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_11       (CRU_SPLLCON_SPLLPOSTDIV2_DIV_11_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 11 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_12       (CRU_SPLLCON_SPLLPOSTDIV2_DIV_12_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 12 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_13       (CRU_SPLLCON_SPLLPOSTDIV2_DIV_13_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 13 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_14       (CRU_SPLLCON_SPLLPOSTDIV2_DIV_14_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 14 Position  */
#define CRU_SPLLCON_SPLLPOSTDIV2_DIV_15       (CRU_SPLLCON_SPLLPOSTDIV2_DIV_15_Val << CRU_SPLLCON_SPLLPOSTDIV2_Pos) /* (CRU_SPLLCON) Second post divide by 15 Position  */
#define CRU_SPLLCON_SPLL_BYP_Pos              _UINT32_(30)                                         /* (CRU_SPLLCON) SPLL Clock 2 Source Position */
#define CRU_SPLLCON_SPLL_BYP_Msk              (_UINT32_(0x3) << CRU_SPLLCON_SPLL_BYP_Pos)          /* (CRU_SPLLCON) SPLL Clock 2 Source Mask */
#define CRU_SPLLCON_SPLL_BYP(value)           (CRU_SPLLCON_SPLL_BYP_Msk & (_UINT32_(value) << CRU_SPLLCON_SPLL_BYP_Pos)) /* Assigment of value for SPLL_BYP in the CRU_SPLLCON register */
#define   CRU_SPLLCON_SPLL_BYP_SPLL3_Val      _UINT32_(0x0)                                        /* (CRU_SPLLCON) SPLL3 (RFPLL) Clock is the clock source for ADC CP Clock Generation.  */
#define   CRU_SPLLCON_SPLL_BYP_FRC_Val        _UINT32_(0x3)                                        /* (CRU_SPLLCON) FRC is used as clock source for ADC CP Clock Generation.  */
#define   CRU_SPLLCON_SPLL_BYP_POSC_Val       _UINT32_(0x2)                                        /* (CRU_SPLLCON) POSC is used as clock source for ADC CP Clock Generation.  */
#define CRU_SPLLCON_SPLL_BYP_SPLL3            (CRU_SPLLCON_SPLL_BYP_SPLL3_Val << CRU_SPLLCON_SPLL_BYP_Pos) /* (CRU_SPLLCON) SPLL3 (RFPLL) Clock is the clock source for ADC CP Clock Generation. Position  */
#define CRU_SPLLCON_SPLL_BYP_FRC              (CRU_SPLLCON_SPLL_BYP_FRC_Val << CRU_SPLLCON_SPLL_BYP_Pos) /* (CRU_SPLLCON) FRC is used as clock source for ADC CP Clock Generation. Position  */
#define CRU_SPLLCON_SPLL_BYP_POSC             (CRU_SPLLCON_SPLL_BYP_POSC_Val << CRU_SPLLCON_SPLL_BYP_Pos) /* (CRU_SPLLCON) POSC is used as clock source for ADC CP Clock Generation. Position  */
#define CRU_SPLLCON_Msk                       _UINT32_(0xC00FFF38)                                 /* (CRU_SPLLCON) Register Mask  */


/* -------- CRU_SPLLCONCLR : (CRU Offset: 0x24) (R/W 32)  -------- */
#define CRU_SPLLCONCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (CRU_SPLLCONCLR)   Reset Value */

#define CRU_SPLLCONCLR_Msk                    _UINT32_(0x00000000)                                 /* (CRU_SPLLCONCLR) Register Mask  */


/* -------- CRU_SPLLCONSET : (CRU Offset: 0x28) (R/W 32)  -------- */
#define CRU_SPLLCONSET_RESETVALUE             _UINT32_(0x00)                                       /*  (CRU_SPLLCONSET)   Reset Value */

#define CRU_SPLLCONSET_Msk                    _UINT32_(0x00000000)                                 /* (CRU_SPLLCONSET) Register Mask  */


/* -------- CRU_SPLLCONINV : (CRU Offset: 0x2C) (R/W 32)  -------- */
#define CRU_SPLLCONINV_RESETVALUE             _UINT32_(0x00)                                       /*  (CRU_SPLLCONINV)   Reset Value */

#define CRU_SPLLCONINV_Msk                    _UINT32_(0x00000000)                                 /* (CRU_SPLLCONINV) Register Mask  */


/* -------- CRU_REFO1CON : (CRU Offset: 0x70) (R/W 32) REFERENCE OSCILLATOR 1 CONTROL REGISTER -------- */
#define CRU_REFO1CON_RESETVALUE               _UINT32_(0x00)                                       /*  (CRU_REFO1CON) REFERENCE OSCILLATOR 1 CONTROL REGISTER  Reset Value */

#define CRU_REFO1CON_ROSEL_Pos                _UINT32_(0)                                          /* (CRU_REFO1CON) Reference Clock Source Select bits Position */
#define CRU_REFO1CON_ROSEL_Msk                (_UINT32_(0xF) << CRU_REFO1CON_ROSEL_Pos)            /* (CRU_REFO1CON) Reference Clock Source Select bits Mask */
#define CRU_REFO1CON_ROSEL(value)             (CRU_REFO1CON_ROSEL_Msk & (_UINT32_(value) << CRU_REFO1CON_ROSEL_Pos)) /* Assigment of value for ROSEL in the CRU_REFO1CON register */
#define   CRU_REFO1CON_ROSEL_REFCLKI_Val      _UINT32_(0x8)                                        /* (CRU_REFO1CON) REFI Pin  */
#define   CRU_REFO1CON_ROSEL_SYSCLK_Val       _UINT32_(0x7)                                        /* (CRU_REFO1CON) System clock (reference clock reflects any device clock switching)  */
#define   CRU_REFO1CON_ROSEL_PBCLK1_Val       _UINT32_(0x6)                                        /* (CRU_REFO1CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching)  */
#define   CRU_REFO1CON_ROSEL_SPLL3_Val        _UINT32_(0x5)                                        /* (CRU_REFO1CON) System PLL3 (Clock-3)  */
#define   CRU_REFO1CON_ROSEL_LPRC_Val         _UINT32_(0x4)                                        /* (CRU_REFO1CON) LPRC  */
#define   CRU_REFO1CON_ROSEL_SOSC_Val         _UINT32_(0x3)                                        /* (CRU_REFO1CON) SOSC  */
#define   CRU_REFO1CON_ROSEL_POSC_Val         _UINT32_(0x2)                                        /* (CRU_REFO1CON) POSC  */
#define   CRU_REFO1CON_ROSEL_SPLL1_Val        _UINT32_(0x1)                                        /* (CRU_REFO1CON) System PLL1 (Clock-1)  */
#define   CRU_REFO1CON_ROSEL_FRC_Val          _UINT32_(0x0)                                        /* (CRU_REFO1CON) FRC  */
#define CRU_REFO1CON_ROSEL_REFCLKI            (CRU_REFO1CON_ROSEL_REFCLKI_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) REFI Pin Position  */
#define CRU_REFO1CON_ROSEL_SYSCLK             (CRU_REFO1CON_ROSEL_SYSCLK_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) System clock (reference clock reflects any device clock switching) Position  */
#define CRU_REFO1CON_ROSEL_PBCLK1             (CRU_REFO1CON_ROSEL_PBCLK1_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching) Position  */
#define CRU_REFO1CON_ROSEL_SPLL3              (CRU_REFO1CON_ROSEL_SPLL3_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) System PLL3 (Clock-3) Position  */
#define CRU_REFO1CON_ROSEL_LPRC               (CRU_REFO1CON_ROSEL_LPRC_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) LPRC Position  */
#define CRU_REFO1CON_ROSEL_SOSC               (CRU_REFO1CON_ROSEL_SOSC_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) SOSC Position  */
#define CRU_REFO1CON_ROSEL_POSC               (CRU_REFO1CON_ROSEL_POSC_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) POSC Position  */
#define CRU_REFO1CON_ROSEL_SPLL1              (CRU_REFO1CON_ROSEL_SPLL1_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) System PLL1 (Clock-1) Position  */
#define CRU_REFO1CON_ROSEL_FRC                (CRU_REFO1CON_ROSEL_FRC_Val << CRU_REFO1CON_ROSEL_Pos) /* (CRU_REFO1CON) FRC Position  */
#define CRU_REFO1CON_ACTIVE_Pos               _UINT32_(8)                                          /* (CRU_REFO1CON) Reference Clock Request Status bit Position */
#define CRU_REFO1CON_ACTIVE_Msk               (_UINT32_(0x1) << CRU_REFO1CON_ACTIVE_Pos)           /* (CRU_REFO1CON) Reference Clock Request Status bit Mask */
#define CRU_REFO1CON_ACTIVE(value)            (CRU_REFO1CON_ACTIVE_Msk & (_UINT32_(value) << CRU_REFO1CON_ACTIVE_Pos)) /* Assigment of value for ACTIVE in the CRU_REFO1CON register */
#define   CRU_REFO1CON_ACTIVE_ACTIVE_Val      _UINT32_(0x1)                                        /* (CRU_REFO1CON) Reference clock request is active (User should not update this REFOCON register)  */
#define   CRU_REFO1CON_ACTIVE_NOT_ACTIVE_Val  _UINT32_(0x0)                                        /* (CRU_REFO1CON) Reference clock request is not active (User can update this REFOCON register)  */
#define CRU_REFO1CON_ACTIVE_ACTIVE            (CRU_REFO1CON_ACTIVE_ACTIVE_Val << CRU_REFO1CON_ACTIVE_Pos) /* (CRU_REFO1CON) Reference clock request is active (User should not update this REFOCON register) Position  */
#define CRU_REFO1CON_ACTIVE_NOT_ACTIVE        (CRU_REFO1CON_ACTIVE_NOT_ACTIVE_Val << CRU_REFO1CON_ACTIVE_Pos) /* (CRU_REFO1CON) Reference clock request is not active (User can update this REFOCON register) Position  */
#define CRU_REFO1CON_DIVSWEN_Pos              _UINT32_(9)                                          /* (CRU_REFO1CON) Clock RODIV/ROTRIM switch enabled. Position */
#define CRU_REFO1CON_DIVSWEN_Msk              (_UINT32_(0x1) << CRU_REFO1CON_DIVSWEN_Pos)          /* (CRU_REFO1CON) Clock RODIV/ROTRIM switch enabled. Mask */
#define CRU_REFO1CON_DIVSWEN(value)           (CRU_REFO1CON_DIVSWEN_Msk & (_UINT32_(value) << CRU_REFO1CON_DIVSWEN_Pos)) /* Assigment of value for DIVSWEN in the CRU_REFO1CON register */
#define   CRU_REFO1CON_DIVSWEN_SWINPROGRESS_Val _UINT32_(0x1)                                        /* (CRU_REFO1CON) Clock Divider Switching currently in progress.  */
#define   CRU_REFO1CON_DIVSWEN_SWCOMPLETE_Val _UINT32_(0x0)                                        /* (CRU_REFO1CON) Clock Divider Switch has completed.  */
#define CRU_REFO1CON_DIVSWEN_SWINPROGRESS     (CRU_REFO1CON_DIVSWEN_SWINPROGRESS_Val << CRU_REFO1CON_DIVSWEN_Pos) /* (CRU_REFO1CON) Clock Divider Switching currently in progress. Position  */
#define CRU_REFO1CON_DIVSWEN_SWCOMPLETE       (CRU_REFO1CON_DIVSWEN_SWCOMPLETE_Val << CRU_REFO1CON_DIVSWEN_Pos) /* (CRU_REFO1CON) Clock Divider Switch has completed. Position  */
#define CRU_REFO1CON_RSLP_Pos                 _UINT32_(11)                                         /* (CRU_REFO1CON) Reference Oscillator Run in Sleep bit Position */
#define CRU_REFO1CON_RSLP_Msk                 (_UINT32_(0x1) << CRU_REFO1CON_RSLP_Pos)             /* (CRU_REFO1CON) Reference Oscillator Run in Sleep bit Mask */
#define CRU_REFO1CON_RSLP(value)              (CRU_REFO1CON_RSLP_Msk & (_UINT32_(value) << CRU_REFO1CON_RSLP_Pos)) /* Assigment of value for RSLP in the CRU_REFO1CON register */
#define   CRU_REFO1CON_RSLP_RSLP_Val          _UINT32_(0x1)                                        /* (CRU_REFO1CON) Reference Oscillator output continues to run in Sleep  */
#define   CRU_REFO1CON_RSLP_NO_RSLP_Val       _UINT32_(0x0)                                        /* (CRU_REFO1CON) Reference Oscillator output is disabled in Sleep  */
#define CRU_REFO1CON_RSLP_RSLP                (CRU_REFO1CON_RSLP_RSLP_Val << CRU_REFO1CON_RSLP_Pos) /* (CRU_REFO1CON) Reference Oscillator output continues to run in Sleep Position  */
#define CRU_REFO1CON_RSLP_NO_RSLP             (CRU_REFO1CON_RSLP_NO_RSLP_Val << CRU_REFO1CON_RSLP_Pos) /* (CRU_REFO1CON) Reference Oscillator output is disabled in Sleep Position  */
#define CRU_REFO1CON_OE_Pos                   _UINT32_(12)                                         /* (CRU_REFO1CON) Reference Clock Output Enable bit Position */
#define CRU_REFO1CON_OE_Msk                   (_UINT32_(0x1) << CRU_REFO1CON_OE_Pos)               /* (CRU_REFO1CON) Reference Clock Output Enable bit Mask */
#define CRU_REFO1CON_OE(value)                (CRU_REFO1CON_OE_Msk & (_UINT32_(value) << CRU_REFO1CON_OE_Pos)) /* Assigment of value for OE in the CRU_REFO1CON register */
#define   CRU_REFO1CON_OE_REFO1_OE_Val        _UINT32_(0x1)                                        /* (CRU_REFO1CON) Reference clock is driven out on REFO1 pin  */
#define   CRU_REFO1CON_OE_NO_REFO1_OE_Val     _UINT32_(0x0)                                        /* (CRU_REFO1CON) Reference clock is not driven out on REFO1 pin.  */
#define CRU_REFO1CON_OE_REFO1_OE              (CRU_REFO1CON_OE_REFO1_OE_Val << CRU_REFO1CON_OE_Pos) /* (CRU_REFO1CON) Reference clock is driven out on REFO1 pin Position  */
#define CRU_REFO1CON_OE_NO_REFO1_OE           (CRU_REFO1CON_OE_NO_REFO1_OE_Val << CRU_REFO1CON_OE_Pos) /* (CRU_REFO1CON) Reference clock is not driven out on REFO1 pin. Position  */
#define CRU_REFO1CON_SIDL_Pos                 _UINT32_(13)                                         /* (CRU_REFO1CON) Peripheral Stop in Idle Mode bit Position */
#define CRU_REFO1CON_SIDL_Msk                 (_UINT32_(0x1) << CRU_REFO1CON_SIDL_Pos)             /* (CRU_REFO1CON) Peripheral Stop in Idle Mode bit Mask */
#define CRU_REFO1CON_SIDL(value)              (CRU_REFO1CON_SIDL_Msk & (_UINT32_(value) << CRU_REFO1CON_SIDL_Pos)) /* Assigment of value for SIDL in the CRU_REFO1CON register */
#define   CRU_REFO1CON_SIDL_SIDL_Val          _UINT32_(0x1)                                        /* (CRU_REFO1CON) Discontinue module operation when device enters Idle mode  */
#define   CRU_REFO1CON_SIDL_NO_SIDL_Val       _UINT32_(0x0)                                        /* (CRU_REFO1CON) Continue module operation in Idle mode  */
#define CRU_REFO1CON_SIDL_SIDL                (CRU_REFO1CON_SIDL_SIDL_Val << CRU_REFO1CON_SIDL_Pos) /* (CRU_REFO1CON) Discontinue module operation when device enters Idle mode Position  */
#define CRU_REFO1CON_SIDL_NO_SIDL             (CRU_REFO1CON_SIDL_NO_SIDL_Val << CRU_REFO1CON_SIDL_Pos) /* (CRU_REFO1CON) Continue module operation in Idle mode Position  */
#define CRU_REFO1CON_FRZ_Pos                  _UINT32_(14)                                         /* (CRU_REFO1CON) Freeze in Debug mode bit Position */
#define CRU_REFO1CON_FRZ_Msk                  (_UINT32_(0x1) << CRU_REFO1CON_FRZ_Pos)              /* (CRU_REFO1CON) Freeze in Debug mode bit Mask */
#define CRU_REFO1CON_FRZ(value)               (CRU_REFO1CON_FRZ_Msk & (_UINT32_(value) << CRU_REFO1CON_FRZ_Pos)) /* Assigment of value for FRZ in the CRU_REFO1CON register */
#define   CRU_REFO1CON_FRZ_FRZ_Val            _UINT32_(0x1)                                        /* (CRU_REFO1CON) When emulator is in Debug mode, module freezes operation  */
#define   CRU_REFO1CON_FRZ_NO_FRZ_Val         _UINT32_(0x0)                                        /* (CRU_REFO1CON) When emulator is in Debug mode, module continues operation  */
#define CRU_REFO1CON_FRZ_FRZ                  (CRU_REFO1CON_FRZ_FRZ_Val << CRU_REFO1CON_FRZ_Pos)   /* (CRU_REFO1CON) When emulator is in Debug mode, module freezes operation Position  */
#define CRU_REFO1CON_FRZ_NO_FRZ               (CRU_REFO1CON_FRZ_NO_FRZ_Val << CRU_REFO1CON_FRZ_Pos) /* (CRU_REFO1CON) When emulator is in Debug mode, module continues operation Position  */
#define CRU_REFO1CON_ON_Pos                   _UINT32_(15)                                         /* (CRU_REFO1CON) Output Enable bit Position */
#define CRU_REFO1CON_ON_Msk                   (_UINT32_(0x1) << CRU_REFO1CON_ON_Pos)               /* (CRU_REFO1CON) Output Enable bit Mask */
#define CRU_REFO1CON_ON(value)                (CRU_REFO1CON_ON_Msk & (_UINT32_(value) << CRU_REFO1CON_ON_Pos)) /* Assigment of value for ON in the CRU_REFO1CON register */
#define   CRU_REFO1CON_ON_ON_Val              _UINT32_(0x1)                                        /* (CRU_REFO1CON) Reference Oscillator Module enabled  */
#define   CRU_REFO1CON_ON_OFF_Val             _UINT32_(0x0)                                        /* (CRU_REFO1CON) Reference Oscillator Module disabled  */
#define CRU_REFO1CON_ON_ON                    (CRU_REFO1CON_ON_ON_Val << CRU_REFO1CON_ON_Pos)      /* (CRU_REFO1CON) Reference Oscillator Module enabled Position  */
#define CRU_REFO1CON_ON_OFF                   (CRU_REFO1CON_ON_OFF_Val << CRU_REFO1CON_ON_Pos)     /* (CRU_REFO1CON) Reference Oscillator Module disabled Position  */
#define CRU_REFO1CON_RODIV_Pos                _UINT32_(16)                                         /* (CRU_REFO1CON) Reference Clock Divider bits Position */
#define CRU_REFO1CON_RODIV_Msk                (_UINT32_(0x7FFF) << CRU_REFO1CON_RODIV_Pos)         /* (CRU_REFO1CON) Reference Clock Divider bits Mask */
#define CRU_REFO1CON_RODIV(value)             (CRU_REFO1CON_RODIV_Msk & (_UINT32_(value) << CRU_REFO1CON_RODIV_Pos)) /* Assigment of value for RODIV in the CRU_REFO1CON register */
#define   CRU_REFO1CON_RODIV_65K_Val          _UINT32_(0x7FFF)                                     /* (CRU_REFO1CON) REFO1 clock is Base clock frequency divided by 65,534 (32,767 *2)  */
#define   CRU_REFO1CON_RODIV_4_Val            _UINT32_(0x2)                                        /* (CRU_REFO1CON) REFO1 clock is Base clock frequency divided by 4 (2*2)  */
#define   CRU_REFO1CON_RODIV_2_Val            _UINT32_(0x1)                                        /* (CRU_REFO1CON) REFO1 clock is Base clock frequency divided by 2 (1*2)  */
#define   CRU_REFO1CON_RODIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_REFO1CON) REFO1 clock is same frequency as Base clock (no divider)  */
#define CRU_REFO1CON_RODIV_65K                (CRU_REFO1CON_RODIV_65K_Val << CRU_REFO1CON_RODIV_Pos) /* (CRU_REFO1CON) REFO1 clock is Base clock frequency divided by 65,534 (32,767 *2) Position  */
#define CRU_REFO1CON_RODIV_4                  (CRU_REFO1CON_RODIV_4_Val << CRU_REFO1CON_RODIV_Pos) /* (CRU_REFO1CON) REFO1 clock is Base clock frequency divided by 4 (2*2) Position  */
#define CRU_REFO1CON_RODIV_2                  (CRU_REFO1CON_RODIV_2_Val << CRU_REFO1CON_RODIV_Pos) /* (CRU_REFO1CON) REFO1 clock is Base clock frequency divided by 2 (1*2) Position  */
#define CRU_REFO1CON_RODIV_NONE               (CRU_REFO1CON_RODIV_NONE_Val << CRU_REFO1CON_RODIV_Pos) /* (CRU_REFO1CON) REFO1 clock is same frequency as Base clock (no divider) Position  */
#define CRU_REFO1CON_Msk                      _UINT32_(0x7FFFFB0F)                                 /* (CRU_REFO1CON) Register Mask  */


/* -------- CRU_REFO1CONCLR : (CRU Offset: 0x74) (R/W 32)  -------- */
#define CRU_REFO1CONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO1CONCLR)   Reset Value */

#define CRU_REFO1CONCLR_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO1CONCLR) Register Mask  */


/* -------- CRU_REFO1CONSET : (CRU Offset: 0x78) (R/W 32)  -------- */
#define CRU_REFO1CONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO1CONSET)   Reset Value */

#define CRU_REFO1CONSET_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO1CONSET) Register Mask  */


/* -------- CRU_REFO1CONINV : (CRU Offset: 0x7C) (R/W 32)  -------- */
#define CRU_REFO1CONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO1CONINV)   Reset Value */

#define CRU_REFO1CONINV_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO1CONINV) Register Mask  */


/* -------- CRU_REFO1TRIM : (CRU Offset: 0x80) (R/W 32) REFERENCE OSCILLATOR 1 TRIM REGISTER -------- */
#define CRU_REFO1TRIM_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_REFO1TRIM) REFERENCE OSCILLATOR 1 TRIM REGISTER  Reset Value */

#define CRU_REFO1TRIM_ROTRIM_Pos              _UINT32_(23)                                         /* (CRU_REFO1TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Position */
#define CRU_REFO1TRIM_ROTRIM_Msk              (_UINT32_(0x1FF) << CRU_REFO1TRIM_ROTRIM_Pos)        /* (CRU_REFO1TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Mask */
#define CRU_REFO1TRIM_ROTRIM(value)           (CRU_REFO1TRIM_ROTRIM_Msk & (_UINT32_(value) << CRU_REFO1TRIM_ROTRIM_Pos)) /* Assigment of value for ROTRIM in the CRU_REFO1TRIM register */
#define   CRU_REFO1TRIM_ROTRIM_ZERO_Val       _UINT32_(0x0)                                        /* (CRU_REFO1TRIM) 0/512 (0.0) divisor added to RODIV value  */
#define   CRU_REFO1TRIM_ROTRIM_1_Val          _UINT32_(0x1)                                        /* (CRU_REFO1TRIM) 1/512 (0.001953125) divisor added to RODIV value  */
#define   CRU_REFO1TRIM_ROTRIM_2_Val          _UINT32_(0x2)                                        /* (CRU_REFO1TRIM) 2/512 (0.00390625) divisor added to RODIV value  */
#define   CRU_REFO1TRIM_ROTRIM_256_Val        _UINT32_(0x100)                                      /* (CRU_REFO1TRIM) 256/512 (0.5000) divisor added to RODIV value  */
#define   CRU_REFO1TRIM_ROTRIM_511_Val        _UINT32_(0x1FF)                                      /* (CRU_REFO1TRIM) 511/512 (0.998046875) divisor added to RODIV value  */
#define CRU_REFO1TRIM_ROTRIM_ZERO             (CRU_REFO1TRIM_ROTRIM_ZERO_Val << CRU_REFO1TRIM_ROTRIM_Pos) /* (CRU_REFO1TRIM) 0/512 (0.0) divisor added to RODIV value Position  */
#define CRU_REFO1TRIM_ROTRIM_1                (CRU_REFO1TRIM_ROTRIM_1_Val << CRU_REFO1TRIM_ROTRIM_Pos) /* (CRU_REFO1TRIM) 1/512 (0.001953125) divisor added to RODIV value Position  */
#define CRU_REFO1TRIM_ROTRIM_2                (CRU_REFO1TRIM_ROTRIM_2_Val << CRU_REFO1TRIM_ROTRIM_Pos) /* (CRU_REFO1TRIM) 2/512 (0.00390625) divisor added to RODIV value Position  */
#define CRU_REFO1TRIM_ROTRIM_256              (CRU_REFO1TRIM_ROTRIM_256_Val << CRU_REFO1TRIM_ROTRIM_Pos) /* (CRU_REFO1TRIM) 256/512 (0.5000) divisor added to RODIV value Position  */
#define CRU_REFO1TRIM_ROTRIM_511              (CRU_REFO1TRIM_ROTRIM_511_Val << CRU_REFO1TRIM_ROTRIM_Pos) /* (CRU_REFO1TRIM) 511/512 (0.998046875) divisor added to RODIV value Position  */
#define CRU_REFO1TRIM_Msk                     _UINT32_(0xFF800000)                                 /* (CRU_REFO1TRIM) Register Mask  */


/* -------- CRU_REFO1TRIMCLR : (CRU Offset: 0x84) (R/W 32)  -------- */
#define CRU_REFO1TRIMCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO1TRIMCLR)   Reset Value */

#define CRU_REFO1TRIMCLR_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO1TRIMCLR) Register Mask  */


/* -------- CRU_REFO1TRIMSET : (CRU Offset: 0x88) (R/W 32)  -------- */
#define CRU_REFO1TRIMSET_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO1TRIMSET)   Reset Value */

#define CRU_REFO1TRIMSET_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO1TRIMSET) Register Mask  */


/* -------- CRU_REFO1TRIMINV : (CRU Offset: 0x8C) (R/W 32)  -------- */
#define CRU_REFO1TRIMINV_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO1TRIMINV)   Reset Value */

#define CRU_REFO1TRIMINV_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO1TRIMINV) Register Mask  */


/* -------- CRU_REFO2CON : (CRU Offset: 0x90) (R/W 32) REFERENCE OSCILLATOR 2 CONTROL REGISTER -------- */
#define CRU_REFO2CON_RESETVALUE               _UINT32_(0x00)                                       /*  (CRU_REFO2CON) REFERENCE OSCILLATOR 2 CONTROL REGISTER  Reset Value */

#define CRU_REFO2CON_ROSEL_Pos                _UINT32_(0)                                          /* (CRU_REFO2CON) Reference Clock Source Select bits Position */
#define CRU_REFO2CON_ROSEL_Msk                (_UINT32_(0xF) << CRU_REFO2CON_ROSEL_Pos)            /* (CRU_REFO2CON) Reference Clock Source Select bits Mask */
#define CRU_REFO2CON_ROSEL(value)             (CRU_REFO2CON_ROSEL_Msk & (_UINT32_(value) << CRU_REFO2CON_ROSEL_Pos)) /* Assigment of value for ROSEL in the CRU_REFO2CON register */
#define   CRU_REFO2CON_ROSEL_REFCLKI_Val      _UINT32_(0x8)                                        /* (CRU_REFO2CON) REFI Pin  */
#define   CRU_REFO2CON_ROSEL_SYSCLK_Val       _UINT32_(0x7)                                        /* (CRU_REFO2CON) System clock (reference clock reflects any device clock switching)  */
#define   CRU_REFO2CON_ROSEL_PBCLK1_Val       _UINT32_(0x6)                                        /* (CRU_REFO2CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching)  */
#define   CRU_REFO2CON_ROSEL_SPLL3_Val        _UINT32_(0x5)                                        /* (CRU_REFO2CON) System PLL3 (Clock-3)  */
#define   CRU_REFO2CON_ROSEL_LPRC_Val         _UINT32_(0x4)                                        /* (CRU_REFO2CON) LPRC  */
#define   CRU_REFO2CON_ROSEL_SOSC_Val         _UINT32_(0x3)                                        /* (CRU_REFO2CON) SOSC  */
#define   CRU_REFO2CON_ROSEL_POSC_Val         _UINT32_(0x2)                                        /* (CRU_REFO2CON) POSC  */
#define   CRU_REFO2CON_ROSEL_SPLL1_Val        _UINT32_(0x1)                                        /* (CRU_REFO2CON) System PLL1 (Clock-1)  */
#define   CRU_REFO2CON_ROSEL_FRC_Val          _UINT32_(0x0)                                        /* (CRU_REFO2CON) FRC  */
#define CRU_REFO2CON_ROSEL_REFCLKI            (CRU_REFO2CON_ROSEL_REFCLKI_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) REFI Pin Position  */
#define CRU_REFO2CON_ROSEL_SYSCLK             (CRU_REFO2CON_ROSEL_SYSCLK_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) System clock (reference clock reflects any device clock switching) Position  */
#define CRU_REFO2CON_ROSEL_PBCLK1             (CRU_REFO2CON_ROSEL_PBCLK1_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching) Position  */
#define CRU_REFO2CON_ROSEL_SPLL3              (CRU_REFO2CON_ROSEL_SPLL3_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) System PLL3 (Clock-3) Position  */
#define CRU_REFO2CON_ROSEL_LPRC               (CRU_REFO2CON_ROSEL_LPRC_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) LPRC Position  */
#define CRU_REFO2CON_ROSEL_SOSC               (CRU_REFO2CON_ROSEL_SOSC_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) SOSC Position  */
#define CRU_REFO2CON_ROSEL_POSC               (CRU_REFO2CON_ROSEL_POSC_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) POSC Position  */
#define CRU_REFO2CON_ROSEL_SPLL1              (CRU_REFO2CON_ROSEL_SPLL1_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) System PLL1 (Clock-1) Position  */
#define CRU_REFO2CON_ROSEL_FRC                (CRU_REFO2CON_ROSEL_FRC_Val << CRU_REFO2CON_ROSEL_Pos) /* (CRU_REFO2CON) FRC Position  */
#define CRU_REFO2CON_ACTIVE_Pos               _UINT32_(8)                                          /* (CRU_REFO2CON) Reference Clock Request Status bit Position */
#define CRU_REFO2CON_ACTIVE_Msk               (_UINT32_(0x1) << CRU_REFO2CON_ACTIVE_Pos)           /* (CRU_REFO2CON) Reference Clock Request Status bit Mask */
#define CRU_REFO2CON_ACTIVE(value)            (CRU_REFO2CON_ACTIVE_Msk & (_UINT32_(value) << CRU_REFO2CON_ACTIVE_Pos)) /* Assigment of value for ACTIVE in the CRU_REFO2CON register */
#define   CRU_REFO2CON_ACTIVE_ACTIVE_Val      _UINT32_(0x1)                                        /* (CRU_REFO2CON) Reference clock request is active (User should not update this REFOCON register)  */
#define   CRU_REFO2CON_ACTIVE_NOT_ACTIVE_Val  _UINT32_(0x0)                                        /* (CRU_REFO2CON) Reference clock request is not active (User can update this REFOCON register)  */
#define CRU_REFO2CON_ACTIVE_ACTIVE            (CRU_REFO2CON_ACTIVE_ACTIVE_Val << CRU_REFO2CON_ACTIVE_Pos) /* (CRU_REFO2CON) Reference clock request is active (User should not update this REFOCON register) Position  */
#define CRU_REFO2CON_ACTIVE_NOT_ACTIVE        (CRU_REFO2CON_ACTIVE_NOT_ACTIVE_Val << CRU_REFO2CON_ACTIVE_Pos) /* (CRU_REFO2CON) Reference clock request is not active (User can update this REFOCON register) Position  */
#define CRU_REFO2CON_DIVSWEN_Pos              _UINT32_(9)                                          /* (CRU_REFO2CON) Clock RODIV/ROTRIM switch enabled. Position */
#define CRU_REFO2CON_DIVSWEN_Msk              (_UINT32_(0x1) << CRU_REFO2CON_DIVSWEN_Pos)          /* (CRU_REFO2CON) Clock RODIV/ROTRIM switch enabled. Mask */
#define CRU_REFO2CON_DIVSWEN(value)           (CRU_REFO2CON_DIVSWEN_Msk & (_UINT32_(value) << CRU_REFO2CON_DIVSWEN_Pos)) /* Assigment of value for DIVSWEN in the CRU_REFO2CON register */
#define   CRU_REFO2CON_DIVSWEN_SWINPROGRESS_Val _UINT32_(0x1)                                        /* (CRU_REFO2CON) Clock Divider Switching currently in progress.  */
#define   CRU_REFO2CON_DIVSWEN_SWCOMPLETE_Val _UINT32_(0x0)                                        /* (CRU_REFO2CON) Clock Divider Switch has completed.  */
#define CRU_REFO2CON_DIVSWEN_SWINPROGRESS     (CRU_REFO2CON_DIVSWEN_SWINPROGRESS_Val << CRU_REFO2CON_DIVSWEN_Pos) /* (CRU_REFO2CON) Clock Divider Switching currently in progress. Position  */
#define CRU_REFO2CON_DIVSWEN_SWCOMPLETE       (CRU_REFO2CON_DIVSWEN_SWCOMPLETE_Val << CRU_REFO2CON_DIVSWEN_Pos) /* (CRU_REFO2CON) Clock Divider Switch has completed. Position  */
#define CRU_REFO2CON_RSLP_Pos                 _UINT32_(11)                                         /* (CRU_REFO2CON) Reference Oscillator Run in Sleep bit Position */
#define CRU_REFO2CON_RSLP_Msk                 (_UINT32_(0x1) << CRU_REFO2CON_RSLP_Pos)             /* (CRU_REFO2CON) Reference Oscillator Run in Sleep bit Mask */
#define CRU_REFO2CON_RSLP(value)              (CRU_REFO2CON_RSLP_Msk & (_UINT32_(value) << CRU_REFO2CON_RSLP_Pos)) /* Assigment of value for RSLP in the CRU_REFO2CON register */
#define   CRU_REFO2CON_RSLP_RSLP_Val          _UINT32_(0x1)                                        /* (CRU_REFO2CON) Reference Oscillator output continues to run in Sleep  */
#define   CRU_REFO2CON_RSLP_NO_RSLP_Val       _UINT32_(0x0)                                        /* (CRU_REFO2CON) Reference Oscillator output is disabled in Sleep  */
#define CRU_REFO2CON_RSLP_RSLP                (CRU_REFO2CON_RSLP_RSLP_Val << CRU_REFO2CON_RSLP_Pos) /* (CRU_REFO2CON) Reference Oscillator output continues to run in Sleep Position  */
#define CRU_REFO2CON_RSLP_NO_RSLP             (CRU_REFO2CON_RSLP_NO_RSLP_Val << CRU_REFO2CON_RSLP_Pos) /* (CRU_REFO2CON) Reference Oscillator output is disabled in Sleep Position  */
#define CRU_REFO2CON_OE_Pos                   _UINT32_(12)                                         /* (CRU_REFO2CON) Reference Clock Output Enable bit Position */
#define CRU_REFO2CON_OE_Msk                   (_UINT32_(0x1) << CRU_REFO2CON_OE_Pos)               /* (CRU_REFO2CON) Reference Clock Output Enable bit Mask */
#define CRU_REFO2CON_OE(value)                (CRU_REFO2CON_OE_Msk & (_UINT32_(value) << CRU_REFO2CON_OE_Pos)) /* Assigment of value for OE in the CRU_REFO2CON register */
#define   CRU_REFO2CON_OE_REFO2_OE_Val        _UINT32_(0x1)                                        /* (CRU_REFO2CON) Reference clock is driven out on REFO2 pin  */
#define   CRU_REFO2CON_OE_NO_REFO2_OE_Val     _UINT32_(0x0)                                        /* (CRU_REFO2CON) Reference clock is not driven out on REFO2 pin.  */
#define CRU_REFO2CON_OE_REFO2_OE              (CRU_REFO2CON_OE_REFO2_OE_Val << CRU_REFO2CON_OE_Pos) /* (CRU_REFO2CON) Reference clock is driven out on REFO2 pin Position  */
#define CRU_REFO2CON_OE_NO_REFO2_OE           (CRU_REFO2CON_OE_NO_REFO2_OE_Val << CRU_REFO2CON_OE_Pos) /* (CRU_REFO2CON) Reference clock is not driven out on REFO2 pin. Position  */
#define CRU_REFO2CON_SIDL_Pos                 _UINT32_(13)                                         /* (CRU_REFO2CON) Peripheral Stop in Idle Mode bit Position */
#define CRU_REFO2CON_SIDL_Msk                 (_UINT32_(0x1) << CRU_REFO2CON_SIDL_Pos)             /* (CRU_REFO2CON) Peripheral Stop in Idle Mode bit Mask */
#define CRU_REFO2CON_SIDL(value)              (CRU_REFO2CON_SIDL_Msk & (_UINT32_(value) << CRU_REFO2CON_SIDL_Pos)) /* Assigment of value for SIDL in the CRU_REFO2CON register */
#define   CRU_REFO2CON_SIDL_SIDL_Val          _UINT32_(0x1)                                        /* (CRU_REFO2CON) Discontinue module operation when device enters Idle mode  */
#define   CRU_REFO2CON_SIDL_NO_SIDL_Val       _UINT32_(0x0)                                        /* (CRU_REFO2CON) Continue module operation in Idle mode  */
#define CRU_REFO2CON_SIDL_SIDL                (CRU_REFO2CON_SIDL_SIDL_Val << CRU_REFO2CON_SIDL_Pos) /* (CRU_REFO2CON) Discontinue module operation when device enters Idle mode Position  */
#define CRU_REFO2CON_SIDL_NO_SIDL             (CRU_REFO2CON_SIDL_NO_SIDL_Val << CRU_REFO2CON_SIDL_Pos) /* (CRU_REFO2CON) Continue module operation in Idle mode Position  */
#define CRU_REFO2CON_FRZ_Pos                  _UINT32_(14)                                         /* (CRU_REFO2CON) Freeze in Debug mode bit Position */
#define CRU_REFO2CON_FRZ_Msk                  (_UINT32_(0x1) << CRU_REFO2CON_FRZ_Pos)              /* (CRU_REFO2CON) Freeze in Debug mode bit Mask */
#define CRU_REFO2CON_FRZ(value)               (CRU_REFO2CON_FRZ_Msk & (_UINT32_(value) << CRU_REFO2CON_FRZ_Pos)) /* Assigment of value for FRZ in the CRU_REFO2CON register */
#define   CRU_REFO2CON_FRZ_FRZ_Val            _UINT32_(0x1)                                        /* (CRU_REFO2CON) When emulator is in Debug mode, module freezes operation  */
#define   CRU_REFO2CON_FRZ_NO_FRZ_Val         _UINT32_(0x0)                                        /* (CRU_REFO2CON) When emulator is in Debug mode, module continues operation  */
#define CRU_REFO2CON_FRZ_FRZ                  (CRU_REFO2CON_FRZ_FRZ_Val << CRU_REFO2CON_FRZ_Pos)   /* (CRU_REFO2CON) When emulator is in Debug mode, module freezes operation Position  */
#define CRU_REFO2CON_FRZ_NO_FRZ               (CRU_REFO2CON_FRZ_NO_FRZ_Val << CRU_REFO2CON_FRZ_Pos) /* (CRU_REFO2CON) When emulator is in Debug mode, module continues operation Position  */
#define CRU_REFO2CON_ON_Pos                   _UINT32_(15)                                         /* (CRU_REFO2CON) Output Enable bit Position */
#define CRU_REFO2CON_ON_Msk                   (_UINT32_(0x1) << CRU_REFO2CON_ON_Pos)               /* (CRU_REFO2CON) Output Enable bit Mask */
#define CRU_REFO2CON_ON(value)                (CRU_REFO2CON_ON_Msk & (_UINT32_(value) << CRU_REFO2CON_ON_Pos)) /* Assigment of value for ON in the CRU_REFO2CON register */
#define   CRU_REFO2CON_ON_ON_Val              _UINT32_(0x1)                                        /* (CRU_REFO2CON) Reference Oscillator Module enabled  */
#define   CRU_REFO2CON_ON_OFF_Val             _UINT32_(0x0)                                        /* (CRU_REFO2CON) Reference Oscillator Module disabled  */
#define CRU_REFO2CON_ON_ON                    (CRU_REFO2CON_ON_ON_Val << CRU_REFO2CON_ON_Pos)      /* (CRU_REFO2CON) Reference Oscillator Module enabled Position  */
#define CRU_REFO2CON_ON_OFF                   (CRU_REFO2CON_ON_OFF_Val << CRU_REFO2CON_ON_Pos)     /* (CRU_REFO2CON) Reference Oscillator Module disabled Position  */
#define CRU_REFO2CON_RODIV_Pos                _UINT32_(16)                                         /* (CRU_REFO2CON) Reference Clock Divider bits Position */
#define CRU_REFO2CON_RODIV_Msk                (_UINT32_(0x7FFF) << CRU_REFO2CON_RODIV_Pos)         /* (CRU_REFO2CON) Reference Clock Divider bits Mask */
#define CRU_REFO2CON_RODIV(value)             (CRU_REFO2CON_RODIV_Msk & (_UINT32_(value) << CRU_REFO2CON_RODIV_Pos)) /* Assigment of value for RODIV in the CRU_REFO2CON register */
#define   CRU_REFO2CON_RODIV_65K_Val          _UINT32_(0x7FFF)                                     /* (CRU_REFO2CON) REFO2 clock is Base clock frequency divided by 65,534 (32,767 *2)  */
#define   CRU_REFO2CON_RODIV_4_Val            _UINT32_(0x2)                                        /* (CRU_REFO2CON) REFO2 clock is Base clock frequency divided by 4 (2*2)  */
#define   CRU_REFO2CON_RODIV_2_Val            _UINT32_(0x1)                                        /* (CRU_REFO2CON) REFO2 clock is Base clock frequency divided by 2 (1*2)  */
#define   CRU_REFO2CON_RODIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_REFO2CON) REFO2 clock is same frequency as Base clock (no divider)  */
#define CRU_REFO2CON_RODIV_65K                (CRU_REFO2CON_RODIV_65K_Val << CRU_REFO2CON_RODIV_Pos) /* (CRU_REFO2CON) REFO2 clock is Base clock frequency divided by 65,534 (32,767 *2) Position  */
#define CRU_REFO2CON_RODIV_4                  (CRU_REFO2CON_RODIV_4_Val << CRU_REFO2CON_RODIV_Pos) /* (CRU_REFO2CON) REFO2 clock is Base clock frequency divided by 4 (2*2) Position  */
#define CRU_REFO2CON_RODIV_2                  (CRU_REFO2CON_RODIV_2_Val << CRU_REFO2CON_RODIV_Pos) /* (CRU_REFO2CON) REFO2 clock is Base clock frequency divided by 2 (1*2) Position  */
#define CRU_REFO2CON_RODIV_NONE               (CRU_REFO2CON_RODIV_NONE_Val << CRU_REFO2CON_RODIV_Pos) /* (CRU_REFO2CON) REFO2 clock is same frequency as Base clock (no divider) Position  */
#define CRU_REFO2CON_Msk                      _UINT32_(0x7FFFFB0F)                                 /* (CRU_REFO2CON) Register Mask  */


/* -------- CRU_REFO2CONCLR : (CRU Offset: 0x94) (R/W 32)  -------- */
#define CRU_REFO2CONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO2CONCLR)   Reset Value */

#define CRU_REFO2CONCLR_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO2CONCLR) Register Mask  */


/* -------- CRU_REFO2CONSET : (CRU Offset: 0x98) (R/W 32)  -------- */
#define CRU_REFO2CONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO2CONSET)   Reset Value */

#define CRU_REFO2CONSET_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO2CONSET) Register Mask  */


/* -------- CRU_REFO2CONINV : (CRU Offset: 0x9C) (R/W 32)  -------- */
#define CRU_REFO2CONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO2CONINV)   Reset Value */

#define CRU_REFO2CONINV_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO2CONINV) Register Mask  */


/* -------- CRU_REFO2TRIM : (CRU Offset: 0xA0) (R/W 32) REFERENCE OSCILLATOR 2 TRIM REGISTER -------- */
#define CRU_REFO2TRIM_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_REFO2TRIM) REFERENCE OSCILLATOR 2 TRIM REGISTER  Reset Value */

#define CRU_REFO2TRIM_ROTRIM_Pos              _UINT32_(23)                                         /* (CRU_REFO2TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Position */
#define CRU_REFO2TRIM_ROTRIM_Msk              (_UINT32_(0x1FF) << CRU_REFO2TRIM_ROTRIM_Pos)        /* (CRU_REFO2TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Mask */
#define CRU_REFO2TRIM_ROTRIM(value)           (CRU_REFO2TRIM_ROTRIM_Msk & (_UINT32_(value) << CRU_REFO2TRIM_ROTRIM_Pos)) /* Assigment of value for ROTRIM in the CRU_REFO2TRIM register */
#define   CRU_REFO2TRIM_ROTRIM_ZERO_Val       _UINT32_(0x0)                                        /* (CRU_REFO2TRIM) 0/512 (0.0) divisor added to RODIV value  */
#define   CRU_REFO2TRIM_ROTRIM_1_Val          _UINT32_(0x1)                                        /* (CRU_REFO2TRIM) 1/512 (0.001953125) divisor added to RODIV value  */
#define   CRU_REFO2TRIM_ROTRIM_2_Val          _UINT32_(0x2)                                        /* (CRU_REFO2TRIM) 2/512 (0.00390625) divisor added to RODIV value  */
#define   CRU_REFO2TRIM_ROTRIM_256_Val        _UINT32_(0x100)                                      /* (CRU_REFO2TRIM) 256/512 (0.5000) divisor added to RODIV value  */
#define   CRU_REFO2TRIM_ROTRIM_511_Val        _UINT32_(0x1FF)                                      /* (CRU_REFO2TRIM) 511/512 (0.998046875) divisor added to RODIV value  */
#define CRU_REFO2TRIM_ROTRIM_ZERO             (CRU_REFO2TRIM_ROTRIM_ZERO_Val << CRU_REFO2TRIM_ROTRIM_Pos) /* (CRU_REFO2TRIM) 0/512 (0.0) divisor added to RODIV value Position  */
#define CRU_REFO2TRIM_ROTRIM_1                (CRU_REFO2TRIM_ROTRIM_1_Val << CRU_REFO2TRIM_ROTRIM_Pos) /* (CRU_REFO2TRIM) 1/512 (0.001953125) divisor added to RODIV value Position  */
#define CRU_REFO2TRIM_ROTRIM_2                (CRU_REFO2TRIM_ROTRIM_2_Val << CRU_REFO2TRIM_ROTRIM_Pos) /* (CRU_REFO2TRIM) 2/512 (0.00390625) divisor added to RODIV value Position  */
#define CRU_REFO2TRIM_ROTRIM_256              (CRU_REFO2TRIM_ROTRIM_256_Val << CRU_REFO2TRIM_ROTRIM_Pos) /* (CRU_REFO2TRIM) 256/512 (0.5000) divisor added to RODIV value Position  */
#define CRU_REFO2TRIM_ROTRIM_511              (CRU_REFO2TRIM_ROTRIM_511_Val << CRU_REFO2TRIM_ROTRIM_Pos) /* (CRU_REFO2TRIM) 511/512 (0.998046875) divisor added to RODIV value Position  */
#define CRU_REFO2TRIM_Msk                     _UINT32_(0xFF800000)                                 /* (CRU_REFO2TRIM) Register Mask  */


/* -------- CRU_REFO2TRIMCLR : (CRU Offset: 0xA4) (R/W 32)  -------- */
#define CRU_REFO2TRIMCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO2TRIMCLR)   Reset Value */

#define CRU_REFO2TRIMCLR_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO2TRIMCLR) Register Mask  */


/* -------- CRU_REFO2TRIMSET : (CRU Offset: 0xA8) (R/W 32)  -------- */
#define CRU_REFO2TRIMSET_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO2TRIMSET)   Reset Value */

#define CRU_REFO2TRIMSET_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO2TRIMSET) Register Mask  */


/* -------- CRU_REFO2TRIMINV : (CRU Offset: 0xAC) (R/W 32)  -------- */
#define CRU_REFO2TRIMINV_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO2TRIMINV)   Reset Value */

#define CRU_REFO2TRIMINV_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO2TRIMINV) Register Mask  */


/* -------- CRU_REFO3CON : (CRU Offset: 0xB0) (R/W 32) REFERENCE OSCILLATOR 3 CONTROL REGISTER -------- */
#define CRU_REFO3CON_RESETVALUE               _UINT32_(0x00)                                       /*  (CRU_REFO3CON) REFERENCE OSCILLATOR 3 CONTROL REGISTER  Reset Value */

#define CRU_REFO3CON_ROSEL_Pos                _UINT32_(0)                                          /* (CRU_REFO3CON) Reference Clock Source Select bits Position */
#define CRU_REFO3CON_ROSEL_Msk                (_UINT32_(0xF) << CRU_REFO3CON_ROSEL_Pos)            /* (CRU_REFO3CON) Reference Clock Source Select bits Mask */
#define CRU_REFO3CON_ROSEL(value)             (CRU_REFO3CON_ROSEL_Msk & (_UINT32_(value) << CRU_REFO3CON_ROSEL_Pos)) /* Assigment of value for ROSEL in the CRU_REFO3CON register */
#define   CRU_REFO3CON_ROSEL_REFCLKI_Val      _UINT32_(0x8)                                        /* (CRU_REFO3CON) REFI Pin  */
#define   CRU_REFO3CON_ROSEL_SYSCLK_Val       _UINT32_(0x7)                                        /* (CRU_REFO3CON) System clock (reference clock reflects any device clock switching)  */
#define   CRU_REFO3CON_ROSEL_PBCLK1_Val       _UINT32_(0x6)                                        /* (CRU_REFO3CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching)  */
#define   CRU_REFO3CON_ROSEL_SPLL3_Val        _UINT32_(0x5)                                        /* (CRU_REFO3CON) System PLL3 (Clock-3)  */
#define   CRU_REFO3CON_ROSEL_LPRC_Val         _UINT32_(0x4)                                        /* (CRU_REFO3CON) LPRC  */
#define   CRU_REFO3CON_ROSEL_SOSC_Val         _UINT32_(0x3)                                        /* (CRU_REFO3CON) SOSC  */
#define   CRU_REFO3CON_ROSEL_POSC_Val         _UINT32_(0x2)                                        /* (CRU_REFO3CON) POSC  */
#define   CRU_REFO3CON_ROSEL_SPLL1_Val        _UINT32_(0x1)                                        /* (CRU_REFO3CON) System PLL1 (Clock-1)  */
#define   CRU_REFO3CON_ROSEL_FRC_Val          _UINT32_(0x0)                                        /* (CRU_REFO3CON) FRC  */
#define CRU_REFO3CON_ROSEL_REFCLKI            (CRU_REFO3CON_ROSEL_REFCLKI_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) REFI Pin Position  */
#define CRU_REFO3CON_ROSEL_SYSCLK             (CRU_REFO3CON_ROSEL_SYSCLK_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) System clock (reference clock reflects any device clock switching) Position  */
#define CRU_REFO3CON_ROSEL_PBCLK1             (CRU_REFO3CON_ROSEL_PBCLK1_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching) Position  */
#define CRU_REFO3CON_ROSEL_SPLL3              (CRU_REFO3CON_ROSEL_SPLL3_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) System PLL3 (Clock-3) Position  */
#define CRU_REFO3CON_ROSEL_LPRC               (CRU_REFO3CON_ROSEL_LPRC_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) LPRC Position  */
#define CRU_REFO3CON_ROSEL_SOSC               (CRU_REFO3CON_ROSEL_SOSC_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) SOSC Position  */
#define CRU_REFO3CON_ROSEL_POSC               (CRU_REFO3CON_ROSEL_POSC_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) POSC Position  */
#define CRU_REFO3CON_ROSEL_SPLL1              (CRU_REFO3CON_ROSEL_SPLL1_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) System PLL1 (Clock-1) Position  */
#define CRU_REFO3CON_ROSEL_FRC                (CRU_REFO3CON_ROSEL_FRC_Val << CRU_REFO3CON_ROSEL_Pos) /* (CRU_REFO3CON) FRC Position  */
#define CRU_REFO3CON_ACTIVE_Pos               _UINT32_(8)                                          /* (CRU_REFO3CON) Reference Clock Request Status bit Position */
#define CRU_REFO3CON_ACTIVE_Msk               (_UINT32_(0x1) << CRU_REFO3CON_ACTIVE_Pos)           /* (CRU_REFO3CON) Reference Clock Request Status bit Mask */
#define CRU_REFO3CON_ACTIVE(value)            (CRU_REFO3CON_ACTIVE_Msk & (_UINT32_(value) << CRU_REFO3CON_ACTIVE_Pos)) /* Assigment of value for ACTIVE in the CRU_REFO3CON register */
#define   CRU_REFO3CON_ACTIVE_ACTIVE_Val      _UINT32_(0x1)                                        /* (CRU_REFO3CON) Reference clock request is active (User should not update this REFOCON register)  */
#define   CRU_REFO3CON_ACTIVE_NOT_ACTIVE_Val  _UINT32_(0x0)                                        /* (CRU_REFO3CON) Reference clock request is not active (User can update this REFOCON register)  */
#define CRU_REFO3CON_ACTIVE_ACTIVE            (CRU_REFO3CON_ACTIVE_ACTIVE_Val << CRU_REFO3CON_ACTIVE_Pos) /* (CRU_REFO3CON) Reference clock request is active (User should not update this REFOCON register) Position  */
#define CRU_REFO3CON_ACTIVE_NOT_ACTIVE        (CRU_REFO3CON_ACTIVE_NOT_ACTIVE_Val << CRU_REFO3CON_ACTIVE_Pos) /* (CRU_REFO3CON) Reference clock request is not active (User can update this REFOCON register) Position  */
#define CRU_REFO3CON_DIVSWEN_Pos              _UINT32_(9)                                          /* (CRU_REFO3CON) Clock RODIV/ROTRIM switch enabled. Position */
#define CRU_REFO3CON_DIVSWEN_Msk              (_UINT32_(0x1) << CRU_REFO3CON_DIVSWEN_Pos)          /* (CRU_REFO3CON) Clock RODIV/ROTRIM switch enabled. Mask */
#define CRU_REFO3CON_DIVSWEN(value)           (CRU_REFO3CON_DIVSWEN_Msk & (_UINT32_(value) << CRU_REFO3CON_DIVSWEN_Pos)) /* Assigment of value for DIVSWEN in the CRU_REFO3CON register */
#define   CRU_REFO3CON_DIVSWEN_SWINPROGRESS_Val _UINT32_(0x1)                                        /* (CRU_REFO3CON) Clock Divider Switching currently in progress.  */
#define   CRU_REFO3CON_DIVSWEN_SWCOMPLETE_Val _UINT32_(0x0)                                        /* (CRU_REFO3CON) Clock Divider Switch has completed.  */
#define CRU_REFO3CON_DIVSWEN_SWINPROGRESS     (CRU_REFO3CON_DIVSWEN_SWINPROGRESS_Val << CRU_REFO3CON_DIVSWEN_Pos) /* (CRU_REFO3CON) Clock Divider Switching currently in progress. Position  */
#define CRU_REFO3CON_DIVSWEN_SWCOMPLETE       (CRU_REFO3CON_DIVSWEN_SWCOMPLETE_Val << CRU_REFO3CON_DIVSWEN_Pos) /* (CRU_REFO3CON) Clock Divider Switch has completed. Position  */
#define CRU_REFO3CON_RSLP_Pos                 _UINT32_(11)                                         /* (CRU_REFO3CON) Reference Oscillator Run in Sleep bit Position */
#define CRU_REFO3CON_RSLP_Msk                 (_UINT32_(0x1) << CRU_REFO3CON_RSLP_Pos)             /* (CRU_REFO3CON) Reference Oscillator Run in Sleep bit Mask */
#define CRU_REFO3CON_RSLP(value)              (CRU_REFO3CON_RSLP_Msk & (_UINT32_(value) << CRU_REFO3CON_RSLP_Pos)) /* Assigment of value for RSLP in the CRU_REFO3CON register */
#define   CRU_REFO3CON_RSLP_RSLP_Val          _UINT32_(0x1)                                        /* (CRU_REFO3CON) Reference Oscillator output continues to run in Sleep  */
#define   CRU_REFO3CON_RSLP_NO_RSLP_Val       _UINT32_(0x0)                                        /* (CRU_REFO3CON) Reference Oscillator output is disabled in Sleep  */
#define CRU_REFO3CON_RSLP_RSLP                (CRU_REFO3CON_RSLP_RSLP_Val << CRU_REFO3CON_RSLP_Pos) /* (CRU_REFO3CON) Reference Oscillator output continues to run in Sleep Position  */
#define CRU_REFO3CON_RSLP_NO_RSLP             (CRU_REFO3CON_RSLP_NO_RSLP_Val << CRU_REFO3CON_RSLP_Pos) /* (CRU_REFO3CON) Reference Oscillator output is disabled in Sleep Position  */
#define CRU_REFO3CON_OE_Pos                   _UINT32_(12)                                         /* (CRU_REFO3CON) Reference Clock Output Enable bit Position */
#define CRU_REFO3CON_OE_Msk                   (_UINT32_(0x1) << CRU_REFO3CON_OE_Pos)               /* (CRU_REFO3CON) Reference Clock Output Enable bit Mask */
#define CRU_REFO3CON_OE(value)                (CRU_REFO3CON_OE_Msk & (_UINT32_(value) << CRU_REFO3CON_OE_Pos)) /* Assigment of value for OE in the CRU_REFO3CON register */
#define   CRU_REFO3CON_OE_REFO3_OE_Val        _UINT32_(0x1)                                        /* (CRU_REFO3CON) Reference clock is driven out on REFO3 pin  */
#define   CRU_REFO3CON_OE_NO_REFO3_OE_Val     _UINT32_(0x0)                                        /* (CRU_REFO3CON) Reference clock is not driven out on REFO3 pin.  */
#define CRU_REFO3CON_OE_REFO3_OE              (CRU_REFO3CON_OE_REFO3_OE_Val << CRU_REFO3CON_OE_Pos) /* (CRU_REFO3CON) Reference clock is driven out on REFO3 pin Position  */
#define CRU_REFO3CON_OE_NO_REFO3_OE           (CRU_REFO3CON_OE_NO_REFO3_OE_Val << CRU_REFO3CON_OE_Pos) /* (CRU_REFO3CON) Reference clock is not driven out on REFO3 pin. Position  */
#define CRU_REFO3CON_SIDL_Pos                 _UINT32_(13)                                         /* (CRU_REFO3CON) Peripheral Stop in Idle Mode bit Position */
#define CRU_REFO3CON_SIDL_Msk                 (_UINT32_(0x1) << CRU_REFO3CON_SIDL_Pos)             /* (CRU_REFO3CON) Peripheral Stop in Idle Mode bit Mask */
#define CRU_REFO3CON_SIDL(value)              (CRU_REFO3CON_SIDL_Msk & (_UINT32_(value) << CRU_REFO3CON_SIDL_Pos)) /* Assigment of value for SIDL in the CRU_REFO3CON register */
#define   CRU_REFO3CON_SIDL_SIDL_Val          _UINT32_(0x1)                                        /* (CRU_REFO3CON) Discontinue module operation when device enters Idle mode  */
#define   CRU_REFO3CON_SIDL_NO_SIDL_Val       _UINT32_(0x0)                                        /* (CRU_REFO3CON) Continue module operation in Idle mode  */
#define CRU_REFO3CON_SIDL_SIDL                (CRU_REFO3CON_SIDL_SIDL_Val << CRU_REFO3CON_SIDL_Pos) /* (CRU_REFO3CON) Discontinue module operation when device enters Idle mode Position  */
#define CRU_REFO3CON_SIDL_NO_SIDL             (CRU_REFO3CON_SIDL_NO_SIDL_Val << CRU_REFO3CON_SIDL_Pos) /* (CRU_REFO3CON) Continue module operation in Idle mode Position  */
#define CRU_REFO3CON_FRZ_Pos                  _UINT32_(14)                                         /* (CRU_REFO3CON) Freeze in Debug mode bit Position */
#define CRU_REFO3CON_FRZ_Msk                  (_UINT32_(0x1) << CRU_REFO3CON_FRZ_Pos)              /* (CRU_REFO3CON) Freeze in Debug mode bit Mask */
#define CRU_REFO3CON_FRZ(value)               (CRU_REFO3CON_FRZ_Msk & (_UINT32_(value) << CRU_REFO3CON_FRZ_Pos)) /* Assigment of value for FRZ in the CRU_REFO3CON register */
#define   CRU_REFO3CON_FRZ_FRZ_Val            _UINT32_(0x1)                                        /* (CRU_REFO3CON) When emulator is in Debug mode, module freezes operation  */
#define   CRU_REFO3CON_FRZ_NO_FRZ_Val         _UINT32_(0x0)                                        /* (CRU_REFO3CON) When emulator is in Debug mode, module continues operation  */
#define CRU_REFO3CON_FRZ_FRZ                  (CRU_REFO3CON_FRZ_FRZ_Val << CRU_REFO3CON_FRZ_Pos)   /* (CRU_REFO3CON) When emulator is in Debug mode, module freezes operation Position  */
#define CRU_REFO3CON_FRZ_NO_FRZ               (CRU_REFO3CON_FRZ_NO_FRZ_Val << CRU_REFO3CON_FRZ_Pos) /* (CRU_REFO3CON) When emulator is in Debug mode, module continues operation Position  */
#define CRU_REFO3CON_ON_Pos                   _UINT32_(15)                                         /* (CRU_REFO3CON) Output Enable bit Position */
#define CRU_REFO3CON_ON_Msk                   (_UINT32_(0x1) << CRU_REFO3CON_ON_Pos)               /* (CRU_REFO3CON) Output Enable bit Mask */
#define CRU_REFO3CON_ON(value)                (CRU_REFO3CON_ON_Msk & (_UINT32_(value) << CRU_REFO3CON_ON_Pos)) /* Assigment of value for ON in the CRU_REFO3CON register */
#define   CRU_REFO3CON_ON_ON_Val              _UINT32_(0x1)                                        /* (CRU_REFO3CON) Reference Oscillator Module enabled  */
#define   CRU_REFO3CON_ON_OFF_Val             _UINT32_(0x0)                                        /* (CRU_REFO3CON) Reference Oscillator Module disabled  */
#define CRU_REFO3CON_ON_ON                    (CRU_REFO3CON_ON_ON_Val << CRU_REFO3CON_ON_Pos)      /* (CRU_REFO3CON) Reference Oscillator Module enabled Position  */
#define CRU_REFO3CON_ON_OFF                   (CRU_REFO3CON_ON_OFF_Val << CRU_REFO3CON_ON_Pos)     /* (CRU_REFO3CON) Reference Oscillator Module disabled Position  */
#define CRU_REFO3CON_RODIV_Pos                _UINT32_(16)                                         /* (CRU_REFO3CON) Reference Clock Divider bits Position */
#define CRU_REFO3CON_RODIV_Msk                (_UINT32_(0x7FFF) << CRU_REFO3CON_RODIV_Pos)         /* (CRU_REFO3CON) Reference Clock Divider bits Mask */
#define CRU_REFO3CON_RODIV(value)             (CRU_REFO3CON_RODIV_Msk & (_UINT32_(value) << CRU_REFO3CON_RODIV_Pos)) /* Assigment of value for RODIV in the CRU_REFO3CON register */
#define   CRU_REFO3CON_RODIV_65K_Val          _UINT32_(0x7FFF)                                     /* (CRU_REFO3CON) REFO3 clock is Base clock frequency divided by 65,534 (32,767 *2)  */
#define   CRU_REFO3CON_RODIV_4_Val            _UINT32_(0x2)                                        /* (CRU_REFO3CON) REFO3 clock is Base clock frequency divided by 4 (2*2)  */
#define   CRU_REFO3CON_RODIV_2_Val            _UINT32_(0x1)                                        /* (CRU_REFO3CON) REFO3 clock is Base clock frequency divided by 2 (1*2)  */
#define   CRU_REFO3CON_RODIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_REFO3CON) REFO3 clock is same frequency as Base clock (no divider)  */
#define CRU_REFO3CON_RODIV_65K                (CRU_REFO3CON_RODIV_65K_Val << CRU_REFO3CON_RODIV_Pos) /* (CRU_REFO3CON) REFO3 clock is Base clock frequency divided by 65,534 (32,767 *2) Position  */
#define CRU_REFO3CON_RODIV_4                  (CRU_REFO3CON_RODIV_4_Val << CRU_REFO3CON_RODIV_Pos) /* (CRU_REFO3CON) REFO3 clock is Base clock frequency divided by 4 (2*2) Position  */
#define CRU_REFO3CON_RODIV_2                  (CRU_REFO3CON_RODIV_2_Val << CRU_REFO3CON_RODIV_Pos) /* (CRU_REFO3CON) REFO3 clock is Base clock frequency divided by 2 (1*2) Position  */
#define CRU_REFO3CON_RODIV_NONE               (CRU_REFO3CON_RODIV_NONE_Val << CRU_REFO3CON_RODIV_Pos) /* (CRU_REFO3CON) REFO3 clock is same frequency as Base clock (no divider) Position  */
#define CRU_REFO3CON_Msk                      _UINT32_(0x7FFFFB0F)                                 /* (CRU_REFO3CON) Register Mask  */


/* -------- CRU_REFO3CONCLR : (CRU Offset: 0xB4) (R/W 32)  -------- */
#define CRU_REFO3CONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO3CONCLR)   Reset Value */

#define CRU_REFO3CONCLR_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO3CONCLR) Register Mask  */


/* -------- CRU_REFO3CONSET : (CRU Offset: 0xB8) (R/W 32)  -------- */
#define CRU_REFO3CONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO3CONSET)   Reset Value */

#define CRU_REFO3CONSET_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO3CONSET) Register Mask  */


/* -------- CRU_REFO3CONINV : (CRU Offset: 0xBC) (R/W 32)  -------- */
#define CRU_REFO3CONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO3CONINV)   Reset Value */

#define CRU_REFO3CONINV_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO3CONINV) Register Mask  */


/* -------- CRU_REFO3TRIM : (CRU Offset: 0xC0) (R/W 32) REFERENCE OSCILLATOR 3 TRIM REGISTER -------- */
#define CRU_REFO3TRIM_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_REFO3TRIM) REFERENCE OSCILLATOR 3 TRIM REGISTER  Reset Value */

#define CRU_REFO3TRIM_ROTRIM_Pos              _UINT32_(23)                                         /* (CRU_REFO3TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Position */
#define CRU_REFO3TRIM_ROTRIM_Msk              (_UINT32_(0x1FF) << CRU_REFO3TRIM_ROTRIM_Pos)        /* (CRU_REFO3TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Mask */
#define CRU_REFO3TRIM_ROTRIM(value)           (CRU_REFO3TRIM_ROTRIM_Msk & (_UINT32_(value) << CRU_REFO3TRIM_ROTRIM_Pos)) /* Assigment of value for ROTRIM in the CRU_REFO3TRIM register */
#define   CRU_REFO3TRIM_ROTRIM_ZERO_Val       _UINT32_(0x0)                                        /* (CRU_REFO3TRIM) 0/512 (0.0) divisor added to RODIV value  */
#define   CRU_REFO3TRIM_ROTRIM_1_Val          _UINT32_(0x1)                                        /* (CRU_REFO3TRIM) 1/512 (0.001953125) divisor added to RODIV value  */
#define   CRU_REFO3TRIM_ROTRIM_2_Val          _UINT32_(0x2)                                        /* (CRU_REFO3TRIM) 2/512 (0.00390625) divisor added to RODIV value  */
#define   CRU_REFO3TRIM_ROTRIM_256_Val        _UINT32_(0x100)                                      /* (CRU_REFO3TRIM) 256/512 (0.5000) divisor added to RODIV value  */
#define   CRU_REFO3TRIM_ROTRIM_511_Val        _UINT32_(0x1FF)                                      /* (CRU_REFO3TRIM) 511/512 (0.998046875) divisor added to RODIV value  */
#define CRU_REFO3TRIM_ROTRIM_ZERO             (CRU_REFO3TRIM_ROTRIM_ZERO_Val << CRU_REFO3TRIM_ROTRIM_Pos) /* (CRU_REFO3TRIM) 0/512 (0.0) divisor added to RODIV value Position  */
#define CRU_REFO3TRIM_ROTRIM_1                (CRU_REFO3TRIM_ROTRIM_1_Val << CRU_REFO3TRIM_ROTRIM_Pos) /* (CRU_REFO3TRIM) 1/512 (0.001953125) divisor added to RODIV value Position  */
#define CRU_REFO3TRIM_ROTRIM_2                (CRU_REFO3TRIM_ROTRIM_2_Val << CRU_REFO3TRIM_ROTRIM_Pos) /* (CRU_REFO3TRIM) 2/512 (0.00390625) divisor added to RODIV value Position  */
#define CRU_REFO3TRIM_ROTRIM_256              (CRU_REFO3TRIM_ROTRIM_256_Val << CRU_REFO3TRIM_ROTRIM_Pos) /* (CRU_REFO3TRIM) 256/512 (0.5000) divisor added to RODIV value Position  */
#define CRU_REFO3TRIM_ROTRIM_511              (CRU_REFO3TRIM_ROTRIM_511_Val << CRU_REFO3TRIM_ROTRIM_Pos) /* (CRU_REFO3TRIM) 511/512 (0.998046875) divisor added to RODIV value Position  */
#define CRU_REFO3TRIM_Msk                     _UINT32_(0xFF800000)                                 /* (CRU_REFO3TRIM) Register Mask  */


/* -------- CRU_REFO3TRIMCLR : (CRU Offset: 0xC4) (R/W 32)  -------- */
#define CRU_REFO3TRIMCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO3TRIMCLR)   Reset Value */

#define CRU_REFO3TRIMCLR_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO3TRIMCLR) Register Mask  */


/* -------- CRU_REFO3TRIMSET : (CRU Offset: 0xC8) (R/W 32)  -------- */
#define CRU_REFO3TRIMSET_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO3TRIMSET)   Reset Value */

#define CRU_REFO3TRIMSET_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO3TRIMSET) Register Mask  */


/* -------- CRU_REFO3TRIMINV : (CRU Offset: 0xCC) (R/W 32)  -------- */
#define CRU_REFO3TRIMINV_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO3TRIMINV)   Reset Value */

#define CRU_REFO3TRIMINV_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO3TRIMINV) Register Mask  */


/* -------- CRU_REFO4CON : (CRU Offset: 0xD0) (R/W 32) REFERENCE OSCILLATOR 4 CONTROL REGISTER -------- */
#define CRU_REFO4CON_RESETVALUE               _UINT32_(0x00)                                       /*  (CRU_REFO4CON) REFERENCE OSCILLATOR 4 CONTROL REGISTER  Reset Value */

#define CRU_REFO4CON_ROSEL_Pos                _UINT32_(0)                                          /* (CRU_REFO4CON) Reference Clock Source Select bits Position */
#define CRU_REFO4CON_ROSEL_Msk                (_UINT32_(0xF) << CRU_REFO4CON_ROSEL_Pos)            /* (CRU_REFO4CON) Reference Clock Source Select bits Mask */
#define CRU_REFO4CON_ROSEL(value)             (CRU_REFO4CON_ROSEL_Msk & (_UINT32_(value) << CRU_REFO4CON_ROSEL_Pos)) /* Assigment of value for ROSEL in the CRU_REFO4CON register */
#define   CRU_REFO4CON_ROSEL_REFCLKI_Val      _UINT32_(0x8)                                        /* (CRU_REFO4CON) REFI Pin  */
#define   CRU_REFO4CON_ROSEL_SYSCLK_Val       _UINT32_(0x7)                                        /* (CRU_REFO4CON) System clock (reference clock reflects any device clock switching)  */
#define   CRU_REFO4CON_ROSEL_PBCLK1_Val       _UINT32_(0x6)                                        /* (CRU_REFO4CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching)  */
#define   CRU_REFO4CON_ROSEL_SPLL3_Val        _UINT32_(0x5)                                        /* (CRU_REFO4CON) System PLL3 (Clock-3)  */
#define   CRU_REFO4CON_ROSEL_LPRC_Val         _UINT32_(0x4)                                        /* (CRU_REFO4CON) LPRC  */
#define   CRU_REFO4CON_ROSEL_SOSC_Val         _UINT32_(0x3)                                        /* (CRU_REFO4CON) SOSC  */
#define   CRU_REFO4CON_ROSEL_POSC_Val         _UINT32_(0x2)                                        /* (CRU_REFO4CON) POSC  */
#define   CRU_REFO4CON_ROSEL_SPLL1_Val        _UINT32_(0x1)                                        /* (CRU_REFO4CON) System PLL1 (Clock-1)  */
#define   CRU_REFO4CON_ROSEL_FRC_Val          _UINT32_(0x0)                                        /* (CRU_REFO4CON) FRC  */
#define CRU_REFO4CON_ROSEL_REFCLKI            (CRU_REFO4CON_ROSEL_REFCLKI_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) REFI Pin Position  */
#define CRU_REFO4CON_ROSEL_SYSCLK             (CRU_REFO4CON_ROSEL_SYSCLK_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) System clock (reference clock reflects any device clock switching) Position  */
#define CRU_REFO4CON_ROSEL_PBCLK1             (CRU_REFO4CON_ROSEL_PBCLK1_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching) Position  */
#define CRU_REFO4CON_ROSEL_SPLL3              (CRU_REFO4CON_ROSEL_SPLL3_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) System PLL3 (Clock-3) Position  */
#define CRU_REFO4CON_ROSEL_LPRC               (CRU_REFO4CON_ROSEL_LPRC_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) LPRC Position  */
#define CRU_REFO4CON_ROSEL_SOSC               (CRU_REFO4CON_ROSEL_SOSC_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) SOSC Position  */
#define CRU_REFO4CON_ROSEL_POSC               (CRU_REFO4CON_ROSEL_POSC_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) POSC Position  */
#define CRU_REFO4CON_ROSEL_SPLL1              (CRU_REFO4CON_ROSEL_SPLL1_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) System PLL1 (Clock-1) Position  */
#define CRU_REFO4CON_ROSEL_FRC                (CRU_REFO4CON_ROSEL_FRC_Val << CRU_REFO4CON_ROSEL_Pos) /* (CRU_REFO4CON) FRC Position  */
#define CRU_REFO4CON_ACTIVE_Pos               _UINT32_(8)                                          /* (CRU_REFO4CON) Reference Clock Request Status bit Position */
#define CRU_REFO4CON_ACTIVE_Msk               (_UINT32_(0x1) << CRU_REFO4CON_ACTIVE_Pos)           /* (CRU_REFO4CON) Reference Clock Request Status bit Mask */
#define CRU_REFO4CON_ACTIVE(value)            (CRU_REFO4CON_ACTIVE_Msk & (_UINT32_(value) << CRU_REFO4CON_ACTIVE_Pos)) /* Assigment of value for ACTIVE in the CRU_REFO4CON register */
#define   CRU_REFO4CON_ACTIVE_ACTIVE_Val      _UINT32_(0x1)                                        /* (CRU_REFO4CON) Reference clock request is active (User should not update this REFOCON register)  */
#define   CRU_REFO4CON_ACTIVE_NOT_ACTIVE_Val  _UINT32_(0x0)                                        /* (CRU_REFO4CON) Reference clock request is not active (User can update this REFOCON register)  */
#define CRU_REFO4CON_ACTIVE_ACTIVE            (CRU_REFO4CON_ACTIVE_ACTIVE_Val << CRU_REFO4CON_ACTIVE_Pos) /* (CRU_REFO4CON) Reference clock request is active (User should not update this REFOCON register) Position  */
#define CRU_REFO4CON_ACTIVE_NOT_ACTIVE        (CRU_REFO4CON_ACTIVE_NOT_ACTIVE_Val << CRU_REFO4CON_ACTIVE_Pos) /* (CRU_REFO4CON) Reference clock request is not active (User can update this REFOCON register) Position  */
#define CRU_REFO4CON_DIVSWEN_Pos              _UINT32_(9)                                          /* (CRU_REFO4CON) Clock RODIV/ROTRIM switch enabled. Position */
#define CRU_REFO4CON_DIVSWEN_Msk              (_UINT32_(0x1) << CRU_REFO4CON_DIVSWEN_Pos)          /* (CRU_REFO4CON) Clock RODIV/ROTRIM switch enabled. Mask */
#define CRU_REFO4CON_DIVSWEN(value)           (CRU_REFO4CON_DIVSWEN_Msk & (_UINT32_(value) << CRU_REFO4CON_DIVSWEN_Pos)) /* Assigment of value for DIVSWEN in the CRU_REFO4CON register */
#define   CRU_REFO4CON_DIVSWEN_SWINPROGRESS_Val _UINT32_(0x1)                                        /* (CRU_REFO4CON) Clock Divider Switching currently in progress.  */
#define   CRU_REFO4CON_DIVSWEN_SWCOMPLETE_Val _UINT32_(0x0)                                        /* (CRU_REFO4CON) Clock Divider Switch has completed.  */
#define CRU_REFO4CON_DIVSWEN_SWINPROGRESS     (CRU_REFO4CON_DIVSWEN_SWINPROGRESS_Val << CRU_REFO4CON_DIVSWEN_Pos) /* (CRU_REFO4CON) Clock Divider Switching currently in progress. Position  */
#define CRU_REFO4CON_DIVSWEN_SWCOMPLETE       (CRU_REFO4CON_DIVSWEN_SWCOMPLETE_Val << CRU_REFO4CON_DIVSWEN_Pos) /* (CRU_REFO4CON) Clock Divider Switch has completed. Position  */
#define CRU_REFO4CON_RSLP_Pos                 _UINT32_(11)                                         /* (CRU_REFO4CON) Reference Oscillator Run in Sleep bit Position */
#define CRU_REFO4CON_RSLP_Msk                 (_UINT32_(0x1) << CRU_REFO4CON_RSLP_Pos)             /* (CRU_REFO4CON) Reference Oscillator Run in Sleep bit Mask */
#define CRU_REFO4CON_RSLP(value)              (CRU_REFO4CON_RSLP_Msk & (_UINT32_(value) << CRU_REFO4CON_RSLP_Pos)) /* Assigment of value for RSLP in the CRU_REFO4CON register */
#define   CRU_REFO4CON_RSLP_RSLP_Val          _UINT32_(0x1)                                        /* (CRU_REFO4CON) Reference Oscillator output continues to run in Sleep  */
#define   CRU_REFO4CON_RSLP_NO_RSLP_Val       _UINT32_(0x0)                                        /* (CRU_REFO4CON) Reference Oscillator output is disabled in Sleep  */
#define CRU_REFO4CON_RSLP_RSLP                (CRU_REFO4CON_RSLP_RSLP_Val << CRU_REFO4CON_RSLP_Pos) /* (CRU_REFO4CON) Reference Oscillator output continues to run in Sleep Position  */
#define CRU_REFO4CON_RSLP_NO_RSLP             (CRU_REFO4CON_RSLP_NO_RSLP_Val << CRU_REFO4CON_RSLP_Pos) /* (CRU_REFO4CON) Reference Oscillator output is disabled in Sleep Position  */
#define CRU_REFO4CON_OE_Pos                   _UINT32_(12)                                         /* (CRU_REFO4CON) Reference Clock Output Enable bit Position */
#define CRU_REFO4CON_OE_Msk                   (_UINT32_(0x1) << CRU_REFO4CON_OE_Pos)               /* (CRU_REFO4CON) Reference Clock Output Enable bit Mask */
#define CRU_REFO4CON_OE(value)                (CRU_REFO4CON_OE_Msk & (_UINT32_(value) << CRU_REFO4CON_OE_Pos)) /* Assigment of value for OE in the CRU_REFO4CON register */
#define   CRU_REFO4CON_OE_REFO4_OE_Val        _UINT32_(0x1)                                        /* (CRU_REFO4CON) Reference clock is driven out on REFO4 pin  */
#define   CRU_REFO4CON_OE_NO_REFO4_OE_Val     _UINT32_(0x0)                                        /* (CRU_REFO4CON) Reference clock is not driven out on REFO4 pin.  */
#define CRU_REFO4CON_OE_REFO4_OE              (CRU_REFO4CON_OE_REFO4_OE_Val << CRU_REFO4CON_OE_Pos) /* (CRU_REFO4CON) Reference clock is driven out on REFO4 pin Position  */
#define CRU_REFO4CON_OE_NO_REFO4_OE           (CRU_REFO4CON_OE_NO_REFO4_OE_Val << CRU_REFO4CON_OE_Pos) /* (CRU_REFO4CON) Reference clock is not driven out on REFO4 pin. Position  */
#define CRU_REFO4CON_SIDL_Pos                 _UINT32_(13)                                         /* (CRU_REFO4CON) Peripheral Stop in Idle Mode bit Position */
#define CRU_REFO4CON_SIDL_Msk                 (_UINT32_(0x1) << CRU_REFO4CON_SIDL_Pos)             /* (CRU_REFO4CON) Peripheral Stop in Idle Mode bit Mask */
#define CRU_REFO4CON_SIDL(value)              (CRU_REFO4CON_SIDL_Msk & (_UINT32_(value) << CRU_REFO4CON_SIDL_Pos)) /* Assigment of value for SIDL in the CRU_REFO4CON register */
#define   CRU_REFO4CON_SIDL_SIDL_Val          _UINT32_(0x1)                                        /* (CRU_REFO4CON) Discontinue module operation when device enters Idle mode  */
#define   CRU_REFO4CON_SIDL_NO_SIDL_Val       _UINT32_(0x0)                                        /* (CRU_REFO4CON) Continue module operation in Idle mode  */
#define CRU_REFO4CON_SIDL_SIDL                (CRU_REFO4CON_SIDL_SIDL_Val << CRU_REFO4CON_SIDL_Pos) /* (CRU_REFO4CON) Discontinue module operation when device enters Idle mode Position  */
#define CRU_REFO4CON_SIDL_NO_SIDL             (CRU_REFO4CON_SIDL_NO_SIDL_Val << CRU_REFO4CON_SIDL_Pos) /* (CRU_REFO4CON) Continue module operation in Idle mode Position  */
#define CRU_REFO4CON_FRZ_Pos                  _UINT32_(14)                                         /* (CRU_REFO4CON) Freeze in Debug mode bit Position */
#define CRU_REFO4CON_FRZ_Msk                  (_UINT32_(0x1) << CRU_REFO4CON_FRZ_Pos)              /* (CRU_REFO4CON) Freeze in Debug mode bit Mask */
#define CRU_REFO4CON_FRZ(value)               (CRU_REFO4CON_FRZ_Msk & (_UINT32_(value) << CRU_REFO4CON_FRZ_Pos)) /* Assigment of value for FRZ in the CRU_REFO4CON register */
#define   CRU_REFO4CON_FRZ_FRZ_Val            _UINT32_(0x1)                                        /* (CRU_REFO4CON) When emulator is in Debug mode, module freezes operation  */
#define   CRU_REFO4CON_FRZ_NO_FRZ_Val         _UINT32_(0x0)                                        /* (CRU_REFO4CON) When emulator is in Debug mode, module continues operation  */
#define CRU_REFO4CON_FRZ_FRZ                  (CRU_REFO4CON_FRZ_FRZ_Val << CRU_REFO4CON_FRZ_Pos)   /* (CRU_REFO4CON) When emulator is in Debug mode, module freezes operation Position  */
#define CRU_REFO4CON_FRZ_NO_FRZ               (CRU_REFO4CON_FRZ_NO_FRZ_Val << CRU_REFO4CON_FRZ_Pos) /* (CRU_REFO4CON) When emulator is in Debug mode, module continues operation Position  */
#define CRU_REFO4CON_ON_Pos                   _UINT32_(15)                                         /* (CRU_REFO4CON) Output Enable bit Position */
#define CRU_REFO4CON_ON_Msk                   (_UINT32_(0x1) << CRU_REFO4CON_ON_Pos)               /* (CRU_REFO4CON) Output Enable bit Mask */
#define CRU_REFO4CON_ON(value)                (CRU_REFO4CON_ON_Msk & (_UINT32_(value) << CRU_REFO4CON_ON_Pos)) /* Assigment of value for ON in the CRU_REFO4CON register */
#define   CRU_REFO4CON_ON_ON_Val              _UINT32_(0x1)                                        /* (CRU_REFO4CON) Reference Oscillator Module enabled  */
#define   CRU_REFO4CON_ON_OFF_Val             _UINT32_(0x0)                                        /* (CRU_REFO4CON) Reference Oscillator Module disabled  */
#define CRU_REFO4CON_ON_ON                    (CRU_REFO4CON_ON_ON_Val << CRU_REFO4CON_ON_Pos)      /* (CRU_REFO4CON) Reference Oscillator Module enabled Position  */
#define CRU_REFO4CON_ON_OFF                   (CRU_REFO4CON_ON_OFF_Val << CRU_REFO4CON_ON_Pos)     /* (CRU_REFO4CON) Reference Oscillator Module disabled Position  */
#define CRU_REFO4CON_RODIV_Pos                _UINT32_(16)                                         /* (CRU_REFO4CON) Reference Clock Divider bits Position */
#define CRU_REFO4CON_RODIV_Msk                (_UINT32_(0x7FFF) << CRU_REFO4CON_RODIV_Pos)         /* (CRU_REFO4CON) Reference Clock Divider bits Mask */
#define CRU_REFO4CON_RODIV(value)             (CRU_REFO4CON_RODIV_Msk & (_UINT32_(value) << CRU_REFO4CON_RODIV_Pos)) /* Assigment of value for RODIV in the CRU_REFO4CON register */
#define   CRU_REFO4CON_RODIV_65K_Val          _UINT32_(0x7FFF)                                     /* (CRU_REFO4CON) REFO4 clock is Base clock frequency divided by 65,534 (32,767 *2)  */
#define   CRU_REFO4CON_RODIV_4_Val            _UINT32_(0x2)                                        /* (CRU_REFO4CON) REFO4 clock is Base clock frequency divided by 4 (2*2)  */
#define   CRU_REFO4CON_RODIV_2_Val            _UINT32_(0x1)                                        /* (CRU_REFO4CON) REFO4 clock is Base clock frequency divided by 2 (1*2)  */
#define   CRU_REFO4CON_RODIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_REFO4CON) REFO4 clock is same frequency as Base clock (no divider)  */
#define CRU_REFO4CON_RODIV_65K                (CRU_REFO4CON_RODIV_65K_Val << CRU_REFO4CON_RODIV_Pos) /* (CRU_REFO4CON) REFO4 clock is Base clock frequency divided by 65,534 (32,767 *2) Position  */
#define CRU_REFO4CON_RODIV_4                  (CRU_REFO4CON_RODIV_4_Val << CRU_REFO4CON_RODIV_Pos) /* (CRU_REFO4CON) REFO4 clock is Base clock frequency divided by 4 (2*2) Position  */
#define CRU_REFO4CON_RODIV_2                  (CRU_REFO4CON_RODIV_2_Val << CRU_REFO4CON_RODIV_Pos) /* (CRU_REFO4CON) REFO4 clock is Base clock frequency divided by 2 (1*2) Position  */
#define CRU_REFO4CON_RODIV_NONE               (CRU_REFO4CON_RODIV_NONE_Val << CRU_REFO4CON_RODIV_Pos) /* (CRU_REFO4CON) REFO4 clock is same frequency as Base clock (no divider) Position  */
#define CRU_REFO4CON_Msk                      _UINT32_(0x7FFFFB0F)                                 /* (CRU_REFO4CON) Register Mask  */


/* -------- CRU_REFO4CONCLR : (CRU Offset: 0xD4) (R/W 32)  -------- */
#define CRU_REFO4CONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO4CONCLR)   Reset Value */

#define CRU_REFO4CONCLR_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO4CONCLR) Register Mask  */


/* -------- CRU_REFO4CONSET : (CRU Offset: 0xD8) (R/W 32)  -------- */
#define CRU_REFO4CONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO4CONSET)   Reset Value */

#define CRU_REFO4CONSET_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO4CONSET) Register Mask  */


/* -------- CRU_REFO4CONINV : (CRU Offset: 0xDC) (R/W 32)  -------- */
#define CRU_REFO4CONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO4CONINV)   Reset Value */

#define CRU_REFO4CONINV_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO4CONINV) Register Mask  */


/* -------- CRU_REFO4TRIM : (CRU Offset: 0xE0) (R/W 32) REFERENCE OSCILLATOR 4 TRIM REGISTER -------- */
#define CRU_REFO4TRIM_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_REFO4TRIM) REFERENCE OSCILLATOR 4 TRIM REGISTER  Reset Value */

#define CRU_REFO4TRIM_ROTRIM_Pos              _UINT32_(23)                                         /* (CRU_REFO4TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Position */
#define CRU_REFO4TRIM_ROTRIM_Msk              (_UINT32_(0x1FF) << CRU_REFO4TRIM_ROTRIM_Pos)        /* (CRU_REFO4TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Mask */
#define CRU_REFO4TRIM_ROTRIM(value)           (CRU_REFO4TRIM_ROTRIM_Msk & (_UINT32_(value) << CRU_REFO4TRIM_ROTRIM_Pos)) /* Assigment of value for ROTRIM in the CRU_REFO4TRIM register */
#define   CRU_REFO4TRIM_ROTRIM_ZERO_Val       _UINT32_(0x0)                                        /* (CRU_REFO4TRIM) 0/512 (0.0) divisor added to RODIV value  */
#define   CRU_REFO4TRIM_ROTRIM_1_Val          _UINT32_(0x1)                                        /* (CRU_REFO4TRIM) 1/512 (0.001953125) divisor added to RODIV value  */
#define   CRU_REFO4TRIM_ROTRIM_2_Val          _UINT32_(0x2)                                        /* (CRU_REFO4TRIM) 2/512 (0.00390625) divisor added to RODIV value  */
#define   CRU_REFO4TRIM_ROTRIM_256_Val        _UINT32_(0x100)                                      /* (CRU_REFO4TRIM) 256/512 (0.5000) divisor added to RODIV value  */
#define   CRU_REFO4TRIM_ROTRIM_511_Val        _UINT32_(0x1FF)                                      /* (CRU_REFO4TRIM) 511/512 (0.998046875) divisor added to RODIV value  */
#define CRU_REFO4TRIM_ROTRIM_ZERO             (CRU_REFO4TRIM_ROTRIM_ZERO_Val << CRU_REFO4TRIM_ROTRIM_Pos) /* (CRU_REFO4TRIM) 0/512 (0.0) divisor added to RODIV value Position  */
#define CRU_REFO4TRIM_ROTRIM_1                (CRU_REFO4TRIM_ROTRIM_1_Val << CRU_REFO4TRIM_ROTRIM_Pos) /* (CRU_REFO4TRIM) 1/512 (0.001953125) divisor added to RODIV value Position  */
#define CRU_REFO4TRIM_ROTRIM_2                (CRU_REFO4TRIM_ROTRIM_2_Val << CRU_REFO4TRIM_ROTRIM_Pos) /* (CRU_REFO4TRIM) 2/512 (0.00390625) divisor added to RODIV value Position  */
#define CRU_REFO4TRIM_ROTRIM_256              (CRU_REFO4TRIM_ROTRIM_256_Val << CRU_REFO4TRIM_ROTRIM_Pos) /* (CRU_REFO4TRIM) 256/512 (0.5000) divisor added to RODIV value Position  */
#define CRU_REFO4TRIM_ROTRIM_511              (CRU_REFO4TRIM_ROTRIM_511_Val << CRU_REFO4TRIM_ROTRIM_Pos) /* (CRU_REFO4TRIM) 511/512 (0.998046875) divisor added to RODIV value Position  */
#define CRU_REFO4TRIM_Msk                     _UINT32_(0xFF800000)                                 /* (CRU_REFO4TRIM) Register Mask  */


/* -------- CRU_REFO4TRIMCLR : (CRU Offset: 0xE4) (R/W 32)  -------- */
#define CRU_REFO4TRIMCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO4TRIMCLR)   Reset Value */

#define CRU_REFO4TRIMCLR_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO4TRIMCLR) Register Mask  */


/* -------- CRU_REFO4TRIMSET : (CRU Offset: 0xE8) (R/W 32)  -------- */
#define CRU_REFO4TRIMSET_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO4TRIMSET)   Reset Value */

#define CRU_REFO4TRIMSET_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO4TRIMSET) Register Mask  */


/* -------- CRU_REFO4TRIMINV : (CRU Offset: 0xEC) (R/W 32)  -------- */
#define CRU_REFO4TRIMINV_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO4TRIMINV)   Reset Value */

#define CRU_REFO4TRIMINV_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO4TRIMINV) Register Mask  */


/* -------- CRU_REFO5CON : (CRU Offset: 0xF0) (R/W 32) REFERENCE OSCILLATOR 5 CONTROL REGISTER -------- */
#define CRU_REFO5CON_RESETVALUE               _UINT32_(0x00)                                       /*  (CRU_REFO5CON) REFERENCE OSCILLATOR 5 CONTROL REGISTER  Reset Value */

#define CRU_REFO5CON_ROSEL_Pos                _UINT32_(0)                                          /* (CRU_REFO5CON) Reference Clock Source Select bits Position */
#define CRU_REFO5CON_ROSEL_Msk                (_UINT32_(0xF) << CRU_REFO5CON_ROSEL_Pos)            /* (CRU_REFO5CON) Reference Clock Source Select bits Mask */
#define CRU_REFO5CON_ROSEL(value)             (CRU_REFO5CON_ROSEL_Msk & (_UINT32_(value) << CRU_REFO5CON_ROSEL_Pos)) /* Assigment of value for ROSEL in the CRU_REFO5CON register */
#define   CRU_REFO5CON_ROSEL_REFCLKI_Val      _UINT32_(0x8)                                        /* (CRU_REFO5CON) REFI Pin  */
#define   CRU_REFO5CON_ROSEL_SYSCLK_Val       _UINT32_(0x7)                                        /* (CRU_REFO5CON) System clock (reference clock reflects any device clock switching)  */
#define   CRU_REFO5CON_ROSEL_PBCLK1_Val       _UINT32_(0x6)                                        /* (CRU_REFO5CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching)  */
#define   CRU_REFO5CON_ROSEL_SPLL3_Val        _UINT32_(0x5)                                        /* (CRU_REFO5CON) System PLL3 (Clock-3)  */
#define   CRU_REFO5CON_ROSEL_LPRC_Val         _UINT32_(0x4)                                        /* (CRU_REFO5CON) LPRC  */
#define   CRU_REFO5CON_ROSEL_SOSC_Val         _UINT32_(0x3)                                        /* (CRU_REFO5CON) SOSC  */
#define   CRU_REFO5CON_ROSEL_POSC_Val         _UINT32_(0x2)                                        /* (CRU_REFO5CON) POSC  */
#define   CRU_REFO5CON_ROSEL_SPLL1_Val        _UINT32_(0x1)                                        /* (CRU_REFO5CON) System PLL1 (Clock-1)  */
#define   CRU_REFO5CON_ROSEL_FRC_Val          _UINT32_(0x0)                                        /* (CRU_REFO5CON) FRC  */
#define CRU_REFO5CON_ROSEL_REFCLKI            (CRU_REFO5CON_ROSEL_REFCLKI_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) REFI Pin Position  */
#define CRU_REFO5CON_ROSEL_SYSCLK             (CRU_REFO5CON_ROSEL_SYSCLK_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) System clock (reference clock reflects any device clock switching) Position  */
#define CRU_REFO5CON_ROSEL_PBCLK1             (CRU_REFO5CON_ROSEL_PBCLK1_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching) Position  */
#define CRU_REFO5CON_ROSEL_SPLL3              (CRU_REFO5CON_ROSEL_SPLL3_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) System PLL3 (Clock-3) Position  */
#define CRU_REFO5CON_ROSEL_LPRC               (CRU_REFO5CON_ROSEL_LPRC_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) LPRC Position  */
#define CRU_REFO5CON_ROSEL_SOSC               (CRU_REFO5CON_ROSEL_SOSC_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) SOSC Position  */
#define CRU_REFO5CON_ROSEL_POSC               (CRU_REFO5CON_ROSEL_POSC_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) POSC Position  */
#define CRU_REFO5CON_ROSEL_SPLL1              (CRU_REFO5CON_ROSEL_SPLL1_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) System PLL1 (Clock-1) Position  */
#define CRU_REFO5CON_ROSEL_FRC                (CRU_REFO5CON_ROSEL_FRC_Val << CRU_REFO5CON_ROSEL_Pos) /* (CRU_REFO5CON) FRC Position  */
#define CRU_REFO5CON_ACTIVE_Pos               _UINT32_(8)                                          /* (CRU_REFO5CON) Reference Clock Request Status bit Position */
#define CRU_REFO5CON_ACTIVE_Msk               (_UINT32_(0x1) << CRU_REFO5CON_ACTIVE_Pos)           /* (CRU_REFO5CON) Reference Clock Request Status bit Mask */
#define CRU_REFO5CON_ACTIVE(value)            (CRU_REFO5CON_ACTIVE_Msk & (_UINT32_(value) << CRU_REFO5CON_ACTIVE_Pos)) /* Assigment of value for ACTIVE in the CRU_REFO5CON register */
#define   CRU_REFO5CON_ACTIVE_ACTIVE_Val      _UINT32_(0x1)                                        /* (CRU_REFO5CON) Reference clock request is active (User should not update this REFOCON register)  */
#define   CRU_REFO5CON_ACTIVE_NOT_ACTIVE_Val  _UINT32_(0x0)                                        /* (CRU_REFO5CON) Reference clock request is not active (User can update this REFOCON register)  */
#define CRU_REFO5CON_ACTIVE_ACTIVE            (CRU_REFO5CON_ACTIVE_ACTIVE_Val << CRU_REFO5CON_ACTIVE_Pos) /* (CRU_REFO5CON) Reference clock request is active (User should not update this REFOCON register) Position  */
#define CRU_REFO5CON_ACTIVE_NOT_ACTIVE        (CRU_REFO5CON_ACTIVE_NOT_ACTIVE_Val << CRU_REFO5CON_ACTIVE_Pos) /* (CRU_REFO5CON) Reference clock request is not active (User can update this REFOCON register) Position  */
#define CRU_REFO5CON_DIVSWEN_Pos              _UINT32_(9)                                          /* (CRU_REFO5CON) Clock RODIV/ROTRIM switch enabled. Position */
#define CRU_REFO5CON_DIVSWEN_Msk              (_UINT32_(0x1) << CRU_REFO5CON_DIVSWEN_Pos)          /* (CRU_REFO5CON) Clock RODIV/ROTRIM switch enabled. Mask */
#define CRU_REFO5CON_DIVSWEN(value)           (CRU_REFO5CON_DIVSWEN_Msk & (_UINT32_(value) << CRU_REFO5CON_DIVSWEN_Pos)) /* Assigment of value for DIVSWEN in the CRU_REFO5CON register */
#define   CRU_REFO5CON_DIVSWEN_SWINPROGRESS_Val _UINT32_(0x1)                                        /* (CRU_REFO5CON) Clock Divider Switching currently in progress.  */
#define   CRU_REFO5CON_DIVSWEN_SWCOMPLETE_Val _UINT32_(0x0)                                        /* (CRU_REFO5CON) Clock Divider Switch has completed.  */
#define CRU_REFO5CON_DIVSWEN_SWINPROGRESS     (CRU_REFO5CON_DIVSWEN_SWINPROGRESS_Val << CRU_REFO5CON_DIVSWEN_Pos) /* (CRU_REFO5CON) Clock Divider Switching currently in progress. Position  */
#define CRU_REFO5CON_DIVSWEN_SWCOMPLETE       (CRU_REFO5CON_DIVSWEN_SWCOMPLETE_Val << CRU_REFO5CON_DIVSWEN_Pos) /* (CRU_REFO5CON) Clock Divider Switch has completed. Position  */
#define CRU_REFO5CON_RSLP_Pos                 _UINT32_(11)                                         /* (CRU_REFO5CON) Reference Oscillator Run in Sleep bit Position */
#define CRU_REFO5CON_RSLP_Msk                 (_UINT32_(0x1) << CRU_REFO5CON_RSLP_Pos)             /* (CRU_REFO5CON) Reference Oscillator Run in Sleep bit Mask */
#define CRU_REFO5CON_RSLP(value)              (CRU_REFO5CON_RSLP_Msk & (_UINT32_(value) << CRU_REFO5CON_RSLP_Pos)) /* Assigment of value for RSLP in the CRU_REFO5CON register */
#define   CRU_REFO5CON_RSLP_RSLP_Val          _UINT32_(0x1)                                        /* (CRU_REFO5CON) Reference Oscillator output continues to run in Sleep  */
#define   CRU_REFO5CON_RSLP_NO_RSLP_Val       _UINT32_(0x0)                                        /* (CRU_REFO5CON) Reference Oscillator output is disabled in Sleep  */
#define CRU_REFO5CON_RSLP_RSLP                (CRU_REFO5CON_RSLP_RSLP_Val << CRU_REFO5CON_RSLP_Pos) /* (CRU_REFO5CON) Reference Oscillator output continues to run in Sleep Position  */
#define CRU_REFO5CON_RSLP_NO_RSLP             (CRU_REFO5CON_RSLP_NO_RSLP_Val << CRU_REFO5CON_RSLP_Pos) /* (CRU_REFO5CON) Reference Oscillator output is disabled in Sleep Position  */
#define CRU_REFO5CON_OE_Pos                   _UINT32_(12)                                         /* (CRU_REFO5CON) Reference Clock Output Enable bit Position */
#define CRU_REFO5CON_OE_Msk                   (_UINT32_(0x1) << CRU_REFO5CON_OE_Pos)               /* (CRU_REFO5CON) Reference Clock Output Enable bit Mask */
#define CRU_REFO5CON_OE(value)                (CRU_REFO5CON_OE_Msk & (_UINT32_(value) << CRU_REFO5CON_OE_Pos)) /* Assigment of value for OE in the CRU_REFO5CON register */
#define   CRU_REFO5CON_OE_REFO5_OE_Val        _UINT32_(0x1)                                        /* (CRU_REFO5CON) Reference clock is driven out on REFO5 pin  */
#define   CRU_REFO5CON_OE_NO_REFO5_OE_Val     _UINT32_(0x0)                                        /* (CRU_REFO5CON) Reference clock is not driven out on REFO5 pin.  */
#define CRU_REFO5CON_OE_REFO5_OE              (CRU_REFO5CON_OE_REFO5_OE_Val << CRU_REFO5CON_OE_Pos) /* (CRU_REFO5CON) Reference clock is driven out on REFO5 pin Position  */
#define CRU_REFO5CON_OE_NO_REFO5_OE           (CRU_REFO5CON_OE_NO_REFO5_OE_Val << CRU_REFO5CON_OE_Pos) /* (CRU_REFO5CON) Reference clock is not driven out on REFO5 pin. Position  */
#define CRU_REFO5CON_SIDL_Pos                 _UINT32_(13)                                         /* (CRU_REFO5CON) Peripheral Stop in Idle Mode bit Position */
#define CRU_REFO5CON_SIDL_Msk                 (_UINT32_(0x1) << CRU_REFO5CON_SIDL_Pos)             /* (CRU_REFO5CON) Peripheral Stop in Idle Mode bit Mask */
#define CRU_REFO5CON_SIDL(value)              (CRU_REFO5CON_SIDL_Msk & (_UINT32_(value) << CRU_REFO5CON_SIDL_Pos)) /* Assigment of value for SIDL in the CRU_REFO5CON register */
#define   CRU_REFO5CON_SIDL_SIDL_Val          _UINT32_(0x1)                                        /* (CRU_REFO5CON) Discontinue module operation when device enters Idle mode  */
#define   CRU_REFO5CON_SIDL_NO_SIDL_Val       _UINT32_(0x0)                                        /* (CRU_REFO5CON) Continue module operation in Idle mode  */
#define CRU_REFO5CON_SIDL_SIDL                (CRU_REFO5CON_SIDL_SIDL_Val << CRU_REFO5CON_SIDL_Pos) /* (CRU_REFO5CON) Discontinue module operation when device enters Idle mode Position  */
#define CRU_REFO5CON_SIDL_NO_SIDL             (CRU_REFO5CON_SIDL_NO_SIDL_Val << CRU_REFO5CON_SIDL_Pos) /* (CRU_REFO5CON) Continue module operation in Idle mode Position  */
#define CRU_REFO5CON_FRZ_Pos                  _UINT32_(14)                                         /* (CRU_REFO5CON) Freeze in Debug mode bit Position */
#define CRU_REFO5CON_FRZ_Msk                  (_UINT32_(0x1) << CRU_REFO5CON_FRZ_Pos)              /* (CRU_REFO5CON) Freeze in Debug mode bit Mask */
#define CRU_REFO5CON_FRZ(value)               (CRU_REFO5CON_FRZ_Msk & (_UINT32_(value) << CRU_REFO5CON_FRZ_Pos)) /* Assigment of value for FRZ in the CRU_REFO5CON register */
#define   CRU_REFO5CON_FRZ_FRZ_Val            _UINT32_(0x1)                                        /* (CRU_REFO5CON) When emulator is in Debug mode, module freezes operation  */
#define   CRU_REFO5CON_FRZ_NO_FRZ_Val         _UINT32_(0x0)                                        /* (CRU_REFO5CON) When emulator is in Debug mode, module continues operation  */
#define CRU_REFO5CON_FRZ_FRZ                  (CRU_REFO5CON_FRZ_FRZ_Val << CRU_REFO5CON_FRZ_Pos)   /* (CRU_REFO5CON) When emulator is in Debug mode, module freezes operation Position  */
#define CRU_REFO5CON_FRZ_NO_FRZ               (CRU_REFO5CON_FRZ_NO_FRZ_Val << CRU_REFO5CON_FRZ_Pos) /* (CRU_REFO5CON) When emulator is in Debug mode, module continues operation Position  */
#define CRU_REFO5CON_ON_Pos                   _UINT32_(15)                                         /* (CRU_REFO5CON) Output Enable bit Position */
#define CRU_REFO5CON_ON_Msk                   (_UINT32_(0x1) << CRU_REFO5CON_ON_Pos)               /* (CRU_REFO5CON) Output Enable bit Mask */
#define CRU_REFO5CON_ON(value)                (CRU_REFO5CON_ON_Msk & (_UINT32_(value) << CRU_REFO5CON_ON_Pos)) /* Assigment of value for ON in the CRU_REFO5CON register */
#define   CRU_REFO5CON_ON_ON_Val              _UINT32_(0x1)                                        /* (CRU_REFO5CON) Reference Oscillator Module enabled  */
#define   CRU_REFO5CON_ON_OFF_Val             _UINT32_(0x0)                                        /* (CRU_REFO5CON) Reference Oscillator Module disabled  */
#define CRU_REFO5CON_ON_ON                    (CRU_REFO5CON_ON_ON_Val << CRU_REFO5CON_ON_Pos)      /* (CRU_REFO5CON) Reference Oscillator Module enabled Position  */
#define CRU_REFO5CON_ON_OFF                   (CRU_REFO5CON_ON_OFF_Val << CRU_REFO5CON_ON_Pos)     /* (CRU_REFO5CON) Reference Oscillator Module disabled Position  */
#define CRU_REFO5CON_RODIV_Pos                _UINT32_(16)                                         /* (CRU_REFO5CON) Reference Clock Divider bits Position */
#define CRU_REFO5CON_RODIV_Msk                (_UINT32_(0x7FFF) << CRU_REFO5CON_RODIV_Pos)         /* (CRU_REFO5CON) Reference Clock Divider bits Mask */
#define CRU_REFO5CON_RODIV(value)             (CRU_REFO5CON_RODIV_Msk & (_UINT32_(value) << CRU_REFO5CON_RODIV_Pos)) /* Assigment of value for RODIV in the CRU_REFO5CON register */
#define   CRU_REFO5CON_RODIV_65K_Val          _UINT32_(0x7FFF)                                     /* (CRU_REFO5CON) REFO5 clock is Base clock frequency divided by 65,534 (32,767 *2)  */
#define   CRU_REFO5CON_RODIV_4_Val            _UINT32_(0x2)                                        /* (CRU_REFO5CON) REFO5 clock is Base clock frequency divided by 4 (2*2)  */
#define   CRU_REFO5CON_RODIV_2_Val            _UINT32_(0x1)                                        /* (CRU_REFO5CON) REFO5 clock is Base clock frequency divided by 2 (1*2)  */
#define   CRU_REFO5CON_RODIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_REFO5CON) REFO5 clock is same frequency as Base clock (no divider)  */
#define CRU_REFO5CON_RODIV_65K                (CRU_REFO5CON_RODIV_65K_Val << CRU_REFO5CON_RODIV_Pos) /* (CRU_REFO5CON) REFO5 clock is Base clock frequency divided by 65,534 (32,767 *2) Position  */
#define CRU_REFO5CON_RODIV_4                  (CRU_REFO5CON_RODIV_4_Val << CRU_REFO5CON_RODIV_Pos) /* (CRU_REFO5CON) REFO5 clock is Base clock frequency divided by 4 (2*2) Position  */
#define CRU_REFO5CON_RODIV_2                  (CRU_REFO5CON_RODIV_2_Val << CRU_REFO5CON_RODIV_Pos) /* (CRU_REFO5CON) REFO5 clock is Base clock frequency divided by 2 (1*2) Position  */
#define CRU_REFO5CON_RODIV_NONE               (CRU_REFO5CON_RODIV_NONE_Val << CRU_REFO5CON_RODIV_Pos) /* (CRU_REFO5CON) REFO5 clock is same frequency as Base clock (no divider) Position  */
#define CRU_REFO5CON_Msk                      _UINT32_(0x7FFFFB0F)                                 /* (CRU_REFO5CON) Register Mask  */


/* -------- CRU_REFO5CONCLR : (CRU Offset: 0xF4) (R/W 32)  -------- */
#define CRU_REFO5CONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO5CONCLR)   Reset Value */

#define CRU_REFO5CONCLR_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO5CONCLR) Register Mask  */


/* -------- CRU_REFO5CONSET : (CRU Offset: 0xF8) (R/W 32)  -------- */
#define CRU_REFO5CONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO5CONSET)   Reset Value */

#define CRU_REFO5CONSET_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO5CONSET) Register Mask  */


/* -------- CRU_REFO5CONINV : (CRU Offset: 0xFC) (R/W 32)  -------- */
#define CRU_REFO5CONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO5CONINV)   Reset Value */

#define CRU_REFO5CONINV_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO5CONINV) Register Mask  */


/* -------- CRU_REFO5TRIM : (CRU Offset: 0x100) (R/W 32) REFERENCE OSCILLATOR 5 TRIM REGISTER -------- */
#define CRU_REFO5TRIM_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_REFO5TRIM) REFERENCE OSCILLATOR 5 TRIM REGISTER  Reset Value */

#define CRU_REFO5TRIM_ROTRIM_Pos              _UINT32_(23)                                         /* (CRU_REFO5TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Position */
#define CRU_REFO5TRIM_ROTRIM_Msk              (_UINT32_(0x1FF) << CRU_REFO5TRIM_ROTRIM_Pos)        /* (CRU_REFO5TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Mask */
#define CRU_REFO5TRIM_ROTRIM(value)           (CRU_REFO5TRIM_ROTRIM_Msk & (_UINT32_(value) << CRU_REFO5TRIM_ROTRIM_Pos)) /* Assigment of value for ROTRIM in the CRU_REFO5TRIM register */
#define   CRU_REFO5TRIM_ROTRIM_ZERO_Val       _UINT32_(0x0)                                        /* (CRU_REFO5TRIM) 0/512 (0.0) divisor added to RODIV value  */
#define   CRU_REFO5TRIM_ROTRIM_1_Val          _UINT32_(0x1)                                        /* (CRU_REFO5TRIM) 1/512 (0.001953125) divisor added to RODIV value  */
#define   CRU_REFO5TRIM_ROTRIM_2_Val          _UINT32_(0x2)                                        /* (CRU_REFO5TRIM) 2/512 (0.00390625) divisor added to RODIV value  */
#define   CRU_REFO5TRIM_ROTRIM_256_Val        _UINT32_(0x100)                                      /* (CRU_REFO5TRIM) 256/512 (0.5000) divisor added to RODIV value  */
#define   CRU_REFO5TRIM_ROTRIM_511_Val        _UINT32_(0x1FF)                                      /* (CRU_REFO5TRIM) 511/512 (0.998046875) divisor added to RODIV value  */
#define CRU_REFO5TRIM_ROTRIM_ZERO             (CRU_REFO5TRIM_ROTRIM_ZERO_Val << CRU_REFO5TRIM_ROTRIM_Pos) /* (CRU_REFO5TRIM) 0/512 (0.0) divisor added to RODIV value Position  */
#define CRU_REFO5TRIM_ROTRIM_1                (CRU_REFO5TRIM_ROTRIM_1_Val << CRU_REFO5TRIM_ROTRIM_Pos) /* (CRU_REFO5TRIM) 1/512 (0.001953125) divisor added to RODIV value Position  */
#define CRU_REFO5TRIM_ROTRIM_2                (CRU_REFO5TRIM_ROTRIM_2_Val << CRU_REFO5TRIM_ROTRIM_Pos) /* (CRU_REFO5TRIM) 2/512 (0.00390625) divisor added to RODIV value Position  */
#define CRU_REFO5TRIM_ROTRIM_256              (CRU_REFO5TRIM_ROTRIM_256_Val << CRU_REFO5TRIM_ROTRIM_Pos) /* (CRU_REFO5TRIM) 256/512 (0.5000) divisor added to RODIV value Position  */
#define CRU_REFO5TRIM_ROTRIM_511              (CRU_REFO5TRIM_ROTRIM_511_Val << CRU_REFO5TRIM_ROTRIM_Pos) /* (CRU_REFO5TRIM) 511/512 (0.998046875) divisor added to RODIV value Position  */
#define CRU_REFO5TRIM_Msk                     _UINT32_(0xFF800000)                                 /* (CRU_REFO5TRIM) Register Mask  */


/* -------- CRU_REFO5TRIMCLR : (CRU Offset: 0x104) (R/W 32)  -------- */
#define CRU_REFO5TRIMCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO5TRIMCLR)   Reset Value */

#define CRU_REFO5TRIMCLR_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO5TRIMCLR) Register Mask  */


/* -------- CRU_REFO5TRIMSET : (CRU Offset: 0x108) (R/W 32)  -------- */
#define CRU_REFO5TRIMSET_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO5TRIMSET)   Reset Value */

#define CRU_REFO5TRIMSET_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO5TRIMSET) Register Mask  */


/* -------- CRU_REFO5TRIMINV : (CRU Offset: 0x10C) (R/W 32)  -------- */
#define CRU_REFO5TRIMINV_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO5TRIMINV)   Reset Value */

#define CRU_REFO5TRIMINV_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO5TRIMINV) Register Mask  */


/* -------- CRU_REFO6CON : (CRU Offset: 0x110) (R/W 32) REFERENCE OSCILLATOR 6 CONTROL REGISTER -------- */
#define CRU_REFO6CON_RESETVALUE               _UINT32_(0x00)                                       /*  (CRU_REFO6CON) REFERENCE OSCILLATOR 6 CONTROL REGISTER  Reset Value */

#define CRU_REFO6CON_ROSEL_Pos                _UINT32_(0)                                          /* (CRU_REFO6CON) Reference Clock Source Select bits Position */
#define CRU_REFO6CON_ROSEL_Msk                (_UINT32_(0xF) << CRU_REFO6CON_ROSEL_Pos)            /* (CRU_REFO6CON) Reference Clock Source Select bits Mask */
#define CRU_REFO6CON_ROSEL(value)             (CRU_REFO6CON_ROSEL_Msk & (_UINT32_(value) << CRU_REFO6CON_ROSEL_Pos)) /* Assigment of value for ROSEL in the CRU_REFO6CON register */
#define   CRU_REFO6CON_ROSEL_REFCLKI_Val      _UINT32_(0x8)                                        /* (CRU_REFO6CON) REFI Pin  */
#define   CRU_REFO6CON_ROSEL_SYSCLK_Val       _UINT32_(0x7)                                        /* (CRU_REFO6CON) System clock (reference clock reflects any device clock switching)  */
#define   CRU_REFO6CON_ROSEL_PBCLK1_Val       _UINT32_(0x6)                                        /* (CRU_REFO6CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching)  */
#define   CRU_REFO6CON_ROSEL_SPLL3_Val        _UINT32_(0x5)                                        /* (CRU_REFO6CON) System PLL3 (Clock-3)  */
#define   CRU_REFO6CON_ROSEL_LPRC_Val         _UINT32_(0x4)                                        /* (CRU_REFO6CON) LPRC  */
#define   CRU_REFO6CON_ROSEL_SOSC_Val         _UINT32_(0x3)                                        /* (CRU_REFO6CON) SOSC  */
#define   CRU_REFO6CON_ROSEL_POSC_Val         _UINT32_(0x2)                                        /* (CRU_REFO6CON) POSC  */
#define   CRU_REFO6CON_ROSEL_SPLL1_Val        _UINT32_(0x1)                                        /* (CRU_REFO6CON) System PLL1 (Clock-1)  */
#define   CRU_REFO6CON_ROSEL_FRC_Val          _UINT32_(0x0)                                        /* (CRU_REFO6CON) FRC  */
#define CRU_REFO6CON_ROSEL_REFCLKI            (CRU_REFO6CON_ROSEL_REFCLKI_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) REFI Pin Position  */
#define CRU_REFO6CON_ROSEL_SYSCLK             (CRU_REFO6CON_ROSEL_SYSCLK_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) System clock (reference clock reflects any device clock switching) Position  */
#define CRU_REFO6CON_ROSEL_PBCLK1             (CRU_REFO6CON_ROSEL_PBCLK1_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) Peripheral clock 1 (reference clock reflects any peripheral clock switching) Position  */
#define CRU_REFO6CON_ROSEL_SPLL3              (CRU_REFO6CON_ROSEL_SPLL3_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) System PLL3 (Clock-3) Position  */
#define CRU_REFO6CON_ROSEL_LPRC               (CRU_REFO6CON_ROSEL_LPRC_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) LPRC Position  */
#define CRU_REFO6CON_ROSEL_SOSC               (CRU_REFO6CON_ROSEL_SOSC_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) SOSC Position  */
#define CRU_REFO6CON_ROSEL_POSC               (CRU_REFO6CON_ROSEL_POSC_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) POSC Position  */
#define CRU_REFO6CON_ROSEL_SPLL1              (CRU_REFO6CON_ROSEL_SPLL1_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) System PLL1 (Clock-1) Position  */
#define CRU_REFO6CON_ROSEL_FRC                (CRU_REFO6CON_ROSEL_FRC_Val << CRU_REFO6CON_ROSEL_Pos) /* (CRU_REFO6CON) FRC Position  */
#define CRU_REFO6CON_ACTIVE_Pos               _UINT32_(8)                                          /* (CRU_REFO6CON) Reference Clock Request Status bit Position */
#define CRU_REFO6CON_ACTIVE_Msk               (_UINT32_(0x1) << CRU_REFO6CON_ACTIVE_Pos)           /* (CRU_REFO6CON) Reference Clock Request Status bit Mask */
#define CRU_REFO6CON_ACTIVE(value)            (CRU_REFO6CON_ACTIVE_Msk & (_UINT32_(value) << CRU_REFO6CON_ACTIVE_Pos)) /* Assigment of value for ACTIVE in the CRU_REFO6CON register */
#define   CRU_REFO6CON_ACTIVE_ACTIVE_Val      _UINT32_(0x1)                                        /* (CRU_REFO6CON) Reference clock request is active (User should not update this REFOCON register)  */
#define   CRU_REFO6CON_ACTIVE_NOT_ACTIVE_Val  _UINT32_(0x0)                                        /* (CRU_REFO6CON) Reference clock request is not active (User can update this REFOCON register)  */
#define CRU_REFO6CON_ACTIVE_ACTIVE            (CRU_REFO6CON_ACTIVE_ACTIVE_Val << CRU_REFO6CON_ACTIVE_Pos) /* (CRU_REFO6CON) Reference clock request is active (User should not update this REFOCON register) Position  */
#define CRU_REFO6CON_ACTIVE_NOT_ACTIVE        (CRU_REFO6CON_ACTIVE_NOT_ACTIVE_Val << CRU_REFO6CON_ACTIVE_Pos) /* (CRU_REFO6CON) Reference clock request is not active (User can update this REFOCON register) Position  */
#define CRU_REFO6CON_DIVSWEN_Pos              _UINT32_(9)                                          /* (CRU_REFO6CON) Clock RODIV/ROTRIM switch enabled. Position */
#define CRU_REFO6CON_DIVSWEN_Msk              (_UINT32_(0x1) << CRU_REFO6CON_DIVSWEN_Pos)          /* (CRU_REFO6CON) Clock RODIV/ROTRIM switch enabled. Mask */
#define CRU_REFO6CON_DIVSWEN(value)           (CRU_REFO6CON_DIVSWEN_Msk & (_UINT32_(value) << CRU_REFO6CON_DIVSWEN_Pos)) /* Assigment of value for DIVSWEN in the CRU_REFO6CON register */
#define   CRU_REFO6CON_DIVSWEN_SWINPROGRESS_Val _UINT32_(0x1)                                        /* (CRU_REFO6CON) Clock Divider Switching currently in progress.  */
#define   CRU_REFO6CON_DIVSWEN_SWCOMPLETE_Val _UINT32_(0x0)                                        /* (CRU_REFO6CON) Clock Divider Switch has completed.  */
#define CRU_REFO6CON_DIVSWEN_SWINPROGRESS     (CRU_REFO6CON_DIVSWEN_SWINPROGRESS_Val << CRU_REFO6CON_DIVSWEN_Pos) /* (CRU_REFO6CON) Clock Divider Switching currently in progress. Position  */
#define CRU_REFO6CON_DIVSWEN_SWCOMPLETE       (CRU_REFO6CON_DIVSWEN_SWCOMPLETE_Val << CRU_REFO6CON_DIVSWEN_Pos) /* (CRU_REFO6CON) Clock Divider Switch has completed. Position  */
#define CRU_REFO6CON_RSLP_Pos                 _UINT32_(11)                                         /* (CRU_REFO6CON) Reference Oscillator Run in Sleep bit Position */
#define CRU_REFO6CON_RSLP_Msk                 (_UINT32_(0x1) << CRU_REFO6CON_RSLP_Pos)             /* (CRU_REFO6CON) Reference Oscillator Run in Sleep bit Mask */
#define CRU_REFO6CON_RSLP(value)              (CRU_REFO6CON_RSLP_Msk & (_UINT32_(value) << CRU_REFO6CON_RSLP_Pos)) /* Assigment of value for RSLP in the CRU_REFO6CON register */
#define   CRU_REFO6CON_RSLP_RSLP_Val          _UINT32_(0x1)                                        /* (CRU_REFO6CON) Reference Oscillator output continues to run in Sleep  */
#define   CRU_REFO6CON_RSLP_NO_RSLP_Val       _UINT32_(0x0)                                        /* (CRU_REFO6CON) Reference Oscillator output is disabled in Sleep  */
#define CRU_REFO6CON_RSLP_RSLP                (CRU_REFO6CON_RSLP_RSLP_Val << CRU_REFO6CON_RSLP_Pos) /* (CRU_REFO6CON) Reference Oscillator output continues to run in Sleep Position  */
#define CRU_REFO6CON_RSLP_NO_RSLP             (CRU_REFO6CON_RSLP_NO_RSLP_Val << CRU_REFO6CON_RSLP_Pos) /* (CRU_REFO6CON) Reference Oscillator output is disabled in Sleep Position  */
#define CRU_REFO6CON_OE_Pos                   _UINT32_(12)                                         /* (CRU_REFO6CON) Reference Clock Output Enable bit Position */
#define CRU_REFO6CON_OE_Msk                   (_UINT32_(0x1) << CRU_REFO6CON_OE_Pos)               /* (CRU_REFO6CON) Reference Clock Output Enable bit Mask */
#define CRU_REFO6CON_OE(value)                (CRU_REFO6CON_OE_Msk & (_UINT32_(value) << CRU_REFO6CON_OE_Pos)) /* Assigment of value for OE in the CRU_REFO6CON register */
#define   CRU_REFO6CON_OE_REFO6_OE_Val        _UINT32_(0x1)                                        /* (CRU_REFO6CON) Reference clock is driven out on REFO6 pin  */
#define   CRU_REFO6CON_OE_NO_REFO6_OE_Val     _UINT32_(0x0)                                        /* (CRU_REFO6CON) Reference clock is not driven out on REFO6 pin.  */
#define CRU_REFO6CON_OE_REFO6_OE              (CRU_REFO6CON_OE_REFO6_OE_Val << CRU_REFO6CON_OE_Pos) /* (CRU_REFO6CON) Reference clock is driven out on REFO6 pin Position  */
#define CRU_REFO6CON_OE_NO_REFO6_OE           (CRU_REFO6CON_OE_NO_REFO6_OE_Val << CRU_REFO6CON_OE_Pos) /* (CRU_REFO6CON) Reference clock is not driven out on REFO6 pin. Position  */
#define CRU_REFO6CON_SIDL_Pos                 _UINT32_(13)                                         /* (CRU_REFO6CON) Peripheral Stop in Idle Mode bit Position */
#define CRU_REFO6CON_SIDL_Msk                 (_UINT32_(0x1) << CRU_REFO6CON_SIDL_Pos)             /* (CRU_REFO6CON) Peripheral Stop in Idle Mode bit Mask */
#define CRU_REFO6CON_SIDL(value)              (CRU_REFO6CON_SIDL_Msk & (_UINT32_(value) << CRU_REFO6CON_SIDL_Pos)) /* Assigment of value for SIDL in the CRU_REFO6CON register */
#define   CRU_REFO6CON_SIDL_SIDL_Val          _UINT32_(0x1)                                        /* (CRU_REFO6CON) Discontinue module operation when device enters Idle mode  */
#define   CRU_REFO6CON_SIDL_NO_SIDL_Val       _UINT32_(0x0)                                        /* (CRU_REFO6CON) Continue module operation in Idle mode  */
#define CRU_REFO6CON_SIDL_SIDL                (CRU_REFO6CON_SIDL_SIDL_Val << CRU_REFO6CON_SIDL_Pos) /* (CRU_REFO6CON) Discontinue module operation when device enters Idle mode Position  */
#define CRU_REFO6CON_SIDL_NO_SIDL             (CRU_REFO6CON_SIDL_NO_SIDL_Val << CRU_REFO6CON_SIDL_Pos) /* (CRU_REFO6CON) Continue module operation in Idle mode Position  */
#define CRU_REFO6CON_FRZ_Pos                  _UINT32_(14)                                         /* (CRU_REFO6CON) Freeze in Debug mode bit Position */
#define CRU_REFO6CON_FRZ_Msk                  (_UINT32_(0x1) << CRU_REFO6CON_FRZ_Pos)              /* (CRU_REFO6CON) Freeze in Debug mode bit Mask */
#define CRU_REFO6CON_FRZ(value)               (CRU_REFO6CON_FRZ_Msk & (_UINT32_(value) << CRU_REFO6CON_FRZ_Pos)) /* Assigment of value for FRZ in the CRU_REFO6CON register */
#define   CRU_REFO6CON_FRZ_FRZ_Val            _UINT32_(0x1)                                        /* (CRU_REFO6CON) When emulator is in Debug mode, module freezes operation  */
#define   CRU_REFO6CON_FRZ_NO_FRZ_Val         _UINT32_(0x0)                                        /* (CRU_REFO6CON) When emulator is in Debug mode, module continues operation  */
#define CRU_REFO6CON_FRZ_FRZ                  (CRU_REFO6CON_FRZ_FRZ_Val << CRU_REFO6CON_FRZ_Pos)   /* (CRU_REFO6CON) When emulator is in Debug mode, module freezes operation Position  */
#define CRU_REFO6CON_FRZ_NO_FRZ               (CRU_REFO6CON_FRZ_NO_FRZ_Val << CRU_REFO6CON_FRZ_Pos) /* (CRU_REFO6CON) When emulator is in Debug mode, module continues operation Position  */
#define CRU_REFO6CON_ON_Pos                   _UINT32_(15)                                         /* (CRU_REFO6CON) Output Enable bit Position */
#define CRU_REFO6CON_ON_Msk                   (_UINT32_(0x1) << CRU_REFO6CON_ON_Pos)               /* (CRU_REFO6CON) Output Enable bit Mask */
#define CRU_REFO6CON_ON(value)                (CRU_REFO6CON_ON_Msk & (_UINT32_(value) << CRU_REFO6CON_ON_Pos)) /* Assigment of value for ON in the CRU_REFO6CON register */
#define   CRU_REFO6CON_ON_ON_Val              _UINT32_(0x1)                                        /* (CRU_REFO6CON) Reference Oscillator Module enabled  */
#define   CRU_REFO6CON_ON_OFF_Val             _UINT32_(0x0)                                        /* (CRU_REFO6CON) Reference Oscillator Module disabled  */
#define CRU_REFO6CON_ON_ON                    (CRU_REFO6CON_ON_ON_Val << CRU_REFO6CON_ON_Pos)      /* (CRU_REFO6CON) Reference Oscillator Module enabled Position  */
#define CRU_REFO6CON_ON_OFF                   (CRU_REFO6CON_ON_OFF_Val << CRU_REFO6CON_ON_Pos)     /* (CRU_REFO6CON) Reference Oscillator Module disabled Position  */
#define CRU_REFO6CON_RODIV_Pos                _UINT32_(16)                                         /* (CRU_REFO6CON) Reference Clock Divider bits Position */
#define CRU_REFO6CON_RODIV_Msk                (_UINT32_(0x7FFF) << CRU_REFO6CON_RODIV_Pos)         /* (CRU_REFO6CON) Reference Clock Divider bits Mask */
#define CRU_REFO6CON_RODIV(value)             (CRU_REFO6CON_RODIV_Msk & (_UINT32_(value) << CRU_REFO6CON_RODIV_Pos)) /* Assigment of value for RODIV in the CRU_REFO6CON register */
#define   CRU_REFO6CON_RODIV_65K_Val          _UINT32_(0x7FFF)                                     /* (CRU_REFO6CON) REFO6 clock is Base clock frequency divided by 65,534 (32,767 *2)  */
#define   CRU_REFO6CON_RODIV_4_Val            _UINT32_(0x2)                                        /* (CRU_REFO6CON) REFO6 clock is Base clock frequency divided by 4 (2*2)  */
#define   CRU_REFO6CON_RODIV_2_Val            _UINT32_(0x1)                                        /* (CRU_REFO6CON) REFO6 clock is Base clock frequency divided by 2 (1*2)  */
#define   CRU_REFO6CON_RODIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_REFO6CON) REFO6 clock is same frequency as Base clock (no divider)  */
#define CRU_REFO6CON_RODIV_65K                (CRU_REFO6CON_RODIV_65K_Val << CRU_REFO6CON_RODIV_Pos) /* (CRU_REFO6CON) REFO6 clock is Base clock frequency divided by 65,534 (32,767 *2) Position  */
#define CRU_REFO6CON_RODIV_4                  (CRU_REFO6CON_RODIV_4_Val << CRU_REFO6CON_RODIV_Pos) /* (CRU_REFO6CON) REFO6 clock is Base clock frequency divided by 4 (2*2) Position  */
#define CRU_REFO6CON_RODIV_2                  (CRU_REFO6CON_RODIV_2_Val << CRU_REFO6CON_RODIV_Pos) /* (CRU_REFO6CON) REFO6 clock is Base clock frequency divided by 2 (1*2) Position  */
#define CRU_REFO6CON_RODIV_NONE               (CRU_REFO6CON_RODIV_NONE_Val << CRU_REFO6CON_RODIV_Pos) /* (CRU_REFO6CON) REFO6 clock is same frequency as Base clock (no divider) Position  */
#define CRU_REFO6CON_Msk                      _UINT32_(0x7FFFFB0F)                                 /* (CRU_REFO6CON) Register Mask  */


/* -------- CRU_REFO6CONCLR : (CRU Offset: 0x114) (R/W 32)  -------- */
#define CRU_REFO6CONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO6CONCLR)   Reset Value */

#define CRU_REFO6CONCLR_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO6CONCLR) Register Mask  */


/* -------- CRU_REFO6CONSET : (CRU Offset: 0x118) (R/W 32)  -------- */
#define CRU_REFO6CONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO6CONSET)   Reset Value */

#define CRU_REFO6CONSET_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO6CONSET) Register Mask  */


/* -------- CRU_REFO6CONINV : (CRU Offset: 0x11C) (R/W 32)  -------- */
#define CRU_REFO6CONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (CRU_REFO6CONINV)   Reset Value */

#define CRU_REFO6CONINV_Msk                   _UINT32_(0x00000000)                                 /* (CRU_REFO6CONINV) Register Mask  */


/* -------- CRU_REFO6TRIM : (CRU Offset: 0x120) (R/W 32) REFERENCE OSCILLATOR 6 TRIM REGISTER -------- */
#define CRU_REFO6TRIM_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_REFO6TRIM) REFERENCE OSCILLATOR 6 TRIM REGISTER  Reset Value */

#define CRU_REFO6TRIM_ROTRIM_Pos              _UINT32_(23)                                         /* (CRU_REFO6TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Position */
#define CRU_REFO6TRIM_ROTRIM_Msk              (_UINT32_(0x1FF) << CRU_REFO6TRIM_ROTRIM_Pos)        /* (CRU_REFO6TRIM) Trim bits - Provides fractional additive to RODIV value for 1/2 period of REFO1 clock Mask */
#define CRU_REFO6TRIM_ROTRIM(value)           (CRU_REFO6TRIM_ROTRIM_Msk & (_UINT32_(value) << CRU_REFO6TRIM_ROTRIM_Pos)) /* Assigment of value for ROTRIM in the CRU_REFO6TRIM register */
#define   CRU_REFO6TRIM_ROTRIM_ZERO_Val       _UINT32_(0x0)                                        /* (CRU_REFO6TRIM) 0/512 (0.0) divisor added to RODIV value  */
#define   CRU_REFO6TRIM_ROTRIM_1_Val          _UINT32_(0x1)                                        /* (CRU_REFO6TRIM) 1/512 (0.001953125) divisor added to RODIV value  */
#define   CRU_REFO6TRIM_ROTRIM_2_Val          _UINT32_(0x2)                                        /* (CRU_REFO6TRIM) 2/512 (0.00390625) divisor added to RODIV value  */
#define   CRU_REFO6TRIM_ROTRIM_256_Val        _UINT32_(0x100)                                      /* (CRU_REFO6TRIM) 256/512 (0.5000) divisor added to RODIV value  */
#define   CRU_REFO6TRIM_ROTRIM_511_Val        _UINT32_(0x1FF)                                      /* (CRU_REFO6TRIM) 511/512 (0.998046875) divisor added to RODIV value  */
#define CRU_REFO6TRIM_ROTRIM_ZERO             (CRU_REFO6TRIM_ROTRIM_ZERO_Val << CRU_REFO6TRIM_ROTRIM_Pos) /* (CRU_REFO6TRIM) 0/512 (0.0) divisor added to RODIV value Position  */
#define CRU_REFO6TRIM_ROTRIM_1                (CRU_REFO6TRIM_ROTRIM_1_Val << CRU_REFO6TRIM_ROTRIM_Pos) /* (CRU_REFO6TRIM) 1/512 (0.001953125) divisor added to RODIV value Position  */
#define CRU_REFO6TRIM_ROTRIM_2                (CRU_REFO6TRIM_ROTRIM_2_Val << CRU_REFO6TRIM_ROTRIM_Pos) /* (CRU_REFO6TRIM) 2/512 (0.00390625) divisor added to RODIV value Position  */
#define CRU_REFO6TRIM_ROTRIM_256              (CRU_REFO6TRIM_ROTRIM_256_Val << CRU_REFO6TRIM_ROTRIM_Pos) /* (CRU_REFO6TRIM) 256/512 (0.5000) divisor added to RODIV value Position  */
#define CRU_REFO6TRIM_ROTRIM_511              (CRU_REFO6TRIM_ROTRIM_511_Val << CRU_REFO6TRIM_ROTRIM_Pos) /* (CRU_REFO6TRIM) 511/512 (0.998046875) divisor added to RODIV value Position  */
#define CRU_REFO6TRIM_Msk                     _UINT32_(0xFF800000)                                 /* (CRU_REFO6TRIM) Register Mask  */


/* -------- CRU_REFO6TRIMCLR : (CRU Offset: 0x124) (R/W 32)  -------- */
#define CRU_REFO6TRIMCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO6TRIMCLR)   Reset Value */

#define CRU_REFO6TRIMCLR_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO6TRIMCLR) Register Mask  */


/* -------- CRU_REFO6TRIMSET : (CRU Offset: 0x128) (R/W 32)  -------- */
#define CRU_REFO6TRIMSET_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO6TRIMSET)   Reset Value */

#define CRU_REFO6TRIMSET_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO6TRIMSET) Register Mask  */


/* -------- CRU_REFO6TRIMINV : (CRU Offset: 0x12C) (R/W 32)  -------- */
#define CRU_REFO6TRIMINV_RESETVALUE           _UINT32_(0x00)                                       /*  (CRU_REFO6TRIMINV)   Reset Value */

#define CRU_REFO6TRIMINV_Msk                  _UINT32_(0x00000000)                                 /* (CRU_REFO6TRIMINV) Register Mask  */


/* -------- CRU_PB1DIV : (CRU Offset: 0x130) (R/W 32) PB1 CLOCK DIVISOR CONTROL REGISTER -------- */
#define CRU_PB1DIV_RESETVALUE                 _UINT32_(0x8801)                                     /*  (CRU_PB1DIV) PB1 CLOCK DIVISOR CONTROL REGISTER  Reset Value */

#define CRU_PB1DIV_PBDIV_Pos                  _UINT32_(0)                                          /* (CRU_PB1DIV) PB1 Peripheral Clock Divisor Control value Position */
#define CRU_PB1DIV_PBDIV_Msk                  (_UINT32_(0x7F) << CRU_PB1DIV_PBDIV_Pos)             /* (CRU_PB1DIV) PB1 Peripheral Clock Divisor Control value Mask */
#define CRU_PB1DIV_PBDIV(value)               (CRU_PB1DIV_PBDIV_Msk & (_UINT32_(value) << CRU_PB1DIV_PBDIV_Pos)) /* Assigment of value for PBDIV in the CRU_PB1DIV register */
#define   CRU_PB1DIV_PBDIV_DIV1_Val           _UINT32_(0x0)                                        /* (CRU_PB1DIV) Divide by 1 PB1 Clock same frequency as sys_clk  */
#define   CRU_PB1DIV_PBDIV_DIV2_Val           _UINT32_(0x1)                                        /* (CRU_PB1DIV) Divide by 2 PB1 Clock is 1/2 of sys_clk  */
#define   CRU_PB1DIV_PBDIV_DIV3_Val           _UINT32_(0x2)                                        /* (CRU_PB1DIV) Divide by 3 PB1 Clock is 1/3 of sys_clk  */
#define   CRU_PB1DIV_PBDIV_DIV16_Val          _UINT32_(0xF)                                        /* (CRU_PB1DIV) Divide by 16 PB1 Clock is 1/16 of sys_clk  */
#define   CRU_PB1DIV_PBDIV_DIV17_Val          _UINT32_(0x10)                                       /* (CRU_PB1DIV) Divide by 17 PB1 Clock is 1/17 of sys_clk  */
#define   CRU_PB1DIV_PBDIV_DIV127_Val         _UINT32_(0x7E)                                       /* (CRU_PB1DIV) Divide by 127 PB1 Clock is 1/127 of sys_clk  */
#define   CRU_PB1DIV_PBDIV_DIV128_Val         _UINT32_(0x7F)                                       /* (CRU_PB1DIV) Divide by 128 PB1 Clock is 1/128 of sys_clk  */
#define CRU_PB1DIV_PBDIV_DIV1                 (CRU_PB1DIV_PBDIV_DIV1_Val << CRU_PB1DIV_PBDIV_Pos)  /* (CRU_PB1DIV) Divide by 1 PB1 Clock same frequency as sys_clk Position  */
#define CRU_PB1DIV_PBDIV_DIV2                 (CRU_PB1DIV_PBDIV_DIV2_Val << CRU_PB1DIV_PBDIV_Pos)  /* (CRU_PB1DIV) Divide by 2 PB1 Clock is 1/2 of sys_clk Position  */
#define CRU_PB1DIV_PBDIV_DIV3                 (CRU_PB1DIV_PBDIV_DIV3_Val << CRU_PB1DIV_PBDIV_Pos)  /* (CRU_PB1DIV) Divide by 3 PB1 Clock is 1/3 of sys_clk Position  */
#define CRU_PB1DIV_PBDIV_DIV16                (CRU_PB1DIV_PBDIV_DIV16_Val << CRU_PB1DIV_PBDIV_Pos) /* (CRU_PB1DIV) Divide by 16 PB1 Clock is 1/16 of sys_clk Position  */
#define CRU_PB1DIV_PBDIV_DIV17                (CRU_PB1DIV_PBDIV_DIV17_Val << CRU_PB1DIV_PBDIV_Pos) /* (CRU_PB1DIV) Divide by 17 PB1 Clock is 1/17 of sys_clk Position  */
#define CRU_PB1DIV_PBDIV_DIV127               (CRU_PB1DIV_PBDIV_DIV127_Val << CRU_PB1DIV_PBDIV_Pos) /* (CRU_PB1DIV) Divide by 127 PB1 Clock is 1/127 of sys_clk Position  */
#define CRU_PB1DIV_PBDIV_DIV128               (CRU_PB1DIV_PBDIV_DIV128_Val << CRU_PB1DIV_PBDIV_Pos) /* (CRU_PB1DIV) Divide by 128 PB1 Clock is 1/128 of sys_clk Position  */
#define CRU_PB1DIV_PBDIVRDY_Pos               _UINT32_(11)                                         /* (CRU_PB1DIV) PB1 Peripheral Clock Divisor Ready Position */
#define CRU_PB1DIV_PBDIVRDY_Msk               (_UINT32_(0x1) << CRU_PB1DIV_PBDIVRDY_Pos)           /* (CRU_PB1DIV) PB1 Peripheral Clock Divisor Ready Mask */
#define CRU_PB1DIV_PBDIVRDY(value)            (CRU_PB1DIV_PBDIVRDY_Msk & (_UINT32_(value) << CRU_PB1DIV_PBDIVRDY_Pos)) /* Assigment of value for PBDIVRDY in the CRU_PB1DIV register */
#define   CRU_PB1DIV_PBDIVRDY_PB1RDY_Val      _UINT32_(0x1)                                        /* (CRU_PB1DIV) Indicates the PB clock divisor logic is not switching divisors and the PB1DIV may be written.  */
#define   CRU_PB1DIV_PBDIVRDY_NOT_PB1RDY_Val  _UINT32_(0x0)                                        /* (CRU_PB1DIV) Indicates the PB clock divisor logic is currently switching values and the PB1DIV cannot be written.  */
#define CRU_PB1DIV_PBDIVRDY_PB1RDY            (CRU_PB1DIV_PBDIVRDY_PB1RDY_Val << CRU_PB1DIV_PBDIVRDY_Pos) /* (CRU_PB1DIV) Indicates the PB clock divisor logic is not switching divisors and the PB1DIV may be written. Position  */
#define CRU_PB1DIV_PBDIVRDY_NOT_PB1RDY        (CRU_PB1DIV_PBDIVRDY_NOT_PB1RDY_Val << CRU_PB1DIV_PBDIVRDY_Pos) /* (CRU_PB1DIV) Indicates the PB clock divisor logic is currently switching values and the PB1DIV cannot be written. Position  */
#define CRU_PB1DIV_PBDIVON_Pos                _UINT32_(15)                                         /* (CRU_PB1DIV) Output Enable bit Position */
#define CRU_PB1DIV_PBDIVON_Msk                (_UINT32_(0x1) << CRU_PB1DIV_PBDIVON_Pos)            /* (CRU_PB1DIV) Output Enable bit Mask */
#define CRU_PB1DIV_PBDIVON(value)             (CRU_PB1DIV_PBDIVON_Msk & (_UINT32_(value) << CRU_PB1DIV_PBDIVON_Pos)) /* Assigment of value for PBDIVON in the CRU_PB1DIV register */
#define   CRU_PB1DIV_PBDIVON_PB1ON_Val        _UINT32_(0x1)                                        /* (CRU_PB1DIV) PB1 Output clock is enabled  */
#define   CRU_PB1DIV_PBDIVON_PB1OFF_Val       _UINT32_(0x0)                                        /* (CRU_PB1DIV) PB1 Output clock is disabled  */
#define CRU_PB1DIV_PBDIVON_PB1ON              (CRU_PB1DIV_PBDIVON_PB1ON_Val << CRU_PB1DIV_PBDIVON_Pos) /* (CRU_PB1DIV) PB1 Output clock is enabled Position  */
#define CRU_PB1DIV_PBDIVON_PB1OFF             (CRU_PB1DIV_PBDIVON_PB1OFF_Val << CRU_PB1DIV_PBDIVON_Pos) /* (CRU_PB1DIV) PB1 Output clock is disabled Position  */
#define CRU_PB1DIV_Msk                        _UINT32_(0x0000887F)                                 /* (CRU_PB1DIV) Register Mask  */


/* -------- CRU_PB1DIVCLR : (CRU Offset: 0x134) (R/W 32)  -------- */
#define CRU_PB1DIVCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB1DIVCLR)   Reset Value */

#define CRU_PB1DIVCLR_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB1DIVCLR) Register Mask  */


/* -------- CRU_PB1DIVSET : (CRU Offset: 0x138) (R/W 32)  -------- */
#define CRU_PB1DIVSET_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB1DIVSET)   Reset Value */

#define CRU_PB1DIVSET_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB1DIVSET) Register Mask  */


/* -------- CRU_PB1DIVINV : (CRU Offset: 0x13C) (R/W 32)  -------- */
#define CRU_PB1DIVINV_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB1DIVINV)   Reset Value */

#define CRU_PB1DIVINV_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB1DIVINV) Register Mask  */


/* -------- CRU_PB2DIV : (CRU Offset: 0x140) (R/W 32) PB2 CLOCK DIVISOR CONTROL REGISTER -------- */
#define CRU_PB2DIV_RESETVALUE                 _UINT32_(0x8801)                                     /*  (CRU_PB2DIV) PB2 CLOCK DIVISOR CONTROL REGISTER  Reset Value */

#define CRU_PB2DIV_PBDIV_Pos                  _UINT32_(0)                                          /* (CRU_PB2DIV) PB2 Peripheral Clock Divisor Control value Position */
#define CRU_PB2DIV_PBDIV_Msk                  (_UINT32_(0x7F) << CRU_PB2DIV_PBDIV_Pos)             /* (CRU_PB2DIV) PB2 Peripheral Clock Divisor Control value Mask */
#define CRU_PB2DIV_PBDIV(value)               (CRU_PB2DIV_PBDIV_Msk & (_UINT32_(value) << CRU_PB2DIV_PBDIV_Pos)) /* Assigment of value for PBDIV in the CRU_PB2DIV register */
#define   CRU_PB2DIV_PBDIV_DIV1_Val           _UINT32_(0x0)                                        /* (CRU_PB2DIV) Divide by 1 PB2 Clock same frequency as sys_clk  */
#define   CRU_PB2DIV_PBDIV_DIV2_Val           _UINT32_(0x1)                                        /* (CRU_PB2DIV) Divide by 2 PB2 Clock is 1/2 of sys_clk  */
#define   CRU_PB2DIV_PBDIV_DIV3_Val           _UINT32_(0x2)                                        /* (CRU_PB2DIV) Divide by 3 PB2 Clock is 1/3 of sys_clk  */
#define   CRU_PB2DIV_PBDIV_DIV16_Val          _UINT32_(0xF)                                        /* (CRU_PB2DIV) Divide by 16 PB2 Clock is 1/16 of sys_clk  */
#define   CRU_PB2DIV_PBDIV_DIV17_Val          _UINT32_(0x10)                                       /* (CRU_PB2DIV) Divide by 17 PB2 Clock is 1/17 of sys_clk  */
#define   CRU_PB2DIV_PBDIV_DIV127_Val         _UINT32_(0x7E)                                       /* (CRU_PB2DIV) Divide by 127 PB2 Clock is 1/127 of sys_clk  */
#define   CRU_PB2DIV_PBDIV_DIV128_Val         _UINT32_(0x7F)                                       /* (CRU_PB2DIV) Divide by 128 PB2 Clock is 1/128 of sys_clk  */
#define CRU_PB2DIV_PBDIV_DIV1                 (CRU_PB2DIV_PBDIV_DIV1_Val << CRU_PB2DIV_PBDIV_Pos)  /* (CRU_PB2DIV) Divide by 1 PB2 Clock same frequency as sys_clk Position  */
#define CRU_PB2DIV_PBDIV_DIV2                 (CRU_PB2DIV_PBDIV_DIV2_Val << CRU_PB2DIV_PBDIV_Pos)  /* (CRU_PB2DIV) Divide by 2 PB2 Clock is 1/2 of sys_clk Position  */
#define CRU_PB2DIV_PBDIV_DIV3                 (CRU_PB2DIV_PBDIV_DIV3_Val << CRU_PB2DIV_PBDIV_Pos)  /* (CRU_PB2DIV) Divide by 3 PB2 Clock is 1/3 of sys_clk Position  */
#define CRU_PB2DIV_PBDIV_DIV16                (CRU_PB2DIV_PBDIV_DIV16_Val << CRU_PB2DIV_PBDIV_Pos) /* (CRU_PB2DIV) Divide by 16 PB2 Clock is 1/16 of sys_clk Position  */
#define CRU_PB2DIV_PBDIV_DIV17                (CRU_PB2DIV_PBDIV_DIV17_Val << CRU_PB2DIV_PBDIV_Pos) /* (CRU_PB2DIV) Divide by 17 PB2 Clock is 1/17 of sys_clk Position  */
#define CRU_PB2DIV_PBDIV_DIV127               (CRU_PB2DIV_PBDIV_DIV127_Val << CRU_PB2DIV_PBDIV_Pos) /* (CRU_PB2DIV) Divide by 127 PB2 Clock is 1/127 of sys_clk Position  */
#define CRU_PB2DIV_PBDIV_DIV128               (CRU_PB2DIV_PBDIV_DIV128_Val << CRU_PB2DIV_PBDIV_Pos) /* (CRU_PB2DIV) Divide by 128 PB2 Clock is 1/128 of sys_clk Position  */
#define CRU_PB2DIV_PBDIVRDY_Pos               _UINT32_(11)                                         /* (CRU_PB2DIV) PB2 Peripheral Clock Divisor Ready Position */
#define CRU_PB2DIV_PBDIVRDY_Msk               (_UINT32_(0x1) << CRU_PB2DIV_PBDIVRDY_Pos)           /* (CRU_PB2DIV) PB2 Peripheral Clock Divisor Ready Mask */
#define CRU_PB2DIV_PBDIVRDY(value)            (CRU_PB2DIV_PBDIVRDY_Msk & (_UINT32_(value) << CRU_PB2DIV_PBDIVRDY_Pos)) /* Assigment of value for PBDIVRDY in the CRU_PB2DIV register */
#define   CRU_PB2DIV_PBDIVRDY_PB2RDY_Val      _UINT32_(0x1)                                        /* (CRU_PB2DIV) Indicates the PB clock divisor logic is not switching divisors and the PB2DIV may be written.  */
#define   CRU_PB2DIV_PBDIVRDY_NOT_PB2RDY_Val  _UINT32_(0x0)                                        /* (CRU_PB2DIV) Indicates the PB clock divisor logic is currently switching values and the PB2DIV cannot be written.  */
#define CRU_PB2DIV_PBDIVRDY_PB2RDY            (CRU_PB2DIV_PBDIVRDY_PB2RDY_Val << CRU_PB2DIV_PBDIVRDY_Pos) /* (CRU_PB2DIV) Indicates the PB clock divisor logic is not switching divisors and the PB2DIV may be written. Position  */
#define CRU_PB2DIV_PBDIVRDY_NOT_PB2RDY        (CRU_PB2DIV_PBDIVRDY_NOT_PB2RDY_Val << CRU_PB2DIV_PBDIVRDY_Pos) /* (CRU_PB2DIV) Indicates the PB clock divisor logic is currently switching values and the PB2DIV cannot be written. Position  */
#define CRU_PB2DIV_PBDIVON_Pos                _UINT32_(15)                                         /* (CRU_PB2DIV) Output Enable bit Position */
#define CRU_PB2DIV_PBDIVON_Msk                (_UINT32_(0x1) << CRU_PB2DIV_PBDIVON_Pos)            /* (CRU_PB2DIV) Output Enable bit Mask */
#define CRU_PB2DIV_PBDIVON(value)             (CRU_PB2DIV_PBDIVON_Msk & (_UINT32_(value) << CRU_PB2DIV_PBDIVON_Pos)) /* Assigment of value for PBDIVON in the CRU_PB2DIV register */
#define   CRU_PB2DIV_PBDIVON_PB2ON_Val        _UINT32_(0x1)                                        /* (CRU_PB2DIV) PB2 Output clock is enabled  */
#define   CRU_PB2DIV_PBDIVON_PB2OFF_Val       _UINT32_(0x0)                                        /* (CRU_PB2DIV) PB2 Output clock is disabled  */
#define CRU_PB2DIV_PBDIVON_PB2ON              (CRU_PB2DIV_PBDIVON_PB2ON_Val << CRU_PB2DIV_PBDIVON_Pos) /* (CRU_PB2DIV) PB2 Output clock is enabled Position  */
#define CRU_PB2DIV_PBDIVON_PB2OFF             (CRU_PB2DIV_PBDIVON_PB2OFF_Val << CRU_PB2DIV_PBDIVON_Pos) /* (CRU_PB2DIV) PB2 Output clock is disabled Position  */
#define CRU_PB2DIV_Msk                        _UINT32_(0x0000887F)                                 /* (CRU_PB2DIV) Register Mask  */


/* -------- CRU_PB2DIVCLR : (CRU Offset: 0x144) (R/W 32)  -------- */
#define CRU_PB2DIVCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB2DIVCLR)   Reset Value */

#define CRU_PB2DIVCLR_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB2DIVCLR) Register Mask  */


/* -------- CRU_PB2DIVSET : (CRU Offset: 0x148) (R/W 32)  -------- */
#define CRU_PB2DIVSET_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB2DIVSET)   Reset Value */

#define CRU_PB2DIVSET_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB2DIVSET) Register Mask  */


/* -------- CRU_PB2DIVINV : (CRU Offset: 0x14C) (R/W 32)  -------- */
#define CRU_PB2DIVINV_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB2DIVINV)   Reset Value */

#define CRU_PB2DIVINV_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB2DIVINV) Register Mask  */


/* -------- CRU_PB3DIV : (CRU Offset: 0x150) (R/W 32) PB3 CLOCK DIVISOR CONTROL REGISTER -------- */
#define CRU_PB3DIV_RESETVALUE                 _UINT32_(0x8801)                                     /*  (CRU_PB3DIV) PB3 CLOCK DIVISOR CONTROL REGISTER  Reset Value */

#define CRU_PB3DIV_PBDIV_Pos                  _UINT32_(0)                                          /* (CRU_PB3DIV) PB3 Peripheral Clock Divisor Control value Position */
#define CRU_PB3DIV_PBDIV_Msk                  (_UINT32_(0x7F) << CRU_PB3DIV_PBDIV_Pos)             /* (CRU_PB3DIV) PB3 Peripheral Clock Divisor Control value Mask */
#define CRU_PB3DIV_PBDIV(value)               (CRU_PB3DIV_PBDIV_Msk & (_UINT32_(value) << CRU_PB3DIV_PBDIV_Pos)) /* Assigment of value for PBDIV in the CRU_PB3DIV register */
#define   CRU_PB3DIV_PBDIV_DIV1_Val           _UINT32_(0x0)                                        /* (CRU_PB3DIV) Divide by 1 PB3 Clock same frequency as sys_clk  */
#define   CRU_PB3DIV_PBDIV_DIV2_Val           _UINT32_(0x1)                                        /* (CRU_PB3DIV) Divide by 2 PB3 Clock is 1/2 of sys_clk  */
#define   CRU_PB3DIV_PBDIV_DIV3_Val           _UINT32_(0x2)                                        /* (CRU_PB3DIV) Divide by 3 PB3 Clock is 1/3 of sys_clk  */
#define   CRU_PB3DIV_PBDIV_DIV16_Val          _UINT32_(0xF)                                        /* (CRU_PB3DIV) Divide by 16 PB3 Clock is 1/16 of sys_clk  */
#define   CRU_PB3DIV_PBDIV_DIV17_Val          _UINT32_(0x10)                                       /* (CRU_PB3DIV) Divide by 17 PB3 Clock is 1/17 of sys_clk  */
#define   CRU_PB3DIV_PBDIV_DIV127_Val         _UINT32_(0x7E)                                       /* (CRU_PB3DIV) Divide by 127 PB3 Clock is 1/127 of sys_clk  */
#define   CRU_PB3DIV_PBDIV_DIV128_Val         _UINT32_(0x7F)                                       /* (CRU_PB3DIV) Divide by 128 PB3 Clock is 1/128 of sys_clk  */
#define CRU_PB3DIV_PBDIV_DIV1                 (CRU_PB3DIV_PBDIV_DIV1_Val << CRU_PB3DIV_PBDIV_Pos)  /* (CRU_PB3DIV) Divide by 1 PB3 Clock same frequency as sys_clk Position  */
#define CRU_PB3DIV_PBDIV_DIV2                 (CRU_PB3DIV_PBDIV_DIV2_Val << CRU_PB3DIV_PBDIV_Pos)  /* (CRU_PB3DIV) Divide by 2 PB3 Clock is 1/2 of sys_clk Position  */
#define CRU_PB3DIV_PBDIV_DIV3                 (CRU_PB3DIV_PBDIV_DIV3_Val << CRU_PB3DIV_PBDIV_Pos)  /* (CRU_PB3DIV) Divide by 3 PB3 Clock is 1/3 of sys_clk Position  */
#define CRU_PB3DIV_PBDIV_DIV16                (CRU_PB3DIV_PBDIV_DIV16_Val << CRU_PB3DIV_PBDIV_Pos) /* (CRU_PB3DIV) Divide by 16 PB3 Clock is 1/16 of sys_clk Position  */
#define CRU_PB3DIV_PBDIV_DIV17                (CRU_PB3DIV_PBDIV_DIV17_Val << CRU_PB3DIV_PBDIV_Pos) /* (CRU_PB3DIV) Divide by 17 PB3 Clock is 1/17 of sys_clk Position  */
#define CRU_PB3DIV_PBDIV_DIV127               (CRU_PB3DIV_PBDIV_DIV127_Val << CRU_PB3DIV_PBDIV_Pos) /* (CRU_PB3DIV) Divide by 127 PB3 Clock is 1/127 of sys_clk Position  */
#define CRU_PB3DIV_PBDIV_DIV128               (CRU_PB3DIV_PBDIV_DIV128_Val << CRU_PB3DIV_PBDIV_Pos) /* (CRU_PB3DIV) Divide by 128 PB3 Clock is 1/128 of sys_clk Position  */
#define CRU_PB3DIV_PBDIVRDY_Pos               _UINT32_(11)                                         /* (CRU_PB3DIV) PB3 Peripheral Clock Divisor Ready Position */
#define CRU_PB3DIV_PBDIVRDY_Msk               (_UINT32_(0x1) << CRU_PB3DIV_PBDIVRDY_Pos)           /* (CRU_PB3DIV) PB3 Peripheral Clock Divisor Ready Mask */
#define CRU_PB3DIV_PBDIVRDY(value)            (CRU_PB3DIV_PBDIVRDY_Msk & (_UINT32_(value) << CRU_PB3DIV_PBDIVRDY_Pos)) /* Assigment of value for PBDIVRDY in the CRU_PB3DIV register */
#define   CRU_PB3DIV_PBDIVRDY_PB3RDY_Val      _UINT32_(0x1)                                        /* (CRU_PB3DIV) Indicates the PB clock divisor logic is not switching divisors and the PB3DIV may be written.  */
#define   CRU_PB3DIV_PBDIVRDY_NOT_PB3RDY_Val  _UINT32_(0x0)                                        /* (CRU_PB3DIV) Indicates the PB clock divisor logic is currently switching values and the PB3DIV cannot be written.  */
#define CRU_PB3DIV_PBDIVRDY_PB3RDY            (CRU_PB3DIV_PBDIVRDY_PB3RDY_Val << CRU_PB3DIV_PBDIVRDY_Pos) /* (CRU_PB3DIV) Indicates the PB clock divisor logic is not switching divisors and the PB3DIV may be written. Position  */
#define CRU_PB3DIV_PBDIVRDY_NOT_PB3RDY        (CRU_PB3DIV_PBDIVRDY_NOT_PB3RDY_Val << CRU_PB3DIV_PBDIVRDY_Pos) /* (CRU_PB3DIV) Indicates the PB clock divisor logic is currently switching values and the PB3DIV cannot be written. Position  */
#define CRU_PB3DIV_PBDIVON_Pos                _UINT32_(15)                                         /* (CRU_PB3DIV) Output Enable bit Position */
#define CRU_PB3DIV_PBDIVON_Msk                (_UINT32_(0x1) << CRU_PB3DIV_PBDIVON_Pos)            /* (CRU_PB3DIV) Output Enable bit Mask */
#define CRU_PB3DIV_PBDIVON(value)             (CRU_PB3DIV_PBDIVON_Msk & (_UINT32_(value) << CRU_PB3DIV_PBDIVON_Pos)) /* Assigment of value for PBDIVON in the CRU_PB3DIV register */
#define   CRU_PB3DIV_PBDIVON_PB3ON_Val        _UINT32_(0x1)                                        /* (CRU_PB3DIV) PB3 Output clock is enabled  */
#define   CRU_PB3DIV_PBDIVON_PB3OFF_Val       _UINT32_(0x0)                                        /* (CRU_PB3DIV) PB3 Output clock is disabled  */
#define CRU_PB3DIV_PBDIVON_PB3ON              (CRU_PB3DIV_PBDIVON_PB3ON_Val << CRU_PB3DIV_PBDIVON_Pos) /* (CRU_PB3DIV) PB3 Output clock is enabled Position  */
#define CRU_PB3DIV_PBDIVON_PB3OFF             (CRU_PB3DIV_PBDIVON_PB3OFF_Val << CRU_PB3DIV_PBDIVON_Pos) /* (CRU_PB3DIV) PB3 Output clock is disabled Position  */
#define CRU_PB3DIV_Msk                        _UINT32_(0x0000887F)                                 /* (CRU_PB3DIV) Register Mask  */


/* -------- CRU_PB3DIVCLR : (CRU Offset: 0x154) (R/W 32)  -------- */
#define CRU_PB3DIVCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB3DIVCLR)   Reset Value */

#define CRU_PB3DIVCLR_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB3DIVCLR) Register Mask  */


/* -------- CRU_PB3DIVSET : (CRU Offset: 0x158) (R/W 32)  -------- */
#define CRU_PB3DIVSET_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB3DIVSET)   Reset Value */

#define CRU_PB3DIVSET_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB3DIVSET) Register Mask  */


/* -------- CRU_PB3DIVINV : (CRU Offset: 0x15C) (R/W 32)  -------- */
#define CRU_PB3DIVINV_RESETVALUE              _UINT32_(0x00)                                       /*  (CRU_PB3DIVINV)   Reset Value */

#define CRU_PB3DIVINV_Msk                     _UINT32_(0x00000000)                                 /* (CRU_PB3DIVINV) Register Mask  */


/* -------- CRU_SLEWCON : (CRU Offset: 0x160) (R/W 32) SLEW RATE CONTROL FOR CLOCK SWITCHING REGISTER -------- */
#define CRU_SLEWCON_RESETVALUE                _UINT32_(0x00)                                       /*  (CRU_SLEWCON) SLEW RATE CONTROL FOR CLOCK SWITCHING REGISTER  Reset Value */

#define CRU_SLEWCON_BUSY_Pos                  _UINT32_(0)                                          /* (CRU_SLEWCON) Clock Switch Slewing Active Status Bit - Read-Only Position */
#define CRU_SLEWCON_BUSY_Msk                  (_UINT32_(0x1) << CRU_SLEWCON_BUSY_Pos)              /* (CRU_SLEWCON) Clock Switch Slewing Active Status Bit - Read-Only Mask */
#define CRU_SLEWCON_BUSY(value)               (CRU_SLEWCON_BUSY_Msk & (_UINT32_(value) << CRU_SLEWCON_BUSY_Pos)) /* Assigment of value for BUSY in the CRU_SLEWCON register */
#define   CRU_SLEWCON_BUSY_FINAL_Val          _UINT32_(0x0)                                        /* (CRU_SLEWCON) Clock Switch has reached its final value  */
#define   CRU_SLEWCON_BUSY_BUSY_Val           _UINT32_(0x1)                                        /* (CRU_SLEWCON) Clock frequency is being actively Slewed  */
#define CRU_SLEWCON_BUSY_FINAL                (CRU_SLEWCON_BUSY_FINAL_Val << CRU_SLEWCON_BUSY_Pos) /* (CRU_SLEWCON) Clock Switch has reached its final value Position  */
#define CRU_SLEWCON_BUSY_BUSY                 (CRU_SLEWCON_BUSY_BUSY_Val << CRU_SLEWCON_BUSY_Pos)  /* (CRU_SLEWCON) Clock frequency is being actively Slewed Position  */
#define CRU_SLEWCON_DNEN_Pos                  _UINT32_(1)                                          /* (CRU_SLEWCON) Clock slew enable for switching down to slower clocks Position */
#define CRU_SLEWCON_DNEN_Msk                  (_UINT32_(0x1) << CRU_SLEWCON_DNEN_Pos)              /* (CRU_SLEWCON) Clock slew enable for switching down to slower clocks Mask */
#define CRU_SLEWCON_DNEN(value)               (CRU_SLEWCON_DNEN_Msk & (_UINT32_(value) << CRU_SLEWCON_DNEN_Pos)) /* Assigment of value for DNEN in the CRU_SLEWCON register */
#define   CRU_SLEWCON_DNEN_DISABLED_Val       _UINT32_(0x0)                                        /* (CRU_SLEWCON) Clock Slewing disabled  */
#define   CRU_SLEWCON_DNEN_ENABLED_Val        _UINT32_(0x1)                                        /* (CRU_SLEWCON) Clock Slewing enabled on a clock switch  */
#define CRU_SLEWCON_DNEN_DISABLED             (CRU_SLEWCON_DNEN_DISABLED_Val << CRU_SLEWCON_DNEN_Pos) /* (CRU_SLEWCON) Clock Slewing disabled Position  */
#define CRU_SLEWCON_DNEN_ENABLED              (CRU_SLEWCON_DNEN_ENABLED_Val << CRU_SLEWCON_DNEN_Pos) /* (CRU_SLEWCON) Clock Slewing enabled on a clock switch Position  */
#define CRU_SLEWCON_UPEN_Pos                  _UINT32_(2)                                          /* (CRU_SLEWCON) Clock slew enable for switching up to faster clocks Position */
#define CRU_SLEWCON_UPEN_Msk                  (_UINT32_(0x1) << CRU_SLEWCON_UPEN_Pos)              /* (CRU_SLEWCON) Clock slew enable for switching up to faster clocks Mask */
#define CRU_SLEWCON_UPEN(value)               (CRU_SLEWCON_UPEN_Msk & (_UINT32_(value) << CRU_SLEWCON_UPEN_Pos)) /* Assigment of value for UPEN in the CRU_SLEWCON register */
#define   CRU_SLEWCON_UPEN_DISABLED_Val       _UINT32_(0x0)                                        /* (CRU_SLEWCON) Clock Slewing disabled  */
#define   CRU_SLEWCON_UPEN_ENABLED_Val        _UINT32_(0x1)                                        /* (CRU_SLEWCON) Clock Slewing enabled on a clock switch OR exit from SLEEP  */
#define CRU_SLEWCON_UPEN_DISABLED             (CRU_SLEWCON_UPEN_DISABLED_Val << CRU_SLEWCON_UPEN_Pos) /* (CRU_SLEWCON) Clock Slewing disabled Position  */
#define CRU_SLEWCON_UPEN_ENABLED              (CRU_SLEWCON_UPEN_ENABLED_Val << CRU_SLEWCON_UPEN_Pos) /* (CRU_SLEWCON) Clock Slewing enabled on a clock switch OR exit from SLEEP Position  */
#define CRU_SLEWCON_SLWDIV_Pos                _UINT32_(8)                                          /* (CRU_SLEWCON) Divisor steps used when doing slewed clock switches Position */
#define CRU_SLEWCON_SLWDIV_Msk                (_UINT32_(0x7) << CRU_SLEWCON_SLWDIV_Pos)            /* (CRU_SLEWCON) Divisor steps used when doing slewed clock switches Mask */
#define CRU_SLEWCON_SLWDIV(value)             (CRU_SLEWCON_SLWDIV_Msk & (_UINT32_(value) << CRU_SLEWCON_SLWDIV_Pos)) /* Assigment of value for SLWDIV in the CRU_SLEWCON register */
#define   CRU_SLEWCON_SLWDIV_NONE_Val         _UINT32_(0x0)                                        /* (CRU_SLEWCON) No Divisor used  */
#define   CRU_SLEWCON_SLWDIV_2_Val            _UINT32_(0x1)                                        /* (CRU_SLEWCON) Divide by 2, then no divisor  */
#define   CRU_SLEWCON_SLWDIV_4to2_Val         _UINT32_(0x2)                                        /* (CRU_SLEWCON) Divide by 4, then by 2, then no divisor  */
#define   CRU_SLEWCON_SLWDIV_8to2_Val         _UINT32_(0x3)                                        /* (CRU_SLEWCON) Divide by 8, then by 4, then by 2, then no divisor  */
#define   CRU_SLEWCON_SLWDIV_16to2_Val        _UINT32_(0x4)                                        /* (CRU_SLEWCON) Divide by 16, then by 8, then by 4, then by 2, then no divisor  */
#define   CRU_SLEWCON_SLWDIV_32to2_Val        _UINT32_(0x5)                                        /* (CRU_SLEWCON) Divide by 32, then by 16, then by 8, then by 4, then by 2, then no divisor  */
#define   CRU_SLEWCON_SLWDIV_64to2_Val        _UINT32_(0x6)                                        /* (CRU_SLEWCON) Divide by 64, then by 32, then by 16, then by 8, then by 4, then by 2, then no divisor  */
#define   CRU_SLEWCON_SLWDIV_128to2_Val       _UINT32_(0x7)                                        /* (CRU_SLEWCON) Divide by 128, then by 64, then by 32, then by 16, then by 8, then by 4, then by 2, then no divisor  */
#define CRU_SLEWCON_SLWDIV_NONE               (CRU_SLEWCON_SLWDIV_NONE_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) No Divisor used Position  */
#define CRU_SLEWCON_SLWDIV_2                  (CRU_SLEWCON_SLWDIV_2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 2, then no divisor Position  */
#define CRU_SLEWCON_SLWDIV_4to2               (CRU_SLEWCON_SLWDIV_4to2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 4, then by 2, then no divisor Position  */
#define CRU_SLEWCON_SLWDIV_8to2               (CRU_SLEWCON_SLWDIV_8to2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 8, then by 4, then by 2, then no divisor Position  */
#define CRU_SLEWCON_SLWDIV_16to2              (CRU_SLEWCON_SLWDIV_16to2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 16, then by 8, then by 4, then by 2, then no divisor Position  */
#define CRU_SLEWCON_SLWDIV_32to2              (CRU_SLEWCON_SLWDIV_32to2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 32, then by 16, then by 8, then by 4, then by 2, then no divisor Position  */
#define CRU_SLEWCON_SLWDIV_64to2              (CRU_SLEWCON_SLWDIV_64to2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 64, then by 32, then by 16, then by 8, then by 4, then by 2, then no divisor Position  */
#define CRU_SLEWCON_SLWDIV_128to2             (CRU_SLEWCON_SLWDIV_128to2_Val << CRU_SLEWCON_SLWDIV_Pos) /* (CRU_SLEWCON) Divide by 128, then by 64, then by 32, then by 16, then by 8, then by 4, then by 2, then no divisor Position  */
#define CRU_SLEWCON_SYSDIV_Pos                _UINT32_(16)                                         /* (CRU_SLEWCON) PBx Peripheral Clock Divisor Control value Position */
#define CRU_SLEWCON_SYSDIV_Msk                (_UINT32_(0xF) << CRU_SLEWCON_SYSDIV_Pos)            /* (CRU_SLEWCON) PBx Peripheral Clock Divisor Control value Mask */
#define CRU_SLEWCON_SYSDIV(value)             (CRU_SLEWCON_SYSDIV_Msk & (_UINT32_(value) << CRU_SLEWCON_SYSDIV_Pos)) /* Assigment of value for SYSDIV in the CRU_SLEWCON register */
#define   CRU_SLEWCON_SYSDIV_DIV1_Val         _UINT32_(0x0)                                        /* (CRU_SLEWCON) Divide by 1- sys_clk_out same frequency as sys_clk source - Default  */
#define   CRU_SLEWCON_SYSDIV_DIV2_Val         _UINT32_(0x1)                                        /* (CRU_SLEWCON) Divide by 2- sys_clk_out is 1/2 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV3_Val         _UINT32_(0x2)                                        /* (CRU_SLEWCON) Divide by 3- sys_clk_out is 1/3 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV4_Val         _UINT32_(0x3)                                        /* (CRU_SLEWCON) Divide by 4- sys_clk_out is 1/4 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV5_Val         _UINT32_(0x4)                                        /* (CRU_SLEWCON) Divide by 5- sys_clk_out is 1/5 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV6_Val         _UINT32_(0x5)                                        /* (CRU_SLEWCON) Divide by 6- sys_clk_out is 1/6 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV7_Val         _UINT32_(0x6)                                        /* (CRU_SLEWCON) Divide by 7- sys_clk_out is 1/7 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV8_Val         _UINT32_(0x7)                                        /* (CRU_SLEWCON) Divide by 8- sys_clk_out is 1/8 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV9_Val         _UINT32_(0x8)                                        /* (CRU_SLEWCON) Divide by 9- sys_clk_out is 1/9 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV10_Val        _UINT32_(0x9)                                        /* (CRU_SLEWCON) Divide by 10- sys_clk_out is 1/10 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV11_Val        _UINT32_(0xA)                                        /* (CRU_SLEWCON) Divide by 11- sys_clk_out is 1/11 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV12_Val        _UINT32_(0xB)                                        /* (CRU_SLEWCON) Divide by 12- sys_clk_out is 1/12 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV13_Val        _UINT32_(0xC)                                        /* (CRU_SLEWCON) Divide by 13- sys_clk_out is 1/13 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV14_Val        _UINT32_(0xD)                                        /* (CRU_SLEWCON) Divide by 14- sys_clk_out is 1/14 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV15_Val        _UINT32_(0xE)                                        /* (CRU_SLEWCON) Divide by 15- sys_clk_out is 1/15 of sys_clk source  */
#define   CRU_SLEWCON_SYSDIV_DIV16_Val        _UINT32_(0xF)                                        /* (CRU_SLEWCON) Divide by 16- sys_clk_out is 1/16 of sys_clk source  */
#define CRU_SLEWCON_SYSDIV_DIV1               (CRU_SLEWCON_SYSDIV_DIV1_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 1- sys_clk_out same frequency as sys_clk source - Default Position  */
#define CRU_SLEWCON_SYSDIV_DIV2               (CRU_SLEWCON_SYSDIV_DIV2_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 2- sys_clk_out is 1/2 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV3               (CRU_SLEWCON_SYSDIV_DIV3_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 3- sys_clk_out is 1/3 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV4               (CRU_SLEWCON_SYSDIV_DIV4_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 4- sys_clk_out is 1/4 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV5               (CRU_SLEWCON_SYSDIV_DIV5_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 5- sys_clk_out is 1/5 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV6               (CRU_SLEWCON_SYSDIV_DIV6_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 6- sys_clk_out is 1/6 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV7               (CRU_SLEWCON_SYSDIV_DIV7_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 7- sys_clk_out is 1/7 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV8               (CRU_SLEWCON_SYSDIV_DIV8_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 8- sys_clk_out is 1/8 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV9               (CRU_SLEWCON_SYSDIV_DIV9_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 9- sys_clk_out is 1/9 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV10              (CRU_SLEWCON_SYSDIV_DIV10_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 10- sys_clk_out is 1/10 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV11              (CRU_SLEWCON_SYSDIV_DIV11_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 11- sys_clk_out is 1/11 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV12              (CRU_SLEWCON_SYSDIV_DIV12_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 12- sys_clk_out is 1/12 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV13              (CRU_SLEWCON_SYSDIV_DIV13_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 13- sys_clk_out is 1/13 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV14              (CRU_SLEWCON_SYSDIV_DIV14_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 14- sys_clk_out is 1/14 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV15              (CRU_SLEWCON_SYSDIV_DIV15_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 15- sys_clk_out is 1/15 of sys_clk source Position  */
#define CRU_SLEWCON_SYSDIV_DIV16              (CRU_SLEWCON_SYSDIV_DIV16_Val << CRU_SLEWCON_SYSDIV_Pos) /* (CRU_SLEWCON) Divide by 16- sys_clk_out is 1/16 of sys_clk source Position  */
#define CRU_SLEWCON_SLWDLY_Pos                _UINT32_(24)                                         /* (CRU_SLEWCON) Number of clocks generated at each slew step for a clock switch Position */
#define CRU_SLEWCON_SLWDLY_Msk                (_UINT32_(0xF) << CRU_SLEWCON_SLWDLY_Pos)            /* (CRU_SLEWCON) Number of clocks generated at each slew step for a clock switch Mask */
#define CRU_SLEWCON_SLWDLY(value)             (CRU_SLEWCON_SLWDLY_Msk & (_UINT32_(value) << CRU_SLEWCON_SLWDLY_Pos)) /* Assigment of value for SLWDLY in the CRU_SLEWCON register */
#define   CRU_SLEWCON_SLWDLY_1_Val            _UINT32_(0x0)                                        /* (CRU_SLEWCON) 1 clock will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_2_Val            _UINT32_(0x1)                                        /* (CRU_SLEWCON) 2 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_3_Val            _UINT32_(0x2)                                        /* (CRU_SLEWCON) 3 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_4_Val            _UINT32_(0x3)                                        /* (CRU_SLEWCON) 4 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_5_Val            _UINT32_(0x4)                                        /* (CRU_SLEWCON) 5 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_6_Val            _UINT32_(0x5)                                        /* (CRU_SLEWCON) 6 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_7_Val            _UINT32_(0x6)                                        /* (CRU_SLEWCON) 7 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_8_Val            _UINT32_(0x7)                                        /* (CRU_SLEWCON) 8 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_9_Val            _UINT32_(0x8)                                        /* (CRU_SLEWCON) 9 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_10_Val           _UINT32_(0x9)                                        /* (CRU_SLEWCON) 10 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_11_Val           _UINT32_(0xA)                                        /* (CRU_SLEWCON) 11 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_12_Val           _UINT32_(0xB)                                        /* (CRU_SLEWCON) 12 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_13_Val           _UINT32_(0xC)                                        /* (CRU_SLEWCON) 13 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_14_Val           _UINT32_(0xD)                                        /* (CRU_SLEWCON) 14 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_15_Val           _UINT32_(0xE)                                        /* (CRU_SLEWCON) 15 clocks will be generated at each slew step  */
#define   CRU_SLEWCON_SLWDLY_16_Val           _UINT32_(0xF)                                        /* (CRU_SLEWCON) 16 clocks will be generated at each slew step  */
#define CRU_SLEWCON_SLWDLY_1                  (CRU_SLEWCON_SLWDLY_1_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 1 clock will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_2                  (CRU_SLEWCON_SLWDLY_2_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 2 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_3                  (CRU_SLEWCON_SLWDLY_3_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 3 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_4                  (CRU_SLEWCON_SLWDLY_4_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 4 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_5                  (CRU_SLEWCON_SLWDLY_5_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 5 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_6                  (CRU_SLEWCON_SLWDLY_6_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 6 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_7                  (CRU_SLEWCON_SLWDLY_7_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 7 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_8                  (CRU_SLEWCON_SLWDLY_8_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 8 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_9                  (CRU_SLEWCON_SLWDLY_9_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 9 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_10                 (CRU_SLEWCON_SLWDLY_10_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 10 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_11                 (CRU_SLEWCON_SLWDLY_11_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 11 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_12                 (CRU_SLEWCON_SLWDLY_12_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 12 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_13                 (CRU_SLEWCON_SLWDLY_13_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 13 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_14                 (CRU_SLEWCON_SLWDLY_14_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 14 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_15                 (CRU_SLEWCON_SLWDLY_15_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 15 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_SLWDLY_16                 (CRU_SLEWCON_SLWDLY_16_Val << CRU_SLEWCON_SLWDLY_Pos) /* (CRU_SLEWCON) 16 clocks will be generated at each slew step Position  */
#define CRU_SLEWCON_Msk                       _UINT32_(0x0F0F0707)                                 /* (CRU_SLEWCON) Register Mask  */


/* -------- CRU_SLEWCONCLR : (CRU Offset: 0x164) (R/W 32)  -------- */
#define CRU_SLEWCONCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (CRU_SLEWCONCLR)   Reset Value */

#define CRU_SLEWCONCLR_Msk                    _UINT32_(0x00000000)                                 /* (CRU_SLEWCONCLR) Register Mask  */


/* -------- CRU_SLEWCONSET : (CRU Offset: 0x168) (R/W 32)  -------- */
#define CRU_SLEWCONSET_RESETVALUE             _UINT32_(0x00)                                       /*  (CRU_SLEWCONSET)   Reset Value */

#define CRU_SLEWCONSET_Msk                    _UINT32_(0x00000000)                                 /* (CRU_SLEWCONSET) Register Mask  */


/* -------- CRU_SLEWCONINV : (CRU Offset: 0x16C) (R/W 32)  -------- */
#define CRU_SLEWCONINV_RESETVALUE             _UINT32_(0x00)                                       /*  (CRU_SLEWCONINV)   Reset Value */

#define CRU_SLEWCONINV_Msk                    _UINT32_(0x00000000)                                 /* (CRU_SLEWCONINV) Register Mask  */


/* -------- CRU_CLKSTAT : (CRU Offset: 0x170) (R/W 32) CLOCK STATUS REGISTER -------- */
#define CRU_CLKSTAT_RESETVALUE                _UINT32_(0x00)                                       /*  (CRU_CLKSTAT) CLOCK STATUS REGISTER  Reset Value */

#define CRU_CLKSTAT_FRCRDY_Pos                _UINT32_(0)                                          /* (CRU_CLKSTAT) FRC Ready Status value Position */
#define CRU_CLKSTAT_FRCRDY_Msk                (_UINT32_(0x1) << CRU_CLKSTAT_FRCRDY_Pos)            /* (CRU_CLKSTAT) FRC Ready Status value Mask */
#define CRU_CLKSTAT_FRCRDY(value)             (CRU_CLKSTAT_FRCRDY_Msk & (_UINT32_(value) << CRU_CLKSTAT_FRCRDY_Pos)) /* Assigment of value for FRCRDY in the CRU_CLKSTAT register */
#define   CRU_CLKSTAT_FRCRDY_NOTRDY_Val       _UINT32_(0x0)                                        /* (CRU_CLKSTAT) FRC is not stable and not ready  */
#define   CRU_CLKSTAT_FRCRDY_RDY_Val          _UINT32_(0x1)                                        /* (CRU_CLKSTAT) FRC is stable and ready  */
#define CRU_CLKSTAT_FRCRDY_NOTRDY             (CRU_CLKSTAT_FRCRDY_NOTRDY_Val << CRU_CLKSTAT_FRCRDY_Pos) /* (CRU_CLKSTAT) FRC is not stable and not ready Position  */
#define CRU_CLKSTAT_FRCRDY_RDY                (CRU_CLKSTAT_FRCRDY_RDY_Val << CRU_CLKSTAT_FRCRDY_Pos) /* (CRU_CLKSTAT) FRC is stable and ready Position  */
#define CRU_CLKSTAT_SPLL1RDY_Pos              _UINT32_(1)                                          /* (CRU_CLKSTAT) System PLL1 Ready Status value Position */
#define CRU_CLKSTAT_SPLL1RDY_Msk              (_UINT32_(0x1) << CRU_CLKSTAT_SPLL1RDY_Pos)          /* (CRU_CLKSTAT) System PLL1 Ready Status value Mask */
#define CRU_CLKSTAT_SPLL1RDY(value)           (CRU_CLKSTAT_SPLL1RDY_Msk & (_UINT32_(value) << CRU_CLKSTAT_SPLL1RDY_Pos)) /* Assigment of value for SPLL1RDY in the CRU_CLKSTAT register */
#define   CRU_CLKSTAT_SPLL1RDY_NOTRDY_Val     _UINT32_(0x0)                                        /* (CRU_CLKSTAT) SPLL1 Primary Output is not stable and not ready  */
#define   CRU_CLKSTAT_SPLL1RDY_RDY_Val        _UINT32_(0x1)                                        /* (CRU_CLKSTAT) SPLL1 Primary Output is stable and ready  */
#define CRU_CLKSTAT_SPLL1RDY_NOTRDY           (CRU_CLKSTAT_SPLL1RDY_NOTRDY_Val << CRU_CLKSTAT_SPLL1RDY_Pos) /* (CRU_CLKSTAT) SPLL1 Primary Output is not stable and not ready Position  */
#define CRU_CLKSTAT_SPLL1RDY_RDY              (CRU_CLKSTAT_SPLL1RDY_RDY_Val << CRU_CLKSTAT_SPLL1RDY_Pos) /* (CRU_CLKSTAT) SPLL1 Primary Output is stable and ready Position  */
#define CRU_CLKSTAT_POSCRDY_Pos               _UINT32_(2)                                          /* (CRU_CLKSTAT) Primary Oscillator Ready Status value Position */
#define CRU_CLKSTAT_POSCRDY_Msk               (_UINT32_(0x1) << CRU_CLKSTAT_POSCRDY_Pos)           /* (CRU_CLKSTAT) Primary Oscillator Ready Status value Mask */
#define CRU_CLKSTAT_POSCRDY(value)            (CRU_CLKSTAT_POSCRDY_Msk & (_UINT32_(value) << CRU_CLKSTAT_POSCRDY_Pos)) /* Assigment of value for POSCRDY in the CRU_CLKSTAT register */
#define   CRU_CLKSTAT_POSCRDY_NOTRDY_Val      _UINT32_(0x0)                                        /* (CRU_CLKSTAT) POSC is not stable and not ready  */
#define   CRU_CLKSTAT_POSCRDY_RDY_Val         _UINT32_(0x1)                                        /* (CRU_CLKSTAT) POSC is stable and ready  */
#define CRU_CLKSTAT_POSCRDY_NOTRDY            (CRU_CLKSTAT_POSCRDY_NOTRDY_Val << CRU_CLKSTAT_POSCRDY_Pos) /* (CRU_CLKSTAT) POSC is not stable and not ready Position  */
#define CRU_CLKSTAT_POSCRDY_RDY               (CRU_CLKSTAT_POSCRDY_RDY_Val << CRU_CLKSTAT_POSCRDY_Pos) /* (CRU_CLKSTAT) POSC is stable and ready Position  */
#define CRU_CLKSTAT_SOSCRDY_Pos               _UINT32_(3)                                          /* (CRU_CLKSTAT) SOSC Ready Status value Position */
#define CRU_CLKSTAT_SOSCRDY_Msk               (_UINT32_(0x1) << CRU_CLKSTAT_SOSCRDY_Pos)           /* (CRU_CLKSTAT) SOSC Ready Status value Mask */
#define CRU_CLKSTAT_SOSCRDY(value)            (CRU_CLKSTAT_SOSCRDY_Msk & (_UINT32_(value) << CRU_CLKSTAT_SOSCRDY_Pos)) /* Assigment of value for SOSCRDY in the CRU_CLKSTAT register */
#define   CRU_CLKSTAT_SOSCRDY_NOTRDY_Val      _UINT32_(0x0)                                        /* (CRU_CLKSTAT) SOSC is not stable and not ready  */
#define   CRU_CLKSTAT_SOSCRDY_RDY_Val         _UINT32_(0x1)                                        /* (CRU_CLKSTAT) SOSC is stable and ready  */
#define CRU_CLKSTAT_SOSCRDY_NOTRDY            (CRU_CLKSTAT_SOSCRDY_NOTRDY_Val << CRU_CLKSTAT_SOSCRDY_Pos) /* (CRU_CLKSTAT) SOSC is not stable and not ready Position  */
#define CRU_CLKSTAT_SOSCRDY_RDY               (CRU_CLKSTAT_SOSCRDY_RDY_Val << CRU_CLKSTAT_SOSCRDY_Pos) /* (CRU_CLKSTAT) SOSC is stable and ready Position  */
#define CRU_CLKSTAT_LPRCRDY_Pos               _UINT32_(5)                                          /* (CRU_CLKSTAT) LPRC Ready Status value Position */
#define CRU_CLKSTAT_LPRCRDY_Msk               (_UINT32_(0x1) << CRU_CLKSTAT_LPRCRDY_Pos)           /* (CRU_CLKSTAT) LPRC Ready Status value Mask */
#define CRU_CLKSTAT_LPRCRDY(value)            (CRU_CLKSTAT_LPRCRDY_Msk & (_UINT32_(value) << CRU_CLKSTAT_LPRCRDY_Pos)) /* Assigment of value for LPRCRDY in the CRU_CLKSTAT register */
#define   CRU_CLKSTAT_LPRCRDY_NOTRDY_Val      _UINT32_(0x0)                                        /* (CRU_CLKSTAT) LPRC is not stable and not ready  */
#define   CRU_CLKSTAT_LPRCRDY_RDY_Val         _UINT32_(0x1)                                        /* (CRU_CLKSTAT) LPRC is stable and ready  */
#define CRU_CLKSTAT_LPRCRDY_NOTRDY            (CRU_CLKSTAT_LPRCRDY_NOTRDY_Val << CRU_CLKSTAT_LPRCRDY_Pos) /* (CRU_CLKSTAT) LPRC is not stable and not ready Position  */
#define CRU_CLKSTAT_LPRCRDY_RDY               (CRU_CLKSTAT_LPRCRDY_RDY_Val << CRU_CLKSTAT_LPRCRDY_Pos) /* (CRU_CLKSTAT) LPRC is stable and ready Position  */
#define CRU_CLKSTAT_SPLL3RDY_Pos              _UINT32_(9)                                          /* (CRU_CLKSTAT) System PLL3 Ready Status value Position */
#define CRU_CLKSTAT_SPLL3RDY_Msk              (_UINT32_(0x1) << CRU_CLKSTAT_SPLL3RDY_Pos)          /* (CRU_CLKSTAT) System PLL3 Ready Status value Mask */
#define CRU_CLKSTAT_SPLL3RDY(value)           (CRU_CLKSTAT_SPLL3RDY_Msk & (_UINT32_(value) << CRU_CLKSTAT_SPLL3RDY_Pos)) /* Assigment of value for SPLL3RDY in the CRU_CLKSTAT register */
#define   CRU_CLKSTAT_SPLL3RDY_NOTRDY_Val     _UINT32_(0x0)                                        /* (CRU_CLKSTAT) SPLL3 Output is not stable and not ready  */
#define   CRU_CLKSTAT_SPLL3RDY_RDY_Val        _UINT32_(0x1)                                        /* (CRU_CLKSTAT) SPLL3 Output is stable and ready  */
#define CRU_CLKSTAT_SPLL3RDY_NOTRDY           (CRU_CLKSTAT_SPLL3RDY_NOTRDY_Val << CRU_CLKSTAT_SPLL3RDY_Pos) /* (CRU_CLKSTAT) SPLL3 Output is not stable and not ready Position  */
#define CRU_CLKSTAT_SPLL3RDY_RDY              (CRU_CLKSTAT_SPLL3RDY_RDY_Val << CRU_CLKSTAT_SPLL3RDY_Pos) /* (CRU_CLKSTAT) SPLL3 Output is stable and ready Position  */
#define CRU_CLKSTAT_Msk                       _UINT32_(0x0000022F)                                 /* (CRU_CLKSTAT) Register Mask  */


/* -------- CRU_CLKDIAG : (CRU Offset: 0x190) (R/W 32) USER CLK DIAGNOSTICS CONTROL REGISTER -------- */
#define CRU_CLKDIAG_RESETVALUE                _UINT32_(0x00)                                       /*  (CRU_CLKDIAG) USER CLK DIAGNOSTICS CONTROL REGISTER  Reset Value */

#define CRU_CLKDIAG_POSCSTOP_Pos              _UINT32_(0)                                          /* (CRU_CLKDIAG) POSC Clock Stop Control value Position */
#define CRU_CLKDIAG_POSCSTOP_Msk              (_UINT32_(0x1) << CRU_CLKDIAG_POSCSTOP_Pos)          /* (CRU_CLKDIAG) POSC Clock Stop Control value Mask */
#define CRU_CLKDIAG_POSCSTOP(value)           (CRU_CLKDIAG_POSCSTOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_POSCSTOP_Pos)) /* Assigment of value for POSCSTOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_POSCSTOP_NORM_Val       _UINT32_(0x0)                                        /* (CRU_CLKDIAG) POSC clock source runs as normal  */
#define   CRU_CLKDIAG_POSCSTOP_STOP_Val       _UINT32_(0x1)                                        /* (CRU_CLKDIAG) POSC clock source is stopped  */
#define CRU_CLKDIAG_POSCSTOP_NORM             (CRU_CLKDIAG_POSCSTOP_NORM_Val << CRU_CLKDIAG_POSCSTOP_Pos) /* (CRU_CLKDIAG) POSC clock source runs as normal Position  */
#define CRU_CLKDIAG_POSCSTOP_STOP             (CRU_CLKDIAG_POSCSTOP_STOP_Val << CRU_CLKDIAG_POSCSTOP_Pos) /* (CRU_CLKDIAG) POSC clock source is stopped Position  */
#define CRU_CLKDIAG_SOSCSTOP_Pos              _UINT32_(1)                                          /* (CRU_CLKDIAG) SOSC Clock Stop Control value Position */
#define CRU_CLKDIAG_SOSCSTOP_Msk              (_UINT32_(0x1) << CRU_CLKDIAG_SOSCSTOP_Pos)          /* (CRU_CLKDIAG) SOSC Clock Stop Control value Mask */
#define CRU_CLKDIAG_SOSCSTOP(value)           (CRU_CLKDIAG_SOSCSTOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_SOSCSTOP_Pos)) /* Assigment of value for SOSCSTOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_SOSCSTOP_NORM_Val       _UINT32_(0x0)                                        /* (CRU_CLKDIAG) SOSC clock source runs as normal  */
#define   CRU_CLKDIAG_SOSCSTOP_STOP_Val       _UINT32_(0x1)                                        /* (CRU_CLKDIAG) SOSC clock source is stopped  */
#define CRU_CLKDIAG_SOSCSTOP_NORM             (CRU_CLKDIAG_SOSCSTOP_NORM_Val << CRU_CLKDIAG_SOSCSTOP_Pos) /* (CRU_CLKDIAG) SOSC clock source runs as normal Position  */
#define CRU_CLKDIAG_SOSCSTOP_STOP             (CRU_CLKDIAG_SOSCSTOP_STOP_Val << CRU_CLKDIAG_SOSCSTOP_Pos) /* (CRU_CLKDIAG) SOSC clock source is stopped Position  */
#define CRU_CLKDIAG_FRCSTOP_Pos               _UINT32_(2)                                          /* (CRU_CLKDIAG) FRC Clock Stop Control value Position */
#define CRU_CLKDIAG_FRCSTOP_Msk               (_UINT32_(0x1) << CRU_CLKDIAG_FRCSTOP_Pos)           /* (CRU_CLKDIAG) FRC Clock Stop Control value Mask */
#define CRU_CLKDIAG_FRCSTOP(value)            (CRU_CLKDIAG_FRCSTOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_FRCSTOP_Pos)) /* Assigment of value for FRCSTOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_FRCSTOP_NORM_Val        _UINT32_(0x0)                                        /* (CRU_CLKDIAG) FRC clock source runs as normal  */
#define   CRU_CLKDIAG_FRCSTOP_STOP_Val        _UINT32_(0x1)                                        /* (CRU_CLKDIAG) FRC clock source is stopped  */
#define CRU_CLKDIAG_FRCSTOP_NORM              (CRU_CLKDIAG_FRCSTOP_NORM_Val << CRU_CLKDIAG_FRCSTOP_Pos) /* (CRU_CLKDIAG) FRC clock source runs as normal Position  */
#define CRU_CLKDIAG_FRCSTOP_STOP              (CRU_CLKDIAG_FRCSTOP_STOP_Val << CRU_CLKDIAG_FRCSTOP_Pos) /* (CRU_CLKDIAG) FRC clock source is stopped Position  */
#define CRU_CLKDIAG_LPRCSTOP_Pos              _UINT32_(3)                                          /* (CRU_CLKDIAG) LPRC Clock Stop Control value Position */
#define CRU_CLKDIAG_LPRCSTOP_Msk              (_UINT32_(0x1) << CRU_CLKDIAG_LPRCSTOP_Pos)          /* (CRU_CLKDIAG) LPRC Clock Stop Control value Mask */
#define CRU_CLKDIAG_LPRCSTOP(value)           (CRU_CLKDIAG_LPRCSTOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_LPRCSTOP_Pos)) /* Assigment of value for LPRCSTOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_LPRCSTOP_NORM_Val       _UINT32_(0x0)                                        /* (CRU_CLKDIAG) LPRC clock source runs as normal  */
#define   CRU_CLKDIAG_LPRCSTOP_STOP_Val       _UINT32_(0x1)                                        /* (CRU_CLKDIAG) LPRC clock source is stopped  */
#define CRU_CLKDIAG_LPRCSTOP_NORM             (CRU_CLKDIAG_LPRCSTOP_NORM_Val << CRU_CLKDIAG_LPRCSTOP_Pos) /* (CRU_CLKDIAG) LPRC clock source runs as normal Position  */
#define CRU_CLKDIAG_LPRCSTOP_STOP             (CRU_CLKDIAG_LPRCSTOP_STOP_Val << CRU_CLKDIAG_LPRCSTOP_Pos) /* (CRU_CLKDIAG) LPRC clock source is stopped Position  */
#define CRU_CLKDIAG_SPLL1STOP_Pos             _UINT32_(4)                                          /* (CRU_CLKDIAG) SPLL1 Clock Stop Control value Position */
#define CRU_CLKDIAG_SPLL1STOP_Msk             (_UINT32_(0x1) << CRU_CLKDIAG_SPLL1STOP_Pos)         /* (CRU_CLKDIAG) SPLL1 Clock Stop Control value Mask */
#define CRU_CLKDIAG_SPLL1STOP(value)          (CRU_CLKDIAG_SPLL1STOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_SPLL1STOP_Pos)) /* Assigment of value for SPLL1STOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_SPLL1STOP_NORM_Val      _UINT32_(0x0)                                        /* (CRU_CLKDIAG) SPLL1 clock source runs as normal  */
#define   CRU_CLKDIAG_SPLL1STOP_STOP_Val      _UINT32_(0x1)                                        /* (CRU_CLKDIAG) SPLL1 clock source is stopped  */
#define CRU_CLKDIAG_SPLL1STOP_NORM            (CRU_CLKDIAG_SPLL1STOP_NORM_Val << CRU_CLKDIAG_SPLL1STOP_Pos) /* (CRU_CLKDIAG) SPLL1 clock source runs as normal Position  */
#define CRU_CLKDIAG_SPLL1STOP_STOP            (CRU_CLKDIAG_SPLL1STOP_STOP_Val << CRU_CLKDIAG_SPLL1STOP_Pos) /* (CRU_CLKDIAG) SPLL1 clock source is stopped Position  */
#define CRU_CLKDIAG_SPLL2STOP_Pos             _UINT32_(5)                                          /* (CRU_CLKDIAG) SPLL2 Clock Stop Control value Position */
#define CRU_CLKDIAG_SPLL2STOP_Msk             (_UINT32_(0x1) << CRU_CLKDIAG_SPLL2STOP_Pos)         /* (CRU_CLKDIAG) SPLL2 Clock Stop Control value Mask */
#define CRU_CLKDIAG_SPLL2STOP(value)          (CRU_CLKDIAG_SPLL2STOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_SPLL2STOP_Pos)) /* Assigment of value for SPLL2STOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_SPLL2STOP_NORM_Val      _UINT32_(0x0)                                        /* (CRU_CLKDIAG) SPLL2 clock source runs as normal  */
#define   CRU_CLKDIAG_SPLL2STOP_STOP_Val      _UINT32_(0x1)                                        /* (CRU_CLKDIAG) SPLL2 clock source is stopped  */
#define CRU_CLKDIAG_SPLL2STOP_NORM            (CRU_CLKDIAG_SPLL2STOP_NORM_Val << CRU_CLKDIAG_SPLL2STOP_Pos) /* (CRU_CLKDIAG) SPLL2 clock source runs as normal Position  */
#define CRU_CLKDIAG_SPLL2STOP_STOP            (CRU_CLKDIAG_SPLL2STOP_STOP_Val << CRU_CLKDIAG_SPLL2STOP_Pos) /* (CRU_CLKDIAG) SPLL2 clock source is stopped Position  */
#define CRU_CLKDIAG_SPLL3STOP_Pos             _UINT32_(6)                                          /* (CRU_CLKDIAG) SPLL3 Clock Stop Control value Position */
#define CRU_CLKDIAG_SPLL3STOP_Msk             (_UINT32_(0x1) << CRU_CLKDIAG_SPLL3STOP_Pos)         /* (CRU_CLKDIAG) SPLL3 Clock Stop Control value Mask */
#define CRU_CLKDIAG_SPLL3STOP(value)          (CRU_CLKDIAG_SPLL3STOP_Msk & (_UINT32_(value) << CRU_CLKDIAG_SPLL3STOP_Pos)) /* Assigment of value for SPLL3STOP in the CRU_CLKDIAG register */
#define   CRU_CLKDIAG_SPLL3STOP_NORM_Val      _UINT32_(0x0)                                        /* (CRU_CLKDIAG) SPLL3 clock source runs as normal  */
#define   CRU_CLKDIAG_SPLL3STOP_STOP_Val      _UINT32_(0x1)                                        /* (CRU_CLKDIAG) SPLL3 clock source is stopped  */
#define CRU_CLKDIAG_SPLL3STOP_NORM            (CRU_CLKDIAG_SPLL3STOP_NORM_Val << CRU_CLKDIAG_SPLL3STOP_Pos) /* (CRU_CLKDIAG) SPLL3 clock source runs as normal Position  */
#define CRU_CLKDIAG_SPLL3STOP_STOP            (CRU_CLKDIAG_SPLL3STOP_STOP_Val << CRU_CLKDIAG_SPLL3STOP_Pos) /* (CRU_CLKDIAG) SPLL3 clock source is stopped Position  */
#define CRU_CLKDIAG_NMICNT_Pos                _UINT32_(16)                                         /* (CRU_CLKDIAG) NMI Counter value Position */
#define CRU_CLKDIAG_NMICNT_Msk                (_UINT32_(0xFFFF) << CRU_CLKDIAG_NMICNT_Pos)         /* (CRU_CLKDIAG) NMI Counter value Mask */
#define CRU_CLKDIAG_NMICNT(value)             (CRU_CLKDIAG_NMICNT_Msk & (_UINT32_(value) << CRU_CLKDIAG_NMICNT_Pos)) /* Assigment of value for NMICNT in the CRU_CLKDIAG register */
#define CRU_CLKDIAG_Msk                       _UINT32_(0xFFFF007F)                                 /* (CRU_CLKDIAG) Register Mask  */


/** \brief CRU register offsets definitions */
#define CRU_OSCCON_REG_OFST            _UINT32_(0x00)      /* (CRU_OSCCON) CRU OSCILLATOR CONTROL REGISTER Offset */
#define CRU_OSCCONCLR_REG_OFST         _UINT32_(0x04)      /* (CRU_OSCCONCLR)  Offset */
#define CRU_OSCCONSET_REG_OFST         _UINT32_(0x08)      /* (CRU_OSCCONSET)  Offset */
#define CRU_OSCCONINV_REG_OFST         _UINT32_(0x0C)      /* (CRU_OSCCONINV)  Offset */
#define CRU_OSCTUN_REG_OFST            _UINT32_(0x10)      /* (CRU_OSCTUN) CRU OSCILLATOR TRIMMING REGISTER Offset */
#define CRU_OSCTUNCLR_REG_OFST         _UINT32_(0x14)      /* (CRU_OSCTUNCLR)  Offset */
#define CRU_OSCTUNSET_REG_OFST         _UINT32_(0x18)      /* (CRU_OSCTUNSET)  Offset */
#define CRU_OSCTUNINV_REG_OFST         _UINT32_(0x1C)      /* (CRU_OSCTUNINV)  Offset */
#define CRU_SPLLCON_REG_OFST           _UINT32_(0x20)      /* (CRU_SPLLCON) SPLL CONTROL REGISTER Offset */
#define CRU_SPLLCONCLR_REG_OFST        _UINT32_(0x24)      /* (CRU_SPLLCONCLR)  Offset */
#define CRU_SPLLCONSET_REG_OFST        _UINT32_(0x28)      /* (CRU_SPLLCONSET)  Offset */
#define CRU_SPLLCONINV_REG_OFST        _UINT32_(0x2C)      /* (CRU_SPLLCONINV)  Offset */
#define CRU_REFO1CON_REG_OFST          _UINT32_(0x70)      /* (CRU_REFO1CON) REFERENCE OSCILLATOR 1 CONTROL REGISTER Offset */
#define CRU_REFO1CONCLR_REG_OFST       _UINT32_(0x74)      /* (CRU_REFO1CONCLR)  Offset */
#define CRU_REFO1CONSET_REG_OFST       _UINT32_(0x78)      /* (CRU_REFO1CONSET)  Offset */
#define CRU_REFO1CONINV_REG_OFST       _UINT32_(0x7C)      /* (CRU_REFO1CONINV)  Offset */
#define CRU_REFO1TRIM_REG_OFST         _UINT32_(0x80)      /* (CRU_REFO1TRIM) REFERENCE OSCILLATOR 1 TRIM REGISTER Offset */
#define CRU_REFO1TRIMCLR_REG_OFST      _UINT32_(0x84)      /* (CRU_REFO1TRIMCLR)  Offset */
#define CRU_REFO1TRIMSET_REG_OFST      _UINT32_(0x88)      /* (CRU_REFO1TRIMSET)  Offset */
#define CRU_REFO1TRIMINV_REG_OFST      _UINT32_(0x8C)      /* (CRU_REFO1TRIMINV)  Offset */
#define CRU_REFO2CON_REG_OFST          _UINT32_(0x90)      /* (CRU_REFO2CON) REFERENCE OSCILLATOR 2 CONTROL REGISTER Offset */
#define CRU_REFO2CONCLR_REG_OFST       _UINT32_(0x94)      /* (CRU_REFO2CONCLR)  Offset */
#define CRU_REFO2CONSET_REG_OFST       _UINT32_(0x98)      /* (CRU_REFO2CONSET)  Offset */
#define CRU_REFO2CONINV_REG_OFST       _UINT32_(0x9C)      /* (CRU_REFO2CONINV)  Offset */
#define CRU_REFO2TRIM_REG_OFST         _UINT32_(0xA0)      /* (CRU_REFO2TRIM) REFERENCE OSCILLATOR 2 TRIM REGISTER Offset */
#define CRU_REFO2TRIMCLR_REG_OFST      _UINT32_(0xA4)      /* (CRU_REFO2TRIMCLR)  Offset */
#define CRU_REFO2TRIMSET_REG_OFST      _UINT32_(0xA8)      /* (CRU_REFO2TRIMSET)  Offset */
#define CRU_REFO2TRIMINV_REG_OFST      _UINT32_(0xAC)      /* (CRU_REFO2TRIMINV)  Offset */
#define CRU_REFO3CON_REG_OFST          _UINT32_(0xB0)      /* (CRU_REFO3CON) REFERENCE OSCILLATOR 3 CONTROL REGISTER Offset */
#define CRU_REFO3CONCLR_REG_OFST       _UINT32_(0xB4)      /* (CRU_REFO3CONCLR)  Offset */
#define CRU_REFO3CONSET_REG_OFST       _UINT32_(0xB8)      /* (CRU_REFO3CONSET)  Offset */
#define CRU_REFO3CONINV_REG_OFST       _UINT32_(0xBC)      /* (CRU_REFO3CONINV)  Offset */
#define CRU_REFO3TRIM_REG_OFST         _UINT32_(0xC0)      /* (CRU_REFO3TRIM) REFERENCE OSCILLATOR 3 TRIM REGISTER Offset */
#define CRU_REFO3TRIMCLR_REG_OFST      _UINT32_(0xC4)      /* (CRU_REFO3TRIMCLR)  Offset */
#define CRU_REFO3TRIMSET_REG_OFST      _UINT32_(0xC8)      /* (CRU_REFO3TRIMSET)  Offset */
#define CRU_REFO3TRIMINV_REG_OFST      _UINT32_(0xCC)      /* (CRU_REFO3TRIMINV)  Offset */
#define CRU_REFO4CON_REG_OFST          _UINT32_(0xD0)      /* (CRU_REFO4CON) REFERENCE OSCILLATOR 4 CONTROL REGISTER Offset */
#define CRU_REFO4CONCLR_REG_OFST       _UINT32_(0xD4)      /* (CRU_REFO4CONCLR)  Offset */
#define CRU_REFO4CONSET_REG_OFST       _UINT32_(0xD8)      /* (CRU_REFO4CONSET)  Offset */
#define CRU_REFO4CONINV_REG_OFST       _UINT32_(0xDC)      /* (CRU_REFO4CONINV)  Offset */
#define CRU_REFO4TRIM_REG_OFST         _UINT32_(0xE0)      /* (CRU_REFO4TRIM) REFERENCE OSCILLATOR 4 TRIM REGISTER Offset */
#define CRU_REFO4TRIMCLR_REG_OFST      _UINT32_(0xE4)      /* (CRU_REFO4TRIMCLR)  Offset */
#define CRU_REFO4TRIMSET_REG_OFST      _UINT32_(0xE8)      /* (CRU_REFO4TRIMSET)  Offset */
#define CRU_REFO4TRIMINV_REG_OFST      _UINT32_(0xEC)      /* (CRU_REFO4TRIMINV)  Offset */
#define CRU_REFO5CON_REG_OFST          _UINT32_(0xF0)      /* (CRU_REFO5CON) REFERENCE OSCILLATOR 5 CONTROL REGISTER Offset */
#define CRU_REFO5CONCLR_REG_OFST       _UINT32_(0xF4)      /* (CRU_REFO5CONCLR)  Offset */
#define CRU_REFO5CONSET_REG_OFST       _UINT32_(0xF8)      /* (CRU_REFO5CONSET)  Offset */
#define CRU_REFO5CONINV_REG_OFST       _UINT32_(0xFC)      /* (CRU_REFO5CONINV)  Offset */
#define CRU_REFO5TRIM_REG_OFST         _UINT32_(0x100)     /* (CRU_REFO5TRIM) REFERENCE OSCILLATOR 5 TRIM REGISTER Offset */
#define CRU_REFO5TRIMCLR_REG_OFST      _UINT32_(0x104)     /* (CRU_REFO5TRIMCLR)  Offset */
#define CRU_REFO5TRIMSET_REG_OFST      _UINT32_(0x108)     /* (CRU_REFO5TRIMSET)  Offset */
#define CRU_REFO5TRIMINV_REG_OFST      _UINT32_(0x10C)     /* (CRU_REFO5TRIMINV)  Offset */
#define CRU_REFO6CON_REG_OFST          _UINT32_(0x110)     /* (CRU_REFO6CON) REFERENCE OSCILLATOR 6 CONTROL REGISTER Offset */
#define CRU_REFO6CONCLR_REG_OFST       _UINT32_(0x114)     /* (CRU_REFO6CONCLR)  Offset */
#define CRU_REFO6CONSET_REG_OFST       _UINT32_(0x118)     /* (CRU_REFO6CONSET)  Offset */
#define CRU_REFO6CONINV_REG_OFST       _UINT32_(0x11C)     /* (CRU_REFO6CONINV)  Offset */
#define CRU_REFO6TRIM_REG_OFST         _UINT32_(0x120)     /* (CRU_REFO6TRIM) REFERENCE OSCILLATOR 6 TRIM REGISTER Offset */
#define CRU_REFO6TRIMCLR_REG_OFST      _UINT32_(0x124)     /* (CRU_REFO6TRIMCLR)  Offset */
#define CRU_REFO6TRIMSET_REG_OFST      _UINT32_(0x128)     /* (CRU_REFO6TRIMSET)  Offset */
#define CRU_REFO6TRIMINV_REG_OFST      _UINT32_(0x12C)     /* (CRU_REFO6TRIMINV)  Offset */
#define CRU_PB1DIV_REG_OFST            _UINT32_(0x130)     /* (CRU_PB1DIV) PB1 CLOCK DIVISOR CONTROL REGISTER Offset */
#define CRU_PB1DIVCLR_REG_OFST         _UINT32_(0x134)     /* (CRU_PB1DIVCLR)  Offset */
#define CRU_PB1DIVSET_REG_OFST         _UINT32_(0x138)     /* (CRU_PB1DIVSET)  Offset */
#define CRU_PB1DIVINV_REG_OFST         _UINT32_(0x13C)     /* (CRU_PB1DIVINV)  Offset */
#define CRU_PB2DIV_REG_OFST            _UINT32_(0x140)     /* (CRU_PB2DIV) PB2 CLOCK DIVISOR CONTROL REGISTER Offset */
#define CRU_PB2DIVCLR_REG_OFST         _UINT32_(0x144)     /* (CRU_PB2DIVCLR)  Offset */
#define CRU_PB2DIVSET_REG_OFST         _UINT32_(0x148)     /* (CRU_PB2DIVSET)  Offset */
#define CRU_PB2DIVINV_REG_OFST         _UINT32_(0x14C)     /* (CRU_PB2DIVINV)  Offset */
#define CRU_PB3DIV_REG_OFST            _UINT32_(0x150)     /* (CRU_PB3DIV) PB3 CLOCK DIVISOR CONTROL REGISTER Offset */
#define CRU_PB3DIVCLR_REG_OFST         _UINT32_(0x154)     /* (CRU_PB3DIVCLR)  Offset */
#define CRU_PB3DIVSET_REG_OFST         _UINT32_(0x158)     /* (CRU_PB3DIVSET)  Offset */
#define CRU_PB3DIVINV_REG_OFST         _UINT32_(0x15C)     /* (CRU_PB3DIVINV)  Offset */
#define CRU_SLEWCON_REG_OFST           _UINT32_(0x160)     /* (CRU_SLEWCON) SLEW RATE CONTROL FOR CLOCK SWITCHING REGISTER Offset */
#define CRU_SLEWCONCLR_REG_OFST        _UINT32_(0x164)     /* (CRU_SLEWCONCLR)  Offset */
#define CRU_SLEWCONSET_REG_OFST        _UINT32_(0x168)     /* (CRU_SLEWCONSET)  Offset */
#define CRU_SLEWCONINV_REG_OFST        _UINT32_(0x16C)     /* (CRU_SLEWCONINV)  Offset */
#define CRU_CLKSTAT_REG_OFST           _UINT32_(0x170)     /* (CRU_CLKSTAT) CLOCK STATUS REGISTER Offset */
#define CRU_CLKDIAG_REG_OFST           _UINT32_(0x190)     /* (CRU_CLKDIAG) USER CLK DIAGNOSTICS CONTROL REGISTER Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief CRU register API structure */
typedef struct
{  /*  */
  __IO  uint32_t                       CRU_OSCCON;         /**< Offset: 0x00 (R/W  32) CRU OSCILLATOR CONTROL REGISTER */
  __IO  uint32_t                       CRU_OSCCONCLR;      /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       CRU_OSCCONSET;      /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       CRU_OSCCONINV;      /**< Offset: 0x0C (R/W  32)  */
  __IO  uint32_t                       CRU_OSCTUN;         /**< Offset: 0x10 (R/W  32) CRU OSCILLATOR TRIMMING REGISTER */
  __IO  uint32_t                       CRU_OSCTUNCLR;      /**< Offset: 0x14 (R/W  32)  */
  __IO  uint32_t                       CRU_OSCTUNSET;      /**< Offset: 0x18 (R/W  32)  */
  __IO  uint32_t                       CRU_OSCTUNINV;      /**< Offset: 0x1C (R/W  32)  */
  __IO  uint32_t                       CRU_SPLLCON;        /**< Offset: 0x20 (R/W  32) SPLL CONTROL REGISTER */
  __IO  uint32_t                       CRU_SPLLCONCLR;     /**< Offset: 0x24 (R/W  32)  */
  __IO  uint32_t                       CRU_SPLLCONSET;     /**< Offset: 0x28 (R/W  32)  */
  __IO  uint32_t                       CRU_SPLLCONINV;     /**< Offset: 0x2C (R/W  32)  */
  __I   uint8_t                        Reserved1[0x40];
  __IO  uint32_t                       CRU_REFO1CON;       /**< Offset: 0x70 (R/W  32) REFERENCE OSCILLATOR 1 CONTROL REGISTER */
  __IO  uint32_t                       CRU_REFO1CONCLR;    /**< Offset: 0x74 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO1CONSET;    /**< Offset: 0x78 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO1CONINV;    /**< Offset: 0x7C (R/W  32)  */
  __IO  uint32_t                       CRU_REFO1TRIM;      /**< Offset: 0x80 (R/W  32) REFERENCE OSCILLATOR 1 TRIM REGISTER */
  __IO  uint32_t                       CRU_REFO1TRIMCLR;   /**< Offset: 0x84 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO1TRIMSET;   /**< Offset: 0x88 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO1TRIMINV;   /**< Offset: 0x8C (R/W  32)  */
  __IO  uint32_t                       CRU_REFO2CON;       /**< Offset: 0x90 (R/W  32) REFERENCE OSCILLATOR 2 CONTROL REGISTER */
  __IO  uint32_t                       CRU_REFO2CONCLR;    /**< Offset: 0x94 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO2CONSET;    /**< Offset: 0x98 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO2CONINV;    /**< Offset: 0x9C (R/W  32)  */
  __IO  uint32_t                       CRU_REFO2TRIM;      /**< Offset: 0xA0 (R/W  32) REFERENCE OSCILLATOR 2 TRIM REGISTER */
  __IO  uint32_t                       CRU_REFO2TRIMCLR;   /**< Offset: 0xA4 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO2TRIMSET;   /**< Offset: 0xA8 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO2TRIMINV;   /**< Offset: 0xAC (R/W  32)  */
  __IO  uint32_t                       CRU_REFO3CON;       /**< Offset: 0xB0 (R/W  32) REFERENCE OSCILLATOR 3 CONTROL REGISTER */
  __IO  uint32_t                       CRU_REFO3CONCLR;    /**< Offset: 0xB4 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO3CONSET;    /**< Offset: 0xB8 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO3CONINV;    /**< Offset: 0xBC (R/W  32)  */
  __IO  uint32_t                       CRU_REFO3TRIM;      /**< Offset: 0xC0 (R/W  32) REFERENCE OSCILLATOR 3 TRIM REGISTER */
  __IO  uint32_t                       CRU_REFO3TRIMCLR;   /**< Offset: 0xC4 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO3TRIMSET;   /**< Offset: 0xC8 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO3TRIMINV;   /**< Offset: 0xCC (R/W  32)  */
  __IO  uint32_t                       CRU_REFO4CON;       /**< Offset: 0xD0 (R/W  32) REFERENCE OSCILLATOR 4 CONTROL REGISTER */
  __IO  uint32_t                       CRU_REFO4CONCLR;    /**< Offset: 0xD4 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO4CONSET;    /**< Offset: 0xD8 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO4CONINV;    /**< Offset: 0xDC (R/W  32)  */
  __IO  uint32_t                       CRU_REFO4TRIM;      /**< Offset: 0xE0 (R/W  32) REFERENCE OSCILLATOR 4 TRIM REGISTER */
  __IO  uint32_t                       CRU_REFO4TRIMCLR;   /**< Offset: 0xE4 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO4TRIMSET;   /**< Offset: 0xE8 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO4TRIMINV;   /**< Offset: 0xEC (R/W  32)  */
  __IO  uint32_t                       CRU_REFO5CON;       /**< Offset: 0xF0 (R/W  32) REFERENCE OSCILLATOR 5 CONTROL REGISTER */
  __IO  uint32_t                       CRU_REFO5CONCLR;    /**< Offset: 0xF4 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO5CONSET;    /**< Offset: 0xF8 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO5CONINV;    /**< Offset: 0xFC (R/W  32)  */
  __IO  uint32_t                       CRU_REFO5TRIM;      /**< Offset: 0x100 (R/W  32) REFERENCE OSCILLATOR 5 TRIM REGISTER */
  __IO  uint32_t                       CRU_REFO5TRIMCLR;   /**< Offset: 0x104 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO5TRIMSET;   /**< Offset: 0x108 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO5TRIMINV;   /**< Offset: 0x10C (R/W  32)  */
  __IO  uint32_t                       CRU_REFO6CON;       /**< Offset: 0x110 (R/W  32) REFERENCE OSCILLATOR 6 CONTROL REGISTER */
  __IO  uint32_t                       CRU_REFO6CONCLR;    /**< Offset: 0x114 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO6CONSET;    /**< Offset: 0x118 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO6CONINV;    /**< Offset: 0x11C (R/W  32)  */
  __IO  uint32_t                       CRU_REFO6TRIM;      /**< Offset: 0x120 (R/W  32) REFERENCE OSCILLATOR 6 TRIM REGISTER */
  __IO  uint32_t                       CRU_REFO6TRIMCLR;   /**< Offset: 0x124 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO6TRIMSET;   /**< Offset: 0x128 (R/W  32)  */
  __IO  uint32_t                       CRU_REFO6TRIMINV;   /**< Offset: 0x12C (R/W  32)  */
  __IO  uint32_t                       CRU_PB1DIV;         /**< Offset: 0x130 (R/W  32) PB1 CLOCK DIVISOR CONTROL REGISTER */
  __IO  uint32_t                       CRU_PB1DIVCLR;      /**< Offset: 0x134 (R/W  32)  */
  __IO  uint32_t                       CRU_PB1DIVSET;      /**< Offset: 0x138 (R/W  32)  */
  __IO  uint32_t                       CRU_PB1DIVINV;      /**< Offset: 0x13C (R/W  32)  */
  __IO  uint32_t                       CRU_PB2DIV;         /**< Offset: 0x140 (R/W  32) PB2 CLOCK DIVISOR CONTROL REGISTER */
  __IO  uint32_t                       CRU_PB2DIVCLR;      /**< Offset: 0x144 (R/W  32)  */
  __IO  uint32_t                       CRU_PB2DIVSET;      /**< Offset: 0x148 (R/W  32)  */
  __IO  uint32_t                       CRU_PB2DIVINV;      /**< Offset: 0x14C (R/W  32)  */
  __IO  uint32_t                       CRU_PB3DIV;         /**< Offset: 0x150 (R/W  32) PB3 CLOCK DIVISOR CONTROL REGISTER */
  __IO  uint32_t                       CRU_PB3DIVCLR;      /**< Offset: 0x154 (R/W  32)  */
  __IO  uint32_t                       CRU_PB3DIVSET;      /**< Offset: 0x158 (R/W  32)  */
  __IO  uint32_t                       CRU_PB3DIVINV;      /**< Offset: 0x15C (R/W  32)  */
  __IO  uint32_t                       CRU_SLEWCON;        /**< Offset: 0x160 (R/W  32) SLEW RATE CONTROL FOR CLOCK SWITCHING REGISTER */
  __IO  uint32_t                       CRU_SLEWCONCLR;     /**< Offset: 0x164 (R/W  32)  */
  __IO  uint32_t                       CRU_SLEWCONSET;     /**< Offset: 0x168 (R/W  32)  */
  __IO  uint32_t                       CRU_SLEWCONINV;     /**< Offset: 0x16C (R/W  32)  */
  __IO  uint32_t                       CRU_CLKSTAT;        /**< Offset: 0x170 (R/W  32) CLOCK STATUS REGISTER */
  __I   uint8_t                        Reserved2[0x1C];
  __IO  uint32_t                       CRU_CLKDIAG;        /**< Offset: 0x190 (R/W  32) USER CLK DIAGNOSTICS CONTROL REGISTER */
} cru_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_CRU_COMPONENT_H_ */
