/*******************************************************************************
  ZCL ZLL Color Control Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclZllColorControlCluster.h

  Summary:
    The header file describes the ZLL Color Control Cluster.

  Description:
    The header file describes the ZLL Color Control Cluster.
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


#ifndef _ZCLZLLCOLORCONTROLCLUSTER_H
#define _ZCLZLLCOLORCONTROLCLUSTER_H

/******************************************************************************
                        Includes section
******************************************************************************/
#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>

/******************************************************************************
                        Defines section
******************************************************************************/
#if ZLO_CLUSTER_ENHANCEMENTS == 1
// startUpColorTemperatureMireds attribute specific values meanings
#define ZCL_ZLL_STARTUP_COLOR_TEMPERATURE_PREVIOUS              0xffffu
// Options attribute bit masks
#define ZCL_ZLL_OPTIONS_ATTR_EXECUTE_IF_OFF_MASK                0x01u
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */

/**
 * \brief ZLL Server Cluster attributes amount.
*/
#define ZCL_COLOR_CONTROL_CLUSTER_SERVER_ATTRIBUTES_AMOUNT     40

/**
 * \brief ZLL Client Cluster attributes amount.
*/
#define ZCL_COLOR_CONTROL_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT     1


/**
 * \brief Color control ClusterVersion attribute identifier
*/

#define ZCL_COLOR_CONTROL_CLUSTER_GLOBAL_CLUSTER_VERSION_ATTRIBUTE_ID   CCPU_TO_LE16(0xfffd)

/**
 * \brief ZLL Cluster server's attributes identifiers
*/

