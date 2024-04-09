/*******************************************************************************
 Custom Temperature Measurement Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customTemperatureMeasurementCluster.h

  Summary:
    This file contains the Custom Temperature Measurement cluster interface.

  Description:
    This file contains the Custom Temperature Measurement cluster interface.
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
#ifndef _CUSTOMTEMPERATUREMEASUREMENTCLUSTER_H
#define _CUSTOMTEMPERATUREMEASUREMENTCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclTemperatureMeasurementCluster.h>
#include <zcl/include/zclZllGroupsCluster.h>


/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define TEMPERATURE_MEASUREMENT_VAL_MIN_REPORT_PERIOD 5
#define TEMPERATURE_MEASUREMENT_VAL_MAX_REPORT_PERIOD 15

/* Some default values for attributes */
#define APP_TEMPERATURE_MEASUREMENT_MEASURED_VALUE_ATTRIBUTE_VALUE       0x5000
#define APP_TEMPERATURE_MEASUREMENT_MIN_MEASURED_VALUE_ATTRIBUTE_VALUE   0x954d //range 0x954d � 0x7ffe
#define APP_TEMPERATURE_MEASUREMENT_MAX_MEASURED_VALUE_ATTRIBUTE_VALUE   0x7fff //range 0x954e � 0x7fff
#define APP_TEMPERATURE_MEASUREMENT_TOLERANCE_ATTRIBUTE_VALUE            0x0100 //0x0000 � 0x0800

#define APP_TEMPERATURE_MEASUREMENT_MEASURED_VALUE_PERIODIC_CHANGE       1000 //corresponding to 10 degree celsius
/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_TemperatureMeasurementClusterServerAttributes_t customTemperatureMeasurementClusterServerAttributes;
extern ZCL_TemperatureMeasurementClusterClientAttributes_t customTemperatureMeasurementClusterClientAttributes;
extern ZCL_GroupsClusterClientAttributes_t  customGroupsClusterClientAttributes;

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Device initialization routine
******************************************************************************/
void customDeviceInit(void);

/**************************************************************************//**
\brief Initializes Temperature Measurement cluster
******************************************************************************/
void customTemperatureMeasurementClusterInit(void);

/**************************************************************************//**
\brief Update the measured Value
******************************************************************************/
void customTempeartureMeasurementUpdateMeasuredValue(void);

#endif // _CUSTOMTEMPERATUREMEASUREMENTCLUSTER_H

// eof tsTemperatureMeasurementCluster.h
