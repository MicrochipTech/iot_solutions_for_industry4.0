/*
 * Component description for PMU
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
#ifndef _BZ45_PMU_COMPONENT_H_
#define _BZ45_PMU_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PMU                                          */
/* ************************************************************************** */

/* -------- PMU_SPICTRL : (PMU Offset: 0x00) (R/W 32)  -------- */
#define PMU_SPICTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_SPICTRL)   Reset Value */

#define PMU_SPICTRL_SPIWDATA_Pos              _UINT32_(0)                                          /* (PMU_SPICTRL)  Position */
#define PMU_SPICTRL_SPIWDATA_Msk              (_UINT32_(0xFFFF) << PMU_SPICTRL_SPIWDATA_Pos)       /* (PMU_SPICTRL)  Mask */
#define PMU_SPICTRL_SPIWDATA(value)           (PMU_SPICTRL_SPIWDATA_Msk & (_UINT32_(value) << PMU_SPICTRL_SPIWDATA_Pos)) /* Assigment of value for SPIWDATA in the PMU_SPICTRL register */
#define PMU_SPICTRL_SPIADDR_Pos               _UINT32_(16)                                         /* (PMU_SPICTRL)  Position */
#define PMU_SPICTRL_SPIADDR_Msk               (_UINT32_(0xFF) << PMU_SPICTRL_SPIADDR_Pos)          /* (PMU_SPICTRL)  Mask */
#define PMU_SPICTRL_SPIADDR(value)            (PMU_SPICTRL_SPIADDR_Msk & (_UINT32_(value) << PMU_SPICTRL_SPIADDR_Pos)) /* Assigment of value for SPIADDR in the PMU_SPICTRL register */
#define PMU_SPICTRL_CMD_Pos                   _UINT32_(24)                                         /* (PMU_SPICTRL)  Position */
#define PMU_SPICTRL_CMD_Msk                   (_UINT32_(0x1) << PMU_SPICTRL_CMD_Pos)               /* (PMU_SPICTRL)  Mask */
#define PMU_SPICTRL_CMD(value)                (PMU_SPICTRL_CMD_Msk & (_UINT32_(value) << PMU_SPICTRL_CMD_Pos)) /* Assigment of value for CMD in the PMU_SPICTRL register */
#define PMU_SPICTRL_PMUCRST_Pos               _UINT32_(30)                                         /* (PMU_SPICTRL)  Position */
#define PMU_SPICTRL_PMUCRST_Msk               (_UINT32_(0x1) << PMU_SPICTRL_PMUCRST_Pos)           /* (PMU_SPICTRL)  Mask */
#define PMU_SPICTRL_PMUCRST(value)            (PMU_SPICTRL_PMUCRST_Msk & (_UINT32_(value) << PMU_SPICTRL_PMUCRST_Pos)) /* Assigment of value for PMUCRST in the PMU_SPICTRL register */
#define PMU_SPICTRL_SPIRST_Pos                _UINT32_(31)                                         /* (PMU_SPICTRL)  Position */
#define PMU_SPICTRL_SPIRST_Msk                (_UINT32_(0x1) << PMU_SPICTRL_SPIRST_Pos)            /* (PMU_SPICTRL)  Mask */
#define PMU_SPICTRL_SPIRST(value)             (PMU_SPICTRL_SPIRST_Msk & (_UINT32_(value) << PMU_SPICTRL_SPIRST_Pos)) /* Assigment of value for SPIRST in the PMU_SPICTRL register */
#define PMU_SPICTRL_Msk                       _UINT32_(0xC1FFFFFF)                                 /* (PMU_SPICTRL) Register Mask  */


/* -------- PMU_SPISTATUS : (PMU Offset: 0x04) (R/W 32)  -------- */
#define PMU_SPISTATUS_RESETVALUE              _UINT32_(0x00)                                       /*  (PMU_SPISTATUS)   Reset Value */

#define PMU_SPISTATUS_SPIERR_Pos              _UINT32_(0)                                          /* (PMU_SPISTATUS)  Position */
#define PMU_SPISTATUS_SPIERR_Msk              (_UINT32_(0x1) << PMU_SPISTATUS_SPIERR_Pos)          /* (PMU_SPISTATUS)  Mask */
#define PMU_SPISTATUS_SPIERR(value)           (PMU_SPISTATUS_SPIERR_Msk & (_UINT32_(value) << PMU_SPISTATUS_SPIERR_Pos)) /* Assigment of value for SPIERR in the PMU_SPISTATUS register */
#define PMU_SPISTATUS_SPIRDY_Pos              _UINT32_(7)                                          /* (PMU_SPISTATUS)  Position */
#define PMU_SPISTATUS_SPIRDY_Msk              (_UINT32_(0x1) << PMU_SPISTATUS_SPIRDY_Pos)          /* (PMU_SPISTATUS)  Mask */
#define PMU_SPISTATUS_SPIRDY(value)           (PMU_SPISTATUS_SPIRDY_Msk & (_UINT32_(value) << PMU_SPISTATUS_SPIRDY_Pos)) /* Assigment of value for SPIRDY in the PMU_SPISTATUS register */
#define PMU_SPISTATUS_SPIADDR_Pos             _UINT32_(8)                                          /* (PMU_SPISTATUS)  Position */
#define PMU_SPISTATUS_SPIADDR_Msk             (_UINT32_(0xFF) << PMU_SPISTATUS_SPIADDR_Pos)        /* (PMU_SPISTATUS)  Mask */
#define PMU_SPISTATUS_SPIADDR(value)          (PMU_SPISTATUS_SPIADDR_Msk & (_UINT32_(value) << PMU_SPISTATUS_SPIADDR_Pos)) /* Assigment of value for SPIADDR in the PMU_SPISTATUS register */
#define PMU_SPISTATUS_SPIRDATA_Pos            _UINT32_(16)                                         /* (PMU_SPISTATUS)  Position */
#define PMU_SPISTATUS_SPIRDATA_Msk            (_UINT32_(0xFFFF) << PMU_SPISTATUS_SPIRDATA_Pos)     /* (PMU_SPISTATUS)  Mask */
#define PMU_SPISTATUS_SPIRDATA(value)         (PMU_SPISTATUS_SPIRDATA_Msk & (_UINT32_(value) << PMU_SPISTATUS_SPIRDATA_Pos)) /* Assigment of value for SPIRDATA in the PMU_SPISTATUS register */
#define PMU_SPISTATUS_Msk                     _UINT32_(0xFFFFFF81)                                 /* (PMU_SPISTATUS) Register Mask  */


/* -------- PMU_CLKCTRL : (PMU Offset: 0x08) (R/W 32)  -------- */
#define PMU_CLKCTRL_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_CLKCTRL)   Reset Value */

