// DOM-IGNORE-BEGIN
/**********************************************************************
  System utilities Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysUtils.h

  Summary:
    Header file describes stack utilities functions.

  Description:
    Header file describes stack utilities functions.
 **************************************************************/

/***********************************************************************
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
**********************************************************************/
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#ifndef _SYSUTILS_H
#define _SYSUTILS_H
// DOM-IGNORE-END

/*************************************************************************
                        Includes section.
 ************************************************************************/
 
#include <systemenvironment/include/sysTypes.h>
#include <string.h>
#include <stdlib.h>
#include <systemenvironment/include/sysIncrementMacro.h>
#include <systemenvironment/include/sysRepeatMacro.h>

/***********************************************************************
                        Definitions section.
 **************************************************************************/
 
//cond internal
#if defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(AT91SAM4S16C) || defined(ATSAMD20J18) \
  || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A) || defined(_PIC32CX_)
  #define SYS_BYTE_MEMCPY SYS_ByteMemcpy
#elif defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) \
   || defined(ATXMEGA128A1) || defined(ATXMEGA256A3) || defined(ATXMEGA128B1) || defined(ATXMEGA256D3) \
   || defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)
  #define SYS_BYTE_MEMCPY memcpy
#else
  #define SYS_BYTE_MEMCPY memcpy
#endif

#if defined(ATMEGA1281) || defined(ATMEGA2561) || defined(ATMEGA1284) || defined(AT90USB1287) || \
   defined(ATMEGA128RFA1) || defined(ATMEGA256RFR2) || defined(ATMEGA2564RFR2)
/** Macroses to accept memory I/O registers for AVR Mega family */
#define MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
#define MMIO_WORD(mem_addr) (*(volatile uint16_t *)(mem_addr))
#endif /** AVR Mega family */

#define  GET_FIELD_PTR(structPtr, typeName, fieldName) \
  ((uint8_t *)(structPtr) + offsetof(typeName, fieldName))

#define GET_PARENT_BY_FIELD(TYPE, FIELD, FIELD_POINTER)  \
  ((TYPE *)(((uint8_t *)FIELD_POINTER) - offsetof(TYPE, FIELD)))
#define GET_CONST_PARENT_BY_FIELD(TYPE, FIELD, FIELD_POINTER)  \
  ((const TYPE *)(((const uint8_t *)FIELD_POINTER) - offsetof(TYPE, FIELD)))

#define GET_STRUCT_BY_FIELD_POINTER(struct_type, field_name, field_pointer)\
  ((struct_type *) (((uint8_t *) field_pointer) - FIELD_OFFSET(struct_type, field_name)))
#define GET_INDEX_FROM_OFFSET(PTR1, PTR2)  (PTR1 - PTR2)

// Size of slice between firstField end lastField of struct (including lastField)
#define SLICE_SIZE(type, firstField, lastField)\
  (offsetof(type, lastField) - offsetof(type, firstField) + sizeof(((type *)0)->lastField))

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

#define ADD_COMMA(value, n) value,
/** Macro for array initialization */
#define INIT_ARRAY(initValue, size) {REPEAT_MACRO(ADD_COMMA, initValue, size)}

#undef FIELD_OFFSET
#define FIELD_OFFSET(struct_type, field_name)\
  (((uint8_t*) &((struct_type *)(NULL))->field_name) - (uint8_t*)NULL)

#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))

#define FIRST_BIT_SET(bitmask)     ((bitmask) & (~(bitmask) + 1))
#define FIRST_BIT_CLEARED(bitmask) (~(bitmask) & ((bitmask) + 1))

#define COMPARE_WITH_THRESHOLD(a, b, threshold) \
  (abs((a) - (b)) < (threshold) ? ((a) > (b) ? 1 : 0) : ((a) > (b) ? 0 : 1))

#define CEIL(a, b) (((a) - 1U)/(b) + 1U)
/*************************************************************************
                        Inline functions' section.
 ************************************************************************/
 
/*********************************************************************//**
  \brief Performs bytes memory copying operation.

  \param dst  - points destination memory start address.
         src  - points source memory start address.
         size - number of bytes to copy.
  \return pointer to dst.
 ***********************************************************************/
INLINE void * SYS_ByteMemcpy(void *dst, const void *src, uint16_t size)
{
  uint8_t *dst_ = (uint8_t *) dst;
  const uint8_t *src_ = (const uint8_t *) src;

  while(size--)
    *(dst_++) = *(src_++);
  return dst;
}

