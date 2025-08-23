#include "sprites_AI/message_banner.h"
#include "gba.h"
#include "sprites_AI/ruins_test.h"
#include "macros.h"

#include "data/sprites/message_banner.h"

#include "constants/audio.h"
#include "constants/demo.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/power_bomb_explosion.h"

// Save yes no cursor

#define SAVE_YES_NO_CURSOR_POSE_INPUT 0x9
#define SAVE_YES_NO_CURSOR_POSE_SAVING 0x43

#define SAVE_YES_NO_CURSOR_LEFT_POSITION ((u16)(SCREEN_SIZE_X * .225f))
#define SAVE_YES_NO_CURSOR_RIGHT_POSITION ((u16)(SCREEN_SIZE_X * .625f))

#define MESSAGE_BANNER_TIMER yPositionSpawn
#define MESSAGE_BANNER_PROCESSING work0
#define MESSAGE_BANNER_NEW_ITEM work2

/**
 * @brief 1b6b8 | 110 | Initializes a message banner sprite
 * 
 */
static void MessageBannerInit(void)
{
    u8 message;
    u8 gfxSlot;
    u8 i;

    gPreventMovementTimer = SAMUS_ITEM_PMT;

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
    {
        gCurrentSprite.status |= SPRITE_STATUS_ONSCREEN;
        gCurrentSprite.roomSlot = UCHAR_MAX;
    }

    message = gCurrentSprite.roomSlot;

    gCurrentSprite.status |= SPRITE_STATUS_HIGH_PRIORITY;
    gCurrentSprite.bgPriority = 0; // On top of everything

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE | SP_ABSOLUTE_POSITION;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(SCREEN_SIZE_X_SUB_PIXEL / 2 + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pOam = sMessageBannerOam_TwoLinesSpawn;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.MESSAGE_BANNER_TIMER = 9 * DELTA_TIME;
    gCurrentSprite.MESSAGE_BANNER_PROCESSING = TRUE;
    gCurrentSprite.MESSAGE_BANNER_NEW_ITEM = FALSE;

    // Flag if the message is the save prompt
    if (message == MESSAGE_SAVE_PROMPT)
        gCurrentSprite.work1 = TRUE;
    else
        gCurrentSprite.work1 = FALSE;

    gfxSlot = 128; // Default

    // Loop through sprites to try and find if a message banner is in the spriteset
    for (i = 0; i < MAX_AMOUNT_OF_SPRITE_TYPES; i++)
    {
        if (gSpritesetSpritesID[i] == PSPRITE_MESSAGE_BANNER)
        {
            // Found area banner, load the gfx slot
            gfxSlot = gSpritesetGfxSlots[i];
            break;
        }
    }

    if (gfxSlot < SPRITE_GFX_SLOT_MAX)
    {
        // Found in the spriteset, skip gfx init
        gCurrentSprite.pose = MESSAGE_BANNER_POSE_POP_UP;
        gCurrentSprite.spritesetGfxSlot = gfxSlot;
    }
    else
    {
        gCurrentSprite.pose = MESSAGE_BANNER_POSE_GFX_INIT;
    }

    // Middle of the screen
    gCurrentSprite.yPosition = SCREEN_SIZE_Y * .3375f;
    gCurrentSprite.xPosition = SCREEN_SIZE_X / 2;

    TextStartMessage(message, gCurrentSprite.spritesetGfxSlot);
}

/**
 * @brief 1b7c8 | 5c | Initializes the Gfx for a message banner
 * 
 */
static void MessageBannerGfxInit(void)
{
    gPreventMovementTimer = SAMUS_ITEM_PMT;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.MESSAGE_BANNER_TIMER);
    if (gCurrentSprite.MESSAGE_BANNER_TIMER == DELTA_TIME * 7)
        SpriteLoadGfx(PSPRITE_MESSAGE_BANNER, gCurrentSprite.spritesetGfxSlot); // Load Gfx
    else if (gCurrentSprite.MESSAGE_BANNER_TIMER == DELTA_TIME * 8)
        SpriteLoadPal(PSPRITE_MESSAGE_BANNER, gCurrentSprite.spritesetGfxSlot, 1); // Load Pal
    
    if (gCurrentSprite.MESSAGE_BANNER_TIMER == 0)
    {
        // Loading done, set pop up behavior
        gCurrentSprite.pose = MESSAGE_BANNER_POSE_POP_UP;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 1b824 | 184 | Handles the pop up animation and the custom behavior based on the current message
 * 
 */
static void MessageBannerPopUp(void)
{
    u16 music;
    u8 msg;
    u8 timer;

    // Work Variable 2 is used as a bool, 1 if getting new item (leading to status screen), 0 otherwise
    gPreventMovementTimer = SAMUS_ITEM_PMT;

    msg = gCurrentSprite.roomSlot;
    if (gCurrentSprite.MESSAGE_BANNER_PROCESSING != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
        if (TextProcessMessageBanner()) // Process text
        {
            // If done processing
            gCurrentSprite.MESSAGE_BANNER_PROCESSING = FALSE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (MESSAGE_IS_ITEM(msg))
            {
                // New item
                gCurrentSprite.MESSAGE_BANNER_NEW_ITEM = TRUE;
                BackupTrackData2SoundChannels();

                // Play item jingle
                if (MESSAGE_IS_UNKNOWN_ITEM(msg))
                    InsertMusicAndQueueCurrent(MUSIC_GETTING_UNKNOWN_ITEM_JINGLE, FALSE);
                else
                    InsertMusicAndQueueCurrent(MUSIC_GETTING_ITEM_JINGLE, FALSE);
            }
            else if (MESSAGE_IS_FIRST_TANK(msg))
            {
                // New tank
                gCurrentSprite.MESSAGE_BANNER_NEW_ITEM = TRUE;
                BackupTrackData2SoundChannels();
                InsertMusicAndQueueCurrent(MUSIC_GETTING_ITEM_JINGLE, FALSE);
            }
            else if (msg == MESSAGE_FULLY_POWERED_SUIT)
            {
                PlayMusic(MUSIC_BRINSTAR_REMIX, 0);
                InsertMusicAndQueueCurrent(MUSIC_GETTING_FULLY_POWERED_SUIT_JINGLE, FALSE);
            }
            else if (msg != MESSAGE_SAVE_PROMPT)
            {
                if (MESSAGE_IS_TANK(msg))
                {
                    BackupTrackData2SoundChannels();
                }

                SoundPlay(MUSIC_GETTING_TANK_JINGLE);
            }
            
            // Check is one line message (new item/ability, save complete, map text)
            if (gCurrentSprite.MESSAGE_BANNER_NEW_ITEM || msg == MESSAGE_SAVE_COMPLETE ||
                (MESSAGE_IS_MAP(msg) || msg == MESSAGE_FULLY_POWERED_SUIT))
            {
                gCurrentSprite.pOam = sMessageBannerOam_OneLineSpawn;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }

        return;
    }

    // Text not done
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        // Spawning animation ended
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = MESSAGE_BANNER_POSE_STATIC;

        // Set static OAM and timer for how long the banner stays
        if (gCurrentSprite.pOam == sMessageBannerOam_OneLineSpawn)
        {
            gCurrentSprite.pOam = sMessageBannerOam_OneLineStatic;

            if (msg == MESSAGE_FULLY_POWERED_SUIT)
                gCurrentSprite.MESSAGE_BANNER_TIMER = CONVERT_SECONDS(5) + TWO_THIRD_SECOND; // Long because jingle is long
            else
                gCurrentSprite.MESSAGE_BANNER_TIMER = CONVERT_SECONDS(1) + TWO_THIRD_SECOND;
        }
        else
        {
            gCurrentSprite.pOam = sMessageBannerOam_TwoLinesStatic;
            gCurrentSprite.MESSAGE_BANNER_TIMER = CONVERT_SECONDS(1) + TWO_THIRD_SECOND;

            if (msg == MESSAGE_SAVE_PROMPT)
            {
                SpriteSpawnSecondary(SSPRITE_SAVE_YES_NO_CURSOR, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, BLOCK_SIZE - PIXEL_SIZE / SUB_PIXEL_RATIO,
                    BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2, 0); // Spawn cursor
            }
            else if (MESSAGE_IS_ESCAPE(msg)) // Escape message
            {
                EscapeStart();
            }
        }
    }
}

/**
 * @brief 1b9a8 | 68 | Handles the message banner being static
 * 
 */
static void MessageBannerStatic(void)
{
    u8 message;

    message = gCurrentSprite.roomSlot;
    if (message == MESSAGE_FULLY_POWERED_SUIT)
        gPreventMovementTimer = 0;
    else
        gPreventMovementTimer = SAMUS_ITEM_PMT;

    // Timer
    if (gCurrentSprite.MESSAGE_BANNER_TIMER != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.MESSAGE_BANNER_TIMER);
        return;
    }

    // Check if should remove (input or demo active, ignore for save prompt)
    if (message != MESSAGE_SAVE_PROMPT &&
        (gButtonInput & (KEY_A | KEY_B | KEY_ALL_DIRECTIONS) || gDemoState != DEMO_STATE_NONE))
    {
        #ifdef BUGFIX
        // If the banner is for a new item, only remove the banner if no power bomb is active
        if (!gCurrentSprite.MESSAGE_BANNER_NEW_ITEM ||
            (!gCurrentPowerBomb.animationState && !gCurrentPowerBomb.powerBombPlaced))
        #endif // BUGFIX
        {
            gCurrentSprite.pose = MESSAGE_BANNER_POSE_REMOVAL_INIT;
        }
    }
}

/**
 * @brief 1ba10 | 50 | Initializes the message banner to be removing
 * 
 */
static void MessageBannerRemovalInit(void)
{
    if (gCollectingTank)
        BgClipFinishCollectingTank();

    if (gCurrentSprite.pOam == sMessageBannerOam_OneLineStatic)
        gCurrentSprite.pOam = sMessageBannerOam_OneLineRemoving;
    else
       gCurrentSprite.pOam = sMessageBannerOam_TwoLinesRemoving;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = MESSAGE_BANNER_POSE_REMOVAL_ANIMATION;
}

/**
 * @brief 1ba60 | b4 | Handles behavior during the removal animation
 * 
 */
static void MessageBannerRemovalAnimation(void)
{
    u8 msg;

    msg = gCurrentSprite.roomSlot;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.status = 0;
        if (msg == MESSAGE_SAVE_COMPLETE)
        {
            // Re-enable pause
            gDisablePause = FALSE;
        }
        else if (msg == MESSAGE_FULLY_POWERED_SUIT)
        {
            // Start suit animation
            gSubSpriteData1.work3 = RUINS_TEST_FIGHT_STAGE_STARTING_SUIT_ANIM;

            // Spawn chozo pillar
            SpriteLoadGfx(PSPRITE_FALLING_CHOZO_PILLAR, 7);
            SpriteLoadPal(PSPRITE_FALLING_CHOZO_PILLAR, 7, 1);
            SpriteSpawnPrimary(PSPRITE_FALLING_CHOZO_PILLAR, 0, 7, gBossWork.work1 - BLOCK_SIZE * 4,
                gBossWork.work2 + BLOCK_SIZE * 12, 0);
        }
        // Check replay sounds
        else if (MESSAGE_IS_TANK(msg))
        {
            RetrieveTrackData2SoundChannels();
        }

        gPreventMovementTimer = 0;

        if (gCurrentSprite.MESSAGE_BANNER_NEW_ITEM)
            gPauseScreenFlag = PAUSE_SCREEN_ITEM_ACQUISITION;
    }
}

