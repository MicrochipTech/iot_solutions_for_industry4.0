/*******************************************************************************
  ZLL Connection Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Connection.h

  Summary:
    Create and maintain a connection with a ZigBee network.

  Description:
    \par
    There are two implementations of this interface: router and end-device.

    \subsection Router
    \par
    A router does not need any other device to join a network: just set the
    network parameters by calling \ref N_Connection_JoinNetwork.

    \subsection End-device
    \par
    An end-device needs a parent to be able to communicate with other devices
    in the network. This component provides the interface to find a parent after
    joining a network and find a new parent if the old one is no longer available.

    \par
    Joining a network with \ref N_Connection_JoinNetwork will trigger a search
    for a parent. A search for a new parent can be triggered by calling
    \ref N_Connection_Reconnect.
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


#ifndef N_CONNECTION_H
#define N_CONNECTION_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Address/include/N_Address.h"
#include "zllplatform/ZLL/N_Beacon/include/N_Beacon.h"
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

#define N_CONNECTION_NETWORK_CHANNEL        0u

#define EXTENDED_PANID_FILTER_MASK    (0x03u)
#define DISABLE_PERMITJOIN_FILTER     (1 << 2u)
#define DISABLE_CAPACITY_FILTER       (1 << 3u)
#define DISABLE_NETWORK_DEPTH_FILTER  (1 << 4u)
#define DISABLE_LQI_FILTER            (1 << 5u)

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

/** Result codes for the N_Connection actions. */
typedef enum N_Connection_Result_t
{
    N_Connection_Result_Success,
    N_Connection_Result_Failure,
    N_Connection_Result_Aborted,
    N_Connection_Result_NoNetworkKey,
    N_Connection_Invalid_Request,
} N_Connection_Result_t;

/** Possible Inter-PAN modes. */
typedef enum N_Connection_InterPanMode_t
{
    N_Connection_InterPanMode_Off,
    N_Connection_InterPanMode_On,
} N_Connection_InterPanMode_t;

/** Filters for associate discovery. */
typedef enum N_Connection_AssociateDiscoveryMode_t
{
    N_Connection_AssociateDiscoveryMode_AnyPan = 0x00u,
    N_Connection_AssociateDiscoveryMode_NotThisPan= 0x01u,
    N_Connection_AssociateDiscoveryMode_OnlyThisPan = 0x02u,
    N_Connection_AssociateDiscoveryMode_Disable_PermitJoin_Filter = 0x04u,
    N_Connection_AssociateDiscoveryMode_Disable_Capacity_Filter = 0x08u,
    N_Connection_AssociateDiscoveryMode_Disable_Network_Depth_Filter = 0x10u,
    N_Connection_AssociateDiscoveryMode_Disable_Lqi_Filter = 0x20u,
    N_Connection_AssociateDiscoveryMode_PrimaryChannelMask = 0x40u,
    N_Connection_AssociateDiscoveryMode_SecondaryChannelMask = 0x80u,
} N_Connection_AssociateDiscoveryMode_t;

/** Filter for the association type. */
typedef enum N_Connection_AssociateType_t
{
    N_Connection_AssociateType_Join,
    N_Connection_AssociateType_Rejoin,
    N_Connection_AssociateType_UnSecureRejoin,
} N_Connection_AssociateType_t;

/** Confirms that \ref N_Connection_JoinNetwork has completed.
    \param result Result of the action (Success or Failure)
*/
typedef void (*N_Connection_JoinNetworkDone_t)(N_Connection_Result_t result);

/** Confirms that \ref N_Connection_AssociateDiscovery has completed.
    \param result Result of the action (Success, Failure or Aborted)
*/
typedef void (*N_Connection_AssociateDiscoveryDone_t)(N_Connection_Result_t result);

/** Confirms that \ref N_Connection_AssociateJoin has completed.
    \param result Result of the action (Success, Failure or NoNetworkKey)

    \note The result NoNetworkKey is given if a devices joins via associate
          and did not receive a network key in time.
*/
typedef void (*N_Connection_AssociateJoinDone_t)(N_Connection_Result_t result);

/** Confirms that \ref N_Connection_UpdateNetwork has completed.
*/
typedef void (*N_Connection_UpdateNetworkDone_t)(void);

/** Confirms that \ref N_Connection_FindFreePan has completed and provides the result.
    \param panId The chosen PAN ID
    \param extendedPanId The chosen Extended PAN ID
*/
typedef void (*N_Connection_FindFreePanDone_t)(uint16_t panId, N_Address_ExtendedPanId_t extendedPanId);

