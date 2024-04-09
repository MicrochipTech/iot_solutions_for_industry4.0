/*
 * Component description for GPIO
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
#ifndef _BZ45_GPIO_COMPONENT_H_
#define _BZ45_GPIO_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR GPIO                                         */
/* ************************************************************************** */

/* -------- GPIO_ANSEL : (GPIO Offset: 0x00) (R/W 32)  -------- */
#define GPIO_ANSEL_RESETVALUE                 _UINT32_(0x00)                                       /*  (GPIO_ANSEL)   Reset Value */

#define GPIO_ANSEL_ANS0_Pos                   _UINT32_(0)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS0_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS0_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS0(value)                (GPIO_ANSEL_ANS0_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS0_Pos)) /* Assigment of value for ANS0 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS1_Pos                   _UINT32_(1)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS1_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS1_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS1(value)                (GPIO_ANSEL_ANS1_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS1_Pos)) /* Assigment of value for ANS1 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS2_Pos                   _UINT32_(2)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS2_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS2_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS2(value)                (GPIO_ANSEL_ANS2_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS2_Pos)) /* Assigment of value for ANS2 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS3_Pos                   _UINT32_(3)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS3_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS3_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS3(value)                (GPIO_ANSEL_ANS3_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS3_Pos)) /* Assigment of value for ANS3 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS4_Pos                   _UINT32_(4)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS4_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS4_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS4(value)                (GPIO_ANSEL_ANS4_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS4_Pos)) /* Assigment of value for ANS4 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS5_Pos                   _UINT32_(5)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS5_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS5_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS5(value)                (GPIO_ANSEL_ANS5_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS5_Pos)) /* Assigment of value for ANS5 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS6_Pos                   _UINT32_(6)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS6_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS6_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS6(value)                (GPIO_ANSEL_ANS6_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS6_Pos)) /* Assigment of value for ANS6 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS7_Pos                   _UINT32_(7)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS7_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS7_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS7(value)                (GPIO_ANSEL_ANS7_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS7_Pos)) /* Assigment of value for ANS7 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS8_Pos                   _UINT32_(8)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS8_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS8_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS8(value)                (GPIO_ANSEL_ANS8_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS8_Pos)) /* Assigment of value for ANS8 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS9_Pos                   _UINT32_(9)                                          /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS9_Msk                   (_UINT32_(0x1) << GPIO_ANSEL_ANS9_Pos)               /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS9(value)                (GPIO_ANSEL_ANS9_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS9_Pos)) /* Assigment of value for ANS9 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS10_Pos                  _UINT32_(10)                                         /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS10_Msk                  (_UINT32_(0x1) << GPIO_ANSEL_ANS10_Pos)              /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS10(value)               (GPIO_ANSEL_ANS10_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS10_Pos)) /* Assigment of value for ANS10 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS11_Pos                  _UINT32_(11)                                         /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS11_Msk                  (_UINT32_(0x1) << GPIO_ANSEL_ANS11_Pos)              /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS11(value)               (GPIO_ANSEL_ANS11_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS11_Pos)) /* Assigment of value for ANS11 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS12_Pos                  _UINT32_(12)                                         /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS12_Msk                  (_UINT32_(0x1) << GPIO_ANSEL_ANS12_Pos)              /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS12(value)               (GPIO_ANSEL_ANS12_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS12_Pos)) /* Assigment of value for ANS12 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS13_Pos                  _UINT32_(13)                                         /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS13_Msk                  (_UINT32_(0x1) << GPIO_ANSEL_ANS13_Pos)              /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS13(value)               (GPIO_ANSEL_ANS13_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS13_Pos)) /* Assigment of value for ANS13 in the GPIO_ANSEL register */
#define GPIO_ANSEL_ANS14_Pos                  _UINT32_(14)                                         /* (GPIO_ANSEL)  Position */
#define GPIO_ANSEL_ANS14_Msk                  (_UINT32_(0x1) << GPIO_ANSEL_ANS14_Pos)              /* (GPIO_ANSEL)  Mask */
#define GPIO_ANSEL_ANS14(value)               (GPIO_ANSEL_ANS14_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS14_Pos)) /* Assigment of value for ANS14 in the GPIO_ANSEL register */
#define GPIO_ANSEL_Msk                        _UINT32_(0x00007FFF)                                 /* (GPIO_ANSEL) Register Mask  */

#define GPIO_ANSEL_ANS_Pos                    _UINT32_(0)                                          /* (GPIO_ANSEL Position)  */
#define GPIO_ANSEL_ANS_Msk                    (_UINT32_(0x7FFF) << GPIO_ANSEL_ANS_Pos)             /* (GPIO_ANSEL Mask) ANS */
#define GPIO_ANSEL_ANS(value)                 (GPIO_ANSEL_ANS_Msk & (_UINT32_(value) << GPIO_ANSEL_ANS_Pos)) 

/* -------- GPIO_ANSELCLR : (GPIO Offset: 0x04) (R/W 32)  -------- */
#define GPIO_ANSELCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (GPIO_ANSELCLR)   Reset Value */

#define GPIO_ANSELCLR_Msk                     _UINT32_(0x00000000)                                 /* (GPIO_ANSELCLR) Register Mask  */


/* -------- GPIO_ANSELSET : (GPIO Offset: 0x08) (R/W 32)  -------- */
#define GPIO_ANSELSET_RESETVALUE              _UINT32_(0x00)                                       /*  (GPIO_ANSELSET)   Reset Value */

#define GPIO_ANSELSET_Msk                     _UINT32_(0x00000000)                                 /* (GPIO_ANSELSET) Register Mask  */


/* -------- GPIO_ANSELINV : (GPIO Offset: 0x0C) (R/W 32)  -------- */
#define GPIO_ANSELINV_RESETVALUE              _UINT32_(0x00)                                       /*  (GPIO_ANSELINV)   Reset Value */

#define GPIO_ANSELINV_Msk                     _UINT32_(0x00000000)                                 /* (GPIO_ANSELINV) Register Mask  */


/* -------- GPIO_TRIS : (GPIO Offset: 0x10) (R/W 32)  -------- */
#define GPIO_TRIS_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPIO_TRIS)   Reset Value */

#define GPIO_TRIS_TRIS0_Pos                   _UINT32_(0)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS0_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS0_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS0(value)                (GPIO_TRIS_TRIS0_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS0_Pos)) /* Assigment of value for TRIS0 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS1_Pos                   _UINT32_(1)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS1_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS1_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS1(value)                (GPIO_TRIS_TRIS1_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS1_Pos)) /* Assigment of value for TRIS1 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS2_Pos                   _UINT32_(2)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS2_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS2_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS2(value)                (GPIO_TRIS_TRIS2_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS2_Pos)) /* Assigment of value for TRIS2 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS3_Pos                   _UINT32_(3)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS3_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS3_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS3(value)                (GPIO_TRIS_TRIS3_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS3_Pos)) /* Assigment of value for TRIS3 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS4_Pos                   _UINT32_(4)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS4_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS4_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS4(value)                (GPIO_TRIS_TRIS4_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS4_Pos)) /* Assigment of value for TRIS4 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS5_Pos                   _UINT32_(5)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS5_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS5_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS5(value)                (GPIO_TRIS_TRIS5_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS5_Pos)) /* Assigment of value for TRIS5 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS6_Pos                   _UINT32_(6)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS6_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS6_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS6(value)                (GPIO_TRIS_TRIS6_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS6_Pos)) /* Assigment of value for TRIS6 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS7_Pos                   _UINT32_(7)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS7_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS7_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS7(value)                (GPIO_TRIS_TRIS7_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS7_Pos)) /* Assigment of value for TRIS7 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS8_Pos                   _UINT32_(8)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS8_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS8_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS8(value)                (GPIO_TRIS_TRIS8_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS8_Pos)) /* Assigment of value for TRIS8 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS9_Pos                   _UINT32_(9)                                          /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS9_Msk                   (_UINT32_(0x1) << GPIO_TRIS_TRIS9_Pos)               /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS9(value)                (GPIO_TRIS_TRIS9_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS9_Pos)) /* Assigment of value for TRIS9 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS10_Pos                  _UINT32_(10)                                         /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS10_Msk                  (_UINT32_(0x1) << GPIO_TRIS_TRIS10_Pos)              /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS10(value)               (GPIO_TRIS_TRIS10_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS10_Pos)) /* Assigment of value for TRIS10 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS13_Pos                  _UINT32_(13)                                         /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS13_Msk                  (_UINT32_(0x1) << GPIO_TRIS_TRIS13_Pos)              /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS13(value)               (GPIO_TRIS_TRIS13_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS13_Pos)) /* Assigment of value for TRIS13 in the GPIO_TRIS register */
#define GPIO_TRIS_TRIS14_Pos                  _UINT32_(14)                                         /* (GPIO_TRIS)  Position */
#define GPIO_TRIS_TRIS14_Msk                  (_UINT32_(0x1) << GPIO_TRIS_TRIS14_Pos)              /* (GPIO_TRIS)  Mask */
#define GPIO_TRIS_TRIS14(value)               (GPIO_TRIS_TRIS14_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS14_Pos)) /* Assigment of value for TRIS14 in the GPIO_TRIS register */
#define GPIO_TRIS_Msk                         _UINT32_(0x000067FF)                                 /* (GPIO_TRIS) Register Mask  */

#define GPIO_TRIS_TRIS_Pos                    _UINT32_(0)                                          /* (GPIO_TRIS Position)  */
#define GPIO_TRIS_TRIS_Msk                    (_UINT32_(0x1FFF) << GPIO_TRIS_TRIS_Pos)             /* (GPIO_TRIS Mask) TRIS */
#define GPIO_TRIS_TRIS(value)                 (GPIO_TRIS_TRIS_Msk & (_UINT32_(value) << GPIO_TRIS_TRIS_Pos)) 

/* -------- GPIO_TRISCLR : (GPIO Offset: 0x14) (R/W 32)  -------- */
#define GPIO_TRISCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_TRISCLR)   Reset Value */

#define GPIO_TRISCLR_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_TRISCLR) Register Mask  */


/* -------- GPIO_TRISSET : (GPIO Offset: 0x18) (R/W 32)  -------- */
#define GPIO_TRISSET_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_TRISSET)   Reset Value */

#define GPIO_TRISSET_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_TRISSET) Register Mask  */


/* -------- GPIO_TRISINV : (GPIO Offset: 0x1C) (R/W 32)  -------- */
#define GPIO_TRISINV_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_TRISINV)   Reset Value */

#define GPIO_TRISINV_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_TRISINV) Register Mask  */


/* -------- GPIO_PORT : (GPIO Offset: 0x20) (R/W 32)  -------- */
#define GPIO_PORT_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPIO_PORT)   Reset Value */

