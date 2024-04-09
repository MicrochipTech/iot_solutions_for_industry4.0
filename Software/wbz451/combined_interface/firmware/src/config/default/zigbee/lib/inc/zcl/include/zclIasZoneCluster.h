/*******************************************************************************
  Zigbee Cluster Library IAS Zone Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclIasZoneCluster.h

  Summary:
    The file describes the zcl IAS Zone Cluster related attributes and commands.

  Description:
    The file describes the zcl IAS Zone Cluster related attributes and commands.
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


#ifndef _ZCLIASZONECLUSTER_H_
#define _ZCLIASZONECLUSTER_H_

/*******************************************************************************
                   Includes section
*******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/
/**
* \brief Supported Zone State attribute values
*/
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATE_ATTRIBUTE_NOT_ENROLLED                  0x00
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATE_ATTRIBUTE_ENROLLED                      0x01
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATE_ATTRIBUTE_RESERVED                      0xFF

/**
* \brief server attribute default values
*/
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_STATE_ATTRIBUTE_ID_DEFAULT             0x00
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_STATUS_ATTRIBUTE_ID_DEFAULT            0x0000
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_ID_ATTRIBUTE_ID_DEFAULT                0xFF
#define ZCL_IAS_ZONE_CLUSTER_SERVER_NUMBEROFZONESENSITIVITY_LEVEL_SUPP_DEFAULT  0x02
#define ZCL_IAS_ZONE_CLUSTER_SERVER_CURRENTZONESENSITIVITY_LEVEL_SUPP_DEFAULT   0x00

/**
* \brief server attribute set identifier value
*/
#define ZCL_IAS_ZONE_CLUSTER_ZONE_INFORMATION_ATTRIBUTE_SET                         CCPU_TO_LE16(0x0000)
#define ZCL_IAS_ZONE_CLUSTER_ZONE_SETTINGS_ATTRIBUTE_SET                            CCPU_TO_LE16(0x0001)

/**
* \brief server attributes amount
*/
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ATTRIBUTES_AMOUNT                           8

/**
* \brief server commands amount
*/
#define ZCL_IAS_ZONE_CLUSTER_SERVER_COMMANDS_AMOUNT                             5

/**
* \brief client commands amount
*/
#define ZCL_IAS_ZONE_CLUSTER_CLIENT_COMMANDS_AMOUNT                             5

/**
* \brief client attributes amount
*/
#define ZCL_IAS_ZONE_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT                           1


/**
* \brief Supported attribute id
*/
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_STATE_ATTRIBUTE_ID                     CCPU_TO_LE16(0x0000)
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_TYPE_ATTRIBUTE_ID                      CCPU_TO_LE16(0x0001)
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_STATUS_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0002)
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_IAS_CIE_ADDRESS_ATTRIBUTE_ID           CCPU_TO_LE16(0x0010)
#define ZCL_IAS_ZONE_CLUSTER_SERVER_ZONE_ID_ATTRIBUTE_ID                        CCPU_TO_LE16(0x0011)
#define ZCL_IAS_ZONE_CLUSTER_SERVER_NUMBEROFZONESENSITIVITY_LEVEL_SUPP_ID       CCPU_TO_LE16(0x0012)
#define ZCL_IAS_ZONE_CLUSTER_SERVER_CURRENTZONESENSITIVITY_LEVEL_SUPP_ID        CCPU_TO_LE16(0x0013)


/**
* \brief Supported Zone Status attribute values
*/
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_ALARM_1                 0
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_ALARM_2                 1
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_TAMPER                  2
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_BATTERY                 3
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_SUPERVISION_REPORTS     4
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_RESTORE_REPORTS         5
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_TROUBLE                 6
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_AC_MAIN                 7
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_TEST_MODE               8
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_BATTERY_DEFECT          9
#define ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_ATTRIBUTE_TEST_MODE_TO_OPERATION_MODE 0xFEFF

//Commands generated by Server      
#define  ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_CHANGE_NOTIFY_COMMAND_ID              0x00
#define  ZCL_IAS_ZONE_CLUSTER_ZONE_ENROLL_REQUEST_COMMAND_ID                    0x01

/**
 * \brief Identify ClusterVersion attribute identifier (for both server and client)
*/
#define ZCL_IAS_ZONE_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID    CCPU_TO_LE16(0xfffd)

//Commands received by Server
#define  ZCL_IAS_ZONE_CLUSTER_ZONE_ENROLL_RESPONSE_COMMAND_ID                   0x00
#define  ZCL_IAS_ZONE_CLUSTER_ZONE_NORMAL_OPERATIONG_MODE                       0x01
#define  ZCL_IAS_ZONE_CLUSTER_ZONE_TEST_MODE                                    0x02
/**
 * \brief server define attributes macros
*/
#define ZCL_DEFINE_IAS_ZONE_CLUSTER_SERVER_ATTRIBUTES()
    
#define ZCL_DEFINE_IAS_ZONE_CLUSTER_CLIENT_ATTRIBUTES() \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_IAS_ZONE_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)
    
