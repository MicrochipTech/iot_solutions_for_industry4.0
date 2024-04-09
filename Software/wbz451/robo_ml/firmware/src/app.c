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
#include <stdio.h>
#include "app.h"
#include "definitions.h"

#include "app_ml.h"
#include "sensor.h"
#include "ringbuffer.h"
#include "app_config.h"
#include "app_user.h"
#include "app_zigbee/app_zigbee.h"
#include <z3device/common/include/z3Device.h>
#include <z3device/stack_interface/zgb_api.h>
#include <z3device/stack_interface/bdb/include/bdb_api.h>
//#include "FreeRTOS.h"
#include <osal/osal_freertos.h>

#include <zcl/include/zclArmorientationcluster0Cluster.h>

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

#define   ACC_ML_INPUT_BUFFER_SIZE  6

//extern void process_UART_evt(char* cmdBuf);
//extern void APP_UartInit(void);
//extern void APP_UartHandler(void);
//extern void process_ZB_evt(void);

extern void ZB_ZCL_CallBack(ZB_AppGenericCallbackParam_t* cb);
extern ZDO_CALLBACK_ptr ZB_ZDO_CallBack[];

APP_DATA appData;
uint16_t conn_hdl = 0xFFFF;

static struct sensor_device_t sensor;
static snsr_data_t _snsr_buffer_data[SNSR_BUF_LEN][SNSR_NUM_AXES];
static ringbuffer_t snsr_buffer;
static volatile bool snsr_buffer_overrun = false;

int8_t accData[ACC_ML_INPUT_BUFFER_SIZE];
int16_t accDataBuffer[ACC_ML_INPUT_BUFFER_SIZE];
int16_t accIndex=0;

extern const char* labels[];


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
static void SNSR_ISR_HANDLER() 
{
    
    APP_Msg_T appMsg_BMI160_EINT;
    appMsg_BMI160_EINT.msgId = APP_MSG_BMI160_SENSOR_INT;

    OSAL_QUEUE_SendISR(&appData.appQueue, &appMsg_BMI160_EINT);

}

