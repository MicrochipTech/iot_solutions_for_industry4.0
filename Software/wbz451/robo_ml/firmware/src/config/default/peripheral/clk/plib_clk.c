/*******************************************************************************
  SYS CLK Static Functions for Clock System Service

  Company:
    Microchip Technology Inc.

  File Name:
    plib_clk.c

  Summary:
    SYS CLK static function implementations for the Clock System Service.

  Description:
    The Clock System Service provides a simple interface to manage the
    oscillators on Microchip microcontrollers. This file defines the static
    implementation for the Clock System Service.

  Remarks:
    Static functions incorporate all system clock configuration settings as
    determined by the user via the Microchip Harmony Configurator GUI.
    It provides static version of the routines, eliminating the need for an
    object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include "plib_clk.h"

#define CLK_READY_RETRIES  8000U
#define BTZB_XTAL_NOT_READY ((BTZBSYS_REGS->BTZBSYS_SUBSYS_STATUS_REG1 \
                            & BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Msk) \
                            != BTZBSYS_SUBSYS_STATUS_REG1_xtal_ready_out_Msk)
#define BTZB_PLL_NOT_LOCKED ((BTZBSYS_REGS->BTZBSYS_SUBSYS_STATUS_REG1 \
                            & BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Msk) \
                            != BTZBSYS_SUBSYS_CNTRL_REG1_subsys_dbg_bus_sel_top_Msk)

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void CLK_Initialize( void )

  Summary:
    Initializes hardware and internal data structure of the System Clock.

  Description:
    This function initializes the hardware and internal data structure of System
    Clock Service.

  Remarks:
    This is configuration values for the static version of the Clock System
    Service module is determined by the user via the MHC GUI.

    The objective is to eliminate the user's need to be knowledgeable in the
    function of the 'configuration bits' to configure the system oscillators.
*/

void CLK_Initialize( void )
{
    //check CLDO ready
    while ((CFG_REGS->CFG_MISCSTAT & CFG_MISCSTAT_CLDORDY_Msk) == 0U)
	{
        /* Do Nothing */
	}		
    
    // wait for xtal_ready      
    uint32_t clk_ready_tries = 0U;
    do
    {
        clk_ready_tries++;
    } while(BTZB_XTAL_NOT_READY && (clk_ready_tries < CLK_READY_RETRIES));
    
    if((clk_ready_tries >= CLK_READY_RETRIES) && BTZB_XTAL_NOT_READY)
    {
        BTZBSYS_REGS->BTZBSYS_SUBSYS_CNTRL_REG1 |=(BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_xtal_ready_Msk);
        while(BTZB_XTAL_NOT_READY)
		{
			/* Do Nothing */
		}
    }
       
    // set PLL_enable
    BLE_REGS->BLE_DPLL_RG2 &= ((uint8_t)~(0x02U));

    // wait for PLL Lock
    clk_ready_tries = 0U;
    do
    {
        clk_ready_tries++;
    } while(BTZB_PLL_NOT_LOCKED && (clk_ready_tries < CLK_READY_RETRIES));
    
    if((clk_ready_tries >= CLK_READY_RETRIES) && BTZB_PLL_NOT_LOCKED)
    {
        BTZBSYS_REGS->BTZBSYS_SUBSYS_CNTRL_REG1 |= BTZBSYS_SUBSYS_CNTRL_REG1_subsys_bypass_pll_lock_Msk;
        while(BTZB_PLL_NOT_LOCKED)
		{
			/* Do Nothing */
		}
    }

    /* Unlock system for clock configuration */
    CFG_REGS->CFG_SYSKEY = 0x00000000U;
    CFG_REGS->CFG_SYSKEY = 0xAA996655U;
    CFG_REGS->CFG_SYSKEY = 0x556699AAU;


    /* SPLLPWDN     = 0x1     */
    /* SPLLFLOCK    = 0x0    */
    /* SPLLRST      = 0x0      */    
    /* SPLLPOSTDIV1 = 1 */
    /* SPLLPOSTDIV2 = 0x0 */    
    /* SPLL_BYP     = 0x3     */
    CRU_REGS->CRU_SPLLCON = 0xc0000108U;


    /* OSWEN    = SWITCH_COMPLETE    */
    /* SOSCEN   = OFF   */
    /* CF       = NO_FAILDET       */
    /* SLPEN    = IDLE    */
    /* CLKLOCK  = UNLOCKED  */
    /* NOSC     = SPLL     */
    /* WAKE2SPD = SELECTED_CLK */
    /* DRMEN    = NO_EFFECT    */
    /* FRCDIV   = DIV_1   */
    CRU_REGS->CRU_OSCCON = 0x100U;

    CRU_REGS->CRU_OSCCONSET = CRU_OSCCON_OSWEN_Msk;  /* request oscillator switch to occur */

    while((CRU_REGS->CRU_OSCCON & CRU_OSCCON_OSWEN_Msk) != 0U)	/* wait for indication of successful clock change before proceeding */
    {
		/* Do Nothing */
	}
  
    /* Peripheral Bus 3 is by default enabled, set its divisor */
    /* PBDIV = 10 */
    CRU_REGS->CRU_PB3DIV = CRU_PB3DIV_PBDIVON_Msk | CRU_PB3DIV_PBDIV(9U);



    /* Set up Reference Clock 1 */
    /* REFO1CON register */
    /* ROSEL =  SPLL1 */
    /* DIVSWEN = 1 */
    /* RSLP = false */ 
    /* SIDL = false */ 
    /* RODIV = 0 */
    CRU_REGS->CRU_REFO1CON = 0x201U;

    /* Enable oscillator (ON bit) */
    CRU_REGS->CRU_REFO1CONSET = 0x00008000U;


    /* Peripheral Clock Generators */
    CFG_REGS->CFG_CFGPCLKGEN1 = 0x99009U;
    CFG_REGS->CFG_CFGPCLKGEN2 = 0x0U;
    CFG_REGS->CFG_CFGPCLKGEN3 = 0x9000000U;

    /* Peripheral Module Disable Configuration */


    CFG_REGS->CFG_PMD1 = 0x200101ceU;
    CFG_REGS->CFG_PMD3 = 0x7e3aU;


    /* Lock system since done with clock configuration */
    CFG_REGS->CFG_SYSKEY = 0x33333333U;

    // Change src_clk source to PLL CLK
    BTZBSYS_REGS->BTZBSYS_SUBSYS_CNTRL_REG1 |= 0x00000010U;

    // set aclb_reset_n[24], bt_en_main_clk[20] zb_en_main_clk[4]
    BTZBSYS_REGS->BTZBSYS_SUBSYS_CNTRL_REG0 = 0x01100010U;
}
