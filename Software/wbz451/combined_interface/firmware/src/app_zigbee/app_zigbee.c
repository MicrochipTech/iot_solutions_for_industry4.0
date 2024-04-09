/*******************************************************************************
  Application Zigbee Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zigbee_app_source.c

  Summary:
    This file contains the Application Zigbee implementation for this project.

  Description:
    This file contains the Application Zigbee implementation for this project.
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

#include <z3device/stack_interface/zgb_api.h>
#include <z3device/stack_interface/bdb/include/bdb_api.h>
#include <z3device/stack_interface/zcl/include/zcl_api.h>
#include <z3device/stack_interface/configServer/include/cs_api.h>
#include <z3device/stack_interface/nwk/include/nwk_api.h>
#include <app_zigbee/zigbee_console/console.h>
#include <z3device/stack_interface/bdb/include/BDB_Unpack.h>
#include <configserver/include/configserver.h>
#include <aps/include/apsCommon.h>
#include <zcl/include/zclAttributes.h>
#include <z3device/common/include/z3Device.h>
#include <zcl/include/clusters.h>
#include <pds/include/wlPdsMemIds.h>
#include "app_zigbee/app_zigbee.h"
#include "app.h"
#include <osal/osal_freertos.h>
#include <zcl/include/zclArmcluster0Cluster.h>
#include "app_timer/app_timer.h"
// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Global Variables
// *****************************************************************************
// *****************************************************************************

static uint8_t joinInterval = APP_JOIN_ATTEMPT_INTERVAL;
static uint8_t joinAttempts = APP_JOIN_ATTEMPTS_AMOUNT;
static void joinRetryTimerFired(void);
static HAL_AppTimer_t joinRetryTimer =
{
  .interval = APP_JOIN_ATTEMPT_INTERVAL* 1000,
  .mode     = TIMER_ONE_SHOT_MODE,
  .callback = joinRetryTimerFired,
};

bool isDeviceCommissioned = false;
PDS_DECLARE_ITEM(PDS_APP_COMMISION_ID, sizeof(isDeviceCommissioned), &isDeviceCommissioned, NULL, NO_ITEM_FLAGS);

static uint8_t bIndex;

static BDB_CommissioningMode_t commissioningMode;
BDB_InvokeCommissioningReq_t aIoT_Gateway_bdbCommissioningreq;
static BDB_InitiatorReq_t aIoT_Gateway_InitiatorReq;

static void aIoT_Gateway_NetworkEventsHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static SYS_EventReceiver_t aIoT_Gateway_NetworkEventsListener  = { .func = aIoT_Gateway_NetworkEventsHandler};

static void aIoT_Gateway_BindTableUpdatedHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static SYS_EventReceiver_t aIoT_Gateway_BindTableUpdated  = { .func = aIoT_Gateway_BindTableUpdatedHandler};

static void aIoT_Gateway_DevAnnouncedHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static SYS_EventReceiver_t aIoT_Gateway_DeviceAnnounce  = { .func = aIoT_Gateway_DevAnnouncedHandler};


// *****************************************************************************
// *****************************************************************************
// Section: Function Prototypes
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_ZigbeeStackCb(ZB_AppGenericCallbackParam_t *response)

  Remarks:
    See prototype in app_zigbee.h.
******************************************************************************/
void ReadAttribCallBack(ZCL_Notify_t *ntfy)
{
    ZCL_NextElement_t element;
    ZCL_ReadAttributeResp_t *readAttributeResp;
    uint8_t s8AttrVal;
    char attribTemp[15];

    if (ZCL_SUCCESS_STATUS == ntfy->status)
    {
        uint8_t numberofAttributesRead = 1;
        ZCL_Status_t zclStatus;
        element.id            = ZCL_READ_ATTRIBUTES_RESPONSE_COMMAND_ID;
        element.payloadLength = ntfy->responseLength;
        element.payload       = ntfy->responsePayload;
        element.content       = NULL;

        do
        {
            zclStatus = ZCL_GetNextElement(&element);
            readAttributeResp = (ZCL_ReadAttributeResp_t *) element.content;
            if (numberofAttributesRead > 10)
            {
                return;
            }
            numberofAttributesRead++;
            if (ZCL_SUCCESS_STATUS == readAttributeResp->status)
            {
                if (readAttributeResp->id == ZCL_ARMCLUSTER0_ARMORIENTATIONCLIENTATTRIBUTE_SERVER_ATTRIBUTE_ID)
                {
                    s8AttrVal = readAttributeResp->value[0];
                    //memcpy(&s16AttrVal, &readAttributeResp->value[0], sizeof(int16_t));
                    //appSnprintf("Id:0x%x, value = %d\r\n", (unsigned)readAttributeResp->id, s16AttrVal);
                    //sprintf(attribTemp, "Set: %d.%dC", (int)(s16AttrVal/100),(int)(s16AttrVal%100));
                    appSnprintf("Arm Position: %d\r\n", s8AttrVal);
                }
                else
                {
                    appSnprintf("ReadAttribCallBack: %d\r\n", readAttributeResp->id);
                }
            }
        } while (ZCL_END_PAYLOAD_REACHED_STATUS != zclStatus);
    }
}

