/*
 * Component description for RCON
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
#ifndef _BZ45_RCON_COMPONENT_H_
#define _BZ45_RCON_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR RCON                                         */
/* ************************************************************************** */

/* -------- RCON_RCON : (RCON Offset: 0x30) (R/W 32) RESET CONTROL REGISTER -------- */
#define RCON_RCON_RESETVALUE                  _UINT32_(0x03)                                       /*  (RCON_RCON) RESET CONTROL REGISTER  Reset Value */

#define RCON_RCON_POR_Pos                     _UINT32_(0)                                          /* (RCON_RCON) Power-On Reset Flag bit Position */
#define RCON_RCON_POR_Msk                     (_UINT32_(0x1) << RCON_RCON_POR_Pos)                 /* (RCON_RCON) Power-On Reset Flag bit Mask */
#define RCON_RCON_POR(value)                  (RCON_RCON_POR_Msk & (_UINT32_(value) << RCON_RCON_POR_Pos)) /* Assigment of value for POR in the RCON_RCON register */
#define   RCON_RCON_POR_POR_Val               _UINT32_(0x1)                                        /* (RCON_RCON) A Power-up Reset has occurred.  */
#define   RCON_RCON_POR_NO_POR_Val            _UINT32_(0x0)                                        /* (RCON_RCON) A Power-up Reset has not occurred.  */
#define RCON_RCON_POR_POR                     (RCON_RCON_POR_POR_Val << RCON_RCON_POR_Pos)         /* (RCON_RCON) A Power-up Reset has occurred. Position  */
#define RCON_RCON_POR_NO_POR                  (RCON_RCON_POR_NO_POR_Val << RCON_RCON_POR_Pos)      /* (RCON_RCON) A Power-up Reset has not occurred. Position  */
#define RCON_RCON_BOR_Pos                     _UINT32_(1)                                          /* (RCON_RCON) Brown-out Reset Flag bit Position */
#define RCON_RCON_BOR_Msk                     (_UINT32_(0x1) << RCON_RCON_BOR_Pos)                 /* (RCON_RCON) Brown-out Reset Flag bit Mask */
#define RCON_RCON_BOR(value)                  (RCON_RCON_BOR_Msk & (_UINT32_(value) << RCON_RCON_BOR_Pos)) /* Assigment of value for BOR in the RCON_RCON register */
#define   RCON_RCON_BOR_BOR_Val               _UINT32_(0x1)                                        /* (RCON_RCON) A Brown-out Reset has occurred.  */
#define   RCON_RCON_BOR_NO_BOR_Val            _UINT32_(0x0)                                        /* (RCON_RCON) A Brown-out Reset has not occurred.  */
#define RCON_RCON_BOR_BOR                     (RCON_RCON_BOR_BOR_Val << RCON_RCON_BOR_Pos)         /* (RCON_RCON) A Brown-out Reset has occurred. Position  */
#define RCON_RCON_BOR_NO_BOR                  (RCON_RCON_BOR_NO_BOR_Val << RCON_RCON_BOR_Pos)      /* (RCON_RCON) A Brown-out Reset has not occurred. Position  */
#define RCON_RCON_IDLE_Pos                    _UINT32_(2)                                          /* (RCON_RCON) Wake from Idle Flag bit Position */
#define RCON_RCON_IDLE_Msk                    (_UINT32_(0x1) << RCON_RCON_IDLE_Pos)                /* (RCON_RCON) Wake from Idle Flag bit Mask */
#define RCON_RCON_IDLE(value)                 (RCON_RCON_IDLE_Msk & (_UINT32_(value) << RCON_RCON_IDLE_Pos)) /* Assigment of value for IDLE in the RCON_RCON register */
#define   RCON_RCON_IDLE_IDLE_Val             _UINT32_(0x1)                                        /* (RCON_RCON) Device was in Idle mode.  */
#define   RCON_RCON_IDLE_NOT_IDLE_Val         _UINT32_(0x0)                                        /* (RCON_RCON) Device was not in Idle mode.  */
#define RCON_RCON_IDLE_IDLE                   (RCON_RCON_IDLE_IDLE_Val << RCON_RCON_IDLE_Pos)      /* (RCON_RCON) Device was in Idle mode. Position  */
#define RCON_RCON_IDLE_NOT_IDLE               (RCON_RCON_IDLE_NOT_IDLE_Val << RCON_RCON_IDLE_Pos)  /* (RCON_RCON) Device was not in Idle mode. Position  */
#define RCON_RCON_SLEEP_Pos                   _UINT32_(3)                                          /* (RCON_RCON) Wake from Sleep Flag bit Position */
#define RCON_RCON_SLEEP_Msk                   (_UINT32_(0x1) << RCON_RCON_SLEEP_Pos)               /* (RCON_RCON) Wake from Sleep Flag bit Mask */
#define RCON_RCON_SLEEP(value)                (RCON_RCON_SLEEP_Msk & (_UINT32_(value) << RCON_RCON_SLEEP_Pos)) /* Assigment of value for SLEEP in the RCON_RCON register */
#define   RCON_RCON_SLEEP_SLEEP_Val           _UINT32_(0x1)                                        /* (RCON_RCON) Device has been in Sleep mode.  */
#define   RCON_RCON_SLEEP_NOT_SLEEP_Val       _UINT32_(0x0)                                        /* (RCON_RCON) Device has not been in Sleep mode.  */
#define RCON_RCON_SLEEP_SLEEP                 (RCON_RCON_SLEEP_SLEEP_Val << RCON_RCON_SLEEP_Pos)   /* (RCON_RCON) Device has been in Sleep mode. Position  */
#define RCON_RCON_SLEEP_NOT_SLEEP             (RCON_RCON_SLEEP_NOT_SLEEP_Val << RCON_RCON_SLEEP_Pos) /* (RCON_RCON) Device has not been in Sleep mode. Position  */
#define RCON_RCON_WDTO_Pos                    _UINT32_(4)                                          /* (RCON_RCON) Watchdog Timer Time-Out Flag bit Position */
#define RCON_RCON_WDTO_Msk                    (_UINT32_(0x1) << RCON_RCON_WDTO_Pos)                /* (RCON_RCON) Watchdog Timer Time-Out Flag bit Mask */
#define RCON_RCON_WDTO(value)                 (RCON_RCON_WDTO_Msk & (_UINT32_(value) << RCON_RCON_WDTO_Pos)) /* Assigment of value for WDTO in the RCON_RCON register */
#define   RCON_RCON_WDTO_WDTO_Val             _UINT32_(0x1)                                        /* (RCON_RCON) WDT Time-out has occurred and caused a reset.  */
#define   RCON_RCON_WDTO_NOT_WDTO_Val         _UINT32_(0x0)                                        /* (RCON_RCON) WDT Time-out has not occurred.  */
#define RCON_RCON_WDTO_WDTO                   (RCON_RCON_WDTO_WDTO_Val << RCON_RCON_WDTO_Pos)      /* (RCON_RCON) WDT Time-out has occurred and caused a reset. Position  */
#define RCON_RCON_WDTO_NOT_WDTO               (RCON_RCON_WDTO_NOT_WDTO_Val << RCON_RCON_WDTO_Pos)  /* (RCON_RCON) WDT Time-out has not occurred. Position  */
#define RCON_RCON_DMTO_Pos                    _UINT32_(5)                                          /* (RCON_RCON) Deadman Timer Time-Out Flag bit Position */
#define RCON_RCON_DMTO_Msk                    (_UINT32_(0x1) << RCON_RCON_DMTO_Pos)                /* (RCON_RCON) Deadman Timer Time-Out Flag bit Mask */
#define RCON_RCON_DMTO(value)                 (RCON_RCON_DMTO_Msk & (_UINT32_(value) << RCON_RCON_DMTO_Pos)) /* Assigment of value for DMTO in the RCON_RCON register */
#define   RCON_RCON_DMTO_DMTO_Val             _UINT32_(0x1)                                        /* (RCON_RCON) DMT Time-out has occurred and caused a reset.  */
#define   RCON_RCON_DMTO_NOT_DMTO_Val         _UINT32_(0x0)                                        /* (RCON_RCON) DMT Time-out has not occurred.  */
#define RCON_RCON_DMTO_DMTO                   (RCON_RCON_DMTO_DMTO_Val << RCON_RCON_DMTO_Pos)      /* (RCON_RCON) DMT Time-out has occurred and caused a reset. Position  */
#define RCON_RCON_DMTO_NOT_DMTO               (RCON_RCON_DMTO_NOT_DMTO_Val << RCON_RCON_DMTO_Pos)  /* (RCON_RCON) DMT Time-out has not occurred. Position  */
#define RCON_RCON_SWR_Pos                     _UINT32_(6)                                          /* (RCON_RCON) Software Reset Flag bit Position */
#define RCON_RCON_SWR_Msk                     (_UINT32_(0x1) << RCON_RCON_SWR_Pos)                 /* (RCON_RCON) Software Reset Flag bit Mask */
#define RCON_RCON_SWR(value)                  (RCON_RCON_SWR_Msk & (_UINT32_(value) << RCON_RCON_SWR_Pos)) /* Assigment of value for SWR in the RCON_RCON register */
#define   RCON_RCON_SWR_SWR_Val               _UINT32_(0x1)                                        /* (RCON_RCON) A Software Commanded Reset has occurred.  */
#define   RCON_RCON_SWR_NOT_SWR_Val           _UINT32_(0x0)                                        /* (RCON_RCON) A Software Commanded Reset has not occurred.  */
#define RCON_RCON_SWR_SWR                     (RCON_RCON_SWR_SWR_Val << RCON_RCON_SWR_Pos)         /* (RCON_RCON) A Software Commanded Reset has occurred. Position  */
#define RCON_RCON_SWR_NOT_SWR                 (RCON_RCON_SWR_NOT_SWR_Val << RCON_RCON_SWR_Pos)     /* (RCON_RCON) A Software Commanded Reset has not occurred. Position  */
#define RCON_RCON_EXTR_Pos                    _UINT32_(7)                                          /* (RCON_RCON) External Reset (MCLR) Status bit Position */
#define RCON_RCON_EXTR_Msk                    (_UINT32_(0x1) << RCON_RCON_EXTR_Pos)                /* (RCON_RCON) External Reset (MCLR) Status bit Mask */
#define RCON_RCON_EXTR(value)                 (RCON_RCON_EXTR_Msk & (_UINT32_(value) << RCON_RCON_EXTR_Pos)) /* Assigment of value for EXTR in the RCON_RCON register */
#define   RCON_RCON_EXTR_EXTR_Val             _UINT32_(0x1)                                        /* (RCON_RCON) A Master Clear (pin) Reset has occurred.  */
#define   RCON_RCON_EXTR_NOT_EXTR_Val         _UINT32_(0x0)                                        /* (RCON_RCON) A Master Clear (pin) Reset has not occurred.  */
#define RCON_RCON_EXTR_EXTR                   (RCON_RCON_EXTR_EXTR_Val << RCON_RCON_EXTR_Pos)      /* (RCON_RCON) A Master Clear (pin) Reset has occurred. Position  */
#define RCON_RCON_EXTR_NOT_EXTR               (RCON_RCON_EXTR_NOT_EXTR_Val << RCON_RCON_EXTR_Pos)  /* (RCON_RCON) A Master Clear (pin) Reset has not occurred. Position  */
#define RCON_RCON_CMR_Pos                     _UINT32_(9)                                          /* (RCON_RCON) Configuration Mismatch Flag bit Position */
#define RCON_RCON_CMR_Msk                     (_UINT32_(0x1) << RCON_RCON_CMR_Pos)                 /* (RCON_RCON) Configuration Mismatch Flag bit Mask */
#define RCON_RCON_CMR(value)                  (RCON_RCON_CMR_Msk & (_UINT32_(value) << RCON_RCON_CMR_Pos)) /* Assigment of value for CMR in the RCON_RCON register */
#define   RCON_RCON_CMR_CMR_Val               _UINT32_(0x1)                                        /* (RCON_RCON) A Configuration Mismatch Reset Event has occurred.  */
#define   RCON_RCON_CMR_NOT_CMR_Val           _UINT32_(0x0)                                        /* (RCON_RCON) A Configuration Mismatch Reset Event has not occurred.  */
#define RCON_RCON_CMR_CMR                     (RCON_RCON_CMR_CMR_Val << RCON_RCON_CMR_Pos)         /* (RCON_RCON) A Configuration Mismatch Reset Event has occurred. Position  */
#define RCON_RCON_CMR_NOT_CMR                 (RCON_RCON_CMR_NOT_CMR_Val << RCON_RCON_CMR_Pos)     /* (RCON_RCON) A Configuration Mismatch Reset Event has not occurred. Position  */
#define RCON_RCON_DPSLP_Pos                   _UINT32_(10)                                         /* (RCON_RCON) DPSLP Deep Sleep Mode Flag Bit Position */
#define RCON_RCON_DPSLP_Msk                   (_UINT32_(0x1) << RCON_RCON_DPSLP_Pos)               /* (RCON_RCON) DPSLP Deep Sleep Mode Flag Bit Mask */
#define RCON_RCON_DPSLP(value)                (RCON_RCON_DPSLP_Msk & (_UINT32_(value) << RCON_RCON_DPSLP_Pos)) /* Assigment of value for DPSLP in the RCON_RCON register */
#define   RCON_RCON_DPSLP_DSLP_Val            _UINT32_(0x1)                                        /* (RCON_RCON) Deep Sleep Mode has occurred.  */
#define   RCON_RCON_DPSLP_NOT_DSLP_Val        _UINT32_(0x0)                                        /* (RCON_RCON) Deep Sleep Mode has not occurred.  */
#define RCON_RCON_DPSLP_DSLP                  (RCON_RCON_DPSLP_DSLP_Val << RCON_RCON_DPSLP_Pos)    /* (RCON_RCON) Deep Sleep Mode has occurred. Position  */
#define RCON_RCON_DPSLP_NOT_DSLP              (RCON_RCON_DPSLP_NOT_DSLP_Val << RCON_RCON_DPSLP_Pos) /* (RCON_RCON) Deep Sleep Mode has not occurred. Position  */
#define RCON_RCON_NVMEOL_Pos                  _UINT32_(24)                                         /* (RCON_RCON) NVM End of Life Flag Bit Position */
#define RCON_RCON_NVMEOL_Msk                  (_UINT32_(0x1) << RCON_RCON_NVMEOL_Pos)              /* (RCON_RCON) NVM End of Life Flag Bit Mask */
#define RCON_RCON_NVMEOL(value)               (RCON_RCON_NVMEOL_Msk & (_UINT32_(value) << RCON_RCON_NVMEOL_Pos)) /* Assigment of value for NVMEOL in the RCON_RCON register */
#define   RCON_RCON_NVMEOL_NO_NVMEOL_Val      _UINT32_(0x0)                                        /* (RCON_RCON) A NVM EOL Failure has not occurred.  */
#define   RCON_RCON_NVMEOL_NVMEOL_Val         _UINT32_(0x1)                                        /* (RCON_RCON) A NVM EOL Failure has occurred.  */
#define RCON_RCON_NVMEOL_NO_NVMEOL            (RCON_RCON_NVMEOL_NO_NVMEOL_Val << RCON_RCON_NVMEOL_Pos) /* (RCON_RCON) A NVM EOL Failure has not occurred. Position  */
#define RCON_RCON_NVMEOL_NVMEOL               (RCON_RCON_NVMEOL_NVMEOL_Val << RCON_RCON_NVMEOL_Pos) /* (RCON_RCON) A NVM EOL Failure has occurred. Position  */
#define RCON_RCON_NVMLTA_Pos                  _UINT32_(25)                                         /* (RCON_RCON) NVM Life Time Alert Flag Bit Position */
#define RCON_RCON_NVMLTA_Msk                  (_UINT32_(0x1) << RCON_RCON_NVMLTA_Pos)              /* (RCON_RCON) NVM Life Time Alert Flag Bit Mask */
#define RCON_RCON_NVMLTA(value)               (RCON_RCON_NVMLTA_Msk & (_UINT32_(value) << RCON_RCON_NVMLTA_Pos)) /* Assigment of value for NVMLTA in the RCON_RCON register */
#define   RCON_RCON_NVMLTA_NO_NVMLTA_Val      _UINT32_(0x0)                                        /* (RCON_RCON) A NVM LTA Error has not occurred.  */
#define   RCON_RCON_NVMLTA_NVMLTA_Val         _UINT32_(0x1)                                        /* (RCON_RCON) A NVM LTA Error has occurred.  */
#define RCON_RCON_NVMLTA_NO_NVMLTA            (RCON_RCON_NVMLTA_NO_NVMLTA_Val << RCON_RCON_NVMLTA_Pos) /* (RCON_RCON) A NVM LTA Error has not occurred. Position  */
#define RCON_RCON_NVMLTA_NVMLTA               (RCON_RCON_NVMLTA_NVMLTA_Val << RCON_RCON_NVMLTA_Pos) /* (RCON_RCON) A NVM LTA Error has occurred. Position  */
#define RCON_RCON_BCFGFAIL_Pos                _UINT32_(26)                                         /* (RCON_RCON) BCFG Failure Flag Bit Position */
#define RCON_RCON_BCFGFAIL_Msk                (_UINT32_(0x1) << RCON_RCON_BCFGFAIL_Pos)            /* (RCON_RCON) BCFG Failure Flag Bit Mask */
#define RCON_RCON_BCFGFAIL(value)             (RCON_RCON_BCFGFAIL_Msk & (_UINT32_(value) << RCON_RCON_BCFGFAIL_Pos)) /* Assigment of value for BCFGFAIL in the RCON_RCON register */
#define   RCON_RCON_BCFGFAIL_NO_BCFGFAIL_Val  _UINT32_(0x0)                                        /* (RCON_RCON) A BCFG Failure has not occurred.  */
#define   RCON_RCON_BCFGFAIL_BCFGFAIL_Val     _UINT32_(0x1)                                        /* (RCON_RCON) A BCFG Failure has occurred.  */
#define RCON_RCON_BCFGFAIL_NO_BCFGFAIL        (RCON_RCON_BCFGFAIL_NO_BCFGFAIL_Val << RCON_RCON_BCFGFAIL_Pos) /* (RCON_RCON) A BCFG Failure has not occurred. Position  */
#define RCON_RCON_BCFGFAIL_BCFGFAIL           (RCON_RCON_BCFGFAIL_BCFGFAIL_Val << RCON_RCON_BCFGFAIL_Pos) /* (RCON_RCON) A BCFG Failure has occurred. Position  */
#define RCON_RCON_BCFGERR_Pos                 _UINT32_(27)                                         /* (RCON_RCON) BCFG Error Flag Bit Position */
#define RCON_RCON_BCFGERR_Msk                 (_UINT32_(0x1) << RCON_RCON_BCFGERR_Pos)             /* (RCON_RCON) BCFG Error Flag Bit Mask */
#define RCON_RCON_BCFGERR(value)              (RCON_RCON_BCFGERR_Msk & (_UINT32_(value) << RCON_RCON_BCFGERR_Pos)) /* Assigment of value for BCFGERR in the RCON_RCON register */
#define   RCON_RCON_BCFGERR_NO_BCFGERR_Val    _UINT32_(0x0)                                        /* (RCON_RCON) A BCFG Error has not occurred.  */
#define   RCON_RCON_BCFGERR_BCFGERR_Val       _UINT32_(0x1)                                        /* (RCON_RCON) A BCFG Error has occurred.  */
#define RCON_RCON_BCFGERR_NO_BCFGERR          (RCON_RCON_BCFGERR_NO_BCFGERR_Val << RCON_RCON_BCFGERR_Pos) /* (RCON_RCON) A BCFG Error has not occurred. Position  */
#define RCON_RCON_BCFGERR_BCFGERR             (RCON_RCON_BCFGERR_BCFGERR_Val << RCON_RCON_BCFGERR_Pos) /* (RCON_RCON) A BCFG Error has occurred. Position  */
#define RCON_RCON_PORCORE_Pos                 _UINT32_(30)                                         /* (RCON_RCON) Core Voltage POR Flag bit Position */
#define RCON_RCON_PORCORE_Msk                 (_UINT32_(0x1) << RCON_RCON_PORCORE_Pos)             /* (RCON_RCON) Core Voltage POR Flag bit Mask */
#define RCON_RCON_PORCORE(value)              (RCON_RCON_PORCORE_Msk & (_UINT32_(value) << RCON_RCON_PORCORE_Pos)) /* Assigment of value for PORCORE in the RCON_RCON register */
#define   RCON_RCON_PORCORE_PORCORE_Val       _UINT32_(0x1)                                        /* (RCON_RCON) A Power-up Reset has occurred due to Core Voltage.  */
#define   RCON_RCON_PORCORE_NO_PORCORE_Val    _UINT32_(0x0)                                        /* (RCON_RCON) A Power-up Reset has not occurred due to Core Voltage.  */
#define RCON_RCON_PORCORE_PORCORE             (RCON_RCON_PORCORE_PORCORE_Val << RCON_RCON_PORCORE_Pos) /* (RCON_RCON) A Power-up Reset has occurred due to Core Voltage. Position  */
#define RCON_RCON_PORCORE_NO_PORCORE          (RCON_RCON_PORCORE_NO_PORCORE_Val << RCON_RCON_PORCORE_Pos) /* (RCON_RCON) A Power-up Reset has not occurred due to Core Voltage. Position  */
#define RCON_RCON_PORIO_Pos                   _UINT32_(31)                                         /* (RCON_RCON) IO Voltage POR Flag bit Position */
#define RCON_RCON_PORIO_Msk                   (_UINT32_(0x1) << RCON_RCON_PORIO_Pos)               /* (RCON_RCON) IO Voltage POR Flag bit Mask */
#define RCON_RCON_PORIO(value)                (RCON_RCON_PORIO_Msk & (_UINT32_(value) << RCON_RCON_PORIO_Pos)) /* Assigment of value for PORIO in the RCON_RCON register */
#define   RCON_RCON_PORIO_PORIO_Val           _UINT32_(0x1)                                        /* (RCON_RCON) A Power-up Reset has occurred due to IO Voltage.  */
#define   RCON_RCON_PORIO_NO_PORIO_Val        _UINT32_(0x0)                                        /* (RCON_RCON) A Power-up Reset has not occurred due to IO Voltage.  */
#define RCON_RCON_PORIO_PORIO                 (RCON_RCON_PORIO_PORIO_Val << RCON_RCON_PORIO_Pos)   /* (RCON_RCON) A Power-up Reset has occurred due to IO Voltage. Position  */
#define RCON_RCON_PORIO_NO_PORIO              (RCON_RCON_PORIO_NO_PORIO_Val << RCON_RCON_PORIO_Pos) /* (RCON_RCON) A Power-up Reset has not occurred due to IO Voltage. Position  */
#define RCON_RCON_Msk                         _UINT32_(0xCF0006FF)                                 /* (RCON_RCON) Register Mask  */


