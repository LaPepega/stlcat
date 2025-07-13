#include "terminal.h"
#include "stdlib.h"

const char *ansi_setfg_str(color256 color)
{
    static char str[12];
    snprintf(str, 12, "\e[38;5;%dm", color);

    return str;
}

const char *ansi_setbg_str(color256 color)
{
    static char str[12];
    snprintf(str, 12, "\e[48;5;%dm", color);

    return str;
}

unsigned int canvas_coord_idx(unsigned int w, unsigned int h, unsigned int x, unsigned int y)
{
    if (x > w || y > h)
        return 0;
    return y * w + x;
}

unsigned int canvas_vec2u_idx(vec2u *size, vec2u *pos)
{
    return canvas_coord_idx(size->x, size->y, pos->x, pos->y);
}

canvas canvas_new_of_size(vec2u s)
{
    return CANVAS(
        malloc(sizeof(color256) * s.x * s.y), s);
}

void canvas_free(canvas *c)
{
    free(c->cells);
    c->size = VEC2U_ZERO;
}

void canvas_set(canvas *c, unsigned int x, unsigned int y, color256 color)
{
    c->cells[canvas_coord_idx(c->size.x, c->size.y, x, y)] = color;
}

void canvas_set_vec2u(canvas *c, vec2u *pos, color256 color)
{
    c->cells[canvas_vec2u_idx(&c->size, pos)] = color;
}

void canvas_print(canvas *c)
{
    for (unsigned int y = 0; y < c->size.y; y += 2)
    {
        for (unsigned int x = 0; x < c->size.x; x++)
        {
            printf("%s%s" CH_BLOCK_UHALF,
                   ansi_setfg_str(c->cells[canvas_coord_idx(
                       c->size.x, c->size.y,
                       x, y)]),
                   ansi_setbg_str(c->cells[canvas_coord_idx(
                       c->size.x, c->size.y,
                       x, y + 1)]));
        }
        printf(ANSI_SET_BG(235) ANSI_SET_FG(235) "\n");
    }
    printf(ANSI_SET_BG(235) ANSI_SET_FG(15));
}