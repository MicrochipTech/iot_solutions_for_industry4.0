/*
 * Component description for ARB
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2023-05-31T11:03:01Z */
#ifndef _BZ45_ARB_COMPONENT_H_
#define _BZ45_ARB_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ARB                                          */
/* ************************************************************************** */

/* -------- ARB_BT_CTRL : (ARB Offset: 0x00) (R/W 32)  -------- */
#define ARB_BT_CTRL_RESETVALUE                _UINT32_(0x0A)                                       /*  (ARB_BT_CTRL)   Reset Value */

#define ARB_BT_CTRL_MAX_ABORT_TIME_BT_Pos     _UINT32_(0)                                          /* (ARB_BT_CTRL) BT max abort time Position */
#define ARB_BT_CTRL_MAX_ABORT_TIME_BT_Msk     (_UINT32_(0xFF) << ARB_BT_CTRL_MAX_ABORT_TIME_BT_Pos) /* (ARB_BT_CTRL) BT max abort time Mask */
#define ARB_BT_CTRL_MAX_ABORT_TIME_BT(value)  (ARB_BT_CTRL_MAX_ABORT_TIME_BT_Msk & (_UINT32_(value) << ARB_BT_CTRL_MAX_ABORT_TIME_BT_Pos)) /* Assigment of value for MAX_ABORT_TIME_BT in the ARB_BT_CTRL register */
#define ARB_BT_CTRL_ALLOW_OPT_RX_BT_Pos       _UINT32_(8)                                          /* (ARB_BT_CTRL) BT allow optimistic rx Position */
#define ARB_BT_CTRL_ALLOW_OPT_RX_BT_Msk       (_UINT32_(0x1) << ARB_BT_CTRL_ALLOW_OPT_RX_BT_Pos)   /* (ARB_BT_CTRL) BT allow optimistic rx Mask */
#define ARB_BT_CTRL_ALLOW_OPT_RX_BT(value)    (ARB_BT_CTRL_ALLOW_OPT_RX_BT_Msk & (_UINT32_(value) << ARB_BT_CTRL_ALLOW_OPT_RX_BT_Pos)) /* Assigment of value for ALLOW_OPT_RX_BT in the ARB_BT_CTRL register */
#define ARB_BT_CTRL_ALLOW_OPT_TX_BT_Pos       _UINT32_(9)                                          /* (ARB_BT_CTRL) BT allow optimistic tx Position */
#define ARB_BT_CTRL_ALLOW_OPT_TX_BT_Msk       (_UINT32_(0x1) << ARB_BT_CTRL_ALLOW_OPT_TX_BT_Pos)   /* (ARB_BT_CTRL) BT allow optimistic tx Mask */
#define ARB_BT_CTRL_ALLOW_OPT_TX_BT(value)    (ARB_BT_CTRL_ALLOW_OPT_TX_BT_Msk & (_UINT32_(value) << ARB_BT_CTRL_ALLOW_OPT_TX_BT_Pos)) /* Assigment of value for ALLOW_OPT_TX_BT in the ARB_BT_CTRL register */
#define ARB_BT_CTRL_Msk                       _UINT32_(0x000003FF)                                 /* (ARB_BT_CTRL) Register Mask  */


/* -------- ARB_ZB_CTRL : (ARB Offset: 0x04) (R/W 32)  -------- */
#define ARB_ZB_CTRL_RESETVALUE                _UINT32_(0x0A)                                       /*  (ARB_ZB_CTRL)   Reset Value */