#define GPIO_PORT_R0_Pos                      _UINT32_(0)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R0_Msk                      (_UINT32_(0x1) << GPIO_PORT_R0_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R0(value)                   (GPIO_PORT_R0_Msk & (_UINT32_(value) << GPIO_PORT_R0_Pos)) /* Assigment of value for R0 in the GPIO_PORT register */
#define GPIO_PORT_R1_Pos                      _UINT32_(1)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R1_Msk                      (_UINT32_(0x1) << GPIO_PORT_R1_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R1(value)                   (GPIO_PORT_R1_Msk & (_UINT32_(value) << GPIO_PORT_R1_Pos)) /* Assigment of value for R1 in the GPIO_PORT register */
#define GPIO_PORT_R2_Pos                      _UINT32_(2)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R2_Msk                      (_UINT32_(0x1) << GPIO_PORT_R2_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R2(value)                   (GPIO_PORT_R2_Msk & (_UINT32_(value) << GPIO_PORT_R2_Pos)) /* Assigment of value for R2 in the GPIO_PORT register */
#define GPIO_PORT_R3_Pos                      _UINT32_(3)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R3_Msk                      (_UINT32_(0x1) << GPIO_PORT_R3_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R3(value)                   (GPIO_PORT_R3_Msk & (_UINT32_(value) << GPIO_PORT_R3_Pos)) /* Assigment of value for R3 in the GPIO_PORT register */
#define GPIO_PORT_R4_Pos                      _UINT32_(4)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R4_Msk                      (_UINT32_(0x1) << GPIO_PORT_R4_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R4(value)                   (GPIO_PORT_R4_Msk & (_UINT32_(value) << GPIO_PORT_R4_Pos)) /* Assigment of value for R4 in the GPIO_PORT register */
#define GPIO_PORT_R5_Pos                      _UINT32_(5)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R5_Msk                      (_UINT32_(0x1) << GPIO_PORT_R5_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R5(value)                   (GPIO_PORT_R5_Msk & (_UINT32_(value) << GPIO_PORT_R5_Pos)) /* Assigment of value for R5 in the GPIO_PORT register */
#define GPIO_PORT_R6_Pos                      _UINT32_(6)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R6_Msk                      (_UINT32_(0x1) << GPIO_PORT_R6_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R6(value)                   (GPIO_PORT_R6_Msk & (_UINT32_(value) << GPIO_PORT_R6_Pos)) /* Assigment of value for R6 in the GPIO_PORT register */
#define GPIO_PORT_R7_Pos                      _UINT32_(7)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R7_Msk                      (_UINT32_(0x1) << GPIO_PORT_R7_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R7(value)                   (GPIO_PORT_R7_Msk & (_UINT32_(value) << GPIO_PORT_R7_Pos)) /* Assigment of value for R7 in the GPIO_PORT register */
#define GPIO_PORT_R8_Pos                      _UINT32_(8)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R8_Msk                      (_UINT32_(0x1) << GPIO_PORT_R8_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R8(value)                   (GPIO_PORT_R8_Msk & (_UINT32_(value) << GPIO_PORT_R8_Pos)) /* Assigment of value for R8 in the GPIO_PORT register */
#define GPIO_PORT_R9_Pos                      _UINT32_(9)                                          /* (GPIO_PORT)  Position */
#define GPIO_PORT_R9_Msk                      (_UINT32_(0x1) << GPIO_PORT_R9_Pos)                  /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R9(value)                   (GPIO_PORT_R9_Msk & (_UINT32_(value) << GPIO_PORT_R9_Pos)) /* Assigment of value for R9 in the GPIO_PORT register */
#define GPIO_PORT_R10_Pos                     _UINT32_(10)                                         /* (GPIO_PORT)  Position */
#define GPIO_PORT_R10_Msk                     (_UINT32_(0x1) << GPIO_PORT_R10_Pos)                 /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R10(value)                  (GPIO_PORT_R10_Msk & (_UINT32_(value) << GPIO_PORT_R10_Pos)) /* Assigment of value for R10 in the GPIO_PORT register */
#define GPIO_PORT_R11_Pos                     _UINT32_(11)                                         /* (GPIO_PORT)  Position */
#define GPIO_PORT_R11_Msk                     (_UINT32_(0x1) << GPIO_PORT_R11_Pos)                 /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R11(value)                  (GPIO_PORT_R11_Msk & (_UINT32_(value) << GPIO_PORT_R11_Pos)) /* Assigment of value for R11 in the GPIO_PORT register */
#define GPIO_PORT_R12_Pos                     _UINT32_(12)                                         /* (GPIO_PORT)  Position */
#define GPIO_PORT_R12_Msk                     (_UINT32_(0x1) << GPIO_PORT_R12_Pos)                 /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R12(value)                  (GPIO_PORT_R12_Msk & (_UINT32_(value) << GPIO_PORT_R12_Pos)) /* Assigment of value for R12 in the GPIO_PORT register */
#define GPIO_PORT_R13_Pos                     _UINT32_(13)                                         /* (GPIO_PORT)  Position */
#define GPIO_PORT_R13_Msk                     (_UINT32_(0x1) << GPIO_PORT_R13_Pos)                 /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R13(value)                  (GPIO_PORT_R13_Msk & (_UINT32_(value) << GPIO_PORT_R13_Pos)) /* Assigment of value for R13 in the GPIO_PORT register */
#define GPIO_PORT_R14_Pos                     _UINT32_(14)                                         /* (GPIO_PORT)  Position */
#define GPIO_PORT_R14_Msk                     (_UINT32_(0x1) << GPIO_PORT_R14_Pos)                 /* (GPIO_PORT)  Mask */
#define GPIO_PORT_R14(value)                  (GPIO_PORT_R14_Msk & (_UINT32_(value) << GPIO_PORT_R14_Pos)) /* Assigment of value for R14 in the GPIO_PORT register */
#define GPIO_PORT_Msk                         _UINT32_(0x00007FFF)                                 /* (GPIO_PORT) Register Mask  */

#define GPIO_PORT_R_Pos                       _UINT32_(0)                                          /* (GPIO_PORT Position)  */
#define GPIO_PORT_R_Msk                       (_UINT32_(0x7FFF) << GPIO_PORT_R_Pos)                /* (GPIO_PORT Mask) R */
#define GPIO_PORT_R(value)                    (GPIO_PORT_R_Msk & (_UINT32_(value) << GPIO_PORT_R_Pos)) 

/* -------- GPIO_PORTCLR : (GPIO Offset: 0x24) (R/W 32)  -------- */
#define GPIO_PORTCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_PORTCLR)   Reset Value */

#define GPIO_PORTCLR_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_PORTCLR) Register Mask  */


/* -------- GPIO_PORTSET : (GPIO Offset: 0x28) (R/W 32)  -------- */
#define GPIO_PORTSET_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_PORTSET)   Reset Value */

#define GPIO_PORTSET_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_PORTSET) Register Mask  */


/* -------- GPIO_PORTINV : (GPIO Offset: 0x2C) (R/W 32)  -------- */
#define GPIO_PORTINV_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_PORTINV)   Reset Value */

#define GPIO_PORTINV_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_PORTINV) Register Mask  */


/* -------- GPIO_LAT : (GPIO Offset: 0x30) (R/W 32)  -------- */
#define GPIO_LAT_RESETVALUE                   _UINT32_(0x00)                                       /*  (GPIO_LAT)   Reset Value */

#define GPIO_LAT_LAT0_Pos                     _UINT32_(0)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT0_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT0_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT0(value)                  (GPIO_LAT_LAT0_Msk & (_UINT32_(value) << GPIO_LAT_LAT0_Pos)) /* Assigment of value for LAT0 in the GPIO_LAT register */
#define GPIO_LAT_LAT1_Pos                     _UINT32_(1)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT1_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT1_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT1(value)                  (GPIO_LAT_LAT1_Msk & (_UINT32_(value) << GPIO_LAT_LAT1_Pos)) /* Assigment of value for LAT1 in the GPIO_LAT register */
#define GPIO_LAT_LAT2_Pos                     _UINT32_(2)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT2_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT2_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT2(value)                  (GPIO_LAT_LAT2_Msk & (_UINT32_(value) << GPIO_LAT_LAT2_Pos)) /* Assigment of value for LAT2 in the GPIO_LAT register */
#define GPIO_LAT_LAT3_Pos                     _UINT32_(3)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT3_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT3_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT3(value)                  (GPIO_LAT_LAT3_Msk & (_UINT32_(value) << GPIO_LAT_LAT3_Pos)) /* Assigment of value for LAT3 in the GPIO_LAT register */
#define GPIO_LAT_LAT4_Pos                     _UINT32_(4)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT4_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT4_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT4(value)                  (GPIO_LAT_LAT4_Msk & (_UINT32_(value) << GPIO_LAT_LAT4_Pos)) /* Assigment of value for LAT4 in the GPIO_LAT register */
#define GPIO_LAT_LAT5_Pos                     _UINT32_(5)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT5_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT5_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT5(value)                  (GPIO_LAT_LAT5_Msk & (_UINT32_(value) << GPIO_LAT_LAT5_Pos)) /* Assigment of value for LAT5 in the GPIO_LAT register */
#define GPIO_LAT_LAT6_Pos                     _UINT32_(6)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT6_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT6_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT6(value)                  (GPIO_LAT_LAT6_Msk & (_UINT32_(value) << GPIO_LAT_LAT6_Pos)) /* Assigment of value for LAT6 in the GPIO_LAT register */
#define GPIO_LAT_LAT7_Pos                     _UINT32_(7)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT7_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT7_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT7(value)                  (GPIO_LAT_LAT7_Msk & (_UINT32_(value) << GPIO_LAT_LAT7_Pos)) /* Assigment of value for LAT7 in the GPIO_LAT register */
#define GPIO_LAT_LAT8_Pos                     _UINT32_(8)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT8_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT8_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT8(value)                  (GPIO_LAT_LAT8_Msk & (_UINT32_(value) << GPIO_LAT_LAT8_Pos)) /* Assigment of value for LAT8 in the GPIO_LAT register */
#define GPIO_LAT_LAT9_Pos                     _UINT32_(9)                                          /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT9_Msk                     (_UINT32_(0x1) << GPIO_LAT_LAT9_Pos)                 /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT9(value)                  (GPIO_LAT_LAT9_Msk & (_UINT32_(value) << GPIO_LAT_LAT9_Pos)) /* Assigment of value for LAT9 in the GPIO_LAT register */
#define GPIO_LAT_LAT10_Pos                    _UINT32_(10)                                         /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT10_Msk                    (_UINT32_(0x1) << GPIO_LAT_LAT10_Pos)                /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT10(value)                 (GPIO_LAT_LAT10_Msk & (_UINT32_(value) << GPIO_LAT_LAT10_Pos)) /* Assigment of value for LAT10 in the GPIO_LAT register */
#define GPIO_LAT_LAT11_Pos                    _UINT32_(11)                                         /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT11_Msk                    (_UINT32_(0x1) << GPIO_LAT_LAT11_Pos)                /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT11(value)                 (GPIO_LAT_LAT11_Msk & (_UINT32_(value) << GPIO_LAT_LAT11_Pos)) /* Assigment of value for LAT11 in the GPIO_LAT register */
#define GPIO_LAT_LAT12_Pos                    _UINT32_(12)                                         /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT12_Msk                    (_UINT32_(0x1) << GPIO_LAT_LAT12_Pos)                /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT12(value)                 (GPIO_LAT_LAT12_Msk & (_UINT32_(value) << GPIO_LAT_LAT12_Pos)) /* Assigment of value for LAT12 in the GPIO_LAT register */
#define GPIO_LAT_LAT13_Pos                    _UINT32_(13)                                         /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT13_Msk                    (_UINT32_(0x1) << GPIO_LAT_LAT13_Pos)                /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT13(value)                 (GPIO_LAT_LAT13_Msk & (_UINT32_(value) << GPIO_LAT_LAT13_Pos)) /* Assigment of value for LAT13 in the GPIO_LAT register */
#define GPIO_LAT_LAT14_Pos                    _UINT32_(14)                                         /* (GPIO_LAT)  Position */
#define GPIO_LAT_LAT14_Msk                    (_UINT32_(0x1) << GPIO_LAT_LAT14_Pos)                /* (GPIO_LAT)  Mask */
#define GPIO_LAT_LAT14(value)                 (GPIO_LAT_LAT14_Msk & (_UINT32_(value) << GPIO_LAT_LAT14_Pos)) /* Assigment of value for LAT14 in the GPIO_LAT register */
#define GPIO_LAT_Msk                          _UINT32_(0x00007FFF)                                 /* (GPIO_LAT) Register Mask  */

