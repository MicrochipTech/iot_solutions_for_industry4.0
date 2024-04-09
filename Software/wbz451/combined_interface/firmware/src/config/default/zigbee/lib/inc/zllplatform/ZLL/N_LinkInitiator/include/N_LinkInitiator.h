/*******************************************************************************
  ZLL Link Initiator Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_LinkInitiator.h

  Summary:
    Initiate touch-link actions.

  Description:
    
    A linking sequence consists roughly of the following steps:
    \image html N_LinkInitiator_LinkingSequence.png
    <!--
    @startuml N_LinkInitiator_LinkingSequence.png

    participant "Initiator" as i
    participant "Target" as t

    group Scanning
      i->t : ScanRequest
      t->i : ScanResponse
    end
    group Identify (optional)
      i->t : IdentifyRequest
    end
    group Add device
      i->t : NetworkJoinRequest
      t->i : NetworkJoinResponse
    end
    @enduml
    -->

    The N_LinkInitiator component implements the software interface to implement the initiator-side of this.

    The Scanning step is initiated using the \ref N_LinkInitiator_Scan() function.
    At the end of the Scanning step, the application typically selects one of the found devices to continue with.
    It may then first further interrogate this device by calling \ref N_LinkInitiator_DeviceInfoRequest().

    The Identify step (to have the selected device identify itself for the user) is optional but it is
    typically only used for touch-linking.

    The Add device step causes an action to be performed with the selected device. The following actions
    are currently supported:
     - \ref N_LinkInitiator_JoinDevice() (causes the selected target device to be joined to the network of the initiator). This
    may cause any of the following InterPan commands to be sent, depending on the situation:
        - StartNetworkRequest
        - RouterJoinNetworkRequest
        - EndDeviceJoinNetworkRequest
        - NetworkUpdateRequest
     - \ref N_LinkInitiator_ResetDeviceToFactoryNew() to reset a device to factory defaults

    \section Callbacks
    Its interface consists of asynchronous functions that each have a Done callback function pointer parameter.

    <b>Note</b>: No function is allowed to be called while any other function is busy.
    The only exception is N_LinkInitiator_StopScan(), which is allowed to be called while a Scan is busy.

    \section IIL Being Initiator and Target simultaneously
    \par
    When starting a linking action from 2 devices at the same time (e.g. linking two ZLL remotes), one
    of the devices should become target (to be decided by the application) and the other one should
    continue being an initiator.
    So when a device that is both target and initiator at the same time receives a scan request while it
    is scanning, the application can decide to abort scanning (and remain target) so it can be linked.

    Only during the Scanning step, a device may be Target and Initiator at the same time. During the
    other steps, the device must give up being a Target.

    \section Establishing Communications
    \par
    To ensure that the application can reliably communicate to the just-linked device, N_LinkInitiator
    uni-casts a (dummy) message to the linked target, requesting a response. This is retried a few times.
    If no response is received even after the retries, the linking is still considered to be partly
    successful, but it returns N_LinkInitiator_Status_CommunicationNotEstablished.

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


#ifndef N_LINKINITIATOR_H
#define N_LINKINITIATOR_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Address/include/N_Address.h"
#include "ZLL/N_InterPan/include/N_InterPan.h"
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

typedef enum N_LinkInitiator_Status_t
{
    /** The action succeeded. */
    N_LinkInitiator_Status_Ok,

    /** The action failed. */
    N_LinkInitiator_Status_Failure,

    /** The action was stopped by the user. */
    N_LinkInitiator_Status_Stopped,

    /** The JoinDevice failed due a timeout. */
    N_LinkInitiator_Status_Timeout,

    /** The JoinDevice succeeded, but could not communicate to the target device within a timeout, for example due to a lack of a parent. */
    N_LinkInitiator_Status_CommunicationNotEstablished,
} N_LinkInitiator_Status_t;

typedef struct N_LinkInitiator_Callback_t
{
     /** Indication that the device has been assigned group adresses.
        \param groupIdFirst The first group identifier assigned to the device during linking.
            Zero if no groups where assigned
        \param groupIdLast The last group identifier assigned to the device during linking.
            Zero if no groups where assigned
    */
    void (*GroupAddressesAssigned)(uint16_t groupIdFirst, uint16_t groupIdLast);

    /** Guard. Must be -1. */
    int8_t endOfList;

} N_LinkInitiator_Callback_t;

