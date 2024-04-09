/*******************************************************************************
  Application console Source File

  Company:
    Microchip Technology Inc.

  File Name:
    console.c

  Summary:
    This file contains the Serial interface console implementation.

  Description:
    This file contains the Serial interface console implementation.
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

#if APP_ENABLE_CONSOLE == 1

/******************************************************************************
                    Includes section
******************************************************************************/
#if (APP_USE_OTAU == 1)
#include <zigbee/z3device_configs/otauConfig.h>
#endif
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include "console.h"
#include "nwk/include/nwkCommon.h"
#include "nwk/include/nwkEndDeviceTimeout.h"
#include "nwk/include/nwkNeighbor.h"
#include "app_zigbee/app_zigbee.h"
#include "app.h"

/******************************************************************************
                    Definitions section
******************************************************************************/
#define VT100_ESCAPE        0x1B
#define VT100_ERASE_LINE    "\x1B[2K"
#define CMD_PROMPT          "$"

#if (APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC) && \
    (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
#define CMD_BUF_SIZE        400
#define MAX_NUM_OF_ARGS     80
#else
#define CMD_BUF_SIZE        85
#define MAX_NUM_OF_ARGS     17
#endif
#define CRLF                "\r\n"
#define FORCE_LOWCASE 0

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  ScanValue_t *top;
  ScanValue_t args[MAX_NUM_OF_ARGS];
  ScanValue_t end[0];
} ScanStack_t;

/******************************************************************************
                              Local variables
******************************************************************************/
static const ConsoleCommand_t *cmdTable;
static const ConsoleCommand_t *zclcmdTable;
static const ConsoleCommand_t *zdocmdTable;
static const ConsoleCommand_t *zgpcmdTable;
#ifdef OTAU_CLIENT
static const ConsoleCommand_t *otaucmdTable;
#endif
static const ConsoleCommand_t *commissioningcmdTable;
/******************************************************************************
                    Prototypes section
******************************************************************************/
static uint8_t tokenizeStr(char *str, ScanStack_t *stk);
static uint8_t unpackArgs(const ConsoleCommand_t *cmd, ScanStack_t *args);
static void processCommand(char *str);
ConsoleCommand_t *cmdForHelpCmd = NULL;

/**************************************************************************//**
\brief Converts decimal string to unsigned long

\param[in] str - string to be converted
\param[out] out - pointer to converted number

\returns 1 if conversation was successful, 0 - otherwise
******************************************************************************/
// No check for overflow
uint8_t decimalStrToUlong(const char *str, uint64_t *out)
{
  uint64_t decCnt = 1;
  uint64_t ret = 0;
  const char *p;

  if (!*str)
    return 0;  // Empty

  for (p = str; *p; p++);                    // Rewind to the end of string

  for (p--; p >= str; p--, decCnt *= 10)     // locStrP points to the last symbol at the loop start
  {
    if (!isdigit((int)*p))
      return 0;

    ret += (*p - '0') * decCnt;
  }

  *out = ret;
  return 1;
}

/**************************************************************************//**
\brief Converts decimal string to signed long

\param[in] str - string to be converted
\param[out] out - pointer to converted number

\returns 1 if conversation was successful, 0 - otherwise
******************************************************************************/
uint8_t decimalStrToSlong(const char *str, int64_t *out)
{
  uint64_t ret;

  if (*str == '-')
  {
    if (decimalStrToUlong(++str, &ret))
    {
      *out = -ret;
      return 1;
    }
  }
  else if (*str)
  {
    if (decimalStrToUlong(str, &ret))
    {
      *out = ret;
      return 1;
    }
  }

  return 0;
}

/**************************************************************************//**
\brief Converts hex string to unsigned long

\param[in] str - string to be converted
\param[out] out - pointer to converted number

\returns 1 if conversation was successful, 0 - otherwise
******************************************************************************/
uint8_t hexStrToUlong(const char *str, uint64_t *out)
{
  uint32_t shift = 0;
  uint64_t ret = 0;
  const char *p;

  if (!*str)
    return 0;  // Empty

  for (p = str; *p; p++);                  // Rewind to the end of string

  for (p--; p >= str && shift < 64; p--, shift += 4)     // locStrP points to the last symbol at the loop start
  {
    char chr = *p;

    if (chr >= 'a' && chr <= 'f')
      chr -= 'a' - 0xA;
    else if (chr >= 'A' && chr <= 'F')
      chr -= 'A' - 0xA;
    else if (chr >= '0' && chr <= '9')
      chr -= '0';
    else
      return 0;

    ret += (uint64_t)chr << shift;
  }

  *out = ret;
  return 1;
}

