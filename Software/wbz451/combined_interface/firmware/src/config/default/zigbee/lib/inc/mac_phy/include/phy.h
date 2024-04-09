/*******************************************************************************
  PHY Header File

  Company:
    Microchip Technology Inc.

  File Name:
    phy.h

  Summary:
    This file comprises the interface to PHY layer primitives.

  Description:
    This file contains the Types and constants declaration for IEEE std 802.15.4-2006
    PHY implementation.
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

#ifndef _PHY_H
#define _PHY_H

/******************************************************************************
                    Includes section
******************************************************************************/
#include <inttypes.h>
#include <mac_phy/include/macAddr.h>
/******************************************************************************
                    Define(s) section
******************************************************************************/
#define DBM_12 12
#define DBM_11 11
#define DBM_10 10
#define DBM_9 9
#define DBM_8 8
#define DBM_7 7
#define DBM_6 6
#define DBM_5 5
#define DBM_4 4
#define DBM_3 3
#define DBM_2 2
#define DBM_1 1
#define DBM_0 0
#define DBM_MIN_1 (-1)
#define DBM_MIN_2 (-2)
#define DBM_MIN_3 (-3)
#define DBM_MIN_4 (-4)
#define DBM_MIN_5 (-5)
#define DBM_MIN_6 (-6)
#define DBM_MIN_7 (-7)
#define DBM_MIN_8 (-8)
#define DBM_MIN_9 (-9)
#define DBM_MIN_10 (-10)
#define DBM_MIN_11 (-11)
#define DBM_MIN_12 (-12)
#define DBM_MIN_13 (-13)
#define DBM_MIN_14 (-14)
#define DBM_MIN_15 (-15)
#define DBM_MIN_16 (-16)
#define DBM_MIN_17 (-17)
#define DBM_MIN_18 (-18)
#define DBM_MIN_19 (-19)
#define DBM_MIN_20 (-20)
#define DBM_MIN_21 (-21)
#define DBM_MIN_22 (-22)
#define DBM_MIN_23 (-23)
#define DBM_MIN_24 (-24)
#define DBM_MIN_25 (-25)
#define DBM_MIN_26 (-26)
#define DBM_MIN_27 (-27)

#define PHY_CHANNEL_0   0
#define PHY_CHANNEL_1   1
#define PHY_CHANNEL_2   2
#define PHY_CHANNEL_3   3
#define PHY_CHANNEL_4   4
#define PHY_CHANNEL_5   5
#define PHY_CHANNEL_6   6
#define PHY_CHANNEL_7   7
#define PHY_CHANNEL_8   8
#define PHY_CHANNEL_9   9
#define PHY_CHANNEL_10  10
#define PHY_CHANNEL_11  11
#define PHY_CHANNEL_12  12
#define PHY_CHANNEL_13  13
#define PHY_CHANNEL_14  14
#define PHY_CHANNEL_15  15
#define PHY_CHANNEL_16  16
#define PHY_CHANNEL_17  17
#define PHY_CHANNEL_18  18
#define PHY_CHANNEL_19  19
#define PHY_CHANNEL_20  20
#define PHY_CHANNEL_21  21
#define PHY_CHANNEL_22  22
#define PHY_CHANNEL_23  23
#define PHY_CHANNEL_24  24
#define PHY_CHANNEL_25  25
#define PHY_CHANNEL_26  26

