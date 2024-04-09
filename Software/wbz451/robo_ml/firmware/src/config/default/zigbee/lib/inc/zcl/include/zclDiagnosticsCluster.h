/*******************************************************************************
  Zigbee Cluster Library Diagnostics Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclDiagnosticsCluster.h

  Summary:
    The header file describes the ZCL Diagnostics Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Diagnostics Cluster.
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



#ifndef _ZCLDIAGNOSTICSCLUSTER_H
#define _ZCLDIAGNOSTICSCLUSTER_H

/*******************************************************************************
                   Includes section
*******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/
/**
 * \brief Diagnostics Server Cluster attributes amount.
*/
#define ZCL_DIAGNOSTICS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT 4
/* HA_PROFILE_EXTENSIONS */

/**
 * \brief Diagnostics Client Cluster attributes amount.
*/
#define ZCL_DIAGNOSTICS_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT 1

/**
 * \brief Diagnostics Client Cluster commands amount.
*/
#define ZCL_DIAGNOSTICS_CLUSTER_COMMANDS_AMOUNT 0

/**
 * \brief Diagnostics server cluster attributes identifiers.
*/
/*Hardware Information Attribute Set*/
#define ZCL_DIAGNOSTICS_CLUSTER_HW_NUMBER_OF_RESETS_ATTR_ID               CCPU_TO_LE16(0x0000)
#define ZCL_DIAGNOSTICS_CLUSTER_PERSISTENT_MEMORY_WRITES_ATTR_ID          CCPU_TO_LE16(0x0001)

/* Stack or Network Information Attribute Set*/
#define ZCL_DIAGNOSTICS_CLUSTER_MAC_RX_BCAST_ATTR_ID                      CCPU_TO_LE16(0x0100)
#define ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_BCAST_ATTR_ID                      CCPU_TO_LE16(0x0101)
#define ZCL_DIAGNOSTICS_CLUSTER_MAC_RX_UCAST_ATTR_ID                      CCPU_TO_LE16(0x0102)
#define ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_UCAST_ATTR_ID                      CCPU_TO_LE16(0x0103)
#define ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_UCAST_RETRY_ATTR_ID                CCPU_TO_LE16(0x0104)
#define ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_UCAST_FAIL_ATTR_ID                 CCPU_TO_LE16(0x0105)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_RX_BCAST_ATTR_ID                      CCPU_TO_LE16(0x0106)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_TX_BCAST_ATTR_ID                      CCPU_TO_LE16(0x0107)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_RX_UCAST_ATTR_ID                      CCPU_TO_LE16(0x0108)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_TX_UCAST_SUCCESS_ATTR_ID              CCPU_TO_LE16(0x0109)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_TX_UCAST_RETRY_ATTR_ID                CCPU_TO_LE16(0x010a)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_TX_UCAST_FAIL_ATTR_ID                 CCPU_TO_LE16(0x010b)
#define ZCL_DIAGNOSTICS_CLUSTER_ROUTE_DISC_INITIATED_ATTR_ID              CCPU_TO_LE16(0x010c)
#define ZCL_DIAGNOSTICS_CLUSTER_NEIGHBOR_ADDED_ATTR_ID                    CCPU_TO_LE16(0x010d)
#define ZCL_DIAGNOSTICS_CLUSTER_NEIGHBOR_REMOVED_ATTR_ID                  CCPU_TO_LE16(0x010e)
#define ZCL_DIAGNOSTICS_CLUSTER_NEIGHBOR_STALE_ATTR_ID                    CCPU_TO_LE16(0x010f)
#define ZCL_DIAGNOSTICS_CLUSTER_JOIN_INDICATION_ATTR_ID                   CCPU_TO_LE16(0x0110)
#define ZCL_DIAGNOSTICS_CLUSTER_CHILD_MOVED_ATTR_ID                       CCPU_TO_LE16(0x0111)
#define ZCL_DIAGNOSTICS_CLUSTER_NWKFC_FAILURE_ATTR_ID                     CCPU_TO_LE16(0x0112)
#define ZCL_DIAGNOSTICS_CLUSTER_APSFC_FAILURE_ATTR_ID                     CCPU_TO_LE16(0x0113)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_UNAUTHORIZED_KEY_ATTR_ID              CCPU_TO_LE16(0x0114)
#define ZCL_DIAGNOSTICS_CLUSTER_NWK_DECRYPT_FAILURES_ATTR_ID              CCPU_TO_LE16(0x0115)
#define ZCL_DIAGNOSTICS_CLUSTER_APS_DECRYPT_FAILURES_ATTR_ID              CCPU_TO_LE16(0x0116)
#define ZCL_DIAGNOSTICS_CLUSTER_PACKET_BUFFER_ALLOCATE_FAILURE_ATTR_ID    CCPU_TO_LE16(0x0117)
#define ZCL_DIAGNOSTICS_CLUSTER_RELAYED_UCAST_ATTR_ID                     CCPU_TO_LE16(0x0118)
#define ZCL_DIAGNOSTICS_CLUSTER_PHYTOMAC_QUEUE_LIMIT_REACHED_ATTR_ID      CCPU_TO_LE16(0x0119)
#define ZCL_DIAGNOSTICS_CLUSTER_PACKET_VALIDATE_DROP_COUNT_ATTR_ID        CCPU_TO_LE16(0x011a)
#define ZCL_DIAGNOSTICS_CLUSTER_AVG_MAC_RETRY_APS_MSG_SENT_ATTR_ID        CCPU_TO_LE16(0x011b)
#define ZCL_DIAGNOSTICS_CLUSTER_LAST_MSG_LQI_ATTR_ID                      CCPU_TO_LE16(0x011c)
#define ZCL_DIAGNOSTICS_CLUSTER_LAST_MSG_RSSI_ATTR_ID                     CCPU_TO_LE16(0x011d)

