#pragma once

#include <stdio.h>
#include <string.h>

#include "vec2.h"

#define CH_BLOCK_UHALF "\u2580"
#define CH_BLOCK_LHALF "\u2584"
#define CH_BLOCK_FULL "\u2588"

enum terminal_commmon_color
{
    TC_BLACK = 0,
    TC_MAROON = 1,
    TC_GREEN = 2,
    TC_OLIVE = 3,
    TC_NAVY = 4,
    TC_PURPLE = 5,
    TC_TEAL = 6,
    TC_SILVER = 7,
    TC_GREY = 8,
    TC_RED = 9,
    TC_LIME = 10,
    TC_YELLOW = 11,
    TC_BLUE = 12,
    TC_FUCHSIA = 13,
    TC_AQUA = 14,
    TC_WHITE = 15
};

#define ANSI_SET_FG(id) "\e[38;5;" #id "m"
#define ANSI_SET_BG(id) "\e[48;5;" #id "m"

typedef unsigned char color256;

const char *ansi_setfg_str(color256 color);
const char *ansi_setbg_str(color256 color);

typedef struct canvas
{
    color256 *cells;
    vec2u size;
} canvas;

#define CANVAS(C, S) \
    (canvas) { .cells = C, .size = S }

#define CANVAS_COORD_IDX(WIDTH, X, Y) (Y * WIDTH + X)

#define CANVAS_SET(C, X, Y, COLOR) \
    C.cells[CANVAS_COORD_IDX(C.size.x, X, Y)] = COLOR

// FIXME: find safe snprintf() alternative

unsigned int canvas_vec2u_idx(vec2u *size, vec2u *v);
unsigned int canvas_coord_idx(unsigned int w, unsigned int h, unsigned int x, unsigned int y);

canvas canvas_new_of_size(vec2u s);
void canvas_free(canvas *c);

void canvas_set(canvas *c, unsigned int x, unsigned int y, color256 color);
void canvas_set_vec2u(canvas *c, vec2u *pos, color256 color);

void canvas_print(canvas *c);