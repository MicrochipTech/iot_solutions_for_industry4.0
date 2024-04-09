/*******************************************************************************
  ZLL InterPan Buffers Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_InterPanBuffers.h

  Summary:
    This file contains the ZLL InterPan Buffers functions.

  Description:
    This file contains the ZLL InterPan Buffers functions.
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


#if defined _INTERPAN_

#ifndef _INTERPAN_BUFFERS_H
#define _INTERPAN_BUFFERS_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <aps/include/intrpData.h>

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
  \brief Initializes InterPan buffers
******************************************************************************/
void initInterPanBuffers(void);

/**************************************************************************//**
  \brief Gets free InterPan buffer

  \returns pointer to buffer if it is available, NULL otherwise
******************************************************************************/
INTRP_DataReq_t *getFreeInterPanBuffer(void);

/**************************************************************************//**
  \brief Frees buffer

  \param[in] req - buffer to be free
******************************************************************************/
void freeInterPanBuffer(INTRP_DataReq_t *req);

/**************************************************************************//**
  \brief Gets buffer for data for interPan request

  \param[in] req - pointer to request for which buffers is allocated

  \returns pointer to buffer for interPan data
******************************************************************************/
uint8_t *getDataBuffer(INTRP_DataReq_t *req);

#endif // _INTERPAN_BUFFERS_H
#endif // #if defined _INTERPAN_

// eof N_InterPanBuffers.h
