/*
 * Component description for PAC
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
#ifndef _BZ45_PAC_COMPONENT_H_
#define _BZ45_PAC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PAC                                          */
/* ************************************************************************** */

/* -------- PAC_WRCTRL : (PAC Offset: 0x00) (R/W 32) Write control -------- */
#define PAC_WRCTRL_RESETVALUE                 _UINT32_(0x00)                                       /*  (PAC_WRCTRL) Write control  Reset Value */

#define PAC_WRCTRL_PERID_Pos                  _UINT32_(0)                                          /* (PAC_WRCTRL) Peripheral identifier Position */
#define PAC_WRCTRL_PERID_Msk                  (_UINT32_(0xFFFF) << PAC_WRCTRL_PERID_Pos)           /* (PAC_WRCTRL) Peripheral identifier Mask */
#define PAC_WRCTRL_PERID(value)               (PAC_WRCTRL_PERID_Msk & (_UINT32_(value) << PAC_WRCTRL_PERID_Pos)) /* Assigment of value for PERID in the PAC_WRCTRL register */
#define PAC_WRCTRL_KEY_Pos                    _UINT32_(16)                                         /* (PAC_WRCTRL) Peripheral access control key Position */
#define PAC_WRCTRL_KEY_Msk                    (_UINT32_(0xFF) << PAC_WRCTRL_KEY_Pos)               /* (PAC_WRCTRL) Peripheral access control key Mask */
#define PAC_WRCTRL_KEY(value)                 (PAC_WRCTRL_KEY_Msk & (_UINT32_(value) << PAC_WRCTRL_KEY_Pos)) /* Assigment of value for KEY in the PAC_WRCTRL register */
#define   PAC_WRCTRL_KEY_OFF_Val              _UINT32_(0x0)                                        /* (PAC_WRCTRL) No action  */
#define   PAC_WRCTRL_KEY_CLR_Val              _UINT32_(0x1)                                        /* (PAC_WRCTRL) Clear protection  */
#define   PAC_WRCTRL_KEY_SET_Val              _UINT32_(0x2)                                        /* (PAC_WRCTRL) Set protection  */
#define   PAC_WRCTRL_KEY_SETLCK_Val           _UINT32_(0x3)                                        /* (PAC_WRCTRL) Set and lock protection  */
#define PAC_WRCTRL_KEY_OFF                    (PAC_WRCTRL_KEY_OFF_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) No action Position  */
#define PAC_WRCTRL_KEY_CLR                    (PAC_WRCTRL_KEY_CLR_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Clear protection Position  */
#define PAC_WRCTRL_KEY_SET                    (PAC_WRCTRL_KEY_SET_Val << PAC_WRCTRL_KEY_Pos)       /* (PAC_WRCTRL) Set protection Position  */
#define PAC_WRCTRL_KEY_SETLCK                 (PAC_WRCTRL_KEY_SETLCK_Val << PAC_WRCTRL_KEY_Pos)    /* (PAC_WRCTRL) Set and lock protection Position  */
#define PAC_WRCTRL_Msk                        _UINT32_(0x00FFFFFF)                                 /* (PAC_WRCTRL) Register Mask  */


/* -------- PAC_EVCTRL : (PAC Offset: 0x04) (R/W 8) Event control -------- */
#define PAC_EVCTRL_RESETVALUE                 _UINT8_(0x00)                                        /*  (PAC_EVCTRL) Event control  Reset Value */

#define PAC_EVCTRL_ERREO_Pos                  _UINT8_(0)                                           /* (PAC_EVCTRL) Peripheral acess error event output Position */
#define PAC_EVCTRL_ERREO_Msk                  (_UINT8_(0x1) << PAC_EVCTRL_ERREO_Pos)               /* (PAC_EVCTRL) Peripheral acess error event output Mask */
#define PAC_EVCTRL_ERREO(value)               (PAC_EVCTRL_ERREO_Msk & (_UINT8_(value) << PAC_EVCTRL_ERREO_Pos)) /* Assigment of value for ERREO in the PAC_EVCTRL register */
#define PAC_EVCTRL_Msk                        _UINT8_(0x01)                                        /* (PAC_EVCTRL) Register Mask  */


/* -------- PAC_INTENCLR : (PAC Offset: 0x08) (R/W 8) Interrupt enable clear -------- */
#define PAC_INTENCLR_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENCLR) Interrupt enable clear  Reset Value */

#define PAC_INTENCLR_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENCLR) Peripheral access error interrupt disable Position */
#define PAC_INTENCLR_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENCLR_ERR_Pos)               /* (PAC_INTENCLR) Peripheral access error interrupt disable Mask */
#define PAC_INTENCLR_ERR(value)               (PAC_INTENCLR_ERR_Msk & (_UINT8_(value) << PAC_INTENCLR_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENCLR register */
#define PAC_INTENCLR_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENCLR) Register Mask  */


/* -------- PAC_INTENSET : (PAC Offset: 0x09) (R/W 8) Interrupt enable set -------- */
#define PAC_INTENSET_RESETVALUE               _UINT8_(0x00)                                        /*  (PAC_INTENSET) Interrupt enable set  Reset Value */

#define PAC_INTENSET_ERR_Pos                  _UINT8_(0)                                           /* (PAC_INTENSET) Peripheral access error interrupt enable Position */
#define PAC_INTENSET_ERR_Msk                  (_UINT8_(0x1) << PAC_INTENSET_ERR_Pos)               /* (PAC_INTENSET) Peripheral access error interrupt enable Mask */
#define PAC_INTENSET_ERR(value)               (PAC_INTENSET_ERR_Msk & (_UINT8_(value) << PAC_INTENSET_ERR_Pos)) /* Assigment of value for ERR in the PAC_INTENSET register */
#define PAC_INTENSET_Msk                      _UINT8_(0x01)                                        /* (PAC_INTENSET) Register Mask  */


