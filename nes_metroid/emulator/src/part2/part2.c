#include "part2.h"
#include "types.h"
#include "gba.h"
#include "macros.h"

#include "structs/part2.h"

u32 sUnk_03002330[] = {
    0x1056, 0x1266, 0x1490, 0x15D9, 0x1872, 0x1B86, 0x1EEF, 0x20AB,
    0x24CC, 0x2BB2, 0x313C, 0x369F, 0x41F5, 0x5268, 0x611A, 0x8178
};

u32 sUnk_03002370 = DMA_32BIT | DMA_DEST_FIXED;

boolu8 sEmulatorAudio_Disabled = FALSE;

void (*sEmulatorAudio_ApuWriteFuncs[0x18])(u8) = {
    [NES_APU_REG_SQ1_VOL]    = EmulatorAudio_Pulse1_WriteVolume,
    [NES_APU_REG_SQ1_SWEEP]  = EmulatorAudio_Pulse1_WriteSweep,
    [NES_APU_REG_SQ1_LO]     = EmulatorAudio_Pulse1_WriteLo,
    [NES_APU_REG_SQ1_HI]     = EmulatorAudio_Pulse1_WriteHi,

    [NES_APU_REG_SQ2_VOL]    = EmulatorAudio_Pulse2_WriteVolume,
    [NES_APU_REG_SQ2_SWEEP]  = EmulatorAudio_Pulse2_WriteSweep,
    [NES_APU_REG_SQ2_LO]     = EmulatorAudio_Pulse2_WriteLo,
    [NES_APU_REG_SQ2_HI]     = EmulatorAudio_Pulse2_WriteHi,

    [NES_APU_REG_TRI_LINEAR] = EmulatorAudio_Triangle_WriteLinear,
    [NES_APU_REG_4009]       = EmulatorAudio_Stub,
    [NES_APU_REG_TRI_LO]     = EmulatorAudio_Triangle_WriteLo,
    [NES_APU_REG_TRI_HI]     = EmulatorAudio_Triangle_WriteHi,

    [NES_APU_REG_NOISE_VOL]  = EmulatorAudio_Noise_WriteVolume,
    [NES_APU_REG_400D]       = EmulatorAudio_Stub,
    [NES_APU_REG_NOISE_LO]   = EmulatorAudio_Noise_WriteLo,
    [NES_APU_REG_NOISE_HI]   = EmulatorAudio_Noise_WriteHi,

    [NES_APU_REG_DMC_FREQ]   = EmulatorAudio_Stub,
    [NES_APU_REG_DMC_RAW]    = EmulatorAudio_Stub,
    [NES_APU_REG_DMC_START]  = EmulatorAudio_Stub,
    [NES_APU_REG_DMC_LEN]    = EmulatorAudio_Stub,

    [NES_APU_REG_OAM_DMA]    = EmulatorAudio_Stub,
    [NES_APU_REG_SND_CHN]    = EmulatorAudio_SoundChannel_Write,
    [NES_APU_REG_JOY_1]      = EmulatorAudio_Stub,
    [NES_APU_REG_FRAME_CTR]  = EmulatorAudio_FrameCounter_Write
};

u32 sUnk_030023D8 = DMA_32BIT | DMA_DEST_FIXED;

/**
 * @brief 03000000 | Set new timer 1 reload value
 * 
 * @param timer1Reload Value for timer 1 reload
 */
void EmulatorAudio_SetTimer1Reload(u16 timer1Reload)
{
    if (gEmuAudio_Timer1Reload != timer1Reload)
    {
        gEmuAudio_Timer1Reload = timer1Reload;
        WRITE_16(REG_TM1CNT_L, -timer1Reload);
    }
}

u16 sub_03000024(u8 arg0)
{
    u32 ret;

    ret = 0x10000 - (0x01000AE0 / sUnk_03002330[arg0]);
    return ret;
}

u16 sub_03000050(u16 arg0)
{
    u32 var_r1;

    var_r1 = 0x01000AE0 / arg0;
    if (var_r1 > 0xFFFF)
    {
        var_r1 = 0xFFFF;
    }
    var_r1 = 0x10000 - var_r1;
    return var_r1;
}

/**
 * @brief 03000080 | Update the APU and audio output buffers
 * 
 */
