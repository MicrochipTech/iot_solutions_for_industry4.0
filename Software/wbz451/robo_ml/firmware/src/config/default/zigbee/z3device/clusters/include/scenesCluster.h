/*******************************************************************************
  Scenes Cluster header File

  Company:
    Microchip Technology Inc.

  File Name:
    scenesCluster.h

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

#ifndef _SCENESCLUSTER_H
#define _SCENESCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclZllScenesCluster.h>
#include <zcl/clusters/include/scenes.h>

/******************************************************************************
                    Externals
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Extracts scene information from received packet and fills scene structure

\param[in]  payload - received packet payload
\param[out] scene   - scene to be filled
******************************************************************************/
ZCL_Status_t extractSceneInfo(ZCL_AddScene_t *payload, Scene_t *scene, uint8_t length);

/**************************************************************************//**
\brief Adds scene to scene table

\param[in] addScene      - the pointer to Add Scene request;
\param[in] payloadLength - the length of request
\param[in] srcEp         - source Endpoint
\returns status of scene adding
******************************************************************************/
ZCL_Status_t addScene(ZCL_AddScene_t *addScene, uint8_t payloadLength, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCount);

/**************************************************************************//**
\brief Views scene in scene table

\param[in] viewScene - the pointer to View Scene request;
\param[in] scene     - the pointer to the pointer to scene

\returns status of scene viewing
******************************************************************************/
ZCL_Status_t viewScene(ZCL_ViewScene_t *viewScene, Scene_t **scene, Endpoint_t srcEp,  Scene_t* scenePool);

/**************************************************************************//**
\brief Removes scene from scene table

\param[in] removeScene - the pointer to Remove Scene request

\returns status of scene removing
******************************************************************************/
ZCL_Status_t removeScene(ZCL_RemoveScene_t *removeScene, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCount);

