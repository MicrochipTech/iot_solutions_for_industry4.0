/*******************************************************************************
  ZLL Error Handling Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_ErrH.h

  Summary:
    This file contains the ZLL Error Handling functions.

  Description:
    This file contains the ZLL Error Handling functions.
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


#ifndef N_ERRH_H
#define N_ERRH_H

/*******************************************************************************
* INCLUDE FILES
*******************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"
#include "zllplatform/infrastructure/N_Util/include/N_Util.h"

/*******************************************************************************
* C++ DECLARATION WRAPPER
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* EXPORTED TYPES
*******************************************************************************/

/** Callback function type. Called when a fatal error occurs.

    The callback function should not return.
*/
typedef void (*N_ErrH_Callback_t)(const char* compId, uint16_t line);

/*******************************************************************************
* EXPORTED MACROS AND CONSTANTS
*******************************************************************************/

/** Unconditionally call the fatal error handler.
*/
#define N_ERRH_FATAL() \
    N_UTIL_SWALLOW_SEMICOLON( \
        N_ErrH_Fatal(COMPID, (uint16_t)__LINE__); \
        ) \
        /*lint -unreachable */

/** Check the condition and call the fatal error handler when it is false.
    \param cond The condition to check
    To save space, __FILE__ is not used. The location can be deduced from COMPID
    when used correctly.
*/
#define N_ERRH_ASSERT_FATAL(cond) \
    N_UTIL_SWALLOW_SEMICOLON( \
        if (!(cond)) \
        { \
            N_ERRH_FATAL(); \
            /*lint -unreachable */ \
        } \
    )

/******************************************************************************
                              Prototypes section
 ******************************************************************************//**************************************************************************//**
  \brief Subscribe callback that is called when a fatal error occurs.
         Only one subscriber is allowed.

  \return None.
 ******************************************************************************/
void N_ErrH_Subscribe(N_ErrH_Callback_t pCallback);

/**************************************************************************//**
  \brief A fatal error occured.
         Not intended to be called directly. Use the macros instead.

  \return None.
 ******************************************************************************/
void N_ErrH_Fatal(const char* compId, uint16_t line);

/**************************************************************************//**
  \brief Reset the currently subscribed callback that is called when a fatal error occurs.

  \return None.
 ******************************************************************************/
void N_ErrH_ResetSubscriber(void);

/*******************************************************************************
* END OF C++ DECLARATION WRAPPER
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_ERRH_H
