/*******************************************************************************
  ZLL Utilities Source File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Util.c

  Summary:
    This file contains the ZLL Utilities.

  Description:
    This file contains the ZLL Utilities.
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


/***************************************************************************************************
* LOCAL INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Util/include/N_Util_Bindings.h"
#include "zllplatform/infrastructure/N_Util/include/N_Util.h"

/***************************************************************************************************
* EXTERNAL INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_ErrH/include/N_ErrH.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"


//#define __MICROCHIP_BITCLOUD__

#if (defined(__ICCAVR__) || defined(__ICCARM__))
#include <intrinsics.h>
#include <hal/cortexm4/pic32cx/include/halMacIsr.h>
#endif

#if defined(__MICROCHIP_BITCLOUD__) && defined(__ICCAVR__)
#include <atmega128rfa1.h>
#include <halIrq.h>
#define read_avr_fuse(n) /
   __AddrToZByteToSPMCR_LPM((void __flash*) \
                             (((n) == 0? 0x0000: ((n) == 1? 0x0003: 0x0002))), \
                             0x09)
#define HIGH_FUSE_MASK 0x06
extern void __bitcloud_start(void);
#define RESET_ADDR __bitcloud_start
#endif

#if defined(__MICROCHIP_BITCLOUD__) && defined(__ICCARM__)
#include "halRfCtrl.h"      // HAL_Delay
//#include "halInterrupt.h"
//#include "halReset.h"
#define BOOTLOADER_PC_OFFSET_ADDR 0x04
#endif

#if defined(__COVERITY__)
#  include <stdlib.h>
#endif

//#include <resetReason.h>

#if (defined(__MICROCHIP_BITCLOUD__) || defined(__GNUC__))
#include <systemenvironment/include/sysUtils.h> // for SYS_GetRandomNumber

#include <systemenvironment/include/sysStat.h> // Enable stack monitoring

#endif

/******************************************************************************
                    Prototypes section
******************************************************************************/
#if (defined(__ICCARM__) && (defined(ATSAMR21G18A) || defined(ATSAMR21E18A)|| defined(ATSAMR21E19A)))
static uint32_t System_Gclk_Get_Hz(void);
#endif // #if (defined(__ICCARM__) && (defined(ATSAMR21G18A) || defined(ATSAMR21E18A)|| defined(ATSAMR21E19A)))
/***************************************************************************************************
* LOCAL MACROS AND CONSTANTS
***************************************************************************************************/

#define COMPID "N_Util"
#if !defined N_UTIL_SYSTEMRESET_METHOD
#define N_UTIL_SYSTEMRESET_METHOD N_Util_RebootMethod_Reset
#endif

/***************************************************************************************************
* LOCAL VARIABLES
***************************************************************************************************/

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

uint8_t N_Util_HighestNetworkUpdateId(uint8_t id1, uint8_t id2)
{
    if (id1 > id2)
    {
        if ( (uint8_t) (id1 - id2) > 200u )
        {
            return id2;
        }
        else
        {
            return id1;
        }
    }
    else
    {
        if ( (uint8_t) (id2 - id1) > 200u )
        {
            return id1;
        }
        else
        {
            return id2;
        }
    }
}

#if defined (__WIN32__)

void N_Util_SystemReset(void)
{
#if (MICROCHIP_APPLICATION_SUPPORT == 0)
    // Simulate a reset
    S_SerialComm_TxMessage("System", "Ready", 0);
#endif
}

#else

void N_Util_SystemReset(void)
{
  N_Util_Reboot(N_UTIL_SYSTEMRESET_METHOD);
}

#endif

#if defined(__ICCAVR__) &&  (defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2))
void move_interrupts_to_Bootloader(void)
{
  uint8_t temp;
  temp = MCUCR;
  /* Enable change of Interrupt Vectors */
  MCUCR = temp|(1<<IVCE);
  /* Move interrupts to Boot Flash section */
  MCUCR = temp|(1<<IVSEL);
}
#endif

