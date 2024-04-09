// DOM-IGNORE-BEGIN
/*******************************************************************************
  System Task manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysTaskManager.h

  Summary:
    The header file describes the public stack Task Manager interface,
    task handlers and tasks IDs of Task Manager

  Description:
    The header file describes the public stack Task Manager interface,
    task handlers and tasks IDs of Task Manager
 *******************************************************************************/

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

// DOM-IGNORE-BEGIN
#ifndef _TASKMANAGER_H
#define _TASKMANAGER_H
// DOM-IGNORE-END

/**************************************************************************
                               Includes section
 **************************************************************************/
 
#include <systemenvironment/include/sysTypes.h>
#include <hal/include/atomic.h>
#ifdef _USE_RTOS_
#include <framework_defs.h>
#endif

/******************************************************************************
                   Define(s) section
 **************************************************************************/


/** The list of task IDs. The IDs are sorted according to descending
    priority. For each task ID there is the corresponding task handler function. 
*/
typedef enum
{
#if defined(_SYS_MAC_PHY_HWD_TASK_) && !defined(ZAPPSI_HOST)
  MAC_PHY_HWD_TASK_ID = 1 << 0, //!< Task ID of the MAC-PHY-HWD layer
#endif
  
#ifdef _SYS_HAL_TASK_
  HAL_TASK_ID         = 1 << 1, //!< Task ID of HAL (Hardware Abstraction Layer)
#endif
  
#if defined(_SYS_MAC_HWI_TASK_) && !defined(ZAPPSI_HOST)
  MAC_HWI_TASK_ID     = 1 << 2, //!< Task ID of the MAC-HWI layer (a part of MAC independent of radio)
#endif
  
#if defined(_SYS_NWK_TASK_) && !defined(ZAPPSI_HOST)
  NWK_TASK_ID         = 1 << 3, //!< Task ID of the NWK layer
#endif
  
#if defined(_SYS_ZDO_TASK_) && !defined(ZAPPSI_HOST)
  ZDO_TASK_ID         = 1 << 4, //!< Task ID of the ZDO layer
#endif
  
#if defined(_SYS_APS_TASK_) && !defined(ZAPPSI_HOST) && !defined(_MAC2_)
  APS_TASK_ID         = 1 << 5, //!< Task ID of the APS layer
#endif
  
#if defined(_SYS_ZGP_TASK_)
  ZGP_TASK_ID         = 1 << 6, //!< Task ID of the ZGP layer
#endif
  
#if defined(_SYS_SSP_TASK_) && !defined(ZAPPSI_HOST)
  SSP_TASK_ID         = 1 << 7, //!< Task ID of Security Service Provider
#endif
  
#if defined(_SYS_TC_TASK_) && !defined(ZAPPSI_HOST)
  TC_TASK_ID          = 1 << 8, //!< Task ID of the Trust Center component
#endif
  
#if defined(ZAPPSI_NP) || defined(ZAPPSI_HOST)
  ZSI_TASK_ID         = 1 << 9, //!< Task ID of the ZAppSI component
#endif
  
#ifdef _ZCL_SUPPORT_ 
  ZCL_TASK_ID         = 1 << 10, //!< Task ID of ZigBee Cluster Library
#endif
  
#ifdef _SYS_ZLL_TASK_
  ZLL_TASK_ID         = 1 << 11, //!< Service Task ID
#endif

#ifdef _SYS_APL_TASK_
  APL_TASK_ID         = 1 << 12, //!< Task ID of the application
#endif
  
#if defined(_SYS_ZGP_TASK_) && defined(_GREENPOWER_SUPPORT_)
  ZGP_DSTUB_TASK_ID   = 1 << 13, // !<Task ID of the ZGP Dstub component
#endif

} SYS_TaskId_t;

/** Possible results of system's initialization */
typedef enum
{
  INIT_SUCCES           = 1 << 0, //!< Initialization is a success
  RF_NOT_RESPOND        = 1 << 1, //!< Radio has not responded
  HAL_NOT_RESPOND       = 1 << 2, //!< HAL has not responded
  RF_PLL_NOT_RESPOND    = 1 << 3, //!< HAL has not responded
} ZGB_InitStatus_t;

/** This function is called to process a user application task.
 The function should be defined in the user application.
 Its very first call is intended just for setting stack parameters.
 For starting a network a new task should be posted.
*/
// \cond internal
//! This function is called for processing HAL task. Should be defined in HAL
extern void HAL_TaskHandler(void);
//! This function is called for processing BSP task. Should be defined in BSP
extern void BSP_TaskHandler(void);
//! This function is called for processing MAC_PHY_HWD task. Should be defined in MAC_PHY_HWD
extern void MAC_PHY_HWD_TaskHandler(void);
//! This function is called for processing MAC_HWI task. Should be defined in MAC_HWI
extern void MAC_HWI_TaskHandler(void);
//! This function is called for processing NWK task. Should be defined in NWK
extern void NWK_TaskHandler(void);
//! This function is called for processing ZDO task. Should be defined in ZDO
extern void ZDO_TaskHandler(void);
//! This function is called for processing APS task. Should be defined in APS
extern void APS_TaskHandler(void);
//! This function is called for processing SSP task. Should be defined in SSP
extern void SSP_TaskHandler(void);
//! This function is called for processing Trust Center task. Should be defined in Trust Center
extern void TC_TaskHandler(void);
//! This function is called for processing ZAppSI task. Should be defined in ZSI
extern void ZSI_TaskHandler(void);
//! This function is called for processing ZCL task. Should be defined in ZCL
extern void ZCL_TaskHandler(void);
//! This function is called for processing ZLL task. Should be defined in ZLL
extern void ZLL_TaskHandler(void);

