/*******************************************************************************
  APSME EstablishKey Header File

  Company
    Microchip Technology Inc.

  File Name
    apsmeEstablishKey.h

  Summary
    Interface of APS Key-Establishment Services.

  Description
    This header file defines the APS functions required to establish a initial network
    connection.
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

#if !defined _APSME_ESTABLISH_KEY_H
#define _APSME_ESTABLISH_KEY_H
/**//**
 *
 *  The APS layer provides services that allow two devices to establish
 * a mutual link key. Initial trust information (for example, a master key) must be
 * installed on each device prior to running the key establishment procedure.
 * See ZigBee Specification r19, 4.4.2, page 441.
 *
 **/

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>
#if defined _SECURITY_ && defined _LINK_SECURITY_
#include <security/serviceprovider/include/sspSkke.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/**//**
 * \brief Status values as a result of the SKKE protocol.
 * See ZigBee Specification r19, Table 4.10, page 448.
 **/
typedef enum
{
  /** No errors occured .*/
  APS_SKKE_SUCCESS_STATUS            = 0x00,
  /** An invalid parameter was input to one of the key establishment
   * primitives. */
  APS_SKKE_INVALID_PARAMETER_STATUS  = 0x01,
  /** No master key is available. */
  APS_SKKE_NO_MASTER_KEY_STATUS      = 0x02,
  /** Challenge is invalid:
   * \li Initiator during action step 3 (sub-clause B.7.1),
   * \li Responder during action step 3 (sub-clause B.7.2).
   **/
  APS_SKKE_INVALID_CHALLENGE_STATUS  = 0x03,
  /** SKG outputs invalid:
   * \li Initiator during action step 4 (sub-clause B.7.1),
   * \li Responder during action step 3 (sub-clause B.7.2).
   **/
  APS_SKKE_INVALID_SKG_STATUS        = 0x04,
  /** MAC transformation outputs invalid:
   * \li Initiator during action step 8 (sub-clause B.7.1),
   * \li Responder during action step 10 (sub-clause B.7.2).
   **/
  APS_SKKE_INVALID_MAC_STATUS        = 0x05,
  /** Tag checking transformation outputs invalid:
   * \li Initiator during action step 12 (sub-clause B.7.1),
   * \li Responder during action step 8 (sub-clause B.7.2).
   **/
  APS_SKKE_INVALID_KEY_STATUS        = 0x06,
  /** Either the initiator or responder waits for the next expected incoming
   * message for time greater than the apsSecurityTimeOutPeriod attribute
   * of the AIB. */
  APS_SKKE_TIMEOUT_STATUS            = 0x07,
  /** Either the initiator or responder receives an SKKE frame out of order. */
  APS_SKKE_BAD_FRAME_STATUS          = 0x08,
  /** Invalid global state of APS layer. */
  APS_SKKE_NOT_PERMITTED_STATUS      = 0x09,
  /** Transmission of SKKE-1 command frame is failure. */
  APS_SKKE_1_TX_ERROR_STATUS         = 0x0A,
  /** Transmission of SKKE-2 command frame is failure. */
  APS_SKKE_2_TX_ERROR_STATUS         = 0x0B,
  /** Transmission of SKKE-3 command frame is failure. */
  APS_SKKE_3_TX_ERROR_STATUS         = 0x0C,
  /** Transmission of SKKE-4 command frame is failure. */
  APS_SKKE_4_TX_ERROR_STATUS         = 0x0D,
  /** Error saving new link key. */
  APS_SKKE_SET_LINK_KEY_ERROR_STATUS = 0x0E,
  /** Short address of key establish partner is not found. */
  APS_SKKE_NO_SHORT_ADDR_STATUS      = 0x0F
} APS_SkkeStatus_t;

/**//**
 * \brief The requested key-establishment method.
 **/
typedef enum
{
  APS_SKKE_KEY_ESTABLISHMENT_METHOD = 0x00
} APS_KeyEstablishmentMethod_t;

/**//**
 * \struct APS_EstablishKeyConf_t apsmeEstablishKey.h "aps.h"
 *
 * \brief Parameters of a callback for the APS_EstablishKeyReq() function.
 *
 *  The structure conforms to APSME-KEY-ESTABLISH.confirm primitive defined in
 *  ZigBee Specification r19, Table 4.6, page 443.
 **/
typedef struct
{
  /** \ref Endian "[LE]"  The extended 64-bit address of the device with
   * which the key-establishment protocol was executed. */
  ExtAddr_t address;
  /** This parameter indicates the final status of the key-establishment
   * protocol. */
  APS_SkkeStatus_t status;
} APS_EstablishKeyConf_t;

