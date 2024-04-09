/*******************************************************************************
  MAC Set and Get Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macSetGet.h

  Summary:
    This file provides access to the MAC Set and Get primitives.

  Description:
    This file contains the Types', constants' and functions' declarations for IEEE 802.15.4-2006
    set and get primitives.
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

#ifndef  _MACSETGET_H
#define  _MACSETGET_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <mac_phy/include/macphyPib.h>

/******************************************************************************
                        Defines section
******************************************************************************/

/******************************************************************************
                        Types section
******************************************************************************/
/**
 * \brief MLME-SET confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.13.2 MLME-SET.confirm.
*/
typedef struct
{
  //! The result of the request to write the PIB attribute.
  MAC_Status_t   status;
  //! The identifier of the PIB attribute that was written.
  MACPHY_PibId_t attrId;
}  MAC_SetConf_t;

/**
 * \brief MLME-SET request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.13.1 MLME-SET.request.
 */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    void *next; /*!< Used for queue support */
#ifdef _ZAPPSI_
    /* to be compatible with MAC service. */
    uint8_t requestId;
    /* Sequence number to identify request-response pair. */
    uint8_t sequenceNumber;
    union
    {
      /* Callback wrapper routine pointer */
      void (*callback)(void*);
      /* Processing routine pointer to call after required memory will become free */
      void (*process)(void*);
    } zsi;
#else /* _ZAPPSI_ */
    uint8_t requestId;
#endif /* # _ZAPPSI_ */
  } service;

  //! The identifier of the PIB attribute to write.
  MACPHY_PibId_t   attrId;
  //! The value to write to the indicated PIB attribute.
  MACPHY_PibAttr_t attrValue;
  //! MLME-SET confirm callback function's pointer.
  void (*MAC_SetConf)(MAC_SetConf_t *conf);
  //! MLME-SET confirm parameters' structure.
  MAC_SetConf_t confirm;
}  MAC_SetReq_t;

/**
 * \brief MLME-GET confirm primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.6.2 MLME-GET.confirm.
 */
typedef struct
{
  //! The result of the request for PIB attribute information.
  MAC_Status_t status;
  //! The identifier of the PIB attribute that was read.
  MACPHY_PibId_t   attrId;
  //! The value of the indicated PIB attribute that was read.
  MACPHY_PibAttr_t attrValue;
}  MAC_GetConf_t;

/**
 * \brief MLME-GET request primitive's parameters structure declaration.
 * IEEE 802.15.4-2006 7.1.6.1 MLME-GET.request.
 */
typedef struct
{
  //! Service field - for internal needs.
  MAC_Service_t service;
  //! The identifier of the PIB attribute to read.
  MACPHY_PibId_t   attrId;
  //! MLME-GET confirm callback function's pointer.
  void (*MAC_GetConf)(MAC_GetConf_t *conf);
  //! MLME-GET confirm parameters' structure.
  MAC_GetConf_t confirm;
}  MAC_GetReq_t;

/******************************************************************************
                        Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief MLME-SET request primitive's prototype.
  \param reqParams - MLME-SET request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_SetReq(MAC_SetReq_t *reqParams);

/**************************************************************************//**
  \brief MLME-GET request primitive's prototype.
  \param reqParams - MLME-GET request parameters' structure pointer.
  \return none.
******************************************************************************/
void MAC_GetReq(MAC_GetReq_t *reqParams);

#endif /* _MACSETGET_H */

// eof macSetGet.h
