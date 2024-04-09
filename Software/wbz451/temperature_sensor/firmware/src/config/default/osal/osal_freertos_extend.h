/*******************************************************************************
  Operating System Abstraction Layer Extention for FreeRTOS

  Company:
    Microchip Technology Inc.

  File Name:
    osal_freertos_extend.h

  Summary:
    OSAL FreeRTOS extention implementation interface file

  Description:
    Interface file to extend the support of FreeRTOS by OSAL
*******************************************************************************/

// DOM-IGNORE-BEGIN
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

#ifndef _OSAL_FREERTOS_EXTEND_H
#define _OSAL_FREERTOS_EXTEND_H

#ifdef __cplusplus
extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "osal_freertos.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* declare default data type handles. Any RTOS port must define it's own copy of these */
/*
 * Type by which queues are referenced.  For example, a call to xQueueCreate()
 * returns an QueueHandle_t variable that can then be used as a parameter to
 * xQueueSend(), xQueueReceive(), etc.
 */
typedef QueueHandle_t              OSAL_QUEUE_HANDLE_TYPE;

/*
 * Type by which queue sets are referenced.  For example, a call to
 * xQueueCreateSet() returns an xQueueSet variable that can then be used as a
 * parameter to xQueueSelectFromSet(), xQueueAddToSet(), etc.
 */
typedef QueueSetHandle_t           OSAL_QUEUE_SET_HANDLE_TYPE;

/*
 * Queue sets can contain both queues and semaphores, so the
 * QueueSetMemberHandle_t is defined as a type to be used where a parameter or
 * return value can be either an QueueHandle_t or an SemaphoreHandle_t.
 */
typedef QueueSetMemberHandle_t     OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE;

// *****************************************************************************
/* OSAL Result type

  Summary:
    Enumerated type representing the general return value from OSAL functions.

  Description:
    This enum represents possible return types from OSAL functions.

  Remarks:
    These enum values are the possible return values from OSAL functions
    where a standard success/fail type response is required. The majority
    of OSAL functions will return this type with a few exceptions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Section: Interface Routines Group
// *****************************************************************************

// *****************************************************************************
/**
*@brief Creates a new queue instance, and returns a handle by which the new queue
*    can be referenced
*
*@param     queID       - A pointer to the queue ID
*       queueLength - The maximum number of items that the queue can contain. 
*       itemSize    - The number of bytes each item in the queue will require.
*                  Items are queued by copy, not by reference, so this is the number of bytes
*                  that will be copied for each posted item.
*                  Each item in the queue must be the same size.
*
*@retval OSAL_RESULT_TRUE    - A queue had been created
*        OSAL_RESULT_FALSE   - Queue creation failed
*/
OSAL_RESULT OSAL_QUEUE_Create(OSAL_QUEUE_HANDLE_TYPE *queID, uint32_t queueLength, uint32_t itemSize);

// *****************************************************************************
/**
*@brief Creates a new queue set instance, and returns a handle by which the new queue
    can be referenced
*
*@param  queID       - A pointer to the queue ID
*        queueLength - The maximum number of items that the queue can contain.
*
*@retval OSAL_RESULT_TRUE    - A queue set had been created
*        OSAL_RESULT_FALSE   - Queue creation failed
*/
OSAL_RESULT OSAL_QUEUE_CreateSet(OSAL_QUEUE_SET_HANDLE_TYPE *queID, uint32_t queueLength);

// *****************************************************************************
/**
*@brief Add the queues and semaphores to the set.Reading from these queues and semaphore can
*	    only be performed after a call to xQueueSelectFromSet() has
*       returned the queue or semaphore handle from this point on.
*
*@param   queSetMember       - Member queue or semaphore to be added in the set
*	      queSetID           - A pointer to the queue ID 
*
*@retval OSAL_RESULT_TRUE    - A queue had been created
*        OSAL_RESULT_FALSE   - Queue creation failed
*/
OSAL_RESULT OSAL_QUEUE_AddToSet(OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE *queSetMember, OSAL_QUEUE_SET_HANDLE_TYPE *queSetID);

