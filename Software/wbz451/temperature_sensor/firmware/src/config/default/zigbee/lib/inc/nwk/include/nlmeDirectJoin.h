// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Direct Join Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeDirectJoin.h

  Summary:
    This file contains the Network Layer Management Entity Direct join primitives.

  Description:
    This file contains the Network Layer Management Entity Direct join primitives.
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

#if !defined _NLME_DIRECT_JOIN_H
#define _NLME_DIRECT_JOIN_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** NLME-DIRECT-JOIN confirm primitive's parameters structure declaration. ZigBee Specification r17, 3.2.2.15 NLME-DIRECT-JOIN.confirm, page 287. */
typedef struct _NWK_DirectJoinConf_t
{
  /** The status of the corresponding request. */
  NWK_Status_t status;
} NWK_DirectJoinConf_t;

/** NLME-DIRECT-JOIN request primitive's parameters structure declaration. Zigbee Specification r17, 3.2.2.14 NLME-DIRECT-JOIN.request, page 286. */
typedef struct _NWK_DirectJoinReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  } service;
  /** The IEEE address of the device to be directly joined.*/
  ExtAddr_t deviceAddress;
  /** Recommended network address. */
  ShortAddr_t networkAddress;
  /** The operating capabilities of the device being directly joined. */
  MAC_CapabilityInf_t capabilityInformation;
  /** NLME-DIRECT-JOIN confirm callback function's pointer. */
  void (*NWK_DirectJoinConf)(NWK_DirectJoinConf_t *conf);
  NWK_DirectJoinConf_t confirm;
} NWK_DirectJoinReq_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-DIRECT-JOIN request primitive's prototype.

  \param[in] req - NLME-DIRECT-JOIN request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_DirectJoinReq(NWK_DirectJoinReq_t *const req);

#endif /* _NLME_DIRECT_JOIN_H */
/** eof nlmeDirectJoin.h */

