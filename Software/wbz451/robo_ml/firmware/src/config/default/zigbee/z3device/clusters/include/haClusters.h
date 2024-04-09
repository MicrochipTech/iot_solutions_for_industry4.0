/*******************************************************************************
  Application HA Clusters Header File

  Company:
    Microchip Technology Inc.

  File Name:
    haClusters.h

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

#ifndef _HACLUSTERS_H
#define _HACLUSTERS_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zdo/include/zdo.h>
#include <z3device/common/include/appConsts.h>
/******************************************************************************
                    Defines section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
typedef void (*AttibuteReadCallback_t)(void *data);
typedef void (*AttributeWriteCallback_t)(void);
typedef void (*ConfigureReportResp_t)(ZCL_Notify_t *ntfy);

typedef void (*ZclNtfyCallback_t)(ZCL_Notify_t *ntfy);
typedef void (*BindFinishedCallback_t)(Endpoint_t ResponentEp, ClusterId_t id);
typedef void (*StartIdentifyingCb_t)(uint16_t time, void (*cb)(void));

typedef struct
{
  Endpoint_t srcEndpoint;
  uint8_t remoteServersCnt;   //client clusters
  uint8_t remoteClientsCnt;   //server clusters
  uint16_t groupId;
  ClusterId_t* remoteServers;
  ClusterId_t* remoteClients;
  BindFinishedCallback_t callback;
  StartIdentifyingCb_t startIdentifyingFn;
} AppBindReq_t;

typedef struct
{
   ZDO_ZdpReq_t        zdpReq;
   AppBindReq_t        *appBindReq[APP_ENDPOINTS_AMOUNT];
} DescModeManagerMem_t;
/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Fills ZCL Request structure

\param[out] req     - pointer to zcl command request;
\param[in]  command - command id;
\param[in] size     - the size of request payload
******************************************************************************/
void fillCommandRequest(ZCL_Request_t *req, uint8_t command, uint8_t size, Endpoint_t srcEp);

/**************************************************************************//**
\brief Fills zcl addressing structure

\param[out] addressing - pointer to the structure to be filled;
\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  cluster    - cluster id
******************************************************************************/
void fillDstAddressing(ZCL_Addressing_t *addressing, APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, ClusterId_t cluster);

/**************************************************************************//**
\brief Fills zcl addressing structure

\param[out] addressing - pointer to the structure to be filled;
\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  cluster    - cluster id
******************************************************************************/
void fillDstAddressingServer(ZCL_Addressing_t *addressing, APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, ClusterId_t cluster);

/**************************************************************************//**
\brief Gets free command buffer

\returns pointer to a command buffer
******************************************************************************/
ZCL_Request_t *getFreeCommand(void);

/**************************************************************************//**
\brief Fills ZCL Addressing structure

\param[out] srcAddressing - pointer to zcl addressing request of source node;
\param[in]  dstAddressing - pointer to zcl addressing request of destination node;
\param[in]  side          - cluster side of recipient side
******************************************************************************/
void fillDstAddressingViaSourceAddressing(ZCL_Addressing_t *srcAddressing, ZCL_Addressing_t *dstAddressing, uint8_t side);
/*******************************************************************************
\brief Sends the simple Descriptor request

\param[in] addr- nwk Address of Interest
\param[in] ep  - Endpoint for which the simple desctiptor is requested
******************************************************************************/
void zdpSimpleDescReq(ShortAddr_t addr,uint8_t ep);
/*******************************************************************************
\brief Sends the Match Descriptor request

\param[in] addr - nwk Address of Interest
\param[in] ep   - Endpoint which requests Match desctiptor
******************************************************************************/
void zdpMatchDescReq(ShortAddr_t addr,uint8_t ep);

/*******************************************************************************
\brief Sends the Active EP req request

\param[in] dstaddr - short address of destination node;
\param[in] nwkAddrofInterest - nwk Address of Interest;
*****************************************************************************/
void zdpActiveEpReq(ShortAddr_t dstaddr, ShortAddr_t nwkAddrofInterest);

