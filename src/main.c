#include <stdio.h>

#include "world.h"
#include "ecs.h"

#include "dyve.h"

int main(void)
{

    // DC_World *g_world = DC_LoadWorldFromFile("empty_16.wld");

    // DC_FreeWorld(g_world);

    ECS_Container *g_ECS = ECS_CreateECS();

    ECS_Destroy(g_ECS);

    return 0;
}