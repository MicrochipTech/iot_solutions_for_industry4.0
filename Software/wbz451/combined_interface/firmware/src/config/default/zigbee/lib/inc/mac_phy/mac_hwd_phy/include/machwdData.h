/*******************************************************************************
  MAC Hwd Data Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwdData.h

  Summary:
    This file contains the MACHWD data types and function prototypes.

  Description:
    This file contains the MACHWD data types and function prototypes.
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

#ifndef _MACHWDDATA_H
#define _MACHWDDATA_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <mac_phy/mac_hwd_phy/include/machwdService.h>
#include <mac_phy/mac_hwd_phy/include/machwdSetTrx.h>
#include <mac_phy/include/macFrame.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/
/*Indicates generic TX data failures other than the MACHWD_DataStatus_t values*/
#define MACHWD_GENERIC_TX_DATA_FAIL_STATUS   (1 << 7)

/******************************************************************************
                    Types section
******************************************************************************/
//! Set of frame transmission statuses.
typedef enum
{
  MACHWD_DATA_PENDING_DATA_STATUS,
  MACHWD_CHANNEL_ACCESS_FAIL_DATA_STATUS,
  MACHWD_NO_ACK_DATA_STATUS,
  MACHWD_SUCCESS_DATA_STATUS,
} MACHWD_DataStatus_t;

//! MACHWD data confirm structure.
typedef struct
{
  //! Frame transmission status.
  MACHWD_DataStatus_t status;
} MACHWD_DataConf_t;

//! MACHWD data request structure.
typedef struct
{
  //! Service field - for internal needs.
  MACHWD_Service_t  service;
  //! Description of the frame to be transmitted.
  MAC_FrameDescr_t  frameDescr;
  //! Command to set trx state after transmitting frame.
  MACHWD_TrxCmd_t   trxCmdToSetAfterTransmitTrxState;
  //! MACHWD data transmission confirm callback function's pointer.
  void (*MACHWD_DataConf)(MACHWD_DataConf_t *confParams);
  //! MACHWD confirm structure.
  MACHWD_DataConf_t confirm;
#if  defined(_ZGPD_SPECIFIC_) || defined(_GREENPOWER_SUPPORT_)
  uint8_t performCsma;
#endif
} MACHWD_DataReq_t;

//! MACHWD data indication structure.
typedef struct
{
  //! Received frame description.
  MAC_FrameDescr_t frameDescr;
} MACHWD_DataInd_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MACHWD data request primitive's prototype.
  \param reqParams - MACHWD data request's parameters' structure pointer.
  \return none.
******************************************************************************/
void MACHWD_DataReq(MACHWD_DataReq_t *reqParams);

/**************************************************************************//**
  \brief MACHWD data indication primitive's prototype.
  \param indParams - MACHWD data indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MACHWD_DataInd(MACHWD_DataInd_t *indParams);

#endif /* _MACHWDDATA_H */

// eof machwdData.h
