/*******************************************************************************
  APS Memory Manager Header File

  Company
    Microchip Technology Inc.

  File Name
    apsMemoryManager.h

  Summary
    The header file describes APS memory manager primitive.

  Description
    This header file describes the APS memory manager primitives.
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

#ifndef APSMEMORYMANAGER_H_
#define APSMEMORYMANAGER_H_

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysQueue.h>
#include <aps/include/aps.h>
#include <nwk/include/nwk.h>
#include <hal/include/appTimer.h>
#include <aps/include/apsmeBind.h>
#include <aps/include/private/apsFrames.h>
#include <security/serviceprovider/include/sspSfp.h>
#include <security/serviceprovider/include/sspAuthentic.h>

/******************************************************************************
                   Types section
******************************************************************************/
typedef enum
{
  APS_DM_DATA_BUFFER_TYPE,
  APS_DM_ACK_DATA_BUFFER_TYPE,
  APS_SM_FREE_BUFFER_TYPE,
  APS_SM_AUR_SSP_AUTH_BUFFER_TYPE,
  APS_SM_AUR_CHALLENGE_COMMAND_BUFFER_TYPE,
  APS_SM_AUR_MAC_DATA_COMMAND_TYPE,
  APS_SM_AUI_SSP_AUTH_BUFFER_TYPE,
  APS_SM_AUI_CHALLENGE_COMMAND_BUFFER_TYPE,
  APS_SM_AUI_MAC_COMMAND_BUFFER_TYPE,
  APS_SM_SSPD_BUFFER_TYPE,
  APS_SM_UDR_COMMAND_BUFFER_TYPE,             //UpdateDevice command
  APS_SM_RDR_COMMAND_BUFFER_TYPE,             //RemoveDevice command
  APS_SM_RKR_COMMAND_BUFFER_TYPE,             //RequestKey command
  APS_SM_SKR_COMMAND_BUFFER_TYPE,             //RequestKey command
  APS_SM_TKR_COMMAND_BUFFER_TYPE,             //TransportKey command
  APS_SM_TKI_COMMAND_BUFFER_TYPE,
  APS_SM_COMMAND_IND_BUFFER_TYPE,
  APS_TUNNEL_COMMAND_BUFFER_TYPE
} ApsBufferType_t;

typedef enum {
  APS_DEFAULT_STATE,
  APS_NLDE_DATA_CONF_WAIT_STATE,
  APS_ACK_WAIT_STATE,
  APS_ACK_RECEIVED_STATE,
  APS_RETRANSMISSION_STATE,
  APS_TIMEOUT_STATE,
} ApsDataDescriptorState_t ;

typedef enum
{
  APS_NLDE_DATA_REQ_BUFFER_TYPE,          //Request for data transmission without ack waiting
  APS_NLDE_DATA_REQ_WITH_ACK_BUFFER_TYPE, //Request for data transmission with ack waiting
  APS_NLDE_DATA_REQ_ACK_BUFFER_TYPE,      //Request for APS ACK transmission
  APS_NLDE_DATA_REQ_BLOCK_BUFFER_TYPE,    //Request for part of fragmented data transmission
} ApsNldeDataReqType_t;

typedef struct
{
#ifdef _BINDING_
    ApsBindingEntry_t *bindEntry;
#endif
#ifdef _SECURITY_
#ifdef _LINK_SECURITY_
  QueueElement_t queueElement;
  APS_KeyHandle_t keyHandle;
#endif // _LINK_SECURITY_
#endif //_SECURITY_
  NWK_DataReq_t nwkDataReq; //NLDE-DATA.request primitive
  uint8_t busy:1;
  ApsNldeDataReqType_t entryType:7;
  ApsDataDescriptorState_t state:4;
  //if request with ack requested data frame then it is a retries counter
  uint8_t retriesCounter:4;
#ifdef _SECURITY_
#ifdef _LINK_SECURITY_
  uint8_t headerLength;
  APS_Status_t securityStatus;
#endif // _LINK_SECURITY_
#endif //_SECURITY_
} ApsDataDescriptor_t;

typedef struct
{
  APS_DataReq_t *link; // request pointer
  uint32_t timeout;
  ApsDataDescriptor_t dataDescriptor;
  ApsBufferType_t type;
} ApsDataBuffer_t ;

