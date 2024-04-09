/*******************************************************************************
  Zigbee Cluster Library OTAU Client Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClient.h

  Summary:
    Declaration of the OTAU client interface.

  Description:
    Declaration of the OTAU client interface.
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

#if APP_USE_OTAU == 1 && defined(_ZCL_SUPPORT_) && defined(OTAU_CLIENT)

#ifndef _ZCLOTAUCLIENT_H
#define _ZCLOTAUCLIENT_H

/******************************************************************************
                   Includes section
******************************************************************************/
#if APP_DEVICE_OTAU_LOGGING == 1
#include <app_zigbee/zigbee_console/console.h>
#endif
#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>
#include <zcl/include/zclOTAUCluster.h>
#include <zcl/include/zclOtauManager.h>
#include <zcl/include/zclDbg.h>
#include <zdo/include/zdo.h>
#include <configserver/include/configserver.h>
#include <systemenvironment/include/sysAssert.h>
#include <nwk/include/nwkAttributes.h>
#if defined(_ENABLE_PERSISTENT_SERVER_)
#include <pds/include/wlPdsMemIds.h>
#endif //  defined(_ENABLE_PERSISTENT_SERVER_)

/******************************************************************************
                   External variables section
******************************************************************************/
#ifdef __GNUC__
extern uint32_t __d_nv_mem_start;
extern uint32_t __d_nv_mem_end;
#endif

/******************************************************************************
                   Define(s) section
******************************************************************************/
#define OTAU_APP_IMAGE_NAME               "Z3Device"

#define OTAU_BLOCK_REQUEST_USAGE         1
#define OTAU_PAGE_REQUEST_USAGE          0
#define OTAU_GET_MISSED_BYTES            1
#define OTAU_NOT_GET_MISSED_BYTES        0
#define OTAU_FIRST_CLIENT_START          1
#define OTAU_CONTINUE_CLIENT_WORK        0
#define OTAU_BLOCK_REQUEST_DELAY_OFF     0
#define OTAU_BLOCK_REQUEST_DELAY_ON      1

#define OTAU_READ_EEPROM_OK         (0)
#define OTAU_READ_EEPROM_FAILED     (-1)
#define OTAU_EEPROM_BUSY            (-2)

#define OTAU_UPGRADE_PENDING_VALUE 0xA5A5A5A5

#define OTAU_UPGRADE_END_RESP_MAN_ID_WILDCARD_VAL   0xFFFF
#define OTAU_UPGRADE_END_RESP_IMG_TYPE_WILDCARD_VAL 0xFFFF
#define OTAU_UPGRADE_END_RESP_FW_VER_WILDCARD_VAL   0xFFFFFFFF

#define AUXILIARY_STRUCTURE_IS_FULL          (sizeof(uint32_t) + sizeof(uint32_t)) //  offset + internalLength
#define IMAGE_CRC_SIZE                       1

/*
OTAU header feilds length zcl spec rev 6 - 11.4.2 OTA Header Format
*/
#define OTAUHDR_FILEID                    (0x0BEEF11E)
#define OTAUHDR_MAJOR_VERSION             (0x01)
#define OTAUHDR_MAJOR_VERSION_SHIFT       (8)
#define OTAUHDR_FILEID_OCTETLEN           (4U)  // OTA upgrade file identifier
#define OTAUHDR_HDRVERSION_OCTELEN        (2U)  // OTA Header version
#define OTAUHDR_HDRLEN_OCTETLEN           (2U)  // OTA Header length
#define OTAUHDR_HDR_FIELD_CTRL_OCTETLEN   (2U)  // OTA Header Field control
#define OTAUHDR_MFG_CODE_OCTETLEN         (2U)  // Manufacturer code
#define OTAUHDR_IMGTYPE_OCTETLEN          (2U)  // Image type
#define OTAUHDR_FILE_VER_OCTETLEN         (4U)  // File version
#define OTAUHDR_ZSTACK_VER_OCTETLEN       (2U)  // ZigBee Stack version
#define OTAUHDR_HDR_STRING_OCTETLEN       (32U) // OTA Header string
#define OTAUHDR_TOTAL_IMAGE_SIZE_OCTETLEN (4U)  // Total Image size (including header)

