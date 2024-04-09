/*******************************************************************************
  Combined Interface console Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ciConsole.c

  Summary:
    This file contains the Combined Interface console implementation.

  Description:
    This file contains the Combined Interface console implementation.
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

#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE)
#if APP_ENABLE_CONSOLE == 1

/******************************************************************************
                    Includes section
******************************************************************************/
#include <app_zigbee/zigbee_console/console.h>
#include <app_zigbee/zigbee_console/consoleCmds.h>
#include <z3device/clusters/include/haClusters.h>
#include <zcl/clusters/include/identifyCluster.h>
#include <z3device/clusters/include/commissioningCluster.h>
#include <z3device/clusters/include/colorControlCluster.h>
#include <z3device/combinedInterface/include/ciBasicCluster.h>
#include <z3device/combinedInterface/include/ciIdentifyCluster.h>
#include <z3device/combinedInterface/include/ciOnOffCluster.h>
#include <z3device/combinedInterface/include/ciLevelControlCluster.h>
#include <z3device/combinedInterface/include/ciGroupsCluster.h>
#include <z3device/combinedInterface/include/ciScenesCluster.h>
#include <z3device/combinedInterface/include/ciOccupancySensingCluster.h>
#include <z3device/combinedInterface/include/ciCommissioningCluster.h>
#include <z3device/combinedInterface/include/ciColorControlCluster.h>
#include <z3device/combinedInterface/include/ciIlluminanceMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciTemperatureMeasurementCluster.h>
#include <z3device/combinedInterface/include/ciThermostatCluster.h>
#include <z3device/combinedInterface/include/ciTimeCluster.h>
#include <z3device/combinedInterface/include/ciAlarmsCluster.h>
#include <z3device/combinedInterface/include/ciIasACECluster.h>
#include <z3device/combinedInterface/include/ciIasZoneCluster.h>
#include <z3device/common/include/z3Device.h>
#include <pds/include/wlPdsMemIds.h>
#include <zdo/include/zdo.h>
#include <nwk/include/nwkAttributes.h>
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
#include <security/TrustCentre/include/tcPermissions.h>
#endif
#include <systemenvironment/include/sysTaskManager.h>
#ifdef BOARD_PC
  #include <conio.h>
#endif
#ifdef ZAPPSI_HOST
#include <zsiHalSerialization.h>
#endif
#include <bdb/include/bdb.h>
#include <bdb/include/bdbInstallCode.h>
#include <zcl/clusters/include/groupsCluster.h>
#include <z3device/clusters/include/scenesCluster.h>
#include <z3device/clusters/include/onOffCluster.h>
#include <z3device/clusters/include/levelControlCluster.h>

#ifdef OTAU_SERVER
#include <zcl/include/zclOTAUCluster.h>
#endif

/******************************************************************************
                    Defines section
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/
#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
static void processGetAppDeviceTypeCmd(const ScanValue_t *args);
static void processGetDeviceTypeCmd(const ScanValue_t *args);

#if BDB_COMMANDS_IN_CONSOLE == 1
static void processSetInstallCodeCmd(const ScanValue_t *args);
#ifndef ZAPPSI_HOST
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
static void processSetAllowRemoteTCpolicyChange(const ScanValue_t *args);
#endif
#endif //#ifndef ZAPPSI_HOST
static void processSetInstallCodeDeviceCmd(const ScanValue_t *args);
static void processSetTrustCenterRequireKeyExchange(const ScanValue_t *args);
#endif // BDB_COMMANDS_IN_CONSOLE == 1
#endif
#if ZCL_COMMANDS_IN_CONSOLE == 1
static void processAddGroupCmd(const ScanValue_t *args);
static void processAddGroupIfIdentifyingCmd(const ScanValue_t *args);
static void processGetGroupMembershipCmd(const ScanValue_t *args);
static void processRemoveAllGroupsCmd(const ScanValue_t *args);
static void processRemoveGroupCmd(const ScanValue_t *args);
static void processViewGroupCmd(const ScanValue_t *args);
#if ZLO_EXTRA_CLUSTERS_SUPPORT == 1
static void processResetToFactoryDefaultsCmd(const ScanValue_t *args);
#endif // ZLO_EXTRA_CLUSTERS_SUPPORT == 1
static void processIdentifyCmd(const ScanValue_t *args);
static void processIdentifyQueryCmd(const ScanValue_t *args);
static void processOnOffToggleCmd(const ScanValue_t *args);
static void processAddSceneToDimmableLightCmd(const ScanValue_t *args);
static void processAddSceneToThermostatCmd(const ScanValue_t *args);
static void processGetSceneMembershipCmd(const ScanValue_t *args);
static void processMoveCmd(const ScanValue_t *args);
static void processMoveToLevelCmd(const ScanValue_t *args);
static void processOffWithEffectCmd(const ScanValue_t *args);
static void processOnWithRecallGlobalSceneCmd(const ScanValue_t *args);
static void processOnWithTimedOffCmd(const ScanValue_t *args);
static void processRecallSceneCmd(const ScanValue_t *args);
static void processRemoveAllScenesCmd(const ScanValue_t *args);
static void processRemoveSceneCmd(const ScanValue_t *args);
static void processStepCmd(const ScanValue_t *args);
static void processStopCmd(const ScanValue_t *args);
static void processStoreSceneCmd(const ScanValue_t *args);
static void processTriggerEffectCmd(const ScanValue_t *args);
static void processViewSceneCmd(const ScanValue_t *args);
static void processZoneInitiateNormalOperatingModeCommand(const ScanValue_t *args);
static void processZoneInitiateTestModeCommand(const ScanValue_t *args);
#if BDB_COMMANDS_IN_CONSOLE == 1
static void processSetbdbJoinUsesInstallCodeKey(const ScanValue_t *args);
#endif
#ifdef OTAU_SERVER
static void processImageNotifyCmd(const ScanValue_t *args);
#endif
// Color Control cluster commands
static void processMoveToHueCmd(const ScanValue_t *args);
static void processMoveHueCmd(const ScanValue_t *args);
static void processStepHueCmd(const ScanValue_t *args);
static void processMoveToSaturationCmd(const ScanValue_t *args);
static void processMoveSaturationCmd(const ScanValue_t *args);
static void processStepSaturationCmd(const ScanValue_t *args);
static void processMoveToHueAndSaturationCmd(const ScanValue_t *args);
static void processMoveToColorCmd(const ScanValue_t *args);
static void processMoveColorCmd(const ScanValue_t *args);
static void processStepColorCmd(const ScanValue_t *args);
static void processMoveToColorTemperatureCmd(const ScanValue_t *args);
static void processEnhancedMoveToHueCmd(const ScanValue_t *args);
static void processEnhancedMoveHueCmd(const ScanValue_t *args);
static void processEnhancedStepHueCmd(const ScanValue_t *args);
static void processEnhancedMoveToHueAndSaturationCmd(const ScanValue_t *args);
static void processColorLoopSetCmd(const ScanValue_t *args);
static void processStopMoveStepCmd(const ScanValue_t *args);
static void processMoveColorTemperatureCmd(const ScanValue_t *args);
static void processStepColorTemperatureCmd(const ScanValue_t *args);

//IAS Zone and ACE cluster
static void processACEGetPanelStatusChangedCommand(const ScanValue_t *args);
static void processACEGetZoneStatusChangedCommand(const ScanValue_t *args);
static void processInitiateZoneEnrollmentProc(const ScanValue_t *args);

//SCENES CLUSTER
static void processEnhancedAddSceneCmd(const ScanValue_t *args);
static void processEnhancedAddSceneToThermostatCmd(const ScanValue_t *args);
static void processCopySceneCmd(const ScanValue_t *args);
static void processEnhancedViewSceneCmd(const ScanValue_t *args);

// Touchlink Commissioning cluster
static void processSendEndpointInfoCmd(const ScanValue_t *args);
static void processGetGroupIdentifiersCmd(const ScanValue_t *args);
static void processGetEndpointListCmd(const ScanValue_t *args);

// Thermostat cluster command
static void processSetPointChange(const ScanValue_t *args);

//Time cluster
static void processSetTimeStatus(const ScanValue_t *args);

//Alarms Cluster
static void processResetAlarmCmd(const ScanValue_t *args);
static void processResetAllAlarmsCmd(const ScanValue_t *args);
static void processResetAlarmLogCmd(const ScanValue_t *args);
static void processGetAlarmCmd(const ScanValue_t *args);

#endif // ZCL_COMMANDS_IN_CONSOLE == 1

/******************************************************************************
                    Local variables section
******************************************************************************/
const ConsoleCommand_t helpCmds[] =
{
  {"help", "",processHelpCmd, "->Show help you're reading now:  help\r\n"},
#if ZDO_COMMANDS_IN_CONSOLE == 1
  {"zdoHelp", "",processZdoHelpCmd, ""},
#endif
#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
  {"commissioningHelp", "",processCommissioningHelpCmd, "->Show commissioning help you're reading now:  help\r\n"},
#endif  
#if ZCL_COMMANDS_IN_CONSOLE == 1
  {"zclHelp", "",processZclHelpCmd, "->Show zcl help you're reading now:  help\r\n"},
#endif
#if APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC
  {"zgpHelp", "",processZgpHelpCmd, ""},
#endif
   {0,0,0,0},
};