#define ZCL_ZLL_CLUSTER_CURRENT_HUE_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0000)
#define ZCL_ZLL_CLUSTER_CURRENT_SATURATION_SERVER_ATTRIBUTE_ID             CCPU_TO_LE16(0x0001)
#define ZCL_ZLL_CLUSTER_REMAINING_TIME_SERVER_ATTRIBUTE_ID                 CCPU_TO_LE16(0x0002)
#define ZCL_ZLL_CLUSTER_CURRENT_X_SERVER_ATTRIBUTE_ID                      CCPU_TO_LE16(0x0003)
#define ZCL_ZLL_CLUSTER_CURRENT_Y_SERVER_ATTRIBUTE_ID                      CCPU_TO_LE16(0x0004)
#define ZCL_ZLL_CLUSTER_COLOR_TEMPERATURE_SERVER_ATTRIBUTE_ID              CCPU_TO_LE16(0x0007)
#define ZCL_ZLL_CLUSTER_COLOR_MODE_SERVER_ATTRIBUTE_ID                     CCPU_TO_LE16(0x0008)
#define ZCL_ZLL_CLUSTER_NUMBER_OF_PRIMARIES_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0010)
#define ZCL_ZLL_CLUSTER_PRIMARY_1_X_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0011)
#define ZCL_ZLL_CLUSTER_PRIMARY_1_Y_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0012)
#define ZCL_ZLL_CLUSTER_PRIMARY_1_INTENSITY_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0013)
#define ZCL_ZLL_CLUSTER_PRIMARY_2_X_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0015)
#define ZCL_ZLL_CLUSTER_PRIMARY_2_Y_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0016)
#define ZCL_ZLL_CLUSTER_PRIMARY_2_INTENSITY_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0017)
#define ZCL_ZLL_CLUSTER_PRIMARY_3_X_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0019)
#define ZCL_ZLL_CLUSTER_PRIMARY_3_Y_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x001A)
#define ZCL_ZLL_CLUSTER_PRIMARY_3_INTENSITY_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x001B)
#define ZCL_ZLL_CLUSTER_PRIMARY_4_X_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0020)
#define ZCL_ZLL_CLUSTER_PRIMARY_4_Y_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0021)
#define ZCL_ZLL_CLUSTER_PRIMARY_4_INTENSITY_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0022)
#define ZCL_ZLL_CLUSTER_PRIMARY_5_X_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0024)
#define ZCL_ZLL_CLUSTER_PRIMARY_5_Y_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0025)
#define ZCL_ZLL_CLUSTER_PRIMARY_5_INTENSITY_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x0026)
#define ZCL_ZLL_CLUSTER_PRIMARY_6_X_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0028)
#define ZCL_ZLL_CLUSTER_PRIMARY_6_Y_SERVER_ATTRIBUTE_ID                    CCPU_TO_LE16(0x0029)
#define ZCL_ZLL_CLUSTER_PRIMARY_6_INTENSITY_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x002A)
/* Additional attributes */
#define ZCL_ZLL_CLUSTER_ENHANCED_CURRENT_HUE_SERVER_ATTRIBUTE_ID           CCPU_TO_LE16(0x4000)
#define ZCL_ZLL_CLUSTER_ENHANCED_COLOR_MODE_SERVER_ATTRIBUTE_ID            CCPU_TO_LE16(0x4001)
#define ZCL_ZLL_CLUSTER_COLOR_LOOP_ACTIVE_SERVER_ATTRIBUTE_ID              CCPU_TO_LE16(0x4002)
#define ZCL_ZLL_CLUSTER_COLOR_LOOP_DIRECTION_SERVER_ATTRIBUTE_ID           CCPU_TO_LE16(0x4003)
#define ZCL_ZLL_CLUSTER_COLOR_LOOP_TIME_SERVER_ATTRIBUTE_ID                CCPU_TO_LE16(0x4004)
#define ZCL_ZLL_CLUSTER_COLOR_LOOP_START_ENHANCED_HUE_SERVER_ATTRIBUTE_ID  CCPU_TO_LE16(0x4005)
#define ZCL_ZLL_CLUSTER_COLOR_LOOP_STORED_ENHANCED_HUE_SERVER_ATTRIBUTE_ID CCPU_TO_LE16(0x4006)
#define ZCL_ZLL_CLUSTER_COLOR_CAPABILITIES_SERVER_ATTRIBUTE_ID             CCPU_TO_LE16(0x400A)
#define ZCL_ZLL_CLUSTER_COLOR_TEMP_PHYSICAL_MIN_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x400B)
#define ZCL_ZLL_CLUSTER_COLOR_TEMP_PHYSICAL_MAX_SERVER_ATTRIBUTE_ID        CCPU_TO_LE16(0x400C)
/* ZLO enhancements additional attributes */
#if ZLO_CLUSTER_ENHANCEMENTS == 1
#define ZCL_ZLL_CLUSTER_COUPLE_COLOR_TEMP_TO_MIN_MIREDS_SERVER_ATTRIBUTE_ID CCPU_TO_LE16(0x400D)
#define ZCL_ZLL_CLUSTER_STARTUP_COLOR_TEMPERATURE_SERVER_ATTRIBUTE_ID       CCPU_TO_LE16(0x4010)
#define ZCL_ZLL_CLUSTER_OPTIONS_SERVER_ATTRIBUTE_ID                         CCPU_TO_LE16(0x000F)
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */

/**
 * \brief Color Control Cluster default attributes values
*/
#define ZCL_ZLL_CLUSTER_CURRENT_HUE_DEFAULT_VALUE                    0x00
#define ZCL_ZLL_CLUSTER_CURRENT_SATURATION_DEFAULT_VALUE             0x00
#define ZCL_ZLL_CLUSTER_REMAINING_TIME_DEFAULT_VALUE                 0x00
#define ZCL_ZLL_CLUSTER_CURRENT_X_DEFAULT_VALUE                      CCPU_TO_LE16(0x616B)
#define ZCL_ZLL_CLUSTER_CURRENT_Y_DEFAULT_VALUE                      CCPU_TO_LE16(0x607D)
#define ZCL_ZCL_CLUSTER_COLOR_TEMP_DEFAULT_VALUE                     CCPU_TO_LE16(0x00FA)
#define ZCL_ZLL_CLUSTER_COLOR_MODE_DEFAULT_VALUE                     0x01
#define ZCL_ZCL_CLUSTER_ENHANCED_CURRENT_HUE_DEFAULT_VALUE           CCPU_TO_LE16(0x0000)
#define ZCL_ZCL_CLUSTER_ENHANCED_COLOR_MODE_DEFAULT_VALUE            0x01
#define ZCL_ZCL_CLUSTER_COLOR_LOOP_ACTIVE_DEFAULT_VALUE              0x00
#define ZCL_ZCL_CLUSTER_COLOR_LOOP_DIRECTION_DEFAULT_VALUE           0x00
#define ZCL_ZCL_CLUSTER_COLOR_LOOP_TIME_DEFAULT_VALUE                CCPU_TO_LE16(0x0019)
#define ZCL_ZCL_CLUSTER_COLOR_LOOP_START_ENHANCED_HUE_DEFAULT_VALUE  CCPU_TO_LE16(0x2300)
#define ZCL_ZCL_CLUSTER_COLOR_LOOP_STORED_ENHANCED_HUE_DEFAULT_VALUE CCPU_TO_LE16(0x0000)

