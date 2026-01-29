#include "part2.h"
#include "types.h"
#include "gba.h"
#include "macros.h"

#include "structs/part2.h"

extern u8 sEmulatorAudio_LengthCounterTable[];

/**
 * @brief 030009A0 | Write to SQ1_HI
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse1_WriteHi(u8 value)
{
    gEmuAudio_Pulse1_Hi = value;

    sub_03000848(((value & 7) << 8) | gEmuAudio_Pulse1_Lo);
    if (gEmuAudio_Pulse1_Enable == 0)
    {
        sub_03000778();
    }
    sub_03000790();
}

/**
 * @brief 030009DC | Clear Pulse 1 variables
 * 
 */
void EmulatorAudio_Pulse1_ClearVariables(void)
{
    gUnk_03005A90 = 0;
    gEmuAudio_Pulse1_Frequency = 0;
    gUnk_03005A94 = 0;
    gUnk_03005A96 = 0;
    gEmuAudio_Pulse1_Vol = 0;
    gEmuAudio_Pulse1_Sweep = 0;
    gEmuAudio_Pulse1_Lo = 0;
    gEmuAudio_Pulse1_Hi = 0;
    gEmuAudio_Pulse1_Timer = 0;
    gUnk_03005AA2 = 0;
    gEmuAudio_Pulse1_Enable = 0;
    gUnk_03005AA4 = 0;
    gUnk_03005AA6 = 0;
    gEmuAudio_Pulse1_LengthCounter = 0;
    gUnk_03005AAA = 0;
    gUnk_03005AAC = 0;
    gUnk_03005AAD = 0;
}

// Real file split between part2_2 and part2_3

void sub_03000D20(void)
{
    gUnk_03005AB0 = 0;
}

/**
 * @brief 03000D2C | Set Pulse 2 length counter
 * 
 * @param lengthCounter Length counter
 */
void EmulatorAudio_Pulse2_SetLengthCounter(u32 lengthCounter)
{
    gEmuAudio_Pulse2_LengthCounter = lengthCounter;
}

void sub_03000D38(void)
{
    if (gUnk_03005AC4 != 0)
    {
        gUnk_03005AC6 = 1;
        return;
    }

    gUnk_03005AC6 = 0;
    if (gEmuAudio_Pulse2_Vol & 0x10)
    {
        gUnk_03005AB4 = gEmuAudio_Pulse2_Vol & 0xF;
    }
    else
    {
        gUnk_03005AB4 = 0xF;
    }

    gUnk_03005AC2 = 0xF;
    if (gEmuAudio_Pulse2_Enable != 0)
    {
        gUnk_03005ACA = 1;
    }
    else
    {
        gUnk_03005ACA = 4;
    }

    EmulatorAudio_Pulse2_SetLengthCounter(sEmulatorAudio_LengthCounterTable[gEmuAudio_Pulse2_Hi >> 3] * 4);
    if (gEmuAudio_SndChn & 2)
    {
        gEmuAudio_Pulse2_Enable = 1;
        gUnk_03005AC4 = 0;
    }
}

void sub_03000DEC(void)
{
    if ((gEmuAudio_Pulse2_Enable != 0) && (gUnk_03005AC4 == 0))
    {
        gUnk_03005AC4 = 2;
    }
}

void sub_03000E10(void)
{
    if (gUnk_03005ACC != 0)
    {
        sub_03000E40((gEmuAudio_Pulse2_Timer & 0xF00) | gEmuAudio_Pulse2_Lo);
    }
}

void sub_03000E40(u16 timer)
{
    u32 tmp;

    gUnk_03005ACC = 0;
    gEmuAudio_Pulse2_Timer = timer;
    if (timer == 0)
    {
        gUnk_03005AB4 = 0;
        return;
    }

    gEmuAudio_Pulse2_Frequency = NES_CLOCK_SPEED / (timer + 1);
    tmp = gEmuAudio_Pulse1_Frequency; // fake
    if (tmp == gEmuAudio_Pulse2_Frequency)
    {
        tmp = 1;
        gEmuAudio_Pulse2_Frequency -= 1;
    }
}

void sub_03000E94(u8 arg0)
{
    gUnk_03005AB4 = arg0;
    gUnk_03005AC2 = 1;
}

/**
 * @brief 03000EAC | Write to SQ2_VOL
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse2_WriteVolume(u8 value)
{
    u8 oldPulse2_ConstantVolumeFlag;
    u8 newPulse2_ConstantVolumeFlag;

    oldPulse2_ConstantVolumeFlag = gEmuAudio_Pulse2_Vol & 0x10;
    newPulse2_ConstantVolumeFlag = value & 0x10;

    gEmuAudio_Pulse2_Vol = value;
    gUnk_03005ACD = 0;

    // If duty cycle is 3 (25% negated), set to 1 (25%)
    if ((value & 0xC0) == 0xC0)
    {
        gEmuAudio_Pulse2_Vol = value & 0x7F;
    }

    if ((oldPulse2_ConstantVolumeFlag != 0) && (newPulse2_ConstantVolumeFlag == 0) && (gEmuAudio_Pulse2_Enable != 0))
    {
        gUnk_03005ACD = 4;
        gUnk_03005AC2 = 1;
    }
}

/**
 * @brief 03000F10 | Write to SQ2_SWEEP
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse2_WriteSweep(u8 value)
{
    gEmuAudio_Pulse2_Sweep = value;
    gUnk_03005ACA = 1;
}

/**
 * @brief 03000F10 | Write to SQ2_LO
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse2_WriteLo(u8 value)
{
    gEmuAudio_Pulse2_Lo = value;
    gUnk_03005ACC = 1;
}

/**
 * @brief 03000F40 | Write to SQ2_HI
 * 
 * @param value Value to write
 */
void EmulatorAudio_Pulse2_WriteHi(u8 value)
{
    gEmuAudio_Pulse2_Hi = value;

    sub_03000E40(((value & 7) << 8) | gEmuAudio_Pulse2_Lo);
    if (gEmuAudio_Pulse2_Enable == 0)
    {
        sub_03000D20();
    }
    sub_03000D38();
}

/**
 * @brief 03000F7C | Clear Pulse 2 variables
 * 
 */
void EmulatorAudio_Pulse2_ClearVariables(void)
{
    gUnk_03005AB0 = 0;
    gEmuAudio_Pulse2_Frequency = 0;
    gUnk_03005AB4 = 0;
    gUnk_03005AB6 = 0;
    gEmuAudio_Pulse2_Vol = 0;
    gEmuAudio_Pulse2_Sweep = 0;
    gEmuAudio_Pulse2_Lo = 0;
    gEmuAudio_Pulse2_Hi = 0;
    gEmuAudio_Pulse2_Timer = 0;
    gUnk_03005AC2 = 0;
    gEmuAudio_Pulse2_Enable = 0;
    gUnk_03005AC4 = 0;
    gUnk_03005AC6 = 0;
    gEmuAudio_Pulse2_LengthCounter = 0;
    gUnk_03005ACA = 0;
    gUnk_03005ACC = 0;
    gUnk_03005ACD = 0;
}
