/*******************************************************************************
  Zigbee Cluster Library OTAU Client Discovery Cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClientDiscovery.c

  Summary:
    The file implements the OTAU client discovery part.

  Description:
    The file implements the OTAU client discovery part.
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

#if (APP_USE_OTAU == 1)
#include <zigbee/z3device_configs/otauConfig.h>
#endif

#if APP_USE_OTAU == 1 && defined(_ZCL_SUPPORT_)  && defined(OTAU_CLIENT)

/******************************************************************************
                   Includes section
******************************************************************************/
#include <zcl/include/zclOtauManager.h>
#include <zcl/include/zclOtauClient.h>
#include <pds/include/wlPdsMemIds.h>

#if (MICROCHIP_APPLICATION_SUPPORT == 1)
#include <bdb/include/bdbZllBindings.h>
#include <zllplatform/ZLL/N_Zdp/include/N_Zdp.h>
#include <zllplatform/ZLL/N_Zdp/include/N_Zdp_Bindings.h>
#include <zllplatform/ZLL/N_Cmi/include/N_Cmi.h>
#include <zllplatform/ZLL/N_EndDeviceRobustness/include/N_EndDeviceRobustness.h>
#endif

/******************************************************************************
                   External variables section
******************************************************************************/
extern ZclOtauClientStateMachine_t otauStateMachine;
extern ZCL_OtauClusterClientAttributes_t otauClientAttributes;
extern ExtAddr_t tempServerExtAddr;
extern ExtAddr_t otauUnauthorizedServers[OTAU_MAX_UNAUTHORIZED_SERVERS];
extern QueueDescriptor_t zclOtauServerDiscoveryQueue;

/******************************************************************************
                   Static variables section
******************************************************************************/
static ZclOtauDiscoveryResult_t otauActiveServer = {
  .busy               = false,
  .serverShortAddress = BROADCAST_ADDR_RX_ON_WHEN_IDLE,
  .serverExtAddress   = INVALID_SERVER_EXT_ADDRESS,
  .serverEndpoint     = 0xFF,
  .service.next       = NULL
};

/******************************************************************************
                   Global variables section
******************************************************************************/
ZclOtauDiscoveryResult_t *actvServer = &otauActiveServer;
ZclOtauDiscoveryResult_t  __attribute__((persistent))  backupOtauActiveServer;
ZclOtauClientStateMachine_t __attribute__((persistent))  backupOtauStateMachine;

/******************************************************************************
                   Implementation section
******************************************************************************/

/***************************************************************************//**
\brief Enqueues an element to discovery queue
******************************************************************************/
void otauEnqueueDiscoveryQueue(ShortAddr_t shortAddr, uint8_t endpoint)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  uint8_t tmpAmount = clientMem->discoveredServerAmount;
  ZclOtauDiscoveryResult_t *tmpMem = clientMem->discoveredServerMem;

  while (tmpAmount--)
  {
    if (tmpMem->busy)
    {
      tmpMem++;
      continue;
    }

    tmpMem->busy = true;
    tmpMem->serverShortAddress = shortAddr;
    tmpMem->serverEndpoint = endpoint;
    putQueueElem(&zclOtauServerDiscoveryQueue, tmpMem);
    break;
  }
}

/***************************************************************************//**
\brief Brodcast Match Desc Response CMD completed status handling
******************************************************************************/
static void otauBroadcastMatchDescRespCmdCompletedStatusHandling(void)
{
  actvServer = (ZclOtauDiscoveryResult_t *)deleteHeadQueueElem(&zclOtauServerDiscoveryQueue);

  if (NULL != actvServer)
  {
    OTAU_SET_STATE(otauStateMachine, OTAU_GET_IEEE_ADDR_STATE);
    otauIeeeAddrReq(actvServer);
  }
  else
  {
    otauStartDiscoveryTimer();
  }
}

