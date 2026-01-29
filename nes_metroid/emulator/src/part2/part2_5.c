#include "part2.h"
#include "types.h"
#include "gba.h"
#include "macros.h"

#include "structs/part2.h"

extern u8 sEmulatorAudio_LengthCounterTable[];
extern u16 sUnk_03002846;
extern u32 sUnk_03002988;
extern u32 sEmulatorAudio_NoiseSampleRateTable[];

void sub_03001730(void)
{
    gUnk_03005AEC = 0;
}

void sub_0300173C(void)
{
    u32 var_r3;

    for (var_r3 = 0; var_r3 < 3; var_r3++)
    {
        gUnk_03005B10[var_r3] = 0x10000;
    }

    for (var_r3 = 3; var_r3 < 0x10; var_r3++)
    {
        gUnk_03005B10[var_r3] = sEmulatorAudio_NoiseSampleRateTable[var_r3];
        if (gUnk_03005B10[var_r3] > 0xFFFF)
        {
            gUnk_03005B10[var_r3] = 0x10000;
        }
    }
}

/**
 * @brief 03001788 | Set Noise length counter
 * 
 * @param lengthCounter Length counter
 */
void EmulatorAudio_Noise_SetLengthCounter(u32 lengthCounter)
{
    gEmuAudio_Noise_LengthCounter = lengthCounter;
}

void sub_03001794(void)
{
    u32 var_r4;
    u32 var_r5;

    if (gEmuAudio_SndChn & 8)
    {
        gEmuAudio_Noise_Enable = 1;
    }

    if (gEmuAudio_Noise_Vol & 0x10)
    {
        gUnk_03005AF4 = gEmuAudio_Noise_Vol & 0xF;
    }
    else
    {
        gUnk_03005AF4 = 0xF;
    }

    gUnk_03005AF8 = gEmuAudio_Noise_Vol & 0xF;
    var_r4 = sEmulatorAudio_LengthCounterTable[gEmuAudio_Noise_Hi >> 3];
    if ((sUnk_03002988 == 0x7F) && (var_r4 == 1))
    {
        var_r4 = 2;
    }
    
    if (gUnk_03005AF6 > 0xB)
    {
        var_r5 = 2;
    }
    else
    {
        var_r5 = 0;
    }
    EmulatorAudio_Noise_SetLengthCounter((sEmulatorAudio_LengthCounterTable[gEmuAudio_Noise_Hi >> 3] * 4) + var_r5);
    sUnk_03002988 = var_r4;
    EmulatorAudio_Noise_SetLengthCounter((var_r4 * 4) + var_r5);
}

void sub_03001840(void)
{
    if ((gEmuAudio_Noise_Enable != 0) && (gUnk_03005AFE == 0))
    {
        gUnk_03005AFE = 2;
    }
}

void sub_03001864(u8 arg0)
{
    gUnk_03005AF4 = arg0;
    gUnk_03005AF8 = 1;
}

/**
 * @brief 0300187C | Write to NOISE_VOL
 * 
 * @param value Value to write
 */
void EmulatorAudio_Noise_WriteVolume(u8 value)
{
    u8 oldNoise_ConstantVolumeFlag;
    u8 newNoise_ConstantVolumeFlag;

    oldNoise_ConstantVolumeFlag = gEmuAudio_Noise_Vol & 0x10;
    newNoise_ConstantVolumeFlag = value & 0x10;

    gEmuAudio_Noise_Vol = value;
    gUnk_03005B08 = 0;

    if (newNoise_ConstantVolumeFlag == 1)
    {
        gUnk_03005AF4 = value & 0xF;
    }
    else if ((oldNoise_ConstantVolumeFlag != 0) && (gEmuAudio_Noise_Enable != 0))
    {
        gUnk_03005B08 = 4;
        gUnk_03005AF8 = value & 0xF;
    }
}

/**
 * @brief 030018E0 | Write to NOISE_LO
 * 
 * @param value Value to write
 */
void EmulatorAudio_Noise_WriteLo(u8 value)
{
    gEmuAudio_Noise_Lo = value;
    gUnk_03005AF6 = value & 0xF;
    gUnk_03005AF0 = gUnk_03005B10[gUnk_03005AF6];

    if (value & 0x80)
    {
        sUnk_03002846 = 0x40;
        gUnk_03005AE8 = 1;
    }
    else
    {
        sUnk_03002846 = 0x4000;
    }
}

