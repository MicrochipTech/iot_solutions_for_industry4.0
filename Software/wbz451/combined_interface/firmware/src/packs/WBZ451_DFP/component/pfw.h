/*
 * Component description for PFW
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
#ifndef _BZ45_PFW_COMPONENT_H_
#define _BZ45_PFW_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PFW                                          */
/* ************************************************************************** */

/* -------- PFW_IFT_CON : (PFW Offset: 0x00) (R/W 32)  -------- */
#define PFW_IFT_CON_RESETVALUE                _UINT32_(0x00)                                       /*  (PFW_IFT_CON)   Reset Value */

#define PFW_IFT_CON_FRZ_Pos                   _UINT32_(13)                                         /* (PFW_IFT_CON)  Position */
#define PFW_IFT_CON_FRZ_Msk                   (_UINT32_(0x1) << PFW_IFT_CON_FRZ_Pos)               /* (PFW_IFT_CON)  Mask */
#define PFW_IFT_CON_FRZ(value)                (PFW_IFT_CON_FRZ_Msk & (_UINT32_(value) << PFW_IFT_CON_FRZ_Pos)) /* Assigment of value for FRZ in the PFW_IFT_CON register */
#define PFW_IFT_CON_SIDL_Pos                  _UINT32_(14)                                         /* (PFW_IFT_CON)  Position */
#define PFW_IFT_CON_SIDL_Msk                  (_UINT32_(0x1) << PFW_IFT_CON_SIDL_Pos)              /* (PFW_IFT_CON)  Mask */
#define PFW_IFT_CON_SIDL(value)               (PFW_IFT_CON_SIDL_Msk & (_UINT32_(value) << PFW_IFT_CON_SIDL_Pos)) /* Assigment of value for SIDL in the PFW_IFT_CON register */
#define PFW_IFT_CON_ON_Pos                    _UINT32_(15)                                         /* (PFW_IFT_CON)  Position */
#define PFW_IFT_CON_ON_Msk                    (_UINT32_(0x1) << PFW_IFT_CON_ON_Pos)                /* (PFW_IFT_CON)  Mask */
#define PFW_IFT_CON_ON(value)                 (PFW_IFT_CON_ON_Msk & (_UINT32_(value) << PFW_IFT_CON_ON_Pos)) /* Assigment of value for ON in the PFW_IFT_CON register */
#define PFW_IFT_CON_Msk                       _UINT32_(0x0000E000)                                 /* (PFW_IFT_CON) Register Mask  */


/* -------- PFW_IFT_CRCCON : (PFW Offset: 0x10) (R/W 32)  -------- */
#define PFW_IFT_CRCCON_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_CRCCON)   Reset Value */

#define PFW_IFT_CRCCON_AUTOR_Pos              _UINT32_(0)                                          /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_AUTOR_Msk              (_UINT32_(0x1) << PFW_IFT_CRCCON_AUTOR_Pos)          /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_AUTOR(value)           (PFW_IFT_CRCCON_AUTOR_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_AUTOR_Pos)) /* Assigment of value for AUTOR in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_RBITO_Pos              _UINT32_(1)                                          /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_RBITO_Msk              (_UINT32_(0x1) << PFW_IFT_CRCCON_RBITO_Pos)          /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_RBITO(value)           (PFW_IFT_CRCCON_RBITO_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_RBITO_Pos)) /* Assigment of value for RBITO in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_PAUSE_Pos              _UINT32_(2)                                          /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_PAUSE_Msk              (_UINT32_(0x1) << PFW_IFT_CRCCON_PAUSE_Pos)          /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_PAUSE(value)           (PFW_IFT_CRCCON_PAUSE_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_PAUSE_Pos)) /* Assigment of value for PAUSE in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_PLEN32_Pos             _UINT32_(12)                                         /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_PLEN32_Msk             (_UINT32_(0x1) << PFW_IFT_CRCCON_PLEN32_Pos)         /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_PLEN32(value)          (PFW_IFT_CRCCON_PLEN32_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_PLEN32_Pos)) /* Assigment of value for PLEN32 in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_ERROR_Pos              _UINT32_(13)                                         /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_ERROR_Msk              (_UINT32_(0x1) << PFW_IFT_CRCCON_ERROR_Pos)          /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_ERROR(value)           (PFW_IFT_CRCCON_ERROR_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_ERROR_Pos)) /* Assigment of value for ERROR in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_DONE_Pos               _UINT32_(14)                                         /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_DONE_Msk               (_UINT32_(0x1) << PFW_IFT_CRCCON_DONE_Pos)           /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_DONE(value)            (PFW_IFT_CRCCON_DONE_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_DONE_Pos)) /* Assigment of value for DONE in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_CRCEN_Pos              _UINT32_(15)                                         /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_CRCEN_Msk              (_UINT32_(0x1) << PFW_IFT_CRCCON_CRCEN_Pos)          /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_CRCEN(value)           (PFW_IFT_CRCCON_CRCEN_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_CRCEN_Pos)) /* Assigment of value for CRCEN in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_PERIOD_Pos             _UINT32_(16)                                         /* (PFW_IFT_CRCCON)  Position */
#define PFW_IFT_CRCCON_PERIOD_Msk             (_UINT32_(0xFFFF) << PFW_IFT_CRCCON_PERIOD_Pos)      /* (PFW_IFT_CRCCON)  Mask */
#define PFW_IFT_CRCCON_PERIOD(value)          (PFW_IFT_CRCCON_PERIOD_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_PERIOD_Pos)) /* Assigment of value for PERIOD in the PFW_IFT_CRCCON register */
#define PFW_IFT_CRCCON_Msk                    _UINT32_(0xFFFFF007)                                 /* (PFW_IFT_CRCCON) Register Mask  */

