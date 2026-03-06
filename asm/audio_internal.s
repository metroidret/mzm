    .include "asm/macros.inc"
    .include "asm/constants.inc"
    .include "asm/audio_internal_constants.inc"

    .syntax unified

    .text

@ Signature: u8 InitTrack(struct TrackData* pTrack, const u32* pHeader)
    thumb_func_start InitTrack
InitTrack: @ 0x08004b50
    push {r4, r5, r6, r7, lr}
    sub sp, #4
    adds r4, r0, #0
    adds r5, r1, #0
    ldrb r6, [r4, o_TrackData_occupied]
    cmp r6, #0
    bne lbl_08004c04
    movs r6, #1
    strb r6, [r4, o_TrackData_occupied]
    ldrb r6, [r4, o_TrackData_unk_1E]
    movs r7, #1
    ands r6, r7
    bne lbl_08004c00
    ldr r6, [r5]
    lsls r2, r6, #0x18
    lsrs r2, r2, #0x18
    bne lbl_08004b7c
    bl ResetTrack
    movs r2, #0
    strb r2, [r4, o_TrackData_flags]
    b lbl_08004c00
lbl_08004b7c:
    ldr r7, [r4, o_TrackData_flags]
    movs r3, #2
    lsls r2, r7, #0x18
    lsrs r2, r2, #0x18
    ands r3, r2
    beq lbl_08004ba2
    movs r3, o_TrackData_unk_1D
    ldrb r3, [r4, r3]
    cmp r3, #0
    beq lbl_08004b9c
    lsls r1, r6, #8
    lsrs r1, r1, #0x18
    lsrs r2, r7, #0x18
    cmp r2, r1
    ble lbl_08004b9c
    b lbl_08004c0e
lbl_08004b9c:
    adds r0, r4, #0
    bl ResetTrack
