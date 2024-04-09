/*******************************************************************************
  Commissioning Cluster header File

  Company:
    Microchip Technology Inc.

  File Name:
    ommissioningCluster.h

  Summary:
    This file contains Commissioning Cluster Implemenation.

  Description:
    This file contains Commissioning Cluster Implemenation.
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

#ifndef _COMMISSIONINGCLUSTER_H
#define _COMMISSIONINGCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclZllCommissioningCluster.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Fill the get group identifiers response command payload

\param[in] payload - pointer to response payload
\param[in] startIndex - start index

\return Size of the command payload
******************************************************************************/
uint8_t fillGetGroupIdentifiersResponsePayload(ZCL_GetGroupIdentifiersResponse_t *payload, uint8_t startIndex);

/**************************************************************************//**
\brief Fill the get endpoint list response command payload

\param[in] payload - pointer to response payload
\param[in] startIndex - start index

\return Size of the command payload
******************************************************************************/
uint8_t fillGetEndpointListResponsePayload(ZCL_GetEndpointListResponse_t *payload, uint8_t startIndex);

/**************************************************************************//**
\brief Send Endpoint Information command to target device.

\param[in] addr - dst address
\param[in] ep   - dst endpoint
******************************************************************************/
void commissioningSendEndpointInformation(ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
\brief Send Get Group Identifiers command to target device.

\param[in] addr       - dst address
\param[in] ep         - dst endpoint
\param[in] startIndex - start index of group ids
******************************************************************************/
void commissioningSendGetGroupIdentifiers(ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t startIndex);

/**************************************************************************//**
\brief Send Get Endpoint List command to target device.

\param[in] addr       - dst address
\param[in] ep         - dst endpoint
\param[in] startIndex - start index of endpoints
******************************************************************************/
void commissioningGetEndpointList(ShortAddr_t addr, Endpoint_t ep,  Endpoint_t srcEp, uint8_t startIndex);

#endif //_COMMISSIONINGCLUSTER_H