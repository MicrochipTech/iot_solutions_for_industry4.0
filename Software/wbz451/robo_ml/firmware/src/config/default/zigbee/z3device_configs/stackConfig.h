/*******************************************************************************
  Zigbee Stack Configuration File

  Company:
    Microchip Technology Inc.

  File Name:
    stackConfig.h

  Summary:
    This file contains Zigbee Stack Configuration.

  Description:
    This file contains Zigbee Stack Configuration.
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

#ifndef _STACK_CONFIG_H_
#define _STACK_CONFIG_H_

#if (BDB_SUPPORT == 1)

//-----------------------------------------------
// Includes Stack specific Configurations.
//-----------------------------------------------
//Max no.Of nodes to be stored in Trust Center node table
#define CS_BDB_NODE_JOIN_INFO_ENTRIES_AMOUNT 2

#define CS_DISTRIBUTED_NETWORK_ADDRESS 0xBEEF
#endif

//-----------------------------------------------
// Radio Arbiter selection
//ARB_ZB_RF233_MODE    0 
//ARB_ZB_STATIC_MODE   1
//ARB_ZB_DYNAMIC_MODE  2  */
//-----------------------------------------------
#define CS_RADIO_ARB_MODE  2

#if (CS_RADIO_ARB_MODE > 2) 
#error - wrong Radio arbiter mode setting
#endif

//-----------------------------------------------
// LPA or MPA Mode Slection
//CS_DEVICE_POWER_MPA    0x0F 
//CS_DEVICE_POWER_LPA    0x0B
//-----------------------------------------------
#define CS_DEVICE_POWER_MPA    (0x0F)
#define CS_DEVICE_POWER_LPA    (0x0B)

#define CS_DEVICE_POWER_TYPE   CS_DEVICE_POWER_MPA

//Tx Power set by user.Considering Radiative power
#define CS_RF_TX_POWER   3

//Tx Power set on Channel 26 for FCC by user.
#define CS_RF_MAX_CH26_TX_POWER  3

//User Specific Items from Product Specific , taken from there , this is just to make sure to have a default value.
#ifndef CS_TX_ANTENNA_GAIN
#define CS_TX_ANTENNA_GAIN    3
#endif

// Enables or disables APS Fragmentation support.
//#define APS_DATA_FRAGMENTATION 0
#define APS_DATA_FRAGMENTATION 1

// 16-bit manufacturer code allocated by the ZigBee Alliance. It is being used in
// payload of OTA commands as well as for filtering of manufacturer-specific ZCL
// commands and attributes. See ZigBee Manufacturer Code Database, 053874r16, Microchip
// code.
#define CS_MANUFACTURER_CODE 0x1014

// Determines whether a router can start a network in distributed security mode
// 
//  If set to 1 (ONE), a router will be allowed to form a network in distributed
// security mode.
//  Otherwise - if set to 0 (ZERO) - a router will be allowed only to join an
// existing network.
// 
//  Value range: 1 or 0
//  C-type: bool
//  Can be set: at any time before network start
//  Persistent: No
#define CS_NWK_DISTRIBUTED_SECURITY 0
//#define CS_NWK_DISTRIBUTED_SECURITY 1

// A period in ms of polling a parent for data by an end device. On a sleeping end
// device the parameter determines a period with which poll requests are sent to
// the parent while the end device is awaken. A parent of a sleeping end device
// uses the parameter to calculate estimates of the time when the next poll request
// from a child will be received.Recommended value range is 100 - 1000.
// 
//  Value range: any value valid for the C-type
//  C-type: uint32_t
//  Can be set: at any time
//  Persistent: No
#define CS_INDIRECT_POLL_RATE 500

// Maximum amount of a failed sync frame. Before attempting to rejoin.
// 
//  Value range: at minimum 1, the maximum value 255
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_ZDO_MAX_SYNC_FAIL_AMOUNT 0xff

// The maximum number of retries of send frame to the parent. Before attempting to
// rejoin.
// 
//  Value range: at minimum 1, the maximum value 255
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_ZDO_PARENT_LINK_RETRY_THRESHOLD 3

// While scanning channels during network join the node keeps listening to each
// channel specified by the ::CS_CHANNEL_MASK for a period of time calculated
// according to the formula that for the 2.4GHz frequency band is: 960 * 16 * (2
// raised to a power n + 1) microseconds, providing n is a value of this parameter.
// Note that the formula for the Sub-GHz employs another constant instead of 16.
#define CS_SCAN_DURATION 5

