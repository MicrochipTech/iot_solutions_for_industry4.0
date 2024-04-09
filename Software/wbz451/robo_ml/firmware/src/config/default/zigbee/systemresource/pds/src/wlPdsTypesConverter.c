/*******************************************************************************
  WlPDS Type converter Source File

  Company:
    Microchip Technology Inc.

  File Name:
    wlPdsTypeConverter.c

  Summary:
    This file provides the interface to the wear leveling PDS API's.

  Description:
    This file provides the interface to the wear leveling PDS API's.
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


#ifdef _ENABLE_PERSISTENT_SERVER_
/******************************************************************************
                    Includes section
******************************************************************************/
#include <pds/include/wlPdsMemIds.h>
#include <pds/include/wlPdsTypesConverter.h>
#include <configserver/include/private/csSIB.h>
#include <zdo/include/zdoConfigServer.h>
#include <zdo/include/private/zdoZib.h>
#include <zllplatform/infrastructure/N_ErrH/include/N_ErrH.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#define COMPID "wlPdsTypesConverter"

/******************************************************************************
                    Types section
******************************************************************************/


/******************************************************************************
                    Externals section
******************************************************************************/
#ifndef _MAC2_
extern NIB_t csNIB;
extern SIB_t csSIB;
extern ZIB_t csZIB;
extern AIB_t csAIB;
#endif
/******************************************************************************
                    Prototypes section
******************************************************************************/
static void verifyItemSizes(PDS_MemId_t id, uint16_t size, uint16_t oldSize);

static bool updateExtendedBcSet(void *data);
#ifdef _SECURITY_
static void updateSecurityCounters(void *data);
#ifndef PDS_SECURITY_CONTROL_ENABLE
static void updateKeyPairDescriptor(void *data, uint16_t size, uint16_t oldSize);
#endif // PDS_SECURITY_CONTROL_ENABLE
#ifdef _NWK_IN_FRAME_COUNTERS_
static void updateSecurityKeys(void *data);
#endif  // _NWK_IN_FRAME_COUNTERS_
#endif  // _SECURITY_
static void updateTable(void *data, uint16_t size, uint16_t oldSize);
#ifdef _BINDING_
static void updateBindTable(void *data, uint16_t size, uint16_t oldSize);
#endif //_BINDING_
#ifdef _GROUP_TABLE_
static void updateGroupTable(void *data, uint16_t size, uint16_t oldSize);
#endif //_GROUP_TABLE_
static void updateNeighborTable(void *data, uint16_t size, uint16_t oldSize);

/******************************************************************************
                    Static variables section
******************************************************************************/
ExtGetMem_t extGenMem;

/******************************************************************************
                    Implementation section
******************************************************************************/

/******************************************************************************
\brief Updates BC parameters after restoring taking into account possible size
  changes

\param[in] id      - item id;
\param[in] data    - pointer to data;
\param[in] size    - current item size;
\param[in] oldSize - last size of item

returns true if memory was updated successfully, false - otherwise
******************************************************************************/
bool pdsUpdateMemoryCallback(PDS_UpdateMemory_t *item)
{
  verifyItemSizes(item->id, item->size, item->oldSize);

  switch (item->id)
  {
    case BC_EXT_GEN_MEMORY_ITEM_ID:
      return updateExtendedBcSet(item->data);
#ifdef _SECURITY_
    case NWK_SECURITY_COUNTERS_ITEM_ID:
      updateSecurityCounters(item->data);
      break;
#endif
    case CS_NEIB_TABLE_ITEM_ID:
      updateNeighborTable(item->data, item->size, item->oldSize);
      break;
#ifdef _BINDING_
    case CS_APS_BINDING_TABLE_ITEM_ID:
      updateBindTable(item->data, item->size, item->oldSize);
      break;
#endif
#ifdef _GROUP_TABLE_
    case CS_GROUP_TABLE_ITEM_ID:
      updateGroupTable(item->data, item->size, item->oldSize);
      break;
#endif //_GROUP_TABLE_
#ifdef _SECURITY_
    case CS_NWK_SECURITY_KEYS_ITEM_ID:
#ifdef _NWK_IN_FRAME_COUNTERS_
      updateSecurityKeys(item->data);
#endif
      break;
#ifndef PDS_SECURITY_CONTROL_ENABLE
    case CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID:
      updateKeyPairDescriptor(item->data, item->size, item->oldSize);
      break;
#endif
    case CS_NWK_SECURITY_IB_ITEM_ID:
#endif
    case NWK_RREQ_IDENTIFIER_ITEM_ID:
      break;
    default:
      break;
  }

  return true;
}

