// DOM-IGNORE-BEGIN
/*******************************************************************************
  BDB Internal Header File

  Company
    Microchip Technology Inc.

  File Name
    bdbInternal.h

  Summary
    bdb internal interface.

  Description
    This header file defines the interface to the BDB internal network API.
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
#ifndef _BDB_INTERNAL_H
#define _BDB_INTERNAL_H
// DOM-IGNORE-END

/**********************************************************************************
                      INCLUDE FILES
 *********************************************************************************/
 
#include <zdo/include/zdo.h>
#include <zdo/include/zdoSecurityManager.h>

/******************************************************************************
                    Defines section
 ******************************************************************************/

/******************************************************************************
                    Types section
 ******************************************************************************/

/** Describes the BDB memory structures */
typedef union _ZdoStackReq_t
{
  ZDO_StartNetworkReq_t  zdoStartNetworkReq;
  APS_RemoveDeviceReq_t apsRemoveDeviceReq;
  APS_RequestKeyReq_t apsReqKeyReq;
  ZDO_VerifiKeyReq_t apsVerify;
} ZdoStackReq_t;

typedef struct _BdbMem_t
{
  ZDO_ZdpReq_t zdpReq;
  ZdoStackReq_t stackReq;
} BdbMem_t;

/******************************************************************************
                    Extern variables
 ******************************************************************************/
 
extern BdbMem_t bdbMem;

/******************************************************************************
                    Prototypes section
 ******************************************************************************/

/********************************************************************//**
  \brief set the bdbNodeIsOnANetwork status

  \param onNetwork - if it is true, it is on network, false otherwise
  
  \return None
 ************************************************************************/
void BDB_SetBdbNodeIsOnANetwork(bool onNetwork);

#endif // _BDB_INTERNAL_H
