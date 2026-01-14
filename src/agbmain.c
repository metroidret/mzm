#include "syscalls.h"
#include "data/generic_data.h"
#include "data/menus/language_select_data.h"

#include "gba.h"
#include "audio/track_internal.h"
#include "constants/game_state.h"

#include "structs/cutscene.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/display.h"

void agbmain(void)
{
    InitializeGame();

    while (TRUE)
    {
        gVblankActive = FALSE;
        #ifdef REGION_EU
        if (gMainGameMode == GM_INGAME || gMainGameMode == GM_DEMO)
            InGameIoWriteRegisters();
        #endif // REGION_EU
        UpdateAudio();

        if (gResetGame)
            break;

        UpdateInput();
        SoftResetCheck();

        APPLY_DELTA_TIME_INC(gFrameCounter8Bit);
        APPLY_DELTA_TIME_INC(gFrameCounter16Bit);

        switch (gMainGameMode)
        {
            case GM_SOFT_RESET:
                if (SoftResetMainLoop())
                {
                    gMainGameMode = GM_INTRO;
                    gSubGameMode1 = 0;
                }
                break;

            case GM_INTRO:
                #ifdef DEBUG
                if (gChangedInput & KEY_R)
                {
                    gSubGameMode1 = 0;
                    gMainGameMode = GM_DEBUG_MENU;
                }
                else
                #endif // DEBUG
                if (IntroMainLoop())
                {
                    gMainGameMode = GM_TITLE;
                    gSubGameMode1 = 0;
                }
                break;

            case GM_TITLE:
                #ifdef DEBUG
                if (gChangedInput & KEY_R)
                {
                    gSubGameMode1 = 0;
                    gPauseScreenFlag = 0;
                    gSubGameMode2 = 0;
                    gMainGameMode = GM_DEBUG_MENU;
                }
                else
                #endif // DEBUG
                if (TitleScreenMainLoop())
                {
                    #ifdef REGION_EU
                    gSubGameMode1 = 0;
                    #endif // REGION_EU
                    if (gSubGameMode2 == 1)
                    {
                        gMainGameMode = GM_FILE_SELECT;
                    }
                    else if (gSubGameMode2 == 2)
                    {
                        DemoStart();
                        gMainGameMode = GM_DEMO;
                    }
                    #ifdef REGION_EU
                    else if (gSubGameMode2 == 3)
                    {
                        gMainGameMode = GM_SOFT_RESET;
                        gSubGameMode1 = sLanguageSelectGameModeSub1Values[1];
                    }
                    #endif // REGION_EU
                    else
                    {
                        #ifdef DEBUG
                        gMainGameMode = GM_DEBUG_MENU;
                        #else // !DEBUG
                        gMainGameMode = GM_INTRO;
                        #endif // DEBUG
                    }

                    #ifndef REGION_EU
                    gSubGameMode1 = 0;
                    #endif // !REGION_EU
                    gPauseScreenFlag = 0;
                    gSubGameMode2 = 0;
                }
                break;

            case GM_FILE_SELECT:
                if (FileSelectMenuMainLoop())
                {
                    if (gSubGameMode2 == 1)
                        gMainGameMode = GM_INGAME;
                    else if (gSubGameMode2 == 2)
                        gMainGameMode = GM_INGAME;
                    else if (gSubGameMode2 == 4)
                        gMainGameMode = GM_FUSION_GALLERY;
                    else if (gSubGameMode2 == 5)
                        gMainGameMode = GM_GALLERY;
                    else
                        gMainGameMode = GM_INTRO;

                    gSubGameMode1 = 0;
                    gSubGameMode3 = 0;
                    gSubGameMode2 = 0;
                }
                break;

            case GM_INGAME:
                if (InGameMainLoop()) 
                {
                    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
                    {
                        if (gCurrentCutscene != 0)
                        {
                            gMainGameMode = GM_CUTSCENE;
                        }
                        else if (gTourianEscapeCutsceneStage != 0)
                        {
                            gMainGameMode = GM_TOURIAN_ESCAPE;
                        }
                        else
                        {
                            #ifdef DEBUG
                            gMainGameMode = GM_DEBUG_MENU;
                            #else // !DEBUG
                            gMainGameMode = GM_TITLE;
                            #endif // DEBUG
                            gSubGameMode1 = 0;
                        }
                    }
                    else
                    {
                        gMainGameMode = GM_MAP_SCREEN;
                    }
                }
                break;

            case GM_MAP_SCREEN:
                if (PauseScreenMainLoop())
                {
                    gMainGameMode = gSubGameMode2;
                    gSubGameMode2 = 0;

                    switch (gPauseScreenFlag)
                    {
                        case PAUSE_SCREEN_UNKNOWN_1:
                            gSubGameMode3 = 0;

                        case PAUSE_SCREEN_SUITLESS_ITEMS:
                            gPauseScreenFlag = PAUSE_SCREEN_NONE;
                            break;

                        case PAUSE_SCREEN_UNKNOWN_9:
                            gPauseScreenFlag = PAUSE_SCREEN_NONE;
                            gSubGameMode2 = 1;
                            break;

                        case PAUSE_SCREEN_PAUSE_OR_CUTSCENE:
                        case PAUSE_SCREEN_UNKNOWN_3:
                        case PAUSE_SCREEN_CHOZO_HINT:
                        case PAUSE_SCREEN_MAP_DOWNLOAD:
                        case PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS:
                            break;
                    }

                    gSubGameMode1 = 0;
                }
                break;

            case GM_GAMEOVER:
                if (GameOverMainLoop())
                {
                    gMainGameMode = gSubGameMode2;
                    gSubGameMode1 = 0;
                    gSubGameMode2 = 0;
                }
                break;

            case GM_CHOZODIA_ESCAPE:
                if (ChozodiaEscapeMainLoop())
                {
                    gSubGameMode1 = 0;
                    gMainGameMode = GM_CREDITS;
                }
                break;

            case GM_CREDITS:
                if (CreditsMainLoop())
                {
                    gSubGameMode1 = 0;
                    gMainGameMode = GM_INTRO;
                    #ifdef DEBUG
                    if (gBootDebugActive || gDebugMode)
                        gMainGameMode = GM_DEBUG_MENU;
                    #endif // DEBUG
                }
                break;

            case GM_TOURIAN_ESCAPE:
                if (TourianEscapeMainLoop())
                {
                    gSubGameMode1 = 0;
                    gMainGameMode = gSubGameMode2;
                    #ifdef DEBUG
                    if (gBootDebugActive)
                        gMainGameMode = GM_DEBUG_MENU;
                    #endif // DEBUG
                }
                break;

            case GM_CUTSCENE:
                if (CutsceneMainLoop())
                {
                    gSubGameMode1 = 0;

                    if (gPauseScreenFlag == PAUSE_SCREEN_SUITLESS_ITEMS || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
                    {
                        gMainGameMode = GM_MAP_SCREEN;
                    }
                    else
                    {
                        gMainGameMode = GM_INGAME;
                        #ifdef DEBUG
                        if (gBootDebugActive)
                            gMainGameMode = gBootDebugActive;
                        #endif // DEBUG
                    }
                }
                break;

            case GM_DEMO:
                if (InGameMainLoop())
                {
                    if (gPauseScreenFlag == PAUSE_SCREEN_PAUSE_OR_CUTSCENE)
                    {
                        gPauseScreenFlag = PAUSE_SCREEN_NONE;
                        gSubGameMode3 = 0;
                        gSubGameMode1 = 0;
                        if (gDemoState == 0)
                        {
                            gMainGameMode = gSubGameMode2;
                            gSubGameMode2 = gCurrentDemo.endedWithInput;
                        }
                        else {
                            DemoStart();
                            gMainGameMode = GM_DEMO;
                        }
                    }
                    else
                        gMainGameMode = GM_MAP_SCREEN;
                }
                break;

            case GM_GALLERY:
                if (GalleryMainLoop())
                {
                    gSubGameMode1 = 0;
                    gMainGameMode = GM_FILE_SELECT;
                }
                break;

            case GM_FUSION_GALLERY:
                if (FusionGalleryMainLoop())
                {
                    gSubGameMode1 = 0;
                    gMainGameMode = GM_FILE_SELECT;
                }
                break;

            case GM_START_SOFT_RESET:
                SoftReset();
                break;

            case GM_ERASE_SRAM:
                if (EraseSramMainLoop())
                {
                    if (gSubGameMode2 == 1)
                    {
                        gResetGame = TRUE;
                    }
                    else
                    {
                        gMainGameMode = GM_SOFT_RESET;
                        #ifdef DEBUG
                        if (gDebugMode)
                            gMainGameMode = GM_DEBUG_MENU;
                        #endif // DEBUG
                    }

                    gSubGameMode1 = 0;
                    gSubGameMode2 = 0;
                }
                break;

            case GM_DEBUG_MENU:
                #ifdef DEBUG
                if (BootDebugMainLoop())
                {
                    gSubGameMode1 = 0;

                    switch (gSubGameMode2)
                    {
                        case 1:
                            gMainGameMode = GM_INGAME;
                            break;
                        case 2:
                            #ifdef REGION_EU
                            if (INVALID_EU_LANGUAGE(gLanguage))
                            {
                                gMainGameMode = GM_SOFT_RESET;
                                gSubGameMode1 = sLanguageSelectGameModeSub1Values[2];
                            }
                            else
                            #endif // REGION_EU
                            {
                                gMainGameMode = GM_INTRO;
                            }
                            break;
                        case 3:
                            gMainGameMode = GM_MAP_SCREEN;
                            break;
                        case 6:
                            gMainGameMode = GM_DEMO;
                            break;
                        case 8:
                            gMainGameMode = GM_CUTSCENE;
                            gSubGameMode2 = 0x10;
                            break;
                        case 7:
                            gMainGameMode = GM_TOURIAN_ESCAPE;
                            gSubGameMode2 = 0x10;
                            break;
                        case 5:
                            gMainGameMode = GM_CREDITS;
                            break;
                        case 4:
                            gMainGameMode = GM_CHOZODIA_ESCAPE;
                            break;
                        default:
                            gMainGameMode = GM_DEBUG_MENU;
                            gWrittenToBldy_NonGameplay = 0;
                            break;
                    }
                }
                #else // !DEBUG
                while (TRUE);
                #endif // DEBUG
                break;
        }
        

        gVBlankRequestFlag &= ~TRUE;
        gVblankActive = TRUE;

        do {
            SYSCALL(2); /* SYS_Halt */
        } while (!(gVBlankRequestFlag & 1));
    }
}
