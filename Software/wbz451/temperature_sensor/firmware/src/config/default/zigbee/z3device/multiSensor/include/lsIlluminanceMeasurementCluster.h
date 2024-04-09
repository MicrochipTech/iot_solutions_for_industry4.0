/*******************************************************************************
  Light-Sensor Illuminance Measurement Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
   lsIlluminanceMeasurementCluster.h

  Summary:
    This file contains Light-Sensor Illuminance Measurement Cluster.

  Description:
    This file contains Light-Sensor Illuminance Measurement Cluster.
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

#ifndef _MSILLUMINANCEMEASUREMENTCLUSTER_H
#define _MSILLUMINANCEMEASUREMENTCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclIlluminanceMeasurementCluster.h>
#include <zcl/include/zclZllGroupsCluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define ILLUMINANCE_MEASUREMENT_VAL_MIN_REPORT_PERIOD 15
#define ILLUMINANCE_MEASUREMENT_VAL_MAX_REPORT_PERIOD 90

/* Some default values for attributes */
#define APP_ILLUMINANCE_MEASUREMENT_MEASURED_VALUE_ATTRIBUTE_VALUE       0x0000
#define APP_ILLUMINANCE_MEASUREMENT_MIN_MEASURED_VALUE_ATTRIBUTE_VALUE   0x0002 //range 0x0002 ? 0xfffd
#define APP_ILLUMINANCE_MEASUREMENT_MAX_MEASURED_VALUE_ATTRIBUTE_VALUE   0xfffe //range 0x0001 ? 0xfffe
#define APP_ILLUMINANCE_MEASUREMENT_TOLERANCE_ATTRIBUTE_VALUE            0x0700 //0x0000 ? 0x0800   //Optional
#define APP_ILLUMINANCE_MEASUREMENT_LIGHT_SENSOR_TYPE_VALUE              0x7f   //0x00 ? 0xff       //Optional

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_IlluminanceMeasurementClusterServerAttributes_t lsIlluminanceMeasurementClusterServerAttributes;
extern ZCL_GroupsClusterClientAttributes_t  lsGroupsClusterClientAttributes;

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void lsDeviceInit(void);

/**************************************************************************//**
\brief Initializes illuminance Measurement cluster
******************************************************************************/
void illuminanceMeasurementClusterInit(void);

/**************************************************************************//**
\brief Update the measured Value
******************************************************************************/
 void illuminanceMeasurementUpdateMeasuredValue(void);

/**************************************************************************//**
\brief Update the tolerance value
******************************************************************************/
 void illuminanceMeasurementUpdateTolerance(void);

/**************************************************************************//**
\brief Backing up attributes
******************************************************************************/
void lsBackupLsAttributes(void);

/**************************************************************************//**
\brief Restoring attributes
******************************************************************************/
void lsRestoreLsAttributes(void);

#endif // _MSILLUMINANCEMEASUREMENTCLUSTER_H

// eof msilluminanceMeasureCluster.h
