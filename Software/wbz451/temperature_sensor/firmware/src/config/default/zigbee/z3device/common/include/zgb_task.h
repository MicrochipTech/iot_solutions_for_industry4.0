/*******************************************************************************
  Zgb task Header File

  Company:
    Microchip Technology Inc.

  File Name:
    zgb_task.h

  Summary:
    This file contains the Zgb task implementation.

  Description:
    This file contains the Zgb task implementation.
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

#ifndef ZGB_TASK_H
#define ZGB_TASK_H
// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "framework_defs.h"
#include <z3device/stack_interface/zgb_api.h>

void zigbee_init(uint32_t               *sram_vector_table,
                 OSAL_API_LIST_TYPE     *osal_api_list,
                 OSAL_QUEUE_HANDLE_TYPE *zigbeeRequestQueueHandle,
                 ZB_AppGenericCallBack    app_callback);

void zigbee_task(void *ptr);

void Zigbee_Init(OSAL_API_LIST_TYPE *osalAPIList,
                 OSAL_QUEUE_HANDLE_TYPE *zigbeeRequestQueueHandle,
                 uint32_t *sram_vector_table,
                 ZB_CS_SYS_IBData_t *zgbIBdata);

#endif // ZGB_TASK_H