/* -------- PAC_INTFLAGAHB : (PAC Offset: 0x10) (R/W 32) Bridge interrupt flag status -------- */
#define PAC_INTFLAGAHB_RESETVALUE             _UINT32_(0x00)                                       /*  (PAC_INTFLAGAHB) Bridge interrupt flag status  Reset Value */

#define PAC_INTFLAGAHB_SRAM0_Pos              _UINT32_(0)                                          /* (PAC_INTFLAGAHB) SRAM0 Position */
#define PAC_INTFLAGAHB_SRAM0_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_SRAM0_Pos)          /* (PAC_INTFLAGAHB) SRAM0 Mask */
#define PAC_INTFLAGAHB_SRAM0(value)           (PAC_INTFLAGAHB_SRAM0_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_SRAM0_Pos)) /* Assigment of value for SRAM0 in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_SRAM1_Pos              _UINT32_(1)                                          /* (PAC_INTFLAGAHB) SRAM1 Position */
#define PAC_INTFLAGAHB_SRAM1_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_SRAM1_Pos)          /* (PAC_INTFLAGAHB) SRAM1 Mask */
#define PAC_INTFLAGAHB_SRAM1(value)           (PAC_INTFLAGAHB_SRAM1_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_SRAM1_Pos)) /* Assigment of value for SRAM1 in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_SRAM2_Pos              _UINT32_(2)                                          /* (PAC_INTFLAGAHB) SRAM2 Position */
#define PAC_INTFLAGAHB_SRAM2_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_SRAM2_Pos)          /* (PAC_INTFLAGAHB) SRAM2 Mask */
#define PAC_INTFLAGAHB_SRAM2(value)           (PAC_INTFLAGAHB_SRAM2_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_SRAM2_Pos)) /* Assigment of value for SRAM2 in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_SRAM3_Pos              _UINT32_(3)                                          /* (PAC_INTFLAGAHB) SRAM3 Position */
#define PAC_INTFLAGAHB_SRAM3_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_SRAM3_Pos)          /* (PAC_INTFLAGAHB) SRAM3 Mask */
#define PAC_INTFLAGAHB_SRAM3(value)           (PAC_INTFLAGAHB_SRAM3_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_SRAM3_Pos)) /* Assigment of value for SRAM3 in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_CFLASH_Pos             _UINT32_(4)                                          /* (PAC_INTFLAGAHB) CFLASH Position */
#define PAC_INTFLAGAHB_CFLASH_Msk             (_UINT32_(0x1) << PAC_INTFLAGAHB_CFLASH_Pos)         /* (PAC_INTFLAGAHB) CFLASH Mask */
#define PAC_INTFLAGAHB_CFLASH(value)          (PAC_INTFLAGAHB_CFLASH_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_CFLASH_Pos)) /* Assigment of value for CFLASH in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_PFLASH_Pos             _UINT32_(5)                                          /* (PAC_INTFLAGAHB) PFLASH Position */
#define PAC_INTFLAGAHB_PFLASH_Msk             (_UINT32_(0x1) << PAC_INTFLAGAHB_PFLASH_Pos)         /* (PAC_INTFLAGAHB) PFLASH Mask */
#define PAC_INTFLAGAHB_PFLASH(value)          (PAC_INTFLAGAHB_PFLASH_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_PFLASH_Pos)) /* Assigment of value for PFLASH in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HPBA_Pos               _UINT32_(6)                                          /* (PAC_INTFLAGAHB) HPBA Position */
#define PAC_INTFLAGAHB_HPBA_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_HPBA_Pos)           /* (PAC_INTFLAGAHB) HPBA Mask */
#define PAC_INTFLAGAHB_HPBA(value)            (PAC_INTFLAGAHB_HPBA_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HPBA_Pos)) /* Assigment of value for HPBA in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HPBB_Pos               _UINT32_(7)                                          /* (PAC_INTFLAGAHB) HPBB Position */
#define PAC_INTFLAGAHB_HPBB_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_HPBB_Pos)           /* (PAC_INTFLAGAHB) HPBB Mask */
#define PAC_INTFLAGAHB_HPBB(value)            (PAC_INTFLAGAHB_HPBB_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HPBB_Pos)) /* Assigment of value for HPBB in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HPBC_Pos               _UINT32_(8)                                          /* (PAC_INTFLAGAHB) HPBC Position */
#define PAC_INTFLAGAHB_HPBC_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_HPBC_Pos)           /* (PAC_INTFLAGAHB) HPBC Mask */
#define PAC_INTFLAGAHB_HPBC(value)            (PAC_INTFLAGAHB_HPBC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HPBC_Pos)) /* Assigment of value for HPBC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_HPBPIC_Pos             _UINT32_(9)                                          /* (PAC_INTFLAGAHB) HPBPIC0 Position */
#define PAC_INTFLAGAHB_HPBPIC_Msk             (_UINT32_(0x1) << PAC_INTFLAGAHB_HPBPIC_Pos)         /* (PAC_INTFLAGAHB) HPBPIC0 Mask */
#define PAC_INTFLAGAHB_HPBPIC(value)          (PAC_INTFLAGAHB_HPBPIC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_HPBPIC_Pos)) /* Assigment of value for HPBPIC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_QSPI_Pos               _UINT32_(10)                                         /* (PAC_INTFLAGAHB) QSPI Position */
#define PAC_INTFLAGAHB_QSPI_Msk               (_UINT32_(0x1) << PAC_INTFLAGAHB_QSPI_Pos)           /* (PAC_INTFLAGAHB) QSPI Mask */
#define PAC_INTFLAGAHB_QSPI(value)            (PAC_INTFLAGAHB_QSPI_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_QSPI_Pos)) /* Assigment of value for QSPI in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_PUKCC_Pos              _UINT32_(11)                                         /* (PAC_INTFLAGAHB) PUKCC Position */
#define PAC_INTFLAGAHB_PUKCC_Msk              (_UINT32_(0x1) << PAC_INTFLAGAHB_PUKCC_Pos)          /* (PAC_INTFLAGAHB) PUKCC Mask */
#define PAC_INTFLAGAHB_PUKCC(value)           (PAC_INTFLAGAHB_PUKCC_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_PUKCC_Pos)) /* Assigment of value for PUKCC in the PAC_INTFLAGAHB register */
#define PAC_INTFLAGAHB_Msk                    _UINT32_(0x00000FFF)                                 /* (PAC_INTFLAGAHB) Register Mask  */

