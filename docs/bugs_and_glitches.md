# Bugs and Glitches

These are known bugs and glitches in the game: code that clearly does not work as intended or was designed poorly. Some of them cause visible gameplay issues, while others are harmless. The bugs listed here can be fixed by compiling with the `BUGFIX` flag (bugs in the TODO section don't have a fix implemented yet). 

## Contents

- [Contents](#contents)
- [Bugs](#bugs)
  - ["Ground" Dessgeegas always set the "Dessgeega long beam killed" event and unlock doors](#ground-dessgeegas-always-set-the-dessgeega-long-beam-killed-event-and-unlock-doors)
  - [Mother Brain block does not spawn when there are too many sprites](#mother-brain-block-does-not-spawn-when-there-are-too-many-sprites)
  - [Samus slow physics aren't properly applied when grabbed by a metroid in a liquid](#samus-slow-physics-arent-properly-applied-when-grabbed-by-a-metroid-in-a-liquid)
  - [Mecha Ridley's missiles can be kept alive after it dies, which get corrupted graphics](#mecha-ridleys-missiles-can-be-kept-alive-after-it-dies-which-get-corrupted-graphics)
  - [Collecting an item while a power bomb is active allows Samus to move early](#collecting-an-item-while-a-power-bomb-is-active-allows-samus-to-move-early)
  - [Killing Imago with pseudo screw attack softlocks the game](#killing-imago-with-pseudo-screw-attack-softlocks-the-game)
  - [Turning can trigger the fully powered suit cutscene without getting locked in place](#turning-can-trigger-the-fully-powered-suit-cutscene-without-getting-locked-in-place)
  - [Dying during a door transition (from lava/acid) puts Samus in the no-clip state](#dying-during-a-door-transition-from-lavaacid-puts-samus-in-the-no-clip-state)
  - [Missiles can be highlighted and toggled while dying](#missiles-can-be-highlighted-and-toggled-while-dying)
  - [Sidehoppers and Dessgeegas don't initialize the delay for their first jump](#sidehoppers-and-dessgeegas-dont-initialize-the-delay-for-their-first-jump)
  - ["Stop enemy" clipdata prevents bomb jumping](#stop-enemy-clipdata-prevents-bomb-jumping)
  - [Samus can get refilled while collecting a Chozo statue item](#samus-can-get-refilled-while-collecting-a-chozo-statue-item)
  - [Samus can clip into blocks on the right when uncrouching next to a frozen enemy](#samus-can-clip-into-blocks-on-the-right-when-uncrouching-next-to-a-frozen-enemy)
  - [Ridley updates sub sprite data even if he's dead](#ridley-updates-sub-sprite-data-even-if-hes-dead)
  - [The first frame of power bomb explosions has a visual bug](#the-first-frame-of-power-bomb-explosions-has-a-visual-bug)
  - [The fully powered suit cutscene fades to black after fading to white](#the-fully-powered-suit-cutscene-fades-to-black-after-fading-to-white)
- [Oversights and Design Flaws](#oversights-and-design-flaws)
  - [Floating point math is used when fixed point could have been used](#floating-point-math-is-used-when-fixed-point-could-have-been-used)
  - [`ClipdataConvertToCollision` is copied to RAM but still runs in ROM](#clipdataconverttocollision-is-copied-to-ram-but-still-runs-in-rom)
  - [Upgrading suit cutscene code is still called after the cutscene ends](#upgrading-suit-cutscene-code-is-still-called-after-the-cutscene-ends)
  - [Game always boots in mono even if stereo is enabled in settings](#game-always-boots-in-mono-even-if-stereo-is-enabled-in-settings)
- [Uninitialized Variables](#uninitialized-variables)
- [TODO](#todo)
  - [Bugs](#bugs-1)
  - [Oversights and Design Flaws](#oversights-and-design-flaws-1)


## Bugs

### "Ground" Dessgeegas always set the "Dessgeega long beam killed" event and unlock doors

**Fix:** Edit `DessgeegaDeath` in [dessgeega.c](../src/sprites_AI/dessgeega.c) to check for the sprite id to run the event and door logic.

```diff
+ if (gCurrentSprite.spriteId == PSPRITE_DESSGEEGA_AFTER_LONG_BEAM)
+ {
      // Set event every time a ground dessgeega is killed instead of checking for the sprite ID ?
      EventFunction(EVENT_ACTION_SETTING, EVENT_LONG_BEAM_DESSGEEGA_KILLED);
      // Unlock doors
      gDoorUnlockTimer = -ONE_THIRD_SECOND;
+ }
```

### Mother Brain block does not spawn when there are too many sprites

Whenever there are too many (24) active sprites in the Mother Brain room, the block that is meant to prevent Samus from leaving the Mother Brain fight fails to spawn. This happens because the block is its own independent sprite, and needs an additional free sprite slot to spawn. The code tries to spawn the block only once, and does not check if it was successfully spawned. The fight continues regardless, and the next Mother Brain pose is set.

**Fix:** Edit `MotherBrainSpawnBlock` in [mother_brain.c](../src/sprites_AI/mother_brain.c) to check if the block sprite was spawned successfully before changing to the next Mother Brain sprite pose. The `SpriteSpawnSecondary()` function returns `0xFF` if it failed to spawn the sprite. By not changing the pose, the game will keep trying to spawn the block until it succeeds. This usually happens just a few frames after the first attempt, so no side effects are noticeable in the Mother Brain fight.

```diff
- SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0, SPRITE_GFX_SLOT_SPECIAL,
-      gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
+ u8 blockSlot = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0, SPRITE_GFX_SLOT_SPECIAL,
+      gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
+ if (blockSlot != UCHAR_MAX)
+ {
      gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1;
      gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
+ }
```

### Samus slow physics aren't properly applied when grabbed by a metroid in a liquid

The code skips the check for the "grabbed by Metroid" flag to apply the slowed physics if Samus is currently in a liquid.
So when Samus is in a liquid that doesn't slow her, she also won't be slowed even if she's grabbed by a Metroid.

**Fix:** Edit `SamusUpdatePhysics` in [samus.c](../src/samus.c) and simply remove the break in the cases for the liquid check.

```diff
  case HAZARD_TYPE_WATER:
  case HAZARD_TYPE_STRONG_LAVA:
  case HAZARD_TYPE_WEAK_LAVA:
  case HAZARD_TYPE_ACID:
      // In liquid, check has gravity to see if slowed
      if (!(pEquipment->suitMiscActivation & SMF_GRAVITY_SUIT))
          slowed++;
-     break;
  
  default:
      // Check grabbed by metroid
      if (gEquipment.grabbedByMetroid)
          slowed++;
```

### Mecha Ridley's missiles can be kept alive after it dies, which get corrupted graphics

If there's a missile on screen when Mecha Ridley dies, you can jump in circles and keep the missile alive until the message box spawns, which will overwrite the missile's graphics. There's another issue where any fireballs or missiles won't animate after Mecha Ridley dies.

**Fix:** Both issues can be avoided by destroying any remaining missiles or fireballs when Mecha Ridley dies. Add the following code to the end of `MechaRidleyDyingInit` in [mecha_ridley.c](../src/sprites_AI/mecha_ridley.c).

```diff
+ // Destroy any remaining missiles or fireballs
+ for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
+ {
+     if (!(pSprite->status & SPRITE_STATUS_EXISTS))
+         continue;
+ 
+     if (!(pSprite->properties & SP_SECONDARY_SPRITE))
+         continue;
+ 
+     if (pSprite->spriteId == SSPRITE_MECHA_RIDLEY_MISSILE || pSprite->spriteId == SSPRITE_MECHA_RIDLEY_FIREBALL)
+         pSprite->pose = 0x44;
+ }
```

### Collecting an item while a power bomb is active allows Samus to move early

When the message banner for a new item closes, it sets `gPreventMovementTimer` to 0 and tries to open the status screen. However, if a power bomb is active, the status screen won't open because the game cannot be paused while a power bomb is active. This allows Samus to move for a short amount of time before the status screen opens.

**Fix:** Edit `MessageBannerStatic` in [message_banner.c](../src/sprites_AI/message_banner.c) to check if a power bomb is active before setting the pose to remove the banner.

```diff
  // Check if should remove (input or demo active, ignore for save prompt)
  if (message != MESSAGE_SAVE_PROMPT &&
      (gButtonInput & (KEY_A | KEY_B | KEY_ALL_DIRECTIONS) || gDemoState != DEMO_STATE_NONE))
  {
+     // If the banner is for a new item, only remove the banner if no power bomb is active
+     if (!gCurrentSprite.MESSAGE_BANNER_NEW_ITEM ||
+         (!gCurrentPowerBomb.animationState && !gCurrentPowerBomb.powerBombPlaced))
+     {
          gCurrentSprite.pose = MESSAGE_BANNER_POSE_REMOVAL_INIT;
+     }
  }
```

### Killing Imago with pseudo screw attack softlocks the game

When a normal (non-boss) enemy is killed, its AI code usually has a default case for the pose that calls `SpriteUtilSpriteDeath`. This handles being killed via various methods, such as shinespark or pseudo screw attack. Imago can be damaged by pseudo screw attack, but its AI code doesn't have a default case or a case for pseudo screw attack. This will cause the game to softlock if the final hit is done using pseudo screw attack.

**Fix:** Edit `Imago` in [imago.c](../src/sprites_AI/imago.c) to remove the `IMAGO_POSE_DYING_INIT` case and add a `default` case at the end that calls `ImagoDyingInit`.

```diff
- case IMAGO_POSE_DYING_INIT:
-     ImagoDyingInit();
-     break;

  ...

+ default:
+     ImagoDyingInit();
+     break;
```

### Turning can trigger the fully powered suit cutscene without getting locked in place

After the Ruins Test fight, the game tries to lock you in place in the center of the room. If you turn in the opposite direction while Samus is turning toward the background, the timer for the cutscene will be triggered but you can move Samus freely before it starts. This is because the game sets the "running" pose if the opposite direction is pressed while Samus is turning to face the background. Normally, the "facing the background" pose should be set.

**Fix:** Edit `SamusTurningFromFacingTheBackgroundGfx` in [samus.c](../src/samus.c) to remove the check for the opposite direction being pressed.

```diff
- // It's unclear what the purpose of this code is. If the opposite direction is held when Samus
- // finishes turning, she will run in the current direction for one frame then turn toward the held
- // direction. This can cause a bug after the Ruins Test fight (see docs/bugs_and_glitches.md).
- if (gButtonInput & OPPOSITE_DIRECTION(pData->direction))
-     return SPOSE_RUNNING;
-
  if (pData->lastWallTouchedMidAir != 0)
      return SPOSE_FACING_THE_BACKGROUND_SUITLESS;
  
  if (gEquipment.suitType == SUIT_SUITLESS)
      return SPOSE_UNCROUCHING_SUITLESS;

  return SPOSE_STANDING;
```

### Dying during a door transition (from lava/acid) puts Samus in the no-clip state

During a door transition, the game calls various "update" routines for one frame in order to initialize data, such as Samus and sprites. When entering a door transition while submerged in lava or acid, it's possible for Samus to take damage during that one frame and die. This sets `gSubGameMode1` to `SUB_GAME_MODE_DYING`, which then gets incremented by one. This is supposed to change the mode from 0 to 1 (`SUB_GAME_MODE_DOOR_TRANSITION`), but instead changes it from 5 to 6 (`SUB_GAME_MODE_NO_CLIP`). This was fixed in the European release.

**Fix:** Edit `SamusExecutePoseMainLoop` in [samus.c](../src/samus.c) to only check for hazard damage if `gSubGameMode1` isn't 0.

```diff
+ if (gSubGameMode1 != 0)
+ {
      // Update hazard damage
      if (SamusTakeHazardDamage(pData, pEquipment, pHazard))
      {
          // Getting knocked back or died, abort
          return SPOSE_HURT_REQUEST;
      }
+ }
```

### Missiles can be highlighted and toggled while dying

During Samus's death animation, missiles can be highlighted and super missiles can be toggled. Even though the HUD isn't displayed, the sound for each will still play. This was fixed in the European release.

**Fix:** Edit `SamusExecutePoseMainLoop` in [samus.c](../src/samus.c) to check if Samus is dying before updating the highlighted weapon.

```diff
  // Update weapon highlight
  if (pEquipment->suitType != SUIT_SUITLESS)
  {
+     if (pData->pose != SPOSE_DYING)
+     {
          SamusSetHighlightedWeapon(pData, pWeapon, pEquipment);
+     }
  }
```

### Sidehoppers and Dessgeegas don't initialize the delay for their first jump

Sidehoppers and Dessgeegas use the `work1` variable to store the delay before jumping. However, this value isn't initialized when they spawn, so `work1` could potentially contain any value that was set by a previous sprite. Normally this is a value between 0-3, but if it's higher, it means their first jump won't happen for an abnormally long amount of time. This bug also occurs in Fusion.

**Fix:** Edit `SidehopperInit` in [sidehopper.c](../src/sprites_AI/sidehopper.c) and `DessgeegaInit` in [dessgeega.c](../src/sprites_AI/dessgeega.c) to initialize `work1`.

```diff
  gCurrentSprite.work0 = 0;
+ gCurrentSprite.work1 = MOD_AND(gSpriteRng, 4);
  gCurrentSprite.pose = SIDEHOPPER_POSE_IDLE;
```

```diff
  gCurrentSprite.work0 = 0;
+ gCurrentSprite.work1 = MOD_AND(gSpriteRng, 4);
```

### "Stop enemy" clipdata prevents bomb jumping

The game checks for solid blocks above and below Samus to see if you can bomb jump. However, the bomb jump code calls `ClipdataProcess`, which sets the collision `actorType` to `CLIPDATA_ACTOR_SPRITE`. This means any "stop enemy" blocks will be considered solid, which can prevent bomb jumping. This bug also occurs in Fusion.

**Fix:** Edit `ProjectileCheckSamusBombBounce` in [projectile.c](../src/projectile.c) to call `ClipdataProcessForSamus` instead of `ClipdataProcess`.

```diff
  // Check block below and block above Samus
- if (!(ClipdataProcess(samusY + HALF_BLOCK_SIZE, samusX) & CLIPDATA_TYPE_SOLID_FLAG) ||
-     !(ClipdataProcess(samusY - (BLOCK_SIZE + HALF_BLOCK_SIZE), samusX) & CLIPDATA_TYPE_SOLID_FLAG))
+ if (!(ClipdataProcessForSamus(samusY + HALF_BLOCK_SIZE, samusX) & CLIPDATA_TYPE_SOLID_FLAG) ||
+     !(ClipdataProcessForSamus(samusY - (BLOCK_SIZE + HALF_BLOCK_SIZE), samusX) & CLIPDATA_TYPE_SOLID_FLAG))
```

### Samus can get refilled while collecting a Chozo statue item

By falling into a Chozo statue item and opening the orb as late as possible, you can reach the hand before Samus is stopped to collect the item. If you fall while morphed or morph on the last possible frame, Samus will be refilled and collect the item at the same time. This happens because the Chozo statue returns to the idle pose once the message box is open, which checks if Samus is in position to get refilled.

**Fix:** Edit `ChozoStatuePartArmCheckGrabSamusRefill` in [chozo_statue.c](../src/sprites_AI/chozo_statue.c) and `UnknownItemChozoStatuePartArmCheckGrabSamusRefill` in [unknown_item_chozo_statue.c](../src/sprites_AI/unknown_item_chozo_statue.c) to check if Samus's movement is prevented before setting the "grabbed" pose.

```diff
  if (gSamusData.pose == SPOSE_MORPH_BALL)
  {
+     if (gPreventMovementTimer == 0)
+     {
          // Set grabbed
          SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
          isGrabbed++;
+     }
  }
```

### Samus can clip into blocks on the right when uncrouching next to a frozen enemy

If Samus is up against a wall on the right and an enemy is frozen up against Samus on the left, uncrouching will push Samus one block to the right, clipping into the wall. When Samus is up against the right side of a solid sprite, she's moved 1 unit to the right, even if she's up against a wall. When Samus uncrouches, the game checks if Samus is slightly under a block in order to push her out to be flush with the block (this also happens when Samus unmorphs). However, the wrong hitbox side is used when collision is detected on the right side. This was likely missed because there aren't any normal situations where Samus can be crouched directly under a block.

**Fix:** Edit `SamusCrouching` and `SamusTurningAroundAndCrouching` in [samus.c](../src/samus.c) to fix which hitbox value is used.

```diff
  // Smooth clamp the X position
  if (collision == SAMUS_COLLISION_DETECTION_LEFT_MOST)
  {
      xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) -
          sSamusBlockHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_BLOCK_HITBOX_LEFT];
  }
  else if (collision == SAMUS_COLLISION_DETECTION_RIGHT_MOST)
  {
-     // BUG: Should use SAMUS_BLOCK_HITBOX_RIGHT, not SAMUS_BLOCK_HITBOX_LEFT
-     xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) -
-         sSamusBlockHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_BLOCK_HITBOX_LEFT] + SUB_PIXEL_POSITION_FLAG;
+     xPosition = (pData->xPosition & BLOCK_POSITION_FLAG) -
+         sSamusBlockHitboxData[SAMUS_HITBOX_TYPE_STANDING][SAMUS_BLOCK_HITBOX_RIGHT] + SUB_PIXEL_POSITION_FLAG;
  }
```

### Ridley updates sub sprite data even if he's dead

Ridley constantly updates sub sprite data at the end of its main function. However, it's possible for the sub sprite data to be uninitialized at this point if Ridley is killed during initialization (Samus doesn't have gravity suit, or Ridley has already been killed). As such, sub sprite data is updated using invalid data (either an old pointer or a null pointer).

**Fix:** Edit `Ridley` in [ridley.c](../src/sprites_AI/ridley.c) to check if Ridley is still alive.

```diff
+ if (gCurrentSprite.status & SPRITE_STATUS_EXISTS)
+ {
        SpriteUtilUpdateSubSprite1Anim();
        RidleySyncSubSprites();
+ }
```

### The first frame of power bomb explosions has a visual bug

On the first frame of a power bomb explosion, the background becomes black (it should be white) and the top of the screen becomes white (which covers the HUD). This was fixed in the European release. The same issue occurs in Fusion, but without the white bar at the top of the screen.

**Fix:** Edit `HazeSetupCode` in [haze.c](../src/haze.c) to set `COLOR_DATA_BG_EWRAM` to `COLOR_WHITE`.

```diff
  PowerBombYellowTint(0);

+ WRITE_16(COLOR_DATA_BG_EWRAM, COLOR_WHITE);

  if (gIoRegistersBackup.Dispcnt_NonGameplay & DCNT_BG0 && gCurrentRoomEntry.bg0Prop != BG_PROP_DISABLE_TRANSPARENCY)
      gWrittenToDispcnt = READ_16(REG_DISPCNT) ^ DCNT_BG0;

  gBackdropColor = COLOR_WHITE;
```

### The fully powered suit cutscene fades to black after fading to white

At the start of the fully powered suit cutscene (after Samus is locked in place), the screen fades to white. Right before the image of suitless Samus is shown, the screen becomes black. Since the image of Samus is relatively bright, this creates an unnecessary flash between dark and light.

**Fix:** Edit `GettingFullyPoweredSuitInit` in [getting_fully_powered_suit.c](../src/cutscenes/getting_fully_powered_suit.c) to call `CutsceneFadeScreenToWhite` instead of `CutsceneFadeScreenToBlack`.

```diff
- CutsceneFadeScreenToBlack();
+ CutsceneFadeScreenToWhite();

  // Load palette, in both background and object
  DmaTransfer(3, sGettingFullyPoweredSuitPal, PALRAM_BASE, 11 * PAL_ROW_SIZE, 16);
  DmaTransfer(3, PALRAM_BASE, PALRAM_OBJ, PAL_SIZE, 32);
  SET_BACKDROP_COLOR(COLOR_BLACK);
```


## Oversights and Design Flaws

### Floating point math is used when fixed point could have been used

Floating point math is used in a few instances even when the result is assigned to or compared with an integer. Fixed point math is much faster and nearly just as accurate.

**Fix:** Call `FixedMultiplication` and convert the fractional part to [Q8.8 format](https://en.wikipedia.org/wiki/Q_(number_format)).

`PowerBombExplosion`:
```diff
  verticalAxis = gCurrentPowerBomb.semiMinorAxis * 4;
  horizontalAxis = gCurrentPowerBomb.semiMinorAxis * 8;
+ verticalAxis = FixedMultiplication(verticalAxis, Q_8_8(0.95));
+ horizontalAxis = FixedMultiplication(horizontalAxis, Q_8_8(0.95));
- verticalAxis *= 0.95;
- horizontalAxis *= 0.95;
```
Could also do `verticalAxis * 19 / 20`

`ImagoCocoonSporeMove`:
```diff
  case IMAGO_COCOON_SPORE_PART_DIAG_RIGHT_UP:
+     movement = FixedMultiplication(movement, Q_8_8(0.8));
-     movement *= 0.8; // 4 * 0.8 = 3.2
      gCurrentSprite.yPosition -= movement;
      gCurrentSprite.xPosition += movement;
      break;
```
Could also do `movement * 4 / 5`

`RidleyLandingShipLanding`:
```diff
+ if (movement >= 2848 - FixedMultiplication(sRidleyLandingScrollingInfo[1].length, Q_8_8(2.f / 3)))
- if (movement >= 2848 - sRidleyLandingScrollingInfo[1].length / 1.5)
  {
      CUTSCENE_DATA.dispcnt |= sRidleyLandingPageData[2].bg;
      CutsceneStartBackgroundScrolling(sRidleyLandingScrollingInfo[1], sRidleyLandingPageData[2].bg);
  }
```
Could also do `sRidleyLandingScrollingInfo[1].length * 2 / 3`

### `ClipdataConvertToCollision` is copied to RAM but still runs in ROM

`ClipdataConvertToCollision` is copied to RAM, presumably for performance reasons, because it is often called many times per frame and code runs faster in RAM. However, the switch statement gets compiled as a jump table, which ends up jumping to the code in ROM.

**Fix:** Convert the switch statement to a series of if statements. Order them such that common block types (like solid and air) are checked first.

See `ClipdataConvertToCollision` in [clipdata.c](../src/clipdata.c)

### Upgrading suit cutscene code is still called after the cutscene ends

The last cutscene stage for upgrading your suit (obtaining Varia or the fully powered suit) returns `IGC_RESULT_NEXT_STAGE` when it should return `IGC_RESULT_STOP`. This sets the stage to 20, which has no case for it and will just return `IGC_RESULT_NONE`. As a result, the in-game cutscene code will be called until a new room is loaded. This was fixed in the European release.

**Fix:** Edit `InGameCutsceneUpgradingSuit` in [in_game_cutscene.c](../src/in_game_cutscene.c) to return `IGC_RESULT_STOP` instead of `IGC_RESULT_NEXT_STAGE`.

```diff
  case 19:
      // Flag cutscene has ended
      if (gCurrentItemBeingAcquired == ITEM_ACQUISITION_GRAVITY)
          gSubSpriteData1.work3 = RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED;

      // Give control back to player
      gSamusData.lastWallTouchedMidAir = FALSE;
      gDisablePause = FALSE;
      gDefaultTransparency.unk_0 = FALSE;

-     // Since this cutscene doesn't return IGC_RESULT_STOP, this function is still called
-     // even after the cutscene ends. It's on stage 20, so technically nothing happens.
-     result = IGC_RESULT_NEXT_STAGE;
+     result = IGC_RESULT_STOP;
      break;
```

### Game always boots in mono even if stereo is enabled in settings

**Fix:** Edit `InitializeGame` in [init_game.c](../src/init_game.c) and `SoftReset` in [soft_reset_input.c](../src/soft_reset_input.c) to apply stereo after calling `InitializeAudio`.

```diff
  InitializeAudio();
+ SramRead_SoundMode();
+ FileSelectApplyStereo();
```

## Uninitialized Variables

| Variable | Function | File |
|----------|----------|------|
| `effect` | `SamusCheckSetEnvironmentalEffect` | [samus.c](../src/samus.c) |
| `stop` | `SamusShinesparking` | [samus.c](../src/samus.c) |
| `pEffectAnim` | `SamusUpdateGraphicsOam` | [samus.c](../src/samus.c) |
| `result` | `BlockSamusApplyScrewSpeedboosterDamageToEnvironment` | [block.c](../src/block.c) |
| `action` | `BgClipCheckOpeningHatch` | [bg_clip.c](../src/bg_clip.c) |
| `pDoor` | `ConnectionCheckAreaConnection` | [connection.c](../src/connection.c) |
| `dst` | `TextProcessStory` | [text.c](../src/text.c) |
| `tmp1`, `tmp2` | `MinimapDraw` | [minimap.c](../src/minimap.c) |
| `pActivation`, `pStatusActivation` | `StatusScreenGetSlotForNewItem` | [status_screen.c](../src/menus/status_screen.c) |
| `ptr` | `StatusScreenSetBeamsVisibility` | [status_screen.c](../src/menus/status_screen.c) |
| `ptr` | `StatusScreenSetSuitsVisibility` | [status_screen.c](../src/menus/status_screen.c) |
| `pActivation` | `StatusScreenToggleItem` | [status_screen.c](../src/menus/status_screen.c) |
| `src` | `TitleScreenTransferGroundGraphics` | [title_screen.c](../src/menus/title_screen.c) |
| `currSlot` | `unk_818cc` | [tourian_escape.c](../src/tourian_escape.c) |
| `diff` | `SramWriteChecked` | [sram.c](../src/sram/sram.c) |
| `updateTextAndEvents` | `BootDebugModeMainLoop` | [boot_debug.c](../src/menus/boot_debug.c) |
| `updateText` | `BootDebugSoundMainLoop` | [boot_debug.c](../src/menus/boot_debug.c) |


## TODO

### Bugs

- PowerBombExplosion doesn't check if out of bounds, which can lead to memory corruption
  - Fix: Don't check collision with any blocks outside of the room
- Bomb hover on frozen enemies ([video](https://youtu.be/UIK8YnT1sG4))
- Warping when Samus stands on multiple respawning enemies and kills one ([video](https://youtu.be/WfxkYSPTjWw))
- Frame perfect pause buffering on ziplines ignores collision
- Clipping into slopes ([video](https://www.youtube.com/watch?v=XiZRJesXHWw))
- It is possible to get an invalid time attack password without cheating, because the time attack anti-cheat check doesn't check wheather maximum ingame time was reached
  - Fix: Edit the if statement in line 283 in `TimeAttackCheckSaveFileValidity` in [time_attack.c](../src/time_attack.c) to check if max ingame time was reached if the times are equal

### Oversights and Design Flaws
