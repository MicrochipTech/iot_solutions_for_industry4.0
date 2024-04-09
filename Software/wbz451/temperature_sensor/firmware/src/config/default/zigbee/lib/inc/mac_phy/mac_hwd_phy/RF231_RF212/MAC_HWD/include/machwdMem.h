/*******************************************************************************
  MAC HwdMemory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    machwdMem.h

  Summary:
    This file contains the MACHWD memory type.

  Description:
    This file comprises the MACHWD memory parameters.
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

#ifndef _MACHWDMEM_H
#define _MACHWDMEM_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/macBuffers.h>
#include <mac_phy/include/phy.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyDataStatus.h>
#include <mac_phy/mac_hwd_phy/include/machwdData.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
/** MAC hardware dependent sublayer internal memory pool */
typedef struct
{
  bool beaconRxMode;
  FrameRxBufferState_t rxBufferState[FRAME_RX_BUFFER_TYPES_AMOUNT];
  uint8_t handlers;
  union
  {
    volatile PHY_EnergyLevel_t energyLevel;
    volatile PHY_DataStatus_t dataStatus;
  };
} MachwdMem_t;

#endif /*_MACHWDMEM_H*/

// eof machwdMem.h