#define PFW_IFT_CRCCON_PLEN_Pos               _UINT32_(12)                                         /* (PFW_IFT_CRCCON Position)  */
#define PFW_IFT_CRCCON_PLEN_Msk               (_UINT32_(0x1) << PFW_IFT_CRCCON_PLEN_Pos)           /* (PFW_IFT_CRCCON Mask) PLEN */
#define PFW_IFT_CRCCON_PLEN(value)            (PFW_IFT_CRCCON_PLEN_Msk & (_UINT32_(value) << PFW_IFT_CRCCON_PLEN_Pos)) 

/* -------- PFW_IFT_CRCMADR : (PFW Offset: 0x20) (R/W 32)  -------- */
#define PFW_IFT_CRCMADR_RESETVALUE            _UINT32_(0x00)                                       /*  (PFW_IFT_CRCMADR)   Reset Value */

#define PFW_IFT_CRCMADR_IFT_CRCMADR_Pos       _UINT32_(0)                                          /* (PFW_IFT_CRCMADR)  Position */
#define PFW_IFT_CRCMADR_IFT_CRCMADR_Msk       (_UINT32_(0xFFFFFFFF) << PFW_IFT_CRCMADR_IFT_CRCMADR_Pos) /* (PFW_IFT_CRCMADR)  Mask */
#define PFW_IFT_CRCMADR_IFT_CRCMADR(value)    (PFW_IFT_CRCMADR_IFT_CRCMADR_Msk & (_UINT32_(value) << PFW_IFT_CRCMADR_IFT_CRCMADR_Pos)) /* Assigment of value for IFT_CRCMADR in the PFW_IFT_CRCMADR register */
#define PFW_IFT_CRCMADR_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_CRCMADR) Register Mask  */


/* -------- PFW_IFT_CRCMLEN : (PFW Offset: 0x30) (R/W 32)  -------- */
#define PFW_IFT_CRCMLEN_RESETVALUE            _UINT32_(0x00)                                       /*  (PFW_IFT_CRCMLEN)   Reset Value */

#define PFW_IFT_CRCMLEN_CRCMLEN_Pos           _UINT32_(0)                                          /* (PFW_IFT_CRCMLEN)  Position */
#define PFW_IFT_CRCMLEN_CRCMLEN_Msk           (_UINT32_(0xFFFFFF) << PFW_IFT_CRCMLEN_CRCMLEN_Pos)  /* (PFW_IFT_CRCMLEN)  Mask */
#define PFW_IFT_CRCMLEN_CRCMLEN(value)        (PFW_IFT_CRCMLEN_CRCMLEN_Msk & (_UINT32_(value) << PFW_IFT_CRCMLEN_CRCMLEN_Pos)) /* Assigment of value for CRCMLEN in the PFW_IFT_CRCMLEN register */
#define PFW_IFT_CRCMLEN_Msk                   _UINT32_(0x00FFFFFF)                                 /* (PFW_IFT_CRCMLEN) Register Mask  */


/* -------- PFW_IFT_CRCIV : (PFW Offset: 0x40) (R/W 32)  -------- */
#define PFW_IFT_CRCIV_RESETVALUE              _UINT32_(0x00)                                       /*  (PFW_IFT_CRCIV)   Reset Value */

#define PFW_IFT_CRCIV_CRCIV_Pos               _UINT32_(0)                                          /* (PFW_IFT_CRCIV)  Position */
#define PFW_IFT_CRCIV_CRCIV_Msk               (_UINT32_(0xFFFFFFFF) << PFW_IFT_CRCIV_CRCIV_Pos)    /* (PFW_IFT_CRCIV)  Mask */
#define PFW_IFT_CRCIV_CRCIV(value)            (PFW_IFT_CRCIV_CRCIV_Msk & (_UINT32_(value) << PFW_IFT_CRCIV_CRCIV_Pos)) /* Assigment of value for CRCIV in the PFW_IFT_CRCIV register */
#define PFW_IFT_CRCIV_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_CRCIV) Register Mask  */


/* -------- PFW_IFT_CRCACC : (PFW Offset: 0x50) (R/W 32)  -------- */
#define PFW_IFT_CRCACC_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_CRCACC)   Reset Value */

#define PFW_IFT_CRCACC_CRCACC_Pos             _UINT32_(0)                                          /* (PFW_IFT_CRCACC)  Position */
#define PFW_IFT_CRCACC_CRCACC_Msk             (_UINT32_(0xFFFFFFFF) << PFW_IFT_CRCACC_CRCACC_Pos)  /* (PFW_IFT_CRCACC)  Mask */
#define PFW_IFT_CRCACC_CRCACC(value)          (PFW_IFT_CRCACC_CRCACC_Msk & (_UINT32_(value) << PFW_IFT_CRCACC_CRCACC_Pos)) /* Assigment of value for CRCACC in the PFW_IFT_CRCACC register */
#define PFW_IFT_CRCACC_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_CRCACC) Register Mask  */


/* -------- PFW_IFT_CRCPOLY : (PFW Offset: 0x60) (R/W 32)  -------- */
#define PFW_IFT_CRCPOLY_RESETVALUE            _UINT32_(0x00)                                       /*  (PFW_IFT_CRCPOLY)   Reset Value */

#define PFW_IFT_CRCPOLY_CYCPOLY_Pos           _UINT32_(0)                                          /* (PFW_IFT_CRCPOLY)  Position */
#define PFW_IFT_CRCPOLY_CYCPOLY_Msk           (_UINT32_(0xFFFFFFFF) << PFW_IFT_CRCPOLY_CYCPOLY_Pos) /* (PFW_IFT_CRCPOLY)  Mask */
#define PFW_IFT_CRCPOLY_CYCPOLY(value)        (PFW_IFT_CRCPOLY_CYCPOLY_Msk & (_UINT32_(value) << PFW_IFT_CRCPOLY_CYCPOLY_Pos)) /* Assigment of value for CYCPOLY in the PFW_IFT_CRCPOLY register */
#define PFW_IFT_CRCPOLY_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_CRCPOLY) Register Mask  */


