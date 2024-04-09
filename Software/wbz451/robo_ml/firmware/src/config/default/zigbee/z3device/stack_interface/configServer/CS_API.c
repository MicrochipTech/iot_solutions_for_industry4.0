/*******************************************************************************
   Zigbee Config server APIs source File

  Company:
    Microchip Technology Inc.

  File Name:
    cs_api.c

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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <framework_defs.h>
#include <z3device/stack_interface/zgb_api.h>
#include <configserver/include/configserver.h>
#include <z3device/stack_interface/configServer/include/CS_Unpack.h>
#include <z3device/stack_interface/configServer/include/cs_api.h>
/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/
CS_ReadParameter_t csReadParameter;
CS_WriteParameter_t csWriteParameter;
static Stack_API_Request_t apiRequest;
/*******************************************************************************
                    Implementation section
*******************************************************************************/
/**************************************************************************//**
\brief CS_ReadParameter pack function
\param[in] parameterId -  the ID of the parameter to be read
\param[out] memoryPtr - a pointer to which the parameter's value is written
******************************************************************************/
void ZB_CS_ReadParameter(CS_MemoryItemId_t parameterId, void *memoryPtr)
{
  csReadParameter.parameterId = parameterId;
  csReadParameter.memoryPtr = memoryPtr;

  apiRequest.unpack_fn = (unpack_ptr)CS_ReadParameter_Unpack;
  apiRequest.parameters = &csReadParameter;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/******************************************************************************//**
\brief CS_WriteParameter Pack function
\param[in] parameterId - the ID of the parameter being written
\param[out] memoryPtr - the pointer to the parameter's new value
******************************************************************************/
void ZB_CS_WriteParameter(CS_MemoryItemId_t parameterId, const void *parameterValue)
{
  csWriteParameter.parameterId = parameterId;
  csWriteParameter.parameterValue = parameterValue;
  
  apiRequest.unpack_fn = (unpack_ptr)CS_WriteParameter_Unpack;
  apiRequest.parameters = &csWriteParameter;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief CS_GetItemSize pack function
\param[in] itemId - item identifier.
\return size of the particular item.
******************************************************************************/
uint16_t ZB_CS_GetItemSize(CS_MemoryItemId_t itemId)
{
  CS_GetItemSize_t zsGetItemSize;
  zsGetItemSize.itemId = itemId;
  
  apiRequest.unpack_fn = (unpack_ptr)CS_GetItemSize_Unpack;
  apiRequest.parameters = &zsGetItemSize;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
  return zsGetItemSize.itemSize;
}

/**************************************************************************//**
\brief CS_PdsDefaultValue pack function
\param[in] void
******************************************************************************/
void ZB_CS_PdsDefaultValue(void)
{
  apiRequest.unpack_fn = (unpack_ptr)CS_PdsDefaultValue_Unpack;
  apiRequest.parameters = NULL;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}

/**************************************************************************//**
\brief CS_Init pack function
\param[in] void
******************************************************************************/
void ZB_CS_Init(void)
{
  apiRequest.unpack_fn = (unpack_ptr)CS_Init_Unpack;
  apiRequest.parameters = NULL;
  ZIGBEE_API_CALL((Stack_API_Request_t *)&apiRequest);
}
/* eof : CS_API.c */
