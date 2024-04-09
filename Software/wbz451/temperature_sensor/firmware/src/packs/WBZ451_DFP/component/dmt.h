/*
 * Component description for DMT
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
#ifndef _BZ45_DMT_COMPONENT_H_
#define _BZ45_DMT_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR DMT                                          */
/* ************************************************************************** */

/* -------- DMT_DMTCON : (DMT Offset: 0x00) (R/W 32)  -------- */
#define DMT_DMTCON_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMT_DMTCON)   Reset Value */

#define DMT_DMTCON_ON_Pos                     _UINT32_(15)                                         /* (DMT_DMTCON)  Position */
#define DMT_DMTCON_ON_Msk                     (_UINT32_(0x1) << DMT_DMTCON_ON_Pos)                 /* (DMT_DMTCON)  Mask */
#define DMT_DMTCON_ON(value)                  (DMT_DMTCON_ON_Msk & (_UINT32_(value) << DMT_DMTCON_ON_Pos)) /* Assigment of value for ON in the DMT_DMTCON register */
#define DMT_DMTCON_Msk                        _UINT32_(0x00008000)                                 /* (DMT_DMTCON) Register Mask  */


/* -------- DMT_DMTCONCLR : (DMT Offset: 0x04) (R/W 32) Bit clear register -------- */
#define DMT_DMTCONCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCONCLR) Bit clear register  Reset Value */

#define DMT_DMTCONCLR_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCONCLR) Register Mask  */


/* -------- DMT_DMTCONSET : (DMT Offset: 0x08) (R/W 32) Bit set register -------- */
#define DMT_DMTCONSET_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCONSET) Bit set register  Reset Value */

#define DMT_DMTCONSET_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCONSET) Register Mask  */


/* -------- DMT_DMTCONINV : (DMT Offset: 0x0C) (R/W 32) Bit invert register -------- */
#define DMT_DMTCONINV_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCONINV) Bit invert register  Reset Value */

#define DMT_DMTCONINV_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCONINV) Register Mask  */


/* -------- DMT_DMTPRECLR : (DMT Offset: 0x10) (R/W 32)  -------- */
#define DMT_DMTPRECLR_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTPRECLR)   Reset Value */

#define DMT_DMTPRECLR_STEP1_Pos               _UINT32_(8)                                          /* (DMT_DMTPRECLR)  Position */
#define DMT_DMTPRECLR_STEP1_Msk               (_UINT32_(0xFF) << DMT_DMTPRECLR_STEP1_Pos)          /* (DMT_DMTPRECLR)  Mask */
#define DMT_DMTPRECLR_STEP1(value)            (DMT_DMTPRECLR_STEP1_Msk & (_UINT32_(value) << DMT_DMTPRECLR_STEP1_Pos)) /* Assigment of value for STEP1 in the DMT_DMTPRECLR register */
#define DMT_DMTPRECLR_Msk                     _UINT32_(0x0000FF00)                                 /* (DMT_DMTPRECLR) Register Mask  */


/* -------- DMT_DMTPRECLRCLR : (DMT Offset: 0x14) (R/W 32) Bit clear register -------- */
#define DMT_DMTPRECLRCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (DMT_DMTPRECLRCLR) Bit clear register  Reset Value */

#define DMT_DMTPRECLRCLR_Msk                  _UINT32_(0x00000000)                                 /* (DMT_DMTPRECLRCLR) Register Mask  */


/* -------- DMT_DMTPRECLRSET : (DMT Offset: 0x18) (R/W 32) Bit set register -------- */
#define DMT_DMTPRECLRSET_RESETVALUE           _UINT32_(0x00)                                       /*  (DMT_DMTPRECLRSET) Bit set register  Reset Value */

#define DMT_DMTPRECLRSET_Msk                  _UINT32_(0x00000000)                                 /* (DMT_DMTPRECLRSET) Register Mask  */


/* -------- DMT_DMTPRECLRINV : (DMT Offset: 0x1C) (R/W 32) Bit invert register -------- */
#define DMT_DMTPRECLRINV_RESETVALUE           _UINT32_(0x00)                                       /*  (DMT_DMTPRECLRINV) Bit invert register  Reset Value */

#define DMT_DMTPRECLRINV_Msk                  _UINT32_(0x00000000)                                 /* (DMT_DMTPRECLRINV) Register Mask  */


