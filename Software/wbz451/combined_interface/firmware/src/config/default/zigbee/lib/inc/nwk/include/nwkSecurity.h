// DOM-IGNORE-BEGIN
/*******************************************************************************
  NWK Security Header File

  Company:
    Microchip Technology Inc.

  File Name:
    nwkSecurity.h

  Summary:
    This file contains the Network security interface.

  Description:
    This file contains the Network security interface.
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


/**//**
 *  The NWK layer is responsible for the processing steps needed to securely
 * transmit outgoing frames and securely receive incoming frames. Upper layers
 * control the security processing operations by setting up the appropriate keys
 * and frame counters and establishing which security level to use.
 * ZigBee spec r17, 4.3, page 426.
 **/
// DOM-IGNORE-END

// DOM-IGNORE-BEGIN
#if !defined _NWK_SECURITY_H && defined _SECURITY_
#define _NWK_SECURITY_H
// DOM-IGNORE-END

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <security/serviceprovider/include/sspCommon.h>
#include <mac_phy/include/mac.h>
#include <nwk/include/nlmeReset.h>

/******************************************************************************
                                Define(s) section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
#define NWK_PRECONFIGURED_NETWORK_KEY 0U
#define NWK_NOT_PRECONFIGURED_NETWORK_KEY 3U

/** Amount of incoming frame counters. */
#define NWK_IN_FRAMES_MAX 4U
/** Startup active network key sequence number */
#define NWK_STARTUP_ACTIVE_KEY_SEQUENCE_NUMBER 0U
/** Size of security counter in bytes */
#define NWK_SIZE_OF_SECURITY_COUNTER 4U
/** Max threshold for frame counter to update the key */
#define NWK_SEC_FRAME_COUNTER_THRESHOLD_2B 0x8000u
#define NWK_SEC_FRAME_COUNTER_THRESHOLD_4B 0x80000000u
/** Invalid outgoing frame counter */
#define NWK_INVALID_OUT_FRAME_COUNTER_VALUE CCPU_TO_LE32(UINT32_MAX)
// DOM-IGNORE-END

/******************************************************************************
                                 Types section
 ******************************************************************************/
/** Type of NWK Key Sequence Number. */
typedef uint8_t NWK_KeySeqNum_t;
/** Type of NWK Key Index and amount. */
typedef uint8_t NwkKeyAmount_t;
typedef NwkKeyAmount_t NwkKeyIndex_t;

/** Type of outgoing frame counter used for outgoing frames. */
typedef uint32_t NwkOutFrameCounter_t;
/** Type of incoming frame counter used for incoming frames. */
typedef uint32_t NwkInFrameCounter_t;
/** Type of outgoing frame counter higher bytes. */
typedef uint16_t NwkOutFrameCounterTop_t;
/** Type of outgoing frame counter lower bytes. */
typedef uint16_t NwkOutFrameCounterLow_t;

/** Outgoing security frame counter handle type. */
BEGIN_PACK
typedef union PACK
{
  NwkOutFrameCounter_t value;
  struct
  {
    LITTLE_ENDIAN_OCTET(2,
      (NwkOutFrameCounterLow_t low,
       NwkOutFrameCounterTop_t top
      ))
  } part;
} NwkOutFrameCounterHandle_t;
END_PACK

BEGIN_PACK
typedef union PACK _NwkUnalignedInFrameCounter_t
{
  NwkInFrameCounter_t value;
  uint8_t raw[sizeof(NwkInFrameCounter_t)];
} NwkUnalignedInFrameCounter_t;
END_PACK

/** The Incoming Frame Counter Descriptor. */
typedef struct _NWK_InFrameCounterSetEntry_t
{
  /** Extended device address. */
  ExtAddr_t senderAddress;
  /** Incoming frame counter used for incoming frames. */
  NwkInFrameCounter_t value;
} NWK_InFrameCounterEntry_t;

/** Type of the incoming frame counter table */
typedef struct _NWK_InFrameCounterSet_t
{
  /** Pointer to first entry of the incoming frame counter table */
  NWK_InFrameCounterEntry_t *table;
  /** Pointer to memory area after last entry of the incoming frame counter table */
  NWK_InFrameCounterEntry_t *end;

} NwkInFrameCounterSet_t;

/** The Network Security Material Descriptor - key and key sequence number. */
typedef struct _NWK_SecurityKey_t
{
  bool isSet; /** Flag indicates busy status of entry. */
  /** A sequence number assigned to a network key by the Trust Center and used
   * to distinguish network keys for purposes of key updates, and incoming
   * frame security operations. */
  NWK_KeySeqNum_t seqNum;
  /** The actual value of the key. */
  uint8_t value[SECURITY_KEY_SIZE];
  
  #if defined _NWK_IN_FRAME_COUNTERS_
  /** Pointer to start incoming frame counter set */
  NwkInFrameCounterSet_t inFrameCounterSet;
  #endif
} NWK_SecurityKey_t;

/** The Network Security Material Descriptor - incoming and outgoing frame counters. */
typedef struct _NWK_SecurityFrameCounters_t
{
  /** Outgoing frame counter lower bytes. */
  NwkOutFrameCounterLow_t outCounterLow;
  /** Outgoing frame counter higher bytes. Common value for all NWK keys. */
  NwkOutFrameCounterTop_t outCounterTop;
} NWK_SecurityFrameCounters_t;