#define ARB_ZB_CTRL_MAX_ABORT_TIME_ZB_Pos     _UINT32_(0)                                          /* (ARB_ZB_CTRL) ZB max abort time Position */
#define ARB_ZB_CTRL_MAX_ABORT_TIME_ZB_Msk     (_UINT32_(0xFF) << ARB_ZB_CTRL_MAX_ABORT_TIME_ZB_Pos) /* (ARB_ZB_CTRL) ZB max abort time Mask */
#define ARB_ZB_CTRL_MAX_ABORT_TIME_ZB(value)  (ARB_ZB_CTRL_MAX_ABORT_TIME_ZB_Msk & (_UINT32_(value) << ARB_ZB_CTRL_MAX_ABORT_TIME_ZB_Pos)) /* Assigment of value for MAX_ABORT_TIME_ZB in the ARB_ZB_CTRL register */
#define ARB_ZB_CTRL_ALLOW_OPT_RX_ZB_Pos       _UINT32_(8)                                          /* (ARB_ZB_CTRL) ZB allow optimistic rx Position */
#define ARB_ZB_CTRL_ALLOW_OPT_RX_ZB_Msk       (_UINT32_(0x1) << ARB_ZB_CTRL_ALLOW_OPT_RX_ZB_Pos)   /* (ARB_ZB_CTRL) ZB allow optimistic rx Mask */
#define ARB_ZB_CTRL_ALLOW_OPT_RX_ZB(value)    (ARB_ZB_CTRL_ALLOW_OPT_RX_ZB_Msk & (_UINT32_(value) << ARB_ZB_CTRL_ALLOW_OPT_RX_ZB_Pos)) /* Assigment of value for ALLOW_OPT_RX_ZB in the ARB_ZB_CTRL register */
#define ARB_ZB_CTRL_ALLOW_OPT_TX_ZB_Pos       _UINT32_(9)                                          /* (ARB_ZB_CTRL) ZB allow optimistic tx Position */
#define ARB_ZB_CTRL_ALLOW_OPT_TX_ZB_Msk       (_UINT32_(0x1) << ARB_ZB_CTRL_ALLOW_OPT_TX_ZB_Pos)   /* (ARB_ZB_CTRL) ZB allow optimistic tx Mask */
#define ARB_ZB_CTRL_ALLOW_OPT_TX_ZB(value)    (ARB_ZB_CTRL_ALLOW_OPT_TX_ZB_Msk & (_UINT32_(value) << ARB_ZB_CTRL_ALLOW_OPT_TX_ZB_Pos)) /* Assigment of value for ALLOW_OPT_TX_ZB in the ARB_ZB_CTRL register */
#define ARB_ZB_CTRL_Msk                       _UINT32_(0x000003FF)                                 /* (ARB_ZB_CTRL) Register Mask  */


/* -------- ARB_EVENT_CTRL : (ARB Offset: 0x08) (R/W 32)  -------- */
#define ARB_EVENT_CTRL_RESETVALUE             _UINT32_(0x01)                                       /*  (ARB_EVENT_CTRL)   Reset Value */

