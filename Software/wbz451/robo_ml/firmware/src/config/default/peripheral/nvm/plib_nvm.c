/*******************************************************************************
  Non-Volatile Memory Controller(NVM) PLIB.

  Company:
    Microchip Technology Inc.

  File Name:
    plib_nvm.c

  Summary:
    Interface definition of NVM Plib.

  Description:
    This file defines the interface for the NVM Plib.
    It allows user to Program, Erase and lock the on-chip Non Volatile Flash
    Memory.
*******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "interrupts.h"
#include "plib_nvm.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
// *****************************************************************************

/*******************************************
 * Internal operation type
 ******************************************/
typedef enum
{
    PROGRAM_ERASE_OPERATION                 = 0x7,
    PAGE_ERASE_OPERATION                    = 0x4,
    ROW_PROGRAM_OPERATION                   = 0x3,
    QUAD_WORD_PROGRAM_OPERATION             = 0x2,
    WORD_PROGRAM_OPERATION                  = 0x1,
    NO_OPERATION                            = 0x0,
} NVM_OPERATION_MODE;

/*******************************************
 * Internal Flash Programming Unlock Keys
 ******************************************/
typedef enum
{
    NVM_UNLOCK_KEY1 = 0xAA996655,
    NVM_UNLOCK_KEY2 = 0x556699AA
} NVM_UNLOCK_KEYS;

typedef struct
{
    NVM_CALLBACK CallbackFunc;
    uintptr_t Context;
}nvmCallbackObjType;

volatile static nvmCallbackObjType nvmCallbackObj;
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

// *****************************************************************************
// *****************************************************************************
// Section: NVM Implementation
// *****************************************************************************
// *****************************************************************************

void NVM_CallbackRegister( NVM_CALLBACK callback, uintptr_t context )
{
    /* Register callback function */
    nvmCallbackObj.CallbackFunc    = callback;
    nvmCallbackObj.Context         = context;
}

void __attribute__((used)) NVM_InterruptHandler( void )
{
    if(nvmCallbackObj.CallbackFunc != NULL)
    {
        uintptr_t context = nvmCallbackObj.Context;
        nvmCallbackObj.CallbackFunc(context);
    }
}

static void NVM_WriteUnlockSequence( void )
{
    // Write the unlock key sequence
    NVM_REGS->NVM_NVMKEY = 0x0U;
    NVM_REGS->NVM_NVMKEY = (uint32_t)NVM_UNLOCK_KEY1;
    NVM_REGS->NVM_NVMKEY = (uint32_t)NVM_UNLOCK_KEY2;
}

static void NVM_StartOperationAtAddress( uint32_t address,  NVM_OPERATION_MODE operation )
{
    uint32_t old_primask = __get_PRIMASK();
    __disable_irq();

    // Set the target Flash address to be operated on (destination).
    NVM_REGS->NVM_NVMADDR = address;

    // Set the flash operation:
    /***************************************************************************
     * Page erase: Erases the entire page which includes the target address
     *    (NVMADDR) if it is not write-protected.
     * Word (32-bit) program: Programs the 32 bit word in NVMDATA0 to the flash
     *    address selected by NVMADDR, if it is not write-protected.
     * Quad Word (128-bit) program: Programs the 128 bit quad words in NVMDATA0
     *    through NVMDATA3 to flash address selected by NVMADDR, if it they are
     *    not write-protected.
     * Row program: Programs the entire row from the physical address in
     *    NVMSRCADDR to the flash address selected by NVMADDR if it is not
     *    write-protected
     **************************************************************************/

    // NVMOP can be written only when WREN is zero. So, clear WREN.
    NVM_REGS->NVM_NVMCONCLR = NVM_NVMCON_WREN_Msk;

    /* Clear and Set, as NVMCON contains status bits and hence need to be accessed atomically.
     * Using bit field access may erroneously cause status bits to get cleared */
    NVM_REGS->NVM_NVMCONCLR = NVM_NVMCON_NVMOP_Msk;
    NVM_REGS->NVM_NVMCONSET = ( NVM_NVMCON_NVMOP_Msk & (((uint32_t)operation) << NVM_NVMCON_NVMOP_Pos) );

    // Set WREN to enable writes to the WR bit and to prevent NVMOP modification
    NVM_REGS->NVM_NVMCONSET = NVM_NVMCON_WREN_Msk;

    NVM_WriteUnlockSequence();

    // Start the operation
    NVM_REGS->NVM_NVMCONSET = NVM_NVMCON_WR_Msk;

    __set_PRIMASK( old_primask );
}

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void NVM_Initialize( void )
{
    NVM_StartOperationAtAddress( NVM_REGS->NVM_NVMADDR,  NO_OPERATION );
}

