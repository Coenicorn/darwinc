#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include <string.h>

#include "world.h"
#include "terrain.h"
#include "vec3.h"

DC_World *DC_CreateWorld(int sx, int sy, int sz, int seed)
{

    DC_World *world = malloc(sizeof(DC_World));

    world->map = malloc(sizeof(DC_Tile) * sx * sy * sz);

    if (world->map == NULL)
    {
        TraceLog(LOG_FATAL, "World too large.");

        exit(1);
    }

    // initialize empty world
    for (int x = 0; x < sx; x++)
    {
        for (int y = 0; y < sy; y++)
        {
            for (int z = 0; z < sz; z++)
            {

                DC_Tile *tile = DC_TileAtWorld(world, x, y, z);

                tile->type = EMPTY;
                tile->pos = (DC_Vec3){x, y, z};

            }
        }
    }

    return world;

}

DC_World *DC_LoadWorldFromFile(const char *filename)
{
    FILE *worldFile = fopen(filename, "r");

    if (worldFile == NULL)
    {
        TraceLog(LOG_ERROR, "Failed to open world file.");
    
        return NULL;
    }

    // get file length
    fseek(worldFile, 0, SEEK_END);
    long fileLen = ftell(worldFile);
    fseek(worldFile, 0, SEEK_SET);

    char buf[fileLen+1];

    fread(buf, fileLen, 1, worldFile);

    buf[fileLen] = '\0';

    // ...

    fclose(worldFile);
}

void DC_FreeWorld(DC_World *w)
{

    free(w->map);
    free(w);

}