#define ARB_EVENT_CTRL_START_TIME_ALLOWANCE_Pos _UINT32_(0)                                          /* (ARB_EVENT_CTRL) minimum change needed in the start time to be considered as an arbitration event. Position */
#define ARB_EVENT_CTRL_START_TIME_ALLOWANCE_Msk (_UINT32_(0xF) << ARB_EVENT_CTRL_START_TIME_ALLOWANCE_Pos) /* (ARB_EVENT_CTRL) minimum change needed in the start time to be considered as an arbitration event. Mask */
#define ARB_EVENT_CTRL_START_TIME_ALLOWANCE(value) (ARB_EVENT_CTRL_START_TIME_ALLOWANCE_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_START_TIME_ALLOWANCE_Pos)) /* Assigment of value for START_TIME_ALLOWANCE in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_USE_END_TIME_AS_EVENT_Pos _UINT32_(4)                                          /* (ARB_EVENT_CTRL)  Position */
#define ARB_EVENT_CTRL_USE_END_TIME_AS_EVENT_Msk (_UINT32_(0x1) << ARB_EVENT_CTRL_USE_END_TIME_AS_EVENT_Pos) /* (ARB_EVENT_CTRL)  Mask */
#define ARB_EVENT_CTRL_USE_END_TIME_AS_EVENT(value) (ARB_EVENT_CTRL_USE_END_TIME_AS_EVENT_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_USE_END_TIME_AS_EVENT_Pos)) /* Assigment of value for USE_END_TIME_AS_EVENT in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_USE_START_TIME_AS_EVENT_Pos _UINT32_(5)                                          /* (ARB_EVENT_CTRL)  Position */
#define ARB_EVENT_CTRL_USE_START_TIME_AS_EVENT_Msk (_UINT32_(0x1) << ARB_EVENT_CTRL_USE_START_TIME_AS_EVENT_Pos) /* (ARB_EVENT_CTRL)  Mask */
#define ARB_EVENT_CTRL_USE_START_TIME_AS_EVENT(value) (ARB_EVENT_CTRL_USE_START_TIME_AS_EVENT_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_USE_START_TIME_AS_EVENT_Pos)) /* Assigment of value for USE_START_TIME_AS_EVENT in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_USE_PRIO_AS_EVENT_Pos  _UINT32_(6)                                          /* (ARB_EVENT_CTRL)  Position */
#define ARB_EVENT_CTRL_USE_PRIO_AS_EVENT_Msk  (_UINT32_(0x1) << ARB_EVENT_CTRL_USE_PRIO_AS_EVENT_Pos) /* (ARB_EVENT_CTRL)  Mask */
#define ARB_EVENT_CTRL_USE_PRIO_AS_EVENT(value) (ARB_EVENT_CTRL_USE_PRIO_AS_EVENT_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_USE_PRIO_AS_EVENT_Pos)) /* Assigment of value for USE_PRIO_AS_EVENT in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_DELAYED_OK_TASKS_DONT_WAIT_Pos _UINT32_(7)                                          /* (ARB_EVENT_CTRL)  Position */
#define ARB_EVENT_CTRL_DELAYED_OK_TASKS_DONT_WAIT_Msk (_UINT32_(0x1) << ARB_EVENT_CTRL_DELAYED_OK_TASKS_DONT_WAIT_Pos) /* (ARB_EVENT_CTRL)  Mask */
#define ARB_EVENT_CTRL_DELAYED_OK_TASKS_DONT_WAIT(value) (ARB_EVENT_CTRL_DELAYED_OK_TASKS_DONT_WAIT_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_DELAYED_OK_TASKS_DONT_WAIT_Pos)) /* Assigment of value for DELAYED_OK_TASKS_DONT_WAIT in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_RESOLVE_EQUAL_PRIO_Pos _UINT32_(8)                                          /* (ARB_EVENT_CTRL)  Position */
#define ARB_EVENT_CTRL_RESOLVE_EQUAL_PRIO_Msk (_UINT32_(0x3) << ARB_EVENT_CTRL_RESOLVE_EQUAL_PRIO_Pos) /* (ARB_EVENT_CTRL)  Mask */
#define ARB_EVENT_CTRL_RESOLVE_EQUAL_PRIO(value) (ARB_EVENT_CTRL_RESOLVE_EQUAL_PRIO_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_RESOLVE_EQUAL_PRIO_Pos)) /* Assigment of value for RESOLVE_EQUAL_PRIO in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_ABORT_IN_STATIC_MODE_Pos _UINT32_(10)                                         /* (ARB_EVENT_CTRL)  Position */
#define ARB_EVENT_CTRL_ABORT_IN_STATIC_MODE_Msk (_UINT32_(0x1) << ARB_EVENT_CTRL_ABORT_IN_STATIC_MODE_Pos) /* (ARB_EVENT_CTRL)  Mask */
#define ARB_EVENT_CTRL_ABORT_IN_STATIC_MODE(value) (ARB_EVENT_CTRL_ABORT_IN_STATIC_MODE_Msk & (_UINT32_(value) << ARB_EVENT_CTRL_ABORT_IN_STATIC_MODE_Pos)) /* Assigment of value for ABORT_IN_STATIC_MODE in the ARB_EVENT_CTRL register */
#define ARB_EVENT_CTRL_Msk                    _UINT32_(0x000007FF)                                 /* (ARB_EVENT_CTRL) Register Mask  */


/* -------- ARB_CORE_CTRL : (ARB Offset: 0x0C) (R/W 32)  -------- */
#define ARB_CORE_CTRL_RESETVALUE              _UINT32_(0x00)                                       /*  (ARB_CORE_CTRL)   Reset Value */

