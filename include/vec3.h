typedef struct vec3
{
    float x;
    float y;
    float z;
} vec3;

#define VEC3_X (vec3){.x = 1.0f, .y = 0.0f, .z = 0.0f}
#define VEC3_Y (vec3){.x = 0.0f, .y = 1.0f, .z = 0.0f}
#define VEC3_Z (vec3){.x = 0.0f, .y = 0.0f, .z = 1.0f}
#define VEC3_ZERO (vec3){.x = 0.0f, .y = 0.0f, .z = 0.0f}

#define VEC3(X, Y, Z) \
    (vec3) { .x = X, .y = Y, .z = Z }

float vec3mag(vec3 v);
float vec3dot(vec3 a, vec3 b);
float vec3cos(vec3 a, vec3 b);
float vec3ang(vec3 a, vec3 b);
float vec3sin(vec3 a, vec3 b);
vec3 vec3cross(vec3 a, vec3 b);