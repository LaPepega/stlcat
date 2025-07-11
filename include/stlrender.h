#pragma once

#include "vec2.h"
#include "vec3.h"
#include "terminal.h"

typedef struct canvas
{
    color256 *cells;
    vec2u size;
} canvas;

vec3 r_vec3localize(vec3 v, vec3 c_pos, vec3 c_target);
vec2 r_vec3proj(vec3 v, float fl, vec2 screen);
vec3 r_mat4x4_mul_vec3(float mat4x4[4][4], vec3 v);