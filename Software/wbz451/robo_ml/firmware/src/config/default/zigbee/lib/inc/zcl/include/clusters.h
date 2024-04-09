/*******************************************************************************
  Zigbee Clusters Header File

  Company:
    Microchip Technology Inc.

  File Name:
    clusters.h

  Summary:
    The header file defines macros used to describe ZCL clusters.

  Description:
    The file contains definitions of some macro functions, constants and types used
    to define ZCL clusters. It also includes an enumeration of IDs of all clusters
    supported by BitCloud.
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


#ifndef _CLUSTERS_H
#define _CLUSTERS_H

#include <zcl/include/zcl.h>
#include <systemenvironment/include/sysEndian.h>
#include <systemenvironment/include/sysUtils.h>

/******************************************************************************
                   Define(s) section
******************************************************************************/
/*! \brief Used as means of contraction to fill the field corresponding
to an attribute in the attributes structure instance of a cluster

The macro function is used in clusters' definition files.
Attributes structure contains one field for each attribute of a cluster.
Attribute fields are themselves structure with the same fields. Reportable
attribute have more fields.
*/
#define DEFINE_ATTRIBUTE(name, props, aid, atype) \
  .name = {.id = aid, .type = atype, .properties = props}

/*! \brief Used as means of contraction to fill the field corresponding
to an attribute in the attributes structure instance of a cluster

The macro function is used in clusters' definition files.
Attributes structure contains one field for each attribute of a cluster.
Attribute fields are themselves structure with the same fields. Attribute with boundary check and reportable
have more fields.
*/
#define DEFINE_ATTRIBUTE_WITH_BOUNDARY(name, props, aid, atype, minValue, maxValue) \
  .name = {.id = aid, .type = atype, .properties = ZCL_BOUNDARY_CHECK | props, .minVal = minValue, .maxVal = maxValue}

/*! \brief Used as means of contraction to fill the attribute field of the
reportable attribute with a given name in the attributes structure instance
of a cluster

A reportable attribute (one that can be configured for automatical reporting)
includes additional fields - min and max reporting intervals.
*/
#define DEFINE_REPORTABLE_ATTRIBUTE(name, props, aid, atype, minReport, maxReport) \
  .name = {.id = aid, .type = atype, .properties = ZCL_REPORTABLE_ATTRIBUTE | (props), .minReportInterval = minReport, .maxReportInterval = maxReport}

/*! \brief Used as means of contraction to fill the attribute field of the
reportable attribute with a given name in the attributes structure instance
of a cluster

A reportable attribute (one that can be configured for automatical reporting)
includes additional fields - min and max reporting intervals.
*/
#define DEFINE_REPORTABLE_ATTRIBUTE_WITH_BOUNDARY(name, props, aid, atype, minReport, maxReport, minValue, maxValue) \
  .name = {.id = aid, .type = atype, .properties = ZCL_BOUNDARY_CHECK | ZCL_REPORTABLE_ATTRIBUTE | (props), .minReportInterval = minReport, .maxReportInterval = maxReport, .minVal = minValue, .maxVal = maxValue}

/*! \brief Used as means of contraction to fill command's option when defining
a cluster's command

The macro function is used in clusters' definition files with the DEFINE_COMMAND()
macro, which itself is used to form the macro function defining all cluster's
commands at once.
*/
#define COMMAND_OPTIONS(cldirection, clwaitingResponse, clackRequest) \
  {.direction = ZCL_FRAME_CONTROL_DIRECTION_##cldirection, .waitingResponse = clwaitingResponse, \
   .ackRequest = clackRequest}

/*! \brief Used as means of contraction to fill the field corresponding to a
command in the commands structure instance of a cluster

A commands structure consists of fields, one per each command supported by the cluster.
*/
#define DEFINE_COMMAND(cname, cid, coptions, cind) \
  .cname = {.id = cid, .options = coptions, cind}

/*! \brief Fills the field corresponding to an attribute of the array type in
the attributes structure instance of a cluster
*/
#define DEFINE_ARRAY(name, props, aid, etype, count)  \
  .name = {.id = aid, .type = ZCL_ARRAY_DATA_TYPE_ID, .properties = props & ~(ZCL_REPORTABLE_ATTRIBUTE), .value = {.type = etype, .cnt = count}}

