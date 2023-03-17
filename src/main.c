#include <raylib.h>

int main(void)
{
    InitWindow(500, 500, "DarwinC");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            DrawRectangle(0, 0, 100, 100, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}