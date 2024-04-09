/*******************************************************************************
  Configuration Server Memory Source File

  Company:
    Microchip Technology Inc.

  File Name:
    csMem.c

  Summary:
    This file contains the BitCloud Configuration Server information base memory.

  Description:
    This file contains the BitCloud Configuration Server information base memory.
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
#include <configserver/include/private/csBuffers.h>
#include <mac_phy/mac_env/include/macenvMem.h>
#ifndef _MAC2_
#include <zdo/include/private/zdoZib.h>
#endif
#ifdef _ZGPD_SPECIFIC_
#include <zgp/GPDevice/include/zgpdIb.h>
#endif
#ifdef BDB_SUPPORT
#include <bdb/include/bdb.h>
#endif
#include <configserver/include/private/csSIB.h>
#include <configserver/include/configserver.h>
#ifndef _MAC2_
#include <nwk/include/nwkSecurity.h>
#include <zllplatform/ZLL/N_DeviceInfo/include/N_DeviceInfo.h>
#include <zllplatform/ZLL/N_AddressManager/include/N_AddressManager.h>
#include <zcl/include/zclMem.h>
#include <pds/include/wlPdsTypesConverter.h>
#include <zcl/include/zcloccupancysensingcluster.h>
#include <zcl/include/zclTemperatureMeasurementCluster.h>
#include <zcl/include/zclIlluminanceMeasurementCluster.h>
#include <zcl/include/zclHumidityMeasurementCluster.h>
#ifdef _SECURITY_
#include <security/TrustCentre/include/tcAuthentic.h>
#endif /* _SECURITY */
#endif //#ifndef _MAC2_

/******************************************************************************
                    Static prototype Section
******************************************************************************/
static void restoreExtendedBcSet(void);
static void backupExtendedBcSet(void);

/******************************************************************************
                    TRNG_ReadData function declaration
******************************************************************************/
uint32_t TRNG_ReadData(void);

/******************************************************************************
                    External variables section
******************************************************************************/
#if defined(_USE_KF_MAC_)
extern uint64_t tal_pib_IeeeAddress;
#endif // defined(_USE_KF_MAC_)

/******************************************************************************
                    Global variables section
******************************************************************************/
/* BitCloud information bases allocation */
#if !defined(_USE_KF_MAC_)
PIB_t csPIB;
#endif // defined(_USE_KF_MAC_)

#ifndef _MAC2_
NIB_t csNIB;
ZIB_t csZIB;
AIB_t csAIB;

ExtGetMem_t extGenMemParams;
typedef struct backup_data_
{
    
    BDBIB_t  backupBdbIB;
    ExtGetMem_t backupExtGenMem;
    DeviceInfoParameters_t backupDeviceInfoParams;
    uint16_t backupOutCounterTop;
    Neib_t backupCsNeibTable[CS_NEIB_TABLE_SIZE];
    NWK_SecurityIB_t securityIB;
    NWK_SecurityKey_t backupCsNwkSecKeys[CS_NWK_SECURITY_KEYS_AMOUNT];
    ApsKeyPairDescriptor_t backupCsApsKeyPairDescriptors[CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT];
    ApsBindingEntry_t backupCsApsBindingTable[CS_APS_BINDING_TABLE_SIZE];
    ZclMem_t backupZclMem;
    uint32_t dummy;
    
} bkupRamData_t;

bkupRamData_t __attribute__((persistent)) backupRamData;
#endif

#ifdef _ZGPD_SPECIFIC_
ZGIB_t csZGIB;
#endif
#ifdef BDB_SUPPORT
BIB_t csBIB;
#endif
SIB_t csSIB;

bool certificationFlag = CS_CERTIFICATION_FLAG;

/* To store the deep sleep wakeup source. */
uint8_t deviceDeepSleepWakeupSrc = CS_DEVICE_DEEP_SLEEP_WAKEUP_SRC;

/* BitCloud memory buffers allocation */
CS_StackBuffers_t stackBuffers;

/* FLASH memory allocation to store read-only parameters */

