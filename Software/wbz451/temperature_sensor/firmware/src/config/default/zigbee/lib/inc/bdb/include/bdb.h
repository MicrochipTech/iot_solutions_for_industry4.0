/*******************************************************************************
  BDB Header File

  Company
    Microchip Technology Inc.

  File Name
    bdb.h

  Summary
    bdb interface.

  Description
    This header file provides the interface to the BDB API's involved in the network formation and steering
    in a Zigbee Network.
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

#ifndef _BDB_H
#define _BDB_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/
#include "zllplatform/infrastructure/N_Task/include/N_Task.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"
#include <systemenvironment/include/sysQueue.h>
#include <mac_phy/include/macAddr.h>
#include <zdo/include/appFramework.h>
#include <aps/include/aps.h>
#ifndef ZAPPSI_NP
#include <zdo/include/appFramework.h>
#include <zcl/include/zcl.h>
#endif

/******************************************************************************
                    Defines section
******************************************************************************/
#ifndef BDB_INITIATOR_MAX_MATCHED_CLIENT_CLUSTER_COUNT
#define BDB_INITIATOR_MAX_MATCHED_CLIENT_CLUSTER_COUNT    15
#endif

#ifndef BDB_INITIATOR_MAX_MATCHED_SERVER_CLUSTER_COUNT
#define BDB_INITIATOR_MAX_MATCHED_SERVER_CLUSTER_COUNT    15
#endif

#ifndef BDB_NODE_JOIN_INFO_ENTRIES_AMOUNT
#define BDB_NODE_JOIN_INFO_ENTRIES_AMOUNT     (2) /* SHALL NOT exceed CS_APS_KEY_PAIR_DESCRIPTORS_AMOUNT */
#endif

extern QueueDescriptor_t bdbEventsubscribersQueue;

#define RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS(queue, callback) \
  for (BdbEventSubscriber_t* subscriber = getQueueElem(&queue); subscriber; subscriber = getNextQueueElem(subscriber)) \
    if (subscriber->callback) \
      subscriber->callback();

#define RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_SINGLE_ARGUMENT(queue, callback) \
  for (BdbEventSubscriber_t* subscriber = getQueueElem(&queue); subscriber; subscriber = getNextQueueElem(subscriber)) \
    if (subscriber->callback) \
      subscriber->callback(argument);

#define RAISE_CALLBACKS_TO_BDBEVENTS_SUBSCRIBERS_WITH_TWO_ARGUMENTS(queue, callback) \
  for (BdbEventSubscriber_t* subscriber = getQueueElem(&queue); subscriber; subscriber = getNextQueueElem(subscriber)) \
    if (subscriber->callback) \
      subscriber->callback(groupIdFirst, groupIdLast);


/******************************************************************************
                    Types section
******************************************************************************/
typedef struct _BIB_t
{
  /** Touchlink RSSI Correction. */
  uint8_t touchlinkRssiCorrection;
  /** Touchlink RSSI Thershold. */
  int8_t touchlinkRssiThershold;
  /** Touchlink Zero DBM TX power. */
  uint8_t touchlinkZeroDbmTxPwr;
  /* Primary channel Set configuration */
  uint32_t primaryChannelMask;
  /* Secondary channel Set configuration */
  uint32_t secondaryChannelMask;
} BIB_t;

/**************************************************************************//**
\brief Describes the the status of its commissioning attempt.Currently
       it specifies only spec specified values.May be modified based on
       implementation requirement
 *****************************************************************************/