/*********************************************************************//**
  \brief Performs swap bytes in array of length

  \param array  - pointer to array.
         length  - array length
  \return no return.
 ************************************************************************/
void SYS_Swap(uint8_t *array, uint8_t length);

/***********************************************************************//**
  \brief  Starts timer to update rand
 **************************************************************************/
void sysStartUpdatingRandSeed(void);

#if defined(_SLEEP_WHEN_IDLE_)
/********************************************************************//**
  \brief Stops periodic updating of the random seed.
 ***************************************************************************/
void sysStopUpdatingRandSeed(void);
#endif // _SLEEP_WHEN_IDLE_ 
/** endcond */

/**********************************************************************//**
  \brief Generates a random two-bytes number

  ingroup sys

  Generation of a random number is based on the seed value created in ZDO
  with the use of the radio (if the radio supports such mechanism). The stack
  creates the seed value on startup and updates it periodically later on.

  \returns A random number in the range 0x000 - 0xFFFF
 ***********************************************************************/
static inline uint16_t SYS_GetRandomNumber(void)
{
  uint16_t result = rand();
  return result;
}

/********************************************************************//**
  \brief Generates a random two-bytes number normalized by given upper limit.

  ingroup sys

  Generation of a random number is based on the seed value created in ZDO
  with the use of the radio (if the radio supports such mechanism). The stack
  creates the seed value on startup and updates it periodically later on.

  \param  upperLimit - The upper limit of random number

  \returns A normalized random number in the range 0x000 - upper limit
 **************************************************************************/
uint16_t SYS_GetNormalizedRandomNumber(uint16_t upperLimit);

/********************************************************************//**
  \brief Generates a sequence of random numbers and copies them into the buffer

  ingroup sys

  The function uses the same mechanism as the SYS_GetRandomNumber() function,but creates the specified number of random bytes.

  \param  buffer - The buffer to hold generated random data
          size   - The number of bytes of random data to compute and 
                   store in the buffer
  \return  0 - indicates successful completion
 ************************************************************************/
int SYS_GetRandomSequence(uint8_t *buffer, unsigned long size);

/*******************************************************************//**
  \brief Calculates CRC using CRC-16-CCITT algorithm

  ingroup sys

  \param initValue - CRC initial value
         byte - next byte to calculate CRC

  \return  calculated CRC value
 ***********************************************************************/
INLINE uint16_t SYS_Crc16Ccitt(uint16_t initValue, uint8_t byte)
{
  byte ^= initValue & 0xffU;
  byte ^= byte << 4U;

  return ((((uint16_t)byte << 8) | ((initValue & 0xff00U) >> 8))
          ^ (uint8_t)(byte >> 4) ^ ((uint16_t)byte << 3));
}

INLINE void memcpy4ByteAligned(void* outbuf, void* inbuf, uint16_t length)
{
  static uint8_t mod_size;
  static uint8_t size;
  static uint16_t k;
  uint32_t* src = (uint32_t* )inbuf;
  uint32_t* dst = (uint32_t* )outbuf;
   
  mod_size = (length % 4);

  // total_length is in multiple of 4
  if (mod_size !=0)
    size  = length + 4 - mod_size; 
  else 
    size  = length;
  
  size  = size >> 2;
  for (k = 0; k < size; k++)
  {
      *dst = *src;
      src++;
      dst++;
  }
}

/*******************************************************************//**
  \brief Calculate difference between two numbers with overflow handling

  ingroup sys

  \param subtrahend - Value to be subtracted
         minuend - Value from where to be subtracted

  \return  difference between subtrahend and minuend
 ***********************************************************************/
INLINE uint32_t SYS_calculateDifference(uint32_t subtrahend, uint32_t minuend)
{
    uint32_t difference = 0U;
    
    if (((int32_t )(minuend -subtrahend)) >= 0)
    {
        difference = (minuend -subtrahend);
    }
    else
    {
        uint32_t complement = (UINT32_MAX - subtrahend);

        difference = complement + minuend + 1;
    }
    
    return difference;
}

#ifndef _MAC2_
/********************************************************************//**
  \brief This function reads version number in CS and returns as string

  \param  strVersion - string version. intVersion - integer version

  \return  bool. true indicates success. false indicates failure,
           which means version is unavailable
 ************************************************************************/
bool SYS_GetBitCloudRevision(uint8_t *strVersion, uint32_t *intVersion);
#endif // _MAC2_

#endif // _SYSUTILS_H
/** eof sysUtils.h */
