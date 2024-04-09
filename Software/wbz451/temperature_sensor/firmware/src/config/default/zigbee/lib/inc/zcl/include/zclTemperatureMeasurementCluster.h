/*******************************************************************************
  Zigbee Cluster Library Temperature Measurement Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclTemperatureMeasurement.h

  Summary:
    The file describes the types and interface of the 
    Temperature Measurement cluster.

  Description:
    The file describes the types and interface of the 
    Temperature Measurement cluster.
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



#ifndef _ZCLTEMPERATUREMEASUREMENT_H_
#define _ZCLTEMPERATUREMEASUREMENT_H_

/*******************************************************************************
                   Includes section
*******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/
/**
* \brief server attribute values
*/
#define TEMPERATURE_MEASUREMENT_MEASURED_VALUE_UNKNOWN               0x8000

/**
* \brief server attributes amount
*/
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 5

/**
* \brief server commands amount
*/
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_COMMANDS_AMOUNT 0

/**
* \brief client attributes amount
*/
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT 1

/**
* \brief client commands amount
*/
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_COMMANDS_AMOUNT 0

//Attribute Ids of Basic Cluster Information
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_VERSION_ATTRIBUTE_ID                          CCPU_TO_LE16(0xfffd)
/**
* \brief Supported attribue id
*/
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MEASURED_VALUE_ATTRIBUTE_ID     CCPU_TO_LE16(0x0000)
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MIN_MEASURED_VALUE_ATTRIBUTE_ID CCPU_TO_LE16(0x0001)
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MAX_MEASURED_VALUE_ATTRIBUTE_ID CCPU_TO_LE16(0x0002)
#define ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_TOLERANCE_ATTRIBUTE_ID          CCPU_TO_LE16(0x0003) //optinal attr

/**
 * \brief server define attributes macros
*/
#define ZCL_DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES(reportMin, reportMax) \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID), \
  DEFINE_REPORTABLE_ATTRIBUTE_WITH_BOUNDARY(measuredValue, ZCL_READONLY_ATTRIBUTE | ZCL_CHECK_OTHER_ATTR, ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MEASURED_VALUE_ATTRIBUTE_ID, ZCL_S16BIT_DATA_TYPE_ID, reportMin, reportMax, \
                                            ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MIN_MEASURED_VALUE_ATTRIBUTE_ID, ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MAX_MEASURED_VALUE_ATTRIBUTE_ID), \
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(minMeasuredValue, ZCL_READONLY_ATTRIBUTE, ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MIN_MEASURED_VALUE_ATTRIBUTE_ID,  ZCL_S16BIT_DATA_TYPE_ID, 0x954D, 0x7FFE), \
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(maxMeasuredValue, ZCL_READONLY_ATTRIBUTE, ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_MAX_MEASURED_VALUE_ATTRIBUTE_ID, ZCL_S16BIT_DATA_TYPE_ID, 0x954E, 0x7FFF), \
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(tolerance, ZCL_READONLY_ATTRIBUTE, ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_TOLERANCE_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID, 0x0000, 0x0800)

#define ZCL_DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBUTES() 
    
#define TEMPERATURE_MEASUREMENT_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes) \
  { \
    .id = TEMPERATURE_MEASUREMENT_CLUSTER_ID, \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *) (clattributes), \
    .commandsAmount = ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_COMMANDS_AMOUNT, \
    .commands = NULL \
  }

#define TEMPERATURE_MEASUREMENT_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes) \
  { \
    .id = TEMPERATURE_MEASUREMENT_CLUSTER_ID, \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *) (clattributes), \
    .commandsAmount = ZCL_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_COMMANDS_AMOUNT, \
    .commands = NULL \
  }


#define DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER(cltype, clattributes) \
    TEMPERATURE_MEASUREMENT_CLUSTER_##cltype(clattributes)


#define ZCL_DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER_FLASH(clattributes) ZCL_DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER_SERVER(clattributes)
#define ZCL_DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT_FLASH() ZCL_DEFINE_TEMPERATURE_MEASUREMENT_CLUSTER_CLIENT()
/******************************************************************************
                    Types section
******************************************************************************/
BEGIN_PACK
typedef struct PACK {
  struct PACK {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    int16_t value;
    ZCL_ReportTime_t reportCounter;     //!<For internal use only
    ZCL_ReportTime_t minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t maxReportInterval; //!<Maximum reporting interval field value
    int16_t reportableChange;           //!<Reporting change field value
    ZCL_ReportTime_t timeoutPeriod;     //!<Timeout period field value
    int16_t lastReportedValue;          //!<Last reported value
    ZCL_AttributeId_t minVal;
    ZCL_AttributeId_t maxVal;
  } measuredValue ;
  struct PACK {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    int16_t value;
    int16_t minVal;
    int16_t maxVal;
  } minMeasuredValue ;
  struct PACK {
    ZCL_AttributeId_t   id;
    uint8_t type;
    uint8_t properties;
    int16_t value;
    int16_t minVal;
    int16_t maxVal;
  } maxMeasuredValue ;
  struct PACK {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  } tolerance ;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_TemperatureMeasurementClusterServerAttributes_t ;

typedef struct PACK
{
} ZCL_TemperatureMeasurementClusterClientAttributes_t;

END_PACK

#endif /* _ZCLTEMPERATUREMEASUREMENT_H_ */
