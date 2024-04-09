/*******************************************************************************
  MAC Polling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macPoll.h

  Summary:
    This file provides access to the MAC Poll Data Request Primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    data requesting primitives.
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

#ifndef _MACPOLL_H
#define _MACPOLL_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                        Defines section
******************************************************************************/


/******************************************************************************
                        Types section
******************************************************************************/
/**
 * \brief MLME-POLL confirm primitive's parameters structure.
 * IEEE 802.15.4-2006 7.1.16.2 MLME-POLL.confirm.
 */
typedef struct
{
  //! The status of the data request.
  MAC_Status_t status;
}  MAC_PollConf_t;

/**
 * \brief MLME-POLL request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.16.1 MLME-POLL.request.
 */
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t  service;
  //! The addressing mode of the coordinator to which the poll is intended.
  MAC_AddrMode_t coordAddrMode;
  //! The PAN identifier of the coordinator to which the poll is intended.
  PanId_t        coordPANId;
  //! The address of the coordinator to which the poll is intended.
  MAC_Addr_t     coordAddr;
  //! MLME-POLL callback function's pointer.
  void (*MAC_PollConf)(MAC_PollConf_t *conf);
  //! MLME-POLL confirm parameters' structure.
  MAC_PollConf_t confirm;
}  MAC_PollReq_t;

/**
 * \brief MLME-POLL indication primitive's parameters.
 * This primitive is not described in IEEE 802.15.4-2006. Non-standard addition.
 */
typedef struct
{
  //! The addressing mode of the device from which poll request is isued.
  MAC_AddrMode_t srcAddrMode;
  //! The PAN identifier of the device from which poll request is isued.
  PanId_t        srcPANId;
  //! The address of the device from which poll request is isued.
  MAC_Addr_t     srcAddr;
  //! LQI value measured during reception of the data request command.
  uint8_t        linkQuality;
  //! The DSN of the received data request command
  uint8_t        dsn;
  // RSSI value measured during  reception of the data request command.
  int8_t         rssi;
#ifdef _CHILD_MANAGEMENT_
	//! The DSN of the received data request command
	uint8_t 	 isUnknowChild;
#endif
}  MAC_PollInd_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-POLL indication primitive's prototype.
  \param indParams - MLME-POLL indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_PollInd(MAC_PollInd_t *indParams);


/**************************************************************************//**
  \brief MLME-POLL request primitive's prototype.
  \param reqParams - MLME-POLL request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_PollReq(MAC_PollReq_t *reqParams);

#endif /* _MACPOLL_H */

// eof macPoll.h
