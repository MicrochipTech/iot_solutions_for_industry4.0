/*******************************************************************************
  System mutex Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysMutex.c

  Summary:
    Implementation of system asynchronous mutex.

  Description:
    Implementation of system asynchronous mutex.
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
#include <systemenvironment/include/sysMutex.h>
#include <systemenvironment/include/sysDbg.h>
#include <systemenvironment/include/sysUtils.h>
#include <systemenvironment/include/sysAssert.h>

/******************************************************************************
                            Implementations section
 ******************************************************************************/
/**************************************************************************//**
  \brief Puts owner's structure to the mutex queue.

  \param[in] mutex - the pointer to a mutex.
  \param[in] owner - the pointer to owner's structure. Memory for this structure
                     is allocated by the owner. Memory can't be reused by owner
                     the mutex is locked by the owner.

  \return true - the locking operation finishes successfuly otherwise
          false - the operation was postponed. The SYS_MutexLockConf() will be
          called when the mutex is locked for this owner.
 ******************************************************************************/
bool SYS_MutexLock(SYS_Mutex_t *const mutex, SYS_MutexOwner_t *const owner)
{
  const bool isUnlocked = (NULL == getQueueElem(mutex));

  SYS_E_ASSERT_FATAL(((NULL != mutex) && (NULL != owner)), SYSMUTEX_MUTEXLOCK0);
  putQueueElem(mutex, &owner->service.qelem);

  return isUnlocked;
}

/**************************************************************************//**
  \brief Unlocks a mutex using synchronous request.

  \param[in] mutex - the pointer to a locked mutex.
  \param[in] owner - the pointer to owner's structure. Memory for this structure
                     can be reused after this operation.

  \return true - the locking operation finishes successfuly otherwise
          false - the mutex is not locked by the owner.
 ******************************************************************************/
bool SYS_MutexUnlock(SYS_Mutex_t *const mutex, SYS_MutexOwner_t *const owner)
{
  QueueElement_t *qelem;
  SYS_MutexOwner_t *currentOwner;

  SYS_E_ASSERT_FATAL(((NULL != mutex) && (NULL != owner)), SYSMUTEX_MUTEXUNLOCK0);

  qelem = getQueueElem(mutex);
  if (NULL == qelem)
  {
    SYS_E_ASSERT_FATAL(false, SYSMUTEX_MUTEXUNLOCK1);
    return false;
  }

  currentOwner = GET_PARENT_BY_FIELD(SYS_MutexOwner_t, service.qelem, qelem);
  if (owner != currentOwner)
  {
    SYS_E_ASSERT_FATAL(false, SYSMUTEX_MUTEXUNLOCK2);
    return false;
  }
  else
    deleteHeadQueueElem(mutex);

  qelem = getQueueElem(mutex);
  if (NULL != qelem)
  {
    currentOwner = GET_PARENT_BY_FIELD(SYS_MutexOwner_t, service.qelem, qelem);
    SYS_E_ASSERT_FATAL(currentOwner->SYS_MutexLockConf, SYSMUTEX_MUTEXUNLOCK3);
    currentOwner->SYS_MutexLockConf(mutex, currentOwner->context);
  }

  return true;
}

/**************************************************************************//**
  \brief Checks whether mutex is locked.

  \ingroup sys

  \param[in] mutex - the pointer to a locked mutex.
  \param[in] owner - the pointer to owner's structure. Memory for this structure
                     can be reused after this operation.

  \return true - the mutex is locked by the owner,
          false - the mutex is not locked by the owner.
 ******************************************************************************/
bool SYS_IsMutexLocked(SYS_Mutex_t *const mutex, SYS_MutexOwner_t *const owner)
{
  SYS_E_ASSERT_FATAL(((NULL != mutex) && (NULL != owner)), SYSMUTEX_ISMUTEXLOCKED0);

  return isQueueElem(mutex, &owner->service.qelem);
}

/** eof sysMutex.c */
