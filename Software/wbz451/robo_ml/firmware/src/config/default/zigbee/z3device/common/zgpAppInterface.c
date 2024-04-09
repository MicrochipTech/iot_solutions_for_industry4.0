/*******************************************************************************
  Zigbee Green Power Application Interface Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zgpAppInterface.c

  Summary:
    This file contains the Zigbee Green Power Application interface

  Description:
    This file contains the Zigbee Green Power Application interface
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


#ifdef _GREENPOWER_SUPPORT_

#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
/******************************************************************************
                           Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <z3device/common/include/zgpAppInterface.h>
#include <zgp/GPInfrastructure/highZgp/include/zgpClusterZclInterface.h>
#include <zcl/include/clusters.h>

/**************************************************************************//**
                          Global variables
******************************************************************************/
OSAL_SEM_HANDLE_TYPE semZgpInternalHandler;
/**************************************************************************//**
   Internal functions
******************************************************************************/
static ZCL_DeviceEndpoint_t greenPowerEndpoint;

/**************************************************************************//**
  Function definitions
******************************************************************************/
/**************************************************************************//**
  \brief To initialize ZGP application and core ZGP

  \param[in] resetToFN - status of resetting to factory new

  \return none
******************************************************************************/
void ZGP_AppInit(void)
{
  ZCL_DeviceEndpoint_t *gpEp = &greenPowerEndpoint;
  gpEp->simpleDescriptor.endpoint = GREEN_POWER_ENDPOINT;
  gpEp->simpleDescriptor.AppProfileId = GREEN_POWER_PROFILE_ID;
  gpEp->simpleDescriptor.AppDeviceVersion = GP_DEVICE_VERSION;
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC    
  gpEp->simpleDescriptor.AppDeviceId = GP_COMBO_BASIC_DEVICE_ID;
  gpEp->simpleDescriptor.AppInClustersCount = 1;
  gpEp->simpleDescriptor.AppInClustersList = zgpServerClusterIds;
  gpEp->serverCluster = zgpServerClusters;
#else
  gpEp->simpleDescriptor.AppDeviceId = GP_PROXY_BASIC_DEVICE_ID;
  gpEp->simpleDescriptor.AppInClustersCount = 0;
  gpEp->simpleDescriptor.AppInClustersList = NULL;
  gpEp->serverCluster = NULL;
#endif
  gpEp->simpleDescriptor.AppOutClustersCount = 1;
  gpEp->simpleDescriptor.AppOutClustersList = zgpClientClusterIds;
  gpEp->clientCluster = zgpClientClusters;
  // Register the end point with AF layer 
  // to handle the frames with ProfileId different from destination endpoint's profile id
  ZCL_RegisterEndpoint(&greenPowerEndpoint);

#if APP_ENABLE_ZGP_CERTIFICATION_EXTENSION != 1
  ZGPH_ProxyBasicInit();
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
  ZGPH_SinkBasicInit();
#ifndef ZGP_DISABLE_TRANSLATION_TABLE
  ZGP_TransTableInit(false);
#endif
#endif
#else
  ZGPL_NvmTableInit();
#endif
  OSAL_SEM_Create(&semZgpInternalHandler, OSAL_SEM_TYPE_BINARY,0, 0);
}
#endif // #if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
#endif // _GREENPOWER_SUPPORT_

// eof zgpAppInterface.c
