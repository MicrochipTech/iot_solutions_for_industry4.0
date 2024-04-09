// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee Cluster Library Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zcl.h

  Summary:
    The header file describes the public ZCL interface.

  Description:
    The file describes the public interface and types of ZCL.
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
#ifndef _ZCL_H
#define _ZCL_H
// DOM-IGNORE-END

/******************************************************************************
                           Includes section
******************************************************************************/

#include <systemenvironment/include/sysTypes.h>
#include <zdo/include/appFramework.h>
#include <aps/include/aps.h>
#include <configserver/include/csDefaults.h>
#include <systemenvironment/include/dbg.h>
#include <zcl/include/zclMem.h>

/******************************************************************************
                           Definitions section
******************************************************************************/

#define PROFILE_ID_SMART_ENERGY  CCPU_TO_LE16       (0x0109)
#define PROFILE_ID_CBA CCPU_TO_LE16                 (0x0105)
#define PROFILE_ID_HOME_AUTOMATION CCPU_TO_LE16     (0x0104)
#define PROFILE_ID_LIGHT_LINK CCPU_TO_LE16          (0xc05e)

// Macros defines the maximum size allocated for a value of type OCTET_STRING
#define OCTET_STRING_MAX_SIZE       255
#define LONG_OCTET_STRING_MAX_SIZE  65535


#define ZCL_REQ_INIT_VAL               0x00
#define ZCL_REQ_FLAG_RESP_RCVD         0x01
#define ZCL_REQ_FLAG_CONF_RCVD         0x02
#define ZCL_REQ_RESP_CONF_MASK         (0x02 | 0x01)
#define ZCL_REQ_RESP_RQRD              0x04
#define ZCL_REQ_RESP_RQRD_MASK         0x04
#define ZCL_REQ_DEFAULT_RESP_RQRD      0x08

/** ZCL header consists of
    Frame control - 1 byte
    Manufacturer code - 2(0 for ZCL_IMAGE_BLOCK_RESP)
    Txn seq. Number - 1 byte
    Command ID - 1 byt */
#define ZCL_FRAME_HEADER_SIZE sizeof(ZclFrameHeader_t)
#define ZCL_FRAME_STANDARD_HEADER_SIZE (sizeof(ZclFrameHeader_t) - sizeof(uint16_t))

/** The size of a buffer used by ZCL to receive data

    When ZCL receives a data from APS, it copies the whole data to a buffer.
    Therefore, even when fragmentation is enabled a ZCL buffer should be big
    enough to hold
    the whole packet.
    <b>Value range:</b> 0 to  255 \n
    <b>C-type:</b> uint8_t \n
    <b>Can be set:</b> at compile time only */
#ifndef ZCL_MAX_RX_ZSDU_SIZE
#if ((CS_APS_MAX_BLOCKS_AMOUNT > 1) && ( (CS_APS_MAX_BLOCKS_AMOUNT * CS_APS_RX_BLOCK_SIZE) > \
                                          (APS_MAX_NON_SECURITY_ASDU_SIZE - APS_DATA_EXTENDED_HEADER_LENGTH) ))
  #define ZCL_MAX_RX_ZSDU_SIZE (CS_APS_MAX_BLOCKS_AMOUNT * CS_APS_RX_BLOCK_SIZE)
#else
  #define ZCL_MAX_RX_ZSDU_SIZE (APS_MAX_NON_SECURITY_ASDU_SIZE + NWK_MAX_SOURCE_ROUTE_SUBFRAME_LENGTH)
#endif
#endif


/** The size of a buffer used by ZCL to receive data

    When ZCL transmits a data to APS, it copies the whole data to a buffer.
    Therefore, even when fragmentation is enabled a ZCL buffer should be limited
    to
    hold the maximum possible APS data size
    <b>Value range:</b> 0 to  255 \n
    <b>C-type:</b> uint8_t \n
    <b>Can be set:</b> at compile time only */
#ifndef ZCL_MAX_TX_ZSDU_SIZE
#if ((CS_APS_MAX_BLOCKS_AMOUNT > 1) && ((CS_APS_MAX_BLOCKS_AMOUNT * CS_APS_TX_BLOCK_SIZE) > APS_MAX_ASDU_SIZE))
  #define ZCL_MAX_TX_ZSDU_SIZE (CS_APS_MAX_BLOCKS_AMOUNT * CS_APS_TX_BLOCK_SIZE)
#else
  #define ZCL_MAX_TX_ZSDU_SIZE (APS_MAX_NON_SECURITY_ASDU_SIZE + NWK_MAX_SOURCE_ROUTE_SUBFRAME_LENGTH)
#endif
#endif

#define ZCL_GET_CLUSTER_DIR_MASK   0x01
#define ZCL_GET_CLUSTER_MSP_MASK   0x02

/******************************************************************************
                           Types section
 ******************************************************************************/
 
typedef uint8_t  ZCL_ClusterType_t; // Not used in ZCL
typedef uint16_t ZCL_AttributeId_t; //!< The type for holding attribute IDs
typedef uint8_t  ZCL_CommandId_t; //!< The type for holding ZCL command IDs
typedef uint32_t ZCL_UTCTime_t; //!< The type for defining values of time used in various commands
typedef uint32_t ZCL_Date_t; // Not used in ZCL
typedef uint16_t ZCL_ReportTime_t; //!< The type for setting reporting intervals, in seconds

/** Enumerated status values used in ZCL */
typedef enum PACK
{
  //! Operation was successful.
  ZCL_SUCCESS_STATUS                      = 0x00,
  //!Operation was not successful
  ZCL_FAILURE_STATUS                      = 0x01,

  //0x02 - 0x7d - Reserved
  //! Invalid parameters have been provided
  ZCL_INVALID_ATTRIBUTE_VALUE_STATUS      = 0x02,
  //! Permission table error
  ZCL_TC_PERMISSION_TABLE_ERROR_STATUS    = 0x03,
  //! APS has failed to set the provided link key
  ZCL_APS_LINK_KEY_ERROR_STATUS           = 0x04,
  /*! Not all attributes were successfully written during write attribute request. */
  ZCL_WRITE_ATTRIBUTES_FAILURE_STATUS     = 0x0f,

  //! The sender of the command does not have authorization to carry out this command.
  ZCL_NOT_AUTHORIZED_STATUS               = 0x7e,
  
   /* CCB 2318 a reserved field may be used in the future and then be non-zero
      ZCL_RESERVED_FIELD_NOT_ZERO_STATUS      = 0x7f,*/
  /*! The command appears to contain the wrong fields, as detected either by the
      presence of one or more invalid field entries or by there being missing fields.
      Command not carried out. Implementer has discretion as to whether to return
      this error or ::ZCL_INVALID_FIELD_STATUS. */
  ZCL_MALFORMED_COMMAND_STATUS            = 0x80,
  /*! The specified cluster command is not supported on the device.Command not
      carried out. */
  ZCL_UNSUP_CLUSTER_COMMAND_STATUS        = 0x81,
  /*! The specified general ZCL command is not supported on the device.*/
  ZCL_UNSUP_GENERAL_COMMAND_STATUS        = 0x82,
  /*! A manufacturer-specific unicast, cluster specific command was received
      with an unknown manufacturer code, or the manufacturer code was recognized but
      the command is not supported. */
  ZCL_UNSUP_MANUF_CLUSTER_COMMAND         = 0x83,
  /*! A manufacturer-specific unicast, ZCL specific command was received with an
      unknown manufacturer code, or manufacturer code was recognized but the command
      is not supported. */
  ZCL_UNSUP_MANUF_GENERAL_COMMAND_STATUS  = 0x84,
  /*! At least one field of the command contains an incorrect value, according
      to the specification the device is implemented to. */
  ZCL_INVALID_FIELD_STATUS                = 0x85,
  /*! The specified attribute does not exist on the device. */
  ZCL_UNSUPPORTED_ATTRIBUTE_STATUS        = 0x86,
  /*! Out of range error, or set to a reserved value. Attribute keeps its old
      value. */
  ZCL_INVALID_VALUE_STATUS                = 0x87,
  /*! Attempt to write a read-only attribute. */
  ZCL_READ_ONLY_STATUS                    = 0x88,
  /*! An operation (e.g. an attempt to create an entry in a table) failed due
      to an insufficient amount of free space available.*/
  ZCL_INSUFFICIENT_SPACE_STATUS           = 0x89,
  /*! An attempt to create an entry in a table failed due to a duplicate entry
      already being present in the table. */
  ZCL_DUPLICATE_EXISTS_STATUS             = 0x8a,
  /*! The requested information (e.g. table entry) be found. */
  ZCL_NOT_FOUND_STATUS                    = 0x8b,
  /*! Periodic reports cannot be issued for this attribute. */
  ZCL_UNREPORTABLE_ATTRIBUTE_STATUS       = 0x8c,
  /*! The data type given for an attribute is incorrect. Command not carried out. */
  ZCL_INVALID_DATA_TYPE_STATUS            = 0x8d,
  /*! The selector for an attribute is incorrect. */
  ZCL_INVALID_SELECTOR_STATUS             = 0x8e,
  /*! A request has been made to read an attribute that the requester is not
      authorized to read. No action taken. */
  ZCL_WRITE_ONLY_STATUS                   = 0x8f,
  /*! Setting the requested values would put the device in an inconsistent state
      on startup. No action taken. */
  ZCL_INCONSISTENT_STARTUP_STATE_STATUS   = 0x90,
  /*! An attempt has been made to write an attribute that is present but is
      defined using an out-of-band method and not over the air. */
  ZCL_DEFINED_OUT_OF_BAND_STATUS          = 0x91,
  /*The supplied values (e.g., contents of table cells) are
      inconsistent. */
  ZCL_INCONSISTENT_STATUS                 = 0x92,
  /*The credentials presented by the device sending the
      command are not sufficient to perform this action*/
  ZCL_ACTION_DENIED_STATUS                = 0x93, 
  /*! Indicates that a response command has not been received in time. */  
  ZCL_TIMEOUT_STATUS                      = 0x94,
  /*! Failed case when a otau client or a otau server decides to abort the upgrade process. */
  ZCL_ABORT_STATUS                        = 0x95,
  /*! Invalid OTA upgrade image (ex. failed signature validation or signer information check or CRC check) */
  ZCL_INVALID_IMAGE_STATUS                = 0x96,
  /*! Server does not have data block available yet */
  ZCL_WAIT_FOR_DATA_STATUS                = 0x97,
  /*! No OTA upgrade image available for a particular client */
  ZCL_NO_IMAGE_AVAILABLE_STATUS           = 0x98,
  /*! The client still requires more OTA upgrade image files in order to successfully upgrade */
  ZCL_REQUIRE_MORE_IMAGE_STATUS           = 0x99,
  /*The command has been received and is being processed*/
  ZCL_NOTIFICATION_PENDING_STATUS         = 0x9a,
  //0x97 - 0xbf - Reserved
  /* Request was successfully processed, but application is forcing to reply with DefaultResponse */
  ZCL_SUCCESS_WITH_DEFAULT_RESPONSE_STATUS = 0xAA,

  /*! An operation was unsuccessful due to a hardware failure. */
  ZCL_HARDWARE_FAILURE_STATUS             = 0xc0,
  /*! An operation was unsuccessful due to a software failure. */
  ZCL_SOFTWARE_FAILURE_STATUS             = 0xc1,
  /*! An error occurred during calibration. */
  ZCL_CALIBRATION_ERROR_STATUS            = 0xc2,
  /*The cluster is not supported*/
  ZCL_UNSUP_CLUSTER_STATUS          = 0xc3,
  /* Limit of attribute range reached. Value is trimmed to closest limit (maximum or minimum) */
  ZCL_LIMIT_REACHED_STATUS                = 0xc4,
    
  ZCL_BAD_FRAME_STATUS                    = 0xc5,

  ZCL_WRONG_RESPONSE_LENGTH_STATUS        = 0xc6,
    
  /** The last element has been extracted from the payload, or the payload size
      has been exceeded. Putting/getting payload elements must be finished. */
  ZCL_END_PAYLOAD_REACHED_STATUS          = 0xfd,
  ZCL_MAX_PAYLOAD_REACHED_STATUS          = 0xfe,
  /** The request cannot be processed with parameters passed to the request. */
  ZCL_INVALID_PARAMETER_STATUS            = 0xff,

} ZCL_Status_t;