/*******************************************************************************
\brief Sends the nwk addr req request

\param[in] dstaddr - short address of destination node;
\param[in] ieeeAddrOfInterest - IEEE Address of Interest;
\param[in] reqType - Request type for the command;
*****************************************************************************/
void zdpNwkAddrReq(ShortAddr_t dstaddr, ExtAddr_t ieeeAddrOfInterest, uint8_t reqType);

/*******************************************************************************
\brief Sends the ieee addr req request

\param[in] dstaddr - short address of destination node;
\param[in] nwkAddrofInterest - nwk Address of Interest;
\param[in] reqType - Request type for the command;
*****************************************************************************/
void zdpIeeeAddrReq(ShortAddr_t dstaddr, ShortAddr_t nwkAddrofInterest, uint8_t reqType);

/*******************************************************************************
\brief Sends the Node Descriptor request

\param[in] dstaddr - short address of destination node
\param[in] nwkAddrofInterest - nwk Address of Interest;
*****************************************************************************/
void zdpNodeDescReq(ShortAddr_t dstaddr, ShortAddr_t nwkAddrofInterest);

/**************************************************************************//**
\brief Sends the Management Leave request

\param[in] dstAddr        - short address of destination node;
\param[in] extAddr        - extended address of destination node;
\param[in] rejoin         - rejoin if TRUE indicates the device will rejoin immediately after leaving
\param[in] removeChildren - removeChildren if TRUE indicates also the children of this device are removed
******************************************************************************/
void zdpMgmtLeaveReq(uint16_t dstAddr, ExtAddr_t extAddr, bool rejoin, bool removeChildren);

/**************************************************************************//**
\brief Sends the Network Leave command

\param[in] extAddr        - extended address of destination node;
\param[in] rejoin         - rejoin if TRUE indicates the device will rejoin immediately after leaving
\param[in] removeChildren - removeChildren if TRUE indicates also the children of this device are removed
******************************************************************************/
void nwkLeaveCommand(ExtAddr_t extAddr, bool rejoin, bool removeChildren);

/**************************************************************************//**
\brief Sends ZDP Bind request

\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  extAddr    - Extended address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  srcEp      - endpoint number of source node;
\param[in]  clusterid  - cluster id
******************************************************************************/
void zdpBindReq(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, Endpoint_t ep, Endpoint_t srcEp, ClusterId_t clusterId);

/**************************************************************************//**
\brief Sends ZDP Unbind request with source address and destination endpoint.

\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  extAddr    - Extended address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  srcEp      - endpoint number of source node;
\param[in]  clusterid  - cluster id
******************************************************************************/
void zdpUnBindReq(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, Endpoint_t ep, Endpoint_t srcEp, ClusterId_t clusterId);

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
void zdpBindReqWithSrcAddrDestEndpoint(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, ExtAddr_t extAddrSrc, Endpoint_t epSrc, Endpoint_t epDst, Endpoint_t srcEp, ClusterId_t clusterId);

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
void zdpUnBindReqWithSrcAddrDestEndpoint(APS_AddrMode_t mode, ShortAddr_t addr, ExtAddr_t extAddr, ExtAddr_t extAddrSrc, Endpoint_t epSrc, Endpoint_t epDst, Endpoint_t srcEp, ClusterId_t clusterId);

/**************************************************************************//**
\brief Sends Management Bind request

\param[in] shortAddr        - short address of destination node;
\param[in] startIndex       - Start Index
******************************************************************************/
void zdpMgmtBindReq(uint16_t shortAddr, uint8_t startIndex);

/**************************************************************************//**
\brief Sends Management LQI request

\param[in] shortAddr        - short address of destination node;
\param[in] startIndex        - Start Index
******************************************************************************/
void zdpMgmtLqiReq(uint16_t shortAddr, uint8_t startIndex);
/**************************************************************************//**
\brief Sends configure reporting request to notify another device about reporting

\param[in] endpoint  - destination endpoint;
\param[in] clusterId - cluster id;
\param[in] attrId    - attribute id;
]param[in] period    - report period
******************************************************************************/
void sendConfigureReportingToNotify(Endpoint_t srcEndpoint, Endpoint_t dstEndpoint, ClusterId_t clusterId, ZCL_AttributeId_t attrId, ZCL_ReportTime_t period, ConfigureReportResp_t configureRespCb);

