#include "audio.h"
#include "macros.h"
#include "gba.h"
#include "syscalls.h"
#include "audio/track_internal.h"

#include "data/audio.h"

#include "constants/audio_engine.h"

static void unk_1bf0(struct TrackVariables* pVariables);
static void unk_1c18(struct TrackVariables* pVariables);
static void unk_1c3c(struct TrackVariables* pVariables);
static void unk_1ccc(struct TrackVariables* pVariables, s16 param_2);
static void unk_1d5c(struct TrackVariables* pVariables);
static void unk_1d78(struct TrackVariables* pVariables);
static void unk_1ddc(struct TrackVariables* pVariables);
static void unk_1de8(struct TrackVariables* pVariables);
static void unk_1e2c(struct TrackData* pTrack, struct TrackVariables* pVariables);
static void unk_1f3c(struct TrackData* pTrack, struct TrackVariables* pVariables);
static void unk_1f90(struct TrackData* pTrack, struct TrackVariables* pVariables);
static void unk_1fe0(struct TrackData* pTrack, struct TrackVariables* pVariables);
static void unk_2030(struct PSGSoundData* pSound, struct TrackVariables* pVariables, u32 param_3);

static u16 GetNoteDelay(struct TrackVariables* pVariables, u8 param_2, u8 param_3);

/**
 * @brief 10c4 | 394 | To document
 * 
 */
void UpdateMusic(void)
{
    u32 maxScanlines;
    s16 envelope;
    s16 var_2;
    u8 var_3;
    u16 var_4;
    u32 envelopeStage;
    u8 var_6;
    u8 var_7;
    u8 dmaCounter;
    u8* buffer;
    u8* buffer2;
    u32 vcount;
    u16 i;
    struct SoundChannel* pChannel;
    struct TrackVariables* pVariables;
    u32 *tmp;
    u32 tmp2;
    u32 tmp3;

    maxScanlines = tmp3 = gMusicInfo.maxScanlines_maybe;
    if (maxScanlines != 0)
    {
        vcount = READ_8(REG_VCOUNT);
        if (vcount < SCREEN_SIZE_Y)
            vcount += VERTICAL_LINE_COUNT;

        // Written this way to produce matching asm
        tmp3 = vcount;
        maxScanlines = vcount;
        tmp3 = gMusicInfo.maxScanlines_maybe;
        maxScanlines = vcount + gMusicInfo.maxScanlines_maybe;
    }

    dmaCounter = gMusicInfo.dmaCounter_maybe;
    var_4 = gMusicInfo.unk_11 * 16;
    var_7 = MUL_SHIFT(gMusicInfo.unk_C, 2) + dmaCounter - 1;
    if (var_7 >= gMusicInfo.maxDmaCount_maybe)
        var_7 -= gMusicInfo.maxDmaCount_maybe;

    var_3 = 0;
    if (dmaCounter <= var_7 && var_7 <= gMusicInfo.unk_11)
    {
        var_4 = (var_7 - gMusicInfo.unk_C + 1) * 16;
        var_6 = gMusicInfo.unk_C;
        if (var_7 + 1 == gMusicInfo.maxDmaCount_maybe)
            gMusicInfo.unk_11 = 0;
        else
            gMusicInfo.unk_11 = var_7 + 1;
    }
    else if (gMusicInfo.unk_11 <= dmaCounter && dmaCounter <= var_7)
    {
        var_4 = (var_7 - gMusicInfo.unk_C + 1) * 16;
        var_6 = gMusicInfo.unk_C;
        if (var_7 + 1 == gMusicInfo.maxDmaCount_maybe)
            gMusicInfo.unk_11 = 0;
        else
            gMusicInfo.unk_11 = var_7 + 1;
    }
    else if (var_7 <= gMusicInfo.unk_11 && gMusicInfo.unk_11 <= dmaCounter)
    {
        var_4 = 0;
        var_6 = var_7 + 1;
        gMusicInfo.unk_11 = var_6;
    }
    else if (gMusicInfo.unk_11 < var_7)
    {
        var_6 = (var_7 - gMusicInfo.unk_11) + 1;
        if (var_7 + 1 == gMusicInfo.maxDmaCount_maybe)
            gMusicInfo.unk_11 = 0;
        else
            gMusicInfo.unk_11 = var_7 + 1;
    }
    else if (gMusicInfo.unk_11 > var_7)
    {
        var_6 = gMusicInfo.maxDmaCount_maybe - gMusicInfo.unk_11;
        var_3 = var_7 + 1;
        gMusicInfo.unk_11 = var_3;
    }
    else
    {
        var_4 = 0;
        var_6 = var_7 + 1;
        gMusicInfo.unk_11 = var_6;
    }


    if (var_6 == 0)
        return;

    buffer2 = &gMusicInfo.soundRawData[var_4];
    tmp = gMusicInfo.musicRawData;
    buffer = gSoundCodeBPointer((u32*)buffer2, (u32*)buffer2, tmp, var_6 * 8);
    if (var_3 != 0)
    {
        buffer2 = gMusicInfo.soundRawData;
        gSoundCodeBPointer((u32*)buffer2, (u32*)buffer2, (u32*)buffer, var_3 * 8);
    }

    gMusicInfo.currentSoundChannel = 0;
    for (i = 0; i < gMusicInfo.maxSoundChannels; i++)
    {
        if (maxScanlines != 0)
        {
            vcount = READ_8(REG_VCOUNT);
            if (vcount < SCREEN_SIZE_Y)
                vcount += VERTICAL_LINE_COUNT;

            if (vcount >= maxScanlines)
                break;
        }

        pChannel = &gMusicInfo.soundChannels[i];
        if (pChannel->envelopeStage_maybe == 0)
            continue;

        gMusicInfo.currentSoundChannel++;
        pVariables = pChannel->pVariables;

        while (pChannel->volumeUpdateFlag_maybe != 0)
        {
            if (pChannel->volumeUpdateFlag_maybe & VOLUME_UPDATE_FLAG_RESET)
            {
                if (pChannel->unk_1 == 0x20)
                    pChannel->unk_18 = pChannel->pSample[3] << 14;
                else
                    pChannel->unk_18 = 0;

                pChannel->envelopeVol_maybe = 0;
                pChannel->volumeUpdateFlag_maybe &= ~VOLUME_UPDATE_FLAG_RESET;
                pChannel->volumeUpdateFlag_maybe |= VOLUME_UPDATE_FLAG_UPDATE;
            }
            else if (pChannel->volumeUpdateFlag_maybe & VOLUME_UPDATE_FLAG_NOTHING)
            {
                pChannel->volumeUpdateFlag_maybe &= ~VOLUME_UPDATE_FLAG_NOTHING;
            }
            else if (pChannel->volumeUpdateFlag_maybe & VOLUME_UPDATE_FLAG_UPDATE)
            {
                if (pVariables->unk_0 & 0x80)
                {
                    pVariables->pan_maybe = pChannel->unk_3;
                    TrackUpdateVolume(pVariables);
                }

                // ChnVolSetAsm
                pChannel->rightVol_maybe = (pVariables->volRightCalculated_maybe * (pChannel->velocity_maybe + 1)) >> 7;
                pChannel->leftVol_maybe = (pVariables->volLeftCalculated_maybe * (pChannel->velocity_maybe + 1)) >> 7;

                pChannel->volumeUpdateFlag_maybe &= ~VOLUME_UPDATE_FLAG_UPDATE;
            }
        }

        envelope = pChannel->envelopeVol_maybe;
        envelopeStage = pChannel->envelopeStage_maybe & 0xF;

        switch (envelopeStage)
        {
            case 10:
                pChannel->envelopeStage_maybe = 0;
                continue;
        }
        
        switch (envelopeStage)
        {
            case 1:
                if (pChannel->envelope.attack != UCHAR_MAX)
                {
                    goto lbl_1;
                }
                else
                {
                    goto lbl_3;
                }
        }

        switch (envelopeStage)
        {
            case 2:
                goto lbl_2;

                lbl_1:
                envelope = 0;
                pChannel->envelopeStage_maybe = 2;

                lbl_2:
                envelope += pChannel->envelope.attack;
                if (envelope < UCHAR_MAX)
                    break;

                lbl_3:
                tmp2 = pChannel->envelope.decay;
                dmaCounter = pChannel->envelope.sustain;
                if (tmp2 != 0)
                {
                    envelope = UCHAR_MAX;
                    pChannel->envelopeStage_maybe = 3;
                }
                else
                {
                    envelope = pChannel->envelope.sustain;
                    pChannel->envelopeStage_maybe = 4;
                    break;
                }

            case 3:
                if ((envelope = (envelope * pChannel->envelope.decay) >> 8) > (dmaCounter = pChannel->envelope.sustain))
                    break;

                if (pChannel->envelope.sustain != 0)
                {
                    envelope = pChannel->envelope.sustain;
                    pChannel->envelopeStage_maybe = 4;
                    break;
                }

            case 5:
                pChannel->envelopeStage_maybe = 6;

            case 6:
                if ((envelope = (envelope * pChannel->envelope.release) >> 8) > 0)
                    break;

                pChannel->envelopeStage_maybe = 0;
                if (pChannel->echoVol_maybe != 0 && pChannel->echoLen_maybe != 0)
                    pChannel->envelopeStage_maybe = 8;
                else
                    FreeSoundChannel(pChannel);
                continue;

            case 8:
                pChannel->echoLen_maybe--;
                if (pChannel->echoLen_maybe == 0)
                {
                    pChannel->envelopeStage_maybe = 0;
                    FreeSoundChannel(pChannel);
                }
                break;
        }

        pChannel->envelopeVol_maybe = envelope;
        var_2 = DIV_SHIFT(envelope * (gMusicInfo.volume + 1), 16);
        pChannel->envelopeVolR_maybe = DIV_SHIFT(var_2 * pChannel->rightVol_maybe, 256);
        pChannel->envelopeVolL_maybe = DIV_SHIFT(var_2 * pChannel->leftVol_maybe, 256);

        tmp = gMusicInfo.musicRawData;
        gSoundCodeAPointer(pChannel, tmp, (var_6 + var_3) * 4);
    }

    buffer2 = &gMusicInfo.soundRawData[var_4];
    tmp = gMusicInfo.musicRawData;
    buffer = gSoundCodeCPointer((u32*)buffer2, tmp, var_6 * 4);
    if (var_3 != 0)
    {
        buffer2 = gMusicInfo.soundRawData;
        gSoundCodeCPointer((u32*)buffer2, (u32*)buffer, var_3 * 4);
    }
}

