#include "cutscenes/story_text_cutscene.h"
#include "cutscenes/cutscene_utils.h"
#include "dma.h"
#include "text.h" // Required

#include "data/shortcut_pointers.h"
#include "data/text_data.h"
#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/story_text_cutscene_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/game_state.h"
#include "constants/text.h"

#include "structs/cutscene.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/text.h"

const u16** sStoryTextPointers[7] = {
    [LANGUAGE_JAPANESE] = sJapaneseTextPointers_Story,
    [LANGUAGE_HIRAGANA] = sHiraganaTextPointers_Story,
    [LANGUAGE_ENGLISH] = sEnglishTextPointers_Story,
    #if defined(REGION_EU) ||  defined(REGION_US_BETA)
    [LANGUAGE_GERMAN] = sGermanTextPointers_Story,
    [LANGUAGE_FRENCH] = sFrenchTextPointers_Story,
    [LANGUAGE_ITALIAN] = sItalianTextPointers_Story,
    [LANGUAGE_SPANISH] = sSpanishTextPointers_Story
    #else // !(REGION_EU || REGION_US_BETA)
    [LANGUAGE_GERMAN] = sEnglishTextPointers_Story,
    [LANGUAGE_FRENCH] = sEnglishTextPointers_Story,
    [LANGUAGE_ITALIAN] = sEnglishTextPointers_Story,
    [LANGUAGE_SPANISH] = sEnglishTextPointers_Story
    #endif // REGION_EU || REGION_US_BETA
};

/**
 * @brief 62b90 | fc | Initializes a story text cutscene
 * 
 * @return u8 FALSE
 */
static u8 StoryTextCutsceneInit(void)
{
    // Reset message
    BitFill(3, 0, &gCurrentMessage, sizeof(gCurrentMessage), 32);

    // Set message ID
    gCurrentMessage.messageID = sCutsceneData[gCurrentCutscene].storyText - 1;
    CutsceneFadeScreenToBlack();

    // Load palette
    DmaTransfer(3, sStoryTextCutscenePal, PALRAM_BASE + 15 * PAL_ROW_SIZE, sizeof(sStoryTextCutscenePal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    // Load tiletable and clear graphics
    CallLZ77UncompVram(sStoryTextCutsceneTileTable, BGCNT_TO_VRAM_TILE_BASE(sStoryTextCutscenePagesData[0].tiletablePage));
    BitFill(3, 0, BGCNT_TO_VRAM_CHAR_BASE(sStoryTextCutscenePagesData[0].graphicsPage) + 0x3000, 0x5000, 32);

    CutsceneSetBgcntPageData(sStoryTextCutscenePagesData[0]);
    
    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;
    gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_H = 0;

    // Check is "fullscreen" text ID
    switch (gCurrentMessage.messageID)
    {
        case STORY_TEXT_PLANET_ZEBES:
        case STORY_TEXT_THE_TIMING:
        case STORY_TEXT_COULD_I_SURVIVE:
            CUTSCENE_DATA.dispcnt = 0;
            CUTSCENE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            gWrittenToBldalpha_L = 0;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE;

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sStoryTextCutscenePagesData[0].bg, NON_GAMEPLAY_START_BG_POS);
            break;
    }

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 62c8c | 122 | Processes the text for the story text cutscenes
 * 
 * @return u8 FALSE
 */
static u8 StoryTextCutsceneProcessText(void)
{
    u32* dst;
    s32 line;
    s32 result;
    u32 flag;

    dst = BGCNT_TO_VRAM_CHAR_BASE(sStoryTextCutscenePagesData[0].graphicsPage) + 0x3000;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            gCurrentMessage.gfxSlot = 0;
            gCurrentMessage.line = 0;
            gCurrentMessage.stage = CUTSCENE_DATA.timeInfo.stage;

            CUTSCENE_DATA.timeInfo.subStage++;

        case 1:
            gCurrentMessage.indent = 0;
            gCurrentMessage.timer = 0;
            if (gCurrentMessage.line > 9)
                gCurrentMessage.line = 0;

            BitFill(3, 0, dst + gCurrentMessage.line * 0x200, 0x800, 16);
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            for (line = 8; line != 0; line--)
            {
                result = TextProcessCurrentMessage(&gCurrentMessage, sStoryTextPointers[gLanguage][gCurrentMessage.messageID],
                    dst + gCurrentMessage.line * 0x200);
                
                switch (result)
                {
                    case TEXT_STATE_ENDED:
                    case TEXT_STATE_NEW_PAGE:
                        CUTSCENE_DATA.timeInfo.timer = 0;
                        CUTSCENE_DATA.timeInfo.subStage = 0;
                        CUTSCENE_DATA.timeInfo.stage++;
                        flag = FALSE;
                        break;

                    case TEXT_STATE_UNK_3:
                        gCurrentMessage.gfxSlot = 1;

                    case TEXT_STATE_NEW_LINE:
                        CUTSCENE_DATA.timeInfo.subStage--;
                        flag = FALSE;
                        break;

                    default:
                        flag = TRUE;
                }

                if (!flag)
                    break;

                if (gCurrentMessage.line > 9)
                {
                    CUTSCENE_DATA.timeInfo.timer = 0;
                    CUTSCENE_DATA.timeInfo.subStage = 0;
                    CUTSCENE_DATA.timeInfo.stage++;
                    break;
                }
            }
            break;
    }

    return FALSE;
}

/**
 * @brief 62dac | 58 | Updates the vertical position of the background that has the text
 * 
 * @return u8 FALSE
 */
static u8 StoryTextCutsceneSetVerticalOffset(void)
{
    u32 bgPosition;

    bgPosition = NON_GAMEPLAY_START_BG_POS;

    // Weird maths, produces the following values (0 to 10) : 1728, 1760, 1792, 1824, 1856, 1888, 1920, 1952, 1984, 2016, 2048
    bgPosition -= (10 - gCurrentMessage.line) / 2 * 64;
    if (MOD_AND(gCurrentMessage.line,2))
        bgPosition -= HALF_BLOCK_SIZE;

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_VOFS, sStoryTextCutscenePagesData[0].bg, bgPosition);

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

/**
 * @brief 62e04 | 84 | Handles the fade in of the text
 * 
 * @return u8 FALSE
 */
static u8 StoryTextCutsceneFadeIn(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Display the text background
            CUTSCENE_DATA.dispcnt |= sStoryTextCutscenePagesData[0].bg;

            // Start fading
            CutsceneStartBackgroundEffect(CUTSCENE_DATA.bldcnt, BLDALPHA_MAX_VALUE, 0, 4, 1);

            // Check play landing sound effect (footsteps, running...)
            if (gCurrentCutscene == CUTSCENE_INTRO_TEXT)
                SoundPlay(SOUND_INTRO_TEXT_LANDING);

            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            // Wait for effect to end
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage = 0;
                CUTSCENE_DATA.timeInfo.stage++;
            }
            break;
    }

    return FALSE;
}

