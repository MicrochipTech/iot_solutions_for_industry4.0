/*******************************************************************************
  Configuration Server Source File

  Company:
    Microchip Technology Inc.

  File Name:
    configServer.c

  Summary:
    This file provides the interface to the Configuration Server implementation.

  Description:
    This file provides the interface to the Configuration Server implementation.
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
#include <configserver/include/configserver.h>
#include <mac_phy/mac_env/include/macenvMem.h>
#include <configserver/include/private/csSIB.h>
#include <configserver/include/private/csDbg.h>
#include <configserver/include/private/csBuffers.h>
#include <systemenvironment/include/sysAssert.h>
#ifdef _ENABLE_PERSISTENT_SERVER_
#include <pds/include/wlPdsMemIds.h>
#include <pds/include/bcPDS.h>
#endif /* _ENABLE_PERSISTENT_SERVER_ */
#ifndef _MAC2_
#include <zdo/include/private/zdoZib.h>
#else
#include <mac_phy/mac_env/include/macenvPib.h>
#endif
#ifdef ZAPPSI_HOST
#include <zsiDriver.h>
#include <zsiSysSerialization.h>
#endif /* ZAPPSI_HOST */

/******************************************************************************
                    External variables section
******************************************************************************/
#ifndef ZAPPSI_HOST

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
#endif /* !ZAPPSI_HOST */

extern CS_MemoryItem_t PROGMEM_DECLARE(csVarItems[]);
extern CS_MemoryItem_t PROGMEM_DECLARE(csConstItems[]);
extern CS_MemoryItem_t PROGMEM_DECLARE(csMemItems[]);

#if defined(_USE_KF_MAC_)
extern uint64_t tal_pib_IeeeAddress;
#if defined(_MAC_BAN_NODE_)
extern CS_ReadOnlyItems_t PROGMEM_DECLARE(csReadOnlyItems);
#endif
#endif

/******************************************************************************
                    Prototypes section
******************************************************************************/
static CS_MemoryItem_t csGetItem(CS_MemoryItemId_t itemId);
#if !defined(ZAPPSI_HOST) || defined(_ZCL_SUPPORT_)
static void csReadInternalParameter(CS_MemoryItemId_t parameterId,
  void *parameterValue);
static void csWriteParameterInternal(CS_MemoryItemId_t parameterId,
  const void *parameterValue);
#endif /* !ZAPPSI_HOST || ZCL_SUPPORT */

/******************************************************************************
                    Implementation section
******************************************************************************/
/******************************************************************************
\brief Returns size of the particular item.

\param[in] itemId - item identifier.

\return size of the particular item.
******************************************************************************/
uint16_t CS_GetItemSize(CS_MemoryItemId_t itemId)
{
  CS_MemoryItem_t item = csGetItem(itemId);

  return item.size;
}

/******************************************************************************
\brief Configuration Server initialization
\param[in] zgbIBdata - IB data
******************************************************************************/
void CS_Init(ZB_CS_SYS_IBData_t *zgbIBdata)
{
  csSetToDefault(zgbIBdata);
#ifdef _ENABLE_PERSISTENT_SERVER_
#ifndef _MAC2_
#ifndef ZAPPSI_HOST  //only realted to BC stack paramter size handling

  ZB_PDS_Init();
#endif
#endif
#endif /* _ENABLE_PERSISTENT_SERVER_ */
}

/******************************************************************************
\brief Gets allocated memory specified by memory identifier

\param[in] memoryId - memory area Id
\param[out] memoryPtr - pointer to the memory

******************************************************************************/
void CS_GetMemory(CS_MemoryItemId_t memoryId, void **memoryPtr)
{
  CS_MemoryItem_t item = csGetItem(memoryId);

  SYS_E_ASSERT_FATAL(((memoryId & CS_TYPE_MASK) == CS_MEM_PARAM_TYPE), CS_GET_MEM0);

  *memoryPtr = item.value.ramValue;
}