/* Default information bases item values */
#ifndef _MAC2_
NIB_t PROGMEM_DECLARE(defaultNIB) =
{
#if defined _SECURITY_
  .securityIB = {
    .securityLevel = CS_SECURITY_LEVEL,
    .secureAllFrames = CS_SECURITY_ALL_FRAMES
  },
#endif
  .deviceType = CS_DEVICE_TYPE,
  .addrAlloc = CS_ADDRESS_ASSIGNMENT_METHOD,
  .symLink = true,
  .uniqueAddr = CS_NWK_UNIQUE_ADDR,
  .leaveReqAllowed = CS_NWK_LEAVE_REQ_ALLOWED,
  .stackProfile = CS_STACK_PROFILE,
  .protocolVersion = CS_PROTOCOL_VERSION,
  .maxDepth = CS_MAX_NETWORK_DEPTH,
  .maxNeighborRouteCost = CS_MAX_NEIGHBOR_ROUTE_COST,
  .maxLinkRouteCost = CS_MAX_LINK_ROUTE_COST,
#if defined _NWK_THRESHOLD_ROUTING_
  .softLinkCostThreshold = CS_SOFT_LINK_COST_THRESHOLD,
#endif /* _NWK_THRESHOLD_ROUTING_ */
  .channelPage = CS_CHANNEL_PAGE,
  .logicalChannel = 0,
  .networkAddress = CCPU_TO_LE16(CS_NWK_ADDR),
  .panId = CCPU_TO_LE16(CS_NWK_PANID),
  .extendedPanId = CCPU_TO_LE64(CS_NWK_EXT_PANID), /* uses as joined-to-network flag */
  .maxRouters = CS_MAX_CHILDREN_ROUTER_AMOUNT,
#ifdef _CHILD_MANAGEMENT_
  /** For an RFD, this records the information received in an End Device
   * Timeout Response command indicating the parent information.
   * For an FFD, this records the deviceâ??s local capabilities. */
  .parentInformation =  CS_DEFAULT_PARENT_INFORMATION,
  /** It indicates the default timeout in minutes for any end device
   * that does not negotiate a different timeout value. */
  .endDeviceTimeoutDefault = CS_DEFAULT_END_DEVICE_TIMEOUT,
#endif /* _CHILD_MANAGEMENT_ */

  .maxEndDevices = CS_MAX_CHILDREN_AMOUNT - CS_MAX_CHILDREN_ROUTER_AMOUNT,

  //.csApsSecurityTimeoutPeriod = CS_APS_SECURITY_TIMEOUT_PERIOD
};

ZIB_t PROGMEM_DECLARE(defaultZIB) =
{
  .permitJoinDuration = CS_PERMIT_DURATION,
  .zdpResponseTimeout = CS_ZDP_RESPONSE_TIMEOUT,
  .scanDuration = CS_SCAN_DURATION,
};

AIB_t PROGMEM_DECLARE(defaultAIB) =
{
  .nonMemberRadius = APS_AIB_NONMEMBER_RADIUS_DEFAULT_VALUE, /* See ZigBee spec r19, Table 2.24. */
  .maxFrameRetries = CS_APS_MAX_FRAME_RETRIES,
#ifdef _APS_FRAGMENTATION_
  .fragWindowSize = CS_APS_MAX_TRANSMISSION_WINDOW_SIZE,
#endif /* _APS_FRAGMENTATION_ */
#ifdef _SECURITY_
  .trustCenterAddress = CCPU_TO_LE64(CS_APS_TRUST_CENTER_ADDRESS),
  .tcNwkAddr = CCPU_TO_LE16(CS_SHORT_TRUST_CENTER_ADDRESS),
#ifdef _LINK_SECURITY_
#if defined _TRUST_CENTRE_
  .tcSecurityPolicy.flags.allowJoins = CS_TC_PERMISSIONS_ALLOWJOINS,
  .tcSecurityPolicy.flags.allowRemoteTCPolicyChange = CS_TC_PERMISSIONS_ALLOWREMOTETCPOLICYCHANGE,
#ifdef _TC_ALLOW_REJOIN_WITH_GLOBAL_LINK_KEY_
  .tcSecurityPolicy.flags.allowRejoins = CS_TC_PERMISSIONS_ALLOWREJOINS,
#endif
  .tcSecurityPolicy.flags.allowInstallCodes = CS_TC_PERMISSIONS_ALLOWINSTALLCODES,
#endif //#if defined _TRUST_CENTRE_
  .securityPolicy = {0x00, 0x07, 0x07, 0x07,
#ifdef _LIGHT_LINK_PROFILE_
                     0x07, 0x7F, 0x1a, 0x78,
#else
                     0x07, 0x7F, 0x7a, 0x78,
#endif // _LIGHT_LINK_PROFILE_
                     0x5e, 0x5f, 0x07, 0x07,
                     0x07, 0x07, 0x07, 0x07,
                     0x78, 0x78, 0x7F, 0x7F}
#endif /* _LINK_SECURITY_ */
#endif /* _SECURITY_ */
};
#endif /* !_MAC2_*/

