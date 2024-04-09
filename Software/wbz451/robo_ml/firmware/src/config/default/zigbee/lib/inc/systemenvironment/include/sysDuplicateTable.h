/*******************************************************************************
  system duplicate table Header File

  Company:
    Microchip Technology Inc.

  File Name:
    sysDuplicateTable.h

  Summary:
    Common interface for BTT, APS Rejection Table and other tables.

  Description:
    Common interface for BTT, APS Rejection Table and other tables.
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

#if !defined _SYS_DUPLICATE_TABLE_H
#define _SYS_DUPLICATE_TABLE_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Enumeration of results of duplicate checking. */
typedef enum _SysDuplicateTableAnswer_t
{
  /** A packet with given sequence number has already been received. */
  SYS_DUPLICATE_TABLE_ANSWER_FOUND,
  /** The received packet is not duplicate and it is added to the table. */
  SYS_DUPLICATE_TABLE_ANSWER_ADDED,
  /** Check can return Full only if removeOldest set to false */
  SYS_DUPLICATE_TABLE_ANSWER_FULL
} SysDuplicateTableAnswer_t;

/** Type of mask to track duplicates. */
typedef uint32_t SYS_DuplicateMask_t;

/** Type of a duplicate rejection entry. */
typedef struct _SYS_DuplicateTableEntry_t
{
  uint16_t address; /*!< Short address of node from which duplicates are tracked. */
  uint8_t seqNumber; /*!< Most recent sequence number which is received from the node. */
  uint8_t ttl; /*!< Current value of time-to-leave. */
#ifdef _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
  /* The mask indicates received packets from particular node. */
  SYS_DuplicateMask_t mask;
#endif // _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
} SYS_DuplicateTableEntry_t;

/* Type of structure which contains internal states of a rejection table. */
typedef struct _SYS_DuplicateTable_t
{
  /** The flag indicates that the oldest entry is removed if the table is full. */
  bool removeOldest:1;
  /* Current size of the table. */
  uint8_t size:7;
  /* A pointer to the duplicate rejection table from configServer. */
  SYS_DuplicateTableEntry_t *entries;
  /* Variable to track timeout and to age out an entry. */
  uint16_t agingPeriod;
  uint32_t lastStamp;
  uint8_t maxTTL;
#ifdef _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
  uint8_t maskSize; /*!<Counter value for duplicate entry. */
#endif // _DUPLICATE_REJECTION_TABLE_BIT_MASK_ENABLE_
} SYS_DuplicateTable_t ;

/******************************************************************************
                             Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Prepare duplicate table to real work.

  \param[in] table - pointer to allocated table
  \param[out] entries - pointer to array of entries
  \param[in] tableSize - count of entries in table
  \param[in] agingPeriod - aging period ms
  \param[in] maxTTL - initial value of TTL.
  \param[in] removeOldest - change behaviour on full table

  \return None.
 ******************************************************************************/
void SYS_DuplicateTableReset(SYS_DuplicateTable_t *table,
    SYS_DuplicateTableEntry_t *entries, uint8_t tableSize,
    uint16_t agingPeriod, uint8_t maxTTL, bool removeOldest,uint8_t maskSize);

/**************************************************************************//**
  \brief Search for record in table, add if not found.

  \param[in] table - pointer to allocated table
  \param[in] address, seqNumber - record to search for or to add if not found

  \return SYS_DUPLICATE_TABLE_ANSWER_FOUND - if duplicate packet is received
          SYS_DUPLICATE_TABLE_ANSWER_ADDED - new packet is received and
                                             information about the packet is added
                                             to the table.
          SYS_DUPLICATE_TABLE_ANSWER_FULL - there is no enough space in the table.
 ******************************************************************************/
SysDuplicateTableAnswer_t SYS_DuplicateTableCheck(SYS_DuplicateTable_t *table,
    uint16_t address, uint8_t seqNumber);

/**************************************************************************//**
  \brief Clear info about given transaction from the rejection table.

  \param[in] table - pointer to allocated table
  \param[in] address, seqNumber - record to search for or to add if not found

  \return None.
 ******************************************************************************/
void SYS_DuplicateTableClear(SYS_DuplicateTable_t *table,
  uint16_t address, uint8_t seqNumber);

/**************************************************************************//**
  \brief Check for record existence in table, returns status

  \param[in] table - pointer to allocated table
  \param[in] address, seqNumber - record to search for or to add if not found

  \return true  - Record exists
          false - Record doesnt exist
 ******************************************************************************/
bool SYS_DuplicateTableEntryExists(SYS_DuplicateTable_t *table,
    uint16_t address, uint8_t seqNumber);

#endif /* _SYS_DUPLICATE_TABLE_H */
/** eof sysDuplicateTable.h */