#define ARB_CORE_CTRL_RADIO_ARB_MODE_Pos      _UINT32_(0)                                          /* (ARB_CORE_CTRL)  Position */
#define ARB_CORE_CTRL_RADIO_ARB_MODE_Msk      (_UINT32_(0x3) << ARB_CORE_CTRL_RADIO_ARB_MODE_Pos)  /* (ARB_CORE_CTRL)  Mask */
#define ARB_CORE_CTRL_RADIO_ARB_MODE(value)   (ARB_CORE_CTRL_RADIO_ARB_MODE_Msk & (_UINT32_(value) << ARB_CORE_CTRL_RADIO_ARB_MODE_Pos)) /* Assigment of value for RADIO_ARB_MODE in the ARB_CORE_CTRL register */
#define ARB_CORE_CTRL_TESTBUS_SELECT_Pos      _UINT32_(2)                                          /* (ARB_CORE_CTRL)  Position */
#define ARB_CORE_CTRL_TESTBUS_SELECT_Msk      (_UINT32_(0x3) << ARB_CORE_CTRL_TESTBUS_SELECT_Pos)  /* (ARB_CORE_CTRL)  Mask */
#define ARB_CORE_CTRL_TESTBUS_SELECT(value)   (ARB_CORE_CTRL_TESTBUS_SELECT_Msk & (_UINT32_(value) << ARB_CORE_CTRL_TESTBUS_SELECT_Pos)) /* Assigment of value for TESTBUS_SELECT in the ARB_CORE_CTRL register */
#define ARB_CORE_CTRL_AD_ARB_SOFT_RESET_Pos   _UINT32_(8)                                          /* (ARB_CORE_CTRL)  Position */
#define ARB_CORE_CTRL_AD_ARB_SOFT_RESET_Msk   (_UINT32_(0x1) << ARB_CORE_CTRL_AD_ARB_SOFT_RESET_Pos) /* (ARB_CORE_CTRL)  Mask */
#define ARB_CORE_CTRL_AD_ARB_SOFT_RESET(value) (ARB_CORE_CTRL_AD_ARB_SOFT_RESET_Msk & (_UINT32_(value) << ARB_CORE_CTRL_AD_ARB_SOFT_RESET_Pos)) /* Assigment of value for AD_ARB_SOFT_RESET in the ARB_CORE_CTRL register */
#define ARB_CORE_CTRL_ARB_TESTBUS_BYTE_SELECT_Pos _UINT32_(9)                                          /* (ARB_CORE_CTRL)  Position */
#define ARB_CORE_CTRL_ARB_TESTBUS_BYTE_SELECT_Msk (_UINT32_(0x3) << ARB_CORE_CTRL_ARB_TESTBUS_BYTE_SELECT_Pos) /* (ARB_CORE_CTRL)  Mask */
#define ARB_CORE_CTRL_ARB_TESTBUS_BYTE_SELECT(value) (ARB_CORE_CTRL_ARB_TESTBUS_BYTE_SELECT_Msk & (_UINT32_(value) << ARB_CORE_CTRL_ARB_TESTBUS_BYTE_SELECT_Pos)) /* Assigment of value for ARB_TESTBUS_BYTE_SELECT in the ARB_CORE_CTRL register */
#define ARB_CORE_CTRL_Reserved_Pos            _UINT32_(11)                                         /* (ARB_CORE_CTRL)  Position */
#define ARB_CORE_CTRL_Reserved_Msk            (_UINT32_(0x1F) << ARB_CORE_CTRL_Reserved_Pos)       /* (ARB_CORE_CTRL)  Mask */
#define ARB_CORE_CTRL_Reserved(value)         (ARB_CORE_CTRL_Reserved_Msk & (_UINT32_(value) << ARB_CORE_CTRL_Reserved_Pos)) /* Assigment of value for Reserved in the ARB_CORE_CTRL register */
#define ARB_CORE_CTRL_RAD_ARB_TIMEOUT_Pos     _UINT32_(16)                                         /* (ARB_CORE_CTRL)  Position */
#define ARB_CORE_CTRL_RAD_ARB_TIMEOUT_Msk     (_UINT32_(0xFFFF) << ARB_CORE_CTRL_RAD_ARB_TIMEOUT_Pos) /* (ARB_CORE_CTRL)  Mask */
#define ARB_CORE_CTRL_RAD_ARB_TIMEOUT(value)  (ARB_CORE_CTRL_RAD_ARB_TIMEOUT_Msk & (_UINT32_(value) << ARB_CORE_CTRL_RAD_ARB_TIMEOUT_Pos)) /* Assigment of value for RAD_ARB_TIMEOUT in the ARB_CORE_CTRL register */
#define ARB_CORE_CTRL_Msk                     _UINT32_(0xFFFFFF0F)                                 /* (ARB_CORE_CTRL) Register Mask  */


