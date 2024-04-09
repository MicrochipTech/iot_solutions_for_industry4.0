/*
 * Component description for NVM
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
#ifndef _BZ45_NVM_COMPONENT_H_
#define _BZ45_NVM_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR NVM                                          */
/* ************************************************************************** */

/* -------- NVM_NVMCON : (NVM Offset: 0x00) (R/W 32)  -------- */
#define NVM_NVMCON_RESETVALUE                 _UINT32_(0x00)                                       /*  (NVM_NVMCON)   Reset Value */

#define NVM_NVMCON_NVMOP_Pos                  _UINT32_(0)                                          /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_NVMOP_Msk                  (_UINT32_(0xF) << NVM_NVMCON_NVMOP_Pos)              /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_NVMOP(value)               (NVM_NVMCON_NVMOP_Msk & (_UINT32_(value) << NVM_NVMCON_NVMOP_Pos)) /* Assigment of value for NVMOP in the NVM_NVMCON register */
#define NVM_NVMCON_BFSWAP_Pos                 _UINT32_(6)                                          /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_BFSWAP_Msk                 (_UINT32_(0x1) << NVM_NVMCON_BFSWAP_Pos)             /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_BFSWAP(value)              (NVM_NVMCON_BFSWAP_Msk & (_UINT32_(value) << NVM_NVMCON_BFSWAP_Pos)) /* Assigment of value for BFSWAP in the NVM_NVMCON register */
#define NVM_NVMCON_PFSWAP_Pos                 _UINT32_(7)                                          /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_PFSWAP_Msk                 (_UINT32_(0x1) << NVM_NVMCON_PFSWAP_Pos)             /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_PFSWAP(value)              (NVM_NVMCON_PFSWAP_Msk & (_UINT32_(value) << NVM_NVMCON_PFSWAP_Pos)) /* Assigment of value for PFSWAP in the NVM_NVMCON register */
#define NVM_NVMCON_HTDPGM_Pos                 _UINT32_(8)                                          /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_HTDPGM_Msk                 (_UINT32_(0x1) << NVM_NVMCON_HTDPGM_Pos)             /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_HTDPGM(value)              (NVM_NVMCON_HTDPGM_Msk & (_UINT32_(value) << NVM_NVMCON_HTDPGM_Pos)) /* Assigment of value for HTDPGM in the NVM_NVMCON register */
#define NVM_NVMCON_LVDERR_Pos                 _UINT32_(12)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_LVDERR_Msk                 (_UINT32_(0x1) << NVM_NVMCON_LVDERR_Pos)             /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_LVDERR(value)              (NVM_NVMCON_LVDERR_Msk & (_UINT32_(value) << NVM_NVMCON_LVDERR_Pos)) /* Assigment of value for LVDERR in the NVM_NVMCON register */
#define NVM_NVMCON_WRERR_Pos                  _UINT32_(13)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_WRERR_Msk                  (_UINT32_(0x1) << NVM_NVMCON_WRERR_Pos)              /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_WRERR(value)               (NVM_NVMCON_WRERR_Msk & (_UINT32_(value) << NVM_NVMCON_WRERR_Pos)) /* Assigment of value for WRERR in the NVM_NVMCON register */
#define NVM_NVMCON_WREN_Pos                   _UINT32_(14)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_WREN_Msk                   (_UINT32_(0x1) << NVM_NVMCON_WREN_Pos)               /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_WREN(value)                (NVM_NVMCON_WREN_Msk & (_UINT32_(value) << NVM_NVMCON_WREN_Pos)) /* Assigment of value for WREN in the NVM_NVMCON register */
#define NVM_NVMCON_WR_Pos                     _UINT32_(15)                                         /* (NVM_NVMCON)  Position */
#define NVM_NVMCON_WR_Msk                     (_UINT32_(0x1) << NVM_NVMCON_WR_Pos)                 /* (NVM_NVMCON)  Mask */
#define NVM_NVMCON_WR(value)                  (NVM_NVMCON_WR_Msk & (_UINT32_(value) << NVM_NVMCON_WR_Pos)) /* Assigment of value for WR in the NVM_NVMCON register */
#define NVM_NVMCON_Msk                        _UINT32_(0x0000F1CF)                                 /* (NVM_NVMCON) Register Mask  */


/* -------- NVM_NVMCONCLR : (NVM Offset: 0x04) (R/W 32)  -------- */
#define NVM_NVMCONCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMCONCLR)   Reset Value */

#define NVM_NVMCONCLR_Msk                     _UINT32_(0x00000000)                                 /* (NVM_NVMCONCLR) Register Mask  */


/* -------- NVM_NVMCONSET : (NVM Offset: 0x08) (R/W 32)  -------- */
#define NVM_NVMCONSET_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMCONSET)   Reset Value */

#define NVM_NVMCONSET_Msk                     _UINT32_(0x00000000)                                 /* (NVM_NVMCONSET) Register Mask  */


/* -------- NVM_NVMCONINV : (NVM Offset: 0x0C) (R/W 32)  -------- */
#define NVM_NVMCONINV_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMCONINV)   Reset Value */

#define NVM_NVMCONINV_Msk                     _UINT32_(0x00000000)                                 /* (NVM_NVMCONINV) Register Mask  */


/* -------- NVM_NVMCON2 : (NVM Offset: 0x10) (R/W 32)  -------- */
#define NVM_NVMCON2_RESETVALUE                _UINT32_(0x00)                                       /*  (NVM_NVMCON2)   Reset Value */

