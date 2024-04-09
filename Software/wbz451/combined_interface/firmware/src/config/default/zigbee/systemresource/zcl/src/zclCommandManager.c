/*******************************************************************************
  Zigbee Cluster Library Command Manager Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclcommandManager.c

  Summary:
    This file contains ZCL Command manager implementation..

  Description:
    This file contains ZCL Command manager implementation..
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


/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysUtils.h>
#include <zcl/include/zclCommandManager.h>
#include <zcl/include/zclParser.h>
#include <app_zigbee/zigbee_console/console.h>
#if MICROCHIP_APPLICATION_SUPPORT == 1
#include <zcl/include/zclZllBasicCluster.h>
#include <zcl/include/zclZllIdentifyCluster.h>
#include <zcl/include/zclZllOnOffCluster.h>
#include <zcl/include/zclZllLevelControlCluster.h>
#include <zcl/include/zclZllColorControlCluster.h>
#include <zcl/include/zclZllCommissioningCluster.h>
#include <zcl/include/zclZllGroupsCluster.h>
#include <zcl/include/zclZllScenesCluster.h>
#include <zcl/clusters/include/scenes.h>
#include <zcl/include/zclIasZoneCluster.h>
#include <zcl/include/zclIasACECluster.h>
#include <zcl/include/zclThermostatCluster.h>
#include <zcl/include/zclZllLevelControlCluster.h>
#include <zcl/include/zclZllScenesCluster.h>
#endif

#ifdef _GREENPOWER_SUPPORT_
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
#include <zcl/include/zclGreenPowerCluster.h>
#include <zgp/GPInfrastructure/highZgp/include/zgpClusterStructure.h>
#endif
#endif
/******************************************************************************
                    Definitions section
******************************************************************************/
#ifndef COMMAND_BUFFERS_AMOUNT
#define COMMAND_BUFFERS_AMOUNT 6
#endif
#define ALL_ATTRIBUTES_ARE_WRITTEN 1

/******************************************************************************
                    Types section
******************************************************************************/
#if MICROCHIP_APPLICATION_SUPPORT == 1
BEGIN_PACK
typedef union PACK
{
  ZCL_GetGroupMembership_t getGroupMembership;
  uint8_t                  payload[sizeof(ZCL_GetGroupMembership_t) - sizeof(uint16_t) + CS_GROUP_TABLE_SIZE * sizeof(uint16_t)];
                                   /* own structure size */           /* size of stub */  /* up to CS_GROUP_TABLE_SIZE groups in list */
} GetGroupMemeberShip_t;

typedef union PACK
{
  ZCL_GetGroupMembershipResponse_t getGroupMembershipResponse;
  uint8_t                          payload[sizeof(ZCL_GetGroupMembershipResponse_t) - sizeof(uint16_t) + CS_GROUP_TABLE_SIZE * sizeof(uint16_t)];
                                           /* own structure size */                 /* size of stub */  /* up to CS_GROUP_TABLE_SIZE groups in list */
} GetGroupMembershipResponse_t;

typedef union PACK
{
  struct PACK
  {
    ZCL_OnOffClusterExtensionFieldSet_t    onOffExtFields;
    ZCL_LevelControlClusterExtensionFieldSet_t levelControlExtFields;
  } onOffLevelControlExt;
  struct PACK
  {
    ZCL_ThermostatClusterExtensionFieldSet_t thermostatExtFields;
  } thermostatExt;
} SceneExtFields_t;

typedef union PACK
{
  ZCL_AddScene_t addScene;
  uint8_t        payload[sizeof(ZCL_AddScene_t) + sizeof(SceneExtFields_t)];
                         /* own structure size */ /* size of ext fields */
} AddScene_t;

typedef union PACK
{
  ZCL_ViewSceneResponse_t viewSceneResponse;
  uint8_t                 payload[sizeof(ZCL_ViewSceneResponse_t) + sizeof(SceneExtFields_t)];
                                  /* own structure size */          /* size of ext fields */
} ViewSceneResponse_t;