#define OTAUHDR_SEC_CREDENTIAL_VER_LEN    (1U)  //Security credential version
#define OTAUHDR_UPGRADE_DEST_ADDR_LEN     (8U)  // Upgrade file destination IEEE Address
#define OTAUHDR_MIN_HW_VER_LEN            (2U)  // Minimum hardware version
#define OTAUHDR_MAX_HW_VER_LEN            (2U)  // Maximum hardware version

/*
OTAU header feilds offset  zcl spec rev 6 - 11.4.2 OTA Header Format
*/

#define OTAUHDR_FILEID_OFFSET               (0)  // OTA upgrade file identifier
#define OTAUHDR_HDRVERSION_OFFSET           (OTAUHDR_FILEID_OFFSET          + OTAUHDR_FILEID_OCTETLEN)        // OTA Header version
#define OTAUHDR_HDRLEN_OFFSET               (OTAUHDR_HDRVERSION_OFFSET      + OTAUHDR_HDRVERSION_OCTELEN)     // OTA Header length
#define OTAUHDR_HDR_FIELD_CTRL_OFFSET       (OTAUHDR_HDRLEN_OFFSET          + OTAUHDR_HDRLEN_OCTETLEN)        // OTA Header Field control
#define OTAUHDR_MFG_CODE_OFFSET             (OTAUHDR_HDR_FIELD_CTRL_OFFSET  + OTAUHDR_HDR_FIELD_CTRL_OCTETLEN)  // Manufacturer code
#define OTAUHDR_IMGTYPE_OFFSET              (OTAUHDR_MFG_CODE_OFFSET        + OTAUHDR_MFG_CODE_OCTETLEN)      // Image type
#define OTAUHDR_FILE_VER_OFFSET             (OTAUHDR_IMGTYPE_OFFSET         + OTAUHDR_IMGTYPE_OCTETLEN)       // File version
#define OTAUHDR_ZSTACK_VER_OFFSET           (OTAUHDR_FILE_VER_OFFSET        + OTAUHDR_FILE_VER_OCTETLEN)      // ZigBee Stack version
#define OTAUHDR_HDR_STRING_OFFSET           (OTAUHDR_ZSTACK_VER_OFFSET      + OTAUHDR_ZSTACK_VER_OCTETLEN)    // OTA Header string
#define OTAUHDR_TOTAL_IMAGE_SIZE_OFFSET     (OTAUHDR_HDR_STRING_OFFSET      + OTAUHDR_HDR_STRING_OCTETLEN)    // Total Image size (including header)

#define OTAUHDR_IMGTYPE_IMGENC_MASK                 (1 << 15)   //0x8000  
#define OTAUHDR_IMGTYPE_INTCHKPRESENT_MASK          (1 << 14)   //0x4000
#define OTAUHDR_IMGTYPE_ISINTCHKENC_MASK            (1 << 13)   //0x2000
#define OTAUHDR_IMGTYPE_ISINTCHKOTHERTHANCRC_MASK   (1 << 12)   //0x1000
#define OTAUHDR_IMGTYPE_MASK                        (0xf << 12) //0xF000

#define OTAUHDR_IMGTYPE_ISIMGSEC_ENABLED(x)     (x & OTAUHDR_IMGTYPE_IMGENC_MASK)
#define OTAUHDR_IMGTYPE_ISINTCHKPRESENT(x)      (x & OTAUHDR_IMGTYPE_INTCHKPRESENT_MASK)
#define OTAUHDR_IMGTYPE_ISINTCHKENCRYPTED(x)    (x & OTAUHDR_IMGTYPE_ISINTCHKENC_MASK)
#define OTAUHDR_IMGTYPE_ISINTCHKOTHERTHANCRC(x) (x & OTAUHDR_IMGTYPE_ISINTCHKOTHERTHANCRC_MASK)

#define OTAUHDR_INTEGRITYCODE_OCTETLEN  (16U)

