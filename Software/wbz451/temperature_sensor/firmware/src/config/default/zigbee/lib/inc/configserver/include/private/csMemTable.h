/*******************************************************************************
  CS MemTable Header File

  Company
    Microchip Technology Inc.

  File Name
    csMemTable.h

  Summary
    This file contains the Configuration Server memory regions information table.

  Description
    This header file provides the interface to access the CS memory regions information table.
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
 * MEMORY_REGION(idm addr) and DUMMY_MEMORY_REGION(id) macroses should be defined
 * first to provide specific table morphing.
 *
 * DUMMY_MEMORY_REGION(id) macro is used to specify few stack buffers sizes during
 * the application compilation phase.
 */

MEMORY_REGION(CS_MAC_FRAME_RX_BUFFER_ID, 0x00, stackBuffers.csMacFrameRxBuffer)
#ifndef _MAC2_
MEMORY_REGION(CS_NEIB_TABLE_ID, 0x01, stackBuffers.csNeibTable)
MEMORY_REGION(CS_MAC_PAN_DESCRIPTOR_BUFFER_ID, 0x02, stackBuffers.csMacPanDescriptorBuffer)
MEMORY_REGION(CS_MUTABLE_NEIB_TABLE_ID, 0x03, stackBuffers.csMutableNeibTable)

#ifdef _MAC_BAN_NODE_
MEMORY_REGION(CS_BAN_TABLE_ID, 0x04, stackBuffers.csBanTable)
#endif

#if CS_ROUTE_CACHE_SIZE > 0
MEMORY_REGION(CS_ROUTE_CACHE_ID, 0x05, stackBuffers.csRouteCache)
#else
DUMMY_MEMORY_REGION(CS_ROUTE_CACHE_ID, 0x05)
#endif /* CS_ROUTE_CACHE_SIZE > 0 */

#if CS_NWK_BUFFERS_AMOUNT > 0
MEMORY_REGION(CS_NWK_BUFFERS_ID, 0x06, stackBuffers.csNwkBuffer)
#else
DUMMY_MEMORY_REGION(CS_NWK_BUFFERS_ID, 0x06)
#endif /* CS_NWK_BUFFERS_AMOUNT > 0 */

#if CS_JOIN_IND_OBJ_AMOUNT > 0
MEMORY_REGION(CS_JOIN_IND_OBJ_ID, 0x07, stackBuffers.csJoinIndObjects)
#else
DUMMY_MEMORY_REGION(CS_JOIN_IND_OBJ_ID, 0x07)
#endif /* CS_JOIN_IND_OBJ_AMOUNT > 0 */

#if CS_DUPLICATE_REJECTION_TABLE_SIZE > 0
MEMORY_REGION(CS_DUPLICATE_REJECTION_TABLE_ID, 0x08, stackBuffers.csDuplicateRejectionTable)
#else
DUMMY_MEMORY_REGION(CS_DUPLICATE_REJECTION_TABLE_ID, 0x08)
#endif /* CS_DUPLICATE_REJECTION_TABLE_SIZE > 0 */

#if CS_ROUTE_TABLE_SIZE > 0
MEMORY_REGION(CS_ROUTE_TABLE_ID, 0x09, stackBuffers.csRoutingTable)
#else
DUMMY_MEMORY_REGION(CS_ROUTE_TABLE_ID, 0x09)
#endif /* CS_ROUTE_TABLE_SIZE > 0 */

#if CS_ADDRESS_MAP_TABLE_SIZE > 0
MEMORY_REGION(CS_ADDRESS_MAP_TABLE_ID, 0x0A, stackBuffers.csAddressMapTable)
#else
DUMMY_MEMORY_REGION(CS_ADDRESS_MAP_TABLE_ID, 0x0A)
#endif /* CS_ADDRESS_MAP_TABLE_SIZE > 0 */