typedef union PACK
{
  ZCL_GetSceneMembershipResponse_t getSceneMembershupResponse;
  uint8_t                          payload[sizeof(ZCL_GetSceneMembershipResponse_t) - sizeof(uint8_t) + MAX_SCENES_AMOUNT * sizeof(uint8_t)];
                                          /* own structure size */                    /* size of stub */ /* up to MAX_SCENES_AMOUNT in list */
} GetSceneMembershipResponse_t;
END_PACK
#endif
typedef union
{
#if MICROCHIP_APPLICATION_SUPPORT == 1
  // Identify Cluster
  ZCL_Identify_t                 identify;
  ZCL_IdentifyQueryResponse_t    identifyQueryResponse;

  // Level Control Cluster
  ZCL_MoveToLevel_t              moveToLevel;
  ZCL_Move_t                     move;
  ZCL_Step_t                     step;
  ZCL_MoveToLevelWithOptions_t   moveToLevelWithOptions;
  ZCL_MoveWithOptions_t          moveWithOptions;
  ZCL_StepWithOptions_t          stepWithOptions;
  ZCL_StopWithOptions_t          stopWithOptions;
  
#ifdef APP_DEVICE_TYPE_EXTENDED_COLOR_LIGHT

  // Color Control cluster
  ZCL_ZllMoveToHueCommand_t         moveToHue;
  ZCL_ZllMoveHueCommand_t           moveHue;
  ZCL_ZllStepHueCommand_t           stepHue;
  ZCL_ZllMoveToSaturationCommand_t  moveToSaturation;
  ZCL_ZllMoveSaturationCommand_t    moveSaturation;
  ZCL_ZllStepSaturationCommand_t    stepSaturation;
  ZCL_ZllMoveToHueAndSaturationCommand_t moveToHueAndSaturation;
  ZCL_ZllMoveToColorCommand_t       moveToColor;
  ZCL_ZllMoveColorCommand_t         moveColor;
  ZCL_ZllStepColorCommand_t         stepColor;
  ZCL_ZllEnhancedMoveToHueCommand_t enhancedMoveToHue;
  ZCL_ZllEnhancedMoveHueCommand_t   enhancedMoveHue;
  ZCL_ZllEnhancedStepHueCommand_t   enhancedStepHue;
  ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t enhancedMoveToHueAndSaturation;
  ZCL_ZllColorLoopSetCommand_t      colorLoopSet;
  ZCL_ZllMoveToColorTemperatureCommand_t moveToColorTemperature;
  ZCL_ZllMoveColorTemperatureCommand_t moveColorTemperature;
  ZCL_ZllStepColorTemperatureCommand_t stepColorTemperature;
  ZCL_ZllMoveToHueWithOptionsCommand_t         moveToHueWithOptions;
  ZCL_ZllMoveHueWithOptionsCommand_t           moveHueWithOptions;
  ZCL_ZllStepHueWithOptionsCommand_t           stepHueWithOptions;
  ZCL_ZllMoveToSaturationWithOptionsCommand_t  moveToSaturationWithOptions;
  ZCL_ZllMoveSaturationWithOptionsCommand_t    moveSaturationWithOptions;
  ZCL_ZllStepSaturationWithOptionsCommand_t    stepSaturationWithOptions;
  ZCL_ZllMoveToHueAndSaturationWithOptionsCommand_t moveToHueAndSaturationWithOptions;
  ZCL_ZllMoveToColorWithOptionsCommand_t       moveToColorWithOptions;
  ZCL_ZllMoveColorWithOptionsCommand_t         moveColorWithOptions;
  ZCL_ZllStepColorWithOptionsCommand_t         stepColorWithOptions;
  ZCL_ZllEnhancedMoveToHueWithOptionsCommand_t enhancedMoveToHueWithOptions;
  ZCL_ZllEnhancedMoveHueWithOptionsCommand_t   enhancedMoveHueWithOptions;
  ZCL_ZllEnhancedStepHueWithOptionsCommand_t   enhancedStepHueWithOptions;
  ZCL_ZllEnhancedMoveToHueAndSaturationWithOptionsCommand_t enhancedMoveToHueAndSaturationWithOptions;
  ZCL_ZllColorLoopSetWithOptionsCommand_t      colorLoopSetWithOptions;
  ZCL_ZllMoveToColorTemperatureWithOptionsCommand_t moveToColorTemperatureWithOptions;
  ZCL_ZllMoveColorTemperatureWithOptionsCommand_t moveColorTemperatureWithOptions;
  ZCL_ZllStepColorTemperatureWithOptionsCommand_t stepColorTemperatureWithOptions;

  // Commissioning cluster
  ZCL_GetGroupIdentifiers_t         getGroupIdentifiers;
  ZCL_GetEndpointList_t             getEndpointList;
  ZCL_EndpointInformation_t         endpointInformation;
  ZCL_GetGroupIdentifiersResponse_t getGroupIdentifiersResp;
  ZCL_GetEndpointListResponse_t     getEndpointListResp;

#endif // APP_DEVICE_TYPE_EXTENDED_COLOR_LIGHT

  // Groups Cluster
  ZCL_AddGroup_t                 addGroup;
  ZCL_ViewGroup_t                viewGroup;
  GetGroupMemeberShip_t          getGroupMembership;
  ZCL_RemoveGroup_t              removeGroup;
  ZCL_AddGroupIfIdentifying_t    addGroupIfIdentifying;
  ZCL_AddGroupResponse_t         addGroupResponse;
  ZCL_ViewGroupResponse_t        viewGroupResponse;
  GetGroupMembershipResponse_t   getGroupMembershipResponse;
  ZCL_RemoveGroupResponse_t      removeGroupResponse;

  // Scenes cluster
  AddScene_t                     addScene;
  ZCL_ViewScene_t                viewScene;
  ZCL_RemoveScene_t              removeScene;
  ZCL_RemoveAllScenes_t          removeAllScenes;
  ZCL_StoreScene_t               storeScene;
  ZCL_RecallScene_t              recallScene;
  ZCL_GetSceneMembership_t       getSceneMembership;
  ZCL_AddSceneResponse_t         addSceneResponse;
  ViewSceneResponse_t            viewSceneResponse;
  ZCL_RemoveSceneResponse_t      removeSceneResponse;
  ZCL_RemoveAllScenesResponse_t  removeAllScenesResponse;
  ZCL_StoreSceneResponse_t       storeSceneResponse;
  GetSceneMembershipResponse_t   getSceneMembershupResponse;
#endif //MICROCHIP_APPLICATION_SUPPORT == 1
#ifdef _GREENPOWER_SUPPORT_
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
  // Green power cluster
  ZGP_TableResp_t gpTableResponse;
  ZGP_GpNotification_t gpNotification;
  ZGP_TableRequest_t gpTableRequest;
#if APP_ZGP_DEVICE_TYPE > APP_ZGP_DEVICE_TYPE_PROXY_BASIC  
  ZGP_GpResp_t gpResponse;
  ZGP_GpPairing_t gpPairing;
  ZGP_GpProxyCommMode_t gpProxyCommMode;
#endif // APP_ZGP_DEVICE_TYPE > APP_ZGP_DEVICE_TYPE_PROXY_BASIC
#endif // APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
#endif // _GREENPOWER_SUPPORT_
} Command_t;

