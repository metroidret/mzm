#include "animated_graphics.h"
#include "dma.h"
#include "gba.h"
#include "macros.h"
#include "sprite.h"
#include "color_effects.h"

#include "data/shortcut_pointers.h"
#include "data/animated_graphics_data.h"
#include "data/animated_tiles_data.h"

#include "constants/animated_graphics.h"
#include "constants/color_fading.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/room.h"
#include "constants/power_bomb_explosion.h"

#include "structs/animated_graphics.h"
#include "structs/color_effects.h"
#include "structs/power_bomb_explosion.h"
#include "structs/room.h"

static const BackgroundEffectBehaviorEntry_T* sBackgroundEffectBehaviorPointers[BACKGROUND_EFFECT_COUNT] = {
    [BACKGROUND_EFFECT_NONE] = sBackgroundEffectBehavior_Lightning,
    [BACKGROUND_EFFECT_LIGHTNING] = sBackgroundEffectBehavior_Lightning,
    [BACKGROUND_EFFECT_SLIGHT_YELLOW] = sBackgroundEffectBehavior_SlightYellow,
    [BACKGROUND_EFFECT_HEAVY_YELLOW] = sBackgroundEffectBehavior_HeavyYellow,
    [BACKGROUND_EFFECT_EXIT_ZEBES_FADE] = sBackgroundEffectBehavior_ExitZebes,
    [BACKGROUND_EFFECT_INTRO_TEXT_FADE] = sBackgroundEffectBehavior_IntroText,
    [BACKGROUND_EFFECT_QUICK_FLASH] = sBackgroundEffectBehavior_QuickFlash,
    [BACKGROUND_EFFECT_ALL_BLACK] = sBackgroundEffectBehavior_AllBlackWhite,
    [BACKGROUND_EFFECT_ALL_WHITE] = sBackgroundEffectBehavior_AllBlackWhite
};

static u16 BackgroundEffectProcess(void);


/**
 * @brief 5dd5c | 270 | Transfers the animated graphics to VRAM
 * 
 */
void AnimatedGraphicsTransfer(void)
{
    if (gAnimatedGraphicsToUpdate == 0)
        return;

    if (gAnimatedGraphicsToUpdate & 1 << 0)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(0), ANIMATED_GFX_VRAM_POS(0), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 1)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(1), ANIMATED_GFX_VRAM_POS(1), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 2)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(2), ANIMATED_GFX_VRAM_POS(2), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 3)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(3), ANIMATED_GFX_VRAM_POS(3), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 4)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(4), ANIMATED_GFX_VRAM_POS(4), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 5)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(5), ANIMATED_GFX_VRAM_POS(5), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 6)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(6), ANIMATED_GFX_VRAM_POS(6), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 7)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(7), ANIMATED_GFX_VRAM_POS(7), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 8)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(8), ANIMATED_GFX_VRAM_POS(8), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 9)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(9), ANIMATED_GFX_VRAM_POS(9), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 10)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(10), ANIMATED_GFX_VRAM_POS(10), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 11)
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(11), ANIMATED_GFX_VRAM_POS(11), ANIMATED_GFX_SIZE_16_BITS);

    if (gAnimatedGraphicsToUpdate & 1 << 12)
    {
        #ifdef REGION_EU
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(12), ANIMATED_GFX_VRAM_POS(12), ANIMATED_GFX_SIZE, 16);
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(12), ANIMATED_GFX_VRAM_END_POS(3), ANIMATED_GFX_SIZE, 16);
        #else // !REGION_EU
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(12), ANIMATED_GFX_VRAM_POS(12), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(12), ANIMATED_GFX_VRAM_END_POS(3), ANIMATED_GFX_SIZE_16_BITS);
        #endif // REGION_EU
    }

    if (gAnimatedGraphicsToUpdate & 1 << 13)
    {
        #ifdef REGION_EU
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(13), ANIMATED_GFX_VRAM_POS(13), ANIMATED_GFX_SIZE, 16);
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(13), ANIMATED_GFX_VRAM_END_POS(2), ANIMATED_GFX_SIZE, 16);
        #else // !REGION_EU
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(13), ANIMATED_GFX_VRAM_POS(13), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(13), ANIMATED_GFX_VRAM_END_POS(2), ANIMATED_GFX_SIZE_16_BITS);
        #endif // REGION_EU
    }

    if (gAnimatedGraphicsToUpdate & 1 << 14)
    {
        #ifdef REGION_EU
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(14), ANIMATED_GFX_VRAM_POS(14), ANIMATED_GFX_SIZE, 16);
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(14), ANIMATED_GFX_VRAM_END_POS(1), ANIMATED_GFX_SIZE, 16);
        #else // !REGION_EU
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(14), ANIMATED_GFX_VRAM_POS(14), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(14), ANIMATED_GFX_VRAM_END_POS(1), ANIMATED_GFX_SIZE_16_BITS);
        #endif // REGION_EU
    }

    if (gAnimatedGraphicsToUpdate & 1 << 15)
    {
        #ifdef REGION_EU
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(15), ANIMATED_GFX_VRAM_POS(15), ANIMATED_GFX_SIZE, 16);
        DmaTransfer(3, ANIMATED_GFX_EWRAM_POS(15), ANIMATED_GFX_VRAM_END_POS(0), ANIMATED_GFX_SIZE, 16);
        #else // !REGION_EU
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(15), ANIMATED_GFX_VRAM_POS(15), ANIMATED_GFX_SIZE_16_BITS);
        DMA3_COPY_16(ANIMATED_GFX_EWRAM_POS(15), ANIMATED_GFX_VRAM_END_POS(0), ANIMATED_GFX_SIZE_16_BITS);
        #endif // REGION_EU
    }

    gAnimatedGraphicsToUpdate = 0;
}

