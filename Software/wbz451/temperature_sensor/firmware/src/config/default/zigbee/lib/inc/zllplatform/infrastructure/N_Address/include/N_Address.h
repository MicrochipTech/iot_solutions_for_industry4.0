/*******************************************************************************
  ZLL Address Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Address.h

  Summary:
    This file contains the ZLL Address functions.

  Description:
    This file contains the ZLL Address functions.
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


#ifndef N_ADDRESS_H
#define N_ADDRESS_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Types/include/N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

typedef uint8_t N_Address_Extended_t[8];

typedef uint8_t N_Address_ExtendedPanId_t[8];

typedef enum N_Address_Mode_t
{
    N_Address_Mode_Binding = 0,
    N_Address_Mode_Group = 1,
    N_Address_Mode_Short = 2,
    N_Address_Mode_Extended = 3,
    N_Address_Mode_Broadcast = 15,
} N_Address_Mode_t;

typedef struct N_Address_t
{
    union
    {
        uint16_t shortAddress;
        N_Address_Extended_t extendedAddress;
    } address;
    N_Address_Mode_t addrMode;
    uint8_t endPoint;
    uint16_t panId; // should typically be zero
} N_Address_t;

/***************************************************************************************************
* EXPORTED MACROS
***************************************************************************************************/

#define N_ADDRESS_INVALID_SHORT_ADDRESS 0xFFFEu
#define N_ADDRESS_INVALID_PAN_ID 0xFFFEu


/***************************************************************************************************
* EXPORTED CONSTANTS
***************************************************************************************************/

extern const N_Address_t c_AddrBinding;
extern const N_Address_t c_Addr64;
extern const N_Address_t c_Addr16;
extern const N_Address_t c_AddrAll;
extern const N_Address_t c_AddrRXON;
extern const N_Address_t c_AddrRoutersOnly;
extern const N_Address_t c_AddrG;

extern const N_Address_ExtendedPanId_t c_ExtPanId00;    // all zeroes
extern const N_Address_ExtendedPanId_t c_ExtPanIdFF;    // all 0xFF's

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/


/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_ADDRESS_H