/*
  APS Acknowledge buffer declaration
*/
typedef struct
{
  /* Current buffer status */
  bool busy;
  /* Determines type of encryption to be used for ack */
  APS_Status_t securityStatus;
  /* Link to relative NWK_DataInd entity */
  NWK_DataInd_t *dataIndLink;

  BEGIN_PACK
  TOP_GUARD
  struct PACK
  {
    uint8_t lowLevelHeader[NWK_NSDU_OFFSET];
#ifdef _LINK_SECURITY_
    uint8_t apsSecHeader[APS_AUXILIARY_HEADER_LENGTH];
#endif /* _LINK_SECURITY_ */

    union  PACK
    {
      ApduAcknowledgementFrame_t dataAck; //Acknowledgement frame for data
      ApduCommandAcknowledgementFrame_t commandAck; //Acknowledgement frame for command
    } frame;
#ifdef _LINK_SECURITY_
    uint8_t apsSecFooter[APS_MAX_DATA_FRAME_FOOTER_LENGTH];
#endif /* _LINK_SECURITY_ */

#if (NWK_AFFIX_LENGTH - NWK_NSDU_OFFSET)
    uint8_t lowLevelFooter[NWK_AFFIX_LENGTH - NWK_NSDU_OFFSET];
#endif
  };
  BOTTOM_GUARD
  END_PACK
} ApsAckBuffer_t;

typedef struct
{
  uint8_t buffersAmount;
  ApsAckBuffer_t *buffers;
} ApsAckBuffersPool_t;

typedef struct
{
  uint8_t buffersAmount;
  uint8_t maxAckCounter;
  uint8_t maxReqCounter;
  uint8_t ackCounter;
  uint8_t reqCounter;
  ApsDataBuffer_t *buffers;
} ApsDataReqBuffersPool_t;

#ifdef _APS_FRAGMENTATION_
typedef struct
{
  uint8_t *buffers;
  uint8_t *bufferLengths;
  ApsDataBuffer_t apsBuffer;
  ApsAckBuffer_t apsAckBuffer;
  uint32_t timeout;
  uint16_t srcAddress;
  uint16_t clusterId;
  uint16_t profileId;
  uint8_t state;
  uint8_t maxBlocksAmount;
  uint8_t blockSize;
  uint8_t blocksAmount;
  uint8_t currentWindowStartBlockNumber;
  uint8_t ackBitfield;
  uint8_t dstEndpoint;
  uint8_t srcEndpoint;
  uint8_t apsCounter;
  APS_Status_t securityStatus;
  uint8_t ackRetriesAmount;
} ApsFragmRxDescr_t;

typedef struct
{
  HAL_AppTimer_t sendTimer; // timer that send frame per apsInterframeDelay
  ApsDataBuffer_t *block; // memory for block
  uint8_t *buffer;
  uint8_t blockSize;
  uint8_t blockNumber;
  uint8_t ackBlockNumber; // block number that expect ack, also it is first block number in the window
  uint8_t blocksToTransmit; // block in window requires to  transmit. 1 required transmission
  uint8_t blocksCount;
  uint8_t apsCounter;
  uint8_t retryCounter;
} ApsFragmTxDescr_t;
#endif // _APS_FRAGMENTATION_

/*
 * APS sublayer memory structure.
 */
typedef struct
{
  ApsDataReqBuffersPool_t dataReqBuffersPool; // Buffers to execute APS Data requests
  ApsAckBuffersPool_t ackBuffersPool; // Buffers to generate APS acknowledgements
#ifdef _APS_FRAGMENTATION_
  ApsFragmRxDescr_t apsFragmRxDescr;
  ApsFragmTxDescr_t apsFragmTxDescr;
#endif // _APS_FRAGMENTATION_
} ApsMem_t;


/******************************************************************************
                   Extern variables section
******************************************************************************/
extern ApsMem_t apsMem;

/******************************************************************************
                   Prototypes section
******************************************************************************/
/*****************************************************************************
  \brief Make a reset of APS Memory Manager

  \param fullReset - reset all internal variables of APS-layer or not.
  \retur none
*****************************************************************************/
APS_PRIVATE void apsResetMemoryManager(void);

