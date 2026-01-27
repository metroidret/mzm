#include "data/sprites/gadora.h"
#include "macros.h"

const u32 sGadoraGfx[585] = INCBIN_U32("data/sprites/gadora.gfx.lz");
const u16 sGadoraPal[32] = INCBIN_U16("data/sprites/gadora.pal");

static const u16 sGadoraOam_EyeClosed_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24f, 8, 0)
};

static const u16 sGadoraOam_EyeClosed_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24f, 8, 0)
};

static const u16 sGadoraOam_EyeClosed_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24f, 8, 0)
};

static const u16 sGadoraOam_Warning_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x24f, 8, 0)
};

static const u16 sGadoraOam_Warning_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x203, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-1, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24f, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_OpeningEye_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x257, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x203, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeOpened_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeOpened_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x266, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeOpened_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeOpened_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeOpened_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeOpened_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_Frame_Unused[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeMoving_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeMoving_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeMoving_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x251, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_EyeMoving_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_Death_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-11, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraOam_Death_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x253, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-2, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x250, 8, 0)
};

static const u16 sGadoraBeamOam_Moving_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(6, 9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x23b, 8, 0)
};

static const u16 sGadoraBeamOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x21e, 8, 0)
};

static const u16 sGadoraBeamOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25c, 8, 0)
};

static const u16 sGadoraBeamOam_Moving_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x25e, 8, 0)
};


const struct FrameData sGadoraOam_EyeClosed[5] = {
    [0] = {
        .pFrame = sGadoraOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOam_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_Warning[7] = {
    [0] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_OpeningEye[7] = {
    [0] = {
        .pFrame = sGadoraOam_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGadoraOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOam_OpeningEye_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraBeamOam_Moving[5] = {
    [0] = {
        .pFrame = sGadoraBeamOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraBeamOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraBeamOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraBeamOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_EyeMoving[7] = {
    [0] = {
        .pFrame = sGadoraOam_EyeMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOam_EyeMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOam_EyeMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOam_EyeMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sGadoraOam_EyeMoving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOam_EyeMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_ClosingEye[5] = {
    [0] = {
        .pFrame = sGadoraOam_OpeningEye_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGadoraOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_Death[5] = {
    [0] = {
        .pFrame = sGadoraOam_EyeMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOam_Death_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGadoraOam_Death_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOam_Death_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_EyeOpened[7] = {
    [0] = {
        .pFrame = sGadoraOam_EyeOpened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGadoraOam_EyeOpened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGadoraOam_EyeOpened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGadoraOam_EyeOpened_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGadoraOam_EyeOpened_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGadoraOam_EyeOpened_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGadoraOam_BeforeClosing[5] = {
    [0] = {
        .pFrame = sGadoraOam_EyeOpened_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGadoraOam_EyeOpened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGadoraOam_EyeOpened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGadoraOam_EyeOpened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};