#define NVM_NVMCON2_PREPG_Pos                 _UINT32_(0)                                          /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_PREPG_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_PREPG_Pos)             /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_PREPG(value)              (NVM_NVMCON2_PREPG_Msk & (_UINT32_(value) << NVM_NVMCON2_PREPG_Pos)) /* Assigment of value for PREPG in the NVM_NVMCON2 register */
#define NVM_NVMCON2_SWAPLK_Pos                _UINT32_(6)                                          /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_SWAPLK_Msk                (_UINT32_(0x3) << NVM_NVMCON2_SWAPLK_Pos)            /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_SWAPLK(value)             (NVM_NVMCON2_SWAPLK_Msk & (_UINT32_(value) << NVM_NVMCON2_SWAPLK_Pos)) /* Assigment of value for SWAPLK in the NVM_NVMCON2 register */
#define NVM_NVMCON2_RETRY_Pos                 _UINT32_(8)                                          /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_RETRY_Msk                 (_UINT32_(0x3) << NVM_NVMCON2_RETRY_Pos)             /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_RETRY(value)              (NVM_NVMCON2_RETRY_Msk & (_UINT32_(value) << NVM_NVMCON2_RETRY_Pos)) /* Assigment of value for RETRY in the NVM_NVMCON2 register */
#define NVM_NVMCON2_VREAD1_Pos                _UINT32_(12)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_VREAD1_Msk                (_UINT32_(0x1) << NVM_NVMCON2_VREAD1_Pos)            /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_VREAD1(value)             (NVM_NVMCON2_VREAD1_Msk & (_UINT32_(value) << NVM_NVMCON2_VREAD1_Pos)) /* Assigment of value for VREAD1 in the NVM_NVMCON2 register */
#define NVM_NVMCON2_CREAD1_Pos                _UINT32_(13)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_CREAD1_Msk                (_UINT32_(0x1) << NVM_NVMCON2_CREAD1_Pos)            /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_CREAD1(value)             (NVM_NVMCON2_CREAD1_Msk & (_UINT32_(value) << NVM_NVMCON2_CREAD1_Pos)) /* Assigment of value for CREAD1 in the NVM_NVMCON2 register */
#define NVM_NVMCON2_TEMP_Pos                  _UINT32_(14)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_TEMP_Msk                  (_UINT32_(0x1) << NVM_NVMCON2_TEMP_Pos)              /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_TEMP(value)               (NVM_NVMCON2_TEMP_Msk & (_UINT32_(value) << NVM_NVMCON2_TEMP_Pos)) /* Assigment of value for TEMP in the NVM_NVMCON2 register */
#define NVM_NVMCON2_WS_Pos                    _UINT32_(16)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_WS_Msk                    (_UINT32_(0x1F) << NVM_NVMCON2_WS_Pos)               /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_WS(value)                 (NVM_NVMCON2_WS_Msk & (_UINT32_(value) << NVM_NVMCON2_WS_Pos)) /* Assigment of value for WS in the NVM_NVMCON2 register */
#define NVM_NVMCON2_SLEEP_Pos                 _UINT32_(24)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_SLEEP_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_SLEEP_Pos)             /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_SLEEP(value)              (NVM_NVMCON2_SLEEP_Msk & (_UINT32_(value) << NVM_NVMCON2_SLEEP_Pos)) /* Assigment of value for SLEEP in the NVM_NVMCON2 register */
#define NVM_NVMCON2_ERS_Pos                   _UINT32_(28)                                         /* (NVM_NVMCON2)  Position */
#define NVM_NVMCON2_ERS_Msk                   (_UINT32_(0xF) << NVM_NVMCON2_ERS_Pos)               /* (NVM_NVMCON2)  Mask */
#define NVM_NVMCON2_ERS(value)                (NVM_NVMCON2_ERS_Msk & (_UINT32_(value) << NVM_NVMCON2_ERS_Pos)) /* Assigment of value for ERS in the NVM_NVMCON2 register */
#define NVM_NVMCON2_Msk                       _UINT32_(0xF11F73C1)                                 /* (NVM_NVMCON2) Register Mask  */

#define NVM_NVMCON2_VREAD_Pos                 _UINT32_(12)                                         /* (NVM_NVMCON2 Position)  */
#define NVM_NVMCON2_VREAD_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_VREAD_Pos)             /* (NVM_NVMCON2 Mask) VREAD */
#define NVM_NVMCON2_VREAD(value)              (NVM_NVMCON2_VREAD_Msk & (_UINT32_(value) << NVM_NVMCON2_VREAD_Pos)) 
#define NVM_NVMCON2_CREAD_Pos                 _UINT32_(13)                                         /* (NVM_NVMCON2 Position)  */
#define NVM_NVMCON2_CREAD_Msk                 (_UINT32_(0x1) << NVM_NVMCON2_CREAD_Pos)             /* (NVM_NVMCON2 Mask) CREAD */
#define NVM_NVMCON2_CREAD(value)              (NVM_NVMCON2_CREAD_Msk & (_UINT32_(value) << NVM_NVMCON2_CREAD_Pos)) 

/* -------- NVM_NVMCON2CLR : (NVM Offset: 0x14) (R/W 32)  -------- */
#define NVM_NVMCON2CLR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMCON2CLR)   Reset Value */

#define NVM_NVMCON2CLR_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMCON2CLR) Register Mask  */


/* -------- NVM_NVMCON2SET : (NVM Offset: 0x18) (R/W 32)  -------- */
#define NVM_NVMCON2SET_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMCON2SET)   Reset Value */

#define NVM_NVMCON2SET_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMCON2SET) Register Mask  */


/* -------- NVM_NVMCON2INV : (NVM Offset: 0x1C) (R/W 32)  -------- */
#define NVM_NVMCON2INV_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMCON2INV)   Reset Value */

#define NVM_NVMCON2INV_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMCON2INV) Register Mask  */


/* -------- NVM_NVMKEY : (NVM Offset: 0x20) (R/W 32)  -------- */
#define NVM_NVMKEY_RESETVALUE                 _UINT32_(0x00)                                       /*  (NVM_NVMKEY)   Reset Value */

#define NVM_NVMKEY_NVMKEY_Pos                 _UINT32_(0)                                          /* (NVM_NVMKEY)  Position */
#define NVM_NVMKEY_NVMKEY_Msk                 (_UINT32_(0xFFFFFFFF) << NVM_NVMKEY_NVMKEY_Pos)      /* (NVM_NVMKEY)  Mask */
#define NVM_NVMKEY_NVMKEY(value)              (NVM_NVMKEY_NVMKEY_Msk & (_UINT32_(value) << NVM_NVMKEY_NVMKEY_Pos)) /* Assigment of value for NVMKEY in the NVM_NVMKEY register */
#define NVM_NVMKEY_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMKEY) Register Mask  */


