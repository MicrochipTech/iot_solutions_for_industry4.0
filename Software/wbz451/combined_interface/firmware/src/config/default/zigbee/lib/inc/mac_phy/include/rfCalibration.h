/*******************************************************************************
  RF Calibration Header File

  Company:
    Microchip Technology Inc.

  File Name:
    rfCalibration.h

  Summary:
    This file contains the Interface for PLL calibration and filter tuning.

  Description:
    This file contains the Interface for PLL calibration and filter tuning.
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

#if !defined _RFCALIBRATION_H
#define _RFCALIBRATION_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#include <mac_phy/include/macCommon.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
/**
 * \brief RF calibration status type.
 *
 * - RF_CALIBRATION_SUCCESS_STATUS means that the calibration cycle has finished
 *     successfuly and the radio chip is ready to work.
 * - RF_CALIBRATION_FAIL_STATUS - MAC hardware depended subsystem cannot preform
 *   the calibration at this time.
 **/
typedef enum _RF_CalibrationStatus_t
{
  RF_CALIBRATION_SUCCESS_STATUS,
  RF_CALIBRATION_FAIL_STATUS
} RF_CalibrationStatus_t;

/**//**
 * \brief The structure declaration of RF calibration confirmation parameters.
 */
typedef struct _RF_CalibrationConf_t
{
  RF_CalibrationStatus_t status;
} RF_CalibrationConf_t;

/**//**
 * \brief Parameters of RF Calibration request.
 */
typedef struct _RF_CalibrationReq_t
{
  /*! Service field - for internal needs. */
  MAC_Service_t  service;

  /** RF Calibration confirm callback function's pointer. */
  void (*RF_CalibrationConf)(RF_CalibrationConf_t *conf);
  /** Status of processing this request. */
  RF_CalibrationConf_t confirm;
} RF_CalibrationReq_t;

/******************************************************************************
                              Prototypes section
 ******************************************************************************/
/**************************************************************************//**
  \brief initiates a calibration cycle.

  \param[in] req - pointer to calibration parameters - callback and conf status.
  \return None.
 ******************************************************************************/
void RF_CalibrationReq(RF_CalibrationReq_t *const req);

#endif /* _RFCALIBRATION_H */
/** eof rfCalibration.h */
