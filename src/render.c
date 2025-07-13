#include "render.h"

vec3 r_mat4x4_mul_vec3(float mat4x4[4][4], vec3 *v)
{
    return VEC3(
        v->x * mat4x4[0][0] +
            v->y * mat4x4[1][0] +
            v->z * mat4x4[2][0] +
            mat4x4[3][0],

        v->x * mat4x4[0][1] +
            v->y * mat4x4[1][1] +
            v->z * mat4x4[2][1] +
            mat4x4[3][1],

        v->x * mat4x4[0][2] +
            v->y * mat4x4[1][2] +
            v->z * mat4x4[2][2] +
            mat4x4[3][2]);
}

// vec3 in camera space
vec3 r_vec3localize(vec3 *v, vec3 *c_pos, vec3 *c_target)
{
    vec3 f = vec3sub(c_pos, c_target);
    vec3 forward = vec3norm(&f);

    vec3 z = VEC3_Z;
    vec3 right = vec3perp_unit(&z, &forward);

    vec3 up = vec3perp_unit(&forward, &right);

    float mat4x4[4][4] = {{right.x, up.x, forward.x, 0},
                          {right.y, up.y, forward.y, 0},
                          {right.z, up.z, forward.z, 0},
                          {-vec3dot(&right, c_pos),
                           -vec3dot(&up, c_pos),
                           -vec3dot(&forward, c_pos), 1}};

    return r_mat4x4_mul_vec3(mat4x4, v);
}

// v must be in camera space
vec2u r_vec3proj(vec3 *v, float fov, vec2u *screen)
{
    return VEC2U((v->x * fov) / v->z + (screen->x / 2),
                 (v->y * fov) / v->z + (screen->y / 2));
}

void canvas_render_solid(canvas *c, solid *s, vec3 *camera, vec3 *target, float fov)
{
    for (size_t i = 0; i < s->n_tris; i++)
    {
        vec3 p1_cam = r_vec3localize(&s->tris[i].p1, camera, target);
        vec3 p2_cam = r_vec3localize(&s->tris[i].p2, camera, target);
        vec3 p3_cam = r_vec3localize(&s->tris[i].p2, camera, target);

        vec2u p1_proj = r_vec3proj(&p1_cam, fov, &c->size);
        vec2u p2_proj = r_vec3proj(&p2_cam, fov, &c->size);
        vec2u p3_proj = r_vec3proj(&p3_cam, fov, &c->size);

        canvas_set_vec2u(c, &p1_proj, DEPTH_COLOR(p1_cam.z));
        canvas_set_vec2u(c, &p2_proj, DEPTH_COLOR(p2_cam.z));
        canvas_set_vec2u(c, &p3_proj, DEPTH_COLOR(p3_cam.z));
    }
}