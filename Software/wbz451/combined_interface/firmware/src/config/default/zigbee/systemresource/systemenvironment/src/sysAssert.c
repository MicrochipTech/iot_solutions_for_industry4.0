/*******************************************************************************
  System assert Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysAssert.c

  Summary:
    This component provides a Assert facility.

  Description:
    This component provides a Assert facility. The component provides application
    to register hooks that are invoked when Assert is encountered in execution. 
    Application handler should log the information and take corrective action.
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
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysAssert.h>
#ifndef MAP_ALL_ASSERT_LEVEL_TO_SYSASSERT
/******************************************************************************
                              Definitions section
 ******************************************************************************/

void SYS_AssertSubscribe(SYS_AssertCallback_t pCallback);

/******************************************************************************
                              Global variable section
 ******************************************************************************/

SYS_AssertParam_t gAssertParam;

#ifdef  USE_DBGCODE
uint16_t gAssertDbgCode;
#endif

#ifdef  USE_COMPID
uint16_t gAssertCompId;
#endif


#ifdef  USE_LINENUM
int16_t gAssertLine;
#endif

#ifdef USE_FILENAME
const char *gAssertFile;
#endif

SYS_AssertCallback_t s_pAssertSubscriber;


/** Subscribe callback, callback will be called when a assert occurs.
    Only one subscriber is allowed.
*/
void SYS_AssertSubscribe(SYS_AssertCallback_t pCallback)
{
  if (pCallback)
    s_pAssertSubscriber = pCallback;
}


/**************************************************************************//**
  \brief SYS_DefAssertCallbackWarn callback invoked on WARN LEVEL ASSERTS
  if enabled       
  \param[in] None
  \return None
******************************************************************************/
void SYS_DefAssertCallbackWarn()
{
  gAssertParam.level   = WARN_LEVEL;

#ifdef USE_DBGCODE
  gAssertParam.dbgCode = gAssertDbgCode;
#endif
#ifdef USE_LINENUM
  gAssertParam.line    = gAssertLine;
#endif
#ifdef USE_COMPID 
  gAssertParam.componentId =  gAssertCompId;
#endif
#ifdef USE_FILENAME
  gAssertParam.file = gAssertFile;
#endif

  if ( NULL != s_pAssertSubscriber ) 
    s_pAssertSubscriber(&gAssertParam); 
} 
 
/**************************************************************************//**
  \brief SYS_DefAssertCallbackError callback invoked on ERROR LEVEL ASSERTS
  if enabled       
  \param[in] None
  \return None
******************************************************************************/
void SYS_DefAssertCallbackError()
{
  gAssertParam.level   = ERROR_LEVEL;
   
#ifdef USE_DBGCODE
  gAssertParam.dbgCode = gAssertDbgCode;
#endif
#ifdef USE_LINENUM
  gAssertParam.line    = gAssertLine;
#endif
#ifdef USE_COMPID 
  gAssertParam.componentId =  gAssertCompId;
#endif
#ifdef USE_FILENAME
  gAssertParam.file = gAssertFile;
#endif

  if ( NULL !=  s_pAssertSubscriber  ) 
    s_pAssertSubscriber(&gAssertParam); 
} 

/**************************************************************************//**
  \brief SYS_DefAssertCallbackFatal callback called on FATAL LEVEL ASSERTS
  if enabled, This function invokes registered callback
  \param[in] None
  \return None
******************************************************************************/
void SYS_DefAssertCallbackFatal()
{
  gAssertParam.level   = FATAL_LEVEL;

#ifdef USE_DBGCODE
  gAssertParam.dbgCode = gAssertDbgCode;
#endif
#ifdef USE_LINENUM
  gAssertParam.line    = gAssertLine;
#endif
#ifdef USE_COMPID 
  gAssertParam.componentId =  gAssertCompId;
#endif
#ifdef USE_FILENAME
  gAssertParam.file = gAssertFile;
#endif

  if ( NULL != s_pAssertSubscriber ) 
    s_pAssertSubscriber(&gAssertParam); 
} 
#endif