#if CS_ROUTE_DISCOVERY_TABLE_SIZE > 0
MEMORY_REGION(CS_ROUTE_DISCOVERY_TABLE_ID, 0x0B, stackBuffers.csRouteDiscoveryTable)
#else
DUMMY_MEMORY_REGION(CS_ROUTE_DISCOVERY_TABLE_ID, 0x0B)
#endif /* CS_ROUTE_DISCOVERY_TABLE_SIZE > 0 */

#if CS_NWK_BTT_SIZE > 0
MEMORY_REGION(CS_BTT_ID, 0x0C, stackBuffers.csBTR)
#else
DUMMY_MEMORY_REGION(CS_BTT_ID, 0x0C)
#endif /* CS_NWK_BTT_SIZE > 0 */

#if CS_APS_DATA_REQ_BUFFERS_AMOUNT > 0
MEMORY_REGION(CS_APS_DATA_REQ_BUFFER_ID, 0x0D, stackBuffers.csApsDataReqBuffer)
#else
DUMMY_MEMORY_REGION(CS_APS_DATA_REQ_BUFFER_ID, 0x0D)
#endif /* CS_APS_DATA_REQ_BUFFERS_AMOUNT > 0 */

#if CS_APS_ACK_FRAME_BUFFERS_AMOUNT > 0
MEMORY_REGION(CS_APS_ACK_FRAME_BUFFER_ID, 0x0E, stackBuffers.csApsAckFrameBuffer)
#else
DUMMY_MEMORY_REGION(CS_APS_ACK_FRAME_BUFFER_ID, 0x0E)
#endif /* CS_APS_ACK_FRAME_BUFFERS_AMOUNT > 0 */

#if defined(_APS_FRAGMENTATION_) && (CS_APS_MAX_BLOCKS_AMOUNT > 0)
MEMORY_REGION(CS_APS_FRAGMENTATION_MEMORY_POOL_ID, 0x0F, stackBuffers.csFragmentationMemoryPool)
MEMORY_REGION(CS_APS_FRAGMENTATION_PACKET_BUFFER_ID, 0x10, stackBuffers.csFragmentationPacketBuffer)
#else
DUMMY_MEMORY_REGION(CS_APS_FRAGMENTATION_MEMORY_POOL_ID, 0x0F)
DUMMY_MEMORY_REGION(CS_APS_FRAGMENTATION_PACKET_BUFFER_ID, 0x10)
#endif /* _APS_FRAGMENTATION_ */

#ifdef _GROUP_TABLE_
MEMORY_REGION(CS_GROUP_TABLE_ID, 0x11, stackBuffers.csGroupTable)
#endif

#ifdef _BINDING_
MEMORY_REGION(CS_APS_BINDING_TABLE_ID, 0x12, stackBuffers.csApsBindingTable)
#endif

#ifdef _ZCL_SUPPORT_ 
MEMORY_REGION(CS_ZCL_BUFFERS_ID, 0x13, stackBuffers.zclBuffers)
MEMORY_REGION(CS_ZCL_BUFFER_DESCRIPTORS_ID, 0x14, stackBuffers.zclMmBufferDescriptors)
#if APP_USE_OTAU == 1
    MEMORY_REGION(CS_ZCL_OTAU_DISCOVERED_SERVER_RESULT_ID, 0x15, stackBuffers.csOtauDiscoveryResult)
    MEMORY_REGION(CS_ZCL_OTAU_CLIENT_SESSION_MEMORY_ID, 0x16, stackBuffers.csOtauSimultaneousClientSession)
#endif /* APP_USE_OTAU == 1 */
#endif

#ifdef _SECURITY_
MEMORY_REGION(CS_NWK_SECURITY_IB_ID, 0x19, csNIB.securityIB)
MEMORY_REGION(CS_NWK_SECURITY_KEYS_ID, 0x1A, stackBuffers.csNwkSecKeys)
  #ifdef _NWK_IN_FRAME_COUNTERS_