/** Type of time-to-live of Establish Key request or response. */
typedef uint16_t ApsSkkeTTL_t;

typedef struct _ApsSkkeElem_t
{
  QueueElement_t qelem; /*!< Used for queue support. */
  uint8_t state;        /*!< Internal state of Establish Key request (response). */
  ApsSkkeTTL_t ttl;     /*!< Time to live of appropriate SKKE request. */
  /** Pointer to confirmation function of SKKE operations. Must not be set to NULL. */
  void (* apsSkkeConf)(struct _ApsSkkeElem_t *elem, APS_SkkeStatus_t skkeStatus);
} ApsSkkeElem_t;

/**//**
 * \struct APS_EstablishKeyReq_t apsmeEstablishKey.h "aps.h"
 *
 * \brief Parameters of the APS_EstablishKeyReq() function
 *
 *   The structure conforms to APSME-KEY-ESTABLISH.request primitive
 *  defined in ZigBee Specification r19, Table 4.5, page 441.
 **/
typedef struct
{
  /** \cond SERVICE_FIELDS */
  struct
  {
    ApsSkkeElem_t elem;       /*!< Common substructure of SKKE request. */
    ShortAddr_t dstShortAddr; /*!< Short address of SKKE responder. */
    /** Saved pointer to NWK_DataReq_t structure for SKKE-1 command frame. */
    NWK_DataReq_t *skke1NwkDataReq;
    /** Saved pointer to NWK_DataReq_t structure for SKKE-3 command frame. */
    NWK_DataReq_t *skke3NwkDataReq;
    /** Request to allocate memory for SKKE command in NWK layer. */
    NWK_AllocDataReq_t allocNwkDataReq;
    /** Parameters of request for calculation of link key by master key. */
    SSP_CalculateSkkeParamsReq_t sspReq;
  } service;
  /** \endcond */

  /** \ref Endian "[LE]" The extended 64-bit address of the responder device. */
  ExtAddr_t responderAddress;
  /** This parameter indicates if the responder's parent shall be used to
   * forward messages between the initiator and responder devices:
   * \li TRUE - Use parent,
   * \li FALSE - Do not use parent.
   **/
  bool useParent;
  /** \ref Endian "[LE]"
   * If \c useParent is TRUE, then the \c responderParentAddress parameter shall
   * contain the extended 64-bit address of the responderâ??s parent device.
   * Otherwise, this parameter is not used and need not to be set. */
  ExtAddr_t responderParentAddress;
  /** Requested key-establishment method. The valid value is SKKE. */
  APS_KeyEstablishmentMethod_t keyEstablishmentMethod;
  /** Parameters that will be passed to the confirmation callback in the argument */
  APS_EstablishKeyConf_t confirm;
  /** Confirmation callback function. Must not be set to NULL. */
  void (*APS_EstablishKeyConf)(APS_EstablishKeyConf_t *conf);
} APS_EstablishKeyReq_t;

/**//**
 * \struct APS_EstablishKeyInd_t apsmeEstablishKey.h "aps.h"
 *
 * \brief Parameters of APSME-KEY-ESTABLISH.indication.
 *  See ZigBee Specification r19, Table 4.7, page 444.
 **/
typedef struct
{
  /** \ref Endian "[LE]" The extended 64-bit address of the initiator device. */
  ExtAddr_t initiatorAddress;
  /** The requested key-establishment method shall be SKKE. */
  APS_KeyEstablishmentMethod_t keyEstablishmentMethod;
  /** Data field from received SKKE-1 command frame. */
  uint8_t qeu[CHALLENGE_SEQUENCE_SIZE];
  /** An initial Establish Key command is received from parent or not. */
  bool fromParent;
} APS_EstablishKeyInd_t;

/**//**
 * \struct APS_EstablishKeyResp_t apsmeEstablishKey.h "aps.h"
 *
 * \brief Parameters of APSME-KEY-ESTABLISH.response.
 *  See ZigBee Specification r19, Table 4.8, page 445.
 **/