/**
 * @brief 03001944 | Write to NOISE_HI
 * 
 * @param value Value to write
 */
void EmulatorAudio_Noise_WriteHi(u8 value)
{
    if (gEmuAudio_Noise_Lo & 0x80)
    {
        sUnk_03002846 = 0x40;
        gUnk_03005AE8 = 1;
    }
    else
    {
        sUnk_03002846 = 0x4000;
    }

    gEmuAudio_Noise_Hi = value;
    sub_03001794();
}

/**
 * @brief 03001990 | Clear Noise variables
 * 
 */
void EmulatorAudio_Noise_ClearVariables(void)
{
    gUnk_03005AE8 = 1;
    gUnk_03005AEC = 0;
    gUnk_03005AF0 = 0;
    gUnk_03005AF4 = 0;
    gUnk_03005AF6 = 0;
    gUnk_03005AF8 = 0;
    gEmuAudio_Noise_LengthCounter = 0;
    gUnk_03005AFC = 0;
    sUnk_03002846 = 0x8000;
    gEmuAudio_Noise_Enable = 0;
    gUnk_03005AFE = 0;
    gEmuAudio_Noise_Vol = 0;
    gUnk_03005B02 = 0;
    gEmuAudio_Noise_Lo = 0;
    gEmuAudio_Noise_Hi = 0;
    gUnk_03005B08 = 0;
}

// File split?

/**
 * @brief 03001C10 | Write to SND_CHN
 * 
 * @param value Value to write
 */
void EmulatorAudio_SoundChannel_Write(u8 value)
{
    gEmuAudio_SndChn = value;

    if (!(value & 1))
    {
        sub_03000824();
    }
    if (!(value & 2))
    {
        sub_03000DEC();
    }
    if (!(value & 4))
    {
        sub_030013C8();
    }
    if (!(value & 8))
    {
        sub_03001840();
    }
}

/**
 * @brief 03001C58 | Write to FRAME_CTR
 * 
 * @param value Value to write
 */
void EmulatorAudio_FrameCounter_Write(u8 value)
{
    gEmuAudio_FrameCtr = value;

    if (value & 0x80)
    {
        EmulatorAudio_SetTimer1Reload(0xA0);
    }
    else
    {
        EmulatorAudio_SetTimer1Reload(0x80);
    }

    if (gUnk_03005AA2 > 1)
    {
        gUnk_03005AA2 -= 1;
    }
    if (gUnk_03005AC2 > 1)
    {
        gUnk_03005AC2 -= 1;
    }
    if (gUnk_03005AF8 > 1)
    {
        gUnk_03005AF8 -= 1;
    }
    if (gUnk_03005AD6 > 1)
    {
        gUnk_03005AD6 -= 1;
    }
    if (gUnk_03005AAA > 1)
    {
        gUnk_03005AAA -= 1;
    }
    if (gUnk_03005ACA > 1)
    {
        gUnk_03005ACA -= 1;
    }

    if (gEmuAudio_Pulse1_LengthCounter != 0)
    {
        gEmuAudio_Pulse1_LengthCounter -= 1;
    }
    if (gEmuAudio_Pulse2_LengthCounter != 0)
    {
        gEmuAudio_Pulse2_LengthCounter -= 1;
    }
    if (gEmuAudio_Triangle_LengthCounter != 0)
    {
        gEmuAudio_Triangle_LengthCounter -= 1;
    }
    if (gEmuAudio_Noise_LengthCounter != 0)
    {
        gEmuAudio_Noise_LengthCounter -= 1;
    }
}

void sub_03001D24(u32 arg0)
{
    gUnk_03005FB8 = arg0;
}

/**
 * @brief 03001D30 | Handle processing APU and mixing APU and output buffers
 * 
 * @param outputBuffer Pointer to output buffer
 * @param timer1Reload Value from timer 1 reload
 */
