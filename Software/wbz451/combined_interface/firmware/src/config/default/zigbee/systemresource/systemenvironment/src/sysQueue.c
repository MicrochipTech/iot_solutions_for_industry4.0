/*******************************************************************************
  System queue Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysQueue.c

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

/*********************************************************************************
                          Includes section.
**********************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysQueue.h>
#include <systemenvironment/include/sysDbg.h>
#include <systemenvironment/include/sysAssert.h>

/***************************************************************************
  Put a element to a queue. Element is added to the tail
  Parameters:
    queue   - pointer to a queue descriptor
    element - pointer to new element
  Returns:
    True - succesfully queued, False - not queued
****************************************************************************/
bool putQueueElem(QueueDescriptor_t *queue, void *element)
{

  if (isQueueElem(queue, element))
  {
    SYS_E_ASSERT_ERROR(false, SYS_ASSERT_ID_DOUBLE_QUEUE_PUT);
    return false;
  }

  ((QueueElement_t*)element)->next = NULL;
  if(!queue->head)
    queue->head = element;
  else
  {
    QueueElement_t *last = queue->head;
    while(last->next)
      last = last->next;
    last->next = element;
  }

  return true;
}

/***************************************************************************
  Delete a head element from a queue. Element is deleted from the head
  Parameters:
    queue - pointer to a queue descriptor
  Returns:
    TRUE  - element is removed successfully
    FALSE - queue is empty
****************************************************************************/
void* deleteHeadQueueElem(QueueDescriptor_t *queue)
{
  if(queue->head)
  {
    void *retval = queue->head;
    queue->head = queue->head->next;
    return retval;
  }
  else
  {
    return NULL;
  }
}

/***************************************************************************
  Delete the certain element of a queue.
  Parameters:
    element - element to be deleted
    queue   - pointer to a queue descriptor
  Returns:
    true if element was removed otherwise false
****************************************************************************/
bool deleteQueueElem(QueueDescriptor_t *queue, void *element)
{
  if (element)
  {
    if(queue->head == element)
    {
      queue->head = queue->head->next;
      return true;
    }
    else
    {
      QueueElement_t *prev = queue->head;
      while (prev && prev->next != element)
        prev = prev->next;
      if (prev)
      {
        prev->next = prev->next->next;
        return true;
      }
    }
  }
  return false;
}

/***************************************************************************
  Check if element is a member of specified queue.
  Parameters:
    queue - pointer to a queue descriptor
    element - pointer to an element
  Returns:
    True - if element is a queue member, false - otherwise.
****************************************************************************/
bool isQueueElem(const QueueDescriptor_t *const queue, const void *const element)
{
  QueueElement_t *it;

  for (it = queue->head; it; it = it->next)
    if (it == element)
      return true;

  return false;
}

//eof sysQueue.c
