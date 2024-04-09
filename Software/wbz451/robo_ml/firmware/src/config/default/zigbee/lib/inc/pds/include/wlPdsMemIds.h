/*******************************************************************************
  Wear Leveling PDS memory identificators Header File

  Company:
    Microchip Technology Inc.

  File Name:
   wlPdsMemIds.h

  Summary:
    This file contains PDS file and directory memory identificators declarations.

  Description:
    This file contains PDS file and directory memory identificators declarations.
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

#ifndef _WLPDSMEMIDS_H_
#define _WLPDSMEMIDS_H_

/******************************************************************************
                               Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/* Compatibility with std PDS mem IDs  */
#include <pds.h>

#define PDS_BC_STACK_OFFSET_ID    (PDS_MODULE_ZB_OFFSET + 0x0)
#define PDS_BC_OTAU_OFFSET_ID     (PDS_MODULE_ZB_OFFSET + 0x100)
#define PDS_BC_ZGP_OFFSET_ID      (PDS_MODULE_ZB_OFFSET + 0x200)
#define PDS_BC_ZLL_OFFSET_ID      (PDS_MODULE_ZB_OFFSET + 0x300)
#define PDS_BC_APP_OFFSET_ID      (PDS_MODULE_ZB_OFFSET + 0x400)

#define PDS_BC_DIR_OFFSET         (PDS_MODULE_ZB_OFFSET + PDS_DIRECTORY_ID_MASK)

/******/
enum
{
  BC_STACK_VERSION_MEM_ID = PDS_BC_STACK_OFFSET_ID,
  BC_EXT_GEN_MEMORY_ITEM_ID,
  CS_NEIB_TABLE_ITEM_ID,
  CS_APS_KEY_PAIR_DESCRIPTORS_ITEM_ID, 
  CS_NWK_SECURITY_IB_ITEM_ID,
  CS_NWK_SECURITY_KEYS_ITEM_ID,
  NWK_SECURITY_COUNTERS_ITEM_ID,
  CS_APS_BINDING_TABLE_ITEM_ID,
  CS_GROUP_TABLE_ITEM_ID,
  NWK_RREQ_IDENTIFIER_ITEM_ID,
  BDB_PARAM1_MEM_ID,
  BC_MAX_PDS_ITEMS_ID
};
#define BC_MAX_PDS_ITEMS_AMOUNT (BC_MAX_PDS_ITEMS_ID - PDS_BC_STACK_OFFSET_ID)
/******/
enum
{
  FREE_RANGES_STORAGE_ITEM_ID = PDS_BC_ZLL_OFFSET_ID, // addressManager
  FACTORY_NEW_STORAGE_ITEM_ID, // device info
  TC_MODE_STORAGE_ITEM_ID,
  ZLL_MAX_STORAGE_ITEM_ID
};
#define BC_ZLL_MAX_PDS_ITEMS_AMOUNT (ZLL_MAX_STORAGE_ITEM_ID - PDS_BC_ZLL_OFFSET_ID)

/******/
/* Application files IDs */
enum
{
  APP_PARAM1_MEM_ID  = PDS_BC_APP_OFFSET_ID,
  APP_PARAM2_MEM_ID,
  APP_PARAM3_MEM_ID,
  APP_PARAM4_MEM_ID,
  APP_PARAM5_MEM_ID,
  APP_PARAM6_MEM_ID,
  APP_PARAM7_MEM_ID,
  APP_PARAM8_MEM_ID,
  APP_PARAM9_MEM_ID,
  APP_PARAM10_MEM_ID,
  APP_PARAM11_MEM_ID,
  APP_PARAM12_MEM_ID,
  APP_PARAM_MAX_MEM_ID
};
#define APP_PARAM_MAX_MEM_ID_AMOUNT (APP_PARAM_MAX_MEM_ID - APP_PARAM1_MEM_ID)
/******/

/******/
/* OTAU item IDs */
enum
{
  OTAU_PARAM1_MEM_ID = PDS_BC_OTAU_OFFSET_ID,
  OTAU_PARAM2_MEM_ID,
  OTAU_PARAM3_MEM_ID,
  OTAU_PARAM4_MEM_ID,
  OTAU_PARAM5_MEM_ID,
  OTAU_PARAM6_MEM_ID,
  OTAU_PARAM7_MEM_ID,
  OTAU_PARAM8_MEM_ID,
  OTAU_PARAM9_MEM_ID,
  OTAU_MAX_PARAM_MEM_ID
};
#if APP_USE_OTAU == 1
#define OTAU_MAX_PARAM_MEM_AMOUNT (OTAU_MAX_PARAM_MEM_ID - OTAU_PARAM1_MEM_ID)
#else
#define OTAU_MAX_PARAM_MEM_AMOUNT 0
#endif
/******/

