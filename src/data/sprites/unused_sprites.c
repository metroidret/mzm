#include "data/sprites/unused_sprites.h"
#include "macros.h"

static const u16 sUnusedSpritesOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3151
};

static const u16 sUnusedSpritesOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3150
};

const struct FrameData sUnusedSpritesOam_Idle[3] = {
    [0] = {
        .pFrame = sUnusedSpritesOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [1] = {
        .pFrame = sUnusedSpritesOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sUnusedSpritesOam_Unused[2] = {
    [0] = {
        .pFrame = sUnusedSpritesOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u32 sUnusedSpritesGfx[6] = INCBIN_U32("data/sprites/UnusedSprites.gfx.lz");
const u16 sUnusedSpritesPal[16] = INCBIN_U16("data/sprites/UnusedSprites.pal");
