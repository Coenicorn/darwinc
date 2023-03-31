#ifndef COMPONENTDEF_H
#define COMPONENTDEF_H

#include "components.h"

// Every component needs to be given an ID
// in this struct, which systems will use
// to identify components
typedef enum
{
    Metaproperties_id               = 1,
    Transform_id                    = 2
} ECS_COMPONENT_IDS;

typedef struct Metaproperties
{
    const char *name;
} Metaproperties;

typedef struct Transform
{
    Vec3 position, rotation, scale;
} Transform;

ECS_COMPONENT_INITIALIZE(Metaproperties, Metaproperties_id)
ECS_COMPONENT_INITIALIZE(Transform, Transform_id)



#endif