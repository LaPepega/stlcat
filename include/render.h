#pragma once

#include "solid.h"
#include "terminal.h"
#include "vec2.h"
#include "vec3.h"

#define DEPTH_COLOR(Z) (255 + (Z * 10)) <= 232 ? 232 : (255 + (Z * 10))

vec3 r_vec3localize(vec3 *v, vec3 *c_pos, vec3 *c_target);
vec2u r_vec3proj(vec3 *v, float fov, vec2u *screen_size);
void canvas_render_solid(canvas *c, solid *s, vec3 *camera, vec3 *target, float fov);
