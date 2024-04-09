// DOM-IGNORE-BEGIN
/*******************************************************************************
  APS CryptoKeys Header File

  Company
    Microchip Technology Inc.

  File Name
    apsCryptoKeys.h

  Summary
    Access interface to cryptographic keys.

  Description
    This header file provides access interface to cryptographic keys.
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
#if !defined _APS_CRYPTO_KEYS_H
#define _APS_CRYPTO_KEYS_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <nwk/include/nwk.h>

/******************************************************************************
                              Define(s) section
 ******************************************************************************/
 
// DOM-IGNORE-BEGIN
/** Value of the default link key. See CCB 1039. */
#define APS_DEFAULT_LINK_KEY \
  {0x5a, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6c,\
   0x6c, 0x69, 0x61, 0x6e, 0x63, 0x65, 0x30, 0x39}
/** Macro returns true if crypto key handle is valid. */
#define APS_KEY_HANDLE_IS_VALID(handle) ((APS_KeyPairIndex_t)0 <= (handle).idx)
/** Macro returns true if key-pair handle is successfully found. */
#define APS_KEYS_FOUND(handle) APS_KEY_HANDLE_IS_VALID(handle)
/** Macro returns true if security status is related to any security with
 *  link key.*/
#define APS_SECURED_WITH_ANY_LINK_KEY_STATUS(securityStatus) \
  ((APS_SECURED_LINK_KEY_STATUS == securityStatus) || \
   (APS_SECURED_TRUST_CENTER_LINK_KEY_STATUS == securityStatus) || \
   (APS_SECURED_HASH_OF_TRUST_CENTER_LINK_KEY_STATUS == securityStatus))

/** List of invalid and service key handle values. */
/** Initial and finish value of key-pair iterator. */
#define APS_KEY_PAIR_INITIAL -1
#define APS_KEY_PAIR_FINISH  -2
/** Memory for key-pair descriptor is out. */
#define APS_KEY_PAIR_ALLOC_FAIL -3
/** Key-pair is not found by device address. */
#define APS_KEY_PAIR_NOT_FOUND  -4
/** Parameter is out of range. */
#define APS_KEY_PAIR_INVALID_PARAMETER  -5
/** APS Key-Pair Set is not initialized. */
#define APS_KEY_PAIR_NO_INIT  -6

/** Values of reset flag. These request reset master, link keys or counters.
 * Zero or more flags can be bitwise-or'd in argument of APS_ResetKeys. */
#define APS_RESET_MASTER_KEY 0x01 /*!< Set default master key (zero key). */
#define APS_RESET_LINK_KEY   0x02 /*!< Set default link key (zero key). */
#define APS_RESET_COUNTERS   0x04 /*!< Set 0 to incoming and outgoing counters.*/
// DOM-IGNORE-END

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** Type of outgoing frame counter, See ZigBee spec r19, Table 4.37. */
typedef uint32_t ApsOutFrameCounter_t;

/** Type of incoming frame counter. See ZigBee spec r19, Table 4.37. */
typedef uint32_t ApsInFrameCounter_t;

/** Type of Key-Pair Index. */
typedef int16_t APS_KeyPairIndex_t;

/** Type of size of APS Key-Pair Set. */
typedef uint16_t APS_KeyPairAmount_t;

/** Type of cryptographic key handle. */
typedef struct _APS_KeyHandle_t
{
  /** Key index */
  APS_KeyPairIndex_t idx;
  /** Set of flags associated with key */
  uint8_t flags;
} APS_KeyHandle_t;

typedef enum
{
  /** A flag indicating that there is no flags for key pair. */
  APS_FLAG_NONE = 0x00,
  /** A flag indicating that key-pair is used. */
  APS_FLAG_KEY_PAIR_USED = 0x01,
  /** A flag indicating that key-pair is authorized. */
  APS_FLAG_KEY_PAIR_AUTHORIZED = 0x02,
  /** A flag indicating uniquess/globalness of link key. */
  APS_FLAG_KEY_PAIR_GLOBAL = 0x04,
  /** A flag indicating that global key is primary one, used in PAN which
   *  device is participating. */
  APS_FLAG_KEY_PAIR_PRIMARY_GLOBAL = 0x08,
  /** A flag indicating if this is the link key for communication with TC. */
  APS_FLAG_KEY_PAIR_TC = 0x10,
  /** A flag indicating that the link key is updated */
  APS_FLAG_KEY_PAIR_UPDATED = 0x20,
} APS_KeyPairFlags_t;