/** Confirm callback type for the SetInterPanMode functions. */
typedef void (*N_Connection_SetInterPanModeDone_t)(void);

/** Callbacks of this component. */
typedef struct N_Connection_Callback_t
{
    /** Notification that the device has been (re)connected to the network.

        This is called in the following situations:

        1. A router is ready, just after the JoinNetworkDone callback.

        2. An end-device has a (re)connection to a parent.
    */
    void (*Connected)(void);

    /** Notification that the device has lost it connection to the network.

        The function is called in the following situations:

        1. A non-factory new device joins a new network, just before the
           new network settings are stored.

        2. An end-device has lost the connection with its parent (sync loss).

        \note This component will not automatically try to find a new parent
              on a disconnect. This auto-reconnect can be implemented in the
              application by calling the Reconnect function from the Disconnected
              callback.
    */
    void (*Disconnected)(void);

    /** Notification that the device has joined a (new) network.

        The function is called when the device has successfully joined the
        network, just after the JoinNetworkDone callback.
        On a router the Connected and NetworkJoined callbacks always come
        at the same time. On an end-device the Connected callback may come
        much later than the NetworkJoined callback.

        Use this callback to set-up the network settings that are reset by
        joining a network (e.g. default groups, default bindings).
    */
    void (*NetworkJoined)(void);

    /** Notification that the device needs to reset.

        The function is called after the device has received a leave request and is
        not allowed to rejoin again.
        The application should reset the device to factory defaults, because that's the only way to
        fully get out of the network.
    */
    void (*ResetToFactoryDefaults)(void);

    /** Notification that a device has associated with this device. 

        This callback is called when a child joins with this device.
    */
    void (*ChildAssociated)(uint16_t networkAddress, N_Address_Extended_t ieeeAddress);


    int8_t endOfList;
} N_Connection_Callback_t;

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

// Platform public interface (also used internally)
/**************************************************************************//**
  \brief Subscribe for events from this component.

  \return none
 ******************************************************************************/
void N_Connection_Subscribe(const N_Connection_Callback_t* pSubscriber);

/**************************************************************************//**
  \brief Subscribe for events from this component.

  \return none
 ******************************************************************************/
void N_Connection_EnddeviceSubscribe(const N_Connection_Callback_t* pSubscriber);

/**************************************************************************//**
  \brief Subscribe for events from this component.

  \return none
 ******************************************************************************/
void N_Connection_RouterSubscribe(const N_Connection_Callback_t* pSubscriber);

/**************************************************************************//**
  \brief Join a network. This is an asynchronous call: do not call any other function of this
    component until the callback is received.

  \param[in] extendedPanId Extended PAN ID of the network to join
  \param[in] channel Channel of the network to join
  \param[in] panId PAN ID of the network to join
  \param[in] networkAddress Network address of this device on the network to join
  \param[in] networkUpdateId Network update id of the network to join
  \param[in] pNetworkKey Network key to use (8 bytes); will be cleared when it has been used, or NULL to have a random one generated
  \param[in] pfDoneCallback Pointer to the function that will be called when the action is done

  \return none
 ******************************************************************************/
