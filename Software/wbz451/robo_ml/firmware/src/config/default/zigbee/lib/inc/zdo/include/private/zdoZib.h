// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object information base Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoZib.h

  Summary:
    This file contains the ZDO information base.

  Description:
    This file contains the ZDO information base.
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
#if !defined _ZDO_ZIB_H
#define _ZDO_ZIB_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** ############# todo by unithra. */
typedef struct _ZIB_t
{
  /* The node descriptor contains information about the capabilities of the ZigBee
   * node and is mandatory for each node. */
  NodeDescriptor_t nodeDescriptor;
  /* The node power descriptor gives a dynamic indication of the power status of the
   * node and is mandatory for each node.*/
  PowerDescriptor_t powerDescriptor;
  /* Duration of a scan procedure. This parameter is used during network formation
   * and joining. */
  ScanDuration_t scanDuration;
  /* The parameter determines the association permit period.
   * 0xff means "always on", 0x00 means "always off. */
  uint8_t permitJoinDuration;
  /* ZDP response wait timeout */
  uint16_t zdpResponseTimeout;
} ZIB_t;

/******************************************************************************
                           External variables section
 ******************************************************************************/
extern ZIB_t csZIB;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Gets information from the Config Server and initializes ZIB.
 ******************************************************************************/
ZDO_PRIVATE void zdoReloadZibFromConfigServer(void);

#endif /* _ZDO_ZIB_H */
/** eof zdoZib.h */
