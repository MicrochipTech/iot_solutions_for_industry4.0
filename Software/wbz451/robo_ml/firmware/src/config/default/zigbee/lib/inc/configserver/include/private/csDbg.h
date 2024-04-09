/*******************************************************************************
  CS Dbg Header File

  Company
    Microchip Technology Inc.

  File Name
    csDbg.h

  Summary
    This file contains the Configuration Server debug info.

  Description
    This header file provides the interface to access the CS debug Info.
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

#ifndef _CSDBG_H_
#define _CSDBG_H_

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/dbg.h>

typedef enum
{
  CS_READ_PARAM0  = 0x6000,
  CS_READ_PARAM1  = 0x6001,
  CS_READ_PARAM2  = 0x6002,
  CS_READ_PARAM3  = 0x6003,

  CS_WRITE_PARAM0 = 0x6004,
  CS_WRITE_PARAM1 = 0x6005,

  CS_GET_MEM0     = 0x6006,

  CS_GET_ITEM0    = 0x6007,
  CS_GET_ITEM1    = 0x6008,
  CS_GET_ITEM2    = 0x6009,
  CS_GET_ITEM3    = 0x600A,
} CS_DbgCodeId_t;

#endif /* _CSDBG_H_ */
