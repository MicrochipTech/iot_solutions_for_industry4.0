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
static uint8_t joinInterval = APP_JOIN_ATTEMPT_INTERVAL;
static uint8_t joinAttempts = APP_JOIN_ATTEMPTS_AMOUNT * 50;
static void joinRetryTimerFired(void);
static HAL_AppTimer_t joinRetryTimer =
{
  .interval = APP_JOIN_ATTEMPT_INTERVAL* 1000,
  .mode     = TIMER_ONE_SHOT_MODE,
  .callback = joinRetryTimerFired,
};

static uint8_t bIndex;

static BDB_CommissioningMode_t commissioningMode;
BDB_InvokeCommissioningReq_t aIoT_roboArm_bdbCommissioningreq;
static BDB_InitiatorReq_t aIoT_roboArm_InitiatorReq;

bool isDeviceCommissioned = false;
PDS_DECLARE_ITEM(PDS_APP_COMMISION_ID, sizeof(isDeviceCommissioned), &isDeviceCommissioned, NULL, NO_ITEM_FLAGS);

static void aIoT_RoboArm_NetworkEventsHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static SYS_EventReceiver_t aIoT_RoboArm_NetworkEventsListener  = { .func = aIoT_RoboArm_NetworkEventsHandler};

static void aIoT_RoboArm_BindTableUpdatedHandler(SYS_EventId_t eventId, SYS_EventData_t data);
static SYS_EventReceiver_t aIoT_RoboArm_BindTableUpdated  = { .func = aIoT_RoboArm_BindTableUpdatedHandler}; 
void APP_AIoT_RoboArm_StartCommissioning(BDB_CommissioningMode_t mode);
bool update_find_n_bind(void);

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

static void handleSteeringFailure(void)
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


static void joinRetryTimerFired(void)
{
    if ( joinAttempts && (joinAttempts !=  0xff))
    {
        joinAttempts--;
    }
//    if(BDB_GetBdbNodeIsOnANetwork())
//    {
//        printf("Dev on network\r\n");
//    }
//    else
//    {
//        printf("Dev not in network\r\n");
//    }
    bIndex = 0;
    commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
    APP_AIoT_RoboArm_StartCommissioning(commissioningMode);
}

bool update_find_n_bind(void)
{
    if (bIndex < APP_ENDPOINTS_AMOUNT)
    {
        commissioningMode = APP_COMMISSIONING_FINDING_AND_BINDING_VALUE;
        APP_AIoT_RoboArm_StartCommissioning(commissioningMode);
        return true;
    }
    else
    {
        return false;
    }
}

