/*******************************************************************************
  Bitcloud PDS Source File

  Company:
    Microchip Technology Inc.

  File Name:
    bcPDS.c

  Summary:
    This file contains Bitcloud specific PDS defines and implementation.

  Description:
    This file contains Bitcloud specific PDS defines and implementation.
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
#ifdef _ENABLE_PERSISTENT_SERVER_
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysAssert.h>
#include <pds/include/wlPdsMemIds.h>
#include <pds/include/wlPdsTypesConverter.h>
#include <pds/include/bcPDS.h>
#include <zllplatform/infrastructure/N_ErrH/include/N_ErrH.h>

/******************************************************************************
                    External variables section
******************************************************************************/
#define COMPID "bcPds"

//Bitwise OR of item id's associated with individual events: HASH_EVENT = (Itemid1 | ItemId2)
#define  HASH_NETWORK_ENTERED_EVENT                0x3F6 
#define  HASH_NETWORK_STARTED_EVENT                0x3F6
#define  HASH_NETWORK_LEFT_EVENT                   0x3F6
#define  HASH_NETWORK_UPDATE_EVENT                 0x02
#define  HASH_CHILD_JOINED_EVENT                   0x04
#define  HASH_CHILD_REMOVED_EVENT                  0x04
#define  HASH_KEY_PAIR_DELETED_EVENT               0x08
#define  HASH_APS_SECURITY_TABLES_UPDATED_EVENT    0x08
#define  HASH_APS_COUNTERS_UPDATED_EVENT           0x08
#define  HASH_NWK_SECURITY_TABLES_UPDATED_EVENT    0x70
#define  HASH_BIND_TABLES_UPDATED_EVENT            0x80
#define  HASH_GROUP_TABLES_UPDATED_EVENT           0x100
#define  HASH_GROUP_REMOVED_EVENT                  0x100
#define  HASH_NWK_COUNTERS_UPDATED_EVENT           0x40
#define  HASH_NWK_REQ_ID_UPDATED_EVENT             0x200
#define  HASH_CHANNEL_CHANGED_EVENT                0x02

#define EVENT_TO_MEM_ID_MAPPING(event, id)  {.eventId = event, .itemId = id}

typedef enum
{
  NETWORK_ENTERED_EVENT,
  NETWORK_STARTED_EVENT,
  NETWORK_LEFT_EVENT,
  NETWORK_UPDATE_EVENT,
  CHILD_JOINED_EVENT,
  CHILD_REMOVED_EVENT,
  KEY_PAIR_DELETED_EVENT,
  APS_SECURITY_TABLES_UPDATED_EVENT,
  APS_COUNTERS_UPDATED_EVENT,
  NWK_SECURITY_TABLES_UPDATED_EVENT,
  BIND_TABLES_UPDATED_EVENT,
  GROUP_TABLES_UPDATED_EVENT,
  GROUP_REMOVED_EVENT,
  NWK_COUNTERS_UPDATED_EVENT,
  NWK_REQ_ID_UPDATED_EVENT,
  CHANNEL_CHANGED_EVENT,
  BC_PDS_MAX_EVENT
}EventsInPDS_t;

typedef struct _EventToMemoryIdMapping_t
{
  uint8_t        eventId;
  PDS_MemId_t    itemId;
} EventToMemoryIdMapping_t;

#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
extern OSAL_SEM_HANDLE_TYPE semZgpInternalHandler;
#endif
/******************************************************************************
                    Prototypes section
******************************************************************************/
extern bool pdsUpdateMemoryCallback(PDS_UpdateMemory_t *pdsUpdateMem);
extern bool PDS_storeOffset(PDS_Operation_Offset_t *item);
static void pdsObserver(SYS_EventId_t eventId, SYS_EventData_t data);
static uint8_t pdsgetLookupTableIndex(SYS_EventId_t eventId);
static void pdsDataStoreCallback(PDS_MemId_t itemID);

/******************************************************************************
                    Static variables section
******************************************************************************/

static SYS_EventReceiver_t pdsEventReceiver = { .func = pdsObserver};

#ifndef PDS_SECURITY_CONTROL_ENABLE
static void pdsTableEventObserver(SYS_EventId_t eventId, SYS_EventData_t data);
static SYS_EventReceiver_t pdsTableEventReceiver = { .func = pdsTableEventObserver};

/* Memory map, shows relationships between BitCloud events and BC Table Items memory which
   is updated on specific event. Such memory should be updated in non-volatile
   storage on an event occurrence. */

static EventToMemoryIdMapping_t PROGMEM_DECLARE(pdsTableItemMemoryMap[]) =
{
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_APS_SECURITY_TABLES_UPDATED, CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_SECURITY_APS_COUNTERS_UPDATE,      CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID)
};

#endif //#ifndef PDS_SECURITY_CONTROL_ENABLE

