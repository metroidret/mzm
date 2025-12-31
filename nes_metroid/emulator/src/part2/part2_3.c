#include "types.h"
#include "gba.h"
#include "macros.h"

extern u8 sUnk_030023DC[];

extern u16 gUnk_03005A7A;
extern u32 gUnk_03005A90;
extern u16 gUnk_03005A94;
extern u16 gUnk_03005A96;
extern u16 gUnk_03005A98;
extern u16 gUnk_03005A9A;
extern u16 gUnk_03005A9C;
extern u16 gUnk_03005A9E;
extern u16 gUnk_03005AA0;
extern u16 gUnk_03005AA2;
extern u16 gUnk_03005AA4;
extern u16 gUnk_03005AA6;
extern u16 gUnk_03005AA8;
extern u16 gUnk_03005AAA;
extern u8 gUnk_03005AAC;
extern u8 gUnk_03005AAD;
extern u32 gUnk_03005AB0;
extern u16 gUnk_03005AB4;
extern u16 gUnk_03005AB6;
extern u16 gUnk_03005AB8;
extern u16 gUnk_03005ABA;
extern u16 gUnk_03005ABC;
extern u16 gUnk_03005ABE;
extern u16 gUnk_03005AC0;
extern u16 gUnk_03005AC2;
extern u16 gUnk_03005AC4;
extern u16 gUnk_03005AC6;
extern u16 gUnk_03005AC8;
extern u16 gUnk_03005ACA;
extern u8 gUnk_03005ACC;
extern u8 gUnk_03005ACD;
extern u32 gUnk_03005FC4;
extern u16 gUnk_03005FCC;
extern u32 gUnk_03005FD0;
extern u16 gUnk_03005FD8;

extern void sub_03000778(void);
extern void sub_03000790(void);
extern void sub_03000848(u16 arg0);

void sub_030009A0(u8 arg0);
void sub_030009DC(void);
void sub_03000D20(void);
void sub_03000D2C(u32 arg0);
void sub_03000D38(void);
void sub_03000DEC(void);
void sub_03000E10(void);
void sub_03000E40(u16 arg0);
void sub_03000E94(u8 arg0);
void sub_03000EAC(u8 arg0);
void sub_03000F10(u8 arg0);
void sub_03000F28(u8 arg0);
void sub_03000F40(u8 arg0);
void sub_03000F7C(void);

void sub_030009A0(u8 arg0)
{
    gUnk_03005A9E = arg0;
    sub_03000848(((arg0 & 7) << 8) | gUnk_03005A9C);
    if (gUnk_03005FCC == 0)
    {
        sub_03000778();
    }
    sub_03000790();
}

void sub_030009DC(void)
{
    gUnk_03005A90 = 0;
    gUnk_03005FD0 = 0;
    gUnk_03005A94 = 0;
    gUnk_03005A96 = 0;
    gUnk_03005A98 = 0;
    gUnk_03005A9A = 0;
    gUnk_03005A9C = 0;
    gUnk_03005A9E = 0;
    gUnk_03005AA0 = 0;
    gUnk_03005AA2 = 0;
    gUnk_03005FCC = 0;
    gUnk_03005AA4 = 0;
    gUnk_03005AA6 = 0;
    gUnk_03005AA8 = 0;
    gUnk_03005AAA = 0;
    gUnk_03005AAC = 0;
    gUnk_03005AAD = 0;
}

// Real file split between part2_2 and part2_3

void sub_03000D20(void)
{
    gUnk_03005AB0 = 0;
}

void sub_03000D2C(u32 arg0)
{
    gUnk_03005AC8 = arg0;
}

void sub_03000D38(void)
{
    if (gUnk_03005AC4 != 0)
    {
        gUnk_03005AC6 = 1;
        return;
    }

    gUnk_03005AC6 = 0;
    if (gUnk_03005AB8 & 0x10)
    {
        gUnk_03005AB4 = gUnk_03005AB8 & 0xF;
    }
    else
    {
        gUnk_03005AB4 = 0xF;
    }

    gUnk_03005AC2 = 0xF;
    if (gUnk_03005FD8 != 0)
    {
        gUnk_03005ACA = 1;
    }
    else
    {
        gUnk_03005ACA = 4;
    }

    sub_03000D2C(sUnk_030023DC[gUnk_03005ABE >> 3] * 4);
    if (gUnk_03005A7A & 2)
    {
        gUnk_03005FD8 = 1;
        gUnk_03005AC4 = 0;
    }
}

void sub_03000DEC(void)
{
    if ((gUnk_03005FD8 != 0) && (gUnk_03005AC4 == 0))
    {
        gUnk_03005AC4 = 2;
    }
}

void sub_03000E10(void)
{
    if (gUnk_03005ACC != 0)
    {
        sub_03000E40((gUnk_03005AC0 & 0xF00) | gUnk_03005ABC);
    }
}

void sub_03000E40(u16 arg0)
{
    u32 tmp;

    gUnk_03005ACC = 0;
    gUnk_03005AC0 = arg0;
    if (arg0 == 0)
    {
        gUnk_03005AB4 = 0;
        return;
    }

    gUnk_03005FC4 = 0x1B4F4DU / (arg0 + 1);
    tmp = gUnk_03005FD0; // fake
    if (tmp == gUnk_03005FC4)
    {
        tmp = 1;
        gUnk_03005FC4 -= 1;
    }
}

void sub_03000E94(u8 arg0)
{
    gUnk_03005AB4 = arg0;
    gUnk_03005AC2 = 1;
}

void sub_03000EAC(u8 arg0)
{
    u8 var_0;
    u8 var_1;

    var_0 = gUnk_03005AB8 & 0x10;
    var_1 = arg0 & 0x10;

    gUnk_03005AB8 = arg0;
    gUnk_03005ACD = 0;

    if ((arg0 & 0xC0) == 0xC0)
    {
        gUnk_03005AB8 = arg0 & 0x7F;
    }

    if ((var_0 != 0) && (var_1 == 0) && (gUnk_03005FD8 != 0))
    {
        gUnk_03005ACD = 4;
        gUnk_03005AC2 = 1;
    }
}

void sub_03000F10(u8 arg0)
{
    gUnk_03005ABA = arg0;
    gUnk_03005ACA = 1;
}

void sub_03000F28(u8 arg0)
{
    gUnk_03005ABC = arg0;
    gUnk_03005ACC = 1;
}

void sub_03000F40(u8 arg0)
{
    gUnk_03005ABE = arg0;
    sub_03000E40(((arg0 & 7) << 8) | gUnk_03005ABC);
    if (gUnk_03005FD8 == 0)
    {
        sub_03000D20();
    }
    sub_03000D38();
}

void sub_03000F7C(void)
{
    gUnk_03005AB0 = 0;
    gUnk_03005FC4 = 0;
    gUnk_03005AB4 = 0;
    gUnk_03005AB6 = 0;
    gUnk_03005AB8 = 0;
    gUnk_03005ABA = 0;
    gUnk_03005ABC = 0;
    gUnk_03005ABE = 0;
    gUnk_03005AC0 = 0;
    gUnk_03005AC2 = 0;
    gUnk_03005FD8 = 0;
    gUnk_03005AC4 = 0;
    gUnk_03005AC6 = 0;
    gUnk_03005AC8 = 0;
    gUnk_03005ACA = 0;
    gUnk_03005ACC = 0;
    gUnk_03005ACD = 0;
}