/**
 * @brief 1458 | 3f8 | To document
 * 
 */
void UpdatePsgSounds(void)
{
    s16 var_0;
    u8 control;
    u8 i;
    struct PSGSoundData* pSound;
    struct TrackVariables* pVariables;
    u32 tmp;

    var_0 = FALSE;

    for (i = 0; i < ARRAY_SIZE(gPsgSounds); i++)
    {
        pSound = &gPsgSounds[i];

        if (pSound->unk_0 == 0)
            continue;

        while (pSound->unk_F)
        {
            if (pSound->unk_F & 0x2)
            {
                pVariables = pSound->pVariables;

                pSound->velocity_maybe = pVariables->velocity_maybe;
                pSound->unk_B = pVariables->volume;
                pSound->echoVol_maybe = pVariables->echoVolume_maybe;
                pSound->echoLen_maybe = pVariables->echoLength_maybe;
                pSound->unk_1D = pVariables->unk_36;
                pSound->unk_1E = pVariables->unk_37;
                
                pSound->pSample = pVariables->pSample1;
                pSound->envelope.attack = pVariables->envelope1.attack;
                pSound->envelope.decay = pVariables->envelope1.decay;
                pSound->envelope.sustain = pVariables->envelope1.sustain;
                pSound->envelope.release = pVariables->envelope1.release;

                pSound->unk_1F = pVariables->modulationType;

                pSound->unk_F &= ~0x2;
                pSound->unk_F |= 0x10;
                continue;
            }

            if (pSound->unk_F & 0x4)
            {
                pSound->nrx3_nrx4 = pSound->maybe_noteDelay;

                UploadSoundDataToSoundChannelRam(pSound);

                pSound->unk_F &= ~0x4;
                continue;
            }

            if (pSound->unk_F & 0x10)
            {
                if (pSound->pVariables->pan_maybe != pSound->unk_C)
                {
                    pSound->pVariables->pan_maybe = pSound->unk_C;
                    TrackUpdateVolume(pSound->pVariables);
                }

                // ChnVolSetAsm
                pSound->rightVol_maybe = (pSound->pVariables->volRightCalculated_maybe * (pSound->velocity_maybe + 1)) >> 7;
                pSound->leftVol_maybe = (pSound->pVariables->volLeftCalculated_maybe * (pSound->velocity_maybe + 1)) >> 7;

                // CgbModVal
                pSound->cgb_envelopeGoal_maybe = (pSound->rightVol_maybe + pSound->leftVol_maybe) >> 4;
                pSound->cgb_sustainGoal_maybe = (pSound->cgb_envelopeGoal_maybe * pSound->envelope.sustain + 15) >> 4;

                // CgbSound apply envelope & volume to HW registers
                control = READ_8(REG_SOUNDCNT_L + 1) & ~(0x11 << i);

                if (pSound->rightVol_maybe >= pSound->leftVol_maybe)
                {
                    if ((pSound->rightVol_maybe >> 1) > pSound->leftVol_maybe)
                    {
                        WRITE_8(REG_SOUNDCNT_L + 1, control | (0x01 << i));
                    }
                    else
                    {
                        WRITE_8(REG_SOUNDCNT_L + 1, control | (0x11 << i));
                    }
                }
                else
                {
                    if ((pSound->leftVol_maybe >> 1) > pSound->rightVol_maybe)
                    {
                        WRITE_8(REG_SOUNDCNT_L + 1, control | (0x10 << i));
                    }
                    else
                    {
                        WRITE_8(REG_SOUNDCNT_L + 1, control | (0x11 << i));
                    }
                }

                pSound->nrx2 = 0;
                pSound->nrx3_nrx4 |= SOUNDCNT_RESTART_SOUND;

                var_0 = TRUE;

                pSound->unk_F &= ~0x10;
                continue;
            }

            if (pSound->unk_F & 0x20)
            {
                pSound->nrx3_nrx4 = pSound->maybe_noteDelay | SOUNDCNT_RESTART_SOUND;

                UploadSoundDataToSoundChannelRam(pSound);

                pSound->unk_F &= ~0x20;
            }
        }

        control = pSound->unk_0 & 0xF;

        switch (control)
        {
            case 10:
                ClearRegistersForPsg(pSound, i);
                continue;
        }

        switch (control)
        {
            case 1:
                if (i == 0)
                {
                    pSound->nrx0 = pSound->unk_1E;
                }
                else if (i == 2)
                {
                    pSound->nrx0 = 0x80;
                }

                if (i < 2)
                    pSound->nrx1 = (u8)(u32)pSound->pSample;
                else
                    pSound->nrx1 = 0;

                pSound->nrx3_nrx4 = pSound->maybe_noteDelay;
                pSound->nrx3_nrx4 |= SOUNDCNT_RESTART_SOUND;

                if (pSound->unk_1D != 0)
                {
                    goto lbl_pre_case_9;
                }

                if (pSound->envelope.attack != 0)
                {
                    goto lbl_pre_case_2;
                }
                else
                {
                    if (pSound->envelope.decay == 0)
                    {
                        goto lbl_1;
                    }
                    else
                    {
                        goto lbl_2;
                    }
                }
                break;
        }

        if (pSound->cgb_envelopeCtr_maybe == 0)
        {
            switch (control)
            {
                case 2:
                    goto lbl_case_2;

                    lbl_pre_case_2:
                    pSound->cgb_envelopeVol_maybe = 0;
                    if (i == 2)
                        pSound->nrx2 = 0;
                    else
                        pSound->nrx2 = pSound->envelope.attack + 8;

                    pSound->unk_0 = 2;
                    UploadSoundDataToSoundChannelRam(pSound);

                    lbl_case_2:
                    if (++pSound->cgb_envelopeVol_maybe >= pSound->cgb_envelopeGoal_maybe)
                    {
                        lbl_3:
                        if (pSound->envelope.decay == 0)
                        {
                            goto lbl_1;
                        }
                        else
                        {
                            goto lbl_2;
                        }
                    }
                    else
                    {
                        if (i == 2)
                        {
                            pSound->nrx2 = 0;
                            var_0 = TRUE;
                        }
    
                        pSound->cgb_envelopeCtr_maybe = pSound->envelope.attack;
                        break;
                    }
                    

                case 3:
                    goto lbl_case_3;
                    
                    lbl_2:
                    pSound->cgb_envelopeVol_maybe = pSound->cgb_envelopeGoal_maybe;
                    if (i == 2)
                    {
                        pSound->nrx2 = 0;
                    }
                    else
                    {
                        pSound->nrx2 = pSound->envelope.decay;
                        pSound->nrx3_nrx4 = pSound->maybe_noteDelay | SOUNDCNT_RESTART_SOUND;
                    }

                    pSound->unk_0 = 3;
                    var_0 = TRUE;

                    lbl_case_3:
                    if (--pSound->cgb_envelopeVol_maybe > pSound->cgb_sustainGoal_maybe)
                    {
                        if (i == 2)
                        {
                            pSound->nrx2 = 0;
                            var_0 = TRUE;
                        }

                        pSound->cgb_envelopeCtr_maybe = pSound->envelope.decay;
                        break;
                    }

                    lbl_1:
                    pSound->cgb_envelopeVol_maybe = pSound->cgb_sustainGoal_maybe;

                    if (i == 2)
                    {
                        pSound->nrx2 = 0;
                    }
                    else
                    {
                        pSound->nrx2 = 0;
                        pSound->nrx3_nrx4 = pSound->maybe_noteDelay | SOUNDCNT_RESTART_SOUND;
                    }
                    
                    pSound->unk_0 = 4;
                    var_0 = TRUE;

                case 4:
                    pSound->cgb_envelopeVol_maybe = pSound->cgb_sustainGoal_maybe;
                    
                    if ((pSound->unk_0 & 0xF) == 4)
                        pSound->cgb_envelopeCtr_maybe = 1;
                    break;

                case 5:
                    if (pSound->envelope.release != 0 && pSound->unk_1D == 0)
                    {
                        if (i != 2)
                        {
                            pSound->nrx2 = pSound->envelope.release;
                            pSound->nrx3_nrx4 = pSound->maybe_noteDelay | SOUNDCNT_RESTART_SOUND;
                        }

                        pSound->unk_0 = 6;
                        var_0 = TRUE;
                    }
                    else
                    {
                        goto lbl_0;
                    }

                case 6:
                    pSound->cgb_envelopeVol_maybe--;
                    if (pSound->cgb_envelopeVol_maybe > 0)
                    {
                        if (i == 2)
                        {
                            pSound->nrx2 = 0;
                            var_0 = TRUE;
                        }

                        pSound->cgb_envelopeCtr_maybe = pSound->envelope.release;
                        break;
                    }

                    lbl_0:
                    pSound->unk_0 = 0;

                    if (pSound->echoVol_maybe != 0 && pSound->echoLen_maybe != 0)
                    {
                        pSound->cgb_envelopeVol_maybe = (pSound->cgb_envelopeGoal_maybe * pSound->echoVol_maybe + 0xFF) >> 8;
                        pSound->cgb_envelopeCtr_maybe = pSound->echoLen_maybe;

                        if (i == 2)
                        {
                            pSound->nrx2 = sCgb3Vol[pSound->cgb_envelopeVol_maybe];
                        }
                        else
                        {
                            pSound->nrx2 = 0;
                            pSound->nrx3_nrx4 = pSound->maybe_noteDelay | SOUNDCNT_RESTART_SOUND;
                        }

                        pSound->unk_0 = 8;
                        var_0 = TRUE;
                    }
                    else
                    {
                        ClearRegistersForPsg(pSound, i);
                        continue;
                    }
                    break;

                case 8:
                    if (pSound->cgb_envelopeCtr_maybe == 0)
                    {
                        ClearRegistersForPsg(pSound, i);
                        pSound->unk_0 = 0;
                    }
                    continue;

                case 9:
                    goto lbl_case_9;

                    lbl_pre_case_9:
                    pSound->nrx1 |= pSound->unk_1D;
                    pSound->nrx2 = 0;
                    pSound->cgb_envelopeVol_maybe = pSound->cgb_sustainGoal_maybe;
                    pSound->nrx3_nrx4 |= SOUNDCNT_LENGTH_STOPS_SOUND;
                    pSound->unk_0 = 9;

                    var_0 = TRUE;

                    lbl_case_9:
                    pSound->cgb_envelopeCtr_maybe = UCHAR_MAX;
                    if (var_0)
                    {
                        pSound->nrx3_nrx4 |= SOUNDCNT_LENGTH_STOPS_SOUND;
                    }
                    break;
            }
        }

        if (var_0)
        {
            var_0 = FALSE;
            control = (u8)pSound->cgb_envelopeVol_maybe;

            if (i == 2)
                pSound->nrx2 = sCgb3Vol[control];
            else
                pSound->nrx2 |= control << 4;

            UploadSoundDataToSoundChannelRam(pSound);
        }

        pSound->cgb_envelopeCtr_maybe--;
    }
}

