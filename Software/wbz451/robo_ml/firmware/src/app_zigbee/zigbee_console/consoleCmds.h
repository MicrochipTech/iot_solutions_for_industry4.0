/*******************************************************************************
  Application Console Commands Header file

  Company:
    Microchip Technology Inc.

  File Name:
    consoleCmds.h

  Summary:
    This file contains the Serial interface console interface.

  Description:
    This file contains the Serial interface console interface.
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

#if APP_ENABLE_CONSOLE == 1
/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/common/include/appConsts.h>
#include <z3device/clusters/include/haClusters.h>
#include <app_zigbee/zigbee_console/console.h>
#include <bdb/include/bdb.h>
#ifdef ZAPPSI_HOST
#include <zsiHalSerialization.h>
#endif
/******************************************************************************
                        Typedefs section
******************************************************************************/

/******************************************************************************
                    Prototypes section
******************************************************************************/
APS_AddrMode_t determineAddressMode(const ScanValue_t *arg);
void processHelpCmd(const ScanValue_t *args);
void helpCmdHandlingTimerFired(void);
void processZdoHelpCmd(const ScanValue_t *args);
void processCommissioningHelpCmd(const ScanValue_t *args);
void processZclHelpCmd(const ScanValue_t *args);
#if APP_ZGP_DEVICE_TYPE >= APP_ZGP_DEVICE_TYPE_PROXY_BASIC
void processZgpHelpCmd(const ScanValue_t *args);
#endif
#ifdef OTAU_CLIENT
void processOtauHelpCmd(const ScanValue_t *args);
#endif
#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
#if BDB_COMMANDS_IN_CONSOLE == 1
#if ZB_COMMISSIONING_ON_STARTUP == 0
void processSetFBRole(const ScanValue_t *args);
#endif
void processSetTCLKExchangeMethodCmd(const ScanValue_t *args);
void processSetTCLKMaxRetryAttemptsCmd(const ScanValue_t *args);
void processSetAllowStealCmd(const ScanValue_t *args);
void processsetGlobalKeyCmd(const ScanValue_t *args);
void processSetPermitJoinCmd(const ScanValue_t *args);
#if BDB_TOUCHLINK_SUPPORT == 1
void processSetAllowTLResetToFNCmd(const ScanValue_t *args);
#endif // #if BDB_TOUCHLINK_SUPPORT == 1
#endif // #if BDB_COMMANDS_IN_CONSOLE == 1
#endif // #if COMMISSIONING_COMMANDS_IN_CONSOLE == 1

#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
void processInvokeCommissioningCmd(const ScanValue_t *args);
void processFormAndSteerCmd(const ScanValue_t *args);
void processFormSteerAndFBCmd(const ScanValue_t *args);
void processGetExtAddrCmd(const ScanValue_t *args);
void processGetNetworkAddressCmd(const ScanValue_t *args);
void processGetChannelCmd(const ScanValue_t *args);
void processPseudoPowerOffCmd(const ScanValue_t *args);
void processResetCmd(const ScanValue_t *args);
void processResetToFactoryFreshCmd(const ScanValue_t *args);
void processSetExtAddr(const ScanValue_t *args);
void processSetPrimaryChannelMaskCmd(const ScanValue_t *args);
void processSetSecondaryChannelMaskCmd(const ScanValue_t *args);
void processSetCCAModeAndThresholdCmd(const ScanValue_t *args);
void processGetCCAModeAndThresholdCmd(const ScanValue_t *args);
#if BDB_COMMANDS_IN_CONSOLE == 1
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
void processSetTLRole(const ScanValue_t *args);
#endif // #if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
#endif // #if BDB_COMMANDS_IN_CONSOLE == 1
#endif //#if COMMISSIONING_COMMANDS_IN_CONSOLE == 1
#ifdef OTAU_CLIENT
void processSetOtauQueryInterval(const ScanValue_t *args);
void processSetMinBlockPeriod(const ScanValue_t *args);
void processGetFirmwareVersion(const ScanValue_t *args);
void processGetImageUpgradeStatus(const ScanValue_t *args);
#endif
#if ZCL_COMMANDS_IN_CONSOLE == 1
// General attribute-manipulation commands
void processReadAttrCmd(const ScanValue_t *args);
void processReadAttrMultipleCmd(const ScanValue_t *args);
void processWriteAttrCmd(const ScanValue_t *args);
void processWriteAttrNoRespCmd(const ScanValue_t *args);
void processConfigureReportingCmd(const ScanValue_t *args);
void processStartReportingCmd(const ScanValue_t *args);
void processConfigureReportingWithReportableChangeCmd(const ScanValue_t *args);
void processReadReportingCmd(const ScanValue_t *args);
void processDisableDefaultResponseBitCmd(const ScanValue_t *args);
#if BDB_COMMANDS_IN_CONSOLE == 1
#if BDB_TOUCHLINK_SUPPORT == 1
#if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
void processTargetToFnCmd(const ScanValue_t *args);
#endif // #if BDB_TOUCHLINK_INITIATOR_SUPPORT == 1
void processSetTargetTypeCmd(const ScanValue_t *args);
#endif // #if BDB_TOUCHLINK_SUPPORT == 1
#endif // #if BDB_COMMANDS_IN_CONSOLE == 1
#endif
#endif // APP_ENABLE_CONSOLE == 1
//#endif // _CONSOLE_H

