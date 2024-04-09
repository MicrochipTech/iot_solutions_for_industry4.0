/*******************************************************************************
  Zigbee Cluster Library Time Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclTimeCluster.h

  Summary:
    The header file describes the ZCL Time Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL Time Cluster.
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

#ifndef _ZCLTIMECLUSTER_H
#define _ZCLTIMECLUSTER_H

/*!
This cluster provides a basic interface to a real-time clock. The clock time may be
read and also written, in order to synchronize the clock (as close as practical) to a
time standard. This time standard is the number of seconds since 0 hrs 0 mins 0
sec on 1st January 2000 UTC (Universal Coordinated Time).
*/

/*******************************************************************************
                   Includes section
*******************************************************************************/

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>


/*******************************************************************************
                   Define(s) section
*******************************************************************************/
#define ZCL_TIME_CLUSTER_DEF_ZERO_VALUE     0x00000000
#define ZCL_TIME_CLUSTER_DEF_INVALID_VALUE  0xffffffff
#define ZCL_TIME_ZONE_MIN_VALUE             -86400
#define ZCL_TIME_ZONE_MAX_VALUE             86400
#define ZCL_DST_SHIFT_MIN_VALUE             -86400
#define ZCL_DST_SHIFT_MAX_VALUE             86400
/***************************************************************************//**
  \brief ZCL Time Cluster server side commands amount
*******************************************************************************/
#define ZCL_TIME_CLUSTER_SERVER_ATTRIBUTES_AMOUNT      11
//The Time and TimeStatus attributes

/***************************************************************************//**
  \brief ZCL Time Cluster client side commands amount
*******************************************************************************/
#define ZCL_TIME_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT      1
//There is no any attributes at client cluster side

/***************************************************************************//**
  \brief ZCL Time Cluster commands amount
*******************************************************************************/
#define ZCL_TIME_CLUSTER_COMMANDS_AMOUNT        0
//There is no any commands at client cluster side

//!ZCL Time Cluster server side Time attribute id
#define ZCL_TIME_CLUSTER_SERVER_TIME_ATTRIBUTE_ID             CCPU_TO_LE16(0x0000)
//!ZCL Time Cluster server side TimeStatus attribute id
#define ZCL_TIME_CLUSTER_SERVER_TIME_STATUS_ATTRIBUTE_ID      CCPU_TO_LE16(0x0001)
//!ZCL Time Cluster server side TimeZone attribute id
#define ZCL_TIME_CLUSTER_SERVER_TIME_ZONE_ATTRIBUTE_ID        CCPU_TO_LE16(0x0002)
//!ZCL Time Cluster server side DstStart attribute id
#define ZCL_TIME_CLUSTER_SERVER_DST_START_ATTRIBUTE_ID        CCPU_TO_LE16(0x0003)
//!ZCL Time Cluster server side DstEnd attribute id
#define ZCL_TIME_CLUSTER_SERVER_DST_END_ATRIBUTE_ID           CCPU_TO_LE16(0x0004)
//!ZCL Time Cluster server side DstShift attribute id
#define ZCL_TIME_CLUSTER_SERVER_DST_SHIFT_ATTRIBUTE_ID        CCPU_TO_LE16(0x0005)
//!ZCL Time Cluster server side StandardTime attribute id
#define ZCL_TIME_CLUSTER_SERVER_STANDARD_TIME_ATTRIBUTE_ID    CCPU_TO_LE16(0x0006)
//!ZCL Time Cluster server side LocalTime attribute id
#define ZCL_TIME_CLUSTER_SERVER_LOCAL_TIME_ATTRIBUTE_ID       CCPU_TO_LE16(0x0007)
//!ZCL Time Cluster server side lastSetTime attribute id
#define ZCL_TIME_CLUSTER_SERVER_LAST_SET_TIME_ATTRIBUTE_ID    CCPU_TO_LE16(0x0008)
//!ZCL Time Cluster server side validUntilTime attribute id
#define ZCL_TIME_CLUSTER_SERVER_VALID_UNTIL_TIME_ATTRIBUTE_ID CCPU_TO_LE16(0x0009)

