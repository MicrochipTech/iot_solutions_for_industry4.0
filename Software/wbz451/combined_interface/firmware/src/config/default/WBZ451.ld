/*--------------------------------------------------------------------------
 * MPLAB XC32 Compiler -  PIC32CX1012BZ25048 linker script
 * 
 * Copyright (c) 2021, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 * 
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/*
 *  Define the __XC32_RESET_HANDLER_NAME macro on the command line when you
 *  want to use a different name for the Reset Handler function.
 */
#ifndef __XC32_RESET_HANDLER_NAME
#define __XC32_RESET_HANDLER_NAME Reset_Handler
#endif /* __XC32_RESET_HANDLER_NAME */

/*  Set the entry point in the ELF file. Once the entry point is in the ELF
 *  file, you can then use the --write-sla option to xc32-bin2hex to place
 *  the address into the hex file using the SLA field (RECTYPE 5). This hex
 *  record may be useful for a bootloader that needs to determine the entry
 *  point to the application.
 */
ENTRY(__XC32_RESET_HANDLER_NAME)

/*************************************************************************
 * Memory-Region Macro Definitions
 * The XC32 linker preprocesses linker scripts. You may define these
 * macros in the MPLAB X project properties or on the command line when
 * calling the linker via the xc32-gcc shell.
 *************************************************************************/
#ifndef PDS_LENGTH
#define PDS_LENGTH           0x4000
#endif

#define ROM_BASE_ADDR        0x01000000
#ifndef PDS_ORIGIN
#define PDS_ORIGIN           ROM_BASE_ADDR
#endif

#ifndef ROM_ORIGIN
#define ROM_ORIGIN           (PDS_ORIGIN + PDS_LENGTH)
#endif

#ifndef ROM_LENGTH
	#define ROM_LENGTH        0x100000 - PDS_LENGTH
#elif (ROM_LENGTH > 0x100000)
	#error ROM_LENGTH is greater than the max size of 0x100000
#endif

#ifndef BOOT_ROM_ORIGIN
#  define BOOT_ROM_ORIGIN     0x0
#endif
#ifndef BOOT_ROM_LENGTH
#  define BOOT_ROM_LENGTH     0x5e00
#elif (BOOT_ROM_LENGTH > 0x5e00)
#  error BOOT_ROM_LENGTH is greater than the max size of 0x5e00
#endif
#ifndef RAM_ORIGIN
#  define RAM_ORIGIN          0x20000000
#endif
#ifndef RAM_LENGTH
#  define RAM_LENGTH 0x20000
#elif (RAM_LENGTH > 0x20000)
#  error RAM_LENGTH is greater than the max size of 0x20000
#endif

#ifndef BACKUPRAM_ORIGIN
#  define BACKUPRAM_ORIGIN 0x44014000
#endif

#ifndef BACKUPRAM_LENGTH
#  define BACKUPRAM_LENGTH 0x2000
#endif
/*************************************************************************
 * Memory-Region Definitions
 * The MEMORY command describes the location and size of blocks of memory
 * on the target device. The command below uses the macros defined above.
 *************************************************************************/
