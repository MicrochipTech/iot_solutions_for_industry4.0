/*******************************************************************************
  Custom ColorControl Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customColorControlCluster.h

  Summary:
    This file contains the Custom ColorControl Cluster interface.

  Description:
    This file contains the Custom ColorControl Cluster interface.
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

#ifndef _CUSTOMCOLORCONTROLCLUSTER_H
#define _CUSTOMCOLORCONTROLCLUSTER_H

/******************************************************************************
                    Includes
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/zclZllColorControlCluster.h>
#include <z3device/common/include/z3Device.h>
#include <zcl/clusters/include/scenes.h>

/******************************************************************************
                    Defines section
******************************************************************************/
/* Same period is used for all attributes */
#define COLOR_CONTROL_CUURENT_HUE_MIN_REPORT_PERIOD 6
#define COLOR_CONTROL_CUURENT_HUE_MAX_REPORT_PERIOD 28

#define COLOR_CONTROL_CURRENT_SAT_MIN_REPORT_PERIOD 8
#define COLOR_CONTROL_CURRENT_SAT_MAX_REPORT_PERIOD 32

#define COLOR_CONTROL_CURR_X_MIN_REPORT_PERIOD 10
#define COLOR_CONTROL_CURR_X_MAX_REPORT_PERIOD 36

#define COLOR_CONTROL_CURR_Y_MIN_REPORT_PERIOD 14
#define COLOR_CONTROL_CURR_Y_MAX_REPORT_PERIOD 40

#define COLOR_CONTROL_COLOR_TEMP_MIN_REPORT_PERIOD 18
#define COLOR_CONTROL_COLOR_TEMP_MAX_REPORT_PERIOD 44

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_ColorControlClusterServerAttributes_t customColorControlClusterServerAttributes;
extern ZCL_ColorControlClusterClientAttributes_t customColorControlClusterClientAttributes;
extern PROGMEM_DECLARE(ZCL_ColorControlClusterCommands_t customColorControlClusterServerCommands);
extern PROGMEM_DECLARE(ZCL_ColorControlClusterCommands_t customColorControlClusterClientCommands);

/******************************************************************************
                    Prototypes
******************************************************************************/
void customColorControlClusterInit(void);
void colorControlClusterSetExtensionField(Scene_t *scene, uint16_t transitionTime);

/**************************************************************************//**
\brief Show identify effect.

\param[in] enhancedHue - enhanced hue to move to.
******************************************************************************/
void colorControlShowIdentifyEffect(uint16_t enhancedHue);

/**************************************************************************//**
\brief Stop showing identify effect and return to previous state.
******************************************************************************/
void colorControlStopIdentifyEffect(void);


/**************************************************************************//**
\brief Update the color temperature on level change if required

\param[in] deviceOn - The on/off status of the device
\param[in] updateColorTemp - Update coupleColorTemp bit overridden in optional fields
\param[in] level    - level the device is moving to
******************************************************************************/
void customUpdateCoupledColorTemperature(bool deviceOn, bool updateColorTemp, uint8_t level);

#endif // _CUSTOMCOLORCONTROLCLUSTER_H

// eof customColorControlCluster.h
