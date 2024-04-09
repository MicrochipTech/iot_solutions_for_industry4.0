// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Reset Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeReset.h

  Summary:
    This file contains the NLME-RESET interface.

  Description:
    This file contains the NLME-RESET interface.
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

#if !defined _NLME_RESET_H
#define _NLME_RESET_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** NLME-RESET confirm primitive's parameters structure declaration.ZigBee Specification r17, 3.2.2.20 NLME-RESET.confirm, page 293. */
typedef struct _NWK_ResetConf_t
{
  /** The result of the reset operation. */
  NWK_Status_t status;
} NWK_ResetConf_t;

/** NLME-RESET request primitive's parameters structure declaration.Zigbee Specification r17, 3.2.2.19 NLME-RESET.request, page 292. */
typedef struct _NWK_ResetReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  } service;
  /** NLME-RESET confirm callback function's pointer. */
  void (*NWK_ResetConf)(NWK_ResetConf_t *conf);
  NWK_ResetConf_t confirm;
} NWK_ResetReq_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-RESET request primitive's prototype.

  \param[in] req - NLME-RESET request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_ResetReq(NWK_ResetReq_t *const req);

#endif  /* _NLME_RESET_H */
/** eof nlmeReset.h */

