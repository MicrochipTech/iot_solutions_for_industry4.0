/*******************************************************************************
  Implementation of image storage driver Source File

  Company:
    Microchip Technology Inc.

  File Name:
    isdImageStorage.c

  Summary:
    The file implements the image storage driver.

  Description:
    The file implements the image storage driver.
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

#if (APP_USE_OTAU == 1)

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysUtils.h>
#include <systemenvironment/include/sysDbg.h>
#include <systemenvironment/include/sysAssert.h>
#include <zcl/include/zclOtauManager.h>
#include <z3device/otau/isd/include/isdConsoleTunneling.h>
#include <z3device/otau/isd/include/isdImageStorage.h>

/******************************************************************************
                   Defines section
******************************************************************************/

//#define ENABLE_ISD_DEBUG_PRINT

// Size of length field in frame
#define LEN_SIZE (sizeof(((IsdCommandFrame_t*)NULL)->length))
// Start of frame market
#define SOF 0x2A //ASCII '*'

// 5000 ms timeout between request to storage system and response from it.
#define INTERMESSAGE_TIMEOUT 2000 // ms

#ifndef APP_MAX_COMMAND_PAYLOAD_SIZE
  #define APP_MAX_COMMAND_PAYLOAD_SIZE 128
#endif

// code from runner
#define ISD_COMMAND_REQUEST           0x0046
#define ISD_COMMAND_RESPONSE          0x0044
#define ISD_INIT_REQUEST              0x0100
#define ISD_INIT_RESPONSE             0x0101
#define ISD_PRINT_REQUEST             0x0200
#define ISD_COMMAND_ID_SIZE           (sizeof(uint16_t))
#define ISD_INIT_MARKER               0x55 // ASCII 'U'

/******************************************************************************
                   Types section
******************************************************************************/
// States of tx FSM
typedef enum _TxState_t
{
  TX_ERR_OR_OFF,
  TX_IDLE,
  TX_SENDING_SOF,
  TX_SENDING_DATA,
} TxState_t;

// States of rx FSM
typedef enum _RxState_t
{
  RX_ERR_OR_OFF,
  RX_WAITING_START,   // AKA IDLE
  RX_WAITING_LEN,
  RX_WAITING_DATA,
} RxState_t;

BEGIN_PACK
typedef struct PACK _IsdCommandFrame_t
{
  uint16_t   length;
  uint16_t   commandId;
  uint8_t    payload[APP_MAX_COMMAND_PAYLOAD_SIZE];
} IsdCommandFrame_t;

typedef struct PACK
{
  uint8_t     srcAddrMode;
  ShortAddr_t srcShortAddress;
  ExtAddr_t   srcExtAddress;
  ProfileId_t srcProfileId;
  Endpoint_t  srcEndpointId;
  ClusterId_t srcClusterId;

  ClusterId_t clusterId;
  uint8_t     direction;
  uint8_t     commandId;
  uint8_t     payload[1];
} IsdCommandIndication_t;

typedef struct PACK
{
  LITTLE_ENDIAN_OCTET(3,(
    uint8_t direction : 1,
    uint8_t generalCommand : 1,
    uint8_t reserved : 6
  ))
} IsdCommandOptions_t;

typedef struct PACK
{
  uint8_t addrMode;
  ShortAddr_t shortAddress;
  ExtAddr_t extAddress;
  ProfileId_t profileId;
  uint8_t endpoint;
  uint8_t dstEndpoint;
  ClusterId_t clusterId;
  uint8_t defaultResponse;
  IsdCommandOptions_t commandOptions;
  uint8_t commandId;
  uint8_t request[1];
} IsdCommandRequest_t;
END_PACK

/******************************************************************************
                   Static Function Prototypes section
******************************************************************************/

static void isdUsartReceivedHandler(uint16_t bytesAmount);
static void isdUsartErrHandler(uint16_t processedBytes);
static void isdSendCommandFrame(void);
static void isdSendCommandInitReqFrame(void);
static void isdUsartTransmittedHandler(void);
static void initTimerExpired(void);
static void isdIntermessageTimeoutExpired(void);
static void isdInitReq(void);
static bool isdInitResp(void);
static void isdSerialNotify(void);
static void isdSetState(ISD_Status_t state);

