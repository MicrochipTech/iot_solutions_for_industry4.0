/*******************************************************************************
  ZLL Device Information Header File

  Company:
    Microchip Technology Inc.

  File Name:
    N_DeviceInfo.h

  Summary:
    This file contains the ZLL Device Information functions.

  Description:
    This file contains the ZLL Device Information functions.
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


#ifndef N_DEVICEINFO_H
#define N_DEVICEINFO_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "zllplatform/infrastructure/N_Address/include/N_Address.h"
#include "zllplatform/infrastructure/N_Types/include/N_Types.h"
#include <mac_phy/include/macAddr.h>
#include <nwk/include/nwkCommon.h>
//#include "ZComDef.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED TYPES
***************************************************************************************************/

typedef struct N_DeviceInfo_Callback_t
{
    /** Pass the incoming data
    *   \param pPacket The incoming packet data
    */
    void (*NetworkSettingsChanged)(uint16_t settings);

    /** Guard to ensure the initializer contains all functions. Must be -1.
    */
    int8_t endOfList;
} N_DeviceInfo_Callback_t;

typedef enum N_DeviceInfo_TrustCenterMode_t
{
    N_DeviceInfo_TrustCenterMode_Central,
    N_DeviceInfo_TrustCenterMode_Distributed,
} N_DeviceInfo_TrustCenterMode_t;

/** The supported profiles. Can be cast to uint16_t to get the profile IDs. */
typedef enum N_DeviceInfo_Profile_t
{
    N_DeviceInfo_Profile_ZLL = 0xC05Eu,
    N_DeviceInfo_Profile_ZHA = 0x0104u,
    N_DeviceInfo_Profile_ZGP = 0xA1E0u,
} N_DeviceInfo_Profile_t;

typedef struct N_DeviceInfo_SynchronizationParameters_t
{
  uint8_t  channel;
  uint16_t panId;
  uint8_t *extPanId;
  uint16_t nwkAddr;
} N_DeviceInfo_SynchronizationParameters_t;

/******************************************************************************
                    Types section
******************************************************************************/
typedef struct
{
  ExtAddr_t                 parentExtAddr;
  uint32_t                  primaryChannelMask;
  uint32_t                  secondaryChannelMask;
  PanId_t                   panId;
  ShortAddr_t               nwkAddr;
  bool                      addressAssignmentCapable;
  bool                      canBeLinkInitiator;
  uint8_t                   correction;
  int8_t                    threshold;
  N_Address_ExtendedPanId_t extPanId;
  uint8_t                   touchlinkZerodBmTransmitPower;
  bool                      factoryNew;
  Channel_t                 channel;
  uint8_t                   nwkUpdateId;
  N_DeviceInfo_TrustCenterMode_t tcMode;
} DeviceInfoParameters_t;

/***************************************************************************************************
* EXPORTED MACROS AND CONSTANTS
***************************************************************************************************/

#define N_DEVICEINFO_SETTING_PANID              0x0001u
#define N_DEVICEINFO_SETTING_EXTPANID           0x0002u
#define N_DEVICEINFO_SETTING_CHANNEL            0x0004u
#define N_DEVICEINFO_SETTING_NETWORK_ADDRESS    0x0008u
#define N_DEVICEINFO_SETTING_NETWORK_UPDATE_ID  0x0010u
#define N_DEVICEINFO_SETTING_FACTORY_NEW        0x0020u
#define N_DEVICEINFO_SETTING_TRUSTCENTERMODE    0x0040u
#define N_DEVICEINFO_SETTING_DURING_INIT        0x8000u

