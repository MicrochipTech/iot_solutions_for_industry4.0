/*******************************************************************************
  Zigbee Cluster Library GreenPower Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclGreenPowerCluster.h

  Summary:
    The header file describes the ZCL green power Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL GreenPower Cluster.
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


#ifndef _ZCLGREENPOWERCLUSTER_H
#define _ZCLGREENPOWERCLUSTER_H

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
#include <configserver/include/csDefaults.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/
#define NO_OF_SINK     1
#define PROXY_BLOCKEDID_TABLE_SIZE 0
#define DMIN_U 5u
#define DMIN_B 32u
#define DMAX   100u

#define GP_DEVICE_VERSION 0x00
//As per 1.1 spec the cluster revision is changed to 2
#define GP_CLUSTER_REVISION 0x0002

#define ZGP_PROXY_ADVANCED           0

#define GPP_ACTIVE_FUNCTIONALITY_FIXED_VALUE   0xFFFFFE
#define COMMISSIONING_WINDOW_DEFAULT_VALUE_IN_MSEC 180000ul
#define GPS_ACTIVE_FUNCTIONALITY_FIXED_VALUE   0xFFFFFE

#ifdef ZGP_CMD_ENABLE_APS_ACK
#define ZGP_APS_ACK_CONFIG ZCL_COMMAND_ACK
#else
#define ZGP_APS_ACK_CONFIG ZCL_COMMAND_NO_ACK
#endif
/**
 * \brief Green power Cluster server attributes amount 8(server) + 4(shared)
*/

#define ZCL_GP_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 12

/**
 * \brief Green power Cluster client attributes amount 8(client) + 4(shared)
*/

#define ZCL_GP_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT 8 // 12

/**
 * \brief Green power Cluster client commands amount
*/

#define ZCL_GP_CLUSTER_CLIENT_COMMANDS_AMOUNT 7

/**
 * \brief Green power Cluster server commands amount
*/

#define ZCL_GP_CLUSTER_SERVER_COMMANDS_AMOUNT 10

/**
 * \brief Green power Cluster commands amount(server and client)
*/

#define ZCL_GP_CLUSTER_COMMANDS_AMOUNT (ZCL_GP_CLUSTER_CLIENT_COMMANDS_AMOUNT + \
                                        ZCL_GP_CLUSTER_SERVER_COMMANDS_AMOUNT)

/**
 * \brief Green power Cluster client's attributes identifiers
*/

#define ZCL_GP_CLUSTER_CLIENT_GPP_MAX_PROXY_TABLE_ENTRIES_ATTRIBUTE_ID              CCPU_TO_LE16(0x0010)
#define ZCL_GP_CLUSTER_CLIENT_PROXY_TABLE_ATTRIBUTE_ID                              CCPU_TO_LE16(0x0011)
#define ZCL_GP_CLUSTER_CLIENT_GPP_NOTIFICATION_RETRY_NUMBER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0012)
#define ZCL_GP_CLUSTER_CLIENT_GPP_NOTIFICATION_RETRY_TIMER_ATTRIBUTE_ID             CCPU_TO_LE16(0x0013)
#define ZCL_GP_CLUSTER_CLIENT_GPP_MAX_SEARCH_COUNTER_ATTRIBUTE_ID                   CCPU_TO_LE16(0x0014)
#define ZCL_GP_CLUSTER_CLIENT_GPP_BLOCKED_GPD_ID_ATTRIBUTE_ID                       CCPU_TO_LE16(0x0015)
#define ZCL_GP_CLUSTER_CLIENT_GPP_FUNCTIONALITY_ATTRIBUTE_ID                        CCPU_TO_LE16(0x0016)
#define ZCL_GP_CLUSTER_CLIENT_GPP_ACTIVE_FUNCTIONALITY_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0017)
#define ZCL_GP_CLUSTER_CLIENT_GP_SHARED_SECURITY_KEY_TYPE_ATTRIBUTE_ID              CCPU_TO_LE16(0x0020)
#define ZCL_GP_CLUSTER_CLIENT_GP_SHARED_SECURITY_KEY_ATTRIBUTE_ID                   CCPU_TO_LE16(0x0021)
#define ZCL_GP_CLUSTER_CLIENT_GP_LINK_KEY_ATTRIBUTE_ID                              CCPU_TO_LE16(0x0022)
#define ZCL_GP_CLUSTER_CLIENT_CLUSTER_REVISION_ATTRIBUTE_ID                         CCPU_TO_LE16(0xfffd)

