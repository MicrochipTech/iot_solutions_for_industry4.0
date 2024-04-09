/*******************************************************************************
  Zigbee Cluster Library Command Manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    commandManager.h

  Summary:
    Interface to provide command management for application.

  Description:
    This file contains Interface to provide command management for application.
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


#ifndef _ZCLCOMMANDMANAGER_H
#define _ZCLCOMMANDMANAGER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#if MICROCHIP_APPLICATION_SUPPORT == 1
#include <app_zigbee/zigbee_console/console.h>
#endif
/******************************************************************************
                    Prototypes
******************************************************************************/
#if MICROCHIP_APPLICATION_SUPPORT == 1
#define cmdprintf(...) appSnprintf(__VA_ARGS__)
#else
#define cmdprintf(...) do{}while(0)
#endif
/**************************************************************************//**
\brief Initialize common cluster functionality
******************************************************************************/
void ZCL_CommandManagerInit(void);

/**************************************************************************//**
\brief Get free ZCL command buffer

\returns command buffer pointer or NULL if no free buffers left
******************************************************************************/
ZCL_Request_t *ZCL_CommandManagerAllocCommand(void);

/**************************************************************************//**
\brief Sends command

\param[in] req - request parameters
******************************************************************************/
void ZCL_CommandManagerSendCommand(ZCL_Request_t *req);

/**************************************************************************//**
\brief Sends attribute request
\param[in] req - request parameters
******************************************************************************/
void ZCL_CommandManagerSendAttribute(ZCL_Request_t *req);

/**************************************************************************//**
\brief ZCL default response
******************************************************************************/
void ZCL_CommandZclDefaultResp(ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);

#endif // _ZCLCOMMANDMANAGER_H

// eof zclcommandManager.h
