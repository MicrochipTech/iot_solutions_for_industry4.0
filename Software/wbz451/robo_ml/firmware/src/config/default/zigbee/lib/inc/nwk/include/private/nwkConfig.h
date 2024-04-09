// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Configuration Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkConfig.h

  Summary:
    This file contains the NWK Constants declarations and definitions.

  Description:
    This file contains the NWK Constants declarations and definitions.
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
#if !defined _NWK_CONFIG_H
#define _NWK_CONFIG_H
// DOM-IGNORE-END

/******************************************************************************
                             Definitions section
 ******************************************************************************/
/** A Boolean flag indicating whether the device is capable of becoming
    the ZigBee coordinator. ZigBee spec r17, page 338, table 3.43.
    */

#if defined _COORDINATOR_
  #define NWKC_COORDINATOR_CAPABLE true
#else
  #define NWKC_COORDINATOR_CAPABLE false
#endif /* _COORDINATOR_ */

/** Define for coordinator address */
#define NWKC_COORD_ADDR 0x0000U

/** North America */
/* #define NWK_NO_WIFI_CHANNELS_MASK 0x610800 */
/** Europe */
#define NWK_NO_WIFI_CHANNELS_MASK 0x618000U

#define NWK_FAVOURITE_CHANNELS_MASK (NWK_NO_WIFI_CHANNELS_MASK)

#define NWKC_PROTOCOL_ID 0U

#define NWKC_INITIAL_LINK_STATUS_PERIOD 15000UL /* msec*/

#define NWK_MAX_CHANNEL 26

#define NWK_MAX_LINK_STATUS_FAILURES 3U
#define NWK_END_DEVICE_MAX_FAILURES 3U

#define NWK_MAX_ED_LEVEL 0xCCU /* 255 * 0.8 */

/** Support network realignment */
/* #define NWK_COORD_REALIGNMENT */

#if defined _NWK_NONSTANDARD_BEACON_FILTER_
  /** Filter by extended pan id */
  #define NWK_BEACON_FILTER_EXTENDED_PANID
  /** If predefined short pan id then discard beacons with other pan id. */
  #define NWK_BEACON_FILTER_PREDEFINED_PANID
  /** Beacons with the end device capacity bit equal zero will discard. */
  #define NWK_BEACON_FILTER_END_DEVICE_CAPACITY
  /** Beacons with the router capacity bit equal zero will discard. */
  #define NWK_BEACON_FILTER_ROUTER_CAPACITY
#endif /* NWK_NONSTANDARD_BEACON_FILTER */

/** Update the neighbor table only if our network address is presented in
 * the received link status command. */
/* #define NWK_LINK_STATUS_ONLY_IN_LIST */

/** Duration of searching other networks on same channel.
 * It is ~(2^NWK_REPORT_SCAN_DURATION)*960*16 (usec) - for 2.4MHz */
#define NWK_SEARCH_NETWORKS_DURATION 8U /* ~4sec - 2.4MHz */

#define NWK_SELECT_RANDOM_PARENT
#define NWK_DELTA_LQI (255/10)

#if defined _NWK_ROUTE_CACHE_
  #define NWKC_NO_ROUTE_CACHE false
#else
  #define NWKC_NO_ROUTE_CACHE true
#endif /* _NWK_ROUTE_CACHE_ */

/** Maximum number of the many-to-one route requests after that the
 * route record command must be transmitted if no source route packet has
 * been received. */
#define NWK_MAX_NO_SOURCE_ROUTE_PERIODS 3U

/** The maximum time duration in milliseconds allowed for the parent and
    all child devices to retransmit a broadcast message. */
#define  NWK_PASSIVE_ACK_TIMEOUT  15625UL /* octets duration ~= 500 ms. in 2.4Ghz */

/** Maximum data packet retransmission. The maximum number of retries allowed
 * after a broadcast transmission failure.*/
#define NWK_MAX_BROADCAST_RETRIES 2U

/** Maximum value of a link cost metric. */
#define NWK_MAX_LINK_COST 7U
/** Maximum cost of route path. */
#define NWK_MAX_PATH_COST  ((uint8_t)UINT8_MAX - 1U)
/** Default maximum value for new neighbor. */
#define NWK_MAX_LQI 255U
#define NWK_MAX_RSSI 0U

/** Time duration in milliseconds until a route discovery expires.
 * ZigBee spec r18, Table 3.43, page 342. */
#define NWKC_ROUTE_DISCOVERY_TIME 0x2710U

#if !defined _NWK_ROUTING_OPTIMIZATION_
#define _NWK_ROUTING_OPTIMIZATION_ 0
#endif

#define NWK_ENDDEVICE_SEND_LEAVE_IND_ON_LEAVE_REQ

#define SEND_UPDATE_DEVICE_ON_LEAVE_INDICATION

#if defined _CERTIFICATION_
/* Doesn't change relationship of router child. */
#define NWK_TAKES_CARE_OF_CHILD_ROUTER

#define NWK_LIFE_TIME_OF_RX_ON_END_DEVICE (65534UL * 2048UL) /* msec */

#else /* not _CERTIFICATION_ */
/* End device Nwk leave indication on reception of Leave request from the Parent */


#define NWK_LIFE_TIME_OF_RX_ON_END_DEVICE (60U * 2048UL) /* msec */

/* Check the depth of potential parent before join. */
#define NWK_CHECK_DEPTH

#endif /* _CERTIFICATION_ */

#define NWK_MAX_DEPTH_IN_BEACON 0xfU

/** The cost of an outgoing link as measured by the neighbor. A value
 * of 0 indicates no outgoing cost is available. See ZigBee Spec r19, Table 3.48. */
#define NWK_NO_OUTGOING_COST 0U

#define NWK_NO_INCOMING_COST 0U

#define NWK_UPDATE_ID_OVERFLOW_LIMIT 200U

#define NWK_NO_LQI 0U

#endif /* _NWK_CONFIG_H */
/** eof nwkConfig.h */
