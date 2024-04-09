/*******************************************************************************
  MAC memory Header File

  Company:
    Microchip Technology Inc.

  File Name:
    macMem.h

  Summary:
    This file provides a interface to the MAC memory.

  Description:
    This file provides a interface to the MAC memory.
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

#ifndef _MACMEM_H
#define _MACMEM_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <mac_phy/mac_hwi/include/machwiMem.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/MAC_HWD/include/machwdMem.h>
#include <mac_phy/mac_env/include/macenvMem.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyMem.h>

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  MachwiMem_t hwi;
  MachwdMem_t hwd;
  PhyMem_t    phy;
} MAC_Mem_t;

/******************************************************************************
                    Prototypes section
******************************************************************************/

#endif /*_MACMEM_H*/

// eof macMem.h
