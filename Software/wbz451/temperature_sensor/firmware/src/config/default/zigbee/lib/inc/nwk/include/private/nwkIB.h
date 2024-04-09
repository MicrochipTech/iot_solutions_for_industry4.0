// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Information Base Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkIB.h

  Summary:
    This file contains the NWK layer Information Base and parameters.

  Description:
    This file contains the NWK layer Information Base and parameters.
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
#if !defined _NWK_IB_H
#define _NWK_IB_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <nwk/include/private/nwkConfig.h>
#include <systemenvironment/include/sysTypes.h>
#include <configserver/include/configserver.h>
#include <nwk/include/private/nwkSystem.h>
#include <mac_phy/include/mac.h>
#include <nwk/include/nwkCommon.h>
#include <nwk/include/nwkSecurity.h>
#include <nwk/include/private/nwkSystem.h>
#include <nwk/include/private/nwkFrame.h>
#include <nwk/include/nlmeReset.h>
#include <nwk/include/nlmePermitJoining.h>
#include <nwk/include/nlmeNetworkDiscovery.h>
#include <nwk/include/nwkEndDeviceTimeout.h>
#include <nwk/include/nwkConfigServer.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
/** Attributes are initialized by NWK-layer. */
typedef struct _NIB_t
{
  /** A network address of parent node. */
  ShortAddr_t parentNetworkAddress;
  /** The count of total transmissions. */
  uint16_t transmitCounter;
  /** The count of transmissions with failures. */
  uint16_t transmitFailureCounter;
  /** The address of the designated network channel manager function. */
  ShortAddr_t managerAddr;
  /** This field shall contain the device capability information established at
   * network joining time. */
  MAC_CapabilityInf_t capabilityInformation;
  /** The tree depth of the neighbor device. A value of 0x00 indicates that
   * the device is the ZigBee coordinator for the network. */
  NwkDepth_t depth;
  /** A sequence number used to identify outgoing frames */
  NwkSequenceNumber_t sequenceNumber;
  /** The total delivery time for a broadcast transmission, i.e. the time
   * required for a broadcast to be delivered to every device in the network. */
  uint32_t networkBroadcastDeliveryTime;
  /** The value identifying a snapshot of the network settings with which this
   * node is operating with. */
  NwkUpdateId_t updateId;
  /** Network rejoin permissions, by default end devices and routers can rejoin. */
  NWK_RejoinPermit_t rejoinPermit;
  /** The flag indicates that NWK-layer don't have to wait all route responses and
   * can calls a confirmation function when a first route reply has been received. */
  bool fastRouteDiscovery;
  struct {
    /** This field is used by MAC layer. */
    NwkLength_t header[MAC_MAX_BEACON_HEADER_LENGTH];
    /** The beacon payload contain the information which enables the NWK layer
     * to provide additional information to new devices that are performing
     * network discovery and allows these new devices to more efficiently select
     * a network and a particular neighbor to join. */
    NwkBeaconPayload_t payload;
  } beacon;
  /** Top part of the identifier of initial route request. */
  uint8_t routeRequestIdTop;

            /*** Attributes are initialized in Config Server. ***/
  /** The type of the device:
   *  - 0x00 - zigbee coordinator
   *  - 0x01 - zigbee router
   *  - 0x02 - zigbee end device */
  DeviceType_t deviceType;
  /** A value that determines the method used to assign addresses:
   *  - 0x00 = use distributed address allocation
   *  - 0x01 = reserved
   *  - 0x02 = use stochastic address allocation. */
  NWK_AddrAlloc_t addrAlloc;
  /** The current route symmetry setting. 1 means that routes are considered to
   * be comprised of symmetric links. Backward and forward routes are created
   * during one-route discovery and they are identical. 0 indicates that routes
   * are not consider to be comprised of symmetric links. Only the forward route
   * is stored during route discovery.*/
  bool symLink;
  /** Determines whether or not the static addressing mode will be used.
   * If set to '1' then the device must use a static network address
   * otherwise, the stochastic addressing mode will be employed. */
  bool uniqueAddr;
  /** The identifier of the ZigBee stack profile in use for this device. */
  StackProfile_t stackProfile;
  /** The version of the ZigBee NWK protocol in the device. */
  uint8_t protocolVersion;
  /** The depth a device can have. */
  NwkDepth_t maxDepth;
  /** Route to neighbor directly only if the incoming cost is less than given
   * threshold. */
  NwkLinkCost_t maxNeighborRouteCost;
  /** Select this route to the hop  only if the  cost is less than given
   * threshold. */
  NwkLinkCost_t maxLinkRouteCost;
  /** RF channel page */
  uint8_t channelPage;
  /** Number of RF channel */
  Channel_t logicalChannel;
  /** The 16-bit address that the device uses to communicate with the PAN. */
  ShortAddr_t networkAddress;
  /** The short (16-bit) pan identifier of a zigbee network. */
  PanId_t panId;
  /** The Extended PAN Identifier for the PAN of which the device is a member.
   * The value 0x0000000000000000 means the Extended PAN Identifier is unknown.
   **/
  ExtPanId_t extendedPanId;
  /** The number of routers any one device is allowed to have as children. */
  NwkChildCount_t maxRouters;
  /** The number of end devices any one device is allowed to have as children.
   **/
  NwkChildCount_t maxEndDevices;
#if defined _SECURITY_
  /** Pointer to the security information base. */
  NWK_SecurityIB_t securityIB;
  /** Current values of incoming and outgoing security counters. */
  NWK_SecurityFrameCounters_t securityCounters;
#endif /* _SECURITY_ */
  /** If the local device receives a remote NWK leave request command then
   * if this flag is equal to FALSE then the received command must be rejected. */
  bool leaveReqAllowed;
#if defined _NWK_THRESHOLD_ROUTING_
  /** The node should notify a source node which is performing route discovery
   * about a bad link. The link is bad if link cost is greater than given parameter. */
  NwkLinkCost_t softLinkCostThreshold;
#endif /* _NWK_THRESHOLD_ROUTING_ */
#ifdef _CHILD_MANAGEMENT_
  /** For an RFD, this records the information received in an End Device
   * Timeout Response command indicating the parent information.
   * For an FFD, this records the deviceâ??s local capabilities. */
  uint8_t parentInformation;
  /** It indicates the default timeout in minutes for any end device
   * that does not negotiate a different timeout value. */
  NwkEndDeviceTimeout_t endDeviceTimeoutDefault;
#endif /* _CHILD_MANAGEMENT_ */
} NIB_t;