// Determines the maximum number of attempts to enter a network performed by the
// stack during network start. Upon each attempt ZDO sends a beacon request and
// collects beacon responses from nearby devices all over again.
#define CS_ZDO_JOIN_ATTEMPTS 1

// This is used to enable or disable nwk concentrator role
#define CS_NWK_CONCENTRATOR_CONFIGURATION false
//#define CS_NWK_CONCENTRATOR_CONFIGURATION true

// 64-bit Unique Identifier (UID) determining the device extended address. If this
// value is 0 stack will try to read hardware UID from external UID or EEPROM chip.
// at startup. Location of hardware UID is platform dependend and it may not be
// available on all platforms. If the latter case then UID value must be provided
// by user via this parameter. This parameter must be unique for each device in a
// network. This should not be 0 for Coordinator.
// 
//  Value range: any 64-bit value except for broadcast extended addresses
//  C-type: ExtAddr_t
//  Can be set: at any time before network start
//  Persistent: Yes
#ifndef CS_UID
#define CS_UID 0xb055LL
#endif

// Determines whether the static or automatic addressing mode will be used for the
// short address.
// 
//  If set to 1, the CS_NWK_ADDR parameter will be used as the device's short
// address. Otherwise, the short address is assigned automatically by the stack. An
// actual assignment method is specified in CS_ADDRESS_ASSIGNMENT_METHOD.
// 
//  Value range: 1 or 0
//  C-type: bool
//  Can be set: at any time before network start
//  Persistent: Yes
#define CS_NWK_UNIQUE_ADDR 0
//#define CS_NWK_UNIQUE_ADDR 1

//-----------------------------------------------
//CS_NWK_DISTRIBUTED_SECURITY == 1
//-----------------------------------------------
#if (CS_NWK_DISTRIBUTED_SECURITY == 1)
  // Specifies short (network) address if CS_NWK_UNIQUE_ADDR equals 1
  // 
  //  If static addressing is applied the stack uses the value of the parameter as a
  // short address. Otherwise, the stack assigns the parameter to a randomly chosen
  // value unique within the network. In both cases after the network start the
  // parameter holds actual short address of the device. While the device is in the
  // network its value must not be changed.
  // 
  //  Note: the coordinator short address always equals 0x0000.
  // 
  //  Value range: 0x0000 - 0xFFF8
  //  C-type: ShortAddr_t
  //  Can be set: at any time before network start
  //  Persistent: Yes
  #define CS_NWK_ADDR 0x0001
#endif

//-----------------------------------------------
//CS_NWK_UNIQUE_ADDR == 1
//-----------------------------------------------
#if (CS_NWK_UNIQUE_ADDR == 1)
  // Specifies short (network) address if CS_NWK_UNIQUE_ADDR equals 1
  // 
  //  If static addressing is applied the stack uses the value of the parameter as a
  // short address. Otherwise, the stack assigns the parameter to a randomly chosen
  // value unique within the network. In both cases after the network start the
  // parameter holds actual short address of the device. While the device is in the
  // network its value must not be changed.
  // 
  //  Note: the coordinator short address always equals 0x0000.
  // 
  //  Value range: 0x0000 - 0xFFF8
  //  C-type: ShortAddr_t
  //  Can be set: at any time before network start
  //  Persistent: Yes
  #undef CS_NWK_ADDR
  #define CS_NWK_ADDR 0x0001
#endif

// The maximum number of direct children that a given device (the coordinator or a
// router) can have.
// 
//  The parameter is only enabled for routers and the coordinator. An end device
// can not have children. If an actual number of children reaches a parameter's
// value, the node will have not been able to accept any more children joining the
// network. The parameter can be set to 0 on a router thus preventing it from
// accepting any children and can help form a desired network topology. For
// example, if the parameter is set to 0 on all routers, then the coordinator will
// be the only device that can have children and the network will have star
// topology.
// 
//  Value range: from 0 to CS_NEIB_TABLE_SIZE
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_MAX_CHILDREN_AMOUNT 6

