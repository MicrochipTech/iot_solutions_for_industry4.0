/*******************************************************************************
  System utilities Source File

  Company:
    Microchip Technology Inc.

  File Name:
    sysUtils.c

  Summary:
    This file contains functions for system utilities

  Description:
    This file contains the functions for random seeding and getting random number.
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
                                   Include section
******************************************************************************/
#include <systemenvironment/include/sysUtils.h>
#include <mac_phy/include/rfRandom.h>
#include <hal/include/appTimer.h>
#include <mac_phy/include/macEnvironment.h>
#include <configserver/include/configserver.h>
#include <limits.h>
#ifdef __XC32__
#include <xc.h>
#endif
/******************************************************************************
                        Definitions section
******************************************************************************/
#define SYS_UPDATE_RAND_SEED_TIMEOUT  1000u
#define SYS_VERSION_ZERO_ASCII                    48
#define SYS_VERSION_P_ASCII                       80
#define SYS_VERSION_M_ASCII                       77
#define SYS_VERSION_E_ASCII                       69
#define SYS_VERSION_QUALIFIER_COMBI_MAX           4
#define SYS_VERSION_CONV_INT_TO_ASCII(intver, asciiver)         \
    if (intver > 9)                                             \
    {                                                           \
      asciiver[i++] = SYS_VERSION_ZERO_ASCII+(intver/10);       \
      asciiver[i++] = SYS_VERSION_ZERO_ASCII+(intver%10);       \
    }                                                           \
    else                                                        \
    {                                                           \
      asciiver[i++] = SYS_VERSION_ZERO_ASCII+intver;            \
    }

/******************************************************************************
                                   Prototypes section
******************************************************************************/
static void sysUpdateRndSeedTimerFired(void);
#ifdef _RF_RND_
static void sysRndConfirm(RF_RandomConf_t *conf);
#endif
static uint16_t sysPseudoRandomSeed(void);
static void sysSeedRandFunction(uint16_t randValue);

#if (defined (TRNG_MODULE_ENABLED) && defined(TRNG_MODULE_INTERRUPT_METHOD))
static void sysRndTrngCallback(uint32_t randData, uintptr_t context);
uint16_t trngContext = 0xAA; //dummy value
#endif

#ifdef TRNG_MODULE_ENABLED
uint32_t TRNG_ReadData( void );
#endif
/******************************************************************************
                    Static variables section
******************************************************************************/
static HAL_AppTimer_t sysRndSeedTimer =
{
  .mode = TIMER_ONE_SHOT_MODE,
  .interval = SYS_UPDATE_RAND_SEED_TIMEOUT,
  .callback = sysUpdateRndSeedTimerFired
};
#ifndef TRNG_MODULE_ENABLED
static RF_RandomReq_t sysRfRndReq =
{
  .disableRx = true,
  .RF_RandomConf = sysRndConfirm
};
#endif
/******************************************************************************
                                   Implementation section
******************************************************************************/
/******************************************************************************
  Performs swap bytes in array of length
  Parameters:
    array  - pointer to array.
    length  - array length
  Returns:
    None
****************************************************************************/
void SYS_Swap(uint8_t *array, uint8_t length)
{
  uint8_t *dst = array + length - 1;

  uint8_t tmp;
  length >>= 1;

  while (length--)
  {
    tmp = *array;
    *array = *dst;
    *dst = tmp;

    array++;
    dst--;
  }
}
/*************************************************************************//**
\brief Seeds the random function 
*****************************************************************************/
static void sysSeedRandFunction(uint16_t randValue)
{
  if(randValue)
    srand(randValue);
  else
    srand(sysPseudoRandomSeed());
}
/*************************************************************************//**
\brief Updates rnd with new random values according to time interval
*****************************************************************************/
static void sysUpdateRndSeedTimerFired(void)
{
#ifdef TRNG_MODULE_ENABLED
#ifdef TRNG_MODULE_INTERRUPT_METHOD
    TRNG_CallbackRegister(sysRndTrngCallback, (uintptr_t)trngContext);
    TRNG_RandomNumberGenerate();
#else
    uint16_t randNum;
    randNum = TRNG_ReadData();
    sysSeedRandFunction(randNum);
#endif //TRNG_MODULE_INTERRUPT_METHOD
    HAL_StopAppTimer(&sysRndSeedTimer);
    HAL_StartAppTimer(&sysRndSeedTimer);
#else
  RF_RandomReq(&sysRfRndReq);
#endif
}
#if (defined (TRNG_MODULE_ENABLED) && defined(TRNG_MODULE_INTERRUPT_METHOD))
/**************************************************************************//**
\brief callback for random number generation updater
******************************************************************************/
static void sysRndTrngCallback(uint32_t randData, uintptr_t context)
{
  sysSeedRandFunction((uint16_t)randData);
}
#endif //TRNG_MODULE_ENABLED

