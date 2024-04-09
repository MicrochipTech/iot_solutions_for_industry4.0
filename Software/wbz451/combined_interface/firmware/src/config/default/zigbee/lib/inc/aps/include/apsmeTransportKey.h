// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSME TransportKey Header File

  Company
    Microchip Technology Inc.

  File Name
    apsmeTransportKey.h

  Summary
    Interface of APS Transport-Key Services.

  Description
    This header file defines the interface to the APS Transport key services.
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
#if !defined _APSME_TRANSPORT_KEY_H
#define _APSME_TRANSPORT_KEY_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
/**//**
 *
 *  The APS-layer provides this services that allow an initiator to transport
 * keying material to a responder. The different types of keying material that
 * can be transported are shown in Tables 4.12 to 4.15 of ZigBee Spec. r19.
 *
 **/
 
 // DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>
#if defined _SECURITY_
#include <security/serviceprovider/include/sspCommon.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** KeyType Parameter of the Transport-Key Primitive.
    See ZigBee Specification r19, Table 4.12, page 452. */
typedef enum
{
  /** Indicates the key is a master key used to set up link keys between
   * the Trust Center and another device. */
  APS_TRUST_CENTER_MASTER_KEY_TYPE   = 0x00,
  /** Indicates that the key is a network key to be used in standard security
   * mode and may be distributed using key-transport or a standard network key.
   **/
  APS_STANDARD_NETWORK_KEY_TYPE      = 0x01,
  /** Indicates the key is a master key used to set up link keys between
   * two devices. */
  APS_APP_MASTER_KEY_TYPE            = 0x02,
  /** Indicates the key is a link key used as a basis of security between
   * two devices. */
  APS_APP_LINK_KEY_TYPE              = 0x03,
  /** Indicates that the key is a link key used as a basis for security
   * between the Trust Center and another device. */
  APS_TRUST_CENTER_LINK_KEY_TYPE     = 0x04,
  /** Indicates that the key is a network key to be used in high security
   * mode and may be distributed using key-transport only. */
  APS_HIGH_SECURITY_NETWORK_KEY_TYPE = 0x05
} APS_TransportKeyType_t;

/** TransportKeyData Parameter for a Trust Center Master Key or Link Key
    See ZigBee Specification r19, Table 4.13, page 453. */
typedef struct
{
  /**  Endian "[LE]" The extended 64-bit address of the parent of
   * the destination device given by the DestAddress parameter. */
  ExtAddr_t parentAddress;
  /** The Trust Center master or link key. */
  uint8_t key[SECURITY_KEY_SIZE];
} APS_ReqTrustCenterMasterOrLinkKeyTransportData_t;

/** TransportKeyData Parameter for a Network Key.
    See ZigBee Specification r19, Table 4.14, page 453. */
typedef struct
{
  /** Endian "[LE]" If the UseParent is TRUE, then ParentAddress parameter
   * shall contain the extended 64-bit address of the destination deviceâ??s
   * parent device; otherwise, this parameter is not used and need not be set.*/
  ExtAddr_t parentAddress;
  /** A sequence number assigned to a network key by the Trust Center and used
   * to distinguish network keys for purposes of key updates and incoming
   * frame security operations. */
  uint8_t keySeqNumber;
  uint8_t networkKey[SECURITY_KEY_SIZE];
  /** This parameter indicates if the destination device's parent shall be
   * used to forward the key to the destination device:
    TRUE = Use parent,
    FALSE = Do not use parent. */
  bool useParent;
  /** Use tunneling for transport NWK key. */
  bool tunneling;
} APS_ReqNetworkKeyTransportData_t;

/** TransportKeyData Parameter for an Application Master or Link Key.
    See ZigBee Specification r19, Table 4.15, page 454. */
typedef struct
{
  /**  Endian "[LE]" The extended 64-bit address of the device that was also
   * sent this master key. */
  ExtAddr_t partnerAddress;
  /** This parameter indicates if the destination device of this master
   * key requested it:
    TRUE = If the destination requested the key,
    FALSE = Otherwise. */
  bool initiator;
  /** The master or link key (as indicated by the KeyType parameter). */
  uint8_t key[SECURITY_KEY_SIZE];
} APS_ReqApplicationMasterOrLinkKeyTransportData_t;

typedef union
{
  APS_ReqTrustCenterMasterOrLinkKeyTransportData_t trustCenterKey;
  APS_ReqNetworkKeyTransportData_t networkKey;
  APS_ReqApplicationMasterOrLinkKeyTransportData_t applicationKey;
} APS_ReqTransportKeyData_t;

/** Status of creating and sending a transport key command frame. */
typedef enum
{
  APS_TRANSPORT_KEY_SUCCESS_STATUS = 0x00,
  APS_TRANSPORT_KEY_NO_SHORT_ADDRESS_STATUS = 0x01,
  APS_TRANSPORT_KEY_SECURITY_FAIL_STATUS = 0x02,
  APS_TRANSPORT_KEY_NOT_SENT_STATUS = 0x03,
  APS_TRANSPORT_KEY_INVALID_PARAMETER_STATUS = 0x04,
  /* These names are deprecated and will be removed. */
  APS_TKR_SUCCESS_STATUS          = APS_TRANSPORT_KEY_SUCCESS_STATUS,
  APS_TKR_NO_SHORT_ADDRESS_STATUS = APS_TRANSPORT_KEY_NO_SHORT_ADDRESS_STATUS,
  APS_TKR_SECURITY_FAIL_STATUS    = APS_TRANSPORT_KEY_SECURITY_FAIL_STATUS,
  APS_TKR_NOT_SENT_STATUS         = APS_TRANSPORT_KEY_NOT_SENT_STATUS
} APS_TkrStatus_t;