#if ZB_COMMISSIONING_ON_STARTUP == 1
#define ZCL_ZCL_CLUSTER_TEMP_PHYSICAL_MIN_DEFAULT_VALUE              CCPU_TO_LE16(0x0000)
#define ZCL_ZCL_CLUSTER_TEMP_PHYSICAL_MAX_DEFAULT_VALUE              CCPU_TO_LE16(0xFFFF)
#else
#define ZCL_ZCL_CLUSTER_TEMP_PHYSICAL_MIN_DEFAULT_VALUE              CCPU_TO_LE16(0x0002)
#define ZCL_ZCL_CLUSTER_TEMP_PHYSICAL_MAX_DEFAULT_VALUE              CCPU_TO_LE16(0xFEFF)
#endif // ZB_COMMISSIONING_ON_STARTUP == 1

#if ZLO_CLUSTER_ENHANCEMENTS == 1
#define ZCL_DEFINE_COLOR_CONTROL_SERVER_CLUSTER_ATTRIBUTES(min, max) 
#else
#define ZCL_DEFINE_COLOR_CONTROL_SERVER_CLUSTER_ATTRIBUTES(min, max) 
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */


#define ZCL_DEFINE_COLOR_CONTROL_CLIENT_CLUSTER_ATTRIBUTES() 

/**
 * \brief ZLL Client Cluster commands amount.
*/
#define ZCL_COLOR_CONTROL_SERVER_CLUSTER_COMMANDS_AMOUNT  20
#define ZCL_COLOR_CONTROL_CLIENT_CLUSTER_COMMANDS_AMOUNT  19

/**
 * \brief ZLL Client Cluster commands identifiers.
*/
#define MOVE_TO_HUE_COMMAND_ID                         0x00
#define MOVE_HUE_COMMAND_ID                            0x01
#define STEP_HUE_COMMAND_ID                            0x02
#define MOVE_TO_SATURATION_COMMAND_ID                  0x03
#define MOVE_SATURATION_COMMAND_ID                     0x04
#define STEP_SATURATION_COMMAND_ID                     0x05
#define MOVE_TO_HUE_AND_SATURATION_COMMAND_ID          0x06
#define MOVE_TO_COLOR_COMMAND_ID                       0x07
#define MOVE_COLOR_COMMAND_ID                          0x08
#define STEP_COLOR_COMMAND_ID                          0x09
#define MOVE_TO_COLOR_TEMPERATURE_COMMAND_ID           0x0A
/* Additional commands */
#define ENHANCED_MOVE_TO_HUE_COMMAND_ID                0x40
#define ENHANCED_MOVE_HUE_COMMAND_ID                   0x41
#define ENHANCED_STEP_HUE_COMMAND_ID                   0x42
#define ENHANCED_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID 0x43
#define COLOR_LOOP_SET_COMMAND_ID                      0x44
#define STOP_MOVE_STEP_COMMAND_ID                      0x47
#define MOVE_COLOR_TEMPERATURE_COMMAND_ID              0x4B
#define STEP_COLOR_TEMPERATURE_COMMAND_ID              0x4C

