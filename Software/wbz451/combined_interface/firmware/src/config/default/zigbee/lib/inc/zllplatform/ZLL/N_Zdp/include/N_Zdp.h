/*******************************************************************************
  ZLL ZDP Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Zdp.h

  Summary:
    This file contains the ZLL ZDP functions.

  Description:
    This file contains the ZLL ZDP functions.
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


#ifndef N_ZDP_H
#define N_ZDP_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/
#include <zdo/include/zdo.h>
#include "zllplatform/infrastructure/N_Address/include/N_Address.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

/* The maximum possible ammount of concurrent ZDP requests. */
#ifndef N_ZDP_REQUESTS_POOL_SIZE
  #define N_ZDP_REQUESTS_POOL_SIZE 3u
#endif /* N_ZDP_REQUESTS_POOL_SIZE */

/** ZDP status values. See section 2.4.5 of the ZigBee 2007 specification
*/
typedef uint8_t N_Zdp_Status_t;

#define N_ZDP_STATUS_SUCCESS                    0x00u
#define N_ZDP_STATUS_INVALID_REQUEST_TYPE       0x80u
#define N_ZDP_STATUS_DEVICE_NOT_FOUND           0x81u
#define N_ZDP_STATUS_INVALID_ENDPOINT           0x82u
#define N_ZDP_STATUS_NOT_ACTIVE                 0x83u
#define N_ZDP_STATUS_NOT_SUPPORTED              0x84u
#define N_ZDP_STATUS_TIMEOUT                    0x85u
#define N_ZDP_STATUS_NO_MATCH                   0x86u

#define N_ZDP_STATUS_NO_ENTRY                   0x88u
#define N_ZDP_STATUS_NO_DESCRIPTOR              0x89u
#define N_ZDP_STATUS_INSUFFICIENT_SPACE         0x8Au
#define N_ZDP_STATUS_NOT_PERMITTED              0x8Bu
#define N_ZDP_STATUS_TABLE_FULL                 0x8Cu
#define N_ZDP_STATUS_NOT_AUTHORIZED             0x8Du

// Mgmt_NWK_Update_req - scanDuration field special values
#define N_ZDP_MGMT_NWK_UPDATE_CHANNEL_CHANGE    0xFEu
#define N_ZDP_MGMT_NWK_UPDATE_MASK_MANAGER      0xFFu

// Mgmt_Rtg_rsp status values
#define N_ZDP_STATUS_RTG_ENTRY_ACTIVE                 0x00u
#define N_ZDP_STATUS_RTG_ENTRY_DISCOVERY_UNDERWAY     0x01u
#define N_ZDP_STATUS_RTG_ENTRY_DISCOVERY_FAILED       0x02u
#define N_ZDP_STATUS_RTG_ENTRY_INACTIVE               0x03u

// make sure that the payload structures are packed
// ...assume that all compilers do support it
#pragma pack(1)


typedef struct N_Zdp_StatusRsp_t
{
    uint8_t           sequenceNumber;
    N_Zdp_Status_t    status;
} N_Zdp_StatusRsp_t;

typedef struct N_Zdp_AddrRsp_t
{
    uint8_t           sequenceNumber;
    N_Zdp_Status_t    status;
    N_Address_Extended_t ieeeAddrRemoteDevice;
    uint16_t          nwkAddrRemoteDevice;
} N_Zdp_AddrRsp_t;

typedef struct N_Zdp_MacCapability_t
{
    uint8_t alternatePANCoordinator : 1;
    uint8_t deviceType : 1;
    uint8_t powerSource : 1;
    uint8_t rxOnWhenIdle : 1;
    uint8_t reserved : 2;
    uint8_t securityCapability : 1;
    uint8_t allocateAddress : 1;
}  N_Zdp_MacCapability_t;

typedef struct N_Zdp_NodeDescriptor_t
{
	uint8_t logicalType : 3;
	uint8_t complexDescriptorAvailable: 1;
	uint8_t userDescriptorAvailable: 1;
	uint8_t reserved: 3;
	uint8_t apsFlags : 3;
	uint8_t frequencyBand : 5;
} N_Zdp_NodeDescriptor_t;

typedef struct N_Zdp_NodeDescRsp_t
{
    uint8_t  sequenceNumber;
    N_Zdp_Status_t status;
    uint16_t nwkAddrOfInterest;
    N_Zdp_NodeDescriptor_t nodeDescriptor;
    N_Zdp_MacCapability_t macCapabilityFlags;
    uint16_t manufacturerCode;
    uint8_t maximumBufferSize;
    uint16_t maxmimumIncomingTransferSize;
    uint16_t serverMask;
    uint16_t maximumOutgoingTransferSize;
    uint8_t descriptorCapabilityField;
} N_Zdp_NodeDescRsp_t;

