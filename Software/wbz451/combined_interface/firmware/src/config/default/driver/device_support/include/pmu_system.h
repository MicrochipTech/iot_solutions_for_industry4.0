#ifndef POWER_H
#define POWER_H

#include <xc.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/** Supported PMU Modes */
typedef enum
{
    // Linear mode - This is the default mode when CPU and peripherals are running.
    PMU_MODE_MLDO = 1,
    // Buck (DC-DC/switching) mode; supports High Power (PWM) - The most efficient mode
    //when the CPU and peripherals are running. In this mode, the SoC is powered by the DC-DC converter
    PMU_MODE_BUCK_PWM,   // 2
    // Buck (DC-DC/switching) mode; supports Low Power (PSK) mode
    PMU_MODE_BUCK_PSM   // 3
} PMU_Mode_T;
 
// *****************************************************************************
/**
*@brief This routine will set the power mode of the system.
*
*@param PMU_Mode_T  - PMU_MODE_MLDO         // 1
*                     PMU_MODE_BUCK_PWM     // 2
*                     PMU_MODE_BUCK_PSM     // 3
*
*@retval uint8_t      0 is success
*                     1 is fail which means no BDADDR IB
*/  
uint8_t PMU_Set_Mode(PMU_Mode_T mode);

// *****************************************************************************
/**
*@brief This routine will get the power mode of the system.
*
*@param None
*
*@retval PMU_Mode_T - PMU_MODE_MLDO         // 1
*                     PMU_MODE_BUCK_PWM     // 2
*                     PMU_MODE_BUCK_PSM     // 3
*/  
PMU_Mode_T PMU_Get_Mode(void);

// *****************************************************************************
/**
*@brief This routine will configure the BUCK current sensor.
*       It only can be configured when the power mode is set as PMU_MODE_BUCK_PSM.
*       Disable current sensor can improve the current consumption of sleep mode.
*
*@param bool          Enable/Disable BUCK current sensor
*                     false: Disable
*                     true : Enable
*
*@retval bool -       true is success
*                     false is fail due to power mode is not in PMU_MODE_BUCK_PSM
*/  
bool PMU_ConfigCurrentSensor(bool enable);


#ifdef __cplusplus
}
#endif

#endif /* POWER_H_INCLUDED */