SIB_t PROGMEM_DECLARE(defaultSIB) =
{
  /* MAC parameters */
  .csMacTransactionTime = CS_MAC_TRANSACTION_TIME,
  .csRfTxAntennaGain    = CS_TX_ANTENNA_GAIN,
  .csRfTxPowerType = CS_DEVICE_POWER_TYPE,
  .csRfTxPower = CS_RF_TX_POWER,
  .csRfch26MaxTxPower = CS_RF_MAX_CH26_TX_POWER,
  .csChannelMask = CS_CHANNEL_MASK,
#ifdef AT86RF212
  .csLbtMode = CS_LBT_MODE,
#endif //AT86RF212
#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_
  .csMacSendEmptyDataFrame = CS_MAC_SEND_EMPTY_DATA_FRAME,
#endif /*_PENDING_EMPTY_DATA_FRAME_*/
#endif /*_FFD_*/
#ifndef _MAC2_

  /* NWK parameters */
  .csNwkPanid = CCPU_TO_LE16(CS_NWK_PANID),
  .csNwkUseMulticast = CS_NWK_USE_MULTICAST,
  .csNwkMaxLinkStatusFailures = CS_NWK_MAX_LINK_STATUS_FAILURES,
  .csNwkEndDeviceMaxFailures = CS_NWK_END_DEVICE_MAX_FAILURES,
  .csNwkLogicalChannel = 0,
  .csNwkPredefinedPanid = CS_NWK_PREDEFINED_PANID,
  .csAddressAssignmentMethod = CS_ADDRESS_ASSIGNMENT_METHOD,
#ifdef _NWK_CONCENTRATOR_
  .csNwkConcentratorDiscoveryTime = NWK_CONCENTRATOR_DISCOVERY_TIME,
#endif
  .csJoinCtrl = {.method = NWK_JOIN_BY_DEFAULT},
  .csLeaveRejoinCtrl = NWK_DEFINE_LEAVE_CONTROL_DEFAULT,
  .csLeaveNonRejoinCtrl = NWK_DEFINE_LEAVE_CONTROL_DEFAULT,
  /* ZDO parameters */
  .csEndDeviceSleepPeriod = CS_END_DEVICE_SLEEP_PERIOD,
  .csFfdSleepPeriod = CS_FFD_SLEEP_PERIOD,
  .csRxOnWhenIdle = (CS_DEVICE_TYPE == DEVICE_TYPE_END_DEVICE) ? CS_RX_ON_WHEN_IDLE : true,
  .csComplexDescriptorAvailable = CS_COMPLEX_DESCRIPTOR_AVAILABLE,
  .csUserDescriptorAvailable = CS_USER_DESCRIPTOR_AVAILABLE,
  .csUserDescriptor = {.FieldLength = ZDP_USER_DESC_FIELD_SIZE, .FieldName = "Microchip"},
  .csIndirectPollRate = CS_INDIRECT_POLL_RATE,
  .csZdoJoinAttempts = CS_ZDO_JOIN_ATTEMPTS,
  .csZdoJoinInterval = CS_ZDO_JOIN_INTERVAL,
  .csExtPANID = CCPU_TO_LE64(CS_EXT_PANID), /* user-defined PAN ID */
#ifdef _CUSTOM_PASSIVE_ACK_THRESHOLD_
  .csPassiveAckThreshold = CS_CUSTOM_PASSIVE_ACK_THRESHOLD,
#endif /* _CUSTOM_PASSIVE_ACK_THRESHOLD_ */

#ifdef _CUSTOM_SUPPRESS_RETRANSMISSION_
  .csCustomRetransmissionMask  = CS_CUSTOM_RETRANSMISSION_MASK,
#endif /* _CUSTOM_SUPPRESS_RETRANSMISSION_ */

  /* PDS parameters*/
  .csDtrWakeup = CS_DTR_WAKEUP,
  .csStackVersion = 0,
  /* ZCL parameters */
#ifdef _ZCL_SUPPORT_ 
  #if (APP_USE_OTAU == 1) && defined(OTAU_CLIENT)
  .csOtauServerDiscoveryPeriod = CS_ZCL_OTAU_SERVER_DISCOVERY_PERIOD,
  .csOtauServerPageRequestUsage = CS_ZCL_OTAU_IMAGE_PAGE_REQUEST_ENABLE,
  .csOtauQueryInterval = CS_ZCL_OTAU_QUERY_INTERVAL,
  .csOtauMaxRetryCount = CS_ZCL_OTAU_MAX_RETRY_COUNT,
  .csOtauUpgradeImageType = CS_ZCL_OTAU_DEFAULT_IMAGE_TYPE,
  .csOtauFileVersion = CS_ZCL_OTAU_FILE_VERSION,
  #endif /* APP_USE_OTAU == 1 */
#endif /* ZCL_SUPPORT == 1 */

    /* Security parameters */
#ifdef _SECURITY_
  .csSecurityOn = CS_SECURITY_ON,
  .csZdoSecurityStatus = CS_ZDO_SECURITY_STATUS,
  .csApsSecurityTimeoutPeriod = CS_APS_SECURITY_TIMEOUT_PERIOD,
#endif /* _SECURITY_ */
#if defined (_STATS_ENABLED_)
  .csStackLeftThreshold = CS_STACK_LEFT_THRESHOLD,
#endif
#endif /* _MAC2_ */

  /* NWK distributed security parameters */
#if defined(_DISTRIBUTED_SECURITY_) && defined(_FFD_)
  .csNwkDistributedSecurity = CS_NWK_DISTRIBUTED_SECURITY
#endif /* defined(_DISTRIBUTED_SECURITY_) && defined(_FFD_) */
};