#define ZCL_COLOR_CONTROL_CLUSTER_COMMANDS_FOR_EXTENDED_COLOR_LIGHT(moveToHueInd, \
                                                                    moveHueInd,   \
                                                                    stepHueInd,   \
                                                                    moveToSaturationInd, \
                                                                    moveSaturationInd, \
                                                                    stepSaturationInd, \
                                                                    moveToHueAndSaturationInd, \
                                                                    moveToColorInd, \
                                                                    moveColorInd, \
                                                                    stepColorInd, \
                                                                    moveToColorTemperatureInd, \
                                                                    enhancedMoveToHueInd, \
                                                                    enhancedMoveHueInd, \
                                                                    enhancedStepHueInd, \
                                                                    enhancedMoveToHueAndSaturationInd, \
                                                                    colorLoopSetInd, \
                                                                    stopMoveStepInd, \
                                                                    moveColorTemperatureInd, \
                                                                    stepColorTemperatureInd) \

#define ZCL_COLOR_CONTROL_CLUSTER_COMMANDS_FOR_COLOR_LIGHT(moveToHueInd, \
                                                           moveHueInd,   \
                                                           stepHueInd,   \
                                                           moveToSaturationInd, \
                                                           moveSaturationInd, \
                                                           stepSaturationInd, \
                                                           moveToHueAndSaturationInd, \
                                                           moveToColorInd, \
                                                           moveColorInd, \
                                                           stepColorInd, \
                                                           enhancedMoveToHueInd, \
                                                           enhancedMoveHueInd, \
                                                           enhancedStepHueInd, \
                                                           enhancedMoveToHueAndSaturationInd, \
                                                           colorLoopSetInd, \
                                                           stopMoveStepInd) \

#define ZCL_COLOR_CONTROL_CLUSTER_COMMANDS_FOR_TEMPERATURE_COLOR_LIGHT(moveToColorTemperatureInd, \
                                                                       moveColorTemperatureInd, \
                                                                       stepColorTemperatureInd) \

#define ZCL_COLOR_CONTROL_CLUSTER_COMMANDS_FOR_COLOR_SCENE_CONTROLLER() \

#define ZLL_COLOR_CONTROL_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = COLOR_CONTROL_CLUSTER_ID, \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_COLOR_CONTROL_CLUSTER_CLIENT_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_COLOR_CONTROL_CLIENT_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (uint8_t *)clcommands \
  }

#define ZLL_COLOR_CONTROL_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands) \
  { \
    .id = COLOR_CONTROL_CLUSTER_ID, \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY}, \
    .attributesAmount = ZCL_COLOR_CONTROL_CLUSTER_SERVER_ATTRIBUTES_AMOUNT, \
    .attributes = (uint8_t *)clattributes, \
    .commandsAmount = ZCL_COLOR_CONTROL_SERVER_CLUSTER_COMMANDS_AMOUNT, \
    .commands = (uint8_t *)clcommands \
  }
#define DEFINE_COLOR_CONTROL_CLUSTER(cltype, clattributes, clcommands) ZLL_COLOR_CONTROL_CLUSTER_##cltype(clattributes, clcommands)

/******************************************************************************
                    Types section
******************************************************************************/

BEGIN_PACK

/**
 * \brief Color Capabilities bitfield type.
*/
typedef struct PACK _ZCL_ZllColorCapabilities_t
{
  LITTLE_ENDIAN_OCTET(6,(
    uint16_t hueSaturationSupported    : 1,
    uint16_t enhancedHueSupported      : 1,
    uint16_t colorLoopSupported        : 1,
    uint16_t XYAttributesSupported     : 1,
    uint16_t colorTemperatureSupported : 1,
    uint16_t reserved                  : 11
  ))
} ZCL_ZllColorCapabilities_t;

/***************************************************************************//**
  \brief
    ZCL Color Control Cluster server side attributes
*******************************************************************************/
typedef struct PACK
{
#if ZLO_CLUSTER_ENHANCEMENTS == 1
#endif /* #if ZLO_CLUSTER_ENHANCEMENTS == 1 */
} ZCL_ColorControlClusterServerAttributes_t;

/***************************************************************************//**
  \brief
    ZCL Color Control Cluster client side attributes
*******************************************************************************/
typedef struct PACK
{
  /*! TBD
  */
  struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint16_t            value;
  } clusterVersion;
} ZCL_ColorControlClusterClientAttributes_t;

END_PACK

