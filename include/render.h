#pragma once

#include "vec2.h"
#include "terminal.h"

typedef struct canvas
{
    color256 *cells;
    vec2u size;
} canvas;