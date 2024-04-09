/*******************************************************************************
  MAC Common Status Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macCommStatus.h

  Summary:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    comm status primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    comm status primitives.
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

#ifndef _MACCOMMSTATUS_H
#define _MACCOMMSTATUS_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/

/******************************************************************************
                        Types section.
******************************************************************************/

/**
 * \brief MLME-COMM_STATUS indication primitive's parameters.
 * IEEE 802.15.4-2006 7.1.12.1 MLME-COMM-STATUS.indication.
*/
typedef struct
{
  //! The individual device address of the entity from which the frame causing
  //! the error originated.
  MAC_Addr_t     srcAddr;
  //! The individual device address of the device for which the frame was intended.
  MAC_Addr_t     dstAddr;
  //! The 16-bit PAN identifier of the device from which the frame was received
  //! or to which the frame was being sent.
  PanId_t        panId;
  //! The source addressing mode for this primitive.
  MAC_AddrMode_t srcAddrMode;
  //! The destination addressing mode for this primitive.
  MAC_AddrMode_t dstAddrMode;
  //! The communications status.
  MAC_Status_t   status;
}  MAC_CommStatusInd_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief This function is called if any error is occured during frame processing.

    Memory which was allocated for parameters will be free immediately after
  return from this function.

  \param commStat - MLME-COMM_STATUS indication parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_CommStatusInd(MAC_CommStatusInd_t *commStat);

#endif //_MACCOMMSTATUS_H

// eof macCommStatus.h
