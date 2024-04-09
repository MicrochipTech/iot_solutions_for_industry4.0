/*******************************************************************************
 System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains implementation of "SYS_Initialize" function requiered for
    MPLAB Harmony system initialization to initialize all system components.

  Remarks:
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#ifdef __XC32__
#include <xc.h>
#endif
#include "osal/osal_freertos_extend.h"
#include "framework_defs.h"
#include <z3device/common/include/zgb_task.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyPic32cx.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phyInit.h>
#include <mac_phy/mac_hwd_phy/RF231_RF212/PHY/include/phySet.h>
#include <hal/cortexm4/pic32cx/include/halAppClock.h>

#define VECTOR_TABLE_SIZE (128)
#define QUEUE_LENGTH (8)
#define QUEUE_ITEM_SIZE (sizeof(void *))

// extern functions
extern void APP_ZigbeeStackCb(void *response);

// Queue Pointer received from Application
extern OSAL_QUEUE_HANDLE_TYPE apiRequestQueueHandle; 
uint32_t sram_vector_table[VECTOR_TABLE_SIZE] __attribute__((aligned(VECTOR_TABLE_SIZE * 4)));
OSAL_API_LIST_TYPE     osalAPIList;
OSAL_QUEUE_HANDLE_TYPE zigbeeRequestQueueHandle;
ZB_AppGenericCallBack fnAppGenericCB;


/*******************************************************************************
  Function:
    void ZB_EventRegister(ZB_AppGenericCallBack app_ZBStackCb)

  Remarks:
    To Register Zigbee Stack Callback function ; Prototype in zgp_task.h.
*******************************************************************************/
void ZB_EventRegister(ZB_AppGenericCallBack app_ZBStackCb)
{
  fnAppGenericCB = app_ZBStackCb; // Generic callback pointer to Application 
}

/*******************************************************************************
  Function:
    void Zigbee_Init(OSAL_API_LIST_TYPE *,OSAL_QUEUE_HANDLE_TYPE *, uint32_t *)

  Remarks:
    See prototype in zgp_task.h.
*******************************************************************************/
void Zigbee_Init(OSAL_API_LIST_TYPE *osalAPIList,OSAL_QUEUE_HANDLE_TYPE *zigbeeRequestQueueHandle ,
                 uint32_t *sram_vector_table , ZB_CS_SYS_IBData_t *zgbIBdata)
{
  uint32_t *flash_vector_table     = (uint32_t *)0x00000000;
  uint8_t devicePowerType;
  zos = osalAPIList;   // Store the OSAL functions to local pointer
  apiRequestQueueHandle = *zigbeeRequestQueueHandle;    // API Request queue from application task


  /*Setting Device Power Type*/
  if((CFG_REGS->CFG_ID & DEVICE_ID_TYPE) == DEVICE_ID_MPA_TYPE)
  {
	devicePowerType = (uint8_t) CS_DEVICE_POWER_MPA_LPA;
    CS_WriteParameter(CS_DEVICE_POWER_ID, &devicePowerType);	
  }
  else if((CFG_REGS->CFG_ID & DEVICE_ID_TYPE) == DEVICE_ID_LPA_TYPE)
  {
    devicePowerType = (uint8_t) CS_DEVICE_POWER_LPA_ONLY;
    CS_WriteParameter(CS_DEVICE_POWER_ID, &devicePowerType);	
  }

  if(sram_vector_table)
  {
    // initialize the vector table in SRAM from the vector table in flash
    for (uint32_t i = 0; i < VECTOR_TABLE_SIZE; i++)
    {
        sram_vector_table[i] = flash_vector_table[i];
    }
    // set the ARM core Vector Table Offset Register value to the sram vector table
    // from now on the ARM core will use the new vecrtor table to handle the exceptions.
    SCB->VTOR = (uint32_t)&sram_vector_table;
  }

  if (!PHY_Init())
  {
    //while(1);   // ERROR during Initialization.
  }
  
  //Zigbee Configuration Server initialization
  CS_Init(zgbIBdata);
  
  //Power Set  
  //int8_t power = (int8_t) (TX_POWER_REQ - TX_ANT_GAIN);
  
  //PHY_setTxPowerinDbm(power);  

}