/**
 * @brief 1850 | 3a0 | Updates a track data
 * 
 * @param pTrack Track data pointer
 */
void UpdateTrack(struct TrackData* pTrack)
{
    u8 i;
    struct TrackVariables* pVariables;
    u8 event;
    u8 tempo;
    s16 var_2;

    if (pTrack->occupied)
        return;

    pTrack->occupied = TRUE;

    if (!(pTrack->unk_1E & TRUE))
    {
        if (pTrack->flags & 0xF8)
        {
            if (pTrack->flags & 0x98)
                unk_2d2c(pTrack);
            else
                unk_2e6c(pTrack);
        }

        if (pTrack->flags & 0x2)
        {
            for (tempo = TrackUpdateTempo(pTrack); tempo != 0; tempo--)
            {
                for (i = 0, pVariables = pTrack->pVariables; i < pTrack->amountOfTracks; i++, pVariables++)
                {
                    if (pVariables->unk_0 == 0)
                        continue;

                    if (pVariables->pChannel != NULL)
                        unk_1bf0(pVariables);

                    if (pVariables->pSoundPSG != NULL)
                        unk_1c18(pVariables);

                    if (pVariables->delay != 0)
                    {
                        pVariables->delay--;
                        if (pVariables->lfoDelayCounter_maybe != 0)
                        {
                            pVariables->lfoDelayCounter_maybe--;
                        }
                        else
                        {
                            if (pVariables->lfoSpeed != 0 && pVariables->modulationDepth != 0)
                            {
                                if (pVariables->pChannel != NULL)
                                {
                                    if (pVariables->pChannel->envelopeStage_maybe != 0)
                                    {
                                        pVariables->lfoSpeedC_maybe += pVariables->lfoSpeed;
                                        if ((s8)(pVariables->lfoSpeedC_maybe - 0x40) < 0)
                                            var_2 = pVariables->lfoSpeedC_maybe;
                                        else
                                            var_2 = 0x80 - (u8)pVariables->lfoSpeedC_maybe;

                                        if (var_2 != pVariables->modulationCalculated_maybe)
                                        {
                                            pVariables->modulationCalculated_maybe = (var_2 * (pVariables->modulationDepth + 1)) >> 7;
                                            unk_1c3c(pVariables);
                                        }
                                    }
                                }
                                else if (pVariables->pSoundPSG != NULL)
                                {
                                    if (pVariables->pSoundPSG->unk_0 != 0)
                                    {
                                        pVariables->lfoSpeedC_maybe += pVariables->lfoSpeed;
                                        if ((s8)(pVariables->lfoSpeedC_maybe - 0x40) < 0)
                                            var_2 = pVariables->lfoSpeedC_maybe;
                                        else
                                            var_2 = 0x80 - (u8)pVariables->lfoSpeedC_maybe;

                                        if (var_2 != pVariables->modulationCalculated_maybe)
                                        {
                                            pVariables->modulationCalculated_maybe = (var_2 * (pVariables->modulationDepth + 1)) >> 7;
                                            unk_1ccc(pVariables, var_2);
                                        }
                                    }
                                }
                            }
                        }
                    }

                    while (pVariables->delay == 0)
                    {
                        event = *pVariables->pRawData;
                        if (event < 0x80)
                            event = pVariables->currentEvent;
                        else if (event >= VOICE)
                        {
                            pVariables->currentEvent = event;
                            pVariables->pRawData++;
                        }

                        if (event >= TIE)
                        {
                            pVariables->unk_0 |= 0x2;
                            pVariables->gateTime_maybe = sClockTable[event - TIE];

                            event = *pVariables->pRawData;

                            if (pVariables->lfoDelay_maybe != 0)
                                pVariables->lfoDelayCounter_maybe = pVariables->lfoDelay_maybe;

                            if (event < 0x80)
                            {
                                pVariables->key_maybe = event;
                                pVariables->pRawData++;

                                event = *pVariables->pRawData;
                                if (event < 0x80)
                                {
                                    pVariables->velocity_maybe = event;
                                    pVariables->pRawData++;
                                
                                    event = *pVariables->pRawData;
                                    if (event < 0x80)
                                    {
                                        pVariables->gateTime_maybe += event;
                                        pVariables->pRawData++;
                                    }
                                }
                            }

                            if ((pVariables->unk_0 & 0xF0) >= 0x40)
                                unk_4e10(pVariables);

                            pVariables->modulationCalculated_maybe = 0;
                            TrackUpdatePitch(pVariables);
                            TrackUpdateVolume(pVariables);

                            if (pTrack->flags & (0x80 | 0x40))
                            {
                                if (pVariables->channel & 7)
                                    unk_1fe0(pTrack, pVariables);
                                else
                                    unk_1f3c(pTrack, pVariables);
                            }
                            else
                            {
                                if (pVariables->channel & 7)
                                    unk_1f90(pTrack, pVariables);
                                else
                                    unk_1e2c(pTrack, pVariables);
                            }
                        }
                        else if (event >= FINE)
                        {
                            if (event == TEMPO)
                            {
                                AudioCommand_Tempo(pTrack, pVariables);
                            }
                            else if (event == VOICE)
                            {
                                AudioCommand_Voice(pTrack, pVariables);
                            }
                            else if (event == FINE)
                            {
                                AudioCommand_Fine(pTrack, pVariables);
                                break;
                            }
                            else if (event == FINE_QUEUE)
                            {
                                AudioCommand_FineAndQueue(pTrack, pVariables);
                                break;
                            }
                            else
                            {
                                sMusicCommandFunctionPointers[event - FINE](pVariables);
                            }
                        }
                        else
                        {
                            pVariables->delay = sClockTable[event - 0x80];
                            pVariables->pRawData++;
                            break;
                        }
                    }


                    if (pVariables->unk_0 & MPT_FLG_VOLCHG)
                    {
                        TrackUpdateVolume(pVariables);
                        if (pVariables->pChannel != NULL)
                            unk_1d5c(pVariables);

                        if (pVariables->pSoundPSG != NULL)
                            unk_1ddc(pVariables);

                        pVariables->unk_0 &= ~MPT_FLG_VOLCHG;
                    }

                    if (pVariables->unk_0 & MPT_FLG_PITCHG)
                    {
                        TrackUpdatePitch(pVariables);
                        if (pVariables->pChannel != NULL)
                            unk_1d78(pVariables);

                        if (pVariables->pSoundPSG != NULL)
                            unk_1de8(pVariables);

                        pVariables->unk_0 &= ~MPT_FLG_PITCHG;
                    }
                }
            }
        }
    }

    pTrack->occupied = FALSE;
    if (pTrack->queueFlags == 0x1)
    {
        PlayMusic(pTrack->musicTrack, pTrack->priority);
        pTrack->occupied = TRUE;

        pTrack->musicTrack = 0;
        pTrack->priority = 0;
        pTrack->queueFlags = 0;
        pTrack->occupied = FALSE;
    }
    else if (pTrack->queueFlags & 0x4)
    {
        SoundPlay(pTrack->musicTrack & SHORT_MAX);
        pTrack->occupied = TRUE;

        pTrack->musicTrack = 0;
        pTrack->priority = 0;
        pTrack->queueFlags = 0;
        pTrack->occupied = FALSE;
    }
    else if (pTrack->queueFlags & 0x2)
    {
        if (pTrack->queueFlags & 0x80)
            ReplayQueuedMusic(pTrack->queueFlags);

        pTrack->queueFlags = 0;
    }
}