/******************************************************************************
\brief Gets the parameter specified by it's identifier from internal or external
       memory.

\param[in] parameterId - ID of the parameter being read
\param[out] parameterValue - pointer to the memory

******************************************************************************/
void CS_ReadParameter(CS_MemoryItemId_t parameterId, void *parameterValue)
{
  /*
  assert_static(ARRAY_SIZE(csVarItems) > UINT8_MAX);
  assert_static(ARRAY_SIZE(csConstItems) > UINT8_MAX);
  assert_static(ARRAY_SIZE(csMemItems) > UINT8_MAX);
  */

  /* Read parameter depending of it's location: from internal memory or external
     one (for ZAppSI HOST device). */
#ifdef ZAPPSI_HOST
  switch (parameterId)
  {
#ifdef _ZCL_SUPPORT_ 
    case CS_ZCL_MEMORY_BUFFERS_AMOUNT_ID:
    case CS_ZCL_BUFFERS_ID:
    case CS_ZCL_BUFFER_SIZE_ID:
#if APP_USE_OTAU == 1
    case CS_ZCL_OTAU_DEFAULT_UPGRADE_SERVER_IEEE_ADDRESS_ID:
    case CS_ZCL_OTAU_DEFAULT_SERVER_DISCOVERY_PERIOD_ID:
    case CS_ZCL_OTAU_QUERY_INTERVAL_ID:
    case CS_ZCL_OTAU_MAX_RETRY_COUNT_ID:
    case CS_ZCL_OTAU_DEFAULT_IMAGE_TYPE_ID:
    case CS_ZCL_OTAU_FILE_VERSION_ID:
    case CS_ZCL_OTAU_DISCOVERED_SERVER_AMOUNT_ID:
    case CS_ZCL_OTAU_CLIENT_SESSION_AMOUNT_ID:
    case CS_ZCL_OTAU_PAGE_REQ_BLOCK_RESPONSE_SPACING_ID:
    case CS_ZCL_OTAU_MISSED_BLOCKS_BUFFER_SIZE_ID:
    case CS_ZCL_OTAU_DISCOVERED_SERVER_RESULT_ID:
    case CS_ZCL_OTAU_CLIENT_SESSION_MEMORY_ID:
    case CS_ZCL_OTAU_MISSED_BLOCKS_BUFFER_ID:
#endif /* APP_USE_OTAU == 1 */
      csReadInternalParameter(parameterId, parameterValue);
      break;
#endif /* ZCL_SUPPORT == 1 */

    default:
      zsiProcessCommand(ZSI_SREQ_CMD, &parameterId, zsiSerializeCS_ReadParameterReq,
        parameterValue);
      return;
      break;
  }
#else
  csReadInternalParameter(parameterId, parameterValue);
#endif /* ZAPPSI_HOST */
}

#if !defined(ZAPPSI_HOST) || defined(_ZCL_SUPPORT_)
/******************************************************************************
\brief Gets the parameter specified by it's identifier from internal memory.

\param[in] parameterId - ID of the parameter being read
\param[out] parameterValue - pointer to the memory

******************************************************************************/
static void csReadInternalParameter(CS_MemoryItemId_t parameterId, void *parameterValue)
{
  CS_MemoryItem_t item = csGetItem(parameterId);

  SYS_E_ASSERT_FATAL(parameterValue, CS_READ_PARAM0);

  switch (parameterId & CS_TYPE_MASK)
  {
    case CS_RAM_PARAM_TYPE:
      memcpy(parameterValue, item.value.ramValue, item.size);
      break;

    case CS_FLASH_PARAM_TYPE:
      memcpy_P(parameterValue, item.value.flashValue, item.size);
      break;

    case CS_MEM_PARAM_TYPE:
    default:
      SYS_E_ASSERT_FATAL(0U, CS_READ_PARAM1);
      break;
  }
  return;
}
#endif /* !defined(ZAPPSI_HOST) || defined(ZCL_SUPPORT) */

