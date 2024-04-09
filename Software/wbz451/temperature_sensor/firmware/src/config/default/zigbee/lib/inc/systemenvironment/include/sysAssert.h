/*******************************************************************************
  System assert Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysAssert.h

  Summary:
    This component provides a Assert facility. The component provides application
    to register hooks that are invoked when Assert is encountered in execution. 
    Application handler should log the diagnostic information and take corrective 
    action.

  Description:
    This component provides a Assert facility. The component provides application
    to register hooks that are invoked when Assert is encountered in execution. 
    Application handler should log the diagnostic information and take corrective 
    action.
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

#ifndef __SYS_ASSERT_H__
#define __SYS_ASSERT_H__

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/dbg.h>
/******************************************************************************
                              Definitions section
 ******************************************************************************/

/******************************************************************************
 *           Top Level MACROs to control behaviour of SYS_E_ASSERTS_xx
 *****************************************************************************/
/*! \def MAP_ALL_ASSERT_LEVEL_TO_SYSASSERT
 *  \brief A macro that maps all SYS_E_ASSERT calls to sysAssert function
 */
 /*! \def USE_WARN_ASSERTS
  *  \brief A macro that maps SYS_E_ASSERT_WARN to its implementation when not defined
  *  SYS_E_ASSERT_WARN macro will not have any effect. This is not defined in release mode
 */
  /*! \def USE_ERROR_ASSERTS
  *  \brief A macro that maps SYS_E_ASSERT_ERROR to its implementation when not defined
  *  SYS_E_ASSERT_ERROR macro will not have any effect
 */
  /*! \def USE_FATAL_ASSERTS
  *  \brief A macro that maps SYS_E_ASSERT_FATAL to its implementation when not defined 
  *  SYS_E_ASSERT_FATAL macro will not have any effect
 */
  /*! \def USE_DBGCODE
  *  \brief A macro that is used to populate and pass dbgCode associated with
  *  current occurance to assert callback handler registerd by application (if any)
 */
  /*! \def USE_COMPID
  *  \brief A macro that is used to populate and pass component id associated with
  *  current occurance to assert callback handler registerd by application (if any)
 */
  /*! \def USE_LINENUM
  *  \brief A macro that is used to populate and pass line number associated with
  *  current occurance to assert callback handler registerd by application (if any)
  */
  /*!  \def USE_FILENAME
  *  \brief A macro that is used to populate and pass filename associated with
  *  current occurance to assert callback handler registerd by application (if any)
 */

  /*! \def INVOKE_CALLBACK_WARN
  *  \brief A macro that is used to control if callback should be invoked for
  *  WARN_LEVEL asserts
 */
  /*! \def INVOKE_CALLBACK_ERROR
  *  \brief A macro that is used to control if callback should be invoked for
  *  ERROR_LEVEL asserts
 */
  /*! \def INVOKE_CALLBACK_FATAL
  *  \brief A macro that is used to control if callback should be invoked for
  *  FATAL_LEVEL asserts
 */

/******************************************************************************
 *           Top Level MACROs to control behaviour of SYS_E_ASSERTS_xx
 *****************************************************************************/

//#define MAP_ALL_ASSERT_LEVEL_TO_SYSASSERT
#ifdef MAP_ALL_ASSERT_LEVEL_TO_SYSASSERT

  #define SYS_E_ASSERT_WARN(condition,  MDbgCode)   sysAssert(condition, MDbgCode);
  #define SYS_E_ASSERT_ERROR(condition, MDbgCode)   sysAssert(condition, MDbgCode);
  #define SYS_E_ASSERT_FATAL(condition, MDbgCode)   sysAssert(condition, MDbgCode);

#else

#ifdef RELEASE

//  #define USE_WARN_ASSERTS
  #define USE_ERROR_ASSERTS
  #define USE_FATAL_ASSERTS

  /** Information to populate for callback handler (have size impact) **/
  #define USE_DBGCODE
//#define USE_COMPID
//#define USE_FILENAME 
//#define USE_LINENUM

#else
 
  #define USE_WARN_ASSERTS
  #define USE_ERROR_ASSERTS
  #define USE_FATAL_ASSERTS
 
  /** Information to populate for callback handler (have size impact for each) **/
  #define USE_DBGCODE
//#define USE_COMPID
//#define USE_FILENAME // File name and component ids are same in nature so ideally only one should be used
//#define USE_LINENUM

#endif


#ifdef RELEASE
  #define  INVOKE_CALLBACK_WARN()   SYS_DefAssertCallbackWarn();
  #define  INVOKE_CALLBACK_ERROR()  SYS_DefAssertCallbackError();
  #define  INVOKE_CALLBACK_FATAL()  SYS_DefAssertCallbackFatal();
#else
  #define  INVOKE_CALLBACK_WARN()   SYS_DefAssertCallbackWarn();
  #define  INVOKE_CALLBACK_ERROR()  SYS_DefAssertCallbackError();
  #define  INVOKE_CALLBACK_FATAL()  SYS_DefAssertCallbackFatal();
#endif

/** Assert levels.  */

#define   WARN_LEVEL   1

#define   ERROR_LEVEL  2

#define   FATAL_LEVEL  3


#ifdef USE_COMPID
#ifndef COMPID
#define COMPID 8
#endif
#endif

/** LOG MACRO.
 * Loggig can be turned off by not mapping this macro
*/

