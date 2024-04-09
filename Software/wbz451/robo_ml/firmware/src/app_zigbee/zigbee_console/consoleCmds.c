/*******************************************************************************
  Application Console Commands Source file

  Company:
    Microchip Technology Inc.

  File Name:
    consoleCmds.c

  Summary:
    This file contains the Serial interface console interface.

  Description:
    This file contains the Serial interface console interface.
 *******************************************************************************/

#include <z3device/clusters/include/haClusters.h>

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

#if APP_ENABLE_CONSOLE == 1
/******************************************************************************
                    Includes section
******************************************************************************/
#include <app_zigbee/zigbee_console/console.h>
#include <zcl/include/clusters.h>
#include <app_zigbee/zigbee_console/consoleCmds.h>
#include <systemenvironment/include/sysTypes.h>
#include <bdb/include/bdbInstallCode.h>
#include <zllplatform/ZLL/N_LinkTarget/include/N_LinkTarget_Bindings.h>
#include <zllplatform/ZLL/N_LinkTarget/include/N_LinkTarget.h>
#include <configserver/include/private/csSIB.h>
#include <z3device/common/include/z3Device.h>
#include <z3device/stack_interface/nwk/include/nwk_api.h>
#include <z3device/stack_interface/bdb/include/bdb_api.h>

#define N_Connection_AssociateDiscovery N_Connection_AssociateDiscovery_Impl
#include <zllplatform/ZLL/N_Connection/include/N_Connection.h>
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
#include <zgp/GPInfrastructure/highZgp/include/zgpInfraDevice.h>
#endif
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#include <zgp/GPInfrastructure/highZgp/include/zgpCluster.h>
#include <z3device/common/include/zgpAppInterface.h>
#ifdef ENABLE_ZGP_TEST_FRAMEWORK
#include <zgp/GPInfrastructure/test/include/zgpTestFrameWork.h>
#endif
#endif // APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#ifdef ZAPPSI_HOST
#include <zsiSysSerialization.h>
#endif // ZAPPSI_HOST

#ifdef _PIC32CX_
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyPic32cx.h>
#endif
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phySet.h>

#ifdef OTAU_CLIENT
#include <zcl/include/zclOtauClient.h>
#endif
/******************************************************************************
                 External variables section
******************************************************************************/
extern DescModeManagerMem_t descModeMem;
extern const ConsoleCommand_t helpCmds[];
extern const ConsoleCommand_t commissioningHelpCmds[];
extern const ConsoleCommand_t zclHelpCmds[];

/******************************************************************************
                    Prototypes section
******************************************************************************/
#if ZDO_COMMANDS_IN_CONSOLE == 1
static void processActiveEpRequestCmd(const ScanValue_t *args);
static void processBindReqCmd(const ScanValue_t *args);
static void processBindReqCmdWithSrcAddrDestEndpoint(const ScanValue_t *args);
static void processIeeeAddrRequestCmd(const ScanValue_t *args);
#ifdef _MAC_BAN_NODE_
static void processMacBanNodeCmd(const ScanValue_t *args);
static void processMacResetBanTableCmd(const ScanValue_t *args);
#endif
static void processMatchDescriptorRequestCmd(const ScanValue_t *args);
static void processNodeDescriptorRequestCmd(const ScanValue_t *args);
static void processNwkAddrRequestCmd(const ScanValue_t *args);
static void processNwkLeaveReqCmd(const ScanValue_t *args);
static void processMgmtSendBindReqCmd(const ScanValue_t *args);
static void processMgmtSendLeaveReqCmd(const ScanValue_t *args);
static void processMgmtSendLqiReqCmd(const ScanValue_t *args);
static void processMgmtSendPermitJoinCmd(const ScanValue_t *args);
static void zdoPermitJoiningResponse(ZDO_ZdpResp_t *resp);
static void processSendNwkUpdateReqCmd(const ScanValue_t *args);
static void processSimpleDescriptorRequestCmd(const ScanValue_t *args);
static void processUnBindReqCmd(const ScanValue_t *args);
static void processUnBindReqCmdWithSrcAddrDestEndpoint(const ScanValue_t *args);
#if BDB_TOUCHLINK_SUPPORT == 1 
static void processSendBeaconReqCmd(const ScanValue_t *args);
#endif
#ifdef OTAU_SERVER
static void processSetAbortUpgradeEndReq(const ScanValue_t *args);
#endif
#endif // #if ZDO_COMMANDS_IN_CONSOLE == 1
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
static void processZgpTableResetToFnCmd(const ScanValue_t *args);
static void processSetPassiveAckThresholdCmd(const ScanValue_t *args);
static void processRestorePassiveAckThresholdCmd(const ScanValue_t *args);
#endif
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#if (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
static void processSendSimpleDescriptorRequestCmd(const ScanValue_t *args);
static void processSinkTableRequestCmd(const ScanValue_t *args);
static void processSendDeviceAnnounceCmd(const ScanValue_t *args);
static void processSendGpRawPayloadCmd(const ScanValue_t *args);
static void processSendProxyCommissioningModeCmd(const ScanValue_t *args);
static void processSendPairingConfigCmd(const ScanValue_t *args);
#endif
static void processEnableDisableDirectModeCmd(const ScanValue_t *args);
static void processSendReadAttributeCmd(const ScanValue_t *args);
static void processProxyTableRequestCmd(const ScanValue_t *args);
static void processSinkCommissioningModeCmd(const ScanValue_t *args);
static void processAddGpdfToTxQueue(const ScanValue_t *args);
static void processSetGroupIdOrAliasCmd(const ScanValue_t *args);
#endif

#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
static void zdoPermitJoinResponse(ZDO_ZdpResp_t *resp);
#endif

#ifdef OTAU_CLIENT
#define OTAU_PRIVILEGED_CONSOLE_CMDS 0
void processSetImageIV (const ScanValue_t *args);
void processSetImageKey (const ScanValue_t *args);

#endif
extern SIB_t csSIB;

/******************************************************************************
                    Local variables section
******************************************************************************/
static PROGMEM_DECLARE(ConsoleCommand_t zdoHelpCmds[]) =
{  
 #if ZDO_COMMANDS_IN_CONSOLE == 1
   {"activeEpReq", "dd",processActiveEpRequestCmd, "[DstAddr] [nwkAddr]\r\n"},
   {"bindReq", "sddddd", processBindReqCmd, "[addrMode][DstAddr][extDstAddrHigh][extDstAddrLow][ep][ClusterId]\r\n"},
   {"bindReq2", "sdddddddd", processBindReqCmdWithSrcAddrDestEndpoint, "[addrMode][DstAddr][extSrcAddrHigh][extSrcAddrLow][extDstAddrHigh][extDstAddrLow/GroupID][ep_Src][ep_Dst][ClusterId]\r\n"},
   {"ieeeAddrReq", "ddd",processIeeeAddrRequestCmd, "[dstAddr] [nwkAddOfInt] [reqType]\r\n"},
#ifdef _MAC_BAN_NODE_
   {"macBanNode", "ddddd", processMacBanNodeCmd, " <extAddr> <shortAddr> <cost> <rssi>\r\n"},
   {"macResetBanTable", "", processMacResetBanTableCmd, ""},
#endif
   {"matchDescReq", "dd",processMatchDescriptorRequestCmd, "[nwkAddr] [srcEp]\r\n"},
   {"NodeDescReq", "dd",processNodeDescriptorRequestCmd, "[dstnwkAddr] [nwkAddrOfInt]\r\n"},
   {"nwkAddrReq", "dddd",processNwkAddrRequestCmd, "[dstAddr] [ieeeAddOfInt] [reqType]\r\n"},
   {"nwkLeaveReq", "dddd", processNwkLeaveReqCmd, "[extAddr][rejoin][removeChild] \r\n"},
#if BDB_TOUCHLINK_SUPPORT == 1
   {"sendBeaconReq", "", processSendBeaconReqCmd, ""},
#endif
   {"sendMgmtBindReq", "dd", processMgmtSendBindReqCmd, "[address][startIndex]\r\n"},
   {"sendMgmtLeaveReq", "ddddd", processMgmtSendLeaveReqCmd, "[dstShortAddr][devExtAddr][rejoin][removeChildren]\r\n"},
   {"sendMgmtLqiReq", "dd", processMgmtSendLqiReqCmd, "[address][startIndex]\r\n"},
   {"sendMgmtPermitJoin", "ddd", processMgmtSendPermitJoinCmd, "[dstAddr][dur][tcSig]\r\n"},
   {"sendNwkMgmtUpdateReq", "ddd", processSendNwkUpdateReqCmd, "<channel> <scanDuration> <nwkAddr>\r\n"},
   {"simpleDescReq", "dd",processSimpleDescriptorRequestCmd, "[nwkAddr] [dstEp]\r\n"},
   {"unbindReq", "sddddd", processUnBindReqCmd, "[addrMode][DstAddr][extAddr][ep][ClusterId]\r\n"},
   {"unbindReq2", "sdddddddd", processUnBindReqCmdWithSrcAddrDestEndpoint, "[addrMode][DstAddr][extSrcAddrHigh][extSrcAddrLow][extDstAddrHigh][extDstAddrLow/GroupID][ep_Src][ep_Dst][ClusterId]\r\n"},
#ifdef OTAU_SERVER
   {"setUpgradeEndReqStaus", "d", processSetAbortUpgradeEndReq, "[value]\r\n"},
#endif
 #endif // #if ZDO_COMMANDS_IN_CONSOLE == 1
  {0,0,0,0},
};

