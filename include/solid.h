#include "tri.h"

typedef struct solid
{
    unsigned long n_tris;
    tri *tris;
    // unsigned int* attrs // usually unused
} solid;

#define SOLID(N, TRIS) \
    (solid) { .n_tris = N, .tris = TRIS }
#define SOLID_ZERO \
    (solid) { .n_tris = 0, .tris = NULL }

#define SOLID_PPRINT(S)                          \
    printf("tris: %lu\n\n", S.n_tris);           \
    for (unsigned long i = 0; i < S.n_tris; i++) \
    {                                            \
        TRI_PPRINT(S.tris[i]);                   \
        printf("\n");                            \
    }

solid solid_new_from_file_bin(const char *path);
solid solid_new_from_file_ascii(const char *path);

void solid_free(solid *s);