/******************************************************************************
\brief Sets the parameter specified by it's identifier

\param[in] parameterId - ID of the parameter being written
\param[out] parameterValue - pointer to the parameter

******************************************************************************/
void CS_WriteParameter(CS_MemoryItemId_t parameterId, const void *parameterValue)
{
  /* Write parameter depending of it's location: to internal memory or external
     one (for ZAppSI HOST device). */
#ifdef ZAPPSI_HOST
  switch (parameterId)
  {
#ifdef _ZCL_SUPPORT_
    case CS_ZCL_MEMORY_BUFFERS_AMOUNT_ID:
    case CS_ZCL_BUFFERS_ID:
    case CS_ZCL_BUFFER_SIZE_ID:
#if APP_USE_OTAU == 1
    case CS_ZCL_OTAU_DEFAULT_SERVER_DISCOVERY_PERIOD_ID:
    case CS_ZCL_OTAU_QUERY_INTERVAL_ID:
    case CS_ZCL_OTAU_MAX_RETRY_COUNT_ID:
    case CS_ZCL_OTAU_DEFAULT_IMAGE_TYPE_ID:
    case CS_ZCL_OTAU_DISCOVERED_SERVER_AMOUNT_ID:
    case CS_ZCL_OTAU_CLIENT_SESSION_AMOUNT_ID:
    case CS_ZCL_OTAU_PAGE_REQ_BLOCK_RESPONSE_SPACING_ID:
    case CS_ZCL_OTAU_MISSED_BLOCKS_BUFFER_SIZE_ID:
    case CS_ZCL_OTAU_DISCOVERED_SERVER_RESULT_ID:
    case CS_ZCL_OTAU_CLIENT_SESSION_MEMORY_ID:
    case CS_ZCL_OTAU_MISSED_BLOCKS_BUFFER_ID:
#endif /* APP_USE_OTAU == 1 */
      csWriteParameterInternal(parameterId, parameterValue);
      break;
#endif /* ZCL_SUPPORT == 1*/
    default:
      {
        ZsiCsParameter_t zsiCsParameter;

        zsiCsParameter.parameterId = parameterId;
        zsiCsParameter.size = CS_GetItemSize(parameterId);
        memcpy(zsiCsParameter.payload, parameterValue, zsiCsParameter.size);

        zsiProcessCommand(ZSI_SREQ_CMD, &zsiCsParameter, zsiSerializeCS_WriteParameterReq,
          NULL);
        return;
      }
      break;
  }
#else
  csWriteParameterInternal(parameterId, parameterValue);
#endif /* ZAPPSI_HOST */
}

#if !defined(ZAPPSI_HOST) || defined(_ZCL_SUPPORT_)
/******************************************************************************
\brief Sets the parameter specified by it's identifier to internal or external
       memory.

\param[in] parameterId - ID of the parameter being written
\param[out] parameterValue - pointer to the parameter

******************************************************************************/
static void csWriteParameterInternal(CS_MemoryItemId_t parameterId,
  const void *parameterValue)
{
  CS_MemoryItem_t item = csGetItem(parameterId);

  SYS_E_ASSERT_FATAL(parameterValue, CS_WRITE_PARAM0);
  SYS_E_ASSERT_FATAL(((parameterId & CS_TYPE_MASK) == CS_RAM_PARAM_TYPE), CS_WRITE_PARAM1);

  memcpy(item.value.ramValue, parameterValue, item.size);
}
#endif /* !defined(ZAPPSI_HOST) || defined(ZCL_SUPPORT) */

