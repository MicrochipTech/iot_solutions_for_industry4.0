/*******************************************************************************
  CS VarTable Header File

  Company
    Microchip Technology Inc.

  File Name
    csVarTable.h

  Summary
    This file contains the Configuration Server RAM parameters information table.

  Description
    This header file defines the interface to access the CS RAM parameters information table.
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

/* This table contains information about particular paramter displacement address.
 *
 * This table should be inlined to external module.
 * RAM_PARAMETER(id, addr) and DUMMY_RAM_PARAMETER(id) macroses should be defined 
 * first to provide specific table morphing.
 *
 * DUMMY_RAM_PARAMETER(id) macro is used to specify few stack buffers sizes during 
 * the application compilation phase.
 */
 
/********************  PHY ************************/
#ifdef AT86RF212
RAM_PARAMETER(CS_LBT_MODE_ID,                     0,   csSIB.csLbtMode)                         //PHY
#endif
RAM_PARAMETER(CS_RF_MAX_CH26_TX_POWER_ID,         1,   csSIB.csRfch26MaxTxPower)                //PHY
RAM_PARAMETER(CS_RF_CCA_MODE_ID,                  2,   csPIB.phyAttr.ccaMode)                   //PHY
RAM_PARAMETER(CS_RF_CURRENT_CHANNEL_ID,           3,   csPIB.phyAttr.channel)                   //PHY
RAM_PARAMETER(CS_RF_TX_POWER_ID,                  4,   csSIB.csRfTxPower)                       //PHY
RAM_PARAMETER(CS_RF_CCA_ED_THRES_ID,              5,   csPIB.macAttr.ccaEdThres)                //PHY

/********************  MAC ************************/
#if defined(_USE_KF_MAC_)
RAM_PARAMETER(CS_UID_ID,                          6,   tal_pib_IeeeAddress)                         //MAC
RAM_PARAMETER(CS_MAX_FRAME_TRANSMISSION_TIME_ID,  7,   maxFrameTransmissionTime)                    //MAC
#else // defined(_USE_KF_MAC_)
RAM_PARAMETER(CS_UID_ID,                          6,   csPIB.macAttr.extAddr)                       //MAC
RAM_PARAMETER(CS_MAX_FRAME_TRANSMISSION_TIME_ID,  7,   csPIB.macAttr.maxFrameTransmissionTime)      //MAC
#endif // defined(_USE_KF_MAC_)
RAM_PARAMETER(CS_MAC_TRANSACTION_TIME_ID,         8,   csSIB.csMacTransactionTime)                  //MAC
#ifdef _FFD_
#ifdef _PENDING_EMPTY_DATA_FRAME_
RAM_PARAMETER(CS_MAC_SEND_EMPTY_DATA_FRAME_ID,    9,   csSIB.csMacSendEmptyDataFrame)               //MAC
#endif /* _PENDING_EMPTY_DATA_FRAME_ */
#endif /* _FFD_ */

/********************  NWK ************************/
#ifndef _MAC2_
RAM_PARAMETER(CS_MAX_NEIGHBOR_ROUTE_COST_ID,        10,   csNIB.maxNeighborRouteCost)             //NWK
RAM_PARAMETER(CS_MAX_LINK_ROUTE_COST_ID,            11,   csNIB.maxLinkRouteCost)                 //NWK
RAM_PARAMETER(CS_NWK_EXT_PANID_ID,                  12,   csNIB.extendedPanId)                    //NWK
RAM_PARAMETER(CS_NWK_ADDR_ID,                       13,   csNIB.networkAddress)                   //NWK
RAM_PARAMETER(CS_NWK_PARENT_ADDR_ID,                14,   csNIB.parentNetworkAddress)             //NWK
RAM_PARAMETER(CS_NWK_DEPTH_ID,                      15,   csNIB.depth)                            //NWK
RAM_PARAMETER(CS_NWK_UNIQUE_ADDR_ID,                16,   csNIB.uniqueAddr)                       //NWK
RAM_PARAMETER(CS_NWK_LEAVE_REQ_ALLOWED_ID,          17,   csNIB.leaveReqAllowed)                  //NWK
RAM_PARAMETER(CS_CHANNEL_PAGE_ID,                   18,   csNIB.channelPage)                      //NWK
RAM_PARAMETER(CS_NWK_USE_MULTICAST_ID,              19,   csSIB.csNwkUseMulticast)                //NWK
RAM_PARAMETER(CS_NWK_MAX_LINK_STATUS_FAILURES_ID,   20,   csSIB.csNwkMaxLinkStatusFailures)       //NWK
RAM_PARAMETER(CS_NWK_END_DEVICE_MAX_FAILURES_ID,    21,   csSIB.csNwkEndDeviceMaxFailures)        //NWK
RAM_PARAMETER(CS_NWK_LOGICAL_CHANNEL_ID,            22,   csSIB.csNwkLogicalChannel)              //NWK
RAM_PARAMETER(CS_NWK_PANID_ID,                      23,   csSIB.csNwkPanid)                       //NWK
RAM_PARAMETER(CS_NWK_PREDEFINED_PANID_ID,           24,   csSIB.csNwkPredefinedPanid)             //NWK
RAM_PARAMETER(CS_ADDRESS_ASSIGNMENT_METHOD_ID,      25,   csSIB.csAddressAssignmentMethod)        //NWK
RAM_PARAMETER(CS_DEVICE_TYPE_ID,                    26,   csNIB.deviceType)                       //NWK
RAM_PARAMETER(CS_PROTOCOL_VERSION_ID,               27,   csNIB.protocolVersion)                  //NWK
RAM_PARAMETER(CS_STACK_PROFILE_ID,                  28,   csNIB.stackProfile)                     //NWK
#endif