// ZigBee Channels (for creating a channelmask)
#define ZB_CHANNEL_26   0x04000000uL  // 0x1A
#define ZB_CHANNEL_25   0x02000000uL  // 0x19
#define ZB_CHANNEL_24   0x01000000uL  // 0x18
#define ZB_CHANNEL_23   0x00800000uL  // 0x17
#define ZB_CHANNEL_22   0x00400000uL  // 0x16
#define ZB_CHANNEL_21   0x00200000uL  // 0x15
#define ZB_CHANNEL_20   0x00100000uL  // 0x14
#define ZB_CHANNEL_19   0x00080000uL  // 0x13
#define ZB_CHANNEL_18   0x00040000uL  // 0x12
#define ZB_CHANNEL_17   0x00020000uL  // 0x11
#define ZB_CHANNEL_16   0x00010000uL  // 0x10
#define ZB_CHANNEL_15   0x00008000uL  // 0x0F
#define ZB_CHANNEL_14   0x00004000uL  // 0x0E
#define ZB_CHANNEL_13   0x00002000uL  // 0x0D
#define ZB_CHANNEL_12   0x00001000uL  // 0x0C
#define ZB_CHANNEL_11   0x00000800uL  // 0x0B

#define LOWEST_ZIGBEE_CHANNEL               11u
#define HIGHEST_ZIGBEE_CHANNEL              26u

#define BEACON_AMOUNT 3u

#define LOWEST_ZIGBEE_CHANNEL_MASK          0x00000800uL
#define VALID_ZIGBEE_CHANNEL_MASK           0x07FFF800uL

#define ZLL_PRIMARY_CHANNELMASK             (ZB_CHANNEL_11 | ZB_CHANNEL_15 | ZB_CHANNEL_20 | ZB_CHANNEL_25)
#define ZLL_SECONDARY_CHANNELMASK           (VALID_ZIGBEE_CHANNEL_MASK & (~ZLL_PRIMARY_CHANNELMASK))

/***************************************************************************************************
* EXPORTED CONSTANTS
***************************************************************************************************/

extern const N_Address_t c_Addr64;
extern const N_Address_t c_Addr16;
extern const N_Address_t c_AddrAll;
extern const N_Address_t c_AddrRXON;
extern const N_Address_t c_AddrG;
extern DeviceInfoParameters_t deviceInfoParams;
/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

/**************************************************************************//**
  \brief Subscribe to this component's callbacks.

  \param[in] pCallback Pointer to a callback structure filled with functions to be called.

  \return none
 ******************************************************************************/
void N_DeviceInfo_Subscribe(const N_DeviceInfo_Callback_t* pCallback);

/**************************************************************************//**
  \brief Return the version string for the ZigBee Platform.
        To get a correct version string a pre-build action must be run to generate
        N_DeviceInfo_Version.h. This file must a define for N_DEVICE_INFO_PLATFORM_VERSION.
        The version string has the following format.

    (ZigBee Platform release),package_ZigBee (svnversion of package_ZigBee folder),package_Z_Stack (svnversion of package_ZigBee folder),built by (name of user of build machine)

    For the output format of svnversion run svnversion help on the command line.
  \return Pointer to the version string
 ******************************************************************************/
const char* N_DeviceInfo_GetStackVersion(void);

/**************************************************************************//**
  \brief Check if this device is address assignment capable.

  \return TRUE if address assignment capable, else FALSE.
 ******************************************************************************/
bool N_DeviceInfo_IsAddressAssignmentCapable(void);

/**************************************************************************//**
  \brief Set if this device is address assignment capable.

  \param isAddressAssignmentCapable the address assignment capability.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetAddressAssignmentCapable(bool isAddressAssignmentCapable);

/**************************************************************************//**
  \brief Check if this device can be link initiator.

  \return TRUE if it can be link initiator, else FALSE.
 ******************************************************************************/
bool N_DeviceInfo_CanBeLinkInitiator(void);

/**************************************************************************//**
  \brief Set if this device can be link initiator.

  \param canBeLinkInitiator TRUE if the device can be link initiator, else FALSE.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetCanBeLinkInitiator(bool canBeLinkInitiator);

/**************************************************************************//**
  \brief Get the touchlink rssi correction.

  \return The touchlink rssi correction.
 ******************************************************************************/
uint8_t N_DeviceInfo_GetTouchlinkRssiCorrection(void);

/**************************************************************************//**
  \brief Set the touchlink rssi correction.

  \return correction The touchlink rssi correction.
 ******************************************************************************/