typedef struct
{
  ZCL_Request_t zclRequest;
  Command_t     zclCommand;
  bool          busy;
  bool          isAttributeOperation;
  void (*ZCL_Notify)(ZCL_Notify_t *ntfy);
} ZclCommandDescriptor_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/
static void commandZclRequestResp(ZCL_Notify_t *ntfy);

/******************************************************************************
                    Local variables section
******************************************************************************/
static ZclCommandDescriptor_t zclCommands[COMMAND_BUFFERS_AMOUNT];

/******************************************************************************
                    Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Initializes command manager
******************************************************************************/
void ZCL_CommandManagerInit(void)
{
  for (uint8_t i = 0; i < COMMAND_BUFFERS_AMOUNT; i++)
    zclCommands[i].busy = false;
}

/**************************************************************************//**
\brief Gets a free buffer for a ZCL command

\return A pointer to a command's buffer or NULL if no free buffers are left
******************************************************************************/
ZCL_Request_t *ZCL_CommandManagerAllocCommand(void)
{
  uint8_t i = 0;
  bool packetBufferAllocateFailures = 0;
  for (; i < COMMAND_BUFFERS_AMOUNT; i++)
  {
    if (!zclCommands[i].busy)
    {
      zclCommands[i].isAttributeOperation = false;
      zclCommands[i].busy = true;
      memset(&zclCommands[i].zclRequest, 0, sizeof(ZCL_Request_t));
      memset(&zclCommands[i].zclCommand, 0, sizeof(Command_t));
      zclCommands[i].zclRequest.requestPayload = (uint8_t *)&zclCommands[i].zclCommand;
      return &zclCommands[i].zclRequest;
    }
   }
   packetBufferAllocateFailures = 1;
   SYS_PostEvent(BC_EVENT_PACKET_BUFFER_ALLOCATE_FAIL, (SYS_EventData_t)&packetBufferAllocateFailures);
  return NULL;
}