typedef struct N_Zdp_MatchDescRsp_t
{
    uint8_t sequenceNumber;
    N_Zdp_Status_t status;
    uint16_t nwkAddrOfInterest;
    uint8_t matchLength;
    uint8_t *matchList;         ///< variable length array, matchLength entries
} N_Zdp_MatchDescRsp_t;

typedef struct N_Zdp_MgmtNwkUpdateReq_t
{
    uint8_t sequenceNumber;
    uint32_t channelMask;
    uint8_t scanDuration;
    union
    {
       struct EnergyScan_t
       {
            uint8_t scanCount;
       } energyScan;
       struct ChannelChange_t
       {
            uint8_t nwkUpdateId;
       } channelChange;
       struct ChannelMaskChange_t
       {
            uint8_t nwkUpdateId;
            uint16_t nwkManagerAddr;
       } channelMaskChange;
    } subCommand;
} N_Zdp_MgmtNwkUpdateReq_t;

typedef struct N_Zdp_RoutingTableRecord_t
{
    uint16_t destinationAddress;
    uint8_t status:3;
    uint8_t memoryConstraint:1;
    uint8_t manyToOne:1;
    uint8_t routeRecordRequired:1;
    uint8_t reserved:2;
    uint16_t nextHopAddress;
} N_Zdp_RoutingTableRecord_t;

typedef struct N_Zdp_MgmtRtgRsp_t
{
    uint8_t sequenceNumber;
    N_Zdp_Status_t status;
    uint8_t routingTableEntries;
    uint8_t startIndex;
    uint8_t routingTableListCount;
    N_Zdp_RoutingTableRecord_t pRoutingTableList[1];
} N_Zdp_MgmtRtgRsp_t;

typedef void (*pfReceivedMgmtNwkUpdateReq_t)(N_Zdp_MgmtNwkUpdateReq_t* pRequest);

typedef struct N_Zdp_DeviceAnnounce_t
{
    uint8_t           sequenceNumber;
    uint16_t          nwkAddr;
    N_Address_Extended_t     ieeeAddr;
    uint8_t           capability;
} N_Zdp_DeviceAnnounce_t;

typedef struct N_Zdp_NeighborTableRecord_t
{
    N_Address_Extended_t extendedPanId;
    N_Address_Extended_t extendedAddress;
    uint16_t networkAddress;
    uint8_t deviceType:2;
    uint8_t rxOnWhenIdle:2;
    uint8_t relationship:3;
    uint8_t reserved1:1;
    uint8_t permitJoining:2;
    uint8_t reserved2:6;
    uint8_t depth;
    uint8_t lqi;
} N_Zdp_NeighborTableRecord_t;

typedef struct N_Zdp_MgmtLqiRsp_t
{
    uint8_t sequenceNumber;
    N_Zdp_Status_t status;
    uint8_t neighborTableEntries;
    uint8_t startIndex;
    uint8_t neighborTableListCount;
    N_Zdp_NeighborTableRecord_t pNeighborTableList[1];
} N_Zdp_MgmtLqiRsp_t;

typedef struct N_Zdp_SimpleDescRsp_t
{
    uint8_t           sequenceNumber;
    N_Zdp_Status_t    status;
    uint16_t          nwkAddrOfInterest;
    uint8_t           length;
    uint8_t           endpoint;
    uint16_t          appProfileId;
    uint16_t          appDeviceId;
    uint8_t           appDeviceVersion:4;
    uint8_t           reserved:4;
    uint8_t           appNumInClusters;
    uint16_t          pAppInClusterList[1];
} N_Zdp_SimpleDescRsp_t;

typedef struct N_Zdp_SimpleDescRsp_OutList_t
{
    uint8_t           appNumOutClusters;
    uint16_t          pAppOutClusterList[1];
} N_Zdp_SimpleDescRsp_OutList_t;

typedef struct N_Zdp_ActiveEndPointRsp_t
{
    uint8_t           sequenceNumber;
    N_Zdp_Status_t    status;
    uint16_t          nwkAddrOfInterest;
    uint8_t           activeEPCount;
    uint8_t           *ActiveEPList; // variable length array, size is activeEPCount
} N_Zdp_ActiveEndPointRsp_t;

