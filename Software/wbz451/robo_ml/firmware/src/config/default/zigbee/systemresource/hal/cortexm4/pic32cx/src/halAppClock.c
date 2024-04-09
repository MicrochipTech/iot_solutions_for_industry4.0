/*******************************************************************************
  HAL Application Clock Source File

  Company:
    Microchip Technology Inc.

  File Name:
    halAppClock.c

  Summary:
    This file contains the Implementation of appTimer hardware-dependent module.

  Description:
    This file contains the Implementation of appTimer hardware-dependent module.
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


/******************************************************************************
 *   WARNING: CHANGING THIS FILE MAY AFFECT CORE FUNCTIONALITY OF THE STACK.  *
 *   EXPERT USERS SHOULD PROCEED WITH CAUTION.                                *
 ******************************************************************************/

/******************************************************************************
                   Includes section
******************************************************************************/
#include "device.h"
#include <hal/cortexm4/pic32cx/include/halAppClock.h>
#include <hal/cortexm4/pic32cx/include/halMacIsr.h>

#include <systemenvironment/include/sysEvents.h>
#if defined(_STATS_ENABLED_)
#include <statStack.h>
#endif
#include <configserver/include/configserver.h>
#include <systemenvironment/include/sysAssert.h>

#include <definitions.h>
/******************************************************************************
                   Define(s) section
******************************************************************************/
 
 #define TC0_SYNCBUSY	TC0_REGS->COUNT16.TC_SYNCBUSY 				//TC_SYNCBUSY
 #define TC0_CTRLA 		TC0_REGS->COUNT16.TC_CTRLA					//TC_CTRLA
 #define TC0_16COUNT	TC0_REGS->COUNT16.TC_COUNT					//TC_COUNT
 #define TC0_CTRLBSET	TC0_REGS->COUNT16.TC_CTRLBSET				//TC_CTRLBSET
 #define TC0_CTRLBCLR	TC0_REGS->COUNT16.TC_CTRLBCLR				//TC_CTRLBCLR
 #define TC0_CC0		TC0_REGS->COUNT16.TC_CC[0]					//TC_CC[0]
 #define TC0_CC1		TC0_REGS->COUNT16.TC_CC[1]					//TC_CC[1]
 #define TC0_INTENSET	TC0_REGS->COUNT16.TC_INTENSET				//TC_INTENSET
 #define TC0_INTENCLR	TC0_REGS->COUNT16.TC_INTENCLR				//TC_INTENCLR
 #define TC0_INTFLAG	TC0_REGS->COUNT16.TC_INTFLAG				//TC_INTFLAG
 #define TC0_WAVE 		TC0_REGS->COUNT16.TC_WAVE					//TC_WAVE
 #define TC0_STATUS		TC0_REGS->COUNT16.TC_STATUS					//TC_STATUS

#define HAL_MIN_SLEEP_TIME_ALLOWED          (1)

/******************************************************************************
                   Prototypes section
******************************************************************************/
/******************************************************************************
  \brief Returns the time left value for the smallest app timer.
  \return time left for the smallest application timer.
******************************************************************************/
uint32_t halGetTimeToNextAppTimer(void);
static void smallestTimerRequestHandler(SYS_EventId_t eventId, SYS_EventData_t data);

/******************************************************************************
                     Global variables section
******************************************************************************/
static uint32_t halAppTime = 0ul;     // time of application timer
static uint32_t __attribute__((persistent)) backupHalAppTime;     // time of application timer
uint8_t halAppTimeOvfw = 0;
static volatile uint32_t halAppIrqCount = 0;

static SYS_EventReceiver_t appTimerEventListener = {.func = smallestTimerRequestHandler};



/******************************************************************************
                   Implementations section
******************************************************************************/
  /******************************************************************************
   Polling the Sync. flag for Software Reset 
   Parameters:
     none
   Returns:
     none
   *****************************************************************************/
INLINE void halTimerSWRSTSync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_SWRST_Msk);
}

/******************************************************************************
 Polling the Sync. flag for Enable 
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/
INLINE void halTimerEnableSync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_ENABLE_Msk);
}

/******************************************************************************
 Polling the Sync. flag for Clock Domain
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/
INLINE void halTimerClockSync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_STATUS_Msk);
}

/******************************************************************************
 Polling the Sync. flag for Count register 
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/
INLINE void halTimerCountSync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_COUNT_Msk);
}

/******************************************************************************
 Polling the Sync. flag for CC register 
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/

INLINE void halTimerCCSync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_CC0_Msk);
}
/******************************************************************************
 Polling the Sync. flag for CC1 register 
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/
INLINE void halTimerCC1Sync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_CC1_Msk);
}
/******************************************************************************
 Polling the Sync. flag for CTRLB register 
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/
INLINE void halTimerCTRLBSync(void)
{
  while(TC0_SYNCBUSY & TC_SYNCBUSY_CTRLB_Msk);
}

/******************************************************************************
 Interrupt handler signal implementation
 Parameters:
   none
 Returns:
   none
 *****************************************************************************/