#ifdef _NWK_CONCENTRATOR_
RAM_PARAMETER(CS_CONCENTRATOR_DISCOVERY_TIME_ID,    29,   csSIB.csNwkConcentratorDiscoveryTime)   //NWK
#endif
#ifdef _SECURITY_
RAM_PARAMETER(CS_SECURITY_LEVEL_ID,                 30,   csNIB.securityIB.securityLevel)         //NWK
RAM_PARAMETER(CS_SECURITY_ALL_FRAMES_ID,            31,   csNIB.securityIB.secureAllFrames)       //NWK
RAM_PARAMETER(CS_NETWORK_KEY_ID,                    32,   defaultKey)                             //NWK
#endif
#ifndef _MAC2_
#ifdef _NWK_THRESHOLD_ROUTING_
RAM_PARAMETER(CS_SOFT_LINK_COST_THRESHOLD_ID,       33,   csNIB.softLinkCostThreshold)            //NWK
#endif /* _NWK_THRESHOLD_ROUTING_ */
#ifdef _CHILD_MANAGEMENT_
// End Device Timeout enum as defined in R21
RAM_PARAMETER(CS_END_DEVICE_TIMEOUT_ID,             34,   csNIB.endDeviceTimeoutDefault)          //NWK
RAM_PARAMETER(CS_PARENT_INFORMATION_ID,             35,   csNIB.parentInformation)  
#endif
#endif // _MAC2_
#if defined(_DISTRIBUTED_SECURITY_) && defined(_FFD_)
RAM_PARAMETER(CS_NWK_DISTRIBUTED_SECURITY_ID,       36,   csSIB.csNwkDistributedSecurity)         //NWK
#endif /* defined(_DISTRIBUTED_SECURITY_) && defined(_FFD_) */
#ifndef _MAC2_
#ifdef _CUSTOM_PASSIVE_ACK_THRESHOLD_
RAM_PARAMETER(CS_CUSTOM_PASSIVE_ACK_THRESHOLD_ID,   37,   csSIB.csPassiveAckThreshold)            //NWK
#endif /* _CUSTOM_PASSIVE_ACK_THRESHOLD_ */
#ifdef _CUSTOM_SUPPRESS_RETRANSMISSION_
RAM_PARAMETER(CS_CUSTOM_RETRANSMISSION_MASK_ID,     38,   csSIB.csCustomRetransmissionMask)       //NWK
#endif /* _CUSTOM_SUPPRESS_RETRANSMISSION_ */
#endif  /* _MAC2_ */

/********************  APS ************************/
#ifdef _APS_FRAGMENTATION_
RAM_PARAMETER(CS_APS_MAX_TRANSMISSION_WINDOW_SIZE_ID,   39,   csAIB.fragWindowSize)                   //APS
#endif
#ifndef _MAC2_
RAM_PARAMETER(CS_APS_MAX_FRAME_RETRIES_ID,              40,   csAIB.maxFrameRetries)                  //APS
#endif
#ifdef _SECURITY_
RAM_PARAMETER(CS_SECURITY_ON_ID,                        41,   csSIB.csSecurityOn)                     //APS
RAM_PARAMETER(CS_APS_TRUST_CENTER_ADDRESS_ID,           42,   csAIB.trustCenterAddress)               //APS
RAM_PARAMETER(CS_SHORT_TRUST_CENTER_ADDRESS_ID,         43,   csAIB.tcNwkAddr)                        //APS
RAM_PARAMETER(CS_APS_SECURITY_TIMEOUT_PERIOD_ID,        44,   csSIB.csApsSecurityTimeoutPeriod)       //APS
RAM_PARAMETER(CS_DISTRIBUTED_SECURITY_LINK_KEY_ID,      45,   distributedSecurityGlobalLinkKey)       //APS
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
RAM_PARAMETER(CS_TC_PERMISSIONS_ID,                     46,   csAIB.tcSecurityPolicy.flags)           //APS
#endif //#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#endif /* _SECURITY_ */