void N_DeviceInfo_SetTouchlinkRssiCorrection(uint8_t correction);

/**************************************************************************//**
  \brief Get the touchlink rssi threshold.

  \return The touchlink rssi threshold.
 ******************************************************************************/
int8_t N_DeviceInfo_GetTouchlinkRssiThreshold(void);

/**************************************************************************//**
  \brief Set the touchlink rssi threshold.

  \param threshold The touchlink rssi threshold.
	
  \return None
 ******************************************************************************/
void N_DeviceInfo_SetTouchlinkRssiThreshold(int8_t threshold);

/**************************************************************************//**
  \brief Get the network pan id.

  \return The network pan id.
 ******************************************************************************/
uint16_t N_DeviceInfo_GetNetworkPanId(void);

/**************************************************************************//**
  \brief Get the extended network pan id.

  \return The extended network pan id.
 ******************************************************************************/
N_Address_ExtendedPanId_t* N_DeviceInfo_GetNetworkExtendedPanId(void);

/**************************************************************************//**
  \brief Get the network address.

  \return The network address.
 ******************************************************************************/
uint16_t N_DeviceInfo_GetNetworkAddress(void);

/**************************************************************************//**
  \brief Get the parents network address.

  \return The parents network address.
 ******************************************************************************/
uint16_t N_DeviceInfo_GetParentNetworkAddress(void);

/**************************************************************************//**
  \brief Get the network channel.

  \return The network channel.
 ******************************************************************************/
uint8_t N_DeviceInfo_GetNetworkChannel(void);

/**************************************************************************//**
  \brief Get the network update id.

  \return The network update id.
 ******************************************************************************/
uint8_t N_DeviceInfo_GetNetworkUpdateId(void);

/**************************************************************************//**
  \brief Get the IEEE address.

  \return The IEEE address.
 ******************************************************************************/
const uint8_t* N_DeviceInfo_GetIEEEAddress(void);

/**************************************************************************//**
  \brief Get the parents IEEE address.

  \return The parents IEEE address.
 ******************************************************************************/
const uint8_t* N_DeviceInfo_GetParentIEEEAddress(void);

/**************************************************************************//**
  \brief Get the touchlink 0 dBm transmit power.

  \return The register value for the corresponding transmit power.
 ******************************************************************************/
uint8_t N_DeviceInfo_GetTouchlinkZerodBmTransmitPower(void);

/**************************************************************************//**
  \brief Check if the device is factory new.

  \return TRUE if device is factory new, else returns FALSE.
 ******************************************************************************/
bool N_DeviceInfo_IsFactoryNew(void);

/**************************************************************************//**
  \brief Check if the device is an end device.

  \return TRUE if device is an end device, else returns FALSE.
 ******************************************************************************/
bool N_DeviceInfo_IsEndDevice(void);

/**************************************************************************//**
  \brief Get the primary channel mask.

  \return The primary channel mask.
 ******************************************************************************/
uint32_t N_DeviceInfo_GetPrimaryChannelMask(void);

/**************************************************************************//**
  \brief Set the primary channel mask.

  \param channelMask The new primary channel mask.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetPrimaryChannelMask(uint32_t channelMask);

/**************************************************************************//**
  \brief Get the secondary channel mask.

  \return The secondary channel mask.
 ******************************************************************************/
uint32_t N_DeviceInfo_GetSecondaryChannelMask(void);

/**************************************************************************//**
  \brief Set the secondary channel mask.

  \param channelMask The new secondary channel mask.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetSecondaryChannelMask(uint32_t channelMask);

/**************************************************************************//**
  \brief Get the number of channels in a channel mask (>=1).

  \param channelMask The channelmask to check

  \return The number of channels in the given channel mask.
 ******************************************************************************/

uint8_t N_DeviceInfo_GetNrChannelsInChannelMask(uint32_t channelMask);

/**************************************************************************//**
  \brief Retrieve one of the channels from a channel mask.

  \param index An index from 0 to N_DeviceInfo_GetNrChannelsInChannelMask()-1
  \param channelMask The channelmask

  \return The channels from the given channel mask in order, e.g. index 0 will return the lowest channel.
 ******************************************************************************/