/* -------- PFW_IFT_CRCFXOR : (PFW Offset: 0x70) (R/W 32)  -------- */
#define PFW_IFT_CRCFXOR_RESETVALUE            _UINT32_(0x00)                                       /*  (PFW_IFT_CRCFXOR)   Reset Value */

#define PFW_IFT_CRCFXOR_CRCFXOR_Pos           _UINT32_(0)                                          /* (PFW_IFT_CRCFXOR)  Position */
#define PFW_IFT_CRCFXOR_CRCFXOR_Msk           (_UINT32_(0xFFFFFFFF) << PFW_IFT_CRCFXOR_CRCFXOR_Pos) /* (PFW_IFT_CRCFXOR)  Mask */
#define PFW_IFT_CRCFXOR_CRCFXOR(value)        (PFW_IFT_CRCFXOR_CRCFXOR_Msk & (_UINT32_(value) << PFW_IFT_CRCFXOR_CRCFXOR_Pos)) /* Assigment of value for CRCFXOR in the PFW_IFT_CRCFXOR register */
#define PFW_IFT_CRCFXOR_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_CRCFXOR) Register Mask  */


/* -------- PFW_IFT_CRCSUM : (PFW Offset: 0x80) (R/W 32)  -------- */
#define PFW_IFT_CRCSUM_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_CRCSUM)   Reset Value */

#define PFW_IFT_CRCSUM_CRCSUM_Pos             _UINT32_(0)                                          /* (PFW_IFT_CRCSUM)  Position */
#define PFW_IFT_CRCSUM_CRCSUM_Msk             (_UINT32_(0xFFFFFFFF) << PFW_IFT_CRCSUM_CRCSUM_Pos)  /* (PFW_IFT_CRCSUM)  Mask */
#define PFW_IFT_CRCSUM_CRCSUM(value)          (PFW_IFT_CRCSUM_CRCSUM_Msk & (_UINT32_(value) << PFW_IFT_CRCSUM_CRCSUM_Pos)) /* Assigment of value for CRCSUM in the PFW_IFT_CRCSUM register */
#define PFW_IFT_CRCSUM_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_CRCSUM) Register Mask  */


/* -------- PFW_IFT_ECCCON : (PFW Offset: 0x90) (R/W 32)  -------- */
#define PFW_IFT_ECCCON_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_ECCCON)   Reset Value */

#define PFW_IFT_ECCCON_FLT_MD_Pos             _UINT32_(0)                                          /* (PFW_IFT_ECCCON)  Position */
#define PFW_IFT_ECCCON_FLT_MD_Msk             (_UINT32_(0x7) << PFW_IFT_ECCCON_FLT_MD_Pos)         /* (PFW_IFT_ECCCON)  Mask */
#define PFW_IFT_ECCCON_FLT_MD(value)          (PFW_IFT_ECCCON_FLT_MD_Msk & (_UINT32_(value) << PFW_IFT_ECCCON_FLT_MD_Pos)) /* Assigment of value for FLT_MD in the PFW_IFT_ECCCON register */
#define PFW_IFT_ECCCON_EVENT_Pos              _UINT32_(7)                                          /* (PFW_IFT_ECCCON)  Position */
#define PFW_IFT_ECCCON_EVENT_Msk              (_UINT32_(0x1) << PFW_IFT_ECCCON_EVENT_Pos)          /* (PFW_IFT_ECCCON)  Mask */
#define PFW_IFT_ECCCON_EVENT(value)           (PFW_IFT_ECCCON_EVENT_Msk & (_UINT32_(value) << PFW_IFT_ECCCON_EVENT_Pos)) /* Assigment of value for EVENT in the PFW_IFT_ECCCON register */
#define PFW_IFT_ECCCON_CTLFLT_Pos             _UINT32_(8)                                          /* (PFW_IFT_ECCCON)  Position */
#define PFW_IFT_ECCCON_CTLFLT_Msk             (_UINT32_(0x7) << PFW_IFT_ECCCON_CTLFLT_Pos)         /* (PFW_IFT_ECCCON)  Mask */
#define PFW_IFT_ECCCON_CTLFLT(value)          (PFW_IFT_ECCCON_CTLFLT_Msk & (_UINT32_(value) << PFW_IFT_ECCCON_CTLFLT_Pos)) /* Assigment of value for CTLFLT in the PFW_IFT_ECCCON register */
#define PFW_IFT_ECCCON_FLTEN_Pos              _UINT32_(15)                                         /* (PFW_IFT_ECCCON)  Position */
#define PFW_IFT_ECCCON_FLTEN_Msk              (_UINT32_(0x1) << PFW_IFT_ECCCON_FLTEN_Pos)          /* (PFW_IFT_ECCCON)  Mask */
#define PFW_IFT_ECCCON_FLTEN(value)           (PFW_IFT_ECCCON_FLTEN_Msk & (_UINT32_(value) << PFW_IFT_ECCCON_FLTEN_Pos)) /* Assigment of value for FLTEN in the PFW_IFT_ECCCON register */
#define PFW_IFT_ECCCON_Msk                    _UINT32_(0x00008787)                                 /* (PFW_IFT_ECCCON) Register Mask  */


/* -------- PFW_IFT_ECCFLT : (PFW Offset: 0xA0) (R/W 32)  -------- */
#define PFW_IFT_ECCFLT_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_ECCFLT)   Reset Value */

