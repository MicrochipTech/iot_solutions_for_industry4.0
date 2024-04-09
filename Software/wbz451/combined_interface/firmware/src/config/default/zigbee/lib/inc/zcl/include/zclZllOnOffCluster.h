/*******************************************************************************
  ZCL ZLL On/Off Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclZllOnOffCluster.h

  Summary:
    The header file describes the ZLL On/Off Cluster and its interface.

  Description:
    The header file describes the ZLL On/Off Cluster and its interface.
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


#ifndef _ZCLZLLONOFFCLUSTER_H
#define	_ZCLZLLONOFFCLUSTER_H

/*!
Attributes and commands for determining basic information about a device,
setting user device information such as location, enabling a device and resetting it
to factory defaults.
*/

/*******************************************************************************
                   Includes section
*******************************************************************************/

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/*******************************************************************************
                   Define(s) section
*******************************************************************************/

#define ZCL_ON_OFF_CLUSTER_ACCEPT_ONLY_WHEN_ON                      0x01u

#define ZCL_ON_OFF_CLUSTER_STARTUP_OFF                              0x00u
#define ZCL_ON_OFF_CLUSTER_STARTUP_ON                               0x01u
#define ZCL_ON_OFF_CLUSTER_STARTUP_TOGGLE                           0x02u
#define ZCL_ON_OFF_CLUSTER_STARTUP_PREVIOUS                         0xffu

/**
 * \brief On/Off Cluster server attributes amount
*/
#define ZCL_ONOFF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT                  6u

/**
 * \brief On/Off Cluster client attributes amount. Clinet doesn't have attributes.
*/

#define ZCL_ONOFF_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT                  1u

/**
 * \brief On/Off Cluster commands amount
*/

#define ZCL_ONOFF_SERVER_CLUSTER_COMMANDS_AMOUNT                    6u
#define ZCL_ONOFF_CLIENT_CLUSTER_COMMANDS_AMOUNT                    6u

/**
 * \brief On/Off ClusterVersion attribute identifier
*/

#define ZCL_ONOFF_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID       CCPU_TO_LE16(0xfffd)

/**
 * \brief On/Off Cluster server's attributes identifiers
*/

#define ZCL_ONOFF_CLUSTER_ONOFF_SERVER_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0000)
#define ZCL_ONOFF_CLUSTER_GLOBAL_SCENE_CONTROL_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x4000)
#define ZCL_ONOFF_CLUSTER_ON_TIME_SERVER_ATTRIBUTE_ID               CCPU_TO_LE16(0x4001)
#define ZCL_ONOFF_CLUSTER_OFF_WAIT_TIME_SERVER_ATTRIBUTE_ID         CCPU_TO_LE16(0x4002)
#if ZLO_CLUSTER_ENHANCEMENTS == 1
#define ZCL_ONOFF_CLUSTER_STARTUP_ONOFF_SERVER_ATTRIBUTE_ID         CCPU_TO_LE16(0x4003)
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */

/**
 * \brief On/Off Cluster client's command identifiers
*/

#define ZCL_ONOFF_CLUSTER_OFF_COMMAND_ID                            0x00u
#define ZCL_ONOFF_CLUSTER_ON_COMMAND_ID                             0x01u
#define ZCL_ONOFF_CLUSTER_TOGGLE_COMMAND_ID                         0x02u
#define ZCL_ONOFF_CLUSTER_OFF_WITH_EFFECT_COMMAND_ID                0x40u
#define ZCL_ONOFF_CLUSTER_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID    0x41u
#define ZCL_ONOFF_CLUSTER_ON_WITH_TIMED_OFF_COMMAND_ID              0x42u

/**
 * \brief On/Off Cluster server define attributes macros
*/

/**
 * \brief On/Off Cluster client define attributes macros
*/
#define ZCL_DEFINE_ONOFF_CLUSTER_CLIENT_ATTRIBUTES() \
    DEFINE_ATTRIBUTE(clusterVersion, ZCL_READONLY_ATTRIBUTE, ZCL_ONOFF_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID, ZCL_U16BIT_DATA_TYPE_ID) 
/**
 * \brief On/Off Cluster define commands macros
*/

#define ZCL_DEFINE_ONOFF_CLUSTER_COMMANDS(onCommandInd, offCommandInd, toggleCommandInd, offWithEffectInd, onWithRecallGlobalSceneInd, onWithTimedOffInd) \

/**
 * \brief On/Off Cluster definition macros
*/

#define ONOFF_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = ONOFF_CLUSTER_ID, \
   .options = \
   { \
     .type = ZCL_CLIENT_CLUSTER_TYPE, \
     .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
     .reserved = 0, \
   }, \
   .attributesAmount = ZCL_ONOFF_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ONOFF_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define ONOFF_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
{ \
   .id = ONOFF_CLUSTER_ID, \
   .options = \
   { \
     .type = ZCL_SERVER_CLUSTER_TYPE, \
     .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY, \
     .reserved = 0, \
   }, \
   .attributesAmount = ZCL_ONOFF_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
   .attributes = (uint8_t *)clattributes, \
   .commandsAmount = ZCL_ONOFF_SERVER_CLUSTER_COMMANDS_AMOUNT, \
   .commands = (uint8_t *)clcommands \
}

#define DEFINE_ONOFF_CLUSTER(cltype, clattributes, clcommands) \
    ONOFF_CLUSTER_##cltype(clattributes, clcommands)

/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief On/Off Cluster server's attributes
*/

typedef struct PACK
{
#if ZLO_CLUSTER_ENHANCEMENTS == 1
#endif

  
} ZCL_OnOffClusterServerAttributes_t;

typedef struct PACK
{
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;
} ZCL_OnOffClusterClientAttributes_t;

/**
 *   \brief On/Off Cluster extension field set
 */
typedef struct PACK
{
    uint16_t  clusterId;
    uint8_t   length;
    bool      onOffValue;
} ZCL_OnOffClusterExtensionFieldSet_t;

typedef struct PACK
{
  uint8_t     effectIdentifier;
  uint8_t     effectVariant;
} ZCL_OffWithEffect_t;

typedef struct PACK
{
  uint8_t   onOffControl;
  uint16_t  onTime;
  uint16_t  offWaitTime;
} ZCL_OnWithTimedOff_t;

END_PACK

/**
 * \brief On/Off Cluster clients's commands.
*/

typedef struct
{
   /* To Avoid linker error*/
   void *tempPtr;
} ZCL_OnOffClusterCommands_t;

#define DEFINE_ONOFF_CLUSTER_EXTENSION_FIELD_SET(value) \
    .clusterId = ONOFF_CLUSTER_ID, \
    .length = sizeof(uint8_t), \
    .onOffValue = value

#endif	/* _ZCLZLLONOFFCLUSTER_H */

