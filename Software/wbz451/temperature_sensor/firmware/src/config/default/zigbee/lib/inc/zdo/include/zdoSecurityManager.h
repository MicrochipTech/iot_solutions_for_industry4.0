// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object security manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoSecurityManager.h

  Summary:
    The header file describes the constants, types and internal interface
    of ZDO security manager

  Description:
    The header file describes the constants, types and internal interface
    of ZDO security manager

 *******************************************************************************/


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

// DOM-IGNORE-BEGIN
#ifndef _ZDOSECURITYMANAGER_H
#define _ZDOSECURITYMANAGER_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <hal/include/appTimer.h>
#include <zdo/include/zdo.h>
#include <security/serviceprovider/include/sspHash.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
typedef enum
{
  ZDO_IDLE_SECURITY_STATE,
  ZDO_NORMAL_OPERATING_SECURITY_STATE,
  ZDO_WAITING_ESTABLISH_KEY_SECURITY_STATE,
  ZDO_WAITING_TRANSPORT_KEY_SECURITY_STATE,
  ZDO_WAITING_PARENT_AUTHENTICATION_SECURITY_STATE,
  ZDO_WAITING_CHILD_AUTHENTICATION_SECURITY_STATE,
  ZDO_APP_KEY_ESTABLISH_RESPONDER_SECURITY_STATE,
  ZDO_APP_KEY_ESTABLISH_INITIATOR_SECURITY_STATE,
  ZDO_STARTING_NORMAL_OPERATING_SECURITY_STATE,
  ZDO_FAIL_CONFIRM_SECURITY_STATE,
  ZDO_CONFIRM_APP_KEY_SECURITY_STATE,
  ZDO_WAITING_APP_KEY_SECURITY_STATE,
  ZDO_WAITING_TC_LINK_KEY_SECURITY_STATE,
  ZDO_VERIFY_KEY_REQ_STATE,
  ZDO_WAITING_CONFIRM_KEY_STATE,
} ZdoSecurityManagerState_t;

typedef struct
{
#ifdef _SECURITY_
  HAL_AppTimer_t             waitTimer;
  HAL_AppTimer_t             delayTimer;
#ifdef _LINK_SECURITY_
  union
  {
    APS_AuthenticateReq_t    apsAuthenticateReq;
#ifdef _HIGH_SECURITY_
    APS_EstablishKeyReq_t    apsEstablishKeyReq;
#endif // _HIGH_SECURITY_
//#ifdef _CUSTOM_4_SECURITY_MODE_
    APS_RequestKeyReq_t      apsRequestKeyReq;
    APS_VerifyKeyReq_t       apsVerifyKeyReq;
    APS_ConfirmKeyReq_t     apsConfirmKeyReq;
//#endif // _CUSTOM_4_SECURITY_MODE_
  };
#ifdef _HIGH_SECURITY_
  APS_EstablishKeyResp_t     apsEstablishKeyResp;
#endif // _HIGH_SECURITY_
  ZDO_EndToEndAppKeyReq_t   *appKeyReq;
#endif // _LINK_SECURITY_
#endif // _SECURITY_
  ZdoSecurityManagerState_t state;
#ifdef _SECURITY_
  uint8_t                    newKeySeqNum;
#endif // _SECURITY_
} ZdoSecurityManager_t;

/******************************************************************************
                                Types section
 ******************************************************************************/
#if defined _SECURITY_ && defined _LINK_SECURITY_
/* Confirmation callback for Key Verification */
typedef void(*ZDO_VerifyKeyConf_t)(APS_VerifyKeyConf_t *conf);

/* Request for key verification */
typedef struct _ZDO_VerifiKeyReq_t_
{
  uint32_t timeout;
  void(*verifyKeyConf)(APS_VerifyKeyConf_t *conf);
  APS_VerifyKeyConf_t conf;
}ZDO_VerifiKeyReq_t;
#endif //#if defined _SECURITY_ && defined _LINK_SECURITY_

/******************************************************************************
                                Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief ZdoResetSecurityManager.
  
  \return None
 ******************************************************************************/
void zdoResetSecurityManager(void);

/**************************************************************************//**
  \brief zdoAuthenticationStart.
  
  \return None
 ******************************************************************************/
void zdoAuthenticationStart(void);

/**************************************************************************//**
  \brief zdoAuthenticationConf.
  
  \return None
 ******************************************************************************/
void zdoAuthenticationConf(ZDO_Status_t status);

/**************************************************************************//**
  \brief ZDO_GetPreconfiguredStatus
  
  \return None
 ******************************************************************************/
uint8_t ZDO_GetPreconfiguredStatus(void);

/**************************************************************************//**
  \brief zdoAuthenticateChild
  
  \return None
 ******************************************************************************/
void zdoAuthenticateChild(const ExtAddr_t *childAddr);

/**************************************************************************//**
  \brief zdoSecurityManagerHandler
  
  \return None
 ******************************************************************************/
void zdoSecurityManagerHandler(void);

#if defined _SECURITY_ && defined _LINK_SECURITY_

/**************************************************************************//**
  \brief Confirmation callback for Key Verification, this will provide a status of Verify Key request 
  \param[in] conf - zdoKeyHashMacConf
  \return None
 ******************************************************************************/
void zdoKeyHashMacConf(SSP_KeyedHashMacConf_t *conf);

/**************************************************************************//**
  \brief This API supports Verify Key request. The current version only supports TC link key verification 
  \param[in] zdoVerifyKeyReq - ZDO_VerifyKeyReq 
  \return None
 ******************************************************************************/
void ZDO_VerifyKeyReq(ZDO_VerifiKeyReq_t *zdoVerifyKeyReq);
#endif //#if defined _SECURITY_ && defined _LINK_SECURITY_
#endif // _ZDOSECURITYMANAGER_H

// eof zdoSecurityManager.h
