#include <stdlib.h>
#include <stdio.h>

#include "solid.h"
#include "stlrender.h"

int main(int argc, char const *argv[])
{
    vec3 origin = VEC3_ZERO;
    vec3 camera = VEC3(10, 1, 5);

    VEC3_PPRINT(r_vec3localize(origin, camera, VEC3(0, 1, 0)));

    return 0;
}
