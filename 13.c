#include <verifier-builtins.h>
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
    fp = &b;
    __VERIFIER_plot(NULL);

    printf("%p %p %p %p", a, b, *fp, *hm);

    return 0;
}