/* -------- RCON_RCONCLR : (RCON Offset: 0x34) (R/W 32)  -------- */
#define RCON_RCONCLR_RESETVALUE               _UINT32_(0x00)                                       /*  (RCON_RCONCLR)   Reset Value */

#define RCON_RCONCLR_Msk                      _UINT32_(0x00000000)                                 /* (RCON_RCONCLR) Register Mask  */


/* -------- RCON_RCONSET : (RCON Offset: 0x38) (R/W 32)  -------- */
#define RCON_RCONSET_RESETVALUE               _UINT32_(0x00)                                       /*  (RCON_RCONSET)   Reset Value */

#define RCON_RCONSET_Msk                      _UINT32_(0x00000000)                                 /* (RCON_RCONSET) Register Mask  */


/* -------- RCON_RCONINV : (RCON Offset: 0x3C) (R/W 32)  -------- */
#define RCON_RCONINV_RESETVALUE               _UINT32_(0x00)                                       /*  (RCON_RCONINV)   Reset Value */

#define RCON_RCONINV_Msk                      _UINT32_(0x00000000)                                 /* (RCON_RCONINV) Register Mask  */


/* -------- RCON_RSWRST : (RCON Offset: 0x40) ( /W 32) SOFTWARE RESET REGISTER -------- */
#define RCON_RSWRST_RESETVALUE                _UINT32_(0x00)                                       /*  (RCON_RSWRST) SOFTWARE RESET REGISTER  Reset Value */