#define PMU_CLKCTRL_SPICLKDIV_Pos             _UINT32_(0)                                          /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_SPICLKDIV_Msk             (_UINT32_(0x3F) << PMU_CLKCTRL_SPICLKDIV_Pos)        /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_SPICLKDIV(value)          (PMU_CLKCTRL_SPICLKDIV_Msk & (_UINT32_(value) << PMU_CLKCTRL_SPICLKDIV_Pos)) /* Assigment of value for SPICLKDIV in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_PMUANA_BKBOREN_Pos        _UINT32_(6)                                          /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_PMUANA_BKBOREN_Msk        (_UINT32_(0x1) << PMU_CLKCTRL_PMUANA_BKBOREN_Pos)    /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_PMUANA_BKBOREN(value)     (PMU_CLKCTRL_PMUANA_BKBOREN_Msk & (_UINT32_(value) << PMU_CLKCTRL_PMUANA_BKBOREN_Pos)) /* Assigment of value for PMUANA_BKBOREN in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_SPISRC_Pos                _UINT32_(7)                                          /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_SPISRC_Msk                (_UINT32_(0x1) << PMU_CLKCTRL_SPISRC_Pos)            /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_SPISRC(value)             (PMU_CLKCTRL_SPISRC_Msk & (_UINT32_(value) << PMU_CLKCTRL_SPISRC_Pos)) /* Assigment of value for SPISRC in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_BUCKCLKDIV_Pos            _UINT32_(8)                                          /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_BUCKCLKDIV_Msk            (_UINT32_(0x3F) << PMU_CLKCTRL_BUCKCLKDIV_Pos)       /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_BUCKCLKDIV(value)         (PMU_CLKCTRL_BUCKCLKDIV_Msk & (_UINT32_(value) << PMU_CLKCTRL_BUCKCLKDIV_Pos)) /* Assigment of value for BUCKCLKDIV in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_BUCKSRC_Pos               _UINT32_(14)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_BUCKSRC_Msk               (_UINT32_(0x3) << PMU_CLKCTRL_BUCKSRC_Pos)           /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_BUCKSRC(value)            (PMU_CLKCTRL_BUCKSRC_Msk & (_UINT32_(value) << PMU_CLKCTRL_BUCKSRC_Pos)) /* Assigment of value for BUCKSRC in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_BACWD_Pos                 _UINT32_(16)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_BACWD_Msk                 (_UINT32_(0x1) << PMU_CLKCTRL_BACWD_Pos)             /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_BACWD(value)              (PMU_CLKCTRL_BACWD_Msk & (_UINT32_(value) << PMU_CLKCTRL_BACWD_Pos)) /* Assigment of value for BACWD in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_MLDOEXTEN_Pos             _UINT32_(17)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_MLDOEXTEN_Msk             (_UINT32_(0x1) << PMU_CLKCTRL_MLDOEXTEN_Pos)         /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_MLDOEXTEN(value)          (PMU_CLKCTRL_MLDOEXTEN_Msk & (_UINT32_(value) << PMU_CLKCTRL_MLDOEXTEN_Pos)) /* Assigment of value for MLDOEXTEN in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_MVREFFSMEN_Pos            _UINT32_(18)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_MVREFFSMEN_Msk            (_UINT32_(0x1) << PMU_CLKCTRL_MVREFFSMEN_Pos)        /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_MVREFFSMEN(value)         (PMU_CLKCTRL_MVREFFSMEN_Msk & (_UINT32_(value) << PMU_CLKCTRL_MVREFFSMEN_Pos)) /* Assigment of value for MVREFFSMEN in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_CMP_CYCLE_Pos             _UINT32_(20)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_CMP_CYCLE_Msk             (_UINT32_(0xF) << PMU_CLKCTRL_CMP_CYCLE_Pos)         /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_CMP_CYCLE(value)          (PMU_CLKCTRL_CMP_CYCLE_Msk & (_UINT32_(value) << PMU_CLKCTRL_CMP_CYCLE_Pos)) /* Assigment of value for CMP_CYCLE in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_BKCLK_HW_OVR_Pos          _UINT32_(24)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_BKCLK_HW_OVR_Msk          (_UINT32_(0x1) << PMU_CLKCTRL_BKCLK_HW_OVR_Pos)      /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_BKCLK_HW_OVR(value)       (PMU_CLKCTRL_BKCLK_HW_OVR_Msk & (_UINT32_(value) << PMU_CLKCTRL_BKCLK_HW_OVR_Pos)) /* Assigment of value for BKCLK_HW_OVR in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_MLDOEXT_BOREN_Pos         _UINT32_(26)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_MLDOEXT_BOREN_Msk         (_UINT32_(0x1) << PMU_CLKCTRL_MLDOEXT_BOREN_Pos)     /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_MLDOEXT_BOREN(value)      (PMU_CLKCTRL_MLDOEXT_BOREN_Msk & (_UINT32_(value) << PMU_CLKCTRL_MLDOEXT_BOREN_Pos)) /* Assigment of value for MLDOEXT_BOREN in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_ADCBOREN_Pos              _UINT32_(27)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_ADCBOREN_Msk              (_UINT32_(0x1) << PMU_CLKCTRL_ADCBOREN_Pos)          /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_ADCBOREN(value)           (PMU_CLKCTRL_ADCBOREN_Msk & (_UINT32_(value) << PMU_CLKCTRL_ADCBOREN_Pos)) /* Assigment of value for ADCBOREN in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_BUCKBOREN_Pos             _UINT32_(28)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_BUCKBOREN_Msk             (_UINT32_(0x1) << PMU_CLKCTRL_BUCKBOREN_Pos)         /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_BUCKBOREN(value)          (PMU_CLKCTRL_BUCKBOREN_Msk & (_UINT32_(value) << PMU_CLKCTRL_BUCKBOREN_Pos)) /* Assigment of value for BUCKBOREN in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_F_BCLK_CFG_Pos            _UINT32_(29)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_F_BCLK_CFG_Msk            (_UINT32_(0x1) << PMU_CLKCTRL_F_BCLK_CFG_Pos)        /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_F_BCLK_CFG(value)         (PMU_CLKCTRL_F_BCLK_CFG_Msk & (_UINT32_(value) << PMU_CLKCTRL_F_BCLK_CFG_Pos)) /* Assigment of value for F_BCLK_CFG in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_WLDOOFF_Pos               _UINT32_(30)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_WLDOOFF_Msk               (_UINT32_(0x1) << PMU_CLKCTRL_WLDOOFF_Pos)           /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_WLDOOFF(value)            (PMU_CLKCTRL_WLDOOFF_Msk & (_UINT32_(value) << PMU_CLKCTRL_WLDOOFF_Pos)) /* Assigment of value for WLDOOFF in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_WCMRET_Pos                _UINT32_(31)                                         /* (PMU_CLKCTRL)  Position */
#define PMU_CLKCTRL_WCMRET_Msk                (_UINT32_(0x1) << PMU_CLKCTRL_WCMRET_Pos)            /* (PMU_CLKCTRL)  Mask */
#define PMU_CLKCTRL_WCMRET(value)             (PMU_CLKCTRL_WCMRET_Msk & (_UINT32_(value) << PMU_CLKCTRL_WCMRET_Pos)) /* Assigment of value for WCMRET in the PMU_CLKCTRL register */
#define PMU_CLKCTRL_Msk                       _UINT32_(0xFDF7FFFF)                                 /* (PMU_CLKCTRL) Register Mask  */


/* -------- PMU_MODECTRL1 : (PMU Offset: 0x0C) (R/W 32)  -------- */
#define PMU_MODECTRL1_RESETVALUE              _UINT32_(0x00)                                       /*  (PMU_MODECTRL1)   Reset Value */

#define PMU_MODECTRL1_VREG4CTRL_Pos           _UINT32_(0)                                          /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_VREG4CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL1_VREG4CTRL_Pos)      /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_VREG4CTRL(value)        (PMU_MODECTRL1_VREG4CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL1_VREG4CTRL_Pos)) /* Assigment of value for VREG4CTRL in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_VREG3CTRL_Pos           _UINT32_(8)                                          /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_VREG3CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL1_VREG3CTRL_Pos)      /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_VREG3CTRL(value)        (PMU_MODECTRL1_VREG3CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL1_VREG3CTRL_Pos)) /* Assigment of value for VREG3CTRL in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_VREG2CTRL_Pos           _UINT32_(16)                                         /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_VREG2CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL1_VREG2CTRL_Pos)      /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_VREG2CTRL(value)        (PMU_MODECTRL1_VREG2CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL1_VREG2CTRL_Pos)) /* Assigment of value for VREG2CTRL in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_VREG1CTRL_Pos           _UINT32_(24)                                         /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_VREG1CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL1_VREG1CTRL_Pos)      /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_VREG1CTRL(value)        (PMU_MODECTRL1_VREG1CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL1_VREG1CTRL_Pos)) /* Assigment of value for VREG1CTRL in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_BUCKMODE_Pos            _UINT32_(29)                                         /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_BUCKMODE_Msk            (_UINT32_(0x1) << PMU_MODECTRL1_BUCKMODE_Pos)        /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_BUCKMODE(value)         (PMU_MODECTRL1_BUCKMODE_Msk & (_UINT32_(value) << PMU_MODECTRL1_BUCKMODE_Pos)) /* Assigment of value for BUCKMODE in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_MLDOEN_Pos              _UINT32_(30)                                         /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_MLDOEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL1_MLDOEN_Pos)          /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_MLDOEN(value)           (PMU_MODECTRL1_MLDOEN_Msk & (_UINT32_(value) << PMU_MODECTRL1_MLDOEN_Pos)) /* Assigment of value for MLDOEN in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_BUCKEN_Pos              _UINT32_(31)                                         /* (PMU_MODECTRL1)  Position */
#define PMU_MODECTRL1_BUCKEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL1_BUCKEN_Pos)          /* (PMU_MODECTRL1)  Mask */
#define PMU_MODECTRL1_BUCKEN(value)           (PMU_MODECTRL1_BUCKEN_Msk & (_UINT32_(value) << PMU_MODECTRL1_BUCKEN_Pos)) /* Assigment of value for BUCKEN in the PMU_MODECTRL1 register */
#define PMU_MODECTRL1_Msk                     _UINT32_(0xFF1F1F1F)                                 /* (PMU_MODECTRL1) Register Mask  */


/* -------- PMU_MODECTRL2 : (PMU Offset: 0x10) (R/W 32)  -------- */
#define PMU_MODECTRL2_RESETVALUE              _UINT32_(0x00)                                       /*  (PMU_MODECTRL2)   Reset Value */

#define PMU_MODECTRL2_VREG4CTRL_Pos           _UINT32_(0)                                          /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_VREG4CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL2_VREG4CTRL_Pos)      /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_VREG4CTRL(value)        (PMU_MODECTRL2_VREG4CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL2_VREG4CTRL_Pos)) /* Assigment of value for VREG4CTRL in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_VREG3CTRL_Pos           _UINT32_(8)                                          /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_VREG3CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL2_VREG3CTRL_Pos)      /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_VREG3CTRL(value)        (PMU_MODECTRL2_VREG3CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL2_VREG3CTRL_Pos)) /* Assigment of value for VREG3CTRL in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_VREG2CTRL_Pos           _UINT32_(16)                                         /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_VREG2CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL2_VREG2CTRL_Pos)      /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_VREG2CTRL(value)        (PMU_MODECTRL2_VREG2CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL2_VREG2CTRL_Pos)) /* Assigment of value for VREG2CTRL in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_VREG1CTRL_Pos           _UINT32_(24)                                         /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_VREG1CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL2_VREG1CTRL_Pos)      /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_VREG1CTRL(value)        (PMU_MODECTRL2_VREG1CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL2_VREG1CTRL_Pos)) /* Assigment of value for VREG1CTRL in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_BUCKMODE_Pos            _UINT32_(29)                                         /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_BUCKMODE_Msk            (_UINT32_(0x1) << PMU_MODECTRL2_BUCKMODE_Pos)        /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_BUCKMODE(value)         (PMU_MODECTRL2_BUCKMODE_Msk & (_UINT32_(value) << PMU_MODECTRL2_BUCKMODE_Pos)) /* Assigment of value for BUCKMODE in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_MLDOEN_Pos              _UINT32_(30)                                         /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_MLDOEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL2_MLDOEN_Pos)          /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_MLDOEN(value)           (PMU_MODECTRL2_MLDOEN_Msk & (_UINT32_(value) << PMU_MODECTRL2_MLDOEN_Pos)) /* Assigment of value for MLDOEN in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_BUCKEN_Pos              _UINT32_(31)                                         /* (PMU_MODECTRL2)  Position */
#define PMU_MODECTRL2_BUCKEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL2_BUCKEN_Pos)          /* (PMU_MODECTRL2)  Mask */
#define PMU_MODECTRL2_BUCKEN(value)           (PMU_MODECTRL2_BUCKEN_Msk & (_UINT32_(value) << PMU_MODECTRL2_BUCKEN_Pos)) /* Assigment of value for BUCKEN in the PMU_MODECTRL2 register */
#define PMU_MODECTRL2_Msk                     _UINT32_(0xFF1F1F1F)                                 /* (PMU_MODECTRL2) Register Mask  */


/* -------- PMU_MODECTRL3 : (PMU Offset: 0x14) (R/W 32)  -------- */
#define PMU_MODECTRL3_RESETVALUE              _UINT32_(0x00)                                       /*  (PMU_MODECTRL3)   Reset Value */