#define ZCL_DEFINE_GP_CLUSTER_CLIENT_ATTRIBUTES()                                                            \
  DEFINE_ATTRIBUTE(gppMaxProxyTableEntries, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GPP_MAX_PROXY_TABLE_ENTRIES_ATTRIBUTE_ID,  ZCL_U8BIT_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(proxyTable, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_PROXY_TABLE_ATTRIBUTE_ID,  ZCL_LONG_OCTET_STRING_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gppFunctionality, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GPP_FUNCTIONALITY_ATTRIBUTE_ID,  ZCL_24BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gppActiveFunctionality, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GPP_ACTIVE_FUNCTIONALITY_ATTRIBUTE_ID,  ZCL_24BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpSharedSecurityKeyType, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GP_SHARED_SECURITY_KEY_TYPE_ATTRIBUTE_ID,  ZCL_8BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpSharedSecuritykey, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GP_SHARED_SECURITY_KEY_ATTRIBUTE_ID,  ZCL_128BIT_SECURITY_KEY_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpLinkKey, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GP_LINK_KEY_ATTRIBUTE_ID,  ZCL_128BIT_SECURITY_KEY_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(clusterRevision, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_CLUSTER_REVISION_ATTRIBUTE_ID,  ZCL_U16BIT_DATA_TYPE_ID)

/**
 * \brief Green power Cluster server's attributes identifiers
*/

#define ZCL_GP_CLUSTER_SERVER_GPS_MAX_SINK_TABLE_ENTRIES_ATTRIBUTE_ID               CCPU_TO_LE16(0x0000)
#define ZCL_GP_CLUSTER_SERVER_SINK_TABLE_ATTRIBUTE_ID                               CCPU_TO_LE16(0x0001)
#define ZCL_GP_CLUSTER_SERVER_GPS_COMMUNICATION_MODE_ATTRIBUTE_ID                   CCPU_TO_LE16(0x0002)
#define ZCL_GP_CLUSTER_SERVER_GPS_COMMISSIONING_EXIT_MODE_ATTRIBUTE_ID              CCPU_TO_LE16(0x0003)
#define ZCL_GP_CLUSTER_SERVER_GPS_COMMISSIONING_WINDOW_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0004)
#define ZCL_GP_CLUSTER_SERVER_GPS_SECURITY_LEVEL_ATTRIBUTE_ID                       CCPU_TO_LE16(0x0005)
#define ZCL_GP_CLUSTER_SERVER_GPS_FUNCTIONALITY_ATTRIBUTE_ID                        CCPU_TO_LE16(0x0006)
#define ZCL_GP_CLUSTER_SERVER_GPS_ACTIVE_FUNCTIONALITY_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0007)
#define ZCL_GP_CLUSTER_SERVER_GP_SHARED_SECURITY_KEY_TYPE_ATTRIBUTE_ID              CCPU_TO_LE16(0x0020)
#define ZCL_GP_CLUSTER_SERVER_GP_SHARED_SECURITY_KEY_ATTRIBUTE_ID                   CCPU_TO_LE16(0x0021)
#define ZCL_GP_CLUSTER_SERVER_GP_LINK_KEY_ATTRIBUTE_ID                              CCPU_TO_LE16(0x0022)
#define ZCL_GP_CLUSTER_SERVER_CLUSTER_REVISION_ATTRIBUTE_ID                         CCPU_TO_LE16(0xfffd)

#define ZCL_DEFINE_GP_CLUSTER_SERVER_ATTRIBUTES()                                                            \
  DEFINE_ATTRIBUTE(gpsMaxSinkTableEntries, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_MAX_SINK_TABLE_ENTRIES_ATTRIBUTE_ID,  ZCL_U8BIT_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(sinkTable, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_SINK_TABLE_ATTRIBUTE_ID,  ZCL_LONG_OCTET_STRING_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpsCommunicationMode, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_COMMUNICATION_MODE_ATTRIBUTE_ID,  ZCL_8BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpsCommissioningExitMode, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_COMMISSIONING_EXIT_MODE_ATTRIBUTE_ID,  ZCL_8BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpsCommissioningWindow, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_COMMISSIONING_WINDOW_ATTRIBUTE_ID,  ZCL_U16BIT_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpsSecurityLevel, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_SECURITY_LEVEL_ATTRIBUTE_ID,  ZCL_8BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpsFunctionality, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_FUNCTIONALITY_ATTRIBUTE_ID,  ZCL_24BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpsActiveFunctionality, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GPS_ACTIVE_FUNCTIONALITY_ATTRIBUTE_ID,  ZCL_24BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpSharedSecurityKeyType, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GP_SHARED_SECURITY_KEY_TYPE_ATTRIBUTE_ID,  ZCL_8BIT_BITMAP_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpSharedSecuritykey, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_CLIENT_GP_SHARED_SECURITY_KEY_ATTRIBUTE_ID,  ZCL_128BIT_SECURITY_KEY_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(gpLinkKey, ZCL_READWRITE_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_GP_LINK_KEY_ATTRIBUTE_ID,  ZCL_128BIT_SECURITY_KEY_DATA_TYPE_ID), \
  DEFINE_ATTRIBUTE(clusterRevision, ZCL_READONLY_ATTRIBUTE, ZCL_GP_CLUSTER_SERVER_CLUSTER_REVISION_ATTRIBUTE_ID,  ZCL_U16BIT_DATA_TYPE_ID)


/**
 * \brief Green power Cluster server define commands macros
*/
#define ZCL_GP_CLUSTER_SERVER_GP_NOTIFICATION_COMMAND_ID                 0x00
#define ZCL_GP_CLUSTER_SERVER_GP_PAIRING_SEARCH_COMMAND_ID               0x01
#define ZCL_GP_CLUSTER_SERVER_GP_TUNNELING_STOP_COMMAND_ID               0x03
#define ZCL_GP_CLUSTER_SERVER_GP_COMMISSIONING_NOTIFICATION_COMMAND_ID   0x04
#define ZCL_GP_CLUSTER_SERVER_GP_SINK_COMMISSIONING_MODE_COMMAND_ID      0x05
#define ZCL_GP_CLUSTER_SERVER_GP_TRANSLATION_TABLE_UPDATE_COMMAND_ID     0x07
#define ZCL_GP_CLUSTER_SERVER_GP_TRANSLATION_TABLE_REQUEST_COMMAND_ID    0x08
#define ZCL_GP_CLUSTER_SERVER_GP_PAIRING_CONFIGURATION_COMMAND_ID        0x09
#define ZCL_GP_CLUSTER_SERVER_GP_SINK_TABLE_REQUEST_COMMAND_ID           0x0a
#define ZCL_GP_CLUSTER_SERVER_GP_PROXY_TABLE_RESPONSE_COMMAND_ID         0x0b

/**
 * \brief Green power Cluster client define commands macros
*/
#define ZCL_GP_CLUSTER_CLIENT_GP_NOTIFICATION_RESP_COMMAND_ID         0x00
#define ZCL_GP_CLUSTER_CLIENT_GP_PAIRING_COMMAND_ID                   0x01
#define ZCL_GP_CLUSTER_CLIENT_GP_PROXY_COMM_MODE_COMMAND_ID           0x02
#define ZCL_GP_CLUSTER_CLIENT_GP_RESPONSE_COMMAND_ID                  0x06
#define ZCL_GP_CLUSTER_CLIENT_GP_TRANSLATION_TABLE_RESP_COMMAND_ID    0x08
#define ZCL_GP_CLUSTER_CLIENT_GP_SINK_TABLE_RESPONSE_COMMAND_ID       0x0a
#define ZCL_GP_CLUSTER_CLIENT_GP_PROXY_TABLE_REQ_COMMAND_ID           0x0b

#define ZCL_DEFINE_GP_CLUSTER_COMMANDS(gpNotificationInd, gpPairingSearchInd, gpTunnelingStopInd, gpCommissioningNotificationInd, \
	                               gpSinkCommissioningModeInd,gpTranslationTableUpdateCommandInd, gpTranslationTableRequestCommandInd, \
                                       gpPairingConfigurationInd, gpSinkTableRequestInd, gpProxyTableResponseInd, \
                                       gpNotificationRespInd, gpPairingInd, gpProxyCommModeInd, gpResponseInd, \
	                               gpTranslationTableRspInd, gpSinkTableRespInd, gpProxyTableReqInd) \
    DEFINE_COMMAND(gpNotification, ZCL_GP_CLUSTER_SERVER_GP_NOTIFICATION_COMMAND_ID,  \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpNotificationInd), \
    DEFINE_COMMAND(gpPairingSearch, ZCL_GP_CLUSTER_SERVER_GP_PAIRING_SEARCH_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpPairingSearchInd), \
    DEFINE_COMMAND(gpTunnelingStop, ZCL_GP_CLUSTER_SERVER_GP_TUNNELING_STOP_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpTunnelingStopInd), \
    DEFINE_COMMAND(gpCommissioningNotification, ZCL_GP_CLUSTER_SERVER_GP_COMMISSIONING_NOTIFICATION_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpCommissioningNotificationInd), \
    DEFINE_COMMAND(gpSinkCommissioningMode, ZCL_GP_CLUSTER_SERVER_GP_SINK_COMMISSIONING_MODE_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpSinkCommissioningModeInd), \
    DEFINE_COMMAND(gpTranslationTableUpdateCommand, ZCL_GP_CLUSTER_SERVER_GP_TRANSLATION_TABLE_UPDATE_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpTranslationTableUpdateCommandInd),  \
    DEFINE_COMMAND(gpTranslationTableRequestCommand, ZCL_GP_CLUSTER_SERVER_GP_TRANSLATION_TABLE_REQUEST_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpTranslationTableRequestCommandInd), \
    DEFINE_COMMAND(gpPairingConfiguration, ZCL_GP_CLUSTER_SERVER_GP_PAIRING_CONFIGURATION_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpPairingConfigurationInd), \
    DEFINE_COMMAND(gpSinkTableRequest, ZCL_GP_CLUSTER_SERVER_GP_SINK_TABLE_REQUEST_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpSinkTableRequestInd), \
    DEFINE_COMMAND(gpProxyTableResponse, ZCL_GP_CLUSTER_SERVER_GP_PROXY_TABLE_RESPONSE_COMMAND_ID,   \
                     COMMAND_OPTIONS(CLIENT_TO_SERVER, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpProxyTableResponseInd), \
    DEFINE_COMMAND(gpNotificationResp, ZCL_GP_CLUSTER_CLIENT_GP_NOTIFICATION_RESP_COMMAND_ID,  \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpNotificationRespInd), \
    DEFINE_COMMAND(gpPairing, ZCL_GP_CLUSTER_CLIENT_GP_PAIRING_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpPairingInd), \
    DEFINE_COMMAND(gpProxyCommMode, ZCL_GP_CLUSTER_CLIENT_GP_PROXY_COMM_MODE_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpProxyCommModeInd), \
    DEFINE_COMMAND(gpResponse, ZCL_GP_CLUSTER_CLIENT_GP_RESPONSE_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpResponseInd), \
    DEFINE_COMMAND(gpTranslationTableResp, ZCL_GP_CLUSTER_CLIENT_GP_TRANSLATION_TABLE_RESP_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpTranslationTableRspInd), \
    DEFINE_COMMAND(gpSinkTableResp, ZCL_GP_CLUSTER_CLIENT_GP_SINK_TABLE_RESPONSE_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_NO_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpSinkTableRespInd), \
    DEFINE_COMMAND(gpProxyTableReq, ZCL_GP_CLUSTER_CLIENT_GP_PROXY_TABLE_REQ_COMMAND_ID,   \
                     COMMAND_OPTIONS(SERVER_TO_CLIENT, ZCL_THERE_IS_RELEVANT_RESPONSE, ZGP_APS_ACK_CONFIG), \
                     gpProxyTableReqInd)


#define DEFINE_GP_CLUSTER(cltype, clattributes, clcommands) \
    GP_CLUSTER_##cltype(clattributes, clcommands)

#define DEFINE_GP_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    GP_CLUSTER_##cltype##_FLASH(clattributes, clcommands)

/**
 * \brief Green power Cluster definition macros
*/

#define GP_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = GREEN_POWER_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GP_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GP_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_GP_CLUSTER(cltype, clattributes, clcommands) \
    GP_CLUSTER_##cltype(clattributes, clcommands)

#define GP_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = GREEN_POWER_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GP_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GP_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define GP_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = GREEN_POWER_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GP_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GP_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}



#define GP_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = GREEN_POWER_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_GP_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_GP_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

BEGIN_PACK
/***************************************************************************//**
  \brief
    ZCL Green Power Cluster client side attributes
*******************************************************************************/
typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gppMaxProxyTableEntries;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[2];     //!<Attribute value (default 0x0000)
  } proxyTable;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[3];     //!<Attribute value (default 0x0000)
  } gppFunctionality;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[3];     //!<Attribute value (default 0x0000)
  } gppActiveFunctionality;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gpSharedSecurityKeyType;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[16];        //!<Attribute value (default 0x0000)
  } gpSharedSecuritykey;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t            value[16];        //!<Attribute value (default 0x0000)
  } gpLinkKey;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint16_t            value;        //!<Attribute value (default 0x0000)
  } clusterRevision;

} ZCL_GreenPowerClusterClientAttributes_t;

