#include <stdlib.h>
#include <stdio.h>

#include "stl3d.h"
#include "terminal.h"

int main(int argc, char const *argv[])
{
    vec3 a = VEC3(10, 2, 1);
    vec3 b = VEC3(6, 5, 1);
    vec3 c = vec3cross(a, b);

    printf("x:%.2f\ny:%.2f\nz:%.2f\n", c.x, c.y, c.z);

    return 0;
}