void aIoT_armOrientation_ReadAttribute(void)
{
    readAttribute(APS_NO_ADDRESS, 0, APP_ENDPOINT_CUSTOM, APP_ENDPOINT_COMBINED_INTERFACE, ARMCLUSTER0_CLUSTER_ID,
                   ZCL_ARMCLUSTER0_ARMORIENTATIONCLIENTATTRIBUTE_SERVER_ATTRIBUTE_ID, ReadAttribCallBack);
}

void aIoT_Gateway_StartCommissioning(BDB_CommissioningMode_t mode)
{
    APP_Msg_T   appBDBCommissioningMsg;
    appBDBCommissioningMsg.msgId = APP_MSG_BDB_COMMISSIONING_EVT;
    appBDBCommissioningMsg.msgData[0] = mode;
    OSAL_QUEUE_Send(&appData.appQueue, &appBDBCommissioningMsg, 0);
}

static void joinRetryTimerFired(void)
{
    if ( joinAttempts && (joinAttempts !=  0xff))
    {
        joinAttempts--;
    }
    aIoT_Gateway_StartCommissioning(commissioningMode);
}

static void handleSteering(void)
{
    APP_Zigbee_Event_t event;
    if (commissioningMode == APP_COMMISSIONING_STEERING_VALUE)
    {
        if (joinInterval && joinAttempts)
        {     
            HAL_StartAppTimer(&joinRetryTimer);
        }
        else
        {
            HAL_StopAppTimer(&joinRetryTimer);
            event.eventGroup = EVENT_ZIGBEE;
            event.eventId = EVENT_COMMISSIONING_FAILURE;
            event.eventData.value = BDB_COMMISSIONING_NO_NETWORK;
            APP_Zigbee_Handler(event);
            joinAttempts = APP_JOIN_ATTEMPTS_AMOUNT;
        }
    }
}

bool update_find_n_bind(void)
{
    if (bIndex < APP_ENDPOINTS_AMOUNT)
    {
//        appSnprintf("FB Started\r\n");
        commissioningMode = APP_COMMISSIONING_FINDING_AND_BINDING_VALUE;
        aIoT_Gateway_StartCommissioning(commissioningMode);
        return true;
    }
    else
    {
//        appSnprintf("FB Done\r\n");
        return false;
    }
}

static void aIoT_Gateway_Callback_Commissioning(BDB_InvokeCommissioningConf_t *conf)
{
//    appSnprintf("BDB_COMMISSIONING: 0x%x - 0x%x\r\n\n", conf->status, commissioningMode);
    if (conf->status == BDB_COMMISSIONING_NO_NETWORK )
    {
        handleSteering();
    }
    else if ((conf->status == BDB_COMMISSIONING_SUCCESS) &&  (commissioningMode == APP_COMMISSIONING_FORMING_VALUE))
    {
        commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
        handleSteering();
    }
    else if ((conf->status == BDB_COMMISSIONING_SUCCESS ) && (commissioningMode == APP_COMMISSIONING_STEERING_VALUE))
    {
        update_find_n_bind();
    }
    else if ((conf->status == BDB_COMMISSIONING_SUCCESS ) && commissioningMode == APP_COMMISSIONING_FINDING_AND_BINDING_VALUE)
    {
        APP_Zigbee_Event_t event;
        event.eventGroup = EVENT_ZIGBEE;
        event.eventId = EVENT_COMMISSIONING_FINDBIND_COMPLETE;
        event.eventData.value = BDB_COMMISSIONING_IN_PROGRESS;
        APP_Zigbee_Handler(event);
    }
}

