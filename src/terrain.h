#ifndef DC_TERRAIN_H
#define DC_TERRAIN_H

#include <stdint.h>

#include "vec3.h"

typedef enum
{
    DC_TILE_EMPTY,
    DC_TILE_GRASS,
    DC_TILE_EARTH,
    DC_TILE_STONE,
    DC_TILE_WATER
} DC_TILE_TYPES;

typedef struct DC_Tile
{

    uint8_t type;
    Vec3 pos;

} DC_Tile;

#endif