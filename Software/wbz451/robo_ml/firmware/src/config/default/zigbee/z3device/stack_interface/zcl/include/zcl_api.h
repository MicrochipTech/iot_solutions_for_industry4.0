/*******************************************************************************
 Zigbee ZCL APIs Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zcl_api.h

  Summary:
    This file contains the Zigbee cluster library Api's for this project.

  Description:
    This file contains the packing Zigbee cluster library requests and send them to zigbee stack through SVC
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

#ifndef ZCL_API_H
#define ZCL_API_H
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <zcl/include/zcl.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/
#ifdef _PIC32CX_
#define ZCL_CommandManagerInit        ZB_ZCL_CommandManagerInit
#define ZCL_RegisterEndpoint          ZB_ZCL_RegisterEndpoint
#define ZCL_UnregisterEndpoint        ZB_ZCL_UnregisterEndpoint
#define ZCL_StartReporting            ZB_ZCL_StartReporting
#define ZCL_GetCluster                ZB_ZCL_GetCluster
#define ZCL_ResetReq                  ZB_ZCL_ResetReq
#define ZCL_ReadAttributeValue        ZB_ZCL_ReadAttributeValue
#define ZCL_WriteAttributeValue       ZB_ZCL_WriteAttributeValue
#define ZCL_GetNextCluster            ZB_ZCL_GetNextCluster
#define ZCL_GetNextElement            ZB_ZCL_GetNextElement
#define ZCL_PutNextElement            ZB_ZCL_PutNextElement
#define ZCL_GetAttributeLength        ZB_ZCL_GetAttributeLength
#define ZCL_IsBusy                    ZB_ZCL_IsBusy
#define ZCL_CommandReq                ZB_ZCL_CommandReq
#define ZCL_AttributeReq              ZB_ZCL_AttributeReq
#define ZCL_ReportOnChangeIfNeeded    ZB_ZCL_ReportOnChangeIfNeeded
#define ZCL_GetNextSeqNumber          ZB_ZCL_GetNextSeqNumber
#define ZCL_SetReportableChange       ZB_ZCL_SetReportableChange
#endif
/*******************************************************************************
                    Global variables section
*******************************************************************************/
#define ZCL_CLUSTER_COMMAND_IND  0
#define ZCL_REPORT_IND           1
#define ZCL_DEFAULT_RESP_IND     2
#define ZCL_ATTRIBUTE_EVENT_IND  3
#define ZCL_NOTIFY_RESP_IND      4

/**************************************************************************//**
\brief ZCL_CommandManagerInit pack function
\param[in] req - request
******************************************************************************/
void ZB_ZCL_CommandManagerInit(void);
/**************************************************************************//**
\brief ZCL_RegisterEndpoint pack function
\param[in] endpoint - contains device descriptor
******************************************************************************/
void ZB_ZCL_RegisterEndpoint(ZCL_DeviceEndpoint_t *endpoint);

/**************************************************************************//**
\brief ZCL_UnregisterEndpoint pack function
\param[in] endpoint - contains device descriptor
******************************************************************************/
void ZB_ZCL_UnregisterEndpoint(ZCL_DeviceEndpoint_t *endpoint);

/**************************************************************************//**
\brief ZCL_StartReporting pack function
\param[in] void
******************************************************************************/
void ZB_ZCL_StartReporting(void);

/**************************************************************************//**
\brief ZCL_GetCluster pack function
\param[in] endpointId - endpoint unique identifier.
\param[in] clusterId - cluster unique identifier.
\param[in] clusterSide - cluster side (client or server).
\return ZCL cluster descriptor if found, NULL otherwise.
******************************************************************************/
ZCL_Cluster_t *ZB_ZCL_GetCluster(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t clusterSide);

/*************************************************************************//**
\brief Resets the ZCL component
\ingroup zcl_common
\param[in] none
*****************************************************************************/
void ZB_ZCL_ResetReq(void);


/*************************************************************************//**
 \brief ZCL_ReadAttributeValue pack functin

 \param[in] endpointId - endpoint on which cluster is registered
 \param[in] clusterId - cluster unique identifier
 \param[in] clusterSide - detects the cluster's side (client or server)
 \param[in] attrId - attribute unique identifier
 \param[out] attrType - pointer to attribute type determined and returned
 \param[out] attrValue - read out attribute value pointer 

 \return The status of the operation:  \n
   ::ZCL_SUCCESS_STATUS (0x00) - attribute value has been obtained successfully \n
   ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is
     not supported
*****************************************************************************/
ZCL_Status_t ZB_ZCL_ReadAttributeValue(Endpoint_t endpointId,
                                       ClusterId_t clusterId,
                                       uint8_t clusterSide,
                                       ZCL_AttributeId_t attrId,
 				                       uint8_t *attrType,
			       	                   uint8_t *attrValue);
									   

