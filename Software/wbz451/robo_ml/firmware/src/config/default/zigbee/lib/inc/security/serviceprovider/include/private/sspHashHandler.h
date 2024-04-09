/*******************************************************************************
  Security Service Provider Hash Handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sspHashHandler.h

  Summary:
    This file contains the SSP Hash routine declaration.

  Description:
    This file contains the SSP Hash routine declaration.
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


#ifndef _SSPHASHHANDLER_H
#define _SSPHASHHANDLER_H

#ifdef _LINK_SECURITY_

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <security/serviceprovider/include/sspCommon.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/
#define MAX_HASH_TEXT_SIZE 53 // 1 + 2*sizeof(uint64_t) + 2*CHALLENGE_SIZE + sizeof(uint32_t)
#define IPAD               0x36
#define OPAD               0x5C

/******************************************************************************
                        Types' definitions section.
******************************************************************************/
/******************************************************************************
  TBD
******************************************************************************/
typedef struct
{
  // Service field - for internal needs.
  SSP_Service_t service;
  // There is should be an additional memory before and after text (16 bytes in both cases).
  uint8_t *text/*[SECURITY_KEY_SIZE + textSize + 16]*/;
  // Pointer to key fir Keyed Hash Function.
  const uint8_t *key/*[SECURITY_KEY_SIZE]*/;
  // Size of the text.
  uint8_t textSize;
  // Buffer for generated hash. Shoul be initialized by the user.
  uint8_t *hash_i/*[SECURITY_KEY_SIZE]*/;
  void (*sspKeyedHashMacConfirm)(void);
} SspKeyedHashMacReq_t;

/******************************************************************************
  TBD
******************************************************************************/
typedef enum
{
  HASH_STATE_IDLE,
  HASH_STATE_CREATE_HASH1,
  HASH_STATE_CREATE_HASH2,
} SspHashHandlerState_t;

/******************************************************************************
  TBD
******************************************************************************/
typedef struct
{
  uint8_t *M/*[textSize + 16]*/;
  uint8_t *hash_i/*[SECURITY_KEY_SIZE]*/;
  uint8_t textSize;
  void (*bcbHashConf)(void);
} SspBcbHashReq_t;

/******************************************************************************
  TBD
******************************************************************************/
typedef struct
{
  SspBcbHashReq_t       *currentBcbHashReq;
  SspKeyedHashMacReq_t  *keyedHashMacReq;
  SspBcbHashReq_t       bcbHashReq;
  uint8_t               bcbBlockCounter;
  SspHashHandlerState_t hashHandlerState;
} SspHashHandlerMem_t;


/******************************************************************************
                        Prototypes section.
******************************************************************************/
/*******************************************************************************
  Keyed hash function implementation.
  Parameters:
    param - parameters of the primitive (for detailed description look at
             SspKeyedHashMacReq_t declaration).
  Return:
    none.
********************************************************************************/
void sspKeyedHashMacReq(SspKeyedHashMacReq_t *param);

/*******************************************************************************
  Block Cipher Based hash function implementation.
  Parameters:
    param - parameters of the primitive (for detailed description look at
             SspBcbHashReq_t declaration).
  Return:
    none.
********************************************************************************/
void sspBcbHashReq(SspBcbHashReq_t *param);

#endif // _LINK_SECURITY_

#endif //_SSPHASHHANDLER_H

//eof sspHashHandler.h
