#include "data/sprites/falling_chozo_pillar.h"
#include "macros.h"

const u32 sFallingChozoPillarGfx[219] = INCBIN_U32("data/sprites/falling_chozo_pillar.gfx.lz");
const u16 sFallingChozoPillarPal[16] = INCBIN_U16("data/sprites/falling_chozo_pillar.pal");

static const u16 sFallingChozoPillarOam_Falling_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-32, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-32, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0)
};

const struct FrameData sFallingChozoPillarOam_Falling[2] = {
    [0] = {
        .pFrame = sFallingChozoPillarOam_Falling_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
