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
    strh r3, [r4, o_TrackData_tempoInterval_maybe]
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
    ldr r2, [r0, o_SoundChannel_pChannelNext_maybe]
    strb r1, [r0, o_SoundChannel_envelopeStage_maybe]
    str r1, [r0, o_SoundChannel_pVariables]
    str r1, [r0, o_SoundChannel_pChannelNext_maybe]
    str r1, [r0, o_SoundChannel_pChannelPrev_maybe]
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
    ldr r2, [r0, o_SoundChannel_pChannelNext_maybe]
    strb r1, [r0, o_SoundChannel_envelopeStage_maybe]
    str r1, [r0, o_SoundChannel_pVariables]
    str r1, [r0, o_SoundChannel_pChannelNext_maybe]
    str r1, [r0, o_SoundChannel_pChannelPrev_maybe]
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

@ Signature: u32 TrackUpdateTempo(struct TrackData* pTrack)
    thumb_func_start TrackUpdateTempo
TrackUpdateTempo: @ 0x08004cfc
    adds r3, r0, #0
    @ r1 = o_TrackData_tempoInterval_maybe + o_TrackData_tempoCounter_maybe
    ldr r0, [r3, o_TrackData_tempoInterval_maybe]
    lsls r1, r0, #0x10
    adds r1, r0, r1
    lsrs r1, r1, #0x10
    @ r0 = r1 & 0xFF00
    movs r2, #0xff
    lsls r0, r2, #8
    ands r0, r1
    beq TrackUpdateTempo_no_tempo_remaining
    @ r0 gets the remaining tempo
    @ r1 gets the subtempo
    lsrs r0, r1, #8
    ands r1, r2
    b TrackUpdateTempo_exit
TrackUpdateTempo_no_tempo_remaining:
    movs r0, #0
TrackUpdateTempo_exit:
    strh r1, [r3, o_TrackData_tempoCounter_maybe]
    bx lr
    .align 2, 0

@ Signature: void AudioCommand_Tempo(struct TrackData* pTrack, struct TrackVariables* pVariables)
    thumb_func_start AudioCommand_Tempo
