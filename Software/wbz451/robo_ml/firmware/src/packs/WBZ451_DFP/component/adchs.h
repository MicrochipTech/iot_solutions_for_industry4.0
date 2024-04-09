/*
 * Component description for ADCHS
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
#ifndef _BZ45_ADCHS_COMPONENT_H_
#define _BZ45_ADCHS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ADCHS                                        */
/* ************************************************************************** */

/* -------- ADCHS_ADCCON1 : (ADCHS Offset: 0x00) (R/W 32)  -------- */
#define ADCHS_ADCCON1_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCON1)   Reset Value */

#define ADCHS_ADCCON1_DMABL_Pos               _UINT32_(0)                                          /* (ADCHS_ADCCON1) DMA to System RAM Buffer Length Size bits Position */
#define ADCHS_ADCCON1_DMABL_Msk               (_UINT32_(0x7) << ADCHS_ADCCON1_DMABL_Pos)           /* (ADCHS_ADCCON1) DMA to System RAM Buffer Length Size bits Mask */
#define ADCHS_ADCCON1_DMABL(value)            (ADCHS_ADCCON1_DMABL_Msk & (_UINT32_(value) << ADCHS_ADCCON1_DMABL_Pos)) /* Assigment of value for DMABL in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_DMABL_128_DMABL_Val   _UINT32_(0x7)                                        /* (ADCHS_ADCCON1) Allocates 128 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_64_DMABL_Val    _UINT32_(0x6)                                        /* (ADCHS_ADCCON1) Allocates 64 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_32_DMABL_Val    _UINT32_(0x5)                                        /* (ADCHS_ADCCON1) Allocates 32 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_16_DMABL_Val    _UINT32_(0x4)                                        /* (ADCHS_ADCCON1) Allocates 16 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_8_DMABL_Val     _UINT32_(0x3)                                        /* (ADCHS_ADCCON1) Allocates 8 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_4_DMABL_Val     _UINT32_(0x2)                                        /* (ADCHS_ADCCON1) Allocates 4 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_2_DMABL_Val     _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) Allocates 2 locations in system memory to each analog input  */
#define   ADCHS_ADCCON1_DMABL_1_DMABL_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) Allocates 1 location in system memory to each analog input  */
#define ADCHS_ADCCON1_DMABL_128_DMABL         (ADCHS_ADCCON1_DMABL_128_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 128 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_64_DMABL          (ADCHS_ADCCON1_DMABL_64_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 64 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_32_DMABL          (ADCHS_ADCCON1_DMABL_32_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 32 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_16_DMABL          (ADCHS_ADCCON1_DMABL_16_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 16 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_8_DMABL           (ADCHS_ADCCON1_DMABL_8_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 8 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_4_DMABL           (ADCHS_ADCCON1_DMABL_4_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 4 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_2_DMABL           (ADCHS_ADCCON1_DMABL_2_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 2 locations in system memory to each analog input Position  */
#define ADCHS_ADCCON1_DMABL_1_DMABL           (ADCHS_ADCCON1_DMABL_1_DMABL_Val << ADCHS_ADCCON1_DMABL_Pos) /* (ADCHS_ADCCON1) Allocates 1 location in system memory to each analog input Position  */
#define ADCHS_ADCCON1_STRGLVL_Pos             _UINT32_(3)                                          /* (ADCHS_ADCCON1) Scan Trigger High Level/Positive Edge Sensitivity bit Position */
#define ADCHS_ADCCON1_STRGLVL_Msk             (_UINT32_(0x1) << ADCHS_ADCCON1_STRGLVL_Pos)         /* (ADCHS_ADCCON1) Scan Trigger High Level/Positive Edge Sensitivity bit Mask */
#define ADCHS_ADCCON1_STRGLVL(value)          (ADCHS_ADCCON1_STRGLVL_Msk & (_UINT32_(value) << ADCHS_ADCCON1_STRGLVL_Pos)) /* Assigment of value for STRGLVL in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_STRGLVL_SCTRIG_HIGH_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) Scan trigger is high level sensitive. Once STRIG mode is selected the scan trigger will continue for all selected analog inputs  */
#define   ADCHS_ADCCON1_STRGLVL_SCTRIG_POSEDGE_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) Scan trigger is positive edge sensitive. Once STRIG mode is selected only a single scan trigger will be generated which will complete the scan of all selected analog inputs. (TRGSRCx in the ADCTRGx register)  */
#define ADCHS_ADCCON1_STRGLVL_SCTRIG_HIGH     (ADCHS_ADCCON1_STRGLVL_SCTRIG_HIGH_Val << ADCHS_ADCCON1_STRGLVL_Pos) /* (ADCHS_ADCCON1) Scan trigger is high level sensitive. Once STRIG mode is selected the scan trigger will continue for all selected analog inputs Position  */
#define ADCHS_ADCCON1_STRGLVL_SCTRIG_POSEDGE  (ADCHS_ADCCON1_STRGLVL_SCTRIG_POSEDGE_Val << ADCHS_ADCCON1_STRGLVL_Pos) /* (ADCHS_ADCCON1) Scan trigger is positive edge sensitive. Once STRIG mode is selected only a single scan trigger will be generated which will complete the scan of all selected analog inputs. (TRGSRCx in the ADCTRGx register) Position  */
#define ADCHS_ADCCON1_IRQVS_Pos               _UINT32_(4)                                          /* (ADCHS_ADCCON1) Interrupt Vector Shift bits Position */
#define ADCHS_ADCCON1_IRQVS_Msk               (_UINT32_(0x7) << ADCHS_ADCCON1_IRQVS_Pos)           /* (ADCHS_ADCCON1) Interrupt Vector Shift bits Mask */
#define ADCHS_ADCCON1_IRQVS(value)            (ADCHS_ADCCON1_IRQVS_Msk & (_UINT32_(value) << ADCHS_ADCCON1_IRQVS_Pos)) /* Assigment of value for IRQVS in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_IRQVS_SHL_7_Val       _UINT32_(0x7)                                        /* (ADCHS_ADCCON1) Shift x left 7 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_6_Val       _UINT32_(0x6)                                        /* (ADCHS_ADCCON1) Shift x left 6 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_5_Val       _UINT32_(0x5)                                        /* (ADCHS_ADCCON1) Shift x left 5 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_4_Val       _UINT32_(0x4)                                        /* (ADCHS_ADCCON1) Shift x left 4 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_3_Val       _UINT32_(0x3)                                        /* (ADCHS_ADCCON1) Shift x left 3 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_2_Val       _UINT32_(0x2)                                        /* (ADCHS_ADCCON1) Shift x left 2 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_1_Val       _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) Shift x left 1 bit position  */
#define   ADCHS_ADCCON1_IRQVS_SHL_0_Val       _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) Shift x left 0 bit position  */
#define ADCHS_ADCCON1_IRQVS_SHL_7             (ADCHS_ADCCON1_IRQVS_SHL_7_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 7 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_6             (ADCHS_ADCCON1_IRQVS_SHL_6_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 6 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_5             (ADCHS_ADCCON1_IRQVS_SHL_5_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 5 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_4             (ADCHS_ADCCON1_IRQVS_SHL_4_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 4 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_3             (ADCHS_ADCCON1_IRQVS_SHL_3_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 3 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_2             (ADCHS_ADCCON1_IRQVS_SHL_2_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 2 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_1             (ADCHS_ADCCON1_IRQVS_SHL_1_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 1 bit position Position  */
#define ADCHS_ADCCON1_IRQVS_SHL_0             (ADCHS_ADCCON1_IRQVS_SHL_0_Val << ADCHS_ADCCON1_IRQVS_Pos) /* (ADCHS_ADCCON1) Shift x left 0 bit position Position  */
#define ADCHS_ADCCON1_SCANEN_Pos              _UINT32_(8)                                          /* (ADCHS_ADCCON1)  Position */
#define ADCHS_ADCCON1_SCANEN_Msk              (_UINT32_(0x1) << ADCHS_ADCCON1_SCANEN_Pos)          /* (ADCHS_ADCCON1)  Mask */
#define ADCHS_ADCCON1_SCANEN(value)           (ADCHS_ADCCON1_SCANEN_Msk & (_UINT32_(value) << ADCHS_ADCCON1_SCANEN_Pos)) /* Assigment of value for SCANEN in the ADCHS_ADCCON1 register */
#define ADCHS_ADCCON1_FSYUPB_Pos              _UINT32_(9)                                          /* (ADCHS_ADCCON1)  Position */
#define ADCHS_ADCCON1_FSYUPB_Msk              (_UINT32_(0x1) << ADCHS_ADCCON1_FSYUPB_Pos)          /* (ADCHS_ADCCON1)  Mask */
#define ADCHS_ADCCON1_FSYUPB(value)           (ADCHS_ADCCON1_FSYUPB_Msk & (_UINT32_(value) << ADCHS_ADCCON1_FSYUPB_Pos)) /* Assigment of value for FSYUPB in the ADCHS_ADCCON1 register */
#define ADCHS_ADCCON1_FSYDMA_Pos              _UINT32_(10)                                         /* (ADCHS_ADCCON1)  Position */
#define ADCHS_ADCCON1_FSYDMA_Msk              (_UINT32_(0x1) << ADCHS_ADCCON1_FSYDMA_Pos)          /* (ADCHS_ADCCON1)  Mask */
#define ADCHS_ADCCON1_FSYDMA(value)           (ADCHS_ADCCON1_FSYDMA_Msk & (_UINT32_(value) << ADCHS_ADCCON1_FSYDMA_Pos)) /* Assigment of value for FSYDMA in the ADCHS_ADCCON1 register */
#define ADCHS_ADCCON1_SIDL_Pos                _UINT32_(13)                                         /* (ADCHS_ADCCON1) Stop in Idle Mode bit Position */
#define ADCHS_ADCCON1_SIDL_Msk                (_UINT32_(0x1) << ADCHS_ADCCON1_SIDL_Pos)            /* (ADCHS_ADCCON1) Stop in Idle Mode bit Mask */
#define ADCHS_ADCCON1_SIDL(value)             (ADCHS_ADCCON1_SIDL_Msk & (_UINT32_(value) << ADCHS_ADCCON1_SIDL_Pos)) /* Assigment of value for SIDL in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_SIDL_DISCONTINUE_Val  _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) Discontinue module operation when device enters Idle mode  */
#define   ADCHS_ADCCON1_SIDL_CONTINUE_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) Continue module operation in Idle mode  */
#define ADCHS_ADCCON1_SIDL_DISCONTINUE        (ADCHS_ADCCON1_SIDL_DISCONTINUE_Val << ADCHS_ADCCON1_SIDL_Pos) /* (ADCHS_ADCCON1) Discontinue module operation when device enters Idle mode Position  */
#define ADCHS_ADCCON1_SIDL_CONTINUE           (ADCHS_ADCCON1_SIDL_CONTINUE_Val << ADCHS_ADCCON1_SIDL_Pos) /* (ADCHS_ADCCON1) Continue module operation in Idle mode Position  */
#define ADCHS_ADCCON1_FRZ_Pos                 _UINT32_(14)                                         /* (ADCHS_ADCCON1)  Position */
#define ADCHS_ADCCON1_FRZ_Msk                 (_UINT32_(0x1) << ADCHS_ADCCON1_FRZ_Pos)             /* (ADCHS_ADCCON1)  Mask */
#define ADCHS_ADCCON1_FRZ(value)              (ADCHS_ADCCON1_FRZ_Msk & (_UINT32_(value) << ADCHS_ADCCON1_FRZ_Pos)) /* Assigment of value for FRZ in the ADCHS_ADCCON1 register */
#define ADCHS_ADCCON1_ON_Pos                  _UINT32_(15)                                         /* (ADCHS_ADCCON1) ADC Module Enable bit Position */
#define ADCHS_ADCCON1_ON_Msk                  (_UINT32_(0x1) << ADCHS_ADCCON1_ON_Pos)              /* (ADCHS_ADCCON1) ADC Module Enable bit Mask */
#define ADCHS_ADCCON1_ON(value)               (ADCHS_ADCCON1_ON_Msk & (_UINT32_(value) << ADCHS_ADCCON1_ON_Pos)) /* Assigment of value for ON in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_ON_ENABLED_Val        _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) ADC module is enabled  */
#define   ADCHS_ADCCON1_ON_DISABLED_Val       _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) ADC module is disabled  */
#define ADCHS_ADCCON1_ON_ENABLED              (ADCHS_ADCCON1_ON_ENABLED_Val << ADCHS_ADCCON1_ON_Pos) /* (ADCHS_ADCCON1) ADC module is enabled Position  */
#define ADCHS_ADCCON1_ON_DISABLED             (ADCHS_ADCCON1_ON_DISABLED_Val << ADCHS_ADCCON1_ON_Pos) /* (ADCHS_ADCCON1) ADC module is disabled Position  */
#define ADCHS_ADCCON1_STRGSRC_Pos             _UINT32_(16)                                         /* (ADCHS_ADCCON1) Scan Trigger Source Select bits Position */
#define ADCHS_ADCCON1_STRGSRC_Msk             (_UINT32_(0x1F) << ADCHS_ADCCON1_STRGSRC_Pos)        /* (ADCHS_ADCCON1) Scan Trigger Source Select bits Mask */
#define ADCHS_ADCCON1_STRGSRC(value)          (ADCHS_ADCCON1_STRGSRC_Msk & (_UINT32_(value) << ADCHS_ADCCON1_STRGSRC_Pos)) /* Assigment of value for STRGSRC in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_STRGSRC_EXT_TRIG_VAL_Val _UINT32_(0x1F)                                       /* (ADCHS_ADCCON1) External trigger for validation  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCCON1) ADC_TRIG_16  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCCON1) ADC_TRIG_15  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCCON1) ADC_TRIG_14  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCCON1) ADC_TRIG_13  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCCON1) ADC_TRIG_12  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCCON1) ADC_TRIG_11  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCCON1) ADC_TRIG_10  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCCON1) ADC_TRIG_9  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCCON1) ADC_TRIG_8  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCCON1) ADC_TRIG_7  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCCON1) ADC_TRIG_6  */
#define   ADCHS_ADCCON1_STRGSRC_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCCON1) ADC_TRIG_5  */
#define   ADCHS_ADCCON1_STRGSRC_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCCON1) INT0  */
#define   ADCHS_ADCCON1_STRGSRC_RESERVED_Val  _UINT32_(0x3)                                        /* (ADCHS_ADCCON1) RESERVED  */
#define   ADCHS_ADCCON1_STRGSRC_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCCON1) Software level trigger  */
#define   ADCHS_ADCCON1_STRGSRC_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) Software edge trigger  */
#define   ADCHS_ADCCON1_STRGSRC_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) No Trigger  */
#define ADCHS_ADCCON1_STRGSRC_EXT_TRIG_VAL    (ADCHS_ADCCON1_STRGSRC_EXT_TRIG_VAL_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) External trigger for validation Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_47        (ADCHS_ADCCON1_STRGSRC_EVSYS_47_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_16 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_46        (ADCHS_ADCCON1_STRGSRC_EVSYS_46_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_15 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_45        (ADCHS_ADCCON1_STRGSRC_EVSYS_45_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_14 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_44        (ADCHS_ADCCON1_STRGSRC_EVSYS_44_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_13 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_43        (ADCHS_ADCCON1_STRGSRC_EVSYS_43_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_12 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_42        (ADCHS_ADCCON1_STRGSRC_EVSYS_42_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_11 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_41        (ADCHS_ADCCON1_STRGSRC_EVSYS_41_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_10 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_40        (ADCHS_ADCCON1_STRGSRC_EVSYS_40_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_9 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_39        (ADCHS_ADCCON1_STRGSRC_EVSYS_39_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_8 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_38        (ADCHS_ADCCON1_STRGSRC_EVSYS_38_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_7 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_37        (ADCHS_ADCCON1_STRGSRC_EVSYS_37_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_6 Position  */
#define ADCHS_ADCCON1_STRGSRC_EVSYS_36        (ADCHS_ADCCON1_STRGSRC_EVSYS_36_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) ADC_TRIG_5 Position  */
#define ADCHS_ADCCON1_STRGSRC_INT0            (ADCHS_ADCCON1_STRGSRC_INT0_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) INT0 Position  */
#define ADCHS_ADCCON1_STRGSRC_RESERVED        (ADCHS_ADCCON1_STRGSRC_RESERVED_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) RESERVED Position  */
#define ADCHS_ADCCON1_STRGSRC_SW_LVL          (ADCHS_ADCCON1_STRGSRC_SW_LVL_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) Software level trigger Position  */
#define ADCHS_ADCCON1_STRGSRC_SW_EDGE         (ADCHS_ADCCON1_STRGSRC_SW_EDGE_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) Software edge trigger Position  */
#define ADCHS_ADCCON1_STRGSRC_NONE            (ADCHS_ADCCON1_STRGSRC_NONE_Val << ADCHS_ADCCON1_STRGSRC_Pos) /* (ADCHS_ADCCON1) No Trigger Position  */
#define ADCHS_ADCCON1_SELRES_Pos              _UINT32_(21)                                         /* (ADCHS_ADCCON1) Shared ADC7 Resolution bits Position */
#define ADCHS_ADCCON1_SELRES_Msk              (_UINT32_(0x3) << ADCHS_ADCCON1_SELRES_Pos)          /* (ADCHS_ADCCON1) Shared ADC7 Resolution bits Mask */
#define ADCHS_ADCCON1_SELRES(value)           (ADCHS_ADCCON1_SELRES_Msk & (_UINT32_(value) << ADCHS_ADCCON1_SELRES_Pos)) /* Assigment of value for SELRES in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_SELRES_12_BITS_Val    _UINT32_(0x3)                                        /* (ADCHS_ADCCON1) 12 bits (default)  */
#define   ADCHS_ADCCON1_SELRES_10_BITS_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCCON1) 10 bits  */
#define   ADCHS_ADCCON1_SELRES_8_BITS_Val     _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) 8 bits  */
#define   ADCHS_ADCCON1_SELRES_6_BITS_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) 6 bits  */
#define ADCHS_ADCCON1_SELRES_12_BITS          (ADCHS_ADCCON1_SELRES_12_BITS_Val << ADCHS_ADCCON1_SELRES_Pos) /* (ADCHS_ADCCON1) 12 bits (default) Position  */
#define ADCHS_ADCCON1_SELRES_10_BITS          (ADCHS_ADCCON1_SELRES_10_BITS_Val << ADCHS_ADCCON1_SELRES_Pos) /* (ADCHS_ADCCON1) 10 bits Position  */
#define ADCHS_ADCCON1_SELRES_8_BITS           (ADCHS_ADCCON1_SELRES_8_BITS_Val << ADCHS_ADCCON1_SELRES_Pos) /* (ADCHS_ADCCON1) 8 bits Position  */
#define ADCHS_ADCCON1_SELRES_6_BITS           (ADCHS_ADCCON1_SELRES_6_BITS_Val << ADCHS_ADCCON1_SELRES_Pos) /* (ADCHS_ADCCON1) 6 bits Position  */
#define ADCHS_ADCCON1_FRACT_Pos               _UINT32_(23)                                         /* (ADCHS_ADCCON1) Fractional Data Output Format bit Position */
#define ADCHS_ADCCON1_FRACT_Msk               (_UINT32_(0x1) << ADCHS_ADCCON1_FRACT_Pos)           /* (ADCHS_ADCCON1) Fractional Data Output Format bit Mask */
#define ADCHS_ADCCON1_FRACT(value)            (ADCHS_ADCCON1_FRACT_Msk & (_UINT32_(value) << ADCHS_ADCCON1_FRACT_Pos)) /* Assigment of value for FRACT in the ADCHS_ADCCON1 register */
#define   ADCHS_ADCCON1_FRACT_FRAC_Val        _UINT32_(0x1)                                        /* (ADCHS_ADCCON1) Fractional  */
#define   ADCHS_ADCCON1_FRACT_INT_Val         _UINT32_(0x0)                                        /* (ADCHS_ADCCON1) Integer  */
#define ADCHS_ADCCON1_FRACT_FRAC              (ADCHS_ADCCON1_FRACT_FRAC_Val << ADCHS_ADCCON1_FRACT_Pos) /* (ADCHS_ADCCON1) Fractional Position  */
#define ADCHS_ADCCON1_FRACT_INT               (ADCHS_ADCCON1_FRACT_INT_Val << ADCHS_ADCCON1_FRACT_Pos) /* (ADCHS_ADCCON1) Integer Position  */
#define ADCHS_ADCCON1_Msk                     _UINT32_(0x00FFE77F)                                 /* (ADCHS_ADCCON1) Register Mask  */


/* -------- ADCHS_ADCCON1CLR : (ADCHS Offset: 0x04) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCON1CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCON1CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON1CLR) Register Mask  */


/* -------- ADCHS_ADCCON1SET : (ADCHS Offset: 0x08) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCON1SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON1SET) Bit set register  Reset Value */

#define ADCHS_ADCCON1SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON1SET) Register Mask  */


/* -------- ADCHS_ADCCON1INV : (ADCHS Offset: 0x0C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCON1INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON1INV) Bit invert register  Reset Value */

#define ADCHS_ADCCON1INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON1INV) Register Mask  */


/* -------- ADCHS_ADCCON2 : (ADCHS Offset: 0x10) (R/W 32)  -------- */
#define ADCHS_ADCCON2_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCON2)   Reset Value */