#ifdef _SECURITY_
uint8_t defaultKey[SECURITY_KEY_SIZE] = CS_NETWORK_KEY;
uint8_t distributedSecurityGlobalLinkKey[SECURITY_KEY_SIZE] = CS_DEFAULT_DISTRIBUTED_SECURITY_LINK_KEY;
uint8_t touchlinkPreconfiguredLinkKey[SECURITY_KEY_SIZE] = CS_DEFAULT_TOUCHLINK_PRECONFIGURED_LINK_KEY;
#endif /* _SECURITY_ */

CS_ReadOnlyItems_t PROGMEM_DECLARE(csReadOnlyItems) =
{
  /* MAC parameters */
  .csMacFrameRxBufferSize = CS_MAC_FRAME_RX_BUFFER_SIZE,
#ifdef _FFD_
  .csMacFrameDataReqBufferSize = CS_MAC_FRAME_DATA_REQ_BUFFER_SIZE,
#endif
#ifdef _MAC_BAN_NODE_
  .csMacBanTableSize = CS_BAN_TABLE_SIZE,
#endif /* _MAC_BAN_NODE_ */
  .csRadioArbMode = CS_RADIO_ARB_MODE,
  /* NWK parameters */
#ifndef _MAC2_
  .csNwkRouteCacheSize = CS_ROUTE_CACHE_SIZE,
  .csNeibTableSize = CS_NEIB_TABLE_SIZE,
  .csMacPanDescriptorAmount = CS_NEIB_TABLE_SIZE,
  .csMaxChildrenAmount = CS_MAX_CHILDREN_AMOUNT,
  .csMaxChildrenRouterAmount = CS_MAX_CHILDREN_ROUTER_AMOUNT,
  .csMaxNetworkDepth = CS_MAX_NETWORK_DEPTH,
  .csNwkBuffersAmount = CS_NWK_BUFFERS_AMOUNT,
  .csJoinIndObjAmount = CS_JOIN_IND_OBJ_AMOUNT,
  .csRouteTableSize = CS_ROUTE_TABLE_SIZE,
  .csAddressMapTableSize = CS_ADDRESS_MAP_TABLE_SIZE,
  .csRouteDiscoveryTableSize = CS_ROUTE_DISCOVERY_TABLE_SIZE,
  .csNwkBttSize = CS_NWK_BTT_SIZE,
  .csNwkMaxPermitJoinPeriodLogic = CS_NWK_MAX_PERMIT_JOIN_PERIOD_LOGIC,
  .csNwkLinkStatusCount = CS_NWK_LINK_STATUS_COUNT,
  .csNwkLinkStatusFragmentationPeriod = CS_NWK_LINK_STATUS_FRAGMENTATION_PERIOD,
#ifdef _CUSTOM_NWK_ADDRESS_CONFLICT_WAIT_TIME_AFTER_RESET_
  .csAddrConflictWaitTimeAfterReset = CS_NWK_ADDRESS_CONFLICT_WAIT_TIME_AFTER_RESET,
#endif
#ifdef _GROUP_TABLE_
  .csGroupTableSize = CS_GROUP_TABLE_SIZE,
#endif /* _GROUP_TABLE_ */
#ifdef _NWK_PASSIVE_ACK_
  .csPassiveAckAmount = CS_NWK_PASSIVE_ACK_AMOUNT,
#endif /* _NWK_PASSIVE_ACK_ */

  /* ZDO parameters */
  .csZdoMaxSyncFailAmount = CS_ZDO_MAX_SYNC_FAIL_AMOUNT,
  .csZdoParentLinkRetryTreshold = CS_ZDO_PARENT_LINK_RETRY_THRESHOLD,

  /* APS parameters */
  .csApsDataReqBuffersAmount = CS_APS_DATA_REQ_BUFFERS_AMOUNT,
  .csApsAckFrameBuffesAmount = CS_APS_ACK_FRAME_BUFFERS_AMOUNT,
  .csDuplicateRejectionTableSize = CS_DUPLICATE_REJECTION_TABLE_SIZE,
#ifdef _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
  .csApsDuplicateEntryCounterSize = CS_APS_DUPLICATE_ENTRY_COUNTER_SIZE,
#endif /* _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_ */
  .csApsDuplicateEntryLifeTime = CS_APS_DUPLICATE_ENTRY_LIFE_TIME,
#ifdef _BINDING_
  .csApsBindingTableSize = CS_APS_BINDING_TABLE_SIZE,
#endif /* _BINDING_ */
#ifdef _APS_FRAGMENTATION_
  .csApsMaxBlocksAmount = CS_APS_MAX_BLOCKS_AMOUNT,
  .csApsBlockSize = CS_APS_BLOCK_SIZE,
  .csApsTxBlockSize = CS_APS_TX_BLOCK_SIZE,
  .csApsRxBlockSize = CS_APS_RX_BLOCK_SIZE,
#endif /* _APS_FRAGMENTATION_ */

#ifdef _ZCL_SUPPORT_
  .csZclMemoryBuffersAmount = CS_ZCL_MEMORY_BUFFERS_AMOUNT,
  .csZclMemoryBuffersSize = CS_ZCL_BUFFER_SIZE,
#if APP_USE_OTAU == 1
#ifdef OTAU_CLIENT
    .csOtauDefaultServerAddress = CS_ZCL_OTAU_DEFAULT_UPGRADE_SERVER_IEEE_ADDRESS,
    .csOtauDiscoveredServerAmount = CS_ZCL_OTAU_DISCOVERED_SERVER_AMOUNT,
#endif
  #endif /* APP_USE_OTAU == 1 */
#endif /* ZCL_SUPPORT == 1 */

#ifdef _SECURITY_
  .csNwkSecurityKeysAmount = CS_NWK_SECURITY_KEYS_AMOUNT,
#ifdef _TRUST_CENTRE_
  .csMaxTcAuthenticProcessAmount = CS_MAX_TC_AUTHENTIC_PROCESS_AMOUNT,
#endif /* _TRUST_CENTRE_ */
#ifdef _LINK_SECURITY_
  #ifdef _TRUST_CENTRE_
  .csMaxTcEstablishKeyAmount = CS_MAX_TC_ESTABLISH_KEY_AMOUNT,
  #endif /* _TRUST_CENTRE_ */
  .csApsKeyPairDescriptorsAmount = CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT,
#endif /* _LINK_SECURITY_ */
#endif /* _SECURITY_ */
#ifdef _PERMISSIONS_
  .csPermissionsTableSize = CS_PERMISSIONS_TABLE_SIZE,
#endif /* _PERMISSIONS_ */
  /* Other parameters */
  .csManufacturerCode = CCPU_TO_LE16(CS_MANUFACTURER_CODE),
  .csZdoCommandsAmount = CS_ZDO_COMMANDS_AMOUNT,
  .csNwkQuotas = {CS_NWK_OUTPUT_COMMAND_PACKET_QUOTA, \
                  CS_NWK_OUTPUT_COMMAND_CHILD_PACKET_QUOTA,\
                  CS_NWK_INPUT_COMMAND_PACKET_QUOTA, \
                  CS_NWK_INPUT_DATA_PACKET_QUOTA, \
                  CS_NWK_TRANSIT_PACKET_QUOTA, \
                  CS_NWK_LOOPBACK_PACKET_QUOTA, \
                  CS_NWK_EXTERN_PACKET_QUOTA},
#ifdef _CHILD_MANAGEMENT_
  .csEndDeviceTimeoutIndObjAmount = CS_ENDDEVICE_TIMEOUT_IND_OBJ_AMOUNT,
#endif /* _CHILD_AMANGEMENT_ */
#ifdef _NWK_CONCENTRATOR_
  .csNwkConcentratorConfiguration = CS_NWK_CONCENTRATOR_CONFIGURATION,
#endif /* _NWK_CONCENTRATOR_ */
#ifdef BDB_SUPPORT
  .joinInfoEntriesAmount = CS_BDB_NODE_JOIN_INFO_ENTRIES_AMOUNT,            //BDB
  .distributedNetworkAddress = CS_DISTRIBUTED_NETWORK_ADDRESS,              //BDB
  .touchlinkSupport = CS_TOUCHLINK_SUPPORT_FLAG                             //BDB
#endif   
#endif /* !_MAC2_*/
};