/******************************************************************************
                   Static variables section
******************************************************************************/
RxState_t rxState = RX_ERR_OR_OFF;
TxState_t txState = TX_ERR_OR_OFF;
ISD_Status_t isdState = ISD_NO_COMMUNICATION;

IsdCommandFrame_t isdBuffer;

uint8_t isdRxByte;

static HAL_AppTimer_t intermessageTimer =
{
  .interval = INTERMESSAGE_TIMEOUT,
  .mode = TIMER_ONE_SHOT_MODE,
  .callback = isdIntermessageTimeoutExpired,
};
HAL_AppTimer_t initTimer =
{
  .interval = INTERMESSAGE_TIMEOUT,
  .mode = TIMER_REPEAT_MODE,
  .callback = initTimerExpired,
};

static IsdOpenCb_t communicationStateChangedCb;
static IsdUpgradeEndCb_t upgradeEndCb;
static IsdQueryNextImageCb_t queryNextImageCb;
static IsdImageBlockCb_t imageBlockCb;
static IsdDefaultRespCb_t defaultRespCB;

static ISD_TunnelDescriptor_t isdTunnelDescriptor;

/******************************************************************************
                   Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Open image storage driver

\param[in] cb - callback about driver actions
******************************************************************************/
bool ISD_Open(IsdOpenCb_t cb)
{
  // Implementation depends on 'length' field in IsdCommandFrame_t being one byte
  // In case of change, several modifications would be required
  assert_static(2 == LEN_SIZE);
  // Also depends on 'length' field being first field of command frame
  assert_static(0 == offsetof(IsdCommandFrame_t, length));

  isdTunnelDescriptor.rxCallback     = &isdUsartReceivedHandler;
  isdTunnelDescriptor.txCallback     = &isdUsartTransmittedHandler;

  isdTunnelDescriptor.errCallback    = &isdUsartErrHandler;

  communicationStateChangedCb = cb;


  if(true == ISD_OpenUsart(&isdTunnelDescriptor))
  {
    rxState = RX_WAITING_START;
    txState = TX_IDLE;
    isdInitReq();
    return true;
  }
  else
  {
    rxState = RX_ERR_OR_OFF;
    txState = TX_ERR_OR_OFF;
    isdSetState(ISD_HARDWARE_FAULT);
    return false;
  }
}

/**************************************************************************//**
\brief Request to storage system about communication.
******************************************************************************/
static void isdInitReq(void)
{
  isdBuffer.commandId = ISD_INIT_REQUEST;
  isdBuffer.length = ISD_COMMAND_ID_SIZE + sizeof(uint8_t);
  isdBuffer.payload[0] = ISD_INIT_MARKER;
  isdSendCommandFrame();
}

#ifdef ENABLE_ISD_DEBUG_PRINT
/**************************************************************************//**
\brief Request to print the pkt received.
******************************************************************************/
void __attribute__((optimize(0))) isdConsolePrint(char *buf, ...)
{
  //fill the payload to ISD tunnel descriptor payload and send  
  IsdCommandIndication_t *serialData = (IsdCommandIndication_t *)isdBuffer.payload;
  
  isdBuffer.commandId = ISD_PRINT_REQUEST;
  isdBuffer.length = ISD_COMMAND_ID_SIZE + strlen(buf);
  memcpy(isdBuffer.payload, buf, isdBuffer.length);

  isdSendCommandFrame();
}
#else
void  isdConsolePrint(char *buf, ...) {(void)(0);}

#endif
/**************************************************************************//**
\brief Complete transaction with PC.
******************************************************************************/
static void completeTransaction(void)
{
  HAL_StopAppTimer(&intermessageTimer);
  rxState = RX_WAITING_START;
  txState = TX_IDLE;
  if(ISD_HARDWARE_FAULT != isdState)
    isdState = ISD_IDLE;
}

/**************************************************************************//**
\brief Response from storage system about communication.

\return false if parse had been failing otherwise true
******************************************************************************/
static bool isdInitResp(void)
{
  completeTransaction();

  if (ISD_INIT_MARKER != isdBuffer.payload[0])
  {
    isdSetState(ISD_NO_COMMUNICATION);
  }
  else
  {
    isdSetState(ISD_IDLE);
  }
  HAL_StartAppTimer(&initTimer);
  return true;
}

