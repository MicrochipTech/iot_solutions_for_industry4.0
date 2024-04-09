/*******************************************************************************
 Custom Illuminance Measurement cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customIlluminanceMeasurementCluster.h

  Summary:
    This file contains the Custom Illuminance Measurement cluster interface.

  Description:
    This file contains the Custom Illuminance Measurement cluster interface.
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

#ifndef _CUSTOMILLUMINANCEMEASUREMENTCLUSTER_H
#define _CUSTOMILLUMINANCEMEASUREMENTCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclIlluminanceMeasurementCluster.h>
#include <zcl/include/zclZllGroupsCluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define ILLUMINANCE_MEASUREMENT_VAL_MIN_REPORT_PERIOD 15
#define ILLUMINANCE_MEASUREMENT_VAL_MAX_REPORT_PERIOD 30

/* Some default values for attributes */
#define APP_ILLUMINANCE_MEASUREMENT_MEASURED_VALUE_ATTRIBUTE_VALUE       0x00ff
#define APP_ILLUMINANCE_MEASUREMENT_MIN_MEASURED_VALUE_ATTRIBUTE_VALUE   0x0002 //range 0x0002 ? 0xfffd
#define APP_ILLUMINANCE_MEASUREMENT_MAX_MEASURED_VALUE_ATTRIBUTE_VALUE   0xfffe //range 0x0001 ? 0xfffe
#define APP_ILLUMINANCE_MEASUREMENT_TOLERANCE_ATTRIBUTE_VALUE            0x0700 //0x0000 ? 0x0800   //Optional
#define APP_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_VALUE              0x7f   //0x00 ? 0xff       //Optional

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_IlluminanceMeasurementClusterServerAttributes_t customIlluminanceMeasurementClusterServerAttributes;
extern ZCL_IlluminanceMeasurementClusterClientAttributes_t customIlluminanceMeasurementClusterClientAttributes;
extern ZCL_GroupsClusterClientAttributes_t  customGroupsClusterClientAttributes;

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void customDeviceInit(void);

/**************************************************************************//**
\brief Initializes illuminance Measurement cluster
******************************************************************************/
void customIlluminanceMeasurementClusterInit(void);

/**************************************************************************//**
\brief Update the measured Value
******************************************************************************/
 void illuminanceMeasurementUpdateMeasuredValue(void);

/**************************************************************************//**
\brief Update the tolerance value
******************************************************************************/
 void illuminanceMeasurementUpdateTolerance(void);

#endif // _CUSTOMILLUMINANCEMEASUREMENTCLUSTER_H

// eof customilluminanceMeasureCluster.h