void aIoT_Gateway_StartCommissioning_task(BDB_CommissioningMode_t mode)
{
    memset(&aIoT_Gateway_bdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
    aIoT_Gateway_bdbCommissioningreq.mode = mode;
    if(aIoT_Gateway_bdbCommissioningreq.mode == APP_COMMISSIONING_FINDING_AND_BINDING_VALUE)
    {
        AppBindReq_t *currBindReq = deviceBindReqs[bIndex++];
        
        aIoT_Gateway_InitiatorReq.initiatorEndpoint = currBindReq->srcEndpoint;
        aIoT_Gateway_InitiatorReq.clientClustersCount = currBindReq->remoteServersCnt;
        aIoT_Gateway_InitiatorReq.serverClustersCount = currBindReq->remoteClientsCnt;

        aIoT_Gateway_InitiatorReq.clientClustersList = currBindReq->remoteServers;
        aIoT_Gateway_InitiatorReq.serverClustersList = currBindReq->remoteClients;

        aIoT_Gateway_InitiatorReq.callback = currBindReq->callback;
        aIoT_Gateway_InitiatorReq.groupId = currBindReq->groupId;

        aIoT_Gateway_bdbCommissioningreq.initiatorReq = &aIoT_Gateway_InitiatorReq;
    }
    aIoT_Gateway_bdbCommissioningreq.BDB_InvokeCommissioningConf = aIoT_Gateway_Callback_Commissioning;
    BDB_InvokeCommissioning(&aIoT_Gateway_bdbCommissioningreq);
}

static void aIoT_Gateway_BindTableUpdatedHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
//    appSnprintf("Bind Table Updated\r\n");
    //LCD_PRINT(0,2,"BIND Completed");
}

static void aIoT_Gateway_DevAnnouncedHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
//    appSnprintf("Device Announce\r\n");
    bIndex = 0;
    update_find_n_bind();
}

static void aIoT_Gateway_NetworkEventsHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
    if((eventId == BC_EVENT_NETWORK_LEFT) || (eventId == BC_EVENT_NETWORK_LOST))
    {
        APP_Zigbee_Event_t event;
        commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
        aIoT_Gateway_StartCommissioning(commissioningMode);

        event.eventGroup = EVENT_ZIGBEE;
        event.eventId = EVENT_LEFT_FROM_NETWORK;
        APP_Zigbee_Handler(event);
    }
    else if (eventId == BC_EVENT_CHILD_JOINED)
    {
//        appSnprintf("Device Joined\r\n");
        bIndex = 0;
        update_find_n_bind();
    }
}

void APP_ZigbeeStackCb(ZB_AppGenericCallbackParam_t *cb)
{
  APP_Msg_T   appMsg;
  void *paramPtr = NULL;
  
  ZB_AppGenericCallbackParam_t* newCB = 
          (ZB_AppGenericCallbackParam_t*) OSAL_Malloc(sizeof(ZB_AppGenericCallbackParam_t));

  
  appMsg.msgId = APP_MSG_ZB_STACK_CB;
  
  memcpy(newCB,cb,sizeof(ZB_AppGenericCallbackParam_t));

  if(cb->paramSize != 0)
  {
    paramPtr = OSAL_Malloc(cb->paramSize);
    memcpy(paramPtr,cb->parameters, cb->paramSize);
    newCB->parameters = paramPtr;
  }
  
  memcpy(appMsg.msgData,&newCB,sizeof(newCB));
#ifdef H3_INDEPENDENT 
  OSAL_QUEUE_Send(&g_appQueue, &appMsg,0);
#else
  OSAL_QUEUE_Send(&appData.appQueue, &appMsg,0);
#endif 
}

void APP_ButtonISR(void)
{
//    appSnprintf("Enable Comm\r\n");
    commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
    aIoT_Gateway_StartCommissioning(commissioningMode);
}

