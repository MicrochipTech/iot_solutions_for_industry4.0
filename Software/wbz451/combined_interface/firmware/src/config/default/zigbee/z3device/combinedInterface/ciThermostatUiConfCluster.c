/*******************************************************************************
  Combined Interface Thermostat cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
   ciThermostatUiConfCluster.c

  Summary:
    This file contains the Combined Interface Thermostat cluster interface.

  Description:
    This file contains the Combined Interface Thermostat cluster interface.
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

#ifdef APP_DEVICE_TYPE_COMBINED_INTERFACE
/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/common/include/appConsts.h>
#include <z3device/combinedInterface/include/ciThermostatUiConfCluster.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/clusters/include/haClusters.h>
/******************************************************************************
                    Local variables section
******************************************************************************/
/******************************************************************************
                    Prototypes section
******************************************************************************/
/******************************************************************************
                    Global variables
******************************************************************************/
ZCL_ThermostatUiConfClusterClientAttributes_t ciThermostatUiConfClusterClientAttributes =
{  
  ZCL_DEFINE_THERMOSTAT_UI_CONF_CLUSTER_CLIENT_ATTRIBUTES()
};

/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Thermostat cluster
******************************************************************************/
void ciThermostatUiConfClusterInit(void)
{
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_COMBINED_INTERFACE, THERMOSTAT_UI_CONF_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);
  ciThermostatUiConfClusterClientAttributes.clusterVersion.value = THERMOSTAT_UI_CONF_CLUSTER_VERSION;
  cluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE
// eof ciThermostatUiConfCluster.c
