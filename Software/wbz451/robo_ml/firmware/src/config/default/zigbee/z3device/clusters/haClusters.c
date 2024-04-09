/*******************************************************************************
  Application HA Clusters Source File

  Company:
    Microchip Technology Inc.

  File Name:
    haClusters.c

  Summary:
    This file contains the Application Clusters interface.

  Description:
    This file contains the Application Clusters interface.
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
#include <z3device/clusters/include/haClusters.h>
#include <z3device/common/include/appConsts.h>
#include <z3device/common/include/z3Device.h>
#include <zcl/include/zclCommandManager.h>
#include <zcl/include/clusters.h>
#include <zcl/include/zclZllBasicCluster.h>
#include <zcl/include/zclSecurityManager.h>
#include <zdo/include/zdo.h>
#include <app_zigbee/zigbee_console/consoleCmds.h>
/******************************************************************************
                    Prototypes section
******************************************************************************/
static void ZCL_ConfigureReportingResp(ZCL_Notify_t *ntfy);
static void ZCL_ConfigureReportingResp2(ZCL_Notify_t *ntfy);
static void zdpSimpleDescResponse(ZDO_ZdpResp_t *resp);
static void zdpMatchDescResponse(ZDO_ZdpResp_t *resp);
static void zdpIeeeAddrResponse(ZDO_ZdpResp_t *resp);
static void zdpNwkAddrResponse(ZDO_ZdpResp_t *resp);
static void zdpActiveEpResponse(ZDO_ZdpResp_t *resp);
static void zdpNodeDescResponse(ZDO_ZdpResp_t *resp);
static void ZCL_ReadReportingResp(ZCL_Notify_t *ntfy);

/******************************************************************************
                    Global variables section
******************************************************************************/
DescModeManagerMem_t descModeMem;
NWK_LeaveReq_t reqNwk;
/*******************************************************************************
                    Local variables section
*******************************************************************************/
static uint8_t zclDefaultResponseBit = ZCL_FRAME_CONTROL_DISABLE_DEFAULT_RESPONSE;

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Set the DisableDefaultResponse value for the default response

\param[in] value - bit value to set in default response 
******************************************************************************/
void setZclDefaultResponseBit(uint8_t value)
{
  zclDefaultResponseBit = value;
}

/**************************************************************************//**
\brief Get the DisableDefaultResponse value for the default response

\return Value to set in default response 
******************************************************************************/
uint8_t getZclDefaultResponseBit(void)
{
  return zclDefaultResponseBit;
}

/**************************************************************************//**
\brief Indication of read attribute response

\param[in] ntfy - pointer to response
******************************************************************************/
void ZCL_ReadAttributeResp(ZCL_Notify_t *ntfy)
{
  ZCL_NextElement_t element;
  ZCL_ReadAttributeResp_t *readAttributeResp;
  
  if (ZCL_SUCCESS_STATUS == ntfy->status)
  {
    uint8_t numberofAttributesRead = 1;
    ZCL_Status_t zclStatus;
    element.id            = ZCL_READ_ATTRIBUTES_RESPONSE_COMMAND_ID;
    element.payloadLength = ntfy->responseLength;
    element.payload       = ntfy->responsePayload;
    element.content       = NULL;

    appSnprintf(" ->Read attribute response: ");
    do
    {
        zclStatus = ZCL_GetNextElement(&element);
        readAttributeResp = (ZCL_ReadAttributeResp_t *) element.content;
        if (numberofAttributesRead > 5)
        {
            appSnprintf("*Increase APP_TX_BUFFER_LENGTH to print all attributes*\r\n");
            return;
        }
        numberofAttributesRead++;
        if (ZCL_SUCCESS_STATUS != readAttributeResp->status)
        {
          appSnprintf("\r\n failed: Id:0x%x, status = 0x%x\r\n", (unsigned)readAttributeResp->id, (unsigned)readAttributeResp->status);
          return;
        }
        else
        {
          appSnprintf("\r\n success ");
        }

        if (ZCL_CHARACTER_STRING_DATA_TYPE_ID == readAttributeResp->type)
        {
          appSnprintf("Id:0x%x, value = %s\r\n", (unsigned)readAttributeResp->id, readAttributeResp->value);
        }
        else if (ZCL_OCTET_STRING_DATA_TYPE_ID == readAttributeResp->type)
        {
          appSnprintf("Id:0x%x, value = %s\r\n", (unsigned)readAttributeResp->id, readAttributeResp->value);
        }
        else if (ZCL_OCTET_STRING_DATA_TYPE_ID == readAttributeResp->type)
        {    
          appSnprintf("Id:0x%x, value = %s\r\n", (unsigned)readAttributeResp->id, readAttributeResp->value);
        }
        else if (ZCL_IEEE_ADDRESS_DATA_TYPE_ID == readAttributeResp->type)
        {
          appSnprintf("Id:0x%x, value = 0x", (unsigned)readAttributeResp->id);
          for (uint8_t i = 8; i > 0; i--)
          {
            appSnprintf("%02x", readAttributeResp->value[i-1]);
          }
          appSnprintf("\r\n");
        }

        else if ((ZCL_U32BIT_DATA_TYPE_ID == readAttributeResp->type) || (ZCL_UTC_TIME_DATA_TYPE_ID == readAttributeResp->type))
        {
          uint32_t u32AttrVal;
          memcpy(&u32AttrVal, &readAttributeResp->value[0], sizeof(uint32_t));
          appSnprintf("Id:0x%x, value = %u\r\n", (unsigned)readAttributeResp->id, u32AttrVal);
        }
        else if (ZCL_U64BIT_DATA_TYPE_ID == readAttributeResp->type)
        {
          uint64_t u64AttrVal;
          memcpy(&u64AttrVal, &readAttributeResp->value[0], sizeof(uint64_t));
          appSnprintf("Id:0x%x, value = 0x%08x%08x\r\n", (unsigned)readAttributeResp->id, (uint32_t)(u64AttrVal >> 32), (uint32_t)(u64AttrVal & 0xFFFFFFFF));
        }
        else if (ZCL_U16BIT_DATA_TYPE_ID == readAttributeResp->type)
        {
          uint16_t u16AttrVal;
          memcpy(&u16AttrVal, &readAttributeResp->value[0], sizeof(uint16_t));
          appSnprintf("Id:0x%x, value = %u\r\n", (unsigned)readAttributeResp->id, u16AttrVal);
        }
        else if(ZCL_S8BIT_DATA_TYPE_ID ==  readAttributeResp->type)
        {
          appSnprintf("Id:0x%x, value = %d\r\n", (unsigned)readAttributeResp->id, (signed)readAttributeResp->value[0]);
        }
        else if (ZCL_S16BIT_DATA_TYPE_ID == readAttributeResp->type)
        {
          int16_t s16AttrVal;
          memcpy(&s16AttrVal, &readAttributeResp->value[0], sizeof(int16_t));
          appSnprintf("Id:0x%x, value = %d\r\n", (unsigned)readAttributeResp->id, s16AttrVal);
        }
        else
        {
          appSnprintf("Id:0x%x, value = %u\r\n", (unsigned)readAttributeResp->id, (unsigned)readAttributeResp->value[0]);
        }
    } while (ZCL_END_PAYLOAD_REACHED_STATUS != zclStatus);
  }
  else
  {
    appSnprintf( " +Read attribute failed: status = 0x%x\r\n", (unsigned)ntfy->status);
  }
}

