/*******************************************************************************
  ZCL ZCC CUSTOM Cluster Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zclArmorientationcluster0Cluster.h

  Summary:
    The header file describes the ZCL CUSTOM Cluster and its interface.

  Description:
    The file describes the types and interface of the ZCL CUSTOM Cluster.
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

#ifndef _ZCLARMORIENTATIONCLUSTER0_H
#define _ZCLARMORIENTATIONCLUSTER0_H

/*******************************************************************************
                   Includes section
*******************************************************************************/

#include <zcl/include/zcl.h>
#include <zcl/include/clusters.h>
/******************************************************************************
                    Define(s) section
******************************************************************************/
    
//ATTRIBUTE DEFINITION SECTION


#define ARMORIENTATIONCLUSTER0_CLUSTER_ID                                                     0xfc00

#define ZCL_ARMORIENTATIONCLUSTER0_SERVER_ATTRIBUTES_AMOUNT                      2
#define ZCL_ARMORIENTATIONCLUSTER0_SERVER_COMMANDS_AMOUNT                        2 

#define ZCL_ARMORIENTATIONCLUSTER0_CLIENT_ATTRIBUTES_AMOUNT                      2
#define ZCL_ARMORIENTATIONCLUSTER0_CLIENT_COMMANDS_AMOUNT                        2

//Attribute IDs
#define ZCL_ARMORIENTATIONCLUSTER0_ARMORIENTATIONSERVERATTRIBUTE_SERVER_ATTRIBUTE_ID CCPU_TO_LE16(0X0)
#define ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTSERVERATTRIBUTE_SERVER_ATTRIBUTE_ID CCPU_TO_LE16(0X1)

#define ZCL_ARMORIENTATIONCLUSTER0_ARMORIENATATIONCLIENTATTRIBUTE_CLIENT_ATTRIBUTE_ID CCPU_TO_LE16(0X1)
#define ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTCLIENTATTRIBUTE_CLIENT_ATTRIBUTE_ID CCPU_TO_LE16(0X1)

#define ZCL_DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER_SERVER_ATTRIBUTES(min,max) \
        DEFINE_REPORTABLE_ATTRIBUTE(Armorientationserverattribute, ZCL_READONLY_ATTRIBUTE, ZCL_ARMORIENTATIONCLUSTER0_ARMORIENTATIONSERVERATTRIBUTE_SERVER_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID, min, max) , \
        DEFINE_REPORTABLE_ATTRIBUTE(Armmovementserverattribute, ZCL_READONLY_ATTRIBUTE, ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTSERVERATTRIBUTE_SERVER_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID, min, max) 

#define ZCL_DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER_CLIENT_ATTRIBUTES(min,max) \
        DEFINE_REPORTABLE_ATTRIBUTE(Armorienatationclientattribute, ZCL_READONLY_ATTRIBUTE, ZCL_ARMORIENTATIONCLUSTER0_ARMORIENATATIONCLIENTATTRIBUTE_CLIENT_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID, min, max) , \
        DEFINE_REPORTABLE_ATTRIBUTE(Armmovementclientattribute, ZCL_READONLY_ATTRIBUTE, ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTCLIENTATTRIBUTE_CLIENT_ATTRIBUTE_ID, ZCL_8BIT_ENUM_DATA_TYPE_ID, min, max) 



#define ARMORIENTATIONCLUSTER0_CLUSTER_ZCL_SERVER_CLUSTER_TYPE(clattributes, clcommands)                                                \
  {                                                                                                              \
    .id = ARMORIENTATIONCLUSTER0_CLUSTER_ID,                                                                                      \
    .options = {.type = ZCL_SERVER_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},                  \
    .attributesAmount = ZCL_ARMORIENTATIONCLUSTER0_SERVER_ATTRIBUTES_AMOUNT,                                              \
    .attributes = (uint8_t *) clattributes,                                                                      \
    .commandsAmount = ZCL_ARMORIENTATIONCLUSTER0_SERVER_COMMANDS_AMOUNT,                                                  \
    .commands = (uint8_t *)clcommands                                                                            \
  }

