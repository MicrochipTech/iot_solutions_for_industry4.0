// DOM-IGNORE-BEGIN
/*******************************************************************************
  Zigbee Cluster Library Security Manager Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclSecurityManager.h

  Summary:
    The header file describes the ZCL Security Manager and its interface.

  Description:
    The file describes the types and interface of the ZCL Security Manager.
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


#ifndef _ZCLSECURITYMANAGER_H
#define _ZCLSECURITYMANAGER_H

/******************************************************************************
                    Includes section
******************************************************************************/

#if (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)
#include <zcl/include/zcl.h>
#include <zdo/include/zdo.h>
#include <zcl/include/genericEcc.h>
#include <security/serviceprovider/include/sspCommon.h>

/******************************************************************************
                    Types section
 ******************************************************************************/

/** Enumerated status values used in by the security procedures in ZCL */
typedef enum
{
  /*! Key establishment completed successfully, or the Certicom security mode
      is not used. */
  ZCL_SECURITY_STATUS_SUCCESS                = 0x00,
#if CERTICOM_SUPPORT == 1
  /*! The Key Establishment cluster can not be bound, because devices
      supporting it have not been found. */
  ZCL_SECURITY_STATUS_DISCOVERY_FAIL         = 0x01,
  /*! Adding an entry to the local binding table failed while starting
      security. */
  ZCL_SECURITY_STATUS_APS_BINDING_FAIL       = 0x02,
  ZCL_SECURITY_STATUS_TIMEOUT                = 0x03,
  /*! Key establishment has been terminated. */
  ZCL_SECURITY_STATUS_TERMINATED             = 0x04,
  /*! Failed to send one of KE cluster's commands during key establishment. */
  ZCL_SECURITY_STATUS_SEND_COMMAND_FAIL      = 0x05,
  /*! Invalid data (extended address or endpoint) have been provided, or
      the KE cluster is already processing a transaction. */
  ZCL_SECURITY_STATUS_INVALID_SETTINGS       = 0x06,
#endif // CERTICOM_SUPPORT == 1
} ZCL_SecurityStatus_t;


/** Status of ZCL operation
    Used to return status of ZCL operation. */
/*
typedef enum
{
  ZCL_SUCCESS_STATUS                    = 0x00,
  ZCL_UNSUPPORTED_ATTRIBUTE_STATUS      = 0x01,
  ZCL_INVALID_ATTRIBUTE_VALUE_STATUS    = 0x02,
  ZCL_TC_PERMISSION_TABLE_ERROR_STATUS  = 0x03,
  ZCL_APS_LINK_KEY_ERROR_STATUS         = 0x04
} ZCL_Status_t;
*/

BEGIN_PACK
typedef struct PACK
{
  ExtAddr_t addr;                   //!<Destination node 64-bit IEEE address
  uint8_t   key[SECURITY_KEY_SIZE]; //!<APS\INCLUDE\APS Link Key
} ZCL_LinkKeyDesc_t;

typedef struct PACK
{
  ProfileId_t   profileId;
  uint8_t       additional[8];
} ZclKEProfileAttributeData_t;

typedef struct PACK
{
  uint8_t                     publicReconstrKey[SECT163K1_COMPRESSED_PUBLIC_KEY_SIZE];  //22-byte
  ExtAddr_t                   subject;                                                  //8-bytes
  ExtAddr_t                   issuer;                                                   //8-byte
  ZclKEProfileAttributeData_t profileAttributeData;                                     //10-byte
} ZclCertificate_t;

#if CERTICOM_SUPPORT == 1
typedef struct PACK
{
  uint8_t publicKey[SECT163K1_COMPRESSED_PUBLIC_KEY_SIZE]; //!<CA Public Key shared between all nodes in network
  uint8_t privateKey[SECT163K1_PRIVATE_KEY_SIZE];          //!<Node secret key
  uint8_t certificate[SECT163K1_CERTIFICATE_SIZE];         //!<Node certificate derived from CA
} ZCL_CertificateDesc_t;

