/*******************************************************************************
  Application Zigbee Handler Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_zigbee_handler.c

  Summary:
    This file contains the Application Zigbee functions for this project.

  Description:
    This file contains the Application Zigbee functions for this project.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <app_zigbee/app_zigbee_handler.h>
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/zclAlarmsCluster.h>
#include <zcl/include/zclZllIdentifyCluster.h>
#include <zcl/include/zclZllGroupsCluster.h>
#include <zcl/include/zclZllOnOffCluster.h>
#include <zcl/include/zclZllLevelControlCluster.h>
#include <zcl/include/zclZllColorControlCluster.h>
#include <zcl/include/zclZllScenesCluster.h>
#include <zcl/include/zclIasACECluster.h>
#include <zcl/include/zclIasZoneCluster.h>
#include <zcl/include/zclFanControlCluster.h>
#include <zcl/include/zclThermostatCluster.h>
#include <zcl/include/zclTemperatureMeasurementCluster.h>
#include <zcl/include/zclTimeCluster.h>
#include <zcl/include/zclThermostatUiConfCluster.h>
#include <zcl/include/zclIlluminanceMeasurementCluster.h>
#include <zcl/include/zcloccupancysensingcluster.h>
#include <z3device/combinedInterface/include/ciThermostatCluster.h>
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************

void BSP_Event_Handler(APP_Zigbee_Event_t event);
void Cluster_Event_Handler(APP_Zigbee_Event_t event);
void Zigbee_Event_Handler(APP_Zigbee_Event_t event);

#define MIN_COLOR_LEVEL           0
#define MAX_COLOR_LEVEL           0xfeff

#define MIN_SATURATION_LEVEL      0
#define MAX_SATURATION_LEVEL      0xfe
// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Zigbee_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void APP_Zigbee_Handler(APP_Zigbee_Event_t event)
{
    switch(event.eventGroup)
    {
        case EVENT_BSP:
        {
            /* BSP Events Dispatcher */
            BSP_Event_Handler(event);
        }
        break;

        case EVENT_ZIGBEE:
        {
            /* Zigbee Events Dispatcher */
            Zigbee_Event_Handler(event);
        }
        break;

        case EVENT_CLUSTER:
        {
            /* Cluster Events Dispatcher */
            Cluster_Event_Handler(event);
        }
        break;

        default:
        break;
    }
}

/*******************************************************************************
  Function:
    void BSP_Event_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void BSP_Event_Handler(APP_Zigbee_Event_t event)
{
    // User to handle  board Support package events
    switch(event.eventId)
    {
        case CMD_LED_OPEN:
        {
            /* Init/Open LEDs */
            //appSnprintf("Init /Open LEDs\r\n");
        }
        break;

        case CMD_LED_ON:
        {
            /* Turn on the LED */
            //Access - > event.eventData.value;
            //appSnprintf("On\r\n");
        }
        break;

        case CMD_LED_OFF:
        {
            /* Turn off the LED */
            //Access - > event.eventData.value;
            //appSnprintf("Off\r\n");
        }
        break;

        case CMD_LED_TOGGLE:
        {
            /* Toggle the LED */
            //Access - > event.eventData.value;
            //appSnprintf("Toggle\r\n");
        }
        break;
        case CMD_LED_BRIGHTNESS:
        {
            /* Set the given LED brightness */
            //Access - > event.eventData.value;
            //appSnprintf("Led Brightness \r\n");
        }
        break;

        case CMD_LED_COLOR_HS:
        {
            /* LED Hue , Saturation */
            //Access - > event.eventData.colorHS.hue;
            //Access - > event.eventData.colorHS.saturation;
            //appSnprintf("LED Hue , Saturation \r\n");
        }
        break;

        case CMD_LED_COLOR_XY:
        {
            /* Set the LED Color X Y */
            //Access - > event.eventData.colorXY.x;
            //Access - > event.eventData.colorXY.y;
            //appSnprintf("LED X,Y Color \r\n");
        }
        break;

        case CMD_BUTTON_OPEN:
        {
            /* Button Init */
            //appSnprintf("Button Init/Open \r\n");
        }
        break;

        case CMD_BUTTON_READ:
        {
            /* Button Press */
            //Access - > event.eventData.state;
            //appSnprintf("Button Read \r\n");
        }
        break;

        case CMD_SENSOR_OPEN:
        {
            /* Sensor Data */
            //appSnprintf("Sensor Open /Init Event \r\n");
        }        
        break;

        case CMD_SENSOR_READ:
        {
            /* Sensor Data */
            //Access - > event.eventData.data;
            //appSnprintf("Sensor Read Event \r\n");
        }        
        break;
		
		case CMD_BUTTON_LONG_PRESS:
        {
            /* Button long press */
        }
		break;

        default:
        break;
    }
}

