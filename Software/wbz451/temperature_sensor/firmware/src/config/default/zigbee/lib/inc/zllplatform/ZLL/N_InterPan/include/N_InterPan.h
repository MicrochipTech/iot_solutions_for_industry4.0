/*******************************************************************************
  ZLL Inter Pan Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_InterPan.h

  Summary:
    This file contains the ZLL Inter Pan functions.

  Description:
    Send/receive Inter-PAN commands. For detailed descriptions of the commands and their
    parameters, see the specification (version 1.0).

    Note that the current implementation only works on little-endian architectures.
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


#ifndef N_INTERPAN_H
#define N_INTERPAN_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Address/include/N_Address.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/

#define NETWORK_KEY_LENGTH 16u

/** The maximum number of device info records in a device info response. */
#define N_INTERPAN_DEVICE_INFO_RECORD_MAX 5u

/* ZigBee info */
#define N_INTERPAN_ZIGBEE_INFO_LOGICAL_TYPE 0x03u
#define N_INTERPAN_ZIGBEE_INFO_COORDINATOR  0x00u
#define N_INTERPAN_ZIGBEE_INFO_ROUTER       0x01u
#define N_INTERPAN_ZIGBEE_INFO_END_DEVICE   0x02u

#define N_INTERPAN_ZIGBEE_INFO_RX_ON_IDLE   0x04u

/* ZLL info */
#define N_INTERPAN_ZLL_INFO_FACTORY_NEW                0x01u
#define N_INTERPAN_ZLL_INFO_ADDRESS_ASSIGNMENT         0x02u
#define N_INTERPAN_ZLL_INFO_TOUCHLINK_INITIATOR        0x10u
#define N_INTERPAN_ZLL_INFO_TOUCHLINK_PRIORITY_REQUEST 0x20u
#define N_INTERPAN_ZLL_INFO_PROFILE_INTEROP            0x80u

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

typedef uint8_t NetworkKey_t[NETWORK_KEY_LENGTH];

// make sure that the Inter-PAN payload structures are packed
// ...assume that all compilers do support it
#pragma pack(1)

/** ZCL frame header - frame control field. */
typedef struct N_InterPan_FrameControl_t
{
    unsigned char type:2;
    unsigned char manufacturerSpecific:1;
    unsigned char direction:1;
    unsigned char disableDefaultResponse:1;
    unsigned char reserved:3;
} N_InterPan_FrameControl_t;

/** ZCL frame header.
    This field is filled in by N_InterPan before the frame is sent, so it can be left uninitialised.
*/
typedef struct N_InterPan_FrameHeader_t
{
    N_InterPan_FrameControl_t  frameControl;
    //uint16_t manufacturerCode;  // May be added later, but this requires additional code to skip it when not needed
    uint8_t                    transactionSequenceNumber;
    uint8_t                    commandId;
} N_InterPan_FrameHeader_t;

/** ZCL frame header with manufacturerCode.
    This field is filled in by N_InterPan before the frame is sent, so it can be left uninitialised.
*/
typedef struct N_InterPan_FrameHeader_ManufacturerSpecific_t
{
    N_InterPan_FrameControl_t  frameControl;
    uint16_t                   manufacturerCode;
    uint8_t                    transactionSequenceNumber;
    uint8_t                    commandId;
} N_InterPan_FrameHeader_ManufacturerSpecific_t;

/** Device (endpoint) info used in ScanResponse and DeviceInfoResponse commands */
typedef struct N_InterPan_DeviceInfo_t
{
    N_Address_Extended_t       ieeeAddress;
    uint8_t                    endPoint;
    uint16_t                   profileId;
    uint16_t                   deviceId;
    uint8_t                    version;
    uint8_t                    groupIds;
    uint8_t                    sort;
} N_InterPan_DeviceInfo_t;

/** ScanRequest command. */
typedef struct N_InterPan_ScanRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint8_t                    zigBeeInfo;
    uint8_t                    zllInfo;
} N_InterPan_ScanRequest_t;

/** ScanResponse command. */
typedef struct N_InterPan_ScanResponse_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint8_t                    touchlinkRssiCorrection;
    uint8_t                    zigBeeInfo;
    uint8_t                    zllInfo;
    uint16_t                   keyBitMask;
    uint32_t                   responseId;
    N_Address_ExtendedPanId_t  extendedPanId;
    uint8_t                    networkUpdateId;
    uint8_t                    channel;
    uint16_t                   panId;
    uint16_t                   networkAddress;
    uint8_t                    numberSubDevices;
    uint8_t                    totalGroupIds;
    // optional fields only present when numberSubDevices == 1
    uint8_t                    endPoint;
    uint16_t                   profileId;
    uint16_t                   deviceId;
    uint8_t                    version;
    uint8_t                    groupIds;
} N_InterPan_ScanResponse_t;