/** Bit map of reset flags. */
typedef uint8_t APS_KeyResetFlags_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
  \brief Returns key handle in uninitialized state.
  
  \param None

  \return key handle in uninitialized state
 ******************************************************************************/
INLINE APS_KeyHandle_t APS_KeyHandleUninitialized(void)
{
  APS_KeyHandle_t keyHandle =
  {
    .idx = APS_KEY_PAIR_INITIAL,
    .flags = 0U
  };

  return keyHandle;
}

/**************************************************************************//**
  \brief Sets a link key for the device with a given extended address

  This function inserts a new entry into the APS key-pair set containing provided
  link key value and extended address.

  The function shall be called to specify the trust center link key before performing
  network start if high security is used with ::CS_ZDO_SECURITY_STATUS set to 1 or
  standard security with link keys is used.

  In high security, if the trust center link key is unavailable
  ::CS_ZDO_SECURITY_STATUS can be set to 2 or 3; in this case a master key is used to authenticate
  the joining device to launch link key establishment procedure with the trust center.

  For communication with a node different from the trust center a separate link key is also
  needed (an application link key). If it is known to the application it shall be set with
  the use of this function. Otherwise, the application shall either apply a master key to
  launch link key establishment procedure (SKKE) with the partner node or request for a link
  key from the trust center.

  A typical example of the function's usage is given below:
\code
APS_KeyHandle_t apsKeyHandle; //A variable to hold a key handle
//Set a link key variable to a 16-byte value
uint8_t linkKey[SECURITY_KEY_SIZE] = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa};
//A variable for the trust center address predefined in ::CS_APS_TRUST_CENTER_ADDRESS.
ExtAddr_t trustCenterAddr;

//Read the trust center address
CS_ReadParameter(CS_APS_TRUST_CENTER_ADDRESS_ID, &trustCenterAddr);
//Set the trust center link key
apsKeyHandle = APS_SetLinkKey(&trustCenterAddr, linkKey);

//Check for errors
if (APS_KEY_HANDLE_IS_VALID(apsKeyHandle))
{
  ...
}
\endcode

  \param deviceAddress \ref Endian "[LE]" - pointer to
                            extended (IEEE) device address
         linkKey - pointer to a new link key

  \return A valid key handle if operation is successfully completed otherwise
          invalid key handle (Use APS_KEY_HANDLE_IS_VALID to check it out).
 ******************************************************************************/
APS_KeyHandle_t APS_SetLinkKey(const ExtAddr_t *const deviceAddress,const uint8_t *const linkKey);

/**************************************************************************//**
  \brief Sets a master key for the device with a given extended address

  This function inserts a new entry into the APS key-pair set containing provided
  master key value and extended address. Thus it specifies a master key used to launch
  link key establishment (SKKE) with the remote device with the corresponding extended address.

  The function is used in high security with ::CS_ZDO_SECURITY_STATUS set to 2 or 3.
  If ::CS_ZDO_SECURITY_STATUS is set to 2, then before joining the network the device
  shall specify a master key value corresponding to the trust center using this function. The
  master key in pair with the joining device's extended address must be set on the trust
  center via this function as well. If ::CS_ZDO_SECURITY_STATUS is set to 3, then the
  master key must be set only on the trust center. In this case the trust center
  trasfers the master key to the device at the beginning of the authentication procedure.

  The function can also be used to specify application master keys corresponding to devices
  different from the trust center. The need for this occurs when a link key for a remote device
  is unknown. The device shall set a master key value for a remote device with which it wishes to
  communicate and initiate the SKKE procedure to establish the link key by calling the
  APS_EstablishKeyReq() function before sending any data requests to the device.

  See the example of usage below:
\code
APS_KeyHandle_t apsKeyHandle; //A variable to hold a key handle
//Set a master key variable to a 16-byte value
uint8_t masterKey[16] = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa};
//Assume the remote node extended address is held by APP_EXT_ADDR constant
ExtAddr_t partnerExtAddr = APP_EXT_ADDR;

apsKeyHandle = APS_SetMasterKey(&partnerExtAddr, masterKey); //Set the master key

//Check for errors
if (APS_KEY_HANDLE_IS_VALID(apsKeyHandle))
{
  ...
}
\endcode
Note that the APP_EXT_ADDR constant shall contain a 64-bit value in the little endian
format. For this purpose in the definition of the constant convert a common value
to the little endian format using the CCPU_TO_LE64 format as follows:
\code
#define APP_EXT_ADDR     CCPU_TO_LE64(0xAAAAAAAAAAAAAAAALL)
\endcode

An extended address corresponding to a given short address can be obtained
through Device Discovery, while short addresses of devices supporting certain services can be
discovered using Service Discovery.

  \param deviceAddress \ref Endian "[LE]" - pointer to extended
                                                IEEE device address.
         masterKey - pointer to new cryptographic master key.

  \return Valid key handle if operation is successfully completed otherwise
          invalid key handle (Use APS_KEY_HANDLE_IS_VALID to check it out).
 ******************************************************************************/