/**
 * @brief 5dfcc | 164 | Updates the animated graphics
 * 
 */
void AnimatedGraphicsUpdate(void)
{
    u32 update;
    s32 i;
    struct AnimatedGraphicsInfo* pGraphics;
    s32 frame;
    const u8* src;

    // Loop through every current animated graphics
    for (pGraphics = gAnimatedGraphicsData, i = 0; i < ARRAY_SIZE(gAnimatedGraphicsData); i++, pGraphics++)
    {
        update = FALSE;

        // Apply animation type
        switch (pGraphics->type)
        {
            case ANIMATED_GFX_TYPE_NONE:
                // No type, so no graphics
                break;

            case ANIMATED_GFX_TYPE_NORMAL:
                // Standard animation progression
                APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);
                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;

                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame++;

                    if (pGraphics->currentAnimationFrame == pGraphics->numberOfStates)
                        pGraphics->currentAnimationFrame = 0;
                }
                break;

            case ANIMATED_GFX_TYPE_NORMAL_ONCE:
                // Play the animation normally, but only once (no looping)
                if (pGraphics->currentAnimationFrame != pGraphics->numberOfStates - 1)
                {
                    APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);
                    if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                    {
                        update = TRUE;

                        pGraphics->animationDurationCounter = 0;
                        pGraphics->currentAnimationFrame++;
                    }
                }
                break;

            case ANIMATED_GFX_TYPE_ALTERNATE:
                APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);

                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;

                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame++;

                    frame = pGraphics->currentAnimationFrame;
                    if (pGraphics->currentAnimationFrame == pGraphics->numberOfStates)
                        pGraphics->currentAnimationFrame = 2 - frame;
                }
                break;

            case ANIMATED_GFX_TYPE_REVERSE_ONCE:
                // Standard animation progression, just played backwards and played once (no looping)
                if (pGraphics->currentAnimationFrame != 0)
                {
                    APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);

                    if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                    {
                        update = TRUE;

                        pGraphics->animationDurationCounter = 0;
                        pGraphics->currentAnimationFrame--;
                    }
                }
                break;

            case ANIMATED_GFX_TYPE_REVERSE:
                // Standard animation progression, just played backwards
                APPLY_DELTA_TIME_INC(pGraphics->animationDurationCounter);

                if (pGraphics->animationDurationCounter == pGraphics->framesPerState)
                {
                    update = TRUE;

                    pGraphics->animationDurationCounter = 0;
                    pGraphics->currentAnimationFrame--;

                    if (pGraphics->currentAnimationFrame < 0)
                    {
                        // Reached "start", set last frame
                        pGraphics->currentAnimationFrame = pGraphics->numberOfStates - 1;
                    }
                }
                break;
        }

        if (update)
        {
            frame = pGraphics->currentAnimationFrame;
            if (pGraphics->currentAnimationFrame < 0)
            {
                // Fancy negation
                frame = (s8)(~frame + 1);
            }

            // Get graphics
            src = &pGraphics->pGraphics[frame * ANIMATED_GFX_SIZE];

            // Transfer graphics to EWRAM
            DMA3_COPY_16(src, ANIMATED_GFX_EWRAM_POS(i), ANIMATED_GFX_SIZE_16_BITS);

            // Mark for transfer to VRAM
            gAnimatedGraphicsToUpdate |= 1 << i;
        }
    }
}

