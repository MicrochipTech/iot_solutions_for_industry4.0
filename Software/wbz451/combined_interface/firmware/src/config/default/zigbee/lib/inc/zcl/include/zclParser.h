/*******************************************************************************
  Zigbee Cluster Library Parser Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclParser.h

  Summary:
    The header file describes the ZCL Parser interface.

  Description:
    The file describes the interface and types of ZCL Parser.
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


#ifndef _ZCLPARSER_H
#define _ZCLPARSER_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/zcl.h>
#include <zcl/include/zclMemoryManager.h>
#include <systemenvironment/include/sysQueue.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
/*ZCL Header Frame Type sub-field value*/
#define ZCL_FRAME_CONTROL_FRAME_TYPE_UNIVERSAL_COMMAND            0x00
#define ZCL_FRAME_CONTROL_FRAME_TYPE_SPECIFIC_COMMAND             0x01

/*ZCL Header Manufacturer Specific sub-field value*/
#define ZCL_FRAME_CONTROL_MANUFACTURER_NONSPECIFIC                0x00
#define ZCL_FRAME_CONTROL_MANUFACTURER_SPECIFIC                   0x01

#define ZCL_FRAME_SIMPLE_HEADER_LENGTH                            3
#define ZCL_FRAME_HEADER_MANUFACTURER_CODE_LENGTH                 2
#define ZCL_FRAME_HEADER_WITH_MANUFACTURER_CODE_LENGTH            \
        (ZCL_FRAME_SIMPLE_HEADER_LENGTH + ZCL_FRAME_HEADER_MANUFACTURER_CODE_LENGTH)

#define ZCL_STANDARD_REQ_TYPE                                     ZCL_FRAME_CONTROL_FRAME_TYPE_UNIVERSAL_COMMAND
#define ZCL_SPECIAL_REQ_TYPE                                      ZCL_FRAME_CONTROL_FRAME_TYPE_SPECIFIC_COMMAND

#ifndef ZCL_MAX_STANDARD_DATA_TYPE_SIZE
#define ZCL_MAX_STANDARD_DATA_TYPE_SIZE                           8
#endif

#define ZCL_DATA_TYPE_DISCRETE_KIND                               0x00
#define ZCL_DATA_TYPE_ANALOG_KIND                                 0x01
#define ZCL_DATA_TYPE_STRUCTURED_KIND                             0x02

/******************************************************************************
                   Types section
******************************************************************************/
BEGIN_PACK
typedef struct PACK
{
  union PACK
  {
    struct PACK
    {
      LITTLE_ENDIAN_OCTET(5,(
        uint8_t frameType             :2, //Frame type sub-field
        uint8_t manufacturerSpecific  :1, //Manufacturer specific sub-field
        uint8_t direction             :1, //Direction sub-field
        uint8_t defaultResponse       :1, //Disable default response sub-field
        uint8_t reserved              :3  //Reserved bits. Must have a zero value
      ))
    };
    uint8_t uint8;
  };
} ZclFrameControlField_t;

typedef struct PACK
{
  ZclFrameControlField_t  frameControl;
  uint16_t                manufacturerCode;
  uint8_t                 sequenceNumber;
  uint8_t                 commandId;
} ZclFrameHeader_t;

/******************************************************************************
 Read Attributes commands
******************************************************************************/
/** \brief ZCL read attributes command record */
typedef struct PACK
{
  uint16_t attributeId;
} ZclReadAttributesRecord_t;

/** \brief ZCL Read attributes command payload */
typedef struct PACK
{
  ZclReadAttributesRecord_t records[1];
} ZclReadAttributesCommand_t;

typedef struct PACK
{
  uint8_t   elementType;
  uint16_t  elementsAmount;
  struct PACK
  {
    uint8_t   value[1];
  } elements[1];
} ZclReadAttributesResponseArraySetBagValue_t;

typedef struct PACK
{
  uint16_t  elementsAmount;
  struct PACK
  {
    uint8_t   elementType;
    uint8_t   value[1];
  } elements [1];
} ZclReadAttributesResponseStructValue_t;

/** \brief ZCL read attributes response command record */
typedef struct PACK
{
  ZCL_AttributeId_t attributeId;
  uint8_t           status;
  uint8_t           type;
  union PACK
  {
    uint8_t         simpleValue[1];
    ZclReadAttributesResponseArraySetBagValue_t arraySetBagValue;
    ZclReadAttributesResponseStructValue_t      structValue;
  };
} ZclReadAttributesResponseRecord_t;

END_PACK

typedef struct
{
  uint8_t   headerLength;
  uint8_t   payloadLength;
  uint8_t   frameType;
  uint8_t   direction;
  uint8_t   defaultResponse;
  uint8_t   manufacturerSpecific;
  uint16_t  manufacturerCode;
  uint8_t   sequenceNumber;
  uint8_t   commandId;
  uint8_t   *header;
  uint8_t   *payload;
} ZclFrameDescriptor_t;

typedef struct
{
  ZclFrameDescriptor_t *frameDescriptor;
  APS_DataInd_t        *ind;
  ZCL_Status_t          commandStatus;
  bool                  apsSecurity;
  bool                  relevantResponse;
} ZclAuxParseData_t;

/*************************************************************************//**
  \brief Reset parser queue and clear memory.
*****************************************************************************/
void zclParserInit(void);