/* -------- DMT_DMTCLR : (DMT Offset: 0x20) (R/W 32)  -------- */
#define DMT_DMTCLR_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMT_DMTCLR)   Reset Value */

#define DMT_DMTCLR_STEP2_Pos                  _UINT32_(0)                                          /* (DMT_DMTCLR)  Position */
#define DMT_DMTCLR_STEP2_Msk                  (_UINT32_(0xFF) << DMT_DMTCLR_STEP2_Pos)             /* (DMT_DMTCLR)  Mask */
#define DMT_DMTCLR_STEP2(value)               (DMT_DMTCLR_STEP2_Msk & (_UINT32_(value) << DMT_DMTCLR_STEP2_Pos)) /* Assigment of value for STEP2 in the DMT_DMTCLR register */
#define DMT_DMTCLR_Msk                        _UINT32_(0x000000FF)                                 /* (DMT_DMTCLR) Register Mask  */


/* -------- DMT_DMTCLRCLR : (DMT Offset: 0x24) (R/W 32) Bit clear register -------- */
#define DMT_DMTCLRCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCLRCLR) Bit clear register  Reset Value */

#define DMT_DMTCLRCLR_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCLRCLR) Register Mask  */


/* -------- DMT_DMTCLRSET : (DMT Offset: 0x28) (R/W 32) Bit set register -------- */
#define DMT_DMTCLRSET_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCLRSET) Bit set register  Reset Value */

#define DMT_DMTCLRSET_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCLRSET) Register Mask  */


/* -------- DMT_DMTCLRINV : (DMT Offset: 0x2C) (R/W 32) Bit invert register -------- */
#define DMT_DMTCLRINV_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCLRINV) Bit invert register  Reset Value */

#define DMT_DMTCLRINV_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCLRINV) Register Mask  */


/* -------- DMT_DMTSTAT : (DMT Offset: 0x30) (R/W 32)  -------- */
#define DMT_DMTSTAT_RESETVALUE                _UINT32_(0x00)                                       /*  (DMT_DMTSTAT)   Reset Value */

#define DMT_DMTSTAT_WINOPN_Pos                _UINT32_(0)                                          /* (DMT_DMTSTAT)  Position */
#define DMT_DMTSTAT_WINOPN_Msk                (_UINT32_(0x1) << DMT_DMTSTAT_WINOPN_Pos)            /* (DMT_DMTSTAT)  Mask */
#define DMT_DMTSTAT_WINOPN(value)             (DMT_DMTSTAT_WINOPN_Msk & (_UINT32_(value) << DMT_DMTSTAT_WINOPN_Pos)) /* Assigment of value for WINOPN in the DMT_DMTSTAT register */
#define DMT_DMTSTAT_DMTEVENT_Pos              _UINT32_(5)                                          /* (DMT_DMTSTAT)  Position */
#define DMT_DMTSTAT_DMTEVENT_Msk              (_UINT32_(0x1) << DMT_DMTSTAT_DMTEVENT_Pos)          /* (DMT_DMTSTAT)  Mask */
#define DMT_DMTSTAT_DMTEVENT(value)           (DMT_DMTSTAT_DMTEVENT_Msk & (_UINT32_(value) << DMT_DMTSTAT_DMTEVENT_Pos)) /* Assigment of value for DMTEVENT in the DMT_DMTSTAT register */
#define DMT_DMTSTAT_BAD_Pos                   _UINT32_(6)                                          /* (DMT_DMTSTAT)  Position */
#define DMT_DMTSTAT_BAD_Msk                   (_UINT32_(0x3) << DMT_DMTSTAT_BAD_Pos)               /* (DMT_DMTSTAT)  Mask */
#define DMT_DMTSTAT_BAD(value)                (DMT_DMTSTAT_BAD_Msk & (_UINT32_(value) << DMT_DMTSTAT_BAD_Pos)) /* Assigment of value for BAD in the DMT_DMTSTAT register */
#define DMT_DMTSTAT_Msk                       _UINT32_(0x000000E1)                                 /* (DMT_DMTSTAT) Register Mask  */


/* -------- DMT_DMTSTATCLR : (DMT Offset: 0x34) (R/W 32) Bit clear register -------- */
#define DMT_DMTSTATCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (DMT_DMTSTATCLR) Bit clear register  Reset Value */

