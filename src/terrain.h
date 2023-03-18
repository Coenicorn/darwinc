#ifndef DC_TERRAIN_H
#define DC_TERRAIN_H

#include <stdint.h>

#include "vec3.h"

typedef enum
{
    DC_TERRAIN_EMPTY,
    DC_TERRAIN_GRASS,
    DC_TERRAIN_EARTH,
    DC_TERRAIN_STONE,

} DC_TILES;

typedef struct DC_Tile
{

    uint8_t type;
    DC_Vec3 pos;

} DC_Tile;

#endif