void EmulatorAudio_UpdateApuAndOutput(void)
{
    WRITE_32(REG_DMA1_CNT, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED, 1 * sizeof(u32)));
    WRITE_16(REG_DMA1_CNT_H, sUnk_03002370);

    if (gEmuAudio_EnableOutput)
    {
        if (gEmuAudio_NumExtraOutputBuffers != 0)
        {
            switch (gEmuAudio_NumExtraOutputBuffers)
            {
                case 1:
                    if (gEmuAudio_CurrentOutputBuffer == 0)
                    {
                        gEmuAudio_CurrentOutputBuffer = 1;
                        EmulatorAudio_SetNewSource(gEmuAudio_OutputBuffer1Ptr);
                        gEmuAudio_ProcessApuAndMixBuffersFunc(gEmuAudio_OutputBuffer0Ptr, gEmuAudio_Timer1Reload);
                    }
                    else
                    {
                        gEmuAudio_CurrentOutputBuffer = 0;
                        EmulatorAudio_SetNewSource(gEmuAudio_OutputBuffer0Ptr);
                        gEmuAudio_ProcessApuAndMixBuffersFunc(gEmuAudio_OutputBuffer1Ptr, gEmuAudio_Timer1Reload);
                    }
                    break;

                case 2:
                    switch (gEmuAudio_CurrentOutputBuffer)
                    {
                        // Output buffer 1 and start mixing buffer 2
                        case 0:
                            gEmuAudio_CurrentOutputBuffer = 1;
                            EmulatorAudio_SetNewSource(gEmuAudio_OutputBuffer1Ptr);
                            gEmuAudio_ProcessApuAndMixBuffersFunc(gEmuAudio_OutputBuffer2Ptr, gEmuAudio_Timer1Reload);
                            break;

                        // Output buffer 2 and start mixing buffer 0
                        case 1:
                            gEmuAudio_CurrentOutputBuffer = 2;
                            EmulatorAudio_SetNewSource(gEmuAudio_OutputBuffer2Ptr);
                            gEmuAudio_ProcessApuAndMixBuffersFunc(gEmuAudio_OutputBuffer0Ptr, gEmuAudio_Timer1Reload);
                            break;

                        // Output buffer 0 and start mixing buffer 1
                        case 2:
                            gEmuAudio_CurrentOutputBuffer = 0;
                            EmulatorAudio_SetNewSource(gEmuAudio_OutputBuffer0Ptr);
                            gEmuAudio_ProcessApuAndMixBuffersFunc(gEmuAudio_OutputBuffer1Ptr, gEmuAudio_Timer1Reload);
                            break;
                    }
                    break;
            }
        }
        else
        {
            EmulatorAudio_SetNewSource(gEmuAudio_OutputBuffer0Ptr);
        }
    }
    else
    {
        EmulatorAudio_DisableTimers();
    }
}

/**
 * @brief 03000188 | Start timer 0 and timer 1
 * 
 */
void EmulatorAudio_StartTimers(u16 timer0Reload)
{
    WRITE_16(REG_TM1CNT_L, -gEmuAudio_Timer1Reload);
    WRITE_16(REG_TM1CNT_H, 0xC4); // Count up, IRQ enable, Start

    WRITE_16(REG_TM0CNT_L, timer0Reload);
    WRITE_16(REG_TM0CNT_H, 0x80); // Start
}

/**
 * @brief 030001B4 | Stop timer 0 and timer 1
 * 
 */
void EmulatorAudio_DisableTimers(void)
{
    WRITE_32(REG_TM0CNT_H, 0);
    WRITE_32(REG_TM1CNT_H, 0);
}

/**
 * @brief 030001C4 | Set new audio source
 * 
 * @param src Source
 */
void EmulatorAudio_SetNewSource(void* src)
{
    WRITE_16(REG_DMA1_SRC, LOW_SHORT((u32)src));
    WRITE_16(REG_DMA1_SRC + 2, HIGH_SHORT((u32)src));

    WRITE_16(REG_DMA1_DST, LOW_SHORT((u32)REG_FIFO_A));
    WRITE_16(REG_DMA1_DST + 2, HIGH_SHORT((u32)REG_FIFO_A));

    WRITE_16(REG_DMA1_CNT_H, DMA_ENABLE | DMA_START_SPECIAL | DMA_REPEAT);
}

void sub_030001F0(void* arg0, u16 arg1, u32 arg2, u8 arg3)
{
    WRITE_16(REG_SOUNDCNT_H, 0xB06); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 100% Vol, Sound 100% Vol

    gEmuAudio_Timer1Reload = arg2;
    gEmuAudio_EnableOutput = arg3;
    gEmuAudio_OutputBuffer0Ptr = arg0;
    gEmuAudio_NumExtraOutputBuffers = 0;

    EmulatorAudio_SetNewSource(arg0);
    EmulatorAudio_StartTimers(arg1);
}