#define ADCHS_ADCCON2_ADCDIV_Pos              _UINT32_(0)                                          /* (ADCHS_ADCCON2) Shared ADC Clock Divider bits Position */
#define ADCHS_ADCCON2_ADCDIV_Msk              (_UINT32_(0x7F) << ADCHS_ADCCON2_ADCDIV_Pos)         /* (ADCHS_ADCCON2) Shared ADC Clock Divider bits Mask */
#define ADCHS_ADCCON2_ADCDIV(value)           (ADCHS_ADCCON2_ADCDIV_Msk & (_UINT32_(value) << ADCHS_ADCCON2_ADCDIV_Pos)) /* Assigment of value for ADCDIV in the ADCHS_ADCCON2 register */
#define ADCHS_ADCCON2_ADCEIS_Pos              _UINT32_(8)                                          /* (ADCHS_ADCCON2) Shared ADC Early Interrupt Select bits Position */
#define ADCHS_ADCCON2_ADCEIS_Msk              (_UINT32_(0x7) << ADCHS_ADCCON2_ADCEIS_Pos)          /* (ADCHS_ADCCON2) Shared ADC Early Interrupt Select bits Mask */
#define ADCHS_ADCCON2_ADCEIS(value)           (ADCHS_ADCCON2_ADCEIS_Msk & (_UINT32_(value) << ADCHS_ADCCON2_ADCEIS_Pos)) /* Assigment of value for ADCEIS in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_ADCEIS_8CLKS_EARLY_Val _UINT32_(0x7)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 8 ADC clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_7CLKS_EARLY_Val _UINT32_(0x6)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 7 ADC clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_6CLKS_EARLY_Val _UINT32_(0x5)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 6 ADC clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_5CLKS_EARLY_Val _UINT32_(0x4)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 5 ADC clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_4CLKS_EARLY_Val _UINT32_(0x3)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 4 ADC clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_3CLKS_EARLY_Val _UINT32_(0x2)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 3 ADC clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_2CLKS_EARLY_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 2 ADC module clocks prior to end of conversion  */
#define   ADCHS_ADCCON2_ADCEIS_1CLKS_EARLY_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) The data ready interrupt is generated 1 ADC module clock prior to end of conversion  */
#define ADCHS_ADCCON2_ADCEIS_8CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_8CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 8 ADC clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_7CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_7CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 7 ADC clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_6CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_6CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 6 ADC clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_5CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_5CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 5 ADC clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_4CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_4CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 4 ADC clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_3CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_3CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 3 ADC clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_2CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_2CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 2 ADC module clocks prior to end of conversion Position  */
#define ADCHS_ADCCON2_ADCEIS_1CLKS_EARLY      (ADCHS_ADCCON2_ADCEIS_1CLKS_EARLY_Val << ADCHS_ADCCON2_ADCEIS_Pos) /* (ADCHS_ADCCON2) The data ready interrupt is generated 1 ADC module clock prior to end of conversion Position  */
#define ADCHS_ADCCON2_ENXCNVRT_Pos            _UINT32_(11)                                         /* (ADCHS_ADCCON2)  Position */
#define ADCHS_ADCCON2_ENXCNVRT_Msk            (_UINT32_(0x1) << ADCHS_ADCCON2_ENXCNVRT_Pos)        /* (ADCHS_ADCCON2)  Mask */
#define ADCHS_ADCCON2_ENXCNVRT(value)         (ADCHS_ADCCON2_ENXCNVRT_Msk & (_UINT32_(value) << ADCHS_ADCCON2_ENXCNVRT_Pos)) /* Assigment of value for ENXCNVRT in the ADCHS_ADCCON2 register */
#define ADCHS_ADCCON2_EOSIEN_Pos              _UINT32_(13)                                         /* (ADCHS_ADCCON2) End of Scan Interrupt Enable bit Position */
#define ADCHS_ADCCON2_EOSIEN_Msk              (_UINT32_(0x1) << ADCHS_ADCCON2_EOSIEN_Pos)          /* (ADCHS_ADCCON2) End of Scan Interrupt Enable bit Mask */
#define ADCHS_ADCCON2_EOSIEN(value)           (ADCHS_ADCCON2_EOSIEN_Msk & (_UINT32_(value) << ADCHS_ADCCON2_EOSIEN_Pos)) /* Assigment of value for EOSIEN in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_EOSIEN_EOSRDY_INT_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) Interrupt will be generated when EOSRDY bit is set  */
#define   ADCHS_ADCCON2_EOSIEN_NOEOSRDY_INT_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) No interrupt is generated when the EOSRDY bit is set  */
#define ADCHS_ADCCON2_EOSIEN_EOSRDY_INT       (ADCHS_ADCCON2_EOSIEN_EOSRDY_INT_Val << ADCHS_ADCCON2_EOSIEN_Pos) /* (ADCHS_ADCCON2) Interrupt will be generated when EOSRDY bit is set Position  */
#define ADCHS_ADCCON2_EOSIEN_NOEOSRDY_INT     (ADCHS_ADCCON2_EOSIEN_NOEOSRDY_INT_Val << ADCHS_ADCCON2_EOSIEN_Pos) /* (ADCHS_ADCCON2) No interrupt is generated when the EOSRDY bit is set Position  */
#define ADCHS_ADCCON2_REFFLTIEN_Pos           _UINT32_(14)                                         /* (ADCHS_ADCCON2) Band Gap/ Vref Voltage Fault Interrupt Enable bit Position */
#define ADCHS_ADCCON2_REFFLTIEN_Msk           (_UINT32_(0x1) << ADCHS_ADCCON2_REFFLTIEN_Pos)       /* (ADCHS_ADCCON2) Band Gap/ Vref Voltage Fault Interrupt Enable bit Mask */
#define ADCHS_ADCCON2_REFFLTIEN(value)        (ADCHS_ADCCON2_REFFLTIEN_Msk & (_UINT32_(value) << ADCHS_ADCCON2_REFFLTIEN_Pos)) /* Assigment of value for REFFLTIEN in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_REFFLTIEN_REFFLT_INT_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) Interrupt will be generated when the REFFLT bit is set  */
#define   ADCHS_ADCCON2_REFFLTIEN_NOREFFLT_INT_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) No interrupt is generated when the REFFLT bit is set  */
#define ADCHS_ADCCON2_REFFLTIEN_REFFLT_INT    (ADCHS_ADCCON2_REFFLTIEN_REFFLT_INT_Val << ADCHS_ADCCON2_REFFLTIEN_Pos) /* (ADCHS_ADCCON2) Interrupt will be generated when the REFFLT bit is set Position  */
#define ADCHS_ADCCON2_REFFLTIEN_NOREFFLT_INT  (ADCHS_ADCCON2_REFFLTIEN_NOREFFLT_INT_Val << ADCHS_ADCCON2_REFFLTIEN_Pos) /* (ADCHS_ADCCON2) No interrupt is generated when the REFFLT bit is set Position  */
#define ADCHS_ADCCON2_BGVRIEN_Pos             _UINT32_(15)                                         /* (ADCHS_ADCCON2) Band Gap/ Vref Voltage Ready Interrupt Enable bit Position */
#define ADCHS_ADCCON2_BGVRIEN_Msk             (_UINT32_(0x1) << ADCHS_ADCCON2_BGVRIEN_Pos)         /* (ADCHS_ADCCON2) Band Gap/ Vref Voltage Ready Interrupt Enable bit Mask */
#define ADCHS_ADCCON2_BGVRIEN(value)          (ADCHS_ADCCON2_BGVRIEN_Msk & (_UINT32_(value) << ADCHS_ADCCON2_BGVRIEN_Pos)) /* Assigment of value for BGVRIEN in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_BGVRIEN_BGVRDDY_INT_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) Interrupt will be generated when the BGVRDDY bit is set  */
#define   ADCHS_ADCCON2_BGVRIEN_NOBGVRDDY_INT_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) No interrupt is generated when the BGVRRDY bit is set  */
#define ADCHS_ADCCON2_BGVRIEN_BGVRDDY_INT     (ADCHS_ADCCON2_BGVRIEN_BGVRDDY_INT_Val << ADCHS_ADCCON2_BGVRIEN_Pos) /* (ADCHS_ADCCON2) Interrupt will be generated when the BGVRDDY bit is set Position  */
#define ADCHS_ADCCON2_BGVRIEN_NOBGVRDDY_INT   (ADCHS_ADCCON2_BGVRIEN_NOBGVRDDY_INT_Val << ADCHS_ADCCON2_BGVRIEN_Pos) /* (ADCHS_ADCCON2) No interrupt is generated when the BGVRRDY bit is set Position  */
#define ADCHS_ADCCON2_SAMC_Pos                _UINT32_(16)                                         /* (ADCHS_ADCCON2) Sample Time for the Shared ADC (ADC7) bits Position */
#define ADCHS_ADCCON2_SAMC_Msk                (_UINT32_(0x3FF) << ADCHS_ADCCON2_SAMC_Pos)          /* (ADCHS_ADCCON2) Sample Time for the Shared ADC (ADC7) bits Mask */
#define ADCHS_ADCCON2_SAMC(value)             (ADCHS_ADCCON2_SAMC_Msk & (_UINT32_(value) << ADCHS_ADCCON2_SAMC_Pos)) /* Assigment of value for SAMC in the ADCHS_ADCCON2 register */
#define ADCHS_ADCCON2_EOSRDY_Pos              _UINT32_(29)                                         /* (ADCHS_ADCCON2) End of Scan Interrupt Status bit Position */
#define ADCHS_ADCCON2_EOSRDY_Msk              (_UINT32_(0x1) << ADCHS_ADCCON2_EOSRDY_Pos)          /* (ADCHS_ADCCON2) End of Scan Interrupt Status bit Mask */
#define ADCHS_ADCCON2_EOSRDY(value)           (ADCHS_ADCCON2_EOSRDY_Msk & (_UINT32_(value) << ADCHS_ADCCON2_EOSRDY_Pos)) /* Assigment of value for EOSRDY in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_EOSRDY_SCAN_COMPLETE_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) All analog inputs are considered for scanning through the scan trigger (all analog inputs specified in the ADCCSS1 and ADCCSS2 registers) have completed scanning  */
#define   ADCHS_ADCCON2_EOSRDY_SCAN_NOT_COMPLETE_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) Scanning has not completed  */
#define ADCHS_ADCCON2_EOSRDY_SCAN_COMPLETE    (ADCHS_ADCCON2_EOSRDY_SCAN_COMPLETE_Val << ADCHS_ADCCON2_EOSRDY_Pos) /* (ADCHS_ADCCON2) All analog inputs are considered for scanning through the scan trigger (all analog inputs specified in the ADCCSS1 and ADCCSS2 registers) have completed scanning Position  */
#define ADCHS_ADCCON2_EOSRDY_SCAN_NOT_COMPLETE (ADCHS_ADCCON2_EOSRDY_SCAN_NOT_COMPLETE_Val << ADCHS_ADCCON2_EOSRDY_Pos) /* (ADCHS_ADCCON2) Scanning has not completed Position  */
#define ADCHS_ADCCON2_REFFLT_Pos              _UINT32_(30)                                         /* (ADCHS_ADCCON2) Band Gap/ Vref / AVdd BOR Fault Status bit Position */
#define ADCHS_ADCCON2_REFFLT_Msk              (_UINT32_(0x1) << ADCHS_ADCCON2_REFFLT_Pos)          /* (ADCHS_ADCCON2) Band Gap/ Vref / AVdd BOR Fault Status bit Mask */
#define ADCHS_ADCCON2_REFFLT(value)           (ADCHS_ADCCON2_REFFLT_Msk & (_UINT32_(value) << ADCHS_ADCCON2_REFFLT_Pos)) /* Assigment of value for REFFLT in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_REFFLT_BG_VREF_FLT_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) Fault in band gap or the Vref voltage while the ON bit (ADCCON1) was set. Most likely a band gap or Vref fault will be caused by a BOR of the analog Vdd supply.  */
#define   ADCHS_ADCCON2_REFFLT_BG_VREF_OK_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) Band gap and Vref voltage are working properly  */
#define ADCHS_ADCCON2_REFFLT_BG_VREF_FLT      (ADCHS_ADCCON2_REFFLT_BG_VREF_FLT_Val << ADCHS_ADCCON2_REFFLT_Pos) /* (ADCHS_ADCCON2) Fault in band gap or the Vref voltage while the ON bit (ADCCON1) was set. Most likely a band gap or Vref fault will be caused by a BOR of the analog Vdd supply. Position  */
#define ADCHS_ADCCON2_REFFLT_BG_VREF_OK       (ADCHS_ADCCON2_REFFLT_BG_VREF_OK_Val << ADCHS_ADCCON2_REFFLT_Pos) /* (ADCHS_ADCCON2) Band gap and Vref voltage are working properly Position  */
#define ADCHS_ADCCON2_BGVRRDY_Pos             _UINT32_(31)                                         /* (ADCHS_ADCCON2) Band Gap Voltage/ADC Reference Voltage Status bit Position */
#define ADCHS_ADCCON2_BGVRRDY_Msk             (_UINT32_(0x1) << ADCHS_ADCCON2_BGVRRDY_Pos)         /* (ADCHS_ADCCON2) Band Gap Voltage/ADC Reference Voltage Status bit Mask */
#define ADCHS_ADCCON2_BGVRRDY(value)          (ADCHS_ADCCON2_BGVRRDY_Msk & (_UINT32_(value) << ADCHS_ADCCON2_BGVRRDY_Pos)) /* Assigment of value for BGVRRDY in the ADCHS_ADCCON2 register */
#define   ADCHS_ADCCON2_BGVRRDY_VREF_RDY_Val  _UINT32_(0x1)                                        /* (ADCHS_ADCCON2) Both band gap voltage and ADC reference voltages (Vref) are ready  */
#define   ADCHS_ADCCON2_BGVRRDY_VREF_NOTRDY_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON2) Either or both band gap voltage and ADC reference voltages (Vref) are not ready  */
#define ADCHS_ADCCON2_BGVRRDY_VREF_RDY        (ADCHS_ADCCON2_BGVRRDY_VREF_RDY_Val << ADCHS_ADCCON2_BGVRRDY_Pos) /* (ADCHS_ADCCON2) Both band gap voltage and ADC reference voltages (Vref) are ready Position  */
#define ADCHS_ADCCON2_BGVRRDY_VREF_NOTRDY     (ADCHS_ADCCON2_BGVRRDY_VREF_NOTRDY_Val << ADCHS_ADCCON2_BGVRRDY_Pos) /* (ADCHS_ADCCON2) Either or both band gap voltage and ADC reference voltages (Vref) are not ready Position  */
#define ADCHS_ADCCON2_Msk                     _UINT32_(0xE3FFEF7F)                                 /* (ADCHS_ADCCON2) Register Mask  */


/* -------- ADCHS_ADCCON2CLR : (ADCHS Offset: 0x14) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCON2CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON2CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCON2CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON2CLR) Register Mask  */


/* -------- ADCHS_ADCCON2SET : (ADCHS Offset: 0x18) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCON2SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON2SET) Bit set register  Reset Value */

#define ADCHS_ADCCON2SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON2SET) Register Mask  */


/* -------- ADCHS_ADCCON2INV : (ADCHS Offset: 0x1C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCON2INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON2INV) Bit invert register  Reset Value */

#define ADCHS_ADCCON2INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON2INV) Register Mask  */


/* -------- ADCHS_ADCCON3 : (ADCHS Offset: 0x20) (R/W 32)  -------- */
#define ADCHS_ADCCON3_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCON3)   Reset Value */

#define ADCHS_ADCCON3_ADINSEL_Pos             _UINT32_(0)                                          /* (ADCHS_ADCCON3) Analog Input Select bits Position */
#define ADCHS_ADCCON3_ADINSEL_Msk             (_UINT32_(0x3F) << ADCHS_ADCCON3_ADINSEL_Pos)        /* (ADCHS_ADCCON3) Analog Input Select bits Mask */
#define ADCHS_ADCCON3_ADINSEL(value)          (ADCHS_ADCCON3_ADINSEL_Msk & (_UINT32_(value) << ADCHS_ADCCON3_ADINSEL_Pos)) /* Assigment of value for ADINSEL in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_ADINSEL_TMP_SENSE_Val _UINT32_(0xB)                                        /* (ADCHS_ADCCON3) CTMU Temperature Sensor (internal AN11)  */
#define   ADCHS_ADCCON3_ADINSEL_VBATDIV2_SENSE_Val _UINT32_(0xA)                                        /* (ADCHS_ADCCON3) VBAT/2 (internal AN10)  */
#define   ADCHS_ADCCON3_ADINSEL_1P2V_SENSE_Val _UINT32_(0x9)                                        /* (ADCHS_ADCCON3) IVref 1.2V (internal AN9)  */
#define   ADCHS_ADCCON3_ADINSEL_BGREF_Val     _UINT32_(0x8)                                        /* (ADCHS_ADCCON3) BandGap Reference (internal AN8)  */
#define   ADCHS_ADCCON3_ADINSEL_AN7_Val       _UINT32_(0x7)                                        /* (ADCHS_ADCCON3) AN7  */
#define   ADCHS_ADCCON3_ADINSEL_AN6_Val       _UINT32_(0x6)                                        /* (ADCHS_ADCCON3) AN6  */
#define   ADCHS_ADCCON3_ADINSEL_AN5_Val       _UINT32_(0x5)                                        /* (ADCHS_ADCCON3) AN5  */
#define   ADCHS_ADCCON3_ADINSEL_AN4_Val       _UINT32_(0x4)                                        /* (ADCHS_ADCCON3) AN4  */
#define   ADCHS_ADCCON3_ADINSEL_AN3_Val       _UINT32_(0x3)                                        /* (ADCHS_ADCCON3) AN3  */
#define   ADCHS_ADCCON3_ADINSEL_AN2_Val       _UINT32_(0x2)                                        /* (ADCHS_ADCCON3) AN2  */
#define   ADCHS_ADCCON3_ADINSEL_AN1_Val       _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) AN1  */
#define   ADCHS_ADCCON3_ADINSEL_AN0_Val       _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) AN0  */
#define ADCHS_ADCCON3_ADINSEL_TMP_SENSE       (ADCHS_ADCCON3_ADINSEL_TMP_SENSE_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) CTMU Temperature Sensor (internal AN11) Position  */
#define ADCHS_ADCCON3_ADINSEL_VBATDIV2_SENSE  (ADCHS_ADCCON3_ADINSEL_VBATDIV2_SENSE_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) VBAT/2 (internal AN10) Position  */
#define ADCHS_ADCCON3_ADINSEL_1P2V_SENSE      (ADCHS_ADCCON3_ADINSEL_1P2V_SENSE_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) IVref 1.2V (internal AN9) Position  */
#define ADCHS_ADCCON3_ADINSEL_BGREF           (ADCHS_ADCCON3_ADINSEL_BGREF_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) BandGap Reference (internal AN8) Position  */
#define ADCHS_ADCCON3_ADINSEL_AN7             (ADCHS_ADCCON3_ADINSEL_AN7_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN7 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN6             (ADCHS_ADCCON3_ADINSEL_AN6_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN6 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN5             (ADCHS_ADCCON3_ADINSEL_AN5_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN5 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN4             (ADCHS_ADCCON3_ADINSEL_AN4_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN4 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN3             (ADCHS_ADCCON3_ADINSEL_AN3_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN3 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN2             (ADCHS_ADCCON3_ADINSEL_AN2_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN2 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN1             (ADCHS_ADCCON3_ADINSEL_AN1_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN1 Position  */
#define ADCHS_ADCCON3_ADINSEL_AN0             (ADCHS_ADCCON3_ADINSEL_AN0_Val << ADCHS_ADCCON3_ADINSEL_Pos) /* (ADCHS_ADCCON3) AN0 Position  */
#define ADCHS_ADCCON3_GSWTRG_Pos              _UINT32_(6)                                          /* (ADCHS_ADCCON3) Global Software Trigger bit Position */
#define ADCHS_ADCCON3_GSWTRG_Msk              (_UINT32_(0x1) << ADCHS_ADCCON3_GSWTRG_Pos)          /* (ADCHS_ADCCON3) Global Software Trigger bit Mask */
#define ADCHS_ADCCON3_GSWTRG(value)           (ADCHS_ADCCON3_GSWTRG_Msk & (_UINT32_(value) << ADCHS_ADCCON3_GSWTRG_Pos)) /* Assigment of value for GSWTRG in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_GSWTRG_GSWTRG_Val     _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) Trigger conversion for ADC inputs that have selected the GSWTRG bit as either through the associated TRGSRC bits in the ADCTRGx registers or through the STRGSRC<4:0> bits in the ADCCON1 register the trigger signal  */
#define   ADCHS_ADCCON3_GSWTRG_NO_GSWTRG_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) Do not trigger an analog-to-digital conversion  */
#define ADCHS_ADCCON3_GSWTRG_GSWTRG           (ADCHS_ADCCON3_GSWTRG_GSWTRG_Val << ADCHS_ADCCON3_GSWTRG_Pos) /* (ADCHS_ADCCON3) Trigger conversion for ADC inputs that have selected the GSWTRG bit as either through the associated TRGSRC bits in the ADCTRGx registers or through the STRGSRC<4:0> bits in the ADCCON1 register the trigger signal Position  */
#define ADCHS_ADCCON3_GSWTRG_NO_GSWTRG        (ADCHS_ADCCON3_GSWTRG_NO_GSWTRG_Val << ADCHS_ADCCON3_GSWTRG_Pos) /* (ADCHS_ADCCON3) Do not trigger an analog-to-digital conversion Position  */
#define ADCHS_ADCCON3_GLSWTRG_Pos             _UINT32_(7)                                          /* (ADCHS_ADCCON3) Global Level Software Trigger bit Position */
#define ADCHS_ADCCON3_GLSWTRG_Msk             (_UINT32_(0x1) << ADCHS_ADCCON3_GLSWTRG_Pos)         /* (ADCHS_ADCCON3) Global Level Software Trigger bit Mask */
#define ADCHS_ADCCON3_GLSWTRG(value)          (ADCHS_ADCCON3_GLSWTRG_Msk & (_UINT32_(value) << ADCHS_ADCCON3_GLSWTRG_Pos)) /* Assigment of value for GLSWTRG in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_GLSWTRG_GLSWTRG_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) Trigger conversion for ADC inputs that have selected the GLSWTRG bit as the trigger signal  */
#define   ADCHS_ADCCON3_GLSWTRG_NO_GLSWTRG_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) Do not trigger an analog-to-digital conversion  */
#define ADCHS_ADCCON3_GLSWTRG_GLSWTRG         (ADCHS_ADCCON3_GLSWTRG_GLSWTRG_Val << ADCHS_ADCCON3_GLSWTRG_Pos) /* (ADCHS_ADCCON3) Trigger conversion for ADC inputs that have selected the GLSWTRG bit as the trigger signal Position  */
#define ADCHS_ADCCON3_GLSWTRG_NO_GLSWTRG      (ADCHS_ADCCON3_GLSWTRG_NO_GLSWTRG_Val << ADCHS_ADCCON3_GLSWTRG_Pos) /* (ADCHS_ADCCON3) Do not trigger an analog-to-digital conversion Position  */
#define ADCHS_ADCCON3_RQCNVRT_Pos             _UINT32_(8)                                          /* (ADCHS_ADCCON3) Individual ADC Input Conversion Request bit Position */
#define ADCHS_ADCCON3_RQCNVRT_Msk             (_UINT32_(0x1) << ADCHS_ADCCON3_RQCNVRT_Pos)         /* (ADCHS_ADCCON3) Individual ADC Input Conversion Request bit Mask */
#define ADCHS_ADCCON3_RQCNVRT(value)          (ADCHS_ADCCON3_RQCNVRT_Msk & (_UINT32_(value) << ADCHS_ADCCON3_RQCNVRT_Pos)) /* Assigment of value for RQCNVRT in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_RQCNVRT_IND_TRIGGER_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) Trigger the conversion of the selected ADC input as specified by the ADINSEL bits  */
#define   ADCHS_ADCCON3_RQCNVRT_NO_TRIGGER_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) Do not trigger the conversion  */
#define ADCHS_ADCCON3_RQCNVRT_IND_TRIGGER     (ADCHS_ADCCON3_RQCNVRT_IND_TRIGGER_Val << ADCHS_ADCCON3_RQCNVRT_Pos) /* (ADCHS_ADCCON3) Trigger the conversion of the selected ADC input as specified by the ADINSEL bits Position  */
#define ADCHS_ADCCON3_RQCNVRT_NO_TRIGGER      (ADCHS_ADCCON3_RQCNVRT_NO_TRIGGER_Val << ADCHS_ADCCON3_RQCNVRT_Pos) /* (ADCHS_ADCCON3) Do not trigger the conversion Position  */
#define ADCHS_ADCCON3_SAMP_Pos                _UINT32_(9)                                          /* (ADCHS_ADCCON3) Shared ADC7 Analog Input Sampling Enable bit  Position */
#define ADCHS_ADCCON3_SAMP_Msk                (_UINT32_(0x1) << ADCHS_ADCCON3_SAMP_Pos)            /* (ADCHS_ADCCON3) Shared ADC7 Analog Input Sampling Enable bit  Mask */
#define ADCHS_ADCCON3_SAMP(value)             (ADCHS_ADCCON3_SAMP_Msk & (_UINT32_(value) << ADCHS_ADCCON3_SAMP_Pos)) /* Assigment of value for SAMP in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_SAMP_SAMPLE_Val       _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) The ADC S&H amplifier is sampling  */
#define   ADCHS_ADCCON3_SAMP_HOLD_Val         _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) The ADC S&H amplifier is holding  */
#define ADCHS_ADCCON3_SAMP_SAMPLE             (ADCHS_ADCCON3_SAMP_SAMPLE_Val << ADCHS_ADCCON3_SAMP_Pos) /* (ADCHS_ADCCON3) The ADC S&H amplifier is sampling Position  */
#define ADCHS_ADCCON3_SAMP_HOLD               (ADCHS_ADCCON3_SAMP_HOLD_Val << ADCHS_ADCCON3_SAMP_Pos) /* (ADCHS_ADCCON3) The ADC S&H amplifier is holding Position  */
#define ADCHS_ADCCON3_UPDRDY_Pos              _UINT32_(10)                                         /* (ADCHS_ADCCON3) ADC Update Ready Status bit Position */
#define ADCHS_ADCCON3_UPDRDY_Msk              (_UINT32_(0x1) << ADCHS_ADCCON3_UPDRDY_Pos)          /* (ADCHS_ADCCON3) ADC Update Ready Status bit Mask */
#define ADCHS_ADCCON3_UPDRDY(value)           (ADCHS_ADCCON3_UPDRDY_Msk & (_UINT32_(value) << ADCHS_ADCCON3_UPDRDY_Pos)) /* Assigment of value for UPDRDY in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_UPDRDY_UPDATE_RDY_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) ADC SFRs can be updated  */
#define   ADCHS_ADCCON3_UPDRDY_UPDATE_NOT_RDY_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) ADC SFRs cannot be updated  */
#define ADCHS_ADCCON3_UPDRDY_UPDATE_RDY       (ADCHS_ADCCON3_UPDRDY_UPDATE_RDY_Val << ADCHS_ADCCON3_UPDRDY_Pos) /* (ADCHS_ADCCON3) ADC SFRs can be updated Position  */
#define ADCHS_ADCCON3_UPDRDY_UPDATE_NOT_RDY   (ADCHS_ADCCON3_UPDRDY_UPDATE_NOT_RDY_Val << ADCHS_ADCCON3_UPDRDY_Pos) /* (ADCHS_ADCCON3) ADC SFRs cannot be updated Position  */
#define ADCHS_ADCCON3_UPDIEN_Pos              _UINT32_(11)                                         /* (ADCHS_ADCCON3) Update Ready Interrupt Enable bit Position */
#define ADCHS_ADCCON3_UPDIEN_Msk              (_UINT32_(0x1) << ADCHS_ADCCON3_UPDIEN_Pos)          /* (ADCHS_ADCCON3) Update Ready Interrupt Enable bit Mask */
#define ADCHS_ADCCON3_UPDIEN(value)           (ADCHS_ADCCON3_UPDIEN_Msk & (_UINT32_(value) << ADCHS_ADCCON3_UPDIEN_Pos)) /* Assigment of value for UPDIEN in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_UPDIEN_INT_ON_UPDATE_RDY_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) Interrupt will be generated when the UPDRDY bit is set by hardware  */
#define   ADCHS_ADCCON3_UPDIEN_NO_INT_ON_UPDATE_RDY_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) No interrupt is generated  */
#define ADCHS_ADCCON3_UPDIEN_INT_ON_UPDATE_RDY (ADCHS_ADCCON3_UPDIEN_INT_ON_UPDATE_RDY_Val << ADCHS_ADCCON3_UPDIEN_Pos) /* (ADCHS_ADCCON3) Interrupt will be generated when the UPDRDY bit is set by hardware Position  */
#define ADCHS_ADCCON3_UPDIEN_NO_INT_ON_UPDATE_RDY (ADCHS_ADCCON3_UPDIEN_NO_INT_ON_UPDATE_RDY_Val << ADCHS_ADCCON3_UPDIEN_Pos) /* (ADCHS_ADCCON3) No interrupt is generated Position  */
#define ADCHS_ADCCON3_TRGSUSP_Pos             _UINT32_(12)                                         /* (ADCHS_ADCCON3) Trigger Suspend bit Position */
#define ADCHS_ADCCON3_TRGSUSP_Msk             (_UINT32_(0x1) << ADCHS_ADCCON3_TRGSUSP_Pos)         /* (ADCHS_ADCCON3) Trigger Suspend bit Mask */
#define ADCHS_ADCCON3_TRGSUSP(value)          (ADCHS_ADCCON3_TRGSUSP_Msk & (_UINT32_(value) << ADCHS_ADCCON3_TRGSUSP_Pos)) /* Assigment of value for TRGSUSP in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_TRGSUSP_TRIG_BLOCKED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) Triggers are blocked from starting a new analog-to-digital conversion  */
#define   ADCHS_ADCCON3_TRGSUSP_TRIG_NOT_BLOCKED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) Triggers are not blocked  */
#define ADCHS_ADCCON3_TRGSUSP_TRIG_BLOCKED    (ADCHS_ADCCON3_TRGSUSP_TRIG_BLOCKED_Val << ADCHS_ADCCON3_TRGSUSP_Pos) /* (ADCHS_ADCCON3) Triggers are blocked from starting a new analog-to-digital conversion Position  */
#define ADCHS_ADCCON3_TRGSUSP_TRIG_NOT_BLOCKED (ADCHS_ADCCON3_TRGSUSP_TRIG_NOT_BLOCKED_Val << ADCHS_ADCCON3_TRGSUSP_Pos) /* (ADCHS_ADCCON3) Triggers are not blocked Position  */
#define ADCHS_ADCCON3_VREFSEL_Pos             _UINT32_(13)                                         /* (ADCHS_ADCCON3) Voltage Reference Input Selection bits Position */
#define ADCHS_ADCCON3_VREFSEL_Msk             (_UINT32_(0x7) << ADCHS_ADCCON3_VREFSEL_Pos)         /* (ADCHS_ADCCON3) Voltage Reference Input Selection bits Mask */
#define ADCHS_ADCCON3_VREFSEL(value)          (ADCHS_ADCCON3_VREFSEL_Msk & (_UINT32_(value) << ADCHS_ADCCON3_VREFSEL_Pos)) /* Assigment of value for VREFSEL in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_VREFSEL_AVDD_AVSS_Val _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) ADC VREFH is AVDD, ADC VREFL is AVSS  */
#define ADCHS_ADCCON3_VREFSEL_AVDD_AVSS       (ADCHS_ADCCON3_VREFSEL_AVDD_AVSS_Val << ADCHS_ADCCON3_VREFSEL_Pos) /* (ADCHS_ADCCON3) ADC VREFH is AVDD, ADC VREFL is AVSS Position  */
#define ADCHS_ADCCON3_DIGEN7_Pos              _UINT32_(23)                                         /* (ADCHS_ADCCON3) Shared ADC (ADC7) Digital Enable bit Position */
#define ADCHS_ADCCON3_DIGEN7_Msk              (_UINT32_(0x1) << ADCHS_ADCCON3_DIGEN7_Pos)          /* (ADCHS_ADCCON3) Shared ADC (ADC7) Digital Enable bit Mask */
#define ADCHS_ADCCON3_DIGEN7(value)           (ADCHS_ADCCON3_DIGEN7_Msk & (_UINT32_(value) << ADCHS_ADCCON3_DIGEN7_Pos)) /* Assigment of value for DIGEN7 in the ADCHS_ADCCON3 register */
#define ADCHS_ADCCON3_CONCLKDIV_Pos           _UINT32_(24)                                         /* (ADCHS_ADCCON3) Analog-to-Digital Control Clock Divider bits Position */
#define ADCHS_ADCCON3_CONCLKDIV_Msk           (_UINT32_(0x3F) << ADCHS_ADCCON3_CONCLKDIV_Pos)      /* (ADCHS_ADCCON3) Analog-to-Digital Control Clock Divider bits Mask */
#define ADCHS_ADCCON3_CONCLKDIV(value)        (ADCHS_ADCCON3_CONCLKDIV_Msk & (_UINT32_(value) << ADCHS_ADCCON3_CONCLKDIV_Pos)) /* Assigment of value for CONCLKDIV in the ADCHS_ADCCON3 register */
#define ADCHS_ADCCON3_ADCSEL_Pos              _UINT32_(30)                                         /* (ADCHS_ADCCON3) Analog-to-Digital Clock Source bits Position */
#define ADCHS_ADCCON3_ADCSEL_Msk              (_UINT32_(0x3) << ADCHS_ADCCON3_ADCSEL_Pos)          /* (ADCHS_ADCCON3) Analog-to-Digital Clock Source bits Mask */
#define ADCHS_ADCCON3_ADCSEL(value)           (ADCHS_ADCCON3_ADCSEL_Msk & (_UINT32_(value) << ADCHS_ADCCON3_ADCSEL_Pos)) /* Assigment of value for ADCSEL in the ADCHS_ADCCON3 register */
#define   ADCHS_ADCCON3_ADCSEL_SYSCLK_Val     _UINT32_(0x3)                                        /* (ADCHS_ADCCON3) SYSCLK  */
#define   ADCHS_ADCCON3_ADCSEL_REFCLK3_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCCON3) REFCLK3  */
#define   ADCHS_ADCCON3_ADCSEL_FRC_Val        _UINT32_(0x1)                                        /* (ADCHS_ADCCON3) FRC  */
#define   ADCHS_ADCCON3_ADCSEL_PBCLK1_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCON3) PBCLK1  */
#define ADCHS_ADCCON3_ADCSEL_SYSCLK           (ADCHS_ADCCON3_ADCSEL_SYSCLK_Val << ADCHS_ADCCON3_ADCSEL_Pos) /* (ADCHS_ADCCON3) SYSCLK Position  */
#define ADCHS_ADCCON3_ADCSEL_REFCLK3          (ADCHS_ADCCON3_ADCSEL_REFCLK3_Val << ADCHS_ADCCON3_ADCSEL_Pos) /* (ADCHS_ADCCON3) REFCLK3 Position  */
#define ADCHS_ADCCON3_ADCSEL_FRC              (ADCHS_ADCCON3_ADCSEL_FRC_Val << ADCHS_ADCCON3_ADCSEL_Pos) /* (ADCHS_ADCCON3) FRC Position  */
#define ADCHS_ADCCON3_ADCSEL_PBCLK1           (ADCHS_ADCCON3_ADCSEL_PBCLK1_Val << ADCHS_ADCCON3_ADCSEL_Pos) /* (ADCHS_ADCCON3) PBCLK1 Position  */
#define ADCHS_ADCCON3_Msk                     _UINT32_(0xFF80FFFF)                                 /* (ADCHS_ADCCON3) Register Mask  */