/*
 * \brief Configuration Server items information table stored in FLASH.
 *        Table record contains informaion about corresponding item displacement and size.
 *        Records are automatically sorted by item location and type
 *        (atomic parameter or memory region).
 */
#define RAM_PARAMETER(label, id, addr) [id] = {{(const void FLASH_PTR*)&(addr)}, sizeof(addr)},
#define DUMMY_RAM_PARAMETER(label, id) [id] = {{NULL}, 0},
#define FLASH_PARAMETER(label, id, addr) [id] = {{(const void FLASH_PTR*)&(addr)}, sizeof(addr)},
#define DUMMY_FLASH_PARAMETER(label, id) [id] = {{NULL}, 0},
#define MEMORY_REGION(label, id, addr) [id] = {{(const void FLASH_PTR*)&(addr)}, 0},
#define DUMMY_MEMORY_REGION(label, id) [id] = {{NULL}, 0},

CS_MemoryItem_t PROGMEM_DECLARE(csVarItems[]) =
{
  #include "configserver/include/private/csVarTable.h"
};

CS_MemoryItem_t PROGMEM_DECLARE(csConstItems[]) =
{
  #include "configserver/include/private/csConstTable.h"
};

CS_MemoryItem_t PROGMEM_DECLARE(csMemItems[]) =
{
  #include "configserver/include/private/csMemTable.h"
};

#undef RAM_PARAMETER
#undef DUMMY_RAM_PARAMETER
#undef FLASH_PARAMETER
#undef DUMMY_FLASH_PARAMETER
#undef MEMORY_REGION
#undef DUMMY_MEMORY_REGION

