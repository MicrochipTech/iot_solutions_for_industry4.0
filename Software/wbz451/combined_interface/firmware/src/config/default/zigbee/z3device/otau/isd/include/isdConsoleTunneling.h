/*******************************************************************************
   Image Stoarge Driver Tunneling mechanism Header File

  Company:
    Microchip Technology Inc.

  File Name:
    isdConsoleTunneling.h

  Summary:
    This file contains the Interface for tunneling functionality.

  Description:
    This file contains the Interface for tunneling functionality.
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

#ifndef _ISDCONSOLETUNNELING_H
#define _ISDCONSOLETUNNELING_H

#include <definitions.h>
#include <xc.h>


/******************************************************************************/
typedef struct
{
    DRV_HANDLE              isdTunnelHandle;
    DRV_USART_BUFFER_HANDLE readBufferHandle;
    DRV_USART_BUFFER_HANDLE writeBufferHandle;
    /** \brief It's pointer to receive buffer. \n
    If rxBuffer is NULL then transactions are discarded. \n
    Size of buffer depends on user application. */
    uint8_t *rxBuffer;
    /** \brief length of receive buffer */
    uint16_t rxBufferLength;
    /** \brief It's pointer to transmit buffer. \n
    If txBuffer is NULL then callback method is used. \n
    If txBuffer isn't NULL then polling method is used. */
    uint8_t *txBuffer;
    /** \brief length of transmit buffer */
    uint16_t txBufferLength;
    /** \brief It's receive usart callback. \n
    If rxCallback is NULL then polling method is used. \n
    If rxCallback isn't NULL then callback method is used.*/
    void (*rxCallback)(uint16_t);
    /** \brief It's transmitting was completed usart callback. \n
    If txBuffer isn't NULL then txCallback notify about end of bytes sending.  */
    void (*txCallback)(void);
    void (*errCallback)(uint16_t);
   
}ISD_TunnelDescriptor_t;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Start sending char from tx tunneling buffer through usart.
******************************************************************************/
void isdSendTunnelingData(void);

void ISD_WriteUSART(uint8_t *buffer, uint8_t length);
void ISD_ReadUSART(uint8_t *buffer, uint8_t length);
void ISD_ClearUSART(void);

/**************************************************************************//**
\brief Raised callback to upper layer.
******************************************************************************/
void raiseTunnelRxCallback(uint8_t);

#endif // _ISDCONSOLETUNNELING_H