extern void APL_TaskHandler(void);
//! Initializes radio chip
extern bool RF_Init(void);
//! This function is called for processing PDS task. Should be defined in PDS
extern void PDS_TaskHandler(void);

//! This function is called for processing MAC_PHY_HWD task. Should be defined in MAC_PHY_HWD
extern void MAC_PHY_HWD_ForceTaskHandler(void);
//! This function is called for processing MAC_HWI task. Should be defined in MAC_HWI
extern void MAC_HWI_ForceTaskHandler(void);
//! This function is called for processing ZGP task. Should be defined for both GPD and Infra ZGP devices
extern void ZGP_TaskHandler(void);
//! This function is called for processing ZGP dstub component lower priority tasks. Should be defined only for ZGP infra devices
extern void ZGP_Dstub_TaskHandler(void);
/** The bitmask of posted task with bits' corresponding to particular stack layers.
A bit becomes set to 1 in the bitmask when the SYS_PostTask() is called with the
task ID of the corresponding layer. A bit is dropped after calling the layer's task
handler function to process the posted task. */
extern volatile uint16_t SYS_taskFlag;
// \endcond

/** Mask of enabled system tasks. Default value - 0xFFFF (All tasks are enabled).
*/
extern uint16_t SYS_taskMask;

#ifdef _USE_RTOS_
extern OSAL_API_LIST_TYPE *zos;
extern OSAL_SEM_HANDLE_TYPE semStackInternalHandler;
#endif
/***************************************************************************
                               Prototypes section
 ***********************************************************************/

/********************************************************************//**
  \brief Posts a task to the task manager, which is later processed by the task handler of the corresponding stack layer.
  
  A task is processed in the SYS_RunTask() function.
  
  \param taskId - ID of the posted task. The application's ID is ::APL_TASK_ID.
   
  IDs of the tasks are listed in the SYS_TaskId enum. Each task has its own priority and is called
  only if there is no any task with higher priority. A handler is called when respective task can be run.
  Each task has its own task handler. Correspondence between tasks and handlers is listed below:  \n
  HAL - HAL_TaskHandler()                 \n
  BSP - BSP_TaskHandler()                 \n
  MAC_PHY_HWD - MAC_PHY_HWD_TaskHandler() \n
  MAC_HWI - MAC_HWI_TaskHandler()         \n
  ZGP - ZGP_TaskHandler()                 \n
  NWK - NWK_TaskHandler()                 \n
  ZDO - ZDO_TaskHandler()                 \n
  APS - APS_TaskHandler()                 \n
  APL - APL_TaskHandler()                 \n
  
  \return None
 ********************************************************************/
INLINE void SYS_PostTask(SYS_TaskId_t taskId)
{
//\cond internal

  if(!(SYS_taskFlag & taskId)) // Post the task only if its not set already
  {
ATOMIC_SECTION_ENTER
     SYS_taskFlag |= taskId;
ATOMIC_SECTION_LEAVE

#ifdef _USE_RTOS_
    zos->OSAL_SEM_Post(&semStackInternalHandler);
#endif
  }

//\endcond
}

INLINE void SYS_PostTaskFromISR(SYS_TaskId_t taskId)
{
//\cond internal

  if(!(SYS_taskFlag & taskId)) // Post the task only if its not set already
  {
     SYS_taskFlag |= taskId;
#ifdef _USE_RTOS_
     zos->OSAL_SEM_PostISR(&semStackInternalHandler);
#endif
  }

//\endcond
}

/********************************************************************//**
  \brief Disables specified task.

  \param[in] taskId - task to be disabled.
 **************************************************************************/
INLINE void SYS_DisableTask(SYS_TaskId_t taskId)
{
  SYS_taskMask &= ~taskId;
}

/**************************************************************//**
  \brief Enables specified task.

  \param[in] taskId - task to be enabled.
 *************************************************************************/
INLINE void SYS_EnableTask(SYS_TaskId_t taskId)
{
  SYS_taskMask |= taskId;
}

/*****************************************************************//**
  \brief  This function is called by the stack or from the \c main() function to process tasks.

If several tasks have been posted by the moment of the function's call, they are executed
in order of layers' priority: a task of the layer with the highest priority is executed first.

  ingroup sys
  
   \param None
   \return None
 **********************************************************************/
void SYS_RunTask(void);
bool SYS_PostIdleTask(void);

//\cond internal
/***************************************************************//**
  \brief To force runTask to help making sync calls

   ingroup sys
 ***********************************************************************/
void SYS_ForceRunTask(void);

/*****************************************************************//**
  \brief To force Pdshandler to help making sync calls

  ingroup sys
 *******************************************************************/
void SYS_ForcePdsHandler(void);
// \endcond


/********************************************************//**
  \brief Force PDS handler procedure
 *****************************************************/
void SYS_ForceZsiHandler(void);

/****************************************************//**
  \brief Initializes the Zigbee Stack internal tasks

  ingroup sys

This is the first stack function to be called by the application in the \c main()
function.

  \param none
  \return Initialization result
 **********************************************************/
void ZB_SysTaskInit(void);

/*****************************************************************//**
  \brief Checks Zigbee ready to Sleep

  ingroup sys

This is the function to be called / Checked by the application before entering into sleep \c main()
function.

  \param none
  \return Initialization result
 ******************************************************************/
bool ZB_ReadyToSleep(void);

/***********************************************************//**
  \brief Check Zigbee is Idle or not by the application

  ingroup sys

This is the function to be called by the application before invoking any critical actions( ex: Flash write) in application \c main()
function.

  \param none
  \return Initialization result
 ********************************************************************/
bool ZB_IsIdle(void);

#endif
