#ifndef DC_TERRAIN_H
#define DC_TERRAIN_H

#include "vec3.h"

typedef enum
{

    GRASS,
    EARTH,
    STONE,
    EMPTY

} DC_TILES;

typedef struct DC_Tile
{

    DC_TILES type;
    DC_Vec3 pos;

} DC_Tile;

#endif