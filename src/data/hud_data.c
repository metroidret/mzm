#include "data/hud_data.h"
#include "macros.h"

// 32ba08

const u16 sCommonSpritesPal[96] = {
    #include "extracted/data/hud/common.pal.inc"
};
const u32 sCommonSpritesGfx[3584] = {
    #include "extracted/data/hud/common.gfx.inc"
};

const u8 sMissileDigitsGfx[2304] = {
    #include "extracted/data/hud/missile_digits.gfx.inc"
};
const u8 sPowerBombDigitsGfx[2304] = {
    #include "extracted/data/hud/power_bomb_digits.gfx.inc"
};

const u8 sMissileHudGfx_Inactive[64] = {
    #include "extracted/data/hud/missile_hud_inactive.gfx.inc"
};
const u8 sMissileHudGfx_Selected[64] = {
    #include "extracted/data/hud/missile_hud_selected.gfx.inc"
};
const u8 sMissileHudGfx_Active[64] = {
    #include "extracted/data/hud/missile_hud_active.gfx.inc"
};
const u8 sMissileHudGfx_Refill1[64] = {
    #include "extracted/data/hud/missile_hud_refill_1.gfx.inc"
};
const u8 sMissileHudGfx_Refill2[64] = {
    #include "extracted/data/hud/missile_hud_refill_2.gfx.inc"
};
const u8 sMissileHudGfx_Refill3[64] = {
    #include "extracted/data/hud/missile_hud_refill_3.gfx.inc"
};

const u8 sSuperMissileHudGfx_Inactive[64] = {
    #include "extracted/data/hud/super_missile_hud_inactive.gfx.inc"
};
const u8 sSuperMissileHudGfx_Selected[64] = {
    #include "extracted/data/hud/super_missile_hud_selected.gfx.inc"
};
const u8 sSuperMissileHudGfx_Active[64] = {
    #include "extracted/data/hud/super_missile_hud_active.gfx.inc"
};
const u8 sSuperMissileHudGfx_Refill1[64] = {
    #include "extracted/data/hud/super_missile_hud_refill_1.gfx.inc"
};
const u8 sSuperMissileHudGfx_Refill2[64] = {
    #include "extracted/data/hud/super_missile_hud_refill_2.gfx.inc"
};
const u8 sSuperMissileHudGfx_Refill3[64] = {
    #include "extracted/data/hud/super_missile_hud_refill_3.gfx.inc"
};

const u8 sPowerBombHudGfx_Inactive[64] = {
    #include "extracted/data/hud/power_bomb_hud_inactive.gfx.inc"
};
const u8 sPowerBombHudGfx_Selected[64] = {
    #include "extracted/data/hud/power_bomb_hud_selected.gfx.inc"
};
const u8 sPowerBombHudGfx_Active[64] = {
    #include "extracted/data/hud/power_bomb_hud_active.gfx.inc"
};
const u8 sPowerBombHudGfx_Refill1[64] = {
    #include "extracted/data/hud/power_bomb_hud_refill_1.gfx.inc"
};
const u8 sPowerBombHudGfx_Refill2[64] = {
    #include "extracted/data/hud/power_bomb_hud_refill_2.gfx.inc"
};
const u8 sPowerBombHudGfx_Refill3[64] = {
    #include "extracted/data/hud/power_bomb_hud_refill_3.gfx.inc"
};

const u8 sEnergyDigitsTensGfx[10 * 32] = {
    #include "extracted/data/hud/energy_digits_tens.gfx.inc"
};
const u8 sEnergyDigitsOnesGfx[10 * 32] = {
    #include "extracted/data/hud/energy_digits_ones.gfx.inc"
};
const u8 sEnergyDigitsRefill1Gfx[20 * 32] = {
    #include "extracted/data/hud/energy_digits_refill_1.gfx.inc"
};
const u8 sEnergyDigitsRefill2Gfx[20 * 32] = {
    #include "extracted/data/hud/energy_digits_refill_2.gfx.inc"
};
const u8 sEnergyDigitsRefill3Gfx[20 * 32] = {
    #include "extracted/data/hud/energy_digits_refill_3.gfx.inc"
};

const u8 sEnergyTanksGfx_Zero[160 * 1] = {
    #include "extracted/data/hud/energy_tanks_zero.gfx.inc"
};
const u8 sEnergyTanksGfx_One[160 * 2] = {
    #include "extracted/data/hud/energy_tanks_one.gfx.inc"
};
const u8 sEnergyTanksGfx_Two[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_two.gfx.inc"
};
const u8 sEnergyTanksGfx_Three[160 * 4] = {
    #include "extracted/data/hud/energy_tanks_three.gfx.inc"
};
const u8 sEnergyTanksGfx_Four[160 * 5] = {
    #include "extracted/data/hud/energy_tanks_four.gfx.inc"
};
const u8 sEnergyTanksGfx_Five[160 * 6] = {
    #include "extracted/data/hud/energy_tanks_five.gfx.inc"
};
const u8 sEnergyTanksGfx_Six[160 * 7] = {
    #include "extracted/data/hud/energy_tanks_six.gfx.inc"
};
const u8 sEnergyTanksGfx_Seven[160 * 8] = {
    #include "extracted/data/hud/energy_tanks_seven.gfx.inc"
};
const u8 sEnergyTanksGfx_Eight[160 * 9] = {
    #include "extracted/data/hud/energy_tanks_eight.gfx.inc"
};
const u8 sEnergyTanksGfx_Nine[160 * 10] = {
    #include "extracted/data/hud/energy_tanks_nine.gfx.inc"
};
const u8 sEnergyTanksGfx_Ten[160 * 11] = {
    #include "extracted/data/hud/energy_tanks_ten.gfx.inc"
};
const u8 sEnergyTanksGfx_Eleven[160 * 12] = {
    #include "extracted/data/hud/energy_tanks_eleven.gfx.inc"
};
const u8 sEnergyTanksGfx_Twelve[160 * 13] = {
    #include "extracted/data/hud/energy_tanks_twelve.gfx.inc"
};

const u8 sEnergyTanksRefillGfx_One[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_one.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Two[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_two.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Three[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_three.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Four[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_four.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Five[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_five.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Six[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_six.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Seven[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_seven.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Eight[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_eight.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Nine[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_nine.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Ten[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_ten.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Eleven[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_eleven.gfx.inc"
};
const u8 sEnergyTanksRefillGfx_Twelve[160 * 3] = {
    #include "extracted/data/hud/energy_tanks_refill_twelve.gfx.inc"
};

const u8 sSuitlessHudChargeBarGfx[56 * 256] = {
    #include "extracted/data/hud/suitless_hud_bar.gfx.inc"
};

// 339aa8
