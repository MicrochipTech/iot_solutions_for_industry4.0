/*******************************************************************************
  TrustCentre Key Establishment Header File

  Company:
    Microchip Technology Inc.

  File Name:
    tcKeyEstablish.h

  Summary:
    This file contains the Security Trust Centre End to End Key Establish primitive.

  Description:
    This file contains the Security Trust Centre End to End Key Establish primitive.
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


#ifndef _TCKEYESTABLISH
#define _TCKEYESTABLISH

#include <security/serviceprovider/include/sspHash.h>
/**************************************************************************//**
  \brief Holds TCLK hash for TC and Device.
******************************************************************************/
typedef struct
{
  /* New TCLK */
  uint8_t linkKey[SECURITY_KEY_SIZE];
  /* TCLK hash calculated in TC */
  uint8_t tcHash[SECURITY_KEY_SIZE];
  /* TCLK hash of the device which is initiated TCLK verification */
  uint8_t senderHash[SECURITY_KEY_SIZE];
  /* Sender extended address */
  ExtAddr_t senderAddr;
  /* TCLK hash in TC */
  SSP_KeyedHashMacReq_t keyHashReq;
  /* Input text for key hashing */
  uint8_t text[32 + 1 + 32];
  /* Indicates TCLK verification is in progress */
} TcKeyHaskReq_t;

/******************************************************************************
                             Types section.
******************************************************************************/
/**************************************************************************//**
  \brief TBD.

  TBD
******************************************************************************/
typedef struct
{
  union
  {
    APS_TransportKeyReq_t transportKeyReq;
    APS_ConfirmKeyReq_t confirmKeyReq;
    TcKeyHaskReq_t  tcKeyHashReq;
  };
  //ExtAddr_t updateIndSrcAddr;
  uint8_t state;
} TC_KeyEstablishObj_t;

/******************************************************************************
                             Functions prototypes section.
******************************************************************************/
/**************************************************************************//**
  \brief TBD.

  \param TBD.
  \return TBD.
******************************************************************************/
#ifdef _LINK_SECURITY_
void APS_RequestKeyInd(APS_RequestKeyInd_t *indParams);
#endif // _LINK_SECURITY_

#endif // _LINK_SECURITY_

// eof tcKeyEstablish.h
