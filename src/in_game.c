#include "in_game.h"
#include "dma.h"
#include "gba.h"
#include "callbacks.h"
#include "oam.h"
#include "projectile.h"
#include "samus.h"
#include "sprite.h"
#include "demo_input.h"
#include "particle.h"
#include "room.h"
#include "scroll.h"
#include "init_helpers.h"
#include "hud_generic.h"
#include "display.h"

#include "data/hud_data.h"

#include "constants/demo.h"
#include "constants/haze.h"
#include "constants/game_state.h"

#include "structs/bg_clip.h"
#include "structs/haze.h"
#include "structs/cutscene.h"
#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/sprite.h"
#include "structs/connection.h"

/**
 * @brief c4b4 | 244 | Main loop in game
 * 
 * @return u32 bool, changing game mode
 */
u32 InGameMainLoop(void)
{
    u32 changing;

    #ifdef DEBUG
    gDebugVCount_InGameStart = READ_16(REG_VCOUNT);
    #endif // DEBUG

    SetVBlankCodeInGame();
    changing = FALSE;

    switch (gSubGameMode1)
    {
        case 0:
            #ifdef DEBUG
            gDebugVCount_AudioMax = 0;
            #endif // DEBUG

            if (gSubGameMode3 == 0)
                DemoResetInputAndDuration();

            if (gDemoState == DEMO_STATE_PLAYING)
                CopyDemoInput();

            InitAndLoadGenerics();
            gSubGameMode1++;
            break;

        case SUB_GAME_MODE_DOOR_TRANSITION:
            #ifndef REGION_EU
            IoWriteRegisters();
            #endif // !REGION_EU
            if (ColorFadingFinishDoorTransition()) // Undefined
                gSubGameMode1++;
            break;

        case SUB_GAME_MODE_PLAYING:
            DemoMainLoop();
            #ifndef REGION_EU
            IoWriteRegisters();
            #endif // !REGION_EU

            #ifdef DEBUG
            // Check for no-clip input
            if (gDebugMode && gChangedInput & KEY_START &&
                (gButtonInput & (KEY_L | KEY_B)) == (KEY_L | KEY_B) && !gPreventMovementTimer)
            {
                gSubGameMode1 = SUB_GAME_MODE_NO_CLIP;
            }
            else
            #endif // DEBUG
            {
                if ((gChangedInput & gButtonAssignments.pause || gPauseScreenFlag != PAUSE_SCREEN_NONE) && ProcessPauseButtonPress())
                    gSubGameMode1++;
    
                if (gSubGameMode1 == SUB_GAME_MODE_PLAYING)
                {
                    gPreviousXPosition = gSamusData.xPosition;
                    gPreviousYPosition = gSamusData.yPosition;
    
                    if (!(gButtonInput & KEY_UP))
                        gNotPressingUp = TRUE;
    
                    if (gPreventMovementTimer != 0)
                        APPLY_DELTA_TIME_DEC(gPreventMovementTimer);
                    else
                    {
                        SamusUpdate();
                        SamusUpdateHitboxMovingDirection();
                    }
    
                    InGameTimerUpdate();
                }
    
                RoomUpdateGfxInfo();
            }
            break;

        case SUB_GAME_MODE_LOADING_ROOM:
            #ifndef REGION_EU
            IoWriteRegistersDuringTransition();
            #endif // !REGION_EU
            if (ColorFadingProcess())
            {
                gSubGameMode1 = 0;
                if (gPauseScreenFlag != PAUSE_SCREEN_NONE || gCurrentCutscene != 0 || gTourianEscapeCutsceneStage != 0)
                    changing = TRUE;
            }
            break;

        case SUB_GAME_MODE_DYING:
            #ifndef REGION_EU
            IoWriteRegisters();
            #endif // !REGION_EU
            SamusUpdate();
            RoomUpdateGfxInfo();
            break;

        case SUB_GAME_MODE_NO_CLIP:
            UpdateNoClip_Debug();
            RoomUpdateGfxInfo();
            break;
    }

    if (gSubGameMode1 == SUB_GAME_MODE_DYING)
    {
        SamusCallGfxFunctions();
        SamusDraw();
        ResetFreeOam();
        RoomUpdate();
    }
    else if (gSubGameMode1 != 0)
    {
        RoomUpdateAnimatedGraphicsAndPalettes();
        SpriteUpdate();
    
        if (!gDisableDrawingSamusAndScrolling)
        {
            ScrollProcessGeneral();
            SamusCallGfxFunctions();
        }
        else if (gDisableScrolling == 2)
            ScrollProcessGeneral();
    
        ProjectileUpdate();
        HudDraw();
    
        SpriteDrawAll_HighPriority();
        ParticleProcessAll();
        ProjectileDrawAll_HighPriority();
    
        if (!gDisableDrawingSprites)
            SpriteDrawAll_MediumPriority();
    
        if (!gDisableDrawingSamusAndScrolling)
            SamusDraw();
    
        SpriteDrawAll_LowPriority();
        ProjectileDrawAll_LowPriority();
        
        ResetFreeOam();
        RoomUpdate();
    
        if (gSubGameMode1 == SUB_GAME_MODE_PLAYING)
            SamusCallCheckLowHealth();
    }

    #ifdef DEBUG
    if (gDebugMode == 1)
    {
        if (gDebugVCount_VBlankEnd < SCREEN_SIZE_Y)
            gOamData[0x7E].split.y = gDebugVCount_InGameStart - gDebugVCount_VBlankEnd;
        else if (gDebugVCount_InGameStart > SCREEN_SIZE_Y)
            gOamData[0x7E].split.y = gDebugVCount_InGameStart - gDebugVCount_VBlankEnd;
        else
            gOamData[0x7E].split.y = gDebugVCount_InGameStart - (gDebugVCount_VBlankEnd + 28);

        if (gDebugVCount_AudioMax <= gOamData[0x7E].split.y)
            gDebugVCount_AudioMax = gOamData[0x7E].split.y;

        gOamData[0x7D].split.y = gDebugVCount_AudioMax; 
        gOamData[0x7D].split.x = 234;
        gOamData[0x7D].split.tileNum = 0x76;
        gOamData[0x7D].split.paletteNum = 4;
        gOamData[0x7E].split.x = 234;
        gOamData[0x7E].split.tileNum = 0x77;
        gOamData[0x7E].split.paletteNum = 4;
        gOamData[0x7F].split.y = gDebugVCount_InGameEnd = READ_16(REG_VCOUNT);
        gOamData[0x7F].split.x = 0;
        gOamData[0x7F].split.tileNum = 0x78;
        gOamData[0x7F].split.paletteNum = 4;
    }
    #endif // DEBUG

    return changing;
}