/***************************************************************************//**
  \brief Allocates memory buffer for NLDE-DATA.request primitive specified by
  parameter primitiveType.

  \param primitiveType - type of buffer which will be allocated
    APS_NLDE_DATA_REQ_BUFFER_TYPE - NLDE-DATA.request without frame
    APS_NLDE_DATA_REQ_WITH_ACK_BUFFER_TYPE - NLDE-DATA.request with ack
      required flag in APDU
    APS_NLDE_DATA_REQ_ACK_BUFFER_TYPE - NLDE-DATA.request with ack frame
  \return nonNULL buffer pointer if memory was allocated successfully
          NULL - no free buffers available.
*******************************************************************************/
APS_PRIVATE ApsDataBuffer_t *apsGetBuffer(uint8_t primitiveType);

/***************************************************************************//**
  \brief Deallocate memory buffer

  \param buffer - pointer to buffer to be freed.
  \return None
*******************************************************************************/
APS_PRIVATE void apsFreeBuffer(void *buffer);

/***************************************************************************//**
  \brief Check memory availability for NLDE-DATA.request primitive to generate
  APS acknowledge.

  \param  None
  \return true - memory is available
          false - in other case
*******************************************************************************/
APS_PRIVATE bool apsIsBufferAvailableForAck(void);

/******************************************************************************
                   Inline functions section
******************************************************************************/
/*****************************************************************************
  \brief Gives pointer to APS layer memory pool.

  \param none
  \retur pointer to APS memory pool.
*****************************************************************************/
INLINE ApsDataReqBuffersPool_t *apsGetDataReqBuffersMem(void)
{
  return &apsMem.dataReqBuffersPool;
}

/*****************************************************************************
  \brief Gives pointer to APS layer acknowledgements memory pool.

  \param none
  \retur pointer to APS acknowledgements memory pool.
*****************************************************************************/
INLINE ApsAckBuffersPool_t *apsGetAckBuffersMem(void)
{
  return &apsMem.ackBuffersPool;
}

#ifdef _APS_FRAGMENTATION_
/*****************************************************************************
  \brief Gives pointer to APS layer fragmentation feature memory (Rx).

  \param none
  \retur pointer to fragmentation feature memory (Rx).
*****************************************************************************/
INLINE ApsFragmRxDescr_t *apsGetFragmRxDescrMem(void)
{
  return &apsMem.apsFragmRxDescr;
}

/*****************************************************************************
  \brief Gives pointer to APS layer fragmentation feature memory (Tx).

  \param none
  \retur pointer to fragmentation feature memory (Tx).
*****************************************************************************/
INLINE ApsFragmTxDescr_t *apsGetFragmTxDescrMem(void)
{
  return &apsMem.apsFragmTxDescr;
}

/*****************************************************************************
  \brief Resets structure which controls fragmented data receiption procedure.

  \param none
  \retur none
*****************************************************************************/
INLINE void apsResetFragmRxDescr(void)
{
  ApsFragmRxDescr_t *apsFragmRxDescr = apsGetFragmRxDescrMem();

  apsFragmRxDescr->ackBitfield = 0;
  apsFragmRxDescr->apsCounter = 0;
  apsFragmRxDescr->blocksAmount = 0;
  apsFragmRxDescr->clusterId = 0;
  apsFragmRxDescr->currentWindowStartBlockNumber = 0;
  apsFragmRxDescr->dstEndpoint = 0;
  apsFragmRxDescr->profileId = 0;
  apsFragmRxDescr->srcAddress = 0;
  apsFragmRxDescr->srcEndpoint = 0;
  apsFragmRxDescr->state = 0;
  apsFragmRxDescr->timeout = 0;

  memset(&apsFragmRxDescr->apsBuffer, 0, sizeof(apsFragmRxDescr->apsBuffer));
  memset(&apsFragmRxDescr->apsAckBuffer, 0, sizeof(apsFragmRxDescr->apsAckBuffer));
  memset(apsFragmRxDescr->buffers, 0,
    apsFragmRxDescr->maxBlocksAmount * apsFragmRxDescr->blockSize + apsFragmRxDescr->maxBlocksAmount);

  apsFragmRxDescr->apsBuffer.dataDescriptor.nwkDataReq.nsdu = (uint8_t *)&apsFragmRxDescr->apsAckBuffer.frame;
}

#endif // ifdef _APS_FRAGMENTATION_
#endif /*APSMEMORYMANAGER_H_*/

//eof apsMemoryManager.h
