// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSME UpdateDevice Header File

  Company
    Microchip Technology Inc.

  File Name
    apsmeUpdateDevice.h

  Summary
    Interface of APS Update Device Service.

  Description
    This header file manages the entry of third or more devices into Zigbee Network with the
    help of update device parameter.
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
#if !defined _APSME_UPDATE_DEVICE_H
#define _APSME_UPDATE_DEVICE_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
/**//**
 *
 *  The APS-layer provides services that allow a device (for example, a router)
 * to inform another device (for example, a Trust Center) that a third device
 * has changed its status (for example, joined or left the network). See ZigBee
 * Specification r19, 4.4.4, page 459.
 *
 **/
 
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>
#if defined _SECURITY_
#include <aps/include/apsCommandReq.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Status of creating and sending a update device command frame. */
typedef enum
{
  APS_UPDATE_SUCCESS_STATUS           = 0x00,
  APS_UPDATE_NO_SHORT_ADDRESS_STATUS  = 0x01,
  APS_UPDATE_SECURITY_FAIL_STATUS     = 0x02,
  APS_UPDATE_NOT_SENT_STATUS          = 0x03,
  /* These names are deprecated and will be removed. */
  APS_UDR_SUCCESS_STATUS           = APS_UPDATE_SUCCESS_STATUS,
  APS_UDR_NO_SHORT_ADDRESS_STATUS  = APS_UPDATE_NO_SHORT_ADDRESS_STATUS,
  APS_UDR_SECURITY_FAIL_STATUS     = APS_UPDATE_SECURITY_FAIL_STATUS,
  APS_UDR_NOT_SENT_STATUS          = APS_UPDATE_NOT_SENT_STATUS
} APS_UpdateStatus_t;

/** This type is deprecated and will be removed. */
typedef APS_UpdateStatus_t APS_UdrStatus_t;

/**
    struct APS_UpdateDeviceConf_t apsmeUpdateDevice.h "aps.h"
 
    brief Type of confirmation parameters of APSME-UPDATE-DEVICE.confirm.
    */
typedef struct
{
  APS_UpdateStatus_t status;
} APS_UpdateDeviceConf_t;

/** Type is used to indicate the updated status of the device
 * given by the DeviceAddress parameter. See ZigBee Spec. r19, Table 4.20. */
typedef enum
{
  APS_UPDATE_DEVICE_STATUS_STANDARD_SECURED_REJOIN        = 0x00,
  APS_UPDATE_DEVICE_STATUS_STANDARD_UNSECURED_JOIN        = 0x01,
  APS_UPDATE_DEVICE_STATUS_LEFT                           = 0x02,
  APS_UPDATE_DEVICE_STATUS_STANDARD_UNSECURED_REJOIN      = 0x03,
  APS_UPDATE_DEVICE_STATUS_HIGH_SECURITY_SECURED_REJOIN   = 0x04,
  APS_UPDATE_DEVICE_STATUS_HIGH_SECURITY_UNSECURED_JOIN   = 0x05,
  APS_UPDATE_DEVICE_STATUS_RESERVED                       = 0x06,
  APS_UPDATE_DEVICE_STATUS_HIGH_SECURITY_UNSECURED_REJOIN = 0x07
} APS_UpdateDeviceStatus_t;

/**
    struct APS_UpdateDeviceReq_t apsmeUpdateDevice.h "aps.h"

    brief Parameters of APSME-UPDATE-DEVICE.request primitive.
    See ZigBee Specification r19, 4.4.4.1, page 459.
    */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    /** Request to send APS Update Device command. */
    ApsCommandReq_t commandReq;
  } service;
  /** \endcond **/

  /** \ref Endian "[LE]" The extended 64-bit address of the device that shall
   * be sent the update information. */
  ExtAddr_t destAddress;
  /** \ref Endian "[LE]"
   * The extended 64-bit address of the device whose status is being updated. */
  ExtAddr_t deviceAddress;
  /** Callback function pointer as a handler of corresponding
   * confirm primitive. Must not be set to NULL. */
  void (*APS_UpdateDeviceConf)(APS_UpdateDeviceConf_t *conf);
  /** \ref Endian "[LE]"
   * The 16-bit network address of the device whose status is being updated. */
  ShortAddr_t deviceShortAddress;
  /** This parameter Indicates the updated status of the device given
   * by the deviceAddress parameter. */
  APS_UpdateDeviceStatus_t status;
  /** Confirm primitive as a parameter of the callback function. */
  APS_UpdateDeviceConf_t confirm;
} APS_UpdateDeviceReq_t;

/**
    struct APS_UpdateDeviceInd_t apsmeUpdateDevice.h "aps.h"
 
    brief Parameters of APSME-UPDATE-DEVICE.indication primitive.
    See ZigBee Specification r19, 4.4.4.2, page 461.
    */
typedef struct
{
  /** \ref Endian "[LE]" The extended 64-bit address of the device originating
   * the update-device command. */
  ExtAddr_t srcAddress;
  /** \ref Endian "[LE]"
   * The extended 64-bit address of the device whose status is being updated. */
  ExtAddr_t deviceAddress;
  /** This parameter Indicates the updated status of the device given
   * by the deviceAddress parameter. */
  APS_UpdateDeviceStatus_t status;
  /** \ref Endian "[LE]"
   * The 16-bit network address of the device whose status is being updated. */
  ShortAddr_t deviceShortAddress;
} APS_UpdateDeviceInd_t;

/**
    struct APS_UpdateDeviceInd_t apsmeUpdateDevice.h "aps.h"
 
    brief Parameters of APSME-UPDATE-DEVICE.indication primitive.
    See ZigBee Specification r19, 4.4.4.2, page 461.
    */
typedef struct
{
  /** \ref The parameters of the update-device command. */
  APS_UpdateDeviceInd_t indParams;
  /** \ref The 16-bit network address of the parent of the joining device */
  ShortAddr_t parentShortAddress;
} APS_UpdateDeviceInfo_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
   brief Request to inform a device that another device has new status.

    The ZDO (for example, on a router or ZigBee coordinator) shall initiate
    the APSME-UPDATE-DEVICE.request primitive when it wants to send updated
    device information to another device (for example, the Trust Center).
    See ZigBee Specification r15, 4.4.1, page 459.

  \param[in] req - pointer to APSME-UPDATE-DEVICE.request's parameters.

 

  \param Response statuses:
    Accessed via the APS_UpdateDeviceConf_t::status field of the 
    APS_UpdateDeviceReq_t::APS_UpdateDeviceConf callback's argument.
    
  \return None.
 ******************************************************************************/
void APS_UpdateDeviceReq(APS_UpdateDeviceReq_t *req);

/************************************************************************//**
   \brief Inform the upper-layer that it received an update-device command frame.

   \param[in] ind - pointer to APSME-UPDATE-DEVICE.indication's parameters.

   \return None.
 ******************************************************************************/
void APS_UpdateDeviceInd(APS_UpdateDeviceInd_t *ind, const ShortAddr_t *parentShortAddr);

#endif /* _SECURITY_ */
#endif /* _APSME_UPDATE_DEVICE_H */
/** eof apsmeUpdateDevice.h */