typedef enum
{
  //!< commissioning sub procedure is successful
  BDB_COMMISSIONING_SUCCESS,
  //!< One of the commissioning sub-procedures has started but is not yet complete
  BDB_COMMISSIONING_IN_PROGRESS,
  //!< The initiator is not address assignment capable during touchlink
  BDB_COMMISSIONING_NOT_AA_CAPABLE,
  //!< A network has not been found during network steering or touchlink
  BDB_COMMISSIONING_NO_NETWORK,
  //!< A node has not joined a network when requested during touchlink
  BDB_COMMISSIONING_TARGET_FAILURE,
  //!< A network could not be formed during network formation
  BDB_COMMISSIONING_FORMATION_FAILURE,
  //!< No response to an identify query command has been received during finding & binding
  BDB_COMMISSIONING_NO_IDENTIFY_QUERY_RESPONSE,
  //!< A binding table entry could not be created due to insufficient space in the binding table during finding & binding.
  BDB_COMMISSIONING_BINDING_TABLE_FULL,
  //!< No response to a scan request inter-PAN command has been received during touchlink
  BDB_COMMISSIONING_NO_SCAN_RESPONSE,
  //!< A touchlink (steal) attempt was made when a node is already connected to a centralized security network.
  BDB_COMMISSIONING_NOT_PERMITTED,
  //!< The Trust Center link key exchange procedure has failed attempting to join a centralized security network
  BDB_COMMISSIONING_TCLK_EX_FAILURE,
  //!< A commissioning procedure was forbidden since the node was not currently on a network
  BDB_COMMISSIONING_NOT_ON_A_NETWORK,
  //!< A commissioning procedure was forbidden since the node was currently on a network
  BDB_COMMISSIONING_ON_A_NETWORK,  
  //!< Other Bitcloud defined statuses
  //!< The given commissioning is not supported
  BDB_COMMISSIONING_NOT_SUPPORTED
} BDB_CommissioningStatus_t;

/**************************************************************************//**
\brief  specifies the commissioning capabilities of the node
 *****************************************************************************/
typedef struct PACK _BDB_NodeCommissioningCapability_t
{
  LITTLE_ENDIAN_OCTET(5,(
    uint8_t nwkSteeringSupported              : 1,
    uint8_t nwkFormationSupported             : 1,
    uint8_t findingAndBindingSupported        : 1,
    uint8_t touchlinkComissioningSupported    : 1,
    uint8_t reserved                          : 4
  ))
} BDB_NodeCommissioningCapability_t;

/**************************************************************************//**
\brief  Defines the attributes/information base of the BDB
 *****************************************************************************/
typedef struct _BDBIB_t
{
  bool bdbJoinUsesInstallCodeKey;
  bool bdbTrustCenterRequireKeyExchange;
  bool bdbNodeIsOnANetwork;
  uint8_t bdbNodeJoinLinkKeyType;
  uint8_t bdbScanDuration;
  uint8_t bdbTCLinkKeyExchangeAttempts;
  uint8_t bdbTCLinkKeyExchangeAttemptsMax;
  uint8_t bdbTCLinkKeyExchangeMethod;
  uint8_t bdbTrustCenterNodeJoinTimeout;
  BDB_NodeCommissioningCapability_t bdbNodeCommissioningCapability;
  uint8_t bdbJoiningNodeNewTCLinkKey[16];
  uint32_t bdbPrimaryChannelSet;
  uint32_t bdbSecondaryChannelSet;
  ExtAddr_t bdbJoiningNodeEui64;
} BDBIB_t;

/**************************************************************************//**
\brief Describes the parameters of the BDB_InvokeCommissioningConf() function
******************************************************************************/
typedef struct
{
  BDB_CommissioningStatus_t  status;
} BDB_InvokeCommissioningConf_t;

typedef void (*BDB_InvokeCommissioningConfCallback_t)(BDB_InvokeCommissioningConf_t *conf);

typedef struct _BDB_CommissioningConfCallBack
{
  BDB_InvokeCommissioningConfCallback_t callbackFn;
  BDB_InvokeCommissioningConf_t *confirm;
  
} BDB_CommissioningConfCB_t;

/**************************************************************************//**
\brief Describes the callback define for Bind finish
******************************************************************************/
typedef void (*BDB_BindFinishedCallback_t)(Endpoint_t ResponentEp, ClusterId_t id);

/**************************************************************************//**
\brief Defines the input parameters required for initiator procedure
******************************************************************************/
typedef struct BDB_InitiatorReq_t
{
  Endpoint_t initiatorEndpoint;
  uint8_t clientClustersCount;
  uint8_t serverClustersCount;
  uint16_t groupId;
  ClusterId_t  *clientClustersList;
  ClusterId_t  *serverClustersList;
  BDB_BindFinishedCallback_t callback;
} BDB_InitiatorReq_t;

/**************************************************************************//**
\brief Defines the commissioning mode parameters required for initiator procedure
******************************************************************************/
typedef uint8_t BDB_CommissioningMode_t;

