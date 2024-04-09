/*******************************************************************************
 Framework Defines Header File

  File Name:
    framework_defs.h

  Summary:

  Description:

  Remarks:
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2022 Microchip Technology Inc. and its subsidiaries.
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

#ifndef FRAMEWORK_DEFS_H
#define FRAMEWORK_DEFS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "osal/osal_freertos_extend.h"

typedef struct
{
    OSAL_CRITSECT_DATA_TYPE(*OSAL_CRIT_Enter)(OSAL_CRIT_TYPE);
    void (*OSAL_CRIT_Leave)(OSAL_CRIT_TYPE, OSAL_CRITSECT_DATA_TYPE);

    OSAL_RESULT(*OSAL_SEM_Create)(OSAL_SEM_HANDLE_TYPE *, OSAL_SEM_TYPE, uint8_t, uint8_t);
    OSAL_RESULT(*OSAL_SEM_Pend)(OSAL_SEM_HANDLE_TYPE *, uint32_t);
    OSAL_RESULT(*OSAL_SEM_Post)(OSAL_SEM_HANDLE_TYPE *);
    OSAL_RESULT(*OSAL_SEM_PostISR)(OSAL_SEM_HANDLE_TYPE *);
    uint8_t(*OSAL_SEM_GetCount)(OSAL_SEM_HANDLE_TYPE *);

    OSAL_RESULT(*OSAL_QUEUE_Create)(OSAL_QUEUE_HANDLE_TYPE *, uint32_t, uint32_t);
    OSAL_RESULT(*OSAL_QUEUE_Send)(OSAL_QUEUE_HANDLE_TYPE *, void *, uint32_t);
    OSAL_RESULT(*OSAL_QUEUE_SendISR)(OSAL_QUEUE_HANDLE_TYPE *, void *);
    OSAL_RESULT(*OSAL_QUEUE_Receive)(OSAL_QUEUE_HANDLE_TYPE *, void *, uint32_t);
    OSAL_RESULT(*OSAL_QUEUE_IsFullISR)(OSAL_QUEUE_HANDLE_TYPE *);

    OSAL_RESULT(*OSAL_QUEUE_CreateSet)(OSAL_QUEUE_SET_HANDLE_TYPE *, uint32_t);
    OSAL_RESULT(*OSAL_QUEUE_AddToSet)(OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE *, OSAL_QUEUE_SET_HANDLE_TYPE *);
    OSAL_RESULT(*OSAL_QUEUE_SelectFromSet)(OSAL_QUEUE_SET_MEMBER_HANDLE_TYPE *, OSAL_QUEUE_SET_HANDLE_TYPE *, uint32_t);
    
    void* (*OSAL_MemAlloc)(size_t size);
    void  (*OSAL_MemFree)(void* );

} OSAL_API_LIST_TYPE;

typedef void (*unpack_fn_t)(void *);

typedef struct
{
    unpack_fn_t unpack_fn;
} Request;

typedef struct
{
    uint32_t operation;
} Response;

typedef void (*app_cb_t)(Response *);

#endif // FRAMEWORK_DEFS_H
