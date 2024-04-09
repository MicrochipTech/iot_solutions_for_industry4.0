/*******************************************************************************
  System Events handlers Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysEventsHandler.c

  Summary:
    This file contains the Event facility.

  Description:
    This file contains the Event facility.
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
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysQueue.h>
#include <systemenvironment/include/sysDbg.h>
#include <systemenvironment/include/sysEvents.h>
#include <systemenvironment/include/sysAssert.h>

/******************************************************************************
                    Static variables section
******************************************************************************/
// Queue of registered event receivers
static DECLARE_QUEUE(eventReceivers);
// Mask for fast query if event have at least one subscriber
static sysEvWord_t subscribed[SYS_EVENTS_MASK_SIZE];

static const unsigned int evWordNBits = sizeof(sysEvWord_t) * 8U;

/******************************************************************************
                    global variables section
******************************************************************************/
//#if defined ZAPPSI_HOST || defined ZAPPSI_NP
#if defined(ZAPPSI_NP) || defined (ZAPPSI_HOST)
ZsiSysPostEvent_t postEventData;
#endif

#ifdef ZAPPSI_NP
extern bool stackInitDone;
#endif

/******************************************************************************
                    Static functions section
******************************************************************************/
#ifdef ZAPPSI_NP
static bool sysIsInternalEvent(SYS_EventId_t eventId);
#endif
/******************************************************************************
                    Implementation section
******************************************************************************/

/**************************************************************************//**
\brief Subscribe receiver to event. Same receiver may be subscribed to
multiple events by calling this function several times

\param[in] id - event id
\param[in] recv - receiver description
******************************************************************************/
void SYS_SubscribeToEvent(SYS_EventId_t id, SYS_EventReceiver_t *recv)
{
  const int pos = id / evWordNBits;
  const sysEvWord_t mask = 1U << (id % evWordNBits);

  SYS_E_ASSERT_FATAL((id <  SYS_MAX_EVENTS), SYS_ASSERT_WRONG_EVENT_SUBSCRIBE);

  // Stop processing, if receiver is already subscribed.
  if (SYS_IsEventSubscriber(id, recv))
    return;

  if (!isQueueElem(&eventReceivers, recv))
  {
    // Clear events mask (we're not in queue and therefore not subscribed to any event)
    memset(recv->service.evmask, 0U, sizeof(recv->service.evmask));
    putQueueElem(&eventReceivers, recv);
  }

  // Update receiver's mask and fast query mask
  recv->service.evmask[pos] |= mask;
  subscribed[pos] |= mask;
}

/**************************************************************************//**
\brief Unsubscribe receiver from event

\param[in] id - event id
\param[in] recv - receiver description
******************************************************************************/
void SYS_UnsubscribeFromEvent(SYS_EventId_t id, SYS_EventReceiver_t *recv)
{
  const int pos = id / evWordNBits;
  const sysEvWord_t mask = 1U << (id % evWordNBits);
  bool more_subscribers = false;

  SYS_E_ASSERT_FATAL((id < SYS_MAX_EVENTS), SYS_ASSERT_WRONG_EVENT_SUBSCRIBE);

  // Stop processing, if receiver wasn't subscribed.
  if (!SYS_IsEventSubscriber(id, recv))
    return;

  // Update receiver's mask
  recv->service.evmask[pos] &= ~mask;

  // Look if there is more subscribers for event
  for (const SYS_EventReceiver_t *hnd = getQueueElem(&eventReceivers); hnd; hnd = getNextQueueElem(hnd))
  {
    if (hnd->service.evmask[pos] & mask)
    {
      more_subscribers = true;
      break;
    }
  }

  // No more subscribers for event. Update fast query mask.
  if (!more_subscribers)
    subscribed[pos] &= ~mask;

// Dequeuing receiver is dangerous since user could unsubscribe and modify queue
// while being called by PostEvent's event delivery loop. Disabled for now.
#if 0
  for (int i = ARRAY_SIZE(recv->service.evlist), i, i--)
  {
    if (recv->service.evlist[i])
      return;
  }
  // No more subscriptions, dequeue receiver
  deleteQueueElem(eventReceivers, recv);
#endif
}

