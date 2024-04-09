// DOM-IGNORE-BEGIN
/*******************************************************************************
  INTRP Data Header File

  Company
    Microchip Technology Inc.

  File Name
    intrpData.h

  Summary
    Interface of inter-PAN transmission.

  Description
    This header file defines the interface to exchange data transfer between devices in and out 
    of the same Zigbee Network.
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
#if !defined _INTRP_DATA_H
#define _INTRP_DATA_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
/**//**
 *
 *  Inter-PAN is a transmission mechanism whereby ZigBee devices can perform
 * limited, insecure, and possibly anonymous exchanges of information with
 * devices in their local neighborhood without having to form or join the same
 * ZigBee network. See ZigBee SE Profile Spec r15, page 81.
 *
 **/
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>
#include <nwk/include/nwkCommon.h>

#if defined _INTERPAN_

/******************************************************************************
                                Definitions section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
#define INTRP_NO_PANID_COMPRESSION_TXOPTION 1u
// DOM-IGNORE-END

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** Type of handle associated with the inter-PAN ASDU to be transmitted. */
typedef uint8_t IntrpAsduHandle_t;
/** Type of inter-PAN frame length. */
typedef uint8_t IntrpLength_t;

/**
    struct INTRP_DataConf_t intrpData.h "aps.h"
 
    brief INTRP-DATA confirm primitive's parameters structure declaration.
 
    ZigBee Smart Energy profile specification r15, B.3.2.
    The INTRP-DATA.confirm Primitive, page 85.
    */
typedef struct
{
  /** An integer handle associated with the transmitted frame. */
  IntrpAsduHandle_t  asduHandle;
  /** The status of the ASDU transmission corresponding to ASDUHandle as
   * returned by the MAC.*/
  MAC_Status_t  status;
} INTRP_DataConf_t;

typedef uint8_t INTRP_TxOptions_t;

/**
    struct INTRP_DataReq_t intrpData.h "aps.h"
 
    brief INTRP-DATA.request primitive's parameters structure declaration.
 
    ZigBee Smart Energy profile specification r15, B.3.1
    The INTRP-DATA.request Primitive, page 83.
    */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    /** MCPS-DATA request primitive's parameters structure. */
    MAC_DataReq_t  macDataReq;
  } service;
  /** \endcond **/
  /** \ref Endian "[LE]" The address of the entity or entities to which
   *  the ASDU is being transferred. */
  MAC_Addr_t dstAddress;
  /** The set of octets comprising the ASDU to be transferred. */
  uint8_t *asdu;
  /** Callback function pointer as a handler of corresponding
   *  confirm primitive. Must not be set to NULL. 
   **/
  void (*INTRP_DataConf)(INTRP_DataConf_t *conf);
  /** Confirm primitive as a parameter of the callback function. */
  INTRP_DataConf_t confirm;
  /** \ref Endian "[LE]" The 16-bit PAN identifier of the entity or entities
   * to which the ASDU is being  transferred or the broadcast PANId 0xffff. */
  PanId_t dstPANID;
  /** \ref Endian "[LE]" The identifier of the profile for which this frame is
   * intended. */
  ProfileId_t profileId;
  /** \ref Endian "[LE]" The identifier of the cluster, within the profile
   * specified by the ProfileId parameter, which defines the application
   * semantics of the ASDU. **/
  ClusterId_t clusterId;
  /** The addressing mode for the destination address used in this primitive.
   *  This parameter can take one of the values from the following list:
   *    \li 0x01 = 16-bit group address
   *    \li 0x02 = 16-bit NWK address, normally  the broadcast address 0xffff
   *    \li 0x03 = 64-bit extended address
   **/
  APS_AddrMode_t dstAddrMode;
  /** The number of octets in the ASDU to be transmitted. */
  IntrpLength_t asduLength;
  /** An integer handle associated with the ASDU to be transmitted. */
  IntrpAsduHandle_t asduHandle;
  /** Transmission options for this request **/
  INTRP_TxOptions_t txOptions;
} INTRP_DataReq_t;

/**
    struct INTRP_DataInd_t intrpData.h "aps.h"
 
    brief INTRP-DATA indication primitive's parameters structure declaration.
 
    ZigBee Smart Energy profile specification r15, B.3.3.
    The INTRP-DATA.indication Primitive, page 86.
    */
typedef struct
{
  /** \ref Endian "[LE]" The 16-bit PAN identifier of the entity from which
   *  the ASDU is being transferred. */
  PanId_t srcPANID;
  /** \ref Endian "[LE]" The device address of the entity from which
   *  the ASDU is being transferred. */
  MAC_Addr_t srcAddress;
  /** The addressing mode for the destination address used in this primitive.
   *  This parameter can take one of the values from the following list:
   *   \li 0x01 = 16-bit group address
   *   \li 0x02 = 16-bit NWK address, normally  the broadcast address 0xffff
   *   \li 0x03 = 64-bit extended address.
   **/
  APS_AddrMode_t dstAddrMode;
  /** \ref Endian "[LE]" The 16-bit PAN identifier of the entity or entities
   * to which the ASDU is being  transferred or the broadcast PANId 0xffff. */
  PanId_t dstPANID;
  /** \ref Endian "[LE]" The address of the entity or entities to which
   *  the ASDU is being transferred. */
  MAC_Addr_t dstAddress;
  /** \ref Endian "[LE]"
   * The identifier of the profile for which this frame is intended. */
  ProfileId_t profileId;
  /** \ref Endian "[LE]" The identifier of the cluster, within the profile
   * specified by the ProfileId parameter, which defines the application
   * semantics of the ASDU. */
  ClusterId_t clusterId;
  /** The number of octets in the ASDU to be transmitted. */
  IntrpLength_t asduLength;
  /** The set of octets comprising the ASDU to be transferred. */
  uint8_t *asdu;
  /** The link quality observed during the reception of the ASDU. */
  Lqi_t lqi;
  /** RSSI observed during the reception of the ASDU. */
  Lqi_t rssi;
} INTRP_DataInd_t;

/** Parameter for INTRP_DataIndRegisterCallback */
typedef void (*INTRP_DataIndCallback_t)(INTRP_DataInd_t *ind);

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief INTRP-DATA request primitive's prototype.

  \param[in] req - INTRP-DATA request parameters' structure pointer.

  \return None.
 ******************************************************************************/
void INTRP_DataReq(INTRP_DataReq_t *const req);

/**************************************************************************//**
  \brief INTRP-DATA indication primitive's prototype.

  \param[in] ind - INTRP-DATA indication parameters' structure pointer.

  \return None.
 ******************************************************************************/
void INTRP_DataInd(INTRP_DataInd_t *ind);

/**************************************************************************//**
  \brief Registers the Interpan Data Indication callback

  \param[in] ind - Callback The callback from subscriber
  \return None.
 ******************************************************************************/
void INTRP_DataIndRegisterCallback(INTRP_DataIndCallback_t callback);

#endif /* _INTERPAN_ */
#endif /* _INTRP_DATA_H */
/** eof intrpData.h */