/*! \brief Fills the field corresponding to an attribute of the set type in
the attributes structure instance of a cluster
*/
#define DEFINE_SET(name, props, aid, etype, count)  \
  .name = {.id = aid, .type = ZCL_SET_DATA_TYPE_ID, .properties = props & ~(ZCL_REPORTABLE_ATTRIBUTE), .value = {.type = etype, .cnt = count}}

/*! \brief Fills the field corresponding to an attribute of the bag type in
the attributes structure instance of a cluster
*/
#define DEFINE_BAG(name, props, aid, etype, count)  \
  .name = {.id = aid, .type = ZCL_BAG_DATA_TYPE_ID, .properties = props & ~(ZCL_REPORTABLE_ATTRIBUTE), .value = {.type = etype, .cnt = count}}

/*! \brief Fills the field corresponding to an attribute of the structure type in
the attributes structure instance of a cluster
*/
#define DEFINE_STRUCTURE(name, props, aid, count)  \
  .name = {.id = aid, .type = ZCL_STRUCTURE_DATA_TYPE_ID, .properties = props & ~(ZCL_REPORTABLE_ATTRIBUTE), .value = {.cnt = count}}

/* ZCL command ack request field */
#define ZCL_COMMAND_NO_ACK 0 //!< APS acknowledgement is not requested
#define ZCL_COMMAND_ACK    1 //!< APS acknowledgement is requested

#define ZCL_SERVER_CLUSTER_TYPE  0 //!< Server part of a cluster
#define ZCL_CLIENT_CLUSTER_TYPE  1 //!< Client part of a cluster

/* ZCL Header Direction sub-field value */
#define ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER    0x00 //!< A command will be sent from client side to server side
#define ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT    0x01 //!< A command will be sent from server side to client side

/* ZCL cluster side possible values */
#define ZCL_CLUSTER_SIDE_SERVER ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER //!< To define a cluster of a server side
#define ZCL_CLUSTER_SIDE_CLIENT ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT //!< To define a cluster of a client side

/*! A value to disable default response for a cluster's command*/
#define ZCL_FRAME_CONTROL_DISABLE_DEFAULT_RESPONSE      0x01
/*! A value to enable default response for a cluster's command*/
#define ZCL_FRAME_CONTROL_ENABLE_DEFAULT_RESPONSE       0x00

/*! A relevant response command exists for this command */
#define ZCL_THERE_IS_RELEVANT_RESPONSE                  0x01
/*! A relevant response command does not exist for this command */
#define ZCL_THERE_IS_NO_RELEVANT_RESPONSE               0x00
/*! Response reqiurement is controlled by command payload */
#define ZCL_RESPONSE_CONTROLLED_BY_PAYLOAD              0x02

/*! Network key enryption is used to secure commands */
#define ZCL_NETWORK_KEY_CLUSTER_SECURITY                0
/*! Encryption with link keys is used to secure commands */
#define ZCL_APPLICATION_LINK_KEY_CLUSTER_SECURITY       1


/* Bits for declaring properties bitmask of attribute */
#define ZCL_READWRITE_ATTRIBUTE  0U //!< Attribute can be read and written remotely
#define ZCL_REPORTABLE_ATTRIBUTE 1U //!< Attribute can be reported
#define ZCL_READONLY_ATTRIBUTE   2U //!< Attribute can not be written by remote nodes
#define ZCL_REPORTING_CONFIGURED 4U //!< Attribute is configured for reporting
#define ZCL_ON_CHANGE_REPORT     8U //!< Attribute should be reported using minimum reporting time
#define ZCL_BOUNDARY_CHECK      16U //!< Attribute whose value needs to be checked for boundary check
#define ZCL_CHECK_OTHER_ATTR    32U //!< Attrbute vlue boundary check with other attribute value

#define  ZCL_DEFAULT_CLUSTER_SECURITY    ZCL_NETWORK_KEY_CLUSTER_SECURITY