/* 
   Account for delay at server for ongoing transaction. Consider page processing
   at server as the longest transaction even if this client is in block mode.
   timeout ~= 3000 ms ~= (((pageSize/serverBlockRspPayloadSize)+1) * 
                           (respSpacing + ISDDelay))
   Considering, pageSize = 256, respSpacing = 200, serverBlockRspPayloadSize = 38,
   200 for server delay for read.
   Note : (1) This is just a guess at client side. If server is transacting page from 
          a client with much higher page size, this client's requests will have 
          frequent retry. (2) Assuming page parameters of server's ongoing transaction
          to be same as this client's page parameters is also not correct, so go for
          default value
*/
#define OTAU_DEFAULT_RESPONSE_WAIT_TIMEOUT   3000ul

#define OTAU_UPGRADE_END_RESP_MAN_ID_WILDCARD_VAL 0xFFFF
#define OTAU_UPGRADE_END_RESP_IMG_TYPE_WILDCARD_VAL 0xFFFF
#define OTAU_UPGRADE_END_RESP_FW_VER_WILDCARD_VAL 0xFFFFFFFF

/* frequency of write(in bytes) = total-file-size/OTAU_NUM_OF_PDS_WRITES */
#define OTAU_NUM_OF_PDS_WRITES               20 // (MAXIMUM 100)

#define REPOST_OFD_ACTION                    10ul
#define AMOUNT_MSEC_IN_SEC                   1000ul
#define WAIT_FOR_RUN_UPGRADE_REQ             0xFF
#define WAITING_UPGRADE_END_RESPONSE_TIMEOUT 1 * 60 * 60 * AMOUNT_MSEC_IN_SEC  // 1 hour (in msec)
#define UNLIMITED_WAITING_TIME               0xFFFFFFFFul
#define UPGRADE_END_REQ_QUICK_TIMEOUT        100

#define ZERO_SERVER_EXT_ADDRESS              0x0000000000000000ull
#define INVALID_SERVER_EXT_ADDRESS           0xFFFFFFFFFFFFFFFFull
#define OTAU_MAX_UNAUTHORIZED_SERVERS        3

#define OTAU_SET_STATE(machine, state)       ((machine) = (state))
#define OTAU_CHECK_STATE(machine, state)     ((machine) == (state))


#define OTAU_ATTRIBUTES_MEM_DIR_ID                  OTAU_DIR1_MEM_ID
// UpgradeServerID 0x0000
#define OTAU_ATTR_UPGRADE_SERVER_ID_ATTR_MEM_ID   OTAU_PARAM1_MEM_ID
// 0x0006 ImageUpgradeStatus
#define OTAU_UPGRADE_STATUS_ATTR_MEM_ID           OTAU_PARAM2_MEM_ID
// 0x0009 MinimumBlockPeriod
#define OTAU_MIN_BLOCK_PERIOD_ATTR_MEM_ID         OTAU_PARAM3_MEM_ID

#define OTAU_RECOVERY_DIR_ID                        OTAU_DIR2_MEM_ID

#define OTAU_RECOVERY_IMAGE_DETAILS_MEM_ID        OTAU_PARAM4_MEM_ID
#define OTAU_RECOVERY_IMAGE_OFFSET_MEM_ID         OTAU_PARAM5_MEM_ID

#define OTAU_MAX_QUERY_JITTER_VALUE         0xff

#if defined _PIC32CX_BZ3_ 
#define OTAU_MAX_SECTOR_ERASE 4U
#endif
/******************************************************************************
                   Constants section
******************************************************************************/
typedef struct {
  ZclOtauDiscoveryResult_t addr;
  ZCL_OtauFirmwareVersion_t ver;
  uint8_t queryJitter;
} ZclOtauImageNotifyParams_t;

#if defined _PIC32CX_BZ3_ 
typedef struct {
    uint8_t buff[CS_ZCL_OTAU_IMAGE_PAGE_REQUEST_PAGE_SIZE]; /*Otau buffer to hold bytes from block response*/
    uint16_t end; /*Index used to write bytes to Otau buffer*/
} otauPageBuff_t;
#endif
/******************************************************************************
                          Prototypes section
******************************************************************************/
ZCL_Status_t otauQueryNextImageRespInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauQueryNextImageResp_t *payload);
ZCL_Status_t otauImageNotifyInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauImageNotify_t *payload);
ZCL_Status_t otauImageBlockRespInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauImageBlockResp_t *payload);
ZCL_Status_t otauUpgradeEndRespInd(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_OtauUpgradeEndResp_t *payload);