// back to the default packing
// ...assume that all other compilers do support it (only tested with visual studio)
#pragma pack()

/** Structure containing one binding table entry from a Mgmt_Bind_rsp command. */
typedef struct N_Zdp_BindingTableEntry_t
{
    /// Binding source address and endpoint. Always a IEEE address.
    N_Address_t bindSource;
    /// Binding cluster ID.
    uint16_t clusterId;
    /// Binding destination address. Either a IEEE address or a group address.
    N_Address_t bindDestination;
} N_Zdp_BindingTableEntry_t;

/** Structure containing a received Mgmt_Bind_rsp command. */
typedef struct N_Zdp_MgmtBindRsp_t
{
    /** Sequence number to identify request-response pair. */
    uint8_t sequenceNumber;
    /** Status. The other fields are only valid if the value of this field is ZSUCCESS. */
    N_Zdp_Status_t status;
    /** The total number of binding table entries on the device. */
    uint8_t bindingTableEntries;
    /** The index of the first binding table entry. */
    uint8_t startIndex;
    /** Number of binding table entries in the command. */
    uint8_t bindingTableListCount;
    /** Array with bindingTableListCount binding entries. */
    N_Zdp_BindingTableEntry_t* pBindingTableList;
} N_Zdp_MgmtBindRsp_t;

/** Result of energy detection scan. */
typedef struct N_Zdp_EDScanConfirm_t
{
  uint8_t status;
  uint32_t scannedChannels;
  uint8_t *energyDetectList;
} N_Zdp_EDScanConfirm_t;

typedef struct N_Zdp_ClientCallback_t
{
     /** Called when a ZDP command is received */
    void (*MessageReceived)(void);

    /** Called when a NWK_addr_rsp command is received, see ZigBee 2007 Specification 2.4.3.1.1. */
    void (*ReceivedNwkAddrRsp)(N_Zdp_AddrRsp_t* pRsp);

    /** Called when a IEEE_addr_rsp command is received, see ZigBee 2007 Specification 2.4.3.1.2. */
    void (*ReceivedIeeeAddrRsp)(N_Zdp_AddrRsp_t* pRsp);
    
    /** Called when a Node_Desc_rsp command is received, see ZigBee 2007 Specification 2.4.3.1.3. */
    void (*ReceivedNodeDescRsp)(N_Zdp_NodeDescRsp_t* pResponse);

    /** Called when a Simple_Desc_rsp command is received, see ZigBee 2007 Specification 2.4.4.1.5. */
    void (*ReceivedSimpleDescRsp)(N_Zdp_SimpleDescRsp_t* pResponse);

    /** Called when a Active_EP_rsp command is received, see ZigBee 2007 Specification 2.4.4.1.6. */
    void (*ReceivedActiveEndPointRsp)(N_Zdp_ActiveEndPointRsp_t* pResponse);

    /** Called when a Match_Desc_rsp command is received, see ZigBee 2007 Specification 2.4.4.1.7. */
    void (*ReceivedMatchDescRsp)(N_Zdp_MatchDescRsp_t* pRsp);

    /** Called when a Unbind_rsp command is received, see ZigBee 2007 Specification 2.4.3.2.2. */
    void (*ReceivedBindRsp)(N_Zdp_StatusRsp_t* pResponse);

    /** Called when a Unbind_rsp command is received, see ZigBee 2007 Specification 2.4.3.2.3. */
    void (*ReceivedUnbindRsp)(N_Zdp_StatusRsp_t* pResponse);

    /** Called when a Mgmt_Lqi_rsp command is received, see ZigBee 2007 Specification 2.4.4.3.2. */
    void (*ReceivedMgmtLqiRsp)(N_Zdp_MgmtLqiRsp_t* pResponse);

    /** Called when a Mgmt_Bind_rsp command is received, see ZigBee 2007 Specification 2.4.4.3.4. */
    void (*ReceivedMgmtBindRsp)(N_Zdp_MgmtBindRsp_t* pResponse);

    /** Called when a Mgmt_Permit_Joining_rsp command is received, see ZigBee 2007 Specification 2.4.4.3.7. */
    void (*ReceivedMgmtPermitJoiningRsp)(N_Zdp_StatusRsp_t* pResponse);

    /** Called when a Mgmt_Rtg_rsp command is received, see !ZigBee 2007 Specification 2.4.4.3.3. */
    void (*ReceivedMgmtRtgRsp)(N_Zdp_MgmtRtgRsp_t* pResponse);

    /** Called when a Mgmt_Leave_rsp command is received, see ZigBee 2007 Specification 2.4.4.3.5. */
    void (*ReceivedMgmtLeaveRsp)(N_Zdp_StatusRsp_t* pResponse);

    int8_t endOfList; // guard, must be initialized to -1
} N_Zdp_ClientCallback_t;