/* -------- NVM_NVMADDR : (NVM Offset: 0x30) (R/W 32)  -------- */
#define NVM_NVMADDR_RESETVALUE                _UINT32_(0x00)                                       /*  (NVM_NVMADDR)   Reset Value */

#define NVM_NVMADDR_NVMADDR_Pos               _UINT32_(0)                                          /* (NVM_NVMADDR)  Position */
#define NVM_NVMADDR_NVMADDR_Msk               (_UINT32_(0xFFFFFFFF) << NVM_NVMADDR_NVMADDR_Pos)    /* (NVM_NVMADDR)  Mask */
#define NVM_NVMADDR_NVMADDR(value)            (NVM_NVMADDR_NVMADDR_Msk & (_UINT32_(value) << NVM_NVMADDR_NVMADDR_Pos)) /* Assigment of value for NVMADDR in the NVM_NVMADDR register */
#define NVM_NVMADDR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMADDR) Register Mask  */


/* -------- NVM_NVMDATA0 : (NVM Offset: 0x40) (R/W 32)  -------- */
#define NVM_NVMDATA0_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA0)   Reset Value */

#define NVM_NVMDATA0_NVMDATA0_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA0)  Position */
#define NVM_NVMDATA0_NVMDATA0_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA0_NVMDATA0_Pos)  /* (NVM_NVMDATA0)  Mask */
#define NVM_NVMDATA0_NVMDATA0(value)          (NVM_NVMDATA0_NVMDATA0_Msk & (_UINT32_(value) << NVM_NVMDATA0_NVMDATA0_Pos)) /* Assigment of value for NVMDATA0 in the NVM_NVMDATA0 register */
#define NVM_NVMDATA0_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA0) Register Mask  */


/* -------- NVM_NVMDATA1 : (NVM Offset: 0x50) (R/W 32)  -------- */
#define NVM_NVMDATA1_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA1)   Reset Value */

#define NVM_NVMDATA1_NVMDATA1_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA1)  Position */
#define NVM_NVMDATA1_NVMDATA1_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA1_NVMDATA1_Pos)  /* (NVM_NVMDATA1)  Mask */
#define NVM_NVMDATA1_NVMDATA1(value)          (NVM_NVMDATA1_NVMDATA1_Msk & (_UINT32_(value) << NVM_NVMDATA1_NVMDATA1_Pos)) /* Assigment of value for NVMDATA1 in the NVM_NVMDATA1 register */
#define NVM_NVMDATA1_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA1) Register Mask  */


/* -------- NVM_NVMDATA2 : (NVM Offset: 0x60) (R/W 32)  -------- */
#define NVM_NVMDATA2_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA2)   Reset Value */

#define NVM_NVMDATA2_NVMDATA2_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA2)  Position */
#define NVM_NVMDATA2_NVMDATA2_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA2_NVMDATA2_Pos)  /* (NVM_NVMDATA2)  Mask */
#define NVM_NVMDATA2_NVMDATA2(value)          (NVM_NVMDATA2_NVMDATA2_Msk & (_UINT32_(value) << NVM_NVMDATA2_NVMDATA2_Pos)) /* Assigment of value for NVMDATA2 in the NVM_NVMDATA2 register */
#define NVM_NVMDATA2_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA2) Register Mask  */


/* -------- NVM_NVMDATA3 : (NVM Offset: 0x70) (R/W 32)  -------- */
#define NVM_NVMDATA3_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA3)   Reset Value */

#define NVM_NVMDATA3_NVMDATA3_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA3)  Position */
#define NVM_NVMDATA3_NVMDATA3_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA3_NVMDATA3_Pos)  /* (NVM_NVMDATA3)  Mask */
#define NVM_NVMDATA3_NVMDATA3(value)          (NVM_NVMDATA3_NVMDATA3_Msk & (_UINT32_(value) << NVM_NVMDATA3_NVMDATA3_Pos)) /* Assigment of value for NVMDATA3 in the NVM_NVMDATA3 register */
#define NVM_NVMDATA3_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA3) Register Mask  */


/* -------- NVM_NVMDATA4 : (NVM Offset: 0x80) (R/W 32)  -------- */
#define NVM_NVMDATA4_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA4)   Reset Value */

#define NVM_NVMDATA4_NVMDATA4_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA4)  Position */
#define NVM_NVMDATA4_NVMDATA4_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA4_NVMDATA4_Pos)  /* (NVM_NVMDATA4)  Mask */
#define NVM_NVMDATA4_NVMDATA4(value)          (NVM_NVMDATA4_NVMDATA4_Msk & (_UINT32_(value) << NVM_NVMDATA4_NVMDATA4_Pos)) /* Assigment of value for NVMDATA4 in the NVM_NVMDATA4 register */
#define NVM_NVMDATA4_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA4) Register Mask  */


/* -------- NVM_NVMDATA5 : (NVM Offset: 0x90) (R/W 32)  -------- */
#define NVM_NVMDATA5_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA5)   Reset Value */

#define NVM_NVMDATA5_NVMDATA5_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA5)  Position */
#define NVM_NVMDATA5_NVMDATA5_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA5_NVMDATA5_Pos)  /* (NVM_NVMDATA5)  Mask */
#define NVM_NVMDATA5_NVMDATA5(value)          (NVM_NVMDATA5_NVMDATA5_Msk & (_UINT32_(value) << NVM_NVMDATA5_NVMDATA5_Pos)) /* Assigment of value for NVMDATA5 in the NVM_NVMDATA5 register */
#define NVM_NVMDATA5_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA5) Register Mask  */


/* -------- NVM_NVMDATA6 : (NVM Offset: 0xA0) (R/W 32)  -------- */
#define NVM_NVMDATA6_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA6)   Reset Value */

#define NVM_NVMDATA6_NVMDATA6_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA6)  Position */
#define NVM_NVMDATA6_NVMDATA6_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA6_NVMDATA6_Pos)  /* (NVM_NVMDATA6)  Mask */
#define NVM_NVMDATA6_NVMDATA6(value)          (NVM_NVMDATA6_NVMDATA6_Msk & (_UINT32_(value) << NVM_NVMDATA6_NVMDATA6_Pos)) /* Assigment of value for NVMDATA6 in the NVM_NVMDATA6 register */
#define NVM_NVMDATA6_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA6) Register Mask  */


