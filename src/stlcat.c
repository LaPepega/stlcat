#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <time.h>

#include "solid.h"
#include "render.h"
#include "terminal.h"

#define DEPTH_COLOR(Z) (255 + (Z * 10)) <= 232 ? 232 : (255 + (Z * 10))

// FIXME: y changes when all p c and t in the same plain
int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Not enough args");
        return 1;
    }

    double read_time, render_time;
    clock_t start = clock();

    // solid sol = solid_new_from_file_bin(argv[1]);

    /*vec3 target = VEC3(
        strtof(argv[1], NULL),
        strtof(argv[2], NULL),
        strtof(argv[3], NULL));*/

    vec3 camera = VEC3(2, 0, 0);
    vec3 target = VEC3(0, 0, 0);
    canvas c = canvas_new_of_size(VEC2U(300, 170));

    float fov = strtof(argv[1], NULL);
    solid s = solid_new_from_file_bin(argv[2]);

    clock_t end = clock();
    read_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    start = clock();

    for (size_t i = 0; i < s.n_tris; i++)
    {
        vec3 p1_cam = r_vec3localize(&s.tris[i].p1, &camera, &target);
        vec3 p2_cam = r_vec3localize(&s.tris[i].p2, &camera, &target);
        vec3 p3_cam = r_vec3localize(&s.tris[i].p2, &camera, &target);

        vec2u p1_proj = r_vec3proj(&p1_cam, fov, &c.size);
        vec2u p2_proj = r_vec3proj(&p2_cam, fov, &c.size);
        vec2u p3_proj = r_vec3proj(&p3_cam, fov, &c.size);

        canvas_set_vec2u(&c, &p1_proj, DEPTH_COLOR(p1_cam.z));
        canvas_set_vec2u(&c, &p2_proj, DEPTH_COLOR(p2_cam.z));
        canvas_set_vec2u(&c, &p3_proj, DEPTH_COLOR(p3_cam.z));
    }
    end = clock();

    canvas_print(&c);

    render_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("tris:%lu, points:%lu, read_ms: %lf, render_ms: %lf\n", s.n_tris, s.n_tris * 3, read_time, render_time);

    canvas_free(&c);
    solid_free(&s);

    return 0;
}