/**
 * @brief c6f8 | 3c | Sets the V-blank code depending on the sub game mode
 * 
 */
void SetVBlankCodeInGame(void)
{
    switch (gSubGameMode1)
    {
        case 0:
        case SUB_GAME_MODE_DOOR_TRANSITION:
        case SUB_GAME_MODE_LOADING_ROOM:
            CallbackSetVblank(VBlankCodeInGameLoad);
            break;

        case SUB_GAME_MODE_PLAYING:
        default:
            CallbackSetVblank(VBlankCodeInGame);
    }
}

#ifdef REGION_EU
/**
 * @brief Calls IoWriteRegisters based on gSubGameMode1
 * 
 */
void InGameIoWriteRegisters(void)
{
    switch (gSubGameMode1)
    {
        case 0:
            break;
        case SUB_GAME_MODE_DOOR_TRANSITION:
        case SUB_GAME_MODE_PLAYING:
        case SUB_GAME_MODE_DYING:
            IoWriteRegisters();
            break;
        case SUB_GAME_MODE_LOADING_ROOM:
            IoWriteRegistersDuringTransition();
            break;
        case SUB_GAME_MODE_NO_CLIP:
            break;
    }
}
#endif // REGION_EU

/**
 * @brief c734 | 160 | Transfers Samus's graphics/palette to VRAM
 * 
 * @param updatePalette Transfer palette flag
 * @param pPhysics Samus Physics Pointer
 */
