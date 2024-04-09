/*******************************************************************************
  MAC Environment Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macEnvironment.h

  Summary:
    This file provides access to Public interface of MAC Environment.

  Description:
    This file provides access to Public interface of MAC Environment.
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

#ifndef _MAC_ENVIRONMENT_H
#define _MAC_ENVIRONMENT_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Gets pointer to extended address.
  \return pointer to extended address.
 ******************************************************************************/
const ExtAddr_t* MAC_GetExtAddr(void);

/**************************************************************************//**
  \brief Sets extended address.
  \param extAddr - extended address.

  \return none.
 ******************************************************************************/
void MAC_SetExtAddr(const ExtAddr_t *const extAddr);

/**************************************************************************//**
  \brief Checks, if extended address is equal to our own one
  \param extAddr - pointer to extended address to check

  \return true, if extended address is equal to our own one; false - otherwise
 ******************************************************************************/
bool MAC_IsOwnExtAddr(const ExtAddr_t *const extAddr);

/**************************************************************************//**
  \brief Convert octet amount to transmit duration.
  \param octets - number of octets.

  \return Time of octets transmission in milliseconds.
 ******************************************************************************/
uint32_t MAC_GetOctetsTransmissionTimeInMs(const uint32_t octets);

/**************************************************************************//**
  \brief Checks if there are any active transactions on MAC layer.

  \return true, if there are any active transactions on MAC layer,
          false - otherwise
 ******************************************************************************/
bool MAC_IsActiveTransaction(void);

#endif /* _MAC_ENVIRONMENT_H */
/** eof macEnvironment.h */
