/*******************************************************************************
  ZCL Memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclMem.h

  Summary:
    The header file describes the ZCL memory structure.

  Description:
    The file describes the structure of ZCL memory.
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


#ifndef _ZCLMEM_H
#define _ZCLMEM_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysQueue.h>
#include <hal/include/appTimer.h>

/******************************************************************************
                   Types section
******************************************************************************/
/******************************************************************************
Describes ZCL memory structure
******************************************************************************/
typedef struct
{
  uint8_t sequenceNumber;
  uint8_t *memoryBuffer;
} ZclMem_t;

/******************************************************************************
                           External variables section
******************************************************************************/
/******************************************************************************
ZCL memory global object
******************************************************************************/
extern ZclMem_t zclMem;

/******************************************************************************
                           Inline functions section
 ******************************************************************************/
/******************************************************************************
Function returns point to ZCL memory object
******************************************************************************/
static inline ZclMem_t * zclMemReq(void)
{
  return ((ZclMem_t *)&zclMem);
}

#endif // _ZCLMEM_H