static const ConsoleCommand_t zgpHelpCmds[] =
{
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
  {"resetZgpTableToFN", "", processZgpTableResetToFnCmd, "-> reset zgp table to FN\r\n"},
  {"setPassiveAckThreshold", "d", processSetPassiveAckThresholdCmd, "[ThresholdValue]\r\n"},
  {"RestorePassiveAckThreshold", "", processRestorePassiveAckThresholdCmd, "->Restores the Passive Ack Threshold Value\r\n"},
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#if (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
  {"SendSimpleDescReq", "dd",processSendSimpleDescriptorRequestCmd, \
    "<nwkAddr> <dstEp>\r\n"},
  {"SendSinkTableRequest", "ddddd", processSinkTableRequestCmd, ""},
  {"sendDeviceAnnounceCmd", "dd", processSendDeviceAnnounceCmd, ""},
  {"SendGpRawModeCmd", "varArg", processSendGpRawPayloadCmd, ""},
  {"proxyCommissioningMode", "ddd", processSendProxyCommissioningModeCmd, ""},
  {"sendPairingConfig", "varArg", processSendPairingConfigCmd, ""},
#endif
  {"enableDisableDirectMode", "d", processEnableDisableDirectModeCmd, "-> Enable/Disable direct mode(dstub) <0/1>\r\n"},
  {"SendReadAttribute", "ddd", processSendReadAttributeCmd, "<addr> <dir> <attrId>\r\n"},
  {"SendProxyTableRequest", "ddddd", processProxyTableRequestCmd, "<addr> <options> <GpdId/ieee> <ep> <index>\r\n"},
  {"sinkCommissioningMode", "ddd", processSinkCommissioningModeCmd, "<options> <ep> <unicast>\r\n"},
  {"AddGpdfToTxQueue", "varArg", processAddGpdfToTxQueue, ""},
  {"setGroupIdOrAlias", "dd", processSetGroupIdOrAliasCmd, "<groupIdOrAlais> <value>"},
#ifdef ENABLE_ZGP_TEST_FRAMEWORK
  ZGP_TEST_FRAMEWORK_COMMANDS
#endif // ENABLE_ZGP_TEST_FRAMEWORK
#endif // APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#endif // APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
  {0,0,0,0},
};

#ifdef OTAU_CLIENT
static const ConsoleCommand_t otauHelpCmds[] =
{
  {"getOtauFirmwareVersion",    "", processGetFirmwareVersion,    ""},
  {"getOtauImageUpgradeStatus", "", processGetImageUpgradeStatus, ""},
  {"setOtauQueryInterval",      "d",processSetOtauQueryInterval,  "[interval ms]\r\n"},
  {"setMinimunBlockPeriod",     "d",processSetMinBlockPeriod,     "[interval ms]\r\n"},
#ifdef OTAU_PRIVILEGED_CONSOLE_CMDS
  {"setImageCBCkey",            "dddd",processSetImageKey,        "<0xb1b2b3b4> <0xb5b6b7b8> <0xb9b10b11b12> <0xb13b14b15b16>\r\n"},
  {"setImageCBCIv",             "dddd",processSetImageIV,         "<0xb1b2b3b4> <0xb5b6b7b8> <0xb9b10b11b12> <0xb13b14b15b16>\r\n"},
#endif
  {0,0,0,0},
};
#endif

static BDB_InitiatorReq_t AppinitiatorReq;
static bool powerOffStatus = false;
static HAL_AppTimer_t helpCmdHandlingTimer =
{
  .mode     = TIMER_ONE_SHOT_MODE,
  .interval = 10,
  .callback = helpCmdHandlingTimerFired
};

static HAL_AppTimer_t aTimer;
static HAL_AppTimer_t fbTimer;
/******************************************************************************
                        Gloabl Variables section
******************************************************************************/
BDB_InvokeCommissioningReq_t AppbdbCommissioningreq;
BDB_SetTargetType_t appSetTargetType;
#if ((APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE) || (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER))
  bool doFindAndBind = true;
#else
  bool doFindAndBind = false;
#endif
ScanValue_t localVar;
/******************************************************************************
                        Definitions section
******************************************************************************/
#define ZGP_MAX_PAIRED_ENDPOINTS 252
/******************************************************************************
                        external variables section
******************************************************************************/
extern bool fbRole;
extern uint8_t srcEp;
#ifdef OTAU_SERVER
extern bool abortUpgradeEndRequest;
#endif
extern BDB_CommissioningMode_t autoCommissionsEnableMask;
/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes console
******************************************************************************/
void initConsole(void)
{
  consoleRegisterCommands(helpCmds);
  consoleRegisterZclCommands(zclHelpCmds);
  consoleRegisterCommissioningCommands(commissioningHelpCmds);
  consoleRegisterZdoCommands(zdoHelpCmds);
  consoleRegisterZgpCommands(zgpHelpCmds);
#ifdef OTAU_CLIENT
  consoleRegisterOtauCommands(otauHelpCmds);
#endif
}
/**************************************************************************//**
\brief Processes help command

\param[in] args - array of command arguments
******************************************************************************/
void processHelpCmd(const ScanValue_t *args)
{
  if (NULL == cmdForHelpCmd)
  {
    appSnprintf("Commands: \r\n");
    if (ZCL_COMMANDS_IN_CONSOLE==1 || COMMISSIONING_COMMANDS_IN_CONSOLE==1 || ZDO_COMMANDS_IN_CONSOLE==1)
    {
      cmdForHelpCmd = (ConsoleCommand_t *)helpCmds+1;
      HAL_StartAppTimer(&helpCmdHandlingTimer);
    }
  }
  (void)args;
}

/**************************************************************************//**
\brief Processes zdo help command

\param[in] args - array of command arguments
******************************************************************************/
void processZdoHelpCmd(const ScanValue_t *args)
{
  if (NULL == cmdForHelpCmd)
  {
    appSnprintf("Commands: \r\n");
    cmdForHelpCmd = (ConsoleCommand_t *)zdoHelpCmds;

    HAL_StartAppTimer(&helpCmdHandlingTimer);
  }
  (void)args;
}

