#include "structs/animated_graphics.h"
#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/block.h"
#include "structs/cable_link.h"
#include "structs/chozodia_escape.h"
#include "structs/clipdata.h"
#include "structs/color_effects.h"
#include "structs/connection.h"
#include "structs/cutscene.h"
#include "structs/demo.h"
#include "structs/display.h"
#include "structs/ending_and_gallery.h"
#include "structs/escape.h"
#include "structs/fusion_gallery.h"
#include "structs/game_state.h"
#include "structs/haze.h"
#include "structs/hud.h"
#include "structs/intro.h"
#include "structs/in_game_cutscene.h"
#include "structs/in_game_timer.h"
#include "structs/link.h"
#include "structs/menu.h"
#include "structs/minimap.h"
#include "structs/multiboot.h"
#include "structs/particle.h"
#include "structs/power_bomb_explosion.h"
#include "structs/projectile.h"
#include "structs/room.h"
#include "structs/samus.h"
#include "structs/save_file.h"
#include "structs/screen_shake.h"
#include "structs/scroll.h"
#include "structs/sprite.h"
#include "structs/text.h"
#include "structs/time_attack.h"
#include "structs/tourian_escape.h"
#include "structs/transfer.h"
#include "structs/transparency.h"
#include "structs/visual_effects.h"

#include "sprite_debris.h"
#include "oam.h"
#include "temp_globals.h"


IWRAM_DATA u8 gDebugMode = 0;
IWRAM_DATA u8 gBootDebugActive = 0;
IWRAM_DATA u16 gFrameCounter16Bit = 0;
IWRAM_DATA u8 gStereoFlag = 0;
IWRAM_DATA u8 gSubGameModeStage = 0;
IWRAM_DATA u16 gWrittenToBldalpha = 0;
IWRAM_DATA u16 gWrittenToBldcnt_Internal = 0;
IWRAM_DATA u16 gWrittenToDispcnt = 0;

#ifdef RAM_PADDING
IWRAM_DATA u16 gUnk_300000C = 0;
#endif

IWRAM_DATA u8 gWrittenToWinIn_H = 0;
IWRAM_DATA u8 gWrittenToWinOut_L = 0;
IWRAM_DATA u16 gBackdropColor = 0;
IWRAM_DATA s8 gWrittenToBldy = 0;

IWRAM_DATA struct FileScreenOptionsUnlocked gFileScreenOptionsUnlocked = {};
IWRAM_DATA s8 gLanguage = 0;
IWRAM_DATA struct GameCompletion gGameCompletion = {};
IWRAM_DATA u8 gCompletedGameFlagCopy = 0;
IWRAM_DATA MonochromeFading gMonochromeBgFading = 0;
IWRAM_DATA u8 gWhichBGPositionIsWrittenToBG3OFS = 0;
IWRAM_DATA u8 gSamusOnTopOfBackgrounds = 0;
IWRAM_DATA Difficulty gDifficulty = 0;
IWRAM_DATA boolu8 gUseMotherShipDoors = 0;
IWRAM_DATA boolu8 gTimeAttackFlag = 0;
IWRAM_DATA u8 gCutsceneToSkip = 0;

IWRAM_DATA struct MusicTrackInfo gMusicTrackInfo = {};
IWRAM_DATA struct Demo gCurrentDemo = {};
IWRAM_DATA boolu8 gResetGame = 0;
IWRAM_DATA u8 gDisableScrolling = 0;
IWRAM_DATA u16 gSlowScrollingTimer = 0;
IWRAM_DATA boolu8 gDisableMusic = 0;
IWRAM_DATA boolu8 gDisableCutscenes_Unused = 0;
IWRAM_DATA boolu8 gSkipDoorTransition = 0;
IWRAM_DATA boolu8 gDisableSoftReset = 0;
IWRAM_DATA s8 gCollectingTank = 0;
IWRAM_DATA u8 gDisableAnimatedGraphicsTimer = 0;
IWRAM_DATA u16 gAnimatedGraphicsToUpdate = 0;
IWRAM_DATA u8 gDisableDoorAndTanks = 0;
IWRAM_DATA s8 gDisablePause = 0;
IWRAM_DATA boolu8 gHideHud = 0;
IWRAM_DATA boolu8 gShipLandingFlag = 0;
IWRAM_DATA u8 gDisableClipdataChangingTransparency = 0;
IWRAM_DATA s8 gDisableAnimatedPalette = 0;
IWRAM_DATA u32 gInGameCutscenesTriggered[1] = {};
IWRAM_DATA Area gCurrentArea = 0;
IWRAM_DATA u8 gCurrentRoom = 0;
IWRAM_DATA u8 gLastDoorUsed = 0;
IWRAM_DATA u8 gLastDoorProperties = 0;
IWRAM_DATA boolu8 gDisplayLocationText = 0;
IWRAM_DATA u8 gMinimapX = 0;
IWRAM_DATA u8 gMinimapY = 0;
IWRAM_DATA u8 gNumberOfNeverReformBlocks[MAX_AMOUNT_OF_AREAS] = {0};
IWRAM_DATA u8 gNumberOfItemsCollected[MAX_AMOUNT_OF_AREAS] = {0};
IWRAM_DATA HazeValue gCurrentHazeValue = 0;
IWRAM_DATA u16 gEffectYPosition = 0;
IWRAM_DATA s16 gEffectYPositionOffset = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3000070 = 0;
#endif

