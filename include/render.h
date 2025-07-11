#pragma once

#include "vec2.h"
#include "vec3.h"

vec3 r_vec3localize(vec3 v, vec3 c_pos, vec3 c_target);
vec2u r_vec3proj(vec3 v, float focal_len, vec2u screen);
