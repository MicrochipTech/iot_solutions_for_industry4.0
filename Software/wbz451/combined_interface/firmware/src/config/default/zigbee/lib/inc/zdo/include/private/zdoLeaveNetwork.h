// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object leave network Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoLeaveNetwork.h

  Summary:
    This file contains the Interface for ZDO Leave Network routines.

  Description:
    This file contains the Interface for ZDO Leave Network routines.
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

// DOM-IGNORE-BEGIN
#ifndef _ZDOLEAVENETWORK_H
#define _ZDOLEAVENETWORK_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/zdo.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                Definitions section
 ******************************************************************************/

/******************************************************************************
                                Types section
 ******************************************************************************/

typedef enum _ZdoLeaveNetworkState_t
{
  ZDO_LEAVE_NETWORK_IDLE_STATE,
  ZDO_LEAVE_NETWORK_NWK_LEAVE_STATE,
  ZDO_LEAVE_NETWORK_APS_STOP_STATE,
  ZDO_LEAVE_NETWORK_REMOTE_STATE
} ZdoLeaveNetworkState_t;


typedef void (ZdoLeaveNetworkConf_t)(ZDO_Status_t status);


typedef struct _ZdoLeaveNetwork_t
{
  ZdoLeaveNetworkConf_t  *confirm;
  NWK_LeaveControl_t     leaveControl;
  bool                   rejoin;
  ZdoLeaveNetworkState_t state;
} ZdoLeaveNetwork_t;

/******************************************************************************
                                Prototypes section
 ******************************************************************************/
 
 /**************************************************************************//**
  \brief Network leave indication

  \param[in] rejoin - true if rejoin is required
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoLeaveNetworkInd(bool rejoin);

/**************************************************************************//**
  \brief Leave device from network
  
  \param[in] removeChildren - remove or not children
  \param[in] rejoin - perform or not rejoin after leaving
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoLeaveNetworkReq(bool removeChildren, bool rejoin);

/**************************************************************************//**
  \brief Leave device from network. Leave Network module must be allocated before
    calling this function.
  \param[in] removeChildren - remove or not children
  \param[in] rejoin - perform or not rejoin after leaving
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoLeaveNetwork(bool removeChildren, bool rejoin);

/**************************************************************************//**
  \brief Allocate Leave Network module
  \param[in] leaveNetworkConf - confirmation callback
  \return if module was alocated, false otherwise
 ******************************************************************************/
ZDO_PRIVATE bool zdoLeaveNetworkAlloc(ZdoLeaveNetworkConf_t *leaveNetworkConf);

/**************************************************************************//**
  \brief Free Leave Network module
  \param None.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoLeaveNetworkFree(void);

/**************************************************************************//**
  \brief Reset Leave Network component.
  \param None.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoLeaveNetworkReset(void);

#endif // _ZDOLEAVENETWORK_H

// eof zdoLeaveNetwork.h
