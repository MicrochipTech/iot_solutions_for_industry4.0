/*******************************************************************************
  ZLL Radio Internal Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Radio_Internal.h

  Summary:
    This file contains the ZLL Radio Internal functions.

  Description:
    Implementation of internal interface to transceiver.
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


#ifndef N_RADIO_INTERNAL_H
#define N_RADIO_INTERNAL_H

/******************************************************************************
                               Prototypes section
 *****************************************************************************
*/

/**************************************************************************//**
  \brief Sets the current channel.

  \param channel - the channel to switch to.
  \param setChannelDoneCb - callback on channel setting completion.
  
  \return None
******************************************************************************/
void N_Radio_SetChannel_Impl(uint8_t channel, void (*setChannelDoneCb)(MAC_SetConf_t *conf));


#endif // N_RADIO_INTERNAL_H

/* eof N_Radio_Internal.h */