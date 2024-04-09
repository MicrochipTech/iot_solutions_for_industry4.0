// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Join Indication Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkJoinInd.h

  Summary:
    This file contains the parameters required for NWK Join Indication of a Zigbee Device.

  Description:
    This file contains the parameters required for NWK Join Indication of a Zigbee Device.
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
#if !defined _NWK_JOININD_H
#define _NWK_JOININD_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/mac.h>
#include <nwk/include/nldeData.h>
#include <nwk/include/nwkNeighbor.h>
#include <nwk/include/private/nwkFrame.h>

/******************************************************************************
                               Define(s) section
 ******************************************************************************/
#define NWK_JOIN_RESP_TX_PARAMETERS \
  {NWK_TX_DELAY_UNICAST_COMMAND, nwkPrepareJoinRespTx, \
    nwkConfirmJoinRespTx, true}

#define NWK_ADDR_CONFLICT_JOIN_RESP_TX_PARAMETERS \
  {NWK_TX_DELAY_UNICAST_COMMAND, nwkPrepareJoinRespTx, \
   nwkConfirmAddrConflictJoinRespTx, true}

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Payload of rejoin response command */
BEGIN_PACK
typedef struct PACK
{
  NwkCommandIdField_t commandId;
  /** If the rejoin was successful, this two-octet field contains the new
   * network address assigned to the rejoining device. If the rejoin was
   * not successful, this field contains the broadcast address (0xffff).
   * ZigBee spec r17, 3.4.7.3.1. */
  ShortAddr_t networkAddr;
  /** This field shall contain one of the nonreserved association status values
   **/
  uint8_t rejoinStatus;
} NwkRejoinRespCmd_t;
END_PACK

/** Service fields of rejoin response */
typedef struct _NwkRejoinResp_t
{
  ExtAddr_t extendedAddr;
  ShortAddr_t newNetworkAddr;
  ShortAddr_t oldNetworkAddr;
  uint8_t status;
  bool secureJoin;
} NwkRejoinResp_t;

/** States of join indication object */
typedef enum _NwkJoinIndObjState_t
{
  NWK_JOIN_IND_FREE_STATE = 0x00,
  NWK_JOIN_IND_FIRST_STATE = 0x01,
  NWK_JOIN_IND_PENDING_STATE = NWK_JOIN_IND_FIRST_STATE,
  NWK_JOIN_IND_ASSOC_INDICATE_STATE = 0x02,
  NWK_JOIN_IND_REJOIN_INDICATE_STATE = 0x03,
  NWK_JOIN_IND_SEND_REJOIN_RESPONSE_STATE = 0x04,
  NWK_JOIN_IND_SEND_ASSOC_RESPONSE_STATE = 0x05,
  NWK_JOIN_IND_LAST_STATE
} NwkJoinIndObjState_t;

/** Join indication object */
typedef struct _NwkJoinIndObj_t
{
  NwkJoinIndObjState_t state;
  MAC_CapabilityInf_t capabilityInformation;
  union
  {
    MAC_AssociateResp_t assoc;
    NwkRejoinResp_t rejoin;
  } resp;
} NwkJoinIndObj_t;

/** Type of total amount of join indication objects. */
typedef uint8_t NwkJoinIndObjAmount_t;

/** Array of join indication objects */
typedef struct _NwkJoinInd_t
{
  NwkJoinIndObjAmount_t totalObjects;
  NwkJoinIndObj_t *objects;
} NwkJoinInd_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
#if defined _ROUTER_ || defined _COORDINATOR_
/**************************************************************************//**
  \brief Rejoin request has been received.

  \param[in] payload - command payload pointer.
  \param[in] header  - command parameters.
  \param[in] parse   - source and destination extended address pointers.

  \return 'true' if continue processing of command packet otherwise 'false'.
 ******************************************************************************/
NWK_PRIVATE bool nwkRejoinRequestFrameInd(const uint8_t *const payload,const NwkFrameHeader_t *const header, const NwkParseHeader_t *const parse);

#if defined _RESOLVE_ADDR_CONFLICT_
/**************************************************************************//**
  \brief Reporting of end device address conflict.

  \param[in] child - pointer to child's entry in the neighbor table.
 ******************************************************************************/
NWK_PRIVATE void nwkSendUnsolicitedRejoinResponse(const NwkNeighbor_t *const child);

#endif /* _RESOLVE_ADDR_CONFLICT_ */

/**************************************************************************//**
  \brief Task handler of join indication component
 ******************************************************************************/
NWK_PRIVATE void nwkJoinIndTaskHandler(void);

/**************************************************************************//**
  \brief Reset the join indication component.
 ******************************************************************************/
NWK_PRIVATE void nwkResetJoinInd(void);

/**************************************************************************//**
  \brief Prepare header and payload of the rejoin response command.

  \param[in] outPkt - pointer to output packet.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkPrepareJoinRespTx(NwkOutputPacket_t *const outPkt);

/**************************************************************************//**
  \brief Confirmation of rejoin response command transmission.

  \param[in] outPkt - pointer to output packet.
  \param[in] status - network status of rejoin response transmission.
  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkConfirmJoinRespTx(NwkOutputPacket_t *const outPkt, const NWK_Status_t status);

/**************************************************************************//**
  \brief Adding child into table.
    All required fields are filled. Address is allocated.

  \param[in] extAddr - extended IEEE address of child.
  \param[in] shortAddr - address that device selected for itself,
                         trying to keep it.
  \param[in] capability - MAC capability information.

  \return NULL if fail, or pointer to created record otherwise.
 ******************************************************************************/
NWK_PRIVATE NwkNeighbor_t* nwkAddChild(const ExtAddr_t extAddr, ShortAddr_t shortAddr, const MAC_CapabilityInf_t capability, const Lqi_t lqi, const Rssi_t rssi,    bool isMACapNeedUpdate);

/***************************************************************************//**
  \brief nwkJoinInd idle checking.

  \return true, if nwkJoinInd performs no activity, false - otherwise.
 ******************************************************************************/
NWK_PRIVATE bool nwkJoinIndIsIdle(void);
#if defined _RESOLVE_ADDR_CONFLICT_
/**************************************************************************//**
  \brief Confirmation of address conflict rejoin response transmission.

  \param[in] outPkt - pointer to output packet.
  \param[in] status - network status of rejoin response transmission.
 ******************************************************************************/
NWK_PRIVATE void nwkConfirmAddrConflictJoinRespTx(NwkOutputPacket_t *const outPkt, const NWK_Status_t status);
#else
#define nwkConfirmAddrConflictJoinRespTx NULL
#endif /* _RESOLVE_ADDR_CONFLICT_ */

#else /* _ROUTER_ or _COORDINATOR_ are not defined. */

#define nwkRejoinRequestFrameInd NULL
#define nwkJoinIndTaskHandler NULL
#define nwkResetJoinInd() (void)0
#define nwkPrepareJoinRespTx NULL
#define nwkConfirmJoinRespTx NULL
#define nwkConfirmAddrConflictJoinRespTx NULL
#define nwkJoinIndIsIdle NULL

#endif /* _ROUTER_ or _COORDINATOR_ */
#endif /* _NWK_JOININD_H */
/** eof nwkJoinInd.h */