#define GPIO_LAT_LAT_Pos                      _UINT32_(0)                                          /* (GPIO_LAT Position)  */
#define GPIO_LAT_LAT_Msk                      (_UINT32_(0x7FFF) << GPIO_LAT_LAT_Pos)               /* (GPIO_LAT Mask) LAT */
#define GPIO_LAT_LAT(value)                   (GPIO_LAT_LAT_Msk & (_UINT32_(value) << GPIO_LAT_LAT_Pos)) 

/* -------- GPIO_LATCLR : (GPIO Offset: 0x34) (R/W 32)  -------- */
#define GPIO_LATCLR_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_LATCLR)   Reset Value */

#define GPIO_LATCLR_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_LATCLR) Register Mask  */


/* -------- GPIO_LATSET : (GPIO Offset: 0x38) (R/W 32)  -------- */
#define GPIO_LATSET_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_LATSET)   Reset Value */

#define GPIO_LATSET_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_LATSET) Register Mask  */


/* -------- GPIO_LATINV : (GPIO Offset: 0x3C) (R/W 32)  -------- */
#define GPIO_LATINV_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_LATINV)   Reset Value */

#define GPIO_LATINV_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_LATINV) Register Mask  */


/* -------- GPIO_ODC : (GPIO Offset: 0x40) (R/W 32)  -------- */
#define GPIO_ODC_RESETVALUE                   _UINT32_(0x00)                                       /*  (GPIO_ODC)   Reset Value */

#define GPIO_ODC_ODC0_Pos                     _UINT32_(0)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC0_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC0_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC0(value)                  (GPIO_ODC_ODC0_Msk & (_UINT32_(value) << GPIO_ODC_ODC0_Pos)) /* Assigment of value for ODC0 in the GPIO_ODC register */
#define GPIO_ODC_ODC1_Pos                     _UINT32_(1)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC1_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC1_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC1(value)                  (GPIO_ODC_ODC1_Msk & (_UINT32_(value) << GPIO_ODC_ODC1_Pos)) /* Assigment of value for ODC1 in the GPIO_ODC register */
#define GPIO_ODC_ODC2_Pos                     _UINT32_(2)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC2_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC2_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC2(value)                  (GPIO_ODC_ODC2_Msk & (_UINT32_(value) << GPIO_ODC_ODC2_Pos)) /* Assigment of value for ODC2 in the GPIO_ODC register */
#define GPIO_ODC_ODC3_Pos                     _UINT32_(3)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC3_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC3_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC3(value)                  (GPIO_ODC_ODC3_Msk & (_UINT32_(value) << GPIO_ODC_ODC3_Pos)) /* Assigment of value for ODC3 in the GPIO_ODC register */
#define GPIO_ODC_ODC4_Pos                     _UINT32_(4)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC4_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC4_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC4(value)                  (GPIO_ODC_ODC4_Msk & (_UINT32_(value) << GPIO_ODC_ODC4_Pos)) /* Assigment of value for ODC4 in the GPIO_ODC register */
#define GPIO_ODC_ODC5_Pos                     _UINT32_(5)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC5_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC5_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC5(value)                  (GPIO_ODC_ODC5_Msk & (_UINT32_(value) << GPIO_ODC_ODC5_Pos)) /* Assigment of value for ODC5 in the GPIO_ODC register */
#define GPIO_ODC_ODC6_Pos                     _UINT32_(6)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC6_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC6_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC6(value)                  (GPIO_ODC_ODC6_Msk & (_UINT32_(value) << GPIO_ODC_ODC6_Pos)) /* Assigment of value for ODC6 in the GPIO_ODC register */
#define GPIO_ODC_ODC7_Pos                     _UINT32_(7)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC7_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC7_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC7(value)                  (GPIO_ODC_ODC7_Msk & (_UINT32_(value) << GPIO_ODC_ODC7_Pos)) /* Assigment of value for ODC7 in the GPIO_ODC register */
#define GPIO_ODC_ODC8_Pos                     _UINT32_(8)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC8_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC8_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC8(value)                  (GPIO_ODC_ODC8_Msk & (_UINT32_(value) << GPIO_ODC_ODC8_Pos)) /* Assigment of value for ODC8 in the GPIO_ODC register */
#define GPIO_ODC_ODC9_Pos                     _UINT32_(9)                                          /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC9_Msk                     (_UINT32_(0x1) << GPIO_ODC_ODC9_Pos)                 /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC9(value)                  (GPIO_ODC_ODC9_Msk & (_UINT32_(value) << GPIO_ODC_ODC9_Pos)) /* Assigment of value for ODC9 in the GPIO_ODC register */
#define GPIO_ODC_ODC10_Pos                    _UINT32_(10)                                         /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC10_Msk                    (_UINT32_(0x1) << GPIO_ODC_ODC10_Pos)                /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC10(value)                 (GPIO_ODC_ODC10_Msk & (_UINT32_(value) << GPIO_ODC_ODC10_Pos)) /* Assigment of value for ODC10 in the GPIO_ODC register */
#define GPIO_ODC_ODC11_Pos                    _UINT32_(11)                                         /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC11_Msk                    (_UINT32_(0x1) << GPIO_ODC_ODC11_Pos)                /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC11(value)                 (GPIO_ODC_ODC11_Msk & (_UINT32_(value) << GPIO_ODC_ODC11_Pos)) /* Assigment of value for ODC11 in the GPIO_ODC register */
#define GPIO_ODC_ODC12_Pos                    _UINT32_(12)                                         /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC12_Msk                    (_UINT32_(0x1) << GPIO_ODC_ODC12_Pos)                /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC12(value)                 (GPIO_ODC_ODC12_Msk & (_UINT32_(value) << GPIO_ODC_ODC12_Pos)) /* Assigment of value for ODC12 in the GPIO_ODC register */
#define GPIO_ODC_ODC13_Pos                    _UINT32_(13)                                         /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC13_Msk                    (_UINT32_(0x1) << GPIO_ODC_ODC13_Pos)                /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC13(value)                 (GPIO_ODC_ODC13_Msk & (_UINT32_(value) << GPIO_ODC_ODC13_Pos)) /* Assigment of value for ODC13 in the GPIO_ODC register */
#define GPIO_ODC_ODC14_Pos                    _UINT32_(14)                                         /* (GPIO_ODC)  Position */
#define GPIO_ODC_ODC14_Msk                    (_UINT32_(0x1) << GPIO_ODC_ODC14_Pos)                /* (GPIO_ODC)  Mask */
#define GPIO_ODC_ODC14(value)                 (GPIO_ODC_ODC14_Msk & (_UINT32_(value) << GPIO_ODC_ODC14_Pos)) /* Assigment of value for ODC14 in the GPIO_ODC register */
#define GPIO_ODC_Msk                          _UINT32_(0x00007FFF)                                 /* (GPIO_ODC) Register Mask  */

#define GPIO_ODC_ODC_Pos                      _UINT32_(0)                                          /* (GPIO_ODC Position)  */
#define GPIO_ODC_ODC_Msk                      (_UINT32_(0x7FFF) << GPIO_ODC_ODC_Pos)               /* (GPIO_ODC Mask) ODC */
#define GPIO_ODC_ODC(value)                   (GPIO_ODC_ODC_Msk & (_UINT32_(value) << GPIO_ODC_ODC_Pos)) 

/* -------- GPIO_ODCCLR : (GPIO Offset: 0x44) (R/W 32)  -------- */
#define GPIO_ODCCLR_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_ODCCLR)   Reset Value */

#define GPIO_ODCCLR_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_ODCCLR) Register Mask  */


/* -------- GPIO_ODCSET : (GPIO Offset: 0x48) (R/W 32)  -------- */
#define GPIO_ODCSET_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_ODCSET)   Reset Value */

#define GPIO_ODCSET_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_ODCSET) Register Mask  */


/* -------- GPIO_ODCINV : (GPIO Offset: 0x4C) (R/W 32)  -------- */
#define GPIO_ODCINV_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_ODCINV)   Reset Value */

#define GPIO_ODCINV_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_ODCINV) Register Mask  */


/* -------- GPIO_CNPU : (GPIO Offset: 0x50) (R/W 32)  -------- */
#define GPIO_CNPU_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPIO_CNPU)   Reset Value */

#define GPIO_CNPU_CNPU0_Pos                   _UINT32_(0)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU0_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU0_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU0(value)                (GPIO_CNPU_CNPU0_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU0_Pos)) /* Assigment of value for CNPU0 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU1_Pos                   _UINT32_(1)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU1_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU1_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU1(value)                (GPIO_CNPU_CNPU1_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU1_Pos)) /* Assigment of value for CNPU1 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU2_Pos                   _UINT32_(2)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU2_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU2_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU2(value)                (GPIO_CNPU_CNPU2_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU2_Pos)) /* Assigment of value for CNPU2 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU3_Pos                   _UINT32_(3)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU3_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU3_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU3(value)                (GPIO_CNPU_CNPU3_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU3_Pos)) /* Assigment of value for CNPU3 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU4_Pos                   _UINT32_(4)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU4_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU4_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU4(value)                (GPIO_CNPU_CNPU4_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU4_Pos)) /* Assigment of value for CNPU4 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU5_Pos                   _UINT32_(5)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU5_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU5_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU5(value)                (GPIO_CNPU_CNPU5_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU5_Pos)) /* Assigment of value for CNPU5 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU6_Pos                   _UINT32_(6)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU6_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU6_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU6(value)                (GPIO_CNPU_CNPU6_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU6_Pos)) /* Assigment of value for CNPU6 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU7_Pos                   _UINT32_(7)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU7_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU7_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU7(value)                (GPIO_CNPU_CNPU7_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU7_Pos)) /* Assigment of value for CNPU7 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU8_Pos                   _UINT32_(8)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU8_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU8_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU8(value)                (GPIO_CNPU_CNPU8_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU8_Pos)) /* Assigment of value for CNPU8 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU9_Pos                   _UINT32_(9)                                          /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU9_Msk                   (_UINT32_(0x1) << GPIO_CNPU_CNPU9_Pos)               /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU9(value)                (GPIO_CNPU_CNPU9_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU9_Pos)) /* Assigment of value for CNPU9 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU10_Pos                  _UINT32_(10)                                         /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU10_Msk                  (_UINT32_(0x1) << GPIO_CNPU_CNPU10_Pos)              /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU10(value)               (GPIO_CNPU_CNPU10_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU10_Pos)) /* Assigment of value for CNPU10 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU11_Pos                  _UINT32_(11)                                         /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU11_Msk                  (_UINT32_(0x1) << GPIO_CNPU_CNPU11_Pos)              /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU11(value)               (GPIO_CNPU_CNPU11_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU11_Pos)) /* Assigment of value for CNPU11 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU12_Pos                  _UINT32_(12)                                         /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU12_Msk                  (_UINT32_(0x1) << GPIO_CNPU_CNPU12_Pos)              /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU12(value)               (GPIO_CNPU_CNPU12_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU12_Pos)) /* Assigment of value for CNPU12 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU13_Pos                  _UINT32_(13)                                         /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU13_Msk                  (_UINT32_(0x1) << GPIO_CNPU_CNPU13_Pos)              /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU13(value)               (GPIO_CNPU_CNPU13_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU13_Pos)) /* Assigment of value for CNPU13 in the GPIO_CNPU register */
#define GPIO_CNPU_CNPU14_Pos                  _UINT32_(14)                                         /* (GPIO_CNPU)  Position */
#define GPIO_CNPU_CNPU14_Msk                  (_UINT32_(0x1) << GPIO_CNPU_CNPU14_Pos)              /* (GPIO_CNPU)  Mask */
#define GPIO_CNPU_CNPU14(value)               (GPIO_CNPU_CNPU14_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU14_Pos)) /* Assigment of value for CNPU14 in the GPIO_CNPU register */
#define GPIO_CNPU_Msk                         _UINT32_(0x00007FFF)                                 /* (GPIO_CNPU) Register Mask  */

