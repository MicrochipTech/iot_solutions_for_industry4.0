/*******************************************************************************
  MAC HWI Scan Handler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwiScanHandler.h

  Summary:
    This file comprises the MAC HWI Scan Handling routines.

  Description:
    This file comprises the MAC HWI Scan Handling routines.
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

#ifndef _MACHWISCANHANDLER_H
#define _MACHWISCANHANDLER_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/mac_hwd_phy/include/machwd.h>
#include <mac_phy/mac_hwi/include/machwiManager.h>

/******************************************************************************
                        Defines section
******************************************************************************/

/******************************************************************************
                         Types section
******************************************************************************/
typedef enum
{
  MACHWI_IDLE_SCAN_STATE,
  MACHWI_SET_CHANNEL_SCAN_STATE,
  MACHWI_SET_BEACON_RX_MODE_SCAN_STATE,
  MACHWI_CLR_BEACON_RX_MODE_SCAN_STATE,
  MACHWI_SET_PAGE_SCAN_STATE,
  MACHWI_RESTORE_TRX_STATE_SCAN_STATE,
  MACHWI_SET_TRX_STATE_RX_ON_SCAN_STATE,
  MACHWI_SET_RF_IRQ_DISABLE_SCAN_STATE,
  MACHWI_SET_RF_IRQ_ENABLE_SCAN_STATE,
  MACHWI_SET_SHORT_ADDR_SCAN_STATE,
  MACHWI_SET_PANID_SCAN_STATE,
  MACHWI_SET_CHANNEL_AFTER_ORPHAN_SCAN_STATE,
  MACHWI_WAIT_SCAN_STATE,
  MACHWI_SCAN_TIME_EXHAUSTED_SCAN_STATE,
  MACHWI_SET_ACTIVE_CHANNEL_SCAN_STATE,
  MACHWI_SET_PANID_BROADCAST_SCAN_STATE,
  MACHWI_SET_PANID_ORIGINAL_SCAN_STATE
} MachwiScanState_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/******************************************************************************
  TBD
 Parameters:
   TBD - TBD.
 Returns:
   TBD.
******************************************************************************/
MachwiHandlerResult_t machwiScanReqHandler(void);


/******************************************************************************
  Indicates, that beacon frame was received.
  Parameters:
    beaconDescr - beacon description.
  Returns:
    none.
******************************************************************************/
void machwiBeaconInd(MAC_FrameDescr_t *beaconDescr);

/******************************************************************************
  Indicates, that coordinator realignment connamd was received.
  Parameters:
    realignmentDescr - realignment command description.
  Returns:
    none.
******************************************************************************/
void machwiCoordRealignmentCommandInd(MAC_FrameDescr_t *realignmentDescr);

/******************************************************************************
  Resets scan handler.
  Parameters:
    none.
  Returns:
    none.
******************************************************************************/
void machwiResetScanHandler(void);

/******************************************************************************
  Calculate scan duration
  Parameters:
    scanDuration - scan duration.
    scanType
  Returns:
    scan duration in ms
******************************************************************************/
uint32_t machwiCalculateScanDuration(uint8_t scanDuration, MAC_ScanType_t scanType);

#endif /* _MACHWISCANHANDLER_H */

// eof machwiScanHandler.h
