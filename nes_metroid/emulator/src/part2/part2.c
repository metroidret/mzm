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

u8 sUnk_03002374 = 0;

void (*sUnk_03002378[0x18])(u8) = {
    sub_030008B4,
    sub_03000918,
    sub_03000930,
    sub_030009A0,
    sub_03000EAC,
    sub_03000F10,
    sub_03000F28,
    sub_03000F40,
    sub_03001458,
    sub_03000404,
    sub_030014C8,
    sub_03001518,
    sub_0300187C,
    sub_03000404,
    sub_030018E0,
    sub_03001944,
    sub_03000404,
    sub_03000404,
    sub_03000404,
    sub_03000404,
    sub_03000404,
    sub_03001C10,
    sub_03000404,
    sub_03001C58,
};

u32 sUnk_030023D8 = DMA_32BIT | DMA_DEST_FIXED;

void sub_03000000(u16 arg0)
{
    if (gUnk_03005FBC != arg0)
    {
        gUnk_03005FBC = arg0;
        WRITE_16(REG_TM1CNT_L, -arg0);
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

void sub_03000080(void)
{
    WRITE_32(REG_DMA1_CNT, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED, 1 * sizeof(u32)));
    WRITE_16(REG_DMA1_CNT_H, sUnk_03002370);

    if (gUnk_03005A5C != 0)
    {
        if (gUnk_03005A5D != 0)
        {
            switch (gUnk_03005A5D)
            {
                case 1:
                    if (gUnk_03005A5E == 0)
                    {
                        gUnk_03005A5E = 1;
                        sub_030001C4(gUnk_03005A54);
                        gUnk_03005A64(gUnk_03005A50, gUnk_03005FBC);
                    }
                    else
                    {
                        gUnk_03005A5E = 0;
                        sub_030001C4(gUnk_03005A50);
                        gUnk_03005A64(gUnk_03005A54, gUnk_03005FBC);
                    }
                    break;
    
                case 2:
                    switch (gUnk_03005A5E)
                    {
                        case 0:
                            gUnk_03005A5E = 1;
                            sub_030001C4(gUnk_03005A54);
                            gUnk_03005A64(gUnk_03005A58, gUnk_03005FBC);
                            break;
        
                        case 1:
                            gUnk_03005A5E = 2;
                            sub_030001C4(gUnk_03005A58);
                            gUnk_03005A64(gUnk_03005A50, gUnk_03005FBC);
                            break;
        
                        case 2:
                            gUnk_03005A5E = 0;
                            sub_030001C4(gUnk_03005A50);
                            gUnk_03005A64(gUnk_03005A54, gUnk_03005FBC);
                            break;
                    }
                    break;
            }
        }
        else
        {
            sub_030001C4(gUnk_03005A50);
        }
    }
    else
    {
        sub_030001B4();
    }
}

void sub_03000188(u16 arg0)
{
    WRITE_16(REG_TM1CNT_L, -gUnk_03005FBC);
    WRITE_16(REG_TM1CNT_H, 0xC4);

    WRITE_16(REG_TM0CNT_L, arg0);
    WRITE_16(REG_TM0CNT_H, 0x80);
}

void sub_030001B4(void)
{
    WRITE_32(REG_TM0CNT_H, 0);
    WRITE_32(REG_TM1CNT_H, 0);
}

void sub_030001C4(void* arg0)
{
    WRITE_16(REG_DMA1_SRC, (u32)arg0);
    WRITE_16(REG_DMA1_SRC + 2, (u32)arg0 >> 0x10);

    // REG_FIFO_A
    WRITE_16(REG_DMA1_DST, 0xA0); 
    WRITE_16(REG_DMA1_DST + 2, 0x400); 

    WRITE_16(REG_DMA1_CNT_H, DMA_ENABLE | DMA_START_SPECIAL | DMA_REPEAT);
}

void sub_030001F0(void* arg0, u16 arg1, u32 arg2, u8 arg3)
{
    WRITE_16(REG_SOUNDCNT_H, 0xB06); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 100% Vol, Sound 100% Vol

    gUnk_03005FBC = arg2;
    gUnk_03005A5C = arg3;
    gUnk_03005A50 = arg0;
    gUnk_03005A5D = 0;

    sub_030001C4(arg0);
    sub_03000188(arg1);
}

void sub_0300023C(void* arg0, void* arg1, u16 arg2, s32 arg3, void* arg4)
{
    WRITE_16(REG_SOUNDCNT_H, 0xB06); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 100% Vol, Sound 100% Vol

    gUnk_03005FBC = arg3;
    gUnk_03005A5C = 1;
    gUnk_03005A50 = arg0;
    gUnk_03005A54 = arg1;
    gUnk_03005A5D = 1;
    gUnk_03005A5E = 0;
    gUnk_03005A64 = arg4;

    sub_030001C4(arg0);
    sub_03000188(arg2);
}

void sub_030002A4(void* arg0, void* arg1, void* arg2, u16 arg3, s32 arg4, void* arg5)
{
    WRITE_16(REG_SOUNDCNT_X, 0x80); // FIFO enable
    WRITE_16(REG_SOUNDCNT_L, 0);
    WRITE_16(REG_SOUNDCNT_H, 0xB00); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 50% Vol, Sound 25% Vol
    WRITE_16(REG_SOUNDCNT_H, 0xB04); // DMA Sound A Enable Left/Right, Timer 0, Reset FIFO, 100% Vol, Sound 25% Vol

    gUnk_03005FBC = arg4;
    gUnk_03005A5C = 1;
    gUnk_03005A50 = arg0;
    gUnk_03005A54 = arg1;
    gUnk_03005A58 = arg2;
    gUnk_03005A5D = 2;
    gUnk_03005A5E = 0;
    gUnk_03005A60 = arg3;
    gUnk_03005A64 = arg5;

    sub_030001C4(arg0);
    sub_03000188(arg3);
}

void sub_03000330(void)
{
    sub_030001B4();
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

u8 sub_03000380(u16 arg0) 
{
    u8 var_r3;
    u8 var_r4;
    u16 subroutine_arg0[5];

    var_r3 = 0;

    if (arg0 == 0x4015)
    {
        subroutine_arg0[0] = (u8)gUnk_03005FCC;
        subroutine_arg0[1] = (u8)gUnk_03005FD8;
        subroutine_arg0[2] = gUnk_03005FB0;
        subroutine_arg0[3] = (u8)gUnk_03005FC0;

        for (var_r4 = 0; var_r4 < 4; var_r4++)
        {
            if (gUnk_03005A68[var_r4] != 0)
            {
                var_r3 |= (gUnk_03005A68[var_r4] - 1) << var_r4;
            }
            else
            {
                var_r3 |= subroutine_arg0[var_r4] << var_r4;
            }
        }

        do { var_r3 |= (u8)subroutine_arg0[4] * 0x10; } while(0); // what?
    }

    return var_r3;
}

void sub_03000404(u8 arg0)
{
    return;
}

void sub_03000408(u16 arg0, u8 arg1)
{
    u32 var_r2;

    if (sUnk_03002374 != 0)
        return;

    arg0 -= 0x4000;
    if (arg0 < 0x18)
    {
        sUnk_03002378[arg0](arg1);
        if ((arg0 & 3) == 3)
        {
            gUnk_03005A68[arg0 >> 2] = 2;
        }
    }

    if (arg0 == 0x15)
    {
        for (var_r2 = 0; var_r2 < 4; var_r2++)
        {
            if (arg1 & 1)
            {
                gUnk_03005A68[var_r2] = 1;
            }
            arg1 >>= 1;
        }
    }
}

void sub_0300047C(u8* arg0, u8 arg1)
{
    WRITE_8(arg0, arg1);
}

u8 sub_03000484(u8* arg0)
{
    return READ_8(arg0);
}

void sub_03000488(void)
{
    sUnk_03002374 = 0;
    sub_03000564();

    sub_0300047C(REG_SOUNDCNT_X, 0xFF); // FIFO enable
    sub_0300047C(REG_SOUNDCNT_L, 0x77); // Sound 1-4 Master Volume Left/Right Enable
    sub_0300047C(REG_SOUNDCNT_L + 1, 0xFF); // Sound 1-4 Flags Left/Right Enable
    WRITE_16(REG_SOUNDBIAS, (READ_16(REG_SOUNDBIAS) & 0x3FF) | 0x4000); // Set Resolution / Sampling to 8bit / 65.536kHz

    sub_0300203C();
}

void sub_030004E0(void)
{
    u32 var_r1;

    sub_03000080();

    for (var_r1 = 0; var_r1 < 5; var_r1++)
    {
        gUnk_03005A68[var_r1] = 0;
    }
}

void sub_03000500(void)
{
    sub_03000408(0x4015, 0);
    sUnk_03002374 = 1;
    sub_03000330();

    WRITE_32(REG_DMA1_CNT, C_32_2_16(DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED, 1 * sizeof(u32)));
    WRITE_16(REG_DMA1_CNT_H, sUnk_030023D8);
}

void sub_0300053C(void)
{
    WRITE_32(REG_FIFO_A, 0);
    WRITE_32(REG_FIFO_B, 0);

    sub_0300203C();
    sub_03000564();
    sUnk_03002374 = 0;
}

void sub_03000564(void)
{
    u32 var_r1;

    for (var_r1 = 0; var_r1 < 5; var_r1++)
    {
        gUnk_03005A68[var_r1] = 0;
    }

    sub_030009DC();
    sub_03000F7C();
    sub_03001594();
    sub_03001990();
}