void TransferSamusGraphics(u32 updatePalette, struct SamusPhysics* pPhysics)
{
    if (gDisableDrawingSamusAndScrolling)
        return;

    if (pPhysics->shoulderGfxSize != 0)
        DMA_SET(3, pPhysics->pShouldersGfx, VRAM_OBJ, C_32_2_16(DMA_ENABLE, pPhysics->shoulderGfxSize / sizeof(u16)));

    if (pPhysics->torsoGfxSize != 0)
        DMA_SET(3, pPhysics->pTorsoGfx, VRAM_BASE + 0x10400, C_32_2_16(DMA_ENABLE, pPhysics->torsoGfxSize / sizeof(u16)));

    if (pPhysics->legsGfxSize != 0)
        DMA_SET(3, pPhysics->pLegsGfx, VRAM_BASE + 0x10280, C_32_2_16(DMA_ENABLE, pPhysics->legsGfxSize / sizeof(u16)));

    if (pPhysics->bodyLowerHalfGfxSize != 0)
        DMA_SET(3, pPhysics->pBodyLowerHalfGfx, VRAM_BASE + 0x10680, C_32_2_16(DMA_ENABLE, pPhysics->bodyLowerHalfGfxSize / sizeof(u16)));

    if (pPhysics->armCannonGfxUpperSize != 0)
        DMA_SET(3, pPhysics->pArmCannonGfxUpper, VRAM_BASE + 0x10800, C_32_2_16(DMA_ENABLE, pPhysics->armCannonGfxUpperSize / sizeof(u16)));

    if (pPhysics->armCannonGfxLowerSize != 0)
        DMA_SET(3, pPhysics->pArmCannonGfxLower, VRAM_BASE + 0x10C00, C_32_2_16(DMA_ENABLE, pPhysics->armCannonGfxLowerSize / sizeof(u16)));

    if (pPhysics->screwSpeedGfxSize != 0)
        DMA_SET(3, pPhysics->pScrewSpeedGfx, VRAM_BASE + 0x10840, C_32_2_16(DMA_ENABLE, pPhysics->screwSpeedGfxSize / sizeof(u16)));

    if (pPhysics->screwShinesparkGfxSize != 0)
        DMA_SET(3, pPhysics->pScrewShinesparkGfx, VRAM_BASE + 0x10C40, C_32_2_16(DMA_ENABLE, pPhysics->screwShinesparkGfxSize / sizeof(u16)));

    if (updatePalette)
        DMA_SET(3, gSamusPalette, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, gSamusPaletteSize / 2));
}

/**
 * @brief c894 | 158 | V-blank code for the in game loads
 * 
 */
void VBlankCodeInGameLoad(void)
{
    vu8 buffer;

    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16((DMA_ENABLE | DMA_32BIT), OAM_SIZE / sizeof(u32)));

    if (gHazeInfo.active)
    {
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16((DMA_ENABLE | DMA_DEST_RELOAD), gHazeInfo.size / sizeof(u16)));
        
        buffer = 0;
        buffer = 0;
        buffer = 0;
        buffer = 0;
        
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_DEST_RELOAD, gHazeInfo.size / sizeof(u16)));

        buffer = 0;
        
        if (!(gVBlankRequestFlag & 1))
        {
            buffer = 0;
            DMA_SET(3, gPreviousHazeValues, gHazeValues, C_32_2_16(DMA_ENABLE, gHazeInfo.unk_4 / sizeof(u16)));
            SET_BACKDROP_COLOR(gBackdropColor);
        }

        buffer = 0;
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD), gHazeInfo.size / sizeof(u16)));
    }

    TransferSamusGraphics(FALSE, &gSamusPhysics);

    if (gWrittenToBldcnt_Internal & BLDCNT_BRIGHTNESS_INCREASE_EFFECT)
    {
        WRITE_16(REG_BLDCNT, gWrittenToBldcnt_Internal);
        gWrittenToBldcnt_Internal = 0;
    }

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    WRITE_16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);

    WRITE_16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    WRITE_16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);

    WRITE_16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    WRITE_16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);

    WRITE_16(REG_BG3HOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].x);
    WRITE_16(REG_BG3VOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].y);

    #ifdef DEBUG
    gDebugVCount_VBlankEnd = READ_16(REG_VCOUNT);
    #endif // DEBUG
}

