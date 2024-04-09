// DOM-IGNORE-BEGIN
/*******************************************************************************
  APSDE Endpoint Header File

  Company
    Microchip Technology Inc.

  File Name
    apsdeEndpoint.h

  Summary
    Interface of APS Endpoint SAP.

  Description
    This header file provides the interface to access APS and application endpoints in Zigbee.
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
 *
 *  The application framework in ZigBee is the environment in which application
 * objects are hosted on ZigBee devices. Up to 254 distinct application objects
 * can be defined, each identified by an endpoint address from 1 to 254.
 *
 *  Two additional endpoints are defined for APSDE-SAP usage: endpoint 0 is
 * reserved for the data interface to the ZDO, and endpoint 255 is reserved for
 * the data interface function to broadcast data to all application objects.
 * See ZigBee Specification r19, 2.1.2, page 18.
 *
 **/
// DOM-IGNORE-END
 
// DOM-IGNORE-BEGIN 
#if !defined _APSDE_ENDPOINT_H
#define _APSDE_ENDPOINT_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
 
#include <zdo/include/appFramework.h>
#include <aps/include/apsdeData.h>

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** struct APS_RegisterEndpointReq_t apsdeEndpoint.h "aps.h"
    Parameters of the APS_RegisterEndpointReq() function
 
    A pointer to an instance of this type shall be passed to APS_RegisterEndpointReq() function
    as an argument to register a new endpoint. The structure contains simple descriptor
    configuration, data indication callback pointer, and the status field. */
typedef struct
{
  /** \cond SERVICE_FIELDS **/
  struct
  {
    void *next;  /*!< Used for queue support. */
    bool noIndication; /*!< Disable indication to upper-layer. */
  } service;
  /** \endcond **/

  /** A pointer to a simple descriptor */
  SimpleDescriptor_t *simpleDescriptor;
  /** A pointer to an indication callback function, which is called when data is received addressed to
   * the endpoint; conforms to APSDE-DATA.indication handler defined in ZigBee spec r19, 2.2.4.1.3.1, page 30. */
  void (*APS_DataInd)(APS_DataInd_t *ind);
  /** The status of endpoint registration; is written by the stack to report the result of the operation */
  APS_Status_t status;
} APS_RegisterEndpointReq_t;

typedef APS_RegisterEndpointReq_t APS_EndpointReg_t;

/** struct APS_UnregisterEndpointReq_t apsdeEndpoint.h "aps.h"
    Parameters of the APS_UnregisterEndpointReq() function */
typedef struct
{
  /*! The endpoint which is to be unregistered. */
  Endpoint_t endpoint;
  /*! The status of endpoint unregistration; is written by the stack to report the result
      * of the operation execution. */
  APS_Status_t status;
} APS_UnregisterEndpointReq_t;

typedef APS_UnregisterEndpointReq_t APS_EndpointUnreg_t;

/** struct Context of action to filter received frame by unexpected ProfileId */
typedef struct _APS_FrameFilteringByProfileIdContext_t
{
  /*! Frame destination endpoint pointer */
  APS_EndpointReg_t *endpoint;
  /*! Conflicting ProfileId */
  ProfileId_t       profileId;
} APS_FrameFilteringByProfileIdContext_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
 