IWRAM_DATA u8 gScreenShakeXOffset = 0;
IWRAM_DATA u8 gScreenShakeYOffset = 0;
IWRAM_DATA u16 gScreenShakeRelated = 0;
IWRAM_DATA u16 gDispcntBackup = 0;
IWRAM_DATA u8 gSpriteset = 0;
IWRAM_DATA ClipdataAffectingAction gCurrentClipdataAffectingAction = 0;
IWRAM_DATA u8 gSpritesetEntryUsed = 0;
IWRAM_DATA s8 gDoorUnlockTimer = 0;
IWRAM_DATA u8 gDisableDrawingSprites = 0;
IWRAM_DATA Cutscene gCurrentCutscene = 0;
IWRAM_DATA s8 gTourianEscapeCutsceneStage = 0;
IWRAM_DATA u8 gNoClipLockCamera = 0;
IWRAM_DATA struct Haze gHazeInfo = {};
IWRAM_DATA struct IoRegistersBackup gIoRegistersBackup = {};
IWRAM_DATA struct BackgroundPointersAndDimensions gBgPointersAndDimensions = {};
IWRAM_DATA struct RoomEntry gCurrentRoomEntry = {};
IWRAM_DATA struct CurrentAffectingClip gCurrentAffectingClipdata = {};

#ifdef RAM_PADDING
IWRAM_DATA u32 gUnk_30000E0 = 0;
#endif

