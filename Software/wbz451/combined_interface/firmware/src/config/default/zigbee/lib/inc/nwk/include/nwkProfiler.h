// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Profiler Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkProfiler.h

  Summary:
    This file contains the Interface of NWK Profiler.

  Description:
    This file contains the prototypes and constants of NWK Profiler.
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
#if !defined _NWK_PROFILER_H
#define _NWK_PROFILER_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

#if defined _PROFILER_
/******************************************************************************
                                Types section
 ******************************************************************************/
/* NWK Profiling information. */
BEGIN_PACK
typedef struct PACK _NWK_ProfilingInfo_t
{
  /** Maximum number of simultaneous join transaction. */
  uint8_t maxJoinTrans;
  /** Current number of processing join requests. */
  uint8_t incomingJoinReq;
  /** Current number of pending buffer for join response command. */
  uint8_t pendingJoinRespBuffers;
  /** Total NWK buffers. */
  uint8_t nwkBuffersAmount;
  /** Current number of busy output command buffers. */
  uint8_t outCmdBuffers;
  /** Total number of passive acks. */
  uint8_t passiveAckAmount;
  /** Used passive acks amount. */
  uint8_t usedPassiveAcks;
} NWK_ProfilingInfo_t;
END_PACK

/******************************************************************************
                           Global variables section
 ******************************************************************************/
extern NWK_ProfilingInfo_t nwkProfilingInfo;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Collect profiling information and update nwkProfInfo.
 ******************************************************************************/
void NWK_CollectProfilingInfo(void);

#endif /* _PROFILER_ */
#endif /* _NWK_PROFILER_H */
/** eof nwkProfiler.h */

