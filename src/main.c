#include <stdio.h>

#include "world.h"

int main(void)
{

    DC_World *g_world = DC_LoadWorldFromFile("empty.wld");;

    DC_FreeWorld(g_world);

    return 0;
}