/** Completion callback for N_LinkInitiator_Scan and N_LinkInitiator_ScanDirect.
    \param status The result of the call
    \param numDevicesFound Number of devices found during the scan
*/
typedef void (*N_LinkInitiator_ScanDone_t)(N_LinkInitiator_Status_t status, uint8_t numDevicesFound);

/** Completion callback for N_LinkInitiator_DeviceInfoRequest.
    \param status The result of the call
*/
typedef void (*N_LinkInitiator_DeviceInfoRequestDone_t)(N_LinkInitiator_Status_t status);

/** Completion callback for N_LinkInitiator_JoinDevice.
    \param status The result of the call
    \param targetNetworkAddress The network address of the target that was joined
*/
typedef void (*N_LinkInitiator_JoinDeviceDone_t)(N_LinkInitiator_Status_t status, uint16_t targetNetworkAddress);

/** Completion callback for N_LinkInitiator_IdentifyStartRequest and N_LinkInitiator_IdentifyStopRequest.
    \param status The result of the call
*/
typedef void (*N_LinkInitiator_IdentifyRequestDone_t)(N_LinkInitiator_Status_t status);

/** Completion callback for N_LinkInitiator_ResetDevice.
    \param status The result of the call
*/
typedef void (*N_LinkInitiator_ResetDeviceToFactoryNewDone_t)(N_LinkInitiator_Status_t status);

#define N_LinkInitiator_ScanType_Touchlink                  0x02u
#define N_LinkInitiator_ScanType_OwnPanOnly                 0x04u
#define N_LinkInitiator_ScanType_IncludeSecondaryChannels   0x08u
typedef uint8_t N_LinkInitiator_ScanType_t;

typedef struct N_LinkInitiator_EndpointInfo_t
{
    N_InterPan_DeviceInfoResponse_t deviceInfoResponse;
} N_LinkInitiator_EndpointInfo_t;

typedef struct N_LinkInitiator_Device_t
{
    N_Address_Extended_t ieeeAddress;
    int8_t rssi;
    N_InterPan_ScanResponse_t scanResponse;
} N_LinkInitiator_Device_t;

/***************************************************************************************************
* EXPORTED CONSTANTS AND MACROS
***************************************************************************************************/

#define N_LINK_IDENTIFY_TIME_DEFAULT 0xFFFFu

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/
/**************************************************************************//**
  \brief Subscribe to indication callbacks from this component.

  \param[in] pCb Pointer to structure with callback functions

  \returns None
******************************************************************************/
void N_LinkInitiator_Subscribe(const N_LinkInitiator_Callback_t* pCb);

/**************************************************************************//**
  \brief Scan for devices.

  \param scanType Indicates whether to do a scan for touchlink and
         optionally return only devices belonging to own PAN or scan on more channels.
  \param dev Client-allocated array that is at least devArraySize elements large, to store found
          devices.
  \param devArraySize Maximum number of devices to return.
  \param pfDoneCallback Callback function pointer that is called upon completion. \see
           N_LinkInitiator_ScanDone_t.
		   
	Initiates a Scan. When the completion function is called, the dev[] array is filled with found
    devices, sorted on (corrected) RSSI values and taking the Touchlink Priority bit into account.

    The \ref N_LinkInitiator_ScanType_IncludeSecondaryChannels option can be used for touchlinking
    to scan both primary and secondary channels. Scanning the secondary channels takes an extra
    3 seconds.

    The application must decide when to scan the secondary channels and when
    to scan the primary channels only. Use the following guidelines:
       -# In a network with a central trust center (see \ref N_DeviceInfo_GetTrustCenterMode),
          always scan both primary and secondary channels.
       -# When scanning to find a device to reset to factory defaults, always scan both
          primary and secondary channels.
       -# In all other situations, scan the primary channels only. This will speed up scanning.

     - The Touchlink scan sequence is described in the ZLL specification. Summarized, it first sends five
    InterPan ScanRequest commands on the first channel of the primary channel mask, followed by one InterPan
    ScanRequest command on each of the other channels of the primary channel mask. Then, this is optionally followed
    by one InterPan ScanRequest command on each of the channels of the secondary channel mask. All of
    these ScanRequest commands are separated by 250 milliseconds.

    Any type of scan sequence can be stopped by calling \ref N_LinkInitiator_StopScan.

  \returns None
******************************************************************************/
void N_LinkInitiator_Scan(N_LinkInitiator_ScanType_t scanType, N_LinkInitiator_Device_t dev[], uint8_t devArraySize, N_LinkInitiator_ScanDone_t pfDoneCallback);

