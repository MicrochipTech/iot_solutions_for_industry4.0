/*******************************************************************************
  TrustCentre Authentication Header File

  Company:
    Microchip Technology Inc.

  File Name:
    tcAuthentic.h

  Summary:
    This file contains the Security Trust Centre authentic primitive.

  Description:
    This file contains the Security Trust Centre authentic primitive.
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


#ifndef _TCAUTHENTICH
#define _TCAUTHENTICH

/******************************************************************************
                             Include section.
******************************************************************************/
#include <aps/include/aps.h>

/******************************************************************************
                             Types section.
******************************************************************************/
typedef enum _TcAuthObjState_t
{
  TC_AUTHENTIC_OBJ_STATE_IDLE,
  TC_AUTHENTIC_OBJ_STATE_TRANSPORTING_NETWORK_KEY,
  TC_AUTHENTIC_OBJ_STATE_TRANSPORTING_MASTER_KEY,
  TC_AUTHENTIC_OBJ_STATE_ESTABLISHING_KEY,
  TC_AUTHENTIC_OBJ_STATE_REMOVING_DEVICE,
} TcAuthObjState_t;

/**************************************************************************//**
  \brief Authentic handler memory object.

  This struct declares memory wichshould be reserved for the Trust Centre
  Authentication proceure.
******************************************************************************/
typedef struct
{
  //! Memory to store source address of APS_UpdateDeviceInd command.
  ExtAddr_t updateIndSrcAddr;
  union
  { //! Memory for APS_TransportKeyReq.
    APS_TransportKeyReq_t transportKey;
    //! Memory for APS_RemoveDeviceReq.
    APS_RemoveDeviceReq_t removeDevice;
#if defined _LINK_SECURITY_ && defined _HIGH_SECURITY_
    //! Memory for APS_EstablishKeyReq.
    APS_EstablishKeyReq_t establishKey;
#endif
  } buffer;
  //! Current state for Trust Centre authentic handler.
  TcAuthObjState_t state;
} TC_AuthenticObj_t;

#endif // _TCAUTHENTICH

// eof tcAuthentic.h