/* -------- NVM_NVMDATA7 : (NVM Offset: 0xB0) (R/W 32)  -------- */
#define NVM_NVMDATA7_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMDATA7)   Reset Value */

#define NVM_NVMDATA7_NVMDATA7_Pos             _UINT32_(0)                                          /* (NVM_NVMDATA7)  Position */
#define NVM_NVMDATA7_NVMDATA7_Msk             (_UINT32_(0xFFFFFFFF) << NVM_NVMDATA7_NVMDATA7_Pos)  /* (NVM_NVMDATA7)  Mask */
#define NVM_NVMDATA7_NVMDATA7(value)          (NVM_NVMDATA7_NVMDATA7_Msk & (_UINT32_(value) << NVM_NVMDATA7_NVMDATA7_Pos)) /* Assigment of value for NVMDATA7 in the NVM_NVMDATA7 register */
#define NVM_NVMDATA7_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMDATA7) Register Mask  */


/* -------- NVM_NVMSRCADDR : (NVM Offset: 0xC0) (R/W 32)  -------- */
#define NVM_NVMSRCADDR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMSRCADDR)   Reset Value */

#define NVM_NVMSRCADDR_NVMSRCADDR_Pos         _UINT32_(0)                                          /* (NVM_NVMSRCADDR)  Position */
#define NVM_NVMSRCADDR_NVMSRCADDR_Msk         (_UINT32_(0xFFFFFFFF) << NVM_NVMSRCADDR_NVMSRCADDR_Pos) /* (NVM_NVMSRCADDR)  Mask */
#define NVM_NVMSRCADDR_NVMSRCADDR(value)      (NVM_NVMSRCADDR_NVMSRCADDR_Msk & (_UINT32_(value) << NVM_NVMSRCADDR_NVMSRCADDR_Pos)) /* Assigment of value for NVMSRCADDR in the NVM_NVMSRCADDR register */
#define NVM_NVMSRCADDR_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (NVM_NVMSRCADDR) Register Mask  */


/* -------- NVM_NVMPWPLT : (NVM Offset: 0xD0) (R/W 32)  -------- */
#define NVM_NVMPWPLT_RESETVALUE               _UINT32_(0x00)                                       /*  (NVM_NVMPWPLT)   Reset Value */

#define NVM_NVMPWPLT_PWPLT_Pos                _UINT32_(0)                                          /* (NVM_NVMPWPLT)  Position */
#define NVM_NVMPWPLT_PWPLT_Msk                (_UINT32_(0xFFFFFF) << NVM_NVMPWPLT_PWPLT_Pos)       /* (NVM_NVMPWPLT)  Mask */
#define NVM_NVMPWPLT_PWPLT(value)             (NVM_NVMPWPLT_PWPLT_Msk & (_UINT32_(value) << NVM_NVMPWPLT_PWPLT_Pos)) /* Assigment of value for PWPLT in the NVM_NVMPWPLT register */
#define NVM_NVMPWPLT_ULOCK_Pos                _UINT32_(31)                                         /* (NVM_NVMPWPLT)  Position */
#define NVM_NVMPWPLT_ULOCK_Msk                (_UINT32_(0x1) << NVM_NVMPWPLT_ULOCK_Pos)            /* (NVM_NVMPWPLT)  Mask */
#define NVM_NVMPWPLT_ULOCK(value)             (NVM_NVMPWPLT_ULOCK_Msk & (_UINT32_(value) << NVM_NVMPWPLT_ULOCK_Pos)) /* Assigment of value for ULOCK in the NVM_NVMPWPLT register */
#define NVM_NVMPWPLT_Msk                      _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMPWPLT) Register Mask  */


/* -------- NVM_NVMPWPLTCLR : (NVM Offset: 0xD4) (R/W 32)  -------- */
#define NVM_NVMPWPLTCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (NVM_NVMPWPLTCLR)   Reset Value */

#define NVM_NVMPWPLTCLR_Msk                   _UINT32_(0x00000000)                                 /* (NVM_NVMPWPLTCLR) Register Mask  */


/* -------- NVM_NVMPWPLTSET : (NVM Offset: 0xD8) (R/W 32)  -------- */
#define NVM_NVMPWPLTSET_RESETVALUE            _UINT32_(0x00)                                       /*  (NVM_NVMPWPLTSET)   Reset Value */

#define NVM_NVMPWPLTSET_Msk                   _UINT32_(0x00000000)                                 /* (NVM_NVMPWPLTSET) Register Mask  */


/* -------- NVM_NVMPWPLTINV : (NVM Offset: 0xDC) (R/W 32)  -------- */
#define NVM_NVMPWPLTINV_RESETVALUE            _UINT32_(0x00)                                       /*  (NVM_NVMPWPLTINV)   Reset Value */

#define NVM_NVMPWPLTINV_Msk                   _UINT32_(0x00000000)                                 /* (NVM_NVMPWPLTINV) Register Mask  */


/* -------- NVM_NVMPWPGTE : (NVM Offset: 0xE0) (R/W 32)  -------- */
#define NVM_NVMPWPGTE_RESETVALUE              _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTE)   Reset Value */

#define NVM_NVMPWPGTE_PWPGTE_Pos              _UINT32_(0)                                          /* (NVM_NVMPWPGTE)  Position */
#define NVM_NVMPWPGTE_PWPGTE_Msk              (_UINT32_(0xFFFFFF) << NVM_NVMPWPGTE_PWPGTE_Pos)     /* (NVM_NVMPWPGTE)  Mask */
#define NVM_NVMPWPGTE_PWPGTE(value)           (NVM_NVMPWPGTE_PWPGTE_Msk & (_UINT32_(value) << NVM_NVMPWPGTE_PWPGTE_Pos)) /* Assigment of value for PWPGTE in the NVM_NVMPWPGTE register */
#define NVM_NVMPWPGTE_ULOCK_Pos               _UINT32_(31)                                         /* (NVM_NVMPWPGTE)  Position */
#define NVM_NVMPWPGTE_ULOCK_Msk               (_UINT32_(0x1) << NVM_NVMPWPGTE_ULOCK_Pos)           /* (NVM_NVMPWPGTE)  Mask */
#define NVM_NVMPWPGTE_ULOCK(value)            (NVM_NVMPWPGTE_ULOCK_Msk & (_UINT32_(value) << NVM_NVMPWPGTE_ULOCK_Pos)) /* Assigment of value for ULOCK in the NVM_NVMPWPGTE register */
#define NVM_NVMPWPGTE_Msk                     _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMPWPGTE) Register Mask  */


