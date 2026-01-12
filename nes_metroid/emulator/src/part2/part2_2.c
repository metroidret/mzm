#include "part2.h"
#include "types.h"
#include "gba.h"
#include "macros.h"

#include "structs/part2.h"

extern u8 sUnk_030023DC[];

void sub_03000778(void)
{
    gUnk_03005A90 = 0;
}

void sub_03000784(u32 arg0)
{
    gUnk_03005AA8 = arg0;
}

void sub_03000790(void)
{
    if (gUnk_03005AA4 != 0)
    {
        gUnk_03005AA6 = 1;
        return;
    }
    gUnk_03005AA6 = 0;

    if (gUnk_03005A98 & 0x10)
    {
        gUnk_03005A94 = gUnk_03005A98 & 0xF;
    }
    else
    {
        gUnk_03005A94 = 0xF;
    }

    gUnk_03005AA2 = 0xF;
    sub_03000784(sUnk_030023DC[gUnk_03005A9E >> 3] * 4);
    if (gUnk_03005A7A & 1)
    {
        gUnk_03005FCC = 1;
        gUnk_03005AA4 = 0;
    }
}

void sub_03000824(void)
{
    if ((gUnk_03005FCC != 0) && (gUnk_03005AA4 == 0))
    {
        gUnk_03005AA4 = 2;
    }
}

void sub_03000848(u16 arg0)
{
    u32 tmp;

    tmp = 1;
    gUnk_03005AAC = 0;
    gUnk_03005AA0 = arg0;
    if (arg0 == 0)
    {
        gUnk_03005A94 = 0;
        return;
    }

    gUnk_03005FD0 = 0x1B4F4DU / (arg0 + 1);
    tmp = gUnk_03005FC4; // fake
    if (gUnk_03005FD0 == gUnk_03005FC4)
    {
        gUnk_03005FC4 -= 1;
    }
}

void sub_0300089C(u8 arg0)
{
    gUnk_03005A94 = arg0;
    gUnk_03005AA2 = 1;
}

void sub_030008B4(u8 arg0)
{
    u8 var_0;
    u8 var_1;

    var_0 = gUnk_03005A98 & 0x10;
    var_1 = arg0 & 0x10;

    gUnk_03005A98 = arg0;
    gUnk_03005AAD = 0;

    if ((arg0 & 0xC0) == 0xC0)
    {
        gUnk_03005A98 = arg0 & 0x7F;
    }

    if ((var_0 != 0) && (var_1 == 0) && (gUnk_03005FCC != 0))
    {
        gUnk_03005AAD = 4;
        gUnk_03005AA2 = 1;
    }
}

void sub_03000918(u8 arg0)
{
    gUnk_03005A9A = arg0;
    gUnk_03005AAA = 1;
}

void sub_03000930(u8 arg0)
{
    gUnk_03005A9C = arg0;
    gUnk_03005AAC = 1;
}

void sub_03000948(void)
{
    if (gUnk_03005AAC != 0)
    {
        sub_03000848((gUnk_03005AA0 & 0xF00) | gUnk_03005A9C);
    }
}
