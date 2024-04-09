/*******************************************************************************
  System debug Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysDbg.h

  Summary:
    This file contains the debugging related assert codes.

  Description:
    This file contains the debugging related assert codes.
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

#ifndef _SYSDBG_H_
#define _SYSDBG_H_

#include <systemenvironment/include/dbg.h>

typedef enum
{
  SYS_ASSERT_ID_DOUBLE_QUEUE_PUT             = 0x8000,
  SYS_ASSERT_ID_DRT_SIZE_TOO_BIG             = 0x8001,
  SYS_ASSERT_ID_DEVICE_WAS_NOT_ABLE_TO_SLEEP = 0x8002,
  SYS_ASSERT_WRONG_EVENT_SUBSCRIBE           = 0x8003,
  SYS_ASSERT_WRONG_EVENT_POST                = 0x8004,
  SYS_POSTEVENT_NULLCALLBACK0                = 0x8005,
  SYS_TASKHANDLER_NULLCALLBACK0              = 0x8006,
  SYSMUTEX_MUTEXLOCK0                        = 0x8007,
  SYSMUTEX_MUTEXUNLOCK0                      = 0x8008,
  SYSMUTEX_MUTEXUNLOCK1                      = 0x8009,
  SYSMUTEX_MUTEXUNLOCK2                      = 0x800A,
  SYSMUTEX_MUTEXUNLOCK3                      = 0x800B,
  SYSMUTEX_ISMUTEXLOCKED0                    = 0x800C
} SysAssertId_t;

#endif /* _SYSDBG_H_ */
