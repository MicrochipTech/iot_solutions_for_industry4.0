/*******************************************************************************
 Custom Ias ace cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customIasACECluster.h

  Summary:
    This file contains the Custom Ias ace cluster interface.

  Description:
    This file contains the Custom Ias ace cluster interface.
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

#ifndef _CUSTOMACEACECLUSTER_H
#define _CUSTOMACEACECLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/zclIasACECluster.h>
#include <zcl/include/zclIasZoneCluster.h>

/******************************************************************************
                    Defines section
******************************************************************************/

/* Enable/Define Zone Table Size */
#define APP_ZONE_TABLE_SIZE  3


#define ZONE_TABLE_ENTRIES      APP_ZONE_TABLE_SIZE
#define DEFAULT_VAL             0x00
#define PANEL_DEFAULT_STATE     DEFAULT_VAL
#define TIME_REMAINING_DEFAULT  DEFAULT_VAL
#define ACE_ENDPT               APP_ENDPOINT_CUSTOM
#define ADRESS_MODE             0x02
#define PAYLOAD_SIZE            0x32
#define PANEL_STAUS_TIMER       1000u

/******************************************************************************
                    Externals
******************************************************************************/
extern PROGMEM_DECLARE (ZCL_IasACEClusterCommands_t customIasAceClusterServerCommands);
extern PROGMEM_DECLARE (ZCL_IasACEClusterCommands_t customIasAceClusterClientCommands);
extern ZCL_IasAceClusterServerAttributes_t customIasAceClusterServerAttributes;
extern ZCL_IasAceClusterClientAttributes_t customIasAceClusterClientAttributes;
typedef ZCL_ZoneTable_t zoneTable_t;
extern zoneTable_t zoneTables[ZONE_TABLE_ENTRIES];

/******************************************************************************
                    Definition(s) section
******************************************************************************/
extern ZCL_IasAceClusterClientAttributes_t iasACEAceClusterClientAttributes;


/******************************************************************************
                    Type section
******************************************************************************/
BEGIN_PACK
typedef struct PACK
{
  uint8_t totalZones;
  bypassList_t bypassTable[ZONE_TABLE_ENTRIES];
}bypassTable_t;
END_PACK
/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Initializes IAS ACE cluster
******************************************************************************/
void customIasACEClusterInit(void);

/**************************************************************************//**
 \brief ACEArmCommand Command
 \param mode - Adress Mode
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \param arm -  ARM mode
 \return none
******************************************************************************/
void aceArmCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep , Endpoint_t srcEp, uint8_t arm_mode , char *code , uint8_t zoneid);

/**************************************************************************//**
 \brief GetByPassZoneList Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \return none
******************************************************************************/
void getByPassZoneListCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
 \brief aceByPass Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \param zone_numbers -  total zones
 \param zoneId(s) -  index of the zone table
 \return none
******************************************************************************/
void aceByPassCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t zoneNumbers, uint8_t *zone_id, char *armDisarmCode);

/**************************************************************************//**
 \brief aceEmergency Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \return none
******************************************************************************/
void aceEmergencyCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
 \brief aceFire Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \return none
******************************************************************************/
void aceFireCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
 \brief acePanic Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \return none
******************************************************************************/
void acePanicCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
 \brief aceGetZoneInformation Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \param zoneId - zoneId offset
 \return none
******************************************************************************/
void aceGetZoneInformationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t zoneId);

/**************************************************************************//**
 \brief aceGetZoneIdMap Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \return none
******************************************************************************/
void aceGetZoneIdMapCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
 \brief aceGetPanelStatus Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \return none
******************************************************************************/
void aceGetPanelStatusCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp);

/**************************************************************************//**
 \brief aceGetZoneStatus Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \param startingZoneId - starting of the zoneId offset
 \param maxNumberZoneids - maximum zoneIdss
 \param zoneStatusMaskFlag - mask flag
 \param zoneStatusMask - status of the zone
 \return none
******************************************************************************/
void aceGetZoneStatusCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint8_t startingZoneId, uint8_t maxNumberZoneids, uint8_t zoneStatusMaskFlag, uint16_t zoneStatusMask);

/**************************************************************************//**
\brief Sends ACEPanelStatusChanged Command

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep     - destination endpoint;
\param[in] srcEp- source endpoint;
\param[in] panel_status - Panel status value;
\param[in] seconds_remaining  - seconds remaining for the panel status;
\param[in] audible_noti - audible notificaiton;
\param[in] alarmstatus   - alarm status;
******************************************************************************/
void acePanelStatusChangedCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, ZCL_PanelStatus_t panelStatus,
                                     uint8_t secondsRemaining, ZCL_AudibleNotification_t audibleNoti,ZCL_AlarmStatus_t alarmStatus);

/**************************************************************************//**
\brief Sends ACEZoneStatusChanged Command

\param[in] mode - address mode;
\param[in] addr - short address of destination node;
\param[in] ep     - destination endpoint;
\param[in] srcEp- source endpoint;
\param[in] zoneId - zone_id which changed the status;
\param[in] zoneStatus  - status of the zoneId which changed;
\param[in] audible_sound - audible sound;
\param[in] zone_label   - zone label;
******************************************************************************/
void aceZoneStatusChangedCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp,
                                 uint8_t zoneId, uint8_t zoneStatus, ZCL_AudibleNotification_t audibleSound, char *zoneLabel);
#endif // _CUSTOMACEACECLUSTER_H

// eof customIasACECluster.h
