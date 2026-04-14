#include "data/fusion_gallery_data.h"
#include "macros.h"

static const u16 sFusionGallery_Palette_0[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_0.pal.inc"
};
static const u16 sFusionGallery_Palette_1[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_1.pal.inc"
};
static const u16 sFusionGallery_Palette_2[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_2.pal.inc"
};
static const u16 sFusionGallery_Palette_3[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_3.pal.inc"
};
static const u16 sFusionGallery_Palette_4[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_4.pal.inc"
};
static const u16 sFusionGallery_Palette_11[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_11.pal.inc"
};
static const u16 sFusionGallery_Palette_12[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_12.pal.inc"
};
static const u16 sFusionGallery_Palette_5[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_5.pal.inc"
};
static const u16 sFusionGallery_Palette_6[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_6.pal.inc"
};
static const u16 sFusionGallery_Palette_7[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_7.pal.inc"
};
static const u16 sFusionGallery_Palette_8[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_8.pal.inc"
};
static const u16 sFusionGallery_Palette_9[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_9.pal.inc"
};
static const u16 sFusionGallery_Palette_10[16 * 16] = {
    #include "extracted/data/fusion_gallery/image_10.pal.inc"
};

extern const u32 sFusionGallery_TopGfx_0[5628];
extern const u32 sFusionGallery_BottomGfx_0[3191];

extern const u32 sFusionGallery_TopGfx_1[5900];
extern const u32 sFusionGallery_BottomGfx_1[2986];

extern const u32 sFusionGallery_TopGfx_2[5731];
extern const u32 sFusionGallery_BottomGfx_2[3293];

extern const u32 sFusionGallery_TopGfx_3[6364];
extern const u32 sFusionGallery_BottomGfx_3[3818];

extern const u32 sFusionGallery_TopGfx_4[6851];
extern const u32 sFusionGallery_BottomGfx_4[3504];

extern const u32 sFusionGallery_TopTileTable_0[551];
extern const u32 sFusionGallery_BottomTileTable_0[368];

extern const u32 sFusionGallery_TopTileTable_1[551];
extern const u32 sFusionGallery_BottomTileTable_1[368];

extern const u32 sFusionGallery_TopTileTable_2[551];
extern const u32 sFusionGallery_BottomTileTable_2[368];

extern const u32 sFusionGallery_TopTileTable_3[551];
extern const u32 sFusionGallery_BottomTileTable_3[369];

extern const u32 sFusionGallery_TopTileTable_4[551];
extern const u32 sFusionGallery_BottomTileTable_4[369];

extern const u32 sFusionGallery_TopGfx_11[5936];
extern const u32 sFusionGallery_BottomGfx_11[3930];

extern const u32 sFusionGallery_TopGfx_12[5604];
extern const u32 sFusionGallery_BottomGfx_12[3582];

extern const u32 sFusionGallery_TopGfx_5[6633];
extern const u32 sFusionGallery_BottomGfx_5[3277];

extern const u32 sFusionGallery_TopGfx_6[6754];
extern const u32 sFusionGallery_BottomGfx_6[3419];

extern const u32 sFusionGallery_TopGfx_7[6977];
extern const u32 sFusionGallery_BottomGfx_7[4372];

extern const u32 sFusionGallery_TopGfx_8[6417];
extern const u32 sFusionGallery_BottomGfx_8[3919];

extern const u32 sFusionGallery_TopGfx_9[6918];
extern const u32 sFusionGallery_BottomGfx_9[4360];

extern const u32 sFusionGallery_TopGfx_10[5764];
extern const u32 sFusionGallery_BottomGfx_10[2273];

extern const u32 sFusionGallery_TopTileTable_11[551];
extern const u32 sFusionGallery_BottomTileTable_11[368];

extern const u32 sFusionGallery_TopTileTable_12[550];
extern const u32 sFusionGallery_BottomTileTable_12[368];

extern const u32 sFusionGallery_TopTileTable_5[551];
extern const u32 sFusionGallery_BottomTileTable_5[369];

extern const u32 sFusionGallery_TopTileTable_6[551];
extern const u32 sFusionGallery_BottomTileTable_6[368];

extern const u32 sFusionGallery_TopTileTable_7[551];
extern const u32 sFusionGallery_BottomTileTable_7[369];

extern const u32 sFusionGallery_TopTileTable_8[551];
extern const u32 sFusionGallery_BottomTileTable_8[369];

extern const u32 sFusionGallery_TopTileTable_9[550];
extern const u32 sFusionGallery_BottomTileTable_9[368];

extern const u32 sFusionGallery_TopTileTable_10[551];
extern const u32 sFusionGallery_BottomTileTable_10[368];

