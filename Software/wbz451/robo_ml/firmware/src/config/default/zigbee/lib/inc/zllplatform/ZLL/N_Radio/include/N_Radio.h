/*******************************************************************************
  ZLL Radio Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Radio.h

  Summary:
    This file contains the ZLL Radio functions.

  Description:
    This file contains the ZLL Radio functions.
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


#ifndef N_RADIO_H
#define N_RADIO_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"
#include <mac_phy/include/phy.h>
#include <mac_phy/include/macEnvironment.h>
#include <mac_phy/include/macCommon.h>

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

typedef enum CarrierMode_t
{
    CARRIER_MODE_UNMODULATED,
    CARRIER_MODE_MODULATED_SPECTRUM
} CarrierMode_t;

typedef struct N_Radio_Callback_t
{
    /** Notify when the MAC layer starts the clear channel assessment before a transmission.
        \param txDataLength The length of the packet that will be transmitted

        \note The callback comes from an Interrupt Service Routine
    */
    void (*MacEnteringTxMode)(uint8_t txDataLength);

    int8_t endOfList;
} N_Radio_Callback_t;

/* Callback on TxPower setting */
typedef void (*N_Radio_SetTxPowerDone_t)(void);

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/
/**************************************************************************//**
  \brief Subscribe for events from this component.

  \param[in] pCallback pointer to callback

  \return None.
 *****************************************************************************/
void N_Radio_Subscribe(const N_Radio_Callback_t* pCallback);

/**************************************************************************//**
  \brief Set the transmit power.

  \param txPower The TXPOWER radio register value to use
  \param setTxPowerDone Callback on tx power setting completion

  \return None.
 *****************************************************************************/
void N_Radio_SetTxPower(uint8_t txPower, N_Radio_SetTxPowerDone_t setTxPowerDone);

/**************************************************************************//**
  \brief Get the transmit power.

  \return The TXPOWER radio register value.
 *****************************************************************************/
uint8_t N_Radio_GetTxPower(void);

/**************************************************************************//**
  \brief Turn on the radio to continuously transmit a modulated or unmodulated carrier.
         This function can be used for emmission tests of the radio, but use it with care.
         \li The function should only be used on a factory new device
         \li The carrier will block all communication on the channel
         \li To return the radio to its normal operating mode the device must be reset
         \li The transmit power cannot be changed after calling this function
 
  \param channel The ZigBee channel on which to transmit
  \param carrierMode Select a modulated or unmodulated carrier

  \return The TXPOWER radio register value.
 *****************************************************************************/
void N_Radio_SetCarrier(uint8_t channel, CarrierMode_t carrierMode);

/**************************************************************************//**
  \brief Sets CCA Mode.

  \param ccaMode - CCA mode set request parameter.
  \param setCcaModeDone - callback on CCA mode setting completion.

  \return None.
 *****************************************************************************/
void N_Radio_SetCcaMode(PHY_CcaMode_t ccaMode, void (*setCcaModeDone)(MAC_Status_t *status));

/**************************************************************************//**
  \brief Sets the current channel.

  \param channel - the channel to switch to.
  \param setChannelDoneCb - callback on channel setting completion.
******************************************************************************/
void N_Radio_SetChannel(uint8_t channel, void (*setChannelDoneCb)(MAC_SetConf_t *conf));

/**************************************************************************//**
  \brief Sets ED Threshold value.

  \param ccaEdThres - ED Threshold value set request parameter.
  \param setCcaEdThreshdone - callback on CCA ED Threshold completion.
  
  \return None
******************************************************************************/
void N_Radio_SetCcaEdThreshold_Impl(uint8_t ccaEdThres, void (*setCcaEdThreshdone)(MAC_Status_t *status));

/**************************************************************************//**
  \brief Disables device's Radio
  
  \return None
******************************************************************************/
void N_Radio_Disable(void (*disableRadioCb)(void));

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_RADIO_H
