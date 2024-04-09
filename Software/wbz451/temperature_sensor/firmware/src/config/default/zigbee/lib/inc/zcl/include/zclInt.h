/*******************************************************************************
  Zigbee Cluster Library Initialisation Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zcl.h

  Summary:
    The header file describes internal ZCL interface.

  Description:
    The header file describes internal ZCL interface and types.
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


#ifndef _ZCLINT_H
#define _ZCLINT_H

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

BEGIN_PACK
typedef struct PACK
{
  uint8_t           status;
  ZCL_AttributeId_t id;
  uint8_t           type;
  uint8_t           value[1];
} ZclReadAttributeResp_t;

typedef struct PACK
{
  uint8_t           status;
  ZCL_AttributeId_t id;
} ZclWriteAttributeResp_t;
END_PACK

ZclAttribute_t *zclGetNextAttribute(Endpoint_t endpoint, ClusterId_t clusterId, uint8_t clusterMask, ZclAttribute_t *currentAttribute);

#endif // _ZCL_INT_H