/******************************************************************************
                    Implementation section
******************************************************************************/

/******************************************************************************
\brief Set Configuration Server memory to its default state
\param[in] zgbIBdata - IB data
******************************************************************************/
void csSetToDefault(ZB_CS_SYS_IBData_t *zgbIBdata)
{
#ifdef _ZGPD_SPECIFIC_
#ifdef ZGP_SECURITY_ENABLE
  uint8_t linkKey[ZGP_SEC_KEY_SIZE] = CS_ZGP_SECURITY_LINK_KEY;
  uint8_t key[ZGP_SEC_KEY_SIZE] = CS_ZGP_DEFAULT_SECURITY_KEY;
#endif 
#endif
  
  /* Restore information bases default values from FLASH */
#if defined(_USE_KF_MAC_)
  tal_pib_IeeeAddress = CCPU_TO_LE64(CS_UID);
  maxFrameTransmissionTime = CS_MAX_FRAME_TRANSMISSION_TIME;
#else
  memset(&csPIB, 0x00, sizeof(PIB_t));
  //Reads the UID from Information block as part of Factory Set  
  if (zgbIBdata->validityCheck.extMacDevAddrValid)
  {
    uint64_t devIEEEAddress = 0;
    memcpy(&devIEEEAddress,&zgbIBdata->extMacDevAddr[0], sizeof(uint64_t));
    csPIB.macAttr.extAddr = devIEEEAddress;
  }
  else
  {
    if (CS_UID != 0)
    {
      csPIB.macAttr.extAddr = CCPU_TO_LE64(CS_UID);
    }
    else
    {
      csPIB.macAttr.extAddr = TRNG_ReadData();
    }
  }
  csPIB.macAttr.maxFrameTransmissionTime = CS_MAX_FRAME_TRANSMISSION_TIME;
  csPIB.phyAttr.ccaMode = CS_PHY_CC_CCA_MODE;
  csPIB.macAttr.ccaEdThres = CS_RF_CCA_ED_THRES;
  
  //Reads from the User to set the Region otherwise falls back to the CS default.
  if (zgbIBdata->validityCheck.antennaGainValid)
    csSIB.csRfTxAntennaGain = zgbIBdata->antGain;//valid antennai gain from IB found so update
  else
    csSIB.csRfTxAntennaGain  = CS_TX_ANTENNA_GAIN;

  csPIB.phyAttr.transmitPower  = CS_RF_TX_POWER;//radiated power

  //Update csRfTxPower default as well.
  csSIB.csRfTxPower = csPIB.phyAttr.transmitPower;

#endif // defined(_USE_KF_MAC_)

#ifndef _MAC2_
  memcpy_P(&csNIB, &defaultNIB, sizeof(NIB_t));
  memcpy_P(&csZIB, &defaultZIB, sizeof(ZIB_t));
  memcpy_P(&csAIB, &defaultAIB, sizeof(AIB_t));
#endif /* _MAC2_ */
#ifdef _ZGPD_SPECIFIC_
  csZGIB.zgpdSpecific = CS_ZGPD_SPECIFIC_ENABLE;
  csZGIB.deviceParams.srcID = CCPU_TO_LE32(CS_ZGP_SRCID);
  csZGIB.deviceParams.appId = CS_ZGP_APPID;
  csZGIB.deviceParams.endPoint = CS_ZGP_ENDPOINT;
  csZGIB.deviceParams.commissioningType = CS_ZGP_COMMISSIONING_TYPE;
  csZGIB.deviceParams.useIncSeqNum = CS_ZGP_USE_INC_SEQ_NUM;
  csZGIB.deviceParams.useCsmaCA = CS_ZGP_USE_CSMA_CA;
  csZGIB.deviceParams.rxAfterTx = CS_ZGP_RX_AFTER_TX;
  csZGIB.deviceParams.rxWindow = CS_ZGP_RX_WINDOW;
  csZGIB.deviceParams.secLevel = CS_ZGP_SECURITY_LEVEL;
  csZGIB.stackparams.panId = CS_NWK_PANID;
  csZGIB.stackparams.identicalFrameTxDelay = CS_ZGP_IDENTICAL_FRAME_TX_DELAY;
  csZGIB.stackparams.numOfFramesInSeq = CS_ZGP_NO_OF_FRAMES_IN_SEQ; 
  csZGIB.stackparams.commissioningState = sCommIdle;
  csZGIB.stackparams.channelConfigState = sChannelConfigIdle;
#ifdef ZGP_SECURITY_ENABLE
  csZGIB.secParams.secKey.keyType = CS_ZGP_SECURITY_KEY_TYPE;
  csZGIB.secParams.outFrmCntr = 0x00;
  if (zgpSetLinkKey(linkKey))
  {
    if (zgpIsValidKey(zgpGetSecParams()->secKey.gpLinkKey))
    {
      zgpGetSecParams()->secKey.gpLinkKeyIsSet = true;
    }
  }
  
  if (zgpSetSecurityKey(key))
  {
    if (zgpIsValidKey(zgpGetSecParams()->secKey.key))
    {
      zgpGetSecParams()->secKey.keyIsSet = true;
    }
  }

  csZGIB.secParams.secKey.keyType = CS_ZGP_SECURITY_KEY_TYPE;
#endif //ZGP_SECURITY_ENABLE
#endif
  memcpy_P(&csSIB, &defaultSIB, sizeof(SIB_t));
  memset(&stackBuffers, 0x00, sizeof(CS_StackBuffers_t));
#ifdef BDB_SUPPORT
  csBIB.touchlinkRssiCorrection = CS_BDB_TOUCHLINK_RSSI_CORRECTION;
  csBIB.touchlinkRssiThershold = CS_BDB_TOUCHLINK_RSSI_THERSHOLD;
  csBIB.touchlinkZeroDbmTxPwr = CS_BDB_TOUCHLINK_ZERO_DBM_TX_POWER;
  csBIB.primaryChannelMask = CS_BDB_PRIMARY_CHANNELS_MASK;
  csBIB.secondaryChannelMask = CS_BDB_SECONDARY_CHANNELS_MASK;
#endif
  csSIB.installCodeBasedJoinLinkKeyType = CS_INSTALL_CODE_BASED_JOIN_LINK_KEY_TYPE;
}