bool isExtAddrValid(ExtAddr_t addr);

// initialization related functions

// discovery related functions
void otauEnqueueDiscoveryQueue(ShortAddr_t shortAddr, uint8_t endpoint);

void otauStartDiscovery(void);
void otauStartDiscoveryTimer(void);

void otauIeeeAddrReq(ZclOtauDiscoveryResult_t *srv);
void otauIeeeAddrResp(ZDO_ZdpResp_t *ieeeAddrResp);

void otauNwkAddrReq(void);
void otauNwkAddrResp(ZDO_ZdpResp_t *nwkAddrResp);

void otauMatchDescReq(bool unicast, void (* zdoZdpResp)(ZDO_ZdpResp_t *zdpResp));
void otauBroadcastMatchDescResp(ZDO_ZdpResp_t *zdpResp);
void otauUnicastMatchDescResp(ZDO_ZdpResp_t *zdpResp);

#if defined _PIC32CX_BZ3_ 
bool otauExternalPageWrite(uint8_t* otauDataBuffer, uint32_t writeAddress);
bool otauCacheExternalFlashPage(otauPageBuff_t* clientBuffer, uint8_t* data, uint32_t* writeAddress, uint16_t blockLength);
DRV_HANDLE * getSstHandle(void);
#endif

#if (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)
void otauRequestKeyReq(ExtAddr_t *tcExtAddr);
void otauRequestKeyResp(APS_RequestKeyConf_t *requestKeyConf);
#endif // (defined _LINK_SECURITY_) && (!defined _LIGHT_LINK_PROFILE_)

// query related functions
void otauStartQueryTimer(void);
void otauTransitionToQuery(void);

// downloading related functions
void otauStartDownload(void);
void otauGetMissedBlocks(void);
void otauCountActuallyDataSize(void);
bool otauCheckPageIntegrity(void);
void otauScheduleImageBlockReq(void);
void otauScheduleImagePageReq(void);

// upgrading related functions
void otauUpgradeEndReq(void);

// helper functions
void otauStartSwitch(void);
void otauStartWrite(void);
void otauStartErase(void);

void otauSwitchCallback(OFD_Status_t status);

void zclOtauFillOutgoingZclRequest(uint8_t id, uint8_t length, uint8_t *payload);
void otauSomeRequestConfirm(ZCL_Notify_t *resp);
void otauSomeDefaultResponse(ZCL_Request_t *req, ZCL_Addressing_t *addressing, uint8_t payloadLength, uint8_t *payload);
void otauAbortUpgradeProcess (void);
void otauSetImageUpgradeStatusAttr(ZCL_ImageUpdateStatus_t status);
ZCL_Status_t otauProcessSuccessfullImageBlockResponse(ZCL_OtauImageBlockResp_t *payload);
ZCL_Status_t otauFillAuxiliaryStructure(ZCL_OtauImageBlockResp_t *payload);
void otauPollServerEndUpgrade(void);
void otauClearPdsParams(void);
void otauConfigureNextPdsWriteOffset(void);

// security related functions
void otauStartEepromDelayedTransaction(void);
void readImgTypeEepromCallback(void);
void writeEepromActionFlagCallback(void);
void otauStartEepromPollTimer(void (*delayedTransaction)());
uint8_t getAesDecryptIVsize (void);
void otauSetNewKey(const uint8_t *key);
void otauSetNewIV(const uint8_t *iv);

void setOtauIVrecovery(bool flag);
void otauRestartBlockRxTimer (void);

#endif // (ZCL_SUPPORT == 1) && (APP_USE_OTAU == 1)
void ZCL_RestoreOtauparams(void);
void ZCL_BackupOtauparams(void);
#endif // _ZCLOTAUCLIENT_H
//eof zclOtauClient.h