void N_Util_Reboot(N_Util_RebootMethod_t method)
{
  switch(method)
  {
    case N_Util_RebootMethod_Reset:
    {
      #if (defined(__ICCAVR__) &&  (defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)))
      {
        HAL_WarmReset();
      }
      #elif (defined(__ICCARM__) && (defined(ATSAMR21G18A) || defined(ATSAMR21E18A)|| defined(ATSAMR21E19A)))
      {
        NVIC_SystemReset();
      }
      #elif (defined(__GNUC__) && defined(_PIC32CX_))
      {
        SystemReset(); 
      }
      #endif
      break;
    }
    case N_Util_RebootMethod_JumpToBootloader:
    {
      #if (defined(__ICCAVR__) &&  (defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)))
      {
        uint32_t START_OF_BOOTLOADER = 0;
        uint8_t high_fuse = 0;
        halDisableInterrupts();
        __disable_interrupt();

        HAL_StopRtimer();
        /*Reset the RF module*/
        TRXPR_REG_s.trxrst = 1;
        while (TRX_STATUS_TRX_OFF != TRX_STATUS_REG_s.trxStatus);
        /* Read high fuse byte to get BOOTSZ0 and BOOTSZ1 size */
        high_fuse = read_avr_fuse(1);
        high_fuse &= HIGH_FUSE_MASK;
        high_fuse = high_fuse >> 1;

        if (high_fuse == 0x00)
           START_OF_BOOTLOADER = 0x1F000uL;
        else if (high_fuse == 0x01)
          START_OF_BOOTLOADER = 0x1F800uL;
        else if (high_fuse == 0x02)
          START_OF_BOOTLOADER = 0x1FC00uL;
        else if (high_fuse == 0x03)
          START_OF_BOOTLOADER = 0x1FE00uL;
        // Remap vector table to specific location
        move_interrupts_to_Bootloader();
        void(* startAddress)(void) =(void(*)(void))START_OF_BOOTLOADER;
        startAddress();
      }
      #elif (defined(__ICCARM__) && (defined(ATSAMR21G18A) || defined(ATSAMR21E18A)|| defined(ATSAMR21E19A)))
      {
         halDisableInterrupts();

         HAL_StopRtimer();
         /*Reset the RF module*/
         HAL_ClearRfRst();
         HAL_Delay(6);
         HAL_SetRfRst();

         const uint32_t START_OF_BOOTLOADER = 0x00000000uL;

         // Remap vector table to specific location
         SCB_VTOR = START_OF_BOOTLOADER;
         // Change stack pointer to bootloader stack
         uint32_t stack = (*(uint32_t *)(START_OF_BOOTLOADER + 0uL));
         __set_SP(stack);
         // Simulate a reset for the Application code by an absolute jump to the bootloader.
         typedef void(*pfVoid_t)(void);
         pfVoid_t pUsersReset = (pfVoid_t)(*(void **)(START_OF_BOOTLOADER + BOOTLOADER_PC_OFFSET_ADDR));
         pUsersReset();
      }
      #endif
      break;
    }
    case N_Util_RebootMethod_JumpToApplication:
    {
      #if defined(__ICCAVR__) &&  (defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2))
      {
        halDisableInterrupts();
         __disable_interrupt();
        HAL_StopRtimer();
        TRXPR_REG_s.trxrst = 1;
        while (TRX_STATUS_TRX_OFF != TRX_STATUS_REG_s.trxStatus);
        void(* startAddress)(void) =(void(*)(void))RESET_ADDR;
        startAddress();
      }
      #elif (defined(__ICCARM__) && (defined(ATSAMR21G18A) || defined(ATSAMR21E18A)|| defined(ATSAMR21E19A)))
      {
        halDisableInterrupts();
        HAL_StopRtimer();
        HAL_ClearRfRst();
        HAL_Delay(6);
        HAL_SetRfRst();
        __set_SP((uint32_t)STACK_TOP);

        void (*reset)() = RESET_ADDR;
        reset();
      }
      #elif defined(_PIC32CX_)
        // TODO: Inform application
      #endif
      break;
    }
    default:
      break;
  }
}

#if (defined(__MICROCHIP_BITCLOUD__) || defined(__GNUC__) )

uint16_t N_Util_Random_Impl(void)
{
    return SYS_GetRandomNumber();
}
#endif


uint16_t N_Util_GetMinimumStackLeft_Impl(void)
{
#if  defined(_STATS_ENABLED_)
  return SYS_StatGetMinimumStackLeft();
#else
  return N_UTIL_STACK_CHECK_DISABLED;
#endif
}

uint16_t N_Util_GetCurrentStackLeft_Impl(void)
{
#if defined(_STATS_ENABLED_)
  return Stat_GetCurrentStackLeft();
#else
  return N_UTIL_STACK_CHECK_DISABLED;
#endif

}


#if defined(__ICCAVR__) &&  (defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2))

uint32_t N_Util_TimerStart(void)
{
    TCCR5B = 0x05u; // Set prescaler to clkIO/1024
    uint16_t result = TCNT5;
    return (uint32_t)result;
}

uint32_t N_Util_TimerElapsed(uint32_t startValue)
{
    uint16_t start = (uint16_t)startValue;
    uint32_t elapsed32 = (uint32_t)(TCNT5 - start);
    elapsed32 = elapsed32 * (1000000ul / (CPU_CLK_HZ / 1024ul)); // using prescaler
    return elapsed32;
}


#elif (defined(__ICCARM__) && (defined(ATSAMR21G18A) || defined(ATSAMR21E18A)|| defined(ATSAMR21E19A)))


static uint32_t System_Gclk_Get_Hz(void)
{
    /* Get the frequency of the GCLK0 */
    uint32_t gen_input_hz;
    gen_input_hz = HAL_ReadGclkFreq();
    return gen_input_hz;
}

uint32_t N_Util_TimerStart(void)
{
    if (!SYSTICK_CSR_s.enable)
{
        SYSTICK_RVR_s.reload = 0xFFFFFFuL;
        SYSTICK_CSR_s.clksource = 1uL;
        SYSTICK_CSR_s.enable = 1uL;
    }
    return SYSTICK_CVR_s.current;
}

uint32_t N_Util_TimerElapsed(uint32_t startValue)
{
    // Note that SYSTICK counts DOWN.
    uint32_t operating_Freq_Hz;
    uint64_t elapsed32 = (startValue - SYSTICK_CVR_s.current) & 0x00FFFFFFuL;
    operating_Freq_Hz = System_Gclk_Get_Hz();
    if(operating_Freq_Hz >= 1000000ul)
    {
      elapsed32 /= (operating_Freq_Hz / 1000000ul);
    }
    else
    {
      elapsed32 *= (1000000ul / operating_Freq_Hz);
    }
    return elapsed32;
}
#endif
