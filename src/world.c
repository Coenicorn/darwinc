#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "world.h"
#include "terrain.h"
#include "vec3.h"
#include "log.h"

DC_World *DC_CreateWorldSkeleton(uint16_t sx, uint16_t sy, uint16_t sz)
{
    // initialization
    DC_World *world = malloc(sizeof(DC_World));

    world->sx = sx;
    world->sy = sy;
    world->sz = sz;

    world->maplen = world->sz * world->sy * world->sx;

    world->map = malloc(sizeof(DC_Tile) * sx * sy * sz);

    if (world->map == NULL)
    {
        DC_Log("World too large");

        exit(1);
    }

    return world;
}

void DC_GenerateMapWorld(DC_World *w)
{
    // initialize empty world
    for (int x = 0; x < w->sx; x++)
    {
        for (int y = 0; y < w->sy; y++)
        {
            for (int z = 0; z < w->sz; z++)
            {

                DC_Tile *tile = DC_TileAtWorld(w, x, y, z);

                tile->type = DC_TERRAIN_EMPTY;

                tile->pos = (DC_Vec3){x, y, z};

            }
        }
    }
}


DC_World *DC_CreateWorld(uint16_t sx, uint16_t sy, uint16_t sz)
{
    DC_World *world = DC_CreateWorldSkeleton(sx, sy, sz);

    DC_GenerateMapWorld(world);

    return world;

}

/* 
    World file operations

    The first 8 bytes of a .wld file are the dimensions (2 bytes per dimension) and the seed.
    The next x*y*z bytes are the tile types of tiles in the map.
    The block of bytes is mapped the same way as the regular map is, ordered
    x -> y -> z.

    An empty 2x2x2 map would look like this (in binary of course):

    0 0 0 0 0 0 0 0

    with xyz

    (((0 0)z0 (0 0)z1)y0 ((0 0)z0 (0 0)z1)y1)x0 (((0 0)z0 (0 0)z1)y0 ((0 0)z0 (0 0)z1)y1)x1
*/
int DC_SaveWorldToFile(DC_World *w, const char *filename)
{

    // open binary file
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        DC_Log("Failed to create world file");

        return 1;
    }

    // store dimensions and seed
    uint16_t dimSeedBuf[3] = { w->sx, w->sy, w->sz };
    fwrite(dimSeedBuf, sizeof(uint16_t), 3, fp);

    // get buffer of tile types in world map
    uint8_t buf[w->maplen];

    for (int i = 0; i < w->maplen; i++)
        buf[i] = w->map[i].type;

    // write the world map to the file in binary
    fwrite(buf, sizeof(uint8_t), (w->sx * w->sy * w->sz), fp);

    fclose(fp);

    DC_Log("Succesfully saved world to file");

    return 0;

}

DC_World *DC_LoadWorldFromFile(const char *filename)
{

    // open binary file
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        DC_Log("Failed to open world file");

        return NULL;
    }

    // get the dimensions
    uint16_t dimensions[3], sx, sy, sz;
    
    fread(dimensions, sizeof(uint16_t), 3, fp);

    sx = dimensions[0];
    sy = dimensions[1];
    sz = dimensions[2];

    DC_World *outWorld = DC_CreateWorldSkeleton(sx, sy, sz);

    // read into world map
    fread(outWorld->map, sizeof(uint8_t), outWorld->maplen, fp);

    DC_Log("Succesfully loaded world from file");

    fclose(fp);

    return outWorld;
}

void DC_FreeWorld(DC_World *w)
{

    free(w->map);
    free(w);

}