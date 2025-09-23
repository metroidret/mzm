#ifndef AUDIO_INTERNAL_CONSTANTS_INC
#define AUDIO_INTERNAL_CONSTANTS_INC

    .equiv MPT_FLG_VOLSET, 0x01
    .equiv MPT_FLG_VOLCHG, 0x03
    .equiv MPT_FLG_PITSET, 0x04
    .equiv MPT_FLG_PITCHG, 0x0C
    .equiv MPT_FLG_START,  0x40
    .equiv MPT_FLG_EXIST,  0x80

    .macro struct_begin
    .struct 0
    .endm

    .macro struct_field name, size
\name:
    .struct \name + \size
    .endm

    struct_begin
    struct_field o_MusicTrackInfo_currentRoomTrack, 2
    struct_field o_MusicTrackInfo_pauseScreenFlag, 1
    struct_field o_MusicTrackInfo_takingNormalTransition, 1
    struct_field o_MusicTrackInfo_unk, 1

    struct_begin
    struct_field o_Envelope_attack, 1
    struct_field o_Envelope_decay, 1
    struct_field o_Envelope_sustain, 1
    struct_field o_Envelope_release, 1

    struct_begin
    struct_field o_Voice_instrumentType, 1
    struct_field o_Voice_pitch, 1
    struct_field o_Voice_unk_2, 1
    struct_field o_Voice_unk_3, 1
    struct_field o_Voice_pSample, 4
    struct_field o_Voice_envelope, 4

    struct_begin
    struct_field o_SoundQueue_exists, 1
    struct_field o_SoundQueue_priority, 1
    struct_field o_SoundQueue_fadingTimer, 2
    struct_field o_SoundQueue_pHeader, 4

    struct_begin
    struct_field o_SoundChannel_envelopeStage_maybe, 1
    struct_field o_SoundChannel_unk_1, 1
    struct_field o_SoundChannel_unk_2, 1
    struct_field o_SoundChannel_unk_3, 1
    struct_field o_SoundChannel_rightVol_maybe, 1
    struct_field o_SoundChannel_leftVol_maybe, 1
    struct_field o_SoundChannel_unk_6, 1
    struct_field o_SoundChannel_unk_7, 1
    struct_field o_SoundChannel_envelope, 4
    struct_field o_SoundChannel_echoVol_maybe, 1
    struct_field o_SoundChannel_echoLen_maybe, 1
    struct_field o_SoundChannel_gateTime_maybe, 1
    struct_field o_SoundChannel_velocity_maybe, 1
    struct_field o_SoundChannel_envelopeVol_maybe, 1
    struct_field o_SoundChannel_envelopeVolR_maybe, 1
    struct_field o_SoundChannel_envelopeVolL_maybe, 1
    struct_field o_SoundChannel_volumeUpdateFlag_maybe, 1
    struct_field o_SoundChannel_pSize, 4
    struct_field o_SoundChannel_unk_18, 4
    struct_field o_SoundChannel_unk_1C, 4
    struct_field o_SoundChannel_pSample, 4
    struct_field o_SoundChannel_pData, 4
    struct_field o_SoundChannel_pVariables, 4
    struct_field o_SoundChannel_pChannelPrev_maybe, 4
    struct_field o_SoundChannel_pChannelNext_maybe, 4

    struct_begin
    struct_field o_SoundChannelBackup_pChannel, 4
    struct_field o_SoundChannelBackup_channel, 80

    struct_begin
    struct_field o_PSGSoundData_unk_0, 1
    struct_field o_PSGSoundData_unk_1, 1
    struct_field o_PSGSoundData_rightVol_maybe, 1
    struct_field o_PSGSoundData_leftVol_maybe, 1
    struct_field o_PSGSoundData_envelope, 4
    struct_field o_PSGSoundData_maybe_noteDelay, 2
    struct_field o_PSGSoundData_velocity_maybe, 1
    struct_field o_PSGSoundData_unk_B, 1
    struct_field o_PSGSoundData_unk_C, 1
    struct_field o_PSGSoundData_echoVol_maybe, 1
    struct_field o_PSGSoundData_echoLen_maybe, 1
    struct_field o_PSGSoundData_unk_F, 1
    struct_field o_PSGSoundData_nrx0, 1
    struct_field o_PSGSoundData_nrx1, 1
    struct_field o_PSGSoundData_nrx2, 1
    struct_field o_PSGSoundData_undefined_13, 1
    struct_field o_PSGSoundData_nrx3_nrx4, 2
    struct_field o_PSGSoundData_unk_16, 1
    struct_field o_PSGSoundData_unk_17, 1
    struct_field o_PSGSoundData_cgb_envelopeCtr_maybe, 1
    struct_field o_PSGSoundData_cgb_envelopeVol_maybe, 1
    struct_field o_PSGSoundData_cgb_envelopeGoal_maybe, 1
    struct_field o_PSGSoundData_cgb_sustainGoal_maybe, 1
    struct_field o_PSGSoundData_unk_1C, 1
    struct_field o_PSGSoundData_unk_1D, 1
    struct_field o_PSGSoundData_unk_1E, 1
    struct_field o_PSGSoundData_unk_1F, 1
    struct_field o_PSGSoundData_pSample, 4
    struct_field o_PSGSoundData_pVariables, 4

    struct_begin
    struct_field o_TrackVariables_unk_0, 1
    struct_field o_TrackVariables_key_maybe, 1
    struct_field o_TrackVariables_delay, 1
    struct_field o_TrackVariables_currentEvent, 1
    struct_field o_TrackVariables_volume, 1
    struct_field o_TrackVariables_volumeX_maybe, 1
    struct_field o_TrackVariables_pan_maybe, 1
    struct_field o_TrackVariables_panX_maybe, 1
    struct_field o_TrackVariables_volRightCalculated_maybe, 1
    struct_field o_TrackVariables_volLeftCalculated_maybe, 1
    struct_field o_TrackVariables_repeatCount, 1
    struct_field o_TrackVariables_priority, 1
    struct_field o_TrackVariables_echoVolume_maybe, 1
    struct_field o_TrackVariables_echoLength_maybe, 1
    struct_field o_TrackVariables_gateTime_maybe, 1
    struct_field o_TrackVariables_velocity_maybe, 1
    struct_field o_TrackVariables_lfoSpeed, 1
    struct_field o_TrackVariables_modulationDepth, 1
    struct_field o_TrackVariables_modulationType, 1
    struct_field o_TrackVariables_modulationCalculated_maybe, 1
    struct_field o_TrackVariables_lfoDelay_maybe, 1
    struct_field o_TrackVariables_lfoDelayCounter_maybe, 1
    struct_field o_TrackVariables_lfoSpeedC_maybe, 1
    struct_field o_TrackVariables_keyShiftCalculated_maybe, 1
    struct_field o_TrackVariables_pitchCalculated_maybe, 1
    struct_field o_TrackVariables_pitchBend, 1
    struct_field o_TrackVariables_bendRange, 1
    struct_field o_TrackVariables_unk_1B, 1
    struct_field o_TrackVariables_keyShift, 1
    struct_field o_TrackVariables_keyShiftX_maybe, 1
    struct_field o_TrackVariables_tune, 1
    struct_field o_TrackVariables_pitchX_maybe, 1
    struct_field o_TrackVariables_unk_20, 4
    struct_field o_TrackVariables_pRawData, 4
    struct_field o_TrackVariables_patternStartPointers, 12
    struct_field o_TrackVariables_channel, 1
    struct_field o_TrackVariables_unk_35, 1
    struct_field o_TrackVariables_unk_36, 1
    struct_field o_TrackVariables_unk_37, 1
    struct_field o_TrackVariables_pSample1, 4
    struct_field o_TrackVariables_envelope1, 4
    struct_field o_TrackVariables_pSample2, 4
    struct_field o_TrackVariables_envelope2, 4
    struct_field o_TrackVariables_pChannel, 4
    struct_field o_TrackVariables_pSoundPSG, 4
    struct_field o_TrackVariables_size, 0

    struct_begin
    struct_field o_TrackData_flags, 1
    struct_field o_TrackData_amountOfTracks, 1
    struct_field o_TrackData_undefined_2, 1
    struct_field o_TrackData_trackHeaderPriority, 1
    struct_field o_TrackData_currentTrack, 1
    struct_field o_TrackData_maxAmountOfTracks, 1
    struct_field o_TrackData_maybe_volume, 2
    struct_field o_TrackData_fadingTimer, 2
    struct_field o_TrackData_tempoRawBpm_maybe, 2
    struct_field o_TrackData_tempoInterval_maybe, 2
    struct_field o_TrackData_tempoCounter_maybe, 2
    struct_field o_TrackData_pHeader, 4
    struct_field o_TrackData_pVoice, 4
    struct_field o_TrackData_pVariables, 4
    struct_field o_TrackData_occupied, 1
    struct_field o_TrackData_unk_1D, 1
    struct_field o_TrackData_unk_1E, 1
    struct_field o_TrackData_priority, 1
    struct_field o_TrackData_musicTrack, 2
    struct_field o_TrackData_maxSoundChannels, 1
    struct_field o_TrackData_unk_23, 1
    struct_field o_TrackData_unk_24, 2
    struct_field o_TrackData_unk_26, 2
    struct_field o_TrackData_queueFlags, 1
    struct_field o_TrackData_undefined_29, 1
    struct_field o_TrackData_undefined_2A, 1
    struct_field o_TrackData_undefined_2B, 1
    struct_field o_TrackData_undefined_2C, 1
    struct_field o_TrackData_undefined_2D, 1
    struct_field o_TrackData_undefined_2E, 1
    struct_field o_TrackData_undefined_2F, 1
    struct_field o_TrackData_undefined_30, 1
    struct_field o_TrackData_undefined_31, 1
    struct_field o_TrackData_undefined_32, 1
    struct_field o_TrackData_unk_33, 1
    struct_field o_TrackData_unk_34, 1
    struct_field o_TrackData_unk_35, 1
    struct_field o_TrackData_undefined_36, 1
    struct_field o_TrackData_undefined_37, 1
    struct_field o_TrackData_undefined_38, 1
    struct_field o_TrackData_undefined_39, 1
    struct_field o_TrackData_undefined_3A, 1
    struct_field o_TrackData_undefined_3B, 1
    struct_field o_TrackData_undefined_3C, 1
    struct_field o_TrackData_undefined_3D, 1
    struct_field o_TrackData_undefined_3E, 1
    struct_field o_TrackData_undefined_3F, 1

    struct_begin
    struct_field o_TrackGroupROMData_pTrack, 4
    struct_field o_TrackGroupROMData_pVariables, 4
    struct_field o_TrackGroupROMData_maxAmountOfTracks, 2
    struct_field o_TrackGroupROMData_unk_A, 2

    struct_begin
    struct_field o_SoundEntry_pHeader, 4
    struct_field o_SoundEntry_trackGroundNumber, 2
    struct_field o_SoundEntry_trackGroundNumber_2, 2

    struct_begin
    struct_field o_MusicInfo_unk_0, 1
    struct_field o_MusicInfo_occupied, 1
    struct_field o_MusicInfo_unk_2, 1
    struct_field o_MusicInfo_unk_3, 1
    struct_field o_MusicInfo_reverb, 1
    struct_field o_MusicInfo_maxSoundChannels, 1
    struct_field o_MusicInfo_volume, 1
    struct_field o_MusicInfo_freqIndex, 1
    struct_field o_MusicInfo_unk_8, 1
    struct_field o_maxScanlines_maybe, 1
    struct_field o_MusicInfo_currentSoundChannel, 1
    struct_field o_MusicInfo_volumeDownFlag, 1
    struct_field o_MusicInfo_unk_C, 1
    struct_field o_MusicInfo_unk_D, 1
    struct_field o_MusicInfo_maxDmaCount_maybe, 1
    struct_field o_MusicInfo_unk_F, 1
    struct_field o_MusicInfo_dmaCounter_maybe, 1
    struct_field o_MusicInfo_unk_11, 1
    struct_field o_MusicInfo_sampleRate, 2
    struct_field o_MusicInfo_unk_14, 4
    struct_field o_MusicInfo_pitch, 4
    struct_field o_MusicInfo_musicTrack, 2
    struct_field o_MusicInfo_unk_1E, 2
    struct_field o_MusicInfo_unk_20, 1
    struct_field o_MusicInfo_priority, 1
    struct_field o_MusicInfo_musicTrackOnTransition, 2
    struct_field o_MusicInfo_musicRawData, 3072
    struct_field o_MusicInfo_soundRawData, 3072
    struct_field o_MusicInfo_soundChannels, 880

#endif @ AUDIO_INTERNAL_CONSTANTS_INC
