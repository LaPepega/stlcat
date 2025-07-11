#pragma once

#include <stdio.h>
#include <string.h>

#define CH_BLOCK_UHALF "\u2580"
#define CH_BLOCK_LHALF "\u2584"
#define CH_BLOCK_FULL "\u2588"

#define ANSI_SET_FG(id) "\e[38;5;" #id "m"
#define ANSI_SET_BG(id) "\e[48;5;" #id "m"

typedef unsigned char color256;

// FIXME: find safe snprintf() alternative

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