#define PAC_INTFLAGAHB_SRAM_Pos               _UINT32_(0)                                          /* (PAC_INTFLAGAHB Position) SRAMx */
#define PAC_INTFLAGAHB_SRAM_Msk               (_UINT32_(0xF) << PAC_INTFLAGAHB_SRAM_Pos)           /* (PAC_INTFLAGAHB Mask) SRAM */
#define PAC_INTFLAGAHB_SRAM(value)            (PAC_INTFLAGAHB_SRAM_Msk & (_UINT32_(value) << PAC_INTFLAGAHB_SRAM_Pos)) 

/* -------- PAC_INTFLAGA : (PAC Offset: 0x14) (R/W 32) Peripheral interrupt flag status - Bridge A -------- */
#define PAC_INTFLAGA_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A  Reset Value */

#define PAC_INTFLAGA_PAC_Pos                  _UINT32_(0)                                          /* (PAC_INTFLAGA) PAC Position */
#define PAC_INTFLAGA_PAC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_PAC_Pos)              /* (PAC_INTFLAGA) PAC Mask */
#define PAC_INTFLAGA_PAC(value)               (PAC_INTFLAGA_PAC_Msk & (_UINT32_(value) << PAC_INTFLAGA_PAC_Pos)) /* Assigment of value for PAC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_FREQM_Pos                _UINT32_(1)                                          /* (PAC_INTFLAGA) FREQM Position */
#define PAC_INTFLAGA_FREQM_Msk                (_UINT32_(0x1) << PAC_INTFLAGA_FREQM_Pos)            /* (PAC_INTFLAGA) FREQM Mask */
#define PAC_INTFLAGA_FREQM(value)             (PAC_INTFLAGA_FREQM_Msk & (_UINT32_(value) << PAC_INTFLAGA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_EIC_Pos                  _UINT32_(2)                                          /* (PAC_INTFLAGA) EIC Position */
#define PAC_INTFLAGA_EIC_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_EIC_Pos)              /* (PAC_INTFLAGA) EIC Mask */
#define PAC_INTFLAGA_EIC(value)               (PAC_INTFLAGA_EIC_Msk & (_UINT32_(value) << PAC_INTFLAGA_EIC_Pos)) /* Assigment of value for EIC in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM0_Pos              _UINT32_(3)                                          /* (PAC_INTFLAGA) SERCOM0 Position */
#define PAC_INTFLAGA_SERCOM0_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM0_Pos)          /* (PAC_INTFLAGA) SERCOM0 Mask */
#define PAC_INTFLAGA_SERCOM0(value)           (PAC_INTFLAGA_SERCOM0_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_SERCOM1_Pos              _UINT32_(4)                                          /* (PAC_INTFLAGA) SERCOM1 Position */
#define PAC_INTFLAGA_SERCOM1_Msk              (_UINT32_(0x1) << PAC_INTFLAGA_SERCOM1_Pos)          /* (PAC_INTFLAGA) SERCOM1 Mask */
#define PAC_INTFLAGA_SERCOM1(value)           (PAC_INTFLAGA_SERCOM1_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TC0_Pos                  _UINT32_(5)                                          /* (PAC_INTFLAGA) TC0 Position */
#define PAC_INTFLAGA_TC0_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_TC0_Pos)              /* (PAC_INTFLAGA) TC0 Mask */
#define PAC_INTFLAGA_TC0(value)               (PAC_INTFLAGA_TC0_Msk & (_UINT32_(value) << PAC_INTFLAGA_TC0_Pos)) /* Assigment of value for TC0 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TC1_Pos                  _UINT32_(6)                                          /* (PAC_INTFLAGA) TC1 Position */
#define PAC_INTFLAGA_TC1_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_TC1_Pos)              /* (PAC_INTFLAGA) TC1 Mask */
#define PAC_INTFLAGA_TC1(value)               (PAC_INTFLAGA_TC1_Msk & (_UINT32_(value) << PAC_INTFLAGA_TC1_Pos)) /* Assigment of value for TC1 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TC2_Pos                  _UINT32_(7)                                          /* (PAC_INTFLAGA) TC2 Position */
#define PAC_INTFLAGA_TC2_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_TC2_Pos)              /* (PAC_INTFLAGA) TC2 Mask */
#define PAC_INTFLAGA_TC2(value)               (PAC_INTFLAGA_TC2_Msk & (_UINT32_(value) << PAC_INTFLAGA_TC2_Pos)) /* Assigment of value for TC2 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TC3_Pos                  _UINT32_(8)                                          /* (PAC_INTFLAGA) TC3 Position */
#define PAC_INTFLAGA_TC3_Msk                  (_UINT32_(0x1) << PAC_INTFLAGA_TC3_Pos)              /* (PAC_INTFLAGA) TC3 Mask */
#define PAC_INTFLAGA_TC3(value)               (PAC_INTFLAGA_TC3_Msk & (_UINT32_(value) << PAC_INTFLAGA_TC3_Pos)) /* Assigment of value for TC3 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TCC0_Pos                 _UINT32_(9)                                          /* (PAC_INTFLAGA) TCC0 Position */
#define PAC_INTFLAGA_TCC0_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_TCC0_Pos)             /* (PAC_INTFLAGA) TCC0 Mask */
#define PAC_INTFLAGA_TCC0(value)              (PAC_INTFLAGA_TCC0_Msk & (_UINT32_(value) << PAC_INTFLAGA_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TCC1_Pos                 _UINT32_(10)                                         /* (PAC_INTFLAGA) TCC1 Position */
#define PAC_INTFLAGA_TCC1_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_TCC1_Pos)             /* (PAC_INTFLAGA) TCC1 Mask */
#define PAC_INTFLAGA_TCC1(value)              (PAC_INTFLAGA_TCC1_Msk & (_UINT32_(value) << PAC_INTFLAGA_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_TCC2_Pos                 _UINT32_(11)                                         /* (PAC_INTFLAGA) TCC2 Position */
#define PAC_INTFLAGA_TCC2_Msk                 (_UINT32_(0x1) << PAC_INTFLAGA_TCC2_Pos)             /* (PAC_INTFLAGA) TCC2 Mask */
#define PAC_INTFLAGA_TCC2(value)              (PAC_INTFLAGA_TCC2_Msk & (_UINT32_(value) << PAC_INTFLAGA_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_INTFLAGA register */
#define PAC_INTFLAGA_Msk                      _UINT32_(0x00000FFF)                                 /* (PAC_INTFLAGA) Register Mask  */

