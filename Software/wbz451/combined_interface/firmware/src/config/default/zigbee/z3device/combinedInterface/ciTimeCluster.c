/*******************************************************************************
 Combined interface time cluster Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ciTimeCluster.c

  Summary:
    This file contains the Combined interface time cluster interface.

  Description:
    This file contains the Combined interface time cluster interface.
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

/******************************************************************************
                    Includes section
******************************************************************************/
#include <z3device/common/include/appConsts.h>
#include <z3device/combinedInterface/include/ciTimeCluster.h>
#include <zcl/include/zclCommandManager.h>
#include <z3device/clusters/include/haClusters.h>
#include <zcl/include/zclAttributes.h>
#include <app_zigbee/zigbee_console/console.h>
#include <app_zigbee/app_zigbee_handler.h>
/******************************************************************************
                    Defines section
******************************************************************************/
#define ONE_SEC_TIME                     1000L
#define UTCTIME_START_YEAR               2000L
#define NO_OF_SECONDS_PER_MIN            60L
#define NO_OF_SECONDS_PER_HOUR           3600L
#define NO_OF_SECONDS_PER_DAY            (NO_OF_SECONDS_PER_HOUR*24)
#define NO_OF_SECONDS_PER_YEAR           (NO_OF_SECONDS_PER_DAY*365)
#define NO_OF_SECONDS_PER_LEAP_YEAR      (NO_OF_SECONDS_PER_DAY*366)
#define NO_OF_LEAP_PER_HUNDRED_YRS       24L
// UTC + 5:30
#define TIME_ZONE_INDIA                  ((NO_OF_SECONDS_PER_HOUR*5) + (NO_OF_SECONDS_PER_MIN*30))
#define TIME_STATUS_ATTR_MASK            0x02
#define INIT_UTC_TIME                    { .date = 12,\
                                           .month = 12,\
                                           .year = 2012,\
                                           .hour = 00,\
                                           .minute = 00,\
                                           .seconds = 00\
                                         }