/** ZigBee data types identifiers
    ZigBee devices, such as thermostats, lamps, etc., are defined in terms of the
    attributes they contain, which can be written, read or reported using
    ZCL commands. The following list defines the data types and formats that
    can be used for these attributes. Note that individual clusters, which may use
    different or new types, show valid values, ranges, and units for the attributes they
    represent.
    Each data type is allocated an 8-bit data type ID. The most significant 5 bits of this
    ID are used to divide the types into 32 type classes, and the least significant 3 bits
    specify a specific data type within this class. */
typedef enum
{
  //Null
  ZCL_NO_DATA_TYPE_ID                       = 0x00,

  //General data
  ZCL_8BIT_DATA_TYPE_ID                     = 0x08,
  ZCL_16BIT_DATA_TYPE_ID                    = 0x09,
  ZCL_24BIT_DATA_TYPE_ID                    = 0x0a,
  ZCL_32BIT_DATA_TYPE_ID                    = 0x0b,
  ZCL_40BIT_DATA_TYPE_ID                    = 0x0c,
  ZCL_48BIT_DATA_TYPE_ID                    = 0x0d,
  ZCL_56BIT_DATA_TYPE_ID                    = 0x0e,
  ZCL_64BIT_DATA_TYPE_ID                    = 0x0f,

  //Logical
  ZCL_BOOLEAN_DATA_TYPE_ID                  = 0x10,

  //Bitmap
  ZCL_8BIT_BITMAP_DATA_TYPE_ID              = 0x18,
  ZCL_16BIT_BITMAP_DATA_TYPE_ID             = 0x19,
  ZCL_24BIT_BITMAP_DATA_TYPE_ID             = 0x1a,
  ZCL_32BIT_BITMAP_DATA_TYPE_ID             = 0x1b,
  ZCL_40BIT_BITMAP_DATA_TYPE_ID             = 0x1c,
  ZCL_48BIT_BITMAP_DATA_TYPE_ID             = 0x1d,
  ZCL_56BIT_BITMAP_DATA_TYPE_ID             = 0x1e,
  ZCL_64BIT_BITMAP_DATA_TYPE_ID             = 0x1f,

  //Unsigned integer
  ZCL_U8BIT_DATA_TYPE_ID                    = 0x20,
  ZCL_U16BIT_DATA_TYPE_ID                   = 0x21,
  ZCL_U24BIT_DATA_TYPE_ID                   = 0x22,
  ZCL_U32BIT_DATA_TYPE_ID                   = 0x23,
  ZCL_U40BIT_DATA_TYPE_ID                   = 0x24,
  ZCL_U48BIT_DATA_TYPE_ID                   = 0x25,
  ZCL_U56BIT_DATA_TYPE_ID                   = 0x26,
  ZCL_U64BIT_DATA_TYPE_ID                   = 0x27,

  //Signed integer
  ZCL_S8BIT_DATA_TYPE_ID                    = 0x28,
  ZCL_S16BIT_DATA_TYPE_ID                   = 0x29,
  ZCL_S24BIT_DATA_TYPE_ID                   = 0x2a,
  ZCL_S32BIT_DATA_TYPE_ID                   = 0x2b,
  ZCL_S40BIT_DATA_TYPE_ID                   = 0x2c,
  ZCL_S48BIT_DATA_TYPE_ID                   = 0x2d,
  ZCL_S56BIT_DATA_TYPE_ID                   = 0x2e,
  ZCL_S64BIT_DATA_TYPE_ID                   = 0x2f,

  //Enumeration
  ZCL_8BIT_ENUM_DATA_TYPE_ID                = 0x30,
  ZCL_16BIT_ENUM_DATA_TYPE_ID               = 0x31,

  //Floating point
  ZCL_FSEMI_PRECISION_DATA_TYPE_ID          = 0x38,
  ZCL_FSINGLE_PRECISION_DATA_TYPE_ID        = 0x39,
  ZCL_FDOUBLE_PRECISION_DATA_TYPE_ID        = 0x3a,

  //String
  ZCL_OCTET_STRING_DATA_TYPE_ID             = 0x41,
  ZCL_CHARACTER_STRING_DATA_TYPE_ID         = 0x42,
  ZCL_LONG_OCTET_STRING_DATA_TYPE_ID        = 0x43,
  ZCL_LONG_CHARACTER_STRING_DATA_TYPE_ID    = 0x44,

  //Ordered sequence
  ZCL_ARRAY_DATA_TYPE_ID                    = 0x48,
  ZCL_STRUCTURE_DATA_TYPE_ID                = 0x4c,

  //Collection
  ZCL_SET_DATA_TYPE_ID                      = 0x50,
  ZCL_BAG_DATA_TYPE_ID                      = 0x51,

  //Time
  ZCL_TIME_OF_DAY_DATA_TYPE_ID              = 0xe0,
  ZCL_DATE_DATA_TYPE_ID                     = 0xe1,
  ZCL_UTC_TIME_DATA_TYPE_ID                 = 0xe2,

  //Identifier
  ZCL_CLUSTER_ID_DATA_TYPE_ID               = 0xe8,
  ZCL_ATTRIBUTE_ID_DATA_TYPE_ID             = 0xe9,
  ZCL_BACNET_OID_DATA_TYPE_ID               = 0xea,

  //Misscellaneous
  ZCL_IEEE_ADDRESS_DATA_TYPE_ID             = 0xf0,
  ZCL_128BIT_SECURITY_KEY_DATA_TYPE_ID      = 0xf1,
} ZCL_AttributeType_t;

/** The list of general ZCL commands */
typedef enum
{
  /** Reading particular attributes' values from a remote device */
  ZCL_READ_ATTRIBUTES_COMMAND_ID                            = 0x00,
  ZCL_READ_ATTRIBUTES_RESPONSE_COMMAND_ID                   = 0x01,

/** Write attributes */
  /** Modifying values of particular attributes on a remote device */
  ZCL_WRITE_ATTRIBUTES_COMMAND_ID                           = 0x02,
  ZCL_WRITE_ATTRIBUTES_UNDIVIDED_COMMAND_ID                 = 0x03,
  ZCL_WRITE_ATTRIBUTES_RESPONSE_COMMAND_ID                  = 0x04,
  ZCL_WRITE_ATTRIBUTES_NO_RESPONSE_COMMAND_ID               = 0x05,

/** Configure reporting */
  ZCL_CONFIGURE_REPORTING_COMMAND_ID                        = 0x06,
  ZCL_CONFIGURE_REPORTING_RESPONSE_COMMAND_ID               = 0x07,

/** Read reporting */
  ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID               = 0x08,
  ZCL_READ_REPORTING_CONFIGURATION_RESPONSE_COMMAND_ID      = 0x09,

/** Report attributes */
  /** Reporting particular attributes to a remote device; that is,
  sending current attributes' values */
  ZCL_REPORT_ATTRIBUTES_COMMAND_ID                          = 0x0a,

/** Default response */
  ZCL_DEFAULT_RESPONSE_COMMAND_ID                           = 0x0b,

/** Discover attributes */
  /** Obtaining information (IDs and types) of attributes supported
  by a particular cluster on a remote device */
  ZCL_DISCOVER_ATTRIBUTES_COMMAND_ID                        = 0x0c,
  ZCL_DISCOVER_ATTRIBUTES_RESPONSE_COMMAND_ID               = 0x0d,

/** Read attributes structured */
  ZCL_READ_ATTRIBUTES_STRUCTURED_COMMAND_ID                 = 0x0e,

/** Write attributes structured */
  ZCL_WRITE_ATTRIBUTES_STRUCTURED_COMMAND_ID                = 0x0f,
  ZCL_WRITE_ATTRIBUTES_STRUCTURED_RESPONSE_COMMAND_ID       = 0x10,

/** Discover commands received */
  ZCL_DISCOVER_COMMANDS_RECEIVED_COMMAND_ID                 = 0x11,
  ZCL_DISCOVER_COMMANDS_RECEIVED_RESPONSE_COMMAND_ID        = 0x12,

/** Discover commands generated */
  ZCL_DISCOVER_COMMANDS_GENERATED_COMMAND_ID                = 0x13,
  ZCL_DISCOVER_COMMANDS_GENERATED_RESPONSE_COMMAND_ID       = 0x14,

/** Discover Attributes extended */
  ZCL_DISCOVER_ATTRIBUTES_EXTENDED_COMMAND_ID               = 0x15,
  ZCL_DISCOVER_ATTRIBUTES_EXTENDED_RESPONSE_COMMAND_ID      = 0x16

} ZCL_GeneralCommandId_t;