// *****************************************************************************
/**
*@brief Block to wait for something to be available from the queues or semaphore that have been added to the set.
*
*@param  queSetMember       - Member queue or semaphore to be added in the set
*	     queSetID           - A pointer to the queue ID
*	     waitMS             - wait time in milliseconds. other value OSAL_WAIT_FOREVER - wait indefinitely
*
*@retval OSAL_RESULT_TRUE    - A queue had been created
*        OSAL_RESULT_FALSE   - Queue creation failed
*/
OSAL_RESULT OSAL_QUEUE_SelectFromSet(OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE *queSetMember, OSAL_QUEUE_SET_HANDLE_TYPE *queSetID, uint32_t waitMS);

// *****************************************************************************
/**
*@brief Post an item into an OSAL Queue. The item is queued by copy, not by reference.
*    This function must not be called from an interrupt service routine.
*    See OSAL_QUEUE_SendISR() for an alternative which may be used in an ISR.
*
*@param  queID       - A pointer to the queue ID
*
*        itemToQueue - A pointer to the item that is to be placed on the queue.
*                  The size of the items the queue will hold was defined when the queue was created,
*                  so this many bytes will be copied from itemToQueue into the queue storage area.
*
*        waitMS       - Time limit to wait in milliseconds.
*                   0 - do not wait
*                   OSAL_WAIT_FOREVER - return only when semaphore is obtained
*                   Other values - timeout delay
*
*@retval OSAL_RESULT_TRUE    - Item copied to the queue
*        OSAL_RESULT_FALSE   - Item not copied to the queue or timeout occurred
*/
OSAL_RESULT OSAL_QUEUE_Send(OSAL_QUEUE_HANDLE_TYPE *queID, void *itemToQueue, uint32_t waitMS);

// *****************************************************************************
/**
*@brief Post an item into an OSAL Queue. The item is queued by copy, not by reference.
*    The highest priority task currently blocked on the queue will be released and
*    made ready to run. This form of the send function should be used witin an ISR.
*
*@param  queID       - A pointer to the queue ID
*
*        itemToQueue - A pointer to the item that is to be placed on the queue.
*                  The size of the items the queue will hold was defined when the queue was created,
*                  so this many bytes will be copied from itemToQueue into the queue storage area.
*
*        waitMS       - Time limit to wait in milliseconds.
*                   0 - do not wait
*                   OSAL_WAIT_FOREVER - return only when semaphore is obtained
*                   Other values - timeout delay
*
*@retval OSAL_RESULT_TRUE    - Item copied to the queue
*        OSAL_RESULT_FALSE   - Item not copied to the queue or timeout occurred
*/
OSAL_RESULT OSAL_QUEUE_SendISR(OSAL_QUEUE_HANDLE_TYPE *queID, void  *itemToQueue);

// *****************************************************************************
/**
*@brief Receive an item from an OSAL Queue. The item is received by copy so a buffer of
*    adequate size must be provided. The number of bytes copied into the buffer
*    was defined when the queue was created.
*    Successfully received items are removed from the queue.
*    This function must not be used in an interrupt service routine.
*
*@param      queID       - A pointer to the queue ID
*
*    buffer      - A pointer to the buffer into which the received item will be copied.
*                  The size of the items the queue hold was defined when the queue was created,
*                  so this many bytes will be copied from the queue storage area into the buffer.
*
*    waitMS      - Time limit to wait in milliseconds.
*                   0 - do not wait
*                   OSAL_WAIT_FOREVER - return only when semaphore is obtained
*                   Other values - timeout delay
*
*@retval OSAL_RESULT_TRUE    - An item was successfully received from the queue
*        OSAL_RESULT_FALSE   - An item was not successfully received from the queue
*                          or timeout occurred
*/
OSAL_RESULT OSAL_QUEUE_Receive(OSAL_QUEUE_HANDLE_TYPE *queID, void  *pBuffer, uint32_t waitMS);

// *****************************************************************************
/**
*@brief Query if an OSAL Queue is full.
*    These function should be used only from witin an ISR, or within a critical section.
*
*@param      queID       - A pointer to the queue ID
*
*@retval OSAL_RESULT_TRUE    - The queue is Full
*        OSAL_RESULT_FALSE   - The queue is not Full
*/
OSAL_RESULT OSAL_QUEUE_IsFullISR(OSAL_QUEUE_HANDLE_TYPE *queID);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif // _OSAL_FREERTOS_EXTEND_H

/*******************************************************************************
 End of File
*/