#define ADCHS_ADCCON3_DIGEN_Pos               _UINT32_(23)                                         /* (ADCHS_ADCCON3 Position) Shared ADC (ADC7) Digital Enable bit */
#define ADCHS_ADCCON3_DIGEN_Msk               (_UINT32_(0x1) << ADCHS_ADCCON3_DIGEN_Pos)           /* (ADCHS_ADCCON3 Mask) DIGEN */
#define ADCHS_ADCCON3_DIGEN(value)            (ADCHS_ADCCON3_DIGEN_Msk & (_UINT32_(value) << ADCHS_ADCCON3_DIGEN_Pos)) 

/* -------- ADCHS_ADCCON3CLR : (ADCHS Offset: 0x24) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCON3CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON3CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCON3CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON3CLR) Register Mask  */


/* -------- ADCHS_ADCCON3SET : (ADCHS Offset: 0x28) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCON3SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON3SET) Bit set register  Reset Value */

#define ADCHS_ADCCON3SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON3SET) Register Mask  */


/* -------- ADCHS_ADCCON3INV : (ADCHS Offset: 0x2C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCON3INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCON3INV) Bit invert register  Reset Value */

#define ADCHS_ADCCON3INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCON3INV) Register Mask  */


/* -------- ADCHS_ADCIMCON1 : (ADCHS Offset: 0x40) (R/W 32)  -------- */
#define ADCHS_ADCIMCON1_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCIMCON1)   Reset Value */

#define ADCHS_ADCIMCON1_SIGN0_Pos             _UINT32_(0)                                          /* (ADCHS_ADCIMCON1) AN0 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN0_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN0_Pos)         /* (ADCHS_ADCIMCON1) AN0 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN0(value)          (ADCHS_ADCIMCON1_SIGN0_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN0_Pos)) /* Assigment of value for SIGN0 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN0_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN0 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN0_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN0 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN0_SIGNED          (ADCHS_ADCIMCON1_SIGN0_SIGNED_Val << ADCHS_ADCIMCON1_SIGN0_Pos) /* (ADCHS_ADCIMCON1) AN0 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN0_UNSIGNED        (ADCHS_ADCIMCON1_SIGN0_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN0_Pos) /* (ADCHS_ADCIMCON1) AN0 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF0_Pos             _UINT32_(1)                                          /* (ADCHS_ADCIMCON1) AN0 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF0_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF0_Pos)         /* (ADCHS_ADCIMCON1) AN0 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF0(value)          (ADCHS_ADCIMCON1_DIFF0_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF0_Pos)) /* Assigment of value for DIFF0 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF0_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN0 differential input pair as AN0+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF0_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN0 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF0_DIFF            (ADCHS_ADCIMCON1_DIFF0_DIFF_Val << ADCHS_ADCIMCON1_DIFF0_Pos) /* (ADCHS_ADCIMCON1) Selects AN0 differential input pair as AN0+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF0_SINGLE          (ADCHS_ADCIMCON1_DIFF0_SINGLE_Val << ADCHS_ADCIMCON1_DIFF0_Pos) /* (ADCHS_ADCIMCON1) AN0 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN1_Pos             _UINT32_(2)                                          /* (ADCHS_ADCIMCON1) AN1 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN1_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN1_Pos)         /* (ADCHS_ADCIMCON1) AN1 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN1(value)          (ADCHS_ADCIMCON1_SIGN1_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN1_Pos)) /* Assigment of value for SIGN1 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN1_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN1 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN1_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN1 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN1_SIGNED          (ADCHS_ADCIMCON1_SIGN1_SIGNED_Val << ADCHS_ADCIMCON1_SIGN1_Pos) /* (ADCHS_ADCIMCON1) AN1 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN1_UNSIGNED        (ADCHS_ADCIMCON1_SIGN1_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN1_Pos) /* (ADCHS_ADCIMCON1) AN1 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF1_Pos             _UINT32_(3)                                          /* (ADCHS_ADCIMCON1) AN1 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF1_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF1_Pos)         /* (ADCHS_ADCIMCON1) AN1 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF1(value)          (ADCHS_ADCIMCON1_DIFF1_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF1_Pos)) /* Assigment of value for DIFF1 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF1_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN1 differential input pair as AN1+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF1_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN1 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF1_DIFF            (ADCHS_ADCIMCON1_DIFF1_DIFF_Val << ADCHS_ADCIMCON1_DIFF1_Pos) /* (ADCHS_ADCIMCON1) Selects AN1 differential input pair as AN1+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF1_SINGLE          (ADCHS_ADCIMCON1_DIFF1_SINGLE_Val << ADCHS_ADCIMCON1_DIFF1_Pos) /* (ADCHS_ADCIMCON1) AN1 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN2_Pos             _UINT32_(4)                                          /* (ADCHS_ADCIMCON1) AN2 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN2_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN2_Pos)         /* (ADCHS_ADCIMCON1) AN2 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN2(value)          (ADCHS_ADCIMCON1_SIGN2_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN2_Pos)) /* Assigment of value for SIGN2 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN2_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN2 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN2_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN2 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN2_SIGNED          (ADCHS_ADCIMCON1_SIGN2_SIGNED_Val << ADCHS_ADCIMCON1_SIGN2_Pos) /* (ADCHS_ADCIMCON1) AN2 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN2_UNSIGNED        (ADCHS_ADCIMCON1_SIGN2_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN2_Pos) /* (ADCHS_ADCIMCON1) AN2 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF2_Pos             _UINT32_(5)                                          /* (ADCHS_ADCIMCON1) AN2 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF2_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF2_Pos)         /* (ADCHS_ADCIMCON1) AN2 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF2(value)          (ADCHS_ADCIMCON1_DIFF2_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF2_Pos)) /* Assigment of value for DIFF2 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF2_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN2 differential input pair as AN2+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF2_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN2 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF2_DIFF            (ADCHS_ADCIMCON1_DIFF2_DIFF_Val << ADCHS_ADCIMCON1_DIFF2_Pos) /* (ADCHS_ADCIMCON1) Selects AN2 differential input pair as AN2+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF2_SINGLE          (ADCHS_ADCIMCON1_DIFF2_SINGLE_Val << ADCHS_ADCIMCON1_DIFF2_Pos) /* (ADCHS_ADCIMCON1) AN2 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN3_Pos             _UINT32_(6)                                          /* (ADCHS_ADCIMCON1) AN3 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN3_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN3_Pos)         /* (ADCHS_ADCIMCON1) AN3 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN3(value)          (ADCHS_ADCIMCON1_SIGN3_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN3_Pos)) /* Assigment of value for SIGN3 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN3_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN3 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN3_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN3 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN3_SIGNED          (ADCHS_ADCIMCON1_SIGN3_SIGNED_Val << ADCHS_ADCIMCON1_SIGN3_Pos) /* (ADCHS_ADCIMCON1) AN3 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN3_UNSIGNED        (ADCHS_ADCIMCON1_SIGN3_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN3_Pos) /* (ADCHS_ADCIMCON1) AN3 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF3_Pos             _UINT32_(7)                                          /* (ADCHS_ADCIMCON1) AN3 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF3_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF3_Pos)         /* (ADCHS_ADCIMCON1) AN3 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF3(value)          (ADCHS_ADCIMCON1_DIFF3_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF3_Pos)) /* Assigment of value for DIFF3 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF3_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN3 differential input pair as AN3+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF3_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN3 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF3_DIFF            (ADCHS_ADCIMCON1_DIFF3_DIFF_Val << ADCHS_ADCIMCON1_DIFF3_Pos) /* (ADCHS_ADCIMCON1) Selects AN3 differential input pair as AN3+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF3_SINGLE          (ADCHS_ADCIMCON1_DIFF3_SINGLE_Val << ADCHS_ADCIMCON1_DIFF3_Pos) /* (ADCHS_ADCIMCON1) AN3 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN4_Pos             _UINT32_(8)                                          /* (ADCHS_ADCIMCON1) AN4 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN4_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN4_Pos)         /* (ADCHS_ADCIMCON1) AN4 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN4(value)          (ADCHS_ADCIMCON1_SIGN4_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN4_Pos)) /* Assigment of value for SIGN4 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN4_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN4 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN4_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN4 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN4_SIGNED          (ADCHS_ADCIMCON1_SIGN4_SIGNED_Val << ADCHS_ADCIMCON1_SIGN4_Pos) /* (ADCHS_ADCIMCON1) AN4 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN4_UNSIGNED        (ADCHS_ADCIMCON1_SIGN4_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN4_Pos) /* (ADCHS_ADCIMCON1) AN4 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF4_Pos             _UINT32_(9)                                          /* (ADCHS_ADCIMCON1) AN4 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF4_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF4_Pos)         /* (ADCHS_ADCIMCON1) AN4 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF4(value)          (ADCHS_ADCIMCON1_DIFF4_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF4_Pos)) /* Assigment of value for DIFF4 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF4_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN4 differential input pair as AN4+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF4_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN4 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF4_DIFF            (ADCHS_ADCIMCON1_DIFF4_DIFF_Val << ADCHS_ADCIMCON1_DIFF4_Pos) /* (ADCHS_ADCIMCON1) Selects AN4 differential input pair as AN4+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF4_SINGLE          (ADCHS_ADCIMCON1_DIFF4_SINGLE_Val << ADCHS_ADCIMCON1_DIFF4_Pos) /* (ADCHS_ADCIMCON1) AN4 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN5_Pos             _UINT32_(10)                                         /* (ADCHS_ADCIMCON1) AN5 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN5_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN5_Pos)         /* (ADCHS_ADCIMCON1) AN5 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN5(value)          (ADCHS_ADCIMCON1_SIGN5_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN5_Pos)) /* Assigment of value for SIGN5 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN5_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN5 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN5_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN5 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN5_SIGNED          (ADCHS_ADCIMCON1_SIGN5_SIGNED_Val << ADCHS_ADCIMCON1_SIGN5_Pos) /* (ADCHS_ADCIMCON1) AN5 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN5_UNSIGNED        (ADCHS_ADCIMCON1_SIGN5_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN5_Pos) /* (ADCHS_ADCIMCON1) AN5 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF5_Pos             _UINT32_(11)                                         /* (ADCHS_ADCIMCON1) AN5 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF5_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF5_Pos)         /* (ADCHS_ADCIMCON1) AN5 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF5(value)          (ADCHS_ADCIMCON1_DIFF5_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF5_Pos)) /* Assigment of value for DIFF5 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF5_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN5 differential input pair as AN5+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF5_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN5 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF5_DIFF            (ADCHS_ADCIMCON1_DIFF5_DIFF_Val << ADCHS_ADCIMCON1_DIFF5_Pos) /* (ADCHS_ADCIMCON1) Selects AN5 differential input pair as AN5+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF5_SINGLE          (ADCHS_ADCIMCON1_DIFF5_SINGLE_Val << ADCHS_ADCIMCON1_DIFF5_Pos) /* (ADCHS_ADCIMCON1) AN5 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN6_Pos             _UINT32_(12)                                         /* (ADCHS_ADCIMCON1) AN6 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN6_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN6_Pos)         /* (ADCHS_ADCIMCON1) AN6 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN6(value)          (ADCHS_ADCIMCON1_SIGN6_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN6_Pos)) /* Assigment of value for SIGN6 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN6_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN6 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN6_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN6 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN6_SIGNED          (ADCHS_ADCIMCON1_SIGN6_SIGNED_Val << ADCHS_ADCIMCON1_SIGN6_Pos) /* (ADCHS_ADCIMCON1) AN6 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN6_UNSIGNED        (ADCHS_ADCIMCON1_SIGN6_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN6_Pos) /* (ADCHS_ADCIMCON1) AN6 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF6_Pos             _UINT32_(13)                                         /* (ADCHS_ADCIMCON1) AN6 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF6_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF6_Pos)         /* (ADCHS_ADCIMCON1) AN6 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF6(value)          (ADCHS_ADCIMCON1_DIFF6_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF6_Pos)) /* Assigment of value for DIFF6 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF6_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN6 differential input pair as AN6+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF6_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN6 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF6_DIFF            (ADCHS_ADCIMCON1_DIFF6_DIFF_Val << ADCHS_ADCIMCON1_DIFF6_Pos) /* (ADCHS_ADCIMCON1) Selects AN6 differential input pair as AN6+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF6_SINGLE          (ADCHS_ADCIMCON1_DIFF6_SINGLE_Val << ADCHS_ADCIMCON1_DIFF6_Pos) /* (ADCHS_ADCIMCON1) AN6 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN7_Pos             _UINT32_(14)                                         /* (ADCHS_ADCIMCON1) AN7 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN7_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN7_Pos)         /* (ADCHS_ADCIMCON1) AN7 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN7(value)          (ADCHS_ADCIMCON1_SIGN7_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN7_Pos)) /* Assigment of value for SIGN7 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN7_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN7 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN7_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN7 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN7_SIGNED          (ADCHS_ADCIMCON1_SIGN7_SIGNED_Val << ADCHS_ADCIMCON1_SIGN7_Pos) /* (ADCHS_ADCIMCON1) AN7 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN7_UNSIGNED        (ADCHS_ADCIMCON1_SIGN7_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN7_Pos) /* (ADCHS_ADCIMCON1) AN7 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF7_Pos             _UINT32_(15)                                         /* (ADCHS_ADCIMCON1) AN7 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF7_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF7_Pos)         /* (ADCHS_ADCIMCON1) AN7 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF7(value)          (ADCHS_ADCIMCON1_DIFF7_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF7_Pos)) /* Assigment of value for DIFF7 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF7_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN7 differential input pair as AN7+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF7_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN7 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF7_DIFF            (ADCHS_ADCIMCON1_DIFF7_DIFF_Val << ADCHS_ADCIMCON1_DIFF7_Pos) /* (ADCHS_ADCIMCON1) Selects AN7 differential input pair as AN7+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF7_SINGLE          (ADCHS_ADCIMCON1_DIFF7_SINGLE_Val << ADCHS_ADCIMCON1_DIFF7_Pos) /* (ADCHS_ADCIMCON1) AN7 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN8_Pos             _UINT32_(16)                                         /* (ADCHS_ADCIMCON1) AN8 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN8_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN8_Pos)         /* (ADCHS_ADCIMCON1) AN8 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN8(value)          (ADCHS_ADCIMCON1_SIGN8_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN8_Pos)) /* Assigment of value for SIGN8 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN8_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN8 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN8_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN8 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN8_SIGNED          (ADCHS_ADCIMCON1_SIGN8_SIGNED_Val << ADCHS_ADCIMCON1_SIGN8_Pos) /* (ADCHS_ADCIMCON1) AN8 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN8_UNSIGNED        (ADCHS_ADCIMCON1_SIGN8_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN8_Pos) /* (ADCHS_ADCIMCON1) AN8 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF8_Pos             _UINT32_(17)                                         /* (ADCHS_ADCIMCON1) AN 8 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF8_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF8_Pos)         /* (ADCHS_ADCIMCON1) AN 8 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF8(value)          (ADCHS_ADCIMCON1_DIFF8_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF8_Pos)) /* Assigment of value for DIFF8 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF8_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN8 differential input pair as AN8+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF8_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN8 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF8_DIFF            (ADCHS_ADCIMCON1_DIFF8_DIFF_Val << ADCHS_ADCIMCON1_DIFF8_Pos) /* (ADCHS_ADCIMCON1) Selects AN8 differential input pair as AN8+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF8_SINGLE          (ADCHS_ADCIMCON1_DIFF8_SINGLE_Val << ADCHS_ADCIMCON1_DIFF8_Pos) /* (ADCHS_ADCIMCON1) AN8 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN9_Pos             _UINT32_(18)                                         /* (ADCHS_ADCIMCON1) AN9 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN9_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN9_Pos)         /* (ADCHS_ADCIMCON1) AN9 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN9(value)          (ADCHS_ADCIMCON1_SIGN9_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN9_Pos)) /* Assigment of value for SIGN9 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN9_SIGNED_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN9 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN9_UNSIGNED_Val  _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN9 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN9_SIGNED          (ADCHS_ADCIMCON1_SIGN9_SIGNED_Val << ADCHS_ADCIMCON1_SIGN9_Pos) /* (ADCHS_ADCIMCON1) AN9 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN9_UNSIGNED        (ADCHS_ADCIMCON1_SIGN9_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN9_Pos) /* (ADCHS_ADCIMCON1) AN9 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF9_Pos             _UINT32_(19)                                         /* (ADCHS_ADCIMCON1) AN9 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF9_Msk             (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF9_Pos)         /* (ADCHS_ADCIMCON1) AN9 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF9(value)          (ADCHS_ADCIMCON1_DIFF9_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF9_Pos)) /* Assigment of value for DIFF9 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF9_DIFF_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN9 differential input pair as AN9+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF9_SINGLE_Val    _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN9 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF9_DIFF            (ADCHS_ADCIMCON1_DIFF9_DIFF_Val << ADCHS_ADCIMCON1_DIFF9_Pos) /* (ADCHS_ADCIMCON1) Selects AN9 differential input pair as AN9+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF9_SINGLE          (ADCHS_ADCIMCON1_DIFF9_SINGLE_Val << ADCHS_ADCIMCON1_DIFF9_Pos) /* (ADCHS_ADCIMCON1) AN9 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN10_Pos            _UINT32_(20)                                         /* (ADCHS_ADCIMCON1) AN10 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN10_Msk            (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN10_Pos)        /* (ADCHS_ADCIMCON1) AN10 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN10(value)         (ADCHS_ADCIMCON1_SIGN10_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN10_Pos)) /* Assigment of value for SIGN10 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN10_SIGNED_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN10 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN10_UNSIGNED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN10 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN10_SIGNED         (ADCHS_ADCIMCON1_SIGN10_SIGNED_Val << ADCHS_ADCIMCON1_SIGN10_Pos) /* (ADCHS_ADCIMCON1) AN10 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN10_UNSIGNED       (ADCHS_ADCIMCON1_SIGN10_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN10_Pos) /* (ADCHS_ADCIMCON1) AN10 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF10_Pos            _UINT32_(21)                                         /* (ADCHS_ADCIMCON1) AN10 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF10_Msk            (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF10_Pos)        /* (ADCHS_ADCIMCON1) AN10 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF10(value)         (ADCHS_ADCIMCON1_DIFF10_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF10_Pos)) /* Assigment of value for DIFF10 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF10_DIFF_Val     _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN10 differential input pair as AN10+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF10_SINGLE_Val   _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN10 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF10_DIFF           (ADCHS_ADCIMCON1_DIFF10_DIFF_Val << ADCHS_ADCIMCON1_DIFF10_Pos) /* (ADCHS_ADCIMCON1) Selects AN10 differential input pair as AN10+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF10_SINGLE         (ADCHS_ADCIMCON1_DIFF10_SINGLE_Val << ADCHS_ADCIMCON1_DIFF10_Pos) /* (ADCHS_ADCIMCON1) AN10 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_SIGN11_Pos            _UINT32_(22)                                         /* (ADCHS_ADCIMCON1) AN11 Signed Data Mode bit Position */
#define ADCHS_ADCIMCON1_SIGN11_Msk            (_UINT32_(0x1) << ADCHS_ADCIMCON1_SIGN11_Pos)        /* (ADCHS_ADCIMCON1) AN11 Signed Data Mode bit Mask */
#define ADCHS_ADCIMCON1_SIGN11(value)         (ADCHS_ADCIMCON1_SIGN11_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_SIGN11_Pos)) /* Assigment of value for SIGN11 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_SIGN11_SIGNED_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) AN11 is using Signed Data mode  */
#define   ADCHS_ADCIMCON1_SIGN11_UNSIGNED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN11 is using Unsigned Data mode  */
#define ADCHS_ADCIMCON1_SIGN11_SIGNED         (ADCHS_ADCIMCON1_SIGN11_SIGNED_Val << ADCHS_ADCIMCON1_SIGN11_Pos) /* (ADCHS_ADCIMCON1) AN11 is using Signed Data mode Position  */
#define ADCHS_ADCIMCON1_SIGN11_UNSIGNED       (ADCHS_ADCIMCON1_SIGN11_UNSIGNED_Val << ADCHS_ADCIMCON1_SIGN11_Pos) /* (ADCHS_ADCIMCON1) AN11 is using Unsigned Data mode Position  */
#define ADCHS_ADCIMCON1_DIFF11_Pos            _UINT32_(23)                                         /* (ADCHS_ADCIMCON1) AN11 Mode bit Position */
#define ADCHS_ADCIMCON1_DIFF11_Msk            (_UINT32_(0x1) << ADCHS_ADCIMCON1_DIFF11_Pos)        /* (ADCHS_ADCIMCON1) AN11 Mode bit Mask */
#define ADCHS_ADCIMCON1_DIFF11(value)         (ADCHS_ADCIMCON1_DIFF11_Msk & (_UINT32_(value) << ADCHS_ADCIMCON1_DIFF11_Pos)) /* Assigment of value for DIFF11 in the ADCHS_ADCIMCON1 register */
#define   ADCHS_ADCIMCON1_DIFF11_DIFF_Val     _UINT32_(0x1)                                        /* (ADCHS_ADCIMCON1) Selects AN11 differential input pair as AN11+ and ANN0-  */
#define   ADCHS_ADCIMCON1_DIFF11_SINGLE_Val   _UINT32_(0x0)                                        /* (ADCHS_ADCIMCON1) AN11 is using Single-ended mode  */
#define ADCHS_ADCIMCON1_DIFF11_DIFF           (ADCHS_ADCIMCON1_DIFF11_DIFF_Val << ADCHS_ADCIMCON1_DIFF11_Pos) /* (ADCHS_ADCIMCON1) Selects AN11 differential input pair as AN11+ and ANN0- Position  */
#define ADCHS_ADCIMCON1_DIFF11_SINGLE         (ADCHS_ADCIMCON1_DIFF11_SINGLE_Val << ADCHS_ADCIMCON1_DIFF11_Pos) /* (ADCHS_ADCIMCON1) AN11 is using Single-ended mode Position  */
#define ADCHS_ADCIMCON1_Msk                   _UINT32_(0x00FFFFFF)                                 /* (ADCHS_ADCIMCON1) Register Mask  */


/* -------- ADCHS_ADCIMOD1CLR : (ADCHS Offset: 0x44) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCIMOD1CLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCIMOD1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCIMOD1CLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCIMOD1CLR) Register Mask  */


/* -------- ADCHS_ADCIMOD1SET : (ADCHS Offset: 0x48) (R/W 32) Bit set register -------- */
#define ADCHS_ADCIMOD1SET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCIMOD1SET) Bit set register  Reset Value */

#define ADCHS_ADCIMOD1SET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCIMOD1SET) Register Mask  */


/* -------- ADCHS_ADCIMOD1INV : (ADCHS Offset: 0x4C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCIMOD1INV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCIMOD1INV) Bit invert register  Reset Value */

#define ADCHS_ADCIMOD1INV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCIMOD1INV) Register Mask  */


/* -------- ADCHS_ADCGIRQEN1 : (ADCHS Offset: 0x80) (R/W 32)  -------- */
#define ADCHS_ADCGIRQEN1_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCGIRQEN1)   Reset Value */

#define ADCHS_ADCGIRQEN1_AGIEN0_Pos           _UINT32_(0)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN0_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN0_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN0(value)        (ADCHS_ADCGIRQEN1_AGIEN0_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN0_Pos)) /* Assigment of value for AGIEN0 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN0_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN0_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN0_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN0_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN0_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN0_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN0_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN0_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN1_Pos           _UINT32_(1)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN1_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN1_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN1(value)        (ADCHS_ADCGIRQEN1_AGIEN1_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN1_Pos)) /* Assigment of value for AGIEN1 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN1_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN1_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN1_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN1_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN1_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN1_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN1_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN1_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN2_Pos           _UINT32_(2)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN2_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN2_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN2(value)        (ADCHS_ADCGIRQEN1_AGIEN2_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN2_Pos)) /* Assigment of value for AGIEN2 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN2_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN2_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN2_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN2_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN2_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN2_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN2_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN2_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN3_Pos           _UINT32_(3)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN3_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN3_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN3(value)        (ADCHS_ADCGIRQEN1_AGIEN3_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN3_Pos)) /* Assigment of value for AGIEN3 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN3_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN3_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN3_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN3_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN3_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN3_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN3_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN3_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN4_Pos           _UINT32_(4)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN4_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN4_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN4(value)        (ADCHS_ADCGIRQEN1_AGIEN4_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN4_Pos)) /* Assigment of value for AGIEN4 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN4_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN4_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN4_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN4_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN4_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN4_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN4_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN4_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN5_Pos           _UINT32_(5)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN5_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN5_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN5(value)        (ADCHS_ADCGIRQEN1_AGIEN5_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN5_Pos)) /* Assigment of value for AGIEN5 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN5_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN5_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN5_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN5_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN5_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN5_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN5_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN5_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN6_Pos           _UINT32_(6)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN6_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN6_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN6(value)        (ADCHS_ADCGIRQEN1_AGIEN6_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN6_Pos)) /* Assigment of value for AGIEN6 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN6_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN6_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN6_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN6_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN6_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN6_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN6_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN6_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN7_Pos           _UINT32_(7)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN7_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN7_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN7(value)        (ADCHS_ADCGIRQEN1_AGIEN7_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN7_Pos)) /* Assigment of value for AGIEN7 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN7_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN7_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN7_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN7_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN7_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN7_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN7_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN7_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN8_Pos           _UINT32_(8)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN8_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN8_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN8(value)        (ADCHS_ADCGIRQEN1_AGIEN8_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN8_Pos)) /* Assigment of value for AGIEN8 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN8_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN8_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN8_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN8_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN8_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN8_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN8_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN8_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN9_Pos           _UINT32_(9)                                          /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN9_Msk           (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN9_Pos)       /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN9(value)        (ADCHS_ADCGIRQEN1_AGIEN9_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN9_Pos)) /* Assigment of value for AGIEN9 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN9_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN9_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN9_ENABLED       (ADCHS_ADCGIRQEN1_AGIEN9_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN9_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN9_DISABLED      (ADCHS_ADCGIRQEN1_AGIEN9_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN9_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN10_Pos          _UINT32_(10)                                         /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN10_Msk          (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN10_Pos)      /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN10(value)       (ADCHS_ADCGIRQEN1_AGIEN10_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN10_Pos)) /* Assigment of value for AGIEN10 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN10_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN10_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN10_ENABLED      (ADCHS_ADCGIRQEN1_AGIEN10_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN10_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN10_DISABLED     (ADCHS_ADCGIRQEN1_AGIEN10_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN10_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_AGIEN11_Pos          _UINT32_(11)                                         /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Position */
#define ADCHS_ADCGIRQEN1_AGIEN11_Msk          (_UINT32_(0x1) << ADCHS_ADCGIRQEN1_AGIEN11_Pos)      /* (ADCHS_ADCGIRQEN1) ADC Global Interrupt Enable bit Mask */
#define ADCHS_ADCGIRQEN1_AGIEN11(value)       (ADCHS_ADCGIRQEN1_AGIEN11_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN11_Pos)) /* Assigment of value for AGIEN11 in the ADCHS_ADCGIRQEN1 register */
#define   ADCHS_ADCGIRQEN1_AGIEN11_ENABLED_Val _UINT32_(0x1)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register)  */
#define   ADCHS_ADCGIRQEN1_AGIEN11_DISABLED_Val _UINT32_(0x0)                                        /* (ADCHS_ADCGIRQEN1) Interrupts are disabled  */
#define ADCHS_ADCGIRQEN1_AGIEN11_ENABLED      (ADCHS_ADCGIRQEN1_AGIEN11_ENABLED_Val << ADCHS_ADCGIRQEN1_AGIEN11_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are enabled for the selected analog input. The interrupt is generated after the converted data is ready (indicated by the AIRDYx bit of the ADCDSTAT1 register) Position  */
#define ADCHS_ADCGIRQEN1_AGIEN11_DISABLED     (ADCHS_ADCGIRQEN1_AGIEN11_DISABLED_Val << ADCHS_ADCGIRQEN1_AGIEN11_Pos) /* (ADCHS_ADCGIRQEN1) Interrupts are disabled Position  */
#define ADCHS_ADCGIRQEN1_Msk                  _UINT32_(0x00000FFF)                                 /* (ADCHS_ADCGIRQEN1) Register Mask  */

