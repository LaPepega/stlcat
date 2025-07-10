#include <math.h>
#include "vec3.h"

float vec3mag(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}
float vec3dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float vec3cos(vec3 a, vec3 b)
{
    float mp = vec3mag(a) * vec3mag(b);
    if (mp == 0.0f)
        return 0.0f;
    return vec3dot(a, b) / mp;
}

float vec3ang(vec3 a, vec3 b)
{
    return acosf(vec3cos(a, b));
}

float vec3sin(vec3 a, vec3 b)
{
    float cos = vec3cos(a, b);
    return sqrtf(1 - cos * cos);
}

vec3 vec3cross(vec3 a, vec3 b)
{
    return (vec3){
        .x = (a.y * b.z - a.z * b.y),
        .y = (a.z * b.x - a.x * b.z),
        .z = (a.x * b.y - a.y * b.x)};
}