/**
 * @brief 5e130 | f4 | Loads the animated graphics
 * 
 */
void AnimatedGraphicsLoad(void)
{
    s32 i;
    u8 entry;
    const u8* src;
    const u8* dst;
    struct AnimatedGraphicsInfo* pGraphics;
    const struct AnimatedGraphicsData* pData;

    gAnimatedGraphicsToUpdate = 0;

    for (pGraphics = gAnimatedGraphicsData, i = 0; i < ARRAY_SIZE(gAnimatedGraphicsData); i++, pGraphics++)
    {
        // Get animated graphics entry
        pGraphics->graphicsEntry = sAnimatedTilesetEntries[gAnimatedGraphicsEntry.tileset][i * 3];

        // Get concerned entry
        entry = pGraphics->graphicsEntry;
        pData = &sAnimatedGraphicsEntries[entry];

        // Fetch data
        pGraphics->type = pData->type;
        pGraphics->framesPerState = pData->framesPerState;
        pGraphics->numberOfStates = pData->numberOfStates;

        // Setup animation
        pGraphics->animationDurationCounter = 0;
        pGraphics->currentAnimationFrame = 0;
        pGraphics->pGraphics = pData->pGraphics;

        switch (pGraphics->type)
        {
            case ANIMATED_GFX_TYPE_NORMAL_ONCE: // This might be an error? should probably be ANIMATED_GFX_TYPE_REVERSE_ONCE
            case ANIMATED_GFX_TYPE_REVERSE:
                // Set start on last frame
                pGraphics->currentAnimationFrame = pGraphics->numberOfStates - 1;
        }

        // Direct transfer to VRAM
        src = &pGraphics->pGraphics[pGraphics->currentAnimationFrame * ANIMATED_GFX_SIZE];
        dst = ANIMATED_GFX_VRAM_POS(i);

        DMA3_COPY_16(src, dst, ANIMATED_GFX_SIZE_16_BITS);

        // Check enable rain sound
        if (gPauseScreenFlag == 0 && pGraphics->graphicsEntry == ANIMATED_GFX_ID_RAIN)
            gRainSoundEffect |= RAIN_SOUND_ENABLED;
    }

    // Some backup?
    #ifdef REGION_EU
    DmaTransfer(3, ANIMATED_GFX_VRAM_POS(12), ANIMATED_GFX_VRAM_END_POS(4 - 1), ANIMATED_GFX_SIZE * 4, 16);
    #else // !REGION_EU
    DMA3_COPY_16(ANIMATED_GFX_VRAM_POS(12), ANIMATED_GFX_VRAM_END_POS(4 - 1), ANIMATED_GFX_SIZE * 4 / 2);
    #endif // REGION_EU
}

/**
 * @brief 5e224 | 24 | Resets the tank animations
 * 
 */
