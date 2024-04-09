// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Start Router Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeStartRouter.h

  Summary:
    This file contains the NLME-START-ROUTER interface.

  Description:
    This file contains the NLME-START-ROUTER interface.
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

#if !defined _NLME_START_ROUTER_H
#define _NLME_START_ROUTER_H

/******************************************************************************
                              Includes section
 ******************************************************************************/
#include <mac_phy/include/mac.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                               Types section
 ******************************************************************************/
/** NLME-START-ROUTER confirm primitive's parameters structure declaration.ZigBee Specification r17, 3.2.2.7 NLME-START-ROUTER.confirm */
typedef struct _NWK_StartRouterConf_t
{
  /** The result of the attempt to initialize a ZigBee router.
   * Valid range: NWK_INVALID_REQUEST_STATUS or any status value returned from
   * the MAC_StartConf callback.*/
  NWK_Status_t status;
} NWK_StartRouterConf_t;

/** NLME-START-ROUTER request primitive's parameters structure declaration.Zigbee Specification r17, 3.2.2.8 NLME-START-ROUTER.request. */
typedef struct _NWK_StartRouterReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
    MAC_StartReq_t macStart;
  } service;
  /* The parameter tunes joining. It defines the joining method. */
  NWK_JoinControl_t ctrl;
  /* NLME-START-ROUTER confirm callback function's pointer. */
  void (*NWK_StartRouterConf)(NWK_StartRouterConf_t *conf);
  /** NLME-START-ROUTER confirm primitive's parameters */
  NWK_StartRouterConf_t confirm;
} NWK_StartRouterReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-START-ROUTER request primitive's prototype.

  \param[in] req - NLME-START-ROUTER request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_StartRouterReq(NWK_StartRouterReq_t *const req);

#endif /* _NLME_START_ROUTER_H */
/** eof nlmeStartRouter.h */

