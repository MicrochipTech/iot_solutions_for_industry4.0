/*******************************************************************************
  ZCC0 Custom Cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
   ciArmcluster0Cluster.c

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

#include <z3device/combinedInterface/include/ciArmcluster0Cluster.h>
#include <zcl/include/zclArmcluster0Cluster.h>

#include <z3device/clusters/include/haClusters.h>
#include <zcl/include/zclCommandManager.h>
#include <app_zigbee/app_zigbee_handler.h>
#include <app_zigbee/zigbee_console/console.h>


/*******************************************************************************
                    Prototypes section
*******************************************************************************/

static void ciArmcluster0ReportInd(ZCL_Addressing_t *addressing, uint8_t reportLength, uint8_t *reportPayload);
void ciArmcluster0Init(void);


ZCL_Status_t ciArmorientationservercommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armorientationservercommand_t *payload);
ZCL_Status_t ciArmmovementservercommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armmovementservercommand_t *payload);

ZCL_Status_t ciSendArmorientationclientcommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint 
    ,uint8_t armOrientationParam );
ZCL_Status_t ciSendArmmovementclientcommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint 
    ,uint8_t armMovementParam );


/******************************************************************************
                    Global variables
******************************************************************************/


//Custom Cluster Attributes
ZCL_Armcluster0ClusterClientAttributes_t armcluster0ClientClusterAttributes =
{
    ZCL_DEFINE_ARMCLUSTER0_CLUSTER_CLIENT_ATTRIBUTES(ARMCLUSTER0_MIN_REPORT_PERIOD,ARMCLUSTER0_MAX_REPORT_PERIOD)
};

//Custom Cluster Commands
PROGMEM_DECLARE (ZCL_Armcluster0ClusterCommands_t armcluster0ClientClusterCommands) =
{

ZCL_DEFINE_ARMCLUSTER0_CLUSTER_COMMANDS( ciArmorientationservercommandCommandInd,  ciArmmovementservercommandCommandInd, NULL , NULL)        

};


/******************************************************************************
                    Implementation section
******************************************************************************/

/**************************************************************************//**
\brief Initialization function for the cluster
******************************************************************************/
void ciArmcluster0Init(void)
{
    /* Executes only for Reportable Client. */
    ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_COMBINED_INTERFACE, ARMCLUSTER0_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);

    if (cluster)
        cluster->ZCL_ReportInd = ciArmcluster0ReportInd;

    cluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;


    // Fill definition here
}

/**************************************************************************//**
\brief Report attribute indication handler

\param[in] addressing - pointer to addressing information;
\param[in] reportLength - data payload length;
\param[in] reportPayload - data pointer
******************************************************************************/
static void ciArmcluster0ReportInd(ZCL_Addressing_t *addressing, uint8_t reportLength, uint8_t *reportPayload)
{
    APP_Zigbee_Event_t eventItem;
    eventItem.eventGroup = EVENT_CLUSTER;
    eventItem.eventId = CMD_ZCL_REPORTING_ARMCLUSTER0; //defined in app_zigbee_handler
    eventItem.eventData.zclEventData.addressing = addressing;
    eventItem.eventData.zclEventData.payloadLength = reportLength;
    eventItem.eventData.zclEventData.payload = reportPayload;

  APP_Zigbee_Handler(eventItem);
}

/**************************************************************************//**
\brief Callback on receiving Armorientationservercommand command

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer

\return status of indication routine
******************************************************************************/
ZCL_Status_t ciArmorientationservercommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armorientationservercommand_t *payload)
{
    appSnprintf("Commands: ciArmorientationservercommandInd \r\n");
    //fill definition
}
/**************************************************************************//**
\brief Callback on receiving Armmovementservercommand command

\param[in] addressing - pointer to addressing information;
\param[in] payloadLength - data payload length;
\param[in] payload - data pointer

\return status of indication routine
******************************************************************************/
ZCL_Status_t ciArmmovementservercommandCommandInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armmovementservercommand_t *payload)
{
    appSnprintf("Commands: ciArmmovementservercommandInd \r\n");
    //fill definition
}
/**************************************************************************//**
\brief Sends Armorientationclientcommand command

\param[in] mode     - address mode;
\param[in] addr     - short address of destination node;
\param[in] ep       - destination endpoint;
\param[in] srcEp    - source endpoint;
******************************************************************************/
ZCL_Status_t ciSendArmorientationclientcommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint 
    ,uint8_t armOrientationParam )
{
    //fill definition
}
/**************************************************************************//**
\brief Sends Armmovementclientcommand command

\param[in] mode     - address mode;
\param[in] addr     - short address of destination node;
\param[in] ep       - destination endpoint;
\param[in] srcEp    - source endpoint;
******************************************************************************/
ZCL_Status_t ciSendArmmovementclientcommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint 
    ,uint8_t armMovementParam )
{
    //fill definition
}