IWRAM_DATA struct BackgroundPositions gBackgroundPositions = {};
IWRAM_DATA struct Coordinates gWaitingSpacePiratesPosition = {};
IWRAM_DATA struct BG2Movement gBg2Movement = {};
IWRAM_DATA struct LockScreen gLockScreen = {};
IWRAM_DATA struct SuitFlashEffect gSuitFlashEffect = {};
IWRAM_DATA struct ScreenShake gScreenShakeY = {};
IWRAM_DATA struct ScreenShake gScreenShakeX = {};
IWRAM_DATA struct Scroll gCurrentScrolls[2] = {};
IWRAM_DATA struct PowerBomb gCurrentPowerBomb = {};
IWRAM_DATA struct Camera gCamera = {};
IWRAM_DATA u8 gMaxInGameTimerFlag = 0;
IWRAM_DATA struct InGameTimer gInGameTimer = {};
IWRAM_DATA struct InGameTimer gBestCompletionTimes[12] = {};
IWRAM_DATA struct InGameTimer gInGameTimerAtBosses[MAX_AMOUNT_OF_IGT_AT_BOSSES] = {};
IWRAM_DATA struct LastElevatorUsed gLastElevatorUsed = {};
IWRAM_DATA struct InGameCutscene gInGameCutscene = {};
IWRAM_DATA u16 gAlarmTimer = 0;
IWRAM_DATA struct SpriteData gSpriteData[MAX_AMOUNT_OF_SPRITES] = {};
IWRAM_DATA u8 gSpritesetSpritesID[MAX_AMOUNT_OF_SPRITE_TYPES] = {};
IWRAM_DATA u8 gSpritesetGfxSlots[MAX_AMOUNT_OF_SPRITE_TYPES] = {};
IWRAM_DATA struct SubSpriteData gSubSpriteData1 = {};
IWRAM_DATA struct SubSpriteData gSubSpriteData2 = {};
IWRAM_DATA u8 gParasiteRelated = 0;
IWRAM_DATA struct SpriteData gCurrentSprite = {};
IWRAM_DATA struct SpriteDebris gSpriteDebris[MAX_AMOUNT_OF_SPRITE_DEBRIS] = {};
IWRAM_DATA u8 gPreviousVerticalCollisionCheck = 0;
IWRAM_DATA u8 gPreviousCollisionCheck = 0;
IWRAM_DATA u8 gIgnoreSamusAndSpriteCollision = 0;
IWRAM_DATA u8 gSpriteDrawOrder[MAX_AMOUNT_OF_SPRITES] = {};
IWRAM_DATA struct BossWork gBossWork = {};
IWRAM_DATA u8 gSpriteRng = 0;
IWRAM_DATA struct ParticleEffect gParticleEffects[MAX_AMOUNT_OF_PARTICLES] = {};
IWRAM_DATA HudHighlightStatus gMissileHighlightStatus = 0;
IWRAM_DATA HudHighlightStatus gPowerBombHighlightStatus = 0;
IWRAM_DATA HudHighlightStatus gSuperMissileHighlightStatus = 0;
IWRAM_DATA MinimapUpdateFlag gUpdateMinimapFlag = 0;
IWRAM_DATA struct HudDigits gEnergyDigits = {};
IWRAM_DATA struct HudDigits gMaxEnergyDigits = {};
IWRAM_DATA struct HudDigits gMissileDigits = {};
IWRAM_DATA struct HudDigits gPowerBombDigits = {};
IWRAM_DATA struct HudDigits gSuperMissileDigits = {};
IWRAM_DATA const u16* gCurrentParticleEffectOamFramePointer = 0;
IWRAM_DATA u8 gAmmoDigitsGfx[64] = {};
IWRAM_DATA EscapeStatus gCurrentEscapeStatus = 0;
IWRAM_DATA u8 gEscapeTimerCounter = 0;
IWRAM_DATA struct EscapeDigits gEscapeTimerDigits = {};
IWRAM_DATA u16 gParticleEscapeOamFrames[OAM_DATA_SIZE(8)] = {0};
IWRAM_DATA u8 gEnergyRefillAnimation = 0;
IWRAM_DATA u8 gMissileRefillAnimation = 0;
IWRAM_DATA u8 gSuperMissileRefillAnimation = 0;
IWRAM_DATA u8 gPowerBombRefillAnimation = 0;
IWRAM_DATA u16 gParticleSamusReflectionOamFrames[OAM_DATA_SIZE(24)] = {};
IWRAM_DATA struct ProjectileData gProjectileData[MAX_AMOUNT_OF_PROJECTILES] = {};
IWRAM_DATA u16 gArmCannonY = 0;
IWRAM_DATA u16 gArmCannonX = 0;
IWRAM_DATA PauseScreenFlag gPauseScreenFlag = 0;
IWRAM_DATA Area gAreaBeforeTransition = 0;
IWRAM_DATA s8 gCurrentItemBeingAcquired = 0;
IWRAM_DATA s8 gOptionsOptionSelected = 0;
IWRAM_DATA u16 gBg0HOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg0VOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg1HOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg1VOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg2HOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg2VOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg3HOFS_NonGameplay = 0;
IWRAM_DATA u16 gBg3VOFS_NonGameplay = 0;
IWRAM_DATA u16 gCurrentOamRotation = 0;
IWRAM_DATA u16 gCurrentOamScaling = 0;
IWRAM_DATA struct LastAreaName gLastAreaNameVisited = {};
IWRAM_DATA struct Message gCurrentMessage = {};
IWRAM_DATA u8 gSramCorruptFlag = 0;
IWRAM_DATA bools8 gIsLoadingFile = 0;
IWRAM_DATA s8 gMostRecentSaveFile = 0;
IWRAM_DATA boolu8 gHasSaved = 0;
IWRAM_DATA u8 gUnk_3000C20 = 0;
IWRAM_DATA u8 gSramOperationStage = 0;
IWRAM_DATA struct SaveFileInfo gSaveFilesInfo[3] = {};
IWRAM_DATA struct SectionInfo gSectionInfo = {};
IWRAM_DATA GameMode gMainGameMode = 0;
IWRAM_DATA s16 gSubGameMode1 = 0;
IWRAM_DATA s8 gSubGameMode2 = 0;
IWRAM_DATA s8 gSubGameMode3 = 0;
IWRAM_DATA bools8 gVblankActive = 0;
IWRAM_DATA u8 gFrameCounter8Bit = 0;
IWRAM_DATA vu16 gVBlankRequestFlag = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3000C7A = 0;
#endif

