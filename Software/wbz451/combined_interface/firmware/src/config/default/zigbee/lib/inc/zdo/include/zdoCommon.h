// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object common Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoCommon.h

  Summary:
    This file contains the Definitions of common ZDO layer's constants and types.

  Description:
    This file contains the Definitions of common ZDO layer's constants and types.

 *******************************************************************************/


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


// DOM-IGNORE-BEGIN
#if !defined _ZDO_COMMON_H
#define _ZDO_COMMON_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macAssociate.h>
/******************************************************************************
                               Definitions section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
// \cond internal
#define ZDP_REQUEST_MASK  CCPU_TO_LE16(0x7FFF)
#define ZDP_RESPONSE_MASK CCPU_TO_LE16(0x8000)

#ifdef _SECURITY_
#define PRECONFIGURED_NETWORK_KEY NWK_PRECONFIGURED_NETWORK_KEY
#define PRECONFIGURED_TRUST_CENTER_LINK_KEY 1
#define PRECONFIGURED_TRUST_CENTER_MASTER_KEY 2
#define NOT_PRECONFIGURED NWK_NOT_PRECONFIGURED_NETWORK_KEY

#ifndef ZDO_SECURITY_STATUS
#define ZDO_SECURITY_STATUS NOT_PRECONFIGURED
#endif //ZDO_SECURITY_STATUS


#define ZDO_NONE_SECURITY_MODE     0
#define ZDO_STANDARD_SECURITY_MODE 1
#define ZDO_HIGH_SECURITY_MODE     2
#endif//_SECURITY_



#ifdef _CHILD_MANAGEMENT_
#ifdef _PARENT_ANNCE_
#define ZDP_CHILD_INFO_LIST_OFFSET 3U

#define ZDP_CHILD_INFO_LIST_SIZE 10

#endif
#endif

#define MAX_REQUESTED_CLUSTER_NUMBER 17

#define MAX_ACTIVE_EP_NUMBER 10u
#define ED_SCAN_RESULTS_AMOUNT 32U

#define ZDP_NEIGBOR_TABLE_LIST_OFFSET 3U
#define ZDP_NEIGBOR_TABLE_LIST_SIZE (APS_MAX_ASDU_SIZE / (ZDP_NEIGBOR_TABLE_LIST_OFFSET + sizeof(NeighborTableList_t)))
#define ZDP_ADDR_LIST_SIZE  10
#define MGMT_BIND_RESP_COMMON_HDR_SIZE 5
#define MGMT_BIND_DST_EXT_ADDR_MODE_ENTRY_SIZE  21
#define MGMT_BIND_DST_GROUP_ADDR_MODE_ENTRY_SIZE 14

/** APS_MAX_NON_SECURITY_ASDU_SIZE is used to calculate the maximum possible 
    table entries that could be present in the received MgmtBindRsp. */
#define ZDP_BINDING_TABLE_LIST_SIZE  (APS_MAX_NON_SECURITY_ASDU_SIZE \
            - MGMT_BIND_RESP_COMMON_HDR_SIZE)/ MGMT_BIND_DST_GROUP_ADDR_MODE_ENTRY_SIZE
