/*******************************************************************************
  CS stackVersion Header File

  Company
    Microchip Technology Inc.

  File Name
    stackVersion.h

  Summary
    This file provides Interface to BitCloud stack version information.

  Description
    This header file provides interface to manage the BitCloud stack version information.
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

/******************************************************************************
                    Define(s) section
******************************************************************************/

/******************************************************************************
Bit field information:

   ---------------------------------------------------
  | bit pos |    field name   |        meaning        |
  |---------------------------------------------------|
  |   0-7   |   Reserved      |         NA            |
  |         |                 |                       |
  |---------------------------------------------------|
  |   8-9   |   Qualifier     | 00 - reserved         |
  |         |                 | 01 - Production       |
  |         |                 | 10 - Maintenance      |
  |         |                 | 11 - Engineering      |
  |         |                 |                       |
  |---------------------------------------------------|
  |  10-15  |    branch       | running version of    |
  |         |   iteration     | branch's release      |
  |         |                 |                       |
  |---------------------------------------------------|
  |  16-19  |    branch       | branch identification |
  |         |   identifier    | number. If there are  |
  |         |                 | many branches for the |
  |         |                 | same <stackMajor.     |
  |         |                 | StackMinor.           |
  |         |                 | StackMinorDerivative>,|
  |         |                 | they can be           |
  |         |                 | represented as this   |
  |         |                 |                       |
  |---------------------------------------------------|
  |  20-23  |  stack minor    | subsequent reference  |
  |         |   derivative    | versions of stackminor|
  |         |                 | until its next update |
  |         |                 |                       |
  |---------------------------------------------------|
  |  24-27  |  stack minor    | minor version         |
  |         |                 |                       |
  |---------------------------------------------------|
  |  28-31  |  stack major    | major version         |
  |         |                 |                       |
   ---------------------------------------------------

Example:
  3.1.1_SAMR21.20E is represented as 0x31145300
  (SAMR21 branch id is assumed as 4)

  0011  0001  0001  0100  010100  11  0000  0000
    |    |     |      |      |     |       |
  stack stack stack branch branch Qual  Reserved
  major minor minor ident   iter
              deriv
******************************************************************************/

#undef  CS_STACK_VERSION_VALUE
#define CS_STACK_VERSION_VALUE  0X51130500 //ZB_V5.1.1_3.1P
