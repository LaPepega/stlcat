#include <stdlib.h>
#include <stdio.h>

#include "solid.h"
#include "render.h"
#include "terminal.h"

// FIXME: y changes when all p c and t in the same plain
int main(int argc, char const *argv[])
{

    if (argc < 4)
    {
        printf("Not enough args");
        return 1;
    }

    // solid sol = solid_new_from_file_bin(argv[1]);
    vec3 camera = VEC3(2, 0, 0);

    vec3 target = VEC3(
        strtof(argv[1], NULL),
        strtof(argv[2], NULL),
        strtof(argv[3], NULL));

    vec3 origin_in_cam_space = r_vec3localize(VEC3_ZERO, camera, target);
    // VEC3_PPRINT(origin_in_cam_space);
    // printf("\n");

    // VEC3_PPRINT(cam_space);
    // VEC2U_PPRINT(r_vec3proj(origin_in_cam_space, 60, screen));

    canvas c = canvas_new_of_size(VEC2U(16, 16));

    canvas_set_vec2u(&c, r_vec3proj(origin_in_cam_space, 60, c.size), TC_WHITE);

    canvas_print(&c);
    canvas_free(&c);

    return 0;
}
