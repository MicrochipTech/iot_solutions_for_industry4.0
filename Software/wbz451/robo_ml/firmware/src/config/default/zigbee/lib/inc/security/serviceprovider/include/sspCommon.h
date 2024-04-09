/*******************************************************************************
  Security Service Provider Common Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sspCommon.h

  Summary:
    This file contains the Declarations of common Security Service Provider's fields
    and types.

  Description:
    This file contains the Declarations of common Security Service Provider's fields
    and types.
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


#ifndef _SSPCOMMON_H
#define _SSPCOMMON_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/
#define SECURITY_KEY_SIZE   16U
#define SECURITY_BLOCK_SIZE 16U
#define SECURITY_NONCE_SIZE 13U
#define SSP_SECURITY_CONTROL_FIELD_LENGTH 1U
#define SSP_FRAME_COUNTER_FIELD_LENGTH    4U
#define SSP_KEY_SEQ_NUMBER_FIELD_LENGTH   1U

/******************************************************************************
                        Types section.
******************************************************************************/
/**************************************************************************//**
  \brief Possible status values of different SSP primitives.
******************************************************************************/
typedef enum
{
  SSP_SUCCESS_STATUS,
  SSP_NOT_PERMITTED_STATUS,
  SSP_MAX_FRM_COUNTER_STATUS,
  SSP_BAD_CCM_OUTPUT_STATUS,
  SSP_INVALID_MIC_STATUS,
} SSP_Status_t;

/**************************************************************************//**
  \brief Internal service fields which give an opportunity to compose requests' queue.
******************************************************************************/
typedef struct
{
  void    *next;
  uint8_t requestId;
#ifdef _ZAPPSI_
  /* Sequence number to identify request-response pair. */
  uint8_t sequenceNumber;
  union
  {
  /*Callback wrapper routine pointer */
    void (*callback)(void*);
  /* Processing routine pointer to call after required memory will become free */
    void (*process)(void*);
  } zsi;
#endif 

} SSP_Service_t;


/******************************************************************************
                      Prototypes section
 ******************************************************************************/
/*******************************************************************************
  Checks a security key.
  Parameters:
    key - valid pointer to a security key.
  Return:
    true - if key is not zero otherwise return false.
********************************************************************************/
bool SSP_IsKeyValid(const uint8_t *key);


#endif //_SSPCOMMON_H

// eof sspCommon.h