/**************************************************************************//**
\brief Processes commissioning help command

\param[in] args - array of command arguments
******************************************************************************/
void processCommissioningHelpCmd(const ScanValue_t *args)
{
  if (NULL == cmdForHelpCmd)
  {
    appSnprintf("Commands: \r\n");
    cmdForHelpCmd = (ConsoleCommand_t *)commissioningHelpCmds;

    HAL_StartAppTimer(&helpCmdHandlingTimer);
  }
  (void)args;
}

/**************************************************************************//**
\brief Processes zcl help command

\param[in] args - array of command arguments
******************************************************************************/
void processZclHelpCmd(const ScanValue_t *args)
{
  if (NULL == cmdForHelpCmd)
  {
    appSnprintf("Commands: \r\n");
    cmdForHelpCmd = (ConsoleCommand_t *)zclHelpCmds;

    HAL_StartAppTimer(&helpCmdHandlingTimer);
  }
  (void)args;
}

/**************************************************************************//**
\brief help command timer handler

\param[in] args - array of command arguments
******************************************************************************/
void helpCmdHandlingTimerFired(void)
{
  appSnprintf("%s\r\n", cmdForHelpCmd->name);
  cmdForHelpCmd++;
  if (cmdForHelpCmd->name)
  {
    HAL_StartAppTimer(&helpCmdHandlingTimer);
  }
  else
    cmdForHelpCmd = NULL;
}

/**************************************************************************//**
\brief Sends single char to serial interface
******************************************************************************/
void consoleTx(char chr)
{
  appSnprintf(&chr);
}

/**************************************************************************//**
\brief Processes single char read from serial interface

\param[in] char - read char
******************************************************************************/
void consoleTxStr(const char *str)
{
  appSnprintf(str);
}

/**************************************************************************//**
\brief Determines address mode for command

\param[in] arg - pointer to command argument with address mode string

\returns address mode
******************************************************************************/
APS_AddrMode_t determineAddressMode(const ScanValue_t *arg)
{
  if (!memcmp("-g", arg->str, 2))
    return APS_GROUP_ADDRESS;

  if (!memcmp("-b", arg->str, 2))
    return APS_NO_ADDRESS;

  if (!memcmp("-e", arg->str, 2))
    return APS_EXT_ADDRESS;

  return APS_SHORT_ADDRESS;
}

#if BDB_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes Set Allow steal command

\param[in] args - array of command arguments
******************************************************************************/
void processSetAllowStealCmd(const ScanValue_t *args)
{
  N_LinkTarget_AllowStealing(args[0].uint8);
}
#endif //BDB_COMMANDS_IN_CONSOLE == 1

#if ZDO_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes Active EP request command

\param[in] args - array of command arguments
******************************************************************************/
static void processActiveEpRequestCmd(const ScanValue_t *args)
{
  zdpActiveEpReq(args[0].uint16,args[1].uint16);
}

/**************************************************************************//**
\brief Processes BindReq command

\param[in] args - array of command arguments
******************************************************************************/
static void processBindReqCmd(const ScanValue_t *args)
{
  ExtAddr_t extAddr = ((uint64_t)args[2].uint32 << 32);
  extAddr |= args[3].uint32;
  zdpBindReq(determineAddressMode(args), args[1].uint16, extAddr, args[4].uint8, srcEp, args[5].uint16);
}

/**************************************************************************//**
\brief Processes BindReqWithSrcAddrDestEndpoint command

\param[in] args - array of command arguments
******************************************************************************/
static void processBindReqCmdWithSrcAddrDestEndpoint(const ScanValue_t *args)
{
  ExtAddr_t extAddrSrc = ((uint64_t)args[2].uint32 << 32);
  extAddrSrc |= args[3].uint32;
  ExtAddr_t extAddrDst = ((uint64_t)args[4].uint32 << 32);
  extAddrDst |= args[5].uint32;
  zdpBindReqWithSrcAddrDestEndpoint(determineAddressMode(args), args[1].uint16, extAddrSrc, extAddrDst, args[6].uint8,args[7].uint8, srcEp, args[8].uint16);
}

/**************************************************************************//**
\brief Processes ieee Addr request command

\param[in] args - array of command arguments
******************************************************************************/
static void processIeeeAddrRequestCmd(const ScanValue_t *args)
{
  zdpIeeeAddrReq(args[0].uint16,args[1].uint16, args[2].uint8);
}
#ifdef _MAC_BAN_NODE_
/**************************************************************************//**
\brief Processes mac ban node command

\param[in] args - array of command arguments
******************************************************************************/
static void processMacBanNodeCmd(const ScanValue_t *args)
{
  ExtAddr_t extAddr = ((uint64_t)args[0].uint32 << 32);
  extAddr |= args[1].uint32;

  MAC_BanNode(args[2].uint16, extAddr, args[3].uint8, args[4].int8);
  appSnprintf("Done\r\n");
}

/**************************************************************************//**
\brief Processes mac ban node command

\param[in] args - array of command arguments
******************************************************************************/
static void processMacResetBanTableCmd(const ScanValue_t *args)
{

  MAC_ResetBanTable();
  appSnprintf("Done\r\n");
  (void)args;
}
#endif
/**************************************************************************//**
\brief Processes Match Descriptor request command

\param[in] args - array of command arguments
******************************************************************************/
static void processMatchDescriptorRequestCmd(const ScanValue_t *args)
{
  zdpMatchDescReq(args[0].uint16,args[1].uint8);
}

/**************************************************************************//**
\brief Processes Node Descriptor request command

\param[in] args - array of command arguments
******************************************************************************/
static void processNodeDescriptorRequestCmd(const ScanValue_t *args)
{
  zdpNodeDescReq(args[0].uint16,args[1].uint16);
}

/**************************************************************************//**
\brief Processes Nwk Addr request command

\param[in] args - array of command arguments
******************************************************************************/
static void processNwkAddrRequestCmd(const ScanValue_t *args)
{
  ExtAddr_t extAddr = ((uint64_t)args[1].uint32 << 32);
  extAddr |= args[2].uint32;
  zdpNwkAddrReq(args[0].uint16,extAddr, args[3].uint8);
}

/**************************************************************************//**
\brief Processes NwkLeaveReq command

\param[in] args - array of command arguments
******************************************************************************/
static void processNwkLeaveReqCmd(const ScanValue_t *args)
{
  ExtAddr_t extAddr = ((uint64_t)args[0].uint32 << 32);
  extAddr |= args[1].uint32;
  nwkLeaveCommand(extAddr, args[2].uint8, args[3].uint8);
}

/**************************************************************************//**
\brief Processes Mgmt SendBind Request command

\param[in] args - array of command arguments
******************************************************************************/
static void processMgmtSendBindReqCmd(const ScanValue_t *args)
{
  zdpMgmtBindReq(args[0].uint16, args[1].uint8);
}

/**************************************************************************//**
\brief Processes Mgmt SendLqi Request command

\param[in] args - array of command arguments
******************************************************************************/
static void processMgmtSendLqiReqCmd(const ScanValue_t *args)
{
  zdpMgmtLqiReq(args[0].uint16, args[1].uint8);
}

/**************************************************************************//**
\brief Processes MgmtSendLeave Request command

\param[in] args - array of command arguments
******************************************************************************/
static void processMgmtSendLeaveReqCmd(const ScanValue_t *args)
{
  ExtAddr_t extAddr = ((uint64_t)args[1].uint32 << 32);
  extAddr |= args[2].uint32;
  zdpMgmtLeaveReq(args[0].uint16, extAddr, args[3].uint8, args[4].uint8);
}