#define PAC_INTFLAGA_SERCOM_Pos               _UINT32_(3)                                          /* (PAC_INTFLAGA Position) SERCOMx */
#define PAC_INTFLAGA_SERCOM_Msk               (_UINT32_(0x3) << PAC_INTFLAGA_SERCOM_Pos)           /* (PAC_INTFLAGA Mask) SERCOM */
#define PAC_INTFLAGA_SERCOM(value)            (PAC_INTFLAGA_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGA_SERCOM_Pos)) 
#define PAC_INTFLAGA_TC_Pos                   _UINT32_(5)                                          /* (PAC_INTFLAGA Position) TCx */
#define PAC_INTFLAGA_TC_Msk                   (_UINT32_(0xF) << PAC_INTFLAGA_TC_Pos)               /* (PAC_INTFLAGA Mask) TC */
#define PAC_INTFLAGA_TC(value)                (PAC_INTFLAGA_TC_Msk & (_UINT32_(value) << PAC_INTFLAGA_TC_Pos)) 
#define PAC_INTFLAGA_TCC_Pos                  _UINT32_(9)                                          /* (PAC_INTFLAGA Position) TCC2 */
#define PAC_INTFLAGA_TCC_Msk                  (_UINT32_(0x7) << PAC_INTFLAGA_TCC_Pos)              /* (PAC_INTFLAGA Mask) TCC */
#define PAC_INTFLAGA_TCC(value)               (PAC_INTFLAGA_TCC_Msk & (_UINT32_(value) << PAC_INTFLAGA_TCC_Pos)) 

/* -------- PAC_INTFLAGB : (PAC Offset: 0x18) (R/W 32) Peripheral interrupt flag status - Bridge B -------- */
#define PAC_INTFLAGB_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B  Reset Value */

#define PAC_INTFLAGB_DSU_Pos                  _UINT32_(0)                                          /* (PAC_INTFLAGB) DSU Position */
#define PAC_INTFLAGB_DSU_Msk                  (_UINT32_(0x1) << PAC_INTFLAGB_DSU_Pos)              /* (PAC_INTFLAGB) DSU Mask */
#define PAC_INTFLAGB_DSU(value)               (PAC_INTFLAGB_DSU_Msk & (_UINT32_(value) << PAC_INTFLAGB_DSU_Pos)) /* Assigment of value for DSU in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_DMAC_Pos                 _UINT32_(2)                                          /* (PAC_INTFLAGB) DMAC Position */
#define PAC_INTFLAGB_DMAC_Msk                 (_UINT32_(0x1) << PAC_INTFLAGB_DMAC_Pos)             /* (PAC_INTFLAGB) DMAC Mask */
#define PAC_INTFLAGB_DMAC(value)              (PAC_INTFLAGB_DMAC_Msk & (_UINT32_(value) << PAC_INTFLAGB_DMAC_Pos)) /* Assigment of value for DMAC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_EVSYS_Pos                _UINT32_(3)                                          /* (PAC_INTFLAGB) EVSYS Position */
#define PAC_INTFLAGB_EVSYS_Msk                (_UINT32_(0x1) << PAC_INTFLAGB_EVSYS_Pos)            /* (PAC_INTFLAGB) EVSYS Mask */
#define PAC_INTFLAGB_EVSYS(value)             (PAC_INTFLAGB_EVSYS_Msk & (_UINT32_(value) << PAC_INTFLAGB_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_RAMECC_Pos               _UINT32_(4)                                          /* (PAC_INTFLAGB) RAMECC Position */
#define PAC_INTFLAGB_RAMECC_Msk               (_UINT32_(0x1) << PAC_INTFLAGB_RAMECC_Pos)           /* (PAC_INTFLAGB) RAMECC Mask */
#define PAC_INTFLAGB_RAMECC(value)            (PAC_INTFLAGB_RAMECC_Msk & (_UINT32_(value) << PAC_INTFLAGB_RAMECC_Pos)) /* Assigment of value for RAMECC in the PAC_INTFLAGB register */
#define PAC_INTFLAGB_Msk                      _UINT32_(0x0000001D)                                 /* (PAC_INTFLAGB) Register Mask  */


/* -------- PAC_INTFLAGC : (PAC Offset: 0x1C) (R/W 32) Peripheral interrupt flag status - Bridge C -------- */
#define PAC_INTFLAGC_RESETVALUE               _UINT32_(0x00)                                       /*  (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C  Reset Value */

