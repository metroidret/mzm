#include "types.h"
#include "gba.h"
#include "macros.h"

extern u8 sUnk_030023DC[];
extern u16 sUnk_03002846;
extern u32 sUnk_03002988;
extern u32 sUnk_0600E008[];

extern u16 gUnk_03005A7A;
extern u16 gUnk_03005A7C;
extern u32* gUnk_03005A80;
extern u32* gUnk_03005A84;
extern u32* gUnk_03005A88;
extern u32* gUnk_03005A8C;
extern u32 gUnk_03005A90;
extern u16 gUnk_03005A94;
extern u16 gUnk_03005A96;
extern u16 gUnk_03005A98;
extern u16 gUnk_03005A9A;
extern u16 gUnk_03005AA0;
extern u16 gUnk_03005AA2;
extern u16 gUnk_03005AA4;
extern u16 gUnk_03005AA6;
extern u16 gUnk_03005AA8;
extern u16 gUnk_03005AAA;
extern u8 gUnk_03005AAD;
extern u16 gUnk_03005AB4;
extern u16 gUnk_03005AB6;
extern u16 gUnk_03005AB8;
extern u16 gUnk_03005ABA;
extern u16 gUnk_03005AC0;
extern u16 gUnk_03005AC2;
extern u16 gUnk_03005AC4;
extern u16 gUnk_03005AC6;
extern u16 gUnk_03005AC8;
extern u16 gUnk_03005ACA;
extern u8 gUnk_03005ACD;
extern u32 gUnk_03005AD0;
extern u16 gUnk_03005AD4;
extern u16 gUnk_03005AD6;
extern u16 gUnk_03005AD8;
extern u16 gUnk_03005ADA;
extern u16 gUnk_03005ADC;
extern u16 gUnk_03005ADE;
extern u32 gUnk_03005AE8;
extern u32 gUnk_03005AEC;
extern u32 gUnk_03005AF0;
extern u16 gUnk_03005AF4;
extern u16 gUnk_03005AF6;
extern u16 gUnk_03005AF8;
extern u16 gUnk_03005AFA;
extern u16 gUnk_03005AFC;
extern u16 gUnk_03005AFE;
extern u16 gUnk_03005B00;
extern u16 gUnk_03005B02;
extern u16 gUnk_03005B04;
extern u16 gUnk_03005B06;
extern u8 gUnk_03005B08;
extern u32 gUnk_03005B10[];
extern u32 gUnk_03005B50[];
extern u32 gUnk_03005BF0[];
extern u32 gUnk_03005C90[];
extern u32 gUnk_03005D30[];
extern u32 gUnk_03005DD0[];
extern u32 gUnk_03005E70[];
extern u32 gUnk_03005F10[];
extern u16 gUnk_03005FB0;
extern u8 gUnk_03005FB8;
extern u16 gUnk_03005FC0;
extern u16 gUnk_03005FCC;
extern u32 gUnk_03005FD0;
extern u16 gUnk_03005FD4;
extern u16 gUnk_03005FD8;
extern u32 gUnk_03005FDC;

extern void sub_03000000(u16 arg0);
extern u16 sub_03000050(u16 arg0);
extern void sub_03000790(void);
extern void sub_03000824(void);
extern void sub_03000848(u16 arg0);
extern void sub_03000948(void);
extern void sub_03000D38(void);
extern void sub_03000DEC(void);
extern void sub_03000E10(void);
extern void sub_03000E40(u16 arg0);
extern void sub_030013C8(void);
extern void sub_030014E0(void);

void sub_03001730(void);
void sub_0300173C(void);
void sub_03001788(u32 arg0);
void sub_03001794(void);
void sub_03001840(void);
void sub_03001864(u8 arg0);
void sub_0300187C(u8 arg0);
void sub_030018E0(u8 arg0);
void sub_03001944(u8 arg0);
void sub_03001990(void);
void sub_03001C10(u8 arg0);
void sub_03001C58(u8 arg0);
void sub_03001D24(u32 arg0);
void sub_03001D30(u32 arg0, u32 arg1);
void sub_0300203C(void);

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
        gUnk_03005B10[var_r3] = sUnk_0600E008[var_r3];
        if (gUnk_03005B10[var_r3] > 0xFFFF)
        {
            gUnk_03005B10[var_r3] = 0x10000;
        }
    }
}

void sub_03001788(u32 arg0)
{
    gUnk_03005AFA = arg0;
}

