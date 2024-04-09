// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK EndDevice Timeout Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkEndDeviceTimeout.h

  Summary:
    This file contains the Network EndDevice Handling Timeout Parameters.

  Description:
    This file contains the Network EndDevice Handling Timeout Parameters and Prototypes.
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

#ifndef _NWK_END_DEVICE_TIMEOUT_H
#define _NWK_END_DEVICE_TIMEOUT_H

/******************************************************************************
                               Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                              Definitions section
******************************************************************************/


/******************************************************************************
                                 Types section
******************************************************************************/
BEGIN_PACK
/** Requested Timeout Enumerated Values. */
typedef enum PACK
{
  NWK_END_DEVICE_TIMEOUT_10S,
  NWK_END_DEVICE_TIMEOUT_2M,
  NWK_END_DEVICE_TIMEOUT_4M,
  NWK_END_DEVICE_TIMEOUT_8M,
  NWK_END_DEVICE_TIMEOUT_16M,
  NWK_END_DEVICE_TIMEOUT_32M,
  NWK_END_DEVICE_TIMEOUT_64M,
  NWK_END_DEVICE_TIMEOUT_128M,
  NWK_END_DEVICE_TIMEOUT_256M,
  NWK_END_DEVICE_TIMEOUT_512M,
  NWK_END_DEVICE_TIMEOUT_1024M,
  NWK_END_DEVICE_TIMEOUT_2048M,
  NWK_END_DEVICE_TIMEOUT_4096M,
  NWK_END_DEVICE_TIMEOUT_8192M,
  NWK_END_DEVICE_TIMEOUT_16384M
} NwkEndDeviceTimeout_t;
END_PACK

/** End Device Timeout Request Command confirmation's
    parameters declaration. */
typedef struct
{
  /* Service fields, for internal needs. */
  struct
  {
    QueueElement_t qelem;
  } service;
  /** The status of the corresponding request. */
  NWK_Status_t status;
} NWK_EndDeviceTimeoutConf_t;

/** End Device Timeout Request Command parameters declaration. Child Aging and Recovery Protocol r20, 7.2, page 7. */
typedef struct
{
  /* Service fields, for internal needs. */
  struct
  {
    QueueElement_t qelem;
  } service;
  /** The requested timeout enumeration. */
  NwkEndDeviceTimeout_t timeout;
  /** This bitmask indicates the end deviceâ??s requested configuration. */
  uint8_t endDeviceConfiguration;
  /** Confirm callback fucntion's pointer. */
  void (*NWK_EndDeviceTimeoutConf)(NWK_EndDeviceTimeoutConf_t *conf);
  /** Coresponding confirmation structure. */
  NWK_EndDeviceTimeoutConf_t confirm;
} NWK_EndDeviceTimeoutReq_t;

/** End Device Timeout Request Command indication's
 parameters declaration. */
typedef struct
{
  /** The network address of an entity that has sent request. */
  ShortAddr_t networkAddress;
  /** The requested timeout enumeration. */
  NwkEndDeviceTimeout_t timeout;
  /** The requested end device configuration. */
  uint8_t endDeviceConfiguration;
  /** Parent information bitmask. */
  uint8_t parentInformation;
} NWK_EndDeviceTimeoutInd_t;

/******************************************************************************
                             Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief End Device Timeout Request Command prototype.

  \param[in] req - End Device Timeout Request Command parameters' structure
    pointer.
 ******************************************************************************/
void NWK_EndDeviceTimeoutReq(NWK_EndDeviceTimeoutReq_t *const req);

/**************************************************************************//**
  \brief Reset the end device timeout request component.
  \param     None.
  \return    None.
 ******************************************************************************/
void NWK_ResetEndDeviceTimeoutReq(void);

/**************************************************************************//**
  \brief Start the end device timeout timer
  \param     None.
  \return    None.
 ******************************************************************************/
void NWK_StartEdKeepAliveTimer(void);

/**************************************************************************//**
  \brief Stop the end device timeout timer
  \param     None.
  \return    None.
 ******************************************************************************/
void NWK_StopEdKeepAliveTimer(void);

/**************************************************************************//**
  \brief End Device Timeout Request Command indication.

  \param[in] ind - End Device Timeout Request Command indication
    parameters' structure pointer.
  \return    None.
 ******************************************************************************/
void NWK_EndDeviceTimeoutInd(NWK_EndDeviceTimeoutInd_t *ind);

/**************************************************************************//**
  \brief End Device Timeout set by parent internally for certification test harness purpose

  \param edExtAddr - End Device Extebnded Address for which timeout to be set
  edTimeoutEnumeration - End Device Timeout enumeration to be set
  \return    None. ******************************************************************************/
uint8_t NWK_SetEndDeviceTimeoutByParent(const ExtAddr_t edExtAddr, uint8_t edTimeoutEnumeration);

#endif /* _NWK_END_DEVICE_TIMEOUT_H */
/** eof nwkEndDeviceTimeout.h */