#define PAC_INTFLAGC_QSPI_Pos                 _UINT32_(0)                                          /* (PAC_INTFLAGC) QSPI Position */
#define PAC_INTFLAGC_QSPI_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_QSPI_Pos)             /* (PAC_INTFLAGC) QSPI Mask */
#define PAC_INTFLAGC_QSPI(value)              (PAC_INTFLAGC_QSPI_Msk & (_UINT32_(value) << PAC_INTFLAGC_QSPI_Pos)) /* Assigment of value for QSPI in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_AES_Pos                  _UINT32_(1)                                          /* (PAC_INTFLAGC) AES Position */
#define PAC_INTFLAGC_AES_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_AES_Pos)              /* (PAC_INTFLAGC) AES Mask */
#define PAC_INTFLAGC_AES(value)               (PAC_INTFLAGC_AES_Msk & (_UINT32_(value) << PAC_INTFLAGC_AES_Pos)) /* Assigment of value for AES in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM2_Pos              _UINT32_(3)                                          /* (PAC_INTFLAGC) SERCOM2 Position */
#define PAC_INTFLAGC_SERCOM2_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM2_Pos)          /* (PAC_INTFLAGC) SERCOM2 Mask */
#define PAC_INTFLAGC_SERCOM2(value)           (PAC_INTFLAGC_SERCOM2_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_SERCOM3_Pos              _UINT32_(4)                                          /* (PAC_INTFLAGC) SERCOM3 Position */
#define PAC_INTFLAGC_SERCOM3_Msk              (_UINT32_(0x1) << PAC_INTFLAGC_SERCOM3_Pos)          /* (PAC_INTFLAGC) SERCOM3 Mask */
#define PAC_INTFLAGC_SERCOM3(value)           (PAC_INTFLAGC_SERCOM3_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_CCL_Pos                  _UINT32_(6)                                          /* (PAC_INTFLAGC) CCL Position */
#define PAC_INTFLAGC_CCL_Msk                  (_UINT32_(0x1) << PAC_INTFLAGC_CCL_Pos)              /* (PAC_INTFLAGC) CCL Mask */
#define PAC_INTFLAGC_CCL(value)               (PAC_INTFLAGC_CCL_Msk & (_UINT32_(value) << PAC_INTFLAGC_CCL_Pos)) /* Assigment of value for CCL in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_AC_Pos                   _UINT32_(7)                                          /* (PAC_INTFLAGC) AC Position */
#define PAC_INTFLAGC_AC_Msk                   (_UINT32_(0x1) << PAC_INTFLAGC_AC_Pos)               /* (PAC_INTFLAGC) AC Mask */
#define PAC_INTFLAGC_AC(value)                (PAC_INTFLAGC_AC_Msk & (_UINT32_(value) << PAC_INTFLAGC_AC_Pos)) /* Assigment of value for AC in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_TRNG_Pos                 _UINT32_(10)                                         /* (PAC_INTFLAGC) TRNG Position */
#define PAC_INTFLAGC_TRNG_Msk                 (_UINT32_(0x1) << PAC_INTFLAGC_TRNG_Pos)             /* (PAC_INTFLAGC) TRNG Mask */
#define PAC_INTFLAGC_TRNG(value)              (PAC_INTFLAGC_TRNG_Msk & (_UINT32_(value) << PAC_INTFLAGC_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_INTFLAGC register */
#define PAC_INTFLAGC_Msk                      _UINT32_(0x000004DB)                                 /* (PAC_INTFLAGC) Register Mask  */

#define PAC_INTFLAGC_SERCOM_Pos               _UINT32_(3)                                          /* (PAC_INTFLAGC Position) SERCOM2 */
#define PAC_INTFLAGC_SERCOM_Msk               (_UINT32_(0x3) << PAC_INTFLAGC_SERCOM_Pos)           /* (PAC_INTFLAGC Mask) SERCOM */
#define PAC_INTFLAGC_SERCOM(value)            (PAC_INTFLAGC_SERCOM_Msk & (_UINT32_(value) << PAC_INTFLAGC_SERCOM_Pos)) 

/* -------- PAC_STATUSA : (PAC Offset: 0x34) ( R/ 32) Peripheral write protection status - Bridge A -------- */
#define PAC_STATUSA_RESETVALUE                _UINT32_(0x10000)                                    /*  (PAC_STATUSA) Peripheral write protection status - Bridge A  Reset Value */