void N_Connection_JoinNetwork(N_Address_Extended_t extendedPanId,
                              uint8_t channel,
                              uint16_t panId,
                              uint16_t networkAddress,
                              uint8_t networkUpdateId,
                              uint8_t* pNetworkKey,
                              N_Connection_JoinNetworkDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Join a network. This is an asynchronous call: do not call any other function of this
    component until the callback is received.

  \param[in] extendedPanId Extended PAN ID of the network to join
  \param[in] channel Channel of the network to join
  \param[in] panId PAN ID of the network to join
  \param[in] networkAddress Network address of this device on the network to join
  \param[in] networkUpdateId Network update id of the network to join
  \param[in] pNetworkKey Network key to use (8 bytes); will be cleared when it has been used, or NULL to have a random one generated
  \param[in] pfDoneCallback Pointer to the function that will be called when the action is done

  \return none
 ******************************************************************************/
void N_Connection_EnddeviceJoinNetwork(N_Address_Extended_t extendedPanId,
                              uint8_t channel,
                              uint16_t panId,
                              uint16_t networkAddress,
                              uint8_t networkUpdateId,
                              uint8_t* pNetworkKey,
                              N_Connection_JoinNetworkDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Join a network. This is an asynchronous call: do not call any other function of this
    component until the callback is received.

  \param[in] extendedPanId Extended PAN ID of the network to join
  \param[in] channel Channel of the network to join
  \param[in] panId PAN ID of the network to join
  \param[in] networkAddress Network address of this device on the network to join
  \param[in] networkUpdateId Network update id of the network to join
  \param[in] pNetworkKey Network key to use (8 bytes); will be cleared when it has been used, or NULL to have a random one generated
  \param[in] pfDoneCallback Pointer to the function that will be called when the action is done

  \return none
 ******************************************************************************/
void N_Connection_RouterJoinNetwork(N_Address_Extended_t extendedPanId,
                              uint8_t channel,
                              uint16_t panId,
                              uint16_t networkAddress,
                              uint8_t networkUpdateId,
                              uint8_t* pNetworkKey,
                              N_Connection_JoinNetworkDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Find a beacon of an open ZigBee Pro network. This is an asynchronous call: do not call any other function of this
    component except for N_Connection_AbortAssociateDiscovery until the callback is received.

  \param[in] pBeacon Pointer to memory that is used to return a beacon from an open network.
  \param[in] mode The discovery mode. Can be used to blacklist or specify a network.
  \param[in] extendedPanId Extended pan id to join or to blacklist depending on the mode parameter.
  \param[in] pfDoneCallback Callback function pointer that is called upon completion. \see
           N_Connection_AssociateDiscoveryDone_t.

  \return none
 ******************************************************************************/
void N_Connection_AssociateDiscovery(N_Beacon_t* pBeacon, uint8_t networkDiscoveryFilteringMode, N_Address_ExtendedPanId_t* extendedPanId, N_Connection_AssociateDiscoveryDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Find a beacon of an open ZigBee Pro network. This is an asynchronous call: do not call any other function of this
    component except for N_Connection_AbortAssociateDiscovery until the callback is received.

  \param[in] pBeacon Pointer to memory that is used to return beacons from an open network.
  \param[in]listSize number of beacons that can be returned.
  \param[in] networkDiscoveryFilteringMode The discovery mode. Can be used to blacklist or specify a network.
  \param[in] extendedPanId Extended pan id to join or to blacklist depending on the mode parameter.
  \param[in] pfDoneCallback Callback function pointer that is called upon completion. \see
           N_Connection_AssociateDiscoveryDone_t.

  \return none
 ******************************************************************************/
void N_Connection_AssociateDiscoveryBeaconList(N_Beacon_t* pBeacon, uint8_t listSize, uint8_t networkDiscoveryFilteringMode, N_Address_ExtendedPanId_t* extendedPanId, N_Connection_AssociateDiscoveryDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Abort the discovery of open ZigBee Pro networks. This is an asynchronous call: do not call any other function of this
    component until the N_Connection_AssociateDiscoveryDone_t callback is received.

  \return none
 ******************************************************************************/
void N_Connection_EnddeviceAbortAssociateDiscovery(void);

/**************************************************************************//**
  \brief Abort the discovery of open ZigBee Pro networks.This is an asynchronous call: do not call any other function of this
    component until the N_Connection_AssociateDiscoveryDone_t callback is received.

  \return none
 ******************************************************************************/
void N_Connection_RouterAbortAssociateDiscovery(void);

/**************************************************************************//**
  \brief Associate with an open ZigBee Pro network. InterPan mode must not be enabled, 
        meaning that N_LinkTarget's target type must be set to None.

  \param[in] pBeacon Beacon of the device to associate with.
  \param[in] associationType Requested mode for association i.e. Join, Rejoin or Unsecure Rejoin.
  \param[in] pfDoneCallback Callback function pointer that is called upon completion. \see
           N_Connection_AssociateJoinDone_t.

  \return none
 ******************************************************************************/
void N_Connection_AssociateJoin(N_Beacon_t* pBeacon, N_Connection_AssociateType_t associationType, N_Connection_AssociateJoinDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Update network channel/update id. This is an asynchronous call: do not call any other function of this
    component until the callback is received.

  \param[in] networkChannel The new network channel
  \param[in] networkUpdateId The new network update id
  \param[in] pfDoneCallback Pointer to the function that will be called when the action is done

  \return none
 ******************************************************************************/
void N_Connection_UpdateNetwork(uint8_t networkChannel,
                                uint8_t networkUpdateId,
                                N_Connection_UpdateNetworkDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Check if the device has a connection to the network (end-device has a parent).

  \return TRUE if the device is a non-factory-new router, or if it has a parent
 ******************************************************************************/
bool N_Connection_IsConnected(void);

/**************************************************************************//**
  \brief Check if the device has a connection to the network (end-device has a parent).

  \return TRUE if the device is a non-factory-new router, or if it has a parent
 ******************************************************************************/
bool N_Connection_EnddeviceIsConnected(void);

/**************************************************************************//**
  \brief Check if the device has a connection to the network (end-device has a parent).

  \return TRUE if the device is a non-factory-new router, or if it has a parent
 ******************************************************************************/
bool N_Connection_RouterIsConnected(void);

/**************************************************************************//**
  \brief Try to find a parent (end-device only, no-op on a router).

  \return None
 ******************************************************************************/
void N_Connection_Reconnect(void);

/**************************************************************************//**
  \brief Try to find a parent (end-device only, no-op on a router).

  \return None
 ******************************************************************************/
void N_Connection_EnddeviceReconnect(void);

/**************************************************************************//**
  \brief Try to find a parent (end-device only, no-op on a router).

  \return None
 ******************************************************************************/
void N_Connection_RouterReconnect(void);

/**************************************************************************//**
  \brief Set the poll rate to be used when polling.Polling is an end-device-only feature. On routers, it is a dummy function.
    When the poll rate is never set, the default of 1000ms is used.

  \param pollIntervalMs The poll interval in milliseconds, or 0 to disable polling.

  \return None
 ******************************************************************************/
void N_Connection_SetPollRate(uint32_t pollIntervalMs);

/**************************************************************************//**
  \brief Force to use the application defined poll rate after joining a network.

    When an end-device is touchlinked, the pollrate is normally set to 300 milliseconds
    for a period of 5 seconds. This is to ensure that the end-device will receive the
    "communication check"-messages from the other device. The application is able
    to stop this fast polling mode by calling this function.
    In this case the application is responsible for the correct poll rate.

    Polling is an end-device-only feature. On routers, it is a dummy function.

  \return None
 ******************************************************************************/
void N_Connection_ForceNormalPolling(void);

/**************************************************************************//**
  \brief Finds a PAN ID and Extended PAN ID that is unique on all channels of the channel mask, in the RF proximity.
        This typically takes 240ms per channel in the mask. In extremely rare conditions, it can take longer.
        Only implemented on routers.

  \param pfDoneCallback Pointer to the function that will be called when the action is done

  \return None
 ******************************************************************************/
void N_Connection_FindFreePan(N_Connection_FindFreePanDone_t pfDoneCallback);
/**************************************************************************//**
  \brief Finds a PAN ID and Extended PAN ID that is unique on all channels of the channel mask, in the RF proximity.
        This typically takes 240ms per channel in the mask. In extremely rare conditions, it can take longer.
        Only implemented on routers.

  \param pfDoneCallback Pointer to the function that will be called when the action is done

  \return None
 ******************************************************************************/
void N_Connection_EnddeviceFindFreePan(N_Connection_FindFreePanDone_t pfDoneCallback);
/**************************************************************************//**
  \brief Finds a PAN ID and Extended PAN ID that is unique on all channels of the channel mask, in the RF proximity.
        This typically takes 240ms per channel in the mask. In extremely rare conditions, it can take longer.
        Only implemented on routers.

  \param pfDoneCallback Pointer to the function that will be called when the action is done

  \return None
 ******************************************************************************/
void N_Connection_RouterFindFreePan(N_Connection_FindFreePanDone_t pfDoneCallback);

/**************************************************************************//**
  \brief Request to turn on Inter-PAN mode (asynchronous call). After the application is done sending/receiving Inter-PAN messages
        \ref N_Connection_SetInterPanModeOff must be called.

  \param[in] channel The requested ZigBee channel
  \param[in] pConfirmCallback Pointer to the function called when the request has been handled
	
  \return None
 ******************************************************************************/
void N_Connection_SetInterPanModeOn(uint8_t channel, N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief Request to leave Inter-PAN mode (asynchronous call).This function must be called is when the application is done
    sending/receiving Inter-PAN messages.

  \param[in] pConfirmCallback Pointer to the function called the when request has been handled
	
  \return None
 ******************************************************************************/
void N_Connection_SetInterPanModeOff(N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief Send Network Leave Request.

  \param[in]rejoin Set to TRUE to indicate the device will rejoin immediately after leaving
  \param[in] removeChildren Set to TRUE to indicate also the children of this device are removed
	
  \return None
 ******************************************************************************/
void N_Connection_SendNetworkLeaveRequest(bool rejoin, bool removeChildren);

/**************************************************************************//**
  \brief Processes postponed setting interPan mode to ON state if required.
	
  \return None
 ******************************************************************************/
void N_Connection_ProcessPostponedInterPanMode(void);

/**************************************************************************//**
  \brief Returns the state of Update Network.
	
  \return None
 ******************************************************************************/
bool N_Connection_UpdateNetwork_IsBusy(void);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_CONNECTION_H
