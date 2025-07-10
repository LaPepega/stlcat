#pragma once
#include "vec3.h"

typedef struct stl3d_facet
{
    vec3 p1;
    vec3 p2;
    vec3 p3;
    vec3 normal;
} stl_facet;
