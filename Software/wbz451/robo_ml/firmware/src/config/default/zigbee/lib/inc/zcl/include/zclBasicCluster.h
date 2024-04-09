/*******************************************************************************
  Zigbee Cluster Library Basic cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclBasicCluster.h

  Summary:
    The header file describes the ZCL Basic Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Basic Cluster.
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


#ifndef _ZCLBASICCLUSTER_H
#define _ZCLBASICCLUSTER_H

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
/***************************************************************************//**
  \brief ZCL Basic Cluster server side commands amount
*******************************************************************************/
#define ZCL_BASIC_CLUSTER_SERVER_ATTRIBUTES_AMOUNT      15

/***************************************************************************//**
  \brief ZCL Basic Cluster derver side commands amount
*******************************************************************************/
#define ZCL_BASIC_CLUSTER_SERVER_COMMANDS_AMOUNT        1
//There are no any commands at the server side

/***************************************************************************//**
  \brief ZCL Basic Cluster client side commands amount
*******************************************************************************/
#define ZCL_BASIC_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT      1
//There are no any attributes at the client side

/***************************************************************************//**
  \brief ZCL Basic Cluster derver side commands amount
*******************************************************************************/
#define ZCL_BASIC_CLUSTER_CLIENT_COMMANDS_AMOUNT        1
//There are no any commands at the client side

//Attribute Ids of Basic Cluster Information
#define ZCL_BASIC_CLUSTER_VERSION_ATTRIBUTE_ID                          CCPU_TO_LE16(0xfffd)

//Atribute Ids of Basic Device Information Attribute Set at the server side
//!ZCL Basic Cluster server side ZCLVersion attribute id
#define ZCL_BASIC_CLUSTER_SERVER_ZCL_VERSION_ATTRIBUTE_ID               CCPU_TO_LE16(0x0000)
//!ZCL Basic Cluster server side ApplicationVersion attribute id
#define ZCL_BASIC_CLUSTER_SERVER_APPLICATION_VERSION_ATTRIBUTE_ID       CCPU_TO_LE16(0x0001)
//!ZCL Basic Cluster server side StackVersion attribute id
#define ZCL_BASIC_CLUSTER_SERVER_STACK_VERSION_ATTRIBUTE_ID             CCPU_TO_LE16(0x0002)
//!ZCL Basic Cluster server side HWVersion attribute id
#define ZCL_BASIC_CLUSTER_SERVER_HW_VERSION_ATTRIBUTE_ID                CCPU_TO_LE16(0x0003)
//!ZCL Basic Cluster server side ManufacturerName attribute id
#define ZCL_BASIC_CLUSTER_SERVER_MANUFACTURER_NAME_ATTRIBUTE_ID         CCPU_TO_LE16(0x0004)
//!ZCL Basic Cluster server side ModelIdentifier attribute id
#define ZCL_BASIC_CLUSTER_SERVER_MODEL_IDENTIFIER_ATTRIBUTE_ID          CCPU_TO_LE16(0x0005)
//!ZCL Basic Cluster server side DateCode attribute id
#define ZCL_BASIC_CLUSTER_SERVER_DATE_CODE_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0006)
//!ZCL Basic Cluster server side PowerSource attribute id
#define ZCL_BASIC_CLUSTER_SERVER_POWER_SOURCE_ATTRIBUTE_ID              CCPU_TO_LE16(0x0007)

#if ZLO_CLUSTER_ENHANCEMENTS == 1
//Additional attributes of the server side of the basic cluster
//!ZCL Basic Cluster server side GenericDeviceClass attribute id
#define ZCL_BASIC_CLUSTER_SERVER_GENERIC_DEVICE_CLASS_ATTRIBUTE_ID      CCPU_TO_LE16(0x0008)
//!ZCL Basic Cluster server side GenericDeviceType attribute id
#define ZCL_BASIC_CLUSTER_SERVER_GENERIC_DEVICE_TYPE_ATTRIBUTE_ID       CCPU_TO_LE16(0x0009)
//!ZCL Basic Cluster server side ProductCode attribute id
#define ZCL_BASIC_CLUSTER_SERVER_PRODUCT_CODE_ATTRIBUTE_ID              CCPU_TO_LE16(0x000a)
//!ZCL Basic Cluster server side ProductURL attribute id
#define ZCL_BASIC_CLUSTER_SERVER_PRODUCT_URL_ATTRIBUTE_ID               CCPU_TO_LE16(0x000b)
#endif // ZLO_CLUSTER_ENHANCEMENTS == 1

