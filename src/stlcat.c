#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "stlcat_args.h"
#include "solid.h"
#include "render.h"
#include "terminal.h"

int main(int argc, char *argv[])
{
    struct arguments args = {
        .cam_x = 2.0f,
        .cam_y = 0.0f,
        .cam_z = 0.0f,
        .fov = 20,
        .height = 100,
        .width = 100,
        .stats_enabled = false,
    };

    argp_parse(&argp, argc, argv, 0, 0, &args);

    double read_time, render_time;
    clock_t start, end;

    vec3 camera = VEC3(args.cam_x, args.cam_y, args.cam_z);
    vec3 target = VEC3(0, 0, 0);
    canvas c = canvas_new_of_size(VEC2U(args.width, args.height));

    start = clock();
    solid s = solid_new_from_file_bin(argv[argc - 1]);
    end = clock();

    read_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    start = clock();
    canvas_render_solid(&c, &s, &camera, &target, args.fov);
    end = clock();

    render_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    canvas_print(&c);

    if (args.stats_enabled)
    {
        printf("tris:%lu, points:%lu, read_ms: %lf, render_ms: %lf\n", s.n_tris, s.n_tris * 3, read_time, render_time);
    }

    canvas_free(&c);
    solid_free(&s);

    return 0;
}
