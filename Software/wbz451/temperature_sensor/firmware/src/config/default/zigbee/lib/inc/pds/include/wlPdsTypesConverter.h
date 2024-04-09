/*******************************************************************************
  Wear Leveling PDS types converter Header File

  Company:
    Microchip Technology Inc.

  File Name:
    wlPdsTypesConverter.h

  Summary:
    This file contains the PDS types conversion definitions.

  Description:
    This file contains the PDS types conversion definitions.
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

#ifndef _WLPDS_TYPESCONVERTER
#define _WLPDS_TYPESCONVERTER

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zdo/include/appFramework.h>
#include <pds/include/wlPdsMemIds.h>
#include <aps/include/apsAIB.h>

/******************************************************************************
                   Definitions section
******************************************************************************/
#define EXTENDED_SET_ITEM_SIZE        (sizeof(ExtGetMem_t))
#define NEIGHBOR_TABLE_ITEM_SIZE      (CS_NEIB_TABLE_SIZE * sizeof(Neib_t))
#define KEY_PAIR_DESCRIPTOR_ITEM_SIZE (CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT * sizeof(ApsKeyPairDescriptor_t))
#define SECURITY_IB_ITEM_SIZE         (sizeof(NWK_SecurityIB_t))
#define NWK_KEYS_ENTRY_SIZE           (sizeof(NWK_SecurityKey_t))
#define LINK_KEYS_ENTRY_SIZE          (sizeof(ApsKeyPairDescriptor_t))
/* SECURITY_KEYS_ITEM_SIZE includes pointers to frame counters which are not required here.
 Left now as is for compatibility. */
#define SECURITY_KEYS_ITEM_SIZE       (CS_NWK_SECURITY_KEYS_AMOUNT * sizeof(NWK_SecurityKey_t))
#define SECURITY_COUNTERS_ITEM_SIZE   (sizeof(NwkOutFrameCounterTop_t))
#define BINDING_TABLE_ITEM_SIZE       (CS_APS_BINDING_TABLE_SIZE * sizeof(ApsBindingEntry_t))
#define GROUP_TABLE_ITEM_SIZE         (CS_GROUP_TABLE_SIZE * sizeof(NWK_GroupTableEntry_t))
#define RREQ_IDENTIFIER_ITEM_SIZE     (sizeof(uint8_t))
#define BC_STACK_VESRION_ITEM_SIZE   (sizeof(csSIB.csStackVersion))



/******************************************************************************
                   Types section
******************************************************************************/
/* The extended set of commonly used BitCloud parameters that can
be stored in the non-volatile memory and identified via BC_EXT_GEN_MEMORY_MEM_ID */
typedef struct
{
  uint64_t         csUid;
  uint8_t          txPower;
  uint64_t         extPanId;
  uint32_t         channelMask;
  uint8_t          channelPage;
  DeviceType_t     deviceType;
  bool             rxOnWhenIdle;
  bool             complexDescrAvailable;
  bool             userDescrAvailable;
  UserDescriptor_t userDescr;
  uint16_t         panId;
  bool             predefinedPanId;
  uint16_t         shortAddress;
  bool             uniqueNwkAddress;
  bool             leaveReqAllowed;
  bool             dtrWakeUp;
  uint8_t          updateId;
  uint64_t         extTcAddress;
  uint16_t         nwkTcAddress;
  uint8_t          securityStatus;
  uint16_t         parentNwkAddress;
  uint8_t          nwkDepth;
  uint64_t         nwkExtPanId;
  uint8_t          logicalChannel;
#if defined _TRUST_CENTRE_
  APS_TCSecurityPolicy_t tcPermissions;
#endif //#if defined _TRUST_CENTRE_
} ExtGetMem_t;

/******************************************************************************
                   Extern section
******************************************************************************/
extern ExtGetMem_t extGenMem;


/******************************************************************************
                    Prototypes section
******************************************************************************/
#if PDS_SECURITY_CONTROL_ENABLE

/******************************************************************************
\brief Checks whether item is under security control

\param[in] id - item id

\returns true if item is under security control, false - otherwise
******************************************************************************/
bool pdsIsItemUnderSecurityControl(S_Nv_ItemId_t id);
#endif


/******************************************************************************
\brief To fill the extended BC set
******************************************************************************/
void fillExtendedBcSet(void);


#endif // _WLPDS_TYPESCONVERTER
/* eof wlPdsTypesConverter.h */