#define PHY_SYMBOL_DURATION_PAGE_0_CHANNELS_0     50 ///< Symbol duration for channel 0 and BPSK modulation.
#define PHY_SYMBOL_DURATION_PAGE_0_CHANNELS_1_10  25 ///< Symbol duration for channels [1 - 10] and BPSK modulation.
#define PHY_SYMBOL_DURATION_PAGE_0_CHANNELS_11_26 16 ///< Symbol duration for channels [11 - 26] and OQPSK modulation.
#define PHY_SYMBOL_DURATION_PAGE_1_CHANNELS_0     80 ///< Symbol duration for channel 0 and ASK modulation.
#define PHY_SYMBOL_DURATION_PAGE_1_CHANNELS_1_10  20 ///< Symbol duration for channels [1 - 10] and ASK modulation.
#define PHY_SYMBOL_DURATION_PAGE_2_CHANNELS_0     40 ///< Symbol duration for channel 0 and OQPSK modulation.
#define PHY_SYMBOL_DURATION_PAGE_2_CHANNELS_1_10  16 ///< Symbol duration for channels [1 - 10] and OQPSK modulation.
//Chinese frequencies.
#define PHY_SYMBOL_DURATION_PAGE_5_CHANNELS_0_3   16 ///< Symbol duration for channels [0 - 3] OQPSK modulation.
//#define PHY_SYMBOL_DURATION_PAGE_5_CHANNELS_4_7   16 ///< Symbol duration for channels [4 - 7] MPSK modulation. Not supported.

#define PHY_SYMBOL_DURATION_PAGE_20_CHANNELS_0_25 50 ///< Symbol duration for channels [0 - 25] and BPSK modulation.
#define PHY_SYMBOL_DURATION_PAGE_22_CHANNELS_0_25 40 ///< Symbol duration for channels [0 - 25] and OQPSK modulation.

// PHY PIB attribute read only parameters.
#define PHY_SYMBOLS_PER_OCTET_PAGE_0_CHANNELS_0     8
#define PHY_SYMBOLS_PER_OCTET_PAGE_0_CHANNELS_0_10  8
#define PHY_SYMBOLS_PER_OCTET_PAGE_0_CHANNELS_11_26 2
//#define PHY_SYMBOLS_PER_OCTET_PAGE_1_CHANNELS_0    (2/5)
//#define PHY_SYMBOLS_PER_OCTET_PAGE_1_CHANNELS_1_10 (6/3.75)
#define PHY_SYMBOLS_PER_OCTET_PAGE_2_CHANNELS_0     2
#define PHY_SYMBOLS_PER_OCTET_PAGE_2_CHANNELS_0_10  2
//Chinese frequencies.
#define PHY_SYMBOLS_PER_OCTET_PAGE_5_CHANNELS_0_3   2
//#define PHY_SYMBOLS_PER_OCTET_PAGE_5_CHANNELS_4_7  2 // Not supported.

#define PHY_SYMBOLS_PER_OCTET_PAGE_20_CHANNELS_0_25 8
#define PHY_SYMBOLS_PER_OCTET_PAGE_22_CHANNELS_0_25 2

// Size of frame fields
#define PHY_FRAME_LENGTH_FIELD_SIZE 1
#define PHY_FCS_FIELD_SIZE          2
#define PHY_SFD_FIELD_SIZE          1
#define PHY_PREAMBLE_FIELD_SIZE     4
#define PHY_LQI_FIELD_SIZE          1
#define PHY_RSSI_FIELD_SIZE         1

/******************************************************************************
                    Types section
******************************************************************************/
//! CCA mode types. IEEE 802.15.4-2006 6.9.9 Clear channel assessment (CCA).
typedef enum
{
  PHY_CCA_MODE_0 = 0,
  PHY_CCA_MODE_1 = 1,
  PHY_CCA_MODE_2 = 2,
  PHY_CCA_MODE_3 = 3
} PHY_CcaMode_t;

//! Energy level type.
typedef uint8_t PHY_EnergyLevel_t;

//! Evailible channel pages.
enum
{
  CHANNEL_PAGE_0 = 0,
  CHANNEL_PAGE_1 = 1,
  CHANNEL_PAGE_2 = 2,
  CHANNEL_PAGE_5 = 5,
  CHANNEL_PAGE_20 = 20,
  CHANNEL_PAGE_22 = 22,
};
#ifdef  _CHILD_MANAGEMENT_
//! Phy Neighbor Search Callback type 
typedef bool (* PhyNeighborSearchCallback_t)(const ShortAddr_t shortAddr);

/******************************************************************************
                    Prototypes section
******************************************************************************/
void PHY_RegisterNeighborSearchCallback(PhyNeighborSearchCallback_t fp);
#endif
#endif /* _PHY_H */

// eof phy.h
