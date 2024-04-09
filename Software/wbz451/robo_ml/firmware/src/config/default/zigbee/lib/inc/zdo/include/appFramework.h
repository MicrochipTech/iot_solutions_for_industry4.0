// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee device object, app framework Header File

  Company:
    Microchip Technology Inc.

  File Name:
    appFramework.h

  Summary:
    This file contains the types of ZDP and descriptors

  Description:
    This file contains the types of ZDP and descriptors

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
#ifndef _APPFRAMEWORK_H
#define _APPFRAMEWORK_H
// DOM-IGNORE-END

/******************************************************************************
                                    Includes section
 ******************************************************************************/
 
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysEndian.h>
#include <mac_phy/include/mac.h>
#include <systemenvironment/include/sysQueue.h>
#include <systemenvironment/include/sysEvents.h>

/******************************************************************************
                               Define(s) section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
#define ZDP_USER_DESC_FIELD_SIZE  16

/** These defines are used only during preprocessor phase. Please use DeviceType_t  enumeration values instead. */
    
#define DEV_TYPE_COORDINATOR  0
#define DEV_TYPE_ROUTER       1
#define DEV_TYPE_ENDDEVICE    2

/** The Stack version needs to be updated for every ZigBee Pro-Core revision. 
    The initial version is 1 for ZigBee Pro-Core Revision r22 */
#define SERVER_MASK_STACK_VERSION 0x0016
// DOM-IGNORE-END

/********************************************************************************
                               Base types
 ********************************************************************************/
typedef uint8_t  Endpoint_t; //!< The type for holding endpoint ID
typedef uint16_t ProfileId_t; //!< The type for holding profile ID
typedef uint16_t ClusterId_t; //!< The type for holding cluster ID
typedef uint16_t GroupAddr_t; //!< The type for holding group address
typedef uint8_t  StackProfile_t; //!< ZigBee stack profile type


/********************************************************************************
                                Zigbee APFW types definition
 ********************************************************************************/

BEGIN_PACK
/** Node descriptor Mandatory for each node. */
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(4, (
    /*! Device role:\n
    000 - ::DEVICE_TYPE_COORDINATOR,\n
    001 - ::DEVICE_TYPE_ROUTER,\n
    010 - ::DEVICE_TYPE_END_DEVICE,\n
    011-111 - reserved.*/
    uint8_t   logicalType : 3,
    /*! Specifies whether a complex descriptor is available on this device. */
    uint8_t   complexDescriptorAvailable: 1,
    /*! Specifies whether a user descriptor is available on this device. */
    uint8_t   userDescriptorAvailable: 1,
    /*! Reserved. */
    uint8_t   reserved: 3
  ))

  LITTLE_ENDIAN_OCTET(2, (
    /*! APS capability flags. Not supported (always set to 0). */
    uint8_t   apsFlags : 3,
    /*! Bit mask for supported frequency bands.\n
      Bit 0: 868 - 868.6 MHz\n
      Bit 1: Reserved\n
      Bit 2: 902 - 928 MHz\n
      Bit 3: 2400 - 2483.5 MHz\n
      Bit 4: Reserved. */
    uint8_t   frequencyBand : 5
  ))

  /*! MAC capability flags.\n
  Bit 0: is the node capable of becoming an alternate PAN coordinator\n
  Bit 1: device type (full-function vs. reduced-function device)\n
  Bit 2: is the device mains-powered \n
  Bit 3: is the receiver enabled when the device is idle \n
  Bits 4-5: Reserved\n
  Bit 6: is MAC security enabled \n
  Bit 7: Always equals 1. */
  MAC_CapabilityInf_t  macCapbFlags;

  /*! 16-bit manufacturer code allocated by the ZigBee Alliance. */
  uint16_t manufacturerCode;

  /*! Maximum size of the network sub-layer data unit (NSDU) for this node, in octets.
  Valid range is 0x00-0x7f. */
  uint8_t maxBufferSize;

  /*! Maximum size of the application sub-layer data unit (ASDU) that can be
  transferred to this node in one single message transfer, in octets.
  Valid range is 0x0000-0x7fff. May exceed the maxBufferSize value through the
  use of fragmentation. */
  uint16_t maxTransferSize;

  /*! Bit mask denoting the system server capabilities of this node.\n
  Used to facilitate discovery of particular system servers by other nodes.\n
  Bit 0: Primary Trust Center\n
  Bit 1: Backup Trust Center\n
  Bit 2: Primary Binding Table Cache\n
  Bit 3: Backup Binding Table Cache\n
  Bit 4: Primary Discovery Cache\n
  Bit 5: Backup Discovery Cache\n
  Bit 6: Network Manager\n
  Bits 7-15: Reserved. */
  uint16_t serverMask;

  /*! Maximum size of the application sub-layer data unit (ASDU) that can be
  transferred from this node in one single message transfer, in octets.
  Valid range is 0x0000-0x7fff. */
  uint16_t maxOutcTransferSize;

  /*! Descriptor capabilities bit mask.
  Bit 0: Extended Active Endpoint list available\n
  Bit 1: Extended Simple Descriptor list available\n
  Bits 2-7: Reserved. */
  uint8_t descriptorCapabilityField;
} NodeDescriptor_t;