#define ADCHS_ADCGIRQEN1_AGIEN_Pos            _UINT32_(0)                                          /* (ADCHS_ADCGIRQEN1 Position) ADC Global Interrupt Enable bit */
#define ADCHS_ADCGIRQEN1_AGIEN_Msk            (_UINT32_(0xFFF) << ADCHS_ADCGIRQEN1_AGIEN_Pos)      /* (ADCHS_ADCGIRQEN1 Mask) AGIEN */
#define ADCHS_ADCGIRQEN1_AGIEN(value)         (ADCHS_ADCGIRQEN1_AGIEN_Msk & (_UINT32_(value) << ADCHS_ADCGIRQEN1_AGIEN_Pos)) 

/* -------- ADCHS_ADCGIRQEN1CLR : (ADCHS Offset: 0x84) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCGIRQEN1CLR_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCGIRQEN1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCGIRQEN1CLR_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCGIRQEN1CLR) Register Mask  */


/* -------- ADCHS_ADCGIRQEN1SET : (ADCHS Offset: 0x88) (R/W 32) Bit set register -------- */
#define ADCHS_ADCGIRQEN1SET_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCGIRQEN1SET) Bit set register  Reset Value */

#define ADCHS_ADCGIRQEN1SET_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCGIRQEN1SET) Register Mask  */


/* -------- ADCHS_ADCGIRQEN1INV : (ADCHS Offset: 0x8C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCGIRQEN1INV_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCGIRQEN1INV) Bit invert register  Reset Value */

#define ADCHS_ADCGIRQEN1INV_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCGIRQEN1INV) Register Mask  */


/* -------- ADCHS_ADCCSS1 : (ADCHS Offset: 0xA0) (R/W 32)  -------- */
#define ADCHS_ADCCSS1_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCSS1)   Reset Value */

#define ADCHS_ADCCSS1_CSS0_Pos                _UINT32_(0)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS0_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS0_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS0(value)             (ADCHS_ADCCSS1_CSS0_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS0_Pos)) /* Assigment of value for CSS0 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS0_SEL_AN0_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS0_SKIP_AN0_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS0_SEL_AN0            (ADCHS_ADCCSS1_CSS0_SEL_AN0_Val << ADCHS_ADCCSS1_CSS0_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS0_SKIP_AN0           (ADCHS_ADCCSS1_CSS0_SKIP_AN0_Val << ADCHS_ADCCSS1_CSS0_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS1_Pos                _UINT32_(1)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS1_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS1_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS1(value)             (ADCHS_ADCCSS1_CSS1_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS1_Pos)) /* Assigment of value for CSS1 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS1_SEL_AN1_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS1_SKIP_AN1_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS1_SEL_AN1            (ADCHS_ADCCSS1_CSS1_SEL_AN1_Val << ADCHS_ADCCSS1_CSS1_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS1_SKIP_AN1           (ADCHS_ADCCSS1_CSS1_SKIP_AN1_Val << ADCHS_ADCCSS1_CSS1_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS2_Pos                _UINT32_(2)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS2_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS2_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS2(value)             (ADCHS_ADCCSS1_CSS2_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS2_Pos)) /* Assigment of value for CSS2 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS2_SEL_AN2_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS2_SKIP_AN2_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS2_SEL_AN2            (ADCHS_ADCCSS1_CSS2_SEL_AN2_Val << ADCHS_ADCCSS1_CSS2_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS2_SKIP_AN2           (ADCHS_ADCCSS1_CSS2_SKIP_AN2_Val << ADCHS_ADCCSS1_CSS2_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS3_Pos                _UINT32_(3)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS3_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS3_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS3(value)             (ADCHS_ADCCSS1_CSS3_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS3_Pos)) /* Assigment of value for CSS3 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS3_SEL_AN3_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS3_SKIP_AN3_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS3_SEL_AN3            (ADCHS_ADCCSS1_CSS3_SEL_AN3_Val << ADCHS_ADCCSS1_CSS3_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS3_SKIP_AN3           (ADCHS_ADCCSS1_CSS3_SKIP_AN3_Val << ADCHS_ADCCSS1_CSS3_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS4_Pos                _UINT32_(4)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS4_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS4_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS4(value)             (ADCHS_ADCCSS1_CSS4_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS4_Pos)) /* Assigment of value for CSS4 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS4_SEL_AN4_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS4_SKIP_AN4_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS4_SEL_AN4            (ADCHS_ADCCSS1_CSS4_SEL_AN4_Val << ADCHS_ADCCSS1_CSS4_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS4_SKIP_AN4           (ADCHS_ADCCSS1_CSS4_SKIP_AN4_Val << ADCHS_ADCCSS1_CSS4_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS5_Pos                _UINT32_(5)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS5_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS5_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS5(value)             (ADCHS_ADCCSS1_CSS5_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS5_Pos)) /* Assigment of value for CSS5 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS5_SEL_AN5_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS5_SKIP_AN5_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS5_SEL_AN5            (ADCHS_ADCCSS1_CSS5_SEL_AN5_Val << ADCHS_ADCCSS1_CSS5_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS5_SKIP_AN5           (ADCHS_ADCCSS1_CSS5_SKIP_AN5_Val << ADCHS_ADCCSS1_CSS5_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS6_Pos                _UINT32_(6)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS6_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS6_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS6(value)             (ADCHS_ADCCSS1_CSS6_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS6_Pos)) /* Assigment of value for CSS6 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS6_SEL_AN6_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS6_SKIP_AN6_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS6_SEL_AN6            (ADCHS_ADCCSS1_CSS6_SEL_AN6_Val << ADCHS_ADCCSS1_CSS6_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS6_SKIP_AN6           (ADCHS_ADCCSS1_CSS6_SKIP_AN6_Val << ADCHS_ADCCSS1_CSS6_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS7_Pos                _UINT32_(7)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS7_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS7_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS7(value)             (ADCHS_ADCCSS1_CSS7_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS7_Pos)) /* Assigment of value for CSS7 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS7_SEL_AN7_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS7_SKIP_AN7_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS7_SEL_AN7            (ADCHS_ADCCSS1_CSS7_SEL_AN7_Val << ADCHS_ADCCSS1_CSS7_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS7_SKIP_AN7           (ADCHS_ADCCSS1_CSS7_SKIP_AN7_Val << ADCHS_ADCCSS1_CSS7_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS8_Pos                _UINT32_(8)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS8_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS8_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS8(value)             (ADCHS_ADCCSS1_CSS8_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS8_Pos)) /* Assigment of value for CSS8 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS8_SEL_AN8_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS8_SKIP_AN8_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS8_SEL_AN8            (ADCHS_ADCCSS1_CSS8_SEL_AN8_Val << ADCHS_ADCCSS1_CSS8_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS8_SKIP_AN8           (ADCHS_ADCCSS1_CSS8_SKIP_AN8_Val << ADCHS_ADCCSS1_CSS8_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS9_Pos                _UINT32_(9)                                          /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS9_Msk                (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS9_Pos)            /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS9(value)             (ADCHS_ADCCSS1_CSS9_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS9_Pos)) /* Assigment of value for CSS9 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS9_SEL_AN9_Val      _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS9_SKIP_AN9_Val     _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS9_SEL_AN9            (ADCHS_ADCCSS1_CSS9_SEL_AN9_Val << ADCHS_ADCCSS1_CSS9_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS9_SKIP_AN9           (ADCHS_ADCCSS1_CSS9_SKIP_AN9_Val << ADCHS_ADCCSS1_CSS9_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS10_Pos               _UINT32_(10)                                         /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS10_Msk               (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS10_Pos)           /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS10(value)            (ADCHS_ADCCSS1_CSS10_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS10_Pos)) /* Assigment of value for CSS10 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS10_SEL_AN10_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS10_SKIP_AN10_Val   _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS10_SEL_AN10          (ADCHS_ADCCSS1_CSS10_SEL_AN10_Val << ADCHS_ADCCSS1_CSS10_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS10_SKIP_AN10         (ADCHS_ADCCSS1_CSS10_SKIP_AN10_Val << ADCHS_ADCCSS1_CSS10_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_CSS11_Pos               _UINT32_(11)                                         /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Position */
#define ADCHS_ADCCSS1_CSS11_Msk               (_UINT32_(0x1) << ADCHS_ADCCSS1_CSS11_Pos)           /* (ADCHS_ADCCSS1) Analog Common Scan Select bits Mask */
#define ADCHS_ADCCSS1_CSS11(value)            (ADCHS_ADCCSS1_CSS11_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS11_Pos)) /* Assigment of value for CSS11 in the ADCHS_ADCCSS1 register */
#define   ADCHS_ADCCSS1_CSS11_SEL_AN11_Val    _UINT32_(0x1)                                        /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin)  */
#define   ADCHS_ADCCSS1_CSS11_SKIP_AN11_Val   _UINT32_(0x0)                                        /* (ADCHS_ADCCSS1) Skip ANx for input scan  */
#define ADCHS_ADCCSS1_CSS11_SEL_AN11          (ADCHS_ADCCSS1_CSS11_SEL_AN11_Val << ADCHS_ADCCSS1_CSS11_Pos) /* (ADCHS_ADCCSS1) Select ANx for input scan (i.e.ANx = CSSx and scan is sequential starting with the lowest to highest enabled CSSx analog input pin) Position  */
#define ADCHS_ADCCSS1_CSS11_SKIP_AN11         (ADCHS_ADCCSS1_CSS11_SKIP_AN11_Val << ADCHS_ADCCSS1_CSS11_Pos) /* (ADCHS_ADCCSS1) Skip ANx for input scan Position  */
#define ADCHS_ADCCSS1_Msk                     _UINT32_(0x00000FFF)                                 /* (ADCHS_ADCCSS1) Register Mask  */

#define ADCHS_ADCCSS1_CSS_Pos                 _UINT32_(0)                                          /* (ADCHS_ADCCSS1 Position) Analog Common Scan Select bits */
#define ADCHS_ADCCSS1_CSS_Msk                 (_UINT32_(0xFFF) << ADCHS_ADCCSS1_CSS_Pos)           /* (ADCHS_ADCCSS1 Mask) CSS */
#define ADCHS_ADCCSS1_CSS(value)              (ADCHS_ADCCSS1_CSS_Msk & (_UINT32_(value) << ADCHS_ADCCSS1_CSS_Pos)) 

/* -------- ADCHS_ADCCSS1CLR : (ADCHS Offset: 0xA4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCSS1CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCSS1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCSS1CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCSS1CLR) Register Mask  */


/* -------- ADCHS_ADCCSS1SET : (ADCHS Offset: 0xA8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCSS1SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCSS1SET) Bit set register  Reset Value */

#define ADCHS_ADCCSS1SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCSS1SET) Register Mask  */


/* -------- ADCHS_ADCCSS1INV : (ADCHS Offset: 0xAC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCSS1INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCSS1INV) Bit invert register  Reset Value */

#define ADCHS_ADCCSS1INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCSS1INV) Register Mask  */


/* -------- ADCHS_ADCDSTAT1 : (ADCHS Offset: 0xC0) (R/W 32)  -------- */
#define ADCHS_ADCDSTAT1_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCDSTAT1)   Reset Value */

#define ADCHS_ADCDSTAT1_ARDY0_Pos             _UINT32_(0)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY0_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY0_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY0(value)          (ADCHS_ADCDSTAT1_ARDY0_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY0_Pos)) /* Assigment of value for ARDY0 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY1_Pos             _UINT32_(1)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY1_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY1_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY1(value)          (ADCHS_ADCDSTAT1_ARDY1_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY1_Pos)) /* Assigment of value for ARDY1 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY2_Pos             _UINT32_(2)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY2_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY2_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY2(value)          (ADCHS_ADCDSTAT1_ARDY2_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY2_Pos)) /* Assigment of value for ARDY2 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY3_Pos             _UINT32_(3)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY3_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY3_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY3(value)          (ADCHS_ADCDSTAT1_ARDY3_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY3_Pos)) /* Assigment of value for ARDY3 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY4_Pos             _UINT32_(4)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY4_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY4_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY4(value)          (ADCHS_ADCDSTAT1_ARDY4_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY4_Pos)) /* Assigment of value for ARDY4 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY5_Pos             _UINT32_(5)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY5_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY5_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY5(value)          (ADCHS_ADCDSTAT1_ARDY5_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY5_Pos)) /* Assigment of value for ARDY5 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY6_Pos             _UINT32_(6)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY6_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY6_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY6(value)          (ADCHS_ADCDSTAT1_ARDY6_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY6_Pos)) /* Assigment of value for ARDY6 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY7_Pos             _UINT32_(7)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY7_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY7_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY7(value)          (ADCHS_ADCDSTAT1_ARDY7_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY7_Pos)) /* Assigment of value for ARDY7 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY8_Pos             _UINT32_(8)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY8_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY8_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY8(value)          (ADCHS_ADCDSTAT1_ARDY8_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY8_Pos)) /* Assigment of value for ARDY8 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY9_Pos             _UINT32_(9)                                          /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY9_Msk             (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY9_Pos)         /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY9(value)          (ADCHS_ADCDSTAT1_ARDY9_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY9_Pos)) /* Assigment of value for ARDY9 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY10_Pos            _UINT32_(10)                                         /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY10_Msk            (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY10_Pos)        /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY10(value)         (ADCHS_ADCDSTAT1_ARDY10_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY10_Pos)) /* Assigment of value for ARDY10 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_ARDY11_Pos            _UINT32_(11)                                         /* (ADCHS_ADCDSTAT1)  Position */
#define ADCHS_ADCDSTAT1_ARDY11_Msk            (_UINT32_(0x1) << ADCHS_ADCDSTAT1_ARDY11_Pos)        /* (ADCHS_ADCDSTAT1)  Mask */
#define ADCHS_ADCDSTAT1_ARDY11(value)         (ADCHS_ADCDSTAT1_ARDY11_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY11_Pos)) /* Assigment of value for ARDY11 in the ADCHS_ADCDSTAT1 register */
#define ADCHS_ADCDSTAT1_Msk                   _UINT32_(0x00000FFF)                                 /* (ADCHS_ADCDSTAT1) Register Mask  */

#define ADCHS_ADCDSTAT1_ARDY_Pos              _UINT32_(0)                                          /* (ADCHS_ADCDSTAT1 Position)  */
#define ADCHS_ADCDSTAT1_ARDY_Msk              (_UINT32_(0xFFF) << ADCHS_ADCDSTAT1_ARDY_Pos)        /* (ADCHS_ADCDSTAT1 Mask) ARDY */
#define ADCHS_ADCDSTAT1_ARDY(value)           (ADCHS_ADCDSTAT1_ARDY_Msk & (_UINT32_(value) << ADCHS_ADCDSTAT1_ARDY_Pos)) 

/* -------- ADCHS_ADCDSTAT1CLR : (ADCHS Offset: 0xC4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCDSTAT1CLR_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCDSTAT1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCDSTAT1CLR_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCDSTAT1CLR) Register Mask  */


/* -------- ADCHS_ADCDSTAT1SET : (ADCHS Offset: 0xC8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCDSTAT1SET_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCDSTAT1SET) Bit set register  Reset Value */

#define ADCHS_ADCDSTAT1SET_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCDSTAT1SET) Register Mask  */


/* -------- ADCHS_ADCDSTAT1INV : (ADCHS Offset: 0xCC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCDSTAT1INV_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCDSTAT1INV) Bit invert register  Reset Value */

#define ADCHS_ADCDSTAT1INV_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCDSTAT1INV) Register Mask  */


/* -------- ADCHS_ADCCMPEN1 : (ADCHS Offset: 0xE0) (R/W 32)  -------- */
#define ADCHS_ADCCMPEN1_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN1)   Reset Value */

#define ADCHS_ADCCMPEN1_CMPE0_Pos             _UINT32_(0)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE0_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE0_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE0(value)          (ADCHS_ADCCMPEN1_CMPE0_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE0_Pos)) /* Assigment of value for CMPE0 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE1_Pos             _UINT32_(1)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE1_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE1_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE1(value)          (ADCHS_ADCCMPEN1_CMPE1_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE1_Pos)) /* Assigment of value for CMPE1 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE2_Pos             _UINT32_(2)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE2_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE2_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE2(value)          (ADCHS_ADCCMPEN1_CMPE2_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE2_Pos)) /* Assigment of value for CMPE2 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE3_Pos             _UINT32_(3)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE3_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE3_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE3(value)          (ADCHS_ADCCMPEN1_CMPE3_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE3_Pos)) /* Assigment of value for CMPE3 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE4_Pos             _UINT32_(4)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE4_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE4_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE4(value)          (ADCHS_ADCCMPEN1_CMPE4_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE4_Pos)) /* Assigment of value for CMPE4 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE5_Pos             _UINT32_(5)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE5_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE5_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE5(value)          (ADCHS_ADCCMPEN1_CMPE5_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE5_Pos)) /* Assigment of value for CMPE5 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE6_Pos             _UINT32_(6)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE6_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE6_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE6(value)          (ADCHS_ADCCMPEN1_CMPE6_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE6_Pos)) /* Assigment of value for CMPE6 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_CMPE7_Pos             _UINT32_(7)                                          /* (ADCHS_ADCCMPEN1)  Position */
#define ADCHS_ADCCMPEN1_CMPE7_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN1_CMPE7_Pos)         /* (ADCHS_ADCCMPEN1)  Mask */
#define ADCHS_ADCCMPEN1_CMPE7(value)          (ADCHS_ADCCMPEN1_CMPE7_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE7_Pos)) /* Assigment of value for CMPE7 in the ADCHS_ADCCMPEN1 register */
#define ADCHS_ADCCMPEN1_Msk                   _UINT32_(0x000000FF)                                 /* (ADCHS_ADCCMPEN1) Register Mask  */

#define ADCHS_ADCCMPEN1_CMPE_Pos              _UINT32_(0)                                          /* (ADCHS_ADCCMPEN1 Position)  */
#define ADCHS_ADCCMPEN1_CMPE_Msk              (_UINT32_(0xFF) << ADCHS_ADCCMPEN1_CMPE_Pos)         /* (ADCHS_ADCCMPEN1 Mask) CMPE */
#define ADCHS_ADCCMPEN1_CMPE(value)           (ADCHS_ADCCMPEN1_CMPE_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN1_CMPE_Pos)) 

/* -------- ADCHS_ADCCMPEN0CLR : (ADCHS Offset: 0xE4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCMPEN0CLR_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN0CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCMPEN0CLR_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPEN0CLR) Register Mask  */


/* -------- ADCHS_ADCCMPEN0SET : (ADCHS Offset: 0xE8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCMPEN0SET_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN0SET) Bit set register  Reset Value */

#define ADCHS_ADCCMPEN0SET_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPEN0SET) Register Mask  */


/* -------- ADCHS_ADCCMPEN0INV : (ADCHS Offset: 0xEC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCMPEN0INV_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN0INV) Bit invert register  Reset Value */

#define ADCHS_ADCCMPEN0INV_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPEN0INV) Register Mask  */


/* -------- ADCHS_ADCCMP1 : (ADCHS Offset: 0xF0) (R/W 32)  -------- */
#define ADCHS_ADCCMP1_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCMP1)   Reset Value */

#define ADCHS_ADCCMP1_ADCMPLO_Pos             _UINT32_(0)                                          /* (ADCHS_ADCCMP1)  Position */
#define ADCHS_ADCCMP1_ADCMPLO_Msk             (_UINT32_(0xFFFF) << ADCHS_ADCCMP1_ADCMPLO_Pos)      /* (ADCHS_ADCCMP1)  Mask */
#define ADCHS_ADCCMP1_ADCMPLO(value)          (ADCHS_ADCCMP1_ADCMPLO_Msk & (_UINT32_(value) << ADCHS_ADCCMP1_ADCMPLO_Pos)) /* Assigment of value for ADCMPLO in the ADCHS_ADCCMP1 register */
#define ADCHS_ADCCMP1_ADCMPHI_Pos             _UINT32_(16)                                         /* (ADCHS_ADCCMP1)  Position */
#define ADCHS_ADCCMP1_ADCMPHI_Msk             (_UINT32_(0xFFFF) << ADCHS_ADCCMP1_ADCMPHI_Pos)      /* (ADCHS_ADCCMP1)  Mask */
#define ADCHS_ADCCMP1_ADCMPHI(value)          (ADCHS_ADCCMP1_ADCMPHI_Msk & (_UINT32_(value) << ADCHS_ADCCMP1_ADCMPHI_Pos)) /* Assigment of value for ADCMPHI in the ADCHS_ADCCMP1 register */
#define ADCHS_ADCCMP1_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCCMP1) Register Mask  */


/* -------- ADCHS_ADCCMP0CLR : (ADCHS Offset: 0xF4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCMP0CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCMP0CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCMP0CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMP0CLR) Register Mask  */


/* -------- ADCHS_ADCCMP0SET : (ADCHS Offset: 0xF8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCMP0SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCMP0SET) Bit set register  Reset Value */

#define ADCHS_ADCCMP0SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMP0SET) Register Mask  */


/* -------- ADCHS_ADCCMP0INV : (ADCHS Offset: 0xFC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCMP0INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCMP0INV) Bit invert register  Reset Value */

#define ADCHS_ADCCMP0INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMP0INV) Register Mask  */


/* -------- ADCHS_ADCCMPEN2 : (ADCHS Offset: 0x100) (R/W 32)  -------- */
#define ADCHS_ADCCMPEN2_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN2)   Reset Value */

#define ADCHS_ADCCMPEN2_CMPE0_Pos             _UINT32_(0)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE0_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE0_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE0(value)          (ADCHS_ADCCMPEN2_CMPE0_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE0_Pos)) /* Assigment of value for CMPE0 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE1_Pos             _UINT32_(1)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE1_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE1_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE1(value)          (ADCHS_ADCCMPEN2_CMPE1_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE1_Pos)) /* Assigment of value for CMPE1 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE2_Pos             _UINT32_(2)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE2_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE2_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE2(value)          (ADCHS_ADCCMPEN2_CMPE2_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE2_Pos)) /* Assigment of value for CMPE2 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE3_Pos             _UINT32_(3)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE3_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE3_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE3(value)          (ADCHS_ADCCMPEN2_CMPE3_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE3_Pos)) /* Assigment of value for CMPE3 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE4_Pos             _UINT32_(4)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE4_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE4_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE4(value)          (ADCHS_ADCCMPEN2_CMPE4_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE4_Pos)) /* Assigment of value for CMPE4 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE5_Pos             _UINT32_(5)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE5_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE5_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE5(value)          (ADCHS_ADCCMPEN2_CMPE5_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE5_Pos)) /* Assigment of value for CMPE5 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE6_Pos             _UINT32_(6)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE6_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE6_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE6(value)          (ADCHS_ADCCMPEN2_CMPE6_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE6_Pos)) /* Assigment of value for CMPE6 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_CMPE7_Pos             _UINT32_(7)                                          /* (ADCHS_ADCCMPEN2)  Position */
#define ADCHS_ADCCMPEN2_CMPE7_Msk             (_UINT32_(0x1) << ADCHS_ADCCMPEN2_CMPE7_Pos)         /* (ADCHS_ADCCMPEN2)  Mask */
#define ADCHS_ADCCMPEN2_CMPE7(value)          (ADCHS_ADCCMPEN2_CMPE7_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE7_Pos)) /* Assigment of value for CMPE7 in the ADCHS_ADCCMPEN2 register */
#define ADCHS_ADCCMPEN2_Msk                   _UINT32_(0x000000FF)                                 /* (ADCHS_ADCCMPEN2) Register Mask  */

#define ADCHS_ADCCMPEN2_CMPE_Pos              _UINT32_(0)                                          /* (ADCHS_ADCCMPEN2 Position)  */
#define ADCHS_ADCCMPEN2_CMPE_Msk              (_UINT32_(0xFF) << ADCHS_ADCCMPEN2_CMPE_Pos)         /* (ADCHS_ADCCMPEN2 Mask) CMPE */
#define ADCHS_ADCCMPEN2_CMPE(value)           (ADCHS_ADCCMPEN2_CMPE_Msk & (_UINT32_(value) << ADCHS_ADCCMPEN2_CMPE_Pos)) 

/* -------- ADCHS_ADCCMPEN1CLR : (ADCHS Offset: 0x104) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCMPEN1CLR_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCMPEN1CLR_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPEN1CLR) Register Mask  */


/* -------- ADCHS_ADCCMPEN1SET : (ADCHS Offset: 0x108) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCMPEN1SET_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN1SET) Bit set register  Reset Value */

#define ADCHS_ADCCMPEN1SET_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPEN1SET) Register Mask  */


/* -------- ADCHS_ADCCMPEN1INV : (ADCHS Offset: 0x10C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCMPEN1INV_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPEN1INV) Bit invert register  Reset Value */

#define ADCHS_ADCCMPEN1INV_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPEN1INV) Register Mask  */


/* -------- ADCHS_ADCCMP2 : (ADCHS Offset: 0x110) (R/W 32)  -------- */
#define ADCHS_ADCCMP2_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCMP2)   Reset Value */

#define ADCHS_ADCCMP2_ADCMPLO_Pos             _UINT32_(0)                                          /* (ADCHS_ADCCMP2)  Position */
#define ADCHS_ADCCMP2_ADCMPLO_Msk             (_UINT32_(0xFFFF) << ADCHS_ADCCMP2_ADCMPLO_Pos)      /* (ADCHS_ADCCMP2)  Mask */
#define ADCHS_ADCCMP2_ADCMPLO(value)          (ADCHS_ADCCMP2_ADCMPLO_Msk & (_UINT32_(value) << ADCHS_ADCCMP2_ADCMPLO_Pos)) /* Assigment of value for ADCMPLO in the ADCHS_ADCCMP2 register */
#define ADCHS_ADCCMP2_ADCMPHI_Pos             _UINT32_(16)                                         /* (ADCHS_ADCCMP2)  Position */
#define ADCHS_ADCCMP2_ADCMPHI_Msk             (_UINT32_(0xFFFF) << ADCHS_ADCCMP2_ADCMPHI_Pos)      /* (ADCHS_ADCCMP2)  Mask */
#define ADCHS_ADCCMP2_ADCMPHI(value)          (ADCHS_ADCCMP2_ADCMPHI_Msk & (_UINT32_(value) << ADCHS_ADCCMP2_ADCMPHI_Pos)) /* Assigment of value for ADCMPHI in the ADCHS_ADCCMP2 register */
#define ADCHS_ADCCMP2_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCCMP2) Register Mask  */


/* -------- ADCHS_ADDCMP1CLR : (ADCHS Offset: 0x114) (R/W 32) Bit clear register -------- */
#define ADCHS_ADDCMP1CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADDCMP1CLR) Bit clear register  Reset Value */

#define ADCHS_ADDCMP1CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADDCMP1CLR) Register Mask  */


/* -------- ADCHS_ADDCMP1SET : (ADCHS Offset: 0x118) (R/W 32) Bit set register -------- */
#define ADCHS_ADDCMP1SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADDCMP1SET) Bit set register  Reset Value */

#define ADCHS_ADDCMP1SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADDCMP1SET) Register Mask  */


/* -------- ADCHS_ADDCMP1INV : (ADCHS Offset: 0x11C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADDCMP1INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADDCMP1INV) Bit invert register  Reset Value */

#define ADCHS_ADDCMP1INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADDCMP1INV) Register Mask  */


/* -------- ADCHS_ADCFLTR1 : (ADCHS Offset: 0x1A0) (R/W 32)  -------- */
#define ADCHS_ADCFLTR1_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR1)   Reset Value */