#define PFW_IFT_ECCFLT_FLT1PTR_Pos            _UINT32_(0)                                          /* (PFW_IFT_ECCFLT)  Position */
#define PFW_IFT_ECCFLT_FLT1PTR_Msk            (_UINT32_(0x1FF) << PFW_IFT_ECCFLT_FLT1PTR_Pos)      /* (PFW_IFT_ECCFLT)  Mask */
#define PFW_IFT_ECCFLT_FLT1PTR(value)         (PFW_IFT_ECCFLT_FLT1PTR_Msk & (_UINT32_(value) << PFW_IFT_ECCFLT_FLT1PTR_Pos)) /* Assigment of value for FLT1PTR in the PFW_IFT_ECCFLT register */
#define PFW_IFT_ECCFLT_FLT2PTR_Pos            _UINT32_(16)                                         /* (PFW_IFT_ECCFLT)  Position */
#define PFW_IFT_ECCFLT_FLT2PTR_Msk            (_UINT32_(0x1FF) << PFW_IFT_ECCFLT_FLT2PTR_Pos)      /* (PFW_IFT_ECCFLT)  Mask */
#define PFW_IFT_ECCFLT_FLT2PTR(value)         (PFW_IFT_ECCFLT_FLT2PTR_Msk & (_UINT32_(value) << PFW_IFT_ECCFLT_FLT2PTR_Pos)) /* Assigment of value for FLT2PTR in the PFW_IFT_ECCFLT register */
#define PFW_IFT_ECCFLT_Msk                    _UINT32_(0x01FF01FF)                                 /* (PFW_IFT_ECCFLT) Register Mask  */


/* -------- PFW_IFT_ECCADR : (PFW Offset: 0xB0) (R/W 32)  -------- */
#define PFW_IFT_ECCADR_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_ECCADR)   Reset Value */

#define PFW_IFT_ECCADR_ECCADR_Pos             _UINT32_(0)                                          /* (PFW_IFT_ECCADR)  Position */
#define PFW_IFT_ECCADR_ECCADR_Msk             (_UINT32_(0xFFFFFFFF) << PFW_IFT_ECCADR_ECCADR_Pos)  /* (PFW_IFT_ECCADR)  Mask */
#define PFW_IFT_ECCADR_ECCADR(value)          (PFW_IFT_ECCADR_ECCADR_Msk & (_UINT32_(value) << PFW_IFT_ECCADR_ECCADR_Pos)) /* Assigment of value for ECCADR in the PFW_IFT_ECCADR register */
#define PFW_IFT_ECCADR_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (PFW_IFT_ECCADR) Register Mask  */


/* -------- PFW_IFT_ECCPAR : (PFW Offset: 0xC0) (R/W 32)  -------- */
#define PFW_IFT_ECCPAR_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_ECCPAR)   Reset Value */

#define PFW_IFT_ECCPAR_SECIN_Pos              _UINT32_(0)                                          /* (PFW_IFT_ECCPAR)  Position */
#define PFW_IFT_ECCPAR_SECIN_Msk              (_UINT32_(0x1FF) << PFW_IFT_ECCPAR_SECIN_Pos)        /* (PFW_IFT_ECCPAR)  Mask */
#define PFW_IFT_ECCPAR_SECIN(value)           (PFW_IFT_ECCPAR_SECIN_Msk & (_UINT32_(value) << PFW_IFT_ECCPAR_SECIN_Pos)) /* Assigment of value for SECIN in the PFW_IFT_ECCPAR register */
#define PFW_IFT_ECCPAR_DEDIN_Pos              _UINT32_(15)                                         /* (PFW_IFT_ECCPAR)  Position */
#define PFW_IFT_ECCPAR_DEDIN_Msk              (_UINT32_(0x1) << PFW_IFT_ECCPAR_DEDIN_Pos)          /* (PFW_IFT_ECCPAR)  Mask */
#define PFW_IFT_ECCPAR_DEDIN(value)           (PFW_IFT_ECCPAR_DEDIN_Msk & (_UINT32_(value) << PFW_IFT_ECCPAR_DEDIN_Pos)) /* Assigment of value for DEDIN in the PFW_IFT_ECCPAR register */
#define PFW_IFT_ECCPAR_SECOUT_Pos             _UINT32_(16)                                         /* (PFW_IFT_ECCPAR)  Position */
#define PFW_IFT_ECCPAR_SECOUT_Msk             (_UINT32_(0x1FF) << PFW_IFT_ECCPAR_SECOUT_Pos)       /* (PFW_IFT_ECCPAR)  Mask */
#define PFW_IFT_ECCPAR_SECOUT(value)          (PFW_IFT_ECCPAR_SECOUT_Msk & (_UINT32_(value) << PFW_IFT_ECCPAR_SECOUT_Pos)) /* Assigment of value for SECOUT in the PFW_IFT_ECCPAR register */
#define PFW_IFT_ECCPAR_DEDOUT_Pos             _UINT32_(31)                                         /* (PFW_IFT_ECCPAR)  Position */
#define PFW_IFT_ECCPAR_DEDOUT_Msk             (_UINT32_(0x1) << PFW_IFT_ECCPAR_DEDOUT_Pos)         /* (PFW_IFT_ECCPAR)  Mask */
#define PFW_IFT_ECCPAR_DEDOUT(value)          (PFW_IFT_ECCPAR_DEDOUT_Msk & (_UINT32_(value) << PFW_IFT_ECCPAR_DEDOUT_Pos)) /* Assigment of value for DEDOUT in the PFW_IFT_ECCPAR register */
#define PFW_IFT_ECCPAR_Msk                    _UINT32_(0x81FF81FF)                                 /* (PFW_IFT_ECCPAR) Register Mask  */


/* -------- PFW_IFT_ECCSYN : (PFW Offset: 0xD0) (R/W 32)  -------- */
#define PFW_IFT_ECCSYN_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_IFT_ECCSYN)   Reset Value */

