#include <stdlib.h>
#include <stdio.h>

#include "solid.h"
#include "render.h"
#include "terminal.h"

// FIXME: y changes when all p c and t in the same plain
int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Not enough args");
        return 1;
    }

    // solid sol = solid_new_from_file_bin(argv[1]);
    vec3 camera = VEC3(2, 0, 0);

    /*vec3 target = VEC3(
        strtof(argv[1], NULL),
        strtof(argv[2], NULL),
        strtof(argv[3], NULL));*/

    vec3 target = VEC3(0, 0, 0);

    canvas c = canvas_new_of_size(VEC2U(100, 100));
    solid s = solid_new_from_file_bin(argv[1]);

    for (size_t i = 0; i < s.n_tris; i++)
    {
        vec3 p1_cam = r_vec3localize(s.tris[i].p1, camera, target);
        vec3 p2_cam = r_vec3localize(s.tris[i].p2, camera, target);
        vec3 p3_cam = r_vec3localize(s.tris[i].p2, camera, target);

        canvas_set_vec2u(&c, r_vec3proj(p1_cam, 20, c.size), TC_WHITE);
        canvas_set_vec2u(&c, r_vec3proj(p2_cam, 20, c.size), TC_WHITE);
        canvas_set_vec2u(&c, r_vec3proj(p3_cam, 20, c.size), TC_WHITE);
    }

    canvas_print(&c);

    canvas_free(&c);
    solid_free(&s);

    return 0;
}