#ifndef TRNG_MODULE_ENABLED //#ifdef _RF_RND_
/**************************************************************************//**
\brief Confirm from random number generation updater

\param[in]
    conf - confirm parameters
******************************************************************************/
static void sysRndConfirm(RF_RandomConf_t *conf)
{
  sysSeedRandFunction(conf->value);
  sysRfRndReq.disableRx = true;
  HAL_StopAppTimer(&sysRndSeedTimer);
  HAL_StartAppTimer(&sysRndSeedTimer);
}
#endif
/**************************************************************************//**
\brief  Starts timer to update rand
******************************************************************************/
void sysStartUpdatingRandSeed(void)
{
  HAL_StopAppTimer(&sysRndSeedTimer);
#ifndef TRNG_MODULE_ENABLED //#ifdef _RF_RND_
  if (false == sysRfRndReq.disableRx)
    return; // random request has been started already
  sysRfRndReq.disableRx = false;
#endif
  sysUpdateRndSeedTimerFired();
}

/**************************************************************************//**
\brief Calculates a pseudo random value for seed if HW random is not available.

\return:
    16-bit value which was calculated by using current time and other params.
******************************************************************************/
static uint16_t sysPseudoRandomSeed(void)
{
  uint16_t result = (uint16_t)HAL_GetSystemTime();
  const uint16_t *extAddr = (const uint16_t *)MAC_GetExtAddr();
  uint8_t i;

  for (i = 0; i < sizeof(ExtAddr_t)/sizeof(result); ++i)
    result ^= extAddr[i];

  return result;
}

/**************************************************************************//**
  \brief This function copies size bytes of random data into buffer.

  \param: buffer - This is an unsigned char array of size at least sz to hold
   the random data.
  \param: size - The number of bytes of random data to compute and store.

  \return:  0 Indicates successful completion.
******************************************************************************/
int SYS_GetRandomSequence(uint8_t *buffer, unsigned long size)
{
  uint16_t i;
  u16Packed_t *u16ptr = (u16Packed_t*)buffer;

  for(i = 0; i < size/2; i++, u16ptr++)
    u16ptr->val = SYS_GetRandomNumber();

  if (size & (1<<0))
    buffer[size-1] = (uint8_t)SYS_GetRandomNumber();

  return 0;
}

uint16_t SYS_GetNormalizedRandomNumber(uint16_t upperLimit)
{
  uint32_t result = (UINT16_MAX & rand());
  result = (result * upperLimit) / UINT16_MAX;

  return result;
}

#if defined(_SLEEP_WHEN_IDLE_)
/**************************************************************************//**
  \brief Stops priodic updating of the random seed.
 ******************************************************************************/
void sysStopUpdatingRandSeed(void)
{
  HAL_StopAppTimer(&sysRndSeedTimer);
}
#endif /* _SLEEP_WHEN_IDLE_ */

#ifndef _MAC2_
/**************************************************************************//**
\brief This function reads version number in CS and returns as string

\param[out] strVersion - string version. intVersion - integer version

\return:  bool. true indicates success. false indicates failure,
          which means version is unavailable
******************************************************************************/
bool SYS_GetBitCloudRevision(uint8_t *strVersion, uint32_t *intVersion)
{
  typedef union {
    uint32_t stackVer;
    struct {
      uint8_t reserved:8;
      uint8_t qualifier:2;
      uint8_t branchIter:6;
      uint8_t branchId:4;
      uint8_t minorDerv:4;
      uint8_t minor:4;
      uint8_t major:4;
    } stackBits;
  } stackVersion_t;
  stackVersion_t stackVersion;
  uint8_t i = 0;
  uint8_t qual[4] = {SYS_VERSION_ZERO_ASCII, SYS_VERSION_P_ASCII, SYS_VERSION_M_ASCII, SYS_VERSION_E_ASCII};

  CS_ReadParameter(CS_STACK_VERSION_ID, &stackVersion.stackVer);

  if (!stackVersion.stackVer || (NULL == strVersion) || (NULL == intVersion))
  {
    if (intVersion)
      *intVersion = 0;
    if (strVersion)
      strVersion[0] = '\0';

    return false;
  }
  else
  {
    // convert to ascii
    strVersion[i++] = 'B';
    strVersion[i++] = 'C';
    strVersion[i++] = '_';
    strVersion[i++] = 'V';
    SYS_VERSION_CONV_INT_TO_ASCII(stackVersion.stackBits.major, strVersion);

    strVersion[i++] = '.';
    SYS_VERSION_CONV_INT_TO_ASCII(stackVersion.stackBits.minor, strVersion);

    strVersion[i++] = '.';
    SYS_VERSION_CONV_INT_TO_ASCII(stackVersion.stackBits.minorDerv, strVersion);

    strVersion[i++] = '_';
    SYS_VERSION_CONV_INT_TO_ASCII(stackVersion.stackBits.branchId, strVersion);

    strVersion[i++] = '.';
    SYS_VERSION_CONV_INT_TO_ASCII(stackVersion.stackBits.branchIter, strVersion);

    strVersion[i++] = qual[stackVersion.stackBits.qualifier];
    strVersion[i] = '\0';

    if (intVersion)
      *intVersion = stackVersion.stackVer;
  }

  return true;
}
#endif // _MAC2_

// eof sysUtils.c
