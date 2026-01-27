#include "data/sprites/sidehopper.h"
#include "macros.h"
#include "oam.h"

const s16 sSidehopperHighJumpVelocity[10] = {
    -8, -16, -16, -8, -4, 0, 4, 8, 16, 16
};

const s16 sSidehopperLowJumpVelocity[10] = {
    -4, -8, -4, -2, 0, 4, 8, 16, 16, 16
};

const u32 sSidehopperGfx[303] = INCBIN_U32("data/sprites/sidehopper.gfx.lz");
const u16 sSidehopperPal[16] = INCBIN_U16("data/sprites/sidehopper.pal");

static const u16 sSidehopperOam_Idle_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_Idle_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-19, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(3, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_Idle_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-19, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(3, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_JumpWarning_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_JumpWarning_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-18, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_JumpWarning_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_JumpWarning_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(3, -22, OAM_DIMS_16x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_JumpWarning_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-18, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(2, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0)
};

static const u16 sSidehopperOam_Jumping_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-23, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(7, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(2, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0)
};

static const u16 sSidehopperOam_Jumping_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-23, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-23, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(7, -25, OAM_DIMS_16x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-18, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(2, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0)
};

static const u16 sSidehopperOam_Jumping_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-23, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-23, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-18, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(7, -24, OAM_DIMS_16x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(2, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x218, 8, 0)
};

static const u16 sSidehopperOam_Landing_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -23, OAM_DIMS_16x8, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-19, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(3, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sSidehopperOam_ShakingHead_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-18, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_ShakingHead_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sSidehopperOam_ShakingHead_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

const struct FrameData sSidehopperOam_Idle[5] = {
    [0] = {
        .pFrame = sSidehopperOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sSidehopperOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sSidehopperOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sSidehopperOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_ShakingHead[9] = {
    [0] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sSidehopperOam_ShakingHead_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_JumpWarning[6] = {
    [0] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_Jumping[4] = {
    [0] = {
        .pFrame = sSidehopperOam_Jumping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSidehopperOam_Jumping_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sSidehopperOam_Jumping_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSidehopperOam_Landing[7] = {
    [0] = {
        .pFrame = sSidehopperOam_Landing_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sSidehopperOam_JumpWarning_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};