/******/
enum
{
  ZGP_PROXY_SHARED_KEY_TYPE_MEM_ID  = PDS_BC_ZGP_OFFSET_ID,
  ZGP_PROXY_SHARED_KEY_MEM_ID,
  ZGP_PROXY_LINK_KEY_MEM_ID,
  ZGP_SINK_ATTR_MEM_ID,
  ZGP_SINK_GROUP_ENTRY_MEM_ID,
  ZGP_TRANS_TABLE_MEM_ID,
  ZGP_GPD_ZCL_CMD_MAPPING_TABLE_MEM_ID,
  ZGP_MAPPING_TABLE_MEM_ID,
  ZGP_ENTRY_STARTING_ITEM_ID,
  ZGP_FRAME_COUNTER_ITEM_ID,
  ZGP_NVM_TABLE_HEADER_MEM_ID,
  ZGP_MAX_PARAM_MEM_ID
};
#if defined _GREENPOWER_SUPPORT_ && (APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC)

#define ZGP_MAX_PARAM_MEM_AMOUNT  (ZGP_MAX_PARAM_MEM_ID - ZGP_PROXY_SHARED_KEY_TYPE_MEM_ID)
#else
#define ZGP_MAX_PARAM_MEM_AMOUNT 0

#endif
/******/

/******/
/* Directories*/
enum
{
  BC_ALL_MEMORY_MEM_ID = PDS_BC_DIR_OFFSET,
  /*App Specifc directories*/
  APP_DIR1_MEM_ID,
  APP_DIR2_MEM_ID,
  APP_DIR3_MEM_ID,
  APP_DIR4_MEM_ID,
#if APP_USE_OTAU == 1
  /* OTAU directory IDs */
  OTAU_DIR1_MEM_ID,
  OTAU_DIR2_MEM_ID,
  OTAU_DIR3_MEM_ID,
  OTAU_DIR4_MEM_ID,
#endif
  BC_MAX_DIR_MEM_ID
};
#define PDS_ZB_MAX_DIR_MEM_ID_AMOUNT (BC_MAX_DIR_MEM_ID - BC_ALL_MEMORY_MEM_ID)
/******/

/******/
#define BITCLOUD_MIN_ITEMS_COUNT                   (3)

#if defined _SECURITY_
#ifdef _LINK_SECURITY_
#define BITCLOUD_APS_KEY_PAIR_DESCR_ITEM_AMOUNT    (1)
#else
#define BITCLOUD_APS_KEY_PAIR_DESCR_ITEM_AMOUNT    (0)
#endif  //_LINK_SECURITY_
#define BITCLOUD_NWK_SECURITY_ITEM_AMOUNT          (3)
#else
#define BITCLOUD_NWK_SECURITY_ITEM_AMOUNT          (0)
#define BITCLOUD_APS_KEY_PAIR_DESCR_ITEM_AMOUNT    (0)
#endif  //_SECURITY_

#ifdef _BINDING_
#define BITCLOUD_APS_BINDING_TABLE_ITEM_AMOUNT     (1)
#else
#define BITCLOUD_APS_BINDING_TABLE_ITEM_AMOUNT     (0)
#endif  //_BINDING_

#ifdef _GROUP_TABLE_
#define BITCLOUD_GROUP_TABLE_ITEM_AMOUNT           (1)
#else
#define BITCLOUD_GROUP_TABLE_ITEM_AMOUNT           (0)
#endif  //_GROUP_TABLE_

#define BITCLOUD_MAX_ITEMS_AMOUNT  (BITCLOUD_MIN_ITEMS_COUNT                + \
                                    BITCLOUD_APS_KEY_PAIR_DESCR_ITEM_AMOUNT + \
                                    BITCLOUD_NWK_SECURITY_ITEM_AMOUNT       + \
                                    BITCLOUD_APS_BINDING_TABLE_ITEM_AMOUNT  + \
                                    BITCLOUD_GROUP_TABLE_ITEM_AMOUNT)
/******/

#define PDS_ZB_MAX_ITEMS_AMOUNT       (BITCLOUD_MAX_ITEMS_AMOUNT      + \
                                      BC_ZLL_MAX_PDS_ITEMS_AMOUNT    + \
                                      APP_PARAM_MAX_MEM_ID_AMOUNT    + \
                                      OTAU_MAX_PARAM_MEM_AMOUNT      + \
                                      ZGP_MAX_PARAM_MEM_AMOUNT)


/* Total files and directories amount supported by PDS */


#endif // _WLPDSMEMIDS_H_
/* eof wlPdsMemIds.h */
