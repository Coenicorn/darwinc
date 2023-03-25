#ifndef ECS_COMPONENTS_H
#define ECS_COMPONENTS_H

#include "vec3.h"
#include "dyve.h"

// Every component needs to be given an ID
// in this struct, which systems will use
// to identify components
typedef enum
{
    ECS_COMPONENT_Transform_id              = 1,
    ECS_COMPONENT_Metaproperties_id         = 2
} ECS_COMPONENT_IDS;





typedef struct ECS_COMPONENT_Metaproperties
{
    const char *name;
} ECS_COMPONENT_Metaproperties;

typedef DYVE_NEWTYPE(ECS_COMPONENT_Metaproperties) 

typedef struct ECS_COMPONENT_Transform
{
    DC_Vec3 position, rotation;
} ECS_COMPONENT_Transform;

#endif