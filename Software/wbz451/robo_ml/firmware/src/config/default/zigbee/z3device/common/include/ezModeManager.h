/*******************************************************************************
  EZ Mode Manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ezModeManager.h

  Summary:
    This file contains EZ-Mode interface declaration.

  Description:
    This file contains EZ-Mode interface declaration.
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

#ifndef _EZMODEMANAGER_H
#define _EZMODEMANAGER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes EZ-Mode manager

\param[in] isInitiator - should be set to true is device acts as an initiator
  of EZ-Mode, to false otherwise
******************************************************************************/
void initEzModeManager(bool isInitiator);

/**************************************************************************//**
\brief Starts EZ-Mode

\param[in] cb - callback which is called when EZ+Mode is finished
******************************************************************************/
void invokeEzMode(void (*cb)(void));

/**************************************************************************//**
\brief Checks whether EZ-Mode commissioning is in progress

\returns true if it is, false otherwise
******************************************************************************/
bool isEzModeInProgress(void);

/**************************************************************************//**
\brief resets ezmodeInProgress state
******************************************************************************/
void resetEzModeInProgress(void);
#endif // _EZMODEMANAGER_H

// eof ezModeManager.h