/**
 * \brief MoveToHue command direction values
*/
typedef enum _ZCL_ZllMoveToHueDirection_t
{
  ZCL_ZLL_MOVE_TO_HUE_DIRECTION_SHORTEST_DISTANCE = 0x00,
  ZCL_ZLL_MOVE_TO_HUE_DIRECTION_LONGEST_DISTANCE  = 0x01,
  ZCL_ZLL_MOVE_TO_HUE_DIRECTION_UP                = 0x02,
  ZCL_ZLL_MOVE_TO_HUE_DIRECTION_DOWN              = 0x03,
} ZCL_ZllMoveToHueDirection_t;

/**
 * \brief MoveHue command moveMode values
*/
typedef enum _ZCL_ZllMoveHueMoveMode_t
{
  ZCL_ZLL_MOVE_HUE_MOVE_MODE_STOP = 0x00,
  ZCL_ZLL_MOVE_HUE_MOVE_MODE_UP   = 0x01,
  ZCL_ZLL_MOVE_HUE_MOVE_MODE_DOWN = 0x03,
} ZCL_ZllMoveHueMoveMode_t;

/**
 * \brief StepHue command stepMode values
*/
typedef enum _ZCL_ZllStepHueStepMode_t
{
  ZCL_ZLL_STEP_HUE_STEP_MODE_UP   = 0x01,
  ZCL_ZLL_STEP_HUE_STEP_MODE_DOWN = 0x03,
} ZCL_ZllStepHueStepMode_t;

/**
 * \brief MoveSaturation command moveMode values
*/
typedef enum _ZCL_ZllMoveSaturationMoveMode_t
{
  ZCL_ZLL_MOVE_SATURATION_MOVE_MODE_STOP = 0x00,
  ZCL_ZLL_MOVE_SATURATION_MOVE_MODE_UP   = 0x01,
  ZCL_ZLL_MOVE_SATURATION_MOVE_MODE_DOWN = 0x03,
} ZCL_ZllMoveSaturationMoveMode_t;

/**
 * \brief StepSaturation command stepMode values
*/
typedef enum _ZCL_ZllStepSaturationStepMode_t
{
  ZCL_ZLL_STEP_SATURATION_STEP_MODE_UP   = 0x01,
  ZCL_ZLL_STEP_SATURATION_STEP_MODE_DOWN = 0x03,
} ZCL_ZllStepSaturationStepMode_t;

/**
 * \brief ColorLoopSet command action values
*/
typedef enum _ZCL_ZllColorLoopSetAction_t
{
  ZCL_ZLL_COLOR_LOOP_SET_ACTION_DEACTIVATE        = 0x00,
  ZCL_ZLL_COLOR_LOOP_SET_ACTION_ACTIVATE          = 0x01,
  ZCL_ZLL_COLOR_LOOP_SET_ACTION_ACTIVATE_ENHANCED = 0x02,
} ZCL_ZllColorLoopSetAction_t;

/**
 * \brief ColorLoopSet command direction values
*/
typedef enum _ZCL_ZllColorLoopSetDirection_t
{
  ZCL_ZLL_COLOR_LOOP_SET_DIRECTION_DECREMENT_HUE = 0x00,
  ZCL_ZLL_COLOR_LOOP_SET_DIRECTION_INCREMENT_HUE = 0x01,
} ZCL_ZllColorLoopSetDirection_t;

/**
 * \brief EnhancedColorMode values
*/
typedef enum _ZCL_ZllEnhancedColorMode_t
{
  ZCL_ZLL_CURRENT_HUE_AND_CURRENT_SATURATION          = 0x00,
  ZCL_ZLL_CURRENT_X_AND_CURRENT_Y                     = 0x01,
  ZCL_ZLL_COLOR_TEMPERATURE                           = 0x02,
  ZCL_ZLL_ENHANCED_CURRENT_HUE_AND_CURRENT_SATURATION = 0x03,
} ZCL_ZllEnhancedColorMode_t;

/**
 * \brief Color Loop action type.
*/
typedef enum _ZCL_ZllColorLoopAction_t
{
  COLOR_LOOP_DEACTIVATE          = 0x00,
  COLOR_LOOP_ACTIVATE_FROM_CLSEH = 0x01,
  COLOR_LOOP_ACTIVATE_FROM_ECH   = 0x02
} ZCL_ZllColorLoopAction_t;