/**
 * @brief 1bb14 | e8 | Message banner AI
 * 
 */
void MessageBanner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MessageBannerInit();
            break;
        
        case MESSAGE_BANNER_POSE_GFX_INIT:
            MessageBannerGfxInit();
            break;

        case MESSAGE_BANNER_POSE_POP_UP:
            MessageBannerPopUp();
            break;

        case MESSAGE_BANNER_POSE_STATIC:
            MessageBannerStatic();
            break;

        case MESSAGE_BANNER_POSE_REMOVAL_INIT:
            MessageBannerRemovalInit();
            break;

        case MESSAGE_BANNER_POSE_REMOVAL_ANIMATION:
            MessageBannerRemovalAnimation();
            break;
    }
}

/**
 * @brief 1bbfc | 190 | Save yes no cursor AI
 * 
 */
void SaveYesNoCursor(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_HIGH_PRIORITY;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.bgPriority = 0;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE | SP_ABSOLUTE_POSITION;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.pOam = sSaveYesNoCursorOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = SAVE_YES_NO_CURSOR_POSE_INPUT;
            gCurrentSprite.yPosition = (SCREEN_SIZE_Y * .4f) - 1;

            if (gSpriteData[ramSlot].roomSlot == MESSAGE_SAVE_PROMPT)
                gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_LEFT_POSITION;
            else
                gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_RIGHT_POSITION;
            break;

        case SAVE_YES_NO_CURSOR_POSE_INPUT:
            if (gChangedInput & KEY_LEFT)
            {
                // Check not already on left
                if (gCurrentSprite.xPosition != SAVE_YES_NO_CURSOR_LEFT_POSITION)
                {
                    SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                    gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_LEFT_POSITION;
                }
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Check not already on right
                if (gCurrentSprite.xPosition != SAVE_YES_NO_CURSOR_RIGHT_POSITION)
                {
                    SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                    gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_RIGHT_POSITION;
                }
            }
            else if (gChangedInput & KEY_A)
            {
                gSpriteData[ramSlot].pose = MESSAGE_BANNER_POSE_REMOVAL_INIT;
                if (gCurrentSprite.xPosition == SAVE_YES_NO_CURSOR_LEFT_POSITION)
                {
                    // On left, "yes" option selected
                    SoundPlay(SOUND_YES_NO_CURSOR_SELECTING_YES);
                    gSpriteData[ramSlot].work1 = TRUE;
                    if (gSpriteData[ramSlot].roomSlot == MESSAGE_SAVE_PROMPT)
                    {
                        gCurrentSprite.pose = SAVE_YES_NO_CURSOR_POSE_SAVING;
                        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                        gDisablePause = TRUE;
                        break;
                    }
                }
                else
                {
                    // On right, "no" option selected
                    SoundPlay(SOUND_REFUSE_MENU);
                    gSpriteData[ramSlot].work1 = FALSE;
                }

                gCurrentSprite.status = 0;
            }
            break;

        case SAVE_YES_NO_CURSOR_POSE_SAVING:
            if (SramSaveFile())
                gCurrentSprite.status = 0;
            break;
    }
}
