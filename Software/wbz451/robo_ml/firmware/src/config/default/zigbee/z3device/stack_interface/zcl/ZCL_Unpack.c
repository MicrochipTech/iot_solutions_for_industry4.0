/*******************************************************************************
  Zigbee Cluster Library Unpack Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ZCL_Unpack.c

  Summary:
    Unpack the ZCL requests and calls corresponding ZCL API.

  Description:
    Unpack the ZCL requests and calls corresponding ZCL API.
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
#include <z3device/stack_interface/zcl/include/ZCL_Unpack.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/
static ZB_AppGenericCallbackParam_t zclCbParams;

/*******************************************************************************
                    Global variables section
*******************************************************************************/
extern ZB_AppGenericCallBack fnAppGenericCB;

/*******************************************************************************
                    Implementation section
*******************************************************************************/

/**************************************************************************//**
\brief ZCL_CommandManagerInit Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_CommandManagerInit_Unpack(void *req)
{
  (void)req;
  //ZCL_CommandManagerInit();
  ZCL_CommandManagerInit(); //should be changed as above after merge
}

/**************************************************************************//**
\brief ZCL_RegisterEndpoint Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_RegisterEndpoint_Unpack(void *req)
{
  ZCL_RegisterEndpoint((ZCL_DeviceEndpoint_t *) req);
}

/**************************************************************************//**
\brief ZCL_UnregisterEndpoint Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_UnregisterEndpoint_Unpack(void *req)
{
  ZCL_UnregisterEndpoint((ZCL_DeviceEndpoint_t *) req);
}

/**************************************************************************//**
\brief ZCL_StartReporting Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_StartReporting_Unpack(void *req)
{
  (void)req;
  ZCL_StartReporting();
}

/**************************************************************************//**
\brief ZCL_GetCluster Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetCluster_Unpack(void *req)
{
  ZCL_GetCluster_t *zclGetCluster = (ZCL_GetCluster_t *)req;
  zclGetCluster->zclCluster = ZCL_GetCluster(zclGetCluster->endpointId,
                                             zclGetCluster->clusterId,
                                             zclGetCluster->clusterSide);
}

/**************************************************************************//**
\brief ZCL_ResetReq Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_ResetReq_Unpack(void *req)
{
  (void)req;
  ZCL_ResetReq();
}

/**************************************************************************//**
\brief ZCL_ReadAttributeValue Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_ReadAttributeValue_Unpack(void *req)
{

  ZCL_ReadAttribute_t *zclReadAttr = (ZCL_ReadAttribute_t *)req;

  zclReadAttr->zclStatus =  ZCL_ReadAttributeValue(zclReadAttr->endpointId,
                                                   zclReadAttr->clusterId,
						                           zclReadAttr->clusterSide,
                                                   zclReadAttr->attrId,
                                                   zclReadAttr->attrType,
                                                   zclReadAttr->attrValue);
}

/**************************************************************************//**
\brief ZCL_WriteAttributeValue Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_WriteAttributeValue_Unpack(void *req)
{
  ZCL_WriteAttribute_t *zclWriteAttr = (ZCL_WriteAttribute_t *)req;
  
  zclWriteAttr->zclStatus = ZCL_WriteAttributeValue(zclWriteAttr->endpointId,
                                                    zclWriteAttr->clusterId,
                                                    zclWriteAttr->clusterSide,
						                            zclWriteAttr->attrId,
						                            zclWriteAttr->attrType,
                                                    zclWriteAttr->attrValue);
}

/**************************************************************************//**
\brief ZCL_GetNextCluster Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetNextCluster_Unpack(void *req)
{
  ZCL_GetNextCluster_t  *zclGetNextCluster = (ZCL_GetNextCluster_t *)req;
  zclGetNextCluster->nextCluster = ZCL_GetNextCluster(zclGetNextCluster->inputCluster);
}

/**************************************************************************//**
\brief ZCL_GetNextElement Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetNextElement_Unpack(void *req)
{
  ZCL_GetPutNextElement_t *zclGetNextElement = (ZCL_GetPutNextElement_t *)req;
  zclGetNextElement->zclStatus = ZCL_GetNextElement(zclGetNextElement->nextElement);
}

/**************************************************************************//**
\brief ZCL_PutNextElemen Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_PutNextElement_Unpack(void *req)
{
  ZCL_GetPutNextElement_t *zclPutNextElement = (ZCL_GetPutNextElement_t *)req;
  zclPutNextElement->zclStatus = ZCL_PutNextElement(zclPutNextElement->nextElement);
}

/**************************************************************************//**
\brief ZCL_GetAttributeLength Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_GetAttributeLength_Unpack(void *req)
{
  ZCL_GetAttributeLength_t *zclGetAttrLen = (ZCL_GetAttributeLength_t *)req;
  zclGetAttrLen->attrLen = ZCL_GetAttributeLength(zclGetAttrLen->typeId, 
                                                  (const uint8_t*)(zclGetAttrLen->value));
}

/**************************************************************************//**
\brief ZCL_IsBusy Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_IsBusy_Unpack(void* req)
{
  bool *isBusy = (bool* )req;
  *isBusy = ZCL_IsBusy();
}

/**************************************************************************//**
\brief ZCL_CommandReq Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_CommandReq_Unpack(void *req)
{
   ZCL_CommandReq((ZCL_Request_t *)req);
}

/**************************************************************************//**
\brief ZCL_AttributeReq Unpack function
\param[in] req - request
******************************************************************************/
void ZCL_AttributeReq_Unpack(void *req)
{
  ZCL_AttributeReq((ZCL_Request_t *)req);
}

