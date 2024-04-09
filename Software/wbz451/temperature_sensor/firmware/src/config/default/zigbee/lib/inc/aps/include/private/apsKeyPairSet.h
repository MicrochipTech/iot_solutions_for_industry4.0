// DOM-IGNORE-BEGIN
/*******************************************************************************
  APS KeyPairSet Header File

  Company
    Microchip Technology Inc.

  File Name
    apsKeyPairSet.h

  Summary
    Private interface of APS Key-Pair Set.

  Description
    This header file defines the interface to the APS Key-Pair Set functions.
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

#if !defined _APS_KEY_PAIR_SET_H
#define _APS_KEY_PAIR_SET_H

#if defined _LINK_SECURITY_
/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <aps/include/apsCryptoKeys.h>
#include <security/serviceprovider/include/sspCommon.h>

/******************************************************************************
                               Definitions section
 ******************************************************************************/
/** Size of APS security counter in bytes */
#define APS_SECURITY_COUNTER_SIZE 4U

/******************************************************************************
                                Types section
 ******************************************************************************/
/* Type of outgoing frame counter higher bytes. */
typedef uint16_t ApsOutFrameCounterTop_t;
/* Type of outgoing frame counter lower bytes. */
typedef uint16_t ApsOutFrameCounterLow_t;

/* Unsigned type of Key-Pair Index. */
typedef APS_KeyPairAmount_t ApsKeyPairUIndex_t;

/** Outgoing security frame counter handle type. */
BEGIN_PACK
typedef union PACK
{
  ApsOutFrameCounter_t value;
  struct
  {
    LITTLE_ENDIAN_OCTET(2,
      (ApsOutFrameCounterLow_t low,
       ApsOutFrameCounterTop_t top))
  } part;
} ApsOutFrameCounterHandle_t;
END_PACK

/* Type of key-pair descriptor. */
typedef struct _ApsKeyPairDescriptor_t
{
  /* Identifies the address of the entity with which this key-pair is shared. */
  ExtAddr_t deviceAddress;
  /* Outgoing frame counter higher bytes. */
  ApsOutFrameCounterTop_t outCounterTop;
  /* Bitmask of flags indicating entry status/type */
  uint8_t flags;
  /* The actual value of the initial key:
     master key for High Security and preinstalled link key for SE Security. */
  uint8_t initialKey[SECURITY_KEY_SIZE];
  /* The actual value of the link key. */
  uint8_t linkKey[SECURITY_KEY_SIZE];
} ApsKeyPairDescriptor_t;

/* Type of incoming and outgoing counters. */
typedef struct _ApsKeyCounters_t
{
  /* Outgoing frame counter lower bytes. */
  ApsOutFrameCounterLow_t outCounterLow;
  /* Incoming frame counter value corresponding to DeviceAddress. */
  ApsInFrameCounter_t in;
} ApsKeyCounters_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Get current value of outgoing frame counter and increment it.

  \param[in] keyHandle - valid key handle.

  \return Pointer to current value of outgoing frame counter.
 ******************************************************************************/
APS_PRIVATE
ApsOutFrameCounter_t apsGetUpdatedOutFrameCounter(const APS_KeyHandle_t keyHandle);

/**************************************************************************//**
  \brief Get current value of incoming frame counter.

  \param[in] handle - valid key handle.

  \return Pointer to current value of incoming frame counter.
 ******************************************************************************/
APS_PRIVATE
ApsInFrameCounter_t apsGetInFrameCounter(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Is the handle assocciated with a global or unique link key?

  \param[in] handle - valid key handle.

  \return true if handle is assocciated with a global link key otherwise false.
 ******************************************************************************/
APS_PRIVATE bool apsIsGlobalLinkKey(const APS_KeyHandle_t handle);

#endif /* _LINK_SECURITY_ */

#endif /* _APS_KEY_PAIR_SET_H */
/** eof apsKeyPairSet.h */