// The maximum number of routers among the direct children of the device
// 
//  The parameter determines how many routers the device can have as children. Note
// that the maximum number of end devices is equal to CS_MAX_CHILDREN_AMOUNT -
// CS_MAX_CHILDREN_ROUTER_AMOUNT.
// 
//  Value range: from 0 to CS_MAX_CHILDREN_AMOUNT
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_MAX_CHILDREN_ROUTER_AMOUNT 2

// End device sleep period given in milliseconds.
// 
//  On an end device this parameter determines the duration of a sleep period.
// Falling asleep is performed with the ZDO_SleepReq() request. After sleeping
// period exceeds the node is awakened and the application receives an indication
// via ZDO_WakeUpInd(). If the parameter's value is 0, then after the node falls
// asleep it can only be awakened by a hardware interrupt; a callback for a given
// IRQ is registered via HAL_RegisterIrq().
// 
//  On a router or the coordinator, the parameter is used in two ways:
// 
//  1) To remove information about lost child end devices. If a parent receives no
// data polls or data frames from the child end device for
// CS_NWK_END_DEVICE_MAX_FAILURES * (CS_END_DEVICE_SLEEP_PERIOD +
// CS_INDIRECT_POLL_RATE) ms, then it assumes it to be lost and deletes all
// information about such child.
// 
//  2) To determine whether to store or drop a message addressed to a child end
// device. The parent estimates the time when its child end device will wake up by
// adding this value to the moment when the last poll request has been received. If
// the time till end device wake up is greater than CS_MAC_TRANSACTION_TIME(Default
// 7680msec) the frame is stored. Otherwise, the frame is dropped.
// 
//  Value range: any value valid for the C-type; add 'L' after a value
//  C-type: uint32_t
//  Can be set: at any time
//  Persistent: No
#define CS_END_DEVICE_SLEEP_PERIOD 7000L

// \brief Default Timeout enumeration used by the device
//     ref Table 3.4.3 of R21
//	 This value need to be set according to the CS_END_DEVICE_SLEEP_PERIOD and
//	 make sure 3 polls shall go within CS_DEFAULT_END_DEVICE_TIMEOUT vaue  
//<b>Value range:</b> \c 0 to \c 14 \n
// 0 -    10 Sec \n
// 1 -     2 minutes \n
// 2 -     4 minutes \n
// 3 -     8 minutes \n
// 4 -    16 minutes \n
// 5 -    32 minutes \n
// 6 -    64 minutes \n
// 7 -   128 minutes \n
// 8 -   256 minutes \n
// 9 -   512 minutes \n
//10 -  1024 minutes \n
//11 -  2048 minutes \n
//12 -  4096 minutes \n
//13 -  8192 minutes \n
//14 - 16384 minutes \n
//<b>C-type:</b> uint8_t \n
//<b>Can be set:</b> at Compile time only \n
#define CS_DEFAULT_END_DEVICE_TIMEOUT  NWK_END_DEVICE_TIMEOUT_2M

// The maximum number of network keys that can be stored on the device
// 
//  A device in a secured network can keep several network keys up to the value of
// this parameter. Upon frame reception the device extracts key sequence number
// from the auxiliary header of the frame and decrypts the message with the network
// key corresponding to this sequence number. Besides, one key is considered active
// for each device; this is the key that is used for encrypting outgoing frames.
// The keys are distributed by the trust center with the help of the
// APS_TransportKeyReq() command. The trust center can also change the active key
// of a remote node via a call to APS_SwitchKeyReq().
// 
//  C-type: NwkKeyAmount_t (typedef for uint8_t)
//  Can be set: at compile time only
//  Persistent: No
#define CS_NWK_SECURITY_KEYS_AMOUNT 2

// Address of device responsible for authentication and key distribution (Trust
// Center).
// 
//  The parameter specifies the trust center extended address. The stack makes use
// of the parameter to support various operations in networks with security
// enabled. For correct network operation a parameter's value must coincide with
// the actual trust center address.
// 
//  In case the trust center extended address is unknown, for example, for testing
// purposes, the parameter can be assigned to the universal trust center address
// which equals APS_SM_UNIVERSAL_TRUST_CENTER_EXT_ADDRESS.
// 
//  Value range: All 64-bit values except for 0xFFFFFFFFFFFFFFFFLL, specify a value
// in the 0x123456789ABCDEFLL format.
//  C-type: ExtAddr_t
//  Can be set: at any time before network start
//  Persistent: Yes
#define CS_APS_TRUST_CENTER_ADDRESS 0x0000000000000000LL