/**************************************************************************//**
\brief Sends a read attribute request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] attr    - attribute identifier;
\param[in] cb      - response callback;

\return none
******************************************************************************/
void readAttribute(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, 
                   uint16_t cluster, uint16_t attr, ZclNtfyCallback_t cb)
{
  /* Stack variables */
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ReadAttributeReq_t readAttrReqElement;

  /* Get free command memory */
  if (!(req = getFreeCommand()))
    return;

  /* Fill the attribute identifier to read from */
  readAttrReqElement.id = attr;

  /* Fill the details of ZCL command payload */
  element.payloadLength = 0;
  element.payload = req->requestPayload;
  element.content = &readAttrReqElement;
  
  element.id = ZCL_READ_ATTRIBUTES_COMMAND_ID;
  ZCL_PutNextElement(&element);

  fillCommandRequest(req, ZCL_READ_ATTRIBUTES_COMMAND_ID, element.payloadLength, srcEp);
  
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);

  /* Callback settings */  
  req->ZCL_Notify = (cb == NULL) ? ZCL_ReadAttributeResp : cb;

  /* Send the command to manipulate attribute */
  ZCL_CommandManagerSendAttribute(req);
  
  return;
}

/**************************************************************************//**
\brief Sends a multiple read attribute request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] startAttrId    - starting attribute identifier;
\param[in] count    - number of attributes to read;
\param[in] cb      - response callback;

\return none
******************************************************************************/
void readAttributeMultiple(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, 
                   uint16_t cluster, uint16_t startAttrId, uint8_t count, ZclNtfyCallback_t cb)
{
  /* Stack variables */
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ReadAttributeReq_t readAttrReqElement;

  /* Get free command memory */
  if (!(req = getFreeCommand()))
    return;

  /* Fill the attribute identifier to read from */
  readAttrReqElement.id = startAttrId;

  /* Fill the details of ZCL command payload */
  element.payloadLength = 0;
  element.payload = req->requestPayload;
  element.content = &readAttrReqElement;
  
  element.id = ZCL_READ_ATTRIBUTES_COMMAND_ID;
  
  for (uint8_t loopIndex = 0; loopIndex < count; loopIndex++)
  {
    readAttrReqElement.id = startAttrId + loopIndex;
    ZCL_PutNextElement(&element);
  }
    
  fillCommandRequest(req, ZCL_READ_ATTRIBUTES_COMMAND_ID, element.payloadLength, srcEp);
  
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);

  /* Callback settings */  
  req->ZCL_Notify = (cb == NULL) ? ZCL_ReadAttributeResp : cb;

  /* Send the command to manipulate attribute */
  ZCL_CommandManagerSendAttribute(req);
  
  return;
}
/**************************************************************************//**
\brief Indication of write attribute response

\param[in] ntfy - pointer to response
******************************************************************************/
void ZCL_WriteAttributeResp(ZCL_Notify_t *ntfy)
{
  if (ZCL_SUCCESS_STATUS == ntfy->status)
  {
    appSnprintf(" <-Write attribute response: success\r\n");
  }
  else
  {
    appSnprintf(" +Write attribute failed: status = 0x%x\r\n", (unsigned)ntfy->status);
  }
}

/**************************************************************************//**
\brief Sends a write attribute request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] type    - type identifier of data;
\param[in] attr    - attribute identifier;
\param[in] data    - pointer to value to be written;
\param[in] size    - size of the data
\param[in] cb      - response callback;

\return none
******************************************************************************/
void writeAttribute(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
                    uint16_t cluster, uint8_t type, uint16_t attr, void *data,
                    uint8_t size, ZclNtfyCallback_t cb)
{
  ZCL_Request_t *req;
  ZCL_WriteAttributeReq_t writeAttrReq;

  if (!(req = getFreeCommand()))
    return;

  writeAttrReq.id = attr;
  writeAttrReq.type = type;
  memset(&writeAttrReq.value, 0, sizeof(ZCL_WriteAttributeReq_t));
  memcpy(req->requestPayload, (uint8_t *)&writeAttrReq, sizeof(ZCL_WriteAttributeReq_t) - sizeof(uint8_t));
  memcpy(req->requestPayload + sizeof(ZCL_WriteAttributeReq_t) - sizeof(uint8_t), (uint8_t *)data, size);

  fillCommandRequest(req, ZCL_WRITE_ATTRIBUTES_COMMAND_ID, size + sizeof(ZCL_WriteAttributeReq_t) - sizeof(uint8_t), srcEp);
  
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);
  
  req->ZCL_Notify = (cb == NULL) ? ZCL_WriteAttributeResp : cb;

  ZCL_CommandManagerSendAttribute(req);
  
  return;
}