/******************************************************************************
                   Prototypes section
******************************************************************************/
static void timeUpdateClockTime(void);
static bool timeIsLeapYear(uint16_t year);
static void timeClusterEventListener(SYS_EventId_t eventId, SYS_EventData_t data);
static void ciTimeAttrEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event);
/******************************************************************************
                    Global variables
******************************************************************************/
ZCL_TimeClusterServerAttributes_t ciTimeClusterServerAttributes =
{
  ZCL_DEFINE_TIME_CLUSTER_SERVER_ATTRIBUTES()
};
static SYS_EventReceiver_t ciTimeEventReceiver = {.func = timeClusterEventListener};
uint8_t dstUpdatedInLocalTime = 0;
/******************************************************************************
                    Local variables
******************************************************************************/
static HAL_AppTimer_t clockTimeTimer;
/******************************************************************************
                    Implementation section
******************************************************************************/
/**************************************************************************//**
\brief Initializes Time cluster
******************************************************************************/
void ciTimeClusterInit(void)
{
  dateTime_t dateTimeInit = INIT_UTC_TIME;
  
  ZCL_Cluster_t *cluster = ZCL_GetCluster(APP_ENDPOINT_COMBINED_INTERFACE, TIME_CLUSTER_ID, ZCL_CLUSTER_SIDE_SERVER);
  ZCL_Cluster_t *timeCluster = ZCL_GetCluster(APP_ENDPOINT_COMBINED_INTERFACE, TIME_CLUSTER_ID, ZCL_CLUSTER_SIDE_CLIENT);
  ciTimeClusterServerAttributes.clusterVersion.value = TIME_CLUSTER_VERSION;
  if (cluster)
  {
    cluster->ZCL_AttributeEventInd = ciTimeAttrEventInd;
  }
  ciTimeClusterServerAttributes.time.value = CCPU_TO_LE16(timeCalculateUTCTime(&dateTimeInit));
  ciTimeClusterServerAttributes.timeStatus.value.master = TIME_SERVER_MASTER;
  ciTimeClusterServerAttributes.timeStatus.value.masterZoneDst = TIME_SERVER_MASTER_ZONE_DST;
  ciTimeClusterServerAttributes.timeStatus.value.synchronized = 0;
  ciTimeClusterServerAttributes.timeStatus.value.superseding = 0;
  ciTimeClusterServerAttributes.timeStatus.value.reserved = 0;
  // Since the master bit is set change the time attribute as READONLY.
  ciTimeClusterServerAttributes.time.properties |= ZCL_READONLY_ATTRIBUTE;
  // Since the masterZoneDst bit is set change zone and Dst attributes as READONLY.
  ciTimeClusterServerAttributes.timeZone.properties |= ZCL_READONLY_ATTRIBUTE;
  ciTimeClusterServerAttributes.dstStart.properties |= ZCL_READONLY_ATTRIBUTE;
  ciTimeClusterServerAttributes.dstEnd.properties |= ZCL_READONLY_ATTRIBUTE;
  ciTimeClusterServerAttributes.dstShift.properties |= ZCL_READONLY_ATTRIBUTE;
  ciTimeClusterServerAttributes.timeZone.value = CCPU_TO_LE16(TIME_ZONE_INDIA);
  ciTimeClusterServerAttributes.dstStart.value = CCPU_TO_LE16(ZCL_TIME_CLUSTER_DEF_INVALID_VALUE);
  ciTimeClusterServerAttributes.dstEnd.value = CCPU_TO_LE16(ZCL_TIME_CLUSTER_DEF_INVALID_VALUE);
  ciTimeClusterServerAttributes.dstShift.value = CCPU_TO_LE16(ZCL_TIME_CLUSTER_DEF_ZERO_VALUE);
  ciTimeClusterServerAttributes.standardTime.value = CCPU_TO_LE16(timeGetStandardTime());
  // no day light saving hence local time is standard time
  ciTimeClusterServerAttributes.localTime.value = CCPU_TO_LE16(timeGetStandardTime());
  // no update required for local time
  dstUpdatedInLocalTime = true;
  ciTimeClusterServerAttributes.lastSetTime.value = ciTimeClusterServerAttributes.time.value;
  ciTimeClusterServerAttributes.validUntilTime.value = CCPU_TO_LE16(ZCL_TIME_CLUSTER_DEF_INVALID_VALUE);
  //start a timer to update the time value
  // if a RTC is used, this shall be removed
  clockTimeTimer.interval = ONE_SEC_TIME;
  clockTimeTimer.mode = TIMER_REPEAT_MODE;
  clockTimeTimer.callback = timeUpdateClockTime;
  HAL_StartAppTimer(&clockTimeTimer);

  SYS_SubscribeToEvent(BC_ZCL_EVENT_ACTION_REQUEST, &ciTimeEventReceiver);
  if(timeCluster)
    timeCluster->ZCL_DefaultRespInd = ZCL_CommandZclDefaultResp;
}