#define IAS_ZONE_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = IAS_ZONE_CLUSTER_ID, \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},\
    .attributesAmount = ZCL_IAS_ZONE_CLUSTER_SERVER_ATTRIBUTES_AMOUNT,\
    .attributes = (uint8_t *) (clattributes),\
    .commandsAmount = ZCL_IAS_ZONE_CLUSTER_SERVER_COMMANDS_AMOUNT,\
    .commands = (uint8_t *)clcommands \
  }

#define IAS_ZONE_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands)\
  { \
    .id = IAS_ZONE_CLUSTER_ID, \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},\
    .attributesAmount = ZCL_IAS_ZONE_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT,\
    .attributes = (uint8_t *) (clattributes),\
    .commandsAmount = ZCL_IAS_ZONE_CLUSTER_CLIENT_COMMANDS_AMOUNT,\
    .commands = (uint8_t *)clcommands \
  }

#define DEFINE_IAS_ZONE_CLUSTER(cltype, clattributes, clcommands)\
    IAS_ZONE_CLUSTER_##cltype(clattributes,clcommands)

/***************************************************************************//**
\brief IAS Zone Cluster define commands macros
*******************************************************************************/

#define ZCL_DEFINE_IAS_ZONE_CLUSTER_COMMANDS(zoneStatusChangeNotificationCommandInd, zoneEnrollRequestCommandInd, zoneEnrollResponseInd, zoneInitiateNormalOperatingModeInd, zoneInitiateTestModeInd)\
    DEFINE_COMMAND(zoneStatusChangeNotificationCommand, ZCL_IAS_ZONE_CLUSTER_ZONE_STATUS_CHANGE_NOTIFY_COMMAND_ID,\
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),\
                     zoneStatusChangeNotificationCommandInd),\
    DEFINE_COMMAND(zoneEnrollRequestCommand, ZCL_IAS_ZONE_CLUSTER_ZONE_ENROLL_REQUEST_COMMAND_ID,\
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_RELEVANT_RESPONSE, ZCL_COMMAND_ACK),\
                     zoneEnrollRequestCommandInd),

/******************************************************************************
                    Types section
******************************************************************************/
BEGIN_PACK
/**
* \brief Supported Zone Type attribute values
*/

typedef enum{
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_STANDARD_CIE                  = 0x0000,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_MOTION_SENSOR                 = 0x000d,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_CONTACT_SWITCH                = 0x0015,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_FIRE_SENSOR                   = 0x0028,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_WATER_SENSOR                  = 0x002A,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_GAS_SENSOR                    = 0x002B,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_PER_EMER_DEVICE               = 0x002C,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_VIBRATION_MOVEMENT_SENSOR     = 0x002D,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_REMOTE_CONTROL                = 0x010F,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_KEY_FOB                       = 0x0115,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_KEY_PAD                       = 0x021D,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_STANDARD_WARNING_DEVICE       = 0x0225,
  ZCL_IAS_ZONE_CLUSTER_ZONE_TYPE_ATTRIBUTE_INVALID_ZONE                  = 0xFFFF
}ZCL_ZoneType_t;

/**
 * \brief server enroll response command
*/
typedef enum {
  ENROLL_RESP_SUCCESS               =  0x00,
  ENROLL_RESP_NOT_SUPPORTED         =  0x01,
  ENROLL_RESP_NOT_ENROLL_PERMIT     =  0x02,
  ENROLL_RESP_TOO_MANY_ZONES        =  0x03
}ZCL_ZoneStatus_t;

typedef struct PACK {
} ZCL_IasZoneClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;
} ZCL_IasZoneClusterClientAttributes_t;

END_PACK

BEGIN_PACK
/**
 * \brief IAS Zone Cluster clients's commands/structures.
*/
//Zone Status Change Structure
typedef struct PACK
{
  uint16_t zoneStatus;
  uint8_t extendedStatus;
  uint8_t zoneId;
  uint16_t delayTime;
} ZCL_ZoneStatusChangeNot_t;

//Zone Enroll Request Structure
typedef struct PACK
{
  uint16_t zoneType;
  uint16_t manufacturerCode;
} ZCL_ZoneEnrollRequest_t;

//Zone Enroll Response Structure
typedef struct PACK
{
  uint8_t enrollResponseCode;
  uint8_t zoneId;
} ZCL_ZoneEnrollResCommand_t;

//Zone Zone Table Structure
typedef struct PACK
{
  uint8_t  zoneId;
  uint16_t zoneType;
  uint16_t zoneStatus;
  uint64_t zoneAddress;
} ZCL_ZoneTable_t;

//Zone Test Mode Structure
typedef struct PACK
{
  uint8_t testmodeDuration;
  uint8_t currentZoneSensitivityLevel;
}ZCL_ZoneInitiateTestMode_t;
END_PACK

// IAS Zone Cluster Commands
typedef struct
{
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*zoneEnrollRequestCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ZoneEnrollRequest_t *payload);
  } zoneEnrollRequestCommand;
  struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*zoneStatusChangeNotificationCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_ZoneStatusChangeNot_t *payload);
  } zoneStatusChangeNotificationCommand;
} ZCL_IasZoneClusterCommands_t;

#endif /* _ZCLIASZONECLUSTER_H_ */
