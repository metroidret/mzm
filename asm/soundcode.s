    .include "asm/macros.inc"
    .include "asm/constants.inc"
    .include "asm/audio_internal_constants.inc"

    .syntax unified

    .text

@ Signature: u8* CallSoundCodeB(u32*, u32*, u32*, u8)
    thumb_func_start CallSoundCodeB
CallSoundCodeB: @ 0x08004310
    push {r4-r7}
    mov r4, r8
    mov r5, r9
    mov r6, r10
    mov r7, r11
    push {r4-r7, lr}
    adr r4, SoundCodeB
    bx r4

    arm_func_start SoundCodeB
SoundCodeB: @ 0x08004320
    ldr r4, =gMusicInfo
    ldrb r12, [r4, o_MusicInfo_reverb]
    mov lr, #0x600
    b lbl_08004338
lbl_08004330:
    subs r3, r3, #0x1
    beq lbl_080043a0
lbl_08004338:
    ldsb r6, [r0, lr]
    ldsb r7, [r1, lr]
    ldsb r4, [r0], #0x1
    ldsb r5, [r1], #0x1
    ldsb r10, [r0, lr]
    ldsb r11, [r1, lr]
    ldsb r8, [r0], #0x1
    ldsb r9, [r1], #0x1
    add r6, r6, r4
    add r6, r6, r5
    add r6, r6, r7
    add r8, r8, r9
    add r8, r8, r10
    add r8, r8, r11
    mul r6, r12, r6
    mul r8, r12, r8
    asrs r6, r6, #0x9
    addmi r6, r6, #0x1
    asrs r8, r8, #0x9
    addmi r8, r8, #0x1
    lsl r6, r6, #0x7
    lsl r8, r8, #0x7
    mov r7, r6
    mov r9, r8
    stmia r2!, {r6, r7, r8, r9}
    b lbl_08004330
lbl_080043a0:
    mov r0, r2
    pop {r8-r11, lr}
    pop {r4-r7}
    bx lr
    .pool

@ Signature: u8* CallSoundCodeC(u32*, u32*, u8)
    thumb_func_start CallSoundCodeC
CallSoundCodeC: @ 0x080043b4
    push {r4-r7}
    mov r4, r8
    mov r5, r9
    mov r6, r10
    mov r7, r11
    push {r4-r7, lr}
    adr r4, SoundCodeC
    bx r4

    arm_func_start SoundCodeC
SoundCodeC: @ 0x080043c4
    mov r3, #0x600
    add r3, r0, r3
    mov r12, #0x0
    sub r12, r12, #0x1
    lsr r12, r12, #0x17
    ldr lr, =sArray_808cce2
    b lbl_080043e8
lbl_080043e0:
    subs r2, r2, #0x1
    beq lbl_08004450
lbl_080043e8:
    ldmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11}
    and r4, r12, r4, lsr #0x7
    and r5, r12, r5, lsr #0x7
    and r6, r12, r6, lsr #0x7
    and r7, r12, r7, lsr #0x7
    and r8, r12, r8, lsr #0x7
    and r9, r12, r9, lsr #0x7
    and r10, r12, r10, lsr #0x7
    and r11, r12, r11, lsr #0x7
    ldrb r4, [lr, r4]
    ldrb r5, [lr, r5]
    ldrb r6, [lr, r6]
    ldrb r7, [lr, r7]
    ldrb r8, [lr, r8]
    ldrb r9, [lr, r9]
    ldrb r10, [lr, r10]
    ldrb r11, [lr, r11]
    orr r4, r4, r6, lsl #0x8
    orr r4, r4, r8, lsl #0x10
    orr r4, r4, r10, lsl #0x18
    str r4, [r0], #0x4
    orr r5, r5, r7, lsl #0x8
    orr r5, r5, r9, lsl #0x10
    orr r5, r5, r11, lsl #0x18
    str r5, [r3], #0x4
    b lbl_080043e0
lbl_08004450:
    mov r0, r1
    pop {r8-r11, lr}
    pop {r4-r7}
    bx lr
    .pool

