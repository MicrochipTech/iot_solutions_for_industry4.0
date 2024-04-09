/*******************************************************************************
  Application Error Code Definition Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app_error_desf.h

  Summary:
    This file contains the definitions of error codes for application.

  Description:
    This file contains the definitions of error codes for application.
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


#ifndef APP_ERROR_DEFS_H
#define APP_ERROR_DEFS_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#ifdef MBA_ERROR_DEFS_H
#include "mba_error_defs.h"

// *****************************************************************************
// *****************************************************************************
// Section: Macros
// *****************************************************************************
// *****************************************************************************

#define APP_RES_SUCCESS                         MBA_RES_SUCCESS                               /**< Execution successfully. */
#define APP_RES_FAIL                            MBA_RES_FAIL                                  /**< Execution fail. */
#define APP_RES_OOM                             MBA_RES_OOM                                   /**< Out of memory. */
#define APP_RES_INVALID_PARA                    MBA_RES_INVALID_PARA                          /**< Invalid parameters. */
#define APP_RES_NO_RESOURCE                     MBA_RES_NO_RESOURCE                           /**< No resource. */
#define APP_RES_BAD_STATE                       MBA_RES_BAD_STATE                             /**< Bad State. */
#define APP_RES_PENDING_DUE_TO_SECURITY         MBA_RES_PENDING_DUE_TO_SECURITY               /**< Pending the request due to security process. */
#define APP_RES_BUSY                            MBA_RES_BUSY                                  /**< Execution fail due to system is busy. */

#else
#define APP_RES_SUCCESS                         0x0000                                        /**< Execution successfully. */
#define APP_RES_FAIL                            0x0001                                        /**< Execution fail. */
#define APP_RES_OOM                             0x0002                                        /**< Out of memory. */
#define APP_RES_INVALID_PARA                    0x0003                                        /**< Invalid parameters. */
#define APP_RES_NO_RESOURCE                     0x0004                                        /**< No resource. */
#define APP_RES_BAD_STATE                       0x0005                                        /**< Bad State. */
#define APP_RES_PENDING_DUE_TO_SECURITY         0x0006                                        /**< Pending the request due to security process. */
#define APP_RES_BUSY                            0x0007                                        /**< Execution fail due to system is busy. */

#endif


#endif
