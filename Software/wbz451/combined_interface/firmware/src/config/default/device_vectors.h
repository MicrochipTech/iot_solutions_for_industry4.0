/*******************************************************************************
 Cortex-M device vectors file

  Company:
    Microchip Technology Inc.

  File Name:
    device_vectors.h

  Summary:
    Harmony3 device handler structure for cortex-M devices

  Description:
    This file contains Harmony3 device handler structure for cortex-M devices
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

#ifndef DEVICE_VECTORS_H
#define DEVICE_VECTORS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************

/* Function pointer type for vector handlers */
typedef void (*pfn_handler_t)(void);

/* Structure defining device vector types */
typedef struct H3DeviceVectorsTag
{
  /* Stack pointer */
  uint32_t* pvStack;

  /* CORTEX-M4 handlers */ 
  pfn_handler_t pfnReset_Handler;                   /* -15 Reset Vector, invoked on Power up and warm reset */
  pfn_handler_t pfnNonMaskableInt_Handler;          /* -14 Non maskable Interrupt, cannot be stopped or preempted */
  pfn_handler_t pfnHardFault_Handler;               /* -13 Hard Fault, all classes of Fault */
  pfn_handler_t pfnMemoryManagement_Handler;        /* -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  pfn_handler_t pfnBusFault_Handler;                /* -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  pfn_handler_t pfnUsageFault_Handler;              /* -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  pfn_handler_t pfnReservedC9;
  pfn_handler_t pfnReservedC8;
  pfn_handler_t pfnReservedC7;
  pfn_handler_t pfnReservedC6;
  pfn_handler_t pfnSVCall_Handler;                  /* -5 System Service Call via SVC instruction */
  pfn_handler_t pfnDebugMonitor_Handler;            /* -4 Debug Monitor */
  pfn_handler_t pfnReservedC3;
  pfn_handler_t pfnPendSV_Handler;                  /* -2 Pendable request for system service */
  pfn_handler_t pfnSysTick_Handler;                 /* -1 System Tick Timer */

  /* Peripheral handlers */
  pfn_handler_t pfnRTC_Handler;                     /* 0 Real Time Counter */
  pfn_handler_t pfnEIC_Handler;                     /* 1 External Interrupt Controller */
  pfn_handler_t pfnFREQM_Handler;                   /* 2 Frequency Meter */
  pfn_handler_t pfnFLASH_CONTROL_Handler;           /* 3 Non-Volatile Memory */
  pfn_handler_t pfnCHANGE_NOTICE_A_Handler;         /* 4 PORT_A_INPUT_CHANGE_INTERRUPT */
  pfn_handler_t pfnCHANGE_NOTICE_B_Handler;         /* 5 PORT_B_INPUT_CHANGE_INTERRUPT */
  pfn_handler_t pfnDMAC_0_3_Handler;                /* 6 DMA Channel 0..3 */
  pfn_handler_t pfnDMAC_4_15_Handler;               /* 7 DMA Channel 4..X */
  pfn_handler_t pfnEVSYS_0_3_Handler;               /* 8 Event System Channel 0..3 */
  pfn_handler_t pfnEVSYS_4_11_Handler;              /* 9 Event System Channel 4..X */
  pfn_handler_t pfnPAC_Handler;                     /* 10 Peripheral Access Controller */
  pfn_handler_t pfnRAMECC_Handler;                  /* 11 RAM Error Correction Code */
  pfn_handler_t pfnSERCOM0_Handler;                 /* 12 Serial Communication Interface 0 */
  pfn_handler_t pfnSERCOM1_Handler;                 /* 13 Serial Communication Interface 1 */
  pfn_handler_t pfnSERCOM2_Handler;                 /* 14 Serial Communication Interface 2 */
  pfn_handler_t pfnSERCOM3_Handler;                 /* 15 Serial Communication Interface 3 */
  pfn_handler_t pfnTCC0_Handler;                    /* 16 Timer/Counter for Control Applications 0 */
  pfn_handler_t pfnTCC1_Handler;                    /* 17 Timer/Counter for Control Applications 1 */
  pfn_handler_t pfnTCC2_Handler;                    /* 18 Timer/Counter for Control Applications 2 */
  pfn_handler_t pfnTC0_Handler;                     /* 19 Timer/Counter 0 */
  pfn_handler_t pfnTC1_Handler;                     /* 20 Timer/Counter 1 */
  pfn_handler_t pfnTC2_Handler;                     /* 21 Timer/Counter 2 */
  pfn_handler_t pfnTC3_Handler;                     /* 22 Timer/Counter 3 */
  pfn_handler_t pfnADCHS_Handler;                   /* 23 Analog-to-Digital Converter */
  pfn_handler_t pfnAC_Handler;                      /* 24 Analog Comparators */
  pfn_handler_t pfnAES_Handler;                     /* 25 Advanced Encryption Standard */
  pfn_handler_t pfnTRNG_Handler;                    /* 26 True Random Generator */
  pfn_handler_t pfnICM_Handler;                     /* 27 Integrity Check Monitor */
  pfn_handler_t pfnPUKCC_Handler;                   /* 28 Public-Key Cryptography Controller */
  pfn_handler_t pfnQSPI_Handler;                    /* 29 Quad SPI interface */
  pfn_handler_t pfnZB_INT0_Handler;                 /* 30 ZIGBEE */
  pfn_handler_t pfnBT_INT0_Handler;                 /* 31 Bluetooth 0 */
  pfn_handler_t pfnBT_INT1_Handler;                 /* 32 Bluetooth 0 */
  pfn_handler_t pfnARBITER_Handler;                 /* 33 Radio Arbiter */
  pfn_handler_t pfnADC_FAULT_Handler;               /* 34 ADC Fault Interrupt */
  pfn_handler_t pfnADC_EOS_Handler;                 /* 35 ADC EOS Interrupt */
  pfn_handler_t pfnADC_BGVR_RDY_Handler;            /* 36 ADC BGVR Ready */
  pfn_handler_t pfnCLKI_WAKEUP_NMI_Handler;         /* 37 Bluetooth WAKEUP */
  pfn_handler_t pfnBT_LC_Handler;                   /* 38 Bluetooth LC */
  pfn_handler_t pfnBT_RC_Handler;                   /* 39 Bluetooth RC */
}H3DeviceVectors;

#endif //DEVICE_VECTORS_H
