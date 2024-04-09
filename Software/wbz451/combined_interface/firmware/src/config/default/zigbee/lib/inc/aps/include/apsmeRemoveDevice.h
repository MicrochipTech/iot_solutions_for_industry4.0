// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSME RemoveDevice Header File

  Company
    Microchip Technology Inc.

  File Name
    apsmeRemoveDevice.h

  Summary
    Interface of APS Remove Device Service.

  Description
    This header file manages the APS services that are required to remove a device from the
    network.
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
#if !defined _APSME_REMOVE_DEVICE_H
#define _APSME_REMOVE_DEVICE_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
/**//**
 *
 *  The APS-layer provides services that allow a device (for example,
 * a Trust Center) to inform another device (for example, a router)
 * that one of its children should be removed from the network, or if it wants
 * to remove a router from the network.
 * See ZigBee Specification r19, 4.4.5, page 463 and CCB 1280.
 *
 **/
 // DOM-IGNORE-END
 
 
/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>

#if defined _SECURITY_
/******************************************************************************
                                Types section
 ******************************************************************************/
/** Status of creating and sending a remove device command frame. */
typedef enum
{
  APS_REMOVE_SUCCESS_STATUS        = 0x00,
  APS_REMOVE_NO_SHORT_ADDRESS_STATUS = 0x01,
  APS_REMOVE_SECURITY_FAIL_STATUS  = 0x02,
  APS_REMOVE_NOT_SENT_STATUS       = 0x03,
  /* These names are deprecated and will be removed. */
  APS_RDR_SUCCESS_STATUS           = APS_REMOVE_SUCCESS_STATUS,
  APS_RDR_NO_SHORT_ADDRESS_STATUS  = APS_REMOVE_NO_SHORT_ADDRESS_STATUS,
  APS_RDR_SECURITY_FAIL_STATUS     = APS_REMOVE_SECURITY_FAIL_STATUS,
  APS_RDR_NOT_SENT_STATUS          = APS_REMOVE_NOT_SENT_STATUS
} APS_RemoveStatus_t;

/** This type is deprecated and will be removed. */
typedef APS_RemoveStatus_t APS_RdrStatus_t;

/**
    struct APS_RemoveDeviceConf_t apsmeRemoveDevice.h "aps.h"
 
    brief Confirmation parameters of APSME-REMOVE-DEVICE.request primitive.
    */
typedef struct
{
  /** Status of device removing. */
  APS_RemoveStatus_t status;
} APS_RemoveDeviceConf_t;

/**
    struct APS_RemoveDeviceReq_t apsmeRemoveDevice.h "aps.h"
 
    brief Parameters of APSME-REMOVE-DEVICE.request primitive.
 
    See ZigBee Specification r19, Table 4.22, page 463.
    */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
   /** Request to send APS Remove Device command. */
    ApsCommandReq_t commandReq;
  } service;
  /** \endcond **/

  /** \ref Endian "[LE]" The extended 64-bit address of the device that is
   * the parent of the child device that is requested to be removed. */
  ExtAddr_t parentAddress;
  /** \ref Endian "[LE]" The extended 64-bit address of the target device
   * that is requested to be removed.  If a router device is requested to be removed,
   * then the parentAddress shall be the same as the targetAddress. */
  ExtAddr_t targetAddress;
  /** Confirm primitive as a parameter of the callback function */
  APS_RemoveDeviceConf_t confirm;
  /** Callback function pointer as a handler of corresponding
   * confirm primitive. Must not be set to NULL. */
  void (*APS_RemoveDeviceConf)(APS_RemoveDeviceConf_t *conf);
} APS_RemoveDeviceReq_t;

/**
    struct APS_RemoveDeviceInd_t apsmeRemoveDevice.h "aps.h"
 
    brief Parameters of APSME-REMOVE-DEVICE.indication primitive.
 
    See ZigBee Specification r19, Table 4.23, page 464.
    */
typedef struct
{
  /** \ref Endian "[LE]" The extended 64-bit address of the device requesting
   * that a child device be removed. */
  ExtAddr_t srcAddress;
  /** \ref Endian "[LE]" The extended 64-bit address of the target device
   * that is requested to be removed. */
  ExtAddr_t targetAddress;
} APS_RemoveDeviceInd_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Request to remove a device from the network.

   ingroup aps_misc

    For example, a Trust Center can use this primitive to remove a target
   device that fails to authenticate properly. See ZigBee Specification r19,
   4.4.5.1, page 463.

  \param[in] req - pointer to APSME-REMOVE-DEVICE.request's parameters.

  \return None.
 ******************************************************************************/
void APS_RemoveDeviceReq(APS_RemoveDeviceReq_t *req);

/**************************************************************************//**
  \brief Indication about device removing from the network.

    The APSME shall generate this primitive when it receives a remove-device
   command frame that is successfully decrypted and authenticated, as specified
   in sub-clause 4.4.1.2 of ZigBee Specification r19.

  \param[in] ind - pointer to APSME-REMOVE-DEVICE.indication's parameters.

  \return None.
 ******************************************************************************/
void APS_RemoveDeviceInd(APS_RemoveDeviceInd_t *ind);

#endif /* _SECURITY_ */
#endif /* _APSME_REMOVE_DEVICE_H */
/** eof apsmeRemoveDevice.h } */

