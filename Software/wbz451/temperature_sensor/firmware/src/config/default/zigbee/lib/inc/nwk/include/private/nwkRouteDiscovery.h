// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Route Discovery Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkRouteDiscovery.h

  Summary:
    This file contains the parameters and defines to the NWK Route Discovery Mechanism.

  Description:
    This file contains the parameters and defines to the NWK Route Discovery Mechanism.
 *******************************************************************************/


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

// DOM-IGNORE-BEGIN
#if !defined _NWK_ROUTE_DISCOVERY_H
#define _NWK_ROUTE_DISCOVERY_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <systemenvironment/include/sysQueue.h>
#include <nwk/include/nlmeRouteDiscovery.h>
#include <nwk/include/nwkCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Internal states of the route discovery component. */
typedef enum _NwkRouteDiscoveryState_t
{
  NWK_ROUTE_DISCOVERY_IDLE_STATE = 0x99,
  NWK_ROUTE_DISCOVERY_PROCESS_STATE = 0x38
} NwkRouteDiscoveryState_t;

/** Internal state and variables of route discovery component. */
typedef struct _NwkRouteDiscovery_t
{
  QueueDescriptor_t queue;  /**< Queue of requests from other components. */
  /** Low part of the identifier of initial route request. */
  uint8_t routeRequestIdLow;
#if defined _SYS_ASSERT_ON_
  /** Finite-state machine. */
  NwkRouteDiscoveryState_t state;
#endif /* _SYS_ASSERT_ON_ */
} NwkRouteDiscovery_t;

/******************************************************************************
                                Prototypes section
 ******************************************************************************/
#if defined NWK_ROUTING_CAPACITY \
  && (defined _NWK_MESH_ROUTING_ || defined _NWK_CONCENTRATOR_)
/**************************************************************************//**
  \brief Task handler of the route discovery component.
 ******************************************************************************/
NWK_PRIVATE void nwkRouteDiscoveryTaskHandler(void);

/***************************************************************************//**
  \brief Reset the route discovery component.
 ******************************************************************************/
NWK_PRIVATE void nwkResetRouteDiscovery(void);

/***************************************************************************//**
  \brief Flush all route discovery requests.
 ******************************************************************************/
NWK_PRIVATE void nwkFlushRouteDiscovery(void);

/***************************************************************************//**
  \brief nwkRouteDiscovery idle checking.

  \return true, if nwkRouteDiscovery performs no activity, false - otherwise.
 ******************************************************************************/
NWK_PRIVATE bool nwkRouteDiscoveryIsIdle(void);

#else /* no NWK_ROUTING_CAPACITY */

#define nwkRouteDiscoveryTaskHandler NULL
#define nwkRouteDiscoveryIsIdle NULL
#define nwkResetRouteDiscovery() (void)0
#define nwkFlushRouteDiscovery() (void)0

#endif /* NWK_ROUTING_CAPACITY and (_NWK_MESH_ROUTING_ or _NWK_CONCENTRATOR_) */
#endif /* _NWK_ROUTE_DISCOVERY_H */
/** eof nwkRouteDiscovery.h */