/* Memory map, shows relationships between BitCloud events and memory which
   is updated on specific event. Such memory should be updated in non-volatile
   storage on an event occurrence. */
static EventToMemoryIdMapping_t PROGMEM_DECLARE(pdsMemoryMap[]) =
{
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             BC_EXT_GEN_MEMORY_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             CS_NEIB_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             CS_NWK_SECURITY_IB_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             CS_NWK_SECURITY_KEYS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             NWK_SECURITY_COUNTERS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             CS_APS_BINDING_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             CS_GROUP_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_ENTERED,             NWK_RREQ_IDENTIFIER_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             BC_EXT_GEN_MEMORY_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             CS_NEIB_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             CS_NWK_SECURITY_IB_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             CS_NWK_SECURITY_KEYS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             NWK_SECURITY_COUNTERS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             CS_APS_BINDING_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             CS_GROUP_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_STARTED,             NWK_RREQ_IDENTIFIER_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                BC_EXT_GEN_MEMORY_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                CS_NEIB_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                CS_NWK_SECURITY_IB_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                NWK_SECURITY_COUNTERS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                CS_NWK_SECURITY_KEYS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                CS_APS_BINDING_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                CS_GROUP_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_LEFT,                NWK_RREQ_IDENTIFIER_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NETWORK_UPDATE,              BC_EXT_GEN_MEMORY_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_CHILD_JOINED,                CS_NEIB_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_CHILD_REMOVED,               CS_NEIB_TABLE_ITEM_ID),

#ifdef PDS_SECURITY_CONTROL_ENABLE

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_KEY_PAIR_DELETED,            CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_APS_SECURITY_TABLES_UPDATED, CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_SECURITY_APS_COUNTERS_UPDATE,      CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID),

#endif

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NWK_SECURITY_TABLES_UPDATED, CS_NWK_SECURITY_IB_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NWK_SECURITY_TABLES_UPDATED, CS_NWK_SECURITY_KEYS_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NWK_SECURITY_TABLES_UPDATED, NWK_SECURITY_COUNTERS_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_TC_MODE_CHANGED,             BC_EXT_GEN_MEMORY_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_BIND_TABLE_UPDATED,          CS_APS_BINDING_TABLE_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_GROUP_TABLE_UPDATED,         CS_GROUP_TABLE_ITEM_ID),
  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_GROUPS_REMOVED,              CS_GROUP_TABLE_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_SECURITY_NWK_COUNTERS_UPDATE,      NWK_SECURITY_COUNTERS_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_NWK_RREQ_ID_UPDATED,         NWK_RREQ_IDENTIFIER_ITEM_ID),

  EVENT_TO_MEM_ID_MAPPING(BC_EVENT_CHANNEL_CHANGED,             BC_EXT_GEN_MEMORY_ITEM_ID)
};
static uint16_t eventsSubscribedFlag;
static uint16_t eventToBeProcessedFlag;

static uint16_t eventToItemLookpupTable[BC_PDS_MAX_EVENT] =
{
  HASH_NETWORK_ENTERED_EVENT, HASH_NETWORK_STARTED_EVENT, HASH_NETWORK_LEFT_EVENT,
  HASH_NETWORK_UPDATE_EVENT, HASH_CHILD_JOINED_EVENT, HASH_CHILD_REMOVED_EVENT,
  HASH_KEY_PAIR_DELETED_EVENT, HASH_APS_SECURITY_TABLES_UPDATED_EVENT,
  HASH_APS_COUNTERS_UPDATED_EVENT, HASH_NWK_SECURITY_TABLES_UPDATED_EVENT,
  HASH_BIND_TABLES_UPDATED_EVENT, HASH_GROUP_TABLES_UPDATED_EVENT,
  HASH_GROUP_REMOVED_EVENT, HASH_NWK_COUNTERS_UPDATED_EVENT,
  HASH_NWK_REQ_ID_UPDATED_EVENT, HASH_CHANNEL_CHANGED_EVENT
};

static uint16_t eventItemBitMask[BC_PDS_MAX_EVENT];

static uint8_t pdsEventIdTable[BC_PDS_MAX_EVENT] =
{
   BC_EVENT_NETWORK_ENTERED,
   BC_EVENT_NETWORK_STARTED,
   BC_EVENT_NETWORK_LEFT,
   BC_EVENT_NETWORK_UPDATE,
   BC_EVENT_CHILD_JOINED,
   BC_EVENT_CHILD_REMOVED,
   BC_EVENT_KEY_PAIR_DELETED,
   BC_EVENT_APS_SECURITY_TABLES_UPDATED,
   BC_SECURITY_APS_COUNTERS_UPDATE,
   BC_EVENT_NWK_SECURITY_TABLES_UPDATED,
   BC_EVENT_BIND_TABLE_UPDATED,
   BC_EVENT_GROUP_TABLE_UPDATED,
   BC_EVENT_GROUPS_REMOVED,
   BC_SECURITY_NWK_COUNTERS_UPDATE,
   BC_EVENT_NWK_RREQ_ID_UPDATED,
   BC_EVENT_CHANNEL_CHANGED
};
/******************************************************************************
                    Prototypes section
******************************************************************************/