//Attribute Ids of Basic Cluster Information
#define ZCL_TIME_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID                          CCPU_TO_LE16(0xfffd)

/***************************************************************************//**
  \brief ZCL Time Cluster server side attributes defining macros

  This macros should be used for ZCL Time Cluster server side attributes defining.

  \return None

  \internal
  //The typical usage is:
  //Time Cluster server side related attributes
  ZCL_TimeClusterServerAttributes_t timeClusterAttributes = ZCL_DEFINE_TIME_CLUSTER_SERVER_ATTRIBUTES();
*******************************************************************************/
#define ZCL_DEFINE_TIME_CLUSTER_SERVER_ATTRIBUTES() \
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(time, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_TIME_ATTRIBUTE_ID, ZCL_UTC_TIME_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(timeStatus, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_TIME_STATUS_ATTRIBUTE_ID,  ZCL_8BIT_BITMAP_DATA_TYPE_ID, 0x00, 0x0F),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(timeZone, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_TIME_ZONE_ATTRIBUTE_ID, ZCL_S32BIT_DATA_TYPE_ID, ZCL_TIME_ZONE_MIN_VALUE, ZCL_TIME_ZONE_MAX_VALUE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(dstStart, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_DST_START_ATTRIBUTE_ID, ZCL_U32BIT_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(dstEnd, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_DST_END_ATRIBUTE_ID, ZCL_U32BIT_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(dstShift, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_DST_SHIFT_ATTRIBUTE_ID, ZCL_S32BIT_DATA_TYPE_ID, ZCL_DST_SHIFT_MIN_VALUE, ZCL_DST_SHIFT_MAX_VALUE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(standardTime, ZCL_READONLY_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_STANDARD_TIME_ATTRIBUTE_ID, ZCL_U32BIT_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(localTime, ZCL_READONLY_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_LOCAL_TIME_ATTRIBUTE_ID, ZCL_U32BIT_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFE),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(lastSetTime, ZCL_READONLY_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_LAST_SET_TIME_ATTRIBUTE_ID, ZCL_UTC_TIME_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFF),\
  DEFINE_ATTRIBUTE_WITH_BOUNDARY(validUntilTime, ZCL_READWRITE_ATTRIBUTE, ZCL_TIME_CLUSTER_SERVER_VALID_UNTIL_TIME_ATTRIBUTE_ID, ZCL_UTC_TIME_DATA_TYPE_ID, 0x00000000, 0xFFFFFFFF),\
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_TIME_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)
    
#define ZCL_DEFINE_TIME_CLUSTER_CLIENT_ATTRIBUTES() \
  DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_TIME_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID)     
/***************************************************************************//**
  \brief ZCL Time Cluster server side defining macros

  This macros should be used with #DEFINE_ZCL_TIME_CLUSTER_SERVER_ATTRIBUTES for
  ZCL Time Cluster server side defining in application.

  \param attributes - pointer to cluster server attributes (ZCL_TimeClusterServerAttributes_t)

  \return None

  \internal
  //The typical code is:
  //Time Cluster server side related attributes
  ZCL_TimeClusterServerAttributes_t timeClusterServerAttributes = DEFINE_ZCL_TIME_CLUSTER_SERVER_ATTRIBUTES();
  ZCL_Cluster_t myClusters[] =
  {
    ZCL_DEFINE_TIME_CLUSTER_SERVER(&timeClusterServerAttributes),
    //... Any other cluster defining ...
  }
*******************************************************************************/
#define TIME_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands)                                                    \
  {                                                                                                                       \
    .id = TIME_CLUSTER_ID,                                                                                                \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},                  \
    .attributesAmount = ZCL_TIME_CLUSTER_SERVER_ATTRIBUTES_AMOUNT,                                                        \
    .attributes = (uint8_t *) clattributes,                                                                               \
    .commandsAmount = ZCL_TIME_CLUSTER_COMMANDS_AMOUNT,                                                                   \
    .commands = (uint8_t *) clcommands                                                                                    \
  }

#define TIME_CLUSTER_ZCL_SERVER_CLUSTER_TYPE_FLASH(clattributes, clcommands)                                              \
  {                                                                                                                       \
    .id = TIME_CLUSTER_ID,                                                                                                \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},                  \
    .attributesAmount = ZCL_TIME_CLUSTER_SERVER_ATTRIBUTES_AMOUNT,                                                        \
    .attributes = (uint8_t *) clattributes,                                                                               \
    .commandsAmount = ZCL_TIME_CLUSTER_COMMANDS_AMOUNT,                                                                   \
    .commands = (FLASH_PTR uint8_t *) clcommands                                                                                    \
  }

/***************************************************************************//**
  \brief ZCL Time Cluster client side defining macros

  This macros should be used for ZCL Time Cluster client side defining in application.

  \return None

  \internal
  //The typical code is:
  ZCL_Cluster_t myClusters[] =
  {
    ZCL_DEFINE_TIME_CLUSTER_CLIENT(),
    //... Any other cluster defining ...
  }
*******************************************************************************/
#define TIME_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands)                                                    \
  {                                                                                                                       \
    .id = TIME_CLUSTER_ID,                                                                                                \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY },                 \
    .attributesAmount = ZCL_TIME_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT,                                                        \
    .attributes = (uint8_t *) clattributes,                                                                               \
    .commandsAmount = ZCL_TIME_CLUSTER_COMMANDS_AMOUNT,                                                                   \
    .commands = (uint8_t *) clcommands                                                                                    \
  }

#define TIME_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE_FLASH(clattributes, clcommands)                                              \
  {                                                                                                                       \
    .id = TIME_CLUSTER_ID,                                                                                                \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY },                 \
    .attributesAmount = ZCL_TIME_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT,                                                        \
    .attributes = (uint8_t *) clattributes,                                                                               \
    .commandsAmount = ZCL_TIME_CLUSTER_COMMANDS_AMOUNT,                                                                   \
    .commands = (FLASH_PTR uint8_t *) clcommands                                                                                    \
  }