typedef struct
{
  /** \cond SERVICE_FIELDS */
  struct
  {
    ApsSkkeElem_t elem; /*!< Common substructure of SKKE request. */
    ShortAddr_t dstShortAddr; /*!< Short address of SKKE initiator. */
    /** Parameters of request for calculation of link key by master key. */
    SSP_CalculateSkkeParamsReq_t sspReq;
    /** Request to allocate memory for SKKE command in NWK layer. */
    NWK_AllocDataReq_t allocNwkDataReq;
    /** Saved pointer to NWK_DataReq_t structure for SKKE-2 command frame. */
    NWK_DataReq_t *skke2NwkDataReq;
    /** Saved pointer to NWK_DataReq_t structure for SKKE-4 command frame. */
    NWK_DataReq_t *skke4NwkDataReq;
  } service;
  /** \endcond */

  /** \ref Endian "[LE]" The extended 64-bit address of the device
   * that initiated key establishment. */
  ExtAddr_t initiatorAddress;
  /** This parameter indicates the response to an initiator's request to
   * execute a keyestablishment protocol. The response shall be either:
   * \li TRUE = Accept,
   * \li FALSE = Reject.
   **/
  bool accept;
  /** This parameter indicates if the responder's parent shall be used to
   * forward messages between the initiator and responder devices:
   * \li TRUE - Use parent,
   * \li FALSE - Do not use parent.
   **/
  bool useParent;
  /** Data field from received SKKE-1 command frame. */
  uint8_t qeu[CHALLENGE_SEQUENCE_SIZE];
  /** Confirm primitive as a parameter of the callback function. */
  APS_EstablishKeyConf_t confirm;
  /** Callback function pointer as a handler of corresponding
   * confirm primitive. Must not be set to NULL. */
  void (*APS_EstablishKeyConf)(APS_EstablishKeyConf_t *conf);
} APS_EstablishKeyResp_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
#if defined _HIGH_SECURITY_
/**************************************************************************//**
  \brief Initiates the key establishment procedure

  \ingroup aps_security

  The function is used in high security to initiate a link key
  establishment procedure (currently, SKKE) between two device. The procedure requires
  the master key, which must be known on both devices (set via the APS_SetMasterKey()
  function). The stack uses this procedure during device authentication on the
  trust center, while the application may use it to establish application link
  keys between two common devices.

  If the function is used to establish an application link key, set the
  \c useParent field to \c false and do not specify \c responderParentAddress.

  Currently only SKKE protocol is supported, and so set \c keyEstablishmentMethod
  to ::APS_SKKE_KEY_ESTABLISHMENT_METHOD.

  The function conforms to APSME-ESTABLISH-KEY.request primitive.
  See ZigBee Specification r19, 4.4.2.1, page 441.

  \param[in] req - pointer to request parameters of the APS_EstablishKeyReq_t type

  \return None
  
  \param Response statuses:
    Accessed via the APS_EstablishKeyConf_t::status field of the 
    APS_EstablishKeyReq_t::APS_EstablishKeyConf callback's argument. \n
    All possible status codes are wrapped in the ::APS_SkkeStatus_t enumeration.
 ******************************************************************************/
void APS_EstablishKeyReq(APS_EstablishKeyReq_t *const req);

/**************************************************************************//**
  \brief Informs the upper layer when APS receives an initial
         key-establishment message

   The APS layer on the responder device calls this function informing the ZDO layer
   when a request to start the key-establishment procedure (for example, an SKKE-1
   frame) is received from the initiator device and the master key associated with
   the initiator is present in the APS Key-pair set.

   The function conforms to APSME-ESTABLISH-KEY.indication primitive.
   See ZigBee Specification r19, 4.4.2.3, page 444.

  \param[in] ind - pointer to parameters of the APS_EstablishKeyInd_t type

  \return None
 ******************************************************************************/
void APS_EstablishKeyInd(APS_EstablishKeyInd_t *ind);

/**************************************************************************//**
  \brief The responder device calls this function to respond
         to an APSME-ESTABLISH-KEY.indication primitive.

   The ZDO layer calls this function to inform APS following a request from the
   initiator device to start the key-establishment procedure. The function provides
   the responder's ZDO with an opportunity to determine whether to accept or reject
   the request to establish the key with a given initiator.

   The function conforms to APSME-ESTABLISH-KEY.response primitive.
   See ZigBee Specification r19, 4.4.2.4, page 444.

  \param[in] resp - pointer to parameters of the APS_EstablishKeyResp_t type

  \return None
 ******************************************************************************/
void APS_EstablishKeyResp(APS_EstablishKeyResp_t *const resp);

#endif /* _HIGH_SECURITY_ */

#endif /* _SECURITY_ and _LINK_SECURITY_ */

#endif /* _APSME_ESTABLISH_KEY_H */
/** eof apsmeEstablishKey.h */

