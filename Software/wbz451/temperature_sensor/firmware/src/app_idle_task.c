/*******************************************************************************
 System Idle Task File

  File Name:
    app_idle_task.c

  Summary:
    This file contains source code necessary for FreeRTOS idle task

  Description:

  Remarks:
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

#include "definitions.h"
static BaseType_t zigbeeTaskAbortDelayReturn;
extern TaskHandle_t zigbeeTaskHandle;
void app_idle_task( void )
{
    uint8_t PDS_Items_Pending = PDS_GetPendingItemsCount();
    bool RF_Cal_Needed = RF_NeedCal(); // device_support library API

    if (PDS_Items_Pending || RF_Cal_Needed)
    {
        if (ZB_IsIdle())
        {
            if (PDS_Items_Pending)
            {
                PDS_StoreItemTaskHandler();
            }
            else if (RF_Cal_Needed)
            {
                RF_Timer_Cal(WSS_ENABLE_ZB);
            }
        }
    }
}


/*
    Devices which do not support Sleep needs to define this function.
*/
void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime )
{
    (void) xExpectedIdleTime;    
}


/*-----------------------------------------------------------*/
/*******************************************************************************
 End of File
 */