/**************************************************************************//**
\brief Indication of write attribute no response response

\param[in] ntfy - pointer to response
******************************************************************************/
void ZCL_WriteAttributeNoResp(ZCL_Notify_t *ntfy)
{
  (void)ntfy;
}

/**************************************************************************//**
\brief Sends a write attribute no response request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] type    - type identifier of data;
\param[in] attr    - attribute identifier;
\param[in] data    - pointer to value to be written;
\param[in] size    - size of the data
\param[in] cb      - response callback;

\return none
******************************************************************************/
void writeAttributeNoResp(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
                          uint16_t cluster, uint8_t type, uint16_t attr, void *data,
                          uint8_t size, ZclNtfyCallback_t cb)
{
  ZCL_Request_t *req;
  ZCL_WriteAttributeNoResponseReq_t writeAttrReq;

  if (!(req = getFreeCommand()))
    return;

  writeAttrReq.id = attr;
  writeAttrReq.type = type;
  memset(&writeAttrReq.value, 0, sizeof(ZCL_WriteAttributeNoResponseReq_t));
  memcpy(req->requestPayload, (uint8_t *)&writeAttrReq, sizeof(ZCL_WriteAttributeNoResponseReq_t) - sizeof(uint8_t));
  memcpy(req->requestPayload + sizeof(ZCL_WriteAttributeNoResponseReq_t) - sizeof(uint8_t), (uint8_t *)data, size);

  fillCommandRequest(req, ZCL_WRITE_ATTRIBUTES_NO_RESPONSE_COMMAND_ID, size + sizeof(ZCL_WriteAttributeNoResponseReq_t) - sizeof(uint8_t), srcEp);
  
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);
  
  req->ZCL_Notify = (cb == NULL) ? ZCL_WriteAttributeNoResp : cb;

  ZCL_CommandManagerSendAttribute(req);
  
  return;
}
/**************************************************************************//**
\brief Sends the Configure Reporting for cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
\param[in] min  - the minimum reporting interval;
\param[in] max  - the maximum reporting interval
******************************************************************************/
void configureReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max)
{
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ConfigureReportingReq_t configureReportingReq;

  if (!(req = getFreeCommand()))
    return;

  configureReportingReq.direction            = ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER;
  configureReportingReq.attributeId          = attrId;
  configureReportingReq.attributeType        = attrType;
  configureReportingReq.minReportingInterval = min;
  configureReportingReq.maxReportingInterval = max;

  if(((configureReportingReq.maxReportingInterval == 0x0000) && (configureReportingReq.minReportingInterval == 0xffff)) || (configureReportingReq.maxReportingInterval == 0xffff))
    configureReportingReq.reportableChange[0] = 0;
  element.payloadLength = 0;
  element.payload = req->requestPayload;
  element.id = ZCL_CONFIGURE_REPORTING_COMMAND_ID;
  element.content = &configureReportingReq;
  ZCL_PutNextElement(&element);

  fillCommandRequest(req, ZCL_CONFIGURE_REPORTING_COMMAND_ID, element.payloadLength, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);
  req->ZCL_Notify = ZCL_ConfigureReportingResp;

  ZCL_CommandManagerSendAttribute(req);
}

/**************************************************************************//**
\brief Sends the Configure Reporting  with report change for cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
\param[in] min  - the minimum reporting interval;
\param[in] max  - the maximum reporting interval
******************************************************************************/
void configureReportingWithRC(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max,
  void *repChange)
{
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ConfigureReportingReq_t configureReportingReq;
  ZCL_DataTypeDescriptor_t attrDescr = {.length = 0, .kind = 0};

  if (!(req = getFreeCommand()))
    return;

  configureReportingReq.direction            = ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER;
  configureReportingReq.attributeId          = attrId;
  configureReportingReq.attributeType        = attrType;
  configureReportingReq.minReportingInterval = min;
  configureReportingReq.maxReportingInterval = max;
  ZCL_GetDataTypeDescriptor(attrType, repChange, &attrDescr);
  if(attrDescr.length != 0)
    memcpy(configureReportingReq.reportableChange, (uint8_t *)repChange, attrDescr.length);

  if(((configureReportingReq.maxReportingInterval == 0x0000) && (configureReportingReq.minReportingInterval == 0xffff)) || (configureReportingReq.maxReportingInterval == 0xffff))
    configureReportingReq.reportableChange[0] = 0;
  
  element.payloadLength = 0;
  element.payload = req->requestPayload;
  element.id = ZCL_CONFIGURE_REPORTING_COMMAND_ID;
  element.content = &configureReportingReq;
  ZCL_PutNextElement(&element);

  fillCommandRequest(req, ZCL_CONFIGURE_REPORTING_COMMAND_ID, element.payloadLength, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);
  req->ZCL_Notify = ZCL_ConfigureReportingResp;

  ZCL_CommandManagerSendAttribute(req);
}

/**************************************************************************//**
\brief Sends the Read Reporting for cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp   - source endpoint;
\param[in] cluster - cluster identifier;
\param[in] attrId - attribute id;
******************************************************************************/
void readReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster,
  ZCL_AttributeId_t attrId)
{
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ReadReportingConfigurationReq_t readReportingReq;

  if (!(req = getFreeCommand()))
    return;

  readReportingReq.direction            = ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER;
  readReportingReq.attributeId          = attrId;

  element.payloadLength = 0;
  element.payload = req->requestPayload;
  element.id = ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID;
  element.content = &readReportingReq;
  ZCL_PutNextElement(&element);

  fillCommandRequest(req, ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID, element.payloadLength, srcEp);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);
  req->ZCL_Notify = ZCL_ReadReportingResp;

  ZCL_CommandManagerSendAttribute(req);
}

