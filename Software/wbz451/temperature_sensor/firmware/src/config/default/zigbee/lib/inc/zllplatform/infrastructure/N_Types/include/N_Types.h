/*******************************************************************************
  ZLL Type Definitions Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Types.h

  Summary:
    This file contains the ZLL Type Definitions functions.

  Description:
    This file contains the ZLL Type Definitions functions.
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



#ifndef N_TYPES_H
#define N_TYPES_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#  include <stdint.h>
#  include <stdbool.h>

#  if defined(__bool_true_false_are_defined) // should be only defined in bootloader and sb_crypt by adding pre-include file stdbool.h
# ifndef TRUE
#    define TRUE true
# endif
# ifndef FALSE
#    define FALSE false
# endif
#  else
      typedef unsigned char   bool;
#  endif


#ifndef TRUE
#  define TRUE 1u
#endif

#ifndef FALSE
#  define FALSE 0u
#endif

#ifndef NULL
#  define NULL 0u
#endif


#endif // N_TYPES_H
