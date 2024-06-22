#include <verifier-builtins.h>
#include <stddef.h>
#include <stdlib.h>

int main()
{
    int *p = malloc(40*sizeof(int));

    int **t;
    int ***h;
    t = &p;
    h = &t;

    p[2];
    (*t)[2];
    (*(*h))[2];

    return 0;
}
