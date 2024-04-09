/*******************************************************************************
  Security Service Provider SKKE Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sspSkke.h

  Summary:
    This file contains the declaration for Security-Key Key Establishment routine.

  Description:
    This file contains the declaration for Security-Key Key Establishment routine.
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


#ifndef _SSPSKKE_H
#define _SSPSKKE_H

#ifdef _LINK_SECURITY_
/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <security/serviceprovider/include/sspCommon.h>
#include <security/serviceprovider/include/sspAuthentic.h>
#include <security/serviceprovider/include/sspChallengeGen.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/

/******************************************************************************
                        Types' definition section.
******************************************************************************/

/**************************************************************************//**
  \brief Declaration of CalculateSkkeParamsConf primitive parameters structure.
******************************************************************************/
typedef struct
{
  //! Calculated MacTag1.
  uint8_t macTag1[HASH_SIZE];
  //! Calculated MacTag2.
  uint8_t macTag2[HASH_SIZE];
  //! Calculated keyData.
  uint8_t keyData[HASH_SIZE];
} SSP_CalculateSkkeParamsConf_t;

/**************************************************************************//**
  \brief Declaration of CalculateSkkeParamsReq primitive parameters structure.
******************************************************************************/
typedef struct
{
  //! Service field - for internal needs.
  SSP_Service_t service;
  //! Extended address of the device which initiated SKKE procedure.
  const uint64_t *initiatorIEEEAddr;
  //! Extended address of the device which should response.
  const uint64_t *responderIEEEAddr;
  //! Preset key which should be known by both devices (initiator and responder).
  uint8_t *masterKey/*[SECURITY_KEY_SIZE]*/;
  //! Initiator challenge sequence (just 128-bit random number).
  uint8_t qeu[CHALLENGE_SEQUENCE_SIZE];
  //! Responder challenge sequence (just 128-bit random number).
  uint8_t qev[CHALLENGE_SEQUENCE_SIZE];
  //! Security Service Provider CalculateSkkeParams confirm callback function's pointer.
  void (*SSP_CalculateSkkeParamsConf)(SSP_CalculateSkkeParamsConf_t *conf);
  //! Security Service Provider CalculateSkkeParams confirm parameters' structure.
  SSP_CalculateSkkeParamsConf_t confirm;
} SSP_CalculateSkkeParamsReq_t;

/******************************************************************************
                        Prototypes section.
******************************************************************************/
/*******************************************************************************
  Performs calculation of the parameters for Symmetric key key establishment
  procedure.
  Parameters:
    param - SKKE procedure parameters (for detailed description look at
             SSP_CalculateSkkeParamsReq_t declaration).
  Return:
    none.
********************************************************************************/
void SSP_CalculateSkkeParamsReq(SSP_CalculateSkkeParamsReq_t *param);

#endif // _LINK_SECURITY_

#endif //_SSPSKKE_H

// eof sspSkke.h

