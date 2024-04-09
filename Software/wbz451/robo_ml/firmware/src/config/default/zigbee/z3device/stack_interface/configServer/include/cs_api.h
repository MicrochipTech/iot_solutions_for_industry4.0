/*******************************************************************************
   Zigbee Config server APIs Header File

  Company:
    Microchip Technology Inc.

  File Name:
    cs_api.h

  Summary:
    This file contains the Config server api's for this project.

  Description:
    This file contains the packing Config server requests and send them to zigbee stack through SVC
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

#ifndef CS_API_H
#define CS_API_H
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <configserver/include/configserver.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/
#ifdef _PIC32CX_
#define CS_ReadParameter              ZB_CS_ReadParameter
#define CS_WriteParameter             ZB_CS_WriteParameter
#define CS_GetItemSize                ZB_CS_GetItemSize
#define CS_PdsDefaultValue            ZB_CS_PdsDefaultValue
#define CS_Init                       ZB_CS_Init
#endif

/*******************************************************************************
                    Global variables section
*******************************************************************************/

/**************************************************************************//**
\brief ZCL_CommandManagerInit pack function
\param[in] req - request
******************************************************************************/
void ZB_CS_ReadParameter(CS_MemoryItemId_t parameterId, void *memoryPtr);

/**************************************************************************//**
\brief ZCL_RegisterEndpoint pack function
\param[in] endpoint - contains device descriptor
******************************************************************************/
void ZB_CS_WriteParameter(CS_MemoryItemId_t parameterId, const void *parameterValue);

/**************************************************************************//**
\brief CS_PdsDefaultValue pack function
\param[in] void
******************************************************************************/
uint16_t ZB_CS_GetItemSize(CS_MemoryItemId_t itemId);

/**************************************************************************//**
\brief CS_PdsDefaultValue pack function
\param[in] void
******************************************************************************/
void ZB_CS_PdsDefaultValue(void);

/**************************************************************************//**
\brief CS_PdsDefaultValue pack function
\param[in] void
******************************************************************************/
void ZB_CS_Init(void);



#endif // CS_API_H
