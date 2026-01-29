#ifndef PART2_STRUCT_H
#define PART2_STRUCT_H

#include "types.h"
#include "macros.h"

#define NES_CLOCK_SPEED 1789773u

#define EMULATOR_AUDIO_BUFFER_SIZE 40

#define NES_APU_REG_BASE 0x4000

MAKE_ENUM(u16, EmulatorAudioApuRegisters) {
    NES_APU_REG_SQ1_VOL,
    NES_APU_REG_SQ1_SWEEP,
    NES_APU_REG_SQ1_LO,
    NES_APU_REG_SQ1_HI,
    NES_APU_REG_SQ2_VOL,
    NES_APU_REG_SQ2_SWEEP,
    NES_APU_REG_SQ2_LO,
    NES_APU_REG_SQ2_HI,
    NES_APU_REG_TRI_LINEAR,
    NES_APU_REG_4009,
    NES_APU_REG_TRI_LO,
    NES_APU_REG_TRI_HI,
    NES_APU_REG_NOISE_VOL,
    NES_APU_REG_400D,
    NES_APU_REG_NOISE_LO,
    NES_APU_REG_NOISE_HI,
    NES_APU_REG_DMC_FREQ,
    NES_APU_REG_DMC_RAW,
    NES_APU_REG_DMC_START,
    NES_APU_REG_DMC_LEN,
    NES_APU_REG_OAM_DMA,
    NES_APU_REG_SND_CHN,
    NES_APU_REG_JOY_1,
    NES_APU_REG_FRAME_CTR,

    NES_APU_REG_COUNT
};

extern void* gEmuAudio_OutputBuffer0Ptr;
extern void* gEmuAudio_OutputBuffer1Ptr;
extern void* gEmuAudio_OutputBuffer2Ptr;
extern u8 gEmuAudio_EnableOutput;
extern u8 gEmuAudio_NumExtraOutputBuffers;
extern u8 gEmuAudio_CurrentOutputBuffer;
extern u16 gEmuAudio_Timer0Reload; // Set but never read
extern void (*gEmuAudio_ProcessApuAndMixBuffersFunc)(void*, u32);
extern u16 gEmuAudio_ActiveChannels[]; // length?
extern u16 gEmuAudio_SndChn; // SND_CHN
extern u16 gEmuAudio_FrameCtr; // FRAME_CTR
extern u32* gEmuAudio_Pulse1_BufferPtr;
extern u32* gEmuAudio_Pulse2_BufferPtr;
extern u32* gEmuAudio_Triangle_BufferPtr;
extern u32* gEmuAudio_Noise_BufferPtr;

// Pulse 1 variables
extern u32 gUnk_03005A90;
extern u16 gUnk_03005A94;
extern u16 gUnk_03005A96;
extern u16 gEmuAudio_Pulse1_Vol; // SQ1_VOL
extern u16 gEmuAudio_Pulse1_Sweep; // SQ1_SWEEP
extern u16 gEmuAudio_Pulse1_Lo; // SQ1_LO
extern u16 gEmuAudio_Pulse1_Hi; // SQ1_HI
extern u16 gEmuAudio_Pulse1_Timer;
extern u16 gUnk_03005AA2;
extern u16 gUnk_03005AA4;
extern u16 gUnk_03005AA6;
extern u16 gEmuAudio_Pulse1_LengthCounter;
extern u16 gUnk_03005AAA;
extern u8 gUnk_03005AAC;
extern u8 gUnk_03005AAD;

// Pulse 2 variables
extern u32 gUnk_03005AB0;
extern u16 gUnk_03005AB4;
extern u16 gUnk_03005AB6;
extern u16 gEmuAudio_Pulse2_Vol; // SQ2_VOL
extern u16 gEmuAudio_Pulse2_Sweep; // SQ2_SWEEP
extern u16 gEmuAudio_Pulse2_Lo; // SQ2_LO
extern u16 gEmuAudio_Pulse2_Hi; // SQ2_HI
extern u16 gEmuAudio_Pulse2_Timer;
extern u16 gUnk_03005AC2;
extern u16 gUnk_03005AC4;
extern u16 gUnk_03005AC6;
extern u16 gEmuAudio_Pulse2_LengthCounter;
extern u16 gUnk_03005ACA;
extern u8 gUnk_03005ACC;
extern u8 gUnk_03005ACD;

// Triangle variables
extern u32 gUnk_03005AD0;
extern u16 gEmuAudio_Triangle_LengthCounter;
extern u16 gUnk_03005AD6;
extern u16 gUnk_03005AD8;
extern u16 gUnk_03005ADA;
extern u16 gUnk_03005ADC;
extern u16 gEmuAudio_Triangle_Linear; // TRI_LINEAR
extern u16 gEmuAudio_Triangle_Lo; // TRI_LO
extern u16 gEmuAudio_Triangle_Hi; // TRI_HI
extern u16 gUnk_03005AE4;

// Noise variables
extern u32 gUnk_03005AE8;
extern u32 gUnk_03005AEC;
extern u32 gUnk_03005AF0;
extern u16 gUnk_03005AF4;
extern u16 gUnk_03005AF6;
extern u16 gUnk_03005AF8;
extern u16 gEmuAudio_Noise_LengthCounter;
extern u16 gUnk_03005AFC;
extern u16 gUnk_03005AFE;
extern u16 gEmuAudio_Noise_Vol; // NOISE_VOL
extern u16 gUnk_03005B02;
extern u16 gEmuAudio_Noise_Lo; // NOISE_LO
extern u16 gEmuAudio_Noise_Hi; // NOISE_HI
extern u8 gUnk_03005B08;

extern u32 gUnk_03005B10[];
extern u32 gEmuAudio_Pulse1_Buffer[EMULATOR_AUDIO_BUFFER_SIZE];
extern u32 gEmuAudio_Pulse2_Buffer[EMULATOR_AUDIO_BUFFER_SIZE];
extern u32 gEmuAudio_Triangle_Buffer[EMULATOR_AUDIO_BUFFER_SIZE];
extern u32 gEmuAudio_Noise_Buffer[EMULATOR_AUDIO_BUFFER_SIZE];
extern u32 gEmuAudio_OutputBuffer0[EMULATOR_AUDIO_BUFFER_SIZE];
extern u32 gEmuAudio_OutputBuffer1[EMULATOR_AUDIO_BUFFER_SIZE];
extern u32 gEmuAudio_OutputBuffer2[EMULATOR_AUDIO_BUFFER_SIZE];
extern u16 gEmuAudio_Triangle_Enable;
extern u32 gUnk_03005FB4; // Set but never read
extern u8 gUnk_03005FB8;
extern u32 gEmuAudio_Timer1Reload;
extern u16 gEmuAudio_Noise_Enable;
extern u32 gEmuAudio_Pulse2_Frequency;
extern u32 gUnk_03005FC8; // Set but never read
extern u16 gEmuAudio_Pulse1_Enable;
extern u32 gEmuAudio_Pulse1_Frequency;
extern u16 gUnk_03005FD4;
extern u16 gEmuAudio_Pulse2_Enable;
extern u32 gUnk_03005FDC;

#endif /* PART2_STRUCT_H */
