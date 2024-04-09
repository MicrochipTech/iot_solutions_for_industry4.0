
/*******************************************************************************
  Application errors source File

  Company:
    Microchip Technology Inc.

  File Name:
    errH.c

  Summary:
    This file contains the declarations for proccesing Errors  

  Description:
    This file contains the declarations for proccesing Errors 
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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zllplatform/infrastructure/N_ErrH/include/N_ErrH.h>
#include <z3device/common/include/errH.h>
#include <z3device/common/include/printLcd.h>
#include <systemenvironment/include/sysAssert.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyPic32cx.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#define ERROR_HANDLERS_MAX_AMOUNT 5u
#define COMPID                    "ErrH"

/******************************************************************************
                    Prototypes section
******************************************************************************/
static void errHProcessFatalError(const char *compId, uint16_t line);
static void assertHandler(SYS_AssertParam_t *assertParam);

/******************************************************************************
                    Static variables section
******************************************************************************/
static ErrorAbortCb_t errorHandlers[ERROR_HANDLERS_MAX_AMOUNT] = {0};
static uint8_t numHandlers;
static int8_t currentHandler = -1;

/******************************************************************************
                    Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Initializes errH module
******************************************************************************/
void errHInit(void)
{
  N_ErrH_ResetSubscriber();
  N_ErrH_Subscribe(errHProcessFatalError);
  SYS_AssertSubscribe(assertHandler);
}

/**************************************************************************//**
\brief Subscribes for fatal error

\param[in] handler - callback function which is called is case of error
******************************************************************************/
void errHSubscribeForFatal(ErrorAbortCb_t handler)
{
  N_ERRH_ASSERT_FATAL((ERROR_HANDLERS_MAX_AMOUNT - 1) > numHandlers);
  errorHandlers[numHandlers] = handler;
  currentHandler = numHandlers;
  numHandlers++;
}

/**************************************************************************//**
\brief Procceses fatal errors, calls subsribers

\param[in] compId - the name of the module where fatal error occured;
\param[in] line   - the line in the module woth fatal error
******************************************************************************/
static void errHProcessFatalError(const char *compId, uint16_t line)
{
  while (0 <= currentHandler)
  {
    uint8_t tmp = currentHandler;
    currentHandler--;
    // First decrement, then call: if the call fails (calls ErrH_Fatal recursively), it is not
    // retried next time (possibly an infinite loop)!
    (errorHandlers[tmp])(compId, line);
  }

#if !defined _DEBUG_ && !defined ZAPPSI_HOST
  SystemReset();
#endif

  while (1);
}

/**************************************************************************//**
\brief Handler to notify assertion (from down layers)

\param[in] SYS_AssertParam_t * type, holding information about the assertion
******************************************************************************/
static void assertHandler(SYS_AssertParam_t *assertParam)
{
  if (assertParam)
  {
    switch (assertParam->level)
    {
      case FATAL_LEVEL:
      {
#if APP_DEVICE_EVENTS_LOGGING == 1           
        LOG_STRING(assertFtlStr, "FATAL:Code:0x%x \n");
        appSnprintf(assertFtlStr, assertParam->dbgCode);
#endif

#ifdef RELEASE
        SystemReset();
#endif
#if APP_DEVICE_EVENTS_LOGGING == 1          
        /* ensure the print buffer gets flushes out */
        appSnprintf(assertFtlStr, assertParam->dbgCode);
        appSnprintf(assertFtlStr, assertParam->dbgCode);
#endif
        /* fatal is considered irrecoverable.
           go for reset, after backing up needed stuff */
        while (1)
        {
          (void)assertParam->dbgCode;
        }
      }
      break;

      /* Add code here to take appropriate action for a level */
      case ERROR_LEVEL:
      {
#if APP_DEVICE_EVENTS_LOGGING == 1            
        LOG_STRING(assertErrStr, "ERROR:Code:0x%x \n");
        appSnprintf(assertErrStr, assertParam->dbgCode);
#endif
      }
      break;

      case WARN_LEVEL:
      {
        //LOG_STRING(assertInfStr, "WARN:Code:0x%x \n");
        //appSnprintf(assertInfStr, assertParam->dbgCode);
      }
      default:
      break;
    }
  }
  else
  {
#if APP_DEVICE_EVENTS_LOGGING == 1        
    LOG_STRING(assertInvStr, "Invalid assert param\n");
    appSnprintf(assertInvStr);
#endif
  }
}
/**************************************************************************//**
\brief Subscribes for fatal errors, calls subscribers

\param[in] compId - the name of the module where fatal error occurred;
\param[in] line   - the line in the module with fatal error
******************************************************************************/
void errHFatal (const char *compId, uint16_t line)
{
  (void)compId;
  (void)line;
}
/* eof errH.c */
