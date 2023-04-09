#ifndef ECS_LOG_H
#define ECS_LOG_H

#include "stdio.h"

static inline void ECS_Log(const char *msg)
{
    printf("%s\n", msg);
}

#endif