AudioCommand_Tempo: @ 0x08004d1c
    @ r3 = pVariables->pRawData[1]
    ldr r2, [r1, o_TrackVariables_pRawData]
    ldrb r3, [r2, #1]
    @ pVariables->pRawData += 2
    adds r2, #2
    str r2, [r1, o_TrackVariables_pRawData]
    @ pTrack->tempoRawBpm_maybe = r2 = r3 << 1
    lsls r2, r3, #1
    strh r2, [r0, o_TrackData_tempoRawBpm_maybe]
    cmp r2, #0x96
    beq lbl_08004d3c
    @ Following the math gives r1 = r2 * 1.706542969
    @ This is an approximation of r1 = r2 * 256 / 150
    @ Where 256 / 150 = 1.706666667
    movs r1, #0x1b
    movs r3, #0x4e
    lsls r1, r1, #8
    orrs r1, r3
    lsls r2, r2, #8
    muls r1, r2, r1
    lsrs r1, r1, #0x14
    b lbl_08004d40
lbl_08004d3c:
    @ r1 = 256
    movs r1, #1
    lsls r1, r1, #8
lbl_08004d40:
    movs r3, #0
    @ pTrack->tempoInterval_maybe = r1
    strh r1, [r0, o_TrackData_tempoInterval_maybe]
    @ pTrack->tempoCounter_maybe = 0
    strh r3, [r0, o_TrackData_tempoCounter_maybe]
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
    ldrb r2, [r0, o_TrackVariables_key_maybe]
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
    strb r2, [r0, o_TrackVariables_pan_maybe]
    b lbl_08004e4c
lbl_08004e38:
    subs r2, #0x80
    bmi lbl_08004e4c
    strb r2, [r0, o_TrackVariables_pan_maybe]
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
    bl UploadSampleToWaveRAM
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

@ Signature: void TrackUpdatePitch(struct TrackVariables* pVariables)
    thumb_func_start TrackUpdatePitch
TrackUpdatePitch: @ 0x08004eb4
    @ r1 = pVariables->pitchBend
    movs r1, o_TrackVariables_pitchBend
    ldrsb r1, [r0, r1]
    cmp r1, #0
    ble lbl_08004ebe
    adds r1, #1
lbl_08004ebe:
    ldr r2, [r0, o_TrackVariables_keyShift]
    ldrb r3, [r0, o_TrackVariables_bendRange]
    @ r1 = (r1 * pVariables->bendRange) << 2
    muls r1, r3, r1
    lsls r1, r1, #2
    @ r1 = r1 + (pVariables->keyShift << 8)
    lsls r3, r2, #0x18
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    @ r1 = r1 + (pVariables->keyShiftX_maybe << 8)
    lsls r3, r2, #0x10
    asrs r3, r3, #0x18
    lsls r3, r3, #8
    adds r1, r1, r3
    @ r1 = r1 + ((pVariables->tune << 2) | ((pVariables->keyShiftX_maybe >> 6) << 2))
    lsls r3, r2, #8
    asrs r3, r3, #0x16
    lsls r3, r3, #2
    adds r1, r1, r3
    lsrs r2, r2, #0x18
    @ r1 = r1 + pVariables->pitchX_maybe
    adds r1, r1, r2
    movs r3, o_TrackVariables_lfoSpeed
    ldr r2, [r0, r3]
    @ pVariables->lfoSpeed
    movs r3, #0xff
    ands r3, r2
    beq lbl_08004f06
    @ pVariables->modulationDepth
    movs r3, #0xff
    lsls r3, r3, #8
    ands r3, r2
    beq lbl_08004f06
    @ pVariables->modulationType
    lsls r3, r2, #8
    lsrs r3, r3, #0x18
    cmp r3, #0
    bne lbl_08004f06
    @ r1 = r1 + (pVariables->modulationCalculated_maybe << 2) * 12
    asrs r2, r2, #0x18
    lsls r2, r2, #2
    movs r3, #0xc
    muls r2, r3, r2
    adds r1, r1, r2
lbl_08004f06:
    @ pVariables->keyShiftCalculated_maybe = r1 >> 8
    @ pVariables->pitchCalculated_maybe = r1
    asrs r2, r1, #8
    strb r2, [r0, o_TrackVariables_keyShiftCalculated_maybe]
    strb r1, [r0, o_TrackVariables_pitchCalculated_maybe]
    bx lr
    .align 2, 0

@ Signature: void TrackUpdateVolume(struct TrackVariables* pVariables)
    thumb_func_start TrackUpdateVolume
TrackUpdateVolume: @ 0x08004f10
    push {r4}
    ldr r1, [r0, o_TrackVariables_volume]
    lsls r2, r1, #0x18
    lsrs r2, r2, #0x18
    lsls r3, r1, #0x10
    lsrs r3, r3, #0x18
    @ r2 = (pVariables->volume * pVariables->volumeX_maybe) >> 5
    muls r2, r3, r2
    lsrs r2, r2, #5
    @ r4 = pVariables->modulationType
    ldrh r3, [r0, o_TrackVariables_modulationType]
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #1
    bne lbl_08004f3a
    @ r4 = pVariables->modulationCalculated_maybe + 0x41
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    adds r4, #0x41
    @ r2 = (r2 * r4) >> 6
    muls r2, r4, r2
    asrs r2, r2, #6
    cmp r2, #0xff
    blt lbl_08004f3a
    movs r2, #0xff
lbl_08004f3a:
    @ r4 = pVariables->pan_maybe
    lsls r4, r1, #8
    lsrs r4, r4, #0x18
    @ r1 = pVariables->panX_maybe + pVariables->pan_maybe - 0x40
    asrs r1, r1, #0x18
    adds r1, r1, r4
    subs r1, #0x40
    cmp r1, #0x3f
    blt lbl_08004f4c
    @ r1 = 0x3f
    movs r1, #0x3f
    b lbl_08004f56
lbl_08004f4c:
    movs r4, #0x40
    negs r4, r4
    cmp r1, r4
    bpl lbl_08004f56
    @ r1 = 0x40
    negs r1, r4
lbl_08004f56:
    @ r4 = pVariables->modulationType
    lsls r4, r3, #0x18
    lsrs r4, r4, #0x18
    cmp r4, #2
    bne lbl_08004f74
    @ r4 = pVariables->modulationCalculated_maybe
    lsls r4, r3, #0x10
    asrs r4, r4, #0x18
    @ r1 = r1 + pVariables->modulationCalculated_maybe
    adds r1, r1, r4
    cmp r1, #0x3f
    blt lbl_08004f6c
    @ r1 = 0x3f
    movs r1, #0x3f
    b lbl_08004f74
lbl_08004f6c:
    movs r4, #0x40
    adds r3, r1, r4
    bpl lbl_08004f74
    @ r1 = -0x40
    negs r1, r4
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
    @ pVariables->volRightCalculated_maybe = ((r1 + 0x40) * r2) >> 7
    @ pVariables->volLeftCalculated_maybe = ((0x40 - r1) * r2) >> 7
    strh r3, [r0, o_TrackVariables_volRightCalculated_maybe]
    pop {r4}
    bx lr

@ Signature: void TrackSendVariablesToChannel(struct SoundChannel* pChannel, struct TrackVariables* pVariables, s32 priority)
    thumb_func_start TrackSendVariablesToChannel
TrackSendVariablesToChannel: @ 0x08004f8c
    push {r4, r5, r6, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    adds r6, r2, #0
    @ pChannel->volumeUpdateFlag_maybe |= VOLUME_UPDATE_FLAG_RESET
    ldrb r1, [r4, o_SoundChannel_volumeUpdateFlag_maybe]
    movs r2, #2
    orrs r1, r2
    strb r1, [r4, o_SoundChannel_volumeUpdateFlag_maybe]
    bl FreeSoundChannel
    @ if pVariables->pChannel is NULL, don't update it
    ldr r0, [r5, o_TrackVariables_pChannel]
    cmp r0, #0
    beq TrackSendVariablesToChannel_skip_channel_prev
    @ pVariables->pChannel->pChannelPrev_maybe = pChannel
    str r4, [r0, o_SoundChannel_pChannelPrev_maybe]
TrackSendVariablesToChannel_skip_channel_prev:
    @ pChannel->pChannelNext_maybe = pVariables->pChannel
    str r0, [r4, o_SoundChannel_pChannelNext_maybe]
    @ pChannel->pChannelPrev_maybe = NULL
    movs r1, #0
    str r1, [r4, o_SoundChannel_pChannelPrev_maybe]
    @ pChannel->pVariables = pVariables
    str r5, [r4, o_SoundChannel_pVariables]
    @ pVariables->pChannel = pChannel
    str r4, [r5, o_TrackVariables_pChannel]
    movs r1, o_TrackVariables_channel
    ldrb r0, [r5, r1]
    ldrb r1, [r5, o_TrackVariables_pan_maybe]
    lsls r0, r0, #8
    lsls r6, r6, #0x10
    lsls r1, r1, #0x18
    movs r2, #1
    orrs r0, r1
    orrs r0, r2
    orrs r0, r6
    @ pChannel->envelopeStage_maybe = 1
    @ pChannel->unk_1 = pVariables->channel
    @ pChannel->unk_2 = priority
    @ pChannel->unk_3 = pVariables->pan_maybe
    str r0, [r4, o_SoundChannel_envelopeStage_maybe]
    @ pChannel->envelope = pVariables->envelope1
    ldr r0, [r5, o_TrackVariables_envelope1]
    str r0, [r4, o_SoundChannel_envelope]
    @ pChannel->echoVol_maybe = pVariables->echoVolume_maybe
    @ pChannel->echoLen_maybe = pVariables->echoLength_maybe
    @ pChannel->gateTime_maybe = pVariables->gateTime_maybe
    @ pChannel->velocity_maybe = pVariables->velocity_maybe
    ldr r0, [r5, o_TrackVariables_echoVolume_maybe]
    str r0, [r4, o_SoundChannel_echoVol_maybe]
    movs r1, #0x10
    movs r2, #0xc
    ldr r0, [r5, o_TrackVariables_pSample1]
    adds r1, r1, r0
    adds r2, r2, r0
    @ pChannel->pSample = pVariables->pSample1
    str r0, [r4, o_SoundChannel_pSample]
    @ pChannel->pData = pVariables->pSample1 + 4
    str r1, [r4, o_SoundChannel_pData]
    @ pChannel->pSize = pVariables->pSample1 + 3
    str r2, [r4, o_SoundChannel_pSize]
    @ r1 = pVariables->unk_0
    @ r2 = pVariables->key_maybe
    ldrh r1, [r5, o_TrackVariables_unk_0]
    lsrs r2, r1, #8
    lsls r1, r1, #0x18
    lsrs r1, r1, #0x18
    @ pChannel->unk_6 = pVariables->key_maybe
    strb r2, [r4, o_SoundChannel_unk_6]
    @ if (pVariables->unk_0 & 0xF0) != 0x80, don't use unk_35
    movs r3, #0xf0
    ands r1, r3
    cmp r1, #0x80
    bne lbl_08004ff6
    movs r3, o_TrackVariables_unk_35
    @ r2 = pVariables->unk_35
    ldrb r2, [r5, r3]
lbl_08004ff6:
    @ pChannel->unk_7 = r2
    strb r2, [r4, o_SoundChannel_unk_7]
    @ midikey = r1 = pVariables->keyShiftCalculated_maybe + pChannel->unk_7
    movs r3, o_TrackVariables_keyShiftCalculated_maybe
    ldrsb r1, [r5, r3]
    adds r1, r1, r2
    bmi TrackSendVariablesToChannel_clamp_0
    cmp r1, #0x7f
    ble TrackSendVariablesToChannel_finish_clamp
    movs r1, #0x7f
    b TrackSendVariablesToChannel_finish_clamp
TrackSendVariablesToChannel_clamp_0:
    movs r1, #0
TrackSendVariablesToChannel_finish_clamp:
    @ frequency = r0 = MidiKey2Freq(pVariables->pSample1, midikey, pVariables->pitchCalculated_maybe)
    ldrb r2, [r5, o_TrackVariables_pitchCalculated_maybe]
    bl MidiKey2Freq
    @ if (frequency == gMusicInfo.sampleRate) use CallGetNoteFrequency result
    ldr r1, lbl_0800502c @ =gMusicInfo
    ldrh r2, [r1, o_MusicInfo_sampleRate]
    cmp r0, r2
    bne TrackSendVariablesToChannel_use_note_frequency
    @ frequency = 0x4000
    movs r0, #0x40
    lsls r0, r0, #8
    b lbl_08005024
TrackSendVariablesToChannel_use_note_frequency:
    @ frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch)
    ldr r1, [r1, o_MusicInfo_pitch]
    bl CallGetNoteFrequency
lbl_08005024:
    @ pChannel->unk_1C = frequency
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
    bne AudioCommand_Goto_not_word_aligned
    @ Read full word if word aligned
    ldr r2, [r1]
    b AudioCommand_Goto_update_raw
AudioCommand_Goto_not_word_aligned:
    movs r2, #1
    ands r2, r1
    bne AudioCommand_Goto_not_halfword_aligned
    @ Read two half words if half word aligned
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    b AudioCommand_Goto_update_raw
AudioCommand_Goto_not_halfword_aligned:
    @ Read four bytes if not word or half word aligned
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
AudioCommand_Goto_update_raw:
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
    bne AudioCommand_PatternPlay_not_word_aligned
    @ Read full word if word aligned
    ldr r2, [r1]
    adds r1, #4
    b AudioCommand_PatternPlay_update_raw
AudioCommand_PatternPlay_not_word_aligned:
    movs r2, #1
    ands r2, r1
    bne AudioCommand_PatternPlay_not_halfword_aligned
    @ Read two half words if half word aligned
    ldrh r2, [r1]
    adds r1, #2
    ldrh r3, [r1]
    lsls r3, r3, #0x10
    orrs r2, r3
    adds r1, #2
    b AudioCommand_PatternPlay_update_raw
AudioCommand_PatternPlay_not_halfword_aligned:
    @ Read four bytes if not word or half word aligned
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
AudioCommand_PatternPlay_update_raw:
    str r2, [r0, o_TrackVariables_pRawData]
    adds r0, o_TrackVariables_patternStartPointers
    ldr r2, [r0]
    cmp r2, #0
    beq AudioCommand_PatternPlay_update_start
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    beq AudioCommand_PatternPlay_update_start
    adds r0, #4
    ldr r2, [r0]
    cmp r2, #0
    bne AudioCommand_PatternPlay_exit
AudioCommand_PatternPlay_update_start:
    str r1, [r0]
AudioCommand_PatternPlay_exit:
    bx lr
    .align 2, 0

@ Signature: void UploadSampleToWaveRAM(const u32* pSample)
    thumb_func_start UploadSampleToWaveRAM
UploadSampleToWaveRAM: @ 0x080050d0
    ldr r3, lbl_080050fc @ =REG_SOUND3CNT_L
    @ Set REG_SOUND3CNT_L wave ram bank = 1
    movs r2, #0x40
    strb r2, [r3]
    ldr r1, lbl_08005100 @ =REG_WAVE_RAM0_L
    ldr r2, [r0]
    str r2, [r1] @ =REG_WAVE_RAM0_L = *pSample++
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1] @ =REG_WAVE_RAM1_L = *pSample++
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1] @ =REG_WAVE_RAM2_L = *pSample++
    adds r0, #4
    adds r1, #4
    ldr r2, [r0]
    str r2, [r1] @ =REG_WAVE_RAM3_L = *pSample++
    @ Set REG_SOUND3CNT_L wave ram bank = 0
    movs r2, #0
    strb r2, [r3]
    bx lr
    .align 2, 0
