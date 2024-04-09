// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object permissions table Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoPermissionsTable.h

  Summary:
    This file contains the Internal interface of the permissions configuration table.

  Description:
    This file contains the Internal interface of the permissions configuration table.
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
#if !defined _ZDO_PERMISSIONS_TABLE_H
#define _ZDO_PERMISSIONS_TABLE_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/zdoPermissions.h>

#if defined _PERMISSIONS_
/******************************************************************************
                                Types section
 ******************************************************************************/
/** Type of a record of the permissions configuration table. */
typedef struct _ZdoPermissionsRecord_t
{
  /** If the record is used (some information was saved) then the field is 'true'
   * otherwise 'false' and it means the record can be reused. */
  bool busy;
  /** Current permissions which are associated the device. */
  ZDO_Permissions_t permissions;
  /** IEEE address of the device whose permissions are stored in the record. */
  ExtAddr_t deviceAddress;
} ZdoPermissionsRecord_t;

/** Type of the permissions table size. */
typedef uint8_t ZdoPermissionsTableSize_t;
/** Type of index to iterate the permissions table. */
typedef ZdoPermissionsTableSize_t ZdoPermissionsIndex_t;

typedef struct _ZdoPermissions_t
{
  /** Permissions that will be applied by default to a device which doesn't have
   * its record in the table. */
  ZDO_Permissions_t defaultPermissions;  
  /** The pointer to the permissions table. The field must be initialized in
   * the zdoResetPermissions function. */
  ZdoPermissionsRecord_t *table;  
  /** Current size of the permissions table. It must be initialized with the 
   * table field. If the table field is NULL then this field must be 0. */
  ZdoPermissionsTableSize_t tableSize;
} ZdoPermissions_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Reloads and reinits the permissions configuration table.

  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoResetPermissions(void);

#endif /* _PERMISSIONS_ */
#endif /* _ZDO_PERMISSIONS_TABLE_H */
/** zdoPermissionsTable.h */