/**************************************************************************//**
\brief Close image storage driver
******************************************************************************/
void ISD_Close(void)
{
  rxState = RX_ERR_OR_OFF;
  txState = TX_ERR_OR_OFF;
  //CLOSE_USART(&isdTunnelDescriptor);
}

/**************************************************************************//**
\brief Callback about timout expiration between request and response
******************************************************************************/
static void isdIntermessageTimeoutExpired(void)
{
  isdSetState(ISD_HARDWARE_FAULT);
  completeTransaction();
  ISD_ClearUSART();
  isdInitReq();
}

/**************************************************************************//**
\brief Callback about timout expiration between Init request and response
******************************************************************************/
static void initTimerExpired(void)
{
  isdSetState(ISD_IDLE);
  completeTransaction();
  ISD_ClearUSART();
  isdInitReq();
}

static void isdUsartErrHandler(uint16_t processedBytes)
{
    while(true)
        appSnprintf("ISD error %d\r\n",processedBytes);
}

/**************************************************************************//**
\brief Callback on reception of serial byte(s)

\param[in] bytesAmount number of received bytes
******************************************************************************/
static void isdUsartReceivedHandler(uint16_t bytesReceived)
{
    switch (rxState)
    {
      case RX_WAITING_START:
        {   
          if (SOF == isdRxByte)
          {
            rxState = RX_WAITING_LEN;
            ISD_ReadUSART((void*) &isdBuffer.length, sizeof(uint16_t)); // Read the next two bytes for length
          }
          else
          {
            void consoleRx(uint8_t data);
            consoleRx(isdRxByte);
            ISD_ReadUSART(&isdRxByte,sizeof(isdRxByte));  // Loop for console command
          }
        }
        break;

      case RX_WAITING_LEN:
        {
            // Limit length to avoid possible buffer overflow
            isdBuffer.length = MIN(isdBuffer.length, sizeof(IsdCommandFrame_t) - LEN_SIZE);

            if (isdBuffer.length > 0)
            {
                rxState = RX_WAITING_DATA;
                ISD_ReadUSART((void*) &isdBuffer.commandId, isdBuffer.length);
            }
            else // Do not allow zero len
            {
                rxState = RX_WAITING_START; 
                ISD_ReadUSART(&isdRxByte,sizeof(isdRxByte));// Wait for next byte
            }
        }
        break;

      case RX_WAITING_DATA:
       
          if (bytesReceived >= isdBuffer.length)
          {
            // Full packet is received 
            otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT,isdSerialNotify);
            
          }
        
          break;
      case RX_ERR_OR_OFF:
      default:
        completeTransaction();
        return;
    }
  
}

/**************************************************************************//**
\brief Sends new command frame

\return result code
******************************************************************************/
static void __attribute__((optimize(0))) isdSendCommandFrame(void)
{
  static uint8_t sof = SOF;

  txState = TX_SENDING_SOF;
  rxState = RX_WAITING_START;

  ISD_ReadUSART(&isdRxByte,sizeof(isdRxByte)); // Wait for next byte
  ISD_WriteUSART(&sof, sizeof(sof));
  
  HAL_StartAppTimer(&intermessageTimer);
}

/**************************************************************************//**
\brief Callback on completion of single serial transmit
******************************************************************************/
static void isdUsartTransmittedHandler(void)
{
  switch (txState)
  {
    case TX_SENDING_SOF:
      {
        uint8_t *writePtr = (uint8_t *)&isdBuffer;

        writePtr += offsetof(IsdCommandFrame_t, length);
        
        ISD_WriteUSART(writePtr, isdBuffer.length + LEN_SIZE);
        txState = TX_SENDING_DATA;
      }
      break;

    case TX_SENDING_DATA:
        txState = TX_IDLE;
      break;

    case TX_IDLE:
    case TX_ERR_OR_OFF:
    default:
        completeTransaction();
      break;
  }
}