/**
 * @brief c9ec | 80 | Transfer Samus and background graphics to VRAM
 * 
 */
void TransferSamusAndBgGraphics(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16((DMA_ENABLE | DMA_32BIT), OAM_SIZE / sizeof(u32)));
    TransferSamusGraphics(FALSE, &gSamusPhysics);

    WRITE_16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    WRITE_16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);

    WRITE_16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    WRITE_16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);

    WRITE_16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    WRITE_16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);

    WRITE_16(REG_BG3HOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].x);
    WRITE_16(REG_BG3VOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].y);
}

/**
 * @brief ca6c | 134 | V-blank code when in game
 * 
 */
void VBlankCodeInGame(void)
{
    vu8 buffer;

    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16((DMA_ENABLE | DMA_32BIT), OAM_SIZE / sizeof(u32)));

    if (gHazeInfo.active)
    {
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16((DMA_ENABLE | DMA_DEST_RELOAD), gHazeInfo.size / sizeof(u16)));
        
        buffer = 0;
        buffer = 0;
        buffer = 0;
        buffer = 0;
        
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16(DMA_DEST_RELOAD, gHazeInfo.size / sizeof(u16)));

        buffer = 0;
        
        if (!(gVBlankRequestFlag & 1))
        {
            buffer = 0;
            DMA_SET(3, gPreviousHazeValues, gHazeValues, C_32_2_16(DMA_ENABLE, gHazeInfo.unk_4 / sizeof(u16)));
            SET_BACKDROP_COLOR(gBackdropColor);
        }

        buffer = 0;
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, C_32_2_16((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD), gHazeInfo.size / sizeof(u16)));
    }

    TransferSamusGraphics(TRUE, &gSamusPhysics);

    WRITE_16(REG_MOSAIC, gWrittenToMosaic_H << 4 | gWrittenToMosaic_L);

    WRITE_16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    WRITE_16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);

    WRITE_16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    WRITE_16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);

    WRITE_16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    WRITE_16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);

    WRITE_16(REG_BG3HOFS, gBackgroundPositions.bg[3].x);
    WRITE_16(REG_BG3VOFS, gBackgroundPositions.bg[3].y);

    #ifdef DEBUG
    gDebugVCount_VBlankEnd = READ_16(REG_VCOUNT);
    #endif // DEBUG
}

/**
 * @brief cba0 | c | Empty V-blank code
 * 
 */
void VBlankInGame_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief cbac | 23c | Loads/initializes generic data
 * 
 */
