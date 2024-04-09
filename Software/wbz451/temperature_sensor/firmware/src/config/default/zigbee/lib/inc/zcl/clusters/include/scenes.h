/*******************************************************************************
  Dimmable Light Scenes Header File

  Company:
    Microchip Technology Inc.

  File Name:
    scenes.h

  Summary:
    Dimmable Light Scenes interface.

  Description:
    This file contains Dimmable Light Scenes interface.
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


#ifndef _SCENES_H
#define _SCENES_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zcl/include/zclZllColorControlCluster.h>
/******************************************************************************
                    Definition(s) section
******************************************************************************/
#ifndef MAX_SCENES_AMOUNT
#define MAX_SCENES_AMOUNT 10
#endif
/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  bool      free;
  uint8_t   sceneId;
  uint16_t  groupId;
  uint16_t  transitionTime;
  uint8_t   transitionTime100ms;

  // On/Off Cluster
  bool      onOff;
#if APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_ON_OFF_LIGHT
  // Level Control Cluster
  uint8_t   currentLevel;
#endif // APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_ON_OFF_LIGHT
#if APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_COLOR_LIGHT
  // Color Control Cluster
  ZCL_ZllEnhancedColorMode_t colorMode;
  uint16_t  currentX;           /* CC scenes attr #1 */
  uint16_t  currentY;           /* CC scenes attr #2 */
  uint16_t  enhancedCurrentHue; /* CC scenes attr #3 */
  uint8_t   currentSaturation;  /* CC scenes attr #4 */
  uint8_t   colorLoopActive;    /* CC scenes attr #5 */
  uint8_t   colorLoopDirection; /* CC scenes attr #6 */
  uint16_t  colorLoopTime;      /* CC scenes attr #7 */
  uint16_t  colorTemperature;   /* CC scenes attr #8 */
#endif // APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_COLOR_LIGHT
   /* Scenes Extensions for thermostat */
#if APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_THERMOSTAT
  int16_t   occupiedCoolingSetpoint;
  int16_t   occupiedHeatingSetpoint;
  uint8_t   systemMode;
#endif
} Scene_t;

/******************************************************************************
                    External variables section
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Allocates scene

\returns the pointer to allocated scene if allocation is successful,
  NULL otherwise
******************************************************************************/
Scene_t *allocateScene(Scene_t* scenePool, uint8_t* currSceneCount);

/**************************************************************************//**
\brief Frees scene

\param[in] scene - the pointer to the scene to be freed
******************************************************************************/
bool freeScene(Scene_t *scene);

/**************************************************************************//**
\brief Gets appropriate scene by group id and scene id

\param[in] group - group id
\param[in] scene - scene id

\returns the pointer to scene if it is found, NULL otherwise
******************************************************************************/
Scene_t *findSceneBySceneAndGroup(uint16_t group, uint8_t scene, Scene_t* scenePool);

/**************************************************************************//**
\brief Removes all scenes associated with the given group

\param[in] group - group id

\return amount of removed groups
******************************************************************************/
uint8_t removeScenesByGroup(uint16_t group, Scene_t* scenePool);

/**************************************************************************//**
\brief Gets next scene by group id

\param[in] scene - the pointer to current scene or NULL to get the first busy scene
\param[in] group - group id

\returns the pointer to scene if it is found, NULL otherwise
******************************************************************************/
Scene_t *getNextSceneByGroup(Scene_t *scene, uint16_t group, Scene_t* scenePool);

#endif // _SCENES_H

// eof scenes.h
