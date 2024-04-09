/*******************************************************************************
  ZLL EndDevice Robustness Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_EndDeviceRobustness.h

  Summary:
    This file contains the ZLL EndDevice Robustness functions.

  Description:
    This file contains the ZLL EndDevice Robustness functions.
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


#ifndef N_END_DEVICE_ROBUSTNESS_H
#define N_END_DEVICE_ROBUSTNESS_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _EndDeviceRobustnessState_t
{
  N_END_DEVICE_ROBUSTNESS_IDLE,
  N_END_DEVICE_ROBUSTNESS_CONNECTED,
  N_END_DEVICE_ROBUSTNESS_DISCONNECTED,
  N_END_DEVICE_ROBUSTNESS_WAIT_FOR_CONFIRM,
  N_END_DEVICE_ROBUSTNESS_TX_FAILURE,
  N_END_DEVICE_ROBUSTNESS_POLL_FAILURE
} EndDeviceRobustnessState_t;

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

/**************************************************************************//**
  \brief Performs APS data request.

  \param apsDataReq - pointer to the request.
******************************************************************************/
void N_EndDeviceRobustness_DataRequest(APS_DataReq_t *apsDataReq);

/**************************************************************************//**
  \brief Performs ZDP request.

  \param apsDataReq - pointer to the request.
******************************************************************************/
void N_EndDeviceRobustness_ZdpRequest(ZDO_ZdpReq_t *zdpReq);

/**************************************************************************//**
  \brief Returns current state of N_EndDeviceRobustness component.
******************************************************************************/
EndDeviceRobustnessState_t N_EndDeviceRobustness_GetState(void);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_END_DEVICE_ROBUSTNESS_H
