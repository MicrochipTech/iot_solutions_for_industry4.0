/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zigbee_app_header.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
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

#ifndef __APP_TASK_H__
#define __APP_TASK_H__

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <pds/include/wlPdsMemIds.h>
#include <bdb/include/bdb.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END
    
#define APP_COMMISSIONING_TOUCHLINK_VALUE                     0 //1
#define APP_COMMISSIONING_STEERING_VALUE                      1 //2
#define APP_COMMISSIONING_FORMING_VALUE                       2 //4
#define APP_COMMISSIONING_FINDING_AND_BINDING_VALUE           3 //8

/**@brief Define PDS mem ID needed for Provisioning */
enum{
    PDS_PROV_APP_ITEM_ID_1 = (PDS_MODULE_APP_OFFSET),
//    PDS_PROV_APP_ITEM_ID_2,
};    

#define PDS_APP_COMMISION_ID PDS_PROV_APP_ITEM_ID_1
#define PDS_APP_DEVICE_NAME_ID PDS_PROV_APP_ITEM_ID_2

extern OSAL_QUEUE_HANDLE_TYPE g_appQueue;
extern void ZDO_ResetNetworkConf_Callback (void *resp);
extern void ZDO_MgmtNwkUpdateNotf_CallBack(void *resp);
extern void ZDO_WakeUpInd_CallBack(void *resp);
extern void ZDO_BindIndication_CallBack(void *resp);
extern void ZDO_UnbindIndication_CallBack(void *resp);
extern void APP_ZigbeeStackInit();

#endif /* _APP_BLE_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