/** Type describing possible ZSE Device IDs */
typedef enum
{
  /*! The Range Extender is a simple device that acts as a router for other devices. The
      Range Extender device shall not be a ZigBee end device. A product that
      implements the Range Extender device shall not implement any other devices
      defined in this profile. This device shall only be used if the product is not intended
      to have any other application, or if a private application is implemented that has
      not been addressed by this profile.*/
  ZSE_RANGE_EXTENDER_DEVICE_ID                          = 0x0008,
  /*! The Energy Service Portal connects the energy supply company communication
      network to the metering and energy management devices within the home. It
      routes messages to and from the relevant end points. It may be installed within a
      meter, thermostat, or In-Premise Display, or may be a standalone device, and it
      will contain another non-ZigBee communication module (e.g. power-line carrier,
      RF, GPRS, broadband Internet connection).*/
  ZSE_ENERGY_SERVICE_INTERFACE_DEVICE_ID                = 0x0500,
  /*!The Metering end device is a meter (electricity, gas, water, heat, etc.) that is fitted
      with a ZigBee device. Depending on what is being metered, the device may be
      capable of immediate (requested) reads or it will autonomously send readings
      periodically. A Metering end device may also be capable of communicating
      certain status indicators (e.g. battery low, tamper detected).*/
  ZSE_METERING_DEVICE_DEVICE_ID                         = 0x0501,
  /*! The In-Premise Display device will relay energy consumption data to the user by
      way of a graphical or text display. The display may or may not be an interactive
      device. At a minimum at least one of the following should be displayed: current
      energy usage, a history over selectable periods, pricing information, or text
      messages. As an interactive device, it can be used for returning simple messages
      for interpretation by the recipient.*/
  ZSE_IN_PREMISE_DISPLAY_DEVICE_ID                      = 0x0502,
  /*! The PCT device shall provide the capability to control the premise heating and
      cooling systems.*/
  ZSE_PROGRAMMABLE_COMMUNICATING_THERMOSTAT_DEVICE_ID   = 0x0503,
  /*! The Load Control device is capable of receiving Demand Response and Load
      Control events to manage consumption on a range of devices. Example devices
      are water heaters, exterior lighting, and pool pumps.*/
  ZSE_LOAD_CONTROL_DEVICE_DEVICE_ID                     = 0x0504,
  /*! Smart Appliance devices on the ZigBee network can participate in energy
      management activities. Examples of these are when Utilities initiate a demand
      response or pricing event, or the appliance actively informs customers via inhome
      displays of when or how energy is being used. In the latter case, scenarios
      include: Washer switching to cold water during periods of higher energy costs;
      Washer/Dryer/Oven/Hot Water Heater reporting cycle status;
      Over temperature conditions in Freezers and Refrigerators.*/
  ZSE_SMART_APPLIANCE_DEVICE_ID                         = 0x0505,
  /*! The Prepayment Terminal device will allow utility customers or other users (e.g.
      sub-metered tenants) to pay for consumption in discrete increments rather than
      establishing a traditional billing agreement. The Prepayment Terminal device will
      accept payment (e.g. credit card, code entry), display remaining balances, and
      alert the user of a balance approaching zero, and may perform some or all of the
      other functions described in In-Premise Display.*/
  ZSE_PREPAYMENT_TERMINAL_DEVICE_ID                     = 0x0506,
  /*! The Physical Device type will identify a supplemental (or sole) endpoint on which
      the clusters related to a physical product may reside. The endpoint shall not
      contain any cluster related to any individual logical SE device on the physical
      product. A product is allowed to have a Physical Device as its sole SE endpoint. A
      Physical Device must be capable of providing other SE device endpoints to be a
      certified SE product.*/
  ZSE_PHYSICAL_DEVICE_ID                                = 0x0507,
} ZSE_DeviceId_t;


/** Type describing possible HA device IDs */
typedef enum
{
  /*! The Remote Control device is capable of controlling and monitoring other
      devices. Typically the Remote Control device is a handheld, battery powered device, that
      can control devices (for example, turn a light on/off), monitor devices (for
      example, read the status of a temperature sensor) or do some user configuration
      (for example, change the setpoint of a thermostat or a light sensor). */
  HA_REMOTE_CONTROL_DEVICE_ID                           = 0x0006,
  /*! The Combined Interface device is capable of controlling and monitoring other
      devices. It is typically a mains-powered device like a personal computer. */
  HA_COMBINED_INTERFACE_ID                              = 0x0007,
  /*! The On/Off Light device is a light that can be switched on and off. */
  HA_ON_OFF_LIGHT_DEVICE_ID                             = 0x0100,
  /*! The Dimmable Light device is a light that can be switched on and off, and whose
      luminance level may be controlled. */
  HA_DIMMABLE_LIGHT_DEVICE_ID                           = 0x0101,
  /*! The On/Off Light Switch device can send on, off and toggle commands to devices
      (typically lights) to switch them on or off. */
  HA_ON_OFF_LIGHT_SWITCH_DEVICE_ID                      = 0x0103,
  /*! The Dimmer Switch device can send on, off and toggle commands to devices
      (typically lights) to switch them on or off, and can also control the level of a
      characteristic of such devices (typically the brightness of lights). */
  HA_DIMMER_SWITCH_DEVICE_ID                            = 0x0104,
  /*! The Light Sensor device reports the illuminance of an area. */
  HA_LIGHT_SENSOR_DEVICE_ID                             = 0x0106,
  /*! The Occupancy Sensor device reports the occupancy state of an area. */
  HA_OCCUPANCY_SENSOR_DEVICE_ID                         = 0x0107,
  /*! The Thermostat device can have either built-in or separate sensors for
      temperature, humidity or occupancy. It allows the desired temperature to be set
      either remotely or locally. The thermostat may send heating and/or cooling
      requirement notifications to a heating/cooling unit (for example, an indoor air
      handler) or may include a mechanism to control a heating or cooling unit directly. */
  HA_THERMOSTAT_DEVICE_ID                               = 0x0301,
  /*! Temperature Sensor Device Id */
  HA_TEMPERATURE_SENSOR_DEVICE_ID                       = 0x0302,
  /*! IAS Control and Indicating Equipment */
  HA_IAS_CIE_DEVICE_ID                                  = 0x0400,
  /*! IAS Ancillary Control Equipment */
  HA_IAS_ACE_DEVICE_ID                                  = 0x0401,
  /*! IAS Zone */
  HA_IAS_ZONE_DEVICE_ID                                 = 0x0402,
  /*! IAS Warning Device */
  HA_IAS_WD_DEVICE_ID                                   = 0x0403
} HA_DeviceId_t;

/** Type describing possible ZLL device IDs */
typedef enum
{
  /*! On/Off Light */
  ZLL_ON_OFF_LIGHT_DEVICE_ID                            = 0x0000,
  /*! On/off plug-in unit */
  ZLL_ON_OFF_PLUGIN_UNIT_DEVICE_ID                      = 0x0010,
  /*! Dimmable light */
  ZLL_DIMMABLE_LIGHT_DEVICE_ID                          = 0x0100,
  /*! Dimmable plug-in unit */
  ZLL_DIMMABLE_PLUGIN_UNIT_DEVICE_ID                    = 0x0110,
  /*! Color light */
  ZLL_COLOR_LIGHT_DEVICE_ID                             = 0x0200,
  /*! Extended color light */
  ZLL_EXTENDED_COLOR_LIGHT_DEVICE_ID                    = 0x0210,
  /*! Temperature color light */
  ZLL_TEMPERATURE_COLOR_LIGHT_DEVICE_ID                 = 0x0220,
  /*! Color remote */
  ZLL_COLOR_REMOTE_DEVICE_ID                            = 0x0800,
  /*! Color scene remote */
  ZLL_COLOR_SCENE_REMOTE_DEVICE_ID                      = 0x0810,
  /*! Non-color remote */
  ZLL_NON_COLOR_REMOTE_DEVICE_ID                        = 0x0820,
  /*! Non-color scene remote */
  ZLL_NON_COLOR_SCENE_REMOTE_DEVICE_ID                  = 0x0830,
  /*! Control bridge */
  ZLL_CONTROL_BRIDGE_DEVICE_ID                          = 0x0840,
  /*! On/off sensor */
  ZLL_ON_OFF_SENSOR_DEVICE_ID                           = 0x0850,
} ZLL_DeviceId_t;

/** Type describing possible ZGP device IDs */
typedef enum
{
  /*! GP advanced proxy */
  GP_PROXY_DEVICE_ID                                    = 0x0060,
  /*! GP  proxy basic*/
  GP_PROXY_BASIC_DEVICE_ID                              = 0x0061,
  /*! GP sink */
  GP_TARGET_PLUS_DEVICE_ID                              = 0x0062,
  /*! GP sink basic */
  GP_TARGET_DEVICE_ID                                   = 0x0063,
  /*! GP commissioning tool */
  GP_COMMISSIONING_TOOL_DEVICE_ID                       = 0x0064,
  /*! GP combo(sink & proxy) */
  GP_COMBO_DEVICE_ID                                    = 0x0065,
  /*! GP combo basic */
  GP_COMBO_BASIC_DEVICE_ID                              = 0x0066,
} GP_DeviceId_t;

