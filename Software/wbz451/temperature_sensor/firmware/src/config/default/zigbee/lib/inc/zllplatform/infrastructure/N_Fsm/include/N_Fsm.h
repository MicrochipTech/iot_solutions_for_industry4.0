/*******************************************************************************
  ZLL FSM Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Fsm.h

  Summary:
    This file contains the ZLL FSM functions.

  Description:
    This file contains the ZLL FSM functions.
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


#ifndef N_FSM_H
#define N_FSM_H

#if defined(N_FSM_ENABLE_LOGGING)

#if (!defined(_WIN32)) && (!defined(N_FSM_NO_LOG_WARNING))
#warning FSM logging enabled!
#endif

// If logging is enabled (e.g. in Testharness-PC build), replace N_Fsm.h with N_Fsm-Logging.h
#  include "N_Fsm-Logging.h"

#else
// rest of file

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"
#include "zllplatform/infrastructure/N_Util/include/N_Util.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

/** State entry function.
*/
typedef void (*N_FSM_EntryFunc_t)(void);

/** State exit function.
*/
typedef void (*N_FSM_ExitFunc_t)(void);

typedef struct N_FSM_StateEntryExit_t
{
    uint8_t state;
    N_FSM_EntryFunc_t OnEntry;
    N_FSM_EntryFunc_t OnExit;
} N_FSM_StateEntryExit_t;

typedef uint8_t N_FSM_State_t;
typedef uint8_t N_FSM_Event_t;
typedef uint8_t N_FSM_Condition_t;
typedef uint8_t N_FSM_Action_t;

/** Type of condition function that determines whether a state transition should occur.
    \param condition The condition to check
    \param arg1 The first argument
    \param arg2 The second argument
    \return Decides whether the transition is taken (TRUE) or not (FALSE)
*/
typedef bool (*N_FSM_ConditionFunc_t)(N_FSM_Condition_t condition, int32_t arg1, int32_t arg2);

/** Type of action function to be called when a corresponding state transition occurs.
    \param action The action to execute
    \param arg1 The first argument
    \param arg2 The second argument
*/
typedef void (*N_FSM_ActionFunc_t)(N_FSM_Action_t action, int32_t arg1, int32_t arg2);

/** Defines one transition in a finite state machine
*/
typedef N_UTIL_ROM struct N_FSM_Transition_NoLog_t
{
    /** The event that triggers the transition, or the state in the transistion table in case the
        first bit is set.
    */
    N_FSM_Event_t          event;

    /** N_FSM_NONE/N_FSM_ELSE (for no condition) or a condition that tells whether to make the transition.
    */
    N_FSM_Condition_t      ConditionalFunction;

    /** Action, if not N_FSM_NONE, to perform when the transition occurs. */
    N_FSM_Action_t         ActionFunction;

    /** This is the state to which the transition occurs, or N_FSM_SAME_STATE. */
    N_FSM_State_t          nextState;

} N_FSM_Transition_NoLog_t;

/** Groups the tables and functions defining the finite state machine.
*/
typedef struct N_FSM_StateMachine_NoLog_t
{
    const N_FSM_Transition_NoLog_t N_UTIL_ROM* pTable;    // pointer to array of size tableSize
    uint8_t                        tableSize;
    const N_FSM_StateEntryExit_t*  pEntryExitTable;    // pointer to array of size entryExitTableSize
    uint8_t                        entryExitTableSize;
    N_FSM_ActionFunc_t             pAction;
    N_FSM_ConditionFunc_t          pCondition;

} N_FSM_StateMachine_NoLog_t;

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/

/** Placeholder to specify 'no condition' or 'no action'. */
#define N_FSM_NONE   (0xFFu)

/** Placeholder to specify 'else condition'. */
#define N_FSM_ELSE   N_FSM_NONE

/** From-state placeholder to specify 'from any state'. */
#define N_FSM_ANY_STATE   (0x7Fu)

/** Internally used in the N_FSM_STATE macro. Not to be used directly. */
#define N_FSM_STATE_BIT   (0x80u)

/** To-state placeholder to specify 'no state transition -> no enter/exit actions'. */
#define N_FSM_SAME_STATE  (0x7Fu)

/** Event placeholder to specify a default case ('all other events'). */
#define N_FSM_OTHER_EVENT (0x7Fu)

#define N_FSM_Transition_t N_FSM_Transition_NoLog_t

#define N_FSM_StateMachine_t N_FSM_StateMachine_NoLog_t

/* Macro's to make lint happy */

