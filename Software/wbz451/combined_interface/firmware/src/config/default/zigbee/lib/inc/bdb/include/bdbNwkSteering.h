/*******************************************************************************
  BDB NwkSteering Header File

  Company
    Microchip Technology Inc.

  File Name
    bdbNwkSteering.h

  Summary
    bdb Nwk Steering interface.

  Description
    This header file defines the interface to the internal BDB network steering functions.
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

#ifndef _BDB_NWK_STEERING_H
#define _BDB_NWK_STEERING_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/
#include "zllplatform/infrastructure/N_Task/include/N_Task.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief State machine initialization routine
******************************************************************************/
void bdbNwkSteering_FsmInit(void);

/**************************************************************************//**
\brief bdb internal API to Trigger Network Steering

\param[in] callback - callback function to be called once the operation is finished
******************************************************************************/
void bdbTriggerNwkSteering (void (*callback) (BDB_CommissioningStatus_t));

/**************************************************************************//**
\brief The event handler for the component's task

\param[in] evt - event to process
\return true if event is handled, false - otherwise
******************************************************************************/
bool bdbNwkSteering_EventHandler(N_Task_Event_t evt);

#endif // _BDB_NWK_STEERING_H