#define PMU_MODECTRL3_VREG4CTRL_Pos           _UINT32_(0)                                          /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_VREG4CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL3_VREG4CTRL_Pos)      /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_VREG4CTRL(value)        (PMU_MODECTRL3_VREG4CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL3_VREG4CTRL_Pos)) /* Assigment of value for VREG4CTRL in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_VREG3CTRL_Pos           _UINT32_(8)                                          /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_VREG3CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL3_VREG3CTRL_Pos)      /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_VREG3CTRL(value)        (PMU_MODECTRL3_VREG3CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL3_VREG3CTRL_Pos)) /* Assigment of value for VREG3CTRL in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_VREG2CTRL_Pos           _UINT32_(16)                                         /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_VREG2CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL3_VREG2CTRL_Pos)      /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_VREG2CTRL(value)        (PMU_MODECTRL3_VREG2CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL3_VREG2CTRL_Pos)) /* Assigment of value for VREG2CTRL in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_VREG1CTRL_Pos           _UINT32_(24)                                         /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_VREG1CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL3_VREG1CTRL_Pos)      /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_VREG1CTRL(value)        (PMU_MODECTRL3_VREG1CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL3_VREG1CTRL_Pos)) /* Assigment of value for VREG1CTRL in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_BUCKMODE_Pos            _UINT32_(29)                                         /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_BUCKMODE_Msk            (_UINT32_(0x1) << PMU_MODECTRL3_BUCKMODE_Pos)        /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_BUCKMODE(value)         (PMU_MODECTRL3_BUCKMODE_Msk & (_UINT32_(value) << PMU_MODECTRL3_BUCKMODE_Pos)) /* Assigment of value for BUCKMODE in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_MLDOEN_Pos              _UINT32_(30)                                         /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_MLDOEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL3_MLDOEN_Pos)          /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_MLDOEN(value)           (PMU_MODECTRL3_MLDOEN_Msk & (_UINT32_(value) << PMU_MODECTRL3_MLDOEN_Pos)) /* Assigment of value for MLDOEN in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_BUCKEN_Pos              _UINT32_(31)                                         /* (PMU_MODECTRL3)  Position */
#define PMU_MODECTRL3_BUCKEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL3_BUCKEN_Pos)          /* (PMU_MODECTRL3)  Mask */
#define PMU_MODECTRL3_BUCKEN(value)           (PMU_MODECTRL3_BUCKEN_Msk & (_UINT32_(value) << PMU_MODECTRL3_BUCKEN_Pos)) /* Assigment of value for BUCKEN in the PMU_MODECTRL3 register */
#define PMU_MODECTRL3_Msk                     _UINT32_(0xFF1F1F1F)                                 /* (PMU_MODECTRL3) Register Mask  */


/* -------- PMU_MODECTRL4 : (PMU Offset: 0x18) (R/W 32)  -------- */
#define PMU_MODECTRL4_RESETVALUE              _UINT32_(0x00)                                       /*  (PMU_MODECTRL4)   Reset Value */

#define PMU_MODECTRL4_VREG4CTRL_Pos           _UINT32_(0)                                          /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_VREG4CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL4_VREG4CTRL_Pos)      /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_VREG4CTRL(value)        (PMU_MODECTRL4_VREG4CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL4_VREG4CTRL_Pos)) /* Assigment of value for VREG4CTRL in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_VREG3CTRL_Pos           _UINT32_(8)                                          /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_VREG3CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL4_VREG3CTRL_Pos)      /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_VREG3CTRL(value)        (PMU_MODECTRL4_VREG3CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL4_VREG3CTRL_Pos)) /* Assigment of value for VREG3CTRL in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_VREG2CTRL_Pos           _UINT32_(16)                                         /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_VREG2CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL4_VREG2CTRL_Pos)      /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_VREG2CTRL(value)        (PMU_MODECTRL4_VREG2CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL4_VREG2CTRL_Pos)) /* Assigment of value for VREG2CTRL in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_VREG1CTRL_Pos           _UINT32_(24)                                         /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_VREG1CTRL_Msk           (_UINT32_(0x1F) << PMU_MODECTRL4_VREG1CTRL_Pos)      /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_VREG1CTRL(value)        (PMU_MODECTRL4_VREG1CTRL_Msk & (_UINT32_(value) << PMU_MODECTRL4_VREG1CTRL_Pos)) /* Assigment of value for VREG1CTRL in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_BUCKMODE_Pos            _UINT32_(29)                                         /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_BUCKMODE_Msk            (_UINT32_(0x1) << PMU_MODECTRL4_BUCKMODE_Pos)        /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_BUCKMODE(value)         (PMU_MODECTRL4_BUCKMODE_Msk & (_UINT32_(value) << PMU_MODECTRL4_BUCKMODE_Pos)) /* Assigment of value for BUCKMODE in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_MLDOEN_Pos              _UINT32_(30)                                         /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_MLDOEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL4_MLDOEN_Pos)          /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_MLDOEN(value)           (PMU_MODECTRL4_MLDOEN_Msk & (_UINT32_(value) << PMU_MODECTRL4_MLDOEN_Pos)) /* Assigment of value for MLDOEN in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_BUCKEN_Pos              _UINT32_(31)                                         /* (PMU_MODECTRL4)  Position */
#define PMU_MODECTRL4_BUCKEN_Msk              (_UINT32_(0x1) << PMU_MODECTRL4_BUCKEN_Pos)          /* (PMU_MODECTRL4)  Mask */
#define PMU_MODECTRL4_BUCKEN(value)           (PMU_MODECTRL4_BUCKEN_Msk & (_UINT32_(value) << PMU_MODECTRL4_BUCKEN_Pos)) /* Assigment of value for BUCKEN in the PMU_MODECTRL4 register */
#define PMU_MODECTRL4_Msk                     _UINT32_(0xFF1F1F1F)                                 /* (PMU_MODECTRL4) Register Mask  */


/* -------- PMU_OVERCTRL : (PMU Offset: 0x1C) (R/W 32)  -------- */
#define PMU_OVERCTRL_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_OVERCTRL)   Reset Value */

#define PMU_OVERCTRL_VREG4OCTRL_Pos           _UINT32_(0)                                          /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_VREG4OCTRL_Msk           (_UINT32_(0x1F) << PMU_OVERCTRL_VREG4OCTRL_Pos)      /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_VREG4OCTRL(value)        (PMU_OVERCTRL_VREG4OCTRL_Msk & (_UINT32_(value) << PMU_OVERCTRL_VREG4OCTRL_Pos)) /* Assigment of value for VREG4OCTRL in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_VREG3OCTRL_Pos           _UINT32_(8)                                          /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_VREG3OCTRL_Msk           (_UINT32_(0x1F) << PMU_OVERCTRL_VREG3OCTRL_Pos)      /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_VREG3OCTRL(value)        (PMU_OVERCTRL_VREG3OCTRL_Msk & (_UINT32_(value) << PMU_OVERCTRL_VREG3OCTRL_Pos)) /* Assigment of value for VREG3OCTRL in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_VREG2OCTRL_Pos           _UINT32_(16)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_VREG2OCTRL_Msk           (_UINT32_(0x1F) << PMU_OVERCTRL_VREG2OCTRL_Pos)      /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_VREG2OCTRL(value)        (PMU_OVERCTRL_VREG2OCTRL_Msk & (_UINT32_(value) << PMU_OVERCTRL_VREG2OCTRL_Pos)) /* Assigment of value for VREG2OCTRL in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_PHWC_Pos                 _UINT32_(22)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_PHWC_Msk                 (_UINT32_(0x1) << PMU_OVERCTRL_PHWC_Pos)             /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_PHWC(value)              (PMU_OVERCTRL_PHWC_Msk & (_UINT32_(value) << PMU_OVERCTRL_PHWC_Pos)) /* Assigment of value for PHWC in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_OVEREN_Pos               _UINT32_(23)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_OVEREN_Msk               (_UINT32_(0x1) << PMU_OVERCTRL_OVEREN_Pos)           /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_OVEREN(value)            (PMU_OVERCTRL_OVEREN_Msk & (_UINT32_(value) << PMU_OVERCTRL_OVEREN_Pos)) /* Assigment of value for OVEREN in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_VREG1OCTRL_Pos           _UINT32_(24)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_VREG1OCTRL_Msk           (_UINT32_(0x1F) << PMU_OVERCTRL_VREG1OCTRL_Pos)      /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_VREG1OCTRL(value)        (PMU_OVERCTRL_VREG1OCTRL_Msk & (_UINT32_(value) << PMU_OVERCTRL_VREG1OCTRL_Pos)) /* Assigment of value for VREG1OCTRL in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_OBUCKMODE_Pos            _UINT32_(29)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_OBUCKMODE_Msk            (_UINT32_(0x1) << PMU_OVERCTRL_OBUCKMODE_Pos)        /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_OBUCKMODE(value)         (PMU_OVERCTRL_OBUCKMODE_Msk & (_UINT32_(value) << PMU_OVERCTRL_OBUCKMODE_Pos)) /* Assigment of value for OBUCKMODE in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_OMLDOEN_Pos              _UINT32_(30)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_OMLDOEN_Msk              (_UINT32_(0x1) << PMU_OVERCTRL_OMLDOEN_Pos)          /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_OMLDOEN(value)           (PMU_OVERCTRL_OMLDOEN_Msk & (_UINT32_(value) << PMU_OVERCTRL_OMLDOEN_Pos)) /* Assigment of value for OMLDOEN in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_OBUCKEN_Pos              _UINT32_(31)                                         /* (PMU_OVERCTRL)  Position */
#define PMU_OVERCTRL_OBUCKEN_Msk              (_UINT32_(0x1) << PMU_OVERCTRL_OBUCKEN_Pos)          /* (PMU_OVERCTRL)  Mask */
#define PMU_OVERCTRL_OBUCKEN(value)           (PMU_OVERCTRL_OBUCKEN_Msk & (_UINT32_(value) << PMU_OVERCTRL_OBUCKEN_Pos)) /* Assigment of value for OBUCKEN in the PMU_OVERCTRL register */
#define PMU_OVERCTRL_Msk                      _UINT32_(0xFFDF1F1F)                                 /* (PMU_OVERCTRL) Register Mask  */


/* -------- PMU_PMUCMODE : (PMU Offset: 0x20) (R/W 32)  -------- */
#define PMU_PMUCMODE_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_PMUCMODE)   Reset Value */

