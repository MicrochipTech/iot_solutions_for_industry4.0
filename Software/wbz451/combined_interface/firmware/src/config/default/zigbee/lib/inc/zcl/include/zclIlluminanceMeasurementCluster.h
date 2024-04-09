/*******************************************************************************
  ZCL Luminescence Measurement Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclIlluminanceMeasurementCluster.h

  Summary:
    The header file describes the ZCL  ZCL Illuminance Measurement Cluster 
    and its interface.

  Description:
    The file describes the types and interface of the ZCL Illuminance measurement 
    Configuration Cluster.
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


#ifndef _ZCLILLUMINANCEMEASUREMENTCLUSTER_H
#define _ZCLILLUMINANCEMEASUREMENTCLUSTER_H

/*!
Attributes and commands for determining basic information about a device,
setting user device information such as location, enabling a device and resetting it
to factory defaults.
*/

/*******************************************************************************
                   Includes section
*******************************************************************************/

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/

/**
 * \brief servar atribute value
*/
#define ILLUMINANCE_MEASUREMENT_MEASURED_VALUE_INVALID               0xFFFF

/**
 * \brief Illuminance measurement cluster attributes values
*/
#define ILLUMINANCE_MEASUREMENT_SENSOR_TYPE_PHOTODIODE_VALUE         0x00
#define ILLUMINANCE_MEASUREMENT_SENSOR_TYPE_CMOS_VALUE               0x01
#define ILLUMINANCE_MEASUREMENT_SENSOR_TYPE_UNKNOWN_VALUE            0xFF

/**
 * \brief Illuminance measurement Cluster server attributes amount
*/
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT  6

/**
 * \brief Illuminance measurement Cluster client attributes amount. Clinet doesn't have attributes.
*/
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT 1

/**
 * \brief On/Off Switch Configuration Cluster commands amount
*/
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_COMMANDS_AMOUNT 0

/**
 * \brief Illuminance measurement ClusteVersion attribute identifier
*/
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID       CCPU_TO_LE16(0xfffd)

/**
 * \brief Illuminance measurement Cluster server's attributes identifiers
*/
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_MEASURED_VALUE_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x0000)
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_MIN_MEASURED_VALUE_SERVER_ATTRIBUTE_ID    CCPU_TO_LE16(0x0001)
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_MAX_MEASURED_VALUE_SERVER_ATTRIBUTE_ID    CCPU_TO_LE16(0x0002)
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_TOLERANCE_SERVER_ATTRIBUTE_ID             CCPU_TO_LE16(0x0003)
#define ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_LIGHT_SENSOR_TYPE_SERVER_ATTRIBUTE_ID     CCPU_TO_LE16(0x0004)

/**
 * \brief Illuminance measurement Cluster server define attributes macros
*/
#define ZCL_DEFINE_ILLUMINANCE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES(min, max) 


/**
 * \brief Illuminance measurement Cluster client define attributes macros
*/
#define ZCL_DEFINE_ILLUMINANCE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)
    
/**
 * \brief Illuminance measurement Cluster definition macros
*/
#define ILLUMINANCE_MEASUREMENT_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes) \
{ \
   .id = ILLUMINANCE_MEASUREMENT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = NULL \
}

#define ILLUMINANCE_MEASUREMENT_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes) \
{ \
   .id = ILLUMINANCE_MEASUREMENT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = NULL \
}

#define DEFINE_ILLUMINANCE_MEASUREMENT_CLUSTER(cltype, clattributes) \
    ILLUMINANCE_MEASUREMENT_CLUSTER_##cltype(clattributes)

#define ILLUMINANCE_MEASUREMENT_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes) \
{ \
   .id = ILLUMINANCE_MEASUREMENT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = NULL \
}

#define ILLUMINANCE_MEASUREMENT_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes) \
{ \
   .id = ILLUMINANCE_MEASUREMENT_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ILLUMINANCE_MEASUREMENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = NULL \
}

#define DEFINE_ILLUMINANCE_MEASUREMENT_CLUSTER_FLASH(cltype, clattributes) \
    ILLUMINANCE_MEASUREMENT_CLUSTER_##cltype##_FLASH(clattributes)
/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief Illuminance measurement Cluster server's attributes
*/

typedef struct PACK
{
} ZCL_IlluminanceMeasurementClusterServerAttributes_t;

/**
 * \brief Illuminance measurement Cluster server's attributes
*/

typedef struct PACK
{
  struct PACK {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_IlluminanceMeasurementClusterClientAttributes_t;

END_PACK

#endif /* _ZCLILLUMINANCEMEASUREMENTCLUSTER_H */