const ConsoleCommand_t commissioningHelpCmds[]=
{
#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
  {"invokeCommissioning", "dd", processInvokeCommissioningCmd, "-> invokes commissioning [mode: 1-Touchlink: 2-Steering: 4-Formation: 8-F&B][gid]Invoke one Commissioning method at a time\r\n"},
  {"getAppDeviceType", "", processGetAppDeviceTypeCmd, "-> Request for device type: getAppDeviceType\r\n"},
  {"getDeviceType", "", processGetDeviceTypeCmd, "-> Request for device type: getDeviceType\r\n"},
  {"getExtAddr", "", processGetExtAddrCmd, "-> Gets ExtAddr: GetExtAddr\r\n"},
  {"getNetworkAddress", "", processGetNetworkAddressCmd, "-> Returns network address: getNetworkAddress\r\n"},
  {"getChannel", "", processGetChannelCmd, "-> Returns current channel: getChannel\r\n"},
  {"setExtAddr", "dd",processSetExtAddr, "->Set Ext Address:[upper][lower]\r\n"},
  {"setPrimaryChannelMask", "d", processSetPrimaryChannelMaskCmd, "-> Sets primary channel mask: setPrimaryChannelMask [mask]\r\n"},
  {"setSecondaryChannelMask", "d", processSetSecondaryChannelMaskCmd, "-> Sets secondary channel mask: setSecondaryChannelMask [mask]\r\n"},
  {"powerOff", "", processPseudoPowerOffCmd, "-> Powers off device: powerOff\r\n"},
  {"reset", "", processResetCmd, "->Reset device\r\n"},
  {"resetToFN", "", processResetToFactoryFreshCmd, "->Reset to factory fresh settings: resetToFN\r\n"},
  {"setcca", "dd", processSetCCAModeAndThresholdCmd, "-> Sets CCA Mode and Threshold [cca mode] [threshold]\r\n"},
  {"getcca", "", processGetCCAModeAndThresholdCmd, "-> Gets CCA Mode and Threshold\r\n"},
#if BDB_COMMANDS_IN_CONSOLE == 1
  {"formAndSteer", "", processFormAndSteerCmd, "-> forms network and steers\r\n"},
  {"formSteerAndFB", "", processFormSteerAndFBCmd, "-> forms network ,steers and FB\r\n"},
  {"SetInstallCode", "dds", processSetInstallCodeCmd, "-> Sets IC [extAddr][code]\r\n"},
#ifndef ZAPPSI_HOST
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
  {"SetAllowRemoteTCpolicyChange", "d", processSetAllowRemoteTCpolicyChange, "-> Sets TCPolicy[enable/disable]\r\n"},
#endif
#endif
  {"SetInstallCodeDevice", "s", processSetInstallCodeDeviceCmd, "-> Sets IC [code]\r\n"},
#if BDB_TOUCHLINK_SUPPORT == 1
  {"setAllowTLResetToFN", "d", processSetAllowTLResetToFNCmd, "-> Sets setAllowTLResetToFN: 0 or 1 <type>\r\n"},
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
  {"SetTLRole", "d", processSetTLRole, "-> Sets TouchLink Role [initiator]\r\n"},
#endif
#endif
#if defined(_ROUTER_)
  {"setTCLKExchangeMethod", "d", processSetTCLKExchangeMethodCmd, "-> Sets TCLK Exchange Method [method]\r\n"},
  {"setTCLKMaxRetryAttempts", "d", processSetTCLKMaxRetryAttemptsCmd, "-> Sets TCLK Max Retry Attempts [attempt]\r\n"},
#endif /* #if defined(_ROUTER_) */
  {"setTCRequireKeyExchange", "d", processSetTrustCenterRequireKeyExchange, "-> Sets TrustCenterRequireKeyExchange: 0 or 1 [require]\r\n"},
#if ZB_COMMISSIONING_ON_STARTUP == 0
  {"SetFBRole", "d", processSetFBRole, "-> Sets FB Role [initiator]\r\n"},
#endif
  {"setGlobalKey", "d", processsetGlobalKeyCmd, "-> Sets Key for negative testing[Option]\r\n"},
  {"setPermitJoin", "d", processSetPermitJoinCmd, "-> Sets Permit Join: setPermitJoin [dur]\r\n"},
#endif
#endif
   {0,0,0,0},
};