/******************************************************************************
                    Implementation section
******************************************************************************/

#ifndef ZAPPSI_HOST
void ZB_PDS_Init (void)
{
    uint32_t stackVersion;
    bool isStackVersionValid = false;
#ifdef PDS_SECURITY_CONTROL_ENABLE
    pdsSecurityPerformMigration();
#endif
    PDS_RegisterWriteCompleteCallback(pdsDataStoreCallback);
    PDS_RegisterUpdateMemoryCallback(pdsUpdateMemoryCallback);

    if (PDS_IsAbleToRestore(BC_STACK_VERSION_MEM_ID))
    {
      if (PDS_Restore(BC_STACK_VERSION_MEM_ID))
      {
#ifndef _MAC2_
        CS_ReadParameter(CS_STACK_VERSION_ID, &stackVersion);
        if (CS_STACK_VERSION == stackVersion)
        {
          isStackVersionValid = true;
        }
        else
        {
          /*Place holder to handle upgrade changes if necessary*/
        }
#endif
      }
    }
    if (false == isStackVersionValid)
    {
#ifndef _MAC2_
      stackVersion = CS_STACK_VERSION;
      CS_WriteParameter(CS_STACK_VERSION_ID, &stackVersion);
#endif

      PDS_Store(BC_STACK_VERSION_MEM_ID);

    }
#ifndef PDS_SECURITY_CONTROL_ENABLE
    if (!PDS_IsAbleToRestore(CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID))
    {
      // This is to store the initial key(set as part of stack init) 
      // for FN device if not stored prev
      PDS_StoreByEvents(CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID);
    }
#endif
    PDS_AddItemExcpetionFromDeleteAll(NWK_SECURITY_COUNTERS_ITEM_ID);

}
#endif


/******************************************************************************
\brief PDS observer routine. Force parameters storing by an event occurrence

\param[in] eventId - occured event identifier;
\param[in] data    - associated data
******************************************************************************/
static void pdsObserver(SYS_EventId_t eventId, SYS_EventData_t data)
{
  EventToMemoryIdMapping_t evMemoryIdMapping;
  bool post = false;

  for (uint8_t i = 0U; i < ARRAY_SIZE(pdsMemoryMap); i++)
  {
    memcpy_P(&evMemoryIdMapping, &pdsMemoryMap[i], sizeof(EventToMemoryIdMapping_t));

    if (evMemoryIdMapping.eventId == eventId)
    {
      uint8_t eventIndex = pdsgetLookupTableIndex(eventId);
      if((1 << eventIndex) & (eventsSubscribedFlag) )
      {
        eventToBeProcessedFlag |= (1<<eventIndex);
        eventItemBitMask[eventIndex] = 0x00;
      }
      PDS_Store(evMemoryIdMapping.itemId);
    }
  }
  (void)data;
}

/**************************************************************************//**
\brief Provides PDS with information about memory that should be kept up-to-date
       in the non-volatile storage
       Data will be saved im non-volatile memory upon specific events

\param[in] memoryId - an identifier of PDS file or directory to be stored
                      in non-volatile memory
******************************************************************************/
void PDS_StoreByEvents(PDS_MemId_t memoryId)
{
#ifdef ZAPPSI_HOST
  if(pdsIsHostPdsItem(memoryId))
#endif
 {
  EventToMemoryIdMapping_t evMemoryIdMapping;

  for (uint8_t i = 0U; i < ARRAY_SIZE(pdsMemoryMap); i++)
  {
    memcpy_P(&evMemoryIdMapping, &pdsMemoryMap[i], sizeof(EventToMemoryIdMapping_t));
    if ((BC_ALL_MEMORY_MEM_ID == memoryId) || (evMemoryIdMapping.itemId == memoryId))
      SYS_SubscribeToEvent(evMemoryIdMapping.eventId, &pdsEventReceiver);
  }

#ifndef PDS_SECURITY_CONTROL_ENABLE
  for(uint8_t i = 0U; i < ARRAY_SIZE(pdsTableItemMemoryMap); i++)
  {
    memcpy_P(&evMemoryIdMapping, &pdsTableItemMemoryMap[i], sizeof(EventToMemoryIdMapping_t));
    if ((BC_ALL_MEMORY_MEM_ID == memoryId) ||(evMemoryIdMapping.itemId == memoryId))
      SYS_SubscribeToEvent(evMemoryIdMapping.eventId, &pdsTableEventReceiver);
  }
#endif
 }
#ifdef ZAPPSI_HOST
 else
   PDS_StoreByEvents_Host(memoryId);
#endif

}

