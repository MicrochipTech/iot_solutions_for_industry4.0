/*******************************************************************************
  Zigbee Cluster Library OTAU Client PDT Cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    zclOtauClientPdt.c

  Summary:
    This file implements the OTAU client PDT definition.

  Description:
    This file implements the OTAU client PDT definition.
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

#if defined(_ENABLE_PERSISTENT_SERVER_) && defined(OTAU_CLIENT)

/*******************************************************************************
                            Includes section
*******************************************************************************/
#include <zcl/include/zclOtauManager.h>
#include <zcl/include/zclOTAUCluster.h>
#include <zcl/include/zclOtauClient.h>
#include <pds/include/wlPdsMemIds.h>
#include <systemenvironment/include/sysTypes.h>
#include <systemenvironment/include/sysUtils.h>

/*******************************************************************************
                      External Global variables section
*******************************************************************************/

PDS_DECLARE_FILE(OTAU_ATTR_UPGRADE_SERVER_ID_ATTR_MEM_ID,
                             sizeof(otauClientAttributes.upgradeServerID),
                             &otauClientAttributes.upgradeServerID, NO_FILE_MARKS);
PDS_DECLARE_FILE(OTAU_UPGRADE_STATUS_ATTR_MEM_ID,
                             sizeof(otauClientAttributes.imageUpgradeStatus),
                             &otauClientAttributes.imageUpgradeStatus, NO_FILE_MARKS);
PDS_DECLARE_FILE(OTAU_MIN_BLOCK_PERIOD_ATTR_MEM_ID,
                             sizeof(otauClientAttributes.minimumBlockPeriod),
                             &otauClientAttributes.minimumBlockPeriod, NO_FILE_MARKS);

PROGMEM_DECLARE(PDS_MemId_t otauAttrIdsTable[]) =
{
  OTAU_ATTR_UPGRADE_SERVER_ID_ATTR_MEM_ID,
  OTAU_UPGRADE_STATUS_ATTR_MEM_ID,
  OTAU_MIN_BLOCK_PERIOD_ATTR_MEM_ID
};

PDS_DECLARE_DIR(PDS_DirDescr_t otauAttrDirDescr) =
{
  .list       = otauAttrIdsTable,
  .filesCount = ARRAY_SIZE(otauAttrIdsTable),
  .memoryId   = OTAU_ATTRIBUTES_MEM_DIR_ID
};

void zclOtauResetAttributesPDS(void)
{
  COPY_EXT_ADDR(otauClientAttributes.upgradeServerID.value,INVALID_SERVER_EXT_ADDRESS);
  otauClientAttributes.imageUpgradeStatus.value = OTAU_NORMAL;
  otauClientAttributes.minimumBlockPeriod.value = ZCL_OTAU_DEFAULT_BLOCK_REQ_PERIOD;
  PDS_Store(OTAU_ATTRIBUTES_MEM_DIR_ID);
  return;
}


static ZclOtauRecovery_t zclOtauRecoveryParams;

/*******************************************************************************
                OTAU client persistent data table definition
*******************************************************************************/
// ZCL OTA Upgrade Client data file descriptors. Shall be placed in the PDS_FF code segment.

PDS_DECLARE_FILE(OTAU_RECOVERY_IMAGE_DETAILS_MEM_ID, sizeof(ZclOtauRecoveryImageInfo_t),
                               &zclOtauRecoveryParams.image, NO_FILE_MARKS);
PDS_DECLARE_FILE(OTAU_RECOVERY_IMAGE_OFFSET_MEM_ID, sizeof(ZCLOtauRecoveryOffsetInfo_t),
                               &zclOtauRecoveryParams.fileOffset, NO_FILE_MARKS);

PROGMEM_DECLARE(PDS_MemId_t otauRecoveryTable[]) =
{
  OTAU_RECOVERY_IMAGE_DETAILS_MEM_ID,
  OTAU_RECOVERY_IMAGE_OFFSET_MEM_ID
};

PDS_DECLARE_DIR(PDS_DirDescr_t otauImageRevoceryDirDescr) =
{
  .list       = otauRecoveryTable,
  .filesCount = ARRAY_SIZE(otauRecoveryTable),
  .memoryId   = OTAU_RECOVERY_DIR_ID
};

ZclOtauRecovery_t *zclOtauGetRecoveryParams(void)
{
  return (&zclOtauRecoveryParams);
}

void zclOtauResetRecoveryParams(void)
{
  memset(&zclOtauRecoveryParams,0,sizeof(ZclOtauRecovery_t));
  PDS_Store(OTAU_RECOVERY_DIR_ID);
  return;
}

#endif // defined(_ENABLE_PERSISTENT_SERVER_)

//eof zclOtauClientPdt.c
