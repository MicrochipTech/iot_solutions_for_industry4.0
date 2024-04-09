/*******************************************************************************
  Scenes Cluster File

  Company:
    Microchip Technology Inc.

  File Name:
    scenesCluster.c

  Summary:
    This file contains Scenes Cluster Implemenation.

  Description:
   This file contains Scenes Cluster Implemenation.
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
#include <z3device/clusters/include/haClusters.h>
#include <zcl/clusters/include/scenes.h>
#if APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE
#include <z3device/custom/include/customOnOffCluster.h>
#include <z3device/custom/include/customLevelControlCluster.h>
#include <z3device/custom/include/customColorControlCluster.h>
#elif APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_ON_OFF_LIGHT
#include <z3device/light/include/lightOnOffCluster.h>
#include <z3device/light/include/lightLevelControlCluster.h>
#include <z3device/light/include/lightColorControlCluster.h>
#endif
#include <zcl/include/zclCommandManager.h>
#include <pds/include/wlPdsMemIds.h>
#include <z3device/clusters/include/scenesCluster.h>
#include <zcl/include/zclThermostatCluster.h>
#include <zcl/clusters/include/groupsCluster.h>
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_THERMOSTAT)
#include <z3device/thermostat/include/thScenesCluster.h>
#endif
/******************************************************************************
                    Prototypes section
******************************************************************************/
ZCL_Status_t storeScene(ZCL_StoreScene_t *storeScene, Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

static void fillViewRemoveStoreRecallScenePayload(ZCL_ViewScene_t *payload, uint16_t group, uint8_t scene);
static void fillRecallScenePayload(ZCL_RecallScene_t *payload, uint16_t group, uint8_t scene, uint16_t time);

static void fillRemoveAllScenesGetSceneMembershipPayload(ZCL_RemoveAllScenes_t *payload, uint16_t group);

static void fillAddSceneToDimmableLightPayload(ZCL_AddScene_t *payload, uint16_t group, uint8_t scene, uint16_t time, bool onOff, uint8_t level);
static void fillAddSceneToThermostatPayload(ZCL_AddScene_t *payload, uint16_t group, uint8_t scene, uint16_t time,
                                              int16_t occupiedCoolingSetPoint, int16_t occupiedHeatingSetPoint, uint8_t systemMode);
static void fillAddSceneToExtendedColorLightPayload(ZCL_AddScene_t *payload, uint16_t group, uint16_t scene, uint16_t time,
                                                        bool onOff, uint8_t level, ZCL_ColorControlClusterExtensionFieldSet_t *ccExt);
static void fillCopyScenePayload(ZCL_CopyScene_t *payload, SceneMode_t mode, uint16_t gidFrom, uint16_t sidFrom, uint16_t gidTo, uint16_t sidTo);

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_THERMOSTAT)
static uint8_t thFillViewSceneResponsePayload(ZCL_ViewSceneResponse_t *payload, Scene_t *scene, uint8_t status, ZCL_ViewScene_t *request);
#else
static uint8_t lightFillViewSceneResponsePayload(bool enhanced, ZCL_EnhancedViewSceneResponse_t *enhancedViewSceneResp,
  Scene_t *scene);
#endif

/******************************************************************************
                    Global variables section
******************************************************************************/

/******************************************************************************
                    Implementation section
******************************************************************************/

/**************************************************************************//**
\brief Removes all scenes from scene table

\param[in] group - group id

\returns status of scene removing
******************************************************************************/
ZCL_Status_t removeAllScenes(uint16_t group, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCnt)
{
  if (groupsIsValidGroup(group, srcEp))
    *currSceneCnt -= removeScenesByGroup(group, scenePool);
  else
    return ZCL_INVALID_FIELD_STATUS;

  return ZCL_SUCCESS_STATUS;
}

