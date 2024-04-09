// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object notify Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoNotify.h

  Summary:
    This file contains the Functions for raising ZDO notifications

  Description:
    This file contains the Functions for raising ZDO notifications

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
#ifndef _ZDONOTIFY_H
#define _ZDONOTIFY_H
// DOM-IGNORE-END


/******************************************************************************
                    Includes section
 ******************************************************************************/
#include <zdo/include/zdo.h>
#include <aps/include/aps.h>

/******************************************************************************
                    Prototypes section
 ******************************************************************************/

/*************************************************************************//**
  \brief Subscribe legacy ZDO notifications to stack events
  \param[in] None
  \return None
 ******************************************************************************/
void zdoInitNotifications(void);

/*************************************************************************//**
  \brief Call ZDO_MgmtNwkUpdateNotf() with prepared notification information
  
  \param[in] notf - notification information
  \return None
 ******************************************************************************/
void ZDO_NotifyGeneral(ZDO_MgmtNwkUpdateNotf_t *notf);

/*************************************************************************//**
  \brief ZDO unsolicited notification
  
  \param[in] notf - notification information
  \return None
 ******************************************************************************/
void ZDO_UnsolicitedNotify(ZDO_MgmtNwkUnsolicatedEnhancedUpdateNotf_t *notf);

#ifdef _TC_PROMISCUOUS_MODE_
/**************************************************************************//**
  \brief Indication of a failed attempt of a remote device to rejoin the network

   The function should be implemented by the trust center's application.

   The function is invoked to notify the application that a remote node
   has attempted to rejoin the network and failed, perhaps, because it has
   provided the pre-configured link key, while the trust center holds the
   randomly generated one.

   If the application previously saved the pre-configured link key by calling
   the APS_SetPreinstalledLinkKey() function, it can now restore the key
   by calling the APS_RestorePreinstalledLinkKey() function.

  \param[in] extAddr - pointer to extended address of the lost device
  \return None
 ******************************************************************************/
void ZDO_NotifyBindLost(ExtAddr_t* extAddr);
#endif /* _TC_PROMISCUOUS_MODE_ */

#endif // _ZDONOTIFY_H
// eof zdoNotify.h