lbl_080050fc: .4byte REG_SOUND3CNT_L
lbl_08005100: .4byte REG_WAVE_RAM0_L

@ Signature: void UploadSoundDataToSoundChannelRam(struct PSGSoundData* pSound)
    thumb_func_start UploadSoundDataToSoundChannelRam
UploadSoundDataToSoundChannelRam: @ 0x08005104
    push {r4, r5}
    ldr r4, [r0, o_PSGSoundData_nrx0]
    ldrh r5, [r0, o_PSGSoundData_nrx3_nrx4]
    ldr r1, [r0, o_PSGSoundData_pVariables]
    movs r2, o_TrackVariables_channel
    ldrb r1, [r1, r2]
    cmp r1, #8
    ble UploadSoundDataToSoundChannelRam_skip_frequency_control_adjustment
    @ r2 = &REG_SOUNDBIAS + 1
    movs r2, #4
    movs r3, #0x89
    lsls r2, r2, #0x18
    orrs r2, r3
    @ r2 = amp res/sample cycle bits
    ldrb r2, [r2]
    lsrs r2, r2, #6
    lsls r2, r2, #6
    movs r3, #0x40
    cmp r2, r3
    bge UploadSoundDataToSoundChannelRam_check_next_sample_rate
    @ Adjust by 2 if lowest sample cycle
    adds r5, #2
    b UploadSoundDataToSoundChannelRam_frequency_control_adjustment
