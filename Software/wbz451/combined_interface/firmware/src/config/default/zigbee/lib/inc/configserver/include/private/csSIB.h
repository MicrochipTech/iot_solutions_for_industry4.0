/*******************************************************************************
  CS SIB Header File

  Company
    Microchip Technology Inc.

  File Name
    csSIB.h

  Summary
    This file contains the BitCloud stack information base.

  Description
    This header file defines the interface to manage the BitCloud stack information base.
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

#ifndef _CSSIB_H_
#define _CSSIB_H_

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <configserver/include/csDefaults.h>
#ifdef _MAC_BAN_NODE_
  #include <mac_phy/include/macBanNode.h>
#endif /* _MAC_BAN_NODE_ */
#ifndef _MAC2_
  #include <nwk/include/nwkConfigServer.h>
  #include <aps/include/apsConfigServer.h>
  #include <zdo/include/zdoConfigServer.h>
#endif
#if APP_USE_OTAU == 1
  #include <zcl/include/zclOTAUCluster.h>
#endif
/******************************************************************************
                    Types section
******************************************************************************/
/**//**
 * \brief Config Server parameter handler
 */
typedef struct _CS_MemoryItem_t
{
  union
  {
    const void FLASH_PTR* flashValue;
    void* ramValue;
  } value;
  uint16_t size;
} CS_MemoryItem_t;

/**//**
 * \brief Read-only parameters, stored in FLASH
 */
typedef struct _CS_ReadOnlyItems_t
{
  /* MAC parameters */
  uint16_t csMacFrameRxBufferSize;
#ifdef _FFD_
  uint16_t csMacFrameDataReqBufferSize;
#endif
#ifdef _MAC_BAN_NODE_
  MAC_BanTableSize_t csMacBanTableSize;
#endif /* _MAC_BAN_NODE_ */
 uint8_t csRadioArbMode; //arbiter mode
#ifndef _MAC2_
  /* NWK parameters */
  NwkRouteCacheSize_t csNwkRouteCacheSize;
  NwkSizeOfNeighborTable_t csNeibTableSize;
  NwkSizeOfAddressMap_t csAddressMapTableSize;
  uint8_t csMacPanDescriptorAmount;
  uint8_t csMaxChildrenAmount;
  uint8_t csMaxChildrenRouterAmount;
  uint8_t csMaxNetworkDepth;
  NwkPacketsAmount_t csNwkBuffersAmount;
  NwkJoinIndObjAmount_t csJoinIndObjAmount;
  NwkRoutingTableSize_t csRouteTableSize;
  NwkRouteDiscoveryTableSize_t csRouteDiscoveryTableSize;
  NwkBttSize_t csNwkBttSize;
  uint8_t csNwkLinkStatusCount;
  uint32_t csNwkLinkStatusFragmentationPeriod;
#ifdef _CUSTOM_NWK_ADDRESS_CONFLICT_WAIT_TIME_AFTER_RESET_
  uint32_t csAddrConflictWaitTimeAfterReset;
#endif
#ifdef _GROUP_TABLE_
  NWK_GroupTableSize_t csGroupTableSize;
#endif /* _GROUP_TABLE_ */
#ifdef _NWK_PASSIVE_ACK_
  NwkPassiveAckAmount_t csPassiveAckAmount;
#endif /* _NWK_PASSIVE_ACK_ */

  /* ZDO parameters */
  uint8_t  csZdoMaxSyncFailAmount;
  uint8_t  csZdoParentLinkRetryTreshold;

  /* APS parameters */
  uint8_t  csApsDataReqBuffersAmount;
  uint8_t  csApsAckFrameBuffesAmount;
  uint8_t  csDuplicateRejectionTableSize;
#ifdef _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
  uint8_t  csApsDuplicateEntryCounterSize;
#endif // _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
  uint32_t csApsDuplicateEntryLifeTime;
#ifdef _BINDING_
  uint8_t  csApsBindingTableSize;
#endif /* _BINDING_ */
#ifdef _APS_FRAGMENTATION_
  uint8_t  csApsMaxBlocksAmount;
  uint16_t csApsBlockSize;
#endif /* _APS_FRAGMENTATION_ */

  /* ZCL parameters */
#ifdef _ZCL_SUPPORT_ 
  uint8_t csZclMemoryBuffersAmount;
  uint16_t csZclMemoryBuffersSize;
#if APP_USE_OTAU == 1

#ifdef OTAU_CLIENT 
  ExtAddr_t csOtauDefaultServerAddress;
  uint8_t  csOtauDiscoveredServerAmount;
#endif
  #endif /* APP_USE_OTAU == 1 */
#endif /* ZCL_SUPPORT == 1 */
  /* Other parameters */
  uint16_t csManufacturerCode;
  /* Security parameters */
#ifdef _SECURITY_
  NwkKeyAmount_t csNwkSecurityKeysAmount;
#ifdef _TRUST_CENTRE_
    uint8_t csMaxTcAuthenticProcessAmount;
#endif /* _TRUST_CENTRE_ */
#ifdef _LINK_SECURITY_
  APS_KeyPairAmount_t csApsKeyPairDescriptorsAmount;
  #ifdef _TRUST_CENTRE_
    uint8_t csMaxTcEstablishKeyAmount;
  #endif /* _TRUST_CENTRE_ */
#endif /* _LINK_SECURITY_ */
#endif /* _SECURITY_ */
#ifdef _PERMISSIONS_
  ZdoPermissionsTableSize_t csPermissionsTableSize;
#endif /* _PERMISSIONS_ */
#ifdef _APS_FRAGMENTATION_
  uint8_t csApsTxBlockSize;
  uint8_t csApsRxBlockSize;
#endif /* _APS_FRAGMENTATION_ */
  NWK_MaxPermitJoiningPeriod_t csNwkMaxPermitJoinPeriodLogic;
  uint8_t csZdoCommandsAmount;
  uint8_t csNwkQuotas[NWK_BUFFER_TYPE_LAST - 1U];
#ifdef _CHILD_MANAGEMENT_
  uint8_t csEndDeviceTimeoutIndObjAmount;
#endif /* _CHILD_MANAGEMENT_ */
#ifdef _NWK_CONCENTRATOR_
  bool csNwkConcentratorConfiguration;
#endif
#ifdef BDB_SUPPORT
  uint8_t joinInfoEntriesAmount;            //BDB
  uint16_t distributedNetworkAddress;       //BDB
  bool touchlinkSupport;                    //BDB
#endif
#endif /* _MAC2_ */
} CS_ReadOnlyItems_t;

