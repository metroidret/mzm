#include "data/animated_tiles_data.h"
#include "macros.h"

const u8 sAnimatedTilesGfx[100 * 128] = {
    #include "extracted/data/animated_tiles/tiles.gfx.inc"
};
const u8 sAnimatedTankGfx[4 * 512] = {
    #include "extracted/data/animated_tiles/tanks.gfx.inc"
};
const u8 sAnimatedLiquidsGfx[12 * 512] = {
    #include "extracted/data/animated_tiles/liquids.gfx.inc"
};
