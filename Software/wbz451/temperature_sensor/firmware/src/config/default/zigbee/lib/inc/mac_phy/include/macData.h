/*******************************************************************************
  MAC Data Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macData.h

  Summary:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    data primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    data primitives.
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

#ifndef _MACDATA_H
#define _MACDATA_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/include/macAddr.h>
#include <mac_phy/include/macCommon.h>


/******************************************************************************
                        Defines section
******************************************************************************/


/******************************************************************************
                        Types section
******************************************************************************/
/**
 * \brief MAC data TxOptions.
 * IEEE 802.15.4-2006 Table 41.
*/
typedef enum
{
  MAC_NO_TXOPTION                   = 0x00,
  MAC_ACK_TXOPTION                  = 0x01,
  MAC_GTS_TXOPTION                  = 0x02,
  MAC_INDIRECT_TXOPTION             = 0x04,
  MAC_NO_PANID_COMPRESSION_TXOPTION = 0x08 //It is not from IEEE 802.15.4
} MAC_TxOptions_t;

/**
 * \brief MCPS-DATA confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.1.2 MCPS-DATA.confirm.
*/
typedef struct
{
  //! The handle associated with the MSDU being confirmed.
  uint8_t       msduHandle;
  //! The status of the last MSDU transmission.
  MAC_Status_t  status;
}  MAC_DataConf_t;

/**
 * \brief MCPS-DATA request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.1.1 MCPS-DATA.request.
*/
typedef struct
{
  //! Service field - for internal needs.
  MAC_ServiceTransaction_t service;
  //! MCPS-DATA confirm callback function's pointer.
  void (*MAC_DataConf)(MAC_DataConf_t *conf);
  //! The set of octets pointer forming the MSDU to be transmitted by the MAC sublayer entity.
  uint8_t         *msdu;
  //! The 16-bit PAN identifier of the entity to which the MSDU is being transferred.
  PanId_t         dstPanId;
  //! MCPS-DATA confirm parameters' structure.
  MAC_DataConf_t confirm;
  //! The source addressing mode for this primitive and subsequent MPDU.
  MAC_AddrMode_t  srcAddrMode;
  //! The destination addressing mode for this primitive and subsequent MPDU.
  MAC_AddrMode_t  dstAddrMode;
  
  //! The individual device address of the entity to which the MSDU is being transferred.
  MAC_Addr_t      dstAddr;
  //! The number of octets contained in the MSDU to be transmitted by the MAC sublayer entity.
  uint8_t         msduLength;
  
  //! The handle associated with the MSDU to be transmitted by the MAC sublayer entity.
  uint8_t         msduHandle;
  //! The 3 bits indicate the transmission options for this MSDU.
  MAC_TxOptions_t txOptions;
  //! To configure CSMA
#if  defined(_ZGPD_SPECIFIC_) || defined(_GREENPOWER_SUPPORT_)
  uint8_t performCsma;
#endif /* _ZGPD_SPECIFIC_ */
  
#if defined _SYS_ASSERT_ON_ && defined _IEEE_ZIGBEE_COMPLIANCE_
  //! Service field - for debug needs.
  bool interPan;
#endif // defined _SYS_ASSERT_ON_ && defined _IEEE_ZIGBEE_COMPLIANCE_
}  MAC_DataReq_t;


/**
 * \brief MCPS-DATA indication primitive's parameters.
 * IEEE 802.15.4-2006 7.1.1.3 MCPS-DATA.indication.
*/
typedef struct
{
  //! The source addressing mode for this primitive corresponding to the received.
  MAC_AddrMode_t srcAddrMode;
  //! The 16-bit PAN identifier of the entity from which the MSDU was received.
  PanId_t        srcPANId;
  //! The individual device address of the entity from which the MSDU was received.
  MAC_Addr_t     srcAddr;
  //! The destination addressing mode for this primitive corresponding to the received MPDU.
  MAC_AddrMode_t dstAddrMode;
  //! The 16-bit PAN identifier of the entity to which the MSDU is being transferred.
  PanId_t        dstPANId;
  //! The individual device address of the entity to which the MSDU is being transferred.
  MAC_Addr_t     dstAddr;
  //! The number of octets contained in the MSDU being indicated by the MAC sublayer entity.
  uint8_t        msduLength;
  //! The set of octets pointer forming the MSDU being indicated by the MAC sublayer entity.
  uint8_t        *msdu;
  //! LQI value measured during reception of the MPDU.
  uint8_t        linkQuality;
  //! The DSN of the received data frame.
  uint8_t        dsn;
  //! RSSI value measured during  reception of the MPDU. Non-standard addition.
  int8_t         rssi;
}  MAC_DataInd_t;


/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MCPS-DATA request primitive's prototype.
  \param reqParams -  MCPS-DATA request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_DataReq(MAC_DataReq_t *reqParams);

/**************************************************************************//**
  \brief MCPS-DATA indication primitive's prototype.
  \param indParams -  MCPS-DATA indication parameters' structure pointer.
  \return none.
******************************************************************************/
extern void MAC_DataInd(MAC_DataInd_t *indParams);

#endif /* _MACDATA_H */

// eof macData.h