#define DMT_DMTSTATCLR_Msk                    _UINT32_(0x00000000)                                 /* (DMT_DMTSTATCLR) Register Mask  */


/* -------- DMT_DMTSTATSET : (DMT Offset: 0x38) (R/W 32) Bit set register -------- */
#define DMT_DMTSTATSET_RESETVALUE             _UINT32_(0x00)                                       /*  (DMT_DMTSTATSET) Bit set register  Reset Value */

#define DMT_DMTSTATSET_Msk                    _UINT32_(0x00000000)                                 /* (DMT_DMTSTATSET) Register Mask  */


/* -------- DMT_DMTSTATINV : (DMT Offset: 0x3C) (R/W 32) Bit invert register -------- */
#define DMT_DMTSTATINV_RESETVALUE             _UINT32_(0x00)                                       /*  (DMT_DMTSTATINV) Bit invert register  Reset Value */

#define DMT_DMTSTATINV_Msk                    _UINT32_(0x00000000)                                 /* (DMT_DMTSTATINV) Register Mask  */


/* -------- DMT_DMTCNT : (DMT Offset: 0x40) (R/W 32)  -------- */
#define DMT_DMTCNT_RESETVALUE                 _UINT32_(0x00)                                       /*  (DMT_DMTCNT)   Reset Value */

#define DMT_DMTCNT_COUNTER_Pos                _UINT32_(0)                                          /* (DMT_DMTCNT)  Position */
#define DMT_DMTCNT_COUNTER_Msk                (_UINT32_(0xFFFFFFFF) << DMT_DMTCNT_COUNTER_Pos)     /* (DMT_DMTCNT)  Mask */
#define DMT_DMTCNT_COUNTER(value)             (DMT_DMTCNT_COUNTER_Msk & (_UINT32_(value) << DMT_DMTCNT_COUNTER_Pos)) /* Assigment of value for COUNTER in the DMT_DMTCNT register */
#define DMT_DMTCNT_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (DMT_DMTCNT) Register Mask  */


/* -------- DMT_DMTCNTCLR : (DMT Offset: 0x44) (R/W 32) Bit clear register -------- */
#define DMT_DMTCNTCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCNTCLR) Bit clear register  Reset Value */

#define DMT_DMTCNTCLR_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCNTCLR) Register Mask  */


/* -------- DMT_DMTCNTSET : (DMT Offset: 0x48) (R/W 32) Bit set register -------- */
#define DMT_DMTCNTSET_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCNTSET) Bit set register  Reset Value */

#define DMT_DMTCNTSET_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCNTSET) Register Mask  */


/* -------- DMT_DMTCNTINV : (DMT Offset: 0x4C) (R/W 32) Bit invert register -------- */
#define DMT_DMTCNTINV_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTCNTINV) Bit invert register  Reset Value */

#define DMT_DMTCNTINV_Msk                     _UINT32_(0x00000000)                                 /* (DMT_DMTCNTINV) Register Mask  */


/* -------- DMT_DMTHOLDREG : (DMT Offset: 0x50) (R/W 32)  -------- */
#define DMT_DMTHOLDREG_RESETVALUE             _UINT32_(0x00)                                       /*  (DMT_DMTHOLDREG)   Reset Value */

#define DMT_DMTHOLDREG_UPRCNT_Pos             _UINT32_(0)                                          /* (DMT_DMTHOLDREG)  Position */
#define DMT_DMTHOLDREG_UPRCNT_Msk             (_UINT32_(0xFFFF) << DMT_DMTHOLDREG_UPRCNT_Pos)      /* (DMT_DMTHOLDREG)  Mask */
#define DMT_DMTHOLDREG_UPRCNT(value)          (DMT_DMTHOLDREG_UPRCNT_Msk & (_UINT32_(value) << DMT_DMTHOLDREG_UPRCNT_Pos)) /* Assigment of value for UPRCNT in the DMT_DMTHOLDREG register */
#define DMT_DMTHOLDREG_Msk                    _UINT32_(0x0000FFFF)                                 /* (DMT_DMTHOLDREG) Register Mask  */


/* -------- DMT_DMTHOLDREGCLR : (DMT Offset: 0x54) (R/W 32) Bit clear register -------- */
#define DMT_DMTHOLDREGCLR_RESETVALUE          _UINT32_(0x00)                                       /*  (DMT_DMTHOLDREGCLR) Bit clear register  Reset Value */

