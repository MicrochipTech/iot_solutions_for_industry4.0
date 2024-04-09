/*******************************************************************************
  Print LCD header File

  Company:
    Microchip Technology Inc.

  File Name:
    printLcd.h

  Summary:
    This file contains interface for printing Lcd messages.

  Description:
    This file contains interface for printing Lcd messages..
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

#ifndef _PRINTLCD_H_
#define _PRINTLCD_H_

/******************************************************************************
                    Includes section
******************************************************************************/
#include <app_zigbee/zigbee_console/console.h>

/******************************************************************************
                   Definitions section
*******************************************************************************/
// Assert codes
#define BSPOPENBUTTONSASSERT_0              0xf001
#define BSPCLOSEBUTTONSASSERT_0             0xf002
#define REMOTEFSM_JOINDEVICE_0              0xf003
#define NETWORKJOINING_DISCOVERYDONE_0      0xf004
#define NETWORKJOINING_JOINDONE_0           0xf004
#define NETWORKJOINING_STARTNETWORK_0       0xf005
#define NETWORKJOINING_STARTNETWORK_1       0xf006
#define REMOTECONSOLE_RESETDEVICETOFN_0     0xf005
#define REMOTECONSOLE_IDENTIFYDEVICE_0      0xf006

/******************************************************************************
                    Prototypes section
******************************************************************************/
#if APP_DEVICE_EVENTS_LOGGING == 1
/**************************************************************************//**
\brief Print a formatted string on the LCD
******************************************************************************/
void dbgLcdMsg(const char *format, ...);

#else

#define dbgLcdMsg(...) while (0) {;}

#endif // APP_DEVICE_EVENTS_LOGGING


#endif // _DEBUG_H_

// eof printLcd.h