IWRAM_DATA u16 gInterruptCode[0x100] = {};
IWRAM_DATA union OamData gOamData[OAM_BUFFER_DATA_SIZE + OAM_BUFFER_AFFINE_SIZE] = {};
IWRAM_DATA u16 gButtonInput = 0;
IWRAM_DATA u16 gPreviousButtonInput = 0;
IWRAM_DATA u16 gChangedInput = 0;
IWRAM_DATA u8 gNextOamSlot = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3001383[17] = {};
#endif

IWRAM_DATA s32 gWrittenToBg2X = 0;
IWRAM_DATA s32 gWrittenToBg2Y = 0;
IWRAM_DATA u16 gWrittenToMosaic_H = 0;
IWRAM_DATA u16 gWrittenToMosaic_L = 0;
IWRAM_DATA u16 gBg2XScaling = 0;
IWRAM_DATA u16 gBg2YScaling = 0;
IWRAM_DATA u16 gBg2Rotation = 0;
IWRAM_DATA s16 gWrittenToBg2Pa = 0;
IWRAM_DATA s16 gWrittenToBg2Pb = 0;
IWRAM_DATA s16 gWrittenToBg2Pc = 0;
IWRAM_DATA s16 gWrittenToBg2Pd = 0;
IWRAM_DATA u16 gWrittenToBldy_NonGameplay = 0;
IWRAM_DATA u16 gWrittenToBldalpha_L = 0;
IWRAM_DATA u16 gWrittenToBldalpha_H = 0;
IWRAM_DATA u16 gBg0XPosition = 0;
IWRAM_DATA u16 gBg0YPosition = 0;
IWRAM_DATA u16 gBg1XPosition = 0;
IWRAM_DATA u16 gBg1YPosition = 0;
IWRAM_DATA u16 gBg2XPosition = 0;
IWRAM_DATA u16 gBg2YPosition = 0;
IWRAM_DATA u16 gBg3XPosition = 0;
IWRAM_DATA u16 gBg3YPosition = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_30013C3[14] = {};
#endif

IWRAM_DATA DemoState gDemoState = 0;
IWRAM_DATA struct SamusData gSamusData = {};
IWRAM_DATA struct SamusData gSamusDataCopy = {};
IWRAM_DATA struct WeaponInfo gSamusWeaponInfo = {};
IWRAM_DATA struct SamusEcho gSamusEcho = {};
IWRAM_DATA struct ScrewSpeedAnimation gScrewSpeedAnimation = {};
IWRAM_DATA struct Equipment gEquipment = {};
IWRAM_DATA struct HazardDamage gSamusHazardDamage = {};
IWRAM_DATA struct EnvironmentalEffect gSamusEnvironmentalEffects[5] = {};
IWRAM_DATA struct SamusPhysics gSamusPhysics = {};
IWRAM_DATA u16 gPreviousXPosition = 0;
IWRAM_DATA u16 gPreviousYPosition = 0;
IWRAM_DATA EndingFlags gEndingFlags = 0;
IWRAM_DATA u16 gPreventMovementTimer = 0;
IWRAM_DATA u8 gDisableDrawingSamusAndScrolling = 0;
IWRAM_DATA struct TimeAttackData gTimeAttackData = {};

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3001670[28] = {};
#endif

IWRAM_DATA struct ButtonAssignments gButtonAssignments = {};
IWRAM_DATA struct TimeAttackRecord gTimeAttackRecord = {};
IWRAM_DATA union NonGameplayRam gNonGameplayRam = {};
IWRAM_DATA Func_T gVBlankCallback = 0;
IWRAM_DATA Func_T gHBlankCallback = 0;
IWRAM_DATA Func_T gVCountCallback = 0;
IWRAM_DATA Func_T gSerialCommunicationCallback = 0;
IWRAM_DATA Func_T gTimer3Callback = 0;
IWRAM_DATA struct MusicInfo gMusicInfo = {};

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3003760[12] = {};
#endif

IWRAM_DATA struct PSGSoundData gUnk_300376C[1] = {};

IWRAM_DATA struct PSGSoundData gPsgSounds[4] = {};
IWRAM_DATA struct SoundChannelBackup gSoundChannelBackup[7] = {};
IWRAM_DATA struct SoundChannelBackup gSoundChannelTrack2Backup[7] = {};
IWRAM_DATA struct SoundQueue gSoundQueue[9] = {};
IWRAM_DATA SoundCodeAFunc_T gSoundCodeAPointer = 0;
IWRAM_DATA u8 gSoundCodeA[1624] = {};
IWRAM_DATA SoundCodeBFunc_T gSoundCodeBPointer = 0;
IWRAM_DATA u8 gSoundCodeB[164] = {};
IWRAM_DATA SoundCodeCFunc_T gSoundCodeCPointer = 0;
IWRAM_DATA u8 gSoundCodeC[176] = {};

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3004344 = 0;
#endif