void sub_0300023C(void* arg0, void* arg1, u16 arg2, s32 arg3, void* arg4)
{
    WRITE_16(REG_SOUNDCNT_H, 0xB06); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 100% Vol, Sound 100% Vol

    gEmuAudio_Timer1Reload = arg3;
    gEmuAudio_EnableOutput = TRUE;
    gEmuAudio_OutputBuffer0Ptr = arg0;
    gEmuAudio_OutputBuffer1Ptr = arg1;
    gEmuAudio_NumExtraOutputBuffers = 1;
    gEmuAudio_CurrentOutputBuffer = 0;
    gEmuAudio_ProcessApuAndMixBuffersFunc = arg4;

    EmulatorAudio_SetNewSource(arg0);
    EmulatorAudio_StartTimers(arg2);
}

/**
 * @brief 030002A4 | Set up the variables for audio output and update
 * 
 * @param outputBuffer0 Pointer to output buffer 0
 * @param outputBuffer1 Pointer to output buffer 1
 * @param outputBuffer2 Pointer to output buffer 2
 * @param timer0Reload Timer 0 reload value
 * @param timer1Reload Timer 1 reload value
 * @param func Pointer to APU/Buffer update function
 */
void EmulatorAudio_SetupOutput(void* outputBuffer0, void* outputBuffer1, void* outputBuffer2, u16 timer0Reload, u32 timer1Reload, void* func)
{
    WRITE_16(REG_SOUNDCNT_X, 0x80); // FIFO enable
    WRITE_16(REG_SOUNDCNT_L, 0);
    WRITE_16(REG_SOUNDCNT_H, 0xB00); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 50% Vol, Sound 25% Vol
    WRITE_16(REG_SOUNDCNT_H, 0xB04); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 100% Vol, Sound 25% Vol

    gEmuAudio_Timer1Reload = timer1Reload;
    gEmuAudio_EnableOutput = TRUE;
    gEmuAudio_OutputBuffer0Ptr = outputBuffer0;
    gEmuAudio_OutputBuffer1Ptr = outputBuffer1;
    gEmuAudio_OutputBuffer2Ptr = outputBuffer2;
    gEmuAudio_NumExtraOutputBuffers = 2;
    gEmuAudio_CurrentOutputBuffer = 0;
    gEmuAudio_Timer0Reload = timer0Reload;
    gEmuAudio_ProcessApuAndMixBuffersFunc = func;

    EmulatorAudio_SetNewSource(outputBuffer0);
    EmulatorAudio_StartTimers(timer0Reload);
}

/**
 * @brief 03000330 | Stop timer 0 and timer 1
 * 
 */
void EmulatorAudio_CallDisableTimers(void)
{
    EmulatorAudio_DisableTimers();
}

void sub_0300033C(u32 arg0)
{
    gUnk_03005FB4 = arg0;
}

void sub_03000348(u32 arg0)
{
    gUnk_03005FC8 = arg0;
}

void sub_03000354(u32 arg0, u32 arg1)
{
    sub_0300033C(arg0);
    sub_03000348(arg1);
}

void sub_03000368(u32 arg0)
{
    gUnk_03005FB4 = arg0;
    gUnk_03005FC8 = arg0 + 0x2000;
}

/**
 * @brief 03000380 | Get the active channels
 * 
 * @param apuRegister APU register to write to (NES address)
 * @return u8 Active channels bitflags
 */
u8 EmulatorAudio_GetActiveChannels(EmulatorAudioApuRegisters apuRegister) 
{
    u8 activeChannels;
    u8 i;
    u16 enabledChannels[5];

    activeChannels = 0;

    if (apuRegister == (NES_APU_REG_BASE | NES_APU_REG_SND_CHN))
    {
        enabledChannels[0] = (u8)gEmuAudio_Pulse1_Enable;
        enabledChannels[1] = (u8)gEmuAudio_Pulse2_Enable;
        enabledChannels[2] = gEmuAudio_Triangle_Enable;
        enabledChannels[3] = (u8)gEmuAudio_Noise_Enable;

        for (i = 0; i < 4; i++)
        {
            if (gEmuAudio_ActiveChannels[i] != 0)
            {
                activeChannels |= (gEmuAudio_ActiveChannels[i] - 1) << i;
            }
            else
            {
                activeChannels |= enabledChannels[i] << i;
            }
        }

        do { activeChannels |= (u8)enabledChannels[4] << 4; } while(0); // what?
    }

    return activeChannels;
}

