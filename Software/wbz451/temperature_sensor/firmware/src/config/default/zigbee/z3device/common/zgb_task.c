/*******************************************************************************
  Zgb task Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zgb_task.c

  Summary:
    This file contains the Zgb task implementation.

  Description:
    This file contains the Zgb task implementation.
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

#include <framework_defs.h>
#include <queue.h>
#include <z3device/clusters/include/haClusters.h>
#include <z3device/stack_interface/zcl/include/ZCL_Unpack.h>
#include <z3device/stack_interface/nwk/include/NWK_Unpack.h>
#include <z3device/stack_interface/zdo/include/ZDO_Unpack.h>
#include <z3device/stack_interface/configServer/include/CS_Unpack.h>

/* Counting semaphore length to handle internal task processing */
#define ZB_STACK_INTERNAL_SEM_LENGTH	20


static Stack_API_Request_t *apiReq;

static QueueSetHandle_t xQueueSet;
static QueueSetMemberHandle_t xActivatedMember;

OSAL_QUEUE_HANDLE_TYPE apiRequestQueueHandle; // Queue Pointer received from Application

OSAL_SEM_HANDLE_TYPE semStackInternalHandler;

OSAL_API_LIST_TYPE *zos;

/*******************************************************************************
   OS Task Handler for Zigbee Stack 
   Handles both API request from Applicaion layer and also internal scheduling

*/
void zigbee_task(void *const ptr)
{
  zos->OSAL_SEM_Create(&semStackInternalHandler, OSAL_SEM_TYPE_COUNTING,ZB_STACK_INTERNAL_SEM_LENGTH, 0);
  
  /* Create the queue set large enough to hold an event for every space in
    every queue and semaphore that is to be added to the set. */
  zos->OSAL_QUEUE_CreateSet(&xQueueSet, QUEUE_LENGTH + ZB_STACK_INTERNAL_SEM_LENGTH);

  /* Add the queues and semaphores to the set.  Reading from these queues and
  semaphore can only be performed after a call to xQueueSelectFromSet() has
  returned the queue or semaphore handle from this point on. */
  zos->OSAL_QUEUE_AddToSet( &apiRequestQueueHandle, &xQueueSet );
  zos->OSAL_QUEUE_AddToSet( &semStackInternalHandler, &xQueueSet );
  
  ZB_SysTaskInit();
  halStartAppClock();
  while (1)
  {
    /* Block to wait for something to be available from the queues or
     semaphore that have been added to the set.*/
     zos->OSAL_QUEUE_SelectFromSet(&xActivatedMember, &xQueueSet, OSAL_WAIT_FOREVER );

    /* Which set member was selected?  Receives/takes can use a block time
    of zero as they are guaranteed to pass because xQueueSelectFromSet()
    would not have returned the handle unless something was available. */
    
    if( xActivatedMember == semStackInternalHandler )
    {
      /*Process Internal Stack Events*/
      zos->OSAL_SEM_Pend(&semStackInternalHandler, 0);
      SYS_RunTask();
    }
    else if( xActivatedMember == apiRequestQueueHandle )
    {
      zos->OSAL_QUEUE_Receive(&apiRequestQueueHandle, &apiReq, 0);
      apiReq->unpack_fn(apiReq->parameters);
    }
    else
    {
      // ASSERT
    }

  }
}
