#include "data/hud_data.h"
#include "macros.h"

// 32ba08

const u16 sCommonSpritesPal[96] = INCBIN_U16("data/hud/common.pal");
const u32 sCommonSpritesGfx[3584] = INCBIN_U32("data/hud/common.gfx");

const u8 sMissileDigitsGfx[2304] = INCBIN_U8("data/hud/missile_digits.gfx");
const u8 sPowerBombDigitsGfx[2304] = INCBIN_U8("data/hud/power_bomb_digits.gfx");

const u8 sMissileHudGfx_Inactive[64] = INCBIN_U8("data/hud/missile_hud_inactive.gfx");
const u8 sMissileHudGfx_Selected[64] = INCBIN_U8("data/hud/missile_hud_selected.gfx");
const u8 sMissileHudGfx_Active[64] = INCBIN_U8("data/hud/missile_hud_active.gfx");
const u8 sMissileHudGfx_Refill1[64] = INCBIN_U8("data/hud/missile_hud_refill_1.gfx");
const u8 sMissileHudGfx_Refill2[64] = INCBIN_U8("data/hud/missile_hud_refill_2.gfx");
const u8 sMissileHudGfx_Refill3[64] = INCBIN_U8("data/hud/missile_hud_refill_3.gfx");

const u8 sSuperMissileHudGfx_Inactive[64] = INCBIN_U8("data/hud/super_missile_hud_inactive.gfx");
const u8 sSuperMissileHudGfx_Selected[64] = INCBIN_U8("data/hud/super_missile_hud_selected.gfx");
const u8 sSuperMissileHudGfx_Active[64] = INCBIN_U8("data/hud/super_missile_hud_active.gfx");
const u8 sSuperMissileHudGfx_Refill1[64] = INCBIN_U8("data/hud/super_missile_hud_refill_1.gfx");
const u8 sSuperMissileHudGfx_Refill2[64] = INCBIN_U8("data/hud/super_missile_hud_refill_2.gfx");
const u8 sSuperMissileHudGfx_Refill3[64] = INCBIN_U8("data/hud/super_missile_hud_refill_3.gfx");

const u8 sPowerBombHudGfx_Inactive[64] = INCBIN_U8("data/hud/power_bomb_hud_inactive.gfx");
const u8 sPowerBombHudGfx_Selected[64] = INCBIN_U8("data/hud/power_bomb_hud_selected.gfx");
const u8 sPowerBombHudGfx_Active[64] = INCBIN_U8("data/hud/power_bomb_hud_active.gfx");
const u8 sPowerBombHudGfx_Refill1[64] = INCBIN_U8("data/hud/power_bomb_hud_refill_1.gfx");
const u8 sPowerBombHudGfx_Refill2[64] = INCBIN_U8("data/hud/power_bomb_hud_refill_2.gfx");
const u8 sPowerBombHudGfx_Refill3[64] = INCBIN_U8("data/hud/power_bomb_hud_refill_3.gfx");

const u8 sEnergyDigitsTensGfx[10 * 32] = INCBIN_U8("data/hud/energy_digits_tens.gfx");
const u8 sEnergyDigitsOnesGfx[10 * 32] = INCBIN_U8("data/hud/energy_digits_ones.gfx");
const u8 sEnergyDigitsRefill1Gfx[20 * 32] = INCBIN_U8("data/hud/energy_digits_refill_1.gfx");
const u8 sEnergyDigitsRefill2Gfx[20 * 32] = INCBIN_U8("data/hud/energy_digits_refill_2.gfx");
const u8 sEnergyDigitsRefill3Gfx[20 * 32] = INCBIN_U8("data/hud/energy_digits_refill_3.gfx");

const u8 sEnergyTanksGfx_Zero[160 * 1] = INCBIN_U8("data/hud/energy_tanks_zero.gfx");
const u8 sEnergyTanksGfx_One[160 * 2] = INCBIN_U8("data/hud/energy_tanks_one.gfx");
const u8 sEnergyTanksGfx_Two[160 * 3] = INCBIN_U8("data/hud/energy_tanks_two.gfx");
const u8 sEnergyTanksGfx_Three[160 * 4] = INCBIN_U8("data/hud/energy_tanks_three.gfx");
const u8 sEnergyTanksGfx_Four[160 * 5] = INCBIN_U8("data/hud/energy_tanks_four.gfx");
const u8 sEnergyTanksGfx_Five[160 * 6] = INCBIN_U8("data/hud/energy_tanks_five.gfx");
const u8 sEnergyTanksGfx_Six[160 * 7] = INCBIN_U8("data/hud/energy_tanks_six.gfx");
const u8 sEnergyTanksGfx_Seven[160 * 8] = INCBIN_U8("data/hud/energy_tanks_seven.gfx");
const u8 sEnergyTanksGfx_Eight[160 * 9] = INCBIN_U8("data/hud/energy_tanks_eight.gfx");
const u8 sEnergyTanksGfx_Nine[160 * 10] = INCBIN_U8("data/hud/energy_tanks_nine.gfx");
const u8 sEnergyTanksGfx_Ten[160 * 11] = INCBIN_U8("data/hud/energy_tanks_ten.gfx");
const u8 sEnergyTanksGfx_Eleven[160 * 12] = INCBIN_U8("data/hud/energy_tanks_eleven.gfx");
const u8 sEnergyTanksGfx_Twelve[160 * 13] = INCBIN_U8("data/hud/energy_tanks_twelve.gfx");

const u8 sEnergyTanksRefillGfx_One[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_one.gfx");
const u8 sEnergyTanksRefillGfx_Two[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_two.gfx");
const u8 sEnergyTanksRefillGfx_Three[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_three.gfx");
const u8 sEnergyTanksRefillGfx_Four[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_four.gfx");
const u8 sEnergyTanksRefillGfx_Five[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_five.gfx");
const u8 sEnergyTanksRefillGfx_Six[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_six.gfx");
const u8 sEnergyTanksRefillGfx_Seven[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_seven.gfx");
const u8 sEnergyTanksRefillGfx_Eight[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_eight.gfx");
const u8 sEnergyTanksRefillGfx_Nine[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_nine.gfx");
const u8 sEnergyTanksRefillGfx_Ten[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_ten.gfx");
const u8 sEnergyTanksRefillGfx_Eleven[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_eleven.gfx");
const u8 sEnergyTanksRefillGfx_Twelve[160 * 3] = INCBIN_U8("data/hud/energy_tanks_refill_twelve.gfx");

const u8 sSuitlessHudChargeBarGfx[56 * 256] = INCBIN_U8("data/hud/suitless_hud_bar.gfx");

// 339aa8
