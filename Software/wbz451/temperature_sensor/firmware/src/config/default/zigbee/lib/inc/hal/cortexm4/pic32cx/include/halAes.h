/*******************************************************************************
  HAL Aes Header File

  Company:
    Microchip Technology Inc.

  File Name:
    halAes.h

  Summary:
    This file contains the Implementation of Bitcloud HAL AES for pic32cx.

  Description:
    This file contains the implementation of Bitcloud HAL AES for pic32cx.
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

// DOM-IGNORE-BEGIN
#ifndef HAL_AES_H_INCLUDED
#define HAL_AES_H_INCLUDED
// DOM-IGNORE-END

/******************************************************************************
                                    Includes section
 ******************************************************************************/
#include <crypto.h>
#include <systemenvironment/include/sysTypes.h>
#include <halAssert.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
                                Defines section
 ******************************************************************************/
#define DRIVER_VERSION 0x00000001u
#define AES_BLOCK_SIZE 16
#define AES_BLOCK_SIZE_TOTAL 64
#define AES_ENCRYPTION 0
#define AES_DECRYPTION 1
#define ERR_NONE 0
#define ERR_INVALID_DATA -1

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** Defines HAL AES commands such as setkey, cbc encrypt, cbc decrypt etc */
typedef enum
{
  SM_SET_KEY_COMMAND = 0,
  SM_ECB_ENCRYPT_COMMAND,
  SM_CBC_ENCRYPT_COMMAND,
  SM_ECB_DECRYPT_COMMAND,
  SM_CBC_DECRYPT_COMMAND,
} HAL_AesCmd_t;

/** Struct for encrypt req */
typedef struct
{
  /** AES command. */
  HAL_AesCmd_t aesCmd;
  
  /** Pointer to input data for AES command. */
  uint8_t *text;
  
  /** Size of input/output data in blocks, 16 bytes aligned blocks*/
  uint8_t blockCount; 

  /** confirmation callback */
  void (*encryptConf)(void);
} HAL_AES_EncryptReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/

/**************************************************************************//**
  \brief Initiates AES Encryption/Decryption/Sets key as per request parameters

  \param[in] req - pointer to request parameters.
  
  \return None.
 ******************************************************************************/
void HAL_AES_EncryptReq(HAL_AES_EncryptReq_t *reqParams);


/**************************************************************************//**
  \brief Resets the security module

  \param None
  
  \return None.
 ******************************************************************************/
void HAL_SmReset (void);

/**************************************************************************//**
  \brief AES engine can be initialized here

  \param None
  
  \return None.
 ******************************************************************************/
void halAesInit(void);

/**************************************************************************//**
  \brief Sets the key and IV

  \param  key - pointer to the key 
          IV  - pointer to the IV
  
  \return None.
 ******************************************************************************/
void halAesSetKeyIV(const uint8_t *key, const uint8_t *iv);

/**************************************************************************//**
  \brief Perform CB decryption on the input

  \param text - pointer the text to be decrypted
         length - length of bytes to be decrypted
  
  \return None.
 ******************************************************************************/
void halAesCBC_Decrypt(uint8_t *text,uint32_t length);

#ifdef __cplusplus
}
#endif

#endif /* HAL_AES_H_INCLUDED */