/**************************************************************************//**
\brief Indication of read attribute response

\param[in] ntfy - pointer to response
******************************************************************************/
static void ZCL_ReadReportingResp(ZCL_Notify_t *ntfy)
{
  ZCL_NextElement_t element;
  ZCL_ReadReportingConfigurationResp_t *readReportingResp;

  if (ZCL_SUCCESS_STATUS == ntfy->status)
  {
    element.id            = ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID;
    element.payloadLength = ntfy->responseLength;
    element.payload       = ntfy->responsePayload;
    element.content       = NULL;

    ZCL_GetNextElement(&element);
    readReportingResp = (ZCL_ReadReportingConfigurationResp_t *) element.content;

    if(ZCL_SUCCESS_STATUS == readReportingResp->status)
    {
      appSnprintf(" <-Read Reporting Attribute (0x%x) response: success\r\n  min = %u max = %u direction = %d attributeType = %u reportableChange = %d\r\n", 
                (unsigned)readReportingResp->attributeId, readReportingResp->minReportingInterval, readReportingResp->maxReportingInterval,
                readReportingResp->direction, readReportingResp->attributeType, readReportingResp->reportableChange[1]);
    }
    else
    {
      appSnprintf(" <-Read Reporting Attribute (0x%x) response: 0x%x\r\n",(unsigned)readReportingResp->attributeId,(unsigned)readReportingResp->status);
    }
  }
  else
  {
    appSnprintf(" +Read Reporting Attribute failed: status = 0x%2x\r\n", (unsigned)ntfy->status);
  }
  (void)readReportingResp;
}
/**************************************************************************//**
\brief Fills ZCL Request structure

\param[out] req     - pointer to zcl command request;
\param[in]  command - command id;
\param[in] size     - the size of request payload
\param[in] srcEp    - source endpoint;
******************************************************************************/
void fillCommandRequest(ZCL_Request_t *req, uint8_t command, uint8_t size, Endpoint_t srcEp)
{
  req->id              = command;
  req->requestLength   = size;
  req->endpointId      = srcEp;
  req->defaultResponse = zclDefaultResponseBit;
}

/**************************************************************************//**
\brief Fills zcl addressing structure

\param[out] addressing - pointer to the structure to be filled;
\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  cluster    - cluster id
******************************************************************************/
void fillDstAddressing(ZCL_Addressing_t *addressing, APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, ClusterId_t cluster)
{
  if(OTAU_CLUSTER_ID == cluster)
  {
    if(ZCL_GetCluster(APP_SRC_ENDPOINT_ID, cluster, ZCL_CLUSTER_SIDE_SERVER))
    {
      addressing->clusterSide         = ZCL_CLUSTER_SIDE_CLIENT;
    }
    else
    {
      addressing->clusterSide         = ZCL_CLUSTER_SIDE_SERVER;
    }
  }
  else
  {
    addressing->clusterSide          = ZCL_CLUSTER_SIDE_SERVER;
  }
  addressing->addrMode              = mode;
  addressing->addr.shortAddress     = addr;
  addressing->profileId             = PROFILE_ID_HOME_AUTOMATION;
  addressing->endpointId            = ep;
  addressing->clusterId             = cluster;
  addressing->manufacturerSpecCode  = 0;
  addressing->sequenceNumber        = ZCL_GetNextSeqNumber();
}

/**************************************************************************//**
\brief Fills zcl addressing structure

\param[out] addressing - pointer to the structure to be filled;
\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  cluster    - cluster id
******************************************************************************/
void fillDstAddressingServer(ZCL_Addressing_t *addressing, APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, ClusterId_t cluster)
{
  addressing->addrMode             = mode;
  addressing->addr.shortAddress    = addr;
  addressing->profileId            = PROFILE_ID_HOME_AUTOMATION;
  addressing->endpointId           = ep;
  addressing->clusterId            = cluster;
  addressing->clusterSide          = ZCL_CLUSTER_SIDE_CLIENT;
  addressing->manufacturerSpecCode = 0;
  addressing->sequenceNumber       = ZCL_GetNextSeqNumber();
}

/**************************************************************************//**
\brief Gets free command buffer

\returns pointer to a command buffer
******************************************************************************/
ZCL_Request_t *getFreeCommand(void)
{
  ZCL_Request_t *req;

  if (!(req = ZCL_CommandManagerAllocCommand()))
  {
    appSnprintf("\r\nNot enough command buffers\r\n");
  }

  return req;
}

/**************************************************************************//**
\brief Fills ZCL Addressing structure

\param[out] srcAddressing - pointer to zcl addressing request of source node;
\param[in]  dstAddressing - pointer to zcl addressing request of destination node;
\param[in]  side          - cluster side of recipient side
******************************************************************************/
void fillDstAddressingViaSourceAddressing(ZCL_Addressing_t *srcAddressing, ZCL_Addressing_t *dstAddressing, uint8_t side)
{
  *srcAddressing = *dstAddressing;
  srcAddressing->clusterSide = side;
}
/*******************************************************************************
\brief Sends the simple Descriptor request

\param[in] addr - nwk Address of Interest
\param[in] ep   - Endpoint for which the simple desctiptor is requested
*****************************************************************************/
void zdpSimpleDescReq(ShortAddr_t addr,uint8_t ep)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_SimpleDescReq_t *simpleDescReq = &zdpReq->req.reqPayload.simpleDescReq;

  zdpReq->ZDO_ZdpResp              =zdpSimpleDescResponse;
  zdpReq->reqCluster               = SIMPLE_DESCRIPTOR_CLID;
  zdpReq->dstAddrMode              = APS_SHORT_ADDRESS; 
  zdpReq->dstAddress.shortAddress  = addr;
  simpleDescReq->nwkAddrOfInterest = addr;
  simpleDescReq->endpoint          = ep;
  ZDO_ZdpReq(zdpReq);
}

