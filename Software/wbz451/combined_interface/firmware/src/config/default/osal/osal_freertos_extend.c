/*******************************************************************************
  Operating System Abstraction Layer Extention for FreeRTOS

  Company:
    Microchip Technology Inc.

  File Name:
    osal_freertos_extend.c

  Summary:
    Provide extention for OSAL mappings for the FreeRTOS(tm) Real-time operating system

  Description:
    This file contains functional implementations of the OSAL extention for FreeRTOS.

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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.
 */

#include "osal_freertos_extend.h"

// *****************************************************************************
// *****************************************************************************
// Section: OSAL Routines
// *****************************************************************************
// *****************************************************************************
/* These routines implement the OSAL for the chosen RTOS.
*/

// Queue group
// *****************************************************************************
/*******************************************************************************
  Function:
    OSAL_RESULT OSAL_QUEUE_Create(OSAL_QUEUE_HANDLE_TYPE *queID, uint32_t queueLength, uint32_t itemSize)

  Summary:
    Create an OSAL Queue

  Description:
    Creates a new queue instance, and returns a handle by which the new queue
    can be referenced.

  Parameters:
    queID       - A pointer to the queue ID

    queueLength - The maximum number of items that the queue can contain.

    itemSize    - The number of bytes each item in the queue will require.
                  Items are queued by copy, not by reference, so this is the number of bytes
                  that will be copied for each posted item.
                  Each item in the queue must be the same size.

  Returns:
    OSAL_RESULT_TRUE    - A queue had been created
    OSAL_RESULT_FALSE   - Queue creation failed

  Example:
    <code>
    OSAL_QUEUE_HANDLE_TYPE queID;
    OSAL_RESULT result = OSAL_QUEUE_Create(&queID, 16, 8);
    </code>

  Remarks:
*/
OSAL_RESULT OSAL_QUEUE_Create(OSAL_QUEUE_HANDLE_TYPE *queID, uint32_t queueLength, uint32_t itemSize)
{
    *queID = xQueueCreate(queueLength, itemSize);

    if (NULL == *queID)
    {
        return OSAL_RESULT_FALSE;
    }

    return OSAL_RESULT_TRUE;
}

OSAL_RESULT OSAL_QUEUE_CreateSet(OSAL_QUEUE_SET_HANDLE_TYPE *queSetID, uint32_t queueLength)
{
    *queSetID = xQueueCreateSet(queueLength);

    if (NULL == *queSetID)
    {
        return OSAL_RESULT_FALSE;
    }

    return OSAL_RESULT_TRUE;
}

OSAL_RESULT OSAL_QUEUE_AddToSet(OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE *queSetMember, OSAL_QUEUE_SET_HANDLE_TYPE *queSetID)
{

    if (pdTRUE == xQueueAddToSet(*queSetMember, *queSetID))
    {
      return OSAL_RESULT_TRUE;
    }

    return OSAL_RESULT_FALSE;
}

OSAL_RESULT OSAL_QUEUE_SelectFromSet(OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE *queSetMember, OSAL_QUEUE_SET_HANDLE_TYPE *queSetID, uint32_t waitMS)
{
    *queSetMember = xQueueSelectFromSet(*queSetID, waitMS);

    if (NULL == *queSetMember)
    {
        return OSAL_RESULT_FALSE;
    }

    return OSAL_RESULT_TRUE;
}

/*******************************************************************************
  Function:
    OSAL_RESULT OSAL_QUEUE_Send(OSAL_QUEUE_HANDLE_TYPE *queID, void *itemToQueue, uint32_t waitMS)

  Summary:
    Post an item into an OSAL Queue.

  Description:
    Post an item into an OSAL Queue. The item is queued by copy, not by reference.
    This function must not be called from an interrupt service routine.
    See OSAL_QUEUE_SendISR() for an alternative which may be used in an ISR.

  Parameters:
    queID       - A pointer to the queue ID

    itemToQueue - A pointer to the item that is to be placed on the queue.
                  The size of the items the queue will hold was defined when the queue was created,
                  so this many bytes will be copied from itemToQueue into the queue storage area.

    waitMS       - Time limit to wait in milliseconds.
                   0 - do not wait
                   OSAL_WAIT_FOREVER - return only when semaphore is obtained
                   Other values - timeout delay

  Returns:
    OSAL_RESULT_TRUE    - Item copied to the queue
    OSAL_RESULT_FALSE   - Item not copied to the queue or timeout occurred

  Example:
    <code>
    OSAL_RESULT result = OSAL_QUEUE_Create(&queID, &itemToQueue, OSAL_WAIT_FOREVER);
    </code>

  Remarks:
*/
OSAL_RESULT OSAL_QUEUE_Send(OSAL_QUEUE_HANDLE_TYPE *queID, void *itemToQueue, uint32_t waitMS)
{
    TickType_t timeout = 0;

    if (OSAL_WAIT_FOREVER == waitMS)
    {
        timeout = portMAX_DELAY;
    }
    else
    {
        timeout = (TickType_t)(waitMS / portTICK_PERIOD_MS);
    }
    if (pdTRUE == xQueueSend(*queID, itemToQueue, timeout))
    {
        return OSAL_RESULT_TRUE;
    }
    else
    {
        return OSAL_RESULT_FALSE;
    }
}