void AnimatedGraphicsTanksAnimationReset(void)
{
    gTankAnimations[0].timer = DELTA_TIME * 1;
    gTankAnimations[0].frame = 0;

    gTankAnimations[1].timer = DELTA_TIME * 2;
    gTankAnimations[1].frame = 0;

    gTankAnimations[2].timer = DELTA_TIME * 3;
    gTankAnimations[2].frame = 0;

    gTankAnimations[3].timer = DELTA_TIME * 4;
    gTankAnimations[3].frame = 0;
}

/**
 * @brief 5e248 | 6c | Updates the animation of the collectable tanks
 * 
 */
void AnimatedGraphicsTanksAnimationUpdate(void)
{
    s32 i;

    for (i = ARRAY_SIZE(gTankAnimations) - 1; i >= 0; i--)
    {
        // Update timer
        APPLY_DELTA_TIME_INC(gTankAnimations[i].timer);

        // Swap animation frame every 5 frames
        if (gTankAnimations[i].timer <= ANIMATED_GFX_TANK_FRAME_DELAY)
            continue;

        gTankAnimations[i].timer = 0;

        // Update current frame
        gTankAnimations[i].frame++;
        if (gTankAnimations[i].frame >= ANIMATED_GFX_TANK_NBR)
            gTankAnimations[i].frame = 0;

        // Transfer graphics
        DMA3_COPY_16(&sAnimatedTankGfx[ANIMATED_GFX_TANK_POS(i, gTankAnimations[i].frame)], ANIMATED_GFX_TANK_VRAM_POS(i), ANIMATED_GFX_SIZE_16_BITS);
    }
}

/**
 * @brief 5e2b4 | 170 | Updates the animated palette
 * 
 */
void AnimatedPaletteUpdate(void)
{
    u32 update;
    s32 row;
    s32 newRow;

    // Check has animated palette
    if (gAnimatedGraphicsEntry.palette == ANIMATED_PALETTE_ID_NONE)
        return;

    // Don't update if a power bomb explosion is occuring
    if (gCurrentPowerBomb.animationState != PB_STATE_NONE)
        return;

    // Don't update if disabled
    if (gDisableAnimatedPalette > FALSE)
        return;

    update = FALSE;

    // Update timer
    APPLY_DELTA_TIME_INC(gAnimatedPaletteTiming.timer1);

    switch (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].type)
    {
        case ANIMATED_PALETTE_TYPE_NONE:
            // No type, so no palette
            break;

        case ANIMATED_PALETTE_TYPE_NORMAL:
            // Standard animation progression
            if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].framesPerState <= gAnimatedPaletteTiming.timer1)
            {
                gAnimatedPaletteTiming.timer1 = 0;
                gAnimatedPaletteTiming.row1++;

                if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates <= gAnimatedPaletteTiming.row1)
                {
                    gAnimatedPaletteTiming.row1 = 0;
                    if (gDisableAnimatedPalette < 0)
                        gDisableAnimatedPalette = TRUE;

                }
                update++;
            }
            break;

        case ANIMATED_PALETTE_TYPE_ALTERNATE:
            if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].framesPerState <= gAnimatedPaletteTiming.timer1)
            {
                gAnimatedPaletteTiming.timer1 = 0;
                gAnimatedPaletteTiming.row1++;
                if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates <= gAnimatedPaletteTiming.row1)
                {
                    newRow = sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates - 1;
                    gAnimatedPaletteTiming.row1 = -newRow;
                }
            
                if (gDisableAnimatedPalette < 0 && gAnimatedPaletteTiming.row1 == 0)
                    gDisableAnimatedPalette = TRUE;

                update++;
            }
            break;

        case ANIMATED_PALETTE_TYPE_REVERSE:
            // Standard animation progression, just played backwards
            if (sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].framesPerState <= gAnimatedPaletteTiming.timer1)
            {
                gAnimatedPaletteTiming.timer1 = 0;
                gAnimatedPaletteTiming.row1--;

                if (gAnimatedPaletteTiming.row1 < 0)
                    gAnimatedPaletteTiming.row1 = sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].numbersOfStates - 1;
                
                update++;
            }
            break;
    }

    if (!update)
        return;

    // Get row
    row = gAnimatedPaletteTiming.row1;
    if (row < 0)
        row = -row;

    // Transfer palette
    if (gSubGameMode1 == SUB_GAME_MODE_PLAYING)
    {
        // Directly to palram if in game
        DMA3_COPY_16(&sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].pPalette[row * PAL_ROW], ANIMATED_PALETTE_PALRAM, PAL_ROW_SIZE / 2);
    }
    else
    {
        // To backup if not in game
        DMA3_COPY_16(&sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].pPalette[row * PAL_ROW], ANIMATED_PALETTE_EWRAM, PAL_ROW_SIZE / 2);    
    }
}