/***************************************************************************//**
\brief Response on broadcast discovery of upgrade server

\param zdpResp - pointer to response.
******************************************************************************/
void otauBroadcastMatchDescResp(ZDO_ZdpResp_t *zdpResp)
{
  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_MATCH_DESC_BROADCAST_STATE))
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_BROADCAST_MATCH_DESC_RSP);
    return;
  }

  if ((ZDO_SUCCESS_STATUS == zdpResp->respPayload.status) && (zdpResp->respPayload.matchDescResp.matchLength))
  {
    otauEnqueueDiscoveryQueue(zdpResp->respPayload.matchDescResp.nwkAddrOfInterest, \
                              zdpResp->respPayload.matchDescResp.matchList[0]);
  }
  else if (ZDO_CMD_COMPLETED_STATUS == zdpResp->respPayload.status)
  {
    otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauBroadcastMatchDescRespCmdCompletedStatusHandling);
  }
  else
  {
    zclRaiseCustomMessage(OTAU_SERVER_HAS_NOT_BEEN_FOUND);
    otauStartDiscoveryTimer();
  }
}

/***************************************************************************//**
\brief Prepares the state machine to move to query state
******************************************************************************/
void otauTransitionToQuery(void)
{
  ExtAddr_t tcExtAddr = 0;

#if (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)
  if (!APS_KEYS_FOUND(APS_FindKeys(&actvServer->serverExtAddress)))
  {
    CS_ReadParameter(CS_APS_TRUST_CENTER_ADDRESS_ID, &tcExtAddr);
    OTAU_SET_STATE(otauStateMachine, OTAU_GET_LINK_KEY_STATE);
    otauRequestKeyReq(&tcExtAddr);
    return;
  }
#endif // (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)
  COPY_EXT_ADDR(otauClientAttributes.upgradeServerID.value, tempServerExtAddr);
  
  otauStartQueryTimer();
  (void)tcExtAddr;
  return;
}

/***************************************************************************//**
\brief Unicast Match Desc Retry handling
******************************************************************************/
static void otauUnicastMatchDescRetryHandling(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  if (clientMem->retryCount--)
  {
    otauMatchDescReq(true,otauUnicastMatchDescResp);
  }
  else
  {
    CS_ReadParameter(CS_ZCL_OTAU_DEFAULT_UPGRADE_SERVER_IEEE_ADDRESS_ID, &tempServerExtAddr);

    if (IS_EQ_EXT_ADDR(tempServerExtAddr, actvServer->serverExtAddress))
    {
      tempServerExtAddr = INVALID_SERVER_EXT_ADDRESS;
      actvServer = &otauActiveServer;
    }
    otauStartDiscoveryTimer();
  }
}

/***************************************************************************//**
\brief Response on unicast match descriptor discovery

\param[in] zdpResp - pointer to response.
******************************************************************************/
void otauUnicastMatchDescResp(ZDO_ZdpResp_t *zdpResp)
{
  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_MATCH_DESC_UNICAST_STATE))
  {
    {
      SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_UNICAST_MATCH_DESC_RSP);
    }
    return;
  }

  if (ZDO_SUCCESS_STATUS == zdpResp->respPayload.status)
  {
    actvServer->serverEndpoint = zdpResp->respPayload.matchDescResp.matchList[0];
  }
  else if (ZDO_CMD_COMPLETED_STATUS == zdpResp->respPayload.status)
  {
    zclClearOtauClientMemory();
    otauTransitionToQuery();
  }
  else
  {
    otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauUnicastMatchDescRetryHandling);
  }
}

/***************************************************************************//**
\brief Send match descriptor response to know server endpoint

\param[in] zdoZdpResp - pointer to response
******************************************************************************/
void otauMatchDescReq(bool unicast, void (* zdoZdpResp)(ZDO_ZdpResp_t *zdpResp))
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZDO_ZdpReq_t *tmpZdpReq = &clientMem->reqMem.zdpOtauReq;

  if ((!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_MATCH_DESC_BROADCAST_STATE)) && \
      (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_MATCH_DESC_UNICAST_STATE)))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_MATCH_DESC_REQ);
    return;
  }

  tmpZdpReq->reqCluster = MATCH_DESCRIPTOR_CLID;
  tmpZdpReq->dstAddrMode = APS_SHORT_ADDRESS;

  if (unicast)
  {
    tmpZdpReq->dstAddress.shortAddress = actvServer->serverShortAddress;
  }
  else
  {
    tmpZdpReq->dstAddress.shortAddress = 0xfffd;
  }

  tmpZdpReq->req.reqPayload.matchDescReq.nwkAddrOfInterest = tmpZdpReq->dstAddress.shortAddress;
  tmpZdpReq->req.reqPayload.matchDescReq.profileId = zclOtauMem.initParam.profileId;
  tmpZdpReq->req.reqPayload.matchDescReq.numInClusters = 1;
  tmpZdpReq->req.reqPayload.matchDescReq.inClusterList[0] = OTAU_CLUSTER_ID;
  tmpZdpReq->req.reqPayload.matchDescReq.numOutClusters = 0;
  tmpZdpReq->ZDO_ZdpResp = zdoZdpResp;

  isOtauBusy = true;
