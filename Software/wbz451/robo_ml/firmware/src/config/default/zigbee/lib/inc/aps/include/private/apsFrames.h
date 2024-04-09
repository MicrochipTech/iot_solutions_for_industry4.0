// DOM-IGNORE-BEGIN
/*******************************************************************************
  APS Frames Header File

  Company
    Microchip Technology Inc.

  File Name
    apsFrames.h

  Summary
    Interface of APS frame control fields

  Description
    This header file defines the private interface to the APS frame control fields.
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

#ifndef _APSFRAMES_H_
#define _APSFRAMES_H_

#include <systemenvironment/include/sysEndian.h>
#include <systemenvironment/include/dbg.h>
#include <nwk/include/nwk.h>
#include <aps/include/apsConfigServer.h>
#include <aps/include/apsCommon.h>

/******************************************************************************
                                Define(s) section
******************************************************************************/
#define APS_SM_KEY_SIZE                       16

#define APS_BROADCAST_MAC_RX_ON_SHORT_ADDRESS           0xfffd

//APDU Frame Format

//Frame control field - ApduFrameControlField_t

//Frame Type subfield values
#define APDU_FRAME_CONTROL_FIELD_DATA_FRAME_TYPE                  0x00
#define APDU_FRAME_CONTROL_FIELD_COMMAND_FRAME_TYPE               0x01
#define APDU_FRAME_CONTROL_FIELD_ACK_FRAME_TYPE                   0x02
#define APDU_FRAME_CONTROL_FIELD_RESERVED_FRAME_TYPE              0x03

//Delivery Mode subfield values
#define APDU_FRAME_CONTROL_FIELD_UNICAST_MODE                     0x00
#define APDU_FRAME_CONTROL_FIELD_RESERVED_MODE                    0x01
#define APDU_FRAME_CONTROL_FIELD_BROADCAST_MODE                   0x02
#define APDU_FRAME_CONTROL_FIELD_GROUP_ADDRESSING_MODE            0x03

//Ack Format subfiel values
#define APDU_FRAME_CONTROL_FIELD_DATA_ACK_FORMAT                  0x00
#define APDU_FRAME_CONTROL_FIELD_COMMAND_ACK_FORMAT               0x01

//Security subfield values
#define APDU_FRAME_CONTROL_FIELD_NOTSECURED                       0x00
#define APDU_FRAME_CONTROL_FIELD_SECURED                          0x01

//Acknowledgement Request subfield values
#define APDU_FRAME_CONTROL_FIELD_NOACK                            0x00
#define APDU_FRAME_CONTROL_FIELD_ACK                              0x01

//Extended Header Present subfield values
#define APDU_FRAME_CONTROL_FIELD_EXTENDED_HEADER_NOT_PRESENT      0x00
#define APDU_FRAME_CONTROL_FIELD_EXTENDED_HEADER_PRESENT          0x01


//Extended Frame Control field - ApduExtendedFrameControlField_t
//Fragmentation subfield values
#define APDU_EXT_FRAME_CONTROL_FIELD_FRAGMENTATION_NOT_FRAGMENTED   0x00
#define APDU_EXT_FRAME_CONTROL_FIELD_FRAGMENTATION_FIRST_FRAGMENT   0x01
#define APDU_EXT_FRAME_CONTROL_FIELD_FRAGMENTATION_FRAGMENT         0x02
#define APDU_EXT_FRAME_CONTROL_FIELD_FRAGMENTATION_RESERVED         0x03

/* Maximum length of auxilary header for aps commands. */
#define APS_MAX_AUXILIARY_HEADER_LENGTH  14U

/******************************************************************************
                   Types section
******************************************************************************/
//APDU Frame Format
//Frame control field
BEGIN_PACK
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(6, (
    uint8_t frameType               :2,
    uint8_t deliveryMode            :2,
    uint8_t ackFormat               :1,
    uint8_t security                :1,
    uint8_t ackRequest              :1,
    uint8_t extendedHeaderPresent   :1
  ))
} ApduFrameControlField_t;

//Extended Frame Control field
typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(2, (
    uint8_t fragmentation   :2,
    uint8_t reserved        :6
  ))
} ApduExtendedFrameControlField_t;

typedef struct PACK
{
  ApduExtendedFrameControlField_t extendedFrameControl;
  uint8_t blockNumber;
  uint8_t ackBitfield;
} ApduFragmentedAckExtendedHeaderSubframe_t;

typedef struct PACK
{
  ApduExtendedFrameControlField_t extendedFrameControl;
} ApduNotFragmentedAckExtendedHeaderSubframe_t;

typedef struct PACK
{
  ApduExtendedFrameControlField_t extendedFrameControl;
  uint8_t blockNumber;
} ApduFragmentedDataExtendedHeaderSubframe_t;

typedef struct PACK
{
  ApduExtendedFrameControlField_t extendedFrameControl;
} ApduNotFragmentedDataExtendedHeaderSubframe_t;

typedef struct PACK
{
  ApduFrameControlField_t frameControl;
  uint8_t dstEndpoint;
  uint16_t clusterId;
  uint16_t profileId;
  uint8_t srcEndpoint;
  uint8_t apsCounter;
  union PACK
  {
    ApduNotFragmentedDataExtendedHeaderSubframe_t notFragmentedExtHeaderSubframe;
    ApduFragmentedDataExtendedHeaderSubframe_t fragmentedExtHeaderSubframe;    //Extended header subframe
  };
} ApduDataFrameNongroup_t;

typedef struct PACK
{
  ApduFrameControlField_t frameControl;
  uint16_t groupAddress;
  uint16_t clusterId;
  uint16_t profileId;
  uint8_t srcEndpoint;
  uint8_t apsCounter;
} ApduDataFrameGroup_t;

typedef struct PACK
{
  ApduFrameControlField_t frameControl;                 //Frame Control field
  uint8_t dstEndpoint;                                  //Destination endpoint
  uint16_t clusterId;                                   //Cluster identifier
  uint16_t profileId;                                   //Profile identifier
  uint8_t srcEndpoint;                                  //Source endpoint
  uint8_t apsCounter;                                   //APS counter
  union PACK
  {
    ApduNotFragmentedAckExtendedHeaderSubframe_t notFragmentedExtHeaderSubframe;
    ApduFragmentedAckExtendedHeaderSubframe_t fragmentedExtHeaderSubframe;    //Extended header subframe
  };
} ApduAcknowledgementFrame_t;

typedef struct PACK
{
  ApduFrameControlField_t frameControl;                 //Frame Control field
  uint8_t apsCounter;                                   //APS counter
} ApduCommandAcknowledgementFrame_t;
END_PACK

/******************************************************************************
                   Prototypes section
******************************************************************************/
#ifdef _LINK_SECURITY_
/***************************************************************************//**
  \brief Returns APS frame header size

  \param[in] apdu - pointer to frame

  \return size of APS frame header
*******************************************************************************/
APS_PRIVATE uint8_t apsGetHeaderSize(uint8_t *apdu);
#endif /* _LINK_SECURITY_ */

#endif /* _APSFRAMES_H_ */