#define GPIO_CNPU_CNPU_Pos                    _UINT32_(0)                                          /* (GPIO_CNPU Position)  */
#define GPIO_CNPU_CNPU_Msk                    (_UINT32_(0x7FFF) << GPIO_CNPU_CNPU_Pos)             /* (GPIO_CNPU Mask) CNPU */
#define GPIO_CNPU_CNPU(value)                 (GPIO_CNPU_CNPU_Msk & (_UINT32_(value) << GPIO_CNPU_CNPU_Pos)) 

/* -------- GPIO_CNPUCLR : (GPIO Offset: 0x54) (R/W 32)  -------- */
#define GPIO_CNPUCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNPUCLR)   Reset Value */

#define GPIO_CNPUCLR_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNPUCLR) Register Mask  */


/* -------- GPIO_CNPUSET : (GPIO Offset: 0x58) (R/W 32)  -------- */
#define GPIO_CNPUSET_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNPUSET)   Reset Value */

#define GPIO_CNPUSET_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNPUSET) Register Mask  */


/* -------- GPIO_CNPUINV : (GPIO Offset: 0x5C) (R/W 32)  -------- */
#define GPIO_CNPUINV_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNPUINV)   Reset Value */

#define GPIO_CNPUINV_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNPUINV) Register Mask  */


/* -------- GPIO_CNPD : (GPIO Offset: 0x60) (R/W 32)  -------- */
#define GPIO_CNPD_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPIO_CNPD)   Reset Value */

#define GPIO_CNPD_CNPD0_Pos                   _UINT32_(0)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD0_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD0_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD0(value)                (GPIO_CNPD_CNPD0_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD0_Pos)) /* Assigment of value for CNPD0 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD1_Pos                   _UINT32_(1)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD1_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD1_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD1(value)                (GPIO_CNPD_CNPD1_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD1_Pos)) /* Assigment of value for CNPD1 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD2_Pos                   _UINT32_(2)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD2_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD2_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD2(value)                (GPIO_CNPD_CNPD2_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD2_Pos)) /* Assigment of value for CNPD2 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD3_Pos                   _UINT32_(3)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD3_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD3_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD3(value)                (GPIO_CNPD_CNPD3_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD3_Pos)) /* Assigment of value for CNPD3 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD4_Pos                   _UINT32_(4)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD4_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD4_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD4(value)                (GPIO_CNPD_CNPD4_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD4_Pos)) /* Assigment of value for CNPD4 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD5_Pos                   _UINT32_(5)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD5_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD5_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD5(value)                (GPIO_CNPD_CNPD5_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD5_Pos)) /* Assigment of value for CNPD5 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD6_Pos                   _UINT32_(6)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD6_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD6_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD6(value)                (GPIO_CNPD_CNPD6_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD6_Pos)) /* Assigment of value for CNPD6 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD7_Pos                   _UINT32_(7)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD7_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD7_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD7(value)                (GPIO_CNPD_CNPD7_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD7_Pos)) /* Assigment of value for CNPD7 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD8_Pos                   _UINT32_(8)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD8_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD8_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD8(value)                (GPIO_CNPD_CNPD8_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD8_Pos)) /* Assigment of value for CNPD8 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD9_Pos                   _UINT32_(9)                                          /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD9_Msk                   (_UINT32_(0x1) << GPIO_CNPD_CNPD9_Pos)               /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD9(value)                (GPIO_CNPD_CNPD9_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD9_Pos)) /* Assigment of value for CNPD9 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD10_Pos                  _UINT32_(10)                                         /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD10_Msk                  (_UINT32_(0x1) << GPIO_CNPD_CNPD10_Pos)              /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD10(value)               (GPIO_CNPD_CNPD10_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD10_Pos)) /* Assigment of value for CNPD10 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD11_Pos                  _UINT32_(11)                                         /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD11_Msk                  (_UINT32_(0x1) << GPIO_CNPD_CNPD11_Pos)              /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD11(value)               (GPIO_CNPD_CNPD11_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD11_Pos)) /* Assigment of value for CNPD11 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD12_Pos                  _UINT32_(12)                                         /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD12_Msk                  (_UINT32_(0x1) << GPIO_CNPD_CNPD12_Pos)              /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD12(value)               (GPIO_CNPD_CNPD12_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD12_Pos)) /* Assigment of value for CNPD12 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD13_Pos                  _UINT32_(13)                                         /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD13_Msk                  (_UINT32_(0x1) << GPIO_CNPD_CNPD13_Pos)              /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD13(value)               (GPIO_CNPD_CNPD13_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD13_Pos)) /* Assigment of value for CNPD13 in the GPIO_CNPD register */
#define GPIO_CNPD_CNPD14_Pos                  _UINT32_(14)                                         /* (GPIO_CNPD)  Position */
#define GPIO_CNPD_CNPD14_Msk                  (_UINT32_(0x1) << GPIO_CNPD_CNPD14_Pos)              /* (GPIO_CNPD)  Mask */
#define GPIO_CNPD_CNPD14(value)               (GPIO_CNPD_CNPD14_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD14_Pos)) /* Assigment of value for CNPD14 in the GPIO_CNPD register */
#define GPIO_CNPD_Msk                         _UINT32_(0x00007FFF)                                 /* (GPIO_CNPD) Register Mask  */

#define GPIO_CNPD_CNPD_Pos                    _UINT32_(0)                                          /* (GPIO_CNPD Position)  */
#define GPIO_CNPD_CNPD_Msk                    (_UINT32_(0x7FFF) << GPIO_CNPD_CNPD_Pos)             /* (GPIO_CNPD Mask) CNPD */
#define GPIO_CNPD_CNPD(value)                 (GPIO_CNPD_CNPD_Msk & (_UINT32_(value) << GPIO_CNPD_CNPD_Pos)) 

/* -------- GPIO_CNPDCLR : (GPIO Offset: 0x64) (R/W 32)  -------- */
#define GPIO_CNPDCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNPDCLR)   Reset Value */

#define GPIO_CNPDCLR_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNPDCLR) Register Mask  */


/* -------- GPIO_CNPDSET : (GPIO Offset: 0x68) (R/W 32)  -------- */
#define GPIO_CNPDSET_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNPDSET)   Reset Value */

#define GPIO_CNPDSET_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNPDSET) Register Mask  */


/* -------- GPIO_CNPDINV : (GPIO Offset: 0x6C) (R/W 32)  -------- */
#define GPIO_CNPDINV_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNPDINV)   Reset Value */

#define GPIO_CNPDINV_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNPDINV) Register Mask  */


/* -------- GPIO_CNCON : (GPIO Offset: 0x70) (R/W 32)  -------- */
#define GPIO_CNCON_RESETVALUE                 _UINT32_(0x00)                                       /*  (GPIO_CNCON)   Reset Value */

#define GPIO_CNCON_EDGEDETECT_Pos             _UINT32_(11)                                         /* (GPIO_CNCON)  Position */
#define GPIO_CNCON_EDGEDETECT_Msk             (_UINT32_(0x1) << GPIO_CNCON_EDGEDETECT_Pos)         /* (GPIO_CNCON)  Mask */
#define GPIO_CNCON_EDGEDETECT(value)          (GPIO_CNCON_EDGEDETECT_Msk & (_UINT32_(value) << GPIO_CNCON_EDGEDETECT_Pos)) /* Assigment of value for EDGEDETECT in the GPIO_CNCON register */
#define GPIO_CNCON_SIDL_Pos                   _UINT32_(13)                                         /* (GPIO_CNCON)  Position */
#define GPIO_CNCON_SIDL_Msk                   (_UINT32_(0x1) << GPIO_CNCON_SIDL_Pos)               /* (GPIO_CNCON)  Mask */
#define GPIO_CNCON_SIDL(value)                (GPIO_CNCON_SIDL_Msk & (_UINT32_(value) << GPIO_CNCON_SIDL_Pos)) /* Assigment of value for SIDL in the GPIO_CNCON register */
#define GPIO_CNCON_FRZ_Pos                    _UINT32_(14)                                         /* (GPIO_CNCON)  Position */
#define GPIO_CNCON_FRZ_Msk                    (_UINT32_(0x1) << GPIO_CNCON_FRZ_Pos)                /* (GPIO_CNCON)  Mask */
#define GPIO_CNCON_FRZ(value)                 (GPIO_CNCON_FRZ_Msk & (_UINT32_(value) << GPIO_CNCON_FRZ_Pos)) /* Assigment of value for FRZ in the GPIO_CNCON register */
#define GPIO_CNCON_ON_Pos                     _UINT32_(15)                                         /* (GPIO_CNCON)  Position */
#define GPIO_CNCON_ON_Msk                     (_UINT32_(0x1) << GPIO_CNCON_ON_Pos)                 /* (GPIO_CNCON)  Mask */
#define GPIO_CNCON_ON(value)                  (GPIO_CNCON_ON_Msk & (_UINT32_(value) << GPIO_CNCON_ON_Pos)) /* Assigment of value for ON in the GPIO_CNCON register */
#define GPIO_CNCON_Msk                        _UINT32_(0x0000E800)                                 /* (GPIO_CNCON) Register Mask  */


/* -------- GPIO_CNCONCLR : (GPIO Offset: 0x74) (R/W 32)  -------- */
#define GPIO_CNCONCLR_RESETVALUE              _UINT32_(0x00)                                       /*  (GPIO_CNCONCLR)   Reset Value */

#define GPIO_CNCONCLR_Msk                     _UINT32_(0x00000000)                                 /* (GPIO_CNCONCLR) Register Mask  */


/* -------- GPIO_CNCONSET : (GPIO Offset: 0x78) (R/W 32)  -------- */
#define GPIO_CNCONSET_RESETVALUE              _UINT32_(0x00)                                       /*  (GPIO_CNCONSET)   Reset Value */

#define GPIO_CNCONSET_Msk                     _UINT32_(0x00000000)                                 /* (GPIO_CNCONSET) Register Mask  */


/* -------- GPIO_CNCONINV : (GPIO Offset: 0x7C) (R/W 32)  -------- */
#define GPIO_CNCONINV_RESETVALUE              _UINT32_(0x00)                                       /*  (GPIO_CNCONINV)   Reset Value */

#define GPIO_CNCONINV_Msk                     _UINT32_(0x00000000)                                 /* (GPIO_CNCONINV) Register Mask  */


/* -------- GPIO_CNEN : (GPIO Offset: 0x80) (R/W 32)  -------- */
#define GPIO_CNEN_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPIO_CNEN)   Reset Value */

