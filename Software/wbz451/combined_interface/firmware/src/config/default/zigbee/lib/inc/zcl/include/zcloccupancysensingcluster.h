/*******************************************************************************
  ZCL Occupancy Sensing Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOccupancySensingCluster.h

  Summary:
    The header file describes the ZCL Occupancy Sensing Cluster and its interface.

  Description:
    The file describes the types and interface of the 
    ZCL Occupancy Sensing Configuration Cluster.
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


#ifndef _ZCLOCCUPANCYSENSINGCLUSTER_H
#define _ZCLOCCUPANCYSENSINGCLUSTER_H

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
 * \brief Occupancy Sensing cluster attributes values
*/

#define OCCUPANCY_ATTRIBUTE_VALUE_OCCUPIED                                                               1
#define OCCUPANCY_ATTRIBUTE_VALUE_UNOCCUPIED                                                             0

#define OCCUPANYC_SENSOR_TYPE_ATTRIBUTE_VALUE_PIR                                                        0x00
#define OCCUPANYC_SENSOR_TYPE_ATTRIBUTE_VALUE_ULTRASONIC                                                 0x01
#define OCCUPANYC_SENSOR_TYPE_ATTRIBITE_VALUE_PIR_AND_ULTRASONIC                                         0x02
#define OCCUPANYC_SENSOR_TYPE_ATTRIBITE_VALUE_PHYSICAL_CONTACT                                           0x03


#define OCCUPANYC_SENSOR_TYPE_BITMAP_ATTRIBUTE_VALUE_PIR                                                 0x01//0b00000001
#define OCCUPANYC_SENSOR_TYPE_BITMAP_ATTRIBUTE_VALUE_ULTRASONIC                                          0x02//0b00000010
#define OCCUPANYC_SENSOR_TYPE_BITMAP_ATTRIBITE_VALUE_PIR_AND_ULTRASONIC                                  0x03//0b00000011
#define OCCUPANYC_SENSOR_TYPE_BITMAP_ATTRIBUTE_VALUE_PHYSICAL_CONTACT_PIR                                0x05//0b00000101
#define OCCUPANYC_SENSOR_TYPE_BITMAP_ATTRIBUTE_VALUE_PHYSICAL_CONTACT_ULTRASONIC                         0x06//0b00000110
#define OCCUPANYC_SENSOR_TYPE_BITMAP_ATTRIBITE_VALUE_PHYSICAL_CONTACT_PIR_AND_ULTRASONIC                 0x07//0b00000111


/* Occupancy cluster attributes min ,max and default values */

#define ZCL_OCCUPANCY_SENSING_CL_OCCUPANCY_SER_ATTR_MIN_VAL                                              (0x00)
#define ZCL_OCCUPANCY_SENSING_CL_OCCUPANCY_SER_ATTR_MAX_VAL                                              (0x01)

#define ZCL_OCCUPANCY_SENSING_CL_OCCUPANCY_SENSOR_TYPE_SER_ATTR_MIN_VAL                                  (0x00)
#define ZCL_OCCUPANCY_SENSING_CL_OCCUPANCY_SENSOR_TYPE_SER_ATTR_MAX_VAL                                  (0xfe)

#define ZCL_OCCUPANCY_SENSING_CL_OCCUPANCY_SENSOR_TYPE_BITMAP_SER_ATTR_MIN_VAL                           (0x00)
#define ZCL_OCCUPANCY_SENSING_CL_OCCUPANCY_SENSOR_TYPE_BITMAP_SER_ATTR_MAX_VAL                           (0x07)

#define ZCL_OCCUPANCY_SENSING_CL_PIR_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_DEFAULT_VAL                   (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_DEFAULT_VAL                   (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_DEFAULT_VAL               (0x001)

#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_DEFAULT_VAL            (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_DEFAULT_VAL            (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_DEFAULT_VAL        (0x01)

#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_DEFAULT_VAL      (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_DEFAULT_VAL      (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_DEFAULT_VAL  (0x01)

#define ZCL_OCCUPANCY_SENSING_CL_PIR_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_MIN_VAL                       (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_MAX_VAL                       (0xfffe)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_MIN_VAL                       (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_MAX_VAL                       (0xfffe)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_MIN_VAL                   (0x01)
#define ZCL_OCCUPANCY_SENSING_CL_PIR_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_MAX_VAL                   (0xfe)

#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_MIN_VAL                (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_MAX_VAL                (0xfffe)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_MIN_VAL                (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_MAX_VAL                (0xfffe)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_MIN_VAL            (0x01)
#define ZCL_OCCUPANCY_SENSING_CL_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_MAX_VAL            (0xfe)

