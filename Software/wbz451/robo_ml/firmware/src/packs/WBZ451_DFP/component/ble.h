/*
 * Component description for BLE
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
#ifndef _BZ45_BLE_COMPONENT_H_
#define _BZ45_BLE_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR BLE                                          */
/* ************************************************************************** */

/* -------- BLE_DPLL_RG1 : (BLE Offset: 0x4B8) (R/W 16)  -------- */
#define BLE_DPLL_RG1_DPLL_RG1BITS_Pos         _UINT16_(0)                                          /* (BLE_DPLL_RG1)  Position */
#define BLE_DPLL_RG1_DPLL_RG1BITS_Msk         (_UINT16_(0xFFFF) << BLE_DPLL_RG1_DPLL_RG1BITS_Pos)  /* (BLE_DPLL_RG1)  Mask */
#define BLE_DPLL_RG1_DPLL_RG1BITS(value)      (BLE_DPLL_RG1_DPLL_RG1BITS_Msk & (_UINT16_(value) << BLE_DPLL_RG1_DPLL_RG1BITS_Pos)) /* Assigment of value for DPLL_RG1BITS in the BLE_DPLL_RG1 register */
#define BLE_DPLL_RG1_Msk                      _UINT16_(0xFFFF)                                     /* (BLE_DPLL_RG1) Register Mask  */


/* -------- BLE_DPLL_RG2 : (BLE Offset: 0x4BA) (R/W 16)  -------- */
#define BLE_DPLL_RG2_DPLL_RG2BITS_Pos         _UINT16_(0)                                          /* (BLE_DPLL_RG2)  Position */
#define BLE_DPLL_RG2_DPLL_RG2BITS_Msk         (_UINT16_(0xFFFF) << BLE_DPLL_RG2_DPLL_RG2BITS_Pos)  /* (BLE_DPLL_RG2)  Mask */
#define BLE_DPLL_RG2_DPLL_RG2BITS(value)      (BLE_DPLL_RG2_DPLL_RG2BITS_Msk & (_UINT16_(value) << BLE_DPLL_RG2_DPLL_RG2BITS_Pos)) /* Assigment of value for DPLL_RG2BITS in the BLE_DPLL_RG2 register */
#define BLE_DPLL_RG2_Msk                      _UINT16_(0xFFFF)                                     /* (BLE_DPLL_RG2) Register Mask  */


/** \brief BLE register offsets definitions */
#define BLE_DPLL_RG1_REG_OFST          _UINT32_(0x4B8)     /* (BLE_DPLL_RG1)  Offset */
#define BLE_DPLL_RG2_REG_OFST          _UINT32_(0x4BA)     /* (BLE_DPLL_RG2)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief BLE register API structure */
typedef struct
{  /* BLE */
  __I   uint8_t                        Reserved1[0x4B8];
  __IO  uint16_t                       BLE_DPLL_RG1;       /**< Offset: 0x4B8 (R/W  16)  */
  __IO  uint16_t                       BLE_DPLL_RG2;       /**< Offset: 0x4BA (R/W  16)  */
} ble_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_BLE_COMPONENT_H_ */