/*************************************************************************//**
  \brief Clusters IDs' definitions. The list comprises all clusters supported in BitCloud.
*****************************************************************************/
enum
{
  /* General clusters defined by ZCL Specification */
  BASIC_CLUSTER_ID = CCPU_TO_LE16(0x0000),                            //!<Basic cluster Id
  POWER_CONFIGURATION_CLUSTER_ID = CCPU_TO_LE16(0x0001),              //!<Power configuration cluster Id
  IDENTIFY_CLUSTER_ID = CCPU_TO_LE16(0x0003),                         //!<Identify cluster Id
  GROUPS_CLUSTER_ID = CCPU_TO_LE16(0x0004),                           //!<Groups cluster Id
  SCENES_CLUSTER_ID = CCPU_TO_LE16(0x0005),                           //!<Scenes cluster Id
  ONOFF_CLUSTER_ID = CCPU_TO_LE16(0x0006),                            //!<OnOff cluster id
  ONOFF_SWITCH_CONFIGURATION_CLUSTER_ID = CCPU_TO_LE16(0x0007),       //!<OnOff Switch Configuration cluster id
  LEVEL_CONTROL_CLUSTER_ID = CCPU_TO_LE16(0x0008),                    //!<Level Control cluster id
  ALARMS_CLUSTER_ID = CCPU_TO_LE16(0x0009),                            //!<Alarm cluster id
  TIME_CLUSTER_ID = CCPU_TO_LE16(0x000a),                             //!<Time cluster Id
  OTAU_CLUSTER_ID = CCPU_TO_LE16(0x0019),                             //!<OTAU cluster Id
  GREEN_POWER_CLUSTER_ID = CCPU_TO_LE16(0x0021),                      //!<Green power cluster id
  THERMOSTAT_CLUSTER_ID = CCPU_TO_LE16(0x0201),                       //!<Thermostat cluster Id
  FAN_CONTROL_CLUSTER_ID = CCPU_TO_LE16(0x0202),                       //!<Fan control cluster Id
  THERMOSTAT_UI_CONF_CLUSTER_ID = CCPU_TO_LE16(0x0204),               //!<Thermostat ui conf cluster Id
  /* Lighting */
  COLOR_CONTROL_CLUSTER_ID = CCPU_TO_LE16(0x0300),                    //!<Color Control cluster id
  ILLUMINANCE_MEASUREMENT_CLUSTER_ID = CCPU_TO_LE16(0x0400),          //!<Illuminance Sensing cluster id  
  TEMPERATURE_MEASUREMENT_CLUSTER_ID = CCPU_TO_LE16(0x0402),          //!<Temperature measurement cluster id
  HUMIDITY_MEASUREMENT_CLUSTER_ID = CCPU_TO_LE16(0x0405),             //!<Humidity measurement cluster id
  OCCUPANCY_SENSING_CLUSTER_ID = CCPU_TO_LE16(0x0406),                //!<Occupancy Sensing cluster id
  /* Security & Safety */
  IAS_ZONE_CLUSTER_ID = CCPU_TO_LE16(0x0500),                         //!<IAS Zone Cluster id
  IAS_ACE_CLUSTER_ID = CCPU_TO_LE16(0x0501),                          //!<IAS ACE Cluster id
  GENERIC_TUNNEL_CLUSTER_ID = CCPU_TO_LE16(0x0600),                   //!<Generic tunnel cluster Id
  BACNET_PROTOCOL_TUNNEL_CLUSTER_ID = CCPU_TO_LE16(0x0601),           //!<BACnet protocol tunnel cluster Id
  /* Smart Energy Profile specific clusters */
  PRICE_CLUSTER_ID = CCPU_TO_LE16(0x0700),                            //!<Price cluster Id
  DEMAND_RESPONSE_AND_LOAD_CONTROL_CLUSTER_ID = CCPU_TO_LE16(0x0701), //!<Demand Response and Load Control cluster Id
  SIMPLE_METERING_CLUSTER_ID = CCPU_TO_LE16(0x0702),                  //!<Simple Metering cluster Id
  MESSAGE_CLUSTER_ID = CCPU_TO_LE16(0x0703),                          //!<Message Cluster Id
  ZCL_SE_TUNNEL_CLUSTER_ID = CCPU_TO_LE16(0x0704),                    //!<Smart Energy Tunneling (Complex Metering)
  ZCL_KEY_ESTABLISHMENT_CLUSTER_ID = CCPU_TO_LE16(0x0800),            //!<ZCL\INCLUDE\ZCL Key Establishment Cluster Id
  DIAGNOSTICS_CLUSTER_ID = CCPU_TO_LE16(0x0b05),                      //!<Diagnostics cluster Id
  /* Light Link Profile clusters */
  ZLL_COMMISSIONING_CLUSTER_ID = CCPU_TO_LE16(0x1000),                //!<ZLL Commissioning Cluster Id
  /* Manufacturer specific clusters */
  LINK_INFO_CLUSTER_ID = CCPU_TO_LE16(0xFF00),                        //!<Link Info cluster id
  /*Light & Occupancy Device based application clusters */
  BALLAST_CONFIGURATION_CLUSTER_ID = CCPU_TO_LE16(0x0301),      //!<Ballast Configuration cluster Id
  /* manudacturer specifc cluster starting id */
  MANUFAC_SPECIFIC_CLUSTER_ID_START = CCPU_TO_LE16(0xFC00),
  /* manudacturer specifc cluster end id */
  MANUFAC_SPECIFIC_CLUSTER_ID_END = CCPU_TO_LE16(0xFFFF)
};