lbl_08004ba2:
    movs r3, #2
    lsls r2, r6, #8
    orrs r2, r3
    ldr r0, [r5, #4]
    str r2, [r4, o_TrackData_flags]
    str r0, [r4, o_TrackData_pVoice]
    str r5, [r4, o_TrackData_pHeader]
    lsls r3, r3, #7
    strh r3, [r4, o_TrackData_unk_C]
    lsrs r2, r6, #0x1f
    beq lbl_08004bbe
    lsrs r0, r6, #0x18
    bl DoSoundAction
lbl_08004bbe:
    lsls r6, r6, #0x18
    lsrs r6, r6, #0x18
    ldr r7, [r4, o_TrackData_pVariables]
    movs r0, #0x10
    str r0, [sp]
    movs r0, #3
    movs r1, #0
    adds r2, r7, #0
    movs r3, #0x50
    muls r3, r6, r3
    bl BitFill
    movs r0, #1
    movs r2, #0x40
    lsls r1, r2, #0x10
    lsls r2, r2, #8
    orrs r1, r2
    movs r3, #0xc
    lsls r3, r3, #8
    movs r2, #2
    orrs r2, r3
    adds r5, #8
    b lbl_08004bf4
lbl_08004bec:
    subs r6, #1
    beq lbl_08004c00
    adds r7, o_TrackVariables_size
    adds r5, #4
lbl_08004bf4:
    ldr r3, [r5]
    strb r0, [r7, o_TrackVariables_unk_0]
    strh r2, [r7, o_TrackVariables_bendRange]
    str r1, [r7, o_TrackVariables_volume]
    str r3, [r7, o_TrackVariables_pRawData]
    b lbl_08004bec
lbl_08004c00:
    movs r6, #0
    strb r6, [r4, o_TrackData_occupied]
lbl_08004c04:
    movs r0, #0
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
lbl_08004c0e:
    movs r6, #0
    strb r6, [r4, o_TrackData_occupied]
    movs r0, #1
    add sp, #4
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

@ Signature: void StopMusicOrSound(struct TrackData* pTrack)
    thumb_func_start StopMusicOrSound
StopMusicOrSound: @ 0x08004c1c
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    ldrb r6, [r7, o_TrackData_occupied]
    cmp r6, #0
    bne lbl_08004c8c
    movs r6, #1
    strb r6, [r7, o_TrackData_occupied]
    ldrb r6, [r7, o_TrackData_unk_1E]
    movs r5, #1
    ands r5, r6
    bne lbl_08004c88
    ldrb r4, [r7, o_TrackData_flags]
    movs r5, #2
    ands r4, r5
    beq lbl_08004c88
    movs r4, #1
    strb r4, [r7, o_TrackData_flags]
    movs r4, #0
    strb r4, [r7, o_TrackData_currentTrack]
    ldrb r6, [r7, o_TrackData_amountOfTracks]
    ldr r5, [r7, o_TrackData_pVariables]
    b lbl_08004c4e
lbl_08004c48:
    subs r6, #1
    beq lbl_08004c88
    adds r5, o_TrackVariables_size
lbl_08004c4e:
    ldr r4, [r5, o_TrackVariables_pSoundPSG]
    cmp r4, #0
    beq lbl_08004c6a
    movs r3, #7
    movs r2, o_TrackVariables_channel
    ldrb r1, [r5, r2]
    ands r1, r3
    subs r1, #1
    adds r0, r4, #0
    bl ClearRegistersForPsg
    movs r3, #0
    strb r3, [r4, o_PSGSoundData_unk_0]
    str r3, [r4, o_PSGSoundData_pVariables]
lbl_08004c6a:
    ldr r0, [r5, o_TrackVariables_pChannel]
    movs r1, #0
lbl_08004c6e:
    cmp r0, #0
    beq lbl_08004c80
    ldr r2, [r0, o_SoundChannel_pChannel2]
    strb r1, [r0, o_SoundChannel_unk_0]
    str r1, [r0, o_SoundChannel_pVariables]
    str r1, [r0, o_SoundChannel_pChannel2]
    str r1, [r0, o_SoundChannel_pChannel1]
    adds r0, r2, #0
    b lbl_08004c6e
lbl_08004c80:
    movs r0, #0
    str r0, [r5, o_TrackVariables_pSoundPSG]
    str r0, [r5, o_TrackVariables_pChannel]
    b lbl_08004c48
lbl_08004c88:
    movs r6, #0
    strb r6, [r7, o_TrackData_occupied]
lbl_08004c8c:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0

@ Signature: void ResetTrack(struct TrackData* pTrack)
    thumb_func_start ResetTrack
ResetTrack: @ 0x08004c94
    push {r4, r5, r6, r7, lr}
    adds r7, r0, #0
    ldrb r6, [r7, o_TrackData_unk_1E]
    movs r5, #1
    ands r5, r6
    bne lbl_08004cf6
    ldrb r4, [r7, o_TrackData_flags]
    movs r5, #2
    ands r4, r5
    beq lbl_08004cf6
    movs r4, #1
    strb r4, [r7, o_TrackData_flags]
    movs r4, #0
    strb r4, [r7, o_TrackData_currentTrack]
    ldrb r6, [r7, o_TrackData_amountOfTracks]
    ldr r5, [r7, o_TrackData_pVariables]
    b lbl_08004cbc
lbl_08004cb6:
    subs r6, #1
    beq lbl_08004cf6
    adds r5, o_TrackVariables_size
lbl_08004cbc:
    ldr r4, [r5, o_TrackVariables_pSoundPSG]
    cmp r4, #0
    beq lbl_08004cd8
    movs r3, #7
    movs r2, o_TrackVariables_channel
    ldrb r1, [r5, r2]
    ands r1, r3
    subs r1, #1
    adds r0, r4, #0
    bl ClearRegistersForPsg
    movs r3, #0
    strb r3, [r4, o_PSGSoundData_unk_0]
    str r3, [r4, o_PSGSoundData_pVariables]
lbl_08004cd8:
    ldr r0, [r5, o_TrackVariables_pChannel]
    movs r1, #0
lbl_08004cdc:
    cmp r0, #0
    beq lbl_08004cee
    ldr r2, [r0, o_SoundChannel_pChannel2]
    strb r1, [r0, o_SoundChannel_unk_0]
    str r1, [r0, o_SoundChannel_pVariables]
    str r1, [r0, o_SoundChannel_pChannel2]
    str r1, [r0, o_SoundChannel_pChannel1]
    adds r0, r2, #0
    b lbl_08004cdc
lbl_08004cee:
    movs r0, #0
    str r0, [r5, o_TrackVariables_pSoundPSG]
    str r0, [r5, o_TrackVariables_pChannel]
    b lbl_08004cb6
lbl_08004cf6:
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0

@ Signature: u32 unk_4cfc(struct TrackData* pTrack)
    thumb_func_start unk_4cfc
unk_4cfc: @ 0x08004cfc
    adds r3, r0, #0
    ldr r0, [r3, o_TrackData_unk_C]
    lsls r1, r0, #0x10
    adds r1, r0, r1
    lsrs r1, r1, #0x10
    movs r2, #0xff
    lsls r0, r2, #8
    ands r0, r1
    beq lbl_08004d14
    lsrs r0, r1, #8
    ands r1, r2
    b lbl_08004d16
lbl_08004d14:
    movs r0, #0
lbl_08004d16:
    strh r1, [r3, o_TrackData_unk_E]
    bx lr
    .align 2, 0

@ Signature: void unk_4d1c(struct TrackData* pTrack, struct TrackVariables* pVariables)
    thumb_func_start unk_4d1c
unk_4d1c: @ 0x08004d1c
    ldr r2, [r1, o_TrackVariables_pRawData]
    ldrb r3, [r2, #1]
    adds r2, #2
    str r2, [r1, o_TrackVariables_pRawData]
    lsls r2, r3, #1
    strh r2, [r0, o_TrackData_unk_A]
    cmp r2, #0x96
    beq lbl_08004d3c
    movs r1, #0x1b
    movs r3, #0x4e
    lsls r1, r1, #8
    orrs r1, r3
    lsls r2, r2, #8
    muls r1, r2, r1
    lsrs r1, r1, #0x14
    b lbl_08004d40
lbl_08004d3c:
    movs r1, #1
    lsls r1, r1, #8
lbl_08004d40:
    movs r3, #0
    strh r1, [r0, o_TrackData_unk_C]
    strh r3, [r0, o_TrackData_unk_E]
    bx lr

@ Signature: void UpdateAudio(void)
    thumb_func_start UpdateAudio
UpdateAudio: @ 0x08004d48
    push {r4, r5, r6, lr}
    ldr r4, lbl_08004df4 @ =sMusicTrackDataRom
    ldr r5, lbl_08004df8 @ =gNumMusicPlayers
    ldr r6, lbl_08004dfc @ =gSoundQueue
    b lbl_08004d5c
lbl_08004d52:
    subs r5, #1
    cmp r5, #0
    beq lbl_08004d72
    adds r4, #0xc
    adds r6, #8
lbl_08004d5c:
    ldrb r3, [r6, o_SoundQueue_exists]
    cmp r3, #0
    beq lbl_08004d52
    ldr r0, [r4, o_TrackGroupROMData_pTrack]
    ldr r1, [r6, o_SoundQueue_pHeader]
    bl InitTrack
    movs r0, #0
    str r0, [r6, o_SoundQueue_exists]
    str r0, [r6, o_SoundQueue_pHeader]
    b lbl_08004d52
lbl_08004d72:
    ldr r4, lbl_08004e00 @ =sMusicTrackDataRom
    ldr r6, lbl_08004e04 @ =gMusicInfo
    movs r0, o_MusicInfo_priority
    ldrb r0, [r6, r0]
    movs r1, #0x80
    ands r1, r0
    beq lbl_08004d92
    movs r1, #0x7f
    ands r0, r1
    movs r1, #4
    cmp r0, r1
    beq lbl_08004dd8
    adds r4, #0xc
    ldr r5, lbl_08004e08 @ =gNumMusicPlayers
    subs r5, #1
    b lbl_08004da8
lbl_08004d92:
    movs r0, o_MusicInfo_priority
    ldrb r0, [r6, r0]
    movs r1, #4
    cmp r0, r1
    beq lbl_08004dbc
    ldr r5, lbl_08004e0c @ =gNumMusicPlayers
    b lbl_08004da8
lbl_08004da0:
    subs r5, #1
    cmp r5, #0
    beq lbl_08004dd8
    adds r4, #0xc
lbl_08004da8:
    ldr r0, [r4]
    cmp r0, #0
    beq lbl_08004da0
    ldrb r3, [r0]
    movs r1, #2
    ands r3, r1
    beq lbl_08004da0
    bl UpdateTrack
    b lbl_08004da0
lbl_08004dbc:
    movs r0, o_MusicInfo_unk_20
    ldrb r0, [r6, r0]
    movs r1, #0
    cmp r0, r1
    beq lbl_08004dc8
    movs r1, #0xc
lbl_08004dc8:
    adds r4, r4, r1
    ldr r0, [r4]
    ldrb r3, [r0]
    movs r1, #2
    ands r3, r1
    beq lbl_08004dd8
    bl UpdateTrack
lbl_08004dd8:
    ldrb r5, [r6, o_MusicInfo_occupied]
    cmp r5, #0
    bne lbl_08004dea
    movs r5, #1
    strb r5, [r6, o_MusicInfo_occupied]
    bl UpdatePsgSounds
    bl UpdateMusic
lbl_08004dea:
    movs r0, #0
    strb r0, [r6, o_MusicInfo_occupied]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_08004df4: .4byte sMusicTrackDataRom
lbl_08004df8: .4byte gNumMusicPlayers
lbl_08004dfc: .4byte gSoundQueue
lbl_08004e00: .4byte sMusicTrackDataRom
lbl_08004e04: .4byte gMusicInfo
lbl_08004e08: .4byte gNumMusicPlayers
lbl_08004e0c: .4byte gNumMusicPlayers

@ Signature: void unk_4e10(struct TrackVariables* pVariables)
    thumb_func_start unk_4e10
unk_4e10: @ 0x08004e10
    push {r4, r5, lr}
    ldr r1, [r0, o_TrackVariables_pSample2]
    ldrb r2, [r0, o_TrackVariables_unk_1]
    ldrb r3, [r0, o_TrackVariables_unk_0]
    movs r4, #0xf0
    ands r3, r4
    cmp r3, #0x80
    bne lbl_08004e40
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
    ldrb r2, [r1, #1]
    movs r3, o_TrackVariables_unk_35
    strb r2, [r0, r3]
    ldrb r2, [r1, #3]
    cmp r2, #0
    bne lbl_08004e38
    movs r2, #0x40
    strb r2, [r0, o_TrackVariables_unk_6]
    b lbl_08004e4c
lbl_08004e38:
    subs r2, #0x80
    bmi lbl_08004e4c
    strb r2, [r0, o_TrackVariables_unk_6]
    b lbl_08004e4c
lbl_08004e40:
    ldr r3, [r0, o_TrackVariables_envelope2]
    adds r3, r3, r2
    ldrb r3, [r3]
    movs r4, #0xc
    muls r3, r4, r3
    adds r1, r1, r3
lbl_08004e4c:
    ldr r2, [r1]
    lsls r3, r2, #0x18
    lsrs r3, r3, #0x18
    movs r4, o_TrackVariables_channel
    strb r3, [r0, r4]
    lsls r4, r2, #8
    lsrs r4, r4, #0x18
    movs r5, o_TrackVariables_unk_36
    strb r4, [r0, r5]
    movs r4, #7
    ands r3, r4
    bne lbl_08004e6a
    ldr r3, [r1, #4]
    str r3, [r0, o_TrackVariables_pSample1]
    b lbl_08004eaa
lbl_08004e6a:
    cmp r3, #2
    bgt lbl_08004e88
    lsrs r3, r2, #0x18
    movs r4, #0x80
    ands r4, r3
    bne lbl_08004e7e
    movs r4, #0x70
    ands r4, r3
    beq lbl_08004e7e
    b lbl_08004e80
lbl_08004e7e:
    movs r3, #8
lbl_08004e80:
    movs r4, o_TrackVariables_unk_37
    strb r3, [r0, r4]
    movs r4, #6
    b lbl_08004ea2
lbl_08004e88:
    cmp r3, #3
    bne lbl_08004e9c
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, [r5, #4]
    bl UploadSampleToWaveRam
    adds r0, r4, #0
    adds r1, r5, #0
    b lbl_08004eaa
lbl_08004e9c:
    cmp r3, #4
    bne lbl_08004eaa
    movs r4, #3
lbl_08004ea2:
    ldr r3, [r1, #4]
    lsls r3, r4
    movs r4, o_TrackVariables_pSample1
    strb r3, [r0, r4]
lbl_08004eaa:
    ldr r2, [r1, #8]
    str r2, [r0, o_TrackVariables_envelope1]
    pop {r4, r5}
    pop {r0}
    bx r0

@ Signature: void unk_4eb4(struct TrackVariables* pVariables)
    thumb_func_start unk_4eb4
unk_4eb4: @ 0x08004eb4
    movs r1, o_TrackVariables_pitchBend
    ldrsb r1, [r0, r1]
    cmp r1, #0
    ble lbl_08004ebe
    adds r1, #1
lbl_08004ebe:
    ldr r2, [r0, o_TrackVariables_keyShift]
    ldrb r3, [r0, o_TrackVariables_bendRange]
    muls r1, r3, r1
    lsls r1, r1, #2
    lsls r3, r2, #0x18
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    lsls r3, r2, #0x10
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    lsls r3, r2, #8
    asrs r3, r3, #0x16
    lsls r3, r3, #2
    adds r1, r1, r3
    lsrs r2, r2, #0x18
    adds r1, r1, r2
    movs r3, o_TrackVariables_lfoSpeed
    ldr r2, [r0, r3]
    movs r3, #0xff
    ands r3, r2
    beq lbl_08004f06
    movs r3, #0xff
    lsls r3, r3, #8
    ands r3, r2
    beq lbl_08004f06
    lsls r3, r2, #8
    lsrs r3, r3, #0x18
    cmp r3, #0
    bne lbl_08004f06
    asrs r2, r2, #0x18
    lsls r2, r2, #2
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
lbl_08004f06:
    asrs r2, r1, #8
    strb r2, [r0, o_TrackVariables_unk_17]
    strb r1, [r0, o_TrackVariables_unk_18]
    bx lr
    .align 2, 0

@ Signature: void unk_4f10(struct TrackVariables* pVariables)
    thumb_func_start unk_4f10
unk_4f10: @ 0x08004f10
    push {r4}
    ldr r1, [r0, o_TrackVariables_volume]
    lsls r2, r1, #0x18
    lsrs r2, r2, #0x18
    lsls r3, r1, #0x10
    lsrs r3, r3, #0x18
    muls r2, r3, r2
    lsrs r2, r2, #5
    ldrh r3, [r0, o_TrackVariables_modulationType]
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #1
    bne lbl_08004f3a
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r4, #0x41
    muls r2, r4, r2
    asrs r2, r2, #6
    cmp r2, #0xff
    blt lbl_08004f3a
    movs r2, #0xff
lbl_08004f3a:
    lsls r4, r1, #8
    lsrs r4, r4, #0x18
    asrs r1, r1, #0x18
    adds r1, r1, r4
    subs r1, #0x40
    cmp r1, #0x3f
    blt lbl_08004f4c
    movs r1, #0x3f
    b lbl_08004f56
lbl_08004f4c:
    movs r4, #0x40
    rsbs r4, r4, #0
    cmp r1, r4
    bpl lbl_08004f56
    rsbs r1, r4, #0
lbl_08004f56:
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #2
    bne lbl_08004f74
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r1, r1, r4
    cmp r1, #0x3f
    blt lbl_08004f6c
    movs r1, #0x3f
    b lbl_08004f74
lbl_08004f6c:
    movs r4, #0x40
    adds r3, r1, r4
    bpl lbl_08004f74
    rsbs r1, r4, #0
lbl_08004f74:
    movs r4, #0x40
    adds r3, r1, r4
    muls r3, r2, r3
    lsrs r3, r3, #7
    subs r4, r4, r1
    muls r4, r2, r4
    lsrs r4, r4, #7
    lsls r4, r4, #8
    orrs r3, r4
    strh r3, [r0, o_TrackVariables_unk_8]
    pop {r4}
    bx lr

@ Signature: void unk_4f8c(struct SoundChannel* pChannel, struct TrackVariables* pVariables, s32 param_3)
    thumb_func_start unk_4f8c
unk_4f8c: @ 0x08004f8c
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    ldrb r1, [r4, o_SoundChannel_unk_13]
    movs r2, #2
    orrs r1, r2
    strb r1, [r4, o_SoundChannel_unk_13]
    bl unk_20a4
    ldr r0, [r5, o_TrackVariables_pChannel]
    cmp r0, #0
    beq lbl_08004fa8
    str r4, [r0, o_SoundChannel_pChannel1]
lbl_08004fa8:
    str r0, [r4, o_SoundChannel_pChannel2]
    movs r1, #0
    str r1, [r4, o_SoundChannel_pChannel1]
    str r5, [r4, o_SoundChannel_pVariables]
    str r4, [r5, o_TrackVariables_pChannel]
    movs r1, o_TrackVariables_channel
    ldrb r0, [r5, r1]
    ldrb r1, [r5, o_TrackVariables_unk_6]
    lsls r0, r0, #8
    lsls r6, r6, #0x10
    lsls r1, r1, #0x18
    movs r2, #1
    orrs r0, r1
    orrs r0, r2
    orrs r0, r6
    str r0, [r4, o_SoundChannel_unk_0]
    ldr r0, [r5, o_TrackVariables_envelope1]
    str r0, [r4, o_SoundChannel_envelope]
    ldr r0, [r5, o_TrackVariables_unk_C]
    str r0, [r4, o_SoundChannel_unk_C]
    movs r1, #0x10
    movs r2, #0xc
    ldr r0, [r5, o_TrackVariables_pSample1]
    adds r1, r1, r0
    adds r2, r2, r0
    str r0, [r4, o_SoundChannel_pSample]
    str r1, [r4, o_SoundChannel_pData]
    str r2, [r4, o_SoundChannel_pSize]
    ldrh r1, [r5, o_TrackVariables_unk_0]
    lsrs r2, r1, #8
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    strb r2, [r4, o_SoundChannel_unk_6]
    movs r3, #0xf0
    ands r1, r3
    cmp r1, #0x80
    bne lbl_08004ff6
    movs r3, o_TrackVariables_unk_35
    ldrb r2, [r5, r3]
lbl_08004ff6:
    strb r2, [r4, o_SoundChannel_unk_7]
    movs r3, o_TrackVariables_unk_17
    ldrsb r1, [r5, r3]
    adds r1, r1, r2
    bmi lbl_08005008
    cmp r1, #0x7f
    ble lbl_0800500a
    movs r1, #0x7f
    b lbl_0800500a
lbl_08005008:
    movs r1, #0
lbl_0800500a:
    ldrb r2, [r5, o_TrackVariables_unk_18]
    bl MidiKey2Freq
    ldr r1, lbl_0800502c @ =gMusicInfo
    ldrh r2, [r1, o_MusicInfo_sampleRate]
    cmp r0, r2
    bne lbl_0800501e
    movs r0, #0x40
    lsls r0, r0, #8
    b lbl_08005024
lbl_0800501e:
    ldr r1, [r1, o_MusicInfo_pitch]
    bl CallGetNoteFrequency
lbl_08005024:
    str r0, [r4, o_SoundChannel_unk_1C]
    pop {r4, r5, r6}
    pop {r0}
    bx r0
    .align 2, 0
lbl_0800502c: .4byte gMusicInfo

@ Signature: void AudioCommand_Goto(struct TrackVariables* pVariables)
    thumb_func_start AudioCommand_Goto
AudioCommand_Goto: @ 0x08005030
    ldr r1, [r0, o_TrackVariables_pRawData]
    adds r1, #1
    movs r2, #3
    ands r2, r1
    bne lbl_0800503e
    ldr r2, [r1]
    b lbl_0800506a
lbl_0800503e:
    movs r2, #1
    ands r2, r1
    bne lbl_08005050
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    b lbl_0800506a
lbl_08005050:
    ldrb r2, [r1]
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #8
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x18
    orrs r2, r3
lbl_0800506a:
    str r2, [r0, o_TrackVariables_pRawData]
    bx lr
    .align 2, 0

@ Signature: void AudioCommand_PatternPlay(struct TrackVariables* pVariables)
    thumb_func_start AudioCommand_PatternPlay
AudioCommand_PatternPlay: @ 0x08005070
    ldr r1, [r0, o_TrackVariables_pRawData]
    adds r1, #1
    movs r2, #3
    ands r2, r1
    bne lbl_08005080
    ldr r2, [r1]
    adds r1, #4
    b lbl_080050b0
lbl_08005080:
    movs r2, #1
    ands r2, r1
    bne lbl_08005094
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #2
    b lbl_080050b0
lbl_08005094:
    ldrb r2, [r1]
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #8
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #1
    ldrb r3, [r1]
    lsls r3, r3, #0x18
    orrs r2, r3
    adds r1, #1
lbl_080050b0:
    str r2, [r0, o_TrackVariables_pRawData]
    adds r0, o_TrackVariables_patternStartPointers
    ldr r2, [r0]
    cmp r2, #0
    beq lbl_080050ca
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    beq lbl_080050ca
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    bne lbl_080050cc
lbl_080050ca:
    str r1, [r0]
lbl_080050cc:
    bx lr
    .align 2, 0

@ Signature: void UploadSampleToWaveRam(const u32* pSample)
    thumb_func_start UploadSampleToWaveRam
UploadSampleToWaveRam: @ 0x080050d0
    ldr r3, lbl_080050fc @ =REG_SOUND3CNT_L
    movs r2, #0x40
    strb r2, [r3]
    ldr r1, lbl_08005100 @ =REG_WAVE_RAM0_L
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1]
    movs r2, #0
    strb r2, [r3]
    bx lr
    .align 2, 0
lbl_080050fc: .4byte REG_SOUND3CNT_L
lbl_08005100: .4byte REG_WAVE_RAM0_L

@ Signature: void unk_5104(struct PSGSoundData* pSound)
    thumb_func_start unk_5104
unk_5104: @ 0x08005104
    push {r4, r5}
    ldr r4, [r0, o_PSGSoundData_unk_10]
    ldrh r5, [r0, o_PSGSoundData_unk_14]
    ldr r1, [r0, o_PSGSoundData_pVariables]
    movs r2, o_TrackVariables_channel
    ldrb r1, [r1, r2]
    cmp r1, #8
    ble lbl_0800513e
    movs r2, #4
    movs r3, #0x89
    lsls r2, r2, #0x18
    orrs r2, r3
    ldrb r2, [r2]
    lsrs r2, r2, #6
    lsls r2, r2, #6
    movs r3, #0x40
    cmp r2, r3
    bge lbl_0800512c
    adds r5, #2
    b lbl_08005134
lbl_0800512c:
    movs r3, #0x80
    cmp r2, r3
    bge lbl_0800513e
    adds r5, #1
lbl_08005134:
    movs r2, #0xc7
    movs r3, #0xfe
    lsls r2, r2, #8
    orrs r2, r3
    ands r5, r2
lbl_0800513e:
    movs r2, #4
    movs r3, #0x60
    lsls r2, r2, #0x18
    orrs r2, r3
    movs r3, #7
    ands r1, r3
    lsls r3, r4, #8
    lsrs r3, r3, #0x10
    cmp r1, #1
    beq lbl_08005160
    cmp r1, #2
    beq lbl_08005172
    cmp r1, #3
    beq lbl_08005178
    cmp r1, #4
    beq lbl_08005180
    b lbl_08005184
lbl_08005160:
    strb r4, [r2]
    strh r3, [r2, #2]
    strh r5, [r2, #4]
    mov r8, r8
    mov r8, r8
    mov r8, r8
    mov r8, r8
    strh r5, [r2, #4]
    b lbl_08005184
lbl_08005172:
    strh r3, [r2, #8]
    strh r5, [r2, #0xc]
    b lbl_08005184
lbl_08005178:
    strb r4, [r2, #0x10]
    strh r3, [r2, #0x12]
    strh r5, [r2, #0x14]
    b lbl_08005184
lbl_08005180:
    strh r3, [r2, #0x18]
    strh r5, [r2, #0x1c]
lbl_08005184:
    lsls r5, r5, #0x11
    lsrs r5, r5, #0x11
    strh r5, [r0, o_PSGSoundData_unk_14]
    pop {r4, r5}
    bx lr
    .align 2, 0
    