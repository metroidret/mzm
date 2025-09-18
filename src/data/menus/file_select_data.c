#include "data/menus/file_select_data.h"
#include "constants/text.h"
#include "macros.h"
#include "gba.h"

const u16 sFileSelectPal[7 * 16] = INCBIN_U16("data/menus/FileSelect/Palette.pal");
const u16 sFileSelect_4548f8[2 * 16] = INCBIN_U16("data/menus/FileSelect/4548f8.pal");
const u16 sFileSelectIconsPal[6 * 16] = INCBIN_U16("data/menus/FileSelect/Icons.pal");

static const u16 sFileSelectOam_SamusHeadTurningOn_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 64, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurningOn_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 66, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurningOn_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 68, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadOff_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 2, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 4, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 6, 0, 0),
};

static const u16 sFileSelectOam_FileAMarkerSelectedRed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 8, 0, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 10, 0, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 72, 0, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 74, 0, 0),
};

static const u16 sFileSelectOam_FileBMarkerSelectedRed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 11, 0, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 13, 0, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 75, 0, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 77, 0, 0),
};

static const u16 sFileSelectOam_FileCMarkerSelectedRed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 14, 0, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 16, 0, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 78, 0, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 80, 0, 0),
};

static const u16 sFileSelectOam_FileAMarkerIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 17, 0, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 19, 0, 0),
};

static const u16 sFileSelectOam_FileBMarkerIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 20, 0, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 22, 0, 0),
};

static const u16 sFileSelectOam_FileCMarkerIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 23, 0, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 25, 0, 0),
};

static const u16 sFileSelectOam_FileAMarkerSelectedGreen_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 104, 0, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 106, 0, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 168, 0, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 170, 0, 0),
};

static const u16 sFileSelectOam_FileBMarkerSelectedGreen_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 107, 0, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 109, 0, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 171, 0, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 173, 0, 0),
};

static const u16 sFileSelectOam_FileCMarkerSelectedGreen_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 110, 0, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 112, 0, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 174, 0, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 176, 0, 0),
};

static const u16 sFileSelectOam_CursorSelected_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 27, 0, 0),
};

static const u16 sFileSelectOam_Cursor_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 1, 0),
};

static const u16 sFileSelectOam_Cursor_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-19, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 1, 0),
};

static const u16 sFileSelectOam_Cursor_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-21, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 26, 1, 0),
};

static const u16 sOptionsOam_GbaIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 81, 1, 0),
};

static const u16 sOptionsOam_SpeakersIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 85, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 1, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 160, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 258, 1, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 162, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 1, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 164, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 1, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 166, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 128, 1, 0),
    OAM_ENTRY(-24, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 130, 1, 0),
    OAM_ENTRY(-24, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 258, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 132, 1, 0),
    OAM_ENTRY(-24, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 260, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 134, 1, 0),
    OAM_ENTRY(-24, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 262, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 256, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 258, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 260, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -52, OAM_DIMS_16x16, OAM_Y_FLIP, 256, 1, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 160, 1, 0),
    OAM_ENTRY(-24, -36, OAM_DIMS_16x8, OAM_Y_FLIP, 224, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -52, OAM_DIMS_16x16, OAM_Y_FLIP, 258, 1, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 162, 1, 0),
    OAM_ENTRY(-24, -36, OAM_DIMS_16x8, OAM_Y_FLIP, 226, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -52, OAM_DIMS_16x16, OAM_Y_FLIP, 260, 1, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 164, 1, 0),
    OAM_ENTRY(-24, -36, OAM_DIMS_16x8, OAM_Y_FLIP, 228, 1, 0),
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-24, -52, OAM_DIMS_16x16, OAM_Y_FLIP, 262, 1, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_16x16, OAM_Y_FLIP, 166, 1, 0),
    OAM_ENTRY(-24, -36, OAM_DIMS_16x8, OAM_Y_FLIP, 230, 1, 0),
};

static const u16 sFileSelectOam_MetroidLogo_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 89, 3, 0),
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 200, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 202, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 204, 0, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 210, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 207, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessIdle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 206, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 208, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 210, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 211, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-30, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 213, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 215, 4, 0),
};

static const u16 sOptionsOam_LeftArrowIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 153, 1, 0),
};

