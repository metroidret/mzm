#include "data/menus/pause_screen_data.h"
#include "macros.h"
#include "gba.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "constants/menus/status_screen.h"

const u16 sPauseScreen_3fcef0[11 * 16] = INCBIN_U16("data/menus/pause_screen/3fcef0.pal");
const u16 sTankIconsPal[16 * 16] = INCBIN_U16("data/menus/pause_screen/tank_icons.pal");
const u16 sPauseScreen_3fd250[5 * 16] = INCBIN_U16("data/menus/pause_screen/3fd250.pal");

const u16 sMinimapAnimatedPalette[1 * 16] = INCBIN_U16("data/menus/pause_screen/minimap_animated.pal");
const u16 sSamusWireframePal[4 * 16] = INCBIN_U16("data/menus/pause_screen/samus_wireframe.pal");


static const u16 sSamusIconOam_Suit_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2fa, 6, 0)
};

static const u16 sBorderArrowOam_Up_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 5, 0)
};

static const u16 sBorderArrowOam_Down_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_Y_FLIP, 0x200, 5, 0)
};

static const u16 sBorderArrowOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 5, 0)
};

static const u16 sBorderArrowOam_Right_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 5, 0)
};

static const u16 sMiscOam_SamusPowerSuitWireFrame_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(0, 0, OAM_DIMS_32x64, OAM_NO_FLIP, 0x2a6, 4, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2aa, 4, 0),
    OAM_ENTRY(32, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x32a, 4, 0),
    OAM_ENTRY(0, 64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25a, 4, 0),
    OAM_ENTRY(32, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 4, 0),
    OAM_ENTRY(0, 80, OAM_DIMS_32x8, OAM_NO_FLIP, 0x29a, 4, 0),
    OAM_ENTRY(32, 80, OAM_DIMS_16x8, OAM_NO_FLIP, 0x29e, 4, 0)
};

static const u16 sMiscOam_SamusFullSuitWireFrame_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(0, 0, OAM_DIMS_32x64, OAM_NO_FLIP, 0x2a0, 4, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2a4, 4, 0),
    OAM_ENTRY(32, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x324, 4, 0),
    OAM_ENTRY(0, 64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3a0, 4, 0),
    OAM_ENTRY(32, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3a4, 4, 0),
    OAM_ENTRY(0, 80, OAM_DIMS_32x8, OAM_NO_FLIP, 0x294, 4, 0),
    OAM_ENTRY(32, 80, OAM_DIMS_16x8, OAM_NO_FLIP, 0x298, 4, 0)
};

static const u16 sMiscOam_EnergyHeader_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x0, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4, 11, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2ac, 11, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2ce, 11, 0),
    OAM_ENTRY(32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d2, 11, 0),
    OAM_ENTRY(64, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d4, 11, 0),
    OAM_ENTRY(88, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d5, 11, 0)
};

static const u16 sMiscOam_BeamHeader_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x6, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0)
};

static const u16 sMiscOam_MissileHeader_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0xb, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0xf, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x370, 11, 0)
};

static const u16 sMiscOam_BombHeader_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x11, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x15, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36e, 11, 0)
};

#ifdef REGION_EU
static const u16 sMiscOam_SuitHeader_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x16, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1a, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x36f, 11, 0)
};

static const u16 sMiscOam_MiscHeader_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1c, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x36f, 11, 0)
};
#else // !REGION_EU
static const u16 sMiscOam_SuitHeader_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x16, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x36f, 11, 0)
};

static const u16 sMiscOam_MiscHeader_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1c, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x36f, 11, 0)
};
#endif // REGION_EU

static const u16 sBorderArrowOam_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x0, 15, 0)
};

static const u16 sMiscOam_DownCursor_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 3, 0)
};

static const u16 sMiscOam_DownCursor_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 3, 0)
};

static const u16 sMiscOam_DownCursor_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x244, 3, 0)
};

static const u16 sMiscOam_RightCursor_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 3, 0)
};

static const u16 sMiscOam_RightCursor_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 3, 0)
};

static const u16 sMiscOam_RightCursor_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x241, 3, 0)
};

static const u16 sTargetOam_Target_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f3, 3, 0)
};

static const u16 sTargetOam_Target_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f4, 3, 0)
};

static const u16 sTargetOam_Target_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f5, 3, 0)
};

static const u16 sTargetOam_Target_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f6, 3, 0)
};

static const u16 sTargetOam_UpArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_UpArrow_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_UpArrow_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_UpArrow_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_UpArrow_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 3, 0)
};

static const u16 sTargetOam_UpArrow_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_DownArrow_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_DownArrow_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_DownArrow_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x242, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_DownArrow_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 3, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0)
};

static const u16 sTargetOam_DownArrow_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x242, 3, 0)
};

static const u16 sTargetOam_DownArrow_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x262, 3, 0)
};

static const u16 sMiscOam_DownloadLine_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3a6, 8, 0)
};

static const u16 sMiscOam_DownloadLineTrail_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c6, 8, 0)
};

static const u16 sMiscOam_DownloadLineTrail_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3aa, 8, 0)
};

static const u16 sMiscOam_DownloadLineTrail_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-128, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ca, 8, 0)
};

static const u16 sBorderArrowOam_Up_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 5, 0)
};

static const u16 sBorderArrowOam_Up_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 5, 0)
};

static const u16 sBorderArrowOam_Down_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_Y_FLIP, 0x200, 5, 0)
};

static const u16 sBorderArrowOam_Down_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -3, OAM_DIMS_16x8, OAM_Y_FLIP, 0x200, 5, 0)
};

static const u16 sBorderArrowOam_Left_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 5, 0)
};

static const u16 sBorderArrowOam_Left_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 5, 0)
};

static const u16 sBorderArrowOam_Right_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 5, 0)
};

static const u16 sBorderArrowOam_Right_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 5, 0)
};

static const u16 sSamusIconOam_Suit_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ff, 8, 0)
};

static const u16 sOverlayOam_Kraid_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x4c, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x50, 5, 0)
};

static const u16 sOverlayOam_Norfair_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x52, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x56, 5, 0)
};

static const u16 sOverlayOam_Ridley_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x58, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5c, 5, 0)
};

static const u16 sOverlayOam_Tourian_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x5e, 5, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x60, 5, 0)
};

static const u16 sOverlayOam_Crateria_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x44, 5, 0)
};

static const u16 sOverlayOam_Chozodia_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x64, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x68, 5, 0)
};

static const u16 sOverlayOam_AreaNameSpawning_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x314, 5, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x316, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x314, 5, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x316, 5, 0)
};

static const u16 sOverlayOam_AreaNameSpawning_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x334, 5, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x336, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x334, 5, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x336, 5, 0)
};

static const u16 sOverlayOam_AreaNameSpawning_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x354, 5, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x356, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x354, 5, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x356, 5, 0)
};

static const u16 sOverlayOam_AreaNameSpawning_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x374, 5, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x376, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x374, 5, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x376, 5, 0)
};

static const u16 sOverlayOam_AreaNameSpawning_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x374, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x374, 5, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x375, 5, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x375, 5, 0)
};

static const u16 sOverlayOam_Brinstar_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x46, 5, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x4a, 5, 0)
};

static const u16 sMiscOam_EnergyTanks_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x318, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x31a, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x319, 3, 0)
};

static const u16 sMiscOam_MissileTanks_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x338, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x33a, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x339, 3, 0)
};

static const u16 sMiscOam_SuperMissileTanks_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x358, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x35a, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x359, 3, 0)
};

static const u16 sMiscOam_PowerBombTanks_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x378, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37a, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x379, 3, 0)
};

static const u16 sMiscOam_InGameTimer_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x394, 3, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x398, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x39c, 8, 0)
};

static const u16 sMiscOam_BeamLinker_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x310, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(8, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30c, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(8, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x30c, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(8, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(24, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30e, 11, 0)
};

static const u16 sMiscOam_BeamLinker_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(8, 40, OAM_DIMS_32x8, OAM_NO_FLIP, 0x30c, 11, 0)
};

static const u16 sMiscOam_MissileLinker_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_MissileLinker_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2ef, 11, 0)
};

static const u16 sMiscOam_MissileLinker_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x30c, 11, 0)
};

static const u16 sMiscOam_MissileLinker_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32c, 11, 0)
};