/**
 * \brief MoveColorTemperature command moveMode values
*/
typedef enum _ZCL_ZllMoveColorTemperatureMoveMode_t
{
  ZCL_ZLL_MOVE_COLOR_TEMPERATURE_MOVE_MODE_STOP = 0x00,
  ZCL_ZLL_MOVE_COLOR_TEMPERATURE_MOVE_MODE_UP   = 0x01,
  ZCL_ZLL_MOVE_COLOR_TEMPERATURE_MOVE_MODE_DOWN = 0x03,
} ZCL_ZllMoveColorTemperatureMoveMode_t;

/**
 * \brief StepColorTemperature command stepMode values
*/
typedef enum _ZCL_ZllStepColorTemperatureStepMode_t
{
  ZCL_ZLL_STEP_COLOR_TEMPERATURE_STEP_MODE_UP   = 0x01,
  ZCL_ZLL_STEP_COLOR_TEMPERATURE_STEP_MODE_DOWN = 0x03,
} ZCL_ZllStepColorTemperatureStepMode_t;

BEGIN_PACK
/**
 * \brief MoveToHue command payload format
*/
typedef struct PACK _ZCL_ZllMoveToHueCommand_t
{
  uint8_t hue;
  uint8_t direction;
  uint16_t transitionTime;
} ZCL_ZllMoveToHueCommand_t;

