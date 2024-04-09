// DOM-IGNORE-BEGIN
/*******************************************************************************
  Network Attributes Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkAttributes.h

  Summary:
    This file contains the Interface of network attributes.

  Description:
    This file contains the Interface of network attributes.
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

#if !defined _NWK_ATTRIBUTES_H
#define _NWK_ATTRIBUTES_H

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/nwkEndDeviceTimeout.h>
#include <hal/include/appTimer.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
typedef struct 
{
  bool     indicationTriggered;
  uint16_t macTxUcastTotal;// Total number of Mac Tx Transactions to attempt to send a message
  uint16_t macTxUcastFailures;// Total number of failed Tx Transac-tions
  uint16_t macTxUcastRetries;// Total number of Mac Retries regardless of whether the transaction resulted in success or failure.
} MACTxUcastFields_t;

typedef struct 
{
  uint32_t timeStamp;
  HAL_AppTimer_t macTxUcastTimer;
} PeriodOfTimeResults_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief This function return a short address that is allocated by parent.

  \return Short address of this node or NWK_NO_SHORT_ADDR.
 ******************************************************************************/
ShortAddr_t NWK_GetShortAddr(void);

/**************************************************************************//**
  \brief Setting new short address of this device.

  \param shortAddr - new short (16-bit) address.
         silent - report (false) or not (true) to upper-layer.

  \return NWK_SUCCESS_STATUS - if this request is valid
     otherwise NWK_NOT_PERMITTED_STATUS.
 ******************************************************************************/
NWK_Status_t NWK_SetShortAddr(const ShortAddr_t shortAddr, const bool silent);

/**************************************************************************//**
  \brief This function return a short address of parent.

  \return Short address of parent device or NWK_NO_SHORT_ADDR
 ******************************************************************************/
ShortAddr_t NWK_GetParentShortAddr(void);

/**************************************************************************//**
  \brief This function return a short panid of network.

  \return short panid or 0xFFFF
 ******************************************************************************/
PanId_t NWK_GetPanId(void);

/**************************************************************************//**
  \brief Setting a short Id of PAN.

  \return short (16-bit) pan id.
 ******************************************************************************/
void NWK_SetPanId(PanId_t panId);

/**************************************************************************//**
  \brief This function return a extended panid of network.

  \return extended panid or 0
 ******************************************************************************/
ExtPanId_t NWK_GetExtPanId(void);

/**************************************************************************//**
  \brief Set a NWK extended PAN ID parameter value.

  \param[in] extPanId - pointer to new NWK extended PAN ID parameter value.
  \return None.
 ******************************************************************************/
void NWK_SetExtPanId(const ExtPanId_t *extPanId);

/**************************************************************************//**
  \brief Current RF channel.
 ******************************************************************************/
Channel_t NWK_GetLogicalChannel(void);

/**************************************************************************//**
  \brief Setting a new RF channel.

  \param[in] channel - the number of new channel.
 ******************************************************************************/
void NWK_SetLogicalChannel(const Channel_t channel);

/**************************************************************************//**
  \brief Maximum delivery time of broadcasting transmission on a network.

    Destination nodes of broadcasting transmission are only full function devices.

  \return Current value of broadcast delivery time in milliseconds.
 ******************************************************************************/
uint32_t NWK_GetBroadcastDeliveryTime(void);

/**************************************************************************//**
  \brief Medium delivery time of unicast packet to a sleep end device.

  \return Current value of unicast delivery time in milliseconds.
 ******************************************************************************/
uint32_t NWK_GetUnicastDeliveryTime(void);

/**************************************************************************//**
  \brief Set a short address of the network manager.

  \param[in] - short address of the network manager.
 ******************************************************************************/
void NWK_SetManagerAddr(const ShortAddr_t shortAddr);

/**************************************************************************//**
  \brief Getting the short address of the network manager.

  \return Network manager address.
 ******************************************************************************/
ShortAddr_t NWK_GetManagerAddr(void);

/**************************************************************************//**
  \brief Set an id of network snapshot.

  \param[in] - new value of the update identifier.
 ******************************************************************************/
