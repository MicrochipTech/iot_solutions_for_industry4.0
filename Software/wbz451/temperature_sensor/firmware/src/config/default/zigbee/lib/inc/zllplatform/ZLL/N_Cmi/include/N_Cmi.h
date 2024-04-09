/*******************************************************************************
  ZLL CMI Component Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Cmi.h

  Summary:
    This file contains the ZLL CMI Component functions.

  Description:
    This file contains the ZLL CMI Component functions.
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


#ifndef N_CMI_H
#define N_CMI_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include <mac_phy/include/macCommon.h>

#include "zllplatform/infrastructure/N_Address/include/N_Address.h"
#include "zllplatform/ZLL/N_Beacon/include/N_Beacon.h"
#include "zllplatform/ZLL/N_Security/include/N_Security.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"
#include "zllplatform/ZLL/N_Connection/include/N_Connection.h"

#include "aps/include/apsdeData.h"
#include "zdo/include/zdo.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

typedef enum N_Cmi_Result_t
{
    N_Cmi_Result_Success,
    N_Cmi_Result_Failure,
    N_Cmi_Result_NoNetworkKey,
    N_Cmi_Result_Invalid_Request,
} N_Cmi_Result_t;

typedef struct N_Cmi_Callback_t
{
    /** The end-device has detected that it has lost its parent.
    */
    void (*SyncLoss)(void);

    /** Indicate that the device is going to join a (new) network.

        This is called when \ref N_Cmi_StartNetworking is called.
        The callback can be used by platform components to reset variables.
        Application components can use the callback from N_DeviceInfo to
        see if a network is joined. This ensures that the platform components
        get a notification before the application components.
    */
    void (*StartNetworking)(void);

    /** The device has received a network key, for example after joining a network via association.
        \param networkKeySequenceNumber The sequence number of the received network key
    */
    void (*NetworkKeyIndication)(uint8_t networkKeySequenceNumber);

    /** The device has received a new network address (probably after an address conflict).
        \param networkAddress The new network address
    */
    void (*NetworkAddressChanged)(uint16_t networkAddress);

    /** The device has received a leave request or leave indication.
        \param leaveIndication The leave request/indication
    */

    /** Guard. */
    int8_t endOfList;

} N_Cmi_Callback_t;

/** Indicates that a beacon has been received during \ref N_Cmi_NetworkDiscovery.
    \param beaconIndication The beacon
*/
typedef void (*N_Cmi_BeaconIndication_t)(N_Beacon_t* beaconIndication);

/** Indicates that the \ref N_Cmi_NetworkDiscovery has completed.
*/
typedef void (*N_Cmi_NetworkDiscoveryDone_t)(void);

/** Indicates that a \ref N_Cmi_Join, \ref N_Cmi_Rejoin, \ref N_Cmi_RejoinParent or \ref N_Cmi_OrphanJoin has completed.
    \param result The result of the action
*/
typedef void (*N_Cmi_JoinDone_t)(N_Cmi_Result_t result);

/** Indicates that a \ref N_Cmi_StartNetworking has completed.
    \param result The result of the action
*/
typedef void (*N_Cmi_StartRouterDone_t)(N_Cmi_Result_t result);

/** Indicates that a \ref N_Cmi_SetMacChannel or N_Cmi_UpdateNetworkChannel has completed successfully.
*/
typedef void (*N_Cmi_SetChannelDone_t)(void);

/** Indicates that ZLL preinstalled TC link key was set marked as a primary global key.
*/
typedef void (*N_Cmi_SetZllLinkKeyAsPrimaryDone_t)(void);

/** Beacon filtering modes.
*/
typedef enum _N_Cmi_BeaconFilteringCriterion_t
{
  BEACON_FILTERING_CRITERION_NONE,
  BEACON_FILTERING_CRITERION_ASSOCIATION,
  BEACON_FILTERING_CRITERION_NETWORK_SEARCH,
  BEACON_FILTERING_CRITERION_RECONNECT
} N_Cmi_BeaconFilteringCriterion_t;

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Subscribe for events from this component

  \param[in] pSubscriber - pointer to subscriber

  \return None
 ******************************************************************************/