typedef struct N_Zdp_ServerCallback_t
{
    /** Called when a ZDP command is received */
    void (*MessageReceived)(void);

    /** Called when a DeviceAnnounce command is received.
    */
    void (*ReceivedDeviceAnnounce)(N_Zdp_DeviceAnnounce_t* pDeviceAnnounce);

    /** Called when a MgmtPermitJoinReq is received or has ended.
        \param permitted TRUE if joining is permitted, FALSE if the joining period has ended
    */
    void (*JoinPermitted)(bool permitted);

    int8_t endOfList; // guard, must be initialized to -1
} N_Zdp_ServerCallback_t;

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/

#define N_ZDP_ZDO_ENDPOINT 0u

/***************************************************************************************************
* EXPORTED PLATFORM INTERNAL FUNCTIONS
***************************************************************************************************/
/**************************************************************************//**
  \brief Subscribe a function that will be called when a Mgmt_NWK_Update_req command is received,
         see ZigBee 2007 Specification 2.4.3.3.9. Only used internally.

  \param callback
  
  \return None.
 *****************************************************************************/
void N_Zdp_Server_SubscribeForMgmtNwkUpdateReq(pfReceivedMgmtNwkUpdateReq_t callback);

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/
/**************************************************************************//**
  \brief Subscribes for N_Zdp responses.

  \param pSubscriber The subscriber
  
  \return None.
 *****************************************************************************/
void N_Zdp_ClientSubscribe(const N_Zdp_ClientCallback_t* pSubscriber);

/**************************************************************************//**
  \brief Subscribes for N_Zdp responses.

  \param pSubscriber The subscriber
  
  \return None.
 *****************************************************************************/
void N_Zdp_ServerSubscribe(const N_Zdp_ServerCallback_t* pSubscriber);

/**************************************************************************//**
  \brief Get the source address of the received ZDP message.
         Note: Only use from a ZDP callback function, otherwise the result is undefined.

  \param pSubscriber The subscriber
  
  \return The source address.
 *****************************************************************************/
N_Address_t* N_Zdp_GetSourceAddress(void);

void N_Zdp_ZdpRequest(ZDO_ZdpReq_t *zdpReq);

/**************************************************************************//**
  \brief Send DeviceAnnounce.

  \return The source address.
 *****************************************************************************/
uint8_t N_Zdp_SendDeviceAnnounce(void);

/**************************************************************************//**
  \brief Send NWK_addr_req, see ZigBee 2007 specification 2.4.3.1.1.
         \note Only the single request type is supported.

  \param pIeeeAddress IEEE address to request
  \param pDestinationAddress The address to send the command to
  
  \return The source address.
 *****************************************************************************/
