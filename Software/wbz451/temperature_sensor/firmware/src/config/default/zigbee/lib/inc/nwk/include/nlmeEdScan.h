// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Energy Detection Scan Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeEdScan.h

  Summary:
    This file contains the Network Layer Management Entity ED Scan Primitives.

  Description:
    This file contains the Network Layer Management Entity ED Scan Primitives.
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

#if !defined _NLME_ED_SCAN_H
#define _NLME_ED_SCAN_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                               Define(s) section
 ******************************************************************************/
/** Maximum number of channels which can be scanned for one request. */
#define MAX_EDSCAN_CHANNEL_AMOUNT 16U

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** NLME-ED-SCAN confirm primitive's parameters structure declaration. ZigBee Specification r17, 3.2.2.10 NLME-ED-SCAN.confirm */
typedef struct _NWK_EDScanConf_t
{
  /** The status of the request. */
  NWK_Status_t status;
  /** Indicates which channels given in the request were not scanned. */
  ChannelsMask_t unScannedChannels;
  /** Size of energyDetectList */
  uint8_t energyDetectListSize;
  /** The list of energy measurements */
  PHY_EnergyLevel_t energyDetectList[MAX_EDSCAN_CHANNEL_AMOUNT];
} NWK_EDScanConf_t;

/** NLME-ED-SCAN request primitive's parameters structure declaration. */
typedef struct _NWK_EDScanReqFields_t
{
  NWK_EDScanConf_t confirm;
  void *context;
   /** Bitmask of channels are to be scanned */
  ChannelsMask_t scanChannels;
  /** A value used to calculate the length of time to spend
   * scanning each channel. */
  ScanDuration_t scanDuration;
  /** NLME-ED-SCAN confirm callback function's pointer. */
  void (*NWK_EDScanConf)(NWK_EDScanConf_t *conf);
}NWK_EDScanReqFields_t;

/** NLME-ED-SCAN request primitive's parameters structure declaration.Zigbee Specification r17, 3.2.2.9 NLME-ED-SCAN.request. */
typedef struct _NWK_EDScanReq_t
{
  /** Service fields - for internal needs. */
  struct
  {
    QueueElement_t qelem; /**< link used for queuing */
    MAC_ScanReq_t macScanReq;
  } service;
  NWK_EDScanReqFields_t *nwkEdScanReqFields;
} NWK_EDScanReq_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-ED-SCAN request primitive's prototype.

  \param[in] req - NLME-ED-SCAN request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_EDScanReq(NWK_EDScanReq_t *const req);

#endif /* _NLME_ED_SCAN_H */
/** eof nlmeEdScan.h */