#define DMT_DMTHOLDREGCLR_Msk                 _UINT32_(0x00000000)                                 /* (DMT_DMTHOLDREGCLR) Register Mask  */


/* -------- DMT_DMTHOLDREGSET : (DMT Offset: 0x58) (R/W 32) Bit set register -------- */
#define DMT_DMTHOLDREGSET_RESETVALUE          _UINT32_(0x00)                                       /*  (DMT_DMTHOLDREGSET) Bit set register  Reset Value */

#define DMT_DMTHOLDREGSET_Msk                 _UINT32_(0x00000000)                                 /* (DMT_DMTHOLDREGSET) Register Mask  */


/* -------- DMT_DMTHOLDREGINV : (DMT Offset: 0x5C) (R/W 32) Bit invert register -------- */
#define DMT_DMTHOLDREGINV_RESETVALUE          _UINT32_(0x00)                                       /*  (DMT_DMTHOLDREGINV) Bit invert register  Reset Value */

#define DMT_DMTHOLDREGINV_Msk                 _UINT32_(0x00000000)                                 /* (DMT_DMTHOLDREGINV) Register Mask  */


/* -------- DMT_DMTPSCNT : (DMT Offset: 0x60) (R/W 32)  -------- */
#define DMT_DMTPSCNT_RESETVALUE               _UINT32_(0x00)                                       /*  (DMT_DMTPSCNT)   Reset Value */

#define DMT_DMTPSCNT_PSCNT_Pos                _UINT32_(0)                                          /* (DMT_DMTPSCNT)  Position */
#define DMT_DMTPSCNT_PSCNT_Msk                (_UINT32_(0xFFFFFFFF) << DMT_DMTPSCNT_PSCNT_Pos)     /* (DMT_DMTPSCNT)  Mask */
#define DMT_DMTPSCNT_PSCNT(value)             (DMT_DMTPSCNT_PSCNT_Msk & (_UINT32_(value) << DMT_DMTPSCNT_PSCNT_Pos)) /* Assigment of value for PSCNT in the DMT_DMTPSCNT register */
#define DMT_DMTPSCNT_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (DMT_DMTPSCNT) Register Mask  */


/* -------- DMT_DMTPSCNTCLR : (DMT Offset: 0x64) (R/W 32) Bit clear register -------- */
#define DMT_DMTPSCNTCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (DMT_DMTPSCNTCLR) Bit clear register  Reset Value */

#define DMT_DMTPSCNTCLR_Msk                   _UINT32_(0x00000000)                                 /* (DMT_DMTPSCNTCLR) Register Mask  */


/* -------- DMT_DMTPSCNTSET : (DMT Offset: 0x68) (R/W 32) Bit set register -------- */
#define DMT_DMTPSCNTSET_RESETVALUE            _UINT32_(0x00)                                       /*  (DMT_DMTPSCNTSET) Bit set register  Reset Value */

#define DMT_DMTPSCNTSET_Msk                   _UINT32_(0x00000000)                                 /* (DMT_DMTPSCNTSET) Register Mask  */


/* -------- DMT_DMTPSCNTINV : (DMT Offset: 0x6C) (R/W 32) Bit invert register -------- */
#define DMT_DMTPSCNTINV_RESETVALUE            _UINT32_(0x00)                                       /*  (DMT_DMTPSCNTINV) Bit invert register  Reset Value */

#define DMT_DMTPSCNTINV_Msk                   _UINT32_(0x00000000)                                 /* (DMT_DMTPSCNTINV) Register Mask  */


/* -------- DMT_DMTPSINTV : (DMT Offset: 0x70) (R/W 32)  -------- */
#define DMT_DMTPSINTV_RESETVALUE              _UINT32_(0x00)                                       /*  (DMT_DMTPSINTV)   Reset Value */

#define DMT_DMTPSINTV_PSINTV_Pos              _UINT32_(0)                                          /* (DMT_DMTPSINTV)  Position */
#define DMT_DMTPSINTV_PSINTV_Msk              (_UINT32_(0xFFFFFFFF) << DMT_DMTPSINTV_PSINTV_Pos)   /* (DMT_DMTPSINTV)  Mask */
#define DMT_DMTPSINTV_PSINTV(value)           (DMT_DMTPSINTV_PSINTV_Msk & (_UINT32_(value) << DMT_DMTPSINTV_PSINTV_Pos)) /* Assigment of value for PSINTV in the DMT_DMTPSINTV register */
#define DMT_DMTPSINTV_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (DMT_DMTPSINTV) Register Mask  */


