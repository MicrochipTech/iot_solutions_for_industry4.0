/*******************************************************************************
  ZCC0 Custom Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
   ciArmcluster0Cluster.h

  Summary:
    This file contains the Custom Cluster interface.

  Description:
    This file contains the Custom Cluster interface.
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

/******************************************************************************
                    Includes section
******************************************************************************/

#include <zcl/include/zclArmcluster0Cluster.h>

/******************************************************************************
                    Definition(s) section
******************************************************************************/
#define ARMCLUSTER0_MIN_REPORT_PERIOD 1
#define ARMCLUSTER0_MAX_REPORT_PERIOD 4

/*******************************************************************************
                    Prototypes section
*******************************************************************************/

    
void ciArmcluster0Init(void);
   
ZCL_Status_t ciArmorientationclientcommandSendCommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint
	, uint8_t Armorientationparam);   
ZCL_Status_t ciArmmovementclientcommandSendCommand(APS_AddrMode_t addressMode, ShortAddr_t shortAddress, Endpoint_t endPoint, Endpoint_t sourceEndPoint
	, uint8_t Armmovementparam);
/******************************************************************************
                    Global variables
******************************************************************************/

//Custom Cluster Attributes
extern ZCL_Armcluster0ClusterClientAttributes_t armcluster0ClientClusterAttributes;
//Custom Cluster Commands
extern PROGMEM_DECLARE (ZCL_Armcluster0ClusterCommands_t armcluster0ClientClusterCommands);



