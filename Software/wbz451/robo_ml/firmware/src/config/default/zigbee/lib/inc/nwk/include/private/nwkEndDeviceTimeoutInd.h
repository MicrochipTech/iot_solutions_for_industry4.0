// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK EndDevice Timeout Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkEndDeviceTimeoutCommandInd.h

  Summary:
    This file provides interface to the NWK EndDevice Timeout Handling.

  Description:
    This file provides interface to the NWK EndDevice Timeout Handling.
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
#ifndef _NWK_END_DEVICE_TIMEOUT_COMMAND_IND_H
#define _NWK_END_DEVICE_TIMEOUT_COMMAND_IND_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <nwk/include/private/nwkFrame.h>
#include <nwk/include/nldeData.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/nwkEndDeviceTimeout.h>

/******************************************************************************
                              Definitions section
******************************************************************************/
// DOM-IGNORE-BEGIN
/** Total size of end device timeout response - NWK header + payload */
#define TOTAL_ENDDEVICE_TIMEOUT_RESP_CMD_SIZE 27U

#define NWK_ENDDEVICE_TIMEOUT_RESP_TX_PARAMETERS \
  {NWK_TX_DELAY_UNICAST_COMMAND, nwkPrepareEndDeviceTimeoutRespTx, nwkConfirmEndDeviceTimeoutRespTx, true}
// DOM-IGNORE-END

/******************************************************************************
                                 Types section
******************************************************************************/
/** Internal states for end device timeout indication component. */
typedef enum
{
  NWK_ENDDEVICE_TIMEOUT_IND_FREE_STATE = 0x00,
  NWK_ENDDEVICE_TIMEOUT_IND_FIRST_STATE,
  NWK_ENDDEVICE_TIMEOUT_IND_PENDING_STATE = NWK_ENDDEVICE_TIMEOUT_IND_FIRST_STATE,
  NWK_ENDDEVICE_TIMEOUT_IND_SEND_REPONSE_STATE,
  NWK_ENDDEVICE_TIMEOUT_IND_INDICATE_STATE,
  NWK_ENDDEVICE_TIMEOUT_IND_CONFIRM_STATE,
  NWK_ENDDEVICE_TIMEOUT_IND_LAST_STATE
} NwkEndDeviceTimeoutIndState_t;

BEGIN_PACK
typedef struct PACK
{
  /** Id of end device timeout request command. ZigBee spec r17, Table 3.40
   * and Child Aging and Recovery Protocol r20, 7.2. */
  NwkCommandIdField_t commandId;
  /** The success or failure result of the previously received
   * End Device Timeout Request command.
   * Child Aging and Recovery Protocol r20, 7.2. */
  uint8_t status;
  /* This bitmask indicates the parent routerâ??s support information to the child device.
   * Child Aging and Recovery Protocol r20, 7.2. */
  LITTLE_ENDIAN_OCTET (4, (
    /** MAC Data Poll Keepalive supported. */
    NwkBitField_t macDataPollKeepAlive        : 1,
    /** Orphan Notification Keepalive supported. */
    NwkBitField_t endDeviceTimeoutKeepAlive   : 1,
    NwkBitField_t powerNegotiationSupport     : 1,
    NwkBitField_t reserved                    : 5
  ))
} NwkEndDeviceTimeoutRespCmd_t;
END_PACK

/** Internal structure. End device timeout indication object. */
typedef struct
{
  /** Finite-state machine. */
  NwkEndDeviceTimeoutIndState_t state;
  /** Response status. */
  NWK_Status_t status;
  /** The short address of request sender. */
  ShortAddr_t shortAddr;
  /** The IEEE address of request sender. */
  ExtAddr_t extAddr;
  /** The requested timeout enumeration. */
  NwkEndDeviceTimeout_t timeout;
  /** The requested end device configuration. */
  uint8_t endDeviceConfiguration;
  /** Parent information bitmask. */
  uint8_t parentInformation;
} NwkEndDeviceTimeoutIndObj_t;

/* Array of end device timeout indication objects. */
typedef struct
{
  /* Total amount of indication objects. */
  uint8_t amount;
  /* Pointer to array of objects. */
  NwkEndDeviceTimeoutIndObj_t *objects;
} NwkEndDeviceTimeoutInd_t;

/******************************************************************************
                             Prototypes section
******************************************************************************/
#ifdef _CHILD_MANAGEMENT_
#if defined _ROUTER_ || defined _COORDINATOR_
/**************************************************************************//**
  \brief Reset the end device timeout indication component.
 ******************************************************************************/
NWK_PRIVATE void nwkResetEndDeviceTimeoutInd(void);

/**************************************************************************//**
  \brief End device timeout request has been received.

  \param[in] payload - command payload pointer.
  \param[in] header  - command parameters.
  \param[in] parse   - source and destination extended address pointers.

  \return 'true' if continue processing of command packet otherwise 'false'.
 ******************************************************************************/
NWK_PRIVATE bool nwkEndDeviceTimeoutRequestFrameInd(const uint8_t *const payload,
  const NwkFrameHeader_t *const header, const NwkParseHeader_t *const parse);

/**************************************************************************//**
  \brief Task handler of NWK end device timeout indication component.
 ******************************************************************************/
NWK_PRIVATE void nwkEndDeviceTimeoutIndTaskHandler(void);

/**************************************************************************//**
  \brief Prepare header and payload of the end device timeout response command.

  \param[in] outPkt - pointer to output packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkPrepareEndDeviceTimeoutRespTx(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Confirmation of end device timeout response command transmission.

  \param[in] outPkt - pointer to output packet.
  \param[in] status - network status of end device timeout response transmission.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkConfirmEndDeviceTimeoutRespTx(NwkOutputPacket_t *const outPkt,
  const NWK_Status_t status);

#else /* _ROUTER_ or _COORDINATOR_ */
  #define nwkEndDeviceTimeoutRequestFrameInd NULL
  #define nwkResetEndDeviceTimeoutInd() (void)NULL
  #define nwkEndDeviceTimeoutIndTaskHandler NULL
  #define nwkPrepareEndDeviceTimeoutRespTx NULL
  #define nwkConfirmEndDeviceTimeoutRespTx NULL
#endif /* _ROUTER_ or _COORDINATOR_ */
#else /* _CHILD_MANAGEMENT_ */
  #define nwkResetEndDeviceTimeoutInd() (void)NULL
  #define nwkEndDeviceTimeoutIndTaskHandler NULL
  #define nwkPrepareEndDeviceTimeoutRespTx NULL
  #define nwkConfirmEndDeviceTimeoutRespTx NULL
#endif /* _CHILD_MANAGEMENT_ */
#endif /* _NWK_END_DEVICE_TIMEOUT_COMMAND_IND_H */
/** eof nwkEndDeviceTimeoutCommandInd.h */