void EmulatorAudio_ProcessApuAndMixBuffers(void* outputBuffer, u32 timer1Reload)
{
    u32 var_r5;
    void* pulse1_Buffer;
    void* pulse2_Buffer;
    void* triangle_Buffer;
    void* noise_Buffer;

    pulse1_Buffer = gEmuAudio_Pulse1_Buffer;
    pulse2_Buffer = gEmuAudio_Pulse2_Buffer;
    triangle_Buffer = gEmuAudio_Triangle_Buffer;
    noise_Buffer = gEmuAudio_Noise_Buffer;

    var_r5 = 0;

    if (gUnk_03005FB8 != 0)
    {
        sub_03000634(0xF0000000, timer1Reload);
        sub_03000704(outputBuffer, timer1Reload);
        return;
    }

    if (gEmuAudio_Pulse1_Enable != 0)
    {
        sub_03000948();
        sub_03000A6C(pulse1_Buffer, timer1Reload);
        if (gUnk_03005AAD != 0)
        {
            gUnk_03005A94 = 0xF;
            gUnk_03005AAD = 0;
        }
        if (gEmuAudio_Pulse1_Sweep & 0x80)
        {
            sub_03000848(gEmuAudio_Pulse1_Timer);
        }
        if (gEmuAudio_Pulse1_LengthCounter != 0)
        {
            gEmuAudio_Pulse1_LengthCounter -= 1;
        }
        if (!(gEmuAudio_Pulse1_Vol & 0x20) && (gEmuAudio_Pulse1_LengthCounter == 0))
        {
            sub_03000824();
        }
    }

    if (gUnk_03005AA4 != 0)
    {
        gUnk_03005AA4 -= 1;
        if (gUnk_03005AA4 == 0)
        {
            var_r5 |= 0x80000000;
            gEmuAudio_Pulse1_Enable = 0;
            if (gUnk_03005AA6 != 0)
            {
                sub_03000790();
            }
        }
    }

    if (gEmuAudio_Pulse2_Enable != 0)
    {
        sub_03000E10();
        sub_0300100C(pulse2_Buffer, timer1Reload);
        if (gUnk_03005ACD != 0)
        {
            gUnk_03005AB4 = 0xF;
            gUnk_03005ACD = 0;
        }
        if (gEmuAudio_Pulse2_Sweep & 0x80)
        {
            sub_03000E40(gEmuAudio_Pulse2_Timer);
        }
        if (gEmuAudio_Pulse2_LengthCounter != 0)
        {
            gEmuAudio_Pulse2_LengthCounter -= 1;
        }
        if (!(gEmuAudio_Pulse2_Vol & 0x20) && (gEmuAudio_Pulse2_LengthCounter == 0))
        {
            sub_03000DEC();
        }
    }

    if (gUnk_03005AC4 != 0)
    {
        gUnk_03005AC4 -= 1;
        if (gUnk_03005AC4 == 0)
        {
            var_r5 |= 0x40000000;
            gEmuAudio_Pulse2_Enable = 0;
            if (gUnk_03005AC6 != 0)
            {
                sub_03000D38();
            }
        }
    }

    if (gEmuAudio_Triangle_Enable != 0)
    {
        sub_030014E0();
        if ((gUnk_03005FD4 == 0) && (gUnk_03005ADA == 0))
        {
            var_r5 |= 0x20000000;
        }
        else
        {
            sub_0300160C(triangle_Buffer, timer1Reload);
        }
        if (gEmuAudio_Triangle_LengthCounter != 0)
        {
            gEmuAudio_Triangle_LengthCounter -= 1;
        }
        if (gUnk_03005AD8 == 0)
        {
            if (gUnk_03005ADC > gUnk_03005ADA)
            {
                gUnk_03005ADA += 1;
            }
            else if (gUnk_03005ADC < gUnk_03005ADA)
            {
                gUnk_03005ADA -= 1;
            }
        }
        if (!(gEmuAudio_Triangle_Linear & 0x80) && (gEmuAudio_Triangle_LengthCounter == 0))
        {
            sub_030013C8();
        }
    }

    if (gUnk_03005AD8 != 0)
    {
        gUnk_03005AD8 >>= 1;
        gUnk_03005ADA = gUnk_03005AD8;
        if (gUnk_03005ADA == 0)
        {
            var_r5 |= 0x20000000;
            gEmuAudio_Triangle_Enable = 0;
        }
    }

    if (gEmuAudio_Noise_Enable != 0)
    {
        sub_03001A24(noise_Buffer, timer1Reload);
        if (gUnk_03005B08 != 0)
        {
            gUnk_03005AF4 = 0xF;
            gUnk_03005B08 = 0;
        }
        if (gEmuAudio_Noise_LengthCounter != 0)
        {
            gEmuAudio_Noise_LengthCounter -= 1;
        }
        if (!(gEmuAudio_Noise_Vol & 0x20) && (gEmuAudio_Noise_LengthCounter == 0))
        {
            sub_03001840();
        }
    }

    if (gUnk_03005AFE != 0)
    {
        gUnk_03005AFE -= 1;
        if (gUnk_03005AFE == 0)
        {
            var_r5 |= 0x10000000;
            gEmuAudio_Noise_Enable = 0;
        }
        else
        {
            sub_0300059C(noise_Buffer, timer1Reload, timer1Reload >> 4);
        }
    }

    sub_03000634(var_r5, timer1Reload);
    sub_03000704(outputBuffer, timer1Reload);
    sub_030006CC(outputBuffer, timer1Reload);
}

