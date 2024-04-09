/*******************************************************************************
  RF Register Access Header File

  Company:
    Microchip Technology Inc.

  File Name:
    rfRegAccess.h

  Summary:
    This file comprises the Radio registers access interface.

  Description:
    This file comprises the Radio registers access interface.
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

#if !defined _RFREGACCESS_H
#define _RFREGACCESS_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/

/**//**
 * \brief The type declaration of the RF register value.
 */
typedef uint8_t RF_RegValue_t;

/**//**
 * \brief The type declaration of the RF register address.
 */
typedef uint16_t RF_RegAddress_t;

/**
 * \brief RF register access status type.
 *
 * - RF_REGISTER_SUCCESS_STATUS means that the value of the requested rf
 *   register has been read successfully.
 * - RF_REGISTER_FAIL_STATUS - MAC hardware depended subsystem cannot perform
 *   reading of the register at this time.
 **/
typedef enum _RF_RegAccessStatus_t
{
  RF_REGISTER_SUCCESS_STATUS,
  RF_REGISTER_FAIL_STATUS
} RF_RegAccessStatus_t;

/**//**
 * \brief The structure declaration of RF register access confirmation parameters.
 */
typedef struct _RF_RegAccessConf_t
{
  RF_RegAccessStatus_t status;
  RF_RegValue_t        value;
} RF_RegAccessConf_t;

/**//**
 * \brief Parameters of RF register access request.
 */
typedef struct _RF_RegAccessReq_t
{
  /*! Service field - for internal needs. */
  MAC_Service_t   service;

  /** Value to write to the register. */
  RF_RegAddress_t addr;

  /** Value to write to the register. */
  RF_RegValue_t   value;

  /** RF register access confirm callback function's pointer. 
      Must not be set to NULL. */
  void (*RF_RegAccessConf)(RF_RegAccessConf_t *conf);

  /** Confirmation parameters of processing this request. */
  RF_RegAccessConf_t confirm;
} RF_RegAccessReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Initiates a register writing procedure.

  \param[in] req - pointer to register write parameters -
                   callback and conf status.

  \return None.
 ******************************************************************************/
void RF_RegWriteReq(RF_RegAccessReq_t *const req);

/**************************************************************************//**
  \brief Initiates a register reading procedure.

  \param[in] req - pointer to register read parameters -
                   callback and conf status.

  \return None.
 ******************************************************************************/
void RF_RegReadReq(RF_RegAccessReq_t *const req);

#endif /* _RFREGACCESS_H */
/** eof rfRegAccess.h */
