// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Transmission Delay Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkTxDelay.h

  Summary:
    This file contains the Interface of transmission delays.

  Description:
    This file contains the Interface of NWK transmission delays.
 *******************************************************************************/


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
#if !defined _NWK_TX_DELAY_H
#define _NWK_TX_DELAY_H
// DOM-IGNORE-END


/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <hal/include/appTimer.h>
#include <systemenvironment/include/sysQueue.h>
#include <nwk/include/nldeData.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Internal variables of delay component. */
typedef struct _NwkTxDelay_t
{
  bool isTimerStarted;
  HAL_AppTimer_t timer;
  QueueDescriptor_t queue;
} NwkTxDelay_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Transmission delay request.

  \param[in] delayReq - pointer to delay request's parameters.
  \param[in] macStatus - pointer to MAC status of MLDE-DATA.confirm or NULL if
    it is first transmission.
  \return further behavior.
 ******************************************************************************/
NWK_PRIVATE NwkTxDelayStatus_t nwkTxDelayReq(NwkTxDelayReq_t *const delayReq,
  MAC_Status_t *const macStatus);

/**************************************************************************//**
  \brief The transmission delay has expired.

  \param[in] delayReq - pointer to delay request's parameters.
  \param[in] status - status of further behavior.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkTxDelayConf(NwkTxDelayReq_t *const delayReq, const NwkTxDelayStatus_t status);

/**************************************************************************//**
  \brief Flush all delays.
 ******************************************************************************/
NWK_PRIVATE void nwkFlushTxDelays(void);

/**************************************************************************//**
  \brief Reset delay component.
 ******************************************************************************/
NWK_PRIVATE void nwkResetTxDelays(void);

/******************************************************************************
  \brief nwkTxDelay idle checking.

  \return true, if nwkTxDelay performs no activity, false - otherwise.
 ******************************************************************************/
NWK_PRIVATE bool nwkTxDelayIsIdle(void);

/**************************************************************************//**
  \brief Delivery time of broadcast data transmission on a network.

  \return Current value of broadcast delivery time in milliseconds.
 ******************************************************************************/
NWK_PRIVATE uint32_t nwkGetBroadcastDeliveryTime(void);

#if defined _NWK_PASSIVE_ACK_ && (defined _ROUTER_ || defined _COORDINATOR_)
/**************************************************************************//**
  \brief All expected passive acks are received, confirm the passive ack req.

  \param[in] delayReq - pointer to delay request's parameters.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkPassiveAckConf(NwkTxDelayReq_t *const delayReq);
#endif /* _NWK_PASSIVE_ACK_ */

#endif /* _NWK_TX_DELAY_H */
/** eof nwkTxDelay.h */

