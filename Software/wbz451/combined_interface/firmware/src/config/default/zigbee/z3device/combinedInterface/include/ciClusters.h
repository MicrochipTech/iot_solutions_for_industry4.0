/*******************************************************************************
  Combined Interface clusters Header File

  Company:
    Microchip Technology Inc.

  File Name:
    ciClusters.h

  Summary:
    This file contains the Combined Interface clusters interface.

  Description:
    This file contains the Combined Interface clusters interface.
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

#ifndef _CICLUSTER_H
#define _CICLUSTER_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <z3device/common/include/appConsts.h>

/******************************************************************************
                    Definitions section
******************************************************************************/
#ifdef OTAU_SERVER
  #define CI_SERVER_CLUSTERS_COUNT     7u
  #define CI_SERVER_CLUSTER_INIT_COUNT (CI_SERVER_CLUSTERS_COUNT - 1)
#else
  #define CI_SERVER_CLUSTERS_COUNT     6u
  #define CI_SERVER_CLUSTER_INIT_COUNT CI_SERVER_CLUSTERS_COUNT
#endif

#define CI_CLIENT_CLUSTER_INIT_COUNT   18u      //sankar
#define CI_CLIENT_CLUSTERS_COUNT       18u      //sankar

/******************************************************************************
                    Externals
******************************************************************************/
extern ZCL_Cluster_t ciServerClusters[CI_SERVER_CLUSTERS_COUNT];
extern ZCL_Cluster_t ciClientClusters[CI_CLIENT_CLUSTERS_COUNT];
extern void (*ciServerClusterInitFunctions[CI_SERVER_CLUSTER_INIT_COUNT])();
extern void (*ciClientClusterInitFunctions[CI_CLIENT_CLUSTER_INIT_COUNT])();
extern ClusterId_t   ciServerClusterIds[CI_SERVER_CLUSTERS_COUNT];
extern ClusterId_t   ciClientClusterIds[CI_CLIENT_CLUSTERS_COUNT];

#endif // _CICLUSTER_H

// eof ciClusters.h
