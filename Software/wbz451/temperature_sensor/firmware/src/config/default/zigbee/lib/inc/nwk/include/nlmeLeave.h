// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Leave Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeLeave.h

  Summary:
    This file contains the Network Layer Management Entity Leave functionality.

  Description:
    This file contains the Network Layer Management Entity Leave functionality Handling.
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

#if !defined _NLME_LEAVE_H
#define _NLME_LEAVE_H

/******************************************************************************
                                 Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                  Types section
 ******************************************************************************/
/** NLME-LEAVE confirm primitive's parameters structure declaration.ZigBee Specification r17, 3.2.2.18 NLME-LEAVE.confirm, page 291. */
typedef struct _NWK_LeaveConf_t
{
  /** The status of the corresponding request.*/
  NWK_Status_t status;
} NWK_LeaveConf_t;

/** NLME-LEAVE request primitive's parameters structure declaration. Zigbee Specification r17, 3.2.2.16 NLME-LEAVE.request, page 288. */
typedef struct _NWK_LeaveReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
#ifdef _ZAPPSI_
    /* to be compatible with MAC and SSP service. */
    uint8_t requestId;
    /* Sequence number to identify request-response pair. */
    uint8_t sequenceNumber;
    union
    {
      /* Callback wrapper routine pointer */
      void (*callback)(void*);
      /* Processing routine pointer to call after required memory will become free */
      void (*process)(void*);
    } zsi;
#endif /* _ZAPPSI_ */
  } service;
  /** The 64-bit IEEE address of the entity to be removed from the network
   * or NULL if the device removes itself from the network. */
  ExtAddr_t deviceAddress;
    /** The short address of the entity to be removed from the network.
    * It is meaningful only if noExtendedAddress is TRUE. */
  ShortAddr_t shortAddress;

  /** Bit field to control of cleaning after leave */
  NWK_LeaveControl_t leaveControl;
  /** This parameter has a value of TRUE if the device being asked to leave the
   * network is also being asked to remove its child devices, if any. Otherwise,
   * it has a value of FALSE. */
  bool removeChildren;
  /** This parameter has a value of TRUE if the device being asked to leave from
   * the current parent is requested to rejoin the network.
   * Otherwise, the parameter has a value of FALSE. */
  bool rejoin;
#ifdef _CHILD_MANAGEMENT_
  /** This parameter has a value of TRUE if teh device being asked to send
   * leave request to another device using only its short address. */
  bool noExtendedAddress;
#endif /* _CHILD_MANAGEMENT_ */
  /** NLME-LEAVE confirm callback function's pointer. */
  void (*NWK_LeaveConf)(NWK_LeaveConf_t *conf);
  NWK_LeaveConf_t confirm;
} NWK_LeaveReq_t;

/** NLME-LEAVE indication primitive's parameters structure declaration.Zigbee Specification r17, 3.2.2.17 NLME-LEAVE.indication, page 290. */
typedef struct _NWK_LeaveInd_t
{
  /** The 64-bit IEEE address of an entity that has removed itself from
   * the network or NULL in the case that the device issuing the primitive has
   * been removed from the network by its parent. */
  ExtAddr_t deviceAddress;
  /** This parameter has a value of TRUE if the device being asked to leave the
   * current parent is requested to rejoin the network. Otherwise, this parameter
   * has a value of FALSE. */
  bool rejoin;
} NWK_LeaveInd_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-LEAVE request primitive's prototype.

  \param[in] req - NLME-LEAVE request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_LeaveReq(NWK_LeaveReq_t *const req);

/**************************************************************************//**
  \brief NLME-LEAVE indication primitive's prototype.

  \param[in] ind - NLME-LEAVE indication parameters' structure pointer.
  \return None.
 ******************************************************************************/
extern void NWK_LeaveInd(NWK_LeaveInd_t *ind);

#endif /* _NLME_LEAVE_H */
/** eof nlmeLeave.h */