#ifndef ZAPPSI_HOST
/******************************************************************************
\brief Set PDS default

******************************************************************************/
void CS_PdsDefaultValue(void)
{
#if defined(_USE_KF_MAC_)
  tal_pib_IeeeAddress = CCPU_TO_LE64(CS_UID);
#else
  csPIB.macAttr.extAddr = CCPU_TO_LE64(CS_UID);
#endif // defined(_USE_KF_MAC_)

  csSIB.csRfTxPowerType = CS_DEVICE_POWER_TYPE;
  csSIB.csRfTxPower = CS_RF_TX_POWER;
  csSIB.csRfch26MaxTxPower = CS_RF_MAX_CH26_TX_POWER;
  csSIB.csChannelMask = CS_CHANNEL_MASK;
#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_
  csSIB.csMacSendEmptyDataFrame = CS_MAC_SEND_EMPTY_DATA_FRAME;
#endif /*_PENDING_EMPTY_DATA_FRAME_*/
#endif /*_FFD_*/
#ifndef _MAC2_
  csSIB.csExtPANID = CCPU_TO_LE64(CS_EXT_PANID);
  csNIB.channelPage = CS_CHANNEL_PAGE;
  csNIB.deviceType = CS_DEVICE_TYPE;
  csSIB.csRxOnWhenIdle = (CS_DEVICE_TYPE == DEVICE_TYPE_END_DEVICE) ? CS_RX_ON_WHEN_IDLE : true;
  csSIB.csComplexDescriptorAvailable = CS_COMPLEX_DESCRIPTOR_AVAILABLE;
  csSIB.csUserDescriptorAvailable = CS_USER_DESCRIPTOR_AVAILABLE;
  csSIB.csNwkPanid = CCPU_TO_LE16(CS_NWK_PANID);
  csSIB.csNwkPredefinedPanid = CS_NWK_PREDEFINED_PANID,
  csNIB.networkAddress = CCPU_TO_LE16(CS_NWK_ADDR);
  csNIB.uniqueAddr = CS_NWK_UNIQUE_ADDR;
  csNIB.leaveReqAllowed = CS_NWK_LEAVE_REQ_ALLOWED,
  csSIB.csDtrWakeup = CS_DTR_WAKEUP;
#if defined(_ENABLE_PERSISTENT_SERVER_)
  csNIB.parentNetworkAddress = CCPU_TO_LE16(0xFFFF);
  csNIB.depth = 0;
  csNIB.extendedPanId = CCPU_TO_LE64(CS_NWK_EXT_PANID);
  csSIB.csNwkLogicalChannel = 0;
#endif /* _ENABLE_PERSISTENT_SERVER_ */
#if defined(_SECURITY_)
  csAIB.trustCenterAddress = CCPU_TO_LE64(CS_APS_TRUST_CENTER_ADDRESS);
  csAIB.tcNwkAddr = CCPU_TO_LE16(CS_SHORT_TRUST_CENTER_ADDRESS);
  csSIB.csZdoSecurityStatus = CS_ZDO_SECURITY_STATUS;
#if defined (_LINK_SECURITY_)
#if defined _TRUST_CENTRE_
  csAIB.tcSecurityPolicy.flags.allowJoins = CS_TC_PERMISSIONS_ALLOWJOINS;
  csAIB.tcSecurityPolicy.flags.allowRemoteTCPolicyChange = CS_TC_PERMISSIONS_ALLOWREMOTETCPOLICYCHANGE;
#ifdef _TC_ALLOW_REJOIN_WITH_GLOBAL_LINK_KEY_
  csAIB.tcSecurityPolicy.flags.allowRejoins = CS_TC_PERMISSIONS_ALLOWREJOINS;
#endif
  csAIB.tcSecurityPolicy.flags.allowInstallCodes = CS_TC_PERMISSIONS_ALLOWINSTALLCODES;
#endif //#if defined _TRUST_CENTRE_
#endif /* _LINK_SECURITY_ */
#endif /* _SECURITY_ */

  /* Parameters not to store in EEPROM */
  csNIB.maxNeighborRouteCost = CS_MAX_NEIGHBOR_ROUTE_COST;
#if defined _NWK_THRESHOLD_ROUTING_
  csNIB.softLinkCostThreshold = CS_SOFT_LINK_COST_THRESHOLD;
#endif /* _NWK_THRESHOLD_ROUTING_ */
  csNIB.maxLinkRouteCost = CS_MAX_LINK_ROUTE_COST;
  csSIB.csNwkMaxLinkStatusFailures = CS_NWK_MAX_LINK_STATUS_FAILURES;
  csSIB.csNwkEndDeviceMaxFailures = CS_NWK_END_DEVICE_MAX_FAILURES;
#ifdef AT86RF212
  csSIB.csLbtMode = CS_LBT_MODE;
#endif /* AT86RF212 */
#if defined(_SECURITY_)
  csSIB.csSecurityOn = CS_SECURITY_ON;
#endif /* _SECURITY_ */

  /* Buffers cleaning */
#if defined(_ENABLE_PERSISTENT_SERVER_)
  memset(&stackBuffers.csNeibTable, 0, CS_NEIB_TABLE_SIZE);
  #if defined(_BINDING_) && (CS_APS_BINDING_TABLE_SIZE > 0)
    memset(&stackBuffers.csApsBindingTable, 0, CS_APS_BINDING_TABLE_SIZE);
  #endif /* _BINDING_ */
  #if defined(_SECURITY_)
  {
    csNIB.securityIB.securityLevel = CS_SECURITY_LEVEL;
    csNIB.securityIB.secureAllFrames = CS_SECURITY_ALL_FRAMES;
    NWK_ResetSecurityIB();
  }
  #endif /* _SECURITY_ */
#endif /* _ENABLE_PERSISTENT_SERVER_ */
#if defined (_GROUP_TABLE_)
  memset(&stackBuffers.csGroupTable, 0, CS_GROUP_TABLE_SIZE);
#endif /* _GROUP_TABLE_ */
#if defined(_SECURITY_)
  #if defined _LINK_SECURITY_ && CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT > 0
    memset(&stackBuffers.csApsKeyPairDescriptors, 0, CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT);
  #endif /* _LINK_SECURITY_ */
#endif /* _SECURITY_ */
#if defined(_PERMISSIONS_) && CS_PERMISSIONS_TABLE_SIZE > 0
  memset(&stackBuffers.csPermissionsTable, 0, CS_PERMISSIONS_TABLE_SIZE);
#endif /* _PERMISSIONS_ */
  csPIB.phyAttr.ccaMode = CS_PHY_CC_CCA_MODE;
  csPIB.macAttr.ccaEdThres = CS_RF_CCA_ED_THRES; 
#endif /* _MAC2_ */
}

