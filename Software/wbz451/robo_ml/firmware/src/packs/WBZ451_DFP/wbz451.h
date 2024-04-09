/*
 * Header file for WBZ451
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

/* File generated from device description version 2023-05-31T11:03:01Z */
#ifndef _WBZ451_H_
#define _WBZ451_H_

/* Header version uses Semantic Versioning 2.0.0 (https://semver.org/) */
#define HEADER_FORMAT_VERSION "2.1.0"

#define HEADER_FORMAT_VERSION_MAJOR (2)
#define HEADER_FORMAT_VERSION_MINOR (1)
#define HEADER_FORMAT_VERSION_PATCH (0)

/* WBZ451 definitions
  This file defines all structures and symbols for WBZ451:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - PIO definitions
*/

#ifdef __cplusplus
 extern "C" {
#endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  include <stdint.h>
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !defined(SKIP_INTEGER_LITERALS)
#  if defined(_UINT8_) || defined(_UINT16_) || defined(_UINT32_)
#    error "Integer constant value macros already defined elsewhere"
#  endif

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Macros that deal with sizes of integer constants for C/C++ */
#  define _UINT8_(x)   ((uint8_t)(x))    /* C code: 8-bits unsigned integer constant value */
#  define _UINT16_(x)  ((uint16_t)(x))   /* C code: 16-bits unsigned integer constant value */
#  define _UINT32_(x)  ((uint32_t)(x))   /* C code: 32-bits unsigned integer constant value */

#else /* Assembler */

#  define _UINT8_(x) x    /* Assembler: 8-bits unsigned integer constant value */
#  define _UINT16_(x) x   /* Assembler: 16-bits unsigned integer constant value */
#  define _UINT32_(x) x   /* Assembler: 32-bits unsigned integer constant value */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* SKIP_INTEGER_LITERALS */

/* ************************************************************************** */
/* CMSIS DEFINITIONS FOR WBZ451                                             */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* Interrupt Number Definition */
typedef enum IRQn
{
/******  CORTEX-M4 Processor Exceptions Numbers ******************************/
  Reset_IRQn                = -15, /* -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn       = -14, /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn            = -13, /* -13 Hard Fault, all classes of Fault    */
  MemoryManagement_IRQn     = -12, /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11, /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn           = -10, /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn               =  -5, /* -5  System Service Call via SVC instruction */
  DebugMonitor_IRQn         =  -4, /* -4  Debug Monitor                       */
  PendSV_IRQn               =  -2, /* -2  Pendable request for system service */
  SysTick_IRQn              =  -1, /* -1  System Tick Timer                   */

/******  WBZ451 specific Interrupt Numbers ***********************************/
  RTC_IRQn                  =   0, /* 0   Real-Time Counter (RTC)             */
  EIC_IRQn                  =   1, /* 1   External Interrupt Controller (EIC) */
  FREQM_IRQn                =   2, /* 2   Frequency Meter (FREQM)             */
  FLASH_CONTROL_IRQn        =   3, /* 3   flash controller (NVM)              */
  CHANGE_NOTICE_A_IRQn      =   4, /* 4   GPIO (GPIOA)                        */
  CHANGE_NOTICE_B_IRQn      =   5, /* 5   GPIO (GPIOB)                        */
  DMAC_0_3_IRQn             =   6, /* 6   Direct Memory Access Controller (DMAC) */
  DMAC_4_15_IRQn            =   7, /* 7   Direct Memory Access Controller (DMAC) */
  EVSYS_0_3_IRQn            =   8, /* 8   Event System Interface (EVSYS)      */
  EVSYS_4_11_IRQn           =   9, /* 9   Event System Interface (EVSYS)      */
  PAC_IRQn                  =  10, /* 10  Peripheral Access Controller (PAC)  */
  RAMECC_IRQn               =  11, /* 11  RAM ECC (RAMECC)                    */
  SERCOM0_IRQn              =  12, /* 12  Serial Communication Interface (SERCOM0) */
  SERCOM1_IRQn              =  13, /* 13  Serial Communication Interface (SERCOM1) */
  SERCOM2_IRQn              =  14, /* 14  Serial Communication Interface (SERCOM2) */
  SERCOM3_IRQn              =  15, /* 15  Serial Communication Interface (SERCOM3) */
  TCC0_IRQn                 =  16, /* 16  Timer Counter Control (TCC0)        */
  TCC1_IRQn                 =  17, /* 17  Timer Counter Control (TCC1)        */
  TCC2_IRQn                 =  18, /* 18  Timer Counter Control (TCC2)        */
  TC0_IRQn                  =  19, /* 19  Basic Timer Counter (TC0)           */
  TC1_IRQn                  =  20, /* 20  Basic Timer Counter (TC1)           */
  TC2_IRQn                  =  21, /* 21  Basic Timer Counter (TC2)           */
  TC3_IRQn                  =  22, /* 22  Basic Timer Counter (TC3)           */
  ADCHS_IRQn                =  23, /* 23  12-bit Analog to Digital Converter (ADCHS) */
  AC_IRQn                   =  24, /* 24  Analog Comparators (AC)             */
  AES_IRQn                  =  25, /* 25  Advanced Encryption Standard (AES)  */
  TRNG_IRQn                 =  26, /* 26  True Random Generator (TRNG)        */
  ICM_IRQn                  =  27, /* 27  Integrity Check Monitor (ICM)       */
  PUKCC_IRQn                =  28, /* 28  PUblic-Key Cryptography Controller (PUKCC) */
  QSPI_IRQn                 =  29, /* 29  Quad SPI interface (QSPI)           */
  ZB_INT0_IRQn              =  30, /* 30  ZIGBEE Radio Registers (ZIGBEE)     */
  BT_INT0_IRQn              =  31, /* 31  BLE (BLE)                           */
  BT_INT1_IRQn              =  32, /* 32  BLE (BLE)                           */
  ARBITER_IRQn              =  33, /* 33  Radio Arbiter (ARB)                 */
  ADC_FAULT_IRQn            =  34, /* 34  12-bit Analog to Digital Converter (ADCHS) */
  ADC_EOS_IRQn              =  35, /* 35  12-bit Analog to Digital Converter (ADCHS) */
  ADC_BGVR_RDY_IRQn         =  36, /* 36  12-bit Analog to Digital Converter (ADCHS) */
  CLKI_WAKEUP_NMI_IRQn      =  37, /* 37  BLE (BLE)                           */
  BT_LC_IRQn                =  38, /* 38  BLE (BLE)                           */
  BT_RC_IRQn                =  39, /* 39  BLE (BLE)                           */

  PERIPH_MAX_IRQn           =  39  /* Max peripheral ID */
} IRQn_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct _DeviceVectors
{
  /* Stack pointer */
  void* pvStack;
  /* CORTEX-M4 handlers */
  void* pfnReset_Handler;                        /* -15 Reset Vector, invoked on Power up and warm reset */
  void* pfnNonMaskableInt_Handler;               /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  void* pfnHardFault_Handler;                    /* -13 Hard Fault, all classes of Fault */
  void* pfnMemoryManagement_Handler;             /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  void* pfnBusFault_Handler;                     /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  void* pfnUsageFault_Handler;                   /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  void* pvReservedC9;
  void* pvReservedC8;
  void* pvReservedC7;
  void* pvReservedC6;
  void* pfnSVCall_Handler;                       /*  -5 System Service Call via SVC instruction */
  void* pfnDebugMonitor_Handler;                 /*  -4 Debug Monitor */
  void* pvReservedC3;
  void* pfnPendSV_Handler;                       /*  -2 Pendable request for system service */
  void* pfnSysTick_Handler;                      /*  -1 System Tick Timer */

  /* Peripheral handlers */
  void* pfnRTC_Handler;                          /*   0 Real-Time Counter (RTC) */
  void* pfnEIC_Handler;                          /*   1 External Interrupt Controller (EIC) */
  void* pfnFREQM_Handler;                        /*   2 Frequency Meter (FREQM) */
  void* pfnFLASH_CONTROL_Handler;                /*   3 flash controller (NVM) */
  void* pfnCHANGE_NOTICE_A_Handler;              /*   4 GPIO (GPIOA) */
  void* pfnCHANGE_NOTICE_B_Handler;              /*   5 GPIO (GPIOB) */
  void* pfnDMAC_0_3_Handler;                     /*   6 Direct Memory Access Controller (DMAC) */
  void* pfnDMAC_4_15_Handler;                    /*   7 Direct Memory Access Controller (DMAC) */
  void* pfnEVSYS_0_3_Handler;                    /*   8 Event System Interface (EVSYS) */
  void* pfnEVSYS_4_11_Handler;                   /*   9 Event System Interface (EVSYS) */
  void* pfnPAC_Handler;                          /*  10 Peripheral Access Controller (PAC) */
  void* pfnRAMECC_Handler;                       /*  11 RAM ECC (RAMECC) */
  void* pfnSERCOM0_Handler;                      /*  12 Serial Communication Interface (SERCOM0) */
  void* pfnSERCOM1_Handler;                      /*  13 Serial Communication Interface (SERCOM1) */
  void* pfnSERCOM2_Handler;                      /*  14 Serial Communication Interface (SERCOM2) */
  void* pfnSERCOM3_Handler;                      /*  15 Serial Communication Interface (SERCOM3) */
  void* pfnTCC0_Handler;                         /*  16 Timer Counter Control (TCC0) */
  void* pfnTCC1_Handler;                         /*  17 Timer Counter Control (TCC1) */
  void* pfnTCC2_Handler;                         /*  18 Timer Counter Control (TCC2) */
  void* pfnTC0_Handler;                          /*  19 Basic Timer Counter (TC0) */
  void* pfnTC1_Handler;                          /*  20 Basic Timer Counter (TC1) */
  void* pfnTC2_Handler;                          /*  21 Basic Timer Counter (TC2) */
  void* pfnTC3_Handler;                          /*  22 Basic Timer Counter (TC3) */
  void* pfnADCHS_Handler;                        /*  23 12-bit Analog to Digital Converter (ADCHS) */
  void* pfnAC_Handler;                           /*  24 Analog Comparators (AC) */
  void* pfnAES_Handler;                          /*  25 Advanced Encryption Standard (AES) */
  void* pfnTRNG_Handler;                         /*  26 True Random Generator (TRNG) */
  void* pfnICM_Handler;                          /*  27 Integrity Check Monitor (ICM) */
  void* pfnPUKCC_Handler;                        /*  28 PUblic-Key Cryptography Controller (PUKCC) */
  void* pfnQSPI_Handler;                         /*  29 Quad SPI interface (QSPI) */
  void* pfnZB_INT0_Handler;                      /*  30 ZIGBEE Radio Registers (ZIGBEE) */
  void* pfnBT_INT0_Handler;                      /*  31 BLE (BLE) */
  void* pfnBT_INT1_Handler;                      /*  32 BLE (BLE) */
  void* pfnARBITER_Handler;                      /*  33 Radio Arbiter (ARB) */
  void* pfnADC_FAULT_Handler;                    /*  34 12-bit Analog to Digital Converter (ADCHS) */
  void* pfnADC_EOS_Handler;                      /*  35 12-bit Analog to Digital Converter (ADCHS) */
  void* pfnADC_BGVR_RDY_Handler;                 /*  36 12-bit Analog to Digital Converter (ADCHS) */
  void* pfnCLKI_WAKEUP_NMI_Handler;              /*  37 BLE (BLE) */
  void* pfnBT_LC_Handler;                        /*  38 BLE (BLE) */
  void* pfnBT_RC_Handler;                        /*  39 BLE (BLE) */
} DeviceVectors;

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if !defined DONT_USE_PREDEFINED_CORE_HANDLERS
/* CORTEX-M4 exception handlers */
void Reset_Handler                 ( void );
void NonMaskableInt_Handler        ( void );
void HardFault_Handler             ( void );
void MemoryManagement_Handler      ( void );
void BusFault_Handler              ( void );
void UsageFault_Handler            ( void );
void SVCall_Handler                ( void );
void DebugMonitor_Handler          ( void );
void PendSV_Handler                ( void );
void SysTick_Handler               ( void );
#endif /* DONT_USE_PREDEFINED_CORE_HANDLERS */

#if !defined DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS
/* Peripherals interrupt handlers */
void RTC_Handler                   ( void );
void EIC_Handler                   ( void );
void FREQM_Handler                 ( void );
void FLASH_CONTROL_Handler         ( void );
void CHANGE_NOTICE_A_Handler       ( void );
void CHANGE_NOTICE_B_Handler       ( void );
void DMAC_0_3_Handler              ( void );
void DMAC_4_15_Handler             ( void );
void EVSYS_0_3_Handler             ( void );
void EVSYS_4_11_Handler            ( void );
void PAC_Handler                   ( void );
void RAMECC_Handler                ( void );
void SERCOM0_Handler               ( void );
void SERCOM1_Handler               ( void );
void SERCOM2_Handler               ( void );
void SERCOM3_Handler               ( void );
void TCC0_Handler                  ( void );
void TCC1_Handler                  ( void );
void TCC2_Handler                  ( void );
void TC0_Handler                   ( void );
void TC1_Handler                   ( void );
void TC2_Handler                   ( void );
void TC3_Handler                   ( void );
void ADCHS_Handler                 ( void );
void AC_Handler                    ( void );
void AES_Handler                   ( void );
void TRNG_Handler                  ( void );
void ICM_Handler                   ( void );
void PUKCC_Handler                 ( void );
void QSPI_Handler                  ( void );
void ZB_INT0_Handler               ( void );
void BT_INT0_Handler               ( void );
void BT_INT1_Handler               ( void );
void ARBITER_Handler               ( void );
void ADC_FAULT_Handler             ( void );
void ADC_EOS_Handler               ( void );
void ADC_BGVR_RDY_Handler          ( void );
void CLKI_WAKEUP_NMI_Handler       ( void );
void BT_LC_Handler                 ( void );
void BT_RC_Handler                 ( void );
#endif /* DONT_USE_PREDEFINED_PERIPHERALS_HANDLERS */
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* Configuration of the CORTEX-M4 Processor and Core Peripherals */
#define __CM4_REV                     0x0001
#define __DEBUG_LVL                        3
#define __FPU_PRESENT                      1
#define __MPU_PRESENT                      1
#define __NVIC_PRIO_BITS                   3
#define __TRACE_LVL                        2
#define __VTOR_PRESENT                     1
#define __Vendor_SysTickConfig             0
#define __ARCH_ARM                         1 /* ARM architecture or not                                                   */

/* CMSIS includes */
#include "core_cm4.h"
#if defined USE_CMSIS_INIT
#include "system_bz45.h"
#endif /* USE_CMSIS_INIT */

/* ************************************************************************** */
/*   SOFTWARE PERIPHERAL API DEFINITION FOR WBZ451                            */
/* ************************************************************************** */
#include "component/ac.h"
#include "component/adchs.h"
#include "component/aes.h"
#include "component/arb.h"
#include "component/ble.h"
#include "component/btzbsys.h"
#include "component/ccl.h"
#include "component/cfg.h"
#include "component/cmcc.h"
#include "component/cru.h"
#include "component/dmac.h"
#include "component/dmt.h"
#include "component/dscon.h"
#include "component/dsu.h"
#include "component/eic.h"
#include "component/evsys.h"
#include "component/freqm.h"
#include "component/fuses.h"
#include "component/gpio.h"
#include "component/hmatrixb.h"
#include "component/icm.h"
#include "component/nvm.h"
#include "component/pac.h"
#include "component/pche.h"
#include "component/pfw.h"
#include "component/pmu.h"
#include "component/pps.h"
#include "component/pukcc.h"
#include "component/qspi.h"
#include "component/ramecc.h"
#include "component/rcon.h"
#include "component/rtc.h"
#include "component/sercom.h"
#include "component/tc.h"
#include "component/tcc.h"
#include "component/trng.h"
#include "component/wdt.h"
#include "component/zigbee.h"

/* ************************************************************************** */
/*   INSTANCE DEFINITIONS FOR WBZ451 */
/* ************************************************************************** */
#include "instance/ac.h"
#include "instance/adchs.h"
#include "instance/aes.h"
#include "instance/arb.h"
#include "instance/ble.h"
#include "instance/btzbsys.h"
#include "instance/ccl.h"
#include "instance/cfg.h"
#include "instance/cmcc.h"
#include "instance/cru.h"
#include "instance/dmac.h"
#include "instance/dmt.h"
#include "instance/dscon.h"
#include "instance/dsu.h"
#include "instance/eic.h"
#include "instance/evsys.h"
#include "instance/freqm.h"
#include "instance/fuses.h"
#include "instance/gpioa.h"
#include "instance/gpiob.h"
#include "instance/hmatrix.h"
#include "instance/icm.h"
#include "instance/nvm.h"
#include "instance/pac.h"
#include "instance/pche.h"
#include "instance/pfw.h"
#include "instance/pmu.h"
#include "instance/pps.h"
#include "instance/qspi.h"
#include "instance/ramecc.h"
#include "instance/rcon.h"
#include "instance/rtc.h"
#include "instance/sercom0.h"
#include "instance/sercom1.h"
#include "instance/sercom2.h"
#include "instance/sercom3.h"
#include "instance/tc0.h"
#include "instance/tc1.h"
#include "instance/tc2.h"
#include "instance/tc3.h"
#include "instance/tcc0.h"
#include "instance/tcc1.h"
#include "instance/tcc2.h"
#include "instance/trng.h"
#include "instance/wdt.h"
#include "instance/zigbee.h"

/* ************************************************************************** */
/*  PERIPHERAL ID DEFINITIONS FOR WBZ451                                      */
/* ************************************************************************** */
#define ID_PAC           (  0) /* Peripheral Access Controller (PAC) */
#define ID_FREQM         (  1) /* Frequency Meter (FREQM) */
#define ID_EIC           (  2) /* External Interrupt Controller (EIC) */
#define ID_SERCOM0       (  3) /* Serial Communication Interface (SERCOM0) */
#define ID_SERCOM1       (  4) /* Serial Communication Interface (SERCOM1) */
#define ID_TC0           (  5) /* Basic Timer Counter (TC0) */
#define ID_TC1           (  6) /* Basic Timer Counter (TC1) */
#define ID_TC2           (  7) /* Basic Timer Counter (TC2) */
#define ID_TC3           (  8) /* Basic Timer Counter (TC3) */
#define ID_TCC0          (  9) /* Timer Counter Control (TCC0) */
#define ID_TCC1          ( 10) /* Timer Counter Control (TCC1) */
#define ID_TCC2          ( 11) /* Timer Counter Control (TCC2) */
#define ID_DSU           ( 32) /* Device Service Unit (DSU) */
#define ID_CMCC          ( 33) /* Cortex M Cache Controller (CMCC) */
#define ID_DMAC          ( 34) /* Direct Memory Access Controller (DMAC) */
#define ID_EVSYS         ( 35) /* Event System Interface (EVSYS) */
#define ID_RAMECC        ( 36) /* RAM ECC (RAMECC) */
#define ID_QSPI          ( 64) /* Quad SPI interface (QSPI) */
#define ID_AES           ( 65) /* Advanced Encryption Standard (AES) */
#define ID_SERCOM2       ( 67) /* Serial Communication Interface (SERCOM2) */
#define ID_SERCOM3       ( 68) /* Serial Communication Interface (SERCOM3) */
#define ID_CCL           ( 70) /* Configurable Custom Logic (CCL) */
#define ID_AC            ( 71) /* Analog Comparators (AC) */
#define ID_HMATRIX       ( 73) /* HSB Matrix (HMATRIX) */
#define ID_TRNG          ( 74) /* True Random Generator (TRNG) */
#define ID_ICM           ( 75) /* Integrity Check Monitor (ICM) */
#define ID_PUKCC         ( 76) /* PUblic-Key Cryptography Controller (PUKCC) */
#define ID_RTC           ( 78) /* Real-Time Counter (RTC) */
#define ID_DSCON         ( 79) /*  (DSCON) */

#define ID_PERIPH_MAX    ( 79) /* Number of peripheral IDs */

/* ************************************************************************** */
/*   REGISTER STRUCTURE ADDRESS DEFINITIONS FOR WBZ451                        */
/* ************************************************************************** */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#define AC_REGS                          ((ac_registers_t*)0x42001c00)                 /* AC Registers Address         */
#define ADCHS_REGS                       ((adchs_registers_t*)0x44001400)              /* ADCHS Registers Address      */
#define AES_REGS                         ((aes_registers_t*)0x42000400)                /* AES Registers Address        */
#define BLE_REGS                         ((ble_registers_t*)0x41012000)                /* BLE Registers Address        */
#define BTZBSYS_REGS                     ((btzbsys_registers_t*)0x41014000)            /* BTZBSYS Registers Address    */
#define CCL_REGS                         ((ccl_registers_t*)0x42001800)                /* CCL Registers Address        */
#define CFG_REGS                         ((cfg_registers_t*)0x44000000)                /* CFG Registers Address        */
#define CMCC_REGS                        ((cmcc_registers_t*)0x41002000)               /* CMCC Registers Address       */
#define CRU_REGS                         ((cru_registers_t*)0x44000a00)                /* CRU Registers Address        */
#define RCON_REGS                        ((rcon_registers_t*)0x44000a00)               /* RCON Registers Address       */
#define DMAC_REGS                        ((dmac_registers_t*)0x41004000)               /* DMAC Registers Address       */
#define DMT_REGS                         ((dmt_registers_t*)0x44000e00)                /* DMT Registers Address        */
#define DSCON_REGS                       ((dscon_registers_t*)0x42011000)              /* DSCON Registers Address      */
#define DSU_REGS                         ((dsu_registers_t*)0x41000000)                /* DSU Registers Address        */
#define EIC_REGS                         ((eic_registers_t*)0x40000800)                /* EIC Registers Address        */
#define EVSYS_REGS                       ((evsys_registers_t*)0x41006000)              /* EVSYS Registers Address      */
#define NVM_REGS                         ((nvm_registers_t*)0x44000600)                /* NVM Registers Address        */
#define FREQM_REGS                       ((freqm_registers_t*)0x40000400)              /* FREQM Registers Address      */
#define USER_FUSES_REGS                  ((fuses_user_fuses_registers_t*)0x00045e80)   /* FUSES Registers Address      */
#define GPIOA_REGS                       ((gpio_registers_t*)0x44002200)               /* GPIOA Registers Address      */
#define GPIOB_REGS                       ((gpio_registers_t*)0x44002300)               /* GPIOB Registers Address      */
#define HMATRIX_REGS                     ((hmatrixb_registers_t*)0x42002400)           /* HMATRIX Registers Address    */
#define ICM_REGS                         ((icm_registers_t*)0x42002c00)                /* ICM Registers Address        */
#define PAC_REGS                         ((pac_registers_t*)0x40000000)                /* PAC Registers Address        */
#define PCHE_REGS                        ((pche_registers_t*)0x44012400)               /* PCHE Registers Address       */
#define PFW_REGS                         ((pfw_registers_t*)0x44000800)                /* PFW Registers Address        */
#define PMU_REGS                         ((pmu_registers_t*)0x44013e00)                /* PMU Registers Address        */
#define PPS_REGS                         ((pps_registers_t*)0x44001000)                /* PPS Registers Address        */
#define QSPI_REGS                        ((qspi_registers_t*)0x42000000)               /* QSPI Registers Address       */
#define RAMECC_REGS                      ((ramecc_registers_t*)0x41008000)             /* RAMECC Registers Address     */
#define RTC_REGS                         ((rtc_registers_t*)0x42010000)                /* RTC Registers Address        */
#define SERCOM0_REGS                     ((sercom_registers_t*)0x40000c00)             /* SERCOM0 Registers Address    */
#define SERCOM1_REGS                     ((sercom_registers_t*)0x40001000)             /* SERCOM1 Registers Address    */
#define SERCOM2_REGS                     ((sercom_registers_t*)0x42000c00)             /* SERCOM2 Registers Address    */
#define SERCOM3_REGS                     ((sercom_registers_t*)0x42001000)             /* SERCOM3 Registers Address    */
#define TC0_REGS                         ((tc_registers_t*)0x40001400)                 /* TC0 Registers Address        */
#define TC1_REGS                         ((tc_registers_t*)0x40001800)                 /* TC1 Registers Address        */
#define TC2_REGS                         ((tc_registers_t*)0x40001c00)                 /* TC2 Registers Address        */
#define TC3_REGS                         ((tc_registers_t*)0x40002000)                 /* TC3 Registers Address        */
#define TCC0_REGS                        ((tcc_registers_t*)0x40002400)                /* TCC0 Registers Address       */
#define TCC1_REGS                        ((tcc_registers_t*)0x40002800)                /* TCC1 Registers Address       */
#define TCC2_REGS                        ((tcc_registers_t*)0x40002c00)                /* TCC2 Registers Address       */
#define TRNG_REGS                        ((trng_registers_t*)0x42002800)               /* TRNG Registers Address       */
#define WDT_REGS                         ((wdt_registers_t*)0x44000500)                /* WDT Registers Address        */
#define ZIGBEE_REGS                      ((zigbee_registers_t*)0x41010000)             /* ZIGBEE Registers Address     */
#define ARB_REGS                         ((arb_registers_t*)0x41011000)                /* ARB Registers Address        */
#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR WBZ451                                      */
/* ************************************************************************** */
#define AC_BASE_ADDRESS                  _UINT32_(0x42001c00)                          /* AC Base Address */
#define ADCHS_BASE_ADDRESS               _UINT32_(0x44001400)                          /* ADCHS Base Address */
#define AES_BASE_ADDRESS                 _UINT32_(0x42000400)                          /* AES Base Address */
#define BLE_BASE_ADDRESS                 _UINT32_(0x41012000)                          /* BLE Base Address */
#define BTZBSYS_BASE_ADDRESS             _UINT32_(0x41014000)                          /* BTZBSYS Base Address */
#define CCL_BASE_ADDRESS                 _UINT32_(0x42001800)                          /* CCL Base Address */
#define CFG_BASE_ADDRESS                 _UINT32_(0x44000000)                          /* CFG Base Address */
#define CMCC_BASE_ADDRESS                _UINT32_(0x41002000)                          /* CMCC Base Address */
#define CRU_BASE_ADDRESS                 _UINT32_(0x44000a00)                          /* CRU Base Address */
#define RCON_BASE_ADDRESS                _UINT32_(0x44000a00)                          /* RCON Base Address */
#define DMAC_BASE_ADDRESS                _UINT32_(0x41004000)                          /* DMAC Base Address */
#define DMT_BASE_ADDRESS                 _UINT32_(0x44000e00)                          /* DMT Base Address */
#define DSCON_BASE_ADDRESS               _UINT32_(0x42011000)                          /* DSCON Base Address */
#define DSU_BASE_ADDRESS                 _UINT32_(0x41000000)                          /* DSU Base Address */
#define EIC_BASE_ADDRESS                 _UINT32_(0x40000800)                          /* EIC Base Address */
#define EVSYS_BASE_ADDRESS               _UINT32_(0x41006000)                          /* EVSYS Base Address */
#define NVM_BASE_ADDRESS                 _UINT32_(0x44000600)                          /* NVM Base Address */
#define FREQM_BASE_ADDRESS               _UINT32_(0x40000400)                          /* FREQM Base Address */
#define USER_FUSES_BASE_ADDRESS          _UINT32_(0x00045e80)                          /* FUSES Base Address */
#define GPIOA_BASE_ADDRESS               _UINT32_(0x44002200)                          /* GPIOA Base Address */
#define GPIOB_BASE_ADDRESS               _UINT32_(0x44002300)                          /* GPIOB Base Address */
#define HMATRIX_BASE_ADDRESS             _UINT32_(0x42002400)                          /* HMATRIX Base Address */
#define ICM_BASE_ADDRESS                 _UINT32_(0x42002c00)                          /* ICM Base Address */
#define PAC_BASE_ADDRESS                 _UINT32_(0x40000000)                          /* PAC Base Address */
#define PCHE_BASE_ADDRESS                _UINT32_(0x44012400)                          /* PCHE Base Address */
#define PFW_BASE_ADDRESS                 _UINT32_(0x44000800)                          /* PFW Base Address */
#define PMU_BASE_ADDRESS                 _UINT32_(0x44013e00)                          /* PMU Base Address */
#define PPS_BASE_ADDRESS                 _UINT32_(0x44001000)                          /* PPS Base Address */
#define QSPI_BASE_ADDRESS                _UINT32_(0x42000000)                          /* QSPI Base Address */
#define RAMECC_BASE_ADDRESS              _UINT32_(0x41008000)                          /* RAMECC Base Address */
#define RTC_BASE_ADDRESS                 _UINT32_(0x42010000)                          /* RTC Base Address */
#define SERCOM0_BASE_ADDRESS             _UINT32_(0x40000c00)                          /* SERCOM0 Base Address */
#define SERCOM1_BASE_ADDRESS             _UINT32_(0x40001000)                          /* SERCOM1 Base Address */
#define SERCOM2_BASE_ADDRESS             _UINT32_(0x42000c00)                          /* SERCOM2 Base Address */
#define SERCOM3_BASE_ADDRESS             _UINT32_(0x42001000)                          /* SERCOM3 Base Address */
#define TC0_BASE_ADDRESS                 _UINT32_(0x40001400)                          /* TC0 Base Address */
#define TC1_BASE_ADDRESS                 _UINT32_(0x40001800)                          /* TC1 Base Address */
#define TC2_BASE_ADDRESS                 _UINT32_(0x40001c00)                          /* TC2 Base Address */
#define TC3_BASE_ADDRESS                 _UINT32_(0x40002000)                          /* TC3 Base Address */
#define TCC0_BASE_ADDRESS                _UINT32_(0x40002400)                          /* TCC0 Base Address */
#define TCC1_BASE_ADDRESS                _UINT32_(0x40002800)                          /* TCC1 Base Address */
#define TCC2_BASE_ADDRESS                _UINT32_(0x40002c00)                          /* TCC2 Base Address */
#define TRNG_BASE_ADDRESS                _UINT32_(0x42002800)                          /* TRNG Base Address */
#define WDT_BASE_ADDRESS                 _UINT32_(0x44000500)                          /* WDT Base Address */
#define ZIGBEE_BASE_ADDRESS              _UINT32_(0x41010000)                          /* ZIGBEE Base Address */
#define ARB_BASE_ADDRESS                 _UINT32_(0x41011000)                          /* ARB Base Address */

/* ************************************************************************** */
/*   PIO DEFINITIONS FOR WBZ451                                               */
/* ************************************************************************** */
#include "pio/wbz451.h"

/* ************************************************************************** */
/*   MEMORY MAPPING DEFINITIONS FOR WBZ451                                    */
/* ************************************************************************** */
#define CMCC_SIZE                      _UINT32_(0x01000000)    /* 16384kB Memory segment type: io */
#define CMCC_DATARAM_SIZE              _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define CMCC_TAGRAM_SIZE               _UINT32_(0x00000400)    /*    1kB Memory segment type: io */
#define CMCC_VALIDRAM_SIZE             _UINT32_(0x00000040)    /*    0kB Memory segment type: io */
#define HSRAM_SIZE                     _UINT32_(0x00020000)    /*  128kB Memory segment type: ram */
#define HSRAM_ETB_SIZE                 _UINT32_(0x00008000)    /*   32kB Memory segment type: ram */
#define HSRAM_RET1_SIZE                _UINT32_(0x00008000)    /*   32kB Memory segment type: ram */
#define PBA_SIZE                       _UINT32_(0x01000000)    /* 16384kB Memory segment type: io */
#define PBB_SIZE                       _UINT32_(0x01000000)    /* 16384kB Memory segment type: io */
#define PBC_SIZE                       _UINT32_(0x01000000)    /* 16384kB Memory segment type: io */
#define PB_PIC_SIZE                    _UINT32_(0x00020000)    /*  128kB Memory segment type: io */
#define BKUPRAM_SIZE                   _UINT32_(0x00002000)    /*    8kB Memory segment type: ram */
#define FLASH_SIZE                     _UINT32_(0x00100000)    /* 1024kB Memory segment type: flash */
#define FLASH_PAGE_SIZE                _UINT32_(      4096)
#define FLASH_NB_OF_PAGES              _UINT32_(       256)

#define PPB_SIZE                       _UINT32_(0x00100000)    /* 1024kB Memory segment type: io */
#define QSPI_SIZE                      _UINT32_(0x01000000)    /* 16384kB Memory segment type: other */
#define SCS_SIZE                       _UINT32_(0x00001000)    /*    4kB Memory segment type: io */
#define BOOT_FLASH_SIZE                _UINT32_(0x00005e00)    /*   23kB Memory segment type: flash */

#define CMCC_ADDR                      _UINT32_(0x03000000)    /* CMCC base address (type: io)*/
#define CMCC_DATARAM_ADDR              _UINT32_(0x03000000)    /* CMCC_DATARAM base address (type: io)*/
#define CMCC_TAGRAM_ADDR               _UINT32_(0x03001000)    /* CMCC_TAGRAM base address (type: io)*/
#define CMCC_VALIDRAM_ADDR             _UINT32_(0x03002000)    /* CMCC_VALIDRAM base address (type: io)*/
#define HSRAM_ADDR                     _UINT32_(0x20000000)    /* HSRAM base address (type: ram)*/
#define HSRAM_ETB_ADDR                 _UINT32_(0x20000000)    /* HSRAM_ETB base address (type: ram)*/
#define HSRAM_RET1_ADDR                _UINT32_(0x20000000)    /* HSRAM_RET1 base address (type: ram)*/
#define PBA_ADDR                       _UINT32_(0x40000000)    /* PBA base address (type: io)*/
#define PBB_ADDR                       _UINT32_(0x41000000)    /* PBB base address (type: io)*/
#define PBC_ADDR                       _UINT32_(0x42000000)    /* PBC base address (type: io)*/
#define PB_PIC_ADDR                    _UINT32_(0x44000000)    /* PB_PIC base address (type: io)*/
#define BKUPRAM_ADDR                   _UINT32_(0x44014000)    /* BKUPRAM base address (type: ram)*/
#define FLASH_ADDR                     _UINT32_(0x01000000)    /* FLASH base address (type: flash)*/
#define PPB_ADDR                       _UINT32_(0xe0000000)    /* PPB base address (type: io)*/
#define QSPI_ADDR                      _UINT32_(0x04000000)    /* QSPI base address (type: other)*/
#define SCS_ADDR                       _UINT32_(0xe000e000)    /* SCS base address (type: io)*/
#define BOOT_FLASH_ADDR                _UINT32_(0x00000000)    /* BOOT_FLASH base address (type: flash)*/

/* ************************************************************************** */
/*   DEVICE SIGNATURES FOR WBZ451                                             */
/* ************************************************************************** */
#define CHIP_JTAGID                    _UINT32_(0X09B8F053)
#define CHIP_DSU_DID                   _UINT32_(0X00009B8F)

/* ************************************************************************** */
/*   ELECTRICAL DEFINITIONS FOR WBZ451                                        */
/* ************************************************************************** */

/* ************************************************************************** */
/* Event Generator IDs for Z451 */
/* ************************************************************************** */
#define EVENT_ID_GEN_RTC_PER_0                            1 /* ID for RTC event generator PER_0 */
#define EVENT_ID_GEN_RTC_PER_1                            2 /* ID for RTC event generator PER_1 */
#define EVENT_ID_GEN_RTC_PER_2                            3 /* ID for RTC event generator PER_2 */
#define EVENT_ID_GEN_RTC_PER_3                            4 /* ID for RTC event generator PER_3 */
#define EVENT_ID_GEN_RTC_PER_4                            5 /* ID for RTC event generator PER_4 */
#define EVENT_ID_GEN_RTC_PER_5                            6 /* ID for RTC event generator PER_5 */
#define EVENT_ID_GEN_RTC_PER_6                            7 /* ID for RTC event generator PER_6 */
#define EVENT_ID_GEN_RTC_PER_7                            8 /* ID for RTC event generator PER_7 */
#define EVENT_ID_GEN_RTC_CMP_0                            9 /* ID for RTC event generator CMP_0 */
#define EVENT_ID_GEN_RTC_CMP_1                           10 /* ID for RTC event generator CMP_1 */
#define EVENT_ID_GEN_RTC_CMP_2                           11 /* ID for RTC event generator CMP_2 */
#define EVENT_ID_GEN_RTC_CMP_3                           12 /* ID for RTC event generator CMP_3 */
#define EVENT_ID_GEN_RTC_TAMPER                          13 /* ID for RTC event generator TAMPER */
#define EVENT_ID_GEN_RTC_OVF                             14 /* ID for RTC event generator OVF */
#define EVENT_ID_GEN_EIC_EXTINT_0                        15 /* ID for EIC event generator EXTINT_0 */
#define EVENT_ID_GEN_EIC_EXTINT_1                        16 /* ID for EIC event generator EXTINT_1 */
#define EVENT_ID_GEN_EIC_EXTINT_2                        17 /* ID for EIC event generator EXTINT_2 */
#define EVENT_ID_GEN_EIC_EXTINT_3                        18 /* ID for EIC event generator EXTINT_3 */
#define EVENT_ID_GEN_DMAC_CH_0                           19 /* ID for DMAC event generator CH_0 */
#define EVENT_ID_GEN_DMAC_CH_1                           20 /* ID for DMAC event generator CH_1 */
#define EVENT_ID_GEN_DMAC_CH_2                           21 /* ID for DMAC event generator CH_2 */
#define EVENT_ID_GEN_DMAC_CH_3                           22 /* ID for DMAC event generator CH_3 */
#define EVENT_ID_GEN_PAC_ACCERR                          23 /* ID for PAC event generator ACCERR */
#define EVENT_ID_GEN_TCC0_OVF                            24 /* ID for TCC0 event generator OVF */
#define EVENT_ID_GEN_TCC0_TRG                            25 /* ID for TCC0 event generator TRG */
#define EVENT_ID_GEN_TCC0_CNT                            26 /* ID for TCC0 event generator CNT */
#define EVENT_ID_GEN_TCC0_MC_0                           27 /* ID for TCC0 event generator MC_0 */
#define EVENT_ID_GEN_TCC0_MC_1                           28 /* ID for TCC0 event generator MC_1 */
#define EVENT_ID_GEN_TCC0_MC_2                           29 /* ID for TCC0 event generator MC_2 */
#define EVENT_ID_GEN_TCC0_MC_3                           30 /* ID for TCC0 event generator MC_3 */
#define EVENT_ID_GEN_TCC0_MC_4                           31 /* ID for TCC0 event generator MC_4 */
#define EVENT_ID_GEN_TCC0_MC_5                           32 /* ID for TCC0 event generator MC_5 */
#define EVENT_ID_GEN_TCC1_OVF                            33 /* ID for TCC1 event generator OVF */
#define EVENT_ID_GEN_TCC1_TRG                            34 /* ID for TCC1 event generator TRG */
#define EVENT_ID_GEN_TCC1_CNT                            35 /* ID for TCC1 event generator CNT */
#define EVENT_ID_GEN_TCC1_MCX_0                          36 /* ID for TCC1 event generator MCX_0 */
#define EVENT_ID_GEN_TCC1_MCX_1                          37 /* ID for TCC1 event generator MCX_1 */
#define EVENT_ID_GEN_TCC1_MCX_2                          38 /* ID for TCC1 event generator MCX_2 */
#define EVENT_ID_GEN_TCC1_MCX_3                          39 /* ID for TCC1 event generator MCX_3 */
#define EVENT_ID_GEN_TCC1_MCX_4                          40 /* ID for TCC1 event generator MCX_4 */
#define EVENT_ID_GEN_TCC1_MCX_5                          41 /* ID for TCC1 event generator MCX_5 */
#define EVENT_ID_GEN_TCC2_OVF                            42 /* ID for TCC2 event generator OVF */
#define EVENT_ID_GEN_TCC2_TRG                            43 /* ID for TCC2 event generator TRG */
#define EVENT_ID_GEN_TCC2_CNT                            44 /* ID for TCC2 event generator CNT */
#define EVENT_ID_GEN_TCC2_MCX_0                          45 /* ID for TCC2 event generator MCX_0 */
#define EVENT_ID_GEN_TCC2_MCX_1                          46 /* ID for TCC2 event generator MCX_1 */
#define EVENT_ID_GEN_TC0_OVF                             47 /* ID for TC0 event generator OVF */
#define EVENT_ID_GEN_TC0_MCX_0                           48 /* ID for TC0 event generator MCX_0 */
#define EVENT_ID_GEN_TC0_MCX_1                           49 /* ID for TC0 event generator MCX_1 */
#define EVENT_ID_GEN_TC1_OVF                             50 /* ID for TC1 event generator OVF */
#define EVENT_ID_GEN_TC1_MCX_0                           51 /* ID for TC1 event generator MCX_0 */
#define EVENT_ID_GEN_TC1_MCX_1                           52 /* ID for TC1 event generator MCX_1 */
#define EVENT_ID_GEN_TC2_OVF                             53 /* ID for TC2 event generator OVF */
#define EVENT_ID_GEN_TC2_MCX_0                           54 /* ID for TC2 event generator MCX_0 */
#define EVENT_ID_GEN_TC2_MCX_1                           55 /* ID for TC2 event generator MCX_1 */
#define EVENT_ID_GEN_TC3_OVF                             56 /* ID for TC3 event generator OVF */
#define EVENT_ID_GEN_TC3_MCX_0                           57 /* ID for TC3 event generator MCX_0 */
#define EVENT_ID_GEN_TC3_MCX_1                           58 /* ID for TC3 event generator MCX_1 */
#define EVENT_ID_GEN_ADC_RESRDY                          59 /* ID for ADCHS event generator ADC_RESRDY */
#define EVENT_ID_GEN_AC_COMP_0                           62 /* ID for AC event generator COMP_0 */
#define EVENT_ID_GEN_AC_COMP_1                           63 /* ID for AC event generator COMP_1 */
#define EVENT_ID_GEN_AC_WIN_0                            64 /* ID for AC event generator WIN_0 */
#define EVENT_ID_GEN_TRNG_READY                          65 /* ID for TRNG event generator READY */
#define EVENT_ID_GEN_CCL_LUTOUT_0                        66 /* ID for CCL event generator LUTOUT_0 */
#define EVENT_ID_GEN_CCL_LUTOUT_1                        67 /* ID for CCL event generator LUTOUT_1 */
#define EVENT_ID_GEN_ZB_TX_TS_ACT                        68 /* ID for ZBT event generator ZB_TX_TS_ACT */
#define EVENT_ID_GEN_ZB_RX_TS_ACT                        69 /* ID for ZBT event generator ZB_RX_TS_ACT */

/* ************************************************************************** */
/*  Event User IDs for Z451 */
/* ************************************************************************** */
#define EVENT_ID_USER_RTC_TAMPER                          0 /* ID for RTC event user TAMPER */
#define EVENT_ID_USER_DMAC_CH_0                           1 /* ID for DMAC event user CH_0 */
#define EVENT_ID_USER_DMAC_CH_1                           2 /* ID for DMAC event user CH_1 */
#define EVENT_ID_USER_DMAC_CH_2                           3 /* ID for DMAC event user CH_2 */
#define EVENT_ID_USER_DMAC_CH_3                           4 /* ID for DMAC event user CH_3 */
#define EVENT_ID_USER_DMAC_CH_4                           5 /* ID for DMAC event user CH_4 */
#define EVENT_ID_USER_DMAC_CH_5                           6 /* ID for DMAC event user CH_5 */
#define EVENT_ID_USER_DMAC_CH_6                           7 /* ID for DMAC event user CH_6 */
#define EVENT_ID_USER_DMAC_CH_7                           8 /* ID for DMAC event user CH_7 */
#define EVENT_ID_USER_CM4_TRACE_START                     9 /* ID for CM4 event user TRACE_START */
#define EVENT_ID_USER_CM4_TRACE_STOP                     10 /* ID for CM4 event user TRACE_STOP */
#define EVENT_ID_USER_CM4_TRACE_TRIG                     11 /* ID for CM4 event user TRACE_TRIG */
#define EVENT_ID_USER_TCC0_EV_0                          12 /* ID for TCC0 event user EV_0 */
#define EVENT_ID_USER_TCC0_EV_1                          13 /* ID for TCC0 event user EV_1 */
#define EVENT_ID_USER_TCC0_MC_0                          14 /* ID for TCC0 event user MC_0 */
#define EVENT_ID_USER_TCC0_MC_1                          15 /* ID for TCC0 event user MC_1 */
#define EVENT_ID_USER_TCC0_MC_2                          16 /* ID for TCC0 event user MC_2 */
#define EVENT_ID_USER_TCC0_MC_3                          17 /* ID for TCC0 event user MC_3 */
#define EVENT_ID_USER_TCC0_MC_4                          18 /* ID for TCC0 event user MC_4 */
#define EVENT_ID_USER_TCC0_MC_5                          19 /* ID for TCC0 event user MC_5 */
#define EVENT_ID_USER_TCC1_EV_0                          20 /* ID for TCC1 event user EV_0 */
#define EVENT_ID_USER_TCC1_EV_1                          21 /* ID for TCC1 event user EV_1 */
#define EVENT_ID_USER_TCC1_MC_0                          22 /* ID for TCC1 event user MC_0 */
#define EVENT_ID_USER_TCC1_MC_1                          23 /* ID for TCC1 event user MC_1 */
#define EVENT_ID_USER_TCC1_MC_2                          24 /* ID for TCC1 event user MC_2 */
#define EVENT_ID_USER_TCC1_MC_3                          25 /* ID for TCC1 event user MC_3 */
#define EVENT_ID_USER_TCC1_MC_4                          26 /* ID for TCC1 event user MC_4 */
#define EVENT_ID_USER_TCC1_MC_5                          27 /* ID for TCC1 event user MC_5 */
#define EVENT_ID_USER_TCC2_EV_0                          28 /* ID for TCC2 event user EV_0 */
#define EVENT_ID_USER_TCC2_EV_1                          29 /* ID for TCC2 event user EV_1 */
#define EVENT_ID_USER_TCC2_MC_0                          30 /* ID for TCC2 event user MC_0 */
#define EVENT_ID_USER_TCC2_MC_1                          31 /* ID for TCC2 event user MC_1 */
#define EVENT_ID_USER_TC0_EVU                            32 /* ID for TC0 event user EVU */
#define EVENT_ID_USER_TC1_EVU                            33 /* ID for TC1 event user EVU */
#define EVENT_ID_USER_TC2_EVU                            34 /* ID for TC2 event user EVU */
#define EVENT_ID_USER_TC3_EVU                            35 /* ID for TC3 event user EVU */
#define EVENT_ID_USER_ADC_TRIG_5                         36 /* ID for ADCHS event user ADC_TRIG_5 */
#define EVENT_ID_USER_ADC_TRIG_6                         37 /* ID for ADCHS event user ADC_TRIG_6 */
#define EVENT_ID_USER_ADC_TRIG_7                         38 /* ID for ADCHS event user ADC_TRIG_7 */
#define EVENT_ID_USER_ADC_TRIG_8                         39 /* ID for ADCHS event user ADC_TRIG_8 */
#define EVENT_ID_USER_ADC_TRIG_9                         40 /* ID for ADCHS event user ADC_TRIG_9 */
#define EVENT_ID_USER_ADC_TRIG_10                        41 /* ID for ADCHS event user ADC_TRIG_10 */
#define EVENT_ID_USER_ADC_TRIG_11                        42 /* ID for ADCHS event user ADC_TRIG_11 */
#define EVENT_ID_USER_ADC_TRIG_12                        43 /* ID for ADCHS event user ADC_TRIG_12 */
#define EVENT_ID_USER_ADC_TRIG_13                        44 /* ID for ADCHS event user ADC_TRIG_13 */
#define EVENT_ID_USER_ADC_TRIG_14                        45 /* ID for ADCHS event user ADC_TRIG_14 */
#define EVENT_ID_USER_ADC_TRIG_15                        46 /* ID for ADCHS event user ADC_TRIG_15 */
#define EVENT_ID_USER_ADC_TRIG_16                        47 /* ID for ADCHS event user ADC_TRIG_16 */
#define EVENT_ID_USER_AC_SOC_0                           48 /* ID for AC event user SOC_0 */
#define EVENT_ID_USER_AC_SOC_1                           49 /* ID for AC event user SOC_1 */
#define EVENT_ID_USER_CCL_LUTIN_0                        50 /* ID for CCL event user LUTIN_0 */
#define EVENT_ID_USER_CCL_LUTIN_1                        51 /* ID for CCL event user LUTIN_1 */

#ifdef __cplusplus
}
#endif

#endif /* _WBZ451_H_ */