/**************************************************************************//**
\brief Update time, standard and local time

\param NA
******************************************************************************/
static void timeUpdateClockTime(void)
{
  ciTimeClusterServerAttributes.time.value += 1;
  ciTimeClusterServerAttributes.standardTime.value += 1;

  if(dstUpdatedInLocalTime)
  {
    ciTimeClusterServerAttributes.localTime.value += 1;
    if(ciTimeClusterServerAttributes.time.value >= ciTimeClusterServerAttributes.dstEnd.value)
    {
      ciTimeClusterServerAttributes.localTime.value = timeGetStandardTime();
    }
  }
  else
  {
    timeUpdateLocalTimeForDst();
  }
}
/**************************************************************************//**
\brief find whether an year is leap year or not 

\param year
******************************************************************************/
static bool timeIsLeapYear(uint16_t year)
{
  if (year%400 == 0)
    return true;
  else if (year%100 == 0)
    return false;
  else if (year%4 == 0)
    return true;
  else
    return false;
}
/**************************************************************************//**
\brief Number of leap years from 2000 till given year

\param start year, end year
******************************************************************************/
static uint8_t timeCountNoOfLeapYears(uint16_t currYear)
{
  // UTCTIME_START_YEAR is a leap year
  uint16_t noOfLeapYears = 0x0001;
  uint16_t noOfYears;
  uint16_t temp;

  if(currYear < UTCTIME_START_YEAR)
    return 0;

  noOfYears = currYear - UTCTIME_START_YEAR;
  if(noOfYears >= 100)
  {
    temp = noOfYears/100;
    noOfLeapYears += temp * NO_OF_LEAP_PER_HUNDRED_YRS;
  }
  if(noOfYears >= 400)
  {
    temp = noOfYears/400;
    // Every 100th year is not leap year unless it is divided by 400
    // hence for every 400 years there are 3 years divisible by 100 but not leap years
    noOfLeapYears += temp;
  }
  temp = noOfYears%100;
  noOfLeapYears += temp/4;

  return noOfLeapYears;
}
/**************************************************************************//**
\brief find UTCTime - the no of seconds elapsed since  
                      0hrs 0mins 0secs of 1st January,2000
\param pointer to dateTime structure
******************************************************************************/
uint32_t timeCalculateUTCTime(dateTime_t* dateTime)
{
  uint16_t i = 0;
  uint32_t utcTime = 0;
  //UTCTime data type mentioned in cluster specification starts by 2000
  if(dateTime->year < UTCTIME_START_YEAR)
    return ZCL_TIME_CLUSTER_DEF_ZERO_VALUE;
   
  utcTime = (NO_OF_SECONDS_PER_YEAR * (dateTime->year - UTCTIME_START_YEAR));
  utcTime += NO_OF_SECONDS_PER_DAY * timeCountNoOfLeapYears(dateTime->year - 1);
  for(i = MONTH_JANUARY; i< dateTime->month; i++)
  {
    switch(i)
    {
      case MONTH_JANUARY:
      case MONTH_MARCH:
      case MONTH_MAY:
      case MONTH_JULY:
      case MONTH_AUGUST:
      case MONTH_OCTOBER:
      case MONTH_DECEMBER:
        utcTime += NO_OF_SECONDS_PER_DAY * 31;
        break;
      case MONTH_APRIL:
      case MONTH_JUNE:
      case MONTH_SEPTEMBER:
      case MONTH_NOVEMBER:
        utcTime += NO_OF_SECONDS_PER_DAY * 30;
        break;
      case MONTH_FEBRUARY:
        {
          if(timeIsLeapYear(dateTime->year))
            utcTime += NO_OF_SECONDS_PER_DAY * 29;
          else
            utcTime += NO_OF_SECONDS_PER_DAY * 28;
          break;
        }
      default:
        break;
     }
   }
  utcTime += ((dateTime->date - 1) * NO_OF_SECONDS_PER_DAY) + (dateTime->hour * NO_OF_SECONDS_PER_HOUR) +
             (dateTime->minute * NO_OF_SECONDS_PER_MIN) + dateTime->seconds;
  return utcTime;
}
/**************************************************************************//**
\brief to get the standard time considering time and timeZone
\param none
******************************************************************************/
inline uint32_t timeGetStandardTime(void)
{
  return (ciTimeClusterServerAttributes.time.value + ciTimeClusterServerAttributes.timeZone.value);
}
/**************************************************************************//**
\brief to get the local time considering time, timeZone and DST
\param none
******************************************************************************/
void timeUpdateLocalTimeForDst(void)
{
  if(dstUpdatedInLocalTime)
    return;
  if(ciTimeClusterServerAttributes.time.value >= ciTimeClusterServerAttributes.dstStart.value &&
       ciTimeClusterServerAttributes.time.value <= ciTimeClusterServerAttributes.dstEnd.value)
  {

     // time is in the day light saving period local time needs to be shifted
     ciTimeClusterServerAttributes.localTime.value = ciTimeClusterServerAttributes.dstShift.value +
                                                     timeGetStandardTime();
     dstUpdatedInLocalTime = true;
  }
  else
     ciTimeClusterServerAttributes.localTime.value = timeGetStandardTime();
}
/**************************************************************************//**
\brief to read the UTCTime
\param none
******************************************************************************/
uint32_t timeReadTimeAttribute(void)
{
  return ciTimeClusterServerAttributes.time.value;
}
/**************************************************************************//**
\brief set the UTCTime
\param date and time
******************************************************************************/
void timeSetTimeAttribute(dateTime_t setDateTime)
{
  ciTimeClusterServerAttributes.time.value = timeCalculateUTCTime(&setDateTime);
  // store the current time in last set time
  ciTimeClusterServerAttributes.lastSetTime.value = ciTimeClusterServerAttributes.time.value;
  ciTimeClusterServerAttributes.standardTime.value = timeGetStandardTime();
  dstUpdatedInLocalTime = false;
  // local time
  timeUpdateLocalTimeForDst();
}
/**************************************************************************//**
\brief  set the time status attribute bits
\param master - true if the server is the master
       synchronized - true if the time is synchronized with the network
       masterZoneDST - true if the server is the master for timeZone and DST
       Superseding - true if the server shall be choosen as best among other servers
******************************************************************************/
void timeSetTimeStatus(bool master, bool synchronized, bool masterZoneDst, bool superseding)
{
  ciTimeClusterServerAttributes.timeStatus.value.master = master;
  // Since the master bit is set change time attribute as READONLY.
  if(master == true)
  {
    ciTimeClusterServerAttributes.timeStatus.value.synchronized = false;
    ciTimeClusterServerAttributes.time.properties |= ZCL_READONLY_ATTRIBUTE;
  }
  else
  {
    ciTimeClusterServerAttributes.time.properties &= ~ZCL_READONLY_ATTRIBUTE; 
    ciTimeClusterServerAttributes.timeStatus.value.synchronized = synchronized;
  }
  
  ciTimeClusterServerAttributes.timeStatus.value.masterZoneDst = masterZoneDst;
  // Since the masterZoneDst bit is set change zone and Dst attributes as READONLY.
  if(masterZoneDst == true)
  {
    ciTimeClusterServerAttributes.timeZone.properties |= ZCL_READONLY_ATTRIBUTE;
    ciTimeClusterServerAttributes.dstStart.properties |= ZCL_READONLY_ATTRIBUTE;
    ciTimeClusterServerAttributes.dstEnd.properties |= ZCL_READONLY_ATTRIBUTE;
    ciTimeClusterServerAttributes.dstShift.properties |= ZCL_READONLY_ATTRIBUTE;
  }
  else
  {
    ciTimeClusterServerAttributes.timeZone.properties &= ~ ZCL_READONLY_ATTRIBUTE;
    ciTimeClusterServerAttributes.dstStart.properties &= ~ZCL_READONLY_ATTRIBUTE;
    ciTimeClusterServerAttributes.dstEnd.properties &= ~ZCL_READONLY_ATTRIBUTE;
    ciTimeClusterServerAttributes.dstShift.properties &= ~ZCL_READONLY_ATTRIBUTE;
  }
  ciTimeClusterServerAttributes.timeStatus.value.superseding = superseding;  
}
/**************************************************************************//**
\brief set the time zone and DST attributes
\param timeZone, dstStart, dstEnd and dstShift in seconds
******************************************************************************/
void timeSetTimezoneAndDSTAttributes(int32_t timeZone, uint32_t dstStart, uint32_t dstEnd, int32_t dstShift)
{
  ciTimeClusterServerAttributes.timeZone.value = timeZone;
  ciTimeClusterServerAttributes.dstStart.value = dstStart;
  ciTimeClusterServerAttributes.dstEnd.value   = dstEnd;
  ciTimeClusterServerAttributes.dstShift.value = dstShift;

  if(ciTimeClusterServerAttributes.dstStart.value == ZCL_TIME_CLUSTER_DEF_INVALID_VALUE ||
   ciTimeClusterServerAttributes.dstEnd.value == ZCL_TIME_CLUSTER_DEF_INVALID_VALUE ||
   ciTimeClusterServerAttributes.dstShift.value == ZCL_TIME_CLUSTER_DEF_ZERO_VALUE )
  {
    dstUpdatedInLocalTime = true;
  }
  else
  {
    dstUpdatedInLocalTime = false;
  }
}
/**************************************************************************//**
\brief Attribute Event indication handler(to indicate when attr values have
        read or written)

\param[in] addressing - pointer to addressing information;
\param[in] reportLength - data payload length;
\param[in] reportPayload - data pointer
******************************************************************************/
static void ciTimeAttrEventInd(ZCL_Addressing_t *addressing, ZCL_AttributeId_t attributeId, ZCL_AttributeEvent_t event)
{
  APP_Zigbee_Event_t eventItem;
  eventItem.eventGroup = EVENT_CLUSTER;
  eventItem.eventId = CMD_ZCL_ATTR_TIME;
  eventItem.eventData.zclAttributeData.addressing = addressing;
  eventItem.eventData.zclAttributeData.attributeId = attributeId;
  eventItem.eventData.zclAttributeData.event = event;

  if(attributeId == ZCL_TIME_CLUSTER_SERVER_TIME_ATTRIBUTE_ID && event == ZCL_WRITE_ATTRIBUTE_EVENT)
  {
    ciTimeClusterServerAttributes.lastSetTime.value = ciTimeClusterServerAttributes.time.value;
    ciTimeClusterServerAttributes.standardTime.value = timeGetStandardTime();
    dstUpdatedInLocalTime = false;
    // local time
    timeUpdateLocalTimeForDst(); 
  }
  APP_Zigbee_Handler(eventItem);
}
/**************************************************************************//**
  \brief  ZCL action request event handler, 
          handles the ZCL_ACTION_WRITE_ATTR_REQUEST for attribute specific validation

  \param[in] ev - must be BC_ZCL_EVENT_ACTION_REQUEST.
  \param[in] data - this field must contain pointer to the BcZCLActionReq_t structure,

  \return None.
 ******************************************************************************/
