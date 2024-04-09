/*******************************************************************************
 Custom Ias Zone cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    customIasZoneCluster.h

  Summary:
    This file contains the Custom Ias Zone cluster interface.

  Description:
    This file contains the Custom Ias Zone cluster interface.
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
#ifndef _CUSTOMIASZONECLUSTER_H
#define _CUSTOMIASZONECLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/zclIasZoneCluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
/* Some default values for attributes */
/* Enable/Define Zone Table Size */
#define APP_IAS_ZONE_TYPE_ATTRIBUTE_VALUE  0x000D

#define APP_IAS_ZONE_CIE_ADDRESS_ATTRIBUTE_VALUE        0x0000
#ifndef ZONE_NOTI_PERIOD
#define ZONE_NOTI_PERIOD                                20000u
#endif
#define EXTENDED_STATE_DEFAULT                          0x00
#define ADRESS_MODE                                     0x02
#define CIE_ADDR                                        0x0000
#define CIE_ENDPT                                       0x14
#define TIME_IN_SECONDS                                 1000u
#define DEFAULT_VAL                                     0x00
#define ZONE_MAXIMUM_LIMIT_VALUE                        CCPU_TO_LE16(0x02FF)

#define DEFAULT_EXT_ADDR     0xFFFFFFFFFFFFFFFF
#define TEST_MODE_DURATION   0x05

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
extern ZCL_IasZoneClusterServerAttributes_t customIasZoneClusterServerAttributes;
extern PROGMEM_DECLARE (ZCL_IasZoneClusterCommands_t customIasZoneClusterServerCommands);
extern ZCL_IasZoneClusterClientAttributes_t customIasZoneClusterClientAttributes;
extern PROGMEM_DECLARE (ZCL_IasZoneClusterCommands_t customIasZoneClusterClientCommands);
typedef ZCL_ZoneTable_t zoneTable_t;
/******************************************************************************
                    Prototypes section
******************************************************************************/
/**************************************************************************//**
 \brief customIasZoneClusterInit
 \param none
 \return none
******************************************************************************/
void customIasZoneClusterInit(void);

/**************************************************************************//**
 \brief zoneStatusChangeNotification Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \param zoneStatus - zone status
 \param extendedStatus - extended status
 \return none
******************************************************************************/
void zoneStatusChangeNotificationCommand(APS_AddrMode_t mode, ShortAddr_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t zoneStatus, uint8_t extendedStatus);

/**************************************************************************//**
 \brief zoneEnrollRequest Command
 \param mode - Adress Mode
 \param addr - short addr
 \param ep  -  Endpoint of the device
 \param[in] srcEp- source endpoint;
 \param zone_id -  index of the zone table
 \param manuf_code  -  manufacturer code
 \return none
******************************************************************************/
void zoneEnrollRequestCommand(APS_AddrMode_t mode, APS_Address_t addr, Endpoint_t ep, Endpoint_t srcEp, uint16_t manufCode);

/**************************************************************************//**
\brief Fills zcl addressing structure

\param[out] addressing - pointer to the structure to be filled;
\param[in]  mode       - addressing mode;
\param[in]  addr       - short address of destination mode;
\param[in]  ep         - endpoint number of destination node;
\param[in]  cluster    - cluster id
******************************************************************************/
void fillDstAddressingServerWithAddrMode(ZCL_Addressing_t *addressing, APS_AddrMode_t mode, APS_Address_t addr, Endpoint_t ep, ClusterId_t cluster);

/***************************************************************************//**
 \brief zoneChange change to send out the notification to CIE
 \param zoneStatusChangeValue - value of the status to trigger some actions
*******************************************************************************/
void zoneStatusChangeCommand(uint16_t zoneStatusChangeValue);
#endif // _CUSTOMIASZONECLUSTER_H

// eof customIasZoneCluster.h
