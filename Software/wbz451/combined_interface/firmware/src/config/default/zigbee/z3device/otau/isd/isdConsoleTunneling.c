/*******************************************************************************
  Implementation of mechanism of console tunneling Source File

  Company:
    Microchip Technology Inc.

  File Name:
    isdConsoleTunneling.c

  Summary:
    The file implements the tunneling mechanism of image storage driver.

  Description:
    The file implements the tunneling mechanism of image storage driver.
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

#if (APP_USE_OTAU == 1)
#include <zigbee/z3device_configs/otauConfig.h>
#include <zcl/include/zclOtauManager.h>
#if (APP_USE_ISD_CONSOLE_TUNNELING == 1)

/******************************************************************************
                   Includes section
******************************************************************************/
#include <systemenvironment/include/sysTypes.h>
#include <z3device/otau/isd/include/isdConsoleTunneling.h>

/******************************************************************************
                   Defines section
******************************************************************************/

/******************************************************************************
                   Types section
******************************************************************************/
/******************************************************************************
                   Static Function Prototypes section
******************************************************************************/
static void ISD_USARTBufferEventHandler ( DRV_USART_BUFFER_EVENT bufferEvent,
                                                DRV_USART_BUFFER_HANDLE bufferHandle,
                                                uintptr_t context );


/******************************************************************************
                   Static variables section
******************************************************************************/
static ISD_TunnelDescriptor_t        *tunnelDescriptor = NULL;

/******************************************************************************
                   Implementations section
******************************************************************************/
/**************************************************************************//**
\brief Initialize ISD tunnel.

\param[in] descriptor - pointer to USART descriptor

\return zero value if tunnel was initialized, false otherwise.
******************************************************************************/
bool ISD_OpenUsart(ISD_TunnelDescriptor_t *descriptor)
{
    descriptor->isdTunnelHandle = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);

    if (descriptor->isdTunnelHandle != DRV_HANDLE_INVALID)
    {
        DRV_USART_BufferEventHandlerSet(descriptor->isdTunnelHandle, ISD_USARTBufferEventHandler, 0);
        tunnelDescriptor = descriptor;
    }
    else 
        return (false);

    return (true);
}
void ISD_WriteUSART(uint8_t *buffer, uint8_t length)
{
    DRV_USART_WriteBufferAdd(tunnelDescriptor->isdTunnelHandle, (void*) buffer, length,  &tunnelDescriptor->writeBufferHandle);
}

void ISD_ReadUSART(uint8_t *buffer, uint8_t length)
{
    DRV_USART_ReadBufferAdd(tunnelDescriptor->isdTunnelHandle, (void*) buffer, length,  &tunnelDescriptor->readBufferHandle);
}

void ISD_ClearUSART(void)
{
  DRV_USART_WriteQueuePurge(tunnelDescriptor->isdTunnelHandle);
  DRV_USART_ReadQueuePurge(tunnelDescriptor->isdTunnelHandle);
}
static void ISD_USARTBufferEventHandler(
    DRV_USART_BUFFER_EVENT bufferEvent,
    DRV_USART_BUFFER_HANDLE bufferHandle,
    uintptr_t context
)
{
    if(NULL == tunnelDescriptor)
        return;
    switch(bufferEvent)
    {
        case DRV_USART_BUFFER_EVENT_COMPLETE:
            if (bufferHandle == tunnelDescriptor->writeBufferHandle)
            {
                tunnelDescriptor->txCallback();
            }
            else if (bufferHandle == tunnelDescriptor->readBufferHandle)
            {
                uint8_t length = DRV_USART_BufferCompletedBytesGet(bufferHandle);
                tunnelDescriptor->rxCallback(length);
            }
            
            break;

        case DRV_USART_BUFFER_EVENT_ERROR:
        default:
        {
            uint16_t processedBytes= DRV_USART_BufferCompletedBytesGet(bufferHandle);
            tunnelDescriptor->errCallback(processedBytes);
        }
            break;
    }
}

#endif // APP_USE_ISD_CONSOLE_TUNNELING == 1
#endif // APP_USE_OTAU == 1

//eof isdConsoleTunneling.c