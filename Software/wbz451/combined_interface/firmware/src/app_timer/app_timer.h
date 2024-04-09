/*******************************************************************************
  Application Timer Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_timer.h

  Summary:
    This file contains the Application Timer functions for this project.

  Description:
    This file contains the Application Timer functions for this project.
    Including the Set/Stop/Reset timer and timer expired handler.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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


#ifndef APP_TIMER_H
#define APP_TIMER_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include <stdbool.h>

#include "../app.h"




// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************

/**@brief The definition of Timer ID. */
typedef enum APP_TIMER_TimerId_T
{
    APP_TIMER_ID_0,
    APP_TIMER_ID_1,
    APP_TIMER_ID_2,
    APP_TIMER_ID_3,
    APP_TIMER_ID_4,
    APP_TIMER_ID_5,
    APP_TIMER_TOTAL,
} APP_TIMER_TimerId_T;

/**@defgroup APP_TIMER_TIMEOUT APP_TIMER_TIMEOUT
 * @brief The definition of the timeout value.
 * @{ */
#define APP_TIMER_10MS                                 0x0A     /**< 10ms timer. */
#define APP_TIMER_12MS                                 0x0C     /**< 12ms timer. */
#define APP_TIMER_18MS                                 0x12     /**< 18ms timer. */
#define APP_TIMER_30MS                                 0x1E     /**< 30ms timer. */
#define APP_TIMER_50MS                                 0x32     /**< 50ms timer. */
#define APP_TIMER_100MS                                0x64     /**< 100ms timer. */
#define APP_TIMER_500MS                                0x1F4    /**< 500ms timer. */
#define APP_TIMER_1S                                   0x3E8    /**< 1s timer. */
#define APP_TIMER_2S                                   0x7D0    /**< 2s timer. */
#define APP_TIMER_3S                                   0xBB8    /**< 3s timer. */
#define APP_TIMER_5S                                   0x1388   /**< 5s timer. */
#define APP_TIMER_30S                                  0x7530   /**< 30s timer. */
/** @} */


// *****************************************************************************
// *****************************************************************************
// Section: Function Prototypes
// *****************************************************************************
// *****************************************************************************

/**@brief The function is used to check if a timer exists already.
 *@param[in] timerId                          Timer ID. See @ref APP_TIMER_TimerId_T.
 *
 * @retval true                               This timer exites alread.
 * @retval false                              This timer doesn't exist.
 *
 */
bool APP_TIMER_IsTimerExisted(uint8_t timerId);

/**@brief The function is used to set and start a timer.
 *@param[in] timerId                          Timer ID. See @ref APP_TIMER_TimerId_T.
 *@param[in] timeout                          Timeout value (unit: ms)
 *@param[in] isPeriodicTimer                  Set as true to let the timer expire repeatedly with a frequency set by the timeout parameter. \n
 *                                            Set as false to let the timer be a one-shot timer.
 *
 * @retval APP_RES_SUCCESS                    Set and start a timer successfully.
 * @retval APP_RES_FAIL                       Failed to start the timer.
 * @retval APP_RES_OOM                        No available memory.
 * @retval APP_RES_NO_RESOURCE                Failed to create a new timer.
 *
 */
uint16_t APP_TIMER_SetTimer(uint8_t timerId, uint32_t timeout, bool isPeriodicTimer);

/**@brief The function is used to stop a timer.
 *@param[in] timerId                          Timer ID. See @ref APP_TIMER_TimerId_T.
 *
 * @retval APP_RES_SUCCESS                    Stop a timer successfully.
 * @retval APP_RES_FAIL                       Failed to stop the timer.
 * @retval APP_RES_INVALID_PARA               The timerId doesn't exist.
 *
 */
uint16_t APP_TIMER_StopTimer(uint8_t timerId);

/**@brief The function is used to re-start a timer. Not available if the timer is one-shot and it has been expired.
 *@param[in] timerId                          Timer ID. See @ref APP_TIMER_TimerId_T.
 *
 * @retval APP_RES_SUCCESS                    Reset a timer successfully.
 * @retval APP_RES_FAIL                       Failed to reset the timer.
 * @retval APP_RES_INVALID_PARA               The timerId doesn't exist.
 *
 */
uint16_t APP_TIMER_ResetTimer(uint8_t timerId);

#endif