/**
 * @brief 03000404 | Stub for invalid/unhandled register writes
 * 
 * @param value (Unused) Value
 */
void EmulatorAudio_Stub(u8 value)
{
    return;
}

/**
 * @brief 03000408 | Write to APU register
 * 
 * @param apuRegister APU register to write to (NES address)
 * @param value Value to write to APU register
 */
void EmulatorAudio_WriteToApu(EmulatorAudioApuRegisters apuRegister, u8 value)
{
    u32 i;

    if (sEmulatorAudio_Disabled)
        return;

    apuRegister -= NES_APU_REG_BASE;
    if (apuRegister < NES_APU_REG_COUNT)
    {
        sEmulatorAudio_ApuWriteFuncs[apuRegister](value);
        // If writing to a length counter register
        // Write 2 to gEmuAudio_ActiveChannels
        if ((apuRegister & 3) == 3)
        {
            gEmuAudio_ActiveChannels[apuRegister >> 2] = 2;
        }
    }

    // SND_CHN register
    if (apuRegister == NES_APU_REG_SND_CHN)
    {
        // If sound channel enabled
        // Write 1 to gEmuAudio_ActiveChannels
        for (i = 0; i < 4; i++)
        {
            if (value & 1)
            {
                gEmuAudio_ActiveChannels[i] = 1;
            }
            value >>= 1;
        }
    }
}

/**
 * @brief 0300047C | Write byte
 * 
 * @param dst Destination
 * @param val Value to write
 */
void EmulatorAudio_Write8(u8* dst, u8 val)
{
    WRITE_8(dst, val);
}

/**
 * @brief 03000484 | (Unused) Read byte
 * 
 * @param src Source
 * @return u8 Value from source
 */
u8 EmulatorAudio_Read8(u8* src)
{
    return READ_8(src);
}

/**
 * @brief 03000488 | Initialize audio engine
 * 
 */
void EmulatorAudio_Initialize(void)
{
    sEmulatorAudio_Disabled = FALSE;
    EmulatorAudio_ClearChannels();

    EmulatorAudio_Write8(REG_SOUNDCNT_X, 0xFF); // FIFO enable
    EmulatorAudio_Write8(REG_SOUNDCNT_L, 0x77); // Sound 1-4 Master Volume Left/Right Enable
    EmulatorAudio_Write8(REG_SOUNDCNT_L + 1, 0xFF); // Sound 1-4 Flags Left/Right Enable
    WRITE_16(REG_SOUNDBIAS, (READ_16(REG_SOUNDBIAS) & 0x3FF) | 0x4000); // Set Resolution / Sampling to 8bit / 65.536kHz

    EmulatorAudio_SetupEngine();
}

/**
 * @brief 030004E0 | Timer 1 interrupt
 * 
 */
void EmulatorAudio_Timer1Callback(void)
{
    u32 i;

    EmulatorAudio_UpdateApuAndOutput();

    for (i = 0; i < 5; i++)
    {
        gEmuAudio_ActiveChannels[i] = 0;
    }
}

/**
 * @brief 03000500 | Disable audio upon reset
 * 
 */
void EmulatorAudio_Disable(void)
{
    EmulatorAudio_WriteToApu(NES_APU_REG_BASE | NES_APU_REG_SND_CHN, 0);
    sEmulatorAudio_Disabled = TRUE;
    EmulatorAudio_CallDisableTimers();

    WRITE_32(REG_DMA1_CNT, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED, 1 * sizeof(u32)));
    WRITE_16(REG_DMA1_CNT_H, sUnk_030023D8);
}

/**
 * @brief 0300053C | Reset audio
 * 
 */
void EmulatorAudio_Reset(void)
{
    WRITE_32(REG_FIFO_A, 0);
    WRITE_32(REG_FIFO_B, 0);

    EmulatorAudio_SetupEngine();
    EmulatorAudio_ClearChannels();
    sEmulatorAudio_Disabled = FALSE;
}

/**
 * @brief 03000564 | Clear channel variables
 * 
 */
void EmulatorAudio_ClearChannels(void)
{
    u32 i;

    for (i = 0; i < 5; i++)
    {
        gEmuAudio_ActiveChannels[i] = 0;
    }

    EmulatorAudio_Pulse1_ClearVariables();
    EmulatorAudio_Pulse2_ClearVariables();
    EmulatorAudio_Triangle_ClearVariables();
    EmulatorAudio_Noise_ClearVariables();
}
