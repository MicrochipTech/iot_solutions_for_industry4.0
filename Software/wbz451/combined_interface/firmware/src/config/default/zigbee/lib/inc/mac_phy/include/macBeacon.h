/*******************************************************************************
  MAC Beacon Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macBeacon.h

  Summary:
    This file contains the Beacon specific types declarations and prototypes.

  Description:
    This file contains the Beacon specific types declarations and prototypes.
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

#ifndef _MACBEACON_H
#define _MACBEACON_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <systemenvironment/include/sysEndian.h>
#include <mac_phy/include/macSuperframe.h>

/******************************************************************************
                        Definitions section.
******************************************************************************/
#define MAC_MAX_PENDING_ADDRESS_COUNT 7
#define MAC_FINAL_CAP_SLOT 15

/******************************************************************************
                        Types section.
******************************************************************************/
/**
  \brief Pending address specification fields.
  IEEE 802.15.4-2006 7.2.2.1.6 Pending Address Specification field.
*/
BEGIN_PACK
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    uint8_t shortAddrNum : 3,
    uint8_t reserved1    : 1,
    uint8_t extAddrNum   : 3,
    uint8_t reserved2    : 1
  ))
}  MAC_PendingAddrSpec_t;
END_PACK

/**
  \brief PAN descriptor.
   IEEE 802.15.4-2006 Table 55.
*/
typedef struct
{
  uint32_t             timeStamp;
  PanId_t              coordPANId;
  MAC_Addr_t           coordAddr;
  uint8_t              channel;
  uint8_t              page;
  bool                 gtsPermit;
  uint8_t              quality;
  MAC_AddrMode_t       coordAddrMode;
  int8_t               rssi; // Additional parameter (NOT described in the standard)
                             // RSSI value while beacon frame receiving procedure.
  MAC_SuperframeSpec_t superframeSpec;
}  MAC_PanDescriptor_t;

/**
  \brief Parameters of BEACON indication.
  IEEE 802.15.4-2006 7.1.5.1 MLME-BEACON-NOTIFY.indication.
*/
typedef struct
{
  //! The beacon sequence number.
  uint8_t               bsn;
  //! The PANDescriptor for the received beacon.
  MAC_PanDescriptor_t   panDescr;
  //! The beacon pending address specification.
  MAC_PendingAddrSpec_t pendAddrSpec;
  //! List of short addresses.
  ShortAddr_t           (*shortPendAddrList)[];
  //! List of extended addresses.
  ExtAddr_t             (*extPendAddrList)[];
  //! The number of octets contained in the beacon payload of the beacon frame
  //! received by the MAC sublayer.
  uint8_t               msduLength;
  //! The set of octets comprising the beacon payload to be transferred from the
  //! MAC sublayer entity to the next higher layer.
  uint8_t               *msdu;
}  MAC_BeaconNotifyInd_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-BEACON_NOTIFY indication primitive's prototype.
  \param indParams - MLME-BEACON_NOTIFY indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_BeaconNotifyInd(MAC_BeaconNotifyInd_t *indParams);

#endif //_MACBEACON_H

// eof macBeacon.h