/**************************************************************************//**
\brief Converts hex string to uint8 array

\param[in] str - string to be converted
\param[out] out - pointer to converted number

\returns 1 if conversation was successful, 0 - otherwise
******************************************************************************/
uint8_t hexStrTouint8array(const char *str, uint8_t *out, uint8_t length)
{
  uint32_t shift = 0;
  uint8_t i = 0U;
  uint8_t local = 0U;
  uint8_t bytecount = 0U;
  const char *p;

  if (!*str)
    return 0;  // Empty

  for (p = str; *p; p++);                  // Rewind to the end of string 


  for (p--; p >= str && shift < (length * 8); p--, shift += 4)     // locStrP points to the last symbol at the loop start
  {
    char chr = *p;

    if (chr >= 'a' && chr <= 'f')
      chr -= 'a' - 0xA;
    else if (chr >= 'A' && chr <= 'F')
      chr -= 'A' - 0xA;
    else if (chr >= '0' && chr <= '9')
      chr -= '0';
    else
      return 0;
    
    ++bytecount;

    if (bytecount == 1)
    {
      local = (uint8_t)chr;
    }
    else
    {
     local += (uint8_t)chr << 4;;
     out[i++] = local;
     bytecount = 0U;
     local = 0U;
    }
  }

  return 1;
}

/**************************************************************************//**
\brief Register commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterCommands(const ConsoleCommand_t *table)
{
  cmdTable = table;
}

/**************************************************************************//**
\brief Register zcl commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterZclCommands(const ConsoleCommand_t *table)
{
  zclcmdTable = table;
}

/**************************************************************************//**
\brief Register commissioning commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterCommissioningCommands(const ConsoleCommand_t *table)
{
  commissioningcmdTable = table;
}

/**************************************************************************//**
\brief Register zdo commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterZdoCommands(const ConsoleCommand_t *table)
{
  zdocmdTable = table;
}

/**************************************************************************//**
\brief Register zgp commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterZgpCommands(const ConsoleCommand_t *table)
{
  zgpcmdTable = table;
}
#ifdef OTAU_CLIENT
/**************************************************************************//**
\brief Register zgp commands in console

\param[in] table - pointer to an array of commands
******************************************************************************/
void consoleRegisterOtauCommands(const ConsoleCommand_t *table)
{
  otaucmdTable = table;
}
#endif

/**************************************************************************//**
\brief This to post USART data to into the app queue to process

\param[in] cmdBuf - data to be posted
******************************************************/
static void APP_UartEvtUpload(char* cmdBuf)
{
  APP_Msg_T   appMsg;
  APP_Msg_T   *p_appMsg;
  appMsg.msgId = APP_MSG_UART_CMD_READY;
  memcpy(appMsg.msgData, cmdBuf, sizeof(appMsg.msgData)); 
  p_appMsg = &appMsg;
#ifdef H3_INDEPENDENT 
  OSAL_QUEUE_SendISR(&g_appQueue, p_appMsg);
#else
  OSAL_QUEUE_SendISR(&appData.appQueue, p_appMsg);
#endif  
}
/**************************************************************************//**
\brief Processes USART eveents

\param[in] cmdBuf - Command to be processed
******************************************************************************/
void process_UART_evt(char* cmdBuf)
{
  processCommand(cmdBuf);
}