#define ZDP_ROUTING_TABLE_LIST_OFFSET 3U
#define ZDP_ROUTING_TABLE_LIST_SIZE (APS_MAX_ASDU_SIZE / (ZDP_ROUTING_TABLE_LIST_OFFSET + sizeof(RoutingTableList_t)))
// \endcond
// DOM-IGNORE-END

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** ZDO result status primitives. */
typedef enum
{
  //! The primitive has finished successfully
  ZDO_SUCCESS_STATUS                         = 0x00,
  //! Wrong parameters were put into the primitive
  ZDO_INVALID_PARAMETERS_STATUS              = 0x01,
  //! Response waiting timer has expired. Response is not received in time.
  ZDO_RESPONSE_WAIT_TIMEOUT_STATUS           = 0x02,
  //! ZDO layer is busy and cannot execute the primitive
  ZDO_BUSY_STATUS                            = 0x04,
  //! No network was found
  ZDO_NO_NETWORKS_STATUS                     = 0x05,
  //! There is a network with the same extended PANID
  ZDO_EXTPANID_ALREADY_EXIST_STATUS          = 0x06,
  //! Unknown error
  ZDO_FAIL_STATUS                            = 0x07,
  ZDO_AUTHENTICATION_SUCCESS_STATUS          = 0x08,
  //! Authentication failed during network start
  ZDO_AUTHENTICATION_FAIL_STATUS             = 0x09,
  ZDO_SECURITY_SUCCESS_STATUS                = 0x0A,
  ZDO_SECURITY_FAIL_STATUS                   = 0x0B,
  ZDO_SECURITY_NOT_SUPPORTED_STATUS          = 0x0C,
  /*! Indicates that command execution has finished. For a match descriptor
  request the confirmation with this status is issued if the timeout for
  ZDP response has exceeded and the stack has ceased waiting */
  ZDO_CMD_COMPLETED_STATUS                   = 0x0D,
  ZDO_KEY_ESTABLISHMENT_NOT_SUPPORTED_STATUS = 0x0E,

  //! Trust center could not find key pair descriptor to authenticate device
  ZDO_NO_KEY_PAIR_DESCRIPTOR_STATUS = 0x50,

  //! Link key for device was updated
  ZDO_UPDATE_LINK_KEY_STATUS        = 0x51,
  //! Master key for device was updated
  ZDO_UPDATE_MASTER_KEY_STATUS      = 0x52,
  //! Key pair descriptor was deleted
  ZDO_DELETE_KEY_PAIR_STATUS        = 0x53,
  //! Link key for device was deleted
  ZDO_DELETE_LINK_KEY_STATUS        = 0x54,

  //! TC is not responding to keep-alive requests
  ZDO_TC_NOT_AVAILABLE_STATUS       = 0x60,

  //! ZDP request is invalid
  ZDO_INVALID_REQUEST_STATUS        = 0x80,
  //! Requested device was not found
  ZDO_DEVICE_NOT_FOUND_STATUS       = 0x81,
  //! Unsupported endpoint of 0x00 or between 0xF1 and 0xFF was requested
  ZDO_INVALID_EP_STATUS             = 0x82,
  //! Requested endpoint has not been registered
  ZDO_NOT_ACTIVE_STATUS             = 0x83,
  //! Requested optional feature is not supported
  ZDO_NOT_SUPPORTED_STATUS          = 0x84,
  //! Timeout occured during the requested operation
  ZDO_TIMEOUT_STATUS                = 0x85,
  //! End device bind request is unsuccessful due to a failure to match any suitable clusters
  ZDO_NO_MATCH_STATUS               = 0x86,
  //! Unbind request is unsuccessful
  ZDO_NO_ENTRY_STATUS               = 0x88,
  //! Child descriptor is not available
  ZDO_NO_DESCRIPTOR_STATUS          = 0x89,
  //! Device does not have enough storage space
  ZDO_INSUFFICIENT_SPACE_STATUS     = 0x8A,
  //! The device does not have storage space to support the requested operation.
  ZDO_NOT_PERMITTED_STATUS          = 0x8B,
  //! Device does not have enough table space
  ZDO_TABLE_FULL_STATUS             = 0x8C,
  //! Request is not authorized from this device
  ZDO_NOT_AUTHORIZED_STATUS         = 0x8D,
  //! Network parameters have been updated (channel, PanId, shortAddr...)
  ZDO_NWK_UPDATE_STATUS             = 0x8E,
  //! Device has joined/rejoined a network and data can be transmitted
  ZDO_NETWORK_STARTED_STATUS        = 0x8F,
  //! Device has lost connection with a parent and the stack tries rejoin by itself. In this case transmission should be stopped.
  ZDO_NETWORK_LOST_STATUS           = 0x90,
  //! Device has left a network. If autonetwork option is on, the stack will rejoin a network. Otherwise, an application should rejoin.
  ZDO_NETWORK_LEFT_STATUS           = 0x91,
  //! New device has joined a network as a child of this device
  ZDO_CHILD_JOINED_STATUS           = 0x92,
  //! Child has been removed from children list
  ZDO_CHILD_REMOVED_STATUS          = 0x93,
  //! User descriptor is changed event
  ZDO_USER_DESCRIPTOR_UPDATE_STATUS = 0x94,
  //! On the device with static addressing the conflict of network addresses has been detected
  ZDO_STATIC_ADDRESS_CONFLICT_STATUS = 0x95
} ZDO_Status_t;

/** Types of response to address requests. */
enum
{
  SINGLE_RESPONSE_REQUESTTYPE   = 0x00, //!< Only the address of the target device is requested
  EXTENDED_RESPONSE_REQUESTTYPE = 0x01 //!< Addresses of all target's child nodes (only end devices) are also requested
};