/**
 * @brief 62e88 | 80 | Handles the fade in of the text
 * 
 * @return u8 FALSE
 */
static u8 StoryTextCutsceneFadeOut(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Start fading
            CutsceneStartBackgroundEffect(CUTSCENE_DATA.bldcnt, 0, BLDALPHA_MAX_VALUE, 4, 1);
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            // Wait for effect to end
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                // Check for multi page message (unused in final game)
                if (gCurrentMessage.messageEnded)
                {
                    #ifdef DEBUG
                    if (gBootDebugActive == 0)
                    #endif // DEBUG
                    {
                        CUTSCENE_DATA.dispcnt = 0; // Message fully ended, clear screen
                    }
                }
                else
                {
                    CUTSCENE_DATA.dispcnt &= ~sStoryTextCutscenePagesData[0].bg; // Message hasn't ended yet, clear the text background   
                }

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage = 0;
                CUTSCENE_DATA.timeInfo.stage++;
            }
            break;
    }

    return FALSE;
}

/**
 * @brief 62f08 | 64 | Handles checking for input to dismiss the text
 * 
 * @return u8 FALSE
 */
static u8 StoryTextCutsceneCheckInput(void)
{
    u8 subStage;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
            {
                if (gCurrentMessage.gfxSlot != 0)
                    subStage = 2;
                else
                    subStage = 1;
                CUTSCENE_DATA.timeInfo.subStage = subStage;
            }
            break;

        case 1:
            if (gChangedInput & (KEY_A | KEY_B))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage = 0;
                CUTSCENE_DATA.timeInfo.stage++;
            }
            break;
        
        case 2:
            if (gChangedInput & (KEY_A | KEY_B))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage = 0;
                CUTSCENE_DATA.timeInfo.stage++;
            }
            break;
    }

    return FALSE;
}

/**
 * @brief 62f6c | 6c | Checks if a story text cutscene should end
 * 
 * @return u8 bool, ended
 */
static u8 StoryTextCutsceneEnd(void)
{
    void* dst;

    if (gCurrentMessage.messageEnded)
        return TRUE; // Message is done, end cutscene

    // Stil has some text to process, clear graphics
    dst = BGCNT_TO_VRAM_CHAR_BASE(sStoryTextCutscenePagesData[0].graphicsPage) + 0x3000;
    BitFill(3, 0, dst + CUTSCENE_DATA.timeInfo.subStage * 0x1000, 0x1000, 32);

    CUTSCENE_DATA.timeInfo.subStage++;
    if (CUTSCENE_DATA.timeInfo.subStage > 4)
    {
        CUTSCENE_DATA.timeInfo.timer = 0;
        CUTSCENE_DATA.timeInfo.subStage = 0;
        CUTSCENE_DATA.timeInfo.stage = gCurrentMessage.stage;
    }

    return FALSE;
}

static struct CutsceneSubroutineData sStoryTextCutsceneSubroutineData[7] = {
    [0] = {
        .pFunction = StoryTextCutsceneInit,
        .oamLength = 0
    },
    [1] = {
        .pFunction = StoryTextCutsceneProcessText,
        .oamLength = 0
    },
    [2] = {
        .pFunction = StoryTextCutsceneSetVerticalOffset,
        .oamLength = 0
    },
    [3] = {
        .pFunction = StoryTextCutsceneFadeIn,
        .oamLength = 0
    },
    [4] = {
        .pFunction = StoryTextCutsceneCheckInput,
        .oamLength = 0
    },
    [5] = {
        .pFunction = StoryTextCutsceneFadeOut,
        .oamLength = 0
    },
    [6] = {
        .pFunction = StoryTextCutsceneEnd,
        .oamLength = 0
    },
};

/**
 * @brief 62fd8 | 30 | Subroutine for the story text cutscenes
 * 
 * @return u8 bool, ended
 */
u8 StoryTextCutsceneSubroutine(void)
{
    u8 ended;

    ended = sStoryTextCutsceneSubroutineData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(FALSE);

    return ended;
}
