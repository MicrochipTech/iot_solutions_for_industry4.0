/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

// This is a guard condition so that contents of this file are not included
// more than once.
#ifndef APP_CONFIG_H
#define	APP_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include "sensor_config.h"
#include "definitions.h"
#include "user.h"

// *****************************************************************************
// *****************************************************************************
// Section: User configurable application level parameters
// *****************************************************************************
// *****************************************************************************

// IMU sampling rate in units of SNSR_SAMPLE_RATE_UNIT
// For BMI160:
//  - set SNSR_SAMPLE_RATE_UNIT to SNSR_SAMPLE_RATE_UNIT_HZ
//  - set SNSR_SAMPLE_RATE to one of: 25, 50, 100, 200, 400, 800, 1600
// For ICM42688 < 1kHz range:
//  - set SNSR_SAMPLE_RATE_UNIT to SNSR_SAMPLE_RATE_UNIT_HZ
//  - set SNSR_SAMPLE_RATE to one of: 25, 50, 100, 200, 500
// For ICM42688 >= 1kHz range:
//  - set SNSR_SAMPLE_RATE_UNIT to SNSR_SAMPLE_RATE_UNIT_KHZ
//  - set SNSR_SAMPLE_RATE to one of: 1, 2, 4, 8, 16
// !NB! Increasing the sample rate above 500Hz (this may be lower for non MDV formats)
// with all 6 axes may cause buffer overruns
//  - Change at your own risk!
#define SNSR_SAMPLE_RATE        25
#define SNSR_SAMPLE_RATE_UNIT   SNSR_SAMPLE_RATE_UNIT_HZ // HZ or KHZ

// Accelerometer range in Gs
// Either sensor supports one of: 2, 4, 8, 16
#define SNSR_ACCEL_RANGE        2

// Gyro range in DPS
// For ICM42688 use one of: 16, 31, 62, 125, 250, 500, 1000, 2000
// For BMI160 use one of: 125, 250, 500, 1000, 2000
#define SNSR_GYRO_RANGE         2000

// Define which axes from the IMU to use
#define SNSR_USE_ACCEL_X        true
#define SNSR_USE_ACCEL_Y        true
#define SNSR_USE_ACCEL_Z        true
#define SNSR_USE_GYRO_X         true	
#define SNSR_USE_GYRO_Y         true	
#define SNSR_USE_GYRO_Z         true	

// Size of sensor buffer in samples (must be power of 2)
#define SNSR_BUF_LEN            128

// Type used to store and stream sensor samples
#define SNSR_DATA_TYPE          int16_t

// Frame header byte for MPLAB DV
#define MDV_START_OF_FRAME      0xA5U
#define MDV_END_OF_FRAME      0x5AU

#define SNSR_SAMPLES_PER_PACKET 1


// LED tick rate periods in ms
#define TICK_RATE_FAST          100
#define TICK_RATE_SLOW          500

// *****************************************************************************
// *****************************************************************************
// Section: Defines derived from user config parameters
// *****************************************************************************
// *****************************************************************************
#define SNSR_NUM_AXES   (SNSR_USE_ACCEL_X + SNSR_USE_ACCEL_Y + SNSR_USE_ACCEL_Z \
                            + SNSR_USE_GYRO_X + SNSR_USE_GYRO_Y + SNSR_USE_GYRO_Z + 2)

/* Define whether multiple sensors types are being used */
#define SNSR_USE_GYRO   (SNSR_USE_GYRO_X || SNSR_USE_GYRO_Y || SNSR_USE_GYRO_Z)
#define SNSR_USE_ACCEL  (SNSR_USE_ACCEL_X || SNSR_USE_ACCEL_Y || SNSR_USE_ACCEL_Z)
#if (SNSR_USE_ACCEL && SNSR_USE_GYRO)
    #define MULTI_SENSOR 1
#else
    #define MULTI_SENSOR 0
#endif

// The way the buffering works the following condition must be enforced
#if (SNSR_BUF_LEN % SNSR_SAMPLES_PER_PACKET) > 0
#error "SNSR_SAMPLES_PER_PACKET must be a factor of SNSR_BUF_LEN"
#endif


#ifdef SNSR_TYPE_BMI160
#define SNSR_NAME "bmi160"
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Platform generic macros for portability
// *****************************************************************************
// *****************************************************************************
#define __nullop__()        do {} while (0)

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

typedef SNSR_DATA_TYPE snsr_data_t;
typedef SNSR_DATA_TYPE snsr_dataframe_t[SNSR_NUM_AXES];
typedef SNSR_DATA_TYPE snsr_datapacket_t[SNSR_NUM_AXES*SNSR_SAMPLES_PER_PACKET];

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* APP_CONFIG_H */