/**
 * @brief 1bf0 | 28 | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1bf0(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannelNext_maybe)
    {
        if (pChannel->gateTime_maybe != 0)
        {
            if (--pChannel->gateTime_maybe == 0)
            {
                pChannel->envelopeStage_maybe = 5;
            }
        }
    }
}

/**
 * @brief 1c18 | 24 | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1c18(struct TrackVariables* pVariables)
{
    struct PSGSoundData* pSound;

    pSound = pVariables->pSoundPSG;

    if (pVariables->gateTime_maybe != 0)
    {
        if (--pVariables->gateTime_maybe == 0)
        {
            pSound->unk_0 = 5;
            pSound->cgb_envelopeCtr_maybe = 0;
        }
    }
}

/**
 * @brief 1c3c | 90 | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1c3c(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    s32 frequency;
    s16 midiKey;

    pChannel = pVariables->pChannel;

    switch (pVariables->modulationType)
    {
        case 1:
        case 2:
            TrackUpdateVolume(pVariables);
            for (; pChannel != NULL; pChannel = pChannel->pChannelNext_maybe)
                pChannel->volumeUpdateFlag_maybe |= VOLUME_UPDATE_FLAG_UPDATE;
            break;
        
        case 0:
            TrackUpdatePitch(pVariables);

            if (pChannel->unk_1 != 0 && pChannel->unk_1 != 0x20)
                break;

            for (; pChannel != NULL; pChannel = pChannel->pChannelNext_maybe)
            {
                midiKey = pVariables->keyShiftCalculated_maybe + pChannel->unk_7;
                CLAMP(midiKey, 0, 0x7F);

                frequency = MidiKey2Freq(pVariables->pSample1, midiKey, pVariables->pitchCalculated_maybe);
                pChannel->unk_1C = frequency;

                if (frequency == gMusicInfo.sampleRate)
                    frequency = 0x4000;
                else
                    frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch);

                pChannel->unk_1C = frequency;
            }
    }
}

/**
 * @brief 1ccc | 90 | To document
 * 
 * @param pVariables Track variables pointer
 * @param param_2 To document
 */
