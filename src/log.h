#ifndef DC_LOG_H
#define DC_LOG_H

#include <stdio.h>

/* Logs a message */
static inline void DC_Log(const char *message)
{
    printf("DarwinC: %s\n", message);
}

#endif