static void timeClusterEventListener(SYS_EventId_t eventId, SYS_EventData_t data)
{
  BcZCLActionReq_t *const actionReq = (BcZCLActionReq_t*)data;
  int16_t requestedValue = 0;
  if (BC_ZCL_EVENT_ACTION_REQUEST == eventId && ZCL_ACTION_WRITE_ATTR_REQUEST == actionReq->action)
  {
     ZCLActionWriteAttrReq_t *const zclWriteAttrReq = (ZCLActionWriteAttrReq_t*)actionReq->context;
     if((TIME_CLUSTER_ID != zclWriteAttrReq->clusterId) || 
              (ZCL_CLUSTER_SIDE_SERVER != zclWriteAttrReq->clusterSide))
     {
       return;
     }
     actionReq->denied = 0U;
     switch(zclWriteAttrReq->attrId)
     {
       case ZCL_TIME_CLUSTER_SERVER_TIME_ATTRIBUTE_ID:
       {
         if(ciTimeClusterServerAttributes.timeStatus.value.master == true ||
            ciTimeClusterServerAttributes.timeStatus.value.superseding == true)
           actionReq->denied = 1U;
       }
         break;
       case ZCL_TIME_CLUSTER_SERVER_TIME_STATUS_ATTRIBUTE_ID:
       { 
         requestedValue = *((int8_t*)(zclWriteAttrReq->attrValue));
         //Allow to write only the synchronized bit if the master bit is 0
         if(!ciTimeClusterServerAttributes.timeStatus.value.master && 
            (requestedValue == 0x00 || requestedValue == 0x02))
         {
           *((int8_t*)(zclWriteAttrReq->attrValue)) |= ciTimeClusterServerAttributes.timeStatus.value.masterZoneDst |
                                                       ciTimeClusterServerAttributes.timeStatus.value.superseding;
         }
         else
           actionReq->denied = 1U;
       }
         break;
     default:
         break;
      }
    } 
}
#endif // APP_DEVICE_TYPE_COMBINED_INTERFACE

// eof ciTimeCluster.c
