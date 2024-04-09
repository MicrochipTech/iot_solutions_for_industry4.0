/*******************************************************************************
  ZLL Binding Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Binding_Bindings.h

  Summary:
    This file contains the ZLL Bindings functions.

  Description:
    This file contains the ZLL Bindings functions.
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

// N_Binding
#ifndef N_BINDING_BINDINGS_H
#define N_BINDING_BINDINGS_H

#define N_Binding_AddBinding N_Binding_AddBinding_Impl
#define N_Binding_AddBindingExt N_Binding_AddBindingExt_Impl
#define N_Binding_RemoveBinding N_Binding_RemoveBinding_Impl
#define N_Binding_RemoveBindings N_Binding_RemoveBindings_Impl
#define N_Binding_FindBinding N_Binding_FindBinding_Impl
#define N_Binding_GetNumberOfBindingRecords N_Binding_GetNumberOfBindingRecords_Impl
#define N_Binding_GetBindingRecord N_Binding_GetBindingRecord_Impl
#define N_Binding_RemoveBindingRecord N_Binding_RemoveBindingRecord_Impl

#endif // N_BINDING_BINDINGS_H
//eof