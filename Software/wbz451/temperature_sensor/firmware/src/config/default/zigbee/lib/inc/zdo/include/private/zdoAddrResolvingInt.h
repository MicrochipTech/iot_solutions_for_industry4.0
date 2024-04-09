// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object address resolving Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoAddrResolvingInt.h

  Summary:
    This file contains private prototypes and definitions for ZDO Address Resolving routines.

  Description:
    This file contains private prototypes and definitions for ZDO Address Resolving routines.
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
#ifndef _ZDOADDRRESOLVINGINTERNAL_H
#define _ZDOADDRRESOLVINGINTERNAL_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <zdo/include/zdo.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of APS _ZdoAddrResolving_t. */
typedef struct _ZdoAddrResolving_t
{
  QueueDescriptor_t         queue;
} ZdoAddrResolving_t;

/******************************************************************************
                                Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
  \brief Address Resolving request task handler.
  \param None.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoAddrResolvingTaskHandler(void);

/**************************************************************************//**
  \brief Reset Address Resolving component.
  \param None.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoResetAddrResolving(void);

#endif // _ZDOADDRRESOLVINGINTERNAL_H