static void unk_1ccc(struct TrackVariables* pVariables, s16 param_2)
{
    struct PSGSoundData* pSound;
    s16 var_0;

    pSound = pVariables->pSoundPSG;

    if (pVariables->modulationType == 1)
    {
        TrackUpdateVolume(pVariables);
        pSound->nrx2 = ((u8)pSound->cgb_envelopeVol_maybe + pVariables->modulationCalculated_maybe / sUnk_808cc4d[param_2]) * 16;
        pSound->unk_F |= 0x20;
    }
    else if (pVariables->modulationType == 0)
    {
        TrackUpdatePitch(pVariables);

        var_0 = pVariables->keyShiftCalculated_maybe + pVariables->pSoundPSG->unk_1C;
        CLAMP(var_0, 0, 0x7F);

        pSound->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->pitchCalculated_maybe);
        pSound->unk_F |= 0x4;
    }
    else if (pVariables->modulationType == 2)
    {
        TrackUpdateVolume(pVariables);
        pSound->unk_F |= 0x10;
    }
}

/**
 * @brief 1d5c | 1c | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1d5c(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannelNext_maybe)
        pChannel->volumeUpdateFlag_maybe |= VOLUME_UPDATE_FLAG_UPDATE;
}

/**
 * @brief 1d78 | 64 | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1d78(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    s32 frequency;
    s16 midiKey;

    for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannelNext_maybe)
    {
        midiKey = pVariables->keyShiftCalculated_maybe + pChannel->unk_7;
        CLAMP(midiKey, 0, 0x7F);

        frequency = MidiKey2Freq(pChannel->pSample, midiKey, pVariables->pitchCalculated_maybe);
        pChannel->unk_1C = frequency;

        if (frequency == gMusicInfo.sampleRate)
            frequency = 0x4000;
        else
            frequency = CallGetNoteFrequency(frequency, gMusicInfo.pitch);

        pChannel->unk_1C = frequency;
        pChannel->volumeUpdateFlag_maybe |= VOLUME_UPDATE_FLAG_NOTHING;
    }
}

/**
 * @brief 1ddc | c | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1ddc(struct TrackVariables* pVariables)
{
    pVariables->pSoundPSG->unk_F |= 0x10;
}

/**
 * @brief 1de8 | 44 | To document
 * 
 * @param pVariables Track variables pointer
 */