const ConsoleCommand_t zclHelpCmds[]=
{
#if ZCL_COMMANDS_IN_CONSOLE == 1
  {"readAttribute", "sdddd", processReadAttrCmd, "->Read Attribute for specified cluster: readAttribute [addrMode][addr][ep][clusterId][attrId]\r\n"},
  {"readAttributeMultiple", "sddddd", processReadAttrMultipleCmd, "->Read Attribute Multiple for specified cluster: readAttributeMultiple [addrMode][addr][ep][clusterId][startAttrId][count]\r\n"},
  {"writeAttribute", "sddddddd", processWriteAttrCmd, "->Write Attribute for specified cluster: writeAttribute [addrMode][addr][ep][clusterId][attrId][type][attrValue][attrSize]\r\n"},
  {"writeAttributeNoResp", "sddddddd", processWriteAttrNoRespCmd, "->Write Attribute No response for specified cluster: writeAttributeNoResp [addrMode][addr][ep][clusterId][attrId][type][attrValue][attrSize]\r\n"},
  {"configureReporting", "sddddddd", processConfigureReportingCmd, "->Sends configure reporting to specified cluster server: configureReporting [addrMode][addr][ep][clusterId][attrId][type][min][max]\r\n"},
  {"configureReportingWRC", "sdddddddd", processConfigureReportingWithReportableChangeCmd, "->Sends configure reporting with reportable Change to specified cluster server: configureReportingWRC [addrMode][addr][ep][clusterId][attrId][type][min][max][repChange]\r\n"},
  {"readReporting", "sdddd", processReadReportingCmd, "->Sends Read reporting to specified cluster server: readReporting [addrMode][addr][ep][clusterId][attrId]\r\n"},
  {"addGroup", "sddd", processAddGroupCmd, "->Send Add Group command: addGroup [addrMode][addr][ep][gid]\r\n"},
  {"addGroupIfIdentifying", "sddd", processAddGroupIfIdentifyingCmd,  "->Send Add Group If Identifying command:addGroupIfIdentifying [addrMode][addr][ep][gid]\r\n"},
  {"getGroupMembership", "sdddddddd", processGetGroupMembershipCmd, "->Send Get Group Membership command: getGroupMembership [addrMode][addr][ep][count][gid]*5\r\n"},
  {"removeAllGroups", "sdd", processRemoveAllGroupsCmd,"->Send Remove All Group command: removeAllGroup[addrMode][addr][ep]\r\n"},
  {"removeGroup", "sddd", processRemoveGroupCmd, "->Send Remove Group command: removeGroup [addrMode][addr][ep][gid]\r\n"},
  {"viewGroup", "sddd", processViewGroupCmd, "->Send View Group command: viewGroup [addrMode][addr][ep][gid]\r\n"},
#if BDB_COMMANDS_IN_CONSOLE == 1
#if BDB_TOUCHLINK_SUPPORT == 1
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
  {"resetTargetToFN", "", processTargetToFnCmd, "Reset device to FN: resetDeviceToFN\r\n"},
#endif
  {"setTargetType", "d", processSetTargetTypeCmd, "-> Sets target type: setTargetType <type>\r\n"},
#endif
  {"SetbdbJoinUsesInstallCodeKey", "d", processSetbdbJoinUsesInstallCodeKey, "-> Sets bdbJoinUsesInstallCodeKey [value]\r\n"},
#endif
#if ZLO_EXTRA_CLUSTERS_SUPPORT == 1
  {"resetToFactoryDefaults", "sdd", processResetToFactoryDefaultsCmd, "-> reset all cluster attributes to factory defaults command:resetToFactoryDefaults [addrMode][addr][ep]\r\n"},
#endif // #if ZLO_EXTRA_CLUSTERS_SUPPORT == 1
  {"disableDefaultResp", "d",  processDisableDefaultResponseBitCmd, "->Disable/Enable default response for ZCL command: disableDefaultResp [value - 0 for enable or 1 for disable]\r\n"},
  {"addSceneToDL", "sddddddd", processAddSceneToDimmableLightCmd, "->Send Add Scene command to Dimmable Light: addScene [addrMode][addr][ep][groupId][sceneId][transitionTime][onOff][level]\r\n"},
  {"addSceneToTH", "sdddddddd", processAddSceneToThermostatCmd,  "->Send Add Scene command to Thermostat: addScene [addrMode][addr][ep][groupId][sceneId][transitionTime][occupiedCoolingSetpoint][occupiedHeatingSetpoint][systemMode]\r\n"},
  {"getSceneMembership", "sddd", processGetSceneMembershipCmd, "->Send Get Scene Membership command: getSceneMembership [addrMode][addr][ep][groupId]\r\n"},
  {"move", "sddddddd", processMoveCmd, "->Send Move (with On/Off) command: move [addrMode][addr][ep][mode][rate][onOff][optMask][optOvrd]\r\n"},
  {"moveToLevel", "sddddddd", processMoveToLevelCmd, "->Send Move To Level (with On/Off) command: moveToLevel [addrMode][addr][ep][level][transitionTime][onOff][optMask][optOvrd]\r\n"},
  {"offWithEffect", "sdddd", processOffWithEffectCmd, "->Send Off With Effect command: offWithEffect [addrMode][addr][ep][effectId][effectVariant]\r\n"},
  {"onWithRecallGlobalScene", "sdd", processOnWithRecallGlobalSceneCmd, "->Send On With Recall Global Scene command: onWithRecallGlobalScene [addrMode][addr][ep]\r\n"},
  {"onWithTimedOff", "sddddd", processOnWithTimedOffCmd, "->Send On With Timed off command: onWithTimedOff [addrMode][mode][ep][onOffCtrl][onTime][offWaitTime]\r\n"},
  {"recallScene", "sddddd", processRecallSceneCmd, "->Send Recall Scene command: recallScene [addrMode][addr][ep][groupId][sceneId][transitionTime]\r\n"},
  {"removeAllScenes", "sddd", processRemoveAllScenesCmd, "->Send Remove All Scenes command: removeAllScenes [addrMode][addr][ep][groupId]\r\n"},
  {"removeScene", "sdddd", processRemoveSceneCmd, "->Send Remove Scene command: removeScene [addrMode][addr][ep][groupId][sceneId]\r\n"},
  {"step", "sdddddddd", processStepCmd, "->Send Step (with On/Off) command: step [addrMode][addr][ep][mode][stepSize][transitionTime][onOff][optMask][optOvrd]\r\n"},
  {"stop", "sddddd", processStopCmd, "->Send Stop (with On/Off) command: stop [addrMode][addr][ep][onOff][optMask][optOvrd]\r\n"},
  {"storeScene", "sdddd", processStoreSceneCmd, "->Send Store Scene command: storeScene [addrMode][addr][ep][groupId][sceneId]\r\n"},
  {"triggerEffect", "sdddd", processTriggerEffectCmd, "->Send TriggerEffect command: triggerEffect [addrMode][addr][ep][effectId][effectVariant]"},
  {"viewScene", "sdddd", processViewSceneCmd, "->Send View Scene command: viewScene [addrMode][addr][ep][groupId][sceneId]\r\n"},
  {"onOff", "sdds", processOnOffToggleCmd, "Sends On/Off command: onOff [addrMode][addr][ep][onOff: -on for On, -off for Off]\r\n"},
  {"identify", "sddd", processIdentifyCmd, "->Send Identify command: identify [addrMode][addr][ep][idTime]\r\n"},
  {"identifyQuery", "sdd", processIdentifyQueryCmd, "->Send Identify Query command: identifyQuery [addrMode][addr][ep]\r\n"},
#ifdef OTAU_SERVER
  {"imageNotify", "dddddddd", processImageNotifyCmd, "Sends Image Notify cmd: imageNotify [ucastFlag] [dstEp] [shortAddress] [payloadType] [Qjitter][manuId][imageType] [fwVersion]\r\n"},
#endif
  // Color Control cluster commands
  {"moveToHue", "sddddddd", processMoveToHueCmd,"[addrMode][addr][ep][hue][direction][transitTime][optMask][optOvrd]\r\n"},
  {"moveHue", "sdddddd", processMoveHueCmd,"[addrMode][addr][ep][moveMode][rate][optMask][optOvrd]\r\n"},
  {"stepHue", "sddddddd", processStepHueCmd, "[addrMode][addr][ep][stepMode][stepSize][transitTime][optMask][optOvrd]\r\n"},
  {"moveToSaturation", "sdddddd", processMoveToSaturationCmd, "[addrMode][addr][ep][saturation][transitTime][optMask][optOvrd]\r\n"},
  {"moveSaturation", "sdddddd", processMoveSaturationCmd, "[addrMode][addr][ep][moveMode][rate][optMask][optOvrd]\r\n"},
  {"stepSaturation", "sddddddd", processStepSaturationCmd, "[addrMode][addr][ep][stepMode][stepSize][transitTime][optMask][optOvrd]\r\n"},
  {"moveToHueAndSaturation", "sddddddd",   processMoveToHueAndSaturationCmd, "[addrMode][addr][ep][hue][saturation][transitTime][optMask][optOvrd]\r\n"},
  {"moveToColor", "sddddddd", processMoveToColorCmd, "[addrMode][addr][ep][colorX][colorY][transitTime][optMask][optOvrd]\r\n"},
  {"moveColor", "sdddddd", processMoveColorCmd, "[addrMode][addr][ep][rateX][rateY][optMask][optOvrd]\r\n"},
  {"stepColor", "sddddddd", processStepColorCmd, "[addrMode][addr][ep][stepX][stepY][transitTime][optMask][optOvrd]\r\n"},
  {"moveToColorTemperature", "sdddddd", processMoveToColorTemperatureCmd, "[addrMode][addr][ep][colorTemp][transitTime][optMask][optOvrd]\r\n"},
  {"enhancedMoveToHue", "sddddddd", processEnhancedMoveToHueCmd, "[addrMode][addr][ep][enhancedHue][direction][transitTime][optMask][optOvrd]\r\n"},
  {"enhancedMoveHue", "sdddddd", processEnhancedMoveHueCmd, "[addrMode][addr][ep][moveMode][rate][optMask][optOvrd]\r\n"},
  {"enhancedStepHue", "sddddddd", processEnhancedStepHueCmd, "[addrMode][addr][ep][stepMode][stepSize][transitTime][optMask][optOvrd]\r\n"},
  {"enhancedMoveToHueAndSaturation", "sddddddd", processEnhancedMoveToHueAndSaturationCmd, "[addrMode][addr][ep][enhancedHue][saturation][transitTime][optMask][optOvrd]\r\n"},
  {"colorLoopSet", "sddddddddd", processColorLoopSetCmd, "[addrMode][addr][ep][updateFlags][action][direction][time][startHue][optMask][optOvrd]\r\n"},
  {"stopMoveStep", "sdddd",processStopMoveStepCmd, "[addrMode][addr][ep][optMask][optOvrd]\r\n"},
  {"moveColorTemperature", "sdddddddd", processMoveColorTemperatureCmd, "[addrMode][addr][ep][moveMode][rate][colorTempMin][colorTempMax][optMask][optOvrd]\r\n"},
  {"stepColorTemperature", "sddddddddd", processStepColorTemperatureCmd, "[addrMode][addr][ep][stepMode][stepSize][transitTime][colorTempMin][colorTempMax][optMask][optOvrd]\r\n"},
  {"enhancedAddScene", "sddddddddddddddd", processEnhancedAddSceneCmd, "[addrMode][addr][ep][group][scene][trTime][onOff][level][X][Y][enHue][sat][colorLoopActv][colorLoopDir][colorLoopTime][colorTemp]\r\n"},
  {"enhancedAddSceneToTH", "sdddddddd", processEnhancedAddSceneToThermostatCmd,  "[addrMode][addr][ep][groupId][sceneId][transitionTime][occupiedCoolingSetpoint][occupiedHeatingSetpoint][systemMode]\r\n"},
  {"copyScene", "sddddddd", processCopySceneCmd, "[addrMode][addr][ep][mode][groupFrom][sceneFrom][groupTo][sceneTo]\r\n"},
  {"enhancedViewScene", "sdddd", processEnhancedViewSceneCmd, "[addrMode][addr][ep][groupId][sceneId]\r\n"},
  // Commissioning cluster commands
  {"sendEndpointInfo", "dd"  , processSendEndpointInfoCmd, "->Send Endpoint Info command: sendEndpointInfo [shortAddr][ep]\r\n"},
  {"getGroupIdentifiers", "ddd" , processGetGroupIdentifiersCmd, "->Send getGroupsIdentifiers command: getGroupIdentifiers [shortAddr][ep][startIndex]\r\n"},
  {"getEndpointList", "ddd" , processGetEndpointListCmd, "->Send getEndpointList command: getGroupIdentifiers [shortAddr][ep][startIndex]\r\n"},
  {"setTimeStatus", "dddd", processSetTimeStatus, "-> setTimeStatus [master][synchronized][masterZoneDst][superseding]\r\n"},
  {"IasAceGetPanelStatusChangedCommand", "sdddddd",processACEGetPanelStatusChangedCommand,
    "->Panel StatusChanged Command Sent:[addrMode][addr][ep][panel_status][seconds_remaining][audible_noti][alarmstatus]\r\n"},
  {"IasAceZoneStatusChangedCommand", "sdddddd",processACEGetZoneStatusChangedCommand,
    "->Zone StatusChanged Command Sent:[addrMode][addr][ep][zoneId][zone_status][audible][zone_label]\r\n"},
  {"ZoneInitiateNormalOperatingModeCommand", "sdd",processZoneInitiateNormalOperatingModeCommand,
    "->Send ZoneInitiateNormalOperatingModeCommand:[addrMode][addr][ep]\r\n"},
  {"ZoneInitiateTestModeCommand", "sdddd",processZoneInitiateTestModeCommand,
    "->Send ZoneInitiateTestModeCommand:[addrMode][addr][ep][Test_Mode_Duration ][Current_Zone_Sensitivity Level]\r\n"},
   {"IasAceInitiateZoneEnrollment", "sddd", processInitiateZoneEnrollmentProc, "->Enrolment procedure update: [addrMode][addr][CieAttrValue][enrolmentType]\r\n"},
  // Thermostat cluster command
  {"setPointChange", "sdddd", processSetPointChange, "[addrMode][addr][ep][setpointmode][amount]\r\n"},
  // Alarm Cluster Commands
  {"resetAlarm", "sdddd", processResetAlarmCmd, "Sends Reset alarm command:  [addrMode][addr][ep][alarmId][clusterID]\r\n"},
  {"resetAllAlarms", "sdd", processResetAllAlarmsCmd, "Sends resetAllAlarms command: resetAllAlarms [addrMode][addr][ep]\r\n"},
  {"resetAlarmLog", "sdd", processResetAlarmLogCmd, "Sends resetAlarmLog command: resetAlarmLog [addrMode][addr][ep]\r\n"},
  {"getAlarm", "sdd", processGetAlarmCmd, "Sends get alarm command: getAlarm [addrMode][addr][ep]\r\n"},

#endif // #if ZCL_COMMANDS_IN_CONSOLE == 1
  {0,0,0,0},
};