#define ADCHS_ADCFLTR1_FLT_DATA0_Pos          _UINT32_(0)                                          /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_FLT_DATA0_Msk          (_UINT32_(0xFFFF) << ADCHS_ADCFLTR1_FLT_DATA0_Pos)   /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_FLT_DATA0(value)       (ADCHS_ADCFLTR1_FLT_DATA0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_FLT_DATA0_Pos)) /* Assigment of value for FLT_DATA0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_FLTINID0_Pos           _UINT32_(16)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_FLTINID0_Msk           (_UINT32_(0x1F) << ADCHS_ADCFLTR1_FLTINID0_Pos)      /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_FLTINID0(value)        (ADCHS_ADCFLTR1_FLTINID0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_FLTINID0_Pos)) /* Assigment of value for FLTINID0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_AFIF0_Pos              _UINT32_(24)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_AFIF0_Msk              (_UINT32_(0x1) << ADCHS_ADCFLTR1_AFIF0_Pos)          /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_AFIF0(value)           (ADCHS_ADCFLTR1_AFIF0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_AFIF0_Pos)) /* Assigment of value for AFIF0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_AFIEN0_Pos             _UINT32_(25)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_AFIEN0_Msk             (_UINT32_(0x1) << ADCHS_ADCFLTR1_AFIEN0_Pos)         /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_AFIEN0(value)          (ADCHS_ADCFLTR1_AFIEN0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_AFIEN0_Pos)) /* Assigment of value for AFIEN0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_OVRSAM0_Pos            _UINT32_(26)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_OVRSAM0_Msk            (_UINT32_(0x7) << ADCHS_ADCFLTR1_OVRSAM0_Pos)        /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_OVRSAM0(value)         (ADCHS_ADCFLTR1_OVRSAM0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_OVRSAM0_Pos)) /* Assigment of value for OVRSAM0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_ADFMODE0_Pos           _UINT32_(29)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_ADFMODE0_Msk           (_UINT32_(0x1) << ADCHS_ADCFLTR1_ADFMODE0_Pos)       /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_ADFMODE0(value)        (ADCHS_ADCFLTR1_ADFMODE0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_ADFMODE0_Pos)) /* Assigment of value for ADFMODE0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_DATA16EN0_Pos          _UINT32_(30)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_DATA16EN0_Msk          (_UINT32_(0x1) << ADCHS_ADCFLTR1_DATA16EN0_Pos)      /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_DATA16EN0(value)       (ADCHS_ADCFLTR1_DATA16EN0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_DATA16EN0_Pos)) /* Assigment of value for DATA16EN0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_AFEN0_Pos              _UINT32_(31)                                         /* (ADCHS_ADCFLTR1)  Position */
#define ADCHS_ADCFLTR1_AFEN0_Msk              (_UINT32_(0x1) << ADCHS_ADCFLTR1_AFEN0_Pos)          /* (ADCHS_ADCFLTR1)  Mask */
#define ADCHS_ADCFLTR1_AFEN0(value)           (ADCHS_ADCFLTR1_AFEN0_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_AFEN0_Pos)) /* Assigment of value for AFEN0 in the ADCHS_ADCFLTR1 register */
#define ADCHS_ADCFLTR1_Msk                    _UINT32_(0xFF1FFFFF)                                 /* (ADCHS_ADCFLTR1) Register Mask  */

#define ADCHS_ADCFLTR1_AFIF_Pos               _UINT32_(24)                                         /* (ADCHS_ADCFLTR1 Position)  */
#define ADCHS_ADCFLTR1_AFIF_Msk               (_UINT32_(0x1) << ADCHS_ADCFLTR1_AFIF_Pos)           /* (ADCHS_ADCFLTR1 Mask) AFIF */
#define ADCHS_ADCFLTR1_AFIF(value)            (ADCHS_ADCFLTR1_AFIF_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_AFIF_Pos)) 
#define ADCHS_ADCFLTR1_AFIEN_Pos              _UINT32_(25)                                         /* (ADCHS_ADCFLTR1 Position)  */
#define ADCHS_ADCFLTR1_AFIEN_Msk              (_UINT32_(0x1) << ADCHS_ADCFLTR1_AFIEN_Pos)          /* (ADCHS_ADCFLTR1 Mask) AFIEN */
#define ADCHS_ADCFLTR1_AFIEN(value)           (ADCHS_ADCFLTR1_AFIEN_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_AFIEN_Pos)) 
#define ADCHS_ADCFLTR1_ADFMODE_Pos            _UINT32_(29)                                         /* (ADCHS_ADCFLTR1 Position)  */
#define ADCHS_ADCFLTR1_ADFMODE_Msk            (_UINT32_(0x1) << ADCHS_ADCFLTR1_ADFMODE_Pos)        /* (ADCHS_ADCFLTR1 Mask) ADFMODE */
#define ADCHS_ADCFLTR1_ADFMODE(value)         (ADCHS_ADCFLTR1_ADFMODE_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_ADFMODE_Pos)) 
#define ADCHS_ADCFLTR1_DATA16EN_Pos           _UINT32_(30)                                         /* (ADCHS_ADCFLTR1 Position)  */
#define ADCHS_ADCFLTR1_DATA16EN_Msk           (_UINT32_(0x1) << ADCHS_ADCFLTR1_DATA16EN_Pos)       /* (ADCHS_ADCFLTR1 Mask) DATA16EN */
#define ADCHS_ADCFLTR1_DATA16EN(value)        (ADCHS_ADCFLTR1_DATA16EN_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_DATA16EN_Pos)) 
#define ADCHS_ADCFLTR1_AFEN_Pos               _UINT32_(31)                                         /* (ADCHS_ADCFLTR1 Position)  */
#define ADCHS_ADCFLTR1_AFEN_Msk               (_UINT32_(0x1) << ADCHS_ADCFLTR1_AFEN_Pos)           /* (ADCHS_ADCFLTR1 Mask) AFEN */
#define ADCHS_ADCFLTR1_AFEN(value)            (ADCHS_ADCFLTR1_AFEN_Msk & (_UINT32_(value) << ADCHS_ADCFLTR1_AFEN_Pos)) 

/* -------- ADCHS_ADCFLTR0CLR : (ADCHS Offset: 0x1A4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCFLTR0CLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR0CLR) Bit clear register  Reset Value */

#define ADCHS_ADCFLTR0CLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFLTR0CLR) Register Mask  */


/* -------- ADCHS_ADCFLTR0SET : (ADCHS Offset: 0x1A8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCFLTR0SET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR0SET) Bit set register  Reset Value */

#define ADCHS_ADCFLTR0SET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFLTR0SET) Register Mask  */


/* -------- ADCHS_ADCFLTR0INV : (ADCHS Offset: 0x1AC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCFLTR0INV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR0INV) Bit invert register  Reset Value */

#define ADCHS_ADCFLTR0INV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFLTR0INV) Register Mask  */


/* -------- ADCHS_ADCFLTR2 : (ADCHS Offset: 0x1B0) (R/W 32)  -------- */
#define ADCHS_ADCFLTR2_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR2)   Reset Value */

#define ADCHS_ADCFLTR2_FLT_DATA1_Pos          _UINT32_(0)                                          /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_FLT_DATA1_Msk          (_UINT32_(0xFFFF) << ADCHS_ADCFLTR2_FLT_DATA1_Pos)   /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_FLT_DATA1(value)       (ADCHS_ADCFLTR2_FLT_DATA1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_FLT_DATA1_Pos)) /* Assigment of value for FLT_DATA1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_FLTINID1_Pos           _UINT32_(16)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_FLTINID1_Msk           (_UINT32_(0x1F) << ADCHS_ADCFLTR2_FLTINID1_Pos)      /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_FLTINID1(value)        (ADCHS_ADCFLTR2_FLTINID1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_FLTINID1_Pos)) /* Assigment of value for FLTINID1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_AFIF1_Pos              _UINT32_(24)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_AFIF1_Msk              (_UINT32_(0x1) << ADCHS_ADCFLTR2_AFIF1_Pos)          /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_AFIF1(value)           (ADCHS_ADCFLTR2_AFIF1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_AFIF1_Pos)) /* Assigment of value for AFIF1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_AFIEN1_Pos             _UINT32_(25)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_AFIEN1_Msk             (_UINT32_(0x1) << ADCHS_ADCFLTR2_AFIEN1_Pos)         /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_AFIEN1(value)          (ADCHS_ADCFLTR2_AFIEN1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_AFIEN1_Pos)) /* Assigment of value for AFIEN1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_OVRSAM1_Pos            _UINT32_(26)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_OVRSAM1_Msk            (_UINT32_(0x7) << ADCHS_ADCFLTR2_OVRSAM1_Pos)        /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_OVRSAM1(value)         (ADCHS_ADCFLTR2_OVRSAM1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_OVRSAM1_Pos)) /* Assigment of value for OVRSAM1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_ADFMODE1_Pos           _UINT32_(29)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_ADFMODE1_Msk           (_UINT32_(0x1) << ADCHS_ADCFLTR2_ADFMODE1_Pos)       /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_ADFMODE1(value)        (ADCHS_ADCFLTR2_ADFMODE1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_ADFMODE1_Pos)) /* Assigment of value for ADFMODE1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_DATA16EN1_Pos          _UINT32_(30)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_DATA16EN1_Msk          (_UINT32_(0x1) << ADCHS_ADCFLTR2_DATA16EN1_Pos)      /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_DATA16EN1(value)       (ADCHS_ADCFLTR2_DATA16EN1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_DATA16EN1_Pos)) /* Assigment of value for DATA16EN1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_AFEN1_Pos              _UINT32_(31)                                         /* (ADCHS_ADCFLTR2)  Position */
#define ADCHS_ADCFLTR2_AFEN1_Msk              (_UINT32_(0x1) << ADCHS_ADCFLTR2_AFEN1_Pos)          /* (ADCHS_ADCFLTR2)  Mask */
#define ADCHS_ADCFLTR2_AFEN1(value)           (ADCHS_ADCFLTR2_AFEN1_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_AFEN1_Pos)) /* Assigment of value for AFEN1 in the ADCHS_ADCFLTR2 register */
#define ADCHS_ADCFLTR2_Msk                    _UINT32_(0xFF1FFFFF)                                 /* (ADCHS_ADCFLTR2) Register Mask  */

#define ADCHS_ADCFLTR2_AFIF_Pos               _UINT32_(24)                                         /* (ADCHS_ADCFLTR2 Position)  */
#define ADCHS_ADCFLTR2_AFIF_Msk               (_UINT32_(0x1) << ADCHS_ADCFLTR2_AFIF_Pos)           /* (ADCHS_ADCFLTR2 Mask) AFIF */
#define ADCHS_ADCFLTR2_AFIF(value)            (ADCHS_ADCFLTR2_AFIF_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_AFIF_Pos)) 
#define ADCHS_ADCFLTR2_AFIEN_Pos              _UINT32_(25)                                         /* (ADCHS_ADCFLTR2 Position)  */
#define ADCHS_ADCFLTR2_AFIEN_Msk              (_UINT32_(0x1) << ADCHS_ADCFLTR2_AFIEN_Pos)          /* (ADCHS_ADCFLTR2 Mask) AFIEN */
#define ADCHS_ADCFLTR2_AFIEN(value)           (ADCHS_ADCFLTR2_AFIEN_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_AFIEN_Pos)) 
#define ADCHS_ADCFLTR2_ADFMODE_Pos            _UINT32_(29)                                         /* (ADCHS_ADCFLTR2 Position)  */
#define ADCHS_ADCFLTR2_ADFMODE_Msk            (_UINT32_(0x1) << ADCHS_ADCFLTR2_ADFMODE_Pos)        /* (ADCHS_ADCFLTR2 Mask) ADFMODE */
#define ADCHS_ADCFLTR2_ADFMODE(value)         (ADCHS_ADCFLTR2_ADFMODE_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_ADFMODE_Pos)) 
#define ADCHS_ADCFLTR2_DATA16EN_Pos           _UINT32_(30)                                         /* (ADCHS_ADCFLTR2 Position)  */
#define ADCHS_ADCFLTR2_DATA16EN_Msk           (_UINT32_(0x1) << ADCHS_ADCFLTR2_DATA16EN_Pos)       /* (ADCHS_ADCFLTR2 Mask) DATA16EN */
#define ADCHS_ADCFLTR2_DATA16EN(value)        (ADCHS_ADCFLTR2_DATA16EN_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_DATA16EN_Pos)) 
#define ADCHS_ADCFLTR2_AFEN_Pos               _UINT32_(31)                                         /* (ADCHS_ADCFLTR2 Position)  */
#define ADCHS_ADCFLTR2_AFEN_Msk               (_UINT32_(0x1) << ADCHS_ADCFLTR2_AFEN_Pos)           /* (ADCHS_ADCFLTR2 Mask) AFEN */
#define ADCHS_ADCFLTR2_AFEN(value)            (ADCHS_ADCFLTR2_AFEN_Msk & (_UINT32_(value) << ADCHS_ADCFLTR2_AFEN_Pos)) 

/* -------- ADCHS_ADCFLTR1CLR : (ADCHS Offset: 0x1B4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCFLTR1CLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCFLTR1CLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFLTR1CLR) Register Mask  */


/* -------- ADCHS_ADCFLTR1SET : (ADCHS Offset: 0x1B8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCFLTR1SET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR1SET) Bit set register  Reset Value */

#define ADCHS_ADCFLTR1SET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFLTR1SET) Register Mask  */


/* -------- ADCHS_ADCFLTR1INV : (ADCHS Offset: 0x1BC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCFLTR1INV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFLTR1INV) Bit invert register  Reset Value */

#define ADCHS_ADCFLTR1INV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFLTR1INV) Register Mask  */


/* -------- ADCHS_ADCTRG1 : (ADCHS Offset: 0x200) (R/W 32) ADC Trigger Source 1 Register -------- */
#define ADCHS_ADCTRG1_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCTRG1) ADC Trigger Source 1 Register  Reset Value */

#define ADCHS_ADCTRG1_TRGSRC0_Pos             _UINT32_(0)                                          /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC0 Module Select bits Position */
#define ADCHS_ADCTRG1_TRGSRC0_Msk             (_UINT32_(0x1F) << ADCHS_ADCTRG1_TRGSRC0_Pos)        /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC0 Module Select bits Mask */
#define ADCHS_ADCTRG1_TRGSRC0(value)          (ADCHS_ADCTRG1_TRGSRC0_Msk & (_UINT32_(value) << ADCHS_ADCTRG1_TRGSRC0_Pos)) /* Assigment of value for TRGSRC0 in the ADCHS_ADCTRG1 register */
#define   ADCHS_ADCTRG1_TRGSRC0_RESERVED_Val  _UINT32_(0x1F)                                       /* (ADCHS_ADCTRG1) RESERVED  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCTRG1) ADC_TRIG_16  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_15  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_14  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_13  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_12  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_11  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_10  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_9  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_8  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_7  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_6  */
#define   ADCHS_ADCTRG1_TRGSRC0_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_5  */
#define   ADCHS_ADCTRG1_TRGSRC0_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCTRG1) INT0  */
#define   ADCHS_ADCTRG1_TRGSRC0_SCAN_TRIG_Val _UINT32_(0x3)                                        /* (ADCHS_ADCTRG1) Scan trigger  */
#define   ADCHS_ADCTRG1_TRGSRC0_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCTRG1) Software level trigger  */
#define   ADCHS_ADCTRG1_TRGSRC0_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCTRG1) Software edge trigger  */
#define   ADCHS_ADCTRG1_TRGSRC0_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCTRG1) No Trigger  */
#define ADCHS_ADCTRG1_TRGSRC0_RESERVED        (ADCHS_ADCTRG1_TRGSRC0_RESERVED_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) RESERVED Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_47        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_47_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_16 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_46        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_46_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_15 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_45        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_45_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_14 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_44        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_44_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_13 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_43        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_43_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_12 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_42        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_42_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_11 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_41        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_41_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_10 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_40        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_40_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_9 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_39        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_39_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_8 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_38        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_38_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_7 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_37        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_37_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_6 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_EVSYS_36        (ADCHS_ADCTRG1_TRGSRC0_EVSYS_36_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_5 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_INT0            (ADCHS_ADCTRG1_TRGSRC0_INT0_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) INT0 Position  */
#define ADCHS_ADCTRG1_TRGSRC0_SCAN_TRIG       (ADCHS_ADCTRG1_TRGSRC0_SCAN_TRIG_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) Scan trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC0_SW_LVL          (ADCHS_ADCTRG1_TRGSRC0_SW_LVL_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) Software level trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC0_SW_EDGE         (ADCHS_ADCTRG1_TRGSRC0_SW_EDGE_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) Software edge trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC0_NONE            (ADCHS_ADCTRG1_TRGSRC0_NONE_Val << ADCHS_ADCTRG1_TRGSRC0_Pos) /* (ADCHS_ADCTRG1) No Trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC1_Pos             _UINT32_(8)                                          /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC1 Module Select bits Position */
#define ADCHS_ADCTRG1_TRGSRC1_Msk             (_UINT32_(0x1F) << ADCHS_ADCTRG1_TRGSRC1_Pos)        /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC1 Module Select bits Mask */
#define ADCHS_ADCTRG1_TRGSRC1(value)          (ADCHS_ADCTRG1_TRGSRC1_Msk & (_UINT32_(value) << ADCHS_ADCTRG1_TRGSRC1_Pos)) /* Assigment of value for TRGSRC1 in the ADCHS_ADCTRG1 register */
#define   ADCHS_ADCTRG1_TRGSRC1_RESERVED_Val  _UINT32_(0x1F)                                       /* (ADCHS_ADCTRG1) RESERVED  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCTRG1) ADC_TRIG_16  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_15  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_14  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_13  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_12  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_11  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_10  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_9  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_8  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_7  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_6  */
#define   ADCHS_ADCTRG1_TRGSRC1_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_5  */
#define   ADCHS_ADCTRG1_TRGSRC1_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCTRG1) INT0  */
#define   ADCHS_ADCTRG1_TRGSRC1_SCAN_TRIG_Val _UINT32_(0x3)                                        /* (ADCHS_ADCTRG1) Scan trigger  */
#define   ADCHS_ADCTRG1_TRGSRC1_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCTRG1) Software level trigger  */
#define   ADCHS_ADCTRG1_TRGSRC1_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCTRG1) Software edge trigger  */
#define   ADCHS_ADCTRG1_TRGSRC1_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCTRG1) No Trigger  */
#define ADCHS_ADCTRG1_TRGSRC1_RESERVED        (ADCHS_ADCTRG1_TRGSRC1_RESERVED_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) RESERVED Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_47        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_47_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_16 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_46        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_46_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_15 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_45        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_45_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_14 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_44        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_44_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_13 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_43        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_43_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_12 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_42        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_42_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_11 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_41        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_41_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_10 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_40        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_40_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_9 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_39        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_39_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_8 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_38        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_38_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_7 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_37        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_37_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_6 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_EVSYS_36        (ADCHS_ADCTRG1_TRGSRC1_EVSYS_36_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_5 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_INT0            (ADCHS_ADCTRG1_TRGSRC1_INT0_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) INT0 Position  */
#define ADCHS_ADCTRG1_TRGSRC1_SCAN_TRIG       (ADCHS_ADCTRG1_TRGSRC1_SCAN_TRIG_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) Scan trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC1_SW_LVL          (ADCHS_ADCTRG1_TRGSRC1_SW_LVL_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) Software level trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC1_SW_EDGE         (ADCHS_ADCTRG1_TRGSRC1_SW_EDGE_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) Software edge trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC1_NONE            (ADCHS_ADCTRG1_TRGSRC1_NONE_Val << ADCHS_ADCTRG1_TRGSRC1_Pos) /* (ADCHS_ADCTRG1) No Trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC2_Pos             _UINT32_(16)                                         /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC2 Module Select bits Position */
#define ADCHS_ADCTRG1_TRGSRC2_Msk             (_UINT32_(0x1F) << ADCHS_ADCTRG1_TRGSRC2_Pos)        /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC2 Module Select bits Mask */
#define ADCHS_ADCTRG1_TRGSRC2(value)          (ADCHS_ADCTRG1_TRGSRC2_Msk & (_UINT32_(value) << ADCHS_ADCTRG1_TRGSRC2_Pos)) /* Assigment of value for TRGSRC2 in the ADCHS_ADCTRG1 register */
#define   ADCHS_ADCTRG1_TRGSRC2_RESERVED_Val  _UINT32_(0x1F)                                       /* (ADCHS_ADCTRG1) RESERVED  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCTRG1) ADC_TRIG_16  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_15  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_14  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_13  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_12  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_11  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_10  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_9  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_8  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_7  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_6  */
#define   ADCHS_ADCTRG1_TRGSRC2_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_5  */
#define   ADCHS_ADCTRG1_TRGSRC2_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCTRG1) INT0  */
#define   ADCHS_ADCTRG1_TRGSRC2_SCAN_TRIG_Val _UINT32_(0x3)                                        /* (ADCHS_ADCTRG1) Scan trigger  */
#define   ADCHS_ADCTRG1_TRGSRC2_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCTRG1) Software level trigger  */
#define   ADCHS_ADCTRG1_TRGSRC2_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCTRG1) Software edge trigger  */
#define   ADCHS_ADCTRG1_TRGSRC2_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCTRG1) No Trigger  */
#define ADCHS_ADCTRG1_TRGSRC2_RESERVED        (ADCHS_ADCTRG1_TRGSRC2_RESERVED_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) RESERVED Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_47        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_47_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_16 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_46        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_46_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_15 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_45        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_45_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_14 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_44        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_44_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_13 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_43        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_43_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_12 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_42        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_42_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_11 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_41        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_41_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_10 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_40        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_40_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_9 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_39        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_39_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_8 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_38        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_38_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_7 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_37        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_37_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_6 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_EVSYS_36        (ADCHS_ADCTRG1_TRGSRC2_EVSYS_36_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_5 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_INT0            (ADCHS_ADCTRG1_TRGSRC2_INT0_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) INT0 Position  */
#define ADCHS_ADCTRG1_TRGSRC2_SCAN_TRIG       (ADCHS_ADCTRG1_TRGSRC2_SCAN_TRIG_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) Scan trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC2_SW_LVL          (ADCHS_ADCTRG1_TRGSRC2_SW_LVL_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) Software level trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC2_SW_EDGE         (ADCHS_ADCTRG1_TRGSRC2_SW_EDGE_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) Software edge trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC2_NONE            (ADCHS_ADCTRG1_TRGSRC2_NONE_Val << ADCHS_ADCTRG1_TRGSRC2_Pos) /* (ADCHS_ADCTRG1) No Trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC3_Pos             _UINT32_(24)                                         /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC3 Module Select bits Position */
#define ADCHS_ADCTRG1_TRGSRC3_Msk             (_UINT32_(0x1F) << ADCHS_ADCTRG1_TRGSRC3_Pos)        /* (ADCHS_ADCTRG1) Trigger Source for Conversion of ADC3 Module Select bits Mask */
#define ADCHS_ADCTRG1_TRGSRC3(value)          (ADCHS_ADCTRG1_TRGSRC3_Msk & (_UINT32_(value) << ADCHS_ADCTRG1_TRGSRC3_Pos)) /* Assigment of value for TRGSRC3 in the ADCHS_ADCTRG1 register */
#define   ADCHS_ADCTRG1_TRGSRC3_RESERVED_Val  _UINT32_(0x1F)                                       /* (ADCHS_ADCTRG1) RESERVED  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCTRG1) ADC_TRIG_16  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_15  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_14  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_13  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_12  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_11  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_10  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_9  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_8  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_7  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_6  */
#define   ADCHS_ADCTRG1_TRGSRC3_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCTRG1) ADC_TRIG_5  */
#define   ADCHS_ADCTRG1_TRGSRC3_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCTRG1) INT0  */
#define   ADCHS_ADCTRG1_TRGSRC3_SCAN_TRIG_Val _UINT32_(0x3)                                        /* (ADCHS_ADCTRG1) Scan trigger  */
#define   ADCHS_ADCTRG1_TRGSRC3_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCTRG1) Software level trigger  */
#define   ADCHS_ADCTRG1_TRGSRC3_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCTRG1) Software edge trigger  */
#define   ADCHS_ADCTRG1_TRGSRC3_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCTRG1) No Trigger  */
#define ADCHS_ADCTRG1_TRGSRC3_RESERVED        (ADCHS_ADCTRG1_TRGSRC3_RESERVED_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) RESERVED Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_47        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_47_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_16 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_46        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_46_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_15 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_45        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_45_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_14 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_44        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_44_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_13 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_43        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_43_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_12 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_42        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_42_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_11 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_41        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_41_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_10 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_40        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_40_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_9 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_39        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_39_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_8 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_38        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_38_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_7 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_37        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_37_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_6 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_EVSYS_36        (ADCHS_ADCTRG1_TRGSRC3_EVSYS_36_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) ADC_TRIG_5 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_INT0            (ADCHS_ADCTRG1_TRGSRC3_INT0_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) INT0 Position  */
#define ADCHS_ADCTRG1_TRGSRC3_SCAN_TRIG       (ADCHS_ADCTRG1_TRGSRC3_SCAN_TRIG_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) Scan trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC3_SW_LVL          (ADCHS_ADCTRG1_TRGSRC3_SW_LVL_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) Software level trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC3_SW_EDGE         (ADCHS_ADCTRG1_TRGSRC3_SW_EDGE_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) Software edge trigger Position  */
#define ADCHS_ADCTRG1_TRGSRC3_NONE            (ADCHS_ADCTRG1_TRGSRC3_NONE_Val << ADCHS_ADCTRG1_TRGSRC3_Pos) /* (ADCHS_ADCTRG1) No Trigger Position  */
#define ADCHS_ADCTRG1_Msk                     _UINT32_(0x1F1F1F1F)                                 /* (ADCHS_ADCTRG1) Register Mask  */


/* -------- ADCHS_ADCTRG1CLR : (ADCHS Offset: 0x204) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCTRG1CLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCTRG1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCTRG1CLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCTRG1CLR) Register Mask  */


/* -------- ADCHS_ADCTRG1SET : (ADCHS Offset: 0x208) (R/W 32) Bit set register -------- */
#define ADCHS_ADCTRG1SET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCTRG1SET) Bit set register  Reset Value */

#define ADCHS_ADCTRG1SET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCTRG1SET) Register Mask  */


/* -------- ADCHS_ADCTRG1INV : (ADCHS Offset: 0x20C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCTRG1INV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCTRG1INV) Bit invert register  Reset Value */

#define ADCHS_ADCTRG1INV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCTRG1INV) Register Mask  */


/* -------- ADCHS_ADCTRG2 : (ADCHS Offset: 0x210) (R/W 32) ADC Trigger Source 2 Register -------- */
#define ADCHS_ADCTRG2_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCTRG2) ADC Trigger Source 2 Register  Reset Value */

