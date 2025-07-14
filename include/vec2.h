#pragma once

typedef struct vec2
{
    float x;
    float y;
} vec2;

#define VEC2(X, Y) \
    (vec2) { .x = X, .y = Y }

#define VEC2_ZERO (vec2){.x = 0.0f, .y = 0.0f}
#define VEC2_X (vec2){.x = 1.0f, .y = 0.0f}
#define VEC2_Y (vec2){.x = 0.0f, .y = 1.0f}

#define VEC2_PRINT(v) printf("(%.2f, %.2f)", v.x, v.y)
#define VEC2_PPRINT(v) printf("x: %.2f\ny: %.2f\n", v.x, v.y)

typedef struct vec2i
{
    int x;
    int y;
} vec2i;

#define VEC2I(X, Y) \
    (vec2i) { .x = X, .y = Y }

#define VEC2I_ZERO (vec2i){.x = 0, .y = 0}
#define VEC2I_X (vec2i){.x = 1, .y = 0}
#define VEC2I_Y (vec2i){.x = 0, .y = 1}

#define VEC2I_PRINT(v) printf("(%d, %d)", v.x, v.y)
#define VEC2I_PPRINT(v) printf("x: %d\ny: %d\n", v.x, v.y)

typedef struct vec2u
{
    unsigned int x;
    unsigned int y;
} vec2u;

#define VEC2U(X, Y) \
    (vec2u) { .x = X, .y = Y }

#define VEC2U_ZERO (vec2u){.x = 0, .y = 0}
#define VEC2U_X (vec2u){.x = 1, .y = 0}
#define VEC2U_Y (vec2u){.x = 0, .y = 1}

#define VEC2U_PRINT(v) printf("(%u, %u)", v.x, v.y)
#define VEC2U_PPRINT(v) printf("x: %u\ny: %u\n", v.x, v.y)