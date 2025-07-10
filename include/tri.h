#pragma once
#include "vec3.h"

typedef struct tri
{
    vec3 p1;
    vec3 p2;
    vec3 p3;
    vec3 normal;
} tri;

#define TRI_ZERO            \
    (tri)                   \
    {                       \
        .p1 = VEC3_ZERO,    \
        .p2 = VEC3_ZERO,    \
        .p3 = VEC3_ZERO,    \
        .normal = VEC3_ZERO \
    }

#define TRI(P1, P2, P3, N) \
    (tri) { .p1 = P1, .p2 = P2, .p3 = P3, .normal = N }

#define TRI_FROM_POINTS(P1, P2, P3) \
    TRI(P1, P2, P3, vec3perp_unit(vec3sub(P1, P2), vec3sub(P1, P3)))

#define TRI_PPRINT(t) \
    printf("p1:\t");  \
    VEC3_PRINT(t.p1); \
    printf("p2:\t");  \
    VEC3_PRINT(t.p2); \
    printf("p3:\t");  \
    VEC3_PRINT(t.p3); \
    printf("n:\t");   \
    VEC3_PRINT(t.normal);

int tri_calc_normal(tri *t);