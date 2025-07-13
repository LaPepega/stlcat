#pragma once

#include <stdlib.h>
#include <argp.h>

const char *argp_program_version = "stlcat 0.0.1";
const char *argp_program_bug_address = "https://github.com/LaPepega/stlcat/issues";
static char doc[] = "Render an .stl file right into your terminal";
static char args_doc[] = "<path/to/file.stl>";

static struct argp_option options[] = {
    {"stats", 's', 0, 0, "Show render stats", 0},
    {"width", 'w', "WIDTH", 0, "Render width in pixels\t\tdefault: 100", 0},
    {"height", 'h', "HEIGHT", 0, "Render height in pixels\t\tdefault: 100", 0},
    {"camX", 'x', "CAMX", 0, "Camera's position along X axis\tdefault: 2", 0},
    {"camY", 'y', "CAMY", 0, "Camera's position along Y axis\tdefault: 0", 0},
    {"camZ", 'z', "CAMZ", 0, "Camera's position along Z axis\tdefault: 0", 0},
    {"fov", 'f', "FOV", 0, "Camera's FOV (smaller number = wider angle)\tdefault: 20", 0},
    {0}};

struct arguments
{
    bool stats_enabled;
    unsigned long width, height;
    float cam_x, cam_y, cam_z, fov;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *args = (struct arguments *)state->input;
    switch (key)
    {
    case 's':
        args->stats_enabled = true;
        break;
    case 'w':
        args->width = strtoul(arg, NULL, 10);
        break;
    case 'h':
        args->height = strtoul(arg, NULL, 10);
        break;
    case 'x':
        args->cam_x = strtof(arg, NULL);
        break;
    case 'y':
        args->cam_y = strtof(arg, NULL);
        break;
    case 'z':
        args->cam_z = strtof(arg, NULL);
        break;
    case 'f':
        args->fov = strtof(arg, NULL);
        break;

    case ARGP_KEY_INIT:
        break;

    case ARGP_KEY_NO_ARGS:
        argp_error(state, "No file specified");
        break;

    case ARGP_KEY_FINI:
        break;

    case ARGP_KEY_END:
        break;

    case ARGP_KEY_SUCCESS:
        break;

    case ARGP_KEY_ARG:
        break;

    default:
        argp_usage(state);
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {
    .options = options,
    .parser = parse_opt,
    .args_doc = args_doc,
    .doc = doc,
    .children = 0,
    .help_filter = 0,
    .argp_domain = 0};