#define PMU_PMUCMODE_CVREG4OCTRL_Pos          _UINT32_(0)                                          /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CVREG4OCTRL_Msk          (_UINT32_(0x1F) << PMU_PMUCMODE_CVREG4OCTRL_Pos)     /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CVREG4OCTRL(value)       (PMU_PMUCMODE_CVREG4OCTRL_Msk & (_UINT32_(value) << PMU_PMUCMODE_CVREG4OCTRL_Pos)) /* Assigment of value for CVREG4OCTRL in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_CVREG3OCTRL_Pos          _UINT32_(8)                                          /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CVREG3OCTRL_Msk          (_UINT32_(0x1F) << PMU_PMUCMODE_CVREG3OCTRL_Pos)     /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CVREG3OCTRL(value)       (PMU_PMUCMODE_CVREG3OCTRL_Msk & (_UINT32_(value) << PMU_PMUCMODE_CVREG3OCTRL_Pos)) /* Assigment of value for CVREG3OCTRL in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_CVREG2OCTROL_Pos         _UINT32_(16)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CVREG2OCTROL_Msk         (_UINT32_(0x1F) << PMU_PMUCMODE_CVREG2OCTROL_Pos)    /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CVREG2OCTROL(value)      (PMU_PMUCMODE_CVREG2OCTROL_Msk & (_UINT32_(value) << PMU_PMUCMODE_CVREG2OCTROL_Pos)) /* Assigment of value for CVREG2OCTROL in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_ADCBOR_Pos               _UINT32_(21)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_ADCBOR_Msk               (_UINT32_(0x1) << PMU_PMUCMODE_ADCBOR_Pos)           /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_ADCBOR(value)            (PMU_PMUCMODE_ADCBOR_Msk & (_UINT32_(value) << PMU_PMUCMODE_ADCBOR_Pos)) /* Assigment of value for ADCBOR in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_BUCKBOR_Pos              _UINT32_(22)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_BUCKBOR_Msk              (_UINT32_(0x1) << PMU_PMUCMODE_BUCKBOR_Pos)          /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_BUCKBOR(value)           (PMU_PMUCMODE_BUCKBOR_Msk & (_UINT32_(value) << PMU_PMUCMODE_BUCKBOR_Pos)) /* Assigment of value for BUCKBOR in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_MLDOEXTBOR_Pos           _UINT32_(23)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_MLDOEXTBOR_Msk           (_UINT32_(0x1) << PMU_PMUCMODE_MLDOEXTBOR_Pos)       /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_MLDOEXTBOR(value)        (PMU_PMUCMODE_MLDOEXTBOR_Msk & (_UINT32_(value) << PMU_PMUCMODE_MLDOEXTBOR_Pos)) /* Assigment of value for MLDOEXTBOR in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_CVREG1OCTRL_Pos          _UINT32_(24)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CVREG1OCTRL_Msk          (_UINT32_(0x1F) << PMU_PMUCMODE_CVREG1OCTRL_Pos)     /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CVREG1OCTRL(value)       (PMU_PMUCMODE_CVREG1OCTRL_Msk & (_UINT32_(value) << PMU_PMUCMODE_CVREG1OCTRL_Pos)) /* Assigment of value for CVREG1OCTRL in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_CBUCKMODE_Pos            _UINT32_(29)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CBUCKMODE_Msk            (_UINT32_(0x1) << PMU_PMUCMODE_CBUCKMODE_Pos)        /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CBUCKMODE(value)         (PMU_PMUCMODE_CBUCKMODE_Msk & (_UINT32_(value) << PMU_PMUCMODE_CBUCKMODE_Pos)) /* Assigment of value for CBUCKMODE in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_CMLDOEN_Pos              _UINT32_(30)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CMLDOEN_Msk              (_UINT32_(0x1) << PMU_PMUCMODE_CMLDOEN_Pos)          /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CMLDOEN(value)           (PMU_PMUCMODE_CMLDOEN_Msk & (_UINT32_(value) << PMU_PMUCMODE_CMLDOEN_Pos)) /* Assigment of value for CMLDOEN in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_CBUCKEN_Pos              _UINT32_(31)                                         /* (PMU_PMUCMODE)  Position */
#define PMU_PMUCMODE_CBUCKEN_Msk              (_UINT32_(0x1) << PMU_PMUCMODE_CBUCKEN_Pos)          /* (PMU_PMUCMODE)  Mask */
#define PMU_PMUCMODE_CBUCKEN(value)           (PMU_PMUCMODE_CBUCKEN_Msk & (_UINT32_(value) << PMU_PMUCMODE_CBUCKEN_Pos)) /* Assigment of value for CBUCKEN in the PMU_PMUCMODE register */
#define PMU_PMUCMODE_Msk                      _UINT32_(0xFFFF1F1F)                                 /* (PMU_PMUCMODE) Register Mask  */


/* -------- PMU_PMUSTATUS : (PMU Offset: 0x24) (R/W 32)  -------- */
#define PMU_PMUSTATUS_RESETVALUE              _UINT32_(0x00)                                       /*  (PMU_PMUSTATUS)   Reset Value */

#define PMU_PMUSTATUS_PMUSTATUS_Pos           _UINT32_(0)                                          /* (PMU_PMUSTATUS)  Position */
#define PMU_PMUSTATUS_PMUSTATUS_Msk           (_UINT32_(0x1F) << PMU_PMUSTATUS_PMUSTATUS_Pos)      /* (PMU_PMUSTATUS)  Mask */
#define PMU_PMUSTATUS_PMUSTATUS(value)        (PMU_PMUSTATUS_PMUSTATUS_Msk & (_UINT32_(value) << PMU_PMUSTATUS_PMUSTATUS_Pos)) /* Assigment of value for PMUSTATUS in the PMU_PMUSTATUS register */
#define PMU_PMUSTATUS_WCMRM_Pos               _UINT32_(5)                                          /* (PMU_PMUSTATUS)  Position */
#define PMU_PMUSTATUS_WCMRM_Msk               (_UINT32_(0x1) << PMU_PMUSTATUS_WCMRM_Pos)           /* (PMU_PMUSTATUS)  Mask */
#define PMU_PMUSTATUS_WCMRM(value)            (PMU_PMUSTATUS_WCMRM_Msk & (_UINT32_(value) << PMU_PMUSTATUS_WCMRM_Pos)) /* Assigment of value for WCMRM in the PMU_PMUSTATUS register */
#define PMU_PMUSTATUS_PMUANA_BUCKBOR_Pos      _UINT32_(6)                                          /* (PMU_PMUSTATUS)  Position */
#define PMU_PMUSTATUS_PMUANA_BUCKBOR_Msk      (_UINT32_(0x1) << PMU_PMUSTATUS_PMUANA_BUCKBOR_Pos)  /* (PMU_PMUSTATUS)  Mask */
#define PMU_PMUSTATUS_PMUANA_BUCKBOR(value)   (PMU_PMUSTATUS_PMUANA_BUCKBOR_Msk & (_UINT32_(value) << PMU_PMUSTATUS_PMUANA_BUCKBOR_Pos)) /* Assigment of value for PMUANA_BUCKBOR in the PMU_PMUSTATUS register */
#define PMU_PMUSTATUS_BSSEDATA_Pos            _UINT32_(8)                                          /* (PMU_PMUSTATUS)  Position */
#define PMU_PMUSTATUS_BSSEDATA_Msk            (_UINT32_(0xFFFF) << PMU_PMUSTATUS_BSSEDATA_Pos)     /* (PMU_PMUSTATUS)  Mask */
#define PMU_PMUSTATUS_BSSEDATA(value)         (PMU_PMUSTATUS_BSSEDATA_Msk & (_UINT32_(value) << PMU_PMUSTATUS_BSSEDATA_Pos)) /* Assigment of value for BSSEDATA in the PMU_PMUSTATUS register */
#define PMU_PMUSTATUS_BSSENUM_Pos             _UINT32_(24)                                         /* (PMU_PMUSTATUS)  Position */
#define PMU_PMUSTATUS_BSSENUM_Msk             (_UINT32_(0x7F) << PMU_PMUSTATUS_BSSENUM_Pos)        /* (PMU_PMUSTATUS)  Mask */
#define PMU_PMUSTATUS_BSSENUM(value)          (PMU_PMUSTATUS_BSSENUM_Msk & (_UINT32_(value) << PMU_PMUSTATUS_BSSENUM_Pos)) /* Assigment of value for BSSENUM in the PMU_PMUSTATUS register */
#define PMU_PMUSTATUS_BSSERR_Pos              _UINT32_(31)                                         /* (PMU_PMUSTATUS)  Position */
#define PMU_PMUSTATUS_BSSERR_Msk              (_UINT32_(0x1) << PMU_PMUSTATUS_BSSERR_Pos)          /* (PMU_PMUSTATUS)  Mask */
#define PMU_PMUSTATUS_BSSERR(value)           (PMU_PMUSTATUS_BSSERR_Msk & (_UINT32_(value) << PMU_PMUSTATUS_BSSERR_Pos)) /* Assigment of value for BSSERR in the PMU_PMUSTATUS register */
#define PMU_PMUSTATUS_Msk                     _UINT32_(0xFFFFFF7F)                                 /* (PMU_PMUSTATUS) Register Mask  */


/* -------- PMU_PMUSEQ1 : (PMU Offset: 0x28) (R/W 32)  -------- */
#define PMU_PMUSEQ1_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_PMUSEQ1)   Reset Value */