#define PAC_STATUSA_PAC_Pos                   _UINT32_(0)                                          /* (PAC_STATUSA) PAC APB Protect Enable Position */
#define PAC_STATUSA_PAC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_PAC_Pos)               /* (PAC_STATUSA) PAC APB Protect Enable Mask */
#define PAC_STATUSA_PAC(value)                (PAC_STATUSA_PAC_Msk & (_UINT32_(value) << PAC_STATUSA_PAC_Pos)) /* Assigment of value for PAC in the PAC_STATUSA register */
#define PAC_STATUSA_FREQM_Pos                 _UINT32_(1)                                          /* (PAC_STATUSA) FREQM APB Protect Enable Position */
#define PAC_STATUSA_FREQM_Msk                 (_UINT32_(0x1) << PAC_STATUSA_FREQM_Pos)             /* (PAC_STATUSA) FREQM APB Protect Enable Mask */
#define PAC_STATUSA_FREQM(value)              (PAC_STATUSA_FREQM_Msk & (_UINT32_(value) << PAC_STATUSA_FREQM_Pos)) /* Assigment of value for FREQM in the PAC_STATUSA register */
#define PAC_STATUSA_EIC_Pos                   _UINT32_(2)                                          /* (PAC_STATUSA) EIC APB Protect Enable Position */
#define PAC_STATUSA_EIC_Msk                   (_UINT32_(0x1) << PAC_STATUSA_EIC_Pos)               /* (PAC_STATUSA) EIC APB Protect Enable Mask */
#define PAC_STATUSA_EIC(value)                (PAC_STATUSA_EIC_Msk & (_UINT32_(value) << PAC_STATUSA_EIC_Pos)) /* Assigment of value for EIC in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM0_Pos               _UINT32_(3)                                          /* (PAC_STATUSA) SERCOM0 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM0_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM0_Pos)           /* (PAC_STATUSA) SERCOM0 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM0(value)            (PAC_STATUSA_SERCOM0_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM0_Pos)) /* Assigment of value for SERCOM0 in the PAC_STATUSA register */
#define PAC_STATUSA_SERCOM1_Pos               _UINT32_(4)                                          /* (PAC_STATUSA) SERCOM1 APB Protect Enable Position */
#define PAC_STATUSA_SERCOM1_Msk               (_UINT32_(0x1) << PAC_STATUSA_SERCOM1_Pos)           /* (PAC_STATUSA) SERCOM1 APB Protect Enable Mask */
#define PAC_STATUSA_SERCOM1(value)            (PAC_STATUSA_SERCOM1_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM1_Pos)) /* Assigment of value for SERCOM1 in the PAC_STATUSA register */
#define PAC_STATUSA_TC0_Pos                   _UINT32_(5)                                          /* (PAC_STATUSA) TC0 APB Protect Enable Position */
#define PAC_STATUSA_TC0_Msk                   (_UINT32_(0x1) << PAC_STATUSA_TC0_Pos)               /* (PAC_STATUSA) TC0 APB Protect Enable Mask */
#define PAC_STATUSA_TC0(value)                (PAC_STATUSA_TC0_Msk & (_UINT32_(value) << PAC_STATUSA_TC0_Pos)) /* Assigment of value for TC0 in the PAC_STATUSA register */
#define PAC_STATUSA_TC1_Pos                   _UINT32_(6)                                          /* (PAC_STATUSA) TC1 APB Protect Enable Position */
#define PAC_STATUSA_TC1_Msk                   (_UINT32_(0x1) << PAC_STATUSA_TC1_Pos)               /* (PAC_STATUSA) TC1 APB Protect Enable Mask */
#define PAC_STATUSA_TC1(value)                (PAC_STATUSA_TC1_Msk & (_UINT32_(value) << PAC_STATUSA_TC1_Pos)) /* Assigment of value for TC1 in the PAC_STATUSA register */
#define PAC_STATUSA_TC2_Pos                   _UINT32_(7)                                          /* (PAC_STATUSA) TC2 APB Protect Enable Position */
#define PAC_STATUSA_TC2_Msk                   (_UINT32_(0x1) << PAC_STATUSA_TC2_Pos)               /* (PAC_STATUSA) TC2 APB Protect Enable Mask */
#define PAC_STATUSA_TC2(value)                (PAC_STATUSA_TC2_Msk & (_UINT32_(value) << PAC_STATUSA_TC2_Pos)) /* Assigment of value for TC2 in the PAC_STATUSA register */
#define PAC_STATUSA_TC3_Pos                   _UINT32_(8)                                          /* (PAC_STATUSA) TC3 APB Protect Enable Position */
#define PAC_STATUSA_TC3_Msk                   (_UINT32_(0x1) << PAC_STATUSA_TC3_Pos)               /* (PAC_STATUSA) TC3 APB Protect Enable Mask */
#define PAC_STATUSA_TC3(value)                (PAC_STATUSA_TC3_Msk & (_UINT32_(value) << PAC_STATUSA_TC3_Pos)) /* Assigment of value for TC3 in the PAC_STATUSA register */
#define PAC_STATUSA_TCC0_Pos                  _UINT32_(9)                                          /* (PAC_STATUSA) TCC0 APB Protect Enable Position */
#define PAC_STATUSA_TCC0_Msk                  (_UINT32_(0x1) << PAC_STATUSA_TCC0_Pos)              /* (PAC_STATUSA) TCC0 APB Protect Enable Mask */
#define PAC_STATUSA_TCC0(value)               (PAC_STATUSA_TCC0_Msk & (_UINT32_(value) << PAC_STATUSA_TCC0_Pos)) /* Assigment of value for TCC0 in the PAC_STATUSA register */
#define PAC_STATUSA_TCC1_Pos                  _UINT32_(10)                                         /* (PAC_STATUSA) TCC1 APB Protect Enable Position */
#define PAC_STATUSA_TCC1_Msk                  (_UINT32_(0x1) << PAC_STATUSA_TCC1_Pos)              /* (PAC_STATUSA) TCC1 APB Protect Enable Mask */
#define PAC_STATUSA_TCC1(value)               (PAC_STATUSA_TCC1_Msk & (_UINT32_(value) << PAC_STATUSA_TCC1_Pos)) /* Assigment of value for TCC1 in the PAC_STATUSA register */
#define PAC_STATUSA_TCC2_Pos                  _UINT32_(11)                                         /* (PAC_STATUSA) TCC2 APB Protect Enable Position */
#define PAC_STATUSA_TCC2_Msk                  (_UINT32_(0x1) << PAC_STATUSA_TCC2_Pos)              /* (PAC_STATUSA) TCC2 APB Protect Enable Mask */
#define PAC_STATUSA_TCC2(value)               (PAC_STATUSA_TCC2_Msk & (_UINT32_(value) << PAC_STATUSA_TCC2_Pos)) /* Assigment of value for TCC2 in the PAC_STATUSA register */
#define PAC_STATUSA_Msk                       _UINT32_(0x00000FFF)                                 /* (PAC_STATUSA) Register Mask  */

#define PAC_STATUSA_SERCOM_Pos                _UINT32_(3)                                          /* (PAC_STATUSA Position) SERCOMx APB Protect Enable */
#define PAC_STATUSA_SERCOM_Msk                (_UINT32_(0x3) << PAC_STATUSA_SERCOM_Pos)            /* (PAC_STATUSA Mask) SERCOM */
#define PAC_STATUSA_SERCOM(value)             (PAC_STATUSA_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSA_SERCOM_Pos)) 
#define PAC_STATUSA_TC_Pos                    _UINT32_(5)                                          /* (PAC_STATUSA Position) TCx APB Protect Enable */
#define PAC_STATUSA_TC_Msk                    (_UINT32_(0xF) << PAC_STATUSA_TC_Pos)                /* (PAC_STATUSA Mask) TC */
#define PAC_STATUSA_TC(value)                 (PAC_STATUSA_TC_Msk & (_UINT32_(value) << PAC_STATUSA_TC_Pos)) 
#define PAC_STATUSA_TCC_Pos                   _UINT32_(9)                                          /* (PAC_STATUSA Position) TCC2 APB Protect Enable */
#define PAC_STATUSA_TCC_Msk                   (_UINT32_(0x7) << PAC_STATUSA_TCC_Pos)               /* (PAC_STATUSA Mask) TCC */
#define PAC_STATUSA_TCC(value)                (PAC_STATUSA_TCC_Msk & (_UINT32_(value) << PAC_STATUSA_TCC_Pos)) 

