/*******************************************************************************
  ZLL Groups Bindings Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_Groups_Bindings.h

  Summary:
    This file contains the ZLL Groups Bindings functions.

  Description:
    This file contains the ZLL Groups Bindings functions.
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


// used interfaces
#ifdef TESTHARNESS

#else

#define N_Groups_AddToGroup N_Groups_AddToGroup_Impl
#define N_Groups_RemoveFromGroup N_Groups_RemoveFromGroup_Impl
#define N_Groups_RemoveFromAllGroups N_Groups_RemoveFromAllGroups_Impl
#define N_Groups_IsMemberOfGroup N_Groups_IsMemberOfGroup_Impl
#define N_Groups_GetTotalCapacity N_Groups_GetTotalCapacity_Impl
#define N_Groups_GetRemainingCapacity N_Groups_GetRemainingCapacity_Impl
#define N_Groups_GetGroup N_Groups_GetGroup_Impl
#define N_Groups_Subscribe N_Groups_Subscribe_Impl

#endif // TESTHARNESS