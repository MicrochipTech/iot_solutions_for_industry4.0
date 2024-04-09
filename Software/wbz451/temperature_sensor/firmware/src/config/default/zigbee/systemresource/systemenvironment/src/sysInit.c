/*******************************************************************************
  System initialization Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysInit.c

  Summary:
    Stack initialization implementation.

  Description:
    Stack initialization implementation.
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
#include <systemenvironment/include/sysInit.h>
#ifdef _ZCL_SUPPORT_ 
  #include <zcl/include/zcl.h>
#endif // ZCL_SUPPORT == 1
#if defined(ZAPPSI_NP) || defined(ZAPPSI_HOST)
  #include <zsiInit.h>
  #include <zsiMem.h>
#endif // ZAPPSI_NP || ZAPPSI_HOST
/******************************************************************************
                   Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Wrapper to initializes ZSI layer.
******************************************************************************/
void SYS_InitZsiLayer(void)
{
#if defined(ZAPPSI_NP) || defined(ZAPPSI_HOST)
  ZSI_Init();
#endif // ZAPPSI_NP || ZAPPSI_HOST
  sysStartUpdatingRandSeed();
}

/**************************************************************************//**
\brief Wrapper to initialize ZCL layer.
******************************************************************************/
void SYS_InitZclLayer(void)
{
#ifdef _ZCL_SUPPORT_ 
  ZCL_ResetReq();
#endif
}

/**************************************************************************//**
\brief Wrapper to initialize zsiMem to execute ZsiInit layer.
******************************************************************************/
void SYS_InitZsiMem(void)
{
#if defined(ZAPPSI_HOST)
  zsiMem.taskManager.pendingTasks = (1U << ZSI_INIT_TASK_ID);
#endif /* ZAPPSI_HOST */
}

#if defined (__GNUC__) && (defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A))

#include <systemenvironment/include/sys/types.h>
#include <systemenvironment/include/sys/stat.h>

extern uint8_t __end;

extern inline caddr_t _sbrk(int incr);

extern inline caddr_t _sbrk(int incr)
{
  static unsigned char *heap = NULL;
  unsigned char *prev_heap;

  if (heap == NULL) 
  {
    heap = (unsigned char *)&__end;
  }
  prev_heap = heap;
  heap += incr;

  return (caddr_t) prev_heap;
}
#endif /*(__GNUC__) && (defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A))*/
/* (defined(AT91SAM7X256) || defined(AT91SAM3S4C) || defined(ATSAMR21G18A) || defined(ATSAMR21E18A) || defined(ATSAMR21E19A)) */

//eof sysInit.c

