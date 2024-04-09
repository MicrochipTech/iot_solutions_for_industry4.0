/*******************************************************************************
 Zigbee ZCL APIs source File

  Company:
    Microchip Technology Inc.

  File Name:
    zcl_api.c

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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <framework_defs.h>
#include <z3device/stack_interface/zgb_api.h>
#include <zcl/include/zcl.h>
#include <z3device/stack_interface/zcl/include/ZCL_Unpack.h>
#include <z3device/stack_interface/zcl/include/zcl_api.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/
static Stack_API_Request_t apiRequest;
/*******************************************************************************
                    Implementation section
*******************************************************************************/
/**************************************************************************//**
\brief ZCL_CommandManagerInit pack function
\param[in] req - request
******************************************************************************/
void ZB_ZCL_CommandManagerInit(void)
{
  apiRequest.unpack_fn = (unpack_ptr)ZCL_CommandManagerInit_Unpack;
  apiRequest.parameters = NULL;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZCL_RegisterEndpoint pack function
\param[in] endpoint - contains device descriptor
******************************************************************************/
void ZB_ZCL_RegisterEndpoint(ZCL_DeviceEndpoint_t *endpoint)
{
  apiRequest.unpack_fn = (unpack_ptr)ZCL_RegisterEndpoint_Unpack;
  apiRequest.parameters = endpoint;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZCL_UnregisterEndpoint pack function
\param[in] endpoint - contains device descriptor
******************************************************************************/
void ZB_ZCL_UnregisterEndpoint(ZCL_DeviceEndpoint_t *endpoint)
{  
  apiRequest.unpack_fn = (unpack_ptr)ZCL_UnregisterEndpoint_Unpack;
  apiRequest.parameters = endpoint;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZCL_StartReporting pack function
\param[in] void
******************************************************************************/
void ZB_ZCL_StartReporting(void)
{
  apiRequest.unpack_fn = (unpack_ptr)ZCL_StartReporting_Unpack;
  apiRequest.parameters = NULL;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief ZCL_GetCluster pack function
\param[in] endpointId - endpoint unique identifier.
\param[in] clusterId - cluster unique identifier.
\param[in] clusterSide - cluster side (client or server).
\return ZCL cluster descriptor if found, NULL otherwise.
******************************************************************************/
ZCL_Cluster_t *ZB_ZCL_GetCluster(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t clusterSide)
{
  ZCL_GetCluster_t zclGetCluster;
  zclGetCluster.clusterId = clusterId;
  zclGetCluster.endpointId = endpointId;
  zclGetCluster.clusterSide = clusterSide;
  
  apiRequest.unpack_fn = (unpack_ptr)ZCL_GetCluster_Unpack;
  apiRequest.parameters = &zclGetCluster;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclGetCluster.zclCluster;
}

/*************************************************************************//**
\brief Resets the ZCL component
\ingroup zcl_common
\param[in] none
*****************************************************************************/
void ZB_ZCL_ResetReq(void)
{
  apiRequest.unpack_fn = (unpack_ptr)ZCL_ResetReq_Unpack;
  apiRequest.parameters = NULL;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

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
			       	       uint8_t *attrValue)
{
  ZCL_ReadAttribute_t zclReadAttribute;
  zclReadAttribute.endpointId = endpointId;
  zclReadAttribute.clusterId = clusterId;
  zclReadAttribute.clusterSide = clusterSide;
  zclReadAttribute.attrId = attrId;
  zclReadAttribute.attrType = attrType;
  zclReadAttribute.attrValue = attrValue;
  
  apiRequest.unpack_fn = (unpack_ptr)ZCL_ReadAttributeValue_Unpack;
  apiRequest.parameters = &zclReadAttribute;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclReadAttribute.zclStatus;
}

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
					 uint8_t attrType, uint8_t *attrValue)
{
  ZCL_WriteAttribute_t zclWriteAttribute;
  zclWriteAttribute.endpointId = endpointId;
  zclWriteAttribute.clusterId = clusterId;
  zclWriteAttribute.clusterSide = clusterSide;
  zclWriteAttribute.attrId = attrId;
  zclWriteAttribute.attrType = attrType;
  zclWriteAttribute.attrValue = attrValue;

  apiRequest.unpack_fn = (unpack_ptr)ZCL_WriteAttributeValue_Unpack;
  apiRequest.parameters = &zclWriteAttribute;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclWriteAttribute.zclStatus;
}

/*************************************************************************//**
 \brief ZCL_GetNextCluster pack API

 \param[in] cluster - pointer to current cluster descriptor.
 \return poiter to next cluster descriptor.
*****************************************************************************/
ZCL_Cluster_t *ZB_ZCL_GetNextCluster(ZCL_Cluster_t *cluster)
{
  ZCL_GetNextCluster_t  zclGetNextCluster;
  zclGetNextCluster.inputCluster = cluster;

  apiRequest.unpack_fn = (unpack_ptr)ZCL_GetNextCluster_Unpack;
  apiRequest.parameters = &zclGetNextCluster;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclGetNextCluster.nextCluster;
}

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
ZCL_Status_t ZB_ZCL_GetNextElement(ZCL_NextElement_t *element)
{
  ZCL_GetPutNextElement_t zclGetNextElement;
  zclGetNextElement.nextElement = element;

  apiRequest.unpack_fn = (unpack_ptr)ZCL_GetNextElement_Unpack;
  apiRequest.parameters = &zclGetNextElement;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclGetNextElement.zclStatus;
}

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
ZCL_Status_t ZB_ZCL_PutNextElement(ZCL_NextElement_t *element)
{
  ZCL_GetPutNextElement_t zclPutGetNextElement;
  zclPutGetNextElement.nextElement = element;

  apiRequest.unpack_fn = (unpack_ptr)ZCL_PutNextElement_Unpack;
  apiRequest.parameters = &zclPutGetNextElement;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclPutGetNextElement.zclStatus;
}

/*************************************************************************//**
 \brief ZB_ZCL_GetAttributeLength pack function
 \param[in] typeId - type's ID
 \param[in] value - pointer to variable of typeId, NULL means
            the maximum possible size
*****************************************************************************/
uint16_t ZB_ZCL_GetAttributeLength(uint8_t typeId, const uint8_t *value)
{
  ZCL_GetAttributeLength_t zclGetAttrLen;
  zclGetAttrLen.typeId = typeId;
  zclGetAttrLen.value = value;

  apiRequest.unpack_fn = (unpack_ptr)ZCL_GetAttributeLength_Unpack;
  apiRequest.parameters = &zclGetAttrLen;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclGetAttrLen.attrLen;
}

/***************************************************************************//**
\brief ZCL_IsBusy pack function
\ingroup zcl_otau
\return true - if ZCL is busy, false - otherwise
******************************************************************************/
bool ZB_ZCL_IsBusy(void)
{
  bool isOtauBusy = false;
  apiRequest.unpack_fn = (unpack_ptr)ZCL_IsBusy_Unpack;
  apiRequest.parameters = &isOtauBusy;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return isOtauBusy;
}

/*********************************************************************************//**
 \brief ZCL_CommandReq Pack function

 \param[in] req - contains request descriptor
************************************************************************************/
void ZB_ZCL_CommandReq(ZCL_Request_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)ZCL_CommandReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/*************************************************************************//**
 \brief Sends a general ZCL command related to attributes to a remote device

 \param[in] req - contains request descriptor
*****************************************************************************/
void ZB_ZCL_AttributeReq(ZCL_Request_t *req)
{
  apiRequest.unpack_fn = (unpack_ptr)ZCL_AttributeReq_Unpack;
  apiRequest.parameters = req;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/*************************************************************************//**
 \brief Reports attribute if report on change is enabled and all
   conditions to report are met.
 \param[in] attr - pointer to attribute

 \return The status of the operation: \n
    ::ZCL_SUCCESS_STATUS (0x00) - new value has been written successfully \n
    ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is not supported
*****************************************************************************/
ZCL_Status_t ZB_ZCL_ReportOnChangeIfNeeded(void *req)
{
  ZCL_ReportOnChangeIfNeeded_t zclReportOnchange;
  zclReportOnchange.attr = req;

  apiRequest.unpack_fn = (unpack_ptr)ZCL_ReportOnChangeIfNeeded_Unpack;
  apiRequest.parameters = &zclReportOnchange;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclReportOnchange.zclStatus;
}

/***************************************************************************//**
\brief ZCL_GetNextSeqNumber pack function

\return offset.
******************************************************************************/
uint8_t ZB_ZCL_GetNextSeqNumber(void)
{
  uint8_t zclNextSeqNo;
  apiRequest.unpack_fn = (unpack_ptr)ZCL_GetNextSeqNumber_Unpack;
  apiRequest.parameters = &zclNextSeqNo;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zclNextSeqNo;
}

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
                                     ZCL_AttributeId_t attrId, uint8_t attrType, uint8_t *repChange)
{
  ZCL_SetReportableChange_t zcSetReportableChange;
  zcSetReportableChange.endpointId = endpointId;
  zcSetReportableChange.clusterId = clusterId;
  zcSetReportableChange.clusterSide = clusterSide;
  zcSetReportableChange.attrId = attrId;
  zcSetReportableChange.attrType = attrType;
  zcSetReportableChange.repChange = repChange;
  
  apiRequest.unpack_fn = (unpack_ptr)ZCL_SetReportableChange_Unpack;
  apiRequest.parameters = &zcSetReportableChange;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zcSetReportableChange.zclStatus;
}

/**************************************************************************//**
\brief ZCL command callbacks
       All ZCL command are called via this call back from stack to app. 
       Based on the application subscription corresponding call back is called.

\param[in] cb - callback paramters structure with moduleId, callback Id & callback params 
******************************************************************************/
void ZB_ZCL_CallBack(ZB_AppGenericCallbackParam_t* cb)
{
  ZB_AppGenericCallbackParam_t *cbParam = (ZB_AppGenericCallbackParam_t *)cb;
  
  switch(cbParam->uCallBackID)
  {
    case ZCL_CLUSTER_COMMAND_IND:
    {
      void **paramPtr = cbParam->parameters;
      
      ZCL_CommandInd_t *zclCmdIndCallback = (ZCL_CommandInd_t *)(*paramPtr);
  
      zclCmdIndCallback->status = zclCmdIndCallback->callbackFn(zclCmdIndCallback->addressing,
                                                                zclCmdIndCallback->payloadLength,
                                                                zclCmdIndCallback->payload);
    }
    break;
    case ZCL_REPORT_IND:
    {
      ZCL_AttrReportInd_t *zclAttrReportInd = (ZCL_AttrReportInd_t *)(cbParam->parameters);
      zclAttrReportInd->callbackFn(zclAttrReportInd->addressing,
                                   zclAttrReportInd->payloadLength,
                                   zclAttrReportInd->payload);
    }
    break;
    case ZCL_DEFAULT_RESP_IND:
    {
      ZCL_DefaultRespInd_t *zclDefaultRespInd = (ZCL_DefaultRespInd_t *)(cbParam->parameters);
      zclDefaultRespInd->callbackFn(zclDefaultRespInd->req,
                                    zclDefaultRespInd->addressing,
                                    zclDefaultRespInd->payloadLength,
                                    zclDefaultRespInd->payload);
    }
    break;
    case ZCL_ATTRIBUTE_EVENT_IND:
    {
      ZCL_AttrEventInd_t *zclAttrEventInd = (ZCL_AttrEventInd_t *)(cbParam->parameters);
      zclAttrEventInd->callbackFn(zclAttrEventInd->addressing,
                                  zclAttrEventInd->attributeId,
                                  zclAttrEventInd->event);
    }
    break;
    case ZCL_NOTIFY_RESP_IND:
    {
      ZCL_NotifyRespInd_t *zclNotifyRespInd = (ZCL_NotifyRespInd_t *)(cbParam->parameters);
      zclNotifyRespInd->callbackFn(zclNotifyRespInd->ntfy);
    }
    break;
  }
  
}

/* eof : ZCL_API.c */