/***************************************************************************//**
  \brief
    ZCL Green Power Cluster server side attributes
*******************************************************************************/
typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gpsMaxSinkTableEntries;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[2];     //!<Attribute value (default 0x0000)
  } sinkTable;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gpsCommunicationMode;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gpsCommissioningExitMode;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint16_t             value;        //!<Attribute value (default 0x0000)
  } gpsCommissioningWindow;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gpsSecurityLevel;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t            value[3];        //!<Attribute value (default 0x0000)
  } gpsFunctionality;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t            value[3];        //!<Attribute value (default 0x0000)
  } gpsActiveFunctionality;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value;        //!<Attribute value (default 0x0000)
  } gpSharedSecurityKeyType;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t             value[16];        //!<Attribute value (default 0x0000)
  } gpSharedSecuritykey;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint8_t            value[16];        //!<Attribute value (default 0x0000)
  } gpLinkKey;
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000, #ZCL_KE_CLUSTER_CLIENT_KEY_ESTABLISHMENT_SUITE_ATTRIBUTE_ID)
    uint8_t             type;         //!<Attribute type (16-bit enumeration, #ZZCL_16BIT_ENUM_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint16_t            value;        //!<Attribute value (default 0x0000)
  } clusterRevision;

} ZCL_GreenPowerClusterServerAttributes_t;
END_PACK