/*
 *\brief ZCL Diagnostics Cluster server side attributes defining macros
 */
#define ZCL_DEFINE_DIAGNOSTICS_CLUSTER_SERVER_ATTRIBUTES() \
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(numberOfResets, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_HW_NUMBER_OF_RESETS_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,       0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(persistentMemoryWrites, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_PERSISTENT_MEMORY_WRITES_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,  0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(macRxBcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_MAC_RX_BCAST_ATTR_ID , ZCL_U32BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(macTxBcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_BCAST_ATTR_ID , ZCL_U32BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(macRxUcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_MAC_RX_UCAST_ATTR_ID , ZCL_U32BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(macTxUcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_UCAST_ATTR_ID , ZCL_U32BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(macTxUcastRetry, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_UCAST_RETRY_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,   0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(macTxUcastFail, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_MAC_TX_UCAST_FAIL_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,    0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsRxBcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_RX_BCAST_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsTxBcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_TX_BCAST_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsRxUcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_RX_UCAST_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,         0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsTxUcastSuccess, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_TX_UCAST_SUCCESS_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID, 0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsTxUcastRetry, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_TX_UCAST_RETRY_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,   0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsTxUcastFail, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_TX_UCAST_FAIL_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,    0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(routeDiscInitiated, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_ROUTE_DISC_INITIATED_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,  0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(neighborAdded, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_NEIGHBOR_ADDED_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,        0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(neighborRemoved, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_NEIGHBOR_REMOVED_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,      0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(neighborStale, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_NEIGHBOR_STALE_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,        0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(joinIndication, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_JOIN_INDICATION_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,      0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(childMoved, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_CHILD_MOVED_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,          0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(nwkFCFailure, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_NWKFC_FAILURE_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,        0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsFCFailure, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APSFC_FAILURE_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,        0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsUnauthorizedKey, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_UNAUTHORIZED_KEY_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID, 0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(nwkDecryptFailures, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_NWK_DECRYPT_FAILURES_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID, 0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(apsDecryptFailures, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_APS_DECRYPT_FAILURES_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID, 0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(packetBufferAllocateFailure, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_PACKET_BUFFER_ALLOCATE_FAILURE_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,   0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(relayedUcast, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_RELAYED_UCAST_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,                    0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(phytoMACqueuelimitreached, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_PHYTOMAC_QUEUE_LIMIT_REACHED_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,     0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(packetValidatedropcount, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_PACKET_VALIDATE_DROP_COUNT_ATTR_ID , ZCL_U16BIT_DATA_TYPE_ID,       0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(averageMACRetryPerAPSMessageSent, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_AVG_MAC_RETRY_APS_MSG_SENT_ATTR_ID, ZCL_U16BIT_DATA_TYPE_ID,        0x0000, 0xffff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(lastMessageLQI, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_LAST_MSG_LQI_ATTR_ID, ZCL_U8BIT_DATA_TYPE_ID,                   0x00, 0xff),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(lastMessageRSSI, ZCL_READONLY_ATTRIBUTE,\
        ZCL_DIAGNOSTICS_CLUSTER_LAST_MSG_RSSI_ATTR_ID, ZCL_S8BIT_DATA_TYPE_ID,                  0x00, 0xff)

/***************************************************************************//**
\brief Diagnostics Cluster definition macros
*******************************************************************************/

#define DIAGNOSTICS_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = DIAGNOSTICS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_DIAGNOSTICS_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_DIAGNOSTICS_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DIAGNOSTICS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = DIAGNOSTICS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_DIAGNOSTICS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_DIAGNOSTICS_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_DIAGNOSTICS_CLUSTER(cltype, clattributes, clcommands) \
    DIAGNOSTICS_CLUSTER_##cltype(clattributes, clcommands)

#define DIAGNOSTICS_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = DIAGNOSTICS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_CLIENT_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_DIAGNOSTICS_CLUSTER_CLIENT_ATTRIBTUES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_DIAGNOSTICS_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DIAGNOSTICS_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands) \
{ \
   .id = DIAGNOSTICS_CLUSTER_ID, \
   .options = { \
                .type = ZCL_SERVER_CLUSTER_TYPE, \
                .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
              }, \
   .attributesAmount = ZCL_DIAGNOSTICS_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_DIAGNOSTICS_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (FLASH_PTR uint8_t *)clcommands \
}

#define DEFINE_DIAGNOSTICS_CLUSTER_FLASH(cltype, clattributes, clcommands) \
    DIAGNOSTICS_CLUSTER_##cltype##_FLASH(clattributes, clcommands)
/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief Diagnostics cluster attributes.
*/
typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }numberOfResets;                      //! <Attr ID 0x0000>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }persistentMemoryWrites;              //! <Attr ID 0x0001>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint32_t value;
    uint32_t minVal;
    uint32_t maxVal;
  }macRxBcast;                          //! <Attr ID 0x0100>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint32_t value;
    uint32_t minVal;
    uint32_t maxVal;
  }macTxBcast;                          //! <Attr ID 0x0101>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint32_t value;
    uint32_t minVal;
    uint32_t maxVal;
  }macRxUcast;                          //! <Attr ID 0x0102>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint32_t value;
    uint32_t minVal;
    uint32_t maxVal;
  }macTxUcast;                          //! <Attr ID 0x0103>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }macTxUcastRetry;                     //! <Attr ID 0x0104>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }macTxUcastFail;                      //! <Attr ID 0x0105>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsRxBcast;                          //! <Attr ID 0x0106>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsTxBcast;                          //! <Attr ID 0x0107>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsRxUcast;                          //! <Attr ID 0x0108>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsTxUcastSuccess;                   //! <Attr ID 0x0109>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsTxUcastRetry;                    //! <Attr ID 0x010a>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsTxUcastFail;                    //! <Attr ID 0x010b>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }routeDiscInitiated;                //! <Attr ID 0x010c>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  } neighborAdded;                    //! <Attr ID 0x010D>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  } neighborRemoved;                  //! <Attr ID 0x010E>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  } neighborStale;                    //! <Attr ID 0x010F>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }joinIndication;                    //! <Attr ID 0x0110>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }childMoved;                        //! <Attr ID 0x0111>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }nwkFCFailure;                      //! <Attr ID 0x0112>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsFCFailure;                      //! <Attr ID 0x0113>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsUnauthorizedKey;                //! <Attr ID 0x0114>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }nwkDecryptFailures;                //! <Attr ID 0x0115>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }apsDecryptFailures;                //! <Attr ID 0x0116>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }packetBufferAllocateFailure;       //! <Attr ID 0x0117>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }relayedUcast;                      //! <Attr ID 0x0118>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }phytoMACqueuelimitreached;         //! <Attr ID 0x0119>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }packetValidatedropcount;           //! <Attr ID 0x011a>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
    uint16_t minVal;
    uint16_t maxVal;
  }averageMACRetryPerAPSMessageSent;  //! <Attr ID 0x011b>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint8_t value;
    uint8_t minVal;
    uint8_t maxVal;
  } lastMessageLQI;                   //! <Attr ID 0x011c>
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    int8_t value;
    int8_t minVal;
    int8_t maxVal;
  } lastMessageRSSI;                  //! <Attr ID 0x011d>
} ZCL_DiagnosticsClusterServerAttributes_t;

END_PACK

#endif /* _ZCLDIAGNOSTICSCLUSTER_H */

