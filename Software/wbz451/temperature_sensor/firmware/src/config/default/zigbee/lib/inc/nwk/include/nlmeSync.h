// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Synchronisation Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeSync.h

  Summary:
    This file provides the NLME-SYNC interface.

  Description:
    This file provides the NLME-SYNC interface.
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

#if !defined _NLME_SYNC_H
#define _NLME_SYNC_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** NLME-SYNC confirm primitive's parameters structure declaration. ZigBee Specification r17, 3.2.2.24 NLME-SYNC.confirm, page 296. */
typedef struct _NWK_SyncConf_t
{
  /** The result of the request to synchronize with the ZigBee coordinator or
   * router. Valid Range: NWK_SUCCESS_STATUS, NWK_INVALID_PARAMETER_STATUS,
   * or any status value returned from the MLME_POLL.confirm primitive. */
  NWK_Status_t status;
} NWK_SyncConf_t;

/** NLME-SYNC request primitive's parameters structure declaration. Zigbee Specification r17, 3.2.2.22 NLME-SYNC.request, page 294. */
typedef struct _NWK_SyncReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
  } service;
  /** Whether or not the synchronization should be maintained for future beacons.
   **/
  bool track;
  /** NLME-SYNC confirm callback function's pointer. Must not be set to NULL. */
  void (*NWK_SyncConf)(NWK_SyncConf_t *conf);
  NWK_SyncConf_t confirm;
} NWK_SyncReq_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-SYNC request primitive's prototype.

  The function sends a data request to the parent polling for buffered data. The confirmation callback is raised with NWK_SUCCESS_STATUS, if the
  request has been executed successfully and a response from the parents has been received. If the current node's parent is storing data frames
  for the child, then after sending response to the polling request it starts sending the data. When the child receives the data the standard callback
  idicating data frame reception is executed.

  \param[in] req - NLME-SYNC request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_SyncReq(NWK_SyncReq_t *const req);

#endif /* _NLME_SYNC_H */
/** eof nlmeSync.h */

