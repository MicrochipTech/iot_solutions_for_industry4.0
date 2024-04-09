/*******************************************************************************
  BDB Dbg Header File

  Company
    Microchip Technology Inc.

  File Name
    bdbDbg.h

  Summary
    bdb Debug Code ID.

  Description
    This header file manages the BDB debug codes used.
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

#ifndef _BDB_DBG_H
#define _BDB_DBG_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/
#include <systemenvironment/include/dbg.h>

/***************************************************************************************************
* TYPES SECTION
***************************************************************************************************/
typedef enum
{
  BDB_RESET_TL_CLUSTER_NULLCALLBACK  = 0xD000,
  BDB_EVENTS_QUEUE_NOT_ALLOCATED = 0xD001,
  BDB_TC_NO_MEMORY_FOR_NODE_JOIN = 0xD002,
} BDB_DbgCodeId_t;

#endif // _BDB_DBG_H