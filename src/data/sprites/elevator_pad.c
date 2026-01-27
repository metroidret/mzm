#include "data/sprites/elevator_pad.h"
#include "macros.h"

const u32 sElevatorPadGfx[136] = INCBIN_U32("data/sprites/elevator_pad.gfx.lz");
const u16 sElevatorPadPal[16] = INCBIN_U16("data/sprites/elevator_pad.pal");

static const u16 sElevatorPadOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sElevatorPadOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sElevatorPadOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sElevatorPadOam_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22a, 8, 0)
};

static const u16 sElevatorPadOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x220, 8, 0)
};

static const u16 sElevatorPadOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sElevatorPadOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x224, 8, 0)
};

const struct FrameData sElevatorPadOam_Moving[5] = {
    [0] = {
        .pFrame = sElevatorPadOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sElevatorPadOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sElevatorPadOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sElevatorPadOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sElevatorPadOam_Idle[7] = {
    [0] = {
        .pFrame = sElevatorPadOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sElevatorPadOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sElevatorPadOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sElevatorPadOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sElevatorPadOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sElevatorPadOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};