/**************************************************************************//**
\brief Send query next image request to storage system

\param[in] addressing - pointer to structure that include client network information; \n
\param[in] data - data payload; \n
\param[in] cd - callback about response receiving from storage system.
******************************************************************************/
void ISD_QueryNextImageReq(ZCL_Addressing_t *addressing, ZCL_OtauQueryNextImageReq_t *data, IsdQueryNextImageCb_t cb)
{
  IsdCommandIndication_t *serialData = (IsdCommandIndication_t *)isdBuffer.payload;
  ExtAddr_t tempExtAddr;
  HAL_StopAppTimer(&initTimer);
  if (ISD_IDLE != isdState)
    return;

  serialData->clusterId       = addressing->clusterId;
  serialData->commandId       = QUERY_NEXT_IMAGE_REQUEST_ID;
  serialData->srcAddrMode     = addressing->addrMode;
  if (APS_SHORT_ADDRESS == serialData->srcAddrMode)
  {
    const ExtAddr_t* extAddr ;
    serialData->srcShortAddress = addressing->addr.shortAddress;
    extAddr = ZDO_FindExtByShort(addressing->addr.shortAddress);

    COPY_EXT_ADDR_A(&tempExtAddr, extAddr);
    serialData->srcExtAddress = tempExtAddr;
  }
  else
  {
    const ShortAddr_t* shortAddr;
    COPY_EXT_ADDR_A(&tempExtAddr, addressing->addr.extAddress);
    serialData->srcExtAddress = tempExtAddr;
    shortAddr = ZDO_FindShortByExt(&tempExtAddr);
    serialData->srcShortAddress = *shortAddr;
  }

  serialData->srcProfileId    = addressing->profileId;
  serialData->srcEndpointId   = addressing->endpointId;
  serialData->srcClusterId    = addressing->clusterId;
  serialData->direction       = ZCL_GetIncomingCommandDirectionBySrcClusterSide(addressing->clusterSide);

  memcpy(serialData->payload, data, sizeof(ZCL_OtauQueryNextImageReq_t));

  isdBuffer.commandId = ISD_COMMAND_REQUEST;
  isdBuffer.length = ISD_COMMAND_ID_SIZE  + sizeof(IsdCommandIndication_t) +
      sizeof(ZCL_OtauQueryNextImageReq_t) - sizeof(uint8_t);

  SYS_E_ASSERT_FATAL(cb, ISD_NULLCALLBACK1);
  queryNextImageCb = cb;

  isdSetState(ISD_BUSY);
  isdSendCommandFrame();
}

/**************************************************************************//**
\brief Send image block request to storage system

\param[in] addressing - pointer to structure that include client network information; \n
\param[in] data - data payload; \n
\param[in] cd - callback about response receiving from storage system.
******************************************************************************/
void ISD_ImageBlockReq(ZCL_Addressing_t *addressing, ZCL_OtauImageBlockReq_t *data, IsdImageBlockCb_t cb)
{
  IsdCommandIndication_t *serialData = (IsdCommandIndication_t *)isdBuffer.payload;
  HAL_StopAppTimer(&initTimer);
  uint8_t size;
  ExtAddr_t tempExtAddr;

  if (ISD_IDLE != isdState)
    return;

  serialData->clusterId       = addressing->clusterId;
  serialData->commandId       = IMAGE_BLOCK_REQUEST_ID;
  serialData->srcAddrMode     = addressing->addrMode;
  if (APS_SHORT_ADDRESS == serialData->srcAddrMode)
  {
    const ExtAddr_t* extAddr;
    serialData->srcShortAddress = addressing->addr.shortAddress;
    extAddr = ZDO_FindExtByShort(addressing->addr.shortAddress);
    COPY_EXT_ADDR_A(&tempExtAddr, extAddr);
    serialData->srcExtAddress = tempExtAddr;
  }
  else
  {
    const ShortAddr_t* shortAddr;
    COPY_EXT_ADDR_A(&tempExtAddr, addressing->addr.extAddress);
    serialData->srcExtAddress = tempExtAddr;
    shortAddr = ZDO_FindShortByExt(&tempExtAddr);
    serialData->srcShortAddress = *shortAddr;
  }
  serialData->srcProfileId    = addressing->profileId;
  serialData->srcEndpointId   = addressing->endpointId;
  serialData->srcClusterId    = addressing->clusterId;
  serialData->direction       = ZCL_GetIncomingCommandDirectionBySrcClusterSide(addressing->clusterSide);

  size = sizeof(ZCL_OtauImageBlockReq_t);
  if (!data->controlField.blockRequestDelayPresent)
    size -= sizeof(data->minimumBlockPeriod);
  memcpy(serialData->payload, data, size);

  isdBuffer.commandId = ISD_COMMAND_REQUEST;
  isdBuffer.length = ISD_COMMAND_ID_SIZE  + sizeof(IsdCommandIndication_t) +
      sizeof(ZCL_OtauImageBlockReq_t) - sizeof(uint8_t);

  SYS_E_ASSERT_FATAL(cb, ISD_NULLCALLBACK2);
  imageBlockCb = cb;

  isdSetState(ISD_BUSY);
  isdSendCommandFrame();
}