void APP_AIoT_Gateway_Zigbee_Event_Handler(APP_Zigbee_Event_t event)
{
    // User to handle all zigbee stack events  
    APP_Msg_T appMsg;
    switch(event.eventId)
    {
        case EVENT_COMMISSIONING_FINDBIND_COMPLETE:
	    {
            if (update_find_n_bind() == false)
            {
                bIndex = 0;
                event.eventGroup = EVENT_ZIGBEE;
                event.eventId = EVENT_COMMISSIONING_COMPLETE;
                event.eventData.value = BDB_COMMISSIONING_SUCCESS;
                APP_Zigbee_Handler(event);
//                appSnprintf("FB Complete\r\n");
            }
            else
            {
//                appSnprintf("FB InProgress\r\n");
            }
	    }
	    break;
        case EVENT_COMMISSIONING_FAILURE:
        {
//            appSnprintf("Cannot Find network to Join\r\n");
//            appSnprintf("Try invokeCommissioning 4 0 to create a network\r\n Or press usr btn to enter steering mode\r\n\n");
           
		}
		break;
        case EVENT_STARTED_CENTRALIZED_NETWORK:
        {
//            appSnprintf("EVENT_C_NETWORK\r\n");
            /* APP_TRPS_Sensor_BLE_light_Init(true);                 */
            if(!isDeviceCommissioned)
            {
                isDeviceCommissioned = true;
                PDS_Store(PDS_APP_COMMISION_ID);
                appMsg.msgId = APP_IDLE_TASK_EVT;
                OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
            }
        }
        break;

        case EVENT_STARTED_DISTRIBUTED_NETWORK:
        {
//            appSnprintf("EVENT_D_NETWORK\r\n");
            /* APP_TRPS_Sensor_BLE_light_Init(true);                 */
            if(!isDeviceCommissioned)
            {
                isDeviceCommissioned = true;
                PDS_Store(PDS_APP_COMMISION_ID);
                appMsg.msgId = APP_IDLE_TASK_EVT;
                OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
            }
        }
        break;

        case EVENT_NETWORK_ESTABLISHED:
        {
//            appSnprintf("EVENT_N_ESTABLISHED\r\n");
            /* APP_TRPS_Sensor_BLE_light_Init(true);    */           
            if(!isDeviceCommissioned)
            {
                isDeviceCommissioned = true;
                PDS_Store(PDS_APP_COMMISION_ID);
                appMsg.msgId = APP_IDLE_TASK_EVT;
                OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
            }
        }
        break;
        case EVENT_CHILD_JOINED:
        {
//            appSnprintf("Child Joined\r\n");
        }
        break;
        case EVENT_JOINED_TO_AN_EXISTING_NETWORK:
        {
//            appSnprintf("EVENT_JOINED__NETWORK\r\n");
            /* APP_TRPS_Sensor_BLE_light_Init(true);    */           
            if(!isDeviceCommissioned)
            {
                isDeviceCommissioned = true;
                PDS_Store(PDS_APP_COMMISION_ID);
                appMsg.msgId = APP_IDLE_TASK_EVT;
                OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
            }
        }
        break;
        case EVENT_COMMISSIONING_COMPLETE:
        {
            appSnprintf("{\"Commissioning\" : \"Complete\"}\r\n");
//            aIoT_armOrientation_ReadAttribute();
//            APP_TIMER_SetTimer(APP_TIMER_ID_0, APP_TIMER_5S, true);
        }
        break;      
        default:
        break;
    }
}

void APP_AIoT_Gateway_Init(void)
{
    SYS_SubscribeToEvent(BC_EVENT_NETWORK_LEFT, &aIoT_Gateway_NetworkEventsListener);
    SYS_SubscribeToEvent(BC_EVENT_NETWORK_LOST, &aIoT_Gateway_NetworkEventsListener);
//    SYS_SubscribeToEvent(BC_EVENT_BIND_TABLE_UPDATED, &aIoT_Gateway_BindTableUpdated);
    SYS_SubscribeToEvent(BC_EVENT_DEVICE_ANNCE, &aIoT_Gateway_DeviceAnnounce);
    
    if (PDS_IsAbleToRestore(PDS_APP_COMMISION_ID))
    {
//        appSnprintf("PDS Restore\r\n");
        isDeviceCommissioned = true;
        PDS_Restore(PDS_APP_COMMISION_ID);
        commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
        aIoT_Gateway_StartCommissioning(commissioningMode);
    }
    else
    {
//        appSnprintf("PDS Restore Failed\r\n");
        isDeviceCommissioned = false;
    }
    
    if(isDeviceCommissioned)
    {
//        appSnprintf("Comm Mode: restore\r\n");
        commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
        aIoT_Gateway_StartCommissioning(commissioningMode);
    }
    else
    {
//        appSnprintf("Comm Mode: Forming\r\n");
        commissioningMode = APP_COMMISSIONING_FORMING_VALUE;        //APP_COMMISSIONING_STEERING_VALUE
        aIoT_Gateway_StartCommissioning(commissioningMode);
    }
       
//    commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
    
    
    EIC_CallbackRegister(EIC_PIN_0, (EIC_CALLBACK)APP_ButtonISR, 0);
    EIC_InterruptEnable(EIC_PIN_0);
    
//    APP_TIMER_SetTimer(APP_TIMER_ID_2, APP_TIMER_5S, true);     //APP_TIMER_30S
}
/*******************************************************************************
  Function:
    void APP_ZigbeeStackInit()

  Remarks:
    See prototype in app_zigbee.h.
******************************************************************************/
void APP_ZigbeeStackInit(void)
{
  ZB_EventRegister(APP_ZigbeeStackCb);
}
