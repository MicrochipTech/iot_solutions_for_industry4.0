// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Permit Joining Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmePermitJoining.h

  Summary:
    This file contains the NLME-PERMIT-JOINING interface.

  Description:
    This file contains the NLME-PERMIT-JOINING interface.
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

#if !defined _NLME_PERMIT_JOINING_H
#define _NLME_PERMIT_JOINING_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                               Definitions section
 ******************************************************************************/
/** Permissions flags of network rejoin. */
#define NWK_ALLOW_REJOIN 0U
/** End Devices can't rejoin to this device. */
#define NWK_BAN_ED_REJOIN 1U
/** Routers can't rejoin to this device. */
#define NWK_BAN_ROUTER_REJOIN 2U
#define NWK_BAN_REJOIN \
  ((NWK_RejoinPermit_t)(NWK_BAN_ED_REJOIN | NWK_BAN_ROUTER_REJOIN))

/******************************************************************************
                                 Types section
 ******************************************************************************/
 
/** NLME-PERMIT-JOINING confirm primitive's parameters structure.ZigBee Specification r17, 3.2.2.6 NLME-PERMIT-JOINING.confirm, page 276. */
typedef struct _NWK_PermitJoiningConf_t
{
  /** The status of the corresponding request. Valid Range: NWK_SUCCESS_STATUS
   * or any status returned from the MLME-SET.confirm primitive. */
  NWK_Status_t status;
} NWK_PermitJoiningConf_t;

/** NLME-PERMIT-JOINING request primitive's parameters structure. Zigbee Specification r17, 3.2.2.5 NLME-PERMIT-JOINING.request, page 274. */
typedef struct _NWK_PermitJoiningReq_t
{
 /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  } service;
  /** The length of time in seconds during which the ZigBee coordinator or
   * router will allow associations. The value 0x00 and 0xff indicate that
   * permission is disabled or enabled, respectively,
   * without a specified time limit. */
  uint8_t permitDuration;
  /** NLME-PERMIT-JOINING confirm callback function's pointer. */
  void (*NWK_PermitJoiningConf)(NWK_PermitJoiningConf_t *conf);
  NWK_PermitJoiningConf_t confirm;
} NWK_PermitJoiningReq_t;

/** Type of rejoin permissions to the given devices. */
typedef uint8_t NWK_RejoinPermit_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-PERMIT-JOINING request primitive's prototype.

  \param[in] req - NLME-PERMIT-JOINING request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_PermitJoiningReq(NWK_PermitJoiningReq_t *const req);

/**************************************************************************//**
  \brief Enable or disable an end deivce or a router rejoin.

  \param[in] permit - rejoin permissions, allow an end device rejoin only
                      if NWK_BAN_ED_REJOIN bit isn't set, and allow a router
                      rejoin only if NWK_BAN_ROUTER_REJOIN flag isn't set.
  \return None.
 ******************************************************************************/
void NWK_SetRejoinPermit(const NWK_RejoinPermit_t permit);

#endif /* _NLME_PERMIT_JOINING_H */
/** eof nlmePermitJoining.h */