/** Power descriptor
    Mandatory for each node */
typedef struct PACK
{
/*! Specifies the current sleep/power-saving mode of the node.\n
0000 - Receiver synchronized with the 'receiver on when idle' subfield of the node descriptor.\n
0001 - Receiver comes on periodically as defined by the node power descriptor.\n
0010 - Receiver comes on when stimulated, e.g. by a user pressing a button.\n
0011-1111 - Reserved. */
  uint8_t currentPowerMode : 4;
/*! Specifies the power sources available on this node.\n
0 - Constant (mains) power\n
1 - Rechargeable battery\n
2 - Disposable battery\n
3 - Reserved. */
  uint8_t availablePowerSources : 4;
/*! Specifies the power source being currently used by the node.\n
0 - Constant (mains) power\n
1 - Rechargeable battery\n
2 - Disposable battery\n
3 - Reserved. */
  uint8_t currentPowerSource : 4;
/*! Specifies the level of charge of the power source.\n
0000 - Critical\n
0100 - 33%\n
1000 - 66%\n
1100 - 100%\n
All other values - Reserved. */
  uint8_t currentPowerSourceLevel : 4;
} PowerDescriptor_t;

/** Simple Descriptor
    Mandatory for each endpoint present in the node. */
typedef struct PACK
{
/*! ID of the endpoint within the node to which this description refers.
Applications shall only use endpoints 1-240. */
  Endpoint_t   endpoint;
/*! Profile that is supported on this endpoint. */
  ProfileId_t  AppProfileId;
/*! Device description supported on this endpoint. */
  uint16_t     AppDeviceId;
/*! Version of the device description supported on this endpoint. */
  uint8_t      AppDeviceVersion : 4;
/*! Reserved. */
  uint8_t      Reserved         : 4;
/*! Number of input clusters supported on this endpoint. If 0, the
application input cluster list field shall not be included. */
  uint8_t      AppInClustersCount;
/*! List of input clusters supported on this endpoint. */
  ClusterId_t* AppInClustersList;
/*! Number of output clusters supported on this endpoint. If 0, the
application output cluster list field shall not be included. */
  uint8_t      AppOutClustersCount;
/*! List of output clusters supported on this endpoint. */
  ClusterId_t* AppOutClustersList;
} SimpleDescriptor_t;

/** User descriptor.
    sed optionally. */
typedef struct PACK
{
  uint8_t FieldLength;
/** Human-readable character string that allows the user to identify the device. */
  uint8_t FieldName[ZDP_USER_DESC_FIELD_SIZE];
} UserDescriptor_t;

END_PACK

/** Intended for specifying device role. */
typedef enum
{
  DEVICE_TYPE_COORDINATOR = DEV_TYPE_COORDINATOR,
  DEVICE_TYPE_ROUTER      = DEV_TYPE_ROUTER,
  DEVICE_TYPE_END_DEVICE  = DEV_TYPE_ENDDEVICE
} DeviceType_t;

