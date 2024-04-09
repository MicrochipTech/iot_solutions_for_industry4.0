
/*******************************************************************************
  Application errors Header File

  Company:
    Microchip Technology Inc.

  File Name:
    errH.h

  Summary:
    This file contains the declarations for proccesing Errors  

  Description:
    This file contains the declarations for proccesing Errors 
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

#ifndef ERRH_H
#define ERRH_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zllplatform/infrastructure/N_ErrH/include/N_ErrH.h>
#include <app_zigbee/zigbee_console/console.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#define ERROR_HANDLERS_MAX_AMOUNT 5u

/******************************************************************************
                    Prototypes section
******************************************************************************/
void errHFatal(const char *compId, uint16_t line);

/******************************************************************************
                    Types section
******************************************************************************/
typedef void (*ErrorAbortCb_t)(const char *compId, uint16_t line);

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes errH module
******************************************************************************/
void errHInit(void);

/**************************************************************************//**
\brief Subscribes for fatal error

\param[in] handler - callback function which is called is case of error
******************************************************************************/
void errHSubscribeForFatal(ErrorAbortCb_t handler);

#endif // ERRH_H
/* eof errH.h */
