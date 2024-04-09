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
  Buffering Interface Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ringbuffer.c

  Summary:
    This file contains the ring buffer API used for generic buffering

  Notes:
    - The API provided here is strictly designed for a single reader thread and
      single writer thread; other uses will cause race conditions.
 *******************************************************************************/

#include <stdint.h>
#include <string.h>
#include "ringbuffer.h"

/* Return non-zero on error */
int8_t ringbuffer_init(ringbuffer_t *ringbuffer, void *buffer, ringbuffer_size_t len, size_t itemsize) {
    /* Check for power of 2 */
    if ( (((len - 1) & len) != 0) || (len > RINGBUFFER_MAX_SIZE) || (buffer == NULL) )
        return 1;

    memset(ringbuffer, 0, sizeof(ringbuffer_t));
    ringbuffer->len = len;
    ringbuffer->itemsize = itemsize;
    ringbuffer->data = buffer;
    ringbuffer->_mask = 2*len - 1;

    return 0;
}

/* 
* This function is not thread safe.
* It should only be called when the program is in a state where the caller
* thread cannot be interrupted by any other thread that could access the ring
* buffer.
*/
void ringbuffer_reset(ringbuffer_t *ringbuffer) {
    ringbuffer->readIdx = 0;
    ringbuffer->writeIdx = 0;
}

ringbuffer_size_t ringbuffer_read(ringbuffer_t *ringbuffer, void *dst, ringbuffer_size_t itemcount) {
    ringbuffer_size_t availitems = ringbuffer_get_read_items(ringbuffer);
    ringbuffer_size_t buflen;
    const void *src = ringbuffer_get_read_buffer(ringbuffer, &buflen);

    if (itemcount > availitems)
        itemcount = availitems;

    if (buflen >= itemcount) {
        memcpy(dst, src, itemcount * ringbuffer->itemsize);
    }
    else {
        memcpy(dst, src, buflen * ringbuffer->itemsize);
        src = ringbuffer->data; /* wrap around buffer */
        memcpy((uint8_t *) dst + buflen * ringbuffer->itemsize, src, (itemcount - buflen) * ringbuffer->itemsize);
    }

    ringbuffer_advance_read_index(ringbuffer, itemcount);
    return itemcount;
}

ringbuffer_size_t ringbuffer_write(ringbuffer_t *ringbuffer, const void *src, ringbuffer_size_t itemcount) {
    ringbuffer_size_t availitems = ringbuffer_get_write_items(ringbuffer);
    ringbuffer_size_t buflen;
    void *dst = ringbuffer_get_write_buffer(ringbuffer, &buflen);

    if (itemcount > availitems)
        itemcount = availitems;
    
    if (buflen >= itemcount) {
        memcpy(dst, src, itemcount * ringbuffer->itemsize);
    }
    else {
        memcpy(dst, src, buflen * ringbuffer->itemsize);
        dst = ringbuffer->data; /* wrap around buffer */
        memcpy(dst, (uint8_t *) src + buflen * ringbuffer->itemsize, (itemcount - buflen) * ringbuffer->itemsize);
    }

    ringbuffer_advance_write_index(ringbuffer, itemcount);
    return itemcount;
}

ringbuffer_size_t ringbuffer_get_read_items(ringbuffer_t *ringbuffer) {
    return (ringbuffer->writeIdx - ringbuffer->readIdx) & ringbuffer->_mask;
}

ringbuffer_size_t ringbuffer_get_write_items(ringbuffer_t *ringbuffer) {
    return ringbuffer->len - ((ringbuffer->writeIdx - ringbuffer->readIdx) & ringbuffer->_mask);
}

const void * ringbuffer_get_read_buffer(ringbuffer_t *ringbuffer, ringbuffer_size_t *itemcount) {
    ringbuffer_size_t writeIdx = ringbuffer->writeIdx;
    ringbuffer_size_t readIdx = ringbuffer->readIdx;
    ringbuffer_size_t availitems = (writeIdx - readIdx) & ringbuffer->_mask;

    readIdx &= ringbuffer->len - 1; /* Shift readIdx to inside the buffer */
    if (readIdx + availitems > ringbuffer->len) {
        *itemcount = ringbuffer->len - readIdx;
    }
    else {
        *itemcount = availitems;
    }
    
    return (const void *) (ringbuffer->data + readIdx * ringbuffer->itemsize);
}

void * ringbuffer_get_write_buffer(ringbuffer_t *ringbuffer, ringbuffer_size_t *itemcount) {
    ringbuffer_size_t readIdx = ringbuffer->readIdx;
    ringbuffer_size_t writeIdx = ringbuffer->writeIdx;
    ringbuffer_size_t availitems = ringbuffer->len - ((writeIdx - readIdx) & ringbuffer->_mask);

    writeIdx &= ringbuffer->len - 1; /* Shift writeIdx to inside the buffer */
    if (writeIdx + availitems > ringbuffer->len) {
        *itemcount = ringbuffer->len - writeIdx;
    }
    else {
        *itemcount = availitems;
    }
    
    return (void *) (ringbuffer->data + writeIdx * ringbuffer->itemsize);
}

ringbuffer_size_t ringbuffer_advance_read_index(ringbuffer_t *ringbuffer, ringbuffer_size_t itemcount) {
    ringbuffer_size_t readIdx = ringbuffer->readIdx;
    ringbuffer_size_t availitems = (ringbuffer->writeIdx - readIdx) & ringbuffer->_mask;
    ringbuffer_size_t newIdx;
    
    if (itemcount > availitems)
        itemcount = availitems;

    newIdx = (readIdx + itemcount) & ringbuffer->_mask;

    __ringbuffer_sync();
    ringbuffer->readIdx = newIdx;
    
    return itemcount;
}

ringbuffer_size_t ringbuffer_advance_write_index(ringbuffer_t *ringbuffer, ringbuffer_size_t itemcount) {
    ringbuffer_size_t writeIdx = ringbuffer->writeIdx;
    ringbuffer_size_t availitems = ringbuffer->len - ((writeIdx - ringbuffer->readIdx) & ringbuffer->_mask);
    ringbuffer_size_t newIdx;

    if (itemcount > availitems)
        itemcount = availitems;
    
    newIdx = (writeIdx + itemcount) & ringbuffer->_mask;

    __ringbuffer_sync();
    ringbuffer->writeIdx = newIdx;

    return itemcount;
}