//Atribute Ids of Basic Device Settings Attribute Set at the server side
//!ZCL Basic Cluster server side LocationDescription attribute id
#define ZCL_BASIC_CLUSTER_SERVER_LOCATION_DESCRIPTION_ATTRIBUTE_ID      CCPU_TO_LE16(0x0010)
//!ZCL Basic Cluster server side PhysicalEnvironment attribute id
#define ZCL_BASIC_CLUSTER_SERVER_PHYSICAL_ENVIRONMENT_ATTRIBUTE_ID      CCPU_TO_LE16(0x0011)
//!ZCL Basic Cluster server side DeviceEnabled attribute id
#define ZCL_BASIC_CLUSTER_SERVER_DEVICE_ENABLED_ATTRIBUTE_ID            CCPU_TO_LE16(0x0012)
//!ZCL Basic Cluster server side AlarmMask attribute id
#define ZCL_BASIC_CLUSTER_SERVER_ALARM_MASK_ATTRIBUTE_ID                CCPU_TO_LE16(0x0013)

//!ZCL Basic Cluster server side SWBuildId attribute id
#define ZCL_BASIC_CLUSTER_SW_BUILD_ID_ATTRIBUTE_ID                      CCPU_TO_LE16(0x4000)

//!ZCL Basic Cluster server side ResetToFactoryDeafaults commabd id
#define ZCL_BASIC_CLUSTER_SERVER_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID   0x00

/*******************************************************************************
                   Types section
*******************************************************************************/

