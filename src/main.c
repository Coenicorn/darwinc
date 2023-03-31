#include <stdio.h>

#include "world.h"
#include "ecs.h"
#include "componentdef.h"
#include "log.h"
#include "dyve.h"

int main(void)
{

    DC_Log("Initialized");

    // DC_World *g_world = DC_LoadWorldFromFile("empty_16.wld");

    // DC_FreeWorld(g_world);

    ECS_Container *globalECS = ECS_CreateECS();

    ECS_COMPONENT_Transform_Add(globalECS);
    ECS_COMPONENT_Metaproperties_Add(globalECS);

    ECS_Destroy(globalECS);

    return 0;
}