/*************************************************************************//**
 \brief ZCL_WriteAttributeValue pack function

 \param[in] endpointId - endpoint on which cluster is registered
 \param[in] clusterId - cluster unique identifier
 \param[in] clusterSide - detects the cluster's side (client or server)
 \param[in] attrId - attribute unique identifier
 \param[in] attrType - type of the attribute to be set
 \param[in] attrValue - pointer to attribute value to be set
 \return The status of the operation: \n
    ::ZCL_SUCCESS_STATUS (0x00) - new value has been written successfully \n
    ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is not supported \n
    ::ZCL_INVALID_PARAMETER_STATUS (0xFF) - NULL has been provided as the attribute's value \n
    ::ZCL_INVALID_DATA_TYPE_STATUS (0x8D) - the attribute's type is not the same as specified
      in the argument \n
    ::ZCL_READ_ONLY_STATUS (0x88) - the attribute's value cannot be changed,
      because the attribute is read-only
*****************************************************************************/
ZCL_Status_t ZB_ZCL_WriteAttributeValue(Endpoint_t endpointId, ClusterId_t clusterId,
                                         uint8_t clusterSide, ZCL_AttributeId_t attrId, 
					 uint8_t attrType, uint8_t *attrValue);

/*************************************************************************//**
 \brief ZCL_GetNextCluster pack API

 \param[in] cluster - pointer to current cluster descriptor.
 \return poiter to next cluster descriptor.
*****************************************************************************/
ZCL_Cluster_t *ZB_ZCL_GetNextCluster(ZCL_Cluster_t *cluster);

/*************************************************************************//**
 \brief ZCL_GetNextElement pack function
 \param[in] element - information about payload and element
 \param[out] status of the operation:
     ::ZCL_SUCCESS_STATUS - an element has been read successfully, more elements
       are contained in the payload \n
     ::ZCL_END_PAYLOAD_REACHED_STATUS (0xFD) - an element has been read successfully and no
       more elements are left in the payload \n
     ::ZCL_INVALID_PARAMETER_STATUS (0xFF) - the argument is NULL
*****************************************************************************/
ZCL_Status_t ZB_ZCL_GetNextElement(ZCL_NextElement_t *element);

/*************************************************************************//**
 \brief ZCL_PutNextElement pack function

 \param[in] element - information about payload and element
 \param[out] status of the operation:
     ::ZCL_SUCCESS_STATUS (0x00) - an element has been written to the payload successfully,
       more elements can be added \n
     ::ZCL_END_PAYLOAD_REACHED_STATUS (0xFD) - an element has been written successfully, and
       the payload is full - no more elements can be added \n
     ::ZCL_INVALID_PARAMETER_STATUS (0xFF) - the argument is NULL
*****************************************************************************/
ZCL_Status_t ZB_ZCL_PutNextElement(ZCL_NextElement_t *element);

/*************************************************************************//**
 \brief ZB_ZCL_GetAttributeLength pack function
 \param[in] typeId - type's ID
 \param[in] value - pointer to variable of typeId, NULL means
            the maximum possible size
*****************************************************************************/
uint16_t ZB_ZCL_GetAttributeLength(uint8_t typeId, const uint8_t *value);					 

/***************************************************************************//**
\brief ZCL_IsBusy pack function
\ingroup zcl_otau
\return true - if ZCL is busy, false - otherwise
******************************************************************************/
bool ZB_ZCL_IsBusy(void);

/*********************************************************************************//**
 \brief ZCL_CommandReq Pack function

 \param[in] req - contains request descriptor
************************************************************************************/
void ZB_ZCL_CommandReq(ZCL_Request_t *req);

/*************************************************************************//**
 \brief Sends a general ZCL command related to attributes to a remote device

 \param[in] req - contains request descriptor
*****************************************************************************/
void ZB_ZCL_AttributeReq(ZCL_Request_t *req);

/*************************************************************************//**
 \brief Reports attribute if report on change is enabled and all
   conditions to report are met.
 \param[in] attr - pointer to attribute

 \return The status of the operation: \n
    ::ZCL_SUCCESS_STATUS (0x00) - new value has been written successfully \n
    ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is not supported
*****************************************************************************/
ZCL_Status_t ZB_ZCL_ReportOnChangeIfNeeded(void *req);

/***************************************************************************//**
\brief ZCL_GetNextSeqNumber pack function

\return offset.
******************************************************************************/
uint8_t ZB_ZCL_GetNextSeqNumber(void);

/*************************************************************************//**
 \brief ZCL_SetReportableChange pack function

 \param[in] endpointId - endpoint on which cluster is registered
 \param[in] clusterId - cluster unique identifier
 \param[in] clusterSide - determs the cluster's side (client or server)
 \param[in] attrId - attribute unique identifier
 \param[in] attrType - type of the attribute to be set
 \param[in] repChange - pointer to reportable change value to be set

 \return status of operation.
*****************************************************************************/
ZCL_Status_t ZB_ZCL_SetReportableChange(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t clusterSide,
                                     ZCL_AttributeId_t attrId, uint8_t attrType, uint8_t *repChange);

/**************************************************************************//**
\brief Application callBack function for ZCL

\param[in] Callback Pointer
******************************************************************************/
void ZB_ZCL_CallBack(ZB_AppGenericCallbackParam_t* cb);

#endif // ZCL_API_H