UploadSoundDataToSoundChannelRam_check_next_sample_rate:
    movs r3, #0x80
    cmp r2, r3
    bge UploadSoundDataToSoundChannelRam_skip_frequency_control_adjustment
    @ Adjust by 1 if second lowest sample cycle
    adds r5, #1
UploadSoundDataToSoundChannelRam_frequency_control_adjustment:
    @ r5 = r5 & 0xC7FE
    movs r2, #0xc7
    movs r3, #0xfe
    lsls r2, r2, #8
    orrs r2, r3
    ands r5, r2
UploadSoundDataToSoundChannelRam_skip_frequency_control_adjustment:
    @ r2 = &REG_SOUND1CNT_L
    movs r2, #4
    movs r3, #0x60
    lsls r2, r2, #0x18
    orrs r2, r3
    @ r1 = pSound->pVariables->channel & 7
    movs r3, #7
    ands r1, r3
    @ r3 = C_16_2_8(pSound->nrx2, pSound->nrx1)
    lsls r3, r4, #8
    lsrs r3, r3, #0x10
    cmp r1, #1
    beq UploadSoundDataToSoundChannelRam_write_channel1
    cmp r1, #2
    beq UploadSoundDataToSoundChannelRam_write_channel2
    cmp r1, #3
    beq UploadSoundDataToSoundChannelRam_write_channel3
    cmp r1, #4
    beq UploadSoundDataToSoundChannelRam_write_channel4
    b UploadSoundDataToSoundChannelRam_exit
