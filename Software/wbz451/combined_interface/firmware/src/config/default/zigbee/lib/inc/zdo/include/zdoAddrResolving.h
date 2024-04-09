// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object address resolving Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoAddrResolving.h

  Summary:
    This file contains the Interface for ZDO Address Resolving request routines.

  Description:
    This file contains the Interface for ZDO Address Resolving request routines.

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

// DOM-IGNORE-BEGIN
#ifndef _ZDOADDRRESOLVING_H
#define _ZDOADDRRESOLVING_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
 
#include <aps/include/apsCommon.h>
#include <zdo/include/zdoCommon.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
 
typedef enum _ZdoAddrResolvingReqState_t
{
  ZDO_ADDRESS_RESOLVING_IDLE_STATE = 0x01,
  ZDO_ADDRESS_RESOLVING_IN_PROGRESS_STATE,
  ZDO_ADDRESS_RESOLVING_CONFIRM_STATE
} ZdoAddrResolvingReqState_t;

/** Describes the parameters of the ZDO_ResolveAddrConf() function. */
typedef struct _ZDO_ResolveAddrConf_t
{
  ZDO_Status_t status; //!< The status of the address resolving request
} ZDO_ResolveAddrConf_t;

/** Describes the parameters of the ZDO_ResolveAddrReq() function. */
typedef struct _ZDO_ResolveAddrReq_t
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    QueueElement_t next;
  } service; //!< Service field for internal use only, should not be touched by user
  /** \endcond **/
  uint8_t reqSeqNo;
  ZdoAddrResolvingReqState_t  resolveAddrState;
  APS_AddrMode_t dstAddrMode; //!< The addressing mode for identifying the destination
  APS_Address_t dstAddress; //!< Address of device for which the resolving will be executed
  ZDO_ResolveAddrConf_t confirm; //!< Parameters of the confirm being rturned in ZDO_ResolveAddrConf()
  void (*ZDO_ResolveAddrConf)(ZDO_ResolveAddrConf_t *conf); //!< The function called to confirm the request
} ZDO_ResolveAddrReq_t;

/******************************************************************************
                        Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
 \brief Determines the missing short address corresponding to the given extended
  address or the missing extended address corresponding to the given short address

  The function sends a ZDP request: either an IEEE address ZDP request if the extended
  address should be determined, or a short address ZDP request if the short address
  should be determined. The callback function reports the result of ZDP request
  execution. If the request has completed successfully, the requested addressing
  info is provided in the argument.

  The function is called by the stack in several cases when one element in a pair of
  short and extended addresses of the same device is unknown. These cases include
  sending a data request when soome information about destination is lacking:
  ::APS_EXT_ADDRESS or ::APS_NO_ADDRESS (send to bound devices) addressing modes are used, 
  but the short address is not known; short address addressing 
  is used, and link key security is used, but the extended address to find out the
  link key is not known. The stack also checks if the extended address is known
  when it receives an encrypted frame.

  Response statuses:
  Accessed via the ZDO_ResolveAddrConf_t::status field of the
  ZDO_ResolveAddrReq_t::ZDO_ResolveAddrConf callback's argument \n\n
  ::ZDO_SUCCESS_STATUS (0x00) - the requested short or extended address has been 
  successfully determined \n
  ::ZDO_INVALID_REQUEST_STATUS (0x80) - the address resolving module is disabled \n
  Any of error codes reported by the ZDO_ZdpReq() function
  
  \param req - request structure to pass attribute id
  
  \return None
 ******************************************************************************/
void ZDO_ResolveAddrReq(ZDO_ResolveAddrReq_t *req);

/*************************************************************************//**
  \brief Determines NWK address by Extended 64-bit address.
  \param extAddr - pointer to extended 64-bit IEEE address
  \return pointer to a valid NWK short address if it has been found,
          NULL otherwise.
 *****************************************************************************/
const ShortAddr_t* ZDO_FindShortByExt(const ExtAddr_t *const extAddr);

/*************************************************************************//**
  \brief Determines Extended 64-bit address by NWK address.
  \param shortAddr - pointer to NWK address.
  \return pointer to a valid IEEE address if it has been found,
          NULL otherwise.
 *****************************************************************************/
const ExtAddr_t* ZDO_FindExtByShort(const ShortAddr_t shortAddr);

#endif // _ZDOADDRRESOLVING_H
