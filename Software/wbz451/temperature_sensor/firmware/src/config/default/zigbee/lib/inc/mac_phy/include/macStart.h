/*******************************************************************************
  MAC Start Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macStart.h

  Summary:
    This file provides access to the MAC Start Request primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    start primitives.
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

#ifndef _MACSTART_H
#define _MACSTART_H

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
 * \brief MLME-START confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.14.2 MLME-START.confirm.
 */
typedef struct
{
  //! The result of the attempt to start using an updated superframe configuration.
  MAC_Status_t status;
}  MAC_StartConf_t;

/**
 * \brief MLME-START request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.14.1 MLME-START.request.
 */
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t service;
  //! The PAN identifier to be used by the device.
  PanId_t       panId;
  //! The logical channel on which to start using the new configuration.
  uint8_t       channel;
  //! The channel page on which to begin using the new configuration.
  uint8_t       page;
  // NOT used - superframe functionality is not implemented.
  //uint8_t     beaconOrder;
  // NOT used - superframe functionality is not implemented.
  //uint8_t     superframeOrder;
  //! If this value is TRUE, the device will become the PAN coordinator of a new PAN.
  bool          panCoordinator;
  // NOT used - superframe functionality is not implemented.
  //bool        batteryLifeExt;
  //! TRUE if a coordinator realignment command is to be transmitted prior to
  //! changing the superframe configuration or FALSE otherwise. TBD.
  bool          coordRealignment;
  //! MLME-START confirm callback fubction's pointer.
  void (*MAC_StartConf)(MAC_StartConf_t *conf);
  //! MLME-START confirm parameters' structure.
  MAC_StartConf_t confirm;
}  MAC_StartReq_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-START request primitive's prototype.
  \param reqParams - MLME-START request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_StartReq(MAC_StartReq_t *reqParams);

#endif /* _MACSTART_H */

// eof macStart.h
