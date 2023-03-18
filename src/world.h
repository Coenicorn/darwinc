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
    int maplen;

    /* Size x, y and z */
    uint16_t sx, sy, sz;

} DC_World;



/* Creates new world without map, this needs to be defined by user */
DC_World *DC_CreateWorldSkeleton(uint16_t sx, uint16_t sy, uint16_t sz);
/* Generates a new map for a world */
void DC_GenerateMapWorld(DC_World *w);
/* Creates new world */
DC_World *DC_CreateWorld(uint16_t sx, uint16_t sy, uint16_t sz);
/* Frees world from memory */
void DC_FreeWorld(DC_World *w);
/* Loads world from .wld file */
DC_World *DC_LoadWorldFromFile(const char *filename);
/* Saves world to .wld file */
int DC_SaveWorldToFile(DC_World *w, const char *filename);



static inline int DC_InWorldBounds(DC_World *w, int x, int y, int z)
{
    return (x >= 0 && x < w->sx && y >= 0 && y < w->sy && z >= 0 && z < w->sz);
}

static inline int DC_WorldPosToIndex(DC_World *w, int x, int y, int z)
{
    return (x * w->sy * w->sz + y * w->sz + z);
}

/* DOES NOT check if (x, y, z) is a valid position */
static inline DC_Tile *DC_TileAtWorld(DC_World *w, int x, int y, int z)
{
    return &w->map[DC_WorldPosToIndex(w, x, y, z)];
}

#endif