#define ADCHS_ADCTRG2_TRGSRC4_Pos             _UINT32_(0)                                          /* (ADCHS_ADCTRG2) Trigger Source for Conversion of ADC4 Module Select bits Position */
#define ADCHS_ADCTRG2_TRGSRC4_Msk             (_UINT32_(0x1F) << ADCHS_ADCTRG2_TRGSRC4_Pos)        /* (ADCHS_ADCTRG2) Trigger Source for Conversion of ADC4 Module Select bits Mask */
#define ADCHS_ADCTRG2_TRGSRC4(value)          (ADCHS_ADCTRG2_TRGSRC4_Msk & (_UINT32_(value) << ADCHS_ADCTRG2_TRGSRC4_Pos)) /* Assigment of value for TRGSRC4 in the ADCHS_ADCTRG2 register */
#define   ADCHS_ADCTRG2_TRGSRC4_RESERVED_Val  _UINT32_(0x1F)                                       /* (ADCHS_ADCTRG2) RESERVED  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCTRG2) ADC_TRIG_16  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_15  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_14  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_13  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_12  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_11  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_10  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_9  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_8  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_7  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_6  */
#define   ADCHS_ADCTRG2_TRGSRC4_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_5  */
#define   ADCHS_ADCTRG2_TRGSRC4_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCTRG2) INT0  */
#define   ADCHS_ADCTRG2_TRGSRC4_SCAN_TRIG_Val _UINT32_(0x3)                                        /* (ADCHS_ADCTRG2) Scan trigger  */
#define   ADCHS_ADCTRG2_TRGSRC4_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCTRG2) Software level trigger  */
#define   ADCHS_ADCTRG2_TRGSRC4_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCTRG2) Software edge trigger  */
#define   ADCHS_ADCTRG2_TRGSRC4_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCTRG2) No Trigger  */
#define ADCHS_ADCTRG2_TRGSRC4_RESERVED        (ADCHS_ADCTRG2_TRGSRC4_RESERVED_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) RESERVED Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_47        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_47_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_16 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_46        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_46_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_15 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_45        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_45_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_14 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_44        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_44_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_13 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_43        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_43_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_12 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_42        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_42_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_11 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_41        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_41_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_10 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_40        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_40_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_9 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_39        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_39_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_8 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_38        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_38_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_7 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_37        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_37_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_6 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_EVSYS_36        (ADCHS_ADCTRG2_TRGSRC4_EVSYS_36_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_5 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_INT0            (ADCHS_ADCTRG2_TRGSRC4_INT0_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) INT0 Position  */
#define ADCHS_ADCTRG2_TRGSRC4_SCAN_TRIG       (ADCHS_ADCTRG2_TRGSRC4_SCAN_TRIG_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) Scan trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC4_SW_LVL          (ADCHS_ADCTRG2_TRGSRC4_SW_LVL_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) Software level trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC4_SW_EDGE         (ADCHS_ADCTRG2_TRGSRC4_SW_EDGE_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) Software edge trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC4_NONE            (ADCHS_ADCTRG2_TRGSRC4_NONE_Val << ADCHS_ADCTRG2_TRGSRC4_Pos) /* (ADCHS_ADCTRG2) No Trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC5_Pos             _UINT32_(8)                                          /* (ADCHS_ADCTRG2) Trigger Source for Conversion of ADC5 Module Select bits Position */
#define ADCHS_ADCTRG2_TRGSRC5_Msk             (_UINT32_(0x1F) << ADCHS_ADCTRG2_TRGSRC5_Pos)        /* (ADCHS_ADCTRG2) Trigger Source for Conversion of ADC5 Module Select bits Mask */
#define ADCHS_ADCTRG2_TRGSRC5(value)          (ADCHS_ADCTRG2_TRGSRC5_Msk & (_UINT32_(value) << ADCHS_ADCTRG2_TRGSRC5_Pos)) /* Assigment of value for TRGSRC5 in the ADCHS_ADCTRG2 register */
#define   ADCHS_ADCTRG2_TRGSRC5_RESERVED_Val  _UINT32_(0x1F)                                       /* (ADCHS_ADCTRG2) RESERVED  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_47_Val  _UINT32_(0x10)                                       /* (ADCHS_ADCTRG2) ADC_TRIG_16  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_46_Val  _UINT32_(0xF)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_15  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_45_Val  _UINT32_(0xE)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_14  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_44_Val  _UINT32_(0xD)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_13  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_43_Val  _UINT32_(0xC)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_12  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_42_Val  _UINT32_(0xB)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_11  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_41_Val  _UINT32_(0xA)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_10  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_40_Val  _UINT32_(0x9)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_9  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_39_Val  _UINT32_(0x8)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_8  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_38_Val  _UINT32_(0x7)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_7  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_37_Val  _UINT32_(0x6)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_6  */
#define   ADCHS_ADCTRG2_TRGSRC5_EVSYS_36_Val  _UINT32_(0x5)                                        /* (ADCHS_ADCTRG2) ADC_TRIG_5  */
#define   ADCHS_ADCTRG2_TRGSRC5_INT0_Val      _UINT32_(0x4)                                        /* (ADCHS_ADCTRG2) INT0  */
#define   ADCHS_ADCTRG2_TRGSRC5_SCAN_TRIG_Val _UINT32_(0x3)                                        /* (ADCHS_ADCTRG2) Scan trigger  */
#define   ADCHS_ADCTRG2_TRGSRC5_SW_LVL_Val    _UINT32_(0x2)                                        /* (ADCHS_ADCTRG2) Software level trigger  */
#define   ADCHS_ADCTRG2_TRGSRC5_SW_EDGE_Val   _UINT32_(0x1)                                        /* (ADCHS_ADCTRG2) Software edge trigger  */
#define   ADCHS_ADCTRG2_TRGSRC5_NONE_Val      _UINT32_(0x0)                                        /* (ADCHS_ADCTRG2) No Trigger  */
#define ADCHS_ADCTRG2_TRGSRC5_RESERVED        (ADCHS_ADCTRG2_TRGSRC5_RESERVED_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) RESERVED Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_47        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_47_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_16 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_46        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_46_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_15 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_45        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_45_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_14 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_44        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_44_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_13 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_43        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_43_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_12 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_42        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_42_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_11 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_41        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_41_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_10 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_40        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_40_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_9 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_39        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_39_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_8 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_38        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_38_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_7 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_37        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_37_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_6 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_EVSYS_36        (ADCHS_ADCTRG2_TRGSRC5_EVSYS_36_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) ADC_TRIG_5 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_INT0            (ADCHS_ADCTRG2_TRGSRC5_INT0_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) INT0 Position  */
#define ADCHS_ADCTRG2_TRGSRC5_SCAN_TRIG       (ADCHS_ADCTRG2_TRGSRC5_SCAN_TRIG_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) Scan trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC5_SW_LVL          (ADCHS_ADCTRG2_TRGSRC5_SW_LVL_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) Software level trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC5_SW_EDGE         (ADCHS_ADCTRG2_TRGSRC5_SW_EDGE_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) Software edge trigger Position  */
#define ADCHS_ADCTRG2_TRGSRC5_NONE            (ADCHS_ADCTRG2_TRGSRC5_NONE_Val << ADCHS_ADCTRG2_TRGSRC5_Pos) /* (ADCHS_ADCTRG2) No Trigger Position  */
#define ADCHS_ADCTRG2_Msk                     _UINT32_(0x00001F1F)                                 /* (ADCHS_ADCTRG2) Register Mask  */


/* -------- ADCHS_ADTRG2CLR : (ADCHS Offset: 0x214) (R/W 32) Bit clear register -------- */
#define ADCHS_ADTRG2CLR_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADTRG2CLR) Bit clear register  Reset Value */

#define ADCHS_ADTRG2CLR_Msk                   _UINT32_(0x00000000)                                 /* (ADCHS_ADTRG2CLR) Register Mask  */


/* -------- ADCHS_ADTRG2SET : (ADCHS Offset: 0x218) (R/W 32) Bit set register -------- */
#define ADCHS_ADTRG2SET_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADTRG2SET) Bit set register  Reset Value */

#define ADCHS_ADTRG2SET_Msk                   _UINT32_(0x00000000)                                 /* (ADCHS_ADTRG2SET) Register Mask  */


/* -------- ADCHS_ADTRG2INV : (ADCHS Offset: 0x21C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADTRG2INV_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADTRG2INV) Bit invert register  Reset Value */

#define ADCHS_ADTRG2INV_Msk                   _UINT32_(0x00000000)                                 /* (ADCHS_ADTRG2INV) Register Mask  */


/* -------- ADCHS_ADTRG3CLR : (ADCHS Offset: 0x224) (R/W 32) Bit clear register -------- */
#define ADCHS_ADTRG3CLR_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADTRG3CLR) Bit clear register  Reset Value */

#define ADCHS_ADTRG3CLR_Msk                   _UINT32_(0x00000000)                                 /* (ADCHS_ADTRG3CLR) Register Mask  */


/* -------- ADCHS_ADTRG3SET : (ADCHS Offset: 0x228) (R/W 32) Bit set register -------- */
#define ADCHS_ADTRG3SET_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADTRG3SET) Bit set register  Reset Value */

#define ADCHS_ADTRG3SET_Msk                   _UINT32_(0x00000000)                                 /* (ADCHS_ADTRG3SET) Register Mask  */


/* -------- ADCHS_ADTRG3INV : (ADCHS Offset: 0x22C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADTRG3INV_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADTRG3INV) Bit invert register  Reset Value */

#define ADCHS_ADTRG3INV_Msk                   _UINT32_(0x00000000)                                 /* (ADCHS_ADTRG3INV) Register Mask  */


/* -------- ADCHS_ADCCMPCON1 : (ADCHS Offset: 0x280) (R/W 32)  -------- */
#define ADCHS_ADCCMPCON1_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPCON1)   Reset Value */

#define ADCHS_ADCCMPCON1_IELOLO_Pos           _UINT32_(0)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_IELOLO_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_IELOLO_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_IELOLO(value)        (ADCHS_ADCCMPCON1_IELOLO_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_IELOLO_Pos)) /* Assigment of value for IELOLO in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_IELOHI_Pos           _UINT32_(1)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_IELOHI_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_IELOHI_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_IELOHI(value)        (ADCHS_ADCCMPCON1_IELOHI_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_IELOHI_Pos)) /* Assigment of value for IELOHI in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_IEHILO_Pos           _UINT32_(2)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_IEHILO_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_IEHILO_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_IEHILO(value)        (ADCHS_ADCCMPCON1_IEHILO_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_IEHILO_Pos)) /* Assigment of value for IEHILO in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_IEHIHI_Pos           _UINT32_(3)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_IEHIHI_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_IEHIHI_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_IEHIHI(value)        (ADCHS_ADCCMPCON1_IEHIHI_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_IEHIHI_Pos)) /* Assigment of value for IEHIHI in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_IEBTWN_Pos           _UINT32_(4)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_IEBTWN_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_IEBTWN_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_IEBTWN(value)        (ADCHS_ADCCMPCON1_IEBTWN_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_IEBTWN_Pos)) /* Assigment of value for IEBTWN in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_DCMPED_Pos           _UINT32_(5)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_DCMPED_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_DCMPED_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_DCMPED(value)        (ADCHS_ADCCMPCON1_DCMPED_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_DCMPED_Pos)) /* Assigment of value for DCMPED in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_DCMPIEN_Pos          _UINT32_(6)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_DCMPIEN_Msk          (_UINT32_(0x1) << ADCHS_ADCCMPCON1_DCMPIEN_Pos)      /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_DCMPIEN(value)       (ADCHS_ADCCMPCON1_DCMPIEN_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_DCMPIEN_Pos)) /* Assigment of value for DCMPIEN in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_ENDCMP_Pos           _UINT32_(7)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_ENDCMP_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON1_ENDCMP_Pos)       /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_ENDCMP(value)        (ADCHS_ADCCMPCON1_ENDCMP_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_ENDCMP_Pos)) /* Assigment of value for ENDCMP in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_CMPINID0_Pos         _UINT32_(8)                                          /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_CMPINID0_Msk         (_UINT32_(0x3F) << ADCHS_ADCCMPCON1_CMPINID0_Pos)    /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_CMPINID0(value)      (ADCHS_ADCCMPCON1_CMPINID0_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_CMPINID0_Pos)) /* Assigment of value for CMPINID0 in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_CVD_DATA_Pos         _UINT32_(16)                                         /* (ADCHS_ADCCMPCON1)  Position */
#define ADCHS_ADCCMPCON1_CVD_DATA_Msk         (_UINT32_(0xFFFF) << ADCHS_ADCCMPCON1_CVD_DATA_Pos)  /* (ADCHS_ADCCMPCON1)  Mask */
#define ADCHS_ADCCMPCON1_CVD_DATA(value)      (ADCHS_ADCCMPCON1_CVD_DATA_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON1_CVD_DATA_Pos)) /* Assigment of value for CVD_DATA in the ADCHS_ADCCMPCON1 register */
#define ADCHS_ADCCMPCON1_Msk                  _UINT32_(0xFFFF3FFF)                                 /* (ADCHS_ADCCMPCON1) Register Mask  */


/* -------- ADCHS_ADCCMPCON1CLR : (ADCHS Offset: 0x284) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCMPCON1CLR_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPCON1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCCMPCON1CLR_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPCON1CLR) Register Mask  */


/* -------- ADCHS_ADCCMPCON1SET : (ADCHS Offset: 0x288) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCMPCON1SET_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPCON1SET) Bit set register  Reset Value */

#define ADCHS_ADCCMPCON1SET_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPCON1SET) Register Mask  */


/* -------- ADCHS_ADCCMPCON1INV : (ADCHS Offset: 0x28C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCMPCON1INV_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPCON1INV) Bit invert register  Reset Value */

#define ADCHS_ADCCMPCON1INV_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCCMPCON1INV) Register Mask  */


/* -------- ADCHS_ADCCMPCON2 : (ADCHS Offset: 0x290) (R/W 32)  -------- */
#define ADCHS_ADCCMPCON2_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCMPCON2)   Reset Value */

#define ADCHS_ADCCMPCON2_IELOLO_Pos           _UINT32_(0)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_IELOLO_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_IELOLO_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_IELOLO(value)        (ADCHS_ADCCMPCON2_IELOLO_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_IELOLO_Pos)) /* Assigment of value for IELOLO in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_IELOHI_Pos           _UINT32_(1)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_IELOHI_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_IELOHI_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_IELOHI(value)        (ADCHS_ADCCMPCON2_IELOHI_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_IELOHI_Pos)) /* Assigment of value for IELOHI in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_IEHILO_Pos           _UINT32_(2)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_IEHILO_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_IEHILO_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_IEHILO(value)        (ADCHS_ADCCMPCON2_IEHILO_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_IEHILO_Pos)) /* Assigment of value for IEHILO in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_IEHIHI_Pos           _UINT32_(3)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_IEHIHI_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_IEHIHI_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_IEHIHI(value)        (ADCHS_ADCCMPCON2_IEHIHI_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_IEHIHI_Pos)) /* Assigment of value for IEHIHI in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_IEBTWN_Pos           _UINT32_(4)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_IEBTWN_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_IEBTWN_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_IEBTWN(value)        (ADCHS_ADCCMPCON2_IEBTWN_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_IEBTWN_Pos)) /* Assigment of value for IEBTWN in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_DCMPED_Pos           _UINT32_(5)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_DCMPED_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_DCMPED_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_DCMPED(value)        (ADCHS_ADCCMPCON2_DCMPED_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_DCMPED_Pos)) /* Assigment of value for DCMPED in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_DCMPGIEN_Pos         _UINT32_(6)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_DCMPGIEN_Msk         (_UINT32_(0x1) << ADCHS_ADCCMPCON2_DCMPGIEN_Pos)     /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_DCMPGIEN(value)      (ADCHS_ADCCMPCON2_DCMPGIEN_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_DCMPGIEN_Pos)) /* Assigment of value for DCMPGIEN in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_ENDCMP_Pos           _UINT32_(7)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_ENDCMP_Msk           (_UINT32_(0x1) << ADCHS_ADCCMPCON2_ENDCMP_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_ENDCMP(value)        (ADCHS_ADCCMPCON2_ENDCMP_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_ENDCMP_Pos)) /* Assigment of value for ENDCMP in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_AINID_Pos            _UINT32_(8)                                          /* (ADCHS_ADCCMPCON2)  Position */
#define ADCHS_ADCCMPCON2_AINID_Msk            (_UINT32_(0x1F) << ADCHS_ADCCMPCON2_AINID_Pos)       /* (ADCHS_ADCCMPCON2)  Mask */
#define ADCHS_ADCCMPCON2_AINID(value)         (ADCHS_ADCCMPCON2_AINID_Msk & (_UINT32_(value) << ADCHS_ADCCMPCON2_AINID_Pos)) /* Assigment of value for AINID in the ADCHS_ADCCMPCON2 register */
#define ADCHS_ADCCMPCON2_Msk                  _UINT32_(0x00001FFF)                                 /* (ADCHS_ADCCMPCON2) Register Mask  */


/* -------- ADCHS_ADCMPCON2CLR : (ADCHS Offset: 0x294) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCMPCON2CLR_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCMPCON2CLR) Bit clear register  Reset Value */

#define ADCHS_ADCMPCON2CLR_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCMPCON2CLR) Register Mask  */


/* -------- ADCHS_ADCMPCON2SET : (ADCHS Offset: 0x298) (R/W 32) Bit set register -------- */
#define ADCHS_ADCMPCON2SET_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCMPCON2SET) Bit set register  Reset Value */

#define ADCHS_ADCMPCON2SET_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCMPCON2SET) Register Mask  */


/* -------- ADCHS_ADCMPCON2INV : (ADCHS Offset: 0x29C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCMPCON2INV_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCMPCON2INV) Bit invert register  Reset Value */

#define ADCHS_ADCMPCON2INV_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCMPCON2INV) Register Mask  */


/* -------- ADCHS_ADCFSTATCLR : (ADCHS Offset: 0x2E4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCFSTATCLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFSTATCLR) Bit clear register  Reset Value */

#define ADCHS_ADCFSTATCLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFSTATCLR) Register Mask  */


/* -------- ADCHS_ADCFSTATSET : (ADCHS Offset: 0x2E8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCFSTATSET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFSTATSET) Bit set register  Reset Value */

#define ADCHS_ADCFSTATSET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFSTATSET) Register Mask  */


/* -------- ADCHS_ADCFSTATINV : (ADCHS Offset: 0x2EC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCFSTATINV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFSTATINV) Bit invert register  Reset Value */

#define ADCHS_ADCFSTATINV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFSTATINV) Register Mask  */


/* -------- ADCHS_ADCFIFOCLR : (ADCHS Offset: 0x2F4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCFIFOCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCFIFOCLR) Bit clear register  Reset Value */

#define ADCHS_ADCFIFOCLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCFIFOCLR) Register Mask  */


/* -------- ADCHS_ADCFIFOSET : (ADCHS Offset: 0x2F8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCFIFOSET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCFIFOSET) Bit set register  Reset Value */

#define ADCHS_ADCFIFOSET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCFIFOSET) Register Mask  */


/* -------- ADCHS_ADCFIFOINV : (ADCHS Offset: 0x2FC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCFIFOINV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCFIFOINV) Bit invert register  Reset Value */

#define ADCHS_ADCFIFOINV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCFIFOINV) Register Mask  */


/* -------- ADCHS_ADCBASE : (ADCHS Offset: 0x300) (R/W 32)  -------- */
#define ADCHS_ADCBASE_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCBASE)   Reset Value */

#define ADCHS_ADCBASE_ADCBASE_Pos             _UINT32_(0)                                          /* (ADCHS_ADCBASE)  Position */
#define ADCHS_ADCBASE_ADCBASE_Msk             (_UINT32_(0xFFFF) << ADCHS_ADCBASE_ADCBASE_Pos)      /* (ADCHS_ADCBASE)  Mask */
#define ADCHS_ADCBASE_ADCBASE(value)          (ADCHS_ADCBASE_ADCBASE_Msk & (_UINT32_(value) << ADCHS_ADCBASE_ADCBASE_Pos)) /* Assigment of value for ADCBASE in the ADCHS_ADCBASE register */
#define ADCHS_ADCBASE_Msk                     _UINT32_(0x0000FFFF)                                 /* (ADCHS_ADCBASE) Register Mask  */


/* -------- ADCHS_ADCBASECLR : (ADCHS Offset: 0x304) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCBASECLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCBASECLR) Bit clear register  Reset Value */

#define ADCHS_ADCBASECLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCBASECLR) Register Mask  */


/* -------- ADCHS_ADCBASESET : (ADCHS Offset: 0x308) (R/W 32) Bit set register -------- */
#define ADCHS_ADCBASESET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCBASESET) Bit set register  Reset Value */

#define ADCHS_ADCBASESET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCBASESET) Register Mask  */


/* -------- ADCHS_ADCBASEINV : (ADCHS Offset: 0x30C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCBASEINV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCBASEINV) Bit invert register  Reset Value */

#define ADCHS_ADCBASEINV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCBASEINV) Register Mask  */


/* -------- ADCHS_ADCDMASTAT : (ADCHS Offset: 0x310) (R/W 32)  -------- */
#define ADCHS_ADCDMASTAT_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCDMASTAT)   Reset Value */

#define ADCHS_ADCDMASTAT_RAF0_Pos             _UINT32_(0)                                          /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_RAF0_Msk             (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RAF0_Pos)         /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_RAF0(value)          (ADCHS_ADCDMASTAT_RAF0_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RAF0_Pos)) /* Assigment of value for RAF0 in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_RAF_IEN0_Pos         _UINT32_(8)                                          /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_RAF_IEN0_Msk         (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RAF_IEN0_Pos)     /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_RAF_IEN0(value)      (ADCHS_ADCDMASTAT_RAF_IEN0_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RAF_IEN0_Pos)) /* Assigment of value for RAF_IEN0 in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_DMA_CNT_EN_Pos       _UINT32_(15)                                         /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_DMA_CNT_EN_Msk       (_UINT32_(0x1) << ADCHS_ADCDMASTAT_DMA_CNT_EN_Pos)   /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_DMA_CNT_EN(value)    (ADCHS_ADCDMASTAT_DMA_CNT_EN_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_DMA_CNT_EN_Pos)) /* Assigment of value for DMA_CNT_EN in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_RBF0_Pos             _UINT32_(16)                                         /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_RBF0_Msk             (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RBF0_Pos)         /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_RBF0(value)          (ADCHS_ADCDMASTAT_RBF0_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RBF0_Pos)) /* Assigment of value for RBF0 in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_WR_OVF_ERR_Pos       _UINT32_(23)                                         /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_WR_OVF_ERR_Msk       (_UINT32_(0x1) << ADCHS_ADCDMASTAT_WR_OVF_ERR_Pos)   /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_WR_OVF_ERR(value)    (ADCHS_ADCDMASTAT_WR_OVF_ERR_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_WR_OVF_ERR_Pos)) /* Assigment of value for WR_OVF_ERR in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_RBF_IEN0_Pos         _UINT32_(24)                                         /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_RBF_IEN0_Msk         (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RBF_IEN0_Pos)     /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_RBF_IEN0(value)      (ADCHS_ADCDMASTAT_RBF_IEN0_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RBF_IEN0_Pos)) /* Assigment of value for RBF_IEN0 in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_DMAEN_Pos            _UINT32_(31)                                         /* (ADCHS_ADCDMASTAT)  Position */
#define ADCHS_ADCDMASTAT_DMAEN_Msk            (_UINT32_(0x1) << ADCHS_ADCDMASTAT_DMAEN_Pos)        /* (ADCHS_ADCDMASTAT)  Mask */
#define ADCHS_ADCDMASTAT_DMAEN(value)         (ADCHS_ADCDMASTAT_DMAEN_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_DMAEN_Pos)) /* Assigment of value for DMAEN in the ADCHS_ADCDMASTAT register */
#define ADCHS_ADCDMASTAT_Msk                  _UINT32_(0x81818101)                                 /* (ADCHS_ADCDMASTAT) Register Mask  */

#define ADCHS_ADCDMASTAT_RAF_Pos              _UINT32_(0)                                          /* (ADCHS_ADCDMASTAT Position)  */
#define ADCHS_ADCDMASTAT_RAF_Msk              (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RAF_Pos)          /* (ADCHS_ADCDMASTAT Mask) RAF */
#define ADCHS_ADCDMASTAT_RAF(value)           (ADCHS_ADCDMASTAT_RAF_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RAF_Pos)) 
#define ADCHS_ADCDMASTAT_RAF_IEN_Pos          _UINT32_(8)                                          /* (ADCHS_ADCDMASTAT Position)  */
#define ADCHS_ADCDMASTAT_RAF_IEN_Msk          (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RAF_IEN_Pos)      /* (ADCHS_ADCDMASTAT Mask) RAF_IEN */
#define ADCHS_ADCDMASTAT_RAF_IEN(value)       (ADCHS_ADCDMASTAT_RAF_IEN_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RAF_IEN_Pos)) 
#define ADCHS_ADCDMASTAT_RBF_Pos              _UINT32_(16)                                         /* (ADCHS_ADCDMASTAT Position)  */
#define ADCHS_ADCDMASTAT_RBF_Msk              (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RBF_Pos)          /* (ADCHS_ADCDMASTAT Mask) RBF */
#define ADCHS_ADCDMASTAT_RBF(value)           (ADCHS_ADCDMASTAT_RBF_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RBF_Pos)) 
#define ADCHS_ADCDMASTAT_RBF_IEN_Pos          _UINT32_(24)                                         /* (ADCHS_ADCDMASTAT Position)  */
#define ADCHS_ADCDMASTAT_RBF_IEN_Msk          (_UINT32_(0x1) << ADCHS_ADCDMASTAT_RBF_IEN_Pos)      /* (ADCHS_ADCDMASTAT Mask) RBF_IEN */
#define ADCHS_ADCDMASTAT_RBF_IEN(value)       (ADCHS_ADCDMASTAT_RBF_IEN_Msk & (_UINT32_(value) << ADCHS_ADCDMASTAT_RBF_IEN_Pos)) 

/* -------- ADCHS_ADCDMASTATCLR : (ADCHS Offset: 0x314) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCDMASTATCLR_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCDMASTATCLR) Bit clear register  Reset Value */

#define ADCHS_ADCDMASTATCLR_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCDMASTATCLR) Register Mask  */


/* -------- ADCHS_ADCDMASTATSET : (ADCHS Offset: 0x318) (R/W 32) Bit set register -------- */
#define ADCHS_ADCDMASTATSET_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCDMASTATSET) Bit set register  Reset Value */

#define ADCHS_ADCDMASTATSET_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCDMASTATSET) Register Mask  */


/* -------- ADCHS_ADCDMASTATINV : (ADCHS Offset: 0x31C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCDMASTATINV_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCDMASTATINV) Bit invert register  Reset Value */

#define ADCHS_ADCDMASTATINV_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCDMASTATINV) Register Mask  */


/* -------- ADCHS_ADCCNTB : (ADCHS Offset: 0x320) (R/W 32)  -------- */
#define ADCHS_ADCCNTB_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCCNTB)   Reset Value */

#define ADCHS_ADCCNTB_ADCCNTB_Pos             _UINT32_(0)                                          /* (ADCHS_ADCCNTB)  Position */
#define ADCHS_ADCCNTB_ADCCNTB_Msk             (_UINT32_(0xFFFFFFFF) << ADCHS_ADCCNTB_ADCCNTB_Pos)  /* (ADCHS_ADCCNTB)  Mask */
#define ADCHS_ADCCNTB_ADCCNTB(value)          (ADCHS_ADCCNTB_ADCCNTB_Msk & (_UINT32_(value) << ADCHS_ADCCNTB_ADCCNTB_Pos)) /* Assigment of value for ADCCNTB in the ADCHS_ADCCNTB register */
#define ADCHS_ADCCNTB_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCCNTB) Register Mask  */


/* -------- ADCHS_ADCCNTBCLR : (ADCHS Offset: 0x324) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCCNTBCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCNTBCLR) Bit clear register  Reset Value */

#define ADCHS_ADCCNTBCLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCNTBCLR) Register Mask  */


/* -------- ADCHS_ADCCNTBSET : (ADCHS Offset: 0x328) (R/W 32) Bit set register -------- */
#define ADCHS_ADCCNTBSET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCNTBSET) Bit set register  Reset Value */

#define ADCHS_ADCCNTBSET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCNTBSET) Register Mask  */


/* -------- ADCHS_ADCCNTBINV : (ADCHS Offset: 0x32C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCCNTBINV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCCNTBINV) Bit invert register  Reset Value */

#define ADCHS_ADCCNTBINV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCCNTBINV) Register Mask  */


/* -------- ADCHS_ADCDMAB : (ADCHS Offset: 0x330) (R/W 32)  -------- */
#define ADCHS_ADCDMAB_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADCDMAB)   Reset Value */

#define ADCHS_ADCDMAB_ADDMAB_Pos              _UINT32_(0)                                          /* (ADCHS_ADCDMAB)  Position */
#define ADCHS_ADCDMAB_ADDMAB_Msk              (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDMAB_ADDMAB_Pos)   /* (ADCHS_ADCDMAB)  Mask */
#define ADCHS_ADCDMAB_ADDMAB(value)           (ADCHS_ADCDMAB_ADDMAB_Msk & (_UINT32_(value) << ADCHS_ADCDMAB_ADDMAB_Pos)) /* Assigment of value for ADDMAB in the ADCHS_ADCDMAB register */
#define ADCHS_ADCDMAB_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDMAB) Register Mask  */


/* -------- ADCHS_ADCDMABCLR : (ADCHS Offset: 0x334) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCDMABCLR_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCDMABCLR) Bit clear register  Reset Value */

#define ADCHS_ADCDMABCLR_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCDMABCLR) Register Mask  */


/* -------- ADCHS_ADCDMABSET : (ADCHS Offset: 0x338) (R/W 32) Bit set register -------- */
#define ADCHS_ADCDMABSET_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCDMABSET) Bit set register  Reset Value */

#define ADCHS_ADCDMABSET_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCDMABSET) Register Mask  */


/* -------- ADCHS_ADCDMABINV : (ADCHS Offset: 0x33C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCDMABINV_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCDMABINV) Bit invert register  Reset Value */

#define ADCHS_ADCDMABINV_Msk                  _UINT32_(0x00000000)                                 /* (ADCHS_ADCDMABINV) Register Mask  */


/* -------- ADCHS_ADCTRGSNS : (ADCHS Offset: 0x340) (R/W 32)  -------- */
#define ADCHS_ADCTRGSNS_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCTRGSNS)   Reset Value */