#define ARMORIENTATIONCLUSTER0_CLUSTER_ZCL_CLIENT_CLUSTER_TYPE(clattributes, clcommands)                                                \
  {                                                                                                              \
    .id = ARMORIENTATIONCLUSTER0_CLUSTER_ID,                                                                                      \
    .options = {.type = ZCL_CLIENT_CLUSTER_TYPE, .security = ZCL_NETWORK_KEY_CLUSTER_SECURITY},                  \
    .attributesAmount = ZCL_ARMORIENTATIONCLUSTER0_CLIENT_ATTRIBUTES_AMOUNT,                                              \
    .attributes = (uint8_t *) clattributes,                                                                      \
    .commandsAmount = ZCL_ARMORIENTATIONCLUSTER0_CLIENT_COMMANDS_AMOUNT,                                                  \
    .commands = (uint8_t *)clcommands                                                                            \
  }


  #define DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER(cltype, clattributes, clcommands) \
    ARMORIENTATIONCLUSTER0_CLUSTER_##cltype(clattributes, clcommands)


// ATTRIBUTE DEFINITION END
//COMMAND DEFINITION SECTION

//Server Commands
#define ZCL_ARMORIENTATIONCLUSTER0_ARMORIENTATIONSERVERCOMMAND_COMMAND_ID        0x0
#define ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTSERVERCOMMAND_COMMAND_ID           0x1

//Client Commands
#define ZCL_ARMORIENTATIONCLUSTER0_ARMORIENATATIONCLIENTCOMMAND_COMMAND_ID       0x0
#define ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTCLIENTCOMMAND_COMMAND_ID           0x1

#define ZCL_DEFINE_ARMORIENTATIONCLUSTER0_CLUSTER_COMMANDS(\
        ArmorientationservercommandCommandInd , \
        ArmmovementservercommandCommandInd , \
        ArmorienatationclientcommandCommandInd , \
        ArmmovementclientcommandCommandInd ) \
    DEFINE_COMMAND(ArmorientationservercommandCommand, ZCL_ARMORIENTATIONCLUSTER0_ARMORIENTATIONSERVERCOMMAND_COMMAND_ID,  \
        COMMAND_OPTIONS(SERVER_TO_CLIENT , ZCL_THERE_IS_RELEVANT_RESPONSE , ZCL_COMMAND_NO_ACK), ArmorientationservercommandCommandInd), \
    DEFINE_COMMAND(ArmmovementservercommandCommand, ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTSERVERCOMMAND_COMMAND_ID,  \
        COMMAND_OPTIONS(SERVER_TO_CLIENT , ZCL_THERE_IS_RELEVANT_RESPONSE , ZCL_COMMAND_NO_ACK), ArmmovementservercommandCommandInd), \
    DEFINE_COMMAND(ArmorienatationclientcommandCommand, ZCL_ARMORIENTATIONCLUSTER0_ARMORIENATATIONCLIENTCOMMAND_COMMAND_ID,  \
        COMMAND_OPTIONS(CLIENT_TO_SERVER , ZCL_THERE_IS_RELEVANT_RESPONSE , ZCL_COMMAND_NO_ACK), ArmorienatationclientcommandCommandInd), \
    DEFINE_COMMAND(ArmmovementclientcommandCommand, ZCL_ARMORIENTATIONCLUSTER0_ARMMOVEMENTCLIENTCOMMAND_COMMAND_ID,  \
        COMMAND_OPTIONS(CLIENT_TO_SERVER , ZCL_THERE_IS_RELEVANT_RESPONSE , ZCL_COMMAND_NO_ACK), ArmmovementclientcommandCommandInd)
    


/******************************************************************************
                    Types section
******************************************************************************/
//ATTRIBUTE's TYPES SECTION
typedef enum _ZCL_Armorientationcluster0ArmorientationserverattributeEnum_t
{
    ARMORIENTATIONCLUSTER0_ARMORIENTATIONSERVERATTRIBUTE_0 = 0x00
}ZCL_Armorientationcluster0ArmorientationserverattributeEnum_t;

typedef enum _ZCL_Armorientationcluster0ArmmovementserverattributeEnum_t
{
    ARMORIENTATIONCLUSTER0_ARMMOVEMENTSERVERATTRIBUTE_1 = 0x00
}ZCL_Armorientationcluster0ArmmovementserverattributeEnum_t;

typedef enum _ZCL_Armorientationcluster0ArmorienatationclientattributeEnum_t
{
    ARMORIENTATIONCLUSTER0_ARMORIENATATIONCLIENTATTRIBUTE_0 = 0x00
}ZCL_Armorientationcluster0ArmorienatationclientattributeEnum_t;

