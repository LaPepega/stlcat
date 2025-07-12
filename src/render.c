#include "solid.h"
#include "vec2.h"
#include "render.h"

vec3 r_mat4x4_mul_vec3(float mat4x4[4][4], vec3 v)
{
    return VEC3(
        v.x * mat4x4[0][0] +
            v.y * mat4x4[1][0] +
            v.z * mat4x4[2][0] +
            mat4x4[3][0],

        v.x * mat4x4[0][1] +
            v.y * mat4x4[1][1] +
            v.z * mat4x4[2][1] +
            mat4x4[3][1],

        v.x * mat4x4[0][2] +
            v.y * mat4x4[1][2] +
            v.z * mat4x4[2][2] +
            mat4x4[3][2]);
}

// vec3 in camera space
vec3 r_vec3localize(vec3 v, vec3 c_pos, vec3 c_target)
{
    vec3 forward = vec3norm(vec3sub(c_pos, c_target));
    vec3 right = vec3perp_unit(VEC3_Z, forward);
    vec3 up = vec3perp_unit(forward, right);

    float mat4x4[4][4] = {{right.x, up.x, forward.x, 0},
                          {right.y, up.y, forward.y, 0},
                          {right.z, up.z, forward.z, 0},
                          {-vec3dot(right, c_pos),
                           -vec3dot(up, c_pos),
                           -vec3dot(forward, c_pos), 1}};

    return r_mat4x4_mul_vec3(mat4x4, v);
}

// v must be in camera space
vec2u r_vec3proj(vec3 v, float focal_len, vec2u screen)
{
    return VEC2U((v.x * focal_len) / v.z + (screen.x / 2),
                 (v.y * focal_len) / v.z + (screen.y / 2));
}