/**
 * @brief 5e424 | dc | Checks if the animated palette should be disabled when loading a room
 * 
 */
void AnimatedPaletteCheckDisableOnTransition(void)
{
    gAnimatedPaletteTiming = sAnimatedPaletteTiming_Empty;
    gHatchFlashingAnimation = sAnimatedPaletteTiming_Empty;

    gDisableAnimatedPalette = FALSE;

    if (gAnimatedGraphicsEntry.palette == ANIMATED_PALETTE_ID_NONE)
        return;

    // Transfer palette
    DMA3_COPY_16(sAnimatedPaletteEntries[gAnimatedGraphicsEntry.palette].pPalette, ANIMATED_PALETTE_PALRAM, PAL_ROW);

    // Check disable
    switch (gAnimatedGraphicsEntry.palette)
    {
        case ANIMATED_PALETTE_ID_ZIPLINE:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
                gDisableAnimatedPalette = TRUE; // No ziplines
            break;

        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 16:
        case 17:
            if (gAlarmTimer == 0)
                gDisableAnimatedPalette = TRUE; // No alarm
    }
}

/**
 * @brief 5e500 | 48 | Checks if the lightning effect should play
 * 
 */
void AnimatedGraphicsCheckPlayLightningEffect(void)
{
    u8 effect;

    effect = BACKGROUND_EFFECT_NONE;

    // Check no effect currently active
    if (gPauseScreenFlag != PAUSE_SCREEN_NONE || gBackgroundEffect.type != BACKGROUND_EFFECT_NONE)
        return;

    // Crateria, landing site with no gunship
    if (gCurrentArea == AREA_CRATERIA && gCurrentRoom == 5)
        effect = BACKGROUND_EFFECT_LIGHTNING;

    // Do effect
    if (effect != BACKGROUND_EFFECT_NONE)
        BackgroundEffectStart(effect);
}

/**
 * @brief 5e548 | 84 | Updates the current background effect
 * 
 */
void BackgroundEffectUpdate(void)
{
    u16 color;

    APPLY_DELTA_TIME_INC(gBackgroundEffect.timer);

    // Process
    color = BackgroundEffectProcess();

    // Check has a color to update
    if (color == 0)
        return;

    // Get color
    color = color == 2
        ? sBackgroundEffectColorData[gBackgroundEffect.type].color_2
        : sBackgroundEffectColorData[gBackgroundEffect.type].color_1;

    if (color & BACKGROUND_EFFECT_NO_COLOR)
        return;

    // Apply on background
    ApplySpecialBackgroundEffectColorOnBG(sBackgroundEffectColorData[gBackgroundEffect.type].colorMask,
        color, gBackgroundEffect.colorStage);

    // Check apply on obj
    if (sBackgroundEffectColorData[gBackgroundEffect.type].applyToObj)
        ApplySpecialBackgroundEffectColorOnOBJ(0xFFFC, color, gBackgroundEffect.colorStage);
}

/**
 * @brief 5e5cc | 12c | Processes the current background effect
 * 
 * @return u16 Color id to update
 */
