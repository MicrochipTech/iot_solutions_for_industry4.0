/*******************************************************************************
  Zigbee Makerules for the library

  Company:
    Microchip Technology Inc.

  File Name:
    Zigbee_AllDevice_Makerules.h

  Summary:
    This file contains Zigbee Makerules for the library.

  Description:
    This file contains Zigbee Makerules for the library.
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

#ifndef FREE_RTOS
#define FREE_RTOS
#endif
#ifndef RELEASE
#define RELEASE
#endif
#ifndef _IEEE_ZIGBEE_COMPLIANCE_
#define _IEEE_ZIGBEE_COMPLIANCE_
#endif
#ifndef _SYS_MAC_PHY_HWD_TASK_
#define _SYS_MAC_PHY_HWD_TASK_
#endif
#ifndef _SYS_HAL_TASK_
#define _SYS_HAL_TASK_
#endif
#ifndef _SYS_MAC_HWI_TASK_
#define _SYS_MAC_HWI_TASK_
#endif
#ifndef _SYS_BSP_TASK_
#define _SYS_BSP_TASK_
#endif
#ifndef _SYS_NWK_TASK_
#define _SYS_NWK_TASK_
#endif
#ifndef _SYS_APS_TASK_
#define _SYS_APS_TASK_
#endif
#ifndef _SYS_ZCL_TASK_
#define _SYS_ZCL_TASK_
#endif
#ifndef _USE_RTOS_
#define _USE_RTOS_
#endif
#ifndef _SYS_ZLL_TASK_
#define _SYS_ZLL_TASK_
#endif
#ifndef _SYS_SSP_TASK_
#define _SYS_SSP_TASK_
#endif
#ifndef _SYS_TC_TASK_
#define _SYS_TC_TASK_
#endif
#ifndef _SYS_ZDO_TASK_
#define _SYS_ZDO_TASK_
#endif
#ifndef _SECURITY_
#define _SECURITY_
#endif
#ifndef _NWK_ALLOCATOR_
#define _NWK_ALLOCATOR_
#endif
#ifndef _HAL_HW_AES_
#define _HAL_HW_AES_
#endif
#ifndef _TRUST_CENTRE_
#define _TRUST_CENTRE_
#endif
#ifndef _DISTRIBUTED_TRUST_CENTER_
#define _DISTRIBUTED_TRUST_CENTER_
#endif
#ifndef _LINK_SECURITY_
#define _LINK_SECURITY_
#endif
#ifndef _HAL_HW_AES_
#define _HAL_HW_AES_
#endif
#ifndef _COORDINATOR_
#define _COORDINATOR_
#endif
#ifndef _ROUTER_
#define _ROUTER_
#endif
#ifndef _ENDDEVICE_
#define _ENDDEVICE_
#endif
#ifndef _FFD_
#define _FFD_
#endif
#ifndef _GREENPOWER_SUPPORT_
#define _GREENPOWER_SUPPORT_
#endif
#ifndef ZGP_SECURITY_ENABLE
#define ZGP_SECURITY_ENABLE
#endif
#ifndef BDB_SUPPORT
#define BDB_SUPPORT 1
#endif
#ifndef MICROCHIP_APPLICATION_SUPPORT
#define MICROCHIP_APPLICATION_SUPPORT 1
#endif
#ifndef BDB_FINDINGANDBINDING_SUPPORT
#define BDB_FINDINGANDBINDING_SUPPORT 1
#endif
#ifndef __MICROCHIP_BITCLOUD__
#define __MICROCHIP_BITCLOUD__
#endif
#ifndef ZIGBEE_END_DEVICE
#define ZIGBEE_END_DEVICE
#endif
#ifndef ZIGBEE_COORDINATOR
#define ZIGBEE_COORDINATOR
#endif
#ifndef ZIGBEE_ROUTER
#define ZIGBEE_ROUTER
#endif
#ifndef BDB_NWKFORMATION_SUPPORT
#define BDB_NWKFORMATION_SUPPORT 1
#endif
#ifndef BDB_TOUCHLINK_SUPPORT
#define BDB_TOUCHLINK_SUPPORT 1
#endif
#ifndef BDB_TOUCHLINK_INITIATOR_SUPPORT
#define BDB_TOUCHLINK_INITIATOR_SUPPORT 1
#endif
#ifndef _MAC_BAN_NODE_
#define _MAC_BAN_NODE_
#endif
#ifndef _RF_REG_ACCESS_
#define _RF_REG_ACCESS_
#endif
#ifndef _CONTROL_FRAME_PENDING_BIT_
#define _CONTROL_FRAME_PENDING_BIT_
#endif
#ifndef _PENDING_EMPTY_DATA_FRAME_
#define _PENDING_EMPTY_DATA_FRAME_
#endif
#ifndef _NWK_FAST_ROUTE_DISCOVERY_
#define _NWK_FAST_ROUTE_DISCOVERY_
#endif
#ifndef _NWK_MANY_TO_ONE_ROUTING_
#define _NWK_MANY_TO_ONE_ROUTING_
#endif
#ifndef _NWK_ROUTE_RECORD_
#define _NWK_ROUTE_RECORD_
#endif
#ifndef _NWK_SOURCE_ROUTING_
#define _NWK_SOURCE_ROUTING_
#endif
#ifndef _NWK_CONCENTRATOR_
#define _NWK_CONCENTRATOR_
#endif
#ifndef _NWK_ROUTE_CACHE_
#define _NWK_ROUTE_CACHE_
#endif
#ifndef _NWK_NONSTANDARD_BEACON_FILTER_
#define _NWK_NONSTANDARD_BEACON_FILTER_
#endif
#ifndef _NWK_CHECK_OUT_BROADCAST_
#define _NWK_CHECK_OUT_BROADCAST_
#endif
#ifndef _NWK_ROUTING_OPTIMIZATION_
#define _NWK_ROUTING_OPTIMIZATION_ 2
#endif
#ifndef _NWK_STOCHASTIC_ADDRESSING_
#define _NWK_STOCHASTIC_ADDRESSING_
#endif
#ifndef _RESOLVE_ADDR_CONFLICT_
#define _RESOLVE_ADDR_CONFLICT_
#endif
#ifndef _NWK_UID_ADDRESSING_
#define _NWK_UID_ADDRESSING_
#endif
#ifndef _NWK_MESH_ROUTING_
#define _NWK_MESH_ROUTING_
#endif
#ifndef _APS_FRAGMENTATION_
#define _APS_FRAGMENTATION_
#endif
#ifndef _ZCL_SUPPORT_
#define _ZCL_SUPPORT_
#endif
#ifndef _ZCL_REPORTING_SUPPORT_
#define _ZCL_REPORTING_SUPPORT_
#endif
#ifndef _ZCL_ATTRIBUTE_EXTENSION_
#define _ZCL_ATTRIBUTE_EXTENSION_
#endif
#ifndef _APS_MULTICAST_
#define _APS_MULTICAST_
#endif
#ifndef _GROUP_TABLE_
#define _GROUP_TABLE_
#endif
#ifndef _BINDING_
#define _BINDING_
#endif
#ifndef _DISTRIBUTED_SECURITY_
#define _DISTRIBUTED_SECURITY_
#endif
#ifndef _COMMISSIONING_
#define _COMMISSIONING_
#endif
#ifndef _ENABLE_PERSISTENT_SERVER_
#define _ENABLE_PERSISTENT_SERVER_
#endif
#ifndef _SYS_PDS_TASK_
#define _SYS_PDS_TASK_
#endif
#ifndef _RESOLVE_PANID_CONFLICT_
#define _RESOLVE_PANID_CONFLICT_
#endif
#ifndef _NETWORK_MANAGER_
#define _NETWORK_MANAGER_
#endif
#ifndef _FREQUENCY_AGILITY_
#define _FREQUENCY_AGILITY_
#endif
#ifndef _INTERPAN_
#define _INTERPAN_
#endif
#ifndef _NWK_DIRECT_JOIN_
#define _NWK_DIRECT_JOIN_
#endif
#ifndef _NWK_ORPHAN_JOIN_
#define _NWK_ORPHAN_JOIN_
#endif
#ifndef _CERTIFICATION_
#define _CERTIFICATION_
#endif
#ifndef _NWK_PASSIVE_ACK_
#define _NWK_PASSIVE_ACK_
#endif
#ifndef _CUSTOM_PASSIVE_ACK_THRESHOLD_
#define _CUSTOM_PASSIVE_ACK_THRESHOLD_
#endif
#ifndef _SILENT_LEAVE_WITHOUT_NETWORK_LEFT_
#define _SILENT_LEAVE_WITHOUT_NETWORK_LEFT_
#endif
#ifndef _NWK_NEIGHBOR_ENTRY_ADDITION_UPON_RX_FRAME_
#define _NWK_NEIGHBOR_ENTRY_ADDITION_UPON_RX_FRAME_
#endif
#ifndef _ZIGBEE_REV_21_SUPPORT_
#define _ZIGBEE_REV_21_SUPPORT_
#endif
#ifndef _CHILD_MANAGEMENT_
#define _CHILD_MANAGEMENT_
#endif
#ifndef _PARENT_ANNCE_
#define _PARENT_ANNCE_
#endif
#ifndef _TEMP_CHANGES_FOR_ZIG_TEST_
#define _TEMP_CHANGES_FOR_ZIG_TEST_
#endif
#ifndef _NWK_ROUTE_REQUEST_RETRIES_BASED_ON_MAC_CONF_
#define _NWK_ROUTE_REQUEST_RETRIES_BASED_ON_MAC_CONF_
#endif
#ifndef _LEAVE_NETWORK_IMMEDIATE_WITH_NO_TANSACTIONS_LEFT_
#define _LEAVE_NETWORK_IMMEDIATE_WITH_NO_TANSACTIONS_LEFT_
#endif
#ifndef _SLEEP_WHEN_IDLE_
#define _SLEEP_WHEN_IDLE_
#endif
#ifndef _NWK_IN_FRAME_COUNTERS_
#define _NWK_IN_FRAME_COUNTERS_
#endif
#ifndef _TC_ALLOW_REJOIN_WITH_GLOBAL_LINK_KEY_
#define _TC_ALLOW_REJOIN_WITH_GLOBAL_LINK_KEY_
#endif
#ifndef ARM_CM4F_GCC
#define ARM_CM4F_GCC
#endif
#ifndef _SLEEP_WHEN_IDLE_
#define _SLEEP_WHEN_IDLE_
#endif
#if defined (Z3DEVICE_APP) || defined (ZGPSENSOR_APP) || defined (ZGPSWITCH_APP)
#include <zigbee/z3device_configs/zigbeeAppConfig.h>
#elif defined (ZIGBEE_ZAPPSI)
#include <zigbee/ZAppSiRunner_configs/zigbeeAppConfig.h>
#endif
