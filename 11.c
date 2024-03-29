#include <verifier-builtins.h>
#include <stdlib.h>
#include <stdio.h>

#define NEW(type) (type *) malloc(sizeof(type))

int *id (int *x) { return x; }

int main()
{
    int *a = NEW(int);
    int *b = NEW(int);

    a = id(a);
    b = id(b);

    __VERIFIER_plot(NULL);
    printf("%p %p", a, b);

    return 0;
}