static const u16 sOptionsOam_LeftArrowMoving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-17, -8, OAM_DIMS_8x16, OAM_X_FLIP, 28, 1, 0),
};

static const u16 sOptionsOam_RightArrowIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 153, 1, 0),
};

static const u16 sOptionsOam_RightArrowMoving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(9, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 28, 1, 0),
};

static const u16 sOptionsOam_SoundTestId_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 30, 3, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 217, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 219, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-29, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 221, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-42, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 264, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-42, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 268, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 272, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 274, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 275, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 277, 4, 0),
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-34, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 278, 4, 0),
    OAM_ENTRY(-18, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 280, 4, 0),
};

static const u16 sOptionsOam_GbaActive_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 81, 1, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 145, 1, 0),
    OAM_ENTRY(21, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_GbaActive_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 81, 1, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 147, 1, 0),
    OAM_ENTRY(21, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_GbaActive_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 81, 1, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 149, 1, 0),
    OAM_ENTRY(21, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_GbaActive_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 81, 1, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 151, 1, 0),
    OAM_ENTRY(21, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_SpeakersActive_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 85, 1, 0),
    OAM_ENTRY(11, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 91, 1, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_8x16, OAM_X_FLIP, 91, 1, 0),
    OAM_ENTRY(-35, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_SpeakersActive_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 85, 1, 0),
    OAM_ENTRY(11, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 92, 1, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_8x16, OAM_X_FLIP, 92, 1, 0),
    OAM_ENTRY(-35, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_SpeakersActive_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 85, 1, 0),
    OAM_ENTRY(11, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 93, 1, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_8x16, OAM_X_FLIP, 93, 1, 0),
    OAM_ENTRY(-35, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_SpeakersActive_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 85, 1, 0),
    OAM_ENTRY(11, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 94, 1, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_8x16, OAM_X_FLIP, 94, 1, 0),
    OAM_ENTRY(-35, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_LeftArrowIdle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_X_FLIP, 154, 1, 0),
};