/**************************************************************************//**
\brief ZCL_ReportOnChangeIfNeeded Unpack function
\param[in] req - request paramters structure
******************************************************************************/
void ZCL_ReportOnChangeIfNeeded_Unpack(void* req)
{
  ZCL_ReportOnChangeIfNeeded_t *zclReportOnchange = (ZCL_ReportOnChangeIfNeeded_t*)req ;
  zclReportOnchange->zclStatus = ZCL_ReportOnChangeIfNeeded(zclReportOnchange->attr);
}

/**************************************************************************//**
\brief ZCL_GetNextSeqNumber Unpack function
\param[in] req - request paramters structure
******************************************************************************/
void ZCL_GetNextSeqNumber_Unpack(void* req)
{
  uint8_t *zclNexySeqNo = (uint8_t* )req;
  *zclNexySeqNo = ZCL_GetNextSeqNumber();
}

/*************************************************************************//**
 \brief ZCL_SetReportableChange Unpack functin
\param[in] req - request paramters structure
*****************************************************************************/
void ZCL_SetReportableChange_Unpack(void* req)
{
  ZCL_SetReportableChange_t  *zcSetReportableChange = (ZCL_SetReportableChange_t*)req;
  zcSetReportableChange->zclStatus = ZCL_SetReportableChange(zcSetReportableChange->endpointId,
                                                    zcSetReportableChange->clusterId,
                                                    zcSetReportableChange->clusterSide,
						    zcSetReportableChange->attrId,
						    zcSetReportableChange->attrType, 
						    zcSetReportableChange->repChange);

}
bool initiatedToApp = false;
/*************************************************************************//**
 \brief Function to send a common ZCL_callback to application
 \param[in] callbackFn   - Calllabck function to be called in the application
            addressing   - Zcl addressing infirmation
            payloadLength- payload length of the command
            payload      - payload of the command
*****************************************************************************/
ZCL_Status_t ZCL_CommandInd(ZCL_CommandIndCallback_t callbackFn, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  ZCL_CommandInd_t zclCommandIndication, *bindIndPtr;
  uint32_t *paramPtr = NULL;
  ZCL_Status_t status;
  zclCommandIndication.callbackFn = callbackFn;
  zclCommandIndication.addressing = addressing;
  zclCommandIndication.payloadLength = payloadLength;
  zclCommandIndication.payload = payload;
  
  zclCbParams.eModuleID = ZIGBEE_ZCL;
  zclCbParams.uCallBackID = ZCL_CLUSTER_COMMAND_IND;
  zclCbParams.paramSize = sizeof(&paramPtr);
  paramPtr = OSAL_Malloc(sizeof(ZCL_CommandInd_t));
  memset(&zclCommandIndication.status,0, sizeof(zclCommandIndication.status));
  memcpy(paramPtr,&zclCommandIndication, sizeof(ZCL_CommandInd_t));
  zclCbParams.parameters = (void *)&paramPtr;
  
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&zclCbParams);
  vTaskDelay(2);
  bindIndPtr = (ZCL_CommandInd_t*)paramPtr;
  status = bindIndPtr->status;
  OSAL_Free(paramPtr);
  return status;
}
/*************************************************************************//**
 \brief Function to send zcl report indication to application
 \param[in] callbackFn   - Calllabck function to be called in the application
            zclIndType  -  zcl indication type
            addressing   - Zcl addressing infirmation
            payloadLength- payload length of the command
            payload      - payload of the command
*****************************************************************************/
void ZCL_AttrReportInd(ZCL_ReportIndCallback_t callbackFn, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  ZCL_AttrReportInd_t zclCommonInd;
  zclCommonInd.callbackFn = callbackFn;
  zclCommonInd.addressing = addressing;
  zclCommonInd.payloadLength = payloadLength;
  zclCommonInd.payload = payload;

  zclCbParams.eModuleID = ZIGBEE_ZCL;
  zclCbParams.uCallBackID = ZCL_REPORT_IND;
  zclCbParams.parameters = (void *)&zclCommonInd;
  zclCbParams.paramSize = sizeof(ZCL_AttrReportInd_t);
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&zclCbParams);
}
/*************************************************************************//**
 \brief Function to send  ZCL default resp Ind to application
 \param[in] callbackFn   - Calllabck function to be called in the application
            zclIndType  -  zcl indication type
            req         - ZCL request for which defaultresp is sent
            addressing   - Zcl addressing infirmation
            payloadLength- payload length of the command
            payload      - payload of the command
*****************************************************************************/
void ZCL_DefaultResponseInd(ZCL_DefaultRespIndCallback_t callbackFn, ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  ZCL_DefaultRespInd_t zclDefaultRespInd;

  zclDefaultRespInd.callbackFn = callbackFn;
  zclDefaultRespInd.req = req;
  zclDefaultRespInd.addressing = addressing;
  zclDefaultRespInd.payloadLength = payloadLength;
  zclDefaultRespInd.payload = payload;

  zclCbParams.eModuleID = ZIGBEE_ZCL;
  zclCbParams.uCallBackID = ZCL_DEFAULT_RESP_IND;
  zclCbParams.parameters = (void *)&zclDefaultRespInd;
  zclCbParams.paramSize = sizeof(ZCL_DefaultRespInd_t);
  
  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&zclCbParams);  
}

