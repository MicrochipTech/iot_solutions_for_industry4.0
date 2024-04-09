/*******************************************************************************
  MAC Scan Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macScan.h

  Summary:
    This file provides access to the MAC Scanning primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    scanning primitives.
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

#ifndef _MACSCAN_H
#define _MACSCAN_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/include/phy.h>
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macBeacon.h>
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                        Defines section
******************************************************************************/
//! Set of MAC scanning types. IEEE 802.15.4-2006 Table 67.
typedef enum
{
  MAC_ED_SCAN      = 0x00,
  MAC_ACTIVE_SCAN  = 0x01,
  MAC_PASSIVE_SCAN = 0x02,
  MAC_ORPHAN_SCAN  = 0x03
} MAC_ScanType_t;


/******************************************************************************
                        Types section
******************************************************************************/
/**
 * \brief Scanning results union. Contains results of energy scanning
 * procedure and passive/active scan procedures.
 */
typedef union
{
  //! Energy scanning procedure results.
  PHY_EnergyLevel_t   (*energy)[];
  //! Active/passive scanning procedure results.
  MAC_PanDescriptor_t (*panDescr)[];
}  MAC_ScanResult_t;

/**
 * \brief MLME-SCAN confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.11.2 MLME-SCAN.confirm
 */
typedef struct
{
  //! Indicates which channels given in the request were not scanned.
  uint32_t    unScannedChannels;
  //! The status of the scan request.
  MAC_Status_t     status;
  //! Indicates the type of scan performed:
  MAC_ScanType_t   type;
  //! The channel page on which the scan was performed TBD
  uint8_t          page;
  //! The number of elements returned in the appropriate result lists.
  uint8_t          resultSize;
  //! EnergyDetectList and PANDescriptorList union. Non-standard addition.
  MAC_ScanResult_t result;
}  MAC_ScanConf_t;

/**
 * \brief MLME-SCAN request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.11.1 MLME-SCAN.request.
 */
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t  service;
  // MLME-SCAN confirm parameters structure.
  MAC_ScanConf_t    confirm;
  //! The 27 bits indicate which channels are to be scanned.
  uint32_t    channels;
  // MLME-SCAN confirm callback function's pointer.
  void (*MAC_ScanConf)(MAC_ScanConf_t *conf);
  //! Indicates the type of scan performed.
  MAC_ScanType_t type;
  //! A value used to calculate the length of time to spend scanning each channel
  //! for ED, active, and passive scans. This parameter is ignored for orphan scans.
  uint8_t        duration;
  //! The channel page on which to perform the scan.
  uint8_t        page;
  //! Non-standard addition. Max number of scan results.
  uint8_t        maxResultSize;
}  MAC_ScanReq_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-SCAN request primitive's prototype.
  \param reqParams - MLME-SCAN request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_ScanReq(MAC_ScanReq_t *reqParams);

#endif /* _MACSCAN_H */

// eof macScan.h
