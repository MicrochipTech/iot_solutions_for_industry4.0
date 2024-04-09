/*******************************************************************************
  ZLL Connection Internal Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Connection_Internal.h

  Summary:
    Create and maintain a connection with a ZigBee network, Platform internal interface.

  Description:
    \subsection Inter-PAN mode
    \par
    The component has a special mode for sending Inter-PAN messages. This
    mode is selected by the N_LinkInitiator and N_LinkTarget components to
    send/receive Inter-PAN messages.

    \par
    An end-device keeps the radio turned on in Inter-PAN mode, stops
    searching for a parent and stops polling its parent, so an end-device
    cannot send and receive normal ZigBee messages in Inter-PAN mode.

    \par
    A router does not do anything special in Inter-PAN mode, so a router can
    send and received in normal ZigBee messages in Inter-PAN mode.

    \par
    To make it possible to control the Inter-PAN mode from the two different
    components (N_LinkInitiator and N_LinkTarget), each component has its own
    set of functions:
    \ref N_Connection_SetInitiatorInterPanModeOn and
    \ref N_Connection_SetInitiatorInterPanModeOff for N_LinkInitiator,
    \ref N_Connection_SetTargetInterPanModeOn and
    \ref N_Connection_SetTargetInterPanModeOff for N_LinkTarget.

    \par
    When both N_LinkInitiator and N_LinkTarget request Inter-PAN mode,
    then the channel requested by N_LinkInitiator is used.
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


#ifndef N_CONNECTION_INTERNAL_H
#define N_CONNECTION_INTERNAL_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* INTERNAL CONSTANTS
***************************************************************************************************/

/** Time to wait for a network key after a AssociateResp before giving up. */
#define TIMEOUT_NETWORKKEYRECEIVED_MS 5000u

/** Maximum number of retries while associating. */
#define MAX_ASSOCIATE_RETRIES 3u

/** Maximum number of discovery retries. */
#define MAX_DISCOVERY_RETRIES 4u

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Try to find a parent ugently, e.g. after touchlinking (end-device only, no-op on a router).
        Call from N_LinkInitiator on Non-Factory-New devices, just before
        starting to send the dummy unicast messages.

  \return none
 ******************************************************************************/
void N_Connection_ReconnectUrgent(void);

/**************************************************************************//**
  \brief Try to find a parent ugently, e.g. after touchlinking (end-device only, no-op on a router).
         Call from N_LinkInitiator on Non-Factory-New devices, just before
         starting to send the dummy unicast messages.

  \return none
 ******************************************************************************/
void N_Connection_EnddeviceReconnectUrgent(void);

/**************************************************************************//**
  \brief  Try to find a parent ugently, e.g. after touchlinking (end-device only, no-op on a router).
         Call from N_LinkInitiator on Non-Factory-New devices, just before
         starting to send the dummy unicast messages.

  \return none
 ******************************************************************************/
void N_Connection_RouterReconnectUrgent(void);

/**************************************************************************//**
  \brief  Request to turn on Inter-PAN mode and set the communication channel from N_LinkInitiator (asynchronous call).
         An Inter-PAN channel must be selected before sending Inter-PAN messages,
         even if the selected channel is the same as the network channel. Do NOT
         call \ref N_Cmi_SetMacChannel directly from N_LinkInitiator, this function
         can be called to change the communication channel when the Inter-PAN mode
         is already on.

         After the component is done sending/receiving Inter-PAN messages
        \ref N_Connection_SetInitiatorInterPanModeOff must be called.

  \param channel The requested ZigBee channel
  \param pConfirmCallback Pointer to the function called when the request has been handled

  \return none
 ******************************************************************************/
void N_Connection_SetInitiatorInterPanModeOn(uint8_t channel, N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief  Request to leave Inter-PAN mode from N_LinkInitiator (asynchronous call).
         This function must be called is when the component is done sending Inter-PAN messages.

  \param pConfirmCallback Pointer to the function called the when request has been handled

  \return none
 ******************************************************************************/
void N_Connection_SetInitiatorInterPanModeOff(N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief  This is to check whether Setting Interpan mode is in progress

  \return TRUE if SetInterpanMode is in progress, FALSE - otherwise
 ******************************************************************************/
bool N_Connection_InitiatorIsSetInterPanModeInProgress(void);

/**************************************************************************//**
  \brief  Request to turn on Inter-PAN mode and set the communication channel from N_LinkTarget (asynchronous call). 
         An Inter-PAN channel must be selected before sending Inter-PAN messages,
         even if the selected channel is the same as the network channel. Do NOT
         call \ref N_Cmi_SetMacChannel directly from N_LinkTarget, this function
         can be called to change the communication channel when the Inter-PAN mode
         is already on.
		 After the component is done sending/receiving Inter-PAN messages
         \ref N_Connection_SetTargetInterPanModeOff must be called.

  \param channel The requested ZigBee channel
  \param pConfirmCallback Pointer to the function called when the request has been handled
	
  \return TRUE if SetInterpanMode is in progress, FALSE - otherwise
 ******************************************************************************/
void N_Connection_SetTargetInterPanModeOn(uint8_t channel, N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief  Request to leave Inter-PAN mode from N_LinkTarget (asynchronous call).
         This function must be called is when the component is done
         sending/receiving Inter-PAN messages.

  \param pConfirmCallback Pointer to the function called the when request has been handled
	
  \return TRUE if SetInterpanMode is in progress, FALSE - otherwise
 ******************************************************************************/
void N_Connection_SetTargetInterPanModeOff(N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief  Performs network discovery and channel change if the network
    which this device is assotiated with works on other channel.
    Actual only for router.

  \return None
 ******************************************************************************/
void N_Connection_SearchNetwork(void);

/**************************************************************************//**
  \brief  Performs network discovery and channel change if the network
    which this device is assotiated with works on other channel.
    Actual only for router.

  \return None
 ******************************************************************************/
void N_Connection_RouterSearchNetwork(void);

/**************************************************************************//**
  \brief  Performs network discovery and channel change if the network
    which this device is assotiated with works on other channel.
    Actual only for router.
	
  \return None
 ******************************************************************************/
void N_Connection_EnddeviceSearchNetwork(void);

/**************************************************************************//**
  \brief Performs leave network request.
	
  \return None
 ******************************************************************************/
void N_Connection_LeaveNetwork(void);

/**************************************************************************//**
  \brief Postpones setting interPan mode to ON state.
	
  \return None
 ******************************************************************************/
void N_Connection_PostponeInterPanMode(uint8_t channel, N_Connection_SetInterPanModeDone_t pConfirmCallback);

/**************************************************************************//**
  \brief change Target channel to macChannel
	
  \return None
 ******************************************************************************/
void N_Connection_SetTargetInterPanMacChannel(void);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_CONNECTION_INTERNAL_H