#define GPIO_CNEN_CNIE0_Pos                   _UINT32_(0)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE0_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE0_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE0(value)                (GPIO_CNEN_CNIE0_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE0_Pos)) /* Assigment of value for CNIE0 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE1_Pos                   _UINT32_(1)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE1_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE1_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE1(value)                (GPIO_CNEN_CNIE1_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE1_Pos)) /* Assigment of value for CNIE1 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE2_Pos                   _UINT32_(2)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE2_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE2_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE2(value)                (GPIO_CNEN_CNIE2_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE2_Pos)) /* Assigment of value for CNIE2 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE3_Pos                   _UINT32_(3)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE3_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE3_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE3(value)                (GPIO_CNEN_CNIE3_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE3_Pos)) /* Assigment of value for CNIE3 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE4_Pos                   _UINT32_(4)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE4_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE4_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE4(value)                (GPIO_CNEN_CNIE4_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE4_Pos)) /* Assigment of value for CNIE4 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE5_Pos                   _UINT32_(5)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE5_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE5_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE5(value)                (GPIO_CNEN_CNIE5_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE5_Pos)) /* Assigment of value for CNIE5 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE6_Pos                   _UINT32_(6)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE6_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE6_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE6(value)                (GPIO_CNEN_CNIE6_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE6_Pos)) /* Assigment of value for CNIE6 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE7_Pos                   _UINT32_(7)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE7_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE7_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE7(value)                (GPIO_CNEN_CNIE7_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE7_Pos)) /* Assigment of value for CNIE7 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE8_Pos                   _UINT32_(8)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE8_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE8_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE8(value)                (GPIO_CNEN_CNIE8_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE8_Pos)) /* Assigment of value for CNIE8 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE9_Pos                   _UINT32_(9)                                          /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE9_Msk                   (_UINT32_(0x1) << GPIO_CNEN_CNIE9_Pos)               /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE9(value)                (GPIO_CNEN_CNIE9_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE9_Pos)) /* Assigment of value for CNIE9 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE10_Pos                  _UINT32_(10)                                         /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE10_Msk                  (_UINT32_(0x1) << GPIO_CNEN_CNIE10_Pos)              /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE10(value)               (GPIO_CNEN_CNIE10_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE10_Pos)) /* Assigment of value for CNIE10 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE11_Pos                  _UINT32_(11)                                         /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE11_Msk                  (_UINT32_(0x1) << GPIO_CNEN_CNIE11_Pos)              /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE11(value)               (GPIO_CNEN_CNIE11_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE11_Pos)) /* Assigment of value for CNIE11 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE12_Pos                  _UINT32_(12)                                         /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE12_Msk                  (_UINT32_(0x1) << GPIO_CNEN_CNIE12_Pos)              /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE12(value)               (GPIO_CNEN_CNIE12_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE12_Pos)) /* Assigment of value for CNIE12 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE13_Pos                  _UINT32_(13)                                         /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE13_Msk                  (_UINT32_(0x1) << GPIO_CNEN_CNIE13_Pos)              /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE13(value)               (GPIO_CNEN_CNIE13_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE13_Pos)) /* Assigment of value for CNIE13 in the GPIO_CNEN register */
#define GPIO_CNEN_CNIE14_Pos                  _UINT32_(14)                                         /* (GPIO_CNEN)  Position */
#define GPIO_CNEN_CNIE14_Msk                  (_UINT32_(0x1) << GPIO_CNEN_CNIE14_Pos)              /* (GPIO_CNEN)  Mask */
#define GPIO_CNEN_CNIE14(value)               (GPIO_CNEN_CNIE14_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE14_Pos)) /* Assigment of value for CNIE14 in the GPIO_CNEN register */
#define GPIO_CNEN_Msk                         _UINT32_(0x00007FFF)                                 /* (GPIO_CNEN) Register Mask  */

#define GPIO_CNEN_CNIE_Pos                    _UINT32_(0)                                          /* (GPIO_CNEN Position)  */
#define GPIO_CNEN_CNIE_Msk                    (_UINT32_(0x7FFF) << GPIO_CNEN_CNIE_Pos)             /* (GPIO_CNEN Mask) CNIE */
#define GPIO_CNEN_CNIE(value)                 (GPIO_CNEN_CNIE_Msk & (_UINT32_(value) << GPIO_CNEN_CNIE_Pos)) 

/* -------- GPIO_CNENCLR : (GPIO Offset: 0x84) (R/W 32)  -------- */
#define GPIO_CNENCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNENCLR)   Reset Value */

#define GPIO_CNENCLR_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNENCLR) Register Mask  */


/* -------- GPIO_CNENSET : (GPIO Offset: 0x88) (R/W 32)  -------- */
#define GPIO_CNENSET_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNENSET)   Reset Value */

#define GPIO_CNENSET_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNENSET) Register Mask  */


/* -------- GPIO_CNENINV : (GPIO Offset: 0x8C) (R/W 32)  -------- */
#define GPIO_CNENINV_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNENINV)   Reset Value */

#define GPIO_CNENINV_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNENINV) Register Mask  */


/* -------- GPIO_CNSTAT : (GPIO Offset: 0x90) (R/W 32)  -------- */
#define GPIO_CNSTAT_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_CNSTAT)   Reset Value */

#define GPIO_CNSTAT_CNSTAT0_Pos               _UINT32_(0)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT0_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT0_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT0(value)            (GPIO_CNSTAT_CNSTAT0_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT0_Pos)) /* Assigment of value for CNSTAT0 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT1_Pos               _UINT32_(1)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT1_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT1_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT1(value)            (GPIO_CNSTAT_CNSTAT1_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT1_Pos)) /* Assigment of value for CNSTAT1 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT2_Pos               _UINT32_(2)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT2_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT2_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT2(value)            (GPIO_CNSTAT_CNSTAT2_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT2_Pos)) /* Assigment of value for CNSTAT2 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT3_Pos               _UINT32_(3)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT3_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT3_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT3(value)            (GPIO_CNSTAT_CNSTAT3_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT3_Pos)) /* Assigment of value for CNSTAT3 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT4_Pos               _UINT32_(4)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT4_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT4_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT4(value)            (GPIO_CNSTAT_CNSTAT4_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT4_Pos)) /* Assigment of value for CNSTAT4 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT5_Pos               _UINT32_(5)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT5_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT5_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT5(value)            (GPIO_CNSTAT_CNSTAT5_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT5_Pos)) /* Assigment of value for CNSTAT5 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT6_Pos               _UINT32_(6)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT6_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT6_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT6(value)            (GPIO_CNSTAT_CNSTAT6_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT6_Pos)) /* Assigment of value for CNSTAT6 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT7_Pos               _UINT32_(7)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT7_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT7_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT7(value)            (GPIO_CNSTAT_CNSTAT7_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT7_Pos)) /* Assigment of value for CNSTAT7 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT8_Pos               _UINT32_(8)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT8_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT8_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT8(value)            (GPIO_CNSTAT_CNSTAT8_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT8_Pos)) /* Assigment of value for CNSTAT8 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTATA_Pos               _UINT32_(9)                                          /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTATA_Msk               (_UINT32_(0x1) << GPIO_CNSTAT_CNSTATA_Pos)           /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTATA(value)            (GPIO_CNSTAT_CNSTATA_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTATA_Pos)) /* Assigment of value for CNSTATA in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT10_Pos              _UINT32_(10)                                         /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT10_Msk              (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT10_Pos)          /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT10(value)           (GPIO_CNSTAT_CNSTAT10_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT10_Pos)) /* Assigment of value for CNSTAT10 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT11_Pos              _UINT32_(11)                                         /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT11_Msk              (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT11_Pos)          /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT11(value)           (GPIO_CNSTAT_CNSTAT11_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT11_Pos)) /* Assigment of value for CNSTAT11 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT12_Pos              _UINT32_(12)                                         /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT12_Msk              (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT12_Pos)          /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT12(value)           (GPIO_CNSTAT_CNSTAT12_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT12_Pos)) /* Assigment of value for CNSTAT12 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT13_Pos              _UINT32_(13)                                         /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT13_Msk              (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT13_Pos)          /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT13(value)           (GPIO_CNSTAT_CNSTAT13_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT13_Pos)) /* Assigment of value for CNSTAT13 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_CNSTAT14_Pos              _UINT32_(14)                                         /* (GPIO_CNSTAT)  Position */
#define GPIO_CNSTAT_CNSTAT14_Msk              (_UINT32_(0x1) << GPIO_CNSTAT_CNSTAT14_Pos)          /* (GPIO_CNSTAT)  Mask */
#define GPIO_CNSTAT_CNSTAT14(value)           (GPIO_CNSTAT_CNSTAT14_Msk & (_UINT32_(value) << GPIO_CNSTAT_CNSTAT14_Pos)) /* Assigment of value for CNSTAT14 in the GPIO_CNSTAT register */
#define GPIO_CNSTAT_Msk                       _UINT32_(0x00007FFF)                                 /* (GPIO_CNSTAT) Register Mask  */


/* -------- GPIO_CNSTATCLR : (GPIO Offset: 0x94) (R/W 32)  -------- */
#define GPIO_CNSTATCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_CNSTATCLR)   Reset Value */

#define GPIO_CNSTATCLR_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_CNSTATCLR) Register Mask  */


/* -------- GPIO_CNSTATSET : (GPIO Offset: 0x98) (R/W 32)  -------- */
#define GPIO_CNSTATSET_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_CNSTATSET)   Reset Value */

#define GPIO_CNSTATSET_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_CNSTATSET) Register Mask  */


/* -------- GPIO_CNSTATINV : (GPIO Offset: 0x9C) (R/W 32)  -------- */
#define GPIO_CNSTATINV_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_CNSTATINV)   Reset Value */

#define GPIO_CNSTATINV_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_CNSTATINV) Register Mask  */


/* -------- GPIO_CNNE : (GPIO Offset: 0xA0) (R/W 32)  -------- */
#define GPIO_CNNE_RESETVALUE                  _UINT32_(0x00)                                       /*  (GPIO_CNNE)   Reset Value */