typedef enum _ZCL_Armorientationcluster0ArmmovementclientattributeEnum_t
{
    ARMORIENTATIONCLUSTER0_ARMMOVEMENTCLIENTATTRIBUTE_1 = 0x00
}ZCL_Armorientationcluster0ArmmovementclientattributeEnum_t;



typedef struct PACK
{
struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint8_t             value;
    ZCL_ReportTime_t    reportCounter;     //!<For internal use only
    ZCL_ReportTime_t    minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t    maxReportInterval; //!<Maximum reporting interval field value
    uint8_t              reportableChange;  //!<Reporting change field value
    ZCL_ReportTime_t    timeoutPeriod;     //!<Timeout period field value
    uint8_t              lastReportedValue; //!<Last reported value
   } Armorientationserverattribute;

struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint8_t             value;
    ZCL_ReportTime_t    reportCounter;     //!<For internal use only
    ZCL_ReportTime_t    minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t    maxReportInterval; //!<Maximum reporting interval field value
    uint8_t              reportableChange;  //!<Reporting change field value
    ZCL_ReportTime_t    timeoutPeriod;     //!<Timeout period field value
    uint8_t              lastReportedValue; //!<Last reported value
   } Armmovementserverattribute;

}ZCL_Armorientationcluster0ClusterServerAttributes_t;

typedef struct PACK
{
struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint8_t             value;
    ZCL_ReportTime_t    reportCounter;     //!<For internal use only
    ZCL_ReportTime_t    minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t    maxReportInterval; //!<Maximum reporting interval field value
    uint8_t             reportableChange;  //!<Reporting change field value
    ZCL_ReportTime_t    timeoutPeriod;     //!<Timeout period field value
    uint8_t             lastReportedValue; //!<Last reported value
   } Armorienatationclientattribute;

struct PACK
  {
    ZCL_AttributeId_t   id;
    uint8_t             type;
    uint8_t             properties;
    uint8_t             value;
    ZCL_ReportTime_t    reportCounter;     //!<For internal use only
    ZCL_ReportTime_t    minReportInterval; //!<Minimum reporting interval field value
    ZCL_ReportTime_t    maxReportInterval; //!<Maximum reporting interval field value
    uint8_t             reportableChange;  //!<Reporting change field value
    ZCL_ReportTime_t    timeoutPeriod;     //!<Timeout period field value
    uint8_t             lastReportedValue; //!<Last reported value
   } Armmovementclientattribute;

}ZCL_Armorientationcluster0ClusterClientAttributes_t;


// COMMANDS TYPE DEFINITION
typedef struct 
{
    //Fill enum here
} ZCL_ZCC0_CUSTOM_CLUSTER_SERVER_COMMANDS_NAME_0ArmorientationserverparamCommandEnum_t;

typedef struct 
{
    //Fill enum here
} ZCL_ZCC0_CUSTOM_CLUSTER_SERVER_COMMANDS_NAME_1ArmmovementserverparamCommandEnum_t;


typedef struct 
{
    //Fill enum here
} ZCL_ArmorientationservercommandArmorientationserverparamCommandEnum_t;

typedef struct 
{
    //Fill enum here
} ZCL_ArmmovementservercommandArmmovementserverparamCommandEnum_t;


typedef struct PACK
{
        uint8_t Armorientationserverparam;

}ZCL_Armorientationservercommand_t;

typedef struct PACK
{
        uint8_t Armmovementserverparam;

}ZCL_Armmovementservercommand_t;


typedef struct PACK
{
        uint8_t Armorienatationclientparam;

}ZCL_Armorienatationclientcommand_t;

typedef struct PACK
{
        uint8_t Armmovementserverparam;

}ZCL_Armmovementclientcommand_t;


typedef struct
{
struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*ArmorientationservercommandCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armorientationservercommand_t *payload);
  } ArmorientationservercommandCommand;

struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*ArmmovementservercommandCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armmovementservercommand_t *payload);
  } ArmmovementservercommandCommand;


struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*ArmorienatationclientcommandCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armorienatationclientcommand_t *payload);
  } ArmorienatationclientcommandCommand;

struct
  {
    ZCL_CommandId_t id;
    ZclCommandOptions_t options;
    ZCL_Status_t(*ArmmovementclientcommandCommand)(ZCL_Addressing_t *addressing, uint8_t payloadLength, ZCL_Armmovementclientcommand_t *payload);
  } ArmmovementclientcommandCommand;


} ZCL_Armorientationcluster0ClusterCommands_t;

#endif