#define PFW_IFT_ECCSYN_SECSYN_Pos             _UINT32_(0)                                          /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_SECSYN_Msk             (_UINT32_(0x1FF) << PFW_IFT_ECCSYN_SECSYN_Pos)       /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_SECSYN(value)          (PFW_IFT_ECCSYN_SECSYN_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_SECSYN_Pos)) /* Assigment of value for SECSYN in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_DEDSYS_Pos             _UINT32_(15)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_DEDSYS_Msk             (_UINT32_(0x1) << PFW_IFT_ECCSYN_DEDSYS_Pos)         /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_DEDSYS(value)          (PFW_IFT_ECCSYN_DEDSYS_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_DEDSYS_Pos)) /* Assigment of value for DEDSYS in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_SERR_Pos               _UINT32_(16)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_SERR_Msk               (_UINT32_(0x1) << PFW_IFT_ECCSYN_SERR_Pos)           /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_SERR(value)            (PFW_IFT_ECCSYN_SERR_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_SERR_Pos)) /* Assigment of value for SERR in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_DERR_Pos               _UINT32_(17)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_DERR_Msk               (_UINT32_(0x1) << PFW_IFT_ECCSYN_DERR_Pos)           /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_DERR(value)            (PFW_IFT_ECCSYN_DERR_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_DERR_Pos)) /* Assigment of value for DERR in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_CERR_Pos               _UINT32_(18)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_CERR_Msk               (_UINT32_(0x1) << PFW_IFT_ECCSYN_CERR_Pos)           /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_CERR(value)            (PFW_IFT_ECCSYN_CERR_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_CERR_Pos)) /* Assigment of value for CERR in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_CTLSTAT_Pos            _UINT32_(24)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_CTLSTAT_Msk            (_UINT32_(0x7) << PFW_IFT_ECCSYN_CTLSTAT_Pos)        /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_CTLSTAT(value)         (PFW_IFT_ECCSYN_CTLSTAT_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_CTLSTAT_Pos)) /* Assigment of value for CTLSTAT in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_PERR0_Pos              _UINT32_(28)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_PERR0_Msk              (_UINT32_(0x1) << PFW_IFT_ECCSYN_PERR0_Pos)          /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_PERR0(value)           (PFW_IFT_ECCSYN_PERR0_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_PERR0_Pos)) /* Assigment of value for PERR0 in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_PERR1_Pos              _UINT32_(29)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_PERR1_Msk              (_UINT32_(0x1) << PFW_IFT_ECCSYN_PERR1_Pos)          /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_PERR1(value)           (PFW_IFT_ECCSYN_PERR1_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_PERR1_Pos)) /* Assigment of value for PERR1 in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_PERR2_Pos              _UINT32_(30)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_PERR2_Msk              (_UINT32_(0x1) << PFW_IFT_ECCSYN_PERR2_Pos)          /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_PERR2(value)           (PFW_IFT_ECCSYN_PERR2_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_PERR2_Pos)) /* Assigment of value for PERR2 in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_PERR3_Pos              _UINT32_(31)                                         /* (PFW_IFT_ECCSYN)  Position */
#define PFW_IFT_ECCSYN_PERR3_Msk              (_UINT32_(0x1) << PFW_IFT_ECCSYN_PERR3_Pos)          /* (PFW_IFT_ECCSYN)  Mask */
#define PFW_IFT_ECCSYN_PERR3(value)           (PFW_IFT_ECCSYN_PERR3_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_PERR3_Pos)) /* Assigment of value for PERR3 in the PFW_IFT_ECCSYN register */
#define PFW_IFT_ECCSYN_Msk                    _UINT32_(0xF70781FF)                                 /* (PFW_IFT_ECCSYN) Register Mask  */

#define PFW_IFT_ECCSYN_PERR_Pos               _UINT32_(28)                                         /* (PFW_IFT_ECCSYN Position)  */
#define PFW_IFT_ECCSYN_PERR_Msk               (_UINT32_(0xF) << PFW_IFT_ECCSYN_PERR_Pos)           /* (PFW_IFT_ECCSYN Mask) PERR */
#define PFW_IFT_ECCSYN_PERR(value)            (PFW_IFT_ECCSYN_PERR_Msk & (_UINT32_(value) << PFW_IFT_ECCSYN_PERR_Pos)) 

/* -------- PFW_DFT_VALCON : (PFW Offset: 0xF0) (R/W 32)  -------- */
#define PFW_DFT_VALCON_RESETVALUE             _UINT32_(0x00)                                       /*  (PFW_DFT_VALCON)   Reset Value */

#define PFW_DFT_VALCON_VAL_ON_Pos             _UINT32_(15)                                         /* (PFW_DFT_VALCON)  Position */
#define PFW_DFT_VALCON_VAL_ON_Msk             (_UINT32_(0x1) << PFW_DFT_VALCON_VAL_ON_Pos)         /* (PFW_DFT_VALCON)  Mask */
#define PFW_DFT_VALCON_VAL_ON(value)          (PFW_DFT_VALCON_VAL_ON_Msk & (_UINT32_(value) << PFW_DFT_VALCON_VAL_ON_Pos)) /* Assigment of value for VAL_ON in the PFW_DFT_VALCON register */
#define PFW_DFT_VALCON_Msk                    _UINT32_(0x00008000)                                 /* (PFW_DFT_VALCON) Register Mask  */


/* -------- PFW_DFT_VALP1RR01 : (PFW Offset: 0x100) (R/W 32)  -------- */
#define PFW_DFT_VALP1RR01_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP1RR01)   Reset Value */