uint8_t N_Zdp_SendNwkAddrReq(N_Address_Extended_t* pIeeeAddress, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send IEEE_addr_req, see ZigBee 2007 specification 2.4.3.1.2.
         Note: Only the single request type is supported.

  \param nwkAddressOfInterest network address to request
  \param pDestinationAddress The address to send the command to
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendIeeeAddrReq(uint16_t nwkAddressOfInterest, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Node_Desc_Req, see ZigBee 2007 specification 2.4.3.1.3.

  \param nwkAddrOfInterest
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendNodeDescReq(uint16_t nwkAddrOfInterest, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Simple_Desc_req, see ZigBee 2007 specification 2.4.3.1.5.

  \param nwkAddrOfInterest
  \param endPoint
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendSimpleDescReq(uint16_t nwkAddrOfInterest, uint8_t endPoint, N_Address_t *pDestinationAddress);

/**************************************************************************//**
  \brief Send Active_EP_req, see ZigBee 2007 specification 2.4.3.1.6.

  \param nwkAddrOfInterest
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendActiveEndPointReq(uint16_t nwkAddrOfInterest, N_Address_t *pDestinationAddress);

/**************************************************************************//**
  \brief Send a Match_Desc_req command, see ZigBee 2007 Specification  2.4.3.1.7.
         Note: This Implementation only allows a match with a single input cluster and no output cluster.

  \param nwkAddrOfInterest Network (Short) address to be used for matching
  \param profileId Profile ID to be used for matching
  \param inClusterId The Input ClusterID to be used for matching
  \param pDestinationAddress Destination address for the request.
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendMatchDescReq(uint16_t nwkAddrOfInterest, uint16_t profileId, uint16_t inClusterId, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Bind_req.

  \param pBindSource Binding source IEEE address and endpoint. Address type must be afAddr64Bit.
  \param clusterId Cluster ID to bind.
  \param pBindDestination Binding destination address. Address type must be afAddr64Bit or afAddrGroup.
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendBindReq(N_Address_t* pBindSource, uint16_t clusterId, N_Address_t* pBindDestination, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Unbind_req.

  \param pBindSource Binding source IEEE address and endpoint. Address type must be afAddr64Bit
  \param clusterId Cluster ID to unbind
  \param pBindDestination Binding destination address. Address type must be afAddr64Bit or afAddrGroup
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 *****************************************************************************/
uint8_t N_Zdp_SendUnbindReq(N_Address_t* pBindSource, uint16_t clusterId, N_Address_t* pBindDestination, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_Bind_req, see ZigBee 2007 specification 2.4.3.3.4.

  \param startIndex
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 ****************************************************************************/
uint8_t N_Zdp_SendMgmtBindReq(uint8_t startIndex, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_Lqi_req, see ZigBee 2007 specification 2.4.3.3.2.

  \param startIndex
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 ****************************************************************************/
uint8_t N_Zdp_SendMgmtLqiReq(uint8_t startIndex, N_Address_t *pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_Permit_Joining_req, see ZigBee 2007 specification 2.4.3.3.7.

  \param permitDuration
  \param trustCenterSignificance
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 ****************************************************************************/
uint8_t N_Zdp_SendMgmtPermitJoiningReq(uint8_t permitDuration, uint8_t trustCenterSignificance, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_NWK_Update_req, see ZigBee 2007 specification 2.4.3.3.9.

  \param channelMask The channels to scan
  \param scanDuration Scan duration
  \param scanCount Number of energy scans to be conducted (Not used)
  \param nwkUpdateId New network ID
  \param nwkManagerAddr Network address of the network manager (Not used)
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 ****************************************************************************/
uint8_t N_Zdp_SendMgmtNwkUpdateReq(uint32_t channelMask, uint8_t scanDuration, uint8_t scanCount,
  uint8_t nwkUpdateId, uint16_t nwkManagerAddr, N_Address_t *pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_Rtg_req, see ZigBee 2007 specification 2.4.3.3.3.

  \param startIndex
  \param pDestinationAddress Destination address of message
  
  \return The sequence number of the sent command, this can be used to match a received response with the request
 ****************************************************************************/
uint8_t N_Zdp_SendMgmtRtgReq(uint8_t startIndex, N_Address_t *pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_NWK_Update_notify, see ZigBee 2007 specification 2.4.4.3.9.

  \param totalTransmissions The number of transmissions reported by the device
  \param transmissionFailures Sum of the total transmission failures reported by the device
  \param transSeq The sequence number of the message to send
  \param pEDScanConfirm The Energy Detect Scan Confirm message
  \param pDestinationAddress Destination address of message
  
  \return None
 ****************************************************************************/
void N_Zdp_SendMgmtNwkUpdateNotify(uint16_t totalTransmissions, uint16_t transmissionFailures,
  uint8_t transSeq, N_Zdp_EDScanConfirm_t *pEDScanConfirm, N_Address_t *pDestinationAddress);

/**************************************************************************//**
  \brief Send Mgmt_Leave_Req, see ZigBee 2007 specificaiton 2.4.3.3.5.

  \param deviceIeeeAddress The IEEE address of the device to be removed.
  \param removeChildren If TRUE the device should also remove its children.
  \param rejoin If TRUE the device is requested to rejoin the network.
  \param pDestinationAddress Destination address of message
  
  \return status
 ****************************************************************************/
uint8_t N_Zdp_SendMgmtLeaveReq(N_Address_Extended_t deviceIeeeAddress, bool removeChildren, bool rejoin, N_Address_t* pDestinationAddress);

/**************************************************************************//**
  \brief Checks if received status is one of ZigBee spec. standard ZDP statuses.

  \param bcStatus BitCloud ZDO status
  
  \return True, if status is ZigBee spec. standard statuses, false - BitCloud-specific one.
 ****************************************************************************/
bool N_Zdp_IsZigBeeStandardStatus(ZDO_Status_t bcStatus);
/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_ZDP_H
