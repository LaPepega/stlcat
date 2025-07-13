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

    float normal_buf[3], p1_buf[3], p2_buf[3], p3_buf[3];
    unsigned int attr;

    for (unsigned long i = 0; i < n_facets; i++)
    {
        if (
            fread(normal_buf, 4, 3, f) == 0 ||
            fread(p1_buf, 4, 3, f) == 0 ||
            fread(p2_buf, 4, 3, f) == 0 ||
            fread(p3_buf, 4, 3, f) == 0 ||
            fread(&attr, 2, 1, f) == 0)
        {
            fclose(f);
            free(s.tris);
            return SOLID_ZERO;
        }

        s.tris[i].normal.x = normal_buf[0];
        s.tris[i].normal.y = normal_buf[1];
        s.tris[i].normal.z = normal_buf[2];

        s.tris[i].p1.x = p1_buf[0];
        s.tris[i].p1.y = p1_buf[1];
        s.tris[i].p1.z = p1_buf[2];

        s.tris[i].p2.x = p2_buf[0];
        s.tris[i].p2.y = p2_buf[1];
        s.tris[i].p2.z = p2_buf[2];

        s.tris[i].p3.x = p3_buf[0];
        s.tris[i].p3.y = p3_buf[1];
        s.tris[i].p3.z = p3_buf[2];
    }

    fclose(f);
    return s;
}

void solid_free(solid *s)
{
    s->n_tris = 0;
    free(s->tris);
}