/*******************************************************************************
  ZCl Memory Manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclMemoryManager.h

  Summary:
    The header file describes the ZCL Memory Manager interface.

  Description:
    The header file describes the ZCL Memory Manager interface.
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


#ifndef _ZCLMEMORYMANAGER_H
#define _ZCLMEMORYMANAGER_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <aps/include/aps.h>
#include <zdo/include/appFramework.h>
#include <mac_phy/include/macAddr.h>
#include <zcl/include/zcl.h>
#include <systemenvironment/include/dbg.h>

#ifdef ZAPPSI_HOST
#define ZCL_RESPONSE_SPACING 300U
#else // basic application
#define ZCL_RESPONSE_SPACING 0U
#endif
/******************************************************************************
                   Types section
******************************************************************************/
typedef enum
{
  /** Value for free buffer */
  ZCL_UNKNOWN_BUFFER = 0x0,
  /** Output packet from APL component. */
  ZCL_OUTPUT_DATA_BUFFER = 0x1,
  /** Input packet from APS-layer. */
  ZCL_INPUT_DATA_BUFFER = 0x2,
  /** Output packet from ZCL-layer(response). */
  ZCL_OUTPUT_RESPONSE_BUFFER = 0x3,
  /** Output packet from ZCL-layer (report). */
  ZCL_OUTPUT_REPORT_BUFFER = 0x4,
  ZCL_BUFFER_TYPE_LAST
} ZclBufferType_t;

typedef union
{
  APS_DataReq_t apsDataReq;
  APS_DataInd_t apsDataInd;
} ZclMmPrimitive_t;

typedef struct
{
  ZclMmPrimitive_t  primitive;
  uint8_t *frame;
} ZclMmBuffer_t;

typedef struct
{
  uint32_t        timeout;
  ZCL_Request_t   *link;
  ZclMmBuffer_t   buf;
  ZclBufferType_t type;
} ZclMmBufferDescriptor_t;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/*************************************************************************//**
\brief Looks for and returns free zcl memory buffer

\param[in] type - the type of a buffer

\returns pointer to memory buffer or NULL if there is no free buffer
*****************************************************************************/
ZclMmBuffer_t *zclMmGetMem(ZclBufferType_t type);

/*************************************************************************//**
\brief Frees zcl buffer

\param[in] mem - pointer to used zcl buffer
*****************************************************************************/
void zclMmFreeMem(ZclMmBuffer_t *mem);

/*************************************************************************//**
\brief Gets next zcl memory buffer descriptor or
  the first one if mem is NULL with output request

\param[in] descr - pointer to current zcl buffer descriptor

\returns pointer to the next busy zcl memory buffer descriptor
  or NULL if no next busy zcl memory buffer descriptor is available
*****************************************************************************/
ZclMmBufferDescriptor_t *zclMmGetNextOutputMemDescriptor(ZclMmBufferDescriptor_t *descr);

#endif  //#ifndef _ZCLMEMORYMANAGER_H

//eof zclMemoryManager.h
