/*******************************************************************************
  Debugging Source File

  Company:
    Microchip Technology Inc.

  File Name:
    dbg.c

  Summary:
    This file contains the functions for getting debugging information.

  Description:
    This file contains the functions for getting debugging information.
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

/*********************************************************************************
  Destination where the log information is saved should be defined in Makefile
  One of the following:
    SYS_LOG_UART
    SYS_LOG_SIMULATOR
    SYS_LOG_EEPROM
**********************************************************************************/

/*********************************************************************************
                          Includes section.
**********************************************************************************/
#include <systemenvironment/include/dbg.h>

/*  ________________________________ SYS_LOG __________________________________ */
#ifdef _SYS_LOG_ON_
  /*********************************************************************************
                            Definitions section.
  **********************************************************************************/
  #define LOG_BUFFER_SIZE 256 //Size of the buffer for buffering logs. If it is less
                              //the algorithm should be revised
  #if defined(_HAL_LOG_INTERFACE_UART0_) || defined(_HAL_LOG_INTERFACE_UART1_)
    #define SYS_MESSAGE_SIZE      2
    #define MESSAGE_MASK       0x7F
    #define OVERFLOW_MASK      0x40

    #if defined(_HAL_LOG_INTERFACE_UART0_)
      #define  LOG_USART_CHANNEL   USART_CHANNEL_0
    #endif
    #if defined(_HAL_LOG_INTERFACE_UART1_)
      #define  LOG_USART_CHANNEL   USART_CHANNEL_1
    #endif

    #define SYS_INIT_LOG       SYS_UsartInitLog();
    #define SYS_WRITE_LOG(A,B) SYS_UsartWriteLog(A,B);
  #else
    #define SYS_INIT_LOG
    #define SYS_WRITE_LOG(A,B)
  #endif

  /*********************************************************************************
                            Static variables section.
  **********************************************************************************/
  #if defined(_HAL_LOG_INTERFACE_UART0_) || defined(_HAL_LOG_INTERFACE_UART1_)
    HAL_UsartDescriptor_t sysUsartDescriptor;
  #endif

  static uint8_t logBuffer[LOG_BUFFER_SIZE]; // buffer for buffering incoming logs
  volatile uint8_t sysInfinityLoopMonitoring = 0;

  /*********************************************************************************
                            Implementation section.
  **********************************************************************************/
  #if defined(_HAL_LOG_INTERFACE_UART0_) || defined(_HAL_LOG_INTERFACE_UART1_)
    /*****************************************************************************//**
     \brief Initialization usart logging system.
    **********************************************************************************/
    INLINE void SYS_UsartInitLog(void)
    {
      sysUsartDescriptor.tty            = LOG_USART_CHANNEL;
      sysUsartDescriptor.mode           = USART_MODE_ASYNC;
      sysUsartDescriptor.flowControl    = USART_FLOW_CONTROL_NONE;
      sysUsartDescriptor.baudrate       = USART_BAUDRATE_38400;
      sysUsartDescriptor.dataLength     = USART_DATA8;
      sysUsartDescriptor.parity         = USART_PARITY_NONE;
      sysUsartDescriptor.stopbits       = USART_STOPBIT_1;
      sysUsartDescriptor.rxBuffer       = NULL;
      sysUsartDescriptor.rxBufferLength = 0;
      sysUsartDescriptor.txBuffer       = logBuffer;
      sysUsartDescriptor.txBufferLength = LOG_BUFFER_SIZE;
      sysUsartDescriptor.rxCallback     = NULL;
      sysUsartDescriptor.txCallback     = NULL;

      HAL_OpenUsart(&sysUsartDescriptor);
    }

    /*****************************************************************************//**
     \brief Write log information to usart.
     \param[in]
       leyerID - identical definition of application layer;
     \param[in]
       message - information byte (must be less then 0x80);
    **********************************************************************************/
    INLINE void SYS_UsartWriteLog(uint8_t leyerID, uint8_t message)
    {
      static result_t wasOverflow = BC_FAIL;
      uint16_t commonData;

      commonData = ((uint16_t)(message & MESSAGE_MASK) << 8) | leyerID;

      if (BC_SUCCESS == wasOverflow)
        commonData |= OVERFLOW_MASK;

      if (SYS_MESSAGE_SIZE != HAL_WriteUsart(&sysUsartDescriptor, (uint8_t *)&commonData, SYS_MESSAGE_SIZE))
        wasOverflow = BC_SUCCESS;
      else
        wasOverflow = BC_FAIL;
    }
  #else
  #endif

  /*****************************************************************************//**
   \brief Write log information to defined destination. The destination can be
    UART, EEPROM, Ethernet... The destination is determined by the define
    during compilation
    \param[in]
      leyerID - identical definition of application layer;
    \param[in]
      message - information byte (must be less then 0x80);
  **********************************************************************************/
  void SYS_WriteLog(uint8_t leyerID, uint8_t message)
  {
    SYS_WRITE_LOG(leyerID, message)
  }

  /*****************************************************************************//**
   \brief Initialization logging system.
  **********************************************************************************/
  void SYS_InitLog(void)
  {
    SYS_INIT_LOG
  }
#endif // _SYS_LOG_ON_



/*  ________________________________ SYS_ASSERT _______________________________ */
#ifdef _SYS_ASSERT_ON_
  /*********************************************************************************
                            Implementation  section.
  **********************************************************************************/
  /*********************************************************************************
    Function catches unexpected conditions in the logic.
    Parameters:
      condition - TRUE or FALSE. FALSE means problems in the logic.
      dbgCode   - assert's unique code.
                  dbgCode ranges: 0x1000 - 0x1fff - MAC
                                  0x2000 - 0x2fff - HAL
                                  0x3000 - 0x3fff - NWK
                                  0x4000 - 0x4fff - APS
                                  0x5000 - 0x5fff - ZDO
                                  0x7000 - 0x7fff - SSP/TC
                                  0x8000 - 0x8fff - System Environment
                                  0x9000 - 0x9fff - BSP
                                  0xf000 - 0xfffe - APL
    Returns:
      none.
  *********************************************************************************/
  void sysAssert(bool condition, uint16_t dbgCode)
  {
    SYS_ASSERT(condition, dbgCode)
  }
#endif  // _SYS_ASSERT_ON_

//eof dbg.c
