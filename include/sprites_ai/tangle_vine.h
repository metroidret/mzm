#ifndef TANGLE_VINE_AI_H
#define TANGLE_VINE_AI_H

enum TangleVineGerutaPart {
    TANGLE_VINE_GERUTA_PART_GRIP,
    TANGLE_VINE_GERUTA_PART_GERUTA,
    TANGLE_VINE_GERUTA_PART_ROOT,

    TANGLE_VINE_GERUTA_PART_END
};

void TangleVineSyncSprites(void);
void TangleVineGeruta(void);
void TangleVineGerutaPart(void);
void TangleVineRedGeruta(void);
void TangleVineLarvaRight(void);
void TangleVineLarvaLeft(void);
void TangleVineTall(void);
void TangleVineMedium(void);
void TangleVineCurved(void);
void TangleVineShort(void);

#endif /* TANGLE_VINE_AI_H */