/*******************************************************************************
\brief Sends the Node Descriptor request

\param[in] dstaddr - short address of destination node
\param[in] nwkAddrofInterest - nwk Address of Interest;
*****************************************************************************/
void zdpNodeDescReq(ShortAddr_t dstaddr, ShortAddr_t nwkAddrofInterest)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_NodeDescReq_t *nodeDescReq = &zdpReq->req.reqPayload.nodeDescReq;

  zdpReq->ZDO_ZdpResp              = zdpNodeDescResponse;
  zdpReq->reqCluster               = NODE_DESCRIPTOR_CLID;
  zdpReq->dstAddrMode              = APS_SHORT_ADDRESS; 
  zdpReq->dstAddress.shortAddress  = dstaddr;
  nodeDescReq->nwkAddrOfInterest = nwkAddrofInterest;
  ZDO_ZdpReq(zdpReq);
}

/*******************************************************************************
\brief Sends the ieee addr req request

\param[in] dstaddr - short address of destination node;
\param[in] nwkAddrofInterest - nwk Address of Interest;
\param[in] reqType - Request type for the command;
*****************************************************************************/
void zdpIeeeAddrReq(ShortAddr_t dstaddr, ShortAddr_t nwkAddrofInterest, uint8_t reqType)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_IeeeAddrReq_t *ieeeAddrReq = &zdpReq->req.reqPayload.ieeeAddrReq;

  zdpReq->ZDO_ZdpResp              = zdpIeeeAddrResponse;
  zdpReq->reqCluster               = IEEE_ADDR_CLID;
  zdpReq->dstAddrMode              = APS_SHORT_ADDRESS; 
  zdpReq->dstAddress.shortAddress  = dstaddr;
  ieeeAddrReq->nwkAddrOfInterest = nwkAddrofInterest;
  ieeeAddrReq->reqType = reqType;
  ieeeAddrReq->startIndex = 0U;
  ZDO_ZdpReq(zdpReq);
}

/*******************************************************************************
\brief Sends the nwk addr req request

\param[in] dstaddr - short address of destination node;
\param[in] ieeeAddrOfInterest - IEEE Address of Interest;
\param[in] reqType - Request type for the command;
*****************************************************************************/
void zdpNwkAddrReq(ShortAddr_t dstaddr, ExtAddr_t ieeeAddrOfInterest, uint8_t reqType)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_NwkAddrReq_t *nwkAddrReq = &zdpReq->req.reqPayload.nwkAddrReq;

  zdpReq->ZDO_ZdpResp              = zdpNwkAddrResponse;
  zdpReq->reqCluster               = NWK_ADDR_CLID;
  zdpReq->dstAddrMode              = APS_SHORT_ADDRESS; 
  zdpReq->dstAddress.shortAddress  = dstaddr;
  nwkAddrReq->ieeeAddrOfInterest   = ieeeAddrOfInterest;
  nwkAddrReq->reqType = reqType;
  nwkAddrReq->startIndex = 0U;
  ZDO_ZdpReq(zdpReq);
}

/*******************************************************************************
\brief Sends the Active EP req request

\param[in] dstaddr - short address of destination node;
\param[in] nwkAddrofInterest - nwk Address of Interest;
*****************************************************************************/
void zdpActiveEpReq(ShortAddr_t dstaddr, ShortAddr_t nwkAddrofInterest)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_ActiveEPReq_t *activeEpReq = &zdpReq->req.reqPayload.activeEPReq;

  zdpReq->ZDO_ZdpResp              = zdpActiveEpResponse;
  zdpReq->reqCluster               = ACTIVE_ENDPOINTS_CLID;
  zdpReq->dstAddrMode              = APS_SHORT_ADDRESS; 
  zdpReq->dstAddress.shortAddress  = dstaddr;
  activeEpReq->nwkAddrOfInterest   = nwkAddrofInterest;
  ZDO_ZdpReq(zdpReq);
}
/**************************************************************************//**
\brief simple Descriptor response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpSimpleDescResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_SIMPLE_DESCRIPTOR_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Nwk Address response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpNwkAddrResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_NWK_ADDRESS_RESPONSE;
  event.eventData.ParentChildInfo.shortAddress = resp->respPayload.nwkAddrResp.nwkAddrRemote;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Ieee Address response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpIeeeAddrResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  uint64_t tmpAddr;
  uint8_t *tmp;
  COPY_EXT_ADDR(tmpAddr, resp->respPayload.ieeeAddrResp.ieeeAddrRemote);
  tmp = (uint8_t *)&tmpAddr;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_IEEE_ADDRESS_RESPONSE;
  event.eventData.ParentChildInfo.ep = resp->respPayload.activeEPResp.activeEPCount;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;
  memcpy(&event.eventData.ParentChildInfo.extendedAddress, tmp, 8);

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Active EP response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpActiveEpResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_ACTIVE_EP_RESPONSE;
  event.eventData.ParentChildInfo.ep = resp->respPayload.activeEPResp.activeEPCount;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Node Descriptor response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpNodeDescResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_NODE_DESCRIPTOR_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Sends the Match Descriptor request

\param[in] addr - nwk Address of Interest
\param[in] ep   - Endpoint which requests Match desctiptor 
******************************************************************************/
void zdpMatchDescReq(ShortAddr_t addr,uint8_t ep)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_MatchDescReq_t *matchDescReq = &zdpReq->req.reqPayload.matchDescReq;
  uint8_t flag=0;
  
  AppBindReq_t **appBindRequest=   &deviceBindReqs[0];
  zdpReq->ZDO_ZdpResp             = zdpMatchDescResponse;
  zdpReq->reqCluster              = MATCH_DESCRIPTOR_CLID;
  zdpReq->dstAddrMode             = APS_SHORT_ADDRESS;
  zdpReq->dstAddress.shortAddress = addr;
  matchDescReq->nwkAddrOfInterest = addr;
  matchDescReq->profileId         = PROFILE_ID_HOME_AUTOMATION;
  for (uint8_t epCount = 0; epCount < APP_ENDPOINTS_AMOUNT; epCount++)
  {
    if( appBindRequest[epCount]->srcEndpoint == ep)
    {
      matchDescReq->numInClusters = appBindRequest[epCount]->remoteServersCnt;
      for (uint8_t i = 0; i < appBindRequest[epCount]->remoteServersCnt; i++)
      matchDescReq->inClusterList[i] = appBindRequest[epCount]->remoteServers[i];

      matchDescReq->numOutClusters = appBindRequest[epCount]->remoteClientsCnt;
      for (uint8_t i = 0; i < appBindRequest[epCount]->remoteClientsCnt; i++)
      matchDescReq->outClusterList[i] = appBindRequest[epCount]->remoteClients[i];
      flag++;
      break;
    }
  }
    if(flag==0)
      appSnprintf("Enter valid EP");
    else
      ZDO_ZdpReq(zdpReq);
}