/***************************************************************************//**
  \brief ZCL Basic Cluster server side attributes defining macros

  This macros should be used for ZCL Basic Cluster server side attributes defining.

  \return None

  \internal
  //The typical usage is:
  //Basic Cluster server side related attributes
  ZCL_BasicClusterServerAttributes_t basicClusterAttributes = ZCL_DEFINE_BASIC_CLUSTER_SERVER_ATTRIBUTES();
*******************************************************************************/
#define ZCL_DEFINE_BASIC_CLUSTER_SERVER_ATTRIBUTES() \
      DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID), \
      DEFINE_ATTRIBUTE(zclVersion, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_ZCL_VERSION_ATTRIBUTE_ID,  ZCL_U8BIT_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(applicationVersion, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_APPLICATION_VERSION_ATTRIBUTE_ID,  ZCL_U8BIT_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(stackVersion, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_STACK_VERSION_ATTRIBUTE_ID,  ZCL_U8BIT_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(hwVersion, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_HW_VERSION_ATTRIBUTE_ID,  ZCL_U8BIT_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(manufacturerName, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_MANUFACTURER_NAME_ATTRIBUTE_ID,  ZCL_CHARACTER_STRING_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(modelIdentifier, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_MODEL_IDENTIFIER_ATTRIBUTE_ID,  ZCL_CHARACTER_STRING_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(dateCode, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_DATE_CODE_ATTRIBUTE_ID,  ZCL_CHARACTER_STRING_DATA_TYPE_ID),    \
      DEFINE_ATTRIBUTE(powerSource, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_POWER_SOURCE_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID),\
      DEFINE_ATTRIBUTE(physicalEnvironment, ZCL_READWRITE_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_PHYSICAL_ENVIRONMENT_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID), \
      DEFINE_ATTRIBUTE(genericDeviceClass, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_GENERIC_DEVICE_CLASS_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID), \
      DEFINE_ATTRIBUTE(genericDeviceType, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_GENERIC_DEVICE_TYPE_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID), \
      DEFINE_ATTRIBUTE(productCode, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_PRODUCT_CODE_ATTRIBUTE_ID, ZCL_OCTET_STRING_DATA_TYPE_ID), \
      DEFINE_ATTRIBUTE(productURL, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SERVER_PRODUCT_URL_ATTRIBUTE_ID, ZCL_CHARACTER_STRING_DATA_TYPE_ID), \
      DEFINE_ATTRIBUTE(swBuildId, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_SW_BUILD_ID_ATTRIBUTE_ID, ZCL_CHARACTER_STRING_DATA_TYPE_ID)
/***************************************************************************//**
  \brief ZCL Basic Cluster client side attributes defining macros

  This macros should be used for ZCL Basic Cluster client side attributes defining.

  \return None

  \internal
  //The typical usage is:
  //Basic Cluster server side related attributes
  ZCL_BasicClusterClientAttributes_t basicClusterAttributes = ZCL_DEFINE_BASIC_CLUSTER_CLIENT_ATTRIBUTES();
*******************************************************************************/
#define ZCL_DEFINE_BASIC_CLUSTER_CLIENT_ATTRIBUTES()                                                            \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_BASIC_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)

/**
 * \brief Basic Cluster define commands macros
 */

#define ZCL_DEFINE_BASIC_CLUSTER_COMMANDS(resetToFactoryDefaultsCommandInd)                    \
    DEFINE_COMMAND(resetToFactoryDefaults, ZCL_BASIC_CLUSTER_SERVER_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID,  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK), \
                     resetToFactoryDefaultsCommandInd)

/***************************************************************************//**
  \brief ZCL Basic Cluster server side defining macros

  This macros should be used with #ZCL_DEFINE_BASIC_CLUSTER_SERVER_ATTRIBUTES for
  ZCL Basic Cluster server side defining in application.

  \param attributes - pointer to cluster server attributes (ZCL_BasicClusterServerAttributes_t)

  \return None

  \internal
  //The typical code is:
  //Basic Cluster server side related attributes
  ZCL_BasicClusterServerAttributes_t basicClusterServerAttributes = DEFINE_ZCL_BASIC_CLUSTER_SERVER_ATTRIBUTES();
  ZCL_Cluster_t myClusters[] =
  {
    ZCL_DEFINE_BASIC_CLUSTER_SERVER(&basicClusterServerAttributes, &basicClusterServerCommands),
    //... Any other cluster defining ...
  }
*******************************************************************************/
#define ZCL_DEFINE_BASIC_CLUSTER_SERVER(clattributes, clcommands)                                                \
  {                                                                                                              \
    .id = BASIC_CLUSTER_ID,                                                                                      \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},                  \
    .attributesAmount = ZCL_BASIC_CLUSTER_SERVER_ATTRIBUTES_AMOUNT,                                              \
    .attributes = (uint8_t *) clattributes,                                                                      \
    .commandsAmount = ZCL_BASIC_CLUSTER_SERVER_COMMANDS_AMOUNT,                                                  \
    .commands = (uint8_t *)clcommands                                                                            \
  }

#define ZCL_DEFINE_BASIC_CLUSTER_SERVER_FLASH(clattributes) ZCL_DEFINE_BASIC_CLUSTER_SERVER(clattributes)
/***************************************************************************//**
  \brief ZCL Basic Cluster client side defining macros

  This macros should be used for ZCL Basic Cluster client side defining in application.

  \return None

  \internal
  //The typical code is:
  ZCL_Cluster_t myClusters[] =
  {
    ZCL_DEFINE_BASIC_CLUSTER_CLIENT(),
    //... Any other cluster defining ...
  }
*******************************************************************************/
#define ZCL_DEFINE_BASIC_CLUSTER_CLIENT(clattributes)                                                                        \
  {                                                                                                              \
    .id = BASIC_CLUSTER_ID,                                                                                      \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},                  \
    .attributesAmount = ZCL_BASIC_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT,                                              \
    .attributes = (uint8_t *) clattributes,                                                                                          \
    .commandsAmount = ZCL_BASIC_CLUSTER_CLIENT_COMMANDS_AMOUNT,                                                  \
    .commands = NULL                                                                                             \
  }

#define ZCL_DEFINE_BASIC_CLUSTER_CLIENT_FLASH() ZCL_DEFINE_BASIC_CLUSTER_CLIENT()
BEGIN_PACK
/***************************************************************************//**
  \brief
    ZCL Basic Cluster server side attributes
*******************************************************************************/
typedef struct PACK
{
  
  //!Basic Device Information attribute set (Id == 0x00)
  /*!ZCL Version attribute (Read only, M)
  The ZCLVersion attribute is 8-bits in length and specifies the version number of
  the ZigBee Cluster Library that all clusters on this endpoint conform to. For the
  initial version of the ZCL, this attribute shall be set to 0x01.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_BASIC_CLUSTER_SERVER_ZCL_VERSION_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (unsigned 8-bit integer, #ZCL_U8BIT_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x00)
  } zclVersion;
  /*!TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0001, #ZCL_BASIC_CLUSTER_SERVER_APPLICATION_VERSION_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (unsigned 8-bit integer, #ZCL_U8BIT_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x00)
  } applicationVersion;
  /*!TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0002, #ZCL_BASIC_CLUSTER_SERVER_STACK_VERSION_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (unsigned 8-bit integer, #ZCL_U8BIT_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x00)
  } stackVersion;
  /*!TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0003, #ZCL_BASIC_CLUSTER_SERVER_HW_VERSION_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (unsigned 8-bit integer, #ZCL_U8BIT_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x00)
  } hwVersion;
  /*!TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0004, #ZCL_BASIC_CLUSTER_SERVER_MANUFACTURER_NAME_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (character string, #ZCL_CHARACTER_STRING_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[32];     //!<Attribute value
  } manufacturerName;
  /*!TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0005, #ZCL_BASIC_CLUSTER_SERVER_MODEL_IDENTIFIER_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (character string, #ZCL_CHARACTER_STRING_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[32];     //!<Attribute value
  } modelIdentifier;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value[16];
  } dateCode;
  /*!Power Source attribute (Read only, M)
  The PowerSource attribute is 8-bits in length and specifies the source(s) of power
  available to the device. Bits b0 of this attribute represent the primary power
  source of the device and bit b7 indicates whether the device has a secondary power
  source in the form of a battery backup.

  Bits b0 of this attribute shall be set to one of the non-reserved values:
  0x00        - Unknown
  0x01        - Mains (single phase)
  0x02        - Mains (3 phase)
  0x03        - Battery
  0x04        - DC source
  0x05        - Emergency mains constantly powered
  0x06        - Emergency mains and transfer switch
  0x07-0x7f   - Reserved

  Bit b7 of this attribute shall be set to 1 if the device has a secondary power source
  in the form of a battery backup. Otherwise, bit b7 shall be set to 0.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0007, #ZCL_BASIC_CLUSTER_SERVER_POWER_SOURCE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (8-bit enumeration, #ZCL_8BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x00)
  } powerSource;
  /*!Physical Environment attribute (Read only, O)
  The PhysicalEnvironment attribute is 8-bits in length and specifies the type of
  physical environment in which the device will operate.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0011, #ZCL_BASIC_CLUSTER_SERVER_PHYSICAL_ENVIRONMENT_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (8-bit enumeration, #ZCL_8BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x00)
  } physicalEnvironment;
#if ZLO_CLUSTER_ENHANCEMENTS == 1
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value;
  } genericDeviceClass;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value;
  } genericDeviceType;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value[32];
  } productCode;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value[32];
  } productURL;
#endif // ZLO_CLUSTER_ENHANCEMENTS == 1
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value[16];
  } swBuildId;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0xfffd, #ZCL_BASIC_CLUSTER_VERSION_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (unsigned 16-bit integer, #ZCL_U16BIT_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint16_t            value;        //!<Attribute value (default 0x01)
  } clusterVersion;
  //!Basic Device Settings attribute set (Id == 0x01)
} ZCL_BasicClusterServerAttributes_t;
END_PACK

BEGIN_PACK
/***************************************************************************//**
  \brief
    ZCL Basic Cluster client side attributes
*******************************************************************************/
typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0xfffd, #ZCL_BASIC_CLUSTER_VERSION_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (unsigned 16-bit integer, #ZCL_U16BIT_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint16_t            value;        //!<Attribute value (default 0x01)
  } clusterVersion;
} ZCL_BasicClusterClientAttributes_t;
END_PACK

// The ResetToFactoryDefaults command is optional now.
/***************************************************************************//**
  \brief
    Describes the Basic Cluster server side commands

    On receipt of this command, the device resets all the attributes of all its clusters to
  their factory defaults.
    Note that ZigBee networking functionality and any bindings are not affected by
  this command.
    This command does not have a payload.
*******************************************************************************/
typedef struct PACK
{
  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x00, #ZCL_BASIC_CLUSTER_SERVER_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*resetToFactoryDefaultsCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } resetToFactoryDefaults;
} ZCL_BasicClusterServerCommands_t;


#endif //#ifndef _ZCLBASICCLUSTER_H

//eof zclBasicCluster.h
