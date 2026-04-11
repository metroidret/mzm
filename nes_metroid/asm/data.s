    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .incbin "payload/payload_us.gba.lz"
    .align 4, 0
    .incbin "emulator/emulator_us.gba.lz"