MEMORY
{
  boot_rom (LRX) : ORIGIN = BOOT_ROM_ORIGIN, LENGTH = BOOT_ROM_LENGTH
  pds (RX) : ORIGIN = PDS_ORIGIN, LENGTH = PDS_LENGTH
  rom (LRX) : ORIGIN = ROM_ORIGIN, LENGTH = ROM_LENGTH
  ram (WX!R) : ORIGIN = RAM_ORIGIN, LENGTH = RAM_LENGTH
  bkupram         : ORIGIN = BACKUPRAM_ORIGIN, LENGTH = BACKUPRAM_LENGTH
  config_00045F80 : ORIGIN = 0x00045F80, LENGTH = 0x4
  config_00045E80 : ORIGIN = 0x00045E80, LENGTH = 0x4
  config_00045F84 : ORIGIN = 0x00045F84, LENGTH = 0x4
  config_00045F88 : ORIGIN = 0x00045F88, LENGTH = 0x4
  config_00045E8C : ORIGIN = 0x00045E8C, LENGTH = 0x4
  config_00045E90 : ORIGIN = 0x00045E90, LENGTH = 0x4
  config_00045E98 : ORIGIN = 0x00045E98, LENGTH = 0x4
  config_00045E94 : ORIGIN = 0x00045E94, LENGTH = 0x4
  config_00045F98 : ORIGIN = 0x00045F98, LENGTH = 0x4
  config_00045E84 : ORIGIN = 0x00045E84, LENGTH = 0x4
  config_00045E9C : ORIGIN = 0x00045E9C, LENGTH = 0x4
  config_00045EB0 : ORIGIN = 0x00045EB0, LENGTH = 0x4
  config_00045F9C : ORIGIN = 0x00045F9C, LENGTH = 0x4
  config_00045FB0 : ORIGIN = 0x00045FB0, LENGTH = 0x4
  config_00045E88 : ORIGIN = 0x00045E88, LENGTH = 0x4
  config_00045EB4 : ORIGIN = 0x00045EB4, LENGTH = 0x4
  config_00045FB8 : ORIGIN = 0x00045FB8, LENGTH = 0x4
  config_00045FB4 : ORIGIN = 0x00045FB4, LENGTH = 0x4
  config_00045FBC : ORIGIN = 0x00045FBC, LENGTH = 0x4
  config_00045F8C : ORIGIN = 0x00045F8C, LENGTH = 0x4
  config_00045EB8 : ORIGIN = 0x00045EB8, LENGTH = 0x4
  config_00045F90 : ORIGIN = 0x00045F90, LENGTH = 0x4
  config_00045EBC : ORIGIN = 0x00045EBC, LENGTH = 0x4
  config_00045F94 : ORIGIN = 0x00045F94, LENGTH = 0x4

}


SECTIONS {
    .bkupram_data : {
      *(.bkupram_data .bkupram_data.*)
    } > bkupram
    .bkupram_bss : {
      *(.bkupram_bss .bkupram_bss.*)
      *(.pbss .pbss.*)
    } > bkupram
}

/*************************************************************************
 * Output region definitions.
 * CODE_REGION defines the output region for .text/.rodata.
 * DATA_REGION defines the output region for .data/.bss
 * VECTOR_REGION defines the output region for .vectors.
 * 
 * CODE_REGION defaults to 'rom', if rom is present (non-zero length),
 * and 'ram' otherwise.
 * DATA_REGION defaults to 'ram', which must be present.
 * VECTOR_REGION defaults to CODE_REGION, unless 'boot_rom' is present.
 */
#ifndef CODE_REGION
# if ROM_LENGTH > 0
#   define CODE_REGION rom
# else
#   define CODE_REGION ram
# endif
#endif
#ifndef DATA_REGION
# define DATA_REGION ram
#endif 
#ifndef VECTOR_REGION
# define VECTOR_REGION boot_rom
#endif
#ifndef PDS_REGION
#define PDS_REGION pds
#endif

__rom_end = ORIGIN(rom) + LENGTH(rom);
__ram_end = ORIGIN(ram) + LENGTH(ram);

/*************************************************************************
 * Section Definitions - Map input sections to output sections
 *************************************************************************/