static void unk_1de8(struct TrackVariables* pVariables)
{
    s16 var_0;

    var_0 = pVariables->keyShiftCalculated_maybe + pVariables->pSoundPSG->unk_1C;
    CLAMP(var_0, 0, 0x7F);

    pVariables->pSoundPSG->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->pitchCalculated_maybe);
    pVariables->pSoundPSG->unk_F |= 0x4;
}

/**
 * @brief 1e2c | 110 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
static void unk_1e2c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    u8 priority;
    u8 var_1;
    u32 var_2;
    s32 var_3;
    s32 var_4;
    u8 i;
    struct SoundChannel* pChannel;
    struct TrackVariables* pVariables2;

    if (pTrack->trackHeaderPriority + pVariables->priority > UCHAR_MAX)
        priority = UCHAR_MAX;
    else
        priority = pTrack->trackHeaderPriority + pVariables->priority;

    var_2 = priority;
    pVariables2 = pVariables;
    var_1 = FALSE;
    pChannel = NULL;

    for (i = 0; i < gMusicInfo.maxSoundChannels; i++)
    {
        if (gMusicInfo.soundChannels[i].envelopeStage_maybe == 0)
        {
            pChannel = &gMusicInfo.soundChannels[i];
            goto end;
            //TrackSendVariablesToChannel(pChannel, pVariables, var_0);
            //return;
        }
        
        if (gMusicInfo.soundChannels[i].envelopeStage_maybe == 5 ||
            gMusicInfo.soundChannels[i].envelopeStage_maybe == 6 ||
            gMusicInfo.soundChannels[i].envelopeStage_maybe == 8)
        {
            if (!var_1)
            {
                var_1 = TRUE;
                var_4 = FALSE;
                var_3 = TRUE;
            }
            else
            {
                var_4 = TRUE;
                var_3 = FALSE;
            }
        }
        else
        {
            var_4 = FALSE;
            var_3 = FALSE;
        }

        if (!var_3)
        {
            if (var_4 || !var_1)
            {
                if (gMusicInfo.soundChannels[i].unk_2 >= var_2 &&
                    (gMusicInfo.soundChannels[i].unk_2 > var_2 ||
                    (gMusicInfo.soundChannels[i].pVariables <= pVariables2 &&
                    gMusicInfo.soundChannels[i].pVariables < pVariables2)))
                {
                    continue;
                }
                var_3 = TRUE;
            }
            else
            {
                var_3 = FALSE;
            }
        }

        if (var_3)
        {
            var_2 = gMusicInfo.soundChannels[i].unk_2;
            pVariables2 = gMusicInfo.soundChannels[i].pVariables;
            pChannel = &gMusicInfo.soundChannels[i];
        }
    }

    if (pChannel != NULL)
    {
        end:
        TrackSendVariablesToChannel(pChannel, pVariables, priority);
    }
}

/**
 * @brief 1f3c | 54 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
static void unk_1f3c(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    if (pTrack->flags & 0x80)
    {
        if (++pTrack->unk_23 <= pTrack->maxSoundChannels)
            unk_1e2c(pTrack, pVariables);
    }
    else if (pTrack->flags & 0x40)
    {
        if (++pTrack->unk_23 <= pTrack->maxSoundChannels)
            unk_1e2c(pTrack, pVariables);
    }
}

/**
 * @brief 1f90 | 50 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
static void unk_1f90(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    u8 priority;
    struct PSGSoundData* pSound;

    if (pTrack->trackHeaderPriority + pVariables->priority > UCHAR_MAX)
        priority = UCHAR_MAX;
    else
        priority = pTrack->trackHeaderPriority + pVariables->priority;

    pSound = &gUnk_300376C[pVariables->channel & 7];
    if (pSound->unk_0 == 0 ||
        (priority >= pSound->unk_16 &&
        (priority != pSound->unk_16 ||
        pVariables <= pSound->pVariables)))
    {
        unk_2030(pSound, pVariables, priority);
    }
}

/**
 * @brief 1fe0 | 50 | To document
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
static void unk_1fe0(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    u8 priority;
    struct PSGSoundData* pSound;

    if (pTrack->trackHeaderPriority + pVariables->priority > UCHAR_MAX)
        priority = UCHAR_MAX;
    else
        priority = pTrack->trackHeaderPriority + pVariables->priority;

    pSound = &gUnk_300376C[pVariables->channel & 7];
    if (pSound->unk_0 == 0 ||
        (priority >= pSound->unk_16 &&
        (priority != pSound->unk_16 ||
        pVariables <= pSound->pVariables)))
    {
        unk_2030(pSound, pVariables, priority);
    }
}

/**
 * @brief 2030 | 74 | To document
 * 
 * @param pSound PSG sound pointer
 * @param pVariables Track variables pointer
 * @param param_3 To document
 */
static void unk_2030(struct PSGSoundData* pSound, struct TrackVariables* pVariables, u32 param_3)
{
    s16 var_0;

    pSound->unk_16 = param_3;
    pSound->unk_1 = pVariables->channel;
    pSound->unk_C = pVariables->pan_maybe;
    pSound->unk_17 = pVariables->key_maybe;

    if ((pVariables->unk_0 & 0xF0) == 0x80)
        pSound->unk_1C = pVariables->unk_35;
    else
        pSound->unk_1C = pVariables->key_maybe;

    var_0 = pVariables->keyShiftCalculated_maybe + pSound->unk_1C;
    CLAMP(var_0, 0, 0x7F);

    pSound->maybe_noteDelay = GetNoteDelay(pVariables, var_0, pVariables->pitchCalculated_maybe);
    pSound->pVariables->pSoundPSG = NULL;
    pSound->pVariables = pVariables;
    pSound->unk_F |= 2;
    pSound->unk_0 = 1;
    pVariables->pSoundPSG = pSound;
}

/**
 * @brief 20a4 | 30 | Removes a channel from the channel list
 * 
 * @param pChannel Sound channel pointer
 */