#if defined(MICROCHIP_APPLICATION_SUPPORT)
  N_Zdp_ZdpRequest(tmpZdpReq);
#else
  ZDO_ZdpReq(tmpZdpReq);
#endif
}

/***************************************************************************//**
\brief Unicast Match Desc Retry handling
******************************************************************************/
static void otauIeeeAddrReqFailureHandling(void)
{
  ZclOtauDiscoveryResult_t *srv = actvServer;
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  if (clientMem->retryCount--)
  {
    otauIeeeAddrReq(srv);
  }
  else
  {
    actvServer = (ZclOtauDiscoveryResult_t *)deleteHeadQueueElem(&zclOtauServerDiscoveryQueue);
    if (NULL != actvServer)
    {
      otauIeeeAddrReq(actvServer);
    }
    else
    {
      zclRaiseCustomMessage(OTAU_SERVER_HAS_NOT_BEEN_FOUND);
      otauStartDiscoveryTimer();
    }
  }
}

/***************************************************************************//**
\brief Send ieeeAddrReq to active server
******************************************************************************/
static void otauIeeeAddrReqToActiveServer(void)
{
  otauIeeeAddrReq(actvServer);
}

/***************************************************************************//**
\brief Server IEEE addresses response

\param zdpResp - pointer to response.
******************************************************************************/
void otauIeeeAddrResp(ZDO_ZdpResp_t *zdpResp)
{
  bool serverIsUnauthorized = false;
  ExtAddr_t tcExtAddr = 0;
  ExtAddr_t ieeeAddr = 0;
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IEEE_ADDR_STATE))
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_IEEE_ADDR_RSP);
    return;
  }

  if (ZDO_SUCCESS_STATUS != zdpResp->respPayload.status)
  {
    otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauIeeeAddrReqFailureHandling);
    return;
  }

  for (uint8_t i = 0; i < OTAU_MAX_UNAUTHORIZED_SERVERS; i++)
  {
    COPY_EXT_ADDR(ieeeAddr, zdpResp->respPayload.ieeeAddrResp.ieeeAddrRemote);
    if (IS_EQ_EXT_ADDR(otauUnauthorizedServers[i], ieeeAddr))
    {
      serverIsUnauthorized = true;
    }
  }

  if(serverIsUnauthorized)
  {
    actvServer = (ZclOtauDiscoveryResult_t *)deleteHeadQueueElem(&zclOtauServerDiscoveryQueue);

    if (NULL != actvServer)
    {
      otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauIeeeAddrReqToActiveServer);
    }
    else
    {
      otauStartDiscoveryTimer();
    }
  }
  else
  {
    COPY_EXT_ADDR(actvServer->serverExtAddress, zdpResp->respPayload.ieeeAddrResp.ieeeAddrRemote);
    COPY_EXT_ADDR(tempServerExtAddr, actvServer->serverExtAddress);
    otauTransitionToQuery();
    return;
  }
  (void)tcExtAddr;
}

/***************************************************************************//**
\brief Server IEEE addresses request
******************************************************************************/
void otauIeeeAddrReq(ZclOtauDiscoveryResult_t *srv)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZDO_ZdpReq_t *tmpZdpReq = &clientMem->reqMem.zdpOtauReq;

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_IEEE_ADDR_STATE))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_IEEE_ADDR_REQ);
    return;
  }

  tmpZdpReq->reqCluster = IEEE_ADDR_CLID;
  tmpZdpReq->dstAddrMode = APS_SHORT_ADDRESS;

  tmpZdpReq->dstAddress.shortAddress = srv->serverShortAddress;

  tmpZdpReq->req.reqPayload.ieeeAddrReq.nwkAddrOfInterest = srv->serverShortAddress;
  tmpZdpReq->req.reqPayload.ieeeAddrReq.reqType = 0;
  tmpZdpReq->ZDO_ZdpResp = otauIeeeAddrResp;