/**************************************************************************//**
\brief ZDO Leave response callback

\param[in] resp - response payload
******************************************************************************/
static void zdoleaveResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_LEAVE_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Sends the Management Leave request

\param[in] dstAddr        - short address of destination node;
\param[in] extAddr        - extended address of destination node;
\param[in] rejoin         - rejoin if TRUE indicates the device will rejoin immediately after leaving
\param[in] removeChildren - removeChildren if TRUE indicates also the children of this device are removed
******************************************************************************/
void zdpMgmtLeaveReq(uint16_t dstAddr, ExtAddr_t extAddr, bool rejoin, bool removeChildren)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_MgmtLeaveReq_t *leavereq = &zdpReq->req.reqPayload.mgmtLeaveReq;

  zdpReq->ZDO_ZdpResp = zdoleaveResponse;
  zdpReq->reqCluster = MGMT_LEAVE_CLID;
  zdpReq->dstAddrMode = APS_SHORT_ADDRESS;

  zdpReq->dstAddress.shortAddress = dstAddr;

  COPY_64BIT_VALUE_A(leavereq->deviceAddr,&extAddr);

  leavereq->rejoin = rejoin;
  leavereq->removeChildren = removeChildren;

  ZDO_ZdpReq(zdpReq);
}
/**************************************************************************//**
\brief Match Descriptor response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpMatchDescResponse(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_MATCH_DESCRIPTOR_RESPONSE;
  event.eventData.ParentChildInfo.ep = resp->respPayload.matchDescResp.matchLength;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}
/**************************************************************************//**
\brief Network Leave Confirmation

\param[in] conf - pointer to confirmation structure
******************************************************************************/
void NWKf_LeaveConf(NWK_LeaveConf_t *conf)
{
 (void)conf;
}

/**************************************************************************//**
\brief Sends the Network Leave command

\param[in] extAddr        - extended address of destination node;
\param[in] rejoin         - rejoin if TRUE indicates the device will rejoin immediately after leaving
\param[in] removeChildren - removeChildren if TRUE indicates also the children of this device are removed
******************************************************************************/
void nwkLeaveCommand(ExtAddr_t extAddr, bool rejoin, bool removeChildren)
{
  NWK_LeaveControl_t defaultValue = NWK_DEFINE_LEAVE_CONTROL_DEFAULT;
  reqNwk.deviceAddress = extAddr;
  reqNwk.leaveControl = defaultValue;
  reqNwk.removeChildren = removeChildren;
  reqNwk.rejoin = rejoin;
  reqNwk.NWK_LeaveConf = NWKf_LeaveConf;
  NWK_LeaveReq(&reqNwk);
}

/**************************************************************************//**
\brief Management Bind response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpMgmtBindResp(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_MANAGEMENT_BIND_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief ZDP LQI response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpLqiResp(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_LQI_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event); 
}

/**************************************************************************//**
\brief ZDP Bind response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpBindResp(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_BIND_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief ZDP Unbind response callback

\param[in] resp - response payload
******************************************************************************/
static void zdpUnBindResp(ZDO_ZdpResp_t *resp)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_ZIGBEE;
  event.eventId = EVENT_UNBIND_RESPONSE;
  event.eventData.ParentChildInfo.status = resp->respPayload.status;

  APP_Zigbee_Handler(event);
}

/**************************************************************************//**
\brief Sends Management LQI request

\param[in] shortAddr        - short address of destination node;
\param[in] startIndex        - Start Index
******************************************************************************/
void zdpMgmtLqiReq(uint16_t shortAddr, uint8_t startIndex)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_MgmtLqiReq_t *Lqireq = &zdpReq->req.reqPayload.mgmtLqiReq;
  
  zdpReq->reqCluster = MGMT_LQI_CLID;
  zdpReq->dstAddrMode = APS_SHORT_ADDRESS;
  zdpReq->dstAddress.shortAddress = shortAddr;
  zdpReq->ZDO_ZdpResp = zdpLqiResp;
  
  Lqireq->startIndex = startIndex;
  
  ZDO_ZdpReq(zdpReq);
}

/**************************************************************************//**
\brief Sends Management Bind request

\param[in] shortAddr        - short address of destination node;
\param[in] startIndex       - Start Index
******************************************************************************/
void zdpMgmtBindReq(uint16_t shortAddr, uint8_t startIndex)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_MgmtBindReq_t *bindreq = &zdpReq->req.reqPayload.mgmtBindReq;

  zdpReq->ZDO_ZdpResp = zdpMgmtBindResp;
  zdpReq->reqCluster = MGMT_BIND_CLID;
  zdpReq->dstAddrMode = APS_SHORT_ADDRESS;

  zdpReq->dstAddress.shortAddress = shortAddr;

  bindreq->startIndex = startIndex;

  ZDO_ZdpReq(zdpReq);  
}