#define GPIO_CNNE_CNNE0_Pos                   _UINT32_(0)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE0_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE0_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE0(value)                (GPIO_CNNE_CNNE0_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE0_Pos)) /* Assigment of value for CNNE0 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE1_Pos                   _UINT32_(1)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE1_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE1_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE1(value)                (GPIO_CNNE_CNNE1_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE1_Pos)) /* Assigment of value for CNNE1 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE2_Pos                   _UINT32_(2)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE2_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE2_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE2(value)                (GPIO_CNNE_CNNE2_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE2_Pos)) /* Assigment of value for CNNE2 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE3_Pos                   _UINT32_(3)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE3_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE3_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE3(value)                (GPIO_CNNE_CNNE3_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE3_Pos)) /* Assigment of value for CNNE3 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE4_Pos                   _UINT32_(4)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE4_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE4_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE4(value)                (GPIO_CNNE_CNNE4_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE4_Pos)) /* Assigment of value for CNNE4 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE5_Pos                   _UINT32_(5)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE5_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE5_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE5(value)                (GPIO_CNNE_CNNE5_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE5_Pos)) /* Assigment of value for CNNE5 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE6_Pos                   _UINT32_(6)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE6_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE6_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE6(value)                (GPIO_CNNE_CNNE6_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE6_Pos)) /* Assigment of value for CNNE6 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE7_Pos                   _UINT32_(7)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE7_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE7_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE7(value)                (GPIO_CNNE_CNNE7_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE7_Pos)) /* Assigment of value for CNNE7 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE8_Pos                   _UINT32_(8)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE8_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE8_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE8(value)                (GPIO_CNNE_CNNE8_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE8_Pos)) /* Assigment of value for CNNE8 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE9_Pos                   _UINT32_(9)                                          /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE9_Msk                   (_UINT32_(0x1) << GPIO_CNNE_CNNE9_Pos)               /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE9(value)                (GPIO_CNNE_CNNE9_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE9_Pos)) /* Assigment of value for CNNE9 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE10_Pos                  _UINT32_(10)                                         /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE10_Msk                  (_UINT32_(0x1) << GPIO_CNNE_CNNE10_Pos)              /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE10(value)               (GPIO_CNNE_CNNE10_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE10_Pos)) /* Assigment of value for CNNE10 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE11_Pos                  _UINT32_(11)                                         /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE11_Msk                  (_UINT32_(0x1) << GPIO_CNNE_CNNE11_Pos)              /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE11(value)               (GPIO_CNNE_CNNE11_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE11_Pos)) /* Assigment of value for CNNE11 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE12_Pos                  _UINT32_(12)                                         /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE12_Msk                  (_UINT32_(0x1) << GPIO_CNNE_CNNE12_Pos)              /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE12(value)               (GPIO_CNNE_CNNE12_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE12_Pos)) /* Assigment of value for CNNE12 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE13_Pos                  _UINT32_(13)                                         /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE13_Msk                  (_UINT32_(0x1) << GPIO_CNNE_CNNE13_Pos)              /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE13(value)               (GPIO_CNNE_CNNE13_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE13_Pos)) /* Assigment of value for CNNE13 in the GPIO_CNNE register */
#define GPIO_CNNE_CNNE14_Pos                  _UINT32_(14)                                         /* (GPIO_CNNE)  Position */
#define GPIO_CNNE_CNNE14_Msk                  (_UINT32_(0x1) << GPIO_CNNE_CNNE14_Pos)              /* (GPIO_CNNE)  Mask */
#define GPIO_CNNE_CNNE14(value)               (GPIO_CNNE_CNNE14_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE14_Pos)) /* Assigment of value for CNNE14 in the GPIO_CNNE register */
#define GPIO_CNNE_Msk                         _UINT32_(0x00007FFF)                                 /* (GPIO_CNNE) Register Mask  */

#define GPIO_CNNE_CNNE_Pos                    _UINT32_(0)                                          /* (GPIO_CNNE Position)  */
#define GPIO_CNNE_CNNE_Msk                    (_UINT32_(0x7FFF) << GPIO_CNNE_CNNE_Pos)             /* (GPIO_CNNE Mask) CNNE */
#define GPIO_CNNE_CNNE(value)                 (GPIO_CNNE_CNNE_Msk & (_UINT32_(value) << GPIO_CNNE_CNNE_Pos)) 

/* -------- GPIO_CNNECLR : (GPIO Offset: 0xA4) (R/W 32)  -------- */
#define GPIO_CNNECLR_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNNECLR)   Reset Value */

#define GPIO_CNNECLR_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNNECLR) Register Mask  */


/* -------- GPIO_CNNESET : (GPIO Offset: 0xA8) (R/W 32)  -------- */
#define GPIO_CNNESET_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNNESET)   Reset Value */

#define GPIO_CNNESET_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNNESET) Register Mask  */


/* -------- GPIO_CNNEINV : (GPIO Offset: 0xAC) (R/W 32)  -------- */
#define GPIO_CNNEINV_RESETVALUE               _UINT32_(0x00)                                       /*  (GPIO_CNNEINV)   Reset Value */

#define GPIO_CNNEINV_Msk                      _UINT32_(0x00000000)                                 /* (GPIO_CNNEINV) Register Mask  */


/* -------- GPIO_CNF : (GPIO Offset: 0xB0) (R/W 32)  -------- */
#define GPIO_CNF_RESETVALUE                   _UINT32_(0x00)                                       /*  (GPIO_CNF)   Reset Value */

#define GPIO_CNF_CNF0_Pos                     _UINT32_(0)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF0_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF0_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF0(value)                  (GPIO_CNF_CNF0_Msk & (_UINT32_(value) << GPIO_CNF_CNF0_Pos)) /* Assigment of value for CNF0 in the GPIO_CNF register */
#define GPIO_CNF_CNF1_Pos                     _UINT32_(1)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF1_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF1_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF1(value)                  (GPIO_CNF_CNF1_Msk & (_UINT32_(value) << GPIO_CNF_CNF1_Pos)) /* Assigment of value for CNF1 in the GPIO_CNF register */
#define GPIO_CNF_CNF2_Pos                     _UINT32_(2)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF2_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF2_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF2(value)                  (GPIO_CNF_CNF2_Msk & (_UINT32_(value) << GPIO_CNF_CNF2_Pos)) /* Assigment of value for CNF2 in the GPIO_CNF register */
#define GPIO_CNF_CNF3_Pos                     _UINT32_(3)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF3_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF3_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF3(value)                  (GPIO_CNF_CNF3_Msk & (_UINT32_(value) << GPIO_CNF_CNF3_Pos)) /* Assigment of value for CNF3 in the GPIO_CNF register */
#define GPIO_CNF_CNF4_Pos                     _UINT32_(4)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF4_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF4_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF4(value)                  (GPIO_CNF_CNF4_Msk & (_UINT32_(value) << GPIO_CNF_CNF4_Pos)) /* Assigment of value for CNF4 in the GPIO_CNF register */
#define GPIO_CNF_CNF5_Pos                     _UINT32_(5)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF5_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF5_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF5(value)                  (GPIO_CNF_CNF5_Msk & (_UINT32_(value) << GPIO_CNF_CNF5_Pos)) /* Assigment of value for CNF5 in the GPIO_CNF register */
#define GPIO_CNF_CNF6_Pos                     _UINT32_(6)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF6_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF6_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF6(value)                  (GPIO_CNF_CNF6_Msk & (_UINT32_(value) << GPIO_CNF_CNF6_Pos)) /* Assigment of value for CNF6 in the GPIO_CNF register */
#define GPIO_CNF_CNF7_Pos                     _UINT32_(7)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF7_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF7_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF7(value)                  (GPIO_CNF_CNF7_Msk & (_UINT32_(value) << GPIO_CNF_CNF7_Pos)) /* Assigment of value for CNF7 in the GPIO_CNF register */
#define GPIO_CNF_CNF8_Pos                     _UINT32_(8)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF8_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF8_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF8(value)                  (GPIO_CNF_CNF8_Msk & (_UINT32_(value) << GPIO_CNF_CNF8_Pos)) /* Assigment of value for CNF8 in the GPIO_CNF register */
#define GPIO_CNF_CNF9_Pos                     _UINT32_(9)                                          /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF9_Msk                     (_UINT32_(0x1) << GPIO_CNF_CNF9_Pos)                 /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF9(value)                  (GPIO_CNF_CNF9_Msk & (_UINT32_(value) << GPIO_CNF_CNF9_Pos)) /* Assigment of value for CNF9 in the GPIO_CNF register */
#define GPIO_CNF_CNF10_Pos                    _UINT32_(10)                                         /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF10_Msk                    (_UINT32_(0x1) << GPIO_CNF_CNF10_Pos)                /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF10(value)                 (GPIO_CNF_CNF10_Msk & (_UINT32_(value) << GPIO_CNF_CNF10_Pos)) /* Assigment of value for CNF10 in the GPIO_CNF register */
#define GPIO_CNF_CNF11_Pos                    _UINT32_(11)                                         /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF11_Msk                    (_UINT32_(0x1) << GPIO_CNF_CNF11_Pos)                /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF11(value)                 (GPIO_CNF_CNF11_Msk & (_UINT32_(value) << GPIO_CNF_CNF11_Pos)) /* Assigment of value for CNF11 in the GPIO_CNF register */
#define GPIO_CNF_CNF12_Pos                    _UINT32_(12)                                         /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF12_Msk                    (_UINT32_(0x1) << GPIO_CNF_CNF12_Pos)                /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF12(value)                 (GPIO_CNF_CNF12_Msk & (_UINT32_(value) << GPIO_CNF_CNF12_Pos)) /* Assigment of value for CNF12 in the GPIO_CNF register */
#define GPIO_CNF_CNF13_Pos                    _UINT32_(13)                                         /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF13_Msk                    (_UINT32_(0x1) << GPIO_CNF_CNF13_Pos)                /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF13(value)                 (GPIO_CNF_CNF13_Msk & (_UINT32_(value) << GPIO_CNF_CNF13_Pos)) /* Assigment of value for CNF13 in the GPIO_CNF register */
#define GPIO_CNF_CNF14_Pos                    _UINT32_(14)                                         /* (GPIO_CNF)  Position */
#define GPIO_CNF_CNF14_Msk                    (_UINT32_(0x1) << GPIO_CNF_CNF14_Pos)                /* (GPIO_CNF)  Mask */
#define GPIO_CNF_CNF14(value)                 (GPIO_CNF_CNF14_Msk & (_UINT32_(value) << GPIO_CNF_CNF14_Pos)) /* Assigment of value for CNF14 in the GPIO_CNF register */
#define GPIO_CNF_Msk                          _UINT32_(0x00007FFF)                                 /* (GPIO_CNF) Register Mask  */

#define GPIO_CNF_CNF_Pos                      _UINT32_(0)                                          /* (GPIO_CNF Position)  */
#define GPIO_CNF_CNF_Msk                      (_UINT32_(0x7FFF) << GPIO_CNF_CNF_Pos)               /* (GPIO_CNF Mask) CNF */
#define GPIO_CNF_CNF(value)                   (GPIO_CNF_CNF_Msk & (_UINT32_(value) << GPIO_CNF_CNF_Pos)) 

/* -------- GPIO_CNFCLR : (GPIO Offset: 0xB4) (R/W 32)  -------- */
#define GPIO_CNFCLR_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_CNFCLR)   Reset Value */

#define GPIO_CNFCLR_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_CNFCLR) Register Mask  */


/* -------- GPIO_CNFSET : (GPIO Offset: 0xB8) (R/W 32)  -------- */
#define GPIO_CNFSET_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_CNFSET)   Reset Value */

#define GPIO_CNFSET_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_CNFSET) Register Mask  */


/* -------- GPIO_CNFINV : (GPIO Offset: 0xBC) (R/W 32)  -------- */
#define GPIO_CNFINV_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_CNFINV)   Reset Value */

#define GPIO_CNFINV_Msk                       _UINT32_(0x00000000)                                 /* (GPIO_CNFINV) Register Mask  */


/* -------- GPIO_SRCON0 : (GPIO Offset: 0xC0) (R/W 32)  -------- */
#define GPIO_SRCON0_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_SRCON0)   Reset Value */