#define ADCHS_ADCTRGSNS_LVL0_Pos              _UINT32_(0)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL0_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL0_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL0(value)           (ADCHS_ADCTRGSNS_LVL0_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL0_Pos)) /* Assigment of value for LVL0 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL1_Pos              _UINT32_(1)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL1_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL1_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL1(value)           (ADCHS_ADCTRGSNS_LVL1_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL1_Pos)) /* Assigment of value for LVL1 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL2_Pos              _UINT32_(2)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL2_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL2_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL2(value)           (ADCHS_ADCTRGSNS_LVL2_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL2_Pos)) /* Assigment of value for LVL2 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL3_Pos              _UINT32_(3)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL3_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL3_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL3(value)           (ADCHS_ADCTRGSNS_LVL3_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL3_Pos)) /* Assigment of value for LVL3 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL4_Pos              _UINT32_(4)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL4_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL4_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL4(value)           (ADCHS_ADCTRGSNS_LVL4_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL4_Pos)) /* Assigment of value for LVL4 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL5_Pos              _UINT32_(5)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL5_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL5_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL5(value)           (ADCHS_ADCTRGSNS_LVL5_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL5_Pos)) /* Assigment of value for LVL5 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL6_Pos              _UINT32_(6)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL6_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL6_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL6(value)           (ADCHS_ADCTRGSNS_LVL6_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL6_Pos)) /* Assigment of value for LVL6 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_LVL7_Pos              _UINT32_(7)                                          /* (ADCHS_ADCTRGSNS)  Position */
#define ADCHS_ADCTRGSNS_LVL7_Msk              (_UINT32_(0x1) << ADCHS_ADCTRGSNS_LVL7_Pos)          /* (ADCHS_ADCTRGSNS)  Mask */
#define ADCHS_ADCTRGSNS_LVL7(value)           (ADCHS_ADCTRGSNS_LVL7_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL7_Pos)) /* Assigment of value for LVL7 in the ADCHS_ADCTRGSNS register */
#define ADCHS_ADCTRGSNS_Msk                   _UINT32_(0x000000FF)                                 /* (ADCHS_ADCTRGSNS) Register Mask  */

#define ADCHS_ADCTRGSNS_LVL_Pos               _UINT32_(0)                                          /* (ADCHS_ADCTRGSNS Position)  */
#define ADCHS_ADCTRGSNS_LVL_Msk               (_UINT32_(0xFF) << ADCHS_ADCTRGSNS_LVL_Pos)          /* (ADCHS_ADCTRGSNS Mask) LVL */
#define ADCHS_ADCTRGSNS_LVL(value)            (ADCHS_ADCTRGSNS_LVL_Msk & (_UINT32_(value) << ADCHS_ADCTRGSNS_LVL_Pos)) 

/* -------- ADCHS_ADCTRGSNSCLR : (ADCHS Offset: 0x344) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCTRGSNSCLR_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCTRGSNSCLR) Bit clear register  Reset Value */

#define ADCHS_ADCTRGSNSCLR_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCTRGSNSCLR) Register Mask  */


/* -------- ADCHS_ADCTRGSNSSET : (ADCHS Offset: 0x348) (R/W 32) Bit set register -------- */
#define ADCHS_ADCTRGSNSSET_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCTRGSNSSET) Bit set register  Reset Value */

#define ADCHS_ADCTRGSNSSET_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCTRGSNSSET) Register Mask  */


/* -------- ADCHS_ADCTRGSNSINV : (ADCHS Offset: 0x34C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCTRGSNSINV_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCTRGSNSINV) Bit invert register  Reset Value */

#define ADCHS_ADCTRGSNSINV_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCTRGSNSINV) Register Mask  */


/* -------- ADCHS_ADC0TIMECLR : (ADCHS Offset: 0x354) (R/W 32) Bit clear register -------- */
#define ADCHS_ADC0TIMECLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADC0TIMECLR) Bit clear register  Reset Value */

#define ADCHS_ADC0TIMECLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADC0TIMECLR) Register Mask  */


/* -------- ADCHS_ADC0TIMESET : (ADCHS Offset: 0x358) (R/W 32) Bit set register -------- */
#define ADCHS_ADC0TIMESET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADC0TIMESET) Bit set register  Reset Value */

#define ADCHS_ADC0TIMESET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADC0TIMESET) Register Mask  */


/* -------- ADCHS_ADC0TIMEINV : (ADCHS Offset: 0x35C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADC0TIMEINV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADC0TIMEINV) Bit invert register  Reset Value */

#define ADCHS_ADC0TIMEINV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADC0TIMEINV) Register Mask  */


/* -------- ADCHS_ADCEISTAT1CLR : (ADCHS Offset: 0x3E4) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCEISTAT1CLR_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCEISTAT1CLR) Bit clear register  Reset Value */

#define ADCHS_ADCEISTAT1CLR_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCEISTAT1CLR) Register Mask  */


/* -------- ADCHS_ADCEISTAT1SET : (ADCHS Offset: 0x3E8) (R/W 32) Bit set register -------- */
#define ADCHS_ADCEISTAT1SET_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCEISTAT1SET) Bit set register  Reset Value */

#define ADCHS_ADCEISTAT1SET_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCEISTAT1SET) Register Mask  */


/* -------- ADCHS_ADCEISTAT1INV : (ADCHS Offset: 0x3EC) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCEISTAT1INV_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCEISTAT1INV) Bit invert register  Reset Value */

#define ADCHS_ADCEISTAT1INV_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCEISTAT1INV) Register Mask  */


/* -------- ADCHS_ADCANCON : (ADCHS Offset: 0x400) (R/W 32)  -------- */
#define ADCHS_ADCANCON_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCANCON)   Reset Value */

#define ADCHS_ADCANCON_ANEN0_Pos              _UINT32_(0)                                          /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_ANEN0_Msk              (_UINT32_(0x1) << ADCHS_ADCANCON_ANEN0_Pos)          /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_ANEN0(value)           (ADCHS_ADCANCON_ANEN0_Msk & (_UINT32_(value) << ADCHS_ADCANCON_ANEN0_Pos)) /* Assigment of value for ANEN0 in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_ANEN7_Pos              _UINT32_(7)                                          /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_ANEN7_Msk              (_UINT32_(0x1) << ADCHS_ADCANCON_ANEN7_Pos)          /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_ANEN7(value)           (ADCHS_ADCANCON_ANEN7_Msk & (_UINT32_(value) << ADCHS_ADCANCON_ANEN7_Pos)) /* Assigment of value for ANEN7 in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_WKRDY0_Pos             _UINT32_(8)                                          /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_WKRDY0_Msk             (_UINT32_(0x1) << ADCHS_ADCANCON_WKRDY0_Pos)         /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_WKRDY0(value)          (ADCHS_ADCANCON_WKRDY0_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKRDY0_Pos)) /* Assigment of value for WKRDY0 in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_WKRDY7_Pos             _UINT32_(15)                                         /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_WKRDY7_Msk             (_UINT32_(0x1) << ADCHS_ADCANCON_WKRDY7_Pos)         /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_WKRDY7(value)          (ADCHS_ADCANCON_WKRDY7_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKRDY7_Pos)) /* Assigment of value for WKRDY7 in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_WKIEN0_Pos             _UINT32_(16)                                         /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_WKIEN0_Msk             (_UINT32_(0x1) << ADCHS_ADCANCON_WKIEN0_Pos)         /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_WKIEN0(value)          (ADCHS_ADCANCON_WKIEN0_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKIEN0_Pos)) /* Assigment of value for WKIEN0 in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_WKIEN7_Pos             _UINT32_(23)                                         /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_WKIEN7_Msk             (_UINT32_(0x1) << ADCHS_ADCANCON_WKIEN7_Pos)         /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_WKIEN7(value)          (ADCHS_ADCANCON_WKIEN7_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKIEN7_Pos)) /* Assigment of value for WKIEN7 in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_WKUPCLKCNT_Pos         _UINT32_(24)                                         /* (ADCHS_ADCANCON)  Position */
#define ADCHS_ADCANCON_WKUPCLKCNT_Msk         (_UINT32_(0xF) << ADCHS_ADCANCON_WKUPCLKCNT_Pos)     /* (ADCHS_ADCANCON)  Mask */
#define ADCHS_ADCANCON_WKUPCLKCNT(value)      (ADCHS_ADCANCON_WKUPCLKCNT_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKUPCLKCNT_Pos)) /* Assigment of value for WKUPCLKCNT in the ADCHS_ADCANCON register */
#define ADCHS_ADCANCON_Msk                    _UINT32_(0x0F818181)                                 /* (ADCHS_ADCANCON) Register Mask  */

#define ADCHS_ADCANCON_ANEN_Pos               _UINT32_(0)                                          /* (ADCHS_ADCANCON Position)  */
#define ADCHS_ADCANCON_ANEN_Msk               (_UINT32_(0x3) << ADCHS_ADCANCON_ANEN_Pos)           /* (ADCHS_ADCANCON Mask) ANEN */
#define ADCHS_ADCANCON_ANEN(value)            (ADCHS_ADCANCON_ANEN_Msk & (_UINT32_(value) << ADCHS_ADCANCON_ANEN_Pos)) 
#define ADCHS_ADCANCON_WKRDY_Pos              _UINT32_(8)                                          /* (ADCHS_ADCANCON Position)  */
#define ADCHS_ADCANCON_WKRDY_Msk              (_UINT32_(0x3) << ADCHS_ADCANCON_WKRDY_Pos)          /* (ADCHS_ADCANCON Mask) WKRDY */
#define ADCHS_ADCANCON_WKRDY(value)           (ADCHS_ADCANCON_WKRDY_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKRDY_Pos)) 
#define ADCHS_ADCANCON_WKIEN_Pos              _UINT32_(16)                                         /* (ADCHS_ADCANCON Position)  */
#define ADCHS_ADCANCON_WKIEN_Msk              (_UINT32_(0x3) << ADCHS_ADCANCON_WKIEN_Pos)          /* (ADCHS_ADCANCON Mask) WKIEN */
#define ADCHS_ADCANCON_WKIEN(value)           (ADCHS_ADCANCON_WKIEN_Msk & (_UINT32_(value) << ADCHS_ADCANCON_WKIEN_Pos)) 

/* -------- ADCHS_ADCANLCTLCLR : (ADCHS Offset: 0x404) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCANLCTLCLR_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCANLCTLCLR) Bit clear register  Reset Value */

#define ADCHS_ADCANLCTLCLR_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCANLCTLCLR) Register Mask  */


/* -------- ADCHS_ADCANLCTLSET : (ADCHS Offset: 0x408) (R/W 32) Bit set register -------- */
#define ADCHS_ADCANLCTLSET_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCANLCTLSET) Bit set register  Reset Value */

#define ADCHS_ADCANLCTLSET_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCANLCTLSET) Register Mask  */


/* -------- ADCHS_ADCANLCTLINV : (ADCHS Offset: 0x40C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCANLCTLINV_RESETVALUE         _UINT32_(0x00)                                       /*  (ADCHS_ADCANLCTLINV) Bit invert register  Reset Value */

#define ADCHS_ADCANLCTLINV_Msk                _UINT32_(0x00000000)                                 /* (ADCHS_ADCANLCTLINV) Register Mask  */


/* -------- ADCHS_ADC7CFG : (ADCHS Offset: 0x670) (R/W 32)  -------- */
#define ADCHS_ADC7CFG_RESETVALUE              _UINT32_(0x00)                                       /*  (ADCHS_ADC7CFG)   Reset Value */

#define ADCHS_ADC7CFG_ADC7CFG_Pos             _UINT32_(0)                                          /* (ADCHS_ADC7CFG)  Position */
#define ADCHS_ADC7CFG_ADC7CFG_Msk             (_UINT32_(0xFFFFFFFF) << ADCHS_ADC7CFG_ADC7CFG_Pos)  /* (ADCHS_ADC7CFG)  Mask */
#define ADCHS_ADC7CFG_ADC7CFG(value)          (ADCHS_ADC7CFG_ADC7CFG_Msk & (_UINT32_(value) << ADCHS_ADC7CFG_ADC7CFG_Pos)) /* Assigment of value for ADC7CFG in the ADCHS_ADC7CFG register */
#define ADCHS_ADC7CFG_Msk                     _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADC7CFG) Register Mask  */


/* -------- ADCHS_ADCFGSHRCLR : (ADCHS Offset: 0x674) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCFGSHRCLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFGSHRCLR) Bit clear register  Reset Value */

#define ADCHS_ADCFGSHRCLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFGSHRCLR) Register Mask  */


/* -------- ADCHS_ADCFGSHRSET : (ADCHS Offset: 0x678) (R/W 32) Bit set register -------- */
#define ADCHS_ADCFGSHRSET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFGSHRSET) Bit set register  Reset Value */

#define ADCHS_ADCFGSHRSET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFGSHRSET) Register Mask  */


/* -------- ADCHS_ADCFGSHRINV : (ADCHS Offset: 0x67C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCFGSHRINV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCFGSHRINV) Bit invert register  Reset Value */

#define ADCHS_ADCFGSHRINV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCFGSHRINV) Register Mask  */


/* -------- ADCHS_ADCSVCONCLR : (ADCHS Offset: 0x684) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCSVCONCLR_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCSVCONCLR) Bit clear register  Reset Value */

#define ADCHS_ADCSVCONCLR_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCSVCONCLR) Register Mask  */


/* -------- ADCHS_ADCSVCONSET : (ADCHS Offset: 0x688) (R/W 32) Bit set register -------- */
#define ADCHS_ADCSVCONSET_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCSVCONSET) Bit set register  Reset Value */

#define ADCHS_ADCSVCONSET_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCSVCONSET) Register Mask  */


/* -------- ADCHS_ADCSVCONINV : (ADCHS Offset: 0x68C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCSVCONINV_RESETVALUE          _UINT32_(0x00)                                       /*  (ADCHS_ADCSVCONINV) Bit invert register  Reset Value */

#define ADCHS_ADCSVCONINV_Msk                 _UINT32_(0x00000000)                                 /* (ADCHS_ADCSVCONINV) Register Mask  */


/* -------- ADCHS_ADCSYSCFG0 : (ADCHS Offset: 0x700) (R/W 32)  -------- */
#define ADCHS_ADCSYSCFG0_RESETVALUE           _UINT32_(0x00)                                       /*  (ADCHS_ADCSYSCFG0)   Reset Value */

#define ADCHS_ADCSYSCFG0_AN0_Pos              _UINT32_(0)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN0_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN0_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN0(value)           (ADCHS_ADCSYSCFG0_AN0_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN0_Pos)) /* Assigment of value for AN0 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN1_Pos              _UINT32_(1)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN1_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN1_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN1(value)           (ADCHS_ADCSYSCFG0_AN1_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN1_Pos)) /* Assigment of value for AN1 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN2_Pos              _UINT32_(2)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN2_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN2_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN2(value)           (ADCHS_ADCSYSCFG0_AN2_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN2_Pos)) /* Assigment of value for AN2 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN3_Pos              _UINT32_(3)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN3_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN3_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN3(value)           (ADCHS_ADCSYSCFG0_AN3_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN3_Pos)) /* Assigment of value for AN3 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN4_Pos              _UINT32_(4)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN4_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN4_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN4(value)           (ADCHS_ADCSYSCFG0_AN4_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN4_Pos)) /* Assigment of value for AN4 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN5_Pos              _UINT32_(5)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN5_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN5_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN5(value)           (ADCHS_ADCSYSCFG0_AN5_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN5_Pos)) /* Assigment of value for AN5 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN6_Pos              _UINT32_(6)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN6_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN6_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN6(value)           (ADCHS_ADCSYSCFG0_AN6_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN6_Pos)) /* Assigment of value for AN6 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN7_Pos              _UINT32_(7)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN7_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN7_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN7(value)           (ADCHS_ADCSYSCFG0_AN7_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN7_Pos)) /* Assigment of value for AN7 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN8_Pos              _UINT32_(8)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN8_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN8_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN8(value)           (ADCHS_ADCSYSCFG0_AN8_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN8_Pos)) /* Assigment of value for AN8 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN9_Pos              _UINT32_(9)                                          /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN9_Msk              (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN9_Pos)          /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN9(value)           (ADCHS_ADCSYSCFG0_AN9_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN9_Pos)) /* Assigment of value for AN9 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN10_Pos             _UINT32_(10)                                         /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN10_Msk             (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN10_Pos)         /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN10(value)          (ADCHS_ADCSYSCFG0_AN10_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN10_Pos)) /* Assigment of value for AN10 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_AN11_Pos             _UINT32_(11)                                         /* (ADCHS_ADCSYSCFG0)  Position */
#define ADCHS_ADCSYSCFG0_AN11_Msk             (_UINT32_(0x1) << ADCHS_ADCSYSCFG0_AN11_Pos)         /* (ADCHS_ADCSYSCFG0)  Mask */
#define ADCHS_ADCSYSCFG0_AN11(value)          (ADCHS_ADCSYSCFG0_AN11_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN11_Pos)) /* Assigment of value for AN11 in the ADCHS_ADCSYSCFG0 register */
#define ADCHS_ADCSYSCFG0_Msk                  _UINT32_(0x00000FFF)                                 /* (ADCHS_ADCSYSCFG0) Register Mask  */

#define ADCHS_ADCSYSCFG0_AN_Pos               _UINT32_(0)                                          /* (ADCHS_ADCSYSCFG0 Position)  */
#define ADCHS_ADCSYSCFG0_AN_Msk               (_UINT32_(0xFFF) << ADCHS_ADCSYSCFG0_AN_Pos)         /* (ADCHS_ADCSYSCFG0 Mask) AN */
#define ADCHS_ADCSYSCFG0_AN(value)            (ADCHS_ADCSYSCFG0_AN_Msk & (_UINT32_(value) << ADCHS_ADCSYSCFG0_AN_Pos)) 

/* -------- ADCHS_ADCSYSCFG0CLR : (ADCHS Offset: 0x704) (R/W 32) Bit clear register -------- */
#define ADCHS_ADCSYSCFG0CLR_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCSYSCFG0CLR) Bit clear register  Reset Value */

#define ADCHS_ADCSYSCFG0CLR_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCSYSCFG0CLR) Register Mask  */


/* -------- ADCHS_ADCSYSCFG0SET : (ADCHS Offset: 0x708) (R/W 32) Bit set register -------- */
#define ADCHS_ADCSYSCFG0SET_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCSYSCFG0SET) Bit set register  Reset Value */

#define ADCHS_ADCSYSCFG0SET_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCSYSCFG0SET) Register Mask  */


/* -------- ADCHS_ADCSYSCFG0INV : (ADCHS Offset: 0x70C) (R/W 32) Bit invert register -------- */
#define ADCHS_ADCSYSCFG0INV_RESETVALUE        _UINT32_(0x00)                                       /*  (ADCHS_ADCSYSCFG0INV) Bit invert register  Reset Value */

#define ADCHS_ADCSYSCFG0INV_Msk               _UINT32_(0x00000000)                                 /* (ADCHS_ADCSYSCFG0INV) Register Mask  */


/* -------- ADCHS_ADCDATA0 : (ADCHS Offset: 0xA00) (R/W 32)  -------- */
#define ADCHS_ADCDATA0_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA0)   Reset Value */

#define ADCHS_ADCDATA0_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA0)  Position */
#define ADCHS_ADCDATA0_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA0_DATA_Pos)    /* (ADCHS_ADCDATA0)  Mask */
#define ADCHS_ADCDATA0_DATA(value)            (ADCHS_ADCDATA0_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA0_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA0 register */
#define ADCHS_ADCDATA0_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA0) Register Mask  */


/* -------- ADCHS_ADCDATA1 : (ADCHS Offset: 0xA10) (R/W 32)  -------- */
#define ADCHS_ADCDATA1_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA1)   Reset Value */

#define ADCHS_ADCDATA1_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA1)  Position */
#define ADCHS_ADCDATA1_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA1_DATA_Pos)    /* (ADCHS_ADCDATA1)  Mask */
#define ADCHS_ADCDATA1_DATA(value)            (ADCHS_ADCDATA1_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA1_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA1 register */
#define ADCHS_ADCDATA1_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA1) Register Mask  */


/* -------- ADCHS_ADCDATA2 : (ADCHS Offset: 0xA20) (R/W 32)  -------- */
#define ADCHS_ADCDATA2_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA2)   Reset Value */

#define ADCHS_ADCDATA2_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA2)  Position */
#define ADCHS_ADCDATA2_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA2_DATA_Pos)    /* (ADCHS_ADCDATA2)  Mask */
#define ADCHS_ADCDATA2_DATA(value)            (ADCHS_ADCDATA2_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA2_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA2 register */
#define ADCHS_ADCDATA2_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA2) Register Mask  */


/* -------- ADCHS_ADCDATA3 : (ADCHS Offset: 0xA30) (R/W 32)  -------- */
#define ADCHS_ADCDATA3_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA3)   Reset Value */

#define ADCHS_ADCDATA3_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA3)  Position */
#define ADCHS_ADCDATA3_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA3_DATA_Pos)    /* (ADCHS_ADCDATA3)  Mask */
#define ADCHS_ADCDATA3_DATA(value)            (ADCHS_ADCDATA3_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA3_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA3 register */
#define ADCHS_ADCDATA3_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA3) Register Mask  */


/* -------- ADCHS_ADCDATA4 : (ADCHS Offset: 0xA40) (R/W 32)  -------- */
#define ADCHS_ADCDATA4_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA4)   Reset Value */

#define ADCHS_ADCDATA4_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA4)  Position */
#define ADCHS_ADCDATA4_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA4_DATA_Pos)    /* (ADCHS_ADCDATA4)  Mask */
#define ADCHS_ADCDATA4_DATA(value)            (ADCHS_ADCDATA4_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA4_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA4 register */
#define ADCHS_ADCDATA4_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA4) Register Mask  */


/* -------- ADCHS_ADCDATA5 : (ADCHS Offset: 0xA50) (R/W 32)  -------- */
#define ADCHS_ADCDATA5_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA5)   Reset Value */

#define ADCHS_ADCDATA5_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA5)  Position */
#define ADCHS_ADCDATA5_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA5_DATA_Pos)    /* (ADCHS_ADCDATA5)  Mask */
#define ADCHS_ADCDATA5_DATA(value)            (ADCHS_ADCDATA5_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA5_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA5 register */
#define ADCHS_ADCDATA5_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA5) Register Mask  */


/* -------- ADCHS_ADCDATA6 : (ADCHS Offset: 0xA60) (R/W 32)  -------- */
#define ADCHS_ADCDATA6_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA6)   Reset Value */

#define ADCHS_ADCDATA6_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA6)  Position */
#define ADCHS_ADCDATA6_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA6_DATA_Pos)    /* (ADCHS_ADCDATA6)  Mask */
#define ADCHS_ADCDATA6_DATA(value)            (ADCHS_ADCDATA6_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA6_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA6 register */
#define ADCHS_ADCDATA6_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA6) Register Mask  */


/* -------- ADCHS_ADCDATA7 : (ADCHS Offset: 0xA70) (R/W 32)  -------- */
#define ADCHS_ADCDATA7_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA7)   Reset Value */

#define ADCHS_ADCDATA7_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA7)  Position */
#define ADCHS_ADCDATA7_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA7_DATA_Pos)    /* (ADCHS_ADCDATA7)  Mask */
#define ADCHS_ADCDATA7_DATA(value)            (ADCHS_ADCDATA7_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA7_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA7 register */
#define ADCHS_ADCDATA7_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA7) Register Mask  */


/* -------- ADCHS_ADCDATA8 : (ADCHS Offset: 0xA80) (R/W 32)  -------- */
#define ADCHS_ADCDATA8_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA8)   Reset Value */

#define ADCHS_ADCDATA8_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA8)  Position */
#define ADCHS_ADCDATA8_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA8_DATA_Pos)    /* (ADCHS_ADCDATA8)  Mask */
#define ADCHS_ADCDATA8_DATA(value)            (ADCHS_ADCDATA8_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA8_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA8 register */
#define ADCHS_ADCDATA8_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA8) Register Mask  */


/* -------- ADCHS_ADCDATA9 : (ADCHS Offset: 0xA90) (R/W 32)  -------- */
#define ADCHS_ADCDATA9_RESETVALUE             _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA9)   Reset Value */

#define ADCHS_ADCDATA9_DATA_Pos               _UINT32_(0)                                          /* (ADCHS_ADCDATA9)  Position */
#define ADCHS_ADCDATA9_DATA_Msk               (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA9_DATA_Pos)    /* (ADCHS_ADCDATA9)  Mask */
#define ADCHS_ADCDATA9_DATA(value)            (ADCHS_ADCDATA9_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA9_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA9 register */
#define ADCHS_ADCDATA9_Msk                    _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA9) Register Mask  */


/* -------- ADCHS_ADCDATA10 : (ADCHS Offset: 0xAA0) (R/W 32)  -------- */
#define ADCHS_ADCDATA10_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA10)   Reset Value */

#define ADCHS_ADCDATA10_DATA_Pos              _UINT32_(0)                                          /* (ADCHS_ADCDATA10)  Position */
#define ADCHS_ADCDATA10_DATA_Msk              (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA10_DATA_Pos)   /* (ADCHS_ADCDATA10)  Mask */
#define ADCHS_ADCDATA10_DATA(value)           (ADCHS_ADCDATA10_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA10_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA10 register */
#define ADCHS_ADCDATA10_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA10) Register Mask  */


/* -------- ADCHS_ADCDATA11 : (ADCHS Offset: 0xAB0) (R/W 32)  -------- */
#define ADCHS_ADCDATA11_RESETVALUE            _UINT32_(0x00)                                       /*  (ADCHS_ADCDATA11)   Reset Value */

#define ADCHS_ADCDATA11_DATA_Pos              _UINT32_(0)                                          /* (ADCHS_ADCDATA11)  Position */
#define ADCHS_ADCDATA11_DATA_Msk              (_UINT32_(0xFFFFFFFF) << ADCHS_ADCDATA11_DATA_Pos)   /* (ADCHS_ADCDATA11)  Mask */
#define ADCHS_ADCDATA11_DATA(value)           (ADCHS_ADCDATA11_DATA_Msk & (_UINT32_(value) << ADCHS_ADCDATA11_DATA_Pos)) /* Assigment of value for DATA in the ADCHS_ADCDATA11 register */
#define ADCHS_ADCDATA11_Msk                   _UINT32_(0xFFFFFFFF)                                 /* (ADCHS_ADCDATA11) Register Mask  */


