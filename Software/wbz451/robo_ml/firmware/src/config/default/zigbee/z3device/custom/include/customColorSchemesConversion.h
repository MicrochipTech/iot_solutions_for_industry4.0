/*******************************************************************************
  Custom ColorControl Schemes Conversion Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customColorSchemesConversion.h

  Summary:
    This file contains the Custom ColorControl Schemes Conversion interface.

  Description:
    This file contains the Custom ColorControl Schemes Conversion interface.
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

#ifndef _CUSTOMCOLORSCHEMESCONVERTION_H
#define _CUSTOMCOLORSCHEMESCONVERTION_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Converts color temperature to appropriate XY coordinates

\param[in] temperature - color temperature (attribute value);
\param[out] x          - x coordinate (attribute value);
\param[out] y          - y coordinate (attribute value)
******************************************************************************/
void customConvertColorToXY(uint16_t temperature, uint16_t *x, uint16_t *y);

/**************************************************************************//**
\brief Converts XY coordinates to appropriate color temperature

\param[in] x - x coordinate (attribute value);
\param[in] y - y coordinate (attribute value)

\returns color temperature (attribute value)
******************************************************************************/
uint16_t customConvertXYToColor(uint16_t x, uint16_t y);

#endif // _CUSTOMCOLORSCHEMESCONVERTION_H

// eof customColorSchemesConversion.h