/**************************************************************************//**
\brief Sends command request
\param[in] req - request parameters
******************************************************************************/
void ZCL_CommandManagerSendCommand(ZCL_Request_t *req)
{
  ZclCommandDescriptor_t *command = GET_PARENT_BY_FIELD(ZclCommandDescriptor_t, zclRequest, req);

  command->isAttributeOperation = false; // command req
  
  command->ZCL_Notify = req->ZCL_Notify;
  req->ZCL_Notify     = commandZclRequestResp;

  ZCL_CommandReq(req);
}

/**************************************************************************//**
\brief Sends attribute request
\param[in] req - request parameters
******************************************************************************/
void ZCL_CommandManagerSendAttribute(ZCL_Request_t *req)
{
  ZclCommandDescriptor_t *command = GET_PARENT_BY_FIELD(ZclCommandDescriptor_t, zclRequest, req);

  command->isAttributeOperation = true; // attribute req
  
  command->ZCL_Notify = req->ZCL_Notify;
  req->ZCL_Notify     = commandZclRequestResp;

  ZCL_AttributeReq(req);
}

/**************************************************************************//**
\brief ZCL command response
******************************************************************************/
static void commandZclRequestResp(ZCL_Notify_t *ntfy)
{
  ZclCommandDescriptor_t *command = GET_PARENT_BY_FIELD(ZclCommandDescriptor_t, zclRequest.notify, ntfy);

  /* Process the response received */
  if (ZCL_APS_CONFIRM_ID == ntfy->id && ZCL_SUCCESS_STATUS != ntfy->status)
  {
    appSnprintf("Zcl Command TX Confirm: status = 0x%02x\r\n", ntfy->status);
  }
  else if (ZCL_ZCL_RESPONSE_ID == ntfy->id)
  {
    ZCL_Request_t *req = GET_STRUCT_BY_FIELD_POINTER(ZCL_Request_t, notify, ntfy);

    if (((ZCL_STANDARD_REQ_TYPE == command->zclRequest.service.requestType) &&
        (ZCL_WRITE_ATTRIBUTES_COMMAND_ID == req->id || ZCL_WRITE_ATTRIBUTES_UNDIVIDED_COMMAND_ID == req->id)) &&
        ALL_ATTRIBUTES_ARE_WRITTEN != req->notify.responseLength)
    {
      ZCL_NextElement_t element;
      ZCL_WriteAttributeResp_t *writeAttributeResp;

      element.id            = ZCL_WRITE_ATTRIBUTES_RESPONSE_COMMAND_ID;
      element.payloadLength = ntfy->responseLength;
      element.payload       = ntfy->responsePayload;
      element.content       = NULL;

      while (element.payloadLength)
      {
        ZCL_GetNextElement(&element);
        writeAttributeResp = (ZCL_WriteAttributeResp_t *) element.content;
        appSnprintf("Write Attribute Response received: status = 0x%02x\r\n", writeAttributeResp->status);
        element.content = NULL;
      }
    }
    else
    {
      if (command->isAttributeOperation || (ZCL_SUCCESS_STATUS != ntfy->status))
      {
        appSnprintf("Attribute operation response received: status = 0x%02x\r\n", ntfy->status);
      }
    }
  }
  else if (ZCL_DEFAULT_RESPONSE_ID == ntfy->id)
  {
    cmdprintf( "ZclDefaultResponse: status = 0x%02x\r\n", ntfy->status);
  }

  /* Notify callbacks if any registered */
  if (command && command->ZCL_Notify)
    command->ZCL_Notify(ntfy);

  if(command != NULL)
    command->busy = false;
}
/**************************************************************************//**
\brief ZCL default response
******************************************************************************/
void ZCL_CommandZclDefaultResp(ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload)
{
  ZclCommandDescriptor_t *command = GET_PARENT_BY_FIELD(ZclCommandDescriptor_t, zclRequest, req);
  ZCL_DefaultResp_t *defaultResp = (ZCL_DefaultResp_t*)payload;
  cmdprintf("ZclDefaultResponse: status = 0x%02x\r\n", defaultResp->statusCode);
  
  if(command != NULL)
    command->busy = false;
  
  (void) addressing;
  (void) payload;
  (void) payloadLength;
  (void) defaultResp;
}
// eof zclcommandManager.c
