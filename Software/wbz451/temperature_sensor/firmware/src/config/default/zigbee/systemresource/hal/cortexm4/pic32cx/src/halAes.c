/*******************************************************************************
  HAL Advanced Encryption Standard Source File

  Company:
    Microchip Technology Inc.

  File Name:
    hal_aes.c

  Summary:
    This file contains the Implementation BitCloud HAL AES for pic32cx.

  Description:
    This file contains the Implementation BitCloud HAL AES for pic32cx.
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



#if defined(__ICCARM__)
#include <pic32cx1012bz25048.h>
#elif defined (__GNUC__)
#include <xc.h>
#endif

#include <hal/cortexm4/pic32cx/include/halAes.h>
#include <hal/cortexm4/pic32cx/include/halDbg.h>
#include <systemenvironment/include/sysQueue.h>
#include <hal/include/halTaskManager.h>
#include <systemenvironment/include/sysAssert.h>

//Instance of Crypto
static CRYPT_AES_CTX aes;

static DECLARE_QUEUE(halAesRequestQueue);

HAL_AES_EncryptReq_t req;


/**************************************************************************//**
\brief HAL AES Encrypt Function Request

\param[in] reqParams_s - request structure of AES
\return None
******************************************************************************/
void HAL_AES_EncryptReq(HAL_AES_EncryptReq_t *reqParams_s)
{
  memcpy(&req,reqParams_s , sizeof(HAL_AES_EncryptReq_t));

  halPostTask(HAL_SM_REQ);
}

/**************************************************************************//**
\brief HAL SmReset

\param[out] None
\param[in] None
\return None
******************************************************************************/
void HAL_SmReset(void)
{
  resetQueue(&halAesRequestQueue);
  halClearTask(HAL_SM_REQ);
}

/**************************************************************************//**
\brief Aes HAL Init

\param[out] None
\param[in] None
\return None
******************************************************************************/
void halAesInit(void)
{
   //Nothing to do
}

void halAesSetKeyIV(const uint8_t *key, const uint8_t *iv)
{
    CRYPT_AES_KeySet(&aes, key, AES_BLOCK_SIZE, iv, AES_DECRYPTION);
}

void halAesCBC_Decrypt(uint8_t *text, uint32_t length)
{
    CRYPT_AES_CBC_Decrypt(&aes, text, text, length);
}


/**************************************************************************//**
\brief Aes HAL Handling of request

\param[out] None
\param[in] None
\return None
******************************************************************************/
void halSmRequestHandler (void)
{
    HAL_AES_EncryptReq_t *reqParams = NULL;

    reqParams = &req; //getQueueElem(&halAesRequestQueue);
    if (NULL != reqParams)
    {
        switch (reqParams->aesCmd)
        {
            case SM_SET_KEY_COMMAND :
            CRYPT_AES_KeySet(&aes, reqParams->text,AES_BLOCK_SIZE, NULL/*IV - For ECB*/, AES_ENCRYPTION);
            CRYPT_AES_KeySet(&aes, reqParams->text,AES_BLOCK_SIZE, NULL/*IV - For ECB*/, AES_DECRYPTION);          
            break;
        
            case SM_ECB_ENCRYPT_COMMAND :
            CRYPT_AES_DIRECT_Encrypt(&aes, reqParams->text,reqParams->text);
            break;

            case SM_ECB_DECRYPT_COMMAND :
            CRYPT_AES_DIRECT_Decrypt(&aes, reqParams->text,reqParams->text);
            break;


            default:
            SYS_E_ASSERT_FATAL(false, HAL_AES);
            break;
        }

        SYS_E_ASSERT_FATAL(reqParams->encryptConf, HAL_AES);
        reqParams->encryptConf();
    }
}