/**************************************************************************//**
\brief Send upgrade end request to storage system

\param[in] addressing - pointer to structure that include client network information; \n
\param[in] data - data payload; \n
\param[in] cd - callback about response receiving from storage system.
******************************************************************************/
void ISD_UpgradeEndReq(ZCL_Addressing_t *addressing, ZCL_OtauUpgradeEndReq_t *data, IsdUpgradeEndCb_t cb)
{
  IsdCommandIndication_t *serialData = (IsdCommandIndication_t *)isdBuffer.payload;
  ExtAddr_t tempExtAddr;
  if (ISD_IDLE != isdState)
    return;

  serialData->clusterId       = addressing->clusterId;
  serialData->commandId       = UPGRADE_END_REQUEST_ID;
  serialData->srcAddrMode     = addressing->addrMode;
  if (APS_SHORT_ADDRESS == serialData->srcAddrMode)
  {
    const ExtAddr_t* extAddr ;
    serialData->srcShortAddress = addressing->addr.shortAddress;
    extAddr = ZDO_FindExtByShort(addressing->addr.shortAddress);
    COPY_EXT_ADDR_A(&tempExtAddr, extAddr);
    serialData->srcExtAddress = tempExtAddr;
  }
  else
  {
    const ShortAddr_t* shortAddr;
    COPY_EXT_ADDR_A(&tempExtAddr, addressing->addr.extAddress);
    serialData->srcExtAddress = tempExtAddr;
    shortAddr = ZDO_FindShortByExt(&tempExtAddr);
    serialData->srcShortAddress = *shortAddr;
  }
  serialData->srcProfileId    = addressing->profileId;
  serialData->srcEndpointId   = addressing->endpointId;
  serialData->srcClusterId    = addressing->clusterId;
  serialData->direction       = ZCL_GetIncomingCommandDirectionBySrcClusterSide(addressing->clusterSide);

  memcpy(serialData->payload, data, sizeof(ZCL_OtauUpgradeEndReq_t));

  isdBuffer.commandId = ISD_COMMAND_REQUEST;
  isdBuffer.length = ISD_COMMAND_ID_SIZE  + sizeof(IsdCommandIndication_t) +
      sizeof(ZCL_OtauUpgradeEndReq_t) - sizeof(uint8_t);

  SYS_E_ASSERT_FATAL(cb, ISD_NULLCALLBACK3);
  upgradeEndCb = cb;

  isdSetState(ISD_BUSY);
  isdSendCommandFrame();
}

void ISD_ZCLDefaultResp(ZCL_Addressing_t *addressing, ZCL_DefaultResp_t *data, IsdDefaultRespCb_t cb)
{
    IsdCommandIndication_t *serialData = (IsdCommandIndication_t *)isdBuffer.payload;
    ExtAddr_t tempExtAddr;
    if (ISD_IDLE != isdState)
      return;
    
    serialData->clusterId       = addressing->clusterId;
    serialData->commandId       =  DEFAULT_RESPONSE_ID;
    serialData->srcAddrMode     = addressing->addrMode;
    if (APS_SHORT_ADDRESS == serialData->srcAddrMode)
    {
      const ExtAddr_t* extAddr ;
      serialData->srcShortAddress = addressing->addr.shortAddress;
      extAddr = ZDO_FindExtByShort(addressing->addr.shortAddress);
      COPY_EXT_ADDR_A(&tempExtAddr, extAddr);
      serialData->srcExtAddress = tempExtAddr;
    }
    else
    {
      const ShortAddr_t* shortAddr;
      COPY_EXT_ADDR_A(&tempExtAddr, addressing->addr.extAddress);
      serialData->srcExtAddress = tempExtAddr;
      shortAddr = ZDO_FindShortByExt(&tempExtAddr);
      serialData->srcShortAddress = *shortAddr;
    }
    serialData->srcProfileId    = addressing->profileId;
    serialData->srcEndpointId   = addressing->endpointId;
    serialData->srcClusterId    = addressing->clusterId;
    serialData->direction       = ZCL_GetIncomingCommandDirectionBySrcClusterSide(addressing->clusterSide);
    
    memcpy(serialData->payload, data, sizeof(ZCL_DefaultResp_t));
    
    isdBuffer.commandId = ISD_COMMAND_REQUEST;
    isdBuffer.length = ISD_COMMAND_ID_SIZE  + sizeof(IsdCommandIndication_t) +
        sizeof(ZCL_DefaultResp_t) - sizeof(uint8_t);
    
    SYS_E_ASSERT_FATAL(cb, ISD_NULLCALLBACK3);
    defaultRespCB = cb;
    
    isdSetState(ISD_BUSY);
    isdSendCommandFrame();

}

