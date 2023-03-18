#include <raylib.h>

#include "world.h"

#define TILESIZEPIXEL 2

RenderTexture getWorldTopDown(DC_World *w)
{
    int width = w->sx * TILESIZEPIXEL, height = w->sy * TILESIZEPIXEL;
    RenderTexture worldTexture = LoadRenderTexture(width, height);

    BeginTextureMode(worldTexture);

        // Get top down view of world

        for (int x = 0; x < w->sx; x++)
        {
            for (int y = 0; y < w->sy; y++)
            {
                for (int z = w->sz-1; z >= 0; z--)
                {

                    DC_Tile *tile = DC_TileAtWorld(w, x, y, z);

                    if (tile == NULL || tile->type == DC_TERRAIN_EMPTY) continue;

                    // add 1 because, as we all know, arrays start counting from 0, but if we had a tile at z=0 it would never get rendered.
                    float depthNormalized = ((float)z+1.f) / (float)w->sz;

                    DrawRectangle(x * TILESIZEPIXEL, y * TILESIZEPIXEL, TILESIZEPIXEL, TILESIZEPIXEL, ColorFromNormalized((Vector4){ depthNormalized, 0, 0, 1 }));

                    break;

                }
            }
        }

    EndTextureMode();

    return worldTexture;

}

int main(void)
{

    DC_World *g_world = DC_LoadWorldFromFile("empty.wld");;

    // raylib initialization
    InitWindow(500, 500, "DarwinC");
    SetTargetFPS(60);

    RenderTexture worldTexture = getWorldTopDown(g_world);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            DrawTexture(worldTexture.texture, 0, 0, WHITE);

        EndDrawing();

    }

    UnloadRenderTexture(worldTexture);
    
    CloseWindow();

    DC_FreeWorld(g_world);

    return 0;
}