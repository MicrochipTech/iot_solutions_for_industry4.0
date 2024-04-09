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
#ifndef SENSOR_CONFIG_H
#define	SENSOR_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

// *****************************************************************************
// *****************************************************************************
// Section: User configurable sensor parameters
// *****************************************************************************
// *****************************************************************************

/* IMU Sensor type defined at a project level */
#if !defined(SNSR_TYPE_BMI160) 
#define SNSR_TYPE_BMI160    1
#endif

#define SNSR_SAMPLE_RATE_UNIT_HZ    0
#define SNSR_SAMPLE_RATE_UNIT_KHZ   1

// high level sensor configuration defined in app_config header
#include "app_config.h"

#if SNSR_SAMPLE_RATE_UNIT == SNSR_SAMPLE_RATE_UNIT_HZ
#define SNSR_SAMPLE_RATE_IN_HZ SNSR_SAMPLE_RATE
#else
#define SNSR_SAMPLE_RATE_IN_HZ (SNSR_SAMPLE_RATE * 1000)
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Internal defines for sensor library
// *****************************************************************************
// *****************************************************************************

// Provide sensor specific functions
#if SNSR_TYPE_BMI160
    #define sensor_init        bmi160_sensor_init
    #define sensor_set_config  bmi160_sensor_set_config
    #define sensor_read        bmi160_sensor_read
#endif

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SENSOR_CONFIG_H */