void NWK_SetUpdateId(const NwkUpdateId_t updateId);

/**************************************************************************//**
  \brief Getting an id of network snapshot.

  \return Network snapshot id
 ******************************************************************************/
NwkUpdateId_t NWK_GetUpdateId(void);

/**************************************************************************//**
  \brief Sets symmetric link attribute value.

  \param[in] symLink - new symmetric link attribute value.
  \return None.
 ******************************************************************************/
void NWK_SetSymLink(const bool symLink);

/**************************************************************************//**
  \brief Changing the route fail order.

    After 2^order failure attempts a route entry will be deleted.

  \param[in] order - new order of route fail.
  \return NWK_SUCCESS_STATUS if order is valid
          otherwise NWK_INVALID_PARAMETER_STATUS.
 ******************************************************************************/
NWK_Status_t NWK_SetFailRouteOrder(const uint8_t order);

/**************************************************************************//**
  \brief Gets attribute value which specifies if static addressing mode is in use

  \return True, if static addressing mode is in use; false - otherwise
 ******************************************************************************/
bool NWK_IsStaticAddressingMode(void);

/**************************************************************************//**
  \brief Gets protocol version attribute value.

  \return Protocol version attribute value.
 ******************************************************************************/
uint8_t NWK_GetProtocolVersion(void);

/**************************************************************************//**
  \brief Getting the total number of transmissions

  \return Value of total number of transmissions
 ******************************************************************************/
uint16_t NWK_GetTransmitCouner(void);

/**************************************************************************//**
  \brief Getting the transmission failures counter.

  \return Value of transmission failures counter
 ******************************************************************************/
uint16_t NWK_GetTransmitFailureCounter(void);

/**************************************************************************//**
  \brief Resets the transmission failures counter and the total tx counter.
 ******************************************************************************/
void NWK_ResetTransmitCounters(void);

/**************************************************************************//**
  \brief Getting a device type parameter value.

  \return device type parameter value.
 ******************************************************************************/
DeviceType_t NWK_GetDeviceType(void);

/**************************************************************************//**
  \brief Perform comparision of new newNwkUpdateId with the current value.

  \param[in] newNwkUpdateId - network updateId to be tested.

  \return true if new network updateId is more recent, false otherwise.
 ******************************************************************************/
bool NWK_IsNewUpdateIdMoreRecent(NwkUpdateId_t newNwkUpdateId);

/**************************************************************************//**
  \brief Check, if specified nwkUpdateId is equal or higher than current one.

  \param[in] newNwkUpdateId - network updateId to be tested.

  \return true if specified nwkUpdateId is equal or higher then current one,
          false - otherwise.
 ******************************************************************************/
bool NWK_IsNewUpdateIdNonLess(NwkUpdateId_t newNwkUpdateId);

#ifdef _CHILD_MANAGEMENT_
/**************************************************************************//**
  \brief Gets parent information value.

  \return Parent information attribute value.
 ******************************************************************************/
uint16_t NWK_GetParentInformation(void);

/**************************************************************************//**
  \brief Sets parent information value.

  \return None.
 ******************************************************************************/
void NWK_SetParentInformation(uint8_t parentInfo);

/**************************************************************************//**
  \brief Gets end device default timeout value.

  \return End device default timeout attribute value.
 ******************************************************************************/
NwkEndDeviceTimeout_t NWK_GetEndDeviceDefaultTimeout(void);
#endif /* _CHILD_MANAGEMENT_ */
/**************************************************************************//**
  TBD.
******************************************************************************/
void NWK_ResetMACTxUcastFields(void);

/**************************************************************************//**
  TBD.
******************************************************************************/
MACTxUcastFields_t* NWK_GetMACTxUcastFields(void);

/**************************************************************************//**
  TBD.
******************************************************************************/
uint8_t NWK_GetPeriodOfTimeResults(void);

/**************************************************************************//**
  TBD.
******************************************************************************/
void NWK_RestartMacTxUcastTimer(void);

#endif /* _NWK_ATTRIBUTES_H */
/** eof nwkAttributes.h */