/********************  ZDO ************************/
#ifdef _SECURITY_
RAM_PARAMETER(CS_ZDO_SECURITY_STATUS_ID,          47,   csSIB.csZdoSecurityStatus)            //ZDO
#endif /* _SECURITY_ */
RAM_PARAMETER(CS_CHANNEL_MASK_ID,                 48,   csSIB.csChannelMask)                  //ZDO
#ifndef _MAC2_
RAM_PARAMETER(CS_SCAN_DURATION_ID,                49,   csZIB.scanDuration)                   //ZDO
RAM_PARAMETER(CS_PERMIT_DURATION_ID,              50,   csZIB.permitJoinDuration)             //ZDO
RAM_PARAMETER(CS_EXT_PANID_ID ,                   51,   csSIB.csExtPANID)                     //ZDO
RAM_PARAMETER(CS_INDIRECT_POLL_RATE_ID,           52,   csSIB.csIndirectPollRate)             //ZDO
RAM_PARAMETER(CS_END_DEVICE_SLEEP_PERIOD_ID,      53,   csSIB.csEndDeviceSleepPeriod)         //ZDO
RAM_PARAMETER(CS_FFD_SLEEP_PERIOD_ID,             54,   csSIB.csFfdSleepPeriod)               //ZDO
RAM_PARAMETER(CS_RX_ON_WHEN_IDLE_ID,              55,   csSIB.csRxOnWhenIdle)                 //ZDO
RAM_PARAMETER(CS_COMPLEX_DESCRIPTOR_AVAILABLE_ID, 56,   csSIB.csComplexDescriptorAvailable)   //ZDO
RAM_PARAMETER(CS_USER_DESCRIPTOR_AVAILABLE_ID,    57,   csSIB.csUserDescriptorAvailable)      //ZDO
RAM_PARAMETER(CS_ZDP_USER_DESCRIPTOR_ID,          58,   csSIB.csUserDescriptor)               //ZDO
RAM_PARAMETER(CS_ZDO_JOIN_ATTEMPTS_ID,            59,   csSIB.csZdoJoinAttempts)              //ZDO
RAM_PARAMETER(CS_ZDO_JOIN_INTERVAL_ID,            60,   csSIB.csZdoJoinInterval)              //ZDO
RAM_PARAMETER(CS_ZDP_RESPONSE_TIMEOUT_ID,         61,   csZIB.zdpResponseTimeout)             //ZDO
RAM_PARAMETER(CS_JOIN_CONTROL_ID,                 62,   csSIB.csJoinCtrl)                     //ZDO
RAM_PARAMETER(CS_LEAVE_REJOIN_CONTROL_ID,         63,   csSIB.csLeaveRejoinCtrl)              //ZDO
RAM_PARAMETER(CS_LEAVE_NON_REJOIN_CONTROL_ID,     64,   csSIB.csLeaveNonRejoinCtrl)           //ZDO
#endif /* _MAC2_ */

/********************  SYSTEM ************************/
#ifndef _MAC2_
RAM_PARAMETER(CS_STACK_VERSION_ID,            65,   csSIB.csStackVersion)                 //SYS
RAM_PARAMETER(CS_DTR_WAKEUP_ID,               66,   csSIB.csDtrWakeup)                    //SYS
#endif
#if defined(_STATS_ENABLED_)
RAM_PARAMETER(CS_STACK_LEFT_THRESHOLD_ID,     67,   csSIB.csStackLeftThreshold)           //SYS
#endif

/********************  ZLL ************************/
#ifdef _SECURITY_
RAM_PARAMETER(CS_TOUCHLINK_PRECONFIGURED_LINK_KEY_ID, 68,   touchlinkPreconfiguredLinkKey)  //ZLL
#endif

