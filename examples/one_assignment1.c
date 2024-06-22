#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *a = NEW(int);
    int **p;
    p = &a;

    return 0;
}