/**************************************************************************//**
  \brief  Requests a busy scan to stop. The client still needs to wait for the 
          \ref N_LinkInitiator_ScanDone_t completion callback to be called.

  \return None.
 *****************************************************************************/
void N_LinkInitiator_StopScan(void);

/**************************************************************************//**
  \brief  Send an IdentifyStartRequest to a scanned device.

  \param pDev A device returned from a scan (for example the first entry of the array).
  \param timeoutInSec The identify timeout, in seconds, or N_LINK_IDENTIFY_TIME_DEFAULT.
  \param pfDoneCallback The completion function pointer.

  \return None.
 *****************************************************************************/
void N_LinkInitiator_IdentifyStartRequest(N_LinkInitiator_Device_t* pDev, uint16_t timeoutInSec, N_LinkInitiator_IdentifyRequestDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Send an IdentifyStopRequest to a scanned device.

  \param pDev A device returned from a scan (for example the first entry of the array).
  \param pfDoneCallback The completion function pointer.

  \return None.
 *****************************************************************************/
void N_LinkInitiator_IdentifyStopRequest(N_LinkInitiator_Device_t* pDev, N_LinkInitiator_IdentifyRequestDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Sends a DeviceInfoRequest to a scanned device. Can be used to obtain additional endpoint information of the device.
        Note: Depending on the number of sub-devices (application endpoints) of the selected device, this may
        cause zero or more InterPan DeviceInfoRequest commands to be sent. When the device has exactly
        one sub-device, no InterPan DeviceInfoRequest command is sent at all - the information is just
        copied from the passed \ref N_LinkInitiator_Device_t structure.

  \param pDev A device returned from a scan (for example the first entry of the array)
  \param epInfo Client-allocated array that is used to store found endpoint information
  \param epInfoArraySize The size of the epInfo array (# of elements) must greater than or equal to pDev->scanResponse.numberSubDevices
  \param pfDoneCallback The completion function pointer

  \return None.
 *****************************************************************************/
void N_LinkInitiator_DeviceInfoRequest(N_LinkInitiator_Device_t* pDev, N_InterPan_DeviceInfo_t epInfo[], uint8_t epInfoArraySize, N_LinkInitiator_DeviceInfoRequestDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Join the target device to the network. If the initiator was factory new, it will join the network as well.
         If the initiator is factory new, then a new network will be started and the initiator will join this network as well.
		 Note: It is not allowed to call any other N_LinkInitiator functions until the DeviceJoined callback is received.

  \param pTarget The target device info (one of the scan results). The pointer must be valid until the completion callback is received.
  \param skipCommunicationCheck If true, N_LinkInitiator will not try to verify communcation after the target device is joined. The callback will return N_LinkInitiator_Status_CommunicationNotEstablished when done.
  \param pfDoneCallback Pointer to the function that will be called after the join sequence is completed. \see N_LinkInitiator_JoinDeviceDone_t

  \return None.
 *****************************************************************************/
void N_LinkInitiator_JoinDevice(N_LinkInitiator_Device_t* pTarget, bool skipCommunicationCheck, N_LinkInitiator_JoinDeviceDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Reset a device to factory defaults.

  \param pDev A device returned from a scan (for example the first entry of the array).
  \param pfDoneCallback The completion function pointer.

  \return None.
 *****************************************************************************/
void N_LinkInitiator_ResetDeviceToFactoryNew(N_LinkInitiator_Device_t* pDev, N_LinkInitiator_ResetDeviceToFactoryNewDone_t pfDoneCallback);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_LINKINITIATOR_H
