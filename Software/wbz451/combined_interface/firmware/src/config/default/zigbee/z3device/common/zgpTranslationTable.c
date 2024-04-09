/*******************************************************************************
  ZGP Translation Table Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zgpTranslationTable.c

  Summary:
    This file contains the zgp translation table implementation.

  Description:
    This file contains the zgp translation table implementation.
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

#ifdef _GREENPOWER_SUPPORT_

#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC

#ifndef ZGP_DISABLE_TRANSLATION_TABLE
/******************************************************************************
                           Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zgp/GPInfrastructure/highZgp/include/zgpCluster.h>
#include <zgp/GPInfrastructure/highZgp/include/zgpInfraDevice.h>
#include <zcl/include/zclGreenPowerCluster.h>
#include <zcl/include/zclParser.h>
#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>
#include <z3device/clusters/include/haClusters.h>
#include <zcl/include/zclCommandManager.h>
#include <zcl/include/zclAttributes.h>
#include <zcl/include/zclZllidentifyCluster.h>
#include <zcl/include/zclZllScenesCluster.h>
#include <zcl/include/zclZllOnOffCluster.h>
#include <zcl/include/zclZllLevelControlCluster.h>
#include <zcl/include/zclZllColorControlCluster.h>
#include <z3device/common/include/zgpAppInterface.h>
#include <z3device/common/include/zgpAppConfig.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/common/include/appConsts.h>

/**************************************************************************//**
   Define Definitions
******************************************************************************/
#define ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX 0xFF
#define IGNORE_CLUSTER_ID 0xFFFF
#define IGNORE_PROFILE_ID 0xFFFF
#define IGNORE_APP_ENDPOINT 0xFF
#define IGNORE_THIS_FIELD 0xFF
#ifndef ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION
#define ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION 0x04
#endif

#define ZCL_OPTION_DISABLE_DEFAULT_RSP_BIT_POS 4u
#define ZCL_OPTION_MANUFAC_CODE_BIT_POS 2u

#define ZGP_FRAME_REPORT_ATTR_BASIC_FRAME_LENGTH 2 // cluster id

#define ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE (ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION *ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE_SIZE)

#define GENERIC_8C_SWITCH_OPTION_DATA_LENGTH   1
#define GENERIC_8C_SWITCH_ADD_INFO_LENGTH   3

#define ZGP_1_CONTACT_PAIRED 0x01
#define ZGP_2_CONTACTS_PAIRED 0x02
#define ZGP_3_CONTACTS_PAIRED 0x03
#define ZGP_4_CONTACTS_PAIRED 0x04
#define ZGP_5_CONTACTS_PAIRED 0x05
#define ZGP_6_CONTACTS_PAIRED 0x06
#define ZGP_7_CONTACTS_PAIRED 0x07
#define ZGP_8_CONTACTS_PAIRED 0x08

#define ZGP_1ST_CONTACT_MASK  0x01
#define ZGP_2ND_CONTACT_MASK  0x02
#define ZGP_3RD_CONTACT_MASK  0x04
#define ZGP_4TH_CONTACT_MASK  0x08
#define ZGP_5TH_CONTACT_MASK  0x10
#define ZGP_6TH_CONTACT_MASK  0x20
#define ZGP_7TH_CONTACT_MASK  0x40
#define ZGP_8TH_CONTACT_MASK  0x80

#define ZGP_NO_CONTACTS_SAVED 0x00
#define ZGP_NO_OF_CMDS_PER_CONTACT 2
#define ZGP_TRACK_ORDER_ARRAY_INVALID_INDEX 0xFF
#define ZGP_UNKNOWN_SWITCH_TYPE 0x00
#define ZGP_BUTTON_SWITCH_TYPE 0x01
#define ZGP_ROCKER_SWITCH_TYPE 0x02
/**************************************************************************//**
   Type Definitions
******************************************************************************/
BEGIN_PACK
// GP trans table update - actions field
typedef enum PACK
{
  ZGP_TRANS_UPDATE_ACTION_ADD = 0x00,
  ZGP_TRANS_UPDATE_ACTION_REPLACE = 0x01,
  ZGP_TRANS_UPDATE_ACTION_REMOVE = 0x02
} zgpGpTransTableUpdateAction_t;

// GP trans table req fields
typedef struct PACK
{
  uint8_t startIndex;
} zgpGpTransTableReq_t;

typedef struct PACK _ZgpTranslationEntryReadOperation_t
{
  ZGP_GpdId_t *gpdId;
  uint8_t transLookupTableIndex;
  ZGP_ApplicationId_t appId;
  uint8_t gpdEndPoint;
  uint8_t gpdCmdId;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT  
  uint8_t contactStatus;
#endif
  bool ignoreAppId;
  bool ignoreGpdId;
} zgpTranslationEntryReadOperation_t;

typedef struct PACK _ZgpTranslationEntryUpdateOperation_t
{
  ZGP_GpdId_t *gpdId;
  uint8_t lookupTableIndex;
  ZGP_ApplicationId_t appId;
  uint8_t gpdEndPoint;
  uint8_t deviceId;
  uint8_t appEndPoint;
  uint8_t noOfCmds;
  bool isReplaceReq;
  uint8_t totalNoofReports;
  void *reportDescriptor; // array of data point descriptors
  uint8_t *cmdList;  
  zgpSwitchInfo_t switchInfo;
} zgpTranslationEntryUpdateOperation_t;

// GP trans table update entry field
typedef struct PACK
{
  uint8_t index;
  uint8_t gpdCmdId;
  uint8_t endPoint;
  uint16_t profileId;
  uint16_t clusterId;
  uint8_t zclCmdId;
  uint8_t zclCmdPayloadLength;
} zgpTransTableUpdateEntryField_t;

// GP Trans Table Remove operation
typedef struct PACK _ZgpTranslationEntryRemoveOperation_t
{
  ZGP_ApplicationId_t appId;
  ZGP_GpdId_t *gpdId;
  uint8_t gpdEndPoint;
  uint8_t appEndPoint;
  uint8_t gpdCmdId;
  uint16_t profileId;
  uint16_t zclClusterId;  
  uint16_t zclCmdId;
}zgpTransTableEntryRemoveOperation_t;

typedef struct PACK _ZgpAppInfoAndCmdMappingLookupEntry_t
{
  uint8_t gpdAppInfoEntryIndex;
  uint8_t cmdMappingEntryIndex;
} zgpAppInfoAndCmdMappingLookupEntry_t;

#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
typedef struct PACK
{
  uint8_t optionLength: 4;
  uint8_t optionId: 4;
} zgpAddInfoBlockOptionSelector_t;

typedef struct PACK
{
  uint8_t clusterSide: 1;
  uint8_t manufacIdPresent: 1;
  uint8_t reserved: 6;
} zgpCompactReportAttrOption_t;

typedef struct PACK
{
  uint8_t reportId;
  uint8_t attrOffsetWithinReport;
  uint16_t clusterId;
  uint16_t attrId;
  uint8_t attrDataType;
  zgpCompactReportAttrOption_t attrOption;
  uint16_t manufacId;
} zgpCompactReportOptionData_t;

typedef struct PACK _zgpGpdMultiSensorOptionRecord_t
{
  bool isValid;
  zgpAddInfoBlockOptionSelector_t optionSelector;
  zgpCompactReportOptionData_t optionData;
} zgpGpdMultiSensorOptionRecord_t;

typedef struct PACK
{
  uint8_t addInfoBlockLength;
  zgpGpdMultiSensorOptionRecord_t record[ZGP_NO_OF_OPTION_RECORDS_IN_TRANS_ENTRY];
} zgpAddInfoBlock_t;
#endif

typedef struct PACK _ZgpGpdAppInfoEntry_t
{
  ZGP_GpdId_t gpdId;
  uint16_t profileId;
  bool isActiveEntry;
  ZGP_ApplicationId_t appId;
  uint8_t gpdEndPoint;
  uint8_t appEndPoint;
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
  zgpAddInfoBlock_t addInfoBlock;
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
  zgpGenericSwitchConfig_t genericSwitchConfig;
#endif
}zgpGpdAppInfoEntry_t;

#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
typedef struct PACK _ZgpG8csOptionData_t
{
  uint8_t contactStatus;
  uint8_t contactBitmask;  
}zgpG8csOptionData_t;

typedef struct PACK
{
  bool busy;
  uint8_t orderOfContactsPressed[ZGP_NO_OF_CONTACTS_IN_GPD_SWITCH];
  uint8_t gpdAppInfoEntryIndexinTT;
  uint8_t noOfContactsPaired;
  uint8_t lastPressContactStatus;
}zgpTrackOrderOfPressG8CS_t;
#endif 
typedef struct PACK _ZgpSinkTranslationTable_t
{
  zgpGpdAppInfoEntry_t gpdAppInfoEntry[ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION];
  zgpAppInfoAndCmdMappingLookupEntry_t appInfoAndCmdMappingLookupTable[ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE];
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT  
  zgpG8csOptionData_t  g8csOptionData[ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE];
#endif  
} zgpSinkTranslationTable_t;

typedef struct _ZgpCmdMap_t
{
  uint16_t zclClusterId;
  uint8_t zclCmdId;
  uint8_t payloadLength;
  uint8_t payload[ZGP_GPD_ZCL_CMD_MAPPING_PAYLOADLENGTH];
}zgpCmdMap_t;

typedef struct PACK _ZgpEndPointAndZclInfo_t
{
  zgpGpdAppInfoEntry_t gpdAppInfoEntry;
  zgpCmdMap_t cmdMapInfo;
  uint8_t appEndPoint;
  uint8_t gpdCmdId;
} zgpEndPointAndZclInfo_t;

typedef struct PACK _ZgpClusterInfo_t
{
  bool endPointPresent;
  uint8_t noOfEndPoint;
  uint8_t endPointList[APP_ENDPOINTS_AMOUNT];
}zgpClusterInfo_t;

typedef struct PACK _zgpGpdToZclCmdMappingEntry_t
{
  uint8_t gpdCmdId;
  uint16_t zclClusterId;
  uint8_t zclCmdId;
  uint8_t payloadLength;
  uint8_t payload[ZGP_GPD_ZCL_CMD_MAPPING_PAYLOADLENGTH];
}zgpGpdToZclCmdMappingEntry_t;

// GP translation table rsp option field
typedef struct PACK
{
  uint8_t applicationId: 3;
  uint8_t additionalInfoBlockPresent: 1;
  uint8_t reserved : 4;
} zgpTransTableRespOption_t;

// GP translation table response command
typedef struct PACK
{
  ZCL_Status_t status;
  zgpTransTableRespOption_t options;
  uint8_t totalNumberOfEntries;
  uint8_t startIndex;
  uint8_t entriesCount;
  uint8_t tableEntries[ZCL_MAX_TX_ZSDU_SIZE];
} zgpTransTableResp_t;

// GP trans table update cmd option field
typedef struct PACK
{
  uint16_t appId : 3;
  uint16_t action : 2;
  uint16_t noOfTranslations : 3;
  uint16_t additionalInfoBlockPresent:1;
  uint16_t reserved : 7;
} zgpTransTableUpdateFieldOption_t;

// GP trans table update cmd field
typedef struct PACK
{
  zgpTransTableUpdateFieldOption_t options;
  ZGP_GpdId_t gpdId;
  uint8_t endPoint;
  zgpTransTableUpdateEntryField_t entryField;
} zgpTransTableUpdateField_t;
END_PACK
/**************************************************************************//**
   Internal functions
******************************************************************************/
static bool validateAppEndPoint(uint8_t newAppEndPoint, uint8_t *entryAppEndPoint);
static bool getCmdListFromDeviceId(uint8_t deviceId, uint8_t *cmdIndex, uint8_t *cmdCount);
static void addToLookUpTable(uint8_t entryCount, uint8_t transTableIndex, uint8_t cmdIndex);
static bool getDeviceIdFromCmdIndex(uint8_t *deviceId, uint8_t cmdIndex);
static bool isGpdDeviceIdSupported(uint8_t deviceId);
static bool isGpdCmdSupported(uint8_t *deviceId, ZGP_GpdAppInfo_t *appInfo);
static bool getDeviceIdOrCmdListFromClusterId(uint8_t *deviceId, ZGP_GpdAppInfo_t *appInfo);
static bool isTTEntryPresentForGPD(uint8_t entryIndex);
#if defined(ZGP_ON_OFF_SWITCH_ENABLED) || defined(ZGP_LEVEL_CONTROL_SWITCH_ENABLED) || \
    defined(ZGP_COLOR_DIMMER_SWITCH_ENABLED) || defined(ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING) || \
    defined(ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT)
static void copyCmdFromEntry(uint8_t index, uint8_t count, ZGP_GpdAppInfo_t *appInfo);
#endif
static void zgpTransTableCmdIndHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static void zgpTransTableIndHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static void zgpTransRemoveLookUpTableEntries(uint8_t lookupTableIndex, uint8_t transTableIndex, uint8_t cmdIndex);
static void zgpTransTableRemoveEntry(zgpTransTableEntryRemoveOperation_t *transTableEntryRemoveField);
static uint8_t zgpTransTableGetZgpZclMappingInfo(zgpTranslationEntryReadOperation_t *transTableReadparameters, zgpEndPointAndZclInfo_t *zgpZclInfo);
static bool zgpTransTableIsFuncMatching(uint8_t *deviceId, ZGP_GpdAppInfo_t *appInfo, uint8_t noOfEndpoints, uint8_t *endPointList);
static void forwardGpdCmdToAppEndPoint(zgpEndPointAndZclInfo_t *endPointZclInfo, ZCL_Addressing_t *addressing, ZGP_GpdCommand_t *gpdCmdInd, \
                                       uint8_t payloadIndex);