APS_KeyHandle_t APS_SetMasterKey(const ExtAddr_t *const deviceAddress, const uint8_t *const masterKey);

/**************************************************************************//**
  \brief Find the master key or the link key corresponding to a given extended address

  The function is used to check whether the link key or the master key has been set for a given
  device identified by its extended address and to retrieve a handle to it if one exists. To
  check whether the key has been found use the APS_KEYS_FOUND macro. If the handle is
  valid an access to a key value is got via APS_GetMasterKey() or APS_GetLinkKey().

  See the example:
\code
//Assume that the extended address of interest is held by APP_EXT_ADDR constant
ExtAddr_t partnerExtAddr = APP_EXT_ADDR;

if (!APS_KEYS_FOUND(APS_FindKeys(&partnerExtAddr)))
{
  ... //Perform required action, e.g. request for a link key, using APS_RequestKeyReq()
}
\endcode

  \param deviceAddress \ref Endian "[LE]" - pointer to extended IEEE
                                                device address.

  \return Valid key handle if any key is found otherwise
          invalid key handle (Use APS_KEYS_FOUND to check it out).
 ******************************************************************************/
APS_KeyHandle_t APS_FindKeys(const ExtAddr_t *const deviceAddress);

/**************************************************************************//**
  \brief Get a pointer to the master key value by a given key handle

  The function returns a pointer to the section of memory containing the master key value
  for a given key handle. A key handle points to a certain entry in the APS key-pair set
  corresponding to a specific extended address. To obtain a key handle for a given
  extended address use the APS_FindKeys() function.

  Note that the received pointer must be only used to read the value and not to
  modify it.

  Consider the example:
\code
//Search for keys associated with the provided extended address
const APS_KeyHandle_t keyHandle = APS_FindKeys(&extAddr);

uint8_t *masterKey;

if (APS_KEYS_FOUND(keyHandle) && NULL != (masterKey = APS_GetMasterKey(keyHandle)))
{
  ... //A pointer to the master key value has been successfully captured
}
\endcode


  \param handle - valid key handle.

  \return A pointer to the master key or NULL if the key handle is invalid
 ******************************************************************************/