void Null_Handler() {
    // Do nothing
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


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
    int8_t app_failed = 0;

    ZB_AppGenericCallbackParam_t cb;
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            //appData.appQueue = xQueueCreate( 10, sizeof(APP_Msg_T) );
//            printf("[BLE] Started Advertising!!!\r\n");
            MIKRO_INT_CallbackRegister(Null_Handler);
            MIKRO_INT_Disable();
            
            /* Initialize the sensor data buffer */
            if (ringbuffer_init(&snsr_buffer, _snsr_buffer_data, sizeof(_snsr_buffer_data) / sizeof(_snsr_buffer_data[0]), sizeof(_snsr_buffer_data[0])))
            {        
                app_failed = 1;
            }

            /* Init and configure sensor */
            if (sensor_init(&sensor) != SNSR_STATUS_OK) {
                printf("ERROR: sensor init result = %d\n\r", sensor.status);
                app_failed = 1;
            }

            if (sensor_set_config(&sensor) != SNSR_STATUS_OK) {
                printf("ERROR: sensor configuration result = %d\n\r", sensor.status);
                app_failed = 1;
            }

            printf("sensor type is %s\n\r", SNSR_NAME);
            printf("sensor sample rate set at %dHz\n\r", SNSR_SAMPLE_RATE);
            
            #if SNSR_USE_ACCEL
                printf("Accelerometer axes %s%s%s enabled with range set at +/-%dGs\n\r", SNSR_USE_ACCEL_X ? "x" : "", SNSR_USE_ACCEL_Y ? "y" : "", SNSR_USE_ACCEL_Z ? "z" : "", SNSR_ACCEL_RANGE);
            #else
                printf("Accelerometer disabled\n\r");
            #endif

            #if SNSR_USE_GYRO
                printf("Gyrometer axes %s%s%s enabled with range set at %dDPS\n\r", SNSR_USE_GYRO_X ? "x" : "", SNSR_USE_GYRO_Y ? "y" : "", SNSR_USE_GYRO_Z ? "z" : "", SNSR_GYRO_RANGE);
            #else
                printf("Gyrometer disabled\n\r");
            #endif

            
            MIKRO_INT_Enable();
            vTaskDelay(pdMS_TO_TICKS(20)+1);
            MIKRO_INT_CallbackRegister(SNSR_ISR_HANDLER);
            tflite_setup();
            
            if (appInitialized && !app_failed)
            {
                appData.state = APP_STATE_SERVICE_TASKS;
                p_appMsg->msgId = APP_MSG_BMI160_SENSOR_READ;
                OSAL_QUEUE_Send(&appData.appQueue, p_appMsg, 0);
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            if (OSAL_QUEUE_Receive(&appData.appQueue, &appMsg, OSAL_WAIT_FOREVER))  //OSAL_WAIT_FOREVER
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
////                else if(p_appMsg->msgId==APP_MSG_BLE_STACK_EVT)
////                {
////                    // Pass BLE Stack Event Message to User Application for handling
////                    APP_BleStackEvtHandler((STACK_Event_T *)p_appMsg->msgData);
////                }
////                else if(p_appMsg->msgId==APP_MSG_BLE_STACK_LOG)
////                {
////                    // Pass BLE LOG Event Message to User Application for handling
////                    APP_BleStackLogHandler((BT_SYS_LogEvent_T *)p_appMsg->msgData);
////                }
                else if( p_appMsg->msgId == APP_MSG_UART_CMD_READY)
                {
                    process_UART_evt((char*)(p_appMsg->msgData));
                }
                else if(p_appMsg->msgId==APP_MSG_BMI160_SENSOR_INT)
                {
//                    sensor_data_read();
                        /* Check if any errors we've flagged have been acknowledged */
                        if ((sensor.status != SNSR_STATUS_OK) || snsr_buffer_overrun)
                            return;

                        ringbuffer_size_t wrcnt;
                        snsr_data_t *ptr = ringbuffer_get_write_buffer(&snsr_buffer, &wrcnt);

                        if (wrcnt == 0)
                            snsr_buffer_overrun = true;
                        else if ((sensor.status = sensor_read(&sensor, ptr)) == SNSR_STATUS_OK)
                            ringbuffer_advance_write_index(&snsr_buffer, 1);
                }
                else if(p_appMsg->msgId == APP_IDLE_TASK_EVT)
                {
                    extern void app_idle_task( void );
                    app_idle_task();
                }
                else if(p_appMsg->msgId==APP_MSG_BMI160_SENSOR_READ)
                {
                    if (sensor.status != SNSR_STATUS_OK)
                    {
                        printf("ERROR: Got a bad sensor status: %d\n", sensor.status);
//                        break;
                    }
                    else if (snsr_buffer_overrun == true)
                    {
                        printf("\n\n\nOverrun!\n\n\n");
                        MIKRO_INT_CallbackRegister(Null_Handler);
                        ringbuffer_reset(&snsr_buffer);
                        snsr_buffer_overrun = false;
                        MIKRO_INT_CallbackRegister(SNSR_ISR_HANDLER);
                    }
                    else if(ringbuffer_get_read_items(&snsr_buffer) >= SNSR_SAMPLES_PER_PACKET)
                    {
                        ringbuffer_size_t rdcnt;
                        SNSR_DATA_TYPE const *ptr = ringbuffer_get_read_buffer(&snsr_buffer, &rdcnt);
                        while (rdcnt >= SNSR_SAMPLES_PER_PACKET) 
                        {
                            snsr_data_t const *scalarptr = (snsr_data_t const *) ptr;
                            int x = (*scalarptr++)>>8;
                            int y = (*scalarptr++)>>8;
                            int z = (*scalarptr++)>>8;
                            int gx = (*scalarptr++)>>8; 
                            int gy = (*scalarptr++)>>8;
                            int gz = (*scalarptr++)>>8;

#ifdef  TRAINING_MODE_ENABLED                            
//                            printf("%d,%d,%d,%d,%d,%d\r\n", x,y,z,gx,gy,gz);
//                            uint8_t headerbyte = MDV_START_OF_FRAME;
//                            int8_t tempBuff[SNSR_NUM_AXES];
//                            tempBuff[0] = MDV_START_OF_FRAME;
//                            tempBuff[1] = x;
//                            tempBuff[2] = y;
//                            tempBuff[3] = z;
//                            tempBuff[4] = gx;
//                            tempBuff[5] = gy;
//                            tempBuff[6] = gz;
//                            tempBuff[7] = MDV_END_OF_FRAME;
//                            SERCOM0_USART_Write(tempBuff, sizeof(tempBuff));
                            
#endif
                            rdcnt -= SNSR_SAMPLES_PER_PACKET;
                            ringbuffer_advance_read_index(&snsr_buffer, SNSR_SAMPLES_PER_PACKET);
                                                        
                            accDataBuffer[0] += x;
                            accDataBuffer[1] += y;
                            accDataBuffer[2] += z;
                            accDataBuffer[3] += gx;
                            accDataBuffer[4] += gy;
                            accDataBuffer[5] += gz;

                            accIndex++;

                            if (accIndex >= 16) 
                            {
                                accData[0] = accDataBuffer[0]>>4;
                                accData[1] = accDataBuffer[1]>>4;
                                accData[2] = accDataBuffer[2]>>4;
                                accData[3] = accDataBuffer[3]>>4;
                                accData[4] = accDataBuffer[4]>>4;
                                accData[5] = accDataBuffer[5]>>4;
                                accIndex=0;
                                p_appMsg->msgId = APP_MSG_PROCESS_TFL;
                                OSAL_QUEUE_Send(&appData.appQueue, p_appMsg, 0);
                                memset(accDataBuffer, 0, sizeof(accDataBuffer));
                            }
                        }
                    }
                    p_appMsg->msgId = APP_MSG_BMI160_SENSOR_READ;
                    OSAL_QUEUE_Send(&appData.appQueue, p_appMsg, 0);
                }
                else if(p_appMsg->msgId==APP_MSG_PROCESS_TFL)
                {
//                    int8_t tempBuff[SNSR_NUM_AXES];
//                    tempBuff[0] = MDV_START_OF_FRAME;
//                    tempBuff[1] = accData[0];
//                    tempBuff[2] = accData[1];
//                    tempBuff[3] = accData[2];
//                    tempBuff[4] = accData[3];
//                    tempBuff[5] = accData[4];
//                    tempBuff[6] = accData[5];
//                    tempBuff[7] = MDV_END_OF_FRAME;
//                    SERCOM0_USART_Write(tempBuff, sizeof(tempBuff));
//#ifndef  TRAINING_MODE_ENABLED 
                        tflite_runInference();
//#endif
                }
                else if(p_appMsg->msgId==APP_MSG_BLE_TRPS_SEND)
                {
                    char temp_buff[50];
                    int8_t max_index = p_appMsg->msgData[0];
                    int8_t max_score = p_appMsg->msgData[1];
                    uint8_t isMoving;
                    
                    if(p_appMsg->msgData[2] > 1)
                    {
                        isMoving = 1;
                    }
                    else
                    {
                        isMoving = 0;
                    }
                    
                    sprintf(temp_buff, "%s [%d%%] -> %s\r\n", labels[max_index], (100*max_score)/127, ((isMoving)?"Is Moving":"Idle"));
#ifndef  TRAINING_MODE_ENABLED  
                    printf("%s", temp_buff);
#endif
                    ZCL_WriteAttributeValue(APP_ENDPOINT_CUSTOM, ARMORIENTATIONCLUSTER0_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER,
                        ZCL_ARMORIENTATIONCLUSTER0_ARMORIENTATIONSERVERATTRIBUTE_SERVER_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID, &max_index);
                    ZCL_WriteAttributeValue(APP_ENDPOINT_CUSTOM, ARMORIENTATIONCLUSTER0_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER,
                        ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTSERVERATTRIBUTE_SERVER_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID, &isMoving);
                }
            }
            break;
        }
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
