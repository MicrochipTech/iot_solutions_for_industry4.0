/*******************************************************************************
 Custom On Off cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customOnOffCluster.h

  Summary:
    This file contains the Custom On Off cluster interface.

  Description:
    This file contains the Custom On Off Control cluster interface.
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

#ifndef _CUSTOMONOFFCLUSTER_H
#define _CUSTOMONOFFCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclZllOnOffCluster.h>
#include <z3device/clusters/include/onOffCluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define ONOFF_VAL_MIN_REPORT_PERIOD 30
#define ONOFF_VAL_MAX_REPORT_PERIOD 60

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_OnOffClusterServerAttributes_t customOnOffClusterServerAttributes;
extern ZCL_OnOffClusterClientAttributes_t customOnOffClusterClientAttributes;
extern PROGMEM_DECLARE(ZCL_OnOffClusterCommands_t         customOnOffCommands);

/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes On/Off cluster
******************************************************************************/
void customOnOffClusterInit(void);

/**************************************************************************//**
\brief Set Extension Field Set
******************************************************************************/
void setOnOff(bool onOff);

/**************************************************************************//**
\brief gets on/off state

\return on/off state
******************************************************************************/
bool onOffState(void);

/**************************************************************************//**
\brief Set Extension Field Set
******************************************************************************/
void onOffClusterSetExtensionField(bool onOff);

/**************************************************************************//**
\brief Set Global Scene Control attribute to 'true'
******************************************************************************/
void onOffClusterSetGlobalSceneControl(void);

/**************************************************************************//**
\brief Update device ON state as per StartUpOnOff attribute value
******************************************************************************/
void customUpdateStartUpOnOffState(void);

#endif // _CUSTOMONOFFCLUSTER_H

// eof customOnOffCluster.h

