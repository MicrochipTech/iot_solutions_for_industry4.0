/*******************************************************************************
  Config Server Unpack Source File

  Company:
    Microchip Technology Inc.

  File Name:
    CS_Unpack.c

  Summary:
    Unpack the CS requests and calls corresponding CS API..

  Description:
    Unpack the CS requests and calls corresponding CS API..
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
#include <z3device/stack_interface/configServer/include/CS_Unpack.h>

/******************************************************************************
                    Definitions section
*******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/

/*******************************************************************************
                    Static functions section
*******************************************************************************/

/*******************************************************************************
                    Global variables section
*******************************************************************************/

/*******************************************************************************
                    Implementation section
*******************************************************************************/

/**************************************************************************//**
\brief CS_ReadParameter Unpack function
\param[in] req - request
******************************************************************************/
void CS_ReadParameter_Unpack(void *req)
{
   CS_ReadParameter_t* csReadParameter = (CS_ReadParameter_t* )req;
   CS_ReadParameter(csReadParameter->parameterId, csReadParameter->memoryPtr);
}

/**************************************************************************//**
\brief CS_WriteParameter Unpack function
\param[in] req - request
******************************************************************************/
void CS_WriteParameter_Unpack(void *req)
{
  CS_WriteParameter_t* csWriteParamter = (CS_WriteParameter_t*)req;
  CS_WriteParameter(csWriteParamter->parameterId, csWriteParamter->parameterValue);
}

/**************************************************************************//**
\brief CS_PdsDefaultValue Unpack function
\param[in] req - request
******************************************************************************/
void CS_PdsDefaultValue_Unpack(void *req)
{
  (void)req;
  CS_PdsDefaultValue();
}

/**************************************************************************//**
\brief CS_GetItemSize Unpack function
\param[in] req - request
******************************************************************************/
void CS_GetItemSize_Unpack(void *req)
{
  CS_GetItemSize_t* zsGetItemSize = (CS_GetItemSize_t*)req;
  zsGetItemSize->itemSize = CS_GetItemSize(zsGetItemSize->itemId);
}

/**************************************************************************//**
\brief CS_Init Unpack function
\param[in] req - request
******************************************************************************/
void CS_Init_Unpack(void *req)
{
  (void)req;
  //CS_Init(); // Mostly will be a direct call.
}
