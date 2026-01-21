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
        src/part2/part2.o(.text);
        asm/part2/part2_2.o(.text);
        asm/part2/part2_3.o(.text);
        asm/part2/part2_4.o(.text);
        asm/part2/part2_5.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        src/part2/part2.o(.data);
        asm/part2/part2_handwritten.o(.data);
        asm/part2/part2_handwritten.o(.text);
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
        . = 0x00005A7A; gUnk_03005A7A = .;
        . = 0x00005A7C; gUnk_03005A7C = .;
        . = 0x00005A80; gUnk_03005A80 = .;
        . = 0x00005A84; gUnk_03005A84 = .;
        . = 0x00005A88; gUnk_03005A88 = .;
        . = 0x00005A8C; gUnk_03005A8C = .;
        . = 0x00005A90; gUnk_03005A90 = .;
        . = 0x00005A94; gUnk_03005A94 = .;
        . = 0x00005A96; gUnk_03005A96 = .;
        . = 0x00005A98; gUnk_03005A98 = .;
        . = 0x00005A9A; gUnk_03005A9A = .;
        . = 0x00005A9C; gUnk_03005A9C = .;
        . = 0x00005A9E; gUnk_03005A9E = .;
        . = 0x00005AA0; gUnk_03005AA0 = .;
        . = 0x00005AA2; gUnk_03005AA2 = .;
        . = 0x00005AA4; gUnk_03005AA4 = .;
        . = 0x00005AA6; gUnk_03005AA6 = .;
        . = 0x00005AA8; gUnk_03005AA8 = .;
        . = 0x00005AAA; gUnk_03005AAA = .;
        . = 0x00005AAC; gUnk_03005AAC = .;
        . = 0x00005AAD; gUnk_03005AAD = .;
        . = 0x00005AB0; gUnk_03005AB0 = .;
        . = 0x00005AB4; gUnk_03005AB4 = .;
        . = 0x00005AB6; gUnk_03005AB6 = .;
        . = 0x00005AB8; gUnk_03005AB8 = .;
        . = 0x00005ABA; gUnk_03005ABA = .;
        . = 0x00005ABC; gUnk_03005ABC = .;
        . = 0x00005ABE; gUnk_03005ABE = .;
        . = 0x00005AC0; gUnk_03005AC0 = .;
        . = 0x00005AC2; gUnk_03005AC2 = .;
        . = 0x00005AC4; gUnk_03005AC4 = .;
        . = 0x00005AC6; gUnk_03005AC6 = .;
        . = 0x00005AC8; gUnk_03005AC8 = .;
        . = 0x00005ACA; gUnk_03005ACA = .;
        . = 0x00005ACC; gUnk_03005ACC = .;
        . = 0x00005ACD; gUnk_03005ACD = .;
        . = 0x00005AD0; gUnk_03005AD0 = .;
        . = 0x00005AD4; gUnk_03005AD4 = .;
        . = 0x00005AD6; gUnk_03005AD6 = .;
        . = 0x00005AD8; gUnk_03005AD8 = .;
        . = 0x00005ADA; gUnk_03005ADA = .;
        . = 0x00005ADC; gUnk_03005ADC = .;
        . = 0x00005ADE; gUnk_03005ADE = .;
        . = 0x00005AE0; gUnk_03005AE0 = .;
        . = 0x00005AE2; gUnk_03005AE2 = .;
        . = 0x00005AE4; gUnk_03005AE4 = .;
        . = 0x00005AE8; gUnk_03005AE8 = .;
        . = 0x00005AEC; gUnk_03005AEC = .;
        . = 0x00005AF0; gUnk_03005AF0 = .;
        . = 0x00005AF4; gUnk_03005AF4 = .;
        . = 0x00005AF6; gUnk_03005AF6 = .;
        . = 0x00005AF8; gUnk_03005AF8 = .;
        . = 0x00005AFA; gUnk_03005AFA = .;
        . = 0x00005AFC; gUnk_03005AFC = .;
        . = 0x00005AFE; gUnk_03005AFE = .;
        . = 0x00005B00; gUnk_03005B00 = .;
        . = 0x00005B02; gUnk_03005B02 = .;
        . = 0x00005B04; gUnk_03005B04 = .;
        . = 0x00005B06; gUnk_03005B06 = .;
        . = 0x00005B08; gUnk_03005B08 = .;
        . = 0x00005B10; gUnk_03005B10 = .;
        . = 0x00005B50; gUnk_03005B50 = .;
        . = 0x00005BF0; gUnk_03005BF0 = .;
        . = 0x00005C90; gUnk_03005C90 = .;
        . = 0x00005D30; gUnk_03005D30 = .;
        . = 0x00005DD0; gUnk_03005DD0 = .;
        . = 0x00005E70; gUnk_03005E70 = .;
        . = 0x00005F10; gUnk_03005F10 = .;
        . = 0x00005FB0; gUnk_03005FB0 = .;
        . = 0x00005FB4; gUnk_03005FB4 = .;
        . = 0x00005FB8; gUnk_03005FB8 = .;
        . = 0x00005FBC; gUnk_03005FBC = .;
        . = 0x00005FC0; gUnk_03005FC0 = .;
        . = 0x00005FC4; gUnk_03005FC4 = .;
        . = 0x00005FC8; gUnk_03005FC8 = .;
        . = 0x00005FCC; gUnk_03005FCC = .;
        . = 0x00005FD0; gUnk_03005FD0 = .;
        . = 0x00005FD4; gUnk_03005FD4 = .;
        . = 0x00005FD8; gUnk_03005FD8 = .;
        . = 0x00005FDC; gUnk_03005FDC = .;
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
        asm/part5.o(.rodata);
        asm/part5.o(.text);
    } > vram
    __rom_cursor += SIZEOF(.vram_text_4);

    .ewram_text 0x0203E000 : AT(__rom_cursor) {
        src/part6.o(.text);
        src/part6.o(.data);
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
