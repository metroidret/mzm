#include "data/cutscenes/story_text_cutscene_data.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sStoryTextCutscenePagesData[1] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0x14,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    }
};

const u32 sStoryTextCutsceneGfx_Unused[645] = {
    #include "extracted/data/cutscenes/story_text/unused_letters.gfx.lz.inc"
};
const u16 sStoryTextCutscenePal[1 * 16] = {
    #include "extracted/data/cutscenes/story_text/palette.pal.inc"
};
const u32 sStoryTextCutsceneTileTable[347] = {
    #include "extracted/data/cutscenes/story_text/text.tt.inc"
};