#define PMU_PMUSEQ1_DELAY_Pos                 _UINT32_(0)                                          /* (PMU_PMUSEQ1)  Position */
#define PMU_PMUSEQ1_DELAY_Msk                 (_UINT32_(0x3F) << PMU_PMUSEQ1_DELAY_Pos)            /* (PMU_PMUSEQ1)  Mask */
#define PMU_PMUSEQ1_DELAY(value)              (PMU_PMUSEQ1_DELAY_Msk & (_UINT32_(value) << PMU_PMUSEQ1_DELAY_Pos)) /* Assigment of value for DELAY in the PMU_PMUSEQ1 register */
#define PMU_PMUSEQ1_CMPBVAL_Pos               _UINT32_(6)                                          /* (PMU_PMUSEQ1)  Position */
#define PMU_PMUSEQ1_CMPBVAL_Msk               (_UINT32_(0x1) << PMU_PMUSEQ1_CMPBVAL_Pos)           /* (PMU_PMUSEQ1)  Mask */
#define PMU_PMUSEQ1_CMPBVAL(value)            (PMU_PMUSEQ1_CMPBVAL_Msk & (_UINT32_(value) << PMU_PMUSEQ1_CMPBVAL_Pos)) /* Assigment of value for CMPBVAL in the PMU_PMUSEQ1 register */
#define PMU_PMUSEQ1_CMD_Pos                   _UINT32_(7)                                          /* (PMU_PMUSEQ1)  Position */
#define PMU_PMUSEQ1_CMD_Msk                   (_UINT32_(0x1) << PMU_PMUSEQ1_CMD_Pos)               /* (PMU_PMUSEQ1)  Mask */
#define PMU_PMUSEQ1_CMD(value)                (PMU_PMUSEQ1_CMD_Msk & (_UINT32_(value) << PMU_PMUSEQ1_CMD_Pos)) /* Assigment of value for CMD in the PMU_PMUSEQ1 register */
#define PMU_PMUSEQ1_SPIRADDR_Pos              _UINT32_(8)                                          /* (PMU_PMUSEQ1)  Position */
#define PMU_PMUSEQ1_SPIRADDR_Msk              (_UINT32_(0xFF) << PMU_PMUSEQ1_SPIRADDR_Pos)         /* (PMU_PMUSEQ1)  Mask */
#define PMU_PMUSEQ1_SPIRADDR(value)           (PMU_PMUSEQ1_SPIRADDR_Msk & (_UINT32_(value) << PMU_PMUSEQ1_SPIRADDR_Pos)) /* Assigment of value for SPIRADDR in the PMU_PMUSEQ1 register */
#define PMU_PMUSEQ1_SPIDATA_Pos               _UINT32_(16)                                         /* (PMU_PMUSEQ1)  Position */
#define PMU_PMUSEQ1_SPIDATA_Msk               (_UINT32_(0xFFFF) << PMU_PMUSEQ1_SPIDATA_Pos)        /* (PMU_PMUSEQ1)  Mask */
#define PMU_PMUSEQ1_SPIDATA(value)            (PMU_PMUSEQ1_SPIDATA_Msk & (_UINT32_(value) << PMU_PMUSEQ1_SPIDATA_Pos)) /* Assigment of value for SPIDATA in the PMU_PMUSEQ1 register */
#define PMU_PMUSEQ1_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (PMU_PMUSEQ1) Register Mask  */


/* -------- PMU_PMUSEQ2 : (PMU Offset: 0x2C) (R/W 32)  -------- */
#define PMU_PMUSEQ2_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_PMUSEQ2)   Reset Value */

#define PMU_PMUSEQ2_DELAY_Pos                 _UINT32_(0)                                          /* (PMU_PMUSEQ2)  Position */
#define PMU_PMUSEQ2_DELAY_Msk                 (_UINT32_(0x3F) << PMU_PMUSEQ2_DELAY_Pos)            /* (PMU_PMUSEQ2)  Mask */
#define PMU_PMUSEQ2_DELAY(value)              (PMU_PMUSEQ2_DELAY_Msk & (_UINT32_(value) << PMU_PMUSEQ2_DELAY_Pos)) /* Assigment of value for DELAY in the PMU_PMUSEQ2 register */
#define PMU_PMUSEQ2_CMPBVAL_Pos               _UINT32_(6)                                          /* (PMU_PMUSEQ2)  Position */
#define PMU_PMUSEQ2_CMPBVAL_Msk               (_UINT32_(0x1) << PMU_PMUSEQ2_CMPBVAL_Pos)           /* (PMU_PMUSEQ2)  Mask */
#define PMU_PMUSEQ2_CMPBVAL(value)            (PMU_PMUSEQ2_CMPBVAL_Msk & (_UINT32_(value) << PMU_PMUSEQ2_CMPBVAL_Pos)) /* Assigment of value for CMPBVAL in the PMU_PMUSEQ2 register */
#define PMU_PMUSEQ2_CMD_Pos                   _UINT32_(7)                                          /* (PMU_PMUSEQ2)  Position */
#define PMU_PMUSEQ2_CMD_Msk                   (_UINT32_(0x1) << PMU_PMUSEQ2_CMD_Pos)               /* (PMU_PMUSEQ2)  Mask */
#define PMU_PMUSEQ2_CMD(value)                (PMU_PMUSEQ2_CMD_Msk & (_UINT32_(value) << PMU_PMUSEQ2_CMD_Pos)) /* Assigment of value for CMD in the PMU_PMUSEQ2 register */
#define PMU_PMUSEQ2_SPIRADDR_Pos              _UINT32_(8)                                          /* (PMU_PMUSEQ2)  Position */
#define PMU_PMUSEQ2_SPIRADDR_Msk              (_UINT32_(0xFF) << PMU_PMUSEQ2_SPIRADDR_Pos)         /* (PMU_PMUSEQ2)  Mask */
#define PMU_PMUSEQ2_SPIRADDR(value)           (PMU_PMUSEQ2_SPIRADDR_Msk & (_UINT32_(value) << PMU_PMUSEQ2_SPIRADDR_Pos)) /* Assigment of value for SPIRADDR in the PMU_PMUSEQ2 register */
#define PMU_PMUSEQ2_SPIDATA_Pos               _UINT32_(16)                                         /* (PMU_PMUSEQ2)  Position */
#define PMU_PMUSEQ2_SPIDATA_Msk               (_UINT32_(0xFFFF) << PMU_PMUSEQ2_SPIDATA_Pos)        /* (PMU_PMUSEQ2)  Mask */
#define PMU_PMUSEQ2_SPIDATA(value)            (PMU_PMUSEQ2_SPIDATA_Msk & (_UINT32_(value) << PMU_PMUSEQ2_SPIDATA_Pos)) /* Assigment of value for SPIDATA in the PMU_PMUSEQ2 register */
#define PMU_PMUSEQ2_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (PMU_PMUSEQ2) Register Mask  */


/* -------- PMU_PMUSEQ3 : (PMU Offset: 0x30) (R/W 32)  -------- */
#define PMU_PMUSEQ3_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_PMUSEQ3)   Reset Value */

#define PMU_PMUSEQ3_DELAY_Pos                 _UINT32_(0)                                          /* (PMU_PMUSEQ3)  Position */
#define PMU_PMUSEQ3_DELAY_Msk                 (_UINT32_(0x3F) << PMU_PMUSEQ3_DELAY_Pos)            /* (PMU_PMUSEQ3)  Mask */
#define PMU_PMUSEQ3_DELAY(value)              (PMU_PMUSEQ3_DELAY_Msk & (_UINT32_(value) << PMU_PMUSEQ3_DELAY_Pos)) /* Assigment of value for DELAY in the PMU_PMUSEQ3 register */
#define PMU_PMUSEQ3_CMPBVAL_Pos               _UINT32_(6)                                          /* (PMU_PMUSEQ3)  Position */
#define PMU_PMUSEQ3_CMPBVAL_Msk               (_UINT32_(0x1) << PMU_PMUSEQ3_CMPBVAL_Pos)           /* (PMU_PMUSEQ3)  Mask */
#define PMU_PMUSEQ3_CMPBVAL(value)            (PMU_PMUSEQ3_CMPBVAL_Msk & (_UINT32_(value) << PMU_PMUSEQ3_CMPBVAL_Pos)) /* Assigment of value for CMPBVAL in the PMU_PMUSEQ3 register */
#define PMU_PMUSEQ3_CMD_Pos                   _UINT32_(7)                                          /* (PMU_PMUSEQ3)  Position */
#define PMU_PMUSEQ3_CMD_Msk                   (_UINT32_(0x1) << PMU_PMUSEQ3_CMD_Pos)               /* (PMU_PMUSEQ3)  Mask */
#define PMU_PMUSEQ3_CMD(value)                (PMU_PMUSEQ3_CMD_Msk & (_UINT32_(value) << PMU_PMUSEQ3_CMD_Pos)) /* Assigment of value for CMD in the PMU_PMUSEQ3 register */
#define PMU_PMUSEQ3_SPIRADDR_Pos              _UINT32_(8)                                          /* (PMU_PMUSEQ3)  Position */
#define PMU_PMUSEQ3_SPIRADDR_Msk              (_UINT32_(0xFF) << PMU_PMUSEQ3_SPIRADDR_Pos)         /* (PMU_PMUSEQ3)  Mask */
#define PMU_PMUSEQ3_SPIRADDR(value)           (PMU_PMUSEQ3_SPIRADDR_Msk & (_UINT32_(value) << PMU_PMUSEQ3_SPIRADDR_Pos)) /* Assigment of value for SPIRADDR in the PMU_PMUSEQ3 register */
#define PMU_PMUSEQ3_SPIDATA_Pos               _UINT32_(16)                                         /* (PMU_PMUSEQ3)  Position */
#define PMU_PMUSEQ3_SPIDATA_Msk               (_UINT32_(0xFFFF) << PMU_PMUSEQ3_SPIDATA_Pos)        /* (PMU_PMUSEQ3)  Mask */
#define PMU_PMUSEQ3_SPIDATA(value)            (PMU_PMUSEQ3_SPIDATA_Msk & (_UINT32_(value) << PMU_PMUSEQ3_SPIDATA_Pos)) /* Assigment of value for SPIDATA in the PMU_PMUSEQ3 register */
#define PMU_PMUSEQ3_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (PMU_PMUSEQ3) Register Mask  */


/* -------- PMU_PMUSEQ4 : (PMU Offset: 0x34) (R/W 32)  -------- */
#define PMU_PMUSEQ4_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_PMUSEQ4)   Reset Value */