const struct FusionGalleryImageEntry sFusionGalleryData[NUMBER_OF_FUSION_GALLERY_IMAGES] = {
    [0] = {
        .pTopGfx = sFusionGallery_TopGfx_0,
        .pBottomGfx = sFusionGallery_BottomGfx_0,
        .pTopTileTable = sFusionGallery_TopTileTable_0,
        .pBottomTileTable = sFusionGallery_BottomTileTable_0,
        .pPalette = sFusionGallery_Palette_0
    },
    [1] = {
        .pTopGfx = sFusionGallery_TopGfx_1,
        .pBottomGfx = sFusionGallery_BottomGfx_1,
        .pTopTileTable = sFusionGallery_TopTileTable_1,
        .pBottomTileTable = sFusionGallery_BottomTileTable_1,
        .pPalette = sFusionGallery_Palette_1
    },
    [2] = {
        .pTopGfx = sFusionGallery_TopGfx_2,
        .pBottomGfx = sFusionGallery_BottomGfx_2,
        .pTopTileTable = sFusionGallery_TopTileTable_2,
        .pBottomTileTable = sFusionGallery_BottomTileTable_2,
        .pPalette = sFusionGallery_Palette_2
    },
    [3] = {
        .pTopGfx = sFusionGallery_TopGfx_3,
        .pBottomGfx = sFusionGallery_BottomGfx_3,
        .pTopTileTable = sFusionGallery_TopTileTable_3,
        .pBottomTileTable = sFusionGallery_BottomTileTable_3,
        .pPalette = sFusionGallery_Palette_3
    },
    [4] = {
        .pTopGfx = sFusionGallery_TopGfx_4,
        .pBottomGfx = sFusionGallery_BottomGfx_4,
        .pTopTileTable = sFusionGallery_TopTileTable_4,
        .pBottomTileTable = sFusionGallery_BottomTileTable_4,
        .pPalette = sFusionGallery_Palette_4
    },
    [5] = {
        .pTopGfx = sFusionGallery_TopGfx_5,
        .pBottomGfx = sFusionGallery_BottomGfx_5,
        .pTopTileTable = sFusionGallery_TopTileTable_5,
        .pBottomTileTable = sFusionGallery_BottomTileTable_5,
        .pPalette = sFusionGallery_Palette_5
    },
    [6] = {
        .pTopGfx = sFusionGallery_TopGfx_6,
        .pBottomGfx = sFusionGallery_BottomGfx_6,
        .pTopTileTable = sFusionGallery_TopTileTable_6,
        .pBottomTileTable = sFusionGallery_BottomTileTable_6,
        .pPalette = sFusionGallery_Palette_6
    },
    [7] = {
        .pTopGfx = sFusionGallery_TopGfx_7,
        .pBottomGfx = sFusionGallery_BottomGfx_7,
        .pTopTileTable = sFusionGallery_TopTileTable_7,
        .pBottomTileTable = sFusionGallery_BottomTileTable_7,
        .pPalette = sFusionGallery_Palette_7
    },
    [8] = {
        .pTopGfx = sFusionGallery_TopGfx_8,
        .pBottomGfx = sFusionGallery_BottomGfx_8,
        .pTopTileTable = sFusionGallery_TopTileTable_8,
        .pBottomTileTable = sFusionGallery_BottomTileTable_8,
        .pPalette = sFusionGallery_Palette_8
    },
    [9] = {
        .pTopGfx = sFusionGallery_TopGfx_9,
        .pBottomGfx = sFusionGallery_BottomGfx_9,
        .pTopTileTable = sFusionGallery_TopTileTable_9,
        .pBottomTileTable = sFusionGallery_BottomTileTable_9,
        .pPalette = sFusionGallery_Palette_9
    },
    [10] = {
        .pTopGfx = sFusionGallery_TopGfx_10,
        .pBottomGfx = sFusionGallery_BottomGfx_10,
        .pTopTileTable = sFusionGallery_TopTileTable_10,
        .pBottomTileTable = sFusionGallery_BottomTileTable_10,
        .pPalette = sFusionGallery_Palette_10
    },
    [11] = {
        .pTopGfx = sFusionGallery_TopGfx_11,
        .pBottomGfx = sFusionGallery_BottomGfx_11,
        .pTopTileTable = sFusionGallery_TopTileTable_11,
        .pBottomTileTable = sFusionGallery_BottomTileTable_11,
        .pPalette = sFusionGallery_Palette_11
    },
    [12] = {
        .pTopGfx = sFusionGallery_TopGfx_12,
        .pBottomGfx = sFusionGallery_BottomGfx_12,
        .pTopTileTable = sFusionGallery_TopTileTable_12,
        .pBottomTileTable = sFusionGallery_BottomTileTable_12,
        .pPalette = sFusionGallery_Palette_12
    }
};