#define STDLINK_SECURITY_MODE

//-----------------------------------------------
//STDLINK_SECURITY_MODE
//-----------------------------------------------
#ifdef STDLINK_SECURITY_MODE
  // The parameter enabled in the high security mode specifies the size of the APS
  // key-pair set. The APS key-pair set stores pairs of corresponding extended
  // address and a link key or a master key. For each node with which the current
  // node is going to communicate it must keep an entry with the remote node extended
  // address and a link key. If the link key is unknown, the node can request the
  // trust center for it via APS_RequestKeyReq(). The trust center must store a link
  // key or a master key depending on the CS_SECURITY_STATUS used for each node it is
  // going to authenticate. Entries can also be added manually by APS_SetLinkKey()
  // and APS_SetMasterKey().
  // 
  //  Value range: 1 - 255
  //  C-type: uint8_t
  //  Can be set: at compile time only
  //  Persistent: No
  #define CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT 5
  
  // Depending on security key type and security mode this is either network key,
  // master key, link key or initial link key.
  // 
  //  Network key is used to encrypt a part of a data frame occupied by the NWK
  // payload. This type of encryption is applied in both the standard and high
  // security mode. The high security mode also enables encryption of the APS payload
  // with a link key, but if the txOptions.useNwkKey field in APS request parameters
  // is set to 0, the APS payload is encrypted with the network key.
  // 
  //  The network key must be predefined if standard security is used with
  // CS_ZDO_SECURITY_STATUS set to 0. For all other values of CS_ZDO_SECURITY_STATUS
  // the network key is received from the trust center during device authentication.
  // Note that in the standard security mode with CS_ZDO_SECURITY_STATUS equal to 3
  // the network key is transferred to the joining device in an unencrypted frame.
  // 
  //  Value range: all 128-bit values
  //  C-type: uint8_t[16] or any compatible
  //  Can be set: at any time before network start
  //  Persistent: No
  #define CS_NETWORK_KEY {0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC}
  
  // Security information waiting timeout before secure network join considered
  // failed.
  // 
  //  A timeout is started when connection with a parent is established. If the
  // security related procedures that are performed after this will not be completed
  // before the timeout exceeds, the device will fail joining the network. A value is
  // measured in milliseconds.
  // 
  //  C-type: uint32_t
  //  Can be set: at compile time only
  //  Persistent: No
  #define CS_APS_SECURITY_TIMEOUT_PERIOD 10000
#endif

#define CS_MAX_TC_ESTABLISH_KEY_AMOUNT 3

// Maximum amount of records in the Group Table.
// 
//  The Group Table size cannot be 0. The group table stores pairs of a group
// address and an endpoint. Upon receiving a frame addressed to members of a
// certain group which include the current node as well the stack fires indications
// on all endpoints registered with the group address.
// 
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_GROUP_TABLE_SIZE 8

// Maximum amount of records in the Neighbor Table.
// 
//  The parameter determines the size of the neighbor table which is used to store
// beacon responses from nearby devices. The parameter puts an upper bound over the
// amount of child devices possible for the node.
// 
//  Value range: at minimum 1, the maximum value is limited to the available memory
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_NEIB_TABLE_SIZE 5

// Maximum amount of records in the network Route Table.
// 
//  The parameter sets the maximum number of records that can be kept in the NWK
// route table. The table is used by NWK to store information about established
// routes. Each table entry specifies the next-hop short address for a route from
// the current node to a given destination node. The table is being filled
// automatically during route discovery. An entry is added when a route is
// discovered.
// 
//  Since the end device always sends a frame directly to its parent its route
// table size should be set to 0.
// 
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_ROUTE_TABLE_SIZE 5

// Maximum amount of records in the network Address Map Table.
// 
//  The parameter sets the maximum number of records in the address map table used
// by NWK to store pairs of corresponding short and extended addresses. The stack
// appeals to the table when a data frame is being sent to a specified extended
// address to extract the corresponding short address. If it fails to find the
// short address, an error is reported.
// 
//  C-type: NwkSizeOfAddressMap_t (typedef for uint8_t)
//  Can be set: at compile time only
//  Persistent: No
#define CS_ADDRESS_MAP_TABLE_SIZE 5

