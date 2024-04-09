// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object and zigbee device profile request Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoZdpReq.h

  Summary:
    The header file describes the constants, types and internal interface
    of ZDP manager. This component manages ZDP requests and responses.

  Description:
    The header file describes the constants, types and internal interface
    of ZDP manager. This component manages ZDP requests and responses.
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
#if !defined _ZDO_ZDP_REQ_H
#define _ZDO_ZDP_REQ_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysQueue.h>
#include <zdo/include/zdo.h>
#include <systemenvironment/include/sysTimer.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Internal states of ZDP requests. */
typedef enum _ZdoZdpReqState_t
{
  ZDO_IDLE_ZDP_REQUEST_STATE,
  ZDO_SEND_ZDP_REQUEST_STATE,
  ZDO_WAIT_RESP_CONF_ZDP_REQUEST_STATE,
  ZDO_WAIT_CONF_ZDP_REQUEST_STATE,
  ZDO_WAIT_RESP_ZDP_REQUEST_STATE,
  ZDO_CONFIRM_MDR_ZDP_REQUEST_STATE,
  ZDO_CONFIRM_MDR1_ZDP_REQUEST_STATE,
  ZDO_CONFIRM_ZDP_REQUEST_STATE,
  ZDO_WAIT_CONFIRM_UPDATE_ZDP_REQUEST_STATE,
  ZDO_WAIT_CONFIRM_CALLBACK
} ZdoZdpReqState_t;

/** Internal variables of the component which processes incoming ZDP requests. */
typedef struct _ZdoZdpReq_t
{
  /** The queue of incoming ZDP requests. */
  QueueDescriptor_t queue;
  /** The time to track ttl of ZDP requests. */
  SYS_Timer_t       timer;
  /** Current ZDP Transaction Sequence Number. */
  uint8_t           seqNum;
} ZdoZdpReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Main task handler of this module.
  \param None
  \return None
 ******************************************************************************/
ZDO_PRIVATE void zdoZdpReqHandler(void);

/**************************************************************************//**
  \brief TTL initialization of the ZDP request.

  \param[in] zdpReq - the pointer to the ZDP request.
  \param[in] ttl - new value of the time-to-leave field of the ZDP request.

  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoInitZdpRequestTTL(ZDO_ZdpReq_t *const zdpReq, const uint32_t ttl);

/*************************************************************************//**
  \brief Process an incoming ZDP command response.

    Match the incoming ZDP response with a pending ZDP request.

  \param[in] apsDataInd - pointer to APSDE-DATA indication structure of
                          received ZDP command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoProcessZdpResponse(APS_DataInd_t *apsDataInd);

/**************************************************************************//**
  \brief Resets the ZDP component.
 ******************************************************************************/
ZDO_PRIVATE void zdoZdpResetReq(void);

/**************************************************************************//**
  \brief Is the incoming ZDP request unicast?

  \param[in] apsDataInd - the pointer to APS_DataInd_t structure which is
                          related to the received ZDP request.

  \return true if the ZDP request is unicast packet otherwise return false.
 ******************************************************************************/
ZDO_PRIVATE bool zdoIsZdpReqUnicast(const APS_DataInd_t *const apsDataInd);

/**************************************************************************//**
  \brief Returns next ZDO frame sequence number
  note Sequence number value will also updated internally

  \return next ZDO frame sequence number
 ******************************************************************************/
ZDO_PRIVATE uint8_t ZDO_GetNextSequenceNumber(void);

/**************************************************************************//**
  \brief ############## TOdo by Unithra
  \param [in] APS_DataInd_t - ### todo by unithra
  \return ### todo by unithra
 ******************************************************************************/
bool validateZdpResponse(const APS_DataInd_t *const apsDataInd);


#endif /* _ZDO_ZDP_REQ_H */
/** eof zdoZdpReq.h */
