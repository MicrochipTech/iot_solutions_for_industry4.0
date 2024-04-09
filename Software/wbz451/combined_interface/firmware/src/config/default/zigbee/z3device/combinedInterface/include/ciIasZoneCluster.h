/*******************************************************************************
  Combined Interface IASZone cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
   ciIasZoneCluster.h

  Summary:
    This file contains the Combined Interface IASZone cluster implementation.

  Description:
    This file contains the Combined Interface IASZone cluster implementation.
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

#ifndef _CIIASZONECLUSTER_H
#define _CIIASZONECLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zclIasZoneCluster.h>
//#include <combinedInterface/include/iasACEZoneCluster.h>
#include <z3device/clusters/include/haClusters.h>
/******************************************************************************
                    Defines section
******************************************************************************/
#define DEFAULT_EXT_ADDR     0xFFFFFFFFFFFFFFFF
#define TEST_MODE_DURATION   0x05

/******************************************************************************
                    Externals
******************************************************************************/
extern PROGMEM_DECLARE (ZCL_IasZoneClusterCommands_t ciIASZoneClusterClientCommands);
extern ZCL_IasZoneClusterClientAttributes_t ciZoneClusterClientAttributes;
typedef ZCL_ZoneTable_t zoneTable_t;
/******************************************************************************
                    Prototypes section
******************************************************************************/

/**************************************************************************//**
\brief Initializes Thermostat cluster
******************************************************************************/
void ciIasZoneClusterInit(void);

/**************************************************************************//**
  \brief ZoneInitiateNormalOperatingModeCommand
  \param[in] mode   - address mode;
  \param[in] addr   - short address of destination node;
  \param[in] ep     - destination endpoint;
  \param[in] srcEp- source endpoint;
  \return none
******************************************************************************/
void zoneInitiateNormalOperatingModeCommand(APS_AddrMode_t mode,ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
  \brief ZoneInitiateTestModeCommand
  \param[in] mode   - address mode;
  \param[in] addr   - short address of destination node;
  \param[in] ep     - destination endpoint;
  \param[in] srcEp- source endpoint;
  \param[in] testmode_duration     - test mode duration;
  \param[in] testmode_duration     - test mode duration;
  \return none
******************************************************************************/
void zoneInitiateTestModeCommand(APS_AddrMode_t mode,ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t testmodeDuration, uint8_t currentZoneSensitivityLevel);
/***************************************************************************//**
 \brief Initiate Enrolment procedure command
 \param[in] addressing - pointer to addressing information;
 \return none
*******************************************************************************/
void aceZoneEnrollmentProcInitiateCmd(APS_AddrMode_t mode, ShortAddr_t zoneServerAddr, uint8_t srcEp, void *data, uint8_t enrolmentType);

#endif // _CIIASZONECLUSTER_H

// eof ciIasZoneCluster.h