void sub_03001794(void)
{
    u32 var_r4;
    u32 var_r5;

    if (gUnk_03005A7A & 8)
    {
        gUnk_03005FC0 = 1;
    }

    if (gUnk_03005B00 & 0x10)
    {
        gUnk_03005AF4 = gUnk_03005B00 & 0xF;
    }
    else
    {
        gUnk_03005AF4 = 0xF;
    }

    gUnk_03005AF8 = gUnk_03005B00 & 0xF;
    var_r4 = sUnk_030023DC[gUnk_03005B06 >> 3];
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
    sub_03001788((sUnk_030023DC[gUnk_03005B06 >> 3] * 4) + var_r5);
    sUnk_03002988 = var_r4;
    sub_03001788((var_r4 * 4) + var_r5);
}

void sub_03001840(void)
{
    if ((gUnk_03005FC0 != 0) && (gUnk_03005AFE == 0))
    {
        gUnk_03005AFE = 2;
    }
}

void sub_03001864(u8 arg0)
{
    gUnk_03005AF4 = arg0;
    gUnk_03005AF8 = 1;
}

void sub_0300187C(u8 arg0)
{
    u8 var_0;
    u8 var_1;

    var_0 = gUnk_03005B00 & 0x10;
    var_1 = arg0 & 0x10;

    gUnk_03005B00 = arg0;
    gUnk_03005B08 = 0;

    if (var_1 == 1)
    {
        gUnk_03005AF4 = arg0 & 0xF;
    }
    else if ((var_0 != 0) && (gUnk_03005FC0 != 0))
    {
        gUnk_03005B08 = 4;
        gUnk_03005AF8 = arg0 & 0xF;
    }
}

void sub_030018E0(u8 arg0)
{
    gUnk_03005B04 = arg0;
    gUnk_03005AF6 = arg0 & 0xF;
    gUnk_03005AF0 = gUnk_03005B10[gUnk_03005AF6];

    if (arg0 & 0x80)
    {
        sUnk_03002846 = 0x40;
        gUnk_03005AE8 = 1;
    }
    else
    {
        sUnk_03002846 = 0x4000;
    }
}

void sub_03001944(u8 arg0)
{
    if (gUnk_03005B04 & 0x80)
    {
        sUnk_03002846 = 0x40;
        gUnk_03005AE8 = 1;
    }
    else
    {
        sUnk_03002846 = 0x4000;
    }

    gUnk_03005B06 = arg0;
    sub_03001794();
}

void sub_03001990(void)
{
    gUnk_03005AE8 = 1;
    gUnk_03005AEC = 0;
    gUnk_03005AF0 = 0;
    gUnk_03005AF4 = 0;
    gUnk_03005AF6 = 0;
    gUnk_03005AF8 = 0;
    gUnk_03005AFA = 0;
    gUnk_03005AFC = 0;
    sUnk_03002846 = 0x8000;
    gUnk_03005FC0 = 0;
    gUnk_03005AFE = 0;
    gUnk_03005B00 = 0;
    gUnk_03005B02 = 0;
    gUnk_03005B04 = 0;
    gUnk_03005B06 = 0;
    gUnk_03005B08 = 0;
}

// File split?

void sub_03001C10(u8 arg0)
{
    gUnk_03005A7A = arg0;

    if (!(arg0 & 1))
    {
        sub_03000824();
    }
    if (!(arg0 & 2))
    {
        sub_03000DEC();
    }
    if (!(arg0 & 4))
    {
        sub_030013C8();
    }
    if (!(arg0 & 8))
    {
        sub_03001840();
    }
}