UploadSoundDataToSoundChannelRam_write_channel1:
    strb r4, [r2, #0] @ REG_SOUND1CNT_L = pSound->nrx0
    strh r3, [r2, #2] @ REG_SOUND1CNT_H = C_16_2_8(pSound->nrx2, pSound->nrx1)
    strh r5, [r2, #4] @ REG_SOUND1CNT_X = pSound->nrx3_nrx4 (modified)
    nop
    nop
    nop
    nop
    strh r5, [r2, #4] @ REG_SOUND1CNT_X = pSound->nrx3_nrx4 (modified)
    b UploadSoundDataToSoundChannelRam_exit
UploadSoundDataToSoundChannelRam_write_channel2:
    strh r3, [r2, #8] @ REG_SOUND2CNT_L = C_16_2_8(pSound->nrx2, pSound->nrx1)
    strh r5, [r2, #0xc] @ REG_SOUND2CNT_H = pSound->nrx3_nrx4 (modified)
    b UploadSoundDataToSoundChannelRam_exit
UploadSoundDataToSoundChannelRam_write_channel3:
    strb r4, [r2, #0x10] @ REG_SOUND3CNT_L = pSound->nrx0
    strh r3, [r2, #0x12] @ REG_SOUND3CNT_H = C_16_2_8(pSound->nrx2, pSound->nrx1)
    strh r5, [r2, #0x14] @ REG_SOUND3CNT_X = pSound->nrx3_nrx4 (modified)
    b UploadSoundDataToSoundChannelRam_exit
UploadSoundDataToSoundChannelRam_write_channel4:
    strh r3, [r2, #0x18] @ REG_SOUND4CNT_L = C_16_2_8(pSound->nrx2, pSound->nrx1)
    strh r5, [r2, #0x1c] @ REG_SOUND4CNT_H = pSound->nrx3_nrx4 (modified)
UploadSoundDataToSoundChannelRam_exit:
    @ Clear bit 15 (restart sound bit flag) of sound channel frequency/control
    lsls r5, r5, #0x11
    lsrs r5, r5, #0x11
    strh r5, [r0, o_PSGSoundData_nrx3_nrx4]
    pop {r4, r5}
    bx lr
    .align 2, 0
