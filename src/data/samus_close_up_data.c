#include "data/samus_close_up_data.h"
#include "macros.h"

const u16 sSamusCloseUpPal[6 * 16] = {
    #include "extracted/data/close_up/palette.pal.inc"
};
const u32 sSamusCloseUpGfx[2319] = {
    #include "extracted/data/close_up/close_up.gfx.lz.inc"
};

const u32 sSamusCloseUpEyesGfx_1[80] = {
    #include "extracted/data/close_up/eyes_1.gfx.inc"
};
const u32 sSamusCloseUpEyesGfx_2[80] = {
    #include "extracted/data/close_up/eyes_2.gfx.inc"
};
const u32 sSamusCloseUpEyesGfx_3[1376] = {
    #include "extracted/data/close_up/eyes_3.gfx.inc"
};

const u32 sSamusCloseUpBackgroundMap[385] = {
    #include "extracted/data/close_up/background.tt.inc"
};
const u32 sSamusCloseUpEyesTiletable[98] = {
    #include "extracted/data/close_up/eyes.tt.inc"
};
