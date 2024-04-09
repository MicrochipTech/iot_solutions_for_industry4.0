
/*******************************************************************************
 Zigbee APIs Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zgb_api.h

  Summary:
    This file contains the Zgp Api's for this project.

  Description:
    This file contains the packing zgb requests and send them to zigbee stack through SVC
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

#ifndef ZGB_API_H
#define ZGB_API_H
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <osal/osal_freertos_extend.h>
#include <bdb/include/bdb.h>
#include <zdo/include/zdo.h>

#define QUEUE_LENGTH (8)
#define QUEUE_ITEM_SIZE (sizeof(void *))

typedef enum
{
  ZIGBEE_NONE,
  ZIGBEE_BDB,
  ZIGBEE_ZCL,
  ZIGBEE_CS,
  ZIGBEE_ZDO,
  ZIGBEE_NWK,
} eMODULE_ID;

typedef enum
{
  ZDO_ResetNwkConf_ID,
  ZDO_MgmtNwkUpdateNotf_ID,
  ZDO_WakeUpInd_ID,
  ZDO_BindIndication_ID,
  ZDO_UnbindIndication_ID,
  ZDO_APP_CALLBACK_MAX
}eZDO_AppGenericCB;

typedef enum
{
  BDB_Connected_ID,
  BDB_Event_Disconnected_ID,
  BDB_Event_IdentifyStartIndication_ID,
  BDB_Event_IdentifyStopIndication_ID,
  BDB_Event_UpdateNetworkIndication_ID,
  BDB_Event_QeryingCompleted_ID,
  BDB_Event_JoinNetworkIndication_ID,
  BDB_Event_TouchlinkCompleted_ID,
  BDB_Event_NetworkFormationCompleted_ID,
  BDB_Event_NetworkSteeringCompleted_ID,
  BDB_Event_FindingBindingCompleted_ID,
  BDB_Event_ResetToFactoryDefaults_ID,
  BDB_Event_TclkProcedureOngoing_ID,
  BDB_Event_TclkProcedureCompleted_ID,
  BDB_Event_AddingBindingLinks_ID,
  BDB_Event_Querying_ID,
  BDB_Event_Scanning_ID,
  BDB_Event_Identifying_ID,
  BDB_Event_Joining_ID,
  BDB_Event_ScanIndication_ID,
  BDB_Event_SteeringNetwork_ID,
  BDB_Event_FindingBindingInitiatorModeCompleted_ID,
  BDB_CommissioningConfCallback_ID,

  BDB_APP_CALLBACK_MAX
}eBDB_AppGenericCB;

typedef void (*unpack_ptr)(void *);
typedef void (*ZDO_CALLBACK_ptr)(void *);

typedef struct
{
  uint8_t eModuleID;  // BDB,ZCL etc
  uint8_t paramSize;
  uint32_t uCallBackID;       // API/Function ID in the respctive module
  void *parameters;
} ZB_AppGenericCallbackParam_t;

typedef void (*ZB_AppGenericCallBack)(ZB_AppGenericCallbackParam_t *inParams);

typedef struct
{
  unpack_ptr unpack_fn;
  void *parameters;      // Function Parameters 
} Stack_API_Request_t;

/******************************************************************************
                    Protoypes section
******************************************************************************/
void ZIGBEE_API_CALL(Stack_API_Request_t *request);
void zigbee_task(void *ptr);
void ZB_EventRegister(ZB_AppGenericCallBack app_ZBStackCb);

#endif // ZGB_API_H
