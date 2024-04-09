/*******************************************************************************
   Image Stoarge Driver Header File

  Company:
    Microchip Technology Inc.

  File Name:
    isdImageStorage.h

  Summary:
    This file contains the public API of the image storage driver..

  Description:
    This file contains the public API of the image storage driver.
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

#ifndef _ISDIMAGESTORAGE_H
#define _ISDIMAGESTORAGE_H

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <z3device/otau/isd/include/isdConsoleTunneling.h>


/******************************************************************************
                   Define(s) section
******************************************************************************/
// Debug info
#define ISD_NULLCALLBACK0   0x2980
#define ISD_NULLCALLBACK1   0x2981
#define ISD_NULLCALLBACK2   0x2982
#define ISD_NULLCALLBACK3   0x2983

#ifndef ISD_COMMUNICATION_RETRY_COUNT
#define ISD_COMMUNICATION_RETRY_COUNT   3
#endif

/** \brief Statuses returned by the driver */
typedef enum
{
  ISD_NO_COMMUNICATION,
  ISD_IDLE,
  ISD_BUSY,
  ISD_HARDWARE_FAULT
} ISD_Status_t;


/******************************************************************************
                   Types section
******************************************************************************/

typedef void (* IsdOpenCb_t)(ISD_Status_t);
typedef void (* IsdQueryNextImageCb_t)(ZCL_OtauQueryNextImageResp_t *);
typedef void (* IsdImageBlockCb_t)(ZCL_OtauImageBlockResp_t *);
typedef void (* IsdUpgradeEndCb_t)(ZCL_OtauUpgradeEndResp_t *);
typedef void (* IsdDefaultRespCb_t)(ZCL_DefaultResp_t *);

/******************************************************************************
                   Prototypes section
******************************************************************************/
/**************************************************************************//**
\brief Opens the serial interface for connection with the image storage

The serial interface captured by executing this function may not be used
until OFD_Close() is called.

\param[in] cb - pointer to a callback function called once the interface is opened;
                can be set to NULL
******************************************************************************/
bool ISD_Open(IsdOpenCb_t cb);

/**************************************************************************//**
\brief Closes the serial interface opened using ISD_Open()
******************************************************************************/
void ISD_Close(void);

/**************************************************************************//**
\brief Sends a query next image request to the storage system, which should decide
whether the request's issuer needs a new image

The response to this command received from the storage system should be somehow
delivered to the client. If the storage system decides that the client needs a new
image the client may then start sending image block requests to retrieve individual
blocks of the new image.

Whether the client device should download a new image is indicated by the \c status
field of the callback's argument (which is of ZCL_OtauQueryNextImageResp_t type)
having the ::ZCL_SUCCESS_STATUS value.

\param[in]
  addressing - pointer to structure that contains network information
  about the client including network address, endpoint, cluster ID and profile ID
\param[in]
  data - data payload containing information about client's firmware
\param[in]
  cb - pointer to a callback function called when the response is received
  from the storage system; can be set to NULL
******************************************************************************/
void ISD_QueryNextImageReq(ZCL_Addressing_t *addressing, ZCL_OtauQueryNextImageReq_t *data, IsdQueryNextImageCb_t cb);

/**************************************************************************//**
\brief Sends an image block request to the storage system, in order to retrieve
a certain block of data of the specified image

The function requests an individual block (specified by the offset inside the image
and having the OFD_BLOCK_SIZE length) of the specific image from the storage system.
The image is specified by its image type, manufacturer ID and firmware version.

The storage system replies with the response comman containing the requested data
(if all information is correct). Response reception is indicated by the callback
function.

\param[in]
  addressing - pointer to the structure that contains network information
  about the client including network address, endpoint, cluster ID and profile ID
\param[in]
  data - data payload containing information about the requested block of data and
  the image
\param[in]
  cb - pointer to a callback function called when the response is received
  from the storage system; can be set to NULL
******************************************************************************/
void ISD_ImageBlockReq(ZCL_Addressing_t *addressing, ZCL_OtauImageBlockReq_t *data, IsdImageBlockCb_t cb);

/**************************************************************************//**
\brief Sends an upgrade end request to the storage system, notifying it that
all blocks have been received

The function notifies the storage system that the client has received the whole
image. The storage system replies with the update end response that specifies the
time after which the client should switch to the new image.

\param[in]
  addressing - pointer to the structure that contains network information
  about the client including network address, endpoint, cluster ID and profile ID
\param[in]
  data - data payload containg information about the image that has been downloaded
  to the client
\param[in]
  cb - pointer to a callback function called when the response is received
  from the storage system; can be set to NULL
******************************************************************************/
void ISD_UpgradeEndReq(ZCL_Addressing_t *addressing, ZCL_OtauUpgradeEndReq_t *data, IsdUpgradeEndCb_t cb);
void ISD_ZCLDefaultResp(ZCL_Addressing_t *addressing, ZCL_DefaultResp_t*data, IsdDefaultRespCb_t cb);

/**************************************************************************//**
\brief Initialize ISD tunnel.

\param[in] descriptor - pointer to USART descriptor

\return zero value if tunnel was initialized, false otherwise.
******************************************************************************/
bool ISD_OpenUsart(ISD_TunnelDescriptor_t *descriptor);


/**************************************************************************//**
\brief Returns the total size of the image to be upgraded.

\param[in] none

\return Total size of the image to be upgraded
******************************************************************************/

uint32_t ISD_GetTotalImageSize (void);

/**************************************************************************//**
\brief Get the state of ISD

\param[in] state - actual ISD state
******************************************************************************/
ISD_Status_t isdGetState(void);

#endif /* _ISDIMAGESTORAGE_H */