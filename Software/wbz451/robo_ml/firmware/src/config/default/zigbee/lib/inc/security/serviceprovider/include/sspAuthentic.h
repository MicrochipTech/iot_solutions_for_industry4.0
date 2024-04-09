/*******************************************************************************
  Security Service Provider Authentication Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sspAuthentic.h

  Summary:
    This file contains the Mutual Symmetric-Key Entity Authentication routine Declaration.

  Description:
    This file contains the Mutual Symmetric-Key Entity Authentication routine Declaration.
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


#ifndef _SSPAUTHENTIC_H
#define _SSPAUTHENTIC_H

#ifdef _LINK_SECURITY_
/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <security/serviceprovider/include/sspCommon.h>
#include <security/serviceprovider/include/sspChallengeGen.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/
#define HASH_SIZE 16

/******************************************************************************
                        Types' definition section.
******************************************************************************/

/**************************************************************************//**
  \brief Declaration of CalculateAuthenticParamsConf primitive parameters structure.
******************************************************************************/
typedef struct
{
  //! Calculated MacTag1 or MacTag2.
  uint8_t macTag[HASH_SIZE];
} SSP_CalculateAuthenticParamsConf_t;

/**************************************************************************//**
  \brief Declaration of CalculateAuthenticParamsConf primitive parameters structure.
******************************************************************************/
typedef struct
{
  //! Service field - for internal needs.
  SSP_Service_t service;
  //! Extended address of the device which initiated authnetication procedure.
  const uint64_t *initiatorIEEEAddr;
  //! Extended address of the device which should response.
  const uint64_t *responderIEEEAddr;
  //! Initiator or responder device frame counter.
  uint32_t frameCounter;
  //! Preset key which should be known by both devices (initiator and responder).
  const uint8_t *networkKey/*[SECURITY_KEY_SIZE]*/;
  //! Initiator challenge sequence (just 128-bit random number).
  uint8_t *qeu;
  //! Responder challenge sequence (just 128-bit random number).
  uint8_t *qev;
  //! Security Service Provider CalculateAuthenticParams confirm callback function's pointer.
  void (*SSP_CalculateAuthenticParamsConf)(SSP_CalculateAuthenticParamsConf_t *conf);
  //! Security Service Provider CalculateAuthenticParams confirm parameters' structure.
  SSP_CalculateAuthenticParamsConf_t confirm;
} SSP_CalculateAuthenticParamsReq_t;

/******************************************************************************
                        Prototypes section.
******************************************************************************/
/*******************************************************************************
  Performs calculation of the parameters for Mutual Symmetric-Key Entity
  Authentication procedure (MatTag1).
  Parameters:
    param - procedure parameters (for detailed description look at
             SSP_CalculateAuthenticParamsReq_t declaration).
  Return:
    none.
********************************************************************************/
void SSP_CalculateAuthenticMacTag1Req(SSP_CalculateAuthenticParamsReq_t *param);

/*******************************************************************************
  Performs calculation of the parameters for Mutual Symmetric-Key Entity
  Authentication procedure (MatTag2).
  Parameters:
    param - procedure parameters (for detailed description look at
             SSP_CalculateAuthenticParamsReq_t declaration).
  Return:
    none.
********************************************************************************/
void SSP_CalculateAuthenticMacTag2Req(SSP_CalculateAuthenticParamsReq_t *param);

#endif // _LINK_SECURITY_

#endif //_SSPAUTHENTIC_H

// eof sspAuthentic.h