/** \brief ADCHS register offsets definitions */
#define ADCHS_ADCCON1_REG_OFST         _UINT32_(0x00)      /* (ADCHS_ADCCON1)  Offset */
#define ADCHS_ADCCON1CLR_REG_OFST      _UINT32_(0x04)      /* (ADCHS_ADCCON1CLR) Bit clear register Offset */
#define ADCHS_ADCCON1SET_REG_OFST      _UINT32_(0x08)      /* (ADCHS_ADCCON1SET) Bit set register Offset */
#define ADCHS_ADCCON1INV_REG_OFST      _UINT32_(0x0C)      /* (ADCHS_ADCCON1INV) Bit invert register Offset */
#define ADCHS_ADCCON2_REG_OFST         _UINT32_(0x10)      /* (ADCHS_ADCCON2)  Offset */
#define ADCHS_ADCCON2CLR_REG_OFST      _UINT32_(0x14)      /* (ADCHS_ADCCON2CLR) Bit clear register Offset */
#define ADCHS_ADCCON2SET_REG_OFST      _UINT32_(0x18)      /* (ADCHS_ADCCON2SET) Bit set register Offset */
#define ADCHS_ADCCON2INV_REG_OFST      _UINT32_(0x1C)      /* (ADCHS_ADCCON2INV) Bit invert register Offset */
#define ADCHS_ADCCON3_REG_OFST         _UINT32_(0x20)      /* (ADCHS_ADCCON3)  Offset */
#define ADCHS_ADCCON3CLR_REG_OFST      _UINT32_(0x24)      /* (ADCHS_ADCCON3CLR) Bit clear register Offset */
#define ADCHS_ADCCON3SET_REG_OFST      _UINT32_(0x28)      /* (ADCHS_ADCCON3SET) Bit set register Offset */
#define ADCHS_ADCCON3INV_REG_OFST      _UINT32_(0x2C)      /* (ADCHS_ADCCON3INV) Bit invert register Offset */
#define ADCHS_ADCIMCON1_REG_OFST       _UINT32_(0x40)      /* (ADCHS_ADCIMCON1)  Offset */
#define ADCHS_ADCIMOD1CLR_REG_OFST     _UINT32_(0x44)      /* (ADCHS_ADCIMOD1CLR) Bit clear register Offset */
#define ADCHS_ADCIMOD1SET_REG_OFST     _UINT32_(0x48)      /* (ADCHS_ADCIMOD1SET) Bit set register Offset */
#define ADCHS_ADCIMOD1INV_REG_OFST     _UINT32_(0x4C)      /* (ADCHS_ADCIMOD1INV) Bit invert register Offset */
#define ADCHS_ADCGIRQEN1_REG_OFST      _UINT32_(0x80)      /* (ADCHS_ADCGIRQEN1)  Offset */
#define ADCHS_ADCGIRQEN1CLR_REG_OFST   _UINT32_(0x84)      /* (ADCHS_ADCGIRQEN1CLR) Bit clear register Offset */
#define ADCHS_ADCGIRQEN1SET_REG_OFST   _UINT32_(0x88)      /* (ADCHS_ADCGIRQEN1SET) Bit set register Offset */
#define ADCHS_ADCGIRQEN1INV_REG_OFST   _UINT32_(0x8C)      /* (ADCHS_ADCGIRQEN1INV) Bit invert register Offset */
#define ADCHS_ADCCSS1_REG_OFST         _UINT32_(0xA0)      /* (ADCHS_ADCCSS1)  Offset */
#define ADCHS_ADCCSS1CLR_REG_OFST      _UINT32_(0xA4)      /* (ADCHS_ADCCSS1CLR) Bit clear register Offset */
#define ADCHS_ADCCSS1SET_REG_OFST      _UINT32_(0xA8)      /* (ADCHS_ADCCSS1SET) Bit set register Offset */
#define ADCHS_ADCCSS1INV_REG_OFST      _UINT32_(0xAC)      /* (ADCHS_ADCCSS1INV) Bit invert register Offset */
#define ADCHS_ADCDSTAT1_REG_OFST       _UINT32_(0xC0)      /* (ADCHS_ADCDSTAT1)  Offset */
#define ADCHS_ADCDSTAT1CLR_REG_OFST    _UINT32_(0xC4)      /* (ADCHS_ADCDSTAT1CLR) Bit clear register Offset */
#define ADCHS_ADCDSTAT1SET_REG_OFST    _UINT32_(0xC8)      /* (ADCHS_ADCDSTAT1SET) Bit set register Offset */
#define ADCHS_ADCDSTAT1INV_REG_OFST    _UINT32_(0xCC)      /* (ADCHS_ADCDSTAT1INV) Bit invert register Offset */
#define ADCHS_ADCCMPEN1_REG_OFST       _UINT32_(0xE0)      /* (ADCHS_ADCCMPEN1)  Offset */
#define ADCHS_ADCCMPEN0CLR_REG_OFST    _UINT32_(0xE4)      /* (ADCHS_ADCCMPEN0CLR) Bit clear register Offset */
#define ADCHS_ADCCMPEN0SET_REG_OFST    _UINT32_(0xE8)      /* (ADCHS_ADCCMPEN0SET) Bit set register Offset */
#define ADCHS_ADCCMPEN0INV_REG_OFST    _UINT32_(0xEC)      /* (ADCHS_ADCCMPEN0INV) Bit invert register Offset */
#define ADCHS_ADCCMP1_REG_OFST         _UINT32_(0xF0)      /* (ADCHS_ADCCMP1)  Offset */
#define ADCHS_ADCCMP0CLR_REG_OFST      _UINT32_(0xF4)      /* (ADCHS_ADCCMP0CLR) Bit clear register Offset */
#define ADCHS_ADCCMP0SET_REG_OFST      _UINT32_(0xF8)      /* (ADCHS_ADCCMP0SET) Bit set register Offset */
#define ADCHS_ADCCMP0INV_REG_OFST      _UINT32_(0xFC)      /* (ADCHS_ADCCMP0INV) Bit invert register Offset */
#define ADCHS_ADCCMPEN2_REG_OFST       _UINT32_(0x100)     /* (ADCHS_ADCCMPEN2)  Offset */
#define ADCHS_ADCCMPEN1CLR_REG_OFST    _UINT32_(0x104)     /* (ADCHS_ADCCMPEN1CLR) Bit clear register Offset */
#define ADCHS_ADCCMPEN1SET_REG_OFST    _UINT32_(0x108)     /* (ADCHS_ADCCMPEN1SET) Bit set register Offset */
#define ADCHS_ADCCMPEN1INV_REG_OFST    _UINT32_(0x10C)     /* (ADCHS_ADCCMPEN1INV) Bit invert register Offset */
#define ADCHS_ADCCMP2_REG_OFST         _UINT32_(0x110)     /* (ADCHS_ADCCMP2)  Offset */
#define ADCHS_ADDCMP1CLR_REG_OFST      _UINT32_(0x114)     /* (ADCHS_ADDCMP1CLR) Bit clear register Offset */
#define ADCHS_ADDCMP1SET_REG_OFST      _UINT32_(0x118)     /* (ADCHS_ADDCMP1SET) Bit set register Offset */
#define ADCHS_ADDCMP1INV_REG_OFST      _UINT32_(0x11C)     /* (ADCHS_ADDCMP1INV) Bit invert register Offset */
#define ADCHS_ADCFLTR1_REG_OFST        _UINT32_(0x1A0)     /* (ADCHS_ADCFLTR1)  Offset */
#define ADCHS_ADCFLTR0CLR_REG_OFST     _UINT32_(0x1A4)     /* (ADCHS_ADCFLTR0CLR) Bit clear register Offset */
#define ADCHS_ADCFLTR0SET_REG_OFST     _UINT32_(0x1A8)     /* (ADCHS_ADCFLTR0SET) Bit set register Offset */
#define ADCHS_ADCFLTR0INV_REG_OFST     _UINT32_(0x1AC)     /* (ADCHS_ADCFLTR0INV) Bit invert register Offset */
#define ADCHS_ADCFLTR2_REG_OFST        _UINT32_(0x1B0)     /* (ADCHS_ADCFLTR2)  Offset */
#define ADCHS_ADCFLTR1CLR_REG_OFST     _UINT32_(0x1B4)     /* (ADCHS_ADCFLTR1CLR) Bit clear register Offset */
#define ADCHS_ADCFLTR1SET_REG_OFST     _UINT32_(0x1B8)     /* (ADCHS_ADCFLTR1SET) Bit set register Offset */
#define ADCHS_ADCFLTR1INV_REG_OFST     _UINT32_(0x1BC)     /* (ADCHS_ADCFLTR1INV) Bit invert register Offset */
#define ADCHS_ADCTRG1_REG_OFST         _UINT32_(0x200)     /* (ADCHS_ADCTRG1) ADC Trigger Source 1 Register Offset */
#define ADCHS_ADCTRG1CLR_REG_OFST      _UINT32_(0x204)     /* (ADCHS_ADCTRG1CLR) Bit clear register Offset */
#define ADCHS_ADCTRG1SET_REG_OFST      _UINT32_(0x208)     /* (ADCHS_ADCTRG1SET) Bit set register Offset */
#define ADCHS_ADCTRG1INV_REG_OFST      _UINT32_(0x20C)     /* (ADCHS_ADCTRG1INV) Bit invert register Offset */
#define ADCHS_ADCTRG2_REG_OFST         _UINT32_(0x210)     /* (ADCHS_ADCTRG2) ADC Trigger Source 2 Register Offset */
#define ADCHS_ADTRG2CLR_REG_OFST       _UINT32_(0x214)     /* (ADCHS_ADTRG2CLR) Bit clear register Offset */
#define ADCHS_ADTRG2SET_REG_OFST       _UINT32_(0x218)     /* (ADCHS_ADTRG2SET) Bit set register Offset */
#define ADCHS_ADTRG2INV_REG_OFST       _UINT32_(0x21C)     /* (ADCHS_ADTRG2INV) Bit invert register Offset */
#define ADCHS_ADTRG3CLR_REG_OFST       _UINT32_(0x224)     /* (ADCHS_ADTRG3CLR) Bit clear register Offset */
#define ADCHS_ADTRG3SET_REG_OFST       _UINT32_(0x228)     /* (ADCHS_ADTRG3SET) Bit set register Offset */
#define ADCHS_ADTRG3INV_REG_OFST       _UINT32_(0x22C)     /* (ADCHS_ADTRG3INV) Bit invert register Offset */
#define ADCHS_ADCCMPCON1_REG_OFST      _UINT32_(0x280)     /* (ADCHS_ADCCMPCON1)  Offset */
#define ADCHS_ADCCMPCON1CLR_REG_OFST   _UINT32_(0x284)     /* (ADCHS_ADCCMPCON1CLR) Bit clear register Offset */
#define ADCHS_ADCCMPCON1SET_REG_OFST   _UINT32_(0x288)     /* (ADCHS_ADCCMPCON1SET) Bit set register Offset */
#define ADCHS_ADCCMPCON1INV_REG_OFST   _UINT32_(0x28C)     /* (ADCHS_ADCCMPCON1INV) Bit invert register Offset */
#define ADCHS_ADCCMPCON2_REG_OFST      _UINT32_(0x290)     /* (ADCHS_ADCCMPCON2)  Offset */
#define ADCHS_ADCMPCON2CLR_REG_OFST    _UINT32_(0x294)     /* (ADCHS_ADCMPCON2CLR) Bit clear register Offset */
#define ADCHS_ADCMPCON2SET_REG_OFST    _UINT32_(0x298)     /* (ADCHS_ADCMPCON2SET) Bit set register Offset */
#define ADCHS_ADCMPCON2INV_REG_OFST    _UINT32_(0x29C)     /* (ADCHS_ADCMPCON2INV) Bit invert register Offset */
#define ADCHS_ADCFSTATCLR_REG_OFST     _UINT32_(0x2E4)     /* (ADCHS_ADCFSTATCLR) Bit clear register Offset */
#define ADCHS_ADCFSTATSET_REG_OFST     _UINT32_(0x2E8)     /* (ADCHS_ADCFSTATSET) Bit set register Offset */
#define ADCHS_ADCFSTATINV_REG_OFST     _UINT32_(0x2EC)     /* (ADCHS_ADCFSTATINV) Bit invert register Offset */
#define ADCHS_ADCFIFOCLR_REG_OFST      _UINT32_(0x2F4)     /* (ADCHS_ADCFIFOCLR) Bit clear register Offset */
#define ADCHS_ADCFIFOSET_REG_OFST      _UINT32_(0x2F8)     /* (ADCHS_ADCFIFOSET) Bit set register Offset */
#define ADCHS_ADCFIFOINV_REG_OFST      _UINT32_(0x2FC)     /* (ADCHS_ADCFIFOINV) Bit invert register Offset */
#define ADCHS_ADCBASE_REG_OFST         _UINT32_(0x300)     /* (ADCHS_ADCBASE)  Offset */
#define ADCHS_ADCBASECLR_REG_OFST      _UINT32_(0x304)     /* (ADCHS_ADCBASECLR) Bit clear register Offset */
#define ADCHS_ADCBASESET_REG_OFST      _UINT32_(0x308)     /* (ADCHS_ADCBASESET) Bit set register Offset */
#define ADCHS_ADCBASEINV_REG_OFST      _UINT32_(0x30C)     /* (ADCHS_ADCBASEINV) Bit invert register Offset */
#define ADCHS_ADCDMASTAT_REG_OFST      _UINT32_(0x310)     /* (ADCHS_ADCDMASTAT)  Offset */
#define ADCHS_ADCDMASTATCLR_REG_OFST   _UINT32_(0x314)     /* (ADCHS_ADCDMASTATCLR) Bit clear register Offset */
#define ADCHS_ADCDMASTATSET_REG_OFST   _UINT32_(0x318)     /* (ADCHS_ADCDMASTATSET) Bit set register Offset */
#define ADCHS_ADCDMASTATINV_REG_OFST   _UINT32_(0x31C)     /* (ADCHS_ADCDMASTATINV) Bit invert register Offset */
#define ADCHS_ADCCNTB_REG_OFST         _UINT32_(0x320)     /* (ADCHS_ADCCNTB)  Offset */
#define ADCHS_ADCCNTBCLR_REG_OFST      _UINT32_(0x324)     /* (ADCHS_ADCCNTBCLR) Bit clear register Offset */
#define ADCHS_ADCCNTBSET_REG_OFST      _UINT32_(0x328)     /* (ADCHS_ADCCNTBSET) Bit set register Offset */
#define ADCHS_ADCCNTBINV_REG_OFST      _UINT32_(0x32C)     /* (ADCHS_ADCCNTBINV) Bit invert register Offset */
#define ADCHS_ADCDMAB_REG_OFST         _UINT32_(0x330)     /* (ADCHS_ADCDMAB)  Offset */
#define ADCHS_ADCDMABCLR_REG_OFST      _UINT32_(0x334)     /* (ADCHS_ADCDMABCLR) Bit clear register Offset */
#define ADCHS_ADCDMABSET_REG_OFST      _UINT32_(0x338)     /* (ADCHS_ADCDMABSET) Bit set register Offset */
#define ADCHS_ADCDMABINV_REG_OFST      _UINT32_(0x33C)     /* (ADCHS_ADCDMABINV) Bit invert register Offset */
#define ADCHS_ADCTRGSNS_REG_OFST       _UINT32_(0x340)     /* (ADCHS_ADCTRGSNS)  Offset */
#define ADCHS_ADCTRGSNSCLR_REG_OFST    _UINT32_(0x344)     /* (ADCHS_ADCTRGSNSCLR) Bit clear register Offset */
#define ADCHS_ADCTRGSNSSET_REG_OFST    _UINT32_(0x348)     /* (ADCHS_ADCTRGSNSSET) Bit set register Offset */
#define ADCHS_ADCTRGSNSINV_REG_OFST    _UINT32_(0x34C)     /* (ADCHS_ADCTRGSNSINV) Bit invert register Offset */
#define ADCHS_ADC0TIMECLR_REG_OFST     _UINT32_(0x354)     /* (ADCHS_ADC0TIMECLR) Bit clear register Offset */
#define ADCHS_ADC0TIMESET_REG_OFST     _UINT32_(0x358)     /* (ADCHS_ADC0TIMESET) Bit set register Offset */
#define ADCHS_ADC0TIMEINV_REG_OFST     _UINT32_(0x35C)     /* (ADCHS_ADC0TIMEINV) Bit invert register Offset */
#define ADCHS_ADCEISTAT1CLR_REG_OFST   _UINT32_(0x3E4)     /* (ADCHS_ADCEISTAT1CLR) Bit clear register Offset */
#define ADCHS_ADCEISTAT1SET_REG_OFST   _UINT32_(0x3E8)     /* (ADCHS_ADCEISTAT1SET) Bit set register Offset */
#define ADCHS_ADCEISTAT1INV_REG_OFST   _UINT32_(0x3EC)     /* (ADCHS_ADCEISTAT1INV) Bit invert register Offset */
#define ADCHS_ADCANCON_REG_OFST        _UINT32_(0x400)     /* (ADCHS_ADCANCON)  Offset */
#define ADCHS_ADCANLCTLCLR_REG_OFST    _UINT32_(0x404)     /* (ADCHS_ADCANLCTLCLR) Bit clear register Offset */
#define ADCHS_ADCANLCTLSET_REG_OFST    _UINT32_(0x408)     /* (ADCHS_ADCANLCTLSET) Bit set register Offset */
#define ADCHS_ADCANLCTLINV_REG_OFST    _UINT32_(0x40C)     /* (ADCHS_ADCANLCTLINV) Bit invert register Offset */
#define ADCHS_ADC7CFG_REG_OFST         _UINT32_(0x670)     /* (ADCHS_ADC7CFG)  Offset */
#define ADCHS_ADCFGSHRCLR_REG_OFST     _UINT32_(0x674)     /* (ADCHS_ADCFGSHRCLR) Bit clear register Offset */
#define ADCHS_ADCFGSHRSET_REG_OFST     _UINT32_(0x678)     /* (ADCHS_ADCFGSHRSET) Bit set register Offset */
#define ADCHS_ADCFGSHRINV_REG_OFST     _UINT32_(0x67C)     /* (ADCHS_ADCFGSHRINV) Bit invert register Offset */
#define ADCHS_ADCSVCONCLR_REG_OFST     _UINT32_(0x684)     /* (ADCHS_ADCSVCONCLR) Bit clear register Offset */
#define ADCHS_ADCSVCONSET_REG_OFST     _UINT32_(0x688)     /* (ADCHS_ADCSVCONSET) Bit set register Offset */
#define ADCHS_ADCSVCONINV_REG_OFST     _UINT32_(0x68C)     /* (ADCHS_ADCSVCONINV) Bit invert register Offset */
#define ADCHS_ADCSYSCFG0_REG_OFST      _UINT32_(0x700)     /* (ADCHS_ADCSYSCFG0)  Offset */
#define ADCHS_ADCSYSCFG0CLR_REG_OFST   _UINT32_(0x704)     /* (ADCHS_ADCSYSCFG0CLR) Bit clear register Offset */
#define ADCHS_ADCSYSCFG0SET_REG_OFST   _UINT32_(0x708)     /* (ADCHS_ADCSYSCFG0SET) Bit set register Offset */
#define ADCHS_ADCSYSCFG0INV_REG_OFST   _UINT32_(0x70C)     /* (ADCHS_ADCSYSCFG0INV) Bit invert register Offset */
#define ADCHS_ADCDATA0_REG_OFST        _UINT32_(0xA00)     /* (ADCHS_ADCDATA0)  Offset */
#define ADCHS_ADCDATA1_REG_OFST        _UINT32_(0xA10)     /* (ADCHS_ADCDATA1)  Offset */
#define ADCHS_ADCDATA2_REG_OFST        _UINT32_(0xA20)     /* (ADCHS_ADCDATA2)  Offset */
#define ADCHS_ADCDATA3_REG_OFST        _UINT32_(0xA30)     /* (ADCHS_ADCDATA3)  Offset */
#define ADCHS_ADCDATA4_REG_OFST        _UINT32_(0xA40)     /* (ADCHS_ADCDATA4)  Offset */
#define ADCHS_ADCDATA5_REG_OFST        _UINT32_(0xA50)     /* (ADCHS_ADCDATA5)  Offset */
#define ADCHS_ADCDATA6_REG_OFST        _UINT32_(0xA60)     /* (ADCHS_ADCDATA6)  Offset */
#define ADCHS_ADCDATA7_REG_OFST        _UINT32_(0xA70)     /* (ADCHS_ADCDATA7)  Offset */
#define ADCHS_ADCDATA8_REG_OFST        _UINT32_(0xA80)     /* (ADCHS_ADCDATA8)  Offset */
#define ADCHS_ADCDATA9_REG_OFST        _UINT32_(0xA90)     /* (ADCHS_ADCDATA9)  Offset */
#define ADCHS_ADCDATA10_REG_OFST       _UINT32_(0xAA0)     /* (ADCHS_ADCDATA10)  Offset */
#define ADCHS_ADCDATA11_REG_OFST       _UINT32_(0xAB0)     /* (ADCHS_ADCDATA11)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief ADCHS register API structure */
typedef struct
{  /*  */
  __IO  uint32_t                       ADCHS_ADCCON1;      /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCON1CLR;   /**< Offset: 0x04 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCON1SET;   /**< Offset: 0x08 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCON1INV;   /**< Offset: 0x0C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCON2;      /**< Offset: 0x10 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCON2CLR;   /**< Offset: 0x14 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCON2SET;   /**< Offset: 0x18 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCON2INV;   /**< Offset: 0x1C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCON3;      /**< Offset: 0x20 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCON3CLR;   /**< Offset: 0x24 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCON3SET;   /**< Offset: 0x28 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCON3INV;   /**< Offset: 0x2C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved1[0x10];
  __IO  uint32_t                       ADCHS_ADCIMCON1;    /**< Offset: 0x40 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCIMOD1CLR;  /**< Offset: 0x44 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCIMOD1SET;  /**< Offset: 0x48 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCIMOD1INV;  /**< Offset: 0x4C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved2[0x30];
  __IO  uint32_t                       ADCHS_ADCGIRQEN1;   /**< Offset: 0x80 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCGIRQEN1CLR; /**< Offset: 0x84 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCGIRQEN1SET; /**< Offset: 0x88 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCGIRQEN1INV; /**< Offset: 0x8C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved3[0x10];
  __IO  uint32_t                       ADCHS_ADCCSS1;      /**< Offset: 0xA0 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCSS1CLR;   /**< Offset: 0xA4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCSS1SET;   /**< Offset: 0xA8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCSS1INV;   /**< Offset: 0xAC (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved4[0x10];
  __IO  uint32_t                       ADCHS_ADCDSTAT1;    /**< Offset: 0xC0 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCDSTAT1CLR; /**< Offset: 0xC4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCDSTAT1SET; /**< Offset: 0xC8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCDSTAT1INV; /**< Offset: 0xCC (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved5[0x10];
  __IO  uint32_t                       ADCHS_ADCCMPEN1;    /**< Offset: 0xE0 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCMPEN0CLR; /**< Offset: 0xE4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCMPEN0SET; /**< Offset: 0xE8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCMPEN0INV; /**< Offset: 0xEC (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCMP1;      /**< Offset: 0xF0 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCMP0CLR;   /**< Offset: 0xF4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCMP0SET;   /**< Offset: 0xF8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCMP0INV;   /**< Offset: 0xFC (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCMPEN2;    /**< Offset: 0x100 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCMPEN1CLR; /**< Offset: 0x104 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCMPEN1SET; /**< Offset: 0x108 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCMPEN1INV; /**< Offset: 0x10C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCMP2;      /**< Offset: 0x110 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADDCMP1CLR;   /**< Offset: 0x114 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADDCMP1SET;   /**< Offset: 0x118 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADDCMP1INV;   /**< Offset: 0x11C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved6[0x80];
  __IO  uint32_t                       ADCHS_ADCFLTR1;     /**< Offset: 0x1A0 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCFLTR0CLR;  /**< Offset: 0x1A4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCFLTR0SET;  /**< Offset: 0x1A8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCFLTR0INV;  /**< Offset: 0x1AC (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCFLTR2;     /**< Offset: 0x1B0 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCFLTR1CLR;  /**< Offset: 0x1B4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCFLTR1SET;  /**< Offset: 0x1B8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCFLTR1INV;  /**< Offset: 0x1BC (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved7[0x40];
  __IO  uint32_t                       ADCHS_ADCTRG1;      /**< Offset: 0x200 (R/W  32) ADC Trigger Source 1 Register */
  __IO  uint32_t                       ADCHS_ADCTRG1CLR;   /**< Offset: 0x204 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCTRG1SET;   /**< Offset: 0x208 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCTRG1INV;   /**< Offset: 0x20C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCTRG2;      /**< Offset: 0x210 (R/W  32) ADC Trigger Source 2 Register */
  __IO  uint32_t                       ADCHS_ADTRG2CLR;    /**< Offset: 0x214 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADTRG2SET;    /**< Offset: 0x218 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADTRG2INV;    /**< Offset: 0x21C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved8[0x04];
  __IO  uint32_t                       ADCHS_ADTRG3CLR;    /**< Offset: 0x224 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADTRG3SET;    /**< Offset: 0x228 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADTRG3INV;    /**< Offset: 0x22C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved9[0x50];
  __IO  uint32_t                       ADCHS_ADCCMPCON1;   /**< Offset: 0x280 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCMPCON1CLR; /**< Offset: 0x284 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCMPCON1SET; /**< Offset: 0x288 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCMPCON1INV; /**< Offset: 0x28C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCMPCON2;   /**< Offset: 0x290 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCMPCON2CLR; /**< Offset: 0x294 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCMPCON2SET; /**< Offset: 0x298 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCMPCON2INV; /**< Offset: 0x29C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved10[0x44];
  __IO  uint32_t                       ADCHS_ADCFSTATCLR;  /**< Offset: 0x2E4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCFSTATSET;  /**< Offset: 0x2E8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCFSTATINV;  /**< Offset: 0x2EC (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved11[0x04];
  __IO  uint32_t                       ADCHS_ADCFIFOCLR;   /**< Offset: 0x2F4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCFIFOSET;   /**< Offset: 0x2F8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCFIFOINV;   /**< Offset: 0x2FC (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCBASE;      /**< Offset: 0x300 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCBASECLR;   /**< Offset: 0x304 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCBASESET;   /**< Offset: 0x308 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCBASEINV;   /**< Offset: 0x30C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCDMASTAT;   /**< Offset: 0x310 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCDMASTATCLR; /**< Offset: 0x314 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCDMASTATSET; /**< Offset: 0x318 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCDMASTATINV; /**< Offset: 0x31C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCCNTB;      /**< Offset: 0x320 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCCNTBCLR;   /**< Offset: 0x324 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCCNTBSET;   /**< Offset: 0x328 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCCNTBINV;   /**< Offset: 0x32C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCDMAB;      /**< Offset: 0x330 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCDMABCLR;   /**< Offset: 0x334 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCDMABSET;   /**< Offset: 0x338 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCDMABINV;   /**< Offset: 0x33C (R/W  32) Bit invert register */
  __IO  uint32_t                       ADCHS_ADCTRGSNS;    /**< Offset: 0x340 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCTRGSNSCLR; /**< Offset: 0x344 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCTRGSNSSET; /**< Offset: 0x348 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCTRGSNSINV; /**< Offset: 0x34C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved12[0x04];
  __IO  uint32_t                       ADCHS_ADC0TIMECLR;  /**< Offset: 0x354 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADC0TIMESET;  /**< Offset: 0x358 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADC0TIMEINV;  /**< Offset: 0x35C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved13[0x84];
  __IO  uint32_t                       ADCHS_ADCEISTAT1CLR; /**< Offset: 0x3E4 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCEISTAT1SET; /**< Offset: 0x3E8 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCEISTAT1INV; /**< Offset: 0x3EC (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved14[0x10];
  __IO  uint32_t                       ADCHS_ADCANCON;     /**< Offset: 0x400 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCANLCTLCLR; /**< Offset: 0x404 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCANLCTLSET; /**< Offset: 0x408 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCANLCTLINV; /**< Offset: 0x40C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved15[0x260];
  __IO  uint32_t                       ADCHS_ADC7CFG;      /**< Offset: 0x670 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCFGSHRCLR;  /**< Offset: 0x674 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCFGSHRSET;  /**< Offset: 0x678 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCFGSHRINV;  /**< Offset: 0x67C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved16[0x04];
  __IO  uint32_t                       ADCHS_ADCSVCONCLR;  /**< Offset: 0x684 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCSVCONSET;  /**< Offset: 0x688 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCSVCONINV;  /**< Offset: 0x68C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved17[0x70];
  __IO  uint32_t                       ADCHS_ADCSYSCFG0;   /**< Offset: 0x700 (R/W  32)  */
  __IO  uint32_t                       ADCHS_ADCSYSCFG0CLR; /**< Offset: 0x704 (R/W  32) Bit clear register */
  __IO  uint32_t                       ADCHS_ADCSYSCFG0SET; /**< Offset: 0x708 (R/W  32) Bit set register */
  __IO  uint32_t                       ADCHS_ADCSYSCFG0INV; /**< Offset: 0x70C (R/W  32) Bit invert register */
  __I   uint8_t                        Reserved18[0x2F0];
  __IO  uint32_t                       ADCHS_ADCDATA0;     /**< Offset: 0xA00 (R/W  32)  */
  __I   uint8_t                        Reserved19[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA1;     /**< Offset: 0xA10 (R/W  32)  */
  __I   uint8_t                        Reserved20[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA2;     /**< Offset: 0xA20 (R/W  32)  */
  __I   uint8_t                        Reserved21[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA3;     /**< Offset: 0xA30 (R/W  32)  */
  __I   uint8_t                        Reserved22[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA4;     /**< Offset: 0xA40 (R/W  32)  */
  __I   uint8_t                        Reserved23[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA5;     /**< Offset: 0xA50 (R/W  32)  */
  __I   uint8_t                        Reserved24[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA6;     /**< Offset: 0xA60 (R/W  32)  */
  __I   uint8_t                        Reserved25[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA7;     /**< Offset: 0xA70 (R/W  32)  */
  __I   uint8_t                        Reserved26[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA8;     /**< Offset: 0xA80 (R/W  32)  */
  __I   uint8_t                        Reserved27[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA9;     /**< Offset: 0xA90 (R/W  32)  */
  __I   uint8_t                        Reserved28[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA10;    /**< Offset: 0xAA0 (R/W  32)  */
  __I   uint8_t                        Reserved29[0x0C];
  __IO  uint32_t                       ADCHS_ADCDATA11;    /**< Offset: 0xAB0 (R/W  32)  */
} adchs_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_ADCHS_COMPONENT_H_ */
