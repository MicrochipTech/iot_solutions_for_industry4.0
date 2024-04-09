// DOM-IGNORE-BEGIN
/*******************************************************************************
  zigbee device object commands Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zdoCommands.h

  Summary:
    This file contains the Interface of ZDO commands: ZDP commands, stack requests and etc.

  Description:
    This file contains the Interface of ZDO commands: ZDP commands, stack requests and etc.
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
#if !defined _ZDO_COMMANDS_H
#define _ZDO_COMMANDS_H
// DOM-IGNORE-END

/******************************************************************************
                               Includes section
 ******************************************************************************/
#include <zdo/include/zdo.h>

/******************************************************************************
                             Definitions section
 ******************************************************************************/
// DOM-IGNORE-BEGIN
#define ZDP_RESP_HEADER_SIZE 2U /*!< ZDO status + Transaction Sequence Number */
#define ZDP_REQ_HEADER_SIZE  1U /*!< Transaction Sequence Number */

#define DEVICE_ANNCE_REQ_SIZE 11
#define NWK_ADDR_REQ_SIZE 10
#define IEEE_ADDR_REQ_SIZE 4
#define SYSTEM_SERVER_DISCOVERY_REQ_SIZE 2
#define NODE_DESCRIPTOR_REQ_SIZE 2
#define POWER_DESCRIPTOR_REQ_SIZE 2
#define MATCH_DESCRIPTOR_REQ_SIZE 6
#define SIMPLE_DESCRIPTOR_REQ_SIZE 3
#define COMPLEX_DESCRIPTOR_REQ_SIZE 2
#define USER_DESCRIPTOR_REQ_SIZE 2
#define USER_DESCRIPTOR_CONF_REQ_SIZE 19
#define ACTIVE_EP_REQ_SIZE 2
#define PARENT_ANNCE_SIZE 1
#define BIND_UNBIND_REQ_SIZE 14
/** Minimum size of the ZDP Mgmt Nwk Update Request command:
 * \li 4 octets - ScanChannels,
 * \li 1 octet - ScanDuration,
 * \li 1 octet - ScanCount or nwkUpdateId */
#define MGMT_NWK_UPDATE_REQ_SIZE        6
#define MGMT_NWK_UPDATE_REQ_MIN_SIZE    5

#define NWK_ADDR_RESP_SIZE 10
#define IEEE_ADDR_RESP_SIZE 10
#define SYSTEM_SERVER_DISCOVERY_RESP_SIZE 2
#define NODE_DESCRIPTOR_RESP_SIZE 15
#define POWER_DESCRIPTOR_RESP_SIZE 4
#define ACTIVE_EP_RESP_SIZE 3
#define SIMPLE_DESCRIPTOR_RESP_SIZE 3
#define MATCH_DESCRIPTOR_RESP_SIZE 3
#define USER_DESCRIPTOR_RESP_SIZE 19
#define USER_DESCRIPTOR_CONF_RESP_SIZE 2
// DOM-IGNORE-END

/******************************************************************************
                                Types section
 ******************************************************************************/
 
/** Type of a ZDO command which can be allocated for ZDP command, NWK request. */
typedef struct _ZdoCommand_t
{
  /** Stack requests. */
  ZDO_ZdpReq_t zdpReq;
  union
  {
    /** NWK request which is used to enable/disable association permit. */
    NWK_PermitJoiningReq_t permitJoining;
    /** NWK request to leave a child or this device from the network. */
    NWK_LeaveReq_t leave;
    /** MAC request to change values of a MAC attribute in MIB. */
    MAC_SetReq_t macSet;
    /** HAL Application timer to track timeouts. */
    HAL_AppTimer_t timer;
    /** NWK request to run the energy detection scan. */
    NWK_EDScanReq_t edScan;
    /** ZdoResetRequest to reset the Stack */
    ZDO_ResetNetworkReq_t resetNetworkReq;
  } req;
  /** The flag indicates that the command is used or not. */
  bool busy;
  /** Is the ZDO command response to a ZDP request unicast. */
  bool isResponseToUnicast;

} ZdoCommand_t;

/******************************************************************************
                 Inline static functions prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Gets a pointer to APS_DataReq_t structure of the ZDO command.
   
  \param[in] zdoCommand - a pointer to allocated memory to perform a stack
                          request or to send ZDP command.
 ******************************************************************************/
INLINE APS_DataReq_t* zdoApsDataReq(ZdoCommand_t *const zdoCommand)
{
  return &zdoCommand->zdpReq.service.apsDataReq;
}

/**************************************************************************//**
  \brief Gets a pointer to the ZDP request frame of the ZDO command.
   
  \param[in] zdoCommand - a pointer to allocated memory to perform a stack
                          request or to send ZDP command.
 ******************************************************************************/
INLINE ZDO_ZdpReqFrame_t* zdoZdpReqFrame(ZdoCommand_t *const zdoCommand)
{
  return &zdoCommand->zdpReq.req.reqPayload;
}

/**************************************************************************//**
  \brief Gets a pointer to the ZDP response frame of the ZDO command.
   
  \param[in] zdoCommand - a pointer to allocated memory to perform a stack
                          request or to send ZDP command.
 ******************************************************************************/
INLINE ZDO_ZdpRespFrame_t* zdoZdpRespFrame(ZdoCommand_t *const zdoCommand)
{
  return &zdoCommand->zdpReq.req.respPayload;
}

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief Request to allocate memory for new ZDO command.

   This function initializes only the flag which indicates that the allocated
  entry is busy. It means that need to link apsData->asdu with zdp frame.
   
  \return Pointer to a ZDO command if there is enough space otherwise NULL.
 ******************************************************************************/
ZDO_PRIVATE ZdoCommand_t* zdoAllocCommand(void);

/**************************************************************************//**
  \brief Free memory which was allocated for the ZDO command.

  \param[in] zdoCommandField - pointer to any field of the ZDO command.
 ******************************************************************************/
ZDO_PRIVATE void zdoFreeCommand(void *zdoCommandField);

/**************************************************************************//**
  \brief Free all entries of the ZDO commands pool.
 ******************************************************************************/
ZDO_PRIVATE void zdoResetCommandsPool(void);

/**************************************************************************//**
  \brief Fill common parameters for the ZDP response.

  \param[in] apsDataInd - pointer to the APSDE-DATA indication structure of the
                          received ZDP command request.
  \param[in, out] zdoCommand - pointer to the ZDO Command structure which
                               is allocated for outgoing ZDP response or
                               a stack request.
  \param[in] APS_DataConf - callback function for apsDataReq
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoPrepareResponseParameters(const APS_DataInd_t *const apsDataInd,
  ZdoCommand_t *const zdoCommand,
  void (*APS_DataConf)(APS_DataConf_t *conf));

/*************************************************************************//**
  \brief Response is sent. Return memory into the ZDO Commands Pool.

  \param[in] apsDataConf - pointer to APSDE-DATA confirmation structure of
                           ZDP command response.
  \return None.
 ******************************************************************************/
ZDO_PRIVATE void zdoZdpResponseConf(APS_DataConf_t *apsDataConf);

#endif /* _ZDO_COMMANDS_H */
/** eof zdoCommands.h */
