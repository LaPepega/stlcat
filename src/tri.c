#include "tri.h"
/*
tri tri_init(vec3 p1, vec3 p2, vec3 p3)
{
    vec3 v1 = vec3sub(p1, p2);
    vec3 v2 = vec3sub(p1, p3);

    return (tri){
        .normal = vec3perp_unit(v1, v2),
        .p1 = p1,
        .p2 = p2,
        .p3 = p3};
}
*/

int tri_calc_normal(tri *t)
{
    t->normal = vec3perp_unit(vec3sub(t->p1, t->p2), vec3sub(t->p1, t->p3));
    return 0;
}