static void aIoT_roboArm_Callback_Commissioning(BDB_InvokeCommissioningConf_t *conf)
{
    printf("BDB_COMMISSIONING cb: 0x%x - 0x%x\r\n\n", conf->status, commissioningMode);
    if (conf->status == BDB_COMMISSIONING_NO_NETWORK )
    {
        handleSteeringFailure();
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

void APP_AIoT_RoboArm_StartCommissioning(BDB_CommissioningMode_t mode)
{
    memset(&aIoT_roboArm_bdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
    aIoT_roboArm_bdbCommissioningreq.mode = mode;
    if(aIoT_roboArm_bdbCommissioningreq.mode == APP_COMMISSIONING_FINDING_AND_BINDING_VALUE)
    {
        AppBindReq_t *currBindReq = deviceBindReqs[bIndex++];
        
        aIoT_roboArm_InitiatorReq.initiatorEndpoint = currBindReq->srcEndpoint;
        aIoT_roboArm_InitiatorReq.clientClustersCount = currBindReq->remoteServersCnt;
        aIoT_roboArm_InitiatorReq.serverClustersCount = currBindReq->remoteClientsCnt;

        aIoT_roboArm_InitiatorReq.clientClustersList = currBindReq->remoteServers;
        aIoT_roboArm_InitiatorReq.serverClustersList = currBindReq->remoteClients;

        aIoT_roboArm_InitiatorReq.callback = currBindReq->callback;
        aIoT_roboArm_InitiatorReq.groupId = currBindReq->groupId;

        aIoT_roboArm_bdbCommissioningreq.initiatorReq = &aIoT_roboArm_InitiatorReq;
    }
    aIoT_roboArm_bdbCommissioningreq.BDB_InvokeCommissioningConf = aIoT_roboArm_Callback_Commissioning;
    BDB_InvokeCommissioning(&aIoT_roboArm_bdbCommissioningreq);
}

static void aIoT_RoboArm_BindTableUpdatedHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
    printf("RoboApp: BIND Completed 0x%X, 0x%X\r\n", eventId, data);
}

static void aIoT_RoboArm_NetworkEventsHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
    printf("Net Lost/Left\r\n");
    if((eventId == BC_EVENT_NETWORK_LEFT) || (eventId == BC_EVENT_NETWORK_LOST))
    {
        APP_Zigbee_Event_t event;
        commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
        APP_AIoT_RoboArm_StartCommissioning(commissioningMode);

        event.eventGroup = EVENT_ZIGBEE;
        event.eventId = EVENT_LEFT_FROM_NETWORK;
        APP_Zigbee_Handler(event);
    }
}

void APP_AIoT_RoboArm_Init(void)
{
    SYS_SubscribeToEvent(BC_EVENT_NETWORK_LEFT, &aIoT_RoboArm_NetworkEventsListener);
    SYS_SubscribeToEvent(BC_EVENT_NETWORK_LOST, &aIoT_RoboArm_NetworkEventsListener);
    SYS_SubscribeToEvent(BC_EVENT_BIND_TABLE_UPDATED, &aIoT_RoboArm_BindTableUpdated);
    
    if (PDS_IsAbleToRestore(PDS_APP_COMMISION_ID))
    {
        PDS_Restore(PDS_APP_COMMISION_ID);
        printf("PDS Restore\r\n");
//        update_find_n_bind();
//        APP_TIMER_SetTimer(APP_TIMER_ID_0, APP_TIMER_5S, true);
    }
    else
    {
        printf("PDS Restore Failed\r\n");
        isDeviceCommissioned = false;
    }
    commissioningMode = APP_COMMISSIONING_STEERING_VALUE; 
    APP_AIoT_RoboArm_StartCommissioning(commissioningMode);
}

void APP_AIoT_Zigbee_Event_Handler(APP_Zigbee_Event_t event)
{
    APP_Msg_T   appMsg;
    // User to handle all zigbee stack events  
    switch(event.eventId)
    {
        case EVENT_COMMISSIONING_FINDBIND_COMPLETE:
	    {
//            printf("FINDBIND_COMPLETE\r\n");
            if (update_find_n_bind() == false)
            {
                event.eventGroup = EVENT_ZIGBEE;
                event.eventId = EVENT_COMMISSIONING_COMPLETE;
                event.eventData.value = BDB_COMMISSIONING_SUCCESS;
                APP_Zigbee_Handler(event);
            }
	    }
	    break;
        case EVENT_COMMISSIONING_FAILURE:
        {
            printf("EVENT_FAILURE\r\n");
           
		}
		break;
        case EVENT_STARTED_CENTRALIZED_NETWORK:
        {
            printf("EVENT_NETWORK\r\n");
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
            printf("EVENT_NETWORK\r\n");
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
            //printf("EVENT_ESTABLISHED\r\n");
            /* APP_TRPS_Sensor_BLE_light_Init(true);    */           
            if(!isDeviceCommissioned)
            {
                printf("PDS Store\r\n");
                isDeviceCommissioned = true;
                PDS_Store(PDS_APP_COMMISION_ID);
                appMsg.msgId = APP_IDLE_TASK_EVT;
                OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
            }
            bIndex = 0;
            update_find_n_bind();
//            APP_TIMER_SetTimer(APP_TIMER_ID_0, APP_TIMER_5S, true); //sankar
        }
        break;
        case EVENT_JOINED_TO_AN_EXISTING_NETWORK:
        {
            printf("EVENT_JOINED__NETWORK\r\n");
            /* APP_TRPS_Sensor_BLE_light_Init(true);    */           
            if(!isDeviceCommissioned)
            {
                isDeviceCommissioned = true;
                PDS_Store(PDS_APP_COMMISION_ID);
                appMsg.msgId = APP_IDLE_TASK_EVT;
                OSAL_QUEUE_Send(&appData.appQueue, &appMsg, 0);
            }
//            APP_TIMER_SetTimer(APP_TIMER_ID_0, APP_TIMER_5S, true); //sankar
        }
        break;
        case EVENT_COMMISSIONING_COMPLETE:
        {
            printf("EVENT_COMPLETE\r\n");
//            LocalTemp_ReadAttribute();
//            OccupiedCoolSP_ReadAttribute();
//            APP_TIMER_SetTimer(APP_TIMER_ID_0, APP_TIMER_5S, true);
        }
        break;
        case EVENT_DISCONNECTED:
        {
            printf("EVENT_DISCONNECTED\r\n");
            commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
            handleSteeringFailure();
//            APP_AIoT_RoboArm_StartCommissioning(commissioningMode);
        }
        break;
        case EVENT_LEFT_FROM_NETWORK:
        {
            printf("EVENT_LEFT_FROM_NETWORK\r\n");
            commissioningMode = APP_COMMISSIONING_STEERING_VALUE;
            handleSteeringFailure();
        }
        break;      
        default:
        break;
    }

//    app_idle_task();
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