/* -------- NVM_NVMPWPGTECLR : (NVM Offset: 0xE4) (R/W 32)  -------- */
#define NVM_NVMPWPGTECLR_RESETVALUE           _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTECLR)   Reset Value */

#define NVM_NVMPWPGTECLR_Msk                  _UINT32_(0x00000000)                                 /* (NVM_NVMPWPGTECLR) Register Mask  */


/* -------- NVM_NVMPWPGTESET : (NVM Offset: 0xE8) (R/W 32)  -------- */
#define NVM_NVMPWPGTESET_RESETVALUE           _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTESET)   Reset Value */

#define NVM_NVMPWPGTESET_Msk                  _UINT32_(0x00000000)                                 /* (NVM_NVMPWPGTESET) Register Mask  */


/* -------- NVM_NVMPWPGTEINV : (NVM Offset: 0xEC) (R/W 32)  -------- */
#define NVM_NVMPWPGTEINV_RESETVALUE           _UINT32_(0x00)                                       /*  (NVM_NVMPWPGTEINV)   Reset Value */

#define NVM_NVMPWPGTEINV_Msk                  _UINT32_(0x00000000)                                 /* (NVM_NVMPWPGTEINV) Register Mask  */


/* -------- NVM_NVMLBWP : (NVM Offset: 0xF0) (R/W 32)  -------- */
#define NVM_NVMLBWP_RESETVALUE                _UINT32_(0x00)                                       /*  (NVM_NVMLBWP)   Reset Value */

#define NVM_NVMLBWP_LBWP0_Pos                 _UINT32_(0)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP0_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP0_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP0(value)              (NVM_NVMLBWP_LBWP0_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP0_Pos)) /* Assigment of value for LBWP0 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP1_Pos                 _UINT32_(1)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP1_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP1_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP1(value)              (NVM_NVMLBWP_LBWP1_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP1_Pos)) /* Assigment of value for LBWP1 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP2_Pos                 _UINT32_(2)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP2_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP2_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP2(value)              (NVM_NVMLBWP_LBWP2_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP2_Pos)) /* Assigment of value for LBWP2 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP3_Pos                 _UINT32_(3)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP3_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP3_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP3(value)              (NVM_NVMLBWP_LBWP3_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP3_Pos)) /* Assigment of value for LBWP3 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP4_Pos                 _UINT32_(4)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP4_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP4_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP4(value)              (NVM_NVMLBWP_LBWP4_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP4_Pos)) /* Assigment of value for LBWP4 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP5_Pos                 _UINT32_(5)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP5_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP5_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP5(value)              (NVM_NVMLBWP_LBWP5_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP5_Pos)) /* Assigment of value for LBWP5 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP6_Pos                 _UINT32_(6)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP6_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP6_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP6(value)              (NVM_NVMLBWP_LBWP6_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP6_Pos)) /* Assigment of value for LBWP6 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP7_Pos                 _UINT32_(7)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP7_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP7_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP7(value)              (NVM_NVMLBWP_LBWP7_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP7_Pos)) /* Assigment of value for LBWP7 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP8_Pos                 _UINT32_(8)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP8_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP8_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP8(value)              (NVM_NVMLBWP_LBWP8_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP8_Pos)) /* Assigment of value for LBWP8 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP9_Pos                 _UINT32_(9)                                          /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP9_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_LBWP9_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP9(value)              (NVM_NVMLBWP_LBWP9_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP9_Pos)) /* Assigment of value for LBWP9 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP10_Pos                _UINT32_(10)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP10_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP10_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP10(value)             (NVM_NVMLBWP_LBWP10_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP10_Pos)) /* Assigment of value for LBWP10 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP11_Pos                _UINT32_(11)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP11_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP11_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP11(value)             (NVM_NVMLBWP_LBWP11_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP11_Pos)) /* Assigment of value for LBWP11 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP12_Pos                _UINT32_(12)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP12_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP12_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP12(value)             (NVM_NVMLBWP_LBWP12_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP12_Pos)) /* Assigment of value for LBWP12 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP13_Pos                _UINT32_(13)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP13_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP13_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP13(value)             (NVM_NVMLBWP_LBWP13_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP13_Pos)) /* Assigment of value for LBWP13 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP14_Pos                _UINT32_(14)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP14_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP14_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP14(value)             (NVM_NVMLBWP_LBWP14_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP14_Pos)) /* Assigment of value for LBWP14 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP15_Pos                _UINT32_(15)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP15_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP15_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP15(value)             (NVM_NVMLBWP_LBWP15_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP15_Pos)) /* Assigment of value for LBWP15 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP16_Pos                _UINT32_(16)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP16_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP16_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP16(value)             (NVM_NVMLBWP_LBWP16_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP16_Pos)) /* Assigment of value for LBWP16 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP17_Pos                _UINT32_(17)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP17_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP17_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP17(value)             (NVM_NVMLBWP_LBWP17_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP17_Pos)) /* Assigment of value for LBWP17 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP18_Pos                _UINT32_(18)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP18_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP18_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP18(value)             (NVM_NVMLBWP_LBWP18_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP18_Pos)) /* Assigment of value for LBWP18 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP19_Pos                _UINT32_(19)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP19_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP19_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP19(value)             (NVM_NVMLBWP_LBWP19_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP19_Pos)) /* Assigment of value for LBWP19 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP20_Pos                _UINT32_(20)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP20_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP20_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP20(value)             (NVM_NVMLBWP_LBWP20_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP20_Pos)) /* Assigment of value for LBWP20 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP21_Pos                _UINT32_(21)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP21_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP21_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP21(value)             (NVM_NVMLBWP_LBWP21_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP21_Pos)) /* Assigment of value for LBWP21 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP22_Pos                _UINT32_(22)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP22_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP22_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP22(value)             (NVM_NVMLBWP_LBWP22_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP22_Pos)) /* Assigment of value for LBWP22 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_LBWP23_Pos                _UINT32_(23)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_LBWP23_Msk                (_UINT32_(0x1) << NVM_NVMLBWP_LBWP23_Pos)            /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_LBWP23(value)             (NVM_NVMLBWP_LBWP23_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP23_Pos)) /* Assigment of value for LBWP23 in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_ULOCK_Pos                 _UINT32_(31)                                         /* (NVM_NVMLBWP)  Position */
#define NVM_NVMLBWP_ULOCK_Msk                 (_UINT32_(0x1) << NVM_NVMLBWP_ULOCK_Pos)             /* (NVM_NVMLBWP)  Mask */
#define NVM_NVMLBWP_ULOCK(value)              (NVM_NVMLBWP_ULOCK_Msk & (_UINT32_(value) << NVM_NVMLBWP_ULOCK_Pos)) /* Assigment of value for ULOCK in the NVM_NVMLBWP register */
#define NVM_NVMLBWP_Msk                       _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMLBWP) Register Mask  */