#define PFW_DFT_VALP1RR01_PR1RR0_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP1RR01)  Position */
#define PFW_DFT_VALP1RR01_PR1RR0_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR01_PR1RR0_Pos)   /* (PFW_DFT_VALP1RR01)  Mask */
#define PFW_DFT_VALP1RR01_PR1RR0(value)       (PFW_DFT_VALP1RR01_PR1RR0_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR01_PR1RR0_Pos)) /* Assigment of value for PR1RR0 in the PFW_DFT_VALP1RR01 register */
#define PFW_DFT_VALP1RR01_P1RR1_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP1RR01)  Position */
#define PFW_DFT_VALP1RR01_P1RR1_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR01_P1RR1_Pos)    /* (PFW_DFT_VALP1RR01)  Mask */
#define PFW_DFT_VALP1RR01_P1RR1(value)        (PFW_DFT_VALP1RR01_P1RR1_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR01_P1RR1_Pos)) /* Assigment of value for P1RR1 in the PFW_DFT_VALP1RR01 register */
#define PFW_DFT_VALP1RR01_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP1RR01) Register Mask  */


/* -------- PFW_DFT_VALP1RR23 : (PFW Offset: 0x110) (R/W 32)  -------- */
#define PFW_DFT_VALP1RR23_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP1RR23)   Reset Value */

#define PFW_DFT_VALP1RR23_PR1RR2_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP1RR23)  Position */
#define PFW_DFT_VALP1RR23_PR1RR2_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR23_PR1RR2_Pos)   /* (PFW_DFT_VALP1RR23)  Mask */
#define PFW_DFT_VALP1RR23_PR1RR2(value)       (PFW_DFT_VALP1RR23_PR1RR2_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR23_PR1RR2_Pos)) /* Assigment of value for PR1RR2 in the PFW_DFT_VALP1RR23 register */
#define PFW_DFT_VALP1RR23_P1RR3_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP1RR23)  Position */
#define PFW_DFT_VALP1RR23_P1RR3_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR23_P1RR3_Pos)    /* (PFW_DFT_VALP1RR23)  Mask */
#define PFW_DFT_VALP1RR23_P1RR3(value)        (PFW_DFT_VALP1RR23_P1RR3_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR23_P1RR3_Pos)) /* Assigment of value for P1RR3 in the PFW_DFT_VALP1RR23 register */
#define PFW_DFT_VALP1RR23_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP1RR23) Register Mask  */


/* -------- PFW_DFT_VALP1RR45 : (PFW Offset: 0x120) (R/W 32)  -------- */
#define PFW_DFT_VALP1RR45_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP1RR45)   Reset Value */

#define PFW_DFT_VALP1RR45_PR1RR4_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP1RR45)  Position */
#define PFW_DFT_VALP1RR45_PR1RR4_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR45_PR1RR4_Pos)   /* (PFW_DFT_VALP1RR45)  Mask */
#define PFW_DFT_VALP1RR45_PR1RR4(value)       (PFW_DFT_VALP1RR45_PR1RR4_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR45_PR1RR4_Pos)) /* Assigment of value for PR1RR4 in the PFW_DFT_VALP1RR45 register */
#define PFW_DFT_VALP1RR45_P1RR5_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP1RR45)  Position */
#define PFW_DFT_VALP1RR45_P1RR5_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR45_P1RR5_Pos)    /* (PFW_DFT_VALP1RR45)  Mask */
#define PFW_DFT_VALP1RR45_P1RR5(value)        (PFW_DFT_VALP1RR45_P1RR5_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR45_P1RR5_Pos)) /* Assigment of value for P1RR5 in the PFW_DFT_VALP1RR45 register */
#define PFW_DFT_VALP1RR45_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP1RR45) Register Mask  */


/* -------- PFW_DFT_VALP1RR67 : (PFW Offset: 0x130) (R/W 32)  -------- */
#define PFW_DFT_VALP1RR67_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP1RR67)   Reset Value */

#define PFW_DFT_VALP1RR67_PR1RR6_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP1RR67)  Position */
#define PFW_DFT_VALP1RR67_PR1RR6_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR67_PR1RR6_Pos)   /* (PFW_DFT_VALP1RR67)  Mask */
#define PFW_DFT_VALP1RR67_PR1RR6(value)       (PFW_DFT_VALP1RR67_PR1RR6_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR67_PR1RR6_Pos)) /* Assigment of value for PR1RR6 in the PFW_DFT_VALP1RR67 register */
#define PFW_DFT_VALP1RR67_P1RR7_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP1RR67)  Position */
#define PFW_DFT_VALP1RR67_P1RR7_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP1RR67_P1RR7_Pos)    /* (PFW_DFT_VALP1RR67)  Mask */
#define PFW_DFT_VALP1RR67_P1RR7(value)        (PFW_DFT_VALP1RR67_P1RR7_Msk & (_UINT32_(value) << PFW_DFT_VALP1RR67_P1RR7_Pos)) /* Assigment of value for P1RR7 in the PFW_DFT_VALP1RR67 register */
#define PFW_DFT_VALP1RR67_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP1RR67) Register Mask  */


/* -------- PFW_DFT_VALP2RR01 : (PFW Offset: 0x140) (R/W 32)  -------- */
#define PFW_DFT_VALP2RR01_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP2RR01)   Reset Value */

#define PFW_DFT_VALP2RR01_PR2RR0_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP2RR01)  Position */
#define PFW_DFT_VALP2RR01_PR2RR0_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR01_PR2RR0_Pos)   /* (PFW_DFT_VALP2RR01)  Mask */
#define PFW_DFT_VALP2RR01_PR2RR0(value)       (PFW_DFT_VALP2RR01_PR2RR0_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR01_PR2RR0_Pos)) /* Assigment of value for PR2RR0 in the PFW_DFT_VALP2RR01 register */
#define PFW_DFT_VALP2RR01_P2RR1_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP2RR01)  Position */
#define PFW_DFT_VALP2RR01_P2RR1_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR01_P2RR1_Pos)    /* (PFW_DFT_VALP2RR01)  Mask */
#define PFW_DFT_VALP2RR01_P2RR1(value)        (PFW_DFT_VALP2RR01_P2RR1_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR01_P2RR1_Pos)) /* Assigment of value for P2RR1 in the PFW_DFT_VALP2RR01 register */
#define PFW_DFT_VALP2RR01_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP2RR01) Register Mask  */


