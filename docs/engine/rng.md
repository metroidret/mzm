# Random Number Generation

Random number generation (RNG) is primarily used by sprites to choose random behavior. This document details how RNG works, as well as some of its flaws.

## Sprite RNG

Sprites use the RAM variable `gSpriteRng`, which is set to a value between 0-15 for each sprite that is processed. This value can be used by the sprite in a variety of ways, including:

- Choosing facing/movement direction
- Action timer (ex: delay before attacking)
- Choosing an attack
- Jump height
- Deciding when to play a sound
- Spawning debris/explosions

### RNG Calculation

Random numbers are calculated in the `SpriteUpdate` function in [sprite.c](../src/sprite.c). The formula looks like this:

```
RandomNumberTable[(frame1 + frame2 + index + xPosition + yPosition) % 32]
```

- **frame1**: 8-bit frame counter
- **frame2**: 16-bit frame counter divided by 16
- **index**: Index of the sprite in `gSpriteData`
- **xPosition**: The sprite's X position
- **yPosition**: The sprite's Y position

The random number table is an array of 32 values, containing two of each number between 0-15 (see `sSpriteRandomNumberTable` in [sprite_data.c](../src/data/sprite_data.c)). This is why the formula above does modulo with 32. These are the numbers in the table:

```
13, 2, 6, 8, 7, 9, 14, 10, 2, 4, 14, 4, 12, 15, 13, 12,
11, 1, 3, 15, 0, 6, 7, 8, 11, 5, 0, 3, 5, 1, 9, 10
```

Before every sprite runs its AI, this number is calculated based on the sprite and assigned to `gSpriteRng`. This number is generally used in one of the following ways:

#### Compared with another number

Comparing to another number (using less than or greater than) computes a probability that's a multiple of 1/16. For example, checking if `gSpriteRng < 7` provides a 7/16 (43.75%) chance.

#### Reduced using modulo

Using modulo with a power of 2 (or bitwise AND with a power of 2 minus 1) computes a probability that equals 1/2^x. This allows for probabilities of 1/2, 1/4, 1/8, and 1/16. For example, checking if `(gSpriteRng % 2) == 0` (or `(gSpriteRng & 1) == 0`) provides a 1/2 (50%) chance. This can be combined with the method above if two separate probabilities are needed at the same time.

#### Mutiplied or divided with another number

Multiplying or dividing can be used to convert the range of 0-16 to a bigger or smaller range, which is often used for timers or counters. For example, dividing by 4 gives a range of 0-3, which could determine the number of attacks. Multiplying by 16 gives a range of 0-240, which could determine how long to wait before attacking.

## Other RNG

There's a random number table which contains one of each number between 0-255 (see `sRandomNumberTable` in [generic_data.c](../src/data/generic_data.c)). It's used in the following situations:

- Determining a Baristute's third drop (`BaristuteDeath` in [baristute.c](../src/sprites_ai/baristute.c))
- Delay before Ruins Test is vulnerable (`RuinsTestCalculateDelay` in [ruins_test.c](../src/sprites_ai/ruins_test.c))
- Debris in the Kraid rising cutscene (`KraidRisingRising`, `KraidRisingUpdatePuff`, and `KraidRisingUpdateDebris` in [kraid_rising.c](../src/cutscenes/kraid_rising.c))
- The particles floating through space in the Ridley in space cutscene (`RidleyInSpaceShipLeaving`, `RidleyInSpaceViewOfShipParticles`, and `RidleyInSpaceShipLeavingParticles` in [ridley_in_space.c](../src/cutscenes/ridley_in_space.c))
- Sprite positions and speeds for the enter Tourian cutscene (`EnterTourianUpdateMetroid` and `EnterTourianUpdatePirate` in [enter_tourian.c](../src/cutscenes/enter_tourian.c))
- Various effects during the fully powered suit cutscene (`GettingFullyPoweredSuitUpdateSparkleAroundRing` and `GettingFullyPoweredSuitUpdateSparkleGoingUp` in [getting_fully_powered_suit.c](../src/cutscenes/getting_fully_powered_suit.c))

## Sprite RNG Flaws

The implementation for sprite RNG has two main issues:

#### 1. Sprite RNG is inefficient

A random number is calculated for every sprite each frame. However, most sprites don't use RNG at all, and sprites that do use RNG only use it occasionally, not every frame.

Despite this, computing the random number is relatively cheap, and there's a maximum of 24 sprites, so the total cost doesn't affect performance much.

#### 2. Sprite RNG is biased

For the sprite RNG formula, it makes sense that the sprite index, sprite position, and frame counter are part of the calculation. This ensures that different enemies will have distinct behavior, and that the same enemy will behave differently each time a room is loaded. However, since the length of the random number table is a power of 2 (32 = 2^5), if the amount of frames between RNG checks is also a power of 2, the patterns will be biased. This is made worse if the sprite doesn't move, or if its position also changes by a power of 2.

For example, suppose a stationary enemy uses RNG to determine how many frames to wait before attacking, using the formula `64 + (RN * 8)`. Since the number of frames between RNG checks would always be a multiple of 8, only 4 of the values in the random number table would ever be used.

In practice, the bias is generally not noticeable, but it does mean the actual pattern distribution for enemies does not match the theoretical distribution.