SECTIONS
{
    .config_00045F80 : {
      KEEP(*(.config_00045F80))
    } > config_00045F80
    .config_00045E80 : {
      KEEP(*(.config_00045E80))
    } > config_00045E80
    .config_00045F84 : {
      KEEP(*(.config_00045F84))
    } > config_00045F84
    .config_00045F88 : {
      KEEP(*(.config_00045F88))
    } > config_00045F88
    .config_00045E8C : {
      KEEP(*(.config_00045E8C))
    } > config_00045E8C
    .config_00045E90 : {
      KEEP(*(.config_00045E90))
    } > config_00045E90
    .config_00045E98 : {
      KEEP(*(.config_00045E98))
    } > config_00045E98
    .config_00045E94 : {
      KEEP(*(.config_00045E94))
    } > config_00045E94
    .config_00045F98 : {
      KEEP(*(.config_00045F98))
    } > config_00045F98
    .config_00045E84 : {
      KEEP(*(.config_00045E84))
    } > config_00045E84
    .config_00045E9C : {
      KEEP(*(.config_00045E9C))
    } > config_00045E9C
    .config_00045EB0 : {
      KEEP(*(.config_00045EB0))
    } > config_00045EB0
    .config_00045F9C : {
      KEEP(*(.config_00045F9C))
    } > config_00045F9C
    .config_00045FB0 : {
      KEEP(*(.config_00045FB0))
    } > config_00045FB0
    .config_00045E88 : {
      KEEP(*(.config_00045E88))
    } > config_00045E88
    .config_00045EB4 : {
      KEEP(*(.config_00045EB4))
    } > config_00045EB4
    .config_00045FB8 : {
      KEEP(*(.config_00045FB8))
    } > config_00045FB8
    .config_00045FB4 : {
      KEEP(*(.config_00045FB4))
    } > config_00045FB4
    .config_00045FBC : {
      KEEP(*(.config_00045FBC))
    } > config_00045FBC
    .config_00045F8C : {
      KEEP(*(.config_00045F8C))
    } > config_00045F8C
    .config_00045EB8 : {
      KEEP(*(.config_00045EB8))
    } > config_00045EB8
    .config_00045F90 : {
      KEEP(*(.config_00045F90))
    } > config_00045F90
    .config_00045EBC : {
      KEEP(*(.config_00045EBC))
    } > config_00045EBC
    .config_00045F94 : {
      KEEP(*(.config_00045F94))
    } > config_00045F94

    /*
     * The linker moves the .vectors section into itcm when itcm is
     * enabled via the -mitcm option, but only when this .vectors output
     * section exists in the linker script.
     */
    .vectors :
    {
        . = ALIGN(4);
        _sfixed = .;
        KEEP(*(.vectors .vectors.* .vectors_default .vectors_default.*))
        KEEP(*(.isr_vector))
        KEEP(*(.reset*))
        KEEP(*(.after_vectors))
    } > VECTOR_REGION
    /*
     * Code Sections - Note that standard input sections such as
     * *(.text), *(.text.*), *(.rodata), & *(.rodata.*)
     * are not mapped here. The best-fit allocator locates them,
     * so that input sections may flow around absolute sections
     * as needed.
     */
    .dnvMem :
    {
       __d_nv_mem_start = .;
       __d_nv_mem_end = ORIGIN(pds) + LENGTH(pds);
    } > PDS_REGION
    .text :
    {
        /* Non-volatile file system PDS_FF section */
        PROVIDE(__pds_ff_start = .);
        KEEP(*(.pds_ff .pds_ff.*))
        PROVIDE(__pds_ff_end = .);
        /* Non-volatile file system PDS_FF section */
        PROVIDE(__pds_fd_start = .);
        KEEP(*(.pds_fd .pds_fd.*))
        PROVIDE(__pds_fd_end = .);

        . = ALIGN(4);
        *(.glue_7t) *(.glue_7)
        *(.gnu.linkonce.r.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)

        /* Support C constructors, and C destructors in both user code
           and the C library. This also provides support for C++ code. */
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;

        . = ALIGN(0x4);
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))

        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;

        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))

        . = ALIGN(4);
        _efixed = .;            /* End of text section */
    } > CODE_REGION

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > CODE_REGION
    PROVIDE_HIDDEN (__exidx_end = .);

    . = ALIGN(4);
    _etext = .;

    /*
     *  Align here to ensure that the .bss section occupies space up to
     *  _end.  Align after .bss to ensure correct alignment even if the
     *  .bss section disappears because there are no input sections.
     *
     *  Note that input sections named .bss* are no longer mapped here.
     *  The best-fit allocator locates them, so that they may flow
     *  around absolute sections as needed.
     */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        _sbss = . ;
        _szero = .;
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
        _ebss = . ;
        _ezero = .;
    } > DATA_REGION

    . = ALIGN(4);
    _end = . ;
    _ram_end_ = ORIGIN(ram) + LENGTH(ram) -1 ;
    
}