/**************************************************************************//**
\brief Function to look up event id's and match index 

\ingroup pds

\param[in]  eventId   - Event ids   
\return - None
******************************************************************************/
static uint8_t pdsgetLookupTableIndex(SYS_EventId_t eventId)
{
  uint8_t index;
  for (index = 0; index < BC_PDS_MAX_EVENT; index++)
  {
    if (pdsEventIdTable[index] == eventId)
      break;
  }
  return index;
}

#ifndef PDS_SECURITY_CONTROL_ENABLE
/******************************************************************************
\brief PDS Table related Event observer routine.Force parameters storing by an 
       event occurrence

\param[in] eventId - occured event identifier;
\param[in] data    - associated data
******************************************************************************/
static void pdsTableEventObserver(SYS_EventId_t eventId, SYS_EventData_t data)
{
  EventToMemoryIdMapping_t evMemoryIdMapping;

  for (uint8_t i = 0U; i < ARRAY_SIZE(pdsTableItemMemoryMap); i++)
  {
    memcpy_P(&evMemoryIdMapping, &pdsTableItemMemoryMap[i], sizeof(EventToMemoryIdMapping_t));
    if (evMemoryIdMapping.eventId == eventId)
    {
#if defined(_SECURITY_) && defined (_LINK_SECURITY_)
      if (CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID == evMemoryIdMapping.itemId)
      {
        uint8_t entrySize;
        APS_KeyHandle_t keyHandle;
        ItemIdToMemoryMapping_t itemDescr;

        if (PDS_GetItemDescr(evMemoryIdMapping.itemId, &itemDescr))
        {
          N_ERRH_ASSERT_FATAL((0U != itemDescr.itemSize) && (NULL != itemDescr.itemData));

          entrySize = itemDescr.itemSize/CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT;
          keyHandle = *((APS_KeyHandle_t *)data);

          if (PDS_IsAbleToRestore(evMemoryIdMapping.itemId))
          {
            PDS_Operation_Offset_t item;
            item.id       = evMemoryIdMapping.itemId;
            item.offset   = (keyHandle.idx)* entrySize;
            item.size     = entrySize;
            item.ramAddr = (uint8_t*)itemDescr.itemData +(keyHandle.idx * entrySize);
            PDS_storeOffset(&item);
          }
          else
          {
            PDS_Store(evMemoryIdMapping.itemId);
          }
        }
        else
        {
           N_ERRH_ASSERT_FATAL(false);
        }
      }
#endif //#if defined(_SECURITY_) && defined (_LINK_SECURITY_)
    }/*End of if (evMemoryIdMapping.itemId == CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID), can be extended for other table Items */
  }
}
#endif //#ifndef PDS_SECURITY_CONTROL_ENABLE

/**************************************************************************//**
\brief Application Layer subcribes to specific PDS activity and raises an event.
  BC_EVENT_STORING_FINISHED

\ingroup pds

\param[in] EventId   - Event to Subscribe
******************************************************************************/
void PDS_SubscribeToStoreCompletion(SYS_EventId_t EventId)
{
  uint16_t eventBitPos = pdsgetLookupTableIndex(EventId);
  eventsSubscribedFlag |= (1 << eventBitPos);
}

/**************************************************************************//**
\brief Observes which all item id's are stored and raise the event 

\ingroup pds

\param[in] memoryId   - memoryId which is stored in flash
\return - None
******************************************************************************/
static void pdsDataStoreCallback(PDS_MemId_t itemID)
{
  uint8_t countEvents;

  if ((itemID < BC_EXT_GEN_MEMORY_ITEM_ID) || (itemID > NWK_RREQ_IDENTIFIER_ITEM_ID))
    return;
  PDS_MemId_t memoryId = (itemID ^ PDS_BC_STACK_OFFSET_ID) ;
  for (countEvents = 0; countEvents < BC_PDS_MAX_EVENT; countEvents++)
  {
    if ((eventsSubscribedFlag & (1UL << countEvents)) && (eventToBeProcessedFlag & (1UL << countEvents)) && (eventToItemLookpupTable[countEvents]&(1UL<<memoryId)) && (memoryId <= BITCLOUD_MAX_ITEMS_AMOUNT))
    {
      eventItemBitMask[countEvents] |= (1UL << memoryId);
      if (eventItemBitMask[countEvents] ==  eventToItemLookpupTable[countEvents])
      {
        SYS_PostEvent(BC_EVENT_STORING_FINISHED, pdsEventIdTable[countEvents]);
        eventItemBitMask[countEvents] = 0x00;
        eventToBeProcessedFlag &= ~(1UL << countEvents);
      }
    }
  }
}

#endif
/* eof bcPds.c */