uint8_t N_DeviceInfo_GetChannelForIndex(uint8_t index, uint32_t channelMask);

/**************************************************************************//**
  \brief Returns whether a channel is valid according to the current channel mask.

  \param channel The channel to check
  \param channelMask The channelMask to check

  \return TRUE if the channel is in the mask, otherwise FALSE
 ******************************************************************************/
bool N_DeviceInfo_IsChannelInMask(uint8_t channel, uint32_t channelMask);

/**************************************************************************//**
  \brief Gets the network mode.
        Note: Must not be called when the device is factory new.

  \param channel The channel to check
  \param channelMask The channelMask to check

  \return The network mode this device is currently operating in.
 ******************************************************************************/
N_DeviceInfo_TrustCenterMode_t N_DeviceInfo_GetTrustCenterMode(void);

/**************************************************************************//**
  \brief Aligns parameters in N_DeviceInfo with configuration server

  \param channel The network channel.
  \param panId The network channel.
  \param extPanId Pointer to the extended network pan id.
  \param nwkAddr The network address.
	
  \return None
 ******************************************************************************/
void N_DeviceInfo_SynchronizeParameters(N_DeviceInfo_SynchronizationParameters_t *params);

/**************************************************************************//**
  \brief Check if the device is a coordinator.
	
  \return TRUE if device is a coordinator, else returns FALSE.
 ******************************************************************************/
bool N_DeviceInfo_IsCoordinator(void);

/***************************************************************************************************
* PLATFORM INTERNAL INTERFACE
***************************************************************************************************//** \privatesection
*/

/**************************************************************************//**
  \brief Set the network pan id.

*param panId The network pan id.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetNetworkPanId(uint16_t panId);

/**************************************************************************//**
  \brief Set the extended network pan id.

*param pExtPanId Pointer to the extended network pan id.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetNetworkExtendedPanId(uint8_t* pExtPanId);

/**************************************************************************//**
  \brief Set the network address.

*param nwkAddress The network address.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetNetworkAddress(uint16_t nwkAddress);

/**************************************************************************//**
  \brief Set the parents network address.

*param parentNwkAddress The parents network address.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetParentNetworkAddress(uint16_t parentNwkAddress);

/**************************************************************************//**
  \brief Set the parents ieee address.

*param ieeeAddress The parents ieee address.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetParentIEEEAddress(N_Address_Extended_t ieeeAddress);

/**************************************************************************//**
  \brief Set the network update id.

*param updateId The network update id.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetNetworkUpdateId(uint8_t updateId);

/**************************************************************************//**
  \brief Set the network channel.

*param nwkChannel The network channel.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetNetworkChannel(uint8_t nwkChannel);

/**************************************************************************//**
  \brief Set if the device is factory new.

*param factoryNew TRUE if device is factory new, else returns FALSE.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetFactoryNew(bool factoryNew);

/**************************************************************************//**
  \brief Sets the trust center mode.

*param trustCenterMode The trust center mode the network is currently operating in.

  \return None
 ******************************************************************************/
void N_DeviceInfo_SetTrustCenterMode(N_DeviceInfo_TrustCenterMode_t trustCenterMode);

/**************************************************************************//**
  \brief Return the profile ID of the given endpoint

*param endpoint the endpoint to get the profile ID of

  \return The profile ID.
 ******************************************************************************/
N_DeviceInfo_Profile_t N_DeviceInfo_GetProfileIdForEndpoint(uint8_t endpoint);

/***************************************************************************************************
* IMPLEMENTATION OF INLINE FUNCTIONS
***************************************************************************************************//**************************************************************************//**
  \brief Implementation of \ref N_DeviceInfo_IsEndDevice
        This function is inline to make it possible for the compiler
    to remove router/enddevice only code.

  \return TRUE if end device, false otherwise
 ******************************************************************************/
bool N_DeviceInfo_IsEndDevice_Impl(void);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_DEVICEINFO_H