/******************************************************************************
                   Global variables section
******************************************************************************/
bool fbRole = true;
ScanValue_t local;
Endpoint_t srcEp = APP_ENDPOINT_COMBINED_INTERFACE;

/******************************************************************************
                    Implementation section
******************************************************************************/
#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes request for HA evice type obtaining

\param[in] args - array of command arguments
******************************************************************************/
static void processGetAppDeviceTypeCmd(const ScanValue_t *args)
{
  appSnprintf("HADeviceType = 0x%04x\r\n", APP_Z3DEVICE_ID);
  (void)args;
}

/**************************************************************************//**
\brief Processes request for device type obtaining

\param[in] args - array of command arguments
******************************************************************************/
void processGetDeviceTypeCmd(const ScanValue_t *args)
{
  (void)args;
#if (APP_ZGP_DEVICE_TYPE == APP_ZGP_DEVICE_TYPE_COMBO_BASIC)
#if (APP_ENABLE_ZGP_CERTIFICATION_EXTENSION == 1)
  appSnprintf("DeviceType = %d\r\n", TEST_DEVICE_TYPE_ZGP_TH);
#else
  appSnprintf("DeviceType = %d\r\n", TEST_DEVICE_TYPE_ZGP_COMBO_BASIC);
#endif
#else
#if (APP_Z3_DEVICE_TYPE == APP_DEVICE_TYPE_COMBINED_INTERFACE)
#ifdef COMBINED_INTERFACE_ROUTER
  appSnprintf("DeviceType = %d\r\n", TEST_DEVICE_TYPE_ZIGBEE_ROUTER);
#else
  appSnprintf("DeviceType = %d\r\n", TEST_DEVICE_TYPE_ZIGBEE_COORDINATOR);
#endif
#else
  appSnprintf("DeviceType = %d\r\n", TEST_DEVICE_TYPE_ZIGBEE_ROUTER);
#endif
#endif
}

