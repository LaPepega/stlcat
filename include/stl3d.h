#pragma once
#include <stdint.h>

typedef struct stl3d_vec3
{
    float x;
    float y;
    float z;
} stl_vec3;

typedef struct stl3d_facet
{
    stl_vec3 p1;
    stl_vec3 p2;
    stl_vec3 p3;
    stl_vec3 normal;
} stl_facet;
