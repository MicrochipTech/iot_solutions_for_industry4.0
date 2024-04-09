/*******************************************************************************
  System task manager Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysTaskManager.c

  Summary:
    The header file describes the public stack Task Manager interface,
    task handlers and tasks IDs of Task Manager.

  Description:
    The header file describes the public stack Task Manager interface,
    task handlers and tasks IDs of Task Manager.
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
#include <systemenvironment/include/sysTaskManager.h>
#include <systemenvironment/include/sysDbg.h>
#include <systemenvironment/include/sysEvents.h>
#include <systemenvironment/include/sysIdleHandler.h>
#include <systemenvironment/include/sysAssert.h>
#include <zdo/include/zdo.h>

#if defined(_USE_KF_MAC_)
#include <mac_phy/include/mac_api.h>
#else  // defined(_USE_KF_MAC_)
#endif // defined(_USE_KF_MAC_)

#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyPic32cx.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyInit.h>

#ifdef SIMULATOR
  #include <halMedium.h>
#endif
#ifdef ZAPPSI_HOST
#include <zsiMem.h>
#include <systemenvironment/include/sysInit.h>
#endif
/******************************************************************************
                             Prototypes section
******************************************************************************/

/******************************************************************************
                             External variables section
******************************************************************************/
volatile uint16_t SYS_taskFlag = 0;
uint16_t SYS_taskMask = 0xFFFF;
/******************************************************************************
                             Static variables section
******************************************************************************/

/*
typedef enum
{
  MAC_PHY_HWD_TASK_ID = 1 << 0, //!< Task ID of the MAC-PHY-HWD layer
  HAL_TASK_ID         = 1 << 1, //!< Task ID of HAL (Hardware Abstraction Layer)
  MAC_HWI_TASK_ID     = 1 << 2, //!< Task ID of the MAC-HWI layer (a part of MAC independent of radio)
  NWK_TASK_ID         = 1 << 3, //!< Task ID of the NWK layer
  ZDO_TASK_ID         = 1 << 4, //!< Task ID of the ZDO layer
  APS_TASK_ID         = 1 << 5, //!< Task ID of the APS layer
  ZGP_TASK_ID         = 1 << 6, //!< Task ID of the ZGP layer
  SSP_TASK_ID         = 1 << 7, //!< Task ID of Security Service Provider
  TC_TASK_ID          = 1 << 8, //!< Task ID of the Trust Center component
  ZSI_TASK_ID         = 1 << 9, //!< Task ID of the ZAppSI component
  ZCL_TASK_ID         = 1 << 10, //!< Task ID of ZigBee Cluster Library
  ZLL_TASK_ID         = 1 << 11, //!< Service Task ID
  PDS_TASK_ID         = 1 << 12, //!< Task ID of the Persistent Data Server component
  ZGP_DSTUB_TASK_ID   = 1 << 13, // !<Task ID of the ZGP Dstub component
} SYS_TaskId_t;

*/
static void (*taskHandlers[])() = {
#if defined(_SYS_MAC_PHY_HWD_TASK_) && !defined(ZAPPSI_HOST)
  MAC_PHY_HWD_TaskHandler,    // ID 0
#else
  NULL,
#endif

#ifdef _SYS_HAL_TASK_
  HAL_TaskHandler,          // ID 1
#else
  NULL,
#endif

#if defined(_SYS_MAC_HWI_TASK_) && !defined(ZAPPSI_HOST)
  MAC_HWI_TaskHandler,    // ID 2
#else
  NULL,
#endif

#if defined(_SYS_NWK_TASK_) && !defined(ZAPPSI_HOST)
  NWK_TaskHandler,    // ID 3
#else
  NULL,
#endif

#if defined(_SYS_ZDO_TASK_) && !defined(ZAPPSI_HOST)
  ZDO_TaskHandler,    // ID 4
#else
  NULL,
#endif

#if defined(_SYS_APS_TASK_) && !defined(ZAPPSI_HOST) && !defined(_MAC2_)
  APS_TaskHandler,    // ID 5
#else
  NULL,
#endif

#if defined(_SYS_ZGP_TASK_)
  ZGP_TaskHandler,    // ID 6
#else
  NULL,
#endif

#if defined(_SYS_SSP_TASK_) && !defined(ZAPPSI_HOST)
  SSP_TaskHandler,    // ID 7
#else
  NULL,
#endif

#if defined(_SYS_TC_TASK_) && !defined(ZAPPSI_HOST)
  TC_TaskHandler,   // ID 8
#else
  NULL,
#endif


#if defined(ZAPPSI_NP) || defined(ZAPPSI_HOST)
  ZSI_TaskHandler,    // ID 9
#else
  NULL,
#endif

#ifdef _ZCL_SUPPORT_ 
  ZCL_TaskHandler,    // ID 10
#else
  NULL,
#endif

#ifdef _SYS_ZLL_TASK_
  ZLL_TaskHandler,    // ID 11
#else
  NULL,
#endif

#if defined(_SYS_APL_TASK_)
  APL_TaskHandler,
#else
  NULL,
#endif

#if defined(_SYS_ZGP_TASK_) && defined(_GREENPOWER_SUPPORT_)
  ZGP_Dstub_TaskHandler,  // ID 13
#else
  NULL,
#endif
};

