#include <stdio.h>
#include <stdlib.h>

#include "solid.h"

solid solid_new_from_file_bin(const char *path)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
        return SOLID_ZERO;

    // skip first 80 bytes - the header
    if (fseek(f, 80, SEEK_SET) != 0)
    {
        fclose(f);
        return SOLID_ZERO;
    }

    unsigned long n_facets = 0;
    if (fread(&n_facets, 4, 1, f) == 0)
    {
        fclose(f);
        return SOLID_ZERO;
    }

    solid s = SOLID(n_facets, malloc(sizeof(tri) * n_facets));

    for (unsigned long i = 0; i < n_facets; i++)
    {
        if (
            fread(&s.tris[i].normal.x, 4, 1, f) == 0 ||
            fread(&s.tris[i].normal.y, 4, 1, f) == 0 ||
            fread(&s.tris[i].normal.z, 4, 1, f) == 0 ||

            fread(&s.tris[i].p1.x, 4, 1, f) == 0 ||
            fread(&s.tris[i].p1.y, 4, 1, f) == 0 ||
            fread(&s.tris[i].p1.z, 4, 1, f) == 0 ||

            fread(&s.tris[i].p2.x, 4, 1, f) == 0 ||
            fread(&s.tris[i].p2.y, 4, 1, f) == 0 ||
            fread(&s.tris[i].p2.z, 4, 1, f) == 0 ||

            fread(&s.tris[i].p3.x, 4, 1, f) == 0 ||
            fread(&s.tris[i].p3.y, 4, 1, f) == 0 ||
            fread(&s.tris[i].p3.z, 4, 1, f) == 0)
        {
            fclose(f);
            free(s.tris);
            return SOLID_ZERO;
        }

        unsigned int attr;
        fread(&attr, 2, 1, f);
    }

    fclose(f);
    return s;
}

void solid_free(solid *s)
{
    s->n_tris = 0;
    free(s->tris);
}