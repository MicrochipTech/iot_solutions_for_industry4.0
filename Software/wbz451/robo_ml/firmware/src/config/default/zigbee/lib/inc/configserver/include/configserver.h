// DOM-IGNORE-BEGIN
/*******************************************************************************
  ConfigServer Header File

  Company
    Microchip Technology Inc.

  File Name
    configServer.h

  Summary
    This file provides the Interface to Configuration Server parameters.

  Description
    This header file manages the configuration server parameters.
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
#ifndef _CONFIG_SERVER_H
#define _CONFIG_SERVER_H
// DOM-IGNORE-END

/******************************************************************************
                    Includes section
 ******************************************************************************/
 
#include <systemenvironment/include/sysTypes.h>
#include <configserver/include/csDefaults.h>

/******************************************************************************
                              Define(s) section
 ******************************************************************************/
 
#define CS_ID_MASK 0xFF
#define CS_TYPE_MASK 0xFF00
#define CS_RAM_PARAM_TYPE   0x0000
#define CS_FLASH_PARAM_TYPE 0x0100
#define CS_MEM_PARAM_TYPE   0x0200

#define RAM_PARAM_ID(n)    (CS_RAM_PARAM_TYPE + n)
#define FLASH_PARAM_ID(n)  (CS_FLASH_PARAM_TYPE + n)
#define MEM_PARAM_ID(n)    (CS_MEM_PARAM_TYPE + n)

#define RAM_PARAMETER(label, id, addr) label = RAM_PARAM_ID(id),
#define DUMMY_RAM_PARAMETER(label, id) label = RAM_PARAM_ID(id),
#define FLASH_PARAMETER(label, id, addr) label = FLASH_PARAM_ID(id),
#define DUMMY_FLASH_PARAMETER(label, id) label = FLASH_PARAM_ID(id),
#define MEMORY_REGION(label, id, addr) label = MEM_PARAM_ID(id),
#define DUMMY_MEMORY_REGION(label, id) label = MEM_PARAM_ID(id),

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** List of the Configuration Server parameter identifiers.
   Identifiers are automatically sorted by memory location
   and item types (atomic parameter or memory region).
   The parameters themselves are defined in the csDefaults.h file.
   Parameter ID's name is got by adding "_ID" to the name of a parameter. */
typedef enum _CS_MemoryItemId_t
{
#include "configserver/include/private/csVarTable.h"
#include "configserver/include/private/csConstTable.h"
#include "configserver/include/private/csMemTable.h"
} CS_MemoryItemId_t;

#undef RAM_PARAMETER
#undef DUMMY_RAM_PARAMETER
#undef FLASH_PARAMETER
#undef DUMMY_FLASH_PARAMETER
#undef MEMORY_REGION
#undef DUMMY_MEMORY_REGION

/******************************************************************************
                    Defines section
 ******************************************************************************/
 
#define CS_MAX_PARAMETER_SIZE sizeof(UserDescriptor_t)

/******************************************************************************
                    Functions prototypes section
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
// DOM-IGNORE-END

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
 
/*********************************************//**
  \brief Configuration Server initialization
  \param zgbIBdata - IB data
  \return None
 ******************************************************************************/
void CS_Init(ZB_CS_SYS_IBData_t *zgbIBdata);

/******************************************************************************//**
  \brief Gets the value of the parameter specified by its ID and writes it to the provided address in memory

  The function reads the value of a ConfigServer parameter specified by its ID. A parameter ID is a constant
  which name can be obtained by adding "_ID" suffix to the name of the parameter. For example, the identifier
  of the CS_NWK_PANID parameter is CS_NWK_PANID_ID.

  The function copies the value to the location in memory specified by the second argument.

  For example, reading the extended address of the device is performed this way:

  \code
  ExtAddr_t ownExtAddr;
  CS_ReadParameter(CS_UID_ID, &ownExtAddr);
  \endcode

  \param[in] parameterId -  the ID of the parameter to be read
        [out] memoryPtr - a pointer to which the parameter's value is written
  \return None
 ******************************************************************************/
void CS_ReadParameter(CS_MemoryItemId_t parameterId, void *memoryPtr);

/******************************************************************************//**
  \brief Sets a value of a certain Configuration Server parameter specified by its ID

   The function assigns a new value to the specified Configuration Server parameter.
   The value is copied from the addres specified by the second argument. The first  pargument is the
   parameter's identifier formed by adding "_ID" suffix to the parameter's name. For example,
   a specific value may be set to own extended address in the following way:

   \code
   ExtAddr_t ownExtAddr = 0x0123456789ABCDEF;
   CS_WriteParameter(CS_UID_ID, &ownExtAddr);
   \endcode

   \param[in] parameterId - the ID of the parameter being written
         [out] memoryPtr - the pointer to the parameter's new value
   \return None
 ******************************************************************************/
void CS_WriteParameter(CS_MemoryItemId_t parameterId, const void *parameterValue);

/***********************************************************************************//**
  \brief Gets a pointer to the memory allocated for a specific internal structure

  The function is used to obtain a pointer to the memory identified by a special value. The memory
  is allocated by the stack for certain internal buffers and tables. For example, this function can be
  employed to get the contents of bidning and routing tables, APS key-pair set, and other tables.

  For some of these objects there is the API in BitCloud; the application must use such API rather than
  this function to access the contents of a buffer. In case the API is absent the application may use
  this function to observe the memory occupied by the buffer but is restricted to use the pointer
  obtained with the function to write data to the memory, or the memory may become corrupted.

  The function should be provided with an address of a pointer variable which will be assigned to
  the starting point of the memory.

  \param[in] memoryId - and ID of a parameter or a specific part of the memory
        [out] memoryPtr - a pointer to which a starting address of the memory is written
  \return None

 ***************************************************************************************/
void CS_GetMemory(CS_MemoryItemId_t memoryId, void **memoryPtr);

/**************************************************************************//**
  \brief Set persist default values
  
  \param None
  
  \return None
 *****************************************************************************/
void CS_PdsDefaultValue(void);

/******************************************************************************
  \brief Returns size of the particular item.

  \param itemId - item identifier.

  \return size of the particular item.
 ******************************************************************************/
uint16_t CS_GetItemSize(CS_MemoryItemId_t itemId);
/******************************************************************************
  \brief Backing up Network parameters
******************************************************************************/
void CS_BackupNwkParams(void);
/******************************************************************************
  \brief Restoring Network parameters
 ******************************************************************************/
void  CS_RestoreNwkParams(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CONFIG_SERVER_H */
/* eof configServer.h */