/**//**
 * \brief Common stack information base
 */
typedef struct _SIB_t
{
  /* MAC parameters */
  uint32_t    csMacTransactionTime;
  int8_t      csRfTxAntennaGain;  //Future Use.
  int8_t      csRfTxPowerType;  
  int8_t      csRfTxPower;
  int8_t      csRfch26MaxTxPower;
  uint32_t    csChannelMask;
#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_
  bool        csMacSendEmptyDataFrame;
#endif /*_PENDING_EMPTY_DATA_FRAME_*/
#endif /*_FFD_*/
#ifdef AT86RF212
  bool        csLbtMode;
#endif /* AT86RF212 */
#ifndef _MAC2_

  /* NWK parameters */
  PanId_t     csNwkPanid;
  bool        csNwkUseMulticast;
  uint8_t     csNwkMaxLinkStatusFailures;
  uint8_t     csNwkEndDeviceMaxFailures;
  uint8_t     csNwkLogicalChannel;
  bool        csNwkPredefinedPanid;
  uint8_t     csAddressAssignmentMethod;
#ifdef _NWK_CONCENTRATOR_
  uint32_t     csNwkConcentratorDiscoveryTime;
#endif
  NWK_JoinControl_t csJoinCtrl;
  NWK_LeaveControl_t csLeaveRejoinCtrl;
  NWK_LeaveControl_t csLeaveNonRejoinCtrl;
  /* ZDO parameters */
  uint32_t         csEndDeviceSleepPeriod;
  uint32_t         csFfdSleepPeriod;
  bool             csRxOnWhenIdle;
  bool             csComplexDescriptorAvailable;
  bool             csUserDescriptorAvailable;
  uint32_t         csIndirectPollRate;
  uint8_t          csZdoJoinAttempts;
  uint32_t         csZdoJoinInterval;
  UserDescriptor_t csUserDescriptor; /* to EEPROM */
  ExtPanId_t       csExtPANID; /* user-defined PAN ID */
#ifdef _CUSTOM_PASSIVE_ACK_THRESHOLD_
  uint8_t          csPassiveAckThreshold;
#endif /* _CUSTOM_PASSIVE_ACK_THRESHOLD_ */
#ifdef _CUSTOM_SUPPRESS_RETRANSMISSION_
  uint8_t          csCustomRetransmissionMask;
#endif /* _CUSTOM_SUPPRESS_RETRANSMISSION_ */
  /* PDS parameters*/
  bool    csDtrWakeup;
  uint32_t csStackVersion;
  uint32_t  csOtauFileVersion;
  /* ZCL parameters */
#ifdef _ZCL_SUPPORT_
  #if APP_USE_OTAU == 1
    uint32_t  csOtauServerDiscoveryPeriod;
    bool      csOtauServerPageRequestUsage;
    uint32_t  csOtauQueryInterval;
    uint8_t   csOtauMaxRetryCount;
    ZCL_OtauImageType_t  csOtauUpgradeImageType;
  #endif // APP_USE_OTAU == 1
#endif /* ZCL_SUPPORT == 1*/

  /* Security parameters */
#ifdef _SECURITY_
  uint32_t csApsSecurityTimeoutPeriod;
  bool      csSecurityOn;
  uint8_t   csZdoSecurityStatus;
#endif /* _SECURITY_ */
#endif /* _MAC2_ */
#if defined(_STATS_ENABLED_)
uint16_t    csStackLeftThreshold;
#endif
  /* NWK distributed security parameters */
#if defined(_DISTRIBUTED_SECURITY_) && defined(_FFD_)
  bool csNwkDistributedSecurity;
#endif /* defined(_DISTRIBUTED_SECURITY_) && defined(_FFD_) */
  bool installCodeBasedJoinLinkKeyType;
} SIB_t;

#endif /* _CSSIB_H_ */
/* eof csSIB.h */
