#include <stdlib.h>
#include <stdio.h>

#include "tri.h"
#include "terminal.h"

int main(int argc, char const *argv[])
{
    vec3 a = VEC3(10, 2, 1);
    vec3 b = VEC3(6, 5, 1);
    vec3 c = VEC3(5, 6, 1);

    tri t = TRI(a, b, c, 0);
    tri_calc_normal(&t);
    TRI_PPRINT(t);
    return 0;
}
