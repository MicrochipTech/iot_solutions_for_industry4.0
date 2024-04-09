/*******************************************************************************
  Custom Color Scenes Conversion Source File

  Company:
    Microchip Technology Inc.

  File Name:
    customColorSchemesConversion.c

  Summary:
    This file contains the Custom Color Scenes Conversion implementation.

  Description:
    This file contains the Custom Color Scenes Conversion implementation.
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_CUSTOM_DEVICE)

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/custom/include/customColorSchemesConversion.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#define TEMPERATURE_TO_X_TEMPERATURE_TRESHOLD           4000

#define TEMPERATURE_TO_Y_FIRST_TEMPERATURE_TRESHOLD     2222
#define TEMPERATURE_TO_Y_SECOND_TEMPERATURE_TRESHOLD    4000

#define TEMPERATURE_TO_X_FIRST_FACTOR_FIRST_EQUATION    17440695910400
#define TEMPERATURE_TO_X_SECOND_FACTOR_FIRST_EQUATION   15358885888
#define TEMPERATURE_TO_X_THIRD_FACTOR_FIRST_EQUATION    57520658
#define TEMPERATURE_TO_X_FOURTH_FACTOR_FIRST_EQUATION   11790

#define TEMPERATURE_TO_X_FIRST_FACTOR_SECOND_EQUATION   198301902438400
#define TEMPERATURE_TO_X_SECOND_FACTOR_SECOND_EQUATION  138086835814
#define TEMPERATURE_TO_X_THIRD_FACTOR_SECOND_EQUATION   14590587
#define TEMPERATURE_TO_X_FOURTH_FACTOR_SECOND_EQUATION  15754

#define TEMPERATURE_TO_Y_FIRST_FACTOR_FIRST_EQUATION    18126
#define TEMPERATURE_TO_Y_SECOND_FACTOR_FIRST_EQUATION   22087
#define TEMPERATURE_TO_Y_THIRD_FACTOR_FIRST_EQUATION    35808
#define TEMPERATURE_TO_Y_FOURTH_FACTOR_FIRST_EQUATION   3312

#define TEMPERATURE_TO_Y_FIRST_FACTOR_SECOND_EQUATION   15645
#define TEMPERATURE_TO_Y_SECOND_FACTOR_SECOND_EQUATION  22514
#define TEMPERATURE_TO_Y_THIRD_FACTOR_SECOND_EQUATION   34265
#define TEMPERATURE_TO_Y_FOURTH_FACTOR_SECOND_EQUATION  2744

#define TEMPERATURE_TO_Y_FIRST_FACTOR_THIRD_EQUATION    50491
#define TEMPERATURE_TO_Y_SECOND_FACTOR_THIRD_EQUATION   96229
#define TEMPERATURE_TO_Y_THIRD_FACTOR_THIRD_EQUATION    61458
#define TEMPERATURE_TO_Y_FOURTH_FACTOR_THIRD_EQUATION   6062

#define XY_TO_TEMPERATURE_X_EPICENTER                   21757
#define XY_TO_TEMPERATURE_Y_EPICENTER                   12176

#define XY_TO_TEMPERATURE_FIRST_FACTOR                  44900ull
#define XY_TO_TEMPERATURE_SECOND_FACTOR                 352500ull
#define XY_TO_TEMPERATURE_THIRD_FACTOR                  682330ull
#define XY_TO_TEMPERATURE_FOURTH_FACTOR                 552033ull

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Converts color temperature to appropriate XY coordinates

\param[in] temperature - color temperature (attribute value);
\param[out] x          - x coordinate (attribute value);
\param[out] y          - y coordinate (attribute value)
******************************************************************************/
void customConvertColorToXY(uint16_t temperature, uint16_t *x, uint16_t *y)
{
  uint64_t localX, localY;
  uint16_t temp = 1000000 / temperature;

  if (TEMPERATURE_TO_X_TEMPERATURE_TRESHOLD > temp)
    localX =  TEMPERATURE_TO_X_THIRD_FACTOR_FIRST_EQUATION / temp +
      TEMPERATURE_TO_X_FOURTH_FACTOR_FIRST_EQUATION -
      TEMPERATURE_TO_X_SECOND_FACTOR_FIRST_EQUATION / temp / temp -
      TEMPERATURE_TO_X_FIRST_FACTOR_FIRST_EQUATION / temp / temp/ temp;
  else
    localX = TEMPERATURE_TO_X_SECOND_FACTOR_SECOND_EQUATION / temp / temp +
      TEMPERATURE_TO_X_THIRD_FACTOR_SECOND_EQUATION / temp +
      TEMPERATURE_TO_X_FOURTH_FACTOR_SECOND_EQUATION -
      TEMPERATURE_TO_X_FIRST_FACTOR_SECOND_EQUATION / temp / temp / temp;

  if (TEMPERATURE_TO_Y_FIRST_TEMPERATURE_TRESHOLD > temp)
    localY = TEMPERATURE_TO_Y_THIRD_FACTOR_FIRST_EQUATION * localX / 65536 -
      TEMPERATURE_TO_Y_FIRST_FACTOR_FIRST_EQUATION * localX * localX * localX / 281474976710656 -
      TEMPERATURE_TO_Y_SECOND_FACTOR_FIRST_EQUATION * localX * localX / 4294967296 -
      TEMPERATURE_TO_Y_FOURTH_FACTOR_FIRST_EQUATION;
  else if (TEMPERATURE_TO_Y_SECOND_TEMPERATURE_TRESHOLD > temp)
    localY = TEMPERATURE_TO_Y_THIRD_FACTOR_SECOND_EQUATION * localX / 65536 -
      TEMPERATURE_TO_Y_FIRST_FACTOR_SECOND_EQUATION * localX * localX * localX / 281474976710656 -
      TEMPERATURE_TO_Y_SECOND_FACTOR_SECOND_EQUATION * localX * localX / 4294967296 -
      TEMPERATURE_TO_Y_FOURTH_FACTOR_SECOND_EQUATION;
  else
  {
    localY = TEMPERATURE_TO_Y_THIRD_FACTOR_THIRD_EQUATION * localX / 65536 +
      TEMPERATURE_TO_Y_FIRST_FACTOR_THIRD_EQUATION * localX * localX * localX / 281474976710656 -
      TEMPERATURE_TO_Y_SECOND_FACTOR_THIRD_EQUATION * localX * localX / 4294967296 -
      TEMPERATURE_TO_Y_FOURTH_FACTOR_THIRD_EQUATION;
  }

  localY *= 4;

  *x = (uint16_t)localX;
  *y = (uint16_t)localY;
}