/* -------- PAC_STATUSB : (PAC Offset: 0x38) ( R/ 32) Peripheral write protection status - Bridge B -------- */
#define PAC_STATUSB_RESETVALUE                _UINT32_(0x02)                                       /*  (PAC_STATUSB) Peripheral write protection status - Bridge B  Reset Value */

#define PAC_STATUSB_DSU_Pos                   _UINT32_(0)                                          /* (PAC_STATUSB) DSU APB Protect Enable Position */
#define PAC_STATUSB_DSU_Msk                   (_UINT32_(0x1) << PAC_STATUSB_DSU_Pos)               /* (PAC_STATUSB) DSU APB Protect Enable Mask */
#define PAC_STATUSB_DSU(value)                (PAC_STATUSB_DSU_Msk & (_UINT32_(value) << PAC_STATUSB_DSU_Pos)) /* Assigment of value for DSU in the PAC_STATUSB register */
#define PAC_STATUSB_DMAC_Pos                  _UINT32_(2)                                          /* (PAC_STATUSB) DMAC APB Protect Enable Position */
#define PAC_STATUSB_DMAC_Msk                  (_UINT32_(0x1) << PAC_STATUSB_DMAC_Pos)              /* (PAC_STATUSB) DMAC APB Protect Enable Mask */
#define PAC_STATUSB_DMAC(value)               (PAC_STATUSB_DMAC_Msk & (_UINT32_(value) << PAC_STATUSB_DMAC_Pos)) /* Assigment of value for DMAC in the PAC_STATUSB register */
#define PAC_STATUSB_EVSYS_Pos                 _UINT32_(3)                                          /* (PAC_STATUSB) EVSYS APB Protect Enable Position */
#define PAC_STATUSB_EVSYS_Msk                 (_UINT32_(0x1) << PAC_STATUSB_EVSYS_Pos)             /* (PAC_STATUSB) EVSYS APB Protect Enable Mask */
#define PAC_STATUSB_EVSYS(value)              (PAC_STATUSB_EVSYS_Msk & (_UINT32_(value) << PAC_STATUSB_EVSYS_Pos)) /* Assigment of value for EVSYS in the PAC_STATUSB register */
#define PAC_STATUSB_RAMECC_Pos                _UINT32_(4)                                          /* (PAC_STATUSB) RAMECC APB Protect Enable Position */
#define PAC_STATUSB_RAMECC_Msk                (_UINT32_(0x1) << PAC_STATUSB_RAMECC_Pos)            /* (PAC_STATUSB) RAMECC APB Protect Enable Mask */
#define PAC_STATUSB_RAMECC(value)             (PAC_STATUSB_RAMECC_Msk & (_UINT32_(value) << PAC_STATUSB_RAMECC_Pos)) /* Assigment of value for RAMECC in the PAC_STATUSB register */
#define PAC_STATUSB_Msk                       _UINT32_(0x0000001D)                                 /* (PAC_STATUSB) Register Mask  */


/* -------- PAC_STATUSC : (PAC Offset: 0x3C) ( R/ 32) Peripheral write protection status - Bridge C -------- */
#define PAC_STATUSC_RESETVALUE                _UINT32_(0x00)                                       /*  (PAC_STATUSC) Peripheral write protection status - Bridge C  Reset Value */

#define PAC_STATUSC_QSPI_Pos                  _UINT32_(0)                                          /* (PAC_STATUSC) QSPI APB Protect Enable Position */
#define PAC_STATUSC_QSPI_Msk                  (_UINT32_(0x1) << PAC_STATUSC_QSPI_Pos)              /* (PAC_STATUSC) QSPI APB Protect Enable Mask */
#define PAC_STATUSC_QSPI(value)               (PAC_STATUSC_QSPI_Msk & (_UINT32_(value) << PAC_STATUSC_QSPI_Pos)) /* Assigment of value for QSPI in the PAC_STATUSC register */
#define PAC_STATUSC_AES_Pos                   _UINT32_(1)                                          /* (PAC_STATUSC) AES APB Protect Enable Position */
#define PAC_STATUSC_AES_Msk                   (_UINT32_(0x1) << PAC_STATUSC_AES_Pos)               /* (PAC_STATUSC) AES APB Protect Enable Mask */
#define PAC_STATUSC_AES(value)                (PAC_STATUSC_AES_Msk & (_UINT32_(value) << PAC_STATUSC_AES_Pos)) /* Assigment of value for AES in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM2_Pos               _UINT32_(3)                                          /* (PAC_STATUSC) SERCOM2 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM2_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM2_Pos)           /* (PAC_STATUSC) SERCOM2 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM2(value)            (PAC_STATUSC_SERCOM2_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM2_Pos)) /* Assigment of value for SERCOM2 in the PAC_STATUSC register */
#define PAC_STATUSC_SERCOM3_Pos               _UINT32_(4)                                          /* (PAC_STATUSC) SERCOM3 APB Protect Enable Position */
#define PAC_STATUSC_SERCOM3_Msk               (_UINT32_(0x1) << PAC_STATUSC_SERCOM3_Pos)           /* (PAC_STATUSC) SERCOM3 APB Protect Enable Mask */
#define PAC_STATUSC_SERCOM3(value)            (PAC_STATUSC_SERCOM3_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM3_Pos)) /* Assigment of value for SERCOM3 in the PAC_STATUSC register */
#define PAC_STATUSC_CCL_Pos                   _UINT32_(6)                                          /* (PAC_STATUSC) CCL APB Protect Enable Position */
#define PAC_STATUSC_CCL_Msk                   (_UINT32_(0x1) << PAC_STATUSC_CCL_Pos)               /* (PAC_STATUSC) CCL APB Protect Enable Mask */
#define PAC_STATUSC_CCL(value)                (PAC_STATUSC_CCL_Msk & (_UINT32_(value) << PAC_STATUSC_CCL_Pos)) /* Assigment of value for CCL in the PAC_STATUSC register */
#define PAC_STATUSC_AC_Pos                    _UINT32_(7)                                          /* (PAC_STATUSC) AC APB Protect Enable Position */
#define PAC_STATUSC_AC_Msk                    (_UINT32_(0x1) << PAC_STATUSC_AC_Pos)                /* (PAC_STATUSC) AC APB Protect Enable Mask */
#define PAC_STATUSC_AC(value)                 (PAC_STATUSC_AC_Msk & (_UINT32_(value) << PAC_STATUSC_AC_Pos)) /* Assigment of value for AC in the PAC_STATUSC register */
#define PAC_STATUSC_TRNG_Pos                  _UINT32_(10)                                         /* (PAC_STATUSC) TRNG APB Protect Enable Position */
#define PAC_STATUSC_TRNG_Msk                  (_UINT32_(0x1) << PAC_STATUSC_TRNG_Pos)              /* (PAC_STATUSC) TRNG APB Protect Enable Mask */
#define PAC_STATUSC_TRNG(value)               (PAC_STATUSC_TRNG_Msk & (_UINT32_(value) << PAC_STATUSC_TRNG_Pos)) /* Assigment of value for TRNG in the PAC_STATUSC register */
#define PAC_STATUSC_Msk                       _UINT32_(0x000004DB)                                 /* (PAC_STATUSC) Register Mask  */

