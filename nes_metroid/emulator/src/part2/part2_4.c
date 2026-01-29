#include "part2.h"
#include "types.h"
#include "gba.h"
#include "macros.h"

#include "structs/part2.h"

extern u8 sEmulatorAudio_LengthCounterTable[];
extern u8 sUnk_03002845;

void sub_03001318(void)
{
    if (gEmuAudio_Triangle_Enable == 0)
    {
        gUnk_03005AD0 = 0;
    }
}

/**
 * @brief 03001334 | Set Triangle length counter
 * 
 * @param lengthCounter Length counter
 */
void EmulatorAudio_Triangle_SetLengthCounter(u32 lengthCounter)
{
    gEmuAudio_Triangle_LengthCounter = lengthCounter;
}

void sub_03001340(void)
{
    EmulatorAudio_Triangle_SetLengthCounter(sEmulatorAudio_LengthCounterTable[gEmuAudio_Triangle_Hi >> 3] * 4);
    if ((gEmuAudio_Triangle_Linear & 0x7F) && (gEmuAudio_SndChn & 4))
    {
        if (gEmuAudio_Triangle_Enable == 0) {
            sub_03001318();
        }
        gEmuAudio_Triangle_Enable = 1;
        gUnk_03005AD8 = 0;
    }
    gUnk_03005AD6 = (gEmuAudio_Triangle_Linear & 0x7F) + 1;
    gUnk_03005ADA = (gUnk_03005ADC + gUnk_03005ADA) >> 1;
}

void sub_030013C8(void)
{
    if ((gEmuAudio_Triangle_Enable != 0) && (gUnk_03005AD8 == 0))
    {
        gUnk_03005AD8 = gUnk_03005ADA;
    }
}

void sub_030013F0(u16 arg0)
{
    gUnk_03005FD4 = arg0;
    sUnk_03002845 = 0;
    gUnk_03005FD4 = arg0; // fake/useless
    if (arg0 == 0)
    {
        gUnk_03005ADC = 0;
        return;
    }

    gUnk_03005FDC = 0x6D3D34U / (arg0 + 1);

    gUnk_03005ADC = 7;
    if (arg0 < 0x40)
    {
        gUnk_03005ADC = 6;
    }
    if (arg0 < 0x20)
    {
        gUnk_03005ADC -= 1;
    }
    if (arg0 < 0x10)
    {
        gUnk_03005ADC -= 1;
    }
}

/**
 * @brief 03001458 | Write to TRI_LINEAR
 * 
 * @param value Value to write
 */
void EmulatorAudio_Triangle_WriteLinear(u8 value)
{
    u32 tmp;
    u32 tmp2;

    tmp2 = gUnk_03005AD6;
    gEmuAudio_Triangle_Linear = value;

    tmp = value & 0x7F;
    if ((value & 0x7F) == 0)
    {
        tmp = tmp2 & 0x80;
        if (((tmp2 & 0x80) == 0) && (gUnk_03005AE4 != 0))
        {
            gUnk_03005AD6 = 1;
            gUnk_03005AE4 = 0;
        }
        else
        {
            sub_030013C8();
            gUnk_03005AE4 = 0;
        }
    }
    else if ((gEmuAudio_Triangle_Enable == 0) || (gUnk_03005AE4 != 0))
    {
        gUnk_03005AD6 = (value & 0x7F) + 1;
        gUnk_03005AE4 = 0;
    }
}

/**
 * @brief 030014C8 | Write to TRI_LO
 * 
 * @param value Value to write
 */
void EmulatorAudio_Triangle_WriteLo(u8 value)
{
    gEmuAudio_Triangle_Lo = value;
    sUnk_03002845 = 1;
}

void sub_030014E0(void)
{
    if (sUnk_03002845 != 0)
    {
        sUnk_03002845 -= 1;
        if (sUnk_03002845 == 0)
        {
            sub_030013F0(((gEmuAudio_Triangle_Hi & 7) << 8) | gEmuAudio_Triangle_Lo);
        }
    }
}

/**
 * @brief 03001518 | Write to TRI_HI
 * 
 * @param value Value to write
 */
void EmulatorAudio_Triangle_WriteHi(u8 value)
{
    gEmuAudio_Triangle_Hi = value;
    gUnk_03005AE4 = 1;

    sub_030013F0(((value & 7) << 8) | gEmuAudio_Triangle_Lo);
    if (gEmuAudio_Triangle_Enable == 0)
    {
        sub_03001340();
        return;
    }

    EmulatorAudio_Triangle_SetLengthCounter(sEmulatorAudio_LengthCounterTable[gEmuAudio_Triangle_Hi >> 3] * 4);
    gUnk_03005AD6 = (gEmuAudio_Triangle_Linear & 0x7F) + 1;
    gUnk_03005AD8 = 0;
}

/**
 * @brief 03001594 | Clear Triangle variables
 * 
 */
void EmulatorAudio_Triangle_ClearVariables(void)
{
    gUnk_03005AD0 = 0;
    gUnk_03005FDC = 0;
    gEmuAudio_Triangle_LengthCounter = 0;
    gUnk_03005AD6 = 0;
    gEmuAudio_Triangle_Enable = 0;
    gUnk_03005AD8 = 0;
    gUnk_03005ADA = 0;
    gUnk_03005ADC = 0;
    gEmuAudio_Triangle_Linear = 0;
    gEmuAudio_Triangle_Lo = 0;
    gEmuAudio_Triangle_Hi = 0;
    gUnk_03005AE4 = 0;
    gUnk_03005FD4 = 0;
    sUnk_03002845 = 0;
}
