/*******************************************************************************
  Console Header File

  Company:
    Microchip Technology Inc.

  File Name:
    console.h

  Summary:
    This file contains the Serial interface console interface.

  Description:
    This file contains the Serial interface console interface.
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

#ifndef _CONSOLE_H
#define _CONSOLE_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#if APP_ENABLE_CONSOLE == 1
#include <driver/usart/drv_usart.h>
#endif
#include <stdio.h>

/******************************************************************************
                    Defines section
******************************************************************************/
#if APP_DEVICE_EVENTS_LOGGING == 1
  #define LOG_STRING(name, str) char const name[] = str
#else
  #define LOG_STRING(name, str) (void)0
#endif

#if APP_ENABLE_CONSOLE == 1
#define appSnprintf(...) printf(__VA_ARGS__)
#else
#define appSnprintf(...)  (void)0
#endif

uint8_t hexStrTouint8array(const char *str, uint8_t *out, uint8_t length);

/**************************************************************************//**
                    Types section
******************************************************************************/
typedef union
{
  int8_t int8;
  uint8_t uint8;
  int16_t int16;
  uint16_t uint16;
  int32_t int32;
  uint32_t uint32;
  uint64_t uint64;
  int64_t int64;
  char chr;
  char *str;
} ScanValue_t;

/**************************************************************************//**
Valid format codes are:
  d, i - signed integer. '0x' perfix before value treat it like hex, otherwise its decimal.
  Hex couldn't be negative (have a '-' before value);
  s - string;
  c - single character.
******************************************************************************/
typedef struct
{
  const char *const name;              // Command name
  const char *const fmt;               // Format string for arguments
  void (*handler)(const ScanValue_t *);// Process function
  const char *helpMsg;                 // Plain text help message for command
} ConsoleCommand_t;

/******************************************************************************           
                     external variables section
******************************************************************************/
extern ConsoleCommand_t *cmdForHelpCmd;

/**************************************************************************//**
\brief Sends string to serial interface
******************************************************************************/
void consoleTxStr(const char *str);

/**************************************************************************//**
\brief Sends single char to serial interface
******************************************************************************/
void consoleTx(char chr);


/**************************************************************************//**
\brief Register commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterCommands(const ConsoleCommand_t *table);

/**************************************************************************//**
\brief Register zcl commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterZclCommands(const ConsoleCommand_t *table);

/**************************************************************************//**
\brief Register commissioning commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterCommissioningCommands(const ConsoleCommand_t *table);

/**************************************************************************//**
\brief Register zdo commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterZdoCommands(const ConsoleCommand_t *table);

/**************************************************************************//**
\brief Register zgp commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterZgpCommands(const ConsoleCommand_t *table);

/**************************************************************************//**
\brief Register Otau commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterOtauCommands(const ConsoleCommand_t *table);

/**************************************************************************//**
\brief Initializes console
******************************************************************************/
void initConsole(void);

/**************************************************************************//**
\brief Processes data received by console
******************************************************************************/
void processConsole(uint16_t length);

#endif // _CONSOLE_H