#define DEFINE_TIME_CLUSTER(cltype, clattributes, clcommands) TIME_CLUSTER_##cltype(clattributes, clcommands)
#define DEFINE_TIME_CLUSTER_FLASH(cltype, clattributes, clcommands) TIME_CLUSTER_##cltype##_FLASH(clattributes, clcommands)

/*******************************************************************************
                   Types section
*******************************************************************************/

BEGIN_PACK
/***************************************************************************//**
  \brief
  ZCL Time Cluster attributes
*******************************************************************************/
typedef struct PACK
{
  /*!
  \brief Time attribute (R/W, M)

  The Time attribute is 32-bits in length and holds the time value of a real time
  clock. This attribute has data type UTCTime, but note that it may not actually be
  synchronised to UTC - see discussion of the TimeStatus attribute below.
  If the Master bit of the TimeStatus attribute has a value of 0, writing to this
  attribute shall set the real time clock to the written value, otherwise it cannot be
  written. The value 0xffffffff indicates an invalid time.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0000)
    uint8_t             type;         //!<Attribute type (UTCTime - 32-bit) (typeId = 0xe2, #ZCL_UTC_TIME_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    ZCL_UTCTime_t       value;        //!<Attribute value (default none)
    ZCL_UTCTime_t       minVal;       //!<Attribute minimum value
    ZCL_UTCTime_t       maxVal;       //!<Attribute maximum value
  } time;
  /*!
  \brief TimeStatus attribute (R/W, M)

    The Master and Synchronized bits together provide information on how closely
  the Time attribute conforms to the time standard.
    The Master bit specifies whether the real time clock corresponding to the Time
  attribute is internally set to the time standard. This bit is not writeable
  if a value is written to the TimeStatus attribute, this bit does not change.
    The Synchronized bit specifies whether Time has been set over the network to
  synchronize it (as close as may be practical) to the time standard. This
  bit must be explicitly written to indicate this i.e. it is not set automatically on
  writing to the Time attribute. If the Master bit is 1, the value of this bit is 0.
    If both the Master and Synchronized bits are 0, the real time clock has no defined
  relationship to the time standard (e.g. it may record the number of seconds since
  the device was initialized).
    The MasterZoneDst bit specifies whether the TimeZone, DstStart, DstEnd and
  DstShift attributes are set internally to correct values for the location of the clock.
  If not, these attributes need to be set over the network. This bit is not writeable if
  a value is written to the TimeStatus attribute, this bit does not change.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;               //!<Attribute Id (0x0001)
    uint8_t             type;             //!<Attribute type (8-bit bitmap, typeId = 0x18, #ZCL_8BIT_BITMAP_DATA_TYPE_ID)
    uint8_t             properties;       //!<Attribute properties bitmask
    struct PACK                           //!<Attribute value (default 0b00000000)
    {
      LITTLE_ENDIAN_OCTET(5,(
        uint8_t           master        :1, //!<Master bit (1 - master clock, 0 - not master clock)
        uint8_t           synchronized  :1, //!<Synchronized bit (1- synchronized, 0 - not synchronized)
        uint8_t           masterZoneDst :1, //!<MasterZoneDst bit (1 - master for Time Zone and DST, 0 - not master for Time Zone and DST)
        uint8_t           superseding   :1,
        uint8_t           reserved      :4  //!<Reserved field
      ))
    }value;
    uint8_t       minVal;       //!<Attribute minimum value
    uint8_t       maxVal;       //!<Attribute maximum value
  } timeStatus;
  /*!
  \brief TimeZone attribute (R/W, O)

  The TimeZone attribute indicates the local time zone, as a signed offset in seconds
  from the Time attribute value. The value 0xffffffff indicates an invalid time zone.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0002)
    uint8_t             type;         //!<Attribute type (signed 32-bit, typeId = 0x29)
    uint8_t             properties;   //!<Attribute properties bitmask
    int32_t             value;        //!<Attribute value (default 0x00000000)
    int32_t             minVal;       //!<Attribute minimum value
    int32_t             maxVal;       //!<Attribute maximum value
  } timeZone;
  /*!
  \brief DstStart attribute (R/W, O)

  The DstStart attribute indicates the DST start time in seconds. The value 0xffffffff
  indicates an invalid DST start time.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0003)
    uint8_t             type;         //!<Attribute type (unsigned 32-bit, typeId = 0x23)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint32_t            value;        //!<Attribute value (default none)
    uint32_t            minVal;       //!<Attribute minimum value
    uint32_t            maxVal;       //!<Attribute maximum value
  } dstStart;
  /*!
  \brief DstEnd attribute (R/W, O)

  The DstEnd attribute indicates the DST end time in seconds. The value 0xffffffff
  indicates an invalid DST end time.
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0004)
    uint8_t             type;         //!<Attribute type (unsigned 32-bit, typeId = 0x23)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint32_t            value;        //!<Attribute value (default none)
    uint32_t            minVal;       //!<Attribute minimum value
    uint32_t            maxVal;       //!<Attribute maximum value
  } dstEnd;
  /*!
  \brief DstShift attribute (R/W, O)

  The DstShift attribute represents a signed offset in seconds from the standard time,
  to be applied between the times DstStart and DstEnd to calculate the Local Time
  (see 3.12.2.2.4). The value 0xffffffff indicates an invalid DST shift. 
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0005)
    uint8_t             type;         //!<Attribute type (signed 32-bit, typeId = 0x29)
    uint8_t             properties;   //!<Attribute properties bitmask
    int32_t             value;        //!<Attribute value (default 0x00000000)
    int32_t             minVal;       //!<Attribute minimum value
    int32_t             maxVal;       //!<Attribute maximum value
  } dstShift;
  /*!
  \brief StandardTime attribute (R, O)

  The local Standard Time is given by the equation in 3.12.2.2.3. Another device on
  the network may calculate this time by reading the Time and TimeZone attributes
  and  adding  them  together.  If  implemented  however,  the  optional  StandardTime
  attribute  indicates  this  time  directly.  The  value  0xffffffff  indicates  an  invalid
  Standard Time. 
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0005)
    uint8_t             type;         //!<Attribute type (unsigned 32-bit, typeId = 0x23)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint32_t            value;        //!<Attribute value (default none)
    uint32_t            minVal;       //!<Attribute minimum value
    uint32_t            maxVal;       //!<Attribute maximum value
  } standardTime;
  /*!
  \brief LocalTime attribute (R, O)

  The  Local  Time  is  given  by  the  equation  in  3.12.2.2.4.  Another  device  on  the
  network may calculate this time by reading the Time, TimeZone, DstStart, DstEnd
  and DstShift attributes and performing the calculation. If implemented however,
  the optional LocalTime attribute indicates this time directly. The value 0xffffffff
  indicates an invalid Local Time.  
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0005)
    uint8_t             type;         //!<Attribute type (unsigned 32-bit, typeId = 0x23)
    uint8_t             properties;   //!<Attribute properties bitmask
    uint32_t            value;        //!<Attribute value (default none)
    uint32_t            minVal;       //!<Attribute minimum value
    uint32_t            maxVal;       //!<Attribute maximum value
  } localTime;
  /*!
  \brief LastSetTime attribute (R, O)

  The  LastSetTime  attribute  indicates  the  most  recent  time  that  the  Time  attribute
  was set, either internally or over the ZigBee network (thus it holds a copy of the
  last value that Time was set to). This attribute is set automatically, so is read only.
  The value 0xffffffff indicates an invalid LastSetTime.   
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0005)
    uint8_t             type;         //!<Attribute type (UTCTime - 32-bit) (typeId = 0xe2, #ZCL_UTC_TIME_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    ZCL_UTCTime_t       value;        //!<Attribute value (default 0xffffffff)
    ZCL_UTCTime_t       minVal;       //!<Attribute minimum value
    ZCL_UTCTime_t       maxVal;       //!<Attribute maximum value
  } lastSetTime;
  /*!
  \brief ValidUntilTime attribute (R/W, O)

  The ValidUntilTime attribute indicates a time, later than LastSetTime, up to which
  the Time attribute may be trusted. �Trusted� means that the difference between the
  Time  attribute  and  the  true  UTC  time  is  less  than  an  acceptable  error.  The
  acceptable error is not defined by this cluster specification, but may be defined by
  the application profile in which devices that use this cluster are specified.    
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;           //!<Attribute Id (0x0005)
    uint8_t             type;         //!<Attribute type (UTCTime - 32-bit) (typeId = 0xe2, #ZCL_UTC_TIME_DATA_TYPE_ID)
    uint8_t             properties;   //!<Attribute properties bitmask
    ZCL_UTCTime_t       value;        //!<Attribute value (default 0xffffffff)
    ZCL_UTCTime_t       minVal;       //!<Attribute minimum value
    ZCL_UTCTime_t       maxVal;       //!<Attribute maximum value
  } validUntilTime;
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_TimeClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t id;
    uint8_t type;
    uint8_t properties;
    uint16_t value;
  } clusterVersion;
} ZCL_TimeClusterClientAttributes_t;

END_PACK
#endif // #ifndef _ZCLTIMECLUSTER_H

//eof zclTimeCluster.h