#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_MIN_VAL          (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_OCCUPIED_TO_UNOCCUPIED_DELAY_SER_ATTR_MAX_VAL          (0xfffe)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_MIN_VAL          (0x0000)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_DELAY_SER_ATTR_MAX_VAL          (0xfffe)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_MIN_VAL      (0x01)
#define ZCL_OCCUPANCY_SENSING_CL_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SER_ATTR_MAX_VAL      (0xfe)

/**
 * \brief Occupancy Sensing Cluster server attributes amount
*/

#define ZCL_OCCUPANCY_SENSING_CLUSTER_SERVER_ATTRIBUTES_AMOUNT (13)

/**
 * \brief Occupancy Sensing Cluster client attributes amount. Clinet doesn't have attributes.
*/

#define ZCL_OCCUPANCY_SENSING_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT (1)

/**
 * \brief On/Off Switch Configuration Cluster commands amount
*/

#define ZCL_OCCUPANCY_SENSING_CLUSTER_COMMANDS_AMOUNT 0

/**
 * \brief Occupancy Sensing Cluster ClusterVersion attribute identifier
*/
#define ZCL_OCCUPANCY_SENSING_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID                                           CCPU_TO_LE16(0xfffd)

/**
 * \brief Occupancy Sensing Cluster server's attributes identifiers
*/
#define ZCL_OCCUPANCY_SENSING_CLUSTER_OCCUPANCY_SERVER_ATTRIBUTE_ID                                                  CCPU_TO_LE16(0x0000)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_OCCUPANCY_SENSOR_TYPE_SERVER_ATTRIBUTE_ID                                      CCPU_TO_LE16(0x0001)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_OCCUPANCY_SENSOR_TYPE_BITMAP_SERVER_ATTRIBUTE_ID                               CCPU_TO_LE16(0x0002)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_PIR_OCCUPIED_TO_UNOCCUPIED_DELAY_SERVER_ATTRIBUTE_ID                           CCPU_TO_LE16(0x0010)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_PIR_UNOCCUPIED_TO_OCCUPIED_DELAY_SERVER_ATTRIBUTE_ID                           CCPU_TO_LE16(0x0011)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_PIR_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SERVER_ATTRIBUTE_ID                       CCPU_TO_LE16(0x0012)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_ULTRASONIC_OCCUPIED_TO_UNOCCUPIED_DELAY_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0020)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_DELAY_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0021)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_ULTRASONIC_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SERVER_ATTRIBUTE_ID                CCPU_TO_LE16(0x0022)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_PHYSICAL_CONTACT_OCCUPIED_TO_UNOCCUPIED_DELAY_SERVER_ATTRIBUTE_ID              CCPU_TO_LE16(0x0030)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_DELAY_SERVER_ATTRIBUTE_ID              CCPU_TO_LE16(0x0031)
#define ZCL_OCCUPANCY_SENSING_CLUSTER_PHYSICAL_CONTACT_UNOCCUPIED_TO_OCCUPIED_THRESHOLD_SERVER_ATTRIBUTE_ID          CCPU_TO_LE16(0x0032)

/**
 * \brief Occupancy Sensing Cluster server define attributes macros
*/

#define ZCL_DEFINE_OCCUPANCY_SENSING_CLUSTER_SERVER_ATTRIBUTES(min, max) 

/**
 * \brief Occupancy Sensing Cluster client define attributes macros
*/

#define ZCL_DEFINE_OCCUPANCY_SENSING_CLUSTER_CLIENT_ATTRIBUTES()\
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_OCCUPANCY_SENSING_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/**
 * \brief Occupancy Sensing Cluster definition macros
*/

#define OCCUPANCY_SENSING_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = OCCUPANCY_SENSING_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define OCCUPANCY_SENSING_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = OCCUPANCY_SENSING_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_OCCUPANCY_SENSING_CLUSTER(cltype, clattributes, clcommands) \
    OCCUPANCY_SENSING_CLUSTER_##cltype(clattributes, clcommands)

#define OCCUPANCY_SENSING_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = OCCUPANCY_SENSING_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define OCCUPANCY_SENSING_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = OCCUPANCY_SENSING_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_OCCUPANCY_SENSING_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DEFINE_OCCUPANCY_SENSING_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    OCCUPANCY_SENSING_CLUSTER_##cltype##_FLASH(clattributes, clcommands)
/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief Occupancy Sensing Cluster server's attributes
*/

typedef struct PACK
{
} ZCL_OccupancySensingClusterServerAttributes_t;

/**
 * \brief Occupancy Sensing Cluster server's attributes
*/

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_OccupancySensingClusterClientAttributes_t;

END_PACK


#endif /* _ZCLOCCUPANCYSENSINGCLUSTER_H */