uint8_t* APS_GetMasterKey(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Get a pointer to the link key value by a given key handle

  The function returns a pointer to the section of memory containing the link key value
  for a given key handle. A key handle points to a certain entry in the APS key-pair set
  corresponding to a specific extended address. To obtain a key handle for a given
  extended address use the APS_FindKeys() function.

  Note that the received pointer must be only used to read the value and not to
  modify it.

  Consider the example:
\code
//Search for keys associated with the provided extended address
const APS_KeyHandle_t keyHandle = APS_FindKeys(&extAddr);

uint8_t *linkKey;

if (APS_KEYS_FOUND(keyHandle) && (linkKey = APS_GetLinkKey(keyHandle)))
{
  ... //A pointer to the link key value has been successfully captured
}
\endcode

  \param handle - valid key handle.

  \return A pointer to the link key or NULL if the key handle is invalid
 ******************************************************************************/
uint8_t* APS_GetLinkKey(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Delete key-pair - master and link keys.

  \param deviceAddress \ref Endian "[LE]" - pointer to extended
                                                IEEE device address.
         notify - notify to upper layer or not.

  \return 'true' if the key-pair is removed otherwise false.
 ******************************************************************************/
bool APS_DeleteKeyPair(ExtAddr_t *const deviceAddress, const bool notify);

/**************************************************************************//**
  \brief Get next key handle.

  \code Example:
    APS_KeyHandle_t handle = APS_KEY_PAIR_INITIAL;

    while (APS_KEYS_FOUND(handle = APS_NextKeys(handle)))
    {
      linkKey = APS_GetLinkKey(handle);
      if (NULL != linkKey)
        ...
      ...
    }
  \endcode

  \param handle - handle of previous key-pair or APS_KEY_PAIR_INITIAL
                      if it's initial call.

  \return if next key-pair is found then return valid key handle
          otherwise return APS_KEY_PAIR_FINISH.
 ******************************************************************************/
APS_KeyHandle_t APS_NextKeys(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief (Un)authorize cryptographic key-pair of given device.

  \param deviceAddress \ref Endian "[LE]" - pointer to extended IEEE
                                                device address.
         status - 'true' for authorized keys otherwise 'false'.

  \return None.
 ******************************************************************************/
void APS_SetAuthorizedStatus(const ExtAddr_t *const deviceAddress,
  const bool status);

/**************************************************************************//**
  \brief Check authorization of crypthographic key-pair.

  \param deviceAddress \ref Endian "[LE]" - pointer to extended
                                                IEEE device address.

  \return 'true' if key-pair is authorized otherwise 'false'.
 ******************************************************************************/
bool APS_AreKeysAuthorized(const ExtAddr_t *const deviceAddress);

/**************************************************************************//**
  \brief Reset device's keys and counters to default values.

  \param deviceAddress \ref Endian "[LE]" - pointer to extended IEEE
                                                device address.
         flags - bit map of APS Key-Pair reset flags. Current implementation
                     supported only APS_RESET_LINK_KEY and APS_RESET_COUNTERS.

  \return APS Key Handle of reseting key-pair or invalid key handle if
          key-pair is not found.
 ******************************************************************************/
APS_KeyHandle_t APS_ResetKeys(const ExtAddr_t *const deviceAddress,
  const APS_KeyResetFlags_t flags);

/**************************************************************************//**
  \brief Init APS key-pair set.

  \param None.

  \return None.
 ******************************************************************************/
void APS_InitKeyPairSet(void);

/**************************************************************************//**
  \brief Reset APS key-pair set.
  \param None
  \return None.
 ******************************************************************************/
void APS_ResetKeyPairSet(void);

/**************************************************************************//**
  \brief Get extended device address of key-pair.

  \param handle - valid key handle.

  \return Pointer to device address or NULL if key-pair is not found..
 ******************************************************************************/
ExtAddr_t* APS_GetKeyPairDeviceAddress(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Find key-pair with old address and set new address.

  \param oldAddress \ref Endian "[LE]" - extended IEEE device
                                             address of key-pair.
         newAddress \ref Endian "[LE]" - new device address of key-pair.
  \return None.
 ******************************************************************************/
void APS_ChangeKeyPairDeviceAddress(const ExtAddr_t oldAddress,
  const ExtAddr_t newAddress);

/**************************************************************************//**
  \brief Get preinstalled link key.

  \param handle - valid key handle.

  \return Pointer to preinstalled link key or NULL if handle is invalid.
 ******************************************************************************/
uint8_t* APS_GetPreinstalledLinkKey(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Set new preinstalled link key for given device.

   This function copies value of preinstalled link key to APS Key-Pair Set.

  \param deviceAddress - pointer to extended IEEE device address.
         preinstalledLinkKey - pointer to new cryptographic preinstalled
                                   link key.

  \return Valid key handle if operation is successfully completed otherwise
          invalid key handle (Use APS_KEY_HANDLE_IS_VALID to check it out).
 ******************************************************************************/
APS_KeyHandle_t APS_SetPreinstalledLinkKey(const ExtAddr_t *const deviceAddress,
  const uint8_t *const preinstalledLinkKey);

/**************************************************************************//**
  \brief Restores link key from preinstalled one.
         Uses to accept TC reestablishing keys with previously joined device.

  \param deviceAddress - pointer to extended IEEE device address.

  \return None.
 ******************************************************************************/
void APS_RestorePreinstalledLinkKey(const ExtAddr_t *const deviceAddress);

/**************************************************************************//**
  \brief Stores link key to preinstalled one.

  \param deviceAddress - pointer to extended IEEE device address.

  \return None.
 ******************************************************************************/
void APS_StorePreinstalledLinkKey(const ExtAddr_t *const deviceAddress);

#ifdef _LINK_SECURITY_
/**************************************************************************//**
  \brief Get current value of outgoing security frames counter.

  \param keyHandle - valid key handle.

  \return Current value of outgoing frame counter.
 ******************************************************************************/
ApsOutFrameCounter_t APS_GetOutSecFrameCounter(const APS_KeyHandle_t keyHandle);

/**************************************************************************//**
  \brief Set the new value of outgoing security frame counter for the device.

  \param deviceAddress - IEEE extended address
         counter - new value of the outgoing security counter for given
                       device.

  \return APS_SUCCESS_STATUS - counter was updated successfuly
          APS_INVALID_PARAMETER_STATUS - if deviceAddress is not correct and
            it's not possible to find any record related to the passed address.
 ******************************************************************************/
APS_Status_t APS_SetOutSecFrameCounter(ExtAddr_t deviceAddress, 
  ApsOutFrameCounter_t counter);

/**************************************************************************//**
  \brief Mark specified gloabal key as 'primary'. It will used as default key for
         all transactions with unknown (unregistered in KeyPairSet) devices
         inside a PAN.

  \param handle - valid global key handle.

  \return None.
 ******************************************************************************/
void APS_MarkGlobalKeyAsPrimary(APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Set the default trust center link key if the the key pair set is empty.
  
  \param None

  \return None.
 ******************************************************************************/
void APS_SetDefaultTcLinkKey(void);

/**************************************************************************//**
  \brief Set the default distributed security link key if the the key pair set is empty.
  
  \param None
  
  \return None.
 ******************************************************************************/
void APS_SetDefaultDsLinkKey(void);


/**************************************************************************//**
  \brief Set extended address for global TC link key.

  \param address - pointer to new extended IEEE TC address.

  \return Valid key handle if operation is successfully completed otherwise
          invalid key handle (Use APS_KEY_HANDLE_IS_VALID to check it out).
 ******************************************************************************/
APS_KeyHandle_t APS_UpdateGlobalTCKey(const ExtAddr_t *const address);

/**************************************************************************//**
  \brief Mark specified global key as 'TC key'. It will be used for communication
         with TC.

  \param handle - valid key handle.

  \return None.
 ******************************************************************************/
void APS_MarkGlobalKeyAsTCKey(APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Sets default key pair status.

  \param flag - new default status.

  \return None.
 ******************************************************************************/
void APS_SetDefaultKeyPairStatus(APS_KeyPairFlags_t flag);

/**************************************************************************//**
  \brief Take a backup of current link key and make the latest link key as operational. 
           This will be used during TCLK update.

  \param deviceAddress - pointer to extended IEEE device address.

  \return None.
 ******************************************************************************/
void APS_UpdateLinkKey(const ExtAddr_t *const deviceAddress);

/**************************************************************************//**
  \brief Take a backup of current link key and make the latest link key as operational. 
           This will be used during TCLK update.

  \param deviceAddress - pointer to extended IEEE device address.

  \return None.
 ******************************************************************************/
void APS_UpdateLinkKey(const ExtAddr_t *const deviceAddress);

/**************************************************************************//**
  \brief Is the handle assocciated with a global or unique link key?

  \param handle - valid key handle.

  \return true if handle is assocciated with a global link key otherwise false.
 ******************************************************************************/
bool APS_IsGlobalLinkKey(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Is the handle assocciated with a updated TCLK or not?

  \param handle - valid key handle.

  \return true if handle is assocciated with a global link key otherwise false.
 ******************************************************************************/
bool APS_IsTclkUpdated(const APS_KeyHandle_t handle);

/**************************************************************************//**
  \brief Find initial (master key for High Security and preinstalled link
         key) or link key of device.

  \param deviceAddress - pointer to extended IEEE device address.

  \return Valid key handle if any key is found otherwise
          invalid key handle (Use APS_KEYS_FOUND to check it out).
 ******************************************************************************/
APS_KeyHandle_t APS_IsIndividualKeyAvailable(const ExtAddr_t *const deviceAddress);

/**************************************************************************//**
  \brief Mark key pair set flags as requested. This won't reset any of the old flags. 

  \param handle - valid key handle.
         flags - required set of flags which needs to be set

  \return None.
 ******************************************************************************/
void APS_MarkKeyPairFlags(APS_KeyHandle_t handle, uint8_t flags);

/**************************************************************************//**
  \brief Clear key pair set flags as requested.

  \param handle - valid key handle.
         flags - required set of flags which needs to be reset

  \return None.
 ******************************************************************************/
void APS_ClearKeyPairFlags(APS_KeyHandle_t handle, uint8_t flags);


#else
#define APS_SetDefaultTcLinkKey() ((void)0)
#define APS_SetDefaultDsLinkKey() ((void)0)
#define APS_ResetKeyPairSet() ((void)0)
#endif /* _LINK_SECURITY_ */
#endif /* _APS_CRYPTO_KEYS_H */
/** eof apsCryptoKeys.h */