/*******************************************************************************
  Function:
    void Zigbee_Event_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void Zigbee_Event_Handler(APP_Zigbee_Event_t event)
{
    extern void APP_AIoT_Gateway_Zigbee_Event_Handler(APP_Zigbee_Event_t event);
    APP_AIoT_Gateway_Zigbee_Event_Handler(event);
    // User to handle all zigbee stack events  
    switch(event.eventId)
    {
        case EVENT_NETWORK_ESTABLISHED:
        {
            appSnprintf("Network Established\r\n");
        }
        break;
        case EVENT_DISCONNECTED:
        {
            appSnprintf("Disconnected from the Network\r\n");
        }
        break;
        case EVENT_STARTED_DISTRIBUTED_NETWORK:
        {
            appSnprintf("Started Distributed Network\r\n");
        }
        break;

        case EVENT_WAKEUP:
        {
            appSnprintf("Wake up Indication \r\n");
        }
        break;

        case EVENT_LEFT_FROM_NETWORK:
        {
            appSnprintf("Left from the Network \r\n");
        }
        break;

        case EVENT_CHILD_JOINED:
        {
            appSnprintf("Device joined: Address 0x%04x  MACID 0x%08x%08x ExtendedPANID 0x%08x%08x\r\n", event.eventData.ParentChildInfo.shortAddress, (uint32_t)(event.eventData.ParentChildInfo.extendedAddress >> 32), (uint32_t)(event.eventData.ParentChildInfo.extendedAddress & 0xFFFFFFFF), (uint32_t)(event.eventData.ParentChildInfo.extendedPanId >> 32), (uint32_t)(event.eventData.ParentChildInfo.extendedPanId & 0xFFFFFFFF));
        }
        break;

        case EVENT_CHILD_REMOVED:
        {
            appSnprintf("Child Left\r\n");
        }
        break;

        case EVENT_NWK_UPDATE:
        {
            appSnprintf("Network Information updated \r\n");
        }
        break;

        case EVENT_RESET_TO_FACTORY_DEFAULTS:
        {
            appSnprintf("Reset To Factory New\r\n");
        }
        break;

        case EVENT_NWK_ADDRESS_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf( "->NwkAddrResponse, status = %d, address = %04x\r\n" ,event.eventData.ParentChildInfo.status, event.eventData.ParentChildInfo.shortAddress);
            else
                appSnprintf( "->NwkAddrResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_IEEE_ADDRESS_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf("->IeeeAddrResponse, status = %d, address = 0x%016x \r\n", event.eventData.ParentChildInfo.status,(event.eventData.ParentChildInfo.extendedAddress));
            else
                appSnprintf( "->IeeeAddrResponse, status = %d, address = 0x%016x \r\n", event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_SIMPLE_DESCRIPTOR_RESPONSE:
        {
            appSnprintf( "->SimpleDescResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_MATCH_DESCRIPTOR_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf( "->MatchDescResponse, status = %d, MatchedEpCount = %d\r\n" ,event.eventData.ParentChildInfo.status, event.eventData.ParentChildInfo.ep);
            else
                appSnprintf( "->MatchDescResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_ACTIVE_EP_RESPONSE:
        {
            if(event.eventData.ParentChildInfo.status == ZCL_SUCCESS_STATUS)
                appSnprintf( "->ActiveEpResponse, status = %d, EpCount = %d\r\n" ,event.eventData.ParentChildInfo.status, event.eventData.ParentChildInfo.ep);
            else
                appSnprintf( "->ActiveEpResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_NODE_DESCRIPTOR_RESPONSE:
        {
            appSnprintf( "->NodeDescResponse, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_LEAVE_RESPONSE:
        {
            appSnprintf( "->LeaveRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_MANAGEMENT_BIND_RESPONSE:
        {
            appSnprintf( "MgmtBindRsp %d\r\n", event.eventData.ParentChildInfo.status); 
        }
        break;

        case EVENT_LQI_RESPONSE:
        {
            appSnprintf( "->MgmtLqiRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_BIND_RESPONSE:
        {
            appSnprintf( "->BindRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        case EVENT_UNBIND_RESPONSE:
        {
            appSnprintf( "->UnBindRsp, status = %d \r\n" ,event.eventData.ParentChildInfo.status);
        }
        break;

        default:
        break;
    }
}

/*******************************************************************************
  Function:
    void Cluster_Event_Handler(APP_Zigbee_Event_t event)

  Remarks:
    See prototype in app_zigbee_handler.h.
******************************************************************************/