/* -------- PFW_DFT_VALP2RR23 : (PFW Offset: 0x150) (R/W 32)  -------- */
#define PFW_DFT_VALP2RR23_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP2RR23)   Reset Value */

#define PFW_DFT_VALP2RR23_PR2RR2_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP2RR23)  Position */
#define PFW_DFT_VALP2RR23_PR2RR2_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR23_PR2RR2_Pos)   /* (PFW_DFT_VALP2RR23)  Mask */
#define PFW_DFT_VALP2RR23_PR2RR2(value)       (PFW_DFT_VALP2RR23_PR2RR2_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR23_PR2RR2_Pos)) /* Assigment of value for PR2RR2 in the PFW_DFT_VALP2RR23 register */
#define PFW_DFT_VALP2RR23_P2RR3_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP2RR23)  Position */
#define PFW_DFT_VALP2RR23_P2RR3_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR23_P2RR3_Pos)    /* (PFW_DFT_VALP2RR23)  Mask */
#define PFW_DFT_VALP2RR23_P2RR3(value)        (PFW_DFT_VALP2RR23_P2RR3_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR23_P2RR3_Pos)) /* Assigment of value for P2RR3 in the PFW_DFT_VALP2RR23 register */
#define PFW_DFT_VALP2RR23_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP2RR23) Register Mask  */


/* -------- PFW_DFT_VALP2RR45 : (PFW Offset: 0x160) (R/W 32)  -------- */
#define PFW_DFT_VALP2RR45_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP2RR45)   Reset Value */

#define PFW_DFT_VALP2RR45_PR2RR4_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP2RR45)  Position */
#define PFW_DFT_VALP2RR45_PR2RR4_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR45_PR2RR4_Pos)   /* (PFW_DFT_VALP2RR45)  Mask */
#define PFW_DFT_VALP2RR45_PR2RR4(value)       (PFW_DFT_VALP2RR45_PR2RR4_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR45_PR2RR4_Pos)) /* Assigment of value for PR2RR4 in the PFW_DFT_VALP2RR45 register */
#define PFW_DFT_VALP2RR45_P2RR5_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP2RR45)  Position */
#define PFW_DFT_VALP2RR45_P2RR5_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR45_P2RR5_Pos)    /* (PFW_DFT_VALP2RR45)  Mask */
#define PFW_DFT_VALP2RR45_P2RR5(value)        (PFW_DFT_VALP2RR45_P2RR5_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR45_P2RR5_Pos)) /* Assigment of value for P2RR5 in the PFW_DFT_VALP2RR45 register */
#define PFW_DFT_VALP2RR45_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP2RR45) Register Mask  */


/* -------- PFW_DFT_VALP2RR67 : (PFW Offset: 0x170) (R/W 32)  -------- */
#define PFW_DFT_VALP2RR67_RESETVALUE          _UINT32_(0x00)                                       /*  (PFW_DFT_VALP2RR67)   Reset Value */

#define PFW_DFT_VALP2RR67_PR2RR6_Pos          _UINT32_(0)                                          /* (PFW_DFT_VALP2RR67)  Position */
#define PFW_DFT_VALP2RR67_PR2RR6_Msk          (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR67_PR2RR6_Pos)   /* (PFW_DFT_VALP2RR67)  Mask */
#define PFW_DFT_VALP2RR67_PR2RR6(value)       (PFW_DFT_VALP2RR67_PR2RR6_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR67_PR2RR6_Pos)) /* Assigment of value for PR2RR6 in the PFW_DFT_VALP2RR67 register */
#define PFW_DFT_VALP2RR67_P2RR7_Pos           _UINT32_(16)                                         /* (PFW_DFT_VALP2RR67)  Position */
#define PFW_DFT_VALP2RR67_P2RR7_Msk           (_UINT32_(0xFFFF) << PFW_DFT_VALP2RR67_P2RR7_Pos)    /* (PFW_DFT_VALP2RR67)  Mask */
#define PFW_DFT_VALP2RR67_P2RR7(value)        (PFW_DFT_VALP2RR67_P2RR7_Msk & (_UINT32_(value) << PFW_DFT_VALP2RR67_P2RR7_Pos)) /* Assigment of value for P2RR7 in the PFW_DFT_VALP2RR67 register */
#define PFW_DFT_VALP2RR67_Msk                 _UINT32_(0xFFFFFFFF)                                 /* (PFW_DFT_VALP2RR67) Register Mask  */


