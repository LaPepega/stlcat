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

#define TRI_FROM_POINTS(P1, P2, P3)       \
    (tri) { .p1 = P1, .p2 = P2, .p3 = P3, \
            .normal = vec3perp_unit(vec3sub(P2, P1), vec3sub(P3, P1)) }

#define TRI_PRINT(t)  \
    VEC3_PRINT(t.p1); \
    VEC3_PRINT(t.p2); \
    VEC3_PRINT(t.p2); \
    VEC3_PRINT(t.normal);

#define TRI_PPRINT(t)     \
    printf("p1:\t");      \
    VEC3_PRINT(t.p1);     \
    printf("\np2:\t");    \
    VEC3_PRINT(t.p2);     \
    printf("\np3:\t");    \
    VEC3_PRINT(t.p3);     \
    printf("\nn:\t");     \
    VEC3_PRINT(t.normal); \
    printf("\n");

int tri_calc_normal(tri *t);