#define PMU_PMUSEQ4_DELAY_Pos                 _UINT32_(0)                                          /* (PMU_PMUSEQ4)  Position */
#define PMU_PMUSEQ4_DELAY_Msk                 (_UINT32_(0x3F) << PMU_PMUSEQ4_DELAY_Pos)            /* (PMU_PMUSEQ4)  Mask */
#define PMU_PMUSEQ4_DELAY(value)              (PMU_PMUSEQ4_DELAY_Msk & (_UINT32_(value) << PMU_PMUSEQ4_DELAY_Pos)) /* Assigment of value for DELAY in the PMU_PMUSEQ4 register */
#define PMU_PMUSEQ4_CMPBVAL_Pos               _UINT32_(6)                                          /* (PMU_PMUSEQ4)  Position */
#define PMU_PMUSEQ4_CMPBVAL_Msk               (_UINT32_(0x1) << PMU_PMUSEQ4_CMPBVAL_Pos)           /* (PMU_PMUSEQ4)  Mask */
#define PMU_PMUSEQ4_CMPBVAL(value)            (PMU_PMUSEQ4_CMPBVAL_Msk & (_UINT32_(value) << PMU_PMUSEQ4_CMPBVAL_Pos)) /* Assigment of value for CMPBVAL in the PMU_PMUSEQ4 register */
#define PMU_PMUSEQ4_CMD_Pos                   _UINT32_(7)                                          /* (PMU_PMUSEQ4)  Position */
#define PMU_PMUSEQ4_CMD_Msk                   (_UINT32_(0x1) << PMU_PMUSEQ4_CMD_Pos)               /* (PMU_PMUSEQ4)  Mask */
#define PMU_PMUSEQ4_CMD(value)                (PMU_PMUSEQ4_CMD_Msk & (_UINT32_(value) << PMU_PMUSEQ4_CMD_Pos)) /* Assigment of value for CMD in the PMU_PMUSEQ4 register */
#define PMU_PMUSEQ4_SPIRADDR_Pos              _UINT32_(8)                                          /* (PMU_PMUSEQ4)  Position */
#define PMU_PMUSEQ4_SPIRADDR_Msk              (_UINT32_(0xFF) << PMU_PMUSEQ4_SPIRADDR_Pos)         /* (PMU_PMUSEQ4)  Mask */
#define PMU_PMUSEQ4_SPIRADDR(value)           (PMU_PMUSEQ4_SPIRADDR_Msk & (_UINT32_(value) << PMU_PMUSEQ4_SPIRADDR_Pos)) /* Assigment of value for SPIRADDR in the PMU_PMUSEQ4 register */
#define PMU_PMUSEQ4_SPIDATA_Pos               _UINT32_(16)                                         /* (PMU_PMUSEQ4)  Position */
#define PMU_PMUSEQ4_SPIDATA_Msk               (_UINT32_(0xFFFF) << PMU_PMUSEQ4_SPIDATA_Pos)        /* (PMU_PMUSEQ4)  Mask */
#define PMU_PMUSEQ4_SPIDATA(value)            (PMU_PMUSEQ4_SPIDATA_Msk & (_UINT32_(value) << PMU_PMUSEQ4_SPIDATA_Pos)) /* Assigment of value for SPIDATA in the PMU_PMUSEQ4 register */
#define PMU_PMUSEQ4_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (PMU_PMUSEQ4) Register Mask  */


/* -------- PMU_PMUCFG : (PMU Offset: 0x38) (R/W 32)  -------- */
#define PMU_PMUCFG_RESETVALUE                 _UINT32_(0x00)                                       /*  (PMU_PMUCFG)   Reset Value */

#define PMU_PMUCFG_BUCK_SW_DELAY_Pos          _UINT32_(0)                                          /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_BUCK_SW_DELAY_Msk          (_UINT32_(0x7F) << PMU_PMUCFG_BUCK_SW_DELAY_Pos)     /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_BUCK_SW_DELAY(value)       (PMU_PMUCFG_BUCK_SW_DELAY_Msk & (_UINT32_(value) << PMU_PMUCFG_BUCK_SW_DELAY_Pos)) /* Assigment of value for BUCK_SW_DELAY in the PMU_PMUCFG register */
#define PMU_PMUCFG_MLDO_SW_DELAY_Pos          _UINT32_(8)                                          /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_MLDO_SW_DELAY_Msk          (_UINT32_(0x3F) << PMU_PMUCFG_MLDO_SW_DELAY_Pos)     /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_MLDO_SW_DELAY(value)       (PMU_PMUCFG_MLDO_SW_DELAY_Msk & (_UINT32_(value) << PMU_PMUCFG_MLDO_SW_DELAY_Pos)) /* Assigment of value for MLDO_SW_DELAY in the PMU_PMUCFG register */
#define PMU_PMUCFG_MLDOEXT_l_Pos              _UINT32_(14)                                         /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_MLDOEXT_l_Msk              (_UINT32_(0x3) << PMU_PMUCFG_MLDOEXT_l_Pos)          /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_MLDOEXT_l(value)           (PMU_PMUCFG_MLDOEXT_l_Msk & (_UINT32_(value) << PMU_PMUCFG_MLDOEXT_l_Pos)) /* Assigment of value for MLDOEXT_l in the PMU_PMUCFG register */
#define PMU_PMUCFG_BUCK_CP_L_Pos              _UINT32_(16)                                         /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_BUCK_CP_L_Msk              (_UINT32_(0xF) << PMU_PMUCFG_BUCK_CP_L_Pos)          /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_BUCK_CP_L(value)           (PMU_PMUCFG_BUCK_CP_L_Msk & (_UINT32_(value) << PMU_PMUCFG_BUCK_CP_L_Pos)) /* Assigment of value for BUCK_CP_L in the PMU_PMUCFG register */
#define PMU_PMUCFG_BUCK_CP_H_Pos              _UINT32_(20)                                         /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_BUCK_CP_H_Msk              (_UINT32_(0xF) << PMU_PMUCFG_BUCK_CP_H_Pos)          /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_BUCK_CP_H(value)           (PMU_PMUCFG_BUCK_CP_H_Msk & (_UINT32_(value) << PMU_PMUCFG_BUCK_CP_H_Pos)) /* Assigment of value for BUCK_CP_H in the PMU_PMUCFG register */
#define PMU_PMUCFG_ADC_CP_L_Pos               _UINT32_(24)                                         /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_ADC_CP_L_Msk               (_UINT32_(0xF) << PMU_PMUCFG_ADC_CP_L_Pos)           /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_ADC_CP_L(value)            (PMU_PMUCFG_ADC_CP_L_Msk & (_UINT32_(value) << PMU_PMUCFG_ADC_CP_L_Pos)) /* Assigment of value for ADC_CP_L in the PMU_PMUCFG register */
#define PMU_PMUCFG_ADC_CP_H_Pos               _UINT32_(28)                                         /* (PMU_PMUCFG)  Position */
#define PMU_PMUCFG_ADC_CP_H_Msk               (_UINT32_(0xF) << PMU_PMUCFG_ADC_CP_H_Pos)           /* (PMU_PMUCFG)  Mask */
#define PMU_PMUCFG_ADC_CP_H(value)            (PMU_PMUCFG_ADC_CP_H_Msk & (_UINT32_(value) << PMU_PMUCFG_ADC_CP_H_Pos)) /* Assigment of value for ADC_CP_H in the PMU_PMUCFG register */
#define PMU_PMUCFG_Msk                        _UINT32_(0xFFFFFF7F)                                 /* (PMU_PMUCFG) Register Mask  */


/* -------- PMU_WCMCMD : (PMU Offset: 0x3C) (R/W 32)  -------- */
#define PMU_WCMCMD_RESETVALUE                 _UINT32_(0x00)                                       /*  (PMU_WCMCMD)   Reset Value */

#define PMU_WCMCMD_WCMADDR_Pos                _UINT32_(0)                                          /* (PMU_WCMCMD)  Position */
#define PMU_WCMCMD_WCMADDR_Msk                (_UINT32_(0x7FF) << PMU_WCMCMD_WCMADDR_Pos)          /* (PMU_WCMCMD)  Mask */
#define PMU_WCMCMD_WCMADDR(value)             (PMU_WCMCMD_WCMADDR_Msk & (_UINT32_(value) << PMU_WCMCMD_WCMADDR_Pos)) /* Assigment of value for WCMADDR in the PMU_WCMCMD register */
#define PMU_WCMCMD_WCMCLKDIV_Pos              _UINT32_(16)                                         /* (PMU_WCMCMD)  Position */
#define PMU_WCMCMD_WCMCLKDIV_Msk              (_UINT32_(0x7) << PMU_WCMCMD_WCMCLKDIV_Pos)          /* (PMU_WCMCMD)  Mask */
#define PMU_WCMCMD_WCMCLKDIV(value)           (PMU_WCMCMD_WCMCLKDIV_Msk & (_UINT32_(value) << PMU_WCMCMD_WCMCLKDIV_Pos)) /* Assigment of value for WCMCLKDIV in the PMU_WCMCMD register */
#define PMU_WCMCMD_WCMRDU_Pos                 _UINT32_(28)                                         /* (PMU_WCMCMD)  Position */
#define PMU_WCMCMD_WCMRDU_Msk                 (_UINT32_(0x1) << PMU_WCMCMD_WCMRDU_Pos)             /* (PMU_WCMCMD)  Mask */
#define PMU_WCMCMD_WCMRDU(value)              (PMU_WCMCMD_WCMRDU_Msk & (_UINT32_(value) << PMU_WCMCMD_WCMRDU_Pos)) /* Assigment of value for WCMRDU in the PMU_WCMCMD register */
#define PMU_WCMCMD_CMD_Pos                    _UINT32_(30)                                         /* (PMU_WCMCMD)  Position */
#define PMU_WCMCMD_CMD_Msk                    (_UINT32_(0x1) << PMU_WCMCMD_CMD_Pos)                /* (PMU_WCMCMD)  Mask */
#define PMU_WCMCMD_CMD(value)                 (PMU_WCMCMD_CMD_Msk & (_UINT32_(value) << PMU_WCMCMD_CMD_Pos)) /* Assigment of value for CMD in the PMU_WCMCMD register */
#define PMU_WCMCMD_MODE_Pos                   _UINT32_(31)                                         /* (PMU_WCMCMD)  Position */
#define PMU_WCMCMD_MODE_Msk                   (_UINT32_(0x1) << PMU_WCMCMD_MODE_Pos)               /* (PMU_WCMCMD)  Mask */
#define PMU_WCMCMD_MODE(value)                (PMU_WCMCMD_MODE_Msk & (_UINT32_(value) << PMU_WCMCMD_MODE_Pos)) /* Assigment of value for MODE in the PMU_WCMCMD register */
#define PMU_WCMCMD_Msk                        _UINT32_(0xD00707FF)                                 /* (PMU_WCMCMD) Register Mask  */