/** DeviceInfoRequest command. */
typedef struct N_InterPan_DeviceInfoRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint8_t                    startIndex;
} N_InterPan_DeviceInfoRequest_t;

/** DeviceInfoResponse command. */
typedef struct N_InterPan_DeviceInfoResponse_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint8_t                    numberSubDevices;
    uint8_t                    startIndex;
    uint8_t                    count;
    N_InterPan_DeviceInfo_t    deviceInfo[N_INTERPAN_DEVICE_INFO_RECORD_MAX];
} N_InterPan_DeviceInfoResponse_t;

/** IdentifyRequest command. */
typedef struct N_InterPan_IdentifyRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint16_t                   identifyTime;
} N_InterPan_IdentifyRequest_t;

/** NetworkStartRequest command. */
typedef struct N_InterPan_NetworkStartRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    N_Address_ExtendedPanId_t  extendedPanId;
    uint8_t                    keyIndex;
    NetworkKey_t               encryptedNetworkKey;
    uint8_t                    channel;
    uint16_t                   panId;
    uint16_t                   networkAddress;
    uint16_t                   groupIdsBegin;
    uint16_t                   groupIdsEnd;
    uint16_t                   freeNetworkAddressRangeBegin;
    uint16_t                   freeNetworkAddressRangeEnd;
    uint16_t                   freeGroupIdRangeBegin;
    uint16_t                   freeGroupIdRangeEnd;
    N_Address_Extended_t       endDeviceIeeeAddress;
    uint16_t                   endDeviceNetworkAddress;
} N_InterPan_NetworkStartRequest_t;

/** NetworkStartResponse command. */
typedef struct N_InterPan_NetworkStartResponse_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint8_t                    status;
    N_Address_ExtendedPanId_t  extendedPanId;
    uint8_t                    networkUpdateId;
    uint8_t                    channel;
    uint16_t                   panId;
} N_InterPan_NetworkStartResponse_t;

/** NetworkJoinRouterRequest and NetworkJoinEndDeviceRequest commands (same payload). */
typedef struct N_InterPan_NetworkJoinRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    N_Address_ExtendedPanId_t  extendedPanId;
    uint8_t                    keyIndex;
    NetworkKey_t               encryptedNetworkKey;
    uint8_t                    networkUpdateId;
    uint8_t                    channel;
    uint16_t                   panId;
    uint16_t                   networkAddress;
    uint16_t                   groupIdsBegin;
    uint16_t                   groupIdsEnd;
    uint16_t                   freeNetworkAddressRangeBegin;
    uint16_t                   freeNetworkAddressRangeEnd;
    uint16_t                   freeGroupIdRangeBegin;
    uint16_t                   freeGroupIdRangeEnd;
} N_InterPan_NetworkJoinRequest_t;

/** NetworkJoinRouterResponse and NetworkJoinEndDeviceResponse commands (same payload). */
typedef struct N_InterPan_NetworkJoinResponse_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    uint8_t                    status;
} N_InterPan_NetworkJoinResponse_t;

/** NetworkUpdateRequest command. */
typedef struct N_InterPan_NetworkUpdateRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
    N_Address_ExtendedPanId_t  extendedPanId;
    uint8_t                    networkUpdateId;
    uint8_t                    channel;
    uint16_t                   panId;
    uint16_t                   networkAddress;
} N_InterPan_NetworkUpdateRequest_t;

/** ResetToFactoryDefaultsRequest command. */
typedef struct N_InterPan_ResetToFactoryNewRequest_t
{
    N_InterPan_FrameHeader_t   header;
    uint32_t                   transactionId;
} N_InterPan_ResetToFactoryNewRequest_t;

// back to the default packing
// ...assume that all compilers do support it (only tested with visual studio)
#pragma pack()

