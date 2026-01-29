#include "part2.h"
#include "types.h"
#include "gba.h"
#include "macros.h"

#include "structs/part2.h"

extern u8 sEmulatorAudio_LengthCounterTable[];

void sub_03000778(void)
{
    gUnk_03005A90 = 0;
}

/**
 * @brief 03000784 | Set Pulse 1 length counter
 * 
 * @param lengthCounter Length counter
 */
void EmulatorAudio_Pulse1_SetLengthCounter(u32 lengthCounter)
{
    gEmuAudio_Pulse1_LengthCounter = lengthCounter;
}

void sub_03000790(void)
{
    if (gUnk_03005AA4 != 0)
    {
        gUnk_03005AA6 = 1;
        return;
    }

    gUnk_03005AA6 = 0;
    if (gEmuAudio_Pulse1_Vol & 0x10)
    {
        gUnk_03005A94 = gEmuAudio_Pulse1_Vol & 0xF;
    }
    else
    {
        gUnk_03005A94 = 0xF;
    }

    gUnk_03005AA2 = 0xF;
    EmulatorAudio_Pulse1_SetLengthCounter(sEmulatorAudio_LengthCounterTable[gEmuAudio_Pulse1_Hi >> 3] * 4);
    if (gEmuAudio_SndChn & 1)
    {
        gEmuAudio_Pulse1_Enable = 1;
        gUnk_03005AA4 = 0;
    }
}

void sub_03000824(void)
{
    if ((gEmuAudio_Pulse1_Enable != 0) && (gUnk_03005AA4 == 0))
    {
        gUnk_03005AA4 = 2;
    }
}

void sub_03000848(u16 timer)
{
    u32 tmp;

    tmp = 1;
    gUnk_03005AAC = 0;
    gEmuAudio_Pulse1_Timer = timer;
    if (timer == 0)
    {
        gUnk_03005A94 = 0;
        return;
    }

    gEmuAudio_Pulse1_Frequency = NES_CLOCK_SPEED / (timer + 1);
    tmp = gEmuAudio_Pulse2_Frequency; // fake
    if (gEmuAudio_Pulse1_Frequency == gEmuAudio_Pulse2_Frequency)
    {
        gEmuAudio_Pulse2_Frequency -= 1;
    }
}

void sub_0300089C(u8 arg0)
{
    gUnk_03005A94 = arg0;
    gUnk_03005AA2 = 1;
}

/**
 * @brief 030008B4 | Write to SQ1_VOL
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse1_WriteVolume(u8 value)
{
    u8 oldPulse1_ConstantVolumeFlag;
    u8 newPulse1_ConstantVolumeFlag;

    oldPulse1_ConstantVolumeFlag = gEmuAudio_Pulse1_Vol & 0x10;
    newPulse1_ConstantVolumeFlag = value & 0x10;

    gEmuAudio_Pulse1_Vol = value;
    gUnk_03005AAD = 0;

    // If duty cycle is 3 (25% negated), set to 1 (25%)
    if ((value & 0xC0) == 0xC0)
    {
        gEmuAudio_Pulse1_Vol = value & 0x7F;
    }

    if ((oldPulse1_ConstantVolumeFlag != 0) && (newPulse1_ConstantVolumeFlag == 0) && (gEmuAudio_Pulse1_Enable != 0))
    {
        gUnk_03005AAD = 4;
        gUnk_03005AA2 = 1;
    }
}

/**
 * @brief 03000918 | Write to SQ1_SWEEP
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse1_WriteSweep(u8 value)
{
    gEmuAudio_Pulse1_Sweep = value;
    gUnk_03005AAA = 1;
}

/**
 * @brief 03000930 | Write to SQ1_LO
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse1_WriteLo(u8 value)
{
    gEmuAudio_Pulse1_Lo = value;
    gUnk_03005AAC = 1;
}

void sub_03000948(void)
{
    if (gUnk_03005AAC != 0)
    {
        sub_03000848((gEmuAudio_Pulse1_Timer & 0xF00) | gEmuAudio_Pulse1_Lo);
    }
}
