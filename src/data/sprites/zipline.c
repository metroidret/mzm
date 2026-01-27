#include "data/sprites/zipline.h"
#include "macros.h"

const u32 sZiplineGfx[264] = INCBIN_U32("data/sprites/zipline.gfx.lz");
const u16 sZiplinePal[16] = INCBIN_U16("data/sprites/zipline.pal");

static const u16 sZiplineOam_OffIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sZiplineOam_OffGrabbingSamus_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sZiplineOam_OffGrabbingSamus_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0)
};

static const u16 sZiplineOam_OnGrabbingSamus_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sZiplineOam_OnSamusGrabbed_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sZiplineOam_OnSamusGrabbed_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sZiplineOam_OnSamusGrabbed_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sZiplineOam_OnIdle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sZiplineOam_OnGrabbingSamus_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0)
};

static const u16 sZiplineOam_OnIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sZiplineOam_OnIdle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0)
};

const u16 sZiplineButtonOam_OffIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x214, 8, 0)
};

const u16 sZiplineButtonOam_OnIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x234, 8, 0)
};

const u16 sZiplineButtonOam_OnIdle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0)
};

const u16 sZiplineButtonOam_OnIdle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x236, 8, 0)
};

const struct FrameData sZiplineOam_OffIdle[2] = {
    [0] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OffGrabbingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OffSamusGrabbed[2] = {
    [0] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame1,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OffReleasingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OffGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnIdle[7] = {
    [0] = {
        .pFrame = sZiplineOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZiplineOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZiplineOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sZiplineOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sZiplineOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sZiplineOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnGrabbingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnSamusGrabbed[7] = {
    [0] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sZiplineOam_OnSamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineOam_OnReleasingSamus[4] = {
    [0] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineOam_OnGrabbingSamus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineButtonOam_OffIdle[2] = {
    [0] = {
        .pFrame = sZiplineButtonOam_OffIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineButtonOam_OnIdle[7] = {
    [0] = {
        .pFrame = sZiplineButtonOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineButtonOam_Active[7] = {
    [0] = {
        .pFrame = sZiplineButtonOam_OffIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sZiplineButtonOam_OnIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};
