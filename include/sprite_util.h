#ifndef SPRITE_UTIL_H
#define SPRITE_UTIL_H

#include "types.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/sprite.h"
#include "structs/samus.h"

void SpriteUtilInitLocationText(void);
void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 samusY, u16 spriteX);
void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 samusY, u16 spriteX);
boolu8 SpriteUtilTakeDamageFromSprite(boolu8 kbFlag, struct SpriteData* pSprite, u16 dmgMultiplier);
boolu32 SpriteUtilCheckObjectsTouching(u16 o1Top, u16 o1Bottom, u16 o1Left, u16 o1Right, u16 o2Top, u16 o2Bottom, u16 o2Left, u16 o2Right);
void SpriteUtilSamusAndSpriteCollision(void);
u32 SpriteUtilCheckVerticalCollisionAtPosition(u16 yPosition, u16 xPosition);
u32 SpriteUtilCheckVerticalCollisionAtPositionSlopes(u16 yPosition, u16 xPosition);
void SpriteUtilAlignYPositionOnSlopeAtOrigin(void);
void SpriteUtilAlignYPositionOnSlopeAtHitboxBottom(void);
void SpriteUtilCheckCollisionAtPosition(u32 yPosition, u32 xPosition);
CollisionResult SpriteUtilGetCollisionAtPosition(u16 yPosition, u16 xPosition);
void SpriteUtilCurrentSpriteFall(void);
void SpriteUtilChooseRandomXFlip(void);
void SpriteUtilChooseRandomXDirection(void);
void SpriteUtilChooseRandomXDirectionRoomSlot(u8 roomSlot);
void SpriteUtilMakeSpriteFaceSamusXFlip(void);
void SpriteUtilMakeSpriteFaceSamusDirection(void);
void SpriteUtilMakeSpriteFaceAwayFromSamusXFlip(void);
void SpriteUtilMakeSpriteFaceAwayFromSamusDirection(void);
void SpriteUtilMoveHorizontallyForwardOnSlopeDirection(s16 movement);
void SpriteUtilMoveHorizontallyForwardOnSlopeXFlip(s16 movement);
u8 SpriteUtilMakeSpriteFaceSamusRotation(s32 rotation, s32 targetY, s32 targetX, s32 spriteY, s32 spriteX);
boolu32 SpriteUtilHasCurrentAnimationEnded(void);
boolu32 SpriteUtilHasCurrentAnimationNearlyEnded(void);
boolu32 SpriteUtilHasAnimationEnded(u8 ramSlot);
boolu32 SpriteUtilHasAnimationNearlyEnded(u8 ramSlot);
boolu32 SpriteUtilHasSubSprite1AnimationEnded(void);
boolu32 SpriteUtilHasSubSprite1AnimationNearlyEnded(void);
boolu32 SpriteUtilHasSubSprite2AnimationEnded(void);
boolu32 SpriteUtilHasSubSpriteAnimationEnded(struct SubSpriteData* pSub);
boolu32 SpriteUtilHasSubSpriteAnimationNearlyEnded(struct SubSpriteData* pSub);
NearLeftRight SpriteUtilCheckSamusNearSpriteLeftRight(u16 yRange, u16 xRange);
NearAboveBelow SpriteUtilCheckSamusNearSpriteAboveBelow(u16 yRange, u16 xRange);
NearFrontBack SpriteUtilCheckSamusNearSpriteFrontBehind(u16 yRange, u16 xRangeFront, u16 xRangeBehind);
void SpriteUtilSamusStandingOnSprite(struct SpriteData* pSprite);
void SpriteUtilUpdateFreezeTimer(void);
void SpriteUtilUnfreezeAnimEasy(void);
void SpriteUtilMetroidUnfreezeAnim(void);
void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 spriteId, u8 ramSlot);
void SpriteUtilUpdatePrimarySpriteFreezeTimerOfCurrent(void);
void SpriteUtilUnfreezeSecondarySprites(SecondarySprite spriteId, u8 ramSlot);
boolu32 SpriteUtilRefillEnergy(void);
boolu32 SpriteUtilRefillMissiles(void);
boolu32 SpriteUtilRefillSuperMissiles(void);
boolu32 SpriteUtilRefillPowerBombs(void);
boolu32 SpriteUtilCheckCrouchingOrMorphed(void);
boolu32 SpriteUtilCheckCrouchingOrCrawling(void);
boolu32 SpriteUtilCheckMorphed(void);
boolu32 SpriteUtilCheckStopSpritesPose(void);
DamageContactType SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData);
boolu32 SpriteUtilCheckPullingSelfUp(void);
boolu32 SpriteUtilCheckOnZipline(void);
u8 SpriteUtilCountPrimarySprites(PrimarySprite spriteId);
u8 SpriteUtilCountChildSecondarySprites(SecondarySprite spriteId);
u8 SpriteUtilCountChildPrimarySprites(PrimarySprite spriteId);
u8 SpriteUtilFindPrimary(PrimarySprite spriteId);
u8 SpriteUtilFindSecondaryWithRoomSlot(SecondarySprite spriteId, u8 roomSlot);
boolu8 SpriteUtilCheckHasDrops(void);
u8 SpriteUtilCountDrops(void);
void SpriteUtilMoveSpriteTowardsSamus(u16 samusY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor);
void SpriteUtilRidleyFireballMove(u16 dstY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor);
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite);
void SpriteUtilRandomSpriteDebris(u8 cloudType, u8 number, u16 yPosition, u16 xPosition);
PrimarySprite SpriteUtilGetAmmoDrop(u8 rng);
PrimarySprite SpriteUtilDetermineEnemyDrop(void);
void SpriteUtilSpriteDeath(SpriteDeathType deathType, u16 yPosition, u16 xPosition, boolu8 playSound, ParticleEffectId effect);
boolu8 SpriteUtilIsSpriteStunned(void);
boolu8 SpriteUtilShouldFall(void);
void SpriteUtilUpdateSubSprite1Timer(void);
void SpriteUtilUpdateSubSprite1Anim(void);
void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void);
void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam(void);
void SpriteUtilUpdateSubSprite2Anim(void);
void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM(void);
void SpriteUtilUpdateSubSpriteAnim(struct SubSpriteData* pSub);
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition(struct SubSpriteData* pSub);
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOam(struct SubSpriteData* pSub);
boolu8 SpriteCheckCollidingWithSamus(void);
void SpriteUtilSetSplashEffect(u16 yPosition, u16 xPosition, SplashSize size);
boolu32 SpriteUtilCheckOutOfRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, SplashSize size);
boolu32 SpriteUtilCheckInRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, SplashSize size);
u32 SpriteUtilGetFinalCompletionPercentage(void);

#endif /* SPRITE_UTIL_H */