/**************************************************************************//**
\brief Stores scene to scene table

\param[in] storeScene - the pointer to Store Scene request

\returns status of scene storing
******************************************************************************/
ZCL_Status_t storeScene(ZCL_StoreScene_t *storeScene, Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

/**************************************************************************//**
\brief Recalls scene from scene table

\param[in] recallScene - the pointer to Recall Scene request
******************************************************************************/
ZCL_Status_t recallScene(ZCL_RecallScene_t *recallScene, Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

/**************************************************************************//**
\brief Removes all scenes from scene table

\param[in] group - group id

\returns status of scene removing
******************************************************************************/
ZCL_Status_t removeAllScenes(uint16_t group, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCnt);

/**************************************************************************//**
\brief Copy scene(s) in scene table

\param[in] copyScene - the pointer to Copy Scene request
\param[in] srcEp     - source endpoint
\param[in] scenePool - pointer to scene table
\param[in] sceneAttributes - pointer to scene cluster attributes

\returns status of scene storing
******************************************************************************/
ZCL_Status_t copyScene(ZCL_CopyScene_t *copyScene, Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

/**************************************************************************//**
\brief Recall the global scene
******************************************************************************/
void recallGlobalScene(Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

/**************************************************************************//**
\brief Store to global scene
******************************************************************************/
void storeGlobalScene(Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

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
  uint16_t group, uint8_t scene, uint16_t time, bool onOff, uint8_t level);

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
  uint16_t group, uint8_t scene, uint16_t time, int16_t occupiedCoolingSetPoint, int16_t occupiedHeatingSetPoint, uint8_t systemMode);

/**************************************************************************//**
\brief Sends View Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendViewScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene);

/**************************************************************************//**
\brief Sends Remove Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendRemoveScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene);

/**************************************************************************//**
\brief Sends Remove All Scenes command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void scenesSendRemoveAllScenes(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group);

/**************************************************************************//**
\brief Sends Get Scene Membership command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id
******************************************************************************/
void scenesSendGetSceneMembership(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group);

/**************************************************************************//**
\brief Sends Recall Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendRecallScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene, uint16_t time);

/**************************************************************************//**
\brief Sends Store Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendStoreScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene);


/**************************************************************************//**
\brief Fills Add Scene Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  scene   - scene id;
\param[in]  status  - the status of scene adding
******************************************************************************/
void fillAddRemoveStoreSceneResponsePayload(ZCL_AddSceneResponse_t *payload, uint16_t group, uint8_t scene, uint8_t status);

/**************************************************************************//**
\brief Fills Remove Scene Response command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
\param[in]  status  - the status of scenes removing
******************************************************************************/
void fillRemoveAllScenesResponsePayload(ZCL_RemoveAllScenesResponse_t *payload, uint16_t group, uint8_t status);

/**************************************************************************//**
\brief Fills Get Scene Membership command structure

\param[out] payload - pointer to command structure;
\param[in]  group   - group id;
******************************************************************************/
uint8_t fillGetSceneMembershipPayload(ZCL_GetSceneMembershipResponse_t *payload, Scene_t* scenePool, uint16_t group, Endpoint_t srcEp, uint8_t currSceneCnt);

/**************************************************************************//**
\brief Process Add Scene and Enhanced Add Scene command
******************************************************************************/
ZCL_Status_t processAddSceneCommand(bool enhanced, ZCL_Addressing_t *addressing,
   uint8_t payloadLength, ZCL_AddScene_t *payload, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCount);

/**************************************************************************//**
\brief Process View Scene and Enhanced View Scene command
******************************************************************************/
ZCL_Status_t processViewSceneCommand(bool enhanced, ZCL_Addressing_t *addressing,
   ZCL_ViewScene_t *payload, Endpoint_t srcEp, Scene_t* scenePool);

/**************************************************************************//**
\brief Process Remove Scene command
******************************************************************************/
ZCL_Status_t processRemoveSceneCommand(ZCL_Addressing_t *addressing,
  ZCL_RemoveScene_t *payload, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCount);

/**************************************************************************//**
\brief Process Remove Scene command
******************************************************************************/
ZCL_Status_t processRemoveAllScenesCommand(ZCL_Addressing_t *addressing,
  ZCL_RemoveAllScenes_t *payload, Endpoint_t srcEp, Scene_t* scenePool, uint8_t* currSceneCount);

/**************************************************************************//**
\brief Process Get SceneMembership command

\param[in] addressing - the pointer to Store Scene request

\returns status of processing of getSceneMembership Req
**************************************************************************/
ZCL_Status_t processGetSceneMembershipCommand(ZCL_Addressing_t *addressing,
  ZCL_GetSceneMembership_t *payload, Endpoint_t srcEp, Scene_t* scenePool, uint8_t currSceneCnt);

/**************************************************************************//**
\brief Process Store Scene command
******************************************************************************/
ZCL_Status_t processStoreSceneCommand(ZCL_Addressing_t *addressing,
  ZCL_StoreScene_t *payload, Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* sceneAttributes);

/**************************************************************************//**
\brief Process Copy Scene command
******************************************************************************/
ZCL_Status_t processCopySceneCommand(ZCL_Addressing_t *addressing,
  ZCL_CopyScene_t *payload, Endpoint_t srcEp, Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* sceneAttributes);

/**************************************************************************//**
\brief Remove all scenes associated with the group
\return returns the no. of scenes removed
******************************************************************************/
uint8_t scenesClusterRemoveByGroup(uint16_t group, Scene_t *scenePool);

/**************************************************************************//**
\brief Copy scene(s) in scene table

\param[in] copyScene - the pointer to Copy Scene request
\param[in] srcEp     - source endpoint
\param[in] scenePool - pointer to scene table
\param[in] sceneAttributes - pointer to scene cluster attributes

\returns status of scene storing
******************************************************************************/
ZCL_Status_t copyScene(ZCL_CopyScene_t *copyScene, Endpoint_t srcEp, Scene_t* scenePool,
                       ZCL_SceneClusterServerAttributes_t* scenesAttributes);

/**************************************************************************//**
\brief Copy scene(s) in scene table

\param[in] groupIdFrom - group id to copy from
\param[in] sceneIdFrom - scene id to copy from
\param[in] groupIdTo   - group id to copy to
\param[in] sceneIdTo   - scene id to copy to

\returns status of scene storing
******************************************************************************/
ZCL_Status_t copyScenesByGroup(uint16_t groupIdFrom, uint16_t sceneIdFrom,
                                      uint16_t groupIdTo, uint16_t sceneIdTo,
                                      Scene_t* scenePool, ZCL_SceneClusterServerAttributes_t* scenesAttributes);

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
  ZCL_ColorControlClusterExtensionFieldSet_t *ccExt);

/**************************************************************************//**
\brief Sends Enhanced Add Scene command to bound Thermostat device

\param[in] mode                     - address mode;
\param[in] addr                     - short address of destination node or number of group;
\param[in] ep                       - endpoint number of destination device;
\param[in] group                    - group id;
\param[in] scene                    - scene id;
\param[in] time                     - transition time;
\param[in] occupiedCoolingSetPoint  - occupied cooling setpoint;
\param[in] occupiedHeatingSetPoint  - occupied heating setpoint;
\param[in] systemMode               - System mode;
******************************************************************************/
void scenesSendEnhancedAddSceneToThermostat(APS_AddrMode_t mode, ShortAddr_t addr,
  Endpoint_t ep, Endpoint_t srcEp, uint16_t group, uint16_t scene, uint16_t time, int16_t occupiedCoolingSetPoint, int16_t occupiedHeatingSetPoint,
  uint8_t systemMode);

/**************************************************************************//**
\brief Sends Enhanced View Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] group - group id;
\param[in] scene - scene id
******************************************************************************/
void scenesSendEnhancedViewScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  uint16_t group, uint8_t scene);

/**************************************************************************//**
\brief Sends Copy Scene command to bound devices

\param[in] mode  - address mode;
\param[in] addr  - short address of destination node or number of group;
\param[in] ep    - endpoint number of destination device;
\param[in] *req  - pointer to ZCL_CopyScene_t command
******************************************************************************/
void scenesSendCopyScene(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
  SceneMode_t copyMode, uint16_t gidFrom, uint16_t sidFrom, uint16_t gidTo, uint16_t sidTo);

#endif //_SCENESCLUSTER_H