/*
 * Component description for WDT
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
#ifndef _BZ45_WDT_COMPONENT_H_
#define _BZ45_WDT_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR WDT                                          */
/* ************************************************************************** */

/* -------- WDT_WDTCON : (WDT Offset: 0x00) (R/W 32) Watchdog Timer Control Register -------- */
#define WDT_WDTCON_WDTWINEN_Pos               _UINT32_(0)                                          /* (WDT_WDTCON) Watchdog Timer Window Enable bit Position */
#define WDT_WDTCON_WDTWINEN_Msk               (_UINT32_(0x1) << WDT_WDTCON_WDTWINEN_Pos)           /* (WDT_WDTCON) Watchdog Timer Window Enable bit Mask */
#define WDT_WDTCON_WDTWINEN(value)            (WDT_WDTCON_WDTWINEN_Msk & (_UINT32_(value) << WDT_WDTCON_WDTWINEN_Pos)) /* Assigment of value for WDTWINEN in the WDT_WDTCON register */
#define   WDT_WDTCON_WDTWINEN_WDTWINEN_Val    _UINT32_(0x1)                                        /* (WDT_WDTCON) Enable windowed Watchdog Timer  */
#define   WDT_WDTCON_WDTWINEN_WDTWINDIS_Val   _UINT32_(0x0)                                        /* (WDT_WDTCON) Disable windowed Watchdog Timer  */
#define WDT_WDTCON_WDTWINEN_WDTWINEN          (WDT_WDTCON_WDTWINEN_WDTWINEN_Val << WDT_WDTCON_WDTWINEN_Pos) /* (WDT_WDTCON) Enable windowed Watchdog Timer Position  */
#define WDT_WDTCON_WDTWINEN_WDTWINDIS         (WDT_WDTCON_WDTWINEN_WDTWINDIS_Val << WDT_WDTCON_WDTWINEN_Pos) /* (WDT_WDTCON) Disable windowed Watchdog Timer Position  */
#define WDT_WDTCON_SLPDIV_Pos                 _UINT32_(1)                                          /* (WDT_WDTCON)  Position */
#define WDT_WDTCON_SLPDIV_Msk                 (_UINT32_(0x1F) << WDT_WDTCON_SLPDIV_Pos)            /* (WDT_WDTCON)  Mask */
#define WDT_WDTCON_SLPDIV(value)              (WDT_WDTCON_SLPDIV_Msk & (_UINT32_(value) << WDT_WDTCON_SLPDIV_Pos)) /* Assigment of value for SLPDIV in the WDT_WDTCON register */
#define WDT_WDTCON_CLKSEL_Pos                 _UINT32_(6)                                          /* (WDT_WDTCON)  Position */
#define WDT_WDTCON_CLKSEL_Msk                 (_UINT32_(0x3) << WDT_WDTCON_CLKSEL_Pos)             /* (WDT_WDTCON)  Mask */
#define WDT_WDTCON_CLKSEL(value)              (WDT_WDTCON_CLKSEL_Msk & (_UINT32_(value) << WDT_WDTCON_CLKSEL_Pos)) /* Assigment of value for CLKSEL in the WDT_WDTCON register */
#define WDT_WDTCON_RUNDIV_Pos                 _UINT32_(8)                                          /* (WDT_WDTCON)  Position */
#define WDT_WDTCON_RUNDIV_Msk                 (_UINT32_(0x1F) << WDT_WDTCON_RUNDIV_Pos)            /* (WDT_WDTCON)  Mask */
#define WDT_WDTCON_RUNDIV(value)              (WDT_WDTCON_RUNDIV_Msk & (_UINT32_(value) << WDT_WDTCON_RUNDIV_Pos)) /* Assigment of value for RUNDIV in the WDT_WDTCON register */
#define WDT_WDTCON_ON_Pos                     _UINT32_(15)                                         /* (WDT_WDTCON) Watchdog Timer Enable bit Position */
#define WDT_WDTCON_ON_Msk                     (_UINT32_(0x1) << WDT_WDTCON_ON_Pos)                 /* (WDT_WDTCON) Watchdog Timer Enable bit Mask */
#define WDT_WDTCON_ON(value)                  (WDT_WDTCON_ON_Msk & (_UINT32_(value) << WDT_WDTCON_ON_Pos)) /* Assigment of value for ON in the WDT_WDTCON register */
#define   WDT_WDTCON_ON_WDTEN_Val             _UINT32_(0x1)                                        /* (WDT_WDTCON) The WDT module is enabled  */
#define   WDT_WDTCON_ON_WDTOFF_Val            _UINT32_(0x0)                                        /* (WDT_WDTCON) The WDT module is disabled  */
#define WDT_WDTCON_ON_WDTEN                   (WDT_WDTCON_ON_WDTEN_Val << WDT_WDTCON_ON_Pos)       /* (WDT_WDTCON) The WDT module is enabled Position  */
#define WDT_WDTCON_ON_WDTOFF                  (WDT_WDTCON_ON_WDTOFF_Val << WDT_WDTCON_ON_Pos)      /* (WDT_WDTCON) The WDT module is disabled Position  */
#define WDT_WDTCON_WDTCLRKEY_Pos              _UINT32_(16)                                         /* (WDT_WDTCON)  Position */
#define WDT_WDTCON_WDTCLRKEY_Msk              (_UINT32_(0xFFFF) << WDT_WDTCON_WDTCLRKEY_Pos)       /* (WDT_WDTCON)  Mask */
#define WDT_WDTCON_WDTCLRKEY(value)           (WDT_WDTCON_WDTCLRKEY_Msk & (_UINT32_(value) << WDT_WDTCON_WDTCLRKEY_Pos)) /* Assigment of value for WDTCLRKEY in the WDT_WDTCON register */
#define WDT_WDTCON_Msk                        _UINT32_(0xFFFF9FFF)                                 /* (WDT_WDTCON) Register Mask  */


