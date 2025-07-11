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

#define VEC3_PRINT(v) printf("(%.2f, %.2f, %.2f)", v.x, v.y, v.z)
#define VEC3_PPRINT(v) printf("x: %.2f\ny: %.2f\nz: %.2f\n", v.x, v.y, v.z)

float vec3mag(vec3 v);
float vec3dot(vec3 a, vec3 b);
float vec3cos(vec3 a, vec3 b);
float vec3ang(vec3 a, vec3 b);
float vec3sin(vec3 a, vec3 b);

vec3 vec3add(vec3 a, vec3 b);
vec3 vec3sub(vec3 a, vec3 b);
vec3 vec3cross(vec3 a, vec3 b);
vec3 vec3norm(vec3 v);
int vec3make_norm(vec3 *v);
vec3 vec3perp_unit(vec3 a, vec3 b);