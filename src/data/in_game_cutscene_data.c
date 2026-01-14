#include "data/in_game_cutscene_data.h"
#include "macros.h"

#include "constants/connection.h"
#include "in_game_cutscene.h"

const struct InGameCutsceneData sInGameCutsceneData[IGC_END] = {
    [0] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [1] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [2] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [3] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [IGC_CLOSE_UP] = {
        .unk_0 = 0,
        .area = AREA_BRINSTAR,
        .pFunction = InGameCutsceneSamusCloseUp
    },
    [5] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [6] = {
        .unk_0 = 0,
        .area = AREA_CRATERIA,
        .pFunction = NULL
    },
    [IGC_LONG_BEAM_HINT] = {
        .unk_0 = 0,
        .area = AREA_BRINSTAR,
        .pFunction = NULL
    },
    [8] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [IGC_GETTING_VARIA] = {
        .unk_0 = 0,
        .area = SCHAR_MAX,
        .pFunction = InGameCutsceneUpgradingSuit
    },
    [IGC_GETTING_FULLY_POWERED] = {
        .unk_0 = 0,
        .area = SCHAR_MAX,
        .pFunction = InGameCutsceneUpgradingSuit
    },
    [11] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [12] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [13] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [14] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [15] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [16] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [17] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [18] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [19] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [20] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [21] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [22] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [23] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [24] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [25] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [26] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [27] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [28] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [29] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [30] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    },
    [31] = {
        .unk_0 = 1,
        .area = SCHAR_MAX,
        .pFunction = NULL
    }
};