/******************************************************************************
\brief Fills extended BC set
******************************************************************************/
void fillExtendedBcSet(void)
{
  extGenMem.csUid = csPIB.macAttr.extAddr;
#ifndef _MAC2_
  extGenMem.txPower = csSIB.csRfTxPower;
  extGenMem.extPanId = csSIB.csExtPANID;
  extGenMem.channelMask = csSIB.csChannelMask;
  extGenMem.channelPage = csNIB.channelPage;
  extGenMem.deviceType = csNIB.deviceType;
  extGenMem.rxOnWhenIdle = csSIB.csRxOnWhenIdle;
  extGenMem.complexDescrAvailable = csSIB.csComplexDescriptorAvailable;
  extGenMem.userDescrAvailable = csSIB.csUserDescriptorAvailable;
  extGenMem.userDescr = csSIB.csUserDescriptor;
  extGenMem.panId = csSIB.csNwkPanid;
  extGenMem.predefinedPanId = csSIB.csNwkPredefinedPanid;
  extGenMem.shortAddress = csNIB.networkAddress;
  extGenMem.uniqueNwkAddress = csNIB.uniqueAddr;
  extGenMem.leaveReqAllowed = csNIB.leaveReqAllowed;
  extGenMem.dtrWakeUp = csSIB.csDtrWakeup;
  extGenMem.updateId = csNIB.updateId;
#if defined _SECURITY_
  extGenMem.extTcAddress = csAIB.trustCenterAddress;
  extGenMem.nwkTcAddress = csAIB.tcNwkAddr;
  extGenMem.securityStatus = csSIB.csZdoSecurityStatus;
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
  extGenMem.tcPermissions = csAIB.tcSecurityPolicy;
#endif //#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#endif 
  extGenMem.parentNwkAddress = csNIB.parentNetworkAddress;
  extGenMem.nwkDepth = csNIB.depth;
  extGenMem.nwkExtPanId = csNIB.extendedPanId;
  extGenMem.logicalChannel = csSIB.csNwkLogicalChannel;
#endif
}

/******************************************************************************
\brief Verifies whether size change is allowed for given item

\param[in] id      - item id;
\param[in] size    - current item size;
\param[in] oldSize - last size of item
******************************************************************************/
static void verifyItemSizes(PDS_MemId_t id, uint16_t size, uint16_t oldSize)
{
  ItemIdToMemoryMapping_t mapItem;

  if (size == oldSize)
    return;

  if (PDS_GetItemDescr(id, &mapItem))
  {
    N_ERRH_ASSERT_FATAL(mapItem.flags & SIZE_MODIFICATION_ALLOWED);
  }
}

/******************************************************************************
\brief Updates extneded BC set of stack parameters

\param[in] data - pointer to data with BC set

\returns returns true extended BC set was updated successfully,
  false - otherwise
******************************************************************************/
static bool updateExtendedBcSet(void *data)
{
  ExtGetMem_t *extGenMem = (ExtGetMem_t *)data;
  uint8_t *ptr = (uint8_t *)data;
  bool inconsistentFlag = true;

  // check network parameters for inconsistence
  for (uint8_t i = 0U; i < sizeof(ExtGetMem_t); i++)
    if (0xFFU != ptr[i])
    {
      inconsistentFlag = false;
      break;
    }

  if (inconsistentFlag)
    return false;

  // update appropriate BC structures
  csPIB.macAttr.extAddr = extGenMem->csUid;
#ifndef _MAC2_
  csSIB.csRfTxPower = extGenMem->txPower;
  csSIB.csExtPANID = extGenMem->extPanId;
  csSIB.csChannelMask = extGenMem->channelMask;
  csNIB.channelPage = extGenMem->channelPage;
  csNIB.deviceType = extGenMem->deviceType;
  csSIB.csRxOnWhenIdle = extGenMem->rxOnWhenIdle;
  csSIB.csComplexDescriptorAvailable = extGenMem->complexDescrAvailable;
  csSIB.csUserDescriptorAvailable = extGenMem->userDescrAvailable;
  csSIB.csUserDescriptor = extGenMem->userDescr;
  csSIB.csNwkPanid = extGenMem->panId;
  csSIB.csNwkPredefinedPanid = extGenMem->predefinedPanId;
  csNIB.networkAddress = extGenMem->shortAddress;
  csNIB.uniqueAddr = extGenMem->uniqueNwkAddress;
  csNIB.leaveReqAllowed = extGenMem->leaveReqAllowed;
  csSIB.csDtrWakeup = extGenMem->dtrWakeUp;
  csNIB.updateId = extGenMem->updateId;
#ifdef _SECURITY_  
  csAIB.trustCenterAddress = extGenMem->extTcAddress;
  csAIB.tcNwkAddr = extGenMem->nwkTcAddress;
  csSIB.csZdoSecurityStatus = extGenMem->securityStatus;
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
  csAIB.tcSecurityPolicy = extGenMem->tcPermissions;
#endif //#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#endif  
  csNIB.parentNetworkAddress = extGenMem->parentNwkAddress;
  csNIB.depth = extGenMem->nwkDepth;
  csNIB.extendedPanId = extGenMem->nwkExtPanId;
  csSIB.csNwkLogicalChannel = extGenMem->logicalChannel;
#endif /* _MAC2_ */
  return true;
}
#ifdef _SECURITY_ 
/******************************************************************************
\brief Updates outgoing security counters

\param[in] data - pointer to data top part of security counter
******************************************************************************/
static void updateSecurityCounters(void *data)
{
  NwkOutFrameCounterTop_t *counterTop = (NwkOutFrameCounterTop_t *)data;

  // we restored default after-init value
  if (0xFFFF == *counterTop)
    *counterTop = 0;
}