#define RCON_RSWRST_SWRST_Pos                 _UINT32_(0)                                          /* (RCON_RSWRST) Software Reset Trigger Position */
#define RCON_RSWRST_SWRST_Msk                 (_UINT32_(0x1) << RCON_RSWRST_SWRST_Pos)             /* (RCON_RSWRST) Software Reset Trigger Mask */
#define RCON_RSWRST_SWRST(value)              (RCON_RSWRST_SWRST_Msk & (_UINT32_(value) << RCON_RSWRST_SWRST_Pos)) /* Assigment of value for SWRST in the RCON_RSWRST register */
#define   RCON_RSWRST_SWRST_SWRST_Val         _UINT32_(0x1)                                        /* (RCON_RSWRST) Enable software reset event  */
#define   RCON_RSWRST_SWRST_NO_SWRST_Val      _UINT32_(0x0)                                        /* (RCON_RSWRST) Do not enable software reset event  */
#define RCON_RSWRST_SWRST_SWRST               (RCON_RSWRST_SWRST_SWRST_Val << RCON_RSWRST_SWRST_Pos) /* (RCON_RSWRST) Enable software reset event Position  */
#define RCON_RSWRST_SWRST_NO_SWRST            (RCON_RSWRST_SWRST_NO_SWRST_Val << RCON_RSWRST_SWRST_Pos) /* (RCON_RSWRST) Do not enable software reset event Position  */
#define RCON_RSWRST_Msk                       _UINT32_(0x00000001)                                 /* (RCON_RSWRST) Register Mask  */