void FreeSoundChannel(struct SoundChannel* pChannel)
{
    if (pChannel->pVariables != NULL)
    {
        if (pChannel->pChannelNext_maybe != NULL)
            pChannel->pChannelNext_maybe->pChannelPrev_maybe = pChannel->pChannelPrev_maybe;

        if (pChannel->pChannelPrev_maybe != NULL)
            pChannel->pChannelPrev_maybe->pChannelNext_maybe = pChannel->pChannelNext_maybe;
        else
            pChannel->pVariables->pChannel = pChannel->pChannelNext_maybe;

        pChannel->pVariables = NULL;
    }
}

/**
 * @brief 20d4 | 6c | Gets the delay for a note (probably)
 * 
 * @param pVariables Track variables pointer
 * @param param_2 Note?
 * @param param_3 To document
 * @return u16 Delay
 */
static u16 GetNoteDelay(struct TrackVariables* pVariables, u8 param_2, u8 param_3)
{
    u16 delay;
    u16 temp;

    if ((pVariables->channel & 7) < 4)
    {
        delay = sUnk_808cad0[param_2];
        if (param_3 != 0)
        {
            if (param_2 + 1 > ARRAY_SIZE(sUnk_808cad0) - 1)
                param_2 = ARRAY_SIZE(sUnk_808cad0) - 1;

            temp = (sUnk_808cad0[param_2 + 1] - delay) * (param_3 + 1) >> 8;
            delay += temp;
        }
    }
    else
    {
        delay = sNoiseTable[param_2 - 21] | (u8)(u32)pVariables->pSample1;
    }
    
    return delay;
}

/**
 * @brief 2140 | 70 | Processes the audio command FINE
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void AudioCommand_Fine(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct SoundChannel* pNext;

    if (pVariables->pSoundPSG != NULL)
    {
        ClearRegistersForPsg(pVariables->pSoundPSG, (pVariables->channel & 7) - 1);
        pVariables->pSoundPSG->unk_0 = 0;
        pVariables->pSoundPSG->pVariables = NULL;
    }

    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pNext)
        {
            pChannel->envelopeStage_maybe = 10;
            pChannel->pVariables = NULL;
            pNext = pChannel->pChannelNext_maybe;
            pChannel->pChannelNext_maybe = NULL;
            pChannel->pChannelPrev_maybe = NULL;
        }
    }

    pVariables->pSoundPSG = NULL;
    pVariables->pChannel = NULL;

    if (++pTrack->currentTrack == pTrack->amountOfTracks)
    {
        unk_2a38(pTrack);
        pTrack->flags = 0;
        pTrack->currentTrack = 0;
    }

    pVariables->unk_0 = 0;
}

/**
 * @brief 21b0 | 7c | Custom audio command that performs the FINE command and sets the queue flag
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void AudioCommand_FineAndQueue(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct SoundChannel* pNext;

    if (pVariables->pSoundPSG != NULL)
    {
        ClearRegistersForPsg(pVariables->pSoundPSG, (pVariables->channel & 7) - 1);
        pVariables->pSoundPSG->unk_0 = 0;
        pVariables->pSoundPSG->pVariables = NULL;
    }

    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pNext)
        {
            pChannel->envelopeStage_maybe = 10;
            pChannel->pVariables = NULL;
            pNext = pChannel->pChannelNext_maybe;
            pChannel->pChannelNext_maybe = NULL;
            pChannel->pChannelPrev_maybe = NULL;
        }
    }

    pVariables->pSoundPSG = NULL;
    pVariables->pChannel = NULL;

    if (++pTrack->currentTrack == pTrack->amountOfTracks)
    {
        unk_2a38(pTrack);
        pTrack->flags = 0;
        pTrack->currentTrack = 0;
        pTrack->queueFlags |= 0x2;
    }

    pVariables->unk_0 = 0;
}

/**
 * @brief 222c | 38 | Processes the audio command PEND
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_PatternEnd(struct TrackVariables* pVariables)
{
    s8 i;

    pVariables->pRawData++;

    for (i = ARRAY_SIZE(pVariables->patternStartPointers) - 1; i >= 0; i--)
    {
        if (pVariables->patternStartPointers[i])
        {
            pVariables->pRawData = pVariables->patternStartPointers[i];
            pVariables->patternStartPointers[i] = NULL;
            break;
        }
    }
}

/**
 * @brief 2264 | 40 | Processes the audio command REPT
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Repeat(struct TrackVariables* pVariables)
{
    if (pVariables->repeatCount == 0)
    {
        // Setup repeat
        pVariables->pRawData++;

        // Get repeat count
        pVariables->repeatCount = *pVariables->pRawData;

        // Start pattern
        AudioCommand_PatternPlay(pVariables);
        return;
    }

    if (--pVariables->repeatCount == 0)
    {
        // Repeat count reached 0, end pattern
        AudioCommand_PatternEnd(pVariables);
        return;
    }

    pVariables->pRawData++;

    // Replay pattern
    AudioCommand_PatternPlay(pVariables);
}

/**
 * @brief 22a4 | 10 | Processes the audio command PRIO
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Priority(struct TrackVariables* pVariables)
{
    pVariables->pRawData++;
    pVariables->priority = *pVariables->pRawData++;
}

/**
 * @brief 22b4 | 18 | Processes the audio command KEYSH
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_KeyShift(struct TrackVariables* pVariables)
{
    pVariables->pRawData++;
    pVariables->keyShift = *pVariables->pRawData;
    pVariables->unk_0 |= MPT_FLG_PITCHG;
    pVariables->pRawData++;
}

/**
 * @brief 22cc | c0 | Processes the audio command VOICE
 * 
 * @param pTrack Track data pointer
 * @param pVariables Track variables pointer
 */
void AudioCommand_Voice(struct TrackData* pTrack, struct TrackVariables* pVariables)
{
    struct Voice* pVoice;
    u32 channel;

    pVoice = &pTrack->pVoice[*pVariables->pRawData];
    pVariables->channel = pVoice->instrumentType;

    if (pVariables->channel >= 0x40)
    {
        if (pVariables->channel == 0x80)
        {
            pVariables->unk_0 |= 0x80;
            pVariables->pSample2 = pVoice->pSample;
        }
        else if (pVariables->channel == 0x40)
        {
            pVariables->unk_0 |= 0x40;
            pVariables->pSample2 = pVoice->pSample;
            pVariables->envelope2 = pVoice->envelope;
        }
    }
    else
    {
        pVariables->unk_0 &= 0xF;
        pVariables->unk_36 = pVoice->unk_2;

        channel = pVariables->channel & 7;

        if (channel == 0)
        {
            pVariables->pSample1 = pVoice->pSample;
        }
        else if (channel < 3)
        {
            if (!(pVoice->unk_3 & 0x80) && pVoice->unk_3 & 0x70)
                pVariables->unk_37 = pVoice->unk_3;
            else
                pVariables->unk_37 = 8;

            pVariables->pSample1 = (u32*)((u32)pVoice->pSample << 0x1E >> 0x18);
        }
        else if (channel == 3)
        {
            UploadSampleToWaveRAM(pVoice->pSample);
        }
        else if (channel == 4)
        {
            pVariables->pSample1 = (u32*)((u32)pVoice->pSample << 0x1B >> 0x18);
        }
        
        pVariables->envelope1 = pVoice->envelope;
    }

    pVariables->pRawData++;
}

