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

/*******************************************************************************
  Sensor Driver Interface Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sensor.h

  Summary:
    This file defines a simplified interface API for configuring the IMU sensor

  Description:
    None
 *******************************************************************************/

#ifndef SENSOR_H
#define	SENSOR_H

#include <stdint.h>
#include "sensor_config.h"
#if SNSR_TYPE_BMI160
    //#include "bmi160.h"
    #include "bmi160/bmi160.h"
#endif

#if SNSR_TYPE_BMI160
    #define SNSR_STATUS_OK BMI160_OK
#endif

// Buffer size in bytes for TX with IMU device
#define SNSR_COM_BUF_SIZE   128

#ifdef	__cplusplus
extern "C" {
#endif

struct sensor_device_t {
#if SNSR_TYPE_BMI160
    struct bmi160_dev device;
#endif
    volatile int status;
};

// forward declarations of functions provided elsewhere
extern uint64_t __attribute__((weak)) snsr_read_timer_ms(void);
extern uint64_t __attribute__((weak)) snsr_read_timer_us(void);
extern void __attribute__((weak)) snsr_sleep_ms(uint32_t ms);
extern void __attribute__((weak)) snsr_sleep_us(uint32_t us);

int sensor_init(struct sensor_device_t *sensor);

int sensor_set_config(struct sensor_device_t *sensor);

int sensor_read(struct sensor_device_t *sensor, snsr_data_t *ptr);

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

