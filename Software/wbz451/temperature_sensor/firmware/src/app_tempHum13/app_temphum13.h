/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zigbee_app_header.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
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

#ifndef __APP_TEMPHUM13_H__
#define __APP_TEMPHUM13_H__

//#include "drv_digital_out.h"
//#include "drv_digital_in.h"
//#include "drv_i2c_master.h"
#include <xc.h>
#include <stdint.h>


// -------------------------------------------------------------- PUBLIC MACROS 
/**
 * \defgroup macros Macros
 * \{
 */

/**
 * \defgroup map_mikrobus MikroBUS
 * \{
 */
#define TEMPHUM13_MAP_MIKROBUS( cfg, mikrobus ) \
  cfg.scl  = MIKROBUS( mikrobus, MIKROBUS_SCL ); \
  cfg.sda  = MIKROBUS( mikrobus, MIKROBUS_SDA )
/** \} */

/**
 * \defgroup error_code Error Code
 * \{
 */
#define  TEMPHUM13_RETVAL  uint8_t

#define  TEMPHUM13_OK                         0x00
#define  TEMPHUM13_INIT_ERROR                 0xFF
/** \} */

/**
 * \defgroup slave_addr Slave Address
 * \{
 */
#define  TEMPHUM13_DEVICE_ADDRESS             0x40
/** \} */

/**
 * \defgroup commands Commands
 * \{
 */
#define  TEMPHUM13_CMD_TRIG_TEMP_MEAS_HOLD    0xE3
#define  TEMPHUM13_CMD_TRIG_HUMI_MEAS_HOLD    0xE5
#define  TEMPHUM13_CMD_TRIG_TEMP_MEAS_NOHOLD  0xF3
#define  TEMPHUM13_CMD_TRIG_HUMI_MEAS_NOHOLD  0xF5
#define  TEMPHUM13_CMD_WRITE_USER_REG         0xE6
#define  TEMPHUM13_CMD_READ_USER_REG          0xE7
#define  TEMPHUM13_CMD_SOFT_RESET             0xFE
/** \} */


/**
 * \defgroup heater_switch Heater Switch
 * \{
 */
#define  TEMPHUM13_HEATER_ENABLE              0x01
#define  TEMPHUM13_HEATER_DISABLE             0x00
/** \} */

/**
 * \defgroup resolution Resolution
 * \{
 */
#define  TEMPHUM13_RESOLUTION_8               0x01
#define  TEMPHUM13_RESOLUTION_10              0x80
#define  TEMPHUM13_RESOLUTION_11              0x81
#define  TEMPHUM13_RESOLUTION_12              0x00
/** \} */

/**
 * \defgroup otp OTP
 * \{
 */
#define  TEMPHUM13_OTP_DISABLE                0x01
#define  TEMPHUM13_OTP_ENABLE                 0x00
/** \} */


/** \} */ // End group macro 
 
#ifdef __cplusplus
extern "C"{
#endif


extern void APP_temphum13_reset ( void );
extern uint16_t APP_temphum13_get_temperature ( void );
#ifdef __cplusplus
}
#endif
#endif  // __APP_TEMPHUM13_H__

/** \} */ // End public_function group
/// \}    // End click Driver group  
/*! @} */
// ------------------------------------------------------------------------- END
