// DOM-IGNORE-BEGIN
/*******************************************************************************
  NLME Network Formation Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nlmeNetworkFormation.h

  Summary:
    This file contains the constants and declaration for NLME Network Formation defines.

  Description:
    This file contains the constants and declaration for NLME Network Formation defines.
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

#if !defined _NLME_NETWORK_FORMATION_H
#define _NLME_NETWORK_FORMATION_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <mac_phy/include/mac.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/nlmeEdScan.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** NLME-NETWORK-FORMATION confirm primitive's parameters structure. ZigBee Specification r17, 3.2.2.3, NLME-NETWORK-FORMATION.confirm */
typedef struct _NWK_NetworkFormationConf_t
{
  /** The status of the request. */
  NWK_Status_t status;
} NWK_NetworkFormationConf_t;

/** NLME-NETWORK-FORMATION request primitive's parameters structure.Zigbee Specification r17, 3.2.2.3 NLME-NETWORK-FORMATION.request. */
typedef struct _NWK_NetworkFormationReq_t
{
  /** Service fields - for internal needs. */
  struct
  { /** Link to a next network formation request in queue. */
    QueueElement_t qelem;
    union
    {
      struct
      {
        MAC_ScanReq_t req;
        PHY_EnergyLevel_t energyList[MAX_EDSCAN_CHANNEL_AMOUNT];
      } scan;
      MAC_SetReq_t setReq;
      MAC_StartReq_t startReq;
      MAC_RxEnableReq_t rxEnableReq;
    } mac;
  } service;
  /** This parameter controls the method of network forming. 
   * Valid values of the method field are: 
   *   \li NWK_JOIN_VIA_FORMING
   *   \li NWK_JOIN_VIA_COMMISSIONING */
  NWK_JoinControl_t ctrl;
  /** Channels are to be scanned in preparation for starting a network. */
  ChannelsMask_t scanChannels;
  /** This field shall contain the device capability information.
   * See ZigBee spec r18, Table 3.44, page 345. */
  MAC_CapabilityInf_t capabilityInformation;
#ifdef _DISTRIBUTED_SECURITY_
  /** This field determines whether a router can form a network
   * in distributed security mode. See ZigBee spec r21, Table 3.9, page 280 */
  bool distributedNwk;
  /** The address the device will use when forming a distributed network
   * See ZigBee spec r21, Table 3.9, page 280 */
  ShortAddr_t distributedNwkAddr;  
#endif // _DISTRIBUTED_SECURITY_
  /** NLME-NETWORK-FORMATION confirm callback function's pointer. */
  void (*NWK_NetworkFormationConf)(NWK_NetworkFormationConf_t *conf);
  NWK_NetworkFormationConf_t confirm;
  /** The time spent scanning each channel is
   *  (aBaseSuperframeDuration * (2n + 1)) symbols,
   * where n is the value of the ScanDuration parameter. */
  ScanDuration_t scanDuration;
} NWK_NetworkFormationReq_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief NLME-NETWORK-FORMATION request primitive's prototype.

  \param[in] req - NLME-NETWORK-FORMATION request parameters' structure pointer.
  \return None.
 ******************************************************************************/
void NWK_NetworkFormationReq(NWK_NetworkFormationReq_t *const req);

#endif /* _NLME_NETWORK_FORMATION_H */
/** eof nlmeNetworkFormation.h */