/** The ZDP clusters ID list.
    <a name="zdp_clusters_list"></a>
    \anchor ZdpClustersList
    The ZDP cluster ID determines the type of a ZDP request/confirmation.
    The ID should be set to the ZDO_ZdpReq_t::reqCluster field of the
    ZDO_ZdpReq() function's argument.

    See also ZDO_ZdpFrame_t::reqPayload field of the ZDO_ZdpReq_t::req field.
    */
enum
{
// Device and Service Discovery commands
  NWK_ADDR_CLID                = CCPU_TO_LE16(0x0000),//!< Request for the 16-bit address of a remote device based on its known IEEE address.
  IEEE_ADDR_CLID               = CCPU_TO_LE16(0x0001),//!< Request for the 64-bit IEEE address of a remote device based on its known 16-bit address.
  NODE_DESCRIPTOR_CLID         = CCPU_TO_LE16(0x0002),//!< Request for the node descriptor of a remote device.
  POWER_DESCRIPTOR_CLID        = CCPU_TO_LE16(0x0003),//!< Request for the power descriptor of a remote device.
  SIMPLE_DESCRIPTOR_CLID       = CCPU_TO_LE16(0x0004),//!< Request for the simple descriptor of a remote device on the specified endpoint.
  ACTIVE_ENDPOINTS_CLID        = CCPU_TO_LE16(0x0005),//!< Request for the list of endpoints on a remote device with simple descriptors.
  MATCH_DESCRIPTOR_CLID        = CCPU_TO_LE16(0x0006),//!< Request for remote devices supporting a specific simple descriptor match criterion.
  COMPLEX_DESCRIPTOR_CLID      = CCPU_TO_LE16(0x0010),//!< Request for the complex descriptor of a remote device.
  USER_DESCRIPTOR_CLID         = CCPU_TO_LE16(0x0011),//!< Request for the user descriptor of a remote device.
  DISCOVERY_CASH_CLID          = CCPU_TO_LE16(0x0012),//!< Request to locate a Primary Discovery Cache device on the network.
  DEVICE_ANNCE_CLID            = CCPU_TO_LE16(0x0013),//!< Request to notify other ZigBee devices on the network that the device has joined or re-joined the network.
  USER_DESC_CONF_CLID          = CCPU_TO_LE16(0x0014),//!< Command to configure the user descriptor on a remote device.
  SYSTEM_SERVER_DISCOVERY_CLID = CCPU_TO_LE16(0x0015),//!< Request for the location of a particular system server or servers.
  DISCOVERY_STORE_CLID         = CCPU_TO_LE16(0x0016),//!< Request for the storage of the device's discovery cache information on a Primary Discovery Cache device.
  NODE_DESC_STORE_CLID         = CCPU_TO_LE16(0x0017),//!< Request for the storage of the device's Node Descriptor on a Primary Discovery Cache device.
  POWER_DESC_STORE_CLID        = CCPU_TO_LE16(0x0018),//!< Request for the storage of the device's Descriptor on a Primary Discovery Cache device.
  ACTIVE_EP_STORE_CLID         = CCPU_TO_LE16(0x0019),//!< Request for the storage of the device's list of Active Endpoints on a Primary Discovery Cache device.
  SIMPLE_DESC_STORE_CLID       = CCPU_TO_LE16(0x001A),//!< Request for the storage of the device's list of Simple Descriptors on a Primary Discovery Cache device.
  REMOVE_NODE_CACHE_CLID       = CCPU_TO_LE16(0x001B),//!< Command for removal of discovery cache information for a specified ZigBee end device from a Primary Discovery Cache device.
  FIND_NODE_CACHE_CLID         = CCPU_TO_LE16(0x001C),//!< Request for a device on the network that holds discovery information for the device of interest.
  EXTENDED_SIMPLE_DESC_CLID    = CCPU_TO_LE16(0x001D),//!< Request for the simple descriptor of a remote device on the specified endpoint, to be used with devices which support more active endpoints than can be returned by a single ::SIMPLE_DESCRIPTOR_CLID request.
  EXTENDED_ACTIVE_EP_CLID      = CCPU_TO_LE16(0x001E),//!< Request for the list of endpoints on a remote device with simple descriptors, to be used with devices which support more active endpoints than can be returned by a single ::ACTIVE_ENDPOINTS_CLID request.
  
#ifdef _CHILD_MANAGEMENT_
#ifdef _PARENT_ANNCE_
  PARENT_ANNCE_CLID      = CCPU_TO_LE16(0x001F),//!< Request for the list of endpoints on a remote device with simple descriptors, to be used with devices which support more active endpoints than can be returned by a single ::ACTIVE_ENDPOINTS_CLID request.
#endif
#endif
// Bind client manager commands
  END_DEVICE_BIND_CLID         = CCPU_TO_LE16(0x0020),//!< Request generated from a Local Device wishing to perform End Device Bind with a Remote Device.
  BIND_CLID                    = CCPU_TO_LE16(0x0021),//!< Request generated from a Local Device wishing to create a Binding Table entry for the source and destination addresses contained as parameters.
  UNBIND_CLID                  = CCPU_TO_LE16(0x0022),//!< Request generated from a Local Device wishing to remove a Binding Table entry for the source and destination addresses contained as parameters.
  BIND_REGISTER_CLID           = CCPU_TO_LE16(0x0023),//!< Request generated from a Local Device and sent to a primary binding table cache device to register that the local device wishes to hold its own binding table entries.
  REPLACE_DEVICE_CLID          = CCPU_TO_LE16(0x0024),//!< Request sent to a primary binding table cache device to change all binding table entries which match OldAddress and OldEndpoint as specified.
  STORE_BCKUP_BIND_ENTRY_CLID  = CCPU_TO_LE16(0x0025),//!< Request generated from a local primary binding table cache and sent to a remote backup binding table cache device to request backup storage of the entry.
  REMOVE_BCKUP_BIND_ENTRY_CLID = CCPU_TO_LE16(0x0026),//!< Request generated from a local primary binding table cache and sent to a remote backup binding table cache device to request removal of the entry from backup storage.
  BACKUP_BIND_TABLE_CLID       = CCPU_TO_LE16(0x0027),//!< Request generated from a local primary binding table cache and sent to the remote backup binding table cache device to request backup storage of its entire binding table.
  RECOVER_BIND_TABLE_CLID      = CCPU_TO_LE16(0x0028),//!< Request generated from a local primary binding table cache and sent to a remote backup binding table cache device when it wants a complete restore of the binding table.
  BACKUP_SOURCE_BIND_CLID      = CCPU_TO_LE16(0x0029),//!< Request generated from a local primary binding table cache and sent to a remote backup binding table cache device to request backup storage of its entire source table.
  RECOVER_SOURCE_BIND_CLID     = CCPU_TO_LE16(0x002A),//!< Request generated from a local primary binding table cache and sent to the remote backup binding table cache device when it wants a complete restore of the source binding table.
// Network Management Client Services commands
  MGMT_NWK_DISC_CLID           = CCPU_TO_LE16(0x0030),//!< Request generated from a Local Device requesting that the Remote Device execute a Scan to report back networks in the vicinity of the Local Device.
  MGMT_LQI_CLID                = CCPU_TO_LE16(0x0031),//!< Request generated from a Local Device wishing to obtain a neighbor list for the Remote Device along with associated LQI values to each neighbor.
  MGMT_RTG_CLID                = CCPU_TO_LE16(0x0032),//!< Request generated from a Local Device wishing to retrieve the contents of the Routing Table from the Remote Device.
  MGMT_BIND_CLID               = CCPU_TO_LE16(0x0033),//!< Request generated from a Local Device wishing to retrieve the contents of the Binding Table from the Remote Device.
  MGMT_LEAVE_CLID              = CCPU_TO_LE16(0x0034),//!< Request generated from a Local Device requesting that a Remote Device leave the network or to request that another device leave the network.
  MGMT_DIRECT_JOIN_CLID        = CCPU_TO_LE16(0x0035),//!< Request generated from a Local Device requesting that a Remote Device permit a device designated by DeviceAddress to join the network directly.
  MGMT_PERMIT_JOINING_CLID     = CCPU_TO_LE16(0x0036),//!< Request generated from a Local Device requesting that a remote device or devices allow or disallow association.
  MGMT_CACHE_CLID              = CCPU_TO_LE16(0x0037),//!< Request The Mgmt_Cache_req is provided to enable ZigBee devices on the network to retrieve a list of ZigBee End Devices registered with a Primary Discovery Cache device.
  MGMT_NWK_UPDATE_CLID         = CCPU_TO_LE16(0x0038), //!< Command provided to allow updating of network configuration parameters or to request information from devices on network conditions in the local operating environment.
  MGMT_NWK_UNSOLICITED_UPDATE_CLID = CCPU_TO_LE16(0x803b), //!< Command provided to allow updating of network configuration parameters or to request information from devices on network conditions in the local operating environment.

// Device and Service Discovery commands
  NWK_ADDR_RESP_CLID                = CCPU_TO_LE16(0x8000),//!< Response for the 16-bit address of a remote device based on its known IEEE address.
  IEEE_ADDR_RESP_CLID               = CCPU_TO_LE16(0x8001),//!< Response for the 64-bit IEEE address of a remote device based on its known 16-bit address.
  NODE_DESCRIPTOR_RESP_CLID         = CCPU_TO_LE16(0x8002),//!< Response for the node descriptor of a remote device.
  POWER_DESCRIPTOR_RESP_CLID        = CCPU_TO_LE16(0x8003),//!< Response for the power descriptor of a remote device.
  SIMPLE_DESCRIPTOR_RESP_CLID       = CCPU_TO_LE16(0x8004),//!< Response for the simple descriptor of a remote device on the specified endpoint.
  ACTIVE_ENDPOINTS_RESP_CLID        = CCPU_TO_LE16(0x8005),//!< Response for the list of endpoints on a remote device with simple descriptors.
  MATCH_DESCRIPTOR_RESP_CLID        = CCPU_TO_LE16(0x8006),//!< Response for remote devices supporting a specific simple descriptor match criterion.
  COMPLEX_DESCRIPTOR_RESP_CLID      = CCPU_TO_LE16(0x8010),//!< Response for the complex descriptor of a remote device.
  MGMT_LEAVE_RESP_CLID              = CCPU_TO_LE16(0x8034),//!< Response for a Remote Device leave the network or to request that another device leave the network.
  MGMT_PERMIT_JOINING_RESP_CLID     = CCPU_TO_LE16(0x8036),//!< Response for a remote device or devices allow or disallow association.
  BIND_RESP_CLID                    = CCPU_TO_LE16(0x8021),//!< Response for Binding Table entry for the source and destination addresses contained as parameters.
  UNBIND_RESP_CLID                  = CCPU_TO_LE16(0x8022),//!< Response for Binding Table entry for the source and destination addresses contained as parameters.
  MGMT_LQI_RESP_CLID                = CCPU_TO_LE16(0x8031),//!< Response generated to obtain a neighbor list for the Remote Device along with associated LQI values to each neighbor.
  MGMT_RTG_RESP_CLID                = CCPU_TO_LE16(0x8032),//!< Response generated to retrieve the contents of the Routing Table from the Remote Device.
  MGMT_BIND_RESP_CLID               = CCPU_TO_LE16(0x8033),//!< Response generated to retrieve the contents of the Binding Table from the Remote Device.
  MGMT_NWK_UPDATE_NOTIFY_CLID       = CCPU_TO_LE16(0x8038), //!< Response generated for updating of network configuration parameters or to request information from devices on network conditions in the local operating environment.
#ifdef _CHILD_MANAGEMENT_
#ifdef _PARENT_ANNCE_
  PARENT_ANNCE_RESP_CLID      = CCPU_TO_LE16(0x801F),//!< Response for the list of endpoints on a remote device with simple descriptors, to be used with devices which support more active endpoints than can be returned by a single ::ACTIVE_ENDPOINTS_CLID request.
#endif
#endif 
};

