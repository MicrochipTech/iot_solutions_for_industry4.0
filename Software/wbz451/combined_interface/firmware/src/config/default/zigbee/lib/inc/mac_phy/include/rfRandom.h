/*******************************************************************************
  RF Random Header File

  Company:
    Microchip Technology Inc.

  File Name:
    rfRandom.h

  Summary:
    This file contains the Prototype of random generation function.

  Description:
    This file contains the Prototype of random generation function.
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

#ifndef _RFRANDOM_H
#define _RFRANDOM_H

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
//! Random confirm structure.
typedef struct
{
  uint8_t *buff;
  uint16_t value;
} RF_RandomConf_t;

//! Random request structure.
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
#else /*  _ZAPPSI_ */
    uint8_t requestId;
#endif /* _ZAPPSI_ */
  } service;
  /** \endcond **/
  //! The flag indicates that MAC laer has to enable or disable frame receiving
  // during processing of the Random request.
  bool disableRx;

  //! Number of bytes to be generated
  uint8_t numberOfBytes;
  //! Confirm structure on RF_RandomReq.
  RF_RandomConf_t confirm;
  //! Callback on RF_RandomReq. Must not be set to NULL. 
  void (*RF_RandomConf)(RF_RandomConf_t *conf);
} RF_RandomReq_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief Requests random value from RF chip. Valid for RF231 and RF212.
  \param reqParams - request parameters structure pointer.
  \return none.
******************************************************************************/
void RF_RandomReq(RF_RandomReq_t *reqParams);

/**************************************************************************//**
  \brief Requests random value from RF chip. Valid for RF231 and RF212.
  \param reqParams - request parameters structure pointer.
  \return none.
******************************************************************************/
void RF_RandomSeqReq(RF_RandomReq_t *reqParams);

#endif /*_RFRANDOM_H*/

// eof rfRandom.h