static const u16 sMiscOam_MissileLinker_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x2ef, 11, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(16, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 0x32c, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-6, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-13, 32, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-13, 32, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(-22, 32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x34e, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-13, 32, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(-30, 32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x34d, 11, 0),
    OAM_ENTRY(-14, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x34f, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_BombLinker_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2f0, 11, 0),
    OAM_ENTRY(-13, 32, OAM_DIMS_8x8, OAM_X_FLIP, 0x30c, 11, 0),
    OAM_ENTRY(-38, 32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x34c, 11, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x32e, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f1, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b1, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-40, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b0, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-40, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b0, 11, 0),
    OAM_ENTRY(-48, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2af, 11, 0)
};

static const u16 sMiscOam_SuitLinker_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-24, 14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-56, 9, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2ae, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-31, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b5, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-39, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b4, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-39, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b4, 11, 0),
    OAM_ENTRY(-47, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b3, 11, 0)
};

static const u16 sMiscOam_MiscLinker_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x2f1, 11, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2ec, 11, 0),
    OAM_ENTRY(-55, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2b2, 11, 0)
};

static const u16 sMiscOam_ItemCursorIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2b9, 3, 0)
};

static const u16 sMiscOam_ItemCursorIdle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2bb, 3, 0)
};

static const u16 sMiscOam_ItemCursorIdle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2bd, 3, 0)
};

static const u16 sOverlayOam_SelectOn_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3b8, 3, 0)
};

static const u16 sOverlayOam_SelectOff_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3bc, 3, 0)
};

static const u16 sOverlayOam_RPromptPressed_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(110, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x357, 5, 0)
};

static const u16 sOverlayOam_LPromptPressed_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-118, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x337, 5, 0)
};

static const u16 sOverlayOam_CrateriaOutline_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x264, 3, 0)
};

static const u16 sOverlayOam_BrinstarOutline_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 3, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x24c, 3, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x288, 3, 0),
    OAM_ENTRY(12, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28c, 3, 0)
};

static const u16 sOverlayOam_KraidOutline_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x226, 3, 0)
};

static const u16 sOverlayOam_NorfairOutline_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x28d, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28f, 3, 0)
};

static const u16 sOverlayOam_RidleyOutline_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26d, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26f, 3, 0)
};

static const u16 sOverlayOam_TourianOutline_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22d, 3, 0)
};

static const u16 sOverlayOam_ChozodiaOutline_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22f, 3, 0)
};

static const u16 sWorldMapOam_OutlinedCrateria_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x6a, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6e, 3, 0),
    OAM_ENTRY(-39, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-39, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(29, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(29, 1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameCrateria_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x6a, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x6e, 2, 0)
};

static const u16 sWorldMapOam_OutlinedBrinstar_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x70, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x74, 3, 0),
    OAM_ENTRY(-50, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-32, 10, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(37, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(37, 8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-16, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-50, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameBrinstar_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x70, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x74, 2, 0)
};

static const u16 sWorldMapOam_OutlinedKraid_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x76, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7a, 3, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(9, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameKraid_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x76, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7a, 2, 0)
};

static const u16 sWorldMapOam_OutlinedNorfair_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x7c, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 3, 0),
    OAM_ENTRY(-32, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-32, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(26, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(26, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameNorfair_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x7c, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sWorldMapOam_OutlinedRidley_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x82, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x86, 3, 0),
    OAM_ENTRY(-23, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-23, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(15, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(15, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameRidley_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sWorldMapOam_OutlinedTourian_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x88, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x8c, 3, 0),
    OAM_ENTRY(-17, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-17, -2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(10, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(10, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameTourian_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sWorldMapOam_OutlinedChozodia_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x8e, 3, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-18, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-18, 4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x228, 8, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(12, 4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x228, 8, 0)
};

static const u16 sWorldMapOam_NameChozodia_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x92, 2, 0)
};

static const u16 sWorldMapOam_Target_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f7, 3, 0)
};

static const u16 sWorldMapOam_Target_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f8, 3, 0)
};

static const u16 sWorldMapOam_Target_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f9, 3, 0)
};

static const u16 sMiscOam_ItemCursorFocusing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3ae, 3, 0)
};

static const u16 sMiscOam_ItemCursorFocusing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3b0, 3, 0)
};

static const u16 sMiscOam_ItemCursorFocusing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3b2, 3, 0)
};

static const u16 sMiscOam_ItemCursorFocusing_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3b4, 3, 0)
};

static const u16 sMiscOam_ItemCursorFocusing_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3b6, 3, 0)
};

static const u16 sMiscOam_TextMarkerDown_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x225, 3, 0)
};

static const u16 sMiscOam_TextMarkerDown_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x224, 3, 0)
};

static const u16 sMiscOam_TextMarkerUp_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x205, 3, 0)
};

static const u16 sMiscOam_TextMarkerUp_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x204, 3, 0)
};

static const u16 sBossIconOam_Kraid_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 3, 0)
};

static const u16 sBossIconOam_Ridley_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 3, 0)
};

static const u16 sSamusIconOam_Suit_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2fc, 6, 0)
};

static const u16 sSamusIconOam_Suit_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2fe, 6, 0)
};

static const u16 sOverlayOam_ChozoHintCrateria_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc0, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc4, 5, 0)
};

static const u16 sOverlayOam_ChozoHintBrinstar_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc8, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xcc, 5, 0)
};

static const u16 sOverlayOam_ChozoHintKraid_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xd0, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xd4, 5, 0)
};

static const u16 sOverlayOam_ChozoHintNorfair_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xd8, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xdc, 5, 0)
};

static const u16 sOverlayOam_ChozoHintRidley_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x100, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x104, 5, 0)
};

static const u16 sOverlayOam_ChozoHintTourian_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x108, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10c, 5, 0)
};

static const u16 sOverlayOam_ChozoHintChozodia_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x110, 5, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x114, 5, 0)
};

static const u16 sBossIconOam_Ship_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x207, 6, 0)
};

static const u16 sBossIconOam_Crossmark_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x231, 3, 0)
};

static const u16 sSamusIconOam_Suit_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x312, 6, 0)
};

static const u16 sMiscOam_GunHeader_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x22, 11, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26, 11, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x36c, 11, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 11, 0)
};

static const u16 sSamusIconOam_Suitless_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x280, 6, 0)
};

static const u16 sSamusIconOam_Suitless_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x281, 6, 0)
};

static const u16 sSamusIconOam_Suitless_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x282, 6, 0)
};

static const u16 sSamusIconOam_Suitless_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x283, 6, 0)
};

static const u16 sTargetOam_GreenFlameSpawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sTargetOam_GreenFlameSpawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0)
};

static const u16 sTargetOam_GreenFlameSpawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0)
};

static const u16 sTargetOam_GreenFlameSpawning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sTargetOam_GreenFlameSpawning_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sTargetOam_GreenFlameSpawning_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sTargetOam_GreenFlameMoving_Frame11[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 7, 0)
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 7, 0)
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 7, 0)
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 7, 0)
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 7, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 7, 0)
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 7, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame11[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -9, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21a, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 7, 0)
};

static const u16 sTargetOam_PurpleFlameMoving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -7, OAM_DIMS_8x16, OAM_X_FLIP, 0x21a, 7, 0)
};

static const u16 sMiscOam_SamusSuitlessWireframe_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x180, 4, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x184, 4, 0),
    OAM_ENTRY(0, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x186, 4, 0),
    OAM_ENTRY(32, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x18a, 4, 0),
    OAM_ENTRY(0, 64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x1ac, 4, 0),
    OAM_ENTRY(32, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1b0, 4, 0),
    OAM_ENTRY(0, 80, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1ec, 4, 0),
    OAM_ENTRY(32, 80, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1f0, 4, 0)
};

static const u16 sMiscOam_PlasmaBeamUnknown_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x18c, 12, 0),
    OAM_ENTRY(28, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x190, 12, 0)
};

static const u16 sMiscOam_SpaceJumpUnknown_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18c, 12, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x192, 12, 0),
    OAM_ENTRY(36, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x196, 12, 0),
    OAM_ENTRY(52, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x198, 12, 0)
};

static const u16 sMiscOam_GravityUnknown_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x18c, 12, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x199, 12, 0),
    OAM_ENTRY(36, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x19d, 12, 0),
    OAM_ENTRY(52, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x19f, 12, 0)
};