IWRAM_DATA struct TrackVariables gTrack0Variables[12] = {};
IWRAM_DATA struct TrackVariables gTrack1Variables[10] = {};
IWRAM_DATA struct TrackVariables gTrack2Variables[2] = {};
IWRAM_DATA struct TrackVariables gTrack3Variables[2] = {};
IWRAM_DATA struct TrackVariables gTrack4Variables[2] = {};
IWRAM_DATA struct TrackVariables gTrack5Variables[2] = {};
IWRAM_DATA struct TrackVariables gTrack6Variables[3] = {};
IWRAM_DATA struct TrackVariables gTrack7Variables[1] = {};
IWRAM_DATA struct TrackVariables gTrack8Variables[6] = {};

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3004FC8 = 0;
#endif

IWRAM_DATA u8 gUnk_03004FC9 = 0;
IWRAM_DATA u16 gDemoInputData[DEMO_MAX_DURATION] = {};
IWRAM_DATA u16 gDemoInputDuration[DEMO_MAX_DURATION] = {};
IWRAM_DATA u16 gDemoInputNumber = 0;
IWRAM_DATA u16 gDemoInputTimer = 0;
IWRAM_DATA u16 gDemoInput = 0;

IWRAM_DATA u8 gNotPressingUp = 0;
IWRAM_DATA s16 gDebugVCount_InGameStart = 0;
IWRAM_DATA u16 gDebugVCount_InGameEnd = 0;
IWRAM_DATA s16 gDebugVCount_VBlankEnd = 0;
IWRAM_DATA s16 gDebugVCount_AudioMax = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_30053DA[6] = {};
#endif

IWRAM_DATA u16 gSamusPalette[16 * 3] = {};
IWRAM_DATA u16 gSamusPaletteSize = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3005442[6] = {};
#endif

IWRAM_DATA u16 gWrittenToWin1H = 0;
IWRAM_DATA u16 gWrittenToWin1V = 0;
IWRAM_DATA u16 gWrittenToBldcnt = 0;
IWRAM_DATA struct TilemapAndClipPointers gTilemapAndClipPointers = {};
IWRAM_DATA struct HatchData gHatchData[MAX_AMOUNT_OF_HATCHES] = {};
IWRAM_DATA u8 gNumberOfValidHatchesInRoom = 0;
IWRAM_DATA struct Coordinates gDoorPositionStart = {};
IWRAM_DATA struct HatchesState gHatchesState = {};
IWRAM_DATA struct BG3Movement gBg3Movement = {};
IWRAM_DATA struct BG0Movement gBg0Movement = {};
IWRAM_DATA struct TilesetTransparentColor gTilesetTransparentColor = {};

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3005500[4] = {};
#endif

IWRAM_DATA struct Unused_3005504 gUnusedStruct_3005504 = {};
IWRAM_DATA s16 gSamusDoorPositionOffset = 0;
IWRAM_DATA u8 gDestinationRoom = 0;
IWRAM_DATA u16 gBg3CntDuringDoorTransition = 0;
IWRAM_DATA u16 gBg1CntDuringDoorTransition = 0;
IWRAM_DATA u8 gUnk_3005514 = 0;
IWRAM_DATA s8 gScreenYOffset = 0;
IWRAM_DATA s16 gScreenXOffset = 0;
IWRAM_DATA u16 gRainSoundEffect = 0;
IWRAM_DATA struct WaterMovement gWaterMovement = {};
IWRAM_DATA struct ColorFading gColorFading = {};
IWRAM_DATA struct BrokenBlock gBrokenBlocks[MAX_AMOUNT_OF_BROKEN_BLOCKS] = {};
IWRAM_DATA struct LastTank gLastTankCollected = {};
IWRAM_DATA struct BombChain gBombChains[MAX_AMOUNT_OF_BOMB_CHAINS] = {};
IWRAM_DATA u8 gActiveBombChainTypes = 0;