/**************************************************************************//**
\brief Fills Add Scene Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  scene   - scene id;
\param[in]  status  - the status of scene adding
******************************************************************************/
void fillAddRemoveStoreSceneResponsePayload(ZCL_AddSceneResponse_t *payload, uint16_t group, uint8_t scene, uint8_t status)
{
  payload->status  = status;
  payload->groupId = group;
  payload->sceneId = scene;
}
/**************************************************************************//**
\brief Fills Add Scene command to ECL structure

\param[out] payload - pointer to command structure;
\param[in] group - group id;
\param[in] scene - scene id;
\param[in] time  - transition time;
\param[in] onOff - onOff extenstion filed value;
\param[in] level - currentLevel extension field value
\param[in] ccExt - pointer to color control scene extensions
******************************************************************************/
static void fillAddSceneToExtendedColorLightPayload(ZCL_AddScene_t *payload, uint16_t group, uint16_t scene, uint16_t time,
  bool onOff, uint8_t level, ZCL_ColorControlClusterExtensionFieldSet_t *ccExt)
{
  ZCL_OnOffClusterExtensionFieldSet_t *onOffExt = (ZCL_OnOffClusterExtensionFieldSet_t *)&payload->name[1];

  uint8_t *tmp = (uint8_t *)onOffExt + sizeof(ZCL_OnOffClusterExtensionFieldSet_t);
  ZCL_LevelControlClusterExtensionFieldSet_t *levelControlExt = (ZCL_LevelControlClusterExtensionFieldSet_t *)tmp;

  tmp = (uint8_t *)levelControlExt + sizeof(ZCL_LevelControlClusterExtensionFieldSet_t);
  ZCL_ColorControlClusterExtensionFieldSet_t *colorControlExt = (ZCL_ColorControlClusterExtensionFieldSet_t *)tmp;

  payload->groupId        = group;
  payload->sceneId        = scene;
  payload->transitionTime = time;
  payload->name[0]        = 0;

  onOffExt->clusterId  = ONOFF_CLUSTER_ID;
  onOffExt->length     = sizeof(onOffExt->onOffValue);
  onOffExt->onOffValue = onOff;

  levelControlExt->clusterId    = LEVEL_CONTROL_CLUSTER_ID;
  levelControlExt->length       = sizeof(levelControlExt->currentLevel);
  levelControlExt->currentLevel = level;

  colorControlExt->clusterId    = COLOR_CONTROL_CLUSTER_ID;
  colorControlExt->length       = sizeof(ZCL_ColorControlClusterExtensionFieldSet_t) - sizeof(uint16_t) - sizeof(uint8_t);
  colorControlExt->currentX     = ccExt->currentX;
  colorControlExt->currentY     = ccExt->currentY;
  colorControlExt->enhancedCurrentHue = ccExt->enhancedCurrentHue;
  colorControlExt->currentSaturation  = ccExt->currentSaturation;
  colorControlExt->colorLoopActive    = ccExt->colorLoopActive;
  colorControlExt->colorLoopDirection = ccExt->colorLoopDirection;
  colorControlExt->colorLoopTime      = ccExt->colorLoopTime;
  colorControlExt->colorTemperature   = ccExt->colorTemperature;

  (void) tmp;
}

/**************************************************************************//**
\brief Fills Copy Scene command to ECL structure
******************************************************************************/
static void fillCopyScenePayload(ZCL_CopyScene_t *payload, SceneMode_t mode, uint16_t gidFrom, uint16_t sidFrom, uint16_t gidTo, uint16_t sidTo)
{
  payload->mode = mode;
  payload->groupIdFrom = gidFrom;
  payload->sceneIdFrom = sidFrom;
  payload->groupIdTo = gidTo;
  payload->sceneIdTo = sidTo;
}
/**************************************************************************//**
\brief Store to global scene
******************************************************************************/
void storeGlobalScene(Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes)
{
  ZCL_StoreScene_t globalScene;

  globalScene.groupId = 0x0000u;
  globalScene.sceneId = 0x00u;
}
/**************************************************************************//**
\brief Sends Add Scene command to bound Dimmable Light device

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id;
\param[in] time  - transition time;
\param[in] onOff - onOff extenstion filed value;
\param[in] level - currentLevel extension field value
******************************************************************************/
void scenesSendAddSceneToDimmableLight(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene, uint16_t time, bool onOff, uint8_t level)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_ADD_SCENE_COMMAND_ID,
    sizeof(ZCL_AddScene_t) + sizeof(ZCL_OnOffClusterExtensionFieldSet_t) +
    sizeof(ZCL_LevelControlClusterExtensionFieldSet_t), srcEp);
  fillAddSceneToDimmableLightPayload((ZCL_AddScene_t *)req->requestPayload, group, scene, time, onOff, level);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Fills Add Scene command to DL structure