typedef struct PACK
{
  uint8_t           publicKey[SECT163K1_COMPRESSED_PUBLIC_KEY_SIZE];  //!<CA Public Key shared between all nodes in network
  uint8_t           privateKey[SECT163K1_PRIVATE_KEY_SIZE];           //!<Node secret key
  ZclCertificate_t  certificate;                                      //!<Node certificate derived from CA
} ZCL_KECertificateDescriptor_t;

#endif // CERTICOM_SUPPORT == 1
END_PACK

/** Security variable identifier type. Used by ZCL_Set() and ZCL_Get()
    function to define variable to write or read. */
typedef enum
{
#if CERTICOM_SUPPORT == 1
  /*! Certificate for Key Establishment */
  ZCL_CERTIFICATE_DESC_ID     = 0x00,
#endif // CERTICOM_SUPPORT == 1
  /*! Link key descriptor*/
  ZCL_LINK_KEY_DESC_ID        = 0x01,
  /* Not used */
  ZCL_REMOVE_LINK_KEY_ID      = 0x02,
#if CERTICOM_SUPPORT == 1
  /*! Endpoint asssigned for Key Establishment cluster */
  ZCL_KE_ACTIVE_ENDPOINT_ID   = 0x03,
#endif // CERTICOM_SUPPORT == 1
  /*! Network key */
  ZCL_NETWORK_KEY_ID          = 0x04
} ZCL_SecurityAttrId_t;

/** The structure for security data provided in the ZCL_Set() function */
typedef union
{
#if CERTICOM_SUPPORT == 1
  ZCL_CertificateDesc_t *certificateDesc;   //!< Used with ZCL_CERTIFICATE_DESC_ID
  Endpoint_t            endpoint;           //!< Used with ZCL_KE_ACTIVE_ENDPOINT_ID
#endif // CERTICOM_SUPPORT == 1
  ZCL_LinkKeyDesc_t     *linkKeyDesc;       //!< Used with ZCL_LINK_KEY_DESC_ID
  uint8_t               *networkKey;        //!< Used with ZCL_NETWORK_KEY_ID
  ExtAddr_t             extAddr;            //!< Used with ZCL_REMOVE_LINK_KEY_ID
} ZCL_SecurityAttrValue_t;



typedef struct
{
  ZCL_SecurityAttrId_t    id;
  uint8_t                 length;
  ZCL_SecurityAttrValue_t value;
} ZCL_SecurityAttr_t;

/** Parameters of the ZCL_Set() function */
typedef struct
{
  ZCL_SecurityAttr_t attr;
  ZCL_Status_t       status; //!< The status of setting a security attribute
} ZCL_Set_t;

/** Parameters of the ZCL_Get() function */
typedef struct
{
  ZCL_SecurityAttr_t attr;
  ZCL_Status_t       status; //!< The status of getting a security attribute
} ZCL_Get_t;

/** Confirmation parameters for the start security callback function */
typedef struct
{
  ZCL_SecurityStatus_t status; //!< The status of starting KE security
} ZCL_StartSecurityConf_t;

/** Parameters of the ZCL_StartSecurityReq() function */
typedef struct
{
  ExtAddr_t remoteAddress;
  ZCL_StartSecurityConf_t confirm;
  //! Confirmation callback. Can be set to NULL.
  void (* ZCL_StartSecurityConf)(ZCL_StartSecurityConf_t *conf);
} ZCL_StartSecurityReq_t;
//API

/******************************************************************************
                    External variables section
 ******************************************************************************/

extern Endpoint_t clKEEndpoint;
extern Endpoint_t srvKEEndpoint;

/******************************************************************************
                    Prototypes section
 ******************************************************************************/
 
/*************************************************************************//**
 \brief Resets the security component of ZCL. Resets the Key Establishment
 cluster if Certicom security is used.
 
 \param None
 
 \return None
 *****************************************************************************/
