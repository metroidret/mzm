#ifndef AUDIO_STRUCT_H
#define AUDIO_STRUCT_H

#include "types.h"
#include "constants/audio.h"

// Structs

struct MusicTrackInfo {
    u16 currentRoomTrack;
    s8 pauseScreenFlag;
    s8 takingNormalTransition;
    s8 unk;
};

struct WaveData {
    u16 type;
    u16 stat;
    u32 freq;
    u32 loop;
    u32 size;
    /* s8 data[size+1]; */
};

struct Envelope {
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct Voice {
    u8 instrumentType;
    u8 pitch;
    u8 unk_2;
    u8 unk_3;
    u32* pSample;
    struct Envelope envelope;
};


struct SoundQueue {
    u8 exists;
    u8 priority;
    u16 fadingTimer;
    const u8* pHeader;
};

struct SoundChannel {
    u8 envelopeStage_maybe;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 rightVol_maybe;
    u8 leftVol_maybe;
    u8 unk_6;
    u8 unk_7;
    struct Envelope envelope;
    u8 echoVol_maybe;
    u8 echoLen_maybe;
    u8 gateTime_maybe;
    u8 velocity_maybe;
    u8 envelopeVol_maybe;
    u8 envelopeVolR_maybe;
    u8 envelopeVolL_maybe;
    u8 volumeUpdateFlag_maybe;
    u32* pSize;
    u32 unk_18;
    u32 unk_1C;
    u32* pSample; // Type?
    u8* pData;
    struct TrackVariables* pVariables;
    struct SoundChannel* pChannelPrev_maybe;
    struct SoundChannel* pChannelNext_maybe;
};

struct SoundChannelBackup {
    struct SoundChannel* pChannel;
    struct SoundChannel channel;
};

struct PSGSoundData {
    u8 unk_0;
    u8 unk_1;
    u8 rightVol_maybe;
    u8 leftVol_maybe;
    struct Envelope envelope;
    u16 maybe_noteDelay;
    u8 velocity_maybe;
    u8 unk_B;
    u8 unk_C;
    u8 echoVol_maybe;
    u8 echoLen_maybe;
    u8 unk_F;
    u8 nrx0; // written to REG_SOUND1CNT_L, REG_SOUND3CNT_L (sound channel sweep, ram select registers)
    u8 nrx1; // written to low byte of REG_SOUND1CNT_H, REG_SOUND2CNT_L, REG_SOUND3CNT_H, REG_SOUND4CNT_L (sound channel duty/len/envelope/volume registers)
    u8 nrx2; // written to high byte of REG_SOUND1CNT_H, REG_SOUND2CNT_L, REG_SOUND3CNT_H, REG_SOUND4CNT_L (sound channel duty/len/envelope/volume registers)
    u8 undefined_13;
    u16 nrx3_nrx4; // written to REG_SOUND1CNT_X, REG_SOUND2CNT_H, REG_SOUND3CNT_X, REG_SOUND4CNT_H (sound channel frequency/control registers)
    u8 unk_16;
    u8 unk_17;
    u8 cgb_envelopeCtr_maybe;
    s8 cgb_envelopeVol_maybe;
    u8 cgb_envelopeGoal_maybe;
    u8 cgb_sustainGoal_maybe;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u32* pSample; // Type?
    struct TrackVariables* pVariables;
};

struct TrackVariables {
    u8 unk_0;
    u8 key_maybe;
    u8 delay;
    u8 currentEvent;
    u8 volume;
    u8 volumeX_maybe;
    u8 pan_maybe;
    s8 panX_maybe;
    u8 volRightCalculated_maybe;
    u8 volLeftCalculated_maybe;
    u8 repeatCount;
    u8 priority;
    u8 echoVolume_maybe;
    u8 echoLength_maybe;
    u8 gateTime_maybe;
    u8 velocity_maybe;
    u8 lfoSpeed;
    u8 modulationDepth;
    u8 modulationType;
    s8 modulationCalculated_maybe;
    u8 lfoDelay_maybe;
    u8 lfoDelayCounter_maybe;
    s8 lfoSpeedC_maybe;
    s8 keyShiftCalculated_maybe;
    u8 pitchCalculated_maybe;
    s8 pitchBend;
    u8 bendRange;
    u8 unk_1B;
    s8 keyShift;
    s8 keyShiftX_maybe;
    u8 tune;
    u8 pitchX_maybe;
    u32 unk_20;
    const u8* pRawData;
    const u8* patternStartPointers[3];
    u8 channel;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;

    u32* pSample1; // Type?
    struct Envelope envelope1;
    u32* pSample2; // Type?
    struct Envelope envelope2;

    struct SoundChannel* pChannel;
    struct PSGSoundData* pSoundPSG;
};

struct TrackData {
    u8 flags;
    u8 amountOfTracks;

    u8 undefined_2;
    u8 trackHeaderPriority;
    u8 currentTrack;