/** Callback structure. */
typedef struct N_InterPan_Callback_t
{
    /** Received a ScanRequest command. */
    void (*ReceivedScanRequest)(N_InterPan_ScanRequest_t* pPayload, int8_t rssi, N_Address_Extended_t* pSourceAddress);
    /** Received a ScanResponse command. */
    void (*ReceivedScanResponse)(N_InterPan_ScanResponse_t* pPayload, int8_t rssi, N_Address_Extended_t* pSourceAddress);
    /** Received a DeviceInfoRequest command. */
    void (*ReceivedDeviceInfoRequest)(N_InterPan_DeviceInfoRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a DeviceInfoResponse command. */
    void (*ReceivedDeviceInfoResponse)(N_InterPan_DeviceInfoResponse_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a IdentifyRequest command. */
    void (*ReceivedIdentifyRequest)(N_InterPan_IdentifyRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkStartRequest command. */
    void (*ReceivedNetworkStartRequest)(N_InterPan_NetworkStartRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkStartResponse command. */
    void (*ReceivedNetworkStartResponse)(N_InterPan_NetworkStartResponse_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkJoinRouterRequest command. */
    void (*ReceivedNetworkJoinRouterRequest)(N_InterPan_NetworkJoinRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkJoinRouterResponse command. */
    void (*ReceivedNetworkJoinRouterResponse)(N_InterPan_NetworkJoinResponse_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkJoinEndDeviceRequest command. */
    void (*ReceivedNetworkJoinEndDeviceRequest)(N_InterPan_NetworkJoinRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkJoinEndDeviceResponse command. */
    void (*ReceivedNetworkJoinEndDeviceResponse)(N_InterPan_NetworkJoinResponse_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a NetworkUpdateRequest command. */
    void (*ReceivedNetworkUpdateRequest)(N_InterPan_NetworkUpdateRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);
    /** Received a ResetToFactoryNew command. */
    void (*ReceivedResetToFactoryNewRequest)(N_InterPan_ResetToFactoryNewRequest_t* pPayload, N_Address_Extended_t* pSourceAddress);

    /** Generic callback to handle an Inter-PAN command. Keep this callback last in the list.
        \param clusterId The cluster ID that the command was received
        \param payloadLength The length of the payload data
        \param pPayload The payload data that has been received
        \param rssi The received signal strength indication
        \param pSourceAddress The IEEE address of the sender of the of the message
        \note The payload includes a ZCL header.
        \note This callback is also called for any of the 'known' InterPan commands.
    */
    void (*ReceivedInterPanCommand)(uint16_t clusterId, uint16_t payloadLength, uint8_t* pPayload, int8_t rssi, N_Address_Extended_t* pSourceAddress);

    /** Guard to ensure the initialiser contains all functions. */
    int8_t endOfList;
} N_InterPan_Callback_t;

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/
/**************************************************************************//**
  \brief Subscribe for callbacks from this component.
  
  \param pCallback Pointer to filled callback structure

  \return None
 *****************************************************************************/
void N_InterPan_Subscribe(const N_InterPan_Callback_t* pCallback);

/**************************************************************************//**
  \brief Broadcast ScanRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized

  \return None
 *****************************************************************************/
void N_InterPan_BroadcastScanRequest(N_InterPan_ScanRequest_t* pPayload);

/**************************************************************************//**
  \brief Unicast ScanRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_UnicastScanRequest(N_InterPan_ScanRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a ScanResponse command.
  
  \param pPayload Pointer to filled payload structure, the header should contain the same sequence number as the request, 
         rest should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendScanResponse(N_InterPan_ScanResponse_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a DeviceInfoRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendDeviceInfoRequest(N_InterPan_DeviceInfoRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a DeviceInfoResponse command.
  
  \param pPayload Pointer to filled payload structure, the header should contain the same sequence
         number as the request, rest should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendDeviceInfoResponse(N_InterPan_DeviceInfoResponse_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a IdentifyRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendIdentifyRequest(N_InterPan_IdentifyRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkStartRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkStartRequest(N_InterPan_NetworkStartRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkStartResponse command.
  
  \param pPayload Pointer to filled payload structure, the header should contain the same sequence number
         as the request, rest should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkStartResponse(N_InterPan_NetworkStartResponse_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkJoinEndDeviceRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkJoinRouterRequest(N_InterPan_NetworkJoinRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkJoinEndDeviceResponse command.
  
  \param pPayload Pointer to filled payload structure, the header should contain the same sequence number as the request, rest should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkJoinRouterResponse(N_InterPan_NetworkJoinResponse_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkJoinEndDeviceRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkJoinEndDeviceRequest(N_InterPan_NetworkJoinRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkJoinEndDeviceResponse command.
  
  \param pPayload Pointer to filled payload structure, the header should contain the same sequence number as the request, rest should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkJoinEndDeviceResponse(N_InterPan_NetworkJoinResponse_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a NetworkUpdateRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendNetworkUpdateRequest(N_InterPan_NetworkUpdateRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send a ResetToFactoryNewRequest command.
  
  \param pPayload Pointer to filled payload structure, the header should be uninitialized
  \param pDestinationAddress Destination IEEE address

  \return None
 *****************************************************************************/
void N_InterPan_SendResetToFactoryNewRequest(N_InterPan_ResetToFactoryNewRequest_t* pPayload, N_Address_Extended_t* pDestinationAddress);

/**************************************************************************//**
  \brief Send an Inter-PAN command. Note:  The payload should include a proper ZCL header.
  
  \param clusterId The cluster ID to use (e.g. 0x1000)
  \param payloadLength Length of the payload data (in bytes)
  \param pPayload Pointer to payload data
  \param destinationPanId The destination PAN ID (typically 0xFFFF)
  \param pDestinationAddress Destination IEEE address, or NULL to broadcast the command.

  \return None
 *****************************************************************************/
void N_InterPan_SendInterPanCommand(uint16_t clusterId, uint8_t payloadLength, uint8_t* pPayload, uint16_t destinationPanId, N_Address_Extended_t* pDestinationAddress);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_INTERPAN_H
