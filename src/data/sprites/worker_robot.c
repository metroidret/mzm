#include "data/sprites/worker_robot.h"
#include "macros.h"

const u32 sWorkerRobotGfx[376] = INCBIN_U32("data/sprites/worker_robot.gfx.lz");
const u16 sWorkerRobotPal[32] = INCBIN_U16("data/sprites/worker_robot.pal");

static const u16 sWorkerRobotOam_Walking_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-4, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-3, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-14, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-2, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-5, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-4, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-12, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame6[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x205, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_Walking_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-7, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x235, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x255, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -30, OAM_DIMS_16x8, OAM_NO_FLIP, 0x275, 8, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 9, 0),
    OAM_ENTRY(-12, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

static const u16 sWorkerRobotOam_BackToSleep_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 9, 0),
    OAM_ENTRY(-12, -36, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(4, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

static const u16 sWorkerRobotOam_Sleeping_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 9, 0),
    OAM_ENTRY(-12, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(4, -34, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

static const u16 sWorkerRobotOam_UnusedFrame[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 9, 0),
    OAM_ENTRY(-12, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(4, -31, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

static const u16 sWorkerRobotOam_WakingUp_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 9, 0),
    OAM_ENTRY(-12, -36, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(4, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

static const u16 sWorkerRobotOam_Standing_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-12, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x257, 9, 0),
    OAM_ENTRY(-12, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(4, -34, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

static const u16 sWorkerRobotOam_GoingToSleep_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-12, -34, OAM_DIMS_16x32, OAM_NO_FLIP, 0x219, 9, 0),
    OAM_ENTRY(4, -34, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21b, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27e, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 9, 0)
};

const struct FrameData sWorkerRobotOam_Walking[9] = {
    [0] = {
        .pFrame = sWorkerRobotOam_Walking_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOam_Walking_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOam_Walking_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOam_Walking_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sWorkerRobotOam_Walking_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOam_Walking_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sWorkerRobotOam_Walking_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOam_Walking_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_WalkingBackwards[9] = {
    [0] = {
        .pFrame = sWorkerRobotOam_Walking_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOam_Walking_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOam_Walking_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOam_Walking_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sWorkerRobotOam_Walking_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOam_Walking_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sWorkerRobotOam_Walking_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOam_Walking_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_Standing[2] = {
    [0] = {
        .pFrame = sWorkerRobotOam_Walking_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_BackToSleep[9] = {
    [0] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame3,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [4] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame5,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [6] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOam_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_Sleeping[2] = {
    [0] = {
        .pFrame = sWorkerRobotOam_Sleeping_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_GoingToSleep[3] = {
    [0] = {
        .pFrame = sWorkerRobotOam_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOam_GoingToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_TurningAround[3] = {
    [0] = {
        .pFrame = sWorkerRobotOam_GoingToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sWorkerRobotOam_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWorkerRobotOam_WakingUp[9] = {
    [0] = {
        .pFrame = sWorkerRobotOam_Sleeping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sWorkerRobotOam_Standing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sWorkerRobotOam_WakingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame5,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [4] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame3,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [6] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sWorkerRobotOam_BackToSleep_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};