static const u16 sOptionsOam_RightArrowIdle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 154, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-56, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 332, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-56, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 333, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-56, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 334, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-56, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 335, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-60, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 364, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame5[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 336, 5, 0),
    OAM_ENTRY(-60, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 366, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame6[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 336, 5, 0),
    OAM_ENTRY(-46, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 337, 5, 0),
    OAM_ENTRY(-38, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 338, 5, 0),
    OAM_ENTRY(-60, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 428, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame7[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 400, 5, 0),
    OAM_ENTRY(-46, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 337, 5, 0),
    OAM_ENTRY(-38, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 338, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame8[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 5, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 401, 5, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 400, 5, 0),
    OAM_ENTRY(-38, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 338, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame9[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 430, 5, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 401, 5, 0),
    OAM_ENTRY(-32, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 400, 5, 0),
    OAM_ENTRY(0, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame10[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 590, 5, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 401, 5, 0),
    OAM_ENTRY(0, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 5, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 561, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame11[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 430, 5, 0),
    OAM_ENTRY(30, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 496, 5, 0),
    OAM_ENTRY(0, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 5, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 561, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame12[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(30, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 496, 5, 0),
    OAM_ENTRY(16, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 561, 5, 0),
    OAM_ENTRY(38, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 497, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame13[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(30, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 496, 5, 0),
    OAM_ENTRY(38, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 497, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame14[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(46, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 498, 5, 0),
    OAM_ENTRY(36, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 339, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame15[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(36, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 403, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame16[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(36, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 467, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame17[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(36, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 531, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame18[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(36, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 595, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame22[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(48, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 492, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame23[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(48, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 493, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame24[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(48, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 494, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame25[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(48, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 495, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame26[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(44, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame27[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(46, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 498, 5, 0),
    OAM_ENTRY(44, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame28[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(30, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 496, 5, 0),
    OAM_ENTRY(38, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 497, 5, 0),
    OAM_ENTRY(44, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 588, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame35[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 336, 5, 0),
    OAM_ENTRY(-68, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 343, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame36[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-68, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 407, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame37[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-68, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 471, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame38[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-68, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 535, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaLinking_Frame39[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-68, 5, OAM_DIMS_32x16, OAM_NO_FLIP, 599, 5, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_455cac_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 466, 1, 0),
    OAM_ENTRY(-56, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 434, 1, 0),
    OAM_ENTRY(-54, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 348, 1, 0),
    OAM_ENTRY(-36, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 347, 1, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_32x8, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(-68, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
    OAM_ENTRY(22, -4, OAM_DIMS_32x8, OAM_X_FLIP, 348, 1, 0),
    OAM_ENTRY(28, -1, OAM_DIMS_8x16, OAM_X_FLIP, 347, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_32x8, OAM_X_FLIP, 380, 1, 0),
    OAM_ENTRY(36, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 411, 1, 0),
};

static const u16 sOptionsOam_GbaActive_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 81, 1, 0),
    OAM_ENTRY(21, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

static const u16 sOptionsOam_SpeakersActive_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 85, 1, 0),
    OAM_ENTRY(-35, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 475, 1, 0),
};

const struct FrameData sFileSelectOam_SamusHeadTurningOn[5] = {
    [0] = {
        .pFrame = sFileSelectOam_SamusHeadTurningOn_Frame0,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [1] = {
        .pFrame = sFileSelectOam_SamusHeadTurningOn_Frame1,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [2] = {
        .pFrame = sFileSelectOam_SamusHeadTurningOn_Frame2,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [3] = {
        .pFrame = sFileSelectOam_SamusHeadTurningOn_Frame1,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_SamusHeadOff[2] = {
    [0] = {
        .pFrame = sFileSelectOam_SamusHeadOff_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFileSelectOam_SamusHeadTurning[11] = {
    [0] = {
        .pFrame = sFileSelectOam_SamusHeadOff_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [6] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [7] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [8] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [9] = {
        .pFrame = sFileSelectOam_SamusHeadTurning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileAMarkerSelectedRed[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileAMarkerSelectedRed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileBMarkerSelectedRed[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileBMarkerSelectedRed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileCMarkerSelectedRed[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileCMarkerSelectedRed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileAMarkerIdle[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileAMarkerIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileBMarkerIdle[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileBMarkerIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileCMarkerIdle[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileCMarkerIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileAMarkerSelectedGreen[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileAMarkerSelectedGreen_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileBMarkerSelectedGreen[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileBMarkerSelectedGreen_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_FileCMarkerSelectedGreen[2] = {
    [0] = {
        .pFrame = sFileSelectOam_FileCMarkerSelectedGreen_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CursorSelected[2] = {
    [0] = {
        .pFrame = sFileSelectOam_CursorSelected_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_Cursor[4] = {
    [0] = {
        .pFrame = sFileSelectOam_Cursor_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sFileSelectOam_Cursor_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sFileSelectOam_Cursor_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_GbaIdle[2] = {
    [0] = {
        .pFrame = sOptionsOam_GbaIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_SpeakersIdle[2] = {
    [0] = {
        .pFrame = sOptionsOam_SpeakersIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowOneDownActive[5] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowOneDownActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sFileSelectOam_CopyArrowOneDownActive_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_CopyArrowOneDownActive_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_CopyArrowOneDownActive_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowOneDownInactive[2] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowOneDownActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowTwoDownActive[5] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowTwoDownActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sFileSelectOam_CopyArrowTwoDownActive_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_CopyArrowTwoDownActive_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_CopyArrowTwoDownActive_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowTwoDownInactive[2] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowTwoDownActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowOneUpActive[5] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowOneUpActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sFileSelectOam_CopyArrowOneUpActive_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_CopyArrowOneUpActive_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_CopyArrowOneUpActive_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowOneUpInactive[2] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowOneUpActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowTwoUpActive[5] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowTwoUpActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sFileSelectOam_CopyArrowTwoUpActive_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_CopyArrowTwoUpActive_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_CopyArrowTwoUpActive_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_CopyArrowTwoUpInactive[2] = {
    [0] = {
        .pFrame = sFileSelectOam_CopyArrowTwoUpActive_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_MetroidLogo[2] = {
    [0] = {
        .pFrame = sFileSelectOam_MetroidLogo_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFileSelectOam_SamusHeadSuitlessIdle[5] = {
    [0] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessIdle_Frame0,
        .timer = CONVERT_SECONDS(2.0f)
    },
    [1] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFileSelectOam_SamusHeadSuitlessTurning[8] = {
    [0] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_LeftArrowIdle[3] = {
    [0] = {
        .pFrame = sOptionsOam_LeftArrowIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sOptionsOam_LeftArrowIdle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_LeftArrowMoving[2] = {
    [0] = {
        .pFrame = sOptionsOam_LeftArrowMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_RightArrowIdle[3] = {
    [0] = {
        .pFrame = sOptionsOam_RightArrowIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sOptionsOam_RightArrowIdle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_RightArrowMoving[2] = {
    [0] = {
        .pFrame = sOptionsOam_RightArrowMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_SoundTestId[2] = {
    [0] = {
        .pFrame = sOptionsOam_SoundTestId_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sFileSelectOam_SamusHeadSuitlessTurningOn[6] = {
    [0] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurningOn_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurningOn_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurningOn_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurningOn_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sFileSelectOam_SamusHeadSuitlessTurningOn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_GbaActive[6] = {
    [0] = {
        .pFrame = sOptionsOam_GbaActive_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sOptionsOam_GbaActive_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sOptionsOam_GbaActive_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sOptionsOam_GbaActive_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sOptionsOam_GbaActive_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_SpeakersActive[6] = {
    [0] = {
        .pFrame = sOptionsOam_SpeakersActive_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sOptionsOam_SpeakersActive_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sOptionsOam_SpeakersActive_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sOptionsOam_SpeakersActive_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sOptionsOam_SpeakersActive_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_GbaLinking[44] = {
    [0] = {
        .pFrame = sOptionsOam_GbaLinking_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sOptionsOam_GbaLinking_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sOptionsOam_GbaLinking_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sOptionsOam_GbaLinking_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sOptionsOam_GbaLinking_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sOptionsOam_GbaLinking_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sOptionsOam_GbaLinking_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sOptionsOam_GbaLinking_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sOptionsOam_GbaLinking_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sOptionsOam_GbaLinking_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sOptionsOam_GbaLinking_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sOptionsOam_GbaLinking_Frame11,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sOptionsOam_GbaLinking_Frame12,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [13] = {
        .pFrame = sOptionsOam_GbaLinking_Frame13,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [14] = {
        .pFrame = sOptionsOam_GbaLinking_Frame14,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [15] = {
        .pFrame = sOptionsOam_GbaLinking_Frame15,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [16] = {
        .pFrame = sOptionsOam_GbaLinking_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [17] = {
        .pFrame = sOptionsOam_GbaLinking_Frame17,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [18] = {
        .pFrame = sOptionsOam_GbaLinking_Frame18,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [19] = {
        .pFrame = sOptionsOam_GbaLinking_Frame17,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [20] = {
        .pFrame = sOptionsOam_GbaLinking_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [21] = {
        .pFrame = sOptionsOam_GbaLinking_Frame15,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [22] = {
        .pFrame = sOptionsOam_GbaLinking_Frame22,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [23] = {
        .pFrame = sOptionsOam_GbaLinking_Frame23,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [24] = {
        .pFrame = sOptionsOam_GbaLinking_Frame24,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [25] = {
        .pFrame = sOptionsOam_GbaLinking_Frame25,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [26] = {
        .pFrame = sOptionsOam_GbaLinking_Frame26,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [27] = {
        .pFrame = sOptionsOam_GbaLinking_Frame27,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [28] = {
        .pFrame = sOptionsOam_GbaLinking_Frame28,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [29] = {
        .pFrame = sOptionsOam_GbaLinking_Frame12,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [30] = {
        .pFrame = sOptionsOam_GbaLinking_Frame11,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [31] = {
        .pFrame = sOptionsOam_GbaLinking_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [32] = {
        .pFrame = sOptionsOam_GbaLinking_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [33] = {
        .pFrame = sOptionsOam_GbaLinking_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [34] = {
        .pFrame = sOptionsOam_GbaLinking_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [35] = {
        .pFrame = sOptionsOam_GbaLinking_Frame35,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [36] = {
        .pFrame = sOptionsOam_GbaLinking_Frame36,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [37] = {
        .pFrame = sOptionsOam_GbaLinking_Frame37,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [38] = {
        .pFrame = sOptionsOam_GbaLinking_Frame38,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [39] = {
        .pFrame = sOptionsOam_GbaLinking_Frame39,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [40] = {
        .pFrame = sOptionsOam_GbaLinking_Frame38,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [41] = {
        .pFrame = sOptionsOam_GbaLinking_Frame37,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [42] = {
        .pFrame = sOptionsOam_GbaLinking_Frame36,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [43] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_455cac[2] = {
    [0] = {
        .pFrame = sOptionsOam_455cac_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u16 sFileSelectOam_SmallPanel_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 330, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 586, 2, 0),
};

static const u16 sFileSelectOam_SmallPanel_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-28, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(-28, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(-28, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 2, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 392, 2, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 2, 0),
};

static const u16 sFileSelectOam_SmallPanel_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-40, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 388, 2, 0),
    OAM_ENTRY(24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 330, 2, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 394, 2, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 544, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 548, 2, 0),
    OAM_ENTRY(-40, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 608, 2, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 612, 0, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 554, 2, 0),
    OAM_ENTRY(24, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 618, 2, 0),
};

static const u16 sFileSelectOam_SmallPanel_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(20, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-52, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(-52, -4, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(20, -4, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 2, 0),
    OAM_ENTRY(-24, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 355, 2, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 359, 2, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 547, 2, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 551, 2, 0),
};

static const u16 sFileSelectOam_SmallPanel_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 516, 2, 0),
};

static const u16 sFileSelectOam_LargePanel_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-72, 8, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_64x32, OAM_NO_FLIP, 516, 2, 0),
    OAM_ENTRY(-72, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 356, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 484, 2, 0),
};

static const u16 sFileSelectOam_LargePanel_Frame6[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-80, 16, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_64x32, OAM_NO_FLIP, 516, 2, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x32, OAM_NO_FLIP, 484, 2, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 356, 2, 0),
    OAM_ENTRY(-80, -48, OAM_DIMS_64x32, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(-80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 448, 2, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 2, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 448, 2, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 2, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_64x32, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 2, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 456, 2, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 2, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 456, 2, 0),
};

static const u16 sFileSelectOam_MediumPanel_Frame6[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-80, 8, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_64x32, OAM_NO_FLIP, 516, 2, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 484, 2, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 356, 2, 0),
    OAM_ENTRY(-80, -40, OAM_DIMS_64x32, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 448, 2, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 2, 0),
    OAM_ENTRY(16, -40, OAM_DIMS_64x32, OAM_NO_FLIP, 324, 2, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 452, 2, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 456, 2, 0),
};

static const u16 sOptionsOam_SmallPanel_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-28, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(-28, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 392, 2, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 2, 0),
    OAM_ENTRY(-28, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(-28, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 384, 2, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 392, 2, 0),
};

static const u16 sOptionsOam_SmallPanel_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 320, 2, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 328, 2, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 2, 0),
};

static const struct FrameData sFileSelectOam_SmallPanel[6] = {
    [0] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_LargePanel[8] = {
    [0] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sFileSelectOam_LargePanel_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sFileSelectOam_LargePanel_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sFileSelectOam_MediumPanel[8] = {
    [0] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sFileSelectOam_LargePanel_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sFileSelectOam_MediumPanel_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOptionsOam_SmallPanel[5] = {
    [0] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sFileSelectOam_SmallPanel_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sOptionsOam_SmallPanel_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sOptionsOam_SmallPanel_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u32 sFileSelectChozoBackgroundGfx[2985] = INCBIN_U32("data/menus/FileSelect/ChozoBackground.gfx.lz");
#ifdef REGION_EU
const u32 sFileSelectAreaNamesGfx[331] = INCBIN_U32("data/menus/FileSelect/AreaNames.gfx.lz");
const u32 sFileSelectBgIconsGfx[651] = INCBIN_U32("data/menus/FileSelect/BgIcons.gfx.lz");
#else // !REGION_EU
const u32 sFileSelectCharactersGfx[1531] = INCBIN_U32("data/menus/FileSelect/Characters.gfx.lz");
#endif // REGION_EU

const u32 sFileSelectOptionsTextEnglishGfx[345] = INCBIN_U32("data/menus/FileSelect/OptionsTextEnglish.gfx.lz");
const u32 sFileSelectOptionsTextGermanGfx[] = INCBIN_U32("data/menus/FileSelect/OptionsTextGerman.gfx.lz");
const u32 sFileSelectOptionsTextFrenchGfx[] = INCBIN_U32("data/menus/FileSelect/OptionsTextFrench.gfx.lz");
const u32 sFileSelectOptionsTextItalianGfx[] = INCBIN_U32("data/menus/FileSelect/OptionsTextItalian.gfx.lz");
const u32 sFileSelectOptionsTextSpanishGfx[] = INCBIN_U32("data/menus/FileSelect/OptionsTextSpanish.gfx.lz");

#ifdef REGION_EU
const u32 sFileSelectLargeTextEnglishGfx[332] = INCBIN_U32("data/menus/FileSelect/LargeTextEnglish.gfx.lz");
const u32 sFileSelectLargeTextGermanGfx[391] = INCBIN_U32("data/menus/FileSelect/LargeTextGerman.gfx.lz");
const u32 sFileSelectLargeTextFrenchGfx[392] = INCBIN_U32("data/menus/FileSelect/LargeTextFrench.gfx.lz");
const u32 sFileSelectLargeTextItalianGfx[353] = INCBIN_U32("data/menus/FileSelect/LargeTextItalian.gfx.lz");
const u32 sFileSelectLargeTextSpanishGfx[364] = INCBIN_U32("data/menus/FileSelect/LargeTextSpanish.gfx.lz");

const u32 sFileSelectDifficultyTextEnglishGfx[67] = INCBIN_U32("data/menus/FileSelect/DifficultyTextEnglish.gfx.lz");
const u32 sFileSelectDifficultyTextGermanGfx[70] = INCBIN_U32("data/menus/FileSelect/DifficultyTextGerman.gfx.lz");
const u32 sFileSelectDifficultyTextFrenchGfx[71] = INCBIN_U32("data/menus/FileSelect/DifficultyTextFrench.gfx.lz");
const u32 sFileSelectDifficultyTextItalianGfx[71] = INCBIN_U32("data/menus/FileSelect/DifficultyTextItalian.gfx.lz");
const u32 sFileSelectDifficultyTextSpanishGfx[70] = INCBIN_U32("data/menus/FileSelect/DifficultyTextSpanish.gfx.lz");
#endif // REGION_EU

const u32 sFileSelectObjIconsGfx[1722] = INCBIN_U32("data/menus/FileSelect/ObjIcons.gfx.lz");
const u32 sFileSelectChozoBackgroundTileTable[368] = INCBIN_U32("data/menus/FileSelect/ChozoBackground.tt");
const u32 sFileSelectMenuTileTable[] = INCBIN_U32("data/menus/FileSelect/Menu.tt");
const u32 sFileSelectOptionsTileTable[] = INCBIN_U32("data/menus/FileSelect/Options.tt");
const u32 sFileSelect3BigPanelsTileTable[233] = INCBIN_U32("data/menus/FileSelect/3BigPanels.tt");
const u32 sFileSelect1Small2BigPanelsTileTable[233] = INCBIN_U32("data/menus/FileSelect/1Small2BigPanels.tt");
const u32 sFileSelect2Big1SmallPanelsTileTable[230] = INCBIN_U32("data/menus/FileSelect/2Big1SmallPanels.tt");

const struct MenuOamData sFileSelectOamData_Empty[2] = {
    [0] = {
        .yPosition = 0,
        .xPosition = 0,
        .unk_4 = 0,
        .unk_5 = 0,
        .unk_6 = 0,
        .unk_7 = 0,
        .animationDurationCounter = 0,
        .currentAnimationFrame = 0,
        .oamID = 0,
        .priority = 1,
        .objMode = 0,
        .ended = 0,
        .notDrawn = 0,
        .exists = 0,
        .boundBackground = 2,
        .rotationScaling = 0,
        .unk_E = 0,
    },
    [1] = {
        .yPosition = 0,
        .xPosition = 0,
        .unk_4 = 0,
        .unk_5 = 0,
        .unk_6 = 0,
        .unk_7 = 0,
        .animationDurationCounter = 0,
        .currentAnimationFrame = 0,
        .oamID = 0,
        .priority = 1,
        .objMode = 0,
        .ended = 0,
        .notDrawn = 0,
        .exists = 0,
        .boundBackground = 1,
        .rotationScaling = 0,
        .unk_E = 0,
    }
};

const struct OamArray sFileSelectOam[FILE_SELECT_OAM_ID_END] = {
    [0] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_IDLE] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_OFF] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_OFF] = {
        .pOam = sFileSelectOam_SamusHeadOff,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [5] = {
        .pOam = sFileSelectOam_SamusHeadTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING] = {
        .pOam = sFileSelectOam_SamusHeadTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_ON] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_IDLE] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_OFF] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_OFF] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [11] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_A_MARKER_IDLE] = {
        .pOam = sFileSelectOam_FileAMarkerIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_B_MARKER_IDLE] = {
        .pOam = sFileSelectOam_FileBMarkerIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_C_MARKER_IDLE] = {
        .pOam = sFileSelectOam_FileCMarkerIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_RED] = {
        .pOam = sFileSelectOam_FileAMarkerSelectedRed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_RED] = {
        .pOam = sFileSelectOam_FileBMarkerSelectedRed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_RED] = {
        .pOam = sFileSelectOam_FileCMarkerSelectedRed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_GREEN] = {
        .pOam = sFileSelectOam_FileAMarkerSelectedGreen,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_GREEN] = {
        .pOam = sFileSelectOam_FileBMarkerSelectedGreen,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_GREEN] = {
        .pOam = sFileSelectOam_FileCMarkerSelectedGreen,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_CURSOR] = {
        .pOam = sFileSelectOam_Cursor,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_CURSOR_IDLE] = {
        .pOam = sFileSelectOam_Cursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_CURSOR_SELECTED] = {
        .pOam = sFileSelectOam_CursorSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_DOWN_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneDownActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_DOWN_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneDownInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_DOWN_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoDownActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_DOWN_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoDownInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_UP_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneUpActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_UP_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneUpInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_UP_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoUpActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_UP_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoUpInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_METROID_LOGO] = {
        .pOam = sFileSelectOam_MetroidLogo,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_SMALL_PANEL] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [35] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [FILE_SELECT_OAM_ID_LARGE_PANEL] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [37] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [FILE_SELECT_OAM_ID_MEDIUM_PANEL] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [39] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    }
};

const struct OamArray sOptionsOam[OPTIONS_OAM_ID_END] = {
    [0] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [OPTIONS_OAM_ID_CURSOR] = {
        .pOam = sFileSelectOam_Cursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_CURSOR_SELECTED] = {
        .pOam = sFileSelectOam_CursorSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_GBA_IDLE] = {
        .pOam = sOptionsOam_GbaIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_SPEAKERS_IDLE] = {
        .pOam = sOptionsOam_SpeakersIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_GBA_ACTIVE] = {
        .pOam = sOptionsOam_GbaActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_SPEAKERS_ACTIVE] = {
        .pOam = sOptionsOam_SpeakersActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_SOUND_TEST_ID] = {
        .pOam = sOptionsOam_SoundTestId,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_LEFT_ARROW_MOVING] = {
        .pOam = sOptionsOam_LeftArrowMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [OPTIONS_OAM_ID_LEFT_ARROW_IDLE] = {
        .pOam = sOptionsOam_LeftArrowIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_RIGHT_ARROW_MOVING] = {
        .pOam = sOptionsOam_RightArrowMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [OPTIONS_OAM_ID_RIGHT_ARROW_IDLE] = {
        .pOam = sOptionsOam_RightArrowIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_GBA_LINKING] = {
        .pOam = sOptionsOam_GbaLinking,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_GBA_STOPPED] = {
        .pOam = sOptionsOam_GbaLinking,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_SMALL_PANEL] = {
        .pOam = sOptionsOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [15] = {
        .pOam = sOptionsOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [OPTIONS_OAM_ID_LARGE_PANEL] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [17] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [OPTIONS_OAM_ID_MEDIUM_PANEL] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [19] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [OPTIONS_OAM_ID_HUGE_PANEL] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [21] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
};

// text_id, dst_type, unk
const u8 sFileScreenMessagesInfo[FILE_SCREEN_MESSAGE_INFO_ID_COUNT][3] = {
    [0] = {
        FILE_SCREEN_TEXT_START_GAME,
        0,
        2
    },
    [1] = {
        FILE_SCREEN_TEXT_COPY_SOURCE_CHOOSE,
        3,
        3
    },
    [2] = {
        FILE_SCREEN_TEXT_COPY_DESTINATION_CHOOSE,
        2,
        3
    },
    [3] = {
        FILE_SCREEN_TEXT_COPY_CONFIRM,
        0,
        3
    },
    [4] = {
        FILE_SCREEN_TEXT_CANT_COPY_TIME_ATTACK,
        0,
        3
    },
    [5] = {
        FILE_SCREEN_TEXT_ERASE_CHOOSE,
        3,
        3
    },
    [6] = {
        FILE_SCREEN_TEXT_ERASE_CONFIRM,
        0,
        3
    },
    [7] = {
        FILE_SCREEN_TEXT_FILE_A_CORRUPT_REVERT,
        3,
        3
    },
    [8] = {
        FILE_SCREEN_TEXT_FILE_B_CORRUPT_REVERT,
        0,
        3
    },
    [9] = {
        FILE_SCREEN_TEXT_FILE_C_CORRUPT_REVERT,
        2,
        3
    },
    [10] = {
        FILE_SCREEN_TEXT_FILE_A_CORRUPT_ERASE,
        3,
        3
    },
    [11] = {
        FILE_SCREEN_TEXT_FILE_B_CORRUPT_ERASE,
        0,
        3
    },
    [12] = {
        FILE_SCREEN_TEXT_FILE_C_CORRUPT_ERASE,
        2,
        3
    },
    [13] = {
        FILE_SCREEN_TEXT_ERASE_ALL_REFORMAT,
        0,
        2
    },
    [14] = {
        FILE_SCREEN_TEXT_ERASE_ALL,
        0,
        2
    },
    [15] = {
        FILE_SCREEN_TEXT_CONTINUE_NEW,
        1,
        4
    },
    [16] = {
        FILE_SCREEN_TEXT_CONTINUE_NEW_TIME_ATTACK,
        1,
        4
    },
    [17] = {
        FILE_SCREEN_TEXT_MESSAGE_OPTION,
        1,
        3
    },
    [18] = {
        FILE_SCREEN_TEXT_DIFFICULTY,
        3,
        4
    },
    [19] = {
        FILE_SCREEN_TEXT_DIFFICULTY_HARD,
        3,
        4
    },
    [20] = {
        FILE_SCREEN_TEXT_ERASE_FILE_CONFIRM,
        3,
        4
    },
    [21] = {
        FILE_SCREEN_TEXT_LINKING_PLEASE_WAIT,
        3,
        4
    },
    [22] = {
        FILE_SCREEN_TEXT_UNABLE_TO_DETECT_FUSION,
        3,
        4
    },
    [23] = {
        FILE_SCREEN_TEXT_LINKING_ERROR,
        0,
        2
    },
    [24] = {
        FILE_SCREEN_TEXT_TURN_OFF_CONFIRM_LINK,
        3,
        4
    },
    [25] = {
        FILE_SCREEN_TEXT_DO_NOT_TURN_POWER_OFF,
        0,
        2
    },
    [26] = {
        FILE_SCREEN_TEXT_DATA_UPLOAD_COMPLETE,
        3,
        4
    },
    [27] = {
        FILE_SCREEN_TEXT_LINKING_ERROR_CHECK_CONNECTION,
        3,
        4
    },
    [28] = {
        FILE_SCREEN_TEXT_LINK_COMPLETE,
        3,
        4
    },
    [29] = {
        FILE_SCREEN_TEXT_BEST_TIME,
        0,
        2
    },
    [30] = {
        FILE_SCREEN_TEXT_BEST_TIME_100,
        0,
        2
    },
    [31] = {
        FILE_SCREEN_TEXT_ID_PASSWORD,
        1,
        4
    },
    [32] = {
        FILE_SCREEN_TEXT_ID_PASSWORD,
        3,
        4
    },
};

const struct Message sFileScreenMessage_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = TRUE,
    .messageEnded = FALSE
};

const u8 sNesMetroidDataCheck[18] = {
    'N', 'E', 'S', ' ', 'M', 'E', 'T', 'R', 'O', 'I', 'D', '\0',
    '\0', '\0', '\0', '\0', '0', '1'
};

const u16 sTimeAttackButtonCode[5] = {
    [0] = KEY_UP,
    [1] = KEY_LEFT,
    [2] = KEY_RIGHT,
    [3] = KEY_DOWN,
    [4] = USHORT_MAX
};