/******************************************************************************
                   Types section
******************************************************************************/
/*************************************************************************//**
\brief A type for setting options of a ZCL cluster's command
*****************************************************************************/
typedef struct
{
  uint8_t   direction          :1; //!< Direction: etiher ::ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER or ::ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT
  uint8_t   defaultResponse    :1; //!< Should be ::ZCL_FRAME_CONTROL_ENABLE_DEFAULT_RESPONSE if the ZCL default response is required and ::ZCL_FRAME_CONTROL_DISABLE_DEFAULT_RESPONSE if not
  uint8_t   waitingResponse    :2; //!< Should be ::ZCL_THERE_IS_RELEVANT_RESPONSE if there is other relevant response specified for the command and ::ZCL_THERE_IS_NO_RELEVANT_RESPONSE otherwise
  uint8_t   ackRequest         :1; //!< Specifies if APS ACK if requested for the command
  uint8_t   reserved           :3; //!< Reserved for future use
} ZclCommandOptions_t;

/*************************************************************************//**
\brief ZCL Cluster command descriptor as command Id and options
*****************************************************************************/
typedef struct
{
  ZCL_CommandId_t id;
  ZclCommandOptions_t options;
  ZCL_Status_t (*callback)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
} ZclCommand_t;

BEGIN_PACK
/*************************************************************************//*
Layouts for supporting ZCL structured types
*****************************************************************************/
typedef struct PACK
{
  uint8_t type;                       //!< Element type
  uint8_t value[1];                   //!< Element value
} ZclStructureElement_t;

typedef struct PACK
{
  uint16_t cnt;                       //!< Number of elements
  ZclStructureElement_t elements[1];  //!< Elements
} ZclStructure_t;

typedef struct PACK
{
  uint8_t type;                       //!< Element type
  uint16_t cnt;                       //!< Number of elements
  uint8_t elements[1];                //!< Elements
} ZclArraySetBag_t;

/*************************************************************************//**
\brief Extra fields of reportable attribute descriptor
*****************************************************************************/
typedef struct PACK
{
  ZCL_ReportTime_t reportCounter; //!< For internal use only
  ZCL_ReportTime_t minReportInterval; //!< Minimum reporting interval field value
  ZCL_ReportTime_t maxReportInterval; //!< Maximum reporting interval field value
} ZclReportableAttributeTail_t;
END_PACK

//\cond internal
/***************************************************************************//**
\brief Type describing image of a ZCL cluster
*******************************************************************************/
#if APP_CLUSTERS_IN_FLASH == 1
typedef struct
{
  ZCL_ClusterPartFlashImage_t partFlash;
  ZCL_ClusterPartRam_t        partRam;
  ZclCommand_t                commandImage;
  ZCL_ClusterPartFlash_t     *partFlashAddr;
  ZCL_ClusterPartRam_t       *partRamAddr;
  FLASH_PTR ZclCommand_t     *commandsAddr;
  bool                        needSynchronize;
} zclClusterImage_t;
//\endcond
#endif //APP_CLUSTERS_IN_FLASH == 1
#endif // _CLUSTERS_H