/**
 * \brief MoveToHue command payload format
*/
typedef struct PACK _ZCL_ZllMoveToHueWithOptionsCommand_t
{
  uint8_t hue;
  uint8_t direction;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveToHueWithOptionsCommand_t;

/**
 * \brief MoveHue command payload format
*/
typedef struct PACK _ZCL_ZllMoveHueCommand_t
{
  uint8_t moveMode;
  uint8_t rate;
} ZCL_ZllMoveHueCommand_t;

/**
 * \brief MoveHue command payload format
*/
typedef struct PACK _ZCL_ZllMoveHueWithOptionsCommand_t
{
  uint8_t moveMode;
  uint8_t rate;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveHueWithOptionsCommand_t;

/**
 * \brief StepHue command payload format
*/
typedef struct PACK _ZCL_ZllStepHueCommand_t
{
  uint8_t stepMode;
  uint8_t stepSize;
  uint8_t transitionTime; /* uint16_t ? */
} ZCL_ZllStepHueCommand_t;

/**
 * \brief StepHue command payload format
*/
typedef struct PACK _ZCL_ZllStepHueWithOptionsCommand_t
{
  uint8_t stepMode;
  uint8_t stepSize;
  uint8_t transitionTime; /* uint16_t ? */
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllStepHueWithOptionsCommand_t;

/**
 * \brief MoveToSaturation command payload format
*/
typedef struct PACK _ZCL_ZllMoveToSaturationCommand_t
{
  uint8_t saturation;
  uint16_t transitionTime;
} ZCL_ZllMoveToSaturationCommand_t;

/**
 * \brief MoveToSaturation command payload format
*/
typedef struct PACK _ZCL_ZllMoveToSaturationWithOptionsCommand_t
{
  uint8_t saturation;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveToSaturationWithOptionsCommand_t;

/**
 * \brief MoveSaturation command payload format
*/
typedef struct PACK _ZCL_ZllMoveSaturationCommand_t
{
  uint8_t moveMode;
  uint8_t rate;
} ZCL_ZllMoveSaturationCommand_t;

/**
 * \brief MoveSaturation command payload format
*/
typedef struct PACK _ZCL_ZllMoveSaturationWithOptionsCommand_t
{
  uint8_t moveMode;
  uint8_t rate;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveSaturationWithOptionsCommand_t;

/**
 * \brief StepSaturation command payload format
*/
typedef struct PACK _ZCL_ZllStepSaturationCommand_t
{
  uint8_t  stepMode;
  uint8_t  stepSize;
  uint16_t transitionTime;
} ZCL_ZllStepSaturationCommand_t;

/**
 * \brief StepSaturation command payload format
*/
typedef struct PACK _ZCL_ZllStepSaturationWithOptionsCommand_t
{
  uint8_t  stepMode;
  uint8_t  stepSize;
  uint16_t transitionTime;
  uint8_t  optionsMask;
  uint8_t  optionsOverride;
} ZCL_ZllStepSaturationWithOptionsCommand_t;

/**
 * \brief MoveToHueAndSaturation command payload format
*/
typedef struct PACK _ZCL_ZllMoveToHueAndSaturationCommand_t
{
  uint8_t hue;
  uint8_t saturation;
  uint16_t transitionTime;
} ZCL_ZllMoveToHueAndSaturationCommand_t;

/**
 * \brief MoveToHueAndSaturation command payload format
*/
typedef struct PACK _ZCL_ZllMoveToHueAndSaturationWithOptionsCommand_t
{
  uint8_t hue;
  uint8_t saturation;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveToHueAndSaturationWithOptionsCommand_t;

/**
 * \brief MoveToColor command payload format
*/
typedef struct PACK _ZCL_ZllMoveToColorCommand_t
{
  uint16_t colorX;
  uint16_t colorY;
  uint16_t transitionTime;
} ZCL_ZllMoveToColorCommand_t;

/**
 * \brief MoveToColor command payload format
*/
typedef struct PACK _ZCL_ZllMoveToColorWithOptionsCommand_t
{
  uint16_t colorX;
  uint16_t colorY;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveToColorWithOptionsCommand_t;

/**
 * \brief MoveColor command payload format
*/
typedef struct PACK _ZCL_ZllMoveColorCommand_t
{
  int16_t rateX;
  int16_t rateY;
} ZCL_ZllMoveColorCommand_t;

/**
 * \brief MoveColor command payload format
*/
typedef struct PACK _ZCL_ZllMoveColorWithOptionsCommand_t
{
  int16_t rateX;
  int16_t rateY;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveColorWithOptionsCommand_t;

/**
 * \brief MoveToColorTemperature command payload format
*/
typedef struct PACK _ZCL_ZllMoveToColorTemperatureCommand_t
{
  uint16_t colorTemperature;
  uint16_t transitionTime;
} ZCL_ZllMoveToColorTemperatureCommand_t;

/**
 * \brief MoveToColorTemperature command payload format
*/
typedef struct PACK _ZCL_ZllMoveToColorTemperatureWithOptionsCommand_t
{
  uint16_t colorTemperature;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveToColorTemperatureWithOptionsCommand_t;

/**
 * \brief StepColor command payload format
*/
typedef struct PACK _ZCL_ZllStepColorCommand_t
{
  int16_t stepX;
  int16_t stepY;
  uint16_t transitionTime;
} ZCL_ZllStepColorCommand_t;

/**
 * \brief StepColor command payload format
*/
typedef struct PACK _ZCL_ZllStepColorWithOptionsCommand_t
{
  int16_t stepX;
  int16_t stepY;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllStepColorWithOptionsCommand_t;

/**
 * \brief EnhancedMoveToHue command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedMoveToHueCommand_t
{
  uint16_t enhancedHue;
  uint8_t direction;
  uint16_t transitionTime;
} ZCL_ZllEnhancedMoveToHueCommand_t;

/**
 * \brief EnhancedMoveToHue command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedMoveToHueWithOptionsCommand_t
{
  uint16_t enhancedHue;
  uint8_t direction;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllEnhancedMoveToHueWithOptionsCommand_t;

/**
 * \brief EnhancedMoveHue command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedMoveHueCommand_t
{
  uint8_t moveMode;
  uint16_t rate;
} ZCL_ZllEnhancedMoveHueCommand_t;

/**
 * \brief EnhancedMoveHue command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedMoveHueWithOptionsCommand_t
{
  uint8_t moveMode;
  uint16_t rate;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllEnhancedMoveHueWithOptionsCommand_t;

/**
 * \brief EnhancedStepHue command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedStepHueCommand_t
{
  uint8_t stepMode;
  uint16_t stepSize;
  uint16_t transitionTime;
} ZCL_ZllEnhancedStepHueCommand_t;

/**
 * \brief EnhancedStepHue command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedStepHueWithOptionsCommand_t
{
  uint8_t stepMode;
  uint16_t stepSize;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllEnhancedStepHueWithOptionsCommand_t;

/**
 * \brief EnhancedMoveToHueAndSaturation command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t
{
  uint16_t enhancedHue;
  uint8_t saturation;
  uint16_t transitionTime;
} ZCL_ZllEnhancedMoveToHueAndSaturationCommand_t;

/**
 * \brief EnhancedMoveToHueAndSaturation command payload format
*/
typedef struct PACK _ZCL_ZllEnhancedMoveToHueAndSaturationWithOptionsCommand_t
{
  uint16_t enhancedHue;
  uint8_t saturation;
  uint16_t transitionTime;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllEnhancedMoveToHueAndSaturationWithOptionsCommand_t;

/**
 * \brief ColorLoopSet command payload format
*/
typedef struct PACK _ZCL_ZllColorLoopSetCommand_t
{
  uint8_t                  updateFlags;
  ZCL_ZllColorLoopAction_t action;
  uint8_t                  direction;
  uint16_t                 time;
  uint16_t                 startHue;
} ZCL_ZllColorLoopSetCommand_t;

/**
 * \brief ColorLoopSet command payload format
*/
typedef struct PACK _ZCL_ZllColorLoopSetWithOptionsCommand_t
{
  uint8_t                  updateFlags;
  ZCL_ZllColorLoopAction_t action;
  uint8_t                  direction;
  uint16_t                 time;
  uint16_t                 startHue;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllColorLoopSetWithOptionsCommand_t;

/**
 * \brief MoveColorTemperature command payload format
*/
typedef struct PACK _ZCL_ZllMoveColorTemperatureCommand_t
{
  uint8_t  moveMode;
  uint16_t rate;
  uint16_t colorTemperatureMinimum;
  uint16_t colorTemperatureMaximum;
} ZCL_ZllMoveColorTemperatureCommand_t;

/**
 * \brief MoveColorTemperature command payload format
*/
typedef struct PACK _ZCL_ZllMoveColorTemperatureWithOptionsCommand_t
{
  uint8_t  moveMode;
  uint16_t rate;
  uint16_t colorTemperatureMinimum;
  uint16_t colorTemperatureMaximum;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllMoveColorTemperatureWithOptionsCommand_t;

/**
 * \brief StepColorTemperature command payload format
*/
typedef struct PACK _ZCL_ZllStepColorTemperatureCommand_t
{
  uint8_t  stepMode;
  uint16_t stepSize;
  uint16_t transitionTime;
  uint16_t colorTemperatureMinimum;
  uint16_t colorTemperatureMaximum;
} ZCL_ZllStepColorTemperatureCommand_t;

/**
 * \brief StepColorTemperature command payload format
*/
typedef struct PACK _ZCL_ZllStepColorTemperatureWithOptionsCommand_t
{
  uint8_t  stepMode;
  uint16_t stepSize;
  uint16_t transitionTime;
  uint16_t colorTemperatureMinimum;
  uint16_t colorTemperatureMaximum;
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllStepColorTemperatureWithOptionsCommand_t;

/**
 * \brief StopMoveStep with options command payload format
*/
typedef struct PACK _ZCL_ZllStopMoveStepWithOptionsCommand_t
{
  uint8_t optionsMask;
  uint8_t optionsOverride;
} ZCL_ZllStopMoveStepWithOptionsCommand_t;

/**
 *   \brief Color Control Cluster extension field set
 */
typedef struct PACK
{
  uint16_t clusterId;
  uint8_t  length;
  uint16_t currentX;
  uint16_t currentY;
  uint16_t enhancedCurrentHue;
  uint8_t  currentSaturation;
  uint8_t  colorLoopActive;
  uint8_t  colorLoopDirection;
  uint16_t colorLoopTime;
  uint16_t colorTemperature;
} ZCL_ColorControlClusterExtensionFieldSet_t;

END_PACK

/**
 * \brief Color Control cluster commands
 */
typedef struct _ZCL_ZllColorControlClusterCommands_t
{
   /* To Avoid linker error*/
   void *tempPtrE;
} ZCL_ColorControlClusterCommands_t;

#endif // _ZCLZLLCOLORCONTROLCLUSTER_H