/**************************************************************************//**
\brief Describes the parameters of the BDB_InvokeCommissioningReq() function
******************************************************************************/
typedef struct
{
  /** Commissioning options to be executed */
  BDB_CommissioningMode_t mode;

  /** Parameters used in f&b and touchlink. Ignore if touchlink or finding and binding is
  not set in mode */
  BDB_InitiatorReq_t* initiatorReq;

  /** Parameters of the confirm being returned in BDB_InvokeCommissioningConf() */
  BDB_InvokeCommissioningConf_t confirm;

  /** The callback function to be called to confirm the request. Must not be set to NULL. */
  void (*BDB_InvokeCommissioningConf)(BDB_InvokeCommissioningConf_t *conf);
} BDB_InvokeCommissioningReq_t;

#if defined(_TRUST_CENTRE_) && defined(ZIGBEE_COORDINATOR)
/* Describes the status of the trust center join */
typedef enum _BDB_TcNodeJoinState_t
{
  BDB_TC_JOIN_STATE_IDLE                    = 0x00,
  BDB_TC_JOIN_STATE_WAITING_FOR_REQUEST_KEY = 0x01,
  BDB_TC_JOIN_STATE_WAITING_FOR_VERIFY_KEY  = 0x02
} BDB_TrustCenterNodeJoinState_t;

/** Structure of the internal table used by the Trust Center to validate
 * joining or rejoining of a new node */
typedef struct _BDB_TcNodeJoinInfo_t
{
  /** Address of the node that is trying to join */
  ExtAddr_t joiningNodeExtAddr;

  /** Parent of the joining node */
  ExtAddr_t parentExtAddr;

  /** Remaning duration until it elapses bdbTrustCenterNodeJoinTimeout. In milliseconds */
  uint32_t ttl;

  /** State of the join process */
  BDB_TrustCenterNodeJoinState_t state;

  /** Busy field; false = ENTRY_NOT_USED; true = ENTRY_USED */
  bool busy;

} BDB_TrustCenterNodeJoinInfo_t;
#endif /* #if defined(_TRUST_CENTRE_) && defined(ZIGBEE_COORDINATOR) */

/**************************************************************************//**
\brief Describes the Endpoint type of the node
******************************************************************************/
typedef enum _BDB_EpType_t
{
  TARGET_EP,
  INITIATOR_EP,
}BDB_EpType_t;

/**************************************************************************//**
\brief Describes the channel mask used for set
******************************************************************************/
typedef enum _BDB_ChannelMaskType_t
{
  PRIMARY_CHANNEL_MASK,
  SECONDARY_CHANNEL_MASK
}BDB_ChannelMaskType_t;

/**************************************************************************//**
\brief Describes the node join link key type. Refer table-7 BDB spec.
******************************************************************************/
typedef enum _BDB_NodeJoinLinkKeyType_t
{
  DEFAULT_GLOBAL_TRUST_CENTER_LINK_KEY,
  DISTRIBUTED_SECURITY_GLOBAL_LINK_KEY,
  INSTALL_CODE_DERIVED_PRECONFIGURED_LINK_KEY,
  TOUCHLINK_PRECONFIGURED_LINK_KEY
}BDB_NodeJoinLinkKeyType_t;

/**************************************************************************//**
\brief Describes the resetToFactory defaults using Touchlink commissioning cluster
       status values
******************************************************************************/
typedef enum ResetTargetStatus_t
{
  /** Reset Target device is success */
  RESET_TARGET_SUCCESS,
  /** Reset Target device is failed */
  RESET_TARGET_FAILURE
}ResetTargetStatus_t;

