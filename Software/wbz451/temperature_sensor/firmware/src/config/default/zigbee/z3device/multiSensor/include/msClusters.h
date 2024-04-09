/*******************************************************************************
  Multi-Sensor clusters Header File

  Company:
    Microchip Technology Inc.

  File Name:
    msClusters.h

  Summary:
    This file contains Multi-Sensor clusters interface.

  Description:
    This file contains Multi-Sensor clusters interface.
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

#ifndef _MSCLUSTER_H
#define _MSCLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <z3device/multiSensor/include/lsIdentifyCluster.h>
#include <z3device/multiSensor/include/osIdentifyCluster.h>
#include <z3device/multiSensor/include/tsIdentifyCluster.h>
#include <z3device/multiSensor/include/hsIdentifyCluster.h>



/******************************************************************************
                    Definitions section
******************************************************************************/



#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR
#define OS_SERVER_CLUSTERS_COUNT     3 
#else
#define OS_SERVER_CLUSTERS_COUNT     0 
#endif

#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR
#define LS_SERVER_CLUSTERS_COUNT     3 
#else
#define LS_SERVER_CLUSTERS_COUNT     0 
#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR
#define TS_SERVER_CLUSTERS_COUNT     3 
#else
#define TS_SERVER_CLUSTERS_COUNT     0 
#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR
#define HS_SERVER_CLUSTERS_COUNT     3 
#else
#define HS_SERVER_CLUSTERS_COUNT     0 
#endif

#define OS_CLIENT_CLUSTERS_COUNT   2 
#define LS_CLIENT_CLUSTERS_COUNT   2 
#define TS_CLIENT_CLUSTERS_COUNT   2 
#define HS_CLIENT_CLUSTERS_COUNT   2 


#define MS_SERVER_CLUSTERS_COUNT     0 
#define MS_SERVER_CLUSTER_INIT_COUNT MS_SERVER_CLUSTERS_COUNT

#ifdef OTAU_CLIENT
  #define MS_CLIENT_CLUSTERS_COUNT   (1) 
  #define MS_CLIENT_CLUSTER_INIT_COUNT 1 
#else
  #define MS_CLIENT_CLUSTERS_COUNT   0 
  #define MS_CLIENT_CLUSTER_INIT_COUNT 0 
#endif

/* Multi sensor device type logical device Id form reserved space */
#define  APP_Z3_MULTI_SENSOR_DEVICE_ID      0x01ff

/******************************************************************************
                    Externals
******************************************************************************/

#ifdef OTAU_CLIENT
extern void (*msClientClusterInitFunctions[MS_CLIENT_CLUSTER_INIT_COUNT])();

extern ZCL_Cluster_t msClientClusters[MS_CLIENT_CLUSTERS_COUNT];
extern ClusterId_t   msClientClusterIds[MS_CLIENT_CLUSTERS_COUNT];
#endif


#ifdef APP_SENSOR_TYPE_OCCUPANCY_SENSOR

extern ZCL_Cluster_t osServerClusters[OS_SERVER_CLUSTERS_COUNT];
extern ClusterId_t   osServerClusterIds[OS_SERVER_CLUSTERS_COUNT];

extern ZCL_Cluster_t osClientClusters[OS_CLIENT_CLUSTERS_COUNT];
extern ClusterId_t   osClientClusterIds[OS_CLIENT_CLUSTERS_COUNT];

extern void (*osClientClusterInitFunctions[OS_CLIENT_CLUSTERS_COUNT])();
extern void (*osServerClusterInitFunctions[OS_SERVER_CLUSTERS_COUNT])();

#endif


#ifdef APP_SENSOR_TYPE_LIGHT_SENSOR

extern ZCL_Cluster_t lsServerClusters[LS_SERVER_CLUSTERS_COUNT];
extern ClusterId_t   lsServerClusterIds[LS_SERVER_CLUSTERS_COUNT];

extern ZCL_Cluster_t lsClientClusters[LS_CLIENT_CLUSTERS_COUNT];
extern ClusterId_t   lsClientClusterIds[LS_CLIENT_CLUSTERS_COUNT];

extern void (*lsClientClusterInitFunctions[LS_CLIENT_CLUSTERS_COUNT])();
extern void (*lsServerClusterInitFunctions[LS_SERVER_CLUSTERS_COUNT])();

#endif

#ifdef APP_SENSOR_TYPE_TEMPERATURE_SENSOR

extern ZCL_Cluster_t tsServerClusters[TS_SERVER_CLUSTERS_COUNT];
extern ClusterId_t   tsServerClusterIds[TS_SERVER_CLUSTERS_COUNT];

extern ZCL_Cluster_t tsClientClusters[TS_CLIENT_CLUSTERS_COUNT];
extern ClusterId_t   tsClientClusterIds[TS_CLIENT_CLUSTERS_COUNT];

extern void (*tsClientClusterInitFunctions[TS_CLIENT_CLUSTERS_COUNT])();
extern void (*tsServerClusterInitFunctions[TS_SERVER_CLUSTERS_COUNT])();

#endif

#ifdef APP_SENSOR_TYPE_HUMIDITY_SENSOR

extern ZCL_Cluster_t hsServerClusters[HS_SERVER_CLUSTERS_COUNT];
extern ClusterId_t   hsServerClusterIds[HS_SERVER_CLUSTERS_COUNT];

extern ZCL_Cluster_t hsClientClusters[HS_CLIENT_CLUSTERS_COUNT];
extern ClusterId_t   hsClientClusterIds[HS_CLIENT_CLUSTERS_COUNT];

extern void (*hsClientClusterInitFunctions[HS_CLIENT_CLUSTERS_COUNT])();
extern void (*hsServerClusterInitFunctions[HS_SERVER_CLUSTERS_COUNT])();

#endif

#endif // _MSCLUSTER_H

// eof msClusters.h

