/*******************************************************************************
  System queue Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysQueue.h

  Summary:
    This file contains the functions for accessing system queues.

  Description:
    This file contains the functions for accessing system queues.
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

#ifndef _SYSQUEUE_H
#define _SYSQUEUE_H

#include <systemenvironment/include/sysTypes.h>

/***************************************************************************
  Declare a queue and reset to the default state
  Every queue should be declared with this macros!
  Any queue element passed as parameter to functions should have as first
  field pointer for adding to a queue.

  Parameters:
    queue - the name of object.
  Returns:
    None
****************************************************************************/
#define DECLARE_QUEUE(queue) QueueDescriptor_t queue = {.head = NULL,}

// Type of queue element
typedef struct _QueueElement_t
{
  struct _QueueElement_t *next;
} QueueElement_t;

// Queue descriptor
typedef struct
{
  QueueElement_t *head;
} QueueDescriptor_t;

/***************************************************************************
  Reset a queue
  Parameters:
    queue - pointer to a queue descriptor
  Returns:
    None
****************************************************************************/
INLINE void resetQueue(QueueDescriptor_t *queue)
{
  queue->head = NULL;
}

/***************************************************************************
  Get a element from a queue. Element is got from the head
  Parameters:
    queue - pointer to a queue descriptor
  Returns:
    None
****************************************************************************/
INLINE void *getQueueElem(const QueueDescriptor_t *queue)
{
  return queue->head;
}

/***************************************************************************
  Get next element of queue after current element. The movement is made from
  head to tail. At the beginning of looking for elements the head element
  should be obtained.
  Parameters:
    currElement - current element
  Returns:
    NULL     - no next element
    NOT NULL - next element is got
****************************************************************************/
INLINE void* getNextQueueElem(const void *currElem)
{
  return currElem? ((const QueueElement_t*) currElem)->next: NULL;
}

bool isQueueElem(const QueueDescriptor_t *const queue, const void *const element);
bool putQueueElem(QueueDescriptor_t *queue, void *element);
void *deleteHeadQueueElem(QueueDescriptor_t *queue);
bool  deleteQueueElem(QueueDescriptor_t *queue, void *element);

#endif
//eof sysQueue.h
