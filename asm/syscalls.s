    .include "asm/macros.inc"
    .include "asm/constants.inc"

    .syntax unified

    thumb_func_start CpuFastSet
CpuFastSet: @ 0x08005190
    swi SYSCALL_CpuSetFast
    bx lr

    thumb_func_start CpuSet
CpuSet: @ 0x08005194
    swi SYSCALL_CpuSet
    bx lr

    thumb_func_start DivarmDiv
DivarmDiv: @ 0x08005198
    swi SYSCALL_DivArm
    bx lr

    thumb_func_start DivarmMod
DivarmMod: @ 0x0800519c
    swi SYSCALL_DivArm
    adds r0, r1, 0
    bx lr

    thumb_func_start LZ77UncompVram
LZ77UncompVram: @ 0x080051a4
    swi SYSCALL_LZ77UnCompVram
    bx lr

    thumb_func_start LZ77UncompWram
LZ77UncompWram: @ 0x080051a8
    swi SYSCALL_LZ77UnCompWram
    bx lr

    thumb_func_start MidiKey2Freq
MidiKey2Freq: @ 0x080051ac
    swi SYSCALL_MidiKey2Freq
    bx lr

    thumb_func_start Multiboot
Multiboot: @ 0x080051b0
    movs r1, 1
    swi SYSCALL_MultiBoot
    bx lr

    thumb_func_start SoundBias0
SoundBias0: @ 0x080051b8
    movs r0, 0
    swi SYSCALL_SoundBiasChange
    bx lr

    thumb_func_start SoundBias200
SoundBias200: @ 0x080051c0
    movs r0, 1
    swi SYSCALL_SoundBiasChange
    bx lr

    thumb_func_start Sqrt
Sqrt: @ 0x080051c8
    swi SYSCALL_Sqrt
    bx lr

    thumb_func_start VBlankIntrWait
VBlankIntrWait: @ 0x080051cc
    movs r2, 0
    swi SYSCALL_VBlankIntrWait
    bx lr

    .align 2, 0 @ don't insert nops