void ZCL_ResetSecurity(void);

/*************************************************************************//**
 \brief Sets security parameters in ZCL

 The function is used in profile-based applications to set various security
 parameters including link keys, network key, and Key Establishment cluster's
 data. The type of security parameter set by the funciton depends on the
 value of the argument's \c attr.id field. Possible values are given by the
 ZCL_SecurityAttrId_t enumeration type.

 The function is executed synchronously.

 Response statuses:
 Accessed via the argument's ZCL_Set_t::status field\n\n
 ::ZCL_SUCCESS_STATUS (0x00) - operation completed successfully \n
 ::ZCL_INVALID_ATTRIBUTE_VALUE_STATUS (0x02) - the provided endpoint is invalid,
   or null certificate description is provided  \n
 ::ZCL_TC_PERMISSION_TABLE_ERROR_STATUS (0x03) - adding the device to the TC
   permission table has failed \n
 ::ZCL_APS_LINK_KEY_ERROR_STATUS (0x04) - setting the link key via APS has failed \n
 ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - an unsupported value has been set
   to the argument's \c attr.id field \n
   
  \param req - request structure to pass attribute id
 
  \return None
 *****************************************************************************/
void ZCL_Set(ZCL_Set_t *req);

/*************************************************************************//**
 \brief Gets security parameters from ZCL

 The function is used in profile-based applications to obtain various security
 parameters including link keys, network key, and Key Establishment cluster's
 data. The type of security parameter obtained by the funciton depends on the
 value of the argument's \c attr.id field. Possible values are given by the
 ZCL_SecurityAttrId_t enumeration type.

 The function is executed synchronously.

 Response statuses:
 Accessed via the argument's ZCL_Get_t::status field\n\n
 ::ZCL_SUCCESS_STATUS (0x00) - operation completed successfully \n
 ::ZCL_INVALID_ATTRIBUTE_VALUE_STATUS (0x02) - the requested link key has not been found,
   the provided endpoint is invalid, or null certificate description is provided  \n
 ::ZCL_UNSUPPORTED_ATTRIBUTE_STATUS (0x86) - an unsupported value has been set
   to the argument's \c attr.id field \n
 
 \param req - request structure to pass attribute id
 
 \return None
  
 *****************************************************************************/
void ZCL_Get(ZCL_Get_t *req);

/*************************************************************************//**
 \brief Initializes the KE cluster, discovers KE devices
 and performs key establishment

 The function should be called in applications supporting the Key Establishment (KE)
 cluster, to perform key establishment procedures. The behavior is different on
 the trust center and common devices.

 On the trust center:
  \li If the \c remoteAddress field is set to 0, KE cluster will be initialized.
      Key establishment will not be performed with any device.
  \li If \c remoteAddress is set to the extended address of a remote device the
      trust center will start key establishment with it.

 On a common device:
  \li If the \c remoteAddress field is set to 0 or to the extended address of the
      trust center, the key establishment with the trust center will start.
  \li Otherwise, the request will eventually fail.

 If Certicom Security is not used, the success status is always reported.

 Response statuses:
 Accessed via the ZCL_StartSecurityConf_t::status field of the
 ZCL_StartSecurityReq_t::ZCL_StartSecurityConf callback's argument. \n
 All possible status codes are wrapped in the ::ZCL_SecurityStatus_t enumeration.
 
 \param req - request structure to pass attribute id
 
 \return None
 *****************************************************************************/
void ZCL_StartSecurityReq(ZCL_StartSecurityReq_t *req);

#if CERTICOM_SUPPORT == 1
/******************************************************************************//**
  \brief Notifies that Key Establishment is finished with status specified in parameters.

  \param status - status of Key Establishment.
  
  \return None
 *****************************************************************************/
void keNotification(ZCL_SecurityStatus_t status);
#endif

#endif // (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)
#endif //#ifndef _ZCLSECURITYMANAGER_H

/** eof zclSecurityManager.h */