/** Type describing possible ZLO device IDs */
typedef enum
{
  /**! On/Off Light */
  ZLO_ON_OFF_LIGHT_DEVICE_ID                            = 0x0100,
  /*! Dimmable Light */
  ZLO_DIMMABLE_LIGHT_DEVICE_ID                          = 0x0101,
  /*! Color Dimmable Light */
  ZLO_COLOR_DIMMABLE_LIGHT_DEVICE_ID                    = 0x0102,
  /*! On/Off Light Switch */
  ZLO_ON_OFF_LIGHT_SWITCH_DEVICE_ID                     = 0x0103,
  /*! Dimmer Switch */
  ZLO_DIMMER_SWITCH_DEVICE_ID                           = 0x0104,
  /*! Color Dimmer Switch */
  ZLO_COLOR_DIMMER_SWITCH_DEVICE_ID                     = 0x0105,
  /*! Light Sensor */
  ZLO_LIGHT_SENSOR_DEVICE_ID                            = 0x0106,
  /*! Occupancy Sensor */
  ZLO_OCCUPANCY_SENSOR_DEVICE_ID                        = 0x0107,
  /**! On/Off Ballast */
  ZLO_ON_OFF_BALLAST_DEVICE_ID                          = 0x0108,
  /**! Dimmable Ballast */
  ZLO_DIMMABLE_BALLAST_DEVICE_ID                        = 0x0109,
  /*! On/off Plug-in unit */
  ZLO_ON_OFF_PLUG_IN_UNIT_DEVICE_ID                     = 0x010A,
  /*! Dimmable Plug-in unit */
  ZLO_DIMMABLE_PLUG_IN_UNIT_DEVICE_ID                   = 0x010B,
  /*! Color Temperature light */
  ZLO_COLOR_TEMPERATURE_LIGHT_DEVICE_ID                 = 0x010C,
  /*! Extended Color light */
  ZLO_EXTENDED_COLOR_LIGHT_DEVICE_ID                    = 0x010D,
  /*! Light level Sensor */
  ZLO_LIGHT_LEVEL_SENSOR_DEVICE_ID                      = 0x010E,
  /*! Color Controller */
  ZLO_COLOR_CONTROLLER_DEVICE_ID                        = 0x0800,
  /*! Color Scene Controller */
  ZLO_COLOR_SCENE_CONTROLLER_DEVICE_ID                  = 0x0810,
  /*! Non Color Controller */
  ZLO_NON_COLOR_CONTROLLER_DEVICE_ID                    = 0x0820,
  /*! Non Color Scene Controller */
  ZLO_NON_COLOR_SCENE_CONTROLLER_DEVICE_ID              = 0x0830,
  /*! Control Bridge */
  ZLO_CONTROL_BRIDGE_DEVICE_ID                          = 0x0840,
  /*! On/off Sensor */
  ZLO_ON_OFF_SENSOR_DEVICE_ID                           = 0x0850,
    /*! ias_ace device id  */
  ZLO_IAS_ACE_DEVICE_ID                                 = 0x0401,
    /*! custom device id  */
  ZLO_CUSTOM_DEVICE_ID                                  = 0x0F00,  
  /*! Shade Device */
  ZLO_SHADE_DEVICE_ID                                   = 0x0200,
  /*! Shade Controller */
  ZLO_SHADE_CONTROLLER_DEVICE_ID                        = 0x0201,
  /*! Window Covering Device */
  ZLO_WINDOW_COVERING_DEVICE_ID                         = 0x0202,
  /*! Window Covering Controller */
  ZLO_WINDOW_COVERING_CONTROLLER_DEVICE_ID              = 0x0203,
} ZLO_DeviceId_t;

/** ZCL events' IDs */
typedef enum
{
  ZCL_ATTRIBUTE_READ_EVENT_ID,      //!< Attribute read event
  ZCL_ATTRIBUTE_WRITE_EVENT_ID,     //!< Attribute write event
} ZCL_EventId_t;

/** ZCL notifications' IDs */
typedef enum
{
  ZCL_APS_CONFIRM_ID,      //!< request was sent and transport acknowledgment was received
  ZCL_ZCL_RESPONSE_ID,     //!< zcl response was received
  ZCL_DEFAULT_RESPONSE_ID  //!< zcl default response was received
} ZCL_NotifyId_t;

/** Reserved type to organize the queue of ZCL requests */
typedef struct
{
  void    *next;
  uint8_t requestType;
  uint8_t statusflags;     //!< zcl request flags
} ZCL_Service_t;

/** Type describing address fields of some attributes in ZCL */
typedef struct
{
  APS_AddrMode_t      addrMode;     //!< Address mode indicates which type of address shall be used
  APS_Address_t       addr;         //!< Can be set to either short, extended, or group addresses, depending on the address mode
  ProfileId_t         profileId;    //!< Profile ID
  Endpoint_t          endpointId;   //!< Endpoint ID
  ClusterId_t         clusterId;    //!< Cluster ID
  uint8_t             clusterSide;  //!< Cluster's side: server or client
  uint16_t            manufacturerSpecCode; //!< Manufacturer-specific code
  uint8_t             sequenceNumber; //!< ZCL sequence number
#ifdef _GREENPOWER_SUPPORT_
  ShortAddr_t         aliasSrcAddr;   //!< Green power alias addr
  NwkSequenceNumber_t aliasSeqNumber; //!< Green power alias seq no
  uint8_t             radius;         //!< Groupcast radius
  APS_AddrMode_t      indDstAddrMode;    //!< destination address mode
  APS_Address_t       indDstAddr;        //!< destination address
#endif
  bool                nonUnicast;   //!< Received request is not a unicast one
} ZCL_Addressing_t;

/** Type describing ZCL Cluster options */
typedef struct
{
  uint8_t type        : 1;
  uint8_t security    : 1;
#ifdef _CUSTOM_ZCL_MSP_SUPPORT_
  uint8_t mspCluster  : 1; //!< manufacturer specific profile cluster - co exist with std cluster
  uint8_t reserved    : 5;
#else
  uint8_t reserved    : 6;
#endif
} ZCL_ClusterOptions_t;

/** Type describing ZCL's events on cluster's attribute */
typedef enum
{
  ZCL_READ_ATTRIBUTE_EVENT,
  ZCL_WRITE_ATTRIBUTE_EVENT,
  ZCL_CONFIGURE_ATTRIBUTE_REPORTING_EVENT,
  ZCL_CONFIGURED_ATTRIBUTE_REPORTING_NOTIFICATION_EVENT,
  ZCL_CONFIGURE_DEFAULT_ATTRIBUTE_REPORTING_EVENT
} ZCL_AttributeEvent_t;

/** Type describing information which is necessary for put/get element to/from     payload */
typedef struct
{
  uint8_t id; //!< Element's ID. Can be either ::ZCL_GeneralCommandId_t value or a special cluster command ID
  uint8_t payloadLength; //!< Payload's length after adding of a new element
  uint8_t *payload; //!< Payload's pointer to the place where an element is added
  void    *content; //!< Pointer to content (memory) which shall be added/filled to/from the payload
} ZCL_NextElement_t;

/** Type describing ZCL response */
typedef struct
{
  ZCL_Status_t          status;          //!< status of command
  ZCL_NotifyId_t        id;              //!< id of notification
  ZCL_Addressing_t     *addressing;      //!< sender addressing (ZCL response case)
  uint8_t               responseLength;  //!< length of response payload
  uint8_t              *responsePayload; //!< pointer to response payload. Response payload can be parsed by ZCL_GetNextElement() function
} ZCL_Notify_t;

/** Type for setting parameters of a ZCL command sent via ZCL_CommandReq() of
    ZCL_AttributeReq() */
typedef void (*Notify)(ZCL_Notify_t *ntfy);

typedef struct
{
  // Service structure - for internal use
  ZCL_Service_t       service;
  ZCL_Notify_t        notify;                        //!< Response structure
  Notify              ZCL_Notify;                    //!< Callback function for response. Can be set to NULL.
  ZCL_Addressing_t    dstAddressing;                 //!< Addressing info on a destination node
  Endpoint_t          endpointId;                    //!< Endpoint ID of the request's originator
  uint8_t             id;                            //!< Command ID
  uint8_t             requestLength;                 //!< Request's payload length
  uint8_t             defaultResponse;               //!< Default response bit state
  uint8_t             *requestPayload;               //!< Request payload. Can be filled by the ZCL_PutNextElement() function.
  uint32_t            responseWaitTimeout;           //!< response waiting timeout
} ZCL_Request_t;