/******************************************************************************
                             Definitions section
 ******************************************************************************/
#define NWK_FREQ_AGILITY_STEP 1U

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Reset the network information base.

  \return None.
 ******************************************************************************/
NWK_PRIVATE void nwkResetNib(void);

/**************************************************************************//**
  \brief Update beacon payload depending on NIB values
 ******************************************************************************/
NWK_PRIVATE void nwkUpdateBeaconPayload(void);

/**************************************************************************//**
  \brief Set depth in NIB and update cSkips.

  \param[in] depth - new value of depth.
 ******************************************************************************/
NWK_PRIVATE void nwkSetDepth(NwkDepth_t depth);

/**************************************************************************//**
  \brief Is it possible to join a new device on given depth?

    Compare the depth with maximum depth and configuration parameters.

  \param[in] depth - current depth of the parent device.
  \return true if the deivce with the passed depth can have children.
 ******************************************************************************/
NWK_PRIVATE bool nwkIsMaxDepth(const NwkDepth_t depth);

/**************************************************************************//**
  \brief Reload parameters from the config server.
 ******************************************************************************/
NWK_PRIVATE void nwkReloadNibFromConfigServer(void);

#ifdef _CHILD_MANAGEMENT_
/**************************************************************************//**
  \brief Set parent information in NIB.

  \param[in] parentInfo - new value of parent information.
 ******************************************************************************/
void nwkSetParentInformation(uint16_t parentInfo);

/**************************************************************************//**
  \brief Set end device default timeout in NIB.

  \param[in] timeout - new value of end device default timeout.
 ******************************************************************************/
void nwkSetEndDeviceDefaultTimeout(NwkEndDeviceTimeout_t timeout);
#endif /* _CHILD_MANAGEMENT_ */

#if defined _ROUTER_ || defined _ENDDEVICE_
/**************************************************************************//**
  \brief Set a network address of parent device.

  \param[in] addr - short address of parent device.
 ******************************************************************************/
NWK_PRIVATE void nwkSetParentShortAddr(ShortAddr_t addr);

#endif /* _ROUTER_ or _ENDDEVICE_ */

#endif  /* _NWK_IB_H */
/**  eof nwkIB.h */

