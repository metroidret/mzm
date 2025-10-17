MEMORY {
    ewram (rwx): ORIGIN = 0x02000000 LENGTH = 256K
    iwram (rwx): ORIGIN = 0x03000000 LENGTH = 32K
    rom    (rx): ORIGIN = 0x08000000 LENGTH = 32M
}

gNumMusicPlayers = 9;
gUnk_Audio0x64 = 0x64;
gUnk_Audio0x194F700 = 0x194F700;
gUnk_Audio0x50 = 0x50;

__nes_metroid_load_address = 0x87D8000;

SECTIONS {
    ewram 0x2000000 (NOLOAD) : ALIGN(4) {
        . = 0x00002000; gClipdataCollisionTypes = .;
        . = 0x00002400; gClipdataCollisionTypes_Tilemap = .;
        . = 0x00003000; gClipdataBehaviorTypes = .;
        . = 0x00003800; gClipdataBehaviorTypes_Tilemap = .;
        . = 0x00004000; gTilemap = .;
        . = 0x00006000; gCommonTilemap = .;
        . = 0x00007000; gDecompBg3Map = .;
        . = 0x00026300; gHazeValues = .;
        . = 0x00026d00; gPreviousHazeValues = .;
        . = 0x00027700; gCurrentCharacterGfx = .;
        . = 0x00027780; gMakeSolidBlocks = .;
        . = 0x00027800; gDecompClipdataMap = .;
        . = 0x0002a800; gDecompBg0Map = .;
        . = 0x0002d800; gDecompBg1Map = .;
        . = 0x00030800; gDecompBg2Map = .;
        . = 0x00033800; gMinimapTilesWithObtainedItems = .;
        . = 0x00034000; gDecompressedMinimapVisitedTiles = .;
        . = 0x00034800; gDecompressedMinimapData = .;
        . = 0x00035400; gUnk_02035400 = .;
        . = 0x00035c00; gNeverReformBlocks = .;
        . = 0x00036c00; gItemsCollected = .;
        . = 0x00037400; gVisitedMinimapTiles = .;
        . = 0x00037e00; gEventsTriggered = .;
        . = 0x00037e20; gMinimapTilesGfx = .;
        . = 0x00038000; gSram = .;

        . = 0x0003f080; gSramDemoInputData = .;
        . = 0x0003f280; gSramDemoInputDuration = .;
    } >ewram

    iwram 0x3000000 (NOLOAD) : ALIGN(4) {
        src/globals1.o(iwram_data);
        *libgcc.a:dp-bit.o(.bss);
        *libgcc.a:fp-bit.o(.bss);
        src/globals2.o(iwram_data);
        . = 0x00007ff8; gInterruptCheckFlag = .;
        . = 0x00007ffc; gIntrCodePointer = .;
        . = 0x00007ffc; gIntrVector = .;
    } >iwram

    .text : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        asm/intr_main.o(.text);
        src/agbmain.o(.text);
        src/init_game.o(.text);
        src/soft_reset_input.o(.text);
        src/syscall_wrappers.o(.text);
        src/update_input.o(.text);
        src/init_helpers.o(.text);
        src/fixed_point.o(.text);
        src/callbacks.o(.text);
        src/sram_misc.o(.text);

        src/audio.o(.text);
        src/audio_wrappers.o(.text);
        src/dma.o(.text);
        src/music_wrappers.o(.text);

        asm/soundcode.o(.text);
        asm/audio_internal.o(.text);
        asm/syscalls.o(.text);

        src/sram/sram.o(.text);
        src/samus.o(.text);
        src/demo_input.o(.text);
        src/in_game.o(.text);
        src/sprite.o(.text);
        src/sprite_util.o(.text);
        src/sprite_debris.o(.text);
        src/location_text.o(.text);

        src/sprites_AI/chozo_statue_movement.o(.text);
        src/sprites_AI/water_drop.o(.text);
        src/sprites_AI/explosion_zebes_escape.o(.text);
        src/sprites_AI/enemy_drop.o(.text);
        src/sprites_AI/unused_sprites.o(.text);
        src/sprites_AI/morph_ball.o(.text);
        src/sprites_AI/power_grip.o(.text);
        src/sprites_AI/charge_beam.o(.text);
        src/sprites_AI/chozo_statue.o(.text);
        src/sprites_AI/unknown_item_chozo_statue.o(.text);
        src/sprites_AI/chozo_ball.o(.text);
        src/sprites_AI/zoomer.o(.text);
        src/sprites_AI/zeela.o(.text);
        src/sprites_AI/kraid.o(.text);
        src/sprites_AI/message_banner.o(.text);
        src/sprites_AI/ripper.o(.text);
        src/sprites_AI/ripper2.o(.text);
        src/sprites_AI/zeb.o(.text);
        src/sprites_AI/skree.o(.text);
        src/sprites_AI/reo.o(.text);
        src/sprites_AI/zipline.o(.text);
        src/sprites_AI/sova.o(.text);
        src/sprites_AI/multiviola.o(.text);
        src/sprites_AI/geruta.o(.text);
        src/sprites_AI/squeept.o(.text);
        src/sprites_AI/map_station.o(.text);
        src/sprites_AI/save_platform.o(.text);
        src/sprites_AI/dragon.o(.text);
        src/sprites_AI/deorem.o(.text);
        src/sprites_AI/dessgeega.o(.text);
        src/sprites_AI/waver.o(.text);
        src/sprites_AI/hive.o(.text);
        src/sprites_AI/imago_larva.o(.text);
        src/sprites_AI/morph_ball_launcher.o(.text);
        src/sprites_AI/imago_cocoon.o(.text);
        src/sprites_AI/elevator_pad.o(.text);
        src/sprites_AI/space_pirate.o(.text);
        src/sprites_AI/black_space_pirate.o(.text);
        src/sprites_AI/escape_ship_pirate.o(.text);
        src/sprites_AI/zipline_generator.o(.text);
        src/sprites_AI/gamet.o(.text);
        src/sprites_AI/security_gate.o(.text);
        src/sprites_AI/zebbo.o(.text);
        src/sprites_AI/worker_robot.o(.text);
        src/sprites_AI/parasite.o(.text);
        src/sprites_AI/piston.o(.text);
        src/sprites_AI/ridley.o(.text);
        src/sprites_AI/metroid.o(.text);
        src/sprites_AI/rinka.o(.text);
        src/sprites_AI/polyp.o(.text);
        src/sprites_AI/viola.o(.text);
        src/sprites_AI/security_laser.o(.text);
        src/sprites_AI/holtz.o(.text);
        src/sprites_AI/gekitai_machine.o(.text);
        src/sprites_AI/ruins_test.o(.text);
        src/sprites_AI/mella.o(.text);
        src/sprites_AI/atomic.o(.text);
        src/sprites_AI/area_banner.o(.text);
        src/sprites_AI/mother_brain.o(.text);
        src/sprites_AI/acid_worm.o(.text);
        src/sprites_AI/sidehopper.o(.text);
        src/sprites_AI/geron_norfair.o(.text);
        src/sprites_AI/geega.o(.text);
        src/sprites_AI/zebetite_and_cannon.o(.text);
        src/sprites_AI/imago_larva_right_side.o(.text);
        src/sprites_AI/tangle_vine.o(.text);
        src/sprites_AI/imago.o(.text);
        src/sprites_AI/crocomire.o(.text);
        src/sprites_AI/searchlight_eye.o(.text);
        src/sprites_AI/geron.o(.text);
        src/sprites_AI/gunship.o(.text);
        src/sprites_AI/glass_tube.o(.text);
        src/sprites_AI/save_platform_chozodia.o(.text);
        src/sprites_AI/baristute.o(.text);
        src/sprites_AI/elevator_statue.o(.text);
        src/sprites_AI/rising_chozo_pillar.o(.text);
        src/sprites_AI/skultera.o(.text);
        src/sprites_AI/boss_statues.o(.text);
        src/sprites_AI/searchlight.o(.text);
        src/sprites_AI/primary_sprite_B3.o(.text);
        src/sprites_AI/gadora.o(.text);
        src/sprites_AI/steam.o(.text);
        src/sprites_AI/unknown_item_block.o(.text);
        src/sprites_AI/escape_ship.o(.text);
        src/sprites_AI/space_pirate_carrying_power_bomb.o(.text);
        src/sprites_AI/falling_chozo_pillar.o(.text);
        src/sprites_AI/mecha_ridley.o(.text);
        src/sprites_AI/escape_gate.o(.text);

        src/projectile_util.o(.text);
        src/projectile.o(.text);
        src/hud.o(.text);
        src/escape.o(.text);
        src/hud_generic.o(.text);
        src/particle.o(.text);
        src/screen_shake.o(.text);
        src/transparency.o(.text);
        src/room.o(.text);
        src/power_bomb_explosion.o(.text);
        src/gadora_hatch.o(.text);
        src/in_game_timer.o(.text);
        src/display.o(.text);
        src/process_pause_press.o(.text);
        src/room_cutscene.o(.text);
        src/clipdata.o(.text);
        src/scroll.o(.text);
        src/block.o(.text);
        src/bg_clip.o(.text);
        src/color_effects.o(.text);
        src/color_fading.o(.text);
        src/haze.o(.text);
        src/animated_graphics.o(.text);
        src/connection.o(.text);
        src/in_game_cutscene.o(.text);
        src/event.o(.text);
        src/room_music.o(.text);
        src/demo.o(.text);

        src/cutscenes/cutscene_utils.o(.text);
        src/cutscenes/kraid_rising.o(.text);
        src/cutscenes/story_text_cutscene.o(.text);
        src/cutscenes/mother_brain_close_up.o(.text);
        src/cutscenes/ridley_in_space.o(.text);
        src/cutscenes/ridley_landing.o(.text);
        src/cutscenes/ridley_spawn.o(.text);
        src/cutscenes/mecha_sees_samus.o(.text);
        src/cutscenes/getting_fully_powered_suit.o(.text);
        src/cutscenes/before_ruins_test.o(.text);
        src/cutscenes/statue_opening.o(.text);
        src/cutscenes/enter_tourian.o(.text);
        src/cutscenes/samus_in_blue_ship.o(.text);

        src/oam_id.o(.text);
        src/menus/pause_screen.o(.text);
        src/minimap.o(.text);
        src/menus/pause_screen_map.o(.text);
        src/text.o(.text);
        src/menus/status_screen.o(.text);
        src/menus/pause_screen_sub_menus.o(.text);
        src/save_file.o(.text);
        src/save_file_load.o(.text);

#ifdef DEBUG
        src/menus/boot_debug.o(.text);
#endif

        src/menus/erase_sram.o(.text);
        src/menus/title_screen.o(.text);
        src/menus/game_over.o(.text);
        src/menus/file_select.o(.text);

        src/soft_reset.o(.text);
        src/time_attack.o(.text);
        src/complex_oam.o(.text);
        src/intro.o(.text);
        src/tourian_escape.o(.text);
        src/fusion_gallery.o(.text);
        src/ending_and_gallery.o(.text);
        src/chozodia_escape.o(.text);
        src/cable_link.o(.text);
        src/multiboot.o(.text);
        src/transfer.o(.text);
        src/link.o(.text);

        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_fixunsdfsi.o(.text);
        *libgcc.a:_modsi3.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        *libgcc.a:_umodsi3.o(.text);

        *libgcc.a:dp-bit.o(.text);
        *libgcc.a:fp-bit.o(.text);
        *libgcc.a:_lshrdi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_negdi2.o(.text);
        *libc.a:memcpy.o(.text);
    } >rom

    .rodata : ALIGN(2) {
        src/data/generic_data.o(.rodata);
        src/data/audio.o(.rodata);

        sound/voice_groups.o(.rodata);
        sound/programmable_wave_data.o(.rodata);

        src/data/music_track_data.o(.rodata);
        sound/sound_entries.o(.rodata);

        sound/tracks/track_0.o(.rodata);

        sound/direct_sound_data.o(.rodata);

        sound/track_data.o(.rodata);

        src/sram/sram.o(.rodata);

        src/data/samus/samus_empty_data.o(.rodata);
        src/data/samus/arm_cannon_data.o(.rodata);
        src/data/samus/samus_palette_data.o(.rodata);
        src/data/samus/samus_animation_pointers.o(.rodata);
        src/data/samus/samus_graphics.o(.rodata);

        src/data/sprite_data.o(.rodata);
        src/data/spriteset.o(.rodata);
        src/data/sprites/enemy_drop.o(.rodata);
        src/data/sprites/unused_sprites.o(.rodata);
        src/data/sprites/morph_ball.o(.rodata);
        src/data/sprites/power_grip.o(.rodata);
        src/data/sprites/charge_beam.o(.rodata);
        src/data/sprites/chozo_statue.o(.rodata);
        src/data/sprites/unknown_item_chozo_statue.o(.rodata);
        src/data/sprites/zoomer.o(.rodata);
        src/data/sprites/zeela.o(.rodata);
        src/data/sprites/kraid.o(.rodata);
        src/data/sprites/message_banner.o(.rodata);
        src/data/sprites/ripper.o(.rodata);
        src/data/sprites/ripper2.o(.rodata);
        src/data/sprites/zeb.o(.rodata);
        src/data/sprites/skree.o(.rodata);
        src/data/sprites/reo.o(.rodata);
        src/data/sprites/zipline.o(.rodata);
        src/data/sprites/sova.o(.rodata);
        src/data/sprites/multiviola.o(.rodata);
        src/data/sprites/geruta.o(.rodata);
        src/data/sprites/squeept.o(.rodata);
        src/data/sprites/map_station.o(.rodata);
        src/data/sprites/save_platform.o(.rodata);
        src/data/sprites/dragon.o(.rodata);
        src/data/sprites/deorem.o(.rodata);
        src/data/sprites/dessgeega.o(.rodata);
        src/data/sprites/waver.o(.rodata);
        src/data/sprites/hive.o(.rodata);
        src/data/sprites/imago_larva.o(.rodata);
        src/data/sprites/morph_ball_launcher.o(.rodata);
        src/data/sprites/imago_cocoon.o(.rodata);
        src/data/sprites/elevator_pad.o(.rodata);
        src/data/sprites/space_pirate.o(.rodata);
        src/data/sprites/zipline_generator.o(.rodata);
        src/data/sprites/gamet.o(.rodata);
        src/data/sprites/security_gate.o(.rodata);
        src/data/sprites/zebbo.o(.rodata);
        src/data/sprites/worker_robot.o(.rodata);
        src/data/sprites/parasite.o(.rodata);
        src/data/sprites/piston.o(.rodata);
        src/data/sprites/ridley.o(.rodata);
        src/data/sprites/metroid.o(.rodata);
        src/data/sprites/rinka.o(.rodata);
        src/data/sprites/polyp.o(.rodata);
        src/data/sprites/viola.o(.rodata);
        src/data/sprites/security_laser.o(.rodata);
        src/data/sprites/holtz.o(.rodata);
        src/data/sprites/gekitai_machine.o(.rodata);
        src/data/sprites/ruins_test.o(.rodata);
        src/data/sprites/mella.o(.rodata);
        src/data/sprites/atomic.o(.rodata);
        src/data/sprites/area_banner.o(.rodata);
        src/data/sprites/mother_brain.o(.rodata);
        src/data/sprites/acid_worm.o(.rodata);
        src/data/sprites/sidehopper.o(.rodata);
        src/data/sprites/geron_norfair.o(.rodata);
        src/data/sprites/geega.o(.rodata);
        src/data/sprites/zebetite_and_cannon.o(.rodata);
        src/data/sprites/imago_larva_right_side.o(.rodata);
        src/data/sprites/tangle_vine.o(.rodata);
        src/data/sprites/imago.o(.rodata);
        src/data/sprites/crocomire.o(.rodata);
        src/data/sprites/searchlight_eye.o(.rodata);
        src/data/sprites/geron.o(.rodata);
        src/data/sprites/gunship.o(.rodata);
        src/data/sprites/glass_tube.o(.rodata);
        src/data/sprites/save_platform_chozodia.o(.rodata);
        src/data/sprites/baristute.o(.rodata);
        src/data/sprites/elevator_statue.o(.rodata);
        src/data/sprites/rising_chozo_pillar.o(.rodata);
        src/data/sprites/skultera.o(.rodata);
        src/data/sprites/boss_statues.o(.rodata);
        src/data/sprites/searchlight.o(.rodata);
        src/data/sprites/gadora.o(.rodata);
        src/data/sprites/steam.o(.rodata);
        src/data/sprites/unknown_item_block.o(.rodata);
        src/data/sprites/escape_ship.o(.rodata);
        src/data/sprites/space_pirate_carrying_power_bomb.o(.rodata);
        src/data/sprites/falling_chozo_pillar.o(.rodata);
        src/data/sprites/mecha_ridley.o(.rodata);
        src/data/sprites/escape_gate.o(.rodata);
        src/data/projectile_data.o(.rodata);
        src/data/hud_data.o(.rodata);
        src/data/particle_data.o(.rodata);
        src/data/visual_effects_data.o(.rodata);
        src/data/rooms_data.o(.rodata);
        src/data/empty_datatypes.o(.rodata);
        src/data/clipdata_data.o(.rodata);
        src/data/block_data.o(.rodata);
        src/data/color_fading_data.o(.rodata);
        src/data/haze_data.o(.rodata);
        src/data/animated_graphics_data.o(.rodata);
        src/data/hatch_data.o(.rodata);
        src/data/in_game_cutscene_data.o(.rodata);
        src/data/demo_data.o(.rodata);
        src/data/default_background_data.o(.rodata);
        src/data/clipdata_types_tilemap.o(.rodata);
        src/data/rooms/test_rooms_data.o(.rodata);

        src/data/samus_close_up_data.o(.rodata);
        src/data/cutscenes/cutscenes_data.o(.rodata);
        src/data/cutscenes/kraid_rising_data.o(.rodata);
        src/data/cutscenes/story_text_cutscene_data.o(.rodata);
        src/data/cutscenes/mother_brain_close_up_data.o(.rodata);
        src/data/cutscenes/ridley_in_space_data.o(.rodata);
        src/data/cutscenes/ridley_landing_data.o(.rodata);
        src/data/cutscenes/ridley_spawn_data.o(.rodata);
        src/data/cutscenes/mecha_sees_samus_data.o(.rodata);
        src/data/cutscenes/getting_fully_powered_suit_data.o(.rodata);
        src/data/cutscenes/before_ruins_test_data.o(.rodata);
        src/data/cutscenes/statue_opening_data.o(.rodata);
        src/data/cutscenes/enter_tourian_data.o(.rodata);
        src/data/cutscenes/samus_in_blue_ship_data.o(.rodata);
        src/data/menus/pause_screen_data.o(.rodata);
        src/data/menus/status_screen_data.o(.rodata);
        src/data/menus/pause_screen_sub_menus_data.o(.rodata);
        src/data/menus/pause_screen_map_data.o(.rodata);
        src/data/save_file_data.o(.rodata);

#ifdef DEBUG
        src/data/menus/boot_debug_data.o(.rodata);
#endif

        src/data/menus/erase_sram_data.o(.rodata);
        src/data/text_data.o(.rodata);
        src/data/menus/title_screen_data.o(.rodata);
        src/data/menus/game_over_data.o(.rodata);
        src/data/menus/file_select_data.o(.rodata);

#ifdef REGION_EU
        src/data/menus/language_select_data.o(.rodata);
#endif

        src/data/intro_data.o(.rodata);
        src/data/tourian_escape_data.o(.rodata);
        src/data/fusion_gallery_data.o(.rodata);
        src/data/ending_and_gallery_data.o(.rodata);
        src/data/chozodia_escape_data.o(.rodata);
        src/data/io_transfer_data.o(.rodata);
        src/data/clipdata_types.o(.rodata);
        src/data/tilesets/tilesets_set0.o(.rodata);
        src/data/common_pals.o(.rodata);
        src/data/tilesets/tilesets_set1.o(.rodata);

        src/data/rooms/brinstar/Brinstar_0.o(.rodata);
        src/data/rooms/brinstar/Brinstar_1.o(.rodata);
        src/data/rooms/brinstar/Brinstar_2.o(.rodata);
        src/data/rooms/brinstar/Brinstar_3.o(.rodata);
        src/data/rooms/brinstar/Brinstar_4.o(.rodata);
        src/data/rooms/brinstar/Brinstar_5.o(.rodata);
        src/data/rooms/brinstar/Brinstar_6.o(.rodata);
        src/data/rooms/brinstar/Brinstar_7.o(.rodata);
        src/data/rooms/brinstar/Brinstar_8.o(.rodata);
        src/data/rooms/brinstar/Brinstar_9.o(.rodata);
        src/data/rooms/brinstar/Brinstar_10.o(.rodata);
        src/data/rooms/brinstar/Brinstar_11.o(.rodata);
        src/data/rooms/brinstar/Brinstar_12.o(.rodata);
        src/data/rooms/brinstar/Brinstar_13.o(.rodata);
        src/data/rooms/brinstar/Brinstar_14.o(.rodata);
        src/data/rooms/brinstar/Brinstar_15.o(.rodata);
        src/data/rooms/brinstar/Brinstar_16.o(.rodata);
        src/data/rooms/brinstar/Brinstar_17.o(.rodata);
        src/data/rooms/brinstar/Brinstar_18.o(.rodata);
        src/data/rooms/brinstar/Brinstar_19.o(.rodata);
        src/data/rooms/brinstar/Brinstar_20.o(.rodata);
        src/data/rooms/brinstar/Brinstar_21.o(.rodata);
        src/data/rooms/brinstar/Brinstar_22.o(.rodata);
        src/data/rooms/brinstar/Brinstar_23.o(.rodata);
        src/data/rooms/brinstar/Brinstar_24.o(.rodata);
        src/data/rooms/brinstar/Brinstar_25.o(.rodata);
        src/data/rooms/brinstar/Brinstar_26.o(.rodata);
        src/data/rooms/brinstar/Brinstar_27.o(.rodata);
        src/data/rooms/brinstar/Brinstar_28.o(.rodata);
        src/data/rooms/brinstar/Brinstar_29.o(.rodata);
        src/data/rooms/brinstar/Brinstar_30.o(.rodata);
        src/data/rooms/brinstar/Brinstar_31.o(.rodata);
        src/data/rooms/brinstar/Brinstar_32.o(.rodata);
        src/data/rooms/brinstar/Brinstar_33.o(.rodata);
        src/data/rooms/brinstar/Brinstar_34.o(.rodata);
        src/data/rooms/brinstar/Brinstar_35.o(.rodata);
        src/data/rooms/brinstar/Brinstar_36.o(.rodata);
        src/data/rooms/brinstar/Brinstar_37.o(.rodata);
        src/data/rooms/brinstar/Brinstar_38.o(.rodata);
        src/data/rooms/brinstar/Brinstar_39.o(.rodata);
        src/data/rooms/brinstar/Brinstar_40.o(.rodata);
        src/data/rooms/brinstar/Brinstar_41.o(.rodata);
        src/data/rooms/brinstar/Bg3.o(.rodata);

        src/data/tilesets/tilesets_set2.o(.rodata);

        src/data/rooms/kraid/Kraid_0.o(.rodata);
        src/data/rooms/kraid/Kraid_1.o(.rodata);
        src/data/rooms/kraid/Kraid_2.o(.rodata);
        src/data/rooms/kraid/Kraid_3.o(.rodata);
        src/data/rooms/kraid/Kraid_4.o(.rodata);
        src/data/rooms/kraid/Kraid_5.o(.rodata);
        src/data/rooms/kraid/Kraid_6.o(.rodata);
        src/data/rooms/kraid/Kraid_7.o(.rodata);
        src/data/rooms/kraid/Kraid_8.o(.rodata);
        src/data/rooms/kraid/Kraid_9.o(.rodata);
        src/data/rooms/kraid/Kraid_10.o(.rodata);
        src/data/rooms/kraid/Kraid_11.o(.rodata);
        src/data/rooms/kraid/Kraid_12.o(.rodata);
        src/data/rooms/kraid/Kraid_13.o(.rodata);
        src/data/rooms/kraid/Kraid_14.o(.rodata);
        src/data/rooms/kraid/Kraid_15.o(.rodata);
        src/data/rooms/kraid/Kraid_16.o(.rodata);
        src/data/rooms/kraid/Kraid_17.o(.rodata);
        src/data/rooms/kraid/Kraid_18.o(.rodata);
        src/data/rooms/kraid/Kraid_19.o(.rodata);
        src/data/rooms/kraid/Kraid_20.o(.rodata);
        src/data/rooms/kraid/Kraid_21.o(.rodata);
        src/data/rooms/kraid/Kraid_22.o(.rodata);
        src/data/rooms/kraid/Kraid_23.o(.rodata);
        src/data/rooms/kraid/Kraid_24.o(.rodata);
        src/data/rooms/kraid/Kraid_25.o(.rodata);
        src/data/rooms/kraid/Kraid_26.o(.rodata);
        src/data/rooms/kraid/Kraid_27.o(.rodata);
        src/data/rooms/kraid/Kraid_28.o(.rodata);
        src/data/rooms/kraid/Kraid_29.o(.rodata);
        src/data/rooms/kraid/Kraid_30.o(.rodata);
        src/data/rooms/kraid/Kraid_31.o(.rodata);
        src/data/rooms/kraid/Kraid_32.o(.rodata);
        src/data/rooms/kraid/Kraid_33.o(.rodata);
        src/data/rooms/kraid/Kraid_34.o(.rodata);
        src/data/rooms/kraid/Kraid_35.o(.rodata);
        src/data/rooms/kraid/Kraid_36.o(.rodata);
        src/data/rooms/kraid/Kraid_37.o(.rodata);
        src/data/rooms/kraid/Kraid_38.o(.rodata);
        src/data/rooms/kraid/Kraid_39.o(.rodata);
        src/data/rooms/kraid/Kraid_40.o(.rodata);
        src/data/rooms/kraid/Kraid_41.o(.rodata);
        src/data/rooms/kraid/Bg3.o(.rodata);

        src/data/tilesets/tilesets_set3.o(.rodata);

        src/data/rooms/norfair/Norfair_0.o(.rodata);
        src/data/rooms/norfair/Norfair_1.o(.rodata);
        src/data/rooms/norfair/Norfair_2.o(.rodata);
        src/data/rooms/norfair/Norfair_3.o(.rodata);
        src/data/rooms/norfair/Norfair_4.o(.rodata);
        src/data/rooms/norfair/Norfair_5.o(.rodata);
        src/data/rooms/norfair/Norfair_6.o(.rodata);
        src/data/rooms/norfair/Norfair_7.o(.rodata);
        src/data/rooms/norfair/Norfair_8.o(.rodata);
        src/data/rooms/norfair/Norfair_9.o(.rodata);
        src/data/rooms/norfair/Norfair_10.o(.rodata);
        src/data/rooms/norfair/Norfair_11.o(.rodata);
        src/data/rooms/norfair/Norfair_12.o(.rodata);
        src/data/rooms/norfair/Norfair_13.o(.rodata);
        src/data/rooms/norfair/Norfair_14.o(.rodata);
        src/data/rooms/norfair/Norfair_15.o(.rodata);
        src/data/rooms/norfair/Norfair_16.o(.rodata);
        src/data/rooms/norfair/Norfair_17.o(.rodata);
        src/data/rooms/norfair/Norfair_18.o(.rodata);
        src/data/rooms/norfair/Norfair_19.o(.rodata);
        src/data/rooms/norfair/Norfair_20.o(.rodata);
        src/data/rooms/norfair/Norfair_21.o(.rodata);
        src/data/rooms/norfair/Norfair_22.o(.rodata);
        src/data/rooms/norfair/Norfair_23.o(.rodata);
        src/data/rooms/norfair/Norfair_24.o(.rodata);
        src/data/rooms/norfair/Norfair_25.o(.rodata);
        src/data/rooms/norfair/Norfair_26.o(.rodata);
        src/data/rooms/norfair/Norfair_27.o(.rodata);
        src/data/rooms/norfair/Norfair_28.o(.rodata);
        src/data/rooms/norfair/Norfair_29.o(.rodata);
        src/data/rooms/norfair/Norfair_30.o(.rodata);
        src/data/rooms/norfair/Norfair_31.o(.rodata);
        src/data/rooms/norfair/Norfair_32.o(.rodata);
        src/data/rooms/norfair/Norfair_33.o(.rodata);
        src/data/rooms/norfair/Norfair_34.o(.rodata);
        src/data/rooms/norfair/Norfair_35.o(.rodata);
        src/data/rooms/norfair/Norfair_36.o(.rodata);
        src/data/rooms/norfair/Norfair_37.o(.rodata);
        src/data/rooms/norfair/Norfair_38.o(.rodata);
        src/data/rooms/norfair/Norfair_39.o(.rodata);
        src/data/rooms/norfair/Norfair_40.o(.rodata);
        src/data/rooms/norfair/Norfair_41.o(.rodata);
        src/data/rooms/norfair/Norfair_42.o(.rodata);
        src/data/rooms/norfair/Norfair_43.o(.rodata);
        src/data/rooms/norfair/Norfair_44.o(.rodata);
        src/data/rooms/norfair/Norfair_45.o(.rodata);
        src/data/rooms/norfair/Norfair_46.o(.rodata);
        src/data/rooms/norfair/Norfair_47.o(.rodata);
        src/data/rooms/norfair/Norfair_48.o(.rodata);
        src/data/rooms/norfair/Norfair_49.o(.rodata);
        src/data/rooms/norfair/Norfair_50.o(.rodata);
        src/data/rooms/norfair/Norfair_51.o(.rodata);
        src/data/rooms/norfair/Norfair_52.o(.rodata);
        src/data/rooms/norfair/Norfair_53.o(.rodata);
        src/data/rooms/norfair/Norfair_54.o(.rodata);
        src/data/rooms/norfair/Norfair_55.o(.rodata);
        src/data/rooms/norfair/Norfair_56.o(.rodata);
        src/data/rooms/norfair/Bg3.o(.rodata);

        src/data/tilesets/tilesets_set4.o(.rodata);

        src/data/rooms/ridley/Ridley_0.o(.rodata);
        src/data/rooms/ridley/Ridley_1.o(.rodata);
        src/data/rooms/ridley/Ridley_2.o(.rodata);
        src/data/rooms/ridley/Ridley_3.o(.rodata);
        src/data/rooms/ridley/Ridley_4.o(.rodata);
        src/data/rooms/ridley/Ridley_5.o(.rodata);
        src/data/rooms/ridley/Ridley_6.o(.rodata);
        src/data/rooms/ridley/Ridley_7.o(.rodata);
        src/data/rooms/ridley/Ridley_8.o(.rodata);
        src/data/rooms/ridley/Ridley_9.o(.rodata);
        src/data/rooms/ridley/Ridley_10.o(.rodata);
        src/data/rooms/ridley/Ridley_11.o(.rodata);
        src/data/rooms/ridley/Ridley_12.o(.rodata);
        src/data/rooms/ridley/Ridley_13.o(.rodata);
        src/data/rooms/ridley/Ridley_14.o(.rodata);
        src/data/rooms/ridley/Ridley_15.o(.rodata);
        src/data/rooms/ridley/Ridley_16.o(.rodata);
        src/data/rooms/ridley/Ridley_17.o(.rodata);
        src/data/rooms/ridley/Ridley_18.o(.rodata);
        src/data/rooms/ridley/Ridley_19.o(.rodata);
        src/data/rooms/ridley/Ridley_20.o(.rodata);
        src/data/rooms/ridley/Ridley_21.o(.rodata);
        src/data/rooms/ridley/Ridley_22.o(.rodata);
        src/data/rooms/ridley/Ridley_23.o(.rodata);
        src/data/rooms/ridley/Ridley_24.o(.rodata);
        src/data/rooms/ridley/Ridley_25.o(.rodata);
        src/data/rooms/ridley/Ridley_26.o(.rodata);
        src/data/rooms/ridley/Ridley_27.o(.rodata);
        src/data/rooms/ridley/Ridley_28.o(.rodata);
        src/data/rooms/ridley/Ridley_29.o(.rodata);
        src/data/rooms/ridley/Ridley_30.o(.rodata);
        src/data/rooms/ridley/Ridley_31.o(.rodata);
        src/data/rooms/ridley/Ridley_32.o(.rodata);
        src/data/rooms/ridley/Bg3.o(.rodata);

        src/data/tilesets/tilesets_set5.o(.rodata);

        src/data/rooms/tourian/Tourian_0.o(.rodata);
        src/data/rooms/tourian/Tourian_1.o(.rodata);
        src/data/rooms/tourian/Tourian_2.o(.rodata);
        src/data/rooms/tourian/Tourian_3.o(.rodata);
        src/data/rooms/tourian/Tourian_4.o(.rodata);
        src/data/rooms/tourian/Tourian_5.o(.rodata);
        src/data/rooms/tourian/Tourian_6.o(.rodata);
        src/data/rooms/tourian/Tourian_7.o(.rodata);
        src/data/rooms/tourian/Tourian_8.o(.rodata);
        src/data/rooms/tourian/Tourian_9.o(.rodata);
        src/data/rooms/tourian/Tourian_10.o(.rodata);
        src/data/rooms/tourian/Tourian_11.o(.rodata);
        src/data/rooms/tourian/Tourian_12.o(.rodata);
        src/data/rooms/tourian/Tourian_13.o(.rodata);
        src/data/rooms/tourian/Tourian_14.o(.rodata);
        src/data/rooms/tourian/Tourian_15.o(.rodata);
        src/data/rooms/tourian/Tourian_16.o(.rodata);
        src/data/rooms/tourian/Tourian_17.o(.rodata);
        src/data/rooms/tourian/Tourian_18.o(.rodata);
        src/data/rooms/tourian/Tourian_19.o(.rodata);
        src/data/rooms/tourian/Bg3.o(.rodata);

        src/data/tilesets/tilesets_set6.o(.rodata);

        src/data/rooms/crateria/Crateria_0.o(.rodata);
        src/data/rooms/crateria/Crateria_1.o(.rodata);
        src/data/rooms/crateria/Crateria_2.o(.rodata);
        src/data/rooms/crateria/Crateria_3.o(.rodata);
        src/data/rooms/crateria/Crateria_4.o(.rodata);
        src/data/rooms/crateria/Crateria_5.o(.rodata);
        src/data/rooms/crateria/Crateria_6.o(.rodata);
        src/data/rooms/crateria/Crateria_7.o(.rodata);
        src/data/rooms/crateria/Crateria_8.o(.rodata);
        src/data/rooms/crateria/Crateria_9.o(.rodata);
        src/data/rooms/crateria/Crateria_10.o(.rodata);
        src/data/rooms/crateria/Crateria_11.o(.rodata);
        src/data/rooms/crateria/Crateria_12.o(.rodata);
        src/data/rooms/crateria/Crateria_13.o(.rodata);
        src/data/rooms/crateria/Crateria_14.o(.rodata);
        src/data/rooms/crateria/Crateria_15.o(.rodata);
        src/data/rooms/crateria/Crateria_16.o(.rodata);
        src/data/rooms/crateria/Crateria_17.o(.rodata);
        src/data/rooms/crateria/Crateria_18.o(.rodata);
        src/data/rooms/crateria/Crateria_19.o(.rodata);
        src/data/rooms/crateria/Crateria_20.o(.rodata);
        src/data/rooms/crateria/Crateria_21.o(.rodata);
        src/data/rooms/crateria/Bg3.o(.rodata);

        src/data/tilesets/tilesets_set7.o(.rodata);

        src/data/rooms/chozodia/Chozodia_0.o(.rodata);
        src/data/rooms/chozodia/Chozodia_1.o(.rodata);
        src/data/rooms/chozodia/Chozodia_2.o(.rodata);
        src/data/rooms/chozodia/Chozodia_3.o(.rodata);
        src/data/rooms/chozodia/Chozodia_4.o(.rodata);
        src/data/rooms/chozodia/Chozodia_5.o(.rodata);
        src/data/rooms/chozodia/Chozodia_6.o(.rodata);
        src/data/rooms/chozodia/Chozodia_7.o(.rodata);
        src/data/rooms/chozodia/Chozodia_8.o(.rodata);
        src/data/rooms/chozodia/Chozodia_9.o(.rodata);
        src/data/rooms/chozodia/Chozodia_10.o(.rodata);
        src/data/rooms/chozodia/Chozodia_11.o(.rodata);
        src/data/rooms/chozodia/Chozodia_12.o(.rodata);
        src/data/rooms/chozodia/Chozodia_13.o(.rodata);
        src/data/rooms/chozodia/Chozodia_14.o(.rodata);
        src/data/rooms/chozodia/Chozodia_15.o(.rodata);
        src/data/rooms/chozodia/Chozodia_16.o(.rodata);
        src/data/rooms/chozodia/Chozodia_17.o(.rodata);
        src/data/rooms/chozodia/Chozodia_18.o(.rodata);
        src/data/rooms/chozodia/Chozodia_19.o(.rodata);
        src/data/rooms/chozodia/Chozodia_20.o(.rodata);
        src/data/rooms/chozodia/Chozodia_21.o(.rodata);
        src/data/rooms/chozodia/Chozodia_22.o(.rodata);
        src/data/rooms/chozodia/Chozodia_23.o(.rodata);
        src/data/rooms/chozodia/Chozodia_24.o(.rodata);
        src/data/rooms/chozodia/Chozodia_25.o(.rodata);
        src/data/rooms/chozodia/Chozodia_26.o(.rodata);
        src/data/rooms/chozodia/Chozodia_27.o(.rodata);
        src/data/rooms/chozodia/Chozodia_28.o(.rodata);
        src/data/rooms/chozodia/Chozodia_29.o(.rodata);
        src/data/rooms/chozodia/Chozodia_30.o(.rodata);
        src/data/rooms/chozodia/Chozodia_31.o(.rodata);
        src/data/rooms/chozodia/Chozodia_32.o(.rodata);
        src/data/rooms/chozodia/Chozodia_33.o(.rodata);
        src/data/rooms/chozodia/Chozodia_34.o(.rodata);
        src/data/rooms/chozodia/Chozodia_35.o(.rodata);
        src/data/rooms/chozodia/Chozodia_36.o(.rodata);
        src/data/rooms/chozodia/Chozodia_37.o(.rodata);
        src/data/rooms/chozodia/Chozodia_38.o(.rodata);
        src/data/rooms/chozodia/Chozodia_39.o(.rodata);
        src/data/rooms/chozodia/Chozodia_40.o(.rodata);
        src/data/rooms/chozodia/Chozodia_41.o(.rodata);
        src/data/rooms/chozodia/Chozodia_42.o(.rodata);
        src/data/rooms/chozodia/Chozodia_43.o(.rodata);
        src/data/rooms/chozodia/Chozodia_44.o(.rodata);
        src/data/rooms/chozodia/Chozodia_45.o(.rodata);
        src/data/rooms/chozodia/Chozodia_46.o(.rodata);
        src/data/rooms/chozodia/Chozodia_47.o(.rodata);
        src/data/rooms/chozodia/Chozodia_48.o(.rodata);
        src/data/rooms/chozodia/Chozodia_49.o(.rodata);
        src/data/rooms/chozodia/Chozodia_50.o(.rodata);
        src/data/rooms/chozodia/Chozodia_51.o(.rodata);
        src/data/rooms/chozodia/Chozodia_52.o(.rodata);
        src/data/rooms/chozodia/Chozodia_53.o(.rodata);
        src/data/rooms/chozodia/Chozodia_54.o(.rodata);
        src/data/rooms/chozodia/Chozodia_55.o(.rodata);
        src/data/rooms/chozodia/Chozodia_56.o(.rodata);
        src/data/rooms/chozodia/Chozodia_57.o(.rodata);
        src/data/rooms/chozodia/Chozodia_58.o(.rodata);
        src/data/rooms/chozodia/Chozodia_59.o(.rodata);
        src/data/rooms/chozodia/Chozodia_60.o(.rodata);
        src/data/rooms/chozodia/Chozodia_61.o(.rodata);
        src/data/rooms/chozodia/Chozodia_62.o(.rodata);
        src/data/rooms/chozodia/Chozodia_63.o(.rodata);
        src/data/rooms/chozodia/Chozodia_64.o(.rodata);
        src/data/rooms/chozodia/Chozodia_65.o(.rodata);
        src/data/rooms/chozodia/Chozodia_66.o(.rodata);
        src/data/rooms/chozodia/Chozodia_67.o(.rodata);
        src/data/rooms/chozodia/Chozodia_68.o(.rodata);
        src/data/rooms/chozodia/Chozodia_69.o(.rodata);
        src/data/rooms/chozodia/Chozodia_70.o(.rodata);
        src/data/rooms/chozodia/Chozodia_71.o(.rodata);
        src/data/rooms/chozodia/Chozodia_72.o(.rodata);
        src/data/rooms/chozodia/Chozodia_73.o(.rodata);
        src/data/rooms/chozodia/Chozodia_74.o(.rodata);
        src/data/rooms/chozodia/Chozodia_75.o(.rodata);
        src/data/rooms/chozodia/Chozodia_76.o(.rodata);
        src/data/rooms/chozodia/Chozodia_77.o(.rodata);
        src/data/rooms/chozodia/Chozodia_78.o(.rodata);
        src/data/rooms/chozodia/Chozodia_79.o(.rodata);
        src/data/rooms/chozodia/Chozodia_80.o(.rodata);
        src/data/rooms/chozodia/Chozodia_81.o(.rodata);
        src/data/rooms/chozodia/Chozodia_82.o(.rodata);
        src/data/rooms/chozodia/Chozodia_83.o(.rodata);
        src/data/rooms/chozodia/Chozodia_84.o(.rodata);
        src/data/rooms/chozodia/Chozodia_85.o(.rodata);
        src/data/rooms/chozodia/Chozodia_86.o(.rodata);
        src/data/rooms/chozodia/Chozodia_87.o(.rodata);
        src/data/rooms/chozodia/Chozodia_88.o(.rodata);
        src/data/rooms/chozodia/Chozodia_89.o(.rodata);
        src/data/rooms/chozodia/Chozodia_90.o(.rodata);
        src/data/rooms/chozodia/Chozodia_91.o(.rodata);
        src/data/rooms/chozodia/Chozodia_92.o(.rodata);
        src/data/rooms/chozodia/Chozodia_93.o(.rodata);
        src/data/rooms/chozodia/Chozodia_94.o(.rodata);
        src/data/rooms/chozodia/Chozodia_95.o(.rodata);
        src/data/rooms/chozodia/Chozodia_96.o(.rodata);
        src/data/rooms/chozodia/Chozodia_97.o(.rodata);
        src/data/rooms/chozodia/Chozodia_98.o(.rodata);
        src/data/rooms/chozodia/Bg3.o(.rodata);

        src/data/animated_tiles_data.o(.rodata);
        src/data/shortcut_pointers.o(.rodata);
        src/data/cable_link_data.o(.rodata);
        sTransferRom_After = .;
    } >rom

    .data (READONLY) : ALIGN(2) {
        src/samus.o(.data);
        src/sprite.o(.data);

        src/sprites_AI/chozo_statue.o(.data);
        src/sprites_AI/unknown_item_chozo_statue.o(.data);
        src/sprites_AI/kraid.o(.data);
        src/sprites_AI/imago_larva.o(.data);
        src/sprites_AI/imago_cocoon.o(.data);
        src/sprites_AI/ridley.o(.data);
        src/sprites_AI/atomic.o(.data);
        src/sprites_AI/mother_brain.o(.data);
        src/sprites_AI/tangle_vine.o(.data);
        src/sprites_AI/imago.o(.data);
        src/sprites_AI/crocomire.o(.data);
        src/sprites_AI/mecha_ridley.o(.data);

        src/projectile_util.o(.data);
        src/particle.o(.data);
        src/room.o(.data);
        src/scroll.o(.data);
        src/block.o(.data);
        src/color_fading.o(.data);
        src/haze.o(.data);
        src/animated_graphics.o(.data);
        src/connection.o(.data);
        src/demo.o(.data);

        src/cutscenes/cutscene_utils.o(.data);
        src/cutscenes/kraid_rising.o(.data);
        src/cutscenes/story_text_cutscene.o(.data);
        src/cutscenes/mother_brain_close_up.o(.data);
        src/cutscenes/ridley_in_space.o(.data);
        src/cutscenes/ridley_landing.o(.data);
        src/cutscenes/ridley_spawn.o(.data);
        src/cutscenes/mecha_sees_samus.o(.data);
        src/cutscenes/getting_fully_powered_suit.o(.data);
        src/cutscenes/before_ruins_test.o(.data);
        src/cutscenes/statue_opening.o(.data);
        src/cutscenes/enter_tourian.o(.data);
        src/cutscenes/samus_in_blue_ship.o(.data);

        src/menus/pause_screen.o(.data);
        src/minimap.o(.data);
        src/menus/pause_screen_map.o(.data);
        src/text.o(.data);
        src/menus/status_screen.o(.data);
        src/menus/pause_screen_sub_menus.o(.data);
        src/save_file.o(.data);

#ifdef DEBUG
        src/menus/boot_debug.o(.data);
#endif

        src/menus/erase_sram.o(.data);
        src/data/text_data.o(.data);
        src/menus/title_screen.o(.data);
        src/menus/game_over.o(.data);
        src/menus/file_select.o(.data);

        src/time_attack.o(.data);
        src/intro.o(.data);
        src/tourian_escape.o(.data);
        src/ending_and_gallery.o(.data);
        src/chozodia_escape.o(.data);
        src/cable_link.o(.data);
    } >rom

    nes_metroid_data __nes_metroid_load_address : ALIGN(2) {
        src/data/nes_metroid.o(.rodata);
    } >rom

    /* DWARF debug sections.
       Symbols in the DWARF debugging sections are relative to the beginning
       of the section so we begin them at 0.  */

    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }

    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }

    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }

    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
