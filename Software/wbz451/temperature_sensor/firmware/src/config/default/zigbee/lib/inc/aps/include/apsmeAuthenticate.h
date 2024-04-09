// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSME Authenticate Header File

  Company
    Microchip Technology Inc.

  File Name
    apsmeAuthenticate.h

  Summary
    Interface of APS Entity Authentication Services.

  Description
    This header file defines the interface to the APS authentication functions.
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
#if !defined _APSME_AUTHENTICATE_H
#define _APSME_AUTHENTICATE_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
/**//**
 *
 *  The APS-layer provides services that allow two devices to mutually
 * authenticate each other. The process authenticates the originator of the
 * data by using a random challenge with a response based on a pre-shared
 * secret, in this case, a key. It also allows optional authenticated data
 * transfer. See ZigBee Specification r19, 4.4.8, page 470.
 *
 **/
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/nwk.h>
#include <aps/include/apsCommon.h>
#if defined _SECURITY_ && defined _LINK_SECURITY_
#include <security/serviceprovider/include/sspChallengeGen.h>
#include <security/serviceprovider/include/sspAuthentic.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of entity authentication status code. */
typedef enum
{
  /** No errors occur. */
  APS_AUTH_SUCCESS_STATUS           = 0x00,
  /*! An invalid parameter was input to one of the key establishment primitives.
   **/
  APS_AUTH_INVALID_PARAMETER_STATUS = 0x01,
  /** No authentication key exists. */
  APS_AUTH_NO_KEY_STATUS            = 0x02,
  /** No authentication data exists. */
  APS_AUTH_NO_DATA_STATUS           = 0x03,
  /** Challenge is invalid:
   * \li Initiator during action step 2 (sub-clause B.8.1 of ZigBee Spec r19),
   * \li Responder during action step 1 (sub-clause B.8.2). */
  APS_AUTH_INVALID_CHALLENGE_STATUS = 0x04,
  /** MAC transformation outputs invalid:
   * \li Initiator during action step 4 (sub-clause B.8.1),
   * \li Responder during action steps 4 and 7 (sub-clause B.8.2). */
  APS_AUTH_INVALID_MAC_STATUS       = 0x05,
  /** Tag checking transformation outputs invalid:
   * \li Initiator during action step 3 (sub-clause B.8.1),
   * \li Responder during action step 6 (sub-clause B.8.2). */
  APS_AUTH_INVALID_KEY_STATUS       = 0x06,
  /**  The initiator or responder waits for an expected incoming
   * message for time greater than apsSecurityTimeoutPeriod. */
  APS_AUTH_TIMEOUT_STATUS           = 0x07,
  /** Short address of authentic partner is not found. */
  APS_AUTH_NO_SHORT_ADDR_STATUS     = 0x08
} APS_AuthenticateStatus_t;

/**
    struct APS_AuthenticateConf_t apsmeAuthenticate.h "aps.h"
 
    brief Parameters of APSME-AUTHENTICATE.confirm primitive.
    See ZigBee Specification r19, Table 4.30, page 472.
    */
typedef struct
{
  /** \ref Endian "[LE]" The extended, 64-bit IEEE address of the device
   * with which the entity authentication took place. */
  ExtAddr_t address;
  /** The final status of the entity authentication. */
  APS_AuthenticateStatus_t status;
} APS_AuthenticateConf_t;

/** Type of action. See ZigBee Specification r19, Table 4.29. */
typedef enum
{
  /** Initiate the entity authentication. */
  APS_INITIATE_ACTION       = 0x00,
  /** Respond to the entity authentication request, accepting it. */
  APS_RESPOND_ACCEPT_ACTION = 0x01,
  /** Respond to the entity authentication request, rejecting it. */
  APS_RESPOND_REJECT_ACTION = 0x02
} APS_AuthenticateAction_t;

/**
    struct APS_AuthenticateReq_t apsmeAuthenticate.h "aps.h"
 
    brief Parameters of APSME-AUTHENTICATE.request primitive.
    See ZigBee Specification r19, Table 4.28, page 471.
    */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    void *next; /*!< Service field, used for queue support. */
    uint8_t ttl;
    /** Allocation request of memory for NWK_DataReq_t and APDU. */
    NWK_AllocDataReq_t allocNwkDataReq;
    /** Request's parameters of authentic calculation - MacTag2 and MacTag1. */
    SSP_CalculateAuthenticParamsReq_t macTagReq;
    /** Pointer to NWK_DataReq_t structure for challenge and macdata frames. */
    NWK_DataReq_t *challengeNwkDataReq;
    NWK_DataReq_t *macdataNwkDataReq;
    struct /** Information about authentic partner. */
    {/** Network address of the ounterpart device in the authentication request.*/
      ShortAddr_t shortAddr;
      /** Received MacTag hash from authentic partner. */
      uint8_t macTag[HASH_SIZE];
      /** Frame counter received from partner in the Data field. */
      uint32_t frameCounter;
    } partner;
    /**  The 16-octet random challenge generated by the responder. */
    uint8_t responderChallenge[CHALLENGE_SEQUENCE_SIZE];
  } service;
  /** \endcond **/

  /** \ref Endian "[LE]" The extended, 64-bit IEEE address of the counterpart
   * device in the entity authentication request. */
  ExtAddr_t partnerAddress;
  /** Indicates the action required. See APS_AuthenticateAction_t enumeration.
   * \sa APS_AuthenticateAction_t */
  APS_AuthenticateAction_t action;
  /**  The 16-octet random challenge generated by the initiator. */
  uint8_t initiatorChallenge[CHALLENGE_SEQUENCE_SIZE];
  /** Callback confirmation function of entity authentication. Must not be set to NULL. */
  void (*APS_AuthenticateConf)(APS_AuthenticateConf_t *conf);
  /** Confirm primitive as a parameter of the callback function */
  APS_AuthenticateConf_t confirm;
} APS_AuthenticateReq_t;

/**
    struct APS_AuthenticateInd_t apsmeAuthenticate.h "aps.h"
 
    brief Parameters of APSME-AUTHENTICATE.indication primitive.
    See ZigBee Specification r19, Table 4.31, page 473.
    */
typedef struct
{
  /** \ref Endian "[LE]"
   * The extended, 64-bit IEEE address of the initiator device. */
  ExtAddr_t initiatorAddress;
  /** The 16-octet random challenge received from the initiator. */
  uint8_t randomChallenge[CHALLENGE_SEQUENCE_SIZE];
} APS_AuthenticateInd_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Initiate or respond an entity authentication.

   This primitive can be used when there is a need to authenticate another
   device without using frame security. The protocol confirms authenticity
   based on the two devices sharing a pre-shared key. See ZigBee spec r19,
   4.4.8.1, page 470.

  \param[in] req - pointer to APSME-AUTHENTICATE.request's parameters.
                   \sa APS_AuthenticateReq_t

  \return None.
 ******************************************************************************/
void APS_AuthenticateReq(APS_AuthenticateReq_t *const req);

/**************************************************************************//**
  \brief A request to start an entity authentication is received.

    See ZigBee Specification r19, 4.4.8.3, page 473.

  \param[in] ind - pointer to APSME-AUTHENTICATE.indication's parameters.
                   \sa APS_AuthenticateInd_t

  \return None.
 ******************************************************************************/
void APS_AuthenticateInd(APS_AuthenticateInd_t *ind);

#endif /* _SECURITY_ and _LINK_SECURITY_ */

#endif /* _APSME_AUTHENTICATE_H */
/** eof apsmeAuthenticate.h */