#define NVM_NVMLBWP_LBWP_Pos                  _UINT32_(0)                                          /* (NVM_NVMLBWP Position)  */
#define NVM_NVMLBWP_LBWP_Msk                  (_UINT32_(0xFFFFFF) << NVM_NVMLBWP_LBWP_Pos)         /* (NVM_NVMLBWP Mask) LBWP */
#define NVM_NVMLBWP_LBWP(value)               (NVM_NVMLBWP_LBWP_Msk & (_UINT32_(value) << NVM_NVMLBWP_LBWP_Pos)) 

/* -------- NVM_NVMLBWPCLR : (NVM Offset: 0xF4) (R/W 32)  -------- */
#define NVM_NVMLBWPCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMLBWPCLR)   Reset Value */

#define NVM_NVMLBWPCLR_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMLBWPCLR) Register Mask  */


/* -------- NVM_NVMLBWPSET : (NVM Offset: 0xF8) (R/W 32)  -------- */
#define NVM_NVMLBWPSET_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMLBWPSET)   Reset Value */

#define NVM_NVMLBWPSET_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMLBWPSET) Register Mask  */


/* -------- NVM_NVMLBWPINV : (NVM Offset: 0xFC) (R/W 32)  -------- */
#define NVM_NVMLBWPINV_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMLBWPINV)   Reset Value */

#define NVM_NVMLBWPINV_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMLBWPINV) Register Mask  */


/* -------- NVM_NVMUBWP : (NVM Offset: 0x100) (R/W 32)  -------- */
#define NVM_NVMUBWP_RESETVALUE                _UINT32_(0x00)                                       /*  (NVM_NVMUBWP)   Reset Value */

#define NVM_NVMUBWP_UBWP0_Pos                 _UINT32_(0)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP0_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP0_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP0(value)              (NVM_NVMUBWP_UBWP0_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP0_Pos)) /* Assigment of value for UBWP0 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP1_Pos                 _UINT32_(1)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP1_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP1_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP1(value)              (NVM_NVMUBWP_UBWP1_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP1_Pos)) /* Assigment of value for UBWP1 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP2_Pos                 _UINT32_(2)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP2_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP2_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP2(value)              (NVM_NVMUBWP_UBWP2_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP2_Pos)) /* Assigment of value for UBWP2 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP3_Pos                 _UINT32_(3)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP3_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP3_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP3(value)              (NVM_NVMUBWP_UBWP3_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP3_Pos)) /* Assigment of value for UBWP3 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP4_Pos                 _UINT32_(4)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP4_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP4_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP4(value)              (NVM_NVMUBWP_UBWP4_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP4_Pos)) /* Assigment of value for UBWP4 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP5_Pos                 _UINT32_(5)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP5_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP5_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP5(value)              (NVM_NVMUBWP_UBWP5_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP5_Pos)) /* Assigment of value for UBWP5 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP6_Pos                 _UINT32_(6)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP6_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP6_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP6(value)              (NVM_NVMUBWP_UBWP6_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP6_Pos)) /* Assigment of value for UBWP6 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP7_Pos                 _UINT32_(7)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP7_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP7_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP7(value)              (NVM_NVMUBWP_UBWP7_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP7_Pos)) /* Assigment of value for UBWP7 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP8_Pos                 _UINT32_(8)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP8_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP8_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP8(value)              (NVM_NVMUBWP_UBWP8_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP8_Pos)) /* Assigment of value for UBWP8 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP9_Pos                 _UINT32_(9)                                          /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP9_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_UBWP9_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP9(value)              (NVM_NVMUBWP_UBWP9_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP9_Pos)) /* Assigment of value for UBWP9 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP10_Pos                _UINT32_(10)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP10_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP10_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP10(value)             (NVM_NVMUBWP_UBWP10_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP10_Pos)) /* Assigment of value for UBWP10 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP11_Pos                _UINT32_(11)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP11_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP11_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP11(value)             (NVM_NVMUBWP_UBWP11_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP11_Pos)) /* Assigment of value for UBWP11 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP12_Pos                _UINT32_(12)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP12_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP12_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP12(value)             (NVM_NVMUBWP_UBWP12_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP12_Pos)) /* Assigment of value for UBWP12 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP13_Pos                _UINT32_(13)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP13_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP13_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP13(value)             (NVM_NVMUBWP_UBWP13_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP13_Pos)) /* Assigment of value for UBWP13 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP14_Pos                _UINT32_(14)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP14_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP14_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP14(value)             (NVM_NVMUBWP_UBWP14_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP14_Pos)) /* Assigment of value for UBWP14 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP15_Pos                _UINT32_(15)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP15_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP15_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP15(value)             (NVM_NVMUBWP_UBWP15_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP15_Pos)) /* Assigment of value for UBWP15 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP16_Pos                _UINT32_(16)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP16_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP16_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP16(value)             (NVM_NVMUBWP_UBWP16_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP16_Pos)) /* Assigment of value for UBWP16 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP17_Pos                _UINT32_(17)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP17_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP17_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP17(value)             (NVM_NVMUBWP_UBWP17_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP17_Pos)) /* Assigment of value for UBWP17 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP18_Pos                _UINT32_(18)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP18_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP18_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP18(value)             (NVM_NVMUBWP_UBWP18_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP18_Pos)) /* Assigment of value for UBWP18 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP19_Pos                _UINT32_(19)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP19_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP19_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP19(value)             (NVM_NVMUBWP_UBWP19_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP19_Pos)) /* Assigment of value for UBWP19 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP20_Pos                _UINT32_(20)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP20_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP20_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP20(value)             (NVM_NVMUBWP_UBWP20_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP20_Pos)) /* Assigment of value for UBWP20 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP21_Pos                _UINT32_(21)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP21_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP21_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP21(value)             (NVM_NVMUBWP_UBWP21_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP21_Pos)) /* Assigment of value for UBWP21 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP22_Pos                _UINT32_(22)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP22_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP22_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP22(value)             (NVM_NVMUBWP_UBWP22_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP22_Pos)) /* Assigment of value for UBWP22 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_UBWP23_Pos                _UINT32_(23)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_UBWP23_Msk                (_UINT32_(0x1) << NVM_NVMUBWP_UBWP23_Pos)            /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_UBWP23(value)             (NVM_NVMUBWP_UBWP23_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP23_Pos)) /* Assigment of value for UBWP23 in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_ULOCK_Pos                 _UINT32_(31)                                         /* (NVM_NVMUBWP)  Position */
#define NVM_NVMUBWP_ULOCK_Msk                 (_UINT32_(0x1) << NVM_NVMUBWP_ULOCK_Pos)             /* (NVM_NVMUBWP)  Mask */
#define NVM_NVMUBWP_ULOCK(value)              (NVM_NVMUBWP_ULOCK_Msk & (_UINT32_(value) << NVM_NVMUBWP_ULOCK_Pos)) /* Assigment of value for ULOCK in the NVM_NVMUBWP register */
#define NVM_NVMUBWP_Msk                       _UINT32_(0x80FFFFFF)                                 /* (NVM_NVMUBWP) Register Mask  */

