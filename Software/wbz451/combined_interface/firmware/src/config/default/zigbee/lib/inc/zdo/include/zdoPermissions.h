// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object permissions Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoPermissions.h

  Summary:
    This file contains the Interface of the permissions configuration table.

  Description:
    This file contains the Interface of the permissions configuration table.

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
#if !defined _ZDO_PERMISSIONS_H
#define _ZDO_PERMISSIONS_H
// DOM-IGNORE-END

/******************************************************************************
                              Includes section
 ******************************************************************************/
#include <aps/include/aps.h>
#include <zdo/include/zdo.h>
#include <systemenvironment/include/sysEvents.h>

/******************************************************************************
                             Definitions section
 ******************************************************************************/
 
// DOM-IGNORE-BEGIN
 /** Checks that some action is permitted or not. */
#define ZDO_IS_PERMITTED(status) (ZDO_SUCCESS_STATUS == (status))
#define ZDO_IS_NOT_PERMITTED(status) (ZDO_SUCCESS_STATUS != (status))
// DOM-IGNORE-END

/******************************************************************************
                                 Types section
 ******************************************************************************/
 
/** Permissions to perform actions on given device. Permissions can be combined
    as actions using the OR operand. */
typedef BcAction_t ZDO_Permissions_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief The permissions that will be used by default.

    If the ZDO_CheckDevicePermissions function hasn't found any permissions
  that associated with the passed address then it will return the default permissions.

  \param[in] permissions - the set of default permissions for all actions,
  \return None.
 ******************************************************************************/
void ZDO_SetDefaultPermissions(ZDO_Permissions_t permissions);

/**************************************************************************//**
  \brief Gets default permissions.

  \return Permissions that are applied by default if there is no special record
          for the particular device. All 0xff mean that all actions are permitted.
 ******************************************************************************/
ZDO_Permissions_t ZDO_GetDefaultPermissions(void);

/**************************************************************************//**
  \brief Set permissions for actions which can be performed by the device.

  \param[in] deviceAddress - the pointer the extended address of the device
             for which new entry in the permissions table is created.
  \param[in] permissions - permissions which are associated with the given device.

  \return ZDO_SUCCESS_STATUS if the operation completed successfuly otherwise
          ZDO_TABLE_FULL_STATUS if the table doesn't have enough space
          ZDO_INVALID_PARAMETERS_STATUS if a parameter has an invalid value.
            For example, the permissions mask has a bit which doesn't associated
            with any supported action.
 ******************************************************************************/
ZDO_Status_t ZDO_SetPermissions( const ExtAddr_t *deviceAddress,ZDO_Permissions_t permissions);

/**************************************************************************//**
  \brief Gets permissions which the device has.

  \param[in] deviceAddress - the IEEE address of the device.

  \return Actual permissions which will be applied to the device.
 ******************************************************************************/
ZDO_Permissions_t ZDO_GetPermissions(const ExtAddr_t *deviceAddress);

/**************************************************************************//**
  \brief Update the permissions record which are associated with the device.

  \param[in] deviceAddress - the pointer the extended address of the device
             for which the record must be updated. If there is no record which
             contains the deviceAddress then new record will be created with
             default permissions which are updated by passed permissions.
  \param[in] permissions - permissions which are associated with the given device.
  \param[in] mask - actions mask for which the passed permissions must applied.
  \return ZDO_SUCCESS_STATUS if the operation completed successfuly otherwise
          ZDO_TABLE_FULL_STATUS if the table doesn't have enough space
          ZDO_INVALID_PARAMETERS_STATUS if a parameter has an invalid value.
            For example, the permissions mask has a bit which doesn't associated
            with any suppoerted action.
 ******************************************************************************/
ZDO_Status_t ZDO_UpdatePermissions(const ExtAddr_t *deviceAddress,ZDO_Permissions_t permissions, ZDO_Permissions_t mask);

/**************************************************************************//**
  \brief Find and remove permissions from the permissions table.

    We suppose that deviceAddress is primary key for the permissions table and
  there is no duplicates in the table. That's why only one record will be removed.

  \param[in] deviceAddress - the pointer to the IEEE address of the device
             which permissions should be removed from the table,

  \return ZDO_SUCCESS_STATUS if a entry was removed from the table.
          ZDO_INVALID_PARAMETERS_STATUS - there is no entry which are matched
            to the passed arguments.
 ******************************************************************************/
ZDO_Status_t ZDO_DeletePermissions(const ExtAddr_t *deviceAddress);

/**************************************************************************//**
  \brief Is permitted the set of actions or not?

  \param[in] deviceAddress - the IEEE address of the device that performs
                           the set of actions.
  \param[in] actions - action mask which can have one or more actions.

  \return ZDO_SUCCESS_STATUS if the actions are permitted.
          ZDO_NOT_AUTHORIZED_STATUS - one or more actions are not permitted.
 ******************************************************************************/
ZDO_Status_t ZDO_CheckPermissions(ExtAddr_t deviceAddress, BcAction_t action);

#endif /** _ZDO_PERMISSIONS_H */
/** eof zdoPermissions.h */
