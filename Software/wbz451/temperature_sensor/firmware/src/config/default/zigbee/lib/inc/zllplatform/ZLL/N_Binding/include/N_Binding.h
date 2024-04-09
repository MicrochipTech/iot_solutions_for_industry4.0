/*******************************************************************************
  ZLL Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Binding.h

  Summary:
    This file contains the ZLL Bindings functions.

  Description:
    This file contains the ZLL Bindings functions.
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


#ifndef N_BINDING_H
#define N_BINDING_H

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
* EXPORTED TYPES
***************************************************************************************************/
typedef struct N_Binding_Record_t
{
    uint8_t sourceEndpoint;
    N_Address_t destinationAddress;
    uint16_t clusterId;
} N_Binding_Record_t;

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/

#define INVALID_BINDING_RECORD_INDEX 0xFFu

/***************************************************************************************************
* EXPORTED VARIABLES
***************************************************************************************************/
extern N_Address_t g_N_Binding_Address;


/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Add an entry to the binding table

  \param[in] sourceEndpoint The source endpoint
  \param[in] pDestinationAddress The destination address
  \param[in] numClusterIds The number of ClusterIds
  \param[in] pClusterIds Array of clusterIds

  \return None
 ******************************************************************************/
void N_Binding_AddBinding( uint8_t sourceEndpoint,
                           const N_Address_t *pDestinationAddress,
                           uint8_t numClusterIds,
                           uint16_t *pClusterIds );

/**************************************************************************//**
  \brief Add an entry to the binding table

  \param[in] sourceEndpoint The source endpoint
  \param[in] pDestinationAddress The destination address
  \param[in] numClusterIds The number of ClusterIds
  \param[in] pClusterIds Array of clusterIds

  \return TRUE if operation succeeded, FALSE otherwise
 ******************************************************************************/
bool N_Binding_AddBindingExt( uint8_t sourceEndpoint,
                              const N_Address_t* pDestinationAddress,
                              uint8_t numClusterIds,
                              uint16_t *pClusterIds );

/**************************************************************************//**
  \brief Remove a binding from the binding table

  \param[in] sourceEndpoint The source endpoint
  \param[in] pDestinationAddress The destination address
  \param[in] clusterId the clusterId

  \return TRUE if operation succeeded, FALSE otherwise
 ******************************************************************************/
bool N_Binding_RemoveBinding( uint8_t sourceEndpoint,
                              const N_Address_t* pDestinationAddress,
                              uint16_t clusterId );

/**************************************************************************//**
  \brief Remove all bindings for an endpoint

  \param[in] endpoint Endpoint to remove, 0xFF is all endpoints

  \return None
 ******************************************************************************/
void N_Binding_RemoveBindings(uint8_t endpoint);

/**************************************************************************//**
  \brief Find an entry to the binding table

  \param[in] sourceEndpoint The source endpoint
  \param[in] clusterId The concerning clusterId
  \param[in] skip The number of bindings to skip. '0' returns the index to the first binding record
                with sourceEndpoint and clusterId, '1' the second, etc.

  \return the index of the binding record, returns INVALID_BINDING_RECORD_INDEX if no such
             binding exist
 ******************************************************************************/
uint8_t N_Binding_FindBinding( uint8_t sourceEndpoint,
                             uint16_t clusterId,
                             uint8_t skip );

/**************************************************************************//**
  \brief Get the number of binding table records

  \return the number of binding table records
 ******************************************************************************/
uint8_t N_Binding_GetNumberOfBindingRecords(void);

/**************************************************************************//**
  \brief Get the binding table records specified by the index

  \param index Index of the binding record to retrieve
        \param[out] pRecord The binding table record
	
  \return None
 ******************************************************************************/
void N_Binding_GetBindingRecord(uint8_t index, N_Binding_Record_t *pRecord);

/**************************************************************************//**
  \brief Remove a binding record

  \param index Index of the binding to remove
	
  \return None
 ******************************************************************************/
void N_Binding_RemoveBindingRecord(uint8_t index);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_BINDING_H
