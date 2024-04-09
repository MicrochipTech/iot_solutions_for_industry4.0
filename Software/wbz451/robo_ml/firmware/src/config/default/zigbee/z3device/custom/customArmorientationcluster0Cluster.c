/*******************************************************************************
  ZCC0 Custom Cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
   customArmorientationcluster0Cluster.c

  Summary:
    This file contains the Custom Cluster interface.

  Description:
    This file contains the Custom Cluster interface.
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


/******************************************************************************
                    Includes section
******************************************************************************/

#include <z3device/custom/include/customArmorientationcluster0Cluster.h>
#include <zcl/include/zclArmorientationcluster0Cluster.h>

#include <z3device/clusters/include/haClusters.h>
#include <zcl/include/zclCommandManager.h>
#include <app_zigbee/app_zigbee_handler.h>
#include <app_zigbee/zigbee_console/console.h>


/*******************************************************************************
                    Prototypes section
*******************************************************************************/

static void customArmorientationcluster0AttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);
static void customArmorientationcluster0ReportInd(ZCL_Addressing_t *addressing, uint8_t reportLength, uint8_t *reportPayload);
void customArmorientationcluster0Init(void);


ZCL_Status_t customSendArmorientationservercommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint
    ,uint8_t armOrientationServerParam );
ZCL_Status_t customSendArmmovementservercommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint
    ,uint8_t armMovementServerParam );

ZCL_Status_t ArmorienatationclientcommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armorienatationclientcommand_t *payload);
ZCL_Status_t ArmmovementclientcommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armmovementclientcommand_t *payload);


/******************************************************************************
                    Global variables
******************************************************************************/


//Custom Cluster Attributes
ZCL_Armorientationcluster0ClusterServerAttributes_t armorientationcluster0ServerClusterAttributes =
{
    ZCL_DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER_SERVER_ATTRIBUTES(ARMORIENTATIONCLUSTER0_MIN_REPORT_PERIOD,ARMORIENTATIONCLUSTER0_MAX_REPORT_PERIOD)
};

//Custom Cluster Commands
PROGMEM_DECLARE (ZCL_Armorientationcluster0ClusterCommands_t armorientationcluster0ServerClusterCommands) =
{

ZCL_DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER_COMMANDS( NULL, NULL, NULL, NULL)       //sankar
//  ZCL_DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER_COMMANDS(ArmorientationservercommandCommandInd,
//        ArmmovementservercommandCommandInd,
//        ArmorienatationclientcommandCommandInd,
//        ArmmovementclientcommandCommandInd)
};


/******************************************************************************
                    Implementation section
******************************************************************************/

void customArmorientationcluster0InitAttributes(void)
{
    armorientationcluster0ServerClusterAttributes.Armmovementserverattribute.minReportInterval = 
            ARMORIENTATIONCLUSTER0_MIN_REPORT_PERIOD;
    armorientationcluster0ServerClusterAttributes.Armmovementserverattribute.maxReportInterval = 
            ARMORIENTATIONCLUSTER0_MAX_REPORT_PERIOD;
    
}

/**************************************************************************//**
\brief Initialization function for the cluster
******************************************************************************/
void customArmorientationcluster0Init(void)
{
    /* Executes only for Server. */
    ZCL_Cluster_t *cluster =  ZCL_GetCluster(APP_ENDPOINT_CUSTOM, ARMORIENTATIONCLUSTER0_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);

    if (cluster)
    {
        cluster->ZCL_AttributeEventInd = customArmorientationcluster0AttributeEventInd;
        cluster->ZCL_ReportInd = customArmorientationcluster0ReportInd;
    }

    // Fill definition here
    customArmorientationcluster0InitAttributes();
}

/**************************************************************************//**
\brief Attribute event (writing/reading) callback.

\param[in] addressing - incoming request addressing information.
\param[in] attributeId - attribute identifier.
\param[in] event - attribute event (read/write).
******************************************************************************/
static void customArmorientationcluster0AttributeEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
    APP_Zigbee_Event_t eventItem;
    eventItem.eventGroup = EVENT_CLUSTER;
    eventItem.eventId = CMD_ZCL_ATTR_ARMORIENTATIONCLUSTER0; //defined in app_zigbee_handler
    eventItem.eventData.zclAttributeData.addressing = addressing;
    eventItem.eventData.zclAttributeData.attributeId = attributeId;
    eventItem.eventData.zclAttributeData.event = event;
                        
  APP_Zigbee_Handler(eventItem);
}

static void customArmorientationcluster0ReportInd(ZCL_Addressing_t *addressing, uint8_t reportLength, uint8_t *reportPayload)
{
  APP_Zigbee_Event_t event;
  event.eventGroup = EVENT_CLUSTER;
  event.eventId = CMD_ZCL_REPORTING_ARMORIENTATIONCLUSTER0;
  event.eventData.zclEventData.addressing = addressing;
  event.eventData.zclEventData.payloadLength = reportLength;
  event.eventData.zclEventData.payload = reportPayload;

  APP_Zigbee_Handler(event);
}
/**************************************************************************//**
\brief Sends Armorientationservercommand command

\param[in] mode     - address mode;
\param[in] addr     - short address of destination node;
\param[in] ep       - destination endpoint;
\param[in] srcEp    - source endpoint;
******************************************************************************/
ZCL_Status_t customSendArmorientationservercommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint 
    ,uint8_t armOrientationServerParam )
{
    //fill definition
}
/**************************************************************************//**
\brief Sends Armmovementservercommand command

\param[in] mode     - address mode;
\param[in] addr     - short address of destination node;
\param[in] ep       - destination endpoint;
\param[in] srcEp    - source endpoint;
******************************************************************************/
ZCL_Status_t customSendArmmovementservercommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint 
    ,uint8_t armMovementServerParam )
{
    //fill definition
}
/**************************************************************************//**
\brief Callback on receiving Armorienatationclientcommand command

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer

\return status of indication routine
******************************************************************************/
ZCL_Status_t ArmorienatationclientcommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armorienatationclientcommand_t *payload)
{
    appSnprintf("Commands: customArmorienatationclientcommandInd \r\n");
    //fill definition
}

/**************************************************************************//**
\brief Callback on receiving Armmovementclientcommand command

******************************************************************************/