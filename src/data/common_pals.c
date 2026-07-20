#include "data/common_pals.h"

#include "macros.h"

const u16 sCommonTilesPal[1 * 16] = {
    #include "extracted/data/common/common_tiles.pal.inc"
};
const u16 sDoorTransitionPal[15 * 16] = {
    #include "extracted/data/common/door_transition.pal.inc"
};

const u16 sCommonTilesMotherShipPal[1 * 16] = {
    #include "extracted/data/common/common_tiles_mother_ship.pal.inc"
};
const u16 sDoorTransitionMotherShipPal[15 * 16] = {
    #include "extracted/data/common/door_transition_mother_ship.pal.inc"
};

const u16 sHatchFlashingMotherShipPal[16 * 16] = {
    #include "extracted/data/common/hatch_flashing_mother_ship.pal.inc"
};
const u16 sHatchFlashingPal[16 * 16] = {
    #include "extracted/data/common/hatch_flashing.pal.inc"
};
