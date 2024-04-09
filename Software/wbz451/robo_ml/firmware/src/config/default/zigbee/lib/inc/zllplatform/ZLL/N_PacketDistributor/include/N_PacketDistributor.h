/*******************************************************************************
  ZLL Packet Distributor Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_PacketDistributor.h

  Summary:
    Header file used in PacketDistributor functionality to register End points 
    and get the information about the end points.

  Description:
    Header file used in PacketDistributor functionality to register End points 
    and get the information about the end points.
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


#ifndef N_PACKETDISTRIBUTOR_H
#define N_PACKETDISTRIBUTOR_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include <zllplatform/ZLL/N_PacketDistributor/include/N_ZllEndpoint.h>
#include <zllplatform/infrastructure/N_Types/include/N_Types.h>
#include <zllplatform/ZLL/N_Zcl_Framework/include/N_Zcl_DataInd.h>

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/


/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/
#define N_PacketDistributor_RegisterEndpoint N_PacketDistributor_RegisterEndpoint_Impl

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/
/**************************************************************************//**
  \brief Register a ZigBee end-point.
        Note: The groups count should include number of the groups that the endpoint uses as client of
        the ZCL groups cluster, NOT the number of groups used as server of the cluster: e.g. a
        remote control endpoint uses one group (groupCount == 1) to control some dimmable
        light endpoints (groupCount == 0).

  \param ZLL_Endpoint_t Pointer to a filled structure describing
        the end-point. The memory must stay available after the call to
        this function
  \param groupCount The number of groups used by the the endpoint (see the note below)

  \return None.
 *****************************************************************************/
void N_PacketDistributor_RegisterEndpoint(ZLL_Endpoint_t* zllEp, uint8_t groupCount);

/**************************************************************************//**
  \brief Returns the number of Zcl EndPoints (so excluding ZDO and InterPan endpoints)

  \return None.
 *****************************************************************************/
uint8_t N_PacketDistributor_GetNumberOfZclEndpoints(void);

/**************************************************************************//**
  \brief Returns the zcl endpoint number for an index (0..NumberOfZclEndpoints-1)

  \return None.
 *****************************************************************************/
uint8_t N_PacketDistributor_GetZclEndpointFromIndex(uint8_t index);

/**************************************************************************//**
  \brief Get the group count registered with \ref N_PacketDistributor_RegisterEndpoint.

  \param endpoint The endpoint number for which to get the group count

  \return The group count.
 *****************************************************************************/
uint8_t N_PacketDistributor_GetGroupCount(uint8_t endpoint);

/**************************************************************************//**
  \brief Get the sum of the group counts registered with \ref N_PacketDistributor_RegisterEndpoint for all endpoints.

  \return The total number of groups
 *****************************************************************************/
uint8_t N_PacketDistributor_GetTotalGroupCount(void);

/**************************************************************************//**
  \brief Returns the number of Zll EndPoints

  \return No of ZLL endpoints
 *****************************************************************************/
uint8_t N_PacketDistributor_GetNumberOfZllEndpoints(void);

/**************************************************************************//**
  \brief  Returns the zll endpoint number for an index (0..NumberOfZllEndpoints-1)

  \return No of ZLL endpoint index
 *****************************************************************************/
uint8_t N_PacketDistributor_GetZllEndpointFromIndex(uint8_t index);

/**************************************************************************//**
  \brief Get the sum of the group counts registered with \ref N_PacketDistributor_RegisterEndpoint for all endpoints.

  \return The total number of groups
 *****************************************************************************/
uint8_t N_PacketDistributor_GetTotalGroupCountZll(void);

/**************************************************************************//**
  \brief Find a registered endpoint.

  \param endpoint Endpoint number

  \return A pointer to the endpoint description or NULL if the endpoint could not be found.
          Do not free the memory
 *****************************************************************************/
#ifndef MICROCHIP_APPLICATION_SUPPORT
ZLL_Endpoint_t* N_PacketDistributor_FindEndpoint_Impl(uint8_t endpoint);
#else
APS_RegisterEndpointReq_t* N_PacketDistributor_FindEndpoint_Impl(uint8_t endpoint);
#endif

/**************************************************************************//**
  \brief Check if the received message is received Inter-PAN.

  \param panId The pan id from the source address
  \param endpoint The endpoint from the source address

  \return TRUE if it is an Inter-PAN message, FALSE otherwise
 *****************************************************************************/
bool N_PacketDistributor_IsInterPan(uint16_t panId, uint8_t endpoint);

/**************************************************************************//**
  \brief Subscribtion on PacketDistributor messages

  \param endpoint The endpoint to subscribe on messages
  \param pCallback Message handling routine pointe

  \return None
 *****************************************************************************/
void N_PacketDistributor_Subscribe(uint8_t endpoint, const N_Zcl_DataInd_Callback_t* pCallback);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_PACKETDISTRIBUTOR_H