/**
 * @brief 238c | 14 | Processes the audio command VOL
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Volume(struct TrackVariables* pVariables)
{
    pVariables->volume = *pVariables->pRawData;
    pVariables->unk_0 |= MPT_FLG_VOLCHG;
    pVariables->pRawData++;
}

/**
 * @brief 23a0 | 14 | Processes the audio command PAN
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_PanPot(struct TrackVariables* pVariables)
{
    pVariables->pan_maybe = *pVariables->pRawData;
    pVariables->unk_0 |= MPT_FLG_VOLCHG;
    pVariables->pRawData++;
}

/**
 * @brief 23b4 | 18 | Processes the audio command BEND
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_PitchBend(struct TrackVariables* pVariables)
{
    pVariables->pitchBend = *pVariables->pRawData - C_V;
    pVariables->unk_0 |= MPT_FLG_PITCHG;
    pVariables->pRawData++;
}

/**
 * @brief 23cc | 18 | Processes the audio command BENDR
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_BendRange(struct TrackVariables* pVariables)
{
    pVariables->bendRange = *pVariables->pRawData;
    pVariables->unk_0 |= MPT_FLG_PITCHG;
    pVariables->pRawData++;
}

/**
 * @brief 23e0 | 10 | Processes the audio command LFOS
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_LfoSpeed(struct TrackVariables* pVariables)
{
    pVariables->lfoSpeed = (*pVariables->pRawData + 1) / 2;
    pVariables->pRawData++;
}

/**
 * @brief 23f0 | 10 | Processes the audio command LFODL
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_LfoDelay(struct TrackVariables* pVariables)
{
    u8 param;

    param = *pVariables->pRawData;
    pVariables->lfoDelay_maybe = param;
    pVariables->lfoDelayCounter_maybe = param;
    pVariables->pRawData++;
}

/**
 * @brief 2400 | c | Processes the audio command MOD
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_ModulationDepth(struct TrackVariables* pVariables)
{
    pVariables->modulationDepth = *pVariables->pRawData;
    pVariables->pRawData++;
}

/**
 * @brief 240c | c | Processes the audio command MODT
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_ModulationType(struct TrackVariables* pVariables)
{
    pVariables->modulationType = *pVariables->pRawData;
    pVariables->pRawData++;
}

/**
 * @brief 2418 | 18 | Processes the audio command TUNE
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_Tune(struct TrackVariables* pVariables)
{
    pVariables->tune = *pVariables->pRawData - C_V;
    pVariables->unk_0 |= MPT_FLG_PITCHG;
    pVariables->pRawData++;
}

/**
 * @brief 2430 | 30 | Processes the audio command XCMD
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_ExtendCommand(struct TrackVariables* pVariables)
{
    if (*pVariables->pRawData == xIECV)
    {
        pVariables->pRawData++;
        pVariables->echoVolume_maybe = *pVariables->pRawData;
        pVariables->pRawData++;
    }

    if (*pVariables->pRawData == xIECL)
    {
        pVariables->pRawData++;
        pVariables->echoLength_maybe = *pVariables->pRawData;
        pVariables->pRawData++;
    }
}

/**
 * @brief 2460 | 5c | Processes the audio command EOT
 * 
 * @param pVariables Track variables pointer
 */
void AudioCommand_EndOfTie(struct TrackVariables* pVariables)
{
    struct SoundChannel* pChannel;
    struct PSGSoundData* pSound;
    u8 key;

    if (*pVariables->pRawData < 0x80)
    {
        key = *pVariables->pRawData;
        pVariables->key_maybe = key;
        pVariables->pRawData++;
    }
    else
    {
        key = pVariables->key_maybe;
    }
    
    if (pVariables->pChannel != NULL)
    {
        for (pChannel = pVariables->pChannel; pChannel != NULL; pChannel = pChannel->pChannelNext_maybe)
        {
            if (pChannel->envelopeStage_maybe >= 1 && pChannel->envelopeStage_maybe <= 4 && pChannel->unk_6 == key)
            {
                pChannel->envelopeStage_maybe = 5;
                break;
            }
        }
    }

    pSound = pVariables->pSoundPSG;
    if (pSound != NULL && pSound->unk_17 == key)
    {
        pSound->unk_0 = 5;
        pVariables->pSoundPSG->cgb_envelopeCtr_maybe = 0;
    }
}

/**
 * @brief 24bc | 4 | Empty function
 * 
 * @param pVariables Track variables pointer
 */
void Music_EmptyCommand(struct TrackVariables* pVariables)
{
    return;
}

/**
 * @brief 24c0 | 5c | Clears the registers for a PSG sound
 * 
 * @param pSound PSG sound pointer
 * @param channel Channel
 */
void ClearRegistersForPsg(struct PSGSoundData* pSound, u8 channel)
{
    switch (channel)
    {
        case 0:
            WRITE_8(REG_SOUND1CNT_H + 1, 8);
            WRITE_16(REG_SOUND1CNT_X, SOUNDCNT_RESTART_SOUND);
            break;

        case 1:
            WRITE_8(REG_SOUND2CNT_L + 1, 8);
            WRITE_16(REG_SOUND2CNT_H, SOUNDCNT_RESTART_SOUND);
            break;

        case 2:
            WRITE_8(REG_SOUND3CNT_L, 0);
            break;

        case 3:
            WRITE_8(REG_SOUND4CNT_L + 1, 8);
            WRITE_16(REG_SOUND4CNT_H, SOUNDCNT_RESTART_SOUND);
            break;
    }
}

/**
 * @brief 251c | 48 | Clears the registers for a PSG sound, unused
 * 
 * @param pSound PSG sound pointer
 * @param channel Channel
 */
void ClearRegistersForPsg_Unused(struct PSGSoundData* pSound, u8 channel)
{
    switch (channel)
    {
        case 0:
            WRITE_8(REG_SOUND1CNT_H + 1, 0);
            break;

        case 1:
            WRITE_8(REG_SOUND2CNT_L + 1, 0);
            break;

        case 2:
            WRITE_8(REG_SOUND3CNT_L, 0);
            break;

        case 3:
            WRITE_8(REG_SOUND4CNT_L + 1, 0);
            break;
    }
}