\param[out] payload - pointer to command structure;
\param[in] group - group id;
\param[in] scene - scene id;
\param[in] time  - transition time;
\param[in] onOff - onOff extenstion filed value;
\param[in] level - currentLevel extension field value
******************************************************************************/
static void fillAddSceneToDimmableLightPayload(ZCL_AddScene_t *payload, uint16_t group, uint8_t scene, uint16_t time, bool onOff, uint8_t level)
{
  ZCL_OnOffClusterExtensionFieldSet_t    *onOffExt = (ZCL_OnOffClusterExtensionFieldSet_t *)&payload->name[1];
  uint8_t                                *tmp = (uint8_t *)(&payload->name[1]) + sizeof(ZCL_OnOffClusterExtensionFieldSet_t);
  ZCL_LevelControlClusterExtensionFieldSet_t *levelControlExt = (ZCL_LevelControlClusterExtensionFieldSet_t *)tmp;

  payload->groupId        = group;
  payload->sceneId        = scene;
  payload->transitionTime = time;
  payload->name[0]        = 0;

  onOffExt->clusterId  = ONOFF_CLUSTER_ID;
  onOffExt->length     = sizeof(onOffExt->onOffValue);
  onOffExt->onOffValue = onOff;

  levelControlExt->clusterId    = LEVEL_CONTROL_CLUSTER_ID;
  levelControlExt->length       = sizeof(levelControlExt->currentLevel);
  levelControlExt->currentLevel = level;
}
/**************************************************************************//**
\brief Sends Add Scene command to bound Thermostat device

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id;
\param[in] time  - transition time;
\param[in] occupiedCoolingSetPoint - occupiedCoolingSetPoint extenstion field value;
\param[in] occupiedHeatingSetPoint - occupiedHeatingSetPoint extension field value
\param[in] systemMode              - systemMode extension field value
******************************************************************************/
void scenesSendAddSceneToThermotstat(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene, uint16_t time, int16_t occupiedCoolingSetPoint, int16_t occupiedHeatingSetPoint, uint8_t systemMode)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_ADD_SCENE_COMMAND_ID,
    sizeof(ZCL_AddScene_t) + sizeof(ZCL_ThermostatClusterExtensionFieldSet_t), srcEp);

  fillAddSceneToThermostatPayload((ZCL_AddScene_t *)req->requestPayload, group, scene, time,
                                    occupiedCoolingSetPoint, occupiedHeatingSetPoint, systemMode);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}

