#include "types.h"
#include "gba.h"
#include "macros.h"

static inline void LZ77UncompVRAM(const void *src, void *dst) {
    asm("\
        mov r0, %0 \n\
        mov r1, %1 \n\
        svc 0x12 \n\
    " : // No outputs
      : "r" (src), "r" (dst)
      : "r0", "r1");
}

static inline void LZ77UncompWRAM(const void *src, void *dst) {
    asm("\
        mov r0, %0 \n\
        mov r1, %1 \n\
        svc 0x11 \n\
    " : // No outputs
      : "r" (src), "r" (dst)
      : "r0", "r1");
}

struct EmulatorSP {
    u8 pad_0[0x830 - 0x0];
    s32 SP_830;
    u8 pad_834[0x84C - 0x834];
    u8* SP_84C;
    u8 pad_850[0x854 - 0x850];
    void* SP_854;
    u8 pad_858[0x904 - 0x858];
    s32 SP_904;
    u8 pad_908[0x924 - 0x908];
    u32** SP_924;
};

extern u32* sUnk_03005840; // sUnk_03005840 = 0x0600B800

// 95.68% Matching: https://decomp.me/scratch/EOTlA
void sub_0600E048(s32 arg0, struct EmulatorSP* arg1)
{
    s32 var_r7;
    s32 var_r7_2;
    u16* var_sl;
    void* temp_r4;
    u32 temp_r5;
    u32 var_r1;
    u32 var_r2;
    u32 var_r3;
    u32* temp_r1_2;
    void* var_r6_2;
    u32 var_1;
    u32 var_2;
    u16* unk_0600B800;
    s32 tmp;

    do
    {
        // while (arg0 != 0x920);
        while (1)
        {
            tmp = 0x920;
            if (arg0 != tmp)
                continue;
            tmp++,tmp--;
            break;
        }
        LZ77UncompVRAM(arg1->SP_924[0xD0/4], sUnk_03005840);
    }
    while(0);

    unk_0600B800 = (u16* )0x0600B800;
    var_sl = unk_0600B800 + 0x80/2;

    for (var_r7 = 1; var_r7 < 0x10u; var_r7++)
    {
        for (var_1 = 0; var_1 < 0x80/2; var_1++)
        {
            var_2 = 0x1F00;
            var_r1 = unk_0600B800[var_1] & 0x1F;
            var_r2 = (unk_0600B800[var_1] >> 0x5) & 0x1F;
            var_r3 = unk_0600B800[var_1] >> 0xA;
            if ((var_r7 & 7) == 0)
            {
                var_r1 = (var_r1 * 0x3A) + (var_r2 * 0x71) + (var_r3 * 0x15) + 0xC00;
            }
            else
            {
                var_r1 = (var_r1 * 0x4D) + (var_r2 * 0x97) + (var_r3 * 0x1C);
            }
            if (var_r1 > var_2)
            {
                var_r1 = 0x1F00;
            }
            
            var_r3 = var_r1;
            var_r2 = var_r1;
            if (var_r7 & 1)
            {
                var_r1 += 0x800;
                if (var_r1 > 0x1F00)
                {
                    var_r1 = 0x1F00;
                }
            }
            if (var_r7 & 2)
            {
                var_r2 += 0x800;
                if (var_r2 > 0x1F00)
                {
                    var_r2 = 0x1F00;
                }
            }
            if (var_r7 & 4)
            {
                var_r3 += 0x800;
                if (var_r3 > 0x1F00)
                {
                    var_r3 = 0x1F00;
                }
            }
            var_sl[var_1] = (var_r1 >> 8) | ((var_r2 & 0x1F00) >> 3) | ((var_r3 & 0x1F00) << 2);
        }

        var_sl += 0x40;
    }

    temp_r1_2 = arg1->SP_924[0xCC/4];
    var_r6_2 = temp_r1_2 + 0x64/4;
    for (var_r7_2 = 0; var_r7_2 < 0x64/4; var_r7_2++)
    {
        temp_r5 = temp_r1_2[var_r7_2];
        do
        {
            temp_r4 = arg1->SP_854 + ((temp_r5 & 0xFFFF) << 4);
            LZ77UncompWRAM(var_r6_2, (temp_r4));
        }
        while(0);
        var_r6_2 += temp_r5 >> 0x10;
    }
}
