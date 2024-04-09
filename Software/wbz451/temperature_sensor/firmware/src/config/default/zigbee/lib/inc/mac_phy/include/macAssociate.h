/*******************************************************************************
  MAC Association Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macAssociate.h

  Summary:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    association primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    association primitives.
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

#ifndef _MACASSOCIATE_H
#define _MACASSOCIATE_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysEndian.h>
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macCommon.h>
#include <mac_phy/include/macCommStatus.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/

/******************************************************************************
                        Types section.
******************************************************************************/
/**
  \brief MAC capability information field.
  IEEE 802.15.4-2006 7.3.1.2 Capability Information field.
*/
BEGIN_PACK
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(7, (
    uint8_t alternatePANCoordinator : 1,
    uint8_t deviceType              : 1,
    uint8_t powerSource             : 1,
    uint8_t rxOnWhenIdle            : 1,
    uint8_t reserved                : 2,
    uint8_t securityCapability      : 1,
    uint8_t allocateAddress         : 1
  ))
}  MAC_CapabilityInf_t;
END_PACK

/**
  \brief MLME-ASSOCIATE confirm primitive's parameters structure declaration.
  IEEE 802.15.4-2006 7.1.3.4 MLME-ASSOCIATE.confirm.
*/
typedef struct
{
  //! The short device address allocated by the coordinator on successful association.
  ShortAddr_t   shortAddr;
  //! The extended device address of coordinator wich allocated short address.
  //! It's additional parameter, not included in IEEE 802.15.4.
  ExtAddr_t     extAddr;
  //! LQI value measured during reception of the association response command.
  uint8_t       lqi;
  //! RSSI value measured during  reception of the MPDU. Non-standard addition.
  int8_t        rssi;
  //! The status of the association attempt.
  MAC_Status_t  status;
}  MAC_AssociateConf_t;

/**
  \brief MLME-ASSOCIATE request primitive's parameters structure declaration.
  IEEE 802.15.4-2006 7.1.3.1 MLME-ASSOCIATE.request.
*/
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t       service;
  //! The logical channel on which to attempt association.
  uint8_t             channel;
  //! The channel page on which to attempt association.
  uint8_t             page;
  //! The coordinator addressing mode for this primitive.
  MAC_AddrMode_t      coordAddrMode;
  //! The identifier of the PAN with which to associate.
  PanId_t             coordPANId;
  //! The address of the coordinator with which to associate.
  MAC_Addr_t          coordAddr;
  //! Specifies the operational capabilities of the associating device.
  MAC_CapabilityInf_t capability;
  //! MLME-ASSOCIATE confirm callback fubction's pointer.
  void (*MAC_AssociateConf)(MAC_AssociateConf_t *conf);
  //! MLME-ASSOCIATE confirm parameters' structure.
  MAC_AssociateConf_t confirm;
}  MAC_AssociateReq_t;

/**
  \brief MLME-ASSOCIATE indication primitive's parameters.
  IEEE 802.15.4-2006 7.1.3.2 MLME-ASSOCIATE.indication.
*/
typedef struct
{
  //! The address of the device requesting association.
  ExtAddr_t           extAddr;
  //! The operational capabilities requesting association.
  MAC_CapabilityInf_t capability;
  //! LQI value measured during reception of the association request command.
  uint8_t             lqi;
  //! RSSI value measured during  reception of the MPDU. Non-standard addition.
  int8_t              rssi;
}  MAC_AssociateInd_t;

/**
  \brief MLME-ASSOCIATE response pritive's parameters.
  IEEE 802.15.4-2006 7.1.3.3 MLME-ASSOCIATE.response.
*/
typedef struct
{
  //! Service field - for internal needs.
  MAC_ServiceTransaction_t service;
  //! The address of the device requesting association.
  ExtAddr_t     extAddr;
  //! The 16-bit short device address allocated by the coordinator on successful association.
  ShortAddr_t   shortAddr;
  //! The status of the association attempt.
  MAC_Status_t  status;
  //! MLME-COMM STATUS callback function's pointer.
  void (*MAC_CommStatusInd)(MAC_CommStatusInd_t *commStat);
  //! Comm staus parameters' structure.
  MAC_CommStatusInd_t commStatus;
}  MAC_AssociateResp_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-ASSOCIATE request primitive's prototype.
  \param reqParams - MLME-ASSOCIATE request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_AssociateReq(MAC_AssociateReq_t *reqParams);

/**************************************************************************//**
  \brief MLME-ASSOCIATE indication primitive's prototype.
  \param indParams - MLME-ASSOCIATE indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_AssociateInd(MAC_AssociateInd_t *indParams);

/**************************************************************************//**
  \brief MLME-ASSOCIATE response primitive's prototype.
  \param respParams - MLME-ASSOCIATE response parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_AssociateResp(MAC_AssociateResp_t *respParams);

#endif //_MACASSOCIATE_H
// eof macAssociate.h
