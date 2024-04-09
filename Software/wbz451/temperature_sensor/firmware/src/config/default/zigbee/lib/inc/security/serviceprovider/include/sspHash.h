/*******************************************************************************
  Security Service Provider Hash Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sspHash.h

  Summary:
    This file contains the Security Hash Processor function declarations.

  Description:
    This file contains the Security Hash Processor function declarations.
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


#ifndef _SSPHASH_H
#define _SSPHASH_H

#include <systemenvironment/include/sysTypes.h>
#include <security/serviceprovider/include/private/sspHashHandler.h>
#include <security/serviceprovider/include/sspCommon.h>

typedef struct
{
  //! Status of Hash key processing.
  SSP_Status_t status;
} SSP_KeyedHashMacConf_t;


typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    void *next; /*!< Used for queue support */
#ifdef _ZAPPSI_
    /* to be compatible with MAC service. */
    uint8_t requestId;
    /* Sequence number to identify request-response pair. */
    uint8_t sequenceNumber;
    union
    {
      /* Callback wrapper routine pointer */
      void (*callback)(void*);
      /* Processing routine pointer to call after required memory will become free */
      void (*process)(void*);
    } zsi;
#else /* _ZAPPSI_ */
    uint8_t requestId;
#endif /* # _ZAPPSI_ */
  } service;
  /** \endcond **/
  // Service field - for internal needs.
  SSP_Service_t           sspService;
  // There is should be an additional memory before and after text (16 bytes in both cases).
  uint8_t *text/*[SECURITY_KEY_SIZE + textSize + 16]*/;
  // Pointer to key fir Keyed Hash Function.
  uint8_t (*key)/*[SECURITY_KEY_SIZE]*/;
  // Size of the text.
  uint8_t textSize;
  // Buffer for generated hash. Shoul be initialized by the user.
  uint8_t (*hash_i)/*[SECURITY_KEY_SIZE]*/;
  // Confirm handler pointer for internal use
  void (*sspKeyedHashMacConf)(void);

  // Confirm handler pointer
  void (*SSP_KeyedHashMacConf)(SSP_KeyedHashMacConf_t *conf);

  SSP_KeyedHashMacConf_t confirm;

} SSP_KeyedHashMacReq_t;


void SSP_KeyedHashMacReq(SSP_KeyedHashMacReq_t *req);
void sspKeyedHashReqHandler(void);
/**************************************************************************\\**
  \brief This function computes the AES MMO digest of the data parameter of
  length <tt>sz</tt>, and stores the result in.

  \param[out] digest  This is an unsigned char buffer to hold the message digest.
                    The length of the digest must be AES_MMO_HASH_SIZE bytes.
  \param[in] sz       The size in bytes of the message to be hashed.
  \param[in] data     This is an unsigned char buffer of data to be hashed.

  \return MCE_ERR_NULL_OUTPUT_BUF  digest is NULL
          MCE_ERR_NULL_INPUT_BUF   data is NULL
          MCE_SUCCESS              indicates successful completion.

******************************************************************************/
int SSP_BcbHash(unsigned char *digest, unsigned long sz, unsigned char *data);

#endif //#ifndef _SSPHASH_H

//eof sspHash.h
