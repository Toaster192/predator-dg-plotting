#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int main()
{
    int *a = NEW(int);
    int *b = NEW(int);
    int **fp;
    int **hm;
    hm = &b;
    fp = &a;

    printf("%p %p %p %p", a, b, *fp, *hm);

    fp = &b;

    return 0;
}
