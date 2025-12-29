MEMORY {
    ewram (rwx): ORIGIN = 0x02000000 LENGTH = 256K
    iwram (rwx): ORIGIN = 0x03000000 LENGTH = 32K
    vram  (rwx): ORIGIN = 0x06000000 LENGTH = 96K
    rom    (rx): ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    . = ORIGIN(rom);
    __rom_cursor = .;

    .rom_text 0x08000000 : AT(__rom_cursor) {
        asm/asm.o(.text);
    } > rom
    __rom_cursor += SIZEOF(.rom_text);

    .vram_text_1 0x06006000 : AT(__rom_cursor) {
        asm/part1.o(.text);
    } > vram
    __rom_cursor += SIZEOF(.vram_text_1);

    .iwram_text 0x03000000 : AT(__rom_cursor) {
        src/part2.o(.text);
        asm/part2.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        src/part2.o(.data);
        asm/part2_2.o(.text);
    } > iwram
    __rom_cursor += SIZEOF(.iwram_text);

    .iwram_data 0x03000000 (NOLOAD) : {
        . = 0x00005A50; gUnk_03005A50 = .;
        . = 0x00005A54; gUnk_03005A54 = .;
        . = 0x00005A58; gUnk_03005A58 = .;
        . = 0x00005A5C; gUnk_03005A5C = .;
        . = 0x00005A5D; gUnk_03005A5D = .;
        . = 0x00005A5E; gUnk_03005A5E = .;
        . = 0x00005A60; gUnk_03005A60 = .;
        . = 0x00005A64; gUnk_03005A64 = .;
        . = 0x00005A68; gUnk_03005A68 = .;
        . = 0x00005FB0; gUnk_03005FB0 = .;
        . = 0x00005FB4; gUnk_03005FB4 = .;
        . = 0x00005FBC; gUnk_03005FBC = .;
        . = 0x00005FC0; gUnk_03005FC0 = .;
        . = 0x00005FC8; gUnk_03005FC8 = .;
        . = 0x00005FCC; gUnk_03005FCC = .;
        . = 0x00005FD8; gUnk_03005FD8 = .;
    } > iwram

    .vram_text_2 0x0600B000 : AT(__rom_cursor) {
        asm/part3.o(.text);
    } > vram
    __rom_cursor += SIZEOF(.vram_text_2);

    .vram_text_3 0x0600C000 : AT(__rom_cursor) {
        asm/part4.o(.text);
    } > vram
    __rom_cursor += SIZEOF(.vram_text_3);

    .vram_text_4 0x0600E000 : AT(__rom_cursor) {
        asm/part5.o(.text);
    } > vram
    __rom_cursor += SIZEOF(.vram_text_4);

    .ewram_text 0x0203E000 : AT(__rom_cursor) {
        src/part6.o(.text);
        src/part6.o(.rodata);
        src/sram/sram.o(.text);
        src/sram/sram.o(.rodata);
        *libgcc.a:_call_via_rX.o(.text);
    } > ewram
    __rom_cursor += SIZEOF(.ewram_text);

    /* DWARF debug sections.
       Symbols in the DWARF debugging sections are relative to the beginning
       of the section so we begin them at 0.  */

    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }

    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }

    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }

    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