/* -------- RCON_RSWRSTCLR : (RCON Offset: 0x44) (R/W 32)  -------- */
#define RCON_RSWRSTCLR_RESETVALUE             _UINT32_(0x00)                                       /*  (RCON_RSWRSTCLR)   Reset Value */

#define RCON_RSWRSTCLR_Msk                    _UINT32_(0x00000000)                                 /* (RCON_RSWRSTCLR) Register Mask  */


/* -------- RCON_RSWRSTSET : (RCON Offset: 0x48) (R/W 32)  -------- */
#define RCON_RSWRSTSET_RESETVALUE             _UINT32_(0x00)                                       /*  (RCON_RSWRSTSET)   Reset Value */

#define RCON_RSWRSTSET_Msk                    _UINT32_(0x00000000)                                 /* (RCON_RSWRSTSET) Register Mask  */


/* -------- RCON_RSWRSTINV : (RCON Offset: 0x4C) (R/W 32)  -------- */
#define RCON_RSWRSTINV_RESETVALUE             _UINT32_(0x00)                                       /*  (RCON_RSWRSTINV)   Reset Value */

#define RCON_RSWRSTINV_Msk                    _UINT32_(0x00000000)                                 /* (RCON_RSWRSTINV) Register Mask  */


/* -------- RCON_RNMICON : (RCON Offset: 0x50) (R/W 32) NMI CONTROL REGISTER -------- */
#define RCON_RNMICON_RESETVALUE               _UINT32_(0x00)                                       /*  (RCON_RNMICON) NMI CONTROL REGISTER  Reset Value */