/**************************************************************************//**
\brief Indication of read attribute response

\param[in] resp - pointer to response
******************************************************************************/
void ZCL_ReadAttributeResp(ZCL_Notify_t *ntfy);

/**************************************************************************//**
\brief Sends a read attribute request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] cluster - cluster identifier;
\param[in] attr    - attribute identifier;
\param[in] cb      - response callback;

\return none
******************************************************************************/
void readAttribute(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster, uint16_t attr, ZclNtfyCallback_t cb);

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
                   uint16_t cluster, uint16_t startAttrId, uint8_t count, ZclNtfyCallback_t cb);

/**************************************************************************//**
\brief Indication of write attribute response

\param[in] resp - pointer to response
******************************************************************************/
void ZCL_WriteAttributeResp(ZCL_Notify_t *ntfy);

/**************************************************************************//**
\brief Sends a write attribute request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] cluster - cluster identifier;
\param[in] type    - type identifier of data;
\param[in] attr    - attribute identifier;
\param[in] data    - pointer to value to be written;
\param[in] size    - size of the data
\param[in] cb      - response callback;

\return none
******************************************************************************/
void writeAttribute(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster, uint8_t type, uint16_t attr, void *data, uint8_t size, ZclNtfyCallback_t cb);

/**************************************************************************//**
\brief Indication of write attribute response

\param[in] resp - pointer to response
******************************************************************************/
void ZCL_WriteAttributeNoResp(ZCL_Notify_t *ntfy);

/**************************************************************************//**
\brief Sends a write attribute no response request to another device

\param[in] mode    - addressing mode;
\param[in] addr    - short destination address;
\param[in] ep      - destination endpoint identifier;
\param[in] cluster - cluster identifier;
\param[in] type    - type identifier of data;
\param[in] attr    - attribute identifier;
\param[in] data    - pointer to value to be written;
\param[in] size    - size of the data
\param[in] cb      - response callback;

\return none
******************************************************************************/
void writeAttributeNoResp(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster, uint8_t type, uint16_t attr, void *data, uint8_t size, ZclNtfyCallback_t cb);
/**************************************************************************//**
\brief Sends the Configure Reporting for cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp- source endpoint;
\param[in] cluster - cluster identifier;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
\param[in] min  - the minimum reporting interval;
\param[in] max  - the maximum reporting interval
******************************************************************************/
void configureReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max);

/**************************************************************************//**
\brief Sends the Configure Reporting for given cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
\param[in] min  - the minimum reporting interval;
\param[in] max  - the maximum reporting interval
******************************************************************************/
void sendConfigureReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, ClusterId_t cluster,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max);


/**************************************************************************//**
\brief Sends the Configure Reporting  with report change for level control cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] srcEp- source endpoint;
\param[in] cluster - cluster identifier;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
\param[in] min  - the minimum reporting interval;
\param[in] max  - the maximum reporting interval
\param[in] *repChange - pointer to the reportableChange value
******************************************************************************/
void configureReportingWithRC(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster,
  ZCL_AttributeId_t attrId, uint8_t attrType, ZCL_ReportTime_t min, ZCL_ReportTime_t max,
  void *repChange);

/**************************************************************************//**
\brief Sends the Read Reporting for cluster

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep   - destination endpoint;
\param[in] cluster - cluster identifier;
\param[in] attrId - attribute id;
\param[in] attrType - attribute type
******************************************************************************/
void readReporting(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t cluster,
  ZCL_AttributeId_t attrId);

/**************************************************************************//**
\brief Set the DisableDefaultResponse value for the default response

\param[in] bitValue - bit value to set in default response
******************************************************************************/
void setZclDefaultResponseBit(uint8_t value);

/**************************************************************************//**
\brief Get the DisableDefaultResponse value for the default response

\return Bit value to set in default response
******************************************************************************/
uint8_t getZclDefaultResponseBit(void);

/**************************************************************************//**
\brief Temporary function set key

\param[in] option - option for key type
******************************************************************************/
void tempfuctionsetkey(uint8_t option);
#endif // _CLUSTER_H

// eof clusters.h
