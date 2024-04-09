// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object task manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoTaskManager.h

  Summary:
    This file contains the constants, types and internal interface
    of ZDO task manager.

  Description:
    This file contains the constants, types and internal interface
    of ZDO task manager.
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
#if !defined _ZDO_TASK_MANAGER_H
#define  _ZDO_TASK_MANAGER_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Identifiers of ZDO task handlers. */
typedef enum  _ZdoTaskID_t
{
  ZDO_SECURITYMANAGER_TASK_ID,
  ZDO_ZDP_MANAGER_TASK_ID,
  ZDO_POWER_MANAGER_TASK_ID,
  ZDO_START_NETWORK_TASK_ID,
  ZDO_ADDRESS_RESOLVING_TASK_ID,
  ZDO_INIT_TASK_ID,
  ZDO_TASKS_SIZE
} ZdoTaskID_t;

/** Bit array of ZDO task. If bit is '1' the task is posted. */
typedef uint8_t ZdoTaskBitMask_t;

/** Type of iterator for task identifiers. */
typedef uint8_t ZdoTaskIdIter_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Post ZDO task.

  \param taskID - identifier of ZDO task.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoPostTask(const ZdoTaskID_t taskID);

/*************************************************************************//**
  \brief Remove ZDO subtask from list of posted tasks.

  \param[in] taskID - identifier of a task which must be unpost.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoUnpostTask(ZdoTaskID_t taskID);

#endif /* _ZDO_TASK_MANAGER_H */
/** eof zdoTaskManager.h */