/*! 
    \def LOG((dbgCode, file, line)
    \brief Log the given message always if logging supported
    \param dbgCode Encoded dbgCode 
    \param file Name of File (Optionally comonent ID) 
    \param line line information within file 
*/
#ifndef PLATFORM_PC
  #define LOG(dbgCode, file, line )
#else
  #define LOG(dbgCode, file, line ) printf("\nCODE_%d:FILE %s:Line %d", dbgCode, file, line)
#endif

#ifdef USE_DBGCODE
  #define  POPULATE_DBGCODE(MDbgCode)     gAssertDbgCode  = MDbgCode;
#else
  #define  POPULATE_DBGCODE(MDbgCode)
#endif

#ifdef USE_COMPID
  #define  POPULATE_COMPID()               gAssertCompId   = COMPID;
#else
  #define  POPULATE_COMPID()
#endif

#ifdef USE_FILENAME
  #define  POPULATE_FILE()                 gAssertFile     = __FILE__;
#else
  #define  POPULATE_FILE()                 
#endif

#ifdef USE_LINENUM
  #define  POPULATE_LINE()                 gAssertLine     = __LINE__;
#else
  #define  POPULATE_LINE()                 
#endif



/* These macros are intended for use by components */


/** \brief SYS_E_ASSERT_WARN MACRO 
    \param condition   boolean value or expression evaluating to boolean value
    \param MDbgCode    Encoded dbgCode 
*/
#ifdef USE_WARN_ASSERTS
  #define SYS_E_ASSERT_WARN(condition, MDbgCode)  \
    if (0 == (condition) ) \
    { \
      POPULATE_DBGCODE(MDbgCode)   \
      POPULATE_COMPID()            \
      POPULATE_LINE()              \
      POPULATE_FILE()              \
      INVOKE_CALLBACK_WARN()       \
    }
#else
  #define SYS_E_ASSERT_WARN(condition, MDbgCode)  
#endif

/** \brief SYS_E_ASSERT_ERROR MACRO 
    \param condition   boolean value or expression evaluating to boolean value
    \param MDbgCode    Encoded dbgCode 
*/
#ifdef USE_ERROR_ASSERTS
  #define SYS_E_ASSERT_ERROR(condition, MDbgCode)   \
    if (0 == (condition) ) \
    { \
      POPULATE_DBGCODE(MDbgCode)   \
      POPULATE_COMPID()            \
      POPULATE_LINE()              \
      POPULATE_FILE()              \
      INVOKE_CALLBACK_ERROR()      \
    }
#else
  #define SYS_E_ASSERT_ERROR(condition, MDbgCode)   
#endif

/** \brief SYS_E_ASSERT_FATAL MACRO 
    \param condition   boolean value or expression evaluating to boolean value
    \param MDbgCode    Encoded dbgCode 
*/
#ifdef USE_FATAL_ASSERTS
  #define SYS_E_ASSERT_FATAL(condition, MDbgCode)   \
    if (0 == (condition) ) \
    { \
      POPULATE_DBGCODE(MDbgCode)   \
      POPULATE_COMPID()            \
      POPULATE_LINE()              \
      POPULATE_FILE()              \
      INVOKE_CALLBACK_FATAL()      \
    }

#else
  #define SYS_E_ASSERT_FATAL(condition, MDbgCode)  
#endif


/******************************************************************************
                                 Types section
 ******************************************************************************/

typedef struct
{
  uint16_t         level;

#ifdef  USE_DBGCODE 
  uint16_t         dbgCode;
#endif

#ifdef  USE_LINENUM
  int16_t         line;
#endif

#ifdef USE_COMPID 
  uint16_t         componentId;
#endif

#ifdef  USE_FILENAME
  const char     *file;
#endif

}SYS_AssertParam_t;

/** Callback function type. Called when assert occurs in code flow
    \param SYS_AssertParam_t * pointer to SYS_AssertParam_t structure
*/

typedef void (* SYS_AssertCallback_t)(SYS_AssertParam_t *);

/******************************************************************************
                             Prototypes section
 ******************************************************************************/

/** Subscribe callback, callback will be called when a assert occurs.
    Only one subscriber is allowed.
*/
void SYS_AssertSubscribe(SYS_AssertCallback_t pCallback);

extern SYS_AssertParam_t gAssertParam;
#ifdef  USE_DBGCODE 
extern uint16_t gAssertDbgCode;
#endif

#ifdef  USE_COMPID
extern uint16_t gAssertCompId;
#endif


#ifdef  USE_LINENUM
extern int16_t gAssertLine;
#endif

#ifdef  USE_FILENAME
extern const char *gAssertFile;
#endif

extern SYS_AssertCallback_t s_pAssertSubscriber;


/**************************************************************************//**
  \brief SYS_DefAssertCallbackWarn callback called on WARN LEVEL ASSERTS
  if enabled, This function invokes registered callback
  \param[in]  None
  \return   None
******************************************************************************/
void SYS_DefAssertCallbackWarn();

/**************************************************************************//**
  \brief SYS_DefAssertCallbackError callback invoked on ERROR LEVEL ASSERTS
  if enabled       
  \param[in] None
  \return   None
******************************************************************************/
void SYS_DefAssertCallbackError(void);

/**************************************************************************//**
  \brief SYS_DefAssertCallbackFatal callback called on FATAL LEVEL ASSERTS
  if enabled, This function invokes registered callback
  \param[in]  None
  \return   None
******************************************************************************/
void SYS_DefAssertCallbackFatal(void);
#endif

#endif //__SYS_ASSERT_H__