// Maximum amount of records in the network Route Discovery Table.
// 
//  The parameter specifies the size of the route discovery table used by NWK to
// store next-hop addresses of the nodes for routes that are not yet established.
// Upon exhausting the capacity of the table, the stack starts rewriting old
// entries. If the size of the route table is big enough after all used routes are
// established the table may not be used.
// 
//  Since the end device always sends a frame directly to its parent its route
// discovery table size should be set to 0.
// 
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_ROUTE_DISCOVERY_TABLE_SIZE 2

// Maximum amount of records in the Duplicate Rejection Table.
// 
//  The duplicate rejection table is used by APS to store information about
// incoming unicast messages in order to reject messages that have been already
// received and processed. Following ZigBee specification, the parameter should be
// not less than 1.
// 
//  Value range: greater than 1
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_DUPLICATE_REJECTION_TABLE_SIZE 7

// Maximim amount of records in the Binding Table
// 
//  The parameter sets the size of the binding table used by APS to store binding
// links, which are structures containing information about source and destination
// extended addresses and endpoints for unicast bindings and just group addresses
// as destinations for group bindings. If the binding is going to be applied to
// send a data frame, then the corresponding entry shall be first inserted into the
// table via the APS_BindingReq() function.
// 
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_APS_BINDING_TABLE_SIZE 25

// The number of buffers for data requests on the APS layer.
// 
//  The parameter specifies the number of buffers that are allocated by APS to
// store data requests parameters. The parameter puts an upper bound to the number
// of data requests that can be processed by APS simultaneously. If all buffers are
// in use and a new data request appears, it is kept in a queue until a buffer is
// released.
// 
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_APS_DATA_REQ_BUFFERS_AMOUNT 4

// The number of buffers for acknowledgement messages sent by APS.
// 
//  This parameter determines the amount of memory that needs to be allocated for a
// special type of buffers used by APS to store payloads for acknowledgement
// frames. The need to use the buffers occurs when the node receives a frame that
// has to be acknowledged. That is, the APS component on the node has to send an
// acknowledgement frame. For frames initiated by the application, the memory for a
// payload is to be allocated by the application on its own, while the payload
// memory for an acknowledgement frame shall be reserved by APS. The request
// parameters are still stored in the data request buffers.
// 
//  Typically, a value of this parameter equals CS_APS_DATA_REQ_BUFFERS_AMOUNT - 1.
// 
//  C-type: uint8_t
//  Can be set: at compile time only
//  Persistent: No
#define CS_APS_ACK_FRAME_BUFFERS_AMOUNT 3

// Amount of buffers on NWK layer used to keep incoming and outgoing frames. This
// parameters affects how many children of a parent are able to get broadcat
// messages.
#define CS_NWK_BUFFERS_AMOUNT 8

//-----------------------------------------------
//APS_DATA_FRAGMENTATION == 1
//-----------------------------------------------
#if (APS_DATA_FRAGMENTATION == 1)
  // This parameter limits the number of pieces to which the data sent with one APS
  // request can be split i f the fragmentation feature is applied. Thus it also
  // limits the maximum amount of data sent by the application with a single request:
  //  maximum data length = CS_APS_MAX_BLOCKS_AMOUNT * CS_APS_BLOCK_SIZE if the
  // latter parameter is not 0, else
  //  maximum data length = CS_APS_MAX_BLOCKS_AMOUNT * APS_MAX_ASDU_SIZE.
  //  C-type: uint8_t
  //  Can be set: at compile time only
  //  Persistent: No
  #define CS_APS_MAX_BLOCKS_AMOUNT 4
  
  // Maximim size of a single fragment during fragmented transmission.
  // 
  //  If the value is 0, blocks will be of the maximum possilbe size; that is the
  // size will equal the value of CS_APS_MAX_ASDU_SIZE. The parameter and
  // CS_APS_MAX_BLOCKS_AMOUNT are also used to determine an amount of memory
  // allocated for a special buffer that keeps parts of incoming fragmented message
  // until all of them are received.
  // 
  //  C-type: uint16_t
  //  Can be set: at compile time only
  //  Persistent: No
  #define CS_APS_BLOCK_SIZE 0
#endif


#endif // _STACK_CONFIG_H_
