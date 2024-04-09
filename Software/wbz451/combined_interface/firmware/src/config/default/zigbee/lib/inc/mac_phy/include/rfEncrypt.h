/*******************************************************************************
  RF Encryption Header File

  Company:
    Microchip Technology Inc.

  File Name:
    rfEncrypt.h

  Summary:
    This file provides interface to the RF Encryption functions.

  Description:
    This file contains the Prototypes of ecnryption functions and corresponding types.
    Powered by RF chip.
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

#ifndef _RFECNRYPT_H
#define _RFECNRYPT_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
//! Set of AES command.
typedef enum
{
  RF_SET_KEY_AES_CMD = 0,
  RF_SET_INIT_VECT_AES_CMD,
  RF_ECB_ENCRYPT_AES_CMD,
  RF_CBC_ENCRYPT_AES_CMD,
  RF_ECB_DECRYPT_AES_CMD
} RF_AesCmd_t;

//! Encryption request structure.
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t  service;
  //! AES command.
  RF_AesCmd_t aesCmd;
  //! Pointer to input data for AES command.
  uint8_t *text;
  //! Size of input data in blocks.
  uint8_t blockCount; // Block is 128-bit data.
  void (*encryptConf)(void);
} RF_EncryptReq_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief Executes AES command. Valid for RF231 and RF212.
  \param reqParams - request parameters structure pointer.
  \return none.
******************************************************************************/
void RF_EncryptReq(RF_EncryptReq_t *reqParams);

#endif /*_RFECNRYPT_H*/

// eof rfEncrypt.h