/**************************************************************************//**
\brief ZDP device announce response callback

\param[in] leaveResp - pointer to response structure
******************************************************************************/
static void zdoPermitJoiningResponse(ZDO_ZdpResp_t *resp)
{
  appSnprintf("setPermitJoinRsp %d\r\n", resp->respPayload.status);
}

/**************************************************************************//**
\brief Processes Set Permit Join command

\param[in] args - array of command arguments
******************************************************************************/
static void processMgmtSendPermitJoinCmd(const ScanValue_t *args)
{
  ZDO_MgmtPermitJoiningReq_t *permit = &descModeMem.zdpReq.req.reqPayload.mgmtPermitJoiningReq;

  descModeMem.zdpReq.ZDO_ZdpResp = zdoPermitJoiningResponse;
  descModeMem.zdpReq.reqCluster = MGMT_PERMIT_JOINING_CLID;
  descModeMem.zdpReq.dstAddrMode = APS_SHORT_ADDRESS;

  descModeMem.zdpReq.dstAddress.shortAddress = args[0].uint16;

  permit->permitDuration = args[1].uint8;
  permit->tcSignificance = args[2].uint8;

  ZDO_ZdpReq(&descModeMem.zdpReq);
}

#if BDB_TOUCHLINK_SUPPORT == 1
/**************************************************************************//**
\brief assocDiscoveryDone Callback

\param[in] result - result of action
******************************************************************************/
static void assocDiscoveryDone(N_Connection_Result_t result)
{
  (void)result;
}

/**************************************************************************//**
\brief Processes Send Beacon Request command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendBeaconReqCmd(const ScanValue_t *args)
{
   N_Beacon_t beacon;
   N_Connection_AssociateDiscovery(&beacon, N_Connection_AssociateDiscoveryMode_AnyPan, NULL, assocDiscoveryDone);

 (void) args;
}

#endif

/**************************************************************************//**
\brief zdoupdate Response

\param[in] resp - pointer to Zdp Response structure
******************************************************************************/
static void zdoupdateResponse(ZDO_ZdpResp_t *resp)
{
  appSnprintf( "Update Done %d\r\n", resp->respPayload.status);
}

/**************************************************************************//**
\brief Processes SendNwk Update Request command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendNwkUpdateReqCmd(const ScanValue_t *args)
{
  ZDO_MgmtNwkUpdateReq_t *mgmtupdatereq = &descModeMem.zdpReq.req.reqPayload.mgmtNwkUpdateReq;

  descModeMem.zdpReq.ZDO_ZdpResp = zdoupdateResponse;
  descModeMem.zdpReq.reqCluster = MGMT_NWK_UPDATE_CLID;
  descModeMem.zdpReq.dstAddrMode = APS_SHORT_ADDRESS;

  descModeMem.zdpReq.dstAddress.shortAddress = args[2].uint16;

  mgmtupdatereq->scanChannels = 1UL << args[0].uint8;
  mgmtupdatereq->scanDuration = args[1].uint8;
  mgmtupdatereq->nwkManagerAddr = 0;
  mgmtupdatereq->nwkUpdateId = NWK_GetUpdateId() + 1;
  mgmtupdatereq->scanCount = 0;

  ZDO_ZdpReq(&descModeMem.zdpReq);
}

/**************************************************************************//**
\brief Processes Simple Descriptor request command

\param[in] args - array of command arguments
******************************************************************************/
static void processSimpleDescriptorRequestCmd(const ScanValue_t *args)
{
  zdpSimpleDescReq(args[0].uint16,args[1].uint8);
}

/**************************************************************************//**
\brief Processes UnBindReq command

\param[in] args - array of command arguments
******************************************************************************/
static void processUnBindReqCmd(const ScanValue_t *args)
{
  ExtAddr_t extAddr = ((uint64_t)args[2].uint32 << 32);
  extAddr |= args[3].uint32;
  zdpUnBindReq(determineAddressMode(args), args[1].uint16, extAddr, args[4].uint8, srcEp, args[5].uint16);
}

/**************************************************************************//**
\brief Processes UnBindReqWithSrcAddrDestEndpoint command

\param[in] args - array of command arguments
******************************************************************************/
static void processUnBindReqCmdWithSrcAddrDestEndpoint(const ScanValue_t *args)
{
  ExtAddr_t extAddrSrc = ((uint64_t)args[2].uint32 << 32);
  extAddrSrc |= args[3].uint32;
  ExtAddr_t extAddrDst = ((uint64_t)args[4].uint32 << 32);
  extAddrDst |= args[5].uint32;
  zdpUnBindReqWithSrcAddrDestEndpoint(determineAddressMode(args), args[1].uint16, extAddrSrc, extAddrDst, args[6].uint8, args[7].uint8, srcEp, args[8].uint16);
}
#ifdef OTAU_SERVER
/**************************************************************************//**
\brief Processes processSetAbortUpgradeEndReq command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetAbortUpgradeEndReq(const ScanValue_t *args)
{
  abortUpgradeEndRequest =  (bool)args[0].uint8;
}
#endif
#endif // #if ZDO_COMMANDS_IN_CONSOLE == 1

#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
#if (BDB_TOUCHLINK_SUPPORT == 1) && (BDB_TOUCHLINK_INITIATOR_SUPPORT == 1)
/**************************************************************************//**
\brief Processes SetTL Role command

\param[in] args - array of command arguments
******************************************************************************/
void processSetTLRole(const ScanValue_t *args)
{
  BDB_SetToulinkRole(args[0].uint8);
  (void)args;
}
#endif

#if BDB_TOUCHLINK_SUPPORT == 1
/**************************************************************************//**
\brief Processes Set Allow steal command

\param[in] args - array of command arguments
******************************************************************************/
void processSetAllowTLResetToFNCmd(const ScanValue_t *args)
{
  BDB_SetAllowTLResetToFN(args[0].uint8);
}
#endif

#if ZB_COMMISSIONING_ON_STARTUP == 0
/**************************************************************************//**
\brief Processes SetFB Role command

\param[in] args - array of command arguments
******************************************************************************/
void processSetFBRole(const ScanValue_t *args)
{
  fbRole = args[0].uint8;
  (void)args;
}
#endif

/**************************************************************************//**
\brief Process SetTCLK Exchange Method command

\param[in] args - array of command arguments
******************************************************************************/
void processSetTCLKExchangeMethodCmd(const ScanValue_t *args)
{
  BDB_SetTCLKExchangeMethod(args[0].uint8);
  (void)args;
}

/**************************************************************************//**
\brief Processes SetTCLK Max Retry Attempts command

\param[in] args - array of command arguments
******************************************************************************/
void processSetTCLKMaxRetryAttemptsCmd(const ScanValue_t *args)
{
  BDB_SetTCLKRetryMaxAttempts(args[0].uint8);
  (void)args;
}

/**************************************************************************//**
\brief Processes Global Key command

\param[in] args - array of command arguments
******************************************************************************/
void processsetGlobalKeyCmd(const ScanValue_t *args)
{
  tempfuctionsetkey(args[0].uint8);
}

/**************************************************************************//**
\brief ZDO permit join response callback

\param[in] resp - pointer to response structure
******************************************************************************/
static void zdoPermitJoinResponse(ZDO_ZdpResp_t *resp)
{
  appSnprintf("setPermitJoinRsp %d\r\n", resp->respPayload.status);
}

/**************************************************************************//**
\brief Processes Set Permit Join command

\param[in] args - array of command arguments
******************************************************************************/
void processSetPermitJoinCmd(const ScanValue_t *args)
{
  ZDO_MgmtPermitJoiningReq_t *permit = &descModeMem.zdpReq.req.reqPayload.mgmtPermitJoiningReq;
  descModeMem.zdpReq.ZDO_ZdpResp = zdoPermitJoinResponse;
  descModeMem.zdpReq.reqCluster = MGMT_PERMIT_JOINING_CLID;
  descModeMem.zdpReq.dstAddrMode = APS_SHORT_ADDRESS;

  descModeMem.zdpReq.dstAddress.shortAddress = NWK_GetShortAddr();

  permit->permitDuration = args[0].uint8;
  permit->tcSignificance = 0x01;

  ZDO_ZdpReq(&descModeMem.zdpReq);
}