/**************************************************************************//**
   \brief Registers a new endpoint in the APS layer

   The function is used to register an application endpoint. In order to take part in network
   communication the application on the device must register at least one endpoint, since
   data exchange on the application level occurs between two endpoints registered on
   two nodes, which in fact can be a single node as well.

   The function call is done synchronously. The function simply writes an entry containing
   endpoint information to a dedicated internal structure. The request parameters for
   the funciton include simple descriptor configuration, a pointer to the  indication callback
   function, which is to be called upon data reception addressed to the endpoint, and a status
   field, which is written by the stack.

   See the example of request parameters configuration and function usage:
\code
//Global definitions
static ClusterId_t clustersTable[] = {0}; //The list of clusters that the endpoint will support

//Configure the simple descriptor of the endpoint
static SimpleDescriptor_t simpleDescriptor =
{
  .endpoint = APP_ENDPOINT, //Endpoint ID, an arbitrary number between 1 and 240
  .AppDeviceVersion = 1,
  .AppInClustersCount = 1, //The number of suppoted input clusters
  .AppInClustersList = clustersTable,  //The list of supported input clusters
  .AppOutClustersCount = 0,
  .AppOutClustersList = NULL, //Suppose out clusters are not supported
};

//Configure parameters for endpoint registration request
static APS_RegisterEndpointReq_t endpointDesc =
{
  .simpleDescriptor = &simpleDescriptor,
  .APS_DataInd = APS_DataInd,
};

//Data indication callback definition
static void APS_DataInd(APS_DataInd_t *ind)
{
  //Perform appropriate actions, for example, switch on the value of
  //cluster specified in the received frame
  switch (ind->clusterId)
  {
    case CPU_TO_LE16(APP_CLUSTER_ONE):
	...
    case CPU_TO_LE16(APP_CLUSTER_TWO):
	...
  }
}
...
simpleDescriptor.AppProfileId = CPU_TO_LE16(APP_PROFILE_ID);
simpleDescriptor.AppDeviceId = CPU_TO_LE16(1);

APS_RegisterEndpointReq(&endpointDesc);
\endcode
Although it is not required that a variable for the simple descriptor is static or simply defined
in the global scope, it may be convenient to do so to keep track of the endpoint. Note the use
of the CPU_TO_LE16 macro which converts a 16-bit value to a 16-bit little-endian value. Backward
convertion is performed with the LE16_TO_CPU macro.

  Response statuses (req->status values):
  ::APS_SUCCESS_STATUS (0x00) - if registration is a success \n
  ::APS_INVALID_PARAMETER_STATUS (0xA6) - if invalid parameters are provided, or such
    endpoint is already registered
    
  \param req - pointer to the endpoint registration request parameters

  \return None
 ******************************************************************************/
void APS_RegisterEndpointReq(APS_RegisterEndpointReq_t *const req);

/**************************************************************************//**
  \brief Unregisters an endpoint from the APS layer

  Response statuses (req->status values):
  ::APS_SUCCESS_STATUS - if the endpoint has been unregistered successfully \n
  ::APS_INVALID_PARAMETER_STATUS (0xA6) - if invalid parameters are provided, or the
    endpoint is not registered
    
  \param  req - pointer to the endpoint unregistering request parameters
  
  \return None
  
 ******************************************************************************/
void APS_UnregisterEndpointReq(APS_UnregisterEndpointReq_t *const req);

/**************************************************************************//**
  \brief Get next registered endpoint descriptor by previous.

  \param prev - previous endpoint descriptor pointer.It is must be non NULL
                  sequential access required if. And it is must be NULL the
                  first descriptor as registered endpoints queue head element
                  access required if.

  \return Valid endpoint descriptor pointer descriptor found if,
         NULL - other case.
 ******************************************************************************/
APS_RegisterEndpointReq_t* APS_NextEndpoint(const APS_RegisterEndpointReq_t *const prev);

/**************************************************************************//**
   \brief Stops APS Data indications of specific endpoint number.

   \param endpoint - the registered endpoint number. The 0xff special value
                      means all registered endpoints.
   \return None.
 ******************************************************************************/
void APS_StopEndpointIndication(const Endpoint_t endpoint);

/**************************************************************************//**
   \brief Resumes APS Data indications of specific endpoint number.

   \param endpoint - the registered endpoint number. The 0xff special value
                      means all registered endpoints.
   \return None.
 ******************************************************************************/
void APS_ResumeEndpointIndication(const Endpoint_t endpoint);

/*************************************************************************//**
  \brief Matches two profile Ids - registered and from an incoming frame.

  \param endpoint - pointer to destination endpoint.
         inProfileId - profile Id of an incoming APS packet.

  \return None
 *****************************************************************************/
bool APS_IsProfileIdMatched(APS_EndpointReg_t *const endpoint,const ProfileId_t inProfileId);

#endif /* _APSDE_ENDPOINT_H */
/** eof apsdeEndpoint.h */