/**************************************************************************//**
\brief Callbck from USART ISR to processes single char read from serial interface

\param[in] char - read char
******************************************************************************/
#ifdef H3_INDEPENDENT
void consoleRx(_DRV_UART_AsyncDev_T *dev, uint8_t data) 
#else
void consoleRx(uint8_t data)
#endif
{
  static char cmdBuf[CMD_BUF_SIZE + 1];             // Additional space for end-of-string
  static char *p = cmdBuf;
  char chr = (char)data;

  if ((chr != '\n') && (chr != '\r'))                             // Not EOL
  {
    if (isprint((int)chr))
    {
      if ((p - cmdBuf) < CMD_BUF_SIZE)  // Put to buffer
      {
#if FORCE_LOWCASE
        chr = tolower(chr);
#endif
        *p++ = chr;
        //consoleTx(chr);                   // Echo
      }
    }
    else if (chr == '\b')                   // Backspace: erase symbol
    {
      if (p > cmdBuf)                     // There are symbols in buffer - delete'em
      {
        *(--p) = 0;                      // Rewind and terminate
        //console_tx_str(VT100_ERASE_LINE"\r" CMD_PROMPT);// Reprint string
        //console_tx_str(cmdBuf);
      }
    }
    else if (chr == VT100_ESCAPE)                  // Escape: flush buffer and erase symbols
    {
      p = cmdBuf;
      //console_tx_str(VT100_ERASE_LINE"\r" CMD_PROMPT);
    }
  }
  else                                            // End of command string
  {
    if (p > cmdBuf)                         // Non-empty command
    {
      *p = 0;                              // Mark an end of string
      APP_UartEvtUpload(cmdBuf);
    }

    p = cmdBuf;                              // Drop buffer
    //console_tx_str(CRLF CMD_PROMPT);             // Command prompt
  }
}

/**************************************************************************//**
\brief Processes command

\param[in] Str - string with command
******************************************************************************/
static void processCommand(char *Str)
{
#if (MAX_NUM_OF_ARGS > 15)
  static ScanStack_t stk;
#else
  ScanStack_t stk;
#endif
  if (!tokenizeStr(Str, &stk))
    return;

  if (stk.top == stk.args)                        // No command name
    return;

  /** Seek for a matching command */
  for (const ConsoleCommand_t *cmd = cmdTable; cmd->name; cmd++)
  {
    if (strcmp(stk.args[0].str, cmd->name) == 0)    // Command match
    {
      if (!unpackArgs(cmd, &stk))
        consoleTxStr(cmd->helpMsg);
      else
        cmd->handler(stk.args + 1);
      return;
    }
  }
  for (const ConsoleCommand_t *cmd = zclcmdTable; cmd->name; cmd++)
  {
    if (strcmp(stk.args[0].str, cmd->name) == 0)    // Command match
    {
      if (!unpackArgs(cmd, &stk))
        consoleTxStr(cmd->helpMsg);
      else
        cmd->handler(stk.args + 1);
      return;
    }
  }
#ifdef OTAU_CLIENT
  for (const ConsoleCommand_t *cmd = otaucmdTable; cmd->name; cmd++)
  {
    if (strcmp(stk.args[0].str, cmd->name) == 0)    // Command match
    {
      if (!unpackArgs(cmd, &stk))
        consoleTxStr(cmd->helpMsg);
      else
        cmd->handler(stk.args + 1);
      return;
    }
  }
#endif
  for (const ConsoleCommand_t *cmd = zdocmdTable; cmd->name; cmd++)
  {
    if (strcmp(stk.args[0].str, cmd->name) == 0)    // Command match
    {
      if (!unpackArgs(cmd, &stk))
        consoleTxStr(cmd->helpMsg);
      else
        cmd->handler(stk.args + 1);
      return;
    }
  }
  for (const ConsoleCommand_t *cmd = commissioningcmdTable; cmd->name; cmd++)
  {
    if (strcmp(stk.args[0].str, cmd->name) == 0)    // Command match
    {
      if (!unpackArgs(cmd, &stk))
        consoleTxStr(cmd->helpMsg);
      else
        cmd->handler(stk.args + 1);
      return;
    }
  }
  for (const ConsoleCommand_t *cmd = zgpcmdTable; cmd->name; cmd++)
  {
    if (strcmp(stk.args[0].str, cmd->name) == 0)    // Command match
    {
      if (strcmp(cmd->fmt,"varArg")== 0) //fmt match(commands that need specific handling)
      {
        int64_t temp;
        ScanValue_t *val = (&stk)->args + 1;
        if(decimalStrToSlong(stk.args[1].str, &temp)) //(if the length of payload entered is > 0)
        {
         // check length argument of datareq is non zero
          if(temp > 0)
          {
            if(temp + 2 > MAX_NUM_OF_ARGS)
            {
              consoleTxStr("MaxPayLoadLengthExceeded - MAX_PAYLOAD_LENGTH:80\r\n");
              return;
            }

            for(uint8_t i = 0; i <= temp; i++)
            {
              if (val->str[0] == '0' && (val->str[1] == 'x' || val->str[1] == 'X'))
              {
                hexStrToUlong(&val->str[2], &val->uint64);
              }
              else                                    // Decimal
              {
                decimalStrToSlong(val->str, &val->int64);
              }
              val++;
            }
            cmd->handler(stk.args + 1);
            return;
          }
        }
        else 
          consoleTxStr(cmd->helpMsg);// to know the syntax of the Cmd
          return;
       }
      else if (!unpackArgs(cmd, &stk))//Other Cmds Handling
        consoleTxStr(cmd->helpMsg);
      else
        cmd->handler(stk.args + 1);
      return;
    }
  }
  consoleTxStr("unknown command\r\n");
}
  