/* -------- ARB_CORE_STATUS : (ARB Offset: 0x10) ( R/ 32)  -------- */
#define ARB_CORE_STATUS_RESETVALUE            _UINT32_(0x00)                                       /*  (ARB_CORE_STATUS)   Reset Value */

#define ARB_CORE_STATUS_ARB_CORE_STATE_Pos    _UINT32_(0)                                          /* (ARB_CORE_STATUS)  Position */
#define ARB_CORE_STATUS_ARB_CORE_STATE_Msk    (_UINT32_(0x7) << ARB_CORE_STATUS_ARB_CORE_STATE_Pos) /* (ARB_CORE_STATUS)  Mask */
#define ARB_CORE_STATUS_ARB_CORE_STATE(value) (ARB_CORE_STATUS_ARB_CORE_STATE_Msk & (_UINT32_(value) << ARB_CORE_STATUS_ARB_CORE_STATE_Pos)) /* Assigment of value for ARB_CORE_STATE in the ARB_CORE_STATUS register */
#define ARB_CORE_STATUS_CUR_RADIO_OWNER_Pos   _UINT32_(3)                                          /* (ARB_CORE_STATUS)  Position */
#define ARB_CORE_STATUS_CUR_RADIO_OWNER_Msk   (_UINT32_(0x3) << ARB_CORE_STATUS_CUR_RADIO_OWNER_Pos) /* (ARB_CORE_STATUS)  Mask */
#define ARB_CORE_STATUS_CUR_RADIO_OWNER(value) (ARB_CORE_STATUS_CUR_RADIO_OWNER_Msk & (_UINT32_(value) << ARB_CORE_STATUS_CUR_RADIO_OWNER_Pos)) /* Assigment of value for CUR_RADIO_OWNER in the ARB_CORE_STATUS register */
#define ARB_CORE_STATUS_CUR_REQ_PRI_Pos       _UINT32_(5)                                          /* (ARB_CORE_STATUS)  Position */
#define ARB_CORE_STATUS_CUR_REQ_PRI_Msk       (_UINT32_(0xF) << ARB_CORE_STATUS_CUR_REQ_PRI_Pos)   /* (ARB_CORE_STATUS)  Mask */
#define ARB_CORE_STATUS_CUR_REQ_PRI(value)    (ARB_CORE_STATUS_CUR_REQ_PRI_Msk & (_UINT32_(value) << ARB_CORE_STATUS_CUR_REQ_PRI_Pos)) /* Assigment of value for CUR_REQ_PRI in the ARB_CORE_STATUS register */
#define ARB_CORE_STATUS_Msk                   _UINT32_(0x000001FF)                                 /* (ARB_CORE_STATUS) Register Mask  */


/* -------- ARB_INT_STATUS : (ARB Offset: 0x14) (R/W 32)  -------- */
#define ARB_INT_STATUS_RESETVALUE             _UINT32_(0x00)                                       /*  (ARB_INT_STATUS)   Reset Value */

