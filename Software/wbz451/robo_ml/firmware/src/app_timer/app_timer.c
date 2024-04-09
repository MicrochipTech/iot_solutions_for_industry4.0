/*******************************************************************************
  Application Timer Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_timer.c

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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <string.h>
#include "app_timer.h"
#include "app_error_defs.h"
#include "FreeRTOS.h"
#include "timers.h"


// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Local Variables
// *****************************************************************************
// *****************************************************************************
static TimerHandle_t s_timerHandler[configTIMER_QUEUE_LENGTH]; // = {NULL};


void vApplicationDaemonTaskStartupHook( void )
{
    
}

// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
static void APP_TIMER_OneShotTimerExpiredHandle(TimerHandle_t xTimer)
{
    uint8_t *timerId;
    uint8_t timerIdTemp;
    APP_Msg_T appMsg;
    uint16_t msgWaitTime = 0;

    timerId = (uint8_t *)pvTimerGetTimerID(xTimer);
    timerIdTemp = *timerId;


    //Delete the timer first to avoid an issue: Start the timer with the same timer ID in this handler, 
    //If we put the delete timer in the last of this handler, then the new started timer with the same timer ID will be delete immediately.
    xTimerDelete(s_timerHandler[*timerId], 0);
    s_timerHandler[*timerId] = NULL;

    //Free timer ID due to one shot timer is expired
    OSAL_Free(timerId);

    switch (timerIdTemp)
    {
        case APP_TIMER_ID_0:
        {
            //appMsg.msgId = APP_TIMER_ID_0_MSG;
        }
        break;   
        
        case APP_TIMER_ID_1:
        {
           //appMsg.msgId = APP_TIMER_ID_1_MSG;
        }
        break;
        case APP_TIMER_ID_2:
        {
           //appMsg.msgId = APP_TIMER_ID_2_MSG;
        }
        break;
        case APP_TIMER_ID_3:
        {
           //appMsg.msgId = APP_TIMER_ID_3_MSG;
        }
        break;
        case APP_TIMER_ID_4:
        {
           //appMsg.msgId = APP_TIMER_ID_4_MSG;
        }
        break;
        case APP_TIMER_ID_5:
        {
           //appMsg.msgId = APP_TIMER_ID_5_MSG;
        }
        break;	

        default:
            break;
    }

    OSAL_QUEUE_Send(&appData.appQueue, &appMsg, msgWaitTime);
}

static void APP_TIMER_PeriodicTimerExpiredHandle(TimerHandle_t xTimer)
{
    uint8_t *timerId;
    APP_Msg_T appMsg;

    timerId = (uint8_t *)pvTimerGetTimerID(xTimer);

    switch (*timerId)
    {
        case APP_TIMER_ID_0:
        {
            //appMsg.msgId = APP_TIMER_ID_0_MSG;
        }
        break;   
        
        case APP_TIMER_ID_1:
        {
           //appMsg.msgId = APP_TIMER_ID_1_MSG;
        }
        break;
        case APP_TIMER_ID_2:
        {
           //appMsg.msgId = APP_TIMER_ID_2_MSG;
        }
        break;
        case APP_TIMER_ID_3:
        {
           //appMsg.msgId = APP_TIMER_ID_3_MSG;
        }
        break;
        case APP_TIMER_ID_4:
        {
           //appMsg.msgId = APP_TIMER_ID_4_MSG;
        }
        break;
        case APP_TIMER_ID_5:
        {
           //appMsg.msgId = APP_TIMER_ID_5_MSG;
        }
        break;
        default:
            break;
    }

    OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
    //No need to free timer ID due to it's periodic timer
}

bool APP_TIMER_IsTimerExisted(uint8_t timerId)
{
    return (s_timerHandler[timerId] == NULL) ? false:true;
}

uint16_t APP_TIMER_SetTimer(uint8_t timerId, uint32_t timeout, bool isPeriodicTimer)
{
    char timerName[] = "APP_Timer0";
    uint8_t nameLen;
    uint8_t *p_timerId;

    if (s_timerHandler[timerId])
    {
        uint8_t *existedTimerId;
        
        existedTimerId = (uint8_t *)pvTimerGetTimerID(s_timerHandler[timerId]);

        xTimerStop(s_timerHandler[timerId], 0);
        xTimerDelete(s_timerHandler[timerId], 0);
        s_timerHandler[timerId] = NULL;

        p_timerId = existedTimerId;                 //Reuse the timer ID, no need to allocate again
    }
    else
    {
        p_timerId = OSAL_Malloc(sizeof(timerId));

        if (p_timerId == NULL)
        {
            return APP_RES_OOM;
        }

        *p_timerId = timerId;
    }

    nameLen = sizeof(timerName) / sizeof(char) - 1;   //-1 means the end character
    timerName[nameLen - 1] = '0' + timerId;           //switch to ASCII

    if (isPeriodicTimer)
    {
        s_timerHandler[timerId] = xTimerCreate(timerName, (timeout / portTICK_PERIOD_MS), pdTRUE, (void *)p_timerId, APP_TIMER_PeriodicTimerExpiredHandle);
    }
    else
    {
        s_timerHandler[timerId] = xTimerCreate(timerName, (timeout / portTICK_PERIOD_MS), pdFALSE, (void *)p_timerId, APP_TIMER_OneShotTimerExpiredHandle);
    }

    if (s_timerHandler[timerId])
    {
        if (pdFAIL == xTimerStart(s_timerHandler[timerId], 0))
        {
            OSAL_Free(p_timerId);
            return APP_RES_FAIL;
        }
        return APP_RES_SUCCESS;
    }

    //The timer is not created successfully
    OSAL_Free(p_timerId);
    s_timerHandler[timerId] = NULL;

    return APP_RES_NO_RESOURCE;
}

uint16_t APP_TIMER_StopTimer(uint8_t timerId)
{
    if (s_timerHandler[timerId] == NULL)
    {
        return APP_RES_INVALID_PARA;
    }

    if (xTimerStop(s_timerHandler[timerId], 0) != pdPASS)
    {
        return APP_RES_FAIL;
    }

    return APP_RES_SUCCESS;
}

uint16_t APP_TIMER_ResetTimer(uint8_t timerId)
{
    if (s_timerHandler[timerId] == NULL)
    {
        return APP_RES_INVALID_PARA;
    }

    if (xTimerReset(s_timerHandler[timerId], 0) != pdPASS)
    {
        return APP_RES_FAIL;
    }

    return APP_RES_SUCCESS;
}
