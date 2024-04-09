/*******************************************************************************
 Custom Level Control cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customLevelControlCluster.h

  Summary:
    This file contains the Custom Level Control cluster interface.

  Description:
    This file contains the Custom Level Control cluster interface.
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

#ifndef _CUSTOMLEVELCONTROLCLUSTER_H
#define _CUSTOMLEVELCONTROLCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/zclZllLevelControlCluster.h>

/******************************************************************************
                    Defines section
******************************************************************************/
#define UPDATE_TIMER_INTERVAL               100 // 1/10th of a second as per specification
#define MIN_CUSTOM_LEVEL                      1
#define MAX_CUSTOM_LEVEL                     254
#define MIN_TRANSITION_TIME                  1
#define DIMMABLE_CUSTOM_HUE_LEVEL            35
#define DIMMABLE_CUSTOM_SATURATION_LEVEL     35

#define LEVEL_CONTROL_VAL_MIN_REPORT_PERIOD 10
#define LEVEL_CONTROL_VAL_MAX_REPORT_PERIOD 20

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_LevelControlClusterServerAttributes_t customLevelControlClusterServerAttributes;
extern ZCL_LevelControlClusterClientAttributes_t customLevelControlClusterClientAttributes;
extern PROGMEM_DECLARE(ZCL_LevelControlClusterCommands_t         customLevelControlCommands);

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Level Control cluster
******************************************************************************/
void customLevelControlClusterInit(void);

/**************************************************************************//**
\brief Stops Level Control cluster
******************************************************************************/
void levelControlClusterStop(void);

/**************************************************************************//**
\brief Gets current color level

\returns current coloe level
******************************************************************************/
uint8_t levelControlCurrentLevel(void);


/**************************************************************************//**
\brief Set Current Level attribute to a specified value
******************************************************************************/

void setLevel(bool wOnOff, bool execIfOff, uint8_t level);

/**************************************************************************//**
\brief Display current level value.
******************************************************************************/
void levelControlDisplayLevel(uint8_t currLevel);

/**************************************************************************//**
\brief Set Extension Field Set
******************************************************************************/
void levelControlClusterSetExtensionField(uint16_t currentLevel, uint16_t transitionTime);

/**************************************************************************//**
\brief Update the current level value to startup current level value.
******************************************************************************/
void customUpdateStartupLevel(void);

#endif // _CUSTOMLEVELCONTROLCLUSTER_H

// eof customLevelControlCluster.h