/* -------- DMT_DMTPSINTVCLR : (DMT Offset: 0x74) (R/W 32) Bit clear register -------- */
#define DMT_DMTPSINTVCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (DMT_DMTPSINTVCLR) Bit clear register  Reset Value */

#define DMT_DMTPSINTVCLR_Msk                  _UINT32_(0x00000000)                                 /* (DMT_DMTPSINTVCLR) Register Mask  */


/* -------- DMT_DMTPSINTVSET : (DMT Offset: 0x78) (R/W 32) Bit set register -------- */
#define DMT_DMTPSINTVSET_RESETVALUE           _UINT32_(0x00)                                       /*  (DMT_DMTPSINTVSET) Bit set register  Reset Value */

#define DMT_DMTPSINTVSET_Msk                  _UINT32_(0x00000000)                                 /* (DMT_DMTPSINTVSET) Register Mask  */


/* -------- DMT_DMTPSINTVINV : (DMT Offset: 0x7C) (R/W 32) Bit invert register -------- */
#define DMT_DMTPSINTVINV_RESETVALUE           _UINT32_(0x00)                                       /*  (DMT_DMTPSINTVINV) Bit invert register  Reset Value */

#define DMT_DMTPSINTVINV_Msk                  _UINT32_(0x00000000)                                 /* (DMT_DMTPSINTVINV) Register Mask  */