static u16 BackgroundEffectProcess(void)
{
    u16 colorId;
    const u16* pBehavior;

    colorId = 0;

    pBehavior = sBackgroundEffectBehaviorPointers[gBackgroundEffect.type][gBackgroundEffect.stage];

    // Execute command
    switch (pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_TYPE])
    {
        case BACKGROUND_EFFECT_CMD_WAIT_FOR_TIMER_RANDOM:
            // Wait for a set + random amount of time
            if (gBackgroundEffect.timer > pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_TIMER] + gFrameCounter8Bit + gFrameCounter16Bit / 16)
            {
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
            }
            break;

        case BACKGROUND_EFFECT_CMD_WAIT_FOR_TIMER:
            // Wait for a set amount of time
            if (gBackgroundEffect.timer > pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_TIMER])
            {
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
            }
            break;

        case BACKGROUND_EFFECT_CMD_WAIT_FOR_TIMER_BEFORE:
            // Wait for just before a set amount of time
            if (gBackgroundEffect.timer >= pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_TIMER] - DELTA_TIME)
            {
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;
            }
            break;

        case BACKGROUND_EFFECT_CMD_CHECK_APPLY_FIRST_COLOR:
            if (gColorFading.status == 0)
            {
                // Set color stage
                gBackgroundEffect.colorStage = pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_ARG];
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;

                // Request first color
                colorId = 1;
            }
            break;

        case BACKGROUND_EFFECT_CMD_CHECK_APPLY_SECOND_COLOR:
            if (gColorFading.status == 0)
            {
                // Set color stage
                gBackgroundEffect.colorStage = pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_ARG];
                gBackgroundEffect.stage++;
                gBackgroundEffect.timer = 0;

                // Request second color
                colorId = 2;
            }
            break;

        case BACKGROUND_EFFECT_CMD_PLAY_SOUND:
            // Play sound
            if (pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_ARG] != 0)
                SoundPlay(pBehavior[BACKGROUND_EFFECT_BEHAVIOR_FIELD_CMD_ARG]);

            gBackgroundEffect.stage++;
            gBackgroundEffect.timer = 0;
            break;

        case BACKGROUND_EFFECT_CMD_FINISH_AND_KILL:
            // Kill
            gBackgroundEffect.type = BACKGROUND_EFFECT_NONE;

        case BACKGROUND_EFFECT_CMD_FINISH:
            // End
            gBackgroundEffect.stage = 0;
            gBackgroundEffect.timer = 0;
            break;

        case BACKGROUND_EFFECT_CMD_FINISH_EXIT_ZEBES:
            // End
            gBackgroundEffect.type = BACKGROUND_EFFECT_NONE;
            gBackgroundEffect.stage = 0;
            gBackgroundEffect.timer = 0;

            // Start appropriate color fading
            ColorFadingStart(COLOR_FADING_TOURIAN_ESCAPE);
            gSubGameMode1 = 3;
            break;

        case BACKGROUND_EFFECT_CMD_FINISH_BEFORE_INTRO_TEXT:
            // End
            gBackgroundEffect.type = BACKGROUND_EFFECT_NONE;
            gBackgroundEffect.stage = 0;
            gBackgroundEffect.timer = 0;

            // Start appropriate color fading
            ColorFadingStart(COLOR_FADING_INTRO_TEXT);
            gSubGameMode1 = 3;
            break;
    }

    return colorId;
}

/**
 * @brief 5e6f8 | 68 | Starts a background effect
 * 
 * @param effect Effect type
 * @return u32 bool, could start
 */
u32 BackgroundEffectStart(u8 effect)
{
    if (gBackgroundEffect.type == BACKGROUND_EFFECT_NONE && effect != UCHAR_MAX)
    {
        gBackgroundEffect.type = effect;
        gBackgroundEffect.colorStage = 0;
        gBackgroundEffect.stage = 0;
        gBackgroundEffect.timer = 0;
        gBackgroundEffect.unk_7 = 0; ANIMATED_GFX_EWRAM_BASE;

        // TODO: verify this is the same or different EWRAM as color fading
        DmaTransfer(3, COLOR_DATA_BG_EWRAM2, COLOR_DATA_BG_EWRAM3, PAL_SIZE, 16);
        DmaTransfer(3, COLOR_DATA_OBJ_EWRAM2, COLOR_DATA_OBJ_EWRAM3, PAL_SIZE, 16);
        return TRUE;
    }

    return FALSE;
}