#define RCON_RNMICON_NMICNT_Pos               _UINT32_(0)                                          /* (RCON_RNMICON) NMI Reset counter value Position */
#define RCON_RNMICON_NMICNT_Msk               (_UINT32_(0xFFFF) << RCON_RNMICON_NMICNT_Pos)        /* (RCON_RNMICON) NMI Reset counter value Mask */
#define RCON_RNMICON_NMICNT(value)            (RCON_RNMICON_NMICNT_Msk & (_UINT32_(value) << RCON_RNMICON_NMICNT_Pos)) /* Assigment of value for NMICNT in the RCON_RNMICON register */
#define   RCON_RNMICON_NMICNT_NODLY_Val       _UINT32_(0x0)                                        /* (RCON_RNMICON) No delay between NMI assertion and device reset event  */
#define   RCON_RNMICON_NMICNT_1CLKDLY_Val     _UINT32_(0x1)                                        /* (RCON_RNMICON) 1 sys_clk cycle that Software has to clear the NMI event before a device reset is performed.  */
#define   RCON_RNMICON_NMICNT_2CLKDLY_Val     _UINT32_(0x2)                                        /* (RCON_RNMICON) 2 sys_clk cycles that Software has to clear the NMI event before a device reset is performed.  */
#define   RCON_RNMICON_NMICNT_64KCLKDLY_Val   _UINT32_(0xFFFF)                                     /* (RCON_RNMICON) 65535 sys_clk cycles that Software has to clear the NMI event before a device reset is performed.  */
#define RCON_RNMICON_NMICNT_NODLY             (RCON_RNMICON_NMICNT_NODLY_Val << RCON_RNMICON_NMICNT_Pos) /* (RCON_RNMICON) No delay between NMI assertion and device reset event Position  */
#define RCON_RNMICON_NMICNT_1CLKDLY           (RCON_RNMICON_NMICNT_1CLKDLY_Val << RCON_RNMICON_NMICNT_Pos) /* (RCON_RNMICON) 1 sys_clk cycle that Software has to clear the NMI event before a device reset is performed. Position  */
#define RCON_RNMICON_NMICNT_2CLKDLY           (RCON_RNMICON_NMICNT_2CLKDLY_Val << RCON_RNMICON_NMICNT_Pos) /* (RCON_RNMICON) 2 sys_clk cycles that Software has to clear the NMI event before a device reset is performed. Position  */
#define RCON_RNMICON_NMICNT_64KCLKDLY         (RCON_RNMICON_NMICNT_64KCLKDLY_Val << RCON_RNMICON_NMICNT_Pos) /* (RCON_RNMICON) 65535 sys_clk cycles that Software has to clear the NMI event before a device reset is performed. Position  */
#define RCON_RNMICON_WDTS_Pos                 _UINT32_(16)                                         /* (RCON_RNMICON) Watch-Dog Timer Time-Out in Sleep Flag bit Position */
#define RCON_RNMICON_WDTS_Msk                 (_UINT32_(0x1) << RCON_RNMICON_WDTS_Pos)             /* (RCON_RNMICON) Watch-Dog Timer Time-Out in Sleep Flag bit Mask */
#define RCON_RNMICON_WDTS(value)              (RCON_RNMICON_WDTS_Msk & (_UINT32_(value) << RCON_RNMICON_WDTS_Pos)) /* Assigment of value for WDTS in the RCON_RNMICON register */
#define   RCON_RNMICON_WDTS_WDTS_Val          _UINT32_(0x1)                                        /* (RCON_RNMICON) WDT Time-out has occurred during sleep_mode and caused a wake-up from sleep.  */
#define   RCON_RNMICON_WDTS_NO_WDTS_Val       _UINT32_(0x0)                                        /* (RCON_RNMICON) WDT Time-out has not occurred during sleep_mode.  */
#define RCON_RNMICON_WDTS_WDTS                (RCON_RNMICON_WDTS_WDTS_Val << RCON_RNMICON_WDTS_Pos) /* (RCON_RNMICON) WDT Time-out has occurred during sleep_mode and caused a wake-up from sleep. Position  */
#define RCON_RNMICON_WDTS_NO_WDTS             (RCON_RNMICON_WDTS_NO_WDTS_Val << RCON_RNMICON_WDTS_Pos) /* (RCON_RNMICON) WDT Time-out has not occurred during sleep_mode. Position  */
#define RCON_RNMICON_CF_Pos                   _UINT32_(17)                                         /* (RCON_RNMICON) Clock Fail Detect bit Position */
#define RCON_RNMICON_CF_Msk                   (_UINT32_(0x1) << RCON_RNMICON_CF_Pos)               /* (RCON_RNMICON) Clock Fail Detect bit Mask */
#define RCON_RNMICON_CF(value)                (RCON_RNMICON_CF_Msk & (_UINT32_(value) << RCON_RNMICON_CF_Pos)) /* Assigment of value for CF in the RCON_RNMICON register */
#define   RCON_RNMICON_CF_CFAIL_Val           _UINT32_(0x1)                                        /* (RCON_RNMICON) FSCM has detected clock failure and caused an NMI  */
#define   RCON_RNMICON_CF_NO_FAILDET_Val      _UINT32_(0x0)                                        /* (RCON_RNMICON) FSCM has not detected clock failure  */
#define RCON_RNMICON_CF_CFAIL                 (RCON_RNMICON_CF_CFAIL_Val << RCON_RNMICON_CF_Pos)   /* (RCON_RNMICON) FSCM has detected clock failure and caused an NMI Position  */
#define RCON_RNMICON_CF_NO_FAILDET            (RCON_RNMICON_CF_NO_FAILDET_Val << RCON_RNMICON_CF_Pos) /* (RCON_RNMICON) FSCM has not detected clock failure Position  */
#define RCON_RNMICON_LVD_Pos                  _UINT32_(18)                                         /* (RCON_RNMICON) Programmable Low Voltage Detect Event Position */
#define RCON_RNMICON_LVD_Msk                  (_UINT32_(0x1) << RCON_RNMICON_LVD_Pos)              /* (RCON_RNMICON) Programmable Low Voltage Detect Event Mask */
#define RCON_RNMICON_LVD(value)               (RCON_RNMICON_LVD_Msk & (_UINT32_(value) << RCON_RNMICON_LVD_Pos)) /* Assigment of value for LVD in the RCON_RNMICON register */
#define   RCON_RNMICON_LVD_LVD_Val            _UINT32_(0x1)                                        /* (RCON_RNMICON) PLVD has detected a low voltage condition and caused an NMI  */
#define   RCON_RNMICON_LVD_NO_LVD_Val         _UINT32_(0x0)                                        /* (RCON_RNMICON) PLVD has not detected a low voltage condition  */
#define RCON_RNMICON_LVD_LVD                  (RCON_RNMICON_LVD_LVD_Val << RCON_RNMICON_LVD_Pos)   /* (RCON_RNMICON) PLVD has detected a low voltage condition and caused an NMI Position  */
#define RCON_RNMICON_LVD_NO_LVD               (RCON_RNMICON_LVD_NO_LVD_Val << RCON_RNMICON_LVD_Pos) /* (RCON_RNMICON) PLVD has not detected a low voltage condition Position  */
#define RCON_RNMICON_GNMI_Pos                 _UINT32_(19)                                         /* (RCON_RNMICON) External / Generic NMI Event Position */
#define RCON_RNMICON_GNMI_Msk                 (_UINT32_(0x1) << RCON_RNMICON_GNMI_Pos)             /* (RCON_RNMICON) External / Generic NMI Event Mask */
#define RCON_RNMICON_GNMI(value)              (RCON_RNMICON_GNMI_Msk & (_UINT32_(value) << RCON_RNMICON_GNMI_Pos)) /* Assigment of value for GNMI in the RCON_RNMICON register */
#define   RCON_RNMICON_GNMI_NMI_Val           _UINT32_(0x1)                                        /* (RCON_RNMICON) A general NMI event has been detected and caused an NMI  */
#define   RCON_RNMICON_GNMI_NO_NMI_Val        _UINT32_(0x0)                                        /* (RCON_RNMICON) A general NMI event has not been detected.  */
#define RCON_RNMICON_GNMI_NMI                 (RCON_RNMICON_GNMI_NMI_Val << RCON_RNMICON_GNMI_Pos) /* (RCON_RNMICON) A general NMI event has been detected and caused an NMI Position  */
#define RCON_RNMICON_GNMI_NO_NMI              (RCON_RNMICON_GNMI_NO_NMI_Val << RCON_RNMICON_GNMI_Pos) /* (RCON_RNMICON) A general NMI event has not been detected. Position  */
#define RCON_RNMICON_SWNMI_Pos                _UINT32_(23)                                         /* (RCON_RNMICON) Software NMI Trigger Position */
#define RCON_RNMICON_SWNMI_Msk                (_UINT32_(0x1) << RCON_RNMICON_SWNMI_Pos)            /* (RCON_RNMICON) Software NMI Trigger Mask */
#define RCON_RNMICON_SWNMI(value)             (RCON_RNMICON_SWNMI_Msk & (_UINT32_(value) << RCON_RNMICON_SWNMI_Pos)) /* Assigment of value for SWNMI in the RCON_RNMICON register */
#define   RCON_RNMICON_SWNMI_SWNMI_Val        _UINT32_(0x1)                                        /* (RCON_RNMICON) Writing a 1 to this bit will cause an NMI to be generated  */
#define   RCON_RNMICON_SWNMI_NO_SWNMI_Val     _UINT32_(0x0)                                        /* (RCON_RNMICON) Writing a 0 to this bit will have no effect.  */
#define RCON_RNMICON_SWNMI_SWNMI              (RCON_RNMICON_SWNMI_SWNMI_Val << RCON_RNMICON_SWNMI_Pos) /* (RCON_RNMICON) Writing a 1 to this bit will cause an NMI to be generated Position  */
#define RCON_RNMICON_SWNMI_NO_SWNMI           (RCON_RNMICON_SWNMI_NO_SWNMI_Val << RCON_RNMICON_SWNMI_Pos) /* (RCON_RNMICON) Writing a 0 to this bit will have no effect. Position  */
#define RCON_RNMICON_WDTR_Pos                 _UINT32_(24)                                         /* (RCON_RNMICON) Watchdog Timer Time-Out in Run Flag bit Position */
#define RCON_RNMICON_WDTR_Msk                 (_UINT32_(0x1) << RCON_RNMICON_WDTR_Pos)             /* (RCON_RNMICON) Watchdog Timer Time-Out in Run Flag bit Mask */
#define RCON_RNMICON_WDTR(value)              (RCON_RNMICON_WDTR_Msk & (_UINT32_(value) << RCON_RNMICON_WDTR_Pos)) /* Assigment of value for WDTR in the RCON_RNMICON register */
#define   RCON_RNMICON_WDTR_WDTR_Val          _UINT32_(0x1)                                        /* (RCON_RNMICON) WDT Time-out has occurred and caused a NMI.  */
#define   RCON_RNMICON_WDTR_NO_WDTR_Val       _UINT32_(0x0)                                        /* (RCON_RNMICON) WDT Time-out has not occurred.  */
#define RCON_RNMICON_WDTR_WDTR                (RCON_RNMICON_WDTR_WDTR_Val << RCON_RNMICON_WDTR_Pos) /* (RCON_RNMICON) WDT Time-out has occurred and caused a NMI. Position  */
#define RCON_RNMICON_WDTR_NO_WDTR             (RCON_RNMICON_WDTR_NO_WDTR_Val << RCON_RNMICON_WDTR_Pos) /* (RCON_RNMICON) WDT Time-out has not occurred. Position  */
#define RCON_RNMICON_DMTO_Pos                 _UINT32_(25)                                         /* (RCON_RNMICON) Deadman Timer Time-Out Flag bit Position */
#define RCON_RNMICON_DMTO_Msk                 (_UINT32_(0x1) << RCON_RNMICON_DMTO_Pos)             /* (RCON_RNMICON) Deadman Timer Time-Out Flag bit Mask */
#define RCON_RNMICON_DMTO(value)              (RCON_RNMICON_DMTO_Msk & (_UINT32_(value) << RCON_RNMICON_DMTO_Pos)) /* Assigment of value for DMTO in the RCON_RNMICON register */
#define   RCON_RNMICON_DMTO_DMTO_Val          _UINT32_(0x1)                                        /* (RCON_RNMICON) DMT Time-out has occurred and caused a NMI.  */
#define   RCON_RNMICON_DMTO_NO_DMTO_Val       _UINT32_(0x0)                                        /* (RCON_RNMICON) DMT Time-out has not occurred.  */
#define RCON_RNMICON_DMTO_DMTO                (RCON_RNMICON_DMTO_DMTO_Val << RCON_RNMICON_DMTO_Pos) /* (RCON_RNMICON) DMT Time-out has occurred and caused a NMI. Position  */
#define RCON_RNMICON_DMTO_NO_DMTO             (RCON_RNMICON_DMTO_NO_DMTO_Val << RCON_RNMICON_DMTO_Pos) /* (RCON_RNMICON) DMT Time-out has not occurred. Position  */
#define RCON_RNMICON_Msk                      _UINT32_(0x038FFFFF)                                 /* (RCON_RNMICON) Register Mask  */


