#include "data/menus/language_select_data.h"

#ifdef REGION_EU

const u16 sLanguageSelectBgPal[16 * 16] = INCBIN_U16("data/menus/LanguageSelect/Background.pal");
const u32 sLanguageSelectGfx[145] = INCBIN_U32("data/menus/LanguageSelect/Background.gfx.lz");
const u32 sLanguageSelectTileTable[95] = INCBIN_U32("data/menus/LanguageSelect/Background.tt");

const struct LanguageColorAnimation sInitialLanguageColorAnimation = {
    .timer = 4,
    .interval = 4,
    .index = 0
};

const u8 sLanguageSelectGameModeSub1Values[3] = {0, 7, 8};

const u16 sLanguageSelectLanguageTileTableOffsets[LANGUAGE_END - LANGUAGE_ENGLISH] = {
    [LANGUAGE_ENGLISH - LANGUAGE_ENGLISH] = 0xA8,
    [LANGUAGE_GERMAN - LANGUAGE_ENGLISH] = 0xE8,
    [LANGUAGE_FRENCH - LANGUAGE_ENGLISH] = 0x128,
    [LANGUAGE_ITALIAN - LANGUAGE_ENGLISH] = 0x168,
    [LANGUAGE_SPANISH - LANGUAGE_ENGLISH] = 0x1A8
};

const u8 sLanguageTextAnimationPaletteRows[14] = {
    0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1
};

#endif // REGION_EU