/********************  ZGP ************************/
#ifdef _ZGPD_SPECIFIC_
RAM_PARAMETER(CS_ZGPD_SPECIFIC_ENABLE_ID,     69,   csZGIB.zgpdSpecific)                    //ZGP
RAM_PARAMETER(CS_ZGP_SRCID_ID,                70,   csZGIB.deviceParams.srcID)              //ZGP
RAM_PARAMETER(CS_ZGP_USE_CSMA_CA_ID,          71,   csZGIB.deviceParams.useCsmaCA)          //ZGP
RAM_PARAMETER(CS_ZGP_NO_OF_FRAMES_IN_SEQ_ID,  72,   csZGIB.stackparams.numOfFramesInSeq)    //ZGP
RAM_PARAMETER(CS_ZGP_COMMISSIONING_TYPE_ID,   73,   csZGIB.deviceParams.commissioningType)  //ZGP
RAM_PARAMETER(CS_ZGP_SECURITY_LEVEL_ID,       74,   csZGIB.deviceParams.secLevel)           //ZGP
  #ifdef ZGP_SECURITY_ENABLE
RAM_PARAMETER(CS_ZGP_SECURITY_KEY_TYPE_ID,    75,   csZGIB.secParams.secKey.keyType)        //ZGP
  #endif //ZGP_SECURITY_ENABLE
RAM_PARAMETER(CS_ZGP_APPID_ID,                76,   csZGIB.deviceParams.appId)              //ZGP
RAM_PARAMETER(CS_ZGP_RX_AFTER_TX_ID,          77,   csZGIB.deviceParams.rxAfterTx)          //ZGP
RAM_PARAMETER(CS_ZGP_USE_INC_SEQ_NUM_ID,      78,   csZGIB.deviceParams.useIncSeqNum)       //ZGP
#endif /* ZGP */

/********************  OTAU ************************/
#ifdef _ZCL_SUPPORT_
  #if APP_USE_OTAU == 1
RAM_PARAMETER(CS_ZCL_OTAU_QUERY_INTERVAL_ID,                        79,   csSIB.csOtauQueryInterval)            //OTAU
RAM_PARAMETER(CS_ZCL_OTAU_DEFAULT_IMAGE_TYPE_ID,                    80,   csSIB.csOtauUpgradeImageType)         //OTAU
RAM_PARAMETER(CS_ZCL_OTAU_DEFAULT_SERVER_DISCOVERY_PERIOD_ID,       81,   csSIB.csOtauServerDiscoveryPeriod)    //OTAU
RAM_PARAMETER(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID,                       83,   csSIB.csOtauMaxRetryCount)            //OTAU
  #endif /* APP_USE_OTAU == 1 */
#endif /* ZCL_SUPPORT == 1 */

/********************  BDB ************************/
#ifdef BDB_SUPPORT
RAM_PARAMETER(CS_BDB_TOUCHLINK_RSSICORRECTION_ID,                   84,   csBIB.touchlinkRssiCorrection)          //BDB
RAM_PARAMETER(CS_BDB_TOUCHLINK_RSSITHERSHOLD_ID,                    85,   csBIB.touchlinkRssiThershold)           //BDB
RAM_PARAMETER(CS_BDB_TOUCHLINK_ZERODBMTXPWR_ID,                     86,   csBIB.touchlinkZeroDbmTxPwr)            //BDB
RAM_PARAMETER(CS_BDB_PRIMARY_CHANNELS_MASK_ID,                      87,   csBIB.primaryChannelMask)               //BDB
RAM_PARAMETER(CS_BDB_SECONDARY_CHANNELS_MASK_ID,                    88,   csBIB.secondaryChannelMask)             //BDB	
#endif
  RAM_PARAMETER(CS_INSTALL_CODE_BASED_JOIN_LINK_KEY_TYPE_ID,        89,   csSIB.installCodeBasedJoinLinkKeyType)  //BDB

/********************  PHY ************************/  
  RAM_PARAMETER(CS_DEVICE_POWER_ID,                                 90,   csSIB.csRfTxPowerType)                  //PHY
  RAM_PARAMETER(CS_TX_ANTENNA_GAIN_ID,                              91,   csSIB.csRfTxAntennaGain)                //PHY
  RAM_PARAMETER(CS_CERTIFICATION_FLAG_ID,                           92,   certificationFlag)                      //certificationFlag
  RAM_PARAMETER(CS_DEVICE_DEEP_SLEEP_WAKEUP_SRC_ID,                 93,   deviceDeepSleepWakeupSrc)               //device wakeup src 
/* Note : Add new Item(s) at the appropriate module and re order the IDs below that.
If the new Item to be added is not used by customer application then we may add at the end.
*/