void sub_03001C58(u8 arg0)
{
    gUnk_03005A7C = arg0;

    if (arg0 & 0x80)
    {
        sub_03000000(0xA0);
    }
    else
    {
        sub_03000000(0x80);
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

    if (gUnk_03005AA8 != 0)
    {
        gUnk_03005AA8 -= 1;
    }
    if (gUnk_03005AC8 != 0)
    {
        gUnk_03005AC8 -= 1;
    }
    if (gUnk_03005AD4 != 0)
    {
        gUnk_03005AD4 -= 1;
    }
    if (gUnk_03005AFA != 0)
    {
        gUnk_03005AFA -= 1;
    }
}

void sub_03001D24(u32 arg0)
{
    gUnk_03005FB8 = arg0;
}

void sub_03001D30(u32 arg0, u32 arg1)
{
    u32 var_r5;
    void* var_0;
    void* var_1;
    void* var_2;
    void* var_3;

    var_0 = gUnk_03005B50;
    var_1 = gUnk_03005BF0;
    var_2 = gUnk_03005C90;
    var_3 = gUnk_03005D30;

    var_r5 = 0;

    if (gUnk_03005FB8 != 0)
    {
        sub_03000634(0xF0000000);
        sub_03000704(arg0, arg1);
        return;
    }

    if (gUnk_03005FCC != 0)
    {
        sub_03000948();
        sub_03000A6C(var_0, arg1);
        if (gUnk_03005AAD != 0)
        {
            gUnk_03005A94 = 0xF;
            gUnk_03005AAD = 0;
        }
        if (gUnk_03005A9A & 0x80)
        {
            sub_03000848(gUnk_03005AA0);
        }
        if (gUnk_03005AA8 != 0)
        {
            gUnk_03005AA8 -= 1;
        }
        if (!(gUnk_03005A98 & 0x20) && (gUnk_03005AA8 == 0))
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
            gUnk_03005FCC = 0;
            if (gUnk_03005AA6 != 0)
            {
                sub_03000790();
            }
        }
    }

    if (gUnk_03005FD8 != 0)
    {
        sub_03000E10();
        sub_0300100C(var_1, arg1);
        if (gUnk_03005ACD != 0)
        {
            gUnk_03005AB4 = 0xF;
            gUnk_03005ACD = 0;
        }
        if (gUnk_03005ABA & 0x80)
        {
            sub_03000E40(gUnk_03005AC0);
        }
        if (gUnk_03005AC8 != 0)
        {
            gUnk_03005AC8 -= 1;
        }
        if (!(gUnk_03005AB8 & 0x20) && (gUnk_03005AC8 == 0))
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
            gUnk_03005FD8 = 0;
            if (gUnk_03005AC6 != 0)
            {
                sub_03000D38();
            }
        }
    }

    if (gUnk_03005FB0 != 0)
    {
        sub_030014E0();
        if ((gUnk_03005FD4 == 0) && (gUnk_03005ADA == 0))
        {
            var_r5 |= 0x20000000;
        }
        else
        {
            sub_0300160C(var_2, arg1);
        }
        if (gUnk_03005AD4 != 0)
        {
            gUnk_03005AD4 -= 1;
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
        if (!(gUnk_03005ADE & 0x80) && (gUnk_03005AD4 == 0))
        {
            sub_030013C8();
        }
    }

    if (gUnk_03005AD8 != 0)
    {
        gUnk_03005AD8 >>= 0x1;
        gUnk_03005ADA = gUnk_03005AD8;
        if (gUnk_03005ADA == 0)
        {
            var_r5 |= 0x20000000;
            gUnk_03005FB0 = 0;
        }
    }

    if (gUnk_03005FC0 != 0)
    {
        sub_03001A24(var_3, arg1);
        if (gUnk_03005B08 != 0)
        {
            gUnk_03005AF4 = 0xF;
            gUnk_03005B08 = 0;
        }
        if (gUnk_03005AFA != 0)
        {
            gUnk_03005AFA -= 1;
        }
        if (!(gUnk_03005B00 & 0x20) && (gUnk_03005AFA == 0))
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
            gUnk_03005FC0 = 0;
        }
        else
        {
            sub_0300059C(var_3, arg1, arg1 >> 4);
        }
    }

    sub_03000634(var_r5, arg1);
    sub_03000704(arg0, arg1);
    sub_030006CC(arg0, arg1);
}

void sub_0300203C(void)
{
    u32 var_r3;
    u32* var_0;

    var_0 = gUnk_03005B50; // fake
    sub_0300173C();

    for (var_r3 = 0; var_r3 < 0x28; var_r3++)
    {
        gUnk_03005B50[var_r3] = 0;
        gUnk_03005BF0[var_r3] = 0;
        gUnk_03005C90[var_r3] = 0;
        gUnk_03005D30[var_r3] = 0;
        gUnk_03005DD0[var_r3] = 0;
        gUnk_03005E70[var_r3] = 0;
        gUnk_03005F10[var_r3] = 0;
    }

    gUnk_03005A80 = gUnk_03005B50;
    gUnk_03005A84 = gUnk_03005BF0;
    gUnk_03005A88 = gUnk_03005C90;
    gUnk_03005A8C = gUnk_03005D30;

    gUnk_03005A90 = 0;
    gUnk_03005FD0 = 0;
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
    sub_03000618(var_0, 0xA0);

    sub_03000704(gUnk_03005DD0, 0xA0);
    sub_03000704(gUnk_03005E70, 0xA0);
    sub_03000704(gUnk_03005F10, 0xA0);

    sub_03000618(gUnk_03005DD0, 0xA0);
    sub_03000618(gUnk_03005E70, 0xA0);
    sub_03000618(gUnk_03005F10, 0xA0);

    gUnk_03005A7A = 0;
    gUnk_03005A7C = 0;
    sub_030002A4(gUnk_03005DD0, gUnk_03005E70, gUnk_03005F10, sub_03000050(0x8000), 0xA0, &sub_03001D30);
}