#if defined(MICROCHIP_APPLICATION_SUPPORT)
  N_Zdp_ZdpRequest(&clientMem->reqMem.zdpOtauReq);
#else
  ZDO_ZdpReq(&clientMem->reqMem.zdpOtauReq);
#endif
}

/***************************************************************************//**
\brief Send match desc req uincast
******************************************************************************/
static void otauSendMatchDescReqUnicast(void)
{
  otauMatchDescReq(true,otauUnicastMatchDescResp);
}

/***************************************************************************//**
\brief Server short address response.

\param zdpResp - pointer to response structute.
******************************************************************************/
void otauNwkAddrResp(ZDO_ZdpResp_t *zdpResp)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_NWK_ADDR_STATE))
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_NWK_ADDR_RSP);
    return;
  }

  if (ZDO_SUCCESS_STATUS == zdpResp->respPayload.status)
  {
    actvServer->serverShortAddress = zdpResp->respPayload.nwkAddrResp.nwkAddrRemote;

    OTAU_SET_STATE(otauStateMachine, OTAU_GET_MATCH_DESC_UNICAST_STATE);
    otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauSendMatchDescReqUnicast);
    return;
  }

  else if (clientMem->retryCount--)
  {
    otauStartGenericTimer(OTAU_CONTEXT_BREAK_QUICK_TIMEOUT, otauNwkAddrReq);
  }
  else
  {
    CS_ReadParameter(CS_ZCL_OTAU_DEFAULT_UPGRADE_SERVER_IEEE_ADDRESS_ID, &tempServerExtAddr);

    if (IS_EQ_EXT_ADDR(tempServerExtAddr, actvServer->serverExtAddress))
    {
      tempServerExtAddr = INVALID_SERVER_EXT_ADDRESS;
      actvServer = &otauActiveServer;
    }

    otauStartDiscoveryTimer();
  }
}

/***************************************************************************//**
\brief Send server short address request
******************************************************************************/
void otauNwkAddrReq(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  ZDO_ZdpReq_t *tmpZdpReq = &clientMem->reqMem.zdpOtauReq;

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_NWK_ADDR_STATE))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_NWK_ADDR_REQ);
    return;
  }

  tmpZdpReq->reqCluster = NWK_ADDR_CLID;
  tmpZdpReq->dstAddrMode = APS_EXT_ADDRESS;

  COPY_EXT_ADDR_A(tmpZdpReq->dstAddress.extAddress, &tempServerExtAddr);

  COPY_EXT_ADDR(tmpZdpReq->req.reqPayload.nwkAddrReq.ieeeAddrOfInterest,tempServerExtAddr);
  tmpZdpReq->req.reqPayload.nwkAddrReq.reqType = 1;
  tmpZdpReq->ZDO_ZdpResp = otauNwkAddrResp;
#if defined(MICROCHIP_APPLICATION_SUPPORT)
  N_Zdp_ZdpRequest(tmpZdpReq);
#else
  ZDO_ZdpReq(tmpZdpReq);
#endif
}

#if (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)
/***************************************************************************//**
\brief APS get link key response

\param conf - pointer to confirm.
******************************************************************************/
void otauRequestKeyResp(APS_RequestKeyConf_t *conf)
{
  ExtAddr_t tcExtAddr;
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_LINK_KEY_STATE))
  {
    SYS_E_ASSERT_WARN(false, ZCL_OTAU_INVALID_STATE_REQUEST_KEY_RSP);
    return;
  }

  if (APS_RKR_SUCCESS_STATUS == conf->status)
  {
    COPY_EXT_ADDR(tempServerExtAddr, actvServer->serverExtAddress);

    zclRaiseCustomMessage(OTAU_SERVER_HAS_BEEN_FOUND);
    otauStartQueryTimer();
    return;
  }

  if (clientMem->retryCount--)
  {

    CS_ReadParameter(CS_APS_TRUST_CENTER_ADDRESS_ID, &tcExtAddr);
    otauRequestKeyReq(&tcExtAddr);
  }
  else
  {
    CS_ReadParameter(CS_ZCL_OTAU_DEFAULT_UPGRADE_SERVER_IEEE_ADDRESS_ID, &tempServerExtAddr);

    if (IS_EQ_EXT_ADDR(tempServerExtAddr, actvServer->serverExtAddress))
    {
      tempServerExtAddr = INVALID_SERVER_EXT_ADDRESS;
      actvServer = &otauActiveServer;
    }
    otauStartDiscoveryTimer();
  }
}