bool NVM_Read( uint32_t *data, uint32_t length, const uint32_t address )
{
    const uint32_t *paddress = (uint32_t *)address;
    (void) memcpy(data, paddress, length);

    return true;
}

bool NVM_WordWrite( uint32_t data, uint32_t address )
{
   NVM_REGS->NVM_NVMDATA0 = data;

   NVM_StartOperationAtAddress( address,  WORD_PROGRAM_OPERATION);

   return true;
}

bool NVM_QuadWordWrite( uint32_t *data, uint32_t address )
{
   NVM_REGS->NVM_NVMDATA0 = *data;
   data++;
   NVM_REGS->NVM_NVMDATA1 = *data;
   data++;
   NVM_REGS->NVM_NVMDATA2 = *data;
   data++;
   NVM_REGS->NVM_NVMDATA3 = *data;
   data++;

   NVM_StartOperationAtAddress( address,  QUAD_WORD_PROGRAM_OPERATION);

   return true;
}

bool NVM_RowWrite( uint32_t *data, uint32_t address )
{
   NVM_REGS->NVM_NVMSRCADDR = (uint32_t )data;

   NVM_StartOperationAtAddress( address,  ROW_PROGRAM_OPERATION);

   return true;
}

bool NVM_PageErase( uint32_t address )
{
   NVM_StartOperationAtAddress(address,  PAGE_ERASE_OPERATION);

   return true;
}

NVM_ERROR NVM_ErrorGet( void )
{
    // mask for WRERR and LVDERR bits
    return (NVM_REGS->NVM_NVMCON & (NVM_NVMCON_LVDERR_Msk | NVM_NVMCON_WRERR_Msk));
}

bool NVM_IsBusy( void )
{
    return (((NVM_REGS->NVM_NVMCON & NVM_NVMCON_WR_Msk) >> NVM_NVMCON_WR_Pos) != 0U);
}

void NVM_ProgramFlashWriteProtect( uint32_t laddress, uint32_t haddress )
{
    uint32_t old_primask = __get_PRIMASK();
    __disable_irq();

    NVM_WriteUnlockSequence();

    // Unlock the Program flash Write protect register
    NVM_REGS->NVM_NVMPWPLT = NVM_NVMPWPLT_ULOCK_Msk;
    NVM_REGS->NVM_NVMPWPGTESET = NVM_NVMPWPGTE_ULOCK_Msk;

    /* Program the address range */
    NVM_REGS->NVM_NVMPWPLT = (laddress & NVM_NVMPWPLT_PWPLT_Msk) | NVM_NVMPWPLT_ULOCK_Msk;
    NVM_REGS->NVM_NVMPWPGTE = (haddress & NVM_NVMPWPGTE_PWPGTE_Msk) | NVM_NVMPWPGTE_ULOCK_Msk;

    __set_PRIMASK( old_primask );
}

void NVM_ProgramFlashWriteProtectLock( void )
{
    uint32_t old_primask = __get_PRIMASK();
    __disable_irq();

    NVM_WriteUnlockSequence();

    // Lock the Program flash Write protect register
    NVM_REGS->NVM_NVMPWPLTCLR = NVM_NVMPWPLT_ULOCK_Msk;
    NVM_REGS->NVM_NVMPWPGTECLR = NVM_NVMPWPGTE_ULOCK_Msk;

    __set_PRIMASK( old_primask );
}

void NVM_BootFlashWriteProtectUnlock( uint32_t bootFlashPagesMsk )
{
    uint32_t old_primask = __get_PRIMASK();
    __disable_irq();

    NVM_WriteUnlockSequence();

    // Disable erase and write protection on the specified pages in bootFlashPagesMsk
    NVM_REGS->NVM_NVMLBWPCLR = (bootFlashPagesMsk & (NVM_NVMLBWP_Msk & ~(0x80000000U)));

    __set_PRIMASK( old_primask );
}

void NVM_BootFlashWriteProtectLock( uint32_t bootFlashPagesMsk )
{
    uint32_t old_primask = __get_PRIMASK();
    __disable_irq();

    NVM_WriteUnlockSequence();

    // Enable erase and write protection on the specified pages in bootFlashPagesMsk
    NVM_REGS->NVM_NVMLBWPSET = (bootFlashPagesMsk & (NVM_NVMLBWP_Msk & ~(0x80000000U)));

    __set_PRIMASK( old_primask );
}