/**************************************************************************//**
\brief Describes the parameters of the BDB_EventsSubscribe () function
******************************************************************************/
typedef struct _BdbEventSubscriber_t
{
  struct
  {
    void *next;
  }service;
  /* Indicates the device has been (re)connected to the network */
  void (*connected)(void);
  /* Indicates the device has lost it connection to the network.*/
  void (*disconnected)(void);
  /* Network Formation Completed with Status */
  void (*networkFormationCompleted)(BDB_CommissioningStatus_t status);
  /* Indicates Network Steering is in progress either in network or not in network */
  void (*SteeringNetwork)(void);
  /* Indicates steering completion */
  void (*SteeringCompleted)(BDB_CommissioningStatus_t status);
  /* Indicates Touchlink scanning started */
  void (*scanning)(void);
  /* Indicates Touchlink identifying the target */
  void (*identifying)(void);
  /* Indicates joining during touchlink is in progress */
  void (*joining)(void);
  /* Indicates scan request reception */
  void (*scanIndication)(void);
  /* Requests the application to identify itself with the given timeout */
  void (*identifyStartIndication)(uint16_t timeoutInSec);
  /* Requests the application to stop identifying itself */
  void (*identifyStopIndication)(void);
  /* Requests the application to reset itself to factory defaults */
  void (*ResetToFactoryDefaults)(void);
  /* Indicates that the device has been linked to a new network by the initiator */
  void (*joinNetworkIndication)(uint16_t groupIdFirst, uint16_t groupIdLast);
  /* Touchlink Complete with status */
  void (*touchlinkCompleted)(BDB_CommissioningStatus_t status);
  /* Indication that the network settings of the device have been updated by the initiator.*/
  void (*updateNetworkIndication)(void);
  /* Indicates Trust center exchange procedure started */
  void (*tclkProcedureOngoing)(void);
  /* Indicates Trust center exchange procedure completed */
  void (*tclkProcedureCompleted)(void);
  /* Indicates identify querying for finding and binding */
  void (*querying)(void);
  /* Indicates identify query completed for finding and binding */
  void (*queryingCompleted)(void);
  /*Indicates binding links adding ongoing after touchlinking*/
  void (*addingBindingLinks)(void);
  /*Finding and binding completion with status*/
  void (*findingBindingCompleted)(BDB_CommissioningStatus_t status);
  /*Finding and binding initiator mode completion*/
  void (*findingBindingInitiatorModeCompleted)(void);
} BdbEventSubscriber_t;

/**************************************************************************//**
\brief Describes the reset using Touchlink commissioning cluster callback typedef
******************************************************************************/
typedef void (*ResetTargetCallback_t)(ResetTargetStatus_t status);

/**************************************************************************//**
\brief Describes the reset using Touchlink commissioning cluster callback typedef
******************************************************************************/
typedef void (*bdbCommissionCallback_t)(BDB_CommissioningStatus_t status);

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/
/** Indicates that a \ref BDB_InitMacLayer has completed successfully.
*/
typedef void (*BDB_InitDone_t)(void);

/**************************************************************************
\brief determine enabled commissioning modes
***************************************************************************/
BDB_CommissioningMode_t determineCommissionMode();

/******************************************************************************
                    Extern variables
******************************************************************************/
extern BDBIB_t bdbIB;

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Initialises the BDB component

\param initDoneCallback - callback after initialization

\return none
 ******************************************************************************/
void BDB_Init(BDB_InitDone_t initDoneCallback);

/**************************************************************************//**
\brief Initialises the BDB device level initalization
 ******************************************************************************/
void BDB_DeviceInit(void);

/**************************************************************************//**
\brief To enable nonCompliance advanced features along with auto commissioning
 ******************************************************************************/
void BDB_EnableAutoCommissioning(void);

/**************************************************************************//**
\brief To check Auto Commissioning is Enabled
 ******************************************************************************/
bool BDB_IsAutoCommissioningEnabled(void);

/**************************************************************************//**
\brief Resets the BDB Information base/Attributes
 ******************************************************************************/
void BDB_ResetIB(void);

/**************************************************************************//**
\brief Initialises the FSM component of the top level commissioning procedure
 ******************************************************************************/
void BDB_FsmInit(void);

/**************************************************************************//**
\brief The event handler for the component's task

\param[in] evt - event to process
\return true if event is handled, false - otherwise
 ******************************************************************************/
bool bdbCommissioning_EventHandler(N_Task_Event_t evt);

/**************************************************************************//**
\brief The commissioning API invokes the commissioning based on the given information in
       the request structure

\param[in] req - request structure information for invoking commissioning
\return true if event is handled, false - otherwise
******************************************************************************/
bool BDB_InvokeCommissioning(BDB_InvokeCommissioningReq_t *req);

/**************************************************************************//**
\brief Sets the channel mask BDB attribute

\param[in] type - type of the channel mask - primary or secondary
\param[in] channelMask - channel mask value to set
******************************************************************************/
void BDB_SetChannelMask(BDB_ChannelMaskType_t type, uint32_t channelMask);

/**************************************************************************//**
\brief Gets the channel mask BDB attribute

\param[in] type - type of the channel mask - primary or secondary
\return channelMask
******************************************************************************/
uint32_t BDB_GetChannelMask(BDB_ChannelMaskType_t type);