IWRAM_DATA struct TransparencyRelated gTransparencyRelated = {};
IWRAM_DATA struct DefaultTransparency gDefaultTransparency = {};
IWRAM_DATA struct BldalphaData gBldalphaData1 = {};
IWRAM_DATA struct BldalphaData gBldalphaData2 = {};
IWRAM_DATA struct BldyData gBldyData1 = {};
IWRAM_DATA struct BldyData gBldyData2 = {};
IWRAM_DATA struct AnimatedPaletteTiming gAnimatedPaletteTiming = {};
IWRAM_DATA struct AnimatedPaletteTiming gHatchFlashingAnimation = {};
IWRAM_DATA struct AnimatedGraphicsEntry gAnimatedGraphicsEntry = {};
IWRAM_DATA struct BackgroundEffect gBackgroundEffect = {};
IWRAM_DATA u8 gScrollCounter = 0;
IWRAM_DATA ClipFunc_T gClipdataCodePointer = 0;
IWRAM_DATA const u8* gCurrentRoomScrollDataPointer = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_300570C[8] = {};
#endif

IWRAM_DATA struct CameraScrollVelocityCaps gScrollingVelocityCaps = {};
IWRAM_DATA struct HazeLoop gHazeLoops[3] = {};
IWRAM_DATA u8 gUnk_3005728 = 0;
IWRAM_DATA u8 gUnk_3005729 = 0;
IWRAM_DATA HazeFunc_T gHazeProcessCodePointer = 0;
IWRAM_DATA struct AnimatedGraphicsInfo gAnimatedGraphicsData[16] = {};
IWRAM_DATA struct AnimatedTiming gTankAnimations[4] = {};
IWRAM_DATA struct MaintainedInput gMaintainedInputData = {};
IWRAM_DATA u16 gPrevChangedInput = 0;
IWRAM_DATA s8 gOamXOffset_NonGameplay = 0;
IWRAM_DATA s8 gOamYOffset_NonGameplay = 0;

IWRAM_DATA struct IoTransferInfo gIoTransferInfo = {};
IWRAM_DATA struct MultiBootData gMultiBootParamData = {};
IWRAM_DATA const u8* gDataSentPointer = 0;
IWRAM_DATA u32 gDataSentSize = 0;
IWRAM_DATA u32 gMultibootErrorFlags = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3005878[8] = {};
#endif

IWRAM_DATA u32 gMultibootUnk_3005880 = 0;
IWRAM_DATA u8 gMultibootInProgress = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_3005886[2] = {};
#endif

IWRAM_DATA u16 gMultiBootRequiredData[MULTIBOOT_MAX_CHILD] = {};
IWRAM_DATA struct TransferManager gTransferManager = {};
IWRAM_DATA u16 gTransferUpdateResult = 0;
IWRAM_DATA u8 gTransferUnk_30058aa = 0;
IWRAM_DATA u16 gTransferDataTimer = 0;
IWRAM_DATA u8 gTransferStartupTimer = 0;
IWRAM_DATA u8 gTransferUnk_30058af = 0;
IWRAM_DATA u8 gTransferGbaDetectedCount = 0;
IWRAM_DATA u8 gTransferGbaId = 0;
IWRAM_DATA u16 gRegIme_Backup = 0;
IWRAM_DATA u16 gRegIe_Backup = 0;
IWRAM_DATA u16 gRegTm3Cnt_H_Backup = 0;
IWRAM_DATA u16 gRegSiocnt_Backup = 0;
IWRAM_DATA u16 gRegRcnt_Backup = 0;
IWRAM_DATA u32 gLinkStatus = 0;
IWRAM_DATA u16 gSendCmd[CMD_LENGTH] = {};
IWRAM_DATA u16 gRecvCmds[MAX_LINK_PLAYERS][CMD_LENGTH] = {};
IWRAM_DATA u8 gShouldAdvanceLinkState = 0;
IWRAM_DATA u8 gLinkPlayerCount = 0;
IWRAM_DATA u8 gLinkLocalId = 0;
IWRAM_DATA u8 gLinkUnkFlag9 = 0;
IWRAM_DATA u16 gLinkSavedIme = 0;
IWRAM_DATA u8 gNumVBlanksWithoutSerialIntr = 0;
IWRAM_DATA u8 gSendBufferEmpty = 0;

#ifdef RAM_PADDING
IWRAM_DATA u8 gUnk_000058D4[1] = {};
#endif

IWRAM_DATA u8 gHandshakePlayerCount = 0;
IWRAM_DATA u8 gChecksumAvailable = 0;
IWRAM_DATA u16 gSendNonzeroCheck = 0;
IWRAM_DATA u16 gRecvNonzeroCheck = 0;