static const u32 sFusionGallery_TopGfx_0[5628] = {
    #include "extracted/data/fusion_gallery/image_0_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_0[3191] = {
    #include "extracted/data/fusion_gallery/image_0_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_1[5900] = {
    #include "extracted/data/fusion_gallery/image_1_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_1[2986] = {
    #include "extracted/data/fusion_gallery/image_1_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_2[5731] = {
    #include "extracted/data/fusion_gallery/image_2_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_2[3293] = {
    #include "extracted/data/fusion_gallery/image_2_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_3[6364] = {
    #include "extracted/data/fusion_gallery/image_3_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_3[3818] = {
    #include "extracted/data/fusion_gallery/image_3_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_4[6851] = {
    #include "extracted/data/fusion_gallery/image_4_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_4[3504] = {
    #include "extracted/data/fusion_gallery/image_4_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopTileTable_0[551] = {
    #include "extracted/data/fusion_gallery/image_0_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_0[368] = {
    #include "extracted/data/fusion_gallery/image_0_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_1[551] = {
    #include "extracted/data/fusion_gallery/image_1_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_1[368] = {
    #include "extracted/data/fusion_gallery/image_1_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_2[551] = {
    #include "extracted/data/fusion_gallery/image_2_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_2[368] = {
    #include "extracted/data/fusion_gallery/image_2_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_3[551] = {
    #include "extracted/data/fusion_gallery/image_3_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_3[369] = {
    #include "extracted/data/fusion_gallery/image_3_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_4[551] = {
    #include "extracted/data/fusion_gallery/image_4_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_4[369] = {
    #include "extracted/data/fusion_gallery/image_4_bottom.tt.inc"
};

static const u32 sFusionGallery_TopGfx_11[5936] = {
    #include "extracted/data/fusion_gallery/image_11_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_11[3930] = {
    #include "extracted/data/fusion_gallery/image_11_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_12[5604] = {
    #include "extracted/data/fusion_gallery/image_12_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_12[3582] = {
    #include "extracted/data/fusion_gallery/image_12_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_5[6633] = {
    #include "extracted/data/fusion_gallery/image_5_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_5[3277] = {
    #include "extracted/data/fusion_gallery/image_5_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_6[6754] = {
    #include "extracted/data/fusion_gallery/image_6_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_6[3419] = {
    #include "extracted/data/fusion_gallery/image_6_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_7[6977] = {
    #include "extracted/data/fusion_gallery/image_7_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_7[4372] = {
    #include "extracted/data/fusion_gallery/image_7_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_8[6417] = {
    #include "extracted/data/fusion_gallery/image_8_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_8[3919] = {
    #include "extracted/data/fusion_gallery/image_8_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_9[6918] = {
    #include "extracted/data/fusion_gallery/image_9_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_9[4360] = {
    #include "extracted/data/fusion_gallery/image_9_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopGfx_10[5764] = {
    #include "extracted/data/fusion_gallery/image_10_top.gfx.lz.inc"
};
static const u32 sFusionGallery_BottomGfx_10[2273] = {
    #include "extracted/data/fusion_gallery/image_10_bottom.gfx.lz.inc"
};

static const u32 sFusionGallery_TopTileTable_11[551] = {
    #include "extracted/data/fusion_gallery/image_11_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_11[368] = {
    #include "extracted/data/fusion_gallery/image_11_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_12[550] = {
    #include "extracted/data/fusion_gallery/image_12_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_12[368] = {
    #include "extracted/data/fusion_gallery/image_12_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_5[551] = {
    #include "extracted/data/fusion_gallery/image_5_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_5[369] = {
    #include "extracted/data/fusion_gallery/image_5_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_6[551] = {
    #include "extracted/data/fusion_gallery/image_6_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_6[368] = {
    #include "extracted/data/fusion_gallery/image_6_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_7[551] = {
    #include "extracted/data/fusion_gallery/image_7_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_7[369] = {
    #include "extracted/data/fusion_gallery/image_7_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_8[551] = {
    #include "extracted/data/fusion_gallery/image_8_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_8[369] = {
    #include "extracted/data/fusion_gallery/image_8_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_9[550] = {
    #include "extracted/data/fusion_gallery/image_9_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_9[368] = {
    #include "extracted/data/fusion_gallery/image_9_bottom.tt.inc"
};

static const u32 sFusionGallery_TopTileTable_10[551] = {
    #include "extracted/data/fusion_gallery/image_10_top.tt.inc"
};
static const u32 sFusionGallery_BottomTileTable_10[368] = {
    #include "extracted/data/fusion_gallery/image_10_bottom.tt.inc"
};