#define GPIO_SRCON0_SR00_Pos                  _UINT32_(0)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR00_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR00_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR00(value)               (GPIO_SRCON0_SR00_Msk & (_UINT32_(value) << GPIO_SRCON0_SR00_Pos)) /* Assigment of value for SR00 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR01_Pos                  _UINT32_(1)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR01_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR01_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR01(value)               (GPIO_SRCON0_SR01_Msk & (_UINT32_(value) << GPIO_SRCON0_SR01_Pos)) /* Assigment of value for SR01 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR02_Pos                  _UINT32_(2)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR02_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR02_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR02(value)               (GPIO_SRCON0_SR02_Msk & (_UINT32_(value) << GPIO_SRCON0_SR02_Pos)) /* Assigment of value for SR02 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR03_Pos                  _UINT32_(3)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR03_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR03_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR03(value)               (GPIO_SRCON0_SR03_Msk & (_UINT32_(value) << GPIO_SRCON0_SR03_Pos)) /* Assigment of value for SR03 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR04_Pos                  _UINT32_(4)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR04_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR04_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR04(value)               (GPIO_SRCON0_SR04_Msk & (_UINT32_(value) << GPIO_SRCON0_SR04_Pos)) /* Assigment of value for SR04 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR05_Pos                  _UINT32_(5)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR05_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR05_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR05(value)               (GPIO_SRCON0_SR05_Msk & (_UINT32_(value) << GPIO_SRCON0_SR05_Pos)) /* Assigment of value for SR05 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR06_Pos                  _UINT32_(6)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR06_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR06_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR06(value)               (GPIO_SRCON0_SR06_Msk & (_UINT32_(value) << GPIO_SRCON0_SR06_Pos)) /* Assigment of value for SR06 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR07_Pos                  _UINT32_(7)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR07_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR07_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR07(value)               (GPIO_SRCON0_SR07_Msk & (_UINT32_(value) << GPIO_SRCON0_SR07_Pos)) /* Assigment of value for SR07 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR08_Pos                  _UINT32_(8)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR08_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR08_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR08(value)               (GPIO_SRCON0_SR08_Msk & (_UINT32_(value) << GPIO_SRCON0_SR08_Pos)) /* Assigment of value for SR08 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR09_Pos                  _UINT32_(9)                                          /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR09_Msk                  (_UINT32_(0x1) << GPIO_SRCON0_SR09_Pos)              /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR09(value)               (GPIO_SRCON0_SR09_Msk & (_UINT32_(value) << GPIO_SRCON0_SR09_Pos)) /* Assigment of value for SR09 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR010_Pos                 _UINT32_(10)                                         /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR010_Msk                 (_UINT32_(0x1) << GPIO_SRCON0_SR010_Pos)             /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR010(value)              (GPIO_SRCON0_SR010_Msk & (_UINT32_(value) << GPIO_SRCON0_SR010_Pos)) /* Assigment of value for SR010 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR011_Pos                 _UINT32_(11)                                         /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR011_Msk                 (_UINT32_(0x1) << GPIO_SRCON0_SR011_Pos)             /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR011(value)              (GPIO_SRCON0_SR011_Msk & (_UINT32_(value) << GPIO_SRCON0_SR011_Pos)) /* Assigment of value for SR011 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR012_Pos                 _UINT32_(12)                                         /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR012_Msk                 (_UINT32_(0x1) << GPIO_SRCON0_SR012_Pos)             /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR012(value)              (GPIO_SRCON0_SR012_Msk & (_UINT32_(value) << GPIO_SRCON0_SR012_Pos)) /* Assigment of value for SR012 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR013_Pos                 _UINT32_(13)                                         /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR013_Msk                 (_UINT32_(0x1) << GPIO_SRCON0_SR013_Pos)             /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR013(value)              (GPIO_SRCON0_SR013_Msk & (_UINT32_(value) << GPIO_SRCON0_SR013_Pos)) /* Assigment of value for SR013 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_SR014_Pos                 _UINT32_(14)                                         /* (GPIO_SRCON0)  Position */
#define GPIO_SRCON0_SR014_Msk                 (_UINT32_(0x1) << GPIO_SRCON0_SR014_Pos)             /* (GPIO_SRCON0)  Mask */
#define GPIO_SRCON0_SR014(value)              (GPIO_SRCON0_SR014_Msk & (_UINT32_(value) << GPIO_SRCON0_SR014_Pos)) /* Assigment of value for SR014 in the GPIO_SRCON0 register */
#define GPIO_SRCON0_Msk                       _UINT32_(0x00007FFF)                                 /* (GPIO_SRCON0) Register Mask  */

#define GPIO_SRCON0_SR_Pos                    _UINT32_(0)                                          /* (GPIO_SRCON0 Position)  */
#define GPIO_SRCON0_SR_Msk                    (_UINT32_(0x7FFF) << GPIO_SRCON0_SR_Pos)             /* (GPIO_SRCON0 Mask) SR */
#define GPIO_SRCON0_SR(value)                 (GPIO_SRCON0_SR_Msk & (_UINT32_(value) << GPIO_SRCON0_SR_Pos)) 

/* -------- GPIO_SRCON0CLR : (GPIO Offset: 0xC4) (R/W 32)  -------- */
#define GPIO_SRCON0CLR_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_SRCON0CLR)   Reset Value */

#define GPIO_SRCON0CLR_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_SRCON0CLR) Register Mask  */


/* -------- GPIO_SRCON0SET : (GPIO Offset: 0xC8) (R/W 32)  -------- */
#define GPIO_SRCON0SET_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_SRCON0SET)   Reset Value */

#define GPIO_SRCON0SET_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_SRCON0SET) Register Mask  */


/* -------- GPIO_SRCON0INV : (GPIO Offset: 0xCC) (R/W 32)  -------- */
#define GPIO_SRCON0INV_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_SRCON0INV)   Reset Value */

#define GPIO_SRCON0INV_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_SRCON0INV) Register Mask  */


/* -------- GPIO_SRCON1 : (GPIO Offset: 0xD0) (R/W 32)  -------- */
#define GPIO_SRCON1_RESETVALUE                _UINT32_(0x00)                                       /*  (GPIO_SRCON1)   Reset Value */

#define GPIO_SRCON1_SR10_Pos                  _UINT32_(0)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR10_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR10_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR10(value)               (GPIO_SRCON1_SR10_Msk & (_UINT32_(value) << GPIO_SRCON1_SR10_Pos)) /* Assigment of value for SR10 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR11_Pos                  _UINT32_(1)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR11_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR11_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR11(value)               (GPIO_SRCON1_SR11_Msk & (_UINT32_(value) << GPIO_SRCON1_SR11_Pos)) /* Assigment of value for SR11 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR12_Pos                  _UINT32_(2)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR12_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR12_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR12(value)               (GPIO_SRCON1_SR12_Msk & (_UINT32_(value) << GPIO_SRCON1_SR12_Pos)) /* Assigment of value for SR12 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR13_Pos                  _UINT32_(3)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR13_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR13_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR13(value)               (GPIO_SRCON1_SR13_Msk & (_UINT32_(value) << GPIO_SRCON1_SR13_Pos)) /* Assigment of value for SR13 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR14_Pos                  _UINT32_(4)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR14_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR14_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR14(value)               (GPIO_SRCON1_SR14_Msk & (_UINT32_(value) << GPIO_SRCON1_SR14_Pos)) /* Assigment of value for SR14 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR15_Pos                  _UINT32_(5)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR15_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR15_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR15(value)               (GPIO_SRCON1_SR15_Msk & (_UINT32_(value) << GPIO_SRCON1_SR15_Pos)) /* Assigment of value for SR15 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR16_Pos                  _UINT32_(6)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR16_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR16_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR16(value)               (GPIO_SRCON1_SR16_Msk & (_UINT32_(value) << GPIO_SRCON1_SR16_Pos)) /* Assigment of value for SR16 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR17_Pos                  _UINT32_(7)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR17_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR17_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR17(value)               (GPIO_SRCON1_SR17_Msk & (_UINT32_(value) << GPIO_SRCON1_SR17_Pos)) /* Assigment of value for SR17 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR18_Pos                  _UINT32_(8)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR18_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR18_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR18(value)               (GPIO_SRCON1_SR18_Msk & (_UINT32_(value) << GPIO_SRCON1_SR18_Pos)) /* Assigment of value for SR18 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR19_Pos                  _UINT32_(9)                                          /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR19_Msk                  (_UINT32_(0x1) << GPIO_SRCON1_SR19_Pos)              /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR19(value)               (GPIO_SRCON1_SR19_Msk & (_UINT32_(value) << GPIO_SRCON1_SR19_Pos)) /* Assigment of value for SR19 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR110_Pos                 _UINT32_(10)                                         /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR110_Msk                 (_UINT32_(0x1) << GPIO_SRCON1_SR110_Pos)             /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR110(value)              (GPIO_SRCON1_SR110_Msk & (_UINT32_(value) << GPIO_SRCON1_SR110_Pos)) /* Assigment of value for SR110 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR111_Pos                 _UINT32_(11)                                         /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR111_Msk                 (_UINT32_(0x1) << GPIO_SRCON1_SR111_Pos)             /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR111(value)              (GPIO_SRCON1_SR111_Msk & (_UINT32_(value) << GPIO_SRCON1_SR111_Pos)) /* Assigment of value for SR111 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR112_Pos                 _UINT32_(12)                                         /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR112_Msk                 (_UINT32_(0x1) << GPIO_SRCON1_SR112_Pos)             /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR112(value)              (GPIO_SRCON1_SR112_Msk & (_UINT32_(value) << GPIO_SRCON1_SR112_Pos)) /* Assigment of value for SR112 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR113_Pos                 _UINT32_(13)                                         /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR113_Msk                 (_UINT32_(0x1) << GPIO_SRCON1_SR113_Pos)             /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR113(value)              (GPIO_SRCON1_SR113_Msk & (_UINT32_(value) << GPIO_SRCON1_SR113_Pos)) /* Assigment of value for SR113 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_SR114_Pos                 _UINT32_(14)                                         /* (GPIO_SRCON1)  Position */
#define GPIO_SRCON1_SR114_Msk                 (_UINT32_(0x1) << GPIO_SRCON1_SR114_Pos)             /* (GPIO_SRCON1)  Mask */
#define GPIO_SRCON1_SR114(value)              (GPIO_SRCON1_SR114_Msk & (_UINT32_(value) << GPIO_SRCON1_SR114_Pos)) /* Assigment of value for SR114 in the GPIO_SRCON1 register */
#define GPIO_SRCON1_Msk                       _UINT32_(0x00007FFF)                                 /* (GPIO_SRCON1) Register Mask  */

#define GPIO_SRCON1_SR_Pos                    _UINT32_(0)                                          /* (GPIO_SRCON1 Position)  */
#define GPIO_SRCON1_SR_Msk                    (_UINT32_(0x7FFF) << GPIO_SRCON1_SR_Pos)             /* (GPIO_SRCON1 Mask) SR */
#define GPIO_SRCON1_SR(value)                 (GPIO_SRCON1_SR_Msk & (_UINT32_(value) << GPIO_SRCON1_SR_Pos)) 

/* -------- GPIO_SRCON1CLR : (GPIO Offset: 0xD4) (R/W 32)  -------- */
#define GPIO_SRCON1CLR_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_SRCON1CLR)   Reset Value */

#define GPIO_SRCON1CLR_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_SRCON1CLR) Register Mask  */


/* -------- GPIO_SRCON1SET : (GPIO Offset: 0xD8) (R/W 32)  -------- */
#define GPIO_SRCON1SET_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_SRCON1SET)   Reset Value */

#define GPIO_SRCON1SET_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_SRCON1SET) Register Mask  */


/* -------- GPIO_SRCON1INV : (GPIO Offset: 0xDC) (R/W 32)  -------- */
#define GPIO_SRCON1INV_RESETVALUE             _UINT32_(0x00)                                       /*  (GPIO_SRCON1INV)   Reset Value */

#define GPIO_SRCON1INV_Msk                    _UINT32_(0x00000000)                                 /* (GPIO_SRCON1INV) Register Mask  */


