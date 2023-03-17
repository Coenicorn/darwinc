#include <raylib.h>

#include "world.h"

int main(void)
{

    DC_World *g_world = DC_CreateWorld(DC_WORLD_SIZEX, DC_WORLD_SIZEY, DC_WORLD_SIZEZ, 0);

    // raylib initialization
    InitWindow(500, 500, "DarwinC");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            DrawRectangle(0, 0, 100, 100, RED);

        EndDrawing();
    }

    CloseWindow();

    DC_FreeWorld(g_world);

    return 0;
}