#if BDB_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief InstallCode callback

\param[in] status - status of action
******************************************************************************/
void myICCallback(InstallCode_Configuration_Status_t status)
{
  appSnprintf( "Status = %d\r\n", status);
}

/**************************************************************************//**
\brief Processes InstallCode command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetInstallCodeCmd(const ScanValue_t *args)
{
  uint8_t icode[18];
  ExtAddr_t extAddr = ((uint64_t)args[0].uint32 << 32);
  extAddr |= args[1].uint32;
  hexStrTouint8array(args[2].str, icode, 18U);
  BDB_ConfigureInstallCode(extAddr, icode, myICCallback);
  (void)args;
}
#ifndef ZAPPSI_HOST
#if defined (_LINK_SECURITY_) && defined (_TRUST_CENTRE_)
/**************************************************************************//**
\brief Processes setAllowRemoteTCPolicyChange command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetAllowRemoteTCpolicyChange(const ScanValue_t *args)
{
  TC_SetAllowRemoteTCPolicyChange(args[0].uint8);
  (void)args;
}
#endif
#endif
/**************************************************************************//**
\brief Processes InstallCode command

\param[in] args - array of command arguments
******************************************************************************/
void processSetInstallCodeDeviceCmd(const ScanValue_t *args)
{
  ExtAddr_t devAddr = 0xFFFFFFFFFFFFFFFF;
  uint8_t icode[18];
  hexStrTouint8array(args[0].str, icode, 18U);
  BDB_ConfigureInstallCode(devAddr, icode, myICCallback);
  (void)args;
}

/**************************************************************************//**
\brief Processes SetTCRequireKeyExchange command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetTrustCenterRequireKeyExchange(const ScanValue_t *args)
{
  BDB_SetTCRequireKeyExchange((bool) args[0].uint8);
}
#endif
#endif

#if ZCL_COMMANDS_IN_CONSOLE == 1

#if BDB_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes bdbJoinUses InstallCode command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetbdbJoinUsesInstallCodeKey(const ScanValue_t *args)
{
  BDB_SetInstallCodeUsage(args[0].uint8);
  (void)args;
}
#endif // #if BDB_COMMANDS_IN_CONSOLE == 1
/**************************************************************************//**
\brief Processes Add group command

\param[in] args - array of command arguments
******************************************************************************/
static void processAddGroupCmd(const ScanValue_t *args)
{
  groupsSendAddGroup(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16);
}

/**************************************************************************//**
\brief Processes View group command

\param[in] args - array of command arguments
******************************************************************************/
static void processViewGroupCmd(const ScanValue_t *args)
{
  groupsSendViewGroup(determineAddressMode(args), args[1].uint16, args[2].uint8,
   srcEp,args[3].uint16);
}

/**************************************************************************//**
\brief Processes Get group membership command

\param[in] args - array of command arguments
******************************************************************************/
static void processGetGroupMembershipCmd(const ScanValue_t *args)
{
  uint16_t groupList[5];

  for (uint8_t i = 0; i < 5; i++)
    groupList[i] = args[i+4].uint16;

  groupsSendGetGroupMembership(determineAddressMode(args), args[1].uint16, args[2].uint8,
   srcEp, args[3].uint8, groupList);
}

/**************************************************************************//**
\brief Processes Remove group command

\param[in] args - array of command arguments
******************************************************************************/
static void processRemoveGroupCmd(const ScanValue_t *args)
{
  groupsSendRemoveGroup(determineAddressMode(args), args[1].uint16, args[2].uint8,srcEp,
    args[3].uint16);
}