/** \brief GPIO register offsets definitions */
#define GPIO_ANSEL_REG_OFST            _UINT32_(0x00)      /* (GPIO_ANSEL)  Offset */
#define GPIO_ANSELCLR_REG_OFST         _UINT32_(0x04)      /* (GPIO_ANSELCLR)  Offset */
#define GPIO_ANSELSET_REG_OFST         _UINT32_(0x08)      /* (GPIO_ANSELSET)  Offset */
#define GPIO_ANSELINV_REG_OFST         _UINT32_(0x0C)      /* (GPIO_ANSELINV)  Offset */
#define GPIO_TRIS_REG_OFST             _UINT32_(0x10)      /* (GPIO_TRIS)  Offset */
#define GPIO_TRISCLR_REG_OFST          _UINT32_(0x14)      /* (GPIO_TRISCLR)  Offset */
#define GPIO_TRISSET_REG_OFST          _UINT32_(0x18)      /* (GPIO_TRISSET)  Offset */
#define GPIO_TRISINV_REG_OFST          _UINT32_(0x1C)      /* (GPIO_TRISINV)  Offset */
#define GPIO_PORT_REG_OFST             _UINT32_(0x20)      /* (GPIO_PORT)  Offset */
#define GPIO_PORTCLR_REG_OFST          _UINT32_(0x24)      /* (GPIO_PORTCLR)  Offset */
#define GPIO_PORTSET_REG_OFST          _UINT32_(0x28)      /* (GPIO_PORTSET)  Offset */
#define GPIO_PORTINV_REG_OFST          _UINT32_(0x2C)      /* (GPIO_PORTINV)  Offset */
#define GPIO_LAT_REG_OFST              _UINT32_(0x30)      /* (GPIO_LAT)  Offset */
#define GPIO_LATCLR_REG_OFST           _UINT32_(0x34)      /* (GPIO_LATCLR)  Offset */
#define GPIO_LATSET_REG_OFST           _UINT32_(0x38)      /* (GPIO_LATSET)  Offset */
#define GPIO_LATINV_REG_OFST           _UINT32_(0x3C)      /* (GPIO_LATINV)  Offset */
#define GPIO_ODC_REG_OFST              _UINT32_(0x40)      /* (GPIO_ODC)  Offset */
#define GPIO_ODCCLR_REG_OFST           _UINT32_(0x44)      /* (GPIO_ODCCLR)  Offset */
#define GPIO_ODCSET_REG_OFST           _UINT32_(0x48)      /* (GPIO_ODCSET)  Offset */
#define GPIO_ODCINV_REG_OFST           _UINT32_(0x4C)      /* (GPIO_ODCINV)  Offset */
#define GPIO_CNPU_REG_OFST             _UINT32_(0x50)      /* (GPIO_CNPU)  Offset */
#define GPIO_CNPUCLR_REG_OFST          _UINT32_(0x54)      /* (GPIO_CNPUCLR)  Offset */
#define GPIO_CNPUSET_REG_OFST          _UINT32_(0x58)      /* (GPIO_CNPUSET)  Offset */
#define GPIO_CNPUINV_REG_OFST          _UINT32_(0x5C)      /* (GPIO_CNPUINV)  Offset */
#define GPIO_CNPD_REG_OFST             _UINT32_(0x60)      /* (GPIO_CNPD)  Offset */
#define GPIO_CNPDCLR_REG_OFST          _UINT32_(0x64)      /* (GPIO_CNPDCLR)  Offset */
#define GPIO_CNPDSET_REG_OFST          _UINT32_(0x68)      /* (GPIO_CNPDSET)  Offset */
#define GPIO_CNPDINV_REG_OFST          _UINT32_(0x6C)      /* (GPIO_CNPDINV)  Offset */
#define GPIO_CNCON_REG_OFST            _UINT32_(0x70)      /* (GPIO_CNCON)  Offset */
#define GPIO_CNCONCLR_REG_OFST         _UINT32_(0x74)      /* (GPIO_CNCONCLR)  Offset */
#define GPIO_CNCONSET_REG_OFST         _UINT32_(0x78)      /* (GPIO_CNCONSET)  Offset */
#define GPIO_CNCONINV_REG_OFST         _UINT32_(0x7C)      /* (GPIO_CNCONINV)  Offset */
#define GPIO_CNEN_REG_OFST             _UINT32_(0x80)      /* (GPIO_CNEN)  Offset */
#define GPIO_CNENCLR_REG_OFST          _UINT32_(0x84)      /* (GPIO_CNENCLR)  Offset */
#define GPIO_CNENSET_REG_OFST          _UINT32_(0x88)      /* (GPIO_CNENSET)  Offset */
#define GPIO_CNENINV_REG_OFST          _UINT32_(0x8C)      /* (GPIO_CNENINV)  Offset */
#define GPIO_CNSTAT_REG_OFST           _UINT32_(0x90)      /* (GPIO_CNSTAT)  Offset */
#define GPIO_CNSTATCLR_REG_OFST        _UINT32_(0x94)      /* (GPIO_CNSTATCLR)  Offset */
#define GPIO_CNSTATSET_REG_OFST        _UINT32_(0x98)      /* (GPIO_CNSTATSET)  Offset */
#define GPIO_CNSTATINV_REG_OFST        _UINT32_(0x9C)      /* (GPIO_CNSTATINV)  Offset */
#define GPIO_CNNE_REG_OFST             _UINT32_(0xA0)      /* (GPIO_CNNE)  Offset */
#define GPIO_CNNECLR_REG_OFST          _UINT32_(0xA4)      /* (GPIO_CNNECLR)  Offset */
#define GPIO_CNNESET_REG_OFST          _UINT32_(0xA8)      /* (GPIO_CNNESET)  Offset */
#define GPIO_CNNEINV_REG_OFST          _UINT32_(0xAC)      /* (GPIO_CNNEINV)  Offset */
#define GPIO_CNF_REG_OFST              _UINT32_(0xB0)      /* (GPIO_CNF)  Offset */
#define GPIO_CNFCLR_REG_OFST           _UINT32_(0xB4)      /* (GPIO_CNFCLR)  Offset */
#define GPIO_CNFSET_REG_OFST           _UINT32_(0xB8)      /* (GPIO_CNFSET)  Offset */
#define GPIO_CNFINV_REG_OFST           _UINT32_(0xBC)      /* (GPIO_CNFINV)  Offset */
#define GPIO_SRCON0_REG_OFST           _UINT32_(0xC0)      /* (GPIO_SRCON0)  Offset */
#define GPIO_SRCON0CLR_REG_OFST        _UINT32_(0xC4)      /* (GPIO_SRCON0CLR)  Offset */
#define GPIO_SRCON0SET_REG_OFST        _UINT32_(0xC8)      /* (GPIO_SRCON0SET)  Offset */
#define GPIO_SRCON0INV_REG_OFST        _UINT32_(0xCC)      /* (GPIO_SRCON0INV)  Offset */
#define GPIO_SRCON1_REG_OFST           _UINT32_(0xD0)      /* (GPIO_SRCON1)  Offset */
#define GPIO_SRCON1CLR_REG_OFST        _UINT32_(0xD4)      /* (GPIO_SRCON1CLR)  Offset */
#define GPIO_SRCON1SET_REG_OFST        _UINT32_(0xD8)      /* (GPIO_SRCON1SET)  Offset */
#define GPIO_SRCON1INV_REG_OFST        _UINT32_(0xDC)      /* (GPIO_SRCON1INV)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief GPIO register API structure */
typedef struct
{
  __IO  uint32_t                       GPIO_ANSEL;         /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       GPIO_ANSELCLR;      /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       GPIO_ANSELSET;      /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       GPIO_ANSELINV;      /**< Offset: 0x0C (R/W  32)  */
  __IO  uint32_t                       GPIO_TRIS;          /**< Offset: 0x10 (R/W  32)  */
  __IO  uint32_t                       GPIO_TRISCLR;       /**< Offset: 0x14 (R/W  32)  */
  __IO  uint32_t                       GPIO_TRISSET;       /**< Offset: 0x18 (R/W  32)  */
  __IO  uint32_t                       GPIO_TRISINV;       /**< Offset: 0x1C (R/W  32)  */
  __IO  uint32_t                       GPIO_PORT;          /**< Offset: 0x20 (R/W  32)  */
  __IO  uint32_t                       GPIO_PORTCLR;       /**< Offset: 0x24 (R/W  32)  */
  __IO  uint32_t                       GPIO_PORTSET;       /**< Offset: 0x28 (R/W  32)  */
  __IO  uint32_t                       GPIO_PORTINV;       /**< Offset: 0x2C (R/W  32)  */
  __IO  uint32_t                       GPIO_LAT;           /**< Offset: 0x30 (R/W  32)  */
  __IO  uint32_t                       GPIO_LATCLR;        /**< Offset: 0x34 (R/W  32)  */
  __IO  uint32_t                       GPIO_LATSET;        /**< Offset: 0x38 (R/W  32)  */
  __IO  uint32_t                       GPIO_LATINV;        /**< Offset: 0x3C (R/W  32)  */
  __IO  uint32_t                       GPIO_ODC;           /**< Offset: 0x40 (R/W  32)  */
  __IO  uint32_t                       GPIO_ODCCLR;        /**< Offset: 0x44 (R/W  32)  */
  __IO  uint32_t                       GPIO_ODCSET;        /**< Offset: 0x48 (R/W  32)  */
  __IO  uint32_t                       GPIO_ODCINV;        /**< Offset: 0x4C (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPU;          /**< Offset: 0x50 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPUCLR;       /**< Offset: 0x54 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPUSET;       /**< Offset: 0x58 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPUINV;       /**< Offset: 0x5C (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPD;          /**< Offset: 0x60 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPDCLR;       /**< Offset: 0x64 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPDSET;       /**< Offset: 0x68 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNPDINV;       /**< Offset: 0x6C (R/W  32)  */
  __IO  uint32_t                       GPIO_CNCON;         /**< Offset: 0x70 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNCONCLR;      /**< Offset: 0x74 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNCONSET;      /**< Offset: 0x78 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNCONINV;      /**< Offset: 0x7C (R/W  32)  */
  __IO  uint32_t                       GPIO_CNEN;          /**< Offset: 0x80 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNENCLR;       /**< Offset: 0x84 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNENSET;       /**< Offset: 0x88 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNENINV;       /**< Offset: 0x8C (R/W  32)  */
  __IO  uint32_t                       GPIO_CNSTAT;        /**< Offset: 0x90 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNSTATCLR;     /**< Offset: 0x94 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNSTATSET;     /**< Offset: 0x98 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNSTATINV;     /**< Offset: 0x9C (R/W  32)  */
  __IO  uint32_t                       GPIO_CNNE;          /**< Offset: 0xA0 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNNECLR;       /**< Offset: 0xA4 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNNESET;       /**< Offset: 0xA8 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNNEINV;       /**< Offset: 0xAC (R/W  32)  */
  __IO  uint32_t                       GPIO_CNF;           /**< Offset: 0xB0 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNFCLR;        /**< Offset: 0xB4 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNFSET;        /**< Offset: 0xB8 (R/W  32)  */
  __IO  uint32_t                       GPIO_CNFINV;        /**< Offset: 0xBC (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON0;        /**< Offset: 0xC0 (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON0CLR;     /**< Offset: 0xC4 (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON0SET;     /**< Offset: 0xC8 (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON0INV;     /**< Offset: 0xCC (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON1;        /**< Offset: 0xD0 (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON1CLR;     /**< Offset: 0xD4 (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON1SET;     /**< Offset: 0xD8 (R/W  32)  */
  __IO  uint32_t                       GPIO_SRCON1INV;     /**< Offset: 0xDC (R/W  32)  */
} gpio_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_GPIO_COMPONENT_H_ */
