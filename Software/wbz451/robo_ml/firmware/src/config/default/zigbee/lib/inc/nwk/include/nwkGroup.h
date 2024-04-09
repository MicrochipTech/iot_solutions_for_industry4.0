// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Group Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkGroup.h

  Summary:
    This file contains the interface of the NWK group table.

  Description:
    This file provides access to the NWK group table and its related parameters.
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
#if !defined _NWK_GROUP_H
#define _NWK_GROUP_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/appFramework.h>
#include <nwk/include/nlmeReset.h>


/******************************************************************************
                               Definitions section
 ******************************************************************************/
/** Value that can not be used as a group data parameter. */
#define NWK_INVALID_GROUP_DATA 0x00U
/** Universal group data. It means any group data value. */
#define NWK_ANY_GROUP_DATA 0xFFU

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of data linked to group. */
typedef uint8_t NWK_GroupData_t;
/** Type of group address. */
typedef GroupAddr_t NWK_GroupAddr_t;

/** Type of group table entry. */
typedef struct _NWK_GroupTableEntry_t
{
  /** The data used by user, for example APS end point. */
  NWK_GroupData_t data;
  /** Address of group. */
  NWK_GroupAddr_t addr;
} NWK_GroupTableEntry_t;

/** Type of size of the group table.*/
typedef uint8_t NWK_GroupTableSize_t;

/** Type of internal variables of group component. */
typedef struct _NWK_GroupTable_t
{
  /** Pointer to first entry of the group table. */
  NWK_GroupTableEntry_t *begin;
  /** Pointer to memory after last entry of the group table. */
  NWK_GroupTableEntry_t *end;
} NWK_GroupTable_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
#if defined _GROUP_TABLE_
/**************************************************************************//**
  \brief Add new entry to the group table.

  \param addr - address of group. Valid range 0x0000 - 0xffff.
         data - value linked to group. Valid range 0x01 - 0xfe.

  \return 'true' if entry is added successfully otherwise 'false'.
 ******************************************************************************/
bool NWK_AddGroup(const NWK_GroupAddr_t addr, const NWK_GroupData_t data);

/**************************************************************************//**
  \brief Remove group entries from the group table.

  \param addr - address of group. Valid range 0x0000 - 0xffff.
         data - value linked to group. Valid range 0x01 - 0xff.
                    If data is equal to NWK_ANY_GROUP_DATA then remove
                    all entries with given group address.

  \return 'true' if any entry is removed successfully otherwise 'false'.
 ******************************************************************************/
bool NWK_RemoveGroup(const NWK_GroupAddr_t addr, const NWK_GroupData_t data);

/**************************************************************************//**
  \brief Remove all group entries with given group data

  \param data - value linked to group. Valid range 0x01 - 0xff.
                    If data is equal to NWK_ANY_GROUP_DATA then remove
                    all entries from table.

  \return 'true' if any entry is removed successfully otherwise 'false'.
 ******************************************************************************/
bool NWK_RemoveAllGroups(const NWK_GroupData_t data);

/**************************************************************************//**
  \brief Check group address and data in the group table.

  \param addr - address of group. Valid range 0x0000 - 0xffff.
         data - value linked to group. Valid range 0x01 - 0xff.
                    If data is equal to NWK_ANY_GROUP_DATA that means
                    any enties with given group address.

  \return 'true' if pair addr and data is found in the group table
           otherwise 'false'.
 ******************************************************************************/
bool NWK_IsGroupMember(const NWK_GroupAddr_t addr, const NWK_GroupData_t data);

/**************************************************************************//**
  \brief Get remaining groups capacity.

  \return number of free entries in the group table.
 ******************************************************************************/
NWK_GroupTableSize_t NWK_GroupCapacity(void);

/**************************************************************************//**
  \brief Get first or next non-free entry from the groups table.

  \param entry - address of the current entry or NULL to get the first entry.

  \return pointer to the next non-free entry or NULL if no more entries exist.
 ******************************************************************************/
NWK_GroupTableEntry_t* NWK_NextGroup(NWK_GroupTableEntry_t *entry);

/**************************************************************************//**
  \brief Allocate and initialize the group table.
 ******************************************************************************/
void NWK_ResetGroups(void);

#else
#define NWK_ResetGroups() (void)0
#endif /* _GROUP_TABLE_ */
#endif /* _NWK_GROUP_H */
/** eof nwkGroup.h */

