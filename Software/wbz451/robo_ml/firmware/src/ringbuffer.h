/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
Buffering Interface Header File

Company:
Microchip Technology Inc.

File Name:
ringbuffer.h

Summary:
This file contains the ring buffer API used for generic buffering

Notes:
    - The API provided here is strictly designed for a single reader thread and
      single writer thread; other uses will cause race conditions.
 *******************************************************************************/
#ifndef RINGBUFFER_H
#define	RINGBUFFER_H
#include <stddef.h>
#include <stdint.h>

/*
* Define the compiler/memory fence directive to use. This directive ensures that
* all data memory operations complete before the updating of the read or write
* index
*/
#if defined(__GNUC__)
#   if defined(__arm__)
    /* Full compiler/memory barrier */
#   define __ringbuffer_sync()        __asm__ volatile ("dsb" ::: "memory")
#   else
/*
* This directive only ensures the *compiler* doesn't reorder data memory
* operations before the updating of the read or write index this is enough on
* platforms that don't do out of order execution
*/
#   define __ringbuffer_sync()        __asm__ volatile ("" ::: "memory")
#   endif /* if defined(__arm__) */
#else
#   pragma message("ringbuffer.h:: No memory barrier defined; thread safety not guaranteed")
#   define __ringbuffer_sync()        do {} while (0)
#endif /* if defined(__GNUC__) */

#ifdef	__cplusplus
extern "C" {
#endif

/*
* Define the ringbuffer size_t
*
* !NOTE!
* - the types size limits the maximum number of items the buffer can hold
* - this type is ***assumed to be a size that can be read/written by the CPU
*   atomically***
* - if the type is not atomically accessible, you'll have to enforce your own
*   synchronization mechanisms
*/
#if defined(__AVR__) || defined(__XC8)
/* AVR, PIC10/12/14/16/18 */
typedef uint8_t ringbuffer_size_t;
#elif defined(__dsPIC30__) || defined(__XC16)
/* PIC24, dsPIC */
typedef uint16_t ringbuffer_size_t;
#elif defined (__arm__) || defined(__XC32)
/* SAM, PIC32C, PIC32M */
typedef uint32_t ringbuffer_size_t;
#else
#pragma message("ringbuffer.h:: Unsure about architecture, assuming 32-bit accesses are atomic")
typedef uint32_t ringbuffer_size_t;
#endif

/* !NOTE!
* Due to implementation, we can only accept buffer sizes up to half of the max
* value that ringbuffer_size_t can represent
*/
#define RINGBUFFER_MAX_SIZE ((((ringbuffer_size_t) ~((ringbuffer_size_t) 0)) >> 1) + 1)

typedef struct ring_buffer {
    volatile ringbuffer_size_t writeIdx;
    volatile ringbuffer_size_t readIdx;
    ringbuffer_size_t len;
    size_t itemsize;
    ringbuffer_size_t _mask;
    uint8_t *data;
} ringbuffer_t;

/* Return non-zero on error */
int8_t ringbuffer_init(ringbuffer_t *ringbuffer, void *buffer, ringbuffer_size_t len, size_t itemsize);

/* 
* This function is not thread safe.
* It should only be called when the program is in a state where the caller
* thread cannot be interrupted by any other thread that could access the ring
* buffer.
*/
void ringbuffer_reset(ringbuffer_t *ringbuffer);

/* Copy items from ringbuffer into another buffer */
ringbuffer_size_t ringbuffer_read(ringbuffer_t *ringbuffer, void *dst, ringbuffer_size_t itemcount);

/* Copy items from buffer into ringbuffer */
ringbuffer_size_t ringbuffer_write(ringbuffer_t *ringbuffer, const void *src, ringbuffer_size_t itemcount);

/* Get number of items available for reading */
ringbuffer_size_t ringbuffer_get_read_items(ringbuffer_t *ringbuffer);

/* Get number of items available for writing */
ringbuffer_size_t ringbuffer_get_write_items(ringbuffer_t *ringbuffer);

/* Get a pointer to a contiguous region starting at the oldest available read item; 
 * itemcount will return the size of the region in terms of number of items 
 * Note:
 * Call advance_read_index and call this again to get the next contiguous region
 */
const void * ringbuffer_get_read_buffer(ringbuffer_t *ringbuffer, ringbuffer_size_t *itemcount);

/* Get a pointer to a contiguously writable region; 
 * itemcount will return the size of the region in terms of number of items 
 * Note:
 * Call advance_write_index and call this again to get the next contiguous region
 */
void * ringbuffer_get_write_buffer(ringbuffer_t *ringbuffer, ringbuffer_size_t *itemcount);

/* Advance the index to indicate new items are available for reading
 * Returns number of indices actually advanced (less than itemcount when overrun is encountered) */
ringbuffer_size_t ringbuffer_advance_write_index(ringbuffer_t *ringbuffer, ringbuffer_size_t itemcount);

/* Advance the index to indicate space is available for writing
*  Returns number of indices actually advanced (less than itemcount when underrun is encountered) */
ringbuffer_size_t ringbuffer_advance_read_index(ringbuffer_t *ringbuffer, ringbuffer_size_t itemcount);

#ifdef	__cplusplus
}
#endif

#endif	/* RINGBUFFER_H */