#endif /* !ZAPPSI_HOST */

/******************************************************************************
\brief Returns Configuration Server item by it's identifier

\param[in] itemId - ID of the parameter

\return - Configuration Server item
******************************************************************************/
static CS_MemoryItem_t csGetItem(CS_MemoryItemId_t itemId)
{
  CS_MemoryItem_t item =
  {
    .size = 0,
    .value = {0}
  };
  uint8_t itemInternalId = itemId & CS_ID_MASK;

  /* Read item info from the FLASH */
  switch (itemId & CS_TYPE_MASK)
  {
    case CS_RAM_PARAM_TYPE:
      //sysAssert(itemInternalId < ARRAY_SIZE(csVarItems), CS_GET_ITEM0);
      memcpy_P(&item, &csVarItems[itemInternalId], sizeof(CS_MemoryItem_t));
      break;

    case CS_FLASH_PARAM_TYPE:
      //sysAssert(itemInternalId < ARRAY_SIZE(csConstItems), CS_GET_ITEM1);
      memcpy_P(&item, &csConstItems[itemInternalId], sizeof(CS_MemoryItem_t));
      break;

    case CS_MEM_PARAM_TYPE:
      //sysAssert(itemInternalId < ARRAY_SIZE(csMemItems), CS_GET_ITEM2);
       memcpy_P(&item, &csMemItems[itemInternalId], sizeof(CS_MemoryItem_t));
       break;

    default:
      SYS_E_ASSERT_FATAL(0U, CS_GET_ITEM3);
      break;
  }

  return item;
}

#if defined(_USE_KF_MAC_) && defined(_MAC_BAN_NODE_)
/******************************************************************************
\brief Returns the BAN table size

\return - the BAN table size
******************************************************************************/
MAC_BanTableSize_t csGetBanTableSize(void)
{
  MAC_BanTableSize_t size;

  memcpy_P(&size, &csReadOnlyItems.csMacBanTableSize, sizeof(MAC_BanTableSize_t));

  return size;
}

/******************************************************************************
\brief Returns the BAN table entry

\return - pointer to the BAN table
******************************************************************************/
MAC_BanTableEntry_t *csGetBanTableEntry(void)
{
  return stackBuffers.csBanTable;
}

#endif // defined(_USE_KF_MAC_) && defined(_MAC_BAN_NODE_)

/* eof configServer.c */