/* -------- PMU_WCMWDATA : (PMU Offset: 0x40) (R/W 32)  -------- */
#define PMU_WCMWDATA_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_WCMWDATA)   Reset Value */

#define PMU_WCMWDATA_WCMWDATA_Pos             _UINT32_(0)                                          /* (PMU_WCMWDATA)  Position */
#define PMU_WCMWDATA_WCMWDATA_Msk             (_UINT32_(0xFFFFFFFF) << PMU_WCMWDATA_WCMWDATA_Pos)  /* (PMU_WCMWDATA)  Mask */
#define PMU_WCMWDATA_WCMWDATA(value)          (PMU_WCMWDATA_WCMWDATA_Msk & (_UINT32_(value) << PMU_WCMWDATA_WCMWDATA_Pos)) /* Assigment of value for WCMWDATA in the PMU_WCMWDATA register */
#define PMU_WCMWDATA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PMU_WCMWDATA) Register Mask  */


/* -------- PMU_WCMRDATA : (PMU Offset: 0x44) (R/W 32)  -------- */
#define PMU_WCMRDATA_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_WCMRDATA)   Reset Value */

#define PMU_WCMRDATA_WCMRDATA_Pos             _UINT32_(0)                                          /* (PMU_WCMRDATA)  Position */
#define PMU_WCMRDATA_WCMRDATA_Msk             (_UINT32_(0xFFFFFFFF) << PMU_WCMRDATA_WCMRDATA_Pos)  /* (PMU_WCMRDATA)  Mask */
#define PMU_WCMRDATA_WCMRDATA(value)          (PMU_WCMRDATA_WCMRDATA_Msk & (_UINT32_(value) << PMU_WCMRDATA_WCMRDATA_Pos)) /* Assigment of value for WCMRDATA in the PMU_WCMRDATA register */
#define PMU_WCMRDATA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PMU_WCMRDATA) Register Mask  */


/* -------- PMU_VBCCMD : (PMU Offset: 0x48) (R/W 32)  -------- */
#define PMU_VBCCMD_RESETVALUE                 _UINT32_(0x00)                                       /*  (PMU_VBCCMD)   Reset Value */

#define PMU_VBCCMD_VBCADDR_Pos                _UINT32_(0)                                          /* (PMU_VBCCMD)  Position */
#define PMU_VBCCMD_VBCADDR_Msk                (_UINT32_(0xFFFF) << PMU_VBCCMD_VBCADDR_Pos)         /* (PMU_VBCCMD)  Mask */
#define PMU_VBCCMD_VBCADDR(value)             (PMU_VBCCMD_VBCADDR_Msk & (_UINT32_(value) << PMU_VBCCMD_VBCADDR_Pos)) /* Assigment of value for VBCADDR in the PMU_VBCCMD register */
#define PMU_VBCCMD_VBCRDY_Pos                 _UINT32_(28)                                         /* (PMU_VBCCMD)  Position */
#define PMU_VBCCMD_VBCRDY_Msk                 (_UINT32_(0x1) << PMU_VBCCMD_VBCRDY_Pos)             /* (PMU_VBCCMD)  Mask */
#define PMU_VBCCMD_VBCRDY(value)              (PMU_VBCCMD_VBCRDY_Msk & (_UINT32_(value) << PMU_VBCCMD_VBCRDY_Pos)) /* Assigment of value for VBCRDY in the PMU_VBCCMD register */
#define PMU_VBCCMD_CMD_Pos                    _UINT32_(30)                                         /* (PMU_VBCCMD)  Position */
#define PMU_VBCCMD_CMD_Msk                    (_UINT32_(0x1) << PMU_VBCCMD_CMD_Pos)                /* (PMU_VBCCMD)  Mask */
#define PMU_VBCCMD_CMD(value)                 (PMU_VBCCMD_CMD_Msk & (_UINT32_(value) << PMU_VBCCMD_CMD_Pos)) /* Assigment of value for CMD in the PMU_VBCCMD register */
#define PMU_VBCCMD_Msk                        _UINT32_(0x5000FFFF)                                 /* (PMU_VBCCMD) Register Mask  */


/* -------- PMU_VBCWDATA : (PMU Offset: 0x4C) (R/W 32)  -------- */
#define PMU_VBCWDATA_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_VBCWDATA)   Reset Value */

#define PMU_VBCWDATA_VBCWDATA_Pos             _UINT32_(0)                                          /* (PMU_VBCWDATA)  Position */
#define PMU_VBCWDATA_VBCWDATA_Msk             (_UINT32_(0xFFFFFFFF) << PMU_VBCWDATA_VBCWDATA_Pos)  /* (PMU_VBCWDATA)  Mask */
#define PMU_VBCWDATA_VBCWDATA(value)          (PMU_VBCWDATA_VBCWDATA_Msk & (_UINT32_(value) << PMU_VBCWDATA_VBCWDATA_Pos)) /* Assigment of value for VBCWDATA in the PMU_VBCWDATA register */
#define PMU_VBCWDATA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PMU_VBCWDATA) Register Mask  */


/* -------- PMU_VBCRDATA : (PMU Offset: 0x50) (R/W 32)  -------- */
#define PMU_VBCRDATA_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_VBCRDATA)   Reset Value */

#define PMU_VBCRDATA_VBCRDATA_Pos             _UINT32_(0)                                          /* (PMU_VBCRDATA)  Position */
#define PMU_VBCRDATA_VBCRDATA_Msk             (_UINT32_(0xFFFFFFFF) << PMU_VBCRDATA_VBCRDATA_Pos)  /* (PMU_VBCRDATA)  Mask */
#define PMU_VBCRDATA_VBCRDATA(value)          (PMU_VBCRDATA_VBCRDATA_Msk & (_UINT32_(value) << PMU_VBCRDATA_VBCRDATA_Pos)) /* Assigment of value for VBCRDATA in the PMU_VBCRDATA register */
#define PMU_VBCRDATA_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (PMU_VBCRDATA) Register Mask  */


/* -------- PMU_WCMCFG : (PMU Offset: 0x54) (R/W 32)  -------- */
#define PMU_WCMCFG_RESETVALUE                 _UINT32_(0x00)                                       /*  (PMU_WCMCFG)   Reset Value */

#define PMU_WCMCFG_WCM1CFG_Pos                _UINT32_(0)                                          /* (PMU_WCMCFG)  Position */
#define PMU_WCMCFG_WCM1CFG_Msk                (_UINT32_(0x7) << PMU_WCMCFG_WCM1CFG_Pos)            /* (PMU_WCMCFG)  Mask */
#define PMU_WCMCFG_WCM1CFG(value)             (PMU_WCMCFG_WCM1CFG_Msk & (_UINT32_(value) << PMU_WCMCFG_WCM1CFG_Pos)) /* Assigment of value for WCM1CFG in the PMU_WCMCFG register */
#define PMU_WCMCFG_WCM2CFG_Pos                _UINT32_(4)                                          /* (PMU_WCMCFG)  Position */
#define PMU_WCMCFG_WCM2CFG_Msk                (_UINT32_(0x7) << PMU_WCMCFG_WCM2CFG_Pos)            /* (PMU_WCMCFG)  Mask */
#define PMU_WCMCFG_WCM2CFG(value)             (PMU_WCMCFG_WCM2CFG_Msk & (_UINT32_(value) << PMU_WCMCFG_WCM2CFG_Pos)) /* Assigment of value for WCM2CFG in the PMU_WCMCFG register */
#define PMU_WCMCFG_Msk                        _UINT32_(0x00000077)                                 /* (PMU_WCMCFG) Register Mask  */


/* -------- PMU_PMUIENB : (PMU Offset: 0x58) (R/W 32)  -------- */
#define PMU_PMUIENB_RESETVALUE                _UINT32_(0x00)                                       /*  (PMU_PMUIENB)   Reset Value */

#define PMU_PMUIENB_ADCBORIEN_Pos             _UINT32_(0)                                          /* (PMU_PMUIENB)  Position */
#define PMU_PMUIENB_ADCBORIEN_Msk             (_UINT32_(0x1) << PMU_PMUIENB_ADCBORIEN_Pos)         /* (PMU_PMUIENB)  Mask */
#define PMU_PMUIENB_ADCBORIEN(value)          (PMU_PMUIENB_ADCBORIEN_Msk & (_UINT32_(value) << PMU_PMUIENB_ADCBORIEN_Pos)) /* Assigment of value for ADCBORIEN in the PMU_PMUIENB register */
#define PMU_PMUIENB_BUCKBORIEN_Pos            _UINT32_(1)                                          /* (PMU_PMUIENB)  Position */
#define PMU_PMUIENB_BUCKBORIEN_Msk            (_UINT32_(0x1) << PMU_PMUIENB_BUCKBORIEN_Pos)        /* (PMU_PMUIENB)  Mask */
#define PMU_PMUIENB_BUCKBORIEN(value)         (PMU_PMUIENB_BUCKBORIEN_Msk & (_UINT32_(value) << PMU_PMUIENB_BUCKBORIEN_Pos)) /* Assigment of value for BUCKBORIEN in the PMU_PMUIENB register */
#define PMU_PMUIENB_SCMPIEN_Pos               _UINT32_(2)                                          /* (PMU_PMUIENB)  Position */
#define PMU_PMUIENB_SCMPIEN_Msk               (_UINT32_(0x1) << PMU_PMUIENB_SCMPIEN_Pos)           /* (PMU_PMUIENB)  Mask */
#define PMU_PMUIENB_SCMPIEN(value)            (PMU_PMUIENB_SCMPIEN_Msk & (_UINT32_(value) << PMU_PMUIENB_SCMPIEN_Pos)) /* Assigment of value for SCMPIEN in the PMU_PMUIENB register */
#define PMU_PMUIENB_WCMIAIEN_Pos              _UINT32_(3)                                          /* (PMU_PMUIENB)  Position */
#define PMU_PMUIENB_WCMIAIEN_Msk              (_UINT32_(0x1) << PMU_PMUIENB_WCMIAIEN_Pos)          /* (PMU_PMUIENB)  Mask */
#define PMU_PMUIENB_WCMIAIEN(value)           (PMU_PMUIENB_WCMIAIEN_Msk & (_UINT32_(value) << PMU_PMUIENB_WCMIAIEN_Pos)) /* Assigment of value for WCMIAIEN in the PMU_PMUIENB register */
#define PMU_PMUIENB_VBCIAIEN_Pos              _UINT32_(4)                                          /* (PMU_PMUIENB)  Position */
#define PMU_PMUIENB_VBCIAIEN_Msk              (_UINT32_(0x1) << PMU_PMUIENB_VBCIAIEN_Pos)          /* (PMU_PMUIENB)  Mask */
#define PMU_PMUIENB_VBCIAIEN(value)           (PMU_PMUIENB_VBCIAIEN_Msk & (_UINT32_(value) << PMU_PMUIENB_VBCIAIEN_Pos)) /* Assigment of value for VBCIAIEN in the PMU_PMUIENB register */
#define PMU_PMUIENB_Msk                       _UINT32_(0x0000001F)                                 /* (PMU_PMUIENB) Register Mask  */


