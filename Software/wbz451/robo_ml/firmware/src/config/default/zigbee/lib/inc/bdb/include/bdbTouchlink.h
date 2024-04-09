/*******************************************************************************
  BDB Touchlink Header File

  Company
    Microchip Technology Inc.

  File Name
    bdbTouchlink.h

  Summary
    bdb Nwk Touchlink interface.

  Description
    This header file defines the interface to the BDB touchlink functions.
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

#ifndef _BDB_TOUCHLINK_H
#define _BDB_TOUCHLINK_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/
#include "zllplatform/infrastructure/N_Task/include/N_Task.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/******************************************************************************
                    Defines section
******************************************************************************/
#define N_LinkTarget_Subscribe N_LinkTarget_Subscribe_Impl
#define N_LinkTarget_SetTargetType N_LinkTarget_SetTargetType_Impl
#define N_Cmi_InitMacLayer N_Cmi_InitMacLayer_Impl
/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief State machine initialization routine
******************************************************************************/
void bdbTouchlink_FsmInit(void);

typedef enum BDB_LinkTarget_Status_t
{
    /** The action succeeded. */
    BDB_LinkTarget_Status_Ok,

    /** The action failed. */
    BDB_LinkTarget_Status_Failure,

} BDB_LinkTarget_Status_t;


/**************************************************************************//**
\brief Describes the parameters of the BDB_SetTargetType() function
******************************************************************************/
typedef struct _BDB_SetTargetType
{
  uint8_t targetType;
    
  void (*BDB_SetTargetTypeConf)(BDB_LinkTarget_Status_t status);
}BDB_SetTargetType_t;

/**************************************************************************//**
\brief bdb API to set Target type

\param[in] req - request paramaters
******************************************************************************/
void BDB_SetTargetType(BDB_SetTargetType_t *req);

/**************************************************************************//**
\brief bdb internal API to Trigger Touchlink

\param[in] resetTargetToFN - if false- touchlink will be initiated, else resets the target
\param[in] initiatorReq - initiator parameters used for binding
\param[in] callback - callback function to be called once the operation is finished
******************************************************************************/
void bdbTriggerTouchlink (bool resetTargetToFN, BDB_InitiatorReq_t* initiatorReq, void (*callback) (BDB_CommissioningStatus_t));

/**************************************************************************//**
\brief The event handler for the component's task

\param[in] evt - event to process
\return true if event is handled, false - otherwise
******************************************************************************/
bool bdbTouchlink_EventHandler(N_Task_Event_t evt);

#endif // _BDB_TOUCHLINK_H