    u8 maxAmountOfTracks;
    u16 maybe_volume;
    u16 fadingTimer;

    u16 tempoRawBpm_maybe;
    u16 tempoInterval_maybe;
    u16 tempoCounter_maybe;

    const u8* pHeader;
    struct Voice* pVoice;
    struct TrackVariables* pVariables;

    u8 occupied;
    u8 unk_1D;
    u8 unk_1E;
    u8 priority;
    u16 musicTrack;
    u8 maxSoundChannels;

    u8 unk_23;
    u16 unk_24;
    u16 unk_26;

    u8 queueFlags;

    u8 undefined_29;
    u8 undefined_2A;
    u8 undefined_2B;
    u8 undefined_2C;
    u8 undefined_2D;
    u8 undefined_2E;
    u8 undefined_2F;
    u8 undefined_30;
    u8 undefined_31;
    u8 undefined_32;

    u8 unk_33;
    u8 unk_34;
    u8 unk_35;

    u8 undefined_36;
    u8 undefined_37;
    u8 undefined_38;
    u8 undefined_39;
    u8 undefined_3A;
    u8 undefined_3B;
    u8 undefined_3C;
    u8 undefined_3D;
    u8 undefined_3E;
    u8 undefined_3F;
};

struct TrackGroupROMData {
    struct TrackData* pTrack;
    struct TrackVariables* pVariables;
    u16 maxAmountOfTracks;
    u16 unk_A;
};

struct SoundEntry {
    const u8* pHeader;
    u16 trackGroundNumber;
    u16 trackGroundNumber_2;
};


struct MusicInfo {
    u8 unk_0;
    boolu8 occupied;
    u8 unk_2;
    u8 unk_3;

    u8 reverb;
    u8 maxSoundChannels;
    u8 volume;
    u8 freqIndex;

    u8 unk_8;
    u8 maxScanlines_maybe;
    u8 currentSoundChannel;
    u8 volumeDownFlag;
    u8 unk_C; // samplesPerFrame / 16
    u8 unk_D; // unused, number of frames to process sample?
    u8 maxDmaCount_maybe; // 96
    u8 unk_F;
    u8 dmaCounter_maybe;
    u8 unk_11; // (samplesPerFrame / 16) * 2
    u16 sampleRate;
    u32 unk_14; // unused, samples per frame
    u32 pitch;
    Sound musicTrack;
    u16 unk_1E;
    u8 unk_20;
    u8 priority;
    u16 musicTrackOnTransition;
    u32 musicRawData[768];
    u8 soundRawData[PCM_DMA_BUF_SIZE * 2];
    struct SoundChannel soundChannels[11];
};


typedef void (*MusicFunc_T)(struct TrackVariables*);

extern u8 gStereoFlag;
extern struct MusicTrackInfo gMusicTrackInfo;

extern struct MusicInfo gMusicInfo;

// Linker variables
extern char gNumMusicPlayers[];
extern char gUnk_Audio0x64[];
extern char gUnk_Audio0x194F700[];
extern char gUnk_Audio0x50[];

extern struct TrackData gTrackData8;
extern struct TrackData gTrackData3;
extern struct TrackData gTrackData1;
extern struct TrackData gTrackData6;
extern struct TrackData gTrackData4;
extern struct TrackData gTrackData0;
extern struct TrackData gTrackData7;
extern struct TrackData gTrackData2;
extern struct TrackData gTrackData5;

extern struct SoundChannelBackup gSoundChannelBackup[7];
extern struct SoundChannelBackup gSoundChannelTrack2Backup[7];
extern struct SoundQueue gSoundQueue[9];

extern struct TrackVariables gTrack0Variables[12];
extern struct TrackVariables gTrack1Variables[10];
extern struct TrackVariables gTrack2Variables[2];
extern struct TrackVariables gTrack3Variables[2];
extern struct TrackVariables gTrack4Variables[2];
extern struct TrackVariables gTrack5Variables[2];
extern struct TrackVariables gTrack6Variables[3];
extern struct TrackVariables gTrack7Variables[1];
extern struct TrackVariables gTrack8Variables[6];

typedef void (*SoundCodeAFunc_T)(struct SoundChannel*, u32*, u8);
typedef u8* (*SoundCodeBFunc_T)(u32*, u32*, u32*, u8);
typedef u8* (*SoundCodeCFunc_T)(u32*, u32*, u8);

extern SoundCodeAFunc_T gSoundCodeAPointer;
extern u8 gSoundCodeA[1624];
extern SoundCodeBFunc_T gSoundCodeBPointer;
extern u8 gSoundCodeB[164];
extern SoundCodeCFunc_T gSoundCodeCPointer;
extern u8 gSoundCodeC[176];

extern struct PSGSoundData gUnk_300376C[];
extern struct PSGSoundData gPsgSounds[4];

#endif /* AUDIO_STRUCT_H */