/***************************************************************************//**
\brief APS link key request

\param tcAddr - pointer to trust center extended address.
******************************************************************************/
void otauRequestKeyReq(ExtAddr_t *tcExtAddr)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();
  APS_RequestKeyReq_t *tmpKeyReq = &clientMem->reqMem.apsKeyReq;

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_GET_LINK_KEY_STATE))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_REQUEST_KEY_REQ);
    return;
  }

  COPY_EXT_ADDR(tmpKeyReq->destAddress, *tcExtAddr);
  tmpKeyReq->partnerAddress = actvServer->serverExtAddress;
  tmpKeyReq->keyType = APS_APP_KEY_TYPE;

  tmpKeyReq->APS_RequestKeyConf = otauRequestKeyResp;
  APS_RequestKeyReq(tmpKeyReq);
}
#endif // (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)

/***************************************************************************//**
\brief Start timer to elapse discovery interval
******************************************************************************/
void otauStartDiscoveryTimer(void)
{
  uint32_t discoveryPeriod = 5000ul;
  CS_ReadParameter(CS_ZCL_OTAU_DEFAULT_SERVER_DISCOVERY_PERIOD_ID, (void *)&discoveryPeriod);

  isOtauBusy = false;
  OTAU_SET_STATE(otauStateMachine, OTAU_WAIT_TO_DISCOVER_STATE);
  otauStartGenericTimer(discoveryPeriod, otauStartDiscovery);
}

/***************************************************************************//**
\brief Start discovery of upgrade server
******************************************************************************/
void otauStartDiscovery(void)
{
  ZCL_OtauClientMem_t *clientMem = zclGetOtauClientMem();

  if (!OTAU_CHECK_STATE(otauStateMachine, OTAU_WAIT_TO_DISCOVER_STATE))
  {
    SYS_E_ASSERT_ERROR(false, ZCL_OTAU_INVALID_STATE_START_DISCOVERY);
    return;
  }

  resetQueue(&zclOtauServerDiscoveryQueue);
  zclClearOtauClientMemory();
  CS_ReadParameter(CS_ZCL_OTAU_MAX_RETRY_COUNT_ID, &clientMem->retryCount);

  clientMem->otauUpgradeEndStatus = ZCL_SUCCESS_STATUS;      // Reset the status
  otauSetImageUpgradeStatusAttr(OTAU_NORMAL);

  OTAU_SET_STATE(otauStateMachine, OTAU_GET_MATCH_DESC_BROADCAST_STATE);
  actvServer = &otauActiveServer;
  appOtauPrintf("OTAU: Starting Discovery\r\n");
  otauMatchDescReq(false,otauBroadcastMatchDescResp);
}

/***************************************************************************//**
\brief backup server info incase of going to deep sleep
******************************************************************************/
void ZCL_BackupOtauparams(void)
{
    memcpy4ByteAligned(&backupOtauActiveServer, (uint8_t*)actvServer, sizeof(ZclOtauDiscoveryResult_t));
    memcpy4ByteAligned(&backupOtauStateMachine, &otauStateMachine, sizeof(ZclOtauClientStateMachine_t));
}

/***************************************************************************//**
\brief restore server info incase of going to deep sleep
******************************************************************************/
void ZCL_RestoreOtauparams(void)
{
    memcpy4ByteAligned((uint8_t*)actvServer, &backupOtauActiveServer, sizeof(ZclOtauDiscoveryResult_t));    
    memcpy4ByteAligned(&otauStateMachine, &backupOtauStateMachine, sizeof(ZclOtauClientStateMachine_t));
}

#endif // (ZCL_SUPPORT == 1) && (APP_USE_OTAU == 1)

//eof zclOtauClientDiscovery.c
