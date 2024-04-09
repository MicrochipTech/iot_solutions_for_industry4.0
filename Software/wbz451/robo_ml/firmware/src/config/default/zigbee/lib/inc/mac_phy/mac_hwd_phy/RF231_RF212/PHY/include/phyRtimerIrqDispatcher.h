/*******************************************************************************
  PHY Rtimer Interrupt Dispatcher Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phyRtimerIrqDispatcher.h

  Summary:
    This file contains the Declaration for Rtimer dispatcher interface.

  Description:
    This file contains declaration to functions which Dispatches RTimer event to 
    registered delay source.
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

#ifndef _PHYRTIMERIRQDISPATCHER_H
#define _PHYRTIMERIRQDISPATCHER_H

/******************************************************************************
                        Includes section.
******************************************************************************/
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyMemAccess.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#define STATE_POLL_PERIOD 100U // [us] Period of time for RF current state polling.

/******************************************************************************
                        Prototypes section.
******************************************************************************/
/******************************************************************************
  Set source of timer invocation.
******************************************************************************/
void phySetRTimerSource(HAL_RTimerSource_t source);

#endif /* _PHYRTIMERIRQDISPATCHER_H */

// eof phyRtimerIrqDispatcher.h
