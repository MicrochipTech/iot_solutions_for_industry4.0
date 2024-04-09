/*******************************************************************************
  Zigbee Cluster Library Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ZCL_Unpack.h

  Summary:
    Unpack the ZCL requests and calls corresponding ZCL API.

  Description:
    This file contains declaration for ZCL Unpack requests and calls corresponding ZCL API.
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


/*******************************************************************************
                             Includes section
*******************************************************************************/
#include <framework_defs.h>
#include <z3device/stack_interface/zgb_api.h>
#include <zcl/include/zcl.h>
#include <zcl/include/zclCommandManager.h> //will be removed later

/******************************************************************************
                    Definitions section
*******************************************************************************/
#define ZCL_CLUSTER_COMMAND_IND  0
#define ZCL_REPORT_IND           1
#define ZCL_DEFAULT_RESP_IND     2
#define ZCL_ATTRIBUTE_EVENT_IND  3
#define ZCL_NOTIFY_RESP_IND      4
/******************************************************************************
                    Types section
******************************************************************************/
/*************************************************************************//**
  \brief ZCL_GetCluster() API parameters
*****************************************************************************/
typedef struct _ZCL_GetCluster
{
  Endpoint_t endpointId;
  ClusterId_t clusterId;
  uint8_t clusterSide;
  ZCL_Cluster_t *zclCluster;
} ZCL_GetCluster_t;

/*************************************************************************//**
  \brief ZCL_ReadAttribute() API parameters
*****************************************************************************/
typedef struct _ZCL_ReadAttribute
{
   Endpoint_t endpointId;
   ClusterId_t clusterId;
   uint8_t clusterSide;
   ZCL_AttributeId_t attrId;
   uint8_t *attrType;
   uint8_t *attrValue;
   ZCL_Status_t zclStatus;
} ZCL_ReadAttribute_t;

/*************************************************************************//**
  \brief ZCL_WriteAttribute() API parameters
*****************************************************************************/
typedef struct _ZCL_WriteAttribute
{
   Endpoint_t endpointId;
   ClusterId_t clusterId;
   uint8_t clusterSide;
   ZCL_AttributeId_t attrId;
   uint8_t attrType;
   uint8_t *attrValue;
   ZCL_Status_t zclStatus;
} ZCL_WriteAttribute_t;

/*************************************************************************//**
  \brief ZCL_GetNextCluster() API parameters
*****************************************************************************/
typedef struct _ZCL_GetNextCluster
{
  ZCL_Cluster_t *inputCluster;
  ZCL_Cluster_t *nextCluster;
} ZCL_GetNextCluster_t;

/*************************************************************************//**
  \brief ZCL_GetNextElement_t() & ZCL_PutNextElement_t API parameters
*****************************************************************************/
typedef struct _ZCL_NextElement
{
  ZCL_NextElement_t* nextElement;
  ZCL_Status_t zclStatus;
} ZCL_GetPutNextElement_t;

/*************************************************************************//**
  \brief ZCL_GetAttributeLength() API parameters
*****************************************************************************/
typedef struct _ZCL_GetAttributeLength
{
  uint8_t typeId;
  uint16_t attrLen;
  uint8_t const* value;  
} ZCL_GetAttributeLength_t;

/*************************************************************************//**
  \brief ZCL_ReportOnChangeIfNeeded() API parameters
*****************************************************************************/
typedef struct _ZCL_ReportOnChangeIfNeeded
{
  void *attr;
  ZCL_Status_t zclStatus;
} ZCL_ReportOnChangeIfNeeded_t;

/*************************************************************************//**
  \brief ZCL_SetReportableChange() API parameters
*****************************************************************************/
typedef struct _ZCL_SetReportableChange
{
   Endpoint_t endpointId;
   ClusterId_t clusterId;
   uint8_t clusterSide;
   ZCL_AttributeId_t attrId;
   uint8_t attrType;
   uint8_t *repChange;
   ZCL_Status_t zclStatus;
} ZCL_SetReportableChange_t;

/*******************************************************************************
                    Global variables section
*******************************************************************************/

/**************************************************************************//**
\brief ZCL_CommandManagerInit Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_CommandManagerInit_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_RegisterEndpoint Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_RegisterEndpoint_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_UnregisterEndpoint Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_UnregisterEndpoint_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_StartReporting Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_StartReporting_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_GetCluster Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetCluster_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_ResetReq Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_ResetReq_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_ReadAttributeValue Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_ReadAttributeValue_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_WriteAttributeValue Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_WriteAttributeValue_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_GetNextCluster Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetNextCluster_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_GetNextElement Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetNextElement_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_PutNextElement Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_PutNextElement_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_GetAttributeLength Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetAttributeLength_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_IsBusy Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_IsBusy_Unpack(void* req);

/**************************************************************************//**
\brief ZCL_CommandReq Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_CommandReq_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_AttributeReq Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_AttributeReq_Unpack(void *req);

/**************************************************************************//**
\brief ZCL_ReportOnChangeIfNeeded Unpack function
\param[in] req - request paramters structure
******************************************************************************/
void ZCL_ReportOnChangeIfNeeded_Unpack(void* req);

/**************************************************************************//**
\brief ZCL_GetNextSeqNumber Unpack function
\param[in] req - request paramters structure
******************************************************************************/
void ZCL_GetNextSeqNumber_Unpack(void* req);

/*************************************************************************//**
 \brief ZCL_SetReportableChange Unpack functin
\param[in] req - request paramters structure
*****************************************************************************/
void ZCL_SetReportableChange_Unpack(void* req);