/** Possible address modes */
#define  ZDO_MGMT_ED_SCAN_DUR_0  0x00     //!< Used as a value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_ED_SCAN_DUR_1  0x01     //!< Used as a value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_ED_SCAN_DUR_2  0x02     //!< Used as a value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_ED_SCAN_DUR_3  0x03     //!< Used as a value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_ED_SCAN_DUR_4  0x04     //!< Used as a value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_ED_SCAN_DUR_5  0x05     //!< Used as a value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_CHANNEL_CHANGE  0xFE    //!< Used as a special value for ZDO_MgmtNwkUpdateReq_t::scanDuration
#define  ZDO_MGMT_NWK_PARAMS_CHANGE  0xFF //!< Used as a special value for ZDO_MgmtNwkUpdateReq_t::scanDuration



BEGIN_PACK
/** Information about the addresses of a device */
typedef struct PACK
{
  ShortAddr_t shortAddr; //!< Short address
  ExtAddr_t   extAddr; //!< Extended address
} NodeAddr_t;
END_PACK

BEGIN_PACK
typedef struct PACK
{
  ShortAddr_t         shortAddr; //!< Short address
  ExtAddr_t           extAddr; //!< Extended address
  MAC_CapabilityInf_t capabilityInfo; //!< Device capability information
} ChildInfo_t;
END_PACK

#endif // _ZDO_COMMON_H