/**
 * @brief 0300203C | Initialize engine buffers and variables
 * 
 */
void EmulatorAudio_SetupEngine(void)
{
    u32 i;
    u32* pulse1_Buffer;

    pulse1_Buffer = gEmuAudio_Pulse1_Buffer; // fake
    sub_0300173C();

    for (i = 0; i < EMULATOR_AUDIO_BUFFER_SIZE; i++)
    {
        gEmuAudio_Pulse1_Buffer[i] = 0;
        gEmuAudio_Pulse2_Buffer[i] = 0;
        gEmuAudio_Triangle_Buffer[i] = 0;
        gEmuAudio_Noise_Buffer[i] = 0;
        gEmuAudio_OutputBuffer0[i] = 0;
        gEmuAudio_OutputBuffer1[i] = 0;
        gEmuAudio_OutputBuffer2[i] = 0;
    }

    gEmuAudio_Pulse1_BufferPtr = gEmuAudio_Pulse1_Buffer;
    gEmuAudio_Pulse2_BufferPtr = gEmuAudio_Pulse2_Buffer;
    gEmuAudio_Triangle_BufferPtr = gEmuAudio_Triangle_Buffer;
    gEmuAudio_Noise_BufferPtr = gEmuAudio_Noise_Buffer;

    gUnk_03005A90 = 0;
    gEmuAudio_Pulse1_Frequency = 0;
    gUnk_03005AD0 = 0;
    gUnk_03005FDC = 0;
    gUnk_03005AE8 = 0x4400;
    gUnk_03005A96 = 0;
    gUnk_03005AB6 = 0;

    sub_03000824();
    sub_03000DEC();
    sub_030013C8();
    sub_03001840();

    sub_03000634(0xF0000000, 0xA0);
    sub_03000618(pulse1_Buffer, 0xA0);

    sub_03000704(gEmuAudio_OutputBuffer0, sizeof(gEmuAudio_OutputBuffer0));
    sub_03000704(gEmuAudio_OutputBuffer1, sizeof(gEmuAudio_OutputBuffer1));
    sub_03000704(gEmuAudio_OutputBuffer2, sizeof(gEmuAudio_OutputBuffer2));

    sub_03000618(gEmuAudio_OutputBuffer0, sizeof(gEmuAudio_OutputBuffer0));
    sub_03000618(gEmuAudio_OutputBuffer1, sizeof(gEmuAudio_OutputBuffer1));
    sub_03000618(gEmuAudio_OutputBuffer2, sizeof(gEmuAudio_OutputBuffer2));

    gEmuAudio_SndChn = 0;
    gEmuAudio_FrameCtr = 0;
    EmulatorAudio_SetupOutput(gEmuAudio_OutputBuffer0, gEmuAudio_OutputBuffer1, gEmuAudio_OutputBuffer2,
                            sub_03000050(0x8000), 0xA0, &EmulatorAudio_ProcessApuAndMixBuffers);
}
