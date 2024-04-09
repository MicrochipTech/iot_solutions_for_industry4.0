// DOM-IGNORE-BEGIN
/*******************************************************************************
  BDB InstallCode Header File

  Company
    Microchip Technology Inc.

  File Name
    bdbInstallCode.h

  Summary
    bdb Install Code interface.

  Description
    This header file provides access to the API to configure the Install code in
    a Zigbee Device.
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
#ifndef _BDB_INSTALLCODE_H
#define _BDB_INSTALLCODE_H
// DOM-IGNORE-END

/********************************************************************************                          INCLUDE FILES
 ******************************************************************************/
 
#include <mac_phy/include/macAddr.h>

/******************************************************************************
                    Types section
 ******************************************************************************/
 
typedef enum InstallCode_Configuration_Status_t
{
    /** The action succeeded. */
    IC_CONFIG_SUCCESS,

    /** The input install code has invalid crc. */
    IC_CONFIG_INVALID_CRC,

    /** The action failed. */
    IC_CONFIG_FAILED,
} InstallCode_Configuration_Status_t;

typedef void (*IcStatusCallback_t)(InstallCode_Configuration_Status_t status);

/******************************************************************************
                    Prototypes section
 ******************************************************************************/

/**************************************************************************//**
  \brief bdb Public API to configure Install Code
   This API calculates the CRC for the install code and compare with the given CRC
   Derives the link key using SSP AES and sets the key in APS Key Pair Set     

  \param deviceAddress - set to 0xffffffff in device or ext addr of the    joining device
             installCode - pointer which holds the install code to be derived
             pfCallback - callback function to be called once the operation is finished
             
  \return None
 ******************************************************************************/
void BDB_ConfigureInstallCode(ExtAddr_t deviceAddress, uint8_t *installCode, IcStatusCallback_t pfCallback);

#endif // _BDB_INSTALLCODE_H