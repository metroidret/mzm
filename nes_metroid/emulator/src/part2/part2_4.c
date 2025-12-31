#include "types.h"
#include "gba.h"
#include "macros.h"

extern u8 sUnk_030023DC[];
extern u8 sUnk_03002845;

extern u16 gUnk_03005A7A;
extern u32 gUnk_03005AD0;
extern u16 gUnk_03005AD4;
extern u16 gUnk_03005AD6;
extern u16 gUnk_03005AD8;
extern u16 gUnk_03005ADA;
extern u16 gUnk_03005ADC;
extern u16 gUnk_03005ADE;
extern u16 gUnk_03005AE0;
extern u16 gUnk_03005AE2;
extern u16 gUnk_03005AE4;
extern u16 gUnk_03005FB0;
extern u16 gUnk_03005FD4;
extern u32 gUnk_03005FDC;

void sub_03001318(void);
void sub_03001334(u32 arg0);
void sub_03001340(void);
void sub_030013C8(void);
void sub_030013F0(u16 arg0);
void sub_03001458(u8 arg0);
void sub_030014C8(u8 arg0);
void sub_030014E0(void);
void sub_03001518(u8 arg0);

void sub_03001318(void)
{
    if (gUnk_03005FB0 == 0)
    {
        gUnk_03005AD0 = 0;
    }
}

void sub_03001334(u32 arg0)
{
    gUnk_03005AD4 = arg0;
}

void sub_03001340(void)
{
    sub_03001334(sUnk_030023DC[gUnk_03005AE2 >> 3] * 4);
    if ((gUnk_03005ADE & 0x7F) && (gUnk_03005A7A & 4))
    {
        if (gUnk_03005FB0 == 0) {
            sub_03001318();
        }
        gUnk_03005FB0 = 1;
        gUnk_03005AD8 = 0;
    }
    gUnk_03005AD6 = (gUnk_03005ADE & 0x7F) + 1;
    gUnk_03005ADA = (gUnk_03005ADC + gUnk_03005ADA) >> 1;
}

void sub_030013C8(void)
{
    if ((gUnk_03005FB0 != 0) && (gUnk_03005AD8 == 0))
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

void sub_03001458(u8 arg0)
{
    u32 tmp;
    u32 tmp2;

    tmp2 = gUnk_03005AD6;
    gUnk_03005ADE = arg0;

    tmp = arg0 & 0x7F;
    if ((arg0 & 0x7F) == 0)
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
    else if ((gUnk_03005FB0 == 0) || (gUnk_03005AE4 != 0))
    {
        gUnk_03005AD6 = (arg0 & 0x7F) + 1;
        gUnk_03005AE4 = 0;
    }
}

void sub_030014C8(u8 arg0)
{
    gUnk_03005AE0 = arg0;
    sUnk_03002845 = 1;
}

void sub_030014E0(void)
{
    if (sUnk_03002845 != 0)
    {
        sUnk_03002845 -= 1;
        if (sUnk_03002845 == 0)
        {
            sub_030013F0(((gUnk_03005AE2 & 7) << 8) | gUnk_03005AE0);
        }
    }
}

void sub_03001518(u8 arg0)
{
    gUnk_03005AE2 = arg0;
    gUnk_03005AE4 = 1;

    sub_030013F0(((arg0 & 7) << 8) | gUnk_03005AE0);
    if (gUnk_03005FB0 == 0)
    {
        sub_03001340();
        return;
    }

    sub_03001334(sUnk_030023DC[gUnk_03005AE2 >> 3] * 4);
    gUnk_03005AD6 = (gUnk_03005ADE & 0x7F) + 1;
    gUnk_03005AD8 = 0;
}

void sub_03001594(void)
{
    gUnk_03005AD0 = 0;
    gUnk_03005FDC = 0;
    gUnk_03005AD4 = 0;
    gUnk_03005AD6 = 0;
    gUnk_03005FB0 = 0;
    gUnk_03005AD8 = 0;
    gUnk_03005ADA = 0;
    gUnk_03005ADC = 0;
    gUnk_03005ADE = 0;
    gUnk_03005AE0 = 0;
    gUnk_03005AE2 = 0;
    gUnk_03005AE4 = 0;
    gUnk_03005FD4 = 0;
    sUnk_03002845 = 0;
}
