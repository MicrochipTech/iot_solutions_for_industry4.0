// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSME VerifyKey Header File

  Company
    Microchip Technology Inc.

  File Name
    apsmeVerifyKey.h

  Summary
    Interface of APS Verify Key Service.

  Description
    This header file provides service that allow a device to verify its TCLK
    with Trust Center.
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
#if !defined _APSME_VERIFY_KEY_H
#define _APSME_VERIFY_KEY_H
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
/**//**
 *
 *  The APSME provides service that allow a device to verify its TCLK
 * with Trust Center. 
 **/
// DOM-IGNORE-END
/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCommon.h>

#if defined _SECURITY_ && defined _LINK_SECURITY_
/******************************************************************************
                                Types section
 ******************************************************************************/
/**
    The type of key being requested:
    \li Trust Center Link Key.
    \li 0x00-0x03 and 0x03-0xFF = Reserved.
    */
typedef enum
{
  APS_VERIFY_TC_LINK_KEY_TYPE = 0x04,
} APS_VerifyKeyType_t;

/** Status of creating and sending a Verify key command frame. */
typedef enum
{
  APS_VERIFY_KEY_SUCCESS_STATUS  = 0x00,
  APS_VERIFY_KEY_FAIL_STATUS = 0x01,
  APS_VERIFY_KEY_TIMEOUT_STATUS = 0x02,
  APS_VERIFY_KEY_INVALID_STATUS = 0x03,
} APS_VerifyKeyStatus_t;

/**
    struct APS_VerifyKeyConf_t apsmeVerifyKey.h "aps.h"
 
    brief Parameters of APSME-VERIFY-KEY.confirm primitive.
    */
typedef struct
{
  APS_VerifyKeyStatus_t status; //!< The status of the Verify key
} APS_VerifyKeyConf_t;

/**
    struct APS_VerifyKeyReq_t apsmeVerifyKey.h "aps.h"
 
    brief Parameters of APSME-VERIFY-KEY.request primitive.
    */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    /** Service field, used for queue support */
    QueueElement_t qelem;
    /** Request to send APS Verify Key command. */
    ApsCommandReq_t commandReq;
    uint32_t ttl;
    uint8_t text[SECURITY_KEY_SIZE + 1 + SECURITY_KEY_SIZE];
    bool confirmKeyReceived;
    bool verifyKeySent;
  } service;
  /** \endcond **/

  /* APS Verification Key Timeout */
  uint32_t timeout;
  /** \ref Endian "[LE]" The extended 64-bit address of the device to which
   * the Verify-Key command should be sent. */
  ExtAddr_t destAddress;
  /** The type of key being confirm:
   * \li 0x04 = Trust Center Link Key. */
  APS_VerifyKeyType_t keyType;
  /** The Hash value of the TCLK. */
  uint8_t hashValue[SECURITY_KEY_SIZE];
  /** Canfirmation parameters. \sa APS_VerifyKeyConf_t */
  APS_VerifyKeyConf_t confirm;
  /** Callback function pointer as a handler of corresponding
   * confirm primitive. Must not be set to NULL. */
  void (*APS_VerifyKeyConf)(APS_VerifyKeyConf_t *conf);
} APS_VerifyKeyReq_t;

/**
    struct APS_VerifyKeyInd_t apsmeVerifyKey.h "aps.h"
 
    brief Parameters of APSME-CONFIRM-KEY.indication primitive.
    */
typedef struct
{
  /** \ref Endian "[LE]" The extended 64-bit address of the device that sent
   * the Confirm-Key command. */
  ExtAddr_t srcAddress;
  /** The type of key being confirm. Valid values:
   * \li APS_VERIFY_TC_LINK_KEY_TYPE
   **/
  APS_VerifyKeyType_t keyType;
  /* The status of the TCLK verification done by TC */
  APS_VerifyKeyStatus_t status;
} APS_ConfirmKeyInd_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Verify the Truct Center Link Key with Trust Center

   ingroup aps_security

  \param[in] req - pointer to APSME-VERIFY-KEY.request's parameters.
                   \sa APS_VerifyKeyReq_t
  

  \param Response statuses:
    Accessed via the APS_VerifyKeyConf_t::status field of the
    APS_VerifyKeyReq_t::APS_VerifyKeyConf callback's argument.
    
  \return None.
 ******************************************************************************/
void APS_VerifyKeyReq(APS_VerifyKeyReq_t *req);

/**************************************************************************//**
  \brief Generate this primitive when APS receives a Confirm-Key command frame

  Upon receipt of the APSME-CONFIRM-KEY.indication primitive, the ZDO shall
  be informed that the device referenced by the SrcAddress parameter is
  requesting a key verification.

  \param[in] indParams - pointer to APSME-CONFIRM-KEY.indication's parameters.
                   \sa APS_ConfirmKeyInd_t
  \return None.
 ******************************************************************************/
void APS_ConfirmKeyInd(APS_ConfirmKeyInd_t *indParams);

#endif /* _SECURITY_ and _LINK_SECURITY_ */

#endif /* _APSME_VERIFY_KEY_H */
/** eof apsmeVerifyKey.h */

