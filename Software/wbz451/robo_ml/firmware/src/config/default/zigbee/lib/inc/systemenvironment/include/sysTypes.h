/*******************************************************************************
  System Types Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysTypes.h

  Summary:
    The header file describes global system types and pre-processor words
    which depends on compiler or platform
  Description:
    The header file describes global system types and pre-processor words
    which depends on compiler or platform
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

#ifndef _SYSTYPES_H
#define _SYSTYPES_H

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <systemenvironment/include/sysEndian.h>

#if defined(__ICCAVR__) || defined(__ICCARM__) || defined(__ICCAVR32__)

// \cond
#if defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
  || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A) || defined(_PIC32CX_)
  #include <intrinsics.h>
  #if defined(AT91SAM4S16C)
    #include <Atmel/iosam4s.h>
  #endif
#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA128B1) || defined(ATXMEGA256A3) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)
  #include <inavr.h>
  #include <ioavr.h>
  #include <intrinsics.h>
  #include <pgmspace.h>
#elif defined(AT32UC3A0512)
  #include <intrinsics.h>
#endif
// \endcond

/**
 * Some preprocessor magic to allow for a header file abstraction of
 * interrupt service routine declarations for the IAR compiler.  This
 * requires the use of the C99 _Pragma() directive (rather than the
 * old #pragma one that could not be used as a macro replacement), as
 * well as two different levels of preprocessor concetanations in
 * order to do both, assign the correct interrupt vector name, as well
 * as construct a unique function name for the ISR.
 *
 * Do *NOT* try to reorder the macros below, or you'll suddenly find
 * out about all kinds of IAR bugs...
 */
#define PRAGMA(x) _Pragma(#x)

// \cond
#if defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
   || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A) || defined(_PIC32CX_)

  #define PROGMEM_DECLARE(x) const x
  #define FLASH_VAR
  #define FLASH_PTR
  #define memcpy_P   memcpy
  #define hw_platform_address_size_t    uint32_t
  #define BEGIN_PACK PRAGMA(pack(push, 1))
  #define END_PACK   PRAGMA(pack(pop))
  #define INLINE static inline

#elif defined(AT32UC3A0512)

  #define PROGMEM_DECLARE(x) const x
  #define FLASH_VAR
  #define FLASH_PTR
  #define memcpy_P   memcpy
  #define hw_platform_address_size_t    uint32_t
  #define BEGIN_PACK PRAGMA(pack(push, 1))
  #define END_PACK   PRAGMA(pack(pop))
  #define INLINE static inline
  #define INTERRUPT   __interrupt

#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA128B1) || defined(ATXMEGA256A3) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)

  #ifndef __HAS_ELPM__
    #define _MEMATTR  __flash
  #else /* __HAS_ELPM__ */
    #define _MEMATTR  __farflash
  #endif /* __HAS_ELPM__ */

  #define PROGMEM_DECLARE(x) const _MEMATTR x
  #define FLASH_VAR _MEMATTR
  #define FLASH_PTR _MEMATTR
  #define BEGIN_PACK
  #define END_PACK
  #define INLINE PRAGMA(inline=forced) static
  #define __packed

  #define ASM     asm
  #define __SLEEP   __sleep()
  #define __ELPM    __extended_load_program_memory

  #if defined(ATXMEGA128A1) || defined(ATXMEGA128B1) || defined(ATXMEGA256A3) || defined(ATXMEGA256D3)
    #define ENABLE_CHANGE_PROTECTION_REGISTER   CCP = 0xD8
  #endif

  #define ISR(vec) PRAGMA(vector=vec) __interrupt void handler_##vec(void)
  #define sei() (__enable_interrupt())
  #define cli() (__disable_interrupt())
  /** Wait until bit \c bit in IO register \c sfr is clear. */
  #define loop_until_bit_is_clear(sfr, bit) do {;} while (sfr & (1 << bit))

  #define wdt_reset() (__watchdog_reset())

  #define SF_GET_LOW_FUSES() __AddrToZByteToSPMCR_LPM((void __flash *)0x0000, 0x09)
#endif

#if defined(ATMEGA1284)
  #define EEMPE  2
  #define EEPE   1
  #define PSRASY 1
#endif

#if defined(ATMEGA256RFR2)
  #define WDP3   5
#endif

#if defined(AT90USB1287)
  #define UPE1 2
  #define USB_GEN_vect USB_General_vect
  #define USB_COM_vect USB_Endpoint_Pipe_vect
#endif

// \endcond

#define PACK
#define MAY_ALIAS
#define NOP       __no_operation()
#define nop() (__no_operation())
#define PRINTF_STYLE
#define DEPRECATED

#elif defined(__GNUC__)

// Leave this here until new security naming will settle
#pragma GCC poison _HI_SECURITY_ _USE_SKKE_ _AUTHENTICATION_ _ZCL_KE_CLUSTER_

// \cond
#if defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
   || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A) || defined(_PIC32CX_)
#elif defined(X86)
#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA128B1) || defined(ATXMEGA256A3) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)
  #include <avr/io.h>
  #include <avr/pgmspace.h>
    #if !defined(ATXMEGA128A1) && !defined(ATXMEGA128B1) && !defined(ATXMEGA256A3) && !defined(ATXMEGA256D3)
      #include <avr/boot.h>
    #endif
  #include <avr/interrupt.h>
  #include <avr/wdt.h>