MEMORY_REGION(CS_NWK_INCOMING_FRAME_COUNTER_SET_ID, 0x1B, stackBuffers.csInFrameCounterSet)
  #endif /* _NWK_IN_FRAME_COUNTERS_ */
  #ifdef _TRUST_CENTRE_
    #if (CS_MAX_TC_AUTHENTIC_PROCESS_AMOUNT > 0)
MEMORY_REGION(CS_TC_AUTHENTIC_PROCESS_BUFFER_ID, 0x1C, stackBuffers.csTcAuthenticProcessBuffer)
    #else
DUMMY_MEMORY_REGION(CS_TC_AUTHENTIC_PROCESS_BUFFER_ID, 0x1C)
    #endif /* (CS_MAX_TC_AUTHENTIC_PROCESS_AMOUNT > 0) */
    #if defined(_PERMISSIONS_) && (CS_PERMISSIONS_TABLE_SIZE > 0)
MEMORY_REGION(CS_PERMISSIONS_TABLE_ID, 0x1D, stackBuffers.csPermissionsTable)
    #else
DUMMY_MEMORY_REGION(CS_PERMISSIONS_TABLE_ID, 0x1D)
    #endif /* defined(CS_PERMISSIONS_TABLE_ID) & (CS_PERMISSIONS_TABLE_SIZE > 0) */
  #endif /* _TRUST_CENTRE_ */
#endif /* _SECURITY_ */

#ifdef _LINK_SECURITY_
MEMORY_REGION(CS_APS_KEY_PAIR_DESCRIPTORS_ID, 0x1E, stackBuffers.csApsKeyPairDescriptors)
MEMORY_REGION(CS_APS_KEY_PAIR_COUNTERS_ID, 0x1F, stackBuffers.csApsKeyCounters)
  #if defined(_TRUST_CENTRE_) && (CS_MAX_TC_ESTABLISH_KEY_AMOUNT > 0)
MEMORY_REGION(CS_TC_ESTABLISH_KEY_BUFFER_ID, 0x20, stackBuffers.csTcEstablishKeyBuffer)
  #else
DUMMY_MEMORY_REGION(CS_TC_ESTABLISH_KEY_BUFFER_ID, 0x20)
  #endif /* defined _LINK_SECURITY_ & defined(_TRUST_CENTRE_) & (CS_MAX_TC_ESTABLISH_KEY_AMOUNT > 0)*/

#endif /* _LINK_SECURITY_ */

#if (defined _NWK_PASSIVE_ACK_) && (CS_NWK_PASSIVE_ACK_AMOUNT > 0)
MEMORY_REGION(CS_NWK_PASSIVE_ACK_TABLE_ID, 0x21, stackBuffers.csNwkPassiveAckTable)
#endif /* _NWK_PASSIVE_ACK_ */

#if CS_ZDO_COMMANDS_AMOUNT > 0
MEMORY_REGION(CS_ZDO_COMMANDS_POOL_ID, 0x22, stackBuffers.csZdoCommandsPool)
#else
DUMMY_MEMORY_REGION(CS_ZDO_COMMANDS_POOL_ID, 0x22)
#endif /* CS_ZDO_COMMANDS_AMOUNT > 0 */
#ifdef _CHILD_MANAGEMENT_
  #if CS_ENDDEVICE_TIMEOUT_IND_OBJ_AMOUNT > 0
MEMORY_REGION(CS_ENDDEVICE_TIMEOUT_IND_OBJ_ID, 0x23, stackBuffers.csEndDeviceTimeoutObjs)
  #else
DUMMY_MEMORY_REGION(CS_ENDDEVICE_TIMEOUT_IND_OBJ_ID, 0x23)
  #endif /* CS_ENDDEVICE_TIMEOUT_IND_OBJ_AMOUNT > 0 */
#endif /* _CHILD_MANAGEMENT_ */
#endif /* _MAC2_ */
#ifdef _FFD_
MEMORY_REGION(CS_MAC_FRAME_DATA_REQ_BUFFER_ID, 0x25, stackBuffers.csMacFrameDataReqBuffer)
#endif