/***************************************************************************//**
  \brief
    Describes the green power cluster commands
*******************************************************************************/
typedef struct PACK
{
  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x00, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpNotificationCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpNotification;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x01, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALL_ALARMS_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpPairingSearchCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpPairingSearch;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x02, #ZCL_ALARM_CLUSTER_SERVER_GET_ALARM_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpTunnelingStopCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpTunnelingStop;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpCommissioningNotificationCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpCommissioningNotification;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpSinkCommissioningModeCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpSinkCommissioningMode;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpTranslationTableUpdateCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpTranslationTableUpdateCommand;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpTranslationTableRequestCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpTranslationTableRequestCommand;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpPairingConfigurationCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpPairingConfiguration;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpSinkTableRequestCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpSinkTableRequest;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpProxyTableResponseCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpProxyTableResponse;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x00, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpNotificationRespCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpNotificationResp;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x01, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALL_ALARMS_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpPairingCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpPairing;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x02, #ZCL_ALARM_CLUSTER_SERVER_GET_ALARM_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpProxyCommModeCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpProxyCommMode;

  struct
  {
    ZCL_CommandId_t       id;       //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t   options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
      \brief
        Command indication handler
      \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpRespCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpResponse;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpTransTableRespCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpTranslationTableResp;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpSinkTableRespCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpSinkTableResp;

  struct
  {
    ZCL_CommandId_t		id; 	  //!<Command Id (0x03, #ZCL_ALARM_CLUSTER_SERVER_RESET_ALARM_LOG_COMMAND_ID)
    ZclCommandOptions_t	options;  //!<Command options (.direction should be equal to #ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER)
    /*!
	  \brief
	    Command indication handler
	  \param payloadLength - actual payload length in bytes (should be zero)
    */
    ZCL_Status_t(*gpProxyTableReqCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t * payload);
  } gpProxyTableReq;

} ZCL_GreenPowerClusterCommands_t;

#endif /* _ZCLGREENPOWERCLUSTER_H */