/** Security-Related NIB Attributes. */
typedef struct _NWK_SecurityIB_t
{
  /** Private field for internal use - the index of active key. */
  NwkKeyIndex_t activeIndex;
  /** The security level for outgoing and incoming NWK frames. */
  uint8_t securityLevel;
  /** Indicates whether security shall be applied to incoming
   * and outgoing NWK data frames. */
  bool secureAllFrames;
} NWK_SecurityIB_t;

/******************************************************************************
                               Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Get value of the nwkSecurityLevel attribute.

    ZigBee spec r17, page 344, Table 3.44.

  \return Current value of nwkSecurityLevel.
 ******************************************************************************/
uint8_t NWK_GetSecurityLevel(void);

/**************************************************************************//**
  \brief Getting value of nwkSecureAllFrames attribute.
    ZigBee spec r17, page 344, Table 3.44.

  \return Current value of nwkSecureAllFrames.
 ******************************************************************************/
bool NWK_GetSecureAllFrames(void);

/**************************************************************************//**
  \brief Set a new network key.

  \param[in] key - a new network security key.
  \param[in] keySeqNum - key sequence number.
  \return 'true' if operation was completed successfully otherwise 'false'.
 ******************************************************************************/
bool NWK_SetKey(const uint8_t *const key, const NWK_KeySeqNum_t keySeqNum);

/**************************************************************************//**
  \brief Set NWK key as active.

  \param[in] keySeqNum - key sequence number.
  \return 'true' if operation was completed successfully otherwise 'false'.
 ******************************************************************************/
bool NWK_ActivateKey(const NWK_KeySeqNum_t keySeqNum);

/**************************************************************************//**
  \brief Check active network key.

  \return 'true' if active NWK key is set otherwise 'false'.
 ******************************************************************************/
bool NWK_IsAnyKeyActivated(void);

/**************************************************************************//**
  \brief Get active network key.

  \return Pointer to value of active network key.
 ******************************************************************************/
const uint8_t* NWK_GetActiveKey(void);

/**************************************************************************//**
  \brief Getting value of nwkActiveKeySeqNumber attribute.
     ZigBee spec r17, page 344, Table 3.44.

  \return Current value of nwkActiveKeySeqNumber.
 ******************************************************************************/
NWK_KeySeqNum_t NWK_GetActiveKeySeqNumber(void);

/**************************************************************************//**
  \brief Update outgoing security frame counter of active NWK key and return
         it's value.

  \return Outgoing frame counter in little-endian format.
 ******************************************************************************/
NwkOutFrameCounter_t NWK_GetUpdatedSecOutCounter(void);

/**************************************************************************//**
  \brief Return outgoing security frame counter value of active NWK key

  \return Outgoing frame counter in little-endian format.
 ******************************************************************************/
NwkOutFrameCounter_t NWK_GetSecOutCounter(void);

/**************************************************************************//**
  \brief Return incoming security frame counter value of active NWK key

  \param[in] srcExtAddr - pointer to extended source address
  \param[in,out] counter - valid current incoming counter value if address is present
  \return 'true' if address is present is present otherwise 'false'
 ******************************************************************************/
bool NWK_GetSecInCounter(const ExtAddr_t *const srcExtAddr, NwkInFrameCounter_t *counter);

/**************************************************************************//**
  \brief Update the incoming frame counter.

  \param[in] seqNum - key sequence number.
  \param[in] srcExtAddr - pointer to extended source address.
  \param[in] counter - a new value of the incoming frame counter.
  \return None.
 ******************************************************************************/
void NWK_SetInFrameCounter(const NWK_KeySeqNum_t seqNum, const ExtAddr_t *const srcExtAddr,
  const NwkInFrameCounter_t *const counter);

/**************************************************************************//**
  \brief Remove the incoming frame counter by IEEE address.

  \param[in] srcExtAddr - pointer to extended source address.
  \return None.
 ******************************************************************************/
void NWK_RemoveInFrameCounterByExtAddr(const ExtAddr_t *const srcExtAddr);

/**************************************************************************//**
  \brief Deactivate current active NWK key.
 ******************************************************************************/
void NWK_DeactivateKey(void);

/**************************************************************************//**
  \brief Set all incoming and outgoing frame counters to zero.
 ******************************************************************************/
void NWK_ResetAllSecurityCounters(void);

/**************************************************************************//**
  \brief Reseting the network security subsystem.

  \return None.
 ******************************************************************************/
void NWK_ResetSecurityIB(void);

/**************************************************************************//**
  \brief Checks, if security services are provided by NWK.

  \return True, if security services are provided by NWK, false - otherwise.
 ******************************************************************************/
bool NWK_IsSecurityProvided(void);


/**************************************************************************//**
  \brief Changes the maximum number of stored NWK security keys.

  \param[in] keyAmount - new total amount of NWK keys.

  \return NWK_SUCCESS_STATUS if keyAmount is changed successfuly otherwise
          return NWK_INVALID_PARAMETERS_STATUS.
 ******************************************************************************/
NWK_Status_t NWK_SetKeyAmount(const uint8_t keyAmount);



/**************************************************************************//**
  \brief Stores security counter of outgoing frames

  \return Outgoing frames security counter handle
 ******************************************************************************/
NWK_Status_t NWK_SetSecOutCounter(NwkOutFrameCounterHandle_t *outCounterHandle);



#endif /* _NWK_SECURITY_H and _SECURITY_ */
/** eof nwkSecurity.h */