/**************************************************************************//**
\brief Receive any messages from storage system

\return false if parse had been failing otherwise true
******************************************************************************/
static void isdSerialNotify(void)
{
  IsdCommandRequest_t *req = (IsdCommandRequest_t *)isdBuffer.payload;

  if (ISD_INIT_RESPONSE == isdBuffer.commandId)
  {
      isdInitResp();
      completeTransaction();
      return;
  }

  else if ((ISD_COMMAND_RESPONSE != isdBuffer.commandId) || (OTAU_CLUSTER_ID != req->clusterId))
  {
        completeTransaction();
        return;
  }
  

  switch (req->commandId)
  {
    case QUERY_NEXT_IMAGE_RESPONSE_ID:
      {
        ZCL_OtauQueryNextImageResp_t *resp = (ZCL_OtauQueryNextImageResp_t *)req->request;

        if (queryNextImageCb)
        {
          queryNextImageCb(resp);
          queryNextImageCb = NULL;
        }
      }
      break;
    case IMAGE_BLOCK_RESPONSE_ID:
      {
        if (imageBlockCb)
        {
          
          ZCL_OtauImageBlockResp_t  *resp = (ZCL_OtauImageBlockResp_t *)req->request;

          imageBlockCb(resp);
          imageBlockCb = NULL;
        }
      }
      break;
      case DEFAULT_RESPONSE_IND_ID:
        {
          if (defaultRespCB)
          {
            ZCL_DefaultResp_t  *resp = (ZCL_DefaultResp_t *)req->request;
      
            defaultRespCB(resp);
            defaultRespCB = NULL;
          }
        }
        break;

    case UPGRADE_END_RESPONSE_ID:
      {
        ZCL_OtauUpgradeEndResp_t *resp = (ZCL_OtauUpgradeEndResp_t *)req->request;
        
        if (upgradeEndCb)
        {
          upgradeEndCb(resp);
          upgradeEndCb = NULL;
        }
        else
        {
          ZCL_Addressing_t addr =
          {
            .addrMode             = req->addrMode,
            .profileId            = req->profileId,
            .endpointId           = req->dstEndpoint,
            .clusterId            = req->clusterId,
            .clusterSide          = ZCL_CLIENT_CLUSTER_TYPE,
            .manufacturerSpecCode = 0,
          };

          if (APS_EXT_ADDRESS == addr.addrMode)
          {
            ExtAddr_t tempExtAddr;
            tempExtAddr = req->extAddress;
            COPY_EXT_ADDR_A(addr.addr.extAddress,&tempExtAddr);
          }
          else
            addr.addr.shortAddress = req->shortAddress;

          ZCL_UnsolicitedUpgradeEndResp(&addr, resp);
        }
      }
      break;
    default:
      break;
  }
  completeTransaction();
  return;
}

/**************************************************************************//**
\brief Set actual driver state and report to high layer about that if required.

\param[in] state - actual driver state
******************************************************************************/
static void isdSetState(ISD_Status_t state)
{
  isdState = state;

  /* Notify higher layer about communication state changing */
  switch (isdState)
  {
    case ISD_NO_COMMUNICATION:
    case ISD_HARDWARE_FAULT:
      SYS_E_ASSERT_FATAL(communicationStateChangedCb, ISD_NULLCALLBACK0);
      communicationStateChangedCb(isdState);
      break;

    default:
      break;
  }
}

/**************************************************************************//**
\brief Get the state of ISD

\param[in] state - actual ISD state
******************************************************************************/
ISD_Status_t isdGetState(void)
{
    return isdState;
}

#endif // (APP_USE_OTAU == 1)

// eof isdImageStorage.c