/** Type describing ZCL Cluster */
typedef struct
{
  ClusterId_t          id;                 //!< Cluster ID
  ZCL_ClusterOptions_t options;
  uint8_t              attributesAmount;   //!< Number of cluster attributes
  uint8_t             *attributes;         //!< Cluster attribute descriptors
  uint8_t              commandsAmount;     //!< Number of cluster-specific commands
  uint8_t             *commands;           //!< Cluster-specific command descriptors
  uint8_t              isReporting;        //!< Service field - indicates if any automatic attribute reports are in progress
  //! Callback on Report attributes command reception. Can be set to NULL.
  void (*ZCL_ReportInd)(ZCL_Addressing_t *addressing, uint8_t reportLength, uint8_t *reportPayload);
  //! Callback on Default response command reception. Can be set to NULL.
  void (*ZCL_DefaultRespInd)(ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
  //! Callback indicates action on cluster's attribute. Can be set to NULL.
  void (*ZCL_AttributeEventInd)(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);
} ZCL_Cluster_t;

#if APP_CLUSTERS_IN_FLASH == 1
/** Type describing image of immutable part separate ZCL cluster */
typedef struct
{
  ClusterId_t          id;                 //!< Cluster ID
  ZCL_ClusterOptions_t options;
  uint8_t              attributesAmount;   //!< Number of cluster attributes
  uint8_t             *attributes;         //!< Cluster attribute descriptors
  uint8_t              commandsAmount;     //!< Number of cluster-specific commands
  uint8_t             *commands;           //!< Cluster-specific command descriptors
} ZCL_ClusterPartFlashImage_t;

/** Type describing progmem immutable part separate ZCL cluster */
typedef PROGMEM_DECLARE(struct
{
  ClusterId_t          id;                 //!< Cluster ID
  ZCL_ClusterOptions_t options;
  uint8_t              attributesAmount;   //!< Number of cluster attributes
  uint8_t             *attributes;         //!< Cluster attribute descriptors
  uint8_t              commandsAmount;     //!< Number of cluster-specific commands
  FLASH_PTR uint8_t   *commands;           //!< Cluster-specific command descriptors
})ZCL_ClusterPartFlash_t;

/** Type describing mutable part separate ZCL cluster */
typedef struct
{
  uint8_t           isReporting;        //!< Service field - if any automatic attribute reports are in progress
  void (*ZCL_ReportInd)(ZCL_Addressing_t *addressing, uint8_t reportLength, uint8_t *reportPayload); //!< Callback on Report attributes command reception
  void (*ZCL_DefaultRespInd)(ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload); //!< Callback on Default response command reception
  void (*ZCL_AttributeEventInd)(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event); //!< Callback indicates action on cluster's attribute
} ZCL_ClusterPartRam_t;
#endif //APP_CLUSTERS_IN_FLASH == 1

BEGIN_PACK
/** ZCL Cluster attribute descriptor */
typedef struct PACK
{
  ZCL_AttributeId_t id;               //!< Attribute ID
  uint8_t           type;             //!< Attribute data type
  uint8_t           properties;       //!< Attribute properties bitmask
  uint8_t           value[1];         //!< Immediate attribute value
} ZclAttribute_t;

/** Type describing payload element of read request command.
    This type can be used to add one attribute entry to the read request payload. */
typedef struct PACK
{
  ZCL_AttributeId_t id; //!< Requested attribute id
} ZCL_ReadAttributeReq_t;

/** Types describing payload element of read attributes structured command. */
typedef struct PACK
{
  uint8_t indicator;          //!< indicator field for obtaining required element
  uint16_t index[1];          //!< array of index fields (path to element)
} ZCL_Selector_t;

/** Types describing payload element of read attributes structured command. */
typedef struct PACK
{
  ZCL_AttributeId_t id;       //!< requested attribute id
  ZCL_Selector_t selector;    //!< attribute selector
} ZCL_ReadAttributesStructuredReq_t;

/** Type describing payload element of response to read request command
    This type can be used to get one attribute entry from the read response payload. */
typedef struct PACK
{
  ZCL_AttributeId_t id;       //!< requested attribute id
  uint8_t           status;   //!< status of reading attribute operation
  uint8_t           type;     //!< requested attribute type
  uint8_t           value[1]; //!< requested attribute value
} ZCL_ReadAttributeResp_t;

/** Type describing payload element of write request commands.
    This type can be used to add one attribute entry to the write request payload. */
typedef struct PACK
{
  ZCL_AttributeId_t id;       //!< requested attribute id
  uint8_t           type;     //!< requested attribute type
  uint8_t           value[1]; //!< requested attribute value
} ZCL_WriteAttributeReq_t;

/**  Type describing payload element of write attribute no response request command. This type can be used to add one attribute entry to the write request payload. */
typedef struct PACK
{
  ZCL_AttributeId_t id;       //!< requested attribute id
  uint8_t           type;     //!< requested attribute type
  uint8_t           value[1]; //!< requested attribute value
} ZCL_WriteAttributeNoResponseReq_t;

/** Type describing payload element of response to write request command.
    This type can be used to get next writing status from the write response payload. */
typedef struct PACK
{
  uint8_t           status; //!< status of writing attribute operation
  ZCL_AttributeId_t id;     //!< requested attribute id
} ZCL_WriteAttributeResp_t;

/** Type describing payload element of configure report request command.This type can be used to add one reporting record to the "configure report" request payload. */
typedef struct PACK
{
  /*! The direction field specifies whether values of the attribute are be reported (0x00),
      or whether reports of the attribute are to be received (0x01).*/
  uint8_t direction;
  /*! If the direction field is 0x00, this field contains the identifier of the attribute
      to be reported. If, instead, the direction field is 0x01,
      the device shall expect reports of values of this attribute.*/
  ZCL_AttributeId_t attributeId;
  union PACK
  {
    struct PACK
    {
      /*! The attribute data type field contains the data type of the attribute
          that is to be reported.*/
      uint8_t attributeType;
      /*! The minimum reporting interval field is 16 bits in length and shall contain
        the minimum interval, in seconds, between issuing reports of the specified attribute.*/
      ZCL_ReportTime_t minReportingInterval;
      /*! The maximum reporting interval field is 16 bits in length and
          shall contain the maximum interval, in seconds, between issuing reports
          of the specified attribute.*/
      ZCL_ReportTime_t maxReportingInterval;
      /*! The reportable change field shall contain the minimum change to the attribute
          that will result in a report being issued. This field is of variable length.
          For attributes with 'analog' data type the field has the same data type
          as the attribute.*/
      uint8_t reportableChange[1];
    };
    /*! The timeout period field is 16 bits in length and shall contain the maximum
        expected time, in seconds, between received reports for the attribute specified
        in the attribute ID field. If more time than this elapses between reports,
        this may be an indication that there is a problem with reporting.
        If this value is set to 0x0000, reports of the attribute are not subject to timeout.*/
    ZCL_ReportTime_t timeoutPeriod;
  };
} ZCL_ConfigureReportingReq_t;

/** Type describing payload element of response to configure report request command.This type can be used to get next status entry from the "configure report" response payload. */
typedef struct PACK
{
  uint8_t           status;    //!< Status of the configure reporting operation
  uint8_t           direction; //!< The direction field specifies whether values of the attribute are be reported (0x00), or whether reports of the attribute are to be received (0x01).
  ZCL_AttributeId_t attributeId;        //!< Requested attribute's ID
} ZCL_ConfigureReportingResp_t;

/** Type describing payload element of ZCL Read Reporting Configuration command. */
typedef struct PACK
{
  uint8_t           direction;    //!< The direction field specifies whether values of the attribute are be reported (0x00), or whether reports of the attribute are to be received (0x01).
  ZCL_AttributeId_t attributeId;  //!< requested attribute identifier
} ZCL_ReadReportingConfigurationReq_t;

/** Type describing payload element of ZCL Read Reporting Configuration Response command. */
typedef struct PACK
{
  /*! If the attribute is not implemented on the sender or receiver of the command,
     whichever is relevant (depending on direction), this field shall be set
     to UNSUPPORTED_ATTRIBUTE. If the attribute is supported, but is not capable of
     being reported, this field shall be set to UNREPORTABLE_ATTRIBUTE.
     Otherwise, this field shall be set to SUCCESS.*/
  uint8_t             status;
  /*! The direction field specifies whether values of the attribute are reported (0x00),
     or whether reports of the attribute are received (0x01).*/
  uint8_t             direction;
  /*! If the direction field is 0x00, this field contains the identifier of the attribute
     that is to be reported. If instead the direction field is 0x01,
     the device shall expect reports of values of this attribute.*/
  ZCL_AttributeId_t   attributeId;
  union PACK
  {
    struct PACK
    {
      /*! The Attribute data type field contains the data type of the attribute
        that is to be reported.*/
      uint8_t          attributeType;
      /*! The minimum reporting interval field is 16 bits in length and shall contain
        the minimum interval, in seconds, between issuing reports of the specified attribute.*/
      ZCL_ReportTime_t minReportingInterval;
      /*! The maximum reporting interval field is 16 bits in length and
        shall contain the maximum interval, in seconds, between issuing reports
        of the specified attribute.*/
      ZCL_ReportTime_t maxReportingInterval;
      /*! The reportable change field shall contain the minimum change to the attribute
        that will result in a report being issued. This field is of variable length.
        For attributes with 'analog' data type the field has the same data type
        as the attribute.*/
      uint8_t          reportableChange[1];
    };
    /*! The timeout period field is 16 bits in length and shall contain the maximum
        expected time, in seconds, between received reports for the attribute specified
        in the attribute ID field. If more time than this elapses between reports,
        this may be an indication that there is a problem with reporting.
        If this value is set to 0x0000, reports of the attribute are not subject to timeout.*/
    ZCL_ReportTime_t  timeoutPeriod;
  };
} ZCL_ReadReportingConfigurationResp_t;

/** Type describing payload element of report command. 
    This type can be used to get next reported attribute from the report payload. */
typedef struct PACK
{
  ZCL_AttributeId_t id;       //!< requested attribute id
  uint8_t           type;     //!< requested attribute type
  uint8_t           value[2]; //!< requested attribute value
} ZCL_Report_t;

/** Type describing payload of ZCL Default Response Command. */
typedef struct PACK
{
  /*! The command identifier field is 8-bit in length and specifies the identifier
      of the received command to which this command is a response.*/
  uint8_t           commandId;
  /*! The status code field is 8-bit in length and specifies either SUCCESS or
      the nature of the error that was detected in the receive command.*/
  uint8_t           statusCode;
} ZCL_DefaultResp_t;

/** Type describing payload of ZCL Discovery Attributes Command. */
typedef struct PACK
{
  /*! The start attribute identifier field is 16-bit in length and specifies
      the ID of the attribute from which to begin attribute discovery.*/
  ZCL_AttributeId_t startAttributeId;
  /*! The maximum attribute IDs field is 8-bit in length and specifies
      the maximum number of attribute IDs that should be returned in the
      resulting discovery attributes response command.*/
  uint8_t           maxAttributeIds;
} ZCL_DiscoverAttributesReq_t;

/** Type describing payload the Attribute Report field of ZCL Discovery
       Attributes Response Command. */
typedef struct PACK
{
  ZCL_AttributeId_t attributeId;  //!< Attribute ID
  uint8_t           typeId;       //!< Attribute's data type ID
} ZCL_DiscoverAttributesRespRec_t;

/** Type describing payload of ZCL Discovery Attributes Response Command. */
typedef struct PACK
{
  /*! A value of 0 indicates that there are some more attributes to be discovered.
      A value of 1 indicates that there are no more attributes to be discovered.*/
  uint8_t                           discoveryComplete;
  /*! Discovered attribute information*/
  ZCL_DiscoverAttributesRespRec_t   attributeInfo[1];
} ZCL_DiscoverAttributesResp_t;

/** Type describing payload of ZCL Discover Commands Received Command. */
typedef struct PACK
{
  /*! The start command identifier field is 8-bit in length and specifies
      the ID of the command from which to begin command received discovery.*/
  ZCL_CommandId_t startCommandId;
  /*! The maximum Command IDs field is 8-bit in length and specifies
      the maximum number of command IDs that should be returned in the
      resulting discover commands received response command.*/
  uint8_t         maxCommandIds;
} ZCL_DiscoverCommandsReceivedReq_t;

/** Type describing payload of ZCL Discover Commands Received response Command. */
typedef struct PACK
{
  /*! A value of 0 indicates that there are some more commands to be discovered.
      A value of 1 indicates that there are no more commands to be discovered.*/
  uint8_t    discoveryComplete;
  /*! The list of command IDs each 8-bit in length and specifies
      the maximum number of command IDs that should be returned in the
      resulting discover commands received response command.*/
  uint8_t    commandIds[1];
} ZCL_DiscoverCommandsReceivedResp_t;

/** Type describing payload of ZCL Discover Commands Generated Command. */
typedef struct PACK
{
  /*! The start command identifier field is 8-bit in length and specifies
      the ID of the command from which to begin command received discovery.*/
  ZCL_CommandId_t startCommandId;
  /*! The maximum Command IDs field is 8-bit in length and specifies
      the maximum number of command IDs that should be returned in the
      resulting discover commands generated response command.*/
  uint8_t         maxCommandIds;
} ZCL_DiscoverCommandsGeneratedReq_t;

/** Type describing payload of ZCL Discover Commands Generated response Command. */
typedef struct PACK
{
  /*! A value of 0 indicates that there are some more commands to be discovered.
      A value of 1 indicates that there are no more commands to be discovered.*/
  uint8_t  discoveryComplete;
  /*! The list of command IDs each 8-bit in length and specifies
      the maximum number of command IDs that should be returned in the
      resulting discover commands generated response command.*/
  uint8_t  commandIds[1];
} ZCL_DiscoverCommandsGeneratedResp_t;

/** Type describing payload of ZCL Discovery Attributes Extended Command. */
typedef struct PACK
{
  /*! The start attribute identifier field is 16-bit in length and specifies
      the ID of the attribute from which to begin attribute extended discovery.*/
  ZCL_AttributeId_t startAttributeId;
  /*! The maximum attribute IDs field is 8-bit in length and specifies
      the maximum number of attribute IDs that should be returned in the
      resulting discover attributes extended response command.*/
  uint8_t           maxAttributeIds;
} ZCL_DiscoverAttributesExtendedReq_t;

/** Type describing access control sub field of the attribute information fields
       of ZCL Discovery Attributes Extended Response Command. */
typedef struct PACK
{
  uint8_t readable   :1;
  uint8_t writeable  :1;
  uint8_t reportable :1;
} ZCL_AttributeAccessCtrl_t;

/** Type describing payload the Attribute information fields of ZCL Discovery
    Attributes Extended Response Command. */
typedef struct PACK
{
  ZCL_AttributeId_t         attributeId;  //!< Attribute ID
  uint8_t                   typeId;       //!< Attribute's data type ID
  ZCL_AttributeAccessCtrl_t accessCtrrl;  //!< Attribute's accessability
} ZCL_DiscoverAttributesExtendedRespRec_t;

/** Type describing payload of ZCL Discovery Attributes Extended Response Command. */
typedef struct PACK
{
  /*! A value of 0 indicates that there are some more attributes to be discovered.
      A value of 1 indicates that there are no more attributes to be discovered.*/
  uint8_t                                   discoveryComplete;
  /*! Discovered attribute information*/
  ZCL_DiscoverAttributesExtendedRespRec_t   attributeInfo[1];
} ZCL_DiscoverAttributesExtendedResp_t;

END_PACK

/** Type describing attribute events notifications */
typedef struct
{
  ZCL_Addressing_t   addressing;        //!< Source addressing, source endpoint, destination cluster
  uint8_t            attributeId;       //!< Attribute ID
} ZCL_AttributeEventNtfy_t;

/** Type describing parameter of the ZCL_EventNtfy() function */
typedef struct
{
  ZCL_EventId_t       eventId;         //!< Avent ID (e.g. ::ZCL_ATTRIBUTE_READ_EVENT_ID)
  union
  {
    ZCL_AttributeEventNtfy_t   attribute;  //!< Attribute event
  } eventType;
} ZCL_EventNtfy_t;

/** Type describing parameter of ZCL_RegisterEndpoint() function */
typedef struct
{
  // Service structure
  struct
  {
    union
    {
      APS_RegisterEndpointReq_t apsEndpoint;
      APS_UnregisterEndpointReq_t unregEpReq;
    };
  } service;

  SimpleDescriptor_t     simpleDescriptor;          //!< Device endpoint Simple Descriptor
  ZCL_Cluster_t          *serverCluster;            //!< Device server clusters
#if APP_CLUSTERS_IN_FLASH == 1
  ZCL_ClusterPartRam_t   *serverClusterPartRam;     //!< Device server clusters mutable part defined in ram memory
  ZCL_ClusterPartFlash_t *serverClusterPartFlash;   //!< Device server clusters immutable part defined in flash memory
#endif
  ZCL_Cluster_t          *clientCluster;            //!< Device client clusters
#if APP_CLUSTERS_IN_FLASH == 1
  ZCL_ClusterPartRam_t   *clientClusterPartRam;     //!< Device server clusters mutable part defined in ram memory
  ZCL_ClusterPartFlash_t *clientClusterPartFlash;   //!< Device server clusters immutable part defined in flash memory
#endif
} ZCL_DeviceEndpoint_t;

/**  ZCL Data Type Descriptor.
     Describes the Data Type length in bytes and Data Type kind (Analog or Descrete). */
typedef struct
{
  uint16_t   length;                     //!<Length in bytes
  /*!Kind of Data Type. The #ZCL_DATA_TYPE_ANALOG_KIND, \n
   !#ZCL_DATA_TYPE_DISCRETE_KIND or \n
   !#ZCL_DATA_TYPE_COLLECTION_KIND should be used).*/
  uint8_t   kind;
} ZCL_DataTypeDescriptor_t;

typedef ZCL_Status_t (*ZCL_CommandIndCallback_t)(ZCL_Addressing_t *addressing,  uint8_t payloadLength, uint8_t *payload);
typedef void (*ZCL_ReportIndCallback_t)(ZCL_Addressing_t *addressing,  uint8_t payloadLength, uint8_t *payload);
typedef void (*ZCL_DefaultRespIndCallback_t)(ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
typedef void (*ZCL_AttrEventIndCallback_t)(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);
typedef void (*ZCL_NotifyRespIndiCallback_t)(ZCL_Notify_t *ntfy);

typedef struct _ZCL_CommandInd
{
  ZCL_CommandIndCallback_t callbackFn;
  ZCL_Addressing_t *addressing;
  uint8_t payloadLength;
  uint8_t *payload;  
  ZCL_Status_t status;
} ZCL_CommandInd_t;

typedef struct _ZCL_AttrReportInd
{
  ZCL_ReportIndCallback_t callbackFn;
  ZCL_Addressing_t *addressing;
  uint8_t payloadLength;
  uint8_t *payload;
} ZCL_AttrReportInd_t;

typedef struct _ZCL_DefaultRespInd
{
  ZCL_DefaultRespIndCallback_t callbackFn;
  ZCL_Request_t *req;
  ZCL_Addressing_t *addressing;
  uint8_t payloadLength;
  uint8_t *payload;
} ZCL_DefaultRespInd_t;

typedef struct _ZCL_AttrEventInd
{
  ZCL_AttrEventIndCallback_t callbackFn;
  ZCL_Addressing_t *addressing;
  ZCL_AttributeId_t attributeId;
  ZCL_AttributeEvent_t event;
} ZCL_AttrEventInd_t;


typedef struct _ZCL_NotifyRespInd
{
  ZCL_NotifyRespIndiCallback_t callbackFn;
  ZCL_Notify_t *ntfy;
} ZCL_NotifyRespInd_t;

/******************************************************************************
                    Prototypes section
 ******************************************************************************/
 
/*************************************************************************//**
  \brief Function to send a common ZCL_callback to application
  \param callbackFn   - Calllabck function to be called in the application
            addressing   - Zcl addressing infirmation
            payloadLength- payload length of the command
            payload      - payload of the command
  \return None
 *****************************************************************************/
ZCL_Status_t ZCL_CommandInd(ZCL_CommandIndCallback_t callbackFn, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);

/*************************************************************************//**
  \brief Function to send zcl report indication to application
  \param callbackFn   - Calllabck function to be called in the application
            zclIndType  -  zcl indication type
            addressing   - Zcl addressing infirmation
            payloadLength- payload length of the command
            payload      - payload of the command
            
   \return None
 *****************************************************************************/
void ZCL_AttrReportInd(ZCL_ReportIndCallback_t callbackFn, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);

/*************************************************************************//**
  \brief Function to send  ZCL default resp Ind to application
  \param callbackFn   - Calllabck function to be called in the application
            zclIndType  -  zcl indication type
            req         - ZCL request for which defaultresp is sent
            addressing   - Zcl addressing infirmation
            payloadLength- payload length of the command
            payload      - payload of the command
            
            
  \return None
 *****************************************************************************/
void ZCL_DefaultResponseInd(ZCL_DefaultRespIndCallback_t callbackFn, ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);

/*************************************************************************//**
  \brief Function to send ZCL Atribute Event Ind to application
  \param callbackFn   - Calllabck function to be called in the application
            zclIndType  -  zcl indication type
            addressing   - Zcl addressing infirmation
            attributeId-  Atribute Id
            Event - Event occured on attribute
  \return None
 *****************************************************************************/
void ZCL_AttrEventInd(ZCL_AttrEventIndCallback_t callbackFn, ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);

/*************************************************************************//**
  \brief Function to send ZCL Atribute Event Ind to application
  \param callbackFn   - Calllabck function to be called in the application
            Notify - ZCL_Notify
            
  \return None
 *****************************************************************************/
void ZCL_NotifyRespInd(ZCL_NotifyRespIndiCallback_t callbackFn, ZCL_Notify_t *ntfy);

/******************************************************************************
                           Inline functions section
 ******************************************************************************/

/********************************************************************************//**
  \brief Gets Cluster Side the Incoming command is intended to.

  \param direction - incoming command direction
  \return cluster side detected
 ***********************************************************************************/
INLINE uint8_t getDstClusterSideByIncommingCommandDirection(uint8_t direction)
{
  return !direction;
}

/********************************************************************************//**
  \brief Gets source Cluster Side by destination Cluster side.

  \param clusterSide - destination cluster's side
  \return cluster side detected
 ***********************************************************************************/
INLINE uint8_t getSrcClusterSideByDstClusterSide(uint8_t clusterSide)
{
  return !clusterSide;
}

/********************************************************************************//**
  \brief Gets destination Cluster Side by source Cluster side.

  \param clusterSide - source cluster's side
  \return cluster side detected
 ***********************************************************************************/
INLINE uint8_t getDstClusterSideBySrcClusterSide(uint8_t clusterSide)
{
  return !clusterSide;
}

/********************************************************************************//**
  \brief Gets outgoing command direction by destination Cluster side.

  \param clusterSide - destination cluster's side
  \return command direction detected
 ***********************************************************************************/
INLINE uint8_t getOutgoingCommandDirectionByDstClusterSide(uint8_t clusterSide)
{
  return clusterSide;
}

/********************************************************************************//**
  \brief Gets source Cluster side by direction of incoming command.

  \param direction - incoming command direction.
  \return detected cluster side.
 ***********************************************************************************/
INLINE uint8_t getOwnClusterSideByIncomingCommandDirection(uint8_t direction)
{
  return direction;
}

/********************************************************************************//**
  \brief Gets destination Cluster side by direction of outgoing command.

  \param direction - outgoing command direction.
  \return detected cluster side.
 ***********************************************************************************/
INLINE uint8_t getDstClusterSideByOutgoingCommandDirection(uint8_t direction)
{
  return direction;
}

/********************************************************************************//**
  \brief Gets direction of incoming command by it's initiator cluster side.

  \param clusterSide - command initiator cluster's side
  \return incoming command direction
 ***********************************************************************************/
INLINE uint8_t ZCL_GetIncomingCommandDirectionBySrcClusterSide(uint8_t clusterSide)
{
  return !clusterSide;
}

/***************************************************************************//**
  \brief Calculates offset for zcl data in zcl buffer.
  \param None
  \return offset.
 ******************************************************************************/
INLINE uint8_t getZclAsduOffset(void)
{
  return APS_ASDU_OFFSET + GUARD_SIZE;
}

/***************************************************************************//**
  \brief Returns next sequence number.
  \param None
  \return offset.
 ******************************************************************************/
static inline uint8_t ZCL_GetNextSeqNumber(void)
{
  return zclMem.sequenceNumber++;
}

/******************************************************************************
                           Functions prototypes section
 ******************************************************************************/
 
/*******************************************************************************//**
  \brief Registers an application endpoint

  \ingroup zcl_common

  This function registers an application endpoint to make ZCL know which devices types
  are used by the application and which client and server clusters are supported.

  \param  endpoint - contains device descriptor
  
  \return None
 *********************************************************************************/
void ZCL_RegisterEndpoint(ZCL_DeviceEndpoint_t *endpoint);

/**************************************************************************//**
  \brief Unregisters an application endpoint.

  \ingroup zcl_common

     This function unregisters an application endpoint.

  \param endpoint - contains device descriptor
  
  \return None
 ******************************************************************************/
void ZCL_UnregisterEndpoint(ZCL_DeviceEndpoint_t *endpoint);

/*************************************************************************//**
  \brief Resets the ZCL component

  \ingroup zcl_common

  \param none
  
  \return None
 *****************************************************************************/
void ZCL_ResetReq(void);

/*************************************************************************//**
  \brief Finds an attribute in ZCL and returns its value

  \ingroup zcl_common

   The function may be used to obtain only local attributes.
   To access an attribute on a remote device, send a read attributes
   general cluster command via the ZCL_AttributeReq() function.

  \param endpointId - endpoint on which cluster is registered
         clusterId - cluster unique identifier
         clusterSide - detects the cluster's side (client or server)
         attrId - attribute unique identifier
         [out] attrType - pointer to attribute type determined and returned
         [out] attrValue - read out attribute value pointer

   Caller is responsible for providing big enough attrValue buffer.

  \return The status of the operation:  \n
   ::ZCL_SUCCESS_STATUS (0x00) - attribute value has been obtained successfully \n
   ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is
     not supported
 *****************************************************************************/
ZCL_Status_t ZCL_ReadAttributeValue(Endpoint_t endpointId, ClusterId_t clusterId,
#ifdef _CUSTOM_ZCL_MSP_SUPPORT_
                              uint8_t clusterSideMspMask,
#else
                              uint8_t clusterSide,
#endif
                              ZCL_AttributeId_t attrId, uint8_t *attrType, uint8_t *attrValue);

/*************************************************************************//**
  \brief Finds an attribute in ZCL and rewrites its value by the new one

  \ingroup zcl_common

  The function may be used to set or rewrite only local attributes.
  Affects attribute reporting on change.
  To set a new value to an attribute on a remote device, send a write attributes
  general cluster command via the ZCL_AttributeReq() function.

  \param endpointId - endpoint on which cluster is registered
             clusterId - cluster unique identifier
             clusterSide - detects the cluster's side (client or server)
             attrId - attribute unique identifier
             attrType - type of the attribute to be set
             attrValue - pointer to attribute value to be set

  \return The status of the operation: \n
    ::ZCL_SUCCESS_STATUS (0x00) - new value has been written successfully \n
    ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is not supported \n
    ::ZCL_INVALID_PARAMETER_STATUS (0xFF) - NULL has been provided as the attribute's value \n
    ::ZCL_INVALID_DATA_TYPE_STATUS (0x8D) - the attribute's type is not the same as specified
      in the argument \n
    ::ZCL_READ_ONLY_STATUS (0x88) - the attribute's value cannot be changed,
      because the attribute is read-only
 *****************************************************************************/
ZCL_Status_t ZCL_WriteAttributeValue(Endpoint_t endpointId, ClusterId_t clusterId,
#ifdef _CUSTOM_ZCL_MSP_SUPPORT_
                                         uint8_t clusterSideMspMask,
#else
                                         uint8_t clusterSide,
#endif
                                         ZCL_AttributeId_t attrId, uint8_t attrType, uint8_t *attrValue);
#ifdef _ZCL_REPORTING_SUPPORT_

/*************************************************************************//**
  \brief Reports attribute if report on change is enabled and all
   conditions to report are met.

  \ingroup zcl_common

  \param attr - pointer to attribute

  \return The status of the operation: \n
    ::ZCL_SUCCESS_STATUS (0x00) - new value has been written successfully \n
    ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - the specified attribute is not supported
 *****************************************************************************/
ZCL_Status_t ZCL_ReportOnChangeIfNeeded(void *attr);

/*************************************************************************//**
  \brief Starts attributes reporting if any attributes are configured for
   reporting by application. Restarts reporting if it was in progress.

  \ingroup zcl_common
  
  \param None
  
  \return None
 *****************************************************************************/
void ZCL_StartReporting(void);

/*************************************************************************//**
  \brief Finds an attribute in ZCL and rewrites its reportable change value by the new one

  \ingroup zcl_common

  If the reportable change value of an attribute is set to a non-zero value, using
  this function, the stack checks how much the attribute has changed each
  time a new value is set to it. The current (just set) value is compared with
  the last reported value, and if the absolute difference is greater than the
  reportable change value a new report is generated and sent to the air.

  \param endpointId - endpoint on which cluster is registered
         clusterId - cluster unique identifier
         clusterSide - determs the cluster's side (client or server)
         attrId - attribute unique identifier
         attrType - type of the attribute to be set
         repChange - pointer to reportable change value to be set

  \return status of operation.
 *****************************************************************************/
ZCL_Status_t ZCL_SetReportableChange(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t clusterSide,
                                     ZCL_AttributeId_t attrId, uint8_t attrType, uint8_t *repChange);

/***************************************************************************//**
  \brief Checks whether the ZCL OTAU component is processing a transaction

  \ingroup zcl_otau
  
  \param None
  
  \return true - if ZCL is busy, false - otherwise
 ******************************************************************************/
bool ZCL_IsBusy(void);

/*************************************************************************//**
  \brief starts the report timer on recieving configure report cmd or
    reportOnChange triggered due to change in attribute value
    
  \param None
  
  \return None
 *****************************************************************************/
void zclStartReportTimer(void);
#endif // _ZCL_REPORTING_SUPPORT_

/*************************************************************************//**
  \brief Finds attribute in ZCL and rewrites its value by the new one
  (to be used with remote write request).

  \param endpointId - endpoint on which cluster is registered
         clusterId - cluster unique identifier
         clusterSideMspMask - detects the cluster's side (client or server)
                                 as well as msp specific cluster
         attrId - attribute unique identifier
         attrType - type of the attribute to be set
         attrValue - pointer to attribute value to be set
         onlyCheck - not to write, but only check attribute existance.

  \return status of operation
 *****************************************************************************/
ZCL_Status_t zclRemoteWriteAttributeValue(Endpoint_t endpointId, ClusterId_t clusterId, uint8_t clusterSideMspMask,
                                          ZCL_AttributeId_t attrId, uint8_t attrType, uint8_t *attrValue,
                                          bool onlyCheck);

/*************************************************************************//**
  \brief Sends a general ZCL command related to attributes to a remote device

  \ingroup zcl_common

  The function is used to read/write attributes from a remote device, to report
  local attributes, and to discover attributes supported by a particular cluster
  on a remote device.

  Command's parameters include addressing information, calback functions, command's
  ID, and the payload. The payload may be formed via the ZCL_PutNextElement()  function
  and an instance of ZCL_NextElement_t type. The command may be used to perform
  actions on multiple attributes at a time; for example, to read several attributes
  from a remote device.

  Attribute related commands are usually send to specific short or extended   addresses.
  Sending such commands to bound devices (employing ::APS_NO_ADDRESS mode) may not
  be as efficient, because in case of responses from more than one device the ZCL
  component will process only the first one.

  The callback function specified in the \c req->ZCL_Notify field is called twice
  for most of the commands (excluding reporting): the first time to confirm that the
  command has been sent, and the second time upon receiving the response command.
  To differentiate these the callback's argument includes the ZCL_Notify_t::id field,
  which equals ::ZCL_APS_CONFIRM_ID in the first case and ::ZCL_ZCL_RESPONSE_ID in the
  second.

  Common uses of the function include sending the following commands (the command's
  ID listed below should be assigned to the \c req->id field):
  \li ::ZCL_READ_ATTRIBUTES_COMMAND_ID - reading remote attributes (obtaining values)
  \li ::ZCL_WRITE_ATTRIBUTES_COMMAND_ID - writing remote attributes (assigning new values)
  \li ::ZCL_REPORT_ATTRIBUTES_COMMAND_ID - reporting local attributes to remote devices
     (sending current attributes' values)
  \li ::ZCL_DISCOVER_ATTRIBUTES_COMMAND_ID - discovering attributes of a remote device (obtaining
     data types and IDs of attributes supported by a particular cluster)
  \li ::ZCL_DISCOVER_COMMANDS_RECEIVED_COMMAND_ID - discovering the commands received (obtaining
     the list of commands those can be received and processed
  \li ::ZCL_DISCOVER_COMMANDS_GENEARATED_COMMAND_ID - discovering the commands generated (obtaining
     the list of commands those can be generated and processed
  \li ::ZCL_DISCOVER_ATTRIBUTES_EXTENDED_COMMAND_ID - discovering attributes of a remote device (obtaining
     data types,access control and IDs of attributes supported by a particular cluster)
    
  Response statuses:
  Accessed via the ZCL_Notify_t::status field of the callback function specified in
  the \c req->ZCL_Notify field \n\n
  <i>All commands</i> \n
  ::ZCL_SUCCESS_STATUS (0x00) - the request has been executed successfully
  (all attributes are written, read, or reported, etc.) \n
  ::ZCL_INSUFFICIENT_SPACE_STATUS (0x89) - the ZCL buffer is not big enough
    to hold the request's payload \n
  ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - an attribute specified in the request is
    not supported by the destination node \n
  ::ZCL_INVALID_FIELD_STATUS (0x85) - a command's field contains an incorrect value \n
  ::ZCL_INVALID_DATA_TYPE_STATUS (0x8D) - wrong attribute type has been specified \n
  ::ZCL_TIMEOUT_STATUS (0x94) - the response command is expected, but has not
    been received in time: the timeout based on network parameters (such as max network
    depth) has occured.\n\n
  <i>Write attributes command</i> \n
  ::ZCL_WRITE_ATTRIBUTES_FAILURE_STATUS (0x0F) - not all attributes have been written;
    see individual statuses of attribute records to check each attribute \n\n
  <i>Report attributes command</i> \n
  ::ZCL_UNREPORTABLE_ATTRIBUTE_STATUS (0x8C) - the requested attribute is not
    reportable \n\n
    
  \param req - command parameters

  \return None
 *****************************************************************************/
void ZCL_AttributeReq(ZCL_Request_t *req);

/********************************************************************************//**
  \brief Sends a cluster-specific command

  \ingroup zcl_common

 The function sends a general cluster specific command. The command's type is
 recognized according to the \c req->id field. Commands' IDs are defined in clusters'
 definition files, which also contain all definition related to a particular cluster.

 In addition to addressing information and command's ID, eesential fields of
 the request parameters include the payload and the payload length. The payload
 for each command is defined as a structure in the cluster's definition file.
 The pointer to a properly configured instance of the command's payload shall be \
 assigned to the \c req->requestPayload field.

 The callback function specified in the \c req->ZCL_Notify field is called to
 indicate the status of the command's delivery (not a specific response for the
 command). If acknowledgment of the command's delivery is received the success
 status is reported in the callback.

 A specific response to the command is processed by a special indication function
 registered for the command. If a command does not imply a specific response
 the default response may be requested (to indicate that the command has been
 executed). To request the default response set the \c req->defaultResponse field
 to ::ZCL_FRAME_CONTROL_ENABLE_DEFAULT_RESPONSE. To disable default response
 set \c req->defaultResponse to ::ZCL_FRAME_CONTROL_DISABLE_DEFAULT_RESPONSE.

  Response statuses:
   The ZCL_Notify_t::status field of the callback function specified in
   the \c req->ZCL_Notify field reports the status of command's transmission
   and acknowledgement \n\n
   ::ZCL_SUCCESS_STATUS (0x00) - the command has been sent successfully and the
     acknowledgement has been received \n
   ::ZCL_INSUFFICIENT_SPACE_STATUS (0x89) - the ZCL buffer is not big enough
     to hold the request's payload \n
   Error codes - all status codes returned by the APS_DataReq() function.

 \param req - contains request descriptor

 \return None 
 **********************************************************************************/
void ZCL_CommandReq(ZCL_Request_t *req);

/*********************************************************************************//**
  \brief Specific command indication handler

  \param ind - contains indication descriptor
  
  \return None
 ********************************************************************************/
//void ZCL_CommandInd(ZCL_CommandInd_t *ind);

/*************************************************************************//**
  \brief ZCL event notification handler

  \param event - contains event descriptor
  
  \return None
 *****************************************************************************/
void ZCL_EventNtfy(ZCL_EventNtfy_t *event);

/*************************************************************************//**
  \brief This function returns bytes amount of a type by the type's ID

  \ingroup zcl_common

  \param typeId - type's ID
         value - pointer to variable of typeId, NULL means
            the maximum possible size
            
  \return None
 *****************************************************************************/
uint16_t ZCL_GetAttributeLength(uint8_t typeId, const uint8_t *value);

/*************************************************************************//**
  \brief Adds an element to the outgoing command payload

  \ingroup zcl_common

  This function is used to simplify forming a correst payload for general
  commands (read/write attributes etc.). A single command may involve actions on
  several attributes, and so the overall payload should contain pieces
  corresponding to each attribute.

  The general idea is to provide a buffer for the payload and some content. The
  function writes the content in a correct way to the buffer and calculate the
  overall payload length. The buffer and the payload length are then passed as
  parameters to the ZCL_AttributeReq() function.

  See the following example:

\code
ZCL_NextElement_t element;
ZCL_ReadAttributeReq_t readAttrReqElement;
ZCL_Request_t readAttrReq;
uint8_t buffer[BUFFER_SIZE];

element.payloadLength = 0;
element.payload = buffer;
element.id = ZCL_READ_ATTRIBUTES_COMMAND_ID;
element.content = &readAttrReqElement;

readAttrReqElement = ATTRIBUTE_ID1; //Set to the ID of the first attribute
ZCL_PutNextElement(&element);

readAttrReqElement = ATTRIBUTE_ID2; //Set to the ID of the second attribute
ZCL_PutNextElement(&element);

readAttrReq.requestLength = element.payloadLength;
readAttrReq.requestPayload = buffer;
...
\endcode

 Note, however, that the usage may differ depending on a command's type.

 \param[in] element - information about payload and element
       [out] status of the operation:
     ::ZCL_SUCCESS_STATUS (0x00) - an element has been written to the payload successfully,
       more elements can be added \n
     ::ZCL_END_PAYLOAD_REACHED_STATUS (0xFD) - an element has been written successfully, and
       the payload is full - no more elements can be added \n
     ::ZCL_INVALID_PARAMETER_STATUS (0xFF) - the argument is NULL
     
  \return None
 *****************************************************************************/
ZCL_Status_t ZCL_PutNextElement(ZCL_NextElement_t *element);

/*************************************************************************//**
  \brief Gets an element from the incoming command's payload

  \ingroup zcl_common

  The function is used to simplify processing of responses fo general
  attributes related commands. Such command may return information concerning
  several attributes in a single frame. This function reads the next portion
  of information from the response payload.

  To use the function configure an instance of ZCL_NextElement type.
  The \c element->payload field should be set to the response payload,
  the \c element->payloadLength to the reponse payload's length, and
  the \c element->id field to the ID of the response. After calling this
  function, the \c element->content field may be casted to the appropriate
  response type (depending on the command's type); for example, for
  read attributes response it is ZCL_ReadAttributeResp_t.

 \param[in] element - information about payload and element
       [out] status of the operation:
     ::ZCL_SUCCESS_STATUS - an element has been read successfully, more elements
       are contained in the payload \n
     ::ZCL_END_PAYLOAD_REACHED_STATUS (0xFD) - an element has been read successfully and no
       more elements are left in the payload \n
     ::ZCL_INVALID_PARAMETER_STATUS (0xFF) - the argument is NULL
     
  \return None
 *****************************************************************************/
ZCL_Status_t ZCL_GetNextElement(ZCL_NextElement_t *element);

/***************************************************************************//**
  \brief Checks whether ZCL OTAU is busy or not.
  
  \param None
  
  \return true - if ZCL OTAU is busy, false - otherwise.
 ******************************************************************************/
bool ZCL_IsOtauBusy(void);

/*************************************************************************//**
  \brief  ZCL data type descriptor get by the type ID function;
          fills the ZCL data type descriptor dased on the ZCL data type ID

  \param  Id - ZCL data type ID (unsigned 8-bit integer)
          value - pointer to variable of typeId, NULL means maximum possible
          size
          descriptor - ZCL Data Type Descriptor being filled
  \return None
  \sa     ZCL_DataTypeDescriptor_t
  \sa     ZCL_GetAttributeLength()
 *****************************************************************************/
void ZCL_GetDataTypeDescriptor(uint8_t typeId, const uint8_t *value, ZCL_DataTypeDescriptor_t *descriptor);

/*************************************************************************//**
  \brief Find cluster descriptor by endpoint id, cluster id.

  \param     endpointId - endpoint unique identifier.
             clusterId - cluster unique identifier.
             clusterSide - cluster side (client or server).
  \return ZCL cluster descriptor if found, NULL otherwise.
 *****************************************************************************/
ZCL_Cluster_t * ZCL_GetCluster(Endpoint_t endpointId, ClusterId_t clusterId,
#ifdef _CUSTOM_ZCL_MSP_SUPPORT_
                              uint8_t clusterSideMspMask);
#else
                              uint8_t clusterSide);
#endif

/*************************************************************************//**
  \brief Returns the first ZCL cluster descriptor by endpoint and cluster side.

  \param endpoint - pointer to endpoint.
             clusterSide - cluster side (client or server).
  \return pointer to the first ZCL cluster descriptor.
 *****************************************************************************/
ZCL_Cluster_t * ZCL_GetHeadCluster(ZCL_DeviceEndpoint_t *endpoint, uint8_t clusterSide);

/*************************************************************************//**
  \brief Finds next cluster descriptor.

  \param cluster - pointer to current cluster descriptor.
  \return poiter to next cluster descriptor.
 *****************************************************************************/
ZCL_Cluster_t * ZCL_GetNextCluster(ZCL_Cluster_t *cluster);

/**************************************************************************//**
  \brief Interface to pass ZCL request to APS

  APS_DataConf field in APS_DataReq must be an actual confirm handler pointer.

  \param req The APS_DataReq_t primitive pointer.
         apsSecurity If true APS security is switched on.
         
  \return None
 *****************************************************************************/
void ZCL_ApsDataReq(APS_DataReq_t *req, bool apsSecurity);

/**************************************************************************//**
  \brief Stops response wait timer
  
  \param None
  
  \return None
 *****************************************************************************/
void zclStopResponseWaitTimer(void);

#endif //_ZCL_H

//eof zcl.h