void N_Cmi_Subscribe(const N_Cmi_Callback_t* pSubscriber);

/**************************************************************************//**
  \brief Set the MAC channel.

  \param[in] channel to be set
  \param[in] pfDoneCallback - channel set done call back pointer

  \return None
 ******************************************************************************/

void N_Cmi_SetMacChannel(uint8_t channel, N_Cmi_SetChannelDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Get the MAC channel.

  \return Channel number
 ******************************************************************************/
uint8_t N_Cmi_GetMacChannel(void);

/**************************************************************************//**
  \brief Start this device (router/end-device) in a ZigBee network.

  \return Result status
 ******************************************************************************/

N_Cmi_Result_t N_Cmi_StartNetworking(N_Address_Extended_t pExtendedPanId,
                                     uint8_t channel,
                                     uint16_t panId,
                                     uint16_t networkAddress,
                                     uint8_t networkUpdateId,
                                     N_Security_Key_t networkKey);

/**************************************************************************//**
  \brief Start routing on this device. A router device is not fully operational until this function returns success.
        Note: This function is only implemented on a router

  \param[in] pfDoneCallback Pointer to the function that will be called when this function is done

  \return Result status
 ******************************************************************************/
void N_Cmi_StartRouter(N_Cmi_StartRouterDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Perform a network discovery (active scan).
        
  \param[in] channelMask The channels to scan
  \param[in] durationPerChannel The time to stay at each channel (enum)
  \param[in] pBeacon Pointer to memory that is used to return a beacon from an open network.
  \param[in] listSize size of the list behind pBeacon
  \param[in] mode The discovery mode. Can be used to blacklist or specify a network.
  \param[in] extendedPanId Extended pan id to join or to blacklist depending on the mode parameter.
  \param[in] filteringMode Beacon filtering mode - specifies the criterion for beacon handling.
  \param[in] pfBeaconReceivedCallback Pointer to the function that should be called on beacon reception.
  \param[in] pfDoneCallback Pointer to the function that should be called after the network discovery is done

  \return None
 ******************************************************************************/
void N_Cmi_NetworkDiscovery(uint32_t channelMask,
                            N_Beacon_Order_t durationPerChannel,
                            N_Beacon_t* pBeacon,
                            uint8_t listSize,
                            N_Connection_AssociateDiscoveryMode_t mode,
                            N_Address_ExtendedPanId_t* extendedPanId,
                            N_Cmi_BeaconFilteringCriterion_t filteringMode,
                            N_Cmi_BeaconIndication_t pfBeaconReceivedCallback,
                            N_Cmi_NetworkDiscoveryDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Perform a ZigBee network join (MAC association).
        
  \param[in] pSelectedBeacon The beacon from a device to join to.
  \param[in] method Method used to perform the association.
  \param[in] isSecured Whether the requested association type is secured or unsecured.
  \param[in] pfDoneCallback Pointer to the function that should be called after the join is done

  \return None
 ******************************************************************************/
void N_Cmi_Join(N_Beacon_t* pSelectedBeacon, NWK_JoinMethod_t method, bool isSecured, N_Cmi_JoinDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Perform a ZigBee network rejoin to find a new parent (end-device only).
        Note: This function is not implemented on a router
        
  \param[in] pSelectedBeacon The beacon from a device to rejoin to.
  \param[in] secure Whether to do a secure rejoin (TRUE) or an unsecure rejoin (FALSE, only possible with central trustcenter)
  \param[in] pfDoneCallback Pointer to the function that should be called after the rejoin is done

  \return None
 ******************************************************************************/
void N_Cmi_Rejoin(N_Beacon_t* pSelectedBeacon, bool secure, N_Cmi_JoinDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Perform a ZigBee network rejoin with the old parent (end-device only).
        Note: This function is not implemented on a router
        
  \param[in] pfDoneCallback Pointer to the function that should be called after the rejoin is done

  \return None
 ******************************************************************************/
void N_Cmi_RejoinParent(N_Cmi_JoinDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Perform a IEEE 802.15.4 orphan join to rejoin the old parent (end-device only).
        Note: This function is not implemented on a router
        
  \param[in] pfDoneCallback Pointer to the function that should be called after the rejoin is done

  \return None
 ******************************************************************************/

void N_Cmi_OrphanJoin(N_Cmi_JoinDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Update the network channel and network update id
        
  \param[in] channel The channel to change to.
  \param[in] networkUpdateId The network update id to update to.
  \param[in] pfDoneCallback Callback that is called after completion. Allowed to be NULL (no callback).

  \return None
 ******************************************************************************/

void N_Cmi_UpdateNetworkChannel(uint8_t channel, uint8_t networkUpdateId, N_Cmi_SetChannelDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Add an end device to the child table.
        Note: Calling this function for an end device is a fatal error.
  \param[in] ieeeAddressEndDevice The IEEE address of the end device to add to the child table
  \param[in] networkAddressEndDevice The network address of the end device to add to the child table

  \return None
 ******************************************************************************/
void N_Cmi_AddChild(N_Address_Extended_t ieeeAddressEndDevice, uint16_t networkAddressEndDevice);

/**************************************************************************//**
  \brief Set the parents short address

  \param[in] networkAddress Parents new short address

  \return None
 ******************************************************************************/
void N_Cmi_SetParentNetworkAddress(uint16_t networkAddress);

/**************************************************************************//**
  \brief Send a link status.

  \param[in] Delay the delay before sending the link status

  \return None
 ******************************************************************************/
void N_Cmi_SendLinkStatus(uint16_t delay);

/**************************************************************************//**
  \brief Retrieves the current network key.

  \param[out] networkKey The current network key

  \return None
 ******************************************************************************/

void N_Cmi_GetNetworkKey(N_Security_Key_t networkKey);

/**************************************************************************//**
  \brief Clear the network settings, thus setting the network layer back to factory defaults.

  \return None
 ******************************************************************************/
void N_Cmi_ResetNetworkSettings(void);

/**************************************************************************//**
  \brief Get the network params from the NIB.

  \param[in] pNetworkAddress The current network address
  \param[in] pPanId The current network pan id
  \param[in] pExtendedPanId The current network extended pan id
  \param[in] pNetworkUpdateId The current network update id
  \param[in] pNetworkChannel The current network channel
	
  \return None
 ******************************************************************************/

void N_Cmi_GetNetworkParams(uint16_t* pNetworkAddress, uint16_t* pPanId, N_Address_Extended_t* pExtendedPanId,
                            uint8_t* pNetworkUpdateId, uint8_t* pNetworkChannel);

/**************************************************************************//**
  \brief Get the parent network params from the NIB.

  \param[out] pParentNetworkAddress The current parent's network address
  \param[out] pParentExtendedAddress The current parent's network extended address

  \return None
 ******************************************************************************/
void N_Cmi_GetParentInfo(uint16_t* pParentNetworkAddress, N_Address_Extended_t* pParentExtendedAddress);

/**************************************************************************//**
  \brief Switch to the network key with the given sequence number

  \param[in] networkKeySequenceNumber The sequence number of the key to use

  \return None
 ******************************************************************************/
void N_Cmi_SwitchNetworkKey(uint8_t networkKeySequenceNumber);

/**************************************************************************//**
  \brief Set the network manager network address

  \param[in] networkManagerAddress New address for the network manager

  \return None
 ******************************************************************************/
void N_Cmi_SetNetworkManager(uint16_t networkManagerAddress);

/**************************************************************************//**
  \brief Retrieve the amount of network transmissions from the NIB

  \return None
 ******************************************************************************/
uint16_t N_Cmi_GetTotalTransmissions(void);

/**************************************************************************//**
  \brief Send a leave indication for device

  \param[in] rejoin Decides the device information need to be removed or not.
  \param[in] removeChildren remove the associated Childrens with the device or not.

  \return None
 ******************************************************************************/
void N_Cmi_SendLeaveIndication(bool rejoin, bool removeChildren);

/**************************************************************************//**
  \brief Send an UpdateDevice command.

  \param[in] ieeeAddr of the device whose status is being updated.
  \param[in] shortAddr of the device whose status is being updated.
  \param[in] status new status of the device.

  \return None
 ******************************************************************************/
void N_Cmi_SendUpdateDevice(uint8_t* ieeeAddr, uint16_t shortAddr, uint8_t status);

/**************************************************************************//**
  \brief Update the device security status to authenticated.

  \param[in] nwkAddr the network address of the device

  \return None
 ******************************************************************************/
void N_Cmi_AuthenticateChild(uint16_t nwkAddr);

/**************************************************************************//**
  \brief Send APS data. Wrapper for APS_DataReq with the parameter transmission option set as own broadcast transmissions. 

  \param[in] apsDataReq - APS data request pointer

  \return None
 ******************************************************************************/
void N_Cmi_DataRequest(APS_DataReq_t *apsDataReq);

/**************************************************************************//**
  \brief Send ZDP request.

  \param[in] zdpReq - ZDP data request pointer

  \return None
 ******************************************************************************/
void N_Cmi_ZdpRequest(ZDO_ZdpReq_t *zdpReq);

/**************************************************************************//**
  \brief Sets indirect poll rate for a given time interval; then restores the default poll rate.

  \param[in] rate - poll rate to be set
  \param[in] time - time interval for poll rate, ms

  \return None
 ******************************************************************************/
void N_Cmi_SetPollRateForTimePeriod(uint32_t rate, uint32_t time);

/**************************************************************************//**
  \brief Sets the type of groupcast to be used - NWK multicast or APS Groupcast.

  \param[in] multicast - if true NWK multicast will be used.

  \return None
 ******************************************************************************/
void N_Cmi_UseNwkMulticast(bool multicast);

/**************************************************************************//**
  \brief Marks ZLL preinstalled TC link key as a primary global key for a PAN

  \param[in] doneCallback Pointer to the function that should be called after the setting is done

  \return None
 ******************************************************************************/
void N_Cmi_SetZllLinkKeyAsPrimary(N_Cmi_SetZllLinkKeyAsPrimaryDone_t doneCallback);

/**************************************************************************//**
  \brief Marks ZHA preinstalled TC link key as a primary global key for a PAN

  \param[in] doneCallback Pointer to the function that should be called after the setting is done

  \return None
 ******************************************************************************/
void N_Cmi_SetZHALinkKeyAsPrimary(N_Cmi_SetZllLinkKeyAsPrimaryDone_t doneCallback);

/**************************************************************************//**
  \brief ZLL Platform to BitCloud addresses convertion

  \param[in] platformAddressing ZLL Platform addressing pointer
  \param[out] bcAddress BitCloud addressing pointer

  \return None
 ******************************************************************************/
void N_Cmi_PlatformToBcAddressingConvert(APS_Address_t *bcAddress, N_Address_t *platformAddressing);

/**************************************************************************//**
  \brief ZLL Platform to BitCloud address mode convertion

  \param[in] platformAddrMode ZLL Platform address mode
  \param[out] bcAddress BitCloud addressing pointer

  \return relative BitCloud address mode
 ******************************************************************************/
APS_AddrMode_t N_Cmi_PlatformToBcAddressModeConvert(N_Address_Mode_t platformAddrMode);

void IN_AfDataRequest_EnddeviceDataRequest(APS_DataReq_t *req);
void IN_AfDataRequest_RouterDataRequest(APS_DataReq_t *req); 

INLINE void IN_AfDataRequest_DataRequest(APS_DataReq_t *req)
{
	DeviceType_t deviceType;
	/* Read Device type from Config Server */
	CS_ReadParameter(CS_DEVICE_TYPE_ID, &deviceType);
#if defined (ZIGBEE_END_DEVICE)
	if (DEVICE_TYPE_END_DEVICE == deviceType)
	  IN_AfDataRequest_EnddeviceDataRequest(req);
#endif
#if defined (ZIGBEE_ROUTER) || defined (ZIGBEE_COORDINATOR)
    if ((DEVICE_TYPE_ROUTER == deviceType) || (DEVICE_TYPE_COORDINATOR == deviceType))
	  IN_AfDataRequest_RouterDataRequest(req);
#endif
}
/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_CMI_H