#define ARB_INT_STATUS_BT_ABORT_HIZB_Pos      _UINT32_(0)                                          /* (ARB_INT_STATUS)  Position */
#define ARB_INT_STATUS_BT_ABORT_HIZB_Msk      (_UINT32_(0x1) << ARB_INT_STATUS_BT_ABORT_HIZB_Pos)  /* (ARB_INT_STATUS)  Mask */
#define ARB_INT_STATUS_BT_ABORT_HIZB(value)   (ARB_INT_STATUS_BT_ABORT_HIZB_Msk & (_UINT32_(value) << ARB_INT_STATUS_BT_ABORT_HIZB_Pos)) /* Assigment of value for BT_ABORT_HIZB in the ARB_INT_STATUS register */
#define ARB_INT_STATUS_ZB_ABORT_HIBT_Pos      _UINT32_(1)                                          /* (ARB_INT_STATUS)  Position */
#define ARB_INT_STATUS_ZB_ABORT_HIBT_Msk      (_UINT32_(0x1) << ARB_INT_STATUS_ZB_ABORT_HIBT_Pos)  /* (ARB_INT_STATUS)  Mask */
#define ARB_INT_STATUS_ZB_ABORT_HIBT(value)   (ARB_INT_STATUS_ZB_ABORT_HIBT_Msk & (_UINT32_(value) << ARB_INT_STATUS_ZB_ABORT_HIBT_Pos)) /* Assigment of value for ZB_ABORT_HIBT in the ARB_INT_STATUS register */
#define ARB_INT_STATUS_BT_RADIO_TO_ABRT_Pos   _UINT32_(2)                                          /* (ARB_INT_STATUS)  Position */
#define ARB_INT_STATUS_BT_RADIO_TO_ABRT_Msk   (_UINT32_(0x1) << ARB_INT_STATUS_BT_RADIO_TO_ABRT_Pos) /* (ARB_INT_STATUS)  Mask */
#define ARB_INT_STATUS_BT_RADIO_TO_ABRT(value) (ARB_INT_STATUS_BT_RADIO_TO_ABRT_Msk & (_UINT32_(value) << ARB_INT_STATUS_BT_RADIO_TO_ABRT_Pos)) /* Assigment of value for BT_RADIO_TO_ABRT in the ARB_INT_STATUS register */
#define ARB_INT_STATUS_ZB_RADIO_TO_ABRT_Pos   _UINT32_(3)                                          /* (ARB_INT_STATUS)  Position */
#define ARB_INT_STATUS_ZB_RADIO_TO_ABRT_Msk   (_UINT32_(0x1) << ARB_INT_STATUS_ZB_RADIO_TO_ABRT_Pos) /* (ARB_INT_STATUS)  Mask */
#define ARB_INT_STATUS_ZB_RADIO_TO_ABRT(value) (ARB_INT_STATUS_ZB_RADIO_TO_ABRT_Msk & (_UINT32_(value) << ARB_INT_STATUS_ZB_RADIO_TO_ABRT_Pos)) /* Assigment of value for ZB_RADIO_TO_ABRT in the ARB_INT_STATUS register */
#define ARB_INT_STATUS_BT_TIMESENSE_REQ_LOSS_Pos _UINT32_(4)                                          /* (ARB_INT_STATUS)  Position */
#define ARB_INT_STATUS_BT_TIMESENSE_REQ_LOSS_Msk (_UINT32_(0x1) << ARB_INT_STATUS_BT_TIMESENSE_REQ_LOSS_Pos) /* (ARB_INT_STATUS)  Mask */
#define ARB_INT_STATUS_BT_TIMESENSE_REQ_LOSS(value) (ARB_INT_STATUS_BT_TIMESENSE_REQ_LOSS_Msk & (_UINT32_(value) << ARB_INT_STATUS_BT_TIMESENSE_REQ_LOSS_Pos)) /* Assigment of value for BT_TIMESENSE_REQ_LOSS in the ARB_INT_STATUS register */
#define ARB_INT_STATUS_ZB_TIMESENSE_REQ_LOSS_Pos _UINT32_(5)                                          /* (ARB_INT_STATUS)  Position */
#define ARB_INT_STATUS_ZB_TIMESENSE_REQ_LOSS_Msk (_UINT32_(0x1) << ARB_INT_STATUS_ZB_TIMESENSE_REQ_LOSS_Pos) /* (ARB_INT_STATUS)  Mask */
#define ARB_INT_STATUS_ZB_TIMESENSE_REQ_LOSS(value) (ARB_INT_STATUS_ZB_TIMESENSE_REQ_LOSS_Msk & (_UINT32_(value) << ARB_INT_STATUS_ZB_TIMESENSE_REQ_LOSS_Pos)) /* Assigment of value for ZB_TIMESENSE_REQ_LOSS in the ARB_INT_STATUS register */
#define ARB_INT_STATUS_Msk                    _UINT32_(0x0000003F)                                 /* (ARB_INT_STATUS) Register Mask  */


