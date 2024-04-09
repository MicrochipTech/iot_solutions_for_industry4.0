// DOM-IGNORE-BEGIN
/*******************************************************************************
  Bitcloud PDS Header File

  Company:
    Microchip Technology Inc.

  File Name:
    bcPDS.h

  Summary:
    This file contains Bitcloud specific PDS related function declarations.

  Description:
    This file contains Bitcloud specific PDS related function declarations.
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
#ifndef _bcPDS_H
#define _bcPDS_H
// DOM-IGNORE-END

#ifdef _ENABLE_PERSISTENT_SERVER_
/******************************************************************************
                        Functions' prototypes section.
 ******************************************************************************/
void ZB_PDS_Init (void);

/**************************************************************************//**
  \brief Provides PDS with information about memory that should be kept up-to-datenin the non-volatile storage.

  ingroup pds

  Data will be saved im non-volatile memory upon specific events.

  \param memoryId - an identifier of PDS file or directory to be stored
                    in non-volatile memory.
  \return None
 ******************************************************************************/
void PDS_StoreByEvents(PDS_MemId_t memoryId);

#endif //_bcPDS_H
#endif 
// eof sspReset.h