void Cluster_Event_Handler(APP_Zigbee_Event_t event)
{
    switch(event.eventId)
    {
        case CMD_ZCL_RESET_TO_FACTORY_DEFAULTS:
        {
            /* Command ZCL ResetToFactoryDefaults */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            //appSnprintf("ZCL ResetToFactoryDefaults\r\n");
        }
        break;
        case CMD_ZCL_IDENTIFY:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf( "->Identify\r\n");
        }
        break;
        case CMD_ZCL_IDENTIFY_QUERY:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("->IdentifyQuery\r\n");
        }
        break;
        case CMD_ZCL_TRIGGER_EFFECT:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_TriggerEffect_t *payload = (ZCL_TriggerEffect_t *)event.eventData.zclEventData.payload;
            appSnprintf("->TriggerEffect 0x%x\r\n",  payload->effectIdentifier);
        }
        break;
        case CMD_ZCL_IDENTIFY_QUERY_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_IdentifyQueryResponse_t *payload = (ZCL_IdentifyQueryResponse_t *)event.eventData.zclEventData.payload;
            ZCL_Addressing_t *addressing = (ZCL_Addressing_t *)event.eventData.zclEventData.addressing;
            //appSnprintf("->IdentifyQueryResponse, addr = 0x%04x, timeout = 0x%04x\r\n", addressing->addr.shortAddress, payload->timeout);
            appSnprintf("{\"zcl\" : \"IdentifyQueryResponse\", \"addr\": \"0x%04x\", \"timeout\" : %d, \"endpoint\" : %d }\r\n",
                    addressing->addr.shortAddress, payload->timeout, addressing->endpointId);
        }
        break;
        case CMD_ZCL_ADD_GROUP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddGroup_t *payload = (ZCL_AddGroup_t *)event.eventData.zclEventData.payload;
            appSnprintf("addGroupInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_VIEW_GROUP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewGroup_t *payload = (ZCL_ViewGroup_t *)event.eventData.zclEventData.payload;
            appSnprintf("viewGroupInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_GET_GROUP_MEMBERSHIP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload; 
            appSnprintf("getGroupMembershipInd()\r\n");
        }
        break;
        case CMD_ZCL_REMOVE_GROUP:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveGroup_t *payload = (ZCL_RemoveGroup_t *)event.eventData.zclEventData.payload;
            appSnprintf("removeGroupInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_REMOVE_ALL_GROUP:
        {
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            appSnprintf( "removeAllGroupsInd()\r\n");
        }
        break;
        case CMD_ZCL_ADD_GROUP_IF_IDENTIFYING:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddGroupIfIdentifying_t *payload = (ZCL_AddGroupIfIdentifying_t *)event.eventData.zclEventData.payload;
            appSnprintf("addGroupIfIdentifyingInd(): 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_ADD_GROUP_RESPONSE:
        {
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            appSnprintf("addGroupResponseInd()\r\n");
        }
        break;
        case CMD_ZCL_VIEW_GROUP_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewGroupResponse_t *payload = (ZCL_ViewGroupResponse_t *)event.eventData.zclEventData.payload;
            appSnprintf("viewGroupResponse(): status = 0x%02x\r\n", payload->status);
            appSnprintf("groupId = 0x%04x\r\n", payload->groupId);
        }
        break;
        case CMD_ZCL_GET_GROUP_MEMBERSHIP_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_GetGroupMembershipResponse_t *payload = (ZCL_GetGroupMembershipResponse_t *)event.eventData.zclEventData.payload;
            appSnprintf("getGroupMembershipResponse()\r\n");
            appSnprintf("groupCount = %d\r\n", payload->groupCount);
            for (uint8_t i = 0; i < payload->groupCount; i++)
              appSnprintf("groupId = 0x%04x\r\n", payload->groupList[i]);
        }
        break;
        case CMD_ZCL_REMOVE_GROUP_RESPONSE:
        {
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveGroupResponse_t *payload = (ZCL_RemoveGroupResponse_t *)event.eventData.zclEventData.payload;
            appSnprintf("removeGroupResponseInd()\r\n");
            appSnprintf("groupId = 0x%04x\r\n", payload->groupId);

        }
        break;
        case CMD_ZCL_ALARM:
        {
            /* Command ZCL OnOffAttributeEventInd */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_Alarm_t *payload = (ZCL_Alarm_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-Alarms alarmCode = %d clusterId = 0x%x\r\n", payload->alarmCode, payload->clusterIdentifier);
        }
        break;
        case CMD_ZCL_GET_ALARM_RESPONSE:
        {
            /* Command ZCL OnOffAttributeEventInd */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload; 
            ZCL_getAlarmResponse_t *payload = (ZCL_getAlarmResponse_t *)event.eventData.zclEventData.payload; 
            if ( BC_SUCCESS == payload->status)
            {
                appSnprintf("<-GetAlarmResponse status = 0x%x clusterId = 0x%x alarmCode = 0x%x\r\n", payload->status, payload->clusterIdentifier, payload->alarmCode);
            }
            else
            {
                appSnprintf("<-GetAlarmResponse failed status = 0x%x\r\n", payload->status);
            }
        }
        break;
        case CMD_ZCL_ADD_SCENE_RESP:
        {
            /* ZCL Command Add scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_AddSceneResponse_t *resp = ((ZCL_AddSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Add scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_VIEW_SCENE_RESP:
        {
            /* ZCL Command View scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_ViewSceneResponse_t *resp = ((ZCL_ViewSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("View scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf( "groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
            appSnprintf("transitionTime = 0x%04x\r\n", resp->transitionTime);
        }
        break;
        case CMD_ZCL_REMOVE_SCENE_RESP:
        {
            /* ZCL Command remove scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveSceneResponse_t *resp = ((ZCL_RemoveSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Remove scene response: status = 0x%02x\r\n",resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_REMOVE_ALL_SCENES_RESP:
        {
            /* ZCL Command remove all scenes response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_RemoveAllScenesResponse_t *resp = ((ZCL_RemoveAllScenesResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Remove all scenes response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
        }
        break;
        case CMD_ZCL_STORE_SCENE_RESP:
        {
            /* ZCL Command store scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_StoreSceneResponse_t *resp = ((ZCL_StoreSceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Store scene response: status = 0x%02x\r\n",resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_GET_SCENE_MEMBERSHIP_RESP:
        {
            /* ZCL Command get scene membership response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_GetSceneMembershipResponse_t *resp = ((ZCL_GetSceneMembershipResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Get scene membership response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneCount = 0x%02x\r\n", resp->sceneCount);
            for (uint8_t i = 0; i < resp->sceneCount; i++)
              appSnprintf("sceneId = 0x%02x\r\n", resp->sceneList[i]);
        }
        break;
        case CMD_ZCL_ENHANCED_ADD_SCENE_RESP:
        {
            /* ZCL Command enhanced Add scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_EnhancedAddSceneResponse_t *resp = (ZCL_EnhancedAddSceneResponse_t *)(event.eventData.zclEventData.payload);
            appSnprintf("Enhanced add scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
        }
        break;
        case CMD_ZCL_ENHANCED_VIEW_SCENE_RESP:
        {
            /* ZCL Command enhanced view scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_EnhancedViewSceneResponse_t *resp = ((ZCL_EnhancedViewSceneResponse_t *)(event.eventData.zclEventData.payload));
            appSnprintf("Enhanced view scene response: status = 0x%02x\r\n", resp->status);
            appSnprintf("groupId = 0x%04x\r\n", resp->groupId);
            appSnprintf("sceneId = 0x%02x\r\n", resp->sceneId);
            appSnprintf("transitionTime = 0x%04x\r\n", resp->transitionTime);
        }
        break;
        case CMD_ZCL_COPY_SCENE_RESP:
        {
            /* ZCL Command copy scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            ZCL_CopySceneResponse_t *resp = ((ZCL_CopySceneResponse_t*)event.eventData.zclEventData.payload);
            appSnprintf("Copy scene response: status = 0x%02x\r\n", resp->status);
        }
        break;
        case CMD_ZCL_ACE_GET_PANEL_STATUS:
        {
            /* ZCL Command copy scene response received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf(" ->ACEGetPanelStatusCommandInd Received\r\n");
        }
        break;
        case CMD_ZCL_ACE_ARM:
        {
            /* ZCL command IAS ACE arm received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            //appSnprintf("aceArmCommandInd()\r\n");
        }
        break;
        case CMD_ZCL_ACE_GET_ZONE_INFO:
        {
            /* ZCL ace get zone information received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("aceGetZoneInformationCommandInd()\r\n");
        }
        break;
        case CMD_ZCL_ACE_GET_ZONE_ID_MAP:
        {
            /* ZCL IAS ACE get zone ID received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("aceGetZoneIdMapCommandInd()\r\n");
        }
        break;
        case CMD_ZCL_ACE_BYPASS:
        {
            /* ZCL IAS ACE bypass command received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("aceByPassCommandInd()\r\n");
        }
        break;
        case CMD_ZCL_ACE_GET_BYPASSED_ZONE_LIST:
        {
            /* ZCL IAS ACE get bypassed zone list command received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf("aceGetByPassedZoneListCommandInd()\r\n");
        }
        break;
        case CMD_ZCL_ACE_EMERGENCY:
        {
            /* ZCL IAS ACE emergency command received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf(" ->ACE Emergency Command Received\r\n");
        }
        break;
        case CMD_ZCL_ACE_FIRE:
        {
            /* ZCL IAS ACE fire command received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf(" ->ACE Fire Command Received\r\n");
        }
        break;
        case CMD_ZCL_ACE_PANIC:
        {
            /* ZCL Command IAS ACE PANIC received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf(" ->ACE Panic Command Received\r\n");
        }
        break;
        case CMD_ZCL_ZONE_STATUS_CHANGE_NOTIFY:
        {
            /* ZCL Command zone status change notification received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            appSnprintf(" <-Zone Status Change Notification Received\r\n");
        }
        break;
        case CMD_ZCL_ZONE_ENROLL_REQ:
        {
            /* ZCL Command ZOne enroll request received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            //appSnprintf("zoneEnrollRequestCommandInd()\r\n");
        }
        break;
        case CMD_ZCL_ATTR_COLOR_CONTROL:
        {
            /* Command ZCL ColorControlAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            //appSnprintf("ZCL ColorControlAttributeEventInd\r\n");
           if(ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT == event.eventData.zclAttributeData.event)
           {
            switch(event.eventData.zclAttributeData.attributeId)
            {
            default:
              break;
        }
           }
        }
        break;
        case CMD_ZCL_ATTR_IDENTIFY:
        {
            /* Command ZCL IdentifyAttributeEventInd */ 
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
            //appSnprintf("ZCL IdentifyAttributeEventInd\r\n");
        }
        break;
        case CMD_ZCL_ATTR_LEVEL_CONTROL:
        {
            /* Command ZCL LevelControlAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
        }
        break;
        case CMD_ZCL_ATTR_ONOFF:
        {
            /* Command ZCL OnOffAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event; 
        }
        break;
        case CMD_ZCL_ATTR_OCCUPANCY:
        {
            /* Command ZCL OccupancyAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
        }
        break;
        case CMD_ZCL_ATTR_ILLUMINANCE_MEASUREMENT:
        {
            /* Command ZCL OnOffAttributeEventInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;
        }
        break;
        case CMD_ZCL_ATTR_HUMIDITY_MEASUREMENT:
        {
            /* Command ZCL CustomHumidityMeasurementReportInd Prints Report Value */
            //Access - > event.zclAttributeData.zclEventData.addressing;
            //Access - > event.zclAttributeData.zclEventData.attributeId;
            //Access - > event.zclAttributeData.zclEventData.event;           
            //appSnprintf("ZCL HS Humidity Measurement Attr Ind\r\n");
        }
        break;
        case CMD_ZCL_ATTR_TIME:
        {
            /* Command ZCL Time attribute indication */         
            if(event.eventData.zclAttributeData.attributeId == ZCL_TIME_CLUSTER_SERVER_TIME_ATTRIBUTE_ID && 
               event.eventData.zclAttributeData.event == ZCL_WRITE_ATTRIBUTE_EVENT)
            {
	          appSnprintf("Standard and local time updated by client\r\n");
            }
        }
        break;
        case CMD_ZCL_ATTR_THERMOSTAT_UI_CONF:
        {
        }
        break;
        case CMD_ZCL_ATTR_THERMOSTAT:
        {
          /* Command ZCL Thermostat Attribute Indication */
          //Access - > eventItem.eventData.zclAttributeData.addressing;
          //Access - > eventItem.eventData.zclAttributeData.attributeId;
          //Access - > eventItem.eventData.zclAttributeData.event;  
        }
        break;
        case CMD_ZCL_ATTR_TEMPERATURE_MEASUREMENT:
        {
            /* Command ZCL Temperature measurement Attribute Indication */
            //Access - > eventItem.eventData.zclAttributeData.addressing;
            //Access - > eventItem.eventData.zclAttributeData.attributeId;
            //Access - > eventItem.eventData.zclAttributeData.event;
        }
        break;
        case CMD_ZCL_ATTR_FANCONTROL:
        {   
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;   		
            //appSnprintf("<-Attr ID 0x%x event 0x%x\r\n",event.eventData.zclAttributeData.attributeId, event.eventData.zclAttributeData.event);
        }
        break;
        case CMD_ZCL_ATTR_IASZONE:
        {
            /* command zcl IASACE attribute indication */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.attributeId;
            //Access - > event.eventData.zclAttributeData.event;               
            //appSnprintf("<-Attr ID 0x%x event 0x%x\r\n",event.eventData.zclAttributeData.attributeId, event.eventData.zclAttributeData.event);
        }
        break;
        case CMD_ZCL_REPORTING_ONOFF:
        {
            /* Command ZCL OnOffReportInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-On/Off Attr Report: Value = 0x%x\r\n", (int)rep->value[0]);
        }
        break;
        case CMD_ZCL_REPORTING_LIGHT_SENSOR:
        {
            /* Command ZCL LightSensorReportInd */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;;
            uint16_t reportValue;
            memcpy(&reportValue, &rep->value[0], sizeof(uint16_t));
            appSnprintf("<-Light Sensor Attr Report: Value = 0x%x\r\n", reportValue);
        }
        break;
        case CMD_ZCL_REPORTING_LEVEL:
        {
            /* Command ZCL LevelReportInd( */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-Level Control Attr Report: Value = 0x%x\r\n", (int)rep->value[0]);
        }
        break;
        case CMD_ZCL_REPORTING_COLOR_CONTROL:
        {
            /* ZCL Command ZCL STOP MOVE SET received */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;
            do  //Possibilities of getting more than one report at a time.
            {
                ZCL_Report_t *rep = (ZCL_Report_t *)(event.eventData.zclEventData.payload);
                uint16_t reportValue = 0;
                if(rep->type == ZCL_U8BIT_DATA_TYPE_ID)
                {
                    memcpy(&reportValue, (event.eventData.zclEventData.payload+ sizeof(ZCL_AttributeId_t)+ sizeof(rep->type)), sizeof(uint8_t));
                }
                else
                {
                    memcpy(&reportValue, (event.eventData.zclEventData.payload+ sizeof(ZCL_AttributeId_t)+ sizeof(rep->type)), sizeof(uint16_t));
                }
                appSnprintf("<-Color Control Attr (0x%x) Report: Value = 0x%x\r\n", (unsigned)rep->id, reportValue);
                
                if((event.eventData.zclEventData.payloadLength >= 4))
                {
                    if(rep->type == ZCL_U8BIT_DATA_TYPE_ID)//Attribute data is of 1 byte
                    {
                        event.eventData.zclEventData.payloadLength = event.eventData.zclEventData.payloadLength - sizeof(uint32_t);  // Skip the first report 
                        event.eventData.zclEventData.payload = (event.eventData.zclEventData.payload)+ sizeof(uint32_t);             // Align the pointer to read next        
                    }
                    else // Attribute data is of 2 byte
                    {
                        event.eventData.zclEventData.payloadLength = event.eventData.zclEventData.payloadLength - sizeof(uint32_t) - sizeof(uint8_t); // Skip the first report 
                        event.eventData.zclEventData.payload = (event.eventData.zclEventData.payload) + sizeof(uint32_t) + sizeof(uint8_t);          // Align the pointer to read next            
                    }
               }
            }while(event.eventData.zclEventData.payloadLength);   
        }
        break;
        case CMD_ZCL_REPORTING_OCCUPANCY:
        {
            /* Command ZCL LevelReportInd( */
            //Access - > event.eventData.zclAttributeData.addressing;
            //Access - > event.eventData.zclAttributeData.payloadLength;
            //Access - > event.eventData.zclAttributeData.payload;
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            appSnprintf("<-Occupancy Sensor Attr Report: Value = 0x%x\r\n", (int)rep->value[0]);
        }
        break;
        case CMD_ZCL_REPORTING_THERMOSTAT:
        {
            /* Command ZCL Thermostat Report Indication */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;                
            //appSnprintf("ZCL Report TH Thermostat Ind\r\n");
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            int16_t reportValue = 0;
            if(rep->id == ZCL_THERMOSTAT_CLUSTER_LOCAL_TEMPERATURE_SERVER_ATTRIBUTE_ID || (rep->id == ZCL_THERMOSTAT_CLUSTER_PI_COOLING_DEMAND_SERVER_ATTRIBUTE_ID)
            || (rep->id == ZCL_THERMOSTAT_CLUSTER_PI_HEATING_DEMAND_SERVER_ATTRIBUTE_ID))
            {
              if(rep->id == ZCL_THERMOSTAT_CLUSTER_LOCAL_TEMPERATURE_SERVER_ATTRIBUTE_ID)
              {
                memcpy(&reportValue, &rep->value[0], sizeof(int16_t));
                appSnprintf("<-Thermostat Attr (0x%x) Report: Value = %d.%dC\r\n", rep->id, (int)(reportValue/THERMOSTAT_LOCAL_TEMPERATURE_SCALE),(int)(reportValue%THERMOSTAT_LOCAL_TEMPERATURE_SCALE));
              }
              else
              {
                memcpy(&reportValue, &rep->value[0], sizeof(uint8_t));
                appSnprintf("<-Thermostat Attr (0x%x) Report: Value = 0x%x\r\n", rep->id, (uint8_t)reportValue);
              }
            }
            else if(rep->id == ZCL_THERMOSTAT_CLUSTER_OCCUPIED_COOLING_SETPOINT_SERVER_ATTRIBUTE_ID)
            {
              setPoint_t *payload = (setPoint_t*)rep;
    
              appSnprintf("<-Setpoints changed on Thermostat:\r\n");
              memcpy(&reportValue, &rep->value[1], sizeof(int16_t));

              appSnprintf("#cool setpoint: Value = %d.%d\r\n", (int)(reportValue/THERMOSTAT_LOCAL_TEMPERATURE_SCALE),(int)(reportValue%THERMOSTAT_LOCAL_TEMPERATURE_SCALE));
              payload++;

              memcpy(&reportValue, &payload->value, sizeof(int16_t));
              appSnprintf("#heat setpoint: Value = %d.%d\r\n", (int)(reportValue/THERMOSTAT_LOCAL_TEMPERATURE_SCALE),(int)(reportValue%THERMOSTAT_LOCAL_TEMPERATURE_SCALE));
            }
        }
        break;
        case CMD_ZCL_REPORTING_TEMPERATURE_MEASUREMENT:
        {
            /* Command ZCL Thermostat Report Indication */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;              
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            int16_t reportValue;
            memcpy(&reportValue, &rep->value[0], sizeof(int16_t));
            appSnprintf( "<-Temperature Measurement Attr Report: Value = 0x%02hx\r\n", reportValue);
        }
        break;
        case CMD_ZCL_REPORTING_HUMIDITY_MEASUREMENT:
        {
            /* Command ZCL Humidity Measurement Report Indication */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;              
            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            uint16_t reportValue;
            memcpy(&reportValue, &rep->value[0], sizeof(uint16_t));
            appSnprintf( "<-Relative Humidity Measurement Attr Report: Value = 0x%x\r\n", reportValue);
        }
        break;
        
        //Custom Clusters       
        case CMD_ZCL_REPORTING_ARMCLUSTER0:
        {
            /*Report Indication */
            //Access - > event.eventData.zclEventData.addressing;
            //Access - > event.eventData.zclEventData.payloadLength;
            //Access - > event.eventData.zclEventData.payload;      

            //handle logic for multiple reportable attributes 

            ZCL_Report_t *rep = (ZCL_Report_t *)event.eventData.zclEventData.payload;
            uint16_t reportValue;
            memcpy(&reportValue, &rep->value[0], sizeof(uint16_t));
            appSnprintf( "<- Armcluster0 Attr Report: Value = 0x%x\r\n", reportValue);
        }
        break;   



        default:
        break;
    }
}