/**************************************************************************//**
\brief BDB invoke commissioning callback

\param[in] conf - pointer to confirmation structure
******************************************************************************/
static void Callback_Commissioning(BDB_InvokeCommissioningConf_t *conf)
{
  appSnprintf("CommissioningStatus = %d\r\n", conf->status);
}

/**************************************************************************//**
\brief Function to check if more than one Comm Mode is set

\param[in] conf - pointer to confirmation structure
******************************************************************************/
static bool checkCommModeBits(BDB_CommissioningMode_t mode)
{
  uint8_t noOfCommModeBitSet = 0;

  if(mode & 0x01)
    noOfCommModeBitSet++;
  if(mode & 0x02)
    noOfCommModeBitSet++;
  if(mode & 0x04)
    noOfCommModeBitSet++;
  if(mode & 0x08)
    noOfCommModeBitSet++;
  
  if(noOfCommModeBitSet > 1)
   return true;
  
  return false;
}
/**************************************************************************//**
\brief Processes Invoke Commissioning command

\param[in] args - array of command arguments
******************************************************************************/
void processInvokeCommissioningCmd(const ScanValue_t *args)
{
  memset(&AppbdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
  autoCommissionsEnableMask = args[0].uint8;
  if(checkCommModeBits(autoCommissionsEnableMask))
  {
    appSnprintf("User cannot invoke more than one commissioning at a time");
    return;
  }
  AppbdbCommissioningreq.mode = determineCommissionMode();
  AppbdbCommissioningreq.initiatorReq = NULL;
  AppBindReq_t *appBindReqLocal = deviceBindReqs[0];

  for(uint8_t i=0;i < APP_ENDPOINTS_AMOUNT;i++ )
  {
      if(deviceBindReqs[i]->srcEndpoint == srcEp)
      {
        appBindReqLocal = deviceBindReqs[i];
        break;
      }
  }
#if ZB_COMMISSIONING_ON_STARTUP != 1
  if (fbRole)
  {
#endif
    AppbdbCommissioningreq.initiatorReq = &AppinitiatorReq;

    if ((args[1].uint16 == 0U) || (args[1].uint16 == 0xffffU))
    {
      AppbdbCommissioningreq.initiatorReq->groupId = 0xffffu;
    }
    else
    {
      AppbdbCommissioningreq.initiatorReq->groupId = args[1].uint16;
    }
    AppbdbCommissioningreq.initiatorReq->initiatorEndpoint = appBindReqLocal->srcEndpoint;
    AppbdbCommissioningreq.initiatorReq->clientClustersCount = appBindReqLocal->remoteServersCnt;
    AppbdbCommissioningreq.initiatorReq->serverClustersCount = appBindReqLocal->remoteClientsCnt;
    AppbdbCommissioningreq.initiatorReq->clientClustersList=appBindReqLocal->remoteServers;
    AppbdbCommissioningreq.initiatorReq->serverClustersList=appBindReqLocal->remoteClients;
    AppbdbCommissioningreq.initiatorReq->callback = appBindReqLocal->callback;
#if ZB_COMMISSIONING_ON_STARTUP != 1
  }
  else
  {
    AppbdbCommissioningreq.initiatorReq = NULL;
  }
#endif
  AppbdbCommissioningreq.BDB_InvokeCommissioningConf = Callback_Commissioning;
  BDB_InvokeCommissioning(&AppbdbCommissioningreq);
}

static void Callback_FormAndSteerFB(BDB_InvokeCommissioningConf_t *conf)
{
  appSnprintf("CommissioningStatus = %d\r\n", conf->status);
}

/**************************************************************************//**
\brief Timer callback
******************************************************************************/
void fbTimerFired(void)
{
  if(autoCommissionsEnableMask == 0x08)
  {
    memset(&AppbdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
    AppbdbCommissioningreq.mode = determineCommissionMode();
    AppbdbCommissioningreq.initiatorReq = NULL;
    const AppBindReq_t *appBindReqLocal = deviceBindReqs[0];
#if BDB_FINDINGBINDING_INITIATOR_TARGET_PARALLEL_EXECUTION != 1
if((APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE) || (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COLOR_SCENE_CONTROLLER))
{
  AppbdbCommissioningreq.initiatorReq = &AppinitiatorReq;
  AppbdbCommissioningreq.initiatorReq->groupId = 0xffffu;
    
  AppbdbCommissioningreq.initiatorReq->initiatorEndpoint = appBindReqLocal->srcEndpoint;
  AppbdbCommissioningreq.initiatorReq->clientClustersCount = appBindReqLocal->remoteServersCnt;
  AppbdbCommissioningreq.initiatorReq->serverClustersCount = appBindReqLocal->remoteClientsCnt;
  AppbdbCommissioningreq.initiatorReq->clientClustersList=appBindReqLocal->remoteServers;
  AppbdbCommissioningreq.initiatorReq->serverClustersList=appBindReqLocal->remoteClients;
  AppbdbCommissioningreq.initiatorReq->callback = appBindReqLocal->callback;
}
#endif
  }
    AppbdbCommissioningreq.BDB_InvokeCommissioningConf = Callback_FormAndSteerFB;
    BDB_InvokeCommissioning(&AppbdbCommissioningreq);
}

/**************************************************************************//**
\brief Form And Steer1 callback

\param[in] conf - pointer to confirmation structure
******************************************************************************/
static void Callback_FormAndSteer1(BDB_InvokeCommissioningConf_t *conf)
{
  if(autoCommissionsEnableMask == 0x00)
    appSnprintf("CommissioningStatus = %d\r\n", conf->status);
  else
  {
     fbTimer.interval = 5;
     fbTimer.mode     = TIMER_ONE_SHOT_MODE;
     fbTimer.callback = fbTimerFired;
     HAL_StartAppTimer(&fbTimer);
  }

}

void aTimerFired(void)
{
  if (doFindAndBind)
  {
    localVar.uint8 = 10;
  }
  else
  {
    localVar.uint8 = 2;
  }
  autoCommissionsEnableMask = localVar.uint8;
  memset(&AppbdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
  AppbdbCommissioningreq.mode = determineCommissionMode();
  AppbdbCommissioningreq.BDB_InvokeCommissioningConf = Callback_FormAndSteer1;
  BDB_InvokeCommissioning(&AppbdbCommissioningreq);
}

/**************************************************************************//**
\brief Form And Steer callback

\param[in] conf - pointer to confirmation structure
******************************************************************************/
static void Callback_FormAndSteer(BDB_InvokeCommissioningConf_t *conf)
{
  aTimer.interval = 5;
  aTimer.mode     = TIMER_ONE_SHOT_MODE;
  aTimer.callback = aTimerFired;
  HAL_StartAppTimer(&aTimer);
}

/**************************************************************************//**
\brief Process Form And Steer command

\param[in] args - array of command arguments
******************************************************************************/
void processFormAndSteerCmd(const ScanValue_t *args)
{
  doFindAndBind = false;
  localVar.uint8 = 4;
  autoCommissionsEnableMask = localVar.uint8;
  memset(&AppbdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
  AppbdbCommissioningreq.mode = determineCommissionMode();
  AppbdbCommissioningreq.initiatorReq = NULL;
  AppbdbCommissioningreq.BDB_InvokeCommissioningConf = Callback_FormAndSteer;
  BDB_InvokeCommissioning(&AppbdbCommissioningreq);
}

/**************************************************************************//**
\brief Process Form And Steer and FB command

\param[in] args - array of command arguments
******************************************************************************/
void processFormSteerAndFBCmd(const ScanValue_t *args)
{
  doFindAndBind = true;
  localVar.uint8 = 4;
  autoCommissionsEnableMask = localVar.uint8;
  memset(&AppbdbCommissioningreq,0,sizeof(BDB_InvokeCommissioningReq_t));
  AppbdbCommissioningreq.mode = determineCommissionMode();
  AppbdbCommissioningreq.BDB_InvokeCommissioningConf = Callback_FormAndSteer;
  BDB_InvokeCommissioning(&AppbdbCommissioningreq);
}

/**************************************************************************//**
\brief Processes get extended address command

\param[in] args - array of command arguments
******************************************************************************/
void processGetExtAddrCmd(const ScanValue_t *args)
{
  ExtAddr_t ieeeAddr;
  uint8_t* extAddr;
  memcpy(&ieeeAddr, MAC_GetExtAddr(), sizeof(ExtAddr_t));
  extAddr = (uint8_t*)&ieeeAddr;

  appSnprintf("%08x", *((uint32_t*)&extAddr[4]));
  appSnprintf("%08x", *((uint32_t*)&extAddr[0]));

  appSnprintf("\r\n");
  (void)args; /*Do nothing, just to avoid compiler warning*/
  (void)extAddr; /*Do nothing, just to avoid compiler warning*/
}

/**************************************************************************//**
\brief Processes get network address command

\param[in] args - array of command arguments
******************************************************************************/
void processGetNetworkAddressCmd(const ScanValue_t *args)
{
  (void)args;
  appSnprintf("%04x\r\n", NWK_GetShortAddr());
}

/**************************************************************************//**
\brief Processes get channel command

\param[in] args - array of command arguments
******************************************************************************/
void processGetChannelCmd(const ScanValue_t *args)
{
  uint8_t currentChannel;
  CS_ReadParameter(CS_RF_CURRENT_CHANNEL_ID, &currentChannel); 
  appSnprintf("%03d\r\n", currentChannel);
  (void)args;
}

/**************************************************************************//**
\brief Processes pseudo power off command

\param[in] args - array of command arguments
******************************************************************************/
void processPseudoPowerOffCmd(const ScanValue_t *args)
{
  /* Disable BitCloud tasks for preventing calls to the radio.
     HAL is enabled so it it allows to receive commands through UART. */
  SYS_ClearEvents();
  SYS_DisableTask(ZLL_TASK_ID);
  SYS_DisableTask(ZCL_TASK_ID);
#ifndef ZAPPSI_HOST
  SYS_DisableTask(ZDO_TASK_ID);
  SYS_DisableTask(APS_TASK_ID);
  SYS_DisableTask(NWK_TASK_ID);
  SYS_DisableTask(MAC_PHY_HWD_TASK_ID);
#else
  {
    ZsiEntityService_t service;
    ATOMIC_SECTION_ENTER
        SYS_taskFlag &= ~(ZLL_TASK_ID);
        SYS_taskFlag &= ~(ZCL_TASK_ID);
    ATOMIC_SECTION_LEAVE
    zsiProcessCommand(ZSI_SREQ_CMD, &service, zsiSerializeSYS_PseudoPowerOffReq, NULL);

  }
#endif
  powerOffStatus = true;

  (void)args;
}

/**************************************************************************//**
\brief Processes reset command: reset device

\param[in] args - array of command arguments
******************************************************************************/
void processResetCmd(const ScanValue_t *args)
{
  (void)args;
#ifdef ZAPPSI_HOST
  /* In case of reset command received on Host first NP
     then Host application need to be reset
     To be implemented
   */
  appResetNP();
#else
  SystemReset();
#endif
}

/**************************************************************************//**
\brief Processes reset to factory fresh

\param[in] args - array of command arguments
******************************************************************************/
void processResetToFactoryFreshCmd(const ScanValue_t *args)
{
  (void)args;
#ifndef ZAPPSI_HOST  
  BDB_ResetToFactoryNew(!powerOffStatus);
#endif  
}

/**************************************************************************//**
\brief To set a new entended address

\param[in] args - extended address
******************************************************************************/
void processSetExtAddr(const ScanValue_t *args)
{
  ExtAddr_t changeExtAddr = ((uint64_t)args[0].uint32 << 32);
  changeExtAddr |= args[1].uint32;
  CS_WriteParameter(CS_UID_ID , &changeExtAddr);
  csPIB.macAttr.extAddr = changeExtAddr;
}

/**************************************************************************//**
\brief Processes set cca mode command

\param[in] args - cca mode and ed threshold
******************************************************************************/
void processSetCCAModeAndThresholdCmd(const ScanValue_t *args)
{
  PHY_SetReq_t  phySetReq;

  CS_WriteParameter(CS_RF_CCA_MODE_ID, &args[0].uint8);
  CS_WriteParameter(CS_RF_CCA_ED_THRES_ID, &args[1].uint8);   
    
  phySetReq.attr.phyPib.ccaMode = (PHY_CcaMode_t)args[0].uint8;
  phySetReq.id = (PHY_SetPibId_t)PHY_PIB_CCA_MODE_ID;
  PHY_SetReq(&phySetReq);

  phySetReq.attr.macPib.ccaEdThres = (uint8_t)args[1].uint8;
  phySetReq.id = (PHY_SetPibId_t)MAC_PIB_CCA_ED_THRES;
  PHY_SetReq(&phySetReq);
  appSnprintf("Done\r\n");

}

/**************************************************************************//**
\brief Processes get cca mode command
\param[in] args - None
******************************************************************************/
void processGetCCAModeAndThresholdCmd(const ScanValue_t *args)
{
  uint8_t regVal;
  
  regVal = phyReadRegister(PHY_CC_CCA_REG);
   
  appSnprintf("CCA Mode = %d\r\n", (regVal & 0x60)>>5);
  
  regVal = phyReadRegister(CCA_THRESH_REG);

  appSnprintf("ED threshold = %d\r\n", regVal & 0xf);
}

#endif //#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1

#ifdef OTAU_CLIENT
/**************************************************************************//**
\brief To set a new otau query interval

\param[in] args - interval in ms
******************************************************************************/
void processSetOtauQueryInterval(const ScanValue_t *args)
{
  uint32_t otauQueryInterval = args[0].uint32;
  CS_WriteParameter(CS_ZCL_OTAU_QUERY_INTERVAL_ID , &otauQueryInterval);
}
void processGetFirmwareVersion(const ScanValue_t *args)
{
  appSnprintf("Firmware Version 0x%04x\r\n",csSIB.csOtauFileVersion);
}

void processGetImageUpgradeStatus(const ScanValue_t *args)
{
  appSnprintf("Image Ugrade Status %d\r\n",otauClientAttributes.imageUpgradeStatus.value);
}
void processSetMinBlockPeriod(const ScanValue_t *args)
{
  otauClientAttributes.minimumBlockPeriod.value = args[0].uint16;
}

#ifdef OTAU_PRIVILEGED_CONSOLE_CMDS

void processSetImageKey (const ScanValue_t *args)
{
    uint32_t imageKey[4];

    imageKey[0] = args[0].uint32;
    imageKey[1] = args[1].uint32;
    imageKey[2] = args[2].uint32;
    imageKey[3] = args[3].uint32;
    otauSetNewKey((uint8_t *)imageKey);
}
void processSetImageIV (const ScanValue_t *args)
{
    uint32_t imageIV[4];

    imageIV[0] = args[0].uint32;
    imageIV[1] = args[1].uint32;
    imageIV[2] = args[2].uint32;
    imageIV[3] = args[3].uint32;
    otauSetNewIV((uint8_t *)imageIV);
}

#endif //OTAU_PRIVILEGED_CONSOLE_CMDS

#endif

#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes Set Primary Channel Mask command

\param[in] args - array of command arguments
******************************************************************************/
void processSetPrimaryChannelMaskCmd(const ScanValue_t *args)
{
  BDB_SetChannelMask(PRIMARY_CHANNEL_MASK, args[0].uint32);
  (void)args;
}

/**************************************************************************//**
\brief Processes Set Secondary Channel Mask command

\param[in] args - array of command arguments
******************************************************************************/
void processSetSecondaryChannelMaskCmd(const ScanValue_t *args)
{
  BDB_SetChannelMask(SECONDARY_CHANNEL_MASK, args[0].uint32);
  (void)args;
}
#endif //#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1

#if ZCL_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes Read attribute command

\param[in] args - array of command arguments
******************************************************************************/
void processReadAttrCmd(const ScanValue_t *args)
{
   readAttribute(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
     args[3].uint16, args[4].uint16, NULL);
}

/**************************************************************************//**
\brief Processes Read attribute Multiple command

\param[in] args - array of command arguments
******************************************************************************/
void processReadAttrMultipleCmd(const ScanValue_t *args)
{
   readAttributeMultiple(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
     args[3].uint16, args[4].uint16, args[5].uint8, NULL);
}

/**************************************************************************//**
\brief Processes Write attribute command

\param[in] args - array of command arguments
******************************************************************************/
void processWriteAttrCmd(const ScanValue_t *args)
{
   writeAttribute(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, args[3].uint16,
     args[5].uint8, args[4].uint16, (void *)&args[6].uint8, args[7].uint8, NULL);
}

/**************************************************************************//**
\brief Processes Write attribute command

\param[in] args - array of command arguments
******************************************************************************/
void processWriteAttrNoRespCmd(const ScanValue_t *args)
{
   writeAttributeNoResp(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, args[3].uint16,
     args[5].uint8, args[4].uint16, (void *)&args[6].uint8, args[7].uint8, NULL);
}

/**************************************************************************//**
\brief Processes Configure specified cluster attribute reporting command

\param[in] args - array of command arguments
******************************************************************************/
void processConfigureReportingCmd(const ScanValue_t *args)
{
   configureReporting(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, args[3].uint16,
     args[4].uint16, args[5].uint8, args[6].uint16, args[7].uint16);
}

/**************************************************************************//**
\brief Processes Start reporting command

\param[in] args - array of command arguments
******************************************************************************/
void processStartReportingCmd(const ScanValue_t *args)
{
   ZCL_StartReporting();
}

/**************************************************************************//**
\brief Processes Configure specified cluster attribute reporting command

\param[in] args - array of command arguments
******************************************************************************/
void processConfigureReportingWithReportableChangeCmd(const ScanValue_t *args)
{
    configureReportingWithRC(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, args[3].uint16,
      args[4].uint16, args[5].uint8, args[6].uint16, args[7].uint16, (void *)&args[8]);
}

/**************************************************************************//**
\brief Processes ReadReporting command

\param[in] args - array of command arguments
******************************************************************************/
void processReadReportingCmd(const ScanValue_t *args)
{
  readReporting(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, args[3].uint16,
    args[4].uint16);
}

/**************************************************************************//**
\brief Processes disableDefaultResp command

\param[in] args - array of command arguments
******************************************************************************/
void processDisableDefaultResponseBitCmd(const ScanValue_t *args)
{
  switch (args[0].uint8)
  {
    case ZCL_FRAME_CONTROL_DISABLE_DEFAULT_RESPONSE:
    case ZCL_FRAME_CONTROL_ENABLE_DEFAULT_RESPONSE:
      setZclDefaultResponseBit(args[0].uint8);
      break;
  }
}

#if BDB_COMMANDS_IN_CONSOLE == 1
#if BDB_TOUCHLINK_SUPPORT == 1 
/**************************************************************************//**
\brief Set type routine completion callback
\param[in] status - status of action
******************************************************************************/
static void setTypeDone(BDB_LinkTarget_Status_t status)
{
  if(status == BDB_LinkTarget_Status_Ok)
    appSnprintf("Done\r\n");
  else
    appSnprintf("NotDone\r\n");
}
/**************************************************************************//**
\brief Processes Set Target Type command

\param[in] args - array of command arguments
******************************************************************************/
void processSetTargetTypeCmd(const ScanValue_t *args)
{
  memset(&appSetTargetType,0,sizeof(BDB_SetTargetType_t));
  appSetTargetType.targetType = args[0].uint8;
  appSetTargetType.BDB_SetTargetTypeConf = setTypeDone;

  BDB_SetTargetType(&appSetTargetType);
}

#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
/**************************************************************************//**
\brief ResetTarget Callback

\param[in] status - status of action
******************************************************************************/
static void ResetTargetCallback(ResetTargetStatus_t status)
{
  appSnprintf("Status = %d\r\n", status);
}

/**************************************************************************//**
\brief Processes TargetToFn command

\param[in] args - array of command arguments
******************************************************************************/
void processTargetToFnCmd(const ScanValue_t *args)
{
  BDB_ResetVia_TouchlinkCluster(ResetTargetCallback);
}
#endif // #if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
#endif // #if BDB_TOUCHLINK_SUPPORT == 1 
#endif // #if BDB_COMMANDS_IN_CONSOLE == 1

#endif // #if ZCL_COMMANDS_IN_CONSOLE == 1

#ifdef OTAU_CLIENT
/**************************************************************************//**
\brief Processes OTAU  help command

\param[in] args - array of command arguments
******************************************************************************/
void processOtauHelpCmd(const ScanValue_t *args)
{
  if (NULL == cmdForHelpCmd)
  {
    appSnprintf("Commands: \r\n");
    cmdForHelpCmd = (ConsoleCommand_t *)otauHelpCmds;
    HAL_StartAppTimer(&helpCmdHandlingTimer);
  }
  (void)args;
}
#endif

#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
/**************************************************************************//**
\brief Processes reset zgp table to factoryNew command

\param[in] args - array of command arguments
******************************************************************************/
static void processZgpTableResetToFnCmd(const ScanValue_t *args)
{
  ZGPL_ResetTableToFN();
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#ifndef ZGP_DISABLE_TRANSLATION_TABLE
  ZGP_TransTableInit(true);
#endif
#endif
  (void)args;
}

/**************************************************************************//**
\brief Processes zgp help command

\param[in] args - array of command arguments
******************************************************************************/
void processZgpHelpCmd(const ScanValue_t *args)
{
  if (NULL == cmdForHelpCmd)
  {
    appSnprintf("Commands: \r\n");
    cmdForHelpCmd = (ConsoleCommand_t *)zgpHelpCmds;

    HAL_StartAppTimer(&helpCmdHandlingTimer);
  }
  (void)args;
}
/**************************************************************************//**
\brief Processes Restore Passive Ack Threshold command

\param[in] args - array of command arguments
******************************************************************************/
static void processRestorePassiveAckThresholdCmd(const ScanValue_t *args)
{
  NWK_SetPassiveAckThreshold(CS_CUSTOM_PASSIVE_ACK_THRESHOLD);
}

/**************************************************************************//**
\brief Processes Set Passive Ack Threshold command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetPassiveAckThresholdCmd(const ScanValue_t *args)
{
  NWK_SetPassiveAckThreshold(args[0].uint8);
}

#endif

#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#if (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
/**************************************************************************//**
\brief Processes send device announce command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendDeviceAnnounceCmd(const ScanValue_t *args)
{
  ZGPL_SendDeviceAnnounceCmd(args[0].uint16, args[1].uint32);
}

/**************************************************************************//**
\brief Processes Simple Descriptor request command

\param[in] args - array of command arguments
******************************************************************************/
void processSendSimpleDescriptorRequestCmd(const ScanValue_t *args)
{
  ZGPL_SendSimpleDescReq(args[0].uint16, args[1].uint8);
}

/**************************************************************************//**
\brief Processes sink table requets command

\param[in] args - array of command arguments
******************************************************************************/
static void processSinkTableRequestCmd(const ScanValue_t *args)
{
  ZGPH_SendSinkTableRequest(args[0].uint16, args[1].uint8, args[2].uint32, args[3].uint8, args[4].uint8);
}

/**************************************************************************//**
\brief Processes gp RawPayloadCmd command(sending first 6 bytes)

\param[in] args - array of command arguments
******************************************************************************/
static void processSendGpRawPayloadCmd(const ScanValue_t *args)
{
  uint8_t payLoad[ZCL_MAX_TX_ZSDU_SIZE];
  ZCL_Addressing_t dstAddr;

  memset(&dstAddr, 0, sizeof(ZCL_Addressing_t));

  for (uint8_t index = 0; index <args[0].uint8 - 4; index++)
    payLoad[index] = args[index+5].uint8;

  dstAddr.addrMode = args[1].uint8;
  dstAddr.addr.shortAddress = args[2].uint16;
  dstAddr.aliasSrcAddr = NWK_NO_SHORT_ADDR;
  ZGPH_SendCmdInRawMode(&dstAddr, args[3].uint8, args[4].uint8, args[0].uint8 - 4, &payLoad[0]);
}
/**************************************************************************//**
\brief Processes Simple Descriptor request command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendProxyCommissioningModeCmd(const ScanValue_t *args)
{
  zgpGpProxyCommModeOptions_t options;

  memcpy((void *)&options, &args[0].uint8, sizeof(options));
  ZGPH_SendProxyCommissioningModeCommand(options, args[1].uint16, args[2].uint8);
}
/**************************************************************************//**
\brief Processes sink commissioning mode command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendPairingConfigCmd(const ScanValue_t *args)
{
  APS_Address_t dstAddr;
  ZGP_PairingConfigCmdInfo_t pairingConfigCmdInfo;
  ZGP_EndpointInfo_t endPointInfo;
  uint8_t pairedEndpoints[ZGP_MAX_PAIRED_ENDPOINTS] = {0};
  ZGP_InfraDeviceStatus_t status = ZCL_SUCCESS_STATUS;

  memset(&pairingConfigCmdInfo, 0 , sizeof(ZGP_PairingConfigCmdInfo_t));
  memset(&endPointInfo, 0, sizeof(ZGP_EndpointInfo_t));

  dstAddr.shortAddress = args[1].uint16;
  pairingConfigCmdInfo.appId = args[2].uint8;
  memcpy(&pairingConfigCmdInfo.gpdId, &args[3].uint32, 4);
  pairingConfigCmdInfo.gpdEndPoint = args[4].uint8;
  pairingConfigCmdInfo.action.action = args[5].uint8;
  pairingConfigCmdInfo.action.sendGpPairing = true;
  pairingConfigCmdInfo.commMode = args[6].uint8;

  endPointInfo.noOfPairedEndPoints = args[7].uint8;
  if(endPointInfo.noOfPairedEndPoints != 0 && endPointInfo.noOfPairedEndPoints != 0xff &&
     endPointInfo.noOfPairedEndPoints != 0xFE && endPointInfo.noOfPairedEndPoints != 0xfd)
  {
    for(uint8_t i = 0; i < endPointInfo.noOfPairedEndPoints ; i++)
    {
     pairedEndpoints[i] = args[8+i].uint8;
    }
  }
  endPointInfo.pairedEndpoints = pairedEndpoints;
  status = ZGPH_SendGpPairingConfigCmd(APS_SHORT_ADDRESS,&dstAddr, pairingConfigCmdInfo, NULL, endPointInfo);
  appSnprintf("ZgpConfirm: status = 0x%02x\r\n", status);
}
#endif // (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)

/**************************************************************************//**
\brief Processes send GP response command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnableDisableDirectModeCmd(const ScanValue_t *args)
{
  ZGPL_EnableDisableDirectMode(args[0].uint8);
}

/**************************************************************************//**
\brief Processes set groupID or Alias command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetGroupIdOrAliasCmd(const ScanValue_t *args)
{
  if(args[0].uint8)
    ZGPH_SetSinkGroupEntry(args[1].uint16);
  else
    ZGPH_SetGPDAssignedAlias(args[1].uint16);
}
/**************************************************************************//**
\brief Processes sink commissioning mode command

\param[in] args - array of command arguments
******************************************************************************/
static void processSinkCommissioningModeCmd(const ScanValue_t *args)
{
  ZGP_SinkCommissioningModeOptions_t options;

  memcpy((void *)&options, &args[0].uint8, sizeof(options));
  ZGPH_PutLocalSinkInCommissioningMode(&options, args[1].uint8, args[2].uint8);
}

/**************************************************************************//**
\brief Processes  queing of Data GPDF

\param[in] args - array of command arguments
******************************************************************************/
static void processAddGpdfToTxQueue(const ScanValue_t *args)
{
  ZGP_GpdfDataReq_t dStubDataReq;
  uint8_t buffer[MAX_PAYLOAD_BY_GPD];

  dStubDataReq.applicationId = (ZGP_ApplicationId_t) args[1].uint8;
  dStubDataReq.txOptions.gpdfFrameType = ZGP_FRAME_DATA;
  if(ZGP_SRC_APPID == dStubDataReq.applicationId)
  {
    dStubDataReq.srcId = args[2].uint32;
  }
  else if(ZGP_IEEE_ADDR_APPID == dStubDataReq.applicationId)
  {
    dStubDataReq.srcId = args[2].uint32;
    dStubDataReq.gpdIeeeAddress = dStubDataReq.srcId;
    dStubDataReq.endpoint = args[3].uint8;
  }

  dStubDataReq.action = true;
  dStubDataReq.txOptions.txOnMatchingEndpoint = 1; // for App id 2
  dStubDataReq.txOptions.requireMacAck = false;
  dStubDataReq.txOptions.performCsma = false;
  dStubDataReq.frameDir = ZGP_TX_TO_ZGPD;
  dStubDataReq.gpdCommandId = (ZGP_CommandId_t)args[4].uint8;
  dStubDataReq.gpdAsduLength = args[0].uint8 - 4;
  dStubDataReq.gpdAsdu = buffer;
  
  if((dStubDataReq.gpdAsduLength + 1/*gpd Command id*/) > MAX_PAYLOAD_BY_GPD)
    appSnprintf("GPD Payload length should be less than or equal to MAX_PAYLOAD_BY_GPD");

  for(uint8_t i = 0; i < dStubDataReq.gpdAsduLength; i++)
  {
    buffer[i] = args[i+5].uint8;
  }
  dStubDataReq.gpTxQueueEntryLifeTime = DEF_QUEUE_ENTRY_LIFETIME;

  ZGPL_GpdfDataRequest(&dStubDataReq);
}
/**************************************************************************//**
\brief Processes Send read attribute command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendReadAttributeCmd(const ScanValue_t *args)
{
  // ZCL_FRAME_CONTROL_DIRECTION_SERVER_TO_CLIENT - 1
  ZGPH_SendReadAttribute(args[0].uint16, args[1].uint8, args[2].uint16);
}
/**************************************************************************//**
\brief Processes proxy table requets command

\param[in] args - array of command arguments
******************************************************************************/
static void processProxyTableRequestCmd(const ScanValue_t *args)
{
  ZGPH_SendProxyTableRequest(args[0].uint16, args[1].uint8, args[2].uint32, args[3].uint8, args[4].uint8);
}

#endif // APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
#endif // APP_ENABLE_CONSOLE == 1