/** \brief DMT register offsets definitions */
#define DMT_DMTCON_REG_OFST            _UINT32_(0x00)      /* (DMT_DMTCON)  Offset */
#define DMT_DMTCONCLR_REG_OFST         _UINT32_(0x04)      /* (DMT_DMTCONCLR) Bit clear register Offset */
#define DMT_DMTCONSET_REG_OFST         _UINT32_(0x08)      /* (DMT_DMTCONSET) Bit set register Offset */
#define DMT_DMTCONINV_REG_OFST         _UINT32_(0x0C)      /* (DMT_DMTCONINV) Bit invert register Offset */
#define DMT_DMTPRECLR_REG_OFST         _UINT32_(0x10)      /* (DMT_DMTPRECLR)  Offset */
#define DMT_DMTPRECLRCLR_REG_OFST      _UINT32_(0x14)      /* (DMT_DMTPRECLRCLR) Bit clear register Offset */
#define DMT_DMTPRECLRSET_REG_OFST      _UINT32_(0x18)      /* (DMT_DMTPRECLRSET) Bit set register Offset */
#define DMT_DMTPRECLRINV_REG_OFST      _UINT32_(0x1C)      /* (DMT_DMTPRECLRINV) Bit invert register Offset */
#define DMT_DMTCLR_REG_OFST            _UINT32_(0x20)      /* (DMT_DMTCLR)  Offset */
#define DMT_DMTCLRCLR_REG_OFST         _UINT32_(0x24)      /* (DMT_DMTCLRCLR) Bit clear register Offset */
#define DMT_DMTCLRSET_REG_OFST         _UINT32_(0x28)      /* (DMT_DMTCLRSET) Bit set register Offset */
#define DMT_DMTCLRINV_REG_OFST         _UINT32_(0x2C)      /* (DMT_DMTCLRINV) Bit invert register Offset */
#define DMT_DMTSTAT_REG_OFST           _UINT32_(0x30)      /* (DMT_DMTSTAT)  Offset */
#define DMT_DMTSTATCLR_REG_OFST        _UINT32_(0x34)      /* (DMT_DMTSTATCLR) Bit clear register Offset */
#define DMT_DMTSTATSET_REG_OFST        _UINT32_(0x38)      /* (DMT_DMTSTATSET) Bit set register Offset */
#define DMT_DMTSTATINV_REG_OFST        _UINT32_(0x3C)      /* (DMT_DMTSTATINV) Bit invert register Offset */
#define DMT_DMTCNT_REG_OFST            _UINT32_(0x40)      /* (DMT_DMTCNT)  Offset */
#define DMT_DMTCNTCLR_REG_OFST         _UINT32_(0x44)      /* (DMT_DMTCNTCLR) Bit clear register Offset */
#define DMT_DMTCNTSET_REG_OFST         _UINT32_(0x48)      /* (DMT_DMTCNTSET) Bit set register Offset */
#define DMT_DMTCNTINV_REG_OFST         _UINT32_(0x4C)      /* (DMT_DMTCNTINV) Bit invert register Offset */
#define DMT_DMTHOLDREG_REG_OFST        _UINT32_(0x50)      /* (DMT_DMTHOLDREG)  Offset */
#define DMT_DMTHOLDREGCLR_REG_OFST     _UINT32_(0x54)      /* (DMT_DMTHOLDREGCLR) Bit clear register Offset */
#define DMT_DMTHOLDREGSET_REG_OFST     _UINT32_(0x58)      /* (DMT_DMTHOLDREGSET) Bit set register Offset */
#define DMT_DMTHOLDREGINV_REG_OFST     _UINT32_(0x5C)      /* (DMT_DMTHOLDREGINV) Bit invert register Offset */
#define DMT_DMTPSCNT_REG_OFST          _UINT32_(0x60)      /* (DMT_DMTPSCNT)  Offset */
#define DMT_DMTPSCNTCLR_REG_OFST       _UINT32_(0x64)      /* (DMT_DMTPSCNTCLR) Bit clear register Offset */
#define DMT_DMTPSCNTSET_REG_OFST       _UINT32_(0x68)      /* (DMT_DMTPSCNTSET) Bit set register Offset */
#define DMT_DMTPSCNTINV_REG_OFST       _UINT32_(0x6C)      /* (DMT_DMTPSCNTINV) Bit invert register Offset */
#define DMT_DMTPSINTV_REG_OFST         _UINT32_(0x70)      /* (DMT_DMTPSINTV)  Offset */
#define DMT_DMTPSINTVCLR_REG_OFST      _UINT32_(0x74)      /* (DMT_DMTPSINTVCLR) Bit clear register Offset */
#define DMT_DMTPSINTVSET_REG_OFST      _UINT32_(0x78)      /* (DMT_DMTPSINTVSET) Bit set register Offset */
#define DMT_DMTPSINTVINV_REG_OFST      _UINT32_(0x7C)      /* (DMT_DMTPSINTVINV) Bit invert register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief DMT register API structure */
typedef struct
{  /* Dead Man Timer */
  __IO  uint32_t                       DMT_DMTCON;         /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTCONCLR;      /**< Offset: 0x04 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTCONSET;      /**< Offset: 0x08 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTCONINV;      /**< Offset: 0x0C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTPRECLR;      /**< Offset: 0x10 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTPRECLRCLR;   /**< Offset: 0x14 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTPRECLRSET;   /**< Offset: 0x18 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTPRECLRINV;   /**< Offset: 0x1C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTCLR;         /**< Offset: 0x20 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTCLRCLR;      /**< Offset: 0x24 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTCLRSET;      /**< Offset: 0x28 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTCLRINV;      /**< Offset: 0x2C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTSTAT;        /**< Offset: 0x30 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTSTATCLR;     /**< Offset: 0x34 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTSTATSET;     /**< Offset: 0x38 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTSTATINV;     /**< Offset: 0x3C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTCNT;         /**< Offset: 0x40 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTCNTCLR;      /**< Offset: 0x44 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTCNTSET;      /**< Offset: 0x48 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTCNTINV;      /**< Offset: 0x4C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTHOLDREG;     /**< Offset: 0x50 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTHOLDREGCLR;  /**< Offset: 0x54 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTHOLDREGSET;  /**< Offset: 0x58 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTHOLDREGINV;  /**< Offset: 0x5C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTPSCNT;       /**< Offset: 0x60 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTPSCNTCLR;    /**< Offset: 0x64 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTPSCNTSET;    /**< Offset: 0x68 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTPSCNTINV;    /**< Offset: 0x6C (R/W  32) Bit invert register */
  __IO  uint32_t                       DMT_DMTPSINTV;      /**< Offset: 0x70 (R/W  32)  */
  __IO  uint32_t                       DMT_DMTPSINTVCLR;   /**< Offset: 0x74 (R/W  32) Bit clear register */
  __IO  uint32_t                       DMT_DMTPSINTVSET;   /**< Offset: 0x78 (R/W  32) Bit set register */
  __IO  uint32_t                       DMT_DMTPSINTVINV;   /**< Offset: 0x7C (R/W  32) Bit invert register */
} dmt_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_DMT_COMPONENT_H_ */
