#ifndef ENDING_AND_GALLERY_DATA_H
#define ENDING_AND_GALLERY_DATA_H

#include "types.h"
#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"
#include "structs/ending_and_gallery.h"
#include "oam.h"

extern const u16 sEndingImageTextPal[14 * 16];

// ...


// ...

extern const u16 sEndingImageOam_NewRecordEnglish[OAM_DATA_SIZE(6)];
#ifdef REGION_EU
extern const u16 sEndingImageOam_NewRecordFrench[OAM_DATA_SIZE(4)];
extern const u16 sEndingImageOam_NewRecordItalian[OAM_DATA_SIZE(6)];
extern const u16 sEndingImageOam_NewRecordSpanish[OAM_DATA_SIZE(6)];
extern const u16 sEndingImageOam_NewRecordGerman[OAM_DATA_SIZE(6)];
#endif // REGION_EU

// ...

extern const u16 sCreditsCharactersPal[3 * 16];
extern const u16 sCreditsChozoWallPal[15 * 16];

// ...

extern const u16 sEndingPosingPal[13 * 16];
extern const u16 sEndingPosingPal_White1[5 * 16];
extern const u16 sEndingPosingPal_White2[5 * 16];
extern const u16 sEndingPosingPal_White3[5 * 16];
extern const u16 sEndingPosingPal_White4[5 * 16];

extern const u16 sUnlockedOptionsPal[1 * 16];

extern const struct EndingImageOam sEndingImageOam_FullLines_English[ENDING_IMAGE_LINE_END];
extern const struct EndingImageOam sEndingImageOam_ClearTime_English[9];
extern const struct EndingImageOam sEndingImageOam_YourRate_English[11];
extern const struct EndingImageOam sEndingImageOam_Collecting_English[17];
extern const struct EndingImageOam sEndingImageOam_FullLines_Hiragana[ENDING_IMAGE_LINE_END];
extern const struct EndingImageOam sEndingImageOam_ClearTime_Hiragana[6];
extern const struct EndingImageOam sEndingImageOam_Collecting_Hiragana[11];
#ifdef REGION_EU
extern const struct EndingImageOam sEndingImageOam_FullLines_German[ENDING_IMAGE_LINE_END];
extern const struct EndingImageOam sEndingImageOam_ClearTime_German[13];
extern const struct EndingImageOam sEndingImageOam_Collecting_German[14];
extern const struct EndingImageOam sEndingImageOam_FullLines_French[ENDING_IMAGE_LINE_END];
extern const struct EndingImageOam sEndingImageOam_ClearTime_French[16];
extern const struct EndingImageOam sEndingImageOam_Collecting_French[20];
extern const struct EndingImageOam sEndingImageOam_FullLines_Italian[ENDING_IMAGE_LINE_END];
extern const struct EndingImageOam sEndingImageOam_ClearTime_Italian[18];
extern const struct EndingImageOam sEndingImageOam_YourRate_Italian[11];
extern const struct EndingImageOam sEndingImageOam_Collecting_Italian[17];
extern const struct EndingImageOam sEndingImageOam_FullLines_Spanish[ENDING_IMAGE_LINE_END];
extern const struct EndingImageOam sEndingImageOam_ClearTime_Spanish[15];
extern const struct EndingImageOam sEndingImageOam_Collecting_Spanish[19];
#endif // REGION_EU

extern const u32* const sEndingImagesTopGfxPointers[ENDING_IMAGE_COUNT];
extern const u32* const sEndingImagesBottomGfxPointers[ENDING_IMAGE_COUNT];
extern const u32* const sEndingImagesTopTileTablePointers[ENDING_IMAGE_COUNT];
extern const u32* const sEndingImagesHalfTileTablePointers[ENDING_IMAGE_COUNT];
extern const u16* const sEndingImagesPalPointers[ENDING_IMAGE_COUNT];

#ifdef REGION_JP
extern const struct CreditsEntry sCredits[245];
#else // !REGION_JP
extern const struct CreditsEntry sCredits[240];
#endif // REGION_JP

extern const u16* const sEndingWhitePalPointers[4];

extern const u8 sEndingImage_54e2dc[8];
extern const u8 sEndingImageNewRecordPalettes[12];

#ifdef REGION_EU
extern const u16 * const sEndingImageOamPointers_NewRecord[LANGUAGE_END];
#endif // REGION_EU

extern const u32 sCreditsCharactersGfx[];

// ...

extern const u32 sEndingImageTextEnglishGfx[803];
extern const u32 sEndingImageTextHiraganaGfx[511];
#ifdef REGION_EU
extern const u32 sEndingImageTextFrenchGfx[759];
extern const u32 sEndingImageTextGermanGfx[726];
extern const u32 sEndingImageTextItalianGfx[883];
extern const u32 sEndingImageTextSpanishGfx[773];
#endif // REGION_EU

extern const u8 sEndingImageNumbersGfx_Upper[10 * 64];
extern const u8 sEndingImageNumbersGfx_Lower[10 * 64];

extern const u32 sEndingImageNumbersMiscEnglishGfx[218];
#ifdef REGION_EU
extern const u32 sEndingImageNumbersMiscGermanGfx[209];
extern const u32 sEndingImageNumbersMiscFrenchGfx[217];
extern const u32 sEndingImageNumbersMiscItalianGfx[208];
extern const u32 sEndingImageNumbersMiscSpanishGfx[225];
#endif // REGION_EU
extern const u32 sEndingSamusPosingSpaceBackgroundGfx[2938];
extern const u32 sEndingSamusPosingSpaceBackgroundTileTable[412];
extern const u32 sEndingLightGfx[743];
extern const u32 sEndingLightTileTable[145];

extern const u32 sEndingSamusPosingGfx_1[1481];
extern const u32 sEndingSamusPosingTileTable_1[209];
extern const u32 sEndingSamusPosingGfx_2[1562];
extern const u32 sEndingSamusPosingTileTable_2[230];
extern const u32 sEndingSamusPosingGfx_3[1712];
extern const u32 sEndingSamusPosingTileTable_3[238];
extern const u32 sEndingSamusPosingGfx_4[1692];
extern const u32 sEndingSamusPosingTileTable_4[221];
extern const u32 sEndingSamusPosingGfx_5[1279];
extern const u32 sEndingSamusPosingTileTable_5[181];

extern const u32 sEndingSamusPosingSuitlessGfx[1167];
extern const u32 sEndingSamusPosingSuitlessTileTable[135];
extern const u32 sEndingSamusPosingFullSuitGfx[1557];
extern const u32 sEndingSamusPosingFullSuitTileTable[226];
extern const u32 sEndingSamusPosingHelmetOffGfx[1568];
extern const u32 sEndingSamusPosingHelmetOffTileTable[226];

extern const u32 sCreditsChozoWallBackgroundGfx[7710];
extern const u32 sCreditsChozoWallBackgroundTileTable[551];
extern const u32 sCreditsChozoWallBottomGfx[3909];
extern const u32 sCreditsChozoWallBottomTileTable[307];
extern const u32 sCreditsChozoWallBottomZoomedGfx[5160];
extern const u32 sCreditsChozoWallBottomZoomedTileTable[368];
extern const u32 sCreditsChozoDrawingGfx[4770];
extern const u32 sCreditsChozoDrawingTileTable[368];

extern const u32 sUnlockedOptionsTileTable[127];

#endif /* ENDING_AND_GALLERY_DATA_H */