/**************************************************************************//**
\brief Fills Add Scene command TH structure

\param[out] payload - pointer to command structure;
\param[in] group - group id;
\param[in] scene - scene id;
\param[in] time  - transition time;
\param[in] occupiedCoolingSetPoint - onOff occupiedCoolingSetPoint filed value;
\param[in] occupiedHeatingSetPoint - occupiedHeatingSetPoint extension field value
\param[in] systemMode              - systemMode extension field value
******************************************************************************/
static void fillAddSceneToThermostatPayload(ZCL_AddScene_t *payload, uint16_t group, uint8_t scene, uint16_t time,
                                              int16_t occupiedCoolingSetPoint, int16_t occupiedHeatingSetPoint, uint8_t systemMode)
{
  ZCL_ThermostatClusterExtensionFieldSet_t    *thermostatExt = (ZCL_ThermostatClusterExtensionFieldSet_t *)&payload->name[1];

  payload->groupId        = group;
  payload->sceneId        = scene;
  payload->transitionTime = time;
  payload->name[0]        = 0;

  thermostatExt->clusterId  = THERMOSTAT_CLUSTER_ID;
  thermostatExt->length     = sizeof(ZCL_ThermostatClusterExtensionFieldSet_t) - sizeof(uint8_t) - sizeof(ClusterId_t) ;
  thermostatExt->occupiedCoolingSetpoint = occupiedCoolingSetPoint;
  thermostatExt->occupiedHeatingSetpoint = occupiedHeatingSetPoint;
  thermostatExt->systemMode = systemMode;
}
/**************************************************************************//**
\brief Sends View Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendViewScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_VIEW_SCENE_COMMAND_ID, sizeof(ZCL_ViewScene_t), srcEp);
  fillViewRemoveStoreRecallScenePayload((ZCL_ViewScene_t *)req->requestPayload, group, scene);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Remove Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendRemoveScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_REMOVE_SCENE_COMMAND_ID, sizeof(ZCL_RemoveScene_t), srcEp);
  fillViewRemoveStoreRecallScenePayload((ZCL_ViewScene_t *)req->requestPayload, group, scene);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Remove All Scenes command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void scenesSendRemoveAllScenes(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_REMOVE_ALL_SCENES_COMMAND_ID, sizeof(ZCL_RemoveAllScenes_t), srcEp);
  fillRemoveAllScenesGetSceneMembershipPayload((ZCL_RemoveAllScenes_t *)req->requestPayload, group);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Store Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendStoreScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_STORE_SCENE_COMMAND_ID, sizeof(ZCL_StoreScene_t), srcEp);
  fillViewRemoveStoreRecallScenePayload((ZCL_ViewScene_t *)req->requestPayload, group, scene);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Recall Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendRecallScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene, uint16_t time)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_RECALL_SCENE_COMMAND_ID, sizeof(ZCL_RecallScene_t), srcEp);
  fillRecallScenePayload((ZCL_RecallScene_t *)req->requestPayload, group, scene, time);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Get Scene Membership command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void scenesSendGetSceneMembership(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_GET_SCENE_MEMBERSHIP_COMMAND_ID, sizeof(ZCL_GetSceneMembership_t), srcEp);
  fillRemoveAllScenesGetSceneMembershipPayload((ZCL_RemoveAllScenes_t *)req->requestPayload, group);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Fills View, Remove, Store or Recall Scene command structure

\param[out] payload - pointer to command structure;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
static void fillViewRemoveStoreRecallScenePayload(ZCL_ViewScene_t *payload, uint16_t group, uint8_t scene)
{
  payload->groupId = group;
  payload->sceneId = scene;
}

/**************************************************************************//**
\brief Fills View, Remove, Store or Recall Scene command structure

\param[out] payload - pointer to command structure;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
static void fillRecallScenePayload(ZCL_RecallScene_t *payload, uint16_t group, uint8_t scene, uint16_t time)
{
  payload->groupId = group;
  payload->sceneId = scene;
  payload->transitionTime = time;
}

/**************************************************************************//**
\brief Fills View, Remove, Store or Recall Scene command structure

\param[out] payload - pointer to command structure;
\param[in] group - group id
******************************************************************************/
static void fillRemoveAllScenesGetSceneMembershipPayload(ZCL_RemoveAllScenes_t *payload, uint16_t group)
{
  payload->groupId = group;
}

/**************************************************************************//**
\brief Remove all scenes associated with the group
\return returns the no. of scenes removed
******************************************************************************/
uint8_t scenesClusterRemoveByGroup(uint16_t group, Scene_t *scenePool)
{
  uint8_t sceneAmt = 0;
  for (uint8_t i = 0; i < MAX_SCENES_AMOUNT; i++)
  {
    if ((scenePool[i].groupId == group) && freeScene(&scenePool[i]))
      sceneAmt++;
  }
  return sceneAmt;
}

