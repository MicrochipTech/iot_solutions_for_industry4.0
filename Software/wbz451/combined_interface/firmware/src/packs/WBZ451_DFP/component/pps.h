/*
 * Component description for PPS
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
#ifndef _BZ45_PPS_COMPONENT_H_
#define _BZ45_PPS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR PPS                                          */
/* ************************************************************************** */

/* -------- PPS_EXTINT0R : (PPS Offset: 0x00) (R/W 32)  -------- */
#define PPS_EXTINT0R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_EXTINT0R)   Reset Value */

#define PPS_EXTINT0R_EXTINT0_Pos              _UINT32_(0)                                          /* (PPS_EXTINT0R) EXTINT0 Position */
#define PPS_EXTINT0R_EXTINT0_Msk              (_UINT32_(0xF) << PPS_EXTINT0R_EXTINT0_Pos)          /* (PPS_EXTINT0R) EXTINT0 Mask */
#define PPS_EXTINT0R_EXTINT0(value)           (PPS_EXTINT0R_EXTINT0_Msk & (_UINT32_(value) << PPS_EXTINT0R_EXTINT0_Pos)) /* Assigment of value for EXTINT0 in the PPS_EXTINT0R register */
#define   PPS_EXTINT0R_EXTINT0_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_EXTINT0R) RPA9  */
#define   PPS_EXTINT0R_EXTINT0_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_EXTINT0R) RPA3  */
#define   PPS_EXTINT0R_EXTINT0_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_EXTINT0R) RPA7  */
#define   PPS_EXTINT0R_EXTINT0_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_EXTINT0R) RPA11  */
#define   PPS_EXTINT0R_EXTINT0_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_EXTINT0R) RPB0  */
#define   PPS_EXTINT0R_EXTINT0_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_EXTINT0R) RPB4  */
#define   PPS_EXTINT0R_EXTINT0_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_EXTINT0R) RPB8  */
#define   PPS_EXTINT0R_EXTINT0_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_EXTINT0R) RPB12  */
#define   PPS_EXTINT0R_EXTINT0_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_EXTINT0R) RPA2  */
#define   PPS_EXTINT0R_EXTINT0_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_EXTINT0R) RPA6  */
#define   PPS_EXTINT0R_EXTINT0_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_EXTINT0R) RPA10  */
#define   PPS_EXTINT0R_EXTINT0_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_EXTINT0R) RPA14  */
#define   PPS_EXTINT0R_EXTINT0_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_EXTINT0R) RPB3  */
#define   PPS_EXTINT0R_EXTINT0_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_EXTINT0R) RPB7  */
#define   PPS_EXTINT0R_EXTINT0_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_EXTINT0R) RPB11  */
#define   PPS_EXTINT0R_EXTINT0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_EXTINT0R) OFF  */
#define PPS_EXTINT0R_EXTINT0_RPA9             (PPS_EXTINT0R_EXTINT0_RPA9_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA9 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA3             (PPS_EXTINT0R_EXTINT0_RPA3_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA3 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA7             (PPS_EXTINT0R_EXTINT0_RPA7_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA7 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA11            (PPS_EXTINT0R_EXTINT0_RPA11_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA11 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB0             (PPS_EXTINT0R_EXTINT0_RPB0_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB0 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB4             (PPS_EXTINT0R_EXTINT0_RPB4_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB4 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB8             (PPS_EXTINT0R_EXTINT0_RPB8_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB8 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB12            (PPS_EXTINT0R_EXTINT0_RPB12_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB12 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA2             (PPS_EXTINT0R_EXTINT0_RPA2_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA2 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA6             (PPS_EXTINT0R_EXTINT0_RPA6_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA6 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA10            (PPS_EXTINT0R_EXTINT0_RPA10_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA10 Position  */
#define PPS_EXTINT0R_EXTINT0_RPA14            (PPS_EXTINT0R_EXTINT0_RPA14_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPA14 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB3             (PPS_EXTINT0R_EXTINT0_RPB3_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB3 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB7             (PPS_EXTINT0R_EXTINT0_RPB7_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB7 Position  */
#define PPS_EXTINT0R_EXTINT0_RPB11            (PPS_EXTINT0R_EXTINT0_RPB11_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) RPB11 Position  */
#define PPS_EXTINT0R_EXTINT0_OFF              (PPS_EXTINT0R_EXTINT0_OFF_Val << PPS_EXTINT0R_EXTINT0_Pos) /* (PPS_EXTINT0R) OFF Position  */
#define PPS_EXTINT0R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_EXTINT0R) Register Mask  */


/* -------- PPS_EXTINT1R : (PPS Offset: 0x04) (R/W 32)  -------- */
#define PPS_EXTINT1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_EXTINT1R)   Reset Value */

#define PPS_EXTINT1R_EXTINT1_Pos              _UINT32_(0)                                          /* (PPS_EXTINT1R) EXTINT1 Position */
#define PPS_EXTINT1R_EXTINT1_Msk              (_UINT32_(0xF) << PPS_EXTINT1R_EXTINT1_Pos)          /* (PPS_EXTINT1R) EXTINT1 Mask */
#define PPS_EXTINT1R_EXTINT1(value)           (PPS_EXTINT1R_EXTINT1_Msk & (_UINT32_(value) << PPS_EXTINT1R_EXTINT1_Pos)) /* Assigment of value for EXTINT1 in the PPS_EXTINT1R register */
#define   PPS_EXTINT1R_EXTINT1_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_EXTINT1R) RPA0  */
#define   PPS_EXTINT1R_EXTINT1_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_EXTINT1R) RPA4  */
#define   PPS_EXTINT1R_EXTINT1_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_EXTINT1R) RPA8  */
#define   PPS_EXTINT1R_EXTINT1_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_EXTINT1R) RPA12  */
#define   PPS_EXTINT1R_EXTINT1_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_EXTINT1R) RPB1  */
#define   PPS_EXTINT1R_EXTINT1_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_EXTINT1R) RPB5  */
#define   PPS_EXTINT1R_EXTINT1_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_EXTINT1R) RPB9  */
#define   PPS_EXTINT1R_EXTINT1_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_EXTINT1R) RPB13  */
#define   PPS_EXTINT1R_EXTINT1_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_EXTINT1R) RPA3  */
#define   PPS_EXTINT1R_EXTINT1_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_EXTINT1R) RPA7  */
#define   PPS_EXTINT1R_EXTINT1_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_EXTINT1R) RPA11  */
#define   PPS_EXTINT1R_EXTINT1_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_EXTINT1R) RPB0  */
#define   PPS_EXTINT1R_EXTINT1_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_EXTINT1R) RPB4  */
#define   PPS_EXTINT1R_EXTINT1_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_EXTINT1R) RPB8  */
#define   PPS_EXTINT1R_EXTINT1_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_EXTINT1R) RPB12  */
#define   PPS_EXTINT1R_EXTINT1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_EXTINT1R) OFF  */
#define PPS_EXTINT1R_EXTINT1_RPA0             (PPS_EXTINT1R_EXTINT1_RPA0_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA0 Position  */
#define PPS_EXTINT1R_EXTINT1_RPA4             (PPS_EXTINT1R_EXTINT1_RPA4_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA4 Position  */
#define PPS_EXTINT1R_EXTINT1_RPA8             (PPS_EXTINT1R_EXTINT1_RPA8_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA8 Position  */
#define PPS_EXTINT1R_EXTINT1_RPA12            (PPS_EXTINT1R_EXTINT1_RPA12_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA12 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB1             (PPS_EXTINT1R_EXTINT1_RPB1_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB1 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB5             (PPS_EXTINT1R_EXTINT1_RPB5_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB5 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB9             (PPS_EXTINT1R_EXTINT1_RPB9_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB9 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB13            (PPS_EXTINT1R_EXTINT1_RPB13_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB13 Position  */
#define PPS_EXTINT1R_EXTINT1_RPA3             (PPS_EXTINT1R_EXTINT1_RPA3_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA3 Position  */
#define PPS_EXTINT1R_EXTINT1_RPA7             (PPS_EXTINT1R_EXTINT1_RPA7_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA7 Position  */
#define PPS_EXTINT1R_EXTINT1_RPA11            (PPS_EXTINT1R_EXTINT1_RPA11_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPA11 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB0             (PPS_EXTINT1R_EXTINT1_RPB0_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB0 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB4             (PPS_EXTINT1R_EXTINT1_RPB4_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB4 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB8             (PPS_EXTINT1R_EXTINT1_RPB8_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB8 Position  */
#define PPS_EXTINT1R_EXTINT1_RPB12            (PPS_EXTINT1R_EXTINT1_RPB12_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) RPB12 Position  */
#define PPS_EXTINT1R_EXTINT1_OFF              (PPS_EXTINT1R_EXTINT1_OFF_Val << PPS_EXTINT1R_EXTINT1_Pos) /* (PPS_EXTINT1R) OFF Position  */
#define PPS_EXTINT1R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_EXTINT1R) Register Mask  */


/* -------- PPS_EXTINT2R : (PPS Offset: 0x08) (R/W 32)  -------- */
#define PPS_EXTINT2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_EXTINT2R)   Reset Value */

#define PPS_EXTINT2R_EXTINT2_Pos              _UINT32_(0)                                          /* (PPS_EXTINT2R) EXTINT2 Position */
#define PPS_EXTINT2R_EXTINT2_Msk              (_UINT32_(0xF) << PPS_EXTINT2R_EXTINT2_Pos)          /* (PPS_EXTINT2R) EXTINT2 Mask */
#define PPS_EXTINT2R_EXTINT2(value)           (PPS_EXTINT2R_EXTINT2_Msk & (_UINT32_(value) << PPS_EXTINT2R_EXTINT2_Pos)) /* Assigment of value for EXTINT2 in the PPS_EXTINT2R register */
#define   PPS_EXTINT2R_EXTINT2_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_EXTINT2R) RPA1  */
#define   PPS_EXTINT2R_EXTINT2_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_EXTINT2R) RPA5  */
#define   PPS_EXTINT2R_EXTINT2_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_EXTINT2R) RPA9  */
#define   PPS_EXTINT2R_EXTINT2_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_EXTINT2R) RPA13  */
#define   PPS_EXTINT2R_EXTINT2_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_EXTINT2R) RPB2  */
#define   PPS_EXTINT2R_EXTINT2_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_EXTINT2R) RPB6  */
#define   PPS_EXTINT2R_EXTINT2_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_EXTINT2R) RPB10  */
#define   PPS_EXTINT2R_EXTINT2_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_EXTINT2R) RPA0  */
#define   PPS_EXTINT2R_EXTINT2_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_EXTINT2R) RPA4  */
#define   PPS_EXTINT2R_EXTINT2_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_EXTINT2R) RPA8  */
#define   PPS_EXTINT2R_EXTINT2_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_EXTINT2R) RPA12  */
#define   PPS_EXTINT2R_EXTINT2_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_EXTINT2R) RPB1  */
#define   PPS_EXTINT2R_EXTINT2_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_EXTINT2R) RPB5  */
#define   PPS_EXTINT2R_EXTINT2_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_EXTINT2R) RPB9  */
#define   PPS_EXTINT2R_EXTINT2_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_EXTINT2R) RPB13  */
#define   PPS_EXTINT2R_EXTINT2_OFF_Val        _UINT32_(0x0)                                        /* (PPS_EXTINT2R) OFF  */
#define PPS_EXTINT2R_EXTINT2_RPA1             (PPS_EXTINT2R_EXTINT2_RPA1_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA1 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA5             (PPS_EXTINT2R_EXTINT2_RPA5_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA5 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA9             (PPS_EXTINT2R_EXTINT2_RPA9_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA9 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA13            (PPS_EXTINT2R_EXTINT2_RPA13_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA13 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB2             (PPS_EXTINT2R_EXTINT2_RPB2_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB2 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB6             (PPS_EXTINT2R_EXTINT2_RPB6_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB6 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB10            (PPS_EXTINT2R_EXTINT2_RPB10_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB10 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA0             (PPS_EXTINT2R_EXTINT2_RPA0_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA0 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA4             (PPS_EXTINT2R_EXTINT2_RPA4_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA4 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA8             (PPS_EXTINT2R_EXTINT2_RPA8_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA8 Position  */
#define PPS_EXTINT2R_EXTINT2_RPA12            (PPS_EXTINT2R_EXTINT2_RPA12_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPA12 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB1             (PPS_EXTINT2R_EXTINT2_RPB1_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB1 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB5             (PPS_EXTINT2R_EXTINT2_RPB5_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB5 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB9             (PPS_EXTINT2R_EXTINT2_RPB9_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB9 Position  */
#define PPS_EXTINT2R_EXTINT2_RPB13            (PPS_EXTINT2R_EXTINT2_RPB13_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) RPB13 Position  */
#define PPS_EXTINT2R_EXTINT2_OFF              (PPS_EXTINT2R_EXTINT2_OFF_Val << PPS_EXTINT2R_EXTINT2_Pos) /* (PPS_EXTINT2R) OFF Position  */
#define PPS_EXTINT2R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_EXTINT2R) Register Mask  */


/* -------- PPS_EXTINT3R : (PPS Offset: 0x0C) (R/W 32)  -------- */
#define PPS_EXTINT3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_EXTINT3R)   Reset Value */

#define PPS_EXTINT3R_EXTINT3_Pos              _UINT32_(0)                                          /* (PPS_EXTINT3R) EXTINT3 Position */
#define PPS_EXTINT3R_EXTINT3_Msk              (_UINT32_(0xF) << PPS_EXTINT3R_EXTINT3_Pos)          /* (PPS_EXTINT3R) EXTINT3 Mask */
#define PPS_EXTINT3R_EXTINT3(value)           (PPS_EXTINT3R_EXTINT3_Msk & (_UINT32_(value) << PPS_EXTINT3R_EXTINT3_Pos)) /* Assigment of value for EXTINT3 in the PPS_EXTINT3R register */
#define   PPS_EXTINT3R_EXTINT3_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_EXTINT3R) RPA2  */
#define   PPS_EXTINT3R_EXTINT3_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_EXTINT3R) RPA6  */
#define   PPS_EXTINT3R_EXTINT3_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_EXTINT3R) RPA10  */
#define   PPS_EXTINT3R_EXTINT3_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_EXTINT3R) RPA14  */
#define   PPS_EXTINT3R_EXTINT3_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_EXTINT3R) RPB3  */
#define   PPS_EXTINT3R_EXTINT3_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_EXTINT3R) RPB7  */
#define   PPS_EXTINT3R_EXTINT3_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_EXTINT3R) RPB11  */
#define   PPS_EXTINT3R_EXTINT3_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_EXTINT3R) RPA1  */
#define   PPS_EXTINT3R_EXTINT3_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_EXTINT3R) RPA5  */
#define   PPS_EXTINT3R_EXTINT3_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_EXTINT3R) RPA9  */
#define   PPS_EXTINT3R_EXTINT3_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_EXTINT3R) RPA13  */
#define   PPS_EXTINT3R_EXTINT3_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_EXTINT3R) RPB2  */
#define   PPS_EXTINT3R_EXTINT3_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_EXTINT3R) RPB6  */
#define   PPS_EXTINT3R_EXTINT3_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_EXTINT3R) RPB10  */
#define   PPS_EXTINT3R_EXTINT3_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_EXTINT3R) RPA8  */
#define   PPS_EXTINT3R_EXTINT3_OFF_Val        _UINT32_(0x0)                                        /* (PPS_EXTINT3R) OFF  */
#define PPS_EXTINT3R_EXTINT3_RPA2             (PPS_EXTINT3R_EXTINT3_RPA2_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA2 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA6             (PPS_EXTINT3R_EXTINT3_RPA6_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA6 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA10            (PPS_EXTINT3R_EXTINT3_RPA10_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA10 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA14            (PPS_EXTINT3R_EXTINT3_RPA14_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA14 Position  */
#define PPS_EXTINT3R_EXTINT3_RPB3             (PPS_EXTINT3R_EXTINT3_RPB3_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPB3 Position  */
#define PPS_EXTINT3R_EXTINT3_RPB7             (PPS_EXTINT3R_EXTINT3_RPB7_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPB7 Position  */
#define PPS_EXTINT3R_EXTINT3_RPB11            (PPS_EXTINT3R_EXTINT3_RPB11_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPB11 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA1             (PPS_EXTINT3R_EXTINT3_RPA1_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA1 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA5             (PPS_EXTINT3R_EXTINT3_RPA5_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA5 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA9             (PPS_EXTINT3R_EXTINT3_RPA9_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA9 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA13            (PPS_EXTINT3R_EXTINT3_RPA13_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA13 Position  */
#define PPS_EXTINT3R_EXTINT3_RPB2             (PPS_EXTINT3R_EXTINT3_RPB2_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPB2 Position  */
#define PPS_EXTINT3R_EXTINT3_RPB6             (PPS_EXTINT3R_EXTINT3_RPB6_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPB6 Position  */
#define PPS_EXTINT3R_EXTINT3_RPB10            (PPS_EXTINT3R_EXTINT3_RPB10_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPB10 Position  */
#define PPS_EXTINT3R_EXTINT3_RPA8             (PPS_EXTINT3R_EXTINT3_RPA8_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) RPA8 Position  */
#define PPS_EXTINT3R_EXTINT3_OFF              (PPS_EXTINT3R_EXTINT3_OFF_Val << PPS_EXTINT3R_EXTINT3_Pos) /* (PPS_EXTINT3R) OFF Position  */
#define PPS_EXTINT3R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_EXTINT3R) Register Mask  */


/* -------- PPS_NMIR : (PPS Offset: 0x3C) (R/W 32)  -------- */
#define PPS_NMIR_RESETVALUE                   _UINT32_(0x00)                                       /*  (PPS_NMIR)   Reset Value */

#define PPS_NMIR_NMI_Pos                      _UINT32_(0)                                          /* (PPS_NMIR) NMI Position */
#define PPS_NMIR_NMI_Msk                      (_UINT32_(0xF) << PPS_NMIR_NMI_Pos)                  /* (PPS_NMIR) NMI Mask */
#define PPS_NMIR_NMI(value)                   (PPS_NMIR_NMI_Msk & (_UINT32_(value) << PPS_NMIR_NMI_Pos)) /* Assigment of value for NMI in the PPS_NMIR register */
#define   PPS_NMIR_NMI_RPA2_Val               _UINT32_(0xF)                                        /* (PPS_NMIR) RPA2  */
#define   PPS_NMIR_NMI_RPA6_Val               _UINT32_(0x1)                                        /* (PPS_NMIR) RPA6  */
#define   PPS_NMIR_NMI_RPA10_Val              _UINT32_(0x2)                                        /* (PPS_NMIR) RPA10  */
#define   PPS_NMIR_NMI_RPA14_Val              _UINT32_(0x3)                                        /* (PPS_NMIR) RPA14  */
#define   PPS_NMIR_NMI_RPB3_Val               _UINT32_(0x4)                                        /* (PPS_NMIR) RPB3  */
#define   PPS_NMIR_NMI_RPB7_Val               _UINT32_(0x5)                                        /* (PPS_NMIR) RPB7  */
#define   PPS_NMIR_NMI_RPB11_Val              _UINT32_(0x6)                                        /* (PPS_NMIR) RPB11  */
#define   PPS_NMIR_NMI_RPA1_Val               _UINT32_(0x7)                                        /* (PPS_NMIR) RPA1  */
#define   PPS_NMIR_NMI_RPA5_Val               _UINT32_(0x8)                                        /* (PPS_NMIR) RPA5  */
#define   PPS_NMIR_NMI_RPA9_Val               _UINT32_(0x9)                                        /* (PPS_NMIR) RPA9  */
#define   PPS_NMIR_NMI_RPA13_Val              _UINT32_(0xA)                                        /* (PPS_NMIR) RPA13  */
#define   PPS_NMIR_NMI_RPB2_Val               _UINT32_(0xB)                                        /* (PPS_NMIR) RPB2  */
#define   PPS_NMIR_NMI_RPB6_Val               _UINT32_(0xC)                                        /* (PPS_NMIR) RPB6  */
#define   PPS_NMIR_NMI_RPB10_Val              _UINT32_(0xD)                                        /* (PPS_NMIR) RPB10  */
#define   PPS_NMIR_NMI_RPA8_Val               _UINT32_(0xE)                                        /* (PPS_NMIR) RPA8  */
#define   PPS_NMIR_NMI_OFF_Val                _UINT32_(0x0)                                        /* (PPS_NMIR) OFF  */
#define PPS_NMIR_NMI_RPA2                     (PPS_NMIR_NMI_RPA2_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPA2 Position  */
#define PPS_NMIR_NMI_RPA6                     (PPS_NMIR_NMI_RPA6_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPA6 Position  */
#define PPS_NMIR_NMI_RPA10                    (PPS_NMIR_NMI_RPA10_Val << PPS_NMIR_NMI_Pos)         /* (PPS_NMIR) RPA10 Position  */
#define PPS_NMIR_NMI_RPA14                    (PPS_NMIR_NMI_RPA14_Val << PPS_NMIR_NMI_Pos)         /* (PPS_NMIR) RPA14 Position  */
#define PPS_NMIR_NMI_RPB3                     (PPS_NMIR_NMI_RPB3_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPB3 Position  */
#define PPS_NMIR_NMI_RPB7                     (PPS_NMIR_NMI_RPB7_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPB7 Position  */
#define PPS_NMIR_NMI_RPB11                    (PPS_NMIR_NMI_RPB11_Val << PPS_NMIR_NMI_Pos)         /* (PPS_NMIR) RPB11 Position  */
#define PPS_NMIR_NMI_RPA1                     (PPS_NMIR_NMI_RPA1_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPA1 Position  */
#define PPS_NMIR_NMI_RPA5                     (PPS_NMIR_NMI_RPA5_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPA5 Position  */
#define PPS_NMIR_NMI_RPA9                     (PPS_NMIR_NMI_RPA9_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPA9 Position  */
#define PPS_NMIR_NMI_RPA13                    (PPS_NMIR_NMI_RPA13_Val << PPS_NMIR_NMI_Pos)         /* (PPS_NMIR) RPA13 Position  */
#define PPS_NMIR_NMI_RPB2                     (PPS_NMIR_NMI_RPB2_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPB2 Position  */
#define PPS_NMIR_NMI_RPB6                     (PPS_NMIR_NMI_RPB6_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPB6 Position  */
#define PPS_NMIR_NMI_RPB10                    (PPS_NMIR_NMI_RPB10_Val << PPS_NMIR_NMI_Pos)         /* (PPS_NMIR) RPB10 Position  */
#define PPS_NMIR_NMI_RPA8                     (PPS_NMIR_NMI_RPA8_Val << PPS_NMIR_NMI_Pos)          /* (PPS_NMIR) RPA8 Position  */
#define PPS_NMIR_NMI_OFF                      (PPS_NMIR_NMI_OFF_Val << PPS_NMIR_NMI_Pos)           /* (PPS_NMIR) OFF Position  */
#define PPS_NMIR_Msk                          _UINT32_(0x0000000F)                                 /* (PPS_NMIR) Register Mask  */


/* -------- PPS_SCOM0P0R : (PPS Offset: 0x40) (R/W 32)  -------- */
#define PPS_SCOM0P0R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM0P0R)   Reset Value */

#define PPS_SCOM0P0R_SCOM0P0_Pos              _UINT32_(0)                                          /* (PPS_SCOM0P0R) SERCOM0/PAD0 Position */
#define PPS_SCOM0P0R_SCOM0P0_Msk              (_UINT32_(0xF) << PPS_SCOM0P0R_SCOM0P0_Pos)          /* (PPS_SCOM0P0R) SERCOM0/PAD0 Mask */
#define PPS_SCOM0P0R_SCOM0P0(value)           (PPS_SCOM0P0R_SCOM0P0_Msk & (_UINT32_(value) << PPS_SCOM0P0R_SCOM0P0_Pos)) /* Assigment of value for SCOM0P0 in the PPS_SCOM0P0R register */
#define   PPS_SCOM0P0R_SCOM0P0_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_SCOM0P0R) RPA0  */
#define   PPS_SCOM0P0R_SCOM0P0_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_SCOM0P0R) RPA4  */
#define   PPS_SCOM0P0R_SCOM0P0_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_SCOM0P0R) RPA8  */
#define   PPS_SCOM0P0R_SCOM0P0_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_SCOM0P0R) RPA12  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_SCOM0P0R) RPB1  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_SCOM0P0R) RPB5  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_SCOM0P0R) RPB9  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_SCOM0P0R) RPB13  */
#define   PPS_SCOM0P0R_SCOM0P0_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_SCOM0P0R) RPA3  */
#define   PPS_SCOM0P0R_SCOM0P0_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_SCOM0P0R) RPA7  */
#define   PPS_SCOM0P0R_SCOM0P0_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_SCOM0P0R) RPA11  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_SCOM0P0R) RPB0  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_SCOM0P0R) RPB4  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_SCOM0P0R) RPB8  */
#define   PPS_SCOM0P0R_SCOM0P0_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_SCOM0P0R) RPB12  */
#define   PPS_SCOM0P0R_SCOM0P0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM0P0R) OFF  */
#define PPS_SCOM0P0R_SCOM0P0_RPA0             (PPS_SCOM0P0R_SCOM0P0_RPA0_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA0 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPA4             (PPS_SCOM0P0R_SCOM0P0_RPA4_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA4 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPA8             (PPS_SCOM0P0R_SCOM0P0_RPA8_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA8 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPA12            (PPS_SCOM0P0R_SCOM0P0_RPA12_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA12 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB1             (PPS_SCOM0P0R_SCOM0P0_RPB1_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB1 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB5             (PPS_SCOM0P0R_SCOM0P0_RPB5_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB5 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB9             (PPS_SCOM0P0R_SCOM0P0_RPB9_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB9 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB13            (PPS_SCOM0P0R_SCOM0P0_RPB13_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB13 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPA3             (PPS_SCOM0P0R_SCOM0P0_RPA3_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA3 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPA7             (PPS_SCOM0P0R_SCOM0P0_RPA7_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA7 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPA11            (PPS_SCOM0P0R_SCOM0P0_RPA11_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPA11 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB0             (PPS_SCOM0P0R_SCOM0P0_RPB0_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB0 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB4             (PPS_SCOM0P0R_SCOM0P0_RPB4_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB4 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB8             (PPS_SCOM0P0R_SCOM0P0_RPB8_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB8 Position  */
#define PPS_SCOM0P0R_SCOM0P0_RPB12            (PPS_SCOM0P0R_SCOM0P0_RPB12_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) RPB12 Position  */
#define PPS_SCOM0P0R_SCOM0P0_OFF              (PPS_SCOM0P0R_SCOM0P0_OFF_Val << PPS_SCOM0P0R_SCOM0P0_Pos) /* (PPS_SCOM0P0R) OFF Position  */
#define PPS_SCOM0P0R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM0P0R) Register Mask  */


/* -------- PPS_SCOM0P1R : (PPS Offset: 0x44) (R/W 32)  -------- */
#define PPS_SCOM0P1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM0P1R)   Reset Value */

#define PPS_SCOM0P1R_SCOM0P1_Pos              _UINT32_(0)                                          /* (PPS_SCOM0P1R) SERCOM0/PAD1 Position */
#define PPS_SCOM0P1R_SCOM0P1_Msk              (_UINT32_(0xF) << PPS_SCOM0P1R_SCOM0P1_Pos)          /* (PPS_SCOM0P1R) SERCOM0/PAD1 Mask */
#define PPS_SCOM0P1R_SCOM0P1(value)           (PPS_SCOM0P1R_SCOM0P1_Msk & (_UINT32_(value) << PPS_SCOM0P1R_SCOM0P1_Pos)) /* Assigment of value for SCOM0P1 in the PPS_SCOM0P1R register */
#define   PPS_SCOM0P1R_SCOM0P1_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_SCOM0P1R) RPA1  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_SCOM0P1R) RPA5  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_SCOM0P1R) RPA9  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_SCOM0P1R) RPA13  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_SCOM0P1R) RPB2  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_SCOM0P1R) RPB6  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_SCOM0P1R) RPB10  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_SCOM0P1R) RPA0  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_SCOM0P1R) RPA4  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_SCOM0P1R) RPA8  */
#define   PPS_SCOM0P1R_SCOM0P1_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_SCOM0P1R) RPA12  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_SCOM0P1R) RPB1  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_SCOM0P1R) RPB5  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_SCOM0P1R) RPB9  */
#define   PPS_SCOM0P1R_SCOM0P1_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_SCOM0P1R) RPB13  */
#define   PPS_SCOM0P1R_SCOM0P1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM0P1R) OFF  */
#define PPS_SCOM0P1R_SCOM0P1_RPA1             (PPS_SCOM0P1R_SCOM0P1_RPA1_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA1 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA5             (PPS_SCOM0P1R_SCOM0P1_RPA5_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA5 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA9             (PPS_SCOM0P1R_SCOM0P1_RPA9_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA9 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA13            (PPS_SCOM0P1R_SCOM0P1_RPA13_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA13 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB2             (PPS_SCOM0P1R_SCOM0P1_RPB2_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB2 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB6             (PPS_SCOM0P1R_SCOM0P1_RPB6_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB6 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB10            (PPS_SCOM0P1R_SCOM0P1_RPB10_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB10 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA0             (PPS_SCOM0P1R_SCOM0P1_RPA0_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA0 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA4             (PPS_SCOM0P1R_SCOM0P1_RPA4_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA4 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA8             (PPS_SCOM0P1R_SCOM0P1_RPA8_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA8 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPA12            (PPS_SCOM0P1R_SCOM0P1_RPA12_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPA12 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB1             (PPS_SCOM0P1R_SCOM0P1_RPB1_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB1 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB5             (PPS_SCOM0P1R_SCOM0P1_RPB5_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB5 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB9             (PPS_SCOM0P1R_SCOM0P1_RPB9_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB9 Position  */
#define PPS_SCOM0P1R_SCOM0P1_RPB13            (PPS_SCOM0P1R_SCOM0P1_RPB13_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) RPB13 Position  */
#define PPS_SCOM0P1R_SCOM0P1_OFF              (PPS_SCOM0P1R_SCOM0P1_OFF_Val << PPS_SCOM0P1R_SCOM0P1_Pos) /* (PPS_SCOM0P1R) OFF Position  */
#define PPS_SCOM0P1R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM0P1R) Register Mask  */


/* -------- PPS_SCOM0P2R : (PPS Offset: 0x48) (R/W 32)  -------- */
#define PPS_SCOM0P2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM0P2R)   Reset Value */

#define PPS_SCOM0P2R_SCOM0P2_Pos              _UINT32_(0)                                          /* (PPS_SCOM0P2R) SERCOM0/PAD2 Position */
#define PPS_SCOM0P2R_SCOM0P2_Msk              (_UINT32_(0xF) << PPS_SCOM0P2R_SCOM0P2_Pos)          /* (PPS_SCOM0P2R) SERCOM0/PAD2 Mask */
#define PPS_SCOM0P2R_SCOM0P2(value)           (PPS_SCOM0P2R_SCOM0P2_Msk & (_UINT32_(value) << PPS_SCOM0P2R_SCOM0P2_Pos)) /* Assigment of value for SCOM0P2 in the PPS_SCOM0P2R register */
#define   PPS_SCOM0P2R_SCOM0P2_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_SCOM0P2R) RPA2  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_SCOM0P2R) RPA6  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_SCOM0P2R) RPA10  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_SCOM0P2R) RPA14  */
#define   PPS_SCOM0P2R_SCOM0P2_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_SCOM0P2R) RPB3  */
#define   PPS_SCOM0P2R_SCOM0P2_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_SCOM0P2R) RPB7  */
#define   PPS_SCOM0P2R_SCOM0P2_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_SCOM0P2R) RPB11  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_SCOM0P2R) RPA1  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_SCOM0P2R) RPA5  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_SCOM0P2R) RPA9  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_SCOM0P2R) RPA13  */
#define   PPS_SCOM0P2R_SCOM0P2_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_SCOM0P2R) RPB2  */
#define   PPS_SCOM0P2R_SCOM0P2_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_SCOM0P2R) RPB6  */
#define   PPS_SCOM0P2R_SCOM0P2_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_SCOM0P2R) RPB10  */
#define   PPS_SCOM0P2R_SCOM0P2_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_SCOM0P2R) RPA8  */
#define   PPS_SCOM0P2R_SCOM0P2_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM0P2R) OFF  */
#define PPS_SCOM0P2R_SCOM0P2_RPA2             (PPS_SCOM0P2R_SCOM0P2_RPA2_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA2 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA6             (PPS_SCOM0P2R_SCOM0P2_RPA6_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA6 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA10            (PPS_SCOM0P2R_SCOM0P2_RPA10_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA10 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA14            (PPS_SCOM0P2R_SCOM0P2_RPA14_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA14 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPB3             (PPS_SCOM0P2R_SCOM0P2_RPB3_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPB3 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPB7             (PPS_SCOM0P2R_SCOM0P2_RPB7_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPB7 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPB11            (PPS_SCOM0P2R_SCOM0P2_RPB11_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPB11 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA1             (PPS_SCOM0P2R_SCOM0P2_RPA1_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA1 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA5             (PPS_SCOM0P2R_SCOM0P2_RPA5_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA5 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA9             (PPS_SCOM0P2R_SCOM0P2_RPA9_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA9 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA13            (PPS_SCOM0P2R_SCOM0P2_RPA13_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA13 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPB2             (PPS_SCOM0P2R_SCOM0P2_RPB2_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPB2 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPB6             (PPS_SCOM0P2R_SCOM0P2_RPB6_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPB6 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPB10            (PPS_SCOM0P2R_SCOM0P2_RPB10_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPB10 Position  */
#define PPS_SCOM0P2R_SCOM0P2_RPA8             (PPS_SCOM0P2R_SCOM0P2_RPA8_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) RPA8 Position  */
#define PPS_SCOM0P2R_SCOM0P2_OFF              (PPS_SCOM0P2R_SCOM0P2_OFF_Val << PPS_SCOM0P2R_SCOM0P2_Pos) /* (PPS_SCOM0P2R) OFF Position  */
#define PPS_SCOM0P2R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM0P2R) Register Mask  */


/* -------- PPS_SCOM0P3R : (PPS Offset: 0x4C) (R/W 32)  -------- */
#define PPS_SCOM0P3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM0P3R)   Reset Value */

#define PPS_SCOM0P3R_SCOM0P3_Pos              _UINT32_(0)                                          /* (PPS_SCOM0P3R) SERCOM0/PAD3 Position */
#define PPS_SCOM0P3R_SCOM0P3_Msk              (_UINT32_(0xF) << PPS_SCOM0P3R_SCOM0P3_Pos)          /* (PPS_SCOM0P3R) SERCOM0/PAD3 Mask */
#define PPS_SCOM0P3R_SCOM0P3(value)           (PPS_SCOM0P3R_SCOM0P3_Msk & (_UINT32_(value) << PPS_SCOM0P3R_SCOM0P3_Pos)) /* Assigment of value for SCOM0P3 in the PPS_SCOM0P3R register */
#define   PPS_SCOM0P3R_SCOM0P3_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_SCOM0P3R) RPA9  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_SCOM0P3R) RPA3  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_SCOM0P3R) RPA7  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_SCOM0P3R) RPA11  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_SCOM0P3R) RPB0  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_SCOM0P3R) RPB4  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_SCOM0P3R) RPB8  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_SCOM0P3R) RPB12  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_SCOM0P3R) RPA2  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_SCOM0P3R) RPA6  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_SCOM0P3R) RPA10  */
#define   PPS_SCOM0P3R_SCOM0P3_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_SCOM0P3R) RPA14  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_SCOM0P3R) RPB3  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_SCOM0P3R) RPB7  */
#define   PPS_SCOM0P3R_SCOM0P3_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_SCOM0P3R) RPB11  */
#define   PPS_SCOM0P3R_SCOM0P3_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM0P3R) OFF  */
#define PPS_SCOM0P3R_SCOM0P3_RPA9             (PPS_SCOM0P3R_SCOM0P3_RPA9_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA9 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA3             (PPS_SCOM0P3R_SCOM0P3_RPA3_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA3 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA7             (PPS_SCOM0P3R_SCOM0P3_RPA7_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA7 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA11            (PPS_SCOM0P3R_SCOM0P3_RPA11_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA11 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB0             (PPS_SCOM0P3R_SCOM0P3_RPB0_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB0 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB4             (PPS_SCOM0P3R_SCOM0P3_RPB4_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB4 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB8             (PPS_SCOM0P3R_SCOM0P3_RPB8_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB8 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB12            (PPS_SCOM0P3R_SCOM0P3_RPB12_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB12 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA2             (PPS_SCOM0P3R_SCOM0P3_RPA2_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA2 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA6             (PPS_SCOM0P3R_SCOM0P3_RPA6_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA6 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA10            (PPS_SCOM0P3R_SCOM0P3_RPA10_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA10 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPA14            (PPS_SCOM0P3R_SCOM0P3_RPA14_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPA14 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB3             (PPS_SCOM0P3R_SCOM0P3_RPB3_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB3 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB7             (PPS_SCOM0P3R_SCOM0P3_RPB7_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB7 Position  */
#define PPS_SCOM0P3R_SCOM0P3_RPB11            (PPS_SCOM0P3R_SCOM0P3_RPB11_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) RPB11 Position  */
#define PPS_SCOM0P3R_SCOM0P3_OFF              (PPS_SCOM0P3R_SCOM0P3_OFF_Val << PPS_SCOM0P3R_SCOM0P3_Pos) /* (PPS_SCOM0P3R) OFF Position  */
#define PPS_SCOM0P3R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM0P3R) Register Mask  */


/* -------- PPS_SCOM1P0R : (PPS Offset: 0x50) (R/W 32)  -------- */
#define PPS_SCOM1P0R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM1P0R)   Reset Value */

#define PPS_SCOM1P0R_SCOM1P0_Pos              _UINT32_(0)                                          /* (PPS_SCOM1P0R) SERCOM1/PAD0 Position */
#define PPS_SCOM1P0R_SCOM1P0_Msk              (_UINT32_(0xF) << PPS_SCOM1P0R_SCOM1P0_Pos)          /* (PPS_SCOM1P0R) SERCOM1/PAD0 Mask */
#define PPS_SCOM1P0R_SCOM1P0(value)           (PPS_SCOM1P0R_SCOM1P0_Msk & (_UINT32_(value) << PPS_SCOM1P0R_SCOM1P0_Pos)) /* Assigment of value for SCOM1P0 in the PPS_SCOM1P0R register */
#define   PPS_SCOM1P0R_SCOM1P0_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_SCOM1P0R) RPA1  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_SCOM1P0R) RPA5  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_SCOM1P0R) RPA9  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_SCOM1P0R) RPA13  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_SCOM1P0R) RPB2  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_SCOM1P0R) RPB6  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_SCOM1P0R) RPB10  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_SCOM1P0R) RPA0  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_SCOM1P0R) RPA4  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_SCOM1P0R) RPA8  */
#define   PPS_SCOM1P0R_SCOM1P0_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_SCOM1P0R) RPA12  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_SCOM1P0R) RPB1  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_SCOM1P0R) RPB5  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_SCOM1P0R) RPB9  */
#define   PPS_SCOM1P0R_SCOM1P0_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_SCOM1P0R) RPB13  */
#define   PPS_SCOM1P0R_SCOM1P0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM1P0R) OFF  */
#define PPS_SCOM1P0R_SCOM1P0_RPA1             (PPS_SCOM1P0R_SCOM1P0_RPA1_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA1 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA5             (PPS_SCOM1P0R_SCOM1P0_RPA5_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA5 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA9             (PPS_SCOM1P0R_SCOM1P0_RPA9_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA9 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA13            (PPS_SCOM1P0R_SCOM1P0_RPA13_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA13 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB2             (PPS_SCOM1P0R_SCOM1P0_RPB2_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB2 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB6             (PPS_SCOM1P0R_SCOM1P0_RPB6_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB6 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB10            (PPS_SCOM1P0R_SCOM1P0_RPB10_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB10 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA0             (PPS_SCOM1P0R_SCOM1P0_RPA0_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA0 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA4             (PPS_SCOM1P0R_SCOM1P0_RPA4_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA4 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA8             (PPS_SCOM1P0R_SCOM1P0_RPA8_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA8 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPA12            (PPS_SCOM1P0R_SCOM1P0_RPA12_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPA12 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB1             (PPS_SCOM1P0R_SCOM1P0_RPB1_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB1 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB5             (PPS_SCOM1P0R_SCOM1P0_RPB5_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB5 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB9             (PPS_SCOM1P0R_SCOM1P0_RPB9_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB9 Position  */
#define PPS_SCOM1P0R_SCOM1P0_RPB13            (PPS_SCOM1P0R_SCOM1P0_RPB13_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) RPB13 Position  */
#define PPS_SCOM1P0R_SCOM1P0_OFF              (PPS_SCOM1P0R_SCOM1P0_OFF_Val << PPS_SCOM1P0R_SCOM1P0_Pos) /* (PPS_SCOM1P0R) OFF Position  */
#define PPS_SCOM1P0R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM1P0R) Register Mask  */


/* -------- PPS_SCOM1P1R : (PPS Offset: 0x54) (R/W 32)  -------- */
#define PPS_SCOM1P1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM1P1R)   Reset Value */

#define PPS_SCOM1P1R_SCOM1P1_Pos              _UINT32_(0)                                          /* (PPS_SCOM1P1R) SERCOM1/PAD1 Position */
#define PPS_SCOM1P1R_SCOM1P1_Msk              (_UINT32_(0xF) << PPS_SCOM1P1R_SCOM1P1_Pos)          /* (PPS_SCOM1P1R) SERCOM1/PAD1 Mask */
#define PPS_SCOM1P1R_SCOM1P1(value)           (PPS_SCOM1P1R_SCOM1P1_Msk & (_UINT32_(value) << PPS_SCOM1P1R_SCOM1P1_Pos)) /* Assigment of value for SCOM1P1 in the PPS_SCOM1P1R register */
#define   PPS_SCOM1P1R_SCOM1P1_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_SCOM1P1R) RPA2  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_SCOM1P1R) RPA6  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_SCOM1P1R) RPA10  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_SCOM1P1R) RPA14  */
#define   PPS_SCOM1P1R_SCOM1P1_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_SCOM1P1R) RPB3  */
#define   PPS_SCOM1P1R_SCOM1P1_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_SCOM1P1R) RPB7  */
#define   PPS_SCOM1P1R_SCOM1P1_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_SCOM1P1R) RPB11  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_SCOM1P1R) RPA1  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_SCOM1P1R) RPA5  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_SCOM1P1R) RPA9  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_SCOM1P1R) RPA13  */
#define   PPS_SCOM1P1R_SCOM1P1_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_SCOM1P1R) RPB2  */
#define   PPS_SCOM1P1R_SCOM1P1_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_SCOM1P1R) RPB6  */
#define   PPS_SCOM1P1R_SCOM1P1_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_SCOM1P1R) RPB10  */
#define   PPS_SCOM1P1R_SCOM1P1_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_SCOM1P1R) RPA8  */
#define   PPS_SCOM1P1R_SCOM1P1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM1P1R) OFF  */
#define PPS_SCOM1P1R_SCOM1P1_RPA2             (PPS_SCOM1P1R_SCOM1P1_RPA2_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA2 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA6             (PPS_SCOM1P1R_SCOM1P1_RPA6_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA6 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA10            (PPS_SCOM1P1R_SCOM1P1_RPA10_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA10 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA14            (PPS_SCOM1P1R_SCOM1P1_RPA14_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA14 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPB3             (PPS_SCOM1P1R_SCOM1P1_RPB3_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPB3 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPB7             (PPS_SCOM1P1R_SCOM1P1_RPB7_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPB7 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPB11            (PPS_SCOM1P1R_SCOM1P1_RPB11_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPB11 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA1             (PPS_SCOM1P1R_SCOM1P1_RPA1_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA1 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA5             (PPS_SCOM1P1R_SCOM1P1_RPA5_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA5 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA9             (PPS_SCOM1P1R_SCOM1P1_RPA9_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA9 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA13            (PPS_SCOM1P1R_SCOM1P1_RPA13_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA13 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPB2             (PPS_SCOM1P1R_SCOM1P1_RPB2_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPB2 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPB6             (PPS_SCOM1P1R_SCOM1P1_RPB6_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPB6 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPB10            (PPS_SCOM1P1R_SCOM1P1_RPB10_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPB10 Position  */
#define PPS_SCOM1P1R_SCOM1P1_RPA8             (PPS_SCOM1P1R_SCOM1P1_RPA8_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) RPA8 Position  */
#define PPS_SCOM1P1R_SCOM1P1_OFF              (PPS_SCOM1P1R_SCOM1P1_OFF_Val << PPS_SCOM1P1R_SCOM1P1_Pos) /* (PPS_SCOM1P1R) OFF Position  */
#define PPS_SCOM1P1R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM1P1R) Register Mask  */


/* -------- PPS_SCOM1P2R : (PPS Offset: 0x58) (R/W 32)  -------- */
#define PPS_SCOM1P2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM1P2R)   Reset Value */

#define PPS_SCOM1P2R_SCOM1P2_Pos              _UINT32_(0)                                          /* (PPS_SCOM1P2R) SERCOM1/PAD2 Position */
#define PPS_SCOM1P2R_SCOM1P2_Msk              (_UINT32_(0xF) << PPS_SCOM1P2R_SCOM1P2_Pos)          /* (PPS_SCOM1P2R) SERCOM1/PAD2 Mask */
#define PPS_SCOM1P2R_SCOM1P2(value)           (PPS_SCOM1P2R_SCOM1P2_Msk & (_UINT32_(value) << PPS_SCOM1P2R_SCOM1P2_Pos)) /* Assigment of value for SCOM1P2 in the PPS_SCOM1P2R register */
#define   PPS_SCOM1P2R_SCOM1P2_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_SCOM1P2R) RPA9  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_SCOM1P2R) RPA3  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_SCOM1P2R) RPA7  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_SCOM1P2R) RPA11  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_SCOM1P2R) RPB0  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_SCOM1P2R) RPB4  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_SCOM1P2R) RPB8  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_SCOM1P2R) RPB12  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_SCOM1P2R) RPA2  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_SCOM1P2R) RPA6  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_SCOM1P2R) RPA10  */
#define   PPS_SCOM1P2R_SCOM1P2_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_SCOM1P2R) RPA14  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_SCOM1P2R) RPB3  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_SCOM1P2R) RPB7  */
#define   PPS_SCOM1P2R_SCOM1P2_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_SCOM1P2R) RPB11  */
#define   PPS_SCOM1P2R_SCOM1P2_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM1P2R) OFF  */
#define PPS_SCOM1P2R_SCOM1P2_RPA9             (PPS_SCOM1P2R_SCOM1P2_RPA9_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA9 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA3             (PPS_SCOM1P2R_SCOM1P2_RPA3_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA3 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA7             (PPS_SCOM1P2R_SCOM1P2_RPA7_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA7 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA11            (PPS_SCOM1P2R_SCOM1P2_RPA11_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA11 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB0             (PPS_SCOM1P2R_SCOM1P2_RPB0_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB0 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB4             (PPS_SCOM1P2R_SCOM1P2_RPB4_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB4 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB8             (PPS_SCOM1P2R_SCOM1P2_RPB8_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB8 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB12            (PPS_SCOM1P2R_SCOM1P2_RPB12_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB12 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA2             (PPS_SCOM1P2R_SCOM1P2_RPA2_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA2 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA6             (PPS_SCOM1P2R_SCOM1P2_RPA6_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA6 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA10            (PPS_SCOM1P2R_SCOM1P2_RPA10_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA10 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPA14            (PPS_SCOM1P2R_SCOM1P2_RPA14_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPA14 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB3             (PPS_SCOM1P2R_SCOM1P2_RPB3_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB3 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB7             (PPS_SCOM1P2R_SCOM1P2_RPB7_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB7 Position  */
#define PPS_SCOM1P2R_SCOM1P2_RPB11            (PPS_SCOM1P2R_SCOM1P2_RPB11_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) RPB11 Position  */
#define PPS_SCOM1P2R_SCOM1P2_OFF              (PPS_SCOM1P2R_SCOM1P2_OFF_Val << PPS_SCOM1P2R_SCOM1P2_Pos) /* (PPS_SCOM1P2R) OFF Position  */
#define PPS_SCOM1P2R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM1P2R) Register Mask  */


/* -------- PPS_SCOM1P3R : (PPS Offset: 0x5C) (R/W 32)  -------- */
#define PPS_SCOM1P3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM1P3R)   Reset Value */

#define PPS_SCOM1P3R_SCOM1P3_Pos              _UINT32_(0)                                          /* (PPS_SCOM1P3R) SERCOM1/PAD3 Position */
#define PPS_SCOM1P3R_SCOM1P3_Msk              (_UINT32_(0xF) << PPS_SCOM1P3R_SCOM1P3_Pos)          /* (PPS_SCOM1P3R) SERCOM1/PAD3 Mask */
#define PPS_SCOM1P3R_SCOM1P3(value)           (PPS_SCOM1P3R_SCOM1P3_Msk & (_UINT32_(value) << PPS_SCOM1P3R_SCOM1P3_Pos)) /* Assigment of value for SCOM1P3 in the PPS_SCOM1P3R register */
#define   PPS_SCOM1P3R_SCOM1P3_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_SCOM1P3R) RPA0  */
#define   PPS_SCOM1P3R_SCOM1P3_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_SCOM1P3R) RPA4  */
#define   PPS_SCOM1P3R_SCOM1P3_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_SCOM1P3R) RPA8  */
#define   PPS_SCOM1P3R_SCOM1P3_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_SCOM1P3R) RPA12  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_SCOM1P3R) RPB1  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_SCOM1P3R) RPB5  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_SCOM1P3R) RPB9  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_SCOM1P3R) RPB13  */
#define   PPS_SCOM1P3R_SCOM1P3_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_SCOM1P3R) RPA3  */
#define   PPS_SCOM1P3R_SCOM1P3_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_SCOM1P3R) RPA7  */
#define   PPS_SCOM1P3R_SCOM1P3_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_SCOM1P3R) RPA11  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_SCOM1P3R) RPB0  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_SCOM1P3R) RPB4  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_SCOM1P3R) RPB8  */
#define   PPS_SCOM1P3R_SCOM1P3_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_SCOM1P3R) RPB12  */
#define   PPS_SCOM1P3R_SCOM1P3_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM1P3R) OFF  */
#define PPS_SCOM1P3R_SCOM1P3_RPA0             (PPS_SCOM1P3R_SCOM1P3_RPA0_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA0 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPA4             (PPS_SCOM1P3R_SCOM1P3_RPA4_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA4 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPA8             (PPS_SCOM1P3R_SCOM1P3_RPA8_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA8 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPA12            (PPS_SCOM1P3R_SCOM1P3_RPA12_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA12 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB1             (PPS_SCOM1P3R_SCOM1P3_RPB1_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB1 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB5             (PPS_SCOM1P3R_SCOM1P3_RPB5_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB5 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB9             (PPS_SCOM1P3R_SCOM1P3_RPB9_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB9 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB13            (PPS_SCOM1P3R_SCOM1P3_RPB13_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB13 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPA3             (PPS_SCOM1P3R_SCOM1P3_RPA3_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA3 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPA7             (PPS_SCOM1P3R_SCOM1P3_RPA7_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA7 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPA11            (PPS_SCOM1P3R_SCOM1P3_RPA11_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPA11 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB0             (PPS_SCOM1P3R_SCOM1P3_RPB0_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB0 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB4             (PPS_SCOM1P3R_SCOM1P3_RPB4_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB4 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB8             (PPS_SCOM1P3R_SCOM1P3_RPB8_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB8 Position  */
#define PPS_SCOM1P3R_SCOM1P3_RPB12            (PPS_SCOM1P3R_SCOM1P3_RPB12_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) RPB12 Position  */
#define PPS_SCOM1P3R_SCOM1P3_OFF              (PPS_SCOM1P3R_SCOM1P3_OFF_Val << PPS_SCOM1P3R_SCOM1P3_Pos) /* (PPS_SCOM1P3R) OFF Position  */
#define PPS_SCOM1P3R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM1P3R) Register Mask  */


/* -------- PPS_SCOM2P0R : (PPS Offset: 0x60) (R/W 32)  -------- */
#define PPS_SCOM2P0R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM2P0R)   Reset Value */

#define PPS_SCOM2P0R_SCOM2P0_Pos              _UINT32_(0)                                          /* (PPS_SCOM2P0R) SERCOM2/PAD0 Position */
#define PPS_SCOM2P0R_SCOM2P0_Msk              (_UINT32_(0xF) << PPS_SCOM2P0R_SCOM2P0_Pos)          /* (PPS_SCOM2P0R) SERCOM2/PAD0 Mask */
#define PPS_SCOM2P0R_SCOM2P0(value)           (PPS_SCOM2P0R_SCOM2P0_Msk & (_UINT32_(value) << PPS_SCOM2P0R_SCOM2P0_Pos)) /* Assigment of value for SCOM2P0 in the PPS_SCOM2P0R register */
#define   PPS_SCOM2P0R_SCOM2P0_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_SCOM2P0R) RPA2  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_SCOM2P0R) RPA6  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_SCOM2P0R) RPA10  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_SCOM2P0R) RPA14  */
#define   PPS_SCOM2P0R_SCOM2P0_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_SCOM2P0R) RPB3  */
#define   PPS_SCOM2P0R_SCOM2P0_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_SCOM2P0R) RPB7  */
#define   PPS_SCOM2P0R_SCOM2P0_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_SCOM2P0R) RPB11  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_SCOM2P0R) RPA1  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_SCOM2P0R) RPA5  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_SCOM2P0R) RPA9  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_SCOM2P0R) RPA13  */
#define   PPS_SCOM2P0R_SCOM2P0_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_SCOM2P0R) RPB2  */
#define   PPS_SCOM2P0R_SCOM2P0_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_SCOM2P0R) RPB6  */
#define   PPS_SCOM2P0R_SCOM2P0_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_SCOM2P0R) RPB10  */
#define   PPS_SCOM2P0R_SCOM2P0_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_SCOM2P0R) RPA8  */
#define   PPS_SCOM2P0R_SCOM2P0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM2P0R) OFF  */
#define PPS_SCOM2P0R_SCOM2P0_RPA2             (PPS_SCOM2P0R_SCOM2P0_RPA2_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA2 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA6             (PPS_SCOM2P0R_SCOM2P0_RPA6_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA6 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA10            (PPS_SCOM2P0R_SCOM2P0_RPA10_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA10 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA14            (PPS_SCOM2P0R_SCOM2P0_RPA14_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA14 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPB3             (PPS_SCOM2P0R_SCOM2P0_RPB3_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPB3 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPB7             (PPS_SCOM2P0R_SCOM2P0_RPB7_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPB7 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPB11            (PPS_SCOM2P0R_SCOM2P0_RPB11_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPB11 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA1             (PPS_SCOM2P0R_SCOM2P0_RPA1_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA1 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA5             (PPS_SCOM2P0R_SCOM2P0_RPA5_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA5 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA9             (PPS_SCOM2P0R_SCOM2P0_RPA9_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA9 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA13            (PPS_SCOM2P0R_SCOM2P0_RPA13_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA13 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPB2             (PPS_SCOM2P0R_SCOM2P0_RPB2_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPB2 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPB6             (PPS_SCOM2P0R_SCOM2P0_RPB6_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPB6 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPB10            (PPS_SCOM2P0R_SCOM2P0_RPB10_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPB10 Position  */
#define PPS_SCOM2P0R_SCOM2P0_RPA8             (PPS_SCOM2P0R_SCOM2P0_RPA8_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) RPA8 Position  */
#define PPS_SCOM2P0R_SCOM2P0_OFF              (PPS_SCOM2P0R_SCOM2P0_OFF_Val << PPS_SCOM2P0R_SCOM2P0_Pos) /* (PPS_SCOM2P0R) OFF Position  */
#define PPS_SCOM2P0R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM2P0R) Register Mask  */


/* -------- PPS_SCOM2P1R : (PPS Offset: 0x64) (R/W 32)  -------- */
#define PPS_SCOM2P1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM2P1R)   Reset Value */

#define PPS_SCOM2P1R_SCOM2P1_Pos              _UINT32_(0)                                          /* (PPS_SCOM2P1R) SERCOM2/PAD1 Position */
#define PPS_SCOM2P1R_SCOM2P1_Msk              (_UINT32_(0xF) << PPS_SCOM2P1R_SCOM2P1_Pos)          /* (PPS_SCOM2P1R) SERCOM2/PAD1 Mask */
#define PPS_SCOM2P1R_SCOM2P1(value)           (PPS_SCOM2P1R_SCOM2P1_Msk & (_UINT32_(value) << PPS_SCOM2P1R_SCOM2P1_Pos)) /* Assigment of value for SCOM2P1 in the PPS_SCOM2P1R register */
#define   PPS_SCOM2P1R_SCOM2P1_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_SCOM2P1R) RPA9  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_SCOM2P1R) RPA3  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_SCOM2P1R) RPA7  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_SCOM2P1R) RPA11  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_SCOM2P1R) RPB0  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_SCOM2P1R) RPB4  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_SCOM2P1R) RPB8  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_SCOM2P1R) RPB12  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_SCOM2P1R) RPA2  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_SCOM2P1R) RPA6  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_SCOM2P1R) RPA10  */
#define   PPS_SCOM2P1R_SCOM2P1_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_SCOM2P1R) RPA14  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_SCOM2P1R) RPB3  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_SCOM2P1R) RPB7  */
#define   PPS_SCOM2P1R_SCOM2P1_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_SCOM2P1R) RPB11  */
#define   PPS_SCOM2P1R_SCOM2P1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM2P1R) OFF  */
#define PPS_SCOM2P1R_SCOM2P1_RPA9             (PPS_SCOM2P1R_SCOM2P1_RPA9_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA9 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA3             (PPS_SCOM2P1R_SCOM2P1_RPA3_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA3 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA7             (PPS_SCOM2P1R_SCOM2P1_RPA7_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA7 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA11            (PPS_SCOM2P1R_SCOM2P1_RPA11_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA11 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB0             (PPS_SCOM2P1R_SCOM2P1_RPB0_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB0 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB4             (PPS_SCOM2P1R_SCOM2P1_RPB4_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB4 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB8             (PPS_SCOM2P1R_SCOM2P1_RPB8_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB8 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB12            (PPS_SCOM2P1R_SCOM2P1_RPB12_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB12 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA2             (PPS_SCOM2P1R_SCOM2P1_RPA2_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA2 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA6             (PPS_SCOM2P1R_SCOM2P1_RPA6_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA6 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA10            (PPS_SCOM2P1R_SCOM2P1_RPA10_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA10 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPA14            (PPS_SCOM2P1R_SCOM2P1_RPA14_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPA14 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB3             (PPS_SCOM2P1R_SCOM2P1_RPB3_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB3 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB7             (PPS_SCOM2P1R_SCOM2P1_RPB7_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB7 Position  */
#define PPS_SCOM2P1R_SCOM2P1_RPB11            (PPS_SCOM2P1R_SCOM2P1_RPB11_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) RPB11 Position  */
#define PPS_SCOM2P1R_SCOM2P1_OFF              (PPS_SCOM2P1R_SCOM2P1_OFF_Val << PPS_SCOM2P1R_SCOM2P1_Pos) /* (PPS_SCOM2P1R) OFF Position  */
#define PPS_SCOM2P1R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM2P1R) Register Mask  */


/* -------- PPS_SCOM2P2R : (PPS Offset: 0x68) (R/W 32)  -------- */
#define PPS_SCOM2P2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM2P2R)   Reset Value */

#define PPS_SCOM2P2R_SCOM2P2_Pos              _UINT32_(0)                                          /* (PPS_SCOM2P2R) SERCOM2/PAD2 Position */
#define PPS_SCOM2P2R_SCOM2P2_Msk              (_UINT32_(0xF) << PPS_SCOM2P2R_SCOM2P2_Pos)          /* (PPS_SCOM2P2R) SERCOM2/PAD2 Mask */
#define PPS_SCOM2P2R_SCOM2P2(value)           (PPS_SCOM2P2R_SCOM2P2_Msk & (_UINT32_(value) << PPS_SCOM2P2R_SCOM2P2_Pos)) /* Assigment of value for SCOM2P2 in the PPS_SCOM2P2R register */
#define   PPS_SCOM2P2R_SCOM2P2_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_SCOM2P2R) RPA0  */
#define   PPS_SCOM2P2R_SCOM2P2_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_SCOM2P2R) RPA4  */
#define   PPS_SCOM2P2R_SCOM2P2_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_SCOM2P2R) RPA8  */
#define   PPS_SCOM2P2R_SCOM2P2_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_SCOM2P2R) RPA12  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_SCOM2P2R) RPB1  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_SCOM2P2R) RPB5  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_SCOM2P2R) RPB9  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_SCOM2P2R) RPB13  */
#define   PPS_SCOM2P2R_SCOM2P2_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_SCOM2P2R) RPA3  */
#define   PPS_SCOM2P2R_SCOM2P2_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_SCOM2P2R) RPA7  */
#define   PPS_SCOM2P2R_SCOM2P2_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_SCOM2P2R) RPA11  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_SCOM2P2R) RPB0  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_SCOM2P2R) RPB4  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_SCOM2P2R) RPB8  */
#define   PPS_SCOM2P2R_SCOM2P2_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_SCOM2P2R) RPB12  */
#define   PPS_SCOM2P2R_SCOM2P2_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM2P2R) OFF  */
#define PPS_SCOM2P2R_SCOM2P2_RPA0             (PPS_SCOM2P2R_SCOM2P2_RPA0_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA0 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPA4             (PPS_SCOM2P2R_SCOM2P2_RPA4_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA4 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPA8             (PPS_SCOM2P2R_SCOM2P2_RPA8_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA8 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPA12            (PPS_SCOM2P2R_SCOM2P2_RPA12_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA12 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB1             (PPS_SCOM2P2R_SCOM2P2_RPB1_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB1 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB5             (PPS_SCOM2P2R_SCOM2P2_RPB5_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB5 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB9             (PPS_SCOM2P2R_SCOM2P2_RPB9_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB9 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB13            (PPS_SCOM2P2R_SCOM2P2_RPB13_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB13 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPA3             (PPS_SCOM2P2R_SCOM2P2_RPA3_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA3 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPA7             (PPS_SCOM2P2R_SCOM2P2_RPA7_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA7 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPA11            (PPS_SCOM2P2R_SCOM2P2_RPA11_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPA11 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB0             (PPS_SCOM2P2R_SCOM2P2_RPB0_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB0 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB4             (PPS_SCOM2P2R_SCOM2P2_RPB4_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB4 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB8             (PPS_SCOM2P2R_SCOM2P2_RPB8_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB8 Position  */
#define PPS_SCOM2P2R_SCOM2P2_RPB12            (PPS_SCOM2P2R_SCOM2P2_RPB12_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) RPB12 Position  */
#define PPS_SCOM2P2R_SCOM2P2_OFF              (PPS_SCOM2P2R_SCOM2P2_OFF_Val << PPS_SCOM2P2R_SCOM2P2_Pos) /* (PPS_SCOM2P2R) OFF Position  */
#define PPS_SCOM2P2R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM2P2R) Register Mask  */


/* -------- PPS_SCOM2P3R : (PPS Offset: 0x6C) (R/W 32)  -------- */
#define PPS_SCOM2P3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM2P3R)   Reset Value */

#define PPS_SCOM2P3R_SCOM2P3_Pos              _UINT32_(0)                                          /* (PPS_SCOM2P3R) SERCOM2/PAD3 Position */
#define PPS_SCOM2P3R_SCOM2P3_Msk              (_UINT32_(0xF) << PPS_SCOM2P3R_SCOM2P3_Pos)          /* (PPS_SCOM2P3R) SERCOM2/PAD3 Mask */
#define PPS_SCOM2P3R_SCOM2P3(value)           (PPS_SCOM2P3R_SCOM2P3_Msk & (_UINT32_(value) << PPS_SCOM2P3R_SCOM2P3_Pos)) /* Assigment of value for SCOM2P3 in the PPS_SCOM2P3R register */
#define   PPS_SCOM2P3R_SCOM2P3_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_SCOM2P3R) RPA1  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_SCOM2P3R) RPA5  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_SCOM2P3R) RPA9  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_SCOM2P3R) RPA13  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_SCOM2P3R) RPB2  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_SCOM2P3R) RPB6  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_SCOM2P3R) RPB10  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_SCOM2P3R) RPA0  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_SCOM2P3R) RPA4  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_SCOM2P3R) RPA8  */
#define   PPS_SCOM2P3R_SCOM2P3_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_SCOM2P3R) RPA12  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_SCOM2P3R) RPB1  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_SCOM2P3R) RPB5  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_SCOM2P3R) RPB9  */
#define   PPS_SCOM2P3R_SCOM2P3_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_SCOM2P3R) RPB13  */
#define   PPS_SCOM2P3R_SCOM2P3_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM2P3R) OFF  */
#define PPS_SCOM2P3R_SCOM2P3_RPA1             (PPS_SCOM2P3R_SCOM2P3_RPA1_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA1 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA5             (PPS_SCOM2P3R_SCOM2P3_RPA5_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA5 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA9             (PPS_SCOM2P3R_SCOM2P3_RPA9_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA9 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA13            (PPS_SCOM2P3R_SCOM2P3_RPA13_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA13 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB2             (PPS_SCOM2P3R_SCOM2P3_RPB2_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB2 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB6             (PPS_SCOM2P3R_SCOM2P3_RPB6_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB6 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB10            (PPS_SCOM2P3R_SCOM2P3_RPB10_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB10 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA0             (PPS_SCOM2P3R_SCOM2P3_RPA0_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA0 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA4             (PPS_SCOM2P3R_SCOM2P3_RPA4_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA4 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA8             (PPS_SCOM2P3R_SCOM2P3_RPA8_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA8 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPA12            (PPS_SCOM2P3R_SCOM2P3_RPA12_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPA12 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB1             (PPS_SCOM2P3R_SCOM2P3_RPB1_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB1 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB5             (PPS_SCOM2P3R_SCOM2P3_RPB5_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB5 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB9             (PPS_SCOM2P3R_SCOM2P3_RPB9_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB9 Position  */
#define PPS_SCOM2P3R_SCOM2P3_RPB13            (PPS_SCOM2P3R_SCOM2P3_RPB13_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) RPB13 Position  */
#define PPS_SCOM2P3R_SCOM2P3_OFF              (PPS_SCOM2P3R_SCOM2P3_OFF_Val << PPS_SCOM2P3R_SCOM2P3_Pos) /* (PPS_SCOM2P3R) OFF Position  */
#define PPS_SCOM2P3R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM2P3R) Register Mask  */


/* -------- PPS_SCOM3P0R : (PPS Offset: 0x70) (R/W 32)  -------- */
#define PPS_SCOM3P0R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM3P0R)   Reset Value */

#define PPS_SCOM3P0R_SCOM3P0_Pos              _UINT32_(0)                                          /* (PPS_SCOM3P0R) SERCOM3/PAD0 Position */
#define PPS_SCOM3P0R_SCOM3P0_Msk              (_UINT32_(0xF) << PPS_SCOM3P0R_SCOM3P0_Pos)          /* (PPS_SCOM3P0R) SERCOM3/PAD0 Mask */
#define PPS_SCOM3P0R_SCOM3P0(value)           (PPS_SCOM3P0R_SCOM3P0_Msk & (_UINT32_(value) << PPS_SCOM3P0R_SCOM3P0_Pos)) /* Assigment of value for SCOM3P0 in the PPS_SCOM3P0R register */
#define   PPS_SCOM3P0R_SCOM3P0_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_SCOM3P0R) RPA9  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_SCOM3P0R) RPA3  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_SCOM3P0R) RPA7  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_SCOM3P0R) RPA11  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_SCOM3P0R) RPB0  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_SCOM3P0R) RPB4  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_SCOM3P0R) RPB8  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_SCOM3P0R) RPB12  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_SCOM3P0R) RPA2  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_SCOM3P0R) RPA6  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_SCOM3P0R) RPA10  */
#define   PPS_SCOM3P0R_SCOM3P0_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_SCOM3P0R) RPA14  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_SCOM3P0R) RPB3  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_SCOM3P0R) RPB7  */
#define   PPS_SCOM3P0R_SCOM3P0_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_SCOM3P0R) RPB11  */
#define   PPS_SCOM3P0R_SCOM3P0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM3P0R) OFF  */
#define PPS_SCOM3P0R_SCOM3P0_RPA9             (PPS_SCOM3P0R_SCOM3P0_RPA9_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA9 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA3             (PPS_SCOM3P0R_SCOM3P0_RPA3_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA3 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA7             (PPS_SCOM3P0R_SCOM3P0_RPA7_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA7 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA11            (PPS_SCOM3P0R_SCOM3P0_RPA11_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA11 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB0             (PPS_SCOM3P0R_SCOM3P0_RPB0_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB0 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB4             (PPS_SCOM3P0R_SCOM3P0_RPB4_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB4 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB8             (PPS_SCOM3P0R_SCOM3P0_RPB8_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB8 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB12            (PPS_SCOM3P0R_SCOM3P0_RPB12_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB12 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA2             (PPS_SCOM3P0R_SCOM3P0_RPA2_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA2 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA6             (PPS_SCOM3P0R_SCOM3P0_RPA6_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA6 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA10            (PPS_SCOM3P0R_SCOM3P0_RPA10_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA10 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPA14            (PPS_SCOM3P0R_SCOM3P0_RPA14_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPA14 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB3             (PPS_SCOM3P0R_SCOM3P0_RPB3_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB3 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB7             (PPS_SCOM3P0R_SCOM3P0_RPB7_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB7 Position  */
#define PPS_SCOM3P0R_SCOM3P0_RPB11            (PPS_SCOM3P0R_SCOM3P0_RPB11_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) RPB11 Position  */
#define PPS_SCOM3P0R_SCOM3P0_OFF              (PPS_SCOM3P0R_SCOM3P0_OFF_Val << PPS_SCOM3P0R_SCOM3P0_Pos) /* (PPS_SCOM3P0R) OFF Position  */
#define PPS_SCOM3P0R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM3P0R) Register Mask  */


/* -------- PPS_SCOM3P1R : (PPS Offset: 0x74) (R/W 32)  -------- */
#define PPS_SCOM3P1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM3P1R)   Reset Value */

#define PPS_SCOM3P1R_SCOM3P1_Pos              _UINT32_(0)                                          /* (PPS_SCOM3P1R) SERCOM3/PAD1 Position */
#define PPS_SCOM3P1R_SCOM3P1_Msk              (_UINT32_(0xF) << PPS_SCOM3P1R_SCOM3P1_Pos)          /* (PPS_SCOM3P1R) SERCOM3/PAD1 Mask */
#define PPS_SCOM3P1R_SCOM3P1(value)           (PPS_SCOM3P1R_SCOM3P1_Msk & (_UINT32_(value) << PPS_SCOM3P1R_SCOM3P1_Pos)) /* Assigment of value for SCOM3P1 in the PPS_SCOM3P1R register */
#define   PPS_SCOM3P1R_SCOM3P1_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_SCOM3P1R) RPA0  */
#define   PPS_SCOM3P1R_SCOM3P1_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_SCOM3P1R) RPA4  */
#define   PPS_SCOM3P1R_SCOM3P1_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_SCOM3P1R) RPA8  */
#define   PPS_SCOM3P1R_SCOM3P1_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_SCOM3P1R) RPA12  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_SCOM3P1R) RPB1  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_SCOM3P1R) RPB5  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_SCOM3P1R) RPB9  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_SCOM3P1R) RPB13  */
#define   PPS_SCOM3P1R_SCOM3P1_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_SCOM3P1R) RPA3  */
#define   PPS_SCOM3P1R_SCOM3P1_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_SCOM3P1R) RPA7  */
#define   PPS_SCOM3P1R_SCOM3P1_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_SCOM3P1R) RPA11  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_SCOM3P1R) RPB0  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_SCOM3P1R) RPB4  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_SCOM3P1R) RPB8  */
#define   PPS_SCOM3P1R_SCOM3P1_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_SCOM3P1R) RPB12  */
#define   PPS_SCOM3P1R_SCOM3P1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM3P1R) OFF  */
#define PPS_SCOM3P1R_SCOM3P1_RPA0             (PPS_SCOM3P1R_SCOM3P1_RPA0_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA0 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPA4             (PPS_SCOM3P1R_SCOM3P1_RPA4_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA4 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPA8             (PPS_SCOM3P1R_SCOM3P1_RPA8_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA8 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPA12            (PPS_SCOM3P1R_SCOM3P1_RPA12_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA12 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB1             (PPS_SCOM3P1R_SCOM3P1_RPB1_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB1 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB5             (PPS_SCOM3P1R_SCOM3P1_RPB5_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB5 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB9             (PPS_SCOM3P1R_SCOM3P1_RPB9_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB9 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB13            (PPS_SCOM3P1R_SCOM3P1_RPB13_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB13 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPA3             (PPS_SCOM3P1R_SCOM3P1_RPA3_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA3 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPA7             (PPS_SCOM3P1R_SCOM3P1_RPA7_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA7 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPA11            (PPS_SCOM3P1R_SCOM3P1_RPA11_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPA11 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB0             (PPS_SCOM3P1R_SCOM3P1_RPB0_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB0 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB4             (PPS_SCOM3P1R_SCOM3P1_RPB4_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB4 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB8             (PPS_SCOM3P1R_SCOM3P1_RPB8_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB8 Position  */
#define PPS_SCOM3P1R_SCOM3P1_RPB12            (PPS_SCOM3P1R_SCOM3P1_RPB12_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) RPB12 Position  */
#define PPS_SCOM3P1R_SCOM3P1_OFF              (PPS_SCOM3P1R_SCOM3P1_OFF_Val << PPS_SCOM3P1R_SCOM3P1_Pos) /* (PPS_SCOM3P1R) OFF Position  */
#define PPS_SCOM3P1R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM3P1R) Register Mask  */


/* -------- PPS_SCOM3P2R : (PPS Offset: 0x78) (R/W 32)  -------- */
#define PPS_SCOM3P2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM3P2R)   Reset Value */

#define PPS_SCOM3P2R_SCOM3P2_Pos              _UINT32_(0)                                          /* (PPS_SCOM3P2R) SERCOM3/PAD2 Position */
#define PPS_SCOM3P2R_SCOM3P2_Msk              (_UINT32_(0xF) << PPS_SCOM3P2R_SCOM3P2_Pos)          /* (PPS_SCOM3P2R) SERCOM3/PAD2 Mask */
#define PPS_SCOM3P2R_SCOM3P2(value)           (PPS_SCOM3P2R_SCOM3P2_Msk & (_UINT32_(value) << PPS_SCOM3P2R_SCOM3P2_Pos)) /* Assigment of value for SCOM3P2 in the PPS_SCOM3P2R register */
#define   PPS_SCOM3P2R_SCOM3P2_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_SCOM3P2R) RPA1  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_SCOM3P2R) RPA5  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_SCOM3P2R) RPA9  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_SCOM3P2R) RPA13  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_SCOM3P2R) RPB2  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_SCOM3P2R) RPB6  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_SCOM3P2R) RPB10  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_SCOM3P2R) RPA0  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_SCOM3P2R) RPA4  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_SCOM3P2R) RPA8  */
#define   PPS_SCOM3P2R_SCOM3P2_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_SCOM3P2R) RPA12  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_SCOM3P2R) RPB1  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_SCOM3P2R) RPB5  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_SCOM3P2R) RPB9  */
#define   PPS_SCOM3P2R_SCOM3P2_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_SCOM3P2R) RPB13  */
#define   PPS_SCOM3P2R_SCOM3P2_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM3P2R) OFF  */
#define PPS_SCOM3P2R_SCOM3P2_RPA1             (PPS_SCOM3P2R_SCOM3P2_RPA1_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA1 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA5             (PPS_SCOM3P2R_SCOM3P2_RPA5_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA5 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA9             (PPS_SCOM3P2R_SCOM3P2_RPA9_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA9 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA13            (PPS_SCOM3P2R_SCOM3P2_RPA13_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA13 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB2             (PPS_SCOM3P2R_SCOM3P2_RPB2_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB2 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB6             (PPS_SCOM3P2R_SCOM3P2_RPB6_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB6 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB10            (PPS_SCOM3P2R_SCOM3P2_RPB10_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB10 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA0             (PPS_SCOM3P2R_SCOM3P2_RPA0_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA0 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA4             (PPS_SCOM3P2R_SCOM3P2_RPA4_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA4 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA8             (PPS_SCOM3P2R_SCOM3P2_RPA8_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA8 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPA12            (PPS_SCOM3P2R_SCOM3P2_RPA12_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPA12 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB1             (PPS_SCOM3P2R_SCOM3P2_RPB1_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB1 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB5             (PPS_SCOM3P2R_SCOM3P2_RPB5_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB5 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB9             (PPS_SCOM3P2R_SCOM3P2_RPB9_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB9 Position  */
#define PPS_SCOM3P2R_SCOM3P2_RPB13            (PPS_SCOM3P2R_SCOM3P2_RPB13_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) RPB13 Position  */
#define PPS_SCOM3P2R_SCOM3P2_OFF              (PPS_SCOM3P2R_SCOM3P2_OFF_Val << PPS_SCOM3P2R_SCOM3P2_Pos) /* (PPS_SCOM3P2R) OFF Position  */
#define PPS_SCOM3P2R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM3P2R) Register Mask  */


/* -------- PPS_SCOM3P3R : (PPS Offset: 0x7C) (R/W 32)  -------- */
#define PPS_SCOM3P3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_SCOM3P3R)   Reset Value */

#define PPS_SCOM3P3R_SCOM3P3_Pos              _UINT32_(0)                                          /* (PPS_SCOM3P3R) SERCOM3/PAD3 Position */
#define PPS_SCOM3P3R_SCOM3P3_Msk              (_UINT32_(0xF) << PPS_SCOM3P3R_SCOM3P3_Pos)          /* (PPS_SCOM3P3R) SERCOM3/PAD3 Mask */
#define PPS_SCOM3P3R_SCOM3P3(value)           (PPS_SCOM3P3R_SCOM3P3_Msk & (_UINT32_(value) << PPS_SCOM3P3R_SCOM3P3_Pos)) /* Assigment of value for SCOM3P3 in the PPS_SCOM3P3R register */
#define   PPS_SCOM3P3R_SCOM3P3_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_SCOM3P3R) RPA2  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_SCOM3P3R) RPA6  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_SCOM3P3R) RPA10  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_SCOM3P3R) RPA14  */
#define   PPS_SCOM3P3R_SCOM3P3_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_SCOM3P3R) RPB3  */
#define   PPS_SCOM3P3R_SCOM3P3_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_SCOM3P3R) RPB7  */
#define   PPS_SCOM3P3R_SCOM3P3_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_SCOM3P3R) RPB11  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_SCOM3P3R) RPA1  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_SCOM3P3R) RPA5  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_SCOM3P3R) RPA9  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_SCOM3P3R) RPA13  */
#define   PPS_SCOM3P3R_SCOM3P3_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_SCOM3P3R) RPB2  */
#define   PPS_SCOM3P3R_SCOM3P3_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_SCOM3P3R) RPB6  */
#define   PPS_SCOM3P3R_SCOM3P3_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_SCOM3P3R) RPB10  */
#define   PPS_SCOM3P3R_SCOM3P3_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_SCOM3P3R) RPA8  */
#define   PPS_SCOM3P3R_SCOM3P3_OFF_Val        _UINT32_(0x0)                                        /* (PPS_SCOM3P3R) OFF  */
#define PPS_SCOM3P3R_SCOM3P3_RPA2             (PPS_SCOM3P3R_SCOM3P3_RPA2_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA2 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA6             (PPS_SCOM3P3R_SCOM3P3_RPA6_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA6 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA10            (PPS_SCOM3P3R_SCOM3P3_RPA10_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA10 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA14            (PPS_SCOM3P3R_SCOM3P3_RPA14_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA14 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPB3             (PPS_SCOM3P3R_SCOM3P3_RPB3_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPB3 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPB7             (PPS_SCOM3P3R_SCOM3P3_RPB7_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPB7 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPB11            (PPS_SCOM3P3R_SCOM3P3_RPB11_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPB11 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA1             (PPS_SCOM3P3R_SCOM3P3_RPA1_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA1 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA5             (PPS_SCOM3P3R_SCOM3P3_RPA5_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA5 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA9             (PPS_SCOM3P3R_SCOM3P3_RPA9_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA9 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA13            (PPS_SCOM3P3R_SCOM3P3_RPA13_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA13 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPB2             (PPS_SCOM3P3R_SCOM3P3_RPB2_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPB2 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPB6             (PPS_SCOM3P3R_SCOM3P3_RPB6_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPB6 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPB10            (PPS_SCOM3P3R_SCOM3P3_RPB10_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPB10 Position  */
#define PPS_SCOM3P3R_SCOM3P3_RPA8             (PPS_SCOM3P3R_SCOM3P3_RPA8_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) RPA8 Position  */
#define PPS_SCOM3P3R_SCOM3P3_OFF              (PPS_SCOM3P3R_SCOM3P3_OFF_Val << PPS_SCOM3P3R_SCOM3P3_Pos) /* (PPS_SCOM3P3R) OFF Position  */
#define PPS_SCOM3P3R_Msk                      _UINT32_(0x0000000F)                                 /* (PPS_SCOM3P3R) Register Mask  */


/* -------- PPS_QSCKR : (PPS Offset: 0x80) (R/W 32)  -------- */
#define PPS_QSCKR_RESETVALUE                  _UINT32_(0x00)                                       /*  (PPS_QSCKR)   Reset Value */

#define PPS_QSCKR_QSCK_Pos                    _UINT32_(0)                                          /* (PPS_QSCKR) QSPI/SCK Position */
#define PPS_QSCKR_QSCK_Msk                    (_UINT32_(0xF) << PPS_QSCKR_QSCK_Pos)                /* (PPS_QSCKR) QSPI/SCK Mask */
#define PPS_QSCKR_QSCK(value)                 (PPS_QSCKR_QSCK_Msk & (_UINT32_(value) << PPS_QSCKR_QSCK_Pos)) /* Assigment of value for QSCK in the PPS_QSCKR register */
#define   PPS_QSCKR_QSCK_RPA9_Val             _UINT32_(0xF)                                        /* (PPS_QSCKR) RPA9  */
#define   PPS_QSCKR_QSCK_RPA3_Val             _UINT32_(0x1)                                        /* (PPS_QSCKR) RPA3  */
#define   PPS_QSCKR_QSCK_RPA7_Val             _UINT32_(0x2)                                        /* (PPS_QSCKR) RPA7  */
#define   PPS_QSCKR_QSCK_RPA11_Val            _UINT32_(0x3)                                        /* (PPS_QSCKR) RPA11  */
#define   PPS_QSCKR_QSCK_RPB0_Val             _UINT32_(0x4)                                        /* (PPS_QSCKR) RPB0  */
#define   PPS_QSCKR_QSCK_RPB4_Val             _UINT32_(0x5)                                        /* (PPS_QSCKR) RPB4  */
#define   PPS_QSCKR_QSCK_RPB8_Val             _UINT32_(0x6)                                        /* (PPS_QSCKR) RPB8  */
#define   PPS_QSCKR_QSCK_RPB12_Val            _UINT32_(0x7)                                        /* (PPS_QSCKR) RPB12  */
#define   PPS_QSCKR_QSCK_RPA2_Val             _UINT32_(0x8)                                        /* (PPS_QSCKR) RPA2  */
#define   PPS_QSCKR_QSCK_RPA6_Val             _UINT32_(0x9)                                        /* (PPS_QSCKR) RPA6  */
#define   PPS_QSCKR_QSCK_RPA10_Val            _UINT32_(0xA)                                        /* (PPS_QSCKR) RPA10  */
#define   PPS_QSCKR_QSCK_RPA14_Val            _UINT32_(0xB)                                        /* (PPS_QSCKR) RPA14  */
#define   PPS_QSCKR_QSCK_RPB3_Val             _UINT32_(0xC)                                        /* (PPS_QSCKR) RPB3  */
#define   PPS_QSCKR_QSCK_RPB7_Val             _UINT32_(0xD)                                        /* (PPS_QSCKR) RPB7  */
#define   PPS_QSCKR_QSCK_RPB11_Val            _UINT32_(0xE)                                        /* (PPS_QSCKR) RPB11  */
#define   PPS_QSCKR_QSCK_OFF_Val              _UINT32_(0x0)                                        /* (PPS_QSCKR) OFF  */
#define PPS_QSCKR_QSCK_RPA9                   (PPS_QSCKR_QSCK_RPA9_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPA9 Position  */
#define PPS_QSCKR_QSCK_RPA3                   (PPS_QSCKR_QSCK_RPA3_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPA3 Position  */
#define PPS_QSCKR_QSCK_RPA7                   (PPS_QSCKR_QSCK_RPA7_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPA7 Position  */
#define PPS_QSCKR_QSCK_RPA11                  (PPS_QSCKR_QSCK_RPA11_Val << PPS_QSCKR_QSCK_Pos)     /* (PPS_QSCKR) RPA11 Position  */
#define PPS_QSCKR_QSCK_RPB0                   (PPS_QSCKR_QSCK_RPB0_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPB0 Position  */
#define PPS_QSCKR_QSCK_RPB4                   (PPS_QSCKR_QSCK_RPB4_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPB4 Position  */
#define PPS_QSCKR_QSCK_RPB8                   (PPS_QSCKR_QSCK_RPB8_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPB8 Position  */
#define PPS_QSCKR_QSCK_RPB12                  (PPS_QSCKR_QSCK_RPB12_Val << PPS_QSCKR_QSCK_Pos)     /* (PPS_QSCKR) RPB12 Position  */
#define PPS_QSCKR_QSCK_RPA2                   (PPS_QSCKR_QSCK_RPA2_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPA2 Position  */
#define PPS_QSCKR_QSCK_RPA6                   (PPS_QSCKR_QSCK_RPA6_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPA6 Position  */
#define PPS_QSCKR_QSCK_RPA10                  (PPS_QSCKR_QSCK_RPA10_Val << PPS_QSCKR_QSCK_Pos)     /* (PPS_QSCKR) RPA10 Position  */
#define PPS_QSCKR_QSCK_RPA14                  (PPS_QSCKR_QSCK_RPA14_Val << PPS_QSCKR_QSCK_Pos)     /* (PPS_QSCKR) RPA14 Position  */
#define PPS_QSCKR_QSCK_RPB3                   (PPS_QSCKR_QSCK_RPB3_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPB3 Position  */
#define PPS_QSCKR_QSCK_RPB7                   (PPS_QSCKR_QSCK_RPB7_Val << PPS_QSCKR_QSCK_Pos)      /* (PPS_QSCKR) RPB7 Position  */
#define PPS_QSCKR_QSCK_RPB11                  (PPS_QSCKR_QSCK_RPB11_Val << PPS_QSCKR_QSCK_Pos)     /* (PPS_QSCKR) RPB11 Position  */
#define PPS_QSCKR_QSCK_OFF                    (PPS_QSCKR_QSCK_OFF_Val << PPS_QSCKR_QSCK_Pos)       /* (PPS_QSCKR) OFF Position  */
#define PPS_QSCKR_Msk                         _UINT32_(0x0000000F)                                 /* (PPS_QSCKR) Register Mask  */


/* -------- PPS_QD0R : (PPS Offset: 0x84) (R/W 32)  -------- */
#define PPS_QD0R_RESETVALUE                   _UINT32_(0x00)                                       /*  (PPS_QD0R)   Reset Value */

#define PPS_QD0R_QD0_Pos                      _UINT32_(0)                                          /* (PPS_QD0R) QSPI/DATA0 Position */
#define PPS_QD0R_QD0_Msk                      (_UINT32_(0xF) << PPS_QD0R_QD0_Pos)                  /* (PPS_QD0R) QSPI/DATA0 Mask */
#define PPS_QD0R_QD0(value)                   (PPS_QD0R_QD0_Msk & (_UINT32_(value) << PPS_QD0R_QD0_Pos)) /* Assigment of value for QD0 in the PPS_QD0R register */
#define   PPS_QD0R_QD0_RPA2_Val               _UINT32_(0xF)                                        /* (PPS_QD0R) RPA2  */
#define   PPS_QD0R_QD0_RPA6_Val               _UINT32_(0x1)                                        /* (PPS_QD0R) RPA6  */
#define   PPS_QD0R_QD0_RPA10_Val              _UINT32_(0x2)                                        /* (PPS_QD0R) RPA10  */
#define   PPS_QD0R_QD0_RPA14_Val              _UINT32_(0x3)                                        /* (PPS_QD0R) RPA14  */
#define   PPS_QD0R_QD0_RPB3_Val               _UINT32_(0x4)                                        /* (PPS_QD0R) RPB3  */
#define   PPS_QD0R_QD0_RPB7_Val               _UINT32_(0x5)                                        /* (PPS_QD0R) RPB7  */
#define   PPS_QD0R_QD0_RPB11_Val              _UINT32_(0x6)                                        /* (PPS_QD0R) RPB11  */
#define   PPS_QD0R_QD0_RPA1_Val               _UINT32_(0x7)                                        /* (PPS_QD0R) RPA1  */
#define   PPS_QD0R_QD0_RPA5_Val               _UINT32_(0x8)                                        /* (PPS_QD0R) RPA5  */
#define   PPS_QD0R_QD0_RPA9_Val               _UINT32_(0x9)                                        /* (PPS_QD0R) RPA9  */
#define   PPS_QD0R_QD0_RPA13_Val              _UINT32_(0xA)                                        /* (PPS_QD0R) RPA13  */
#define   PPS_QD0R_QD0_RPB2_Val               _UINT32_(0xB)                                        /* (PPS_QD0R) RPB2  */
#define   PPS_QD0R_QD0_RPB6_Val               _UINT32_(0xC)                                        /* (PPS_QD0R) RPB6  */
#define   PPS_QD0R_QD0_RPB10_Val              _UINT32_(0xD)                                        /* (PPS_QD0R) RPB10  */
#define   PPS_QD0R_QD0_RPA8_Val               _UINT32_(0xE)                                        /* (PPS_QD0R) RPA8  */
#define   PPS_QD0R_QD0_OFF_Val                _UINT32_(0x0)                                        /* (PPS_QD0R) OFF  */
#define PPS_QD0R_QD0_RPA2                     (PPS_QD0R_QD0_RPA2_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPA2 Position  */
#define PPS_QD0R_QD0_RPA6                     (PPS_QD0R_QD0_RPA6_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPA6 Position  */
#define PPS_QD0R_QD0_RPA10                    (PPS_QD0R_QD0_RPA10_Val << PPS_QD0R_QD0_Pos)         /* (PPS_QD0R) RPA10 Position  */
#define PPS_QD0R_QD0_RPA14                    (PPS_QD0R_QD0_RPA14_Val << PPS_QD0R_QD0_Pos)         /* (PPS_QD0R) RPA14 Position  */
#define PPS_QD0R_QD0_RPB3                     (PPS_QD0R_QD0_RPB3_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPB3 Position  */
#define PPS_QD0R_QD0_RPB7                     (PPS_QD0R_QD0_RPB7_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPB7 Position  */
#define PPS_QD0R_QD0_RPB11                    (PPS_QD0R_QD0_RPB11_Val << PPS_QD0R_QD0_Pos)         /* (PPS_QD0R) RPB11 Position  */
#define PPS_QD0R_QD0_RPA1                     (PPS_QD0R_QD0_RPA1_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPA1 Position  */
#define PPS_QD0R_QD0_RPA5                     (PPS_QD0R_QD0_RPA5_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPA5 Position  */
#define PPS_QD0R_QD0_RPA9                     (PPS_QD0R_QD0_RPA9_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPA9 Position  */
#define PPS_QD0R_QD0_RPA13                    (PPS_QD0R_QD0_RPA13_Val << PPS_QD0R_QD0_Pos)         /* (PPS_QD0R) RPA13 Position  */
#define PPS_QD0R_QD0_RPB2                     (PPS_QD0R_QD0_RPB2_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPB2 Position  */
#define PPS_QD0R_QD0_RPB6                     (PPS_QD0R_QD0_RPB6_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPB6 Position  */
#define PPS_QD0R_QD0_RPB10                    (PPS_QD0R_QD0_RPB10_Val << PPS_QD0R_QD0_Pos)         /* (PPS_QD0R) RPB10 Position  */
#define PPS_QD0R_QD0_RPA8                     (PPS_QD0R_QD0_RPA8_Val << PPS_QD0R_QD0_Pos)          /* (PPS_QD0R) RPA8 Position  */
#define PPS_QD0R_QD0_OFF                      (PPS_QD0R_QD0_OFF_Val << PPS_QD0R_QD0_Pos)           /* (PPS_QD0R) OFF Position  */
#define PPS_QD0R_Msk                          _UINT32_(0x0000000F)                                 /* (PPS_QD0R) Register Mask  */


/* -------- PPS_QD1R : (PPS Offset: 0x88) (R/W 32)  -------- */
#define PPS_QD1R_RESETVALUE                   _UINT32_(0x00)                                       /*  (PPS_QD1R)   Reset Value */

#define PPS_QD1R_QD1_Pos                      _UINT32_(0)                                          /* (PPS_QD1R) QSPI/DATA1 Position */
#define PPS_QD1R_QD1_Msk                      (_UINT32_(0xF) << PPS_QD1R_QD1_Pos)                  /* (PPS_QD1R) QSPI/DATA1 Mask */
#define PPS_QD1R_QD1(value)                   (PPS_QD1R_QD1_Msk & (_UINT32_(value) << PPS_QD1R_QD1_Pos)) /* Assigment of value for QD1 in the PPS_QD1R register */
#define   PPS_QD1R_QD1_RPA9_Val               _UINT32_(0xF)                                        /* (PPS_QD1R) RPA9  */
#define   PPS_QD1R_QD1_RPA3_Val               _UINT32_(0x1)                                        /* (PPS_QD1R) RPA3  */
#define   PPS_QD1R_QD1_RPA7_Val               _UINT32_(0x2)                                        /* (PPS_QD1R) RPA7  */
#define   PPS_QD1R_QD1_RPA11_Val              _UINT32_(0x3)                                        /* (PPS_QD1R) RPA11  */
#define   PPS_QD1R_QD1_RPB0_Val               _UINT32_(0x4)                                        /* (PPS_QD1R) RPB0  */
#define   PPS_QD1R_QD1_RPB4_Val               _UINT32_(0x5)                                        /* (PPS_QD1R) RPB4  */
#define   PPS_QD1R_QD1_RPB8_Val               _UINT32_(0x6)                                        /* (PPS_QD1R) RPB8  */
#define   PPS_QD1R_QD1_RPB12_Val              _UINT32_(0x7)                                        /* (PPS_QD1R) RPB12  */
#define   PPS_QD1R_QD1_RPA2_Val               _UINT32_(0x8)                                        /* (PPS_QD1R) RPA2  */
#define   PPS_QD1R_QD1_RPA6_Val               _UINT32_(0x9)                                        /* (PPS_QD1R) RPA6  */
#define   PPS_QD1R_QD1_RPA10_Val              _UINT32_(0xA)                                        /* (PPS_QD1R) RPA10  */
#define   PPS_QD1R_QD1_RPA14_Val              _UINT32_(0xB)                                        /* (PPS_QD1R) RPA14  */
#define   PPS_QD1R_QD1_RPB3_Val               _UINT32_(0xC)                                        /* (PPS_QD1R) RPB3  */
#define   PPS_QD1R_QD1_RPB7_Val               _UINT32_(0xD)                                        /* (PPS_QD1R) RPB7  */
#define   PPS_QD1R_QD1_RPB11_Val              _UINT32_(0xE)                                        /* (PPS_QD1R) RPB11  */
#define   PPS_QD1R_QD1_OFF_Val                _UINT32_(0x0)                                        /* (PPS_QD1R) OFF  */
#define PPS_QD1R_QD1_RPA9                     (PPS_QD1R_QD1_RPA9_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPA9 Position  */
#define PPS_QD1R_QD1_RPA3                     (PPS_QD1R_QD1_RPA3_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPA3 Position  */
#define PPS_QD1R_QD1_RPA7                     (PPS_QD1R_QD1_RPA7_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPA7 Position  */
#define PPS_QD1R_QD1_RPA11                    (PPS_QD1R_QD1_RPA11_Val << PPS_QD1R_QD1_Pos)         /* (PPS_QD1R) RPA11 Position  */
#define PPS_QD1R_QD1_RPB0                     (PPS_QD1R_QD1_RPB0_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPB0 Position  */
#define PPS_QD1R_QD1_RPB4                     (PPS_QD1R_QD1_RPB4_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPB4 Position  */
#define PPS_QD1R_QD1_RPB8                     (PPS_QD1R_QD1_RPB8_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPB8 Position  */
#define PPS_QD1R_QD1_RPB12                    (PPS_QD1R_QD1_RPB12_Val << PPS_QD1R_QD1_Pos)         /* (PPS_QD1R) RPB12 Position  */
#define PPS_QD1R_QD1_RPA2                     (PPS_QD1R_QD1_RPA2_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPA2 Position  */
#define PPS_QD1R_QD1_RPA6                     (PPS_QD1R_QD1_RPA6_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPA6 Position  */
#define PPS_QD1R_QD1_RPA10                    (PPS_QD1R_QD1_RPA10_Val << PPS_QD1R_QD1_Pos)         /* (PPS_QD1R) RPA10 Position  */
#define PPS_QD1R_QD1_RPA14                    (PPS_QD1R_QD1_RPA14_Val << PPS_QD1R_QD1_Pos)         /* (PPS_QD1R) RPA14 Position  */
#define PPS_QD1R_QD1_RPB3                     (PPS_QD1R_QD1_RPB3_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPB3 Position  */
#define PPS_QD1R_QD1_RPB7                     (PPS_QD1R_QD1_RPB7_Val << PPS_QD1R_QD1_Pos)          /* (PPS_QD1R) RPB7 Position  */
#define PPS_QD1R_QD1_RPB11                    (PPS_QD1R_QD1_RPB11_Val << PPS_QD1R_QD1_Pos)         /* (PPS_QD1R) RPB11 Position  */
#define PPS_QD1R_QD1_OFF                      (PPS_QD1R_QD1_OFF_Val << PPS_QD1R_QD1_Pos)           /* (PPS_QD1R) OFF Position  */
#define PPS_QD1R_Msk                          _UINT32_(0x0000000F)                                 /* (PPS_QD1R) Register Mask  */


/* -------- PPS_QD2R : (PPS Offset: 0x8C) (R/W 32)  -------- */
#define PPS_QD2R_RESETVALUE                   _UINT32_(0x00)                                       /*  (PPS_QD2R)   Reset Value */

#define PPS_QD2R_QD2_Pos                      _UINT32_(0)                                          /* (PPS_QD2R) QSPI/DATA2 Position */
#define PPS_QD2R_QD2_Msk                      (_UINT32_(0xF) << PPS_QD2R_QD2_Pos)                  /* (PPS_QD2R) QSPI/DATA2 Mask */
#define PPS_QD2R_QD2(value)                   (PPS_QD2R_QD2_Msk & (_UINT32_(value) << PPS_QD2R_QD2_Pos)) /* Assigment of value for QD2 in the PPS_QD2R register */
#define   PPS_QD2R_QD2_RPA0_Val               _UINT32_(0xF)                                        /* (PPS_QD2R) RPA0  */
#define   PPS_QD2R_QD2_RPA4_Val               _UINT32_(0x1)                                        /* (PPS_QD2R) RPA4  */
#define   PPS_QD2R_QD2_RPA8_Val               _UINT32_(0x2)                                        /* (PPS_QD2R) RPA8  */
#define   PPS_QD2R_QD2_RPA12_Val              _UINT32_(0x3)                                        /* (PPS_QD2R) RPA12  */
#define   PPS_QD2R_QD2_RPB1_Val               _UINT32_(0x4)                                        /* (PPS_QD2R) RPB1  */
#define   PPS_QD2R_QD2_RPB5_Val               _UINT32_(0x5)                                        /* (PPS_QD2R) RPB5  */
#define   PPS_QD2R_QD2_RPB9_Val               _UINT32_(0x6)                                        /* (PPS_QD2R) RPB9  */
#define   PPS_QD2R_QD2_RPB13_Val              _UINT32_(0x7)                                        /* (PPS_QD2R) RPB13  */
#define   PPS_QD2R_QD2_RPA3_Val               _UINT32_(0x8)                                        /* (PPS_QD2R) RPA3  */
#define   PPS_QD2R_QD2_RPA7_Val               _UINT32_(0x9)                                        /* (PPS_QD2R) RPA7  */
#define   PPS_QD2R_QD2_RPA11_Val              _UINT32_(0xA)                                        /* (PPS_QD2R) RPA11  */
#define   PPS_QD2R_QD2_RPB0_Val               _UINT32_(0xB)                                        /* (PPS_QD2R) RPB0  */
#define   PPS_QD2R_QD2_RPB4_Val               _UINT32_(0xC)                                        /* (PPS_QD2R) RPB4  */
#define   PPS_QD2R_QD2_RPB8_Val               _UINT32_(0xD)                                        /* (PPS_QD2R) RPB8  */
#define   PPS_QD2R_QD2_RPB12_Val              _UINT32_(0xE)                                        /* (PPS_QD2R) RPB12  */
#define   PPS_QD2R_QD2_OFF_Val                _UINT32_(0x0)                                        /* (PPS_QD2R) OFF  */
#define PPS_QD2R_QD2_RPA0                     (PPS_QD2R_QD2_RPA0_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPA0 Position  */
#define PPS_QD2R_QD2_RPA4                     (PPS_QD2R_QD2_RPA4_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPA4 Position  */
#define PPS_QD2R_QD2_RPA8                     (PPS_QD2R_QD2_RPA8_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPA8 Position  */
#define PPS_QD2R_QD2_RPA12                    (PPS_QD2R_QD2_RPA12_Val << PPS_QD2R_QD2_Pos)         /* (PPS_QD2R) RPA12 Position  */
#define PPS_QD2R_QD2_RPB1                     (PPS_QD2R_QD2_RPB1_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPB1 Position  */
#define PPS_QD2R_QD2_RPB5                     (PPS_QD2R_QD2_RPB5_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPB5 Position  */
#define PPS_QD2R_QD2_RPB9                     (PPS_QD2R_QD2_RPB9_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPB9 Position  */
#define PPS_QD2R_QD2_RPB13                    (PPS_QD2R_QD2_RPB13_Val << PPS_QD2R_QD2_Pos)         /* (PPS_QD2R) RPB13 Position  */
#define PPS_QD2R_QD2_RPA3                     (PPS_QD2R_QD2_RPA3_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPA3 Position  */
#define PPS_QD2R_QD2_RPA7                     (PPS_QD2R_QD2_RPA7_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPA7 Position  */
#define PPS_QD2R_QD2_RPA11                    (PPS_QD2R_QD2_RPA11_Val << PPS_QD2R_QD2_Pos)         /* (PPS_QD2R) RPA11 Position  */
#define PPS_QD2R_QD2_RPB0                     (PPS_QD2R_QD2_RPB0_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPB0 Position  */
#define PPS_QD2R_QD2_RPB4                     (PPS_QD2R_QD2_RPB4_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPB4 Position  */
#define PPS_QD2R_QD2_RPB8                     (PPS_QD2R_QD2_RPB8_Val << PPS_QD2R_QD2_Pos)          /* (PPS_QD2R) RPB8 Position  */
#define PPS_QD2R_QD2_RPB12                    (PPS_QD2R_QD2_RPB12_Val << PPS_QD2R_QD2_Pos)         /* (PPS_QD2R) RPB12 Position  */
#define PPS_QD2R_QD2_OFF                      (PPS_QD2R_QD2_OFF_Val << PPS_QD2R_QD2_Pos)           /* (PPS_QD2R) OFF Position  */
#define PPS_QD2R_Msk                          _UINT32_(0x0000000F)                                 /* (PPS_QD2R) Register Mask  */


/* -------- PPS_QD3R : (PPS Offset: 0x90) (R/W 32)  -------- */
#define PPS_QD3R_RESETVALUE                   _UINT32_(0x00)                                       /*  (PPS_QD3R)   Reset Value */

#define PPS_QD3R_QD3_Pos                      _UINT32_(0)                                          /* (PPS_QD3R) QSPI/DATA3 Position */
#define PPS_QD3R_QD3_Msk                      (_UINT32_(0xF) << PPS_QD3R_QD3_Pos)                  /* (PPS_QD3R) QSPI/DATA3 Mask */
#define PPS_QD3R_QD3(value)                   (PPS_QD3R_QD3_Msk & (_UINT32_(value) << PPS_QD3R_QD3_Pos)) /* Assigment of value for QD3 in the PPS_QD3R register */
#define   PPS_QD3R_QD3_RPA1_Val               _UINT32_(0xF)                                        /* (PPS_QD3R) RPA1  */
#define   PPS_QD3R_QD3_RPA5_Val               _UINT32_(0x1)                                        /* (PPS_QD3R) RPA5  */
#define   PPS_QD3R_QD3_RPA9_Val               _UINT32_(0x2)                                        /* (PPS_QD3R) RPA9  */
#define   PPS_QD3R_QD3_RPA13_Val              _UINT32_(0x3)                                        /* (PPS_QD3R) RPA13  */
#define   PPS_QD3R_QD3_RPB2_Val               _UINT32_(0x4)                                        /* (PPS_QD3R) RPB2  */
#define   PPS_QD3R_QD3_RPB6_Val               _UINT32_(0x5)                                        /* (PPS_QD3R) RPB6  */
#define   PPS_QD3R_QD3_RPB10_Val              _UINT32_(0x6)                                        /* (PPS_QD3R) RPB10  */
#define   PPS_QD3R_QD3_RPA0_Val               _UINT32_(0x7)                                        /* (PPS_QD3R) RPA0  */
#define   PPS_QD3R_QD3_RPA4_Val               _UINT32_(0x8)                                        /* (PPS_QD3R) RPA4  */
#define   PPS_QD3R_QD3_RPA8_Val               _UINT32_(0x9)                                        /* (PPS_QD3R) RPA8  */
#define   PPS_QD3R_QD3_RPA12_Val              _UINT32_(0xA)                                        /* (PPS_QD3R) RPA12  */
#define   PPS_QD3R_QD3_RPB1_Val               _UINT32_(0xB)                                        /* (PPS_QD3R) RPB1  */
#define   PPS_QD3R_QD3_RPB5_Val               _UINT32_(0xC)                                        /* (PPS_QD3R) RPB5  */
#define   PPS_QD3R_QD3_RPB9_Val               _UINT32_(0xD)                                        /* (PPS_QD3R) RPB9  */
#define   PPS_QD3R_QD3_RPB13_Val              _UINT32_(0xE)                                        /* (PPS_QD3R) RPB13  */
#define   PPS_QD3R_QD3_OFF_Val                _UINT32_(0x0)                                        /* (PPS_QD3R) OFF  */
#define PPS_QD3R_QD3_RPA1                     (PPS_QD3R_QD3_RPA1_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPA1 Position  */
#define PPS_QD3R_QD3_RPA5                     (PPS_QD3R_QD3_RPA5_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPA5 Position  */
#define PPS_QD3R_QD3_RPA9                     (PPS_QD3R_QD3_RPA9_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPA9 Position  */
#define PPS_QD3R_QD3_RPA13                    (PPS_QD3R_QD3_RPA13_Val << PPS_QD3R_QD3_Pos)         /* (PPS_QD3R) RPA13 Position  */
#define PPS_QD3R_QD3_RPB2                     (PPS_QD3R_QD3_RPB2_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPB2 Position  */
#define PPS_QD3R_QD3_RPB6                     (PPS_QD3R_QD3_RPB6_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPB6 Position  */
#define PPS_QD3R_QD3_RPB10                    (PPS_QD3R_QD3_RPB10_Val << PPS_QD3R_QD3_Pos)         /* (PPS_QD3R) RPB10 Position  */
#define PPS_QD3R_QD3_RPA0                     (PPS_QD3R_QD3_RPA0_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPA0 Position  */
#define PPS_QD3R_QD3_RPA4                     (PPS_QD3R_QD3_RPA4_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPA4 Position  */
#define PPS_QD3R_QD3_RPA8                     (PPS_QD3R_QD3_RPA8_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPA8 Position  */
#define PPS_QD3R_QD3_RPA12                    (PPS_QD3R_QD3_RPA12_Val << PPS_QD3R_QD3_Pos)         /* (PPS_QD3R) RPA12 Position  */
#define PPS_QD3R_QD3_RPB1                     (PPS_QD3R_QD3_RPB1_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPB1 Position  */
#define PPS_QD3R_QD3_RPB5                     (PPS_QD3R_QD3_RPB5_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPB5 Position  */
#define PPS_QD3R_QD3_RPB9                     (PPS_QD3R_QD3_RPB9_Val << PPS_QD3R_QD3_Pos)          /* (PPS_QD3R) RPB9 Position  */
#define PPS_QD3R_QD3_RPB13                    (PPS_QD3R_QD3_RPB13_Val << PPS_QD3R_QD3_Pos)         /* (PPS_QD3R) RPB13 Position  */
#define PPS_QD3R_QD3_OFF                      (PPS_QD3R_QD3_OFF_Val << PPS_QD3R_QD3_Pos)           /* (PPS_QD3R) OFF Position  */
#define PPS_QD3R_Msk                          _UINT32_(0x0000000F)                                 /* (PPS_QD3R) Register Mask  */


/* -------- PPS_REFIR : (PPS Offset: 0x94) (R/W 32)  -------- */
#define PPS_REFIR_RESETVALUE                  _UINT32_(0x00)                                       /*  (PPS_REFIR)   Reset Value */

#define PPS_REFIR_REFI_Pos                    _UINT32_(0)                                          /* (PPS_REFIR) REFI Position */
#define PPS_REFIR_REFI_Msk                    (_UINT32_(0xF) << PPS_REFIR_REFI_Pos)                /* (PPS_REFIR) REFI Mask */
#define PPS_REFIR_REFI(value)                 (PPS_REFIR_REFI_Msk & (_UINT32_(value) << PPS_REFIR_REFI_Pos)) /* Assigment of value for REFI in the PPS_REFIR register */
#define   PPS_REFIR_REFI_RPA9_Val             _UINT32_(0xF)                                        /* (PPS_REFIR) RPA9  */
#define   PPS_REFIR_REFI_RPA3_Val             _UINT32_(0x1)                                        /* (PPS_REFIR) RPA3  */
#define   PPS_REFIR_REFI_RPA7_Val             _UINT32_(0x2)                                        /* (PPS_REFIR) RPA7  */
#define   PPS_REFIR_REFI_RPA11_Val            _UINT32_(0x3)                                        /* (PPS_REFIR) RPA11  */
#define   PPS_REFIR_REFI_RPB0_Val             _UINT32_(0x4)                                        /* (PPS_REFIR) RPB0  */
#define   PPS_REFIR_REFI_RPB4_Val             _UINT32_(0x5)                                        /* (PPS_REFIR) RPB4  */
#define   PPS_REFIR_REFI_RPB8_Val             _UINT32_(0x6)                                        /* (PPS_REFIR) RPB8  */
#define   PPS_REFIR_REFI_RPB12_Val            _UINT32_(0x7)                                        /* (PPS_REFIR) RPB12  */
#define   PPS_REFIR_REFI_RPA2_Val             _UINT32_(0x8)                                        /* (PPS_REFIR) RPA2  */
#define   PPS_REFIR_REFI_RPA6_Val             _UINT32_(0x9)                                        /* (PPS_REFIR) RPA6  */
#define   PPS_REFIR_REFI_RPA10_Val            _UINT32_(0xA)                                        /* (PPS_REFIR) RPA10  */
#define   PPS_REFIR_REFI_RPA14_Val            _UINT32_(0xB)                                        /* (PPS_REFIR) RPA14  */
#define   PPS_REFIR_REFI_RPB3_Val             _UINT32_(0xC)                                        /* (PPS_REFIR) RPB3  */
#define   PPS_REFIR_REFI_RPB7_Val             _UINT32_(0xD)                                        /* (PPS_REFIR) RPB7  */
#define   PPS_REFIR_REFI_RPB11_Val            _UINT32_(0xE)                                        /* (PPS_REFIR) RPB11  */
#define   PPS_REFIR_REFI_OFF_Val              _UINT32_(0x0)                                        /* (PPS_REFIR) OFF  */
#define PPS_REFIR_REFI_RPA9                   (PPS_REFIR_REFI_RPA9_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPA9 Position  */
#define PPS_REFIR_REFI_RPA3                   (PPS_REFIR_REFI_RPA3_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPA3 Position  */
#define PPS_REFIR_REFI_RPA7                   (PPS_REFIR_REFI_RPA7_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPA7 Position  */
#define PPS_REFIR_REFI_RPA11                  (PPS_REFIR_REFI_RPA11_Val << PPS_REFIR_REFI_Pos)     /* (PPS_REFIR) RPA11 Position  */
#define PPS_REFIR_REFI_RPB0                   (PPS_REFIR_REFI_RPB0_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPB0 Position  */
#define PPS_REFIR_REFI_RPB4                   (PPS_REFIR_REFI_RPB4_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPB4 Position  */
#define PPS_REFIR_REFI_RPB8                   (PPS_REFIR_REFI_RPB8_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPB8 Position  */
#define PPS_REFIR_REFI_RPB12                  (PPS_REFIR_REFI_RPB12_Val << PPS_REFIR_REFI_Pos)     /* (PPS_REFIR) RPB12 Position  */
#define PPS_REFIR_REFI_RPA2                   (PPS_REFIR_REFI_RPA2_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPA2 Position  */
#define PPS_REFIR_REFI_RPA6                   (PPS_REFIR_REFI_RPA6_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPA6 Position  */
#define PPS_REFIR_REFI_RPA10                  (PPS_REFIR_REFI_RPA10_Val << PPS_REFIR_REFI_Pos)     /* (PPS_REFIR) RPA10 Position  */
#define PPS_REFIR_REFI_RPA14                  (PPS_REFIR_REFI_RPA14_Val << PPS_REFIR_REFI_Pos)     /* (PPS_REFIR) RPA14 Position  */
#define PPS_REFIR_REFI_RPB3                   (PPS_REFIR_REFI_RPB3_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPB3 Position  */
#define PPS_REFIR_REFI_RPB7                   (PPS_REFIR_REFI_RPB7_Val << PPS_REFIR_REFI_Pos)      /* (PPS_REFIR) RPB7 Position  */
#define PPS_REFIR_REFI_RPB11                  (PPS_REFIR_REFI_RPB11_Val << PPS_REFIR_REFI_Pos)     /* (PPS_REFIR) RPB11 Position  */
#define PPS_REFIR_REFI_OFF                    (PPS_REFIR_REFI_OFF_Val << PPS_REFIR_REFI_Pos)       /* (PPS_REFIR) OFF Position  */
#define PPS_REFIR_Msk                         _UINT32_(0x0000000F)                                 /* (PPS_REFIR) Register Mask  */


/* -------- PPS_CCLIN0R : (PPS Offset: 0x98) (R/W 32)  -------- */
#define PPS_CCLIN0R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_CCLIN0R)   Reset Value */

#define PPS_CCLIN0R_CCLIN0_Pos                _UINT32_(0)                                          /* (PPS_CCLIN0R) CCL/IN0 Position */
#define PPS_CCLIN0R_CCLIN0_Msk                (_UINT32_(0xF) << PPS_CCLIN0R_CCLIN0_Pos)            /* (PPS_CCLIN0R) CCL/IN0 Mask */
#define PPS_CCLIN0R_CCLIN0(value)             (PPS_CCLIN0R_CCLIN0_Msk & (_UINT32_(value) << PPS_CCLIN0R_CCLIN0_Pos)) /* Assigment of value for CCLIN0 in the PPS_CCLIN0R register */
#define   PPS_CCLIN0R_CCLIN0_RPA9_Val         _UINT32_(0xF)                                        /* (PPS_CCLIN0R) RPA9  */
#define   PPS_CCLIN0R_CCLIN0_RPA3_Val         _UINT32_(0x1)                                        /* (PPS_CCLIN0R) RPA3  */
#define   PPS_CCLIN0R_CCLIN0_RPA7_Val         _UINT32_(0x2)                                        /* (PPS_CCLIN0R) RPA7  */
#define   PPS_CCLIN0R_CCLIN0_RPA11_Val        _UINT32_(0x3)                                        /* (PPS_CCLIN0R) RPA11  */
#define   PPS_CCLIN0R_CCLIN0_RPB0_Val         _UINT32_(0x4)                                        /* (PPS_CCLIN0R) RPB0  */
#define   PPS_CCLIN0R_CCLIN0_RPB4_Val         _UINT32_(0x5)                                        /* (PPS_CCLIN0R) RPB4  */
#define   PPS_CCLIN0R_CCLIN0_RPB8_Val         _UINT32_(0x6)                                        /* (PPS_CCLIN0R) RPB8  */
#define   PPS_CCLIN0R_CCLIN0_RPB12_Val        _UINT32_(0x7)                                        /* (PPS_CCLIN0R) RPB12  */
#define   PPS_CCLIN0R_CCLIN0_RPA2_Val         _UINT32_(0x8)                                        /* (PPS_CCLIN0R) RPA2  */
#define   PPS_CCLIN0R_CCLIN0_RPA6_Val         _UINT32_(0x9)                                        /* (PPS_CCLIN0R) RPA6  */
#define   PPS_CCLIN0R_CCLIN0_RPA10_Val        _UINT32_(0xA)                                        /* (PPS_CCLIN0R) RPA10  */
#define   PPS_CCLIN0R_CCLIN0_RPA14_Val        _UINT32_(0xB)                                        /* (PPS_CCLIN0R) RPA14  */
#define   PPS_CCLIN0R_CCLIN0_RPB3_Val         _UINT32_(0xC)                                        /* (PPS_CCLIN0R) RPB3  */
#define   PPS_CCLIN0R_CCLIN0_RPB7_Val         _UINT32_(0xD)                                        /* (PPS_CCLIN0R) RPB7  */
#define   PPS_CCLIN0R_CCLIN0_RPB11_Val        _UINT32_(0xE)                                        /* (PPS_CCLIN0R) RPB11  */
#define   PPS_CCLIN0R_CCLIN0_OFF_Val          _UINT32_(0x0)                                        /* (PPS_CCLIN0R) OFF  */
#define PPS_CCLIN0R_CCLIN0_RPA9               (PPS_CCLIN0R_CCLIN0_RPA9_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA9 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA3               (PPS_CCLIN0R_CCLIN0_RPA3_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA3 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA7               (PPS_CCLIN0R_CCLIN0_RPA7_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA7 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA11              (PPS_CCLIN0R_CCLIN0_RPA11_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA11 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB0               (PPS_CCLIN0R_CCLIN0_RPB0_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB0 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB4               (PPS_CCLIN0R_CCLIN0_RPB4_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB4 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB8               (PPS_CCLIN0R_CCLIN0_RPB8_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB8 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB12              (PPS_CCLIN0R_CCLIN0_RPB12_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB12 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA2               (PPS_CCLIN0R_CCLIN0_RPA2_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA2 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA6               (PPS_CCLIN0R_CCLIN0_RPA6_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA6 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA10              (PPS_CCLIN0R_CCLIN0_RPA10_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA10 Position  */
#define PPS_CCLIN0R_CCLIN0_RPA14              (PPS_CCLIN0R_CCLIN0_RPA14_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPA14 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB3               (PPS_CCLIN0R_CCLIN0_RPB3_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB3 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB7               (PPS_CCLIN0R_CCLIN0_RPB7_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB7 Position  */
#define PPS_CCLIN0R_CCLIN0_RPB11              (PPS_CCLIN0R_CCLIN0_RPB11_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) RPB11 Position  */
#define PPS_CCLIN0R_CCLIN0_OFF                (PPS_CCLIN0R_CCLIN0_OFF_Val << PPS_CCLIN0R_CCLIN0_Pos) /* (PPS_CCLIN0R) OFF Position  */
#define PPS_CCLIN0R_Msk                       _UINT32_(0x0000000F)                                 /* (PPS_CCLIN0R) Register Mask  */


/* -------- PPS_CCLIN1R : (PPS Offset: 0x9C) (R/W 32)  -------- */
#define PPS_CCLIN1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_CCLIN1R)   Reset Value */

#define PPS_CCLIN1R_CCLIN1_Pos                _UINT32_(0)                                          /* (PPS_CCLIN1R) CCL/IN1 Position */
#define PPS_CCLIN1R_CCLIN1_Msk                (_UINT32_(0xF) << PPS_CCLIN1R_CCLIN1_Pos)            /* (PPS_CCLIN1R) CCL/IN1 Mask */
#define PPS_CCLIN1R_CCLIN1(value)             (PPS_CCLIN1R_CCLIN1_Msk & (_UINT32_(value) << PPS_CCLIN1R_CCLIN1_Pos)) /* Assigment of value for CCLIN1 in the PPS_CCLIN1R register */
#define   PPS_CCLIN1R_CCLIN1_RPA0_Val         _UINT32_(0xF)                                        /* (PPS_CCLIN1R) RPA0  */
#define   PPS_CCLIN1R_CCLIN1_RPA4_Val         _UINT32_(0x1)                                        /* (PPS_CCLIN1R) RPA4  */
#define   PPS_CCLIN1R_CCLIN1_RPA8_Val         _UINT32_(0x2)                                        /* (PPS_CCLIN1R) RPA8  */
#define   PPS_CCLIN1R_CCLIN1_RPA12_Val        _UINT32_(0x3)                                        /* (PPS_CCLIN1R) RPA12  */
#define   PPS_CCLIN1R_CCLIN1_RPB1_Val         _UINT32_(0x4)                                        /* (PPS_CCLIN1R) RPB1  */
#define   PPS_CCLIN1R_CCLIN1_RPB5_Val         _UINT32_(0x5)                                        /* (PPS_CCLIN1R) RPB5  */
#define   PPS_CCLIN1R_CCLIN1_RPB9_Val         _UINT32_(0x6)                                        /* (PPS_CCLIN1R) RPB9  */
#define   PPS_CCLIN1R_CCLIN1_RPB13_Val        _UINT32_(0x7)                                        /* (PPS_CCLIN1R) RPB13  */
#define   PPS_CCLIN1R_CCLIN1_RPA3_Val         _UINT32_(0x8)                                        /* (PPS_CCLIN1R) RPA3  */
#define   PPS_CCLIN1R_CCLIN1_RPA7_Val         _UINT32_(0x9)                                        /* (PPS_CCLIN1R) RPA7  */
#define   PPS_CCLIN1R_CCLIN1_RPA11_Val        _UINT32_(0xA)                                        /* (PPS_CCLIN1R) RPA11  */
#define   PPS_CCLIN1R_CCLIN1_RPB0_Val         _UINT32_(0xB)                                        /* (PPS_CCLIN1R) RPB0  */
#define   PPS_CCLIN1R_CCLIN1_RPB4_Val         _UINT32_(0xC)                                        /* (PPS_CCLIN1R) RPB4  */
#define   PPS_CCLIN1R_CCLIN1_RPB8_Val         _UINT32_(0xD)                                        /* (PPS_CCLIN1R) RPB8  */
#define   PPS_CCLIN1R_CCLIN1_RPB12_Val        _UINT32_(0xE)                                        /* (PPS_CCLIN1R) RPB12  */
#define   PPS_CCLIN1R_CCLIN1_OFF_Val          _UINT32_(0x0)                                        /* (PPS_CCLIN1R) OFF  */
#define PPS_CCLIN1R_CCLIN1_RPA0               (PPS_CCLIN1R_CCLIN1_RPA0_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA0 Position  */
#define PPS_CCLIN1R_CCLIN1_RPA4               (PPS_CCLIN1R_CCLIN1_RPA4_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA4 Position  */
#define PPS_CCLIN1R_CCLIN1_RPA8               (PPS_CCLIN1R_CCLIN1_RPA8_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA8 Position  */
#define PPS_CCLIN1R_CCLIN1_RPA12              (PPS_CCLIN1R_CCLIN1_RPA12_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA12 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB1               (PPS_CCLIN1R_CCLIN1_RPB1_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB1 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB5               (PPS_CCLIN1R_CCLIN1_RPB5_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB5 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB9               (PPS_CCLIN1R_CCLIN1_RPB9_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB9 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB13              (PPS_CCLIN1R_CCLIN1_RPB13_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB13 Position  */
#define PPS_CCLIN1R_CCLIN1_RPA3               (PPS_CCLIN1R_CCLIN1_RPA3_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA3 Position  */
#define PPS_CCLIN1R_CCLIN1_RPA7               (PPS_CCLIN1R_CCLIN1_RPA7_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA7 Position  */
#define PPS_CCLIN1R_CCLIN1_RPA11              (PPS_CCLIN1R_CCLIN1_RPA11_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPA11 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB0               (PPS_CCLIN1R_CCLIN1_RPB0_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB0 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB4               (PPS_CCLIN1R_CCLIN1_RPB4_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB4 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB8               (PPS_CCLIN1R_CCLIN1_RPB8_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB8 Position  */
#define PPS_CCLIN1R_CCLIN1_RPB12              (PPS_CCLIN1R_CCLIN1_RPB12_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) RPB12 Position  */
#define PPS_CCLIN1R_CCLIN1_OFF                (PPS_CCLIN1R_CCLIN1_OFF_Val << PPS_CCLIN1R_CCLIN1_Pos) /* (PPS_CCLIN1R) OFF Position  */
#define PPS_CCLIN1R_Msk                       _UINT32_(0x0000000F)                                 /* (PPS_CCLIN1R) Register Mask  */


/* -------- PPS_CCLIN2R : (PPS Offset: 0xA0) (R/W 32)  -------- */
#define PPS_CCLIN2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_CCLIN2R)   Reset Value */

#define PPS_CCLIN2R_CCLIN2_Pos                _UINT32_(0)                                          /* (PPS_CCLIN2R) CCL/IN2 Position */
#define PPS_CCLIN2R_CCLIN2_Msk                (_UINT32_(0xF) << PPS_CCLIN2R_CCLIN2_Pos)            /* (PPS_CCLIN2R) CCL/IN2 Mask */
#define PPS_CCLIN2R_CCLIN2(value)             (PPS_CCLIN2R_CCLIN2_Msk & (_UINT32_(value) << PPS_CCLIN2R_CCLIN2_Pos)) /* Assigment of value for CCLIN2 in the PPS_CCLIN2R register */
#define   PPS_CCLIN2R_CCLIN2_RPA1_Val         _UINT32_(0xF)                                        /* (PPS_CCLIN2R) RPA1  */
#define   PPS_CCLIN2R_CCLIN2_RPA5_Val         _UINT32_(0x1)                                        /* (PPS_CCLIN2R) RPA5  */
#define   PPS_CCLIN2R_CCLIN2_RPA9_Val         _UINT32_(0x2)                                        /* (PPS_CCLIN2R) RPA9  */
#define   PPS_CCLIN2R_CCLIN2_RPA13_Val        _UINT32_(0x3)                                        /* (PPS_CCLIN2R) RPA13  */
#define   PPS_CCLIN2R_CCLIN2_RPB2_Val         _UINT32_(0x4)                                        /* (PPS_CCLIN2R) RPB2  */
#define   PPS_CCLIN2R_CCLIN2_RPB6_Val         _UINT32_(0x5)                                        /* (PPS_CCLIN2R) RPB6  */
#define   PPS_CCLIN2R_CCLIN2_RPB10_Val        _UINT32_(0x6)                                        /* (PPS_CCLIN2R) RPB10  */
#define   PPS_CCLIN2R_CCLIN2_RPA0_Val         _UINT32_(0x7)                                        /* (PPS_CCLIN2R) RPA0  */
#define   PPS_CCLIN2R_CCLIN2_RPA4_Val         _UINT32_(0x8)                                        /* (PPS_CCLIN2R) RPA4  */
#define   PPS_CCLIN2R_CCLIN2_RPA8_Val         _UINT32_(0x9)                                        /* (PPS_CCLIN2R) RPA8  */
#define   PPS_CCLIN2R_CCLIN2_RPA12_Val        _UINT32_(0xA)                                        /* (PPS_CCLIN2R) RPA12  */
#define   PPS_CCLIN2R_CCLIN2_RPB1_Val         _UINT32_(0xB)                                        /* (PPS_CCLIN2R) RPB1  */
#define   PPS_CCLIN2R_CCLIN2_RPB5_Val         _UINT32_(0xC)                                        /* (PPS_CCLIN2R) RPB5  */
#define   PPS_CCLIN2R_CCLIN2_RPB9_Val         _UINT32_(0xD)                                        /* (PPS_CCLIN2R) RPB9  */
#define   PPS_CCLIN2R_CCLIN2_RPB13_Val        _UINT32_(0xE)                                        /* (PPS_CCLIN2R) RPB13  */
#define   PPS_CCLIN2R_CCLIN2_OFF_Val          _UINT32_(0x0)                                        /* (PPS_CCLIN2R) OFF  */
#define PPS_CCLIN2R_CCLIN2_RPA1               (PPS_CCLIN2R_CCLIN2_RPA1_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA1 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA5               (PPS_CCLIN2R_CCLIN2_RPA5_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA5 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA9               (PPS_CCLIN2R_CCLIN2_RPA9_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA9 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA13              (PPS_CCLIN2R_CCLIN2_RPA13_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA13 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB2               (PPS_CCLIN2R_CCLIN2_RPB2_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB2 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB6               (PPS_CCLIN2R_CCLIN2_RPB6_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB6 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB10              (PPS_CCLIN2R_CCLIN2_RPB10_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB10 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA0               (PPS_CCLIN2R_CCLIN2_RPA0_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA0 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA4               (PPS_CCLIN2R_CCLIN2_RPA4_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA4 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA8               (PPS_CCLIN2R_CCLIN2_RPA8_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA8 Position  */
#define PPS_CCLIN2R_CCLIN2_RPA12              (PPS_CCLIN2R_CCLIN2_RPA12_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPA12 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB1               (PPS_CCLIN2R_CCLIN2_RPB1_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB1 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB5               (PPS_CCLIN2R_CCLIN2_RPB5_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB5 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB9               (PPS_CCLIN2R_CCLIN2_RPB9_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB9 Position  */
#define PPS_CCLIN2R_CCLIN2_RPB13              (PPS_CCLIN2R_CCLIN2_RPB13_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) RPB13 Position  */
#define PPS_CCLIN2R_CCLIN2_OFF                (PPS_CCLIN2R_CCLIN2_OFF_Val << PPS_CCLIN2R_CCLIN2_Pos) /* (PPS_CCLIN2R) OFF Position  */
#define PPS_CCLIN2R_Msk                       _UINT32_(0x0000000F)                                 /* (PPS_CCLIN2R) Register Mask  */


/* -------- PPS_CCLIN3R : (PPS Offset: 0xA4) (R/W 32)  -------- */
#define PPS_CCLIN3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_CCLIN3R)   Reset Value */

#define PPS_CCLIN3R_CCLIN3_Pos                _UINT32_(0)                                          /* (PPS_CCLIN3R) CCL/IN3 Position */
#define PPS_CCLIN3R_CCLIN3_Msk                (_UINT32_(0xF) << PPS_CCLIN3R_CCLIN3_Pos)            /* (PPS_CCLIN3R) CCL/IN3 Mask */
#define PPS_CCLIN3R_CCLIN3(value)             (PPS_CCLIN3R_CCLIN3_Msk & (_UINT32_(value) << PPS_CCLIN3R_CCLIN3_Pos)) /* Assigment of value for CCLIN3 in the PPS_CCLIN3R register */
#define   PPS_CCLIN3R_CCLIN3_RPA9_Val         _UINT32_(0xF)                                        /* (PPS_CCLIN3R) RPA9  */
#define   PPS_CCLIN3R_CCLIN3_RPA3_Val         _UINT32_(0x1)                                        /* (PPS_CCLIN3R) RPA3  */
#define   PPS_CCLIN3R_CCLIN3_RPA7_Val         _UINT32_(0x2)                                        /* (PPS_CCLIN3R) RPA7  */
#define   PPS_CCLIN3R_CCLIN3_RPA11_Val        _UINT32_(0x3)                                        /* (PPS_CCLIN3R) RPA11  */
#define   PPS_CCLIN3R_CCLIN3_RPB0_Val         _UINT32_(0x4)                                        /* (PPS_CCLIN3R) RPB0  */
#define   PPS_CCLIN3R_CCLIN3_RPB4_Val         _UINT32_(0x5)                                        /* (PPS_CCLIN3R) RPB4  */
#define   PPS_CCLIN3R_CCLIN3_RPB8_Val         _UINT32_(0x6)                                        /* (PPS_CCLIN3R) RPB8  */
#define   PPS_CCLIN3R_CCLIN3_RPB12_Val        _UINT32_(0x7)                                        /* (PPS_CCLIN3R) RPB12  */
#define   PPS_CCLIN3R_CCLIN3_RPA2_Val         _UINT32_(0x8)                                        /* (PPS_CCLIN3R) RPA2  */
#define   PPS_CCLIN3R_CCLIN3_RPA6_Val         _UINT32_(0x9)                                        /* (PPS_CCLIN3R) RPA6  */
#define   PPS_CCLIN3R_CCLIN3_RPA10_Val        _UINT32_(0xA)                                        /* (PPS_CCLIN3R) RPA10  */
#define   PPS_CCLIN3R_CCLIN3_RPA14_Val        _UINT32_(0xB)                                        /* (PPS_CCLIN3R) RPA14  */
#define   PPS_CCLIN3R_CCLIN3_RPB3_Val         _UINT32_(0xC)                                        /* (PPS_CCLIN3R) RPB3  */
#define   PPS_CCLIN3R_CCLIN3_RPB7_Val         _UINT32_(0xD)                                        /* (PPS_CCLIN3R) RPB7  */
#define   PPS_CCLIN3R_CCLIN3_RPB11_Val        _UINT32_(0xE)                                        /* (PPS_CCLIN3R) RPB11  */
#define   PPS_CCLIN3R_CCLIN3_OFF_Val          _UINT32_(0x0)                                        /* (PPS_CCLIN3R) OFF  */
#define PPS_CCLIN3R_CCLIN3_RPA9               (PPS_CCLIN3R_CCLIN3_RPA9_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA9 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA3               (PPS_CCLIN3R_CCLIN3_RPA3_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA3 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA7               (PPS_CCLIN3R_CCLIN3_RPA7_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA7 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA11              (PPS_CCLIN3R_CCLIN3_RPA11_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA11 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB0               (PPS_CCLIN3R_CCLIN3_RPB0_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB0 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB4               (PPS_CCLIN3R_CCLIN3_RPB4_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB4 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB8               (PPS_CCLIN3R_CCLIN3_RPB8_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB8 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB12              (PPS_CCLIN3R_CCLIN3_RPB12_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB12 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA2               (PPS_CCLIN3R_CCLIN3_RPA2_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA2 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA6               (PPS_CCLIN3R_CCLIN3_RPA6_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA6 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA10              (PPS_CCLIN3R_CCLIN3_RPA10_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA10 Position  */
#define PPS_CCLIN3R_CCLIN3_RPA14              (PPS_CCLIN3R_CCLIN3_RPA14_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPA14 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB3               (PPS_CCLIN3R_CCLIN3_RPB3_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB3 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB7               (PPS_CCLIN3R_CCLIN3_RPB7_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB7 Position  */
#define PPS_CCLIN3R_CCLIN3_RPB11              (PPS_CCLIN3R_CCLIN3_RPB11_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) RPB11 Position  */
#define PPS_CCLIN3R_CCLIN3_OFF                (PPS_CCLIN3R_CCLIN3_OFF_Val << PPS_CCLIN3R_CCLIN3_Pos) /* (PPS_CCLIN3R) OFF Position  */
#define PPS_CCLIN3R_Msk                       _UINT32_(0x0000000F)                                 /* (PPS_CCLIN3R) Register Mask  */


/* -------- PPS_CCLIN4R : (PPS Offset: 0xA8) (R/W 32)  -------- */
#define PPS_CCLIN4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_CCLIN4R)   Reset Value */

#define PPS_CCLIN4R_CCLIN4_Pos                _UINT32_(0)                                          /* (PPS_CCLIN4R) CCL/IN4 Position */
#define PPS_CCLIN4R_CCLIN4_Msk                (_UINT32_(0xF) << PPS_CCLIN4R_CCLIN4_Pos)            /* (PPS_CCLIN4R) CCL/IN4 Mask */
#define PPS_CCLIN4R_CCLIN4(value)             (PPS_CCLIN4R_CCLIN4_Msk & (_UINT32_(value) << PPS_CCLIN4R_CCLIN4_Pos)) /* Assigment of value for CCLIN4 in the PPS_CCLIN4R register */
#define   PPS_CCLIN4R_CCLIN4_RPA0_Val         _UINT32_(0xF)                                        /* (PPS_CCLIN4R) RPA0  */
#define   PPS_CCLIN4R_CCLIN4_RPA4_Val         _UINT32_(0x1)                                        /* (PPS_CCLIN4R) RPA4  */
#define   PPS_CCLIN4R_CCLIN4_RPA8_Val         _UINT32_(0x2)                                        /* (PPS_CCLIN4R) RPA8  */
#define   PPS_CCLIN4R_CCLIN4_RPA12_Val        _UINT32_(0x3)                                        /* (PPS_CCLIN4R) RPA12  */
#define   PPS_CCLIN4R_CCLIN4_RPB1_Val         _UINT32_(0x4)                                        /* (PPS_CCLIN4R) RPB1  */
#define   PPS_CCLIN4R_CCLIN4_RPB5_Val         _UINT32_(0x5)                                        /* (PPS_CCLIN4R) RPB5  */
#define   PPS_CCLIN4R_CCLIN4_RPB9_Val         _UINT32_(0x6)                                        /* (PPS_CCLIN4R) RPB9  */
#define   PPS_CCLIN4R_CCLIN4_RPB13_Val        _UINT32_(0x7)                                        /* (PPS_CCLIN4R) RPB13  */
#define   PPS_CCLIN4R_CCLIN4_RPA3_Val         _UINT32_(0x8)                                        /* (PPS_CCLIN4R) RPA3  */
#define   PPS_CCLIN4R_CCLIN4_RPA7_Val         _UINT32_(0x9)                                        /* (PPS_CCLIN4R) RPA7  */
#define   PPS_CCLIN4R_CCLIN4_RPA11_Val        _UINT32_(0xA)                                        /* (PPS_CCLIN4R) RPA11  */
#define   PPS_CCLIN4R_CCLIN4_RPB0_Val         _UINT32_(0xB)                                        /* (PPS_CCLIN4R) RPB0  */
#define   PPS_CCLIN4R_CCLIN4_RPB4_Val         _UINT32_(0xC)                                        /* (PPS_CCLIN4R) RPB4  */
#define   PPS_CCLIN4R_CCLIN4_RPB8_Val         _UINT32_(0xD)                                        /* (PPS_CCLIN4R) RPB8  */
#define   PPS_CCLIN4R_CCLIN4_RPB12_Val        _UINT32_(0xE)                                        /* (PPS_CCLIN4R) RPB12  */
#define   PPS_CCLIN4R_CCLIN4_OFF_Val          _UINT32_(0x0)                                        /* (PPS_CCLIN4R) OFF  */
#define PPS_CCLIN4R_CCLIN4_RPA0               (PPS_CCLIN4R_CCLIN4_RPA0_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA0 Position  */
#define PPS_CCLIN4R_CCLIN4_RPA4               (PPS_CCLIN4R_CCLIN4_RPA4_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA4 Position  */
#define PPS_CCLIN4R_CCLIN4_RPA8               (PPS_CCLIN4R_CCLIN4_RPA8_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA8 Position  */
#define PPS_CCLIN4R_CCLIN4_RPA12              (PPS_CCLIN4R_CCLIN4_RPA12_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA12 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB1               (PPS_CCLIN4R_CCLIN4_RPB1_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB1 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB5               (PPS_CCLIN4R_CCLIN4_RPB5_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB5 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB9               (PPS_CCLIN4R_CCLIN4_RPB9_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB9 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB13              (PPS_CCLIN4R_CCLIN4_RPB13_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB13 Position  */
#define PPS_CCLIN4R_CCLIN4_RPA3               (PPS_CCLIN4R_CCLIN4_RPA3_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA3 Position  */
#define PPS_CCLIN4R_CCLIN4_RPA7               (PPS_CCLIN4R_CCLIN4_RPA7_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA7 Position  */
#define PPS_CCLIN4R_CCLIN4_RPA11              (PPS_CCLIN4R_CCLIN4_RPA11_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPA11 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB0               (PPS_CCLIN4R_CCLIN4_RPB0_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB0 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB4               (PPS_CCLIN4R_CCLIN4_RPB4_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB4 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB8               (PPS_CCLIN4R_CCLIN4_RPB8_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB8 Position  */
#define PPS_CCLIN4R_CCLIN4_RPB12              (PPS_CCLIN4R_CCLIN4_RPB12_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) RPB12 Position  */
#define PPS_CCLIN4R_CCLIN4_OFF                (PPS_CCLIN4R_CCLIN4_OFF_Val << PPS_CCLIN4R_CCLIN4_Pos) /* (PPS_CCLIN4R) OFF Position  */
#define PPS_CCLIN4R_Msk                       _UINT32_(0x0000000F)                                 /* (PPS_CCLIN4R) Register Mask  */


/* -------- PPS_CCLIN5R : (PPS Offset: 0xAC) (R/W 32)  -------- */
#define PPS_CCLIN5R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_CCLIN5R)   Reset Value */

#define PPS_CCLIN5R_CCLIN5_Pos                _UINT32_(0)                                          /* (PPS_CCLIN5R) CCL/IN5 Position */
#define PPS_CCLIN5R_CCLIN5_Msk                (_UINT32_(0xF) << PPS_CCLIN5R_CCLIN5_Pos)            /* (PPS_CCLIN5R) CCL/IN5 Mask */
#define PPS_CCLIN5R_CCLIN5(value)             (PPS_CCLIN5R_CCLIN5_Msk & (_UINT32_(value) << PPS_CCLIN5R_CCLIN5_Pos)) /* Assigment of value for CCLIN5 in the PPS_CCLIN5R register */
#define   PPS_CCLIN5R_CCLIN5_RPA1_Val         _UINT32_(0xF)                                        /* (PPS_CCLIN5R) RPA1  */
#define   PPS_CCLIN5R_CCLIN5_RPA5_Val         _UINT32_(0x1)                                        /* (PPS_CCLIN5R) RPA5  */
#define   PPS_CCLIN5R_CCLIN5_RPA9_Val         _UINT32_(0x2)                                        /* (PPS_CCLIN5R) RPA9  */
#define   PPS_CCLIN5R_CCLIN5_RPA13_Val        _UINT32_(0x3)                                        /* (PPS_CCLIN5R) RPA13  */
#define   PPS_CCLIN5R_CCLIN5_RPB2_Val         _UINT32_(0x4)                                        /* (PPS_CCLIN5R) RPB2  */
#define   PPS_CCLIN5R_CCLIN5_RPB6_Val         _UINT32_(0x5)                                        /* (PPS_CCLIN5R) RPB6  */
#define   PPS_CCLIN5R_CCLIN5_RPB10_Val        _UINT32_(0x6)                                        /* (PPS_CCLIN5R) RPB10  */
#define   PPS_CCLIN5R_CCLIN5_RPA0_Val         _UINT32_(0x7)                                        /* (PPS_CCLIN5R) RPA0  */
#define   PPS_CCLIN5R_CCLIN5_RPA4_Val         _UINT32_(0x8)                                        /* (PPS_CCLIN5R) RPA4  */
#define   PPS_CCLIN5R_CCLIN5_RPA8_Val         _UINT32_(0x9)                                        /* (PPS_CCLIN5R) RPA8  */
#define   PPS_CCLIN5R_CCLIN5_RPA12_Val        _UINT32_(0xA)                                        /* (PPS_CCLIN5R) RPA12  */
#define   PPS_CCLIN5R_CCLIN5_RPB1_Val         _UINT32_(0xB)                                        /* (PPS_CCLIN5R) RPB1  */
#define   PPS_CCLIN5R_CCLIN5_RPB5_Val         _UINT32_(0xC)                                        /* (PPS_CCLIN5R) RPB5  */
#define   PPS_CCLIN5R_CCLIN5_RPB9_Val         _UINT32_(0xD)                                        /* (PPS_CCLIN5R) RPB9  */
#define   PPS_CCLIN5R_CCLIN5_RPB13_Val        _UINT32_(0xE)                                        /* (PPS_CCLIN5R) RPB13  */
#define   PPS_CCLIN5R_CCLIN5_OFF_Val          _UINT32_(0x0)                                        /* (PPS_CCLIN5R) OFF  */
#define PPS_CCLIN5R_CCLIN5_RPA1               (PPS_CCLIN5R_CCLIN5_RPA1_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA1 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA5               (PPS_CCLIN5R_CCLIN5_RPA5_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA5 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA9               (PPS_CCLIN5R_CCLIN5_RPA9_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA9 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA13              (PPS_CCLIN5R_CCLIN5_RPA13_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA13 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB2               (PPS_CCLIN5R_CCLIN5_RPB2_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB2 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB6               (PPS_CCLIN5R_CCLIN5_RPB6_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB6 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB10              (PPS_CCLIN5R_CCLIN5_RPB10_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB10 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA0               (PPS_CCLIN5R_CCLIN5_RPA0_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA0 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA4               (PPS_CCLIN5R_CCLIN5_RPA4_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA4 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA8               (PPS_CCLIN5R_CCLIN5_RPA8_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA8 Position  */
#define PPS_CCLIN5R_CCLIN5_RPA12              (PPS_CCLIN5R_CCLIN5_RPA12_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPA12 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB1               (PPS_CCLIN5R_CCLIN5_RPB1_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB1 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB5               (PPS_CCLIN5R_CCLIN5_RPB5_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB5 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB9               (PPS_CCLIN5R_CCLIN5_RPB9_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB9 Position  */
#define PPS_CCLIN5R_CCLIN5_RPB13              (PPS_CCLIN5R_CCLIN5_RPB13_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) RPB13 Position  */
#define PPS_CCLIN5R_CCLIN5_OFF                (PPS_CCLIN5R_CCLIN5_OFF_Val << PPS_CCLIN5R_CCLIN5_Pos) /* (PPS_CCLIN5R) OFF Position  */
#define PPS_CCLIN5R_Msk                       _UINT32_(0x0000000F)                                 /* (PPS_CCLIN5R) Register Mask  */


/* -------- PPS_TC0WO0G1R : (PPS Offset: 0xB0) (R/W 32)  -------- */
#define PPS_TC0WO0G1R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC0WO0G1R)   Reset Value */

#define PPS_TC0WO0G1R_TC0WO0_Pos              _UINT32_(0)                                          /* (PPS_TC0WO0G1R) TC0/WO0G1 Position */
#define PPS_TC0WO0G1R_TC0WO0_Msk              (_UINT32_(0xF) << PPS_TC0WO0G1R_TC0WO0_Pos)          /* (PPS_TC0WO0G1R) TC0/WO0G1 Mask */
#define PPS_TC0WO0G1R_TC0WO0(value)           (PPS_TC0WO0G1R_TC0WO0_Msk & (_UINT32_(value) << PPS_TC0WO0G1R_TC0WO0_Pos)) /* Assigment of value for TC0WO0 in the PPS_TC0WO0G1R register */
#define   PPS_TC0WO0G1R_TC0WO0_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_TC0WO0G1R) RPA9  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_TC0WO0G1R) RPA3  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_TC0WO0G1R) RPA7  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_TC0WO0G1R) RPA11  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_TC0WO0G1R) RPB0  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_TC0WO0G1R) RPB4  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_TC0WO0G1R) RPB8  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_TC0WO0G1R) RPB12  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_TC0WO0G1R) RPA2  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_TC0WO0G1R) RPA6  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_TC0WO0G1R) RPA10  */
#define   PPS_TC0WO0G1R_TC0WO0_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_TC0WO0G1R) RPA14  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_TC0WO0G1R) RPB3  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_TC0WO0G1R) RPB7  */
#define   PPS_TC0WO0G1R_TC0WO0_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_TC0WO0G1R) RPB11  */
#define   PPS_TC0WO0G1R_TC0WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC0WO0G1R) OFF  */
#define PPS_TC0WO0G1R_TC0WO0_RPA9             (PPS_TC0WO0G1R_TC0WO0_RPA9_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA9 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA3             (PPS_TC0WO0G1R_TC0WO0_RPA3_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA3 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA7             (PPS_TC0WO0G1R_TC0WO0_RPA7_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA7 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA11            (PPS_TC0WO0G1R_TC0WO0_RPA11_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA11 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB0             (PPS_TC0WO0G1R_TC0WO0_RPB0_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB0 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB4             (PPS_TC0WO0G1R_TC0WO0_RPB4_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB4 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB8             (PPS_TC0WO0G1R_TC0WO0_RPB8_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB8 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB12            (PPS_TC0WO0G1R_TC0WO0_RPB12_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB12 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA2             (PPS_TC0WO0G1R_TC0WO0_RPA2_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA2 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA6             (PPS_TC0WO0G1R_TC0WO0_RPA6_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA6 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA10            (PPS_TC0WO0G1R_TC0WO0_RPA10_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA10 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPA14            (PPS_TC0WO0G1R_TC0WO0_RPA14_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPA14 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB3             (PPS_TC0WO0G1R_TC0WO0_RPB3_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB3 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB7             (PPS_TC0WO0G1R_TC0WO0_RPB7_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB7 Position  */
#define PPS_TC0WO0G1R_TC0WO0_RPB11            (PPS_TC0WO0G1R_TC0WO0_RPB11_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) RPB11 Position  */
#define PPS_TC0WO0G1R_TC0WO0_OFF              (PPS_TC0WO0G1R_TC0WO0_OFF_Val << PPS_TC0WO0G1R_TC0WO0_Pos) /* (PPS_TC0WO0G1R) OFF Position  */
#define PPS_TC0WO0G1R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC0WO0G1R) Register Mask  */


/* -------- PPS_TC0WO0G2R : (PPS Offset: 0xB4) (R/W 32)  -------- */
#define PPS_TC0WO0G2R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC0WO0G2R)   Reset Value */

#define PPS_TC0WO0G2R_TC0WO0_Pos              _UINT32_(0)                                          /* (PPS_TC0WO0G2R) TC0/WO0G2 Position */
#define PPS_TC0WO0G2R_TC0WO0_Msk              (_UINT32_(0xF) << PPS_TC0WO0G2R_TC0WO0_Pos)          /* (PPS_TC0WO0G2R) TC0/WO0G2 Mask */
#define PPS_TC0WO0G2R_TC0WO0(value)           (PPS_TC0WO0G2R_TC0WO0_Msk & (_UINT32_(value) << PPS_TC0WO0G2R_TC0WO0_Pos)) /* Assigment of value for TC0WO0 in the PPS_TC0WO0G2R register */
#define   PPS_TC0WO0G2R_TC0WO0_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_TC0WO0G2R) RPA0  */
#define   PPS_TC0WO0G2R_TC0WO0_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_TC0WO0G2R) RPA4  */
#define   PPS_TC0WO0G2R_TC0WO0_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_TC0WO0G2R) RPA8  */
#define   PPS_TC0WO0G2R_TC0WO0_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_TC0WO0G2R) RPA12  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_TC0WO0G2R) RPB1  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_TC0WO0G2R) RPB5  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_TC0WO0G2R) RPB9  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_TC0WO0G2R) RPB13  */
#define   PPS_TC0WO0G2R_TC0WO0_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_TC0WO0G2R) RPA3  */
#define   PPS_TC0WO0G2R_TC0WO0_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_TC0WO0G2R) RPA7  */
#define   PPS_TC0WO0G2R_TC0WO0_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_TC0WO0G2R) RPA11  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_TC0WO0G2R) RPB0  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_TC0WO0G2R) RPB4  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_TC0WO0G2R) RPB8  */
#define   PPS_TC0WO0G2R_TC0WO0_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_TC0WO0G2R) RPB12  */
#define   PPS_TC0WO0G2R_TC0WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC0WO0G2R) OFF  */
#define PPS_TC0WO0G2R_TC0WO0_RPA0             (PPS_TC0WO0G2R_TC0WO0_RPA0_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA0 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPA4             (PPS_TC0WO0G2R_TC0WO0_RPA4_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA4 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPA8             (PPS_TC0WO0G2R_TC0WO0_RPA8_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA8 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPA12            (PPS_TC0WO0G2R_TC0WO0_RPA12_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA12 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB1             (PPS_TC0WO0G2R_TC0WO0_RPB1_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB1 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB5             (PPS_TC0WO0G2R_TC0WO0_RPB5_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB5 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB9             (PPS_TC0WO0G2R_TC0WO0_RPB9_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB9 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB13            (PPS_TC0WO0G2R_TC0WO0_RPB13_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB13 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPA3             (PPS_TC0WO0G2R_TC0WO0_RPA3_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA3 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPA7             (PPS_TC0WO0G2R_TC0WO0_RPA7_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA7 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPA11            (PPS_TC0WO0G2R_TC0WO0_RPA11_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPA11 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB0             (PPS_TC0WO0G2R_TC0WO0_RPB0_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB0 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB4             (PPS_TC0WO0G2R_TC0WO0_RPB4_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB4 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB8             (PPS_TC0WO0G2R_TC0WO0_RPB8_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB8 Position  */
#define PPS_TC0WO0G2R_TC0WO0_RPB12            (PPS_TC0WO0G2R_TC0WO0_RPB12_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) RPB12 Position  */
#define PPS_TC0WO0G2R_TC0WO0_OFF              (PPS_TC0WO0G2R_TC0WO0_OFF_Val << PPS_TC0WO0G2R_TC0WO0_Pos) /* (PPS_TC0WO0G2R) OFF Position  */
#define PPS_TC0WO0G2R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC0WO0G2R) Register Mask  */


/* -------- PPS_TC0WO1G3R : (PPS Offset: 0xB8) (R/W 32)  -------- */
#define PPS_TC0WO1G3R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC0WO1G3R)   Reset Value */

#define PPS_TC0WO1G3R_TC0WO1_Pos              _UINT32_(0)                                          /* (PPS_TC0WO1G3R) TC0/WO1G3 Position */
#define PPS_TC0WO1G3R_TC0WO1_Msk              (_UINT32_(0xF) << PPS_TC0WO1G3R_TC0WO1_Pos)          /* (PPS_TC0WO1G3R) TC0/WO1G3 Mask */
#define PPS_TC0WO1G3R_TC0WO1(value)           (PPS_TC0WO1G3R_TC0WO1_Msk & (_UINT32_(value) << PPS_TC0WO1G3R_TC0WO1_Pos)) /* Assigment of value for TC0WO1 in the PPS_TC0WO1G3R register */
#define   PPS_TC0WO1G3R_TC0WO1_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_TC0WO1G3R) RPA1  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_TC0WO1G3R) RPA5  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_TC0WO1G3R) RPA9  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_TC0WO1G3R) RPA13  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_TC0WO1G3R) RPB2  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_TC0WO1G3R) RPB6  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_TC0WO1G3R) RPB10  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_TC0WO1G3R) RPA0  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_TC0WO1G3R) RPA4  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_TC0WO1G3R) RPA8  */
#define   PPS_TC0WO1G3R_TC0WO1_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_TC0WO1G3R) RPA12  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_TC0WO1G3R) RPB1  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_TC0WO1G3R) RPB5  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_TC0WO1G3R) RPB9  */
#define   PPS_TC0WO1G3R_TC0WO1_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_TC0WO1G3R) RPB13  */
#define   PPS_TC0WO1G3R_TC0WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC0WO1G3R) OFF  */
#define PPS_TC0WO1G3R_TC0WO1_RPA1             (PPS_TC0WO1G3R_TC0WO1_RPA1_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA1 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA5             (PPS_TC0WO1G3R_TC0WO1_RPA5_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA5 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA9             (PPS_TC0WO1G3R_TC0WO1_RPA9_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA9 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA13            (PPS_TC0WO1G3R_TC0WO1_RPA13_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA13 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB2             (PPS_TC0WO1G3R_TC0WO1_RPB2_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB2 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB6             (PPS_TC0WO1G3R_TC0WO1_RPB6_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB6 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB10            (PPS_TC0WO1G3R_TC0WO1_RPB10_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB10 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA0             (PPS_TC0WO1G3R_TC0WO1_RPA0_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA0 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA4             (PPS_TC0WO1G3R_TC0WO1_RPA4_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA4 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA8             (PPS_TC0WO1G3R_TC0WO1_RPA8_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA8 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPA12            (PPS_TC0WO1G3R_TC0WO1_RPA12_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPA12 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB1             (PPS_TC0WO1G3R_TC0WO1_RPB1_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB1 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB5             (PPS_TC0WO1G3R_TC0WO1_RPB5_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB5 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB9             (PPS_TC0WO1G3R_TC0WO1_RPB9_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB9 Position  */
#define PPS_TC0WO1G3R_TC0WO1_RPB13            (PPS_TC0WO1G3R_TC0WO1_RPB13_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) RPB13 Position  */
#define PPS_TC0WO1G3R_TC0WO1_OFF              (PPS_TC0WO1G3R_TC0WO1_OFF_Val << PPS_TC0WO1G3R_TC0WO1_Pos) /* (PPS_TC0WO1G3R) OFF Position  */
#define PPS_TC0WO1G3R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC0WO1G3R) Register Mask  */


/* -------- PPS_TC0WO1G4R : (PPS Offset: 0xBC) (R/W 32)  -------- */
#define PPS_TC0WO1G4R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC0WO1G4R)   Reset Value */

#define PPS_TC0WO1G4R_TC0WO1_Pos              _UINT32_(0)                                          /* (PPS_TC0WO1G4R) TC0/WO1G4 Position */
#define PPS_TC0WO1G4R_TC0WO1_Msk              (_UINT32_(0xF) << PPS_TC0WO1G4R_TC0WO1_Pos)          /* (PPS_TC0WO1G4R) TC0/WO1G4 Mask */
#define PPS_TC0WO1G4R_TC0WO1(value)           (PPS_TC0WO1G4R_TC0WO1_Msk & (_UINT32_(value) << PPS_TC0WO1G4R_TC0WO1_Pos)) /* Assigment of value for TC0WO1 in the PPS_TC0WO1G4R register */
#define   PPS_TC0WO1G4R_TC0WO1_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_TC0WO1G4R) RPA2  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_TC0WO1G4R) RPA6  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_TC0WO1G4R) RPA10  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_TC0WO1G4R) RPA14  */
#define   PPS_TC0WO1G4R_TC0WO1_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_TC0WO1G4R) RPB3  */
#define   PPS_TC0WO1G4R_TC0WO1_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_TC0WO1G4R) RPB7  */
#define   PPS_TC0WO1G4R_TC0WO1_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_TC0WO1G4R) RPB11  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_TC0WO1G4R) RPA1  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_TC0WO1G4R) RPA5  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_TC0WO1G4R) RPA9  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_TC0WO1G4R) RPA13  */
#define   PPS_TC0WO1G4R_TC0WO1_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_TC0WO1G4R) RPB2  */
#define   PPS_TC0WO1G4R_TC0WO1_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_TC0WO1G4R) RPB6  */
#define   PPS_TC0WO1G4R_TC0WO1_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_TC0WO1G4R) RPB10  */
#define   PPS_TC0WO1G4R_TC0WO1_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_TC0WO1G4R) RPA8  */
#define   PPS_TC0WO1G4R_TC0WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC0WO1G4R) OFF  */
#define PPS_TC0WO1G4R_TC0WO1_RPA2             (PPS_TC0WO1G4R_TC0WO1_RPA2_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA2 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA6             (PPS_TC0WO1G4R_TC0WO1_RPA6_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA6 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA10            (PPS_TC0WO1G4R_TC0WO1_RPA10_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA10 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA14            (PPS_TC0WO1G4R_TC0WO1_RPA14_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA14 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPB3             (PPS_TC0WO1G4R_TC0WO1_RPB3_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPB3 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPB7             (PPS_TC0WO1G4R_TC0WO1_RPB7_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPB7 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPB11            (PPS_TC0WO1G4R_TC0WO1_RPB11_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPB11 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA1             (PPS_TC0WO1G4R_TC0WO1_RPA1_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA1 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA5             (PPS_TC0WO1G4R_TC0WO1_RPA5_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA5 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA9             (PPS_TC0WO1G4R_TC0WO1_RPA9_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA9 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA13            (PPS_TC0WO1G4R_TC0WO1_RPA13_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA13 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPB2             (PPS_TC0WO1G4R_TC0WO1_RPB2_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPB2 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPB6             (PPS_TC0WO1G4R_TC0WO1_RPB6_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPB6 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPB10            (PPS_TC0WO1G4R_TC0WO1_RPB10_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPB10 Position  */
#define PPS_TC0WO1G4R_TC0WO1_RPA8             (PPS_TC0WO1G4R_TC0WO1_RPA8_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) RPA8 Position  */
#define PPS_TC0WO1G4R_TC0WO1_OFF              (PPS_TC0WO1G4R_TC0WO1_OFF_Val << PPS_TC0WO1G4R_TC0WO1_Pos) /* (PPS_TC0WO1G4R) OFF Position  */
#define PPS_TC0WO1G4R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC0WO1G4R) Register Mask  */


/* -------- PPS_TC1WO0G1R : (PPS Offset: 0xC0) (R/W 32)  -------- */
#define PPS_TC1WO0G1R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC1WO0G1R)   Reset Value */

#define PPS_TC1WO0G1R_TC1WO0_Pos              _UINT32_(0)                                          /* (PPS_TC1WO0G1R) TC1/WO0G1 Position */
#define PPS_TC1WO0G1R_TC1WO0_Msk              (_UINT32_(0xF) << PPS_TC1WO0G1R_TC1WO0_Pos)          /* (PPS_TC1WO0G1R) TC1/WO0G1 Mask */
#define PPS_TC1WO0G1R_TC1WO0(value)           (PPS_TC1WO0G1R_TC1WO0_Msk & (_UINT32_(value) << PPS_TC1WO0G1R_TC1WO0_Pos)) /* Assigment of value for TC1WO0 in the PPS_TC1WO0G1R register */
#define   PPS_TC1WO0G1R_TC1WO0_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_TC1WO0G1R) RPA9  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_TC1WO0G1R) RPA3  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_TC1WO0G1R) RPA7  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_TC1WO0G1R) RPA11  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_TC1WO0G1R) RPB0  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_TC1WO0G1R) RPB4  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_TC1WO0G1R) RPB8  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_TC1WO0G1R) RPB12  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_TC1WO0G1R) RPA2  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_TC1WO0G1R) RPA6  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_TC1WO0G1R) RPA10  */
#define   PPS_TC1WO0G1R_TC1WO0_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_TC1WO0G1R) RPA14  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_TC1WO0G1R) RPB3  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_TC1WO0G1R) RPB7  */
#define   PPS_TC1WO0G1R_TC1WO0_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_TC1WO0G1R) RPB11  */
#define   PPS_TC1WO0G1R_TC1WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC1WO0G1R) OFF  */
#define PPS_TC1WO0G1R_TC1WO0_RPA9             (PPS_TC1WO0G1R_TC1WO0_RPA9_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA9 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA3             (PPS_TC1WO0G1R_TC1WO0_RPA3_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA3 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA7             (PPS_TC1WO0G1R_TC1WO0_RPA7_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA7 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA11            (PPS_TC1WO0G1R_TC1WO0_RPA11_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA11 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB0             (PPS_TC1WO0G1R_TC1WO0_RPB0_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB0 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB4             (PPS_TC1WO0G1R_TC1WO0_RPB4_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB4 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB8             (PPS_TC1WO0G1R_TC1WO0_RPB8_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB8 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB12            (PPS_TC1WO0G1R_TC1WO0_RPB12_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB12 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA2             (PPS_TC1WO0G1R_TC1WO0_RPA2_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA2 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA6             (PPS_TC1WO0G1R_TC1WO0_RPA6_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA6 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA10            (PPS_TC1WO0G1R_TC1WO0_RPA10_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA10 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPA14            (PPS_TC1WO0G1R_TC1WO0_RPA14_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPA14 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB3             (PPS_TC1WO0G1R_TC1WO0_RPB3_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB3 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB7             (PPS_TC1WO0G1R_TC1WO0_RPB7_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB7 Position  */
#define PPS_TC1WO0G1R_TC1WO0_RPB11            (PPS_TC1WO0G1R_TC1WO0_RPB11_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) RPB11 Position  */
#define PPS_TC1WO0G1R_TC1WO0_OFF              (PPS_TC1WO0G1R_TC1WO0_OFF_Val << PPS_TC1WO0G1R_TC1WO0_Pos) /* (PPS_TC1WO0G1R) OFF Position  */
#define PPS_TC1WO0G1R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC1WO0G1R) Register Mask  */


/* -------- PPS_TC1WO1G2R : (PPS Offset: 0xC4) (R/W 32)  -------- */
#define PPS_TC1WO1G2R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC1WO1G2R)   Reset Value */

#define PPS_TC1WO1G2R_TC1WO1_Pos              _UINT32_(0)                                          /* (PPS_TC1WO1G2R) TC1/WO1G2 Position */
#define PPS_TC1WO1G2R_TC1WO1_Msk              (_UINT32_(0xF) << PPS_TC1WO1G2R_TC1WO1_Pos)          /* (PPS_TC1WO1G2R) TC1/WO1G2 Mask */
#define PPS_TC1WO1G2R_TC1WO1(value)           (PPS_TC1WO1G2R_TC1WO1_Msk & (_UINT32_(value) << PPS_TC1WO1G2R_TC1WO1_Pos)) /* Assigment of value for TC1WO1 in the PPS_TC1WO1G2R register */
#define   PPS_TC1WO1G2R_TC1WO1_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_TC1WO1G2R) RPA0  */
#define   PPS_TC1WO1G2R_TC1WO1_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_TC1WO1G2R) RPA4  */
#define   PPS_TC1WO1G2R_TC1WO1_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_TC1WO1G2R) RPA8  */
#define   PPS_TC1WO1G2R_TC1WO1_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_TC1WO1G2R) RPA12  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_TC1WO1G2R) RPB1  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_TC1WO1G2R) RPB5  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_TC1WO1G2R) RPB9  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_TC1WO1G2R) RPB13  */
#define   PPS_TC1WO1G2R_TC1WO1_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_TC1WO1G2R) RPA3  */
#define   PPS_TC1WO1G2R_TC1WO1_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_TC1WO1G2R) RPA7  */
#define   PPS_TC1WO1G2R_TC1WO1_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_TC1WO1G2R) RPA11  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_TC1WO1G2R) RPB0  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_TC1WO1G2R) RPB4  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_TC1WO1G2R) RPB8  */
#define   PPS_TC1WO1G2R_TC1WO1_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_TC1WO1G2R) RPB12  */
#define   PPS_TC1WO1G2R_TC1WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC1WO1G2R) OFF  */
#define PPS_TC1WO1G2R_TC1WO1_RPA0             (PPS_TC1WO1G2R_TC1WO1_RPA0_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA0 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPA4             (PPS_TC1WO1G2R_TC1WO1_RPA4_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA4 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPA8             (PPS_TC1WO1G2R_TC1WO1_RPA8_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA8 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPA12            (PPS_TC1WO1G2R_TC1WO1_RPA12_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA12 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB1             (PPS_TC1WO1G2R_TC1WO1_RPB1_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB1 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB5             (PPS_TC1WO1G2R_TC1WO1_RPB5_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB5 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB9             (PPS_TC1WO1G2R_TC1WO1_RPB9_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB9 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB13            (PPS_TC1WO1G2R_TC1WO1_RPB13_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB13 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPA3             (PPS_TC1WO1G2R_TC1WO1_RPA3_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA3 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPA7             (PPS_TC1WO1G2R_TC1WO1_RPA7_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA7 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPA11            (PPS_TC1WO1G2R_TC1WO1_RPA11_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPA11 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB0             (PPS_TC1WO1G2R_TC1WO1_RPB0_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB0 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB4             (PPS_TC1WO1G2R_TC1WO1_RPB4_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB4 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB8             (PPS_TC1WO1G2R_TC1WO1_RPB8_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB8 Position  */
#define PPS_TC1WO1G2R_TC1WO1_RPB12            (PPS_TC1WO1G2R_TC1WO1_RPB12_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) RPB12 Position  */
#define PPS_TC1WO1G2R_TC1WO1_OFF              (PPS_TC1WO1G2R_TC1WO1_OFF_Val << PPS_TC1WO1G2R_TC1WO1_Pos) /* (PPS_TC1WO1G2R) OFF Position  */
#define PPS_TC1WO1G2R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC1WO1G2R) Register Mask  */


/* -------- PPS_TC2WO0G1R : (PPS Offset: 0xC8) (R/W 32)  -------- */
#define PPS_TC2WO0G1R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC2WO0G1R)   Reset Value */

#define PPS_TC2WO0G1R_TC2WO0_Pos              _UINT32_(0)                                          /* (PPS_TC2WO0G1R) TC2/WO0G1 Position */
#define PPS_TC2WO0G1R_TC2WO0_Msk              (_UINT32_(0xF) << PPS_TC2WO0G1R_TC2WO0_Pos)          /* (PPS_TC2WO0G1R) TC2/WO0G1 Mask */
#define PPS_TC2WO0G1R_TC2WO0(value)           (PPS_TC2WO0G1R_TC2WO0_Msk & (_UINT32_(value) << PPS_TC2WO0G1R_TC2WO0_Pos)) /* Assigment of value for TC2WO0 in the PPS_TC2WO0G1R register */
#define   PPS_TC2WO0G1R_TC2WO0_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_TC2WO0G1R) RPA9  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_TC2WO0G1R) RPA3  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_TC2WO0G1R) RPA7  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_TC2WO0G1R) RPA11  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_TC2WO0G1R) RPB0  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_TC2WO0G1R) RPB4  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_TC2WO0G1R) RPB8  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_TC2WO0G1R) RPB12  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_TC2WO0G1R) RPA2  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_TC2WO0G1R) RPA6  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_TC2WO0G1R) RPA10  */
#define   PPS_TC2WO0G1R_TC2WO0_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_TC2WO0G1R) RPA14  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_TC2WO0G1R) RPB3  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_TC2WO0G1R) RPB7  */
#define   PPS_TC2WO0G1R_TC2WO0_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_TC2WO0G1R) RPB11  */
#define   PPS_TC2WO0G1R_TC2WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC2WO0G1R) OFF  */
#define PPS_TC2WO0G1R_TC2WO0_RPA9             (PPS_TC2WO0G1R_TC2WO0_RPA9_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA9 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA3             (PPS_TC2WO0G1R_TC2WO0_RPA3_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA3 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA7             (PPS_TC2WO0G1R_TC2WO0_RPA7_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA7 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA11            (PPS_TC2WO0G1R_TC2WO0_RPA11_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA11 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB0             (PPS_TC2WO0G1R_TC2WO0_RPB0_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB0 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB4             (PPS_TC2WO0G1R_TC2WO0_RPB4_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB4 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB8             (PPS_TC2WO0G1R_TC2WO0_RPB8_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB8 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB12            (PPS_TC2WO0G1R_TC2WO0_RPB12_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB12 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA2             (PPS_TC2WO0G1R_TC2WO0_RPA2_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA2 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA6             (PPS_TC2WO0G1R_TC2WO0_RPA6_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA6 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA10            (PPS_TC2WO0G1R_TC2WO0_RPA10_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA10 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPA14            (PPS_TC2WO0G1R_TC2WO0_RPA14_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPA14 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB3             (PPS_TC2WO0G1R_TC2WO0_RPB3_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB3 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB7             (PPS_TC2WO0G1R_TC2WO0_RPB7_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB7 Position  */
#define PPS_TC2WO0G1R_TC2WO0_RPB11            (PPS_TC2WO0G1R_TC2WO0_RPB11_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) RPB11 Position  */
#define PPS_TC2WO0G1R_TC2WO0_OFF              (PPS_TC2WO0G1R_TC2WO0_OFF_Val << PPS_TC2WO0G1R_TC2WO0_Pos) /* (PPS_TC2WO0G1R) OFF Position  */
#define PPS_TC2WO0G1R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC2WO0G1R) Register Mask  */


/* -------- PPS_TC2WO0G3R : (PPS Offset: 0xCC) (R/W 32)  -------- */
#define PPS_TC2WO0G3R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC2WO0G3R)   Reset Value */

#define PPS_TC2WO0G3R_TC2WO0_Pos              _UINT32_(0)                                          /* (PPS_TC2WO0G3R) TC2/WO0G3 Position */
#define PPS_TC2WO0G3R_TC2WO0_Msk              (_UINT32_(0xF) << PPS_TC2WO0G3R_TC2WO0_Pos)          /* (PPS_TC2WO0G3R) TC2/WO0G3 Mask */
#define PPS_TC2WO0G3R_TC2WO0(value)           (PPS_TC2WO0G3R_TC2WO0_Msk & (_UINT32_(value) << PPS_TC2WO0G3R_TC2WO0_Pos)) /* Assigment of value for TC2WO0 in the PPS_TC2WO0G3R register */
#define   PPS_TC2WO0G3R_TC2WO0_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_TC2WO0G3R) RPA1  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_TC2WO0G3R) RPA5  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_TC2WO0G3R) RPA9  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_TC2WO0G3R) RPA13  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_TC2WO0G3R) RPB2  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_TC2WO0G3R) RPB6  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_TC2WO0G3R) RPB10  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_TC2WO0G3R) RPA0  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_TC2WO0G3R) RPA4  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_TC2WO0G3R) RPA8  */
#define   PPS_TC2WO0G3R_TC2WO0_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_TC2WO0G3R) RPA12  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_TC2WO0G3R) RPB1  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_TC2WO0G3R) RPB5  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_TC2WO0G3R) RPB9  */
#define   PPS_TC2WO0G3R_TC2WO0_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_TC2WO0G3R) RPB13  */
#define   PPS_TC2WO0G3R_TC2WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC2WO0G3R) OFF  */
#define PPS_TC2WO0G3R_TC2WO0_RPA1             (PPS_TC2WO0G3R_TC2WO0_RPA1_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA1 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA5             (PPS_TC2WO0G3R_TC2WO0_RPA5_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA5 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA9             (PPS_TC2WO0G3R_TC2WO0_RPA9_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA9 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA13            (PPS_TC2WO0G3R_TC2WO0_RPA13_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA13 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB2             (PPS_TC2WO0G3R_TC2WO0_RPB2_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB2 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB6             (PPS_TC2WO0G3R_TC2WO0_RPB6_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB6 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB10            (PPS_TC2WO0G3R_TC2WO0_RPB10_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB10 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA0             (PPS_TC2WO0G3R_TC2WO0_RPA0_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA0 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA4             (PPS_TC2WO0G3R_TC2WO0_RPA4_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA4 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA8             (PPS_TC2WO0G3R_TC2WO0_RPA8_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA8 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPA12            (PPS_TC2WO0G3R_TC2WO0_RPA12_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPA12 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB1             (PPS_TC2WO0G3R_TC2WO0_RPB1_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB1 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB5             (PPS_TC2WO0G3R_TC2WO0_RPB5_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB5 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB9             (PPS_TC2WO0G3R_TC2WO0_RPB9_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB9 Position  */
#define PPS_TC2WO0G3R_TC2WO0_RPB13            (PPS_TC2WO0G3R_TC2WO0_RPB13_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) RPB13 Position  */
#define PPS_TC2WO0G3R_TC2WO0_OFF              (PPS_TC2WO0G3R_TC2WO0_OFF_Val << PPS_TC2WO0G3R_TC2WO0_Pos) /* (PPS_TC2WO0G3R) OFF Position  */
#define PPS_TC2WO0G3R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC2WO0G3R) Register Mask  */


/* -------- PPS_TC2WO1G2R : (PPS Offset: 0xD0) (R/W 32)  -------- */
#define PPS_TC2WO1G2R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC2WO1G2R)   Reset Value */

#define PPS_TC2WO1G2R_TC2WO1_Pos              _UINT32_(0)                                          /* (PPS_TC2WO1G2R) TC2/WO1G2 Position */
#define PPS_TC2WO1G2R_TC2WO1_Msk              (_UINT32_(0xF) << PPS_TC2WO1G2R_TC2WO1_Pos)          /* (PPS_TC2WO1G2R) TC2/WO1G2 Mask */
#define PPS_TC2WO1G2R_TC2WO1(value)           (PPS_TC2WO1G2R_TC2WO1_Msk & (_UINT32_(value) << PPS_TC2WO1G2R_TC2WO1_Pos)) /* Assigment of value for TC2WO1 in the PPS_TC2WO1G2R register */
#define   PPS_TC2WO1G2R_TC2WO1_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_TC2WO1G2R) RPA0  */
#define   PPS_TC2WO1G2R_TC2WO1_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_TC2WO1G2R) RPA4  */
#define   PPS_TC2WO1G2R_TC2WO1_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_TC2WO1G2R) RPA8  */
#define   PPS_TC2WO1G2R_TC2WO1_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_TC2WO1G2R) RPA12  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_TC2WO1G2R) RPB1  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_TC2WO1G2R) RPB5  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_TC2WO1G2R) RPB9  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_TC2WO1G2R) RPB13  */
#define   PPS_TC2WO1G2R_TC2WO1_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_TC2WO1G2R) RPA3  */
#define   PPS_TC2WO1G2R_TC2WO1_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_TC2WO1G2R) RPA7  */
#define   PPS_TC2WO1G2R_TC2WO1_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_TC2WO1G2R) RPA11  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_TC2WO1G2R) RPB0  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_TC2WO1G2R) RPB4  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_TC2WO1G2R) RPB8  */
#define   PPS_TC2WO1G2R_TC2WO1_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_TC2WO1G2R) RPB12  */
#define   PPS_TC2WO1G2R_TC2WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC2WO1G2R) OFF  */
#define PPS_TC2WO1G2R_TC2WO1_RPA0             (PPS_TC2WO1G2R_TC2WO1_RPA0_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA0 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPA4             (PPS_TC2WO1G2R_TC2WO1_RPA4_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA4 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPA8             (PPS_TC2WO1G2R_TC2WO1_RPA8_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA8 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPA12            (PPS_TC2WO1G2R_TC2WO1_RPA12_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA12 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB1             (PPS_TC2WO1G2R_TC2WO1_RPB1_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB1 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB5             (PPS_TC2WO1G2R_TC2WO1_RPB5_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB5 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB9             (PPS_TC2WO1G2R_TC2WO1_RPB9_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB9 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB13            (PPS_TC2WO1G2R_TC2WO1_RPB13_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB13 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPA3             (PPS_TC2WO1G2R_TC2WO1_RPA3_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA3 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPA7             (PPS_TC2WO1G2R_TC2WO1_RPA7_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA7 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPA11            (PPS_TC2WO1G2R_TC2WO1_RPA11_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPA11 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB0             (PPS_TC2WO1G2R_TC2WO1_RPB0_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB0 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB4             (PPS_TC2WO1G2R_TC2WO1_RPB4_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB4 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB8             (PPS_TC2WO1G2R_TC2WO1_RPB8_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB8 Position  */
#define PPS_TC2WO1G2R_TC2WO1_RPB12            (PPS_TC2WO1G2R_TC2WO1_RPB12_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) RPB12 Position  */
#define PPS_TC2WO1G2R_TC2WO1_OFF              (PPS_TC2WO1G2R_TC2WO1_OFF_Val << PPS_TC2WO1G2R_TC2WO1_Pos) /* (PPS_TC2WO1G2R) OFF Position  */
#define PPS_TC2WO1G2R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC2WO1G2R) Register Mask  */


/* -------- PPS_TC2WO1G4R : (PPS Offset: 0xD4) (R/W 32)  -------- */
#define PPS_TC2WO1G4R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC2WO1G4R)   Reset Value */

#define PPS_TC2WO1G4R_TC2WO1_Pos              _UINT32_(0)                                          /* (PPS_TC2WO1G4R) TC2/WO1G4 Position */
#define PPS_TC2WO1G4R_TC2WO1_Msk              (_UINT32_(0xF) << PPS_TC2WO1G4R_TC2WO1_Pos)          /* (PPS_TC2WO1G4R) TC2/WO1G4 Mask */
#define PPS_TC2WO1G4R_TC2WO1(value)           (PPS_TC2WO1G4R_TC2WO1_Msk & (_UINT32_(value) << PPS_TC2WO1G4R_TC2WO1_Pos)) /* Assigment of value for TC2WO1 in the PPS_TC2WO1G4R register */
#define   PPS_TC2WO1G4R_TC2WO1_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_TC2WO1G4R) RPA2  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_TC2WO1G4R) RPA6  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_TC2WO1G4R) RPA10  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_TC2WO1G4R) RPA14  */
#define   PPS_TC2WO1G4R_TC2WO1_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_TC2WO1G4R) RPB3  */
#define   PPS_TC2WO1G4R_TC2WO1_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_TC2WO1G4R) RPB7  */
#define   PPS_TC2WO1G4R_TC2WO1_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_TC2WO1G4R) RPB11  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_TC2WO1G4R) RPA1  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_TC2WO1G4R) RPA5  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_TC2WO1G4R) RPA9  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_TC2WO1G4R) RPA13  */
#define   PPS_TC2WO1G4R_TC2WO1_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_TC2WO1G4R) RPB2  */
#define   PPS_TC2WO1G4R_TC2WO1_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_TC2WO1G4R) RPB6  */
#define   PPS_TC2WO1G4R_TC2WO1_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_TC2WO1G4R) RPB10  */
#define   PPS_TC2WO1G4R_TC2WO1_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_TC2WO1G4R) RPA8  */
#define   PPS_TC2WO1G4R_TC2WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC2WO1G4R) OFF  */
#define PPS_TC2WO1G4R_TC2WO1_RPA2             (PPS_TC2WO1G4R_TC2WO1_RPA2_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA2 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA6             (PPS_TC2WO1G4R_TC2WO1_RPA6_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA6 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA10            (PPS_TC2WO1G4R_TC2WO1_RPA10_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA10 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA14            (PPS_TC2WO1G4R_TC2WO1_RPA14_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA14 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPB3             (PPS_TC2WO1G4R_TC2WO1_RPB3_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPB3 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPB7             (PPS_TC2WO1G4R_TC2WO1_RPB7_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPB7 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPB11            (PPS_TC2WO1G4R_TC2WO1_RPB11_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPB11 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA1             (PPS_TC2WO1G4R_TC2WO1_RPA1_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA1 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA5             (PPS_TC2WO1G4R_TC2WO1_RPA5_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA5 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA9             (PPS_TC2WO1G4R_TC2WO1_RPA9_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA9 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA13            (PPS_TC2WO1G4R_TC2WO1_RPA13_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA13 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPB2             (PPS_TC2WO1G4R_TC2WO1_RPB2_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPB2 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPB6             (PPS_TC2WO1G4R_TC2WO1_RPB6_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPB6 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPB10            (PPS_TC2WO1G4R_TC2WO1_RPB10_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPB10 Position  */
#define PPS_TC2WO1G4R_TC2WO1_RPA8             (PPS_TC2WO1G4R_TC2WO1_RPA8_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) RPA8 Position  */
#define PPS_TC2WO1G4R_TC2WO1_OFF              (PPS_TC2WO1G4R_TC2WO1_OFF_Val << PPS_TC2WO1G4R_TC2WO1_Pos) /* (PPS_TC2WO1G4R) OFF Position  */
#define PPS_TC2WO1G4R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC2WO1G4R) Register Mask  */


/* -------- PPS_TC3WO0G1R : (PPS Offset: 0xD8) (R/W 32)  -------- */
#define PPS_TC3WO0G1R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC3WO0G1R)   Reset Value */

#define PPS_TC3WO0G1R_TC3WO0_Pos              _UINT32_(0)                                          /* (PPS_TC3WO0G1R) TC3/WO0G1 Position */
#define PPS_TC3WO0G1R_TC3WO0_Msk              (_UINT32_(0xF) << PPS_TC3WO0G1R_TC3WO0_Pos)          /* (PPS_TC3WO0G1R) TC3/WO0G1 Mask */
#define PPS_TC3WO0G1R_TC3WO0(value)           (PPS_TC3WO0G1R_TC3WO0_Msk & (_UINT32_(value) << PPS_TC3WO0G1R_TC3WO0_Pos)) /* Assigment of value for TC3WO0 in the PPS_TC3WO0G1R register */
#define   PPS_TC3WO0G1R_TC3WO0_RPA9_Val       _UINT32_(0xF)                                        /* (PPS_TC3WO0G1R) RPA9  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA3_Val       _UINT32_(0x1)                                        /* (PPS_TC3WO0G1R) RPA3  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA7_Val       _UINT32_(0x2)                                        /* (PPS_TC3WO0G1R) RPA7  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA11_Val      _UINT32_(0x3)                                        /* (PPS_TC3WO0G1R) RPA11  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB0_Val       _UINT32_(0x4)                                        /* (PPS_TC3WO0G1R) RPB0  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB4_Val       _UINT32_(0x5)                                        /* (PPS_TC3WO0G1R) RPB4  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB8_Val       _UINT32_(0x6)                                        /* (PPS_TC3WO0G1R) RPB8  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB12_Val      _UINT32_(0x7)                                        /* (PPS_TC3WO0G1R) RPB12  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA2_Val       _UINT32_(0x8)                                        /* (PPS_TC3WO0G1R) RPA2  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA6_Val       _UINT32_(0x9)                                        /* (PPS_TC3WO0G1R) RPA6  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA10_Val      _UINT32_(0xA)                                        /* (PPS_TC3WO0G1R) RPA10  */
#define   PPS_TC3WO0G1R_TC3WO0_RPA14_Val      _UINT32_(0xB)                                        /* (PPS_TC3WO0G1R) RPA14  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB3_Val       _UINT32_(0xC)                                        /* (PPS_TC3WO0G1R) RPB3  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB7_Val       _UINT32_(0xD)                                        /* (PPS_TC3WO0G1R) RPB7  */
#define   PPS_TC3WO0G1R_TC3WO0_RPB11_Val      _UINT32_(0xE)                                        /* (PPS_TC3WO0G1R) RPB11  */
#define   PPS_TC3WO0G1R_TC3WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC3WO0G1R) OFF  */
#define PPS_TC3WO0G1R_TC3WO0_RPA9             (PPS_TC3WO0G1R_TC3WO0_RPA9_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA9 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA3             (PPS_TC3WO0G1R_TC3WO0_RPA3_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA3 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA7             (PPS_TC3WO0G1R_TC3WO0_RPA7_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA7 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA11            (PPS_TC3WO0G1R_TC3WO0_RPA11_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA11 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB0             (PPS_TC3WO0G1R_TC3WO0_RPB0_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB0 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB4             (PPS_TC3WO0G1R_TC3WO0_RPB4_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB4 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB8             (PPS_TC3WO0G1R_TC3WO0_RPB8_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB8 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB12            (PPS_TC3WO0G1R_TC3WO0_RPB12_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB12 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA2             (PPS_TC3WO0G1R_TC3WO0_RPA2_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA2 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA6             (PPS_TC3WO0G1R_TC3WO0_RPA6_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA6 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA10            (PPS_TC3WO0G1R_TC3WO0_RPA10_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA10 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPA14            (PPS_TC3WO0G1R_TC3WO0_RPA14_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPA14 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB3             (PPS_TC3WO0G1R_TC3WO0_RPB3_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB3 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB7             (PPS_TC3WO0G1R_TC3WO0_RPB7_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB7 Position  */
#define PPS_TC3WO0G1R_TC3WO0_RPB11            (PPS_TC3WO0G1R_TC3WO0_RPB11_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) RPB11 Position  */
#define PPS_TC3WO0G1R_TC3WO0_OFF              (PPS_TC3WO0G1R_TC3WO0_OFF_Val << PPS_TC3WO0G1R_TC3WO0_Pos) /* (PPS_TC3WO0G1R) OFF Position  */
#define PPS_TC3WO0G1R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC3WO0G1R) Register Mask  */


/* -------- PPS_TC3WO0G3R : (PPS Offset: 0xDC) (R/W 32)  -------- */
#define PPS_TC3WO0G3R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC3WO0G3R)   Reset Value */

#define PPS_TC3WO0G3R_TC3WO0_Pos              _UINT32_(0)                                          /* (PPS_TC3WO0G3R) TC3/WO0G3 Position */
#define PPS_TC3WO0G3R_TC3WO0_Msk              (_UINT32_(0xF) << PPS_TC3WO0G3R_TC3WO0_Pos)          /* (PPS_TC3WO0G3R) TC3/WO0G3 Mask */
#define PPS_TC3WO0G3R_TC3WO0(value)           (PPS_TC3WO0G3R_TC3WO0_Msk & (_UINT32_(value) << PPS_TC3WO0G3R_TC3WO0_Pos)) /* Assigment of value for TC3WO0 in the PPS_TC3WO0G3R register */
#define   PPS_TC3WO0G3R_TC3WO0_RPA1_Val       _UINT32_(0xF)                                        /* (PPS_TC3WO0G3R) RPA1  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA5_Val       _UINT32_(0x1)                                        /* (PPS_TC3WO0G3R) RPA5  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA9_Val       _UINT32_(0x2)                                        /* (PPS_TC3WO0G3R) RPA9  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA13_Val      _UINT32_(0x3)                                        /* (PPS_TC3WO0G3R) RPA13  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB2_Val       _UINT32_(0x4)                                        /* (PPS_TC3WO0G3R) RPB2  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB6_Val       _UINT32_(0x5)                                        /* (PPS_TC3WO0G3R) RPB6  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB10_Val      _UINT32_(0x6)                                        /* (PPS_TC3WO0G3R) RPB10  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA0_Val       _UINT32_(0x7)                                        /* (PPS_TC3WO0G3R) RPA0  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA4_Val       _UINT32_(0x8)                                        /* (PPS_TC3WO0G3R) RPA4  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA8_Val       _UINT32_(0x9)                                        /* (PPS_TC3WO0G3R) RPA8  */
#define   PPS_TC3WO0G3R_TC3WO0_RPA12_Val      _UINT32_(0xA)                                        /* (PPS_TC3WO0G3R) RPA12  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB1_Val       _UINT32_(0xB)                                        /* (PPS_TC3WO0G3R) RPB1  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB5_Val       _UINT32_(0xC)                                        /* (PPS_TC3WO0G3R) RPB5  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB9_Val       _UINT32_(0xD)                                        /* (PPS_TC3WO0G3R) RPB9  */
#define   PPS_TC3WO0G3R_TC3WO0_RPB13_Val      _UINT32_(0xE)                                        /* (PPS_TC3WO0G3R) RPB13  */
#define   PPS_TC3WO0G3R_TC3WO0_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC3WO0G3R) OFF  */
#define PPS_TC3WO0G3R_TC3WO0_RPA1             (PPS_TC3WO0G3R_TC3WO0_RPA1_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA1 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA5             (PPS_TC3WO0G3R_TC3WO0_RPA5_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA5 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA9             (PPS_TC3WO0G3R_TC3WO0_RPA9_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA9 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA13            (PPS_TC3WO0G3R_TC3WO0_RPA13_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA13 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB2             (PPS_TC3WO0G3R_TC3WO0_RPB2_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB2 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB6             (PPS_TC3WO0G3R_TC3WO0_RPB6_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB6 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB10            (PPS_TC3WO0G3R_TC3WO0_RPB10_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB10 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA0             (PPS_TC3WO0G3R_TC3WO0_RPA0_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA0 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA4             (PPS_TC3WO0G3R_TC3WO0_RPA4_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA4 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA8             (PPS_TC3WO0G3R_TC3WO0_RPA8_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA8 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPA12            (PPS_TC3WO0G3R_TC3WO0_RPA12_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPA12 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB1             (PPS_TC3WO0G3R_TC3WO0_RPB1_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB1 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB5             (PPS_TC3WO0G3R_TC3WO0_RPB5_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB5 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB9             (PPS_TC3WO0G3R_TC3WO0_RPB9_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB9 Position  */
#define PPS_TC3WO0G3R_TC3WO0_RPB13            (PPS_TC3WO0G3R_TC3WO0_RPB13_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) RPB13 Position  */
#define PPS_TC3WO0G3R_TC3WO0_OFF              (PPS_TC3WO0G3R_TC3WO0_OFF_Val << PPS_TC3WO0G3R_TC3WO0_Pos) /* (PPS_TC3WO0G3R) OFF Position  */
#define PPS_TC3WO0G3R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC3WO0G3R) Register Mask  */


/* -------- PPS_TC3WO1G2R : (PPS Offset: 0xE0) (R/W 32)  -------- */
#define PPS_TC3WO1G2R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC3WO1G2R)   Reset Value */

#define PPS_TC3WO1G2R_TC3WO1_Pos              _UINT32_(0)                                          /* (PPS_TC3WO1G2R) TC3/WO1G2 Position */
#define PPS_TC3WO1G2R_TC3WO1_Msk              (_UINT32_(0xF) << PPS_TC3WO1G2R_TC3WO1_Pos)          /* (PPS_TC3WO1G2R) TC3/WO1G2 Mask */
#define PPS_TC3WO1G2R_TC3WO1(value)           (PPS_TC3WO1G2R_TC3WO1_Msk & (_UINT32_(value) << PPS_TC3WO1G2R_TC3WO1_Pos)) /* Assigment of value for TC3WO1 in the PPS_TC3WO1G2R register */
#define   PPS_TC3WO1G2R_TC3WO1_RPA0_Val       _UINT32_(0xF)                                        /* (PPS_TC3WO1G2R) RPA0  */
#define   PPS_TC3WO1G2R_TC3WO1_RPA4_Val       _UINT32_(0x1)                                        /* (PPS_TC3WO1G2R) RPA4  */
#define   PPS_TC3WO1G2R_TC3WO1_RPA8_Val       _UINT32_(0x2)                                        /* (PPS_TC3WO1G2R) RPA8  */
#define   PPS_TC3WO1G2R_TC3WO1_RPA12_Val      _UINT32_(0x3)                                        /* (PPS_TC3WO1G2R) RPA12  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB1_Val       _UINT32_(0x4)                                        /* (PPS_TC3WO1G2R) RPB1  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB5_Val       _UINT32_(0x5)                                        /* (PPS_TC3WO1G2R) RPB5  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB9_Val       _UINT32_(0x6)                                        /* (PPS_TC3WO1G2R) RPB9  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB13_Val      _UINT32_(0x7)                                        /* (PPS_TC3WO1G2R) RPB13  */
#define   PPS_TC3WO1G2R_TC3WO1_RPA3_Val       _UINT32_(0x8)                                        /* (PPS_TC3WO1G2R) RPA3  */
#define   PPS_TC3WO1G2R_TC3WO1_RPA7_Val       _UINT32_(0x9)                                        /* (PPS_TC3WO1G2R) RPA7  */
#define   PPS_TC3WO1G2R_TC3WO1_RPA11_Val      _UINT32_(0xA)                                        /* (PPS_TC3WO1G2R) RPA11  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB0_Val       _UINT32_(0xB)                                        /* (PPS_TC3WO1G2R) RPB0  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB4_Val       _UINT32_(0xC)                                        /* (PPS_TC3WO1G2R) RPB4  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB8_Val       _UINT32_(0xD)                                        /* (PPS_TC3WO1G2R) RPB8  */
#define   PPS_TC3WO1G2R_TC3WO1_RPB12_Val      _UINT32_(0xE)                                        /* (PPS_TC3WO1G2R) RPB12  */
#define   PPS_TC3WO1G2R_TC3WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC3WO1G2R) OFF  */
#define PPS_TC3WO1G2R_TC3WO1_RPA0             (PPS_TC3WO1G2R_TC3WO1_RPA0_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA0 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPA4             (PPS_TC3WO1G2R_TC3WO1_RPA4_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA4 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPA8             (PPS_TC3WO1G2R_TC3WO1_RPA8_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA8 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPA12            (PPS_TC3WO1G2R_TC3WO1_RPA12_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA12 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB1             (PPS_TC3WO1G2R_TC3WO1_RPB1_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB1 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB5             (PPS_TC3WO1G2R_TC3WO1_RPB5_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB5 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB9             (PPS_TC3WO1G2R_TC3WO1_RPB9_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB9 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB13            (PPS_TC3WO1G2R_TC3WO1_RPB13_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB13 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPA3             (PPS_TC3WO1G2R_TC3WO1_RPA3_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA3 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPA7             (PPS_TC3WO1G2R_TC3WO1_RPA7_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA7 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPA11            (PPS_TC3WO1G2R_TC3WO1_RPA11_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPA11 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB0             (PPS_TC3WO1G2R_TC3WO1_RPB0_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB0 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB4             (PPS_TC3WO1G2R_TC3WO1_RPB4_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB4 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB8             (PPS_TC3WO1G2R_TC3WO1_RPB8_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB8 Position  */
#define PPS_TC3WO1G2R_TC3WO1_RPB12            (PPS_TC3WO1G2R_TC3WO1_RPB12_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) RPB12 Position  */
#define PPS_TC3WO1G2R_TC3WO1_OFF              (PPS_TC3WO1G2R_TC3WO1_OFF_Val << PPS_TC3WO1G2R_TC3WO1_Pos) /* (PPS_TC3WO1G2R) OFF Position  */
#define PPS_TC3WO1G2R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC3WO1G2R) Register Mask  */


/* -------- PPS_TC3WO1G4R : (PPS Offset: 0xE4) (R/W 32)  -------- */
#define PPS_TC3WO1G4R_RESETVALUE              _UINT32_(0x00)                                       /*  (PPS_TC3WO1G4R)   Reset Value */

#define PPS_TC3WO1G4R_TC3WO1_Pos              _UINT32_(0)                                          /* (PPS_TC3WO1G4R) TC3/WO1G4 Position */
#define PPS_TC3WO1G4R_TC3WO1_Msk              (_UINT32_(0xF) << PPS_TC3WO1G4R_TC3WO1_Pos)          /* (PPS_TC3WO1G4R) TC3/WO1G4 Mask */
#define PPS_TC3WO1G4R_TC3WO1(value)           (PPS_TC3WO1G4R_TC3WO1_Msk & (_UINT32_(value) << PPS_TC3WO1G4R_TC3WO1_Pos)) /* Assigment of value for TC3WO1 in the PPS_TC3WO1G4R register */
#define   PPS_TC3WO1G4R_TC3WO1_RPA2_Val       _UINT32_(0xF)                                        /* (PPS_TC3WO1G4R) RPA2  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA6_Val       _UINT32_(0x1)                                        /* (PPS_TC3WO1G4R) RPA6  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA10_Val      _UINT32_(0x2)                                        /* (PPS_TC3WO1G4R) RPA10  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA14_Val      _UINT32_(0x3)                                        /* (PPS_TC3WO1G4R) RPA14  */
#define   PPS_TC3WO1G4R_TC3WO1_RPB3_Val       _UINT32_(0x4)                                        /* (PPS_TC3WO1G4R) RPB3  */
#define   PPS_TC3WO1G4R_TC3WO1_RPB7_Val       _UINT32_(0x5)                                        /* (PPS_TC3WO1G4R) RPB7  */
#define   PPS_TC3WO1G4R_TC3WO1_RPB11_Val      _UINT32_(0x6)                                        /* (PPS_TC3WO1G4R) RPB11  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA1_Val       _UINT32_(0x7)                                        /* (PPS_TC3WO1G4R) RPA1  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA5_Val       _UINT32_(0x8)                                        /* (PPS_TC3WO1G4R) RPA5  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA9_Val       _UINT32_(0x9)                                        /* (PPS_TC3WO1G4R) RPA9  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA13_Val      _UINT32_(0xA)                                        /* (PPS_TC3WO1G4R) RPA13  */
#define   PPS_TC3WO1G4R_TC3WO1_RPB2_Val       _UINT32_(0xB)                                        /* (PPS_TC3WO1G4R) RPB2  */
#define   PPS_TC3WO1G4R_TC3WO1_RPB6_Val       _UINT32_(0xC)                                        /* (PPS_TC3WO1G4R) RPB6  */
#define   PPS_TC3WO1G4R_TC3WO1_RPB10_Val      _UINT32_(0xD)                                        /* (PPS_TC3WO1G4R) RPB10  */
#define   PPS_TC3WO1G4R_TC3WO1_RPA8_Val       _UINT32_(0xE)                                        /* (PPS_TC3WO1G4R) RPA8  */
#define   PPS_TC3WO1G4R_TC3WO1_OFF_Val        _UINT32_(0x0)                                        /* (PPS_TC3WO1G4R) OFF  */
#define PPS_TC3WO1G4R_TC3WO1_RPA2             (PPS_TC3WO1G4R_TC3WO1_RPA2_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA2 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA6             (PPS_TC3WO1G4R_TC3WO1_RPA6_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA6 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA10            (PPS_TC3WO1G4R_TC3WO1_RPA10_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA10 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA14            (PPS_TC3WO1G4R_TC3WO1_RPA14_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA14 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPB3             (PPS_TC3WO1G4R_TC3WO1_RPB3_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPB3 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPB7             (PPS_TC3WO1G4R_TC3WO1_RPB7_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPB7 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPB11            (PPS_TC3WO1G4R_TC3WO1_RPB11_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPB11 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA1             (PPS_TC3WO1G4R_TC3WO1_RPA1_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA1 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA5             (PPS_TC3WO1G4R_TC3WO1_RPA5_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA5 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA9             (PPS_TC3WO1G4R_TC3WO1_RPA9_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA9 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA13            (PPS_TC3WO1G4R_TC3WO1_RPA13_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA13 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPB2             (PPS_TC3WO1G4R_TC3WO1_RPB2_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPB2 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPB6             (PPS_TC3WO1G4R_TC3WO1_RPB6_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPB6 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPB10            (PPS_TC3WO1G4R_TC3WO1_RPB10_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPB10 Position  */
#define PPS_TC3WO1G4R_TC3WO1_RPA8             (PPS_TC3WO1G4R_TC3WO1_RPA8_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) RPA8 Position  */
#define PPS_TC3WO1G4R_TC3WO1_OFF              (PPS_TC3WO1G4R_TC3WO1_OFF_Val << PPS_TC3WO1G4R_TC3WO1_Pos) /* (PPS_TC3WO1G4R) OFF Position  */
#define PPS_TC3WO1G4R_Msk                     _UINT32_(0x0000000F)                                 /* (PPS_TC3WO1G4R) Register Mask  */


/* -------- PPS_RPA0G2R : (PPS Offset: 0x200) (R/W 32)  -------- */
#define PPS_RPA0G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA0G2R)   Reset Value */

#define PPS_RPA0G2R_RPA0G2R_Pos               _UINT32_(0)                                          /* (PPS_RPA0G2R) RPA0/G2 Position */
#define PPS_RPA0G2R_RPA0G2R_Msk               (_UINT32_(0x1F) << PPS_RPA0G2R_RPA0G2R_Pos)          /* (PPS_RPA0G2R) RPA0/G2 Mask */
#define PPS_RPA0G2R_RPA0G2R(value)            (PPS_RPA0G2R_RPA0G2R_Msk & (_UINT32_(value) << PPS_RPA0G2R_RPA0G2R_Pos)) /* Assigment of value for RPA0G2R in the PPS_RPA0G2R register */
#define   PPS_RPA0G2R_RPA0G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA0G2R) OFF  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPA0G2R) SERCOM0/PAD0  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPA0G2R) SERCOM0/PAD3  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPA0G2R) SERCOM0/PAD2  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPA0G2R) SERCOM1/PAD1  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPA0G2R) SERCOM1/PAD3  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPA0G2R) SERCOM1/PAD2  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPA0G2R) SERCOM2/PAD1  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPA0G2R) SERCOM2/PAD2  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPA0G2R) SERCOM3/PAD1  */
#define   PPS_RPA0G2R_RPA0G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPA0G2R) SERCOM3/PAD0  */
#define   PPS_RPA0G2R_RPA0G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPA0G2R) TCC0/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPA0G2R) TCC0/WO5  */
#define   PPS_RPA0G2R_RPA0G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPA0G2R) TCC0/WO3  */
#define   PPS_RPA0G2R_RPA0G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPA0G2R) TCC1/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPA0G2R) TCC1/WO5  */
#define   PPS_RPA0G2R_RPA0G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPA0G2R) TCC1/WO3  */
#define   PPS_RPA0G2R_RPA0G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA0G2R) TCC2/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA0G2R) TC0/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPA0G2R) REFO2  */
#define   PPS_RPA0G2R_RPA0G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA0G2R) TC1/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA0G2R) TC2/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA0G2R) TC3/WO1  */
#define   PPS_RPA0G2R_RPA0G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA0G2R) QSCK  */
#define   PPS_RPA0G2R_RPA0G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA0G2R) QCS  */
#define   PPS_RPA0G2R_RPA0G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPA0G2R) QD0  */
#define   PPS_RPA0G2R_RPA0G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPA0G2R) QD3  */
#define   PPS_RPA0G2R_RPA0G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPA0G2R) QD2  */
#define   PPS_RPA0G2R_RPA0G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA0G2R) CCLOUT1  */
#define   PPS_RPA0G2R_RPA0G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPA0G2R) TSTBUS1  */
#define   PPS_RPA0G2R_RPA0G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPA0G2R) TSTBUS5  */
#define   PPS_RPA0G2R_RPA0G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPA0G2R) TSTBUS9  */
#define PPS_RPA0G2R_RPA0G2R_OFF               (PPS_RPA0G2R_RPA0G2R_OFF_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) OFF Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM0P0           (PPS_RPA0G2R_RPA0G2R_SCOM0P0_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM0/PAD0 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM0P3           (PPS_RPA0G2R_RPA0G2R_SCOM0P3_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM0/PAD3 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM0P2           (PPS_RPA0G2R_RPA0G2R_SCOM0P2_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM0/PAD2 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM1P1           (PPS_RPA0G2R_RPA0G2R_SCOM1P1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM1/PAD1 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM1P3           (PPS_RPA0G2R_RPA0G2R_SCOM1P3_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM1/PAD3 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM1P2           (PPS_RPA0G2R_RPA0G2R_SCOM1P2_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM1/PAD2 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM2P1           (PPS_RPA0G2R_RPA0G2R_SCOM2P1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM2/PAD1 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM2P2           (PPS_RPA0G2R_RPA0G2R_SCOM2P2_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM2/PAD2 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM3P1           (PPS_RPA0G2R_RPA0G2R_SCOM3P1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM3/PAD1 Position  */
#define PPS_RPA0G2R_RPA0G2R_SCOM3P0           (PPS_RPA0G2R_RPA0G2R_SCOM3P0_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) SERCOM3/PAD0 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC0WO1           (PPS_RPA0G2R_RPA0G2R_TCC0WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC0/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC0WO5           (PPS_RPA0G2R_RPA0G2R_TCC0WO5_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC0/WO5 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC0WO3           (PPS_RPA0G2R_RPA0G2R_TCC0WO3_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC0/WO3 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC1WO1           (PPS_RPA0G2R_RPA0G2R_TCC1WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC1/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC1WO5           (PPS_RPA0G2R_RPA0G2R_TCC1WO5_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC1/WO5 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC1WO3           (PPS_RPA0G2R_RPA0G2R_TCC1WO3_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC1/WO3 Position  */
#define PPS_RPA0G2R_RPA0G2R_TCC2WO1           (PPS_RPA0G2R_RPA0G2R_TCC2WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TCC2/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TC0WO1            (PPS_RPA0G2R_RPA0G2R_TC0WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TC0/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_REFO2             (PPS_RPA0G2R_RPA0G2R_REFO2_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) REFO2 Position  */
#define PPS_RPA0G2R_RPA0G2R_TC1WO1            (PPS_RPA0G2R_RPA0G2R_TC1WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TC1/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TC2WO1            (PPS_RPA0G2R_RPA0G2R_TC2WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TC2/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TC3WO1            (PPS_RPA0G2R_RPA0G2R_TC3WO1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TC3/WO1 Position  */
#define PPS_RPA0G2R_RPA0G2R_QSCK              (PPS_RPA0G2R_RPA0G2R_QSCK_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) QSCK Position  */
#define PPS_RPA0G2R_RPA0G2R_QCS               (PPS_RPA0G2R_RPA0G2R_QCS_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) QCS Position  */
#define PPS_RPA0G2R_RPA0G2R_QD0               (PPS_RPA0G2R_RPA0G2R_QD0_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) QD0 Position  */
#define PPS_RPA0G2R_RPA0G2R_QD3               (PPS_RPA0G2R_RPA0G2R_QD3_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) QD3 Position  */
#define PPS_RPA0G2R_RPA0G2R_QD2               (PPS_RPA0G2R_RPA0G2R_QD2_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) QD2 Position  */
#define PPS_RPA0G2R_RPA0G2R_CCLOUT1           (PPS_RPA0G2R_RPA0G2R_CCLOUT1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) CCLOUT1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TSTBUS1           (PPS_RPA0G2R_RPA0G2R_TSTBUS1_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TSTBUS1 Position  */
#define PPS_RPA0G2R_RPA0G2R_TSTBUS5           (PPS_RPA0G2R_RPA0G2R_TSTBUS5_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TSTBUS5 Position  */
#define PPS_RPA0G2R_RPA0G2R_TSTBUS9           (PPS_RPA0G2R_RPA0G2R_TSTBUS9_Val << PPS_RPA0G2R_RPA0G2R_Pos) /* (PPS_RPA0G2R) TSTBUS9 Position  */
#define PPS_RPA0G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA0G2R) Register Mask  */


/* -------- PPS_RPA0G3R : (PPS Offset: 0x204) (R/W 32)  -------- */
#define PPS_RPA0G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA0G3R)   Reset Value */

#define PPS_RPA0G3R_RPA0G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA0G3R) RPA0/G3 Position */
#define PPS_RPA0G3R_RPA0G3R_Msk               (_UINT32_(0x1F) << PPS_RPA0G3R_RPA0G3R_Pos)          /* (PPS_RPA0G3R) RPA0/G3 Mask */
#define PPS_RPA0G3R_RPA0G3R(value)            (PPS_RPA0G3R_RPA0G3R_Msk & (_UINT32_(value) << PPS_RPA0G3R_RPA0G3R_Pos)) /* Assigment of value for RPA0G3R in the PPS_RPA0G3R register */
#define   PPS_RPA0G3R_RPA0G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA0G3R) OFF  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA0G3R) SERCOM0/PAD1  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA0G3R) SERCOM0/PAD0  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA0G3R) SERCOM0/PAD3  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA0G3R) SERCOM1/PAD2  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA0G3R) SERCOM1/PAD0  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA0G3R) SERCOM1/PAD3  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA0G3R) SERCOM2/PAD2  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA0G3R) SERCOM2/PAD3  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA0G3R) SERCOM3/PAD2  */
#define   PPS_RPA0G3R_RPA0G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA0G3R) SERCOM3/PAD1  */
#define   PPS_RPA0G3R_RPA0G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA0G3R) TCC0/WO2  */
#define   PPS_RPA0G3R_RPA0G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA0G3R) TCC0/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA0G3R) TCC0/WO4  */
#define   PPS_RPA0G3R_RPA0G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA0G3R) TCC1/WO2  */
#define   PPS_RPA0G3R_RPA0G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA0G3R) TCC1/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA0G3R) TCC1/WO4  */
#define   PPS_RPA0G3R_RPA0G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA0G3R) TCC2/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA0G3R) TC0/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA0G3R) REFO3  */
#define   PPS_RPA0G3R_RPA0G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA0G3R) TC1/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA0G3R) TC2/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA0G3R) TC3/WO0  */
#define   PPS_RPA0G3R_RPA0G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA0G3R) QSCK  */
#define   PPS_RPA0G3R_RPA0G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA0G3R) QCS  */
#define   PPS_RPA0G3R_RPA0G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA0G3R) QD1  */
#define   PPS_RPA0G3R_RPA0G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA0G3R) QD0  */
#define   PPS_RPA0G3R_RPA0G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA0G3R) QD3  */
#define   PPS_RPA0G3R_RPA0G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA0G3R) CCLOUT0  */
#define   PPS_RPA0G3R_RPA0G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA0G3R) TSTBUS2  */
#define   PPS_RPA0G3R_RPA0G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA0G3R) TSTBUS6  */
#define   PPS_RPA0G3R_RPA0G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA0G3R) TSTBUS10  */
#define PPS_RPA0G3R_RPA0G3R_OFF               (PPS_RPA0G3R_RPA0G3R_OFF_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) OFF Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM0P1           (PPS_RPA0G3R_RPA0G3R_SCOM0P1_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM0P0           (PPS_RPA0G3R_RPA0G3R_SCOM0P0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM0P3           (PPS_RPA0G3R_RPA0G3R_SCOM0P3_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM1P2           (PPS_RPA0G3R_RPA0G3R_SCOM1P2_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM1P0           (PPS_RPA0G3R_RPA0G3R_SCOM1P0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM1P3           (PPS_RPA0G3R_RPA0G3R_SCOM1P3_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM2P2           (PPS_RPA0G3R_RPA0G3R_SCOM2P2_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM2P3           (PPS_RPA0G3R_RPA0G3R_SCOM2P3_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM3P2           (PPS_RPA0G3R_RPA0G3R_SCOM3P2_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA0G3R_RPA0G3R_SCOM3P1           (PPS_RPA0G3R_RPA0G3R_SCOM3P1_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC0WO2           (PPS_RPA0G3R_RPA0G3R_TCC0WO2_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC0/WO2 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC0WO0           (PPS_RPA0G3R_RPA0G3R_TCC0WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC0/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC0WO4           (PPS_RPA0G3R_RPA0G3R_TCC0WO4_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC0/WO4 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC1WO2           (PPS_RPA0G3R_RPA0G3R_TCC1WO2_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC1/WO2 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC1WO0           (PPS_RPA0G3R_RPA0G3R_TCC1WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC1/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC1WO4           (PPS_RPA0G3R_RPA0G3R_TCC1WO4_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC1/WO4 Position  */
#define PPS_RPA0G3R_RPA0G3R_TCC2WO0           (PPS_RPA0G3R_RPA0G3R_TCC2WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TCC2/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_TC0WO0            (PPS_RPA0G3R_RPA0G3R_TC0WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TC0/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_REFO3             (PPS_RPA0G3R_RPA0G3R_REFO3_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) REFO3 Position  */
#define PPS_RPA0G3R_RPA0G3R_TC1WO0            (PPS_RPA0G3R_RPA0G3R_TC1WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TC1/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_TC2WO0            (PPS_RPA0G3R_RPA0G3R_TC2WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TC2/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_TC3WO0            (PPS_RPA0G3R_RPA0G3R_TC3WO0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TC3/WO0 Position  */
#define PPS_RPA0G3R_RPA0G3R_QSCK              (PPS_RPA0G3R_RPA0G3R_QSCK_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) QSCK Position  */
#define PPS_RPA0G3R_RPA0G3R_QCS               (PPS_RPA0G3R_RPA0G3R_QCS_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) QCS Position  */
#define PPS_RPA0G3R_RPA0G3R_QD1               (PPS_RPA0G3R_RPA0G3R_QD1_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) QD1 Position  */
#define PPS_RPA0G3R_RPA0G3R_QD0               (PPS_RPA0G3R_RPA0G3R_QD0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) QD0 Position  */
#define PPS_RPA0G3R_RPA0G3R_QD3               (PPS_RPA0G3R_RPA0G3R_QD3_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) QD3 Position  */
#define PPS_RPA0G3R_RPA0G3R_CCLOUT0           (PPS_RPA0G3R_RPA0G3R_CCLOUT0_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) CCLOUT0 Position  */
#define PPS_RPA0G3R_RPA0G3R_TSTBUS2           (PPS_RPA0G3R_RPA0G3R_TSTBUS2_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TSTBUS2 Position  */
#define PPS_RPA0G3R_RPA0G3R_TSTBUS6           (PPS_RPA0G3R_RPA0G3R_TSTBUS6_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TSTBUS6 Position  */
#define PPS_RPA0G3R_RPA0G3R_TSTBUS10          (PPS_RPA0G3R_RPA0G3R_TSTBUS10_Val << PPS_RPA0G3R_RPA0G3R_Pos) /* (PPS_RPA0G3R) TSTBUS10 Position  */
#define PPS_RPA0G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA0G3R) Register Mask  */


/* -------- PPS_RPA1G3R : (PPS Offset: 0x208) (R/W 32)  -------- */
#define PPS_RPA1G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA1G3R)   Reset Value */

#define PPS_RPA1G3R_RPA1G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA1G3R) RPA1/G3 Position */
#define PPS_RPA1G3R_RPA1G3R_Msk               (_UINT32_(0x1F) << PPS_RPA1G3R_RPA1G3R_Pos)          /* (PPS_RPA1G3R) RPA1/G3 Mask */
#define PPS_RPA1G3R_RPA1G3R(value)            (PPS_RPA1G3R_RPA1G3R_Msk & (_UINT32_(value) << PPS_RPA1G3R_RPA1G3R_Pos)) /* Assigment of value for RPA1G3R in the PPS_RPA1G3R register */
#define   PPS_RPA1G3R_RPA1G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA1G3R) OFF  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA1G3R) SERCOM0/PAD1  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA1G3R) SERCOM0/PAD0  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA1G3R) SERCOM0/PAD3  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA1G3R) SERCOM1/PAD2  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA1G3R) SERCOM1/PAD0  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA1G3R) SERCOM1/PAD3  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA1G3R) SERCOM2/PAD2  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA1G3R) SERCOM2/PAD3  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA1G3R) SERCOM3/PAD2  */
#define   PPS_RPA1G3R_RPA1G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA1G3R) SERCOM3/PAD1  */
#define   PPS_RPA1G3R_RPA1G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA1G3R) TCC0/WO2  */
#define   PPS_RPA1G3R_RPA1G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA1G3R) TCC0/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA1G3R) TCC0/WO4  */
#define   PPS_RPA1G3R_RPA1G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA1G3R) TCC1/WO2  */
#define   PPS_RPA1G3R_RPA1G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA1G3R) TCC1/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA1G3R) TCC1/WO4  */
#define   PPS_RPA1G3R_RPA1G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA1G3R) TCC2/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA1G3R) TC0/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA1G3R) REFO3  */
#define   PPS_RPA1G3R_RPA1G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA1G3R) TC1/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA1G3R) TC2/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA1G3R) TC3/WO0  */
#define   PPS_RPA1G3R_RPA1G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA1G3R) QSCK  */
#define   PPS_RPA1G3R_RPA1G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA1G3R) QCS  */
#define   PPS_RPA1G3R_RPA1G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA1G3R) QD1  */
#define   PPS_RPA1G3R_RPA1G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA1G3R) QD0  */
#define   PPS_RPA1G3R_RPA1G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA1G3R) QD3  */
#define   PPS_RPA1G3R_RPA1G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA1G3R) CCLOUT0  */
#define   PPS_RPA1G3R_RPA1G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA1G3R) TSTBUS2  */
#define   PPS_RPA1G3R_RPA1G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA1G3R) TSTBUS6  */
#define   PPS_RPA1G3R_RPA1G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA1G3R) TSTBUS10  */
#define PPS_RPA1G3R_RPA1G3R_OFF               (PPS_RPA1G3R_RPA1G3R_OFF_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) OFF Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM0P1           (PPS_RPA1G3R_RPA1G3R_SCOM0P1_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM0P0           (PPS_RPA1G3R_RPA1G3R_SCOM0P0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM0P3           (PPS_RPA1G3R_RPA1G3R_SCOM0P3_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM1P2           (PPS_RPA1G3R_RPA1G3R_SCOM1P2_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM1P0           (PPS_RPA1G3R_RPA1G3R_SCOM1P0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM1P3           (PPS_RPA1G3R_RPA1G3R_SCOM1P3_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM2P2           (PPS_RPA1G3R_RPA1G3R_SCOM2P2_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM2P3           (PPS_RPA1G3R_RPA1G3R_SCOM2P3_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM3P2           (PPS_RPA1G3R_RPA1G3R_SCOM3P2_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA1G3R_RPA1G3R_SCOM3P1           (PPS_RPA1G3R_RPA1G3R_SCOM3P1_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC0WO2           (PPS_RPA1G3R_RPA1G3R_TCC0WO2_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC0/WO2 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC0WO0           (PPS_RPA1G3R_RPA1G3R_TCC0WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC0/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC0WO4           (PPS_RPA1G3R_RPA1G3R_TCC0WO4_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC0/WO4 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC1WO2           (PPS_RPA1G3R_RPA1G3R_TCC1WO2_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC1/WO2 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC1WO0           (PPS_RPA1G3R_RPA1G3R_TCC1WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC1/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC1WO4           (PPS_RPA1G3R_RPA1G3R_TCC1WO4_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC1/WO4 Position  */
#define PPS_RPA1G3R_RPA1G3R_TCC2WO0           (PPS_RPA1G3R_RPA1G3R_TCC2WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TCC2/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_TC0WO0            (PPS_RPA1G3R_RPA1G3R_TC0WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TC0/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_REFO3             (PPS_RPA1G3R_RPA1G3R_REFO3_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) REFO3 Position  */
#define PPS_RPA1G3R_RPA1G3R_TC1WO0            (PPS_RPA1G3R_RPA1G3R_TC1WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TC1/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_TC2WO0            (PPS_RPA1G3R_RPA1G3R_TC2WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TC2/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_TC3WO0            (PPS_RPA1G3R_RPA1G3R_TC3WO0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TC3/WO0 Position  */
#define PPS_RPA1G3R_RPA1G3R_QSCK              (PPS_RPA1G3R_RPA1G3R_QSCK_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) QSCK Position  */
#define PPS_RPA1G3R_RPA1G3R_QCS               (PPS_RPA1G3R_RPA1G3R_QCS_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) QCS Position  */
#define PPS_RPA1G3R_RPA1G3R_QD1               (PPS_RPA1G3R_RPA1G3R_QD1_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) QD1 Position  */
#define PPS_RPA1G3R_RPA1G3R_QD0               (PPS_RPA1G3R_RPA1G3R_QD0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) QD0 Position  */
#define PPS_RPA1G3R_RPA1G3R_QD3               (PPS_RPA1G3R_RPA1G3R_QD3_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) QD3 Position  */
#define PPS_RPA1G3R_RPA1G3R_CCLOUT0           (PPS_RPA1G3R_RPA1G3R_CCLOUT0_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) CCLOUT0 Position  */
#define PPS_RPA1G3R_RPA1G3R_TSTBUS2           (PPS_RPA1G3R_RPA1G3R_TSTBUS2_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TSTBUS2 Position  */
#define PPS_RPA1G3R_RPA1G3R_TSTBUS6           (PPS_RPA1G3R_RPA1G3R_TSTBUS6_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TSTBUS6 Position  */
#define PPS_RPA1G3R_RPA1G3R_TSTBUS10          (PPS_RPA1G3R_RPA1G3R_TSTBUS10_Val << PPS_RPA1G3R_RPA1G3R_Pos) /* (PPS_RPA1G3R) TSTBUS10 Position  */
#define PPS_RPA1G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA1G3R) Register Mask  */


/* -------- PPS_RPA1G4R : (PPS Offset: 0x20C) (R/W 32)  -------- */
#define PPS_RPA1G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA1G4R)   Reset Value */

#define PPS_RPA1G4R_RPA1G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA1G4R) RPA1/G4 Position */
#define PPS_RPA1G4R_RPA1G4R_Msk               (_UINT32_(0x1F) << PPS_RPA1G4R_RPA1G4R_Pos)          /* (PPS_RPA1G4R) RPA1/G4 Mask */
#define PPS_RPA1G4R_RPA1G4R(value)            (PPS_RPA1G4R_RPA1G4R_Msk & (_UINT32_(value) << PPS_RPA1G4R_RPA1G4R_Pos)) /* Assigment of value for RPA1G4R in the PPS_RPA1G4R register */
#define   PPS_RPA1G4R_RPA1G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA1G4R) OFF  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA1G4R) SERCOM0/PAD2  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA1G4R) SERCOM0/PAD1  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA1G4R) SERCOM0/PAD0  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA1G4R) SERCOM1/PAD3  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA1G4R) SERCOM1/PAD1  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA1G4R) SERCOM1/PAD0  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA1G4R) SERCOM2/PAD3  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA1G4R) SERCOM2/PAD0  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA1G4R) SERCOM3/PAD3  */
#define   PPS_RPA1G4R_RPA1G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA1G4R) SERCOM3/PAD2  */
#define   PPS_RPA1G4R_RPA1G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA1G4R) TCC0/WO3  */
#define   PPS_RPA1G4R_RPA1G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA1G4R) TCC0/WO1  */
#define   PPS_RPA1G4R_RPA1G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA1G4R) TCC0/WO5  */
#define   PPS_RPA1G4R_RPA1G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA1G4R) TCC1/WO3  */
#define   PPS_RPA1G4R_RPA1G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA1G4R) TCC1/WO1  */
#define   PPS_RPA1G4R_RPA1G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA1G4R) TCC1/WO5  */
#define   PPS_RPA1G4R_RPA1G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA1G4R) TCC2/WO1  */
#define   PPS_RPA1G4R_RPA1G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA1G4R) TC0/WO0  */
#define   PPS_RPA1G4R_RPA1G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA1G4R) REFO4  */
#define   PPS_RPA1G4R_RPA1G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA1G4R) TC1/WO1  */
#define   PPS_RPA1G4R_RPA1G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA1G4R) TC2/WO1  */
#define   PPS_RPA1G4R_RPA1G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA1G4R) TC3/WO1  */
#define   PPS_RPA1G4R_RPA1G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA1G4R) QSCK  */
#define   PPS_RPA1G4R_RPA1G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA1G4R) QCS  */
#define   PPS_RPA1G4R_RPA1G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA1G4R) QD2  */
#define   PPS_RPA1G4R_RPA1G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA1G4R) QD1  */
#define   PPS_RPA1G4R_RPA1G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA1G4R) QD0  */
#define   PPS_RPA1G4R_RPA1G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA1G4R) CCLOUT1  */
#define   PPS_RPA1G4R_RPA1G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA1G4R) TSTBUS3  */
#define   PPS_RPA1G4R_RPA1G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA1G4R) TSTBUS7  */
#define   PPS_RPA1G4R_RPA1G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA1G4R) TSTBUS11  */
#define PPS_RPA1G4R_RPA1G4R_OFF               (PPS_RPA1G4R_RPA1G4R_OFF_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) OFF Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM0P2           (PPS_RPA1G4R_RPA1G4R_SCOM0P2_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM0P1           (PPS_RPA1G4R_RPA1G4R_SCOM0P1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM0P0           (PPS_RPA1G4R_RPA1G4R_SCOM0P0_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM1P3           (PPS_RPA1G4R_RPA1G4R_SCOM1P3_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM1P1           (PPS_RPA1G4R_RPA1G4R_SCOM1P1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM1P0           (PPS_RPA1G4R_RPA1G4R_SCOM1P0_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM2P3           (PPS_RPA1G4R_RPA1G4R_SCOM2P3_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM2P0           (PPS_RPA1G4R_RPA1G4R_SCOM2P0_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM3P3           (PPS_RPA1G4R_RPA1G4R_SCOM3P3_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA1G4R_RPA1G4R_SCOM3P2           (PPS_RPA1G4R_RPA1G4R_SCOM3P2_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC0WO3           (PPS_RPA1G4R_RPA1G4R_TCC0WO3_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC0/WO3 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC0WO1           (PPS_RPA1G4R_RPA1G4R_TCC0WO1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC0/WO1 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC0WO5           (PPS_RPA1G4R_RPA1G4R_TCC0WO5_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC0/WO5 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC1WO3           (PPS_RPA1G4R_RPA1G4R_TCC1WO3_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC1/WO3 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC1WO1           (PPS_RPA1G4R_RPA1G4R_TCC1WO1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC1/WO1 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC1WO5           (PPS_RPA1G4R_RPA1G4R_TCC1WO5_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC1/WO5 Position  */
#define PPS_RPA1G4R_RPA1G4R_TCC2WO1           (PPS_RPA1G4R_RPA1G4R_TCC2WO1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TCC2/WO1 Position  */
#define PPS_RPA1G4R_RPA1G4R_TC0WO0            (PPS_RPA1G4R_RPA1G4R_TC0WO0_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TC0/WO0 Position  */
#define PPS_RPA1G4R_RPA1G4R_REFO4             (PPS_RPA1G4R_RPA1G4R_REFO4_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) REFO4 Position  */
#define PPS_RPA1G4R_RPA1G4R_TC1WO1            (PPS_RPA1G4R_RPA1G4R_TC1WO1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TC1/WO1 Position  */
#define PPS_RPA1G4R_RPA1G4R_TC2WO1            (PPS_RPA1G4R_RPA1G4R_TC2WO1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TC2/WO1 Position  */
#define PPS_RPA1G4R_RPA1G4R_TC3WO1            (PPS_RPA1G4R_RPA1G4R_TC3WO1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TC3/WO1 Position  */
#define PPS_RPA1G4R_RPA1G4R_QSCK              (PPS_RPA1G4R_RPA1G4R_QSCK_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) QSCK Position  */
#define PPS_RPA1G4R_RPA1G4R_QCS               (PPS_RPA1G4R_RPA1G4R_QCS_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) QCS Position  */
#define PPS_RPA1G4R_RPA1G4R_QD2               (PPS_RPA1G4R_RPA1G4R_QD2_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) QD2 Position  */
#define PPS_RPA1G4R_RPA1G4R_QD1               (PPS_RPA1G4R_RPA1G4R_QD1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) QD1 Position  */
#define PPS_RPA1G4R_RPA1G4R_QD0               (PPS_RPA1G4R_RPA1G4R_QD0_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) QD0 Position  */
#define PPS_RPA1G4R_RPA1G4R_CCLOUT1           (PPS_RPA1G4R_RPA1G4R_CCLOUT1_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) CCLOUT1 Position  */
#define PPS_RPA1G4R_RPA1G4R_TSTBUS3           (PPS_RPA1G4R_RPA1G4R_TSTBUS3_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TSTBUS3 Position  */
#define PPS_RPA1G4R_RPA1G4R_TSTBUS7           (PPS_RPA1G4R_RPA1G4R_TSTBUS7_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TSTBUS7 Position  */
#define PPS_RPA1G4R_RPA1G4R_TSTBUS11          (PPS_RPA1G4R_RPA1G4R_TSTBUS11_Val << PPS_RPA1G4R_RPA1G4R_Pos) /* (PPS_RPA1G4R) TSTBUS11 Position  */
#define PPS_RPA1G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA1G4R) Register Mask  */


/* -------- PPS_RPA2G1R : (PPS Offset: 0x210) (R/W 32)  -------- */
#define PPS_RPA2G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA2G1R)   Reset Value */

#define PPS_RPA2G1R_RPA2G1R_Pos               _UINT32_(0)                                          /* (PPS_RPA2G1R) RPA2/G1 Position */
#define PPS_RPA2G1R_RPA2G1R_Msk               (_UINT32_(0x1F) << PPS_RPA2G1R_RPA2G1R_Pos)          /* (PPS_RPA2G1R) RPA2/G1 Mask */
#define PPS_RPA2G1R_RPA2G1R(value)            (PPS_RPA2G1R_RPA2G1R_Msk & (_UINT32_(value) << PPS_RPA2G1R_RPA2G1R_Pos)) /* Assigment of value for RPA2G1R in the PPS_RPA2G1R register */
#define   PPS_RPA2G1R_RPA2G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA2G1R) OFF  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPA2G1R) SERCOM0/PAD3  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPA2G1R) SERCOM0/PAD2  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPA2G1R) SERCOM0/PAD1  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPA2G1R) SERCOM1/PAD0  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPA2G1R) SERCOM1/PAD2  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPA2G1R) SERCOM1/PAD1  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPA2G1R) SERCOM2/PAD0  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPA2G1R) SERCOM2/PAD1  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPA2G1R) SERCOM3/PAD0  */
#define   PPS_RPA2G1R_RPA2G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPA2G1R) SERCOM3/PAD3  */
#define   PPS_RPA2G1R_RPA2G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPA2G1R) TCC0/WO0  */
#define   PPS_RPA2G1R_RPA2G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPA2G1R) TCC0/WO4  */
#define   PPS_RPA2G1R_RPA2G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPA2G1R) TCC0/WO2  */
#define   PPS_RPA2G1R_RPA2G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPA2G1R) TCC1/WO0  */
#define   PPS_RPA2G1R_RPA2G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPA2G1R) TCC1/WO4  */
#define   PPS_RPA2G1R_RPA2G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPA2G1R) TCC1/WO2  */
#define   PPS_RPA2G1R_RPA2G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA2G1R) TCC2/WO0  */
#define   PPS_RPA2G1R_RPA2G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA2G1R) TC0/WO1  */
#define   PPS_RPA2G1R_RPA2G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPA2G1R) REFO1  */
#define   PPS_RPA2G1R_RPA2G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA2G1R) TC1/WO0  */
#define   PPS_RPA2G1R_RPA2G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA2G1R) TC2/WO0  */
#define   PPS_RPA2G1R_RPA2G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA2G1R) TC3/WO0  */
#define   PPS_RPA2G1R_RPA2G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA2G1R) QSCK  */
#define   PPS_RPA2G1R_RPA2G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA2G1R) QCS  */
#define   PPS_RPA2G1R_RPA2G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPA2G1R) QD3  */
#define   PPS_RPA2G1R_RPA2G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPA2G1R) QD2  */
#define   PPS_RPA2G1R_RPA2G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPA2G1R) QD1  */
#define   PPS_RPA2G1R_RPA2G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA2G1R) CCLOUT0  */
#define   PPS_RPA2G1R_RPA2G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPA2G1R) TSTBUS0  */
#define   PPS_RPA2G1R_RPA2G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPA2G1R) TSTBUS4  */
#define   PPS_RPA2G1R_RPA2G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPA2G1R) TSTBUS8  */
#define PPS_RPA2G1R_RPA2G1R_OFF               (PPS_RPA2G1R_RPA2G1R_OFF_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) OFF Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM0P3           (PPS_RPA2G1R_RPA2G1R_SCOM0P3_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM0P2           (PPS_RPA2G1R_RPA2G1R_SCOM0P2_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM0P1           (PPS_RPA2G1R_RPA2G1R_SCOM0P1_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM1P0           (PPS_RPA2G1R_RPA2G1R_SCOM1P0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM1P2           (PPS_RPA2G1R_RPA2G1R_SCOM1P2_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM1P1           (PPS_RPA2G1R_RPA2G1R_SCOM1P1_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM2P0           (PPS_RPA2G1R_RPA2G1R_SCOM2P0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM2P1           (PPS_RPA2G1R_RPA2G1R_SCOM2P1_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM3P0           (PPS_RPA2G1R_RPA2G1R_SCOM3P0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA2G1R_RPA2G1R_SCOM3P3           (PPS_RPA2G1R_RPA2G1R_SCOM3P3_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC0WO0           (PPS_RPA2G1R_RPA2G1R_TCC0WO0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC0/WO0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC0WO4           (PPS_RPA2G1R_RPA2G1R_TCC0WO4_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC0/WO4 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC0WO2           (PPS_RPA2G1R_RPA2G1R_TCC0WO2_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC0/WO2 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC1WO0           (PPS_RPA2G1R_RPA2G1R_TCC1WO0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC1/WO0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC1WO4           (PPS_RPA2G1R_RPA2G1R_TCC1WO4_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC1/WO4 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC1WO2           (PPS_RPA2G1R_RPA2G1R_TCC1WO2_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC1/WO2 Position  */
#define PPS_RPA2G1R_RPA2G1R_TCC2WO0           (PPS_RPA2G1R_RPA2G1R_TCC2WO0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TCC2/WO0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TC0WO1            (PPS_RPA2G1R_RPA2G1R_TC0WO1_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TC0/WO1 Position  */
#define PPS_RPA2G1R_RPA2G1R_REFO1             (PPS_RPA2G1R_RPA2G1R_REFO1_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) REFO1 Position  */
#define PPS_RPA2G1R_RPA2G1R_TC1WO0            (PPS_RPA2G1R_RPA2G1R_TC1WO0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TC1/WO0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TC2WO0            (PPS_RPA2G1R_RPA2G1R_TC2WO0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TC2/WO0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TC3WO0            (PPS_RPA2G1R_RPA2G1R_TC3WO0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TC3/WO0 Position  */
#define PPS_RPA2G1R_RPA2G1R_QSCK              (PPS_RPA2G1R_RPA2G1R_QSCK_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) QSCK Position  */
#define PPS_RPA2G1R_RPA2G1R_QCS               (PPS_RPA2G1R_RPA2G1R_QCS_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) QCS Position  */
#define PPS_RPA2G1R_RPA2G1R_QD3               (PPS_RPA2G1R_RPA2G1R_QD3_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) QD3 Position  */
#define PPS_RPA2G1R_RPA2G1R_QD2               (PPS_RPA2G1R_RPA2G1R_QD2_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) QD2 Position  */
#define PPS_RPA2G1R_RPA2G1R_QD1               (PPS_RPA2G1R_RPA2G1R_QD1_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) QD1 Position  */
#define PPS_RPA2G1R_RPA2G1R_CCLOUT0           (PPS_RPA2G1R_RPA2G1R_CCLOUT0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) CCLOUT0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TSTBUS0           (PPS_RPA2G1R_RPA2G1R_TSTBUS0_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TSTBUS0 Position  */
#define PPS_RPA2G1R_RPA2G1R_TSTBUS4           (PPS_RPA2G1R_RPA2G1R_TSTBUS4_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TSTBUS4 Position  */
#define PPS_RPA2G1R_RPA2G1R_TSTBUS8           (PPS_RPA2G1R_RPA2G1R_TSTBUS8_Val << PPS_RPA2G1R_RPA2G1R_Pos) /* (PPS_RPA2G1R) TSTBUS8 Position  */
#define PPS_RPA2G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA2G1R) Register Mask  */


/* -------- PPS_RPA2G4R : (PPS Offset: 0x214) (R/W 32)  -------- */
#define PPS_RPA2G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA2G4R)   Reset Value */

#define PPS_RPA2G4R_RPA2G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA2G4R) RPA2/G4 Position */
#define PPS_RPA2G4R_RPA2G4R_Msk               (_UINT32_(0x1F) << PPS_RPA2G4R_RPA2G4R_Pos)          /* (PPS_RPA2G4R) RPA2/G4 Mask */
#define PPS_RPA2G4R_RPA2G4R(value)            (PPS_RPA2G4R_RPA2G4R_Msk & (_UINT32_(value) << PPS_RPA2G4R_RPA2G4R_Pos)) /* Assigment of value for RPA2G4R in the PPS_RPA2G4R register */
#define   PPS_RPA2G4R_RPA2G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA2G4R) OFF  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA2G4R) SERCOM0/PAD2  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA2G4R) SERCOM0/PAD1  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA2G4R) SERCOM0/PAD0  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA2G4R) SERCOM1/PAD3  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA2G4R) SERCOM1/PAD1  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA2G4R) SERCOM1/PAD0  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA2G4R) SERCOM2/PAD3  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA2G4R) SERCOM2/PAD0  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA2G4R) SERCOM3/PAD3  */
#define   PPS_RPA2G4R_RPA2G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA2G4R) SERCOM3/PAD2  */
#define   PPS_RPA2G4R_RPA2G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA2G4R) TCC0/WO3  */
#define   PPS_RPA2G4R_RPA2G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA2G4R) TCC0/WO1  */
#define   PPS_RPA2G4R_RPA2G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA2G4R) TCC0/WO5  */
#define   PPS_RPA2G4R_RPA2G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA2G4R) TCC1/WO3  */
#define   PPS_RPA2G4R_RPA2G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA2G4R) TCC1/WO1  */
#define   PPS_RPA2G4R_RPA2G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA2G4R) TCC1/WO5  */
#define   PPS_RPA2G4R_RPA2G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA2G4R) TCC2/WO1  */
#define   PPS_RPA2G4R_RPA2G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA2G4R) TC0/WO0  */
#define   PPS_RPA2G4R_RPA2G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA2G4R) REFO4  */
#define   PPS_RPA2G4R_RPA2G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA2G4R) TC1/WO1  */
#define   PPS_RPA2G4R_RPA2G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA2G4R) TC2/WO1  */
#define   PPS_RPA2G4R_RPA2G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA2G4R) TC3/WO1  */
#define   PPS_RPA2G4R_RPA2G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA2G4R) QSCK  */
#define   PPS_RPA2G4R_RPA2G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA2G4R) QCS  */
#define   PPS_RPA2G4R_RPA2G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA2G4R) QD2  */
#define   PPS_RPA2G4R_RPA2G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA2G4R) QD1  */
#define   PPS_RPA2G4R_RPA2G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA2G4R) QD0  */
#define   PPS_RPA2G4R_RPA2G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA2G4R) CCLOUT1  */
#define   PPS_RPA2G4R_RPA2G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA2G4R) TSTBUS3  */
#define   PPS_RPA2G4R_RPA2G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA2G4R) TSTBUS7  */
#define   PPS_RPA2G4R_RPA2G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA2G4R) TSTBUS11  */
#define PPS_RPA2G4R_RPA2G4R_OFF               (PPS_RPA2G4R_RPA2G4R_OFF_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) OFF Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM0P2           (PPS_RPA2G4R_RPA2G4R_SCOM0P2_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM0P1           (PPS_RPA2G4R_RPA2G4R_SCOM0P1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM0P0           (PPS_RPA2G4R_RPA2G4R_SCOM0P0_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM1P3           (PPS_RPA2G4R_RPA2G4R_SCOM1P3_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM1P1           (PPS_RPA2G4R_RPA2G4R_SCOM1P1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM1P0           (PPS_RPA2G4R_RPA2G4R_SCOM1P0_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM2P3           (PPS_RPA2G4R_RPA2G4R_SCOM2P3_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM2P0           (PPS_RPA2G4R_RPA2G4R_SCOM2P0_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM3P3           (PPS_RPA2G4R_RPA2G4R_SCOM3P3_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA2G4R_RPA2G4R_SCOM3P2           (PPS_RPA2G4R_RPA2G4R_SCOM3P2_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC0WO3           (PPS_RPA2G4R_RPA2G4R_TCC0WO3_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC0/WO3 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC0WO1           (PPS_RPA2G4R_RPA2G4R_TCC0WO1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC0/WO1 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC0WO5           (PPS_RPA2G4R_RPA2G4R_TCC0WO5_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC0/WO5 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC1WO3           (PPS_RPA2G4R_RPA2G4R_TCC1WO3_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC1/WO3 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC1WO1           (PPS_RPA2G4R_RPA2G4R_TCC1WO1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC1/WO1 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC1WO5           (PPS_RPA2G4R_RPA2G4R_TCC1WO5_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC1/WO5 Position  */
#define PPS_RPA2G4R_RPA2G4R_TCC2WO1           (PPS_RPA2G4R_RPA2G4R_TCC2WO1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TCC2/WO1 Position  */
#define PPS_RPA2G4R_RPA2G4R_TC0WO0            (PPS_RPA2G4R_RPA2G4R_TC0WO0_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TC0/WO0 Position  */
#define PPS_RPA2G4R_RPA2G4R_REFO4             (PPS_RPA2G4R_RPA2G4R_REFO4_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) REFO4 Position  */
#define PPS_RPA2G4R_RPA2G4R_TC1WO1            (PPS_RPA2G4R_RPA2G4R_TC1WO1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TC1/WO1 Position  */
#define PPS_RPA2G4R_RPA2G4R_TC2WO1            (PPS_RPA2G4R_RPA2G4R_TC2WO1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TC2/WO1 Position  */
#define PPS_RPA2G4R_RPA2G4R_TC3WO1            (PPS_RPA2G4R_RPA2G4R_TC3WO1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TC3/WO1 Position  */
#define PPS_RPA2G4R_RPA2G4R_QSCK              (PPS_RPA2G4R_RPA2G4R_QSCK_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) QSCK Position  */
#define PPS_RPA2G4R_RPA2G4R_QCS               (PPS_RPA2G4R_RPA2G4R_QCS_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) QCS Position  */
#define PPS_RPA2G4R_RPA2G4R_QD2               (PPS_RPA2G4R_RPA2G4R_QD2_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) QD2 Position  */
#define PPS_RPA2G4R_RPA2G4R_QD1               (PPS_RPA2G4R_RPA2G4R_QD1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) QD1 Position  */
#define PPS_RPA2G4R_RPA2G4R_QD0               (PPS_RPA2G4R_RPA2G4R_QD0_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) QD0 Position  */
#define PPS_RPA2G4R_RPA2G4R_CCLOUT1           (PPS_RPA2G4R_RPA2G4R_CCLOUT1_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) CCLOUT1 Position  */
#define PPS_RPA2G4R_RPA2G4R_TSTBUS3           (PPS_RPA2G4R_RPA2G4R_TSTBUS3_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TSTBUS3 Position  */
#define PPS_RPA2G4R_RPA2G4R_TSTBUS7           (PPS_RPA2G4R_RPA2G4R_TSTBUS7_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TSTBUS7 Position  */
#define PPS_RPA2G4R_RPA2G4R_TSTBUS11          (PPS_RPA2G4R_RPA2G4R_TSTBUS11_Val << PPS_RPA2G4R_RPA2G4R_Pos) /* (PPS_RPA2G4R) TSTBUS11 Position  */
#define PPS_RPA2G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA2G4R) Register Mask  */


/* -------- PPS_RPA3G1R : (PPS Offset: 0x218) (R/W 32)  -------- */
#define PPS_RPA3G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA3G1R)   Reset Value */

#define PPS_RPA3G1R_RPA3G1R_Pos               _UINT32_(0)                                          /* (PPS_RPA3G1R) RPA3/G1 Position */
#define PPS_RPA3G1R_RPA3G1R_Msk               (_UINT32_(0x1F) << PPS_RPA3G1R_RPA3G1R_Pos)          /* (PPS_RPA3G1R) RPA3/G1 Mask */
#define PPS_RPA3G1R_RPA3G1R(value)            (PPS_RPA3G1R_RPA3G1R_Msk & (_UINT32_(value) << PPS_RPA3G1R_RPA3G1R_Pos)) /* Assigment of value for RPA3G1R in the PPS_RPA3G1R register */
#define   PPS_RPA3G1R_RPA3G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA3G1R) OFF  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPA3G1R) SERCOM0/PAD3  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPA3G1R) SERCOM0/PAD2  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPA3G1R) SERCOM0/PAD1  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPA3G1R) SERCOM1/PAD0  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPA3G1R) SERCOM1/PAD2  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPA3G1R) SERCOM1/PAD1  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPA3G1R) SERCOM2/PAD0  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPA3G1R) SERCOM2/PAD1  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPA3G1R) SERCOM3/PAD0  */
#define   PPS_RPA3G1R_RPA3G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPA3G1R) SERCOM3/PAD3  */
#define   PPS_RPA3G1R_RPA3G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPA3G1R) TCC0/WO0  */
#define   PPS_RPA3G1R_RPA3G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPA3G1R) TCC0/WO4  */
#define   PPS_RPA3G1R_RPA3G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPA3G1R) TCC0/WO2  */
#define   PPS_RPA3G1R_RPA3G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPA3G1R) TCC1/WO0  */
#define   PPS_RPA3G1R_RPA3G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPA3G1R) TCC1/WO4  */
#define   PPS_RPA3G1R_RPA3G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPA3G1R) TCC1/WO2  */
#define   PPS_RPA3G1R_RPA3G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA3G1R) TCC2/WO0  */
#define   PPS_RPA3G1R_RPA3G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA3G1R) TC0/WO1  */
#define   PPS_RPA3G1R_RPA3G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPA3G1R) REFO1  */
#define   PPS_RPA3G1R_RPA3G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA3G1R) TC1/WO0  */
#define   PPS_RPA3G1R_RPA3G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA3G1R) TC2/WO0  */
#define   PPS_RPA3G1R_RPA3G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA3G1R) TC3/WO0  */
#define   PPS_RPA3G1R_RPA3G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA3G1R) QSCK  */
#define   PPS_RPA3G1R_RPA3G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA3G1R) QCS  */
#define   PPS_RPA3G1R_RPA3G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPA3G1R) QD3  */
#define   PPS_RPA3G1R_RPA3G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPA3G1R) QD2  */
#define   PPS_RPA3G1R_RPA3G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPA3G1R) QD1  */
#define   PPS_RPA3G1R_RPA3G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA3G1R) CCLOUT0  */
#define   PPS_RPA3G1R_RPA3G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPA3G1R) TSTBUS0  */
#define   PPS_RPA3G1R_RPA3G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPA3G1R) TSTBUS4  */
#define   PPS_RPA3G1R_RPA3G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPA3G1R) TSTBUS8  */
#define PPS_RPA3G1R_RPA3G1R_OFF               (PPS_RPA3G1R_RPA3G1R_OFF_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) OFF Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM0P3           (PPS_RPA3G1R_RPA3G1R_SCOM0P3_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM0P2           (PPS_RPA3G1R_RPA3G1R_SCOM0P2_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM0P1           (PPS_RPA3G1R_RPA3G1R_SCOM0P1_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM1P0           (PPS_RPA3G1R_RPA3G1R_SCOM1P0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM1P2           (PPS_RPA3G1R_RPA3G1R_SCOM1P2_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM1P1           (PPS_RPA3G1R_RPA3G1R_SCOM1P1_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM2P0           (PPS_RPA3G1R_RPA3G1R_SCOM2P0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM2P1           (PPS_RPA3G1R_RPA3G1R_SCOM2P1_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM3P0           (PPS_RPA3G1R_RPA3G1R_SCOM3P0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA3G1R_RPA3G1R_SCOM3P3           (PPS_RPA3G1R_RPA3G1R_SCOM3P3_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC0WO0           (PPS_RPA3G1R_RPA3G1R_TCC0WO0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC0/WO0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC0WO4           (PPS_RPA3G1R_RPA3G1R_TCC0WO4_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC0/WO4 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC0WO2           (PPS_RPA3G1R_RPA3G1R_TCC0WO2_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC0/WO2 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC1WO0           (PPS_RPA3G1R_RPA3G1R_TCC1WO0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC1/WO0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC1WO4           (PPS_RPA3G1R_RPA3G1R_TCC1WO4_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC1/WO4 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC1WO2           (PPS_RPA3G1R_RPA3G1R_TCC1WO2_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC1/WO2 Position  */
#define PPS_RPA3G1R_RPA3G1R_TCC2WO0           (PPS_RPA3G1R_RPA3G1R_TCC2WO0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TCC2/WO0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TC0WO1            (PPS_RPA3G1R_RPA3G1R_TC0WO1_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TC0/WO1 Position  */
#define PPS_RPA3G1R_RPA3G1R_REFO1             (PPS_RPA3G1R_RPA3G1R_REFO1_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) REFO1 Position  */
#define PPS_RPA3G1R_RPA3G1R_TC1WO0            (PPS_RPA3G1R_RPA3G1R_TC1WO0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TC1/WO0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TC2WO0            (PPS_RPA3G1R_RPA3G1R_TC2WO0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TC2/WO0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TC3WO0            (PPS_RPA3G1R_RPA3G1R_TC3WO0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TC3/WO0 Position  */
#define PPS_RPA3G1R_RPA3G1R_QSCK              (PPS_RPA3G1R_RPA3G1R_QSCK_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) QSCK Position  */
#define PPS_RPA3G1R_RPA3G1R_QCS               (PPS_RPA3G1R_RPA3G1R_QCS_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) QCS Position  */
#define PPS_RPA3G1R_RPA3G1R_QD3               (PPS_RPA3G1R_RPA3G1R_QD3_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) QD3 Position  */
#define PPS_RPA3G1R_RPA3G1R_QD2               (PPS_RPA3G1R_RPA3G1R_QD2_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) QD2 Position  */
#define PPS_RPA3G1R_RPA3G1R_QD1               (PPS_RPA3G1R_RPA3G1R_QD1_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) QD1 Position  */
#define PPS_RPA3G1R_RPA3G1R_CCLOUT0           (PPS_RPA3G1R_RPA3G1R_CCLOUT0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) CCLOUT0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TSTBUS0           (PPS_RPA3G1R_RPA3G1R_TSTBUS0_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TSTBUS0 Position  */
#define PPS_RPA3G1R_RPA3G1R_TSTBUS4           (PPS_RPA3G1R_RPA3G1R_TSTBUS4_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TSTBUS4 Position  */
#define PPS_RPA3G1R_RPA3G1R_TSTBUS8           (PPS_RPA3G1R_RPA3G1R_TSTBUS8_Val << PPS_RPA3G1R_RPA3G1R_Pos) /* (PPS_RPA3G1R) TSTBUS8 Position  */
#define PPS_RPA3G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA3G1R) Register Mask  */


/* -------- PPS_RPA3G2R : (PPS Offset: 0x21C) (R/W 32)  -------- */
#define PPS_RPA3G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA3G2R)   Reset Value */

#define PPS_RPA3G2R_RPA3G2R_Pos               _UINT32_(0)                                          /* (PPS_RPA3G2R) RPA3/G2 Position */
#define PPS_RPA3G2R_RPA3G2R_Msk               (_UINT32_(0x1F) << PPS_RPA3G2R_RPA3G2R_Pos)          /* (PPS_RPA3G2R) RPA3/G2 Mask */
#define PPS_RPA3G2R_RPA3G2R(value)            (PPS_RPA3G2R_RPA3G2R_Msk & (_UINT32_(value) << PPS_RPA3G2R_RPA3G2R_Pos)) /* Assigment of value for RPA3G2R in the PPS_RPA3G2R register */
#define   PPS_RPA3G2R_RPA3G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA3G2R) OFF  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPA3G2R) SERCOM0/PAD0  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPA3G2R) SERCOM0/PAD3  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPA3G2R) SERCOM0/PAD2  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPA3G2R) SERCOM1/PAD1  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPA3G2R) SERCOM1/PAD3  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPA3G2R) SERCOM1/PAD2  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPA3G2R) SERCOM2/PAD1  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPA3G2R) SERCOM2/PAD2  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPA3G2R) SERCOM3/PAD1  */
#define   PPS_RPA3G2R_RPA3G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPA3G2R) SERCOM3/PAD0  */
#define   PPS_RPA3G2R_RPA3G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPA3G2R) TCC0/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPA3G2R) TCC0/WO5  */
#define   PPS_RPA3G2R_RPA3G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPA3G2R) TCC0/WO3  */
#define   PPS_RPA3G2R_RPA3G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPA3G2R) TCC1/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPA3G2R) TCC1/WO5  */
#define   PPS_RPA3G2R_RPA3G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPA3G2R) TCC1/WO3  */
#define   PPS_RPA3G2R_RPA3G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA3G2R) TCC2/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA3G2R) TC0/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPA3G2R) REFO2  */
#define   PPS_RPA3G2R_RPA3G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA3G2R) TC1/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA3G2R) TC2/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA3G2R) TC3/WO1  */
#define   PPS_RPA3G2R_RPA3G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA3G2R) QSCK  */
#define   PPS_RPA3G2R_RPA3G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA3G2R) QCS  */
#define   PPS_RPA3G2R_RPA3G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPA3G2R) QD0  */
#define   PPS_RPA3G2R_RPA3G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPA3G2R) QD3  */
#define   PPS_RPA3G2R_RPA3G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPA3G2R) QD2  */
#define   PPS_RPA3G2R_RPA3G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA3G2R) CCLOUT1  */
#define   PPS_RPA3G2R_RPA3G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPA3G2R) TSTBUS1  */
#define   PPS_RPA3G2R_RPA3G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPA3G2R) TSTBUS5  */
#define   PPS_RPA3G2R_RPA3G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPA3G2R) TSTBUS9  */
#define PPS_RPA3G2R_RPA3G2R_OFF               (PPS_RPA3G2R_RPA3G2R_OFF_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) OFF Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM0P0           (PPS_RPA3G2R_RPA3G2R_SCOM0P0_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM0/PAD0 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM0P3           (PPS_RPA3G2R_RPA3G2R_SCOM0P3_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM0/PAD3 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM0P2           (PPS_RPA3G2R_RPA3G2R_SCOM0P2_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM0/PAD2 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM1P1           (PPS_RPA3G2R_RPA3G2R_SCOM1P1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM1/PAD1 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM1P3           (PPS_RPA3G2R_RPA3G2R_SCOM1P3_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM1/PAD3 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM1P2           (PPS_RPA3G2R_RPA3G2R_SCOM1P2_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM1/PAD2 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM2P1           (PPS_RPA3G2R_RPA3G2R_SCOM2P1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM2/PAD1 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM2P2           (PPS_RPA3G2R_RPA3G2R_SCOM2P2_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM2/PAD2 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM3P1           (PPS_RPA3G2R_RPA3G2R_SCOM3P1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM3/PAD1 Position  */
#define PPS_RPA3G2R_RPA3G2R_SCOM3P0           (PPS_RPA3G2R_RPA3G2R_SCOM3P0_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) SERCOM3/PAD0 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC0WO1           (PPS_RPA3G2R_RPA3G2R_TCC0WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC0/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC0WO5           (PPS_RPA3G2R_RPA3G2R_TCC0WO5_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC0/WO5 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC0WO3           (PPS_RPA3G2R_RPA3G2R_TCC0WO3_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC0/WO3 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC1WO1           (PPS_RPA3G2R_RPA3G2R_TCC1WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC1/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC1WO5           (PPS_RPA3G2R_RPA3G2R_TCC1WO5_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC1/WO5 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC1WO3           (PPS_RPA3G2R_RPA3G2R_TCC1WO3_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC1/WO3 Position  */
#define PPS_RPA3G2R_RPA3G2R_TCC2WO1           (PPS_RPA3G2R_RPA3G2R_TCC2WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TCC2/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TC0WO1            (PPS_RPA3G2R_RPA3G2R_TC0WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TC0/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_REFO2             (PPS_RPA3G2R_RPA3G2R_REFO2_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) REFO2 Position  */
#define PPS_RPA3G2R_RPA3G2R_TC1WO1            (PPS_RPA3G2R_RPA3G2R_TC1WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TC1/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TC2WO1            (PPS_RPA3G2R_RPA3G2R_TC2WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TC2/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TC3WO1            (PPS_RPA3G2R_RPA3G2R_TC3WO1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TC3/WO1 Position  */
#define PPS_RPA3G2R_RPA3G2R_QSCK              (PPS_RPA3G2R_RPA3G2R_QSCK_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) QSCK Position  */
#define PPS_RPA3G2R_RPA3G2R_QCS               (PPS_RPA3G2R_RPA3G2R_QCS_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) QCS Position  */
#define PPS_RPA3G2R_RPA3G2R_QD0               (PPS_RPA3G2R_RPA3G2R_QD0_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) QD0 Position  */
#define PPS_RPA3G2R_RPA3G2R_QD3               (PPS_RPA3G2R_RPA3G2R_QD3_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) QD3 Position  */
#define PPS_RPA3G2R_RPA3G2R_QD2               (PPS_RPA3G2R_RPA3G2R_QD2_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) QD2 Position  */
#define PPS_RPA3G2R_RPA3G2R_CCLOUT1           (PPS_RPA3G2R_RPA3G2R_CCLOUT1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) CCLOUT1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TSTBUS1           (PPS_RPA3G2R_RPA3G2R_TSTBUS1_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TSTBUS1 Position  */
#define PPS_RPA3G2R_RPA3G2R_TSTBUS5           (PPS_RPA3G2R_RPA3G2R_TSTBUS5_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TSTBUS5 Position  */
#define PPS_RPA3G2R_RPA3G2R_TSTBUS9           (PPS_RPA3G2R_RPA3G2R_TSTBUS9_Val << PPS_RPA3G2R_RPA3G2R_Pos) /* (PPS_RPA3G2R) TSTBUS9 Position  */
#define PPS_RPA3G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA3G2R) Register Mask  */


/* -------- PPS_RPA3G3R : (PPS Offset: 0x220) (R/W 32)  -------- */
#define PPS_RPA3G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA3G3R)   Reset Value */

#define PPS_RPA3G3R_RPA3G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA3G3R) RPA3/G3 Position */
#define PPS_RPA3G3R_RPA3G3R_Msk               (_UINT32_(0x1F) << PPS_RPA3G3R_RPA3G3R_Pos)          /* (PPS_RPA3G3R) RPA3/G3 Mask */
#define PPS_RPA3G3R_RPA3G3R(value)            (PPS_RPA3G3R_RPA3G3R_Msk & (_UINT32_(value) << PPS_RPA3G3R_RPA3G3R_Pos)) /* Assigment of value for RPA3G3R in the PPS_RPA3G3R register */
#define   PPS_RPA3G3R_RPA3G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA3G3R) OFF  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA3G3R) SERCOM0/PAD1  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA3G3R) SERCOM0/PAD0  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA3G3R) SERCOM0/PAD3  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA3G3R) SERCOM1/PAD2  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA3G3R) SERCOM1/PAD0  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA3G3R) SERCOM1/PAD3  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA3G3R) SERCOM2/PAD2  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA3G3R) SERCOM2/PAD3  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA3G3R) SERCOM3/PAD2  */
#define   PPS_RPA3G3R_RPA3G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA3G3R) SERCOM3/PAD1  */
#define   PPS_RPA3G3R_RPA3G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA3G3R) TCC0/WO2  */
#define   PPS_RPA3G3R_RPA3G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA3G3R) TCC0/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA3G3R) TCC0/WO4  */
#define   PPS_RPA3G3R_RPA3G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA3G3R) TCC1/WO2  */
#define   PPS_RPA3G3R_RPA3G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA3G3R) TCC1/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA3G3R) TCC1/WO4  */
#define   PPS_RPA3G3R_RPA3G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA3G3R) TCC2/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA3G3R) TC0/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA3G3R) REFO3  */
#define   PPS_RPA3G3R_RPA3G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA3G3R) TC1/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA3G3R) TC2/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA3G3R) TC3/WO0  */
#define   PPS_RPA3G3R_RPA3G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA3G3R) QSCK  */
#define   PPS_RPA3G3R_RPA3G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA3G3R) QCS  */
#define   PPS_RPA3G3R_RPA3G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA3G3R) QD1  */
#define   PPS_RPA3G3R_RPA3G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA3G3R) QD0  */
#define   PPS_RPA3G3R_RPA3G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA3G3R) QD3  */
#define   PPS_RPA3G3R_RPA3G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA3G3R) CCLOUT0  */
#define   PPS_RPA3G3R_RPA3G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA3G3R) TSTBUS2  */
#define   PPS_RPA3G3R_RPA3G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA3G3R) TSTBUS6  */
#define   PPS_RPA3G3R_RPA3G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA3G3R) TSTBUS10  */
#define PPS_RPA3G3R_RPA3G3R_OFF               (PPS_RPA3G3R_RPA3G3R_OFF_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) OFF Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM0P1           (PPS_RPA3G3R_RPA3G3R_SCOM0P1_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM0P0           (PPS_RPA3G3R_RPA3G3R_SCOM0P0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM0P3           (PPS_RPA3G3R_RPA3G3R_SCOM0P3_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM1P2           (PPS_RPA3G3R_RPA3G3R_SCOM1P2_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM1P0           (PPS_RPA3G3R_RPA3G3R_SCOM1P0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM1P3           (PPS_RPA3G3R_RPA3G3R_SCOM1P3_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM2P2           (PPS_RPA3G3R_RPA3G3R_SCOM2P2_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM2P3           (PPS_RPA3G3R_RPA3G3R_SCOM2P3_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM3P2           (PPS_RPA3G3R_RPA3G3R_SCOM3P2_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA3G3R_RPA3G3R_SCOM3P1           (PPS_RPA3G3R_RPA3G3R_SCOM3P1_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC0WO2           (PPS_RPA3G3R_RPA3G3R_TCC0WO2_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC0/WO2 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC0WO0           (PPS_RPA3G3R_RPA3G3R_TCC0WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC0/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC0WO4           (PPS_RPA3G3R_RPA3G3R_TCC0WO4_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC0/WO4 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC1WO2           (PPS_RPA3G3R_RPA3G3R_TCC1WO2_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC1/WO2 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC1WO0           (PPS_RPA3G3R_RPA3G3R_TCC1WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC1/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC1WO4           (PPS_RPA3G3R_RPA3G3R_TCC1WO4_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC1/WO4 Position  */
#define PPS_RPA3G3R_RPA3G3R_TCC2WO0           (PPS_RPA3G3R_RPA3G3R_TCC2WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TCC2/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_TC0WO0            (PPS_RPA3G3R_RPA3G3R_TC0WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TC0/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_REFO3             (PPS_RPA3G3R_RPA3G3R_REFO3_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) REFO3 Position  */
#define PPS_RPA3G3R_RPA3G3R_TC1WO0            (PPS_RPA3G3R_RPA3G3R_TC1WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TC1/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_TC2WO0            (PPS_RPA3G3R_RPA3G3R_TC2WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TC2/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_TC3WO0            (PPS_RPA3G3R_RPA3G3R_TC3WO0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TC3/WO0 Position  */
#define PPS_RPA3G3R_RPA3G3R_QSCK              (PPS_RPA3G3R_RPA3G3R_QSCK_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) QSCK Position  */
#define PPS_RPA3G3R_RPA3G3R_QCS               (PPS_RPA3G3R_RPA3G3R_QCS_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) QCS Position  */
#define PPS_RPA3G3R_RPA3G3R_QD1               (PPS_RPA3G3R_RPA3G3R_QD1_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) QD1 Position  */
#define PPS_RPA3G3R_RPA3G3R_QD0               (PPS_RPA3G3R_RPA3G3R_QD0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) QD0 Position  */
#define PPS_RPA3G3R_RPA3G3R_QD3               (PPS_RPA3G3R_RPA3G3R_QD3_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) QD3 Position  */
#define PPS_RPA3G3R_RPA3G3R_CCLOUT0           (PPS_RPA3G3R_RPA3G3R_CCLOUT0_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) CCLOUT0 Position  */
#define PPS_RPA3G3R_RPA3G3R_TSTBUS2           (PPS_RPA3G3R_RPA3G3R_TSTBUS2_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TSTBUS2 Position  */
#define PPS_RPA3G3R_RPA3G3R_TSTBUS6           (PPS_RPA3G3R_RPA3G3R_TSTBUS6_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TSTBUS6 Position  */
#define PPS_RPA3G3R_RPA3G3R_TSTBUS10          (PPS_RPA3G3R_RPA3G3R_TSTBUS10_Val << PPS_RPA3G3R_RPA3G3R_Pos) /* (PPS_RPA3G3R) TSTBUS10 Position  */
#define PPS_RPA3G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA3G3R) Register Mask  */


/* -------- PPS_RPA4G2R : (PPS Offset: 0x224) (R/W 32)  -------- */
#define PPS_RPA4G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA4G2R)   Reset Value */

#define PPS_RPA4G2R_RPA4G2R_Pos               _UINT32_(0)                                          /* (PPS_RPA4G2R) RPA4/G2 Position */
#define PPS_RPA4G2R_RPA4G2R_Msk               (_UINT32_(0x1F) << PPS_RPA4G2R_RPA4G2R_Pos)          /* (PPS_RPA4G2R) RPA4/G2 Mask */
#define PPS_RPA4G2R_RPA4G2R(value)            (PPS_RPA4G2R_RPA4G2R_Msk & (_UINT32_(value) << PPS_RPA4G2R_RPA4G2R_Pos)) /* Assigment of value for RPA4G2R in the PPS_RPA4G2R register */
#define   PPS_RPA4G2R_RPA4G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA4G2R) OFF  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPA4G2R) SERCOM0/PAD0  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPA4G2R) SERCOM0/PAD3  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPA4G2R) SERCOM0/PAD2  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPA4G2R) SERCOM1/PAD1  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPA4G2R) SERCOM1/PAD3  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPA4G2R) SERCOM1/PAD2  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPA4G2R) SERCOM2/PAD1  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPA4G2R) SERCOM2/PAD2  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPA4G2R) SERCOM3/PAD1  */
#define   PPS_RPA4G2R_RPA4G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPA4G2R) SERCOM3/PAD0  */
#define   PPS_RPA4G2R_RPA4G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPA4G2R) TCC0/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPA4G2R) TCC0/WO5  */
#define   PPS_RPA4G2R_RPA4G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPA4G2R) TCC0/WO3  */
#define   PPS_RPA4G2R_RPA4G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPA4G2R) TCC1/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPA4G2R) TCC1/WO5  */
#define   PPS_RPA4G2R_RPA4G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPA4G2R) TCC1/WO3  */
#define   PPS_RPA4G2R_RPA4G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA4G2R) TCC2/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA4G2R) TC0/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPA4G2R) REFO2  */
#define   PPS_RPA4G2R_RPA4G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA4G2R) TC1/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA4G2R) TC2/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA4G2R) TC3/WO1  */
#define   PPS_RPA4G2R_RPA4G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA4G2R) QSCK  */
#define   PPS_RPA4G2R_RPA4G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA4G2R) QCS  */
#define   PPS_RPA4G2R_RPA4G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPA4G2R) QD0  */
#define   PPS_RPA4G2R_RPA4G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPA4G2R) QD3  */
#define   PPS_RPA4G2R_RPA4G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPA4G2R) QD2  */
#define   PPS_RPA4G2R_RPA4G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA4G2R) CCLOUT1  */
#define   PPS_RPA4G2R_RPA4G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPA4G2R) TSTBUS1  */
#define   PPS_RPA4G2R_RPA4G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPA4G2R) TSTBUS5  */
#define   PPS_RPA4G2R_RPA4G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPA4G2R) TSTBUS9  */
#define PPS_RPA4G2R_RPA4G2R_OFF               (PPS_RPA4G2R_RPA4G2R_OFF_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) OFF Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM0P0           (PPS_RPA4G2R_RPA4G2R_SCOM0P0_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM0/PAD0 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM0P3           (PPS_RPA4G2R_RPA4G2R_SCOM0P3_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM0/PAD3 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM0P2           (PPS_RPA4G2R_RPA4G2R_SCOM0P2_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM0/PAD2 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM1P1           (PPS_RPA4G2R_RPA4G2R_SCOM1P1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM1/PAD1 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM1P3           (PPS_RPA4G2R_RPA4G2R_SCOM1P3_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM1/PAD3 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM1P2           (PPS_RPA4G2R_RPA4G2R_SCOM1P2_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM1/PAD2 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM2P1           (PPS_RPA4G2R_RPA4G2R_SCOM2P1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM2/PAD1 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM2P2           (PPS_RPA4G2R_RPA4G2R_SCOM2P2_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM2/PAD2 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM3P1           (PPS_RPA4G2R_RPA4G2R_SCOM3P1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM3/PAD1 Position  */
#define PPS_RPA4G2R_RPA4G2R_SCOM3P0           (PPS_RPA4G2R_RPA4G2R_SCOM3P0_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) SERCOM3/PAD0 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC0WO1           (PPS_RPA4G2R_RPA4G2R_TCC0WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC0/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC0WO5           (PPS_RPA4G2R_RPA4G2R_TCC0WO5_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC0/WO5 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC0WO3           (PPS_RPA4G2R_RPA4G2R_TCC0WO3_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC0/WO3 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC1WO1           (PPS_RPA4G2R_RPA4G2R_TCC1WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC1/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC1WO5           (PPS_RPA4G2R_RPA4G2R_TCC1WO5_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC1/WO5 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC1WO3           (PPS_RPA4G2R_RPA4G2R_TCC1WO3_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC1/WO3 Position  */
#define PPS_RPA4G2R_RPA4G2R_TCC2WO1           (PPS_RPA4G2R_RPA4G2R_TCC2WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TCC2/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TC0WO1            (PPS_RPA4G2R_RPA4G2R_TC0WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TC0/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_REFO2             (PPS_RPA4G2R_RPA4G2R_REFO2_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) REFO2 Position  */
#define PPS_RPA4G2R_RPA4G2R_TC1WO1            (PPS_RPA4G2R_RPA4G2R_TC1WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TC1/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TC2WO1            (PPS_RPA4G2R_RPA4G2R_TC2WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TC2/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TC3WO1            (PPS_RPA4G2R_RPA4G2R_TC3WO1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TC3/WO1 Position  */
#define PPS_RPA4G2R_RPA4G2R_QSCK              (PPS_RPA4G2R_RPA4G2R_QSCK_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) QSCK Position  */
#define PPS_RPA4G2R_RPA4G2R_QCS               (PPS_RPA4G2R_RPA4G2R_QCS_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) QCS Position  */
#define PPS_RPA4G2R_RPA4G2R_QD0               (PPS_RPA4G2R_RPA4G2R_QD0_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) QD0 Position  */
#define PPS_RPA4G2R_RPA4G2R_QD3               (PPS_RPA4G2R_RPA4G2R_QD3_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) QD3 Position  */
#define PPS_RPA4G2R_RPA4G2R_QD2               (PPS_RPA4G2R_RPA4G2R_QD2_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) QD2 Position  */
#define PPS_RPA4G2R_RPA4G2R_CCLOUT1           (PPS_RPA4G2R_RPA4G2R_CCLOUT1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) CCLOUT1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TSTBUS1           (PPS_RPA4G2R_RPA4G2R_TSTBUS1_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TSTBUS1 Position  */
#define PPS_RPA4G2R_RPA4G2R_TSTBUS5           (PPS_RPA4G2R_RPA4G2R_TSTBUS5_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TSTBUS5 Position  */
#define PPS_RPA4G2R_RPA4G2R_TSTBUS9           (PPS_RPA4G2R_RPA4G2R_TSTBUS9_Val << PPS_RPA4G2R_RPA4G2R_Pos) /* (PPS_RPA4G2R) TSTBUS9 Position  */
#define PPS_RPA4G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA4G2R) Register Mask  */


/* -------- PPS_RPA4G3R : (PPS Offset: 0x228) (R/W 32)  -------- */
#define PPS_RPA4G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA4G3R)   Reset Value */

#define PPS_RPA4G3R_RPA4G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA4G3R) RPA4/G3 Position */
#define PPS_RPA4G3R_RPA4G3R_Msk               (_UINT32_(0x1F) << PPS_RPA4G3R_RPA4G3R_Pos)          /* (PPS_RPA4G3R) RPA4/G3 Mask */
#define PPS_RPA4G3R_RPA4G3R(value)            (PPS_RPA4G3R_RPA4G3R_Msk & (_UINT32_(value) << PPS_RPA4G3R_RPA4G3R_Pos)) /* Assigment of value for RPA4G3R in the PPS_RPA4G3R register */
#define   PPS_RPA4G3R_RPA4G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA4G3R) OFF  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA4G3R) SERCOM0/PAD1  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA4G3R) SERCOM0/PAD0  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA4G3R) SERCOM0/PAD3  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA4G3R) SERCOM1/PAD2  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA4G3R) SERCOM1/PAD0  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA4G3R) SERCOM1/PAD3  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA4G3R) SERCOM2/PAD2  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA4G3R) SERCOM2/PAD3  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA4G3R) SERCOM3/PAD2  */
#define   PPS_RPA4G3R_RPA4G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA4G3R) SERCOM3/PAD1  */
#define   PPS_RPA4G3R_RPA4G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA4G3R) TCC0/WO2  */
#define   PPS_RPA4G3R_RPA4G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA4G3R) TCC0/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA4G3R) TCC0/WO4  */
#define   PPS_RPA4G3R_RPA4G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA4G3R) TCC1/WO2  */
#define   PPS_RPA4G3R_RPA4G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA4G3R) TCC1/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA4G3R) TCC1/WO4  */
#define   PPS_RPA4G3R_RPA4G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA4G3R) TCC2/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA4G3R) TC0/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA4G3R) REFO3  */
#define   PPS_RPA4G3R_RPA4G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA4G3R) TC1/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA4G3R) TC2/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA4G3R) TC3/WO0  */
#define   PPS_RPA4G3R_RPA4G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA4G3R) QSCK  */
#define   PPS_RPA4G3R_RPA4G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA4G3R) QCS  */
#define   PPS_RPA4G3R_RPA4G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA4G3R) QD1  */
#define   PPS_RPA4G3R_RPA4G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA4G3R) QD0  */
#define   PPS_RPA4G3R_RPA4G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA4G3R) QD3  */
#define   PPS_RPA4G3R_RPA4G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA4G3R) CCLOUT0  */
#define   PPS_RPA4G3R_RPA4G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA4G3R) TSTBUS2  */
#define   PPS_RPA4G3R_RPA4G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA4G3R) TSTBUS6  */
#define   PPS_RPA4G3R_RPA4G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA4G3R) TSTBUS10  */
#define PPS_RPA4G3R_RPA4G3R_OFF               (PPS_RPA4G3R_RPA4G3R_OFF_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) OFF Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM0P1           (PPS_RPA4G3R_RPA4G3R_SCOM0P1_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM0P0           (PPS_RPA4G3R_RPA4G3R_SCOM0P0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM0P3           (PPS_RPA4G3R_RPA4G3R_SCOM0P3_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM1P2           (PPS_RPA4G3R_RPA4G3R_SCOM1P2_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM1P0           (PPS_RPA4G3R_RPA4G3R_SCOM1P0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM1P3           (PPS_RPA4G3R_RPA4G3R_SCOM1P3_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM2P2           (PPS_RPA4G3R_RPA4G3R_SCOM2P2_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM2P3           (PPS_RPA4G3R_RPA4G3R_SCOM2P3_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM3P2           (PPS_RPA4G3R_RPA4G3R_SCOM3P2_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA4G3R_RPA4G3R_SCOM3P1           (PPS_RPA4G3R_RPA4G3R_SCOM3P1_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC0WO2           (PPS_RPA4G3R_RPA4G3R_TCC0WO2_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC0/WO2 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC0WO0           (PPS_RPA4G3R_RPA4G3R_TCC0WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC0/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC0WO4           (PPS_RPA4G3R_RPA4G3R_TCC0WO4_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC0/WO4 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC1WO2           (PPS_RPA4G3R_RPA4G3R_TCC1WO2_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC1/WO2 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC1WO0           (PPS_RPA4G3R_RPA4G3R_TCC1WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC1/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC1WO4           (PPS_RPA4G3R_RPA4G3R_TCC1WO4_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC1/WO4 Position  */
#define PPS_RPA4G3R_RPA4G3R_TCC2WO0           (PPS_RPA4G3R_RPA4G3R_TCC2WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TCC2/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_TC0WO0            (PPS_RPA4G3R_RPA4G3R_TC0WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TC0/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_REFO3             (PPS_RPA4G3R_RPA4G3R_REFO3_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) REFO3 Position  */
#define PPS_RPA4G3R_RPA4G3R_TC1WO0            (PPS_RPA4G3R_RPA4G3R_TC1WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TC1/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_TC2WO0            (PPS_RPA4G3R_RPA4G3R_TC2WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TC2/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_TC3WO0            (PPS_RPA4G3R_RPA4G3R_TC3WO0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TC3/WO0 Position  */
#define PPS_RPA4G3R_RPA4G3R_QSCK              (PPS_RPA4G3R_RPA4G3R_QSCK_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) QSCK Position  */
#define PPS_RPA4G3R_RPA4G3R_QCS               (PPS_RPA4G3R_RPA4G3R_QCS_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) QCS Position  */
#define PPS_RPA4G3R_RPA4G3R_QD1               (PPS_RPA4G3R_RPA4G3R_QD1_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) QD1 Position  */
#define PPS_RPA4G3R_RPA4G3R_QD0               (PPS_RPA4G3R_RPA4G3R_QD0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) QD0 Position  */
#define PPS_RPA4G3R_RPA4G3R_QD3               (PPS_RPA4G3R_RPA4G3R_QD3_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) QD3 Position  */
#define PPS_RPA4G3R_RPA4G3R_CCLOUT0           (PPS_RPA4G3R_RPA4G3R_CCLOUT0_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) CCLOUT0 Position  */
#define PPS_RPA4G3R_RPA4G3R_TSTBUS2           (PPS_RPA4G3R_RPA4G3R_TSTBUS2_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TSTBUS2 Position  */
#define PPS_RPA4G3R_RPA4G3R_TSTBUS6           (PPS_RPA4G3R_RPA4G3R_TSTBUS6_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TSTBUS6 Position  */
#define PPS_RPA4G3R_RPA4G3R_TSTBUS10          (PPS_RPA4G3R_RPA4G3R_TSTBUS10_Val << PPS_RPA4G3R_RPA4G3R_Pos) /* (PPS_RPA4G3R) TSTBUS10 Position  */
#define PPS_RPA4G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA4G3R) Register Mask  */


/* -------- PPS_RPA4G4R : (PPS Offset: 0x22C) (R/W 32)  -------- */
#define PPS_RPA4G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA4G4R)   Reset Value */

#define PPS_RPA4G4R_RPA4G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA4G4R) RPA4/G4 Position */
#define PPS_RPA4G4R_RPA4G4R_Msk               (_UINT32_(0x1F) << PPS_RPA4G4R_RPA4G4R_Pos)          /* (PPS_RPA4G4R) RPA4/G4 Mask */
#define PPS_RPA4G4R_RPA4G4R(value)            (PPS_RPA4G4R_RPA4G4R_Msk & (_UINT32_(value) << PPS_RPA4G4R_RPA4G4R_Pos)) /* Assigment of value for RPA4G4R in the PPS_RPA4G4R register */
#define   PPS_RPA4G4R_RPA4G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA4G4R) OFF  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA4G4R) SERCOM0/PAD2  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA4G4R) SERCOM0/PAD1  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA4G4R) SERCOM0/PAD0  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA4G4R) SERCOM1/PAD3  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA4G4R) SERCOM1/PAD1  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA4G4R) SERCOM1/PAD0  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA4G4R) SERCOM2/PAD3  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA4G4R) SERCOM2/PAD0  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA4G4R) SERCOM3/PAD3  */
#define   PPS_RPA4G4R_RPA4G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA4G4R) SERCOM3/PAD2  */
#define   PPS_RPA4G4R_RPA4G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA4G4R) TCC0/WO3  */
#define   PPS_RPA4G4R_RPA4G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA4G4R) TCC0/WO1  */
#define   PPS_RPA4G4R_RPA4G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA4G4R) TCC0/WO5  */
#define   PPS_RPA4G4R_RPA4G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA4G4R) TCC1/WO3  */
#define   PPS_RPA4G4R_RPA4G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA4G4R) TCC1/WO1  */
#define   PPS_RPA4G4R_RPA4G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA4G4R) TCC1/WO5  */
#define   PPS_RPA4G4R_RPA4G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA4G4R) TCC2/WO1  */
#define   PPS_RPA4G4R_RPA4G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA4G4R) TC0/WO0  */
#define   PPS_RPA4G4R_RPA4G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA4G4R) REFO4  */
#define   PPS_RPA4G4R_RPA4G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA4G4R) TC1/WO1  */
#define   PPS_RPA4G4R_RPA4G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA4G4R) TC2/WO1  */
#define   PPS_RPA4G4R_RPA4G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA4G4R) TC3/WO1  */
#define   PPS_RPA4G4R_RPA4G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA4G4R) QSCK  */
#define   PPS_RPA4G4R_RPA4G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA4G4R) QCS  */
#define   PPS_RPA4G4R_RPA4G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA4G4R) QD2  */
#define   PPS_RPA4G4R_RPA4G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA4G4R) QD1  */
#define   PPS_RPA4G4R_RPA4G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA4G4R) QD0  */
#define   PPS_RPA4G4R_RPA4G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA4G4R) CCLOUT1  */
#define   PPS_RPA4G4R_RPA4G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA4G4R) TSTBUS3  */
#define   PPS_RPA4G4R_RPA4G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA4G4R) TSTBUS7  */
#define   PPS_RPA4G4R_RPA4G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA4G4R) TSTBUS11  */
#define PPS_RPA4G4R_RPA4G4R_OFF               (PPS_RPA4G4R_RPA4G4R_OFF_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) OFF Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM0P2           (PPS_RPA4G4R_RPA4G4R_SCOM0P2_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM0P1           (PPS_RPA4G4R_RPA4G4R_SCOM0P1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM0P0           (PPS_RPA4G4R_RPA4G4R_SCOM0P0_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM1P3           (PPS_RPA4G4R_RPA4G4R_SCOM1P3_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM1P1           (PPS_RPA4G4R_RPA4G4R_SCOM1P1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM1P0           (PPS_RPA4G4R_RPA4G4R_SCOM1P0_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM2P3           (PPS_RPA4G4R_RPA4G4R_SCOM2P3_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM2P0           (PPS_RPA4G4R_RPA4G4R_SCOM2P0_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM3P3           (PPS_RPA4G4R_RPA4G4R_SCOM3P3_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA4G4R_RPA4G4R_SCOM3P2           (PPS_RPA4G4R_RPA4G4R_SCOM3P2_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC0WO3           (PPS_RPA4G4R_RPA4G4R_TCC0WO3_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC0/WO3 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC0WO1           (PPS_RPA4G4R_RPA4G4R_TCC0WO1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC0/WO1 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC0WO5           (PPS_RPA4G4R_RPA4G4R_TCC0WO5_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC0/WO5 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC1WO3           (PPS_RPA4G4R_RPA4G4R_TCC1WO3_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC1/WO3 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC1WO1           (PPS_RPA4G4R_RPA4G4R_TCC1WO1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC1/WO1 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC1WO5           (PPS_RPA4G4R_RPA4G4R_TCC1WO5_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC1/WO5 Position  */
#define PPS_RPA4G4R_RPA4G4R_TCC2WO1           (PPS_RPA4G4R_RPA4G4R_TCC2WO1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TCC2/WO1 Position  */
#define PPS_RPA4G4R_RPA4G4R_TC0WO0            (PPS_RPA4G4R_RPA4G4R_TC0WO0_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TC0/WO0 Position  */
#define PPS_RPA4G4R_RPA4G4R_REFO4             (PPS_RPA4G4R_RPA4G4R_REFO4_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) REFO4 Position  */
#define PPS_RPA4G4R_RPA4G4R_TC1WO1            (PPS_RPA4G4R_RPA4G4R_TC1WO1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TC1/WO1 Position  */
#define PPS_RPA4G4R_RPA4G4R_TC2WO1            (PPS_RPA4G4R_RPA4G4R_TC2WO1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TC2/WO1 Position  */
#define PPS_RPA4G4R_RPA4G4R_TC3WO1            (PPS_RPA4G4R_RPA4G4R_TC3WO1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TC3/WO1 Position  */
#define PPS_RPA4G4R_RPA4G4R_QSCK              (PPS_RPA4G4R_RPA4G4R_QSCK_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) QSCK Position  */
#define PPS_RPA4G4R_RPA4G4R_QCS               (PPS_RPA4G4R_RPA4G4R_QCS_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) QCS Position  */
#define PPS_RPA4G4R_RPA4G4R_QD2               (PPS_RPA4G4R_RPA4G4R_QD2_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) QD2 Position  */
#define PPS_RPA4G4R_RPA4G4R_QD1               (PPS_RPA4G4R_RPA4G4R_QD1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) QD1 Position  */
#define PPS_RPA4G4R_RPA4G4R_QD0               (PPS_RPA4G4R_RPA4G4R_QD0_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) QD0 Position  */
#define PPS_RPA4G4R_RPA4G4R_CCLOUT1           (PPS_RPA4G4R_RPA4G4R_CCLOUT1_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) CCLOUT1 Position  */
#define PPS_RPA4G4R_RPA4G4R_TSTBUS3           (PPS_RPA4G4R_RPA4G4R_TSTBUS3_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TSTBUS3 Position  */
#define PPS_RPA4G4R_RPA4G4R_TSTBUS7           (PPS_RPA4G4R_RPA4G4R_TSTBUS7_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TSTBUS7 Position  */
#define PPS_RPA4G4R_RPA4G4R_TSTBUS11          (PPS_RPA4G4R_RPA4G4R_TSTBUS11_Val << PPS_RPA4G4R_RPA4G4R_Pos) /* (PPS_RPA4G4R) TSTBUS11 Position  */
#define PPS_RPA4G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA4G4R) Register Mask  */


/* -------- PPS_RPA5G1R : (PPS Offset: 0x230) (R/W 32)  -------- */
#define PPS_RPA5G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA5G1R)   Reset Value */

#define PPS_RPA5G1R_RPA5G1R_Pos               _UINT32_(0)                                          /* (PPS_RPA5G1R) RPA5/G1 Position */
#define PPS_RPA5G1R_RPA5G1R_Msk               (_UINT32_(0x1F) << PPS_RPA5G1R_RPA5G1R_Pos)          /* (PPS_RPA5G1R) RPA5/G1 Mask */
#define PPS_RPA5G1R_RPA5G1R(value)            (PPS_RPA5G1R_RPA5G1R_Msk & (_UINT32_(value) << PPS_RPA5G1R_RPA5G1R_Pos)) /* Assigment of value for RPA5G1R in the PPS_RPA5G1R register */
#define   PPS_RPA5G1R_RPA5G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA5G1R) OFF  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPA5G1R) SERCOM0/PAD3  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPA5G1R) SERCOM0/PAD2  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPA5G1R) SERCOM0/PAD1  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPA5G1R) SERCOM1/PAD0  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPA5G1R) SERCOM1/PAD2  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPA5G1R) SERCOM1/PAD1  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPA5G1R) SERCOM2/PAD0  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPA5G1R) SERCOM2/PAD1  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPA5G1R) SERCOM3/PAD0  */
#define   PPS_RPA5G1R_RPA5G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPA5G1R) SERCOM3/PAD3  */
#define   PPS_RPA5G1R_RPA5G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPA5G1R) TCC0/WO0  */
#define   PPS_RPA5G1R_RPA5G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPA5G1R) TCC0/WO4  */
#define   PPS_RPA5G1R_RPA5G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPA5G1R) TCC0/WO2  */
#define   PPS_RPA5G1R_RPA5G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPA5G1R) TCC1/WO0  */
#define   PPS_RPA5G1R_RPA5G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPA5G1R) TCC1/WO4  */
#define   PPS_RPA5G1R_RPA5G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPA5G1R) TCC1/WO2  */
#define   PPS_RPA5G1R_RPA5G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA5G1R) TCC2/WO0  */
#define   PPS_RPA5G1R_RPA5G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA5G1R) TC0/WO1  */
#define   PPS_RPA5G1R_RPA5G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPA5G1R) REFO1  */
#define   PPS_RPA5G1R_RPA5G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA5G1R) TC1/WO0  */
#define   PPS_RPA5G1R_RPA5G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA5G1R) TC2/WO0  */
#define   PPS_RPA5G1R_RPA5G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA5G1R) TC3/WO0  */
#define   PPS_RPA5G1R_RPA5G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA5G1R) QSCK  */
#define   PPS_RPA5G1R_RPA5G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA5G1R) QCS  */
#define   PPS_RPA5G1R_RPA5G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPA5G1R) QD3  */
#define   PPS_RPA5G1R_RPA5G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPA5G1R) QD2  */
#define   PPS_RPA5G1R_RPA5G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPA5G1R) QD1  */
#define   PPS_RPA5G1R_RPA5G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA5G1R) CCLOUT0  */
#define   PPS_RPA5G1R_RPA5G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPA5G1R) TSTBUS0  */
#define   PPS_RPA5G1R_RPA5G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPA5G1R) TSTBUS4  */
#define   PPS_RPA5G1R_RPA5G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPA5G1R) TSTBUS8  */
#define PPS_RPA5G1R_RPA5G1R_OFF               (PPS_RPA5G1R_RPA5G1R_OFF_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) OFF Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM0P3           (PPS_RPA5G1R_RPA5G1R_SCOM0P3_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM0P2           (PPS_RPA5G1R_RPA5G1R_SCOM0P2_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM0P1           (PPS_RPA5G1R_RPA5G1R_SCOM0P1_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM1P0           (PPS_RPA5G1R_RPA5G1R_SCOM1P0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM1P2           (PPS_RPA5G1R_RPA5G1R_SCOM1P2_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM1P1           (PPS_RPA5G1R_RPA5G1R_SCOM1P1_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM2P0           (PPS_RPA5G1R_RPA5G1R_SCOM2P0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM2P1           (PPS_RPA5G1R_RPA5G1R_SCOM2P1_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM3P0           (PPS_RPA5G1R_RPA5G1R_SCOM3P0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA5G1R_RPA5G1R_SCOM3P3           (PPS_RPA5G1R_RPA5G1R_SCOM3P3_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC0WO0           (PPS_RPA5G1R_RPA5G1R_TCC0WO0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC0/WO0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC0WO4           (PPS_RPA5G1R_RPA5G1R_TCC0WO4_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC0/WO4 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC0WO2           (PPS_RPA5G1R_RPA5G1R_TCC0WO2_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC0/WO2 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC1WO0           (PPS_RPA5G1R_RPA5G1R_TCC1WO0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC1/WO0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC1WO4           (PPS_RPA5G1R_RPA5G1R_TCC1WO4_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC1/WO4 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC1WO2           (PPS_RPA5G1R_RPA5G1R_TCC1WO2_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC1/WO2 Position  */
#define PPS_RPA5G1R_RPA5G1R_TCC2WO0           (PPS_RPA5G1R_RPA5G1R_TCC2WO0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TCC2/WO0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TC0WO1            (PPS_RPA5G1R_RPA5G1R_TC0WO1_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TC0/WO1 Position  */
#define PPS_RPA5G1R_RPA5G1R_REFO1             (PPS_RPA5G1R_RPA5G1R_REFO1_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) REFO1 Position  */
#define PPS_RPA5G1R_RPA5G1R_TC1WO0            (PPS_RPA5G1R_RPA5G1R_TC1WO0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TC1/WO0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TC2WO0            (PPS_RPA5G1R_RPA5G1R_TC2WO0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TC2/WO0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TC3WO0            (PPS_RPA5G1R_RPA5G1R_TC3WO0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TC3/WO0 Position  */
#define PPS_RPA5G1R_RPA5G1R_QSCK              (PPS_RPA5G1R_RPA5G1R_QSCK_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) QSCK Position  */
#define PPS_RPA5G1R_RPA5G1R_QCS               (PPS_RPA5G1R_RPA5G1R_QCS_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) QCS Position  */
#define PPS_RPA5G1R_RPA5G1R_QD3               (PPS_RPA5G1R_RPA5G1R_QD3_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) QD3 Position  */
#define PPS_RPA5G1R_RPA5G1R_QD2               (PPS_RPA5G1R_RPA5G1R_QD2_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) QD2 Position  */
#define PPS_RPA5G1R_RPA5G1R_QD1               (PPS_RPA5G1R_RPA5G1R_QD1_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) QD1 Position  */
#define PPS_RPA5G1R_RPA5G1R_CCLOUT0           (PPS_RPA5G1R_RPA5G1R_CCLOUT0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) CCLOUT0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TSTBUS0           (PPS_RPA5G1R_RPA5G1R_TSTBUS0_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TSTBUS0 Position  */
#define PPS_RPA5G1R_RPA5G1R_TSTBUS4           (PPS_RPA5G1R_RPA5G1R_TSTBUS4_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TSTBUS4 Position  */
#define PPS_RPA5G1R_RPA5G1R_TSTBUS8           (PPS_RPA5G1R_RPA5G1R_TSTBUS8_Val << PPS_RPA5G1R_RPA5G1R_Pos) /* (PPS_RPA5G1R) TSTBUS8 Position  */
#define PPS_RPA5G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA5G1R) Register Mask  */


/* -------- PPS_RPA5G3R : (PPS Offset: 0x234) (R/W 32)  -------- */
#define PPS_RPA5G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA5G3R)   Reset Value */

#define PPS_RPA5G3R_RPA5G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA5G3R) RPA5/G3 Position */
#define PPS_RPA5G3R_RPA5G3R_Msk               (_UINT32_(0x1F) << PPS_RPA5G3R_RPA5G3R_Pos)          /* (PPS_RPA5G3R) RPA5/G3 Mask */
#define PPS_RPA5G3R_RPA5G3R(value)            (PPS_RPA5G3R_RPA5G3R_Msk & (_UINT32_(value) << PPS_RPA5G3R_RPA5G3R_Pos)) /* Assigment of value for RPA5G3R in the PPS_RPA5G3R register */
#define   PPS_RPA5G3R_RPA5G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA5G3R) OFF  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA5G3R) SERCOM0/PAD1  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA5G3R) SERCOM0/PAD0  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA5G3R) SERCOM0/PAD3  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA5G3R) SERCOM1/PAD2  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA5G3R) SERCOM1/PAD0  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA5G3R) SERCOM1/PAD3  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA5G3R) SERCOM2/PAD2  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA5G3R) SERCOM2/PAD3  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA5G3R) SERCOM3/PAD2  */
#define   PPS_RPA5G3R_RPA5G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA5G3R) SERCOM3/PAD1  */
#define   PPS_RPA5G3R_RPA5G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA5G3R) TCC0/WO2  */
#define   PPS_RPA5G3R_RPA5G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA5G3R) TCC0/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA5G3R) TCC0/WO4  */
#define   PPS_RPA5G3R_RPA5G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA5G3R) TCC1/WO2  */
#define   PPS_RPA5G3R_RPA5G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA5G3R) TCC1/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA5G3R) TCC1/WO4  */
#define   PPS_RPA5G3R_RPA5G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA5G3R) TCC2/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA5G3R) TC0/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA5G3R) REFO3  */
#define   PPS_RPA5G3R_RPA5G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA5G3R) TC1/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA5G3R) TC2/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA5G3R) TC3/WO0  */
#define   PPS_RPA5G3R_RPA5G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA5G3R) QSCK  */
#define   PPS_RPA5G3R_RPA5G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA5G3R) QCS  */
#define   PPS_RPA5G3R_RPA5G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA5G3R) QD1  */
#define   PPS_RPA5G3R_RPA5G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA5G3R) QD0  */
#define   PPS_RPA5G3R_RPA5G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA5G3R) QD3  */
#define   PPS_RPA5G3R_RPA5G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA5G3R) CCLOUT0  */
#define   PPS_RPA5G3R_RPA5G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA5G3R) TSTBUS2  */
#define   PPS_RPA5G3R_RPA5G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA5G3R) TSTBUS6  */
#define   PPS_RPA5G3R_RPA5G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA5G3R) TSTBUS10  */
#define PPS_RPA5G3R_RPA5G3R_OFF               (PPS_RPA5G3R_RPA5G3R_OFF_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) OFF Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM0P1           (PPS_RPA5G3R_RPA5G3R_SCOM0P1_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM0P0           (PPS_RPA5G3R_RPA5G3R_SCOM0P0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM0P3           (PPS_RPA5G3R_RPA5G3R_SCOM0P3_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM1P2           (PPS_RPA5G3R_RPA5G3R_SCOM1P2_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM1P0           (PPS_RPA5G3R_RPA5G3R_SCOM1P0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM1P3           (PPS_RPA5G3R_RPA5G3R_SCOM1P3_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM2P2           (PPS_RPA5G3R_RPA5G3R_SCOM2P2_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM2P3           (PPS_RPA5G3R_RPA5G3R_SCOM2P3_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM3P2           (PPS_RPA5G3R_RPA5G3R_SCOM3P2_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA5G3R_RPA5G3R_SCOM3P1           (PPS_RPA5G3R_RPA5G3R_SCOM3P1_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC0WO2           (PPS_RPA5G3R_RPA5G3R_TCC0WO2_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC0/WO2 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC0WO0           (PPS_RPA5G3R_RPA5G3R_TCC0WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC0/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC0WO4           (PPS_RPA5G3R_RPA5G3R_TCC0WO4_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC0/WO4 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC1WO2           (PPS_RPA5G3R_RPA5G3R_TCC1WO2_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC1/WO2 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC1WO0           (PPS_RPA5G3R_RPA5G3R_TCC1WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC1/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC1WO4           (PPS_RPA5G3R_RPA5G3R_TCC1WO4_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC1/WO4 Position  */
#define PPS_RPA5G3R_RPA5G3R_TCC2WO0           (PPS_RPA5G3R_RPA5G3R_TCC2WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TCC2/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_TC0WO0            (PPS_RPA5G3R_RPA5G3R_TC0WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TC0/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_REFO3             (PPS_RPA5G3R_RPA5G3R_REFO3_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) REFO3 Position  */
#define PPS_RPA5G3R_RPA5G3R_TC1WO0            (PPS_RPA5G3R_RPA5G3R_TC1WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TC1/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_TC2WO0            (PPS_RPA5G3R_RPA5G3R_TC2WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TC2/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_TC3WO0            (PPS_RPA5G3R_RPA5G3R_TC3WO0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TC3/WO0 Position  */
#define PPS_RPA5G3R_RPA5G3R_QSCK              (PPS_RPA5G3R_RPA5G3R_QSCK_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) QSCK Position  */
#define PPS_RPA5G3R_RPA5G3R_QCS               (PPS_RPA5G3R_RPA5G3R_QCS_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) QCS Position  */
#define PPS_RPA5G3R_RPA5G3R_QD1               (PPS_RPA5G3R_RPA5G3R_QD1_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) QD1 Position  */
#define PPS_RPA5G3R_RPA5G3R_QD0               (PPS_RPA5G3R_RPA5G3R_QD0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) QD0 Position  */
#define PPS_RPA5G3R_RPA5G3R_QD3               (PPS_RPA5G3R_RPA5G3R_QD3_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) QD3 Position  */
#define PPS_RPA5G3R_RPA5G3R_CCLOUT0           (PPS_RPA5G3R_RPA5G3R_CCLOUT0_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) CCLOUT0 Position  */
#define PPS_RPA5G3R_RPA5G3R_TSTBUS2           (PPS_RPA5G3R_RPA5G3R_TSTBUS2_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TSTBUS2 Position  */
#define PPS_RPA5G3R_RPA5G3R_TSTBUS6           (PPS_RPA5G3R_RPA5G3R_TSTBUS6_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TSTBUS6 Position  */
#define PPS_RPA5G3R_RPA5G3R_TSTBUS10          (PPS_RPA5G3R_RPA5G3R_TSTBUS10_Val << PPS_RPA5G3R_RPA5G3R_Pos) /* (PPS_RPA5G3R) TSTBUS10 Position  */
#define PPS_RPA5G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA5G3R) Register Mask  */


/* -------- PPS_RPA5G4R : (PPS Offset: 0x238) (R/W 32)  -------- */
#define PPS_RPA5G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA5G4R)   Reset Value */

#define PPS_RPA5G4R_RPA5G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA5G4R) RPA5/G4 Position */
#define PPS_RPA5G4R_RPA5G4R_Msk               (_UINT32_(0x1F) << PPS_RPA5G4R_RPA5G4R_Pos)          /* (PPS_RPA5G4R) RPA5/G4 Mask */
#define PPS_RPA5G4R_RPA5G4R(value)            (PPS_RPA5G4R_RPA5G4R_Msk & (_UINT32_(value) << PPS_RPA5G4R_RPA5G4R_Pos)) /* Assigment of value for RPA5G4R in the PPS_RPA5G4R register */
#define   PPS_RPA5G4R_RPA5G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA5G4R) OFF  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA5G4R) SERCOM0/PAD2  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA5G4R) SERCOM0/PAD1  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA5G4R) SERCOM0/PAD0  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA5G4R) SERCOM1/PAD3  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA5G4R) SERCOM1/PAD1  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA5G4R) SERCOM1/PAD0  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA5G4R) SERCOM2/PAD3  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA5G4R) SERCOM2/PAD0  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA5G4R) SERCOM3/PAD3  */
#define   PPS_RPA5G4R_RPA5G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA5G4R) SERCOM3/PAD2  */
#define   PPS_RPA5G4R_RPA5G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA5G4R) TCC0/WO3  */
#define   PPS_RPA5G4R_RPA5G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA5G4R) TCC0/WO1  */
#define   PPS_RPA5G4R_RPA5G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA5G4R) TCC0/WO5  */
#define   PPS_RPA5G4R_RPA5G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA5G4R) TCC1/WO3  */
#define   PPS_RPA5G4R_RPA5G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA5G4R) TCC1/WO1  */
#define   PPS_RPA5G4R_RPA5G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA5G4R) TCC1/WO5  */
#define   PPS_RPA5G4R_RPA5G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA5G4R) TCC2/WO1  */
#define   PPS_RPA5G4R_RPA5G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA5G4R) TC0/WO0  */
#define   PPS_RPA5G4R_RPA5G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA5G4R) REFO4  */
#define   PPS_RPA5G4R_RPA5G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA5G4R) TC1/WO1  */
#define   PPS_RPA5G4R_RPA5G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA5G4R) TC2/WO1  */
#define   PPS_RPA5G4R_RPA5G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA5G4R) TC3/WO1  */
#define   PPS_RPA5G4R_RPA5G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA5G4R) QSCK  */
#define   PPS_RPA5G4R_RPA5G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA5G4R) QCS  */
#define   PPS_RPA5G4R_RPA5G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA5G4R) QD2  */
#define   PPS_RPA5G4R_RPA5G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA5G4R) QD1  */
#define   PPS_RPA5G4R_RPA5G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA5G4R) QD0  */
#define   PPS_RPA5G4R_RPA5G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA5G4R) CCLOUT1  */
#define   PPS_RPA5G4R_RPA5G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA5G4R) TSTBUS3  */
#define   PPS_RPA5G4R_RPA5G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA5G4R) TSTBUS7  */
#define   PPS_RPA5G4R_RPA5G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA5G4R) TSTBUS11  */
#define PPS_RPA5G4R_RPA5G4R_OFF               (PPS_RPA5G4R_RPA5G4R_OFF_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) OFF Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM0P2           (PPS_RPA5G4R_RPA5G4R_SCOM0P2_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM0P1           (PPS_RPA5G4R_RPA5G4R_SCOM0P1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM0P0           (PPS_RPA5G4R_RPA5G4R_SCOM0P0_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM1P3           (PPS_RPA5G4R_RPA5G4R_SCOM1P3_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM1P1           (PPS_RPA5G4R_RPA5G4R_SCOM1P1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM1P0           (PPS_RPA5G4R_RPA5G4R_SCOM1P0_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM2P3           (PPS_RPA5G4R_RPA5G4R_SCOM2P3_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM2P0           (PPS_RPA5G4R_RPA5G4R_SCOM2P0_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM3P3           (PPS_RPA5G4R_RPA5G4R_SCOM3P3_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA5G4R_RPA5G4R_SCOM3P2           (PPS_RPA5G4R_RPA5G4R_SCOM3P2_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC0WO3           (PPS_RPA5G4R_RPA5G4R_TCC0WO3_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC0/WO3 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC0WO1           (PPS_RPA5G4R_RPA5G4R_TCC0WO1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC0/WO1 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC0WO5           (PPS_RPA5G4R_RPA5G4R_TCC0WO5_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC0/WO5 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC1WO3           (PPS_RPA5G4R_RPA5G4R_TCC1WO3_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC1/WO3 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC1WO1           (PPS_RPA5G4R_RPA5G4R_TCC1WO1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC1/WO1 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC1WO5           (PPS_RPA5G4R_RPA5G4R_TCC1WO5_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC1/WO5 Position  */
#define PPS_RPA5G4R_RPA5G4R_TCC2WO1           (PPS_RPA5G4R_RPA5G4R_TCC2WO1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TCC2/WO1 Position  */
#define PPS_RPA5G4R_RPA5G4R_TC0WO0            (PPS_RPA5G4R_RPA5G4R_TC0WO0_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TC0/WO0 Position  */
#define PPS_RPA5G4R_RPA5G4R_REFO4             (PPS_RPA5G4R_RPA5G4R_REFO4_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) REFO4 Position  */
#define PPS_RPA5G4R_RPA5G4R_TC1WO1            (PPS_RPA5G4R_RPA5G4R_TC1WO1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TC1/WO1 Position  */
#define PPS_RPA5G4R_RPA5G4R_TC2WO1            (PPS_RPA5G4R_RPA5G4R_TC2WO1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TC2/WO1 Position  */
#define PPS_RPA5G4R_RPA5G4R_TC3WO1            (PPS_RPA5G4R_RPA5G4R_TC3WO1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TC3/WO1 Position  */
#define PPS_RPA5G4R_RPA5G4R_QSCK              (PPS_RPA5G4R_RPA5G4R_QSCK_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) QSCK Position  */
#define PPS_RPA5G4R_RPA5G4R_QCS               (PPS_RPA5G4R_RPA5G4R_QCS_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) QCS Position  */
#define PPS_RPA5G4R_RPA5G4R_QD2               (PPS_RPA5G4R_RPA5G4R_QD2_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) QD2 Position  */
#define PPS_RPA5G4R_RPA5G4R_QD1               (PPS_RPA5G4R_RPA5G4R_QD1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) QD1 Position  */
#define PPS_RPA5G4R_RPA5G4R_QD0               (PPS_RPA5G4R_RPA5G4R_QD0_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) QD0 Position  */
#define PPS_RPA5G4R_RPA5G4R_CCLOUT1           (PPS_RPA5G4R_RPA5G4R_CCLOUT1_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) CCLOUT1 Position  */
#define PPS_RPA5G4R_RPA5G4R_TSTBUS3           (PPS_RPA5G4R_RPA5G4R_TSTBUS3_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TSTBUS3 Position  */
#define PPS_RPA5G4R_RPA5G4R_TSTBUS7           (PPS_RPA5G4R_RPA5G4R_TSTBUS7_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TSTBUS7 Position  */
#define PPS_RPA5G4R_RPA5G4R_TSTBUS11          (PPS_RPA5G4R_RPA5G4R_TSTBUS11_Val << PPS_RPA5G4R_RPA5G4R_Pos) /* (PPS_RPA5G4R) TSTBUS11 Position  */
#define PPS_RPA5G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA5G4R) Register Mask  */


/* -------- PPS_RPA6G1R : (PPS Offset: 0x23C) (R/W 32)  -------- */
#define PPS_RPA6G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA6G1R)   Reset Value */

#define PPS_RPA6G1R_RPA6G1R_Pos               _UINT32_(0)                                          /* (PPS_RPA6G1R) RPA6/G1 Position */
#define PPS_RPA6G1R_RPA6G1R_Msk               (_UINT32_(0x1F) << PPS_RPA6G1R_RPA6G1R_Pos)          /* (PPS_RPA6G1R) RPA6/G1 Mask */
#define PPS_RPA6G1R_RPA6G1R(value)            (PPS_RPA6G1R_RPA6G1R_Msk & (_UINT32_(value) << PPS_RPA6G1R_RPA6G1R_Pos)) /* Assigment of value for RPA6G1R in the PPS_RPA6G1R register */
#define   PPS_RPA6G1R_RPA6G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA6G1R) OFF  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPA6G1R) SERCOM0/PAD3  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPA6G1R) SERCOM0/PAD2  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPA6G1R) SERCOM0/PAD1  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPA6G1R) SERCOM1/PAD0  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPA6G1R) SERCOM1/PAD2  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPA6G1R) SERCOM1/PAD1  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPA6G1R) SERCOM2/PAD0  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPA6G1R) SERCOM2/PAD1  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPA6G1R) SERCOM3/PAD0  */
#define   PPS_RPA6G1R_RPA6G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPA6G1R) SERCOM3/PAD3  */
#define   PPS_RPA6G1R_RPA6G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPA6G1R) TCC0/WO0  */
#define   PPS_RPA6G1R_RPA6G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPA6G1R) TCC0/WO4  */
#define   PPS_RPA6G1R_RPA6G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPA6G1R) TCC0/WO2  */
#define   PPS_RPA6G1R_RPA6G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPA6G1R) TCC1/WO0  */
#define   PPS_RPA6G1R_RPA6G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPA6G1R) TCC1/WO4  */
#define   PPS_RPA6G1R_RPA6G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPA6G1R) TCC1/WO2  */
#define   PPS_RPA6G1R_RPA6G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA6G1R) TCC2/WO0  */
#define   PPS_RPA6G1R_RPA6G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA6G1R) TC0/WO1  */
#define   PPS_RPA6G1R_RPA6G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPA6G1R) REFO1  */
#define   PPS_RPA6G1R_RPA6G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA6G1R) TC1/WO0  */
#define   PPS_RPA6G1R_RPA6G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA6G1R) TC2/WO0  */
#define   PPS_RPA6G1R_RPA6G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA6G1R) TC3/WO0  */
#define   PPS_RPA6G1R_RPA6G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA6G1R) QSCK  */
#define   PPS_RPA6G1R_RPA6G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA6G1R) QCS  */
#define   PPS_RPA6G1R_RPA6G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPA6G1R) QD3  */
#define   PPS_RPA6G1R_RPA6G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPA6G1R) QD2  */
#define   PPS_RPA6G1R_RPA6G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPA6G1R) QD1  */
#define   PPS_RPA6G1R_RPA6G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA6G1R) CCLOUT0  */
#define   PPS_RPA6G1R_RPA6G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPA6G1R) TSTBUS0  */
#define   PPS_RPA6G1R_RPA6G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPA6G1R) TSTBUS4  */
#define   PPS_RPA6G1R_RPA6G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPA6G1R) TSTBUS8  */
#define PPS_RPA6G1R_RPA6G1R_OFF               (PPS_RPA6G1R_RPA6G1R_OFF_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) OFF Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM0P3           (PPS_RPA6G1R_RPA6G1R_SCOM0P3_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM0P2           (PPS_RPA6G1R_RPA6G1R_SCOM0P2_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM0P1           (PPS_RPA6G1R_RPA6G1R_SCOM0P1_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM1P0           (PPS_RPA6G1R_RPA6G1R_SCOM1P0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM1P2           (PPS_RPA6G1R_RPA6G1R_SCOM1P2_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM1P1           (PPS_RPA6G1R_RPA6G1R_SCOM1P1_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM2P0           (PPS_RPA6G1R_RPA6G1R_SCOM2P0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM2P1           (PPS_RPA6G1R_RPA6G1R_SCOM2P1_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM3P0           (PPS_RPA6G1R_RPA6G1R_SCOM3P0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA6G1R_RPA6G1R_SCOM3P3           (PPS_RPA6G1R_RPA6G1R_SCOM3P3_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC0WO0           (PPS_RPA6G1R_RPA6G1R_TCC0WO0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC0/WO0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC0WO4           (PPS_RPA6G1R_RPA6G1R_TCC0WO4_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC0/WO4 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC0WO2           (PPS_RPA6G1R_RPA6G1R_TCC0WO2_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC0/WO2 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC1WO0           (PPS_RPA6G1R_RPA6G1R_TCC1WO0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC1/WO0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC1WO4           (PPS_RPA6G1R_RPA6G1R_TCC1WO4_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC1/WO4 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC1WO2           (PPS_RPA6G1R_RPA6G1R_TCC1WO2_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC1/WO2 Position  */
#define PPS_RPA6G1R_RPA6G1R_TCC2WO0           (PPS_RPA6G1R_RPA6G1R_TCC2WO0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TCC2/WO0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TC0WO1            (PPS_RPA6G1R_RPA6G1R_TC0WO1_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TC0/WO1 Position  */
#define PPS_RPA6G1R_RPA6G1R_REFO1             (PPS_RPA6G1R_RPA6G1R_REFO1_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) REFO1 Position  */
#define PPS_RPA6G1R_RPA6G1R_TC1WO0            (PPS_RPA6G1R_RPA6G1R_TC1WO0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TC1/WO0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TC2WO0            (PPS_RPA6G1R_RPA6G1R_TC2WO0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TC2/WO0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TC3WO0            (PPS_RPA6G1R_RPA6G1R_TC3WO0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TC3/WO0 Position  */
#define PPS_RPA6G1R_RPA6G1R_QSCK              (PPS_RPA6G1R_RPA6G1R_QSCK_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) QSCK Position  */
#define PPS_RPA6G1R_RPA6G1R_QCS               (PPS_RPA6G1R_RPA6G1R_QCS_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) QCS Position  */
#define PPS_RPA6G1R_RPA6G1R_QD3               (PPS_RPA6G1R_RPA6G1R_QD3_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) QD3 Position  */
#define PPS_RPA6G1R_RPA6G1R_QD2               (PPS_RPA6G1R_RPA6G1R_QD2_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) QD2 Position  */
#define PPS_RPA6G1R_RPA6G1R_QD1               (PPS_RPA6G1R_RPA6G1R_QD1_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) QD1 Position  */
#define PPS_RPA6G1R_RPA6G1R_CCLOUT0           (PPS_RPA6G1R_RPA6G1R_CCLOUT0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) CCLOUT0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TSTBUS0           (PPS_RPA6G1R_RPA6G1R_TSTBUS0_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TSTBUS0 Position  */
#define PPS_RPA6G1R_RPA6G1R_TSTBUS4           (PPS_RPA6G1R_RPA6G1R_TSTBUS4_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TSTBUS4 Position  */
#define PPS_RPA6G1R_RPA6G1R_TSTBUS8           (PPS_RPA6G1R_RPA6G1R_TSTBUS8_Val << PPS_RPA6G1R_RPA6G1R_Pos) /* (PPS_RPA6G1R) TSTBUS8 Position  */
#define PPS_RPA6G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA6G1R) Register Mask  */


/* -------- PPS_RPA6G2R : (PPS Offset: 0x240) (R/W 32)  -------- */
#define PPS_RPA6G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA6G2R)   Reset Value */

#define PPS_RPA6G2R_RPA6G2R_Pos               _UINT32_(0)                                          /* (PPS_RPA6G2R) RPA6/G2 Position */
#define PPS_RPA6G2R_RPA6G2R_Msk               (_UINT32_(0x1F) << PPS_RPA6G2R_RPA6G2R_Pos)          /* (PPS_RPA6G2R) RPA6/G2 Mask */
#define PPS_RPA6G2R_RPA6G2R(value)            (PPS_RPA6G2R_RPA6G2R_Msk & (_UINT32_(value) << PPS_RPA6G2R_RPA6G2R_Pos)) /* Assigment of value for RPA6G2R in the PPS_RPA6G2R register */
#define   PPS_RPA6G2R_RPA6G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA6G2R) OFF  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPA6G2R) SERCOM0/PAD0  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPA6G2R) SERCOM0/PAD3  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPA6G2R) SERCOM0/PAD2  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPA6G2R) SERCOM1/PAD1  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPA6G2R) SERCOM1/PAD3  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPA6G2R) SERCOM1/PAD2  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPA6G2R) SERCOM2/PAD1  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPA6G2R) SERCOM2/PAD2  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPA6G2R) SERCOM3/PAD1  */
#define   PPS_RPA6G2R_RPA6G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPA6G2R) SERCOM3/PAD0  */
#define   PPS_RPA6G2R_RPA6G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPA6G2R) TCC0/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPA6G2R) TCC0/WO5  */
#define   PPS_RPA6G2R_RPA6G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPA6G2R) TCC0/WO3  */
#define   PPS_RPA6G2R_RPA6G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPA6G2R) TCC1/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPA6G2R) TCC1/WO5  */
#define   PPS_RPA6G2R_RPA6G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPA6G2R) TCC1/WO3  */
#define   PPS_RPA6G2R_RPA6G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA6G2R) TCC2/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA6G2R) TC0/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPA6G2R) REFO2  */
#define   PPS_RPA6G2R_RPA6G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA6G2R) TC1/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA6G2R) TC2/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA6G2R) TC3/WO1  */
#define   PPS_RPA6G2R_RPA6G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA6G2R) QSCK  */
#define   PPS_RPA6G2R_RPA6G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA6G2R) QCS  */
#define   PPS_RPA6G2R_RPA6G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPA6G2R) QD0  */
#define   PPS_RPA6G2R_RPA6G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPA6G2R) QD3  */
#define   PPS_RPA6G2R_RPA6G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPA6G2R) QD2  */
#define   PPS_RPA6G2R_RPA6G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA6G2R) CCLOUT1  */
#define   PPS_RPA6G2R_RPA6G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPA6G2R) TSTBUS1  */
#define   PPS_RPA6G2R_RPA6G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPA6G2R) TSTBUS5  */
#define   PPS_RPA6G2R_RPA6G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPA6G2R) TSTBUS9  */
#define PPS_RPA6G2R_RPA6G2R_OFF               (PPS_RPA6G2R_RPA6G2R_OFF_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) OFF Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM0P0           (PPS_RPA6G2R_RPA6G2R_SCOM0P0_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM0/PAD0 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM0P3           (PPS_RPA6G2R_RPA6G2R_SCOM0P3_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM0/PAD3 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM0P2           (PPS_RPA6G2R_RPA6G2R_SCOM0P2_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM0/PAD2 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM1P1           (PPS_RPA6G2R_RPA6G2R_SCOM1P1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM1/PAD1 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM1P3           (PPS_RPA6G2R_RPA6G2R_SCOM1P3_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM1/PAD3 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM1P2           (PPS_RPA6G2R_RPA6G2R_SCOM1P2_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM1/PAD2 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM2P1           (PPS_RPA6G2R_RPA6G2R_SCOM2P1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM2/PAD1 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM2P2           (PPS_RPA6G2R_RPA6G2R_SCOM2P2_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM2/PAD2 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM3P1           (PPS_RPA6G2R_RPA6G2R_SCOM3P1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM3/PAD1 Position  */
#define PPS_RPA6G2R_RPA6G2R_SCOM3P0           (PPS_RPA6G2R_RPA6G2R_SCOM3P0_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) SERCOM3/PAD0 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC0WO1           (PPS_RPA6G2R_RPA6G2R_TCC0WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC0/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC0WO5           (PPS_RPA6G2R_RPA6G2R_TCC0WO5_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC0/WO5 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC0WO3           (PPS_RPA6G2R_RPA6G2R_TCC0WO3_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC0/WO3 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC1WO1           (PPS_RPA6G2R_RPA6G2R_TCC1WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC1/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC1WO5           (PPS_RPA6G2R_RPA6G2R_TCC1WO5_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC1/WO5 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC1WO3           (PPS_RPA6G2R_RPA6G2R_TCC1WO3_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC1/WO3 Position  */
#define PPS_RPA6G2R_RPA6G2R_TCC2WO1           (PPS_RPA6G2R_RPA6G2R_TCC2WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TCC2/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TC0WO1            (PPS_RPA6G2R_RPA6G2R_TC0WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TC0/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_REFO2             (PPS_RPA6G2R_RPA6G2R_REFO2_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) REFO2 Position  */
#define PPS_RPA6G2R_RPA6G2R_TC1WO1            (PPS_RPA6G2R_RPA6G2R_TC1WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TC1/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TC2WO1            (PPS_RPA6G2R_RPA6G2R_TC2WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TC2/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TC3WO1            (PPS_RPA6G2R_RPA6G2R_TC3WO1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TC3/WO1 Position  */
#define PPS_RPA6G2R_RPA6G2R_QSCK              (PPS_RPA6G2R_RPA6G2R_QSCK_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) QSCK Position  */
#define PPS_RPA6G2R_RPA6G2R_QCS               (PPS_RPA6G2R_RPA6G2R_QCS_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) QCS Position  */
#define PPS_RPA6G2R_RPA6G2R_QD0               (PPS_RPA6G2R_RPA6G2R_QD0_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) QD0 Position  */
#define PPS_RPA6G2R_RPA6G2R_QD3               (PPS_RPA6G2R_RPA6G2R_QD3_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) QD3 Position  */
#define PPS_RPA6G2R_RPA6G2R_QD2               (PPS_RPA6G2R_RPA6G2R_QD2_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) QD2 Position  */
#define PPS_RPA6G2R_RPA6G2R_CCLOUT1           (PPS_RPA6G2R_RPA6G2R_CCLOUT1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) CCLOUT1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TSTBUS1           (PPS_RPA6G2R_RPA6G2R_TSTBUS1_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TSTBUS1 Position  */
#define PPS_RPA6G2R_RPA6G2R_TSTBUS5           (PPS_RPA6G2R_RPA6G2R_TSTBUS5_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TSTBUS5 Position  */
#define PPS_RPA6G2R_RPA6G2R_TSTBUS9           (PPS_RPA6G2R_RPA6G2R_TSTBUS9_Val << PPS_RPA6G2R_RPA6G2R_Pos) /* (PPS_RPA6G2R) TSTBUS9 Position  */
#define PPS_RPA6G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA6G2R) Register Mask  */


/* -------- PPS_RPA6G4R : (PPS Offset: 0x244) (R/W 32)  -------- */
#define PPS_RPA6G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA6G4R)   Reset Value */

#define PPS_RPA6G4R_RPA6G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA6G4R) RPA6/G4 Position */
#define PPS_RPA6G4R_RPA6G4R_Msk               (_UINT32_(0x1F) << PPS_RPA6G4R_RPA6G4R_Pos)          /* (PPS_RPA6G4R) RPA6/G4 Mask */
#define PPS_RPA6G4R_RPA6G4R(value)            (PPS_RPA6G4R_RPA6G4R_Msk & (_UINT32_(value) << PPS_RPA6G4R_RPA6G4R_Pos)) /* Assigment of value for RPA6G4R in the PPS_RPA6G4R register */
#define   PPS_RPA6G4R_RPA6G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA6G4R) OFF  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA6G4R) SERCOM0/PAD2  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA6G4R) SERCOM0/PAD1  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA6G4R) SERCOM0/PAD0  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA6G4R) SERCOM1/PAD3  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA6G4R) SERCOM1/PAD1  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA6G4R) SERCOM1/PAD0  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA6G4R) SERCOM2/PAD3  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA6G4R) SERCOM2/PAD0  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA6G4R) SERCOM3/PAD3  */
#define   PPS_RPA6G4R_RPA6G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA6G4R) SERCOM3/PAD2  */
#define   PPS_RPA6G4R_RPA6G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA6G4R) TCC0/WO3  */
#define   PPS_RPA6G4R_RPA6G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA6G4R) TCC0/WO1  */
#define   PPS_RPA6G4R_RPA6G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA6G4R) TCC0/WO5  */
#define   PPS_RPA6G4R_RPA6G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA6G4R) TCC1/WO3  */
#define   PPS_RPA6G4R_RPA6G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA6G4R) TCC1/WO1  */
#define   PPS_RPA6G4R_RPA6G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA6G4R) TCC1/WO5  */
#define   PPS_RPA6G4R_RPA6G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA6G4R) TCC2/WO1  */
#define   PPS_RPA6G4R_RPA6G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA6G4R) TC0/WO0  */
#define   PPS_RPA6G4R_RPA6G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA6G4R) REFO4  */
#define   PPS_RPA6G4R_RPA6G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA6G4R) TC1/WO1  */
#define   PPS_RPA6G4R_RPA6G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA6G4R) TC2/WO1  */
#define   PPS_RPA6G4R_RPA6G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA6G4R) TC3/WO1  */
#define   PPS_RPA6G4R_RPA6G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA6G4R) QSCK  */
#define   PPS_RPA6G4R_RPA6G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA6G4R) QCS  */
#define   PPS_RPA6G4R_RPA6G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA6G4R) QD2  */
#define   PPS_RPA6G4R_RPA6G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA6G4R) QD1  */
#define   PPS_RPA6G4R_RPA6G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA6G4R) QD0  */
#define   PPS_RPA6G4R_RPA6G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA6G4R) CCLOUT1  */
#define   PPS_RPA6G4R_RPA6G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA6G4R) TSTBUS3  */
#define   PPS_RPA6G4R_RPA6G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA6G4R) TSTBUS7  */
#define   PPS_RPA6G4R_RPA6G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA6G4R) TSTBUS11  */
#define PPS_RPA6G4R_RPA6G4R_OFF               (PPS_RPA6G4R_RPA6G4R_OFF_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) OFF Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM0P2           (PPS_RPA6G4R_RPA6G4R_SCOM0P2_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM0P1           (PPS_RPA6G4R_RPA6G4R_SCOM0P1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM0P0           (PPS_RPA6G4R_RPA6G4R_SCOM0P0_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM1P3           (PPS_RPA6G4R_RPA6G4R_SCOM1P3_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM1P1           (PPS_RPA6G4R_RPA6G4R_SCOM1P1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM1P0           (PPS_RPA6G4R_RPA6G4R_SCOM1P0_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM2P3           (PPS_RPA6G4R_RPA6G4R_SCOM2P3_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM2P0           (PPS_RPA6G4R_RPA6G4R_SCOM2P0_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM3P3           (PPS_RPA6G4R_RPA6G4R_SCOM3P3_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA6G4R_RPA6G4R_SCOM3P2           (PPS_RPA6G4R_RPA6G4R_SCOM3P2_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC0WO3           (PPS_RPA6G4R_RPA6G4R_TCC0WO3_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC0/WO3 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC0WO1           (PPS_RPA6G4R_RPA6G4R_TCC0WO1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC0/WO1 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC0WO5           (PPS_RPA6G4R_RPA6G4R_TCC0WO5_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC0/WO5 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC1WO3           (PPS_RPA6G4R_RPA6G4R_TCC1WO3_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC1/WO3 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC1WO1           (PPS_RPA6G4R_RPA6G4R_TCC1WO1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC1/WO1 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC1WO5           (PPS_RPA6G4R_RPA6G4R_TCC1WO5_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC1/WO5 Position  */
#define PPS_RPA6G4R_RPA6G4R_TCC2WO1           (PPS_RPA6G4R_RPA6G4R_TCC2WO1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TCC2/WO1 Position  */
#define PPS_RPA6G4R_RPA6G4R_TC0WO0            (PPS_RPA6G4R_RPA6G4R_TC0WO0_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TC0/WO0 Position  */
#define PPS_RPA6G4R_RPA6G4R_REFO4             (PPS_RPA6G4R_RPA6G4R_REFO4_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) REFO4 Position  */
#define PPS_RPA6G4R_RPA6G4R_TC1WO1            (PPS_RPA6G4R_RPA6G4R_TC1WO1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TC1/WO1 Position  */
#define PPS_RPA6G4R_RPA6G4R_TC2WO1            (PPS_RPA6G4R_RPA6G4R_TC2WO1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TC2/WO1 Position  */
#define PPS_RPA6G4R_RPA6G4R_TC3WO1            (PPS_RPA6G4R_RPA6G4R_TC3WO1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TC3/WO1 Position  */
#define PPS_RPA6G4R_RPA6G4R_QSCK              (PPS_RPA6G4R_RPA6G4R_QSCK_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) QSCK Position  */
#define PPS_RPA6G4R_RPA6G4R_QCS               (PPS_RPA6G4R_RPA6G4R_QCS_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) QCS Position  */
#define PPS_RPA6G4R_RPA6G4R_QD2               (PPS_RPA6G4R_RPA6G4R_QD2_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) QD2 Position  */
#define PPS_RPA6G4R_RPA6G4R_QD1               (PPS_RPA6G4R_RPA6G4R_QD1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) QD1 Position  */
#define PPS_RPA6G4R_RPA6G4R_QD0               (PPS_RPA6G4R_RPA6G4R_QD0_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) QD0 Position  */
#define PPS_RPA6G4R_RPA6G4R_CCLOUT1           (PPS_RPA6G4R_RPA6G4R_CCLOUT1_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) CCLOUT1 Position  */
#define PPS_RPA6G4R_RPA6G4R_TSTBUS3           (PPS_RPA6G4R_RPA6G4R_TSTBUS3_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TSTBUS3 Position  */
#define PPS_RPA6G4R_RPA6G4R_TSTBUS7           (PPS_RPA6G4R_RPA6G4R_TSTBUS7_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TSTBUS7 Position  */
#define PPS_RPA6G4R_RPA6G4R_TSTBUS11          (PPS_RPA6G4R_RPA6G4R_TSTBUS11_Val << PPS_RPA6G4R_RPA6G4R_Pos) /* (PPS_RPA6G4R) TSTBUS11 Position  */
#define PPS_RPA6G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA6G4R) Register Mask  */


/* -------- PPS_RPA7G1R : (PPS Offset: 0x248) (R/W 32)  -------- */
#define PPS_RPA7G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA7G1R)   Reset Value */

#define PPS_RPA7G1R_RPA7G1R_Pos               _UINT32_(0)                                          /* (PPS_RPA7G1R) RPA7/G1 Position */
#define PPS_RPA7G1R_RPA7G1R_Msk               (_UINT32_(0x1F) << PPS_RPA7G1R_RPA7G1R_Pos)          /* (PPS_RPA7G1R) RPA7/G1 Mask */
#define PPS_RPA7G1R_RPA7G1R(value)            (PPS_RPA7G1R_RPA7G1R_Msk & (_UINT32_(value) << PPS_RPA7G1R_RPA7G1R_Pos)) /* Assigment of value for RPA7G1R in the PPS_RPA7G1R register */
#define   PPS_RPA7G1R_RPA7G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA7G1R) OFF  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPA7G1R) SERCOM0/PAD3  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPA7G1R) SERCOM0/PAD2  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPA7G1R) SERCOM0/PAD1  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPA7G1R) SERCOM1/PAD0  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPA7G1R) SERCOM1/PAD2  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPA7G1R) SERCOM1/PAD1  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPA7G1R) SERCOM2/PAD0  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPA7G1R) SERCOM2/PAD1  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPA7G1R) SERCOM3/PAD0  */
#define   PPS_RPA7G1R_RPA7G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPA7G1R) SERCOM3/PAD3  */
#define   PPS_RPA7G1R_RPA7G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPA7G1R) TCC0/WO0  */
#define   PPS_RPA7G1R_RPA7G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPA7G1R) TCC0/WO4  */
#define   PPS_RPA7G1R_RPA7G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPA7G1R) TCC0/WO2  */
#define   PPS_RPA7G1R_RPA7G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPA7G1R) TCC1/WO0  */
#define   PPS_RPA7G1R_RPA7G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPA7G1R) TCC1/WO4  */
#define   PPS_RPA7G1R_RPA7G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPA7G1R) TCC1/WO2  */
#define   PPS_RPA7G1R_RPA7G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA7G1R) TCC2/WO0  */
#define   PPS_RPA7G1R_RPA7G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA7G1R) TC0/WO1  */
#define   PPS_RPA7G1R_RPA7G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPA7G1R) REFO1  */
#define   PPS_RPA7G1R_RPA7G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA7G1R) TC1/WO0  */
#define   PPS_RPA7G1R_RPA7G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA7G1R) TC2/WO0  */
#define   PPS_RPA7G1R_RPA7G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA7G1R) TC3/WO0  */
#define   PPS_RPA7G1R_RPA7G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA7G1R) QSCK  */
#define   PPS_RPA7G1R_RPA7G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA7G1R) QCS  */
#define   PPS_RPA7G1R_RPA7G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPA7G1R) QD3  */
#define   PPS_RPA7G1R_RPA7G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPA7G1R) QD2  */
#define   PPS_RPA7G1R_RPA7G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPA7G1R) QD1  */
#define   PPS_RPA7G1R_RPA7G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA7G1R) CCLOUT0  */
#define   PPS_RPA7G1R_RPA7G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPA7G1R) TSTBUS0  */
#define   PPS_RPA7G1R_RPA7G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPA7G1R) TSTBUS4  */
#define   PPS_RPA7G1R_RPA7G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPA7G1R) TSTBUS8  */
#define PPS_RPA7G1R_RPA7G1R_OFF               (PPS_RPA7G1R_RPA7G1R_OFF_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) OFF Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM0P3           (PPS_RPA7G1R_RPA7G1R_SCOM0P3_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM0P2           (PPS_RPA7G1R_RPA7G1R_SCOM0P2_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM0P1           (PPS_RPA7G1R_RPA7G1R_SCOM0P1_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM1P0           (PPS_RPA7G1R_RPA7G1R_SCOM1P0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM1P2           (PPS_RPA7G1R_RPA7G1R_SCOM1P2_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM1P1           (PPS_RPA7G1R_RPA7G1R_SCOM1P1_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM2P0           (PPS_RPA7G1R_RPA7G1R_SCOM2P0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM2P1           (PPS_RPA7G1R_RPA7G1R_SCOM2P1_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM3P0           (PPS_RPA7G1R_RPA7G1R_SCOM3P0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA7G1R_RPA7G1R_SCOM3P3           (PPS_RPA7G1R_RPA7G1R_SCOM3P3_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC0WO0           (PPS_RPA7G1R_RPA7G1R_TCC0WO0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC0/WO0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC0WO4           (PPS_RPA7G1R_RPA7G1R_TCC0WO4_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC0/WO4 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC0WO2           (PPS_RPA7G1R_RPA7G1R_TCC0WO2_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC0/WO2 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC1WO0           (PPS_RPA7G1R_RPA7G1R_TCC1WO0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC1/WO0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC1WO4           (PPS_RPA7G1R_RPA7G1R_TCC1WO4_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC1/WO4 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC1WO2           (PPS_RPA7G1R_RPA7G1R_TCC1WO2_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC1/WO2 Position  */
#define PPS_RPA7G1R_RPA7G1R_TCC2WO0           (PPS_RPA7G1R_RPA7G1R_TCC2WO0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TCC2/WO0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TC0WO1            (PPS_RPA7G1R_RPA7G1R_TC0WO1_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TC0/WO1 Position  */
#define PPS_RPA7G1R_RPA7G1R_REFO1             (PPS_RPA7G1R_RPA7G1R_REFO1_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) REFO1 Position  */
#define PPS_RPA7G1R_RPA7G1R_TC1WO0            (PPS_RPA7G1R_RPA7G1R_TC1WO0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TC1/WO0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TC2WO0            (PPS_RPA7G1R_RPA7G1R_TC2WO0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TC2/WO0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TC3WO0            (PPS_RPA7G1R_RPA7G1R_TC3WO0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TC3/WO0 Position  */
#define PPS_RPA7G1R_RPA7G1R_QSCK              (PPS_RPA7G1R_RPA7G1R_QSCK_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) QSCK Position  */
#define PPS_RPA7G1R_RPA7G1R_QCS               (PPS_RPA7G1R_RPA7G1R_QCS_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) QCS Position  */
#define PPS_RPA7G1R_RPA7G1R_QD3               (PPS_RPA7G1R_RPA7G1R_QD3_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) QD3 Position  */
#define PPS_RPA7G1R_RPA7G1R_QD2               (PPS_RPA7G1R_RPA7G1R_QD2_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) QD2 Position  */
#define PPS_RPA7G1R_RPA7G1R_QD1               (PPS_RPA7G1R_RPA7G1R_QD1_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) QD1 Position  */
#define PPS_RPA7G1R_RPA7G1R_CCLOUT0           (PPS_RPA7G1R_RPA7G1R_CCLOUT0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) CCLOUT0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TSTBUS0           (PPS_RPA7G1R_RPA7G1R_TSTBUS0_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TSTBUS0 Position  */
#define PPS_RPA7G1R_RPA7G1R_TSTBUS4           (PPS_RPA7G1R_RPA7G1R_TSTBUS4_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TSTBUS4 Position  */
#define PPS_RPA7G1R_RPA7G1R_TSTBUS8           (PPS_RPA7G1R_RPA7G1R_TSTBUS8_Val << PPS_RPA7G1R_RPA7G1R_Pos) /* (PPS_RPA7G1R) TSTBUS8 Position  */
#define PPS_RPA7G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA7G1R) Register Mask  */


/* -------- PPS_RPA7G2R : (PPS Offset: 0x24C) (R/W 32)  -------- */
#define PPS_RPA7G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA7G2R)   Reset Value */

#define PPS_RPA7G2R_RPA7G2R_Pos               _UINT32_(0)                                          /* (PPS_RPA7G2R) RPA7/G2 Position */
#define PPS_RPA7G2R_RPA7G2R_Msk               (_UINT32_(0x1F) << PPS_RPA7G2R_RPA7G2R_Pos)          /* (PPS_RPA7G2R) RPA7/G2 Mask */
#define PPS_RPA7G2R_RPA7G2R(value)            (PPS_RPA7G2R_RPA7G2R_Msk & (_UINT32_(value) << PPS_RPA7G2R_RPA7G2R_Pos)) /* Assigment of value for RPA7G2R in the PPS_RPA7G2R register */
#define   PPS_RPA7G2R_RPA7G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA7G2R) OFF  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPA7G2R) SERCOM0/PAD0  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPA7G2R) SERCOM0/PAD3  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPA7G2R) SERCOM0/PAD2  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPA7G2R) SERCOM1/PAD1  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPA7G2R) SERCOM1/PAD3  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPA7G2R) SERCOM1/PAD2  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPA7G2R) SERCOM2/PAD1  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPA7G2R) SERCOM2/PAD2  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPA7G2R) SERCOM3/PAD1  */
#define   PPS_RPA7G2R_RPA7G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPA7G2R) SERCOM3/PAD0  */
#define   PPS_RPA7G2R_RPA7G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPA7G2R) TCC0/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPA7G2R) TCC0/WO5  */
#define   PPS_RPA7G2R_RPA7G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPA7G2R) TCC0/WO3  */
#define   PPS_RPA7G2R_RPA7G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPA7G2R) TCC1/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPA7G2R) TCC1/WO5  */
#define   PPS_RPA7G2R_RPA7G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPA7G2R) TCC1/WO3  */
#define   PPS_RPA7G2R_RPA7G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA7G2R) TCC2/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA7G2R) TC0/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPA7G2R) REFO2  */
#define   PPS_RPA7G2R_RPA7G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA7G2R) TC1/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA7G2R) TC2/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA7G2R) TC3/WO1  */
#define   PPS_RPA7G2R_RPA7G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA7G2R) QSCK  */
#define   PPS_RPA7G2R_RPA7G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA7G2R) QCS  */
#define   PPS_RPA7G2R_RPA7G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPA7G2R) QD0  */
#define   PPS_RPA7G2R_RPA7G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPA7G2R) QD3  */
#define   PPS_RPA7G2R_RPA7G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPA7G2R) QD2  */
#define   PPS_RPA7G2R_RPA7G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA7G2R) CCLOUT1  */
#define   PPS_RPA7G2R_RPA7G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPA7G2R) TSTBUS1  */
#define   PPS_RPA7G2R_RPA7G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPA7G2R) TSTBUS5  */
#define   PPS_RPA7G2R_RPA7G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPA7G2R) TSTBUS9  */
#define PPS_RPA7G2R_RPA7G2R_OFF               (PPS_RPA7G2R_RPA7G2R_OFF_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) OFF Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM0P0           (PPS_RPA7G2R_RPA7G2R_SCOM0P0_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM0/PAD0 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM0P3           (PPS_RPA7G2R_RPA7G2R_SCOM0P3_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM0/PAD3 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM0P2           (PPS_RPA7G2R_RPA7G2R_SCOM0P2_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM0/PAD2 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM1P1           (PPS_RPA7G2R_RPA7G2R_SCOM1P1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM1/PAD1 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM1P3           (PPS_RPA7G2R_RPA7G2R_SCOM1P3_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM1/PAD3 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM1P2           (PPS_RPA7G2R_RPA7G2R_SCOM1P2_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM1/PAD2 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM2P1           (PPS_RPA7G2R_RPA7G2R_SCOM2P1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM2/PAD1 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM2P2           (PPS_RPA7G2R_RPA7G2R_SCOM2P2_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM2/PAD2 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM3P1           (PPS_RPA7G2R_RPA7G2R_SCOM3P1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM3/PAD1 Position  */
#define PPS_RPA7G2R_RPA7G2R_SCOM3P0           (PPS_RPA7G2R_RPA7G2R_SCOM3P0_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) SERCOM3/PAD0 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC0WO1           (PPS_RPA7G2R_RPA7G2R_TCC0WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC0/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC0WO5           (PPS_RPA7G2R_RPA7G2R_TCC0WO5_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC0/WO5 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC0WO3           (PPS_RPA7G2R_RPA7G2R_TCC0WO3_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC0/WO3 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC1WO1           (PPS_RPA7G2R_RPA7G2R_TCC1WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC1/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC1WO5           (PPS_RPA7G2R_RPA7G2R_TCC1WO5_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC1/WO5 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC1WO3           (PPS_RPA7G2R_RPA7G2R_TCC1WO3_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC1/WO3 Position  */
#define PPS_RPA7G2R_RPA7G2R_TCC2WO1           (PPS_RPA7G2R_RPA7G2R_TCC2WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TCC2/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TC0WO1            (PPS_RPA7G2R_RPA7G2R_TC0WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TC0/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_REFO2             (PPS_RPA7G2R_RPA7G2R_REFO2_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) REFO2 Position  */
#define PPS_RPA7G2R_RPA7G2R_TC1WO1            (PPS_RPA7G2R_RPA7G2R_TC1WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TC1/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TC2WO1            (PPS_RPA7G2R_RPA7G2R_TC2WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TC2/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TC3WO1            (PPS_RPA7G2R_RPA7G2R_TC3WO1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TC3/WO1 Position  */
#define PPS_RPA7G2R_RPA7G2R_QSCK              (PPS_RPA7G2R_RPA7G2R_QSCK_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) QSCK Position  */
#define PPS_RPA7G2R_RPA7G2R_QCS               (PPS_RPA7G2R_RPA7G2R_QCS_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) QCS Position  */
#define PPS_RPA7G2R_RPA7G2R_QD0               (PPS_RPA7G2R_RPA7G2R_QD0_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) QD0 Position  */
#define PPS_RPA7G2R_RPA7G2R_QD3               (PPS_RPA7G2R_RPA7G2R_QD3_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) QD3 Position  */
#define PPS_RPA7G2R_RPA7G2R_QD2               (PPS_RPA7G2R_RPA7G2R_QD2_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) QD2 Position  */
#define PPS_RPA7G2R_RPA7G2R_CCLOUT1           (PPS_RPA7G2R_RPA7G2R_CCLOUT1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) CCLOUT1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TSTBUS1           (PPS_RPA7G2R_RPA7G2R_TSTBUS1_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TSTBUS1 Position  */
#define PPS_RPA7G2R_RPA7G2R_TSTBUS5           (PPS_RPA7G2R_RPA7G2R_TSTBUS5_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TSTBUS5 Position  */
#define PPS_RPA7G2R_RPA7G2R_TSTBUS9           (PPS_RPA7G2R_RPA7G2R_TSTBUS9_Val << PPS_RPA7G2R_RPA7G2R_Pos) /* (PPS_RPA7G2R) TSTBUS9 Position  */
#define PPS_RPA7G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA7G2R) Register Mask  */


/* -------- PPS_RPA8G2R : (PPS Offset: 0x250) (R/W 32)  -------- */
#define PPS_RPA8G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA8G2R)   Reset Value */

#define PPS_RPA8G2R_RPA8G2R_Pos               _UINT32_(0)                                          /* (PPS_RPA8G2R) RPA8/G2 Position */
#define PPS_RPA8G2R_RPA8G2R_Msk               (_UINT32_(0x1F) << PPS_RPA8G2R_RPA8G2R_Pos)          /* (PPS_RPA8G2R) RPA8/G2 Mask */
#define PPS_RPA8G2R_RPA8G2R(value)            (PPS_RPA8G2R_RPA8G2R_Msk & (_UINT32_(value) << PPS_RPA8G2R_RPA8G2R_Pos)) /* Assigment of value for RPA8G2R in the PPS_RPA8G2R register */
#define   PPS_RPA8G2R_RPA8G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA8G2R) OFF  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPA8G2R) SERCOM0/PAD0  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPA8G2R) SERCOM0/PAD3  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPA8G2R) SERCOM0/PAD2  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPA8G2R) SERCOM1/PAD1  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPA8G2R) SERCOM1/PAD3  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPA8G2R) SERCOM1/PAD2  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPA8G2R) SERCOM2/PAD1  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPA8G2R) SERCOM2/PAD2  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPA8G2R) SERCOM3/PAD1  */
#define   PPS_RPA8G2R_RPA8G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPA8G2R) SERCOM3/PAD0  */
#define   PPS_RPA8G2R_RPA8G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPA8G2R) TCC0/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPA8G2R) TCC0/WO5  */
#define   PPS_RPA8G2R_RPA8G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPA8G2R) TCC0/WO3  */
#define   PPS_RPA8G2R_RPA8G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPA8G2R) TCC1/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPA8G2R) TCC1/WO5  */
#define   PPS_RPA8G2R_RPA8G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPA8G2R) TCC1/WO3  */
#define   PPS_RPA8G2R_RPA8G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA8G2R) TCC2/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA8G2R) TC0/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPA8G2R) REFO2  */
#define   PPS_RPA8G2R_RPA8G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA8G2R) TC1/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA8G2R) TC2/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA8G2R) TC3/WO1  */
#define   PPS_RPA8G2R_RPA8G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA8G2R) QSCK  */
#define   PPS_RPA8G2R_RPA8G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA8G2R) QCS  */
#define   PPS_RPA8G2R_RPA8G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPA8G2R) QD0  */
#define   PPS_RPA8G2R_RPA8G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPA8G2R) QD3  */
#define   PPS_RPA8G2R_RPA8G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPA8G2R) QD2  */
#define   PPS_RPA8G2R_RPA8G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA8G2R) CCLOUT1  */
#define   PPS_RPA8G2R_RPA8G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPA8G2R) TSTBUS1  */
#define   PPS_RPA8G2R_RPA8G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPA8G2R) TSTBUS5  */
#define   PPS_RPA8G2R_RPA8G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPA8G2R) TSTBUS9  */
#define PPS_RPA8G2R_RPA8G2R_OFF               (PPS_RPA8G2R_RPA8G2R_OFF_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) OFF Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM0P0           (PPS_RPA8G2R_RPA8G2R_SCOM0P0_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM0/PAD0 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM0P3           (PPS_RPA8G2R_RPA8G2R_SCOM0P3_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM0/PAD3 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM0P2           (PPS_RPA8G2R_RPA8G2R_SCOM0P2_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM0/PAD2 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM1P1           (PPS_RPA8G2R_RPA8G2R_SCOM1P1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM1/PAD1 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM1P3           (PPS_RPA8G2R_RPA8G2R_SCOM1P3_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM1/PAD3 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM1P2           (PPS_RPA8G2R_RPA8G2R_SCOM1P2_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM1/PAD2 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM2P1           (PPS_RPA8G2R_RPA8G2R_SCOM2P1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM2/PAD1 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM2P2           (PPS_RPA8G2R_RPA8G2R_SCOM2P2_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM2/PAD2 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM3P1           (PPS_RPA8G2R_RPA8G2R_SCOM3P1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM3/PAD1 Position  */
#define PPS_RPA8G2R_RPA8G2R_SCOM3P0           (PPS_RPA8G2R_RPA8G2R_SCOM3P0_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) SERCOM3/PAD0 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC0WO1           (PPS_RPA8G2R_RPA8G2R_TCC0WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC0/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC0WO5           (PPS_RPA8G2R_RPA8G2R_TCC0WO5_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC0/WO5 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC0WO3           (PPS_RPA8G2R_RPA8G2R_TCC0WO3_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC0/WO3 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC1WO1           (PPS_RPA8G2R_RPA8G2R_TCC1WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC1/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC1WO5           (PPS_RPA8G2R_RPA8G2R_TCC1WO5_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC1/WO5 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC1WO3           (PPS_RPA8G2R_RPA8G2R_TCC1WO3_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC1/WO3 Position  */
#define PPS_RPA8G2R_RPA8G2R_TCC2WO1           (PPS_RPA8G2R_RPA8G2R_TCC2WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TCC2/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TC0WO1            (PPS_RPA8G2R_RPA8G2R_TC0WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TC0/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_REFO2             (PPS_RPA8G2R_RPA8G2R_REFO2_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) REFO2 Position  */
#define PPS_RPA8G2R_RPA8G2R_TC1WO1            (PPS_RPA8G2R_RPA8G2R_TC1WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TC1/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TC2WO1            (PPS_RPA8G2R_RPA8G2R_TC2WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TC2/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TC3WO1            (PPS_RPA8G2R_RPA8G2R_TC3WO1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TC3/WO1 Position  */
#define PPS_RPA8G2R_RPA8G2R_QSCK              (PPS_RPA8G2R_RPA8G2R_QSCK_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) QSCK Position  */
#define PPS_RPA8G2R_RPA8G2R_QCS               (PPS_RPA8G2R_RPA8G2R_QCS_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) QCS Position  */
#define PPS_RPA8G2R_RPA8G2R_QD0               (PPS_RPA8G2R_RPA8G2R_QD0_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) QD0 Position  */
#define PPS_RPA8G2R_RPA8G2R_QD3               (PPS_RPA8G2R_RPA8G2R_QD3_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) QD3 Position  */
#define PPS_RPA8G2R_RPA8G2R_QD2               (PPS_RPA8G2R_RPA8G2R_QD2_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) QD2 Position  */
#define PPS_RPA8G2R_RPA8G2R_CCLOUT1           (PPS_RPA8G2R_RPA8G2R_CCLOUT1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) CCLOUT1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TSTBUS1           (PPS_RPA8G2R_RPA8G2R_TSTBUS1_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TSTBUS1 Position  */
#define PPS_RPA8G2R_RPA8G2R_TSTBUS5           (PPS_RPA8G2R_RPA8G2R_TSTBUS5_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TSTBUS5 Position  */
#define PPS_RPA8G2R_RPA8G2R_TSTBUS9           (PPS_RPA8G2R_RPA8G2R_TSTBUS9_Val << PPS_RPA8G2R_RPA8G2R_Pos) /* (PPS_RPA8G2R) TSTBUS9 Position  */
#define PPS_RPA8G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA8G2R) Register Mask  */


/* -------- PPS_RPA8G3R : (PPS Offset: 0x254) (R/W 32)  -------- */
#define PPS_RPA8G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA8G3R)   Reset Value */

#define PPS_RPA8G3R_RPA8G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA8G3R) RPA8/G3 Position */
#define PPS_RPA8G3R_RPA8G3R_Msk               (_UINT32_(0x1F) << PPS_RPA8G3R_RPA8G3R_Pos)          /* (PPS_RPA8G3R) RPA8/G3 Mask */
#define PPS_RPA8G3R_RPA8G3R(value)            (PPS_RPA8G3R_RPA8G3R_Msk & (_UINT32_(value) << PPS_RPA8G3R_RPA8G3R_Pos)) /* Assigment of value for RPA8G3R in the PPS_RPA8G3R register */
#define   PPS_RPA8G3R_RPA8G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA8G3R) OFF  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA8G3R) SERCOM0/PAD1  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA8G3R) SERCOM0/PAD0  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA8G3R) SERCOM0/PAD3  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA8G3R) SERCOM1/PAD2  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA8G3R) SERCOM1/PAD0  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA8G3R) SERCOM1/PAD3  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA8G3R) SERCOM2/PAD2  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA8G3R) SERCOM2/PAD3  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA8G3R) SERCOM3/PAD2  */
#define   PPS_RPA8G3R_RPA8G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA8G3R) SERCOM3/PAD1  */
#define   PPS_RPA8G3R_RPA8G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA8G3R) TCC0/WO2  */
#define   PPS_RPA8G3R_RPA8G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA8G3R) TCC0/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA8G3R) TCC0/WO4  */
#define   PPS_RPA8G3R_RPA8G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA8G3R) TCC1/WO2  */
#define   PPS_RPA8G3R_RPA8G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA8G3R) TCC1/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA8G3R) TCC1/WO4  */
#define   PPS_RPA8G3R_RPA8G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA8G3R) TCC2/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA8G3R) TC0/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA8G3R) REFO3  */
#define   PPS_RPA8G3R_RPA8G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA8G3R) TC1/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA8G3R) TC2/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA8G3R) TC3/WO0  */
#define   PPS_RPA8G3R_RPA8G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA8G3R) QSCK  */
#define   PPS_RPA8G3R_RPA8G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA8G3R) QCS  */
#define   PPS_RPA8G3R_RPA8G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA8G3R) QD1  */
#define   PPS_RPA8G3R_RPA8G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA8G3R) QD0  */
#define   PPS_RPA8G3R_RPA8G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA8G3R) QD3  */
#define   PPS_RPA8G3R_RPA8G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA8G3R) CCLOUT0  */
#define   PPS_RPA8G3R_RPA8G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA8G3R) TSTBUS2  */
#define   PPS_RPA8G3R_RPA8G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA8G3R) TSTBUS6  */
#define   PPS_RPA8G3R_RPA8G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA8G3R) TSTBUS10  */
#define PPS_RPA8G3R_RPA8G3R_OFF               (PPS_RPA8G3R_RPA8G3R_OFF_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) OFF Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM0P1           (PPS_RPA8G3R_RPA8G3R_SCOM0P1_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM0P0           (PPS_RPA8G3R_RPA8G3R_SCOM0P0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM0P3           (PPS_RPA8G3R_RPA8G3R_SCOM0P3_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM1P2           (PPS_RPA8G3R_RPA8G3R_SCOM1P2_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM1P0           (PPS_RPA8G3R_RPA8G3R_SCOM1P0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM1P3           (PPS_RPA8G3R_RPA8G3R_SCOM1P3_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM2P2           (PPS_RPA8G3R_RPA8G3R_SCOM2P2_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM2P3           (PPS_RPA8G3R_RPA8G3R_SCOM2P3_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM3P2           (PPS_RPA8G3R_RPA8G3R_SCOM3P2_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA8G3R_RPA8G3R_SCOM3P1           (PPS_RPA8G3R_RPA8G3R_SCOM3P1_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC0WO2           (PPS_RPA8G3R_RPA8G3R_TCC0WO2_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC0/WO2 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC0WO0           (PPS_RPA8G3R_RPA8G3R_TCC0WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC0/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC0WO4           (PPS_RPA8G3R_RPA8G3R_TCC0WO4_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC0/WO4 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC1WO2           (PPS_RPA8G3R_RPA8G3R_TCC1WO2_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC1/WO2 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC1WO0           (PPS_RPA8G3R_RPA8G3R_TCC1WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC1/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC1WO4           (PPS_RPA8G3R_RPA8G3R_TCC1WO4_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC1/WO4 Position  */
#define PPS_RPA8G3R_RPA8G3R_TCC2WO0           (PPS_RPA8G3R_RPA8G3R_TCC2WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TCC2/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_TC0WO0            (PPS_RPA8G3R_RPA8G3R_TC0WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TC0/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_REFO3             (PPS_RPA8G3R_RPA8G3R_REFO3_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) REFO3 Position  */
#define PPS_RPA8G3R_RPA8G3R_TC1WO0            (PPS_RPA8G3R_RPA8G3R_TC1WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TC1/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_TC2WO0            (PPS_RPA8G3R_RPA8G3R_TC2WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TC2/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_TC3WO0            (PPS_RPA8G3R_RPA8G3R_TC3WO0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TC3/WO0 Position  */
#define PPS_RPA8G3R_RPA8G3R_QSCK              (PPS_RPA8G3R_RPA8G3R_QSCK_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) QSCK Position  */
#define PPS_RPA8G3R_RPA8G3R_QCS               (PPS_RPA8G3R_RPA8G3R_QCS_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) QCS Position  */
#define PPS_RPA8G3R_RPA8G3R_QD1               (PPS_RPA8G3R_RPA8G3R_QD1_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) QD1 Position  */
#define PPS_RPA8G3R_RPA8G3R_QD0               (PPS_RPA8G3R_RPA8G3R_QD0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) QD0 Position  */
#define PPS_RPA8G3R_RPA8G3R_QD3               (PPS_RPA8G3R_RPA8G3R_QD3_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) QD3 Position  */
#define PPS_RPA8G3R_RPA8G3R_CCLOUT0           (PPS_RPA8G3R_RPA8G3R_CCLOUT0_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) CCLOUT0 Position  */
#define PPS_RPA8G3R_RPA8G3R_TSTBUS2           (PPS_RPA8G3R_RPA8G3R_TSTBUS2_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TSTBUS2 Position  */
#define PPS_RPA8G3R_RPA8G3R_TSTBUS6           (PPS_RPA8G3R_RPA8G3R_TSTBUS6_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TSTBUS6 Position  */
#define PPS_RPA8G3R_RPA8G3R_TSTBUS10          (PPS_RPA8G3R_RPA8G3R_TSTBUS10_Val << PPS_RPA8G3R_RPA8G3R_Pos) /* (PPS_RPA8G3R) TSTBUS10 Position  */
#define PPS_RPA8G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA8G3R) Register Mask  */


/* -------- PPS_RPA8G4R : (PPS Offset: 0x258) (R/W 32)  -------- */
#define PPS_RPA8G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA8G4R)   Reset Value */

#define PPS_RPA8G4R_RPA8G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA8G4R) RPA8/G4 Position */
#define PPS_RPA8G4R_RPA8G4R_Msk               (_UINT32_(0x1F) << PPS_RPA8G4R_RPA8G4R_Pos)          /* (PPS_RPA8G4R) RPA8/G4 Mask */
#define PPS_RPA8G4R_RPA8G4R(value)            (PPS_RPA8G4R_RPA8G4R_Msk & (_UINT32_(value) << PPS_RPA8G4R_RPA8G4R_Pos)) /* Assigment of value for RPA8G4R in the PPS_RPA8G4R register */
#define   PPS_RPA8G4R_RPA8G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA8G4R) OFF  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA8G4R) SERCOM0/PAD2  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA8G4R) SERCOM0/PAD1  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA8G4R) SERCOM0/PAD0  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA8G4R) SERCOM1/PAD3  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA8G4R) SERCOM1/PAD1  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA8G4R) SERCOM1/PAD0  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA8G4R) SERCOM2/PAD3  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA8G4R) SERCOM2/PAD0  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA8G4R) SERCOM3/PAD3  */
#define   PPS_RPA8G4R_RPA8G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA8G4R) SERCOM3/PAD2  */
#define   PPS_RPA8G4R_RPA8G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA8G4R) TCC0/WO3  */
#define   PPS_RPA8G4R_RPA8G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA8G4R) TCC0/WO1  */
#define   PPS_RPA8G4R_RPA8G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA8G4R) TCC0/WO5  */
#define   PPS_RPA8G4R_RPA8G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA8G4R) TCC1/WO3  */
#define   PPS_RPA8G4R_RPA8G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA8G4R) TCC1/WO1  */
#define   PPS_RPA8G4R_RPA8G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA8G4R) TCC1/WO5  */
#define   PPS_RPA8G4R_RPA8G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA8G4R) TCC2/WO1  */
#define   PPS_RPA8G4R_RPA8G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA8G4R) TC0/WO0  */
#define   PPS_RPA8G4R_RPA8G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA8G4R) REFO4  */
#define   PPS_RPA8G4R_RPA8G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA8G4R) TC1/WO1  */
#define   PPS_RPA8G4R_RPA8G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA8G4R) TC2/WO1  */
#define   PPS_RPA8G4R_RPA8G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA8G4R) TC3/WO1  */
#define   PPS_RPA8G4R_RPA8G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA8G4R) QSCK  */
#define   PPS_RPA8G4R_RPA8G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA8G4R) QCS  */
#define   PPS_RPA8G4R_RPA8G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA8G4R) QD2  */
#define   PPS_RPA8G4R_RPA8G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA8G4R) QD1  */
#define   PPS_RPA8G4R_RPA8G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA8G4R) QD0  */
#define   PPS_RPA8G4R_RPA8G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA8G4R) CCLOUT1  */
#define   PPS_RPA8G4R_RPA8G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA8G4R) TSTBUS3  */
#define   PPS_RPA8G4R_RPA8G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA8G4R) TSTBUS7  */
#define   PPS_RPA8G4R_RPA8G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA8G4R) TSTBUS11  */
#define PPS_RPA8G4R_RPA8G4R_OFF               (PPS_RPA8G4R_RPA8G4R_OFF_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) OFF Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM0P2           (PPS_RPA8G4R_RPA8G4R_SCOM0P2_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM0P1           (PPS_RPA8G4R_RPA8G4R_SCOM0P1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM0P0           (PPS_RPA8G4R_RPA8G4R_SCOM0P0_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM1P3           (PPS_RPA8G4R_RPA8G4R_SCOM1P3_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM1P1           (PPS_RPA8G4R_RPA8G4R_SCOM1P1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM1P0           (PPS_RPA8G4R_RPA8G4R_SCOM1P0_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM2P3           (PPS_RPA8G4R_RPA8G4R_SCOM2P3_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM2P0           (PPS_RPA8G4R_RPA8G4R_SCOM2P0_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM3P3           (PPS_RPA8G4R_RPA8G4R_SCOM3P3_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA8G4R_RPA8G4R_SCOM3P2           (PPS_RPA8G4R_RPA8G4R_SCOM3P2_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC0WO3           (PPS_RPA8G4R_RPA8G4R_TCC0WO3_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC0/WO3 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC0WO1           (PPS_RPA8G4R_RPA8G4R_TCC0WO1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC0/WO1 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC0WO5           (PPS_RPA8G4R_RPA8G4R_TCC0WO5_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC0/WO5 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC1WO3           (PPS_RPA8G4R_RPA8G4R_TCC1WO3_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC1/WO3 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC1WO1           (PPS_RPA8G4R_RPA8G4R_TCC1WO1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC1/WO1 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC1WO5           (PPS_RPA8G4R_RPA8G4R_TCC1WO5_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC1/WO5 Position  */
#define PPS_RPA8G4R_RPA8G4R_TCC2WO1           (PPS_RPA8G4R_RPA8G4R_TCC2WO1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TCC2/WO1 Position  */
#define PPS_RPA8G4R_RPA8G4R_TC0WO0            (PPS_RPA8G4R_RPA8G4R_TC0WO0_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TC0/WO0 Position  */
#define PPS_RPA8G4R_RPA8G4R_REFO4             (PPS_RPA8G4R_RPA8G4R_REFO4_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) REFO4 Position  */
#define PPS_RPA8G4R_RPA8G4R_TC1WO1            (PPS_RPA8G4R_RPA8G4R_TC1WO1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TC1/WO1 Position  */
#define PPS_RPA8G4R_RPA8G4R_TC2WO1            (PPS_RPA8G4R_RPA8G4R_TC2WO1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TC2/WO1 Position  */
#define PPS_RPA8G4R_RPA8G4R_TC3WO1            (PPS_RPA8G4R_RPA8G4R_TC3WO1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TC3/WO1 Position  */
#define PPS_RPA8G4R_RPA8G4R_QSCK              (PPS_RPA8G4R_RPA8G4R_QSCK_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) QSCK Position  */
#define PPS_RPA8G4R_RPA8G4R_QCS               (PPS_RPA8G4R_RPA8G4R_QCS_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) QCS Position  */
#define PPS_RPA8G4R_RPA8G4R_QD2               (PPS_RPA8G4R_RPA8G4R_QD2_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) QD2 Position  */
#define PPS_RPA8G4R_RPA8G4R_QD1               (PPS_RPA8G4R_RPA8G4R_QD1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) QD1 Position  */
#define PPS_RPA8G4R_RPA8G4R_QD0               (PPS_RPA8G4R_RPA8G4R_QD0_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) QD0 Position  */
#define PPS_RPA8G4R_RPA8G4R_CCLOUT1           (PPS_RPA8G4R_RPA8G4R_CCLOUT1_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) CCLOUT1 Position  */
#define PPS_RPA8G4R_RPA8G4R_TSTBUS3           (PPS_RPA8G4R_RPA8G4R_TSTBUS3_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TSTBUS3 Position  */
#define PPS_RPA8G4R_RPA8G4R_TSTBUS7           (PPS_RPA8G4R_RPA8G4R_TSTBUS7_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TSTBUS7 Position  */
#define PPS_RPA8G4R_RPA8G4R_TSTBUS11          (PPS_RPA8G4R_RPA8G4R_TSTBUS11_Val << PPS_RPA8G4R_RPA8G4R_Pos) /* (PPS_RPA8G4R) TSTBUS11 Position  */
#define PPS_RPA8G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA8G4R) Register Mask  */


/* -------- PPS_RPA9G1R : (PPS Offset: 0x25C) (R/W 32)  -------- */
#define PPS_RPA9G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA9G1R)   Reset Value */

#define PPS_RPA9G1R_RPA9G1R_Pos               _UINT32_(0)                                          /* (PPS_RPA9G1R) RPA9/G1 Position */
#define PPS_RPA9G1R_RPA9G1R_Msk               (_UINT32_(0x1F) << PPS_RPA9G1R_RPA9G1R_Pos)          /* (PPS_RPA9G1R) RPA9/G1 Mask */
#define PPS_RPA9G1R_RPA9G1R(value)            (PPS_RPA9G1R_RPA9G1R_Msk & (_UINT32_(value) << PPS_RPA9G1R_RPA9G1R_Pos)) /* Assigment of value for RPA9G1R in the PPS_RPA9G1R register */
#define   PPS_RPA9G1R_RPA9G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA9G1R) OFF  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPA9G1R) SERCOM0/PAD3  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPA9G1R) SERCOM0/PAD2  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPA9G1R) SERCOM0/PAD1  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPA9G1R) SERCOM1/PAD0  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPA9G1R) SERCOM1/PAD2  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPA9G1R) SERCOM1/PAD1  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPA9G1R) SERCOM2/PAD0  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPA9G1R) SERCOM2/PAD1  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPA9G1R) SERCOM3/PAD0  */
#define   PPS_RPA9G1R_RPA9G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPA9G1R) SERCOM3/PAD3  */
#define   PPS_RPA9G1R_RPA9G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPA9G1R) TCC0/WO0  */
#define   PPS_RPA9G1R_RPA9G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPA9G1R) TCC0/WO4  */
#define   PPS_RPA9G1R_RPA9G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPA9G1R) TCC0/WO2  */
#define   PPS_RPA9G1R_RPA9G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPA9G1R) TCC1/WO0  */
#define   PPS_RPA9G1R_RPA9G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPA9G1R) TCC1/WO4  */
#define   PPS_RPA9G1R_RPA9G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPA9G1R) TCC1/WO2  */
#define   PPS_RPA9G1R_RPA9G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA9G1R) TCC2/WO0  */
#define   PPS_RPA9G1R_RPA9G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPA9G1R) TC0/WO1  */
#define   PPS_RPA9G1R_RPA9G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPA9G1R) REFO1  */
#define   PPS_RPA9G1R_RPA9G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA9G1R) TC1/WO0  */
#define   PPS_RPA9G1R_RPA9G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA9G1R) TC2/WO0  */
#define   PPS_RPA9G1R_RPA9G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA9G1R) TC3/WO0  */
#define   PPS_RPA9G1R_RPA9G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA9G1R) QSCK  */
#define   PPS_RPA9G1R_RPA9G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA9G1R) QCS  */
#define   PPS_RPA9G1R_RPA9G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPA9G1R) QD3  */
#define   PPS_RPA9G1R_RPA9G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPA9G1R) QD2  */
#define   PPS_RPA9G1R_RPA9G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPA9G1R) QD1  */
#define   PPS_RPA9G1R_RPA9G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA9G1R) CCLOUT0  */
#define   PPS_RPA9G1R_RPA9G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPA9G1R) TSTBUS0  */
#define   PPS_RPA9G1R_RPA9G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPA9G1R) TSTBUS4  */
#define   PPS_RPA9G1R_RPA9G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPA9G1R) TSTBUS8  */
#define PPS_RPA9G1R_RPA9G1R_OFF               (PPS_RPA9G1R_RPA9G1R_OFF_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) OFF Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM0P3           (PPS_RPA9G1R_RPA9G1R_SCOM0P3_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM0P2           (PPS_RPA9G1R_RPA9G1R_SCOM0P2_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM0P1           (PPS_RPA9G1R_RPA9G1R_SCOM0P1_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM1P0           (PPS_RPA9G1R_RPA9G1R_SCOM1P0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM1P2           (PPS_RPA9G1R_RPA9G1R_SCOM1P2_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM1P1           (PPS_RPA9G1R_RPA9G1R_SCOM1P1_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM2P0           (PPS_RPA9G1R_RPA9G1R_SCOM2P0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM2P1           (PPS_RPA9G1R_RPA9G1R_SCOM2P1_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM3P0           (PPS_RPA9G1R_RPA9G1R_SCOM3P0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA9G1R_RPA9G1R_SCOM3P3           (PPS_RPA9G1R_RPA9G1R_SCOM3P3_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC0WO0           (PPS_RPA9G1R_RPA9G1R_TCC0WO0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC0/WO0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC0WO4           (PPS_RPA9G1R_RPA9G1R_TCC0WO4_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC0/WO4 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC0WO2           (PPS_RPA9G1R_RPA9G1R_TCC0WO2_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC0/WO2 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC1WO0           (PPS_RPA9G1R_RPA9G1R_TCC1WO0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC1/WO0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC1WO4           (PPS_RPA9G1R_RPA9G1R_TCC1WO4_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC1/WO4 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC1WO2           (PPS_RPA9G1R_RPA9G1R_TCC1WO2_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC1/WO2 Position  */
#define PPS_RPA9G1R_RPA9G1R_TCC2WO0           (PPS_RPA9G1R_RPA9G1R_TCC2WO0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TCC2/WO0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TC0WO1            (PPS_RPA9G1R_RPA9G1R_TC0WO1_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TC0/WO1 Position  */
#define PPS_RPA9G1R_RPA9G1R_REFO1             (PPS_RPA9G1R_RPA9G1R_REFO1_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) REFO1 Position  */
#define PPS_RPA9G1R_RPA9G1R_TC1WO0            (PPS_RPA9G1R_RPA9G1R_TC1WO0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TC1/WO0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TC2WO0            (PPS_RPA9G1R_RPA9G1R_TC2WO0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TC2/WO0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TC3WO0            (PPS_RPA9G1R_RPA9G1R_TC3WO0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TC3/WO0 Position  */
#define PPS_RPA9G1R_RPA9G1R_QSCK              (PPS_RPA9G1R_RPA9G1R_QSCK_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) QSCK Position  */
#define PPS_RPA9G1R_RPA9G1R_QCS               (PPS_RPA9G1R_RPA9G1R_QCS_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) QCS Position  */
#define PPS_RPA9G1R_RPA9G1R_QD3               (PPS_RPA9G1R_RPA9G1R_QD3_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) QD3 Position  */
#define PPS_RPA9G1R_RPA9G1R_QD2               (PPS_RPA9G1R_RPA9G1R_QD2_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) QD2 Position  */
#define PPS_RPA9G1R_RPA9G1R_QD1               (PPS_RPA9G1R_RPA9G1R_QD1_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) QD1 Position  */
#define PPS_RPA9G1R_RPA9G1R_CCLOUT0           (PPS_RPA9G1R_RPA9G1R_CCLOUT0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) CCLOUT0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TSTBUS0           (PPS_RPA9G1R_RPA9G1R_TSTBUS0_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TSTBUS0 Position  */
#define PPS_RPA9G1R_RPA9G1R_TSTBUS4           (PPS_RPA9G1R_RPA9G1R_TSTBUS4_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TSTBUS4 Position  */
#define PPS_RPA9G1R_RPA9G1R_TSTBUS8           (PPS_RPA9G1R_RPA9G1R_TSTBUS8_Val << PPS_RPA9G1R_RPA9G1R_Pos) /* (PPS_RPA9G1R) TSTBUS8 Position  */
#define PPS_RPA9G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA9G1R) Register Mask  */


/* -------- PPS_RPA9G3R : (PPS Offset: 0x260) (R/W 32)  -------- */
#define PPS_RPA9G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA9G3R)   Reset Value */

#define PPS_RPA9G3R_RPA9G3R_Pos               _UINT32_(0)                                          /* (PPS_RPA9G3R) RPA9/G3 Position */
#define PPS_RPA9G3R_RPA9G3R_Msk               (_UINT32_(0x1F) << PPS_RPA9G3R_RPA9G3R_Pos)          /* (PPS_RPA9G3R) RPA9/G3 Mask */
#define PPS_RPA9G3R_RPA9G3R(value)            (PPS_RPA9G3R_RPA9G3R_Msk & (_UINT32_(value) << PPS_RPA9G3R_RPA9G3R_Pos)) /* Assigment of value for RPA9G3R in the PPS_RPA9G3R register */
#define   PPS_RPA9G3R_RPA9G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA9G3R) OFF  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPA9G3R) SERCOM0/PAD1  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPA9G3R) SERCOM0/PAD0  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPA9G3R) SERCOM0/PAD3  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPA9G3R) SERCOM1/PAD2  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPA9G3R) SERCOM1/PAD0  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPA9G3R) SERCOM1/PAD3  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPA9G3R) SERCOM2/PAD2  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPA9G3R) SERCOM2/PAD3  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPA9G3R) SERCOM3/PAD2  */
#define   PPS_RPA9G3R_RPA9G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPA9G3R) SERCOM3/PAD1  */
#define   PPS_RPA9G3R_RPA9G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPA9G3R) TCC0/WO2  */
#define   PPS_RPA9G3R_RPA9G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPA9G3R) TCC0/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPA9G3R) TCC0/WO4  */
#define   PPS_RPA9G3R_RPA9G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPA9G3R) TCC1/WO2  */
#define   PPS_RPA9G3R_RPA9G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPA9G3R) TCC1/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPA9G3R) TCC1/WO4  */
#define   PPS_RPA9G3R_RPA9G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPA9G3R) TCC2/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA9G3R) TC0/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPA9G3R) REFO3  */
#define   PPS_RPA9G3R_RPA9G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPA9G3R) TC1/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPA9G3R) TC2/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPA9G3R) TC3/WO0  */
#define   PPS_RPA9G3R_RPA9G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA9G3R) QSCK  */
#define   PPS_RPA9G3R_RPA9G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA9G3R) QCS  */
#define   PPS_RPA9G3R_RPA9G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPA9G3R) QD1  */
#define   PPS_RPA9G3R_RPA9G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPA9G3R) QD0  */
#define   PPS_RPA9G3R_RPA9G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPA9G3R) QD3  */
#define   PPS_RPA9G3R_RPA9G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPA9G3R) CCLOUT0  */
#define   PPS_RPA9G3R_RPA9G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPA9G3R) TSTBUS2  */
#define   PPS_RPA9G3R_RPA9G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPA9G3R) TSTBUS6  */
#define   PPS_RPA9G3R_RPA9G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPA9G3R) TSTBUS10  */
#define PPS_RPA9G3R_RPA9G3R_OFF               (PPS_RPA9G3R_RPA9G3R_OFF_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) OFF Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM0P1           (PPS_RPA9G3R_RPA9G3R_SCOM0P1_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM0P0           (PPS_RPA9G3R_RPA9G3R_SCOM0P0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM0P3           (PPS_RPA9G3R_RPA9G3R_SCOM0P3_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM1P2           (PPS_RPA9G3R_RPA9G3R_SCOM1P2_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM1P0           (PPS_RPA9G3R_RPA9G3R_SCOM1P0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM1P3           (PPS_RPA9G3R_RPA9G3R_SCOM1P3_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM2P2           (PPS_RPA9G3R_RPA9G3R_SCOM2P2_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM2P3           (PPS_RPA9G3R_RPA9G3R_SCOM2P3_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM3P2           (PPS_RPA9G3R_RPA9G3R_SCOM3P2_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA9G3R_RPA9G3R_SCOM3P1           (PPS_RPA9G3R_RPA9G3R_SCOM3P1_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC0WO2           (PPS_RPA9G3R_RPA9G3R_TCC0WO2_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC0/WO2 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC0WO0           (PPS_RPA9G3R_RPA9G3R_TCC0WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC0/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC0WO4           (PPS_RPA9G3R_RPA9G3R_TCC0WO4_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC0/WO4 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC1WO2           (PPS_RPA9G3R_RPA9G3R_TCC1WO2_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC1/WO2 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC1WO0           (PPS_RPA9G3R_RPA9G3R_TCC1WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC1/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC1WO4           (PPS_RPA9G3R_RPA9G3R_TCC1WO4_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC1/WO4 Position  */
#define PPS_RPA9G3R_RPA9G3R_TCC2WO0           (PPS_RPA9G3R_RPA9G3R_TCC2WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TCC2/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_TC0WO0            (PPS_RPA9G3R_RPA9G3R_TC0WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TC0/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_REFO3             (PPS_RPA9G3R_RPA9G3R_REFO3_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) REFO3 Position  */
#define PPS_RPA9G3R_RPA9G3R_TC1WO0            (PPS_RPA9G3R_RPA9G3R_TC1WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TC1/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_TC2WO0            (PPS_RPA9G3R_RPA9G3R_TC2WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TC2/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_TC3WO0            (PPS_RPA9G3R_RPA9G3R_TC3WO0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TC3/WO0 Position  */
#define PPS_RPA9G3R_RPA9G3R_QSCK              (PPS_RPA9G3R_RPA9G3R_QSCK_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) QSCK Position  */
#define PPS_RPA9G3R_RPA9G3R_QCS               (PPS_RPA9G3R_RPA9G3R_QCS_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) QCS Position  */
#define PPS_RPA9G3R_RPA9G3R_QD1               (PPS_RPA9G3R_RPA9G3R_QD1_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) QD1 Position  */
#define PPS_RPA9G3R_RPA9G3R_QD0               (PPS_RPA9G3R_RPA9G3R_QD0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) QD0 Position  */
#define PPS_RPA9G3R_RPA9G3R_QD3               (PPS_RPA9G3R_RPA9G3R_QD3_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) QD3 Position  */
#define PPS_RPA9G3R_RPA9G3R_CCLOUT0           (PPS_RPA9G3R_RPA9G3R_CCLOUT0_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) CCLOUT0 Position  */
#define PPS_RPA9G3R_RPA9G3R_TSTBUS2           (PPS_RPA9G3R_RPA9G3R_TSTBUS2_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TSTBUS2 Position  */
#define PPS_RPA9G3R_RPA9G3R_TSTBUS6           (PPS_RPA9G3R_RPA9G3R_TSTBUS6_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TSTBUS6 Position  */
#define PPS_RPA9G3R_RPA9G3R_TSTBUS10          (PPS_RPA9G3R_RPA9G3R_TSTBUS10_Val << PPS_RPA9G3R_RPA9G3R_Pos) /* (PPS_RPA9G3R) TSTBUS10 Position  */
#define PPS_RPA9G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA9G3R) Register Mask  */


/* -------- PPS_RPA9G4R : (PPS Offset: 0x264) (R/W 32)  -------- */
#define PPS_RPA9G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPA9G4R)   Reset Value */

#define PPS_RPA9G4R_RPA9G4R_Pos               _UINT32_(0)                                          /* (PPS_RPA9G4R) RPA9/G4 Position */
#define PPS_RPA9G4R_RPA9G4R_Msk               (_UINT32_(0x1F) << PPS_RPA9G4R_RPA9G4R_Pos)          /* (PPS_RPA9G4R) RPA9/G4 Mask */
#define PPS_RPA9G4R_RPA9G4R(value)            (PPS_RPA9G4R_RPA9G4R_Msk & (_UINT32_(value) << PPS_RPA9G4R_RPA9G4R_Pos)) /* Assigment of value for RPA9G4R in the PPS_RPA9G4R register */
#define   PPS_RPA9G4R_RPA9G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPA9G4R) OFF  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPA9G4R) SERCOM0/PAD2  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPA9G4R) SERCOM0/PAD1  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPA9G4R) SERCOM0/PAD0  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPA9G4R) SERCOM1/PAD3  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPA9G4R) SERCOM1/PAD1  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPA9G4R) SERCOM1/PAD0  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPA9G4R) SERCOM2/PAD3  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPA9G4R) SERCOM2/PAD0  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPA9G4R) SERCOM3/PAD3  */
#define   PPS_RPA9G4R_RPA9G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPA9G4R) SERCOM3/PAD2  */
#define   PPS_RPA9G4R_RPA9G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPA9G4R) TCC0/WO3  */
#define   PPS_RPA9G4R_RPA9G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPA9G4R) TCC0/WO1  */
#define   PPS_RPA9G4R_RPA9G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPA9G4R) TCC0/WO5  */
#define   PPS_RPA9G4R_RPA9G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPA9G4R) TCC1/WO3  */
#define   PPS_RPA9G4R_RPA9G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPA9G4R) TCC1/WO1  */
#define   PPS_RPA9G4R_RPA9G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPA9G4R) TCC1/WO5  */
#define   PPS_RPA9G4R_RPA9G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPA9G4R) TCC2/WO1  */
#define   PPS_RPA9G4R_RPA9G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPA9G4R) TC0/WO0  */
#define   PPS_RPA9G4R_RPA9G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPA9G4R) REFO4  */
#define   PPS_RPA9G4R_RPA9G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPA9G4R) TC1/WO1  */
#define   PPS_RPA9G4R_RPA9G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPA9G4R) TC2/WO1  */
#define   PPS_RPA9G4R_RPA9G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPA9G4R) TC3/WO1  */
#define   PPS_RPA9G4R_RPA9G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPA9G4R) QSCK  */
#define   PPS_RPA9G4R_RPA9G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPA9G4R) QCS  */
#define   PPS_RPA9G4R_RPA9G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPA9G4R) QD2  */
#define   PPS_RPA9G4R_RPA9G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPA9G4R) QD1  */
#define   PPS_RPA9G4R_RPA9G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPA9G4R) QD0  */
#define   PPS_RPA9G4R_RPA9G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPA9G4R) CCLOUT1  */
#define   PPS_RPA9G4R_RPA9G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPA9G4R) TSTBUS3  */
#define   PPS_RPA9G4R_RPA9G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPA9G4R) TSTBUS7  */
#define   PPS_RPA9G4R_RPA9G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPA9G4R) TSTBUS11  */
#define PPS_RPA9G4R_RPA9G4R_OFF               (PPS_RPA9G4R_RPA9G4R_OFF_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) OFF Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM0P2           (PPS_RPA9G4R_RPA9G4R_SCOM0P2_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM0P1           (PPS_RPA9G4R_RPA9G4R_SCOM0P1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM0P0           (PPS_RPA9G4R_RPA9G4R_SCOM0P0_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM1P3           (PPS_RPA9G4R_RPA9G4R_SCOM1P3_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM1P1           (PPS_RPA9G4R_RPA9G4R_SCOM1P1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM1P0           (PPS_RPA9G4R_RPA9G4R_SCOM1P0_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM2P3           (PPS_RPA9G4R_RPA9G4R_SCOM2P3_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM2P0           (PPS_RPA9G4R_RPA9G4R_SCOM2P0_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM3P3           (PPS_RPA9G4R_RPA9G4R_SCOM3P3_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA9G4R_RPA9G4R_SCOM3P2           (PPS_RPA9G4R_RPA9G4R_SCOM3P2_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC0WO3           (PPS_RPA9G4R_RPA9G4R_TCC0WO3_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC0/WO3 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC0WO1           (PPS_RPA9G4R_RPA9G4R_TCC0WO1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC0/WO1 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC0WO5           (PPS_RPA9G4R_RPA9G4R_TCC0WO5_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC0/WO5 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC1WO3           (PPS_RPA9G4R_RPA9G4R_TCC1WO3_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC1/WO3 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC1WO1           (PPS_RPA9G4R_RPA9G4R_TCC1WO1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC1/WO1 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC1WO5           (PPS_RPA9G4R_RPA9G4R_TCC1WO5_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC1/WO5 Position  */
#define PPS_RPA9G4R_RPA9G4R_TCC2WO1           (PPS_RPA9G4R_RPA9G4R_TCC2WO1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TCC2/WO1 Position  */
#define PPS_RPA9G4R_RPA9G4R_TC0WO0            (PPS_RPA9G4R_RPA9G4R_TC0WO0_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TC0/WO0 Position  */
#define PPS_RPA9G4R_RPA9G4R_REFO4             (PPS_RPA9G4R_RPA9G4R_REFO4_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) REFO4 Position  */
#define PPS_RPA9G4R_RPA9G4R_TC1WO1            (PPS_RPA9G4R_RPA9G4R_TC1WO1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TC1/WO1 Position  */
#define PPS_RPA9G4R_RPA9G4R_TC2WO1            (PPS_RPA9G4R_RPA9G4R_TC2WO1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TC2/WO1 Position  */
#define PPS_RPA9G4R_RPA9G4R_TC3WO1            (PPS_RPA9G4R_RPA9G4R_TC3WO1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TC3/WO1 Position  */
#define PPS_RPA9G4R_RPA9G4R_QSCK              (PPS_RPA9G4R_RPA9G4R_QSCK_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) QSCK Position  */
#define PPS_RPA9G4R_RPA9G4R_QCS               (PPS_RPA9G4R_RPA9G4R_QCS_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) QCS Position  */
#define PPS_RPA9G4R_RPA9G4R_QD2               (PPS_RPA9G4R_RPA9G4R_QD2_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) QD2 Position  */
#define PPS_RPA9G4R_RPA9G4R_QD1               (PPS_RPA9G4R_RPA9G4R_QD1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) QD1 Position  */
#define PPS_RPA9G4R_RPA9G4R_QD0               (PPS_RPA9G4R_RPA9G4R_QD0_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) QD0 Position  */
#define PPS_RPA9G4R_RPA9G4R_CCLOUT1           (PPS_RPA9G4R_RPA9G4R_CCLOUT1_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) CCLOUT1 Position  */
#define PPS_RPA9G4R_RPA9G4R_TSTBUS3           (PPS_RPA9G4R_RPA9G4R_TSTBUS3_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TSTBUS3 Position  */
#define PPS_RPA9G4R_RPA9G4R_TSTBUS7           (PPS_RPA9G4R_RPA9G4R_TSTBUS7_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TSTBUS7 Position  */
#define PPS_RPA9G4R_RPA9G4R_TSTBUS11          (PPS_RPA9G4R_RPA9G4R_TSTBUS11_Val << PPS_RPA9G4R_RPA9G4R_Pos) /* (PPS_RPA9G4R) TSTBUS11 Position  */
#define PPS_RPA9G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPA9G4R) Register Mask  */


/* -------- PPS_RPA10G1R : (PPS Offset: 0x268) (R/W 32)  -------- */
#define PPS_RPA10G1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPA10G1R)   Reset Value */

#define PPS_RPA10G1R_RPA10G1R_Pos             _UINT32_(0)                                          /* (PPS_RPA10G1R) RPA10/G1 Position */
#define PPS_RPA10G1R_RPA10G1R_Msk             (_UINT32_(0x1F) << PPS_RPA10G1R_RPA10G1R_Pos)        /* (PPS_RPA10G1R) RPA10/G1 Mask */
#define PPS_RPA10G1R_RPA10G1R(value)          (PPS_RPA10G1R_RPA10G1R_Msk & (_UINT32_(value) << PPS_RPA10G1R_RPA10G1R_Pos)) /* Assigment of value for RPA10G1R in the PPS_RPA10G1R register */
#define   PPS_RPA10G1R_RPA10G1R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPA10G1R) OFF  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM0P3_Val   _UINT32_(0x1)                                        /* (PPS_RPA10G1R) SERCOM0/PAD3  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM0P2_Val   _UINT32_(0x2)                                        /* (PPS_RPA10G1R) SERCOM0/PAD2  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM0P1_Val   _UINT32_(0x3)                                        /* (PPS_RPA10G1R) SERCOM0/PAD1  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM1P0_Val   _UINT32_(0x4)                                        /* (PPS_RPA10G1R) SERCOM1/PAD0  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM1P2_Val   _UINT32_(0x5)                                        /* (PPS_RPA10G1R) SERCOM1/PAD2  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM1P1_Val   _UINT32_(0x6)                                        /* (PPS_RPA10G1R) SERCOM1/PAD1  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM2P0_Val   _UINT32_(0x7)                                        /* (PPS_RPA10G1R) SERCOM2/PAD0  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM2P1_Val   _UINT32_(0x8)                                        /* (PPS_RPA10G1R) SERCOM2/PAD1  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM3P0_Val   _UINT32_(0x9)                                        /* (PPS_RPA10G1R) SERCOM3/PAD0  */
#define   PPS_RPA10G1R_RPA10G1R_SCOM3P3_Val   _UINT32_(0xA)                                        /* (PPS_RPA10G1R) SERCOM3/PAD3  */
#define   PPS_RPA10G1R_RPA10G1R_TCC0WO0_Val   _UINT32_(0xB)                                        /* (PPS_RPA10G1R) TCC0/WO0  */
#define   PPS_RPA10G1R_RPA10G1R_TCC0WO4_Val   _UINT32_(0xC)                                        /* (PPS_RPA10G1R) TCC0/WO4  */
#define   PPS_RPA10G1R_RPA10G1R_TCC0WO2_Val   _UINT32_(0xD)                                        /* (PPS_RPA10G1R) TCC0/WO2  */
#define   PPS_RPA10G1R_RPA10G1R_TCC1WO0_Val   _UINT32_(0xE)                                        /* (PPS_RPA10G1R) TCC1/WO0  */
#define   PPS_RPA10G1R_RPA10G1R_TCC1WO4_Val   _UINT32_(0xF)                                        /* (PPS_RPA10G1R) TCC1/WO4  */
#define   PPS_RPA10G1R_RPA10G1R_TCC1WO2_Val   _UINT32_(0x10)                                       /* (PPS_RPA10G1R) TCC1/WO2  */
#define   PPS_RPA10G1R_RPA10G1R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPA10G1R) TCC2/WO0  */
#define   PPS_RPA10G1R_RPA10G1R_TC0WO1_Val    _UINT32_(0x12)                                       /* (PPS_RPA10G1R) TC0/WO1  */
#define   PPS_RPA10G1R_RPA10G1R_REFO1_Val     _UINT32_(0x13)                                       /* (PPS_RPA10G1R) REFO1  */
#define   PPS_RPA10G1R_RPA10G1R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPA10G1R) TC1/WO0  */
#define   PPS_RPA10G1R_RPA10G1R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPA10G1R) TC2/WO0  */
#define   PPS_RPA10G1R_RPA10G1R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPA10G1R) TC3/WO0  */
#define   PPS_RPA10G1R_RPA10G1R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPA10G1R) QSCK  */
#define   PPS_RPA10G1R_RPA10G1R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPA10G1R) QCS  */
#define   PPS_RPA10G1R_RPA10G1R_QD3_Val       _UINT32_(0x19)                                       /* (PPS_RPA10G1R) QD3  */
#define   PPS_RPA10G1R_RPA10G1R_QD2_Val       _UINT32_(0x1A)                                       /* (PPS_RPA10G1R) QD2  */
#define   PPS_RPA10G1R_RPA10G1R_QD1_Val       _UINT32_(0x1B)                                       /* (PPS_RPA10G1R) QD1  */
#define   PPS_RPA10G1R_RPA10G1R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPA10G1R) CCLOUT0  */
#define   PPS_RPA10G1R_RPA10G1R_TSTBUS0_Val   _UINT32_(0x1D)                                       /* (PPS_RPA10G1R) TSTBUS0  */
#define   PPS_RPA10G1R_RPA10G1R_TSTBUS4_Val   _UINT32_(0x1E)                                       /* (PPS_RPA10G1R) TSTBUS4  */
#define   PPS_RPA10G1R_RPA10G1R_TSTBUS8_Val   _UINT32_(0x1F)                                       /* (PPS_RPA10G1R) TSTBUS8  */
#define PPS_RPA10G1R_RPA10G1R_OFF             (PPS_RPA10G1R_RPA10G1R_OFF_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) OFF Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM0P3         (PPS_RPA10G1R_RPA10G1R_SCOM0P3_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM0P2         (PPS_RPA10G1R_RPA10G1R_SCOM0P2_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM0P1         (PPS_RPA10G1R_RPA10G1R_SCOM0P1_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM1P0         (PPS_RPA10G1R_RPA10G1R_SCOM1P0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM1P2         (PPS_RPA10G1R_RPA10G1R_SCOM1P2_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM1P1         (PPS_RPA10G1R_RPA10G1R_SCOM1P1_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM2P0         (PPS_RPA10G1R_RPA10G1R_SCOM2P0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM2P1         (PPS_RPA10G1R_RPA10G1R_SCOM2P1_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM3P0         (PPS_RPA10G1R_RPA10G1R_SCOM3P0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA10G1R_RPA10G1R_SCOM3P3         (PPS_RPA10G1R_RPA10G1R_SCOM3P3_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC0WO0         (PPS_RPA10G1R_RPA10G1R_TCC0WO0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC0/WO0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC0WO4         (PPS_RPA10G1R_RPA10G1R_TCC0WO4_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC0/WO4 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC0WO2         (PPS_RPA10G1R_RPA10G1R_TCC0WO2_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC0/WO2 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC1WO0         (PPS_RPA10G1R_RPA10G1R_TCC1WO0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC1/WO0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC1WO4         (PPS_RPA10G1R_RPA10G1R_TCC1WO4_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC1/WO4 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC1WO2         (PPS_RPA10G1R_RPA10G1R_TCC1WO2_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC1/WO2 Position  */
#define PPS_RPA10G1R_RPA10G1R_TCC2WO0         (PPS_RPA10G1R_RPA10G1R_TCC2WO0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TCC2/WO0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TC0WO1          (PPS_RPA10G1R_RPA10G1R_TC0WO1_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TC0/WO1 Position  */
#define PPS_RPA10G1R_RPA10G1R_REFO1           (PPS_RPA10G1R_RPA10G1R_REFO1_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) REFO1 Position  */
#define PPS_RPA10G1R_RPA10G1R_TC1WO0          (PPS_RPA10G1R_RPA10G1R_TC1WO0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TC1/WO0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TC2WO0          (PPS_RPA10G1R_RPA10G1R_TC2WO0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TC2/WO0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TC3WO0          (PPS_RPA10G1R_RPA10G1R_TC3WO0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TC3/WO0 Position  */
#define PPS_RPA10G1R_RPA10G1R_QSCK            (PPS_RPA10G1R_RPA10G1R_QSCK_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) QSCK Position  */
#define PPS_RPA10G1R_RPA10G1R_QCS             (PPS_RPA10G1R_RPA10G1R_QCS_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) QCS Position  */
#define PPS_RPA10G1R_RPA10G1R_QD3             (PPS_RPA10G1R_RPA10G1R_QD3_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) QD3 Position  */
#define PPS_RPA10G1R_RPA10G1R_QD2             (PPS_RPA10G1R_RPA10G1R_QD2_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) QD2 Position  */
#define PPS_RPA10G1R_RPA10G1R_QD1             (PPS_RPA10G1R_RPA10G1R_QD1_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) QD1 Position  */
#define PPS_RPA10G1R_RPA10G1R_CCLOUT0         (PPS_RPA10G1R_RPA10G1R_CCLOUT0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) CCLOUT0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TSTBUS0         (PPS_RPA10G1R_RPA10G1R_TSTBUS0_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TSTBUS0 Position  */
#define PPS_RPA10G1R_RPA10G1R_TSTBUS4         (PPS_RPA10G1R_RPA10G1R_TSTBUS4_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TSTBUS4 Position  */
#define PPS_RPA10G1R_RPA10G1R_TSTBUS8         (PPS_RPA10G1R_RPA10G1R_TSTBUS8_Val << PPS_RPA10G1R_RPA10G1R_Pos) /* (PPS_RPA10G1R) TSTBUS8 Position  */
#define PPS_RPA10G1R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPA10G1R) Register Mask  */


/* -------- PPS_RPA10G4R : (PPS Offset: 0x26C) (R/W 32)  -------- */
#define PPS_RPA10G4R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPA10G4R)   Reset Value */

#define PPS_RPA10G4R_RPA10G4R_Pos             _UINT32_(0)                                          /* (PPS_RPA10G4R) RPA10/G4 Position */
#define PPS_RPA10G4R_RPA10G4R_Msk             (_UINT32_(0x1F) << PPS_RPA10G4R_RPA10G4R_Pos)        /* (PPS_RPA10G4R) RPA10/G4 Mask */
#define PPS_RPA10G4R_RPA10G4R(value)          (PPS_RPA10G4R_RPA10G4R_Msk & (_UINT32_(value) << PPS_RPA10G4R_RPA10G4R_Pos)) /* Assigment of value for RPA10G4R in the PPS_RPA10G4R register */
#define   PPS_RPA10G4R_RPA10G4R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPA10G4R) OFF  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM0P2_Val   _UINT32_(0x1)                                        /* (PPS_RPA10G4R) SERCOM0/PAD2  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM0P1_Val   _UINT32_(0x2)                                        /* (PPS_RPA10G4R) SERCOM0/PAD1  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM0P0_Val   _UINT32_(0x3)                                        /* (PPS_RPA10G4R) SERCOM0/PAD0  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM1P3_Val   _UINT32_(0x4)                                        /* (PPS_RPA10G4R) SERCOM1/PAD3  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM1P1_Val   _UINT32_(0x5)                                        /* (PPS_RPA10G4R) SERCOM1/PAD1  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM1P0_Val   _UINT32_(0x6)                                        /* (PPS_RPA10G4R) SERCOM1/PAD0  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM2P3_Val   _UINT32_(0x7)                                        /* (PPS_RPA10G4R) SERCOM2/PAD3  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM2P0_Val   _UINT32_(0x8)                                        /* (PPS_RPA10G4R) SERCOM2/PAD0  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM3P3_Val   _UINT32_(0x9)                                        /* (PPS_RPA10G4R) SERCOM3/PAD3  */
#define   PPS_RPA10G4R_RPA10G4R_SCOM3P2_Val   _UINT32_(0xA)                                        /* (PPS_RPA10G4R) SERCOM3/PAD2  */
#define   PPS_RPA10G4R_RPA10G4R_TCC0WO3_Val   _UINT32_(0xB)                                        /* (PPS_RPA10G4R) TCC0/WO3  */
#define   PPS_RPA10G4R_RPA10G4R_TCC0WO1_Val   _UINT32_(0xC)                                        /* (PPS_RPA10G4R) TCC0/WO1  */
#define   PPS_RPA10G4R_RPA10G4R_TCC0WO5_Val   _UINT32_(0xD)                                        /* (PPS_RPA10G4R) TCC0/WO5  */
#define   PPS_RPA10G4R_RPA10G4R_TCC1WO3_Val   _UINT32_(0xE)                                        /* (PPS_RPA10G4R) TCC1/WO3  */
#define   PPS_RPA10G4R_RPA10G4R_TCC1WO1_Val   _UINT32_(0xF)                                        /* (PPS_RPA10G4R) TCC1/WO1  */
#define   PPS_RPA10G4R_RPA10G4R_TCC1WO5_Val   _UINT32_(0x10)                                       /* (PPS_RPA10G4R) TCC1/WO5  */
#define   PPS_RPA10G4R_RPA10G4R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPA10G4R) TCC2/WO1  */
#define   PPS_RPA10G4R_RPA10G4R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPA10G4R) TC0/WO0  */
#define   PPS_RPA10G4R_RPA10G4R_REFO4_Val     _UINT32_(0x13)                                       /* (PPS_RPA10G4R) REFO4  */
#define   PPS_RPA10G4R_RPA10G4R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPA10G4R) TC1/WO1  */
#define   PPS_RPA10G4R_RPA10G4R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPA10G4R) TC2/WO1  */
#define   PPS_RPA10G4R_RPA10G4R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPA10G4R) TC3/WO1  */
#define   PPS_RPA10G4R_RPA10G4R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPA10G4R) QSCK  */
#define   PPS_RPA10G4R_RPA10G4R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPA10G4R) QCS  */
#define   PPS_RPA10G4R_RPA10G4R_QD2_Val       _UINT32_(0x19)                                       /* (PPS_RPA10G4R) QD2  */
#define   PPS_RPA10G4R_RPA10G4R_QD1_Val       _UINT32_(0x1A)                                       /* (PPS_RPA10G4R) QD1  */
#define   PPS_RPA10G4R_RPA10G4R_QD0_Val       _UINT32_(0x1B)                                       /* (PPS_RPA10G4R) QD0  */
#define   PPS_RPA10G4R_RPA10G4R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPA10G4R) CCLOUT1  */
#define   PPS_RPA10G4R_RPA10G4R_TSTBUS3_Val   _UINT32_(0x1D)                                       /* (PPS_RPA10G4R) TSTBUS3  */
#define   PPS_RPA10G4R_RPA10G4R_TSTBUS7_Val   _UINT32_(0x1E)                                       /* (PPS_RPA10G4R) TSTBUS7  */
#define   PPS_RPA10G4R_RPA10G4R_TSTBUS11_Val  _UINT32_(0x1F)                                       /* (PPS_RPA10G4R) TSTBUS11  */
#define PPS_RPA10G4R_RPA10G4R_OFF             (PPS_RPA10G4R_RPA10G4R_OFF_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) OFF Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM0P2         (PPS_RPA10G4R_RPA10G4R_SCOM0P2_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM0P1         (PPS_RPA10G4R_RPA10G4R_SCOM0P1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM0P0         (PPS_RPA10G4R_RPA10G4R_SCOM0P0_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM1P3         (PPS_RPA10G4R_RPA10G4R_SCOM1P3_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM1P1         (PPS_RPA10G4R_RPA10G4R_SCOM1P1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM1P0         (PPS_RPA10G4R_RPA10G4R_SCOM1P0_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM2P3         (PPS_RPA10G4R_RPA10G4R_SCOM2P3_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM2P0         (PPS_RPA10G4R_RPA10G4R_SCOM2P0_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM3P3         (PPS_RPA10G4R_RPA10G4R_SCOM3P3_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA10G4R_RPA10G4R_SCOM3P2         (PPS_RPA10G4R_RPA10G4R_SCOM3P2_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC0WO3         (PPS_RPA10G4R_RPA10G4R_TCC0WO3_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC0/WO3 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC0WO1         (PPS_RPA10G4R_RPA10G4R_TCC0WO1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC0/WO1 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC0WO5         (PPS_RPA10G4R_RPA10G4R_TCC0WO5_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC0/WO5 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC1WO3         (PPS_RPA10G4R_RPA10G4R_TCC1WO3_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC1/WO3 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC1WO1         (PPS_RPA10G4R_RPA10G4R_TCC1WO1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC1/WO1 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC1WO5         (PPS_RPA10G4R_RPA10G4R_TCC1WO5_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC1/WO5 Position  */
#define PPS_RPA10G4R_RPA10G4R_TCC2WO1         (PPS_RPA10G4R_RPA10G4R_TCC2WO1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TCC2/WO1 Position  */
#define PPS_RPA10G4R_RPA10G4R_TC0WO0          (PPS_RPA10G4R_RPA10G4R_TC0WO0_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TC0/WO0 Position  */
#define PPS_RPA10G4R_RPA10G4R_REFO4           (PPS_RPA10G4R_RPA10G4R_REFO4_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) REFO4 Position  */
#define PPS_RPA10G4R_RPA10G4R_TC1WO1          (PPS_RPA10G4R_RPA10G4R_TC1WO1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TC1/WO1 Position  */
#define PPS_RPA10G4R_RPA10G4R_TC2WO1          (PPS_RPA10G4R_RPA10G4R_TC2WO1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TC2/WO1 Position  */
#define PPS_RPA10G4R_RPA10G4R_TC3WO1          (PPS_RPA10G4R_RPA10G4R_TC3WO1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TC3/WO1 Position  */
#define PPS_RPA10G4R_RPA10G4R_QSCK            (PPS_RPA10G4R_RPA10G4R_QSCK_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) QSCK Position  */
#define PPS_RPA10G4R_RPA10G4R_QCS             (PPS_RPA10G4R_RPA10G4R_QCS_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) QCS Position  */
#define PPS_RPA10G4R_RPA10G4R_QD2             (PPS_RPA10G4R_RPA10G4R_QD2_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) QD2 Position  */
#define PPS_RPA10G4R_RPA10G4R_QD1             (PPS_RPA10G4R_RPA10G4R_QD1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) QD1 Position  */
#define PPS_RPA10G4R_RPA10G4R_QD0             (PPS_RPA10G4R_RPA10G4R_QD0_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) QD0 Position  */
#define PPS_RPA10G4R_RPA10G4R_CCLOUT1         (PPS_RPA10G4R_RPA10G4R_CCLOUT1_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) CCLOUT1 Position  */
#define PPS_RPA10G4R_RPA10G4R_TSTBUS3         (PPS_RPA10G4R_RPA10G4R_TSTBUS3_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TSTBUS3 Position  */
#define PPS_RPA10G4R_RPA10G4R_TSTBUS7         (PPS_RPA10G4R_RPA10G4R_TSTBUS7_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TSTBUS7 Position  */
#define PPS_RPA10G4R_RPA10G4R_TSTBUS11        (PPS_RPA10G4R_RPA10G4R_TSTBUS11_Val << PPS_RPA10G4R_RPA10G4R_Pos) /* (PPS_RPA10G4R) TSTBUS11 Position  */
#define PPS_RPA10G4R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPA10G4R) Register Mask  */


/* -------- PPS_RPA13G3R : (PPS Offset: 0x278) (R/W 32)  -------- */
#define PPS_RPA13G3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPA13G3R)   Reset Value */

#define PPS_RPA13G3R_RPA13G3R_Pos             _UINT32_(0)                                          /* (PPS_RPA13G3R) RPA13/G3 Position */
#define PPS_RPA13G3R_RPA13G3R_Msk             (_UINT32_(0x1F) << PPS_RPA13G3R_RPA13G3R_Pos)        /* (PPS_RPA13G3R) RPA13/G3 Mask */
#define PPS_RPA13G3R_RPA13G3R(value)          (PPS_RPA13G3R_RPA13G3R_Msk & (_UINT32_(value) << PPS_RPA13G3R_RPA13G3R_Pos)) /* Assigment of value for RPA13G3R in the PPS_RPA13G3R register */
#define   PPS_RPA13G3R_RPA13G3R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPA13G3R) OFF  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM0P1_Val   _UINT32_(0x1)                                        /* (PPS_RPA13G3R) SERCOM0/PAD1  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM0P0_Val   _UINT32_(0x2)                                        /* (PPS_RPA13G3R) SERCOM0/PAD0  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM0P3_Val   _UINT32_(0x3)                                        /* (PPS_RPA13G3R) SERCOM0/PAD3  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM1P2_Val   _UINT32_(0x4)                                        /* (PPS_RPA13G3R) SERCOM1/PAD2  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM1P0_Val   _UINT32_(0x5)                                        /* (PPS_RPA13G3R) SERCOM1/PAD0  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM1P3_Val   _UINT32_(0x6)                                        /* (PPS_RPA13G3R) SERCOM1/PAD3  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM2P2_Val   _UINT32_(0x7)                                        /* (PPS_RPA13G3R) SERCOM2/PAD2  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM2P3_Val   _UINT32_(0x8)                                        /* (PPS_RPA13G3R) SERCOM2/PAD3  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM3P2_Val   _UINT32_(0x9)                                        /* (PPS_RPA13G3R) SERCOM3/PAD2  */
#define   PPS_RPA13G3R_RPA13G3R_SCOM3P1_Val   _UINT32_(0xA)                                        /* (PPS_RPA13G3R) SERCOM3/PAD1  */
#define   PPS_RPA13G3R_RPA13G3R_TCC0WO2_Val   _UINT32_(0xB)                                        /* (PPS_RPA13G3R) TCC0/WO2  */
#define   PPS_RPA13G3R_RPA13G3R_TCC0WO0_Val   _UINT32_(0xC)                                        /* (PPS_RPA13G3R) TCC0/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_TCC0WO4_Val   _UINT32_(0xD)                                        /* (PPS_RPA13G3R) TCC0/WO4  */
#define   PPS_RPA13G3R_RPA13G3R_TCC1WO2_Val   _UINT32_(0xE)                                        /* (PPS_RPA13G3R) TCC1/WO2  */
#define   PPS_RPA13G3R_RPA13G3R_TCC1WO0_Val   _UINT32_(0xF)                                        /* (PPS_RPA13G3R) TCC1/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_TCC1WO4_Val   _UINT32_(0x10)                                       /* (PPS_RPA13G3R) TCC1/WO4  */
#define   PPS_RPA13G3R_RPA13G3R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPA13G3R) TCC2/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPA13G3R) TC0/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_REFO3_Val     _UINT32_(0x13)                                       /* (PPS_RPA13G3R) REFO3  */
#define   PPS_RPA13G3R_RPA13G3R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPA13G3R) TC1/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPA13G3R) TC2/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPA13G3R) TC3/WO0  */
#define   PPS_RPA13G3R_RPA13G3R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPA13G3R) QSCK  */
#define   PPS_RPA13G3R_RPA13G3R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPA13G3R) QCS  */
#define   PPS_RPA13G3R_RPA13G3R_QD1_Val       _UINT32_(0x19)                                       /* (PPS_RPA13G3R) QD1  */
#define   PPS_RPA13G3R_RPA13G3R_QD0_Val       _UINT32_(0x1A)                                       /* (PPS_RPA13G3R) QD0  */
#define   PPS_RPA13G3R_RPA13G3R_QD3_Val       _UINT32_(0x1B)                                       /* (PPS_RPA13G3R) QD3  */
#define   PPS_RPA13G3R_RPA13G3R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPA13G3R) CCLOUT0  */
#define   PPS_RPA13G3R_RPA13G3R_TSTBUS2_Val   _UINT32_(0x1D)                                       /* (PPS_RPA13G3R) TSTBUS2  */
#define   PPS_RPA13G3R_RPA13G3R_TSTBUS6_Val   _UINT32_(0x1E)                                       /* (PPS_RPA13G3R) TSTBUS6  */
#define   PPS_RPA13G3R_RPA13G3R_TSTBUS10_Val  _UINT32_(0x1F)                                       /* (PPS_RPA13G3R) TSTBUS10  */
#define PPS_RPA13G3R_RPA13G3R_OFF             (PPS_RPA13G3R_RPA13G3R_OFF_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) OFF Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM0P1         (PPS_RPA13G3R_RPA13G3R_SCOM0P1_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM0/PAD1 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM0P0         (PPS_RPA13G3R_RPA13G3R_SCOM0P0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM0/PAD0 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM0P3         (PPS_RPA13G3R_RPA13G3R_SCOM0P3_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM0/PAD3 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM1P2         (PPS_RPA13G3R_RPA13G3R_SCOM1P2_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM1/PAD2 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM1P0         (PPS_RPA13G3R_RPA13G3R_SCOM1P0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM1/PAD0 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM1P3         (PPS_RPA13G3R_RPA13G3R_SCOM1P3_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM1/PAD3 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM2P2         (PPS_RPA13G3R_RPA13G3R_SCOM2P2_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM2/PAD2 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM2P3         (PPS_RPA13G3R_RPA13G3R_SCOM2P3_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM2/PAD3 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM3P2         (PPS_RPA13G3R_RPA13G3R_SCOM3P2_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM3/PAD2 Position  */
#define PPS_RPA13G3R_RPA13G3R_SCOM3P1         (PPS_RPA13G3R_RPA13G3R_SCOM3P1_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) SERCOM3/PAD1 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC0WO2         (PPS_RPA13G3R_RPA13G3R_TCC0WO2_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC0/WO2 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC0WO0         (PPS_RPA13G3R_RPA13G3R_TCC0WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC0/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC0WO4         (PPS_RPA13G3R_RPA13G3R_TCC0WO4_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC0/WO4 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC1WO2         (PPS_RPA13G3R_RPA13G3R_TCC1WO2_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC1/WO2 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC1WO0         (PPS_RPA13G3R_RPA13G3R_TCC1WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC1/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC1WO4         (PPS_RPA13G3R_RPA13G3R_TCC1WO4_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC1/WO4 Position  */
#define PPS_RPA13G3R_RPA13G3R_TCC2WO0         (PPS_RPA13G3R_RPA13G3R_TCC2WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TCC2/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_TC0WO0          (PPS_RPA13G3R_RPA13G3R_TC0WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TC0/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_REFO3           (PPS_RPA13G3R_RPA13G3R_REFO3_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) REFO3 Position  */
#define PPS_RPA13G3R_RPA13G3R_TC1WO0          (PPS_RPA13G3R_RPA13G3R_TC1WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TC1/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_TC2WO0          (PPS_RPA13G3R_RPA13G3R_TC2WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TC2/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_TC3WO0          (PPS_RPA13G3R_RPA13G3R_TC3WO0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TC3/WO0 Position  */
#define PPS_RPA13G3R_RPA13G3R_QSCK            (PPS_RPA13G3R_RPA13G3R_QSCK_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) QSCK Position  */
#define PPS_RPA13G3R_RPA13G3R_QCS             (PPS_RPA13G3R_RPA13G3R_QCS_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) QCS Position  */
#define PPS_RPA13G3R_RPA13G3R_QD1             (PPS_RPA13G3R_RPA13G3R_QD1_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) QD1 Position  */
#define PPS_RPA13G3R_RPA13G3R_QD0             (PPS_RPA13G3R_RPA13G3R_QD0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) QD0 Position  */
#define PPS_RPA13G3R_RPA13G3R_QD3             (PPS_RPA13G3R_RPA13G3R_QD3_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) QD3 Position  */
#define PPS_RPA13G3R_RPA13G3R_CCLOUT0         (PPS_RPA13G3R_RPA13G3R_CCLOUT0_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) CCLOUT0 Position  */
#define PPS_RPA13G3R_RPA13G3R_TSTBUS2         (PPS_RPA13G3R_RPA13G3R_TSTBUS2_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TSTBUS2 Position  */
#define PPS_RPA13G3R_RPA13G3R_TSTBUS6         (PPS_RPA13G3R_RPA13G3R_TSTBUS6_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TSTBUS6 Position  */
#define PPS_RPA13G3R_RPA13G3R_TSTBUS10        (PPS_RPA13G3R_RPA13G3R_TSTBUS10_Val << PPS_RPA13G3R_RPA13G3R_Pos) /* (PPS_RPA13G3R) TSTBUS10 Position  */
#define PPS_RPA13G3R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPA13G3R) Register Mask  */


/* -------- PPS_RPA13G4R : (PPS Offset: 0x27C) (R/W 32)  -------- */
#define PPS_RPA13G4R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPA13G4R)   Reset Value */

#define PPS_RPA13G4R_RPA13G4R_Pos             _UINT32_(0)                                          /* (PPS_RPA13G4R) RPA13/G4 Position */
#define PPS_RPA13G4R_RPA13G4R_Msk             (_UINT32_(0x1F) << PPS_RPA13G4R_RPA13G4R_Pos)        /* (PPS_RPA13G4R) RPA13/G4 Mask */
#define PPS_RPA13G4R_RPA13G4R(value)          (PPS_RPA13G4R_RPA13G4R_Msk & (_UINT32_(value) << PPS_RPA13G4R_RPA13G4R_Pos)) /* Assigment of value for RPA13G4R in the PPS_RPA13G4R register */
#define   PPS_RPA13G4R_RPA13G4R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPA13G4R) OFF  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM0P2_Val   _UINT32_(0x1)                                        /* (PPS_RPA13G4R) SERCOM0/PAD2  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM0P1_Val   _UINT32_(0x2)                                        /* (PPS_RPA13G4R) SERCOM0/PAD1  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM0P0_Val   _UINT32_(0x3)                                        /* (PPS_RPA13G4R) SERCOM0/PAD0  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM1P3_Val   _UINT32_(0x4)                                        /* (PPS_RPA13G4R) SERCOM1/PAD3  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM1P1_Val   _UINT32_(0x5)                                        /* (PPS_RPA13G4R) SERCOM1/PAD1  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM1P0_Val   _UINT32_(0x6)                                        /* (PPS_RPA13G4R) SERCOM1/PAD0  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM2P3_Val   _UINT32_(0x7)                                        /* (PPS_RPA13G4R) SERCOM2/PAD3  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM2P0_Val   _UINT32_(0x8)                                        /* (PPS_RPA13G4R) SERCOM2/PAD0  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM3P3_Val   _UINT32_(0x9)                                        /* (PPS_RPA13G4R) SERCOM3/PAD3  */
#define   PPS_RPA13G4R_RPA13G4R_SCOM3P2_Val   _UINT32_(0xA)                                        /* (PPS_RPA13G4R) SERCOM3/PAD2  */
#define   PPS_RPA13G4R_RPA13G4R_TCC0WO3_Val   _UINT32_(0xB)                                        /* (PPS_RPA13G4R) TCC0/WO3  */
#define   PPS_RPA13G4R_RPA13G4R_TCC0WO1_Val   _UINT32_(0xC)                                        /* (PPS_RPA13G4R) TCC0/WO1  */
#define   PPS_RPA13G4R_RPA13G4R_TCC0WO5_Val   _UINT32_(0xD)                                        /* (PPS_RPA13G4R) TCC0/WO5  */
#define   PPS_RPA13G4R_RPA13G4R_TCC1WO3_Val   _UINT32_(0xE)                                        /* (PPS_RPA13G4R) TCC1/WO3  */
#define   PPS_RPA13G4R_RPA13G4R_TCC1WO1_Val   _UINT32_(0xF)                                        /* (PPS_RPA13G4R) TCC1/WO1  */
#define   PPS_RPA13G4R_RPA13G4R_TCC1WO5_Val   _UINT32_(0x10)                                       /* (PPS_RPA13G4R) TCC1/WO5  */
#define   PPS_RPA13G4R_RPA13G4R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPA13G4R) TCC2/WO1  */
#define   PPS_RPA13G4R_RPA13G4R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPA13G4R) TC0/WO0  */
#define   PPS_RPA13G4R_RPA13G4R_REFO4_Val     _UINT32_(0x13)                                       /* (PPS_RPA13G4R) REFO4  */
#define   PPS_RPA13G4R_RPA13G4R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPA13G4R) TC1/WO1  */
#define   PPS_RPA13G4R_RPA13G4R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPA13G4R) TC2/WO1  */
#define   PPS_RPA13G4R_RPA13G4R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPA13G4R) TC3/WO1  */
#define   PPS_RPA13G4R_RPA13G4R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPA13G4R) QSCK  */
#define   PPS_RPA13G4R_RPA13G4R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPA13G4R) QCS  */
#define   PPS_RPA13G4R_RPA13G4R_QD2_Val       _UINT32_(0x19)                                       /* (PPS_RPA13G4R) QD2  */
#define   PPS_RPA13G4R_RPA13G4R_QD1_Val       _UINT32_(0x1A)                                       /* (PPS_RPA13G4R) QD1  */
#define   PPS_RPA13G4R_RPA13G4R_QD0_Val       _UINT32_(0x1B)                                       /* (PPS_RPA13G4R) QD0  */
#define   PPS_RPA13G4R_RPA13G4R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPA13G4R) CCLOUT1  */
#define   PPS_RPA13G4R_RPA13G4R_TSTBUS3_Val   _UINT32_(0x1D)                                       /* (PPS_RPA13G4R) TSTBUS3  */
#define   PPS_RPA13G4R_RPA13G4R_TSTBUS7_Val   _UINT32_(0x1E)                                       /* (PPS_RPA13G4R) TSTBUS7  */
#define   PPS_RPA13G4R_RPA13G4R_TSTBUS11_Val  _UINT32_(0x1F)                                       /* (PPS_RPA13G4R) TSTBUS11  */
#define PPS_RPA13G4R_RPA13G4R_OFF             (PPS_RPA13G4R_RPA13G4R_OFF_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) OFF Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM0P2         (PPS_RPA13G4R_RPA13G4R_SCOM0P2_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM0P1         (PPS_RPA13G4R_RPA13G4R_SCOM0P1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM0P0         (PPS_RPA13G4R_RPA13G4R_SCOM0P0_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM1P3         (PPS_RPA13G4R_RPA13G4R_SCOM1P3_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM1P1         (PPS_RPA13G4R_RPA13G4R_SCOM1P1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM1P0         (PPS_RPA13G4R_RPA13G4R_SCOM1P0_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM2P3         (PPS_RPA13G4R_RPA13G4R_SCOM2P3_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM2P0         (PPS_RPA13G4R_RPA13G4R_SCOM2P0_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM3P3         (PPS_RPA13G4R_RPA13G4R_SCOM3P3_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA13G4R_RPA13G4R_SCOM3P2         (PPS_RPA13G4R_RPA13G4R_SCOM3P2_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC0WO3         (PPS_RPA13G4R_RPA13G4R_TCC0WO3_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC0/WO3 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC0WO1         (PPS_RPA13G4R_RPA13G4R_TCC0WO1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC0/WO1 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC0WO5         (PPS_RPA13G4R_RPA13G4R_TCC0WO5_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC0/WO5 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC1WO3         (PPS_RPA13G4R_RPA13G4R_TCC1WO3_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC1/WO3 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC1WO1         (PPS_RPA13G4R_RPA13G4R_TCC1WO1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC1/WO1 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC1WO5         (PPS_RPA13G4R_RPA13G4R_TCC1WO5_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC1/WO5 Position  */
#define PPS_RPA13G4R_RPA13G4R_TCC2WO1         (PPS_RPA13G4R_RPA13G4R_TCC2WO1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TCC2/WO1 Position  */
#define PPS_RPA13G4R_RPA13G4R_TC0WO0          (PPS_RPA13G4R_RPA13G4R_TC0WO0_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TC0/WO0 Position  */
#define PPS_RPA13G4R_RPA13G4R_REFO4           (PPS_RPA13G4R_RPA13G4R_REFO4_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) REFO4 Position  */
#define PPS_RPA13G4R_RPA13G4R_TC1WO1          (PPS_RPA13G4R_RPA13G4R_TC1WO1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TC1/WO1 Position  */
#define PPS_RPA13G4R_RPA13G4R_TC2WO1          (PPS_RPA13G4R_RPA13G4R_TC2WO1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TC2/WO1 Position  */
#define PPS_RPA13G4R_RPA13G4R_TC3WO1          (PPS_RPA13G4R_RPA13G4R_TC3WO1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TC3/WO1 Position  */
#define PPS_RPA13G4R_RPA13G4R_QSCK            (PPS_RPA13G4R_RPA13G4R_QSCK_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) QSCK Position  */
#define PPS_RPA13G4R_RPA13G4R_QCS             (PPS_RPA13G4R_RPA13G4R_QCS_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) QCS Position  */
#define PPS_RPA13G4R_RPA13G4R_QD2             (PPS_RPA13G4R_RPA13G4R_QD2_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) QD2 Position  */
#define PPS_RPA13G4R_RPA13G4R_QD1             (PPS_RPA13G4R_RPA13G4R_QD1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) QD1 Position  */
#define PPS_RPA13G4R_RPA13G4R_QD0             (PPS_RPA13G4R_RPA13G4R_QD0_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) QD0 Position  */
#define PPS_RPA13G4R_RPA13G4R_CCLOUT1         (PPS_RPA13G4R_RPA13G4R_CCLOUT1_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) CCLOUT1 Position  */
#define PPS_RPA13G4R_RPA13G4R_TSTBUS3         (PPS_RPA13G4R_RPA13G4R_TSTBUS3_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TSTBUS3 Position  */
#define PPS_RPA13G4R_RPA13G4R_TSTBUS7         (PPS_RPA13G4R_RPA13G4R_TSTBUS7_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TSTBUS7 Position  */
#define PPS_RPA13G4R_RPA13G4R_TSTBUS11        (PPS_RPA13G4R_RPA13G4R_TSTBUS11_Val << PPS_RPA13G4R_RPA13G4R_Pos) /* (PPS_RPA13G4R) TSTBUS11 Position  */
#define PPS_RPA13G4R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPA13G4R) Register Mask  */


/* -------- PPS_RPA14G1R : (PPS Offset: 0x280) (R/W 32)  -------- */
#define PPS_RPA14G1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPA14G1R)   Reset Value */

#define PPS_RPA14G1R_RPA14G1R_Pos             _UINT32_(0)                                          /* (PPS_RPA14G1R) RPA14/G1 Position */
#define PPS_RPA14G1R_RPA14G1R_Msk             (_UINT32_(0x1F) << PPS_RPA14G1R_RPA14G1R_Pos)        /* (PPS_RPA14G1R) RPA14/G1 Mask */
#define PPS_RPA14G1R_RPA14G1R(value)          (PPS_RPA14G1R_RPA14G1R_Msk & (_UINT32_(value) << PPS_RPA14G1R_RPA14G1R_Pos)) /* Assigment of value for RPA14G1R in the PPS_RPA14G1R register */
#define   PPS_RPA14G1R_RPA14G1R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPA14G1R) OFF  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM0P3_Val   _UINT32_(0x1)                                        /* (PPS_RPA14G1R) SERCOM0/PAD3  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM0P2_Val   _UINT32_(0x2)                                        /* (PPS_RPA14G1R) SERCOM0/PAD2  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM0P1_Val   _UINT32_(0x3)                                        /* (PPS_RPA14G1R) SERCOM0/PAD1  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM1P0_Val   _UINT32_(0x4)                                        /* (PPS_RPA14G1R) SERCOM1/PAD0  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM1P2_Val   _UINT32_(0x5)                                        /* (PPS_RPA14G1R) SERCOM1/PAD2  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM1P1_Val   _UINT32_(0x6)                                        /* (PPS_RPA14G1R) SERCOM1/PAD1  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM2P0_Val   _UINT32_(0x7)                                        /* (PPS_RPA14G1R) SERCOM2/PAD0  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM2P1_Val   _UINT32_(0x8)                                        /* (PPS_RPA14G1R) SERCOM2/PAD1  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM3P0_Val   _UINT32_(0x9)                                        /* (PPS_RPA14G1R) SERCOM3/PAD0  */
#define   PPS_RPA14G1R_RPA14G1R_SCOM3P3_Val   _UINT32_(0xA)                                        /* (PPS_RPA14G1R) SERCOM3/PAD3  */
#define   PPS_RPA14G1R_RPA14G1R_TCC0WO0_Val   _UINT32_(0xB)                                        /* (PPS_RPA14G1R) TCC0/WO0  */
#define   PPS_RPA14G1R_RPA14G1R_TCC0WO4_Val   _UINT32_(0xC)                                        /* (PPS_RPA14G1R) TCC0/WO4  */
#define   PPS_RPA14G1R_RPA14G1R_TCC0WO2_Val   _UINT32_(0xD)                                        /* (PPS_RPA14G1R) TCC0/WO2  */
#define   PPS_RPA14G1R_RPA14G1R_TCC1WO0_Val   _UINT32_(0xE)                                        /* (PPS_RPA14G1R) TCC1/WO0  */
#define   PPS_RPA14G1R_RPA14G1R_TCC1WO4_Val   _UINT32_(0xF)                                        /* (PPS_RPA14G1R) TCC1/WO4  */
#define   PPS_RPA14G1R_RPA14G1R_TCC1WO2_Val   _UINT32_(0x10)                                       /* (PPS_RPA14G1R) TCC1/WO2  */
#define   PPS_RPA14G1R_RPA14G1R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPA14G1R) TCC2/WO0  */
#define   PPS_RPA14G1R_RPA14G1R_TC0WO1_Val    _UINT32_(0x12)                                       /* (PPS_RPA14G1R) TC0/WO1  */
#define   PPS_RPA14G1R_RPA14G1R_REFO1_Val     _UINT32_(0x13)                                       /* (PPS_RPA14G1R) REFO1  */
#define   PPS_RPA14G1R_RPA14G1R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPA14G1R) TC1/WO0  */
#define   PPS_RPA14G1R_RPA14G1R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPA14G1R) TC2/WO0  */
#define   PPS_RPA14G1R_RPA14G1R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPA14G1R) TC3/WO0  */
#define   PPS_RPA14G1R_RPA14G1R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPA14G1R) QSCK  */
#define   PPS_RPA14G1R_RPA14G1R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPA14G1R) QCS  */
#define   PPS_RPA14G1R_RPA14G1R_QD3_Val       _UINT32_(0x19)                                       /* (PPS_RPA14G1R) QD3  */
#define   PPS_RPA14G1R_RPA14G1R_QD2_Val       _UINT32_(0x1A)                                       /* (PPS_RPA14G1R) QD2  */
#define   PPS_RPA14G1R_RPA14G1R_QD1_Val       _UINT32_(0x1B)                                       /* (PPS_RPA14G1R) QD1  */
#define   PPS_RPA14G1R_RPA14G1R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPA14G1R) CCLOUT0  */
#define   PPS_RPA14G1R_RPA14G1R_TSTBUS0_Val   _UINT32_(0x1D)                                       /* (PPS_RPA14G1R) TSTBUS0  */
#define   PPS_RPA14G1R_RPA14G1R_TSTBUS4_Val   _UINT32_(0x1E)                                       /* (PPS_RPA14G1R) TSTBUS4  */
#define   PPS_RPA14G1R_RPA14G1R_TSTBUS8_Val   _UINT32_(0x1F)                                       /* (PPS_RPA14G1R) TSTBUS8  */
#define PPS_RPA14G1R_RPA14G1R_OFF             (PPS_RPA14G1R_RPA14G1R_OFF_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) OFF Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM0P3         (PPS_RPA14G1R_RPA14G1R_SCOM0P3_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM0/PAD3 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM0P2         (PPS_RPA14G1R_RPA14G1R_SCOM0P2_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM0/PAD2 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM0P1         (PPS_RPA14G1R_RPA14G1R_SCOM0P1_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM0/PAD1 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM1P0         (PPS_RPA14G1R_RPA14G1R_SCOM1P0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM1/PAD0 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM1P2         (PPS_RPA14G1R_RPA14G1R_SCOM1P2_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM1/PAD2 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM1P1         (PPS_RPA14G1R_RPA14G1R_SCOM1P1_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM1/PAD1 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM2P0         (PPS_RPA14G1R_RPA14G1R_SCOM2P0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM2/PAD0 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM2P1         (PPS_RPA14G1R_RPA14G1R_SCOM2P1_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM2/PAD1 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM3P0         (PPS_RPA14G1R_RPA14G1R_SCOM3P0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM3/PAD0 Position  */
#define PPS_RPA14G1R_RPA14G1R_SCOM3P3         (PPS_RPA14G1R_RPA14G1R_SCOM3P3_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) SERCOM3/PAD3 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC0WO0         (PPS_RPA14G1R_RPA14G1R_TCC0WO0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC0/WO0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC0WO4         (PPS_RPA14G1R_RPA14G1R_TCC0WO4_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC0/WO4 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC0WO2         (PPS_RPA14G1R_RPA14G1R_TCC0WO2_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC0/WO2 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC1WO0         (PPS_RPA14G1R_RPA14G1R_TCC1WO0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC1/WO0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC1WO4         (PPS_RPA14G1R_RPA14G1R_TCC1WO4_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC1/WO4 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC1WO2         (PPS_RPA14G1R_RPA14G1R_TCC1WO2_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC1/WO2 Position  */
#define PPS_RPA14G1R_RPA14G1R_TCC2WO0         (PPS_RPA14G1R_RPA14G1R_TCC2WO0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TCC2/WO0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TC0WO1          (PPS_RPA14G1R_RPA14G1R_TC0WO1_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TC0/WO1 Position  */
#define PPS_RPA14G1R_RPA14G1R_REFO1           (PPS_RPA14G1R_RPA14G1R_REFO1_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) REFO1 Position  */
#define PPS_RPA14G1R_RPA14G1R_TC1WO0          (PPS_RPA14G1R_RPA14G1R_TC1WO0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TC1/WO0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TC2WO0          (PPS_RPA14G1R_RPA14G1R_TC2WO0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TC2/WO0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TC3WO0          (PPS_RPA14G1R_RPA14G1R_TC3WO0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TC3/WO0 Position  */
#define PPS_RPA14G1R_RPA14G1R_QSCK            (PPS_RPA14G1R_RPA14G1R_QSCK_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) QSCK Position  */
#define PPS_RPA14G1R_RPA14G1R_QCS             (PPS_RPA14G1R_RPA14G1R_QCS_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) QCS Position  */
#define PPS_RPA14G1R_RPA14G1R_QD3             (PPS_RPA14G1R_RPA14G1R_QD3_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) QD3 Position  */
#define PPS_RPA14G1R_RPA14G1R_QD2             (PPS_RPA14G1R_RPA14G1R_QD2_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) QD2 Position  */
#define PPS_RPA14G1R_RPA14G1R_QD1             (PPS_RPA14G1R_RPA14G1R_QD1_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) QD1 Position  */
#define PPS_RPA14G1R_RPA14G1R_CCLOUT0         (PPS_RPA14G1R_RPA14G1R_CCLOUT0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) CCLOUT0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TSTBUS0         (PPS_RPA14G1R_RPA14G1R_TSTBUS0_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TSTBUS0 Position  */
#define PPS_RPA14G1R_RPA14G1R_TSTBUS4         (PPS_RPA14G1R_RPA14G1R_TSTBUS4_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TSTBUS4 Position  */
#define PPS_RPA14G1R_RPA14G1R_TSTBUS8         (PPS_RPA14G1R_RPA14G1R_TSTBUS8_Val << PPS_RPA14G1R_RPA14G1R_Pos) /* (PPS_RPA14G1R) TSTBUS8 Position  */
#define PPS_RPA14G1R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPA14G1R) Register Mask  */


/* -------- PPS_RPA14G4R : (PPS Offset: 0x284) (R/W 32)  -------- */
#define PPS_RPA14G4R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPA14G4R)   Reset Value */

#define PPS_RPA14G4R_RPA14G4R_Pos             _UINT32_(0)                                          /* (PPS_RPA14G4R) RPA14/G4 Position */
#define PPS_RPA14G4R_RPA14G4R_Msk             (_UINT32_(0x1F) << PPS_RPA14G4R_RPA14G4R_Pos)        /* (PPS_RPA14G4R) RPA14/G4 Mask */
#define PPS_RPA14G4R_RPA14G4R(value)          (PPS_RPA14G4R_RPA14G4R_Msk & (_UINT32_(value) << PPS_RPA14G4R_RPA14G4R_Pos)) /* Assigment of value for RPA14G4R in the PPS_RPA14G4R register */
#define   PPS_RPA14G4R_RPA14G4R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPA14G4R) OFF  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM0P2_Val   _UINT32_(0x1)                                        /* (PPS_RPA14G4R) SERCOM0/PAD2  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM0P1_Val   _UINT32_(0x2)                                        /* (PPS_RPA14G4R) SERCOM0/PAD1  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM0P0_Val   _UINT32_(0x3)                                        /* (PPS_RPA14G4R) SERCOM0/PAD0  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM1P3_Val   _UINT32_(0x4)                                        /* (PPS_RPA14G4R) SERCOM1/PAD3  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM1P1_Val   _UINT32_(0x5)                                        /* (PPS_RPA14G4R) SERCOM1/PAD1  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM1P0_Val   _UINT32_(0x6)                                        /* (PPS_RPA14G4R) SERCOM1/PAD0  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM2P3_Val   _UINT32_(0x7)                                        /* (PPS_RPA14G4R) SERCOM2/PAD3  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM2P0_Val   _UINT32_(0x8)                                        /* (PPS_RPA14G4R) SERCOM2/PAD0  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM3P3_Val   _UINT32_(0x9)                                        /* (PPS_RPA14G4R) SERCOM3/PAD3  */
#define   PPS_RPA14G4R_RPA14G4R_SCOM3P2_Val   _UINT32_(0xA)                                        /* (PPS_RPA14G4R) SERCOM3/PAD2  */
#define   PPS_RPA14G4R_RPA14G4R_TCC0WO3_Val   _UINT32_(0xB)                                        /* (PPS_RPA14G4R) TCC0/WO3  */
#define   PPS_RPA14G4R_RPA14G4R_TCC0WO1_Val   _UINT32_(0xC)                                        /* (PPS_RPA14G4R) TCC0/WO1  */
#define   PPS_RPA14G4R_RPA14G4R_TCC0WO5_Val   _UINT32_(0xD)                                        /* (PPS_RPA14G4R) TCC0/WO5  */
#define   PPS_RPA14G4R_RPA14G4R_TCC1WO3_Val   _UINT32_(0xE)                                        /* (PPS_RPA14G4R) TCC1/WO3  */
#define   PPS_RPA14G4R_RPA14G4R_TCC1WO1_Val   _UINT32_(0xF)                                        /* (PPS_RPA14G4R) TCC1/WO1  */
#define   PPS_RPA14G4R_RPA14G4R_TCC1WO5_Val   _UINT32_(0x10)                                       /* (PPS_RPA14G4R) TCC1/WO5  */
#define   PPS_RPA14G4R_RPA14G4R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPA14G4R) TCC2/WO1  */
#define   PPS_RPA14G4R_RPA14G4R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPA14G4R) TC0/WO0  */
#define   PPS_RPA14G4R_RPA14G4R_REFO4_Val     _UINT32_(0x13)                                       /* (PPS_RPA14G4R) REFO4  */
#define   PPS_RPA14G4R_RPA14G4R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPA14G4R) TC1/WO1  */
#define   PPS_RPA14G4R_RPA14G4R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPA14G4R) TC2/WO1  */
#define   PPS_RPA14G4R_RPA14G4R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPA14G4R) TC3/WO1  */
#define   PPS_RPA14G4R_RPA14G4R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPA14G4R) QSCK  */
#define   PPS_RPA14G4R_RPA14G4R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPA14G4R) QCS  */
#define   PPS_RPA14G4R_RPA14G4R_QD2_Val       _UINT32_(0x19)                                       /* (PPS_RPA14G4R) QD2  */
#define   PPS_RPA14G4R_RPA14G4R_QD1_Val       _UINT32_(0x1A)                                       /* (PPS_RPA14G4R) QD1  */
#define   PPS_RPA14G4R_RPA14G4R_QD0_Val       _UINT32_(0x1B)                                       /* (PPS_RPA14G4R) QD0  */
#define   PPS_RPA14G4R_RPA14G4R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPA14G4R) CCLOUT1  */
#define   PPS_RPA14G4R_RPA14G4R_TSTBUS3_Val   _UINT32_(0x1D)                                       /* (PPS_RPA14G4R) TSTBUS3  */
#define   PPS_RPA14G4R_RPA14G4R_TSTBUS7_Val   _UINT32_(0x1E)                                       /* (PPS_RPA14G4R) TSTBUS7  */
#define   PPS_RPA14G4R_RPA14G4R_TSTBUS11_Val  _UINT32_(0x1F)                                       /* (PPS_RPA14G4R) TSTBUS11  */
#define PPS_RPA14G4R_RPA14G4R_OFF             (PPS_RPA14G4R_RPA14G4R_OFF_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) OFF Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM0P2         (PPS_RPA14G4R_RPA14G4R_SCOM0P2_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM0/PAD2 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM0P1         (PPS_RPA14G4R_RPA14G4R_SCOM0P1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM0/PAD1 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM0P0         (PPS_RPA14G4R_RPA14G4R_SCOM0P0_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM0/PAD0 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM1P3         (PPS_RPA14G4R_RPA14G4R_SCOM1P3_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM1/PAD3 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM1P1         (PPS_RPA14G4R_RPA14G4R_SCOM1P1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM1/PAD1 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM1P0         (PPS_RPA14G4R_RPA14G4R_SCOM1P0_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM1/PAD0 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM2P3         (PPS_RPA14G4R_RPA14G4R_SCOM2P3_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM2/PAD3 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM2P0         (PPS_RPA14G4R_RPA14G4R_SCOM2P0_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM2/PAD0 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM3P3         (PPS_RPA14G4R_RPA14G4R_SCOM3P3_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM3/PAD3 Position  */
#define PPS_RPA14G4R_RPA14G4R_SCOM3P2         (PPS_RPA14G4R_RPA14G4R_SCOM3P2_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) SERCOM3/PAD2 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC0WO3         (PPS_RPA14G4R_RPA14G4R_TCC0WO3_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC0/WO3 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC0WO1         (PPS_RPA14G4R_RPA14G4R_TCC0WO1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC0/WO1 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC0WO5         (PPS_RPA14G4R_RPA14G4R_TCC0WO5_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC0/WO5 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC1WO3         (PPS_RPA14G4R_RPA14G4R_TCC1WO3_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC1/WO3 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC1WO1         (PPS_RPA14G4R_RPA14G4R_TCC1WO1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC1/WO1 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC1WO5         (PPS_RPA14G4R_RPA14G4R_TCC1WO5_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC1/WO5 Position  */
#define PPS_RPA14G4R_RPA14G4R_TCC2WO1         (PPS_RPA14G4R_RPA14G4R_TCC2WO1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TCC2/WO1 Position  */
#define PPS_RPA14G4R_RPA14G4R_TC0WO0          (PPS_RPA14G4R_RPA14G4R_TC0WO0_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TC0/WO0 Position  */
#define PPS_RPA14G4R_RPA14G4R_REFO4           (PPS_RPA14G4R_RPA14G4R_REFO4_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) REFO4 Position  */
#define PPS_RPA14G4R_RPA14G4R_TC1WO1          (PPS_RPA14G4R_RPA14G4R_TC1WO1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TC1/WO1 Position  */
#define PPS_RPA14G4R_RPA14G4R_TC2WO1          (PPS_RPA14G4R_RPA14G4R_TC2WO1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TC2/WO1 Position  */
#define PPS_RPA14G4R_RPA14G4R_TC3WO1          (PPS_RPA14G4R_RPA14G4R_TC3WO1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TC3/WO1 Position  */
#define PPS_RPA14G4R_RPA14G4R_QSCK            (PPS_RPA14G4R_RPA14G4R_QSCK_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) QSCK Position  */
#define PPS_RPA14G4R_RPA14G4R_QCS             (PPS_RPA14G4R_RPA14G4R_QCS_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) QCS Position  */
#define PPS_RPA14G4R_RPA14G4R_QD2             (PPS_RPA14G4R_RPA14G4R_QD2_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) QD2 Position  */
#define PPS_RPA14G4R_RPA14G4R_QD1             (PPS_RPA14G4R_RPA14G4R_QD1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) QD1 Position  */
#define PPS_RPA14G4R_RPA14G4R_QD0             (PPS_RPA14G4R_RPA14G4R_QD0_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) QD0 Position  */
#define PPS_RPA14G4R_RPA14G4R_CCLOUT1         (PPS_RPA14G4R_RPA14G4R_CCLOUT1_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) CCLOUT1 Position  */
#define PPS_RPA14G4R_RPA14G4R_TSTBUS3         (PPS_RPA14G4R_RPA14G4R_TSTBUS3_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TSTBUS3 Position  */
#define PPS_RPA14G4R_RPA14G4R_TSTBUS7         (PPS_RPA14G4R_RPA14G4R_TSTBUS7_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TSTBUS7 Position  */
#define PPS_RPA14G4R_RPA14G4R_TSTBUS11        (PPS_RPA14G4R_RPA14G4R_TSTBUS11_Val << PPS_RPA14G4R_RPA14G4R_Pos) /* (PPS_RPA14G4R) TSTBUS11 Position  */
#define PPS_RPA14G4R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPA14G4R) Register Mask  */


/* -------- PPS_RPB0G1R : (PPS Offset: 0x28C) (R/W 32)  -------- */
#define PPS_RPB0G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB0G1R)   Reset Value */

#define PPS_RPB0G1R_RPB0G1R_Pos               _UINT32_(0)                                          /* (PPS_RPB0G1R) RPB0/G1 Position */
#define PPS_RPB0G1R_RPB0G1R_Msk               (_UINT32_(0x1F) << PPS_RPB0G1R_RPB0G1R_Pos)          /* (PPS_RPB0G1R) RPB0/G1 Mask */
#define PPS_RPB0G1R_RPB0G1R(value)            (PPS_RPB0G1R_RPB0G1R_Msk & (_UINT32_(value) << PPS_RPB0G1R_RPB0G1R_Pos)) /* Assigment of value for RPB0G1R in the PPS_RPB0G1R register */
#define   PPS_RPB0G1R_RPB0G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB0G1R) OFF  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPB0G1R) SERCOM0/PAD3  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPB0G1R) SERCOM0/PAD2  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPB0G1R) SERCOM0/PAD1  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPB0G1R) SERCOM1/PAD0  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPB0G1R) SERCOM1/PAD2  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPB0G1R) SERCOM1/PAD1  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPB0G1R) SERCOM2/PAD0  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPB0G1R) SERCOM2/PAD1  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPB0G1R) SERCOM3/PAD0  */
#define   PPS_RPB0G1R_RPB0G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPB0G1R) SERCOM3/PAD3  */
#define   PPS_RPB0G1R_RPB0G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPB0G1R) TCC0/WO0  */
#define   PPS_RPB0G1R_RPB0G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPB0G1R) TCC0/WO4  */
#define   PPS_RPB0G1R_RPB0G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPB0G1R) TCC0/WO2  */
#define   PPS_RPB0G1R_RPB0G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPB0G1R) TCC1/WO0  */
#define   PPS_RPB0G1R_RPB0G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPB0G1R) TCC1/WO4  */
#define   PPS_RPB0G1R_RPB0G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPB0G1R) TCC1/WO2  */
#define   PPS_RPB0G1R_RPB0G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB0G1R) TCC2/WO0  */
#define   PPS_RPB0G1R_RPB0G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB0G1R) TC0/WO1  */
#define   PPS_RPB0G1R_RPB0G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPB0G1R) REFO1  */
#define   PPS_RPB0G1R_RPB0G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB0G1R) TC1/WO0  */
#define   PPS_RPB0G1R_RPB0G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB0G1R) TC2/WO0  */
#define   PPS_RPB0G1R_RPB0G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB0G1R) TC3/WO0  */
#define   PPS_RPB0G1R_RPB0G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB0G1R) QSCK  */
#define   PPS_RPB0G1R_RPB0G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB0G1R) QCS  */
#define   PPS_RPB0G1R_RPB0G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPB0G1R) QD3  */
#define   PPS_RPB0G1R_RPB0G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPB0G1R) QD2  */
#define   PPS_RPB0G1R_RPB0G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPB0G1R) QD1  */
#define   PPS_RPB0G1R_RPB0G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB0G1R) CCLOUT0  */
#define   PPS_RPB0G1R_RPB0G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPB0G1R) TSTBUS0  */
#define   PPS_RPB0G1R_RPB0G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPB0G1R) TSTBUS4  */
#define   PPS_RPB0G1R_RPB0G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPB0G1R) TSTBUS8  */
#define PPS_RPB0G1R_RPB0G1R_OFF               (PPS_RPB0G1R_RPB0G1R_OFF_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) OFF Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM0P3           (PPS_RPB0G1R_RPB0G1R_SCOM0P3_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM0P2           (PPS_RPB0G1R_RPB0G1R_SCOM0P2_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM0P1           (PPS_RPB0G1R_RPB0G1R_SCOM0P1_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM1P0           (PPS_RPB0G1R_RPB0G1R_SCOM1P0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM1P2           (PPS_RPB0G1R_RPB0G1R_SCOM1P2_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM1P1           (PPS_RPB0G1R_RPB0G1R_SCOM1P1_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM2P0           (PPS_RPB0G1R_RPB0G1R_SCOM2P0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM2P1           (PPS_RPB0G1R_RPB0G1R_SCOM2P1_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM3P0           (PPS_RPB0G1R_RPB0G1R_SCOM3P0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB0G1R_RPB0G1R_SCOM3P3           (PPS_RPB0G1R_RPB0G1R_SCOM3P3_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC0WO0           (PPS_RPB0G1R_RPB0G1R_TCC0WO0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC0/WO0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC0WO4           (PPS_RPB0G1R_RPB0G1R_TCC0WO4_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC0/WO4 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC0WO2           (PPS_RPB0G1R_RPB0G1R_TCC0WO2_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC0/WO2 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC1WO0           (PPS_RPB0G1R_RPB0G1R_TCC1WO0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC1/WO0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC1WO4           (PPS_RPB0G1R_RPB0G1R_TCC1WO4_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC1/WO4 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC1WO2           (PPS_RPB0G1R_RPB0G1R_TCC1WO2_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC1/WO2 Position  */
#define PPS_RPB0G1R_RPB0G1R_TCC2WO0           (PPS_RPB0G1R_RPB0G1R_TCC2WO0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TCC2/WO0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TC0WO1            (PPS_RPB0G1R_RPB0G1R_TC0WO1_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TC0/WO1 Position  */
#define PPS_RPB0G1R_RPB0G1R_REFO1             (PPS_RPB0G1R_RPB0G1R_REFO1_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) REFO1 Position  */
#define PPS_RPB0G1R_RPB0G1R_TC1WO0            (PPS_RPB0G1R_RPB0G1R_TC1WO0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TC1/WO0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TC2WO0            (PPS_RPB0G1R_RPB0G1R_TC2WO0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TC2/WO0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TC3WO0            (PPS_RPB0G1R_RPB0G1R_TC3WO0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TC3/WO0 Position  */
#define PPS_RPB0G1R_RPB0G1R_QSCK              (PPS_RPB0G1R_RPB0G1R_QSCK_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) QSCK Position  */
#define PPS_RPB0G1R_RPB0G1R_QCS               (PPS_RPB0G1R_RPB0G1R_QCS_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) QCS Position  */
#define PPS_RPB0G1R_RPB0G1R_QD3               (PPS_RPB0G1R_RPB0G1R_QD3_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) QD3 Position  */
#define PPS_RPB0G1R_RPB0G1R_QD2               (PPS_RPB0G1R_RPB0G1R_QD2_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) QD2 Position  */
#define PPS_RPB0G1R_RPB0G1R_QD1               (PPS_RPB0G1R_RPB0G1R_QD1_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) QD1 Position  */
#define PPS_RPB0G1R_RPB0G1R_CCLOUT0           (PPS_RPB0G1R_RPB0G1R_CCLOUT0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) CCLOUT0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TSTBUS0           (PPS_RPB0G1R_RPB0G1R_TSTBUS0_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TSTBUS0 Position  */
#define PPS_RPB0G1R_RPB0G1R_TSTBUS4           (PPS_RPB0G1R_RPB0G1R_TSTBUS4_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TSTBUS4 Position  */
#define PPS_RPB0G1R_RPB0G1R_TSTBUS8           (PPS_RPB0G1R_RPB0G1R_TSTBUS8_Val << PPS_RPB0G1R_RPB0G1R_Pos) /* (PPS_RPB0G1R) TSTBUS8 Position  */
#define PPS_RPB0G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB0G1R) Register Mask  */


/* -------- PPS_RPB0G2R : (PPS Offset: 0x290) (R/W 32)  -------- */
#define PPS_RPB0G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB0G2R)   Reset Value */

#define PPS_RPB0G2R_RPB0G2R_Pos               _UINT32_(0)                                          /* (PPS_RPB0G2R) RPB0/G2 Position */
#define PPS_RPB0G2R_RPB0G2R_Msk               (_UINT32_(0x1F) << PPS_RPB0G2R_RPB0G2R_Pos)          /* (PPS_RPB0G2R) RPB0/G2 Mask */
#define PPS_RPB0G2R_RPB0G2R(value)            (PPS_RPB0G2R_RPB0G2R_Msk & (_UINT32_(value) << PPS_RPB0G2R_RPB0G2R_Pos)) /* Assigment of value for RPB0G2R in the PPS_RPB0G2R register */
#define   PPS_RPB0G2R_RPB0G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB0G2R) OFF  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPB0G2R) SERCOM0/PAD0  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPB0G2R) SERCOM0/PAD3  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPB0G2R) SERCOM0/PAD2  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPB0G2R) SERCOM1/PAD1  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPB0G2R) SERCOM1/PAD3  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPB0G2R) SERCOM1/PAD2  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPB0G2R) SERCOM2/PAD1  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPB0G2R) SERCOM2/PAD2  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPB0G2R) SERCOM3/PAD1  */
#define   PPS_RPB0G2R_RPB0G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPB0G2R) SERCOM3/PAD0  */
#define   PPS_RPB0G2R_RPB0G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPB0G2R) TCC0/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPB0G2R) TCC0/WO5  */
#define   PPS_RPB0G2R_RPB0G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPB0G2R) TCC0/WO3  */
#define   PPS_RPB0G2R_RPB0G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPB0G2R) TCC1/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPB0G2R) TCC1/WO5  */
#define   PPS_RPB0G2R_RPB0G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPB0G2R) TCC1/WO3  */
#define   PPS_RPB0G2R_RPB0G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB0G2R) TCC2/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB0G2R) TC0/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPB0G2R) REFO2  */
#define   PPS_RPB0G2R_RPB0G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB0G2R) TC1/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB0G2R) TC2/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB0G2R) TC3/WO1  */
#define   PPS_RPB0G2R_RPB0G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB0G2R) QSCK  */
#define   PPS_RPB0G2R_RPB0G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB0G2R) QCS  */
#define   PPS_RPB0G2R_RPB0G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPB0G2R) QD0  */
#define   PPS_RPB0G2R_RPB0G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPB0G2R) QD3  */
#define   PPS_RPB0G2R_RPB0G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPB0G2R) QD2  */
#define   PPS_RPB0G2R_RPB0G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB0G2R) CCLOUT1  */
#define   PPS_RPB0G2R_RPB0G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPB0G2R) TSTBUS1  */
#define   PPS_RPB0G2R_RPB0G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPB0G2R) TSTBUS5  */
#define   PPS_RPB0G2R_RPB0G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPB0G2R) TSTBUS9  */
#define PPS_RPB0G2R_RPB0G2R_OFF               (PPS_RPB0G2R_RPB0G2R_OFF_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) OFF Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM0P0           (PPS_RPB0G2R_RPB0G2R_SCOM0P0_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM0P3           (PPS_RPB0G2R_RPB0G2R_SCOM0P3_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM0P2           (PPS_RPB0G2R_RPB0G2R_SCOM0P2_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM1P1           (PPS_RPB0G2R_RPB0G2R_SCOM1P1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM1P3           (PPS_RPB0G2R_RPB0G2R_SCOM1P3_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM1P2           (PPS_RPB0G2R_RPB0G2R_SCOM1P2_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM2P1           (PPS_RPB0G2R_RPB0G2R_SCOM2P1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM2P2           (PPS_RPB0G2R_RPB0G2R_SCOM2P2_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM3P1           (PPS_RPB0G2R_RPB0G2R_SCOM3P1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB0G2R_RPB0G2R_SCOM3P0           (PPS_RPB0G2R_RPB0G2R_SCOM3P0_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC0WO1           (PPS_RPB0G2R_RPB0G2R_TCC0WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC0/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC0WO5           (PPS_RPB0G2R_RPB0G2R_TCC0WO5_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC0/WO5 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC0WO3           (PPS_RPB0G2R_RPB0G2R_TCC0WO3_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC0/WO3 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC1WO1           (PPS_RPB0G2R_RPB0G2R_TCC1WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC1/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC1WO5           (PPS_RPB0G2R_RPB0G2R_TCC1WO5_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC1/WO5 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC1WO3           (PPS_RPB0G2R_RPB0G2R_TCC1WO3_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC1/WO3 Position  */
#define PPS_RPB0G2R_RPB0G2R_TCC2WO1           (PPS_RPB0G2R_RPB0G2R_TCC2WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TCC2/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TC0WO1            (PPS_RPB0G2R_RPB0G2R_TC0WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TC0/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_REFO2             (PPS_RPB0G2R_RPB0G2R_REFO2_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) REFO2 Position  */
#define PPS_RPB0G2R_RPB0G2R_TC1WO1            (PPS_RPB0G2R_RPB0G2R_TC1WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TC1/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TC2WO1            (PPS_RPB0G2R_RPB0G2R_TC2WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TC2/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TC3WO1            (PPS_RPB0G2R_RPB0G2R_TC3WO1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TC3/WO1 Position  */
#define PPS_RPB0G2R_RPB0G2R_QSCK              (PPS_RPB0G2R_RPB0G2R_QSCK_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) QSCK Position  */
#define PPS_RPB0G2R_RPB0G2R_QCS               (PPS_RPB0G2R_RPB0G2R_QCS_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) QCS Position  */
#define PPS_RPB0G2R_RPB0G2R_QD0               (PPS_RPB0G2R_RPB0G2R_QD0_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) QD0 Position  */
#define PPS_RPB0G2R_RPB0G2R_QD3               (PPS_RPB0G2R_RPB0G2R_QD3_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) QD3 Position  */
#define PPS_RPB0G2R_RPB0G2R_QD2               (PPS_RPB0G2R_RPB0G2R_QD2_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) QD2 Position  */
#define PPS_RPB0G2R_RPB0G2R_CCLOUT1           (PPS_RPB0G2R_RPB0G2R_CCLOUT1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) CCLOUT1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TSTBUS1           (PPS_RPB0G2R_RPB0G2R_TSTBUS1_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TSTBUS1 Position  */
#define PPS_RPB0G2R_RPB0G2R_TSTBUS5           (PPS_RPB0G2R_RPB0G2R_TSTBUS5_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TSTBUS5 Position  */
#define PPS_RPB0G2R_RPB0G2R_TSTBUS9           (PPS_RPB0G2R_RPB0G2R_TSTBUS9_Val << PPS_RPB0G2R_RPB0G2R_Pos) /* (PPS_RPB0G2R) TSTBUS9 Position  */
#define PPS_RPB0G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB0G2R) Register Mask  */


/* -------- PPS_RPB1G2R : (PPS Offset: 0x294) (R/W 32)  -------- */
#define PPS_RPB1G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB1G2R)   Reset Value */

#define PPS_RPB1G2R_RPB1G2R_Pos               _UINT32_(0)                                          /* (PPS_RPB1G2R) RPB1/G2 Position */
#define PPS_RPB1G2R_RPB1G2R_Msk               (_UINT32_(0x1F) << PPS_RPB1G2R_RPB1G2R_Pos)          /* (PPS_RPB1G2R) RPB1/G2 Mask */
#define PPS_RPB1G2R_RPB1G2R(value)            (PPS_RPB1G2R_RPB1G2R_Msk & (_UINT32_(value) << PPS_RPB1G2R_RPB1G2R_Pos)) /* Assigment of value for RPB1G2R in the PPS_RPB1G2R register */
#define   PPS_RPB1G2R_RPB1G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB1G2R) OFF  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPB1G2R) SERCOM0/PAD0  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPB1G2R) SERCOM0/PAD3  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPB1G2R) SERCOM0/PAD2  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPB1G2R) SERCOM1/PAD1  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPB1G2R) SERCOM1/PAD3  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPB1G2R) SERCOM1/PAD2  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPB1G2R) SERCOM2/PAD1  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPB1G2R) SERCOM2/PAD2  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPB1G2R) SERCOM3/PAD1  */
#define   PPS_RPB1G2R_RPB1G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPB1G2R) SERCOM3/PAD0  */
#define   PPS_RPB1G2R_RPB1G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPB1G2R) TCC0/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPB1G2R) TCC0/WO5  */
#define   PPS_RPB1G2R_RPB1G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPB1G2R) TCC0/WO3  */
#define   PPS_RPB1G2R_RPB1G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPB1G2R) TCC1/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPB1G2R) TCC1/WO5  */
#define   PPS_RPB1G2R_RPB1G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPB1G2R) TCC1/WO3  */
#define   PPS_RPB1G2R_RPB1G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB1G2R) TCC2/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB1G2R) TC0/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPB1G2R) REFO2  */
#define   PPS_RPB1G2R_RPB1G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB1G2R) TC1/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB1G2R) TC2/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB1G2R) TC3/WO1  */
#define   PPS_RPB1G2R_RPB1G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB1G2R) QSCK  */
#define   PPS_RPB1G2R_RPB1G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB1G2R) QCS  */
#define   PPS_RPB1G2R_RPB1G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPB1G2R) QD0  */
#define   PPS_RPB1G2R_RPB1G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPB1G2R) QD3  */
#define   PPS_RPB1G2R_RPB1G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPB1G2R) QD2  */
#define   PPS_RPB1G2R_RPB1G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB1G2R) CCLOUT1  */
#define   PPS_RPB1G2R_RPB1G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPB1G2R) TSTBUS1  */
#define   PPS_RPB1G2R_RPB1G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPB1G2R) TSTBUS5  */
#define   PPS_RPB1G2R_RPB1G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPB1G2R) TSTBUS9  */
#define PPS_RPB1G2R_RPB1G2R_OFF               (PPS_RPB1G2R_RPB1G2R_OFF_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) OFF Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM0P0           (PPS_RPB1G2R_RPB1G2R_SCOM0P0_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM0P3           (PPS_RPB1G2R_RPB1G2R_SCOM0P3_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM0P2           (PPS_RPB1G2R_RPB1G2R_SCOM0P2_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM1P1           (PPS_RPB1G2R_RPB1G2R_SCOM1P1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM1P3           (PPS_RPB1G2R_RPB1G2R_SCOM1P3_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM1P2           (PPS_RPB1G2R_RPB1G2R_SCOM1P2_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM2P1           (PPS_RPB1G2R_RPB1G2R_SCOM2P1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM2P2           (PPS_RPB1G2R_RPB1G2R_SCOM2P2_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM3P1           (PPS_RPB1G2R_RPB1G2R_SCOM3P1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB1G2R_RPB1G2R_SCOM3P0           (PPS_RPB1G2R_RPB1G2R_SCOM3P0_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC0WO1           (PPS_RPB1G2R_RPB1G2R_TCC0WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC0/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC0WO5           (PPS_RPB1G2R_RPB1G2R_TCC0WO5_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC0/WO5 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC0WO3           (PPS_RPB1G2R_RPB1G2R_TCC0WO3_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC0/WO3 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC1WO1           (PPS_RPB1G2R_RPB1G2R_TCC1WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC1/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC1WO5           (PPS_RPB1G2R_RPB1G2R_TCC1WO5_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC1/WO5 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC1WO3           (PPS_RPB1G2R_RPB1G2R_TCC1WO3_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC1/WO3 Position  */
#define PPS_RPB1G2R_RPB1G2R_TCC2WO1           (PPS_RPB1G2R_RPB1G2R_TCC2WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TCC2/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TC0WO1            (PPS_RPB1G2R_RPB1G2R_TC0WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TC0/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_REFO2             (PPS_RPB1G2R_RPB1G2R_REFO2_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) REFO2 Position  */
#define PPS_RPB1G2R_RPB1G2R_TC1WO1            (PPS_RPB1G2R_RPB1G2R_TC1WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TC1/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TC2WO1            (PPS_RPB1G2R_RPB1G2R_TC2WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TC2/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TC3WO1            (PPS_RPB1G2R_RPB1G2R_TC3WO1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TC3/WO1 Position  */
#define PPS_RPB1G2R_RPB1G2R_QSCK              (PPS_RPB1G2R_RPB1G2R_QSCK_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) QSCK Position  */
#define PPS_RPB1G2R_RPB1G2R_QCS               (PPS_RPB1G2R_RPB1G2R_QCS_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) QCS Position  */
#define PPS_RPB1G2R_RPB1G2R_QD0               (PPS_RPB1G2R_RPB1G2R_QD0_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) QD0 Position  */
#define PPS_RPB1G2R_RPB1G2R_QD3               (PPS_RPB1G2R_RPB1G2R_QD3_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) QD3 Position  */
#define PPS_RPB1G2R_RPB1G2R_QD2               (PPS_RPB1G2R_RPB1G2R_QD2_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) QD2 Position  */
#define PPS_RPB1G2R_RPB1G2R_CCLOUT1           (PPS_RPB1G2R_RPB1G2R_CCLOUT1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) CCLOUT1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TSTBUS1           (PPS_RPB1G2R_RPB1G2R_TSTBUS1_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TSTBUS1 Position  */
#define PPS_RPB1G2R_RPB1G2R_TSTBUS5           (PPS_RPB1G2R_RPB1G2R_TSTBUS5_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TSTBUS5 Position  */
#define PPS_RPB1G2R_RPB1G2R_TSTBUS9           (PPS_RPB1G2R_RPB1G2R_TSTBUS9_Val << PPS_RPB1G2R_RPB1G2R_Pos) /* (PPS_RPB1G2R) TSTBUS9 Position  */
#define PPS_RPB1G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB1G2R) Register Mask  */


/* -------- PPS_RPB1G3R : (PPS Offset: 0x298) (R/W 32)  -------- */
#define PPS_RPB1G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB1G3R)   Reset Value */

#define PPS_RPB1G3R_RPB1G3R_Pos               _UINT32_(0)                                          /* (PPS_RPB1G3R) RPB1/G3 Position */
#define PPS_RPB1G3R_RPB1G3R_Msk               (_UINT32_(0x1F) << PPS_RPB1G3R_RPB1G3R_Pos)          /* (PPS_RPB1G3R) RPB1/G3 Mask */
#define PPS_RPB1G3R_RPB1G3R(value)            (PPS_RPB1G3R_RPB1G3R_Msk & (_UINT32_(value) << PPS_RPB1G3R_RPB1G3R_Pos)) /* Assigment of value for RPB1G3R in the PPS_RPB1G3R register */
#define   PPS_RPB1G3R_RPB1G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB1G3R) OFF  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPB1G3R) SERCOM0/PAD1  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPB1G3R) SERCOM0/PAD0  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPB1G3R) SERCOM0/PAD3  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPB1G3R) SERCOM1/PAD2  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPB1G3R) SERCOM1/PAD0  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPB1G3R) SERCOM1/PAD3  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPB1G3R) SERCOM2/PAD2  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPB1G3R) SERCOM2/PAD3  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPB1G3R) SERCOM3/PAD2  */
#define   PPS_RPB1G3R_RPB1G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPB1G3R) SERCOM3/PAD1  */
#define   PPS_RPB1G3R_RPB1G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPB1G3R) TCC0/WO2  */
#define   PPS_RPB1G3R_RPB1G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPB1G3R) TCC0/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPB1G3R) TCC0/WO4  */
#define   PPS_RPB1G3R_RPB1G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPB1G3R) TCC1/WO2  */
#define   PPS_RPB1G3R_RPB1G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPB1G3R) TCC1/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPB1G3R) TCC1/WO4  */
#define   PPS_RPB1G3R_RPB1G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB1G3R) TCC2/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB1G3R) TC0/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPB1G3R) REFO3  */
#define   PPS_RPB1G3R_RPB1G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB1G3R) TC1/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB1G3R) TC2/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB1G3R) TC3/WO0  */
#define   PPS_RPB1G3R_RPB1G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB1G3R) QSCK  */
#define   PPS_RPB1G3R_RPB1G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB1G3R) QCS  */
#define   PPS_RPB1G3R_RPB1G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPB1G3R) QD1  */
#define   PPS_RPB1G3R_RPB1G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPB1G3R) QD0  */
#define   PPS_RPB1G3R_RPB1G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPB1G3R) QD3  */
#define   PPS_RPB1G3R_RPB1G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB1G3R) CCLOUT0  */
#define   PPS_RPB1G3R_RPB1G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPB1G3R) TSTBUS2  */
#define   PPS_RPB1G3R_RPB1G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPB1G3R) TSTBUS6  */
#define   PPS_RPB1G3R_RPB1G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPB1G3R) TSTBUS10  */
#define PPS_RPB1G3R_RPB1G3R_OFF               (PPS_RPB1G3R_RPB1G3R_OFF_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) OFF Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM0P1           (PPS_RPB1G3R_RPB1G3R_SCOM0P1_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM0P0           (PPS_RPB1G3R_RPB1G3R_SCOM0P0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM0P3           (PPS_RPB1G3R_RPB1G3R_SCOM0P3_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM1P2           (PPS_RPB1G3R_RPB1G3R_SCOM1P2_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM1P0           (PPS_RPB1G3R_RPB1G3R_SCOM1P0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM1P3           (PPS_RPB1G3R_RPB1G3R_SCOM1P3_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM2P2           (PPS_RPB1G3R_RPB1G3R_SCOM2P2_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM2P3           (PPS_RPB1G3R_RPB1G3R_SCOM2P3_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM3P2           (PPS_RPB1G3R_RPB1G3R_SCOM3P2_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB1G3R_RPB1G3R_SCOM3P1           (PPS_RPB1G3R_RPB1G3R_SCOM3P1_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC0WO2           (PPS_RPB1G3R_RPB1G3R_TCC0WO2_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC0/WO2 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC0WO0           (PPS_RPB1G3R_RPB1G3R_TCC0WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC0/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC0WO4           (PPS_RPB1G3R_RPB1G3R_TCC0WO4_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC0/WO4 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC1WO2           (PPS_RPB1G3R_RPB1G3R_TCC1WO2_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC1/WO2 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC1WO0           (PPS_RPB1G3R_RPB1G3R_TCC1WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC1/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC1WO4           (PPS_RPB1G3R_RPB1G3R_TCC1WO4_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC1/WO4 Position  */
#define PPS_RPB1G3R_RPB1G3R_TCC2WO0           (PPS_RPB1G3R_RPB1G3R_TCC2WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TCC2/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_TC0WO0            (PPS_RPB1G3R_RPB1G3R_TC0WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TC0/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_REFO3             (PPS_RPB1G3R_RPB1G3R_REFO3_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) REFO3 Position  */
#define PPS_RPB1G3R_RPB1G3R_TC1WO0            (PPS_RPB1G3R_RPB1G3R_TC1WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TC1/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_TC2WO0            (PPS_RPB1G3R_RPB1G3R_TC2WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TC2/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_TC3WO0            (PPS_RPB1G3R_RPB1G3R_TC3WO0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TC3/WO0 Position  */
#define PPS_RPB1G3R_RPB1G3R_QSCK              (PPS_RPB1G3R_RPB1G3R_QSCK_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) QSCK Position  */
#define PPS_RPB1G3R_RPB1G3R_QCS               (PPS_RPB1G3R_RPB1G3R_QCS_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) QCS Position  */
#define PPS_RPB1G3R_RPB1G3R_QD1               (PPS_RPB1G3R_RPB1G3R_QD1_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) QD1 Position  */
#define PPS_RPB1G3R_RPB1G3R_QD0               (PPS_RPB1G3R_RPB1G3R_QD0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) QD0 Position  */
#define PPS_RPB1G3R_RPB1G3R_QD3               (PPS_RPB1G3R_RPB1G3R_QD3_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) QD3 Position  */
#define PPS_RPB1G3R_RPB1G3R_CCLOUT0           (PPS_RPB1G3R_RPB1G3R_CCLOUT0_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) CCLOUT0 Position  */
#define PPS_RPB1G3R_RPB1G3R_TSTBUS2           (PPS_RPB1G3R_RPB1G3R_TSTBUS2_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TSTBUS2 Position  */
#define PPS_RPB1G3R_RPB1G3R_TSTBUS6           (PPS_RPB1G3R_RPB1G3R_TSTBUS6_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TSTBUS6 Position  */
#define PPS_RPB1G3R_RPB1G3R_TSTBUS10          (PPS_RPB1G3R_RPB1G3R_TSTBUS10_Val << PPS_RPB1G3R_RPB1G3R_Pos) /* (PPS_RPB1G3R) TSTBUS10 Position  */
#define PPS_RPB1G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB1G3R) Register Mask  */


/* -------- PPS_RPB2G3R : (PPS Offset: 0x29C) (R/W 32)  -------- */
#define PPS_RPB2G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB2G3R)   Reset Value */

#define PPS_RPB2G3R_RPB2G3R_Pos               _UINT32_(0)                                          /* (PPS_RPB2G3R) RPB2/G3 Position */
#define PPS_RPB2G3R_RPB2G3R_Msk               (_UINT32_(0x1F) << PPS_RPB2G3R_RPB2G3R_Pos)          /* (PPS_RPB2G3R) RPB2/G3 Mask */
#define PPS_RPB2G3R_RPB2G3R(value)            (PPS_RPB2G3R_RPB2G3R_Msk & (_UINT32_(value) << PPS_RPB2G3R_RPB2G3R_Pos)) /* Assigment of value for RPB2G3R in the PPS_RPB2G3R register */
#define   PPS_RPB2G3R_RPB2G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB2G3R) OFF  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPB2G3R) SERCOM0/PAD1  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPB2G3R) SERCOM0/PAD0  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPB2G3R) SERCOM0/PAD3  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPB2G3R) SERCOM1/PAD2  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPB2G3R) SERCOM1/PAD0  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPB2G3R) SERCOM1/PAD3  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPB2G3R) SERCOM2/PAD2  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPB2G3R) SERCOM2/PAD3  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPB2G3R) SERCOM3/PAD2  */
#define   PPS_RPB2G3R_RPB2G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPB2G3R) SERCOM3/PAD1  */
#define   PPS_RPB2G3R_RPB2G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPB2G3R) TCC0/WO2  */
#define   PPS_RPB2G3R_RPB2G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPB2G3R) TCC0/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPB2G3R) TCC0/WO4  */
#define   PPS_RPB2G3R_RPB2G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPB2G3R) TCC1/WO2  */
#define   PPS_RPB2G3R_RPB2G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPB2G3R) TCC1/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPB2G3R) TCC1/WO4  */
#define   PPS_RPB2G3R_RPB2G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB2G3R) TCC2/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB2G3R) TC0/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPB2G3R) REFO3  */
#define   PPS_RPB2G3R_RPB2G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB2G3R) TC1/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB2G3R) TC2/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB2G3R) TC3/WO0  */
#define   PPS_RPB2G3R_RPB2G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB2G3R) QSCK  */
#define   PPS_RPB2G3R_RPB2G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB2G3R) QCS  */
#define   PPS_RPB2G3R_RPB2G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPB2G3R) QD1  */
#define   PPS_RPB2G3R_RPB2G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPB2G3R) QD0  */
#define   PPS_RPB2G3R_RPB2G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPB2G3R) QD3  */
#define   PPS_RPB2G3R_RPB2G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB2G3R) CCLOUT0  */
#define   PPS_RPB2G3R_RPB2G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPB2G3R) TSTBUS2  */
#define   PPS_RPB2G3R_RPB2G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPB2G3R) TSTBUS6  */
#define   PPS_RPB2G3R_RPB2G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPB2G3R) TSTBUS10  */
#define PPS_RPB2G3R_RPB2G3R_OFF               (PPS_RPB2G3R_RPB2G3R_OFF_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) OFF Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM0P1           (PPS_RPB2G3R_RPB2G3R_SCOM0P1_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM0P0           (PPS_RPB2G3R_RPB2G3R_SCOM0P0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM0P3           (PPS_RPB2G3R_RPB2G3R_SCOM0P3_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM1P2           (PPS_RPB2G3R_RPB2G3R_SCOM1P2_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM1P0           (PPS_RPB2G3R_RPB2G3R_SCOM1P0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM1P3           (PPS_RPB2G3R_RPB2G3R_SCOM1P3_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM2P2           (PPS_RPB2G3R_RPB2G3R_SCOM2P2_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM2P3           (PPS_RPB2G3R_RPB2G3R_SCOM2P3_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM3P2           (PPS_RPB2G3R_RPB2G3R_SCOM3P2_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB2G3R_RPB2G3R_SCOM3P1           (PPS_RPB2G3R_RPB2G3R_SCOM3P1_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC0WO2           (PPS_RPB2G3R_RPB2G3R_TCC0WO2_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC0/WO2 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC0WO0           (PPS_RPB2G3R_RPB2G3R_TCC0WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC0/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC0WO4           (PPS_RPB2G3R_RPB2G3R_TCC0WO4_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC0/WO4 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC1WO2           (PPS_RPB2G3R_RPB2G3R_TCC1WO2_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC1/WO2 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC1WO0           (PPS_RPB2G3R_RPB2G3R_TCC1WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC1/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC1WO4           (PPS_RPB2G3R_RPB2G3R_TCC1WO4_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC1/WO4 Position  */
#define PPS_RPB2G3R_RPB2G3R_TCC2WO0           (PPS_RPB2G3R_RPB2G3R_TCC2WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TCC2/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_TC0WO0            (PPS_RPB2G3R_RPB2G3R_TC0WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TC0/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_REFO3             (PPS_RPB2G3R_RPB2G3R_REFO3_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) REFO3 Position  */
#define PPS_RPB2G3R_RPB2G3R_TC1WO0            (PPS_RPB2G3R_RPB2G3R_TC1WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TC1/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_TC2WO0            (PPS_RPB2G3R_RPB2G3R_TC2WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TC2/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_TC3WO0            (PPS_RPB2G3R_RPB2G3R_TC3WO0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TC3/WO0 Position  */
#define PPS_RPB2G3R_RPB2G3R_QSCK              (PPS_RPB2G3R_RPB2G3R_QSCK_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) QSCK Position  */
#define PPS_RPB2G3R_RPB2G3R_QCS               (PPS_RPB2G3R_RPB2G3R_QCS_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) QCS Position  */
#define PPS_RPB2G3R_RPB2G3R_QD1               (PPS_RPB2G3R_RPB2G3R_QD1_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) QD1 Position  */
#define PPS_RPB2G3R_RPB2G3R_QD0               (PPS_RPB2G3R_RPB2G3R_QD0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) QD0 Position  */
#define PPS_RPB2G3R_RPB2G3R_QD3               (PPS_RPB2G3R_RPB2G3R_QD3_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) QD3 Position  */
#define PPS_RPB2G3R_RPB2G3R_CCLOUT0           (PPS_RPB2G3R_RPB2G3R_CCLOUT0_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) CCLOUT0 Position  */
#define PPS_RPB2G3R_RPB2G3R_TSTBUS2           (PPS_RPB2G3R_RPB2G3R_TSTBUS2_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TSTBUS2 Position  */
#define PPS_RPB2G3R_RPB2G3R_TSTBUS6           (PPS_RPB2G3R_RPB2G3R_TSTBUS6_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TSTBUS6 Position  */
#define PPS_RPB2G3R_RPB2G3R_TSTBUS10          (PPS_RPB2G3R_RPB2G3R_TSTBUS10_Val << PPS_RPB2G3R_RPB2G3R_Pos) /* (PPS_RPB2G3R) TSTBUS10 Position  */
#define PPS_RPB2G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB2G3R) Register Mask  */


/* -------- PPS_RPB2G4R : (PPS Offset: 0x2A0) (R/W 32)  -------- */
#define PPS_RPB2G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB2G4R)   Reset Value */

#define PPS_RPB2G4R_RPB2G4R_Pos               _UINT32_(0)                                          /* (PPS_RPB2G4R) RPB2/G4 Position */
#define PPS_RPB2G4R_RPB2G4R_Msk               (_UINT32_(0x1F) << PPS_RPB2G4R_RPB2G4R_Pos)          /* (PPS_RPB2G4R) RPB2/G4 Mask */
#define PPS_RPB2G4R_RPB2G4R(value)            (PPS_RPB2G4R_RPB2G4R_Msk & (_UINT32_(value) << PPS_RPB2G4R_RPB2G4R_Pos)) /* Assigment of value for RPB2G4R in the PPS_RPB2G4R register */
#define   PPS_RPB2G4R_RPB2G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB2G4R) OFF  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPB2G4R) SERCOM0/PAD2  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPB2G4R) SERCOM0/PAD1  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPB2G4R) SERCOM0/PAD0  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPB2G4R) SERCOM1/PAD3  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPB2G4R) SERCOM1/PAD1  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPB2G4R) SERCOM1/PAD0  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPB2G4R) SERCOM2/PAD3  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPB2G4R) SERCOM2/PAD0  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPB2G4R) SERCOM3/PAD3  */
#define   PPS_RPB2G4R_RPB2G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPB2G4R) SERCOM3/PAD2  */
#define   PPS_RPB2G4R_RPB2G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPB2G4R) TCC0/WO3  */
#define   PPS_RPB2G4R_RPB2G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPB2G4R) TCC0/WO1  */
#define   PPS_RPB2G4R_RPB2G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPB2G4R) TCC0/WO5  */
#define   PPS_RPB2G4R_RPB2G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPB2G4R) TCC1/WO3  */
#define   PPS_RPB2G4R_RPB2G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPB2G4R) TCC1/WO1  */
#define   PPS_RPB2G4R_RPB2G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPB2G4R) TCC1/WO5  */
#define   PPS_RPB2G4R_RPB2G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB2G4R) TCC2/WO1  */
#define   PPS_RPB2G4R_RPB2G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB2G4R) TC0/WO0  */
#define   PPS_RPB2G4R_RPB2G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPB2G4R) REFO4  */
#define   PPS_RPB2G4R_RPB2G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB2G4R) TC1/WO1  */
#define   PPS_RPB2G4R_RPB2G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB2G4R) TC2/WO1  */
#define   PPS_RPB2G4R_RPB2G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB2G4R) TC3/WO1  */
#define   PPS_RPB2G4R_RPB2G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB2G4R) QSCK  */
#define   PPS_RPB2G4R_RPB2G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB2G4R) QCS  */
#define   PPS_RPB2G4R_RPB2G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPB2G4R) QD2  */
#define   PPS_RPB2G4R_RPB2G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPB2G4R) QD1  */
#define   PPS_RPB2G4R_RPB2G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPB2G4R) QD0  */
#define   PPS_RPB2G4R_RPB2G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB2G4R) CCLOUT1  */
#define   PPS_RPB2G4R_RPB2G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPB2G4R) TSTBUS3  */
#define   PPS_RPB2G4R_RPB2G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPB2G4R) TSTBUS7  */
#define   PPS_RPB2G4R_RPB2G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPB2G4R) TSTBUS11  */
#define PPS_RPB2G4R_RPB2G4R_OFF               (PPS_RPB2G4R_RPB2G4R_OFF_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) OFF Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM0P2           (PPS_RPB2G4R_RPB2G4R_SCOM0P2_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM0/PAD2 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM0P1           (PPS_RPB2G4R_RPB2G4R_SCOM0P1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM0/PAD1 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM0P0           (PPS_RPB2G4R_RPB2G4R_SCOM0P0_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM0/PAD0 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM1P3           (PPS_RPB2G4R_RPB2G4R_SCOM1P3_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM1/PAD3 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM1P1           (PPS_RPB2G4R_RPB2G4R_SCOM1P1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM1/PAD1 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM1P0           (PPS_RPB2G4R_RPB2G4R_SCOM1P0_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM1/PAD0 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM2P3           (PPS_RPB2G4R_RPB2G4R_SCOM2P3_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM2/PAD3 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM2P0           (PPS_RPB2G4R_RPB2G4R_SCOM2P0_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM2/PAD0 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM3P3           (PPS_RPB2G4R_RPB2G4R_SCOM3P3_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM3/PAD3 Position  */
#define PPS_RPB2G4R_RPB2G4R_SCOM3P2           (PPS_RPB2G4R_RPB2G4R_SCOM3P2_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) SERCOM3/PAD2 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC0WO3           (PPS_RPB2G4R_RPB2G4R_TCC0WO3_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC0/WO3 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC0WO1           (PPS_RPB2G4R_RPB2G4R_TCC0WO1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC0/WO1 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC0WO5           (PPS_RPB2G4R_RPB2G4R_TCC0WO5_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC0/WO5 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC1WO3           (PPS_RPB2G4R_RPB2G4R_TCC1WO3_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC1/WO3 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC1WO1           (PPS_RPB2G4R_RPB2G4R_TCC1WO1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC1/WO1 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC1WO5           (PPS_RPB2G4R_RPB2G4R_TCC1WO5_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC1/WO5 Position  */
#define PPS_RPB2G4R_RPB2G4R_TCC2WO1           (PPS_RPB2G4R_RPB2G4R_TCC2WO1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TCC2/WO1 Position  */
#define PPS_RPB2G4R_RPB2G4R_TC0WO0            (PPS_RPB2G4R_RPB2G4R_TC0WO0_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TC0/WO0 Position  */
#define PPS_RPB2G4R_RPB2G4R_REFO4             (PPS_RPB2G4R_RPB2G4R_REFO4_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) REFO4 Position  */
#define PPS_RPB2G4R_RPB2G4R_TC1WO1            (PPS_RPB2G4R_RPB2G4R_TC1WO1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TC1/WO1 Position  */
#define PPS_RPB2G4R_RPB2G4R_TC2WO1            (PPS_RPB2G4R_RPB2G4R_TC2WO1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TC2/WO1 Position  */
#define PPS_RPB2G4R_RPB2G4R_TC3WO1            (PPS_RPB2G4R_RPB2G4R_TC3WO1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TC3/WO1 Position  */
#define PPS_RPB2G4R_RPB2G4R_QSCK              (PPS_RPB2G4R_RPB2G4R_QSCK_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) QSCK Position  */
#define PPS_RPB2G4R_RPB2G4R_QCS               (PPS_RPB2G4R_RPB2G4R_QCS_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) QCS Position  */
#define PPS_RPB2G4R_RPB2G4R_QD2               (PPS_RPB2G4R_RPB2G4R_QD2_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) QD2 Position  */
#define PPS_RPB2G4R_RPB2G4R_QD1               (PPS_RPB2G4R_RPB2G4R_QD1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) QD1 Position  */
#define PPS_RPB2G4R_RPB2G4R_QD0               (PPS_RPB2G4R_RPB2G4R_QD0_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) QD0 Position  */
#define PPS_RPB2G4R_RPB2G4R_CCLOUT1           (PPS_RPB2G4R_RPB2G4R_CCLOUT1_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) CCLOUT1 Position  */
#define PPS_RPB2G4R_RPB2G4R_TSTBUS3           (PPS_RPB2G4R_RPB2G4R_TSTBUS3_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TSTBUS3 Position  */
#define PPS_RPB2G4R_RPB2G4R_TSTBUS7           (PPS_RPB2G4R_RPB2G4R_TSTBUS7_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TSTBUS7 Position  */
#define PPS_RPB2G4R_RPB2G4R_TSTBUS11          (PPS_RPB2G4R_RPB2G4R_TSTBUS11_Val << PPS_RPB2G4R_RPB2G4R_Pos) /* (PPS_RPB2G4R) TSTBUS11 Position  */
#define PPS_RPB2G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB2G4R) Register Mask  */


/* -------- PPS_RPB3G1R : (PPS Offset: 0x2A4) (R/W 32)  -------- */
#define PPS_RPB3G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB3G1R)   Reset Value */

#define PPS_RPB3G1R_RPB3G1R_Pos               _UINT32_(0)                                          /* (PPS_RPB3G1R) RPB3/G1 Position */
#define PPS_RPB3G1R_RPB3G1R_Msk               (_UINT32_(0x1F) << PPS_RPB3G1R_RPB3G1R_Pos)          /* (PPS_RPB3G1R) RPB3/G1 Mask */
#define PPS_RPB3G1R_RPB3G1R(value)            (PPS_RPB3G1R_RPB3G1R_Msk & (_UINT32_(value) << PPS_RPB3G1R_RPB3G1R_Pos)) /* Assigment of value for RPB3G1R in the PPS_RPB3G1R register */
#define   PPS_RPB3G1R_RPB3G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB3G1R) OFF  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPB3G1R) SERCOM0/PAD3  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPB3G1R) SERCOM0/PAD2  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPB3G1R) SERCOM0/PAD1  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPB3G1R) SERCOM1/PAD0  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPB3G1R) SERCOM1/PAD2  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPB3G1R) SERCOM1/PAD1  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPB3G1R) SERCOM2/PAD0  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPB3G1R) SERCOM2/PAD1  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPB3G1R) SERCOM3/PAD0  */
#define   PPS_RPB3G1R_RPB3G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPB3G1R) SERCOM3/PAD3  */
#define   PPS_RPB3G1R_RPB3G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPB3G1R) TCC0/WO0  */
#define   PPS_RPB3G1R_RPB3G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPB3G1R) TCC0/WO4  */
#define   PPS_RPB3G1R_RPB3G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPB3G1R) TCC0/WO2  */
#define   PPS_RPB3G1R_RPB3G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPB3G1R) TCC1/WO0  */
#define   PPS_RPB3G1R_RPB3G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPB3G1R) TCC1/WO4  */
#define   PPS_RPB3G1R_RPB3G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPB3G1R) TCC1/WO2  */
#define   PPS_RPB3G1R_RPB3G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB3G1R) TCC2/WO0  */
#define   PPS_RPB3G1R_RPB3G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB3G1R) TC0/WO1  */
#define   PPS_RPB3G1R_RPB3G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPB3G1R) REFO1  */
#define   PPS_RPB3G1R_RPB3G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB3G1R) TC1/WO0  */
#define   PPS_RPB3G1R_RPB3G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB3G1R) TC2/WO0  */
#define   PPS_RPB3G1R_RPB3G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB3G1R) TC3/WO0  */
#define   PPS_RPB3G1R_RPB3G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB3G1R) QSCK  */
#define   PPS_RPB3G1R_RPB3G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB3G1R) QCS  */
#define   PPS_RPB3G1R_RPB3G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPB3G1R) QD3  */
#define   PPS_RPB3G1R_RPB3G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPB3G1R) QD2  */
#define   PPS_RPB3G1R_RPB3G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPB3G1R) QD1  */
#define   PPS_RPB3G1R_RPB3G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB3G1R) CCLOUT0  */
#define   PPS_RPB3G1R_RPB3G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPB3G1R) TSTBUS0  */
#define   PPS_RPB3G1R_RPB3G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPB3G1R) TSTBUS4  */
#define   PPS_RPB3G1R_RPB3G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPB3G1R) TSTBUS8  */
#define PPS_RPB3G1R_RPB3G1R_OFF               (PPS_RPB3G1R_RPB3G1R_OFF_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) OFF Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM0P3           (PPS_RPB3G1R_RPB3G1R_SCOM0P3_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM0P2           (PPS_RPB3G1R_RPB3G1R_SCOM0P2_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM0P1           (PPS_RPB3G1R_RPB3G1R_SCOM0P1_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM1P0           (PPS_RPB3G1R_RPB3G1R_SCOM1P0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM1P2           (PPS_RPB3G1R_RPB3G1R_SCOM1P2_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM1P1           (PPS_RPB3G1R_RPB3G1R_SCOM1P1_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM2P0           (PPS_RPB3G1R_RPB3G1R_SCOM2P0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM2P1           (PPS_RPB3G1R_RPB3G1R_SCOM2P1_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM3P0           (PPS_RPB3G1R_RPB3G1R_SCOM3P0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB3G1R_RPB3G1R_SCOM3P3           (PPS_RPB3G1R_RPB3G1R_SCOM3P3_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC0WO0           (PPS_RPB3G1R_RPB3G1R_TCC0WO0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC0/WO0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC0WO4           (PPS_RPB3G1R_RPB3G1R_TCC0WO4_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC0/WO4 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC0WO2           (PPS_RPB3G1R_RPB3G1R_TCC0WO2_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC0/WO2 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC1WO0           (PPS_RPB3G1R_RPB3G1R_TCC1WO0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC1/WO0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC1WO4           (PPS_RPB3G1R_RPB3G1R_TCC1WO4_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC1/WO4 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC1WO2           (PPS_RPB3G1R_RPB3G1R_TCC1WO2_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC1/WO2 Position  */
#define PPS_RPB3G1R_RPB3G1R_TCC2WO0           (PPS_RPB3G1R_RPB3G1R_TCC2WO0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TCC2/WO0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TC0WO1            (PPS_RPB3G1R_RPB3G1R_TC0WO1_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TC0/WO1 Position  */
#define PPS_RPB3G1R_RPB3G1R_REFO1             (PPS_RPB3G1R_RPB3G1R_REFO1_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) REFO1 Position  */
#define PPS_RPB3G1R_RPB3G1R_TC1WO0            (PPS_RPB3G1R_RPB3G1R_TC1WO0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TC1/WO0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TC2WO0            (PPS_RPB3G1R_RPB3G1R_TC2WO0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TC2/WO0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TC3WO0            (PPS_RPB3G1R_RPB3G1R_TC3WO0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TC3/WO0 Position  */
#define PPS_RPB3G1R_RPB3G1R_QSCK              (PPS_RPB3G1R_RPB3G1R_QSCK_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) QSCK Position  */
#define PPS_RPB3G1R_RPB3G1R_QCS               (PPS_RPB3G1R_RPB3G1R_QCS_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) QCS Position  */
#define PPS_RPB3G1R_RPB3G1R_QD3               (PPS_RPB3G1R_RPB3G1R_QD3_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) QD3 Position  */
#define PPS_RPB3G1R_RPB3G1R_QD2               (PPS_RPB3G1R_RPB3G1R_QD2_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) QD2 Position  */
#define PPS_RPB3G1R_RPB3G1R_QD1               (PPS_RPB3G1R_RPB3G1R_QD1_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) QD1 Position  */
#define PPS_RPB3G1R_RPB3G1R_CCLOUT0           (PPS_RPB3G1R_RPB3G1R_CCLOUT0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) CCLOUT0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TSTBUS0           (PPS_RPB3G1R_RPB3G1R_TSTBUS0_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TSTBUS0 Position  */
#define PPS_RPB3G1R_RPB3G1R_TSTBUS4           (PPS_RPB3G1R_RPB3G1R_TSTBUS4_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TSTBUS4 Position  */
#define PPS_RPB3G1R_RPB3G1R_TSTBUS8           (PPS_RPB3G1R_RPB3G1R_TSTBUS8_Val << PPS_RPB3G1R_RPB3G1R_Pos) /* (PPS_RPB3G1R) TSTBUS8 Position  */
#define PPS_RPB3G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB3G1R) Register Mask  */


/* -------- PPS_RPB3G4R : (PPS Offset: 0x2A8) (R/W 32)  -------- */
#define PPS_RPB3G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB3G4R)   Reset Value */

#define PPS_RPB3G4R_RPB3G4R_Pos               _UINT32_(0)                                          /* (PPS_RPB3G4R) RPB3/G4 Position */
#define PPS_RPB3G4R_RPB3G4R_Msk               (_UINT32_(0x1F) << PPS_RPB3G4R_RPB3G4R_Pos)          /* (PPS_RPB3G4R) RPB3/G4 Mask */
#define PPS_RPB3G4R_RPB3G4R(value)            (PPS_RPB3G4R_RPB3G4R_Msk & (_UINT32_(value) << PPS_RPB3G4R_RPB3G4R_Pos)) /* Assigment of value for RPB3G4R in the PPS_RPB3G4R register */
#define   PPS_RPB3G4R_RPB3G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB3G4R) OFF  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPB3G4R) SERCOM0/PAD2  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPB3G4R) SERCOM0/PAD1  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPB3G4R) SERCOM0/PAD0  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPB3G4R) SERCOM1/PAD3  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPB3G4R) SERCOM1/PAD1  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPB3G4R) SERCOM1/PAD0  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPB3G4R) SERCOM2/PAD3  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPB3G4R) SERCOM2/PAD0  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPB3G4R) SERCOM3/PAD3  */
#define   PPS_RPB3G4R_RPB3G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPB3G4R) SERCOM3/PAD2  */
#define   PPS_RPB3G4R_RPB3G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPB3G4R) TCC0/WO3  */
#define   PPS_RPB3G4R_RPB3G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPB3G4R) TCC0/WO1  */
#define   PPS_RPB3G4R_RPB3G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPB3G4R) TCC0/WO5  */
#define   PPS_RPB3G4R_RPB3G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPB3G4R) TCC1/WO3  */
#define   PPS_RPB3G4R_RPB3G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPB3G4R) TCC1/WO1  */
#define   PPS_RPB3G4R_RPB3G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPB3G4R) TCC1/WO5  */
#define   PPS_RPB3G4R_RPB3G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB3G4R) TCC2/WO1  */
#define   PPS_RPB3G4R_RPB3G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB3G4R) TC0/WO0  */
#define   PPS_RPB3G4R_RPB3G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPB3G4R) REFO4  */
#define   PPS_RPB3G4R_RPB3G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB3G4R) TC1/WO1  */
#define   PPS_RPB3G4R_RPB3G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB3G4R) TC2/WO1  */
#define   PPS_RPB3G4R_RPB3G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB3G4R) TC3/WO1  */
#define   PPS_RPB3G4R_RPB3G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB3G4R) QSCK  */
#define   PPS_RPB3G4R_RPB3G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB3G4R) QCS  */
#define   PPS_RPB3G4R_RPB3G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPB3G4R) QD2  */
#define   PPS_RPB3G4R_RPB3G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPB3G4R) QD1  */
#define   PPS_RPB3G4R_RPB3G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPB3G4R) QD0  */
#define   PPS_RPB3G4R_RPB3G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB3G4R) CCLOUT1  */
#define   PPS_RPB3G4R_RPB3G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPB3G4R) TSTBUS3  */
#define   PPS_RPB3G4R_RPB3G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPB3G4R) TSTBUS7  */
#define   PPS_RPB3G4R_RPB3G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPB3G4R) TSTBUS11  */
#define PPS_RPB3G4R_RPB3G4R_OFF               (PPS_RPB3G4R_RPB3G4R_OFF_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) OFF Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM0P2           (PPS_RPB3G4R_RPB3G4R_SCOM0P2_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM0/PAD2 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM0P1           (PPS_RPB3G4R_RPB3G4R_SCOM0P1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM0/PAD1 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM0P0           (PPS_RPB3G4R_RPB3G4R_SCOM0P0_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM0/PAD0 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM1P3           (PPS_RPB3G4R_RPB3G4R_SCOM1P3_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM1/PAD3 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM1P1           (PPS_RPB3G4R_RPB3G4R_SCOM1P1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM1/PAD1 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM1P0           (PPS_RPB3G4R_RPB3G4R_SCOM1P0_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM1/PAD0 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM2P3           (PPS_RPB3G4R_RPB3G4R_SCOM2P3_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM2/PAD3 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM2P0           (PPS_RPB3G4R_RPB3G4R_SCOM2P0_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM2/PAD0 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM3P3           (PPS_RPB3G4R_RPB3G4R_SCOM3P3_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM3/PAD3 Position  */
#define PPS_RPB3G4R_RPB3G4R_SCOM3P2           (PPS_RPB3G4R_RPB3G4R_SCOM3P2_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) SERCOM3/PAD2 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC0WO3           (PPS_RPB3G4R_RPB3G4R_TCC0WO3_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC0/WO3 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC0WO1           (PPS_RPB3G4R_RPB3G4R_TCC0WO1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC0/WO1 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC0WO5           (PPS_RPB3G4R_RPB3G4R_TCC0WO5_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC0/WO5 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC1WO3           (PPS_RPB3G4R_RPB3G4R_TCC1WO3_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC1/WO3 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC1WO1           (PPS_RPB3G4R_RPB3G4R_TCC1WO1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC1/WO1 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC1WO5           (PPS_RPB3G4R_RPB3G4R_TCC1WO5_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC1/WO5 Position  */
#define PPS_RPB3G4R_RPB3G4R_TCC2WO1           (PPS_RPB3G4R_RPB3G4R_TCC2WO1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TCC2/WO1 Position  */
#define PPS_RPB3G4R_RPB3G4R_TC0WO0            (PPS_RPB3G4R_RPB3G4R_TC0WO0_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TC0/WO0 Position  */
#define PPS_RPB3G4R_RPB3G4R_REFO4             (PPS_RPB3G4R_RPB3G4R_REFO4_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) REFO4 Position  */
#define PPS_RPB3G4R_RPB3G4R_TC1WO1            (PPS_RPB3G4R_RPB3G4R_TC1WO1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TC1/WO1 Position  */
#define PPS_RPB3G4R_RPB3G4R_TC2WO1            (PPS_RPB3G4R_RPB3G4R_TC2WO1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TC2/WO1 Position  */
#define PPS_RPB3G4R_RPB3G4R_TC3WO1            (PPS_RPB3G4R_RPB3G4R_TC3WO1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TC3/WO1 Position  */
#define PPS_RPB3G4R_RPB3G4R_QSCK              (PPS_RPB3G4R_RPB3G4R_QSCK_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) QSCK Position  */
#define PPS_RPB3G4R_RPB3G4R_QCS               (PPS_RPB3G4R_RPB3G4R_QCS_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) QCS Position  */
#define PPS_RPB3G4R_RPB3G4R_QD2               (PPS_RPB3G4R_RPB3G4R_QD2_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) QD2 Position  */
#define PPS_RPB3G4R_RPB3G4R_QD1               (PPS_RPB3G4R_RPB3G4R_QD1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) QD1 Position  */
#define PPS_RPB3G4R_RPB3G4R_QD0               (PPS_RPB3G4R_RPB3G4R_QD0_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) QD0 Position  */
#define PPS_RPB3G4R_RPB3G4R_CCLOUT1           (PPS_RPB3G4R_RPB3G4R_CCLOUT1_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) CCLOUT1 Position  */
#define PPS_RPB3G4R_RPB3G4R_TSTBUS3           (PPS_RPB3G4R_RPB3G4R_TSTBUS3_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TSTBUS3 Position  */
#define PPS_RPB3G4R_RPB3G4R_TSTBUS7           (PPS_RPB3G4R_RPB3G4R_TSTBUS7_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TSTBUS7 Position  */
#define PPS_RPB3G4R_RPB3G4R_TSTBUS11          (PPS_RPB3G4R_RPB3G4R_TSTBUS11_Val << PPS_RPB3G4R_RPB3G4R_Pos) /* (PPS_RPB3G4R) TSTBUS11 Position  */
#define PPS_RPB3G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB3G4R) Register Mask  */


/* -------- PPS_RPB4G1R : (PPS Offset: 0x2AC) (R/W 32)  -------- */
#define PPS_RPB4G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB4G1R)   Reset Value */

#define PPS_RPB4G1R_RPB4G1R_Pos               _UINT32_(0)                                          /* (PPS_RPB4G1R) RPB4/G1 Position */
#define PPS_RPB4G1R_RPB4G1R_Msk               (_UINT32_(0x1F) << PPS_RPB4G1R_RPB4G1R_Pos)          /* (PPS_RPB4G1R) RPB4/G1 Mask */
#define PPS_RPB4G1R_RPB4G1R(value)            (PPS_RPB4G1R_RPB4G1R_Msk & (_UINT32_(value) << PPS_RPB4G1R_RPB4G1R_Pos)) /* Assigment of value for RPB4G1R in the PPS_RPB4G1R register */
#define   PPS_RPB4G1R_RPB4G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB4G1R) OFF  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPB4G1R) SERCOM0/PAD3  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPB4G1R) SERCOM0/PAD2  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPB4G1R) SERCOM0/PAD1  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPB4G1R) SERCOM1/PAD0  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPB4G1R) SERCOM1/PAD2  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPB4G1R) SERCOM1/PAD1  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPB4G1R) SERCOM2/PAD0  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPB4G1R) SERCOM2/PAD1  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPB4G1R) SERCOM3/PAD0  */
#define   PPS_RPB4G1R_RPB4G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPB4G1R) SERCOM3/PAD3  */
#define   PPS_RPB4G1R_RPB4G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPB4G1R) TCC0/WO0  */
#define   PPS_RPB4G1R_RPB4G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPB4G1R) TCC0/WO4  */
#define   PPS_RPB4G1R_RPB4G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPB4G1R) TCC0/WO2  */
#define   PPS_RPB4G1R_RPB4G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPB4G1R) TCC1/WO0  */
#define   PPS_RPB4G1R_RPB4G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPB4G1R) TCC1/WO4  */
#define   PPS_RPB4G1R_RPB4G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPB4G1R) TCC1/WO2  */
#define   PPS_RPB4G1R_RPB4G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB4G1R) TCC2/WO0  */
#define   PPS_RPB4G1R_RPB4G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB4G1R) TC0/WO1  */
#define   PPS_RPB4G1R_RPB4G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPB4G1R) REFO1  */
#define   PPS_RPB4G1R_RPB4G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB4G1R) TC1/WO0  */
#define   PPS_RPB4G1R_RPB4G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB4G1R) TC2/WO0  */
#define   PPS_RPB4G1R_RPB4G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB4G1R) TC3/WO0  */
#define   PPS_RPB4G1R_RPB4G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB4G1R) QSCK  */
#define   PPS_RPB4G1R_RPB4G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB4G1R) QCS  */
#define   PPS_RPB4G1R_RPB4G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPB4G1R) QD3  */
#define   PPS_RPB4G1R_RPB4G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPB4G1R) QD2  */
#define   PPS_RPB4G1R_RPB4G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPB4G1R) QD1  */
#define   PPS_RPB4G1R_RPB4G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB4G1R) CCLOUT0  */
#define   PPS_RPB4G1R_RPB4G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPB4G1R) TSTBUS0  */
#define   PPS_RPB4G1R_RPB4G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPB4G1R) TSTBUS4  */
#define   PPS_RPB4G1R_RPB4G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPB4G1R) TSTBUS8  */
#define PPS_RPB4G1R_RPB4G1R_OFF               (PPS_RPB4G1R_RPB4G1R_OFF_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) OFF Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM0P3           (PPS_RPB4G1R_RPB4G1R_SCOM0P3_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM0P2           (PPS_RPB4G1R_RPB4G1R_SCOM0P2_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM0P1           (PPS_RPB4G1R_RPB4G1R_SCOM0P1_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM1P0           (PPS_RPB4G1R_RPB4G1R_SCOM1P0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM1P2           (PPS_RPB4G1R_RPB4G1R_SCOM1P2_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM1P1           (PPS_RPB4G1R_RPB4G1R_SCOM1P1_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM2P0           (PPS_RPB4G1R_RPB4G1R_SCOM2P0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM2P1           (PPS_RPB4G1R_RPB4G1R_SCOM2P1_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM3P0           (PPS_RPB4G1R_RPB4G1R_SCOM3P0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB4G1R_RPB4G1R_SCOM3P3           (PPS_RPB4G1R_RPB4G1R_SCOM3P3_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC0WO0           (PPS_RPB4G1R_RPB4G1R_TCC0WO0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC0/WO0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC0WO4           (PPS_RPB4G1R_RPB4G1R_TCC0WO4_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC0/WO4 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC0WO2           (PPS_RPB4G1R_RPB4G1R_TCC0WO2_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC0/WO2 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC1WO0           (PPS_RPB4G1R_RPB4G1R_TCC1WO0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC1/WO0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC1WO4           (PPS_RPB4G1R_RPB4G1R_TCC1WO4_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC1/WO4 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC1WO2           (PPS_RPB4G1R_RPB4G1R_TCC1WO2_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC1/WO2 Position  */
#define PPS_RPB4G1R_RPB4G1R_TCC2WO0           (PPS_RPB4G1R_RPB4G1R_TCC2WO0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TCC2/WO0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TC0WO1            (PPS_RPB4G1R_RPB4G1R_TC0WO1_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TC0/WO1 Position  */
#define PPS_RPB4G1R_RPB4G1R_REFO1             (PPS_RPB4G1R_RPB4G1R_REFO1_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) REFO1 Position  */
#define PPS_RPB4G1R_RPB4G1R_TC1WO0            (PPS_RPB4G1R_RPB4G1R_TC1WO0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TC1/WO0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TC2WO0            (PPS_RPB4G1R_RPB4G1R_TC2WO0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TC2/WO0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TC3WO0            (PPS_RPB4G1R_RPB4G1R_TC3WO0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TC3/WO0 Position  */
#define PPS_RPB4G1R_RPB4G1R_QSCK              (PPS_RPB4G1R_RPB4G1R_QSCK_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) QSCK Position  */
#define PPS_RPB4G1R_RPB4G1R_QCS               (PPS_RPB4G1R_RPB4G1R_QCS_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) QCS Position  */
#define PPS_RPB4G1R_RPB4G1R_QD3               (PPS_RPB4G1R_RPB4G1R_QD3_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) QD3 Position  */
#define PPS_RPB4G1R_RPB4G1R_QD2               (PPS_RPB4G1R_RPB4G1R_QD2_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) QD2 Position  */
#define PPS_RPB4G1R_RPB4G1R_QD1               (PPS_RPB4G1R_RPB4G1R_QD1_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) QD1 Position  */
#define PPS_RPB4G1R_RPB4G1R_CCLOUT0           (PPS_RPB4G1R_RPB4G1R_CCLOUT0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) CCLOUT0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TSTBUS0           (PPS_RPB4G1R_RPB4G1R_TSTBUS0_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TSTBUS0 Position  */
#define PPS_RPB4G1R_RPB4G1R_TSTBUS4           (PPS_RPB4G1R_RPB4G1R_TSTBUS4_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TSTBUS4 Position  */
#define PPS_RPB4G1R_RPB4G1R_TSTBUS8           (PPS_RPB4G1R_RPB4G1R_TSTBUS8_Val << PPS_RPB4G1R_RPB4G1R_Pos) /* (PPS_RPB4G1R) TSTBUS8 Position  */
#define PPS_RPB4G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB4G1R) Register Mask  */


/* -------- PPS_RPB4G2R : (PPS Offset: 0x2B0) (R/W 32)  -------- */
#define PPS_RPB4G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB4G2R)   Reset Value */

#define PPS_RPB4G2R_RPB4G2R_Pos               _UINT32_(0)                                          /* (PPS_RPB4G2R) RPB4G2 Position */
#define PPS_RPB4G2R_RPB4G2R_Msk               (_UINT32_(0x1F) << PPS_RPB4G2R_RPB4G2R_Pos)          /* (PPS_RPB4G2R) RPB4G2 Mask */
#define PPS_RPB4G2R_RPB4G2R(value)            (PPS_RPB4G2R_RPB4G2R_Msk & (_UINT32_(value) << PPS_RPB4G2R_RPB4G2R_Pos)) /* Assigment of value for RPB4G2R in the PPS_RPB4G2R register */
#define   PPS_RPB4G2R_RPB4G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB4G2R) OFF  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPB4G2R) SERCOM0/PAD0  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPB4G2R) SERCOM0/PAD3  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPB4G2R) SERCOM0/PAD2  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPB4G2R) SERCOM1/PAD1  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPB4G2R) SERCOM1/PAD3  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPB4G2R) SERCOM1/PAD2  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPB4G2R) SERCOM2/PAD1  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPB4G2R) SERCOM2/PAD2  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPB4G2R) SERCOM3/PAD1  */
#define   PPS_RPB4G2R_RPB4G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPB4G2R) SERCOM3/PAD0  */
#define   PPS_RPB4G2R_RPB4G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPB4G2R) TCC0/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPB4G2R) TCC0/WO5  */
#define   PPS_RPB4G2R_RPB4G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPB4G2R) TCC0/WO3  */
#define   PPS_RPB4G2R_RPB4G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPB4G2R) TCC1/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPB4G2R) TCC1/WO5  */
#define   PPS_RPB4G2R_RPB4G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPB4G2R) TCC1/WO3  */
#define   PPS_RPB4G2R_RPB4G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB4G2R) TCC2/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB4G2R) TC0/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPB4G2R) REFO2  */
#define   PPS_RPB4G2R_RPB4G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB4G2R) TC1/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB4G2R) TC2/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB4G2R) TC3/WO1  */
#define   PPS_RPB4G2R_RPB4G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB4G2R) QSCK  */
#define   PPS_RPB4G2R_RPB4G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB4G2R) QCS  */
#define   PPS_RPB4G2R_RPB4G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPB4G2R) QD0  */
#define   PPS_RPB4G2R_RPB4G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPB4G2R) QD3  */
#define   PPS_RPB4G2R_RPB4G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPB4G2R) QD2  */
#define   PPS_RPB4G2R_RPB4G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB4G2R) CCLOUT1  */
#define   PPS_RPB4G2R_RPB4G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPB4G2R) TSTBUS1  */
#define   PPS_RPB4G2R_RPB4G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPB4G2R) TSTBUS5  */
#define   PPS_RPB4G2R_RPB4G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPB4G2R) TSTBUS9  */
#define PPS_RPB4G2R_RPB4G2R_OFF               (PPS_RPB4G2R_RPB4G2R_OFF_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) OFF Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM0P0           (PPS_RPB4G2R_RPB4G2R_SCOM0P0_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM0P3           (PPS_RPB4G2R_RPB4G2R_SCOM0P3_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM0P2           (PPS_RPB4G2R_RPB4G2R_SCOM0P2_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM1P1           (PPS_RPB4G2R_RPB4G2R_SCOM1P1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM1P3           (PPS_RPB4G2R_RPB4G2R_SCOM1P3_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM1P2           (PPS_RPB4G2R_RPB4G2R_SCOM1P2_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM2P1           (PPS_RPB4G2R_RPB4G2R_SCOM2P1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM2P2           (PPS_RPB4G2R_RPB4G2R_SCOM2P2_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM3P1           (PPS_RPB4G2R_RPB4G2R_SCOM3P1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB4G2R_RPB4G2R_SCOM3P0           (PPS_RPB4G2R_RPB4G2R_SCOM3P0_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC0WO1           (PPS_RPB4G2R_RPB4G2R_TCC0WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC0/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC0WO5           (PPS_RPB4G2R_RPB4G2R_TCC0WO5_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC0/WO5 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC0WO3           (PPS_RPB4G2R_RPB4G2R_TCC0WO3_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC0/WO3 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC1WO1           (PPS_RPB4G2R_RPB4G2R_TCC1WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC1/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC1WO5           (PPS_RPB4G2R_RPB4G2R_TCC1WO5_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC1/WO5 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC1WO3           (PPS_RPB4G2R_RPB4G2R_TCC1WO3_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC1/WO3 Position  */
#define PPS_RPB4G2R_RPB4G2R_TCC2WO1           (PPS_RPB4G2R_RPB4G2R_TCC2WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TCC2/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TC0WO1            (PPS_RPB4G2R_RPB4G2R_TC0WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TC0/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_REFO2             (PPS_RPB4G2R_RPB4G2R_REFO2_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) REFO2 Position  */
#define PPS_RPB4G2R_RPB4G2R_TC1WO1            (PPS_RPB4G2R_RPB4G2R_TC1WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TC1/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TC2WO1            (PPS_RPB4G2R_RPB4G2R_TC2WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TC2/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TC3WO1            (PPS_RPB4G2R_RPB4G2R_TC3WO1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TC3/WO1 Position  */
#define PPS_RPB4G2R_RPB4G2R_QSCK              (PPS_RPB4G2R_RPB4G2R_QSCK_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) QSCK Position  */
#define PPS_RPB4G2R_RPB4G2R_QCS               (PPS_RPB4G2R_RPB4G2R_QCS_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) QCS Position  */
#define PPS_RPB4G2R_RPB4G2R_QD0               (PPS_RPB4G2R_RPB4G2R_QD0_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) QD0 Position  */
#define PPS_RPB4G2R_RPB4G2R_QD3               (PPS_RPB4G2R_RPB4G2R_QD3_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) QD3 Position  */
#define PPS_RPB4G2R_RPB4G2R_QD2               (PPS_RPB4G2R_RPB4G2R_QD2_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) QD2 Position  */
#define PPS_RPB4G2R_RPB4G2R_CCLOUT1           (PPS_RPB4G2R_RPB4G2R_CCLOUT1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) CCLOUT1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TSTBUS1           (PPS_RPB4G2R_RPB4G2R_TSTBUS1_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TSTBUS1 Position  */
#define PPS_RPB4G2R_RPB4G2R_TSTBUS5           (PPS_RPB4G2R_RPB4G2R_TSTBUS5_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TSTBUS5 Position  */
#define PPS_RPB4G2R_RPB4G2R_TSTBUS9           (PPS_RPB4G2R_RPB4G2R_TSTBUS9_Val << PPS_RPB4G2R_RPB4G2R_Pos) /* (PPS_RPB4G2R) TSTBUS9 Position  */
#define PPS_RPB4G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB4G2R) Register Mask  */


/* -------- PPS_RPB5G2R : (PPS Offset: 0x2B4) (R/W 32)  -------- */
#define PPS_RPB5G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB5G2R)   Reset Value */

#define PPS_RPB5G2R_RPB5G2R_Pos               _UINT32_(0)                                          /* (PPS_RPB5G2R) RPB5/G2 Position */
#define PPS_RPB5G2R_RPB5G2R_Msk               (_UINT32_(0x1F) << PPS_RPB5G2R_RPB5G2R_Pos)          /* (PPS_RPB5G2R) RPB5/G2 Mask */
#define PPS_RPB5G2R_RPB5G2R(value)            (PPS_RPB5G2R_RPB5G2R_Msk & (_UINT32_(value) << PPS_RPB5G2R_RPB5G2R_Pos)) /* Assigment of value for RPB5G2R in the PPS_RPB5G2R register */
#define   PPS_RPB5G2R_RPB5G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB5G2R) OFF  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPB5G2R) SERCOM0/PAD0  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPB5G2R) SERCOM0/PAD3  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPB5G2R) SERCOM0/PAD2  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPB5G2R) SERCOM1/PAD1  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPB5G2R) SERCOM1/PAD3  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPB5G2R) SERCOM1/PAD2  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPB5G2R) SERCOM2/PAD1  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPB5G2R) SERCOM2/PAD2  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPB5G2R) SERCOM3/PAD1  */
#define   PPS_RPB5G2R_RPB5G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPB5G2R) SERCOM3/PAD0  */
#define   PPS_RPB5G2R_RPB5G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPB5G2R) TCC0/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPB5G2R) TCC0/WO5  */
#define   PPS_RPB5G2R_RPB5G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPB5G2R) TCC0/WO3  */
#define   PPS_RPB5G2R_RPB5G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPB5G2R) TCC1/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPB5G2R) TCC1/WO5  */
#define   PPS_RPB5G2R_RPB5G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPB5G2R) TCC1/WO3  */
#define   PPS_RPB5G2R_RPB5G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB5G2R) TCC2/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB5G2R) TC0/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPB5G2R) REFO2  */
#define   PPS_RPB5G2R_RPB5G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB5G2R) TC1/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB5G2R) TC2/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB5G2R) TC3/WO1  */
#define   PPS_RPB5G2R_RPB5G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB5G2R) QSCK  */
#define   PPS_RPB5G2R_RPB5G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB5G2R) QCS  */
#define   PPS_RPB5G2R_RPB5G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPB5G2R) QD0  */
#define   PPS_RPB5G2R_RPB5G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPB5G2R) QD3  */
#define   PPS_RPB5G2R_RPB5G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPB5G2R) QD2  */
#define   PPS_RPB5G2R_RPB5G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB5G2R) CCLOUT1  */
#define   PPS_RPB5G2R_RPB5G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPB5G2R) TSTBUS1  */
#define   PPS_RPB5G2R_RPB5G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPB5G2R) TSTBUS5  */
#define   PPS_RPB5G2R_RPB5G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPB5G2R) TSTBUS9  */
#define PPS_RPB5G2R_RPB5G2R_OFF               (PPS_RPB5G2R_RPB5G2R_OFF_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) OFF Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM0P0           (PPS_RPB5G2R_RPB5G2R_SCOM0P0_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM0P3           (PPS_RPB5G2R_RPB5G2R_SCOM0P3_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM0P2           (PPS_RPB5G2R_RPB5G2R_SCOM0P2_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM1P1           (PPS_RPB5G2R_RPB5G2R_SCOM1P1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM1P3           (PPS_RPB5G2R_RPB5G2R_SCOM1P3_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM1P2           (PPS_RPB5G2R_RPB5G2R_SCOM1P2_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM2P1           (PPS_RPB5G2R_RPB5G2R_SCOM2P1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM2P2           (PPS_RPB5G2R_RPB5G2R_SCOM2P2_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM3P1           (PPS_RPB5G2R_RPB5G2R_SCOM3P1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB5G2R_RPB5G2R_SCOM3P0           (PPS_RPB5G2R_RPB5G2R_SCOM3P0_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC0WO1           (PPS_RPB5G2R_RPB5G2R_TCC0WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC0/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC0WO5           (PPS_RPB5G2R_RPB5G2R_TCC0WO5_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC0/WO5 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC0WO3           (PPS_RPB5G2R_RPB5G2R_TCC0WO3_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC0/WO3 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC1WO1           (PPS_RPB5G2R_RPB5G2R_TCC1WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC1/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC1WO5           (PPS_RPB5G2R_RPB5G2R_TCC1WO5_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC1/WO5 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC1WO3           (PPS_RPB5G2R_RPB5G2R_TCC1WO3_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC1/WO3 Position  */
#define PPS_RPB5G2R_RPB5G2R_TCC2WO1           (PPS_RPB5G2R_RPB5G2R_TCC2WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TCC2/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TC0WO1            (PPS_RPB5G2R_RPB5G2R_TC0WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TC0/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_REFO2             (PPS_RPB5G2R_RPB5G2R_REFO2_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) REFO2 Position  */
#define PPS_RPB5G2R_RPB5G2R_TC1WO1            (PPS_RPB5G2R_RPB5G2R_TC1WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TC1/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TC2WO1            (PPS_RPB5G2R_RPB5G2R_TC2WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TC2/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TC3WO1            (PPS_RPB5G2R_RPB5G2R_TC3WO1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TC3/WO1 Position  */
#define PPS_RPB5G2R_RPB5G2R_QSCK              (PPS_RPB5G2R_RPB5G2R_QSCK_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) QSCK Position  */
#define PPS_RPB5G2R_RPB5G2R_QCS               (PPS_RPB5G2R_RPB5G2R_QCS_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) QCS Position  */
#define PPS_RPB5G2R_RPB5G2R_QD0               (PPS_RPB5G2R_RPB5G2R_QD0_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) QD0 Position  */
#define PPS_RPB5G2R_RPB5G2R_QD3               (PPS_RPB5G2R_RPB5G2R_QD3_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) QD3 Position  */
#define PPS_RPB5G2R_RPB5G2R_QD2               (PPS_RPB5G2R_RPB5G2R_QD2_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) QD2 Position  */
#define PPS_RPB5G2R_RPB5G2R_CCLOUT1           (PPS_RPB5G2R_RPB5G2R_CCLOUT1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) CCLOUT1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TSTBUS1           (PPS_RPB5G2R_RPB5G2R_TSTBUS1_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TSTBUS1 Position  */
#define PPS_RPB5G2R_RPB5G2R_TSTBUS5           (PPS_RPB5G2R_RPB5G2R_TSTBUS5_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TSTBUS5 Position  */
#define PPS_RPB5G2R_RPB5G2R_TSTBUS9           (PPS_RPB5G2R_RPB5G2R_TSTBUS9_Val << PPS_RPB5G2R_RPB5G2R_Pos) /* (PPS_RPB5G2R) TSTBUS9 Position  */
#define PPS_RPB5G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB5G2R) Register Mask  */


/* -------- PPS_RPB5G3R : (PPS Offset: 0x2B8) (R/W 32)  -------- */
#define PPS_RPB5G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB5G3R)   Reset Value */

#define PPS_RPB5G3R_RPB5G3R_Pos               _UINT32_(0)                                          /* (PPS_RPB5G3R) RPB5/G3 Position */
#define PPS_RPB5G3R_RPB5G3R_Msk               (_UINT32_(0x1F) << PPS_RPB5G3R_RPB5G3R_Pos)          /* (PPS_RPB5G3R) RPB5/G3 Mask */
#define PPS_RPB5G3R_RPB5G3R(value)            (PPS_RPB5G3R_RPB5G3R_Msk & (_UINT32_(value) << PPS_RPB5G3R_RPB5G3R_Pos)) /* Assigment of value for RPB5G3R in the PPS_RPB5G3R register */
#define   PPS_RPB5G3R_RPB5G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB5G3R) OFF  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPB5G3R) SERCOM0/PAD1  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPB5G3R) SERCOM0/PAD0  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPB5G3R) SERCOM0/PAD3  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPB5G3R) SERCOM1/PAD2  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPB5G3R) SERCOM1/PAD0  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPB5G3R) SERCOM1/PAD3  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPB5G3R) SERCOM2/PAD2  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPB5G3R) SERCOM2/PAD3  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPB5G3R) SERCOM3/PAD2  */
#define   PPS_RPB5G3R_RPB5G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPB5G3R) SERCOM3/PAD1  */
#define   PPS_RPB5G3R_RPB5G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPB5G3R) TCC0/WO2  */
#define   PPS_RPB5G3R_RPB5G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPB5G3R) TCC0/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPB5G3R) TCC0/WO4  */
#define   PPS_RPB5G3R_RPB5G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPB5G3R) TCC1/WO2  */
#define   PPS_RPB5G3R_RPB5G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPB5G3R) TCC1/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPB5G3R) TCC1/WO4  */
#define   PPS_RPB5G3R_RPB5G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB5G3R) TCC2/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB5G3R) TC0/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPB5G3R) REFO3  */
#define   PPS_RPB5G3R_RPB5G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB5G3R) TC1/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB5G3R) TC2/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB5G3R) TC3/WO0  */
#define   PPS_RPB5G3R_RPB5G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB5G3R) QSCK  */
#define   PPS_RPB5G3R_RPB5G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB5G3R) QCS  */
#define   PPS_RPB5G3R_RPB5G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPB5G3R) QD1  */
#define   PPS_RPB5G3R_RPB5G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPB5G3R) QD0  */
#define   PPS_RPB5G3R_RPB5G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPB5G3R) QD3  */
#define   PPS_RPB5G3R_RPB5G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB5G3R) CCLOUT0  */
#define   PPS_RPB5G3R_RPB5G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPB5G3R) TSTBUS2  */
#define   PPS_RPB5G3R_RPB5G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPB5G3R) TSTBUS6  */
#define   PPS_RPB5G3R_RPB5G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPB5G3R) TSTBUS10  */
#define PPS_RPB5G3R_RPB5G3R_OFF               (PPS_RPB5G3R_RPB5G3R_OFF_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) OFF Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM0P1           (PPS_RPB5G3R_RPB5G3R_SCOM0P1_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM0P0           (PPS_RPB5G3R_RPB5G3R_SCOM0P0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM0P3           (PPS_RPB5G3R_RPB5G3R_SCOM0P3_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM1P2           (PPS_RPB5G3R_RPB5G3R_SCOM1P2_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM1P0           (PPS_RPB5G3R_RPB5G3R_SCOM1P0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM1P3           (PPS_RPB5G3R_RPB5G3R_SCOM1P3_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM2P2           (PPS_RPB5G3R_RPB5G3R_SCOM2P2_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM2P3           (PPS_RPB5G3R_RPB5G3R_SCOM2P3_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM3P2           (PPS_RPB5G3R_RPB5G3R_SCOM3P2_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB5G3R_RPB5G3R_SCOM3P1           (PPS_RPB5G3R_RPB5G3R_SCOM3P1_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC0WO2           (PPS_RPB5G3R_RPB5G3R_TCC0WO2_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC0/WO2 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC0WO0           (PPS_RPB5G3R_RPB5G3R_TCC0WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC0/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC0WO4           (PPS_RPB5G3R_RPB5G3R_TCC0WO4_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC0/WO4 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC1WO2           (PPS_RPB5G3R_RPB5G3R_TCC1WO2_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC1/WO2 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC1WO0           (PPS_RPB5G3R_RPB5G3R_TCC1WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC1/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC1WO4           (PPS_RPB5G3R_RPB5G3R_TCC1WO4_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC1/WO4 Position  */
#define PPS_RPB5G3R_RPB5G3R_TCC2WO0           (PPS_RPB5G3R_RPB5G3R_TCC2WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TCC2/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_TC0WO0            (PPS_RPB5G3R_RPB5G3R_TC0WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TC0/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_REFO3             (PPS_RPB5G3R_RPB5G3R_REFO3_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) REFO3 Position  */
#define PPS_RPB5G3R_RPB5G3R_TC1WO0            (PPS_RPB5G3R_RPB5G3R_TC1WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TC1/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_TC2WO0            (PPS_RPB5G3R_RPB5G3R_TC2WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TC2/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_TC3WO0            (PPS_RPB5G3R_RPB5G3R_TC3WO0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TC3/WO0 Position  */
#define PPS_RPB5G3R_RPB5G3R_QSCK              (PPS_RPB5G3R_RPB5G3R_QSCK_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) QSCK Position  */
#define PPS_RPB5G3R_RPB5G3R_QCS               (PPS_RPB5G3R_RPB5G3R_QCS_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) QCS Position  */
#define PPS_RPB5G3R_RPB5G3R_QD1               (PPS_RPB5G3R_RPB5G3R_QD1_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) QD1 Position  */
#define PPS_RPB5G3R_RPB5G3R_QD0               (PPS_RPB5G3R_RPB5G3R_QD0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) QD0 Position  */
#define PPS_RPB5G3R_RPB5G3R_QD3               (PPS_RPB5G3R_RPB5G3R_QD3_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) QD3 Position  */
#define PPS_RPB5G3R_RPB5G3R_CCLOUT0           (PPS_RPB5G3R_RPB5G3R_CCLOUT0_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) CCLOUT0 Position  */
#define PPS_RPB5G3R_RPB5G3R_TSTBUS2           (PPS_RPB5G3R_RPB5G3R_TSTBUS2_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TSTBUS2 Position  */
#define PPS_RPB5G3R_RPB5G3R_TSTBUS6           (PPS_RPB5G3R_RPB5G3R_TSTBUS6_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TSTBUS6 Position  */
#define PPS_RPB5G3R_RPB5G3R_TSTBUS10          (PPS_RPB5G3R_RPB5G3R_TSTBUS10_Val << PPS_RPB5G3R_RPB5G3R_Pos) /* (PPS_RPB5G3R) TSTBUS10 Position  */
#define PPS_RPB5G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB5G3R) Register Mask  */


/* -------- PPS_RPB6G3R : (PPS Offset: 0x2BC) (R/W 32)  -------- */
#define PPS_RPB6G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB6G3R)   Reset Value */

#define PPS_RPB6G3R_RPB6G3R_Pos               _UINT32_(0)                                          /* (PPS_RPB6G3R) RPB6/G3 Position */
#define PPS_RPB6G3R_RPB6G3R_Msk               (_UINT32_(0x1F) << PPS_RPB6G3R_RPB6G3R_Pos)          /* (PPS_RPB6G3R) RPB6/G3 Mask */
#define PPS_RPB6G3R_RPB6G3R(value)            (PPS_RPB6G3R_RPB6G3R_Msk & (_UINT32_(value) << PPS_RPB6G3R_RPB6G3R_Pos)) /* Assigment of value for RPB6G3R in the PPS_RPB6G3R register */
#define   PPS_RPB6G3R_RPB6G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB6G3R) OFF  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPB6G3R) SERCOM0/PAD1  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPB6G3R) SERCOM0/PAD0  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPB6G3R) SERCOM0/PAD3  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPB6G3R) SERCOM1/PAD2  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPB6G3R) SERCOM1/PAD0  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPB6G3R) SERCOM1/PAD3  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPB6G3R) SERCOM2/PAD2  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPB6G3R) SERCOM2/PAD3  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPB6G3R) SERCOM3/PAD2  */
#define   PPS_RPB6G3R_RPB6G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPB6G3R) SERCOM3/PAD1  */
#define   PPS_RPB6G3R_RPB6G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPB6G3R) TCC0/WO2  */
#define   PPS_RPB6G3R_RPB6G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPB6G3R) TCC0/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPB6G3R) TCC0/WO4  */
#define   PPS_RPB6G3R_RPB6G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPB6G3R) TCC1/WO2  */
#define   PPS_RPB6G3R_RPB6G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPB6G3R) TCC1/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPB6G3R) TCC1/WO4  */
#define   PPS_RPB6G3R_RPB6G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB6G3R) TCC2/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB6G3R) TC0/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPB6G3R) REFO3  */
#define   PPS_RPB6G3R_RPB6G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB6G3R) TC1/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB6G3R) TC2/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB6G3R) TC3/WO0  */
#define   PPS_RPB6G3R_RPB6G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB6G3R) QSCK  */
#define   PPS_RPB6G3R_RPB6G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB6G3R) QCS  */
#define   PPS_RPB6G3R_RPB6G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPB6G3R) QD1  */
#define   PPS_RPB6G3R_RPB6G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPB6G3R) QD0  */
#define   PPS_RPB6G3R_RPB6G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPB6G3R) QD3  */
#define   PPS_RPB6G3R_RPB6G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB6G3R) CCLOUT0  */
#define   PPS_RPB6G3R_RPB6G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPB6G3R) TSTBUS2  */
#define   PPS_RPB6G3R_RPB6G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPB6G3R) TSTBUS6  */
#define   PPS_RPB6G3R_RPB6G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPB6G3R) TSTBUS10  */
#define PPS_RPB6G3R_RPB6G3R_OFF               (PPS_RPB6G3R_RPB6G3R_OFF_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) OFF Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM0P1           (PPS_RPB6G3R_RPB6G3R_SCOM0P1_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM0P0           (PPS_RPB6G3R_RPB6G3R_SCOM0P0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM0P3           (PPS_RPB6G3R_RPB6G3R_SCOM0P3_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM1P2           (PPS_RPB6G3R_RPB6G3R_SCOM1P2_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM1P0           (PPS_RPB6G3R_RPB6G3R_SCOM1P0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM1P3           (PPS_RPB6G3R_RPB6G3R_SCOM1P3_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM2P2           (PPS_RPB6G3R_RPB6G3R_SCOM2P2_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM2P3           (PPS_RPB6G3R_RPB6G3R_SCOM2P3_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM3P2           (PPS_RPB6G3R_RPB6G3R_SCOM3P2_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB6G3R_RPB6G3R_SCOM3P1           (PPS_RPB6G3R_RPB6G3R_SCOM3P1_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC0WO2           (PPS_RPB6G3R_RPB6G3R_TCC0WO2_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC0/WO2 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC0WO0           (PPS_RPB6G3R_RPB6G3R_TCC0WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC0/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC0WO4           (PPS_RPB6G3R_RPB6G3R_TCC0WO4_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC0/WO4 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC1WO2           (PPS_RPB6G3R_RPB6G3R_TCC1WO2_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC1/WO2 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC1WO0           (PPS_RPB6G3R_RPB6G3R_TCC1WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC1/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC1WO4           (PPS_RPB6G3R_RPB6G3R_TCC1WO4_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC1/WO4 Position  */
#define PPS_RPB6G3R_RPB6G3R_TCC2WO0           (PPS_RPB6G3R_RPB6G3R_TCC2WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TCC2/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_TC0WO0            (PPS_RPB6G3R_RPB6G3R_TC0WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TC0/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_REFO3             (PPS_RPB6G3R_RPB6G3R_REFO3_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) REFO3 Position  */
#define PPS_RPB6G3R_RPB6G3R_TC1WO0            (PPS_RPB6G3R_RPB6G3R_TC1WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TC1/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_TC2WO0            (PPS_RPB6G3R_RPB6G3R_TC2WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TC2/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_TC3WO0            (PPS_RPB6G3R_RPB6G3R_TC3WO0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TC3/WO0 Position  */
#define PPS_RPB6G3R_RPB6G3R_QSCK              (PPS_RPB6G3R_RPB6G3R_QSCK_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) QSCK Position  */
#define PPS_RPB6G3R_RPB6G3R_QCS               (PPS_RPB6G3R_RPB6G3R_QCS_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) QCS Position  */
#define PPS_RPB6G3R_RPB6G3R_QD1               (PPS_RPB6G3R_RPB6G3R_QD1_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) QD1 Position  */
#define PPS_RPB6G3R_RPB6G3R_QD0               (PPS_RPB6G3R_RPB6G3R_QD0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) QD0 Position  */
#define PPS_RPB6G3R_RPB6G3R_QD3               (PPS_RPB6G3R_RPB6G3R_QD3_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) QD3 Position  */
#define PPS_RPB6G3R_RPB6G3R_CCLOUT0           (PPS_RPB6G3R_RPB6G3R_CCLOUT0_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) CCLOUT0 Position  */
#define PPS_RPB6G3R_RPB6G3R_TSTBUS2           (PPS_RPB6G3R_RPB6G3R_TSTBUS2_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TSTBUS2 Position  */
#define PPS_RPB6G3R_RPB6G3R_TSTBUS6           (PPS_RPB6G3R_RPB6G3R_TSTBUS6_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TSTBUS6 Position  */
#define PPS_RPB6G3R_RPB6G3R_TSTBUS10          (PPS_RPB6G3R_RPB6G3R_TSTBUS10_Val << PPS_RPB6G3R_RPB6G3R_Pos) /* (PPS_RPB6G3R) TSTBUS10 Position  */
#define PPS_RPB6G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB6G3R) Register Mask  */


/* -------- PPS_RPB6G4R : (PPS Offset: 0x2C0) (R/W 32)  -------- */
#define PPS_RPB6G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB6G4R)   Reset Value */

#define PPS_RPB6G4R_RPB6G4R_Pos               _UINT32_(0)                                          /* (PPS_RPB6G4R) RPB6/G4 Position */
#define PPS_RPB6G4R_RPB6G4R_Msk               (_UINT32_(0x1F) << PPS_RPB6G4R_RPB6G4R_Pos)          /* (PPS_RPB6G4R) RPB6/G4 Mask */
#define PPS_RPB6G4R_RPB6G4R(value)            (PPS_RPB6G4R_RPB6G4R_Msk & (_UINT32_(value) << PPS_RPB6G4R_RPB6G4R_Pos)) /* Assigment of value for RPB6G4R in the PPS_RPB6G4R register */
#define   PPS_RPB6G4R_RPB6G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB6G4R) OFF  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPB6G4R) SERCOM0/PAD2  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPB6G4R) SERCOM0/PAD1  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPB6G4R) SERCOM0/PAD0  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPB6G4R) SERCOM1/PAD3  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPB6G4R) SERCOM1/PAD1  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPB6G4R) SERCOM1/PAD0  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPB6G4R) SERCOM2/PAD3  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPB6G4R) SERCOM2/PAD0  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPB6G4R) SERCOM3/PAD3  */
#define   PPS_RPB6G4R_RPB6G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPB6G4R) SERCOM3/PAD2  */
#define   PPS_RPB6G4R_RPB6G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPB6G4R) TCC0/WO3  */
#define   PPS_RPB6G4R_RPB6G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPB6G4R) TCC0/WO1  */
#define   PPS_RPB6G4R_RPB6G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPB6G4R) TCC0/WO5  */
#define   PPS_RPB6G4R_RPB6G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPB6G4R) TCC1/WO3  */
#define   PPS_RPB6G4R_RPB6G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPB6G4R) TCC1/WO1  */
#define   PPS_RPB6G4R_RPB6G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPB6G4R) TCC1/WO5  */
#define   PPS_RPB6G4R_RPB6G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB6G4R) TCC2/WO1  */
#define   PPS_RPB6G4R_RPB6G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB6G4R) TC0/WO0  */
#define   PPS_RPB6G4R_RPB6G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPB6G4R) REFO4  */
#define   PPS_RPB6G4R_RPB6G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB6G4R) TC1/WO1  */
#define   PPS_RPB6G4R_RPB6G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB6G4R) TC2/WO1  */
#define   PPS_RPB6G4R_RPB6G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB6G4R) TC3/WO1  */
#define   PPS_RPB6G4R_RPB6G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB6G4R) QSCK  */
#define   PPS_RPB6G4R_RPB6G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB6G4R) QCS  */
#define   PPS_RPB6G4R_RPB6G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPB6G4R) QD2  */
#define   PPS_RPB6G4R_RPB6G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPB6G4R) QD1  */
#define   PPS_RPB6G4R_RPB6G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPB6G4R) QD0  */
#define   PPS_RPB6G4R_RPB6G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB6G4R) CCLOUT1  */
#define   PPS_RPB6G4R_RPB6G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPB6G4R) TSTBUS3  */
#define   PPS_RPB6G4R_RPB6G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPB6G4R) TSTBUS7  */
#define   PPS_RPB6G4R_RPB6G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPB6G4R) TSTBUS11  */
#define PPS_RPB6G4R_RPB6G4R_OFF               (PPS_RPB6G4R_RPB6G4R_OFF_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) OFF Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM0P2           (PPS_RPB6G4R_RPB6G4R_SCOM0P2_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM0/PAD2 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM0P1           (PPS_RPB6G4R_RPB6G4R_SCOM0P1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM0/PAD1 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM0P0           (PPS_RPB6G4R_RPB6G4R_SCOM0P0_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM0/PAD0 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM1P3           (PPS_RPB6G4R_RPB6G4R_SCOM1P3_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM1/PAD3 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM1P1           (PPS_RPB6G4R_RPB6G4R_SCOM1P1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM1/PAD1 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM1P0           (PPS_RPB6G4R_RPB6G4R_SCOM1P0_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM1/PAD0 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM2P3           (PPS_RPB6G4R_RPB6G4R_SCOM2P3_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM2/PAD3 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM2P0           (PPS_RPB6G4R_RPB6G4R_SCOM2P0_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM2/PAD0 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM3P3           (PPS_RPB6G4R_RPB6G4R_SCOM3P3_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM3/PAD3 Position  */
#define PPS_RPB6G4R_RPB6G4R_SCOM3P2           (PPS_RPB6G4R_RPB6G4R_SCOM3P2_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) SERCOM3/PAD2 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC0WO3           (PPS_RPB6G4R_RPB6G4R_TCC0WO3_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC0/WO3 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC0WO1           (PPS_RPB6G4R_RPB6G4R_TCC0WO1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC0/WO1 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC0WO5           (PPS_RPB6G4R_RPB6G4R_TCC0WO5_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC0/WO5 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC1WO3           (PPS_RPB6G4R_RPB6G4R_TCC1WO3_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC1/WO3 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC1WO1           (PPS_RPB6G4R_RPB6G4R_TCC1WO1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC1/WO1 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC1WO5           (PPS_RPB6G4R_RPB6G4R_TCC1WO5_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC1/WO5 Position  */
#define PPS_RPB6G4R_RPB6G4R_TCC2WO1           (PPS_RPB6G4R_RPB6G4R_TCC2WO1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TCC2/WO1 Position  */
#define PPS_RPB6G4R_RPB6G4R_TC0WO0            (PPS_RPB6G4R_RPB6G4R_TC0WO0_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TC0/WO0 Position  */
#define PPS_RPB6G4R_RPB6G4R_REFO4             (PPS_RPB6G4R_RPB6G4R_REFO4_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) REFO4 Position  */
#define PPS_RPB6G4R_RPB6G4R_TC1WO1            (PPS_RPB6G4R_RPB6G4R_TC1WO1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TC1/WO1 Position  */
#define PPS_RPB6G4R_RPB6G4R_TC2WO1            (PPS_RPB6G4R_RPB6G4R_TC2WO1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TC2/WO1 Position  */
#define PPS_RPB6G4R_RPB6G4R_TC3WO1            (PPS_RPB6G4R_RPB6G4R_TC3WO1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TC3/WO1 Position  */
#define PPS_RPB6G4R_RPB6G4R_QSCK              (PPS_RPB6G4R_RPB6G4R_QSCK_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) QSCK Position  */
#define PPS_RPB6G4R_RPB6G4R_QCS               (PPS_RPB6G4R_RPB6G4R_QCS_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) QCS Position  */
#define PPS_RPB6G4R_RPB6G4R_QD2               (PPS_RPB6G4R_RPB6G4R_QD2_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) QD2 Position  */
#define PPS_RPB6G4R_RPB6G4R_QD1               (PPS_RPB6G4R_RPB6G4R_QD1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) QD1 Position  */
#define PPS_RPB6G4R_RPB6G4R_QD0               (PPS_RPB6G4R_RPB6G4R_QD0_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) QD0 Position  */
#define PPS_RPB6G4R_RPB6G4R_CCLOUT1           (PPS_RPB6G4R_RPB6G4R_CCLOUT1_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) CCLOUT1 Position  */
#define PPS_RPB6G4R_RPB6G4R_TSTBUS3           (PPS_RPB6G4R_RPB6G4R_TSTBUS3_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TSTBUS3 Position  */
#define PPS_RPB6G4R_RPB6G4R_TSTBUS7           (PPS_RPB6G4R_RPB6G4R_TSTBUS7_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TSTBUS7 Position  */
#define PPS_RPB6G4R_RPB6G4R_TSTBUS11          (PPS_RPB6G4R_RPB6G4R_TSTBUS11_Val << PPS_RPB6G4R_RPB6G4R_Pos) /* (PPS_RPB6G4R) TSTBUS11 Position  */
#define PPS_RPB6G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB6G4R) Register Mask  */


/* -------- PPS_RPB7G1R : (PPS Offset: 0x2C4) (R/W 32)  -------- */
#define PPS_RPB7G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB7G1R)   Reset Value */

#define PPS_RPB7G1R_RPB7G1R_Pos               _UINT32_(0)                                          /* (PPS_RPB7G1R) RPB7/G1 Position */
#define PPS_RPB7G1R_RPB7G1R_Msk               (_UINT32_(0x1F) << PPS_RPB7G1R_RPB7G1R_Pos)          /* (PPS_RPB7G1R) RPB7/G1 Mask */
#define PPS_RPB7G1R_RPB7G1R(value)            (PPS_RPB7G1R_RPB7G1R_Msk & (_UINT32_(value) << PPS_RPB7G1R_RPB7G1R_Pos)) /* Assigment of value for RPB7G1R in the PPS_RPB7G1R register */
#define   PPS_RPB7G1R_RPB7G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB7G1R) OFF  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPB7G1R) SERCOM0/PAD3  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPB7G1R) SERCOM0/PAD2  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPB7G1R) SERCOM0/PAD1  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPB7G1R) SERCOM1/PAD0  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPB7G1R) SERCOM1/PAD2  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPB7G1R) SERCOM1/PAD1  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPB7G1R) SERCOM2/PAD0  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPB7G1R) SERCOM2/PAD1  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPB7G1R) SERCOM3/PAD0  */
#define   PPS_RPB7G1R_RPB7G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPB7G1R) SERCOM3/PAD3  */
#define   PPS_RPB7G1R_RPB7G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPB7G1R) TCC0/WO0  */
#define   PPS_RPB7G1R_RPB7G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPB7G1R) TCC0/WO4  */
#define   PPS_RPB7G1R_RPB7G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPB7G1R) TCC0/WO2  */
#define   PPS_RPB7G1R_RPB7G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPB7G1R) TCC1/WO0  */
#define   PPS_RPB7G1R_RPB7G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPB7G1R) TCC1/WO4  */
#define   PPS_RPB7G1R_RPB7G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPB7G1R) TCC1/WO2  */
#define   PPS_RPB7G1R_RPB7G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB7G1R) TCC2/WO0  */
#define   PPS_RPB7G1R_RPB7G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB7G1R) TC0/WO1  */
#define   PPS_RPB7G1R_RPB7G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPB7G1R) REFO1  */
#define   PPS_RPB7G1R_RPB7G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB7G1R) TC1/WO0  */
#define   PPS_RPB7G1R_RPB7G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB7G1R) TC2/WO0  */
#define   PPS_RPB7G1R_RPB7G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB7G1R) TC3/WO0  */
#define   PPS_RPB7G1R_RPB7G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB7G1R) QSCK  */
#define   PPS_RPB7G1R_RPB7G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB7G1R) QCS  */
#define   PPS_RPB7G1R_RPB7G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPB7G1R) QD3  */
#define   PPS_RPB7G1R_RPB7G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPB7G1R) QD2  */
#define   PPS_RPB7G1R_RPB7G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPB7G1R) QD1  */
#define   PPS_RPB7G1R_RPB7G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB7G1R) CCLOUT0  */
#define   PPS_RPB7G1R_RPB7G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPB7G1R) TSTBUS0  */
#define   PPS_RPB7G1R_RPB7G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPB7G1R) TSTBUS4  */
#define   PPS_RPB7G1R_RPB7G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPB7G1R) TSTBUS8  */
#define PPS_RPB7G1R_RPB7G1R_OFF               (PPS_RPB7G1R_RPB7G1R_OFF_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) OFF Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM0P3           (PPS_RPB7G1R_RPB7G1R_SCOM0P3_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM0P2           (PPS_RPB7G1R_RPB7G1R_SCOM0P2_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM0P1           (PPS_RPB7G1R_RPB7G1R_SCOM0P1_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM1P0           (PPS_RPB7G1R_RPB7G1R_SCOM1P0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM1P2           (PPS_RPB7G1R_RPB7G1R_SCOM1P2_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM1P1           (PPS_RPB7G1R_RPB7G1R_SCOM1P1_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM2P0           (PPS_RPB7G1R_RPB7G1R_SCOM2P0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM2P1           (PPS_RPB7G1R_RPB7G1R_SCOM2P1_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM3P0           (PPS_RPB7G1R_RPB7G1R_SCOM3P0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB7G1R_RPB7G1R_SCOM3P3           (PPS_RPB7G1R_RPB7G1R_SCOM3P3_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC0WO0           (PPS_RPB7G1R_RPB7G1R_TCC0WO0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC0/WO0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC0WO4           (PPS_RPB7G1R_RPB7G1R_TCC0WO4_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC0/WO4 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC0WO2           (PPS_RPB7G1R_RPB7G1R_TCC0WO2_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC0/WO2 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC1WO0           (PPS_RPB7G1R_RPB7G1R_TCC1WO0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC1/WO0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC1WO4           (PPS_RPB7G1R_RPB7G1R_TCC1WO4_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC1/WO4 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC1WO2           (PPS_RPB7G1R_RPB7G1R_TCC1WO2_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC1/WO2 Position  */
#define PPS_RPB7G1R_RPB7G1R_TCC2WO0           (PPS_RPB7G1R_RPB7G1R_TCC2WO0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TCC2/WO0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TC0WO1            (PPS_RPB7G1R_RPB7G1R_TC0WO1_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TC0/WO1 Position  */
#define PPS_RPB7G1R_RPB7G1R_REFO1             (PPS_RPB7G1R_RPB7G1R_REFO1_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) REFO1 Position  */
#define PPS_RPB7G1R_RPB7G1R_TC1WO0            (PPS_RPB7G1R_RPB7G1R_TC1WO0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TC1/WO0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TC2WO0            (PPS_RPB7G1R_RPB7G1R_TC2WO0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TC2/WO0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TC3WO0            (PPS_RPB7G1R_RPB7G1R_TC3WO0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TC3/WO0 Position  */
#define PPS_RPB7G1R_RPB7G1R_QSCK              (PPS_RPB7G1R_RPB7G1R_QSCK_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) QSCK Position  */
#define PPS_RPB7G1R_RPB7G1R_QCS               (PPS_RPB7G1R_RPB7G1R_QCS_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) QCS Position  */
#define PPS_RPB7G1R_RPB7G1R_QD3               (PPS_RPB7G1R_RPB7G1R_QD3_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) QD3 Position  */
#define PPS_RPB7G1R_RPB7G1R_QD2               (PPS_RPB7G1R_RPB7G1R_QD2_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) QD2 Position  */
#define PPS_RPB7G1R_RPB7G1R_QD1               (PPS_RPB7G1R_RPB7G1R_QD1_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) QD1 Position  */
#define PPS_RPB7G1R_RPB7G1R_CCLOUT0           (PPS_RPB7G1R_RPB7G1R_CCLOUT0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) CCLOUT0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TSTBUS0           (PPS_RPB7G1R_RPB7G1R_TSTBUS0_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TSTBUS0 Position  */
#define PPS_RPB7G1R_RPB7G1R_TSTBUS4           (PPS_RPB7G1R_RPB7G1R_TSTBUS4_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TSTBUS4 Position  */
#define PPS_RPB7G1R_RPB7G1R_TSTBUS8           (PPS_RPB7G1R_RPB7G1R_TSTBUS8_Val << PPS_RPB7G1R_RPB7G1R_Pos) /* (PPS_RPB7G1R) TSTBUS8 Position  */
#define PPS_RPB7G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB7G1R) Register Mask  */


/* -------- PPS_RPB7G4R : (PPS Offset: 0x2C8) (R/W 32)  -------- */
#define PPS_RPB7G4R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB7G4R)   Reset Value */

#define PPS_RPB7G4R_RPB7G4R_Pos               _UINT32_(0)                                          /* (PPS_RPB7G4R) RPB7/G4 Position */
#define PPS_RPB7G4R_RPB7G4R_Msk               (_UINT32_(0x1F) << PPS_RPB7G4R_RPB7G4R_Pos)          /* (PPS_RPB7G4R) RPB7/G4 Mask */
#define PPS_RPB7G4R_RPB7G4R(value)            (PPS_RPB7G4R_RPB7G4R_Msk & (_UINT32_(value) << PPS_RPB7G4R_RPB7G4R_Pos)) /* Assigment of value for RPB7G4R in the PPS_RPB7G4R register */
#define   PPS_RPB7G4R_RPB7G4R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB7G4R) OFF  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM0P2_Val     _UINT32_(0x1)                                        /* (PPS_RPB7G4R) SERCOM0/PAD2  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM0P1_Val     _UINT32_(0x2)                                        /* (PPS_RPB7G4R) SERCOM0/PAD1  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM0P0_Val     _UINT32_(0x3)                                        /* (PPS_RPB7G4R) SERCOM0/PAD0  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM1P3_Val     _UINT32_(0x4)                                        /* (PPS_RPB7G4R) SERCOM1/PAD3  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM1P1_Val     _UINT32_(0x5)                                        /* (PPS_RPB7G4R) SERCOM1/PAD1  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM1P0_Val     _UINT32_(0x6)                                        /* (PPS_RPB7G4R) SERCOM1/PAD0  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM2P3_Val     _UINT32_(0x7)                                        /* (PPS_RPB7G4R) SERCOM2/PAD3  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM2P0_Val     _UINT32_(0x8)                                        /* (PPS_RPB7G4R) SERCOM2/PAD0  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM3P3_Val     _UINT32_(0x9)                                        /* (PPS_RPB7G4R) SERCOM3/PAD3  */
#define   PPS_RPB7G4R_RPB7G4R_SCOM3P2_Val     _UINT32_(0xA)                                        /* (PPS_RPB7G4R) SERCOM3/PAD2  */
#define   PPS_RPB7G4R_RPB7G4R_TCC0WO3_Val     _UINT32_(0xB)                                        /* (PPS_RPB7G4R) TCC0/WO3  */
#define   PPS_RPB7G4R_RPB7G4R_TCC0WO1_Val     _UINT32_(0xC)                                        /* (PPS_RPB7G4R) TCC0/WO1  */
#define   PPS_RPB7G4R_RPB7G4R_TCC0WO5_Val     _UINT32_(0xD)                                        /* (PPS_RPB7G4R) TCC0/WO5  */
#define   PPS_RPB7G4R_RPB7G4R_TCC1WO3_Val     _UINT32_(0xE)                                        /* (PPS_RPB7G4R) TCC1/WO3  */
#define   PPS_RPB7G4R_RPB7G4R_TCC1WO1_Val     _UINT32_(0xF)                                        /* (PPS_RPB7G4R) TCC1/WO1  */
#define   PPS_RPB7G4R_RPB7G4R_TCC1WO5_Val     _UINT32_(0x10)                                       /* (PPS_RPB7G4R) TCC1/WO5  */
#define   PPS_RPB7G4R_RPB7G4R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB7G4R) TCC2/WO1  */
#define   PPS_RPB7G4R_RPB7G4R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB7G4R) TC0/WO0  */
#define   PPS_RPB7G4R_RPB7G4R_REFO4_Val       _UINT32_(0x13)                                       /* (PPS_RPB7G4R) REFO4  */
#define   PPS_RPB7G4R_RPB7G4R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB7G4R) TC1/WO1  */
#define   PPS_RPB7G4R_RPB7G4R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB7G4R) TC2/WO1  */
#define   PPS_RPB7G4R_RPB7G4R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB7G4R) TC3/WO1  */
#define   PPS_RPB7G4R_RPB7G4R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB7G4R) QSCK  */
#define   PPS_RPB7G4R_RPB7G4R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB7G4R) QCS  */
#define   PPS_RPB7G4R_RPB7G4R_QD2_Val         _UINT32_(0x19)                                       /* (PPS_RPB7G4R) QD2  */
#define   PPS_RPB7G4R_RPB7G4R_QD1_Val         _UINT32_(0x1A)                                       /* (PPS_RPB7G4R) QD1  */
#define   PPS_RPB7G4R_RPB7G4R_QD0_Val         _UINT32_(0x1B)                                       /* (PPS_RPB7G4R) QD0  */
#define   PPS_RPB7G4R_RPB7G4R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB7G4R) CCLOUT1  */
#define   PPS_RPB7G4R_RPB7G4R_TSTBUS3_Val     _UINT32_(0x1D)                                       /* (PPS_RPB7G4R) TSTBUS3  */
#define   PPS_RPB7G4R_RPB7G4R_TSTBUS7_Val     _UINT32_(0x1E)                                       /* (PPS_RPB7G4R) TSTBUS7  */
#define   PPS_RPB7G4R_RPB7G4R_TSTBUS11_Val    _UINT32_(0x1F)                                       /* (PPS_RPB7G4R) TSTBUS11  */
#define PPS_RPB7G4R_RPB7G4R_OFF               (PPS_RPB7G4R_RPB7G4R_OFF_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) OFF Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM0P2           (PPS_RPB7G4R_RPB7G4R_SCOM0P2_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM0/PAD2 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM0P1           (PPS_RPB7G4R_RPB7G4R_SCOM0P1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM0/PAD1 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM0P0           (PPS_RPB7G4R_RPB7G4R_SCOM0P0_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM0/PAD0 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM1P3           (PPS_RPB7G4R_RPB7G4R_SCOM1P3_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM1/PAD3 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM1P1           (PPS_RPB7G4R_RPB7G4R_SCOM1P1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM1/PAD1 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM1P0           (PPS_RPB7G4R_RPB7G4R_SCOM1P0_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM1/PAD0 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM2P3           (PPS_RPB7G4R_RPB7G4R_SCOM2P3_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM2/PAD3 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM2P0           (PPS_RPB7G4R_RPB7G4R_SCOM2P0_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM2/PAD0 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM3P3           (PPS_RPB7G4R_RPB7G4R_SCOM3P3_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM3/PAD3 Position  */
#define PPS_RPB7G4R_RPB7G4R_SCOM3P2           (PPS_RPB7G4R_RPB7G4R_SCOM3P2_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) SERCOM3/PAD2 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC0WO3           (PPS_RPB7G4R_RPB7G4R_TCC0WO3_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC0/WO3 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC0WO1           (PPS_RPB7G4R_RPB7G4R_TCC0WO1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC0/WO1 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC0WO5           (PPS_RPB7G4R_RPB7G4R_TCC0WO5_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC0/WO5 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC1WO3           (PPS_RPB7G4R_RPB7G4R_TCC1WO3_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC1/WO3 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC1WO1           (PPS_RPB7G4R_RPB7G4R_TCC1WO1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC1/WO1 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC1WO5           (PPS_RPB7G4R_RPB7G4R_TCC1WO5_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC1/WO5 Position  */
#define PPS_RPB7G4R_RPB7G4R_TCC2WO1           (PPS_RPB7G4R_RPB7G4R_TCC2WO1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TCC2/WO1 Position  */
#define PPS_RPB7G4R_RPB7G4R_TC0WO0            (PPS_RPB7G4R_RPB7G4R_TC0WO0_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TC0/WO0 Position  */
#define PPS_RPB7G4R_RPB7G4R_REFO4             (PPS_RPB7G4R_RPB7G4R_REFO4_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) REFO4 Position  */
#define PPS_RPB7G4R_RPB7G4R_TC1WO1            (PPS_RPB7G4R_RPB7G4R_TC1WO1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TC1/WO1 Position  */
#define PPS_RPB7G4R_RPB7G4R_TC2WO1            (PPS_RPB7G4R_RPB7G4R_TC2WO1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TC2/WO1 Position  */
#define PPS_RPB7G4R_RPB7G4R_TC3WO1            (PPS_RPB7G4R_RPB7G4R_TC3WO1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TC3/WO1 Position  */
#define PPS_RPB7G4R_RPB7G4R_QSCK              (PPS_RPB7G4R_RPB7G4R_QSCK_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) QSCK Position  */
#define PPS_RPB7G4R_RPB7G4R_QCS               (PPS_RPB7G4R_RPB7G4R_QCS_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) QCS Position  */
#define PPS_RPB7G4R_RPB7G4R_QD2               (PPS_RPB7G4R_RPB7G4R_QD2_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) QD2 Position  */
#define PPS_RPB7G4R_RPB7G4R_QD1               (PPS_RPB7G4R_RPB7G4R_QD1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) QD1 Position  */
#define PPS_RPB7G4R_RPB7G4R_QD0               (PPS_RPB7G4R_RPB7G4R_QD0_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) QD0 Position  */
#define PPS_RPB7G4R_RPB7G4R_CCLOUT1           (PPS_RPB7G4R_RPB7G4R_CCLOUT1_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) CCLOUT1 Position  */
#define PPS_RPB7G4R_RPB7G4R_TSTBUS3           (PPS_RPB7G4R_RPB7G4R_TSTBUS3_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TSTBUS3 Position  */
#define PPS_RPB7G4R_RPB7G4R_TSTBUS7           (PPS_RPB7G4R_RPB7G4R_TSTBUS7_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TSTBUS7 Position  */
#define PPS_RPB7G4R_RPB7G4R_TSTBUS11          (PPS_RPB7G4R_RPB7G4R_TSTBUS11_Val << PPS_RPB7G4R_RPB7G4R_Pos) /* (PPS_RPB7G4R) TSTBUS11 Position  */
#define PPS_RPB7G4R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB7G4R) Register Mask  */


/* -------- PPS_RPB8G1R : (PPS Offset: 0x2CC) (R/W 32)  -------- */
#define PPS_RPB8G1R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB8G1R)   Reset Value */

#define PPS_RPB8G1R_RPB8G1R_Pos               _UINT32_(0)                                          /* (PPS_RPB8G1R) RPB8/G1 Position */
#define PPS_RPB8G1R_RPB8G1R_Msk               (_UINT32_(0x1F) << PPS_RPB8G1R_RPB8G1R_Pos)          /* (PPS_RPB8G1R) RPB8/G1 Mask */
#define PPS_RPB8G1R_RPB8G1R(value)            (PPS_RPB8G1R_RPB8G1R_Msk & (_UINT32_(value) << PPS_RPB8G1R_RPB8G1R_Pos)) /* Assigment of value for RPB8G1R in the PPS_RPB8G1R register */
#define   PPS_RPB8G1R_RPB8G1R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB8G1R) OFF  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM0P3_Val     _UINT32_(0x1)                                        /* (PPS_RPB8G1R) SERCOM0/PAD3  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM0P2_Val     _UINT32_(0x2)                                        /* (PPS_RPB8G1R) SERCOM0/PAD2  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM0P1_Val     _UINT32_(0x3)                                        /* (PPS_RPB8G1R) SERCOM0/PAD1  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM1P0_Val     _UINT32_(0x4)                                        /* (PPS_RPB8G1R) SERCOM1/PAD0  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM1P2_Val     _UINT32_(0x5)                                        /* (PPS_RPB8G1R) SERCOM1/PAD2  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM1P1_Val     _UINT32_(0x6)                                        /* (PPS_RPB8G1R) SERCOM1/PAD1  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM2P0_Val     _UINT32_(0x7)                                        /* (PPS_RPB8G1R) SERCOM2/PAD0  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM2P1_Val     _UINT32_(0x8)                                        /* (PPS_RPB8G1R) SERCOM2/PAD1  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM3P0_Val     _UINT32_(0x9)                                        /* (PPS_RPB8G1R) SERCOM3/PAD0  */
#define   PPS_RPB8G1R_RPB8G1R_SCOM3P3_Val     _UINT32_(0xA)                                        /* (PPS_RPB8G1R) SERCOM3/PAD3  */
#define   PPS_RPB8G1R_RPB8G1R_TCC0WO0_Val     _UINT32_(0xB)                                        /* (PPS_RPB8G1R) TCC0/WO0  */
#define   PPS_RPB8G1R_RPB8G1R_TCC0WO4_Val     _UINT32_(0xC)                                        /* (PPS_RPB8G1R) TCC0/WO4  */
#define   PPS_RPB8G1R_RPB8G1R_TCC0WO2_Val     _UINT32_(0xD)                                        /* (PPS_RPB8G1R) TCC0/WO2  */
#define   PPS_RPB8G1R_RPB8G1R_TCC1WO0_Val     _UINT32_(0xE)                                        /* (PPS_RPB8G1R) TCC1/WO0  */
#define   PPS_RPB8G1R_RPB8G1R_TCC1WO4_Val     _UINT32_(0xF)                                        /* (PPS_RPB8G1R) TCC1/WO4  */
#define   PPS_RPB8G1R_RPB8G1R_TCC1WO2_Val     _UINT32_(0x10)                                       /* (PPS_RPB8G1R) TCC1/WO2  */
#define   PPS_RPB8G1R_RPB8G1R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB8G1R) TCC2/WO0  */
#define   PPS_RPB8G1R_RPB8G1R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB8G1R) TC0/WO1  */
#define   PPS_RPB8G1R_RPB8G1R_REFO1_Val       _UINT32_(0x13)                                       /* (PPS_RPB8G1R) REFO1  */
#define   PPS_RPB8G1R_RPB8G1R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB8G1R) TC1/WO0  */
#define   PPS_RPB8G1R_RPB8G1R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB8G1R) TC2/WO0  */
#define   PPS_RPB8G1R_RPB8G1R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB8G1R) TC3/WO0  */
#define   PPS_RPB8G1R_RPB8G1R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB8G1R) QSCK  */
#define   PPS_RPB8G1R_RPB8G1R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB8G1R) QCS  */
#define   PPS_RPB8G1R_RPB8G1R_QD3_Val         _UINT32_(0x19)                                       /* (PPS_RPB8G1R) QD3  */
#define   PPS_RPB8G1R_RPB8G1R_QD2_Val         _UINT32_(0x1A)                                       /* (PPS_RPB8G1R) QD2  */
#define   PPS_RPB8G1R_RPB8G1R_QD1_Val         _UINT32_(0x1B)                                       /* (PPS_RPB8G1R) QD1  */
#define   PPS_RPB8G1R_RPB8G1R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB8G1R) CCLOUT0  */
#define   PPS_RPB8G1R_RPB8G1R_TSTBUS0_Val     _UINT32_(0x1D)                                       /* (PPS_RPB8G1R) TSTBUS0  */
#define   PPS_RPB8G1R_RPB8G1R_TSTBUS4_Val     _UINT32_(0x1E)                                       /* (PPS_RPB8G1R) TSTBUS4  */
#define   PPS_RPB8G1R_RPB8G1R_TSTBUS8_Val     _UINT32_(0x1F)                                       /* (PPS_RPB8G1R) TSTBUS8  */
#define PPS_RPB8G1R_RPB8G1R_OFF               (PPS_RPB8G1R_RPB8G1R_OFF_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) OFF Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM0P3           (PPS_RPB8G1R_RPB8G1R_SCOM0P3_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM0P2           (PPS_RPB8G1R_RPB8G1R_SCOM0P2_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM0P1           (PPS_RPB8G1R_RPB8G1R_SCOM0P1_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM1P0           (PPS_RPB8G1R_RPB8G1R_SCOM1P0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM1P2           (PPS_RPB8G1R_RPB8G1R_SCOM1P2_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM1P1           (PPS_RPB8G1R_RPB8G1R_SCOM1P1_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM2P0           (PPS_RPB8G1R_RPB8G1R_SCOM2P0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM2P1           (PPS_RPB8G1R_RPB8G1R_SCOM2P1_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM3P0           (PPS_RPB8G1R_RPB8G1R_SCOM3P0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB8G1R_RPB8G1R_SCOM3P3           (PPS_RPB8G1R_RPB8G1R_SCOM3P3_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC0WO0           (PPS_RPB8G1R_RPB8G1R_TCC0WO0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC0/WO0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC0WO4           (PPS_RPB8G1R_RPB8G1R_TCC0WO4_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC0/WO4 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC0WO2           (PPS_RPB8G1R_RPB8G1R_TCC0WO2_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC0/WO2 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC1WO0           (PPS_RPB8G1R_RPB8G1R_TCC1WO0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC1/WO0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC1WO4           (PPS_RPB8G1R_RPB8G1R_TCC1WO4_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC1/WO4 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC1WO2           (PPS_RPB8G1R_RPB8G1R_TCC1WO2_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC1/WO2 Position  */
#define PPS_RPB8G1R_RPB8G1R_TCC2WO0           (PPS_RPB8G1R_RPB8G1R_TCC2WO0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TCC2/WO0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TC0WO1            (PPS_RPB8G1R_RPB8G1R_TC0WO1_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TC0/WO1 Position  */
#define PPS_RPB8G1R_RPB8G1R_REFO1             (PPS_RPB8G1R_RPB8G1R_REFO1_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) REFO1 Position  */
#define PPS_RPB8G1R_RPB8G1R_TC1WO0            (PPS_RPB8G1R_RPB8G1R_TC1WO0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TC1/WO0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TC2WO0            (PPS_RPB8G1R_RPB8G1R_TC2WO0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TC2/WO0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TC3WO0            (PPS_RPB8G1R_RPB8G1R_TC3WO0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TC3/WO0 Position  */
#define PPS_RPB8G1R_RPB8G1R_QSCK              (PPS_RPB8G1R_RPB8G1R_QSCK_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) QSCK Position  */
#define PPS_RPB8G1R_RPB8G1R_QCS               (PPS_RPB8G1R_RPB8G1R_QCS_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) QCS Position  */
#define PPS_RPB8G1R_RPB8G1R_QD3               (PPS_RPB8G1R_RPB8G1R_QD3_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) QD3 Position  */
#define PPS_RPB8G1R_RPB8G1R_QD2               (PPS_RPB8G1R_RPB8G1R_QD2_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) QD2 Position  */
#define PPS_RPB8G1R_RPB8G1R_QD1               (PPS_RPB8G1R_RPB8G1R_QD1_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) QD1 Position  */
#define PPS_RPB8G1R_RPB8G1R_CCLOUT0           (PPS_RPB8G1R_RPB8G1R_CCLOUT0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) CCLOUT0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TSTBUS0           (PPS_RPB8G1R_RPB8G1R_TSTBUS0_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TSTBUS0 Position  */
#define PPS_RPB8G1R_RPB8G1R_TSTBUS4           (PPS_RPB8G1R_RPB8G1R_TSTBUS4_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TSTBUS4 Position  */
#define PPS_RPB8G1R_RPB8G1R_TSTBUS8           (PPS_RPB8G1R_RPB8G1R_TSTBUS8_Val << PPS_RPB8G1R_RPB8G1R_Pos) /* (PPS_RPB8G1R) TSTBUS8 Position  */
#define PPS_RPB8G1R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB8G1R) Register Mask  */


/* -------- PPS_RPB8G2R : (PPS Offset: 0x2D0) (R/W 32)  -------- */
#define PPS_RPB8G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB8G2R)   Reset Value */

#define PPS_RPB8G2R_RPB8G2R_Pos               _UINT32_(0)                                          /* (PPS_RPB8G2R) RPB8/G2 Position */
#define PPS_RPB8G2R_RPB8G2R_Msk               (_UINT32_(0x1F) << PPS_RPB8G2R_RPB8G2R_Pos)          /* (PPS_RPB8G2R) RPB8/G2 Mask */
#define PPS_RPB8G2R_RPB8G2R(value)            (PPS_RPB8G2R_RPB8G2R_Msk & (_UINT32_(value) << PPS_RPB8G2R_RPB8G2R_Pos)) /* Assigment of value for RPB8G2R in the PPS_RPB8G2R register */
#define   PPS_RPB8G2R_RPB8G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB8G2R) OFF  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPB8G2R) SERCOM0/PAD0  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPB8G2R) SERCOM0/PAD3  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPB8G2R) SERCOM0/PAD2  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPB8G2R) SERCOM1/PAD1  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPB8G2R) SERCOM1/PAD3  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPB8G2R) SERCOM1/PAD2  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPB8G2R) SERCOM2/PAD1  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPB8G2R) SERCOM2/PAD2  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPB8G2R) SERCOM3/PAD1  */
#define   PPS_RPB8G2R_RPB8G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPB8G2R) SERCOM3/PAD0  */
#define   PPS_RPB8G2R_RPB8G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPB8G2R) TCC0/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPB8G2R) TCC0/WO5  */
#define   PPS_RPB8G2R_RPB8G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPB8G2R) TCC0/WO3  */
#define   PPS_RPB8G2R_RPB8G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPB8G2R) TCC1/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPB8G2R) TCC1/WO5  */
#define   PPS_RPB8G2R_RPB8G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPB8G2R) TCC1/WO3  */
#define   PPS_RPB8G2R_RPB8G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB8G2R) TCC2/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB8G2R) TC0/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPB8G2R) REFO2  */
#define   PPS_RPB8G2R_RPB8G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB8G2R) TC1/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB8G2R) TC2/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB8G2R) TC3/WO1  */
#define   PPS_RPB8G2R_RPB8G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB8G2R) QSCK  */
#define   PPS_RPB8G2R_RPB8G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB8G2R) QCS  */
#define   PPS_RPB8G2R_RPB8G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPB8G2R) QD0  */
#define   PPS_RPB8G2R_RPB8G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPB8G2R) QD3  */
#define   PPS_RPB8G2R_RPB8G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPB8G2R) QD2  */
#define   PPS_RPB8G2R_RPB8G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB8G2R) CCLOUT1  */
#define   PPS_RPB8G2R_RPB8G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPB8G2R) TSTBUS1  */
#define   PPS_RPB8G2R_RPB8G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPB8G2R) TSTBUS5  */
#define   PPS_RPB8G2R_RPB8G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPB8G2R) TSTBUS9  */
#define PPS_RPB8G2R_RPB8G2R_OFF               (PPS_RPB8G2R_RPB8G2R_OFF_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) OFF Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM0P0           (PPS_RPB8G2R_RPB8G2R_SCOM0P0_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM0P3           (PPS_RPB8G2R_RPB8G2R_SCOM0P3_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM0P2           (PPS_RPB8G2R_RPB8G2R_SCOM0P2_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM1P1           (PPS_RPB8G2R_RPB8G2R_SCOM1P1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM1P3           (PPS_RPB8G2R_RPB8G2R_SCOM1P3_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM1P2           (PPS_RPB8G2R_RPB8G2R_SCOM1P2_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM2P1           (PPS_RPB8G2R_RPB8G2R_SCOM2P1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM2P2           (PPS_RPB8G2R_RPB8G2R_SCOM2P2_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM3P1           (PPS_RPB8G2R_RPB8G2R_SCOM3P1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB8G2R_RPB8G2R_SCOM3P0           (PPS_RPB8G2R_RPB8G2R_SCOM3P0_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC0WO1           (PPS_RPB8G2R_RPB8G2R_TCC0WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC0/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC0WO5           (PPS_RPB8G2R_RPB8G2R_TCC0WO5_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC0/WO5 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC0WO3           (PPS_RPB8G2R_RPB8G2R_TCC0WO3_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC0/WO3 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC1WO1           (PPS_RPB8G2R_RPB8G2R_TCC1WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC1/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC1WO5           (PPS_RPB8G2R_RPB8G2R_TCC1WO5_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC1/WO5 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC1WO3           (PPS_RPB8G2R_RPB8G2R_TCC1WO3_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC1/WO3 Position  */
#define PPS_RPB8G2R_RPB8G2R_TCC2WO1           (PPS_RPB8G2R_RPB8G2R_TCC2WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TCC2/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TC0WO1            (PPS_RPB8G2R_RPB8G2R_TC0WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TC0/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_REFO2             (PPS_RPB8G2R_RPB8G2R_REFO2_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) REFO2 Position  */
#define PPS_RPB8G2R_RPB8G2R_TC1WO1            (PPS_RPB8G2R_RPB8G2R_TC1WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TC1/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TC2WO1            (PPS_RPB8G2R_RPB8G2R_TC2WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TC2/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TC3WO1            (PPS_RPB8G2R_RPB8G2R_TC3WO1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TC3/WO1 Position  */
#define PPS_RPB8G2R_RPB8G2R_QSCK              (PPS_RPB8G2R_RPB8G2R_QSCK_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) QSCK Position  */
#define PPS_RPB8G2R_RPB8G2R_QCS               (PPS_RPB8G2R_RPB8G2R_QCS_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) QCS Position  */
#define PPS_RPB8G2R_RPB8G2R_QD0               (PPS_RPB8G2R_RPB8G2R_QD0_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) QD0 Position  */
#define PPS_RPB8G2R_RPB8G2R_QD3               (PPS_RPB8G2R_RPB8G2R_QD3_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) QD3 Position  */
#define PPS_RPB8G2R_RPB8G2R_QD2               (PPS_RPB8G2R_RPB8G2R_QD2_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) QD2 Position  */
#define PPS_RPB8G2R_RPB8G2R_CCLOUT1           (PPS_RPB8G2R_RPB8G2R_CCLOUT1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) CCLOUT1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TSTBUS1           (PPS_RPB8G2R_RPB8G2R_TSTBUS1_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TSTBUS1 Position  */
#define PPS_RPB8G2R_RPB8G2R_TSTBUS5           (PPS_RPB8G2R_RPB8G2R_TSTBUS5_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TSTBUS5 Position  */
#define PPS_RPB8G2R_RPB8G2R_TSTBUS9           (PPS_RPB8G2R_RPB8G2R_TSTBUS9_Val << PPS_RPB8G2R_RPB8G2R_Pos) /* (PPS_RPB8G2R) TSTBUS9 Position  */
#define PPS_RPB8G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB8G2R) Register Mask  */


/* -------- PPS_RPB9G2R : (PPS Offset: 0x2D4) (R/W 32)  -------- */
#define PPS_RPB9G2R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB9G2R)   Reset Value */

#define PPS_RPB9G2R_RPB9G2R_Pos               _UINT32_(0)                                          /* (PPS_RPB9G2R) RPB9/G2 Position */
#define PPS_RPB9G2R_RPB9G2R_Msk               (_UINT32_(0x1F) << PPS_RPB9G2R_RPB9G2R_Pos)          /* (PPS_RPB9G2R) RPB9/G2 Mask */
#define PPS_RPB9G2R_RPB9G2R(value)            (PPS_RPB9G2R_RPB9G2R_Msk & (_UINT32_(value) << PPS_RPB9G2R_RPB9G2R_Pos)) /* Assigment of value for RPB9G2R in the PPS_RPB9G2R register */
#define   PPS_RPB9G2R_RPB9G2R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB9G2R) OFF  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM0P0_Val     _UINT32_(0x1)                                        /* (PPS_RPB9G2R) SERCOM0/PAD0  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM0P3_Val     _UINT32_(0x2)                                        /* (PPS_RPB9G2R) SERCOM0/PAD3  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM0P2_Val     _UINT32_(0x3)                                        /* (PPS_RPB9G2R) SERCOM0/PAD2  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM1P1_Val     _UINT32_(0x4)                                        /* (PPS_RPB9G2R) SERCOM1/PAD1  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM1P3_Val     _UINT32_(0x5)                                        /* (PPS_RPB9G2R) SERCOM1/PAD3  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM1P2_Val     _UINT32_(0x6)                                        /* (PPS_RPB9G2R) SERCOM1/PAD2  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM2P1_Val     _UINT32_(0x7)                                        /* (PPS_RPB9G2R) SERCOM2/PAD1  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM2P2_Val     _UINT32_(0x8)                                        /* (PPS_RPB9G2R) SERCOM2/PAD2  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM3P1_Val     _UINT32_(0x9)                                        /* (PPS_RPB9G2R) SERCOM3/PAD1  */
#define   PPS_RPB9G2R_RPB9G2R_SCOM3P0_Val     _UINT32_(0xA)                                        /* (PPS_RPB9G2R) SERCOM3/PAD0  */
#define   PPS_RPB9G2R_RPB9G2R_TCC0WO1_Val     _UINT32_(0xB)                                        /* (PPS_RPB9G2R) TCC0/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_TCC0WO5_Val     _UINT32_(0xC)                                        /* (PPS_RPB9G2R) TCC0/WO5  */
#define   PPS_RPB9G2R_RPB9G2R_TCC0WO3_Val     _UINT32_(0xD)                                        /* (PPS_RPB9G2R) TCC0/WO3  */
#define   PPS_RPB9G2R_RPB9G2R_TCC1WO1_Val     _UINT32_(0xE)                                        /* (PPS_RPB9G2R) TCC1/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_TCC1WO5_Val     _UINT32_(0xF)                                        /* (PPS_RPB9G2R) TCC1/WO5  */
#define   PPS_RPB9G2R_RPB9G2R_TCC1WO3_Val     _UINT32_(0x10)                                       /* (PPS_RPB9G2R) TCC1/WO3  */
#define   PPS_RPB9G2R_RPB9G2R_TCC2WO1_Val     _UINT32_(0x11)                                       /* (PPS_RPB9G2R) TCC2/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_TC0WO1_Val      _UINT32_(0x12)                                       /* (PPS_RPB9G2R) TC0/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_REFO2_Val       _UINT32_(0x13)                                       /* (PPS_RPB9G2R) REFO2  */
#define   PPS_RPB9G2R_RPB9G2R_TC1WO1_Val      _UINT32_(0x14)                                       /* (PPS_RPB9G2R) TC1/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_TC2WO1_Val      _UINT32_(0x15)                                       /* (PPS_RPB9G2R) TC2/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_TC3WO1_Val      _UINT32_(0x16)                                       /* (PPS_RPB9G2R) TC3/WO1  */
#define   PPS_RPB9G2R_RPB9G2R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB9G2R) QSCK  */
#define   PPS_RPB9G2R_RPB9G2R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB9G2R) QCS  */
#define   PPS_RPB9G2R_RPB9G2R_QD0_Val         _UINT32_(0x19)                                       /* (PPS_RPB9G2R) QD0  */
#define   PPS_RPB9G2R_RPB9G2R_QD3_Val         _UINT32_(0x1A)                                       /* (PPS_RPB9G2R) QD3  */
#define   PPS_RPB9G2R_RPB9G2R_QD2_Val         _UINT32_(0x1B)                                       /* (PPS_RPB9G2R) QD2  */
#define   PPS_RPB9G2R_RPB9G2R_CCLOUT1_Val     _UINT32_(0x1C)                                       /* (PPS_RPB9G2R) CCLOUT1  */
#define   PPS_RPB9G2R_RPB9G2R_TSTBUS1_Val     _UINT32_(0x1D)                                       /* (PPS_RPB9G2R) TSTBUS1  */
#define   PPS_RPB9G2R_RPB9G2R_TSTBUS5_Val     _UINT32_(0x1E)                                       /* (PPS_RPB9G2R) TSTBUS5  */
#define   PPS_RPB9G2R_RPB9G2R_TSTBUS9_Val     _UINT32_(0x1F)                                       /* (PPS_RPB9G2R) TSTBUS9  */
#define PPS_RPB9G2R_RPB9G2R_OFF               (PPS_RPB9G2R_RPB9G2R_OFF_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) OFF Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM0P0           (PPS_RPB9G2R_RPB9G2R_SCOM0P0_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM0P3           (PPS_RPB9G2R_RPB9G2R_SCOM0P3_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM0P2           (PPS_RPB9G2R_RPB9G2R_SCOM0P2_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM1P1           (PPS_RPB9G2R_RPB9G2R_SCOM1P1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM1P3           (PPS_RPB9G2R_RPB9G2R_SCOM1P3_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM1P2           (PPS_RPB9G2R_RPB9G2R_SCOM1P2_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM2P1           (PPS_RPB9G2R_RPB9G2R_SCOM2P1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM2P2           (PPS_RPB9G2R_RPB9G2R_SCOM2P2_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM3P1           (PPS_RPB9G2R_RPB9G2R_SCOM3P1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB9G2R_RPB9G2R_SCOM3P0           (PPS_RPB9G2R_RPB9G2R_SCOM3P0_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC0WO1           (PPS_RPB9G2R_RPB9G2R_TCC0WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC0/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC0WO5           (PPS_RPB9G2R_RPB9G2R_TCC0WO5_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC0/WO5 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC0WO3           (PPS_RPB9G2R_RPB9G2R_TCC0WO3_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC0/WO3 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC1WO1           (PPS_RPB9G2R_RPB9G2R_TCC1WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC1/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC1WO5           (PPS_RPB9G2R_RPB9G2R_TCC1WO5_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC1/WO5 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC1WO3           (PPS_RPB9G2R_RPB9G2R_TCC1WO3_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC1/WO3 Position  */
#define PPS_RPB9G2R_RPB9G2R_TCC2WO1           (PPS_RPB9G2R_RPB9G2R_TCC2WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TCC2/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TC0WO1            (PPS_RPB9G2R_RPB9G2R_TC0WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TC0/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_REFO2             (PPS_RPB9G2R_RPB9G2R_REFO2_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) REFO2 Position  */
#define PPS_RPB9G2R_RPB9G2R_TC1WO1            (PPS_RPB9G2R_RPB9G2R_TC1WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TC1/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TC2WO1            (PPS_RPB9G2R_RPB9G2R_TC2WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TC2/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TC3WO1            (PPS_RPB9G2R_RPB9G2R_TC3WO1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TC3/WO1 Position  */
#define PPS_RPB9G2R_RPB9G2R_QSCK              (PPS_RPB9G2R_RPB9G2R_QSCK_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) QSCK Position  */
#define PPS_RPB9G2R_RPB9G2R_QCS               (PPS_RPB9G2R_RPB9G2R_QCS_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) QCS Position  */
#define PPS_RPB9G2R_RPB9G2R_QD0               (PPS_RPB9G2R_RPB9G2R_QD0_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) QD0 Position  */
#define PPS_RPB9G2R_RPB9G2R_QD3               (PPS_RPB9G2R_RPB9G2R_QD3_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) QD3 Position  */
#define PPS_RPB9G2R_RPB9G2R_QD2               (PPS_RPB9G2R_RPB9G2R_QD2_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) QD2 Position  */
#define PPS_RPB9G2R_RPB9G2R_CCLOUT1           (PPS_RPB9G2R_RPB9G2R_CCLOUT1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) CCLOUT1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TSTBUS1           (PPS_RPB9G2R_RPB9G2R_TSTBUS1_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TSTBUS1 Position  */
#define PPS_RPB9G2R_RPB9G2R_TSTBUS5           (PPS_RPB9G2R_RPB9G2R_TSTBUS5_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TSTBUS5 Position  */
#define PPS_RPB9G2R_RPB9G2R_TSTBUS9           (PPS_RPB9G2R_RPB9G2R_TSTBUS9_Val << PPS_RPB9G2R_RPB9G2R_Pos) /* (PPS_RPB9G2R) TSTBUS9 Position  */
#define PPS_RPB9G2R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB9G2R) Register Mask  */


/* -------- PPS_RPB9G3R : (PPS Offset: 0x2D8) (R/W 32)  -------- */
#define PPS_RPB9G3R_RESETVALUE                _UINT32_(0x00)                                       /*  (PPS_RPB9G3R)   Reset Value */

#define PPS_RPB9G3R_RPB9G3R_Pos               _UINT32_(0)                                          /* (PPS_RPB9G3R) RPB9/G3 Position */
#define PPS_RPB9G3R_RPB9G3R_Msk               (_UINT32_(0x1F) << PPS_RPB9G3R_RPB9G3R_Pos)          /* (PPS_RPB9G3R) RPB9/G3 Mask */
#define PPS_RPB9G3R_RPB9G3R(value)            (PPS_RPB9G3R_RPB9G3R_Msk & (_UINT32_(value) << PPS_RPB9G3R_RPB9G3R_Pos)) /* Assigment of value for RPB9G3R in the PPS_RPB9G3R register */
#define   PPS_RPB9G3R_RPB9G3R_OFF_Val         _UINT32_(0x0)                                        /* (PPS_RPB9G3R) OFF  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM0P1_Val     _UINT32_(0x1)                                        /* (PPS_RPB9G3R) SERCOM0/PAD1  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM0P0_Val     _UINT32_(0x2)                                        /* (PPS_RPB9G3R) SERCOM0/PAD0  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM0P3_Val     _UINT32_(0x3)                                        /* (PPS_RPB9G3R) SERCOM0/PAD3  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM1P2_Val     _UINT32_(0x4)                                        /* (PPS_RPB9G3R) SERCOM1/PAD2  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM1P0_Val     _UINT32_(0x5)                                        /* (PPS_RPB9G3R) SERCOM1/PAD0  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM1P3_Val     _UINT32_(0x6)                                        /* (PPS_RPB9G3R) SERCOM1/PAD3  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM2P2_Val     _UINT32_(0x7)                                        /* (PPS_RPB9G3R) SERCOM2/PAD2  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM2P3_Val     _UINT32_(0x8)                                        /* (PPS_RPB9G3R) SERCOM2/PAD3  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM3P2_Val     _UINT32_(0x9)                                        /* (PPS_RPB9G3R) SERCOM3/PAD2  */
#define   PPS_RPB9G3R_RPB9G3R_SCOM3P1_Val     _UINT32_(0xA)                                        /* (PPS_RPB9G3R) SERCOM3/PAD1  */
#define   PPS_RPB9G3R_RPB9G3R_TCC0WO2_Val     _UINT32_(0xB)                                        /* (PPS_RPB9G3R) TCC0/WO2  */
#define   PPS_RPB9G3R_RPB9G3R_TCC0WO0_Val     _UINT32_(0xC)                                        /* (PPS_RPB9G3R) TCC0/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_TCC0WO4_Val     _UINT32_(0xD)                                        /* (PPS_RPB9G3R) TCC0/WO4  */
#define   PPS_RPB9G3R_RPB9G3R_TCC1WO2_Val     _UINT32_(0xE)                                        /* (PPS_RPB9G3R) TCC1/WO2  */
#define   PPS_RPB9G3R_RPB9G3R_TCC1WO0_Val     _UINT32_(0xF)                                        /* (PPS_RPB9G3R) TCC1/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_TCC1WO4_Val     _UINT32_(0x10)                                       /* (PPS_RPB9G3R) TCC1/WO4  */
#define   PPS_RPB9G3R_RPB9G3R_TCC2WO0_Val     _UINT32_(0x11)                                       /* (PPS_RPB9G3R) TCC2/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_TC0WO0_Val      _UINT32_(0x12)                                       /* (PPS_RPB9G3R) TC0/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_REFO3_Val       _UINT32_(0x13)                                       /* (PPS_RPB9G3R) REFO3  */
#define   PPS_RPB9G3R_RPB9G3R_TC1WO0_Val      _UINT32_(0x14)                                       /* (PPS_RPB9G3R) TC1/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_TC2WO0_Val      _UINT32_(0x15)                                       /* (PPS_RPB9G3R) TC2/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_TC3WO0_Val      _UINT32_(0x16)                                       /* (PPS_RPB9G3R) TC3/WO0  */
#define   PPS_RPB9G3R_RPB9G3R_QSCK_Val        _UINT32_(0x17)                                       /* (PPS_RPB9G3R) QSCK  */
#define   PPS_RPB9G3R_RPB9G3R_QCS_Val         _UINT32_(0x18)                                       /* (PPS_RPB9G3R) QCS  */
#define   PPS_RPB9G3R_RPB9G3R_QD1_Val         _UINT32_(0x19)                                       /* (PPS_RPB9G3R) QD1  */
#define   PPS_RPB9G3R_RPB9G3R_QD0_Val         _UINT32_(0x1A)                                       /* (PPS_RPB9G3R) QD0  */
#define   PPS_RPB9G3R_RPB9G3R_QD3_Val         _UINT32_(0x1B)                                       /* (PPS_RPB9G3R) QD3  */
#define   PPS_RPB9G3R_RPB9G3R_CCLOUT0_Val     _UINT32_(0x1C)                                       /* (PPS_RPB9G3R) CCLOUT0  */
#define   PPS_RPB9G3R_RPB9G3R_TSTBUS2_Val     _UINT32_(0x1D)                                       /* (PPS_RPB9G3R) TSTBUS2  */
#define   PPS_RPB9G3R_RPB9G3R_TSTBUS6_Val     _UINT32_(0x1E)                                       /* (PPS_RPB9G3R) TSTBUS6  */
#define   PPS_RPB9G3R_RPB9G3R_TSTBUS10_Val    _UINT32_(0x1F)                                       /* (PPS_RPB9G3R) TSTBUS10  */
#define PPS_RPB9G3R_RPB9G3R_OFF               (PPS_RPB9G3R_RPB9G3R_OFF_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) OFF Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM0P1           (PPS_RPB9G3R_RPB9G3R_SCOM0P1_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM0P0           (PPS_RPB9G3R_RPB9G3R_SCOM0P0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM0P3           (PPS_RPB9G3R_RPB9G3R_SCOM0P3_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM1P2           (PPS_RPB9G3R_RPB9G3R_SCOM1P2_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM1P0           (PPS_RPB9G3R_RPB9G3R_SCOM1P0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM1P3           (PPS_RPB9G3R_RPB9G3R_SCOM1P3_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM2P2           (PPS_RPB9G3R_RPB9G3R_SCOM2P2_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM2P3           (PPS_RPB9G3R_RPB9G3R_SCOM2P3_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM3P2           (PPS_RPB9G3R_RPB9G3R_SCOM3P2_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB9G3R_RPB9G3R_SCOM3P1           (PPS_RPB9G3R_RPB9G3R_SCOM3P1_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC0WO2           (PPS_RPB9G3R_RPB9G3R_TCC0WO2_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC0/WO2 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC0WO0           (PPS_RPB9G3R_RPB9G3R_TCC0WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC0/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC0WO4           (PPS_RPB9G3R_RPB9G3R_TCC0WO4_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC0/WO4 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC1WO2           (PPS_RPB9G3R_RPB9G3R_TCC1WO2_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC1/WO2 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC1WO0           (PPS_RPB9G3R_RPB9G3R_TCC1WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC1/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC1WO4           (PPS_RPB9G3R_RPB9G3R_TCC1WO4_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC1/WO4 Position  */
#define PPS_RPB9G3R_RPB9G3R_TCC2WO0           (PPS_RPB9G3R_RPB9G3R_TCC2WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TCC2/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_TC0WO0            (PPS_RPB9G3R_RPB9G3R_TC0WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TC0/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_REFO3             (PPS_RPB9G3R_RPB9G3R_REFO3_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) REFO3 Position  */
#define PPS_RPB9G3R_RPB9G3R_TC1WO0            (PPS_RPB9G3R_RPB9G3R_TC1WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TC1/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_TC2WO0            (PPS_RPB9G3R_RPB9G3R_TC2WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TC2/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_TC3WO0            (PPS_RPB9G3R_RPB9G3R_TC3WO0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TC3/WO0 Position  */
#define PPS_RPB9G3R_RPB9G3R_QSCK              (PPS_RPB9G3R_RPB9G3R_QSCK_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) QSCK Position  */
#define PPS_RPB9G3R_RPB9G3R_QCS               (PPS_RPB9G3R_RPB9G3R_QCS_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) QCS Position  */
#define PPS_RPB9G3R_RPB9G3R_QD1               (PPS_RPB9G3R_RPB9G3R_QD1_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) QD1 Position  */
#define PPS_RPB9G3R_RPB9G3R_QD0               (PPS_RPB9G3R_RPB9G3R_QD0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) QD0 Position  */
#define PPS_RPB9G3R_RPB9G3R_QD3               (PPS_RPB9G3R_RPB9G3R_QD3_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) QD3 Position  */
#define PPS_RPB9G3R_RPB9G3R_CCLOUT0           (PPS_RPB9G3R_RPB9G3R_CCLOUT0_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) CCLOUT0 Position  */
#define PPS_RPB9G3R_RPB9G3R_TSTBUS2           (PPS_RPB9G3R_RPB9G3R_TSTBUS2_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TSTBUS2 Position  */
#define PPS_RPB9G3R_RPB9G3R_TSTBUS6           (PPS_RPB9G3R_RPB9G3R_TSTBUS6_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TSTBUS6 Position  */
#define PPS_RPB9G3R_RPB9G3R_TSTBUS10          (PPS_RPB9G3R_RPB9G3R_TSTBUS10_Val << PPS_RPB9G3R_RPB9G3R_Pos) /* (PPS_RPB9G3R) TSTBUS10 Position  */
#define PPS_RPB9G3R_Msk                       _UINT32_(0x0000001F)                                 /* (PPS_RPB9G3R) Register Mask  */


/* -------- PPS_RPB10G3R : (PPS Offset: 0x2DC) (R/W 32)  -------- */
#define PPS_RPB10G3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB10G3R)   Reset Value */

#define PPS_RPB10G3R_RPB10G3R_Pos             _UINT32_(0)                                          /* (PPS_RPB10G3R) RPB10/G3 Position */
#define PPS_RPB10G3R_RPB10G3R_Msk             (_UINT32_(0x1F) << PPS_RPB10G3R_RPB10G3R_Pos)        /* (PPS_RPB10G3R) RPB10/G3 Mask */
#define PPS_RPB10G3R_RPB10G3R(value)          (PPS_RPB10G3R_RPB10G3R_Msk & (_UINT32_(value) << PPS_RPB10G3R_RPB10G3R_Pos)) /* Assigment of value for RPB10G3R in the PPS_RPB10G3R register */
#define   PPS_RPB10G3R_RPB10G3R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB10G3R) OFF  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM0P1_Val   _UINT32_(0x1)                                        /* (PPS_RPB10G3R) SERCOM0/PAD1  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM0P0_Val   _UINT32_(0x2)                                        /* (PPS_RPB10G3R) SERCOM0/PAD0  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM0P3_Val   _UINT32_(0x3)                                        /* (PPS_RPB10G3R) SERCOM0/PAD3  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM1P2_Val   _UINT32_(0x4)                                        /* (PPS_RPB10G3R) SERCOM1/PAD2  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM1P0_Val   _UINT32_(0x5)                                        /* (PPS_RPB10G3R) SERCOM1/PAD0  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM1P3_Val   _UINT32_(0x6)                                        /* (PPS_RPB10G3R) SERCOM1/PAD3  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM2P2_Val   _UINT32_(0x7)                                        /* (PPS_RPB10G3R) SERCOM2/PAD2  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM2P3_Val   _UINT32_(0x8)                                        /* (PPS_RPB10G3R) SERCOM2/PAD3  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM3P2_Val   _UINT32_(0x9)                                        /* (PPS_RPB10G3R) SERCOM3/PAD2  */
#define   PPS_RPB10G3R_RPB10G3R_SCOM3P1_Val   _UINT32_(0xA)                                        /* (PPS_RPB10G3R) SERCOM3/PAD1  */
#define   PPS_RPB10G3R_RPB10G3R_TCC0WO2_Val   _UINT32_(0xB)                                        /* (PPS_RPB10G3R) TCC0/WO2  */
#define   PPS_RPB10G3R_RPB10G3R_TCC0WO0_Val   _UINT32_(0xC)                                        /* (PPS_RPB10G3R) TCC0/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_TCC0WO4_Val   _UINT32_(0xD)                                        /* (PPS_RPB10G3R) TCC0/WO4  */
#define   PPS_RPB10G3R_RPB10G3R_TCC1WO2_Val   _UINT32_(0xE)                                        /* (PPS_RPB10G3R) TCC1/WO2  */
#define   PPS_RPB10G3R_RPB10G3R_TCC1WO0_Val   _UINT32_(0xF)                                        /* (PPS_RPB10G3R) TCC1/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_TCC1WO4_Val   _UINT32_(0x10)                                       /* (PPS_RPB10G3R) TCC1/WO4  */
#define   PPS_RPB10G3R_RPB10G3R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPB10G3R) TCC2/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPB10G3R) TC0/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_REFO3_Val     _UINT32_(0x13)                                       /* (PPS_RPB10G3R) REFO3  */
#define   PPS_RPB10G3R_RPB10G3R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPB10G3R) TC1/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPB10G3R) TC2/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPB10G3R) TC3/WO0  */
#define   PPS_RPB10G3R_RPB10G3R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB10G3R) QSCK  */
#define   PPS_RPB10G3R_RPB10G3R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB10G3R) QCS  */
#define   PPS_RPB10G3R_RPB10G3R_QD1_Val       _UINT32_(0x19)                                       /* (PPS_RPB10G3R) QD1  */
#define   PPS_RPB10G3R_RPB10G3R_QD0_Val       _UINT32_(0x1A)                                       /* (PPS_RPB10G3R) QD0  */
#define   PPS_RPB10G3R_RPB10G3R_QD3_Val       _UINT32_(0x1B)                                       /* (PPS_RPB10G3R) QD3  */
#define   PPS_RPB10G3R_RPB10G3R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPB10G3R) CCLOUT0  */
#define   PPS_RPB10G3R_RPB10G3R_TSTBUS2_Val   _UINT32_(0x1D)                                       /* (PPS_RPB10G3R) TSTBUS2  */
#define   PPS_RPB10G3R_RPB10G3R_TSTBUS6_Val   _UINT32_(0x1E)                                       /* (PPS_RPB10G3R) TSTBUS6  */
#define   PPS_RPB10G3R_RPB10G3R_TSTBUS10_Val  _UINT32_(0x1F)                                       /* (PPS_RPB10G3R) TSTBUS10  */
#define PPS_RPB10G3R_RPB10G3R_OFF             (PPS_RPB10G3R_RPB10G3R_OFF_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) OFF Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM0P1         (PPS_RPB10G3R_RPB10G3R_SCOM0P1_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM0P0         (PPS_RPB10G3R_RPB10G3R_SCOM0P0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM0P3         (PPS_RPB10G3R_RPB10G3R_SCOM0P3_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM1P2         (PPS_RPB10G3R_RPB10G3R_SCOM1P2_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM1P0         (PPS_RPB10G3R_RPB10G3R_SCOM1P0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM1P3         (PPS_RPB10G3R_RPB10G3R_SCOM1P3_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM2P2         (PPS_RPB10G3R_RPB10G3R_SCOM2P2_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM2P3         (PPS_RPB10G3R_RPB10G3R_SCOM2P3_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM3P2         (PPS_RPB10G3R_RPB10G3R_SCOM3P2_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB10G3R_RPB10G3R_SCOM3P1         (PPS_RPB10G3R_RPB10G3R_SCOM3P1_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC0WO2         (PPS_RPB10G3R_RPB10G3R_TCC0WO2_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC0/WO2 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC0WO0         (PPS_RPB10G3R_RPB10G3R_TCC0WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC0/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC0WO4         (PPS_RPB10G3R_RPB10G3R_TCC0WO4_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC0/WO4 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC1WO2         (PPS_RPB10G3R_RPB10G3R_TCC1WO2_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC1/WO2 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC1WO0         (PPS_RPB10G3R_RPB10G3R_TCC1WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC1/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC1WO4         (PPS_RPB10G3R_RPB10G3R_TCC1WO4_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC1/WO4 Position  */
#define PPS_RPB10G3R_RPB10G3R_TCC2WO0         (PPS_RPB10G3R_RPB10G3R_TCC2WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TCC2/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_TC0WO0          (PPS_RPB10G3R_RPB10G3R_TC0WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TC0/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_REFO3           (PPS_RPB10G3R_RPB10G3R_REFO3_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) REFO3 Position  */
#define PPS_RPB10G3R_RPB10G3R_TC1WO0          (PPS_RPB10G3R_RPB10G3R_TC1WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TC1/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_TC2WO0          (PPS_RPB10G3R_RPB10G3R_TC2WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TC2/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_TC3WO0          (PPS_RPB10G3R_RPB10G3R_TC3WO0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TC3/WO0 Position  */
#define PPS_RPB10G3R_RPB10G3R_QSCK            (PPS_RPB10G3R_RPB10G3R_QSCK_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) QSCK Position  */
#define PPS_RPB10G3R_RPB10G3R_QCS             (PPS_RPB10G3R_RPB10G3R_QCS_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) QCS Position  */
#define PPS_RPB10G3R_RPB10G3R_QD1             (PPS_RPB10G3R_RPB10G3R_QD1_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) QD1 Position  */
#define PPS_RPB10G3R_RPB10G3R_QD0             (PPS_RPB10G3R_RPB10G3R_QD0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) QD0 Position  */
#define PPS_RPB10G3R_RPB10G3R_QD3             (PPS_RPB10G3R_RPB10G3R_QD3_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) QD3 Position  */
#define PPS_RPB10G3R_RPB10G3R_CCLOUT0         (PPS_RPB10G3R_RPB10G3R_CCLOUT0_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) CCLOUT0 Position  */
#define PPS_RPB10G3R_RPB10G3R_TSTBUS2         (PPS_RPB10G3R_RPB10G3R_TSTBUS2_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TSTBUS2 Position  */
#define PPS_RPB10G3R_RPB10G3R_TSTBUS6         (PPS_RPB10G3R_RPB10G3R_TSTBUS6_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TSTBUS6 Position  */
#define PPS_RPB10G3R_RPB10G3R_TSTBUS10        (PPS_RPB10G3R_RPB10G3R_TSTBUS10_Val << PPS_RPB10G3R_RPB10G3R_Pos) /* (PPS_RPB10G3R) TSTBUS10 Position  */
#define PPS_RPB10G3R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB10G3R) Register Mask  */


/* -------- PPS_RPB10G4R : (PPS Offset: 0x2E0) (R/W 32)  -------- */
#define PPS_RPB10G4R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB10G4R)   Reset Value */

#define PPS_RPB10G4R_RPB10G4R_Pos             _UINT32_(0)                                          /* (PPS_RPB10G4R) RPB10/G4 Position */
#define PPS_RPB10G4R_RPB10G4R_Msk             (_UINT32_(0x1F) << PPS_RPB10G4R_RPB10G4R_Pos)        /* (PPS_RPB10G4R) RPB10/G4 Mask */
#define PPS_RPB10G4R_RPB10G4R(value)          (PPS_RPB10G4R_RPB10G4R_Msk & (_UINT32_(value) << PPS_RPB10G4R_RPB10G4R_Pos)) /* Assigment of value for RPB10G4R in the PPS_RPB10G4R register */
#define   PPS_RPB10G4R_RPB10G4R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB10G4R) OFF  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM0P2_Val   _UINT32_(0x1)                                        /* (PPS_RPB10G4R) SERCOM0/PAD2  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM0P1_Val   _UINT32_(0x2)                                        /* (PPS_RPB10G4R) SERCOM0/PAD1  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM0P0_Val   _UINT32_(0x3)                                        /* (PPS_RPB10G4R) SERCOM0/PAD0  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM1P3_Val   _UINT32_(0x4)                                        /* (PPS_RPB10G4R) SERCOM1/PAD3  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM1P1_Val   _UINT32_(0x5)                                        /* (PPS_RPB10G4R) SERCOM1/PAD1  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM1P0_Val   _UINT32_(0x6)                                        /* (PPS_RPB10G4R) SERCOM1/PAD0  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM2P3_Val   _UINT32_(0x7)                                        /* (PPS_RPB10G4R) SERCOM2/PAD3  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM2P0_Val   _UINT32_(0x8)                                        /* (PPS_RPB10G4R) SERCOM2/PAD0  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM3P3_Val   _UINT32_(0x9)                                        /* (PPS_RPB10G4R) SERCOM3/PAD3  */
#define   PPS_RPB10G4R_RPB10G4R_SCOM3P2_Val   _UINT32_(0xA)                                        /* (PPS_RPB10G4R) SERCOM3/PAD2  */
#define   PPS_RPB10G4R_RPB10G4R_TCC0WO3_Val   _UINT32_(0xB)                                        /* (PPS_RPB10G4R) TCC0/WO3  */
#define   PPS_RPB10G4R_RPB10G4R_TCC0WO1_Val   _UINT32_(0xC)                                        /* (PPS_RPB10G4R) TCC0/WO1  */
#define   PPS_RPB10G4R_RPB10G4R_TCC0WO5_Val   _UINT32_(0xD)                                        /* (PPS_RPB10G4R) TCC0/WO5  */
#define   PPS_RPB10G4R_RPB10G4R_TCC1WO3_Val   _UINT32_(0xE)                                        /* (PPS_RPB10G4R) TCC1/WO3  */
#define   PPS_RPB10G4R_RPB10G4R_TCC1WO1_Val   _UINT32_(0xF)                                        /* (PPS_RPB10G4R) TCC1/WO1  */
#define   PPS_RPB10G4R_RPB10G4R_TCC1WO5_Val   _UINT32_(0x10)                                       /* (PPS_RPB10G4R) TCC1/WO5  */
#define   PPS_RPB10G4R_RPB10G4R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPB10G4R) TCC2/WO1  */
#define   PPS_RPB10G4R_RPB10G4R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPB10G4R) TC0/WO0  */
#define   PPS_RPB10G4R_RPB10G4R_REFO4_Val     _UINT32_(0x13)                                       /* (PPS_RPB10G4R) REFO4  */
#define   PPS_RPB10G4R_RPB10G4R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPB10G4R) TC1/WO1  */
#define   PPS_RPB10G4R_RPB10G4R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPB10G4R) TC2/WO1  */
#define   PPS_RPB10G4R_RPB10G4R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPB10G4R) TC3/WO1  */
#define   PPS_RPB10G4R_RPB10G4R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB10G4R) QSCK  */
#define   PPS_RPB10G4R_RPB10G4R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB10G4R) QCS  */
#define   PPS_RPB10G4R_RPB10G4R_QD2_Val       _UINT32_(0x19)                                       /* (PPS_RPB10G4R) QD2  */
#define   PPS_RPB10G4R_RPB10G4R_QD1_Val       _UINT32_(0x1A)                                       /* (PPS_RPB10G4R) QD1  */
#define   PPS_RPB10G4R_RPB10G4R_QD0_Val       _UINT32_(0x1B)                                       /* (PPS_RPB10G4R) QD0  */
#define   PPS_RPB10G4R_RPB10G4R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPB10G4R) CCLOUT1  */
#define   PPS_RPB10G4R_RPB10G4R_TSTBUS3_Val   _UINT32_(0x1D)                                       /* (PPS_RPB10G4R) TSTBUS3  */
#define   PPS_RPB10G4R_RPB10G4R_TSTBUS7_Val   _UINT32_(0x1E)                                       /* (PPS_RPB10G4R) TSTBUS7  */
#define   PPS_RPB10G4R_RPB10G4R_TSTBUS11_Val  _UINT32_(0x1F)                                       /* (PPS_RPB10G4R) TSTBUS11  */
#define PPS_RPB10G4R_RPB10G4R_OFF             (PPS_RPB10G4R_RPB10G4R_OFF_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) OFF Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM0P2         (PPS_RPB10G4R_RPB10G4R_SCOM0P2_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM0/PAD2 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM0P1         (PPS_RPB10G4R_RPB10G4R_SCOM0P1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM0/PAD1 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM0P0         (PPS_RPB10G4R_RPB10G4R_SCOM0P0_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM0/PAD0 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM1P3         (PPS_RPB10G4R_RPB10G4R_SCOM1P3_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM1/PAD3 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM1P1         (PPS_RPB10G4R_RPB10G4R_SCOM1P1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM1/PAD1 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM1P0         (PPS_RPB10G4R_RPB10G4R_SCOM1P0_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM1/PAD0 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM2P3         (PPS_RPB10G4R_RPB10G4R_SCOM2P3_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM2/PAD3 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM2P0         (PPS_RPB10G4R_RPB10G4R_SCOM2P0_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM2/PAD0 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM3P3         (PPS_RPB10G4R_RPB10G4R_SCOM3P3_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM3/PAD3 Position  */
#define PPS_RPB10G4R_RPB10G4R_SCOM3P2         (PPS_RPB10G4R_RPB10G4R_SCOM3P2_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) SERCOM3/PAD2 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC0WO3         (PPS_RPB10G4R_RPB10G4R_TCC0WO3_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC0/WO3 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC0WO1         (PPS_RPB10G4R_RPB10G4R_TCC0WO1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC0/WO1 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC0WO5         (PPS_RPB10G4R_RPB10G4R_TCC0WO5_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC0/WO5 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC1WO3         (PPS_RPB10G4R_RPB10G4R_TCC1WO3_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC1/WO3 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC1WO1         (PPS_RPB10G4R_RPB10G4R_TCC1WO1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC1/WO1 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC1WO5         (PPS_RPB10G4R_RPB10G4R_TCC1WO5_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC1/WO5 Position  */
#define PPS_RPB10G4R_RPB10G4R_TCC2WO1         (PPS_RPB10G4R_RPB10G4R_TCC2WO1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TCC2/WO1 Position  */
#define PPS_RPB10G4R_RPB10G4R_TC0WO0          (PPS_RPB10G4R_RPB10G4R_TC0WO0_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TC0/WO0 Position  */
#define PPS_RPB10G4R_RPB10G4R_REFO4           (PPS_RPB10G4R_RPB10G4R_REFO4_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) REFO4 Position  */
#define PPS_RPB10G4R_RPB10G4R_TC1WO1          (PPS_RPB10G4R_RPB10G4R_TC1WO1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TC1/WO1 Position  */
#define PPS_RPB10G4R_RPB10G4R_TC2WO1          (PPS_RPB10G4R_RPB10G4R_TC2WO1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TC2/WO1 Position  */
#define PPS_RPB10G4R_RPB10G4R_TC3WO1          (PPS_RPB10G4R_RPB10G4R_TC3WO1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TC3/WO1 Position  */
#define PPS_RPB10G4R_RPB10G4R_QSCK            (PPS_RPB10G4R_RPB10G4R_QSCK_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) QSCK Position  */
#define PPS_RPB10G4R_RPB10G4R_QCS             (PPS_RPB10G4R_RPB10G4R_QCS_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) QCS Position  */
#define PPS_RPB10G4R_RPB10G4R_QD2             (PPS_RPB10G4R_RPB10G4R_QD2_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) QD2 Position  */
#define PPS_RPB10G4R_RPB10G4R_QD1             (PPS_RPB10G4R_RPB10G4R_QD1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) QD1 Position  */
#define PPS_RPB10G4R_RPB10G4R_QD0             (PPS_RPB10G4R_RPB10G4R_QD0_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) QD0 Position  */
#define PPS_RPB10G4R_RPB10G4R_CCLOUT1         (PPS_RPB10G4R_RPB10G4R_CCLOUT1_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) CCLOUT1 Position  */
#define PPS_RPB10G4R_RPB10G4R_TSTBUS3         (PPS_RPB10G4R_RPB10G4R_TSTBUS3_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TSTBUS3 Position  */
#define PPS_RPB10G4R_RPB10G4R_TSTBUS7         (PPS_RPB10G4R_RPB10G4R_TSTBUS7_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TSTBUS7 Position  */
#define PPS_RPB10G4R_RPB10G4R_TSTBUS11        (PPS_RPB10G4R_RPB10G4R_TSTBUS11_Val << PPS_RPB10G4R_RPB10G4R_Pos) /* (PPS_RPB10G4R) TSTBUS11 Position  */
#define PPS_RPB10G4R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB10G4R) Register Mask  */


/* -------- PPS_RPB11G1R : (PPS Offset: 0x2E4) (R/W 32)  -------- */
#define PPS_RPB11G1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB11G1R)   Reset Value */

#define PPS_RPB11G1R_RPB11G1R_Pos             _UINT32_(0)                                          /* (PPS_RPB11G1R) RPB11/G1 Position */
#define PPS_RPB11G1R_RPB11G1R_Msk             (_UINT32_(0x1F) << PPS_RPB11G1R_RPB11G1R_Pos)        /* (PPS_RPB11G1R) RPB11/G1 Mask */
#define PPS_RPB11G1R_RPB11G1R(value)          (PPS_RPB11G1R_RPB11G1R_Msk & (_UINT32_(value) << PPS_RPB11G1R_RPB11G1R_Pos)) /* Assigment of value for RPB11G1R in the PPS_RPB11G1R register */
#define   PPS_RPB11G1R_RPB11G1R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB11G1R) OFF  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM0P3_Val   _UINT32_(0x1)                                        /* (PPS_RPB11G1R) SERCOM0/PAD3  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM0P2_Val   _UINT32_(0x2)                                        /* (PPS_RPB11G1R) SERCOM0/PAD2  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM0P1_Val   _UINT32_(0x3)                                        /* (PPS_RPB11G1R) SERCOM0/PAD1  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM1P0_Val   _UINT32_(0x4)                                        /* (PPS_RPB11G1R) SERCOM1/PAD0  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM1P2_Val   _UINT32_(0x5)                                        /* (PPS_RPB11G1R) SERCOM1/PAD2  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM1P1_Val   _UINT32_(0x6)                                        /* (PPS_RPB11G1R) SERCOM1/PAD1  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM2P0_Val   _UINT32_(0x7)                                        /* (PPS_RPB11G1R) SERCOM2/PAD0  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM2P1_Val   _UINT32_(0x8)                                        /* (PPS_RPB11G1R) SERCOM2/PAD1  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM3P0_Val   _UINT32_(0x9)                                        /* (PPS_RPB11G1R) SERCOM3/PAD0  */
#define   PPS_RPB11G1R_RPB11G1R_SCOM3P3_Val   _UINT32_(0xA)                                        /* (PPS_RPB11G1R) SERCOM3/PAD3  */
#define   PPS_RPB11G1R_RPB11G1R_TCC0WO0_Val   _UINT32_(0xB)                                        /* (PPS_RPB11G1R) TCC0/WO0  */
#define   PPS_RPB11G1R_RPB11G1R_TCC0WO4_Val   _UINT32_(0xC)                                        /* (PPS_RPB11G1R) TCC0/WO4  */
#define   PPS_RPB11G1R_RPB11G1R_TCC0WO2_Val   _UINT32_(0xD)                                        /* (PPS_RPB11G1R) TCC0/WO2  */
#define   PPS_RPB11G1R_RPB11G1R_TCC1WO0_Val   _UINT32_(0xE)                                        /* (PPS_RPB11G1R) TCC1/WO0  */
#define   PPS_RPB11G1R_RPB11G1R_TCC1WO4_Val   _UINT32_(0xF)                                        /* (PPS_RPB11G1R) TCC1/WO4  */
#define   PPS_RPB11G1R_RPB11G1R_TCC1WO2_Val   _UINT32_(0x10)                                       /* (PPS_RPB11G1R) TCC1/WO2  */
#define   PPS_RPB11G1R_RPB11G1R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPB11G1R) TCC2/WO0  */
#define   PPS_RPB11G1R_RPB11G1R_TC0WO1_Val    _UINT32_(0x12)                                       /* (PPS_RPB11G1R) TC0/WO1  */
#define   PPS_RPB11G1R_RPB11G1R_REFO1_Val     _UINT32_(0x13)                                       /* (PPS_RPB11G1R) REFO1  */
#define   PPS_RPB11G1R_RPB11G1R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPB11G1R) TC1/WO0  */
#define   PPS_RPB11G1R_RPB11G1R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPB11G1R) TC2/WO0  */
#define   PPS_RPB11G1R_RPB11G1R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPB11G1R) TC3/WO0  */
#define   PPS_RPB11G1R_RPB11G1R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB11G1R) QSCK  */
#define   PPS_RPB11G1R_RPB11G1R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB11G1R) QCS  */
#define   PPS_RPB11G1R_RPB11G1R_QD3_Val       _UINT32_(0x19)                                       /* (PPS_RPB11G1R) QD3  */
#define   PPS_RPB11G1R_RPB11G1R_QD2_Val       _UINT32_(0x1A)                                       /* (PPS_RPB11G1R) QD2  */
#define   PPS_RPB11G1R_RPB11G1R_QD1_Val       _UINT32_(0x1B)                                       /* (PPS_RPB11G1R) QD1  */
#define   PPS_RPB11G1R_RPB11G1R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPB11G1R) CCLOUT0  */
#define   PPS_RPB11G1R_RPB11G1R_TSTBUS0_Val   _UINT32_(0x1D)                                       /* (PPS_RPB11G1R) TSTBUS0  */
#define   PPS_RPB11G1R_RPB11G1R_TSTBUS4_Val   _UINT32_(0x1E)                                       /* (PPS_RPB11G1R) TSTBUS4  */
#define   PPS_RPB11G1R_RPB11G1R_TSTBUS8_Val   _UINT32_(0x1F)                                       /* (PPS_RPB11G1R) TSTBUS8  */
#define PPS_RPB11G1R_RPB11G1R_OFF             (PPS_RPB11G1R_RPB11G1R_OFF_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) OFF Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM0P3         (PPS_RPB11G1R_RPB11G1R_SCOM0P3_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM0P2         (PPS_RPB11G1R_RPB11G1R_SCOM0P2_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM0P1         (PPS_RPB11G1R_RPB11G1R_SCOM0P1_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM1P0         (PPS_RPB11G1R_RPB11G1R_SCOM1P0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM1P2         (PPS_RPB11G1R_RPB11G1R_SCOM1P2_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM1P1         (PPS_RPB11G1R_RPB11G1R_SCOM1P1_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM2P0         (PPS_RPB11G1R_RPB11G1R_SCOM2P0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM2P1         (PPS_RPB11G1R_RPB11G1R_SCOM2P1_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM3P0         (PPS_RPB11G1R_RPB11G1R_SCOM3P0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB11G1R_RPB11G1R_SCOM3P3         (PPS_RPB11G1R_RPB11G1R_SCOM3P3_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC0WO0         (PPS_RPB11G1R_RPB11G1R_TCC0WO0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC0/WO0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC0WO4         (PPS_RPB11G1R_RPB11G1R_TCC0WO4_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC0/WO4 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC0WO2         (PPS_RPB11G1R_RPB11G1R_TCC0WO2_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC0/WO2 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC1WO0         (PPS_RPB11G1R_RPB11G1R_TCC1WO0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC1/WO0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC1WO4         (PPS_RPB11G1R_RPB11G1R_TCC1WO4_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC1/WO4 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC1WO2         (PPS_RPB11G1R_RPB11G1R_TCC1WO2_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC1/WO2 Position  */
#define PPS_RPB11G1R_RPB11G1R_TCC2WO0         (PPS_RPB11G1R_RPB11G1R_TCC2WO0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TCC2/WO0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TC0WO1          (PPS_RPB11G1R_RPB11G1R_TC0WO1_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TC0/WO1 Position  */
#define PPS_RPB11G1R_RPB11G1R_REFO1           (PPS_RPB11G1R_RPB11G1R_REFO1_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) REFO1 Position  */
#define PPS_RPB11G1R_RPB11G1R_TC1WO0          (PPS_RPB11G1R_RPB11G1R_TC1WO0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TC1/WO0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TC2WO0          (PPS_RPB11G1R_RPB11G1R_TC2WO0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TC2/WO0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TC3WO0          (PPS_RPB11G1R_RPB11G1R_TC3WO0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TC3/WO0 Position  */
#define PPS_RPB11G1R_RPB11G1R_QSCK            (PPS_RPB11G1R_RPB11G1R_QSCK_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) QSCK Position  */
#define PPS_RPB11G1R_RPB11G1R_QCS             (PPS_RPB11G1R_RPB11G1R_QCS_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) QCS Position  */
#define PPS_RPB11G1R_RPB11G1R_QD3             (PPS_RPB11G1R_RPB11G1R_QD3_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) QD3 Position  */
#define PPS_RPB11G1R_RPB11G1R_QD2             (PPS_RPB11G1R_RPB11G1R_QD2_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) QD2 Position  */
#define PPS_RPB11G1R_RPB11G1R_QD1             (PPS_RPB11G1R_RPB11G1R_QD1_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) QD1 Position  */
#define PPS_RPB11G1R_RPB11G1R_CCLOUT0         (PPS_RPB11G1R_RPB11G1R_CCLOUT0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) CCLOUT0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TSTBUS0         (PPS_RPB11G1R_RPB11G1R_TSTBUS0_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TSTBUS0 Position  */
#define PPS_RPB11G1R_RPB11G1R_TSTBUS4         (PPS_RPB11G1R_RPB11G1R_TSTBUS4_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TSTBUS4 Position  */
#define PPS_RPB11G1R_RPB11G1R_TSTBUS8         (PPS_RPB11G1R_RPB11G1R_TSTBUS8_Val << PPS_RPB11G1R_RPB11G1R_Pos) /* (PPS_RPB11G1R) TSTBUS8 Position  */
#define PPS_RPB11G1R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB11G1R) Register Mask  */


/* -------- PPS_RPB11G4R : (PPS Offset: 0x2E8) (R/W 32)  -------- */
#define PPS_RPB11G4R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB11G4R)   Reset Value */

#define PPS_RPB11G4R_RPB11G4R_Pos             _UINT32_(0)                                          /* (PPS_RPB11G4R) RPB11/G4 Position */
#define PPS_RPB11G4R_RPB11G4R_Msk             (_UINT32_(0x1F) << PPS_RPB11G4R_RPB11G4R_Pos)        /* (PPS_RPB11G4R) RPB11/G4 Mask */
#define PPS_RPB11G4R_RPB11G4R(value)          (PPS_RPB11G4R_RPB11G4R_Msk & (_UINT32_(value) << PPS_RPB11G4R_RPB11G4R_Pos)) /* Assigment of value for RPB11G4R in the PPS_RPB11G4R register */
#define   PPS_RPB11G4R_RPB11G4R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB11G4R) OFF  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM0P2_Val   _UINT32_(0x1)                                        /* (PPS_RPB11G4R) SERCOM0/PAD2  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM0P1_Val   _UINT32_(0x2)                                        /* (PPS_RPB11G4R) SERCOM0/PAD1  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM0P0_Val   _UINT32_(0x3)                                        /* (PPS_RPB11G4R) SERCOM0/PAD0  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM1P3_Val   _UINT32_(0x4)                                        /* (PPS_RPB11G4R) SERCOM1/PAD3  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM1P1_Val   _UINT32_(0x5)                                        /* (PPS_RPB11G4R) SERCOM1/PAD1  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM1P0_Val   _UINT32_(0x6)                                        /* (PPS_RPB11G4R) SERCOM1/PAD0  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM2P3_Val   _UINT32_(0x7)                                        /* (PPS_RPB11G4R) SERCOM2/PAD3  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM2P0_Val   _UINT32_(0x8)                                        /* (PPS_RPB11G4R) SERCOM2/PAD0  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM3P3_Val   _UINT32_(0x9)                                        /* (PPS_RPB11G4R) SERCOM3/PAD3  */
#define   PPS_RPB11G4R_RPB11G4R_SCOM3P2_Val   _UINT32_(0xA)                                        /* (PPS_RPB11G4R) SERCOM3/PAD2  */
#define   PPS_RPB11G4R_RPB11G4R_TCC0WO3_Val   _UINT32_(0xB)                                        /* (PPS_RPB11G4R) TCC0/WO3  */
#define   PPS_RPB11G4R_RPB11G4R_TCC0WO1_Val   _UINT32_(0xC)                                        /* (PPS_RPB11G4R) TCC0/WO1  */
#define   PPS_RPB11G4R_RPB11G4R_TCC0WO5_Val   _UINT32_(0xD)                                        /* (PPS_RPB11G4R) TCC0/WO5  */
#define   PPS_RPB11G4R_RPB11G4R_TCC1WO3_Val   _UINT32_(0xE)                                        /* (PPS_RPB11G4R) TCC1/WO3  */
#define   PPS_RPB11G4R_RPB11G4R_TCC1WO1_Val   _UINT32_(0xF)                                        /* (PPS_RPB11G4R) TCC1/WO1  */
#define   PPS_RPB11G4R_RPB11G4R_TCC1WO5_Val   _UINT32_(0x10)                                       /* (PPS_RPB11G4R) TCC1/WO5  */
#define   PPS_RPB11G4R_RPB11G4R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPB11G4R) TCC2/WO1  */
#define   PPS_RPB11G4R_RPB11G4R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPB11G4R) TC0/WO0  */
#define   PPS_RPB11G4R_RPB11G4R_REFO4_Val     _UINT32_(0x13)                                       /* (PPS_RPB11G4R) REFO4  */
#define   PPS_RPB11G4R_RPB11G4R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPB11G4R) TC1/WO1  */
#define   PPS_RPB11G4R_RPB11G4R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPB11G4R) TC2/WO1  */
#define   PPS_RPB11G4R_RPB11G4R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPB11G4R) TC3/WO1  */
#define   PPS_RPB11G4R_RPB11G4R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB11G4R) QSCK  */
#define   PPS_RPB11G4R_RPB11G4R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB11G4R) QCS  */
#define   PPS_RPB11G4R_RPB11G4R_QD2_Val       _UINT32_(0x19)                                       /* (PPS_RPB11G4R) QD2  */
#define   PPS_RPB11G4R_RPB11G4R_QD1_Val       _UINT32_(0x1A)                                       /* (PPS_RPB11G4R) QD1  */
#define   PPS_RPB11G4R_RPB11G4R_QD0_Val       _UINT32_(0x1B)                                       /* (PPS_RPB11G4R) QD0  */
#define   PPS_RPB11G4R_RPB11G4R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPB11G4R) CCLOUT1  */
#define   PPS_RPB11G4R_RPB11G4R_TSTBUS3_Val   _UINT32_(0x1D)                                       /* (PPS_RPB11G4R) TSTBUS3  */
#define   PPS_RPB11G4R_RPB11G4R_TSTBUS7_Val   _UINT32_(0x1E)                                       /* (PPS_RPB11G4R) TSTBUS7  */
#define   PPS_RPB11G4R_RPB11G4R_TSTBUS11_Val  _UINT32_(0x1F)                                       /* (PPS_RPB11G4R) TSTBUS11  */
#define PPS_RPB11G4R_RPB11G4R_OFF             (PPS_RPB11G4R_RPB11G4R_OFF_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) OFF Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM0P2         (PPS_RPB11G4R_RPB11G4R_SCOM0P2_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM0/PAD2 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM0P1         (PPS_RPB11G4R_RPB11G4R_SCOM0P1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM0/PAD1 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM0P0         (PPS_RPB11G4R_RPB11G4R_SCOM0P0_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM0/PAD0 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM1P3         (PPS_RPB11G4R_RPB11G4R_SCOM1P3_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM1/PAD3 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM1P1         (PPS_RPB11G4R_RPB11G4R_SCOM1P1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM1/PAD1 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM1P0         (PPS_RPB11G4R_RPB11G4R_SCOM1P0_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM1/PAD0 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM2P3         (PPS_RPB11G4R_RPB11G4R_SCOM2P3_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM2/PAD3 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM2P0         (PPS_RPB11G4R_RPB11G4R_SCOM2P0_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM2/PAD0 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM3P3         (PPS_RPB11G4R_RPB11G4R_SCOM3P3_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM3/PAD3 Position  */
#define PPS_RPB11G4R_RPB11G4R_SCOM3P2         (PPS_RPB11G4R_RPB11G4R_SCOM3P2_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) SERCOM3/PAD2 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC0WO3         (PPS_RPB11G4R_RPB11G4R_TCC0WO3_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC0/WO3 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC0WO1         (PPS_RPB11G4R_RPB11G4R_TCC0WO1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC0/WO1 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC0WO5         (PPS_RPB11G4R_RPB11G4R_TCC0WO5_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC0/WO5 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC1WO3         (PPS_RPB11G4R_RPB11G4R_TCC1WO3_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC1/WO3 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC1WO1         (PPS_RPB11G4R_RPB11G4R_TCC1WO1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC1/WO1 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC1WO5         (PPS_RPB11G4R_RPB11G4R_TCC1WO5_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC1/WO5 Position  */
#define PPS_RPB11G4R_RPB11G4R_TCC2WO1         (PPS_RPB11G4R_RPB11G4R_TCC2WO1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TCC2/WO1 Position  */
#define PPS_RPB11G4R_RPB11G4R_TC0WO0          (PPS_RPB11G4R_RPB11G4R_TC0WO0_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TC0/WO0 Position  */
#define PPS_RPB11G4R_RPB11G4R_REFO4           (PPS_RPB11G4R_RPB11G4R_REFO4_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) REFO4 Position  */
#define PPS_RPB11G4R_RPB11G4R_TC1WO1          (PPS_RPB11G4R_RPB11G4R_TC1WO1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TC1/WO1 Position  */
#define PPS_RPB11G4R_RPB11G4R_TC2WO1          (PPS_RPB11G4R_RPB11G4R_TC2WO1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TC2/WO1 Position  */
#define PPS_RPB11G4R_RPB11G4R_TC3WO1          (PPS_RPB11G4R_RPB11G4R_TC3WO1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TC3/WO1 Position  */
#define PPS_RPB11G4R_RPB11G4R_QSCK            (PPS_RPB11G4R_RPB11G4R_QSCK_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) QSCK Position  */
#define PPS_RPB11G4R_RPB11G4R_QCS             (PPS_RPB11G4R_RPB11G4R_QCS_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) QCS Position  */
#define PPS_RPB11G4R_RPB11G4R_QD2             (PPS_RPB11G4R_RPB11G4R_QD2_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) QD2 Position  */
#define PPS_RPB11G4R_RPB11G4R_QD1             (PPS_RPB11G4R_RPB11G4R_QD1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) QD1 Position  */
#define PPS_RPB11G4R_RPB11G4R_QD0             (PPS_RPB11G4R_RPB11G4R_QD0_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) QD0 Position  */
#define PPS_RPB11G4R_RPB11G4R_CCLOUT1         (PPS_RPB11G4R_RPB11G4R_CCLOUT1_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) CCLOUT1 Position  */
#define PPS_RPB11G4R_RPB11G4R_TSTBUS3         (PPS_RPB11G4R_RPB11G4R_TSTBUS3_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TSTBUS3 Position  */
#define PPS_RPB11G4R_RPB11G4R_TSTBUS7         (PPS_RPB11G4R_RPB11G4R_TSTBUS7_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TSTBUS7 Position  */
#define PPS_RPB11G4R_RPB11G4R_TSTBUS11        (PPS_RPB11G4R_RPB11G4R_TSTBUS11_Val << PPS_RPB11G4R_RPB11G4R_Pos) /* (PPS_RPB11G4R) TSTBUS11 Position  */
#define PPS_RPB11G4R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB11G4R) Register Mask  */


/* -------- PPS_RPB12G1R : (PPS Offset: 0x2EC) (R/W 32)  -------- */
#define PPS_RPB12G1R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB12G1R)   Reset Value */

#define PPS_RPB12G1R_RPB12G1R_Pos             _UINT32_(0)                                          /* (PPS_RPB12G1R) RPB12/G1 Position */
#define PPS_RPB12G1R_RPB12G1R_Msk             (_UINT32_(0x1F) << PPS_RPB12G1R_RPB12G1R_Pos)        /* (PPS_RPB12G1R) RPB12/G1 Mask */
#define PPS_RPB12G1R_RPB12G1R(value)          (PPS_RPB12G1R_RPB12G1R_Msk & (_UINT32_(value) << PPS_RPB12G1R_RPB12G1R_Pos)) /* Assigment of value for RPB12G1R in the PPS_RPB12G1R register */
#define   PPS_RPB12G1R_RPB12G1R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB12G1R) OFF  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM0P3_Val   _UINT32_(0x1)                                        /* (PPS_RPB12G1R) SERCOM0/PAD3  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM0P2_Val   _UINT32_(0x2)                                        /* (PPS_RPB12G1R) SERCOM0/PAD2  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM0P1_Val   _UINT32_(0x3)                                        /* (PPS_RPB12G1R) SERCOM0/PAD1  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM1P0_Val   _UINT32_(0x4)                                        /* (PPS_RPB12G1R) SERCOM1/PAD0  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM1P2_Val   _UINT32_(0x5)                                        /* (PPS_RPB12G1R) SERCOM1/PAD2  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM1P1_Val   _UINT32_(0x6)                                        /* (PPS_RPB12G1R) SERCOM1/PAD1  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM2P0_Val   _UINT32_(0x7)                                        /* (PPS_RPB12G1R) SERCOM2/PAD0  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM2P1_Val   _UINT32_(0x8)                                        /* (PPS_RPB12G1R) SERCOM2/PAD1  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM3P0_Val   _UINT32_(0x9)                                        /* (PPS_RPB12G1R) SERCOM3/PAD0  */
#define   PPS_RPB12G1R_RPB12G1R_SCOM3P3_Val   _UINT32_(0xA)                                        /* (PPS_RPB12G1R) SERCOM3/PAD3  */
#define   PPS_RPB12G1R_RPB12G1R_TCC0WO0_Val   _UINT32_(0xB)                                        /* (PPS_RPB12G1R) TCC0/WO0  */
#define   PPS_RPB12G1R_RPB12G1R_TCC0WO4_Val   _UINT32_(0xC)                                        /* (PPS_RPB12G1R) TCC0/WO4  */
#define   PPS_RPB12G1R_RPB12G1R_TCC0WO2_Val   _UINT32_(0xD)                                        /* (PPS_RPB12G1R) TCC0/WO2  */
#define   PPS_RPB12G1R_RPB12G1R_TCC1WO0_Val   _UINT32_(0xE)                                        /* (PPS_RPB12G1R) TCC1/WO0  */
#define   PPS_RPB12G1R_RPB12G1R_TCC1WO4_Val   _UINT32_(0xF)                                        /* (PPS_RPB12G1R) TCC1/WO4  */
#define   PPS_RPB12G1R_RPB12G1R_TCC1WO2_Val   _UINT32_(0x10)                                       /* (PPS_RPB12G1R) TCC1/WO2  */
#define   PPS_RPB12G1R_RPB12G1R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPB12G1R) TCC2/WO0  */
#define   PPS_RPB12G1R_RPB12G1R_TC0WO1_Val    _UINT32_(0x12)                                       /* (PPS_RPB12G1R) TC0/WO1  */
#define   PPS_RPB12G1R_RPB12G1R_REFO1_Val     _UINT32_(0x13)                                       /* (PPS_RPB12G1R) REFO1  */
#define   PPS_RPB12G1R_RPB12G1R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPB12G1R) TC1/WO0  */
#define   PPS_RPB12G1R_RPB12G1R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPB12G1R) TC2/WO0  */
#define   PPS_RPB12G1R_RPB12G1R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPB12G1R) TC3/WO0  */
#define   PPS_RPB12G1R_RPB12G1R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB12G1R) QSCK  */
#define   PPS_RPB12G1R_RPB12G1R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB12G1R) QCS  */
#define   PPS_RPB12G1R_RPB12G1R_QD3_Val       _UINT32_(0x19)                                       /* (PPS_RPB12G1R) QD3  */
#define   PPS_RPB12G1R_RPB12G1R_QD2_Val       _UINT32_(0x1A)                                       /* (PPS_RPB12G1R) QD2  */
#define   PPS_RPB12G1R_RPB12G1R_QD1_Val       _UINT32_(0x1B)                                       /* (PPS_RPB12G1R) QD1  */
#define   PPS_RPB12G1R_RPB12G1R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPB12G1R) CCLOUT0  */
#define   PPS_RPB12G1R_RPB12G1R_TSTBUS0_Val   _UINT32_(0x1D)                                       /* (PPS_RPB12G1R) TSTBUS0  */
#define   PPS_RPB12G1R_RPB12G1R_TSTBUS4_Val   _UINT32_(0x1E)                                       /* (PPS_RPB12G1R) TSTBUS4  */
#define   PPS_RPB12G1R_RPB12G1R_TSTBUS8_Val   _UINT32_(0x1F)                                       /* (PPS_RPB12G1R) TSTBUS8  */
#define PPS_RPB12G1R_RPB12G1R_OFF             (PPS_RPB12G1R_RPB12G1R_OFF_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) OFF Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM0P3         (PPS_RPB12G1R_RPB12G1R_SCOM0P3_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM0/PAD3 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM0P2         (PPS_RPB12G1R_RPB12G1R_SCOM0P2_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM0/PAD2 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM0P1         (PPS_RPB12G1R_RPB12G1R_SCOM0P1_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM0/PAD1 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM1P0         (PPS_RPB12G1R_RPB12G1R_SCOM1P0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM1/PAD0 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM1P2         (PPS_RPB12G1R_RPB12G1R_SCOM1P2_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM1/PAD2 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM1P1         (PPS_RPB12G1R_RPB12G1R_SCOM1P1_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM1/PAD1 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM2P0         (PPS_RPB12G1R_RPB12G1R_SCOM2P0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM2/PAD0 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM2P1         (PPS_RPB12G1R_RPB12G1R_SCOM2P1_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM2/PAD1 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM3P0         (PPS_RPB12G1R_RPB12G1R_SCOM3P0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM3/PAD0 Position  */
#define PPS_RPB12G1R_RPB12G1R_SCOM3P3         (PPS_RPB12G1R_RPB12G1R_SCOM3P3_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) SERCOM3/PAD3 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC0WO0         (PPS_RPB12G1R_RPB12G1R_TCC0WO0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC0/WO0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC0WO4         (PPS_RPB12G1R_RPB12G1R_TCC0WO4_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC0/WO4 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC0WO2         (PPS_RPB12G1R_RPB12G1R_TCC0WO2_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC0/WO2 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC1WO0         (PPS_RPB12G1R_RPB12G1R_TCC1WO0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC1/WO0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC1WO4         (PPS_RPB12G1R_RPB12G1R_TCC1WO4_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC1/WO4 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC1WO2         (PPS_RPB12G1R_RPB12G1R_TCC1WO2_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC1/WO2 Position  */
#define PPS_RPB12G1R_RPB12G1R_TCC2WO0         (PPS_RPB12G1R_RPB12G1R_TCC2WO0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TCC2/WO0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TC0WO1          (PPS_RPB12G1R_RPB12G1R_TC0WO1_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TC0/WO1 Position  */
#define PPS_RPB12G1R_RPB12G1R_REFO1           (PPS_RPB12G1R_RPB12G1R_REFO1_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) REFO1 Position  */
#define PPS_RPB12G1R_RPB12G1R_TC1WO0          (PPS_RPB12G1R_RPB12G1R_TC1WO0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TC1/WO0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TC2WO0          (PPS_RPB12G1R_RPB12G1R_TC2WO0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TC2/WO0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TC3WO0          (PPS_RPB12G1R_RPB12G1R_TC3WO0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TC3/WO0 Position  */
#define PPS_RPB12G1R_RPB12G1R_QSCK            (PPS_RPB12G1R_RPB12G1R_QSCK_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) QSCK Position  */
#define PPS_RPB12G1R_RPB12G1R_QCS             (PPS_RPB12G1R_RPB12G1R_QCS_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) QCS Position  */
#define PPS_RPB12G1R_RPB12G1R_QD3             (PPS_RPB12G1R_RPB12G1R_QD3_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) QD3 Position  */
#define PPS_RPB12G1R_RPB12G1R_QD2             (PPS_RPB12G1R_RPB12G1R_QD2_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) QD2 Position  */
#define PPS_RPB12G1R_RPB12G1R_QD1             (PPS_RPB12G1R_RPB12G1R_QD1_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) QD1 Position  */
#define PPS_RPB12G1R_RPB12G1R_CCLOUT0         (PPS_RPB12G1R_RPB12G1R_CCLOUT0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) CCLOUT0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TSTBUS0         (PPS_RPB12G1R_RPB12G1R_TSTBUS0_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TSTBUS0 Position  */
#define PPS_RPB12G1R_RPB12G1R_TSTBUS4         (PPS_RPB12G1R_RPB12G1R_TSTBUS4_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TSTBUS4 Position  */
#define PPS_RPB12G1R_RPB12G1R_TSTBUS8         (PPS_RPB12G1R_RPB12G1R_TSTBUS8_Val << PPS_RPB12G1R_RPB12G1R_Pos) /* (PPS_RPB12G1R) TSTBUS8 Position  */
#define PPS_RPB12G1R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB12G1R) Register Mask  */


/* -------- PPS_RPB12G2R : (PPS Offset: 0x2F0) (R/W 32)  -------- */
#define PPS_RPB12G2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB12G2R)   Reset Value */

#define PPS_RPB12G2R_RPB12G2R_Pos             _UINT32_(0)                                          /* (PPS_RPB12G2R) RPB12/G2 Position */
#define PPS_RPB12G2R_RPB12G2R_Msk             (_UINT32_(0x1F) << PPS_RPB12G2R_RPB12G2R_Pos)        /* (PPS_RPB12G2R) RPB12/G2 Mask */
#define PPS_RPB12G2R_RPB12G2R(value)          (PPS_RPB12G2R_RPB12G2R_Msk & (_UINT32_(value) << PPS_RPB12G2R_RPB12G2R_Pos)) /* Assigment of value for RPB12G2R in the PPS_RPB12G2R register */
#define   PPS_RPB12G2R_RPB12G2R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB12G2R) OFF  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM0P0_Val   _UINT32_(0x1)                                        /* (PPS_RPB12G2R) SERCOM0/PAD0  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM0P3_Val   _UINT32_(0x2)                                        /* (PPS_RPB12G2R) SERCOM0/PAD3  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM0P2_Val   _UINT32_(0x3)                                        /* (PPS_RPB12G2R) SERCOM0/PAD2  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM1P1_Val   _UINT32_(0x4)                                        /* (PPS_RPB12G2R) SERCOM1/PAD1  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM1P3_Val   _UINT32_(0x5)                                        /* (PPS_RPB12G2R) SERCOM1/PAD3  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM1P2_Val   _UINT32_(0x6)                                        /* (PPS_RPB12G2R) SERCOM1/PAD2  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM2P1_Val   _UINT32_(0x7)                                        /* (PPS_RPB12G2R) SERCOM2/PAD1  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM2P2_Val   _UINT32_(0x8)                                        /* (PPS_RPB12G2R) SERCOM2/PAD2  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM3P1_Val   _UINT32_(0x9)                                        /* (PPS_RPB12G2R) SERCOM3/PAD1  */
#define   PPS_RPB12G2R_RPB12G2R_SCOM3P0_Val   _UINT32_(0xA)                                        /* (PPS_RPB12G2R) SERCOM3/PAD0  */
#define   PPS_RPB12G2R_RPB12G2R_TCC0WO1_Val   _UINT32_(0xB)                                        /* (PPS_RPB12G2R) TCC0/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_TCC0WO5_Val   _UINT32_(0xC)                                        /* (PPS_RPB12G2R) TCC0/WO5  */
#define   PPS_RPB12G2R_RPB12G2R_TCC0WO3_Val   _UINT32_(0xD)                                        /* (PPS_RPB12G2R) TCC0/WO3  */
#define   PPS_RPB12G2R_RPB12G2R_TCC1WO1_Val   _UINT32_(0xE)                                        /* (PPS_RPB12G2R) TCC1/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_TCC1WO5_Val   _UINT32_(0xF)                                        /* (PPS_RPB12G2R) TCC1/WO5  */
#define   PPS_RPB12G2R_RPB12G2R_TCC1WO3_Val   _UINT32_(0x10)                                       /* (PPS_RPB12G2R) TCC1/WO3  */
#define   PPS_RPB12G2R_RPB12G2R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPB12G2R) TCC2/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_TC0WO1_Val    _UINT32_(0x12)                                       /* (PPS_RPB12G2R) TC0/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_REFO2_Val     _UINT32_(0x13)                                       /* (PPS_RPB12G2R) REFO2  */
#define   PPS_RPB12G2R_RPB12G2R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPB12G2R) TC1/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPB12G2R) TC2/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPB12G2R) TC3/WO1  */
#define   PPS_RPB12G2R_RPB12G2R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB12G2R) QSCK  */
#define   PPS_RPB12G2R_RPB12G2R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB12G2R) QCS  */
#define   PPS_RPB12G2R_RPB12G2R_QD0_Val       _UINT32_(0x19)                                       /* (PPS_RPB12G2R) QD0  */
#define   PPS_RPB12G2R_RPB12G2R_QD3_Val       _UINT32_(0x1A)                                       /* (PPS_RPB12G2R) QD3  */
#define   PPS_RPB12G2R_RPB12G2R_QD2_Val       _UINT32_(0x1B)                                       /* (PPS_RPB12G2R) QD2  */
#define   PPS_RPB12G2R_RPB12G2R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPB12G2R) CCLOUT1  */
#define   PPS_RPB12G2R_RPB12G2R_TSTBUS1_Val   _UINT32_(0x1D)                                       /* (PPS_RPB12G2R) TSTBUS1  */
#define   PPS_RPB12G2R_RPB12G2R_TSTBUS5_Val   _UINT32_(0x1E)                                       /* (PPS_RPB12G2R) TSTBUS5  */
#define   PPS_RPB12G2R_RPB12G2R_TSTBUS9_Val   _UINT32_(0x1F)                                       /* (PPS_RPB12G2R) TSTBUS9  */
#define PPS_RPB12G2R_RPB12G2R_OFF             (PPS_RPB12G2R_RPB12G2R_OFF_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) OFF Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM0P0         (PPS_RPB12G2R_RPB12G2R_SCOM0P0_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM0P3         (PPS_RPB12G2R_RPB12G2R_SCOM0P3_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM0P2         (PPS_RPB12G2R_RPB12G2R_SCOM0P2_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM1P1         (PPS_RPB12G2R_RPB12G2R_SCOM1P1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM1P3         (PPS_RPB12G2R_RPB12G2R_SCOM1P3_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM1P2         (PPS_RPB12G2R_RPB12G2R_SCOM1P2_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM2P1         (PPS_RPB12G2R_RPB12G2R_SCOM2P1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM2P2         (PPS_RPB12G2R_RPB12G2R_SCOM2P2_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM3P1         (PPS_RPB12G2R_RPB12G2R_SCOM3P1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB12G2R_RPB12G2R_SCOM3P0         (PPS_RPB12G2R_RPB12G2R_SCOM3P0_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC0WO1         (PPS_RPB12G2R_RPB12G2R_TCC0WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC0/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC0WO5         (PPS_RPB12G2R_RPB12G2R_TCC0WO5_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC0/WO5 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC0WO3         (PPS_RPB12G2R_RPB12G2R_TCC0WO3_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC0/WO3 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC1WO1         (PPS_RPB12G2R_RPB12G2R_TCC1WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC1/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC1WO5         (PPS_RPB12G2R_RPB12G2R_TCC1WO5_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC1/WO5 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC1WO3         (PPS_RPB12G2R_RPB12G2R_TCC1WO3_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC1/WO3 Position  */
#define PPS_RPB12G2R_RPB12G2R_TCC2WO1         (PPS_RPB12G2R_RPB12G2R_TCC2WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TCC2/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TC0WO1          (PPS_RPB12G2R_RPB12G2R_TC0WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TC0/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_REFO2           (PPS_RPB12G2R_RPB12G2R_REFO2_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) REFO2 Position  */
#define PPS_RPB12G2R_RPB12G2R_TC1WO1          (PPS_RPB12G2R_RPB12G2R_TC1WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TC1/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TC2WO1          (PPS_RPB12G2R_RPB12G2R_TC2WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TC2/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TC3WO1          (PPS_RPB12G2R_RPB12G2R_TC3WO1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TC3/WO1 Position  */
#define PPS_RPB12G2R_RPB12G2R_QSCK            (PPS_RPB12G2R_RPB12G2R_QSCK_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) QSCK Position  */
#define PPS_RPB12G2R_RPB12G2R_QCS             (PPS_RPB12G2R_RPB12G2R_QCS_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) QCS Position  */
#define PPS_RPB12G2R_RPB12G2R_QD0             (PPS_RPB12G2R_RPB12G2R_QD0_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) QD0 Position  */
#define PPS_RPB12G2R_RPB12G2R_QD3             (PPS_RPB12G2R_RPB12G2R_QD3_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) QD3 Position  */
#define PPS_RPB12G2R_RPB12G2R_QD2             (PPS_RPB12G2R_RPB12G2R_QD2_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) QD2 Position  */
#define PPS_RPB12G2R_RPB12G2R_CCLOUT1         (PPS_RPB12G2R_RPB12G2R_CCLOUT1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) CCLOUT1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TSTBUS1         (PPS_RPB12G2R_RPB12G2R_TSTBUS1_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TSTBUS1 Position  */
#define PPS_RPB12G2R_RPB12G2R_TSTBUS5         (PPS_RPB12G2R_RPB12G2R_TSTBUS5_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TSTBUS5 Position  */
#define PPS_RPB12G2R_RPB12G2R_TSTBUS9         (PPS_RPB12G2R_RPB12G2R_TSTBUS9_Val << PPS_RPB12G2R_RPB12G2R_Pos) /* (PPS_RPB12G2R) TSTBUS9 Position  */
#define PPS_RPB12G2R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB12G2R) Register Mask  */


/* -------- PPS_RPB13G2R : (PPS Offset: 0x2F4) (R/W 32)  -------- */
#define PPS_RPB13G2R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB13G2R)   Reset Value */

#define PPS_RPB13G2R_RPB13G2R_Pos             _UINT32_(0)                                          /* (PPS_RPB13G2R) RPB13/G2 Position */
#define PPS_RPB13G2R_RPB13G2R_Msk             (_UINT32_(0x1F) << PPS_RPB13G2R_RPB13G2R_Pos)        /* (PPS_RPB13G2R) RPB13/G2 Mask */
#define PPS_RPB13G2R_RPB13G2R(value)          (PPS_RPB13G2R_RPB13G2R_Msk & (_UINT32_(value) << PPS_RPB13G2R_RPB13G2R_Pos)) /* Assigment of value for RPB13G2R in the PPS_RPB13G2R register */
#define   PPS_RPB13G2R_RPB13G2R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB13G2R) OFF  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM0P0_Val   _UINT32_(0x1)                                        /* (PPS_RPB13G2R) SERCOM0/PAD0  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM0P3_Val   _UINT32_(0x2)                                        /* (PPS_RPB13G2R) SERCOM0/PAD3  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM0P2_Val   _UINT32_(0x3)                                        /* (PPS_RPB13G2R) SERCOM0/PAD2  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM1P1_Val   _UINT32_(0x4)                                        /* (PPS_RPB13G2R) SERCOM1/PAD1  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM1P3_Val   _UINT32_(0x5)                                        /* (PPS_RPB13G2R) SERCOM1/PAD3  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM1P2_Val   _UINT32_(0x6)                                        /* (PPS_RPB13G2R) SERCOM1/PAD2  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM2P1_Val   _UINT32_(0x7)                                        /* (PPS_RPB13G2R) SERCOM2/PAD1  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM2P2_Val   _UINT32_(0x8)                                        /* (PPS_RPB13G2R) SERCOM2/PAD2  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM3P1_Val   _UINT32_(0x9)                                        /* (PPS_RPB13G2R) SERCOM3/PAD1  */
#define   PPS_RPB13G2R_RPB13G2R_SCOM3P0_Val   _UINT32_(0xA)                                        /* (PPS_RPB13G2R) SERCOM3/PAD0  */
#define   PPS_RPB13G2R_RPB13G2R_TCC0WO1_Val   _UINT32_(0xB)                                        /* (PPS_RPB13G2R) TCC0/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_TCC0WO5_Val   _UINT32_(0xC)                                        /* (PPS_RPB13G2R) TCC0/WO5  */
#define   PPS_RPB13G2R_RPB13G2R_TCC0WO3_Val   _UINT32_(0xD)                                        /* (PPS_RPB13G2R) TCC0/WO3  */
#define   PPS_RPB13G2R_RPB13G2R_TCC1WO1_Val   _UINT32_(0xE)                                        /* (PPS_RPB13G2R) TCC1/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_TCC1WO5_Val   _UINT32_(0xF)                                        /* (PPS_RPB13G2R) TCC1/WO5  */
#define   PPS_RPB13G2R_RPB13G2R_TCC1WO3_Val   _UINT32_(0x10)                                       /* (PPS_RPB13G2R) TCC1/WO3  */
#define   PPS_RPB13G2R_RPB13G2R_TCC2WO1_Val   _UINT32_(0x11)                                       /* (PPS_RPB13G2R) TCC2/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_TC0WO1_Val    _UINT32_(0x12)                                       /* (PPS_RPB13G2R) TC0/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_REFO2_Val     _UINT32_(0x13)                                       /* (PPS_RPB13G2R) REFO2  */
#define   PPS_RPB13G2R_RPB13G2R_TC1WO1_Val    _UINT32_(0x14)                                       /* (PPS_RPB13G2R) TC1/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_TC2WO1_Val    _UINT32_(0x15)                                       /* (PPS_RPB13G2R) TC2/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_TC3WO1_Val    _UINT32_(0x16)                                       /* (PPS_RPB13G2R) TC3/WO1  */
#define   PPS_RPB13G2R_RPB13G2R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB13G2R) QSCK  */
#define   PPS_RPB13G2R_RPB13G2R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB13G2R) QCS  */
#define   PPS_RPB13G2R_RPB13G2R_QD0_Val       _UINT32_(0x19)                                       /* (PPS_RPB13G2R) QD0  */
#define   PPS_RPB13G2R_RPB13G2R_QD3_Val       _UINT32_(0x1A)                                       /* (PPS_RPB13G2R) QD3  */
#define   PPS_RPB13G2R_RPB13G2R_QD2_Val       _UINT32_(0x1B)                                       /* (PPS_RPB13G2R) QD2  */
#define   PPS_RPB13G2R_RPB13G2R_CCLOUT1_Val   _UINT32_(0x1C)                                       /* (PPS_RPB13G2R) CCLOUT1  */
#define   PPS_RPB13G2R_RPB13G2R_TSTBUS1_Val   _UINT32_(0x1D)                                       /* (PPS_RPB13G2R) TSTBUS1  */
#define   PPS_RPB13G2R_RPB13G2R_TSTBUS5_Val   _UINT32_(0x1E)                                       /* (PPS_RPB13G2R) TSTBUS5  */
#define   PPS_RPB13G2R_RPB13G2R_TSTBUS9_Val   _UINT32_(0x1F)                                       /* (PPS_RPB13G2R) TSTBUS9  */
#define PPS_RPB13G2R_RPB13G2R_OFF             (PPS_RPB13G2R_RPB13G2R_OFF_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) OFF Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM0P0         (PPS_RPB13G2R_RPB13G2R_SCOM0P0_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM0/PAD0 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM0P3         (PPS_RPB13G2R_RPB13G2R_SCOM0P3_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM0/PAD3 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM0P2         (PPS_RPB13G2R_RPB13G2R_SCOM0P2_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM0/PAD2 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM1P1         (PPS_RPB13G2R_RPB13G2R_SCOM1P1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM1/PAD1 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM1P3         (PPS_RPB13G2R_RPB13G2R_SCOM1P3_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM1/PAD3 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM1P2         (PPS_RPB13G2R_RPB13G2R_SCOM1P2_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM1/PAD2 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM2P1         (PPS_RPB13G2R_RPB13G2R_SCOM2P1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM2/PAD1 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM2P2         (PPS_RPB13G2R_RPB13G2R_SCOM2P2_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM2/PAD2 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM3P1         (PPS_RPB13G2R_RPB13G2R_SCOM3P1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM3/PAD1 Position  */
#define PPS_RPB13G2R_RPB13G2R_SCOM3P0         (PPS_RPB13G2R_RPB13G2R_SCOM3P0_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) SERCOM3/PAD0 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC0WO1         (PPS_RPB13G2R_RPB13G2R_TCC0WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC0/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC0WO5         (PPS_RPB13G2R_RPB13G2R_TCC0WO5_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC0/WO5 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC0WO3         (PPS_RPB13G2R_RPB13G2R_TCC0WO3_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC0/WO3 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC1WO1         (PPS_RPB13G2R_RPB13G2R_TCC1WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC1/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC1WO5         (PPS_RPB13G2R_RPB13G2R_TCC1WO5_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC1/WO5 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC1WO3         (PPS_RPB13G2R_RPB13G2R_TCC1WO3_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC1/WO3 Position  */
#define PPS_RPB13G2R_RPB13G2R_TCC2WO1         (PPS_RPB13G2R_RPB13G2R_TCC2WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TCC2/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TC0WO1          (PPS_RPB13G2R_RPB13G2R_TC0WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TC0/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_REFO2           (PPS_RPB13G2R_RPB13G2R_REFO2_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) REFO2 Position  */
#define PPS_RPB13G2R_RPB13G2R_TC1WO1          (PPS_RPB13G2R_RPB13G2R_TC1WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TC1/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TC2WO1          (PPS_RPB13G2R_RPB13G2R_TC2WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TC2/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TC3WO1          (PPS_RPB13G2R_RPB13G2R_TC3WO1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TC3/WO1 Position  */
#define PPS_RPB13G2R_RPB13G2R_QSCK            (PPS_RPB13G2R_RPB13G2R_QSCK_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) QSCK Position  */
#define PPS_RPB13G2R_RPB13G2R_QCS             (PPS_RPB13G2R_RPB13G2R_QCS_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) QCS Position  */
#define PPS_RPB13G2R_RPB13G2R_QD0             (PPS_RPB13G2R_RPB13G2R_QD0_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) QD0 Position  */
#define PPS_RPB13G2R_RPB13G2R_QD3             (PPS_RPB13G2R_RPB13G2R_QD3_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) QD3 Position  */
#define PPS_RPB13G2R_RPB13G2R_QD2             (PPS_RPB13G2R_RPB13G2R_QD2_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) QD2 Position  */
#define PPS_RPB13G2R_RPB13G2R_CCLOUT1         (PPS_RPB13G2R_RPB13G2R_CCLOUT1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) CCLOUT1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TSTBUS1         (PPS_RPB13G2R_RPB13G2R_TSTBUS1_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TSTBUS1 Position  */
#define PPS_RPB13G2R_RPB13G2R_TSTBUS5         (PPS_RPB13G2R_RPB13G2R_TSTBUS5_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TSTBUS5 Position  */
#define PPS_RPB13G2R_RPB13G2R_TSTBUS9         (PPS_RPB13G2R_RPB13G2R_TSTBUS9_Val << PPS_RPB13G2R_RPB13G2R_Pos) /* (PPS_RPB13G2R) TSTBUS9 Position  */
#define PPS_RPB13G2R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB13G2R) Register Mask  */


/* -------- PPS_RPB13G3R : (PPS Offset: 0x2F8) (R/W 32)  -------- */
#define PPS_RPB13G3R_RESETVALUE               _UINT32_(0x00)                                       /*  (PPS_RPB13G3R)   Reset Value */

#define PPS_RPB13G3R_RPB13G3R_Pos             _UINT32_(0)                                          /* (PPS_RPB13G3R) RPB13/G3 Position */
#define PPS_RPB13G3R_RPB13G3R_Msk             (_UINT32_(0x1F) << PPS_RPB13G3R_RPB13G3R_Pos)        /* (PPS_RPB13G3R) RPB13/G3 Mask */
#define PPS_RPB13G3R_RPB13G3R(value)          (PPS_RPB13G3R_RPB13G3R_Msk & (_UINT32_(value) << PPS_RPB13G3R_RPB13G3R_Pos)) /* Assigment of value for RPB13G3R in the PPS_RPB13G3R register */
#define   PPS_RPB13G3R_RPB13G3R_OFF_Val       _UINT32_(0x0)                                        /* (PPS_RPB13G3R) OFF  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM0P1_Val   _UINT32_(0x1)                                        /* (PPS_RPB13G3R) SERCOM0/PAD1  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM0P0_Val   _UINT32_(0x2)                                        /* (PPS_RPB13G3R) SERCOM0/PAD0  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM0P3_Val   _UINT32_(0x3)                                        /* (PPS_RPB13G3R) SERCOM0/PAD3  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM1P2_Val   _UINT32_(0x4)                                        /* (PPS_RPB13G3R) SERCOM1/PAD2  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM1P0_Val   _UINT32_(0x5)                                        /* (PPS_RPB13G3R) SERCOM1/PAD0  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM1P3_Val   _UINT32_(0x6)                                        /* (PPS_RPB13G3R) SERCOM1/PAD3  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM2P2_Val   _UINT32_(0x7)                                        /* (PPS_RPB13G3R) SERCOM2/PAD2  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM2P3_Val   _UINT32_(0x8)                                        /* (PPS_RPB13G3R) SERCOM2/PAD3  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM3P2_Val   _UINT32_(0x9)                                        /* (PPS_RPB13G3R) SERCOM3/PAD2  */
#define   PPS_RPB13G3R_RPB13G3R_SCOM3P1_Val   _UINT32_(0xA)                                        /* (PPS_RPB13G3R) SERCOM3/PAD1  */
#define   PPS_RPB13G3R_RPB13G3R_TCC0WO2_Val   _UINT32_(0xB)                                        /* (PPS_RPB13G3R) TCC0/WO2  */
#define   PPS_RPB13G3R_RPB13G3R_TCC0WO0_Val   _UINT32_(0xC)                                        /* (PPS_RPB13G3R) TCC0/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_TCC0WO4_Val   _UINT32_(0xD)                                        /* (PPS_RPB13G3R) TCC0/WO4  */
#define   PPS_RPB13G3R_RPB13G3R_TCC1WO2_Val   _UINT32_(0xE)                                        /* (PPS_RPB13G3R) TCC1/WO2  */
#define   PPS_RPB13G3R_RPB13G3R_TCC1WO0_Val   _UINT32_(0xF)                                        /* (PPS_RPB13G3R) TCC1/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_TCC1WO4_Val   _UINT32_(0x10)                                       /* (PPS_RPB13G3R) TCC1/WO4  */
#define   PPS_RPB13G3R_RPB13G3R_TCC2WO0_Val   _UINT32_(0x11)                                       /* (PPS_RPB13G3R) TCC2/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_TC0WO0_Val    _UINT32_(0x12)                                       /* (PPS_RPB13G3R) TC0/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_REFO3_Val     _UINT32_(0x13)                                       /* (PPS_RPB13G3R) REFO3  */
#define   PPS_RPB13G3R_RPB13G3R_TC1WO0_Val    _UINT32_(0x14)                                       /* (PPS_RPB13G3R) TC1/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_TC2WO0_Val    _UINT32_(0x15)                                       /* (PPS_RPB13G3R) TC2/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_TC3WO0_Val    _UINT32_(0x16)                                       /* (PPS_RPB13G3R) TC3/WO0  */
#define   PPS_RPB13G3R_RPB13G3R_QSCK_Val      _UINT32_(0x17)                                       /* (PPS_RPB13G3R) QSCK  */
#define   PPS_RPB13G3R_RPB13G3R_QCS_Val       _UINT32_(0x18)                                       /* (PPS_RPB13G3R) QCS  */
#define   PPS_RPB13G3R_RPB13G3R_QD1_Val       _UINT32_(0x19)                                       /* (PPS_RPB13G3R) QD1  */
#define   PPS_RPB13G3R_RPB13G3R_QD0_Val       _UINT32_(0x1A)                                       /* (PPS_RPB13G3R) QD0  */
#define   PPS_RPB13G3R_RPB13G3R_QD3_Val       _UINT32_(0x1B)                                       /* (PPS_RPB13G3R) QD3  */
#define   PPS_RPB13G3R_RPB13G3R_CCLOUT0_Val   _UINT32_(0x1C)                                       /* (PPS_RPB13G3R) CCLOUT0  */
#define   PPS_RPB13G3R_RPB13G3R_TSTBUS2_Val   _UINT32_(0x1D)                                       /* (PPS_RPB13G3R) TSTBUS2  */
#define   PPS_RPB13G3R_RPB13G3R_TSTBUS6_Val   _UINT32_(0x1E)                                       /* (PPS_RPB13G3R) TSTBUS6  */
#define   PPS_RPB13G3R_RPB13G3R_TSTBUS10_Val  _UINT32_(0x1F)                                       /* (PPS_RPB13G3R) TSTBUS10  */
#define PPS_RPB13G3R_RPB13G3R_OFF             (PPS_RPB13G3R_RPB13G3R_OFF_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) OFF Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM0P1         (PPS_RPB13G3R_RPB13G3R_SCOM0P1_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM0/PAD1 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM0P0         (PPS_RPB13G3R_RPB13G3R_SCOM0P0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM0/PAD0 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM0P3         (PPS_RPB13G3R_RPB13G3R_SCOM0P3_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM0/PAD3 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM1P2         (PPS_RPB13G3R_RPB13G3R_SCOM1P2_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM1/PAD2 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM1P0         (PPS_RPB13G3R_RPB13G3R_SCOM1P0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM1/PAD0 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM1P3         (PPS_RPB13G3R_RPB13G3R_SCOM1P3_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM1/PAD3 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM2P2         (PPS_RPB13G3R_RPB13G3R_SCOM2P2_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM2/PAD2 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM2P3         (PPS_RPB13G3R_RPB13G3R_SCOM2P3_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM2/PAD3 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM3P2         (PPS_RPB13G3R_RPB13G3R_SCOM3P2_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM3/PAD2 Position  */
#define PPS_RPB13G3R_RPB13G3R_SCOM3P1         (PPS_RPB13G3R_RPB13G3R_SCOM3P1_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) SERCOM3/PAD1 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC0WO2         (PPS_RPB13G3R_RPB13G3R_TCC0WO2_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC0/WO2 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC0WO0         (PPS_RPB13G3R_RPB13G3R_TCC0WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC0/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC0WO4         (PPS_RPB13G3R_RPB13G3R_TCC0WO4_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC0/WO4 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC1WO2         (PPS_RPB13G3R_RPB13G3R_TCC1WO2_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC1/WO2 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC1WO0         (PPS_RPB13G3R_RPB13G3R_TCC1WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC1/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC1WO4         (PPS_RPB13G3R_RPB13G3R_TCC1WO4_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC1/WO4 Position  */
#define PPS_RPB13G3R_RPB13G3R_TCC2WO0         (PPS_RPB13G3R_RPB13G3R_TCC2WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TCC2/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_TC0WO0          (PPS_RPB13G3R_RPB13G3R_TC0WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TC0/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_REFO3           (PPS_RPB13G3R_RPB13G3R_REFO3_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) REFO3 Position  */
#define PPS_RPB13G3R_RPB13G3R_TC1WO0          (PPS_RPB13G3R_RPB13G3R_TC1WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TC1/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_TC2WO0          (PPS_RPB13G3R_RPB13G3R_TC2WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TC2/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_TC3WO0          (PPS_RPB13G3R_RPB13G3R_TC3WO0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TC3/WO0 Position  */
#define PPS_RPB13G3R_RPB13G3R_QSCK            (PPS_RPB13G3R_RPB13G3R_QSCK_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) QSCK Position  */
#define PPS_RPB13G3R_RPB13G3R_QCS             (PPS_RPB13G3R_RPB13G3R_QCS_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) QCS Position  */
#define PPS_RPB13G3R_RPB13G3R_QD1             (PPS_RPB13G3R_RPB13G3R_QD1_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) QD1 Position  */
#define PPS_RPB13G3R_RPB13G3R_QD0             (PPS_RPB13G3R_RPB13G3R_QD0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) QD0 Position  */
#define PPS_RPB13G3R_RPB13G3R_QD3             (PPS_RPB13G3R_RPB13G3R_QD3_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) QD3 Position  */
#define PPS_RPB13G3R_RPB13G3R_CCLOUT0         (PPS_RPB13G3R_RPB13G3R_CCLOUT0_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) CCLOUT0 Position  */
#define PPS_RPB13G3R_RPB13G3R_TSTBUS2         (PPS_RPB13G3R_RPB13G3R_TSTBUS2_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TSTBUS2 Position  */
#define PPS_RPB13G3R_RPB13G3R_TSTBUS6         (PPS_RPB13G3R_RPB13G3R_TSTBUS6_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TSTBUS6 Position  */
#define PPS_RPB13G3R_RPB13G3R_TSTBUS10        (PPS_RPB13G3R_RPB13G3R_TSTBUS10_Val << PPS_RPB13G3R_RPB13G3R_Pos) /* (PPS_RPB13G3R) TSTBUS10 Position  */
#define PPS_RPB13G3R_Msk                      _UINT32_(0x0000001F)                                 /* (PPS_RPB13G3R) Register Mask  */


/** \brief PPS register offsets definitions */
#define PPS_EXTINT0R_REG_OFST          _UINT32_(0x00)      /* (PPS_EXTINT0R)  Offset */
#define PPS_EXTINT1R_REG_OFST          _UINT32_(0x04)      /* (PPS_EXTINT1R)  Offset */
#define PPS_EXTINT2R_REG_OFST          _UINT32_(0x08)      /* (PPS_EXTINT2R)  Offset */
#define PPS_EXTINT3R_REG_OFST          _UINT32_(0x0C)      /* (PPS_EXTINT3R)  Offset */
#define PPS_NMIR_REG_OFST              _UINT32_(0x3C)      /* (PPS_NMIR)  Offset */
#define PPS_SCOM0P0R_REG_OFST          _UINT32_(0x40)      /* (PPS_SCOM0P0R)  Offset */
#define PPS_SCOM0P1R_REG_OFST          _UINT32_(0x44)      /* (PPS_SCOM0P1R)  Offset */
#define PPS_SCOM0P2R_REG_OFST          _UINT32_(0x48)      /* (PPS_SCOM0P2R)  Offset */
#define PPS_SCOM0P3R_REG_OFST          _UINT32_(0x4C)      /* (PPS_SCOM0P3R)  Offset */
#define PPS_SCOM1P0R_REG_OFST          _UINT32_(0x50)      /* (PPS_SCOM1P0R)  Offset */
#define PPS_SCOM1P1R_REG_OFST          _UINT32_(0x54)      /* (PPS_SCOM1P1R)  Offset */
#define PPS_SCOM1P2R_REG_OFST          _UINT32_(0x58)      /* (PPS_SCOM1P2R)  Offset */
#define PPS_SCOM1P3R_REG_OFST          _UINT32_(0x5C)      /* (PPS_SCOM1P3R)  Offset */
#define PPS_SCOM2P0R_REG_OFST          _UINT32_(0x60)      /* (PPS_SCOM2P0R)  Offset */
#define PPS_SCOM2P1R_REG_OFST          _UINT32_(0x64)      /* (PPS_SCOM2P1R)  Offset */
#define PPS_SCOM2P2R_REG_OFST          _UINT32_(0x68)      /* (PPS_SCOM2P2R)  Offset */
#define PPS_SCOM2P3R_REG_OFST          _UINT32_(0x6C)      /* (PPS_SCOM2P3R)  Offset */
#define PPS_SCOM3P0R_REG_OFST          _UINT32_(0x70)      /* (PPS_SCOM3P0R)  Offset */
#define PPS_SCOM3P1R_REG_OFST          _UINT32_(0x74)      /* (PPS_SCOM3P1R)  Offset */
#define PPS_SCOM3P2R_REG_OFST          _UINT32_(0x78)      /* (PPS_SCOM3P2R)  Offset */
#define PPS_SCOM3P3R_REG_OFST          _UINT32_(0x7C)      /* (PPS_SCOM3P3R)  Offset */
#define PPS_QSCKR_REG_OFST             _UINT32_(0x80)      /* (PPS_QSCKR)  Offset */
#define PPS_QD0R_REG_OFST              _UINT32_(0x84)      /* (PPS_QD0R)  Offset */
#define PPS_QD1R_REG_OFST              _UINT32_(0x88)      /* (PPS_QD1R)  Offset */
#define PPS_QD2R_REG_OFST              _UINT32_(0x8C)      /* (PPS_QD2R)  Offset */
#define PPS_QD3R_REG_OFST              _UINT32_(0x90)      /* (PPS_QD3R)  Offset */
#define PPS_REFIR_REG_OFST             _UINT32_(0x94)      /* (PPS_REFIR)  Offset */
#define PPS_CCLIN0R_REG_OFST           _UINT32_(0x98)      /* (PPS_CCLIN0R)  Offset */
#define PPS_CCLIN1R_REG_OFST           _UINT32_(0x9C)      /* (PPS_CCLIN1R)  Offset */
#define PPS_CCLIN2R_REG_OFST           _UINT32_(0xA0)      /* (PPS_CCLIN2R)  Offset */
#define PPS_CCLIN3R_REG_OFST           _UINT32_(0xA4)      /* (PPS_CCLIN3R)  Offset */
#define PPS_CCLIN4R_REG_OFST           _UINT32_(0xA8)      /* (PPS_CCLIN4R)  Offset */
#define PPS_CCLIN5R_REG_OFST           _UINT32_(0xAC)      /* (PPS_CCLIN5R)  Offset */
#define PPS_TC0WO0G1R_REG_OFST         _UINT32_(0xB0)      /* (PPS_TC0WO0G1R)  Offset */
#define PPS_TC0WO0G2R_REG_OFST         _UINT32_(0xB4)      /* (PPS_TC0WO0G2R)  Offset */
#define PPS_TC0WO1G3R_REG_OFST         _UINT32_(0xB8)      /* (PPS_TC0WO1G3R)  Offset */
#define PPS_TC0WO1G4R_REG_OFST         _UINT32_(0xBC)      /* (PPS_TC0WO1G4R)  Offset */
#define PPS_TC1WO0G1R_REG_OFST         _UINT32_(0xC0)      /* (PPS_TC1WO0G1R)  Offset */
#define PPS_TC1WO1G2R_REG_OFST         _UINT32_(0xC4)      /* (PPS_TC1WO1G2R)  Offset */
#define PPS_TC2WO0G1R_REG_OFST         _UINT32_(0xC8)      /* (PPS_TC2WO0G1R)  Offset */
#define PPS_TC2WO0G3R_REG_OFST         _UINT32_(0xCC)      /* (PPS_TC2WO0G3R)  Offset */
#define PPS_TC2WO1G2R_REG_OFST         _UINT32_(0xD0)      /* (PPS_TC2WO1G2R)  Offset */
#define PPS_TC2WO1G4R_REG_OFST         _UINT32_(0xD4)      /* (PPS_TC2WO1G4R)  Offset */
#define PPS_TC3WO0G1R_REG_OFST         _UINT32_(0xD8)      /* (PPS_TC3WO0G1R)  Offset */
#define PPS_TC3WO0G3R_REG_OFST         _UINT32_(0xDC)      /* (PPS_TC3WO0G3R)  Offset */
#define PPS_TC3WO1G2R_REG_OFST         _UINT32_(0xE0)      /* (PPS_TC3WO1G2R)  Offset */
#define PPS_TC3WO1G4R_REG_OFST         _UINT32_(0xE4)      /* (PPS_TC3WO1G4R)  Offset */
#define PPS_RPA0G2R_REG_OFST           _UINT32_(0x200)     /* (PPS_RPA0G2R)  Offset */
#define PPS_RPA0G3R_REG_OFST           _UINT32_(0x204)     /* (PPS_RPA0G3R)  Offset */
#define PPS_RPA1G3R_REG_OFST           _UINT32_(0x208)     /* (PPS_RPA1G3R)  Offset */
#define PPS_RPA1G4R_REG_OFST           _UINT32_(0x20C)     /* (PPS_RPA1G4R)  Offset */
#define PPS_RPA2G1R_REG_OFST           _UINT32_(0x210)     /* (PPS_RPA2G1R)  Offset */
#define PPS_RPA2G4R_REG_OFST           _UINT32_(0x214)     /* (PPS_RPA2G4R)  Offset */
#define PPS_RPA3G1R_REG_OFST           _UINT32_(0x218)     /* (PPS_RPA3G1R)  Offset */
#define PPS_RPA3G2R_REG_OFST           _UINT32_(0x21C)     /* (PPS_RPA3G2R)  Offset */
#define PPS_RPA3G3R_REG_OFST           _UINT32_(0x220)     /* (PPS_RPA3G3R)  Offset */
#define PPS_RPA4G2R_REG_OFST           _UINT32_(0x224)     /* (PPS_RPA4G2R)  Offset */
#define PPS_RPA4G3R_REG_OFST           _UINT32_(0x228)     /* (PPS_RPA4G3R)  Offset */
#define PPS_RPA4G4R_REG_OFST           _UINT32_(0x22C)     /* (PPS_RPA4G4R)  Offset */
#define PPS_RPA5G1R_REG_OFST           _UINT32_(0x230)     /* (PPS_RPA5G1R)  Offset */
#define PPS_RPA5G3R_REG_OFST           _UINT32_(0x234)     /* (PPS_RPA5G3R)  Offset */
#define PPS_RPA5G4R_REG_OFST           _UINT32_(0x238)     /* (PPS_RPA5G4R)  Offset */
#define PPS_RPA6G1R_REG_OFST           _UINT32_(0x23C)     /* (PPS_RPA6G1R)  Offset */
#define PPS_RPA6G2R_REG_OFST           _UINT32_(0x240)     /* (PPS_RPA6G2R)  Offset */
#define PPS_RPA6G4R_REG_OFST           _UINT32_(0x244)     /* (PPS_RPA6G4R)  Offset */
#define PPS_RPA7G1R_REG_OFST           _UINT32_(0x248)     /* (PPS_RPA7G1R)  Offset */
#define PPS_RPA7G2R_REG_OFST           _UINT32_(0x24C)     /* (PPS_RPA7G2R)  Offset */
#define PPS_RPA8G2R_REG_OFST           _UINT32_(0x250)     /* (PPS_RPA8G2R)  Offset */
#define PPS_RPA8G3R_REG_OFST           _UINT32_(0x254)     /* (PPS_RPA8G3R)  Offset */
#define PPS_RPA8G4R_REG_OFST           _UINT32_(0x258)     /* (PPS_RPA8G4R)  Offset */
#define PPS_RPA9G1R_REG_OFST           _UINT32_(0x25C)     /* (PPS_RPA9G1R)  Offset */
#define PPS_RPA9G3R_REG_OFST           _UINT32_(0x260)     /* (PPS_RPA9G3R)  Offset */
#define PPS_RPA9G4R_REG_OFST           _UINT32_(0x264)     /* (PPS_RPA9G4R)  Offset */
#define PPS_RPA10G1R_REG_OFST          _UINT32_(0x268)     /* (PPS_RPA10G1R)  Offset */
#define PPS_RPA10G4R_REG_OFST          _UINT32_(0x26C)     /* (PPS_RPA10G4R)  Offset */
#define PPS_RPA13G3R_REG_OFST          _UINT32_(0x278)     /* (PPS_RPA13G3R)  Offset */
#define PPS_RPA13G4R_REG_OFST          _UINT32_(0x27C)     /* (PPS_RPA13G4R)  Offset */
#define PPS_RPA14G1R_REG_OFST          _UINT32_(0x280)     /* (PPS_RPA14G1R)  Offset */
#define PPS_RPA14G4R_REG_OFST          _UINT32_(0x284)     /* (PPS_RPA14G4R)  Offset */
#define PPS_RPB0G1R_REG_OFST           _UINT32_(0x28C)     /* (PPS_RPB0G1R)  Offset */
#define PPS_RPB0G2R_REG_OFST           _UINT32_(0x290)     /* (PPS_RPB0G2R)  Offset */
#define PPS_RPB1G2R_REG_OFST           _UINT32_(0x294)     /* (PPS_RPB1G2R)  Offset */
#define PPS_RPB1G3R_REG_OFST           _UINT32_(0x298)     /* (PPS_RPB1G3R)  Offset */
#define PPS_RPB2G3R_REG_OFST           _UINT32_(0x29C)     /* (PPS_RPB2G3R)  Offset */
#define PPS_RPB2G4R_REG_OFST           _UINT32_(0x2A0)     /* (PPS_RPB2G4R)  Offset */
#define PPS_RPB3G1R_REG_OFST           _UINT32_(0x2A4)     /* (PPS_RPB3G1R)  Offset */
#define PPS_RPB3G4R_REG_OFST           _UINT32_(0x2A8)     /* (PPS_RPB3G4R)  Offset */
#define PPS_RPB4G1R_REG_OFST           _UINT32_(0x2AC)     /* (PPS_RPB4G1R)  Offset */
#define PPS_RPB4G2R_REG_OFST           _UINT32_(0x2B0)     /* (PPS_RPB4G2R)  Offset */
#define PPS_RPB5G2R_REG_OFST           _UINT32_(0x2B4)     /* (PPS_RPB5G2R)  Offset */
#define PPS_RPB5G3R_REG_OFST           _UINT32_(0x2B8)     /* (PPS_RPB5G3R)  Offset */
#define PPS_RPB6G3R_REG_OFST           _UINT32_(0x2BC)     /* (PPS_RPB6G3R)  Offset */
#define PPS_RPB6G4R_REG_OFST           _UINT32_(0x2C0)     /* (PPS_RPB6G4R)  Offset */
#define PPS_RPB7G1R_REG_OFST           _UINT32_(0x2C4)     /* (PPS_RPB7G1R)  Offset */
#define PPS_RPB7G4R_REG_OFST           _UINT32_(0x2C8)     /* (PPS_RPB7G4R)  Offset */
#define PPS_RPB8G1R_REG_OFST           _UINT32_(0x2CC)     /* (PPS_RPB8G1R)  Offset */
#define PPS_RPB8G2R_REG_OFST           _UINT32_(0x2D0)     /* (PPS_RPB8G2R)  Offset */
#define PPS_RPB9G2R_REG_OFST           _UINT32_(0x2D4)     /* (PPS_RPB9G2R)  Offset */
#define PPS_RPB9G3R_REG_OFST           _UINT32_(0x2D8)     /* (PPS_RPB9G3R)  Offset */
#define PPS_RPB10G3R_REG_OFST          _UINT32_(0x2DC)     /* (PPS_RPB10G3R)  Offset */
#define PPS_RPB10G4R_REG_OFST          _UINT32_(0x2E0)     /* (PPS_RPB10G4R)  Offset */
#define PPS_RPB11G1R_REG_OFST          _UINT32_(0x2E4)     /* (PPS_RPB11G1R)  Offset */
#define PPS_RPB11G4R_REG_OFST          _UINT32_(0x2E8)     /* (PPS_RPB11G4R)  Offset */
#define PPS_RPB12G1R_REG_OFST          _UINT32_(0x2EC)     /* (PPS_RPB12G1R)  Offset */
#define PPS_RPB12G2R_REG_OFST          _UINT32_(0x2F0)     /* (PPS_RPB12G2R)  Offset */
#define PPS_RPB13G2R_REG_OFST          _UINT32_(0x2F4)     /* (PPS_RPB13G2R)  Offset */
#define PPS_RPB13G3R_REG_OFST          _UINT32_(0x2F8)     /* (PPS_RPB13G3R)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief PPS register API structure */
typedef struct
{  /* 'PPS */
  __IO  uint32_t                       PPS_EXTINT0R;       /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       PPS_EXTINT1R;       /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       PPS_EXTINT2R;       /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       PPS_EXTINT3R;       /**< Offset: 0x0C (R/W  32)  */
  __I   uint8_t                        Reserved1[0x2C];
  __IO  uint32_t                       PPS_NMIR;           /**< Offset: 0x3C (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM0P0R;       /**< Offset: 0x40 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM0P1R;       /**< Offset: 0x44 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM0P2R;       /**< Offset: 0x48 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM0P3R;       /**< Offset: 0x4C (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM1P0R;       /**< Offset: 0x50 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM1P1R;       /**< Offset: 0x54 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM1P2R;       /**< Offset: 0x58 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM1P3R;       /**< Offset: 0x5C (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM2P0R;       /**< Offset: 0x60 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM2P1R;       /**< Offset: 0x64 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM2P2R;       /**< Offset: 0x68 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM2P3R;       /**< Offset: 0x6C (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM3P0R;       /**< Offset: 0x70 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM3P1R;       /**< Offset: 0x74 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM3P2R;       /**< Offset: 0x78 (R/W  32)  */
  __IO  uint32_t                       PPS_SCOM3P3R;       /**< Offset: 0x7C (R/W  32)  */
  __IO  uint32_t                       PPS_QSCKR;          /**< Offset: 0x80 (R/W  32)  */
  __IO  uint32_t                       PPS_QD0R;           /**< Offset: 0x84 (R/W  32)  */
  __IO  uint32_t                       PPS_QD1R;           /**< Offset: 0x88 (R/W  32)  */
  __IO  uint32_t                       PPS_QD2R;           /**< Offset: 0x8C (R/W  32)  */
  __IO  uint32_t                       PPS_QD3R;           /**< Offset: 0x90 (R/W  32)  */
  __IO  uint32_t                       PPS_REFIR;          /**< Offset: 0x94 (R/W  32)  */
  __IO  uint32_t                       PPS_CCLIN0R;        /**< Offset: 0x98 (R/W  32)  */
  __IO  uint32_t                       PPS_CCLIN1R;        /**< Offset: 0x9C (R/W  32)  */
  __IO  uint32_t                       PPS_CCLIN2R;        /**< Offset: 0xA0 (R/W  32)  */
  __IO  uint32_t                       PPS_CCLIN3R;        /**< Offset: 0xA4 (R/W  32)  */
  __IO  uint32_t                       PPS_CCLIN4R;        /**< Offset: 0xA8 (R/W  32)  */
  __IO  uint32_t                       PPS_CCLIN5R;        /**< Offset: 0xAC (R/W  32)  */
  __IO  uint32_t                       PPS_TC0WO0G1R;      /**< Offset: 0xB0 (R/W  32)  */
  __IO  uint32_t                       PPS_TC0WO0G2R;      /**< Offset: 0xB4 (R/W  32)  */
  __IO  uint32_t                       PPS_TC0WO1G3R;      /**< Offset: 0xB8 (R/W  32)  */
  __IO  uint32_t                       PPS_TC0WO1G4R;      /**< Offset: 0xBC (R/W  32)  */
  __IO  uint32_t                       PPS_TC1WO0G1R;      /**< Offset: 0xC0 (R/W  32)  */
  __IO  uint32_t                       PPS_TC1WO1G2R;      /**< Offset: 0xC4 (R/W  32)  */
  __IO  uint32_t                       PPS_TC2WO0G1R;      /**< Offset: 0xC8 (R/W  32)  */
  __IO  uint32_t                       PPS_TC2WO0G3R;      /**< Offset: 0xCC (R/W  32)  */
  __IO  uint32_t                       PPS_TC2WO1G2R;      /**< Offset: 0xD0 (R/W  32)  */
  __IO  uint32_t                       PPS_TC2WO1G4R;      /**< Offset: 0xD4 (R/W  32)  */
  __IO  uint32_t                       PPS_TC3WO0G1R;      /**< Offset: 0xD8 (R/W  32)  */
  __IO  uint32_t                       PPS_TC3WO0G3R;      /**< Offset: 0xDC (R/W  32)  */
  __IO  uint32_t                       PPS_TC3WO1G2R;      /**< Offset: 0xE0 (R/W  32)  */
  __IO  uint32_t                       PPS_TC3WO1G4R;      /**< Offset: 0xE4 (R/W  32)  */
  __I   uint8_t                        Reserved2[0x118];
  __IO  uint32_t                       PPS_RPA0G2R;        /**< Offset: 0x200 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA0G3R;        /**< Offset: 0x204 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA1G3R;        /**< Offset: 0x208 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA1G4R;        /**< Offset: 0x20C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA2G1R;        /**< Offset: 0x210 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA2G4R;        /**< Offset: 0x214 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA3G1R;        /**< Offset: 0x218 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA3G2R;        /**< Offset: 0x21C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA3G3R;        /**< Offset: 0x220 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA4G2R;        /**< Offset: 0x224 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA4G3R;        /**< Offset: 0x228 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA4G4R;        /**< Offset: 0x22C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA5G1R;        /**< Offset: 0x230 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA5G3R;        /**< Offset: 0x234 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA5G4R;        /**< Offset: 0x238 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA6G1R;        /**< Offset: 0x23C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA6G2R;        /**< Offset: 0x240 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA6G4R;        /**< Offset: 0x244 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA7G1R;        /**< Offset: 0x248 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA7G2R;        /**< Offset: 0x24C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA8G2R;        /**< Offset: 0x250 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA8G3R;        /**< Offset: 0x254 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA8G4R;        /**< Offset: 0x258 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA9G1R;        /**< Offset: 0x25C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA9G3R;        /**< Offset: 0x260 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA9G4R;        /**< Offset: 0x264 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA10G1R;       /**< Offset: 0x268 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA10G4R;       /**< Offset: 0x26C (R/W  32)  */
  __I   uint8_t                        Reserved3[0x08];
  __IO  uint32_t                       PPS_RPA13G3R;       /**< Offset: 0x278 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA13G4R;       /**< Offset: 0x27C (R/W  32)  */
  __IO  uint32_t                       PPS_RPA14G1R;       /**< Offset: 0x280 (R/W  32)  */
  __IO  uint32_t                       PPS_RPA14G4R;       /**< Offset: 0x284 (R/W  32)  */
  __I   uint8_t                        Reserved4[0x04];
  __IO  uint32_t                       PPS_RPB0G1R;        /**< Offset: 0x28C (R/W  32)  */
  __IO  uint32_t                       PPS_RPB0G2R;        /**< Offset: 0x290 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB1G2R;        /**< Offset: 0x294 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB1G3R;        /**< Offset: 0x298 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB2G3R;        /**< Offset: 0x29C (R/W  32)  */
  __IO  uint32_t                       PPS_RPB2G4R;        /**< Offset: 0x2A0 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB3G1R;        /**< Offset: 0x2A4 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB3G4R;        /**< Offset: 0x2A8 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB4G1R;        /**< Offset: 0x2AC (R/W  32)  */
  __IO  uint32_t                       PPS_RPB4G2R;        /**< Offset: 0x2B0 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB5G2R;        /**< Offset: 0x2B4 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB5G3R;        /**< Offset: 0x2B8 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB6G3R;        /**< Offset: 0x2BC (R/W  32)  */
  __IO  uint32_t                       PPS_RPB6G4R;        /**< Offset: 0x2C0 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB7G1R;        /**< Offset: 0x2C4 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB7G4R;        /**< Offset: 0x2C8 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB8G1R;        /**< Offset: 0x2CC (R/W  32)  */
  __IO  uint32_t                       PPS_RPB8G2R;        /**< Offset: 0x2D0 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB9G2R;        /**< Offset: 0x2D4 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB9G3R;        /**< Offset: 0x2D8 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB10G3R;       /**< Offset: 0x2DC (R/W  32)  */
  __IO  uint32_t                       PPS_RPB10G4R;       /**< Offset: 0x2E0 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB11G1R;       /**< Offset: 0x2E4 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB11G4R;       /**< Offset: 0x2E8 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB12G1R;       /**< Offset: 0x2EC (R/W  32)  */
  __IO  uint32_t                       PPS_RPB12G2R;       /**< Offset: 0x2F0 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB13G2R;       /**< Offset: 0x2F4 (R/W  32)  */
  __IO  uint32_t                       PPS_RPB13G3R;       /**< Offset: 0x2F8 (R/W  32)  */
} pps_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_PPS_COMPONENT_H_ */