/*******************************************************************************
  Function:
    OSAL_RESULT OSAL_QUEUE_SendISR(OSAL_QUEUE_HANDLE_TYPE *queID, void  *itemToQueue)

  Summary:
    Post an item into an OSAL Queue from within an ISR

  Description:
    Post an item into an OSAL Queue. The item is queued by copy, not by reference.
    The highest priority task currently blocked on the queue will be released and
    made ready to run.
    This form of the send function should be used witin an ISR.

  Parameters:
    queID       - A pointer to the queue ID

    itemToQueue - A pointer to the item that is to be placed on the queue.
                  The size of the items the queue will hold was defined when the queue was created,
                  so this many bytes will be copied from itemToQueue into the queue storage area.

  Returns:
    OSAL_RESULT_TRUE    - Item copied to the queue
    OSAL_RESULT_FALSE   - Item not copied to the queue

  Example:
    <code>
    OSAL_RESULT result = OSAL_QUEUE_Create(&queID, &itemToQueue, OSAL_WAIT_FOREVER);
    </code>

  Remarks:
*/
OSAL_RESULT OSAL_QUEUE_SendISR(OSAL_QUEUE_HANDLE_TYPE *queID, void  *itemToQueue)
{
    BaseType_t _taskWoken = pdFALSE;

    if (pdTRUE == xQueueSendFromISR(*queID, itemToQueue, &_taskWoken))
    {
        portYIELD_FROM_ISR(_taskWoken);
        return OSAL_RESULT_TRUE;
    }
    else
    {
        return OSAL_RESULT_FALSE;
    }
}

/*******************************************************************************
  Function:
    OSAL_RESULT OSAL_QUEUE_Receive(OSAL_QUEUE_HANDLE_TYPE *queID, void  *buffer, uint32_t waitMS)

  Summary:
    Receive an item from an OSAL Queue.

  Description:
    Receive an item from an OSAL Queue. The item is received by copy so a buffer of
    adequate size must be provided. The number of bytes copied into the buffer
    was defined when the queue was created.
    Successfully received items are removed from the queue.
    This function must not be used in an interrupt service routine.

  Parameters:
    queID       - A pointer to the queue ID

    buffer      - A pointer to the buffer into which the received item will be copied.
                  The size of the items the queue hold was defined when the queue was created,
                  so this many bytes will be copied from the queue storage area into the buffer.

    waitMS      - Time limit to wait in milliseconds.
                   0 - do not wait
                   OSAL_WAIT_FOREVER - return only when semaphore is obtained
                   Other values - timeout delay

  Returns:
    OSAL_RESULT_TRUE    - An item was successfully received from the queue.
    OSAL_RESULT_FALSE   - An item was not successfully received from the queue
                          or timeout occurred

  Example:
    <code>
    OSAL_RESULT result = OSAL_QUEUE_Receive(&queID, &buffer, OSAL_WAIT_FOREVER);
    </code>

  Remarks:
*/
OSAL_RESULT OSAL_QUEUE_Receive(OSAL_QUEUE_HANDLE_TYPE *queID, void  *buffer, uint32_t waitMS)
{
    TickType_t timeout = 0;

    if (OSAL_WAIT_FOREVER == waitMS)
    {
        timeout = portMAX_DELAY;
    }
    else
    {
        timeout = (TickType_t)(waitMS / portTICK_PERIOD_MS);
    }
    if (pdTRUE == xQueueReceive(*queID, buffer, timeout))
    {
        return OSAL_RESULT_TRUE;
    }
    else
    {
        return OSAL_RESULT_FALSE;
    }
}

/*******************************************************************************
  Function:
    OSAL_RESULT OSAL_QUEUE_IsFullISR(OSAL_QUEUE_HANDLE_TYPE *queID)

  Summary:
    Query if an OSAL Queue is full.

  Description:
    Query if an OSAL Queue is full.
    These function should be used only from witin an ISR, or within a critical section.

  Parameters:
    queID       - A pointer to the queue ID

  Returns:
    OSAL_RESULT_TRUE    - The queue is Full.
    OSAL_RESULT_FALSE   - The queue is not Full.

  Example:
    <code>
    OSAL_RESULT result = OSAL_QUEUE_IsFullISR(&queID);
    </code>

  Remarks:
*/
OSAL_RESULT OSAL_QUEUE_IsFullISR(OSAL_QUEUE_HANDLE_TYPE *queID)
{
    if (pdTRUE == xQueueIsQueueFullFromISR(*queID))
    {
        return OSAL_RESULT_TRUE;
    }
    else
    {
        return OSAL_RESULT_FALSE;
    }
}

/*******************************************************************************
 End of File
*/

