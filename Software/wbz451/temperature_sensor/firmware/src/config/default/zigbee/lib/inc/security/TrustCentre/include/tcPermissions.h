/*******************************************************************************
  TrustCentre Permissions Header File

  Company:
    Microchip Technology Inc.

  File Name:
    tcPermissions.h

  Summary:
    This file contains the Interface of the Trust Center permissions configurations.

  Description:
    This file contains the Interface of the Trust Center permissions configurations.
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


#if !defined _TC_PERMISSIONS_H
#define _TC_PERMISSIONS_H

#include <aps/include/apsAIB.h>

#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Enable/Disable TC policy allowJoins.

  \param[in] allowJoin - TRUE, allowJoins will be enabled. FALSE, otherwise.
  \return None.
 ******************************************************************************/
void TC_SetAllowJoins(bool allowJoin);

/**************************************************************************//**
  \brief Checks whether TC policy allowJoins is enabled ot not.

  \param None.
  \return TRUE, if allowJoins is enabled. FALSE, otherwise.
 ******************************************************************************/
bool TC_IsAllowJoins();

/**************************************************************************//**
  \brief Enable/Disable TC policy allowRemoteTCPolicyChange

  \param[in] allowJoin - TRUE, allowRemoteTCPolicyChange will be enabled. FALSE, otherwise.
  \return None.
 ******************************************************************************/
void TC_SetAllowRemoteTCPolicyChange(bool allowRemoteTCPolicyChange);

/**************************************************************************//**
  \brief Checks whether TC policy allowRemoteTCPolicyChange is enabled ot not.

  \param None.
  \return TRUE, if allowRemoteTCPolicyChange is enabled. FALSE, otherwise.
 ******************************************************************************/
bool TC_IsAllowRemoteTCPolicyChange(void);

/**************************************************************************//**
  \brief Enable/Disable TC policy allowRejoins.

  \param[in] allowRejoin - TRUE, allowRejoins will be enabled. FALSE, otherwise.
  \return None.
 ******************************************************************************/
void TC_SetAllowRejoins(bool allowRejoin);

/**************************************************************************//**
  \brief Checks whether TC policy allowRejoins is enabled ot not.

  \param None.
  \return TRUE, if allowRejoins is enabled. FALSE, otherwise.
 ******************************************************************************/
bool TC_IsAllowRejoins();

/**************************************************************************//**
  \brief Enable/Disable TC policy allowInstallCodes.

  \param[in] allowInstallCodes - TRUE, allowInstallCodes will be enabled. FALSE, otherwise.
  \return None.
 ******************************************************************************/
void TC_SetAllowInstallCodes(bool allowInstallCodes);

/**************************************************************************//**
  \brief Checks whether TC policy allowInstallCodes is enabled ot not.

  \param None.
  \return TRUE, if allowInstallCodes is enabled. FALSE, otherwise.
 ******************************************************************************/
bool TC_IsAllowInstallCodes();

/**************************************************************************//**
  \brief Initialize TC policies.

  \param[in] policy - TC policies.
  \return None.
 ******************************************************************************/
void TC_InitializePolicy(APS_TCSecurityPolicy_t *policy);

#endif //#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#endif //#if !defined _TC_PERMISSIONS_H
