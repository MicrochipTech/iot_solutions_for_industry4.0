/*******************************************************************************
  ZLL Logging Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Log.h

  Summary:
    This file contains the ZLL Logging functions.

  Description:
    This component provides a logging facility.
    As a bonus, the component shows fatal errors on the LCD when they occur.
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


#ifndef N_LOG_H
#define N_LOG_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Util/include/N_Util.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

#include <stdarg.h>

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

/** Log levels.
*/
typedef enum _N_Log_Level_t
{
    N_Log_Level_None      = 0x0000u,
    N_Log_Level_Fatal     = 0x0001u,    /**< Logging about a fatal error */
    N_Log_Level_Warning   = 0x0002u,    /**< Logging about a non-fatal strange condition */
    N_Log_Level_Info      = 0x0004u,    /**< Remarkable information */
    N_Log_Level_State     = 0x0008u,    /**< State change */
    N_Log_Level_ExtEnter  = 0x0010u,    /**< Enter of an external interface function */
    N_Log_Level_ExtLeave  = 0x0020u,    /**< Leave of an external interface function */
    N_Log_Level_CbEnter   = 0x0040u,    /**< Enter of a callback function */
    N_Log_Level_CbLeave   = 0x0080u,    /**< Leave of a callback function */
    N_Log_Level_CbCall    = 0x0100u,    /**< Calling a callback function */
    N_Log_Level_FuncEnter = 0x0200u,    /**< Enter of a local function */
    N_Log_Level_OsalEvent = 0x0400u,    /**< An OSAL event is handled */
    N_Log_Level_Free1     = 0x1000u,    /**< User-defined logging level */
    N_Log_Level_Free2     = 0x2000u,    /**< User-defined logging level */
    N_Log_Level_Free3     = 0x4000u,    /**< User-defined logging level */
    N_Log_Level_All       = 0xFFFFu,
} N_Log_Level_t;

/** Callback function type. Called when something is logged.
    \param compId The component ID
    \param level The log-level
    \param func The name of the function (for function logging) or NULL
    \param format Printf style format string
    \param ap Variable arguments list used with the format string
*/
typedef void (*N_Log_Callback_t)(const char* compId, N_Log_Level_t level, const char* func, const char* format, va_list ap);

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/

/** Macro for logging. Intended for internal use only
*/
#define N_LOG_COMPID(compid,level,func,msg) \
    N_UTIL_SWALLOW_SEMICOLON( \
        N_Log_Prepare(compid, level, func); \
        N_Log_Trace msg ; \
    )

#if defined(N_LOG_ENABLE_DEBUG_LOGGING)
#  define N_LOGX(compid,level,func,msg)   N_LOG_COMPID(compid,level,func,msg)
#else
#  define N_LOGX(compid,level,func,args)
#endif

/* These macros are intended for use by components */

/** \brief Log the given message at the given level
    \param level One of the N_Log_Level_t enum values
    \param msg The following format: ("printf-like format string"{,args})
*/
#define N_LOG(level,msg)        N_LOGX(COMPID, level, NULL, msg)

/** \brief Log function entry with automatic function name logging
    \param level One of the N_Log_Level_t enum values, but should be one of the *_Enter values
    \param msg Printf-like format string with arguments, intended for function arguments
*/
#define N_LOGF(level,msg)       N_LOGX(COMPID, level, __func__, msg)

// Shortcuts:
#define N_LOG_FATAL(msg)        N_LOG(N_Log_Level_Fatal, msg)
#define N_LOG_WARNING(msg)      N_LOG(N_Log_Level_Warning, msg)
#define N_LOG_INFO(msg)         N_LOG(N_Log_Level_Info, msg)
#define N_LOG_STATE(msg)        N_LOG(N_Log_Level_State, msg)
#define N_LOG_EXT_ENTER(msg)    N_LOG(N_Log_Level_ExtEnter, msg)
#define N_LOG_EXT_LEAVE(msg)    N_LOG(N_Log_Level_ExtLeave, msg)
#define N_LOG_CB_ENTER(msg)     N_LOG(N_Log_Level_CbLeave, msg)
#define N_LOG_CB_LEAVE(msg)     N_LOG(N_Log_Level_CbLeave, msg)
#define N_LOG_CB_CALL(msg)      N_LOG(N_Log_Level_CbCall, msg)
#define N_LOG_OSAL_EVENT(msg)   N_LOG(N_Log_Level_OsalEvent, msg)
#define N_LOG_FREE1(msg)        N_LOG(N_Log_Level_Free1, msg)
#define N_LOG_FREE2(msg)        N_LOG(N_Log_Level_Free2, msg)
#define N_LOG_FREE3(msg)        N_LOG(N_Log_Level_Free3, msg)

// Shortcuts for function call logging:
#define N_LOGF_EXT_ENTER(msg)   N_LOGF(N_Log_Level_ExtEnter, msg)
#define N_LOGF_CB_ENTER(msg)    N_LOGF(N_Log_Level_CbEnter, msg)
#define N_LOGF_FUNC_ENTER(msg)  N_LOGF(N_Log_Level_FuncEnter, msg)

/** Log message even when USE_DEBUG_LOGGING is not defined */
#define N_LOG_ALWAYS(msg) \
    N_UTIL_SWALLOW_SEMICOLON( \
        N_Log_Prepare(COMPID, N_Log_Level_Info, NULL); \
        N_Log_Trace msg ; \
    )

/** Log a non-fatal error.
    If N_LOG_NON_FATALS_ARE_FATAL is defined, then a non-fatal error becomes fatal.
    Else if N_LOG_ENABLE_NON_FATALS is defined, then the error is logged.
    Else the error is ignored.
*/
#if defined(N_LOG_NON_FATALS_ARE_FATAL)
#  define N_LOG_NONFATAL() N_ERRH_FATAL()
#else
#  if defined(N_LOG_ENABLE_NON_FATALS)
#    define N_LOG_NONFATAL() N_LOG_ALWAYS(("%d", __LINE__))
#  else
#    define N_LOG_NONFATAL() /* empty */
#  endif
#endif

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Subscribe callback that is called when something needs to be logged.
        Only one subscriber is allowed.

  \return None.
 ******************************************************************************/
void N_Log_Subscribe(N_Log_Callback_t pCallback);

/**************************************************************************//**
  \brief Prepares the following N_Log_Trace() function call
        Note: Not to be directly used, only through the N_LOG macro

  \param[in] compId The component ID
  \param[in] level The log-level
  \param[in] func The name of the function (for function logging) or NULL

  \return None.
 ******************************************************************************/
void N_Log_Prepare(const char* compId, N_Log_Level_t level, const char* func);

/**************************************************************************//**
  \brief Print log message. Not to be directly used (only to be used via N_LOG macro)
        Note: N_Log_Prepare() must be called immediately before calling this function.

  \return None.
 ******************************************************************************/
void N_Log_Trace(const char* format, ...);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_LOG_H
