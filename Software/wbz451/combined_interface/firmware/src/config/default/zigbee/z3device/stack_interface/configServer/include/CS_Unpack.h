/*******************************************************************************
  Config Server Unpack Header File

  Company:
    Microchip Technology Inc.

  File Name:
    CS_Unpack.h

  Summary:
    Unpack the CS requests and calls corresponding CS API.

  Description:
    This file contains declaration for CS Unpack requests and calls corresponding CS API.
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


/*******************************************************************************
                             Includes section
*******************************************************************************/
#include <framework_defs.h>
#include <z3device/stack_interface/zgb_api.h>
#include <configserver/include/configserver.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
/*************************************************************************//**
  \brief CS_ReadParameter() API parameters
*****************************************************************************/
typedef struct _CS_ReadParameter
{
  CS_MemoryItemId_t parameterId;
  void *memoryPtr;
} CS_ReadParameter_t;

/*************************************************************************//**
  \brief CS_WriteParameter() API parameters
*****************************************************************************/
typedef struct _CS_WriteParameter
{
  CS_MemoryItemId_t parameterId;
  const void *parameterValue;
} CS_WriteParameter_t;

typedef struct _CS_GetItemSize
{
  CS_MemoryItemId_t itemId;
  uint16_t itemSize;
} CS_GetItemSize_t;

/*******************************************************************************
                    Global variables section
*******************************************************************************/

/**************************************************************************//**
\brief CS_ReadParameter Unpack function
\param[in] req - request
******************************************************************************/
void CS_ReadParameter_Unpack(void *req);

/**************************************************************************//**
\brief CS_WriteParameter Unpack function
\param[in] req - request
******************************************************************************/
void CS_WriteParameter_Unpack(void *req);

/**************************************************************************//**
\brief CS_PdsDefaultValue Unpack function
\param[in] req - request
******************************************************************************/
void CS_PdsDefaultValue_Unpack(void *req);

/**************************************************************************//**
\brief CS_GetItemSize Unpack function
\param[in] req - request
******************************************************************************/
void CS_GetItemSize_Unpack(void *req);

/**************************************************************************//**
\brief CS_Init Unpack function
\param[in] req - request
******************************************************************************/
void CS_Init_Unpack(void *req);

