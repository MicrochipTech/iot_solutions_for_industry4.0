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

/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <string.h>
#include "app.h"
#include "definitions.h"
#include "app_zigbee/app_zigbee.h"
#include <z3device/common/include/z3Device.h>
#include <z3device/stack_interface/zgb_api.h>
#include <z3device/stack_interface/bdb/include/bdb_api.h>
#include <osal/osal_freertos.h>


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
extern void process_UART_evt(char* cmdBuf);
extern void APP_UartInit(void);
extern void APP_UartHandler(void);
extern void process_ZB_evt(void);
extern void ZB_ZCL_CallBack(ZB_AppGenericCallbackParam_t* cb);
extern ZDO_CALLBACK_ptr ZB_ZDO_CallBack[];

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;


    appData.appQueue = xQueueCreate( 64, sizeof(APP_Msg_T) );
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
    APP_UartInit();

    APP_ZigbeeStackInit();
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    APP_Msg_T    appMsg[1];
    APP_Msg_T   *p_appMsg;
    p_appMsg=appMsg;

    ZB_AppGenericCallbackParam_t cb;
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            //appData.appQueue = xQueueCreate( 10, sizeof(APP_Msg_T) );

            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            if (OSAL_QUEUE_Receive(&appData.appQueue, &appMsg, OSAL_WAIT_FOREVER))
            {
                if (p_appMsg->msgId == APP_MSG_ZB_STACK_CB)
                {
                    // Pass Zigbee Stack Callback Event Message to User Application for handling
                    uint32_t *paramPtr = NULL;
                    memcpy(&paramPtr,p_appMsg->msgData,sizeof(paramPtr));
                    memcpy(&cb, paramPtr, sizeof(cb));
                    switch (cb.eModuleID)
                    {
                      case ZIGBEE_BDB:
                        ZB_BDB_CallBack(&cb);
                      break;

                      case ZIGBEE_ZDO:
                        ZB_ZDO_CallBack[cb.uCallBackID]((void *)cb.parameters);
                      break;

                      case ZIGBEE_ZCL:
                          ZB_ZCL_CallBack(&cb);
                      break;

                      default:
                        //appSnprintf("[APP CB]  Default case\r\n");
                      break;
                    }
                    void *ptr = NULL;
                    memcpy(&ptr, p_appMsg->msgData,sizeof(ptr));
                    OSAL_Free(ptr);
                    OSAL_Free(cb.parameters);
                    
                }
                else if(p_appMsg->msgId==APP_MSG_ZB_STACK_EVT)
                {
                    // Pass Zigbee Stack Event Message to User Application for handling
                    process_ZB_evt();
                }
                else if( p_appMsg->msgId == APP_MSG_UART_CMD_READY)
                {
                    process_UART_evt((char*)(p_appMsg->msgData));
                }
                else if( p_appMsg->msgId == APP_MSG_BDB_COMMISSIONING_EVT)
                {
                    extern void aIoT_Gateway_StartCommissioning_task(BDB_CommissioningMode_t mode);
                    
                    BDB_CommissioningMode_t cMode = p_appMsg->msgData[0];
                    aIoT_Gateway_StartCommissioning_task(cMode);
                }
                else if(p_appMsg->msgId == APP_IDLE_TASK_EVT)
                {
                    extern void app_idle_task( void );
                    app_idle_task();
                }
            }
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}


/*******************************************************************************
 End of File
 */