/**************************************************************************//**
\brief Converts XY coordinates to appropriate color temperature

\param[in] x - x coordinate (attribute value);
\param[in] y - y coordinate (attribute value)

\returns color temperature (attribute value)
******************************************************************************/
uint16_t customConvertXYToColor(uint16_t x, uint16_t y)
{
  uint32_t nX;
  uint32_t nY = y - XY_TO_TEMPERATURE_Y_EPICENTER;
  bool negativeNx = x > XY_TO_TEMPERATURE_X_EPICENTER ? false : true;
  uint64_t temperature;

  if (negativeNx)
  {
    nX = XY_TO_TEMPERATURE_X_EPICENTER - x;
    temperature = XY_TO_TEMPERATURE_SECOND_FACTOR * nX * nX / nY / nY +
      XY_TO_TEMPERATURE_FOURTH_FACTOR +
      XY_TO_TEMPERATURE_FIRST_FACTOR * nX * nX * nX / nY / nY / nY +
      XY_TO_TEMPERATURE_THIRD_FACTOR * nX / nY;
  }
  else
  {
    nX = x - XY_TO_TEMPERATURE_X_EPICENTER;
    temperature = XY_TO_TEMPERATURE_SECOND_FACTOR * nX * nX / nY / nY +
      XY_TO_TEMPERATURE_FOURTH_FACTOR -
      XY_TO_TEMPERATURE_FIRST_FACTOR * nX * nX * nX / nY / nY / nY -
      XY_TO_TEMPERATURE_THIRD_FACTOR * nX / nY;
  }

  return (uint16_t)(1000000 / (temperature / 100));
}

#endif // APP_Z3_DEVICE_TYPE >= APP_DEVICE_TYPE_COLOR_custom

// eof customColorSchemesConversion.c


