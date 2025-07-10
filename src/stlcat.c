#include <stdlib.h>
#include <stdio.h>

#include "stl3d.h"
#include "terminal.h"

int main(int argc, char const *argv[])
{

    for (color256 i = 0; i < 128; i++)
    {
        printf("%s%s" CH_BLOCK_UHALF,
               ansi_setfg_str(i), ansi_setbg_str(i + 128));
    }

    return 0;
}