static const u16 sMiscOam_PlasmaBeamKnown_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xa0, 12, 0),
    OAM_ENTRY(28, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa4, 12, 0)
};

static const u16 sMiscOam_SpaceJumpKnown_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa0, 12, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xa6, 12, 0),
    OAM_ENTRY(36, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xaa, 12, 0),
    OAM_ENTRY(52, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xac, 12, 0)
};

static const u16 sMiscOam_GravityKnown_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa0, 12, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xad, 12, 0),
    OAM_ENTRY(36, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xb1, 12, 0),
    OAM_ENTRY(52, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb3, 12, 0)
};


static const struct FrameData sSamusIconOam_Suit[9] = {
    [0] = {
        .pFrame = sSamusIconOam_Suit_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sSamusIconOam_Suit_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSamusIconOam_Suit_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSamusIconOam_Suit_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = ONE_THIRD_SECOND
    },
    [5] = {
        .pFrame = sSamusIconOam_Suit_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSamusIconOam_Suit_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_RightCursor[5] = {
    [0] = {
        .pFrame = sMiscOam_RightCursor_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_RightCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_RightCursor_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMiscOam_RightCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DownCursor[5] = {
    [0] = {
        .pFrame = sMiscOam_DownCursor_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_DownCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_DownCursor_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMiscOam_DownCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Up[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Up_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Up_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Up_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Up_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Down[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Down_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Down_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Down_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Down_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Left[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Left_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Left_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Left_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Left_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Right[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Right_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Right_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Right_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Right_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Unused[2] = {
    [0] = {
        .pFrame = sBorderArrowOam_Unused_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_UpArrow[8] = {
    [0] = {
        .pFrame = sTargetOam_UpArrow_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_UpArrow_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_UpArrow_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_UpArrow_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_UpArrow_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_UpArrow_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_DownArrow[8] = {
    [0] = {
        .pFrame = sTargetOam_DownArrow_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_DownArrow_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_DownArrow_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_DownArrow_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_DownArrow_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_DownArrow_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DownloadLineTrail[5] = {
    [0] = {
        .pFrame = sMiscOam_DownloadLine_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMiscOam_DownloadLineTrail_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMiscOam_DownloadLineTrail_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMiscOam_DownloadLineTrail_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DownloadLine[2] = {
    [0] = {
        .pFrame = sMiscOam_DownloadLine_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Brinstar[2] = {
    [0] = {
        .pFrame = sOverlayOam_Brinstar_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Kraid[2] = {
    [0] = {
        .pFrame = sOverlayOam_Kraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Norfair[2] = {
    [0] = {
        .pFrame = sOverlayOam_Norfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Ridley[2] = {
    [0] = {
        .pFrame = sOverlayOam_Ridley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Tourian[2] = {
    [0] = {
        .pFrame = sOverlayOam_Tourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Crateria[2] = {
    [0] = {
        .pFrame = sOverlayOam_Crateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Chozodia[2] = {
    [0] = {
        .pFrame = sOverlayOam_Chozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_AreaNameSpawning[10] = {
    [0] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_EnergyTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_EnergyTanks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MissileTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_MissileTanks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SuperMissileTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_SuperMissileTanks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_PowerBombTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_PowerBombTanks_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_Target[5] = {
    [0] = {
        .pFrame = sTargetOam_Target_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_Target_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_Target_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_Target_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_EnergyHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_EnergyHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BeamHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_BeamHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MissileHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_MissileHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BombHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_BombHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SuitHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_SuitHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MiscHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_MiscHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SamusPowerSuitWireframe[2] = {
    [0] = {
        .pFrame = sMiscOam_SamusPowerSuitWireFrame_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SamusFullSuitWireframe[2] = {
    [0] = {
        .pFrame = sMiscOam_SamusFullSuitWireFrame_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BeamLinker[11] = {
    [0] = {
        .pFrame = sMiscOam_BeamLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_BeamLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_BeamLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_BeamLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_BeamLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_BeamLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_BeamLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_BeamLinker_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMiscOam_BeamLinker_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sMiscOam_BeamLinker_Frame9,
        .timer = UCHAR_MAX
    },
    [10] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MissileLinker[6] = {
    [0] = {
        .pFrame = sMiscOam_MissileLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_MissileLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_MissileLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_MissileLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_MissileLinker_Frame4,
        .timer = UCHAR_MAX
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BombLinker[10] = {
    [0] = {
        .pFrame = sMiscOam_BombLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_BombLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_BombLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_BombLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_BombLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_BombLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_BombLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_BombLinker_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMiscOam_BombLinker_Frame8,
        .timer = UCHAR_MAX
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SuitLinker[10] = {
    [0] = {
        .pFrame = sMiscOam_SuitLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_SuitLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_SuitLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_SuitLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_SuitLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_SuitLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_SuitLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_SuitLinker_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMiscOam_SuitLinker_Frame8,
        .timer = UCHAR_MAX
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MiscLinker[9] = {
    [0] = {
        .pFrame = sMiscOam_MiscLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_MiscLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_MiscLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_MiscLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_MiscLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_MiscLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_MiscLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_MiscLinker_Frame7,
        .timer = UCHAR_MAX
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_ItemCursorIdle[7] = {
    [0] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_SelectOn[2] = {
    [0] = {
        .pFrame = sOverlayOam_SelectOn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_SelectOff[2] = {
    [0] = {
        .pFrame = sOverlayOam_SelectOff_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_InGameTimer[2] = {
    [0] = {
        .pFrame = sMiscOam_InGameTimer_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_RPromptPressed[2] = {
    [0] = {
        .pFrame = sOverlayOam_RPromptPressed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_LPromptPressed[2] = {
    [0] = {
        .pFrame = sOverlayOam_LPromptPressed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_CrateriaOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_CrateriaOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_BrinstarOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_BrinstarOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_KraidOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_KraidOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_NorfairOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_NorfairOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_RidleyOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_RidleyOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_TourianOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_TourianOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozodiaOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozodiaOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedCrateria[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedCrateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameCrateria[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameCrateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedBrinstar[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedBrinstar_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameBrinstar[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameBrinstar_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedKraid[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedKraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameKraid[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameKraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedNorfair[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedNorfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameNorfair[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameNorfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedRidley[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedRidley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameRidley[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameRidley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedTourian[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedTourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameTourian[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameTourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedChozodia[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedChozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameChozodia[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameChozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_Target[8] = {
    [0] = {
        .pFrame = sWorldMapOam_Target_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sWorldMapOam_Target_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sWorldMapOam_Target_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sWorldMapOam_Target_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sWorldMapOam_Target_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sWorldMapOam_Target_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_ItemCursorFocusing[6] = {
    [0] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_TextMarkerDown[3] = {
    [0] = {
        .pFrame = sMiscOam_TextMarkerDown_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMiscOam_TextMarkerDown_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_TextMarkerUp[3] = {
    [0] = {
        .pFrame = sMiscOam_TextMarkerUp_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMiscOam_TextMarkerUp_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Kraid[2] = {
    [0] = {
        .pFrame = sBossIconOam_Kraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Ridley[2] = {
    [0] = {
        .pFrame = sBossIconOam_Ridley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintCrateria[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintCrateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintBrinstar[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintBrinstar_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintNorfair[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintNorfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintRidley[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintRidley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintTourian[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintTourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintChozodia[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintChozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintKraid[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintKraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Crossmark[2] = {
    [0] = {
        .pFrame = sBossIconOam_Crossmark_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_GunHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_GunHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSamusIconOam_Suitless[9] = {
    [0] = {
        .pFrame = sSamusIconOam_Suitless_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sSamusIconOam_Suitless_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSamusIconOam_Suitless_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSamusIconOam_Suitless_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = ONE_THIRD_SECOND
    },
    [5] = {
        .pFrame = sSamusIconOam_Suitless_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suitless_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSamusIconOam_Suitless_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Ship[2] = {
    [0] = {
        .pFrame = sBossIconOam_Ship_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_GreenFlameSpawning[7] = {
    [0] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_GreenFlame[5] = {
    [0] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_GreenFlameMoving[17] = {
    [0] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_PurpleFlameSpawning[7] = {
    [0] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_PurpleFlame[5] = {
    [0] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_PurpleFlameMoving[17] = {
    [0] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SamusSuitlessWireframe[2] = {
    [0] = {
        .pFrame = sMiscOam_SamusSuitlessWireframe_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_PlasmaBeamUnknown[2] = {
    [0] = {
        .pFrame = sMiscOam_PlasmaBeamUnknown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SpaceJumpUnknown[2] = {
    [0] = {
        .pFrame = sMiscOam_SpaceJumpUnknown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_GravityUnknown[2] = {
    [0] = {
        .pFrame = sMiscOam_GravityUnknown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_PlasmaBeamKnown[2] = {
    [0] = {
        .pFrame = sMiscOam_PlasmaBeamKnown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SpaceJumpKnown[2] = {
    [0] = {
        .pFrame = sMiscOam_SpaceJumpKnown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_GravityKnown[2] = {
    [0] = {
        .pFrame = sMiscOam_GravityKnown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u16 sMiscOam_DebugCursor_Frame0[OAM_DATA_SIZE(0)] = {
    0
};

static const u16 sMiscOam_DebugCursor_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f4, 3, 0)
};

static const u16 sMiscOam_DebugSelector_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 3, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x263, 3, 0)
};

static const u16 sMiscOam_DebugSelector_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 3, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x263, 3, 0)
};

static const u16 sMiscOam_DebugSelector_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 3, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x263, 3, 0)
};

static const u16 sMiscOam_DebugSamusHeadAndArrows_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f3, 11, 0),
    OAM_ENTRY(-7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x240, 3, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x260, 3, 0),
    OAM_ENTRY(-12, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2fa, 6, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x97, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x99, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9a, 8, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9c, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x9d, 8, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9f, 8, 0)
};

static const struct FrameData sMiscOam_DebugCursor[3] = {
    [0] = {
        .pFrame = sMiscOam_DebugCursor_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_DebugCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DebugSelector[5] = {
    [0] = {
        .pFrame = sMiscOam_DebugSelector_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMiscOam_DebugSelector_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_DebugSelector_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMiscOam_DebugSelector_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DebugSamusHeadAndArrows[2] = {
    [0] = {
        .pFrame = sMiscOam_DebugSamusHeadAndArrows_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};


const u32 sMotifBehindWireframeSamusGfx[278] = INCBIN_U32("data/menus/pause_screen/motif_behind_wireframe_samus.gfx.lz");
const u32 sPauseScreenHudGfx[1404] = INCBIN_U32("data/menus/pause_screen/pause_screen_hud.gfx.lz");
const u32 sMinimapLettersGfx[60] = INCBIN_U32("data/menus/pause_screen/minimap_letters.gfx.lz");

const u32 sMenuNamesJapaneseGfx[92] = INCBIN_U32("data/menus/pause_screen/menu_names_japanese.gfx.lz");
const u32 sEquipmentNamesJapaneseGfx[384] = INCBIN_U32("data/menus/pause_screen/equipment_names_japanese.gfx.lz");

const u32 sTankIconsGfx[1786] = INCBIN_U32("data/menus/pause_screen/tank_icons.gfx.lz");

const u32 sMapScreenAreaNamesEnglishGfx[216] = INCBIN_U32("data/menus/pause_screen/map_screen_area_names_english.gfx.lz");
const u32 sMapScreenUnknownItemsNamesJapaneseGfx[65] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_japanese.gfx.lz");
const u32 sMapScreenChozoStatueAreaNamesEnglishGfx[152] = INCBIN_U32("data/menus/pause_screen/map_screen_chozo_statue_area_names_english.gfx.lz");

const u32 sChozoHintBackgroundGfx[3618] = INCBIN_U32("data/menus/pause_screen/chozo_hint_background.gfx.lz");

const u32 sBrinstarMinimap[133] = INCBIN_U32("data/menus/pause_screen/brinstar_minimap.tt");
const u32 sKraidMinimap[121] = INCBIN_U32("data/menus/pause_screen/kraid_minimap.tt");
const u32 sNorfairMinimap[153] = INCBIN_U32("data/menus/pause_screen/norfair_minimap.tt");
const u32 sRidleyMinimap[120] = INCBIN_U32("data/menus/pause_screen/ridley_minimap.tt");
const u32 sTourianMinimap[91] = INCBIN_U32("data/menus/pause_screen/tourian_minimap.tt");
const u32 sCrateriaMinimap[114] = INCBIN_U32("data/menus/pause_screen/crateria_minimap.tt");
const u32 sChozodiaMinimap[194] = INCBIN_U32("data/menus/pause_screen/chozodia_minimap.tt");
const u32 sTestMinimap[78] = INCBIN_U32("data/menus/pause_screen/test_minimap.tt");

const u32 sDebugMenuTileParts[175] = INCBIN_U32("data/menus/pause_screen/debug_menu_tile_parts.tt");
const u32 sMapScreenVisorOverlayTilemap[122] = INCBIN_U32("data/menus/pause_screen/map_screen_visor_overlay.tt");
const u32 sMapScreenOverlayTilemap[125] = INCBIN_U32("data/menus/pause_screen/map_screen_overlay.tt");
const u32 sWorldMapOverlayTilemap[206] = INCBIN_U32("data/menus/pause_screen/world_map_overlay.tt");
const u32 sStatusScreenTilemap[264] = INCBIN_U32("data/menus/pause_screen/status_screen.tt");
const u32 sEasySleepTilemap[196] = INCBIN_U32("data/menus/pause_screen/easy_sleep.tt");
const u32 sStatusScreenBackgroundTilemap[169] = INCBIN_U32("data/menus/pause_screen/status_screen_background.tt");
const u32 sMapScreenTextBg0TileTable[92] = INCBIN_U32("data/menus/pause_screen/map_screen_text_bg0.tt");
const u32 sChozoHintBackgroundTileTable[577] = INCBIN_U32("data/menus/pause_screen/chozo_hint_background.tt");

const u32 sEquipmentNamesHiraganaGfx[411] = INCBIN_U32("data/menus/pause_screen/equipment_names_hiragana.gfx.lz");
const u32 sEquipmentNamesEnglishGfx[380] = INCBIN_U32("data/menus/pause_screen/equipment_names_english.gfx.lz");
const u32 sEquipmentNamesGermanGfx[] = INCBIN_U32("data/menus/pause_screen/equipment_names_german.gfx.lz");
const u32 sEquipmentNamesFrenchGfx[] = INCBIN_U32("data/menus/pause_screen/equipment_names_french.gfx.lz");
const u32 sEquipmentNamesItalianGfx[] = INCBIN_U32("data/menus/pause_screen/equipment_names_italian.gfx.lz");
const u32 sEquipmentNamesSpanishGfx[] = INCBIN_U32("data/menus/pause_screen/equipment_names_spanish.gfx.lz");


const u32 sMapScreenAreaNamesHiraganaGfx[198] = INCBIN_U32("data/menus/pause_screen/map_screen_area_names_hiragana.gfx.lz");

const u32 sMenuNamesHiraganaGfx[113] = INCBIN_U32("data/menus/pause_screen/menu_names_hiragana.gfx.lz");
const u32 sMenuNamesEnglishGfx[92] = INCBIN_U32("data/menus/pause_screen/menu_names_english.gfx.lz");
const u32 sMenuNamesGermanGfx[97] = INCBIN_U32("data/menus/pause_screen/menu_names_german.gfx.lz");
const u32 sMenuNamesFrenchGfx[91] = INCBIN_U32("data/menus/pause_screen/menu_names_french.gfx.lz");
const u32 sMenuNamesItalianGfx[] = INCBIN_U32("data/menus/pause_screen/menu_names_italian.gfx.lz");
const u32 sMenuNamesSpanishGfx[] = INCBIN_U32("data/menus/pause_screen/menu_names_spanish.gfx.lz");

const u32 sMapScreenUnknownItemsNamesHiraganaGfx[76] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_hiragana.gfx.lz");
const u32 sMapScreenUnknownItemsNamesEnglishGfx[65] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_english.gfx.lz");
const u32 sMapScreenUnknownItemsNamesGermanGfx[] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_german.gfx.lz");
const u32 sMapScreenUnknownItemsNamesFrenchGfx[] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_french.gfx.lz");
const u32 sMapScreenUnknownItemsNamesItalianGfx[] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_italian.gfx.lz");
const u32 sMapScreenUnknownItemsNamesSpanishGfx[] = INCBIN_U32("data/menus/pause_screen/map_screen_unknown_items_names_spanish.gfx.lz");

const u32 sMapScreenChozoStatueAreaNamesHiraganaGfx[154] = INCBIN_U32("data/menus/pause_screen/map_screen_chozo_statue_area_names_hiragana.gfx.lz");

const struct MenuOamData sMenuOamData_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 4,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const struct MenuOamData sMenuOamDataChozoHint_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 3,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const struct MenuOamData sMenuOamDataEraseSram_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 1,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const struct CutsceneOamData sCutsceneOam_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .padding_4 = { 0, 0, 0, 0 },
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 4,
    .rotationScaling = FALSE,
    .actions = 0,
    .xVelocity = 0,
    .yVelocity = 0,
    .unk_12 = 0,
    .timer = 0,
    .unk_16 = 0,
    .unk_18 = 0,
    .unk_1A = 0,
    .padding_1C = { 0, 0 },
    .unk_1E = 0
};

const struct MenuOamData sMenuOamDataMinimapRoomInfo = {
    .yPosition = 0x20,
    .xPosition = 0x350,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0x37,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = TRUE,
    .exists = TRUE,
    .boundBackground = 4,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const u16 sPauseScreen_BgCntPriority[4] = {
    [BGCNT_HIGH_PRIORITY] = BGCNT_HIGH_PRIORITY,
    [BGCNT_HIGH_MID_PRIORITY] = BGCNT_HIGH_MID_PRIORITY,
    [BGCNT_LOW_MID_PRIORITY] = BGCNT_LOW_MID_PRIORITY,
    [BGCNT_LOW_PRIORITY] = BGCNT_LOW_PRIORITY
};

const struct PauseScreenAreaIconData sPauseScreenAreaIconsData[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = {
        .nameOamId = OVERLAY_OAM_ID_BRINSTAR,
        .nameSpawningOamId = OVERLAY_OAM_ID_BRINSTAR_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_BRINSTAR_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 12
    },
    [AREA_KRAID] = {
        .nameOamId = OVERLAY_OAM_ID_KRAID,
        .nameSpawningOamId = OVERLAY_OAM_ID_KRAID_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_KRAID_OUTLINE,
        .xPosition = BLOCK_SIZE * 12,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 12
    },
    [AREA_NORFAIR] = {
        .nameOamId = OVERLAY_OAM_ID_NORFAIR,
        .nameSpawningOamId = OVERLAY_OAM_ID_NORFAIR_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_NORFAIR_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 + 8,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 4
    },
    [AREA_RIDLEY] = {
        .nameOamId = OVERLAY_OAM_ID_RIDLEY,
        .nameSpawningOamId = OVERLAY_OAM_ID_RIDLEY_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_RIDLEY_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 + 4,
        .yPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_TOURIAN] = {
        .nameOamId = OVERLAY_OAM_ID_TOURIAN,
        .nameSpawningOamId = OVERLAY_OAM_ID_TOURIAN_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_TOURIAN_OUTLINE,
        .xPosition = BLOCK_SIZE * 11 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 8
    },
    [AREA_CRATERIA] = {
        .nameOamId = OVERLAY_OAM_ID_CRATERIA,
        .nameSpawningOamId = OVERLAY_OAM_ID_CRATERIA_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_CRATERIA_OUTLINE,
        .xPosition = BLOCK_SIZE * 12 + 12,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 4
    },
    [AREA_CHOZODIA] = {
        .nameOamId = OVERLAY_OAM_ID_CHOZODIA,
        .nameSpawningOamId = OVERLAY_OAM_ID_CHOZODIA_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_CHOZODIA_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 + HALF_BLOCK_SIZE + 4,
        .yPosition = BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + 4
    },
    [AREA_TEST] = {
        .nameOamId = OVERLAY_OAM_ID_NONE,
        .nameSpawningOamId = OVERLAY_OAM_ID_NONE,
        .outlineOamId = OVERLAY_OAM_ID_NONE,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = -QUARTER_BLOCK_SIZE
    }
};

// right, left, up, down?
// borderArrowsOam_id index, oam_id, x_position, y_position
const u16 sMapScreenArrowsData[4][4] = {
    {
        1, BORDER_ARROW_OAM_ID_RIGHT, BLOCK_SIZE * 14 + 8, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE
    },
    {
        0, BORDER_ARROW_OAM_ID_LEFT, QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE
    },
    {
        2, BORDER_ARROW_OAM_ID_UP, BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + 8
    },
    {
        3, BORDER_ARROW_OAM_ID_DOWN, BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE + 8
    }
};

const BeamBombFlags sStatusScreenBeamFlagsOrder[STATUS_SCREEN_BEAM_OFFSET_COUNT] = {
    [STATUS_SCREEN_BEAM_OFFSET_LONG] = BBF_LONG_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_CHARGE] = BBF_CHARGE_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_ICE] = BBF_ICE_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_WAVE] = BBF_WAVE_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_PLASMA] = BBF_PLASMA_BEAM
};

const BeamBombFlags sStatusScreenBombFlagsOrder[1] = {
    BBF_BOMBS
};

const SuitMiscFlags sStatusScreenSuitFlagsOrder[STATUS_SCREEN_SUIT_OFFSET_COUNT] = {
    [STATUS_SCREEN_SUIT_OFFSET_VARIA] = SMF_VARIA_SUIT,
    [STATUS_SCREEN_SUIT_OFFSET_GRAVITY] = SMF_GRAVITY_SUIT
};

const SuitMiscFlags sStatusScreenMiscFlagsOrder[STATUS_SCREEN_MISC_OFFSET_COUNT] = {
    [STATUS_SCREEN_MISC_OFFSET_MORPH_BALL] = SMF_MORPH_BALL,
    [STATUS_SCREEN_MISC_OFFSET_POWER_GRIP] = SMF_POWER_GRIP,
    [STATUS_SCREEN_MISC_OFFSET_SPEED_BOOSTER] = SMF_SPEEDBOOSTER,
    [STATUS_SCREEN_MISC_OFFSET_HIGH_JUMP] = SMF_HIGH_JUMP,
    [STATUS_SCREEN_MISC_OFFSET_SCREW_ATTACK] = SMF_SCREW_ATTACK,
    [STATUS_SCREEN_MISC_OFFSET_SPACE_JUMP] = SMF_SPACE_JUMP
};

const u8 sStatusScreenFlagsSize[ABILITY_GROUP_STATUS_GROUPS_COUNT] = {
    [ABILITY_GROUP_BEAMS] = ARRAY_SIZE(sStatusScreenBeamFlagsOrder),
    [ABILITY_GROUP_BOMBS] = ARRAY_SIZE(sStatusScreenBombFlagsOrder),
    [ABILITY_GROUP_SUITS] = ARRAY_SIZE(sStatusScreenSuitFlagsOrder),
    [ABILITY_GROUP_MISC] = ARRAY_SIZE(sStatusScreenMiscFlagsOrder)
};

const u16 sPowersOfTen[5] = {
    1, 10, 100, 1000, 10000
};

const struct PauseScreenWireframeData sSamusWireframeData[SAMUS_WIREFRAME_DATA_COUNT] = {
    [SAMUS_WIREFRAME_DATA_ENERGY] = {
        .oamId = MISC_OAM_ID_ENERGY_HEADER,
        .xPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 15,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .yPosition2 = BLOCK_SIZE - QUARTER_BLOCK_SIZE 
    },
    [SAMUS_WIREFRAME_DATA_BEAM] = {
        .oamId = MISC_OAM_ID_BEAM_HEADER,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 16,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 4,
        .yPosition2 = BLOCK_SIZE * 2
    },
    [SAMUS_WIREFRAME_DATA_MISSILE] = {
        .oamId = MISC_OAM_ID_MISSILE_HEADER,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 17,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 4 + 4,
        .yPosition2 = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 4
    },
    [SAMUS_WIREFRAME_DATA_BOMB] = {
        .oamId = MISC_OAM_ID_BOMB_HEADER,
        .xPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 9 + 4,
        .yPosition2 = BLOCK_SIZE
    },
    [SAMUS_WIREFRAME_DATA_SUIT] = {
        .oamId = MISC_OAM_ID_SUIT_HEADER,
        .xPosition = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 10 + 4,
        .yPosition2 = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 4
    },
    [SAMUS_WIREFRAME_DATA_MISC] = {
        .oamId = MISC_OAM_ID_MISC_HEADER,
        .xPosition = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 11 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 10 + 4,
        .yPosition2 = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + 4
    },
    [SAMUS_WIREFRAME_DATA_SAMUS_POWER_SUIT_WIREFRAME] = {
        .oamId = MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME,
        .xPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .xOffset = 0,
        .objMode = 1,
        .xPosition2 = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .yPosition2 = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE
    }
};

const u16 sChozoHintAreaNamesPosition[2] = {
    0x80, 0x28
};

const u8 sChozoHintAreaNamesOamIds[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = OVERLAY_OAM_ID_CHOZO_HINT_BRINSTAR,
    [AREA_KRAID] = OVERLAY_OAM_ID_CHOZO_HINT_KRAID,
    [AREA_NORFAIR] = OVERLAY_OAM_ID_CHOZO_HINT_NORFAIR,
    [AREA_RIDLEY] = OVERLAY_OAM_ID_CHOZO_HINT_RIDLEY,
    [AREA_TOURIAN] = OVERLAY_OAM_ID_CHOZO_HINT_TOURIAN,
    [AREA_CRATERIA] = OVERLAY_OAM_ID_CHOZO_HINT_CRATERIA,
    [AREA_CHOZODIA] = OVERLAY_OAM_ID_CHOZO_HINT_CHOZODIA,
    [AREA_TEST] = 0
};

const struct WorldMapData sWorldMapData[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_BRINSTAR,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_BRINSTAR,
        .xPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 + 8
    },
    [AREA_KRAID] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_KRAID,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_KRAID,
        .xPosition = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 12,
        .yPosition = BLOCK_SIZE * 7 + 12
    },
    [AREA_NORFAIR] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_NORFAIR,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_NORFAIR,
        .xPosition = BLOCK_SIZE * 9 + 8,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_RIDLEY] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_RIDLEY,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_RIDLEY,
        .xPosition = BLOCK_SIZE * 9,
        .yPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_TOURIAN] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_TOURIAN,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_TOURIAN,
        .xPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + 4,
        .yPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE + 12
    },
    [AREA_CRATERIA] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_CRATERIA,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_CRATERIA,
        .xPosition = BLOCK_SIZE * 6 + 8,
        .yPosition = BLOCK_SIZE * 3 + 8
    },
    [AREA_CHOZODIA] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_CHOZODIA,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_CHOZODIA,
        .xPosition = BLOCK_SIZE * 10,
        .yPosition = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4
    }
};

const u16 sWorldMapTargetPositions[16][2] = {
    [0] = { BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE + 8 },
    [1] = { BLOCK_SIZE * 10 - 4, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE + 12 },
    [2] = { BLOCK_SIZE * 10 + HALF_BLOCK_SIZE + 4, BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + 8 },
    [3] = { BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 8, BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 4 },
    [4] = { BLOCK_SIZE * 11 - QUARTER_BLOCK_SIZE + 4, BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 8 },
    [5] = { BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE * 4 + 12 },
    [6] = { BLOCK_SIZE * 8 + 12, BLOCK_SIZE * 7 + 8 },
    [7] = { BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 8, BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 4 },
    [8] = { 0, 0 },
    [9] = { 0, 0 },
    [10] = { 0, 0 },
    [11] = { 0, 0 },
    [12] = { 0, 0 },
    [13] = { 0, 0 },
    [14] = { 0, 0 },
    [15] = { 0, 0 }
};

/**
 * 0 : Associated event
 * 1 : Boss icon OAM ID
 * 2 : X position
 * 3 : Y position
 * 4 : X offset
 */
const u8 sBossIcons[AREA_NORMAL_COUNT][5] = {
    [AREA_BRINSTAR] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_KRAID] = {
        EVENT_KRAID_KILLED,
        BOSS_ICON_OAM_ID_KRAID,
        9,
        14,
        0
    },
    [AREA_NORFAIR] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_RIDLEY] = {
        EVENT_RIDLEY_KILLED,
        BOSS_ICON_OAM_ID_RIDLEY,
        7,
        6,
        0
    },
    [AREA_TOURIAN] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_CRATERIA] = {
        EVENT_ESCAPED_ZEBES,
        0,
        9,
        7,
        4
    },
    [AREA_CHOZODIA] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    }
};

const u16 sMapChunksToUpdate[3] = {
    0x1C, 0x5C, 0xD4
};




const struct OamArray sPauseScreenMiscOam[MISC_OAM_ID_COUNT] = {
    [MISC_OAM_ID_NONE] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [MISC_OAM_ID_SAMUS_ICON_SUIT] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_RIGHT_CURSOR] = {
        .pOam = sMiscOam_RightCursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_DOWN_CURSOR] = {
        .pOam = sMiscOam_DownCursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_TEXT_MARKER_DOWN] = {
        .pOam = sMiscOam_TextMarkerDown,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_TEXT_MARKER_UP] = {
        .pOam = sMiscOam_TextMarkerUp,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_ITEM_CURSOR_FOCUSING] = {
        .pOam = sMiscOam_ItemCursorFocusing,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [MISC_OAM_ID_ITEM_CURSOR_IDLE] = {
        .pOam = sMiscOam_ItemCursorIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_AREA_UP_ARROW] = {
        .pOam = sTargetOam_UpArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_AREA_DOWN_ARROW] = {
        .pOam = sTargetOam_DownArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_MAP_DOWNLOAD_LINE_TRAIL] = {
        .pOam = sMiscOam_DownloadLineTrail,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [MISC_OAM_ID_MAP_DOWNLOAD_LINE] = {
        .pOam = sMiscOam_DownloadLine,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MAP_DOWNLOAD_LINE_BLINKING] = {
        .pOam = sMiscOam_DownloadLineTrail,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_ITEM_CURSOR_FOCUSING_DESTROY] = {
        .pOam = sMiscOam_ItemCursorFocusing,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [MISC_OAM_ID_IN_GAME_TIMER] = {
        .pOam = sMiscOam_InGameTimer,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_ENERGY_TANKS] = {
        .pOam = sMiscOam_EnergyTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MISSILE_TANKS] = {
        .pOam = sMiscOam_MissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SUPER_MISSILE_TANKS] = {
        .pOam = sMiscOam_SuperMissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_POWER_BOMB_TANKS] = {
        .pOam = sMiscOam_PowerBombTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [19] = {
        .pOam = sMiscOam_EnergyTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [20] = {
        .pOam = sMiscOam_MissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [21] = {
        .pOam = sMiscOam_SuperMissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [22] = {
        .pOam = sMiscOam_PowerBombTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_ENERGY_HEADER] = {
        .pOam = sMiscOam_EnergyHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [24] = {
        .pOam = sMiscOam_EnergyHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [25] = {
        .pOam = sMiscOam_EnergyHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [MISC_OAM_ID_BEAM_HEADER] = {
        .pOam = sMiscOam_BeamHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_BEAM_LINKER] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [28] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [MISC_OAM_ID_MISSILE_HEADER] = {
        .pOam = sMiscOam_MissileHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MISSILE_LINKER] = {
        .pOam = sMiscOam_MissileLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [31] = {
        .pOam = sMiscOam_MissileLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [MISC_OAM_ID_BOMB_HEADER] = {
        .pOam = sMiscOam_BombHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_BOMB_LINKER] = {
        .pOam = sMiscOam_BombLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [34] = {
        .pOam = sMiscOam_BombLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [MISC_OAM_ID_SUIT_HEADER] = {
        .pOam = sMiscOam_SuitHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SUIT_LINKER] = {
        .pOam = sMiscOam_SuitLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [37] = {
        .pOam = sMiscOam_SuitLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [MISC_OAM_ID_MISC_HEADER] = {
        .pOam = sMiscOam_MiscHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MISC_LINKER] = {
        .pOam = sMiscOam_MiscLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [40] = {
        .pOam = sMiscOam_MiscLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [MISC_OAM_ID_GUN_HEADER] = {
        .pOam = sMiscOam_GunHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_GUN_LINKER] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [43] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME] = {
        .pOam = sMiscOam_SamusPowerSuitWireframe,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SAMUS_FULL_SUIT_WIREFRAME] = {
        .pOam = sMiscOam_SamusFullSuitWireframe,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SAMUS_SUITLESS_WIREFRAME] = {
        .pOam = sMiscOam_SamusSuitlessWireframe,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_PLASMA_UNKNOWN] = {
        .pOam = sMiscOam_PlasmaBeamUnknown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_PLASMA_KNOWN] = {
        .pOam = sMiscOam_PlasmaBeamKnown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SPACE_JUMP_UNKNOWN] = {
        .pOam = sMiscOam_SpaceJumpUnknown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SPACE_JUMP_KNOWN] = {
        .pOam = sMiscOam_SpaceJumpKnown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_GRAVITY_UNKNOWN] = {
        .pOam = sMiscOam_GravityUnknown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_GRAVITY_KNOWN] = {
        .pOam = sMiscOam_GravityKnown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_DEBUG_CURSOR] = {
        .pOam = sMiscOam_DebugCursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_DEBUG_SELECTOR] = {
        .pOam = sMiscOam_DebugSelector,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_DEBUG_SAMUS_HEAD_AND_ARROWS] = {
        .pOam = sMiscOam_DebugSamusHeadAndArrows,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const struct OamArray sPauseScreenOverlayOam[OVERLAY_OAM_ID_COUNT] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [OVERLAY_OAM_ID_BRINSTAR] = {
        .pOam = sOverlayOam_Brinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_BRINSTAR_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_KRAID] = {
        .pOam = sOverlayOam_Kraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_KRAID_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_NORFAIR] = {
        .pOam = sOverlayOam_Norfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_NORFAIR_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_RIDLEY] = {
        .pOam = sOverlayOam_Ridley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_RIDLEY_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_TOURIAN] = {
        .pOam = sOverlayOam_Tourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_TOURIAN_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_CRATERIA] = {
        .pOam = sOverlayOam_Crateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CRATERIA_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_CHOZODIA] = {
        .pOam = sOverlayOam_Chozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZODIA_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_R_PROMPT_PRESSED] = {
        .pOam = sOverlayOam_RPromptPressed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_L_PROMPT_PRESSED] = {
        .pOam = sOverlayOam_LPromptPressed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_SELECT_ON] = {
        .pOam = sOverlayOam_SelectOn,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_SELECT_OFF] = {
        .pOam = sOverlayOam_SelectOff,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_BRINSTAR_OUTLINE] = {
        .pOam = sOverlayOam_BrinstarOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_KRAID_OUTLINE] = {
        .pOam = sOverlayOam_KraidOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_NORFAIR_OUTLINE] = {
        .pOam = sOverlayOam_NorfairOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_RIDLEY_OUTLINE] = {
        .pOam = sOverlayOam_RidleyOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_TOURIAN_OUTLINE] = {
        .pOam = sOverlayOam_TourianOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CRATERIA_OUTLINE] = {
        .pOam = sOverlayOam_CrateriaOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZODIA_OUTLINE] = {
        .pOam = sOverlayOam_ChozodiaOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_BRINSTAR] = {
        .pOam = sOverlayOam_ChozoHintBrinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_KRAID] = {
        .pOam = sOverlayOam_ChozoHintKraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_NORFAIR] = {
        .pOam = sOverlayOam_ChozoHintNorfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_RIDLEY] = {
        .pOam = sOverlayOam_ChozoHintRidley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_TOURIAN] = {
        .pOam = sOverlayOam_ChozoHintTourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_CRATERIA] = {
        .pOam = sOverlayOam_ChozoHintCrateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_CHOZODIA] = {
        .pOam = sOverlayOam_ChozoHintChozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const struct OamArray sPauseScreenBorderArrowsOam[BORDER_ARROW_OAM_ID_COUNT] = {
    [BORDER_ARROW_OAM_ID_NONE] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [BORDER_ARROW_OAM_ID_UP] = {
        .pOam = sBorderArrowOam_Up,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [BORDER_ARROW_OAM_ID_DOWN] = {
        .pOam = sBorderArrowOam_Down,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [BORDER_ARROW_OAM_ID_LEFT] = {
        .pOam = sBorderArrowOam_Left,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [BORDER_ARROW_OAM_ID_RIGHT] = {
        .pOam = sBorderArrowOam_Right,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const struct OamArray sPauseScreenSamusIconOam[SAMUS_ICON_OAM_ID_COUNT] = {
    [SAMUS_ICON_OAM_ID_NONE] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [SAMUS_ICON_OAM_ID_SUIT] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [SAMUS_ICON_OAM_ID_SUITLESS] = {
        .pOam = sSamusIconOam_Suitless,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const struct OamArray sPauseScreenBossIconsOam[BOSS_ICON_OAM_ID_COUNT] = {
    [BOSS_ICON_OAM_ID_NONE] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [BOSS_ICON_OAM_ID_KRAID] = {
        .pOam = sBossIconOam_Kraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [BOSS_ICON_OAM_ID_RIDLEY] = {
        .pOam = sBossIconOam_Ridley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [BOSS_ICON_OAM_ID_CROSSMARK] = {
        .pOam = sBossIconOam_Crossmark,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [BOSS_ICON_OAM_ID_SHIP] = {
        .pOam = sBossIconOam_Ship,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const struct OamArray sPauseScreenTargetsOam[TARGET_OAM_COUNT] = {
    [TARGET_OAM_ID_NONE] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [TARGET_OAM_ID_TARGET] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_ID_UP_ARROW] = {
        .pOam = sTargetOam_UpArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_ID_DOWN_ARROW] = {
        .pOam = sTargetOam_DownArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [4] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [5] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [6] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [7] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [TARGET_OAM_GREEN_FLAME_SPAWNING] = {
        .pOam = sTargetOam_GreenFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TARGET_OAM_GREEN_FLAME] = {
        .pOam = sTargetOam_GreenFlame,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_GREEN_FLAME_MOVING] = {
        .pOam = sTargetOam_GreenFlameMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_GREEN_FLAME_DESPAWNING] = {
        .pOam = sTargetOam_GreenFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    },
    [TARGET_OAM_PURPLE_FLAME_SPAWNING] = {
        .pOam = sTargetOam_PurpleFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TARGET_OAM_PURPLE_FLAME] = {
        .pOam = sTargetOam_PurpleFlame,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_PURPLE_FLAME_MOVING] = {
        .pOam = sTargetOam_PurpleFlameMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_PURPLE_FLAME_DESPAWNING] = {
        .pOam = sTargetOam_PurpleFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_PLAY_BACKWARDS
    }
};

const struct OamArray sPauseScreenWorldMapOam[WORLD_MAP_OAM_ID_COUNT] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [WORLD_MAP_OAM_ID_NAME_BRINSTAR] = {
        .pOam = sWorldMapOam_NameBrinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_KRAID] = {
        .pOam = sWorldMapOam_NameKraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_NORFAIR] = {
        .pOam = sWorldMapOam_NameNorfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_RIDLEY] = {
        .pOam = sWorldMapOam_NameRidley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_TOURIAN] = {
        .pOam = sWorldMapOam_NameTourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_CRATERIA] = {
        .pOam = sWorldMapOam_NameCrateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_CHOZODIA] = {
        .pOam = sWorldMapOam_NameChozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_BRINSTAR] = {
        .pOam = sWorldMapOam_OutlinedBrinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_KRAID] = {
        .pOam = sWorldMapOam_OutlinedKraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_NORFAIR] = {
        .pOam = sWorldMapOam_OutlinedNorfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_RIDLEY] = {
        .pOam = sWorldMapOam_OutlinedRidley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_TOURIAN] = {
        .pOam = sWorldMapOam_OutlinedTourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_CRATERIA] = {
        .pOam = sWorldMapOam_OutlinedCrateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_CHOZODIA] = {
        .pOam = sWorldMapOam_OutlinedChozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_TARGET] = {
        .pOam = sWorldMapOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [WORLD_MAP_OAM_ID_SAMUS_ICON_SUIT] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [WORLD_MAP_OAM_ID_SAMUS_ICON_SUITLESS] = {
        .pOam = sSamusIconOam_Suitless,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};


const u8 sMaintainedInputDelays_Fast[7] = {
    20, 4, 4, 4, 4, 4, 2
};

#ifdef REGION_EU
const u8 sMaintainedInputDelays_Slow[4] = {
    20, 8, 8, 6
};

const u8 sMaintainedInputDelaysLastSet[MAINTAINED_INPUT_SPEED_COUNT] = {
    [MAINTAINED_INPUT_SPEED_FAST] = ARRAY_SIZE(sMaintainedInputDelays_Fast) - 1,
    [MAINTAINED_INPUT_SPEED_SLOW] = ARRAY_SIZE(sMaintainedInputDelays_Slow) - 1
};
#endif // REGION_EU

// NOTE: Wrapped in a struct so that it is 4 byte aligned
const struct MapScreenAreaIds sMapScreenAreaIds = {
    .ids = {
        AREA_BRINSTAR,
        AREA_KRAID,
        AREA_NORFAIR,
        AREA_RIDLEY,
        AREA_TOURIAN,
        AREA_CRATERIA,
        AREA_CHOZODIA,
        0x8
    }
};

const u8 sMapScreenAreasViewOrder[MAX_AMOUNT_OF_AREAS] = {
    AREA_CRATERIA,
    AREA_BRINSTAR,
    AREA_KRAID,
    AREA_NORFAIR,
    AREA_RIDLEY,
    AREA_TOURIAN,
    AREA_CHOZODIA,
    AREA_BRINSTAR
};

const struct MinimapAreaName sMinimapAreaNames[10] = {
    [0] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 3 + 1,
        .mapY1 = 13 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_TOURIAN,
        .mapX2 = 18 + 1,
        .mapY2 = 1 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1 
    },
    [1] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 9 + 1,
        .mapY1 = 11 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_BRINSTAR,
        .mapX2 = 2 + 1,
        .mapY2 = 13 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [2] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 15 + 1,
        .mapY1 = 8 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_NORFAIR,
        .mapX2 = 5 + 1,
        .mapY2 = 3 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [3] = {
        .area1 = AREA_BRINSTAR,
        .mapX1 = 22 + 1,
        .mapY1 = 13 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_NORFAIR,
        .mapX2 = 14 + 1,
        .mapY2 = 3 + 1,
        .xOffset2 = -2,
        .yOffset2 = -1
    },
    [4] = {
        .area1 = AREA_BRINSTAR,
        .mapX1 = 6 + 1,
        .mapY1 = 19 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_KRAID,
        .mapX2 = 9 + 1,
        .mapY2 = 4 + 1,
        .xOffset2 = -2,
        .yOffset2 = -1
    },
    [5] = {
        .area1 = AREA_BRINSTAR,
        .mapX1 = 1 + 1,
        .mapY1 = 4 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_TOURIAN,
        .mapX2 = 20 + 1,
        .mapY2 = 2 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [6] = {
        .area1 = AREA_NORFAIR,
        .mapX1 = 17 + 1,
        .mapY1 = 14 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_RIDLEY,
        .mapX2 = 15 + 1,
        .mapY2 = 1 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [7] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 24 + 1,
        .mapY1 = 3 + 1,
        .xOffset1 = 1,
        .yOffset1 = 0,
        .area2 = AREA_CHOZODIA,
        .mapX2 = 2 + 1,
        .mapY2 = 17 + 1,
        .xOffset2 = -1,
        .yOffset2 = 0
    },
    [8] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 24 + 1,
        .mapY1 = 7 + 1,
        .xOffset1 = 1,
        .yOffset1 = 0,
        .area2 = AREA_CHOZODIA,
        .mapX2 = 2 + 1,
        .mapY2 = 21 + 1,
        .xOffset2 = 1,
        .yOffset2 = 1
    },
    [9] = {
        .area1 = UCHAR_MAX,
        .mapX1 = UCHAR_MAX,
        .mapY1 = UCHAR_MAX,
        .xOffset1 = UCHAR_MAX,
        .yOffset1 = UCHAR_MAX,
        .area2 = UCHAR_MAX,
        .mapX2 = UCHAR_MAX,
        .mapY2 = UCHAR_MAX,
        .xOffset2 = UCHAR_MAX,
        .yOffset2 = UCHAR_MAX
    }
};

const u8 sPauseScreen_40d6fc[80] = INCBIN_U8("data/menus/pause_screen/40d6fc.gfx");
const u8 sPauseScreen_40d74c[80] = INCBIN_U8("data/menus/pause_screen/40d74c.gfx");

u8* const sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_COUNT] = {
    [IGT_AND_TANKS_VRAM_ADDRESS_ENERGY_TANKS] = VRAM_BASE + 0x16360,
    [IGT_AND_TANKS_VRAM_ADDRESS_MISSILE_TANKS] = VRAM_BASE + 0x16760,
    [IGT_AND_TANKS_VRAM_ADDRESS_SUPER_MISSILE_TANKS] = VRAM_BASE + 0x16B60,
    [IGT_AND_TANKS_VRAM_ADDRESS_POWER_BOMB_TANKS] = VRAM_BASE + 0x16F60,
    [IGT_AND_TANKS_VRAM_ADDRESS_TIME] = VRAM_BASE + 0x17300
};

// TODO use char defines
const u8 sCharacterWidths[1184] = {
    #ifdef REGION_EU
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    4, 6, 7, 7, 7, 8, 8, 4, 5, 5, 7, 7, 4, 7, 4, 7,
    7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 4, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 6, 6, 7, 7, 6,
    6, 6, 6, 6, 6, 6, 7, 7, 8, 6, 6, 5, 7, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 5, 5, 5, 5, 5, 5, 5, 5, 2, 5, 5, 3, 6, 5, 5,
    5, 5, 5, 5, 5, 5, 6, 6, 6, 5, 6, 5, 3, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 6, 8, 8, 8, 8, 8, 16, 8, 11, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    14, 8, 14, 8, 14, 8, 14, 8, 14, 8, 14, 8, 16, 8, 16, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 8, 13, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 6, 6, 6, 6, 6, 8, 6, 6, 6, 6, 6, 4, 4, 4, 4,
    6, 6, 6, 6, 6, 6, 6, 8, 8, 6, 6, 6, 6, 6, 6, 6,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    5, 5, 5, 5, 5, 5, 8, 5, 5, 5, 5, 5, 4, 4, 4, 4,
    8, 6, 5, 5, 5, 5, 5, 6, 8, 6, 6, 6, 6, 6, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6, 5, 7, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 6, 7, 7, 7, 7, 6, 7, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 6, 6, 6, 6, 5, 6, 6, 2, 5, 5, 3, 6, 6, 6,
    6, 6, 5, 6, 5, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8
    #else // !REGION_EU
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 6, 7, 7, 7, 8, 8, 4, 5, 5, 7, 7, 4, 8, 4, 7,
    7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 4, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 8, 7, 7,
    7, 7, 7, 7, 6, 7, 8, 8, 8, 6, 7, 5, 7, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 6, 6, 6, 6, 5, 6, 6, 2, 5, 5, 3, 6, 6, 6,
    6, 6, 5, 6, 5, 6, 6, 6, 6, 6, 6, 5, 3, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 6, 8, 8, 8, 8, 8, 16, 8, 11, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    14, 8, 14, 8, 14, 8, 14, 8, 14, 8, 14, 8, 16, 8, 16, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 6, 7, 7, 7, 7, 6, 7, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 6, 6, 6, 6, 5, 6, 6, 2, 5, 5, 3, 6, 6, 6,
    6, 6, 5, 6, 5, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8
    #endif // REGION_EU
};

const struct Message sMessage_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageId = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = TRUE,
    .messageEnded = FALSE
};

const struct Message sMessageStoryText_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageId = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const struct Message sMessageFileScreen_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageId = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const struct Message sMessageDescription_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 2,
    .delay = 20,
    .messageId = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const u16 sPauseScreen_40dc90[1 * 16] = INCBIN_U16("data/menus/pause_screen/40dc90.pal");
const u16 sPauseScreen_40dcb0[1 * 16] = INCBIN_U16("data/menus/pause_screen/40dcb0.pal");
const u16 sPauseScreen_40dcd0[1 * 16] = INCBIN_U16("data/menus/pause_screen/40dcd0.pal");

const u8 sPauseScreen_40dcf0[4] = {
    32, 16, 16, 16
};

const u8 sPauseScreen_40dcf4[16] = {
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2
};

const u8 sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS + 1] = {
    [AREA_BRINSTAR] = 0x9E,
    [AREA_KRAID] = 0x9D,
    [AREA_NORFAIR] = 0x9C,
    [AREA_RIDLEY] = 0x9B,
    [AREA_TOURIAN] = 0x9A,
    [AREA_CRATERIA] = 0x9F,
    [AREA_CHOZODIA] = 0x99,
    [AREA_TEST] = 0x98,
    [MAX_AMOUNT_OF_AREAS] = 0x97
};
