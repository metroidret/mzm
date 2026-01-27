#include "data/sprites/parasite.h"
#include "macros.h"

const u32 sParasiteGfx[309] = INCBIN_U32("data/sprites/parasite.gfx.lz");
const u16 sParasitePal[16] = INCBIN_U16("data/sprites/parasite.pal");

static const u16 sParasiteOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sParasiteOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x201, 8, 0)
};

static const u16 sParasiteOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sParasiteOam_Idle_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0)
};

static const u16 sParasiteOam_LandingAfterFalling_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x220, 8, 0)
};

static const u16 sParasiteOam_LandingAfterFalling_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x221, 8, 0)
};

static const u16 sParasiteOam_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x222, 8, 0)
};

static const u16 sParasiteOam_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x223, 8, 0)
};

static const u16 sParasiteOam_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sParasiteOam_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x200, 8, 0)
};

static const u16 sParasiteOam_Tumbling_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 8, 0)
};

static const u16 sParasiteOam_TurningBackOnFeet_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 8, 0)
};

static const u16 sParasiteOam_TurningBackOnFeet_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 8, 0)
};

static const u16 sParasiteOam_TurningBackOnFeet_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x224, 8, 0)
};

static const u16 sParasiteOam_TurningAround_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x206, 8, 0)
};

static const u16 sParasiteOam_JumpingUp_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 8, 0)
};

static const u16 sParasiteOam_JumpingUp_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sParasiteOam_JumpingUp_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0)
};

static const u16 sParasiteOam_JumpingUp_Unused_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20a, 8, 0)
};

static const u16 sParasiteOam_JumpingUp_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 8, 0)
};

static const u16 sParasiteOam_JumpingDown_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x227, 8, 0)
};

static const u16 sParasiteOam_JumpingDown_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sParasiteOam_JumpingDown_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0)
};

static const u16 sParasiteOam_JumpingDown_Unused_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sParasiteOam_Attached_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20b, 8, 0)
};

static const u16 sParasiteOam_Attached_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20c, 8, 0)
};

static const u16 sParasiteOam_Attached_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20d, 8, 0)
};

static const u16 sParasiteOam_Attached_Unused_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sParasiteOam_Attached_Unused_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sParasiteOam_Attached_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0)
};

static const u16 sParasiteOam_Attached_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0)
};

static const u16 sParasiteOam_Attached_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sParasiteOam_Attached_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0)
};

static const u16 sParasiteOam_Attached_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22f, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x215, 8, 0)
};

static const u16 sParasiteOam_Expelled_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 8, 0)
};

static const u16 sParasiteOam_Dying_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0)
};

static const u16 sParasiteOam_Dying_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sParasiteOam_Dying_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x232, 8, 0)
};

static const u16 sParasiteOam_Dying_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x217, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x218, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0)
};

static const u16 sParasiteOam_Dying_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x23b, 8, 0)
};

const struct FrameData sParasiteOam_Idle[7] = {
    [0] = {
        .pFrame = sParasiteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sParasiteOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sParasiteOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sParasiteOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sParasiteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sParasiteOam_Idle_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_LandingAfterFalling[5] = {
    [0] = {
        .pFrame = sParasiteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_LandingAfterFalling_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_LandingAfterFalling_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOam_LandingAfterFalling_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Landing[4] = {
    [0] = {
        .pFrame = sParasiteOam_Landing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_Landing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Tumbling[5] = {
    [0] = {
        .pFrame = sParasiteOam_Tumbling_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_Tumbling_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_TurningBackOnFeet[8] = {
    [0] = {
        .pFrame = sParasiteOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_TurningBackOnFeet_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_TurningBackOnFeet_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOam_TurningBackOnFeet_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParasiteOam_Landing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParasiteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParasiteOam_Landing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_TurningAround[2] = {
    [0] = {
        .pFrame = sParasiteOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_JumpingUp_Unused[7] = {
    [0] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_JumpingDown_Unused[7] = {
    [0] = {
        .pFrame = sParasiteOam_JumpingDown_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sParasiteOam_JumpingDown_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sParasiteOam_JumpingDown_Unused_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sParasiteOam_JumpingDown_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sParasiteOam_JumpingDown_Unused_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sParasiteOam_JumpingDown_Unused_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_JumpingUp[3] = {
    [0] = {
        .pFrame = sParasiteOam_JumpingUp_Unused_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_JumpingUp_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Attached_Unused[9] = {
    [0] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParasiteOam_Attached_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Attached[9] = {
    [0] = {
        .pFrame = sParasiteOam_Attached_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_Attached_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_Attached_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOam_Attached_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParasiteOam_Attached_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParasiteOam_Attached_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParasiteOam_Attached_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParasiteOam_Attached_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Expelled[9] = {
    [0] = {
        .pFrame = sParasiteOam_Attached_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParasiteOam_Expelled_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParasiteOam_Expelled_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParasiteOam_Expelled_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParasiteOam_Expelled_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParasiteOam_Expelled_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParasiteOam_Expelled_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParasiteOam_Expelled_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Dying_Unused[5] = {
    [0] = {
        .pFrame = sParasiteOam_Dying_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParasiteOam_Dying_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParasiteOam_Dying_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParasiteOam_Dying_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParasiteOam_Dying[11] = {
    [0] = {
        .pFrame = sParasiteOam_Dying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sParasiteOam_Dying_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sParasiteOam_Dying_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sParasiteOam_Dying_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sParasiteOam_Dying_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sParasiteOam_Dying_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sParasiteOam_Dying_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sParasiteOam_Dying_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sParasiteOam_Dying_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sParasiteOam_Dying_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};
