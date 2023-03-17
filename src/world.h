#ifndef DC_WORLD_H
#define DC_WORLD_H

#include <stdlib.h>

#include "terrain.h"

#define DC_WORLD_SIZEX 4
#define DC_WORLD_SIZEY 4
#define DC_WORLD_SIZEZ 4

typedef struct DC_World
{

    /* DC_TileAtWorld() to access tiles */
    DC_Tile *map;

    /* Size x, y and z */
    int sx, sy, sz

} DC_World;



DC_World *DC_CreateWorld(int sx, int sy, int sz, int seed);
void DC_FreeWorld(DC_World *w);
DC_World *DC_LoadWorldFromFile(const char *filename);



static inline int DC_InWorldBounds(DC_World *w, int x, int y, int z)
{
    return (x >= 0 && x < w->sx && y >= 0 && y < w->sy && z >= 0 && z < w->sz);
}

static inline int DC_WorldPosToIndex(DC_World *w, int x, int y, int z)
{
    return (x * w->sx + y * w->sy + z);
}

/* DOES NOT check if (x, y, z) is a valid position */
static inline DC_Tile *DC_TileAtWorld(DC_World *w, int x, int y, int z)
{
    return &w->map[DC_WorldPosToIndex(w, x, y, z)];
}

#endif