/**************************************************************************//**
\brief Sends ZDP Bind request

\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  extAddr    - Extended address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  srcEp      - endpoint number of source node;
\param[in]  clusterid  - cluster id
******************************************************************************/
void zdpBindReq(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, Endpoint_t ep, Endpoint_t srcEp, ClusterId_t clusterId)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_BindReq_t *bindreq = &zdpReq->req.reqPayload.bindReq;
  ExtAddr_t ownExtAddr;
  
  CS_ReadParameter(CS_UID_ID, &ownExtAddr);

  zdpReq->ZDO_ZdpResp = zdpBindResp;
  zdpReq->reqCluster = BIND_CLID;
  zdpReq->dstAddrMode = mode;
  
  zdpReq->dstAddress.shortAddress = addr;

  COPY_EXT_ADDR(bindreq->srcAddr, extAddr);
  bindreq->srcEndpoint = ep;
  bindreq->clusterId = clusterId;
  bindreq->dstAddrMode = APS_EXT_ADDRESS;
  COPY_EXT_ADDR(bindreq->dstExtAddr, ownExtAddr);
  bindreq->dstEndpoint = srcEp;

  ZDO_ZdpReq(zdpReq);
}

/**************************************************************************//**
\brief Sends ZDP Bind request with source address and destination endpoint.

\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  extAddr    - Extended address of destination mode;
\param[in]  extAddrSrc - Extended address of source mode;
\param[in]  epSrc      - endpoint number of source node;
\param[in]  epDst      - endpoint number of destination node;
\param[in]  srcEp      - endpoint number of source node;
\param[in]  clusterid  - cluster id
******************************************************************************/
void zdpBindReqWithSrcAddrDestEndpoint(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, ExtAddr_t extAddrSrc, Endpoint_t epSrc, Endpoint_t epDst, Endpoint_t srcEp, ClusterId_t clusterId)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_BindReq_t *bindreq = &zdpReq->req.reqPayload.bindReq;
  ExtAddr_t ownExtAddr;

  CS_ReadParameter(CS_UID_ID, &ownExtAddr);

  zdpReq->ZDO_ZdpResp = zdpBindResp;
  zdpReq->reqCluster = BIND_CLID;

  zdpReq->dstAddrMode = APS_SHORT_ADDRESS;
  zdpReq->dstAddress.shortAddress = addr;
  if (mode == APS_SHORT_ADDRESS)
  {
    appSnprintf("Use -g or -e instead ");
  }
  else
  {
  if (mode == APS_GROUP_ADDRESS)
  {
    bindreq->dstAddrMode = mode;
    bindreq->dstGroupAddr = (uint16_t) extAddrSrc;
    COPY_EXT_ADDR(bindreq->srcAddr, extAddr);
  } 
  else //mode == APS_EXT_ADDRESS
  {
    bindreq->dstAddrMode = mode;
    bindreq->dstExtAddr = extAddr;
    bindreq->dstEndpoint = (epDst==0)?srcEp:epDst;
    COPY_EXT_ADDR(bindreq->srcAddr, extAddr);
    COPY_EXT_ADDR(bindreq->dstExtAddr,(extAddrSrc==0)? ownExtAddr:extAddrSrc);
  }

  bindreq->srcEndpoint = epSrc;
  bindreq->clusterId = clusterId;

  ZDO_ZdpReq(zdpReq);
  }
}

/**************************************************************************//**
\brief Sends ZDP Unbind request with source address and destination endpoint.

\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  extAddr    - Extended address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  srcEp      - endpoint number of source node;
\param[in]  clusterid  - cluster id
******************************************************************************/
void zdpUnBindReq(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, Endpoint_t ep, Endpoint_t srcEp, ClusterId_t clusterId)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_UnbindReq_t *Unbindreq = &zdpReq->req.reqPayload.unbindReq;
  ExtAddr_t ownExtAddr;
  
  CS_ReadParameter(CS_UID_ID, &ownExtAddr);

  zdpReq->ZDO_ZdpResp = zdpUnBindResp;
  zdpReq->reqCluster = UNBIND_CLID;
  zdpReq->dstAddrMode = mode;
  zdpReq->dstAddress.shortAddress = addr;

  COPY_EXT_ADDR(Unbindreq->srcAddr, extAddr);
  Unbindreq->srcEndpoint = ep;
  Unbindreq->clusterId = clusterId;
  Unbindreq->dstAddrMode = APS_EXT_ADDRESS;
  COPY_EXT_ADDR(Unbindreq->dstExtAddr, ownExtAddr);
  Unbindreq->dstEndpoint = srcEp;

  ZDO_ZdpReq(zdpReq);
}

/**************************************************************************//**
\brief Sends ZDP Unbind request with source address and destination endpoint.

\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  extAddr    - Extended address of destination mode;
\param[in]  extAddrSrc - Extended address of source mode;
\param[in]  epSrc      - endpoint number of source node;
\param[in]  epDst      - endpoint number of destination node;
\param[in]  srcEp      - endpoint number of source node;
\param[in]  clusterid  - cluster id
******************************************************************************/
void zdpUnBindReqWithSrcAddrDestEndpoint(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, ExtAddr_t extAddrSrc, Endpoint_t epSrc, Endpoint_t epDst, Endpoint_t srcEp, ClusterId_t clusterId)
{
  ZDO_ZdpReq_t *zdpReq = &descModeMem.zdpReq;
  ZDO_UnbindReq_t *Unbindreq = &zdpReq->req.reqPayload.unbindReq;
  ExtAddr_t ownExtAddr;

  CS_ReadParameter(CS_UID_ID, &ownExtAddr);

  zdpReq->ZDO_ZdpResp = zdpBindResp;
  zdpReq->reqCluster = UNBIND_CLID;

  zdpReq->dstAddrMode = APS_SHORT_ADDRESS;
  zdpReq->dstAddress.shortAddress = addr;
  if (mode == APS_SHORT_ADDRESS)
  {
    appSnprintf("Bind Request Arguments error");
  }
  else
  {
  if (mode == APS_GROUP_ADDRESS)
  {
    Unbindreq->dstAddrMode = mode;
    Unbindreq->dstGroupAddr = (uint16_t) extAddrSrc;
    COPY_EXT_ADDR(Unbindreq->srcAddr, extAddr);
  }
  else//mode == APS_EXT_ADDRESS
  {
    Unbindreq->dstAddrMode = mode;
    Unbindreq->dstExtAddr = extAddr;
    Unbindreq->dstEndpoint = (epDst==0)?srcEp:epDst;
    COPY_EXT_ADDR(Unbindreq->srcAddr, extAddr);
    COPY_EXT_ADDR(Unbindreq->dstExtAddr,(extAddrSrc==0)? ownExtAddr:extAddrSrc);
  }

  Unbindreq->srcEndpoint = epSrc;
  Unbindreq->clusterId = clusterId;

  ZDO_ZdpReq(zdpReq);
  }
}

