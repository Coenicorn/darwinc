/*
    Dyve is a DYnamic VEctor implementation in C/C++

    Copyright (C) 2023 Coenicorn

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied w(arr)anty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/*
    Usage


    #include "dyve.h"

    // type name customizable
    typedef DYVE_NEWTYPE(int) intarr_t;

    // initialization with initial size
    intArr arr;
    DYVE_Init(arr, 5);

    // push value to array
    DYVE_Push(arr, 5);
    DYVE_Push(arr, 9);
    DYVE_Push(arr, 27);

    // remove value at index
    DYVE_Remove(arr, 1);

    printf("%i\n", arr.data[0])     // 5
    printf("%i\n", arr.data[1])     // 27

    printf("%u\n", arr.size)        // 2


    Some variables can be adjusted to fit bigger array entries:

    DYVE_MAXSIZEDIFFERENCE -> The allowed size difference beween the buffer size and the used size of the array.
    When low, more memory allocation will happen (depending on the activity), but memory will be saved. When large,
    more memory will go unused, but future allocations will be faster until the buffer end is reached.

*/

#ifndef DYVE_H
#define DYVE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define DYVE_MAXSIZE __UINT32_MAX__

#ifndef DYVE_MAXSIZEDIFFERENCE
#define DYVE_MAXSIZEDIFFERENCE 16
#endif

#define DYVE_NEWTYPE(_TYPE) struct { uint32_t size, bufSize; _TYPE *data; }

/* Initializes (arr). Needs be called for every DYVE */
#define DYVE_Init(arr, _SIZE)\
{\
    (arr).size = 0;\
    (arr).bufSize = _SIZE;\
    (arr).data = malloc(sizeof((*(arr).data)) * _SIZE);\
}\

#define DYVE_Resize(arr, _SIZE)\
{\
    uint32_t DYVE_LOCAL_newLen = (arr).bufSize + (uint32_t) _SIZE;\
\
    if (DYVE_LOCAL_newLen >= DYVE_MAXSIZE)\
    {\
        printf("DYVE: Array too long");\
    }\
\
    void *DYVE_LOCAL_newData = realloc((arr).data, sizeof(*((arr).data)) * DYVE_LOCAL_newLen);\
\
    if (DYVE_LOCAL_newData == NULL)\
    {\
        printf("DYVE: Failed to allocate memory");\
    }\
    else\
    {\
        (arr).bufSize = DYVE_LOCAL_newLen;\
        (arr).data = DYVE_LOCAL_newData;\
    }\
}\

/* Pushes val to head of (arr) */
#define DYVE_Push(arr, val)\
{\
    if ((arr).size > (arr).bufSize)\
        DYVE_Resize((arr), (arr).size + DYVE_MAXSIZEDIFFERENCE);\
\
    (arr).data[(arr).size++] = val;\
}\

/* Removes (arr)[index] from (arr) */
#define DYVE_Remove(arr, index)\
{\
    if (index > (arr).size || index < 0)\
    {\
        printf("DYVE: Index outside (arr)ay bounds\n");\
    }\
    else\
    {\
\
        for (uint32_t DYVE_LOCAL_i = index; DYVE_LOCAL_i < (arr).size-1; DYVE_LOCAL_i++)\
        {\
            (arr).data[DYVE_LOCAL_i] = (arr).data[DYVE_LOCAL_i+1];\
        }\
\
        (arr).size--;\
\
        if (((arr).bufSize - (arr).size) > DYVE_MAXSIZEDIFFERENCE)\
            DYVE_Resize(arr, (arr).bufSize - DYVE_MAXSIZEDIFFERENCE);\
    }\
}\

#define DYVE_Free(arr)\
{\
    free((arr).data);\
}\

#endif