/**************************************************************************//**
\brief Processes Remove all groups command

\param[in] args - array of command arguments
******************************************************************************/
static void processRemoveAllGroupsCmd(const ScanValue_t *args)
{
  (void)args;
  groupsSendRemoveAllGroups(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

/**************************************************************************//**
\brief Processes Add group if identifying command

\param[in] args - array of command arguments
******************************************************************************/
static void processAddGroupIfIdentifyingCmd(const ScanValue_t *args)
{
  groupsSendAddGroupIfIdentifying(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16);
}

/*****************************************************************************/
//                      BASIC CLUSTER COMMANDS
/*****************************************************************************/
#if ZLO_EXTRA_CLUSTERS_SUPPORT == 1

/**************************************************************************//**
\brief Processes reset To factory defaults command

\param[in] args - array of command arguments
******************************************************************************/
static void processResetToFactoryDefaultsCmd(const ScanValue_t *args)
{
  basicResetToFactoryDefaultsCommand(determineAddressMode(args), args[1].uint16,
    args[2].uint8, srcEp);
}

#endif // #if ZLO_EXTRA_CLUSTERS_SUPPORT == 1

/**************************************************************************//**
\brief Processes Move to level command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveToLevelCmd(const ScanValue_t *args)
{
  levelControlSendMoveToLevel(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint16, args[5].uint8, args[6].uint8, args[7].uint8);
}

/**************************************************************************//**
\brief Processes Off with Effect command

\param[in] args - array of command arguments
******************************************************************************/
static void processOffWithEffectCmd(const ScanValue_t *args)
{
  onOffSendOffWithEffect(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint8);
}

/**************************************************************************//**
\brief Processes On with recall global scene command

\param[in] args - array of command arguments
******************************************************************************/
static void processOnWithRecallGlobalSceneCmd(const ScanValue_t *args)
{
  onOffSendOnWithRecallGlobalScene(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

/**************************************************************************//**
\brief Processes On with timed off command

\param[in] args - array of command arguments
******************************************************************************/
static void processOnWithTimedOffCmd(const ScanValue_t *args)
{
  onOffSendOnWithTimedOff(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint16, args[5].uint16);
}

/**************************************************************************//**
\brief Processes Move command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveCmd(const ScanValue_t *args)
{
  levelControlSendMove(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint8, args[5].uint8, args[6].uint8, args[7].uint8);
}

/**************************************************************************//**
\brief Processes Step command

\param[in] args - array of command arguments
******************************************************************************/
static void processStepCmd(const ScanValue_t *args)
{
  levelControlSendStep(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint8, args[5].uint16, args[6].uint8, args[7].uint8, args[8].uint8);
}

/**************************************************************************//**
\brief Processes Stop command

\param[in] args - array of command arguments
******************************************************************************/
static void processStopCmd(const ScanValue_t *args)
{
  levelControlSendStop(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint8, args[5].uint8);
}

/**************************************************************************//**
\brief Processes Add Scene command to DL

\param[in] args - array of command arguments
******************************************************************************/
static void processAddSceneToDimmableLightCmd(const ScanValue_t *args)
{
  scenesSendAddSceneToDimmableLight(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16, args[4].uint8, args[5].uint16, args[6].uint8, args[7].uint8);
}

/**************************************************************************//**
\brief Processes Add Scene command to Thermostat

\param[in] args - array of command arguments
******************************************************************************/
static void processAddSceneToThermostatCmd(const ScanValue_t *args)
{
  scenesSendAddSceneToThermotstat(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16, args[4].uint8, args[5].uint16, args[6].int16, args[7].int16, args[8].uint8 );
}

/**************************************************************************//**
\brief Processes View Scene command

\param[in] args - array of command arguments
******************************************************************************/
static void processViewSceneCmd(const ScanValue_t *args)
{
  scenesSendViewScene(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16, args[4].uint8);
}

/**************************************************************************//**
\brief Processes Zone Initiate Normal Operating Mode Command

\param[in] args - array of command arguments
******************************************************************************/
static void processZoneInitiateNormalOperatingModeCommand(const ScanValue_t *args)
{
  zoneInitiateNormalOperatingModeCommand(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

/**************************************************************************//**
\brief Processes Zone Initiate Test Mode Command

\param[in] args - array of command arguments
******************************************************************************/
static void processZoneInitiateTestModeCommand(const ScanValue_t *args)
{
  zoneInitiateTestModeCommand(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, args[3].uint8, args[4].uint8);
}

/**************************************************************************//**
\brief Cmd to initiate Enrolment Procedure from Server

\param[in] arg - pointer to command argument with address mode string

\returns none
******************************************************************************/
static void processInitiateZoneEnrollmentProc(const ScanValue_t *args)
{
  aceZoneEnrollmentProcInitiateCmd(determineAddressMode(args), args[1].uint16, srcEp, (void *)&args[2].uint8, args[3].uint8);
}

/**************************************************************************//**
\brief Processes Remove group command

\param[in] args - array of command arguments
******************************************************************************/
static void processRemoveSceneCmd(const ScanValue_t *args)
{
  scenesSendRemoveScene(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16, args[4].uint8);
}

/**************************************************************************//**
\brief Processes Remove all scenes command

\param[in] args - array of command arguments
******************************************************************************/
static void processRemoveAllScenesCmd(const ScanValue_t *args)
{
  scenesSendRemoveAllScenes(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16);
}

/**************************************************************************//**
\brief Processes Store scene command

\param[in] args - array of command arguments
******************************************************************************/
static void processStoreSceneCmd(const ScanValue_t *args)
{
  scenesSendStoreScene(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16, args[4].uint8);
}

/**************************************************************************//**
\brief Processes Recall scene command

\param[in] args - array of command arguments
******************************************************************************/
static void processRecallSceneCmd(const ScanValue_t *args)
{
  scenesSendRecallScene(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16, args[4].uint8, args[5].uint16);
}

/**************************************************************************//**
\brief Processes Get scene membership command

\param[in] args - array of command arguments
******************************************************************************/
static void processGetSceneMembershipCmd(const ScanValue_t *args)
{
  scenesSendGetSceneMembership(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16);
}

/**************************************************************************//**
\brief Processes Trigger Effect command

\param[in] args - array of command arguments
******************************************************************************/
static void processTriggerEffectCmd(const ScanValue_t *args)
{
  identifySendTriggerEffect(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint8);
}

/**************************************************************************//**
\brief Processes Identify command

\param[in] args - array of command arguments
******************************************************************************/
static void processIdentifyCmd(const ScanValue_t *args)
{
  identifySendIdentify(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint16);
}

/**************************************************************************//**
\brief Processes Identify Query command

\param[in] args - array of command arguments
******************************************************************************/
static void processIdentifyQueryCmd(const ScanValue_t *args)
{
  identifySendIdentifyQuery(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

/**************************************************************************//**
\brief Processes On/Off/Toggle command

\param[in] args - array of command arguments
******************************************************************************/
static void processOnOffToggleCmd(const ScanValue_t *args)
{
  uint8_t command;

  if (!memcmp("-on", args[3].str, 3))
    command = 1;
  else if (!memcmp("-toggle", args[3].str, 7))
    command = 2;
  else
    command = 0;

  onOffSendOnOffToggle(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp, (OnOffToggle_t)command);
}

#ifdef OTAU_SERVER
/**************************************************************************//**
\brief Processes image notify command

\param[in] args - array of command arguments
******************************************************************************/
static void processImageNotifyCmd(const ScanValue_t *args)
{
  bool isUcast = args[0].uint8?true:false;
  ZCL_OtauImageNotify_t imgNtfy;
  ZCL_Addressing_t addr =
  {
  .addrMode             = APS_SHORT_ADDRESS,
  .profileId            = APP_PROFILE_ID,
  .clusterId            = OTAU_CLUSTER_ID,
  .clusterSide          = ZCL_CLIENT_CLUSTER_TYPE,
  .manufacturerSpecCode = 0,
  };

  addr.addr.shortAddress    = isUcast?args[2].uint16:BROADCAST_ADDR_ALL;
  addr.sequenceNumber       = ZCL_GetNextSeqNumber();
  addr.endpointId           = args[1].uint16;

  imgNtfy.payloadType       = args[3].uint8;
  imgNtfy.queryJitter       = args[4].uint8;
  imgNtfy.manufacturerCode  = args[5].uint16;
  imgNtfy.imageType         = args[6].uint16;
  imgNtfy.newFileVersion    = args[7].uint32;

  ZCL_ImageNotifyReq(&addr, &imgNtfy);

  (void)args;
}
#endif

/**************************************************************************//**
\brief Processes Color Control: MoveToHue command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveToHueCmd(const ScanValue_t *args)
{
  colorControlSendMoveToHueCommand(determineAddressMode(args),
                                     args[1].uint16,
                                     args[2].uint8,
                                     /* Payload arguments */
                                     srcEp,
                                     args[3].uint8,
                                     args[4].uint8,
                                     args[5].uint16,
                                     args[6].uint8,
                                     args[7].uint8
                                    );
}

/**************************************************************************//**
\brief Processes Color Control: MoveHue command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveHueCmd(const ScanValue_t *args)
{
  colorControlSendMoveHueCommand(determineAddressMode(args),
                                   args[1].uint16,
                                   args[2].uint8,
                                   srcEp,
                                     /* Payload arguments */
                                   args[3].uint8,
                                   args[4].uint8,
                                   args[5].uint8,
                                   args[6].uint8
                                  );
}

/**************************************************************************//**
\brief Processes Color Control: StepHue command

\param[in] args - array of command arguments
******************************************************************************/
static void processStepHueCmd(const ScanValue_t *args)
{
  colorControlSendStepHueCommand(determineAddressMode(args),
                                   args[1].uint16,
                                   args[2].uint8,
                                   srcEp,
                                     /* Payload arguments */
                                   args[3].uint8,
                                   args[4].uint8,
                                   args[5].uint8,
                                   args[6].uint8,
                                   args[7].uint8
                                  );
}

/**************************************************************************//**
\brief Processes Color Control: MoveToSaturation command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveToSaturationCmd(const ScanValue_t *args)
{
  colorControlSendMoveToSaturationCommand(determineAddressMode(args),
                                            args[1].uint16,
                                            args[2].uint8,
                                            srcEp,
                                     /* Payload arguments */
                                            args[3].uint8,
                                            args[4].uint16,
                                            args[5].uint8, 
                                            args[6].uint8
                                           );
}

/**************************************************************************//**
\brief Processes Color Control: MoveSaturation command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveSaturationCmd(const ScanValue_t *args)
{
  colorControlSendMoveSaturationCommand(determineAddressMode(args),
                                          args[1].uint16,
                                          args[2].uint8,
                                          srcEp,
                                     /* Payload arguments */
                                          args[3].uint8,
                                          args[4].uint8,
                                          args[5].uint8,
                                          args[6].uint8
                                         );
}

