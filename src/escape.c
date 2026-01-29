#include "escape.h"
#include "gba.h"

#include "data/visual_effects_data.h"

#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"

#include "structs/escape.h"
#include "structs/game_state.h"
#include "structs/particle.h"
#include "structs/samus.h"

/**
 * @brief 53968 | 40 | Determines the current escape timer (if any) based on the events
 * 
 * @return u8 Escape ID
 */
Escape EscapeDetermineTimer(void)
{
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
        {
            // Didn't escape zebes, and mother brain killed
            return ESCAPE_MOTHER_BRAIN;
        }
    }
    else
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA) && EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        {
            // Didn't escape chozodia, and mecha ridley killed
            return ESCAPE_MECHA_RIDLEY;
        }
    }

    return ESCAPE_NONE;
}

/**
 * @brief 539a8 | 38 | Checks if Samus has escaped
 * 
 * @return u8 TRUE if escaped, FALSE otherwise
 */
boolu8 EscapeCheckHasEscaped(void)
{

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
    {
        // Chozodia escape
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA))
            return TRUE;
    }
    else if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        // Tourian escape
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 539e0 | 38 | Updates the OAM of the escape timer
 * 
 */
void EscapeUpdateOam(void)
{
    u16 baseTile;

    // Third palette, base tile of 0x3C0
    baseTile = 3 << 12 | 0x3C0;

    gParticleEscapeOamFrames[24] = baseTile + gEscapeTimerDigits.hundredths;
    gParticleEscapeOamFrames[21] = baseTile + gEscapeTimerDigits.tenths;
    gParticleEscapeOamFrames[15] = baseTile + gEscapeTimerDigits.secondsOnes;
    gParticleEscapeOamFrames[12] = baseTile + gEscapeTimerDigits.secondsTens;
    gParticleEscapeOamFrames[6]  = baseTile + gEscapeTimerDigits.minutesOnes;
    gParticleEscapeOamFrames[3]  = baseTile + gEscapeTimerDigits.minutesTens;
}

/**
 * @brief 53a18 | 30 | Checks if the escape timer graphics should reload
 * 
 */
void EscapeCheckReloadGraphics(void)
{
    if (EscapeDetermineTimer() != ESCAPE_NONE)
    {
        DMA3_COPY_16(sEscapeTimerDigitsGfx, VRAM_OBJ + 0x7800, sizeof(sEscapeTimerDigitsGfx) / 2);
    }
}

/**
 * @brief 53a48 | 60 | Starts an escape
 * 
 */
void EscapeStart(void)
{
    DMA3_COPY_16(sEscapeTimerDigitsGfx, VRAM_OBJ + 0x7800, 0xB0);
    DMA3_COPY_16(sEscapeTimerDigitsGfx + 1024, VRAM_OBJ + 0x7C00, 0xB0);

    // Setup oam
    DMA3_COPY_16(sParticleEscapeOam_Frame0, gParticleEscapeOamFrames, ARRAY_SIZE(gParticleEscapeOamFrames));

    // Escape timer uses absolute position, which isn't converted to pixel coordinates when drawing,
    // hence pixel coordinates are used when creating it
    ParticleSet(SUB_PIXEL_TO_PIXEL(EIGHTH_BLOCK_SIZE),
        SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 8 + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE), PE_ESCAPE);
}

/**
 * @brief 53aa8 | bc | Sets the timer for the current escape
 * 
 */
void EscapeSetTimer(void)
{
    u8 escape;

    escape = EscapeDetermineTimer();

    gEscapeTimerCounter = UCHAR_MAX;

    if (escape == ESCAPE_MOTHER_BRAIN)
    {
        if (gDifficulty == DIFF_EASY)
        {
            CREATE_ESCAPE_TIMER(3, 0, 0);
        }
        else if (gDifficulty == DIFF_HARD)
        {
            CREATE_ESCAPE_TIMER(1, 0, 0);
        }
        else
        {
            CREATE_ESCAPE_TIMER(2, 0, 0);
        }
    }
    else if (escape == ESCAPE_MECHA_RIDLEY)
    {
        if (gDifficulty == DIFF_HARD)
        {
            CREATE_ESCAPE_TIMER(3, 0, 0);
        }
        else
        {
            CREATE_ESCAPE_TIMER(5, 0, 0);
        }
    }
    else
    {
        CREATE_ESCAPE_TIMER(99, 99, 99);
    }
}

/**
 * @brief 53b64 | 104 | Updates the escape timer
 * 
 */
void EscapeUpdateTimer(void)
{
    u32 counter;

    if (EscapeDetermineTimer() == ESCAPE_NONE || gCurrentEscapeStatus != ESCAPE_STATUS_HAPPENNING)
    {
        gCurrentEscapeStatus = ESCAPE_STATUS_NONE;
        return;
    }

    if (gSubGameMode1 != SUB_GAME_MODE_PLAYING)
        return;

    if (gPreventMovementTimer != 0)
        return;

    counter = APPLY_DELTA_TIME_INC(gEscapeTimerCounter);

    if (counter % CONVERT_SECONDS(1.f / 30))
    {
        if (gEscapeTimerDigits.hundredths > 1)
        {
            gEscapeTimerDigits.hundredths -= 2;
        }
        else
        {
            gEscapeTimerDigits.hundredths += 8;

            if (gEscapeTimerDigits.tenths != 0)
                gEscapeTimerDigits.tenths--;
            else
                gEscapeTimerDigits.tenths = 9;
        }
    }
    else
    {
        if (gEscapeTimerDigits.hundredths != 0)
        {
            gEscapeTimerDigits.hundredths--;
        }
        else
        {
            gEscapeTimerDigits.hundredths = 9;

            if (gEscapeTimerDigits.tenths != 0)
                gEscapeTimerDigits.tenths--;
            else
                gEscapeTimerDigits.tenths = 9;
        }
    }

    if (counter % SIMULATED_FPS == 0)
    {
        gEscapeTimerDigits.hundredths = 99 / 10;
        gEscapeTimerDigits.tenths = 99 % 10;

        if (gEscapeTimerDigits.secondsOnes != 0)
        {
            gEscapeTimerDigits.secondsOnes--;
            return;
        }

        gEscapeTimerDigits.secondsOnes = 9;

        if (gEscapeTimerDigits.secondsTens != 0)
        {
            gEscapeTimerDigits.secondsTens--;
            return;
        }

        gEscapeTimerDigits.secondsTens = 5;
        if (gEscapeTimerDigits.minutesOnes != 0)
        {
            gEscapeTimerDigits.minutesOnes--;
            return;
        }

        gEscapeTimerDigits.minutesOnes = 9;
        if (gEscapeTimerDigits.minutesTens != 0)
        {
            gEscapeTimerDigits.minutesTens--;
            return;
        }

        CREATE_ESCAPE_TIMER(0, 0, 0);
        gCurrentEscapeStatus = ESCAPE_STATUS_FAILED;
    }
}