#define PAC_STATUSC_SERCOM_Pos                _UINT32_(3)                                          /* (PAC_STATUSC Position) SERCOM2 APB Protect Enable */
#define PAC_STATUSC_SERCOM_Msk                (_UINT32_(0x3) << PAC_STATUSC_SERCOM_Pos)            /* (PAC_STATUSC Mask) SERCOM */
#define PAC_STATUSC_SERCOM(value)             (PAC_STATUSC_SERCOM_Msk & (_UINT32_(value) << PAC_STATUSC_SERCOM_Pos)) 

/** \brief PAC register offsets definitions */
#define PAC_WRCTRL_REG_OFST            _UINT32_(0x00)      /* (PAC_WRCTRL) Write control Offset */
#define PAC_EVCTRL_REG_OFST            _UINT32_(0x04)      /* (PAC_EVCTRL) Event control Offset */
#define PAC_INTENCLR_REG_OFST          _UINT32_(0x08)      /* (PAC_INTENCLR) Interrupt enable clear Offset */
#define PAC_INTENSET_REG_OFST          _UINT32_(0x09)      /* (PAC_INTENSET) Interrupt enable set Offset */
#define PAC_INTFLAGAHB_REG_OFST        _UINT32_(0x10)      /* (PAC_INTFLAGAHB) Bridge interrupt flag status Offset */
#define PAC_INTFLAGA_REG_OFST          _UINT32_(0x14)      /* (PAC_INTFLAGA) Peripheral interrupt flag status - Bridge A Offset */
#define PAC_INTFLAGB_REG_OFST          _UINT32_(0x18)      /* (PAC_INTFLAGB) Peripheral interrupt flag status - Bridge B Offset */
#define PAC_INTFLAGC_REG_OFST          _UINT32_(0x1C)      /* (PAC_INTFLAGC) Peripheral interrupt flag status - Bridge C Offset */
#define PAC_STATUSA_REG_OFST           _UINT32_(0x34)      /* (PAC_STATUSA) Peripheral write protection status - Bridge A Offset */
#define PAC_STATUSB_REG_OFST           _UINT32_(0x38)      /* (PAC_STATUSB) Peripheral write protection status - Bridge B Offset */
#define PAC_STATUSC_REG_OFST           _UINT32_(0x3C)      /* (PAC_STATUSC) Peripheral write protection status - Bridge C Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PAC register API structure */
typedef struct
{  /* Peripheral Access Controller */
  __IO  uint32_t                       PAC_WRCTRL;         /**< Offset: 0x00 (R/W  32) Write control */
  __IO  uint8_t                        PAC_EVCTRL;         /**< Offset: 0x04 (R/W  8) Event control */
  __I   uint8_t                        Reserved1[0x03];
  __IO  uint8_t                        PAC_INTENCLR;       /**< Offset: 0x08 (R/W  8) Interrupt enable clear */
  __IO  uint8_t                        PAC_INTENSET;       /**< Offset: 0x09 (R/W  8) Interrupt enable set */
  __I   uint8_t                        Reserved2[0x06];
  __IO  uint32_t                       PAC_INTFLAGAHB;     /**< Offset: 0x10 (R/W  32) Bridge interrupt flag status */
  __IO  uint32_t                       PAC_INTFLAGA;       /**< Offset: 0x14 (R/W  32) Peripheral interrupt flag status - Bridge A */
  __IO  uint32_t                       PAC_INTFLAGB;       /**< Offset: 0x18 (R/W  32) Peripheral interrupt flag status - Bridge B */
  __IO  uint32_t                       PAC_INTFLAGC;       /**< Offset: 0x1C (R/W  32) Peripheral interrupt flag status - Bridge C */
  __I   uint8_t                        Reserved3[0x14];
  __I   uint32_t                       PAC_STATUSA;        /**< Offset: 0x34 (R/   32) Peripheral write protection status - Bridge A */
  __I   uint32_t                       PAC_STATUSB;        /**< Offset: 0x38 (R/   32) Peripheral write protection status - Bridge B */
  __I   uint32_t                       PAC_STATUSC;        /**< Offset: 0x3C (R/   32) Peripheral write protection status - Bridge C */
} pac_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_PAC_COMPONENT_H_ */