#define NVM_NVMUBWP_UBWP_Pos                  _UINT32_(0)                                          /* (NVM_NVMUBWP Position)  */
#define NVM_NVMUBWP_UBWP_Msk                  (_UINT32_(0xFFFFFF) << NVM_NVMUBWP_UBWP_Pos)         /* (NVM_NVMUBWP Mask) UBWP */
#define NVM_NVMUBWP_UBWP(value)               (NVM_NVMUBWP_UBWP_Msk & (_UINT32_(value) << NVM_NVMUBWP_UBWP_Pos)) 

/* -------- NVM_NVMUBWPCLR : (NVM Offset: 0x104) (R/W 32)  -------- */
#define NVM_NVMUBWPCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMUBWPCLR)   Reset Value */

#define NVM_NVMUBWPCLR_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMUBWPCLR) Register Mask  */


/* -------- NVM_NVMUBWPSET : (NVM Offset: 0x108) (R/W 32)  -------- */
#define NVM_NVMUBWPSET_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMUBWPSET)   Reset Value */

#define NVM_NVMUBWPSET_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMUBWPSET) Register Mask  */


/* -------- NVM_NVMUBWPINV : (NVM Offset: 0x10C) (R/W 32)  -------- */
#define NVM_NVMUBWPINV_RESETVALUE             _UINT32_(0x00)                                       /*  (NVM_NVMUBWPINV)   Reset Value */

#define NVM_NVMUBWPINV_Msk                    _UINT32_(0x00000000)                                 /* (NVM_NVMUBWPINV) Register Mask  */