/**************************************************************************//**
\brief Unpacks arguments according to the format string

\param[in] Cmd - command descriptor;
\param[in] Args - stack with pointers to arguments (some of them would be
               replaced by literal values after unpack)

\returns 1 if case of successful unpacking, 0 - otherwise
******************************************************************************/
static uint8_t unpackArgs(const ConsoleCommand_t *cmd, ScanStack_t *args)
{
  // Now we have a command and a stack of arguments
  const char *fmt = cmd->fmt;
  ScanValue_t *val = args->args + 1;

  // Unpack arguments of command according to format specifier
  for (; *fmt; fmt++, val++)
  {
    if (val >= args->top)
      return 0;

    switch (*fmt)
    {
      case 's':                                   // String, leave as is
        break;

      case 'c':                                   // Single char
        if (val->str[1])                        // Check next char - must be zero terminator
          return 0;
        val->chr = val->str[0];
        break;

      case 'd':                                   // Integer
      case 'i':
        // Lookup for hex prefix. Negative hex is not supported
        if (val->str[0] == '0' && (val->str[1] == 'x' || val->str[1] == 'X'))
        {
          if (!hexStrToUlong(&val->str[2], &val->uint64))
            return 0;
        }
        else                                    // Decimal
        {
          if (!decimalStrToSlong(val->str, &val->int64))
            return 0;
        }
        break;

      default:
        break;
    }
  }

  if (val != args->top)                           // Starvation of arguments
    return 0;

  return 1;
}

/**************************************************************************//**
\brief Splits string to white-separated tokens; "quotes" on tokens are supported

\param[in] Str - cinput string; each token(substring) would be zero-terminated;
\param[in] Stk - stack for pointers to tokens

\returns 1 if case of successful unpacking, 0 - otherwise
******************************************************************************/
static uint8_t tokenizeStr(char *str, ScanStack_t *stk)
{
  enum tokStates
  {
    WHITE,          // Inside of whitespaces
    TOK,            // Inside of token
    QTOK,           // Inside of quoted token
    POST_QTOK,      // Just after quoted token - waiting for whitespace
  };

  enum tokStates St = WHITE;

  stk->top = stk->args;

  for (; *str; str++)
  {
    switch (St)
    {
      case WHITE:
        if (*str == ' ')
          break;

        if (stk->top >= stk->end)          // No more space in stack
          return 0;

        if (*str == '"')
        {
          St = QTOK;
          (*stk->top++).str = str + 1;    // Store token position in stack (skipping quote)
        }
        else                                // Other symbol
        {
          St = TOK;
          (*stk->top++).str = str;        // Store token position in stack
        }
        break;

      case TOK:
        if (*str == '"')                    // Quotes are forbidden inside of plain token
          return 0;

        if (*str == ' ')
        {
          St = WHITE;
          *str = 0;                       // Put terminator
        }
        break;

      case QTOK:                              // Put terminator
        if (*str == '"')
        {
          St = POST_QTOK;
          *str = 0;
        }
        break;

      case POST_QTOK:
        if (*str != ' ')
          return 0;
        St = WHITE;
        break;
    }
  }

  if (St == QTOK)                             // Scan ended while inside of quote
    return 0;

  return 1;
}

#endif // APP_ENABLE_CONSOLE == 1