/**************************************************************************//**
\brief Sends configure reporting request to notify another device about reporting

\param[in] srcEndpoint    - source endpoint;
\param[in] dstEndpoint    - destination endpoint;
\param[in] clusterId      - cluster id;
\param[in] attrId         - attribute id;
\param[in] period         - report period
\param[in]configureRespCb - configure reporting callback 
******************************************************************************/
void sendConfigureReportingToNotify(Endpoint_t srcEndpoint, Endpoint_t dstEndpoint, ClusterId_t clusterId, ZCL_AttributeId_t attrId, ZCL_ReportTime_t period, ConfigureReportResp_t configureRespCb)
{
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ConfigureReportingReq_t configureReportingReq;

  if (!(req = getFreeCommand()))
    return;

  configureReportingReq.direction     = ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT;
  configureReportingReq.attributeId   = attrId;
  configureReportingReq.timeoutPeriod = period;

  element.payloadLength = 0;
  element.payload       = req->requestPayload;
  element.id            = ZCL_CONFIGURE_REPORTING_COMMAND_ID;
  element.content       = &configureReportingReq;
  ZCL_PutNextElement(&element);

  fillCommandRequest(req, ZCL_CONFIGURE_REPORTING_COMMAND_ID, element.payloadLength, srcEndpoint);
  req->endpointId = srcEndpoint;
  fillDstAddressing(&req->dstAddressing, APS_NO_ADDRESS, 0, dstEndpoint, clusterId);
  req->dstAddressing.clusterSide = ZCL_CLUSTER_SIDE_CLIENT;
  if(NULL == configureRespCb)
    req->ZCL_Notify = ZCL_ConfigureReportingResp;
  else
    req->ZCL_Notify = configureRespCb;

  ZCL_CommandManagerSendAttribute(req);
}

/**************************************************************************//**
\brief Sends the Configure Reporting for given cluster

\param[in] mode       - address mode;
\param[in] addr       - short address of destination node;
\param[in] ep         - destination endpoint;
\param[in] cluster    - cluster id;
\param[in] attrId     - attribute id;
\param[in] attrType   - attribute type
\param[in] min        - the minimum reporting interval;
\param[in] max        - the maximum reporting interval
******************************************************************************/
void sendConfigureReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, ClusterId_t cluster,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max)
{
  ZCL_Request_t *req;
  ZCL_NextElement_t element;
  ZCL_ConfigureReportingReq_t configureReportingReq;

  if (!(req = getFreeCommand()))
    return;

  configureReportingReq.direction            = ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER;
  configureReportingReq.attributeId          = attrId;
  configureReportingReq.attributeType        = attrType;
  configureReportingReq.minReportingInterval = min;
  configureReportingReq.maxReportingInterval = max;

  element.payloadLength = 0;
  element.payload = req->requestPayload;
  element.id = ZCL_CONFIGURE_REPORTING_COMMAND_ID;
  element.content = &configureReportingReq;
  ZCL_PutNextElement(&element);

  fillCommandRequest(req, ZCL_CONFIGURE_REPORTING_COMMAND_ID, element.payloadLength,ep);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, cluster);
  req->ZCL_Notify = ZCL_ConfigureReportingResp2;

  ZCL_CommandManagerSendAttribute(req);
}
/**************************************************************************//**
\brief Indication of configure reporting response

\param[in] ntfy - pointer to response
******************************************************************************/
static void ZCL_ConfigureReportingResp(ZCL_Notify_t *ntfy)
{
  (void)ntfy;
}

/* TODO: Move this to test harness app code */
/**************************************************************************//**
\brief Temporary function set key

\param[in] option - option for key type
******************************************************************************/
void tempfuctionsetkey(uint8_t option)
{
  ZCL_LinkKeyDesc_t localkeyDesc;
  ZCL_Set_t zclSet;
  
  APS_InitKeyPairSet();

  zclSet.attr.id = ZCL_LINK_KEY_DESC_ID;
  zclSet.attr.value.linkKeyDesc = &localkeyDesc;
  COPY_EXT_ADDR(localkeyDesc.addr, APS_UNIVERSAL_EXTENDED_ADDRESS);
  
  if (option == 1)
  {
    memcpy(localkeyDesc.key,&(uint8_t[])DS_LINK_KEY, 16);
  }
  else if (option == 2)
  {
    memcpy(localkeyDesc.key,&(uint8_t[])TL_LINK_KEY, 16);
  }
  else if (option == 3)
  {
    memcpy(localkeyDesc.key,&(uint8_t[])IC_LINK_KEY, 16);
  }
  else
  {
    memcpy(localkeyDesc.key,&(uint8_t[])HA_LINK_KEY, 16);
  }  
  ZCL_Set(&zclSet);
}

/**************************************************************************//**
\brief Indication of configure reporting response

\param[in] ntfy - pointer to response
******************************************************************************/
static void ZCL_ConfigureReportingResp2(ZCL_Notify_t *ntfy)
{
  (void)ntfy;
}

// eof haClusters.c