/** struct APS_TransportKeyConf_t apsmeTransportKey.h "aps.h"
    Confirmation parameters of APSME-TRANSPORT-KEY.request. */
typedef struct
{
  APS_TkrStatus_t status;
} APS_TransportKeyConf_t;

/** struct APS_TransportKeyReq_t apsmeTransportKey.h "aps.h"
 
    Parameters of APSME-TRANSPORT-KEY.request primitive.
    See ZigBee Specification r19, 4.4.3.1, page 451. */
typedef struct
{
  /**  Endian "[LE]"
   * The extended 64-bit address of the destination device.*/
  ExtAddr_t destAddress;
  /** \cond SERVICE_FIELDS **/
  struct
  {
    ApsCommandReq_t commandReq;
    /** Global internal state of APS Transport Key component. */
    enum
    {
      APS_TRANSPORT_KEY_BEGIN_STATE,
      APS_TRANSPORT_KEY_CONFIRM_STATE,
      APS_TRANSPORT_KEY_PROCESS_STATE
    } state;
  } service;
  /** \endcond **/
  /** The key being transported along with identification
   * and usage parameters. */
  APS_ReqTransportKeyData_t transportKeyData;
  /** Callback function pointer as a handler of corresponding
   * confirm primitive. Must not be set to NULL. */
  void (*APS_TransportKeyConf)(APS_TransportKeyConf_t *conf);
  /** Confirm primitive as a parameter of the callback function. */
  APS_TransportKeyConf_t confirm;
  /** Identifies the type of key material that should be transported;
   * See ZigBee Specification r19, Table 4.12, page 452. */
  APS_TransportKeyType_t keyType;
} APS_TransportKeyReq_t;

/** TransportKeyData Parameter for a Trust Center Master or Link Key.
    See ZigBee Specification r19, Table 4.17, page 457. */
typedef struct
{
  uint8_t trustCenterMasterKey[SECURITY_KEY_SIZE];
} APS_IndTrustCenterMasterOrLinkKeyTransportData_t;

/** TransportKeyData Parameter for a Network Key.
    See ZigBee Specification r19, Table 4.18, page 457. */
typedef struct
{
  /** A sequence number assigned to a network key by the Trust Center and
   * used to distinguish. */
  uint8_t keySeqNumber;
  uint8_t networkKey[SECURITY_KEY_SIZE];
} APS_IndNetworkKeyTransportData_t;

/** TransportKeyData Parameter for an Application Master or Link Key.
    See ZigBee Specification r19, Table 4.19, page 457. */
typedef struct
{
  /** This parameter indicates this device was initiator or not. */
  bool initiatorFlag;
  /**  Endian "[LE]" The extended 64-bit address of the device that was also
   * sent this master key. */
  ExtAddr_t partnerAddress;
  /** The master or link key (as indicated by the KeyType
   * parameter). \sa APS_TransportKeyInd_t */
  uint8_t key[SECURITY_KEY_SIZE];
} APS_IndApplicationMasterOrLinkKeyTransportData_t;

typedef union
{
  APS_IndTrustCenterMasterOrLinkKeyTransportData_t trustCenterKey;
  APS_IndNetworkKeyTransportData_t networkKey;
  APS_IndApplicationMasterOrLinkKeyTransportData_t applicationKey;
} APS_IndTransportKeyData_t;

//\cond internal

/** struct APS_TransportKeyInd_t apsmeTransportKey.h "aps.h"
 
    Parameters of APSME-TRANSPORT-KEY.indication primitive.
    See ZigBee Specification r19, 4.4.3.2, page 455. */
typedef struct
{
  /**  Endian "[LE]" The extended 64-bit address of the device
   * that is the original source of the transported key. */
  ExtAddr_t srcAddress;
  /**  Endian "[LE]" Network address of the device the Transport Key
   * was received from. */
  ShortAddr_t prevNwkAddress;
  /** Identifies the type of key material that was be transported;
   * See Table 4.12 of ZigBee Specification r19. */
  APS_TransportKeyType_t keyType;
  /** The key that was transported along with identification and usage
   * parameters. The type of this parameter depends on the KeyType
   * parameter. */
  APS_IndTransportKeyData_t transportKeyData;
  /* Type of key with the transport key command was secured. */
  ApsSecurityStatusDescriptor_t securedWith;
} APS_TransportKeyInd_t;
//\endcond

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
    \brief Transfers a security key to a specified node


       The function is used by the stack on the trust center to transfer security
       keys during authentication procedures and upon receiving requests for a link
       key. The application can also use it, for example, to distribute a new network
       key. The function conforms to ZigBee Specification r19, 4.4.3.1, page 451.

   Response statuses:
   Accessed via the APS_TransportKeyConf_t::status field of the 
   APS_TransportKeyReq_t::APS_TransportKeyConf callback's 
   argument.
  \param req - a pointer to request parameters of type APS_TransportKeyReq_t

  \return None.
  
 ******************************************************************************/
void APS_TransportKeyReq(APS_TransportKeyReq_t *const req);

/**************************************************************************//**


    \brief Informs ZDO of security key reception

      See ZigBee Specification r19, 4.4.3.2, page 455.

    \param ind - pointer to APSME-TRANSPORT-KEY.indication's parameters.

    \return None


 ******************************************************************************/
void APS_TransportKeyInd(APS_TransportKeyInd_t *ind);

#endif /* _SECURITY_ */
#endif /* _APSME_TRANSPORT_KEY_H */
/** eof apsmeTransportKey.h */