@ Signature: void CallSoundCodeA(struct SoundChannel*, u32*, u8)
    thumb_func_start CallSoundCodeA
CallSoundCodeA: @ 0x08004464
    push {r4-r7}
    mov r3, r8
    mov r4, r9
    mov r5, r10
    mov r6, r11
    push {r3-r6, lr}
    adr r4, SoundCodeA
    bx r4

    arm_func_start SoundCodeA
SoundCodeA: @ 0x08004474
    ldr r12, [r0, o_SoundChannel_unk_18]
    ldrb r11, [r0, o_SoundChannel_unk_11]
    ldrb r10, [r0, o_SoundChannel_unk_12]
    ldr r9, [r0, o_SoundChannel_pData]
    ldr r3, [r0, o_SoundChannel_pSample]
    ldr r8, [r3, #0xC]
    ldrb r4, [r0, o_SoundChannel_unk_1]
    cmp r4, #0x20
    beq lbl_080048c0
    cmp r4, #0x8
    beq lbl_08004794
    mov r7, #0x0
    sub r7, r7, #0x1
    lsr r7, r7, #0x12
    ldr r6, [r0, o_SoundChannel_unk_1C]
    stmdb sp!, {r0}
    ldrh r0, [r3, #0x2]
    ldr lr, [r3, #0x8]
    sub lr, lr, r8
    b lbl_080044cc
lbl_080044c4:
    subs r2, r2, #0x1
    beq lbl_08004aa8
lbl_080044cc:
    add r4, r12, r6, lsl #0x2
    subs r4, r8, r4, lsr #0xE
    bgt lbl_080046d0
    mov r5, r12, lsr #0xE
    ands r0, r0, r0
    bne lbl_080045b8
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    bge lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    bge lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    bge lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    b lbl_08004a98
lbl_080045b8:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    blt lbl_08004600
    and r3, r12, r7
    add r5, r5, lr
    add r12, r3, r5, lsl #0xE
    b lbl_08004700
lbl_08004600:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    blt lbl_08004648
    and r3, r12, r7
    add r5, r5, lr
    add r12, r3, r5, lsl #0xE
    b lbl_08004730
lbl_08004648:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, r8
    blt lbl_08004690
    and r3, r12, r7
    add r5, r5, lr
    add r12, r3, r5, lsl #0xE
    b lbl_08004760
lbl_08004690:
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    and r3, r12, r7
    add r5, r5, lr
    add r12, r3, r5, lsl #0xE
    b lbl_080044c4
lbl_080046d0:
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
lbl_08004700:
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
lbl_08004730:
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
lbl_08004760:
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    b lbl_080044c4
lbl_08004794:
    stmdb sp!, {r0}
    ldrh r7, [r3, #0x2]
    ldr r6, [r3, #0x8]
    b lbl_080047ac
lbl_080047a4:
    subs r2, r2, #0x1
    beq lbl_08004aa8
lbl_080047ac:
    add r4, r12, #0x4
    cmp r4, r8
    blt lbl_0800486c
    ldsb r3, [r9, r12]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, #0x1
    cmp r12, r8
    bne lbl_080047e4
    ands r7, r7, r7
    beq lbl_08004a98
    mov r12, r6
lbl_080047e4:
    ldsb r3, [r9, r12]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, #0x1
    cmp r12, r8
    bne lbl_08004810
    ands r7, r7, r7
    beq lbl_08004a98
    mov r12, r6
lbl_08004810:
    ldsb r3, [r9, r12]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, #0x1
    cmp r12, r8
    bne lbl_0800483c
    ands r7, r7, r7
    beq lbl_08004a98
    mov r12, r6
lbl_0800483c:
    ldsb r3, [r9, r12]
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, #0x1
    cmp r12, r8
    bne lbl_080047a4
    ands r7, r7, r7
    beq lbl_08004a98
    mov r12, r6
    b lbl_080047a4
lbl_0800486c:
    ldmia r1, {r3, r4, r5, lr}
    ldsb r0, [r9, r12]
    mla r3, r0, r11, r3
    mla r4, r0, r10, r4
    add r12, r12, #0x1
    ldsb r0, [r9, r12]
    mla r5, r0, r11, r5
    mla lr, r0, r10, lr
    add r12, r12, #0x1
    stmia r1!, {r3, r4, r5, lr}
    ldmia r1, {r3, r4, r5, lr}
    ldsb r0, [r9, r12]
    mla r3, r0, r11, r3
    mla r4, r0, r10, r4
    add r12, r12, #0x1
    ldsb r0, [r9, r12]
    mla r5, r0, r11, r5
    mla lr, r0, r10, lr
    add r12, r12, #0x1
    stmia r1!, {r3, r4, r5, lr}
    b lbl_080047a4
lbl_080048c0:
    mov r7, #0x0
    sub r7, r7, #0x1
    mov r4, r7
    mov r7, r7, lsr #0x12
    ldr r6, [r0, o_SoundChannel_unk_1C]
    eor r6, r6, r4
    add r6, r6, #0x1
    stmdb sp!, {r0}
    ldrh r0, [r3, #0x2]
    b lbl_080048f0
lbl_080048e8:
    subs r2, r2, #0x1
    beq lbl_08004aa8
lbl_080048f0:
    add r4, r12, r6, lsl #0x2
    movs r4, r4, asr #0xE
    bgt lbl_080049d4
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, #0x0
    ble lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, #0x0
    ble lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    cmp r5, #0x0
    ble lbl_08004a98
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    b lbl_08004a98
lbl_080049d4:
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    mov r5, r12, lsr #0xE
    ldsb r3, [r5, r9]!
    ldsb r4, [r5, #0x1]
    sub r4, r4, r3
    and r5, r12, r7
    mul r4, r5, r4
    add r3, r3, r4, lsr #0xE
    ldmia r1, {r4, r5}
    mla r4, r3, r11, r4
    mla r5, r3, r10, r5
    stmia r1!, {r4, r5}
    add r12, r12, r6
    b lbl_080048e8
lbl_08004a98:
    ldmia sp!, {r0}
    mov r4, #0x0
    strb r4, [r0, o_SoundChannel_unk_0]
    b lbl_08004ab0
lbl_08004aa8:
    ldmia sp!, {r0}
    str r12, [r0, o_SoundChannel_unk_18]
lbl_08004ab0:
    pop {r8-r11, lr}
    pop {r4-r7}
    bx lr

@ Signature: s32 CallGetNoteFrequency(s32, u32)
    thumb_func_start CallGetNoteFrequency
CallGetNoteFrequency: @ 0x08004abc
    adr r2, GetNoteFrequency
    bx r2

    arm_func_start GetNoteFrequency
GetNoteFrequency: @ 0x08004ac0
    umull r2, r3, r0, r1
    lsr r2, r2, #0x12
    lsl r3, r3, #0xe
    add r3, r3, r2
    add r0, r3, #0
    bx lr

    thumb_func_start sub_08004ad8
sub_08004ad8: @ 0x08004ad8
    adr r0, sub_08004adc
    bx r0

    arm_func_start sub_08004adc
sub_08004adc: @ 0x08004adc
    ldr r0, =gMusicInfo
    ldrb r1, [r0, o_MusicInfo_unk_10]
    add r1, r1, #1
    ldrb r3, [r0, o_MusicInfo_unk_E]
    cmp r1, r3
    bne lbl_08004b3c
    ldr r3, =sDma1ControlPointer
    ldr r3, [r3]
    ldr r12, =sDma1ControlValue
    ldr r12, [r12]
    str r12, [r3]
    str r12, [r3, #0xC]
    nop
    mov r12, #0x50
    lsl r12, r12, #0x4
    strh r12, [r3, #0x2]
    strh r12, [r3, #0xE]
    mov r12, #0xB6
    lsl r12, r12, #0x8
    strh r12, [r3, #0x2]
    mov r12, #0xF6
    lsl r12, r12, #0x8
    strh r12, [r3, #0xE]
    mov r1, #0x0
lbl_08004b3c:
    strb r1, [r0, o_MusicInfo_unk_10]
    bx lr
    .align 2, 0
    .pool