#ifndef _MAC2_
/******************************************************************************
  \brief Backing up Network parameters
******************************************************************************/
void CS_BackupNwkParams(void)
{
    backupExtendedBcSet();
    memcpy4ByteAligned((uint8_t*)&backupRamData.backupExtGenMem, &extGenMemParams, sizeof(ExtGetMem_t));
    //BDB
    memcpy4ByteAligned((uint8_t*)&backupRamData.backupBdbIB, (uint8_t*)&bdbIB, sizeof(BDBIB_t));
    //nwk Security IB
    memcpy4ByteAligned((uint8_t*)&backupRamData.securityIB, (uint8_t*)&csNIB.securityIB, sizeof(NWK_SecurityIB_t));
    //security counter
    memcpy4ByteAligned(&backupRamData.backupOutCounterTop, &csNIB.securityCounters.outCounterTop, 2); 
    //zll dev info params
    memcpy4ByteAligned((uint8_t*)&backupRamData.backupDeviceInfoParams, (uint8_t*)&deviceInfoParams, sizeof(DeviceInfoParameters_t));
    //neighbor table
    memcpy4ByteAligned(backupRamData.backupCsNeibTable,stackBuffers.csNeibTable,NEIGHBOR_TABLE_ITEM_SIZE);
    //nwk keys
    memcpy4ByteAligned(&backupRamData.backupCsNwkSecKeys, &stackBuffers.csNwkSecKeys, SECURITY_KEYS_ITEM_SIZE);
    memcpy4ByteAligned(backupRamData.backupCsApsKeyPairDescriptors, stackBuffers.csApsKeyPairDescriptors, KEY_PAIR_DESCRIPTOR_ITEM_SIZE);
    //binding table
    for (uint8_t i=0; i< CS_APS_BINDING_TABLE_SIZE; i++)
        backupRamData.backupCsApsBindingTable[i] = stackBuffers.csApsBindingTable[i];
    //zcl mem
    memcpy4ByteAligned(&backupRamData.backupZclMem, &zclMem, sizeof(ZclMem_t)); 

}

/******************************************************************************
  \brief Restoring Backup Network parameters
 ******************************************************************************/
void  CS_RestoreNwkParams(void)
{
    memcpy4ByteAligned(&extGenMemParams,(uint8_t*)&backupRamData.backupExtGenMem,sizeof(ExtGetMem_t));
    restoreExtendedBcSet();
     //BDB
    memcpy4ByteAligned((uint8_t*)&bdbIB, (uint8_t*)&backupRamData.backupBdbIB, sizeof(BDBIB_t));
    //nwk Security IB
    memcpy4ByteAligned((uint8_t*)&csNIB.securityIB, (uint8_t*)&backupRamData.securityIB, sizeof(NWK_SecurityIB_t));
    //security counter
    memcpy4ByteAligned(&csNIB.securityCounters.outCounterTop, &backupRamData.backupOutCounterTop, 2);
    //device Params
    memcpy4ByteAligned((uint8_t*)&deviceInfoParams, (uint8_t*)&backupRamData.backupDeviceInfoParams, sizeof(DeviceInfoParameters_t));
    //neighbor table
    memcpy4ByteAligned(stackBuffers.csNeibTable, backupRamData.backupCsNeibTable, NEIGHBOR_TABLE_ITEM_SIZE);

    memcpy4ByteAligned(&stackBuffers.csNwkSecKeys, &backupRamData.backupCsNwkSecKeys, SECURITY_KEYS_ITEM_SIZE);
    memcpy4ByteAligned(stackBuffers.csApsKeyPairDescriptors, backupRamData.backupCsApsKeyPairDescriptors,  KEY_PAIR_DESCRIPTOR_ITEM_SIZE);
    for (uint8_t i=0; i< CS_APS_BINDING_TABLE_SIZE; i++)
        stackBuffers.csApsBindingTable[i] = backupRamData.backupCsApsBindingTable[i] ;
    //zcl mem
    memcpy4ByteAligned(&zclMem, &backupRamData.backupZclMem, sizeof(ZclMem_t));
}