/* -------- ARB_INT_MASK : (ARB Offset: 0x18) (R/W 32)  -------- */
#define ARB_INT_MASK_RESETVALUE               _UINT32_(0x00)                                       /*  (ARB_INT_MASK)   Reset Value */

#define ARB_INT_MASK_BT_ABORT_HIZB_MSK_Pos    _UINT32_(0)                                          /* (ARB_INT_MASK)  Position */
#define ARB_INT_MASK_BT_ABORT_HIZB_MSK_Msk    (_UINT32_(0x1) << ARB_INT_MASK_BT_ABORT_HIZB_MSK_Pos) /* (ARB_INT_MASK)  Mask */
#define ARB_INT_MASK_BT_ABORT_HIZB_MSK(value) (ARB_INT_MASK_BT_ABORT_HIZB_MSK_Msk & (_UINT32_(value) << ARB_INT_MASK_BT_ABORT_HIZB_MSK_Pos)) /* Assigment of value for BT_ABORT_HIZB_MSK in the ARB_INT_MASK register */
#define ARB_INT_MASK_ZB_ABORT_HIBT_MSK_Pos    _UINT32_(1)                                          /* (ARB_INT_MASK)  Position */
#define ARB_INT_MASK_ZB_ABORT_HIBT_MSK_Msk    (_UINT32_(0x1) << ARB_INT_MASK_ZB_ABORT_HIBT_MSK_Pos) /* (ARB_INT_MASK)  Mask */
#define ARB_INT_MASK_ZB_ABORT_HIBT_MSK(value) (ARB_INT_MASK_ZB_ABORT_HIBT_MSK_Msk & (_UINT32_(value) << ARB_INT_MASK_ZB_ABORT_HIBT_MSK_Pos)) /* Assigment of value for ZB_ABORT_HIBT_MSK in the ARB_INT_MASK register */
#define ARB_INT_MASK_BT_RADIO_TO_ABRT_MSK_Pos _UINT32_(2)                                          /* (ARB_INT_MASK)  Position */
#define ARB_INT_MASK_BT_RADIO_TO_ABRT_MSK_Msk (_UINT32_(0x1) << ARB_INT_MASK_BT_RADIO_TO_ABRT_MSK_Pos) /* (ARB_INT_MASK)  Mask */
#define ARB_INT_MASK_BT_RADIO_TO_ABRT_MSK(value) (ARB_INT_MASK_BT_RADIO_TO_ABRT_MSK_Msk & (_UINT32_(value) << ARB_INT_MASK_BT_RADIO_TO_ABRT_MSK_Pos)) /* Assigment of value for BT_RADIO_TO_ABRT_MSK in the ARB_INT_MASK register */
#define ARB_INT_MASK_ZB_RADIO_TO_ABRT_MSK_Pos _UINT32_(3)                                          /* (ARB_INT_MASK)  Position */
#define ARB_INT_MASK_ZB_RADIO_TO_ABRT_MSK_Msk (_UINT32_(0x1) << ARB_INT_MASK_ZB_RADIO_TO_ABRT_MSK_Pos) /* (ARB_INT_MASK)  Mask */
#define ARB_INT_MASK_ZB_RADIO_TO_ABRT_MSK(value) (ARB_INT_MASK_ZB_RADIO_TO_ABRT_MSK_Msk & (_UINT32_(value) << ARB_INT_MASK_ZB_RADIO_TO_ABRT_MSK_Pos)) /* Assigment of value for ZB_RADIO_TO_ABRT_MSK in the ARB_INT_MASK register */
#define ARB_INT_MASK_BT_TIMESENSE_REQ_LOSS_MSK_Pos _UINT32_(4)                                          /* (ARB_INT_MASK)  Position */
#define ARB_INT_MASK_BT_TIMESENSE_REQ_LOSS_MSK_Msk (_UINT32_(0x1) << ARB_INT_MASK_BT_TIMESENSE_REQ_LOSS_MSK_Pos) /* (ARB_INT_MASK)  Mask */
#define ARB_INT_MASK_BT_TIMESENSE_REQ_LOSS_MSK(value) (ARB_INT_MASK_BT_TIMESENSE_REQ_LOSS_MSK_Msk & (_UINT32_(value) << ARB_INT_MASK_BT_TIMESENSE_REQ_LOSS_MSK_Pos)) /* Assigment of value for BT_TIMESENSE_REQ_LOSS_MSK in the ARB_INT_MASK register */
#define ARB_INT_MASK_ZB_TIMESENSE_REQ_LOSS_MSK_Pos _UINT32_(5)                                          /* (ARB_INT_MASK)  Position */
#define ARB_INT_MASK_ZB_TIMESENSE_REQ_LOSS_MSK_Msk (_UINT32_(0x1) << ARB_INT_MASK_ZB_TIMESENSE_REQ_LOSS_MSK_Pos) /* (ARB_INT_MASK)  Mask */
#define ARB_INT_MASK_ZB_TIMESENSE_REQ_LOSS_MSK(value) (ARB_INT_MASK_ZB_TIMESENSE_REQ_LOSS_MSK_Msk & (_UINT32_(value) << ARB_INT_MASK_ZB_TIMESENSE_REQ_LOSS_MSK_Pos)) /* Assigment of value for ZB_TIMESENSE_REQ_LOSS_MSK in the ARB_INT_MASK register */
#define ARB_INT_MASK_Msk                      _UINT32_(0x0000003F)                                 /* (ARB_INT_MASK) Register Mask  */