/* -------- PMU_PMUISTAT : (PMU Offset: 0x5C) (R/W 32)  -------- */
#define PMU_PMUISTAT_RESETVALUE               _UINT32_(0x00)                                       /*  (PMU_PMUISTAT)   Reset Value */

#define PMU_PMUISTAT_ADCBORINT_Pos            _UINT32_(0)                                          /* (PMU_PMUISTAT)  Position */
#define PMU_PMUISTAT_ADCBORINT_Msk            (_UINT32_(0x1) << PMU_PMUISTAT_ADCBORINT_Pos)        /* (PMU_PMUISTAT)  Mask */
#define PMU_PMUISTAT_ADCBORINT(value)         (PMU_PMUISTAT_ADCBORINT_Msk & (_UINT32_(value) << PMU_PMUISTAT_ADCBORINT_Pos)) /* Assigment of value for ADCBORINT in the PMU_PMUISTAT register */
#define PMU_PMUISTAT_BUCKBORINT_Pos           _UINT32_(1)                                          /* (PMU_PMUISTAT)  Position */
#define PMU_PMUISTAT_BUCKBORINT_Msk           (_UINT32_(0x1) << PMU_PMUISTAT_BUCKBORINT_Pos)       /* (PMU_PMUISTAT)  Mask */
#define PMU_PMUISTAT_BUCKBORINT(value)        (PMU_PMUISTAT_BUCKBORINT_Msk & (_UINT32_(value) << PMU_PMUISTAT_BUCKBORINT_Pos)) /* Assigment of value for BUCKBORINT in the PMU_PMUISTAT register */
#define PMU_PMUISTAT_SCMPINT_Pos              _UINT32_(2)                                          /* (PMU_PMUISTAT)  Position */
#define PMU_PMUISTAT_SCMPINT_Msk              (_UINT32_(0x1) << PMU_PMUISTAT_SCMPINT_Pos)          /* (PMU_PMUISTAT)  Mask */
#define PMU_PMUISTAT_SCMPINT(value)           (PMU_PMUISTAT_SCMPINT_Msk & (_UINT32_(value) << PMU_PMUISTAT_SCMPINT_Pos)) /* Assigment of value for SCMPINT in the PMU_PMUISTAT register */
#define PMU_PMUISTAT_WCMIAINT_Pos             _UINT32_(3)                                          /* (PMU_PMUISTAT)  Position */
#define PMU_PMUISTAT_WCMIAINT_Msk             (_UINT32_(0x1) << PMU_PMUISTAT_WCMIAINT_Pos)         /* (PMU_PMUISTAT)  Mask */
#define PMU_PMUISTAT_WCMIAINT(value)          (PMU_PMUISTAT_WCMIAINT_Msk & (_UINT32_(value) << PMU_PMUISTAT_WCMIAINT_Pos)) /* Assigment of value for WCMIAINT in the PMU_PMUISTAT register */
#define PMU_PMUISTAT_VBCIAINT_Pos             _UINT32_(4)                                          /* (PMU_PMUISTAT)  Position */
#define PMU_PMUISTAT_VBCIAINT_Msk             (_UINT32_(0x1) << PMU_PMUISTAT_VBCIAINT_Pos)         /* (PMU_PMUISTAT)  Mask */
#define PMU_PMUISTAT_VBCIAINT(value)          (PMU_PMUISTAT_VBCIAINT_Msk & (_UINT32_(value) << PMU_PMUISTAT_VBCIAINT_Pos)) /* Assigment of value for VBCIAINT in the PMU_PMUISTAT register */
#define PMU_PMUISTAT_Msk                      _UINT32_(0x0000001F)                                 /* (PMU_PMUISTAT) Register Mask  */


/** \brief PMU register offsets definitions */
#define PMU_SPICTRL_REG_OFST           _UINT32_(0x00)      /* (PMU_SPICTRL)  Offset */
#define PMU_SPISTATUS_REG_OFST         _UINT32_(0x04)      /* (PMU_SPISTATUS)  Offset */
#define PMU_CLKCTRL_REG_OFST           _UINT32_(0x08)      /* (PMU_CLKCTRL)  Offset */
#define PMU_MODECTRL1_REG_OFST         _UINT32_(0x0C)      /* (PMU_MODECTRL1)  Offset */
#define PMU_MODECTRL2_REG_OFST         _UINT32_(0x10)      /* (PMU_MODECTRL2)  Offset */
#define PMU_MODECTRL3_REG_OFST         _UINT32_(0x14)      /* (PMU_MODECTRL3)  Offset */
#define PMU_MODECTRL4_REG_OFST         _UINT32_(0x18)      /* (PMU_MODECTRL4)  Offset */
#define PMU_OVERCTRL_REG_OFST          _UINT32_(0x1C)      /* (PMU_OVERCTRL)  Offset */
#define PMU_PMUCMODE_REG_OFST          _UINT32_(0x20)      /* (PMU_PMUCMODE)  Offset */
#define PMU_PMUSTATUS_REG_OFST         _UINT32_(0x24)      /* (PMU_PMUSTATUS)  Offset */
#define PMU_PMUSEQ1_REG_OFST           _UINT32_(0x28)      /* (PMU_PMUSEQ1)  Offset */
#define PMU_PMUSEQ2_REG_OFST           _UINT32_(0x2C)      /* (PMU_PMUSEQ2)  Offset */
#define PMU_PMUSEQ3_REG_OFST           _UINT32_(0x30)      /* (PMU_PMUSEQ3)  Offset */
#define PMU_PMUSEQ4_REG_OFST           _UINT32_(0x34)      /* (PMU_PMUSEQ4)  Offset */
#define PMU_PMUCFG_REG_OFST            _UINT32_(0x38)      /* (PMU_PMUCFG)  Offset */
#define PMU_WCMCMD_REG_OFST            _UINT32_(0x3C)      /* (PMU_WCMCMD)  Offset */
#define PMU_WCMWDATA_REG_OFST          _UINT32_(0x40)      /* (PMU_WCMWDATA)  Offset */
#define PMU_WCMRDATA_REG_OFST          _UINT32_(0x44)      /* (PMU_WCMRDATA)  Offset */
#define PMU_VBCCMD_REG_OFST            _UINT32_(0x48)      /* (PMU_VBCCMD)  Offset */
#define PMU_VBCWDATA_REG_OFST          _UINT32_(0x4C)      /* (PMU_VBCWDATA)  Offset */
#define PMU_VBCRDATA_REG_OFST          _UINT32_(0x50)      /* (PMU_VBCRDATA)  Offset */
#define PMU_WCMCFG_REG_OFST            _UINT32_(0x54)      /* (PMU_WCMCFG)  Offset */
#define PMU_PMUIENB_REG_OFST           _UINT32_(0x58)      /* (PMU_PMUIENB)  Offset */
#define PMU_PMUISTAT_REG_OFST          _UINT32_(0x5C)      /* (PMU_PMUISTAT)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PMU register API structure */
typedef struct
{  /* PMU SPI controller */
  __IO  uint32_t                       PMU_SPICTRL;        /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       PMU_SPISTATUS;      /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       PMU_CLKCTRL;        /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       PMU_MODECTRL1;      /**< Offset: 0x0C (R/W  32)  */
  __IO  uint32_t                       PMU_MODECTRL2;      /**< Offset: 0x10 (R/W  32)  */
  __IO  uint32_t                       PMU_MODECTRL3;      /**< Offset: 0x14 (R/W  32)  */
  __IO  uint32_t                       PMU_MODECTRL4;      /**< Offset: 0x18 (R/W  32)  */
  __IO  uint32_t                       PMU_OVERCTRL;       /**< Offset: 0x1C (R/W  32)  */
  __IO  uint32_t                       PMU_PMUCMODE;       /**< Offset: 0x20 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUSTATUS;      /**< Offset: 0x24 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUSEQ1;        /**< Offset: 0x28 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUSEQ2;        /**< Offset: 0x2C (R/W  32)  */
  __IO  uint32_t                       PMU_PMUSEQ3;        /**< Offset: 0x30 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUSEQ4;        /**< Offset: 0x34 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUCFG;         /**< Offset: 0x38 (R/W  32)  */
  __IO  uint32_t                       PMU_WCMCMD;         /**< Offset: 0x3C (R/W  32)  */
  __IO  uint32_t                       PMU_WCMWDATA;       /**< Offset: 0x40 (R/W  32)  */
  __IO  uint32_t                       PMU_WCMRDATA;       /**< Offset: 0x44 (R/W  32)  */
  __IO  uint32_t                       PMU_VBCCMD;         /**< Offset: 0x48 (R/W  32)  */
  __IO  uint32_t                       PMU_VBCWDATA;       /**< Offset: 0x4C (R/W  32)  */
  __IO  uint32_t                       PMU_VBCRDATA;       /**< Offset: 0x50 (R/W  32)  */
  __IO  uint32_t                       PMU_WCMCFG;         /**< Offset: 0x54 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUIENB;        /**< Offset: 0x58 (R/W  32)  */
  __IO  uint32_t                       PMU_PMUISTAT;       /**< Offset: 0x5C (R/W  32)  */
} pmu_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_PMU_COMPONENT_H_ */