INLINE void halInterruptAppClock(void)
{
  halAppIrqCount++;
  halPostTaskFromISR(HAL_APPTIMER);
  // infinity loop spy
  SYS_InfinityLoopMonitoring();
}

/******************************************************************************
 To get app clock elapsed time since last ISR
 Parameters:
   none
 Returns:
   elapsed time in us
 *****************************************************************************/
uint32_t halGetElapsedTimeFromAppClock(void)
{
  TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
  halTimerCTRLBSync();	
  uint16_t tcCount = TC0_16COUNT;
	
  return (tcCount * AMOUNT_NSEC_FOR_TIMER_CLOCK) /1000;
}

/**************************************************************************//**
\brief Takes account of the sleep interval.

\param[in]
  interval - time of sleep
******************************************************************************/
void halAdjustSleepInterval(uint32_t interval)
{
  halAppTime += interval;
  halPostTask(HAL_APPTIMER);
}

/**************************************************************************//**
Synchronization system time which based on application timer.
******************************************************************************/
void halAppSystemTimeSynchronize(void)
{
  uint32_t tmpCounter;
  uint32_t tmpValue = 0;

  ATOMIC_SECTION_ENTER
    tmpCounter = halAppIrqCount;
    halAppIrqCount = 0;
  ATOMIC_SECTION_LEAVE

  tmpValue = tmpCounter * HAL_APPTIMERINTERVAL;
  halAppTime += tmpValue;
  if (halAppTime < tmpValue)
    halAppTimeOvfw++;
}

// Only For testing
//#define PORTA_BASE 0x41008000
//#define PORTB_BASE 0x41008000 + 0x80
//#define PORTC_BASE PORTB_BASE + 0x80
//
//#define PORTA_OUTTGL	MMIO_REG(PORTA_BASE + 0x0C, uint32_t)
//#define PORTC_OUTTGL	MMIO_REG(PORTC_BASE + 0x0C, uint32_t)
/******************************************************************
time counter interrupt handler
 Parameters:
   none
 Returns:
   none
******************************************************************/

void TC0_Handler(TC_TIMER_STATUS status, uintptr_t context)
{
#if defined(_STATS_ENABLED_)
  uint16_t stack_threshold;
  uint16_t stack_left = Stat_GetCurrentStackLeft();
  CS_ReadParameter(CS_STACK_LEFT_THRESHOLD_ID,&stack_threshold);
  SYS_E_ASSERT_FATAL((stack_left>stack_threshold),TIMER_ISR_STACK_OVERFLOW);
#endif //(_STATS_ENABLED_)

 TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
 halTimerCTRLBSync();
 uint16_t tcCount = TC0_16COUNT;
 uint8_t intFlag = TC0_INTFLAG;
    
  if((status & TC_INTFLAG_MC0(1))&&(TC0_INTENSET & TC_INTENSET_MC0(1)))
  {
    // appTimer handling      
   TC0_INTFLAG = TC_INTFLAG_MC0(1);
   TC0_16COUNT = 0;
   halTimerCountSync();
   halInterruptAppClock();
  }
    
  if((status & TC_INTFLAG_MC1(1)) && (!(TC0_INTENSET & TC_INTENSET_MC1(1))))
  {
   TC0_INTFLAG = TC_INTFLAG_MC1(1);
  }
    
  if((status & TC_INTFLAG_MC1(1))&&(TC0_INTENSET & TC_INTENSET_MC1(1)))
  { 
   TC0_INTFLAG = TC_INTFLAG_MC1(1);//rTimerHandling
   TC0_CC1 = TC_COUNT16_CC_CC(0);
   halTimerCC1Sync();
   halMacTimerHandler();
  }
       
}