/******************************************************************************
                             Implementation section
******************************************************************************/

/***************************************************************************//**
\brief Zigbee task initialization routine
*******************************************************************************/
void ZB_SysTaskInit(void)
{
#if defined(_SYS_ZDO_TASK_) && !defined(ZAPPSI_HOST)
  SYS_PostTask(ZDO_TASK_ID); // ZDO task must be started first to initialize the stack
#elif defined(ZAPPSI_HOST)
  SYS_InitZsiMem();
  SYS_PostTask(ZSI_TASK_ID);
#elif defined(_SYS_ZGP_TASK_)
  SYS_PostTask(ZGP_TASK_ID);
#else
  SYS_PostTask(APL_TASK_ID); // If there isn't ZDO e.g. HAL SE target is used
#endif /* _SYS_ZDO_TAKS_ */

#ifdef SIMULATOR
  HAL_MediumStart();
#endif
}


/***************************************************************************//**
\brief Task processing handler
*******************************************************************************/
void SYS_RunTask(void)
{
  uint8_t taskId;

  for (taskId = 0; taskId < (sizeof(taskHandlers) / sizeof(taskHandlers[0])); taskId++)
  {
#if defined(_USE_KF_MAC_)
    wpan_task();
#endif // defined(_USE_KF_MAC_)
    SYS_INFINITY_LOOP_MONITORING
    if ((1 << taskId) & (SYS_taskFlag & SYS_taskMask))
    {
      ATOMIC_SECTION_ENTER
        SYS_taskFlag &= ~(1 << taskId);
      ATOMIC_SECTION_LEAVE

      SYS_E_ASSERT_FATAL(taskHandlers[taskId], SYS_TASKHANDLER_NULLCALLBACK0);
      taskHandlers[taskId]();

      break;
    }
  }
}


/***************************************************************************//**
\brief Task processing handler
*******************************************************************************/
bool SYS_PostIdleTask(void)
{
  SYS_PostEvent(SYS_EVENT_TASK_PROCESSED, 0);
  // enter the mcu's idle mode
  if (0 == SYS_taskFlag)
    SYS_IdleHandler();

  return (SYS_taskFlag != 0);
}

/*****************************************************************************************//**
\brief Checks Zigbee ready to Sleep

\ingroup sys

This is the function to be called / Checked by the application before entering into sleep \c main()
function.

\param none
\return Initialization result
*********************************************************************************************/
bool ZB_ReadyToSleep(void)
{
#if !defined(_MAC2_)
    if (ZDO_IsStackSleeping())
    {
        return true;
    }
    else if(true == ZDO_IsDeviceReadyToSleep())
#endif
    {
        SYS_PostIdleTask();
    }
    return false;
}

/*****************************************************************************************//**
\brief Check Zigbee is Idle or not by the application

\ingroup sys

This is the function to be called by the application before invoking any critical actions( ex: Flash write) in application \c main()
function.

\param none
\return Initialization result
*********************************************************************************************/
bool ZB_IsIdle(void)
{
    if (PHY_ZBIsIdle() && (0 == SYS_taskFlag))
    {
        return true;
    }
    return false;
}
/* eof sysTaskManager.c */