/**************************************************************************//**
\brief Processes Color Control: StepSaturation command

\param[in] args - array of command arguments
******************************************************************************/
static void processStepSaturationCmd(const ScanValue_t *args)
{
  colorControlSendStepSaturationCommand(determineAddressMode(args),
                                          args[1].uint16,
                                          args[2].uint8,
                                          srcEp,
                                     /* Payload arguments */
                                          args[3].uint8,
                                          args[4].uint8,
                                          args[5].uint16,
                                          args[6].uint8,
                                          args[7].uint8
                                         );
}

/**************************************************************************//**
\brief Processes Color Control: MoveToHueAndSaturation command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveToHueAndSaturationCmd(const ScanValue_t *args)
{
  colorControlSendMoveToHueAndSaturationCommand(determineAddressMode(args),
                                                  args[1].uint16,
                                                  args[2].uint8,
                                                  srcEp,
                                     /* Payload arguments */
                                                  args[3].uint8,
                                                  args[4].uint8,
                                                  args[5].uint16,
                                                  args[6].uint8,
                                                  args[7].uint8
                                                 );
}

/**************************************************************************//**
\brief Processes Color Control: MoveToColor command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveToColorCmd(const ScanValue_t *args)
{
  colorControlSendMoveToColorCommand(determineAddressMode(args),
                                       args[1].uint16,
                                       args[2].uint8,
                                       srcEp,
                                     /* Payload arguments */
                                       args[3].uint16,
                                       args[4].uint16,
                                       args[5].uint16,
                                       args[6].uint8, 
                                       args[7].uint8
                                      );
}

/**************************************************************************//**
\brief Processes Color Control: MoveColor command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveColorCmd(const ScanValue_t *args)
{
  colorControlSendMoveColorCommand(determineAddressMode(args),
                                     args[1].uint16,
                                     args[2].uint8,
                                     srcEp,
                                     /* Payload arguments */
                                     args[3].int16,
                                     args[4].int16,
                                     args[5].uint8,
                                     args[6].uint8
                                    );
}

/**************************************************************************//**
\brief Processes Color Control: StepColor command

\param[in] args - array of command arguments
******************************************************************************/
static void processStepColorCmd(const ScanValue_t *args)
{
  colorControlSendStepColorCommand(determineAddressMode(args),
                                     args[1].uint16,
                                     args[2].uint8,
                                     srcEp,
                                     /* Payload arguments */
                                     args[3].int16,
                                     args[4].int16,
                                     args[5].int16,
                                     args[6].uint8,
                                     args[7].uint8
                                    );
}

/**************************************************************************//**
\brief Processes Color Control: MoveToColorTemperature command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveToColorTemperatureCmd(const ScanValue_t *args)
{
  colorControlSendMoveToColorTemperatureCommand(determineAddressMode(args),
                                                  args[1].uint16,
                                                  args[2].uint8,
                                                  srcEp,
                                                  /* Payload arguments */
                                                  args[3].uint16,
                                                  args[4].uint16,
                                                  args[5].uint8,
                                                  args[6].uint8
                                                 );
}

/**************************************************************************//**
\brief Processes Color Control: EnhancedMoveToHue command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedMoveToHueCmd(const ScanValue_t *args)
{
  colorControlSendEnhancedMoveToHueCommand(determineAddressMode(args),
                                             args[1].uint16,
                                             args[2].uint8,
                                             srcEp,
                                             /* Payload arguments */
                                             args[3].uint16,
                                             args[4].uint8,
                                             args[5].uint16,
                                             args[6].uint8,
                                             args[7].uint8
                                            );
}

/**************************************************************************//**
\brief Processes Color Control: EnhancedMoveHue command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedMoveHueCmd(const ScanValue_t *args)
{
  colorControlSendEnhancedMoveHueCommand(determineAddressMode(args),
                                           args[1].uint16,
                                           args[2].uint8,
                                           srcEp,
                                           /* Payload arguments */
                                           args[3].uint8,
                                           args[4].uint16,
                                           args[5].uint8, 
                                           args[6].uint8
                                          );
}

/**************************************************************************//**
\brief Processes Color Control: EnhancedStepHue command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedStepHueCmd(const ScanValue_t *args)
{
  colorControlSendEnhancedStepHueCommand(determineAddressMode(args),
                                           args[1].uint16,
                                           args[2].uint8,
                                           srcEp,
                                           /* Payload arguments */
                                           args[3].uint8,
                                           args[4].uint16,
                                           args[5].uint16,
                                           args[6].uint8,
                                           args[7].uint8
                                          );
}

/**************************************************************************//**
\brief Processes Color Control: EnhancedMoveToHueAndSaturation command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedMoveToHueAndSaturationCmd(const ScanValue_t *args)
{
  colorControlSendEnhancedMoveToHueAndSaturationCommand(determineAddressMode(args),
                                                          args[1].uint16,
                                                          args[2].uint8,
                                                          srcEp,
                                                          /* Payload arguments */
                                                          args[3].uint16,
                                                          args[4].uint8,
                                                          args[5].uint16,
                                                          args[6].uint8,
                                                          args[7].uint8
                                                         );
}

/**************************************************************************//**
\brief Processes Color Control: ColorLoopSet command

\param[in] args - array of command arguments
******************************************************************************/
static void processColorLoopSetCmd(const ScanValue_t *args)
{
  colorControlSendColorLoopSetCommand(determineAddressMode(args),
                                        args[1].uint16,
                                        args[2].uint8,
                                        srcEp,
                                        /* Payload arguments */
                                        args[3].uint8,
                                        args[4].uint8,
                                        args[5].uint8,
                                        args[6].uint16,
                                        args[7].uint16,
                                        args[8].uint8,
                                        args[9].uint8
                                       );
}

/**************************************************************************//**
\brief Processes Color Control: StopMoveStep command

\param[in] args - array of command arguments
******************************************************************************/
static void processStopMoveStepCmd(const ScanValue_t *args)
{
  colorControlSendStopMoveStepCommand(determineAddressMode(args),
                                        args[1].uint16,
                                        args[2].uint8,
                                        srcEp,
                                        args[3].uint8,
                                        args[4].uint8
                                       );
}

/**************************************************************************//**
\brief Processes Color Control: MoveColorTemperature command

\param[in] args - array of command arguments
******************************************************************************/
static void processMoveColorTemperatureCmd(const ScanValue_t *args)
{
  colorControlSendMoveColorTemperatureCommand(determineAddressMode(args),
                                                args[1].uint16,
                                                args[2].uint8,
                                                srcEp,
                                                /* Payload arguments */
                                                args[3].uint8,
                                                args[4].uint16,
                                                args[5].uint16,
                                                args[6].uint16,
                                                args[7].uint8,
                                                args[8].uint8
                                               );
}

