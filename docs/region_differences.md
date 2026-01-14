# Region Differences

This document explains all of the differences in releases of the game compared to the US version. These are the release dates for each region:

- US: 2004-02-09
- EU: 2004-04-08
- JP: 2004-05-27
- CN: 2005-06-15

There are also two beta versions of the game that have leaked: one with a US game code dated 2003-12-02, and one with an EU game code dated 2004-01-14.

Even though the EU version was released before the JP version, evidence from the decompilation suggests that EU was worked on after the US and JP versions were finalized.


## Contents

- [EU Differences](#eu-differences)
- [JP Differences](#jp-differences)
- [CN Differences](#cn-differences)
- [Beta US Differences](#beta-us-differences)
- [Beta EU Differences](#beta-eu-differences)


## EU Differences

### Code Differences

#### General

- The `DmaTransfer` and `BitFill` functions are called in many places instead of writing directly to the DMA registers
- A few places use an integer to indicate the game region (EU uses 1)
  - `SramWrite_FileScreenOptionsUnlocked` in [save_file.c](../src/save_file.c)
  - `CheckUnlockTimeAttack` in [time_attack.c](../src/time_attack.c)
  - `PauseDebugDrawStaticInfo` in [status_screen.c](../src/menus/status_screen.c)
- Save file game version text has "EUR" in the string
  - `SramWrite_FileScreenOptionsUnlocked` in [save_file.c](../src/save_file.c)
- The cursor for "Yes" on the easy sleep menu is moved slightly to the right (due to text being thinner)
  - `PauseScreenEasySleepMainLoop` in [pause_screen_sub_menus.c](../src/menus/pause_screen_sub_menus.c)
- The credits scroll a bit faster due to being longer
  - `CreditsDisplay` in [ending_and_gallery.c](../src/ending_and_gallery.c)
- Text drawing has an extra check that can increment the character width by 1 (TODO: investigate the purpose of this)
  - `TextDrawCharacter` and `TextDrawMessageCharacter` in [text.c](../src/text.c)
- `CheckForMaintainedInput` allows for two different speeds (the language select menu uses a slower speed)
  - `MaintainedInputSpeed` in [pause_screen.h](../include/menus/pause_screen.h)
  - `CheckForMaintainedInput` and `PauseScreenCallStateMainLoop` in [pause_screen.c](../src/menus/pause_screen.c)
  - `BootDebugHandleInput` in [boot_debug.c](../src/menus/boot_debug.c)
  - `FileSelectUpdateSubMenu` and `OptionsMainLoop` in [file_select.c](../src/menus/file_select.c)

#### Language

- In several places, the language is set to English if it's not a valid European language
  - `unk_7584c` in [save_file.c](../src/save_file.c)
  - `FileSelectSetLanguage` in [file_select.c](../src/menus/file_select.c)
  - `EraseSramInit` in [erase_sram.c](../src/menus/erase_sram.c)
  - `FileSelectSetLanguage` in [file_select.c](../src/menus/file_select.c)
- `SramWrite_Language` sets the language to 0 if it's invalid
  - `SramWrite_Language` in [save_file.c](../src/save_file.c)
- `SramRead_All` ignores any errors returned by `SramRead_Language`
  - `SramRead_All` in [save_file.c](../src/save_file.c)
- The title screen has a language select menu
  - See [soft_reset.c](../src/soft_reset.c) and [soft_reset_input.c](../src/soft_reset_input.c)
  - `agbmain` in [agbmain.c](../src/agbmain.c)
  - `TitleScreenCheckPlayEffects`, `TitleScreenMainLoop`, and `TitleScreenInit` in [title_screen.c](../src/menus/title_screen.c)
- The title screen has an extra function for setting the menu palette
  - `TitleScreenSetMenuPalette` and `TitleScreenInit` in [title_screen.c](../src/menus/title_screen.c)
- A different palette row is used for title screen debug text
  - `TitleScreenDrawDebugText` in [title_screen.c](../src/menus/title_screen.c)
- In several places, different text graphics are used depending on the language
  - `TitleScreenInit` in [title_screen.c](../src/menus/title_screen.c)
  - `FileSelectInit` in [file_select.c](../src/menus/file_select.c)
  - `ChozodiaEscapeMissionAccomplished` in [chozodia_escape.c](../src/chozodia_escape.c)
  - `EndingImageLoadTextOAM`, `EndingImageDisplayLinePermanently`, `EndingImageInit`, and `EndingImageDisplayText` in [ending_and_gallery.c](../src/ending_and_gallery.c)
- The language is saved after the new file intro has played
  - `InGameCutsceneSamusCloseUp` in [in_game_cutscene.c](../src/in_game_cutscene.c)
- The credits support three additional text characters ('ó', 'ß', and acute accent)
  - `CreditsDisplayLine` in [ending_and_gallery.c](../src/ending_and_gallery.c)
- The language is not checked when the minimap is drawn
  - `MinimapDraw` in [minimap.c](../src/minimap.c)

#### File Select

- Some file select options OAM use a different priority
  - `OptionsUpdateStereoOam`, `OptionsSoundTestMainLoop`, and `OptionsTimeAttackRecordsMainLoop` in [file_select.c](../src/menus/file_select.c)
- The `FileScreenProcessTextStage` enum uses a single value for lines
  - `FileScreenProcessTextStage` in [file_select.h](../include/menus/file_select.h)
  - `FileScreenProcessText` in [file_select.c](../src/menus/file_select.c)
- EWRAM data is laid out differently on the file select screen
  - `OptionsSetupTiletable` and `FileSelectInit` in [file_select.c](../src/menus/file_select.c)
- Selecting a file uses larger horizontal dimensions for window 0
  - `FileSelectProcessFileSelection` in [file_select.c](../src/menus/file_select.c)

#### Gameplay

- A function was added (`InGameIoWriteRegisters`) to handle writing IO values and slightly clean up the code
  - `InGameIoWriteRegisters` and `InGameMainLoop` in [in_game.c](../src/in_game.c)
  - `agbmain` in [agbmain.c](../src/agbmain.c)
- Upgrading suit cutscenes are properly stopped (see [bugs_and_glitches.md](bugs_and_glitches.md#upgrading-suit-cutscene-code-is-still-called-after-the-cutscene-ends))
  - `InGameCutsceneUpgradingSuit` in [in_game_cutscene.c](../src/in_game_cutscene.c)
- The fully powered suit cutscene fades to white instead of black, which reduces flashing (see [bugs_and_glitches.md](bugs_and_glitches.md#the-fully-powered-suit-cutscene-fades-to-black-after-fading-to-white))
  - `GettingFullyPoweredSuitInit` in [getting_fully_powered_suit.c](../src/cutscenes/getting_fully_powered_suit.c)
- BLDCNT is set to brightness increase instead of brightness decrease for some color fades
  - `CutsceneInit` in [cutscene_utils.c](../src/cutscenes/cutscene_utils.c)
- A single frame visual bug is fixed when a power bomb starts exploding (see [bugs_and_glitches.md](bugs_and_glitches.md#the-first-frame-of-power-bomb-explosions-has-a-visual-bug))
  - `HazeSetupCode` in [haze.c](../src/haze.c)
- Samus's standing status is checked before updating her horizontal and vertical movement directions (TODO: investigate the purpose of this)
  - `SamusUpdateHitboxMovingDirection` in [samus.c](../src/samus.c)
- `gSubGameMode1` is checked before taking hazard damage, which prevents dying during a door transition (see [bugs_and_glitches.md](bugs_and_glitches.md#dying-during-a-door-transition-from-lavaacid-puts-samus-in-the-no-clip-state))
  - `SamusExecutePoseMainLoop` in [samus.c](../src/samus.c)
- Samus's pose is checked before updating the highlighted weapon, which prevents highlighting or toggling missiles while dying (see [bugs_and_glitches.md](bugs_and_glitches.md#missiles-can-be-highlighted-and-toggled-while-dying))
  - `SamusExecutePoseMainLoop` in [samus.c](../src/samus.c)
- Ziplines update Samus's horizontal movement direction (TODO: investigate the purpose of this)
  - `ZiplineMoving` in [zipline.c](../src/sprites_AI/zipline.c)

### Data Differences

#### General

- The build date string is "01/14 14:30"
  - `sTitleScreenRomInfoTime` in [title_screen_data.c](../src/data/menus/title_screen_data.c)
- The region strings ("JPN", "EUR", "USA") were removed (likely because they were unused)
  - `sTitleScreenRomInfoRegion*` in [title_screen_data.c](../src/data/menus/title_screen_data.c)
- Character widths are thinner
  - `sCharacterWidths` in [pause_screen_data.c](../src/data/menus/pause_screen_data.c)
- English text gap sizes were changed (due to text being thinner)
  - `sEnglishText_*` in [text_data.c](../src/data/text_data.c)
- Data for the different maintained input speeds
  - `sMaintainedInputDelaysPointers` in [pause_screen.c](../src/menus/pause_screen.c)
  - `sMaintainedInputDelays_Slow` and `sMaintainedInputDelaysLastSet` in [pause_screen_data.c](../src/data/menus/pause_screen_data.c)
- The fully powered suit cutscene uses a different value for BG fading
  - `sCutsceneData` in [cutscenes_data.c](../src/data/cutscenes/cutscenes_data.c)
- An array of 256 0xFF bytes was removed (probably because it was unused)
  - `sBuffer_754ab4` in [shortcut_pointers.c](../src/data/shortcut_pointers.c)

#### Language

- Text was added for German, French, Italian, and Spanish
  - See [text_data.c](../src/data/text_data.c)
- Text pointers have unique pointers for German, French, Italian, and Spanish instead of using English for all of them
  - `sEraseSramTextGfxPointers` in [erase_sram.c](../src/menus/erase_sram.c)
  - `sFileSelectOptionsTextGfxPointers` in [file_select.c](../src/menus/file_select.c)
  - `sGameOverTextPromptGfxPointers` in [game_over.c](../src/menus/game_over.c)
  - `sMapScreenUnknownItemsNamesGfxPointers`, `sMapScreenEquipmentNamesGfxPointers`, and `sMapScreenMenuNamesGfxPointers` in [pause_screen.c](../src/menus/pause_screen.c)
  - `sStoryTextPointers` in [story_text_cutscene.c](../src/cutscenes/story_text_cutscene.c)
  - `sDescriptionTextPointers` in [text.c](../src/text.c)
  - `sLocationTextPointers`, `sMessageTextPointers`, and `sFileScreenTextPointers` in [text_data.c](../src/data/text_data.c)
- Unique text graphics for each language are used in several places
  - `sTitleScreenMenuGfxPointers` in [title_screen.c](../src/menus/title_screen.c)
  - `sFileSelectLargeTextGfxPointers` and `sFileSelectDifficultyTextGfxPointers` in [file_select.c](../src/menus/file_select.c)
  - `sFileSelectAreaNamesGfx`, `sFileSelectBgIconsGfx`, `sFileSelectLargeText*Gfx`, and `sFileSelectDifficultyText*Gfx` in [file_select_data.c](../src/data/menus/file_select_data.c)
  - `sChozodiaEscapeOamPointers_MissionAccomplished` in [chozodia_escape_data.c](../src/data/chozodia_escape_data.c)
  - Lots of graphics and OAM data in [ending_and_gallery_data.c](../src/data/ending_and_gallery_data.c)
- The title screen has an extra palette for the unselected menu item
  - `sTitleScreenUnselectedMenuPal` in [title_screen_data.c](../src/data/menus/title_screen_data.c)
- The status screen OAM for "SUIT" and "MISC" are bigger
  - `sMiscOam_SuitHeader_Frame0` and `sMiscOam_MiscHeader_Frame0` in [pause_screen_data.c](../src/data/menus/pause_screen_data.c)
- The game over cursor X position is different for each language
  - `sGameOverSamusHeadXPositions` in [game_over_data.c](../src/data/menus/game_over_data.c)
- The credits include localization for European languages
  - `sCredits` in [ending_and_gallery_data.c](../src/data/ending_and_gallery_data.c)

#### Rooms
- In Brinstar room 7, a rock on BG2 was removed from above the red door (it was covered by BG1 except for 2 pixels)
  - `sBrinstar_7_Bg2` in [Brinstar_7.c](../src/data/rooms/brinstar/Brinstar_7.c)
- Also in Brinstar room 7, many BG1 tiling errors were fixed, mainly rocks that stick out or don't line up
  - `sBrinstar_7_Bg1` in [Brinstar_7.c](../src/data/rooms/brinstar/Brinstar_7.c)
  - `sTileset_17_Gfx` and `sTileset_17_Tilemap` in [tilesets_set1.c](../src/data/tilesets/tilesets_set1.c)
- Kraid room 17 doesn't use a room effect for the lava
  - `sKraidRoomEntries` in [rooms_data.c](../src/data/rooms_data.c)
  - `sKraid_17_Clipdata` and `sKraid_17_Bg0` in [Kraid_17.c](../src/data/rooms/kraid/Kraid_17.c)
- In Norfair room 20, a slope in the lava was moved one block to the right
  - `sNorfair_20_Clipdata` and `sNorfair_20_Bg1` in [Norfair_20.c](../src/data/rooms/norfair/Norfair_20.c)
- In Norfair rooms 43 and 51, a corner of the tunnel is more rounded
  - `sNorfair_43_Clipdata` and `sNorfair_43_Bg1` in [Norfair_43.c](../src/data/rooms/norfair/Norfair_43.c)
  - `sNorfair_51_Bg1` in [Norfair_51.c](../src/data/rooms/norfair/Norfair_51.c)
- Also in Norfair room 43, an extra door transition block to the right of the tunnel was removed (possibly leftover from an earlier door placement)
  - `sNorfair_43_Clipdata` in [Norfair_43.c](../src/data/rooms/norfair/Norfair_43.c)
- In Chozodia room 51, the speedboost blocks were changed to not reform
  - `sChozodia_51_Clipdata` in [Chozodia_51.c](../src/data/rooms/chozodia/Chozodia_51.c)
- In Chozodia room 77, the missile blocks were changed to never reform (this is what allows 9% completion on hard mode)
  - `sChozodia_77_Clipdata` in [Chozodia_77.c](../src/data/rooms/chozodia/Chozodia_77.c)
- In tileset 74 (used in the Chozo Ruins area), there are blocks used above/below gates with a red rectangle on them. These were changed to work like tileset 44 (Mother Ship area), where the rectangle is transparent and a separate block placed on BG2 has a red rectangle that uses the animated palette
  - `sTileset_74_Gfx` and `sTileset_74_Tilemap` in [tilesets_set7.c](../src/data/tilesets/tilesets_set7.c)


## JP Differences

### Code Differences

- A few places use an integer to indicate the game region (JP uses 0)
  - `SramWrite_FileScreenOptionsUnlocked` in [save_file.c](../src/save_file.c)
  - `CheckUnlockTimeAttack` in [time_attack.c](../src/time_attack.c)
  - `PauseDebugDrawStaticInfo` in [status_screen.c](../src/menus/status_screen.c)
- Save file game version text has "JPN" in the string
  - `SramWrite_FileScreenOptionsUnlocked` in [save_file.c](../src/save_file.c)
- In several places, the language is set to Japanese if it's anything other than Japanese or Hiragana
  - `unk_7584c` in [save_file.c](../src/save_file.c)
  - `FileSelectSetLanguage` in [file_select.c](../src/menus/file_select.c)
  - `EraseSramInit` in [erase_sram.c](../src/menus/erase_sram.c)
- When starting a new file, there's an extra dialog for choosing Japanese for adults (with kanji) or for children (without kanji)
  - `FileSelectMenuMainLoop`, `FileSelectUpdateSubMenu`, and `FileSelectProcessFileSelection` in [file_select.c](../src/menus/file_select.c)
- Hiragana uses different text graphics in some places
  - `FileSelectDisplaySaveFileMiscInfo` in [file_select.c](../src/menus/file_select.c)
  - `PauseScreenInit` in [pause_screen.c](../src/menus/pause_screen.c)
- On the file select screen, the text graphics for "Copy", "Erase", and "Options" are still in English, but there are Japanese translations to the right of them
  - `FileSelectInit` in [file_select.c](../src/menus/file_select.c)
- The title screen uses the registered trademark symbol ®️ instead of the trademark symbol ™️
  - `TitleScreenInit` in [title_screen.c](../src/menus/title_screen.c)

### Data Differences

- The credits don't include localization
  - `sCredits` in [ending_and_gallery_data.c](../src/data/ending_and_gallery_data.c)


## CN Differences

### Code Differences

TODO

### Data Differences

TODO


## Beta US Differences

The beta ROMs include all of the debug related code (see [debug.md](debug.md)), along with all the differences below.

### Code Differences

- Time attack has a flag indicating a new 100% record, which is added instead of bitwise ORed
  - `TimeAttackCheckSetNewRecord` in [time_attack.c](../src/time_attack.c)
- Time attack checks the wrong flag to update the 100% record (0x20 instead of 2)
  - `TimeAttackCheckSetNewRecord` in [time_attack.c](../src/time_attack.c)
- Stereo sound is not restored after using the link cable for the Fusion gallery
  - `FusionGalleryConnectProcess` in [cable_link.c](../src/cable_link.c)
- The enemy drop function is missing a check for the RNG value being 0, which would cause nothing to be dropped
  - `SpriteUtilDetermineEnemyDrop` in [sprite_util.c](../src/sprite_util.c)
- Various differences related to viewing time attack records
  - `OptionsTimeAttackRecordsMainLoop` and `OptionsTimeAttackLoadBestTimeMessage` in [file_select.c](../src/menus/file_select.c)
  - `OptionsTimeAttackStage` and `OptionsOam` in [file_select.h](../include/menus/file_select.h)
- The high priority flag is not set on the gadora before Kraid
  - `GadoraInit` in [gadora.c](../src/sprites_AI/gadora.c)
- Mecha Ridley's missile attack timer increments while Mecha Ridley is idle or curled up, which results in missiles being fired more often
  - `MechaRidley` in [mecha_ridley.c](../src/sprites_AI/mecha_ridley.c)
- Unknown item block light sets its top draw distance to 5 blocks instead of the bottom draw distance, which can cause part of the bottom half to not be drawn
  - `UnknownItemBlock` in [unknown_item_block.c](../src/sprites_AI/unknown_item_block.c)
- Baristutes don't do a collision check before updating its pose, which can cause them to awkwardly walk/jump into walls
  - `BaristuteIdle` in [baristute.c](../src/sprites_AI/baristute.c)
- Kraid's nails target Samus differently
  - `KraidNailMovement` and `KraidNail` in [kraid.c](../src/sprites_AI/kraid.c)

### Data Differences

- Text pointers have unique pointers for German, French, Italian, and Spanish instead of using English for all of them
  - `sEraseSramTextGfxPointers` in [erase_sram.c](../src/menus/erase_sram.c)
  - `sFileSelectOptionsTextGfxPointers` in [file_select.c](../src/menus/file_select.c)
  - `sGameOverTextPromptGfxPointers` in [game_over.c](../src/menus/game_over.c)
  - `sMapScreenUnknownItemsNamesGfxPointers`, `sMapScreenEquipmentNamesGfxPointers`, and `sMapScreenMenuNamesGfxPointers` in [pause_screen.c](../src/menus/pause_screen.c)
  - `sStoryTextPointers` in [story_text_cutscene.c](../src/cutscenes/story_text_cutscene.c)
  - `sDescriptionTextPointers` in [text.c](../src/text.c)
- Baristutes have twice as much health (400 instead of 200)
  - `sPrimarySpriteStats` in [sprite_data.c](../src/data/sprite_data.c)
- Demo 15 is slightly different, due to baristutes having more health
  - `sDemo15_Inputs` and `sDemo15_Durations` in [demo_data.c](../src/data/demo_data.c)
- Chozodia room 54 has an effect Y position of 11, most likely from an earlier room design where lava filled the whole room
  - `sChozodiaRoomEntries` in [rooms_data.c](../src/data/rooms_data.c)
- There are extra bytes at the end of the NES Metroid data (the purpose is unknown)
  - `sNesMetroidDataEnd` in [nes_metroid.c](../src/data/nes_metroid.c)
- Time attack "best time" text is missing gaps at the start
  - `sEnglishText_FileScreen_BestTime` and `sEnglishText_FileScreen_BestTime100` in [text_data.c](../src/data/text_data.c)
- Incomplete placeholder text is used for German, French, Italian, and Spanish, including text leftover from Fusion
  - See [text_data.c](../src/data/text_data.c)
- The build date string is "12/02 22:00"
  - `sTitleScreenRomInfoTime` in [title_screen_data.c](../src/data/menus/title_screen_data.c)
- The intro and title screen music are louder
  - See [track_2.s](../sound/tracks/track_2.s) and [track_4.s](../sound/tracks/track_4.s)
- The priority is higher for sound effects used in the intro
  - See [track_550.s](../sound/tracks/track_550.s), [track_551.s](../sound/tracks/track_551.s), [track_552.s](../sound/tracks/track_552.s), [track_553.s](../sound/tracks/track_553.s), [track_554.s](../sound/tracks/track_554.s), and [track_555.s](../sound/tracks/track_555.s)


## Beta EU Differences

The beta ROMs include all of the debug related code (see [debug.md](debug.md)), along with all the differences below. The differences here are compared to the official EU release.

### Code Differences

- The credits can be skipped by pressing `L` (the US beta does not have this feature)
  - `CreditsMainLoop` in [ending_and_gallery.c](../src/ending_and_gallery.c)

### Data Differences

- There are extra bytes at the end of the NES Metroid data, different from the US beta (the purpose is unknown)
  - `sNesMetroidDataEnd` in [nes_metroid.c](../src/data/nes_metroid.c)
