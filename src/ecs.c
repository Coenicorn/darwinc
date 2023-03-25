#include <stdlib.h>
#include <stdio.h>

#include "ecs.h"
#include "log.h"
#include "dyve.h";

// Initial size of entity array
#define ECS_ENTITYSTARTCOUNT 256

ECS_Container *ECS_CreateECS(void)
{
    ECS_Container *outContainer = malloc(sizeof(ECS_Container));

    DYVE_Init(outContainer->components, 8);
    DYVE_Init(outContainer->entities, ECS_ENTITYSTARTCOUNT);
    DYVE_Init(outContainer->systems, 4);

    outContainer->nextEntityID = 0;
}

void ECS_AddComponentContainer(ECS_Container *container, ECS_ComponentID_t id)
{
    // // safety check
    // if (id >= container->nContainers)
    // {
    //     int oldLen = container->nContainers;
    //     container->nContainers += 4;

    //     // allocate more memory
    //     ECS_ComponentContainer *new = realloc(container->componentContainers, sizeof(ECS_ComponentContainer) * container->nContainers);
    
    //     if (new == NULL)
    //     {
    //         DC_Log("Failed to allocate more memory for container");

    //         return;
    //     }

    //     // initialize memory
    //     for (int i = oldLen; i < container->nContainers; i++)
    //         container->componentContainers[i] = (ECS_ComponentContainer){ .components = NULL, .id = 0, .size = 0 };

    //     container->componentContainers = new;
    // }

    // // check if already exists
    // if (container->componentContainers[id].components != NULL)
    //     return;

}


void ECS_CreateComponent(ECS_Container *ecs, ECS_ComponentID_t id, void *componentArray)
{
    
}



void ECS_Destroy(ECS_Container *ecs)
{
    // free all systems
    for (int i = 0; i < ecs->systems.size; i++)
    {
        DYVE_Free(ecs->systems.data[i].entities);
    }
    
    // free all components
    for (int i = 0; i < ecs->components.size; i++)
    {
        ecs->components.data[i].destroy();
    }

    DYVE_Free(ecs->components);
    DYVE_Free(ecs->entities);
    DYVE_Free(ecs->systems);
}