void InitAndLoadGenerics(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);
    WRITE_16(REG_IME, TRUE);

    CallbackSetVblank(VBlankInGame_Empty);

    if (gSubGameMode3 == 0 || gTourianEscapeCutsceneStage != 0)
    {
        ClearGfxRam();
        HudGenericLoadCommonSpriteGfx();
    }

    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;
    ColorFadingHideScreenDuringLoad(); // Undefined
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE || gCurrentCutscene != 0)
        DmaTransfer(3, EWRAM_BASE + 0x1E000, VRAM_OBJ, 0x4000, 16);

    #ifndef DEBUG
    gDebugMode = FALSE;
    #endif // !DEBUG
    DMA_SET(3, sCommonSpritesPal, PALRAM_BASE + 0x240, C_32_2_16(DMA_ENABLE, sizeof(sCommonSpritesPal) / 2));
    SamusInit();

    do {
    } while ((u16)(READ_16(REG_VCOUNT) - 21) < 140); // READ_16(REG_VCOUNT) <= SCREEN_SIZE_Y

    RoomLoad();

    do {
    } while ((u16)(READ_16(REG_VCOUNT) - 21) < 140); // READ_16(REG_VCOUNT) <= SCREEN_SIZE_Y

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && gSubGameMode3 != 0)
    {
        SamusUpdate();
        SamusUpdateHitboxMovingDirection();
    }

    SamusCallGfxFunctions();
    DMA_SET(3, gSamusPalette, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, gSamusPaletteSize / sizeof(u16)));

    TransferSamusAndBgGraphics();

    do {
    } while ((u16)(READ_16(REG_VCOUNT) - 21) < 140); // READ_16(REG_VCOUNT) <= SCREEN_SIZE_Y

    HudGenericResetHUDData();
    SpriteLoadAllData();
    ProjectileCallLoadGraphicsAndClearProjectiles();

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        DmaTransfer(3, EWRAM_BASE + 0x22000, VRAM_BASE + 0x14000, 0x4000, 16);
        DmaTransfer(3, EWRAM_BASE + 0x35700, PALRAM_BASE + 0x300, 0x100, 16);
        DmaTransfer(3, EWRAM_BASE + 0x35460, PALRAM_BASE + 0x60, 0x1A0, 16);
    }

    unk_55f68();

    if (gSubGameMode3 == 0)
    {
        SpriteUpdate();
        gSubGameMode3 = 1;
        gPreventMovementTimer = 0;
    }

    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE - 1;

    do {
    } while ((u16)(READ_16(REG_VCOUNT) - 21) < 140); // READ_16(REG_VCOUNT) <= SCREEN_SIZE_Y


    #ifdef REGION_EU_BETA
    do {
        gIsLoadingFile = FALSE;
        gPauseScreenFlag = PAUSE_SCREEN_NONE;
        gCurrentCutscene = 0;
        gTourianEscapeCutsceneStage = 0;
    } while(0);
    #endif // REGION_EU_BETA

    gIsLoadingFile = FALSE;
    gPauseScreenFlag = PAUSE_SCREEN_NONE;
    gCurrentCutscene = 0;
    gTourianEscapeCutsceneStage = 0;

    CallbackSetVblank(VBlankCodeInGameLoad);
}

void UpdateNoClip_Debug(void)
{
    s32 xVelocity;
    s32 yVelocity;
    u32 bgSize;

    xVelocity = 0;
    yVelocity = 0;

    gPreviousXPosition = gSamusData.xPosition;
    gPreviousYPosition = gSamusData.yPosition;

    if (gChangedInput & (KEY_B | KEY_START))
    {
        gSubGameMode1 = SUB_GAME_MODE_PLAYING;
        gNoClipLockCamera = FALSE;
    }

    if (gChangedInput & KEY_SELECT)
        gNoClipLockCamera ^= TRUE;

    if (gButtonInput & KEY_RIGHT)
        xVelocity = 3 * PIXEL_SIZE;

    if (gButtonInput & KEY_LEFT)
        xVelocity = -(3 * PIXEL_SIZE);

    if (gButtonInput & KEY_UP)
        yVelocity = -(3 * PIXEL_SIZE);

    if (gButtonInput & KEY_DOWN)
        yVelocity = 3 * PIXEL_SIZE;

    if (gButtonInput & (KEY_R | KEY_L))
    {
        xVelocity = (s16)(xVelocity * 2);
        yVelocity = (s16)(yVelocity * 2);
    }

    if (gSamusData.xPosition & 0x8000) // xPos < 0
        gSamusData.xPosition = 0;

    if (gSamusData.yPosition & 0x8000) // yPos < 0
        gSamusData.yPosition = 0;

    bgSize = gBgPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE;
    if (xVelocity < 0)
    {
        if (gSamusData.xPosition < -xVelocity)
            gSamusData.xPosition = 0;
        else
            gSamusData.xPosition += xVelocity;
    }
    else
    {
        if (gSamusData.xPosition > (s32)(bgSize - xVelocity))
            gSamusData.xPosition = bgSize;
        else
            gSamusData.xPosition += xVelocity;
    }

    bgSize = gBgPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE;
    if (yVelocity < 0)
    {
        if (gSamusData.yPosition < -yVelocity)
            gSamusData.yPosition = 0;
        else
            gSamusData.yPosition += yVelocity;
    }
    else
    {
        if (gSamusData.yPosition > (s32)(bgSize - yVelocity))
            gSamusData.yPosition = bgSize;
        else
            gSamusData.yPosition += yVelocity;
    }
}