/** \brief PFW register offsets definitions */
#define PFW_IFT_CON_REG_OFST           _UINT32_(0x00)      /* (PFW_IFT_CON)  Offset */
#define PFW_IFT_CRCCON_REG_OFST        _UINT32_(0x10)      /* (PFW_IFT_CRCCON)  Offset */
#define PFW_IFT_CRCMADR_REG_OFST       _UINT32_(0x20)      /* (PFW_IFT_CRCMADR)  Offset */
#define PFW_IFT_CRCMLEN_REG_OFST       _UINT32_(0x30)      /* (PFW_IFT_CRCMLEN)  Offset */
#define PFW_IFT_CRCIV_REG_OFST         _UINT32_(0x40)      /* (PFW_IFT_CRCIV)  Offset */
#define PFW_IFT_CRCACC_REG_OFST        _UINT32_(0x50)      /* (PFW_IFT_CRCACC)  Offset */
#define PFW_IFT_CRCPOLY_REG_OFST       _UINT32_(0x60)      /* (PFW_IFT_CRCPOLY)  Offset */
#define PFW_IFT_CRCFXOR_REG_OFST       _UINT32_(0x70)      /* (PFW_IFT_CRCFXOR)  Offset */
#define PFW_IFT_CRCSUM_REG_OFST        _UINT32_(0x80)      /* (PFW_IFT_CRCSUM)  Offset */
#define PFW_IFT_ECCCON_REG_OFST        _UINT32_(0x90)      /* (PFW_IFT_ECCCON)  Offset */
#define PFW_IFT_ECCFLT_REG_OFST        _UINT32_(0xA0)      /* (PFW_IFT_ECCFLT)  Offset */
#define PFW_IFT_ECCADR_REG_OFST        _UINT32_(0xB0)      /* (PFW_IFT_ECCADR)  Offset */
#define PFW_IFT_ECCPAR_REG_OFST        _UINT32_(0xC0)      /* (PFW_IFT_ECCPAR)  Offset */
#define PFW_IFT_ECCSYN_REG_OFST        _UINT32_(0xD0)      /* (PFW_IFT_ECCSYN)  Offset */
#define PFW_DFT_VALCON_REG_OFST        _UINT32_(0xF0)      /* (PFW_DFT_VALCON)  Offset */
#define PFW_DFT_VALP1RR01_REG_OFST     _UINT32_(0x100)     /* (PFW_DFT_VALP1RR01)  Offset */
#define PFW_DFT_VALP1RR23_REG_OFST     _UINT32_(0x110)     /* (PFW_DFT_VALP1RR23)  Offset */
#define PFW_DFT_VALP1RR45_REG_OFST     _UINT32_(0x120)     /* (PFW_DFT_VALP1RR45)  Offset */
#define PFW_DFT_VALP1RR67_REG_OFST     _UINT32_(0x130)     /* (PFW_DFT_VALP1RR67)  Offset */
#define PFW_DFT_VALP2RR01_REG_OFST     _UINT32_(0x140)     /* (PFW_DFT_VALP2RR01)  Offset */
#define PFW_DFT_VALP2RR23_REG_OFST     _UINT32_(0x150)     /* (PFW_DFT_VALP2RR23)  Offset */
#define PFW_DFT_VALP2RR45_REG_OFST     _UINT32_(0x160)     /* (PFW_DFT_VALP2RR45)  Offset */
#define PFW_DFT_VALP2RR67_REG_OFST     _UINT32_(0x170)     /* (PFW_DFT_VALP2RR67)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PFW register API structure */
typedef struct
{  /* flash wrapper */
  __IO  uint32_t                       PFW_IFT_CON;        /**< Offset: 0x00 (R/W  32)  */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCCON;     /**< Offset: 0x10 (R/W  32)  */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCMADR;    /**< Offset: 0x20 (R/W  32)  */
  __I   uint8_t                        Reserved3[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCMLEN;    /**< Offset: 0x30 (R/W  32)  */
  __I   uint8_t                        Reserved4[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCIV;      /**< Offset: 0x40 (R/W  32)  */
  __I   uint8_t                        Reserved5[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCACC;     /**< Offset: 0x50 (R/W  32)  */
  __I   uint8_t                        Reserved6[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCPOLY;    /**< Offset: 0x60 (R/W  32)  */
  __I   uint8_t                        Reserved7[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCFXOR;    /**< Offset: 0x70 (R/W  32)  */
  __I   uint8_t                        Reserved8[0x0C];
  __IO  uint32_t                       PFW_IFT_CRCSUM;     /**< Offset: 0x80 (R/W  32)  */
  __I   uint8_t                        Reserved9[0x0C];
  __IO  uint32_t                       PFW_IFT_ECCCON;     /**< Offset: 0x90 (R/W  32)  */
  __I   uint8_t                        Reserved10[0x0C];
  __IO  uint32_t                       PFW_IFT_ECCFLT;     /**< Offset: 0xA0 (R/W  32)  */
  __I   uint8_t                        Reserved11[0x0C];
  __IO  uint32_t                       PFW_IFT_ECCADR;     /**< Offset: 0xB0 (R/W  32)  */
  __I   uint8_t                        Reserved12[0x0C];
  __IO  uint32_t                       PFW_IFT_ECCPAR;     /**< Offset: 0xC0 (R/W  32)  */
  __I   uint8_t                        Reserved13[0x0C];
  __IO  uint32_t                       PFW_IFT_ECCSYN;     /**< Offset: 0xD0 (R/W  32)  */
  __I   uint8_t                        Reserved14[0x1C];
  __IO  uint32_t                       PFW_DFT_VALCON;     /**< Offset: 0xF0 (R/W  32)  */
  __I   uint8_t                        Reserved15[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP1RR01;  /**< Offset: 0x100 (R/W  32)  */
  __I   uint8_t                        Reserved16[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP1RR23;  /**< Offset: 0x110 (R/W  32)  */
  __I   uint8_t                        Reserved17[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP1RR45;  /**< Offset: 0x120 (R/W  32)  */
  __I   uint8_t                        Reserved18[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP1RR67;  /**< Offset: 0x130 (R/W  32)  */
  __I   uint8_t                        Reserved19[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP2RR01;  /**< Offset: 0x140 (R/W  32)  */
  __I   uint8_t                        Reserved20[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP2RR23;  /**< Offset: 0x150 (R/W  32)  */
  __I   uint8_t                        Reserved21[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP2RR45;  /**< Offset: 0x160 (R/W  32)  */
  __I   uint8_t                        Reserved22[0x0C];
  __IO  uint32_t                       PFW_DFT_VALP2RR67;  /**< Offset: 0x170 (R/W  32)  */
} pfw_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_PFW_COMPONENT_H_ */