/* -------- RCON_RNMICONCLR : (RCON Offset: 0x54) (R/W 32)  -------- */
#define RCON_RNMICONCLR_RESETVALUE            _UINT32_(0x00)                                       /*  (RCON_RNMICONCLR)   Reset Value */

#define RCON_RNMICONCLR_Msk                   _UINT32_(0x00000000)                                 /* (RCON_RNMICONCLR) Register Mask  */


/* -------- RCON_RNMICONSET : (RCON Offset: 0x58) (R/W 32)  -------- */
#define RCON_RNMICONSET_RESETVALUE            _UINT32_(0x00)                                       /*  (RCON_RNMICONSET)   Reset Value */

#define RCON_RNMICONSET_Msk                   _UINT32_(0x00000000)                                 /* (RCON_RNMICONSET) Register Mask  */


/* -------- RCON_RNMICONINV : (RCON Offset: 0x5C) (R/W 32)  -------- */
#define RCON_RNMICONINV_RESETVALUE            _UINT32_(0x00)                                       /*  (RCON_RNMICONINV)   Reset Value */

#define RCON_RNMICONINV_Msk                   _UINT32_(0x00000000)                                 /* (RCON_RNMICONINV) Register Mask  */


/** \brief RCON register offsets definitions */
#define RCON_RCON_REG_OFST             _UINT32_(0x30)      /* (RCON_RCON) RESET CONTROL REGISTER Offset */
#define RCON_RCONCLR_REG_OFST          _UINT32_(0x34)      /* (RCON_RCONCLR)  Offset */
#define RCON_RCONSET_REG_OFST          _UINT32_(0x38)      /* (RCON_RCONSET)  Offset */
#define RCON_RCONINV_REG_OFST          _UINT32_(0x3C)      /* (RCON_RCONINV)  Offset */
#define RCON_RSWRST_REG_OFST           _UINT32_(0x40)      /* (RCON_RSWRST) SOFTWARE RESET REGISTER Offset */
#define RCON_RSWRSTCLR_REG_OFST        _UINT32_(0x44)      /* (RCON_RSWRSTCLR)  Offset */
#define RCON_RSWRSTSET_REG_OFST        _UINT32_(0x48)      /* (RCON_RSWRSTSET)  Offset */
#define RCON_RSWRSTINV_REG_OFST        _UINT32_(0x4C)      /* (RCON_RSWRSTINV)  Offset */
#define RCON_RNMICON_REG_OFST          _UINT32_(0x50)      /* (RCON_RNMICON) NMI CONTROL REGISTER Offset */
#define RCON_RNMICONCLR_REG_OFST       _UINT32_(0x54)      /* (RCON_RNMICONCLR)  Offset */
#define RCON_RNMICONSET_REG_OFST       _UINT32_(0x58)      /* (RCON_RNMICONSET)  Offset */
#define RCON_RNMICONINV_REG_OFST       _UINT32_(0x5C)      /* (RCON_RNMICONINV)  Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief RCON register API structure */
typedef struct
{  /*  */
  __I   uint8_t                        Reserved1[0x30];
  __IO  uint32_t                       RCON_RCON;          /**< Offset: 0x30 (R/W  32) RESET CONTROL REGISTER */
  __IO  uint32_t                       RCON_RCONCLR;       /**< Offset: 0x34 (R/W  32)  */
  __IO  uint32_t                       RCON_RCONSET;       /**< Offset: 0x38 (R/W  32)  */
  __IO  uint32_t                       RCON_RCONINV;       /**< Offset: 0x3C (R/W  32)  */
  __O   uint32_t                       RCON_RSWRST;        /**< Offset: 0x40 ( /W  32) SOFTWARE RESET REGISTER */
  __IO  uint32_t                       RCON_RSWRSTCLR;     /**< Offset: 0x44 (R/W  32)  */
  __IO  uint32_t                       RCON_RSWRSTSET;     /**< Offset: 0x48 (R/W  32)  */
  __IO  uint32_t                       RCON_RSWRSTINV;     /**< Offset: 0x4C (R/W  32)  */
  __IO  uint32_t                       RCON_RNMICON;       /**< Offset: 0x50 (R/W  32) NMI CONTROL REGISTER */
  __IO  uint32_t                       RCON_RNMICONCLR;    /**< Offset: 0x54 (R/W  32)  */
  __IO  uint32_t                       RCON_RNMICONSET;    /**< Offset: 0x58 (R/W  32)  */
  __IO  uint32_t                       RCON_RNMICONINV;    /**< Offset: 0x5C (R/W  32)  */
} rcon_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _BZ45_RCON_COMPONENT_H_ */
