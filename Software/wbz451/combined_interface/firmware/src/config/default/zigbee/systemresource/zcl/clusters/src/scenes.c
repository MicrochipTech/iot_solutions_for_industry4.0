/*******************************************************************************
  Scenes Source File

  Company:
    Microchip Technology Inc.

  File Name:
    scenes.c

  Summary:
    This file contains Scenes implementation.

  Description:
    This file contains Scenes implementation.
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
#include <zcl/clusters/include/scenes.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#define DEFAULT_TRANSITION_TIME   0u

#define GLOBAL_SCENE_SCENE_ID     0x00
#define GLOBAL_SCENE_GROUP_ID     0x0000

/******************************************************************************
                    Global variables section
******************************************************************************/

/******************************************************************************
                    Implementation section
******************************************************************************/

/**************************************************************************//**
\brief Allocate free scene and mark it busy
******************************************************************************/
Scene_t *allocateScene(Scene_t* scenePool, uint8_t* currSceneCount)
{
  for (uint8_t i = 0; i < MAX_SCENES_AMOUNT; i++)
  {
    if (scenePool[i].free)
    {
      memset(&scenePool[i], 0, sizeof(Scene_t));
      scenePool[i].free = false;
      scenePool[i].transitionTime = DEFAULT_TRANSITION_TIME;
      scenePool[i].transitionTime100ms = 0;
      *currSceneCount += 1;
      return &scenePool[i];
    }
  }
  return NULL;
}

/**************************************************************************//**
\brief Mark scene table record as free
******************************************************************************/
bool freeScene(Scene_t *scene)
{
  if (GLOBAL_SCENE_GROUP_ID == scene->groupId &&
      GLOBAL_SCENE_SCENE_ID == scene->sceneId)
    return false; // Can't free global scene

  if (!scene->free)
  {
    scene->free = true;
    return true;    
  }
  return false;
}

/**************************************************************************//**
\brief Gets appropriate scene by group id and scene id

\param[in] group - group id
\param[in] scene - scene id

\returns the pointer to scene if it is found, NULL otherwise
******************************************************************************/
Scene_t *findSceneBySceneAndGroup(uint16_t group, uint8_t scene, Scene_t* scenePool)
{
  for (uint8_t i = 0; i < MAX_SCENES_AMOUNT; i++)
  {
    if ((scenePool[i].groupId == group) && (scenePool[i].sceneId == scene) && !scenePool[i].free)
      return &scenePool[i];
  }

  return NULL;
}

/**************************************************************************//**
\brief Removes all scenes associated with the given group

\param[in] group - group id

\return amount of removed scenes
******************************************************************************/
uint8_t removeScenesByGroup(uint16_t group, Scene_t* scenePool)
{
  uint8_t amount = 0;

  for (uint8_t i = 0; i < MAX_SCENES_AMOUNT; i++)
  {
    if (scenePool[i].groupId == group)
    {
      if (GLOBAL_SCENE_GROUP_ID == scenePool[i].groupId  &&
          GLOBAL_SCENE_SCENE_ID == scenePool[i].sceneId)
         continue; // Can't free global scene

      if (!scenePool[i].free)
       {
         scenePool[i].free = true;
         freeScene(&scenePool[i]);
         amount++;
       }
    }
  }

  return amount;
}


/**************************************************************************//**
\brief Gets next scene by group id

\param[in] scene - the pointer to current scene or NULL to get the first busy scene
\param[in] group - group id

\returns the pointer to scene if it is found, NULL otherwise
******************************************************************************/
Scene_t *getNextSceneByGroup(Scene_t *scene, uint16_t group, Scene_t* scenePool)
{
  if (!scene)
  {
    for (uint8_t i = 0; i < MAX_SCENES_AMOUNT; i++)
    {
      if (!scenePool[i].free && (scenePool[i].groupId == group))
        return &scenePool[i];
    }
    return NULL;
  }

  if ((scene < scenePool) || (scene > &scenePool[MAX_SCENES_AMOUNT - 1]))
    return NULL;

  for (uint8_t i = 0; i < MAX_SCENES_AMOUNT; i++)
  {
    if ((scene < &scenePool[i]) && (!scenePool[i].free) && (scenePool[i].groupId == group))
      return &scenePool[i];
  }

  return NULL;
}



// eof scenes.c