/******************************************************************
configure and enable timer counter channel 0
 Parameters:
   none
 Returns:
   none
******************************************************************/
void halStartAppClock(void)
{
  //MCLK_APBBMASK |= MCLK_APBBMASK_TC3;
  
  /*Configuring Peripheral - 26 TCC2, TC3 clock for GEN3 as source*/
  //GCLK_PCHCTRL(TCC2_GCLK_ID) = GCLK_PCHCTRL_GEN(GCLK_GEN_3) | GCLK_PCHCTRL_CHEN;
	
  TC0_CTRLA = 0;
  halTimerClockSync ();
  TC0_CTRLA = TC_CTRLA_SWRST_Msk;
  halTimerSWRSTSync();

  /* Prescaler DIV2 8Mhz / 8 = 1 Mhz
     Reload or reset the counter on next prescaler clock
    */
	
  uint32_t mode = TC_CTRLA_PRESCALER_DIV16 | TC_CTRLA_PRESCSYNC_PRESC | TC_CTRLA_RUNSTDBY(1);
  TC0_CTRLA = mode;
	
  halTimerClockSync();

  //TCC2_WAVE = TCC_WAVE_WAVEGEN_MFRQ;

  /*The TC will wrap around and run on the next underflow/overflow condition, counter count up*/
  TC0_CTRLBCLR = TC_CTRLBCLR_ONESHOT(1) | TC_CTRLBCLR_DIR(1);
  halTimerCTRLBSync();

  TC0_16COUNT =0;
  halTimerCountSync();

  // ((F_PERI/1000ul) / TIMER_FREQUENCY_PRESCALER(DIV8)) * HAL_APPTIMERINTERVAL (10 ms)
  TC0_CC0 = TC_COUNT16_CC_CC(TOP_TIMER_COUNTER_VALUE);
  halTimerCCSync();

  NVIC_DisableIRQ(TC0_IRQn);
  NVIC_ClearPendingIRQ(TC0_IRQn);
  NVIC_SetPriority(TC0_IRQn,7);
  TC0_INTENSET = TC_INTENSET_MC0(1);
  NVIC_EnableIRQ(TC0_IRQn);

  TC0_CTRLA |= TC_CTRLA_ENABLE(1);
  halTimerEnableSync();

  TC0_INTFLAG = TC_INTFLAG_MC1(1);

  SYS_SubscribeToEvent((SYS_EventId_t)BC_EVENT_MAX_SLEEP_TIME_REQUEST, &appTimerEventListener);

  // Call back register - TC0_handler function 
  TC0_TimerCallbackRegister( TC0_Handler, 0 );

}

/******************************************************************
disable timer
 Parameters:
   none
 Returns:
   none
******************************************************************/
void halStopAppClock(void)
{
  uint32_t elapsedTimeinUs = 0;

  /*compensate before stoping as it misses the time counted till this time from last 10 ms intterupt */
  elapsedTimeinUs = halGetElapsedTimeFromAppClock(); 
  halAppTime += elapsedTimeinUs/1000; //in ms

  /* Disable the clock */
  NVIC_DisableIRQ(TC0_IRQn);
  TC0_INTENCLR = TC_INTENCLR_MC0(1);// disabling interrupt MC0
  TC0_CTRLA &= ~TC_CTRLA_ENABLE(1);// Stop timer
  halTimerEnableSync();
}


/******************************************************************************
Return time of sleep timer.

Returns:
  time in ms.
******************************************************************************/
uint32_t halGetTimeOfAppTimer(void)
{
  halAppSystemTimeSynchronize();
  return halAppTime;
}

/**************************************************************************//**
\brief System clock.

\return
  system clock in Hz.
******************************************************************************/
uint32_t HAL_ReadFreq(void)
{
  return (uint32_t)CPU_CLK_HZ;
}

/******************************************************************************
 Delay in microseconds.
 Parameters:
   us - delay time in microseconds
******************************************************************************/
void halDelayUs(uint16_t us)
{
  uint32_t startCounter = 0;
  uint32_t delta = 0;

  us *= AMOUNT_TIMER_CLOCK_IN_ONE_USEC;
  // begin counter meaning

  TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
  halTimerCTRLBSync();
  startCounter = TC0_16COUNT;
  // different between compare regitser and current counter

  delta = TC0_CC0 - startCounter;

  if(delta > us)
  {
    TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
    halTimerCTRLBSync();
    while((TC0_16COUNT - startCounter ) < us)
   {
      TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
      halTimerCTRLBSync();
			
   }
  }
  else
  {
    us -= delta;
        TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
    halTimerCTRLBSync();
    while((TC0_16COUNT > startCounter ) || (TC0_16COUNT < us))
   {
     TC0_CTRLBSET |= TC_CTRLBCLR_CMD_READSYNC;
     halTimerCTRLBSync();
   }
  }

}
/**************************************************************************//**
  \brief Processes BC_EVENT_MAX_SLEEP_TIME_REQUEST request

  \param[in] eventId - id of raised event;
  \param[in] data    - event's data
 ******************************************************************************/
static void smallestTimerRequestHandler(SYS_EventId_t eventId, SYS_EventData_t data)
{
  uint32_t *minValue = (uint32_t *)data;
  uint32_t timeToFire = halGetTimeToNextAppTimer();

  if (*minValue <= HAL_MIN_SLEEP_TIME_ALLOWED)
  {
    *minValue = 0;
    return;
  }

  if (*minValue > timeToFire)
  {
    if (timeToFire > HAL_MIN_SLEEP_TIME_ALLOWED)
      *minValue = timeToFire;
    else
      *minValue = 0;
  }
  (void)eventId;
}
/**************************************************************************//**
\brief Takes backup of current sys time

\param[in]
  interval - time of sleep
******************************************************************************/
void halBackupSystemTime(void)
{
   backupHalAppTime = halGetTimeOfAppTimer();
}


/**************************************************************************//**
\brief restoring of current sys time

\param[in]
  interval - time of sleep
******************************************************************************/
void halRestoreSystemTime(void)
{
   halAppTime = backupHalAppTime;
}


// eof halAppClock.c