/** Intended for specifying NodeDescriptor_t::macCapbFlags field. */
enum
{
  MAC_CAP_ALTERNATE_PAN_COORDINATOR = 0x01,
  MAC_CAP_DEVICE_TYPE_FFD = 0x02,
  MAC_CAP_POWER_SOURCE_MAINS = 0x04,
  MAC_CAP_RX_ON_WHEN_IDLE = 0x08,
  MAC_CAP_SECURITY_CAPABLE = 0x40,
  MAC_CAP_ALLOCATE_ADDRESS = 0x80 // always set for rev13
};

/** Intended for specifying NodeDescriptor_t::serverMask field. */
enum
{
  SERVER_MASK_NO_SERVER = 0x0000,
  SERVER_MASK_PRIMARY_TRUST_CENTER = 0x0001,
  SERVER_MASK_BACKUP_TRUST_CENTER = 0x0002,
  SERVER_MASK_PRIMARY_BINDING_TABLE_CACHE = 0x0004,
  SERVER_MASK_BACKUP_BINDING_TABLE_CACHE = 0x0008,
  SERVER_MASK_PRIMARY_DISCOVERY_CACHE = 0x0010,
  SERVER_MASK_BACKUP_DISCOVERY_CACHE = 0x0020,
  SERVER_MASK_NETWORK_MANAGER = 0x0040,
};

/** Intended for specifying NodeDescriptor_t::descriptorCapabilityField field. */
enum
{
  EXT_LIST_ACTIVE_EP = 0x01,
  EXT_LIST_SIMPLE_DESC = 0x02
};

/** Intended for specifying PowerDescriptor_t::currentPowerMode field. */
typedef enum
{
  RECEIVER_SYNCRONIZED_WHEN_ON_IDLE = 0,
  RECEIVER_COMES_PERIODICALLY = 1,
  RECEIVER_COMES_WHEN_STIMULATED = 2
  //RESERVED = 0xF /* all other values */
} PowerMode_t;

/** Intended for specifying PowerDescriptor_t::availablePowerSources
and PowerDescriptor_t::currentPowerSource fields. */
typedef enum
{
  MAINS_POWER = 0x1,
  RECHARGEABLE_BATTERY = 0x2,
  DISPOSABLE_BATTERY = 0x4,
  //RESERVED
} PowerSource_t;

/** Intended for specifying PowerDescriptor_t::currentPowerSourceLevel field. */
typedef enum
{
  CRITICAL_0 = 0,
  PERCENT_33 = 4,
  PERCENT_66 = 8,
  PERCENT_100 = 0xC
  //RESERVED = 0xFF;  /* all over values */
} PowerSourceLevel_t;


/** Intended for specifying ComplexDescriptorField_t::CompressedXMLTag field. */
enum
{
  TAG_LANGUAGE_AND_CHARACTER_SET = 0001,
  TAG_MANUFACTURER_NAME = 0010,
  TAG_MODEL_NAME = 0011,
  TAG_SERIAL_NUMBER = 0100,
  TAG_DEVICE_URL = 0101,
  TAG_ICON = 0110,
  TAG_ICON_URL = 0111,
};

/** Complex Descriptor field. */
typedef struct
{
/*! Field type.\n
Possible values:\n
0x00 - Reserved\n
0x01 - ISO 639-1 language code\n
0x02 - Manufacturer name\n
0x03 - Model name\n
0x04 - Serial number\n
0x05 - Device URL\n
0x06 - Icon\n
0x07 - Icon URL\n
0x08-0xFF - Reserved. */
  uint8_t CompressedXMLTag;
/*! Field contents. */
  uint8_t* pDataField;
} ComplexDescriptorField_t;


/** brief Complex Descriptor.
    Used optionally.
Consists of compressed XML tags.
The overall length shall be less than or equal to apscMaxDescriptorSize.*/
typedef struct
{
/*! Field count. */
  uint8_t FieldCount;
/*! List of fields. */
  ComplexDescriptorField_t* pFields;
} ComplexDescriptor_t;

#endif  /* _APPFRAMEWORK_H */

