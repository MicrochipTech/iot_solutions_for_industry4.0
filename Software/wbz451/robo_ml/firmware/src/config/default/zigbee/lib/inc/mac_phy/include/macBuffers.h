/*******************************************************************************
  MAC Buffers Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macBuffers.h

  Summary:
    This file contains the MAC and PHY buffers description.

  Description:
    This file contains the MAC and PHY buffers description.
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

#ifndef _MACBUFFERS_H
#define _MACBUFFERS_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <inttypes.h>
#include <systemenvironment/include/sysTypes.h>
#include <mac_phy/include/phy.h>
#include <mac_phy/include/macphyPib.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/
//! Size of internal reception buffer.
#define FRAME_RX_BUFFER_SIZE (PHY_FRAME_LENGTH_FIELD_SIZE + \
                              PHY_MAX_PACKET_SIZE + \
                              PHY_LQI_FIELD_SIZE + \
                              PHY_RSSI_FIELD_SIZE)

/******************************************************************************
                    Types section
******************************************************************************/
typedef enum
{
  FRAME_RX_BUFFER_TYPE_DATA,
#if defined(_FFD_)
  FRAME_RX_BUFFER_TYPE_DATA_REQ,
#endif // defined(_FFD_)
  FRAME_RX_BUFFER_TYPES_AMOUNT
} FrameRxBufferType_t;

//! Rx frame buffer state descriptor.
typedef struct
{
  uint8_t *buffer;
  uint8_t *reserved;
  uint8_t *gap1b;
  uint8_t *gap1e;
  uint8_t *gap2b;
  uint8_t *gap2e;
} FrameRxBufferState_t;

#endif // _MACBUFFERS_H

// eof macBuffers.h
