/**************************************************************************//**
\file   ofdMemoryDriver.h

\brief  The implementation interface of external flash.

\author
    Atmel Corporation: http://www.atmel.com \n
    Support email: avr@atmel.com

  Copyright (c) 2008-2015, Atmel Corporation. All rights reserved.
  Licensed under Atmel's Limited License Agreement (BitCloudTM).

\internal
  History:
    31/07/09 A. Khromykh - Created
*******************************************************************************/
/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/
#ifndef _OFDMEMORYDRIVER_H
#define _OFDMEMORYDRIVER_H

#if APP_USE_OTAU == 1

#include "definitions.h"

/******************************************************************************
                   Includes section
******************************************************************************/

/******************************************************************************
                   Define(s) section
******************************************************************************/
/*Common Definitions*/
#if !defined _PIC32CX_BZ3_ 
  #define OFD_IMAGE_START_ADDRESS    (0x01080000) // SLOT 2 start address 
  #define OFD_IMAGE_END_ADDRESS     (0x010fC000) 
  #define OFD_IMAGE_MAX_SIZE    (OFD_IMAGE_END_ADDRESS - OFD_IMAGE_START_ADDRESS)
#else
  #define OFD_IMAGE_START_ADDRESS   (0x00000000) // SLOT 2 start address 
  #define OFD_IMAGE_END_ADDRESS     (0x00080000)
  #define OFD_IMAGE_MAX_SIZE    (OFD_IMAGE_END_ADDRESS - OFD_IMAGE_START_ADDRESS)
#endif

#define OFD_LITTLE_TO_BIG_ENDIAN(A)  ((((uint32_t)A & 0xFFul) << 24)   \
                                   | (((uint32_t)A & 0xFF00ul) << 8)   \
                                   | (((uint32_t)A >> 8) & 0xFF00ul)   \
                                   | (((uint32_t)A >> 24) & 0xFFul))


/** \brief Status messages for upper component about the OFD state */
typedef enum
{
  OFD_STATUS_SUCCESS = 0,
  OFD_STATUS_SERIAL_BUSY,
  OFD_STATUS_UNKNOWN_EXTERNAL_FLASH_TYPE,
  OFD_STATUS_INCORRECT_API_PARAMETER,
  OFD_STATUS_INCORRECT_EEPROM_PARAMETER,
  OFD_SERIAL_INTERFACE_BUSY
} OFD_Status_t ;

/** \brief Parameters for access to the FLASH  \n
 offset - offset from start address  \n
 data - pointer to MCU RAM area with\for data for\from FLASH  \n
 length - size of MCU RAM area with\for data. */
typedef struct
{
  uint32_t  offset;
  uint32_t  length;
  uint8_t  *data;
  uint8_t  ofdWriteRetry;
} OFD_MemoryAccessParam_t;

// image type table
typedef uint8_t OfdImageTable_t;

typedef void (* OFD_Callback_t)(OFD_Status_t);

/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Starts image erasing in the external memory.
******************************************************************************/
void ofdEraseImage(void);

/**************************************************************************//**
\brief Writes data to the external memory.
******************************************************************************/
void ofdWriteData(void);

/**************************************************************************//**
\brief Checks image crc.
******************************************************************************/
void ofdCheckCrc(void);

/**************************************************************************//**
\brief Starts saving internal flash.
******************************************************************************/
void ofdSaveCurrentFlashImage(void);

/**************************************************************************//**
\brief Reads image crc from internal eeprom.
******************************************************************************/
void ofdReadCrc(void);

/**************************************************************************//**
\brief Counts crc current memory area. CRC-8. Polynom 0x31    x^8 + x^5 + x^4 + 1.

\param[in]
  crc - first crc state
\param[in]
  pcBlock - pointer to the memory for crc counting
\param[in]
  length - memory size

\return
  current area crc
******************************************************************************/
uint8_t ofdCrc(uint8_t crc, uint8_t *pcBlock, uint8_t length);

/**************************************************************************//**
\brief Finds storage space.
******************************************************************************/
void ofdFindStorageSpace(void);

/**************************************************************************//**
\brief Sets action for internal bootloader.
******************************************************************************/
void ofdSetActionForBootloader(void);

/**************************************************************************//**
\brief Flushs memory buffer to flash.
******************************************************************************/
void ofdFlushData(void);
/**************************************************************************//**
\brief Writes data to the external memory

The function writes a piece of the new image (specified by its image position \c pos)
at a given offset to the external memory.

The function can be called for the first time only after the serial interface
has been opened by OFD_Open() and the memory at the specified image position has
been erased by OFD_EraseImage().


\param[in]
  accessParam - pointer to the structure containing: data offset, pointer to the
  buffer with the received data, and its length.
\param[in]
  cb - pointer to a callback function; must not be set to NULL
******************************************************************************/
bool OFD_Write(OFD_MemoryAccessParam_t *accessParam);

/**************************************************************************//**
\brief Reads data from the external memory

The function reads a piece of the data (specified by its image position \c pos)
at a given offset to the external memory.

The function can be called for the first time only after the serial interface
has been opened by OFD_Open() and the memory at the specified image position has
been erased by OFD_EraseImage().

\param[in]
  pos - image position of the data
\param[in]
  accessParam - pointer to the structure containing: data offset, pointer to the
  buffer with the received data, and its length.
\param[in]
  cb - pointer to a callback function; must not be set to NULL
******************************************************************************/
void OFD_Read(uint32_t address, uint8_t *data, uint16_t size, OFD_Callback_t cb);
#endif // APP_USE_OTAU == 1

#endif /* _OFDMEMORYDRIVER_H */
