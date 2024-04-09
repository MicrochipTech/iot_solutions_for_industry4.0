/*******************************************************************************
  Zigbee Cluster Library Attributes Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclAttributes.h

  Summary:
    Header for implementation of state-independent attributes logic for ZCL.

  Description:
    This file contains implementation of state-independent attributes logic for ZCL.
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


#ifndef _ZCL_ATTRIBUTES_H
#define _ZCL_ATTRIBUTES_H

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>
/******************************************************************************
                           Definitions section
******************************************************************************/
#define ATTRIBUTE_ID_SIZE   (sizeof(ZCL_AttributeId_t))
#define ATTRIBUTE_TYPE_SIZE (sizeof(uint8_t))

/******************************************************************************
                                Types section
 ******************************************************************************/
 /*! \breif This structure is used by ZCL_ACTION_WRITE_ATTR_REQUEST action in BC_ZCL_EVENT_ACTION_REQUEST
    to inform the respective cluster about the write attribuite request*/
typedef struct _ZCLActionWriteAttrReq_t
{
  ClusterId_t clusterId;
  uint8_t clusterSide;
  ZCL_AttributeId_t attrId;
  uint8_t attrType;
  uint8_t *attrValue;
  ZCL_Status_t status;
}ZCLActionWriteAttrReq_t;

/*! \breif This structure is used by ZCL_ACTION_READ_ATTR_REQUEST action in BC_ZCL_EVENT_ACTION_REQUEST
    to inform the respective cluster about the read attribuite request*/
typedef struct _ZCLActionReadAttrReq_t
{
  Endpoint_t endpointId;
  ClusterId_t clusterId;
  uint8_t clusterSide;
  ZCL_AttributeId_t attrId;
  uint8_t attrType;
  uint16_t attrLength;
  uint8_t lengthField;
  uint8_t *attrValue;
}ZCLActionReadAttrReq_t;

/******************************************************************************
                           Functions prototypes section
******************************************************************************/

/*************************************************************************//**
  \brief Finds command descriptor by cluster, direction and command id.

  \param[in] cluster   - pointer to cluster.
  \param[in] direction - command direction (client or server).
  \param[in] commandId - command unique identifier.
  \return command descriptor if found, NULL otherwise.
*****************************************************************************/
ZclCommand_t * zclGetCommandByCluster(ZCL_Cluster_t *cluster, uint8_t direction, ZCL_CommandId_t commandId);

/*************************************************************************//**
  \brief Finds command descriptor by endpoint id, cluster id and command id.

  \param[in] endpointId - endpoint number.
  \param[in] clusterId - cluster unique identifier.
  \param[in] directionMspMask - command direction (client or server) as well as msp specific cluster.
  \param[in] commandId - command unique identifier.
  \return command descriptor if found, NULL otherwise.
*****************************************************************************/
ZclCommand_t * zclGetCommand(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t directionMspMask, ZCL_CommandId_t commandId);

/*************************************************************************//**
  \brief Finds attribute descriptor by endpoint id, cluster id , cluster side
         and attribute id.

  \param[in] endpointId - endpoint unique identifier.
  \param[in] clusterId - cluster unique identifier.
  \param[in] clusterSideMspMask - cluster side (client or server) as well as msp specific cluster
  \param[in] attributeId - attribute unique identifier.
  \return attribute descriptor if found, NULL otherwise.
*****************************************************************************/
ZclAttribute_t * zclGetAttribute(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t clusterSideMspMask, ZCL_AttributeId_t attributeId);

/**************************************************************************//**
\brief Safe version of ZCL_ReadAttributeValue without caller buffer overflow

\param[in] endpointId - endpoint of attribute to be read
\param[in] clusterId - cluster of attribute to be read
\param[in] clusterSideMspMask - client or server side as well as msp specific cluster
\param[in] attrId - attribute identifier
\param[out] attrType - attribute type
\param[out] attrValue - buffer to read attribute value
\param[in] maxSize - maximum size of buffer
\return status of operation
******************************************************************************/
ZCL_Status_t zclReadAttributeValueSafe(Endpoint_t endpointId,
                                       ClusterId_t clusterId,
                                       uint8_t clusterSideMspMask,
                                       ZCL_AttributeId_t attrId,
                                       uint8_t *attrType,
                                       uint8_t *attrValue,
                                       uint16_t maxSize);

#ifdef _ZCL_REPORTING_SUPPORT_
/*************************************************************************//**
  \brief Checks whether attribute is configured for reporting.

  \param[in] pAttr - pointer to attribute.

  \return true if reporting is permitted, false otherwise.
*****************************************************************************/
bool isReportingPermitted(const ZclAttribute_t *pAttr);

/*************************************************************************//**
  \brief Checks whether attribute is configured to stop reporting.

  \param[in] pAttr - pointer to attribute.

  \return true if reporting is permitted, false otherwise.
*****************************************************************************/
bool isReportingStopped(const ZclAttribute_t *pAttr);

/**************************************************************************//**
\brief Read indexed (structured) attribute from array

\param[in,out] selector - pointer to pointer to index selector
\param[in] endpointId - endpoint of attribute to be read
\param[in] clusterId - cluster of attribute to be read
\param[in] clusterSideMspMask - client or server side as well as msp specific cluster
\param[in] attrId - attribute identifier
\param[out] attrType - attribute type
\param[out] attrValue - buffer to read attribute value
\param[in] maxSize - maximum size of buffer
\return status of operation
******************************************************************************/
ZCL_Status_t zclReadIndexedAttribute(const ZCL_Selector_t *selector,
                                     Endpoint_t endpointId,
                                     ClusterId_t clusterId,
                                     uint8_t clusterSideMspMask,
                                     ZCL_AttributeId_t attrId,
                                     uint8_t *attrType,
                                     uint8_t *attrValue,
                                     uint16_t maxSize);
#endif // _ZCL_REPORTING_SUPPORT_

/**************************************************************************//**
\brief Jumps to the next attribute

\param[in] attr - current attribute
\return next attribute
******************************************************************************/
ZclAttribute_t *jumpToNextAttribute(ZclAttribute_t *attr);


/**************************************************************************//**
\brief Get Next command

\param[in] command - current command
\return next command
******************************************************************************/

ZclCommand_t * zclGetNextCommand(ZclCommand_t *command);

/*************************************************************************//**
  \brief Finds cluster by endpoint id and cluster id.

  \param[in] endpointId - endpoint number.
  \param[in] clusterId - cluster unique identifier.
  \param[in] direction - command direction (client or server).
  \return cluster descriptor if found, NULL otherwise.
*****************************************************************************/
ZCL_Cluster_t * zclGetCcluster(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t directionMspMask);

#endif // _ZCL_ATTRIBUTES_H
//eof zclAttributes.h
