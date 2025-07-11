#include <stdlib.h>
#include <stdio.h>

#include "solid.h"
#include "terminal.h"

int main(int argc, char const *argv[])
{
    solid s = solid_new_from_file_bin(argv[1]);

    SOLID_PPRINT(s);

    solid_free(&s);
    return 0;
}