#if defined(_ROUTER_) || defined(_ENDDEVICE_)
/**************************************************************************//**
\brief Sets the TCLK Exchnage Method BDB attribute

\param[in] exchangeMethod - type of the TCLK exchange method
******************************************************************************/
void BDB_SetTCLKExchangeMethod(uint8_t exchangeMethod);

/**************************************************************************//**
\brief Sets the TCLK Retry Max Attempts BDB attribute

\param[in] attempts - number of max retry attempts
******************************************************************************/
void BDB_SetTCLKRetryMaxAttempts(uint8_t attempts);
#endif //#if defined(_ROUTER_) || defined(_ENDDEVICE_)

/**************************************************************************//**
\brief Get the commissioning capability of the device

\return BDB_NodeCommissioningCapability_t - commissioning capability
******************************************************************************/
BDB_NodeCommissioningCapability_t BDB_GetCommissioningCapability(void);

/**************************************************************************//**
\brief Sets the install code usage at the trust center

\param[in] useInstallCode - if it is true, TC will allow only install code devices to join
******************************************************************************/
void BDB_SetInstallCodeUsage (bool useInstallCode);

/**************************************************************************//**
\brief Sets the Node Join TimeOut

\param[in] timeOutInSec - timeout in seconds
******************************************************************************/
void BDB_SetNodeJoinTimeout (uint8_t timeOutInSec);

/**************************************************************************//**
\brief Sets the Trust center Require key change or not of the joining device

\param[in] requireKeyExchange - true or false
******************************************************************************/
void BDB_SetTCRequireKeyExchange (bool requireKeyExchange);

#if BDB_TOUCHLINK_SUPPORT == 1
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
/**************************************************************************//**
\brief Sets the Touchlink role

\param[in] initiator - true is initiator , false means target
******************************************************************************/
void BDB_SetToulinkRole(bool initiator);
/*TBD-Whether such API is needed or not based on application defintion */

/**************************************************************************//**
\brief Resets the target device to factory defaults using touchlink commissioning cluster

\param[in] pfcallback - callback to be called with status once the request is complete
******************************************************************************/
void BDB_ResetVia_TouchlinkCluster(ResetTargetCallback_t pfcallback);
#endif
#endif

/**************************************************************************//**
\brief bdb internal API for reset to factory new
******************************************************************************/
void bdbResetToFactoryNew(void);

/**************************************************************************//**
\brief bdb internal API to initiate self leave
******************************************************************************/
void bdbleaveNetwork(void);

/**************************************************************************//**
\brief BDB reset via local action

\param[in] leaveNetwork - leave network before resetting to FN
******************************************************************************/
void BDB_ResetToFactoryNew (bool leaveNetwork);

/**************************************************************************//**
\brief BDB set the device to allow to accept TL reset to FN

\param[in] allow - true - allows resettofn, false-does not allow
******************************************************************************/
void BDB_SetAllowTLResetToFN(bool allow);

/**************************************************************************//**
\brief Get the bdbNodeIsOnANetwork status

\return bool - true if the device is on network, false - otherwise
******************************************************************************/
bool BDB_GetBdbNodeIsOnANetwork(void);

/**************************************************************************//**
\brief To get link key type

\return bdb join link key type
******************************************************************************/
BDB_NodeJoinLinkKeyType_t BDB_GetBdbNodeJoinLinkKeyType(void);

#if defined(_TRUST_CENTRE_) && defined(ZIGBEE_COORDINATOR)
/**************************************************************************//**
\brief Reset the bdbTrustCenterNodeJoinInfoTable

\return None.
******************************************************************************/
void bdbTrustCenterResetNodeJoinInfoTable(void);
#endif /* #if defined(_TRUST_CENTRE_) && defined(ZIGBEE_COORDINATOR) */

/**************************************************************************//**
\brief BDB Subscribe to different events for application

\param[in] subscriber - Structure listing functions for Events
******************************************************************************/
void BDB_EventsSubscribe(const BdbEventSubscriber_t *subscriber);

/**************************************************************************//**
\brief Resets BDB F & B fsm

******************************************************************************/
void BDB_ResetFsm(void);

/**************************************************************************//**
\brief BDB Invoke Commissioning Confirm

\param[in] callbackFn - Callback Function
\param[in] conf       - Status
******************************************************************************/
void BDB_InvokeCommissioningConfirm(BDB_InvokeCommissioningConfCallback_t callbackFn, BDB_InvokeCommissioningConf_t *conf);

#endif // _BDB_H
