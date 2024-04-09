/*******************************************************************************
  Configuration Server Persistent Memory Source File

  Company:
    Microchip Technology Inc.

  File Name:
    csPersistentMem.c

  Summary:
    This file defines a interface to the Configuration Server persistent memory to store 
    in non-volatile memory.

  Description:
    This file defines a interface to the Configuration Server persistent memory to store 
    in non-volatile memory..
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

#ifndef ZAPPSI_HOST
/******************************************************************************
                    Includes section
******************************************************************************/
#include <pds/include/wlPdsMemIds.h>
#include <pds/include/wlPdsTypesConverter.h>
#include <mac_phy/mac_env/include/macenvMem.h>
#include <configserver/include/private/csSIB.h>
#include <configserver/include/private/csBuffers.h>
#ifndef _MAC2_
#include <aps/include/apsConfigServer.h>
#include <nwk/include/nwkConfigServer.h>
#include <zdo/include/private/zdoZib.h>
#include <bdb/include/bdb.h>
#include <zllplatform/ZLL/N_DeviceInfo/include/N_DeviceInfo.h>
#include <zllplatform/ZLL/N_AddressManager/include/N_AddressManager.h>
#endif

#ifdef _ENABLE_PERSISTENT_SERVER_
/******************************************************************************
                    External variables section
******************************************************************************/
#if !defined(_USE_KF_MAC_)
extern PIB_t csPIB;
#endif // !defined(_USE_KF_MAC_)
extern SIB_t csSIB;
#ifndef _MAC2_
extern NIB_t csNIB;
extern AIB_t csAIB;
extern ZIB_t csZIB;
#endif

extern CS_StackBuffers_t stackBuffers;
#ifdef _LINK_SECURITY_
extern CS_ReadOnlyItems_t PROGMEM_DECLARE(csReadOnlyItems);
#endif

#if defined(_USE_KF_MAC_)
extern uint64_t tal_pib_IeeeAddress;
#endif // defined(_USE_KF_MAC_)

/* PDS Memory Id used for storing bdbNodeIsOnANwk Parameter */
#define BDB_NODEISONANWK_MEM_ID          BDB_PARAM1_MEM_ID

#ifndef _MAC2_
/******************************************************************************
                    Files definitions
******************************************************************************/
PDS_DECLARE_ITEM(BC_EXT_GEN_MEMORY_ITEM_ID, EXTENDED_SET_ITEM_SIZE, &extGenMem, fillExtendedBcSet, NO_ITEM_FLAGS);
PDS_DECLARE_ITEM(CS_NEIB_TABLE_ITEM_ID, NEIGHBOR_TABLE_ITEM_SIZE, &stackBuffers.csNeibTable, NULL, SIZE_MODIFICATION_ALLOWED);
#if defined _SECURITY_
#ifdef _LINK_SECURITY_
PDS_DECLARE_ITEM(CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID, KEY_PAIR_DESCRIPTOR_ITEM_SIZE, &stackBuffers.csApsKeyPairDescriptors, NULL, ITEM_UNDER_SECURITY_CONTROL | SIZE_MODIFICATION_ALLOWED);
#endif
PDS_DECLARE_ITEM(CS_NWK_SECURITY_IB_ITEM_ID, SECURITY_IB_ITEM_SIZE, &csNIB.securityIB, NULL, NO_ITEM_FLAGS);
PDS_DECLARE_ITEM(CS_NWK_SECURITY_KEYS_ITEM_ID, SECURITY_KEYS_ITEM_SIZE, &stackBuffers.csNwkSecKeys, NULL, ITEM_UNDER_SECURITY_CONTROL);
PDS_DECLARE_ITEM(NWK_SECURITY_COUNTERS_ITEM_ID, SECURITY_COUNTERS_ITEM_SIZE, &csNIB.securityCounters.outCounterTop, NULL, NO_ITEM_FLAGS);
#endif
#ifdef _BINDING_
PDS_DECLARE_ITEM(CS_APS_BINDING_TABLE_ITEM_ID, BINDING_TABLE_ITEM_SIZE, &stackBuffers.csApsBindingTable, NULL, SIZE_MODIFICATION_ALLOWED);
#endif //_BINDING_
#ifdef _GROUP_TABLE_
PDS_DECLARE_ITEM(CS_GROUP_TABLE_ITEM_ID, GROUP_TABLE_ITEM_SIZE, &stackBuffers.csGroupTable, NULL, SIZE_MODIFICATION_ALLOWED);
#endif //_GROUP_TABLE_
PDS_DECLARE_ITEM(NWK_RREQ_IDENTIFIER_ITEM_ID, RREQ_IDENTIFIER_ITEM_SIZE, &csNIB.routeRequestIdTop, NULL, NO_ITEM_FLAGS);

PDS_DECLARE_ITEM(BC_STACK_VERSION_MEM_ID, BC_STACK_VESRION_ITEM_SIZE, &csSIB.csStackVersion, NULL, NO_ITEM_FLAGS);
#if (BDB_SUPPORT == 1)
#ifndef ZAPPSI_NP
PDS_DECLARE_ITEM(BDB_NODEISONANWK_MEM_ID, sizeof(bool), &bdbIB.bdbNodeIsOnANetwork, NULL, NO_FILE_MARKS);
#endif
PDS_DECLARE_ITEM(TC_MODE_STORAGE_ITEM_ID, sizeof(deviceInfoParams.tcMode), &deviceInfoParams.tcMode, NULL, NO_ITEM_FLAGS);
PDS_DECLARE_ITEM(FACTORY_NEW_STORAGE_ITEM_ID, sizeof(deviceInfoParams.factoryNew), &deviceInfoParams.factoryNew, NULL, NO_ITEM_FLAGS);
PDS_DECLARE_ITEM(FREE_RANGES_STORAGE_ITEM_ID, sizeof(s_freeRanges), &s_freeRanges, NULL, NO_ITEM_FLAGS)
#endif
PROGMEM_DECLARE(PDS_MemId_t BCItemIdsTable[]) =
{
  BC_EXT_GEN_MEMORY_ITEM_ID,
  CS_NEIB_TABLE_ITEM_ID,
#if defined _SECURITY_
#ifdef _LINK_SECURITY_
  CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID,
#endif // _LINK_SECURITY_
  CS_NWK_SECURITY_IB_ITEM_ID,
  CS_NWK_SECURITY_KEYS_ITEM_ID,
  NWK_SECURITY_COUNTERS_ITEM_ID,
#endif  //_SECURITY_
#ifdef _BINDING_
  CS_APS_BINDING_TABLE_ITEM_ID,
#endif //_BINDING_
#ifdef _GROUP_TABLE_
  CS_GROUP_TABLE_ITEM_ID,
#endif //_GROUP_TABLE_
  NWK_RREQ_IDENTIFIER_ITEM_ID
};

/* BitCloud rejoin parameters directory descriptor.
   Shall be placed in the PDS_FD code segment. */
PDS_DECLARE_DIR(PDS_DirDescr_t BCRejoinParamsDirDescr) =
{
  .list       = BCItemIdsTable,
  .filesCount = ARRAY_SIZE(BCItemIdsTable),
  .memoryId   = BC_ALL_MEMORY_MEM_ID
};
#endif /* _MAC2_ */
#endif /* _ENABLE_PERSISTENT_SERVER_ */
#endif /* !ZAPPSI_HOST */
/* eof csPersistentMem.c */
