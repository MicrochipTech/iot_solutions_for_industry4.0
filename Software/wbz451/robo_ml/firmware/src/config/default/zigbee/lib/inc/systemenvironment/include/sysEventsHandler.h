// DOM-IGNORE-BEGIN
/*******************************************************************************
  System events handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysEventsHandler.h

  Summary:
    Interface for subscription to event facility.

  Description:
    Interface for subscription to event facility.
 *******************************************************************************/


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

// DOM-IGNORE-BEGIN
#ifndef _SYS_EVENTS_HANDLER_H
#define _SYS_EVENTS_HANDLER_H
// DOM-IGNORE-END

#include <systemenvironment/include/sysTypes.h>
#include <limits.h>
#include <systemenvironment/include/sysUtils.h>

/**************************************************************************
                   Defines section
 *************************************************************************/
/** The maximum number of events that can be defined in the System Environment.
Any event ID must not be greater than this value.  */
#define SYS_MAX_EVENTS 91U

#define SYS_EVENTS_MASK_SIZE CEIL(SYS_MAX_EVENTS, sizeof(sysEvWord_t) * 8U)

/******************************************************************************
                   Types section
******************************************************************************/
/** \brief The type for event identifier

Note that identifiers of events raised by the stack are defined
in the ::BcEvents_t enumeration. The user can define its own set of
event IDs in the application, subscribe to them and raise them,
though the overall number of event IDs defined by both the stack and
the application can not be greater than ::SYS_MAX_EVENTS, and
an event ID value must not be greater than ::SYS_MAX_EVENTS.
*/
typedef uint8_t SYS_EventId_t;

/** Data for event. Arbitrary unsigned integer, but large enough to
hold pointer if required (such use is generally discouraged). */
typedef uintptr_t SYS_EventData_t;

// Select native types for 8-bit and 32-bit machines
#if UINT_MAX < 0xFFFFFFFFULL
typedef uint8_t sysEvWord_t;
#else
typedef uint32_t sysEvWord_t;
#endif

// Internal service fields for handler.
typedef struct
{
  struct _SYS_EventReceiver_t *next;
  sysEvWord_t evmask[SYS_EVENTS_MASK_SIZE];
} SYS_EventService_t;
/** \brief Structure for declaring an event receiver */
typedef struct _SYS_EventReceiver_t
{
  // Internal service fields for handler.
  // Do not rely on them.
  // They may be changed at future releases.
  //\cond internal
  SYS_EventService_t service;
  //\endcond

  /** Function to be called on event. Must not be set to NULL. */
  void (*func)(SYS_EventId_t id, SYS_EventData_t data);
} SYS_EventReceiver_t;

/******************************************************************************
                   Prototypes section
 ******************************************************************************/

/**************************************************************************//**
  \brief Subscribe a receiver to an event. The same receiver may be subscribed to
  multiple events by calling this function several times.

  ingroup sys

  \param id - event ID
         recv - receiver's descriptor
  \return None
 ******************************************************************************/
void SYS_SubscribeToEvent(SYS_EventId_t id, SYS_EventReceiver_t *recv);

/**************************************************************************//**
  \brief Unsubscribe a receiver from an event

  ingroup sys

  \param id - event ID
         recv - receiver's descriptor
  \return None
 ******************************************************************************/
void SYS_UnsubscribeFromEvent(SYS_EventId_t id, SYS_EventReceiver_t *recv);

/**************************************************************************//**
  \brief Post an event to be delivered to all subscribed receivers

  ingroup sys

  \param id - event ID
         data - associated data that will be passed to callback functions
                of event's receivers
  \return None
 ******************************************************************************/
void SYS_PostEvent(SYS_EventId_t id, SYS_EventData_t data);

/**************************************************************************//**
  \brief Check if event have at least one subscriber

  ingroup sys

  \param[in] id - event ID
  \return result
 ******************************************************************************/
bool SYS_IsEventDeliverable(SYS_EventId_t id);

/**************************************************************************//**
  \brief Check if the specified receiver is subscribed to an event

  ingroup sys

  \param id - event ID
         recv - receiver's descriptor

   \return result
 ******************************************************************************/
bool SYS_IsEventSubscriber(SYS_EventId_t id, SYS_EventReceiver_t *recv);

/**************************************************************************//**
  \brief Clear the events

  ingroup sys
  
  \return None
 ******************************************************************************/
void SYS_ClearEvents(void);


#endif  // _SYS_EVENTS_HANDLER_H
/** eof sysEventsHandler.h */