/* -------- WDT_WDTCONCLR : (WDT Offset: 0x04) (R/W 32)  -------- */
#define WDT_WDTCONCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (WDT_WDTCONCLR)   Reset Value */

#define WDT_WDTCONCLR_Msk                     _UINT32_(0x00000000)                                 /* (WDT_WDTCONCLR) Register Mask  */


/* -------- WDT_WDTCONSET : (WDT Offset: 0x08) (R/W 32)  -------- */
#define WDT_WDTCONSET_RESETVALUE              _UINT32_(0x00)                                       /*  (WDT_WDTCONSET)   Reset Value */

#define WDT_WDTCONSET_Msk                     _UINT32_(0x00000000)                                 /* (WDT_WDTCONSET) Register Mask  */


/* -------- WDT_WDTCONINV : (WDT Offset: 0x0C) (R/W 32)  -------- */
#define WDT_WDTCONINV_RESETVALUE              _UINT32_(0x00)                                       /*  (WDT_WDTCONINV)   Reset Value */

#define WDT_WDTCONINV_Msk                     _UINT32_(0x00000000)                                 /* (WDT_WDTCONINV) Register Mask  */


/** \brief WDT register offsets definitions */
#define WDT_WDTCON_REG_OFST            _UINT32_(0x00)      /* (WDT_WDTCON) Watchdog Timer Control Register Offset */
#define WDT_WDTCONCLR_REG_OFST         _UINT32_(0x04)      /* (WDT_WDTCONCLR)  Offset */
#define WDT_WDTCONSET_REG_OFST         _UINT32_(0x08)      /* (WDT_WDTCONSET)  Offset */
#define WDT_WDTCONINV_REG_OFST         _UINT32_(0x0C)      /* (WDT_WDTCONINV)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief WDT register API structure */
typedef struct
{
  __IO  uint32_t                       WDT_WDTCON;         /**< Offset: 0x00 (R/W  32) Watchdog Timer Control Register */
  __IO  uint32_t                       WDT_WDTCONCLR;      /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       WDT_WDTCONSET;      /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       WDT_WDTCONINV;      /**< Offset: 0x0C (R/W  32)  */
} wdt_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_WDT_COMPONENT_H_ */