/**************************************************************************//**
\brief Processes Color Control: StepColorTemperature command

\param[in] args - array of command arguments
******************************************************************************/
static void processStepColorTemperatureCmd(const ScanValue_t *args)
{
  colorControlSendStepColorTemperatureCommand(determineAddressMode(args),
                                                args[1].uint16,
                                                args[2].uint8,
                                                srcEp,
                                                /* Payload arguments */
                                                args[3].uint8,
                                                args[4].uint16,
                                                args[5].uint16,
                                                args[6].uint16,
                                                args[7].uint16,
                                                args[8].uint8,
                                                args[9].uint8
                                               );
}

/**************************************************************************//**
\brief Processes sendEndpointInfo command

\param[in] args - array of command arguments
******************************************************************************/
static void processSendEndpointInfoCmd(const ScanValue_t *args)
{
  commissioningSendEndpointInformation(args[0].uint16, /* dst short address */
                                         args[1].uint8, srcEp  /* dst endpoint */
                                        );
}

/**************************************************************************//**
\brief Processes getGroupIdentifiers command

\param[in] args - array of command arguments
******************************************************************************/
static void processGetGroupIdentifiersCmd(const ScanValue_t *args)
{
  commissioningSendGetGroupIdentifiers(args[0].uint16, /* dst short address */
                                         args[1].uint8, srcEp,  /* dst endpoint */
                                         args[2].uint8   /* start index */
                                        );
}

/**************************************************************************//**
\brief Processes getEndpointList command

\param[in] args - array of command arguments
******************************************************************************/
static void processGetEndpointListCmd(const ScanValue_t *args)
{
  commissioningGetEndpointList(args[0].uint16, /* dst short address */
                                 args[1].uint8, srcEp,  /* dst endpoint */
                                 args[2].uint8   /* start index */
                                );
}

/**************************************************************************//**
\brief Processes EnhancedViewScene command

\param[in] args - array of command arguments
******************************************************************************/
static void processSetPointChange(const ScanValue_t *args)
{
  ciSendSetpointRaiseLowerCommand(determineAddressMode(args), args[1].uint16, args[2].uint8,
    srcEp, args[3].int8, args[4].int8);
}

/**************************************************************************//**
\brief Processes ACE Get Panel Status Change Command

\param[in] args - array of command arguments
******************************************************************************/
static void processACEGetPanelStatusChangedCommand(const ScanValue_t *args)
{
    acePanelStatusChangedCommand(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    (ZCL_PanelStatus_t)args[3].uint8, args[4].uint8, (ZCL_AudibleNotification_t)args[5].uint8, (ZCL_AlarmStatus_t)args[6].uint8);
}

/**************************************************************************//**
\brief Processes ACE Get Zone Status Change Command

\param[in] args - array of command arguments
******************************************************************************/
static void processACEGetZoneStatusChangedCommand(const ScanValue_t *args)
{
    aceZoneStatusChangedCommand(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp,
    args[3].uint8, args[4].uint8, (ZCL_AudibleNotification_t)args[5].uint8, args[6].str);  
}

/**************************************************************************//**
\brief Processes EnhancedAddScene command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedAddSceneCmd(const ScanValue_t *args)
{
  ZCL_ColorControlClusterExtensionFieldSet_t ccExt;

  ccExt.currentX           = args[8].uint16;
  ccExt.currentY           = args[9].uint16;
  ccExt.enhancedCurrentHue = args[10].uint16;
  ccExt.currentSaturation  = args[11].uint8;
  ccExt.colorLoopActive    = args[12].uint8;
  ccExt.colorLoopDirection = args[13].uint8;
  ccExt.colorLoopTime      = args[14].uint16;
  ccExt.colorTemperature   = args[15].uint16;

  scenesSendEnhancedAddSceneToExtendedColorLightWithExtFields(
    determineAddressMode(args),
    args[1].uint16, //  addr
    args[2].uint8,  //  destination endpoint
    srcEp,          //  source endpoint
    args[3].uint16, //  groupId
    args[4].uint16, //  sceneId
    args[5].uint16, //  transitionTime
    args[6].uint8,  //  onOff
    args[7].uint8,  //  level
    &ccExt
  );
}

/**************************************************************************//**
\brief Processes EnhancedAddSceneToThermostat command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedAddSceneToThermostatCmd(const ScanValue_t *args)
{
    scenesSendEnhancedAddSceneToThermostat(
    determineAddressMode(args),
    args[1].uint16,
    args[2].uint8,
    srcEp,
    args[3].uint16,
    args[4].uint16,
    args[5].uint16,
    args[6].int16,
    args[7].int16,
    args[8].uint8
    );
}
/**************************************************************************//**
\brief Processes copy scene command

\param[in] args - array of command arguments
******************************************************************************/
static void processCopySceneCmd(const ScanValue_t *args)
{
    SceneMode_t mode = {.copyAllScenes =args[3].uint8,
                        .reserved = 0};
    scenesSendCopyScene(determineAddressMode(args), args[1].uint16, args[2].uint8,
    srcEp, mode, args[4].uint16, args[5].uint16, args[6].uint16, args[7].uint16);

}


/**************************************************************************//**
\brief Processes EnhancedViewScene command

\param[in] args - array of command arguments
******************************************************************************/
static void processEnhancedViewSceneCmd(const ScanValue_t *args)
{
  scenesSendEnhancedViewScene(determineAddressMode(args), args[1].uint16, args[2].uint8,
    srcEp, args[3].uint16, args[4].uint16);
}
/**************************************************************************//**
\brief Process set time status bits

\param[in] args - array of command arguments
******************************************************************************/
static void processSetTimeStatus(const ScanValue_t *args)
{
  timeSetTimeStatus(args[0].uint8, args[1].uint8, args[2].uint8, args[3].uint8);
}

/**************************************************************************//**
\brief Processes processResetAlarmCmd command

\param[in] args - array of command arguments
******************************************************************************/
static void processResetAlarmCmd(const ScanValue_t *args)
{
  alarmsSendResetAlarm(determineAddressMode(args), args[1].uint16, args[2].uint8,
    srcEp, args[3].uint16, args[4].uint16);
}

/**************************************************************************//**
\brief Processes processResetAllAlarmsCmd command

\param[in] args - array of command arguments
******************************************************************************/
static void processResetAllAlarmsCmd(const ScanValue_t *args)
{
  alarmsSendResetAllAlarms(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

/**************************************************************************//**
\brief Processes processResetAlarmLogCmd command

\param[in] args - array of command arguments
******************************************************************************/
static void processResetAlarmLogCmd(const ScanValue_t *args)
{
  alarmsSendResetAlarmLog(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

/**************************************************************************//**
\brief Processes processGetAlarmCmd command

\param[in] args - array of command arguments
******************************************************************************/
static void processGetAlarmCmd(const ScanValue_t *args)
{
  alarmsSendGetAlarm(determineAddressMode(args), args[1].uint16, args[2].uint8, srcEp);
}

#endif // #if ZCL_COMMANDS_IN_CONSOLE == 1

#endif // APP_ENABLE_CONSOLE == 1

#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE

// eof cbConsole.c