/**************************************************************************//**
\brief Sends Enhanced Add Scene command to bound Extended Color Light device

\param[in] mode   - address mode;
\param[in] addr   - short address of destination node or number of group;
\param[in] ep     - endpoint number of destination device;
\param[in] group  - group id;
\param[in] scene  - scene id;
\param[in] time   - transition time;
\param[in] onOff  - onOff extenstion filed value;
\param[in] level  - currentLevel extension field value
\param[in] ccExt  - pointer to color control extension fields values
******************************************************************************/
void scenesSendEnhancedAddSceneToExtendedColorLightWithExtFields(APS_AddrMode_t mode, ShortAddr_t addr,
  Endpoint_t ep, Endpoint_t srcEp, uint16_t group, uint16_t scene, uint16_t time, bool onOff, uint8_t level,
  ZCL_ColorControlClusterExtensionFieldSet_t *ccExt)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_ENHANCED_ADD_SCENE_COMMAND_ID, sizeof(ZCL_EnhancedAddScene_t), srcEp);

  fillAddSceneToExtendedColorLightPayload((ZCL_AddScene_t *)req->requestPayload, group, scene, time, onOff, level, ccExt);

  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Enhanced Add Scene command to bound Thermostat device

\param[in] mode   - address mode;
\param[in] addr   - short address of destination node or number of group;
\param[in] ep     - endpoint number of destination device;
\param[in] group  - group id;
\param[in] scene  - scene id;
\param[in] time   - transition time;
\param[in] occupiedCoolingSetPoint  - occupied cooling setpoint;
\param[in] occupiedHeatingSetPoint  - occupied heating setpoint;
\param[in] systemMode               - System mode;
******************************************************************************/
void scenesSendEnhancedAddSceneToThermostat(APS_AddrMode_t mode, ShortAddr_t addr,
  Endpoint_t ep, Endpoint_t srcEp, uint16_t group, uint16_t scene, uint16_t time, int16_t occupiedCoolingSetPoint, int16_t occupiedHeatingSetPoint,
  uint8_t systemMode)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_ENHANCED_ADD_SCENE_COMMAND_ID, sizeof(ZCL_AddScene_t) + sizeof(ZCL_ThermostatClusterExtensionFieldSet_t), srcEp);

  fillAddSceneToThermostatPayload((ZCL_AddScene_t *)req->requestPayload, group, scene, time, occupiedCoolingSetPoint, occupiedHeatingSetPoint, systemMode);

  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);

  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Enhanced View Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendEnhancedViewScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_ENHANCED_VIEW_SCENE_COMMAND_ID, sizeof(ZCL_ViewScene_t), srcEp);
  fillViewRemoveStoreRecallScenePayload((ZCL_ViewScene_t *)req->requestPayload, group, scene);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
/**************************************************************************//**
\brief Sends Copy Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] *req  - pointer to ZCL_CopyScene_t command
******************************************************************************/
void scenesSendCopyScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  SceneMode_t copyMode, uint16_t gidFrom, uint16_t sidFrom, uint16_t gidTo, uint16_t sidTo)
{
  ZCL_Request_t *req;

  if (!(req = getFreeCommand()))
    return;

  fillCommandRequest(req, ZCL_SCENES_CLUSTER_COPY_SCENE_COMMAND_ID, sizeof(ZCL_CopyScene_t), srcEp);
  fillCopyScenePayload((ZCL_CopyScene_t *)req->requestPayload, copyMode, gidFrom, sidFrom, gidTo, sidTo);
  fillDstAddressing(&req->dstAddressing, mode, addr, ep, SCENES_CLUSTER_ID);
  ZCL_CommandManagerSendCommand(req);
}
//eof scenesCluster.c
