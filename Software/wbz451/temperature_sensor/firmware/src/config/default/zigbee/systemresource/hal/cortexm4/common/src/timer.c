/*******************************************************************************
  HAL Timer Source File

  Company:
    Microchip Technology Inc.

  File Name:
    timer.c

  Summary:
    This file defines the Functions to manipulate timers list used by the stack Component 
    and the application.

  Description:
    This file defines the Functions to manipulate timers list used by the stack Component 
    and the application.
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


/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/

/******************************************************************************
                   Includes section
******************************************************************************/
#include <hal/include/bcTimer.h>

/******************************************************************************
                   Implementations section
******************************************************************************/
/******************************************************************************
Adds timer to the timer's list.
Parameters:
  head - address of pointer to head of the timers list.
  timer - address of timer that must be added to the list.
  sysTime - current time.
Returns:
  none.
******************************************************************************/
void halAddTimer(BC_Timer_t **head, BC_Timer_t *newTimer, uint32_t sysTime)
{
  if (!*head)
  {
    *head = newTimer;
    return;
  }

  BC_Timer_t *it, *prev = NULL;
  for (it = *head; it; it = it->service.next)
  {
    uint64_t remain;
    if (it->service.sysTimeLabel <= sysTime)
      remain = (uint64_t)(it->service.sysTimeLabel) + it->interval - sysTime;
    else
      remain = (uint64_t)it->interval - ((uint32_t)~it->service.sysTimeLabel + 1) - sysTime;
    if ((remain <= UINT32_MAX) && (remain >= newTimer->interval))
      break;
    prev = it;
  }
  if (it == *head)
  {
    newTimer->service.next = *head;
    *head = newTimer;
  }
  else
  {
    prev->service.next = newTimer;
    newTimer->service.next = it;
  }
}

/******************************************************************************
Removes timer from the timers list.
Parameters:
  head - address of pointer to head of the timers list.
  prev - address of the timer before the timer that must be removed from the list.
  p - address of timer that must be removed from the list.
Returns:
  pointer to next cell or pointer to head if deleting is head
******************************************************************************/
BC_Timer_t* halRemoveTimer(BC_Timer_t **head, BC_Timer_t *prev, BC_Timer_t *p)
{
  BC_Timer_t *t;
  if (p == *head)
  {// removing first element of list
    t = p->service.next;
    p->service.next = 0;
    *head = t;
    return *head;
  }
  else
  {
    if(prev != NULL)
	{
		prev->service.next = p->service.next;
		p->service.next = 0;
		return prev->service.next;
	}
	else
	{
		return *head;
	}
  }
}

/******************************************************************************
The search of the timer in the timers list before one.
Parameters:
  head - address of pointer to head of the timers list.
Returns:
  pointer to saerching timer
******************************************************************************/
BC_Timer_t *halFindPrevTimer(BC_Timer_t **head,  BC_Timer_t *p)
{
  BC_Timer_t *t = *head;

  for (; t ;)
  {
    if (t->service.next == p)
      return t;
    t = t->service.next;
  }
  return NULL;
}

//eof timer.c