/******************************************************************************
  \brief Backing up Network parameters
******************************************************************************/
static void backupExtendedBcSet(void)
{
  extGenMemParams.csUid = csPIB.macAttr.extAddr;

  extGenMemParams.txPower = csSIB.csRfTxPower;
  extGenMemParams.extPanId = csSIB.csExtPANID;
  extGenMemParams.channelMask = csSIB.csChannelMask;
  extGenMemParams.channelPage = csNIB.channelPage;
  extGenMemParams.deviceType = csNIB.deviceType;
  extGenMemParams.rxOnWhenIdle = csSIB.csRxOnWhenIdle;
  extGenMemParams.complexDescrAvailable = csSIB.csComplexDescriptorAvailable;
  extGenMemParams.userDescrAvailable = csSIB.csUserDescriptorAvailable;
  extGenMemParams.userDescr = csSIB.csUserDescriptor;
  extGenMemParams.panId = csSIB.csNwkPanid;
  extGenMemParams.predefinedPanId = csSIB.csNwkPredefinedPanid;
  extGenMemParams.shortAddress = csNIB.networkAddress;
  extGenMemParams.uniqueNwkAddress = csNIB.uniqueAddr;
  extGenMemParams.leaveReqAllowed = csNIB.leaveReqAllowed;
  extGenMemParams.dtrWakeUp = csSIB.csDtrWakeup;
  extGenMemParams.updateId = csNIB.updateId;
#if defined _SECURITY_
  extGenMemParams.extTcAddress = csAIB.trustCenterAddress;
  extGenMemParams.nwkTcAddress = csAIB.tcNwkAddr;
  extGenMemParams.securityStatus = csSIB.csZdoSecurityStatus;
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
  extGenMemParams.tcPermissions = csAIB.tcSecurityPolicy;
#endif //#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#endif
  extGenMemParams.parentNwkAddress = csNIB.parentNetworkAddress;
  extGenMemParams.nwkDepth = csNIB.depth;
  extGenMemParams.nwkExtPanId = csNIB.extendedPanId;
  extGenMemParams.logicalChannel = csSIB.csNwkLogicalChannel;
}
/******************************************************************************
  \brief Restoring Network parameters
******************************************************************************/
static void restoreExtendedBcSet(void)
{

  // update appropriate BC structures
  csPIB.macAttr.extAddr = extGenMemParams.csUid;
  csSIB.csRfTxPower = extGenMemParams.txPower;
  csSIB.csExtPANID = extGenMemParams.extPanId;
  csSIB.csChannelMask = extGenMemParams.channelMask;
  csNIB.channelPage = extGenMemParams.channelPage;
  csNIB.deviceType = extGenMemParams.deviceType;
  csSIB.csRxOnWhenIdle = extGenMemParams.rxOnWhenIdle;
  csSIB.csComplexDescriptorAvailable = extGenMemParams.complexDescrAvailable;
  csSIB.csUserDescriptorAvailable = extGenMemParams.userDescrAvailable;
  csSIB.csUserDescriptor = extGenMemParams.userDescr;
  csSIB.csNwkPanid = extGenMemParams.panId;
  csSIB.csNwkPredefinedPanid = extGenMemParams.predefinedPanId;
  csNIB.networkAddress = extGenMemParams.shortAddress;
  csNIB.uniqueAddr = extGenMemParams.uniqueNwkAddress;
  csNIB.leaveReqAllowed = extGenMemParams.leaveReqAllowed;
  csSIB.csDtrWakeup = extGenMemParams.dtrWakeUp;
  csNIB.updateId = extGenMemParams.updateId;
#ifdef _SECURITY_  
  csAIB.trustCenterAddress = extGenMemParams.extTcAddress;
  csAIB.tcNwkAddr = extGenMemParams.nwkTcAddress;
  csSIB.csZdoSecurityStatus = extGenMemParams.securityStatus;
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
  csAIB.tcSecurityPolicy = extGenMemParams.tcPermissions;
#endif //#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#endif
  csNIB.parentNetworkAddress = extGenMemParams.parentNwkAddress;
  csNIB.depth = extGenMemParams.nwkDepth;
  csNIB.extendedPanId = extGenMemParams.nwkExtPanId;
  csSIB.csNwkLogicalChannel = extGenMemParams.logicalChannel;
  csNIB.deviceType = backupRamData.backupExtGenMem.deviceType;
}
#endif /* _MAC2_ */
/* eof csMem.c */

