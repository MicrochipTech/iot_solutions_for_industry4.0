// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object management network update Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoMgmtNwkUpdate.h

  Summary:
    This file contains the Interface of ZDO Mgmt Nwk Update Request/Notify.

  Description:
    This file contains the Interface of ZDO Mgmt Nwk Update Request/Notify.
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
#if !defined _ZDO_MGMT_NWK_UPDATE_H
#define _ZDO_MGMT_NWK_UPDATE_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <hal/include/appTimer.h>
#include <aps/include/aps.h>
#include <zdo/include/private/zdoCommands.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
 
/** Enumerations of internal states of the component. */
typedef enum _ZdoMgmtNwkUpdateState_t
{
  ZDO_MGMT_NWK_UPDATE_IDLE_STATE,
  ZDO_MGMT_NWK_UPDATE_SEND_ERROR_STATE,
  ZDO_MGMT_NWK_UPDATE_SET_TIMER_STATE,
  ZDO_MGMT_NWK_UPDATE_SET_CHANNEL_STATE,
  ZDO_MGMT_NWK_UPDATE_ED_SCAN_STATE,
  ZDO_MGMT_NWK_UPDATE_ED_SCAN_REPORT_STATE
} ZdoMgmtNwkUpdateState_t;

/** Internale state and variable to process ZDO Mgmt NWK Update commands. */
typedef struct _ZdoMgmtNwkUpdate_t
{
  /* Pointer to allocated ZDO Command to perform requests to the stack and
   * send ZDP Mgmt Nwk Update Notify/Request commands. */  
  ZdoCommand_t *zdoCommand;
  /** This field represents the number of energy scans to be conducted and
   * reported. */
  uint8_t scanCount;
  /** Transaction Sequence Number of the original Mgmt Nwk Update Request. */
  uint8_t seqNum;
  /* Internal state of the Mgmt Nwk Update component. */
  ZdoMgmtNwkUpdateState_t state;
} ZdoMgmtNwkUpdate_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
 
/***************************************************************************//**
  \brief Prepare Mgmt Nwk Update Request command payload.
  \param[in] zdpReq - the pointer to the ZDP request's structure for
                      the Mgmt NWK Update Request Command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoPrepareMgmtNwkUpdateRequest(ZDO_ZdpReq_t *zdpReq);

/**************************************************************************//**
  \brief Prepare Mgmt Nwk Update Notify command payload.
  \param[in] zdpReq - the pointer to the ZDP request's structure for
                      the Mgmt NWK Update Notify Command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoPrepareMgmtNwkUpdateNotify(ZDO_ZdpReq_t *zdpReq);

/**************************************************************************//**
  \brief Process a Mgmt Nwk Update Request command.
 
  \param[in] apsDataInd - pointer to APSDE-DATA indication parameters structure
                          of received Mgmt Nwk Update Request command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoMgmtNwkUpdateInd(const APS_DataInd_t *const apsDataInd);

/*************************************************************************//**
  \brief Process Mgmt Nwk Update Notify command.
 
  \param[in] apsDataInd - pointer to APSDE-DATA indication parameters structure
                          of received Mgmt Nwk Update Notify response command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoMgmtNwkUpdateNotifyInd(const APS_DataInd_t *const apsDataInd);

/**************************************************************************//**
  \brief Resets the Mgmt Nwk Update module to the idle state.
 ******************************************************************************/
ZDO_PRIVATE void zdoResetMgmtNwkUpdate(void);

#ifdef _FREQUENCY_AGILITY_
/**************************************************************************//**
  \brief Prepare Mgmt Nwk Unsolicted Enhanced Update Notify command payload.
  \param[in] zdpReq - the pointer to the ZDP request's structure for
                      the Mgmt NWK Update Notify Command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoPrepareMgmtNwkUnsolicitedEnhancedUpdateNotify(ZDO_ZdpReq_t *zdpReq);

/**************************************************************************//**
  \brief Process Mgmt Nwk Unsolicited NWK Update Notify Ind.

  \param[in] apsDataInd - pointer to APSDE-DATA indication parameters structure
                          of received Mgmt Nwk Update Notify response command.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoMgmtNwkUnsolicitedEnhancedUpdateNotifyInd(const APS_DataInd_t *const apsDataInd);

/**************************************************************************//**
  \brief Reports to the NWK Manager about link problems.

  \return 'true' if the procedure was initiated successfully otherwise 'false'.
 ******************************************************************************/
ZDO_PRIVATE bool zdoBadLinkReport(void);
#endif // _FREQUENCY_AGILITY_
#endif /* _ZDO_MGMT_NWK_UPDATE_H */
/** eof zdoMgmtNwkUpdate.h */
