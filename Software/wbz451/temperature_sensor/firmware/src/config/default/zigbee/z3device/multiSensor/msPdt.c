/*******************************************************************************
  Multi-Sensor Persistent Data Table Source File

  Company:
    Microchip Technology Inc.

  File Name:
    msPdt.c

  Summary:
    This file contains Multi-Sensor Persistent Data Table implementation.

  Description:
    This file contains Multi-Sensor Persistent Data Table implementation.
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_MULTI_SENSOR)

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/multiSensor/include/osOccupancySensingCluster.h>
#include <z3device/multiSensor/include/lsIlluminanceMeasurementCluster.h>
#include <z3device/multiSensor/include/tsTemperatureMeasurementCluster.h>
#include <z3device/multiSensor/include/hsHumidityMeasurementCluster.h>
#include <z3device/common/include/appConsts.h>
#include <pds/include/wlPdsMemIds.h>
/******************************************************************************
                    PDT definitions
******************************************************************************/
#ifdef _ENABLE_PERSISTENT_SERVER_
/* Occupancy Sensor application data file descriptors.
   Shall be placed in the PDS_FF code segment. */
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
PDS_DECLARE_FILE(APP_MS_OCCUPANCY_MEM_ID, sizeof(osOccupancySensingClusterServerAttributes.occupancy), &osOccupancySensingClusterServerAttributes.occupancy,  NO_FILE_MARKS);
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
PDS_DECLARE_FILE(APP_MS_ILLU_MEASURED_VALUE_MEM_ID, sizeof(lsIlluminanceMeasurementClusterServerAttributes.measuredValue), &lsIlluminanceMeasurementClusterServerAttributes.measuredValue,  NO_FILE_MARKS);
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
PDS_DECLARE_FILE(APP_MS_TEMP_MEASURED_VALUE_MEM_ID, sizeof(tsTemperatureMeasurementClusterServerAttributes.measuredValue), &tsTemperatureMeasurementClusterServerAttributes.measuredValue,  NO_FILE_MARKS);
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
PDS_DECLARE_FILE(APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID, sizeof(hsHumidityMeasurementClusterServerAttributes.measuredValue), &hsHumidityMeasurementClusterServerAttributes.measuredValue,  NO_FILE_MARKS);
#endif

/* Multi sensor application data file identifiers list.
   Will be placed in flash. */
PROGMEM_DECLARE(PDS_MemId_t appMsMemoryIdsTable[]) =
{
#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
  APP_MS_OCCUPANCY_MEM_ID,
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
  APP_MS_ILLU_MEASURED_VALUE_MEM_ID,
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
  APP_MS_TEMP_MEASURED_VALUE_MEM_ID,
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
  APP_MS_HUMIDITY_MEASURED_VALUE_MEM_ID,
#endif

};

#endif // _ENABLE_PERSISTENT_SERVER_
#endif // APP_DEVICE_TYPE_MULTI_SENSOR

// eof msPdt.c