/**************************************************************************//**
\brief Form zcl header.

\param[in] - dataReq - pointer to data request;
\param[in] - reqType - type of the request;
\param[in] - direction - cluster\server side;
\param[in] - commandId - zcl command identification;
\param[in] - defaultResponse - presence or absence of the default responde;
\param[in] - manufacSpecCode - manufacturer specific code;
\param[in] - sequenceNumber - next sequence number;
\return header length
******************************************************************************/
uint8_t zclFormRequest(APS_DataReq_t *dataReq,
                       uint8_t reqType,
                       uint8_t direction,
                       uint8_t commandId,
                       uint8_t defaultResponse,
                       uint16_t manufacSpecCode,
                       uint8_t sequenceNumber);

/*************************************************************************//**
  \brief Response has been received.

  \param[in] auxData - pointer to structure with command payload and
  descriptor of received command frame.
  \param[in] req - pointer to the request, which is the reason of the response.
*****************************************************************************/
void zclResponseInd(ZclAuxParseData_t *auxData, ZCL_Request_t *req);

#ifdef _ZCL_REPORTING_SUPPORT_
/*************************************************************************//**
\brief Routine of Read Reporting Configuration Command.

\param[in] apsDataInd - pointer to aps payload
\param[in] frameDescriptor - pointer to parsed data structure from payload

\returns true if corresponding request may be removed, false otherwise
*****************************************************************************/
bool zclReadReportingConfigurationHandler(APS_DataInd_t *apsDataInd, ZclFrameDescriptor_t *frameDescriptor);

/*************************************************************************//**
\brief Routine of Configure Reporting Command.

\param[in] apsDataInd - pointer to aps payload
\param[in] frameDescriptor - pointer to parsed data structure from payload

\returns true if corresponding request may be removed, false otherwise
*****************************************************************************/
bool zclConfigureReportingHandler(APS_DataInd_t *apsDataInd, ZclFrameDescriptor_t *frameDescriptor);

/*************************************************************************//**
  \brief Report has been received.

  \param[in] apsData - report payload
  \param[in] frameDesc - descriptor of received report frame
*****************************************************************************/
void zclReportInd(APS_DataInd_t *apsData, ZclFrameDescriptor_t *frameDesc);
#endif // _ZCL_REPORTING_SUPPORT_

/*************************************************************************//**
  \brief Special cluster command has been received.

  \param[in] auxData - pointer to structure with command payload and
  descriptor of received command frame.
*****************************************************************************/
void zclCommandInd(ZclAuxParseData_t *auxData);

/*************************************************************************//**
  \brief The attribute has been read or written.

  \param[in] apsDataInd - attribute payload
  \param[in] incomingFrameInfo - information from the header of the incoming frame
  \param[in] event - event type
  \param[in] attributeId - attribute identifier
*****************************************************************************/
void zclAttributeEventInd(const APS_DataInd_t *apsDataInd,
                          const ZclFrameDescriptor_t *incomingFrameInfo,
                          ZCL_AttributeEvent_t event,
                          ZCL_AttributeId_t attributeId);

/*************************************************************************//**
  \brief Configuration has been received.

  \param[in] apsData - configuration payload
  \param[in] frameDesc - descriptor of received report frame
*****************************************************************************/
void zclConfigurationInd(APS_DataInd_t *apsData, ZclFrameDescriptor_t *frameDesc);

/*************************************************************************//**
  \brief Indication from CAPS.

  \param[in] ind - buffer for data indication.
*****************************************************************************/
void zclDataInd(APS_DataInd_t *ind);

/*************************************************************************//**
  \brief     Security Type get by Cluster Id function and by endpointId, on which
             was registered cluster.
             Returns Security Type should be used with ClusterId specified
  \param[in] clusterId - cluster identifier
  \param[in] endpointId - end point identifier
  \param[in] mspSupport - manufacturerSpecific bit in the header
  \return    ZCL_NETWORK_KEY_CLUSTER_SECURITY - NWK Key Security should be used
             ZCL_APPLICATION_LINK_KEY_CLUSTER_SECURITY - APS Link Key Security
             shoud be used.
             If cluster is unknown, security key will be determined by security mode,
             i.e. ZCL_NETWORK_KEY_CLUSTER_SECURITY for Standard Security,
                  ZCL_APPLICATION_LINK_KEY_CLUSTER_SECURITY for High Security.
*****************************************************************************/
uint8_t zclGetSecurityTypeByClusterId(ClusterId_t clusterId, Endpoint_t endpointId, bool mspSupport);

/**************************************************************************//**
  \brief Get next registered ZCL endpoint descriptor by previous.

  \param[in] prev - previous ZCL endpoint descriptor pointer.It is must be non NULL
                    sequential access required if. And it is must be NULL the
                    first descriptor as registered endpoints queue head element
                    access required if.

  \return Valid ZCL endpoint descriptor pointer descriptor found if,
           NULL - other case.
 ******************************************************************************/
ZCL_DeviceEndpoint_t* zclNextEndpoint(ZCL_DeviceEndpoint_t *prev);

/*************************************************************************//**
  \brief Find endpoint descriptor by endpoint id.

  \param[in] endpointId - endpoint unique identifier.
  \return endpoint descriptor if found, NULL otherwise.
*****************************************************************************/
ZCL_DeviceEndpoint_t *zclGetEndpoint(Endpoint_t endpointId);
#endif  //#ifndef _ZCLPARSER_H

//eof zclParser.h
