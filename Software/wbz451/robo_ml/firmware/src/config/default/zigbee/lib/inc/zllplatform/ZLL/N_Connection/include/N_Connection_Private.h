/*******************************************************************************
  ZLL Connection Private Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Connection_Private.h

  Summary:
    This file contains the ZLL Connection Private functions.

  Description:
    This file contains the ZLL Connection Private functions.
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


#ifndef N_CONNECTION_PRIVATE_H
#define N_CONNECTION_PRIVATE_H

/*******************************************************************************
* INCLUDE FILES
*******************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/*******************************************************************************
* C++ DECLARATION WRAPPER
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* EXPORTED FUNCTIONS
*******************************************************************************//**************************************************************************//**
  \brief Checks if LinkTarget set the InterPan mode to on

  \return TRUE if LinkTarget set the InterPan mode to on; FALSE - otherwise
 ******************************************************************************/
bool N_Connection_TargetIsInterpanModeOn(void);

/**************************************************************************//**
  \brief Component internal networkJoined notification

  \return None
 ******************************************************************************/
void N_Connection_RouterNetworkJoined(void);

/**************************************************************************//**
  \brief Component internal networkJoined notification

  \return None
 ******************************************************************************/
void N_Connection_NetworkJoined(void);

/**************************************************************************//**
  \brief Component internal networkJoined notification for enddevice

  \return None
 ******************************************************************************/
void N_Connection_EnddeviceNetworkJoined(void);

/**************************************************************************//**
  \brief Component internal networkJoined notification

  \return None
 ******************************************************************************/
void N_Connection_Connected(void);

/**************************************************************************//**
  \brief Component internal router connected  notification

  \return None
 ******************************************************************************/
void N_Connection_RouterConnected(void);

/**************************************************************************//**
  \brief Component internal ed connected notification

  \return None
 ******************************************************************************/
void N_Connection_EnddeviceConnected(void);

/**************************************************************************//**
  \brief Component internal networkJoined notification

  \return None
 ******************************************************************************/
void N_Connection_Disconnected(void);

/**************************************************************************//**
  \brief Component internal disconnected notification

  \return None
 ******************************************************************************/
void N_Connection_RouterDisconnected(void);

/**************************************************************************//**
  \brief Component internal disconnected notification

  \return None
 ******************************************************************************/
void N_Connection_EnddeviceDisconnected(void);

/**************************************************************************//**
  \brief Leave network routine.

  \return None
 ******************************************************************************/
void N_Connection_LeaveNetwork(void);

/**************************************************************************//**
  \brief Returns the state of Reconnect urgent.

  \return None
 ******************************************************************************/
bool N_Connection_Is_ReconnectUrgentOngoing(void);

/**************************************************************************//**
  \brief Returns the state of Reconnect.

  \return None
 ******************************************************************************/
bool N_Connection_Is_ReconnectOngoing(void);

/*******************************************************************************
* END OF C++ DECLARATION WRAPPER
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_CONNECTION_PRIVATE_H
