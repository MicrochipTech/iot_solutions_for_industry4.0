/*******************************************************************************
 System Interrupts File

  Company:
    Microchip Technology Inc.

  File Name:
    interrupt.c

  Summary:
    Interrupt vectors mapping

  Description:
    This file maps all the interrupt vectors to their corresponding
    implementations. If a particular module interrupt is used, then its ISR
    definition can be found in corresponding PLIB source file. If a module
    interrupt is not used, then its ISR implementation is mapped to dummy
    handler.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "device_vectors.h"
#include "interrupts.h"
#include "definitions.h"



// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

/* MISRA C-2012 Rule 8.6 deviated below. Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
extern uint32_t _stack;
extern const H3DeviceVectors exception_table;

extern void Dummy_Handler(void);

/* Brief default interrupt handler for unused IRQs.*/
void __attribute__((optimize("-O1"), long_call, noreturn, used))Dummy_Handler(void)
{
#if defined(__DEBUG) || defined(__DEBUG_D) && defined(__XC32)
    __builtin_software_breakpoint();
#endif
    while (true)
    {
    }
}

/* MISRAC 2012 deviation block start */
/* MISRA C-2012 Rule 8.6 deviated 36 times.  Deviation record ID -  H3_MISRAC_2012_R_8_6_DR_1 */
/* Device vectors list dummy definition*/
extern void RTC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void FREQM_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CHANGE_NOTICE_A_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CHANGE_NOTICE_B_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_0_3_Handler           ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void DMAC_4_15_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_0_3_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void EVSYS_4_11_Handler         ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PAC_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void RAMECC_Handler             ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM2_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void SERCOM3_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC0_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC1_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TCC2_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC1_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC2_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TC3_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADCHS_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AC_Handler                 ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void AES_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void TRNG_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ICM_Handler                ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void PUKCC_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void QSPI_Handler               ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ZB_INT0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void BT_INT0_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void BT_INT1_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ARBITER_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_FAULT_Handler          ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_EOS_Handler            ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void ADC_BGVR_RDY_Handler       ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void CLKI_WAKEUP_NMI_Handler    ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void BT_LC_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));
extern void BT_RC_Handler              ( void ) __attribute__((weak, alias("Dummy_Handler")));


/* MISRAC 2012 deviation block end */

/* Multiple handlers for vector */



__attribute__ ((section(".vectors"), used))
const H3DeviceVectors exception_table=
{
    /* Configure Initial Stack Pointer, using linker-generated symbols */
    .pvStack = &_stack,

    .pfnReset_Handler              = Reset_Handler,
    .pfnNonMaskableInt_Handler     = NonMaskableInt_Handler,
    .pfnHardFault_Handler          = HardFault_Handler,
    .pfnMemoryManagement_Handler   = MemoryManagement_Handler,
    .pfnBusFault_Handler           = BusFault_Handler,
    .pfnUsageFault_Handler         = UsageFault_Handler,
    .pfnSVCall_Handler             = vPortSVCHandler,
    .pfnDebugMonitor_Handler       = DebugMonitor_Handler,
    .pfnPendSV_Handler             = xPortPendSVHandler,
    .pfnSysTick_Handler            = xPortSysTickHandler,
    .pfnRTC_Handler                = RTC_Handler,
    .pfnEIC_Handler                = EIC_InterruptHandler,
    .pfnFREQM_Handler              = FREQM_Handler,
    .pfnFLASH_CONTROL_Handler      = NVM_InterruptHandler,
    .pfnCHANGE_NOTICE_A_Handler    = CHANGE_NOTICE_A_Handler,
    .pfnCHANGE_NOTICE_B_Handler    = CHANGE_NOTICE_B_Handler,
    .pfnDMAC_0_3_Handler           = DMAC_0_3_Handler,
    .pfnDMAC_4_15_Handler          = DMAC_4_15_Handler,
    .pfnEVSYS_0_3_Handler          = EVSYS_0_3_Handler,
    .pfnEVSYS_4_11_Handler         = EVSYS_4_11_Handler,
    .pfnPAC_Handler                = PAC_Handler,
    .pfnRAMECC_Handler             = RAMECC_Handler,
    .pfnSERCOM0_Handler            = SERCOM0_USART_InterruptHandler,
    .pfnSERCOM1_Handler            = SERCOM1_Handler,
    .pfnSERCOM2_Handler            = SERCOM2_Handler,
    .pfnSERCOM3_Handler            = SERCOM3_Handler,
    .pfnTCC0_Handler               = TCC0_Handler,
    .pfnTCC1_Handler               = TCC1_Handler,
    .pfnTCC2_Handler               = TCC2_Handler,
    .pfnTC0_Handler                = TC0_TimerInterruptHandler,
    .pfnTC1_Handler                = TC1_Handler,
    .pfnTC2_Handler                = TC2_Handler,
    .pfnTC3_Handler                = TC3_Handler,
    .pfnADCHS_Handler              = ADCHS_Handler,
    .pfnAC_Handler                 = AC_Handler,
    .pfnAES_Handler                = AES_Handler,
    .pfnTRNG_Handler               = TRNG_Handler,
    .pfnICM_Handler                = ICM_Handler,
    .pfnPUKCC_Handler              = PUKCC_Handler,
    .pfnQSPI_Handler               = QSPI_Handler,
    .pfnZB_INT0_Handler            = ZB_INT0_Handler,
    .pfnBT_INT0_Handler            = BT_INT0_Handler,
    .pfnBT_INT1_Handler            = BT_INT1_Handler,
    .pfnARBITER_Handler            = ARBITER_Handler,
    .pfnADC_FAULT_Handler          = ADC_FAULT_Handler,
    .pfnADC_EOS_Handler            = ADC_EOS_Handler,
    .pfnADC_BGVR_RDY_Handler       = ADC_BGVR_RDY_Handler,
    .pfnCLKI_WAKEUP_NMI_Handler    = CLKI_WAKEUP_NMI_Handler,
    .pfnBT_LC_Handler              = BT_LC_Handler,
    .pfnBT_RC_Handler              = BT_RC_Handler,


};

/*******************************************************************************
 End of File
*/