/**************************************************************************//**
\brief Post an event to be delivered to all subscribed receivers

\param[in] id - event id
\param[in] data - associated data
******************************************************************************/
void SYS_PostEvent(SYS_EventId_t id, SYS_EventData_t data)
{
  const int pos = id / evWordNBits;
  const sysEvWord_t mask = 1U << (id % evWordNBits);

  SYS_E_ASSERT_FATAL((id <  SYS_MAX_EVENTS), SYS_ASSERT_WRONG_EVENT_POST);
#ifndef ZAPPSI_NP
  if (!(subscribed[pos] & mask))  // There is no one listening
    return;
#endif
  for (const SYS_EventReceiver_t *hnd = getQueueElem(&eventReceivers); hnd; hnd = getNextQueueElem(hnd))
  {
    if (hnd->service.evmask[pos] & mask)
    {
      SYS_E_ASSERT_FATAL(hnd->func, SYS_POSTEVENT_NULLCALLBACK0);
      hnd->func(id, data);
    }
  }
#ifdef ZAPPSI_NP
  if (ZSI_IsStackInitDone() && !sysIsInternalEvent(id) && ZSI_IsStackResetDone())
  {
      postEventData.id = id;
      memcpy(&postEventData.data, &data, sizeof(SYS_EventData_t)); //local pointer
    /* updated Event data is required in te confirmation */
    if ((BC_EVENT_ACCESS_REQUEST == id) || (BC_EVENT_TC_ACCESS_REQUEST == id))
    {
      BcAccessReq_t* bcAccessReq = (BcAccessReq_t*)postEventData.data.uint8ptr;
      if( bcAccessReq->action != BC_FRAME_FILTERING_BY_PROFILE_ID_ACTION)
        zsiProcessCommand(ZSI_SREQ_CMD, &postEventData, zsiSerializeSYS_PostEventReq, &postEventData);
    }
    else
    {
       zsiProcessCommand(ZSI_SREQ_NR_CMD, &postEventData, zsiSerializeSYS_PostEventReq, NULL);
    }
  }
#endif  //#ifdef ZAPPSI_NP
}

/**************************************************************************//**
\brief Check if event have at least one subscriber

\param[in] id - event if
\return result
******************************************************************************/
bool SYS_IsEventDeliverable(SYS_EventId_t id)
{
  return subscribed[id / evWordNBits] & (1U << (id % evWordNBits));
}

/**************************************************************************//**
\brief Check if specified receiver is subscribed to event.

\param[in] id - event if
\param[in] recv - receiver description

\return result
******************************************************************************/
bool SYS_IsEventSubscriber(SYS_EventId_t id, SYS_EventReceiver_t *recv)
{
  const int pos = id / evWordNBits;
  const sysEvWord_t mask = 1U << (id % evWordNBits);

  return recv->service.evmask[pos] & mask;
}

/**************************************************************************//**
\brief Clear the events

\ingroup sys

******************************************************************************/
void SYS_ClearEvents(void)
{
  int pos;
  for(pos = 0; pos < SYS_EVENTS_MASK_SIZE; pos++)
  {
  	subscribed[pos] = 0x0;
  }
}

#ifdef ZAPPSI_NP
/**************************************************************************//**
\brief to check whther the event is posted and subscribed with in NP

\param[in] id - event id
\return result - true if it is internal , false otherwise
******************************************************************************/
static bool sysIsInternalEvent(SYS_EventId_t eventId)
{
  switch (eventId)
  {
     /* internal to the NP */
    case BC_EVENT_MAC_TX_SUCCESS:
    case BC_EVENT_APS_DATA_INDICATION:
    case BC_ZSI_LOST_SYNCHRONIZATION:
    case SYS_EVENT_TASK_PROCESSED:
    case BC_EVENT_NWK_DATA_CONFIRM:

    /* These events are used only to store the corresponding PDS items
       which are internal to the NP */
    case BC_EVENT_KEY_PAIR_DELETED:
    case BC_EVENT_APS_SECURITY_TABLES_UPDATED:
    case BC_SECURITY_APS_COUNTERS_UPDATE:
    case BC_EVENT_NWK_SECURITY_TABLES_UPDATED:
    case BC_EVENT_BIND_TABLE_UPDATED:
    case BC_EVENT_GROUP_TABLE_UPDATED:
    case BC_EVENT_GROUPS_REMOVED:
    case BC_SECURITY_NWK_COUNTERS_UPDATE:
    case BC_EVENT_NWK_RREQ_ID_UPDATED:
      return true;

    /* diagnostic events */
    case BC_EVENT_APS_BCAST_DATA_INDICATION:
    case BC_EVENT_APS_TX_UCAST_RETRY:
    case BC_EVENT_ROUTE_DISC_INITIATED:
    case BC_EVENT_PACKET_BUFFER_ALLOCATE_FAIL:
    case BC_EVENT_MAC_RX_BCAST:
    case BC_EVENT_MAC_TX_BCAST:
    case BC_EVENT_MAC_RX_UCAST:
    case BC_EVENT_MAC_TX_UCAST:
    case BC_EVENT_MAC_TX_UCAST_FAIL:
    case BC_EVENT_APS_RX_UCAST:
    case BC_EVENT_APS_TX_UCAST_SUCCESS:
    case BC_EVENT_NWK_ADD_NEIGHBOR:
    case BC_EVENT_NWK_REMOVE_NEIGHBOR:
    case BC_EVENT_NWK_STALE_NEIGHBOR:
    case BC_EVENT_MAC_TX_BCAST_CH_ACCESS_FAIL:
      return true;

    default:
      return false;

  }
}
#endif //#ifdef ZAPPSI_NP