static uint8_t zgpGetAllEndPoints(uint8_t *endPointId);
static bool zgpTransTableAddEntry(zgpTranslationEntryUpdateOperation_t *updateParam, zgpTransTableUpdateEntryField_t *gpdZclMapping, uint8_t *payload);
#ifndef ZGP_LW_TRANSLATION_TABLE
static uint8_t zgpGetTransTableEntries(void);
static void tableRespNotify(ZCL_Notify_t *ntfy);
static ZCL_Status_t zgpTranslationTableRequestHandling(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
static ZCL_Status_t zgpTranslationTableUpdateHandling(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
static void zgpSendTransCommand(ZCL_Request_t *req, bool dir, uint8_t cmdId, uint8_t payLoadLength);
static uint8_t addToGpdZclMappingTable(zgpTransTableUpdateEntryField_t *mappingEntry, uint8_t *payload);
static bool compareZclFields(zgpEndPointAndZclInfo_t *entryInfo, zgpTransTableUpdateEntryField_t *rxdinfo);
#endif
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
static bool zgpUpdateAdditionalInfoBlockForCompactReport(zgpTranslationEntryUpdateOperation_t *updateParam, \
                                                         uint8_t entryIndex);
static bool zgpCheckForReportDescriptorMatch(ZGP_GpdAppInfo_t *appInfo, \
                                        uint8_t noOfEndpoints, uint8_t *endPointList);
static void forwardCompactReportCmdToAppEndPoint(ZCL_Addressing_t *addressing, \
                        zgpEndPointAndZclInfo_t *endPointZclInfo, ZGP_GpdCommand_t *gpdCmdInd);
#ifndef ZGP_LW_TRANSLATION_TABLE
static uint8_t zgpAddAdditionalInfoBlockToResponse(zgpEndPointAndZclInfo_t *zclCmdInfo, uint8_t *payload);
#endif //#ifndef ZGP_LW_TRANSLATION_TABLE
#endif
static bool isGpdServerClusterSupported(ZGP_GpdAppInfo_t *appInfo);
static bool isTranslationAlreadyPresent(uint8_t entryIndex, uint8_t existingCmdIndex, zgpSwitchInfo_t *switchInfo);

#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
static uint8_t getCmdListForG8cs(uint8_t currContactStatus, uint8_t gpdAppInfoIndex, uint8_t *cmdIndex, uint8_t *cmdCount);
static bool addG8csCmdListToLookupTable(uint8_t currContactStatus, uint8_t gpdAppInfoIndex, uint8_t *cmdIndex, uint8_t *cmdCount);
static void gpdG8csSaveOrderOfPress(uint8_t trackIndex, uint8_t saveOrderIndex, uint8_t currNoOfContactsPressed, uint8_t currContactStatus, uint8_t savedContacts);
static bool readUpdateLastPressContactStatus(zgpTranslationEntryReadOperation_t *transTableReadparameters);
#ifdef ZGP_GPD_PROCESSING_IN_APPLICATION_SUPPORTED
static void forwardGpdCmdToApplication(zgpEndPointAndZclInfo_t *endPointZclInfo, ZCL_Addressing_t *addressing, ZGP_GpdCommand_t *gpdCmdInd, \
                                       uint8_t payloadIndex);
#endif // ZGP_GPD_PROCESSING_IN_APPLICATION_SUPPORTED
#endif // ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
/**************************************************************************//**
  Internal varibales
******************************************************************************/
static const uint8_t zgpSupportedGpdDeviceIds[ZGP_SUPPORTED_GPD_DEVICE_ID_LIST_SIZE] = {ZGP_SUPPORTED_GPD_DEVICE_ID_LIST};
static uint8_t zgpTransTableLogicalEntriesCount;

#ifdef ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING
static uint16_t zgpSupportedManufacIds[] = {ZGP_SUPPORTED_MANUFAC_LIST};
static uint16_t zgpSupportedManufacClusterIds[] = {ZGP_MANUFAC_SPECIFIC_CLUSTER_LIST};
#endif

static SYS_EventReceiver_t zgpTransTableCmdIndEvent = { .func = zgpTransTableCmdIndHandler};
static SYS_EventReceiver_t zgpTransTableIndEvent = { .func = zgpTransTableIndHandler};
static zgpGpdToZclCmdMappingEntry_t zgpGpdToZclCmdMappingTable[ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE_SIZE] = {ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE
                                                                                                             ZGP_MANUFAC_SPECIFIC_GPD_CMD_LIST
                                                                                                     };
static zgpSinkTranslationTable_t zgpSinkTranslationTable;

static zgpEndPointAndZclInfo_t zgpZclMappingInfo;

PDS_DECLARE_FILE(ZGP_TRANS_TABLE_MEM_ID, sizeof(zgpSinkTranslationTable), &zgpSinkTranslationTable, NO_FILE_MARKS);
PDS_DECLARE_FILE(ZGP_GPD_ZCL_CMD_MAPPING_TABLE_MEM_ID, sizeof(zgpGpdToZclCmdMappingTable), &zgpGpdToZclCmdMappingTable[0], NO_FILE_MARKS);
typedef union
{
  struct
  {
    APS_DataInd_t zgpApsDataInd;
    uint8_t zgpApsPayload[ZGP_MAX_GSDU_SIZE];
  };
  uint8_t compactReportZclPayload[ZCL_MAX_RX_ZSDU_SIZE];
}zgpZclPayloadToEp_t;

static zgpZclPayloadToEp_t zgpZclPayloadToEp;

#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
static zgpTrackOrderOfPressG8CS_t trackOrderOfPressG8cs[MAX_NO_OF_G8CS_TO_TRACK_ORDER_OF_PRESS];
#endif
/**************************************************************************//**
\brief Initialized the sink translation table
\param[in] resetToFN - status of resetting to factory new
\return none
******************************************************************************/
void ZGP_TransTableInit(bool resetToFN)
{
  uint8_t i;
  zgpGpdAppInfoEntry_t *gpdAppInfoEntry = &zgpSinkTranslationTable.gpdAppInfoEntry[0];

  for(i = 0; i < ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION; i++)
  {
    memset(&gpdAppInfoEntry[i], 0x00, sizeof(gpdAppInfoEntry[i]));
  }
  memset(&zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[0].gpdAppInfoEntryIndex, ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX, sizeof(zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable));

  if (resetToFN)
  {
    zgpTransTableLogicalEntriesCount = 0;
    PDS_Store(ZGP_TRANS_TABLE_MEM_ID);
    return;
  }
  if (PDS_IsAbleToRestore(ZGP_TRANS_TABLE_MEM_ID))
  {
    PDS_Restore(ZGP_TRANS_TABLE_MEM_ID);
  }
  if (PDS_IsAbleToRestore(ZGP_GPD_ZCL_CMD_MAPPING_TABLE_MEM_ID))
  {
    PDS_Restore(ZGP_GPD_ZCL_CMD_MAPPING_TABLE_MEM_ID);
  }

  for (i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
  {
    if (zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex != ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX)
      zgpTransTableLogicalEntriesCount++;
  }

  // Subscribe to translation table events
  SYS_SubscribeToEvent(BC_EVENT_ZGPH_INDICATION, &zgpTransTableCmdIndEvent);
  SYS_SubscribeToEvent(BC_EVENT_ZGPH_TRANS_TABLE_INDICATION, &zgpTransTableIndEvent);
}
#ifndef ZGP_LW_TRANSLATION_TABLE
/**************************************************************************//**
\brief Get total no. of trans table entries
\param[in] none
\return count of translation table entries.
******************************************************************************/
static uint8_t zgpGetTransTableEntries(void)
{
  return zgpTransTableLogicalEntriesCount;
}
#endif
/**************************************************************************//**
\brief To check whether the given GPD device id is supported by sink or not
\param[in] deviceId- device ID
\return true- if device ID supported
        false -if device ID not supported
******************************************************************************/
static bool isGpdDeviceIdSupported(uint8_t deviceId)
{
  for(uint8_t i = 0; i < ZGP_SUPPORTED_GPD_DEVICE_ID_LIST_SIZE; i++)
  {
    if (zgpSupportedGpdDeviceIds[i] == deviceId)
      return true;
  }
  return false;
}

/**************************************************************************//**
\brief To check whether the requested functionality matching with sink
\param[in] deviceId- device ID
           appInfo- appliaction information
\return status
******************************************************************************/
static bool zgpTransTableIsFuncMatching(uint8_t *deviceId, ZGP_GpdAppInfo_t *appInfo, \
                                        uint8_t noOfEndpoints, uint8_t *endPointList)
{
  bool functionalityMatching = false;

  if (isGpdDeviceIdSupported(*deviceId))
  {
    functionalityMatching = true;
    if (appInfo->noOfClusters.numOfClientCluster)
      // Need to getch the gpdCommand for this cluster
      getDeviceIdOrCmdListFromClusterId(NULL, appInfo);
  }
  else
  {
    uint8_t *updateDeviceId = NULL;
    if(*deviceId != ZGP_UNSPECIFIED_DEVICE_ID)
      updateDeviceId = deviceId;
    if (appInfo->appInfoOptions.appDescriptionCommandFollows)
    {
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
      uint8_t pairedEps[APP_ENDPOINTS_AMOUNT];
      uint8_t *pairedEpList = endPointList;

      if (ALL_END_POINT == endPointList[0])
      {
        noOfEndpoints = zgpGetAllEndPoints(pairedEps);
        pairedEpList = &pairedEps[0];
      }
      // Check for the attributes to be reported supported by the device
      functionalityMatching = zgpCheckForReportDescriptorMatch(appInfo, noOfEndpoints, pairedEpList);
#endif
    }
    if (appInfo->noOfGpdCmds)
    {
      if (isGpdCmdSupported(updateDeviceId, appInfo))
      {
        functionalityMatching = true;
      }
    }
    if (appInfo->noOfClusters.numOfClientCluster)
    {
      if (getDeviceIdOrCmdListFromClusterId(updateDeviceId, appInfo))
        functionalityMatching = true;
    }
    if (appInfo->noOfClusters.numOfServerCluster)
    {
      if (isGpdServerClusterSupported(appInfo))
        functionalityMatching = true;
    }
  }

  return functionalityMatching;
}

#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
/**************************************************************************//**
\brief To check whether the received report descriptor cluster matching with sink
\param[in] appInfo- rxd app info
           noOfEndpoints, endPointList - app endPoint info
\return true if cluster matches
        false otherwise
******************************************************************************/
static bool zgpCheckForReportDescriptorMatch(ZGP_GpdAppInfo_t *appInfo, \
                                        uint8_t noOfEndpoints, uint8_t *endPointList)
{
  uint8_t reportDescIndex = 0;
  ZGP_ReportDescriptor_t *currentReportDescriptor = appInfo->reportDescriptor;
  ZGP_DataPointDescriptor_t *dataPointDescriptor = NULL;
  bool isClusterMatching = false;

  while(reportDescIndex < appInfo->totalNoofReports)
  {
    if (currentReportDescriptor)
    {
      dataPointDescriptor = currentReportDescriptor->dataPointDescriptor;
      while (dataPointDescriptor)
      {
        if (dataPointDescriptor->busy)
        {
          uint8_t dir = ZGP_DATAPOINT_DESC_CLIENT_SERVER(dataPointDescriptor->dataPointOptions);
          uint8_t endPointIndex = 0;

          while(endPointIndex < noOfEndpoints)
          {
            if (NULL != ZCL_GetCluster(endPointList[endPointIndex],
                                    dataPointDescriptor->clusterId,
                                    dir))
            {
              isClusterMatching = true;
              break;
            }
            endPointIndex++;
          }
        }
        else
        {
          // This is not expected .. May need to raise assert/notification to the application
         return isClusterMatching;
        }
        if (isClusterMatching)
          break;
        dataPointDescriptor = dataPointDescriptor->nextDataPointDescriptor;
      }
    }
    else
    {
      // This is not expected .. May need to raise assert/notification to the application
      return isClusterMatching;
    }
    reportDescIndex++;
    if (isClusterMatching)
      break;
    currentReportDescriptor = currentReportDescriptor->nextReportDescriptor;
  }
  return isClusterMatching;
}
#endif

/**************************************************************************//**
\brief To check whether the given GPD device id is supported by sink or not
\param[in] deviceId- device ID
           appInfo- appliaction information
\return status
******************************************************************************/
static bool isGpdCmdSupported(uint8_t *deviceId, ZGP_GpdAppInfo_t *appInfo)
{
  for (uint8_t j = 0; j < appInfo->noOfGpdCmds; j++)
  {
    if ((appInfo->gpdCommandList[j] >= ZGP_MANUFAC_SPECIFIC_CMD_ID_START) && (appInfo->gpdCommandList[j] <= ZGP_MANUFAC_SPECIFIC_CMD_ID_END))
    {
#ifdef ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING
      uint8_t manufacIdCnt = sizeof(zgpSupportedManufacIds);
      // This is manufacturer specific cmd so need to check manufac. id also
      while(manufacIdCnt)
      {
        if (zgpSupportedManufacIds[manufacIdCnt-1] == appInfo->manfacId)
           break;
        manufacIdCnt--;
      }

      if (!manufacIdCnt)
        return false;
#else
      return false;
#endif
    }
    for(uint8_t i = 0; i < ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE_SIZE; i++)
    {
      if (zgpGpdToZclCmdMappingTable[i].gpdCmdId && (zgpGpdToZclCmdMappingTable[i].gpdCmdId == appInfo->gpdCommandList[j]))
      {
        if (getDeviceIdFromCmdIndex(deviceId, i))
          return true;
      }
    }
  }
  return false;
}

#if defined(ZGP_ON_OFF_SWITCH_ENABLED) || defined(ZGP_LEVEL_CONTROL_SWITCH_ENABLED) || \
    defined(ZGP_COLOR_DIMMER_SWITCH_ENABLED) || defined(ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING) || \
    defined(ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT)
/**************************************************************************//**
\brief To copy the cmd id from the mapping entry to the given pointer
\param[in] count- Entry count
           index- index of the entry
           appInfo- appliaction information
\return status
******************************************************************************/
static void copyCmdFromEntry(uint8_t count, uint8_t index, ZGP_GpdAppInfo_t *appInfo)
{
  while(count && (appInfo->noOfGpdCmds < (COMM_REQ_COMMAND_COUNT - 1)))
  {
    appInfo->gpdCommandList[appInfo->noOfGpdCmds] = zgpGpdToZclCmdMappingTable[index].gpdCmdId;
    appInfo->noOfGpdCmds++;
    index++;
    count--;
  }
}
#endif

/**************************************************************************//**
\brief To get device id from the corresponding cmd Index
\param[in] deviceId- device ID
           appInfo- appliaction information
\return status
******************************************************************************/
static bool getDeviceIdOrCmdListFromClusterId(uint8_t *deviceId, ZGP_GpdAppInfo_t *appInfo)
{
  for (uint8_t i = 0; i < appInfo->noOfClusters.numOfClientCluster; i++)
  {
#ifdef ZGP_ON_OFF_SWITCH_ENABLED
    if (ONOFF_CLUSTER_ID == appInfo->clusterListClient[i])
    {
      if (deviceId)
        *deviceId = ZGP_ON_OFF_SWITCH;
      else
      {
        copyCmdFromEntry(ZGP_ON_OFF_SWITCH_CMD_LIST_SIZE, ZGP_ON_OFF_SWITCH_CMD_LIST_START_INDEX, appInfo);
      }
      return true;
    }
#endif
#ifdef ZGP_LEVEL_CONTROL_SWITCH_ENABLED
    if (LEVEL_CONTROL_CLUSTER_ID == appInfo->clusterListClient[i])
    {
      if (deviceId)
        *deviceId = ZGP_LEVEL_CONTROL_SWITCH;
      else
      {
        copyCmdFromEntry(ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_SIZE, ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_START_INDEX, appInfo);
      }
      return true;
    }
#endif
#ifdef ZGP_COLOR_DIMMER_SWITCH_ENABLED
    if (COLOR_CONTROL_CLUSTER_ID == appInfo->clusterListClient[i])
    {
      if (deviceId)
        *deviceId = ZGP_COLOR_DIMMER_SWITCH;
      else
      {
        copyCmdFromEntry(ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_SIZE, ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_START_INDEX, appInfo);
      }
      return true;
    }
#endif
#ifdef ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING
    if (appInfo->clusterListClient[i] >= MANUFAC_SPECIFIC_CLUSTER_ID_START)
    {
      uint8_t manufacClusterIdCnt = sizeof(zgpSupportedManufacClusterIds) / sizeof(zgpSupportedManufacClusterIds[0]);

      while(manufacClusterIdCnt)
      {
        if (appInfo->clusterListClient[i] == zgpSupportedManufacClusterIds[manufacClusterIdCnt - 1])
        {
          if (deviceId)
             *deviceId = ZGP_UNSPECIFIED_DEVICE_ID;

          copyCmdFromEntry(ZGP_MANUFAC_SPECIFIC_GPD_CMD_LIST_SIZE, ZGP_MANUFAC_CMD_STARTING_INDEX, appInfo);
          return true;
        }
        manufacClusterIdCnt--;
      }
    }
#endif
  }
  return false;
}

/**************************************************************************//**
\brief To check whether gpd server cluster supported
\param[in] appInfo- appliaction information
\return true - for cluster match
        false otherwise
******************************************************************************/
static bool isGpdServerClusterSupported(ZGP_GpdAppInfo_t *appInfo)
{
  for (uint8_t i = 0; i < appInfo->noOfClusters.numOfServerCluster; i++)
  {
#ifdef ZGP_TEMPERATURE_MEASUREMENT_SENSOR_ENABLED
    if (TEMPERATURE_MEASUREMENT_CLUSTER_ID == appInfo->clusterListServer[i])
    {
      return true;
    }
#endif
#ifdef ZGP_OCCUPANCY_SENSOR_ENABLED
    if (OCCUPANCY_SENSING_CLUSTER_ID == appInfo->clusterListServer[i])
    {
      return true;
    }
#endif
#ifdef ZGP_ILLUMINANCE_MEASUREMENT_SENSOR_ENABLED
    if (ILLUMINANCE_MEASUREMENT_CLUSTER_ID == appInfo->clusterListServer[i])
    {
      return true;
    }
#endif
  }
  return false;
}

/**************************************************************************//**
\brief To get device id from the corresponding cmd Index
\param[in] deviceId- device ID
           cmdIndex- Index of the command
\return status
******************************************************************************/
static bool getDeviceIdFromCmdIndex(uint8_t *deviceId, uint8_t cmdIndex)
{
  bool retValue = false;
  uint8_t deviceIdValue = 0;
#ifdef ZGP_ON_OFF_SWITCH_ENABLED
  if (cmdIndex < (ZGP_ON_OFF_SWITCH_CMD_LIST_START_INDEX + ZGP_ON_OFF_SWITCH_CMD_LIST_SIZE))
  {
    deviceIdValue = ZGP_ON_OFF_SWITCH;
    retValue = true;
  }
#endif
#ifdef ZGP_LEVEL_CONTROL_SWITCH_ENABLED
  if ((cmdIndex >= ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_START_INDEX) && \
      (cmdIndex < (ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_START_INDEX + ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_SIZE)))
  {
    deviceIdValue = ZGP_LEVEL_CONTROL_SWITCH;
    retValue = true;
  }
#endif
#ifdef ZGP_COLOR_DIMMER_SWITCH_ENABLED
  if ((cmdIndex >= ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_START_INDEX) && \
      (cmdIndex < (ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_START_INDEX + ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_SIZE)))
  {
    deviceIdValue = ZGP_COLOR_DIMMER_SWITCH;
    retValue = true;
  }
#endif
#ifdef ZGP_SINK_ENABLE_MANUFAC_SPECIFIC_HANDLING
  if ((cmdIndex >= ZGP_MANUFAC_CMD_STARTING_INDEX) && \
      (cmdIndex < (ZGP_MANUFAC_CMD_STARTING_INDEX + ZGP_MANUFAC_SPECIFIC_GPD_CMD_LIST_SIZE)))
  {
    deviceIdValue = ZGP_UNSPECIFIED_DEVICE_ID;
    retValue = true;
  }
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
  if ((cmdIndex >= ZGP_G8CS_1C_CMD_LIST_START_INDEX) && \
      (cmdIndex < (ZGP_G8CS_ROCKER_8C_CMD_LIST_START_INDEX + ZGP_G8CS_1C_CMD_LIST_SIZE)))
  {
    deviceIdValue = ZGP_GENERIC_8_CONTACT_SWITCH;
    retValue = true;
  }
#endif
  if(deviceId != NULL)
    *deviceId = deviceIdValue;
  return retValue;
}
/**************************************************************************//**
\brief To fetch the command list from the device id
\param[in] deviceId- device ID
           cmdIndex- Index of the command
           cmdCount - command count
\return status
******************************************************************************/
static bool getCmdListFromDeviceId(uint8_t deviceId, uint8_t *cmdIndex, uint8_t *cmdCount)
{
  switch (deviceId)
  {
#ifdef ZGP_ON_OFF_SWITCH_ENABLED
  case ZGP_ON_OFF_SWITCH:
    *cmdIndex = ZGP_ON_OFF_SWITCH_CMD_LIST_START_INDEX;
    *cmdCount = ZGP_ON_OFF_SWITCH_CMD_LIST_SIZE;
  return true;
#endif
#ifdef ZGP_LEVEL_CONTROL_SWITCH_ENABLED
  case ZGP_LEVEL_CONTROL_SWITCH:
    *cmdIndex = ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_START_INDEX;
    *cmdCount = ZGP_LEVEL_CONTROL_SWITCH_CMD_LIST_SIZE;
  return true;
#endif
#ifdef ZGP_COLOR_DIMMER_SWITCH_ENABLED
  case ZGP_COLOR_DIMMER_SWITCH:
    *cmdIndex = ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_START_INDEX;
    *cmdCount = ZGP_COLOR_DIMMER_SWITCH_CMD_LIST_SIZE;
  return true;
#endif
#if defined(ZGP_TEMPERATURE_MEASUREMENT_SENSOR_ENABLED) || \
    defined(ZGP_OCCUPANCY_SENSOR_ENABLED) || \
    defined(ZGP_ILLUMINANCE_MEASUREMENT_SENSOR_ENABLED)
  case ZGP_OCCUPANCY_SENSOR:
  case ZGP_TEMPERATURE_SENSOR:
  case ZGP_LIGHT_SENSOR:
    *cmdIndex = ZGP_ATTR_REPORT_START_INDEX;
    *cmdCount = ZGP_ATTR_REPORT_CMD_LIST_SIZE + ZGP_ZCL_TUNNELING_CMD_LIST_SIZE;
  return true;
#endif
  default:
    return false;
  }
}

/*************************************************************************//**
\brief Add trans table index and cmd index to lookup table
\param[in] entryCount- entry count
           transTableIndex- Index of the translation table
           cmdIndex - command index
\return none
******************************************************************************/
static void addToLookUpTable(uint8_t entryCount, uint8_t transTableIndex, uint8_t cmdIndex)
{
  uint8_t newEntryIndex = 0;

  for (uint8_t i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
  {
    if (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex)
    {
      zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex = transTableIndex;
      zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].cmdMappingEntryIndex = cmdIndex;
      newEntryIndex++;
      cmdIndex++;
      zgpTransTableLogicalEntriesCount++;
      if (newEntryIndex >= entryCount)
        break;
    }
  }
}
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
/**************************************************************************//**
\brief To fetch the command list for diff contact combination in generic 8 contact switch
\param[in] currContactStatus- contactStatus in appinfo
           cmdIndex- Index of the command
           cmdCount - command count
\return total no of contacts paired so far
******************************************************************************/
static uint8_t getCmdListForG8cs(uint8_t currContactStatus, uint8_t gpdAppInfoIndex, uint8_t *cmdIndex, uint8_t *cmdCount)
{
  uint8_t totalNoOfContactsPaired = 0;
  uint8_t collectAllContactStatus = 0;

  // count no of contacts paired so far
  for (uint8_t i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
  {
    if (gpdAppInfoIndex == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex)
    {
      collectAllContactStatus |= zgpSinkTranslationTable.g8csOptionData[i].contactStatus;
    }
  }
  // include the current contact status
  collectAllContactStatus |= currContactStatus;
  for(uint8_t i=0; i < ZGP_8_CONTACTS_PAIRED; i++)
  {
    if(collectAllContactStatus & (ZGP_1_CONTACT_PAIRED << i))
      totalNoOfContactsPaired++;
  }
  // based on the switch type and totalNoOfContactsPaired, decide the cmd list
  if((zgpSinkTranslationTable.gpdAppInfoEntry[gpdAppInfoIndex].genericSwitchConfig.switchType == ZGP_BUTTON_SWITCH_TYPE) ||
     (zgpSinkTranslationTable.gpdAppInfoEntry[gpdAppInfoIndex].genericSwitchConfig.switchType == ZGP_UNKNOWN_SWITCH_TYPE))  // unknown switch type is considered as button as of now
  {
    switch (totalNoOfContactsPaired)
    {
      case ZGP_1_CONTACT_PAIRED:
        *cmdIndex = ZGP_G8CS_1C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_1C_CMD_LIST_SIZE;
        break;
      case ZGP_2_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_2C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_2C_CMD_LIST_SIZE;
        break;
      case ZGP_3_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_3C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_3C_CMD_LIST_SIZE;
        break;
      case ZGP_4_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_4C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_4C_CMD_LIST_SIZE;
        break;
      case ZGP_5_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_5C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_5C_CMD_LIST_SIZE;
        break;
      case ZGP_6_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_6C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_6C_CMD_LIST_SIZE;
        break;
      case ZGP_7_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_7C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_7C_CMD_LIST_SIZE;
        break;
      case ZGP_8_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_8C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_8C_CMD_LIST_SIZE;
        break;
      default:
        break;
    }
  }
  else if(zgpSinkTranslationTable.gpdAppInfoEntry[gpdAppInfoIndex].genericSwitchConfig.switchType == ZGP_ROCKER_SWITCH_TYPE)
  {
    switch (totalNoOfContactsPaired)
    {
      case ZGP_1_CONTACT_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_1C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_1C_CMD_LIST_SIZE;
        break;
      case ZGP_2_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_2C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_2C_CMD_LIST_SIZE;
        break;
      case ZGP_3_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_3C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_3C_CMD_LIST_SIZE;
        break;
      case ZGP_4_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_4C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_4C_CMD_LIST_SIZE;
        break;
      case ZGP_5_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_5C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_5C_CMD_LIST_SIZE;
        break;
      case ZGP_6_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_6C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_6C_CMD_LIST_SIZE;
        break;
      case ZGP_7_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_7C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_7C_CMD_LIST_SIZE;
        break;
      case ZGP_8_CONTACTS_PAIRED:
        *cmdIndex = ZGP_G8CS_ROCKER_8C_CMD_LIST_START_INDEX;
        *cmdCount = ZGP_G8CS_8C_CMD_LIST_SIZE;       
        break;
      default:
        break;
    }
  }
  return totalNoOfContactsPaired;
}
/*************************************************************************//**
\brief get cmd list and Add trans table index & cmd index to lookup table for
       generic 8-contact switch
\param[in] trackIndex- index for trackOrderOfPressG8cs array
           saveOrderIndex- Index for orderOfContactsPressed array
           currNoOfContactsPressed - no of contacts currently pressed
           currContactStatus - current Contact Status
\return none
******************************************************************************/
static void gpdG8csSaveOrderOfPress(uint8_t trackIndex, uint8_t saveOrderIndex, uint8_t currNoOfContactsPressed, uint8_t currContactStatus, uint8_t savedContacts)
{
  if((currContactStatus & ZGP_1ST_CONTACT_MASK) && (!(savedContacts & ZGP_1ST_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_1ST_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_2ND_CONTACT_MASK) && (!(savedContacts & ZGP_2ND_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_2ND_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_3RD_CONTACT_MASK) && (!(savedContacts & ZGP_3RD_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_3RD_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_4TH_CONTACT_MASK) && (!(savedContacts & ZGP_4TH_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_4TH_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_5TH_CONTACT_MASK) && (!(savedContacts & ZGP_5TH_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_5TH_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_6TH_CONTACT_MASK) && (!(savedContacts & ZGP_6TH_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_6TH_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_7TH_CONTACT_MASK) && (!(savedContacts & ZGP_7TH_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_7TH_CONTACT_MASK;
    saveOrderIndex++;
  }
  if((currContactStatus & ZGP_8TH_CONTACT_MASK) && (!(savedContacts & ZGP_8TH_CONTACT_MASK)))
  {
    trackOrderOfPressG8cs[trackIndex].orderOfContactsPressed[saveOrderIndex] = ZGP_8TH_CONTACT_MASK;
    saveOrderIndex++;
  }
}
/*************************************************************************//**
\brief get cmd list and Add trans table index & cmd index to lookup table for
       generic 8-contact switch
\param[in] entryCount- entry count
           transTableIndex- Index of the translation table
           cmdIndex - command index
\return true - cmd list matched for device id
        false - otherwise
******************************************************************************/
static bool addG8csCmdListToLookupTable(uint8_t currContactStatus, uint8_t gpdAppInfoIndex, uint8_t *cmdIndex, uint8_t *cmdCount)
{
  bool retStatus = false;
  uint8_t totalNoOfContactsPaired = 0;
  uint8_t trackOrderIndex = ZGP_TRACK_ORDER_ARRAY_INVALID_INDEX;
  uint8_t currNoOfContactsPressed = 0;
  uint8_t i = 0;
  uint8_t j = 0;
  uint8_t matchCountinTTEntry = 0;
  uint8_t savedContacts = 0;
  
  if(currContactStatus == ZGP_NO_CONTACTS_SAVED)
    return retStatus;

  // find no of contacts pressed currently
  for(i = 0; i < ZGP_8_CONTACTS_PAIRED; i++)
  {
    if(currContactStatus & (ZGP_1_CONTACT_PAIRED << i))
      currNoOfContactsPressed++;
  }
  totalNoOfContactsPaired = getCmdListForG8cs(currContactStatus, gpdAppInfoIndex, cmdIndex , cmdCount);
  if(totalNoOfContactsPaired != 0 && totalNoOfContactsPaired <= ZGP_NO_OF_CONTACTS_IN_GPD_SWITCH)
  {
    retStatus = true;
   // save the current contact status
    for(i = 0; i < MAX_NO_OF_G8CS_TO_TRACK_ORDER_OF_PRESS; i++)
    {
      if(trackOrderOfPressG8cs[i].gpdAppInfoEntryIndexinTT == gpdAppInfoIndex)
      {
        trackOrderIndex = i;
        // collect all contacts save for this gpd
        for(uint8_t k = 0; k < ZGP_NO_OF_CONTACTS_IN_GPD_SWITCH; k++)
        {
          savedContacts |= trackOrderOfPressG8cs[i].orderOfContactsPressed[k];
        }
        for(j = 0; j < ZGP_NO_OF_CONTACTS_IN_GPD_SWITCH; j++)
        {
          if(trackOrderOfPressG8cs[i].orderOfContactsPressed[j] == ZGP_NO_CONTACTS_SAVED)
          {
            gpdG8csSaveOrderOfPress(trackOrderIndex, j, currNoOfContactsPressed, currContactStatus, savedContacts);
            trackOrderOfPressG8cs[i].noOfContactsPaired = totalNoOfContactsPaired;
            break;
          }
        }
        break;
      }
    }
    if(ZGP_TRACK_ORDER_ARRAY_INVALID_INDEX == trackOrderIndex) // new addition
    {
      for(i = 0; i < MAX_NO_OF_G8CS_TO_TRACK_ORDER_OF_PRESS; i++)
      { 
        if(!trackOrderOfPressG8cs[i].busy)
        {
          trackOrderIndex = i;
          trackOrderOfPressG8cs[i].busy = true;
          trackOrderOfPressG8cs[i].gpdAppInfoEntryIndexinTT = gpdAppInfoIndex;
          gpdG8csSaveOrderOfPress(i, 0, currNoOfContactsPressed, currContactStatus, 0);
          trackOrderOfPressG8cs[i].noOfContactsPaired = totalNoOfContactsPaired;
          retStatus = true;
          break;
        }
        else
          retStatus = false;
      }
    }
    
    // Remove existing entries and create new TT entries as per total no of contacts paired so far
    zgpTransRemoveLookUpTableEntries(ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX, gpdAppInfoIndex , ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX);
    addToLookUpTable(*cmdCount, gpdAppInfoIndex, *cmdIndex);
   
    matchCountinTTEntry = 0;
    // update the contactStatus and contactBitmask in the translation table entries
    for (i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
    {
      if (gpdAppInfoIndex == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex)
      {
        uint8_t orderIndex = matchCountinTTEntry/ZGP_NO_OF_CMDS_PER_CONTACT;
        zgpSinkTranslationTable.g8csOptionData[i].contactStatus = trackOrderOfPressG8cs[trackOrderIndex].orderOfContactsPressed[orderIndex];
        zgpSinkTranslationTable.g8csOptionData[i].contactBitmask = trackOrderOfPressG8cs[trackOrderIndex].orderOfContactsPressed[orderIndex];
        matchCountinTTEntry++;

        if(matchCountinTTEntry >= (ZGP_NO_OF_CMDS_PER_CONTACT *totalNoOfContactsPaired))
          break;
      }
    }
    if(trackOrderOfPressG8cs[trackOrderIndex].noOfContactsPaired == zgpSinkTranslationTable.gpdAppInfoEntry[gpdAppInfoIndex].genericSwitchConfig.noOfContacts)
    {
      //trackOrderOfPressG8cs[trackOrderIndex].busy = false;
      memset(&trackOrderOfPressG8cs[i], 0, sizeof(zgpTrackOrderOfPressG8CS_t));
    }
  }
  return retStatus;
}
#endif // ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
/*************************************************************************//**
\brief Check whether any TT entry present for a particular GPDID and App info paremeters
\param[in] entryIndex - index for gpdAppInfoEntry array
\return true/false
******************************************************************************/
static bool isTTEntryPresentForGPD(uint8_t entryIndex)
{
  for (uint8_t i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
  {
    if (entryIndex == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex)
    {
      return true;
    }
  }
  return false;
}
/*************************************************************************//**
\brief Check whether the given cmd id exists in the cmd mapping table
\param[in] gpdCmd -command of ZGPD
           contactStatus - applicable for 8-bit vector press and release command
\return status
******************************************************************************/
static uint8_t gpdZclCmdMappingEntryExists(uint8_t gpdCmd, uint16_t zclClusterId, uint8_t zclCmd, uint8_t entryIndex, zgpSwitchInfo_t *switchInfo, bool *isTTEntryAdded)
{
  uint8_t i = 0;
  uint8_t cmdMappingTableIndex = ZGP_ENTRY_INVALID_INDEX;
  if(NULL != isTTEntryAdded)
    *isTTEntryAdded = false;
  for (i = 0; i < ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE_SIZE; i++)
  {
    if (zgpGpdToZclCmdMappingTable[i].gpdCmdId == gpdCmd)
    {
      if(zclClusterId != IGNORE_CLUSTER_ID) // if valid
      {
        if(zgpGpdToZclCmdMappingTable[i].zclClusterId == zclClusterId)
        {
          if(zclCmd != IGNORE_THIS_FIELD)
          {
            if(zgpGpdToZclCmdMappingTable[i].zclCmdId == zclCmd)
            {
              cmdMappingTableIndex = i;
            }
          }
          else
          {
            cmdMappingTableIndex = i;
          }
        }
      }
      else
      {
        cmdMappingTableIndex = i;
      }
    }

    if((cmdMappingTableIndex != ZGP_ENTRY_INVALID_INDEX)  && (ZGP_ENTRY_INVALID_INDEX != entryIndex))
    {
      if(isTranslationAlreadyPresent(entryIndex, cmdMappingTableIndex, switchInfo))
      {
        if(NULL != isTTEntryAdded)
        {
          *isTTEntryAdded = true;
        }
        return cmdMappingTableIndex;
      }
      else
        continue;
        
    }
    else if(cmdMappingTableIndex != ZGP_ENTRY_INVALID_INDEX)
      return cmdMappingTableIndex;
  }
  return cmdMappingTableIndex;
}
#ifndef ZGP_LW_TRANSLATION_TABLE
/*************************************************************************//**
\brief Add to gpd cmd - zcl cmd mapping table
\param[in] mappingEntry - mapping entry info
           payload - payload info
\returnm status
******************************************************************************/
static uint8_t addToGpdZclMappingTable(zgpTransTableUpdateEntryField_t *mappingEntry, uint8_t *payload)
{
  uint8_t i = ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE_DEFAULT_SIZE + ZGP_MANUFAC_SPECIFIC_GPD_CMD_LIST_SIZE;

  for (; i < ZGP_GPD_CMD_TO_ZCL_CMD_MAPPING_TABLE_SIZE; i++)
  {
    if (!zgpGpdToZclCmdMappingTable[i].gpdCmdId)
    {
      zgpGpdToZclCmdMappingTable[i].gpdCmdId = mappingEntry->gpdCmdId;
      zgpGpdToZclCmdMappingTable[i].zclCmdId = mappingEntry->zclCmdId;
      zgpGpdToZclCmdMappingTable[i].zclClusterId = mappingEntry->clusterId;
      zgpGpdToZclCmdMappingTable[i].payloadLength = mappingEntry->zclCmdPayloadLength;
      if (mappingEntry->zclCmdPayloadLength && (mappingEntry->zclCmdPayloadLength < UNSPECIFIED_LENGTH))
      {
        memcpy(zgpGpdToZclCmdMappingTable[i].payload, payload, sizeof(zgpGpdToZclCmdMappingTable[i].payload));
      }
      // stroing to PDS
      PDS_Store(ZGP_GPD_ZCL_CMD_MAPPING_TABLE_MEM_ID);
      return i;
    }
  }
  return ZGP_ENTRY_INVALID_INDEX;
}
#endif
/**************************************************************************//**
\brief Add or update the translation table entry
\param[in] updateParam - update parameter info
          gpdZclMapping - scl mapping info
          payload - payload info
\return status
******************************************************************************/
static bool zgpTransTableAddEntry(zgpTranslationEntryUpdateOperation_t *updateParam, zgpTransTableUpdateEntryField_t *gpdZclMapping, uint8_t *payload)
{
  uint8_t entryIndex = ZGP_ENTRY_INVALID_INDEX;
  uint8_t i;
  ZGP_ApplicationId_t appId = updateParam->appId;
  uint8_t gpdEndPoint = updateParam->gpdEndPoint;
  zgpGpdAppInfoEntry_t *gpdAppInfoEntry = &zgpSinkTranslationTable.gpdAppInfoEntry[0];
  bool transTableEntryFound = false;

  for (i = 0; i < ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION; i++)
  {
    if (gpdAppInfoEntry[i].isActiveEntry)
    {
      if (appId == gpdAppInfoEntry[i].appId)
      {
        if ((ZGP_SRC_APPID == appId) && (updateParam->gpdId->gpdSrcId == gpdAppInfoEntry[i].gpdId.gpdSrcId))
        {
          if (!validateAppEndPoint(updateParam->appEndPoint, &gpdAppInfoEntry[i].appEndPoint))
          {
            if(((gpdZclMapping != NULL) && (gpdZclMapping->profileId == gpdAppInfoEntry[i].profileId)) || \
               (gpdZclMapping == NULL))
            {
              transTableEntryFound = true;

              if (!updateParam->noOfCmds && !updateParam->totalNoofReports && (ZGP_ENTRY_INVALID_INDEX == updateParam->lookupTableIndex)
                  && (updateParam->deviceId != ZGP_GENERIC_8_CONTACT_SWITCH))
                return true;
              else
              {
                entryIndex = i;
                break;
              }
            }
          }
        }
        else if ((ZGP_IEEE_ADDR_APPID == appId) && (updateParam->gpdId->gpdIeeeAddr == gpdAppInfoEntry[i].gpdId.gpdIeeeAddr))
        {
          if ((ALL_END_POINT == gpdAppInfoEntry[i].gpdEndPoint) || \
              (ALL_END_POINT == gpdEndPoint) || \
              (gpdEndPoint == gpdAppInfoEntry[i].gpdEndPoint))
          {
            if (!validateAppEndPoint(updateParam->appEndPoint, &gpdAppInfoEntry[i].appEndPoint))
            {
            if(((gpdZclMapping != NULL) && (gpdZclMapping->profileId == gpdAppInfoEntry[i].profileId)) || \
               (gpdZclMapping == NULL))
              {
                transTableEntryFound = true;

                if (!updateParam->noOfCmds && !updateParam->totalNoofReports && (ZGP_ENTRY_INVALID_INDEX == updateParam->lookupTableIndex)
                    && (updateParam->deviceId != ZGP_GENERIC_8_CONTACT_SWITCH))
                  return true;
                else
                {
                  entryIndex = i;
                  break;
                }
              }
            }
          }
        }
      }
    }
    else
      entryIndex = i;
  }

  if (transTableEntryFound || (!transTableEntryFound && (entryIndex != ZGP_ENTRY_INVALID_INDEX)))
  {
    uint8_t cmdIndex = 0;
    uint8_t cmdCount = 0;
    uint16_t zclClusterId = IGNORE_CLUSTER_ID;
    uint8_t zclCmdId     = IGNORE_THIS_FIELD;
    if(gpdZclMapping !=  NULL)
    {
      zclClusterId = gpdZclMapping->clusterId;
      zclCmdId = gpdZclMapping->zclCmdId;
    }

    if (!transTableEntryFound)
    {
      memset(&gpdAppInfoEntry[entryIndex], 0x00, sizeof(gpdAppInfoEntry[entryIndex]));
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
      gpdAppInfoEntry[entryIndex].addInfoBlock.addInfoBlockLength = 0x00;
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
      memcpy(&gpdAppInfoEntry[entryIndex].genericSwitchConfig, &updateParam->switchInfo.genericSwitchConfig, sizeof(zgpGenericSwitchConfig_t));
#endif
      gpdAppInfoEntry[entryIndex].appId = appId;
      if (ZGP_SRC_APPID == appId)
        gpdAppInfoEntry[entryIndex].gpdId.gpdSrcId = updateParam->gpdId->gpdSrcId;
      else
      {
        gpdAppInfoEntry[entryIndex].gpdEndPoint = gpdEndPoint;
        gpdAppInfoEntry[entryIndex].gpdId.gpdIeeeAddr = updateParam->gpdId->gpdIeeeAddr;
      }
      gpdAppInfoEntry[entryIndex].appEndPoint = updateParam->appEndPoint;
      if (gpdZclMapping)
        gpdAppInfoEntry[entryIndex].profileId = gpdZclMapping->profileId;
      else
        gpdAppInfoEntry[entryIndex].profileId = APP_PROFILE_ID;
      if (updateParam->deviceId)
      {
        // this is for commissioning we can remove the existing command entries
        zgpTransRemoveLookUpTableEntries(ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX, entryIndex , ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX);
      }
    }

    // no addition to gpd zcl cmd mapping table
    if (updateParam->deviceId)
    {
      bool matching = false;
      bool includeDefaultTranslations = true;
      
      if(updateParam->noOfCmds)
      {
        uint8_t i = updateParam->noOfCmds;
        if(getCmdListFromDeviceId(updateParam->deviceId, &cmdIndex , &cmdCount))
        {
          while(i)
          {
            for(uint8_t j = cmdIndex; j < cmdCount; j++)
            {
              if(updateParam->cmdList[i - 1] == zgpGpdToZclCmdMappingTable[j].gpdCmdId) 
              {
                includeDefaultTranslations = false;
                break;
              }
            }
            if(!includeDefaultTranslations)
              break;
            i--;
          }
        }
      }

      if ((ZGP_UNSPECIFIED_DEVICE_ID != updateParam->deviceId) && includeDefaultTranslations)
      {
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
        if(updateParam->deviceId == ZGP_GENERIC_8_CONTACT_SWITCH)
        {
          matching = addG8csCmdListToLookupTable(updateParam->switchInfo.currContactStatus, entryIndex, &cmdIndex , &cmdCount);
        }
        else if(getCmdListFromDeviceId(updateParam->deviceId, &cmdIndex , &cmdCount))
#else
        if (getCmdListFromDeviceId(updateParam->deviceId, &cmdIndex , &cmdCount))
#endif
        {
          matching = true;
          addToLookUpTable(cmdCount, entryIndex, cmdIndex);
        }
      }
      while (updateParam->noOfCmds)
      {
        // check in the cmd mapping table
        // If found, then add the entry in lookup table with trans entry index & cmd index
        if (ZGP_ENTRY_INVALID_INDEX != (cmdIndex = gpdZclCmdMappingEntryExists(updateParam->cmdList[updateParam->noOfCmds - 1], zclClusterId, zclCmdId, ZGP_ENTRY_INVALID_INDEX, NULL, NULL)))
        {
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT          
          if(updateParam->cmdList[updateParam->noOfCmds - 1] == ZGP_8_BIT_VECTOR_PRESS ||
             updateParam->cmdList[updateParam->noOfCmds - 1] == ZGP_8_BIT_VECTOR_RELEASE)
          {
            matching = addG8csCmdListToLookupTable(updateParam->switchInfo.currContactStatus, entryIndex, &cmdIndex , &cmdCount); 
          }
          else
#endif
          {
            matching = true;
            addToLookUpTable(1, entryIndex, cmdIndex);
          }
        }
        updateParam->noOfCmds--;
      }
      gpdAppInfoEntry[entryIndex].isActiveEntry = true;

#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
      if (updateParam->totalNoofReports)
      {
        if (ZGP_ENTRY_INVALID_INDEX != (cmdIndex = gpdZclCmdMappingEntryExists((uint8_t)ZGP_COMPACT_ATTR_REPORT_CMD_ID, zclClusterId, zclCmdId, ZGP_ENTRY_INVALID_INDEX, NULL, NULL)))
        {
          matching = true;
          addToLookUpTable(1, entryIndex, cmdIndex);
          // There are report descriptors need to be added to translation table entry(additional information block fields)
          zgpUpdateAdditionalInfoBlockForCompactReport(updateParam, entryIndex);
        }
      }
#endif
      if (matching)
        gpdAppInfoEntry[entryIndex].isActiveEntry = true;

      PDS_Store(ZGP_TRANS_TABLE_MEM_ID);

      return matching;

    }
#ifndef ZGP_LW_TRANSLATION_TABLE
    else
    {
      uint8_t existingCmdIndex = 0;
      bool isTTEntryAdded = false;
      if (ZGP_ENTRY_INVALID_INDEX == (existingCmdIndex = gpdZclCmdMappingEntryExists(gpdZclMapping->gpdCmdId, zclClusterId, zclCmdId, ZGP_ENTRY_INVALID_INDEX, NULL, NULL)))
      {
        if ( ZGP_ENTRY_INVALID_INDEX ==(cmdIndex = addToGpdZclMappingTable(gpdZclMapping, payload)))
        {
          // drop the request
          return false;
        }
      }
      else
        cmdIndex = existingCmdIndex;

      if (ZGP_ENTRY_INVALID_INDEX != updateParam->lookupTableIndex)
      {
        if((zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[updateParam->lookupTableIndex].cmdMappingEntryIndex == ZGP_ENTRY_INVALID_INDEX) &&
           (zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[updateParam->lookupTableIndex].gpdAppInfoEntryIndex == ZGP_ENTRY_INVALID_INDEX))
          zgpTransTableLogicalEntriesCount++;
        zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[updateParam->lookupTableIndex].cmdMappingEntryIndex = cmdIndex; // newly added command index
        zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[updateParam->lookupTableIndex].gpdAppInfoEntryIndex = entryIndex;
      }
      else
      {
        //find the index to be replaced
        existingCmdIndex = gpdZclCmdMappingEntryExists(gpdZclMapping->gpdCmdId, zclClusterId, IGNORE_THIS_FIELD, entryIndex, &updateParam->switchInfo, &isTTEntryAdded);
        if (updateParam->isReplaceReq)
        {
          zgpTransRemoveLookUpTableEntries(ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX, entryIndex , existingCmdIndex);
        }
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT        
        if(!isTTEntryAdded || (isTTEntryAdded && updateParam->isReplaceReq))
#endif
          addToLookUpTable(1, entryIndex, cmdIndex);
      }
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
      if (updateParam->totalNoofReports)
      {
        // additional info block is expected and gpd command id should be compact attribute report or ZGP_8_BIT_VECTOR_PRESS or ZGP_8_BIT_VECTOR_RELEASE
        uint8_t addInfoBlockLength = *(uint8_t *)updateParam->reportDescriptor;
        uint8_t *addInfoBlock = (uint8_t *)updateParam->reportDescriptor + 1;
        uint8_t addInfoIndex = 0;

        for (uint8_t i = 0; i < ZGP_NO_OF_OPTION_RECORDS_IN_TRANS_ENTRY; i++)
        {
          if (!gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].isValid)
          {
            gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].isValid = true;
            memcpy(&gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].optionSelector, &addInfoBlock[addInfoIndex], \
                                         sizeof(gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].optionSelector));
            addInfoIndex++;
            memcpy(&gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].optionData, &addInfoBlock[addInfoIndex], \
                    (gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].optionSelector.optionLength + 1));
            addInfoIndex += (gpdAppInfoEntry[entryIndex].addInfoBlock.record[i].optionSelector.optionLength + 1);
            if (addInfoIndex > addInfoBlockLength)
            {
              return false;
            }
            else
            {
              gpdAppInfoEntry[entryIndex].addInfoBlock.addInfoBlockLength += addInfoBlockLength;
              if (addInfoIndex == addInfoBlockLength)
              {
                // all options records have been processed
                break;
              }
            }
          }
        }
      }
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
      if(updateParam->switchInfo.switchInfoLength)
      {
        for (uint8_t i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
        {
          if(zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex == entryIndex)
          {
            if((cmdIndex == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].cmdMappingEntryIndex) &&
             ((zgpSinkTranslationTable.g8csOptionData[i].contactStatus == updateParam->switchInfo.currContactStatus) ||
              (zgpSinkTranslationTable.g8csOptionData[i].contactStatus == ZGP_NO_CONTACTS_SAVED)))
            {
              zgpSinkTranslationTable.g8csOptionData[i].contactBitmask = updateParam->switchInfo.contactBitMask;
              if(zgpSinkTranslationTable.g8csOptionData[i].contactStatus == ZGP_NO_CONTACTS_SAVED) // new entry
                zgpSinkTranslationTable.g8csOptionData[i].contactStatus = updateParam->switchInfo.currContactStatus;
              break;
            }
          }
        }
      }
#endif      
      gpdAppInfoEntry[entryIndex].isActiveEntry = true;
    }
#endif //#ifndef ZGP_LW_TRANSLATION_TABLE

    PDS_Store(ZGP_TRANS_TABLE_MEM_ID);
    return true;
  }
  else
    return false;
}

/**************************************************************************//**
\brief Update additional information block
param[in] updateParam - update param fields
          entryIndex - entry index
\return true - for successful update
        false - otherwise
******************************************************************************/
static bool isTranslationAlreadyPresent(uint8_t entryIndex, uint8_t existingCmdIndex, zgpSwitchInfo_t *switchInfo)
{
    if(ZGP_ENTRY_INVALID_INDEX == existingCmdIndex)
      return false;

   for (uint8_t i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
   {
     if(zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex == entryIndex)
     {
       if(existingCmdIndex == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].cmdMappingEntryIndex)
       {
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
          if(NULL != switchInfo)
          {
            if(((zgpSinkTranslationTable.g8csOptionData[i].contactStatus == switchInfo->currContactStatus) ||
              (zgpSinkTranslationTable.g8csOptionData[i].contactStatus == ZGP_NO_CONTACTS_SAVED)))
              return true;
            else
              return false;
          }
          else
#endif
            return true;
       }
     }
    }
  return false;
}

#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
/**************************************************************************//**
\brief Update additional information block
param[in] updateParam - update param fields
          entryIndex - entry index
\return true - for successful update
        false - otherwise
******************************************************************************/
static bool zgpUpdateAdditionalInfoBlockForCompactReport(zgpTranslationEntryUpdateOperation_t *updateParam, \
                                                         uint8_t entryIndex)
{
  uint8_t reportDescIndex = 0;
  uint8_t transOptionRecordIndex = 0;
  ZGP_ReportDescriptor_t *currentReportDescriptor = (ZGP_ReportDescriptor_t *)updateParam->reportDescriptor;
  zgpGpdAppInfoEntry_t *gpdAppInfoEntry = &zgpSinkTranslationTable.gpdAppInfoEntry[entryIndex];
  ZGP_DataPointDescriptor_t *dataPointDescriptor = NULL;

  gpdAppInfoEntry->addInfoBlock.addInfoBlockLength = 0x0;// including addInfoBlockLength field

  while(reportDescIndex < updateParam->totalNoofReports)
  {
    if (currentReportDescriptor)
    {
      dataPointDescriptor = currentReportDescriptor->dataPointDescriptor;
      while (dataPointDescriptor)
      {
        if (dataPointDescriptor->busy)
        {
          uint8_t attrCount = ZGP_DATAPOINT_DESC_NO_OF_ATTRIBUTE_RECORDS(dataPointDescriptor->dataPointOptions) + 1;
          uint8_t attrIndex = 0;
          bool clusterMatch = false;
          uint8_t pairedEps[APP_ENDPOINTS_AMOUNT] = {updateParam->appEndPoint};
          uint8_t noOfPairedEps = 1;

          if (ALL_END_POINT == updateParam->appEndPoint)
          {
            noOfPairedEps = zgpGetAllEndPoints(pairedEps);
          }
          while(noOfPairedEps)
          {
            if (NULL != ZCL_GetCluster(pairedEps[noOfPairedEps-1],
                                     dataPointDescriptor->clusterId,
                                      ZGP_DATAPOINT_DESC_CLIENT_SERVER(dataPointDescriptor->dataPointOptions)))
            {
              clusterMatch = true;
              break;
            }
            noOfPairedEps--;
          }

          if (clusterMatch)
          {
            while(attrIndex < attrCount)
            {
              if (IS_ZGP_ATTR_REPORTED(dataPointDescriptor->attrRecord[attrIndex].attrOptions))
              {
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].isValid = true;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionSelector.optionId = 0;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionSelector.optionLength = sizeof(gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData) - 1; // (Option data length - 1)

                gpdAppInfoEntry->addInfoBlock.addInfoBlockLength++; // for option selector
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.reportId = currentReportDescriptor->reportId;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.attrOffsetWithinReport = dataPointDescriptor->attrRecord[attrIndex].attrOffsetWithinReport;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.clusterId = dataPointDescriptor->clusterId;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.attrId = dataPointDescriptor->attrRecord[attrIndex].attrId;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.attrDataType = dataPointDescriptor->attrRecord[attrIndex].attrDataType;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.attrOption.clusterSide = ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT;// For server side
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.attrOption.manufacIdPresent = 0;
                gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.manufacId = 0x00;
                if (IS_ZGP_DATAPOINT_DESC_MANUFAC_ID_PRESENT(dataPointDescriptor->dataPointOptions))
                {
                  gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.attrOption.manufacIdPresent = 1;
                  gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.manufacId = dataPointDescriptor->manufacturerId;
                }
                else
                  gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionSelector.optionLength -= sizeof(gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionData.manufacId);

                gpdAppInfoEntry->addInfoBlock.addInfoBlockLength += (gpdAppInfoEntry->addInfoBlock.record[transOptionRecordIndex].optionSelector.optionLength + 1);
                transOptionRecordIndex++;
                if (transOptionRecordIndex >= ZGP_NO_OF_OPTION_RECORDS_IN_TRANS_ENTRY)
                {
                  // Application needs to handle this. May increase ZGP_NO_OF_OPTION_RECORDS_IN_TRANS_ENTRY size
                  return false;
                }
              }
              attrIndex++;
            }
          }
        }
        else
        {
          // This is not expected .. May need to raise assert/notification to the application
          return false;
        }
        dataPointDescriptor = dataPointDescriptor->nextDataPointDescriptor;
      }
    }
    else
    {
      // This is not expected .. May need to raise assert/notification to the application
      return false;
    }
    reportDescIndex++;
    currentReportDescriptor = currentReportDescriptor->nextReportDescriptor;
  }
  return true;
}
#endif

/**************************************************************************//**
\brief Validate the endpoint
param[in] newAppEndPoint - app endpoint
        entryAppEndPoint - app endpoint info
\return status
******************************************************************************/
static bool validateAppEndPoint(uint8_t newAppEndPoint, uint8_t *entryAppEndPoint)
{
  bool valid = false;

  // This function returns true if new entry is to be added
  // Otherwise false - not proceeding with creation of new entry

  // if endpoint to be added is ALL_END_POINT, then update the existing entry end point &
  // don't proceed with creation of new entry & return false
  // If endpoint to be added is different from the existing one and the existing one is not
  // equal to ALL_END_POINT, then we need to create a separate translation table entry
  // so return true
  if (ALL_END_POINT == newAppEndPoint)
    *entryAppEndPoint = newAppEndPoint;
  else if ((newAppEndPoint != *entryAppEndPoint) && (ALL_END_POINT != *entryAppEndPoint))
    valid = true;

  return valid;
}

/**************************************************************************//**
\brief Get the translation table entry
\param[in] transTableReadparameters - translation table read parameter info
           zgpZclInfo - zcl info
\return status
******************************************************************************/
static uint8_t zgpTransTableGetZgpZclMappingInfo(zgpTranslationEntryReadOperation_t *transTableReadparameters, zgpEndPointAndZclInfo_t *zgpZclInfo)
{
  uint8_t lookupIndex = transTableReadparameters->transLookupTableIndex;
  zgpGpdAppInfoEntry_t *gpdAppInfoEntry = &zgpSinkTranslationTable.gpdAppInfoEntry[0];

  for (; lookupIndex < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; lookupIndex++)
  {
    uint8_t transTableEntryIndex =  zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[lookupIndex].gpdAppInfoEntryIndex;
    bool entryMatch = false;

    if (transTableEntryIndex != ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX)
    {
      uint8_t cmdIndex = zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[lookupIndex].cmdMappingEntryIndex;

      if (transTableReadparameters->ignoreAppId)
        entryMatch = true;
      else if (transTableReadparameters->appId == gpdAppInfoEntry[transTableEntryIndex].appId)
      {
        if (transTableReadparameters->ignoreGpdId)
          entryMatch = true;
        else if (((ZGP_SRC_APPID == transTableReadparameters->appId) && (transTableReadparameters->gpdId->gpdSrcId == gpdAppInfoEntry[transTableEntryIndex].gpdId.gpdSrcId)) || \
            ((ZGP_IEEE_ADDR_APPID == transTableReadparameters->appId) && (transTableReadparameters->gpdId->gpdIeeeAddr == gpdAppInfoEntry[transTableEntryIndex].gpdId.gpdIeeeAddr) && \
            ((ALL_END_POINT == gpdAppInfoEntry[transTableEntryIndex].gpdEndPoint) || (APP_INDEPENDENT_END_POINT == transTableReadparameters->gpdEndPoint) || (ALL_END_POINT == transTableReadparameters->gpdEndPoint) ||
             (transTableReadparameters->gpdEndPoint == gpdAppInfoEntry[transTableEntryIndex].gpdEndPoint))))
        {
          //if (ZGP_ATTRIBUTE_REPORT_CMD_ID != transTableReadparameters->gpdCmdId)
          {
            if (transTableReadparameters->gpdCmdId == zgpGpdToZclCmdMappingTable[cmdIndex].gpdCmdId)
            {
              entryMatch = true;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
              if((ZGP_8_BIT_VECTOR_RELEASE == transTableReadparameters->gpdCmdId) ||
                 (ZGP_8_BIT_VECTOR_PRESS == transTableReadparameters->gpdCmdId))
              {
                if(((transTableReadparameters->contactStatus) & (zgpSinkTranslationTable.g8csOptionData[lookupIndex].contactBitmask))
                     != zgpSinkTranslationTable.g8csOptionData[lookupIndex].contactStatus)
                  entryMatch = false;
              }
#endif
            }
            if(!entryMatch)
              continue;
          }
          //entryMatch = true;
        }
      }
      if (entryMatch)
      {
        zgpZclInfo->gpdCmdId = zgpGpdToZclCmdMappingTable[cmdIndex].gpdCmdId;
        zgpZclInfo->appEndPoint = gpdAppInfoEntry[transTableEntryIndex].appEndPoint;
        zgpZclInfo->cmdMapInfo.zclCmdId = zgpGpdToZclCmdMappingTable[cmdIndex].zclCmdId;
        zgpZclInfo->cmdMapInfo.zclClusterId = zgpGpdToZclCmdMappingTable[cmdIndex].zclClusterId;
        zgpZclInfo->cmdMapInfo.payloadLength = zgpGpdToZclCmdMappingTable[cmdIndex].payloadLength;
        if (zgpGpdToZclCmdMappingTable[cmdIndex].payloadLength && (zgpGpdToZclCmdMappingTable[cmdIndex].payloadLength < UNSPECIFIED_LENGTH))
          memcpy(zgpZclInfo->cmdMapInfo.payload, zgpGpdToZclCmdMappingTable[cmdIndex].payload, sizeof(zgpZclInfo->cmdMapInfo.payload));
        memcpy(&zgpZclInfo->gpdAppInfoEntry, &gpdAppInfoEntry[transTableEntryIndex], sizeof(zgpZclInfo->gpdAppInfoEntry));
        return lookupIndex;
      }
    }
  }
  return ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
}
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
/**************************************************************************//**
\brief retrieve the last contact status for the last press command received
\param[in] transTableReadparameters - translation table read parameter info
\return status
******************************************************************************/
static bool readUpdateLastPressContactStatus(zgpTranslationEntryReadOperation_t *transTableReadparam)
{
  uint8_t retStatus = false;
  uint8_t gpdAppInfoIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
  
    // find the gpdInfoIndex
  for(uint8_t i = 0; i < ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION; i++)
  {
    if (((ZGP_SRC_APPID == transTableReadparam->appId) && (transTableReadparam->gpdId->gpdSrcId == zgpSinkTranslationTable.gpdAppInfoEntry[i].gpdId.gpdSrcId)) || \
         ((ZGP_IEEE_ADDR_APPID == transTableReadparam->appId) && (transTableReadparam->gpdId->gpdIeeeAddr == zgpSinkTranslationTable.gpdAppInfoEntry[i].gpdId.gpdIeeeAddr) && \
          ((ALL_END_POINT == zgpSinkTranslationTable.gpdAppInfoEntry[i].gpdEndPoint) || (transTableReadparam->gpdEndPoint == zgpSinkTranslationTable.gpdAppInfoEntry[i].gpdEndPoint) || \
          (APP_INDEPENDENT_END_POINT == transTableReadparam->gpdEndPoint) || (ALL_END_POINT == transTableReadparam->gpdEndPoint))))
    {
      gpdAppInfoIndex = i;
      break;
    }
  }

  if((transTableReadparam->gpdCmdId == ZGP_8_BIT_VECTOR_PRESS) &&
     (ZGP_NO_CONTACTS_SAVED != transTableReadparam->contactStatus))
  {
      // Remember the currContactStatus for the press command received
      uint8_t trackOrderIndex = ZGP_TRACK_ORDER_ARRAY_INVALID_INDEX;
      // find the existing entry in trackOrderOfPressG8cs and update
      for(uint8_t i = 0; i < MAX_NO_OF_G8CS_TO_TRACK_ORDER_OF_PRESS; i++)
      {
        if(trackOrderOfPressG8cs[i].gpdAppInfoEntryIndexinTT == gpdAppInfoIndex)
        {
          trackOrderOfPressG8cs[i].lastPressContactStatus = transTableReadparam->contactStatus;          
          trackOrderIndex = i;
          retStatus = true;
          break;
        }
        else if(!trackOrderOfPressG8cs[i].busy)
          trackOrderIndex = i;
      }
      // update in available free entry in trackOrderOfPressG8cs
      if(trackOrderIndex != ZGP_TRACK_ORDER_ARRAY_INVALID_INDEX)
      {
        if(!trackOrderOfPressG8cs[trackOrderIndex].busy)
        {
          trackOrderOfPressG8cs[trackOrderIndex].busy = true;
          trackOrderOfPressG8cs[trackOrderIndex].gpdAppInfoEntryIndexinTT = gpdAppInfoIndex;
          trackOrderOfPressG8cs[trackOrderIndex].lastPressContactStatus = transTableReadparam->contactStatus;
          retStatus = true;
        }
      }
  }
  else if(transTableReadparam->gpdCmdId == ZGP_8_BIT_VECTOR_RELEASE)
  {
     // retreive the contact status when latest press command was received from this gpd
     for(uint8_t i = 0; i < MAX_NO_OF_G8CS_TO_TRACK_ORDER_OF_PRESS; i++)
     {
       if(trackOrderOfPressG8cs[i].gpdAppInfoEntryIndexinTT == gpdAppInfoIndex)
       {
         if(trackOrderOfPressG8cs[i].lastPressContactStatus != ZGP_NO_CONTACTS_SAVED)
         {
           transTableReadparam->contactStatus = trackOrderOfPressG8cs[i].lastPressContactStatus;
           if((trackOrderOfPressG8cs[i].noOfContactsPaired != 0) &&
                (trackOrderOfPressG8cs[i].noOfContactsPaired == zgpSinkTranslationTable.gpdAppInfoEntry[gpdAppInfoIndex].genericSwitchConfig.noOfContacts))
           {
             //trackOrderOfPressG8cs[i].busy = false;
             memset(&trackOrderOfPressG8cs[i], 0, sizeof(zgpTrackOrderOfPressG8CS_t));
           }
           retStatus = true;
         }
         break;
       }
     }
  }
  return retStatus;
}
#endif // ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
/**************************************************************************//**
\brief Remove look up table entries for the given trans table index and cmd entry index
\param[in] lookupTableIndex -index of lookup table
           transTableIndex -index of translation table
           cmdIndex - index of command
******************************************************************************/
static void zgpTransRemoveLookUpTableEntries(uint8_t lookupTableIndex, uint8_t transTableIndex, uint8_t cmdIndex)
{
  bool transTablePresent = false;

  if (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != lookupTableIndex)
  {
    if (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[lookupTableIndex].gpdAppInfoEntryIndex)
    {
      transTableIndex = zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[lookupTableIndex].gpdAppInfoEntryIndex;
      zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[lookupTableIndex].gpdAppInfoEntryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
      zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[lookupTableIndex].cmdMappingEntryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
      zgpSinkTranslationTable.g8csOptionData[lookupTableIndex].contactStatus = ZGP_NO_CONTACTS_SAVED;
      zgpSinkTranslationTable.g8csOptionData[lookupTableIndex].contactBitmask = ZGP_NO_CONTACTS_SAVED;
#endif
      zgpTransTableLogicalEntriesCount--;
    }
    else
      return;
    // remove translation table entry no other lookup entry has the same translation table index
  }

  for (uint8_t i = 0; i < ZGP_APP_INFO_CMD_MAPPING_LOOKUP_TABLE_SIZE; i++)
  {
    if (transTableIndex == zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex)
    {
      if (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != lookupTableIndex)
      {
        transTablePresent = true;
        break;
      }
      if (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX == cmdIndex)
      {
        zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
        zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].cmdMappingEntryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
      zgpSinkTranslationTable.g8csOptionData[i].contactStatus = ZGP_NO_CONTACTS_SAVED;
      zgpSinkTranslationTable.g8csOptionData[i].contactBitmask = ZGP_NO_CONTACTS_SAVED;
#endif        
        zgpTransTableLogicalEntriesCount--;
        continue;
      }
      else if (zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].cmdMappingEntryIndex == cmdIndex)
      {
        zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].gpdAppInfoEntryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
        zgpSinkTranslationTable.appInfoAndCmdMappingLookupTable[i].cmdMappingEntryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
      zgpSinkTranslationTable.g8csOptionData[i].contactStatus = ZGP_NO_CONTACTS_SAVED;
      zgpSinkTranslationTable.g8csOptionData[i].contactBitmask = ZGP_NO_CONTACTS_SAVED;
#endif        
        zgpTransTableLogicalEntriesCount--;
        //break;
      }
    }
  }

  if (!transTablePresent && (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != lookupTableIndex))
  {
    zgpSinkTranslationTable.gpdAppInfoEntry[transTableIndex].isActiveEntry = false;
  }
}

/**************************************************************************//**
  \brief Remove the translation table entry

  \param[in] Remove operation structure
******************************************************************************/
static void zgpTransTableRemoveEntry(zgpTransTableEntryRemoveOperation_t *transTableEntryRemoveField)
{
  uint8_t i;
  zgpGpdAppInfoEntry_t *gpdAppInfoEntry = &zgpSinkTranslationTable.gpdAppInfoEntry[0];
  uint8_t entryIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
  uint8_t cmdIndex = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;

  for (i = 0; i < ZGP_NO_OF_GPD_ENTRIES_IN_SINK_TRANSLATION; i++)
  {
    if (gpdAppInfoEntry[i].isActiveEntry)
    {
      if (transTableEntryRemoveField->appId == gpdAppInfoEntry[i].appId)
      {
        if ((((ZGP_SRC_APPID == transTableEntryRemoveField->appId) && (transTableEntryRemoveField->gpdId->gpdSrcId == gpdAppInfoEntry[i].gpdId.gpdSrcId)) || \
            ((ZGP_IEEE_ADDR_APPID == transTableEntryRemoveField->appId) && (transTableEntryRemoveField->gpdId->gpdIeeeAddr == gpdAppInfoEntry[i].gpdId.gpdIeeeAddr) && \
             ((ALL_END_POINT == transTableEntryRemoveField->gpdEndPoint) || (transTableEntryRemoveField->gpdEndPoint == gpdAppInfoEntry[i].gpdEndPoint)))) && \
             ((IGNORE_PROFILE_ID == transTableEntryRemoveField->profileId) || (transTableEntryRemoveField->profileId == gpdAppInfoEntry[i].profileId)) && \
             ((IGNORE_APP_ENDPOINT == transTableEntryRemoveField->appEndPoint) || (transTableEntryRemoveField->appEndPoint == gpdAppInfoEntry[i].appEndPoint)))
        {
          entryIndex = i;
        }
      }
    }
  }
  if((transTableEntryRemoveField->gpdCmdId != IGNORE_THIS_FIELD) && (transTableEntryRemoveField->zclClusterId != IGNORE_THIS_FIELD) && (transTableEntryRemoveField->zclCmdId != IGNORE_THIS_FIELD))
  {
    cmdIndex = gpdZclCmdMappingEntryExists(transTableEntryRemoveField->gpdCmdId, transTableEntryRemoveField->zclClusterId, transTableEntryRemoveField->zclCmdId, entryIndex, NULL, NULL);
  }

  // Need to update lookup table
  zgpTransRemoveLookUpTableEntries(ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX, entryIndex , cmdIndex);
  // if removing for a decommissioning command or is the command removed is the last one for this gpd
  if(((transTableEntryRemoveField->gpdCmdId == IGNORE_THIS_FIELD) && (transTableEntryRemoveField->zclClusterId == IGNORE_THIS_FIELD) &&
     (transTableEntryRemoveField->zclCmdId == IGNORE_THIS_FIELD) && (transTableEntryRemoveField->profileId == IGNORE_THIS_FIELD)) ||
      !isTTEntryPresentForGPD(entryIndex))
  {
    gpdAppInfoEntry[entryIndex].isActiveEntry = false;
  }
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
  if(entryIndex != ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX)
    memset(&gpdAppInfoEntry[entryIndex].addInfoBlock, 0x00, sizeof(gpdAppInfoEntry[entryIndex].addInfoBlock));
#endif
  PDS_Store(ZGP_TRANS_TABLE_MEM_ID);
}

/**************************************************************************//**
  \brief translation command indication - event handler

  \param[in] eventId - event id
             data - event data

  \return None
******************************************************************************/
static void zgpTransTableCmdIndHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
  ZGP_IndicationInfo_t *indicationInfo = (ZGP_IndicationInfo_t *)data;
  ZGP_ClusterCmdInd_t *transTableCmdInd;
#ifndef ZGP_LW_TRANSLATION_TABLE
  if (GP_TRANSLATION_TABLE_REQUEST_COMMAND_IND == indicationInfo->indicationType)
  {
    transTableCmdInd = (ZGP_ClusterCmdInd_t *)&indicationInfo->indicationData.clusterCmdInd;
    transTableCmdInd->retStatus = zgpTranslationTableRequestHandling(transTableCmdInd->srcAddress, transTableCmdInd->payloadlength, transTableCmdInd->payload);
  }
  else if(GP_TRANSLATION_TABLE_UPDATE_COMMAND_IND == indicationInfo->indicationType)
  {
    transTableCmdInd = (ZGP_ClusterCmdInd_t *)&indicationInfo->indicationData.clusterCmdInd;
    transTableCmdInd->retStatus = zgpTranslationTableUpdateHandling(transTableCmdInd->srcAddress, transTableCmdInd->payloadlength, transTableCmdInd->payload);
  }
#endif
  if (GPD_COMMAND_RECEIVED == indicationInfo->indicationType)
  {
    ZGP_GpdCommand_t *gpdCmdInd = (ZGP_GpdCommand_t *)&indicationInfo->indicationData.gpdCommand;
    zgpTranslationEntryReadOperation_t transTableReadParam = {.ignoreAppId = false, .ignoreGpdId = false, .transLookupTableIndex = 0, \
                                                              .appId = gpdCmdInd->appId, .gpdId = &gpdCmdInd->gpdId, .gpdEndPoint = gpdCmdInd->endPoint, .gpdCmdId = gpdCmdInd->cmdId,
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT                                                                
                                                              .contactStatus = gpdCmdInd->cmdPayload[0]
#endif
                                                              };
    bool dir = ZCL_FRAME_CONTROL_DIRECTION_CLIENT_TO_SERVER;
    memset(&zgpZclMappingInfo, 0x00, sizeof(zgpZclMappingInfo));
    // Forward the command to paired/all end points
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
    if(transTableReadParam.gpdCmdId == ZGP_8_BIT_VECTOR_PRESS || transTableReadParam.gpdCmdId == ZGP_8_BIT_VECTOR_RELEASE)
    {
      if(!readUpdateLastPressContactStatus(&transTableReadParam))
        if(transTableReadParam.gpdCmdId == ZGP_8_BIT_VECTOR_RELEASE)
          return; // Release - contact status of last press cannot be retreived, press - can still execute
    }
#endif
    while(ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != (transTableReadParam.transLookupTableIndex = zgpTransTableGetZgpZclMappingInfo(&transTableReadParam, &zgpZclMappingInfo)))
    {
      // By default we have only one paired endpoint
      // will be overridden when ALL_END_POINT is set
      uint8_t noOfPairedEps = 1;
      uint8_t pairedEps[APP_ENDPOINTS_AMOUNT];
      uint16_t manucfacCode = 0;
      uint8_t index = 0;
      bool  multipleCommandsToBeFwded = false;
      ZCL_Addressing_t addressing;
      memset(&addressing, 0x00, sizeof(ZCL_Addressing_t));

      if ((ZGP_ATTRIBUTE_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
          (ZGP_MANU_SPEC_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
          (ZGP_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
          (ZGP_MANU_SPEC_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId))
      {
        uint8_t minLength = ZGP_FRAME_REPORT_ATTR_BASIC_FRAME_LENGTH;

        if ((ZGP_MANU_SPEC_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
            (ZGP_MANU_SPEC_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId))
        {
          manucfacCode = (uint16_t)gpdCmdInd->cmdPayload[index] | ((uint16_t)gpdCmdInd->cmdPayload[index+1] << 8);
          minLength += sizeof(manucfacCode);
          index += sizeof(manucfacCode);
        }
        if (gpdCmdInd->cmdPayloadLength < minLength)
        {
          return;
        }

        zgpZclMappingInfo.cmdMapInfo.zclCmdId = ZCL_REPORT_ATTRIBUTES_COMMAND_ID;
        zgpZclMappingInfo.cmdMapInfo.zclClusterId = (uint16_t)gpdCmdInd->cmdPayload[index] | ((uint16_t)gpdCmdInd->cmdPayload[index+1] << 8);
        index += sizeof(zgpZclMappingInfo.cmdMapInfo.zclClusterId);

        dir = ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT;
        if ((ZGP_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
            (ZGP_MANU_SPEC_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId))
        {
          uint8_t attrLength = ZCL_GetAttributeLength(gpdCmdInd->cmdPayload[index + 2], &gpdCmdInd->cmdPayload[index + 3]);
          zgpZclMappingInfo.cmdMapInfo.payloadLength = sizeof(uint16_t) /* attr id*/+ sizeof(uint8_t)/* attr data type*/ + \
                                                       attrLength;
          multipleCommandsToBeFwded = true;
        }
        else
          zgpZclMappingInfo.cmdMapInfo.payloadLength = gpdCmdInd->cmdPayloadLength - index;
      }
      else if(ZGP_COMPACT_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId)
      {
        zgpZclMappingInfo.cmdMapInfo.payloadLength = gpdCmdInd->cmdPayloadLength;
      }
      else if (ZGP_ZCL_TUNNELING_CMD_ID == gpdCmdInd->cmdId)
      {
        // Nothing to do
      }
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT      
      else if(ZGP_8_BIT_VECTOR_PRESS == gpdCmdInd->cmdId || ZGP_8_BIT_VECTOR_RELEASE == gpdCmdInd->cmdId)
      {
        if(zgpSinkTranslationTable.g8csOptionData[transTableReadParam.transLookupTableIndex].contactStatus !=
           (zgpSinkTranslationTable.g8csOptionData[transTableReadParam.transLookupTableIndex].contactBitmask & transTableReadParam.contactStatus))
        {
          transTableReadParam.transLookupTableIndex++;
          continue;
        }
      }
#endif      
      else if (zgpZclMappingInfo.cmdMapInfo.payloadLength >= UNSPECIFIED_LENGTH)
      {
        // If payloadlength is 0xFF, then we need to take the payload from the received gpdCmd
        memcpy(zgpZclMappingInfo.cmdMapInfo.payload, gpdCmdInd->cmdPayload,sizeof(zgpZclMappingInfo.cmdMapInfo.payload));
        zgpZclMappingInfo.cmdMapInfo.payloadLength = sizeof(zgpZclMappingInfo.cmdMapInfo.payload);
      }
      else if ((gpdCmdInd->cmdId >= ZGP_LC_CMD_ID_MOVE_UP) && (gpdCmdInd->cmdId <= ZGP_LC_CMD_ID_STEP_DOWN_WITH_ONOFF))
      {
        if (gpdCmdInd->cmdPayloadLength)
        {
          uint8_t length = (zgpZclMappingInfo.cmdMapInfo.payloadLength - 1) < gpdCmdInd->cmdPayloadLength ?
            (zgpZclMappingInfo.cmdMapInfo.payloadLength - 1):gpdCmdInd->cmdPayloadLength;
          memcpy(&zgpZclMappingInfo.cmdMapInfo.payload[1], &gpdCmdInd->cmdPayload[0], length);
        }
        //zgpZclMappingInfo.cmdMapInfo.payloadLength = sizeof(zgpZclMappingInfo.cmdMapInfo.payload);
      }
      pairedEps[0] = zgpZclMappingInfo.appEndPoint;
      if(GPD_PROCESSING_IN_APPLICATION == zgpZclMappingInfo.appEndPoint)
      {
#ifdef ZGP_GPD_PROCESSING_IN_APPLICATION_SUPPORTED
        forwardGpdCmdToApplication(&zgpZclMappingInfo, &addressing, gpdCmdInd, index);
#else
        transTableCmdInd->retStatus = ZCL_FAILURE_STATUS;
#endif
        return; 
      }
      if (ALL_END_POINT == zgpZclMappingInfo.appEndPoint)
      {
        noOfPairedEps = zgpGetAllEndPoints(pairedEps);
      }

      {
        addressing.addrMode             = APS_SHORT_ADDRESS;
        addressing.addr.shortAddress    = gpdCmdInd->gpdId.gpdSrcId;
        addressing.profileId            = APP_PROFILE_ID;//GREEN_POWER_PROFILE_ID;
        addressing.endpointId           = ALL_END_POINT;
        addressing.clusterId            = zgpZclMappingInfo.cmdMapInfo.zclClusterId;
        addressing.clusterSide          = dir;
        addressing.sequenceNumber       = 0;
        addressing.nonUnicast           = true;
        addressing.manufacturerSpecCode = manucfacCode;
      }

      do
      {
        while (noOfPairedEps)
        {
          zgpZclMappingInfo.appEndPoint = pairedEps[noOfPairedEps - 1];
          // forward to the endpoint and scan the next end point
          forwardGpdCmdToAppEndPoint(&zgpZclMappingInfo, &addressing, gpdCmdInd, index);
          index += zgpZclMappingInfo.cmdMapInfo.payloadLength;
          noOfPairedEps--;
        }
        if ((ZGP_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
            (ZGP_MANU_SPEC_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId))
        {
          if (gpdCmdInd->cmdPayloadLength > index)
          {
            uint8_t attrLength = 0;

            zgpZclMappingInfo.cmdMapInfo.zclClusterId = (uint16_t)gpdCmdInd->cmdPayload[index] | ((uint16_t)gpdCmdInd->cmdPayload[index+1] << 8);
            index += sizeof(zgpZclMappingInfo.cmdMapInfo.zclClusterId);
            attrLength = ZCL_GetAttributeLength(gpdCmdInd->cmdPayload[index + 2], &gpdCmdInd->cmdPayload[index + 3]);
            addressing.clusterId = zgpZclMappingInfo.cmdMapInfo.zclClusterId;

            zgpZclMappingInfo.cmdMapInfo.payloadLength = sizeof(uint16_t) /* attr id*/+ sizeof(uint8_t)/* attr data type*/ + \
                                                       attrLength;

            noOfPairedEps = 1;
            pairedEps[0] = zgpZclMappingInfo.appEndPoint;
            if (ALL_END_POINT == zgpZclMappingInfo.appEndPoint)
            {
              noOfPairedEps = zgpGetAllEndPoints(pairedEps);
            }
          }
          else
            multipleCommandsToBeFwded = false;
        }
      } while (multipleCommandsToBeFwded);
      transTableReadParam.transLookupTableIndex++;
    }
  }
}

/**************************************************************************//**
  \brief translation table event indication

  \param[in] eventId - event id
             data - event data

  \return None
******************************************************************************/
static void zgpTransTableIndHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
  ZGP_TransTableIndicationInfo_t *transTableIndicationInfo = (ZGP_TransTableIndicationInfo_t *)data;
  uint8_t endPointForPreCommissioned = APP_SRC_ENDPOINT_ID;

  if (ADD_TRANS_TABLE_ENTRY == transTableIndicationInfo->transTableIndType)
  {
    ZGP_SinkTableEntry_t *sinkTableEntry = transTableIndicationInfo->indicationData.addTransTableEntry.sinkEntry;
    uint8_t noOfPairedEndPoints = transTableIndicationInfo->indicationData.addTransTableEntry.noOfEndPoints;
    ZGP_GpdAppInfo_t *appInfo = transTableIndicationInfo->indicationData.addTransTableEntry.appInfo;
    uint8_t endPointForPreCommissioned = APP_SRC_ENDPOINT_ID;

    if ((PAIRING_CONFIG_TYPE == transTableIndicationInfo->indicationData.addTransTableEntry.pairingType) && \
        ((PRECOMMISSIONED_GROUPCAST == noOfPairedEndPoints) || (0xFE == noOfPairedEndPoints)))
    {
      noOfPairedEndPoints = 1;
      transTableIndicationInfo->indicationData.addTransTableEntry.endPointList = &endPointForPreCommissioned;
    }

    while(noOfPairedEndPoints)
    {
      // adding entry to translation table
      zgpTranslationEntryUpdateOperation_t entryUpdateParam = {.lookupTableIndex = ZGP_ENTRY_INVALID_INDEX, .appId = (ZGP_ApplicationId_t)sinkTableEntry->options.appId,
                                                               .gpdId = &sinkTableEntry->tableGenericInfo.gpdId, .gpdEndPoint = sinkTableEntry->tableGenericInfo.endPoint, .deviceId = sinkTableEntry->deviceId,
                                                               .appEndPoint = transTableIndicationInfo->indicationData.addTransTableEntry.endPointList[noOfPairedEndPoints - 1], .noOfCmds = appInfo->noOfGpdCmds,
                                                               .cmdList = appInfo->gpdCommandList, .isReplaceReq = false,
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
                                                               .totalNoofReports = appInfo->totalNoofReports,
                                                               .reportDescriptor = (void *)appInfo->reportDescriptor,
#else
                                                               .totalNoofReports = 0,
                                                               .reportDescriptor = NULL,
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
                                                               .switchInfo.switchInfoLength = appInfo->switchInfo.switchInfoLength,
                                                               .switchInfo.genericSwitchConfig = appInfo->switchInfo.genericSwitchConfig,
                                                               .switchInfo.currContactStatus = appInfo->switchInfo.currContactStatus,
                                                               .switchInfo.contactBitMask = appInfo->switchInfo.currContactStatus
#else
                                                               .switchInfo.switchInfoLength = 0,
                                                               .switchInfo.genericSwitchConfig = 0,
                                                               .switchInfo.currContactStatus = 0,
                                                               .switchInfo.contactBitMask = 0
#endif
                                                               };
      // TBD need to handle when no free entry available in translation table
      zgpTransTableAddEntry(&entryUpdateParam, NULL, NULL);
      noOfPairedEndPoints--;
    }
  }
  else if (APP_FUNCTIONALITY_CHECK == transTableIndicationInfo->transTableIndType)
  {
    if ((0x00 == transTableIndicationInfo->indicationData.appFuncCheckInfo.noOfEndPoints) || (0xFE == transTableIndicationInfo->indicationData.appFuncCheckInfo.noOfEndPoints))
    {
      transTableIndicationInfo->indicationData.appFuncCheckInfo.endPointList = &endPointForPreCommissioned;
      transTableIndicationInfo->indicationData.appFuncCheckInfo.noOfEndPoints = 1;
    }
    transTableIndicationInfo->indicationData.appFuncCheckInfo.isMatching = zgpTransTableIsFuncMatching(transTableIndicationInfo->indicationData.appFuncCheckInfo.deviceId, \
                                         transTableIndicationInfo->indicationData.appFuncCheckInfo.appInfo, transTableIndicationInfo->indicationData.appFuncCheckInfo.noOfEndPoints, \
                                          transTableIndicationInfo->indicationData.appFuncCheckInfo.endPointList);
  }
  else if (REMOVE_TRANS_TABLE_ENTRY == transTableIndicationInfo->transTableIndType)
  {
    zgpTransTableEntryRemoveOperation_t transTableRemoveField = { .appId = transTableIndicationInfo->indicationData.removeTransTableEntry.appId,
                                                                  .gpdId = transTableIndicationInfo->indicationData.removeTransTableEntry.gpdId,
                                                                  .gpdEndPoint = transTableIndicationInfo->indicationData.removeTransTableEntry.endPoint,
                                                                  .gpdCmdId = IGNORE_THIS_FIELD,
                                                                  .zclClusterId = IGNORE_THIS_FIELD,
                                                                  .zclCmdId = IGNORE_THIS_FIELD,
                                                                  .profileId = IGNORE_PROFILE_ID,
                                                                  .appEndPoint = IGNORE_APP_ENDPOINT
                                                                };
    // deleting translation entry
    zgpTransTableRemoveEntry(&transTableRemoveField);
  }
}

#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
/**************************************************************************//**
  \brief Forward rxd compact report to application end point

  \param[in] endPointZclInfo - application end point info
             gpdCmdInd - rxd gpd command

  \return None
******************************************************************************/
static void forwardCompactReportCmdToAppEndPoint(ZCL_Addressing_t *addressing, \
                        zgpEndPointAndZclInfo_t *endPointZclInfo, ZGP_GpdCommand_t *gpdCmdInd)
{
  uint8_t payloadIndex = 0;
  uint8_t attrOffset = 0;
  uint8_t reportId = gpdCmdInd->cmdPayload[payloadIndex++];

  // Need to interpret the compact report and fwd to app. end point
  if (endPointZclInfo->gpdAppInfoEntry.addInfoBlock.addInfoBlockLength)
  {
    while (payloadIndex < gpdCmdInd->cmdPayloadLength)
    {
      bool entryFound = false;
      for (uint8_t i = 0; i < ZGP_NO_OF_OPTION_RECORDS_IN_TRANS_ENTRY; i++)
      {
        if ((endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].isValid) && \
            (reportId == endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.reportId) && \
            (attrOffset == endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrOffsetWithinReport) )
        {
          uint16_t attrLength = ZCL_GetAttributeLength(endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrDataType, \
                                   &endPointZclInfo->cmdMapInfo.payload[payloadIndex]);
          uint16_t attrId = endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrId;

          uint8_t reportIndex = 0;
          ZCL_Cluster_t *cluster = NULL;

          entryFound = true;
          memcpy(&zgpZclPayloadToEp.compactReportZclPayload[reportIndex], &attrId, \
                          sizeof(endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrId));
          reportIndex += sizeof(endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrId);
          memcpy(&zgpZclPayloadToEp.compactReportZclPayload[reportIndex], &endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrDataType, \
                          sizeof(endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrDataType));
          reportIndex += sizeof(endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrDataType);
          memcpy(&zgpZclPayloadToEp.compactReportZclPayload[reportIndex], &gpdCmdInd->cmdPayload[payloadIndex], attrLength);
          payloadIndex += attrLength;
          reportIndex += attrLength;
          attrOffset += attrLength;
          if (payloadIndex > gpdCmdInd->cmdPayloadLength)
          {
            // partial command payload so drop the remaining payload
            return;
          }
          // Forward to application end point cluster report callback
          cluster = ZCL_GetCluster(endPointZclInfo->appEndPoint, endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.clusterId, \
                                   endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrOption.clusterSide);
          if (!cluster || !cluster->ZCL_ReportInd)
            return;

          addressing->clusterId =  endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.clusterId;
          addressing->clusterSide = endPointZclInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData.attrOption.clusterSide;
          cluster->ZCL_ReportInd(addressing, reportIndex, &zgpZclPayloadToEp.compactReportZclPayload[0]);
        }
      }
      if (!entryFound)
      {
        // For the corresponding attrOffset payload no trans entry is found out
        // so we can't process the sub-sequent payload
        attrOffset++;
        payloadIndex++;
      }
    }
  }
}
#endif

/**************************************************************************//**
  \brief Forward rxd gpd cmd to application end point

  \param[in] endPointZclInfo - application end point info
             direction - direction of the cmd(server to client/client to server)
             gpdCmdInd - rxd gpd command
             manucfacCode - manufacturer specific code

  \return None
******************************************************************************/
static void forwardGpdCmdToAppEndPoint(zgpEndPointAndZclInfo_t *endPointZclInfo, ZCL_Addressing_t *addressing,  ZGP_GpdCommand_t *gpdCmdInd, \
                                       uint8_t payloadIndex)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(endPointZclInfo->appEndPoint, endPointZclInfo->cmdMapInfo.zclClusterId, addressing->clusterSide);
  ZclCommand_t *command = zclGetCommand(endPointZclInfo->appEndPoint, endPointZclInfo->cmdMapInfo.zclClusterId, addressing->clusterSide, endPointZclInfo->cmdMapInfo.zclCmdId);

  if (ZGP_COMPACT_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId)
  {
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
    forwardCompactReportCmdToAppEndPoint(addressing, endPointZclInfo, gpdCmdInd);
#endif
  }
  else if ((ZGP_ATTRIBUTE_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
           (ZGP_MANU_SPEC_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
           (ZGP_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId) || \
           (ZGP_MANU_SPEC_MULTI_CLUSTER_ATTR_REPORT_CMD_ID == gpdCmdInd->cmdId))
  {
    if (!cluster || !cluster->ZCL_ReportInd)
      return;

    cluster->ZCL_ReportInd(addressing, gpdCmdInd->cmdPayloadLength, &gpdCmdInd->cmdPayload[payloadIndex]);
  }
  else if (ZGP_ZCL_TUNNELING_CMD_ID == gpdCmdInd->cmdId)
  {
    uint8_t gpdCmdIndex = 0;
    uint8_t apsPayloadIndex = 0;

    memset(&zgpZclPayloadToEp.zgpApsDataInd, 0x00, sizeof(APS_DataInd_t));
    memset(&zgpZclPayloadToEp.zgpApsPayload[0], 0x00, sizeof(zgpZclPayloadToEp.zgpApsPayload));

    zgpZclPayloadToEp.zgpApsPayload[apsPayloadIndex++] = gpdCmdInd->cmdPayload[gpdCmdIndex++] | ((uint8_t)1 << ZCL_OPTION_DISABLE_DEFAULT_RSP_BIT_POS);

    if (gpdCmdInd->cmdPayload[0] & ((uint8_t)1 << ZCL_OPTION_MANUFAC_CODE_BIT_POS))
    {
      memcpy(&zgpZclPayloadToEp.zgpApsPayload[apsPayloadIndex], &gpdCmdInd->cmdPayload[gpdCmdIndex], sizeof(uint16_t));
      gpdCmdIndex += sizeof(uint16_t);
      apsPayloadIndex += sizeof(uint16_t);
    }
    // transaction number
    zgpZclPayloadToEp.zgpApsPayload[apsPayloadIndex++] = 0;

    zgpZclPayloadToEp.zgpApsDataInd.clusterId = ((uint16_t)gpdCmdInd->cmdPayload[gpdCmdIndex] | (gpdCmdInd->cmdPayload[gpdCmdIndex + 1] << 8));
    gpdCmdIndex += sizeof(uint16_t);

    // zcl command id
    zgpZclPayloadToEp.zgpApsPayload[apsPayloadIndex++] = gpdCmdInd->cmdPayload[gpdCmdIndex++];

    if (gpdCmdInd->cmdPayload[gpdCmdIndex])
    {
      memcpy(&zgpZclPayloadToEp.zgpApsPayload[apsPayloadIndex], &gpdCmdInd->cmdPayload[gpdCmdIndex + 1], gpdCmdInd->cmdPayload[gpdCmdIndex]);
      apsPayloadIndex += gpdCmdInd->cmdPayload[gpdCmdIndex];
    }
    zgpZclPayloadToEp.zgpApsDataInd.asdu = &zgpZclPayloadToEp.zgpApsPayload[0];

    zgpZclPayloadToEp.zgpApsDataInd.asduLength = apsPayloadIndex;

    zgpZclPayloadToEp.zgpApsDataInd.dstAddress = addressing->indDstAddr;
    zgpZclPayloadToEp.zgpApsDataInd.dstAddrMode = addressing->indDstAddrMode;
    zgpZclPayloadToEp.zgpApsDataInd.dstEndpoint = endPointZclInfo->appEndPoint;
    //zgpApsDataInd.linkQuality =
    zgpZclPayloadToEp.zgpApsDataInd.nwkSecurityStatus = false;
    //zgpApsDataInd.prevHopAddr =
    zgpZclPayloadToEp.zgpApsDataInd.profileId = APP_PROFILE_ID;
    //zgpApsDataInd.rssi =
    //zgpApsDataInd.rxTime =
    zgpZclPayloadToEp.zgpApsDataInd.securityStatus = APS_UNSECURED_STATUS;
    zgpZclPayloadToEp.zgpApsDataInd.status = APS_SUCCESS_STATUS;
    zgpZclPayloadToEp.zgpApsDataInd.srcAddress.shortAddress = (uint16_t)gpdCmdInd->gpdId.gpdSrcId;
    zgpZclPayloadToEp.zgpApsDataInd.srcAddrMode = APS_SHORT_ADDRESS;
    zgpZclPayloadToEp.zgpApsDataInd.srcEndpoint = GREEN_POWER_ENDPOINT;
    zclDataInd(&zgpZclPayloadToEp.zgpApsDataInd);
  }
  else
  {
    if (!command || !command->callback)
      return;

    command->callback(addressing, endPointZclInfo->cmdMapInfo.payloadLength, endPointZclInfo->cmdMapInfo.payload);
  }
}
#ifdef ZGP_GPD_PROCESSING_IN_APPLICATION_SUPPORTED
/**************************************************************************//**
  \brief Forward rxd gpd cmd for application processing/no translation

  \param[in] endPointZclInfo - application end point info
             direction - direction of the cmd(server to client/client to server)
             gpdCmdInd - rxd gpd command
             manucfacCode - manufacturer specific code

  \return None
******************************************************************************/
static void forwardGpdCmdToApplication(zgpEndPointAndZclInfo_t *endPointZclInfo, ZCL_Addressing_t *addressing,  ZGP_GpdCommand_t *gpdCmdInd, \
                                       uint8_t payloadIndex)
{
  // to do Endpoint = 0xfc handling
  // GPD command processing in application
}
#endif
#ifndef ZGP_LW_TRANSLATION_TABLE
/**************************************************************************//**
  \brief GP translation table update indication

  \param[in] addressing - addressing info
             payloadlength & payload - payload info

  \return success or failure.
******************************************************************************/
static ZCL_Status_t zgpTranslationTableUpdateHandling(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  zgpTransTableUpdateField_t transUpdateCmd;
  uint8_t payloadIndex = 0;
  uint16_t i = 0;
  bool additionalInfoBlockPresent = false;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
  zgpSwitchInfo_t switchInfo;
  memset(&switchInfo, 0x00, sizeof(zgpSwitchInfo_t));
#endif  

  memset(&transUpdateCmd, 0x00, sizeof(transUpdateCmd));

  memcpy(&transUpdateCmd.options, payload, sizeof(transUpdateCmd.options));
  payloadIndex += sizeof(transUpdateCmd.options);
  additionalInfoBlockPresent = transUpdateCmd.options.additionalInfoBlockPresent;

  {
    uint8_t gpdIdLength = ZGPH_ParseGpdIdFromPayload((ZGP_ApplicationId_t)transUpdateCmd.options.appId, &transUpdateCmd.gpdId, \
                                                                &transUpdateCmd.endPoint, &payload[payloadIndex]);
    if (INVALID_CMD_LENGTH == gpdIdLength)
      return ZCL_INVALID_FIELD_STATUS;
    payloadIndex += gpdIdLength;
  }

  if (payloadLength < payloadIndex)
    return ZCL_MALFORMED_COMMAND_STATUS;

  // To check for malformed command
  {
    uint8_t tempPayloadIndex = payloadIndex;

    while(i < transUpdateCmd.options.noOfTranslations)
    {
      memcpy(&transUpdateCmd.entryField, &payload[tempPayloadIndex], sizeof(zgpTransTableUpdateEntryField_t));
      tempPayloadIndex += sizeof(zgpTransTableUpdateEntryField_t);
      if (transUpdateCmd.entryField.zclCmdPayloadLength && (transUpdateCmd.entryField.zclCmdPayloadLength < UNSPECIFIED_LENGTH))
      {
        tempPayloadIndex += transUpdateCmd.entryField.zclCmdPayloadLength;
      }
      if (additionalInfoBlockPresent)
      {
        uint8_t addInfolength = payload[tempPayloadIndex++];

        tempPayloadIndex += addInfolength;
      }
      if (payloadLength < tempPayloadIndex)
        return ZCL_MALFORMED_COMMAND_STATUS;
      i++;
    }
  }

  i = 0;
  while(i < transUpdateCmd.options.noOfTranslations)
  {
    uint8_t zclCmdPayloadIndex = 0;
#if (defined ZGP_ENABLE_MULTI_SENSOR_SUPPORT || defined ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT)
    uint8_t addBlockInfoIndex = 0; 
#endif

    memcpy(&transUpdateCmd.entryField, &payload[payloadIndex], sizeof(zgpTransTableUpdateEntryField_t));
    payloadIndex += sizeof(zgpTransTableUpdateEntryField_t);
    if (additionalInfoBlockPresent)
    {
#if (defined ZGP_ENABLE_MULTI_SENSOR_SUPPORT || defined ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT)
      addBlockInfoIndex = payloadIndex;
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
    if((transUpdateCmd.entryField.gpdCmdId == ZGP_8_BIT_VECTOR_PRESS) ||
       (transUpdateCmd.entryField.gpdCmdId == ZGP_8_BIT_VECTOR_RELEASE))
    {
      // parse addinfo block as switchinfo
      uint8_t tempIndex = addBlockInfoIndex; 
      switchInfo.switchInfoLength = payload[tempIndex++];
      memcpy(&switchInfo.genericSwitchConfig, (void const *)(payload+tempIndex), sizeof(zgpGenericSwitchConfig_t));
	  tempIndex++;
      switchInfo.currContactStatus = payload[tempIndex++];
      switchInfo.contactBitMask = payload[tempIndex];
    }
#endif  // ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT       
#endif
      payloadIndex += (1 + payload[payloadIndex]);
    }
    if (transUpdateCmd.entryField.zclCmdPayloadLength && (transUpdateCmd.entryField.zclCmdPayloadLength < UNSPECIFIED_LENGTH))
    {
      zclCmdPayloadIndex = payloadIndex;
      payloadIndex += transUpdateCmd.entryField.zclCmdPayloadLength;
    }
    if (transUpdateCmd.entryField.index != ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX)
    {
      // the current spec. (A.3.3.4.4), this field should be ignored on reception
      transUpdateCmd.entryField.index = ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX;
    }

    // process the action
    if ((ZGP_TRANS_UPDATE_ACTION_ADD == transUpdateCmd.options.action) || \
        (ZGP_TRANS_UPDATE_ACTION_REPLACE == transUpdateCmd.options.action))
    {
      zgpTranslationEntryReadOperation_t transTableReadParam = {.appId = (ZGP_ApplicationId_t)transUpdateCmd.options.appId, .ignoreAppId = false, .ignoreGpdId = false, .transLookupTableIndex = 0, \
                                                                .gpdId = &transUpdateCmd.gpdId, .gpdEndPoint = transUpdateCmd.endPoint, \
                                                                .gpdCmdId = transUpdateCmd.entryField.gpdCmdId,
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT                                                                  
                                                                .contactStatus = switchInfo.currContactStatus
#endif
                                                               };
      bool replaceRequired = false;

      memset(&zgpZclMappingInfo, 0x00, sizeof(zgpZclMappingInfo));
      if (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != zgpTransTableGetZgpZclMappingInfo(&transTableReadParam, &zgpZclMappingInfo))
      {
        if (ZGP_TRANS_UPDATE_ACTION_ADD == transUpdateCmd.options.action)
        {
          i++;
          if (ZGP_COMPACT_ATTR_REPORT_CMD_ID != transUpdateCmd.entryField.gpdCmdId)
            continue;
        }
        else
        {
          if (compareZclFields(&zgpZclMappingInfo, &transUpdateCmd.entryField))
          {
            // update may be required for contactBitmask
            if((transUpdateCmd.entryField.gpdCmdId != ZGP_8_BIT_VECTOR_PRESS) &&
               (transUpdateCmd.entryField.gpdCmdId != ZGP_8_BIT_VECTOR_RELEASE))
            {
              i++;
              continue;
            }
          }
          else
          {
            if(zgpZclMappingInfo.cmdMapInfo.zclClusterId != transUpdateCmd.entryField.clusterId)
              replaceRequired = false;
            else
              replaceRequired = true;
          }
        }
      }
      {
        zgpTranslationEntryUpdateOperation_t entryUpdateParam = {.lookupTableIndex = transUpdateCmd.entryField.index, .appId = (ZGP_ApplicationId_t)transUpdateCmd.options.appId,
                                                        .gpdId = &transUpdateCmd.gpdId, .gpdEndPoint = transUpdateCmd.endPoint, .deviceId = 0x00,
                                                        .appEndPoint = transUpdateCmd.entryField.endPoint, .noOfCmds = 0x1,
                                                        .cmdList =  NULL, .isReplaceReq = replaceRequired,
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
                                                        .totalNoofReports = (uint8_t)additionalInfoBlockPresent,
                                                        .reportDescriptor = (void *)&payload[addBlockInfoIndex],
#else
                                                        .totalNoofReports = 0,
                                                        .reportDescriptor = NULL,
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
                                                        .switchInfo.switchInfoLength = switchInfo.switchInfoLength,
                                                        .switchInfo.genericSwitchConfig = switchInfo.genericSwitchConfig,
                                                        .switchInfo.currContactStatus = switchInfo.currContactStatus,
                                                        .switchInfo.contactBitMask = switchInfo.contactBitMask
#else
                                                        .switchInfo.switchInfoLength = 0,
                                                        .switchInfo.genericSwitchConfig = 0,
                                                        .switchInfo.currContactStatus = 0,
                                                        .switchInfo.contactBitMask = 0
#endif                                                          
                                                        };
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
#ifndef ZGP_GPD_PROCESSING_IN_APPLICATION_SUPPORTED 
        if((entryUpdateParam.switchInfo.switchInfoLength) && (entryUpdateParam.switchInfo.contactBitMask == 0x00))
          return ZCL_FAILURE_STATUS;
#endif     
#endif
        // If given index is 0xFF, look for avain the given index, add the new entry
        zgpTransTableAddEntry(&entryUpdateParam, &transUpdateCmd.entryField, &payload[zclCmdPayloadIndex]);
      }
    }
    else if (ZGP_TRANS_UPDATE_ACTION_REMOVE == transUpdateCmd.options.action)
    {
      zgpTransTableEntryRemoveOperation_t transTableRemoveField = { .appId = (ZGP_ApplicationId_t)transUpdateCmd.options.appId,
                                                                    .gpdId = &transUpdateCmd.gpdId,
                                                                    .gpdEndPoint = transUpdateCmd.endPoint,
                                                                    .gpdCmdId = transUpdateCmd.entryField.gpdCmdId,
                                                                    .zclClusterId = transUpdateCmd.entryField.clusterId,
                                                                    .zclCmdId = transUpdateCmd.entryField.zclCmdId,
                                                                    .profileId = transUpdateCmd.entryField.profileId,
                                                                    .appEndPoint = transUpdateCmd.entryField.endPoint
                                                                  };
      zgpTransTableRemoveEntry(&transTableRemoveField);
      //break;
    }
    else
      return ZCL_INVALID_FIELD_STATUS;

    i++;
  }

  return ZCL_SUCCESS_STATUS;
}
/**************************************************************************//**
  \brief comparing rxd trans table update field and the existing entry field

  \param[in] entryInfo - existing entry field
             rxdinfo - rxd fields

  \return true - if entry matches
          false otherwise
******************************************************************************/
static bool compareZclFields(zgpEndPointAndZclInfo_t *entryInfo, zgpTransTableUpdateEntryField_t *rxdinfo)
{
  if ( (entryInfo->appEndPoint == rxdinfo->endPoint) && (entryInfo->gpdCmdId == rxdinfo->gpdCmdId) && \
       (entryInfo->cmdMapInfo.zclCmdId == rxdinfo->zclCmdId) && (entryInfo->cmdMapInfo.zclClusterId == rxdinfo->clusterId) && \
       (entryInfo->gpdAppInfoEntry.profileId == rxdinfo->profileId))
    return true;

  return false;
}

/**************************************************************************//**
  \brief GP translation table request indication

  \param[in] addressing - addressing info
             payloadlength & payload - payload info

  \return success or failure.
******************************************************************************/
static ZCL_Status_t zgpTranslationTableRequestHandling(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  zgpGpTransTableReq_t tableReq;
  ZCL_Request_t *req;
  zgpTransTableResp_t *tableResp;
  uint8_t *entryPayload;
  uint8_t rspOverhead = 0;
  uint8_t payloadIndex = 0;
  zgpTranslationEntryReadOperation_t transTableReadParam = {.ignoreAppId = true, .ignoreGpdId = true, .transLookupTableIndex = 0, \
                                                            .gpdId = NULL};
  uint8_t zclMaxApsAsduSize = 0;
  zclMaxApsAsduSize = APS_MAX_NON_SECURITY_ASDU_SIZE;
#ifdef _NWK_CONCENTRATOR_
  bool nwkConcentrator = false;
  CS_ReadParameter(CS_NWK_CONCENTRATOR_CONFIG_ID, &nwkConcentrator);
  if (!nwkConcentrator)
  zclMaxApsAsduSize += NWK_MAX_SOURCE_ROUTE_SUBFRAME_LENGTH;
#endif
  if(addressing->nonUnicast)
    return ZCL_SUCCESS_STATUS;

  memset(&zgpZclMappingInfo, 0x00, sizeof(zgpZclMappingInfo));
  tableReq.startIndex = payload[0];

  if (!(req = getFreeCommand()))
    return ZCL_INSUFFICIENT_SPACE_STATUS;

  tableResp = (zgpTransTableResp_t *)req->requestPayload;
  entryPayload = &tableResp->tableEntries[0];

  rspOverhead = sizeof(ZCL_Status_t) + sizeof(tableResp->totalNumberOfEntries)
                + sizeof(tableResp->options) + sizeof(tableResp->entriesCount) + sizeof(tableResp->startIndex);

  tableResp->startIndex = tableReq.startIndex;
  transTableReadParam.transLookupTableIndex  = tableReq.startIndex;
  memset(&tableResp->options, 0x00, sizeof(tableResp->options));
  tableResp->totalNumberOfEntries = zgpGetTransTableEntries();
  tableResp->entriesCount = 0x00;
    
  {
    uint8_t maxRspPayload = zclMaxApsAsduSize - ZCL_FRAME_STANDARD_HEADER_SIZE - rspOverhead;
    uint8_t tempPayload[sizeof(zgpTransTableResp_t)] = {0};

    tableResp->status = ZCL_SUCCESS_STATUS;

    while (ZGP_TRANS_TABLE_ENTRY_INVALID_INDEX != (transTableReadParam.transLookupTableIndex = zgpTransTableGetZgpZclMappingInfo(&transTableReadParam, &zgpZclMappingInfo)))
    {
      uint8_t index = 0;
      if (transTableReadParam.ignoreAppId)
      {
        // After reading the first entry matching index
        // then look for the translation entries with the same application id
        transTableReadParam.ignoreAppId = false;
        transTableReadParam.appId = zgpZclMappingInfo.gpdAppInfoEntry.appId;
        tableResp->options.applicationId = zgpZclMappingInfo.gpdAppInfoEntry.appId;
      }
      if (ZGP_SRC_APPID == transTableReadParam.appId)
      {
        uint32_t srcId = zgpZclMappingInfo.gpdAppInfoEntry.gpdId.gpdSrcId;
        // add the entry to the payload
        memcpy(&tempPayload[index], &srcId, sizeof(srcId));
        index += sizeof(zgpZclMappingInfo.gpdAppInfoEntry.gpdId.gpdSrcId);
      }
      else
      {
        uint64_t ieeeAddr = zgpZclMappingInfo.gpdAppInfoEntry.gpdId.gpdIeeeAddr;
        // add the entry to the payload
        memcpy(&tempPayload[index], &ieeeAddr, sizeof(ieeeAddr));
        index += sizeof(zgpZclMappingInfo.gpdAppInfoEntry.gpdId.gpdIeeeAddr);
        tempPayload[index++] = zgpZclMappingInfo.gpdAppInfoEntry.gpdEndPoint;
      }
      tempPayload[index++] = zgpZclMappingInfo.gpdCmdId;
      tempPayload[index++] = zgpZclMappingInfo.gpdAppInfoEntry.appEndPoint;
      {
        uint16_t tempData = zgpZclMappingInfo.gpdAppInfoEntry.profileId;
        memcpy(&tempPayload[index], &tempData, sizeof(uint16_t));
        index += sizeof(uint16_t);
        tempData = zgpZclMappingInfo.cmdMapInfo.zclClusterId;
        memcpy(&tempPayload[index], &tempData, sizeof(uint16_t));
        index += sizeof(uint16_t);
      }
      tempPayload[index++] = zgpZclMappingInfo.cmdMapInfo.zclCmdId;
      tempPayload[index++] = zgpZclMappingInfo.cmdMapInfo.payloadLength;
      if (zgpZclMappingInfo.cmdMapInfo.payloadLength && ((UNSPECIFIED_LENGTH != zgpZclMappingInfo.cmdMapInfo.payloadLength) && (0xFF != zgpZclMappingInfo.cmdMapInfo.payloadLength)))
      {
        memcpy(&tempPayload[index], &zgpZclMappingInfo.cmdMapInfo.payload[0], zgpZclMappingInfo.cmdMapInfo.payloadLength);
        index += zgpZclMappingInfo.cmdMapInfo.payloadLength;
      }
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
      if (zgpZclMappingInfo.gpdAppInfoEntry.addInfoBlock.addInfoBlockLength)
      {
        tableResp->options.additionalInfoBlockPresent = true;
        if (ZGP_COMPACT_ATTR_REPORT_CMD_ID == zgpZclMappingInfo.gpdCmdId)
          index += zgpAddAdditionalInfoBlockToResponse(&zgpZclMappingInfo, &tempPayload[index]);
        else
        {
          tempPayload[index++] = 0x00; // For gpd command Ids other then 0xA8(compact report), additional block length is set to zero
        }
      }
#endif
#ifdef ZGP_ENABLE_GENERIC_8_CONTACT_SWITCH_SUPPORT
      if ((ZGP_8_BIT_VECTOR_PRESS == zgpZclMappingInfo.gpdCmdId) || 
        ZGP_8_BIT_VECTOR_RELEASE == zgpZclMappingInfo.gpdCmdId)
      {
        tableResp->options.additionalInfoBlockPresent = true;
        tempPayload[index++] = GENERIC_8C_SWITCH_ADD_INFO_LENGTH;
        tempPayload[index++] = GENERIC_8C_SWITCH_OPTION_DATA_LENGTH; // option length = 1, generic switch command execution = 0
        tempPayload[index++] = zgpSinkTranslationTable.g8csOptionData[transTableReadParam.transLookupTableIndex].contactStatus;
        tempPayload[index++] = zgpSinkTranslationTable.g8csOptionData[transTableReadParam.transLookupTableIndex].contactBitmask;
      }
#endif

      if (index > maxRspPayload)
      {
        break;
      }

      memcpy(&entryPayload[payloadIndex], &tempPayload[0], index);
      tableResp->entriesCount++;
      payloadIndex += index;
      maxRspPayload -= index;
      transTableReadParam.transLookupTableIndex++;
    }
  }

  // initiate table response via zcl command
  req->dstAddressing.addrMode = APS_SHORT_ADDRESS;
  req->dstAddressing.addr.shortAddress = addressing->addr.shortAddress; // send to proxy address
  req->dstAddressing.sequenceNumber = addressing->sequenceNumber;

  rspOverhead += payloadIndex;

  req->ZCL_Notify = tableRespNotify;
  
//As per 1.1 spec the status should be NOt Found
  if((!(tableResp->totalNumberOfEntries)) || !(tableResp->entriesCount))
  {
    tableResp->status = ZCL_NOT_FOUND_STATUS;
    tableResp->entriesCount = 0;
    rspOverhead -= payloadIndex;
  }

  zgpSendTransCommand(req, ZCL_CLUSTER_SIDE_CLIENT, ZCL_GP_CLUSTER_CLIENT_GP_TRANSLATION_TABLE_RESP_COMMAND_ID, \
                                    rspOverhead);

  return ZCL_SUCCESS_STATUS;
}
#ifdef ZGP_ENABLE_MULTI_SENSOR_SUPPORT
/**************************************************************************//**
  \brief add additional information block to trans table response

  \param[in] zclCmdInfo - mapped zcl cmd info
             payload - rsp payload to be populated

  \return length of payload populated
******************************************************************************/
static uint8_t zgpAddAdditionalInfoBlockToResponse(zgpEndPointAndZclInfo_t *zclCmdInfo, uint8_t *payload)
{
  uint8_t addBlocklength = 0;

  payload[addBlocklength++] = zclCmdInfo->gpdAppInfoEntry.addInfoBlock.addInfoBlockLength;

  for (uint8_t i = 0; i < ZGP_NO_OF_OPTION_RECORDS_IN_TRANS_ENTRY; i++)
  {
    if (zclCmdInfo->gpdAppInfoEntry.addInfoBlock.record[i].isValid)
    {
      memcpy(&payload[addBlocklength++], &zclCmdInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionSelector, \
                      sizeof(zclCmdInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionSelector));
      memcpy(&payload[addBlocklength], &zclCmdInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionData, \
              zclCmdInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionSelector.optionLength + 1);
      addBlocklength += (zclCmdInfo->gpdAppInfoEntry.addInfoBlock.record[i].optionSelector.optionLength + 1);
    }
  }
  return addBlocklength;
}
#endif
/**************************************************************************//**
  \brief confirmation callback for trans table response sent

  \param[in] ntfy - callback info

  \return None
******************************************************************************/
static void tableRespNotify(ZCL_Notify_t *ntfy)
{
  (void)ntfy;
}
#endif //#ifndef ZGP_LW_TRANSLATION_TABLE
/**************************************************************************//**
  \brief Returns the all app end points

  \param[in] endPointId - pointer to the list where eps will be loaded

  \return number of end points
******************************************************************************/
static uint8_t zgpGetAllEndPoints(uint8_t *endPointId)
{
  APS_RegisterEndpointReq_t *epReq = NULL;
  uint8_t epCount = 0;

  //To get eachEndpoint and verify if the cluster is available in the particular endpoint(scan through all the endpoints)
  epReq = APS_NextEndpoint(epReq);
  while(NULL != epReq)
  {
    if (GREEN_POWER_ENDPOINT != epReq->simpleDescriptor->endpoint)
    {
      endPointId[epCount++] = epReq->simpleDescriptor->endpoint;
    }
    epReq = APS_NextEndpoint(epReq);
  }
  return epCount;
}
#ifndef ZGP_LW_TRANSLATION_TABLE
/**************************************************************************//**
  \brief send zgp cluster command

  \param[in] req - pointer to ZCL request
             options - direction/attribute cmd information
             cmdId - command id of the request
             payLoadLength - length of the command payload length

  \return none
******************************************************************************/
static void zgpSendTransCommand(ZCL_Request_t *req, bool dir, uint8_t cmdId, \
                                uint8_t payLoadLength)
{
  req->dstAddressing.endpointId = GREEN_POWER_ENDPOINT;
  req->dstAddressing.manufacturerSpecCode = false;
  req->dstAddressing.profileId = GREEN_POWER_PROFILE_ID;
  req->dstAddressing.clusterId = GREEN_POWER_CLUSTER_ID;
  req->dstAddressing.clusterSide = dir;
  req->endpointId = GREEN_POWER_ENDPOINT;
  req->requestLength = payLoadLength;
  req->id = cmdId;
  req->defaultResponse = ZCL_FRAME_CONTROL_DISABLE_DEFAULT_RESPONSE;

  ZCL_CommandManagerSendCommand(req);
}
#endif // ZGP_LW_TRANSLATION_TABLE
#endif //_ZGP_DISABLE_TRANSLATION_TABLE_
#endif // #if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#endif // _GREENPOWER_SUPPORT_

// eof zgpTranslationTable.c