/** \brief NVM register offsets definitions */
#define NVM_NVMCON_REG_OFST            _UINT32_(0x00)      /* (NVM_NVMCON)  Offset */
#define NVM_NVMCONCLR_REG_OFST         _UINT32_(0x04)      /* (NVM_NVMCONCLR)  Offset */
#define NVM_NVMCONSET_REG_OFST         _UINT32_(0x08)      /* (NVM_NVMCONSET)  Offset */
#define NVM_NVMCONINV_REG_OFST         _UINT32_(0x0C)      /* (NVM_NVMCONINV)  Offset */
#define NVM_NVMCON2_REG_OFST           _UINT32_(0x10)      /* (NVM_NVMCON2)  Offset */
#define NVM_NVMCON2CLR_REG_OFST        _UINT32_(0x14)      /* (NVM_NVMCON2CLR)  Offset */
#define NVM_NVMCON2SET_REG_OFST        _UINT32_(0x18)      /* (NVM_NVMCON2SET)  Offset */
#define NVM_NVMCON2INV_REG_OFST        _UINT32_(0x1C)      /* (NVM_NVMCON2INV)  Offset */
#define NVM_NVMKEY_REG_OFST            _UINT32_(0x20)      /* (NVM_NVMKEY)  Offset */
#define NVM_NVMADDR_REG_OFST           _UINT32_(0x30)      /* (NVM_NVMADDR)  Offset */
#define NVM_NVMDATA0_REG_OFST          _UINT32_(0x40)      /* (NVM_NVMDATA0)  Offset */
#define NVM_NVMDATA1_REG_OFST          _UINT32_(0x50)      /* (NVM_NVMDATA1)  Offset */
#define NVM_NVMDATA2_REG_OFST          _UINT32_(0x60)      /* (NVM_NVMDATA2)  Offset */
#define NVM_NVMDATA3_REG_OFST          _UINT32_(0x70)      /* (NVM_NVMDATA3)  Offset */
#define NVM_NVMDATA4_REG_OFST          _UINT32_(0x80)      /* (NVM_NVMDATA4)  Offset */
#define NVM_NVMDATA5_REG_OFST          _UINT32_(0x90)      /* (NVM_NVMDATA5)  Offset */
#define NVM_NVMDATA6_REG_OFST          _UINT32_(0xA0)      /* (NVM_NVMDATA6)  Offset */
#define NVM_NVMDATA7_REG_OFST          _UINT32_(0xB0)      /* (NVM_NVMDATA7)  Offset */
#define NVM_NVMSRCADDR_REG_OFST        _UINT32_(0xC0)      /* (NVM_NVMSRCADDR)  Offset */
#define NVM_NVMPWPLT_REG_OFST          _UINT32_(0xD0)      /* (NVM_NVMPWPLT)  Offset */
#define NVM_NVMPWPLTCLR_REG_OFST       _UINT32_(0xD4)      /* (NVM_NVMPWPLTCLR)  Offset */
#define NVM_NVMPWPLTSET_REG_OFST       _UINT32_(0xD8)      /* (NVM_NVMPWPLTSET)  Offset */
#define NVM_NVMPWPLTINV_REG_OFST       _UINT32_(0xDC)      /* (NVM_NVMPWPLTINV)  Offset */
#define NVM_NVMPWPGTE_REG_OFST         _UINT32_(0xE0)      /* (NVM_NVMPWPGTE)  Offset */
#define NVM_NVMPWPGTECLR_REG_OFST      _UINT32_(0xE4)      /* (NVM_NVMPWPGTECLR)  Offset */
#define NVM_NVMPWPGTESET_REG_OFST      _UINT32_(0xE8)      /* (NVM_NVMPWPGTESET)  Offset */
#define NVM_NVMPWPGTEINV_REG_OFST      _UINT32_(0xEC)      /* (NVM_NVMPWPGTEINV)  Offset */
#define NVM_NVMLBWP_REG_OFST           _UINT32_(0xF0)      /* (NVM_NVMLBWP)  Offset */
#define NVM_NVMLBWPCLR_REG_OFST        _UINT32_(0xF4)      /* (NVM_NVMLBWPCLR)  Offset */
#define NVM_NVMLBWPSET_REG_OFST        _UINT32_(0xF8)      /* (NVM_NVMLBWPSET)  Offset */
#define NVM_NVMLBWPINV_REG_OFST        _UINT32_(0xFC)      /* (NVM_NVMLBWPINV)  Offset */
#define NVM_NVMUBWP_REG_OFST           _UINT32_(0x100)     /* (NVM_NVMUBWP)  Offset */
#define NVM_NVMUBWPCLR_REG_OFST        _UINT32_(0x104)     /* (NVM_NVMUBWPCLR)  Offset */
#define NVM_NVMUBWPSET_REG_OFST        _UINT32_(0x108)     /* (NVM_NVMUBWPSET)  Offset */
#define NVM_NVMUBWPINV_REG_OFST        _UINT32_(0x10C)     /* (NVM_NVMUBWPINV)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief NVM register API structure */
typedef struct
{  /* flash controller */
  __IO  uint32_t                       NVM_NVMCON;         /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCONCLR;      /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCONSET;      /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCONINV;      /**< Offset: 0x0C (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2;        /**< Offset: 0x10 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2CLR;     /**< Offset: 0x14 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2SET;     /**< Offset: 0x18 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMCON2INV;     /**< Offset: 0x1C (R/W  32)  */
  __IO  uint32_t                       NVM_NVMKEY;         /**< Offset: 0x20 (R/W  32)  */
  __I   uint8_t                        Reserved1[0x0C];
  __IO  uint32_t                       NVM_NVMADDR;        /**< Offset: 0x30 (R/W  32)  */
  __I   uint8_t                        Reserved2[0x0C];
  __IO  uint32_t                       NVM_NVMDATA0;       /**< Offset: 0x40 (R/W  32)  */
  __I   uint8_t                        Reserved3[0x0C];
  __IO  uint32_t                       NVM_NVMDATA1;       /**< Offset: 0x50 (R/W  32)  */
  __I   uint8_t                        Reserved4[0x0C];
  __IO  uint32_t                       NVM_NVMDATA2;       /**< Offset: 0x60 (R/W  32)  */
  __I   uint8_t                        Reserved5[0x0C];
  __IO  uint32_t                       NVM_NVMDATA3;       /**< Offset: 0x70 (R/W  32)  */
  __I   uint8_t                        Reserved6[0x0C];
  __IO  uint32_t                       NVM_NVMDATA4;       /**< Offset: 0x80 (R/W  32)  */
  __I   uint8_t                        Reserved7[0x0C];
  __IO  uint32_t                       NVM_NVMDATA5;       /**< Offset: 0x90 (R/W  32)  */
  __I   uint8_t                        Reserved8[0x0C];
  __IO  uint32_t                       NVM_NVMDATA6;       /**< Offset: 0xA0 (R/W  32)  */
  __I   uint8_t                        Reserved9[0x0C];
  __IO  uint32_t                       NVM_NVMDATA7;       /**< Offset: 0xB0 (R/W  32)  */
  __I   uint8_t                        Reserved10[0x0C];
  __IO  uint32_t                       NVM_NVMSRCADDR;     /**< Offset: 0xC0 (R/W  32)  */
  __I   uint8_t                        Reserved11[0x0C];
  __IO  uint32_t                       NVM_NVMPWPLT;       /**< Offset: 0xD0 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPLTCLR;    /**< Offset: 0xD4 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPLTSET;    /**< Offset: 0xD8 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPLTINV;    /**< Offset: 0xDC (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTE;      /**< Offset: 0xE0 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTECLR;   /**< Offset: 0xE4 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTESET;   /**< Offset: 0xE8 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMPWPGTEINV;   /**< Offset: 0xEC (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWP;        /**< Offset: 0xF0 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWPCLR;     /**< Offset: 0xF4 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWPSET;     /**< Offset: 0xF8 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMLBWPINV;     /**< Offset: 0xFC (R/W  32)  */
  __IO  uint32_t                       NVM_NVMUBWP;        /**< Offset: 0x100 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMUBWPCLR;     /**< Offset: 0x104 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMUBWPSET;     /**< Offset: 0x108 (R/W  32)  */
  __IO  uint32_t                       NVM_NVMUBWPINV;     /**< Offset: 0x10C (R/W  32)  */
} nvm_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_NVM_COMPONENT_H_ */