#define N_FSM_ENTRYEXIT(state, entry, exit) \
    {(uint8_t)(state), (entry), (exit)}

#define N_FSM_DECLARE(fsmVariable, transitionTable, transitionTableSize, entryExitTable, entryExitTableSize, actionFunction, checkFunction) \
    static const N_FSM_StateMachine_t fsmVariable = \
    { \
        transitionTable, \
        transitionTableSize, \
        entryExitTable, \
        entryExitTableSize, \
        actionFunction, \
        checkFunction \
    }

#define N_FSM_STATE(state) \
    { (N_FSM_STATE_BIT + (uint8_t)state), 0u, 0u, 0u }

#define N_FSM(event, condition, action, nextState) \
    { (uint8_t)(event), (uint8_t)(condition), (uint8_t)(action), (uint8_t)(nextState) }

#define N_FSM_TABLE_SIZE(ar) \
    ((uint8_t)(sizeof(ar)/sizeof(*(ar))))

#define N_FSM_INITIALIZE(pFsm, pActualState, initialState) \
    N_FSM_Initialize((pFsm), (pActualState), (uint8_t)(initialState))

#define N_FSM_PROCESS_EVENT(pFsm, pActualState, event) \
    N_FSM_ProcessEvent((pFsm), (pActualState), (uint8_t)(event) )

#define N_FSM_PROCESS_EVENT_1ARG(pFsm, pActualState, event, arg1) \
    N_FSM_ProcessEvent1arg((pFsm), (pActualState), (uint8_t)(event), (arg1))

#define N_FSM_PROCESS_EVENT_2ARGS(pFsm, pActualState, event, arg1, arg2) \
    N_FSM_ProcessEvent2args((pFsm), (pActualState), (uint8_t)(event), (arg1), (arg2))

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

/**************************************************************************//**
  \brief Initialize an N_FSM. Not intended for direct use. Use N_FSM_INITIALIZE() macro instead.

  \param[in] pFsm A pointer to a N_FSM_Fsm_t structure
  \param[in] pActualState Pointer to a parameter storing the actual state
  \param[in] initialState The initial state

  \return None.
 ******************************************************************************/
void N_FSM_Initialize(N_FSM_StateMachine_t const* pFsm, N_FSM_State_t* pActualState, N_FSM_State_t initialState);

/**************************************************************************//**
  \brief Processes the event through the N_FSM. The condition function and action function are called with arg1 and arg2 set to 0
        Not intended for direct use. Use N_FSM_PROCESS_EVENT() macro instead.

  \param[in] pFsm The state machine to use
  \param[in] pActualState Pointer to a parameter storing the actual state
  \param[in] event The event to handle

  \return TRUE when the the event was handled, or FALSE when it was ignored.
 ******************************************************************************/

bool N_FSM_ProcessEvent(N_FSM_StateMachine_t const* pFsm, N_FSM_State_t* pActualState, N_FSM_Event_t event);

/**************************************************************************//**
  \brief Process the event through the N_FSM and pass 1 parameter to the condition and action functions.
        The condition function and action function are called with arg2 set to 0. Not intended for direct use. 
		Use N_FSM_PROCESS_EVENT_1ARG() macro instead.

  \param[in] pFsm The state machine to use
  \param[in] pActualState Pointer to a parameter storing the actual state
  \param[in] event The event to handle
  \param[in] The argument to pass to the condition and action functions

  \return TRUE when the the event was handled, or FALSE when it was ignored.
 ******************************************************************************/

bool N_FSM_ProcessEvent1arg(N_FSM_StateMachine_t const* pFsm, N_FSM_State_t* pActualState, N_FSM_Event_t event, int32_t arg1);

/**************************************************************************//**
  \brief Process the event through the N_FSM and pass 2 parameters to the condition and action functions.
        Not intended for direct use. Use N_FSM_PROCESS_EVENT_2ARGS() macro instead.

  \param[in] pFsm The state machine to use
  \param[in] pActualState Pointer to a parameter storing the actual state
  \param[in] event The event to handle
  \param[in] arg1 The argument to pass to the condition and action functions
  \param[in] arg2 The second argument to pass to the condition and action functions

  \return TRUE when the the event was handled, or FALSE when it was ignored.
 ******************************************************************************/
bool N_FSM_ProcessEvent2args(N_FSM_StateMachine_t const* pFsm, N_FSM_State_t* pActualState, N_FSM_Event_t event, int32_t arg1, int32_t arg2);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif

#endif // N_FSM_H