/*************************************************************************//**
 \brief Function to send ZCL Atribute Event Ind to application
 \param[in] callbackFn   - Calllabck function to be called in the application
            zclIndType  -  zcl indication type
            addressing   - Zcl addressing infirmation
            attributeId-  Atribute Id
            Event - Event occured on attribute
*****************************************************************************/
void ZCL_AttrEventInd(ZCL_AttrEventIndCallback_t callbackFn, ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
  ZCL_AttrEventInd_t zclAttrEventInd;
  
  zclAttrEventInd.callbackFn = callbackFn;
  zclAttrEventInd.addressing = addressing;
  zclAttrEventInd.attributeId = attributeId;
  zclAttrEventInd.event = event;
  
  zclCbParams.eModuleID = ZIGBEE_ZCL;
  zclCbParams.uCallBackID = ZCL_ATTRIBUTE_EVENT_IND;
  zclCbParams.parameters = (void *)&zclAttrEventInd;
  zclCbParams.paramSize = sizeof(ZCL_AttrEventInd_t);

  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&zclCbParams);
}

/*************************************************************************//**
 \brief Function to send ZCL Atribute Event Ind to application
 \param[in] callbackFn   - Calllabck function to be called in the application
            Notify       - ZCL_Notify
*****************************************************************************/
void ZCL_NotifyRespInd(ZCL_NotifyRespIndiCallback_t callbackFn, ZCL_Notify_t *ntfy)
{
  ZCL_NotifyRespInd_t zclNotifyRespInd;
  
  zclNotifyRespInd.callbackFn = callbackFn;
  zclNotifyRespInd.ntfy = ntfy;
  
  zclCbParams.eModuleID = ZIGBEE_ZCL;
  zclCbParams.uCallBackID = ZCL_NOTIFY_RESP_IND;
  zclCbParams.parameters = (void *)&zclNotifyRespInd;
  zclCbParams.paramSize = sizeof(ZCL_NotifyRespInd_t);

  if (NULL != fnAppGenericCB)
    fnAppGenericCB(&zclCbParams);
}