#elif defined(SIMULATOR)
#endif
// \endcond

// \cond
#if defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
   || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A) || defined(_PIC32CX_)

  #define PROGMEM_DECLARE(x) const x
  #define FLASH_VAR
  #define FLASH_PTR
  #define memcpy_P   memcpy
  #define hw_platform_address_size_t    uint32_t
  #define BEGIN_PACK
  #define END_PACK
  #define PACK __attribute__ ((packed))

#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA128B1) || defined(ATXMEGA256A3) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)

  #define SF_GET_LOW_FUSES() boot_lock_fuse_bits_get(GET_LOW_FUSE_BITS)
  // GCC with version lower than 4.7 ignores progmem attribute if it is used
  // in type definition with const modificator
  #define PROGMEM_DECLARE(x) const x __attribute__((__progmem__))
  #define FLASH_VAR PROGMEM
  #define FLASH_PTR
  #define hw_platform_address_size_t    uint16_t
  #define BEGIN_PACK
  #define END_PACK
  #define PACK
  #define __packed

  #define ASM     asm volatile
  #define __SLEEP   asm volatile ("sleep")
  #define UINT64_MEMCMP

  #if defined(ATXMEGA128A1) || defined(ATXMEGA128B1) || defined(ATXMEGA256A3) || defined(ATXMEGA256D3)
    #define ENABLE_CHANGE_PROTECTION_REGISTER   CCP = 0xD8
  #endif

#elif defined(WIN)
  #define PROGMEM_DECLARE(x) const x
  #define FLASH_VAR
  #define FLASH_PTR
  #define memcpy_P   memcpy
  #define hw_platform_address_size_t    uint32_t
  #define BEGIN_PACK
  #define END_PACK
  #define PACK __attribute__ ((packed))

#elif defined(SIMULATOR)
  #define PROGMEM_DECLARE(x) const x
  #define FLASH_VAR
  #define FLASH_PTR
  #define memcpy_P   memcpy
  #define hw_platform_address_size_t    uint32_t
  #define BEGIN_PACK
  #define END_PACK
  #define PACK __attribute__ ((packed))

#endif
// \endcond

#define INLINE static inline __attribute__ ((always_inline))
#define MAY_ALIAS __attribute__((__may_alias__))
#define NOP       asm volatile ("nop")
#define PRINTF_STYLE __attribute__ ((format (printf, 1, 2)))
#define DEPRECATED __attribute__ ((deprecated))

#else
  #error 'Compiler not supported.'
#endif

typedef bool result_t;
typedef uint64_t BcTime_t;

BEGIN_PACK
typedef struct PACK {uint16_t val;} u16Packed_t;
typedef struct PACK {uint32_t val;} u32Packed_t;
typedef struct PACK {uint64_t val;} u64Packed_t;
typedef struct PACK {int16_t val;}  s16Packed_t;
typedef struct PACK {int32_t val;}  s32Packed_t;
typedef struct PACK {int64_t val;}  s64Packed_t;
END_PACK

#if defined __ICCAVR__ || defined __ICCARM__ || defined __ICCAVR32__
  typedef uint8_t BitField_t;
#else
  typedef unsigned int BitField_t;
#endif

#if defined UINT64_MEMCMP
  #define IS_EQ_64BIT_VALUES(A, B) (0 == memcmp(&(A), &(B), sizeof(uint64_t)))
  #define IS_EQ_64BIT_VALUES_A(A, B) (0 == memcmp((A), (B), sizeof(uint64_t)))
  #define COPY_64BIT_VALUE(DST, SRC) __builtin_memcpy(&(DST), &(SRC), sizeof(uint64_t))
  #define COPY_64BIT_VALUE_A(DST, SRC) __builtin_memcpy((DST), (SRC), sizeof(uint64_t))
#else
  #define IS_EQ_64BIT_VALUES(A, B) ((A) == (B))
  #define COPY_64BIT_VALUE(DST, SRC) (DST) = (SRC)
  #define IS_EQ_64BIT_VALUES_A(A, B) (0 == memcmp((A), (B), sizeof(uint64_t)))
  #define COPY_64BIT_VALUE_A(DST, SRC) memcpy((DST), (SRC), sizeof(uint64_t))
#endif

#define BC_SUCCESS false
#define BC_FAIL    true

/**
 * \brief Emit the compiler pragma \a arg.
 *
 * \param[in] arg  The pragma directive as it would appear after \e \#pragma
 *             (i.e. not stringified).
 */
#define COMPILER_PRAGMA(arg)          _Pragma(#arg)

/**
 * \brief Set aligned boundary.
 */
#if (defined __GNUC__) || (defined __CC_ARM)
#define COMPILER_ALIGNED(a)        __attribute__((__aligned__(a)))
#elif (defined __ICCARM__)
#define COMPILER_ALIGNED(a)        COMPILER_PRAGMA(data_alignment = a)
#endif


/**
 * \brief Set word-aligned boundary.
 */
#if (defined __GNUC__) || defined(__CC_ARM)
#define COMPILER_WORD_ALIGNED         __attribute__((__aligned__(4)))
#elif (defined __ICCARM__)
#define COMPILER_WORD_ALIGNED         COMPILER_PRAGMA(data_alignment = 4)
#endif

#endif
// eof sysTypes.h