#ifndef PDS_SECURITY_CONTROL_ENABLE
/******************************************************************************
\brief Updates Key Pair Descriptors

\param[in] data    - pointer to data with KeyPairSet;
\param[in] size    - current item size;
\param[in] oldSize - last size of item
******************************************************************************/
static void updateKeyPairDescriptor(void *data, uint16_t size, uint16_t oldSize)
{
  if (size == oldSize)
    return;

  updateTable(data, size, oldSize);
  PDS_Store(CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID);
}
#endif // PDS_SECURITY_CONTROL_ENABLE

#ifdef _NWK_IN_FRAME_COUNTERS_
/******************************************************************************
\brief Updates security keys

\param[in] data - pointer to key
******************************************************************************/
static void updateSecurityKeys(void *data)
{
  NWK_SecurityKey_t *keys = (NWK_SecurityKey_t *)data;
  NWK_InFrameCounterEntry_t *inFrameCounterSet;
  NwkKeyAmount_t keyAmount;
  uint8_t keyIndex;
  uint8_t neighborsAmount;

  CS_ReadParameter(CS_NWK_SECURITY_KEYS_AMOUNT_ID, &keyAmount);
  CS_ReadParameter(CS_NEIB_TABLE_SIZE_ID, &neighborsAmount);
  CS_GetMemory(CS_NWK_INCOMING_FRAME_COUNTER_SET_ID, NWK_ADDR_OF_TABLE(inFrameCounterSet));

  for (keyIndex = 0U; keyIndex < keyAmount; ++keyIndex)
  {
    if (keys[keyIndex].isSet)
    {
      keys[keyIndex].inFrameCounterSet.table = inFrameCounterSet + neighborsAmount * keyIndex;
      keys[keyIndex].inFrameCounterSet.end   = inFrameCounterSet + neighborsAmount * (keyIndex + 1);
    }
  }
}
#endif
#endif
/******************************************************************************
\brief Updates table

\param[in] data    - pointer to data with table;
\param[in] size    - current item size;
\param[in] oldSize - last size of item
******************************************************************************/
static void updateTable(void *data, uint16_t size, uint16_t oldSize)
{
  uint8_t *ptr = (uint8_t *)data;

  if (size > oldSize)
    memset(ptr + oldSize, 0U, size - oldSize);
}
#ifdef _BINDING_
/******************************************************************************
\brief Updates binding table

\param[in] data    - pointer to data with binding table;
\param[in] size    - current item size;
\param[in] oldSize - last size of item
******************************************************************************/
static void updateBindTable(void *data, uint16_t size, uint16_t oldSize)
{
  if (size == oldSize)
    return;

  updateTable(data, size, oldSize);

  if (size > oldSize)
  {
    uint8_t *ptr = (uint8_t *)data + oldSize; // points to added records;
    ApsBindingEntry_t *entry = (ApsBindingEntry_t *)ptr;

    // go through all new records and mark them as free
    while (oldSize < size)
    {
      entry->confirm.status = APS_NO_BOUND_DEVICE_STATUS;
      entry++;
      oldSize += sizeof(ApsBindingEntry_t);
    }
    PDS_Store(CS_APS_BINDING_TABLE_ITEM_ID);
  }
}
#endif // _BINDING_
#ifdef _GROUP_TABLE_
/******************************************************************************
\brief Updates group table

\param[in] data    - pointer to data with group table;
\param[in] size    - current item size;
\param[in] oldSize - last size of item
******************************************************************************/
static void updateGroupTable(void *data, uint16_t size, uint16_t oldSize)
{
  if (size == oldSize)
    return;

  updateTable(data, size, oldSize);

  PDS_Store(CS_GROUP_TABLE_ITEM_ID);
}
#endif //_GROUP_TABLE_
/******************************************************************************
\brief Updates neighbor table

\param[in] data    - pointer to data with neighbor table;
\param[in] size    - current item size;
\param[in] oldSize - last size of item
******************************************************************************/
static void updateNeighborTable(void *data, uint16_t size, uint16_t oldSize)
{
  if (size == oldSize)
    return;

  updateTable(data, size, oldSize);

  if (size > oldSize)
  {
    uint8_t *ptr = (uint8_t *)data + oldSize; // points to added records;
    Neib_t *entry = (Neib_t *)ptr;

    // go through all new records and mark them as free
    while (oldSize < size)
    {
      entry->relationship = RELATIONSHIP_EMPTY;
      entry++;
      oldSize += sizeof(Neib_t);
    }
    PDS_Store(CS_NEIB_TABLE_ITEM_ID);
  }
}

#endif // _ENABLE_PERSISTENT_SERVER_
// eof wlPdsTypesConverter.c