/** \brief ARB register offsets definitions */
#define ARB_BT_CTRL_REG_OFST           _UINT32_(0x00)      /* (ARB_BT_CTRL)  Offset */
#define ARB_ZB_CTRL_REG_OFST           _UINT32_(0x04)      /* (ARB_ZB_CTRL)  Offset */
#define ARB_EVENT_CTRL_REG_OFST        _UINT32_(0x08)      /* (ARB_EVENT_CTRL)  Offset */
#define ARB_CORE_CTRL_REG_OFST         _UINT32_(0x0C)      /* (ARB_CORE_CTRL)  Offset */
#define ARB_CORE_STATUS_REG_OFST       _UINT32_(0x10)      /* (ARB_CORE_STATUS)  Offset */
#define ARB_INT_STATUS_REG_OFST        _UINT32_(0x14)      /* (ARB_INT_STATUS)  Offset */
#define ARB_INT_MASK_REG_OFST          _UINT32_(0x18)      /* (ARB_INT_MASK)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief ARB register API structure */
typedef struct
{  /*  */
  __IO  uint32_t                       ARB_BT_CTRL;        /**< Offset: 0x00 (R/W  32)  */
  __IO  uint32_t                       ARB_ZB_CTRL;        /**< Offset: 0x04 (R/W  32)  */
  __IO  uint32_t                       ARB_EVENT_CTRL;     /**< Offset: 0x08 (R/W  32)  */
  __IO  uint32_t                       ARB_CORE_CTRL;      /**< Offset: 0x0C (R/W  32)  */
  __I   uint32_t                       ARB_CORE_STATUS;    /**< Offset: 0x10 (R/   32)  */
  __IO  uint32_t                       ARB_INT_STATUS;     /**< Offset: 0x14 (R/W  32)  */
  __IO  uint32_t                       ARB_INT_MASK;       /**< Offset: 0x18 (R/W  32)  */
} arb_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_ARB_COMPONENT_H_ */
